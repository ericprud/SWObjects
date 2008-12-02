/* ResultSet - sets of variable bindings and their proofs.
 * $Id: ResultSet.hpp,v 1.10 2008-12-02 04:55:46 eric Exp $

 Consider reverting to a version before BindingInfo:
   ResultSet.hpp,v 1.10 2008/08/13 22:47:37
   ResultSet.cc,v 1.11 2008/08/13 22:47:36
 and storing the weakness in a wrapper class created / Result.

 */

#ifndef RESULT_SET_H
#define RESULT_SET_H

#include "SWObjects.hpp"
#include "RdfDB.hpp"
#include "XMLSerializer.hpp"
#include <set>
#include <list>

namespace w3c_sw {

    typedef struct { bool weaklyBound; POS* pos; } BindingInfo;
    typedef std::map<POS*, BindingInfo> BindingSet;
    typedef std::map<POS*, BindingInfo>::iterator BindingSetIterator;
    //typedef std::pair<std::map<POS*,POS*>::iterator, bool> InsertRet;
    typedef std::set<const POS*> VariableList;
    typedef std::set<const POS*>::iterator VariableListIterator;

    class Result {
    protected:
	BindingSet bindings;
    public:
	Result (ResultSet*) : bindings() {  }
	~Result () {  }
	std::string toString () const {
	    std::stringstream s;
	    s << "{";
	    for (std::map<POS*, BindingInfo>::const_iterator it = bindings.begin(); it != bindings.end(); ++it)
		s << (it == bindings.begin() ? "" : ", ")
		  << it->first->toString() << "="
		  << it->second.pos->toString();
	    s << "}";
	    return s.str();
	}
	XMLSerializer* toXml(XMLSerializer* xml = NULL);
	BindingSetIterator begin () { return bindings.begin(); }
	BindingSetIterator end () { return bindings.end(); }
	size_t size () const { return bindings.size(); }
	BindingSetIterator find (POS* pos) { return bindings.find(pos); }

	POS* get(const POS* variable) const;
	/* set should only be used by ResultSet::set if you want to keep the
	   header consistent.
	 */
	void set(const POS* variable, const POS* value, bool weaklyBound);
	Result* duplicate(ResultSet* rs, ResultSetIterator row);

	ResultSet* makeResultSet();
	void assumeNewBindings(Result* from);
    };

    typedef std::list<Result*> ResultList;
    typedef std::list<Result*>::iterator ResultSetIterator;

    class ResultSet {
    protected:
	POSFactory* posFactory;
	VariableList knownVars;
	ResultList results;

    public:
	ResultSet(POSFactory* posFactory = NULL);
	/* Parsed constructor, a la
		ResultSet(&f, 
			  "?n1  _:n2\n"
			  "<n1> <n2>\n"
			  "<n4> \"l1\"" )
	 * A \n on the last line creates a row with no bindings.
	 */
	ResultSet (POSFactory* posFactory, std::string str) : posFactory(posFactory), knownVars(), results() {
	    const boost::regex expression("[ \\t]*((?:<[^>]*>)|(?:_:[^[:space:]]+)|(?:[?$][^[:space:]]+)|(?:\\\"[^\\\"]+\\\")|\\n)");
	    std::string::const_iterator start, end; 
	    start = str.begin(); 
	    end = str.end(); 
	    boost::match_results<std::string::const_iterator> what;
	    boost::match_flag_type flags = boost::match_default;
	    bool firstRow = true;
	    std::vector<POS*> headers;
	    int col = 0;
	    Result* curRow;
	    while (regex_search(start, end, what, expression, flags)) {
		std::string matched(what[1].first, what[1].second);
		if (matched == "\n") {
		    firstRow = false;
		    col = 0;
		    curRow = new Result(this);
		    insert(this->end(), curRow);
		} else {
		    POS* pos = posFactory->getPOS(matched);
		    if (firstRow)
			headers.push_back(pos);
		    else
			set(curRow, headers[col++], pos, false);
		}

		start = what[0].second; 
		// update flags: 
		flags |= boost::match_prev_avail; 
		flags |= boost::match_not_bob; 
	    }
	}
	virtual ~ResultSet();
	bool operator== (const ResultSet & ref) const {
	    if (ref.size() != size())
		return false;
	    std::list<Result*>::const_iterator myRow = results.begin();
	    std::list<Result*>::const_iterator yourRow = ref.results.begin();
	    while (myRow != results.end()) {
		if ((*yourRow)->size() != (*myRow)->size())
		    return false;
		std::set<POS*> yourVars;
		for (BindingSetIterator yourBinding = (*yourRow)->begin();
		     yourBinding != (*yourRow)->end(); ++yourBinding)
		    yourVars.insert(yourBinding->first);
		for (BindingSetIterator myBinding = (*myRow)->begin();
		     myBinding != (*myRow)->end(); ++myBinding) {
		    POS* var = myBinding->first;
		    if (yourVars.erase(var) == 0)
			return false;
		    POS* yours = (*yourRow)->find(var)->second.pos;
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
	void containsAtLeast(ResultSet*) { throw(std::runtime_error(__PRETTY_FUNCTION__)); }
    };

    class ConstructResultSet : ResultSet {
	ConstructResultSet(POSFactory* posFactory) : ResultSet(posFactory) {  }
    };

    /* TransformerResultSet: extra bits needed for query on query.
     */
    class TransformerResultSet : public ResultSet {
    };

    std::ostream& operator<<(std::ostream& os, ResultSet const& my);

} // namespace w3c_sw

#endif // !RESULT_SET_H

