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

std::string BaseURI;
std::string ArgBaseURI;
bool NoExec = false;


/* Base class for all relative URI arguments. */
struct baseArg {
public:
    baseArg(std::string s) : s(s) {  }
    std::string s;
    virtual std::string& global() = 0;
};

struct relURI : public baseArg {
public:
    relURI(std::string s) : baseArg(s) {  }
};

std::string validateBase(boost::any& v, const std::vector<std::string>& values, std::string* setMe) {
    const std::string& s = po::validators::get_single_string(values);
    if (s == "?") {
	std::cout << "Base URI: <" << *setMe << ">\n";
	NoExec = true;
	return boost::lexical_cast<std::string>(*setMe);
    } else {
	std::string abs(libwww::HTParse(s, setMe->empty() ? NULL : setMe, libwww::PARSE_all));
	*setMe = abs;
	return boost::lexical_cast<std::string>(abs);
    }
}

/* Overload of relURI to validate --base arguments. */
struct baseURI : public relURI {
    baseURI(std::string s) : relURI(s) {  }
    virtual std::string& global () { std::cerr << "baseURI\n"; return BaseURI; }
};
void validate (boost::any& v, const std::vector<std::string>& values, baseURI*, int)
{
    v = boost::any(baseURI(validateBase(v, values, &BaseURI)));
}

/* Overload of relURI to validate --arg-base arguments. */
struct argBaseURI : public relURI {
    argBaseURI(std::string s) : relURI(s) {  }
    virtual std::string& global () { std::cerr << "baseURI\n"; return ArgBaseURI; }
};
void validate (boost::any& v, const std::vector<std::string>& values, argBaseURI*, int)
{
    v = boost::any(argBaseURI(validateBase(v, values, &ArgBaseURI)));
}


int main(int ac, char* av[])
{
    try {
	ArgBaseURI = BaseURI = "file://localhost/";

	int debug;

        /* General options -- cli-only. */
        po::options_description generalOpts("General options");
        generalOpts.add_options()
            ("help,h", "brief help message")    
            ("Help,H", 
	     po::value< std::vector<std::string> >()->composing(), 
	     "general, query, data, authentication, SQL, tutorial, all")
            ("debug", po::value<int>(&debug)->default_value(0), 
	     "debugging level")
            ("no-exec,n", "don't execute")
            ("print,p", "print final query")
            ("quiet,q", "quiet")
            ("version,v", "print version string")
	    ;

	/* cli overrides cfg file. */
        po::options_description formatOpts("");
        formatOpts.add_options()
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

        /* Ordered options -- not shown with --help. */
        po::options_description orderedArgs("Ordered options");
        orderedArgs.add_options()
            ("query", po::value<std::string>(), "SPARQL Query")
            ("view", po::value< std::vector<std::string> >(), "SPARQL View")
            ;
        
        po::options_description dataOpts("");
        dataOpts.add_options()
            ("data,d", po::value<baseURI>(), 
	     "read default graph from arg or stdin")
            ("graph,g", po::value<baseURI>(), 
	     "read default graph from arg or stdin")
            ;
    
        po::options_description cmdline_options;
        cmdline_options.add(generalOpts).add(formatOpts).add(uriOpts).add(orderedArgs);

        po::options_description config_file_options;
        config_file_options.add(formatOpts).add(uriOpts).add(orderedArgs);

        po::options_description visible("Allowed options");
        visible.add(generalOpts).add(formatOpts).add(uriOpts);
        
        po::positional_options_description p;
        p.add("query", 1).add("view", -1);
        
        po::variables_map vm;
        store(po::command_line_parser(ac, av).
              options(cmdline_options).positional(p).run(), vm);

	std::ifstream ifs(".SPARQL");
        store(parse_config_file(ifs, config_file_options), vm);
        notify(vm);
    
        if (vm.count("help")) {
            std::cout << visible << "\n";
            NoExec = true;
        }
        if (vm.count("Help"))
        {
	    std::vector<std::string> helps(vm["Help"].as< std::vector<std::string> >());
	    for (std::vector<std::string>::const_iterator it = helps.begin();
		 it != helps.end(); ++it)
		std::cout << "Help on " << *it << "\n";
            NoExec = true;
        }


        if (vm.count("version")) {
            std::cout << "Multiple sources example, version 1.0\n";
            return 0;
        }

        if (vm.count("query"))
        {
            std::cout << "SPARQL query is: " 
		      << vm["query"].as<std::string>() << "\n";
        }

        if (vm.count("view"))
        {
	    std::vector<std::string> helps(vm["view"].as< std::vector<std::string> >());
	    for (std::vector<std::string>::const_iterator it = helps.begin();
		 it != helps.end(); ++it)
		std::cout << "through view " << *it << "\n";
        }

        std::cout << "debugging level is " << debug << "\n";                
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << "\n";
        return 1;
    }    
    return 0;
}
