/* SWSexSchema - a validator for RDF graphs.
 * $Id: RdfDB.hpp,v 1.5 2008-10-14 12:02:57 eric Exp $
 */

#ifndef SWSEX_SCHEMA_H
#define SWSEX_SCHEMA_H

#include "SWObjects.hpp"

namespace w3c_sw {

    struct SWSexSchema {
	struct CodeMap : public std::map<std::string, std::string> {
	    std::ostream& print(std::ostream& os) const;
	};

	struct RulePattern {
	    virtual ~RulePattern () {  }
	    virtual std::ostream& print(std::ostream& os, bool braces = false) const = 0;
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
	};
	struct AndRule : public SetRule {
	    virtual std::ostream& print(std::ostream& os, bool braces = false) const;
	};
	struct NegatedRule : public RulePattern {
	    const RulePattern* pat;
	    NegatedRule (const RulePattern* pat) : pat(pat) {  }
	    virtual ~NegatedRule () {
		delete pat;
	    }
	    virtual std::ostream& print(std::ostream& os, bool braces = false) const;
	};
	struct AtomicRule : public RulePattern {
	    struct NameClass {
		bool reverse;
		NameClass () : reverse(false) {  }
		virtual std::ostream& print(std::ostream& os) const = 0;
	    };
	    struct NameTerm : public NameClass {
		const TTerm* term;
		NameTerm (const TTerm* term) : term(term) {  }
		virtual std::ostream& print(std::ostream& os) const;
	    };
	    struct NameAll : public NameClass {
		virtual std::ostream& print(std::ostream& os) const;
	    };
	    struct NamePattern : public NameClass {
		const TTerm* base;
		NamePattern (const TTerm* base) : base(base) {  }
		virtual std::ostream& print(std::ostream& os) const;
	    };

	    struct Value {
		virtual ~Value () {  }
		virtual std::ostream& print(std::ostream& os) const = 0;
	    };
	    struct ValueReference : public Value {
		const TTerm* label;
		ValueReference (const TTerm* label)
		    : label(label) {  }
		virtual std::ostream& print(std::ostream& os) const;
	    };
	    struct ValueSimple : public Value {
		const TTerm* tterm;
		ValueSimple (const TTerm* tterm)
		    : tterm(tterm) {  }
		virtual std::ostream& print(std::ostream& os) const;
	    };
	    struct ValueSet : public Value {
		std::vector<const TTerm*> tterms;
		virtual std::ostream& print(std::ostream& os) const;
	    };
	    struct ValueAny : public Value {
		virtual std::ostream& print(std::ostream& os) const;
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
	};
	struct RuleActions : public RulePattern {
	    const RulePattern* pattern;
	    CodeMap codeMap;
	    RuleActions (const RulePattern* pattern) : pattern(pattern) {  }
	    virtual ~RuleActions () {
		delete pattern;
	    }
	    virtual std::ostream& print(std::ostream& os, bool braces = false) const;
	};

	struct RuleMap : public std::map<const TTerm*, const RulePattern*> {
	    ~RuleMap () {
		for (const_iterator it = begin(); it != end(); ++it)
		    delete it->second;
	    }
	    std::ostream& print(std::ostream& os) const;
	};
	RuleMap ruleMap;
	const TTerm* start;

	SWSexSchema () {
	    start = NULL;
	}

	std::ostream& print(std::ostream& os) const;
    };

    inline std::ostream& operator<< (std::ostream& os, const SWSexSchema::CodeMap& obj) {
	return obj.print(os);
    }
    inline std::ostream& operator<< (std::ostream& os, const SWSexSchema::RulePattern& obj) {
	return obj.print(os);
    }
    inline std::ostream& operator<< (std::ostream& os, const SWSexSchema::OrRule& obj) {
	return obj.print(os);
    }
    inline std::ostream& operator<< (std::ostream& os, const SWSexSchema::AndRule& obj) {
	return obj.print(os);
    }
    inline std::ostream& operator<< (std::ostream& os, const SWSexSchema::NegatedRule& obj) {
	return obj.print(os);
    }
    inline std::ostream& operator<< (std::ostream& os, const SWSexSchema::AtomicRule& obj) {
	return obj.print(os);
    }
    inline std::ostream& operator<< (std::ostream& os, const SWSexSchema::AtomicRule::NameClass& obj) {
	return obj.print(os);
    }
    inline std::ostream& operator<< (std::ostream& os, const SWSexSchema::AtomicRule::NameTerm& obj) {
	return obj.print(os);
    }
    inline std::ostream& operator<< (std::ostream& os, const SWSexSchema::AtomicRule::NameAll& obj) {
	return obj.print(os);
    }
    inline std::ostream& operator<< (std::ostream& os, const SWSexSchema::AtomicRule::NamePattern& obj) {
	return obj.print(os);
    }
    inline std::ostream& operator<< (std::ostream& os, const SWSexSchema::AtomicRule::Value& obj) {
	return obj.print(os);
    }
    inline std::ostream& operator<< (std::ostream& os, const SWSexSchema::AtomicRule::ValueReference& obj) {
	return obj.print(os);
    }
    inline std::ostream& operator<< (std::ostream& os, const SWSexSchema::AtomicRule::ValueSimple& obj) {
	return obj.print(os);
    }
    inline std::ostream& operator<< (std::ostream& os, const SWSexSchema::AtomicRule::ValueSet& obj) {
	return obj.print(os);
    }
    inline std::ostream& operator<< (std::ostream& os, const SWSexSchema::AtomicRule::ValueAny& obj) {
	return obj.print(os);
    }
    inline std::ostream& operator<< (std::ostream& os, const SWSexSchema::RuleActions& obj) {
	return obj.print(os);
    }
    inline std::ostream& operator<< (std::ostream& os, const SWSexSchema::RuleMap& obj) {
	return obj.print(os);
    }
    inline std::ostream& operator<< (std::ostream& os, const SWSexSchema& obj) {
	return obj.print(os);
    }


} // namespace w3c_sw

#endif // !SWSEX_SCHEMA_H

