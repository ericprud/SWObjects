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
            POSFactory f;
            RdfDB db;

            TurtleSDriver tp(req_uri, &f);
            tp.setGraph(db.assureGraph(NULL));
            tp.parse_file(r->filename);

            ResultSet rs(&f);
            rs.setRdfDB(&db);

            SPARQLfedDriver sp(req_uri, &f);
            sp.parse_string(query);
            sp.root->execute(&db, &rs);

            //std::string out = db.assureGraph(NULL)->toString();
            //std::ofstream of(r->filename);
            //delete tp.root;
            cout << db.assureGraph(NULL)->toString();

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
