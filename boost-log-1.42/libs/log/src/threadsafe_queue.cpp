/*
 *          Copyright Andrey Semashev 2007 - 2010.
 * Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *          http://www.boost.org/LICENSE_1_0.txt)
 */
/*!
 * \file   threadsafe_queue.cpp
 * \author Andrey Semashev
 * \date   05.11.2010
 *
 * \brief  This header is the Boost.Log library implementation, see the library documentation
 *         at http://www.boost.org/libs/log/doc/log.html.
 *
 * The implementation is based on algorithms published in the "Simple, Fast,
 * and Practical Non-Blocking and Blocking Concurrent Queue Algorithms" article
 * in PODC96 by Maged M. Michael and Michael L. Scott. Pseudocode is available here:
 * http://www.cs.rochester.edu/research/synchronization/pseudocode/queues.html
 */

#include <boost/log/detail/threadsafe_queue.hpp>

#ifndef BOOST_LOG_NO_THREADS

#include <boost/assert.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/alignment_of.hpp>
#include <boost/log/utility/once_block.hpp>
#include <boost/log/detail/spin_mutex.hpp>
#include <boost/log/detail/locks.hpp>

#if defined(BOOST_WINDOWS)
#include <stddef.h> // uintptr_t
#if defined(_MSC_VER)
#include <intrin.h>
#else
#include "windows_version.hpp"
#include <windows.h>
#endif
#else
#include <stdint.h> // uintptr_t
#endif

// The macro allows to specify type alignment
#if defined(_MSC_VER)
#define BOOST_LOG_ALIGNMENT(x) __declspec(align(x))
#elif defined(__GNUC__)
#define BOOST_LOG_ALIGNMENT(x) __attribute__((__aligned__(x)))
#else
#define BOOST_LOG_ALIGNMENT(x)
#endif

namespace boost {

namespace BOOST_LOG_NAMESPACE {

namespace aux {

//! Generic queue implementation with two locks
class threadsafe_queue_impl_generic :
    public threadsafe_queue_impl
{
private:
    //! Mutex type to be used
    typedef spin_mutex mutex_type;

    /*!
     * A structure that contains a pointer to the node and the associated mutex.
     */
    struct pointer
    {
        //! Pointer to the either end of the queue
        node_base* node;
        //! Lock for access synchronization
        mutex_type mutex;
    };

private:
    //  The alignment below allows to eliminate false sharing, it should be not less than CPU cache line size.
    //! Pointer to the beginning of the queue
    BOOST_LOG_ALIGNMENT(128) pointer m_Head;
    //! Pointer to the end of the queue
    BOOST_LOG_ALIGNMENT(128) pointer m_Tail;

public:
    explicit threadsafe_queue_impl_generic(node_base* first_node)
    {
        set_next(first_node, NULL);
        m_Head.node = m_Tail.node = first_node;
    }

    ~threadsafe_queue_impl_generic()
    {
    }

    node_base* reset_last_node()
    {
        BOOST_ASSERT(m_Head.node == m_Tail.node);
        node_base* p = m_Head.node;
        m_Head.node = m_Tail.node = NULL;
        return p;
    }

    bool unsafe_empty() const
    {
        return m_Head.node == m_Tail.node;
    }

    void push(node_base* p)
    {
        set_next(p, NULL);
        exclusive_lock_guard< mutex_type > _(m_Tail.mutex);
        set_next(m_Tail.node, p);
        m_Tail.node = p;
    }

    bool try_pop(node_base*& node_to_free, node_base*& node_with_value)
    {
        exclusive_lock_guard< mutex_type > _(m_Head.mutex);
        node_base* next = get_next(m_Head.node);
        if (next)
        {
            // We have a node to pop
            node_to_free = m_Head.node;
            node_with_value = m_Head.node = next;
            return true;
        }
        else
            return false;
    }

private:
    // Copying and assignment are closed
    threadsafe_queue_impl_generic(threadsafe_queue_impl_generic const&);
    threadsafe_queue_impl_generic& operator= (threadsafe_queue_impl_generic const&);

    BOOST_LOG_FORCEINLINE static void set_next(node_base* p, node_base* next)
    {
        p->next.data[0] = next;
    }
    BOOST_LOG_FORCEINLINE static node_base* get_next(node_base* p)
    {
        return static_cast< node_base* >(p->next.data[0]);
    }
};

#if defined(_MSC_VER) && !defined(_M_CEE_PURE)
#   if defined(_M_IX86)
#       define BOOST_LOG_HAS_DCAS 1

BOOST_LOG_FORCEINLINE unsigned char pointer_dcas(
    threadsafe_queue_impl::pointer_storage* target,
    threadsafe_queue_impl::pointer_storage* comperand,
    const threadsafe_queue_impl::pointer_storage* replacement)
{
    register unsigned char result;
    __asm
    {
        mov ecx, replacement
        mov esi, comperand
        mov edi, target
        mov ebx, dword ptr [ecx]
        mov ecx, dword ptr [ecx + 4]
        mov eax, dword ptr [esi]
        mov edx, dword ptr [esi + 4]
        lock cmpxchg8b qword ptr [edi]
        mov dword ptr [esi], eax
        mov dword ptr [esi + 4], edx
        sete result
    };
    return result;
}

//! Atomically loads the double-pointer value
BOOST_LOG_FORCEINLINE void load_pointer(
    threadsafe_queue_impl::pointer_storage* from,
    threadsafe_queue_impl::pointer_storage* to)
{
    // The "from" pointer is always properly aligned
    BOOST_ASSERT((((uintptr_t)from) & 7U) == 0U);
    __asm
    {
        mov eax, from
        mov edx, to
        fild qword ptr [eax]
        fistp qword ptr [edx]
    };
}

BOOST_LOG_FORCEINLINE bool has_dcas()
{
    // Check for cmpxchg8b
    unsigned int result;
    __asm
    {
        mov eax, 1
        cpuid
        mov result, edx
    };
    return (result & (1U << 8)) != 0U;
}

#   elif defined(_M_AMD64)
#       define BOOST_LOG_HAS_DCAS 1

BOOST_LOG_FORCEINLINE unsigned char pointer_dcas(
    threadsafe_queue_impl::pointer_storage* target,
    threadsafe_queue_impl::pointer_storage* comperand,
    const threadsafe_queue_impl::pointer_storage* replacement)
{
    // Ensure the correct alignment
    BOOST_ASSERT((((uintptr_t)from) & 15U) == 0U);
    return _InterlockedCompareExchange128(
        (__int64*)target, ((__int64*)replacement)[1], ((__int64*)replacement)[0], comperand);
}

//! Atomically loads the double-pointer value
BOOST_LOG_FORCEINLINE void load_pointer(
    threadsafe_queue_impl::pointer_storage* from,
    threadsafe_queue_impl::pointer_storage* to)
{
    // The "from" pointer is always properly aligned
    BOOST_ASSERT((((uintptr_t)from) & 15U) == 0U);
    _mm_storeu_si128((__m128i*)to, _mm_load_si128((__m128i*)from));
}

BOOST_LOG_FORCEINLINE bool has_dcas()
{
    // Check for cmpxchg16b
    int cpu_info[4] = {};
    __cpuid(cpu_info, 1);
    return (cpu_info[2] & (1 << 13)) != 0;
}

#   endif

#elif defined(__GNUC__)

#   if defined(__i386__)
#       define BOOST_LOG_HAS_DCAS 1

BOOST_LOG_FORCEINLINE unsigned char pointer_dcas(
    threadsafe_queue_impl::pointer_storage* target,
    threadsafe_queue_impl::pointer_storage* comperand,
    const threadsafe_queue_impl::pointer_storage* replacement)
{
    register unsigned char result;

#if __PIC__
    // In position independed code EBX is reserved and cannot be allocated
    __asm__ __volatile__
    (
        "pushl %%ebx\n\t"
        "movl (%%ecx), %%ebx\n\t"
        "movl 4(%%ecx), %%ecx\n\t"
        "lock\n\t"
        "cmpxchg8b %1\n\t"
        "popl %%ebx\n\t"
        "sete %0"
            : "=q" (result), "=m" (*(unsigned long long*)target), "=A" (*(unsigned long long*)comperand)
            : "m" (*(unsigned long long*)target), "c" (replacement), "2" (*(unsigned long long*)comperand)
            : "memory", "cc", "esp"
    );
#else
    __asm__ __volatile__
    (
        "lock\n\t"
        "cmpxchg8b %1\n\t"
        "sete %0"
            : "=q" (result), "=m" (*(unsigned long long*)target), "=A" (*(unsigned long long*)comperand)
            : "m" (*(unsigned long long*)target),
              "b" (((unsigned int*)replacement)[0]), "c" (((unsigned int*)replacement)[1]),
              "2" (*(unsigned long long*)comperand)
            : "memory", "cc"
    );
#endif

    return result;
}

//! Atomically loads the double-pointer value
BOOST_LOG_FORCEINLINE void load_pointer(
    threadsafe_queue_impl::pointer_storage* from,
    threadsafe_queue_impl::pointer_storage* to)
{
    // The "from" pointer is always properly aligned
    BOOST_ASSERT((((uintptr_t)from) & 7U) == 0U);
    __asm__ __volatile__
    (
        "fildq %1\n\t"
        "fistpq %0"
            : "=m" (*(unsigned long long*)to)
            : "m" (*(unsigned long long*)from)
            : "memory"
    );
}

BOOST_LOG_FORCEINLINE bool has_dcas()
{
    // Check for cmpxchg8b
    register unsigned int result;
#if __PIC__
    // In position independed code EBX is reserved and cannot be allocated
    __asm__ __volatile__
    (
        "pushl %%ebx\n\t"
        "cpuid\n\t"
        "popl %%ebx"
            : "=d" (result)
            : "a" (1)
            : "esp", "ecx"
    );
#else
    __asm__ __volatile__
    (
        "cpuid"
            : "=d" (result)
            : "a" (1)
            : "ebx", "ecx"
    );
#endif
    return (result & (1U << 8)) != 0U;
}

#   elif defined(__x86_64__)
#       define BOOST_LOG_HAS_DCAS 1

BOOST_LOG_FORCEINLINE unsigned char pointer_dcas(
    threadsafe_queue_impl::pointer_storage* target,
    threadsafe_queue_impl::pointer_storage* comperand,
    const threadsafe_queue_impl::pointer_storage* replacement)
{
    // Ensure the correct alignment
    BOOST_ASSERT((((uintptr_t)from) & 15U) == 0U);
    register unsigned char result;

    __asm__ __volatile__
    (
        "lock\n\t"
        "cmpxchg16b %1\n\t"
        "sete %0"
            : "=q" (result),
              "=m" (*target),
              "=a" (((unsigned long long*)comperand)[0]), "=d" (((unsigned long long*)comperand)[1])
            : "m" (*target),
              "b" (((unsigned long long*)replacement)[0]), "c" (((unsigned long long*)replacement)[1]),
              "2" (((unsigned long long*)comperand)[0]), "3" (((unsigned long long*)comperand)[1])
            : "memory", "cc"
    );

    return result;
}

//! Atomically loads the double-pointer value
BOOST_LOG_FORCEINLINE void load_pointer(
    threadsafe_queue_impl::pointer_storage* from,
    threadsafe_queue_impl::pointer_storage* to)
{
    // The "from" pointer is always properly aligned
    BOOST_ASSERT((((uintptr_t)from) & 15U) == 0U);
    __asm__ __volatile__
    (
        "movdqa %1, %%xmm0\n\t"
        "movdqu %%xmm0, %0"
            : "=m" (*to)
            : "m" (*from)
            : "memory", "xmm0"
    );
}

BOOST_LOG_FORCEINLINE bool has_dcas()
{
    // Check for cmpxchg16b
    register unsigned long long result;
    __asm__ __volatile__
    (
        "cpuid"
            : "=c" (result)
            : "a" (1ULL)
            : "rbx", "rdx"
    );
    return (result & (1ULL << 13)) != 0U;
}

#   endif

#endif

#if defined(BOOST_LOG_HAS_DCAS)

//! DCAS-based queue implementation
class threadsafe_queue_impl_dcas :
    public threadsafe_queue_impl
{
private:
    /*!
     * A structure that contains a pointer to the node and the associated counter.
     */
    struct pointer_rep
    {
        //! Counter to eliminate ABA problem
        uintptr_t counter;
        //! Pointer to either end of the queue
        node_base* node;

        bool operator== (pointer_rep const& that) const
        {
            return counter == that.counter && node == that.node;
        }
    };
    BOOST_STATIC_ASSERT(sizeof(pointer_rep) <= sizeof(pointer_storage));

    //! Pointer casting helper
    union pointer
    {
        pointer_rep as_rep;
        pointer_storage as_storage;
    };

private:
    //  The alignment below allows to eliminate false sharing, it should be not less than CPU cache line size.
    //! Pointer to the beginning of the queue
    BOOST_LOG_ALIGNMENT(128) pointer m_Head;
    //! Pointer to the end of the queue
    BOOST_LOG_ALIGNMENT(128) pointer m_Tail;

public:
    explicit threadsafe_queue_impl_dcas(node_base* first_node)
    {
        pointer empty_pointer = {};
        first_node->next = empty_pointer.as_storage;
        m_Head.as_rep.counter = m_Tail.as_rep.counter = 0;
        m_Head.as_rep.node = m_Tail.as_rep.node = first_node;
    }

    ~threadsafe_queue_impl_dcas()
    {
    }

    node_base* reset_last_node()
    {
        BOOST_ASSERT(m_Head.as_rep.node == m_Tail.as_rep.node);
        node_base* p = m_Head.as_rep.node;
        m_Head.as_rep.node = m_Tail.as_rep.node = NULL;
        return p;
    }

    bool unsafe_empty() const
    {
        return m_Head.as_rep.node == m_Tail.as_rep.node;
    }

    void push(node_base* p)
    {
        pointer tail = {};
        p->next = tail.as_storage; // initialize the node pointer
        while (true)
        {
            load_pointer(&m_Tail.as_storage, &tail.as_storage);
            pointer next = {};
            load_pointer(&tail.as_rep.node->next, &next.as_storage);
            if (next.as_rep.node == NULL)
            {
                // The node is really the last one
                pointer new_next;
                new_next.as_rep.counter = next.as_rep.counter + 1;
                new_next.as_rep.node = p;
                if (pointer_dcas(&tail.as_rep.node->next, &next.as_storage, &new_next.as_storage))
                {
                    // All done, although the tail pointer now points one position back
                    break;
                }
            }
            else
            {
                // There is already a node beyond the tail pointer, update tail pointer
                pointer new_tail;
                new_tail.as_rep.counter = tail.as_rep.counter + 1;
                new_tail.as_rep.node = next.as_rep.node;
                pointer_dcas(&m_Tail.as_storage, &tail.as_storage, &new_tail.as_storage);
            }
        }

        // Try to update the tail pointer
        pointer new_tail;
        new_tail.as_rep.counter = tail.as_rep.counter + 1;
        new_tail.as_rep.node = p;
        pointer_dcas(&m_Tail.as_storage, &tail.as_storage, &new_tail.as_storage);
    }

    bool try_pop(node_base*& node_to_free, node_base*& node_with_value)
    {
        pointer head = {};
        while (true)
        {
            load_pointer(&m_Head.as_storage, &head.as_storage);
            pointer tail = {};
            load_pointer(&m_Tail.as_storage, &tail.as_storage);
            pointer next = {};
            load_pointer(&head.as_rep.node->next, &next.as_storage);
            if (head.as_rep.node == tail.as_rep.node)
            {
                if (next.as_rep.node == NULL)
                    return false; // the queue is empty

                // The tail pointer is one node behind, try to update it
                pointer new_tail;
                new_tail.as_rep.counter = tail.as_rep.counter + 1;
                new_tail.as_rep.node = next.as_rep.node;
                pointer_dcas(&m_Tail.as_storage, &tail.as_storage, &new_tail.as_storage);
            }
            else
            {
                // Try to dequeue the node
                node_with_value = next.as_rep.node;
                node_to_free = head.as_rep.node;
                pointer new_head;
                new_head.as_rep.counter = head.as_rep.counter + 1;
                new_head.as_rep.node = next.as_rep.node;
                if (pointer_dcas(&m_Head.as_storage, &head.as_storage, &new_head.as_storage))
                {
                    // All done
                    break;
                }
            }
        }

        return true;
    }

private:
    // Copying and assignment are closed
    threadsafe_queue_impl_dcas(threadsafe_queue_impl_dcas const&);
    threadsafe_queue_impl_dcas& operator= (threadsafe_queue_impl_dcas const&);
};

#endif // defined(BOOST_LOG_HAS_DCAS)

BOOST_LOG_EXPORT threadsafe_queue_impl* threadsafe_queue_impl::create(node_base* first_node)
{
#if defined(BOOST_LOG_HAS_DCAS)
    static bool use_dcas = false;
    BOOST_LOG_ONCE_BLOCK()
    {
        // Check for CPU capabilities
        use_dcas = has_dcas();
    }
    if (use_dcas)
        return new threadsafe_queue_impl_dcas(first_node);
#endif // defined(BOOST_LOG_HAS_DCAS)

    return new threadsafe_queue_impl_generic(first_node);
}

} // namespace aux

} // namespace log

} // namespace boost

#endif // BOOST_LOG_NO_THREADS
