/* ResultSet - sets of variable bindings and their proofs.
 * $Id: ResultSet.hpp,v 1.2 2008-08-27 02:21:41 eric Exp $

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
	XMLSerializer* toXml(XMLSerializer* xml = NULL);
	BindingSetIterator begin () { return bindings.begin(); }
	BindingSetIterator end () { return bindings.end(); }
	BindingSetIterator find (POS* pos) { return bindings.find(pos); }

	POS* get(const POS* variable) const;
	/* set should only be used by ResultSet::set if you want to keep the
	   header consistent.
	 */
	void set(const POS* variable, const POS* value, bool weaklyBound);
	ResultSetIterator duplicate(ResultSet* rs, ResultSetIterator row);

	ResultSet* makeResultSet();
	void assumeNewBindings(Result* from);
    };

    typedef std::list<Result*> ResultList;
    typedef std::list<Result*>::iterator ResultSetIterator;

    class ResultSet {
    protected:
	VariableList knownVars;
	ResultList results;
    public:
	ResultSet();
	virtual ~ResultSet();
	XMLSerializer* toXml(XMLSerializer* xml = NULL);
	ResultSetIterator begin () { return results.begin(); }
	ResultSetIterator end () { return results.end(); }
	size_t size () { return results.size(); }
	void erase (ResultSetIterator it) { results.erase(it); }
	void set(Result* r, const POS* variable, const POS* value, bool weaklyBound);
	ResultSetIterator insert (ResultSetIterator at, Result* elem) { return results.insert(at, elem); }
	ResultSet* clone();
	void remove (ResultSetIterator it, const Result* r) { results.erase(it); delete r; }
	void containsAtLeast(ResultSet*) { throw(std::runtime_error(__PRETTY_FUNCTION__)); }
    };

    /* TransformerResultSet: extra bits needed for query on query.
     */
    class TransformerResultSet : public ResultSet {
    };

} // namespace w3c_sw

#endif // !RESULT_SET_H

