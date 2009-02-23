/* RdfDB - sets of variable bindings and their proofs.
 * $Id: RdfDB.cpp,v 1.2 2008-08-27 02:21:41 eric Exp $
 */

#include <boost/regex.hpp>
#include <boost/asio.hpp>
#include <libxml/parser.h>
#include "RdfDB.hpp"
#include "SAXparser_libxml.hpp"

using boost::asio::ip::tcp;

namespace w3c_sw {

    RdfDB::~RdfDB () {
	for (graphmap_type::const_iterator it = graphs.begin();
	     it != graphs.end(); it++)
	    delete it->second;
    }

    void RdfDB::clearTriples () {
	for (graphmap_type::const_iterator it = graphs.begin();
	     it != graphs.end(); it++)
	    it->second->clearTriples();
    }

    BasicGraphPattern* RdfDB::assureGraph (const POS* name) {
	if (name == NULL)
	    name = DefaultGraph;
	graphmap_type::const_iterator vi = graphs.find(name);
	if (vi == graphs.end()) {
	    BasicGraphPattern* ret;
	    if (name == DefaultGraph)
		ret = new DefaultGraphPattern();
	    else
		ret = new NamedGraphPattern(name);
	    graphs[name] = ret;
	    return ret;
	} else {
	    return vi->second;
	}
    }

    DefaultGraphClass defaultGraphInst;
    POS* DefaultGraph = &defaultGraphInst;

    void RdfDB::bindVariables (ResultSet* rs, const POS* graph, const BasicGraphPattern* toMatch) {
	graphmap_type::const_iterator vi;
	if (graph == NULL) graph = DefaultGraph;

	/* Look in each candidate graph. */
	if (graph->isConstant()) {
	    if ((vi = graphs.find(graph)) != graphs.end())
		vi->second->bindVariables(rs, graph, toMatch, vi->first);
	} else {
	    for (vi = graphs.begin(); vi != graphs.end(); vi++)
		if (vi->first != DefaultGraph)
		    vi->second->bindVariables(rs, graph, toMatch, vi->first);
	}
    }

    void RdfDB::express (Expressor* expressor) const {
	for (graphmap_type::const_iterator it = graphs.begin();
	     it != graphs.end(); it++)
	    it->second->express(expressor);
    }

    void RdfRemoteDB::loadData (const POS* name, POSFactory* posFactory) {
	for (std::vector<const char*>::const_iterator it = endpointPatterns.begin();
	     it != endpointPatterns.end(); ++it) {
#ifdef HAVE_REGEX
	    boost::regex re(*it);
	    boost::cmatch matches;
	    if (boost::regex_match(name->getTerminal().c_str(), matches, re)) {
		loadedEndpoints.insert(name);
		this->posFactory = posFactory;
		return;
	    }
#endif /* HAVE_REGEX */
	}
	RdfDB::loadData(name, posFactory);
    }

    void RdfRemoteDB::bindVariables (ResultSet* rs, const POS* graph, const BasicGraphPattern* toMatch) {
#ifdef HAVE_REGEX
	if (loadedEndpoints.find(graph) == loadedEndpoints.end())
#endif /* HAVE_REGEX */
	    RdfDB::bindVariables(rs, graph, toMatch);
#ifdef HAVE_REGEX
	else {
	    /* Build the request URL in buffer u. */
	    std::stringstream u;
	    u.setf(std::ios::hex, std::ios::basefield);
	    u.setf(std::ios::uppercase);

	    u << graph->getTerminal() << "?query=";
	    GraphSerializer ser(rs);
	    toMatch->express(&ser);
	    std::string q = ser.getSelectString() + '{' + ser.getSPARQLstring() + ser.getFederationString() + '}';
	    for (std::string::const_iterator it = q.begin(); it != q.end(); ++it) {
		if (*it == ' ')
		    u << '+';
		else if ((*it >= 'a' && *it <= 'z') || 
			 (*it >= 'A' && *it <= 'Z') || 
			 (*it >= '0' && *it <= '9'))
		    u << *it;
		else if (*it < 0x10)
		    u << "%0" << (unsigned)*it;
		else
		    u << '%' << (unsigned)*it;
	    }
	    std::string url = u.str();

	    // !!! duplicate of SPARQL_server.cpp
	    boost::regex re;
	    boost::cmatch matches;

	    re = "(ftp|http|https):\\/\\/((?:\\w+\\.)*\\w*)(?::([0-9]+))?(.*)";
	    if (!boost::regex_match(url.c_str(), matches, re))
		throw std::string("Address ") + url + " is not a valid URL\n";

#define PROT 1
#define HOST 2
#define PORT 3
#define PATH 4
	    std::string host(matches[HOST].first, matches[HOST].second);
	    std::string port(matches[PORT].first, matches[PORT].second);
	    std::string path(matches[PATH].first, matches[PATH].second);

	    std::cerr << "http://" << host << ":" << port << path << std::endl;

	    boost::asio::io_service io_service;

	    // Get a list of endpoints corresponding to the server name.
	    tcp::resolver resolver(io_service);
	    tcp::resolver::query query(host.c_str(), port.c_str());
	    tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
	    tcp::resolver::iterator end;

	    // Try each endpoint until we successfully establish a connection.
	    tcp::socket socket(io_service);
	    boost::system::error_code error = boost::asio::error::host_not_found;
	    while (error && endpoint_iterator != end) {
		socket.close();
		socket.connect(*endpoint_iterator++, error);
	    }
	    if (error)
		throw boost::system::system_error(error);

	    // Form the request. We specify the "Connection: close" header so that the
	    // server will close the socket after transmitting the response. This will
	    // allow us to treat all data up until the EOF as the content.
	    boost::asio::streambuf request;
	    std::ostream request_stream(&request);
	    request_stream << "GET " << path << " HTTP/1.0\r\n";
	    request_stream << "Host: " << host << "\r\n";
	    request_stream << "Accept: */*\r\n";
	    request_stream << "Connection: close\r\n\r\n";

	    // Send the request.
	    boost::asio::write(socket, request);

	    // Read the response status line.
	    boost::asio::streambuf response;
	    boost::asio::read_until(socket, response, "\r\n");

	    // Check that response is OK.
	    std::istream response_stream(&response);
	    std::string http_version;
	    response_stream >> http_version;
	    unsigned int status_code;
	    response_stream >> status_code;
	    std::string status_message;
	    std::getline(response_stream, status_message);
	    if (!response_stream || http_version.substr(0, 5) != "HTTP/")
		throw "Invalid response";
	    if (status_code != 200)
		throw std::string("Response returned with status code "); // + status_code;

	    // Read the response headers, which are terminated by a blank line.
	    boost::asio::read_until(socket, response, "\r\n\r\n");

	    // Process the response headers.
	    std::string header;
	    while (std::getline(response_stream, header) && header != "\r")
		std::cout << header << "\n";
	    std::cout << "\n";

	    std::ostringstream xmlResults;
	    // Write whatever content we already have to output.
	    if (response.size() > 0)
		xmlResults << &response;

	    // Read until EOF, writing data to output as we go.
	    while (boost::asio::read(socket, response,
				     boost::asio::transfer_at_least(1), error))
		xmlResults << &response;
	    if (error != boost::asio::error::eof)
		throw boost::system::system_error(error);
	    SAXparser_libxml p;
	    LIBXML_TEST_VERSION;
	    std::string s(xmlResults.str());
	    ResultSet red(posFactory, &p, s.begin(), s.end());
	    rs->joinIn(&red);
	    std::cerr << *rs;
	}
#endif /* HAVE_REGEX */
    }

    void RdfRemoteDB::GraphSerializer::namedGraphPattern (const NamedGraphPattern* const self, const POS* p_name, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns, const ProductionVector<const Filter*>* p_Filters) {
	if (expectOuterGraph) {
	    expectOuterGraph = false;
	    lead();

	    /* Serialize nested stuff. */
	    depth++;
	    p_TriplePatterns->express(this);
	    p_Filters->express(this);
	    depth--;
	    // _BasicGraphPattern(self, p_TriplePatterns, p_Filters, p_allOpts);

	    /* Build SELECT and FILTER strings from enountered Variables. */
	    selectString = "SELECT ";
	    for (std::set<const Variable*>::const_iterator it = vars.begin();
		 it != vars.end(); ++it)
		selectString += (*it)->toString() + ' ';
	    federationString = rs->buildFederationString(vars);

	    expectOuterGraph = true;
	} else
	    SPARQLSerializer::namedGraphPattern(self, p_name, p_allOpts, p_TriplePatterns, p_Filters);
    }
} // namespace w3c_sw

