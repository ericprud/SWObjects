/* Copyright Eric Prud'hommeaux 2009.
 * Distributed under the Apache Software License.
 * thanks to Vladimir Prus's boost:program_options examples.

 * $Id$ */

#include <boost/program_options.hpp>
namespace po = boost::program_options;
#include <boost/regex.hpp>
#include <iostream>
#include <fstream>
#include <iterator>

/* Simulate HTParse interface (with bogus results, but good enough for testing CLI). */
namespace libwww {
    typedef enum {PARSE_all} e_PARSE_opts;
    std::string HTParse (std::string name, const std::string* rel, e_PARSE_opts /* wanted */)
    {
	std::string ret;
	if (rel)
	    ret = *rel;
	return ret.append(name);
    }
};

std::string CwdURI;
std::string BaseURI;
std::string ArgBaseURI;
bool NoExec = false;
int Debug = 0;
std::string NamedGraphName;
std::string Query;
std::vector< std::string >Maps;
std::string DataMediaType;
std::string UserName;
std::string PassWord;
std::map<std::string, std::string> HTTPHeaders;


/* Set Debug when parsed. */
struct debugLevel { };
void validate (boost::any& v, const std::vector<std::string>& values, debugLevel*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    std::stringstream stream(s);
    int i;
    stream >> i;
    Debug = i;
    v = boost::any(debugLevel());
    if (Debug > 0)
	std::cout << "debug level: " << Debug << "\n";
}

/* Set DataMediaType when parsed. */
struct langName { };
void validate (boost::any& v, const std::vector<std::string>& values, langName*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    if (!s.compare("?")) {
	std::cout << "language options: \"\", guess, turtle, trig, rdfa, rdfxml";
    } else {
	if (!s.compare(""))
	    DataMediaType = "";
	else if (!s.compare("guess"))
	    DataMediaType = "text/plain";
	else if (!s.compare("turtle"))
	    DataMediaType = "text/turtle";
	else if (!s.compare("trig"))
	    DataMediaType = "text/trig";
	else if (!s.compare("rdfa") || !s.compare("html"))
	    DataMediaType = "text/html";
	else if (!s.compare("rdfxml"))
	    DataMediaType = "application/rdf+xml";
	else
	    throw boost::program_options::validation_error(std::string("invalid value: \"").append(s).append("\""));
	if (Debug > 0)
	    if (DataMediaType.size() == 0)
		std::cout << "using no language mediatype.\n";
	    else
		std::cout << "using language mediatype " << DataMediaType << ".\n";
    }
}
struct langType { };
void validate (boost::any& v, const std::vector<std::string>& values, langType*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    if (!s.compare("?")) {
	std::cout << "language options: \"\", text/plain, text/turtle, text/trig, text/html, application/rdf:xml";
    } else {
	if (!s.compare(""))
	    DataMediaType = "";
	else if (!s.compare("text/plain"))
	    DataMediaType = "text/plain";
	else if (!s.compare("text/turtle"))
	    DataMediaType = "text/turtle";
	else if (!s.compare("text/trig"))
	    DataMediaType = "text/trig";
	else if (!s.compare("text/html"))
	    DataMediaType = "text/html";
	else if (!s.compare("application/rdf+xml"))
	    DataMediaType = "application/rdf+xml";
	else
	    throw boost::program_options::validation_error(std::string("invalid value: \"").append(s).append("\""));
	if (Debug > 0)
	    if (DataMediaType.size() == 0)
		std::cout << "using no language mediatype.\n";
	    else
		std::cout << "using language mediatype " << DataMediaType << ".\n";
    }
}

/* Base class for all relative URI arguments. */
struct relURI {};

void validateBase(const std::vector<std::string>& values, std::string* setMe, std::string* copySource, const char* argName) {
    const std::string& s = po::validators::get_single_string(values);
    if (s == "?") {
	std::cout << argName << "URI: " << *setMe << "\n";
    } else {
	std::string val = 
	    (s == ".") ? CwdURI : 
	    (s == ":") ? *copySource : 
	    libwww::HTParse(s, setMe->empty() ? NULL : setMe, libwww::PARSE_all);

	if (Debug > 0)
	    std::cout << "setting " << argName << " URI to " << val << "\n";
	*setMe = val;
    }
}

/* Overload of relURI to validate --base arguments. */
struct baseURI : public relURI {};
void validate (boost::any& v, const std::vector<std::string>& values, baseURI*, int)
{
    validateBase(values, &BaseURI, &ArgBaseURI, "base");
}

/* Overload of relURI to validate --arg-base arguments. */
struct argBaseURI : public relURI {};
void validate (boost::any& v, const std::vector<std::string>& values, argBaseURI*, int)
{
    validateBase(values, &ArgBaseURI, &BaseURI, "argument base");
}

/* Overload of relURI to validate --data arguments. */
struct dataURI : public relURI {};
void validate (boost::any& v, const std::vector<std::string>& values, dataURI*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    std::string abs(libwww::HTParse(s, ArgBaseURI == "" ? NULL : &ArgBaseURI, libwww::PARSE_all));
    if (Debug > 0)
	std::cout << "reading default graph from " << abs << " with base URI " << BaseURI << "\n";
}

/* Overload of relURI to validate --graph arguments. */
struct graphURI : public relURI {};
void validate (boost::any& v, const std::vector<std::string>& values, graphURI*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    NamedGraphName = s == "." ? s : libwww::HTParse(s, ArgBaseURI == "" ? NULL : &ArgBaseURI, libwww::PARSE_all);
}

/* Overload of relURI to validate --graph, query and map arguments. */
struct orderedURI : public relURI {};
void validate (boost::any& v, const std::vector<std::string>& values, orderedURI*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    std::string vald = libwww::HTParse(s, ArgBaseURI == "" ? NULL : &ArgBaseURI, libwww::PARSE_all);
    if (NamedGraphName != "") {
	if (NamedGraphName == ".")
	    NamedGraphName = vald;
	if (Debug > 0)
	    std::cout << "reading named graph " << NamedGraphName << " from " << vald << " with base URI " << BaseURI << "\n";
	NamedGraphName = "";
    } else if (Query == "") {
	if (Debug > 0)
	    std::cout << "query: " << vald << "\n";
	Query = vald;
    } else {
	if (Debug > 0)
	    std::cout << "view: " << vald << "\n";
	Maps.push_back(vald);
    }
}

/* Set UserName when parsed. */
struct userName {};
void validate (boost::any& v, const std::vector<std::string>& values, userName*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    UserName = s;
}
/* Set Password when parsed. */
struct passWord {};
void validate (boost::any& v, const std::vector<std::string>& values, passWord*, int)
{
    const std::string& s = po::validators::get_single_string(values);
    PassWord = s;
}
/* Assign an HTTP header when parsed. */
struct HeaderPair {
    std::string name;
    std::string value;
    HeaderPair(std::string name, std::string value) : name(name), value(value) {  }
};
HeaderPair parseHeaderPair (const std::vector<std::string>& values)
{
    const std::string& s = po::validators::get_single_string(values);
    size_t pos = s.find_first_of(':');
    if (pos == std::string::npos)
	throw boost::program_options::validation_error(std::string("no ':' found in HTTP header pair \"").append(s).append("\""));
    return HeaderPair(s.substr(0, pos), s.substr(pos+2));
}
struct headerAssign {};
void validate (boost::any& v, const std::vector<std::string>& values, headerAssign*, int)
{
    HeaderPair pair = parseHeaderPair(values);
    HTTPHeaders[pair.name] = pair.value;
}
struct headerAppend {};
void validate (boost::any& v, const std::vector<std::string>& values, headerAppend*, int)
{
    HeaderPair pair = parseHeaderPair(values);
    HTTPHeaders[pair.name].append(", ").append(pair.value);
}


int main(int ac, char* av[])
{
    try {
	CwdURI = ArgBaseURI = BaseURI = "file://localhost/";

        /* General options -- cli-only. */
        po::options_description generalOpts("General options");
        generalOpts.add_options()
            ("help,h", "brief help message")    
            ("Help,H", 
	     po::value< std::vector<std::string> >()->composing(), 
	     "general, results, uri, query, data, http, sql, tutorial, all")
            ("debug,D", po::value<debugLevel>(), 
	     "debugging level")
            ("no-exec,n", "don't execute")
            ("print,p", "print final query")
            ("quiet,q", "quiet")
            ("version,v", "print version string")
	    ;

	/* rest: cli appends cfg file. */

        po::options_description resultsOpts("");
        resultsOpts.add_options()
            ("ascii,a", "output ASCII-only")
            ("utf-8,u", "output utf-8")
            ("nullterm,0", "terminate lines with \0")
            ;
    
        po::options_description uriOpts("URI resolution");
        uriOpts.add_options()
            ("base,b", po::value<baseURI>(), 
	     "base URI for data/query resoultion")
            ("arg-base,B", 
	     po::value<argBaseURI>()->composing(), 
	     "base URI for command line arguments")
            ;

        po::options_description dataOpts("Reading data");
        dataOpts.add_options()
            ("data,d", po::value<dataURI>(), 
	     "read default graph from arg or stdin")
            ("graph,g", po::value<graphURI>(), 
	     "URI  read named graph <arg> from <URI> or stdin")
            ("language-name,l", po::value<langName>(), 
	     "data language\n\"guess\" to guess by resource extension, or \"-\" for stdin")
            ("lang-media-type,L", po::value<langType>(), 
	     "data language\n\"guess\" to guess by resource extension, or \"-\" for stdin")
            ("output,o", po::value<std::string>(), 
	     "send results to relURI or \"-\" for stdout.")
            ("in-place,i", po::value<std::string>(), 
	     "update arg with the results.\n\"-\" to read from stdin and write to stdout.")
            ("description,D", 
	     "read application description graph (see section) into default graph.")
            ("desc-graph,G", po::value<std::string>(), 
	     "read application description graph into graph arg.")
            ;
    
        po::options_description httpOpts("HTTP options");
        httpOpts.add_options()
            ("username,u", po::value<userName>(), 
	     "username for HTTP transactions")
            ("password,u", po::value<passWord>(), 
	     "password for HTTP transactions")
            ("header", po::value<headerAssign>(), 
	     "assign a header value.\n"
	     "\"--header ’Accept: text/turtle,text/html;q=.8’\" prefers turtle over HTML.")
            ("header+", po::value<headerAppend>(), 
	     "append earlier value of header.")
            ;

        po::options_description sqlOpts("SQL options");
        sqlOpts.add_options()
            ("stem,s", po::value<std::string>(), 
	     "stem URL.")
            ("sql-service,S", po::value<std::string>(), 
	     "odbc-style SQL database\n\tdriver://[username[:password]@]host[:port]/database\nmysql://localhost/orders")
            ("mapset,m", po::value<std::string>(), 
	     "mapset resource, which supplies above parameters.")
            ;

        /* Ordered options -- not shown with --help.
	 * Hack: 2nd arg to --graph is a orderedURI 'cause boost::po doesn't
	 * handle "--foo arg1 arg2".
	 */
        po::options_description hidden("Hidden options");
        hidden.add_options()
            ("ordered", po::value<orderedURI>(), "URIs")
            ;

        po::options_description cmdline_options;
        cmdline_options.add(generalOpts).add(resultsOpts).add(uriOpts).add(dataOpts).add(httpOpts).add(sqlOpts).add(hidden);

        po::options_description config_file_options;
        config_file_options.add(resultsOpts).add(uriOpts).add(dataOpts).add(httpOpts).add(sqlOpts).add(hidden);

        po::options_description visible("");
        visible.add(generalOpts).add(resultsOpts).add(uriOpts).add(httpOpts).add(sqlOpts).add(dataOpts);
        
        po::options_description cursory("");
        cursory.add(generalOpts).add(resultsOpts).add(uriOpts).add(dataOpts);
        
        po::positional_options_description p;
        p.add("ordered", -1);
        
        po::variables_map vm;
	po::store(po::command_line_parser(ac, av).
              options(cmdline_options).positional(p).run(), vm);

	std::ifstream ifs(".SPARQL");
	po::store(parse_config_file(ifs, config_file_options), vm);
	po::notify(vm);
    
        if (vm.count("no-exec")) {
	    if (Debug > 0)
		std::cout << "Execution suppressed.\n";
            NoExec = true;
        }

	static const char* queryHelp = "Queries and maps:\n"
	    "  <queryURI>            read and execute a query from <queryURI>.\n"
	    "  -e <query>            execute <query>.\n"
	    "  <mapURI>              map query through <mapURI> before executing.\n";
	static const char* appDescGraph = 
	    "    @prefix doap: <http://usefulinc.com/ns/doap#> .\n"
	    "    <> a doap:Project ;\n"
            "        doap:homepage <http://swobj.org/SPARQL/v1> ;\n"
            "        doap:shortdesc \"a semantic web query toolbox\" .\n";
	static const char* tutorial = 
	    "SPARQL -D \"SELECT ?proj ?page WHERE {?proj <http://use‐fulinc.com/ns/doap#homepage> ?page}\""
	    ;

        if (vm.count("help")) {
            std::cout << 
		"Usage: SPARQL [opts] queryURI mapURI*\n"
		"Usage: SPARQL [opts] -e query mapURI*\n\n"
		"get started with: SPARQL help tutorial\n" << 
		queryHelp << cursory;
            NoExec = true;
        }

        if (vm.count("Help"))
        {
	    std::vector<std::string> helps(vm["Help"].as< std::vector<std::string> >());
	    for (std::vector<std::string>::const_iterator it = helps.begin();
		 it != helps.end(); ++it) {
		std::string nl = "\n"; // !it->compare("all") ? "\n" : "";
		bool matched = false;
		if (!it->compare("general") || !it->compare("all"))
		    matched = true, std::cout << generalOpts << nl;
		if (!it->compare("results") || !it->compare("all"))
		    matched = true, std::cout << resultsOpts << nl;
 		if (!it->compare("uri") || !it->compare("all"))
		    matched = true, std::cout << uriOpts << nl;
 		if (!it->compare("query") || !it->compare("all"))
		    matched = true, std::cout
			<< queryHelp
			<<  nl;
		if (!it->compare("data") || !it->compare("all"))
		    matched = true, std::cout
			<< dataOpts
			<< "SPARQL will \"guess\" that data from ’-’ is trig and output is either a table or trig.\n\n"
			<< "Application description graph:\n" << appDescGraph
			<< nl;
 		if (!it->compare("http") || !it->compare("all"))
		    matched = true, std::cout << httpOpts << nl;
 		if (!it->compare("sql") || !it->compare("all"))
		    matched = true, std::cout << sqlOpts << nl;
 		if (!it->compare("tutorial") || !it->compare("all"))
		    matched = true, std::cout << tutorial << nl;
		if (matched == false)
		    std::cout << "Unknown help topic: " << *it << "\n";
	    }
            NoExec = true;
        }


        if (vm.count("version")) {
            std::cout << "Multiple sources example, version 1.0\n";
            return 0;
        }

	if (NoExec == false)
	    std::cout << "now we do stuff \n";
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << "\n";
        return 1;
    }    
    return 0;
}
