/* SWObjects: components for capturing and manipulating compile trees of RDF
   languages. This should capture all of SPARQL and most of N3 (no graphs as
   parts of an RDF triple).

 * $Id: SWObjects.cpp,v 1.17 2008-12-02 04:57:12 eric Exp $
 */

#include "SWObjects.hpp"
#include "ResultSet.hpp"
#include <string.h>
#include "SPARQLSerializer.hpp"
#include "SWObjectDuplicator.hpp"
#include "../interface/WEBagent.hpp"

#ifdef _MSC_VER
  #define SET_Variable_CONSTIT_NE(L, R) set_Variable_constit_ne(L, R)
  bool set_Variable_constit_ne (std::set<const w3c_sw::Variable*>::const_iterator l, 
				std::set<const w3c_sw::Variable*>::const_iterator r)
  { return l != r; }
  #define SET_POS_CONSTIT_NE(L, R) set_POS_constit_ne(L, R)
  bool set_POS_constit_ne (std::set<const w3c_sw::POS*>::const_iterator l, 
			   std::set<const w3c_sw::POS*>::const_iterator r)
  { return l != r; }
#else /* !_MSC_VER */
  #define SET_Variable_CONSTIT_NE(L, R) L != R
  #define SET_POS_CONSTIT_NE(L, R) L != R
#endif /* !_MSC_VER */

namespace w3c_sw {

    const char* NS_xml = "http://www.w3.org/XML/1998/namespace"		;
    const char* NS_xsd = "http://www.w3.org/2001/XMLSchema#"		;
    const char* NS_rdf = "http://www.w3.org/1999/02/22-rdf-syntax-ns#"  ;
    const char* NS_rdfs= "http://www.w3.org/2000/01/rdf-schema#"	;
    const char* NS_srx = "http://www.w3.org/2005/sparql-results#"	;
    const char* NS_dc  = "http://purl.org/dc/terms/"			;
    const char* NS_sadl= "http://www.w3.org/2005/03/saddle/#"		;

void Base::express (Expressor* p_expressor) const {
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
    // std::cerr << "HTParse(" << name << ", " << (rel ? *rel : std::string("NULL")) << ", " << wanted << ")";
    std::string result;
    //    std::string return_value = 0;
    size_t p;
    std::string scheme;
    std::string relStr(rel ? *rel : "junk");

    if (name.size() == 0) return rel ? *rel : "";
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
	    if(related->hasRelative() && result.empty()) {
		std::string r = related->getRelative();
		size_t endOfPath = r.find_last_of("/");
		if (endOfPath != std::string::npos)
		    result += r.substr(0, endOfPath+1);
	    }
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
    // std::cerr << " => " << result;
    // if (rel)
    // 	std::cerr << " (rel: " << *rel << ")";
    // std::cerr << "\n";
    return result;		/* exactly the right length */
}

} // namespace libwww

namespace w3c_sw {

MediaTypeMap StreamContextMediaTypes::MediaTypes;

template<class T>
StreamContext<T>::StreamContext (std::string nameStr, T* def, e_opts opts,
				 const char* p_mediaType, SWWEBagent* webAgent,
				 std::ostream** debugStream)
    : nameStr(nameStr), malloced(true), p(NULL)
{
    if (opts & STRING) {
	p = new std::stringstream(nameStr);
    } else if (!(opts & FILE) && webAgent != NULL && !nameStr.compare(0, 5, "http:")) {
	if (debugStream != NULL && *debugStream != NULL)
	    **debugStream << "reading web resource " << nameStr << std::endl;
	std::string s(webAgent->get(nameStr.c_str()));
	mediaType = webAgent->getMediaType().c_str();
	p = new std::stringstream(s); // would be nice to use webAgent stream, or have a callback.
    } else if ((opts & STDIO) && nameStr == "-") {
	p = def;
	malloced = false;
    } else {
	/* Remove file://[^/]+ . */
	if (nameStr.substr(0, 7) == "file://") {
	    size_t slash = nameStr.find_first_of('/', 7);
	    nameStr = nameStr.substr(slash);
	}
	p = NULL;
	malloced = false;
    }
    if (!mediaType) {
	if (p_mediaType == NULL)
	    guessMediaType();
	else
	    mediaType = p_mediaType;
    }
}

IStreamContext::IStreamContext (std::string name, e_opts opts,
				const char* p_mediaType, SWWEBagent* webAgent,
				std::ostream** debugStream)
    : StreamContext<std::istream>(name, &std::cin, opts, 
				  p_mediaType, webAgent, debugStream) {
    if (p == NULL) {
	if (debugStream != NULL && *debugStream != NULL)
	    **debugStream << "reading file " << nameStr << std::endl;
	std::ifstream* istr = new std::ifstream(nameStr.c_str());
	malloced = true;
	p = istr;
	if (!istr->is_open())
	    throw std::string("unable to open file \"").append(nameStr).append("\"");
    }
}
OStreamContext::OStreamContext (std::string name, e_opts opts,
				const char* p_mediaType, SWWEBagent* webAgent,
				std::ostream** debugStream)
    : StreamContext<std::ostream>(name, &std::cout, opts, 
				  p_mediaType, webAgent, debugStream) {
    if (p == NULL) {
	if (debugStream != NULL && *debugStream != NULL)
	    **debugStream << "writing file " << nameStr << std::endl;
	std::ofstream* ostr = new std::ofstream(nameStr.c_str());
	malloced = true;
	p = ostr;
	if (!ostr->is_open())
	    throw std::string("unable to open file \"").append(nameStr).append("\" for writing.");
    }
}

/* Make sure this compilation unit includes ctor for StreamContext<std::{i,o}stream> */
void __makeSureStreamContextsAreLinked () {
    IStreamContext i("/dev/null"); i = i;
    OStreamContext o("/dev/null"); o = o;
}

std::string NamespaceMap::unmap (std::string mapped) {
    return std::string("<") + mapped + ">";
    // return std::string("[[") + mapped + "]]";
}

void URI::express (Expressor* p_expressor) const {
    p_expressor->uri(this, terminal);
}
void Variable::express (Expressor* p_expressor) const {
    p_expressor->variable(this, terminal);
}
void BNode::express (Expressor* p_expressor) const {
    p_expressor->bnode(this, terminal);
}
void RDFLiteral::express (Expressor* p_expressor) const {
    p_expressor->rdfLiteral(this, terminal, datatype, m_LANGTAG);
}
void IntegerRDFLiteral::express (Expressor* p_expressor) const {
    p_expressor->rdfLiteral(this, m_value);
}
void DecimalRDFLiteral::express (Expressor* p_expressor) const {
    p_expressor->rdfLiteral(this, m_value);
}
void FloatRDFLiteral::express (Expressor* p_expressor) const {
    p_expressor->rdfLiteral(this, m_value);
}
void DoubleRDFLiteral::express (Expressor* p_expressor) const {
    p_expressor->rdfLiteral(this, m_value);
}
void BooleanRDFLiteral::express (Expressor* p_expressor) const {
    p_expressor->rdfLiteral(this, m_value);
}
void NULLpos::express (Expressor* p_expressor) const {
    p_expressor->nullpos(this);
}
void TriplePattern::express (Expressor* p_expressor) const {
    p_expressor->triplePattern(this, m_s, m_p, m_o);
}
void Filter::express (Expressor* p_expressor) const {
    p_expressor->filter(this, m_TableOperation, &m_Expressions);
}
void NamedGraphPattern::express (Expressor* p_expressor) const {
    p_expressor->namedGraphPattern(this, m_name, allOpts, &m_TriplePatterns);
}
void DefaultGraphPattern::express (Expressor* p_expressor) const {
    p_expressor->defaultGraphPattern(this, allOpts, &m_TriplePatterns);
}
void TableDisjunction::express (Expressor* p_expressor) const {
    p_expressor->tableDisjunction(this, &m_TableOperations);
}
void TableConjunction::express (Expressor* p_expressor) const {
    p_expressor->tableConjunction(this, &m_TableOperations);
}
void OptionalGraphPattern::express (Expressor* p_expressor) const {
    p_expressor->optionalGraphPattern(this, m_TableOperation, &m_Expressions);
}
void MinusGraphPattern::express (Expressor* p_expressor) const {
    p_expressor->minusGraphPattern(this, m_TableOperation);
}
void GraphGraphPattern::express (Expressor* p_expressor) const {
    p_expressor->graphGraphPattern(this, m_VarOrIRIref, m_TableOperation);
}
void ServiceGraphPattern::express (Expressor* p_expressor) const {
    p_expressor->serviceGraphPattern(this, m_VarOrIRIref, m_TableOperation, posFactory, lexicalCompare);
}
void ExpressionAlias::express (Expressor* p_expressor) const {
    p_expressor->expressionAlias(this, expr, label);
}
void ExpressionAliasList::express (Expressor* p_expressor) const {
    p_expressor->expressionAliasList(this, &m_Expressions);
}
void POSList::express (Expressor* p_expressor) const {
    p_expressor->posList(this, &m_POSs);
}
void StarVarSet::express (Expressor* p_expressor) const {
    p_expressor->starVarSet(this);
}
void DefaultGraphClause::express (Expressor* p_expressor) const {
    p_expressor->defaultGraphClause(this, m_IRIref);
}
void NamedGraphClause::express (Expressor* p_expressor) const {
    p_expressor->namedGraphClause(this, m_IRIref);
}
void SolutionModifier::express (Expressor* p_expressor) const {
    IF_IMPL(groupBy != NULL || having != NULL, "SPARQL 1.1 SolutionModifier (groupBy, having)");
    p_expressor->solutionModifier(this, m_OrderConditions, m_limit,m_offset);
}
void Binding::express (Expressor* p_expressor) const {
    p_expressor->binding(this, this);
}
void BindingClause::express (Expressor* p_expressor) const {
    p_expressor->bindingClause(this, m_Vars, this);
}
void WhereClause::express (Expressor* p_expressor) const {
    p_expressor->whereClause(this, m_GroupGraphPattern, m_BindingClause);
}
void Select::express (Expressor* p_expressor) const {
    p_expressor->select(this, m_distinctness, m_VarSet, m_DatasetClauses, m_WhereClause,m_SolutionModifier);
}
void SubSelect::express (Expressor* p_expressor) const {
    p_expressor->subSelect(this, m_Select);
}
void Construct::express (Expressor* p_expressor) const {
    p_expressor->construct(this, m_ConstructTemplate, m_DatasetClauses, m_WhereClause,m_SolutionModifier);
}
void Describe::express (Expressor* p_expressor) const {
    p_expressor->describe(this, m_VarSet, m_DatasetClauses, m_WhereClause,m_SolutionModifier);
}
void Ask::express (Expressor* p_expressor) const {
    p_expressor->ask(this, m_DatasetClauses,m_WhereClause);
}
void Replace::express (Expressor* p_expressor) const {
    p_expressor->replace(this, m_WhereClause,m_GraphTemplate);
}
void Insert::express (Expressor* p_expressor) const {
    p_expressor->insert(this, m_GraphTemplate,m_WhereClause);
}
void Delete::express (Expressor* p_expressor) const {
    p_expressor->del(this, m_GraphTemplate,m_WhereClause);
}
void Load::express (Expressor* p_expressor) const {
    p_expressor->load(this, m_IRIrefs,m_into);
}
void Clear::express (Expressor* p_expressor) const {
    p_expressor->clear(this, m__QGraphIRI_E_Opt);
}
void Create::express (Expressor* p_expressor) const {
    p_expressor->create(this, m_Silence,m_GraphIRI);
}
void Drop::express (Expressor* p_expressor) const {
    p_expressor->drop(this, m_Silence,m_GraphIRI);
}
void POSExpression::express (Expressor* p_expressor) const {
    p_expressor->posExpression(this, m_POS);
}
void ArgList::express (Expressor* p_expressor) const {
    p_expressor->argList(this, expressions);
}
void FunctionCall::express (Expressor* p_expressor) const {
    p_expressor->functionCall(this, m_IRIref,m_ArgList);
}
void FunctionCallExpression::express (Expressor* p_expressor) const {
    p_expressor->functionCallExpression(this, m_FunctionCall);
}
/* Expressions */
void BooleanNegation::express (Expressor* p_expressor) const {
    p_expressor->booleanNegation(this, m_Expression);
}
void ArithmeticNegation::express (Expressor* p_expressor) const {
    p_expressor->arithmeticNegation(this, m_Expression);
}
void ArithmeticInverse::express (Expressor* p_expressor) const {
    p_expressor->arithmeticInverse(this, m_Expression);
}
void BooleanConjunction::express (Expressor* p_expressor) const {
    p_expressor->booleanConjunction(this, &m_Expressions);
}
void BooleanDisjunction::express (Expressor* p_expressor) const {
    p_expressor->booleanDisjunction(this, &m_Expressions);
}
void ArithmeticSum::express (Expressor* p_expressor) const {
    p_expressor->arithmeticSum(this, &m_Expressions);
}
void ArithmeticProduct::express (Expressor* p_expressor) const {
    p_expressor->arithmeticProduct(this, &m_Expressions);
}
void BooleanEQ::express (Expressor* p_expressor) const {
    p_expressor->booleanEQ(this, left,right);
}
void BooleanNE::express (Expressor* p_expressor) const {
    p_expressor->booleanNE(this, left,right);
}
void BooleanLT::express (Expressor* p_expressor) const {
    p_expressor->booleanLT(this, left,right);
}
void BooleanGT::express (Expressor* p_expressor) const {
    p_expressor->booleanGT(this, left,right);
}
void BooleanLE::express (Expressor* p_expressor) const {
    p_expressor->booleanLE(this, left,right);
}
void BooleanGE::express (Expressor* p_expressor) const {
    p_expressor->booleanGE(this, left,right);
}
void ComparatorExpression::express (Expressor* p_expressor) const {
    p_expressor->comparatorExpression(this, m_BooleanComparator);
}
void NumberExpression::express (Expressor* p_expressor) const {
    p_expressor->numberExpression(this, m_NumericRDFLiteral);
}


    POSsorter* ThePOSsorter;

    /* <POSFactory> */
    POSFactory::~POSFactory () {

	std::map<std::string, const TriplePattern*>::iterator iTriples;
	for (iTriples = triples.begin(); iTriples != triples.end(); iTriples++)
	    delete iTriples->second;
	triples.clear();

	std::map<std::string, const Variable*>::iterator iVariables;
	for (iVariables = variables.begin(); iVariables != variables.end(); iVariables++)
	    delete iVariables->second;
	variables.clear();

	std::map<std::string, const URI*>::iterator iURIs;
	for (iURIs = uris.begin(); iURIs != uris.end(); iURIs++)
	    delete iURIs->second;
	uris.clear();

	std::set<const BNode*>::iterator iBNodes;
	for (iBNodes = bnodes.begin(); iBNodes != bnodes.end(); ++iBNodes)
	    delete *iBNodes;
	bnodes.clear();

	std::map<std::string, const RDFLiteral*>::iterator iRDFLiterals;
	for (iRDFLiterals = rdfLiterals.begin(); iRDFLiterals != rdfLiterals.end(); iRDFLiterals++)
	    delete iRDFLiterals->second;
	rdfLiterals.clear();
    }

    const Variable* POSFactory::getVariable (std::string name) {
	std::string key(name);
	VariableMap::const_iterator vi = variables.find(key);
	if (vi == variables.end()) {
	    Variable* ret = new Variable(name);
	    variables[key] = ret;
	    return ret;
	} else
	    return vi->second;
    }

    const BNode* POSFactory::createBNode () {
	BNode* ret = new BNode();
	std::stringstream name;
	name << ret; // addr
	bnodes.insert(ret);
	return ret;
    }

    const BNode* POSFactory::getBNode (std::string name, POS::String2BNode& nodeMap) {
	std::string key(name);
	POS::String2BNode::const_iterator vi = nodeMap.find(key);
	if (vi == nodeMap.end()) {
	    BNode* ret = new BNode(name);
	    nodeMap[key] = ret;
	    bnodes.insert(ret);
	    return ret;
	} else
	    return vi->second;
    }

    const URI* POSFactory::getURI (std::string name) {
	std::string key(name);
	URIMap::const_iterator vi = uris.find(key);
	if (vi == uris.end()) {
	    URI* ret = new URI(name);
	    uris[key] = ret;
	    return ret;
	} else
	    return vi->second;
    }

    const POS* POSFactory::getPOS (std::string posStr, POS::String2BNode& nodeMap) {
	if (posStr[0] == '<' && posStr[posStr.size()-1] == '>')
	    return getURI(posStr.substr(1, posStr.size()-2));
	if (posStr[0] == '_' && posStr[1] == ':')
	    return getBNode(posStr.substr(2, posStr.size()-2), nodeMap);
	if (posStr[0] == '"' && posStr[posStr.size()-1] == '"')
	    return getRDFLiteral(posStr.substr(1, posStr.size()-2), NULL, NULL);
	if (posStr[0] == '?')
	    return getVariable(posStr.substr(1, posStr.size()-1));
	throw(std::runtime_error("unable to getPOS("+posStr+")"));
    }

     void POSFactory::validate (std::string value, std::string datatype) {
#if REGEX_LIB == SWOb_BOOST
	 ValidatorSet::const_iterator it = validators.find(datatype);
	 if (it == validators.end())
	     return;
	 const Validator& v = it->second;
	 boost::match_results<std::string::const_iterator> what;
	 if (!regex_search(value, what, v.pattern, boost::match_default)) {
	     if (debugStream && *debugStream)
		 **debugStream << "pattern \"" << v.pattern << "\" failed to match \"" << value << "\"." << std::endl;
	     throw TypeError(value, datatype);
	 }
	 if (v.intmin != RANGE_unlimited || v.intmax != RANGE_unlimited) {
	     std::istringstream is(value);
	     long i;
	     is >> i;
	     if ((v.intmin != RANGE_unlimited && i < -v.intmin) || 
		 (v.intmax != RANGE_unlimited && i > -v.intmax))
		 throw TypeError(value, datatype);
	 }
	 if (v.floatmin != RANGE_unlimited || v.floatmax != RANGE_unlimited) {
	     std::istringstream is(value);
	     double d;
	     is >> d;
	     if ((v.floatmin != RANGE_unlimited && d < -v.floatmin) || 
		 (v.floatmax != RANGE_unlimited && d > -v.floatmax))
		 throw TypeError(value, datatype);
	 }
#else /* REGEX_LIB == SWOb_BOOST */
	if (debugStream != NULL && *debugStream != NULL)
	    **debugStream << "unable to validate that \"" << value << "\" is a " << datatype << " without boost regular expression" << std::endl;
#endif /* REGEX_LIB != SWOb_BOOST */
    }

    const RDFLiteral* POSFactory::getRDFLiteral (std::string p_String, const URI* p_URI, LANGTAG* p_LANGTAG, bool needsValidation) {
	std::istringstream is(p_String);

	if (p_URI != NULL && needsValidation == true)
	    validate(p_String, p_URI->getLexicalValue());
	if (p_URI == getURI("http://www.w3.org/2001/XMLSchema#integer") || 
	    p_URI == getURI("http://www.w3.org/2001/XMLSchema#nonPositiveInteger") || 
	    p_URI == getURI("http://www.w3.org/2001/XMLSchema#negativeInteger") || 
	    p_URI == getURI("http://www.w3.org/2001/XMLSchema#long") || 
	    p_URI == getURI("http://www.w3.org/2001/XMLSchema#int") || 
	    p_URI == getURI("http://www.w3.org/2001/XMLSchema#short") || 
	    p_URI == getURI("http://www.w3.org/2001/XMLSchema#byte") || 
	    p_URI == getURI("http://www.w3.org/2001/XMLSchema#nonNegativeInteger") || 
	    p_URI == getURI("http://www.w3.org/2001/XMLSchema#unsignedLong") || 
	    p_URI == getURI("http://www.w3.org/2001/XMLSchema#unsignedInt") || 
	    p_URI == getURI("http://www.w3.org/2001/XMLSchema#unsignedShort") || 
	    p_URI == getURI("http://www.w3.org/2001/XMLSchema#unsignedByte") || 
	    p_URI == getURI("http://www.w3.org/2001/XMLSchema#positiveInteger")) {
	    int i;
	    is >> i;
// 	    std::stringstream canonical;
// 	    canonical << std::dec << i;
// 	    return getNumericRDFLiteral(canonical.str().c_str(), i);
	    return getNumericRDFLiteral(p_String.c_str(), i);
	} else if (p_URI == getURI("http://www.w3.org/2001/XMLSchema#decimal") || 
		   p_URI == getURI("http://www.w3.org/2001/XMLSchema#float")) {
	    float f;
	    is >> f;
// 	    std::stringstream canonical;
// 	    canonical << std::fixed << f;
// 	    return getNumericRDFLiteral(canonical.str().c_str(), f);
	    return p_URI == getURI("http://www.w3.org/2001/XMLSchema#float") ? 
		getNumericRDFLiteral(p_String.c_str(), f, true) :
		getNumericRDFLiteral(p_String.c_str(), f);
	} else if (p_URI == getURI("http://www.w3.org/2001/XMLSchema#double")) {
	    double d;
	    is >> d;
// 	    std::stringstream canonical;
// 	    canonical << std::scientific << d;
// 	    return getNumericRDFLiteral(canonical.str().c_str(), d);
	    return getNumericRDFLiteral(p_String.c_str(), d);
	} else if (p_URI == getURI("http://www.w3.org/2001/XMLSchema#boolean")) {
	    if (p_String == "0" || p_String == "false")
		return getBooleanRDFLiteral("false", 0);
	    bool b;
#ifdef LIBC_PARSES_BOOL
	    is >> b;
#else
	    b = true;
#endif
// 	    std::stringstream canonical;
// 	    canonical << std::boolalpha << b;
// 	    return getNumericRDFLiteral(canonical.str().c_str(), b);
	    return getBooleanRDFLiteral(p_String.c_str(), b);
	}

	std::stringstream buf;
	buf << '"' << p_String << '"';
	if (p_URI)
	    buf << "^^<" << p_URI->getLexicalValue() << ">";
	if (p_LANGTAG) {
	    std::string lang(p_LANGTAG->getLexicalValue());
	    std::locale loc("C");
	    for(std::string::iterator each= lang.begin(); each!= lang.end(); ++each)
		*each= std::tolower(*each, loc);
	    buf << "@" << lang;
	}
	std::string key(buf.str());
	RDFLiteralMap::const_iterator vi = rdfLiterals.find(key);
	if (vi == rdfLiterals.end()) {
	    RDFLiteral* ret = new RDFLiteral(p_String, p_URI, p_LANGTAG);
	    rdfLiterals[key] = ret;
	    return ret;
	} else {
	    delete p_LANGTAG; // will not be used to create an RDFLiteral.
	    return vi->second;
	}
    }

#define XSD "http://www.w3.org/2001/XMLSchema#"
#define LEN_XSD sizeof(XSD)
    const IntegerRDFLiteral* POSFactory::getNumericRDFLiteral (std::string p_String, int p_value) {
	class MakeIntegerRDFLiteral : public MakeNumericRDFLiteral {
	private: int m_value;
	public: MakeIntegerRDFLiteral (int p_value) : m_value(p_value) {  }
	    virtual const NumericRDFLiteral* makeIt (std::string p_String, const URI* p_URI) {
		return new IntegerRDFLiteral(p_String, p_URI, m_value);
	    }
	};
	MakeIntegerRDFLiteral maker(p_value);
	IntegerRDFLiteral* ret = (IntegerRDFLiteral*)getNumericRDFLiteral(p_String, "integer", &maker);
	return ret;
    }

    const DecimalRDFLiteral* POSFactory::getNumericRDFLiteral (std::string p_String, float p_value) {
	class MakeDecimalRDFLiteral : public MakeNumericRDFLiteral {
	private: float m_value;
	public: MakeDecimalRDFLiteral (float p_value) : m_value(p_value) {  }
	    virtual const NumericRDFLiteral* makeIt (std::string p_String, const URI* p_URI) {
		return new DecimalRDFLiteral(p_String, p_URI, m_value);
	    }
	};
	MakeDecimalRDFLiteral maker(p_value);
	DecimalRDFLiteral* ret = (DecimalRDFLiteral*)getNumericRDFLiteral(p_String, "decimal", &maker);
	return ret;
    }

    const FloatRDFLiteral* POSFactory::getNumericRDFLiteral (std::string p_String, float p_value, bool /* floatness */) {
	class MakeFloatRDFLiteral : public MakeNumericRDFLiteral {
	private: float m_value;
	public: MakeFloatRDFLiteral (float p_value) : m_value(p_value) {  }
	    virtual const NumericRDFLiteral* makeIt (std::string p_String, const URI* p_URI) {
		return new FloatRDFLiteral(p_String, p_URI, m_value);
	    }
	};
	MakeFloatRDFLiteral maker(p_value);
	FloatRDFLiteral* ret = (FloatRDFLiteral*)getNumericRDFLiteral(p_String, "float", &maker);
	return ret;
    }

    const DoubleRDFLiteral* POSFactory::getNumericRDFLiteral (std::string p_String, double p_value) {
	class MakeDoubleRDFLiteral : public MakeNumericRDFLiteral {
	private: double m_value;
	public: MakeDoubleRDFLiteral (double p_value) : m_value(p_value) {  }
	    virtual const NumericRDFLiteral* makeIt (std::string p_String, const URI* p_URI) {
		return new DoubleRDFLiteral(p_String, p_URI, m_value);
	    }
	};
	MakeDoubleRDFLiteral maker(p_value);
	DoubleRDFLiteral* ret = (DoubleRDFLiteral*)getNumericRDFLiteral(p_String, "double", &maker);
	return ret;
    }

    const BooleanRDFLiteral* POSFactory::getBooleanRDFLiteral (std::string p_String, bool p_value) {
	std::stringstream buf;
	buf << "\"" << (p_value ? "true" : "false") << "\"^^<http://www.w3.org/2001/XMLSchema#boolean>"; // p_String
	std::string key(buf.str());
	RDFLiteralMap::const_iterator vi = rdfLiterals.find(key);
	if (vi == rdfLiterals.end()) {
	    BooleanRDFLiteral* ret = new BooleanRDFLiteral(p_String, getURI("http://www.w3.org/2001/XMLSchema#boolean"), p_value);
	    rdfLiterals[key] = ret;
	    return ret;
	} else
	    return (BooleanRDFLiteral*)vi->second; // shameful downcast
    }

    const NumericRDFLiteral* POSFactory::getNumericRDFLiteral (std::string p_String, const char* type, MakeNumericRDFLiteral* maker) {

	std::string str;
	str += XSD;
	str += type;
	const URI* uri = getURI(str);

	std::stringstream buf;
	buf << '"' << p_String << '"';
	if (uri)
	    buf << "^^<" << uri->getLexicalValue() << ">";
	std::string key(buf.str());
	RDFLiteralMap::const_iterator vi = rdfLiterals.find(key);
	if (vi == rdfLiterals.end()) {
	    const NumericRDFLiteral* ret = maker->makeIt(p_String, uri);
	    rdfLiterals[key] = ret;
	    return ret;
	} else
	    return (const NumericRDFLiteral*)vi->second; // shameful downcast
    }

    const TriplePattern* POSFactory::getTriple (const POS* s, const POS* p, const POS* o, bool weaklyBound) {
	if (s == NULL || p == NULL || o == NULL)
	    throw
		std::string("getTriple(")
		+ (s == NULL ? "NULL" : s->toString()) + ", " 
		+ (p == NULL ? "NULL" : p->toString()) + ", " 
		+ (o == NULL ? "NULL" : o->toString()) + ")";

	std::stringstream key;
	key << s << p << o << weaklyBound;
	TriplePatternMap::const_iterator vi = triples.find(key.str());
	if (vi == triples.end()) {
	    TriplePattern* ret = new TriplePattern(s, p, o);
	    triples[key.str()] = ret;
	    return ret;
	} else {
	    const TriplePattern* ret = vi->second;
	    return ret;
	}
    }

#if REGEX_LIB == SWOb_BOOST
    void POSFactory::parseTriples (BasicGraphPattern* g, std::string spo, POS::String2BNode& nodeMap) {
	const boost::regex expression("[[:space:]]*((?:<[^>]*>)|(?:_:[^[:space:]]+)|(?:[?$][^[:space:]]+)|(?:\\\"[^\\\"]+\\\"))"
				      "[[:space:]]*((?:<[^>]*>)|(?:_:[^[:space:]]+)|(?:[?$][^[:space:]]+)|(?:\\\"[^\\\"]+\\\"))"
				      "[[:space:]]*((?:<[^>]*>)|(?:_:[^[:space:]]+)|(?:[?$][^[:space:]]+)|(?:\\\"[^\\\"]+\\\"))[[:space:]]*\\.");
	std::string::const_iterator start, end; 
	start = spo.begin(); 
	end = spo.end(); 
	boost::match_results<std::string::const_iterator> what;
	boost::match_flag_type flags = boost::match_default;
	while (regex_search(start, end, what, expression, flags)) {
	    g->addTriplePattern(getTriple(getPOS(std::string(what[1].first, what[1].second), nodeMap), 
					  getPOS(std::string(what[2].first, what[2].second), nodeMap), 
					  getPOS(std::string(what[3].first, what[3].second), nodeMap), false));
	    start = what[0].second; 
	    // update flags: 
	    flags |= boost::match_prev_avail; 
	    flags |= boost::match_not_bob; 
	}
    }
#endif /* REGEX_LIB == SWOb_BOOST */

    const POS* POSFactory::applyCommonNumeric (const Expression* arg, UnaryFunctor* func) {
	const POS* v = arg->eval(func->res, this, func->evaluator);
	const std::string lt = typeid(*v).name();
	TypeOrder::const_iterator dtp = typeOrder.find(lt);
	if (dtp == typeOrder.end())
	    throw lt + " is not a known datatype.";
	DT_Numeric dt = dtp->second;
	switch (dt) {
	case DT_Integer: {
	    int i = func->eval(static_cast<const NumericRDFLiteral*>(v)->getInt());
	    std::stringstream s;
	    s << i;
	    v = getNumericRDFLiteral(s.str(), i);
	     break;
	 }
	 case DT_Float:
	     case DT_Decimal: {
		 float i = func->eval(static_cast<const NumericRDFLiteral*>(v)->getFloat());
		 std::stringstream s;
		 s << i;
		 v = getNumericRDFLiteral(s.str(), i);
		 break;
	     }
	     case DT_Double: {
		 double i = func->eval(static_cast<const NumericRDFLiteral*>(v)->getDouble());
		 std::stringstream s;
		 s << i;
		 v = getNumericRDFLiteral(s.str(), i);
		 break;
	     }
	     default:
		 throw lt + " is not a numeric datatype: " + v->toString();
	}
	return v;
    }
    const POS* POSFactory::applyCommonNumeric (std::vector<const Expression*> args, NaryFunctor* func) {
	std::vector<const Expression*>::const_iterator it = args.begin();
	const POS* l = (*it)->eval(func->res, this, func->evaluator);
	const std::string lt = typeid(*l).name();
	TypeOrder::const_iterator dtp = typeOrder.find(lt);
	if (dtp == typeOrder.end())
	    throw lt + " is not a known datatype.";
	DT_Numeric dt = dtp->second;
	++it;
	while (it != args.end()) {
	    const POS* r = (*it)->eval(func->res, this, func->evaluator);
	    const std::string rt = typeid(*r).name();
	    dtp = typeOrder.find(rt);
	    if (dtp == typeOrder.end())
		throw rt + " is not a known datatype.";
	    if (dtp->second > dt)
		dt = dtp->second;
	    switch (dt) {
	    case DT_Integer: {
		int i = func->eval(static_cast<const NumericRDFLiteral*>(l)->getInt(), 
				   static_cast<const NumericRDFLiteral*>(r)->getInt());
		std::stringstream s;
		s << i;
		l = getNumericRDFLiteral(s.str(), i);
		break;
	    }
	    case DT_Float:
	    case DT_Decimal: {
		float i = func->eval(static_cast<const NumericRDFLiteral*>(l)->getFloat(), 
				     static_cast<const NumericRDFLiteral*>(r)->getFloat());
		std::stringstream s;
		s << i;
		l = dt == DT_Float ? getNumericRDFLiteral(s.str(), i, true) : getNumericRDFLiteral(s.str(), i);
		break;
	    }
	    case DT_Double: {
		double i = func->eval(static_cast<const NumericRDFLiteral*>(l)->getDouble(), 
				      static_cast<const NumericRDFLiteral*>(r)->getDouble());
		std::stringstream s;
		s << i;
		l = getNumericRDFLiteral(s.str(), i);
		break;
	    }
	    default:
		throw rt + " is not a numeric datatype: " + r->toString();
	    }
	    ++it;
	}
	return l;
    }

    /* EBV (Better place for this?) */
    const POS* POSFactory::ebv (const POS* pos) {
	const BooleanRDFLiteral* b = dynamic_cast<const BooleanRDFLiteral*>(pos);
	if (b != NULL)
	    return b->getValue() ? getTrue() : getFalse();
	const IntegerRDFLiteral* i = dynamic_cast<const IntegerRDFLiteral*>(pos);
	if (i != NULL)
	    return i->getValue() == 0 ? getFalse() : getTrue();
	const DecimalRDFLiteral* f = dynamic_cast<const DecimalRDFLiteral*>(pos);
	if (f != NULL)
	    return f->getValue() == 0.0 ? getFalse() : getTrue();
	const FloatRDFLiteral* fl = dynamic_cast<const FloatRDFLiteral*>(pos);
	if (fl != NULL)
	    return fl->getValue() == 0.0 ? getFalse() : getTrue();
	const DoubleRDFLiteral* d = dynamic_cast<const DoubleRDFLiteral*>(pos);
	if (d != NULL)
	    return d->getValue() == 0.0 ? getFalse() : getTrue();
	const RDFLiteral* l = dynamic_cast<const RDFLiteral*>(pos);
	const URI* dt = l == NULL ? NULL : l->getDatatype();
	if (l != NULL && 
	    (dt == NULL || dt == getURI("http://www.w3.org/2001/XMLSchema#string")))
	    return std::string(l->getLexicalValue()).empty() ? getFalse() : getTrue();
	throw TypeError("beats me", "EBV");
    }

    /* </POSFactory> */

    const POS* BNode::evalPOS (const Result* r, BNodeEvaluator* evaluator) const {
	return evaluator->evaluate(this, r);
    }
    const POS* Variable::evalPOS (const Result* r, BNodeEvaluator*) const {
	return r->get(this);
    }

    std::string Operation::toString () const {
	SPARQLSerializer s;
	express(&s);
	return s.str();
    }

    void TableJunction::addTableOperation (const TableOperation* tableOp, bool flatten) {
	if (flatten == true && typeid(*tableOp) == typeid(*this)) { // deactivated
	    TableJunction* j = (TableJunction*)tableOp; /* !!! LIES !!! */
	    for (std::vector<const TableOperation*>::const_iterator it = j->m_TableOperations.begin();
		 it != j->m_TableOperations.end(); ++it)
		m_TableOperations.push_back(*it);
	    j->m_TableOperations.clear();
	    delete j;
	} else
	    m_TableOperations.push_back(tableOp);
    }

    ResultSet* Select::execute (RdfDB* db, ResultSet* rs) const {
	if (!rs) rs = new ResultSet(rs->getPOSFactory());
	for (std::vector<const DatasetClause*>::const_iterator ds = m_DatasetClauses->begin();
	     ds != m_DatasetClauses->end(); ds++)
	    (*ds)->loadData(db);
	m_WhereClause->bindVariables(db, rs);
	if (m_SolutionModifier != NULL) {
	    m_SolutionModifier->order(rs); // @@ need to do two passes if order by can reference ?x AS ?y
	    m_VarSet->project(rs, m_SolutionModifier->groupBy, m_SolutionModifier->having);
	} else
	    m_VarSet->project(rs, NULL, NULL);
	if (m_SolutionModifier == NULL)
	    rs->trim(m_distinctness, -1, -1);
	else
	    rs->trim(m_distinctness, m_SolutionModifier->m_limit, m_SolutionModifier->m_offset);
	return rs;
    }

    ResultSet* Construct::execute (RdfDB* db, ResultSet* rs) const {
	if (!rs) rs = new ResultSet(rs->getPOSFactory());
	for (std::vector<const DatasetClause*>::const_iterator ds = m_DatasetClauses->begin();
	     ds != m_DatasetClauses->end(); ds++)
	    (*ds)->loadData(db);
	m_WhereClause->bindVariables(db, rs);
	struct MakeNewBNode : public BNodeEvaluator {
	    POSFactory* posFactory;
	    virtual const POS* evaluate (const BNode* /* node */, const Result* /* r */) {
		return posFactory->createBNode();
	    }
	public:
	    MakeNewBNode (POSFactory* posFactory) : posFactory(posFactory) {  }
	};
	MakeNewBNode makeNewBNode(rs->getPOSFactory());
	rs->resultType = ResultSet::RESULT_Graphs;
	m_ConstructTemplate->construct(rs->getRdfDB()->assureGraph(DefaultGraph), rs, &makeNewBNode);
	//std::cerr << "CONSTRUCTED: " << g << std::endl;
	return rs;
    }

    ResultSet* Ask::execute (RdfDB* db, ResultSet* rs) const {
	if (!rs) rs = new ResultSet(rs->getPOSFactory());
	for (std::vector<const DatasetClause*>::const_iterator ds = m_DatasetClauses->begin();
	     ds != m_DatasetClauses->end(); ds++)
	    (*ds)->loadData(db);
	m_WhereClause->bindVariables(db, rs);
	rs->resultType = ResultSet::RESULT_Boolean;
	return rs;
    }

    ResultSet* Insert::execute (RdfDB* db, ResultSet* rs) const {
	if (!rs) rs = new ResultSet(rs->getPOSFactory());
	if (m_WhereClause != NULL)
	    m_WhereClause->bindVariables(db, rs);
	struct MakeNewBNode : public BNodeEvaluator {
	    POSFactory* posFactory;
	    virtual const POS* evaluate (const BNode* /* node */, const Result* /* r */) {
		return posFactory->createBNode();
	    }
	public:
	    MakeNewBNode (POSFactory* posFactory) : posFactory(posFactory) {  }
	};
	MakeNewBNode makeNewBNode(rs->getPOSFactory());
	rs->resultType = ResultSet::RESULT_Graphs;
	m_GraphTemplate->construct(rs->getRdfDB(), rs, &makeNewBNode, NULL);
	return rs;
    }

    ResultSet* Delete::execute (RdfDB* db, ResultSet* rs) const {
	if (!rs) {
	    rs = new ResultSet(rs->getPOSFactory());
	    *rs->getRdfDB() = *db;
	}
	if (m_WhereClause != NULL)
	    m_WhereClause->bindVariables(db, rs);
	TreatAsVar treatAsVar;
	rs->resultType = ResultSet::RESULT_Graphs;
	m_GraphTemplate->deletePattern(rs->getRdfDB(), rs, &treatAsVar, NULL);
	return rs;
    }

    void DatasetClause::loadGraph (RdfDB* db, const POS* name, BasicGraphPattern* target) const {
	std::string nameStr = name->getLexicalValue();
	IStreamContext iptr(nameStr, IStreamContext::NONE, NULL, db->webAgent, db->debugStream);
	if (db->loadData(target, iptr, nameStr, nameStr, m_posFactory))
	    throw nameStr + ":0: error: unable to parse web document";
    }
    void DefaultGraphClause::loadData (RdfDB* db) const {
	loadGraph(db, m_IRIref, db->assureGraph(DefaultGraph));
    }
    void NamedGraphClause::loadData (RdfDB* db) const {
	loadGraph(db, m_IRIref, db->assureGraph(m_IRIref));
    }

    void WhereClause::bindVariables (RdfDB* db, ResultSet* rs) const {
	if (m_BindingClause != NULL) m_BindingClause->bindVariables(db, rs);
	m_GroupGraphPattern->bindVariables(db, rs);
    }

    void ExpressionAliasList::project (ResultSet* rs, ExpressionAliasList* groupBy, ProductionVector<const w3c_sw::Expression*>* having) const {
	rs->project(&m_Expressions, groupBy, having);
    }

    void StarVarSet::project (ResultSet* /* rs */, ExpressionAliasList* /* groupBy */, ProductionVector<const w3c_sw::Expression*>* /* having */) const {
    }

    void SolutionModifier::order (ResultSet* rs) {
	if (m_OrderConditions != NULL)
	    rs->order(m_OrderConditions);
    }

    void BindingClause::bindVariables (RdfDB* db, ResultSet* rs) const {
	for (ResultSetIterator it = rs->begin() ; it != rs->end(); ) {
	    for (std::vector<const Binding*>::const_iterator binding = begin() ; binding != end(); ++binding) {
		Result* r = new Result(rs);
		rs->insert(it, r);
		(*binding)->bindVariables(db, rs, r, m_Vars);
	    }
	    delete *it;
	    it = rs->erase(it);
	}
    }

    void Binding::bindVariables (RdfDB*, ResultSet* rs, Result* r, POSList* p_Vars) const {
	std::vector<const POS*>::const_iterator variable = p_Vars->begin();
	std::vector<const POS*>::const_iterator value = begin();
	while (value != end()) {
	    rs->set(r, *variable, *value, false);
	    variable++;
	    value++;
	}
    }

    void Filter::bindVariables (RdfDB* db, ResultSet* rs) const {
	ResultSet island(rs->getPOSFactory(), rs->debugStream);
	m_TableOperation->bindVariables(db, &island);
	for (std::vector<const Expression*>::const_iterator it = m_Expressions.begin();
	     it != m_Expressions.end(); it++)
	    island.restrict(*it);
	rs->joinIn(&island, false);
    }

    void TableConjunction::bindVariables (RdfDB* db, ResultSet* rs) const {
	ResultSet island(rs->getPOSFactory(), rs->debugStream);
	for (std::vector<const TableOperation*>::const_iterator it = m_TableOperations.begin();
	     it != m_TableOperations.end() && rs->size() > 0; it++)
	    (*it)->bindVariables(db, &island);
	rs->joinIn(&island, false);
    }

    void TableConjunction::construct (RdfDB* target, const ResultSet* rs, BNodeEvaluator* evaluator, BasicGraphPattern* bgp) const {
	for (std::vector<const TableOperation*>::const_iterator it = m_TableOperations.begin();
	     it != m_TableOperations.end() && rs->size() > 0; it++)
	    (*it)->construct(target, rs, evaluator, bgp);
    }

    void TableConjunction::deletePattern (RdfDB* target, const ResultSet* rs, BNodeEvaluator* evaluator, BasicGraphPattern* bgp) const {
	for (std::vector<const TableOperation*>::const_iterator it = m_TableOperations.begin();
	     it != m_TableOperations.end() && rs->size() > 0; it++)
	    (*it)->deletePattern(target, rs, evaluator, bgp);
    }

    void TableDisjunction::bindVariables (RdfDB* db, ResultSet* rs) const {
	ResultSet island(rs->getPOSFactory(), rs->debugStream);
	delete *(island.begin());
	island.erase(island.begin());
	for (std::vector<const TableOperation*>::const_iterator it = m_TableOperations.begin();
	     it != m_TableOperations.end(); it++) {
	    ResultSet disjoint(rs->getPOSFactory(), rs->debugStream);
	    (*it)->bindVariables(db, &disjoint);
#if 0
	    for (std::vector<const Filter*>::const_iterator it = m_Filters.begin();
		 it != m_Filters.end(); it++)
		disjoint.restrict(*it);
#endif
	    for (ResultSetIterator row = disjoint.begin() ; row != disjoint.end(); ) {
		island.insert(island.end(), (*row)->duplicate(&island, island.end()));
		delete *row;
		row = disjoint.erase(row);
	    }
	}
	rs->joinIn(&island, false);
    }

    void SubSelect::bindVariables (RdfDB* db, ResultSet* rs) const {
	ResultSet island(rs->getPOSFactory(), rs->debugStream);
	m_Select->execute(db, &island);
	rs->joinIn(&island, false);
    }

    /* wrapper function pushed into .cpp because RdfDB is incomplete. */
    void BasicGraphPattern::_bindVariables (RdfDB* db, ResultSet* rs, const POS* p_name) const {
	db->bindVariables(rs, p_name, this);

	/*
+ "algebra__filter_nested_2": 			check measured == expected
- "optional__dawg_optional_complex_1": 		check measured == ResultSet(&F, &rdfDB, "")
- "optional_filter__dawg_optional_filter_002": 	check measured == ResultSet(&F, &rdfDB, "")
- "optional_filter__dawg_optional_filter_003": 	check measured == ResultSet(&F, &rdfDB, "")
- "boolean_effective_value__dawg_bev_5": 	check measured == ResultSet(&F, &rdfDB, "")
- "boolean_effective_value__dawg_bev_6": 	check measured == ResultSet(&F, &rdfDB, "")
- "bound__dawg_bound_query_001": 		check measured == ResultSet(&F, &rdfDB, "")!

compared against
	ResultSet island(rs->getPOSFactory());
	db->bindVariables(&island, p_name, this);
	for (std::vector<const Filter*>::const_iterator it = m_Filters.begin();
	     it != m_Filters.end(); it++)
	    island.restrict(*it);
	rs->joinIn(&island, false);

	*/
    }

    CanonicalRDFLiteral::e_CANON CanonicalRDFLiteral::format = CANON_brief;
    std::ostream* BasicGraphPattern::DiffStream = NULL;
    bool BasicGraphPattern::CompareVars = false;

    /* constOrNull helper function for cheesy operator== below */
    const POS* BasicGraphPattern::_cOrN (const POS* pos, const NULLpos* n) {
	if (CompareVars)
	    return dynamic_cast<const Bindable*>(pos) ? n : pos;
	else
	    return dynamic_cast<const BNode*>(pos) ? n : pos;
    }

    bool BasicGraphPattern::operator== (const BasicGraphPattern& ref) const {
	unsigned errorCount = 0; // Only used if there's a DiffStream.
	std::map<const TriplePattern*, std::vector<const TriplePattern*> >mine;
	POSFactory f; // temp to hold trimmed triples.
	const NULLpos* n = f.getNULL();
	for (std::vector<const TriplePattern*>::const_iterator mit = 
		 m_TriplePatterns.begin();
	     mit != m_TriplePatterns.end(); ++mit)
	    mine[f.getTriple(_cOrN((*mit)->getS(), n), 
			     _cOrN((*mit)->getP(), n), 
			     _cOrN((*mit)->getO(), n))].push_back(*mit);

	for (std::vector<const TriplePattern*>::const_iterator rit = 
		 ref.m_TriplePatterns.begin();
	     rit != ref.m_TriplePatterns.end(); ++rit) {
	    const TriplePattern* r = 
		f.getTriple(_cOrN((*rit)->getS(), n), 
			    _cOrN((*rit)->getP(), n), 
			    _cOrN((*rit)->getO(), n));
	    if (mine.find(r) == mine.end()) {
		if (DiffStream != NULL) {
		    *DiffStream << "- " << (*rit)->toString() << std::endl;
		    ++errorCount;
		} else
		    return false;
	    } else {
		// Pick one at random.
		mine[r].erase(mine[r].begin());
		if (mine[r].size() == 0)
		    mine.erase(r);
	    }
	}
	if (mine.size() != 0) {
	    if (DiffStream != NULL) {
		for (std::map<const TriplePattern*, 
			 std::vector<const TriplePattern*> >::iterator mit = 
			 mine.begin(); mit != mine.end(); ++mit)
		    for (std::vector<const TriplePattern*>::iterator tpit = 
			     mit->second.begin();
			 tpit != mit->second.end(); ++ tpit) {
			*DiffStream << "+ " << (*tpit)->toString() << std::endl;
			++errorCount;
		    }
	    } else
		return false;
	}
	if (errorCount > 0) {
	    *DiffStream << errorCount << " errors" << std::endl;
	    return false;
	}
	return true;
    }

    void BasicGraphPattern::bindVariables (ResultSet* rs, const POS* graphVar, const BasicGraphPattern* toMatch, const POS* graphName) const {
	if (rs->debugStream != NULL && *rs->debugStream != NULL)
	    **rs->debugStream << "matching " << *toMatch;
	for (std::vector<const TriplePattern*>::const_iterator constraint = toMatch->m_TriplePatterns.begin();
	     constraint != toMatch->m_TriplePatterns.end(); constraint++) {
	    for (ResultSetIterator row = rs->begin() ; row != rs->end(); ) {
		bool rowMatched = false;
		const POS* pToMatch = (*constraint)->getP();

		idx_range range
		    = dynamic_cast<const Bindable*>(pToMatch) 
		    ? idx_range(idx.begin(), idx.end())
		    : idx.equal_range (pToMatch);
		for (idx_type::const_iterator triple = range.first; triple != range.second; ++triple) {
		    Result* newRow = (*row)->duplicate(rs, row);
		    /* @@@ move filter her */
		    if ((*constraint)->bindVariables(triple->second, toMatch->allOpts, rs, graphVar, newRow, graphName)) {
			rowMatched = true;
			rs->insert(row, newRow);
		    } else {
			delete newRow;
		    }
		}
		if (rowMatched || !toMatch->allOpts) {
		    delete *row;
		    row = rs->erase(row);
		} else {
		    row++;
		}
	    }
	}
	if (rs->debugStream != NULL && *rs->debugStream != NULL)
	    **rs->debugStream << "produced\n" << *rs;
    }
    bool POS::bindVariable (const POS* constant, ResultSet* rs, Result* provisional, bool weaklyBound) const {
	if (this == NULL || constant == NULL)
	    return true;
	TreatAsVar treatAsVar;
	const POS* curVal = evalPOS(provisional, &treatAsVar); // doesn't need to generate symbols
	if (curVal == NULL) {
	    rs->set(provisional, this, constant, weaklyBound);
	    return true;
	}
	return constant == curVal;
    }

    void GraphGraphPattern::construct (RdfDB* target, const ResultSet* rs, BNodeEvaluator* evaluator, BasicGraphPattern* /* bgp */) const {
	const URI* graphName = dynamic_cast<const URI*>(m_VarOrIRIref);
	if (graphName != NULL) {
	    /* GRAPH <x> { ?s ?p ?o } */
	    BasicGraphPattern* bgp = target->assureGraph(graphName);
	    m_TableOperation->construct(target, rs, evaluator, bgp);
	} else {
	    /* GRAPH ?g { ?s ?p ?o } */
	    for (ResultSetConstIterator result = rs->begin() ; result != rs->end(); result++) {
		const POS* evaldGraphName = m_VarOrIRIref->evalPOS(*result, evaluator);
		BasicGraphPattern* bgp = target->assureGraph(evaldGraphName);
		m_TableOperation->construct(target, rs, evaluator, bgp);
	    }
	}
    }

    void GraphGraphPattern::deletePattern (RdfDB* target, const ResultSet* rs, BNodeEvaluator* evaluator, BasicGraphPattern* /* bgp */) const {
	const URI* graphName = dynamic_cast<const URI*>(m_VarOrIRIref);
	if (graphName != NULL) {
	    /* GRAPH <x> { ?s ?p ?o } */
	    BasicGraphPattern* bgp = target->assureGraph(graphName);
	    m_TableOperation->deletePattern(target, rs, evaluator, bgp);
	} else {
	    /* GRAPH ?g { ?s ?p ?o } */
	    for (ResultSetConstIterator result = rs->begin() ; result != rs->end(); result++) {
		const POS* evaldGraphName = m_VarOrIRIref->evalPOS(*result, evaluator);
		BasicGraphPattern* bgp = target->assureGraph(evaldGraphName);
		m_TableOperation->deletePattern(target, rs, evaluator, bgp);
	    }
	}
    }

    void _constructQuery (const URI* service, const TableOperation* op, ResultSet* rs, POSFactory* posFactory, SWSAXparser* xmlParser, SWWEBagent* agent, std::ostream** debugStream) {
	/* The VarLister is a serializer which also records all variables.
	 */
	struct VarLister : public SPARQLSerializer {
	    std::set<const POS*> vars;
	    ExpressionAliasList* l;
	    VarLister () : l(new ExpressionAliasList()) {  }
	    virtual void variable (const Variable* const self, std::string lexicalValue) {
		if (vars.find(self) == vars.end()) {
		    vars.insert(self);
		    l->push_back(new ExpressionAlias(new POSExpression(self)));
		}
		SPARQLSerializer::variable(self, lexicalValue);
	    }
	};

	VarLister vars;
	op->express(&vars);

	/* Copy graph pattern for inclusion in a new Select. */
	SWObjectDuplicator dup(NULL); // doesn't need to create new atoms.
	op->express(&dup);
	const Operation* query = new Select(DIST_distinct, vars.l,
					    new ProductionVector<const DatasetClause*>(),
					    new WhereClause(dup.last.tableOperation, NULL),
					    new SolutionModifier(NULL, NULL, NULL, LIMIT_None, OFFSET_None)); // !!! groupBy, having

	/* Constrain query with any existing result bindings. */
	const Operation* rsConstrained = rs->getConstrainedOperation(query);
	SWWEBagent::Parameter p("query", SWWEBagent::urlEncode((rsConstrained ? rsConstrained : query)->toString()));
	if (rsConstrained)
	    delete rsConstrained;
	delete query;
	std::string q(SWWEBagent::getURL(service->getLexicalValue(), &p, 1));

	if (debugStream != NULL && *(debugStream) != NULL)
	    **(debugStream) << "Querying <" << service->getLexicalValue() << "> for\n" << q;

	/* Do an HTTP GET and parse results into a ResultSet. */
	std::string s(agent->get(q.c_str()));
	IStreamContext istr(s, IStreamContext::STRING);
	ResultSet red(posFactory, xmlParser, istr);
	if (debugStream != NULL && *(debugStream) != NULL)
	    **(debugStream) << " yielded\n" << red;

	/* Join those results against our initial results. */
	rs->joinIn(&red);
    }
    void ServiceGraphPattern::bindVariables (RdfDB* db, ResultSet* rs) const {
	const URI* graph = dynamic_cast<const URI*>(m_VarOrIRIref);
	if (graph != NULL)
	    _constructQuery(graph, m_TableOperation, rs, posFactory, db->xmlParser, db->webAgent, db->debugStream);
	else {
	    const Variable* graphVar = dynamic_cast<const Variable*>(m_VarOrIRIref);
	    if (graphVar != NULL) {
		for (ResultSetIterator outerRow = rs->begin() ; outerRow != rs->end(); ) {
		    BindingSetConstIterator binding;
		    const URI* graph;
		    if ((binding = (*outerRow)->find(graphVar)) != (*outerRow)->end()
			&& (graph = dynamic_cast<const URI*>(m_VarOrIRIref)) != NULL) {
			ResultSet* single = (*outerRow)->makeResultSet(posFactory);
			_constructQuery(graph, m_TableOperation, single, posFactory, db->xmlParser, db->webAgent, db->debugStream);
			for (ResultSetIterator innerRow = single->begin() ; innerRow != single->end(); ) {
			    rs->insert(outerRow, *innerRow);
			    single->erase(innerRow);
			}
		    } else {
			// treat like a TypeError; no result
		    }
		    delete *outerRow;
		    outerRow = rs->erase(outerRow);
		}
	    } else
		throw std::string("Service name must be an IRI; attempted to call SERVICE ").append(m_VarOrIRIref->toString());
	}
    }

    void ServiceGraphPattern::construct (RdfDB* /* target */, const ResultSet* /* rs */, BNodeEvaluator* /* evaluator */, BasicGraphPattern* /* bgp */) const {
	throw std::string("@@ServiceGraphPattern::construct not yet written");
	// const URI* serviceName = dynamic_cast<const URI*>(m_VarOrIRIref);
	// if (serviceName != NULL) {
	//     /* GRAPH <x> { ?s ?p ?o } */
	//     BasicGraphPattern* bgp = target->assureGraph(graphName);
	//     m_TableOperation->construct(target, rs, evaluator, bgp);
	// } else {
	//     /* SERVICE ?g { ?s ?p ?o } */
	//     for (ResultSetConstIterator result = rs->begin() ; result != rs->end(); result++) {
	// 	const POS* evaldServiceName = m_VarOrIRIref->evalPOS(*result, evaluator);
	// 	BasicGraphPattern* bgp = target->assureGraph(evaldServiceName);
	// 	m_TableOperation->construct(target, rs, evaluator, bgp);
	//     }
	// }
    }

    void ServiceGraphPattern::deletePattern (RdfDB* /* target */, const ResultSet* /* rs */, BNodeEvaluator* /* evaluator */, BasicGraphPattern* /* bgp */) const {
	throw std::string("@@ServiceGraphPattern::delete not yet written");
	// const URI* serviceName = dynamic_cast<const URI*>(m_VarOrIRIref);
	// if (serviceName != NULL) {
	//     /* GRAPH <x> { ?s ?p ?o } */
	//     BasicGraphPattern* bgp = target->assureGraph(graphName);
	//     m_TableOperation->deletePattern(target, rs, evaluator, bgp);
	// } else {
	//     /* SERVICE ?g { ?s ?p ?o } */
	//     for (ResultSetConstIterator result = rs->begin() ; result != rs->end(); result++) {
	// 	const POS* evaldServiceName = m_VarOrIRIref->evalPOS(*result, evaluator);
	// 	BasicGraphPattern* bgp = target->assureGraph(evaldServiceName);
	// 	m_TableOperation->deletePattern(target, rs, evaluator, bgp);
	//     }
	// }
    }

    void OptionalGraphPattern::bindVariables (RdfDB* db, ResultSet* rs) const {
	ResultSet optRS(*rs); // no POSFactory
	m_TableOperation->bindVariables(db, &optRS);
	rs->joinIn(&optRS, &m_Expressions, ResultSet::OP_outer);
    }

    void MinusGraphPattern::bindVariables (RdfDB* db, ResultSet* rs) const {
	ResultSet optRS(*rs); // no POSFactory
	m_TableOperation->bindVariables(db, &optRS);
	rs->joinIn(&optRS, NULL, ResultSet::OP_minus);
    }

    void BasicGraphPattern::construct (BasicGraphPattern* target, const ResultSet* rs, BNodeEvaluator* evaluator) const {
	for (ResultSetConstIterator result = rs->begin() ; result != rs->end(); result++)
	    for (std::vector<const TriplePattern*>::const_iterator triple = m_TriplePatterns.begin();
		 triple != m_TriplePatterns.end(); triple++)
		(*triple)->construct(target, *result, rs->getPOSFactory(), evaluator);
    }

    void BasicGraphPattern::construct (RdfDB* target, const ResultSet* rs, BNodeEvaluator* evaluator, BasicGraphPattern* bgp) const {
	if (bgp == NULL)
	    bgp = target->assureGraph(NULL);
	construct(bgp, rs, evaluator);
    }

    void BasicGraphPattern::deletePattern (RdfDB* target, const ResultSet* rs, BNodeEvaluator* /* evaluator */, BasicGraphPattern* bgp) const {
	if (bgp == NULL)
	    bgp = target->assureGraph(NULL);
	for (std::vector<const TriplePattern*>::const_iterator constraint = m_TriplePatterns.begin();
	     constraint != m_TriplePatterns.end(); constraint++) {
	    for (ResultSetConstIterator row = rs->begin() ; row != rs->end(); ++row) {
		for (std::vector<const TriplePattern*>::iterator triple = bgp->m_TriplePatterns.begin();
		     triple != bgp->m_TriplePatterns.end(); ) {
		    ResultSet* island = (*row)->makeResultSet(rs->getPOSFactory());
		    if ((*constraint)->bindVariables(*triple, false, island, NULL, *island->begin(), NULL))
			triple = bgp->m_TriplePatterns.erase(triple);
		    else
			triple++;
		    delete island;
		}
	    }
	}
    }

    bool TriplePattern::construct (BasicGraphPattern* target, const Result* r, POSFactory* posFactory, BNodeEvaluator* evaluator) const {
	bool ret = false;
	const POS *s, *p, *o;
	if ((s = m_s->evalPOS(r, evaluator)) != NULL && 
	    (p = m_p->evalPOS(r, evaluator)) != NULL && 
	    (o = m_o->evalPOS(r, evaluator)) != NULL) {
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

    TableOperation* TableOperationOnOperation::getDNF ( ) const {
	TableOperation* op = m_TableOperation->getDNF();
	TableDisjunction* disjoints;
	if ((disjoints = dynamic_cast<TableDisjunction*>(op)) == NULL) {
	    return makeANewThis(op);
	}

	/* GRAPH <X> { A || B } => GRAPH <X> { A } || GRAPH <X> { B } 
	 * likewise for OPTIONALS.*/
	TableDisjunction* ret = new TableDisjunction();
	for (std::vector<const TableOperation*>::const_iterator disjoint = disjoints->begin();
	     disjoint != disjoints->end(); disjoint++)
	    ret->addTableOperation(makeANewThis(*disjoint), false);
	disjoints->clear();
	delete disjoints;
	return ret;
    }
    TableOperation::TableOperation (const TableOperation& ref) :
	Base(ref) {
#if 0
	SWObjectDuplicator dup(NULL); // doesn't need to create new atoms.
	for (std::vector<const Filter*>::const_iterator it = ref.m_Filters.begin();
	     it != ref.m_Filters.end(); ++it) {
	    (*it)->express(&dup);
	    m_Filters.push_back(dup.last.filter);
	}
#endif
    }
    std::string TriplePattern::toString (MediaType mediaType, NamespaceMap* namespaces) const {
	std::stringstream s;
	if (mediaType.match("text/turtle")) {
	    s << m_s->toString() << " " << m_p->toString() << " " << m_o->toString() << " ." << std::endl;
	} else {
	    s << "{" << m_s->toString() << " " << m_p->toString() << " " << m_o->toString() << "}";
	}
	return s.str();
    }
    std::string TableOperation::toString (MediaType mediaType, NamespaceMap* namespaces) const {
	SPARQLSerializer s("  ", SPARQLSerializer::DEBUG_none, "", namespaces);
	express(&s);
	return s.str();
    }
    std::string BasicGraphPattern::toString (MediaType mediaType, NamespaceMap* namespaces) const {
	std::stringstream ret;
	if (mediaType.match("text/trig")) {
	    SPARQLSerializer s("  ", SPARQLSerializer::DEBUG_none, "", namespaces);
	    express(&s);
	    ret << s.str();
	} else {
	    for (std::vector<const TriplePattern*>::const_iterator triple = m_TriplePatterns.begin();
		 triple != m_TriplePatterns.end(); triple++)
		ret << (*triple)->toString(mediaType, namespaces);
	}
	return ret.str();
    }
    TableOperation* TableDisjunction::getDNF () const {
	TableDisjunction* ret = new TableDisjunction();
	for (std::vector<const TableOperation*>::const_iterator it = m_TableOperations.begin();
	     it != m_TableOperations.end(); ++it) {
	    TableOperation* op = (*it)->getDNF();
	    TableDisjunction* disjoints;
	    if ((disjoints = dynamic_cast<TableDisjunction*>(op)) != NULL) {
		for (std::vector<const TableOperation*>::const_iterator disjoint = disjoints->begin();
		     disjoint != disjoints->end(); disjoint++)
		    ret->addTableOperation(*disjoint, true);
		disjoints->clear();
		delete disjoints;
	    } else {
		ret->addTableOperation(op, true);
	    }
	}
	return ret;
    }
    TableOperation* TableConjunction::getDNF () const {
	/* Create a disjunction of conjunctions: (A & B) | (C & D) */
	TableDisjunction* ret = new TableDisjunction();
	ret->addTableOperation(new TableConjunction(), true);

	/* for each of our elements... */
	for (std::vector<const TableOperation*>::const_iterator it = m_TableOperations.begin();
	     it != m_TableOperations.end(); ++it) {
	    TableOperation* op = (*it)->getDNF();
	    TableDisjunction* disjoints;
	    TableConjunction* conjoints;
	    if ((disjoints = dynamic_cast<TableDisjunction*>(op)) != NULL) {
		/* If this conjoint is a disjunction
                 * à la A & ( B | C ) & ( D | E | F )
		 *                      ^^^^^^^^^^^^^
		 * ret is already ( A & B ) | ( A & C ) so copy each ret and append disjoints.
		 */
		for (std::vector<const TableOperation*>::iterator disjoint = disjoints->begin();
		     disjoint != disjoints->end(); ) {
		    /* for each ret conjunction */
		    for (std::vector<const TableOperation*>::iterator reti = ret->begin();
			 reti != ret->end(); reti++) {
			const TableConjunction* o = dynamic_cast<const TableConjunction*>(*reti);
			TableConjunction* n = new TableConjunction();
			/* Copy the conjunction. */
			for (std::vector<const TableOperation*>::const_iterator copyi = o->begin();
			     copyi != o->end(); copyi++)
			    n->addTableOperation(*copyi, true);
			/* Append the current disjoint. */
			n->addTableOperation(*disjoint, true);
			disjoint = disjoints->erase(disjoint);
		    }
		    disjoint = disjoints->erase(disjoint);
		}
		delete op;
		
	    } else if ((conjoints = dynamic_cast<TableConjunction*>(op)) != NULL) {
		/* A & ( B & C ) i.e. tree was not simplified */
		for (std::vector<const TableOperation*>::iterator conjoint = conjoints->begin();
		     conjoint != conjoints->end(); ) {
		    /* for each ret */
		    for (std::vector<const TableOperation*>::const_iterator reti = ret->begin();
			 reti != ret->end(); reti++) {
			const TableConjunction* c = (dynamic_cast<const TableConjunction*>(*reti));
			((TableConjunction*)c)->addTableOperation(*conjoint, true); /* !!! LIES !!! */
		    }
		    conjoint = conjoints->erase(conjoint);
		}
		delete conjoints;
	    } else {
		/* for each ret */
		for (std::vector<const TableOperation*>::const_iterator reti = ret->begin();
		     reti != ret->end(); reti++) {
		    const TableConjunction* c = (dynamic_cast<const TableConjunction*>(*reti));
		    ((TableConjunction*)c)->addTableOperation(op, true); /* !!! LIES !!! */
		}
	    }
	}

	/* If there's only one disjoint, return it. */
	if (ret->size() == 1) {
	    std::vector<const TableOperation*>::iterator it = ret->begin();
	    TableOperation* r = (TableOperation*)*it; /* !!! LIES !!! */
	    ret->erase(it);
	    delete ret;
	    return r;
	}
	return ret;
    }

    TableOperationOnOperation* Filter::makeANewThis (const TableOperation* p_TableOperation) const {
	Filter* ret = new Filter(p_TableOperation);
	SWObjectDuplicator dup(NULL); // doesn't need to create new atoms.
	for (std::vector<const Expression*>::const_iterator it = m_Expressions.begin();
	     it != m_Expressions.end(); ++it) {
	    (*it)->express(&dup);
	    ret->m_Expressions.push_back(dup.last.expression);
	}
	return ret;
    }

    std::ostream& operator<< (std::ostream& os, BasicGraphPattern const& my) {
	SPARQLSerializer s;
	my.express(&s);
	return os << s.str();
    }

    std::ostream& operator<< (std::ostream& os, TableOperation const& my) {
	return os << my.toString();
    }

    std::ostream& operator<< (std::ostream& os, WhereClause const& my) {
	SPARQLSerializer s;
	my.express(&s);
	return os << s.str();
    }

} // namespace w3c_sw

