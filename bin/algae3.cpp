/* bin/algae3 - Algae 3 command line: parse, evaluate (both modes), debug.
 *
 *   algae3 file.a3 ...              evaluate; print the final result table
 *   algae3 --algebra file.a3       print the parsed action algebra (per mode)
 *   algae3 --mode topdown|bottomup  override the script's evaluation mode
 *   algae3 --proofs                 show per-row proof sets in tables
 *   algae3 --debug file.a3          step through the pipeline (REPL below)
 *
 * Debugger commands:
 *   step | next     advance one action (into vs over scope sub-pipelines)
 *   into            descend into the next action's first scope pipeline
 *   where           show the pipeline with the current position
 *   print [n]       current result set (first n rows) with proofs
 *   bindings ?v     column view of one variable
 *   watch ?v        break when ?v's binding set changes
 *   try ( pattern ) speculative match: how many rows would extend/drop
 *   mode [m]        show or override the evaluation mode
 *   break N         breakpoint at action ordinal N ; run   continue
 *   reset           back to the start (reload dataset)
 *   quit
 */

#include "SWObjects.hpp"
#include "Algae3.hpp"
#include "Algae3Parser.hpp"
#include "BNodeResolver.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

namespace sw = w3c_sw;

#include "algae3serve.inc"

namespace {

    sw::AtomFactory F;

    std::string dirOf (const std::string& path) {
	size_t slash = path.find_last_of('/');
	return slash == std::string::npos ? "." : path.substr(0, slash);
    }

    std::string readFile (const std::string& path) {
	std::ifstream in(path.c_str(), std::ios::binary);
	if (!in)
	    throw std::string("cannot open \"") + path + "\"";
	std::ostringstream ss;
	ss << in.rdbuf();
	return ss.str();
    }

    /** flatten the pipeline for the debugger: each entry is an action plus
     * its nesting depth (scope sub-pipelines indent) */
    struct Step {
	const sw::a3::Action* action;
	int depth;
	Step (const sw::a3::Action* action, int depth) : action(action), depth(depth) {  }
    };

    void flattenScopes (const sw::a3::Pattern& p, int depth, std::vector<Step>& into);

    void flatten (const sw::a3::Action& a, int depth, std::vector<Step>& into) {
	into.push_back(Step(&a, depth));
	if (const sw::a3::Ask* ask = dynamic_cast<const sw::a3::Ask*>(&a))
	    flattenScopes(*ask->pattern, depth, into);
    }

    struct ScopeFinder : public sw::a3::PatternVisitor {
	int depth;
	std::vector<Step>& into;
	ScopeFinder (int depth, std::vector<Step>& into) : depth(depth), into(into) {  }
	virtual void visit (const sw::a3::DeclPattern&) {  }
	virtual void visit (const sw::a3::FilterPattern&) {  }
	virtual void visit (const sw::a3::UnaryPattern& p) { p.inner->accept(*this); }
	virtual void visit (const sw::a3::ConjPattern& p) {
	    for (std::vector<const sw::a3::Pattern*>::const_iterator it = p.elts.begin();
		 it != p.elts.end(); ++it)
		(*it)->accept(*this);
	}
	virtual void visit (const sw::a3::ConnPattern& p) { p.l->accept(*this); p.r->accept(*this); }
	virtual void visit (const sw::a3::InGraphPattern& p) { p.inner->accept(*this); }
	virtual void visit (const sw::a3::ScopePattern& p) {
	    for (std::vector<const sw::a3::Action*>::const_iterator it = p.pipeline.begin();
		 it != p.pipeline.end(); ++it)
	        flatten(**it, depth + 1, into);
	    if (p.pattern != NULL)
		p.pattern->accept(*this);
	}
	virtual void visit (const sw::a3::ActionPattern&) {  }
    };

    void flattenScopes (const sw::a3::Pattern& p, int depth, std::vector<Step>& into) {
	ScopeFinder f(depth, into);
	p.accept(f);
    }

    /** binding-set snapshot of one variable, for `watch` */
    std::set<const sw::TTerm*> bindingSet (const sw::a3::Engine& e, const sw::TTerm* var) {
	std::set<const sw::TTerm*> ret;
	for (sw::ResultSetConstIterator it = e.rs->begin(); it != e.rs->end(); ++it) {
	    const sw::TTerm* v = (*it)->get(var);
	    if (v != NULL)
		ret.insert(v);
	}
	return ret;
    }

    struct Debugger {
	sw::a3::Query& query;
	sw::Algae3Driver& driver;
	std::string baseDir;
	sw::a3::EvalMode mode;

	sw::a3::Engine* engine;
	size_t pos;                 // next top-level action ordinal
	std::set<size_t> breaks;
	const sw::TTerm* watched;
	std::set<const sw::TTerm*> watchedSet;

	Debugger (sw::a3::Query& query, sw::Algae3Driver& driver, std::string baseDir)
	    : query(query), driver(driver), baseDir(baseDir), mode(query.mode),
	      engine(NULL), pos(0), watched(NULL) {
	    restart();
	}
	~Debugger () { delete engine; }

	void restart () {
	    delete engine;
	    engine = new sw::a3::Engine(&F, mode);
	    engine->baseDir = baseDir;
	    pos = 0;
	}

	const char* modeName () const {
	    return mode == sw::a3::EVAL_topdown ? "topdown" : "bottomup";
	}

	void where () const {
	    for (size_t i = 0; i < query.actions.size(); ++i)
		std::cout << (i == pos ? "-> " : "   ") << i << ": "
			  << query.actions[i]->str(mode) << "\n";
	    if (pos >= query.actions.size())
		std::cout << "-> (end of pipeline)\n";
	}

	bool stepOne () {
	    if (pos >= query.actions.size()) {
		std::cout << "at end of pipeline; `reset` to start over\n";
		return false;
	    }
	    engine->mode = mode;
	    try {
		engine->apply(*query.actions[pos]);
	    } catch (std::string& e) {
		std::cout << "action failed: " << e << "\n";
	    } catch (std::exception& e) {
		std::cout << "action failed: " << e.what() << "\n";
	    }
	    ++pos;
	    if (watched != NULL) {
		std::set<const sw::TTerm*> now = bindingSet(*engine, watched);
		if (now != watchedSet) {
		    std::cout << "watch: " << watched->toString() << " binding set changed ("
			      << watchedSet.size() << " -> " << now.size() << " values)\n";
		    watchedSet = now;
		}
	    }
	    return true;
	}

	void run () {
	    while (pos < query.actions.size()) {
		if (!stepOne())
		    break;
		if (breaks.find(pos) != breaks.end()) {
		    std::cout << "breakpoint at action " << pos << "\n";
		    break;
		}
	    }
	}

	void replayTo (size_t target) {
	    restart();
	    while (pos < target && pos < query.actions.size())
		stepOne();
	}

	void repl () {
	    std::cout << "Algae 3 debugger; mode " << modeName()
		      << "; " << query.actions.size() << " actions. `where` to look around.\n";
	    std::string line;
	    while (true) {
		std::cout << "a3dbg> " << std::flush;
		if (!std::getline(std::cin, line))
		    break;
		std::istringstream ss(line);
		std::string cmd;
		ss >> cmd;
		if (cmd == "" ) continue;
		else if (cmd == "quit" || cmd == "q") break;
		else if (cmd == "step" || cmd == "s" || cmd == "next" || cmd == "n") {
		    /* top-level stepping treats a whole action (with its scope
		     * sub-pipelines) as one step; `into` inspects scopes */
		    if (stepOne())
			std::cout << engine->renderTable(10, false);
		} else if (cmd == "into") {
		    /* show the sub-pipeline of the NEXT action's scopes */
		    if (pos >= query.actions.size()) { std::cout << "at end\n"; continue; }
		    std::vector<Step> steps;
		    flatten(*query.actions[pos], 0, steps);
		    if (steps.size() <= 1) {
			std::cout << "action " << pos << " has no scope sub-pipeline; `step` instead\n";
			continue;
		    }
		    for (size_t i = 0; i < steps.size(); ++i)
			std::cout << std::string(2 * steps[i].depth, ' ')
				  << (steps[i].depth > 0 ? "- " : "* ")
				  << steps[i].action->str(mode) << "\n";
		    std::cout << "(scope pipelines evaluate per enclosing "
			      << (mode == sw::a3::EVAL_topdown ? "row (lateral)" : "scope (isolated)")
			      << "; step executes the whole action)\n";
		} else if (cmd == "where" || cmd == "w") {
		    where();
		} else if (cmd == "print" || cmd == "p") {
		    size_t n = 10;
		    ss >> n;
		    std::cout << engine->renderTable(n, true);
		} else if (cmd == "bindings") {
		    std::string v;
		    ss >> v;
		    if (v.empty() || v[0] != '?') { std::cout << "usage: bindings ?var\n"; continue; }
		    const sw::TTerm* var = F.getVariable(v.substr(1));
		    std::set<const sw::TTerm*> vals = bindingSet(*engine, var);
		    std::cout << v << ": " << vals.size() << " distinct value(s)\n";
		    for (std::set<const sw::TTerm*>::const_iterator it = vals.begin();
			 it != vals.end(); ++it)
			std::cout << "  " << (*it)->toString() << "\n";
		} else if (cmd == "watch") {
		    std::string v;
		    ss >> v;
		    if (v.empty() || v[0] != '?') { std::cout << "usage: watch ?var\n"; continue; }
		    watched = F.getVariable(v.substr(1));
		    watchedSet = bindingSet(*engine, watched);
		    std::cout << "watching " << v << " (" << watchedSet.size() << " values)\n";
		} else if (cmd == "try") {
		    std::string rest;
		    std::getline(ss, rest);
		    std::string errMsg;
		    const sw::a3::Pattern* p = driver.parsePattern(rest, errMsg);
		    if (p == NULL) {
			std::cout << "parse error: " << errMsg << "\n";
			continue;
		    }
		    engine->mode = mode;
		    try {
			std::pair<size_t, size_t> counts = engine->tryMatch(*p);
			std::cout << "try (" << modeName() << "): "
				  << engine->rs->size() << " rows -> ";
			if (counts.first == 0 && counts.second == 0)
			    std::cout << "unchanged row count";
			if (counts.first > 0)
			    std::cout << "+" << counts.first << " extended";
			if (counts.second > 0)
			    std::cout << (counts.first ? ", " : "") << "-" << counts.second << " dropped";
			std::cout << " (discarded)\n";
		    } catch (std::string& e) {
			std::cout << "try failed: " << e << "\n";
		    }
		    delete p;
		} else if (cmd == "mode") {
		    std::string m;
		    ss >> m;
		    if (m.empty())
			std::cout << "mode " << modeName() << "\n";
		    else if (m == "topdown" || m == "bottomup") {
			mode = m == "topdown" ? sw::a3::EVAL_topdown : sw::a3::EVAL_bottomup;
			std::cout << "mode " << modeName()
				  << " (applies to the remaining pipeline; `reset` + `run` for a full re-run)\n";
		    } else
			std::cout << "usage: mode [topdown|bottomup]\n";
		} else if (cmd == "break" || cmd == "b") {
		    size_t n;
		    if (ss >> n) { breaks.insert(n); std::cout << "break at action " << n << "\n"; }
		    else std::cout << "usage: break <action-ordinal>\n";
		} else if (cmd == "run" || cmd == "r" || cmd == "continue" || cmd == "c") {
		    run();
		    std::cout << engine->renderTable(10, false);
		} else if (cmd == "reset") {
		    restart();
		    std::cout << "reset to action 0 (dataset cleared)\n";
		} else if (cmd == "help" || cmd == "h") {
		    std::cout << "step/next into where print [n] bindings ?v watch ?v\n"
			      << "try ( pattern ) mode [m] break N run reset quit\n";
		} else
		    std::cout << "unknown command \"" << cmd << "\"; try help\n";
	    }
	}
    };

} // namespace

/** `attach <http://…/sparql> name` gets a live SPARQL protocol client;
 * BNodeResolver re-identifies response bnodes across round trips. */
static sw::bnr::SPARQLClient* makeHTTPClient (const std::string& iri, sw::AtomFactory* F) {
    return new sw::bnr::HTTPSPARQLClient(F, iri);
}

int main (int argc, char** argv) {
    sw::a3::Engine::attachClientFactory = &makeHTTPClient;
    bool debug = false, algebra = false, proofs = false, sortedBindings = false;
    int servePort = 0;
    std::string serveDir = ".";
    int modeOverride = -1;
    std::vector<std::string> files;

    for (int i = 1; i < argc; ++i) {
	std::string arg = argv[i];
	if (arg == "--debug") debug = true;
	else if (arg == "--algebra") algebra = true;
	else if (arg == "--proofs") proofs = true;
	else if (arg == "--sorted-bindings") sortedBindings = true; // test-golden format
	else if (arg == "--serve" && i+1 < argc) servePort = atoi(argv[++i]);
	else if (arg == "--serve-dir" && i+1 < argc) serveDir = argv[++i];
	else if (arg == "--mode" && i+1 < argc) {
	    std::string m = argv[++i];
	    if (m == "topdown") modeOverride = sw::a3::EVAL_topdown;
	    else if (m == "bottomup") modeOverride = sw::a3::EVAL_bottomup;
	    else { std::cerr << "unknown mode \"" << m << "\"\n"; return 2; }
	} else if (arg == "--help" || arg == "-h") {
	    std::cout << "usage: algae3 [--algebra] [--proofs] [--mode topdown|bottomup] [--debug] file.a3 ...\n";
	    return 0;
	} else
	    files.push_back(arg);
    }
    if (servePort > 0)
	return a3serve::serve(servePort, &F, serveDir);
    if (files.empty()) {
	std::cerr << "usage: algae3 [--algebra] [--proofs] [--mode m] [--debug] file.a3 ...\n";
	return 2;
    }

    int status = 0;
    for (std::vector<std::string>::const_iterator f = files.begin(); f != files.end(); ++f) {
	if (files.size() > 1)
	    std::cout << "-- " << *f << "\n";
	sw::a3::Query query;
	sw::Algae3Driver driver("", &F);
	try {
	    std::string text = readFile(*f);
	    sw::IStreamContext istr(text, sw::IStreamContext::STRING);
	    istr.nameStr = *f;
	    driver.parse(istr, &query);
	} catch (sw::ParserException& e) {
	    std::cerr << *f << ": " << e.what() << "\n";
	    status = 1;
	    continue;
	} catch (std::string& e) {
	    std::cerr << *f << ": " << e << "\n";
	    status = 1;
	    continue;
	}
	if (modeOverride >= 0)
	    query.mode = (sw::a3::EvalMode)modeOverride;

	if (algebra) {
	    std::cout << query.str() << "\n";
	    continue;
	}

	if (debug) {
	    Debugger dbg(query, driver, dirOf(*f));
	    dbg.repl();
	    continue;
	}

	sw::a3::Engine engine(&F, query.mode);
	engine.baseDir = dirOf(*f);
	try {
	    engine.run(query);
	} catch (std::string& e) {
	    std::cerr << *f << ": " << e << "\n";
	    status = 1;
	    continue;
	} catch (std::exception& e) {
	    std::cerr << *f << ": " << e.what() << "\n";
	    status = 1;
	    continue;
	}
	if (sortedBindings) {
	    std::vector<std::string> rows;
	    for (sw::ResultSetConstIterator it = engine.rs->begin(); it != engine.rs->end(); ++it) {
		std::vector<std::string> cells;
		for (sw::BindingSetConstIterator b = (*it)->begin(); b != (*it)->end(); ++b)
		    cells.push_back(b->first->toString() + "=" + b->second.tterm->toString() + ";");
		std::sort(cells.begin(), cells.end());
		std::string row;
		for (std::vector<std::string>::const_iterator c = cells.begin(); c != cells.end(); ++c)
		    row += *c;
		rows.push_back(row);
	    }
	    std::sort(rows.begin(), rows.end());
	    for (std::vector<std::string>::const_iterator it = rows.begin(); it != rows.end(); ++it)
		std::cout << *it << "\n";
	    continue;
	}
	std::cout << engine.renderTable(0, proofs);
	if (!engine.asserted.empty()) {
	    std::cout << "asserted:\n";
	    for (std::vector<const sw::TriplePattern*>::const_iterator it = engine.asserted.begin();
		 it != engine.asserted.end(); ++it)
		std::cout << "  " << (*it)->toString() << " .\n";
	}
	bool sawTest = false;
	for (std::vector<const sw::a3::Action*>::const_iterator it = query.actions.begin();
	     it != query.actions.end(); ++it)
	    if (dynamic_cast<const sw::a3::Test*>(*it) != NULL)
		sawTest = true;
	if (sawTest)
	    std::cout << "test: " << (engine.lastTest ? "yes" : "no") << "\n";
    }
    return status;
}
