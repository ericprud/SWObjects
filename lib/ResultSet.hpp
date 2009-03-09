/* ResultSet - sets of variable bindings and their proofs.
 * $Id: ResultSet.hpp,v 1.10 2008-12-02 04:55:46 eric Exp $

 Consider reverting to a version before BindingInfo:
   ResultSet.hpp,v 1.10 2008/08/13 22:47:37
   ResultSet.cc,v 1.11 2008/08/13 22:47:36
 and storing the weakness in a wrapper class created / Result.

 */

#ifndef RESULT_SET_H
#define RESULT_SET_H

#include <set>
#include <list>
//#include "SWObjects.hpp"
//#include "RdfDB.hpp"
//#include "XMLSerializer.hpp"
class XMLSerializer;
#include "../interface/SAXparser.hpp"

namespace w3c_sw {

    typedef struct { bool weaklyBound; const POS* pos; } BindingInfo;
    typedef std::map<const POS*, BindingInfo> BindingSet;
    typedef std::map<const POS*, BindingInfo>::iterator BindingSetIterator;
    typedef std::map<const POS*, BindingInfo>::const_iterator BindingSetConstIterator;
    //typedef std::pair<std::map<POS*,POS*>::iterator, bool> InsertRet;
    typedef std::set<const POS*> VariableList;
    typedef std::set<const POS*>::iterator VariableListIterator;
    typedef std::set<const POS*>::const_iterator VariableListConstIterator;

    typedef std::list<Result*> ResultList;
    typedef std::list<Result*>::iterator ResultSetIterator;
    struct ResultSetIteratorPair {
	std::list<Result*>::iterator begin;
	std::list<Result*>::iterator end;
	ResultSetIteratorPair (std::list<Result*>::iterator begin, 
			       std::list<Result*>::iterator end) : 
	    begin(begin), end(end) {  }
    };
    typedef std::list<Result*>::const_iterator ResultSetConstIterator;


    class Result {
    protected:
	BindingSet bindings;
    public:
	Result (ResultSet*) : bindings() {  }
	Result (const Result& ref) : bindings() {
	    for (BindingSetConstIterator it = ref.begin(); it != ref.end(); ++it) {
		const POS* var = it->first;
		BindingInfo bi(it->second);
		bindings[var] = bi;
	    }
	}
	~Result () {  }
	std::string toString() const;
	XMLSerializer* toXml(XMLSerializer* xml = NULL);
	BindingSetIterator begin () { return bindings.begin(); }
	BindingSetConstIterator begin () const { return bindings.begin(); }
	BindingSetIterator end () { return bindings.end(); }
	BindingSetConstIterator end () const { return bindings.end(); }
	size_t size () const { return bindings.size(); }
	BindingSetIterator find (const POS* pos) { return bindings.find(pos); }
	void erase (BindingSetIterator it) { bindings.erase(it); }

	const POS* get(const POS* variable) const;
	/* set should only be used by ResultSet::set if you want to keep the
	   header consistent.
	 */
	void set(const POS* variable, const POS* value, bool weaklyBound, bool replace = false);
	Result* duplicate(ResultSet* rs, ResultSetIterator row);

	ResultSet* makeResultSet(POSFactory* posFactory);
	void assumeNewBindings(Result* from);
    };

    class ResultSet {
    protected:
	POSFactory* posFactory;
	VariableList knownVars;
	ResultList results;
	bool ordered;

    public:
	ResultSet(POSFactory* posFactory);
	ResultSet (const ResultSet& ref) : posFactory(ref.posFactory), knownVars(ref.knownVars), results(), ordered(ref.ordered) {
	    for (ResultSetConstIterator row = ref.results.begin() ; row != ref.results.end(); row++)
		insert(this->end(), new Result(**row));
	}
	/* Parsed constructor, a la
		ResultSet(&f, 
			  "?n1  _:n2\n"
			  "<n1> <n2>\n"
			  "<n4> \"l1\"" )
	 * A \n on the last line creates a row with no bindings.
	 */
#if REGEX_LIB != SWOb_DISABLED
	ResultSet(POSFactory* posFactory, std::string str, bool ordered);
#endif /* REGEX_LIB != SWOb_DISABLED */

	ResultSet(POSFactory* posFactory, SWSAXparser* parser, const char* filename);

	ResultSet(POSFactory* posFactory, SWSAXparser* parser, std::string::iterator start, std::string::iterator finish);

	virtual ~ResultSet();
	bool operator==(const ResultSet & ref) const;
	const VariableList* getKnownVars () { return &knownVars; }
	void joinIn (ResultSet* ref) { // !!! make const ref
	    for (ResultSetIterator myRow = results.begin();
		 myRow != results.end(); ) {		
		for (ResultSetConstIterator yourRow = ref->results.begin();
		     yourRow != ref->results.end(); ++yourRow) {
		    bool matched = true;
		    std::set<const POS*>copy;
		    for (BindingSetConstIterator yourBinding = (*yourRow)->begin();
			 yourBinding != (*yourRow)->end(); ++yourBinding) {
			const POS* var = yourBinding->first;
			const POS* yourVal = yourBinding->second.pos;
			const POS* myVal = (*myRow)->get(var);
			if (myVal == NULL) {
			    knownVars.insert(var); // means we can bypass ResultSet::set(...).
			    if (yourVal != NULL)
				copy.insert(var);
			} else if (myVal != yourVal) {
			    matched = false;
			    break;
			}
		    }
		    if (matched) {
			Result* newRow = (*myRow)->duplicate(this, myRow);
			for (std::set<const POS*>::iterator vars = copy.begin();
			     vars != copy.end(); ++vars)
			    newRow->set(*vars, (*yourRow)->get(*vars), false);
			insert(myRow, newRow);
		    }
		}
		erase(myRow++);
	    }
	}
	bool compareOrdered (const ResultSet & ref) const {
	    if (ref.size() != size())
		return false;
	    ResultSetConstIterator myRow = results.begin();
	    ResultSetConstIterator yourRow = ref.results.begin();
	    while (myRow != results.end()) {
		if ((*yourRow)->size() != (*myRow)->size())
		    return false;
		std::set<const POS*> yourVars;
		for (BindingSetConstIterator yourBinding = (*yourRow)->begin();
		     yourBinding != (*yourRow)->end(); ++yourBinding)
		    yourVars.insert(yourBinding->first);
		for (BindingSetConstIterator myBinding = (*myRow)->begin();
		     myBinding != (*myRow)->end(); ++myBinding) {
		    const POS* var = myBinding->first;
		    if (yourVars.erase(var) == 0)
			return false;
		    const POS* yours = (*yourRow)->find(var)->second.pos;
		    if (yours != myBinding->second.pos)
			return false;
		}
		if (yourVars.size() != 0)
		    return false;
		++myRow;
		++yourRow;
	    }
	    return true;
	}

	void project(ProductionVector<const POS*> const * varsV);
	void order(std::vector<s_OrderConditionPair>* orderConditions, int offset, int limit);
	bool isOrdered () const { return ordered; }

	POSFactory* getPOSFactory () {
	    if (posFactory == NULL)
		throw(std::runtime_error("ConstructResultSet has no POSFactory."));
	    return posFactory;
	}
	std::string toString() const;
	XMLSerializer* toXml(XMLSerializer* xml = NULL);
	ResultSetIterator begin () { return results.begin(); }
	ResultSetIterator end () { return results.end(); }
	size_t size () const { return results.size(); }
	void erase (ResultSetIterator it) { results.erase(it); }
	void set(Result* r, const POS* variable, const POS* value, bool weaklyBound);
	ResultSetIterator insert (ResultSetIterator at, Result* elem) { return results.insert(at, elem); }
	ResultSet* clone();
	void remove (ResultSetIterator it, const Result* r) { results.erase(it); delete r; }
	void containsAtLeast (ResultSet*) { throw(std::runtime_error(FUNCTION_STRING)); }
	std::string buildFederationString(std::set<const Variable*> vars);

	void matchConstraint(const TriplePattern* constraint, 
			     const ProductionVector<const TriplePattern*>* data, 
			     bool allOpts, const POS* graphVar, const POS* graphName);
    };

    std::ostream& operator<<(std::ostream& os, ResultSet const& my);

} // namespace w3c_sw

#endif // !RESULT_SET_H

