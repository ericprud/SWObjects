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
	     "general, results, URI, query, data, authentication, SQL, tutorial, all")
            ("debug,D", po::value<debugLevel>(), 
	     "debugging level")
            ("no-exec,n", "don't execute")
            ("print,p", "print final query")
            ("quiet,q", "quiet")
            ("version,v", "print version string")
	    ;

	/* cli overrides cfg file. */
        po::options_description resultsOpts("");
        resultsOpts.add_options()
            ("ascii,a", "output ASCII-only")
            ("utf-8,u", "output utf-8")
            ("nullterm,0", "terminate lines with \0")
            ;
    
        // Declare a group of options that will be 
        // allowed both on command line and in
        // config file
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
        cmdline_options.add(generalOpts).add(resultsOpts).add(uriOpts).add(dataOpts).add(hidden);

        po::options_description config_file_options;
        config_file_options.add(resultsOpts).add(uriOpts).add(dataOpts).add(hidden);

        po::options_description visible("");
        visible.add(generalOpts).add(resultsOpts).add(uriOpts).add(dataOpts);
        
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

        if (vm.count("help")) {
            std::cout << 
		"Usage: SPARQL [opts] queryURI mapURI*\n" << 
		"Usage: SPARQL [opts] -e query mapURI*\n\n" << 
		"get started with: SPARQL help tutorial\n" << 
		visible << "\n";
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
			<< "Queries and maps:\n"
			<< "  <queryURI>            read and execute a query from <queryURI>.\n"
			<< "  -e <query>            execute <query>.\n"
			<< "  <mapURI>              map query through <mapURI> before executing.\n"
			<<  nl;
		if (!it->compare("data") || !it->compare("all"))
		    matched = true, std::cout << dataOpts << nl;
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
