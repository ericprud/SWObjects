/* SWSexSchema - a validator for RDF graphs.
 * $Id: RdfDB.hpp,v 1.5 2008-10-14 12:02:57 eric Exp $
 */

#ifndef SWSEX_SCHEMA_H
#define SWSEX_SCHEMA_H

#include "SWObjects.hpp"

namespace w3c_sw {

    struct SWSexSchema {
	struct Solution;
	struct RuleMap;

	typedef std::string Code;
	struct CodeMap : public std::map<std::string, Code> {
	    std::ostream& print(std::ostream& os) const;
	    std::string str() const;
	};

	struct RulePattern {
	    virtual ~RulePattern () {  }
	    virtual std::ostream& print(std::ostream& os, bool braces = false) const = 0;
	    virtual std::string str() const;
	    virtual SWSexSchema::Solution* validate(DefaultGraphPattern& source, const RuleMap& rm, const TTerm* point) const = 0;
	};
	struct SetRule : public RulePattern {
	    std::vector<const RulePattern*> rules;
	    SetRule () {  }
	    virtual ~SetRule () {
		for (std::vector<const RulePattern*>::const_iterator it = rules.begin();
		     it != rules.end(); ++it)
		    delete *it;
	    }
	};
	struct OrRule : public SetRule {
	    virtual std::ostream& print(std::ostream& os, bool braces = false) const;
	    virtual SWSexSchema::Solution* validate(DefaultGraphPattern& source, const RuleMap& rm, const TTerm* point) const;
	};
	struct AndRule : public SetRule {
	    virtual std::ostream& print(std::ostream& os, bool braces = false) const;
	    virtual SWSexSchema::Solution* validate(DefaultGraphPattern& source, const RuleMap& rm, const TTerm* point) const;
	};
	struct NegatedRule : public RulePattern {
	    const RulePattern* pat;
	    NegatedRule (const RulePattern* pat) : pat(pat) {  }
	    virtual ~NegatedRule () {
		delete pat;
	    }
	    virtual std::ostream& print(std::ostream& os, bool braces = false) const;
	    virtual SWSexSchema::Solution* validate(DefaultGraphPattern& source, const RuleMap& rm, const TTerm* point) const;
	};
	struct AtomicRule : public RulePattern {
	    struct NameClass {
		bool reverse;
		NameClass () : reverse(false) {  }
		virtual ~NameClass () {  }
		virtual std::ostream& print(std::ostream& os) const = 0;
		virtual std::string str() const;
		virtual const TTerm* getP() const = 0;
		virtual bool matchP(const TTerm* test) const = 0;
	    };
	    struct NameTerm : public NameClass {
		const TTerm* term;
		NameTerm (const TTerm* term) : term(term) {  }
		virtual std::ostream& print(std::ostream& os) const;
		virtual const TTerm* getP() const;
		virtual bool matchP(const TTerm* test) const;
	    };
	    struct NameAll : public NameClass {
		virtual std::ostream& print(std::ostream& os) const;
		virtual const TTerm* getP() const;
		virtual bool matchP(const TTerm* test) const;
	    };
	    struct NamePattern : public NameClass {
		const TTerm* base;
		NamePattern (const TTerm* base) : base(base) {  }
		virtual std::ostream& print(std::ostream& os) const;
		virtual const TTerm* getP() const;
		virtual bool matchP(const TTerm* test) const;
	    };

	    struct Value {
		typedef std::vector<const TTerm*> TermSet;
		virtual ~Value () {  }
		virtual std::ostream& print(std::ostream& os) const = 0;
		virtual std::string str() const;
		virtual TermSet getOs() const = 0;
		virtual SWSexSchema::Solution* validateTriple(const w3c_sw::SWSexSchema::AtomicRule* rule, const TriplePattern* tp, DefaultGraphPattern& source, const RuleMap& rm, const TTerm* point) const = 0;
	    };
	    struct ValueReference : public Value {
		const TTerm* label;
		ValueReference (const TTerm* label)
		    : label(label) {  }
		virtual std::ostream& print(std::ostream& os) const;
		virtual TermSet getOs() const;
		virtual SWSexSchema::Solution* validateTriple(const w3c_sw::SWSexSchema::AtomicRule* rule, const TriplePattern* tp, DefaultGraphPattern& source, const RuleMap& rm, const TTerm* point) const;
	    };
	    struct ValueType : public Value {
		const TTerm* tterm;
		ValueType (const TTerm* tterm)
		    : tterm(tterm) {  }
		virtual std::ostream& print(std::ostream& os) const;
		virtual TermSet getOs() const;
		virtual SWSexSchema::Solution* validateTriple(const w3c_sw::SWSexSchema::AtomicRule* rule, const TriplePattern* tp, DefaultGraphPattern& source, const RuleMap& rm, const TTerm* point) const;
	    };
	    struct ValueSet : public Value {
		TermSet tterms;
		virtual std::ostream& print(std::ostream& os) const;
		virtual TermSet getOs() const;
		virtual SWSexSchema::Solution* validateTriple(const w3c_sw::SWSexSchema::AtomicRule* rule, const TriplePattern* tp, DefaultGraphPattern& source, const RuleMap& rm, const TTerm* point) const;
	    };
	    struct ValueAny : public Value {
		virtual std::ostream& print(std::ostream& os) const;
		virtual TermSet getOs() const;
		virtual SWSexSchema::Solution* validateTriple(const w3c_sw::SWSexSchema::AtomicRule* rule, const TriplePattern* tp, DefaultGraphPattern& source, const RuleMap& rm, const TTerm* point) const;
	    };

	    const NameClass* nameClass;
	    const Value* value;
	    const static unsigned Unlimited = ~0U;

	    unsigned min; unsigned max;
	    AtomicRule (const NameClass* nameClass, const Value* value, unsigned min, unsigned max)
		: nameClass(nameClass), value(value), min(min), max(max) {  }
	    virtual ~AtomicRule () {
		delete nameClass;
		delete value;
	    }
	    virtual std::ostream& print(std::ostream& os, bool braces = false) const;
	    virtual SWSexSchema::Solution* validate(DefaultGraphPattern& source, const RuleMap& rm, const TTerm* point) const;
	};
	struct RuleActions : public RulePattern {
	    const RulePattern* pattern;
	    CodeMap codeMap;
	    RuleActions (const RulePattern* pattern) : pattern(pattern) {  }
	    virtual ~RuleActions () {
		delete pattern;
	    }
	    virtual std::ostream& print(std::ostream& os, bool braces = false) const;
	    virtual SWSexSchema::Solution* validate(DefaultGraphPattern& source, const RuleMap& rm, const TTerm* point) const;
	};

	struct RuleMap : public std::map<const TTerm*, const RulePattern*> {
	    ~RuleMap () {
		for (const_iterator it = begin(); it != end(); ++it)
		    delete it->second;
	    }
	    std::ostream& print(std::ostream& os, const TTerm* start = NULL) const;
	    std::string str() const;
	};

	struct Solution {
	    struct Error : public std::runtime_error {
	    };
	    struct Visitor {
		virtual bool enter(const TriplePattern* tp) = 0;
		virtual bool visit(const TriplePattern* tp) = 0;
		virtual bool leave(const TriplePattern* tp) = 0;
	    };
	    /*
	      <p1> -     │ <s1> <p1> <o1>.      │ (<s1> <p1> <o1>, CBs)
	      <p2> -     │ <s1> <p1> <o1>.      │ (, CBs)
	      (<p1> -	 │ <s1> <p1> <o1>.      │ (<p1> - : (<s1> <p1> <o1>, CBs)
	       | <p2> -) │                      │  <p2> - : (, CBs)), CBs
	      (<p1> - ,	 │ <s1> <p1> <o1>;      │ (<p1> - : (<s1> <p1> <o1>, CBs)
	       <p2> -)   │      <p2> <o2>.      │  <p2> - : (<s1> <p2> <o2>, CBs)), CBs
	                 │                      │ 
	      <p1> -*    │ <s1> <p1> <o1>, <o2> │ (<s1> <p1> <o1>, <o2>, CBs)
	      <p1> -     │ <s1> <p1> <o1>, <o2> │ ()
	    */
	    const SWSexSchema::RulePattern* rule;
	    const CodeMap* code;
	    DefaultGraphPattern consumed;
	    std::vector<Error> errors;
	    bool passes;
	    Solution (const SWSexSchema::RulePattern* rule)
		: rule(rule) {  }
	    virtual ~Solution () {  }
	    virtual std::ostream& print(std::ostream& os) const = 0;
	    virtual std::string str() const;
	    virtual bool visit(Visitor& v) const = 0;
	};
	struct AtomicSolution : public Solution {
	    struct Ref {
		const TriplePattern* tp;
		const Solution* s;
		Ref (const TriplePattern* tp, const Solution* s)
		    : tp(tp), s(s) {  }
	    };
	    typedef std::vector<Ref> RefList;
	    RefList refs;
	    AtomicSolution (const SWSexSchema::RulePattern* rule)
		: Solution(rule) {  }
	    ~AtomicSolution () {
		for (RefList::iterator it = refs.begin();
		     it != refs.end(); ++it)
		    if (it->s != NULL)
			delete it->s;
	    }
	    virtual std::ostream& print(std::ostream& os) const;
	    virtual bool visit(Visitor& v) const;
	};
	struct SetSolution : public Solution {
	    typedef std::map<const RulePattern*, const Solution*> Map;
	    Map m;
	    SetSolution (const SWSexSchema::SetRule* rule)
		: Solution(rule) {  }
	    ~SetSolution () {
		for (Map::iterator it = m.begin(); it != m.end(); ++it)
		    delete it->second;
	    }
	    virtual std::ostream& print(std::ostream& os) const;
	    virtual bool visit(Visitor& v) const;
	};

	RuleMap ruleMap;
	const TTerm* start;

	SWSexSchema () {
	    start = NULL;
	}

	bool validate(DefaultGraphPattern& bgp, const TTerm* point, const TTerm* as = NULL) const;

	std::ostream& print(std::ostream& os) const;
	std::string str() const ;
    };

    inline std::ostream& operator<< (std::ostream& os, const SWSexSchema::CodeMap& obj) {
	return obj.print(os);
    }
    inline std::ostream& operator<< (std::ostream& os, const SWSexSchema::RulePattern& obj) {
	return obj.print(os);
    }
    inline std::ostream& operator<< (std::ostream& os, const SWSexSchema::AtomicRule::NameClass& obj) {
	return obj.print(os);
    }
    inline std::ostream& operator<< (std::ostream& os, const SWSexSchema::AtomicRule::Value& obj) {
	return obj.print(os);
    }
    inline std::ostream& operator<< (std::ostream& os, const SWSexSchema::RuleActions& obj) {
	return obj.print(os);
    }
    inline std::ostream& operator<< (std::ostream& os, const SWSexSchema::RuleMap& obj) {
	return obj.print(os);
    }
    inline std::ostream& operator<< (std::ostream& os, const SWSexSchema::Solution& obj) {
	return obj.print(os);
    }
    inline std::ostream& operator<< (std::ostream& os, const SWSexSchema& obj) {
	return obj.print(os);
    }


} // namespace w3c_sw

#endif // !SWSEX_SCHEMA_H

