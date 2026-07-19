/* algae3serve.inc - `algae3 --serve PORT`: the debugger REPL as a tiny
 * HTTP/JSON service for SPARQL-explorer.html. Single-threaded, one session.
 *
 *   POST /load?mode=topdown   body = Algae 3 script     -> state
 *   POST /step | /run | /reset                          -> state
 *   POST /mode?m=bottomup                               -> state
 *   POST /try                 body = pattern            -> {extended,dropped}
 *   GET  /state                                         -> state
 * state = {mode, pos, done, lastTest, actions:[...], vars:[...],
 *          rows:[[...]], proofs:[[...]], asserted:[...]}
 */

#include <boost/asio.hpp>

namespace a3serve {
    using boost::asio::ip::tcp;

    std::string jesc (const std::string& s) {
	std::string r;
	for (size_t i = 0; i < s.size(); ++i) {
	    char c = s[i];
	    if (c == '"' || c == '\\') { r += '\\'; r += c; }
	    else if (c == '\n') r += "\\n";
	    else if (c == '\t') r += "\\t";
	    else if (c == '\r') r += "\\r";
	    else if ((unsigned char)c < 0x20) r += ' ';
	    else r += c;
	}
	return r;
    }

    struct Session {
	sw::AtomFactory* F;
	std::string baseDir;
	sw::a3::Query* query;
	sw::Algae3Driver* driver;
	sw::a3::Engine* engine;
	size_t pos;
	sw::a3::EvalMode mode;

	Session (sw::AtomFactory* F, std::string baseDir)
	    : F(F), baseDir(baseDir), query(NULL), driver(NULL), engine(NULL),
	      pos(0), mode(sw::a3::EVAL_topdown) {  }
	~Session () { delete engine; delete query; delete driver; }

	void restart () {
	    delete engine;
	    engine = new sw::a3::Engine(F, mode);
	    engine->baseDir = baseDir;
	    pos = 0;
	}

	std::string load (const std::string& script, const std::string& modeStr) {
	    delete query; query = NULL;
	    delete driver; driver = NULL;
	    query = new sw::a3::Query();
	    driver = new sw::Algae3Driver("", F);
	    sw::IStreamContext istr(script, sw::IStreamContext::STRING);
	    istr.nameStr = "posted-script";
	    driver->parse(istr, query);
	    mode = modeStr == "bottomup" ? sw::a3::EVAL_bottomup
		 : modeStr == "topdown" ? sw::a3::EVAL_topdown : query->mode;
	    restart();
	    return state();
	}

	bool step () {
	    if (query == NULL || pos >= query->actions.size())
		return false;
	    engine->mode = mode;
	    engine->apply(*query->actions[pos]);
	    ++pos;
	    return true;
	}

	std::string state (const std::string& err = "") {
	    std::ostringstream j;
	    j << "{\"mode\":\"" << (mode == sw::a3::EVAL_topdown ? "topdown" : "bottomup") << "\"";
	    j << ",\"pos\":" << pos;
	    j << ",\"done\":" << (query == NULL || pos >= query->actions.size() ? "true" : "false");
	    if (!err.empty())
		j << ",\"error\":\"" << jesc(err) << "\"";
	    j << ",\"actions\":[";
	    if (query != NULL)
		for (size_t i = 0; i < query->actions.size(); ++i)
		    j << (i ? "," : "") << "\"" << jesc(query->actions[i]->str(mode)) << "\"";
	    j << "]";
	    /* result set: columns = known vars (name-sorted), rows in order */
	    std::vector<const sw::TTerm*> vars;
	    if (engine != NULL) {
		const sw::VariableList* known = engine->rs->getKnownVars();
		for (sw::VariableListConstIterator it = known->begin(); it != known->end(); ++it)
		    vars.push_back(*it);
		struct ByName { bool operator() (const sw::TTerm* a, const sw::TTerm* b) const {
		    return a->getLexicalValue() < b->getLexicalValue(); } };
		std::sort(vars.begin(), vars.end(), ByName());
	    }
	    j << ",\"vars\":[";
	    for (size_t i = 0; i < vars.size(); ++i)
	        j << (i ? "," : "") << "\"?" << jesc(vars[i]->getLexicalValue()) << "\"";
	    j << "],\"rows\":[";
	    if (engine != NULL) {
		bool firstRow = true;
		for (sw::ResultSetConstIterator r = engine->rs->begin(); r != engine->rs->end(); ++r) {
		    j << (firstRow ? "" : ",") << "[";
		    firstRow = false;
		    for (size_t i = 0; i < vars.size(); ++i) {
			const sw::TTerm* v = (*r)->get(vars[i]);
			j << (i ? "," : "") << "\"" << (v ? jesc(v->toString()) : "") << "\"";
		    }
		    j << "]";
		}
	    }
	    j << "],\"proofs\":[";
	    if (engine != NULL) {
		bool firstRow = true;
		for (sw::ResultSetConstIterator r = engine->rs->begin(); r != engine->rs->end(); ++r) {
		    j << (firstRow ? "" : ",") << "[";
		    firstRow = false;
		    std::map<const sw::Result*, sw::a3::ProofSet>::const_iterator p
			= engine->proofs.find(*r);
		    if (p != engine->proofs.end()) {
			bool firstT = true;
			for (sw::a3::ProofSet::const_iterator t = p->second.begin();
			     t != p->second.end(); ++t) {
			    j << (firstT ? "" : ",") << "\"" << jesc((*t)->toString()) << "\"";
			    firstT = false;
			}
		    }
		    j << "]";
		}
	    }
	    j << "],\"lastTest\":" << (engine != NULL && engine->lastTest ? "true" : "false");
	    j << ",\"asserted\":[";
	    if (engine != NULL)
		for (size_t i = 0; i < engine->asserted.size(); ++i)
		    j << (i ? "," : "") << "\"" << jesc(engine->asserted[i]->toString()) << "\"";
	    j << "]}";
	    return j.str();
	}

	std::string tryPattern (const std::string& text) {
	    if (driver == NULL || engine == NULL)
		return "{\"error\":\"no script loaded\"}";
	    std::string errMsg;
	    const sw::a3::Pattern* p = driver->parsePattern(text, errMsg);
	    if (p == NULL)
		return std::string("{\"error\":\"") + jesc(errMsg) + "\"}";
	    engine->mode = mode;
	    std::pair<size_t, size_t> counts = engine->tryMatch(*p);
	    delete p;
	    std::ostringstream j;
	    j << "{\"extended\":" << counts.first << ",\"dropped\":" << counts.second
	      << ",\"rowsNow\":" << engine->rs->size() << "}";
	    return j.str();
	}
    };

    int serve (int port, sw::AtomFactory* F, std::string baseDir) {
	boost::asio::io_context io;
	tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), port));
	Session session(F, baseDir);
	std::cerr << "algae3 debugger serving on http://localhost:" << port
		  << "/ (base dir " << baseDir << ")\n";
	while (true) {
	    tcp::socket sock(io);
	    acceptor.accept(sock);
	    boost::asio::streambuf buf;
	    boost::system::error_code ec;
	    boost::asio::read_until(sock, buf, "\r\n\r\n", ec);
	    if (ec) continue;
	    std::istream hs(&buf);
	    std::string method, target, version;
	    hs >> method >> target >> version;
	    std::string line;
	    size_t contentLength = 0;
	    bool expectContinue = false;
	    std::getline(hs, line);
	    while (std::getline(hs, line) && line != "\r" && !line.empty()) {
		if (line.compare(0, 15, "Content-Length:") == 0)
		    contentLength = atol(line.substr(15).c_str());
		if (line.compare(0, 7, "Expect:") == 0)
		    expectContinue = true;
	    }
	    if (expectContinue)
		boost::asio::write(sock, boost::asio::buffer(std::string("HTTP/1.1 100 Continue\r\n\r\n")), ec);
	    std::string body;
	    {
		std::ostringstream b;
		b << &buf; // whatever came after the headers
		body = b.str();
		/* strip any leading bytes read past the headers */
		while (body.size() < contentLength) {
		    char tmp[4096];
		    size_t n = sock.read_some(boost::asio::buffer(tmp), ec);
		    if (ec) break;
		    body.append(tmp, n);
		}
		if (body.size() > contentLength)
		    body.resize(contentLength);
	    }
	    std::string path = target, queryStr;
	    size_t q = target.find('?');
	    if (q != std::string::npos) { path = target.substr(0, q); queryStr = target.substr(q+1); }
	    std::map<std::string, std::string> params;
	    {
		size_t s = 0;
		while (s < queryStr.size()) {
		    size_t e = queryStr.find('&', s);
		    std::string kv = queryStr.substr(s, e == std::string::npos ? e : e - s);
		    size_t eq = kv.find('=');
		    if (eq != std::string::npos)
			params[kv.substr(0, eq)] = kv.substr(eq+1);
		    if (e == std::string::npos) break;
		    s = e + 1;
		}
	    }

	    std::string resp;
	    int code = 200;
	    try {
		if (path == "/load")       resp = session.load(body, params["mode"]);
		else if (path == "/step")  { session.step(); resp = session.state(); }
		else if (path == "/run")   { while (session.step()) ; resp = session.state(); }
		else if (path == "/reset") { session.restart(); resp = session.state(); }
		else if (path == "/mode")  {
		    session.mode = params["m"] == "bottomup" ? sw::a3::EVAL_bottomup : sw::a3::EVAL_topdown;
		    resp = session.state();
		}
		else if (path == "/try")   resp = session.tryPattern(body);
		else if (path == "/state") resp = session.state();
		else { code = 404; resp = "{\"error\":\"unknown endpoint\"}"; }
	    } catch (sw::ParserException& e) {
		resp = session.state(e.what());
	    } catch (std::string& e) {
		resp = session.state(e);
	    } catch (std::exception& e) {
		resp = session.state(e.what());
	    }

	    std::ostringstream out;
	    out << "HTTP/1.1 " << code << " OK\r\n"
		<< "Content-Type: application/json\r\n"
		<< "Access-Control-Allow-Origin: *\r\n"
		<< "Access-Control-Allow-Methods: GET, POST\r\n"
		<< "Content-Length: " << resp.size() << "\r\n\r\n" << resp;
	    boost::asio::write(sock, boost::asio::buffer(out.str()), ec);
	}
	return 0;
    }
} // namespace a3serve
