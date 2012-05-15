/** SimpleServer tools
 *
 * in progress, see ../bin/sparql.cpp for example of use
 */

#ifndef INCLUDED_lib_SimpleServer_hpp
 #define INCLUDED_lib_SimpleServer_hpp

namespace w3c_sw {

    template <class engine_type, class data_loader, class controller_type>
    class SimpleInterface : public WebHandler {
	engine_type& engine;
	controller_type* controller;
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

    public:
	SimpleInterface (engine_type& engine, controller_type* controller, std::string servicePath, std::string interfacePath) : 
	    WebHandler("."), // @@ docroot is irrelevant -- create a docserver
	    engine(engine), controller(controller), servicePath(servicePath), interfacePath(interfacePath),
	    // hard-code explore*CountLimit
	    exploreTripleCountLimit(100), exploreGraphCountLimit(10)
	{  }

    protected:

	webserver::reply::status_type
	handle_request (webserver::request& req, webserver::reply& rep) {
	    std::string query;
	    try {
		std::string path(req.getPath());
		path.erase(0, 1); // get rid of leading '/' to keep stuff relative.
		std::ostringstream sout;
		data_loader queryLoadList;
		const BasicGraphPattern* getGraph = engine.db.getGraph(engine.atomFactory.getURI(path));

		if (req.getMethod() == "PUT") {
		    const URI* into = engine.atomFactory.getURI(req.getPath());
		    BasicGraphPattern* bgp = engine.db.ensureGraph(into);
		    IStreamContext istr(req.getBody(), IStreamContext::STRING, req.getContentType().c_str());
		    NamespaceMap map;
		    engine.db.loadData(bgp, istr, req.getPath(), "", &engine.atomFactory, &map);

		    rep.setStatus(webserver::reply::ok);
		    head(sout, "Q&amp;D SPARQL Server PUT Successful");
		    sout << 
			"    <p>Uploaded " << bgp->size() << " triples into " << uriLink(into) << "</p>\n";
		    sout << DBsummary();

		    rep.setContentType("text/html");
		    foot(sout);
		} else if (path == servicePath || getGraph != NULL) {
		    webserver::request::parmmap::const_iterator parm;
		    if (req.getMethod() == "GET"
			|| (req.getMethod() == "POST" && req.getContentType().compare(0, 33, "application/x-www-form-urlencoded") == 0)) {
			parm = req.parms.find("query");
			if (parm != req.parms.end())
			    query = parm->second;
		    } else if (req.getMethod() == "POST" && req.getContentType().compare(0, 24, "application/sparql-query") == 0)
			query = req.getBody();
		    if (query == interfacePath && path != servicePath) {
			rep.status = webserver::reply::ok;
			std::string body = getGraph->toString(MediaType("text/turtle"));
			sout.write(body.c_str(), body.size());
			rep.setContentType("text/turtle");
			rep.addHeader("MS-Author-Via", "SPARQL");
		    } else {
			parm = req.parms.find("default-graph-uri");
			if (parm != req.parms.end() && parm->second != "") {
			    const TTerm* abs(engine.htparseWrapper(parm->second, engine.argBaseURI));
			    queryLoadList.enqueue(NULL, abs, engine.baseURI, engine.dataMediaType);
			    std::cerr << "default graph: " << parm->second << std::endl;
			}
			parm = req.parms.find("named-graph-uri");
			while (parm != req.parms.end() && parm->first == "namedGraph" && parm->second != "") {
			    const TTerm* abs(engine.htparseWrapper(parm->second, engine.argBaseURI));
			    queryLoadList.enqueue(abs, abs, engine.baseURI, engine.dataMediaType);
			    std::cerr << "named graph: " << parm->second << std::endl;
			    ++parm;
			}
			if (!controller->getStopCommand().empty() && query == controller->getStopCommand()) {
			    rep.status = webserver::reply::ok;
			    head(sout, "Done!");
			    sout << "    <p>Served " << engine.served << " queries.</p>\n";
			    foot(sout);

			    engine.done = true;
			    controller->stop();
			} else {
			    IStreamContext istr(query, IStreamContext::STRING);
			    try {
				Operation* op = engine.sparqlParser.parse(istr);
				if (op == NULL) { // @@@ i think this can't be reached; that is, return NULL would entail having thrown an exception.
				    head(sout, "Query Error");

				    sout << "    <p>Query</p>\n"
					"    <pre>" << XMLSerializer::escapeCharData(query) << "</pre>\n"
					"    <p>is screwed up.</p>\n"
					 << std::endl;
				    std::cerr << "400: " << query << std::endl;
				    rep.status = webserver::reply::bad_request;

				    foot(sout);
				} else {
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
					    engine.db.setTarget(engine.atomFactory.getURI(path));
					engine.executeQuery(op, rs, language, newQuery);
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
					std::cerr << ex.what() << std::endl;
					throw WebHandler::SimpleMessageException(ex);
				    } catch (std::string ex) {
					delete op;
					std::cerr << ex << std::endl;
					throw WebHandler::SimpleMessageException(XMLSerializer::escapeCharData(ex));
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

						    XMLSerializer::Attributes submitAttrs;
						    submitAttrs["type"] = "submit";
						    submitAttrs["value"] = "re-query";
						    submitAttrs["onclick"] = "copy('edit', 'query')";
						    submitAttrs["style"] = "margin: 2em;";
						    xml.empty("input", submitAttrs);
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
				    if (engine.runOnce) {
					engine.done = true;
					controller->stop();
				    }
				}
			    } catch (ParserException& ex) {
				std::cerr << ex.what() << std::endl;
				throw WebHandler::SimpleMessageException(ex);
			    }
			}
		    }
		} else if (path == interfacePath) {
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
		} else {
		    return webserver::reply::declined;
		}
		rep.setContent(sout.str());
		return webserver::reply::ok;
	    }
	    catch (SimpleMessageException& e) {
		rep.status = webserver::reply::bad_request;
		rep.setContentType("text/html");
		rep.setContent(e.what());
	    } catch (std::exception& e) {
		errorMessage(rep, query, e.what());
	    } catch (std::string& e) {
		errorMessage(rep, query, e);
	    }
	    return webserver::reply::internal_server_error;
	}

	void errorMessage (webserver::reply& rep, std::string query, std::string what) {
	    std::ostringstream sout;

	    rep.status = webserver::reply::bad_request;
	    std::cerr << what << std::endl;
	    head(sout, "Q&amp;D SPARQL Server Error");
	    sout << 
		"    <pre>" << escapeHTML(query) << "</pre>\n"
		"    <p>yeilded</p>\n"
		"    <pre>" << escapeHTML(what) << "</pre>\n"; 
	    foot(sout);
	    rep.setContent(sout.str());
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
		    std::cerr << "error unlinking " << *iCreatedFile << ": " << strerror(errno);
	    IStreamContext istr2(istr.nameStr, pis, mediaType.c_str());
	    return engine.db.loadData(target, istr2, nameStr, baseURI, atomFactory, nsMap);
	    //     return RdfDB::HandlerSet::parse(mediaType, args,
	    // 					target, istr,
	    // 					nameStr, baseURI,
	    // 					atomFactory, nsMap);
	}

	static std::string genTempFile (std::string dir, std::istream& istr) {
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

    AtomFactory atomFactory;
    NamespaceAccumulator nsAccumulator;
    NamespaceRelay nsRelay;
    DBHandlers rdfDBHandlers;
    FilesystemRdfDB db;
    W3C_SW_SAXPARSER xmlParser;
    ResultSet resultSet;
    bool runOnce;
    bool inPlace;
    bool done;
    int served;
    std::string stemURI;
    std::string serviceURI;
    std::string defaultGraphURI;
    bool printQuery;
    SPARQLfedDriver sparqlParser;
    TurtleSDriver turtleParser;
    std::string pkAttribute;
    KeyMap keyMap;
    MapSetDriver mapSetParser;
    ChainingMapper queryMapper;
    SQLConnectInfo sqlConnectInfo;
#if HTTP_SERVER == SWOb_ASIO
    boost::mutex executeMutex;    
#endif /* HTTP_SERVER == SWOb_ASIO */
    GRDDLmap grddlMap;
#if HTTP_CLIENT != SWOb_DISABLED
    console_auth_prompter webClient_authPrompter;
    W3C_SW_WEBAGENT<console_auth_prompter> webClient;
#endif /* HTTP_CLIENT != SWOb_DISABLED */
    const TTerm* baseURI;
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
	  resultSet(&atomFactory), runOnce(false), inPlace(false),
	  done(false), served(0), stemURI(""), serviceURI(""),
	  defaultGraphURI(""), printQuery(false), 
	  sparqlParser("", &atomFactory), turtleParser("", &atomFactory), 
	  pkAttribute(pkAttribute), mapSetParser("", &atomFactory), 
	  queryMapper(&atomFactory),
#if HTTP_CLIENT != SWOb_DISABLED
	  webClient_authPrompter(),
	  webClient(&webClient_authPrompter),
#endif /* HTTP_CLIENT != SWOb_DISABLED */
	  noExec(false)
    {  }

    bool executeQuery (const Operation* query, ResultSet& rs, std::string& language, std::string& finalQuery) {
	language = "SPARQL";
	const Operation* delMe = rs.getConstrainedOperation(query);
	if (delMe != NULL)
	    query = delMe;

	if (queryMapper.getRuleCount() > 0) {
	    BOOST_LOG_SEV(Logger::RewriteLog::get(), Logger::info) << "Transforming user query by applying " << queryMapper.getRuleCount() << " rule maps.\n";
	    const Operation* transformed(queryMapper.map(query));
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
		std::cerr <<
		    "Unable to connect to " << sqlConnectString() << " .\n"
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
	} else if (istr.mediaType.match("text/sparql-results") ||
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
	    ResultSet loaded(&atomFactory, istr, false, bnodeMap);
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
		o << " into " << graph->toString() << ".\n";
		BOOST_LOG_SEV(Logger::IOLog::get(), Logger::info) << o.str();
	    }
	    db->loadData(db->ensureGraph(graph), istr, uriString(baseURI), 
			 baseURI ? uriString(baseURI) : nameStr, &atomFactory, &nsAccumulator, &grddlMap);
	    rs.resultType = ResultSet::RESULT_Graphs;
	    return false;
	}
    }

};

} /* namespace w3c_sw */

#endif /* !INCLUDED_lib_SimpleServer_hpp */

