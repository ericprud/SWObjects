/* ServerInteraction.hpp - test functions for programs which serve HTTP.
 *
 * $Id: ServerInteraction.hpp,v 1 $
 */

#include <stdio.h>
#include <assert.h>
#include <sys/wait.h>   /* header for waitpid() and various macros */
#include "SPARQLParser.hpp"

#ifndef INCLUDED_tests_ServerInteraction
#define INCLUDED_tests_ServerInteraction

namespace w3c_sw {

    /** SigChildGuard - capture SIGCHLD signals and record the child return value.
     */
    struct SigChildGuard {
	static int ChildRet;		// A global to capture the result from a childHandler
	static bool ChildRetSet;	// and a marker for whether it's set.

	struct sigaction oldact;

	SigChildGuard () {
	    ChildRetSet = false;
	    if (sigaction(SIGCHLD, NULL, &oldact) < 0)
		throw std::runtime_error("unable to get current SIGCHLD action");

	    struct sigaction act;
	    sigemptyset(&act.sa_mask); // clear out act's sigset_t

	    act.sa_handler = childHandler;
	    act.sa_flags = SA_NOCLDSTOP; // only catch terminated children
	    if (sigaction(SIGCHLD, &act, NULL) < 0)
		throw std::runtime_error("unable to set SIGCHLD action");
	}

	~SigChildGuard () {
	    if (sigaction(SIGCHLD, &oldact, NULL) < 0)
		throw std::runtime_error("unable to restore old SIGCHLD action");
	}

	static void childHandler (int /* signo */) {
	    int status, child_val;

	    /* Wait for any child without blocking */
	    if (waitpid(-1, &status, WNOHANG) < 0) 
		; // sometimes returns error in linux
	    // throw std::runtime_error("signal caught but child failed to terminate");
	    if (WIFEXITED(status)) {            /* If child exited normally   */
		ChildRet = WEXITSTATUS(status); /*   get child's exit status. */
		ChildRetSet = true;
	    }
	}
    };
    int SigChildGuard::ChildRet = 0;		// A global to capture the result from a childHandler
    bool SigChildGuard::ChildRetSet = false;	// and a marker for whether it's set.


    /** OutputFromNonInteractiveProcess - execute cmd and return the standard output.
     */
    struct OutputFromNonInteractiveProcess {
	std::string s;
	OutputFromNonInteractiveProcess (const std::string cmd) {
	    w3c_sw::SigChildGuard g;
	    s  = "execution failure";
	    FILE *p = ::popen(cmd.c_str(), "r");
	    assert(p != NULL);
	    char buf[100];
	    s = "";

	    /* Gave up on [[ ferror(p) ]] because it sometimes returns EPERM on OSX. */
	    for (size_t count; (count = fread(buf, 1, sizeof(buf), p)) || !feof(p);) {
		s += std::string(buf, buf + count);
		::fflush(p);
	    }
	    ::pclose(p);
	}
    };
    bool operator== (OutputFromNonInteractiveProcess& tested, std::string& ref) {
	return tested.s == ref;
    }
    std::ostream& operator== (std::ostream& o, OutputFromNonInteractiveProcess& tested) {
	return o << tested.s;
    }


    /** substituteQueryVariables - perform the following substitutions on s:
     *   %p -> port.
     */
    std::string substituteQueryVariables (std::string s, int port) {
	std::string portStr = boost::lexical_cast<std::string>(port);
	for (size_t i = 0; i < s.length(); ) {
	    i = s.find("%p", i);
	    if (i == std::string::npos)
		break;
	    s.replace(i, 2, portStr);
	}
	return s;
    }

    struct ServerInteraction {
	std::string exe, path;
	std::string hostIP;
	int port;
	std::string serverS, serverURL;
	FILE *serverPipe;
	w3c_sw::SigChildGuard g;

	ServerInteraction (std::string exe, std::string path,
			   std::string hostIP, std::string serverParams,
			   int lowPort, int highPort)
	    : exe(exe), path(path), hostIP(hostIP), port(firstOpenPort(hostIP, lowPort, highPort)),
	      serverURL("http://localhost:" + boost::lexical_cast<std::string>(port) + path)
	{
	    char line[80];

	    /* Start the server and wait for it to listen.
	     */
	    std::string serverCmd(// std::string("sleep 1 && ") + // slow start to reveal race conditions.
				  exe + " " + substituteQueryVariables(serverParams, port) + 
				  " --serve " + serverURL);
	    // serverCmd += " 2>&1 | tee -a server.mon";
	    BOOST_LOG_SEV(w3c_sw::Logger::ProcessLog::get(), w3c_sw::Logger::info)
		<< "serverCmd: " << serverCmd << std::endl;
	    serverPipe = popen(serverCmd.c_str(), "r");
	    if (serverPipe == NULL)
		throw std::string("popen") + strerror(errno);
	    if (fgets(line, sizeof line, serverPipe) == NULL ||
		strncmp("Working directory:", line, 18))
		throw std::string(serverCmd + " didn't print a status line");
	    serverS += line;
	    waitConnect(hostIP, port);
	}

	~ServerInteraction () {
	    if (pclose(serverPipe) == -1 && errno != ECHILD)
		throw std::string() + "pclose(serverPipe)" + strerror(errno);
	}

	static int firstOpenPort (std::string ip, int start, int end) {
	    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	    sockaddr_in remote;
	    remote.sin_family = AF_INET;
	    remote.sin_addr.s_addr = inet_addr(ip.c_str());

	    for (int port = start; port <= end; ++port) {
		remote.sin_port = htons(port);
		int ret = bind(sockfd, (struct sockaddr *) &remote, sizeof(remote));
		// w3c_sw_LINEN << " bind(" << port << ") = " << ret << " : " << strerror(errno) << "\n";
		if (ret != -1) {
		    close (sockfd);
		    return port;
		}
	    }
	    throw std::runtime_error("Unable to find an available port between "
				     + boost::lexical_cast<std::string>(start)
				     + " and "
				     + boost::lexical_cast<std::string>(end)
				     + ".");
	}

	/** waitConnect - busywait trying to connect to a port.
	 */
	static void waitConnect (std::string ip, int port) {
	    sockaddr_in remote;
	    remote.sin_family = AF_INET;
	    remote.sin_addr.s_addr = inet_addr(ip.c_str());
	    remote.sin_port = htons(port);

	    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	    assert(sockfd != -1);

	    for (;;) {
		// assert(sockfd != -1);
		if (connect(sockfd, (struct sockaddr *) &remote, sizeof(remote)) < 0) {
		    // w3c_sw_LINEN << " still can't connect: " << strerror(errno) << "\n";
		} else {
		    // w3c_sw_LINEN << "Connected after " << (finish - start) << " seconds.\n";
		    close(sockfd);
		    break;
		}
	    }
	}

	/** waitLsof - busywait grepping for port in lsof.
	 * (An alternative to waitLsof.)
	 */
	static void waitLsof (int port) {
	    std::stringstream ss;
	    ss << "lsof -nP -iTCP -sTCP:LISTEN | grep " << port;
	    char buf[80];
	    for (;;) {
		struct sigaction child, old;
		child.sa_handler = SIG_IGN;
		sigaction(SIGCHLD, &child, &old);
		FILE* readyPipe = ::popen(ss.str().c_str(), "r");
		if (::fgets(buf, sizeof buf, readyPipe) != NULL)
		    break;
		else
		    w3c_sw_LINEN << "not yet\n";
		sigaction(SIGCHLD, &old, NULL);
		if (::pclose(readyPipe) == -1 && errno != ECHILD)
		    throw std::string("pclose(readyPipe)") + strerror(errno);
	    }
	    w3c_sw_LINEN << "running\n";
	}

	/** readToExhaustion - read and close an iostream.
	 */
	static void readToExhaustion (FILE* stream, std::string& str) {
	    char line[80];
	    while (fgets(line, sizeof line, stream) != NULL)
		str += line;
	}

    };


    /** SPARQLServerInteraction - ivocations of the bin/sparql binary.
     */
    struct SPARQLServerInteraction : public ServerInteraction {
	SPARQLServerInteraction (std::string serverParams, std::string serverPath, int lowPort, int highPort)
	    : ServerInteraction ("../bin/sparql", serverPath, "127.0.0.1", serverParams, lowPort, highPort)
	{  }
    };


    /** EvaluatedResultSet - result set from an executed query.
     */
    struct EvaluatedResultSet : public ResultSet {
	struct DBLoader {
	    virtual void operator()(RdfDB* db) = 0;
	};
	EvaluatedResultSet (AtomFactory* atomFactory, SWWEBagent* webAgent, SWSAXparser* xmlParser, std::string query, DBLoader* dbLoader = NULL)
	    : ResultSet(atomFactory)
	{
	    IStreamContext istr(query, IStreamContext::STRING);
	    BOOST_LOG_SEV(w3c_sw::Logger::ProcessLog::get(), w3c_sw::Logger::info)
		<< "query: " << query << std::endl;
	    SPARQLDriver sparqlParser("", atomFactory);
	    try {
		Operation* op = sparqlParser.parse(istr);
		sparqlParser.clear(""); // clear out namespaces and base URI.
		RdfDB d(webAgent, xmlParser);
		if (dbLoader != NULL)
		    (*dbLoader)(&d);
		op->execute(&d, this);
		delete op;
	    } catch (ParserException& ex) {
		BOOST_LOG_SEV(w3c_sw::Logger::ProcessLog::get(), w3c_sw::Logger::info)
		    << "parser error: " << ex.what() << std::endl;
	    }
	}
	struct ResultAccessor {
	    const ResultSet* rs;
	    const Result* r;
	    ResultAccessor (const ResultSet* rs, const Result* r)
		: rs(rs), r(r)
	    {  }
	    struct TTermInterface {
		const TTerm* t;
		TTermInterface (const TTerm* t)
		    : t(t)
		{  }
		double getDouble () const {
		    const NumericRDFLiteral* f = dynamic_cast<const NumericRDFLiteral*>(t);
		    if (f == NULL)
			throw std::runtime_error(t == NULL ? std::string("NULL") : t->toString()
						 + ".getDouble() undefined");
		    return f->getDouble();
		}
	    };
	    const TTermInterface operator[] (std::string key) const {
		return TTermInterface(r->get(rs->getAtomFactory()->getVariable(key)));
	    }
	};
	const ResultAccessor operator[] (size_t i) const {
	    ResultList::const_iterator it = results.begin();
	    while (i--)
		if (++it == results.end())
		    throw std::out_of_range("past end of ResultSet");
	    return ResultAccessor(this, *it);
	}
    };


    /** ParsedResultSet - result set from a text string.
     */
    struct ParsedResultSet : public ResultSet {
	ParsedResultSet (AtomFactory* atomFactory, std::string srt) : 
	    ResultSet(atomFactory) {
	    delete *begin();
	    erase(begin());
	    IStreamContext sptr(srt.c_str(), IStreamContext::STRING, "text/sparql-results");
	    TTerm::String2BNode bnodeMap;
	    parseTable(sptr, false, &bnodeMap);
	}
    };


    /* Send \query to a waiting server.
     */
    struct SocketMessage {
	int fd;

	SocketMessage (int port, std::string addr, std::string path, std::string query)
	{
	    sockaddr_in remote;
	    remote.sin_family = AF_INET;
	    remote.sin_addr.s_addr = inet_addr(addr.c_str());
	    remote.sin_port = htons(port);

	    fd = socket(AF_INET, SOCK_STREAM, 0);
	    assert(fd != -1);

	    if (connect(fd, (struct sockaddr *) &remote, sizeof(remote)) < 0) {
		std::stringstream ss;
		ss << "failed to connect to "
		   << addr << ":" << port << " - error: " << strerror(errno);
		throw ss.str();
	    }

	    std::stringstream reqSS;
	    reqSS << "POST " << path << " HTTP/1.1\r\n"
		  << "Host: localhost:" << port << "\r\n"
		  << "Content-Length: " << query.size() << "\r\n"
		  << "Content-Type: application/x-www-form-urlencoded\r\n"
		  << "\r\n"
		  << query;

	    std::string req = reqSS.str();
	    const char* ptr = req.c_str();
	    for (size_t i = 0; i < req.size(); ) {
		ssize_t wrote = write(fd, ptr+i, req.size() - i);
		if (wrote == -1) {
		    std::stringstream ss;
		    ss << "failed to write " << req.size() - i << " bytes to "
		       << addr << ":" << port << " - error: " << strerror(errno);
		    throw ss.str();
		}
		i += wrote;
	    }
	}

	~SocketMessage () {
	    close(fd);
	    // if (pclose(serverPipe) == -1 && errno != ECHILD)
	    //     throw std::string() + "pclose(server pipe)" + strerror(errno);
	    // Could call
	    //   readToExhaustion(serverPipe, serverS, "server pipe");
	    // but there's no reason to read from serverPipe.
	}
    };


    /** OperationOnInvokedServer - client interactions with the server built into
     *  the bin/sparql binary.
     */
    struct OperationOnInvokedServer : SPARQLServerInteraction {
	EvaluatedResultSet got;
	ParsedResultSet expected;

	OperationOnInvokedServer (AtomFactory* atomFactory,
				  SWWEBagent* webAgent, SWSAXparser* xmlParser,
				  std::string serverParams, std::string serverPath,
				  int lowPort, int highPort,
				  std::string query, std::string expect)
	    : SPARQLServerInteraction(serverParams, serverPath, lowPort, highPort),
	      got(atomFactory, webAgent, xmlParser, substituteQueryVariables(query, port)),
	      expected(atomFactory, expect)
	{  }
    };

    /** ClientServerInteraction - client interactions with the server built into
     *  the bin/sparql binary.
     */
    struct ClientServerInteraction : SPARQLServerInteraction {
	std::string clientS;

	ClientServerInteraction (std::string serverParams, std::string serverPath, int lowPort, int highPort)
	    : SPARQLServerInteraction(serverParams, serverPath, lowPort, highPort)
	{  }

	void invoke (std::string clientCmd) {
	    // clientCmd += " | tee client.mon 2>&1";
	    BOOST_LOG_SEV(Logger::ProcessLog::get(), Logger::info)
		<< "clientCmd: " << clientCmd << std::endl;
	    char line[80];

	    /* Start the client and demand at least one line of output.
	     */
	    FILE *clientPipe = ::popen(clientCmd.c_str(), "r");
	    for (int tryNo = 0; tryNo < 2; ++tryNo)
		if (fgets(line, sizeof line, clientPipe) == NULL) {
		    if (errno != EINTR)
			throw std::string("no response from client process: ") + strerror(errno);
		} else {
		    clientS += line;
		    break;
		}

	    /* Read and close the client and server pipes.
	     */
	    readToExhaustion(clientPipe, clientS);
	    readToExhaustion(serverPipe, serverS);
	    if (pclose(clientPipe) == -1 && errno != ECHILD)
		throw std::string() + "pclose(clientPipe)" + strerror(errno);
	}

    };

    /** SPARQLClientServerInteraction - build a sparql client invocation string
     *  from the parameters used in the server invocation.
     */
    struct SPARQLClientServerInteraction : ClientServerInteraction {
	SPARQLClientServerInteraction (std::string serverParams, std::string serverPath,
				       std::string clientParams, int lowPort, int highPort)
	    : ClientServerInteraction(serverParams, serverPath, lowPort, highPort)
	{
	    invoke(exe + " --service " + serverURL + " " + substituteQueryVariables(clientParams, port));
	}
    };

} // namespace w3c_sw

#endif /* INCLUDED_tests_ServerInteraction */

