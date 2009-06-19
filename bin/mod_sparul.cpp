#include "codea_hookmap.h"
#include "codea_hooks.h"
#include "codea_log.h"
#include "SWObjects.hpp"
#include "SPARQLfedParser/SPARQLfedParser.hpp"
#include "SPARQLSerializer.hpp"

using namespace std;
using namespace w3c_sw;

//ostream* DebugStream = NULL;
//POSFactory posFactory;

static const CodeaHooks::tag_t& SPARUL_tag( "SPARUL" );
class SPARULHooks : public CodeaHooks
{
public:
    static const tag_t& GetTag() { return SPARUL_tag; }

    static int Handler( request_rec* r ) {
        const char *ctype;
        ctype = apr_table_get(r->headers_in, "Content-Type");
        if (ctype != NULL
            && strcmp(ctype, "application/sparql-query")==0
            && strcmp(r->method, "POST")==0) {
            // trigger SPARUL query on request URI
            long q = 1;
            string query = "";
            char buf[1024];
            buf[0] = 0;

            do {
                // accumulate client post data (query)
                q = ap_get_client_block(r, buf, 1024);
                query += buf;
            } while (q > 0);

            // execute query
            /*
            POSFactory f;
            TurtleSDriver tp(r->uri, &f);
            RdfDB db;
            tp.setGraph(db.assureGraph(NULL));
            tp.parse_file(r->filename);
            // TODO instead: canonical hostname [+ port] + r->uri 
            SPARQLfedDriver sp(r->uri, &f);
            sp.parse_string(query);
            ResultSet rs;
            sp.getRoot()->execute(&db, &rs);
            std::string out = db.assureGraph(NULL)->toString();
            std::ofstream of(r->filename);
            of << out;
            delete tp.getRoot();
            */

            // its working
            printf("SPARUL: %s\n", query);
            ap_rputs("SPARUL module invoked successfully.", r);
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
