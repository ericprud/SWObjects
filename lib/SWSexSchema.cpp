/* RdfDB - sets of variable bindings and their proofs.
 * $Id: RdfDB.cpp,v 1.2 2008-08-27 02:21:41 eric Exp $
 */

#include "SWSexSchema.hpp"

namespace w3c_sw {

    std::ostream& SWSexSchema::CodeMap::print (std::ostream& os) const {
	for (const_iterator it = begin(); it != end(); ++it) {
	    os << " %" << it->first << "{" << it->second << "%}";
	}
	return os;
    }
    std::ostream& SWSexSchema::OrRule::print (std::ostream& os, bool braces) const {
	if (braces)
	    os << '{';
	os << '(' << "\n    ";
	for (std::vector<const RulePattern*>::const_iterator it = rules.begin();
	     it != rules.end(); ++it) {
	    if (it != rules.begin())
		os << "\n  | ";
	    os << **it;
	}
	os << ')';
	if (braces)
	    os << '}';
	return os;
    }
    std::ostream& SWSexSchema::AndRule::print (std::ostream& os, bool braces) const {
	if (braces)
	    os << '{';
	os << '(' << "\n    ";
	for (std::vector<const RulePattern*>::const_iterator it = rules.begin();
	     it != rules.end(); ++it) {
	    if (it != rules.begin())
		os << ",\n    ";
	    os << **it;
	}
	os << ')';
	if (braces)
	    os << '}';
	return os;
    }
    std::ostream& SWSexSchema::NegatedRule::print (std::ostream& os, bool braces) const {
	if (braces)
	    os << '{';
	os << '!' << *pat;
	if (braces)
	    os << '}';
	return os;
    }
    std::ostream& SWSexSchema::AtomicRule::print (std::ostream& os, bool braces) const {
	if (braces)
	    os << '{';
	os << *nameClass << ' ' << *value << "{" << min << ',';
	if (max != Unlimited)
	    os << max;
	os << '}';
	if (braces)
	    os << '}';
	return os;
    }
    std::ostream& SWSexSchema::AtomicRule::NameTerm::print (std::ostream& os) const {
	if (reverse)
	    os << '^';
	return os << term->str();
    }
    std::ostream& SWSexSchema::AtomicRule::NameAll::print (std::ostream& os) const {
	if (reverse)
	    os << '^';
	return os << '*';
    }
    std::ostream& SWSexSchema::AtomicRule::NamePattern::print (std::ostream& os) const {
	if (reverse)
	    os << '^';
	return os << base->str() << '*';
    }
    std::ostream& SWSexSchema::AtomicRule::ValueReference::print (std::ostream& os) const {
	return os << '@' << label->str();
    }
    std::ostream& SWSexSchema::AtomicRule::ValueSimple::print (std::ostream& os) const {
	return os << tterm->str();
    }
    std::ostream& SWSexSchema::AtomicRule::ValueSet::print (std::ostream& os) const {
	os << '(';
	for (std::vector<const TTerm*>::const_iterator it = tterms.begin();
	     it != tterms.end(); ++it) {
	    if (it != tterms.begin())
		os << ' ';
	    os << (*it)->str();
	}
	return os << ')';
    }
    std::ostream& SWSexSchema::AtomicRule::ValueAny::print (std::ostream& os) const {
	return os << '-';
    }
    std::ostream& SWSexSchema::RuleActions::print (std::ostream& os, bool braces) const {
	if (braces)
	    os << '{';
	os << *pattern;
	if (braces)
	    os << '}';
	return os << codeMap;
    }
    std::ostream& SWSexSchema::RuleMap::print (std::ostream& os) const {
	for (const_iterator it = begin(); it != end(); ++it) {
	    if (it != begin())
		os << "\n\n";
	    os << it->first->str() << ' ';
	    it->second->print(os, true);
	}
	return os;
    }
    std::ostream& SWSexSchema::print (std::ostream& os) const {
	if (start != NULL)
	    os << "start=" << start->str() << "\n";
	return os << ruleMap;
    }  

} // namespace w3c_sw

