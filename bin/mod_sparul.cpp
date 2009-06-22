#include "codea_hookmap.h"
#include "codea_hooks.h"
#include "codea_log.h"
#include "RdfDB.hpp"
#include "ResultSet.hpp"
#include "SWObjects.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "SPARQLSerializer.hpp"
#include "TurtleSParser/TurtleSParser.hpp"

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
        const char *ctype;
        ctype = apr_table_get(r->headers_in, "Content-Type");
        if (1) {
            /*
            ctype != NULL
            && strcmp(ctype, "application/sparql-query")==0
            && strcmp(r->method, "POST")==0) {
            */
            // trigger SPARUL query on request URI
            long q = 1;
            string query = "";
            char buf[1024];
            buf[0] = 0;

            //do {
                // accumulate client post data (query)
                q = ap_get_client_block(r, buf, 1024);
            //    query += buf;
            //} while (q > 0);

            // figure absolute URI
            const char *req_uri, *port;
            port = ap_is_default_port(ap_get_server_port(r), r)
                   ? "" : apr_psprintf(r->pool, ":%u", ap_get_server_port(r));
            req_uri = apr_psprintf(r->pool, "%s://%s%s%s%s",
                                   ap_http_scheme(r), ap_get_server_name(r), port,
                                   (*r->uri == '/') ? "" : "/",
                                   r->uri);

            // execute query
            POSFactory f;

            printf("req_uri: %s\n", req_uri);
            TurtleSDriver tp(req_uri, &f);
            RdfDB db;
            tp.setGraph(db.assureGraph(NULL));

            printf("filename: %s\n", r->filename);
            tp.parse_file(r->filename);
            SPARQLfedDriver sp(req_uri, &f);
            //sp.parse_string(query);
            printf("SPARUL: %s\n", buf);
            sp.parse_string("SELECT ?s ?p ?o { ?s ?p ?o. }");

            ResultSet rs(&f);
            sp.root->execute(&db, &rs);
            //std::string out = db.assureGraph(NULL)->toString();
            //std::ofstream of(r->filename);
            cout << db;
            delete tp.root;

            // its working
            //printf("SPARUL on %s: %s\n", req_uri, buf);
            //ap_rputs("SPARUL module invoked successfully.", r);
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
