/**
 * activate with: LoadModule sparul_module /tmp/sparql11/apache/.libs/mod_sparul.so
 */

#include "codea_hookmap.h"
#include "codea_hooks.h"
#include "codea_log.h"
#include "RdfDB.hpp"
#include "ResultSet.hpp"
#include "SWObjects.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "SPARQLSerializer.hpp"
#include "TurtleSParser/TurtleSParser.hpp"
#include "version.h"

//#include <fstream>
//#include <iostream>

#include "apr_strings.h"
#include "httpd.h"
#include "http_core.h"

using namespace std;
using namespace w3c_sw;

static const CodeaHooks::tag_t& SPARUL_tag( "SPARUL" );
class SPARULHooks : public CodeaHooks
{
public:
    static const tag_t& GetTag() { return SPARUL_tag; }

    static int Handler( request_rec* r ) {

        ap_log_error(APLOG_MARK, APLOG_DEBUG, 0, r->server, "mod_sparul: %s", 
                     "abcd");

	if (!strcmp(r->handler, "sparul-soundoff")) {

	    /* Add this to /etc/apache2/apache2.conf:
	    <Location /soundoff>
	      SetHandler sparul-soundoff
	    </Location>
	    and GET http://localhost/soundoff for instant gratification. */

	    ap_set_content_type(r, "text/html");
	    if (r->header_only)
		return OK;

	    ap_rputs(DOCTYPE_HTML_3_2, r);
	    ap_rputs("<html>\n", r);
	    ap_rputs(" <head>\n<title>mod_sparul Module Content-Handler Output\n</title>\n</head>\n", r);
	    ap_rputs(" <body>\n", r);
	    ap_rputs("  <h1><samp>mod_sparul</samp> Module Content-Handler Output\n</h1>\n", r);
	    ap_rputs("  <p>\n", r);
	    ap_rprintf(r, "  Apache HTTP Server version: \"%s\"<br />\n",
		       ap_get_server_banner());
	    ap_rprintf(r, "  Server built: %s<br />\n", ap_get_server_built());
	    ap_rprintf(r, "  Module built: %s %s<br />\n", __DATE__, __TIME__);
	    ap_rprintf(r, "  SWObjects Revision: %s modified %s by %s<br />\n",
		       SVN_Revision, SVN_Last_Changed_Date, SVN_Last_Changed_Author);
	    ap_rprintf(r, "  %s<br />\n", SVN_URL);
	    ap_rputs("  </p>\n", r);;
	    ap_rputs(" </body>\n", r);
	    ap_rputs("</html>\n", r);
	    return OK;
	}
        const char *ctype;
        ctype = apr_table_get(r->headers_in, "Content-Type");
        if (r->method_number == M_POST && ctype != NULL
            && strcmp(ctype, "application/sparql-query")==0) {
            ap_setup_client_block(r, REQUEST_CHUNKED_DECHUNK);

            // trigger SPARUL query on request URI
            int ret = 0;
            string query = "";
            char buf[1024];
            buf[0] = 0;

            if (!ap_should_client_block(r))
                return DECLINED;

            // accumulate client post data (query)
            while ((ret = ap_get_client_block(r, buf, 1024)) > 0) {
                query.append(buf, ret);
                if (ret < 1024)
                    break;
            }
            //printf("query: %s\n", query.c_str());

            // determine absolute URI
            const char *req_uri, *port;
            port = ap_is_default_port(ap_get_server_port(r), r)
                   ? "" : apr_psprintf(r->pool, ":%u", ap_get_server_port(r));
            req_uri = apr_psprintf(r->pool, "%s://%s%s%s%s",
                                   ap_http_scheme(r), ap_get_server_name(r), port,
                                   (*r->uri == '/') ? "" : "/",
                                   r->uri);
            //printf("req_uri: %s\n", req_uri);
            //printf("filename: %s\n", r->filename);

            // execute query
            AtomFactory f;
            RdfDB db;

            TurtleSDriver tp(req_uri, &f);
            tp.setGraph(db.ensureGraph(NULL));
            IStreamContext istr(r->filename, IStreamContext::FILE);
            tp.parse(istr);

            ResultSet rs(&f);
            rs.setRdfDB(&db);

            SPARQLfedDriver sp(req_uri, &f);
            IStreamContext qstr(query, IStreamContext::STRING);
            sp.parse(qstr);
            sp.root->execute(&db, &rs);

            //std::string out = db.ensureGraph(NULL)->toString();
            //std::ofstream of(r->filename);
            //delete tp.root;
            cout << db.ensureGraph(NULL)->toString();

            return OK;
        }

	return DECLINED;
    }
};

CODEA_REGISTER_HOOK_CLASS( SPARULHooks, SPARULHooks::GetTag() );

CODEA_BEGIN_HOOK_MAP( sparul )
CODEA_HANDLER( SPARULHooks::Handler, 0, 0, APR_HOOK_MIDDLE )
CODEA_END_HOOK_MAP( sparul )

CODEA_PUBLISH_MODULE( sparul, 0, 0, 0, 0, 0 )

