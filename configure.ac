AC_INIT(SWObjects, 1.0, swobjects-devel@lists.sourceforge.net, SWObjects)
AC_PREREQ(2.57)
AM_INIT_AUTOMAKE([1.10 -Wall no-define])
AC_REVISION($Revision$)
AC_CONFIG_HEADER(config.h)

AC_PROG_CXX
AM_PROG_LEX

BOOST_REQUIRE([1.36])

PKG_CHECK_MODULES([LIBXML2], [libxml-2.0 >= 2.6.19])

AC_ARG_WITH([mysql-include-path],
  [AS_HELP_STRING([--with-mysql-include-path],
    [location of the MySQL headers, defaults to /usr/include/mysql])],
  [MYSQL_CFLAGS="-I$withval"],
  [MYSQL_CFLAGS='-I/usr/include/mysql'])
AC_SUBST([MYSQL_CFLAGS])

AC_ARG_WITH([mysql-lib-path],
  [AS_HELP_STRING([--with-mysql-lib-path], [location of the MySQL libraries])],
  [MYSQL_LIBS="-L$withval -lmysqlclient"],
  [MYSQL_LIBS='-lmysqlclient'])
AC_SUBST([MYSQL_LIBS])
AC_SUBST([BOOST_CPPFLAGS])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
