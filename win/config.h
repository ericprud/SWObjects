/* You can use this to turn on and off compilation options when
 * compiling under windows.
 */

 #define SWOb_DISABLED		135
 /* XML Parsers: */
 #define SWOb_LIBXML2		137
 #define SWOb_EXPAT1		138
 #define SWOb_MSXML		139
 /* Character Encodings: */
 #define SWOb_UTF8		143
 /* Regexp Libs: */
 #define SWOb_BOOST		144
 /* HTTP Libs: */
 #define SWOb_ASIO		145
 #define SWOb_DLIB		146
 /* SQL Libs: */
 #define SWOb_MYSQL		148
 
 #define XML_PARSER SWOb_LIBXML2 
 #define CONSOLE_ENCODING SWOb_UTF8 
 #define REGEX_LIB SWOb_BOOST 
 #define HTTP_CLIENT SWOb_ASIO 
 #define HTTP_SERVER SWOb_DLIB 
 #define SQL_CLIENT SWOb_MYSQL 

