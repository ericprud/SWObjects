/*
 *          Copyright Andrey Semashev 2007 - 2010.
 * Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *          http://www.boost.org/LICENSE_1_0.txt)
 */
/*!
 * \file   light_function.hpp
 * \author Andrey Semashev
 * \date   20.06.2010
 *
 * \brief  This header is the Boost.Log library implementation, see the library documentation
 *         at http://www.boost.org/libs/log/doc/log.html.
 *
 * The file contains a lightweight alternative of Boost.Function. It does not provide all
 * features of Boost.Function but doesn't introduce dependency on Boost.Bind.
 */

#ifndef BOOST_LOG_DETAIL_LIGHT_FUNCTION_HPP_INCLUDED_
#define BOOST_LOG_DETAIL_LIGHT_FUNCTION_HPP_INCLUDED_

#include <boost/assert.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/iteration/iterate.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <boost/preprocessor/repetition/enum_trailing_params.hpp>
#include <boost/log/detail/prologue.hpp>
#include <boost/log/utility/explicit_operator_bool.hpp>

#ifndef BOOST_LOG_LIGHT_FUNCTION_LIMIT
#define BOOST_LOG_LIGHT_FUNCTION_LIMIT 2
#endif

namespace boost {

namespace BOOST_LOG_NAMESPACE {

namespace aux {

#define BOOST_PP_FILENAME_1 <boost/log/detail/light_function.hpp>
#define BOOST_PP_ITERATION_LIMITS (0, BOOST_LOG_LIGHT_FUNCTION_LIMIT)
#include BOOST_PP_ITERATE()

} // namespace aux

} // namespace log

} // namespace boost

#endif // BOOST_LOG_DETAIL_LIGHT_FUNCTION_HPP_INCLUDED_

#ifdef BOOST_PP_IS_ITERATING

#define BOOST_LOG_LWFUNCTION_NAME BOOST_PP_CAT(light_function, BOOST_PP_ITERATION())

template<
    typename ResultT
    BOOST_PP_ENUM_TRAILING_PARAMS(BOOST_PP_ITERATION(), typename ArgT)
>
class BOOST_LOG_LWFUNCTION_NAME
{
public:
    typedef ResultT result_type;

private:
    struct BOOST_LOG_NO_VTABLE implementation_base
    {
        virtual ~implementation_base() {}
        virtual implementation_base* clone() const = 0;
        virtual result_type operator() (BOOST_PP_ENUM_BINARY_PARAMS(BOOST_PP_ITERATION(), ArgT, arg)) = 0;
    };

#if !defined(BOOST_LOG_NO_MEMBER_TEMPLATE_FRIENDS)
    template< typename FunT >
    class implementation;
    template< typename FunT >
    friend class implementation;
#endif

    template< typename FunT >
    class implementation :
        public implementation_base
    {
        FunT m_Function;

    public:
        explicit implementation(FunT const& fun) : m_Function(fun)
        {
        }

        implementation_base* clone() const
        {
            return new implementation(m_Function);
        }
        result_type operator() (BOOST_PP_ENUM_BINARY_PARAMS(BOOST_PP_ITERATION(), ArgT, arg))
        {
            return m_Function(BOOST_PP_ENUM_PARAMS(BOOST_PP_ITERATION(), arg));
        }
    };

private:
    implementation_base* m_pImpl;

public:
    BOOST_LOG_LWFUNCTION_NAME() : m_pImpl(NULL)
    {
    }
    BOOST_LOG_LWFUNCTION_NAME(BOOST_LOG_LWFUNCTION_NAME const& that)
    {
        if (that.m_pImpl)
            m_pImpl = that.m_pImpl->clone();
        else
            m_pImpl = NULL;
    }
    template< typename FunT >
    BOOST_LOG_LWFUNCTION_NAME(FunT const& fun) : m_pImpl(new implementation< FunT >(fun))
    {
    }
    //! Constructor from NULL
    BOOST_LOG_LWFUNCTION_NAME(int p) : m_pImpl(NULL)
    {
        BOOST_ASSERT(p == 0);
    }
    ~BOOST_LOG_LWFUNCTION_NAME()
    {
        delete m_pImpl;
    }

    BOOST_LOG_LWFUNCTION_NAME& operator= (BOOST_LOG_LWFUNCTION_NAME that)
    {
        this->swap(that);
        return *this;
    }
    //! Assignment of NULL
    BOOST_LOG_LWFUNCTION_NAME& operator= (int p)
    {
        BOOST_ASSERT(p == 0);
        clear();
        return *this;
    }

    result_type operator() (BOOST_PP_ENUM_BINARY_PARAMS(BOOST_PP_ITERATION(), ArgT, arg)) const
    {
        return m_pImpl->operator() (BOOST_PP_ENUM_PARAMS(BOOST_PP_ITERATION(), arg));
    }

    BOOST_LOG_EXPLICIT_OPERATOR_BOOL()
    bool operator! () const { return (m_pImpl == NULL); }
    bool empty() const { return (m_pImpl == NULL); }
    void clear()
    {
        delete m_pImpl;
        m_pImpl = NULL;
    }

    void swap(BOOST_LOG_LWFUNCTION_NAME& that)
    {
        register implementation_base* p = m_pImpl;
        m_pImpl = that.m_pImpl;
        that.m_pImpl = p;
    }
};

template<
    BOOST_PP_ENUM_PARAMS(BOOST_PP_ITERATION(), typename ArgT)
>
class BOOST_LOG_LWFUNCTION_NAME<
    void
    BOOST_PP_ENUM_TRAILING_PARAMS(BOOST_PP_ITERATION(), ArgT)
>
{
public:
    typedef void result_type;

private:
    struct BOOST_LOG_NO_VTABLE implementation_base
    {
        virtual ~implementation_base() {}
        virtual implementation_base* clone() const = 0;
        virtual result_type operator() (BOOST_PP_ENUM_BINARY_PARAMS(BOOST_PP_ITERATION(), ArgT, arg)) = 0;
    };

#if !defined(BOOST_LOG_NO_MEMBER_TEMPLATE_FRIENDS)
    template< typename FunT >
    class implementation;
    template< typename FunT >
    friend class implementation;
#endif

    template< typename FunT >
    class implementation :
        public implementation_base
    {
        FunT m_Function;

    public:
        explicit implementation(FunT const& fun) : m_Function(fun)
        {
        }

        implementation_base* clone() const
        {
            return new implementation(m_Function);
        }
        result_type operator() (BOOST_PP_ENUM_BINARY_PARAMS(BOOST_PP_ITERATION(), ArgT, arg))
        {
            m_Function(BOOST_PP_ENUM_PARAMS(BOOST_PP_ITERATION(), arg));
        }
    };

private:
    implementation_base* m_pImpl;

public:
    BOOST_LOG_LWFUNCTION_NAME() : m_pImpl(NULL)
    {
    }
    BOOST_LOG_LWFUNCTION_NAME(BOOST_LOG_LWFUNCTION_NAME const& that)
    {
        if (that.m_pImpl)
            m_pImpl = that.m_pImpl->clone();
        else
            m_pImpl = NULL;
    }
    template< typename FunT >
    BOOST_LOG_LWFUNCTION_NAME(FunT const& fun) : m_pImpl(new implementation< FunT >(fun))
    {
    }
    //! Constructor from NULL
    BOOST_LOG_LWFUNCTION_NAME(int p) : m_pImpl(NULL)
    {
        BOOST_ASSERT(p == 0);
    }
    ~BOOST_LOG_LWFUNCTION_NAME()
    {
        delete m_pImpl;
    }

    BOOST_LOG_LWFUNCTION_NAME& operator= (BOOST_LOG_LWFUNCTION_NAME that)
    {
        this->swap(that);
        return *this;
    }
    //! Assignment of NULL
    BOOST_LOG_LWFUNCTION_NAME& operator= (int p)
    {
        BOOST_ASSERT(p == 0);
        clear();
        return *this;
    }

    result_type operator() (BOOST_PP_ENUM_BINARY_PARAMS(BOOST_PP_ITERATION(), ArgT, arg)) const
    {
        m_pImpl->operator() (BOOST_PP_ENUM_PARAMS(BOOST_PP_ITERATION(), arg));
    }

    BOOST_LOG_EXPLICIT_OPERATOR_BOOL()
    bool operator! () const { return (m_pImpl == NULL); }
    bool empty() const { return (m_pImpl == NULL); }
    void clear()
    {
        delete m_pImpl;
        m_pImpl = NULL;
    }

    void swap(BOOST_LOG_LWFUNCTION_NAME& that)
    {
        register implementation_base* p = m_pImpl;
        m_pImpl = that.m_pImpl;
        that.m_pImpl = p;
    }
};

template<
    typename ResultT
    BOOST_PP_ENUM_TRAILING_PARAMS(BOOST_PP_ITERATION(), typename ArgT)
>
inline void swap(
    BOOST_LOG_LWFUNCTION_NAME< ResultT BOOST_PP_ENUM_TRAILING_PARAMS(BOOST_PP_ITERATION(), ArgT) >& left,
    BOOST_LOG_LWFUNCTION_NAME< ResultT BOOST_PP_ENUM_TRAILING_PARAMS(BOOST_PP_ITERATION(), ArgT) >& right)
{
    left.swap(right);
}

#undef BOOST_LOG_LWFUNCTION_NAME

#endif // BOOST_PP_IS_ITERATING
