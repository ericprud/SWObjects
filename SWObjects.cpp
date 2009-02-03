/* SWObjects: components for capturing and manipulating compile trees of RDF
   languages. This should capture all of SPARQL and most of N3 (no graphs as
   parts of an RDF triple).

 * $Id: SWObjects.cpp,v 1.17 2008-12-02 04:57:12 eric Exp $
 */

#include "SWObjects.hpp"
#include "ResultSet.hpp"
#include "TurtleSParser.hpp"
#include <string.h>
#include "SPARQLSerializer.hpp"

namespace w3c_sw {

void Base::express (Expressor* p_expressor) {
    p_expressor->base(this, typeid(*this).name());
}

char const * yit = "yacker:implicit-terminal";
std::map<StringException*, std::string> StringException::strs;

} // namespace w3c_sw

/* END yacker-specific test harness */

namespace libwww {
/* copied from libwww's HTParse.c
 * transliterated to c++ using std::string (for reduced performance) - EGP
 */

HTURI::HTURI (std::string name) : DummyHTURI()
{
    schemeP =  hostP =  absoluteP =  relativeP =  fragmentP = false;
    
    size_t p;
    size_t after_scheme = 0;

    /* Look for fragment identifier */
    if ((p = name.find('#')) != std::string::npos) {
	std::string t = name.substr(p+1, name.size()-p-1);
	fragment = t;
	fragmentP = true;
	name.erase(p);
    }
    
    
    if ((p = name.find(' ')) != std::string::npos) name.erase(p++);
    
    for(p=0; p<name.size(); p++) {

	/* 
	** Look for any whitespace. This is very bad for pipelining as it
	** makes the request invalid
	*/
	if (isspace(name[p])) {
	    name.erase(p, 1);
	    p = p-1;
	}
	if (name[p]=='/' || name[p]=='#' || name[p]=='?')
	    break;
	if (name[p]==':') {
		scheme = name.substr(after_scheme, p); /* Scheme has been specified */
		schemeP = true;
		name.erase(0, p+1);
		p = 0-1;

/* The combination of gcc, the "-O" flag and the HP platform is
   unhealthy. The following three lines is a quick & dirty fix, but is
   not recommended. Rather, turn off "-O". */

/*		after_scheme = p;*/
/*		while (*after_scheme == 0)*/
/*		    after_scheme++;*/

		after_scheme = p+1;

		if (scheme=="URL") {
		    scheme.clear();  /* Ignore IETF's URL: pre-prefix */
		    schemeP = false;
		} else break;
	}
    }

    p = after_scheme;
    if (name[p]=='/'){
	if (name[p+1]=='/') {
	    host = name.substr(p+2, name.size());/* host has been specified 	*/
	    hostP = true;
	    name.erase(0, p+2);			/* Terminate scheme 		*/
	    p=host.find('/');	/* look for end of host name if any */
	    if(p != std::string::npos) {
	        host.erase(p);			/* Terminate host */
	        absolute = name.substr(p+1, name.size());/* Root has been found */
		absoluteP = true;
	    }
	} else {
	    absolute = name.substr(p+1, name.size());	/* Root found but no host */
	    absoluteP = true;
	}	    
    } else if (after_scheme < name.size()) {
        relative = name.substr(after_scheme, name.size());
	relativeP = true;
    } else {
	relative.clear(); /* zero for "" */
	relativeP = false;
    }
}
std::string HTParse (std::string name, const std::string* rel, e_PARSE_opts wanted)
{
    std::string result;
    //    std::string return_value = 0;
    size_t p;
    std::string scheme;
    std::string relStr(rel ? *rel : "junk");

    if (name.size() == 0) return "";
    //if (!relatedName)        /* HWL 23/8/94: dont dump due to NULL */
    //    relatedName = "";
    
    /* Make working copies of input strings to cut up: */
    //len = strlen(aName)+strlen(relatedName)+10;
    //if ((result=(std::string ) HT_MALLOC(len)) == NULL) /* Lots of space: more than enough */
    //	HT_OUTOFMEM("parse space");
    //StrAllocCopy(name, aName);
    //StrAllocCopy(rel, relatedName);
    
    HTURI given(name);

    DummyHTURI* related = rel ? new HTURI(relStr) : new DummyHTURI();
    //result[0]=0;		/* Clear string  */
    scheme = given.hasScheme() ? given.getScheme() : related->getScheme();

    if (wanted & PARSE_scheme)
        if (scheme.size() != 0) {
	    result += scheme;
	    if(wanted & PARSE_punctuation) result += ":";
	}
	
    if (given.hasScheme() && related->hasScheme())/* If different, inherit nothing. */
        if (given.getScheme() != related->getScheme()) {
	    related->clearHost();
	    related->clearAbsolute();
	    related->clearRelative();
	    related->clearFragment();
	}
	
    if (wanted & PARSE_host)
        if(given.hasHost() || related->hasHost()) {
	    if(wanted & PARSE_punctuation) result += "//";
	    result += given.hasHost() ? given.getHost() : related->getHost();
	}
	
    if (given.hasHost() && related->hasHost())  /* If different hosts, inherit no path. */
        if (given.getHost() != related->getHost()) {
	    related->clearAbsolute();
	    related->clearRelative();
	    related->clearFragment();
	}
	
    if (wanted & PARSE_path) {
        if(given.hasAbsolute()) {			/* All is given */
	    if(wanted & PARSE_punctuation) result += "/";
	    result += given.getAbsolute();
	} else if(related->hasAbsolute()) {	/* Adopt path not name */
	    result += "/";
	    result += related->getAbsolute();
	    if (given.hasRelative()) {
		p = result.find('?');	/* Search part? */
		if (p == std::string::npos) p=result.size()-1;
		p = result.rfind('/', p);	/* last / */
		result.erase(p+1);			/* Remove filename */
		result += given.getRelative();		/* Add given one */
	    }
	} else if(given.hasRelative()) {
	    result += given.getRelative();		/* what we've got */
	} else if(related->hasRelative()) {
	    result += related->getRelative();
	} else {  /* No inheritance */
	    result += "/";
	}
    }
		
    if (wanted & PARSE_view)
	if(given.hasFragment() || related->hasFragment()) {
	    if(given.hasAbsolute() && given.hasFragment()) {   /*Fixes for relURLs...*/
		if(wanted & PARSE_punctuation) result += "#";
		result += given.getFragment(); 
	    } else if (given.hasFragment()) {
		if(wanted & PARSE_punctuation) result += "#"; // differs from HTParse.c:202-206
		result += given.getFragment(); 
	    }
	}

    delete related;
    return result;		/* exactly the right length */
}

} // namespace libwww

namespace w3c_sw {

void URI::express (Expressor* p_expressor) {
    p_expressor->uri(this, terminal);
}
void Variable::express (Expressor* p_expressor) {
    p_expressor->variable(this, terminal);
}
void BNode::express (Expressor* p_expressor) {
    p_expressor->bnode(this, terminal);
}
void RDFLiteral::express (Expressor* p_expressor) {
    p_expressor->rdfLiteral(this, m_String, datatype, m_LANGTAG);
}
void IntegerRDFLiteral::express (Expressor* p_expressor) {
    p_expressor->rdfLiteral(this, m_value);
}
void DecimalRDFLiteral::express (Expressor* p_expressor) {
    p_expressor->rdfLiteral(this, m_value);
}
void DoubleRDFLiteral::express (Expressor* p_expressor) {
    p_expressor->rdfLiteral(this, m_value);
}
void BooleanRDFLiteral::express (Expressor* p_expressor) {
    p_expressor->rdfLiteral(this, m_value);
}
void NULLpos::express (Expressor* p_expressor) {
    p_expressor->nullpos(this);
}
void TriplePattern::express (Expressor* p_expressor) {
    p_expressor->triplePattern(this, m_s,m_p,m_o);
}
void Filter::express (Expressor* p_expressor) {
    p_expressor->filter(this, m_Constraint);
}
void NamedGraphPattern::express (Expressor* p_expressor) {
    p_expressor->namedGraphPattern(this, m_name, allOpts, &m_TriplePatterns, &m_Filters);
}
void DefaultGraphPattern::express (Expressor* p_expressor) {
    p_expressor->defaultGraphPattern(this, allOpts, &m_TriplePatterns, &m_Filters);
}
void TableDisjunction::express (Expressor* p_expressor) {
    p_expressor->tableDisjunction(this, &m_TableOperations, &m_Filters);
}
void TableConjunction::express (Expressor* p_expressor) {
    p_expressor->tableConjunction(this, &m_TableOperations, &m_Filters);
}
void OptionalGraphPattern::express (Expressor* p_expressor) {
    p_expressor->optionalGraphPattern(this, m_TableOperation);
}
void GraphGraphPattern::express (Expressor* p_expressor) {
    p_expressor->graphGraphPattern(this, m_VarOrIRIref, m_TableOperation);
}
void POSList::express (Expressor* p_expressor) {
    p_expressor->posList(this, &m_POSs);
}
void StarVarSet::express (Expressor* p_expressor) {
    p_expressor->starVarSet(this);
}
void DefaultGraphClause::express (Expressor* p_expressor) {
    p_expressor->defaultGraphClause(this, m_IRIref);
}
void NamedGraphClause::express (Expressor* p_expressor) {
    p_expressor->namedGraphClause(this, m_IRIref);
}
void SolutionModifier::express (Expressor* p_expressor) {
    p_expressor->solutionModifier(this, m_OrderConditions, m_limit,m_offset);
}
void Binding::express (Expressor* p_expressor) {
    p_expressor->binding(this, this);
}
void BindingClause::express (Expressor* p_expressor) {
    p_expressor->bindingClause(this, m_Vars, this);
}
void WhereClause::express (Expressor* p_expressor) {
    p_expressor->whereClause(this, m_GroupGraphPattern, m_BindingClause);
}
void Select::express (Expressor* p_expressor) {
    p_expressor->select(this, m_distinctness, m_VarSet, m_DatasetClauses, m_WhereClause,m_SolutionModifier);
}
void Construct::express (Expressor* p_expressor) {
    p_expressor->construct(this, m_ConstructTemplate, m_DatasetClauses, m_WhereClause,m_SolutionModifier);
}
void Describe::express (Expressor* p_expressor) {
    p_expressor->describe(this, m_VarSet, m_DatasetClauses, m_WhereClause,m_SolutionModifier);
}
void Ask::express (Expressor* p_expressor) {
    p_expressor->ask(this, m_DatasetClauses,m_WhereClause);
}
void Replace::express (Expressor* p_expressor) {
    p_expressor->replace(this, m_WhereClause,m_GraphTemplate);
}
void Insert::express (Expressor* p_expressor) {
    p_expressor->insert(this, m_GraphTemplate,m_WhereClause);
}
void Delete::express (Expressor* p_expressor) {
    p_expressor->del(this, m_GraphTemplate,m_WhereClause);
}
void Load::express (Expressor* p_expressor) {
    p_expressor->load(this, m_IRIrefs,m_into);
}
void Clear::express (Expressor* p_expressor) {
    p_expressor->clear(this, m__QGraphIRI_E_Opt);
}
void Create::express (Expressor* p_expressor) {
    p_expressor->create(this, m_Silence,m_GraphIRI);
}
void Drop::express (Expressor* p_expressor) {
    p_expressor->drop(this, m_Silence,m_GraphIRI);
}
void VarExpression::express (Expressor* p_expressor) {
    p_expressor->varExpression(this, m_Variable);
}
void LiteralExpression::express (Expressor* p_expressor) {
    p_expressor->literalExpression(this, m_RDFLiteral);
}
void BooleanExpression::express (Expressor* p_expressor) {
    p_expressor->booleanExpression(this, m_BooleanRDFLiteral);
}
void URIExpression::express (Expressor* p_expressor) {
    p_expressor->uriExpression(this, m_URI);
}
void ArgList::express (Expressor* p_expressor) {
    p_expressor->argList(this, expressions);
}
void FunctionCall::express (Expressor* p_expressor) {
    p_expressor->functionCall(this, m_IRIref,m_ArgList);
}
void FunctionCallExpression::express (Expressor* p_expressor) {
    p_expressor->functionCallExpression(this, m_FunctionCall);
}
/* Expressions */
void BooleanNegation::express (Expressor* p_expressor) {
    p_expressor->booleanNegation(this, m_Expression);
}
void ArithmeticNegation::express (Expressor* p_expressor) {
    p_expressor->arithmeticNegation(this, m_Expression);
}
void ArithmeticInverse::express (Expressor* p_expressor) {
    p_expressor->arithmeticInverse(this, m_Expression);
}
void BooleanConjunction::express (Expressor* p_expressor) {
    p_expressor->booleanConjunction(this, &m_Expressions);
}
void BooleanDisjunction::express (Expressor* p_expressor) {
    p_expressor->booleanDisjunction(this, &m_Expressions);
}
void ArithmeticSum::express (Expressor* p_expressor) {
    p_expressor->arithmeticSum(this, &m_Expressions);
}
void ArithmeticProduct::express (Expressor* p_expressor) {
    p_expressor->arithmeticProduct(this, &m_Expressions);
}
void BooleanEQ::express (Expressor* p_expressor) {
    p_expressor->booleanEQ(this, left,right);
}
void BooleanNE::express (Expressor* p_expressor) {
    p_expressor->booleanNE(this, left,right);
}
void BooleanLT::express (Expressor* p_expressor) {
    p_expressor->booleanLT(this, left,right);
}
void BooleanGT::express (Expressor* p_expressor) {
    p_expressor->booleanGT(this, left,right);
}
void BooleanLE::express (Expressor* p_expressor) {
    p_expressor->booleanLE(this, left,right);
}
void BooleanGE::express (Expressor* p_expressor) {
    p_expressor->booleanGE(this, left,right);
}
void ComparatorExpression::express (Expressor* p_expressor) {
    p_expressor->comparatorExpression(this, m_BooleanComparator);
}
void NumberExpression::express (Expressor* p_expressor) {
    p_expressor->numberExpression(this, m_NumericRDFLiteral);
}


    POSsorter* ThePOSsorter;

    /* <POSFactory> */
    POSFactory::~POSFactory () {

	std::map<std::string, TriplePattern*>::iterator iTriples;
	for (iTriples = triples.begin(); iTriples != triples.end(); iTriples++)
	    delete iTriples->second;
	triples.clear();

	std::map<std::string, Variable*>::iterator iVariables;
	for (iVariables = variables.begin(); iVariables != variables.end(); iVariables++)
	    delete iVariables->second;
	variables.clear();

	std::map<std::string, URI*>::iterator iURIs;
	for (iURIs = uris.begin(); iURIs != uris.end(); iURIs++)
	    delete iURIs->second;
	uris.clear();

	std::map<std::string, BNode*>::iterator iBNodes;
	for (iBNodes = bnodes.begin(); iBNodes != bnodes.end(); iBNodes++)
	    delete iBNodes->second;
	bnodes.clear();

	std::map<std::string, RDFLiteral*>::iterator iRDFLiterals;
	for (iRDFLiterals = rdfLiterals.begin(); iRDFLiterals != rdfLiterals.end(); iRDFLiterals++)
	    delete iRDFLiterals->second;
	rdfLiterals.clear();
    }

    Variable* POSFactory::getVariable (std::string name) {
	std::string key(name);
	VariableMap::const_iterator vi = variables.find(key);
	if (vi == variables.end()) {
	    Variable* ret = new Variable(name);
	    variables[key] = ret;
	    return ret;
	} else
	    return vi->second;
    }

    BNode* POSFactory::createBNode () {
	BNode* ret = new BNode();
	std::stringstream name;
	name << ret; // addr
	bnodes[name.str()] = ret;
	return ret;
    }

    BNode* POSFactory::getBNode (std::string name) {
	std::string key(name);
	BNodeMap::const_iterator vi = bnodes.find(key);
	if (vi == bnodes.end()) {
	    BNode* ret = new BNode(name);
	    bnodes[key] = ret;
	    return ret;
	} else
	    return vi->second;
    }

    URI* POSFactory::getURI (std::string name) {
	std::string key(name);
	URIMap::const_iterator vi = uris.find(key);
	if (vi == uris.end()) {
	    URI* ret = new URI(name);
	    uris[key] = ret;
	    return ret;
	} else
	    return vi->second;
    }

    POS* POSFactory::getPOS (std::string posStr) {
	if (posStr[0] == '<' && posStr[posStr.size()-1] == '>')
	    return getURI(posStr.substr(1, posStr.size()-2));
	if (posStr[0] == '_' && posStr[1] == ':')
	    return getBNode(posStr.substr(2, posStr.size()-2));
	if (posStr[0] == '"' && posStr[posStr.size()-1] == '"')
	    return getRDFLiteral(posStr.substr(1, posStr.size()-2), NULL, NULL);
	if (posStr[0] == '?')
	    return getVariable(posStr.substr(1, posStr.size()-1));
	throw(std::runtime_error("unable to getPOS("+posStr+")"));
    }

    RDFLiteral* POSFactory::getRDFLiteral (std::string p_String, URI* p_URI, LANGTAG* p_LANGTAG) {
	std::stringstream buf;
	buf << '"' << p_String << '"';
	if (p_URI)
	    buf << "^^<" << p_URI->getTerminal() << ">";
	if (p_LANGTAG)
	    buf << "@" << p_LANGTAG->getTerminal();
	std::string key(buf.str());
	RDFLiteralMap::const_iterator vi = rdfLiterals.find(key);
	if (vi == rdfLiterals.end()) {
	    RDFLiteral* ret = new RDFLiteral(p_String, p_URI, p_LANGTAG, key.c_str());
	    rdfLiterals[key] = ret;
	    return ret;
	} else
	    return vi->second;
    }

#define XSD "http://www.w3.org/2001/XMLSchema/"
#define LEN_XSD sizeof(XSD)
    IntegerRDFLiteral* POSFactory::getNumericRDFLiteral (std::string p_String, int p_value) {
	class MakeIntegerRDFLiteral : public MakeNumericRDFLiteral {
	private: int m_value;
	public: MakeIntegerRDFLiteral (int p_value) : m_value(p_value) {  }
	    virtual NumericRDFLiteral* makeIt (std::string p_String, URI* p_URI, std::string matched) {
		return new IntegerRDFLiteral(p_String, p_URI, matched, m_value);
	    }
	};
	MakeIntegerRDFLiteral maker(p_value);
	IntegerRDFLiteral* ret = (IntegerRDFLiteral*)getNumericRDFLiteral(p_String, "integer", &maker);
	return ret;
    }

    DecimalRDFLiteral* POSFactory::getNumericRDFLiteral (std::string p_String, float p_value) {
	class MakeDecimalRDFLiteral : public MakeNumericRDFLiteral {
	private: float m_value;
	public: MakeDecimalRDFLiteral (float p_value) : m_value(p_value) {  }
	    virtual NumericRDFLiteral* makeIt (std::string p_String, URI* p_URI, std::string matched) {
		return new DecimalRDFLiteral(p_String, p_URI, matched, m_value);
	    }
	};
	MakeDecimalRDFLiteral maker(p_value);
	DecimalRDFLiteral* ret = (DecimalRDFLiteral*)getNumericRDFLiteral(p_String, "decimal", &maker);
	return ret;
    }

    DoubleRDFLiteral* POSFactory::getNumericRDFLiteral (std::string p_String, double p_value) {
	class MakeDoubleRDFLiteral : public MakeNumericRDFLiteral {
	private: double m_value;
	public: MakeDoubleRDFLiteral (double p_value) : m_value(p_value) {  }
	    virtual NumericRDFLiteral* makeIt (std::string p_String, URI* p_URI, std::string matched) {
		return new DoubleRDFLiteral(p_String, p_URI, matched, m_value);
	    }
	};
	MakeDoubleRDFLiteral maker(p_value);
	DoubleRDFLiteral* ret = (DoubleRDFLiteral*)getNumericRDFLiteral(p_String, "double", &maker);
	return ret;
    }

    BooleanRDFLiteral* POSFactory::getBooleanRDFLiteral (std::string p_String, bool p_value) {
	std::stringstream buf;
	buf << "\"" << (p_value ? "true" : "false") << "\"^^<http://www.w3.org/2001/XMLSchema/boolean>"; // p_String
	std::string key(buf.str());
	RDFLiteralMap::const_iterator vi = rdfLiterals.find(key);
	if (vi == rdfLiterals.end()) {
	    BooleanRDFLiteral* ret = new BooleanRDFLiteral(p_String, key.c_str(), p_value);
	    rdfLiterals[key] = ret;
	    return ret;
	} else
	    return (BooleanRDFLiteral*)vi->second; // shameful downcast
    }

    NumericRDFLiteral* POSFactory::getNumericRDFLiteral (std::string p_String, const char* type, MakeNumericRDFLiteral* maker) {

	std::string str;
	str += XSD;
	str += type;
	URI* uri = getURI(str);

	std::stringstream buf;
	buf << '"' << p_String << '"';
	if (uri)
	    buf << "^^<" << uri->getTerminal() << ">";
	std::string key(buf.str());
	RDFLiteralMap::const_iterator vi = rdfLiterals.find(key);
	if (vi == rdfLiterals.end()) {
	    NumericRDFLiteral* ret = maker->makeIt(p_String, uri, key.c_str());
	    rdfLiterals[key] = ret;
	    return ret;
	} else
	    return (NumericRDFLiteral*)vi->second; // shameful downcast
    }

    TriplePattern* POSFactory::getTriple (POS* s, POS* p, POS* o, bool weaklyBound) {
	std::stringstream key;
	key << s << p << o << weaklyBound;
	TriplePatternMap::const_iterator vi = triples.find(key.str());
	if (vi == triples.end()) {
	    TriplePattern* ret = new TriplePattern(s, p, o);
	    triples[key.str()] = ret;
	    return ret;
	} else {
	    TriplePattern* ret = vi->second;
	    return ret;
	}
    }

    void POSFactory::parseTriples (BasicGraphPattern* g, std::string spo) {
	const boost::regex expression("[[:space:]]*((?:<[^>]*>)|(?:_:[^[:space:]]+)|(?:[?$][^[:space:]]+)|(?:\\\"[^\\\"]+\\\"))"
				      "[[:space:]]*((?:<[^>]*>)|(?:_:[^[:space:]]+)|(?:[?$][^[:space:]]+)|(?:\\\"[^\\\"]+\\\"))"
				      "[[:space:]]*((?:<[^>]*>)|(?:_:[^[:space:]]+)|(?:[?$][^[:space:]]+)|(?:\\\"[^\\\"]+\\\"))[[:space:]]*\\.");
	std::string::const_iterator start, end; 
	start = spo.begin(); 
	end = spo.end(); 
	boost::match_results<std::string::const_iterator> what;
	boost::match_flag_type flags = boost::match_default;
	while (regex_search(start, end, what, expression, flags)) {
	    g->addTriplePattern(getTriple(getPOS(std::string(what[1].first, what[1].second)), 
					  getPOS(std::string(what[2].first, what[2].second)), 
					  getPOS(std::string(what[3].first, what[3].second)), false));
	    start = what[0].second; 
	    // update flags: 
	    flags |= boost::match_prev_avail; 
	    flags |= boost::match_not_bob; 
	}
    }
    /* </POSFactory> */

    POS* BNode::eval (Result* r, bool bNodesGenSymbols) {
	return bNodesGenSymbols ? this : r->get(this);
    }
    POS* Variable::eval (Result* r, bool) {
	POS* ret = r->get(this);

	URI* u;
	if ((u = dynamic_cast<URI*>(ret)) != NULL) {
	    for (std::vector<URImap>::iterator it = uriMaps.begin();
		 it != uriMaps.end(); ++it) {
		std::ostringstream t(std::ios::out | std::ios::binary);
		std::ostream_iterator<char, char> oi(t);
		std::string tweak = u->getTerminal();
		//std::cerr << "s{" << it->ifacePattern << "}\n {" << it->localPattern << "}\n (" << tweak << ")\n=>";
		boost::regex_replace(oi, tweak.begin(), tweak.end(),
				     it->ifacePattern, it->localPattern, 
				 boost::match_default | boost::format_all);
		//std::cerr << t.str() << std::endl;
		ret = u = posFactory->getURI(t.str());
	    }
	}
	return ret;
    }

    void TableJunction::addTableOperation (TableOperation* tableOp) {
	if (typeid(*tableOp) == typeid(*this)) {
	    TableJunction* j = (TableJunction*)tableOp; // @@@ shameful downcast.
	    for (size_t i = 0; i < j->m_TableOperations.size(); i++)
		m_TableOperations.push_back(j->m_TableOperations[i]);
	    j->m_TableOperations.clear();
	    delete j;
	} else
	    m_TableOperations.push_back(tableOp);
    }

    ResultSet* Select::execute (RdfDB* db, ResultSet* rs) {
	if (!rs) rs = new ResultSet();
	for (std::vector<DatasetClause*>::iterator ds = m_DatasetClauses->begin();
	     ds != m_DatasetClauses->end(); ds++)
	    (*ds)->loadData(db);
	m_WhereClause->bindVariables(db, rs);
	if (m_SolutionModifier != NULL)
	    m_SolutionModifier->modifyResult(rs);
	return rs;
    }

    ResultSet* Construct::execute (RdfDB* db, ResultSet* rs) {
	if (!rs) rs = new ResultSet();
	for (std::vector<DatasetClause*>::iterator ds = m_DatasetClauses->begin();
	     ds != m_DatasetClauses->end(); ds++)
	    (*ds)->loadData(db);
	m_WhereClause->bindVariables(db, rs);
	DefaultGraphPattern g;
	m_ConstructTemplate->construct(&g, rs);
	std::cerr << "CONSTRUCTED: " << g << std::endl;
	return rs;
    }

    void DatasetClause::_loadData (BasicGraphPattern* target) {
	TurtleSDriver turtleParser("http://example.org/", m_posFactory);
	if (turtleParser.parse_file(m_IRIref->getTerminal())) {
	    std::cerr << m_IRIref->getTerminal() << ":0: error: unable to parse document" << std::endl;
	} else {
	    BasicGraphPattern* graph = turtleParser.root;
	    SPARQLSerializer s; graph->express(&s); std::cerr << "PARSED: " << s.getSPARQLstring() << std::endl;
	    for (std::vector<TriplePattern*>::iterator from = graph->begin();
		 from != graph->end(); ) {
		target->addTriplePattern(*from);
		graph->erase(from);
	    }
	    delete graph;
	}
    }
    void DefaultGraphClause::loadData (RdfDB* db) {
	DatasetClause::_loadData(db->assureGraph(DefaultGraph));
    }
    void NamedGraphClause::loadData (RdfDB* db) {
	DatasetClause::_loadData(db->assureGraph(m_IRIref));
    }

    void WhereClause::bindVariables (RdfDB* db, ResultSet* rs) {
	if (m_BindingClause != NULL) m_BindingClause->bindVariables(db, rs);
	m_GroupGraphPattern->bindVariables(db, rs);
    }

    void SolutionModifier::modifyResult (ResultSet* rs) {
	rs->order(m_OrderConditions, m_offset, m_limit);
    }

    void BindingClause::bindVariables (RdfDB* db, ResultSet* rs) {
	std::vector<Binding*>::iterator binding;

	for (ResultSetIterator it = rs->begin() ; it != rs->end(); ) {
	    for (binding = begin() ; binding != end(); binding++) {
		Result* r = new Result(rs);
		rs->insert(it, r);
		(*binding)->bindVariables(db, rs, r, m_Vars);
	    }
	    delete *it;
	    rs->erase(it++);
	}
    }

    void Binding::bindVariables (RdfDB*, ResultSet* rs, Result* r, POSList* p_Vars) {
	std::vector<POS*>::iterator variable = p_Vars->begin();
	std::vector<POS*>::iterator value = begin();
	while (value != end()) {
	    rs->set(r, *variable, *value, false);
	    variable++;
	    value++;
	}
    }

    void TableConjunction::bindVariables (RdfDB* db, ResultSet* rs) {
	for (std::vector<TableOperation*>::iterator it = m_TableOperations.begin();
	     it != m_TableOperations.end(); it++)
	    (*it)->bindVariables(db, rs);
    }

    void TableDisjunction::bindVariables (RdfDB* db, ResultSet* rs) {
	ResultSet* orig = rs->clone();
	for (std::vector<TableOperation*>::iterator it = m_TableOperations.begin();
	     it != m_TableOperations.end(); it++) {
	    ResultSet* clone = orig->clone();
	    (*it)->bindVariables(db, clone);
	    for (ResultSetIterator row = clone->begin() ; row != clone->end(); ) {
		rs->insert(row, (*row)->duplicate(rs, rs->end()));
		delete *row;
		clone->erase(row++);
	    }
	    delete clone;
	}
	delete orig;
    }

    void NamedGraphPattern::bindVariables (RdfDB* db, ResultSet* rs) {
	db->bindVariables(rs, m_name, this);
    }
    void DefaultGraphPattern::bindVariables (RdfDB* db, ResultSet* rs) {
	db->bindVariables(rs, NULL, this);
    }

    void BasicGraphPattern::bindVariables (ResultSet* rs, POS* graphVar, BasicGraphPattern* toMatch, POS* graphName) {
	bool matched = true; // Pretend it's matched so we can try the first constraint.
	for (std::vector<TriplePattern*>::iterator constraint = toMatch->m_TriplePatterns.begin();
	     constraint != toMatch->m_TriplePatterns.end() && (matched || toMatch->allOpts); constraint++) {
	    for (ResultSetIterator row = rs->begin() ; row != rs->end(); ) {
		matched = false;
		for (std::vector<TriplePattern*>::iterator triple = m_TriplePatterns.begin();
		     triple != m_TriplePatterns.end(); triple++) {
		    Result* newRow = (*row)->duplicate(rs, row);
		    if ((*triple)->bindVariables(*constraint, toMatch->allOpts, rs, graphVar, newRow, graphName)) {
			matched = true;
			rs->insert(row, newRow);
		    } else {
			delete newRow;
		    }
		}
		if (matched || !toMatch->allOpts) {
		    delete *row;
		    rs->erase(row++);
		} else {
		    row++;
		}
	    }
	}
    }
    bool TriplePattern::_bindVariable (POS* pattern, const POS* constant, ResultSet* rs, Result* provisional, bool weaklyBound) {
	if (pattern == NULL || constant == NULL)
	    return true;
	POS* curVal = pattern->eval(provisional, false);
	if (curVal == NULL) {
	    rs->set(provisional, pattern, constant, weaklyBound);
	    return true;
	}
	return constant == curVal;
    }

    void OptionalGraphPattern::bindVariables (RdfDB* db, ResultSet* rs) {
	for (ResultSetIterator row = rs->begin() ; row != rs->end(); ) {
	    ResultSet* rowRS = (*row)->makeResultSet();
	    m_TableOperation->bindVariables(db, rowRS);
	    bool empty = true;
	    for (ResultSetIterator optRow = rowRS->begin() ; optRow != rowRS->end(); ) {
		empty = false;
		Result* r = (*row)->duplicate(rs, row);
		rs->insert(row, r);
		r->assumeNewBindings(*optRow);
		delete *optRow;
		rowRS->erase(optRow++);
	    }
	    delete rowRS;
	    if (empty)
		row++;
	    else
		rs->erase(row++);
	}
    }

    void BasicGraphPattern::construct (BasicGraphPattern* target, ResultSet* rs) {
	for (ResultSetIterator result = rs->begin() ; result != rs->end(); result++)
	    for (std::vector<TriplePattern*>::iterator triple = m_TriplePatterns.begin();
		 triple != m_TriplePatterns.end(); triple++)
		(*triple)->construct(target, *result, rs->getPOSFactory());
    }

    bool TriplePattern::construct (BasicGraphPattern* target, Result* r, POSFactory* posFactory, bool bNodesGenSymbols) {
	bool ret = false;
	POS *s, *p, *o;
	if ((s = m_s->eval(r, bNodesGenSymbols)) != NULL && 
	    (p = m_p->eval(r, bNodesGenSymbols)) != NULL && 
	    (o = m_o->eval(r, bNodesGenSymbols)) != NULL) {
	    if (posFactory == NULL) {
		if (s == m_s && p == m_p && o == m_o && !weaklyBound)
		    target->addTriplePattern(this);
		else
		    throw(std::runtime_error("TriplePattern::construct requires POSFactory when constructing new triples."));
	    } else
		  target->addTriplePattern(posFactory->getTriple(s, p, o));
	}
	return ret;
    }

    TableOperation* TableOperationOnOperation::getDNF ( ) {
	TableOperation* op = m_TableOperation->getDNF();
	TableDisjunction* disjoints;
	if ((disjoints = dynamic_cast<TableDisjunction*>(op)) == NULL) {
	    return makeANewThis(op);
	}

	/* GRAPH <X> { A || B } => GRAPH <X> { A } || GRAPH <X> { B } 
	 * likewise for OPTIONALS.*/
	TableDisjunction* ret = new TableDisjunction();
	for (std::vector<TableOperation*>::iterator disjoint = disjoints->begin();
	     disjoint != disjoints->end(); disjoint++)
	    ret->addTableOperation(makeANewThis(*disjoint));
	disjoints->clear();
	delete disjoints;
	return ret;
    }
    TableOperation* BasicGraphPattern::getDNF () {
	return new DontDeleteThisBGP(this);
    }
    TableOperation* TableDisjunction::getDNF () {
	TableDisjunction* ret = new TableDisjunction();
	for (std::vector<TableOperation*>::iterator element = m_TableOperations.begin();
	     element != m_TableOperations.end(); element++) {
	    TableOperation* op = (*element)->getDNF();
	    TableDisjunction* disjoints;
	    if ((disjoints = dynamic_cast<TableDisjunction*>(op)) != NULL) {
		for (std::vector<TableOperation*>::iterator disjoint = disjoints->begin();
		     disjoint != disjoints->end(); disjoint++)
		    ret->addTableOperation(*disjoint);
		disjoints->clear();
		delete disjoints;
	    } else {
		ret->addTableOperation(op);
	    }
	}
	return ret;
    }
    TableOperation* TableConjunction::getDNF () {
	/* Create a disjunction of conjunctions: (A & B) | (C & D) */
	TableDisjunction* ret = new TableDisjunction();
	ret->addTableOperation(new TableConjunction());

	/* for each of our elements... */
	for (std::vector<TableOperation*>::iterator element = m_TableOperations.begin();
	     element != m_TableOperations.end(); element++) {
	    TableOperation* op = (*element)->getDNF();
	    TableDisjunction* disjoints;
	    TableConjunction* conjoints;
	    if ((disjoints = dynamic_cast<TableDisjunction*>(op)) != NULL) {
		/* A & ( B | C ) & ( D | E | F )
		 *                 ^^^^^^^^^^^^^
		 * ret is already ( A & B ) | ( A & C ) so copy each ret and append disjoints.
		 */
		for (std::vector<TableOperation*>::iterator disjoint = disjoints->begin();
		     disjoint != disjoints->end(); ) {
		    /* for each ret conjunction */
		    for (std::vector<TableOperation*>::iterator reti = ret->begin();
			 reti != ret->end(); reti++) {
			TableConjunction* o = dynamic_cast<TableConjunction*>(*reti);
			TableConjunction* n = new TableConjunction();
			/* Copy the conjunction. */
			for (std::vector<TableOperation*>::iterator copyi = o->begin();
			     copyi != o->end(); copyi++)
			    n->addTableOperation(*copyi);
			/* Append the current disjoint. */
			n->addTableOperation(*disjoint);
		    }
		    disjoints->erase(disjoint++);
		}
		
	    } else if ((conjoints = dynamic_cast<TableConjunction*>(op)) != NULL) {
		/* A & ( B & C ) i.e. tree was not simplified */
		for (std::vector<TableOperation*>::iterator conjoint = conjoints->begin();
		     conjoint != conjoints->end(); ) {
		    /* for each ret */
		    for (std::vector<TableOperation*>::iterator reti = ret->begin();
			 reti != ret->end(); reti++)
			(dynamic_cast<TableConjunction*>(*reti))->addTableOperation(*conjoint);
		    conjoints->erase(conjoint++);
		}
		delete conjoints;
	    } else {
		/* for each ret */
		for (std::vector<TableOperation*>::iterator reti = ret->begin();
		     reti != ret->end(); reti++)
		    (dynamic_cast<TableConjunction*>(*reti))->addTableOperation(op);
	    }
	}

	/* If there's only one disjoint, return it. */
	if (ret->size() == 1) {
	    std::vector<TableOperation*>::iterator it = ret->begin();
	    TableOperation* r = *it;
	    ret->erase(it);
	    delete ret;
	    return r;
	}
	return ret;
    }

#ifdef _MSC_VER
    /* @@@ Temporary work-around for a build bug in MSVC++ where TurltSDriver
     *     isn't defined by including TurtleSParser/TurtleSParser.hpp .
     */
    void loadGraph (BasicGraphPattern* bgp, POSFactory* f, std::string mediaType, std::string baseURI, std::string fileName) {
	TurtleSDriver turtleParser(baseURI, f);
 	turtleParser.setGraph(bgp);
 	turtleParser.parse_file(fileName);
    }
#endif /* _MSC_VER */
} // namespace w3c_sw

