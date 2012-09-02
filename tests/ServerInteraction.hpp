/* ServerInteraction.hpp - test functions for programs which serve HTTP.
 *
 * $Id: ServerInteraction.hpp,v 1 $
 */

#include <stdio.h>

#ifndef INCLUDED_tests_ServerInteraction
#define INCLUDED_tests_ServerInteraction

namespace w3c_sw {

    struct ServerInteraction {
	std::string exe, path;
	std::string hostIP;
	int port;
	std::string serverS, serverURL;
	FILE *serverPipe;

	ServerInteraction (std::string exe, std::string path,
			   std::string hostIP, std::string serverParams, int lowPort, int highPort)
	    : exe(exe), path(path), hostIP(hostIP), 
	      port(firstOpenPort(hostIP, lowPort, highPort))
	{
	    {
		std::stringstream ss;
		ss << "http://localhost:" << port << path;
		serverURL = ss.str();
	    }
	    char line[80];

	    /* Start the server and wait for it to listen.
	     */
	    std::string serverCmd(// std::string("sleep 1 && ") + // slow start to reveal race conditions.
				  exe + " " + serverParams + 
				  " --serve " + serverURL);
	    // w3c_sw_LINEN << "serverCmd: " << serverCmd << std::endl;
	    serverPipe = popen(serverCmd.c_str(), "r");
	    if (serverPipe == NULL)
		throw std::string("popen") + strerror(errno);
	    if (fgets(line, sizeof line, serverPipe) == NULL ||
		strncmp("Working directory:", line, 18))
		throw std::string("server didn't print a status line");
	    serverS += line;
	    waitConnect(hostIP, port);
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
	    std::stringstream ss;
	    ss << "Unable to find an available port between " << start << " and " << end << ".";
	    throw ss.str();
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
		FILE* readyPipe = popen(ss.str().c_str(), "r");
		if (fgets(buf, sizeof buf, readyPipe) != NULL)
		    break;
		else
		    w3c_sw_LINEN << "not yet\n";
		sigaction(SIGCHLD, &old, NULL);
		if (pclose(readyPipe) == -1 && errno != ECHILD)
		    throw std::string("pclose(readyPipe)") + strerror(errno);
	    }
	    w3c_sw_LINEN << "running\n";
	}

	/** readToExhaustion - read and close an iostream.
	 */
	static void readToExhaustion (FILE* stream, std::string& str, const char* title) {
	    char line[80];
	    while (fgets(line, sizeof line, stream) != NULL)
		str += line;
	    if (pclose(stream) == -1 && errno != ECHILD)
		throw std::string() + "pclose(" + title +")" + strerror(errno);
	}

    };


    /** SPARQLServerInteraction - ivocations of the bin/sparql binary.
     */
    struct SPARQLServerInteraction : public ServerInteraction {
	SPARQLServerInteraction (std::string serverParams)
	    : ServerInteraction ("../bin/sparql", "/SPARQL", "127.0.0.1", serverParams, 31533, 32767)
	{  }
    };


    /** ClientServerInteraction - client interactions with the server built into
     * the bin/sparql binary.
     */
    struct ClientServerInteraction : SPARQLServerInteraction {
	std::string clientS;

	ClientServerInteraction (std::string serverParams,
				 std::string clientParams)
	    : SPARQLServerInteraction(serverParams)
	{
	    char line[80];

	    /* Start the client and demand at least one line of output.
	     */
	    std::string clientCmd(exe + " --service " + serverURL +
				  " " + clientParams);
	    // w3c_sw_LINEN << "clientCmd: " << clientCmd << std::endl;
	    FILE *clientPipe = popen(clientCmd.c_str(), "r");
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
	    readToExhaustion(clientPipe, clientS, "client pipe");
	    readToExhaustion(serverPipe, serverS, "server pipe");
	}

    };


} // namespace w3c_sw

#endif /* INCLUDED_tests_ServerInteraction */

