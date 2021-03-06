/* You can use this to turn on and off compilation options when
 * compiling under windows.
 */

 #define SWOb_DISABLED		135
 /* XML Parsers: */
 #define SWOb_LIBXML2		137
 #define SWOb_EXPAT1		138
 #define SWOb_MSXML3		139
 /* Character Encodings: */
 #define SWOb_UTF8		143
 /* Regexp Libs: */
 #define SWOb_BOOST		144
 /* HTTP Libs: */
 #define SWOb_ASIO		145
 #define SWOb_DLIB		146
 /* SQL Libs: */
 #define SWOb_MYSQL		148
 
 #define XML_PARSER SWOb_MSXML3 
 #define CONSOLE_ENCODING SWOb_DISABLED 
 #define REGEX_LIB SWOb_BOOST 
 #define HTTP_CLIENT SWOb_ASIO 
 #define HTTP_SERVER SWOb_ASIO 
 #define SQL_CLIENT SWOb_MYSQL 
 #define SQL_CLIENT_MYSQL 
 #define SQL_CLIENT_POSTGRES 
 #define SQL_CLIENT_MSSQL 

#ifdef _DEBUG
  /* Debug builds can use the dynamic libs as you probably installed them
   * with the dev libs. */
  #define BOOST_ALL_DYN_LINK	// implies e.g. BOOST_TEST_DYN_LINK
  // #define BOOST_LOG_NO_LIB	// can't seem to statically link boost log
  // #define BOOST_LIB_DIAGNOSTIC
#else /* !_DEBUG */
  /* Release (NDEBUG) builds are probably for folks who don't have
   * boost*.dll installed. By default, boost links statically. */
#endif /* !_DEBUG */

#define HAVE_REGEX
#define _WIN32_WINNT 0x0501
#define SQL_CLIENT_MYSQL
#define SQL_CLIENT_MSSQL
