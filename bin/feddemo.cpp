/* feddemo - test of federation algorithm

   compiles with very strict error checking:
   g++ -g -O0 -std=c++0x -pedantic-errors -Wall -Wextra -Wno-empty-body \
       -Wno-missing-field-initializers -Wwrite-strings -Wno-deprecated \
       -Wno-unused -Wno-non-virtual-dtor -Wno-variadic-macros \
       -fmessage-length=0 -ftemplate-depth-128 -fno-merge-constants \
       -fno-nonansi-builtins -fno-gnu-keywords -fno-elide-constructors \
       -fstrict-aliasing -Winvalid-pch \
       -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_GLIBCXX_CONCEPT_CHECKS \
       -o feddemo feddemo.cpp

   executes with no memory leaks:
   valgrind --leak-check=yes  --xml=no ./feddemo
 */

#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

std::ostream* DebugStream = &std::cerr;

template <typename KeyType, typename T> 
struct SingleIdx : public std::multimap<KeyType, T> {  };

template <typename KeyType, typename T> 
struct DoubleIdx : public std::map<KeyType, SingleIdx<KeyType, T> > {  };

template <typename KeyType, typename T> 
std::ostream& operator<< (std::ostream& os, SingleIdx<KeyType, T> const& idx) {
    KeyType last;
    typename SingleIdx<KeyType, T>::const_iterator inner = idx.begin();
    while (inner != idx.end()) {
	if (last != inner->first) {
	    os << "    " << *inner->first << ":\n";
	    last = inner->first;
	}
	os << "      " << *inner->second << "\n";
	++inner;
    }
    return os;
}

template <typename KeyType, typename T> 
std::ostream& operator<< (std::ostream& os, DoubleIdx<KeyType, T> const& idx) {
    typename DoubleIdx<KeyType, T>::const_iterator outer = idx.begin();
    while (outer != idx.end()) {
	os << "  " << *outer->first << "\n";
	os << outer->second;
	++outer;
    }
    return os;
}


template <typename KeyType, typename T> struct IdxPair {
    DoubleIdx<KeyType, T> ps;
    DoubleIdx<KeyType, T> po;
    IdxPair (T begin, T end) {
	for (T triple = begin; triple != end; ++triple) {
	    KeyType from = triple->getFrom();
	    KeyType rel = triple->getRel();
	    KeyType to = triple->getTo();
	    std::pair<KeyType, T> psp(from, triple);
	    ps[rel].insert(psp);
	    std::pair<KeyType, T> pop(to, triple);
	    po[rel].insert(pop);
	}
    }
};
template <typename KeyType, typename T> 
std::ostream& operator<< (std::ostream& os, IdxPair<KeyType, T> const& indexes) {
    os << "ps:\n" << indexes.ps;
    os << "po:\n" << indexes.po;
    return os;
}


/*     Atom
 *    /    \
 * Const   Var
 */
struct Atom {
    std::string lexical;
    virtual bool isConst() const = 0;
    Atom (std::string lexical) : lexical(lexical) {  }
    virtual std::string toString() const = 0;
    static bool orderPtrs(const Atom* l, const Atom* r);
};
bool operator== (const Atom& l, const Atom& r) {
    return l.lexical == r.lexical;
}
bool operator!= (const Atom& l, const Atom& r) {
    return l.lexical != r.lexical;
}
bool operator< (const Atom& l, const Atom& r) {
    return l.lexical < r.lexical;
}
std::ostream& operator<< (std::ostream& os, Atom const& atom) {
    os << atom.toString();
    return os;
}
inline bool Atom::orderPtrs (const Atom* l, const Atom* r) {
    return *l < *r;
}

struct Const : public Atom {
    virtual bool isConst () const { return true; }
    Const (std::string lexical) : Atom(lexical) {  }
    virtual std::string toString () const { return lexical; }
};
struct Var : public Atom {
    virtual bool isConst () const { return false; }
    Var (std::string lexical) : Atom(lexical) {  }
    virtual std::string toString () const { return std::string("?") + lexical; }
};

template <typename T>
struct AtomDict : public std::map<std::string, const T*> {
    ~AtomDict () {
	for (typename std::map<std::string, const T*>::const_iterator it =
		 std::map<std::string, const T*>::begin();
	     it != std::map<std::string, const T*>::end(); ++it)
	    delete it->second;
    }
    const T* assure (std::string name) {
	typename std::map<std::string, const T*>::iterator it = std::map<std::string, const T*>::find(name);
	if (it != std::map<std::string, const T*>::end()) {
	    return it->second;
	}
	const T* ret = new T(name);
	std::pair<std::string, const T*> ent(name, ret);
	insert(ent);
	return ret;
    }
    const T* operator[] (std::string name) {
	return assure(name);
    }
};

AtomDict<Const> Consts;
AtomDict<Var> Vars;
struct Result;
struct ResultSet;
struct RuleArc;

/* Arc:  Atom--Atom->Atom
 */
struct Arc {
    const Atom* from;
    const Atom* rel;
    const Atom* to;
    static const Atom* _toAtom (std::string s) {
	return s[0] == '?' ? (const Atom*)Vars[s.substr(1)] : (Atom*)Consts[s];
    }
    Arc () : from(NULL), rel(NULL), to(NULL) {  }
    Arc (const Atom* frm, const Atom* rel, const Atom* to) :
    	from(frm), rel(rel), to(to) {  }
    Arc (const char* frm, const char* rel, const char* to) :
    	from(_toAtom(frm)), rel(_toAtom(rel)), to(_toAtom(to)) {  }
    Arc (const Arc& ref) : 
	from(_toAtom(ref.from->toString())), 
	rel(_toAtom(ref.rel->toString())), 
	to(_toAtom(ref.to->toString())) {  }
    const Atom* getFrom () const { return from; }
    const Atom* getRel () const { return rel; }
    const Atom* getTo () const { return to; }
};
bool operator== (const Arc l, const Arc r) {
    return 
	*l.from == *r.from && 
	*l.rel == *r.rel   &&
	*l.to == *r.to;
}
bool operator!= (const Arc l, const Arc r) {
    return 
	*l.from != *r.from || 
	*l.rel != *r.rel   ||
	*l.to != *r.to;
}
bool operator< (const Arc l, const Arc r) {
    return 
	(*l.from != *r.from) ? *l.from < *r.from : 
	(*l.rel != *r.rel) ? *l.rel < *r.rel : 
	*l.to < *r.to;
}
std::ostream& operator<< (std::ostream& os, Arc const& arc) {
    os << *arc.from << "--" << *arc.rel << "->" << *arc.to;
    return os;
}

typedef std::set<Arc> Pattern;
bool operator!= (const Pattern l, const Pattern r) {
    Pattern::const_iterator lit = l.begin();
    Pattern::const_iterator rit = r.begin();
    while (lit != l.end() && rit != r.end())
	if (*lit != *rit)
	    return true;
    return false;
}
std::ostream& operator<< (std::ostream& os, Pattern const& arcSet) {
    os << "{\n";
    for (Pattern::const_iterator it = arcSet.begin(); it != arcSet.end(); ++it)
	os << "  " << *it << "\n";
    os << "}" << std::endl;
    return os;
}

typedef std::vector<Pattern> Disjunction;
std::ostream& operator<< (std::ostream& os, Disjunction const& disjoints) {
    for (Disjunction::const_iterator it = disjoints.begin(); it != disjoints.end(); ++it) {
	if (it != disjoints.begin())
	    os << " || \n" << std::endl;
	os << "  " << *it << "\n";
    }
    return os;
}

typedef IdxPair<const Atom*, Pattern::const_iterator> PatternIdx;

struct Rule {
    Pattern head;
    Pattern body;
    std::string label;
    Rule (const Arc* hFirst, const Arc* hLast, 
	  const Arc* bFirst, const Arc* bLast, std::string label) : 
	head(hFirst, hLast), body(bFirst, bLast), 
	label(label) {  }
    std::string getLabel () const { return label; }
};
bool operator< (const Rule l, const Rule r) {
    return
	l.head != r.head ? l.head < r.head : 
	l.body < r.body;
}

struct RuleArc {
    const Rule* rule;
    const Arc* arc;
    RuleArc (const Rule* rule, const Arc* arc) : rule(rule), arc(arc) {  }
    RuleArc (const RuleArc& ref) : rule(ref.rule), arc(ref.arc) {  }
    const Atom* getFrom () const { return arc->getFrom(); }
    const Atom* getRel () const { return arc->getRel(); }
    const Atom* getTo () const { return arc->getTo(); }
};
bool operator< (const RuleArc l, const RuleArc r) {
    return
	l.arc != r.arc ? l.arc < r.arc : 
	*l.rule < *r.rule;
}
std::ostream& operator<< (std::ostream& os, RuleArc const& arc) {
    os << *arc.arc << " per " << arc.rule->getLabel();
    return os;
}

struct PatternOfRules : public std::set<RuleArc> {
    void insert (Rule* insertMe) {
	for (Pattern::const_iterator it = insertMe->head.begin(); it != insertMe->head.end(); ++it)
	    std::set<RuleArc>::insert(RuleArc(insertMe, &*it));
    }
    Disjunction transformQuery(const Pattern& query);
};
typedef IdxPair<const Atom*, PatternOfRules::const_iterator> RuleArcIdxPair;
typedef DoubleIdx<const Atom*, PatternOfRules::const_iterator> RuleArcDoubleIdx;
typedef SingleIdx<const Atom*, PatternOfRules::const_iterator> RuleArcSingleIdx;
std::ostream& operator<< (std::ostream& os, PatternOfRules const& arcSet) {
    os << "<\n";
    for (PatternOfRules::const_iterator it = arcSet.begin(); it != arcSet.end(); ++it)
	os << "  " << *it << "\n";
    os << ">" << std::endl;
    return os;
}
typedef IdxPair<const Atom*, std::set<RuleArc>::const_iterator> PatternOfRulesIdx; // !!!DOOMED

/* Mapping from Query Vars to Rule/Atom */
struct RuleAtom {
    unsigned invocation;
    const Atom* atom;
    RuleAtom () : invocation(NULL), atom(NULL) {  }
    RuleAtom (unsigned invocation, const Atom* atom) : 
	invocation(invocation), atom(atom) {  }
};
std::ostream& operator<< (std::ostream& os, RuleAtom const& ra) {
    os << *ra.atom << "(" << ra.invocation << ")";
    return os;
}

struct ResultsPerRule : public std::map<const Rule*, RuleAtom> {
};
std::ostream& operator<< (std::ostream& os, ResultsPerRule const& resultsPerRule) {
    for (ResultsPerRule::const_iterator it = resultsPerRule.begin(); it != resultsPerRule.end(); ++it) {
	if (it != resultsPerRule.begin())
	    os << "\n         ";
	os << it->first->getLabel() << ":" << it->second;
    }
    return os;
}
struct Result : public std::map<const Atom*, ResultsPerRule> {
};
bool operator< (const Result l, const Result r) {
    /* Could memoize this. */
    std::set<const Atom*> ps;
    for (Result::const_iterator it = l.begin(); it != l.end(); ++it)
	ps.insert(it->first);
    for (Result::const_iterator it = r.begin(); it != r.end(); ++it)
	ps.insert(it->first);
    std::vector<const Atom*> vs(ps.begin(), ps.end());
    std::sort(vs.begin(), vs.end(), Atom::orderPtrs);
    for (std::vector<const Atom*>::const_iterator atom = vs.begin();
	 atom != vs.end(); ++atom) {
	Result::const_iterator lit = l.find(*atom);
	Result::const_iterator rit = r.find(*atom);
	if (lit == l.end())
	    return true;
	if (rit == r.end())
	    return false;

	std::set<const Atom*> resPerRule;
	//!!! for (Result::const_iterator it = lit.second.begin(); it != lit.second.end(); ++it)
	//     resPerRule.insert(it->first);
	// for (Result::const_iterator it = rit.second.begin(); it != rit.second.end(); ++it)
	//     resPerRule.insert(it->first);
	// std::vector<const Atom*> v_resPerRule(resPerRule.begin(), resPerRule.end());

	// for (std::vector<const Atom*>::const_iterator atom = v_resPerRule.begin();
	//      atom != v_resPerRule.end(); ++atom) {
	//     ResultsPerRule::const_iterator lit_resPerRule = lit.second.find(*atom);
	//     ResultsPerRule::const_iterator rit_resPerRule = rit.second.find(*atom);
	//     if (lit_resPerRule == lit.second.end())
	// 	return true;
	//     if (rit_resPerRule == rit.second.end())
	// 	return false;
	
	//     if (*lit_resPerRule->second.atom != *rit_resPerRule->second.atom)
	// 	return *lit_resPerRule->second.atom < *rit_resPerRule->second.atom;
	// }
    }
    return false;
}
std::ostream& operator<< (std::ostream& os, Result const& row) {
    os << "  {";
    for (Result::const_iterator it = row.begin(); it != row.end(); ++it) {
	if (it != row.begin())
	    os << "\n   ";
	os << *it->first << " => " << it->second;
    }
    os << "}" << std::endl;
    return os;
}

struct  ResultSet : public std::vector<Result> {
    ResultSet () {
	Result s;
	push_back(s);
    }
};
std::ostream& operator<< (std::ostream& os, ResultSet const& rs) {
    os << "[\n";
    for (ResultSet::const_iterator it = rs.begin(); it != rs.end(); ++it)
	os << *it;
    os << "]" << std::endl;
    return os;
}


Disjunction PatternOfRules::transformQuery (const Pattern& query) {
    Disjunction disjoints;
    RuleArcIdxPair rulesIdx(begin(), end());

    std::map<const Rule*, std::map<const Arc*, int> > invocationsByRuleArc;
    std::map<const Rule*, std::map<const Atom*, int> > invocationsByRuleAtom;
    int maxInvocations = 0;

    ResultSet rs;
    for (Pattern::const_iterator constraint = query.begin(); 
	 rs.size() != 0 && constraint != query.end(); ) {
	if (DebugStream) *DebugStream << *constraint << std::endl;

	for (size_t iRow = 0; iRow < rs.size(); ++iRow) {
	    ResultSet::iterator row = rs.begin();
	    for (size_t j = 0; j < iRow; ++j) ++row; // synch up an iterator
	    bool matched = false;

	    const Atom* from = constraint->getFrom();
	    const Atom* rel = constraint->getRel();
	    const Atom* to = constraint->getTo();
	    RuleArcDoubleIdx::const_iterator byRel =
		rulesIdx.po.find(rel);
	    if (byRel != rulesIdx.po.end()) {

		for (RuleArcSingleIdx::const_iterator triple =
			 to->isConst() ? byRel->second.find(to) : byRel->second.begin();
		     triple != byRel->second.end(); ++triple) {
		    if (DebugStream) *DebugStream << "considering " << *triple->second << "\n";
		    Result newRow(*row);
		    Arc a(*constraint);
		    const RuleArc ruleArc = *triple->second;

		    const Atom* f = from->isConst() ? from : newRow.find(from) == newRow.end() || newRow[from].find(ruleArc.rule) == newRow[from].end() ? ruleArc.getFrom() : newRow[from][ruleArc.rule].atom;
		    const Atom* r = rel->isConst()  ? rel  : newRow.find(rel)  == newRow.end() || newRow[rel ].find(ruleArc.rule) == newRow[from].end() ? ruleArc.getRel()  : newRow[rel ][ruleArc.rule].atom;
		    const Atom* t = to->isConst()   ? to   : newRow.find(to)   == newRow.end() || newRow[to  ].find(ruleArc.rule) == newRow[from].end() ? ruleArc.getTo()   : newRow[to  ][ruleArc.rule].atom;

		    if ((!from->isConst() || f == from) && 
			(!rel ->isConst() || r == rel ) && 
			(!to  ->isConst() || t == to  )) {
			int& thisInvocation = invocationsByRuleArc[ruleArc.rule][ruleArc.arc];
			if (!from->isConst() && (newRow.find(from) == newRow.end() ||
						 newRow[from].find(ruleArc.rule) == newRow[from].end())) {
			    newRow[from][ruleArc.rule] = RuleAtom(thisInvocation, f);
			    if (invocationsByRuleAtom[ruleArc.rule][f] < thisInvocation)
				invocationsByRuleAtom[ruleArc.rule][f] = thisInvocation;
			}
			if (!rel ->isConst() && (newRow.find(rel ) == newRow.end() ||
						 newRow[rel ].find(ruleArc.rule) == newRow[rel ].end())) {
			    newRow[rel ][ruleArc.rule] = RuleAtom(thisInvocation, r);
			    if (invocationsByRuleAtom[ruleArc.rule][r] < thisInvocation)
				invocationsByRuleAtom[ruleArc.rule][r] = thisInvocation;
			}
			if (!to  ->isConst() && (newRow.find(to  ) == newRow.end() ||
						 newRow[to  ].find(ruleArc.rule) == newRow[to  ].end())) {
			    newRow[to  ][ruleArc.rule] = RuleAtom(thisInvocation, t);
			    if (invocationsByRuleAtom[ruleArc.rule][t] < thisInvocation)
				invocationsByRuleAtom[ruleArc.rule][t] = thisInvocation;
			}

			if (maxInvocations < ++thisInvocation)
			    maxInvocations = thisInvocation;
			matched = true;
			rs.insert(row, newRow);
			++iRow;
			row = rs.begin();
			for (size_t j = 0; j < iRow; ++j) ++row;
		    }
		}
	    }
	    if (matched) {
		rs.erase(row++);
	    } else {
		row++;
	    }
	}
	++constraint;
    }
    
    if (DebugStream) *DebugStream << rs;

    for (ResultSet::const_iterator row = rs.begin(); 
	 row != rs.end(); ++row) {

	std::map<const Rule*, ResultSet> resSetsByRule;

	for (int curInvocation = 0; curInvocation < maxInvocations; ++curInvocation) {
	    for (Result::const_iterator binding = row->begin();
		 binding != row->end(); ++binding) {

	    for (ResultsPerRule::const_iterator resultsPerRuleIt = binding->second.begin();
		 resultsPerRuleIt != binding->second.end(); ++resultsPerRuleIt) {

		const Atom* queryAtom = binding->first;
		const Atom* ruleAtom = resultsPerRuleIt->second.atom;
		const Rule* rule = resultsPerRuleIt->first;
		int ruleInvocation = resultsPerRuleIt->second.invocation;
		if (ruleInvocation != curInvocation && 
		    invocationsByRuleAtom[rule][ruleAtom] >= curInvocation)
		    continue;
		if (resSetsByRule[rule].back().find(ruleAtom) != resSetsByRule[rule].back().end() && 
		    resSetsByRule.find(rule) != resSetsByRule.end()) {
		    Result result;
		    resSetsByRule[rule].push_back(result);
		}
		resSetsByRule[rule].back()[ruleAtom][rule] = 
		    RuleAtom(ruleInvocation, queryAtom);
	    }
	    }
	}

	Pattern disjoint;
	for (std::map<const Rule*, ResultSet>::const_iterator rule = resSetsByRule.begin();
	     rule != resSetsByRule.end(); ++rule) {
	    for (Pattern::const_iterator triple = rule->first->body.begin();
		 triple != rule->first->body.end(); ++triple) {
		ResultSet ruleResultSet = rule->second;
		if (DebugStream) *DebugStream << "filling " << *triple << " from\n" << ruleResultSet;
		for (ResultSet::const_iterator ruleResultSetRow = ruleResultSet.begin(); 
		     ruleResultSetRow != ruleResultSet.end(); ++ruleResultSetRow) {
		    const Atom* f = triple->from->isConst() ? triple->from : 
		     	ruleResultSetRow->find(triple->from) == ruleResultSetRow->end() || 
			ruleResultSetRow->find(triple->from)->second.find(rule->first) == ruleResultSetRow->find(triple->from)->second.end() ? NULL : 
		     	ruleResultSetRow->find(triple->from)->second.find(rule->first)->second.atom;
		    const Atom* r = triple->rel ->isConst() ? triple->rel  : 
		     	ruleResultSetRow->find(triple->rel ) == ruleResultSetRow->end() || 
			ruleResultSetRow->find(triple->rel )->second.find(rule->first) == ruleResultSetRow->find(triple->rel )->second.end() ? NULL : 
		     	ruleResultSetRow->find(triple->rel )->second.find(rule->first)->second.atom;
		    const Atom* t = triple->to  ->isConst() ? triple->to   : 
		     	ruleResultSetRow->find(triple->to  ) == ruleResultSetRow->end() || 
			ruleResultSetRow->find(triple->to  )->second.find(rule->first) == ruleResultSetRow->find(triple->to  )->second.end() ? NULL : 
		     	ruleResultSetRow->find(triple->to  )->second.find(rule->first)->second.atom;
		    if (f != NULL && r != NULL && t != NULL) {
		     	Arc a(f, r, t);
		     	disjoint.insert(a);
		    }
		}
	    }
	}
	disjoints.push_back(disjoint);	
    }
    return disjoints;
}


int main () {
    Arc query0Inits[] = {
	Arc("?A", "rule0:rel1", "?B"),
	Arc("?B", "rule0:rel2", "?C"),
	Arc("?C", "rule0:rel1", "?D"),
	Arc("?D", "rule0:rel2", "?E"),
    };
    Pattern query0(query0Inits, query0Inits+sizeof(query0Inits)/sizeof(query0Inits[0]));

    Arc rule0Head[] = {
	Arc("?x", "rule0:rel1", "?y"),
	Arc("?y", "rule0:rel2", "?z"),
    };
    Arc rule0Body[] = {
	Arc("?y", "rel1i", "?x"),
	Arc("?z", "rel2i", "?y"),
    };
    Rule rule0(rule0Head, rule0Head+sizeof(rule0Head)/sizeof(rule0Head[0]), 
	       rule0Body, rule0Body+sizeof(rule0Body)/sizeof(rule0Body[0]), "rule0");

    {
	PatternOfRules rulePatterns;
	rulePatterns.insert(&rule0);

	Disjunction disjoints = rulePatterns.transformQuery(query0);

	std::cout << query0;
	std::cout << " => \n";
	std::cout << disjoints;
	std::cout << "-- \n";
    }

    Arc query1Inits[] = {
	Arc("?A", "rule0:rel1", "?B"),
	Arc("?B", "rule0:rel2", "?C"),
	Arc("?C", "rule1:rel3", "?D"),
	Arc("?D", "rule1:rel3", "?E"),
    };
    Pattern query1(query1Inits, query1Inits+sizeof(query1Inits)/sizeof(query1Inits[0]));
    Arc rule1Head[] = {
	Arc("?x", "rule1:rel3", "?y"),
	Arc("?y", "rule1:rel4", "?z"),
    };
    Arc rule1Body[] = {
	Arc("?y", "rel3i", "?x"),
	Arc("?z", "rel4i", "?y"),
    };
    Rule rule1(rule1Head, rule1Head+sizeof(rule1Head)/sizeof(rule1Head[0]), 
	       rule1Body, rule1Body+sizeof(rule1Body)/sizeof(rule1Body[0]), "rule1");
    {
	//DebugStream = &std::cerr;
	PatternOfRules rulePatterns;
	rulePatterns.insert(&rule0);
	rulePatterns.insert(&rule1);

	Disjunction disjoints = rulePatterns.transformQuery(query1);

	std::cout << query1;
	std::cout << " => \n";
	std::cout << disjoints;
	std::cout << "-- \n";
    }

    Arc rule2Head[] = {
	Arc("?x", "rule1:rel3", "?y"), // note rule1:
	Arc("?y", "rule1:rel4", "?z"),
    };
    Arc rule2Body[] = {
	Arc("?y", "rel3i.2", "?x"),
	Arc("?z", "rel4i.2", "?y"),
    };
    Rule rule2(rule2Head, rule2Head+sizeof(rule2Head)/sizeof(rule2Head[0]), 
	       rule2Body, rule2Body+sizeof(rule2Body)/sizeof(rule2Body[0]), "rule2");
    {
	//DebugStream = &std::cerr;
	PatternOfRules rulePatterns;
	rulePatterns.insert(&rule0);
	rulePatterns.insert(&rule1);
	rulePatterns.insert(&rule2);

	Disjunction disjoints = rulePatterns.transformQuery(query1);

	std::cout << query1;
	std::cout << " => \n";
	std::cout << disjoints;
	std::cout << "-- \n";
    }

    return 0;
}
