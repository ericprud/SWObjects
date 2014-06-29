/** SimpleServer tools
 *
 * in progress, see ../bin/sparql.cpp for example of use
 */

#ifndef INCLUDED_lib_SimpleServer_hpp
 #define INCLUDED_lib_SimpleServer_hpp

#if HTTP_SERVER == SWOb_ASIO
#include <sys/inotify.h>
#include <sys/epoll.h>

#define EVENT_SIZE  (sizeof (struct inotify_event))
#define BUF_LEN        (1024 * (EVENT_SIZE + 16))
#endif /* HTTP_SERVER == SWOb_ASIO */

namespace w3c_sw {

    template <class engine_type, class data_loader, class controller_type>
    class SimpleInterface : public WebHandler {
	engine_type& engine;
	controller_type* controller;
	std::string serviceURI;
	std::string servicePath;
	std::string interfacePath;
	size_t exploreTripleCountLimit;
	size_t exploreGraphCountLimit;

	static std::string CSS_common;
	static std::string CSS_Results;
	static std::string Javascript_TableSorter_remote;
	static std::string Javascript_ToggleDisplay_init;
	static std::string Javascript_TableSorter_init;
	static std::string Javascript_ToggleDisplay_defn;
	static std::string AuthChallenge;

    public:
	SimpleInterface (engine_type& engine, controller_type* controller,
			 std::string serviceURI, std::string servicePath,
			 std::string interfacePath) : 
	    WebHandler("."), // @@ docroot is irrelevant -- create a docserver
	    engine(engine), controller(controller), serviceURI(serviceURI),
	    servicePath(servicePath), interfacePath(interfacePath),
	    // hard-code explore*CountLimit
	    exploreTripleCountLimit(100), exploreGraphCountLimit(10)
	{  }
	~SimpleInterface () {  }

    protected:

	struct IStreamList : public std::list<IStreamContext*> {
	    void release () {
		for (const_iterator it = begin(); it != end(); ++it)
		    delete *it;
		clear();
	    }
	};
	IStreamList getBodies (webserver::request& req) {
	    IStreamList ret;
	    MediaType mediaType = MediaType(req.getContentType());
	    if (mediaType.match("multipart/form-data")) {
		if (!mediaType.parameterValue("boundary", NULL))
		    throw std::runtime_error("DOOM1");
		std::string boundary = "\r\n--"+mediaType.getParameter("boundary");
		std::string body = req.getBody();
		for (size_t pos = boundary.size(); pos != std::string::npos; ) {
		    size_t p2 = body.find(boundary, pos);
		    std::string section = body.substr(pos, p2 - pos);
		    pos = p2 + boundary.size();
		    if (body[pos] == '\r' && body[pos+1] == '\n')
			pos += 2;
		    else if (body[pos] == '-' && body[pos+1] == '-')
			pos = std::string::npos;
		    else
			throw std::runtime_error("");

		    std::string sectionBody;
		    std::string attribute;
		    std::string contentType;
		    typedef enum { EXPECT_crlf, EXPECT_lf, EXPECT_attribute, EXPECT_value } EXPECT_type;
		    EXPECT_type exp = EXPECT_attribute;
		    for (std::string::const_iterator c = section.begin();
			 c != section.end(); ++c) {
			switch (exp) {
			case EXPECT_crlf:
			    switch (*c) {
			    case '\n': exp = EXPECT_attribute; break;
			    case '\r': exp = EXPECT_lf; break;
			    default: throw std::runtime_error("");
			    } break;
			case EXPECT_lf:
			    switch (*c) {
			    case '\n': exp = EXPECT_attribute; break;
			    default: throw std::runtime_error("");
			    } break;
			case EXPECT_attribute:
			    if (*c == '\n' || (*c == '\r' && *(++c) == '\n')) {
				std::string::const_iterator end = section.end();
				++c;
				sectionBody = std::string(c, end);
				c = end - 1;
				break;
			    }
			    {
				std::string::const_iterator start = c;
				while (*c != ':') ++c;
				attribute = std::string(start, c++);
				while (*c == ' ') ++c;
				--c;
				exp = EXPECT_value; 
			    } break;
			case EXPECT_value:
			    {
				std::string::const_iterator start = c;
				while (*c != '\r' && *c != '\n') ++c;
				std::string value = std::string(start, c);
				--c;
				std::string nameCopy = attribute;
				std::transform(nameCopy.begin(), nameCopy.end(), nameCopy.begin(), ::tolower);
				if (nameCopy == "content-type") {
				    contentType = value;
				}
				exp = EXPECT_crlf; 
			    } break;
			}
		    }
		    // w3c_sw_LINEN << contentType << ": [[" << sectionBody << "]]\n";
		    ret.insert(ret.end(), new IStreamContext(sectionBody, IStreamContext::STRING, ::strdup(contentType.c_str())));
		}
	    } else {
		ret.insert(ret.end(), new IStreamContext(req.getBody(), IStreamContext::STRING, mediaType.c_str()));
	    }
	    return ret;
	}

	const URI* nextAvailableGraph (std::string absURL, webserver::request& /* req */, webserver::reply& rep) {
	    for (unsigned int i = 0; i < 1000; ++i) {
		std::string s = absURL + boost::lexical_cast<std::string>(i);
		const URI* ret = engine.atomFactory.getURI(s);
		if (engine.db.findGraph(ret) == NULL) {
		    rep.addHeader("Location", s);
		    return ret;
		}
	    }
	    throw std::runtime_error("exhausted available graph pool");
	}

	void stop_handler (webserver::request& /* req */, webserver::reply& rep, std::ostringstream& sout) {
	    rep.status = webserver::reply::ok;
	    head(sout, "Done!");
	    sout << "    <p>Served " << engine.served << " queries.</p>\n";
	    foot(sout);
	    engine.done = true;
	    controller->stop();
	}

	void sadi_handler (webserver::request& req, webserver::reply& rep, std::ostringstream& sout) {
		    IStreamContext istr(req.getBody(), IStreamContext::STRING, req.getContentType().c_str());
		    engine.loadDataOrResults(sw::DefaultGraph, "sadiInput",
					     engine.baseURI, istr, engine.resultSet, &engine.db);
		    ResultSet rs(&engine.atomFactory);
		    RdfDB constructed; // For operations which create a new database.
		    rs.setRdfDB(&constructed);
		    std::string language;
		    std::string newQuery(req.getBody());
		    //queryLoadList.loadAll();
		    engine.executeQuery(engine.sadiOp, rs, language, newQuery, NULL);
		    // engine.db.setTarget(NULL);
		    XMLSerializer xml("  ");
		    rep.status = webserver::reply::ok;
		    rep.setContentType(
				       rs.resultType == ResultSet::RESULT_Graphs
				       ? "text/turtle; charset=UTF-8"
				       : "application/sparql-results+xml; charset=UTF-8");
		    rs.toXml(&xml);
		    sout << xml.str();
		    BOOST_LOG_SEV(Logger::ProcessLog::get(), Logger::info)
			<< "SADI invocation returning [[\n" << xml.str() << "\n]].\n";
		    ++engine.served;
		    if (engine.stopAfter != engine.RunForever && --engine.stopAfter == 0) {
			engine.done = true;
			controller->stop();
		    }
	}

	void ldp_handler (webserver::request& req, webserver::reply& rep, std::ostringstream& sout) {
		    IStreamContext istr(req.getBody(), IStreamContext::STRING, req.getContentType().c_str());
		    // w3c_sw_LINE << "executing " << req.getBody() << " on " << engine.db.str();
		    // RdfDB& execDB = engine.db;
		    RdfDB execDB(engine.db);
		    // w3c_sw_LINE << execDB.str();
		    // BasicGraphPattern* ldpInput = engine.db.setTarget(engine.atomFactory.getURI("ldpInput"));
		    // const sw::TTerm* postGraph = engine.atomFactory.getURI("/POST");
		    // engine.loadDataOrResults(postGraph, "ldpInput", engine.baseURI,
		    // 			     istr, engine.resultSet, &execDB);
		    engine.loadDataOrResults(sw::DefaultGraph, "ldpInput",
					     engine.baseURI, istr, engine.resultSet, &execDB);
		    BOOST_LOG_SEV(Logger::IOLog::get(), Logger::info)
			<< "parsing " << req.getContentType().c_str()
			<< " [[\n" << req.getBody() << "\n]]"
			<< " yielded [[\n" << execDB.str() << "\n]].\n";
		    // w3c_sw_LINE << execDB.str();
		    // std::string language;
		    // std::string newQuery(req.getBody());
		    // queryLoadList.loadAll();
		    ResultSet rs(&engine.atomFactory);
		    // engine.executeQuery(engine.ldpOp, rs, language, newQuery);
		    engine.ldpOp->bindVariables(&execDB, &rs);
		    // w3c_sw_LINE << rs;
		    {
			boost::mutex::scoped_lock lock(engine.executeMutex);
			engine.db.clearGraphLog();
			engine.ldpOp->update(&engine.db, &rs);
			rs.resultType = ResultSet::RESULT_Tabular;
			// w3c_sw_LINE << rs;
			engine.db.synch();
		    }
		    RdfDB constructed; // For operations which create a new database.
		    MakeNewBNode mb(&engine.atomFactory);
		    BasicGraphPattern* defGP = constructed.findGraph(DefaultGraph);
		    engine.ldpOp->construct(&constructed, &rs, &mb, defGP);
		    // engine.db.setTarget(NULL);
		    rep.status = webserver::reply::ok;
		    rep.setContentType("text/trig");
		    sout << constructed.str();
		    BOOST_LOG_SEV(Logger::ProcessLog::get(), Logger::info)
			<< "LDP invocation returning [[\n" << constructed.str() << "\n]].\n";
		    ++engine.served;
		    if (engine.stopAfter != engine.RunForever && --engine.stopAfter == 0) {
			engine.done = true;
			controller->stop();
		    }
	}

	void put_or_post_graph_handler (webserver::request& req, webserver::reply& rep, std::ostringstream& sout) {
		std::string path(req.getPath());
		path.erase(0, 1); // get rid of leading '/' to keep stuff relative.
		std::string absURL = libwww::GetAbsoluteURIstring("/"+path, serviceURI);
		    IStreamList bodies = getBodies(req);
		    if (bodies.size() == 1) { // !! preparse to not clear mis-posts - remove this expectation from <http://metacognition.info/gsp_validation/gsp.validator.run>
			IStreamContext istr(req.getBody(), IStreamContext::STRING, req.getContentType().c_str());
			NamespaceMap map;
			DefaultGraphPattern bgp;
			engine.db.loadData(&bgp, istr, absURL, "", &engine.atomFactory, &map); // req.getPath()
		    }
		    webserver::request::ParmMap::const_iterator parm;
		    parm = req.parms.find("default");
		    bool isDefaultGraph = parm != req.parms.end();
		    parm = req.parms.find("graph");

		    const URI* into =
			isDefaultGraph ? NULL
			: parm != req.parms.end() ? engine.atomFactory.getURI(parm->second)
			: path == servicePath ? nextAvailableGraph(absURL, req, rep)
			: engine.atomFactory.getURI(absURL);

		    size_t oldSize = 0;
		    BasicGraphPattern* bgp = engine.db.findGraph(isDefaultGraph ? DefaultGraph : into);
		    bool existed = true;
		    if (bgp == NULL) {
			bgp = engine.db.ensureGraph(isDefaultGraph ? DefaultGraph : into);
			existed = false;
		    } else if (req.getMethod() == "PUT") {
			oldSize = bgp->size();
			bgp->clearTriples();
		    }
		    for (std::list<IStreamContext*>::iterator it = bodies.begin(); it != bodies.end(); ++it) {
			NamespaceMap map;
			engine.db.loadData(bgp, **it, absURL, "", &engine.atomFactory, &map); // req.getPath()
		    }
		    bodies.release();

		    rep.setStatus(!existed ? webserver::reply::created : oldSize == 0 ? webserver::reply::no_content : webserver::reply::ok);
		    head(sout, "Q&amp;D SPARQL Server PUT Successful");
		    sout << 
			"    <p>Uploaded " << bgp->size() << " triples into ";
		    if (isDefaultGraph)
			sout << "default graph";
		    else
			sout << uriLink(into);
		    sout << "</p>\n";
		    sout << DBsummary();

		    rep.setContentType("text/html");
		    foot(sout);
	}

	void delete_handler (webserver::request& req, webserver::reply& rep, std::ostringstream& sout) {
		std::string path(req.getPath());
		path.erase(0, 1); // get rid of leading '/' to keep stuff relative.
		std::string absURL = libwww::GetAbsoluteURIstring("/"+path, serviceURI);
		    webserver::request::ParmMap::const_iterator parm;
		    parm = req.parms.find("default");
		    bool isDefaultGraph = parm != req.parms.end();

		    const URI* into = isDefaultGraph ? NULL : engine.atomFactory.getURI(absURL); // req.getPath()
		    BasicGraphPattern* bgp = engine.db.findGraph(isDefaultGraph ? DefaultGraph : into);
		    size_t oldSize = 0;
		    bool existed = true;
		    std::string responseTitle = "Q&amp;D SPARQL Server DELETE ";
		    if (bgp == NULL) {
			existed = false;
			responseTitle += "Unsuccessful";
		    } else {
			oldSize = bgp->size();
			engine.db.eraseGraph(isDefaultGraph ? DefaultGraph : into);
			responseTitle += "Successful";
		    }

		    rep.setStatus(!existed ? webserver::reply::not_found : isDefaultGraph ? webserver::reply::no_content : webserver::reply::ok);
		    head(sout, responseTitle);
		    sout << 
			"    <p>Deleted " << oldSize << " triples from ";
		    if (isDefaultGraph)
			sout << "default graph";
		    else
			sout << uriLink(into);
		    sout << "</p>\n";
		    sout << DBsummary();

		    rep.setContentType("text/html");
		    foot(sout);
	}

	void html_interface_handler (webserver::request& /* req */, webserver::reply& rep, std::ostringstream& sout) {
		    rep.status = webserver::reply::ok;
		    head(sout, "Q&amp;D SPARQL Server");
		    const char* method =
			ServiceGraphPattern::defaultHTTPmethod == ServiceGraphPattern::HTTP_METHOD_GET ? "get" :
			"post";
		    sout << 
			"    <form action='" << servicePath << "' method='" << method << "'><p>\n"
			"      Query: <textarea name='query' rows='25' cols='80'></textarea> <input type='submit' /><br />\n"
			"      default graph: <input type='text' name='default-graph-uri' size='50' /><br />\n"
			"      named graph:   <input type='text' name=  'named-graph-uri' size='50' /><span id=\"addGraph\" onclick='\n"
			"        var b = document.createElement(\"br\");\n"
			"        this.parentNode.insertBefore(b, this);\n"
			"        var t = document.createTextNode(\"named graph: \");\n"
			"        this.parentNode.insertBefore(t, this);\n"
			"        var i = document.createElement(\"input\");\n"
			"        i.setAttribute(\"type\", \"text\");\n"
			"        i.setAttribute(\"name\", \"named-graph-uri\");\n"
			"        i.setAttribute(\"size\", \"50\");\n"
			"        this.parentNode.insertBefore(i, this);\n"
			"        '> +</span><br />\n"
			"      <input type='radio' name='media' value='xmlres' />SPARQL XML Results\n"
			"      <input type='radio' name='media' value='html' checked='checked' />HTML Results\n"
			"      <input type='radio' name='media' value='tablesorter' />JQuery Tablesorter\n"
			"      <input type='radio' name='media' value='textplain' />SPARQL XML Results in text/html\n"
			"    </p></form>\n"
			"    <form action='" << servicePath << "' method='post'><p>\n"
			"      server status: running, " << engine.served << " served. ";
		    if (!controller->getStopCommand().empty())
			sout << "<input name='query' type='submit' value='" << controller->getStopCommand() << "'/>";
		    sout << "\n"
			"    </p></form>\n";
		    sout << DBsummary();

		    rep.setContentType("text/html");
		    foot(sout);
	}

	void parse_execute_render (std::string query, const data_loader& queryLoadList, webserver::request& req, webserver::reply& rep, std::ostringstream& sout)
			{
		std::string path(req.getPath());
		path.erase(0, 1); // get rid of leading '/' to keep stuff relative.
		std::string absURL = libwww::GetAbsoluteURIstring("/"+path, serviceURI);
			    IStreamContext istr(query, IStreamContext::STRING, req.getContentType().c_str());
		std::pair<std::string, std::string> userPass = req.getUserPassword();
		std::string oldBase = engine.sparqlParser.getBase();
		engine.sparqlParser.setBase(absURL);
			    Operation* op = engine.sparqlParser.parse(istr);
		engine.sparqlParser.setBase(oldBase);
			webserver::request::ParmMap::const_iterator parm;
			    parm = req.parms.find("media");
			    bool humanReader = (parm != req.parms.end()
						&& (parm->second == "html"
						    || parm->second == "edit"
						    || parm->second == "tablesorter"));

			    ResultSet rs(&engine.atomFactory);
			    RdfDB constructed; // For operations which create a new database.
			    rs.setRdfDB(dynamic_cast<Construct*>(op) != NULL && !engine.inPlace ? &constructed : &engine.db);
			    std::string language;
			    std::string newQuery(query);

			    try {
				queryLoadList.loadAll();
				if (path != servicePath)
				    engine.db.setTarget(engine.atomFactory.getURI(absURL));

				// This one-row ResultSet holds system-defined variables.
				ResultSet mappingConstants(&engine.atomFactory);
				Result* firstRow = *mappingConstants.begin();
				mappingConstants.set(firstRow, engine.atomFactory.getVariable("VERSION"), // @@ haven't used outside of FILTER
					     engine.atomFactory.getRDFLiteral("SWObjects 1.0"), false);
				if (userPass.first != "") {
				    mappingConstants.set(firstRow, engine.atomFactory.getVariable("USER"),
						 engine.atomFactory.getRDFLiteral(userPass.first), false);
				    mappingConstants.set(firstRow, engine.atomFactory.getVariable("PASSWORD"),
						 engine.atomFactory.getRDFLiteral(userPass.second), false);
				}
				engine.executeQuery(op, rs, language, newQuery, &mappingConstants);
				if (humanReader &&
				    (dynamic_cast<GraphChange*>(op) != NULL || 
				     dynamic_cast<OperationSet*>(op) != NULL)) { // @@@ OperationSet *currently* only used for updates.
				    /** 
				     * For a nice human interface, we can do
				     * another query to report the resulting
				     * database.
				     */
				    delete op;
				    rs.clear();
				    op = engine.sparqlParser.parse("SELECT ?s ?p ?o {\n  ?s ?p ?o\n}");
				    op->execute(&engine.db, &rs);
				}
				engine.db.setTarget(NULL);
				delete op;
			    } catch (ParserException& ex) {
				delete op;
				throw ex;
			    } catch (std::string ex) {
				delete op;
				throw ex;
			    }
			    const VariableVector cols = rs.getOrderedVars();

			    XMLSerializer xml("  ");
			    if (humanReader) {
				std::string headStr =
				    "    <style type=\"text/css\" media=\"screen\">\n"
				    "/*<![CDATA[*/\n" + CSS_common
				    ;
				if (parm->second == "html"
				    || parm->second == "edit")
				    headStr += CSS_Results;
				headStr +=
				    "/*]]>*/\n"
				    "    </style>\n"
				    "\n"
				    ;
				if (parm->second == "tablesorter")
				    headStr += Javascript_TableSorter_remote;
				headStr +=
				    "    <script language=\"javascript\" type=\"text/javascript\">\n"
				    "<!--\n"
				    ;
				if (parm->second == "tablesorter")
				    headStr +=
					"    $(function() {\n"
					;
				else
				    headStr +=
					"    window.onload=function(){\n"
					;
				headStr += Javascript_ToggleDisplay_init;
				
				if (parm->second == "tablesorter")
				    headStr += Javascript_TableSorter_init;
				if (parm->second == "tablesorter")
				    headStr +=
					"    });\n"
					;
				else
				    headStr +=
					"    };\n"
					;
				headStr += Javascript_ToggleDisplay_defn +
				    "-->\n"
				    "    </script>\n"
				    ;
				head(sout, "SPARQL Query Results", headStr);
				/*
				  <div id="requery">
				  <pre id="edit" contenteditable="true" style="display:block; float:left;">SELECT ?s ?p ?o {
				  ?s ?p ?o
				  }</pre>
				  <form action="/as/df">
				  <p>
				  <input id="query" name="query" type="hidden" value=""/>
				  <input type="submit" value="re-query" onclick="copy('edit', 'query');" style="margin: 2em"/>
				  </p>
				  </form>
				  </div>
				*/
				/** construct XHTML body with query and results. */
				xml.open("div"); {
				    xml.attribute("id", "requery");
				    XMLSerializer::Attributes preAttrs;
				    preAttrs["id"] = "edit";
				    preAttrs["contenteditable"] = "true";
				    preAttrs["style"] = "display:block; float:left;";
				    xml.leaf("pre", newQuery, preAttrs);
				    xml.open("form"); {
					xml.attribute("action", path);
					xml.attribute("method", "get");
					xml.open("p"); {
					    XMLSerializer::Attributes queryAttrs;
					    queryAttrs["type"] = "hidden";
					    queryAttrs["value"] = "";
					    queryAttrs["id"] = "query";
					    queryAttrs["name"] = "query";
					    xml.empty("input", queryAttrs);

					    XMLSerializer::Attributes mediaAttrs;
					    mediaAttrs["type"] = "hidden";
					    mediaAttrs["value"] = "edit";
					    mediaAttrs["name"] = "media";
					    xml.empty("input", mediaAttrs);

					    // Create a hidden input field with user's current username.
					    XMLSerializer::Attributes userAttrs;
					    userAttrs["type"] = "hidden";
					    userAttrs["name"] = "user";
					    userAttrs["value"] = req.getUserPassword().first;
					    xml.empty("input", userAttrs);

					    // Create a div with an editable query and a prompt to change the username.
					    XMLSerializer::Attributes controlsAttrs;
					    controlsAttrs["style"] = "margin: 2em;";
					    xml.open("div", controlsAttrs); {
						XMLSerializer::Attributes submitAttrs;
						submitAttrs["type"] = "submit";
						submitAttrs["value"] = "re-query";
						submitAttrs["onclick"] = "copy('edit', 'query')";
						xml.empty("input", submitAttrs);

						xml.empty("br");

						XMLSerializer::Attributes authAttrs;
						authAttrs["type"] = "checkbox";
						authAttrs["name"] = AuthChallenge;
						xml.leaf("input", std::string("change auth"), authAttrs);
					    } xml.close(); // div
					} xml.close(); // p
				    } xml.close(); // form
				} xml.close(); // div

				XMLSerializer::Attributes resultsAttrs;
				resultsAttrs["id"] = "results";
				resultsAttrs["class"] = "tablesorter";
				rs.toHtmlTable(&xml, resultsAttrs, path == servicePath ? "" : std::string("") + "/" + path);

				/** construct reply from headers and XHTML body */
				rep.status = webserver::reply::ok;
				rep.setContentType(
						   "text/html; charset=UTF-8");
				sout << xml.str();
				foot(sout);

			    } else if (parm != req.parms.end() && parm->second == "textplain") {
				head(sout, "SPARQL Query Results");

				// cute lexical representation of xml nesting:
				xml.leaf("pre", newQuery);
				rep.status = webserver::reply::ok;
				rep.setContentType(
						   "text/html; charset=UTF-8");

				XMLSerializer rsSerializer("  ");
				rs.toXml(&rsSerializer);
				std::string source(rsSerializer.str());
				xml.leaf("pre", rsSerializer.str());

				sout << xml.str();
				foot(sout);
			    } else { /* !htmlResults */
				rep.status = webserver::reply::ok;
				rep.setContentType(
						   rs.resultType == ResultSet::RESULT_Graphs
						   ? "text/turtle; charset=UTF-8"
						   : "application/sparql-results+xml; charset=UTF-8");
				rs.toXml(&xml);
				sout << xml.str();
			    } /* !htmlResults */

			    ++engine.served;
			    if (engine.stopAfter != engine.RunForever && --engine.stopAfter == 0) {
				engine.done = true;
				controller->stop();
			    }
			}


	webserver::reply::status_type
	handle_request (webserver::request& req, webserver::reply& rep) {
	    try {
		std::string path(req.getPath());
		path.erase(0, 1); // get rid of leading '/' to keep stuff relative.
		std::string absURL = libwww::GetAbsoluteURIstring("/"+path, serviceURI);
		std::ostringstream sout;
		const BasicGraphPattern* getGraph = engine.db.getGraph(engine.atomFactory.getURI(absURL)); // path

		if (!controller->getStopCommand().empty() &&
		    req.parms.get_only("query") == controller->getStopCommand()) {
		    stop_handler(req, rep, sout);
		} else if (engine.sadiOp != NULL) {
		    sadi_handler(req, rep, sout);
		} else if (engine.ldpOp != NULL) {
		    ldp_handler(req, rep, sout);
		} else if ((req.getMethod() == "PUT" ||
			    (req.getMethod() == "POST" &&
			     req.getContentType().compare(0, 33, "application/x-www-form-urlencoded") != 0 &&
			     req.getContentType().compare(0, 33, "application/sparql-query") != 0 &&
			     req.getContentType().compare(0, 34, "application/sparql-update") != 0)) &&
			   req.parms.find("query") == req.parms.end() && req.parms.find("update") == req.parms.end()) {
		    put_or_post_graph_handler(req, rep, sout);
		} else if (req.getMethod() == "DELETE") {
		    delete_handler(req, rep, sout);
		} else if ((req.getMethod() == "GET" || req.getMethod() == "HEAD" || req.getMethod() == "POST") && (path == servicePath || getGraph != NULL)) {
		    bool isDefaultGraph = false;
		    webserver::request::ParmMap::const_iterator parm;
		    // w3c_sw_LINEN << "method: " << req.getMethod() << "\n";
		    // w3c_sw_LINEN << "content type: " << req.getContentType() << "\n";
		    std::string query;
		    if (req.getContentType().compare(0, 33, "application/sparql-query") == 0 ||
			req.getContentType().compare(0, 34, "application/sparql-update") == 0) {
			query = req.getBody();
		    } else {
			// If a client demands a new AuthChallenge, send them a 403 until they change username.
			parm = req.parms.find(AuthChallenge);
			if (parm != req.parms.end()) {
			    std::pair<std::string, std::string> userpass = req.getUserPassword();
			    parm = req.parms.find("user");
			    if (parm != req.parms.end() &&
				(userpass.first == parm->second || userpass.first != userpass.second)) {
				HTTPMessageException throwme(webserver::reply::unauthorized, 
							     "text/html", "queen for a day");
				throwme.addHeader("WWW-Authenticate", "Basic realm=Q%26D%20Server");
				throw throwme;
			    }
			}

			parm = req.parms.find("query");
			if (parm != req.parms.end()) {
			    query = parm->second;
			    if (req.parms.get_all("query").size() != 1)
				return webserver::reply::declined;
			    if (req.parms.get_all("update").size() != 0)
				return webserver::reply::declined;
			} else {
			    parm = req.parms.find("update");
			    if (parm != req.parms.end()) {
				query = parm->second;
				if (req.getMethod() == "GET" || req.getMethod() == "HEAD")
				    return webserver::reply::declined;
				if (req.parms.get_all("query").size() != 0)
				    return webserver::reply::declined;
				if (req.parms.get_all("update").size() != 1)
				    return webserver::reply::declined;
			    } else {
				parm = req.parms.find("graph");
				if (parm != req.parms.end())
				    getGraph = engine.db.getGraph(engine.atomFactory.getURI(parm->second));
				else {
				    parm = req.parms.find("default");
				    if (parm != req.parms.end()) {
					getGraph = engine.db.getGraph(DefaultGraph);
					isDefaultGraph = true;
				    }
				}
			    }
			}
		    }
		    if ((path != servicePath && query == interfacePath) ||
			(path == servicePath && query == "")) {
			if (getGraph) {
			    rep.status = webserver::reply::ok;
			    std::string body = getGraph->toString(MediaType("text/turtle"));
			    sout.write(body.c_str(), body.size());
			    rep.setContentType("text/turtle");
			    rep.addHeader("MS-Author-Via", "SPARQL");
			} else
			    return webserver::reply::declined;
		    } else {
			data_loader queryLoadList;
			parm = req.parms.find("default-graph-uri");
			if (parm != req.parms.end() && parm->second != "") {
			    const TTerm* abs(engine.htparseWrapper(parm->second, engine.argBaseURI));
			    queryLoadList.enqueue(NULL, abs, engine.baseURI, engine.dataMediaType);
			    BOOST_LOG_SEV(Logger::IOLog::get(), Logger::info)
				<< "Reading default graph from " << parm->second
				<< engine.baseUriMessage() << ".\n";
			}
			parm = req.parms.find("named-graph-uri");
			while (parm != req.parms.end() && parm->first == "namedGraph" && parm->second != "") {
			    const TTerm* abs(engine.htparseWrapper(parm->second, engine.argBaseURI));
			    queryLoadList.enqueue(abs, abs, engine.baseURI, engine.dataMediaType);
			    BOOST_LOG_SEV(Logger::IOLog::get(), Logger::info)
				<< "Reading named graph " << parm->second
				<< " from " << parm->second
				<< engine.baseUriMessage() << ".\n";
			    ++parm;
			}
			parse_execute_render(query, queryLoadList, req, rep, sout);
		    }
		} else if (path == interfacePath) {
		    html_interface_handler(req, rep, sout);
		} else {
		    if (engine.stopAfter != engine.RunForever && --engine.stopAfter == 0) {
			engine.done = true;
			controller->stop();
		    }
		    return webserver::reply::declined;
		}
		rep.setContent(sout.str());
		return webserver::reply::ok;
	    } catch (ParserException& e) {
		BOOST_LOG_SEV(Logger::IOLog::get(), Logger::error)
		    << e.what() << std::endl;
		rep.status = webserver::reply::bad_request;
		rep.setContentType("text/html");
		rep.setContent(e.what());
		return webserver::reply::internal_server_error;
	    } catch (HTTPMessageException& e) {
		rep.status = e.status;
		for (std::vector<web_util::header>::const_iterator it = e.headers.begin();
		     it != e.headers.end(); ++it)
		    rep.addHeader(*it);
		rep.setContent(e.what());
		return webserver::reply::internal_server_error;
	    } catch (std::exception& e) {
		return errorMessage(rep, req.str(), e.what());
	    } catch (std::string& e) {
		return errorMessage(rep, req.str(), e);
	    }
	}

	webserver::reply::status_type
        errorMessage (webserver::reply& rep, std::string query, std::string what) {
	    std::ostringstream sout;

	    rep.status = webserver::reply::bad_request;
	    BOOST_LOG_SEV(Logger::IOLog::get(), Logger::error)
		<< what << std::endl;
	    head(sout, "Q&amp;D SPARQL Server Error");
	    sout << 
		"    <pre>" << escapeHTML(query) << "</pre>\n"
		"    <p>yeilded</p>\n"
		"    <pre>" << escapeHTML(what) << "</pre>\n"; 
	    foot(sout);
	    rep.setContent(sout.str());
	    return webserver::reply::internal_server_error;
	}
	std::string uriLink (const URI* target) {
	    return std::string() + "&lt;<a href=\"" + escapeHTML(target->getLexicalValue()) + "\">" + escapeHTML(target->getLexicalValue()) + "</a>&gt;";
	}
	std::string DBsummary () {
	    /** Show the user what data exists à la:
		<p>5 triples in 3 graphs:</p>
		<ul>
		<li>Default Graph: <a href='/SPARQL?media=html&amp;query=SELECT+%3Fs+%3Fp+%3Fo+%7B%0A++%3Fs+%3Fp+%3Fo%0A%7D'>0 triples</a>.</li>
		<li>&lt;graphOne&gt;: <a href='/SPARQL?media=html&amp;query=SELECT+%3Fs+%3Fp+%3Fo+%7B%0A++GRAPH+%3CgraphOne%3E+%7B%3Fs+%3Fp+%3Fo%7D%0A%7D'>3 triples</a>.</li>
		<li>&lt;http://localhost:8888/SPARQL&gt;: <a href='/SPARQL?media=html&amp;query=SELECT+%3Fs+%3Fp+%3Fo+%7B%0A++GRAPH+%3Chttp%3A%2F%2Flocalhost%3A8888%2FSPARQL%3E+%7B%3Fs+%3Fp+%3Fo%7D%0A%7D'>2 triples</a>.</li>
		</ul>
	    */
	    std::stringstream sout;
	    size_t triples = engine.db.size();
	    sout << "    <h2>Database Summary</h2>\n";
	    if (triples < 1000) {
		std::set<const TTerm*>graphs = engine.db.getGraphNames();
		sout << "    <p>" << triples << " triples in " << graphs.size() << " graphs";
		if (graphs.size() <= exploreGraphCountLimit) {
		    sout << ":</p>\n    <ul>\n";
		    for (std::set<const TTerm*>::const_iterator g = graphs.begin();
			 g != graphs.end(); ++g) {
			size_t graphSize = engine.db.ensureGraph(*g)->size();
			std::stringstream query;
			query << "SELECT ?s ?p ?o {\n  ";
			query << "?s ?p ?o";

			const URI* asURI = dynamic_cast<const URI*>(*g);
			std::string renderedName = asURI == NULL
			    ? escapeHTML((*g)->toString())
			    : uriLink(asURI);

			sout << "      <li>" << renderedName << ": <a href='";
			query << "\n}";
			if (graphSize > exploreTripleCountLimit)
			    query << " LIMIT " << exploreTripleCountLimit;
			SWWEBagent::ParameterList p;
			p.set("query", query.str());
			p.set("media", "edit");
			sout << escapeHTML(*g == DefaultGraph ? servicePath : (*g)->getLexicalValue()) << "?" << escapeHTML(p.str());
			sout << "'>" << graphSize << " triples</a>.";
			sout << "</li>\n";
		    }
		    sout << "    </ul>\n";
		} else {
		    sout << ".</p>\n";
		}
	    } else
		sout << "    <p>" << triples << " triples in database.</p>\n";
	    return sout.str();
	}
    };

    template <class engine_type, class data_loader, class controller_type>
	std::string SimpleInterface<engine_type, data_loader, controller_type>::CSS_common =
"code {\n"
"  font-weight: bold;\n"
"  }\n"
"\n"
"#requery {\n"
"  margin-top:-1em;\n"
"}\n"
"\n"
"#edit {\n"
"  border:1px solid #000;\n"
"  padding: 1em;\n"
"  background-color: #eee;\n"
"  font-size: smaller;\n"
"  }\n"
"\n"
	    ;
    template <class engine_type, class data_loader, class controller_type>
	std::string SimpleInterface<engine_type, data_loader, controller_type>::CSS_Results =
"#results {\n"
"  font-family:\"Trebuchet MS\", Arial, Helvetica, sans-serif;\n"
"  width:100%;\n"
"  border-collapse:collapse;\n"
"  }\n"
"#results td, #results th {\n"
"  font-size:1.2em;\n"
"  border:1px solid #98bf21;\n"
"  padding:3px 7px 2px 7px;\n"
"  }\n"
"#results th {\n"
"  font-size:1.4em;\n"
"  text-align:left;\n"
"  padding-top:5px;\n"
"  padding-bottom:4px;\n"
"  background-color:#A7C942;\n"
"  color:#fff;\n"
"  }\n"
"#results tr.even td {\n"
"  color:#000;\n"
"  background-color:#EAF2D3;\n"
"  }\n"
	    ;
    template <class engine_type, class data_loader, class controller_type>
	std::string SimpleInterface<engine_type, data_loader, controller_type>::Javascript_TableSorter_remote =
"    <link rel=\"stylesheet\" href=\"http://tablesorter.com/themes/blue/style.css\" type=\"text/css\" media=\"print, projection, screen\" />\n"
"    <script type=\"text/javascript\" src=\"http://tablesorter.com/jquery-latest.js\"></script>\n"
"    <script type=\"text/javascript\" src=\"http://tablesorter.com/jquery.tablesorter.js\"></script>\n"
	    ;
    template <class engine_type, class data_loader, class controller_type>
	std::string SimpleInterface<engine_type, data_loader, controller_type>::Javascript_ToggleDisplay_init =
"	toggleDisplay('requery');\n"
"	var query = document.getElementById('requery');\n"
"	var p = document.createElement('p');\n"
"	document.body.insertBefore(p, query);\n"
"	var input = document.createElement('input');\n"
"	input.setAttribute('type', 'checkbox');\n"
"	input.setAttribute('onclick', 'toggleDisplay(\"requery\")');\n"
"	p.appendChild(input);\n"
"	p.appendChild(document.createTextNode(\" display query\"));\n"
	  ;
    template <class engine_type, class data_loader, class controller_type>
	std::string SimpleInterface<engine_type, data_loader, controller_type>::Javascript_TableSorter_init =
"	$(\"#results\").tablesorter({widgets: ['zebra']});\n"
	  ;
    template <class engine_type, class data_loader, class controller_type>
	std::string SimpleInterface<engine_type, data_loader, controller_type>::Javascript_ToggleDisplay_defn =
"    function toggleDisplay(element){\n"
"	s = document.getElementById(element).style\n"
"	if(s.display == 'none')\n"
"	    s.display = 'block';\n"
"	else\n"
"	    s.display = 'none';\n"
"    }\n"
"    function modify(id){\n"
"	var path = document.getElementById(id + \"_form\").getAttribute(\"action\");\n"
"	var tr = document.getElementById(id);\n"
"	var q = document.getElementById(id + \"_query\");\n"
"	var del = q.value;\n"
"	var off = q.value.indexOf(\";\")\n"
"	if (off != -1)\n"
"	    del = del.substr(0, off);\n"
"\n"
"	var ns = document.getElementById(id + '_0').childNodes[0].nodeValue;\n"
"	var np = document.getElementById(id + '_1').childNodes[0].nodeValue;\n"
"	var no = document.getElementById(id + '_2').childNodes[0].nodeValue;\n"
"\n"
//"	q.value = del + \"; INSERT DATA { GRAPH <\" + path + \"> { \" + ns + \" \" + np + \" \" + no + \" } }\";\n"
"	q.value = del + \"; INSERT DATA { \" + ns + \" \" + np + \" \" + no + \" }\";\n"
"	document.getElementById(id + \"_submit\").value = \"modify\";\n"
"    }\n"
"    function copy (from, to) {\n"
"	var children = document.getElementById(from).childNodes;\n"
"	var q = \"\";\n"
"	for (var i = 0; i < children.length; i++) {\n"
"	    if (children[i].nodeValue != null)\n"
"		q = q + children[i].nodeValue + \"\\n\";\n"
"	}\n"
"	document.getElementById(to).value = q;\n"
"    }\n"
	    ;
    template <class engine_type, class data_loader, class controller_type>
        std::string SimpleInterface<engine_type, data_loader, controller_type>::AuthChallenge = "authChallenge";

class NamespaceAccumulator : public NamespaceMap {
public:
    std::string toString (const char* mediaType = NULL) {
	std::stringstream sstr;
	if (mediaType == NULL)
	    for (NamespaceMap::const_iterator it = begin();
		 it != end(); ++it)
		sstr << it->first << "=> " << it->second->toString() << "\n";
	return sstr.str();
    }
};
class NamespaceRelay : public NamespaceMap {
    NamespaceMap& relay;
public:
    NamespaceRelay (NamespaceMap& relay) : relay(relay) {  }
    virtual void set (std::string prefix, const URI* uri) {
	NamespaceMap::set(prefix, uri);
	relay.set(prefix, uri);
    }
};

struct SimpleEngine {
    const TTerm* htparseWrapper (std::string s, const TTerm* base) {
	std::string baseURIstring = base ? base->getLexicalValue() : "";
	std::string t = libwww::HTParse(s, &baseURIstring, libwww::PARSE_all); // !! maybe with PARSE_less ?
	return atomFactory.getURI(t.c_str());
    }

    struct DBHandlers : public RdfDB::HandlerSet {
	SimpleEngine& engine;
	DBHandlers (SimpleEngine& engine) : engine(engine) {  }
	bool parse (std::string mediaType, std::vector<std::string> args,
		    BasicGraphPattern* target, IStreamContext& istr,
		    std::string nameStr, std::string baseURI,
		    AtomFactory* atomFactory, NamespaceMap* nsMap) {
	    const char* env = ::getenv("XSLT");
	    if (env == NULL)
		return RdfDB::HandlerSet::parse(mediaType, args,
						    target, istr,
						    nameStr, baseURI,
						    atomFactory, nsMap);

	    // break up $XSLT
	    std::vector<std::string> tokens;
	    {
		std::string buf;
		std::stringstream ss(env);
		while (ss >> buf)
		    tokens.push_back(buf);
	    }

	    std::vector<std::string> createdFiles;
	    for (std::vector<std::string>::iterator iToken = tokens.begin();
		 iToken != tokens.end(); ++iToken) {
		if (*iToken == "%DATA") {
		    *iToken = genTempFile(".", *istr);
		    createdFiles.push_back(*iToken);
		} else if (*iToken == "%STYLESHEET") {
		    IStreamContext xsltIstr(args[0], IStreamContext::NONE, NULL, 
						&engine.webClient);
		    *iToken = genTempFile(".", *xsltIstr);
		    createdFiles.push_back(*iToken);
		}
	    }

#ifdef BOOST_PROCESS
	    std::string exec = $tokens[0]; // "/usr/bin/xsltproc"; // POSIX_cat;

	    namespace bp = ::boost::process; 

	    bp::context ctx;
	    ctx.stdout_behavior = bp::capture_stream();
	    bp::child c = bp::launch(exec, tokens, ctx);
	    bp::pistream &pis = c.get_stdout();
#else /* !BOOST_PROCESS */
	    std::stringstream cmd;
	    for (std::vector<std::string>::const_iterator iToken = tokens.begin();
		 iToken != tokens.end(); ++iToken) {
		if (iToken != tokens.begin())
		    cmd << " ";
		cmd << *iToken;
	    }
	    BOOST_LOG_SEV(Logger::ProcessLog::get(), Logger::info) << "Executing \"" << cmd.str().c_str() << "\".\n";
	    FILE *p = POSIX_popen(cmd.str().c_str(), "r"); // 
	    assert(p != NULL);
	    char buf[100];
	    std::string s  = "execution failure";
	    s = "";

	    /* Gave up on [[ ferror(p) ]] because it sometimes returns EPERM on OSX.
	     */
	    for (size_t count; (count = fread(buf, 1, sizeof(buf), p)) || !feof(p);)
		s += std::string(buf, buf + count);
	    POSIX_pclose(p);
	    std::stringstream pis(s);
#endif /* !BOOST_PROCESS */
	    for (std::vector<std::string>::const_iterator iCreatedFile = createdFiles.begin();
		 iCreatedFile != createdFiles.end(); ++iCreatedFile)
		if (POSIX_unlink(iCreatedFile->c_str()) != 0)
		    BOOST_LOG_SEV(Logger::IOLog::get(), Logger::error)
			<< "error unlinking " << *iCreatedFile << ": " << strerror(errno);
	    IStreamContext istr2(istr.nameStr, pis, mediaType.c_str());
	    return engine.db.loadData(target, istr2, nameStr, baseURI, atomFactory, nsMap);
	    //     return RdfDB::HandlerSet::parse(mediaType, args,
	    // 					target, istr,
	    // 					nameStr, baseURI,
	    // 					atomFactory, nsMap);
	}

	static std::string genTempFile (std::string /* dir */, std::istream& istr) {
#ifdef _MSC_VER
	    TCHAR buffer[MAX_PATH+1];
	    DWORD len = ::GetTempPath(MAX_PATH, &buffer[0]);
               
	    std::wstring directory(buffer, len);
	    TCHAR prefix[] = TEXT("SWObj");

	    if (!GetTempFileName(directory.c_str(), prefix, 0, buffer))
		throw ::GetLastError();

	    size_t dlen(wcsnlen(directory.c_str(), MAX_PATH));
	    size_t flen(wcsnlen(buffer, MAX_PATH));
	    std::wstring file(buffer); // +dlen);

	    std::string filename;
	    for (std::wstring::const_iterator it = file.begin();
		 it != file.end(); ++it)
		filename += (char)*it;
	    int fileHandle = POSIX_open(filename.c_str(), POSIX_trunkwrite, POSIX_USER_RW);
#else /* !_MSC_VER */
	    char buf[] = "SWObjXXXXXX";
	    int fileHandle = mkstemp(buf);
	    std::string filename(buf);
#endif /* !_MSC_VER */
	    std::istreambuf_iterator<char> i(istr), e;
	    std::string input(i, e);
	    boost::iostreams::stream_buffer<FileHandleDevice> ofs(fileHandle, filename);
	    std::ostream os(&ofs);
	    os << input;
	    os.flush();
	    ofs.close();
	    POSIX_close(fileHandle);

	    return filename;
	}
    };

    /** FilesystemRdfDB - a TargetedRdfDB which may be backed by files in the
     * filesystem.
     *
     * pathMap: a mapping from paths patterns to filesystem paths, similar to,
     * but more expressive than, an apache Alias.
     */
    struct FilesystemRdfDB : public TargetedRdfDB {

#if REGEX_LIB != SWOb_DISABLED
	struct PathMap {
	    boost::regex from;
	    std::string to;
	    PathMap (const boost::regex from, const std::string to)
		: from(from), to(to)
	    {  }
// 	    bool operator< (const PathMap& r) const {
// 		return from < r.from || to < r.to;
// 	    }
	};
	std::vector<PathMap> pathMaps;
#endif /* REGEX_LIB != SWOb_DISABLED */

	struct MappedPath {
	    const TTerm* name;
	    const std::string path;
	    MappedPath (const TTerm* name, const std::string path)
		: name(name), path(path)
	    {  }
	    bool operator< (const MappedPath& r) const {
		return *name < *(r.name) || path < r.path;
	    }
	};
	SimpleEngine& engine;
	std::set<MappedPath> dirty;

	FilesystemRdfDB (SimpleEngine& engine)
	    : TargetedRdfDB(&engine.webClient, &engine.xmlParser, &engine.rdfDBHandlers), engine(engine)
	{  }

	/** finalEnsureGraph - force calling RdfDB::findGraph(name) so we don't
	 *  endlessly recurse when findGraph gets a graph in which to load data.
	 */
	BasicGraphPattern* finalEnsureGraph (const TTerm* name) {
	    if (name == NULL)
		name = DefaultGraph;
	    BasicGraphPattern* ret = RdfDB::findGraph(name);
	    if (ret == NULL) {
		if (name == DefaultGraph)
		    ret = new DefaultGraphPattern();
		else
		    ret = new NamedGraphPattern(name);
		graphs[name] = ret;
		return ret;
	    } else {
		return ret;
	    }
	}

#if REGEX_LIB != SWOb_DISABLED
	virtual BasicGraphPattern* findGraph (const TTerm* name) {
	    if (name == NULL)
		name = DefaultGraph;
	    if (name == DefaultGraph && defaultTarget != NULL)
		name = defaultTarget;
	    const URI* u = dynamic_cast<const URI*>(name);
	    if (u != NULL) {
		std::string outres = u->getLexicalValue();
		for (std::vector<PathMap>::const_iterator it = pathMaps.begin();
		     it != pathMaps.end(); ++it)
		    outres = regex_replace(outres, it->from, it->to, boost::match_default | boost::format_perl | boost::format_first_only);

		if (outres != u->getLexicalValue()) { // @@ cheesy hack -- should check returns from regex_match, but i don't know how it's constructed.
		    BOOST_LOG_SEV(Logger::IOLog::get(), Logger::info) << "Reading " << name->toString() << " from " << outres << engine.baseUriMessage() << ".\n";
		    try {
			IStreamContext istr(outres, IStreamContext::FILE, NULL, &engine.webClient);
			loadData(finalEnsureGraph(name), istr, engine.uriString(engine.baseURI), 
				 engine.baseURI ? engine.uriString(engine.baseURI) : outres, &engine.atomFactory);
		    } catch (std::string&) {
		    }
		    dirty.insert(MappedPath(name, outres));
		}
	    }
	    return RdfDB::findGraph(name);
	}
#endif /* REGEX_LIB != SWOb_DISABLED */

	void clearGraphLog () {
	    dirty.clear();
	}

	void synch () {
	    for (std::set<MappedPath>::const_iterator it = dirty.begin();
		 it != dirty.end(); ++it) {
		OStreamContext optr(it->path, OStreamContext::FILE,
					engine.dataMediaType.c_str(),
					&engine.webClient);
		BOOST_LOG_SEV(Logger::IOLog::get(), Logger::info) << "Writing " << it->name->toString() << " to " << it->path << ".\n";
		*optr << RdfDB::ensureGraph(it->name)->toString(optr.mediaType.c_str(), &engine.nsAccumulator);
	    }
	    clearGraphLog();
	}

    };

#if HTTP_SERVER == SWOb_ASIO

    struct InotifySet {
	struct InotifyInstance {
	    int watch;
	    const char* name;
	};
	int pollfd;
	std::map<int, InotifyInstance> inotMap;
	std::vector<struct epoll_event> events;
	SimpleEngine& engine;
	std::map<const char*, BasicGraphPattern*> targets;

	InotifySet (SimpleEngine& engine)
	    : pollfd(::epoll_create1(0)), engine(engine)
	{
	    assert(pollfd != -1);
	}
	~InotifySet () {
	    for (std::map<int, InotifyInstance>::const_iterator
		     it = inotMap.begin(); it != inotMap.end(); ++it) {
		::inotify_rm_watch(it->first, it->second.watch);
		::close(it->first);
	    }
	    ::close(pollfd);
	}

	size_t size () const {
	    return inotMap.size();
	}
	void add (const char* name, BasicGraphPattern* target) {
	    targets[name] = target;
	    int inotifyInstance = ::inotify_init1(IN_NONBLOCK);
	    assert(inotifyInstance > 0);
	    inotMap[inotifyInstance].name = name;
	    inotMap[inotifyInstance].watch
		= inotify_add_watch(inotifyInstance, name, 
				    IN_DELETE_SELF|IN_MODIFY|IN_MOVE_SELF);
	    struct epoll_event event;
	    event.data.fd = inotifyInstance;
	    event.events = EPOLLIN | EPOLLET;
	    assert(::epoll_ctl(pollfd, EPOLL_CTL_ADD,
			       inotifyInstance, &event) != -1);
	}
	const char* _name (int inotifyInstance) const {
	    std::map<int, InotifyInstance>::const_iterator it
		= inotMap.find(inotifyInstance);
	    assert(it != inotMap.end());
	    return it->second.name;
	}
	/**
	 * example usage:
	 *   for (int j = 0; j < 3; ++j) {
	 *   	   std::vector<const char*> fns = fd2.poll();
	 *   	   for (std::vector<const char*>::const_iterator it = fns.begin();
	 *   	        it != fns.end(); ++it)
	 *   	       std::cerr << "modified " << *it << "\n";
	 *   }
	 */
	std::vector<const char*> poll () {
	    std::vector<const char*> ret;
	    std::set<const char*> seen;
	    events.resize(size());
	    int ready = ::epoll_wait (pollfd, &events[0], events.size(), -1);
	    for (int eventNo = 0; eventNo < ready; eventNo++) {
		// w3c_sw_LINEN << "ready " << events[eventNo].data.fd << "\n";
		if ((events[eventNo].events & EPOLLERR) ||
		    (events[eventNo].events & EPOLLHUP) ||
		    (!(events[eventNo].events & EPOLLIN))) {
		    /* An error has occured on this fd, or the socket is not
		       ready for reading (why were we notified then?) */
		    w3c_sw_LINEN << "epoll error on " << events[eventNo].data.fd << "\n";
		    ::close(events[eventNo].data.fd);
		    continue;
		} else {
		    /* reasonable guess as to size of 1024 events */
			char buf[2 * (sizeof(struct inotify_event) + 16)];
		    for (;;) {
			int len = ::read(events[eventNo].data.fd, buf, sizeof(buf));
			if (len < 0) {
			    if (errno == EINTR) {
				w3c_sw_LINEN << "EINTR in epoll_wait\n"; // reissue system call
			    } else if (errno == EWOULDBLOCK) {
				// w3c_sw_LINEN << "EWOULDBLOCK\n";
				break;
			    } else {
				w3c_sw_LINEN << errno;
				perror (": read error in epoll_wait");
				w3c_sw_LINEN << "Closed connection on descriptor "
					     << events[eventNo].data.fd << "\n";
				::close(events[eventNo].data.fd); // automatically removed
				break;
			    }
			} else if (!len) {
			    /* BUF_LEN too small? */
			    assert(false);
			} else {
			    for (int readOffset = 0; readOffset < len; ) {
				struct inotify_event *event;

				event = (struct inotify_event *) &buf[readOffset];

				const char* name
				    = event->len
				    ? event->name
				    : _name(events[eventNo].data.fd);
				// w3c_sw_LINEN << name
				// 		 << ": wd=" << event->wd
				// 		 << " mask=" << event->mask
				// 		 << " cookie=" << event->cookie
				// 		 << " len=" << event->len << "\n";
				if (seen.find(name) == seen.end()) {
				    seen.insert(name);
				    ret.push_back(name);
				}

				if (false) {
				    w3c_sw_LINEN << "Closed connection on descriptor "
						 << events[eventNo].data.fd << "\n";
				    ::close(events[eventNo].data.fd); // automatically removed
				}

				readOffset += sizeof(struct inotify_event) + event->len;
			    }
			}
		    }
		}
	    }
	    return ret;
	}

	void start () {
	    m_Thread = boost::thread(&InotifySet::spin, this);
	}

	void join () {
	    m_Thread.join();
	}
    
	void interrupt () {
	    m_Thread.interrupt();
	}
    
	void spin () {
	    for (;;) {
		std::vector<const char*> fns = poll();
		for (std::vector<const char*>::const_iterator it = fns.begin();
		     it != fns.end(); ++it) {
		    w3c_sw_LINEN << "loading: " << *it << "\n";

		    IStreamContext istr(*it, IStreamContext::FILE, NULL, NULL); // &engine.webClient
		    // loadData(finalEnsureGraph(name), istr, engine.uriString(engine.baseURI), 
		    // 	 engine.baseURI ? engine.uriString(engine.baseURI) : outres, &engine.atomFactory);

		    boost::mutex::scoped_lock lock(engine.executeMutex);
		    targets[*it]->clearTriples();
		    engine.turtleParser.parse(istr, targets[*it]);
		    // make parser.
		    // db.clearGraphLog();
		    // query->execute(&db, &rs);
		    engine.db.synch();
		    //executeMutex.unlock_shared();
		    // executed = true;
		}
	    }
	}

    protected:

	boost::thread m_Thread;
    };
#endif /* HTTP_SERVER == SWOb_ASIO */

    AtomFactory atomFactory;
    NamespaceAccumulator nsAccumulator;
    NamespaceRelay nsRelay;
    DBHandlers rdfDBHandlers;
    FilesystemRdfDB db;
    W3C_SW_SAXPARSER xmlParser;
    ResultSet resultSet;
    const static unsigned int RunForever = ~0;
    unsigned int stopAfter;
    bool inPlace;
    bool done;
    int served;
    std::string stemURI;
    std::string serviceURI;
    std::string defaultGraphURI;
    bool printQuery, bestEffort;
    SPARQLDriver sparqlParser;
    TurtleDriver turtleParser;
    std::string pkAttribute;
    KeyMap keyMap;
    MapSetDriver mapSetParser;
    ChainingMapper queryMapper;
    SQLConnectInfo sqlConnectInfo;
#if HTTP_SERVER == SWOb_ASIO
    boost::mutex executeMutex;
    InotifySet inotifySet;
#endif /* HTTP_SERVER == SWOb_ASIO */
    GRDDLmap grddlMap;
#if HTTP_CLIENT != SWOb_DISABLED
    console_auth_prompter webClient_authPrompter;
    W3C_SW_WEBAGENT<console_auth_prompter> webClient;
#endif /* HTTP_CLIENT != SWOb_DISABLED */
    const TTerm* baseURI;
    const Construct* sadiOp;
    const Modify* ldpOp;
    std::string baseUriMessage () {
	return (baseURI == NULL)
	    ? std::string(" with no base URI")
	    : std::string(" with base URI ") + baseURI->getLexicalValue();
    }
    std::string uriString (const TTerm* uri) {
	return (uri == NULL)
	    ? ""
	    : std::string(uri->getLexicalValue());
    }

    const TTerm* argBaseURI;
    bool noExec;
    MediaType dataMediaType;

    SimpleEngine (std::string pkAttribute)
	: atomFactory(), nsRelay(nsAccumulator),
	  rdfDBHandlers(*this), db(*this),
	  resultSet(&atomFactory), stopAfter(RunForever), inPlace(false),
	  done(false), served(0), stemURI(""), serviceURI(""),
	  defaultGraphURI(""), printQuery(false), bestEffort(false), 
	  sparqlParser("", &atomFactory), turtleParser("", &atomFactory), 
	  pkAttribute(pkAttribute), mapSetParser("", &atomFactory), 
	  queryMapper(&atomFactory),
#if HTTP_SERVER == SWOb_ASIO
	  inotifySet(*this),
#endif /* HTTP_SERVER == SWOb_ASIO */
#if HTTP_CLIENT != SWOb_DISABLED
	  webClient_authPrompter(),
	  webClient(&webClient_authPrompter),
#endif /* HTTP_CLIENT != SWOb_DISABLED */
	  sadiOp(NULL), ldpOp(NULL),
	  noExec(false)
    {  }

    bool executeQuery (const Operation* query, ResultSet& rs, std::string& language, std::string& finalQuery, const ResultSet* mappingConstants) {
	language = "SPARQL";
	const Operation* delMe = rs.getConstrainedOperation(query);
	if (delMe != NULL)
	    query = delMe;

	if (queryMapper.getRuleCount() > 0) {
	    BOOST_LOG_SEV(Logger::RewriteLog::get(), Logger::info) << "Transforming user query by applying " << queryMapper.getRuleCount() << " rule maps.\n";
	    const Operation* transformed(queryMapper.map(query, mappingConstants));
	    if (delMe != NULL)
		delete delMe;
	    query = delMe = transformed;
	}

	if (Logger::Logging(Logger::RewriteLog_level, Logger::info)) {
	    SPARQLAlgebraSerializer s;
	    query->express(&s);
	    BOOST_LOG_SEV(Logger::RewriteLog::get(), Logger::support) << "<Query_algebra>\n" << s.str() << "</Query_algebra>" << std::endl;
	}

	bool executed = false;
// 	if (rs.size() > 0 && (!serviceURI.empty() || !stemURI.empty())) {
// 	    const Operation* t = rs.getConstrainedOperation (query);
// 	    if (t != NULL) {
// 		if (delMe != NULL)
// 		    delete delMe;
// 		query = delMe = t;
// 	    }
// 	}
	if (!stemURI.empty()) {
	    language = "SQL";
	    char predicateDelims[]={'#',' ',' '};
	    char nodeDelims[]={'/','.',' '};
	    std::string drv = sqlConnectInfo.driver.find("oracle") == 0 ? "oracle" : sqlConnectInfo.driver;
	    SQLizer sqlizer(&atomFactory, stemURI, predicateDelims, nodeDelims, pkAttribute, keyMap, drv);
	    query->express(&sqlizer);
	    finalQuery = sqlizer.getSQLstring();

	    bool doSQLquery = noExec == false && sqlConnectInfo.initialized();
	    BOOST_LOG_SEV(Logger::SQLLog::get(), Logger::info) << "SQL: " << std::endl;
	    if (printQuery || doSQLquery == false) {
		BOOST_LOG_SEV(Logger::SQLLog::get(), Logger::info) << "Final query: " << ".\n";
		std::cout << finalQuery << std::endl;
	    } else
		BOOST_LOG_SEV(Logger::SQLLog::get(), Logger::info) << "SQL Query: " << finalQuery << std::endl;

	    if (doSQLquery == true) {
#ifdef SQL_CLIENT_NONE
		BOOST_LOG_SEV(Logger::SQLLog::get(), Logger::error) <<
		    "Unable to connect to " << sqlConnectInfo.sqlConnectString() << " .\n"
		    "No SQL client libraries linked in.\n";
#else /* !SQL_CLIENT_NONE */
		SQLClientWrapper sqlClient(sqlConnectInfo);
		SQLclient::Result* res;
		try {
		    sqlClient.connect(sqlConnectInfo);
		} catch (std::string ex) {
		    throw std::string("unable to connect to ") + sqlConnectInfo.sqlConnectString() + ": " + ex;
		}
		try {
		    res = sqlClient.executeQuery(finalQuery);
		} catch (std::string ex) {
		    throw ex + "\n" + sqlConnectInfo.sqlConnectString() + " was unable to execute " + finalQuery;
		}
		SqlResultSet rs2(&atomFactory, res);
		sqlizer.postEval(&rs2);
		rs.joinIn(&rs2);
		executed = true;
#endif /* !SQL_CLIENT_NONE */
	    }
	} else {
	    if (!serviceURI.empty()) {
		SWWEBagent::ParameterList p;
		p.set("query", query->toString());
		if (!defaultGraphURI.empty())
		    p.set("default-graph-uri", defaultGraphURI);
		if (printQuery) {
		    BOOST_LOG_SEV(Logger::ServiceLog::get(), Logger::info) << "Service query: " << std::endl;
		    std::cout << serviceURI << " " << p << std::endl;
		}
		if (noExec == false) {
		    boost::shared_ptr<IStreamContext> istr;
		    switch (ServiceGraphPattern::defaultHTTPmethod) {
		    case ServiceGraphPattern::HTTP_METHOD_GET:
			istr = webClient.get(serviceURI.c_str(), p);
			break;
		    case ServiceGraphPattern::HTTP_METHOD_POST:
			istr = webClient.post(serviceURI.c_str(), p);
			break;
		    default:
			throw "program flow exception -- unknown defaultHTTPmethod";
		    }
		    if (dataMediaType) // override with command line argument for media type.
			istr->mediaType = dataMediaType;
		    if (!loadDataOrResults(DefaultGraph, serviceURI, baseURI, *istr, rs, rs.getRdfDB()))
			rs.resultType = ResultSet::RESULT_Graphs;
		    executed = true;
		}
	    } else {
		if (printQuery) {
		    BOOST_LOG_SEV(Logger::RewriteLog::get(), Logger::info) << "Final query: " << ".\n";
		    std::cout << query->toString() << std::endl;
		}
		if (noExec == false) {
#if HTTP_SERVER == SWOb_ASIO
		    boost::mutex::scoped_lock lock(executeMutex);
		    /* Is this how one implements a single-writer lock with a shared_mutex?
		     *   if query->readOnly() executeMutex.lock_shared(); */
#endif /* HTTP_SERVER == SWOb_ASIO */
		    db.clearGraphLog();
		    query->execute(&db, &rs);
		    db.synch();
		    //executeMutex.unlock_shared();
		    executed = true;
		}
	    }
	}
	if (delMe != NULL)
	    delete delMe;
	return executed;
    }

    bool loadDataOrResults (const TTerm* graph,
			    std::string nameStr,
			    const TTerm* baseURI,
			    IStreamContext& istr,
			    ResultSet& rs,
			    RdfDB* db) {
	/**
	 * Look for a couple of sparql-specific non-standard "media types".
	 */
	if (istr.mediaType.match("application/sparql-results+xml")) {
	    if (Logger::Logging(Logger::IOLog_level, Logger::info)) {
		std::stringstream o;
		o << "Reading SPARQL XML Result Set " << nameStr;
		if (baseURI != NULL)
		    o << " with base URI <" << baseURI->getLexicalValue() << ">";
		o << " into result set.\n";
		BOOST_LOG_SEV(Logger::IOLog::get(), Logger::info) << o.str();
	    }
	    ResultSet loaded(&atomFactory, &xmlParser, istr);
	    rs.joinIn(&loaded);
	    rs.resultType = loaded.resultType;
	    return true;
	} else if // ResultSet media types:
		(istr.mediaType.match("text/columns") ||
		 istr.mediaType.match("text/sparql-results") ||
		 istr.mediaType.match("text/csv") ||
		 istr.mediaType.match("text/tab-separated-values") ||
		 istr.mediaType.match("application/sparql-results+json") ||
		 istr.mediaType.match("application/binary-rdf-results-table") ||
		 istr.mediaType.match("application/x-binary-rdf-results-table")) {
	    if (Logger::Logging(Logger::IOLog_level, Logger::info)) {
		std::stringstream o;
		o << "Reading data table " << nameStr;
		if (baseURI != NULL)
		    o << " with base URI <" << baseURI->getLexicalValue() << ">";
		o << " into result set.\n";
		BOOST_LOG_SEV(Logger::IOLog::get(), Logger::info) << o.str();
	    }
	    TTerm::String2BNode bnodeMap;
	    ResultSet loaded(&atomFactory, istr, false, &bnodeMap);
	    rs.joinIn(&loaded);
	    rs.resultType = loaded.resultType;
	    return true;
	} else {
	    /**
	     * All other media types are loaded via RdfDB::loadData.
	     */
	    if (Logger::Logging(Logger::IOLog_level, Logger::info)) {
		std::stringstream o;
		o << "Reading " << nameStr;
		if (baseURI != NULL)
		    o << " with base URI <" << baseURI->getLexicalValue() << ">";
		if (istr.mediaType)
		    o << " with media type " << *istr.mediaType;
		if (graph != NULL)
		    o << " into " << graph->toString();
		o << ".\n";
		BOOST_LOG_SEV(Logger::IOLog::get(), Logger::info) << o.str();
	    }
	    std::string parserBaseURI =
		baseURI ? uriString(baseURI) :
		nameStr.find("data:") == 0 ? "" : // EGP: decided data: URIs don't contribute a base.
		nameStr;
	    db->loadData(db->ensureGraph(graph), istr, uriString(baseURI), 
			 parserBaseURI, &atomFactory, &nsAccumulator, &grddlMap);
	    rs.resultType = ResultSet::RESULT_Graphs;
	    return false;
	}
    }

};

} /* namespace w3c_sw */

#endif /* !INCLUDED_lib_SimpleServer_hpp */

