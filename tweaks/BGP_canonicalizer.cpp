#include <iostream>
#include <sstream>
#include <vector>
#include <assert.h>
#include <map>
#include <set>
#include <exception>

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define LINE std::cerr << __FILE__ "(" TOSTRING(__LINE__) "): warning LINE\n"

struct TTerm {
    std::string lexicalValue;
    TTerm (std::string lexicalValue) : lexicalValue(lexicalValue) {  }
    bool operator== (const TTerm& ref) const {
	return lexicalValue == ref.lexicalValue;
    }
    bool operator!= (const TTerm& ref) const {
	return lexicalValue != ref.lexicalValue;
    }
    bool operator< (const TTerm& ref) const {
	return lexicalValue < ref.lexicalValue;
    }
    virtual void print(std::ostream& os) const =0;
    virtual std::string str() const =0;
    virtual const TTerm* copy() const =0;
};

std::ostream& operator << (std::ostream& os, const TTerm& t) {
    t.print(os);
    return os;
}

struct URI : public TTerm {
    URI (std::string lexicalValue) : TTerm(lexicalValue) {  }
    virtual void print (std::ostream& os) const { os << "<" << lexicalValue << ">"; };
    virtual std::string str () const { return std::string("<") + lexicalValue + ">"; }
    virtual const TTerm* copy () const { return new URI(lexicalValue); }
    static const URI* ensure(std::string lexicalValue);
};

struct BNode : public TTerm {
    BNode (std::string lexicalValue) : TTerm(lexicalValue) {  }
    virtual void print (std::ostream& os) const { os << "_:" << lexicalValue; };
    virtual std::string str () const { return std::string("_:") + lexicalValue; }
    virtual const TTerm* copy () const { return new BNode(lexicalValue); }
    static const BNode* ensure(std::string lexicalValue);
};

struct Pool {
    std::map<std::string, const URI*> URIs;
    const URI* getURI (std::string lexicalValue) {
	std::map<std::string, const URI*>::iterator it = URIs.find(lexicalValue);
	if (it == URIs.end())
	    it = URIs.insert(std::pair<std::string, const URI*>(lexicalValue, new URI(lexicalValue))).first;
	return it->second;
    }
    std::map<std::string, const BNode*> BNodes;
    const BNode* getBNode (std::string lexicalValue) {
	std::map<std::string, const BNode*>::iterator it = BNodes.find(lexicalValue);
	if (it == BNodes.end())
	    it = BNodes.insert(std::pair<std::string, const BNode*>(lexicalValue, new BNode(lexicalValue))).first;
	return it->second;
    }
};
Pool P;
const URI* URI::ensure (std::string lexicalValue) { return P.getURI(lexicalValue); }
const BNode* BNode::ensure (std::string lexicalValue) { return P.getBNode(lexicalValue); }

struct Triple {
    const TTerm* s;
    const TTerm* p;
    const TTerm* o;
    Triple (const TTerm* s, const TTerm* p, const TTerm* o) : s(s), p(p), o(o) {  }
    Triple (std::string s, std::string p, std::string o) : s(_parse(s)), p(_parse(p)), o(_parse(o)) {  }
    const TTerm* _parse(std::string t) {
	if (t.find_first_of("<") == 0)
	    return URI::ensure(t.substr(1, t.size()-2));
	if (t.find_first_of("_:") == 0)
	    return BNode::ensure(t.substr(2));
	throw std::string("What kind of TTerm is ") + t;
    }
#if 0
    ~Triple () {
	delete s;
	delete p;
	delete o;
    }
#endif
    Triple* copy () const {
	return new Triple(s->copy(), p->copy(), o->copy());
    }
    /*    bool operator== (const Triple& ref) const {
	  return *s == *ref.s && *p == *ref.p && *o == *ref.o;
	  }*/
    bool operator< (const Triple& ref) const {
	return 
	    *s != *ref.s ? *s < *ref.s
	    : *p != *ref.p ? *p < *ref.p
	    : *o < *ref.o;
    }
};

std::ostream& operator << (std::ostream& os, const Triple& t) {
    os << *t.s << " " << *t.p << " " << *t.o;
    return os;
}

struct BGP {
    std::vector<const Triple*> triples;
    BGP& operator += (const Triple* t) {
	triples.push_back(t);
	return *this;
    }
    ~BGP () {
	for (std::vector<const Triple*>::iterator it = triples.begin();
	     it != triples.end(); ) {
	    delete *it;
	    it = triples.erase(it);
	}
    }

    struct Root {
	unsigned depth;
	std::set<const TTerm*> peers;
	Root () : depth(-1) {  }

	void consider (const TTerm* peer, unsigned peerDepth) {
	    if (peers.size() == 0 || depth >= peerDepth) {
		if (depth > peerDepth)
		    peers.clear();
		depth = peerDepth;
		peers.insert(peer);
	    }
	}
	void consider (const Root& candidateRoot) {
	    if (peers.size() == 0 || depth >= candidateRoot.depth) {
		if (depth > candidateRoot.depth)
		    peers.clear();
		depth = candidateRoot.depth;
		for (std::set<const TTerm*>::const_iterator peer = candidateRoot.peers.begin();
		     peer != candidateRoot.peers.end(); ++peer)
		    peers.insert(*peer);
	    }
	}
    };

    struct DepthList {
	Root root;
	std::map<const TTerm*, unsigned> leads;
	std::map<const TTerm*, unsigned> touched;
	void print (std::ostream& os) const {
	    //assert(leads.size()>1 || root.peers.size()>1);
	    if (root.peers.size() > 0) {
		os << "roots: ";
		for (std::set<const TTerm*>::const_iterator it = root.peers.begin();
		     it != root.peers.end(); ++it)
		    os << **it;
		os << "@" << root.depth;
	    }
	    if (leads.size() > 0) {
		os << "leads: ";
		for (std::map<const TTerm*, unsigned>::const_iterator via = leads.begin();
		     via != leads.end(); ++via) {
		    if (via != leads.begin())
			os << "|";
		    os << *via->first << "@" << via->second;
		}
	    }
	    if (touched.size() > 0) {
		os << " touched: ";
		for (std::map<const TTerm*, unsigned>::const_iterator touch = touched.begin();
		     touch != touched.end(); ++touch) {
		    if (touch != touched.begin())
			os << ",";
		    os << *touch->first << "@" << touch->second;
		}
	    }
	}
    };

    struct ObjectOf : public std::map<const TTerm*, DepthList> {
	void print (std::ostream& os) const {
	    for (ObjectOf::const_iterator it = begin();
		 it != end(); ++it) {
		os << *it->first << ": ";
		it->second.print(os);
		os << std::endl;
	    }
	}
	unsigned depthOf (const TTerm* t) const {
	    ObjectOf::const_iterator it = find(t);
	    return it == end() ? 0 : it->second.root.depth;
	}
    };

    struct DepthTriple {
	unsigned depth;
	const Triple* triple;
	const ObjectOf& oo;
	DepthTriple(const Triple* triple, const ObjectOf& oo)
	    : depth(oo.depthOf(triple->s)), triple(triple), oo(oo) {  }
	bool operator< (const DepthTriple& ref) const {
	    return depth == ref.depth ? *triple < *ref.triple : depth < ref.depth;
	}
    };

    struct BGP* canonicalize () {
	/*
	 * A → B   D
	 * ↓ ↖ ↓   ↓
	 * F   C → E
	 */
	ObjectOf work;
	std::set<const TTerm*> subjects;
	size_t pendingLeads = 0;

        for (std::vector<const Triple*>::const_iterator t = triples.begin();
	     t != triples.end(); ++t) {
	    work[(*t)->o].leads[(*t)->s] = 1;
	    ++pendingLeads;
	    subjects.erase((*t)->o);
	    if (work.find((*t)->s) == work.end())
		subjects.insert((*t)->s);
	    /* !!! <s> <p> <s> . */
	}

	/* A: C
	 * B: A
	 * F: A|C
	 * C: B
	 * E: C+D
	 */
	for (unsigned gen = 1; pendingLeads > 0 && gen < 5; ++gen) {
	    pendingLeads = 0;
	    // work.print(std::cerr);
	    for (ObjectOf::iterator oo = work.begin();
		 oo != work.end(); ) {
		/* A		 * B		 * F		 * C		 * E		 */
		const TTerm* goal = oo->first;
		// std::cerr << *goal;

		std::map<const TTerm*, unsigned> nextLeads;
		Root candidateRoot;
		/* (C)		 * (A)		 * (AC)		 * (B)		 * (CD)		 */
		for (std::map<const TTerm*, unsigned>::const_iterator leads = oo->second.leads.begin();
		     leads != oo->second.leads.end(); ++leads) {
		    const TTerm* lead = leads->first;
		    unsigned curDistance = leads->second;
		    ObjectOf::const_iterator follow = work.find(lead);
		    oo->second.touched[lead] = gen;
		    if (follow == work.end()) {
			// std::cerr << " finished with " << *lead << " in " << gen << " generations\n";
			candidateRoot.consider(lead, gen);
		    } else {
			/* C:1		 * A:1		 * A:1,C:1	 * B:1		 * C:1,D:1	 */
			// if (leads != oo->second.leads.begin())
			//     std::cerr << "   ";
			// std::cerr << " following " << *lead << " to (";
			/* (B)		 * (A)		 * (AC)		 * (B)		 * (CD)		 */
			for (std::map<const TTerm*, unsigned>::const_iterator followLead = follow->second.leads.begin();
			     followLead != follow->second.leads.end(); ++followLead) {
			    const TTerm* gp = followLead->first;
			    unsigned nextDepth = curDistance + followLead->second;
			    if (gp == goal) {
				// std::cerr << "!";
				oo->second.touched[gp] = nextDepth;
				candidateRoot.consider(gp, nextDepth);
			    } else
				nextLeads[gp] = nextDepth;
			    // std::cerr << *gp << "@" << curDistance + followLead->second;
			}
			if (follow->second.leads.size() == 0 && follow->second.root.peers.size() > 0 && nextLeads.size() == 0) {
			    Root followedRoot(follow->second.root);
			    ++followedRoot.depth;
			    candidateRoot.consider(followedRoot);
			}
			for (std::map<const TTerm*, unsigned>::const_iterator t = follow->second.touched.begin();
			     t != follow->second.touched.end(); ++t)
			    if (oo->second.touched.find(t->first) != oo->second.touched.end()) {
				std::stringstream ss;
				ss << t->first->str() << "[" << oo->second.touched[t->first] << "]/" << t->first->str() << "[" << t->second + gen << "] ";
				// std::cerr << ss.str();
			    } else {
				if (t->first == goal) {
				    // std::cerr << "^";
				    candidateRoot.consider(t->first, t->second + gen);
				}
				oo->second.touched[t->first] = t->second + gen;
			    }
			// std::cerr << ")" << std::endl;
		    }
		}
		if (nextLeads.size() == 0 && candidateRoot.peers.size() > 0)
		    oo->second.root.consider(candidateRoot);
		oo->second.leads = nextLeads;
		pendingLeads += nextLeads.size();
		// std::cerr << *goal << "-";
		// oo->second.print(std::cerr);
		// std::cerr << std::endl;
		++oo;
	    }
	}
	work.print(std::cerr);

	BGP* ret = new BGP();
	std::set<DepthTriple> ordered; // @@@ would like const DepthTriple
        for (std::vector<const Triple*>::const_iterator t = triples.begin();
	     t != triples.end(); ++t) {
	    const DepthTriple dt(*t, work);
	    ordered.insert(dt);
	    //	    *ret += (*t)->copy();
	}
	for (std::set<DepthTriple>::const_iterator it = ordered.begin();
	     it != ordered.end(); ++it)
	    *ret += (*it).triple->copy();
	return ret;
    }
};

std::ostream& operator << (std::ostream& os, const BGP& bgp) {
    os << "{\n";
    for (std::vector<const Triple*>::const_iterator t = bgp.triples.begin();
	 t != bgp.triples.end(); ++t) {
	if (t != bgp.triples.begin())
	    os << " .\n";
	os << "  " << **t;
    }
    os << "}\n";
    return os;
}

std::ostream& operator<< (std::ostream& os, const std::vector<int>& v) {
    os << "{";
    for (std::vector<int>::const_iterator i = v.begin(); i != v.end(); ++i) {
	if (i != v.begin())
	    os << ", ";
	os << *i;
    }
    return os << "}";
}

int main () {
    BGP bgp;
    bgp += new Triple("_:A", "<p>", "_:B");
    bgp += new Triple("_:A", "<p>", "_:F");
    bgp += new Triple("_:B", "<p>", "_:C");
    bgp += new Triple("_:C", "<p>", "_:A");
    bgp += new Triple("_:C", "<p>", "_:E");
    bgp += new Triple("_:C", "<p>", "_:F");
    bgp += new Triple("_:D", "<p>", "_:E");
    BGP* c(bgp.canonicalize());
    std::cerr << "bgp: " << *c;
    delete c;
    return 0;
}
