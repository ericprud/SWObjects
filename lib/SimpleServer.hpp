/** SimpleServer tools
 *
 * in progress, see ../bin/sparql.cpp for example of use
 */

#ifndef INCLUDED_lib_SimpleServer_hpp
 #define INCLUDED_lib_SimpleServer_hpp

namespace w3c_sw {

    template <class server_type, class data_loader>
    class SimpleInterface : public sw::WebHandler {
	server_type& server;
	size_t exploreTripleCountLimit;
	size_t exploreGraphCountLimit;

	static std::string CSS_common;
	static std::string CSS_Results;
	static std::string Javascript_TableSorter_remote;
	static std::string Javascript_ToggleDisplay_init;
	static std::string Javascript_TableSorter_init;
	static std::string Javascript_ToggleDisplay_defn;

    public:
	SimpleInterface (server_type& server) : 
	    WebHandler("."), // @@ docroot is irrelevant -- create a docserver
	    server(server),
	    // hard-code explore*CountLimit
	    exploreTripleCountLimit(100), exploreGraphCountLimit(10)
	{  }

    protected:

	sw::webserver::reply::status_type
	handle_request (w3c_sw::webserver::request& req, w3c_sw::webserver::reply& rep) {
	    std::string query;
	    try {
		std::string path(req.getPath());
		path.erase(0, 1); // get rid of leading '/' to keep stuff relative.
		std::ostringstream sout;
		data_loader queryLoadList;
		const sw::BasicGraphPattern* getGraph = server.db.getGraph(server.atomFactory.getURI(path));

		if (req.method == "PUT") {
		    const sw::URI* into = server.atomFactory.getURI(req.getPath());
		    sw::BasicGraphPattern* bgp = server.db.ensureGraph(into);
		    sw::IStreamContext istr(req.body, sw::IStreamContext::STRING, req.content_type.c_str());
		    sw::NamespaceMap map;
		    server.db.loadData(bgp, istr, req.getPath(), "", &server.atomFactory, &map);

		    rep.status = sw::webserver::reply::ok;
		    head(sout, "Q&amp;D SPARQL Server PUT Successful");
		    sout << 
			"    <p>Uploaded " << bgp->size() << " triples into " << uriLink(into) << "</p>\n";
		    sout << DBsummary();

		    rep.addHeader("Content-Type", "text/html");
		    foot(sout);
		} else if (getGraph != NULL) {
		    sw::webserver::request::parmmap::const_iterator parm;
		    if (req.method == "GET"
			|| (req.method == "POST" && req.content_type.compare(0, 33, "application/x-www-form-urlencoded") == 0)) {
			parm = req.parms.find("query");
			if (parm != req.parms.end())
			    query = parm->second;
		    } else if (req.method == "POST" && req.content_type.compare(0, 24, "application/sparql-query") == 0)
			query = req.body;
		    if (query == "" && path != server.path) {
			rep.status = sw::webserver::reply::ok;
			std::string body = getGraph->toString(sw::MediaType("text/turtle"));
			sout.write(body.c_str(), body.size());
			rep.addHeader("Content-Type", "text/turtle");
			rep.addHeader("MS-Author-Via", "SPARQL");
		    } else {
			parm = req.parms.find("default-graph-uri");
			if (parm != req.parms.end() && parm->second != "") {
			    const sw::TTerm* abs(server.htparseWrapper(parm->second, server.argBaseURI));
			    queryLoadList.enqueue(NULL, abs, server.baseURI, server.dataMediaType);
			    std::cerr << "default graph: " << parm->second << std::endl;
			}
			parm = req.parms.find("named-graph-uri");
			while (parm != req.parms.end() && parm->first == "namedGraph" && parm->second != "") {
			    const sw::TTerm* abs(server.htparseWrapper(parm->second, server.argBaseURI));
			    queryLoadList.enqueue(abs, abs, server.baseURI, server.dataMediaType);
			    std::cerr << "named graph: " << parm->second << std::endl;
			    ++parm;
			}
			if (query == "stop") {
			    head(sout, "Done!");
			    sout << "    <p>Served " << server.served << " queries.</p>\n";
			    foot(sout);

			    server.done = true;
			} else {
			    sw::IStreamContext istr(query, sw::IStreamContext::STRING);
			    try {
				sw::Operation* op = server.sparqlParser.parse(istr);
				if (op == NULL) { // @@@ i think this can't be reached; that is, return NULL would entail having thrown an exception.
				    head(sout, "Query Error");

				    sout << "    <p>Query</p>\n"
					"    <pre>" << sw::XMLSerializer::escapeCharData(query) << "</pre>\n"
					"    <p>is screwed up.</p>\n"
					 << std::endl;
				    std::cerr << "400: " << query << std::endl;
				    rep.status = sw::webserver::reply::bad_request;

				    foot(sout);
				} else {
				    parm = req.parms.find("media");
				    bool humanReader = (parm != req.parms.end()
							&& (parm->second == "html"
							    || parm->second == "edit"
							    || parm->second == "tablesorter"));

				    sw::ResultSet rs(&server.atomFactory);
				    sw::RdfDB constructed; // For operations which create a new database.
				    rs.setRdfDB(dynamic_cast<sw::Construct*>(op) != NULL && !server.inPlace ? &constructed : &server.db);
				    std::string language;
				    std::string newQuery(query);

				    try {
					queryLoadList.loadAll();
					if (path != server.path)
					    server.db.setTarget(server.atomFactory.getURI(path));
					server.executeQuery(op, rs, language, newQuery);
					if (humanReader &&
					    (dynamic_cast<sw::GraphChange*>(op) != NULL || 
					     dynamic_cast<sw::OperationSet*>(op) != NULL)) { // @@@ OperationSet *currently* only used for updates.
					    /** 
					     * For a nice human interface, we can do
					     * another query to report the resulting
					     * database.
					     */
					    delete op;
					    rs.clear();
					    op = server.sparqlParser.parse("SELECT ?s ?p ?o {\n  ?s ?p ?o\n}");
					    op->execute(&server.db, &rs);
					}
					server.db.setTarget(NULL);
					delete op;
				    } catch (sw::ParserException& ex) {
					delete op;
					std::cerr << ex.what() << std::endl;
					throw sw::WebHandler::SimpleMessageException(ex);
				    } catch (std::string ex) {
					delete op;
					std::cerr << ex << std::endl;
					throw sw::WebHandler::SimpleMessageException(sw::XMLSerializer::escapeCharData(ex));
				    }
				    const sw::VariableVector cols = rs.getOrderedVars();

				    sw::XMLSerializer xml("  ");
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
					    sw::XMLSerializer::Attributes preAttrs;
					    preAttrs["id"] = "edit";
					    preAttrs["contenteditable"] = "true";
					    preAttrs["style"] = "display:block; float:left;";
					    xml.leaf("pre", newQuery, preAttrs);
					    xml.open("form"); {
						xml.attribute("action", path);
						xml.attribute("method", "get");
						xml.open("p"); {
						    sw::XMLSerializer::Attributes queryAttrs;
						    queryAttrs["type"] = "hidden";
						    queryAttrs["value"] = "";
						    queryAttrs["id"] = "query";
						    queryAttrs["name"] = "query";
						    xml.empty("input", queryAttrs);

						    sw::XMLSerializer::Attributes mediaAttrs;
						    mediaAttrs["type"] = "hidden";
						    mediaAttrs["value"] = "edit";
						    mediaAttrs["name"] = "media";
						    xml.empty("input", mediaAttrs);

						    sw::XMLSerializer::Attributes submitAttrs;
						    submitAttrs["type"] = "submit";
						    submitAttrs["value"] = "re-query";
						    submitAttrs["onclick"] = "copy('edit', 'query')";
						    submitAttrs["style"] = "margin: 2em;";
						    xml.empty("input", submitAttrs);
						} xml.close(); // p
					    } xml.close(); // form
					} xml.close(); // div

					sw::XMLSerializer::Attributes resultsAttrs;
					resultsAttrs["id"] = "results";
					resultsAttrs["class"] = "tablesorter";
					rs.toHtmlTable(&xml, resultsAttrs, path == server.path ? "" : path);

					/** construct reply from headers and XHTML body */
					rep.status = sw::webserver::reply::ok;
					rep.addHeader("Content-Type", 
						      "text/html; charset=UTF-8");
					sout << xml.str();
					foot(sout);

				    } else if (parm != req.parms.end() && parm->second == "textplain") {
					head(sout, "SPARQL Query Results");

					// cute lexical representation of xml nesting:
					xml.leaf("pre", newQuery);
					rep.status = sw::webserver::reply::ok;
					rep.addHeader("Content-Type", 
						      "text/html; charset=UTF-8");

					sw::XMLSerializer rsSerializer("  ");
					rs.toXml(&rsSerializer);
					std::string source(rsSerializer.str());
					xml.leaf("pre", rsSerializer.str());

					sout << xml.str();
					foot(sout);
				    } else { /* !htmlResults */
					rep.status = sw::webserver::reply::ok;
					rep.addHeader("Content-Type", 
						      rs.resultType == sw::ResultSet::RESULT_Graphs
						      ? "text/turtle; charset=UTF-8"
						      : "application/sparql-results+xml; charset=UTF-8");
					rs.toXml(&xml);
					sout << xml.str();
				    } /* !htmlResults */

				    ++server.served;
				    if (server.runOnce)
					server.done = true;
				}
			    } catch (sw::ParserException& ex) {
				std::cerr << ex.what() << std::endl;
				throw sw::WebHandler::SimpleMessageException(ex);
			    }
			}
		    }
		} else if (path == "") {
		    rep.status = sw::webserver::reply::ok;
		    head(sout, "Q&amp;D SPARQL Server");
		    const char* method =
			sw::ServiceGraphPattern::defaultHTTPmethod == sw::ServiceGraphPattern::HTTP_METHOD_GET ? "get" :
			"post";
		    sout << 
			"    <form action='" << server.path << "' method='" << method << "'><p>\n"
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
			"    <form action='" << server.path << "' method='post'><p>\n"
			"      server status: running, " << server.served << " served. <input name='query' type='submit' value='stop'/>\n"
			"    </p></form>\n";
		    sout << DBsummary();

		    rep.addHeader("Content-Type", "text/html");
		    foot(sout);
		} else {
		    return sw::webserver::reply::declined;
		}
		rep.content = sout.str();
		return sw::webserver::reply::ok;
	    }
	    catch (SimpleMessageException& e) {
		rep.status = sw::webserver::reply::bad_request;
		rep.addHeader("Content-Type", "text/html");
		rep.content = e.what();
	    } catch (std::exception& e) {
		errorMessage(rep, query, e.what());
	    } catch (std::string& e) {
		errorMessage(rep, query, e);
	    }
	    return sw::webserver::reply::internal_server_error;
	}

	void errorMessage (w3c_sw::webserver::reply& rep, std::string query, std::string what) {
	    std::ostringstream sout;

	    rep.status = sw::webserver::reply::bad_request;
	    std::cerr << what << std::endl;
	    head(sout, "Q&amp;D SPARQL Server Error");
	    sout << 
		"    <pre>" << escapeHTML(query) << "</pre>\n"
		"    <p>yeilded</p>\n"
		"    <pre>" << escapeHTML(what) << "</pre>\n"; 
	    foot(sout);
	    rep.content = sout.str();
	}
	std::string uriLink (const sw::URI* target) {
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
	    size_t triples = server.db.size();
	    sout << "    <h2>Database Summary</h2>\n";
	    if (triples < 1000) {
		std::set<const sw::TTerm*>graphs = server.db.getGraphNames();
		sout << "    <p>" << triples << " triples in " << graphs.size() << " graphs";
		if (graphs.size() <= exploreGraphCountLimit) {
		    sout << ":</p>\n    <ul>\n";
		    for (std::set<const sw::TTerm*>::const_iterator g = graphs.begin();
			 g != graphs.end(); ++g) {
			size_t graphSize = server.db.ensureGraph(*g)->size();
			std::stringstream query;
			query << "SELECT ?s ?p ?o {\n  ";
			query << "?s ?p ?o";

			const sw::URI* asURI = dynamic_cast<const sw::URI*>(*g);
			std::string renderedName = asURI == NULL
			    ? escapeHTML((*g)->toString())
			    : uriLink(asURI);

			sout << "      <li>" << renderedName << ": <a href='";
			query << "\n}";
			if (graphSize > exploreTripleCountLimit)
			    query << " LIMIT " << exploreTripleCountLimit;
			sw::SWWEBagent::ParameterList p;
			p.set("query", query.str());
			p.set("media", "edit");
			sout << escapeHTML(*g == sw::DefaultGraph ? server.path : (*g)->getLexicalValue()) << "?" << escapeHTML(p.str());
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

    template <class server_type, class data_loader>
	std::string SimpleInterface<server_type, data_loader>::CSS_common =
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
    template <class server_type, class data_loader>
	std::string SimpleInterface<server_type, data_loader>::CSS_Results =
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
    template <class server_type, class data_loader>
	std::string SimpleInterface<server_type, data_loader>::Javascript_TableSorter_remote =
"    <link rel=\"stylesheet\" href=\"http://tablesorter.com/themes/blue/style.css\" type=\"text/css\" media=\"print, projection, screen\" />\n"
"    <script type=\"text/javascript\" src=\"http://tablesorter.com/jquery-latest.js\"></script>\n"
"    <script type=\"text/javascript\" src=\"http://tablesorter.com/jquery.tablesorter.js\"></script>\n"
	    ;
    template <class server_type, class data_loader>
	std::string SimpleInterface<server_type, data_loader>::Javascript_ToggleDisplay_init =
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
    template <class server_type, class data_loader>
	std::string SimpleInterface<server_type, data_loader>::Javascript_TableSorter_init =
"	$(\"#results\").tablesorter({widgets: ['zebra']});\n"
	  ;
    template <class server_type, class data_loader>
	std::string SimpleInterface<server_type, data_loader>::Javascript_ToggleDisplay_defn =
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

} /* namespace w3c_sw */

#endif /* !INCLUDED_lib_SimpleServer_hpp */

