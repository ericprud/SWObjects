/* ResultSet - sets of variable bindings and their proofs.
 * $Id: ResultSet.cpp,v 1.2 2008-08-27 02:21:41 eric Exp $
 */

#include "ResultSet.hpp"
#include "XMLQueryExpressor.hpp"
#include <iostream>

namespace w3c_sw {
    #include "SPARQLSerializer.hpp"
    void Result::set (const POS* variable, const POS* value, bool weaklyBound) {
	BindingSet::const_iterator vi = bindings.find((POS*)variable);
	if (vi == bindings.end()) {
	    BindingInfo b = {weaklyBound, (POS*)value};
	    bindings[(POS*)variable] = b;
	} else {
	    throw(std::runtime_error(__PRETTY_FUNCTION__));
	}
    }

    POS* Result::get (const POS* variable) const {
	BindingSet::const_iterator vi = bindings.find((POS*)variable);
	if (vi == bindings.end())
	    return NULL;
	else
	    return (*vi).second.pos;
    }

    XMLSerializer* Result::toXml (XMLSerializer* xml) {
	XMLQueryExpressor xmlizer(xml);
	xml->open("result");
	xml->attribute("addr", this);
	for (BindingSetIterator it = bindings.begin(); it != bindings.end(); it++) {
	    xml->open("binding");
	    xml->attribute(it->first->getBindingAttributeName(), it->first->getTerminal());
	    if (it->second.weaklyBound) xml->attribute("binding", "weak" );
	    it->second.pos->express(&xmlizer);
	    xml->close();
	}
	xml->close();
	return xml;
    }

    ResultSetIterator Result::duplicate (ResultSet* rs, ResultSetIterator row) {
	Result* ret = new Result(rs);
	ResultSetIterator it = rs->insert(row, ret);
	for (BindingSetIterator it = bindings.begin(); it != bindings.end(); it++)
	    ret->set(it->first, it->second.pos, it->second.weaklyBound);
	return it;
    }

    ResultSet::ResultSet () : knownVars(), results() {
	results.insert(results.begin(), new Result(this));
    }

    ResultSet::~ResultSet () {
	for (ResultSetIterator it = results.begin(); it != results.end(); it++)
	    delete *it;
    }

    ResultSet* Result::makeResultSet () {
	ResultSet* ret = new ResultSet();
	ret->erase(ret->begin());
	duplicate(ret, ret->begin());
	return ret;
    }
    void Result::assumeNewBindings (Result* from) {
	for (BindingSetIterator it = from->bindings.begin(); it != from->bindings.end(); it++)
	    bindings[it->first] = it->second;
	//	    set(it->first, it->second);	
    }


    ResultSet* ResultSet::clone () {
	ResultSet* ret = new ResultSet();
	delete *ret->begin();
	ret->erase(ret->begin());
	for (ResultSetIterator it = begin() ; it != end(); it++)
	    (*it)->duplicate(ret, ret->end());
	return ret;
    }

    void ResultSet::set (Result* r, const POS* variable, const POS* value, bool weaklyBound) {
	VariableList::const_iterator vi = knownVars.find(variable);
	if (vi == knownVars.end())
	    knownVars.insert(variable);
	r->set(variable, value, weaklyBound);
    }

    XMLSerializer* ResultSet::toXml (XMLSerializer* xml) {
	if (xml == NULL) xml = new XMLSerializer("  ");
	xml->open("sparql");
	xml->attribute("xmlns", "http://www.w3.org/2005/sparql-results#");
	xml->open("head");
	for (VariableListIterator it = knownVars.begin() ; it != knownVars.end(); it++) {
	    xml->empty("variable");
	    xml->attribute("name", (*it)->getTerminal());
	}
	xml->close();
	xml->open("results");
	for (ResultSetIterator it = begin() ; it != end(); it++)
	    (*it)->toXml(xml);
	xml->close();
	xml->close();
	return xml;
    }

}

