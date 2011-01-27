/*
 *          Copyright Andrey Semashev 2007 - 2010.
 * Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *          http://www.boost.org/LICENSE_1_0.txt)
 */
/*!
 * \file   process_id.cpp
 * \author Andrey Semashev
 * \date   12.09.2009
 *
 * \brief  This header is the Boost.Log library implementation, see the library documentation
 *         at http://www.boost.org/libs/log/doc/log.html.
 */

#include <iostream>
#include <boost/integer.hpp>
#include <boost/io/ios_state.hpp>
#include <boost/log/detail/process_id.hpp>

#if defined(BOOST_WINDOWS)

#define WIN32_LEAN_AND_MEAN

#include "windows_version.hpp"
#include <windows.h>

namespace boost {

namespace BOOST_LOG_NAMESPACE {

namespace aux {

enum { pid_size = sizeof(GetCurrentProcessId()) };

namespace this_process {

    //! The function returns current process identifier
    BOOST_LOG_EXPORT process::id get_id()
    {
        return process::id(GetCurrentProcessId());
    }

} // namespace this_process

} // namespace aux

} // namespace log

} // namespace boost

#else // defined(BOOST_WINDOWS)

#include <unistd.h>
#include <boost/type_traits/is_integral.hpp>

namespace boost {

namespace BOOST_LOG_NAMESPACE {

namespace aux {

namespace this_process {

    BOOST_LOG_ANONYMOUS_NAMESPACE {

        template< typename T, bool = is_integral< T >::value >
        struct pid_traits
        {
            enum _ { pid_size = sizeof(T) < sizeof(uintmax_t) ? sizeof(T) : sizeof(uintmax_t) };

            static uintmax_t acquire_native()
            {
                union
                {
                    uintmax_t as_integer;
                    T as_native;
                }
                pid = {};
                pid.as_native = getpid();
                return pid.as_integer;
            }
        };

        template< typename T >
        struct pid_traits< T, true >
        {
            enum _ { pid_size = sizeof(T) };

            static uintmax_t acquire_native()
            {
                return static_cast< uintmax_t >(getpid());
            }
        };

        template< typename T >
        struct pid_traits< T*, false >
        {
            enum _ { pid_size = sizeof(uintptr_t) };

            static uintmax_t acquire_native()
            {
                return static_cast< uintmax_t >((uintptr_t)getpid());
            }
        };

    } // namespace

    //! The function returns current process identifier
    BOOST_LOG_EXPORT process::id get_id()
    {
        typedef pid_traits< pid_t > traits_t;
        return process::id(traits_t::acquire_native());
    }

} // namespace this_process

enum { pid_size = this_process::pid_traits< pid_t >::pid_size };

} // namespace aux

} // namespace log

} // namespace boost

#endif // defined(BOOST_WINDOWS)


namespace boost {

namespace BOOST_LOG_NAMESPACE {

namespace aux {

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >&
operator<< (std::basic_ostream< CharT, TraitsT >& strm, process::id const& pid)
{
    if (strm.good())
    {
        io::ios_flags_saver flags_saver(strm, std::ios_base::hex | std::ios_base::showbase);
        // The width is set calculated to accomodate pid in hex + "0x" prefix
        io::ios_width_saver width_saver(strm, static_cast< std::streamsize >(pid_size * 2 + 2));
        io::basic_ios_fill_saver< CharT, TraitsT > fill_saver(strm, static_cast< CharT >('0'));
        strm << static_cast< uint_t< pid_size * 8 >::least >(pid.m_NativeID);
    }

    return strm;
}

#if defined(BOOST_LOG_USE_CHAR)
template BOOST_LOG_EXPORT
std::basic_ostream< char, std::char_traits< char > >&
operator<< (std::basic_ostream< char, std::char_traits< char > >& strm, process::id const& pid);
#endif // defined(BOOST_LOG_USE_CHAR)

#if defined(BOOST_LOG_USE_WCHAR_T)
template BOOST_LOG_EXPORT
std::basic_ostream< wchar_t, std::char_traits< wchar_t > >&
operator<< (std::basic_ostream< wchar_t, std::char_traits< wchar_t > >& strm, process::id const& pid);
#endif // defined(BOOST_LOG_USE_WCHAR_T)

} // namespace aux

} // namespace log

} // namespace boost
