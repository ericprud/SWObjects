/* SWObjects: components for capturing and manipulating compile trees of RDF
   languages. This should capture all of SPARQL and most of N3 (no graphs as
   parts of an RDF triple).

 * $Id: SWObjects.cpp,v 1.17 2008-12-02 04:57:12 eric Exp $
 */

#define SWObjects_STAND_ALONE
#include "SWObjects.hpp"
#undef SWObjects_STAND_ALONE
#include "ResultSet.hpp"
#include <string.h>
#include <vector>
#include <set>
#include "SPARQLSerializer.hpp"
#include "SWObjectDuplicator.hpp"
#include "../interface/WEBagent.hpp"
#include "utf8.h"

#ifdef CRYPT_LIB
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include "dll.h"
#include "md5.h"
#endif /* CRYPT_LIB */

extern "C"
{
#ifdef WIN32
#include <Rpc.h>
#else
#include <uuid/uuid.h>
#endif
}


#ifdef _MSC_VER
  #define SET_Variable_CONSTIT_NE(L, R) set_Variable_constit_ne(L, R)
  bool set_Variable_constit_ne (std::set<const w3c_sw::Variable*>::const_iterator l, 
				std::set<const w3c_sw::Variable*>::const_iterator r)
  { return l != r; }
  #define SET_POS_CONSTIT_NE(L, R) set_POS_constit_ne(L, R)
  bool set_POS_constit_ne (std::set<const w3c_sw::TTerm*>::const_iterator l, 
			   std::set<const w3c_sw::TTerm*>::const_iterator r)
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
    const char* NS_grddl="http://www.w3.org/2003/g/data-view#"		;


void Base::express (Expressor* p_expressor) const {
    p_expressor->base(this, typeid(*this).name());
}

#if defined(SWIG)
    %immutable;
#endif /* defined(SWIG) */
char const * yit = "yacker:implicit-terminal";
#if defined(SWIG)
    %mutable;
#endif /* defined(SWIG) */

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

    // Truncate URL at first space -- disabled 'cause it's convenient to abuse
    //   URL grammar in data: URLs, e.g. "data:text/plain,my data".
    // if ((p = name.find(' ')) != std::string::npos) name.erase(p++);
    
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
				 const char* p_mediaType, SWWEBagent* webAgent)
    : nameStr(nameStr), malloced(true), p(NULL)
{
    if (opts & STRING) {
	p = new std::stringstream(nameStr);
    } else if (!(opts & FILE) && webAgent != NULL
	       && !(nameStr.compare(0, 5, "http:")
		    && nameStr.compare(0, 6, "https:")
		    && nameStr.compare(0, 4, "ftp:")
		    && nameStr.compare(0, 5, "data:"))) {
	BOOST_LOG_SEV(Logger::IOLog::get(), Logger::info) << "Reading web resource " << nameStr << std::endl;
	boost::shared_ptr<IStreamContext> s(webAgent->get(nameStr.c_str()));
	if (p_mediaType == NULL) {
	    BOOST_LOG_SEV(Logger::IOLog::get(), Logger::info) << nameStr << "'s reported media type is " << webAgent->getMediaType() << ".";
	    mediaType = webAgent->getMediaType().c_str();
	} else {
	    BOOST_LOG_SEV(Logger::IOLog::get(), Logger::info) << "Overriding " << nameStr << "'s reported media type (" << webAgent->getMediaType() << ") with " << p_mediaType << ".";
	    mediaType = p_mediaType;
	}
	
	/* optimization opportunity: re-use the old rdbuf and add a ref count for reaping. */
	std::stringstream* ss = new std::stringstream(); // would be nice to use webAgent stream, or have a callback.
	*ss << s->p->rdbuf();
	p = ss;
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
				const char* p_mediaType, SWWEBagent* webAgent)
    : StreamContext<std::istream>(name, &std::cin, opts, 
				  p_mediaType, webAgent) {
    if (p == NULL) {
	BOOST_LOG_SEV(Logger::IOLog::get(), Logger::support) << "Stream constructed to read file " << nameStr << ".\n";
	std::ifstream* istr = new std::ifstream(nameStr.c_str());
	malloced = true;
	p = istr;
	if (!istr->is_open())
	    throw std::string("unable to open file \"").append(nameStr).append("\"");
    }
}

OStreamContext::OStreamContext (std::string name, e_opts opts,
				const char* p_mediaType, SWWEBagent* webAgent)
    : StreamContext<std::ostream>(name, &std::cout, opts, 
				  p_mediaType, webAgent) {
    if (p == NULL) {
	BOOST_LOG_SEV(Logger::IOLog::get(), Logger::support) << "Stream constructed to write file " << nameStr << ".\n";
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

void Members::express (Expressor* p_expressor) const {
    p_expressor->members(this, m_vars);
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
void DateTimeRDFLiteral::express (Expressor* p_expressor) const {
    p_expressor->rdfLiteral(this, terminal, TTerm::URI_xsd_dateTime, NULL);
    // w3c_sw_NEED_IMPL("DateTimeRDFLiteral non-existent in expressor");
}
void BooleanRDFLiteral::express (Expressor* p_expressor) const {
    p_expressor->rdfLiteral(this, m_value);
}
void NULLtterm::express (Expressor* p_expressor) const {
    p_expressor->nulltterm(this);
}
void TriplePattern::express (Expressor* p_expressor) const {
    p_expressor->triplePattern(this, m_s, m_p, m_o);
}
void Filter::express (Expressor* p_expressor) const {
    p_expressor->filter(this, m_TableOperation, &m_Expressions);
}
void Bind::express (Expressor* p_expressor) const {
    p_expressor->bind(this, m_TableOperation, m_expr, m_label);
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
    p_expressor->serviceGraphPattern(this, m_VarOrIRIref, m_TableOperation, m_Silence, atomFactory, lexicalCompare);
}
void ExpressionAlias::express (Expressor* p_expressor) const {
    p_expressor->expressionAlias(this, expr, label);
}
void ExpressionAliasList::express (Expressor* p_expressor) const {
    p_expressor->expressionAliasList(this, &m_Expressions);
}
void TTermList::express (Expressor* p_expressor) const {
    p_expressor->posList(this, &m_TTerms);
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
    p_expressor->solutionModifier(this, groupBy, having, m_OrderConditions, m_limit, m_offset);
}
void BindingClause::express (Expressor* p_expressor) const {
    p_expressor->bindingClause(this, m_ResultSet);
}
void WhereClause::express (Expressor* p_expressor) const {
    p_expressor->whereClause(this, m_GroupGraphPattern);
}
void OperationSet::express (Expressor* p_expressor) const {
    p_expressor->operationSet(this, &operations);
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
    p_expressor->ask(this, m_DatasetClauses,m_WhereClause,m_SolutionModifier);
}
void Modify::express (Expressor* p_expressor) const {
    p_expressor->modify(this, m_delete,m_insert,m_WhereClause);
}
void Insert::express (Expressor* p_expressor) const {
    p_expressor->insert(this, m_GraphTemplate,m_WhereClause);
}
void Delete::express (Expressor* p_expressor) const {
    p_expressor->del(this, m_GraphTemplate,m_WhereClause);
}
void Load::express (Expressor* p_expressor) const {
    p_expressor->load(this, m_Silence,m_from,m_into);
}
void Clear::express (Expressor* p_expressor) const {
    p_expressor->clear(this, m_Silence,m__QGraphIRI_E_Opt);
}
void Create::express (Expressor* p_expressor) const {
    p_expressor->create(this, m_Silence,m_GraphIRI);
}
void Drop::express (Expressor* p_expressor) const {
    p_expressor->drop(this, m_Silence,m_GraphIRI);
}
void Add::express (Expressor* p_expressor) const {
    p_expressor->add(this, m_Silence,from,to);
}
void Move::express (Expressor* p_expressor) const {
    p_expressor->move(this, m_Silence,from,to);
}
void Copy::express (Expressor* p_expressor) const {
    p_expressor->copy(this, m_Silence,from,to);
}
void TTermExpression::express (Expressor* p_expressor) const {
    p_expressor->posExpression(this, m_TTerm);
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
void ExistsExpression::express (Expressor* p_expressor) const {
    p_expressor->existsExpression(this, m_TableOperation);
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
void NaryIn::express (Expressor* p_expressor) const {
    p_expressor->naryIn(this, left, right);
}
void ComparatorExpression::express (Expressor* p_expressor) const {
    p_expressor->comparatorExpression(this, m_GeneralComparator);
}
void NumberExpression::express (Expressor* p_expressor) const {
    p_expressor->numberExpression(this, m_NumericRDFLiteral);
}

void RecursiveExpressor::bindingClause (const BindingClause* const, const ResultSet* p_ResultSet) {
    const VariableList* vars = p_ResultSet->getKnownVars();
    for (VariableList::const_iterator it = vars->begin();
	 it != vars->end(); ++it)
	(*it)->express(this);
}

#define RDFCONST(lname) { URI("http://www.w3.org/1999/02/22-rdf-syntax-ns#" #lname), NULL }
#define XSDCONST(lname) { URI("http://www.w3.org/2001/XMLSchema#" #lname), NULL }
#define XPATHCONST(lname) { URI("http://www.w3.org/2005/xpath-functions#" #lname), #lname }
#define XPATHCNST2(lname, op) { URI("http://www.w3.org/2005/xpath-functions#" #lname), op }
#define OPERATORCONST(lname) { URI("http://www.w3.org/TR/rdf-sparql-query/#" #lname), #lname }
#define EXTENCONST(lname) { URI("https://github.com/ericprud/SWObjects/wiki/Sparql-extensions#" #lname), NULL}

    /** URI constants, shared between all AtomFactories: */
    const AtomFactory::URIstr AtomFactory::_URIConstants[] = {
	// { "http://www.w3.org/2001/XMLSchema#integer", URI("http://www.w3.org/2001/XMLSchema#integer") }
	XPATHCONST   (normalize_space),
	EXTENCONST   (lastTail),
	EXTENCONST   (newTail),
	EXTENCONST   (newNil),
	EXTENCONST   (curTail),
	EXTENCONST   (newObj),

	XSDCONST(integer),
	XSDCONST(decimal),
	XSDCONST(float),
	XSDCONST(double),
	XSDCONST(string),
	XSDCONST(boolean),
	XSDCONST(nonPositiveInteger),
	XSDCONST(negativeInteger),
	XSDCONST(long),
	XSDCONST(int),
	XSDCONST(short),
	XSDCONST(byte),
	XSDCONST(nonNegativeInteger),
	XSDCONST(unsignedLong),
	XSDCONST(unsignedInt),
	XSDCONST(unsignedShort),
	XSDCONST(unsignedByte),
	XSDCONST(positiveInteger),
	XSDCONST(dateTime),

	OPERATORCONST(bound),
	OPERATORCONST(if),
	OPERATORCONST(coalesce),
	OPERATORCONST(exists), // not exists || && RDFterm-equal
	OPERATORCONST(sameTerm),
	OPERATORCONST(in), // not in
	OPERATORCONST(isIRI),
	OPERATORCONST(isURI),
	OPERATORCONST(isBlank),
	OPERATORCONST(isLiteral),
	OPERATORCONST(isNumeric),
	OPERATORCONST(str),
	OPERATORCONST(lang),
	OPERATORCONST(datatype),
	OPERATORCONST(iri),
	OPERATORCONST(uri),
	OPERATORCONST(bnode),
	OPERATORCONST(strdt),
	OPERATORCONST(strlang),
	XPATHCNST2   (string-length, "strlen"),
	XPATHCNST2   (substring, "substr"),
	XPATHCNST2   (upper-case, "ucase"),
	XPATHCNST2   (lower-case, "lcase"),
	XPATHCNST2   (starts-with, "strStarts"),
	XPATHCNST2   (ends-with, "strEnds"),
	XPATHCNST2   (substring-before, "strBefore"),
	XPATHCNST2   (substring-after, "strAfter"),
	XPATHCONST   (contains),
	XPATHCONST   (encode-for-uri),
	XPATHCONST   (concat),
	XPATHCONST   (replace),
	OPERATORCONST(langMatches),
	XPATHCNST2   (matches, "regex"),
	XPATHCNST2   (numeric-abs, "abs"),
	XPATHCNST2   (numeric-round, "round"),
	XPATHCNST2   (numeric-ceil, "ceil"),
	XPATHCNST2   (numeric-floor, "floor"),
	OPERATORCONST(rand),
	OPERATORCONST(now),
	XPATHCNST2   (year-from-dateTime, "year"),
	XPATHCNST2   (month-from-dateTime, "month"),
	XPATHCNST2   (day-from-dateTime, "day"),
	XPATHCNST2   (hours-from-dateTime, "hours"),
	XPATHCNST2   (minutes-from-dateTime, "minutes"),
	XPATHCNST2   (seconds-from-dateTime, "seconds"),
	XPATHCNST2   (timezone-from-dateTime, "timezone"),
	OPERATORCONST(tz),
	OPERATORCONST(uuid),
	OPERATORCONST(struuid),
	OPERATORCONST(md5),
	OPERATORCONST(sha1),
	OPERATORCONST(sha256),
	OPERATORCONST(sha384),
	OPERATORCONST(sha512),
	OPERATORCONST(count),
	OPERATORCONST(sum),
	OPERATORCONST(min),
	OPERATORCONST(max),
	OPERATORCONST(avg),
	OPERATORCONST(group_concat),
	OPERATORCONST(sample),
	EXTENCONST   (group_group),
	EXTENCONST   (group_regex),

	RDFCONST(type),
	RDFCONST(List),
	RDFCONST(first),
	RDFCONST(rest),
	RDFCONST(nil),
    };

#if !defined(SWIG) // SWIG 2.0.0 appears to barf on initializers for statics. \[\([0-9]+\)\] -> [\#]
    const URI* TTerm::FUNC_normalize_space	 = &AtomFactory::_URIConstants[0].uri;
    const URI* TTerm::FUNC_lastTail		 = &AtomFactory::_URIConstants[1].uri;
    const URI* TTerm::FUNC_newTail		 = &AtomFactory::_URIConstants[2].uri;
    const URI* TTerm::FUNC_newNil		 = &AtomFactory::_URIConstants[3].uri;
    const URI* TTerm::FUNC_curTail		 = &AtomFactory::_URIConstants[4].uri;
    const URI* TTerm::FUNC_newObj		 = &AtomFactory::_URIConstants[5].uri;

    const URI* TTerm::URI_xsd_integer		 = &AtomFactory::_URIConstants[6].uri;
    const URI* TTerm::URI_xsd_decimal		 = &AtomFactory::_URIConstants[7].uri;
    const URI* TTerm::URI_xsd_float		 = &AtomFactory::_URIConstants[8].uri;
    const URI* TTerm::URI_xsd_double		 = &AtomFactory::_URIConstants[9].uri;
    const URI* TTerm::URI_xsd_string		 = &AtomFactory::_URIConstants[10].uri;
    const URI* TTerm::URI_xsd_boolean		 = &AtomFactory::_URIConstants[11].uri;
    const URI* TTerm::URI_xsd_nonPositiveInteger = &AtomFactory::_URIConstants[12].uri;
    const URI* TTerm::URI_xsd_negativeInteger	 = &AtomFactory::_URIConstants[13].uri;
    const URI* TTerm::URI_xsd_long		 = &AtomFactory::_URIConstants[14].uri;
    const URI* TTerm::URI_xsd_int		 = &AtomFactory::_URIConstants[15].uri;
    const URI* TTerm::URI_xsd_short		 = &AtomFactory::_URIConstants[16].uri;
    const URI* TTerm::URI_xsd_byte		 = &AtomFactory::_URIConstants[17].uri;
    const URI* TTerm::URI_xsd_nonNegativeInteger = &AtomFactory::_URIConstants[18].uri;
    const URI* TTerm::URI_xsd_unsignedLong	 = &AtomFactory::_URIConstants[19].uri;
    const URI* TTerm::URI_xsd_unsignedInt	 = &AtomFactory::_URIConstants[20].uri;
    const URI* TTerm::URI_xsd_unsignedShort	 = &AtomFactory::_URIConstants[21].uri;
    const URI* TTerm::URI_xsd_unsignedByte	 = &AtomFactory::_URIConstants[22].uri;
    const URI* TTerm::URI_xsd_positiveInteger	 = &AtomFactory::_URIConstants[23].uri;
    const URI* TTerm::URI_xsd_dateTime		 = &AtomFactory::_URIConstants[24].uri;

    const URI* TTerm::FUNC_bound		 = &AtomFactory::_URIConstants[25].uri;
    const URI* TTerm::FUNC_if			 = &AtomFactory::_URIConstants[26].uri;
    const URI* TTerm::FUNC_coalesce		 = &AtomFactory::_URIConstants[27].uri;
    const URI* TTerm::FUNC_exists		 = &AtomFactory::_URIConstants[28].uri;
    const URI* TTerm::FUNC_sameTerm 		 = &AtomFactory::_URIConstants[29].uri;
    const URI* TTerm::FUNC_in			 = &AtomFactory::_URIConstants[30].uri;
    const URI* TTerm::FUNC_isIRI		 = &AtomFactory::_URIConstants[31].uri;
    const URI* TTerm::FUNC_isURI		 = &AtomFactory::_URIConstants[32].uri;
    const URI* TTerm::FUNC_isBlank		 = &AtomFactory::_URIConstants[33].uri;
    const URI* TTerm::FUNC_isLiteral		 = &AtomFactory::_URIConstants[34].uri;
    const URI* TTerm::FUNC_isNumeric		 = &AtomFactory::_URIConstants[35].uri;
    const URI* TTerm::FUNC_str			 = &AtomFactory::_URIConstants[36].uri;
    const URI* TTerm::FUNC_lang			 = &AtomFactory::_URIConstants[37].uri;
    const URI* TTerm::FUNC_datatype		 = &AtomFactory::_URIConstants[38].uri;
    const URI* TTerm::FUNC_iri			 = &AtomFactory::_URIConstants[39].uri;
    const URI* TTerm::FUNC_uri			 = &AtomFactory::_URIConstants[40].uri;
    const URI* TTerm::FUNC_bnode		 = &AtomFactory::_URIConstants[41].uri;
    const URI* TTerm::FUNC_strdt		 = &AtomFactory::_URIConstants[42].uri;
    const URI* TTerm::FUNC_strlang		 = &AtomFactory::_URIConstants[43].uri;
    const URI* TTerm::FUNC_string_length	 = &AtomFactory::_URIConstants[44].uri;
    const URI* TTerm::FUNC_substring		 = &AtomFactory::_URIConstants[45].uri;
    const URI* TTerm::FUNC_upper_case		 = &AtomFactory::_URIConstants[46].uri;
    const URI* TTerm::FUNC_lower_case		 = &AtomFactory::_URIConstants[47].uri;
    const URI* TTerm::FUNC_starts_with		 = &AtomFactory::_URIConstants[48].uri;
    const URI* TTerm::FUNC_ends_with		 = &AtomFactory::_URIConstants[49].uri;
    const URI* TTerm::FUNC_substring_before	 = &AtomFactory::_URIConstants[50].uri;
    const URI* TTerm::FUNC_substring_after	 = &AtomFactory::_URIConstants[51].uri;
    const URI* TTerm::FUNC_contains		 = &AtomFactory::_URIConstants[52].uri;
    const URI* TTerm::FUNC_encode_for_uri	 = &AtomFactory::_URIConstants[53].uri;
    const URI* TTerm::FUNC_concat		 = &AtomFactory::_URIConstants[54].uri;
    const URI* TTerm::FUNC_replace		 = &AtomFactory::_URIConstants[55].uri;
    const URI* TTerm::FUNC_langMatches		 = &AtomFactory::_URIConstants[56].uri;
    const URI* TTerm::FUNC_matches		 = &AtomFactory::_URIConstants[57].uri;
    const URI* TTerm::FUNC_numeric_abs		 = &AtomFactory::_URIConstants[58].uri;
    const URI* TTerm::FUNC_numeric_round	 = &AtomFactory::_URIConstants[59].uri;
    const URI* TTerm::FUNC_numeric_ceil		 = &AtomFactory::_URIConstants[60].uri;
    const URI* TTerm::FUNC_numeric_floor	 = &AtomFactory::_URIConstants[61].uri;
    const URI* TTerm::FUNC_rand			 = &AtomFactory::_URIConstants[62].uri;
    const URI* TTerm::FUNC_now			 = &AtomFactory::_URIConstants[63].uri;
    const URI* TTerm::FUNC_year_from_dateTime	 = &AtomFactory::_URIConstants[64].uri;
    const URI* TTerm::FUNC_month_from_dateTime	 = &AtomFactory::_URIConstants[65].uri;
    const URI* TTerm::FUNC_day_from_dateTime	 = &AtomFactory::_URIConstants[66].uri;
    const URI* TTerm::FUNC_hours_from_dateTime	 = &AtomFactory::_URIConstants[67].uri;
    const URI* TTerm::FUNC_minutes_from_dateTime = &AtomFactory::_URIConstants[68].uri;
    const URI* TTerm::FUNC_seconds_from_dateTime = &AtomFactory::_URIConstants[69].uri;
    const URI* TTerm::FUNC_timezone_from_dateTime= &AtomFactory::_URIConstants[70].uri;
    const URI* TTerm::FUNC_tz			 = &AtomFactory::_URIConstants[71].uri;
    const URI* TTerm::FUNC_uuid			 = &AtomFactory::_URIConstants[72].uri;
    const URI* TTerm::FUNC_struuid		 = &AtomFactory::_URIConstants[73].uri;
    const URI* TTerm::FUNC_md5			 = &AtomFactory::_URIConstants[74].uri;
    const URI* TTerm::FUNC_sha1			 = &AtomFactory::_URIConstants[75].uri;
    const URI* TTerm::FUNC_sha256		 = &AtomFactory::_URIConstants[76].uri;
    const URI* TTerm::FUNC_sha384		 = &AtomFactory::_URIConstants[77].uri;
    const URI* TTerm::FUNC_sha512		 = &AtomFactory::_URIConstants[78].uri;
    const URI* TTerm::FUNC_count		 = &AtomFactory::_URIConstants[79].uri;
    const URI* TTerm::FUNC_sum			 = &AtomFactory::_URIConstants[80].uri;
    const URI* TTerm::FUNC_min			 = &AtomFactory::_URIConstants[81].uri;
    const URI* TTerm::FUNC_max			 = &AtomFactory::_URIConstants[82].uri;
    const URI* TTerm::FUNC_avg			 = &AtomFactory::_URIConstants[83].uri;
    const URI* TTerm::FUNC_group_concat		 = &AtomFactory::_URIConstants[84].uri;
    const URI* TTerm::FUNC_sample		 = &AtomFactory::_URIConstants[85].uri;
    const URI* TTerm::FUNC_group_group		 = &AtomFactory::_URIConstants[86].uri;
    const URI* TTerm::FUNC_group_regex		 = &AtomFactory::_URIConstants[87].uri;

    const URI* TTerm::RDF_type			 = &AtomFactory::_URIConstants[88].uri;
    const URI* TTerm::RDF_List			 = &AtomFactory::_URIConstants[89].uri;
    const URI* TTerm::RDF_first			 = &AtomFactory::_URIConstants[90].uri;
    const URI* TTerm::RDF_rest			 = &AtomFactory::_URIConstants[91].uri;
    const URI* TTerm::RDF_nil			 = &AtomFactory::_URIConstants[92].uri;
#endif /* !defined(SWIG) */

    const BooleanRDFLiteral AtomFactory::_BooleanConstants[2] = {
	BooleanRDFLiteral("true",  TTerm::URI_xsd_boolean, true),
	BooleanRDFLiteral("false", TTerm::URI_xsd_boolean, false)
    };

#if !defined(SWIG) // SWIG 2.0.0 appears to barf on initializers for statics.
    const BooleanRDFLiteral* TTerm::BOOL_true	 = AtomFactory::_BooleanConstants + 0;
    const BooleanRDFLiteral* TTerm::BOOL_false	 = AtomFactory::_BooleanConstants + 1;

    AtomFactory::URIMap AtomFactory::uris_static (_URIConstants, 
						  _URIConstants + sizeof(_URIConstants)/sizeof(_URIConstants[0]));
    AtomFactory::RDFLiteralMap AtomFactory::rdfLiterals_static (_BooleanConstants, 
								_BooleanConstants + sizeof(_BooleanConstants)/sizeof(_BooleanConstants[0]));
    AtomFactory::pURI_str AtomFactory::operatorNames_static (_URIConstants, 
						  _URIConstants + sizeof(_URIConstants)/sizeof(_URIConstants[0]));
#endif /* !defined(SWIG) */

    const NULLtterm AtomFactory::_NULLtterm;

    const NULLtterm* TTerm::Unbound		 = &AtomFactory::_NULLtterm;

    namespace AtomicFunction {
	namespace BuiltIn {
	    const TTerm* EXTFUNC_normalize_space (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* sterm = dynamic_cast<const RDFLiteral*>(args[0]);
		if (sterm == NULL)
		    throw TypeError(args[0]->toString(), "EXTFUNC_normalize_space");
		std::string s = sterm->getLexicalValue();
		bool lastWasSpace = false;
		for (std::string::iterator sit = s.begin(); sit != s.end(); ) {
		    if (::isspace(*sit)) {
			if (sit == s.begin() || lastWasSpace)
			    sit = s.erase(sit);
			else {
			    lastWasSpace = true;
			    ++sit;
			}
		    } else {
			lastWasSpace = false;
			++sit;
		    }
		}
		if (lastWasSpace)
		    s.erase(s.length()-1);
		std::stringstream ss;
		return atomFactory->getRDFLiteral(s, sterm->getDatatype(), NULL, false);
	    }

	    struct TailDetails {
		int pageNo;
		const TTerm* lastTail;
		const TTerm* newTail;
		const TTerm* newNil;
		const TTerm* curTail;
	    };
	    TailDetails getTailDetails (std::vector<const TTerm*>& args, AtomFactory* atomFactory, const RdfDB* db, std::string function) {
		const URI* container = dynamic_cast<const URI*>(args[0]);
		if (container == NULL)
		    throw TypeError(args[0]->toString(), function + " arg1 (container)");
		const URI* membershipSubject = dynamic_cast<const URI*>(args[1]);
		if (membershipSubject == NULL)
		    throw TypeError(args[1]->toString(), function + " arg2 (membershipSubject subject)");
		const URI* membershipPredicate = dynamic_cast<const URI*>(args[2]);
		if (membershipPredicate == NULL)
		    throw TypeError(args[2]->toString(), function + " arg3 (membershipPredicate predicate)");
		const IntegerRDFLiteral* perPage = dynamic_cast<const IntegerRDFLiteral*>(args[3]);
		if (membershipPredicate == NULL)
		    throw TypeError(args[3]->toString(), function + " arg4 (elements per page)");
		// w3c_sw_LINEN << "tailDetails("    << container->toString()
		// 	     <<              ", " << membershipSubject->toString()
		// 	     <<              ", " << membershipPredicate->toString()
		// 	     <<              ", " << perPage->toString()
		// 	     << ")\n";

		TailDetails ret;
#if CHECK_IN_EACH_GRAPH_FOR_MEMBERSHIP
		std::set<const TTerm*> names = db->getGraphNames();
		for (std::set<const TTerm*>::const_iterator name = names.begin(); name != names.end(); ++name) {
		    BasicGraphPattern* bgp = db->findGraph(*name);
		    // w3c_sw_LINEN << "GRAPH " << (*name)->toString() << " " << bgp->toString() << "\n";
		    const TTerm* pageOf = atomFactory->getURI("http://open-services.net/ns/basicProfile#pageOf");
		    for (std::set<const TTerm*>::const_iterator si = subjs.begin(); si != subjs.end(); ++si)
			w3c_sw_LINEN << "GRAPH " << (*name)->toString() << " " << (*si)->toString() << "\n";
		}
#else /* !CHECK_IN_EACH_GRAPH_FOR_MEMBERSHIP */
		ret.pageNo = 1;
		while (db->findGraph(atomFactory->getURI
				     (container->getLexicalValue() + "?p="
				      + boost::lexical_cast<std::string>(ret.pageNo)))) {
		    ret.lastTail = atomFactory->getURI
			(container->getLexicalValue() + "?p="
			 + boost::lexical_cast<std::string>(ret.pageNo));
		    ++ret.pageNo;
		}
		--ret.pageNo;
		if (ret.pageNo == 0) {
		    ret.lastTail = TTerm::Unbound;
		    ret.newTail = atomFactory->getURI
			(container->getLexicalValue() + "?p="
			 + boost::lexical_cast<std::string>(ret.pageNo+1));
		    ret.newNil = TTerm::Unbound;
		    ret.curTail = ret.newTail;
		} else {
		    BasicGraphPattern* bgp = db->findGraph(ret.lastTail);
		    std::set<const TTerm*> subjs = bgp->expectNObjects(membershipSubject, membershipPredicate);
		    if (subjs.size() < (size_t)perPage->getInt()) {
			// Page is below capacity.
			ret.newTail = TTerm::Unbound;
			ret.newNil = TTerm::RDF_nil;
			ret.curTail = ret.lastTail;
		    } else {
			// Page is at capacity; add NewObj to a new page.
			ret.newTail = atomFactory->getURI
			    (container->getLexicalValue() + "?p="
			     + boost::lexical_cast<std::string>(ret.pageNo+1));
			ret.newNil = TTerm::Unbound;
			ret.curTail = ret.newTail;
		    }
		}
#endif /* !CHECK_IN_EACH_GRAPH_FOR_MEMBERSHIP */
		// w3c_sw_LINEN << "\n"
		//     << "  pageNo:"   << ret.pageNo                                         << "\n"
		//     << "  lastTail:" << (ret.lastTail ? ret.lastTail->toString() : "NULL") << "\n"
		//     << "  newTail: " << (ret.newTail  ? ret.newTail ->toString() : "NULL") << "\n"
		//     << "  newNil: "  << (ret.newNil   ? ret.newNil  ->toString() : "NULL") << "\n"
		//     << "  curTail: " << (ret.curTail  ? ret.curTail ->toString() : "NULL") << "\n"
		//     ;
		return ret;
	    }

	    const TTerm* EXTFUNC_lastTail (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* db) {
		return getTailDetails(args, atomFactory, db, "ldp:lastTail").lastTail;
	    }
	    const TTerm* EXTFUNC_newTail (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* db) {
		return getTailDetails(args, atomFactory, db, "ldp:newTail").newTail;
	    }
	    const TTerm* EXTFUNC_newNil (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* db) {
		return getTailDetails(args, atomFactory, db, "ldp:newNil").newNil;
	    }
	    const TTerm* EXTFUNC_curTail (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* db) {
		return getTailDetails(args, atomFactory, db, "ldp:curTail").curTail;
	    }
	    const TTerm* EXTFUNC_newObj (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* db) {
		const URI* newItemBase = dynamic_cast<const URI*>(args[0]);
		if (newItemBase == NULL)
		    throw TypeError(args[0]->toString(), "ldp:newObj arg1 (newItemBase)");

		int lastItem = 1;
		while (db->findGraph(atomFactory->getURI
				     (newItemBase->getLexicalValue()
				      + boost::lexical_cast<std::string>(lastItem))))
		    ++lastItem;

		return atomFactory->getURI
		    (newItemBase->getLexicalValue()
		     + boost::lexical_cast<std::string>(lastItem));
	    }

	    /** numericCast - casts from numeric|boolean|string|simple literal to numeric|boolean.
	     * canonicalizes all casts except those from string.
	     */
	    const TTerm* numericCast (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		// from URI_xsd_float, URI_xsd_double, URI_xsd_decimal, URI_xsd_integer:
		const NumericRDFLiteral* n = dynamic_cast<const NumericRDFLiteral*>(args[0]);
		if (n != NULL) {
		    if (name == TTerm::URI_xsd_float  ) return atomFactory->getNumericRDFLiteral(n->getFloat(), true);
		    if (name == TTerm::URI_xsd_double ) return atomFactory->getNumericRDFLiteral(n->getDouble());
		    if (name == TTerm::URI_xsd_decimal) return atomFactory->getNumericRDFLiteral(n->getFloat());
		    if (name == TTerm::URI_xsd_integer) return atomFactory->getNumericRDFLiteral(n->getInt());
		    if (name == TTerm::URI_xsd_boolean) return atomFactory->getBooleanRDFLiteral
							  (n->getFloat() != 0 && n->getInt() != 0);
		    throw TypeError(n->toString(), name->toString()); // @@shorten?
		}

		// from URI_xsd_boolean:
		const BooleanRDFLiteral* b = dynamic_cast<const BooleanRDFLiteral*>(args[0]);
		if (b != NULL) {
		    if (name == TTerm::URI_xsd_float  ) return atomFactory->getNumericRDFLiteral(float(b->getValue()), true);
		    if (name == TTerm::URI_xsd_double ) return atomFactory->getNumericRDFLiteral(double(b->getValue()));
		    if (name == TTerm::URI_xsd_decimal) return atomFactory->getNumericRDFLiteral(float(b->getValue()));
		    if (name == TTerm::URI_xsd_integer) return atomFactory->getNumericRDFLiteral(int(b->getValue()));
		    if (name == TTerm::URI_xsd_boolean) return atomFactory->getNumericRDFLiteral(b->getValue()); // normalizes
		    throw TypeError(b->toString(), name->toString()); // @@shorten?
		}

		// from URI_xsd_string, simple literal:
		const RDFLiteral* s = dynamic_cast<const RDFLiteral*>(args[0]);
		if (s != NULL && (s->getDatatype() == NULL || s->getDatatype() == TTerm::URI_xsd_string))
		    return atomFactory->getRDFLiteral(args[0]->getLexicalValue(), name, NULL, true); // validates

		throw TypeError(args[0]->toString(), name->toString()); // @@shorten?
	    }

	    const TTerm* URI_xsd_dateTime (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* s = dynamic_cast<const RDFLiteral*>(args[0]);
		if (s != NULL) {
		    const URI* dt = s->getDatatype();
		    if (dt == NULL || 
			dt == TTerm::URI_xsd_dateTime  )// adjust
			return atomFactory->getRDFLiteral(args[0]->getLexicalValue(), name, NULL, true);
		}
		throw TypeError(args[0]->toString(), "dateTime");
	    }

	    const TTerm* URI_xsd_string (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		return atomFactory->getRDFLiteral(args[0]->getLexicalValue(), name, NULL, true);
	    }

	    const TTerm* FUNC_bound (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		return args[0] == TTerm::Unbound ? TTerm::BOOL_false : TTerm::BOOL_true;
	    }

	    const TTerm* FUNC_isIRI (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		return dynamic_cast<const URI*>(args[0]) == NULL ? TTerm::BOOL_false : TTerm::BOOL_true;
	    }

	    const TTerm* FUNC_isBlank (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		return dynamic_cast<const BNode*>(args[0]) == NULL ? TTerm::BOOL_false : TTerm::BOOL_true;
	    }

	    const TTerm* FUNC_isLiteral (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		return dynamic_cast<const RDFLiteral*>(args[0]) == NULL ? TTerm::BOOL_false : TTerm::BOOL_true;
	    }

	    const TTerm* FUNC_isNumeric (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		return dynamic_cast<const NumericRDFLiteral*>(args[0]) == NULL ? TTerm::BOOL_false : TTerm::BOOL_true;
	    }

	    const TTerm* FUNC_str (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		if (dynamic_cast<const RDFLiteral*>(args[0]) != NULL)
		    return atomFactory->getRDFLiteral(args[0]->getLexicalValue());
		if (dynamic_cast<const URI*>(args[0]) != NULL)
		    return atomFactory->getRDFLiteral(args[0]->getLexicalValue());
		throw TypeError(args[0]->toString(), "name");
	    }

	    const TTerm* FUNC_lang (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		if (dynamic_cast<const RDFLiteral*>(args[0]) == NULL)
		    throw TypeError(args[0]->toString(), "FUNC_lang");
		const LANGTAG* t = dynamic_cast<const RDFLiteral*>(args[0])->getLangtag();
		return atomFactory->getRDFLiteral(t ? t->getLexicalValue() : "");
	    }

	    const TTerm* FUNC_iri (const URI* /* name */, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* s = dynamic_cast<const RDFLiteral*>(args[0]);
		if (s == NULL)
		    throw TypeError(args[0]->toString(), "IRI");
		std::string name = s->getLexicalValue();
		if (args.size() == 2 && args[1] != NULL) {
		    std::string baseURI = args[1]->getLexicalValue();
		    std::string abs(libwww::HTParse(name, &baseURI, libwww::PARSE_all));
		    size_t pos = abs.find_last_of("/");
		    if (pos != std::string::npos && abs.size() == pos + 2 && abs[pos+1] == '.')
			abs = abs.substr(0, pos+1);
		    return atomFactory->getURI(abs);
		}
		return atomFactory->getURI(name);
	    }

	    const TTerm* FUNC_strdt (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* val = dynamic_cast<const RDFLiteral*>(args[0]);
		const URI* dt = dynamic_cast<const URI*>(args[1]);
		if (val == NULL || val->getDatatype() != NULL || val->getLangtag() != NULL)
		    throw TypeError(args[0]->toString(), "STRDT");
		if (dt == NULL)
		    throw TypeError(args[1]->toString(), "STRDT");
		return atomFactory->getRDFLiteral(val->getLexicalValue(), dt);
	    }

	    const TTerm* FUNC_strlang (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* val = dynamic_cast<const RDFLiteral*>(args[0]);
		const RDFLiteral* lang = dynamic_cast<const RDFLiteral*>(args[1]);
		if (val == NULL || val->getDatatype() != NULL || val->getLangtag() != NULL)
		    throw TypeError(args[0]->toString(), "STRDT");
		if (lang == NULL || lang->getDatatype() != NULL || lang->getLangtag() != NULL)
		    throw TypeError(args[1]->toString(), "STRDT");
		return atomFactory->getRDFLiteral(val->getLexicalValue(), NULL, new LANGTAG(lang->getLexicalValue()));
	    }

	    const TTerm* FUNC_bnode (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* bnodeMap, const RdfDB* /* db */) {
		if (args.size() == 0)
		    return atomFactory->createBNode();
		if (args.size() == 1 && dynamic_cast<const RDFLiteral*>(args[0]) != NULL)
		    return atomFactory->getBNode(args[0]->getLexicalValue(), bnodeMap);
		throw TypeError(args[0]->toString(), "BNode");
	    }

	    const TTerm* FUNC_datatype (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		if (dynamic_cast<const RDFLiteral*>(args[0]) != NULL && 
		    dynamic_cast<const RDFLiteral*>(args[0])->getLangtag() == NULL) {
		    const URI* dt = dynamic_cast<const RDFLiteral*>(args[0])->getDatatype();
		    return dt ? dt : TTerm::URI_xsd_string;
		}
		throw TypeError(args[0]->toString(), name->toString());
	    }

	    const TTerm* FUNC_lower_case (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		if (dynamic_cast<const RDFLiteral*>(args[0]) != NULL) {
		    const RDFLiteral* upper = dynamic_cast<const RDFLiteral*>(args[0]);
		    std::string lex = upper->getLexicalValue();
		    std::transform(lex.begin(), lex.end(), lex.begin(), ::tolower);
		    LANGTAG* l = upper->getLangtag() ? new LANGTAG(*upper->getLangtag()) : NULL;
		    return atomFactory->getRDFLiteral(lex, upper->getDatatype(), l); // !!! loses e.g. DateTimeRDFLiteral
		}
		throw TypeError(args[0]->toString(), name->toString());
	    }

	    const TTerm* FUNC_upper_case (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		if (dynamic_cast<const RDFLiteral*>(args[0]) != NULL) {
		    const RDFLiteral* lower = dynamic_cast<const RDFLiteral*>(args[0]);
		    std::string lex = lower->getLexicalValue();
		    std::transform(lex.begin(), lex.end(), lex.begin(), ::toupper);
		    LANGTAG* l = lower->getLangtag() ? new LANGTAG(*lower->getLangtag()) : NULL;
		    return atomFactory->getRDFLiteral(lex, lower->getDatatype(), l); // !!! loses e.g. DateTimeRDFLiteral
		}
		throw TypeError(args[0]->toString(), name->toString());
	    }

	    const TTerm* FUNC_string_length (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		if (dynamic_cast<const RDFLiteral*>(args[0]) != NULL) {
		    const RDFLiteral* upper = dynamic_cast<const RDFLiteral*>(args[0]);
		    std::string lex = upper->getLexicalValue();
		    int i = utf8::distance(lex.begin(), lex.end());
		    return atomFactory->getNumericRDFLiteral(i);
		}
		throw TypeError(args[0]->toString(), name->toString());
	    }


	    // http://www.zedwood.com/article/111/cpp-urlencode-function
	    std::string char2hex( char dec ) {
		char dig1 = (dec&0xF0)>>4;
		char dig2 = (dec&0x0F);
		if ( 0<= dig1 && dig1<= 9) dig1+=48;    //0,48inascii
		if (10<= dig1 && dig1<=15) dig1+=65-10; //a,97inascii
		if ( 0<= dig2 && dig2<= 9) dig2+=48;
		if (10<= dig2 && dig2<=15) dig2+=65-10;

		std::string r;
		r.append( &dig1, 1);
		r.append( &dig2, 1);
		return r;
	    }

	    const TTerm* FUNC_encode_for_uri (const URI* /* name */, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* s = dynamic_cast<const RDFLiteral*>(args[0]);
		if (s == NULL)
		    throw TypeError(args[0]->toString(), "encode_for_uri");

		const URI* fd = s->getDatatype();
		if (fd != NULL && fd != TTerm::URI_xsd_string)
		    throw TypeError(args[0]->toString(), "encode_for_uri");

		std::string c = s->getLexicalValue();
		std::string escaped="";
		int max = c.length();
		for(int i=0; i<max; i++) {
		    if ( (48 <= c[i] && c[i] <= 57) ||//0-9
			 (65 <= c[i] && c[i] <= 90) ||//abc...xyz
			 (97 <= c[i] && c[i] <= 122) || //ABC...XYZ
			 (c[i]=='~' || c[i]=='!' || c[i]=='*' || c[i]=='(' || c[i]==')' || c[i]=='\'')
			 ) {
			escaped.append( &c[i], 1);
		    } else {
			escaped.append("%");
			escaped.append( char2hex(c[i]) );//converts char 255 to string "ff"
		    }
		}
		return atomFactory->getRDFLiteral(escaped);
	    }

	    const TTerm* FUNC_concat (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		std::stringstream ss;
		bool allStrings = true;
		std::string lastLangTag;
		bool sameLang = true;

		for (std::vector<const TTerm*>::const_iterator sub = args.begin();
		     sub != args.end(); ++sub) {
		    const RDFLiteral* s = dynamic_cast<const RDFLiteral*>(*sub);
		    if (s == NULL ||
			(s->getDatatype() != NULL && s->getDatatype() != TTerm::URI_xsd_string))
			throw TypeError(std::string("unexpected ") + (s ? s->toString() : std::string("NULL")),
					"concat");
		    if (s->getDatatype() != TTerm::URI_xsd_string)
			allStrings = false;
		    if (s->getLangtag()) {
			if (sub == args.begin())
			    lastLangTag = s->getLangtag()->getLexicalValue();
			else if (sameLang && s->getLangtag()->getLexicalValue() != lastLangTag)
			    sameLang = false;
		    } else
			sameLang = false;
		    ss << s->getLexicalValue();
		}
		return atomFactory->getRDFLiteral
		    (ss.str(),
		     allStrings ? TTerm::URI_xsd_string : NULL,
		     sameLang ? new LANGTAG(lastLangTag) : NULL,
		     false);
	    }

	    std::wstring _from8 (std::string from) {
		std::wstring ret;
		utf8::utf8to32(from.begin(), from.end(), back_inserter(ret));
		return ret;
	    }

	    std::string _to8 (std::wstring from) {
		std::string ret;
		utf8::utf32to8(from.begin(), from.end(), back_inserter(ret));
		return ret;
	    }

	    const TTerm* FUNC_replace (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* changeMe  = dynamic_cast<const RDFLiteral*>(args[0]);
		if (changeMe == NULL || (changeMe->getDatatype() != NULL && changeMe->getDatatype() != TTerm::URI_xsd_string))
		    throw TypeError(args[0]->toString(), "fn:replace");
		std::string s = changeMe->getLexicalValue();

		const RDFLiteral* fromL = dynamic_cast<const RDFLiteral*>(args[1]);
		if (fromL == NULL || fromL->getDatatype() != NULL)
		    throw TypeError(args[1]->toString(), "fn:replace");
		std::string from = fromL->getLexicalValue();

		const RDFLiteral* toL = dynamic_cast<const RDFLiteral*>(args[2]);
		if (toL == NULL || toL->getDatatype() != NULL)
		    throw TypeError(args[2]->toString(), "fn:replace");
		std::string to = toL->getLexicalValue();

#if REGEX_LIB == SWOb_BOOST
		// Convert the target text and the from and to patterns to UCS32.
		std::wstring ws = _from8(s);
		std::basic_ostringstream<wchar_t> ss(std::ios::out | std::ios::binary);
		std::ostream_iterator<wchar_t, wchar_t> oi(ss);
		boost::regex_replace(oi, ws.begin(), ws.end(),
				     boost::wregex(_from8(from)), _from8(to), 
				     boost::match_default | boost::format_all);
		// Convert the result to UTF-8.
		s = _to8(ss.str());
#else /* REGEX_LIB != SWOb_BOOST */
		for (size_t i = 0; (i = s.find(from, i)) != std::string::npos; i += to.size())
		    s.replace(i, from.size(), to);
#endif /* REGEX_LIB != SWOb_BOOST */

		LANGTAG* l = changeMe->getLangtag() ? new LANGTAG(*changeMe->getLangtag()) : NULL;
		return atomFactory->getRDFLiteral(s, changeMe->getDatatype(), l, false);
	    }

	    const TTerm* FUNC_sameTerm (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		return args[0] == args[1] && args[0] != TTerm::Unbound ? TTerm::BOOL_true : TTerm::BOOL_false;
	    }

	    const TTerm* FUNC_langMatches (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* firstLit  = dynamic_cast<const RDFLiteral*>(args[0]);
		const RDFLiteral* secondLit = dynamic_cast<const RDFLiteral*>(args[1]);

		if (firstLit == NULL ||
		    secondLit == NULL) {
		    throw TypeError(args[0]->toString(), name->toString());
		}

		/* knock off the easy ones... */
		if (args[0] == args[1])
		    return TTerm::BOOL_true;
		std::string tag = firstLit->getLexicalValue();
		std::string range = secondLit->getLexicalValue();
		if (range == "*")
		    return tag.empty() ? TTerm::BOOL_false : TTerm::BOOL_true;

		std::string::iterator t = tag.begin();
		std::string::iterator te = tag.end();
		std::string::iterator r = range.begin();
		std::string::iterator re = range.end();

		while (t != te && r != re)
		    if (::tolower(*t++) != ::tolower(*r++))
			return TTerm::BOOL_false;

		if (r == re && 
		    (t == te || *t == '-'))
		    return TTerm::BOOL_true;

		return TTerm::BOOL_false;
	    }

	    const TTerm* FUNC_numeric_abs (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		struct UnaryAbsolutifier : public AtomFactory::UnaryFunctor {
		    UnaryAbsolutifier () : AtomFactory::UnaryFunctor(NULL, NULL, NULL, NULL) {  } // @@ get rid of these
		    virtual int eval (int v) { return v < 0 ? -v : v; }
		    virtual float eval (float v) { return v < 0 ? -v : v; }
		    virtual double eval (double v) { return v < 0 ? -v : v; }
		};
		UnaryAbsolutifier f;
		return atomFactory->applyCommonNumeric(args[0], &f);
	    }

	    const TTerm* FUNC_numeric_round (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		struct UnaryRounder : public AtomFactory::UnaryFunctor {
		    UnaryRounder () : AtomFactory::UnaryFunctor(NULL, NULL, NULL, NULL) {  } // @@ get rid of these
		    virtual int eval (int v) { return v; }
		    virtual float eval (float v) { return ::roundf(v); }
		    virtual double eval (double v) { return ::round(v); }
		};
		UnaryRounder f;
		return atomFactory->applyCommonNumeric(args[0], &f);
	    }

	    const TTerm* FUNC_numeric_ceil (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		struct UnaryCeiler : public AtomFactory::UnaryFunctor {
		    UnaryCeiler () : AtomFactory::UnaryFunctor(NULL, NULL, NULL, NULL) {  } // @@ get rid of these
		    virtual int eval (int v) { return v; }
		    virtual float eval (float v) { return ::ceilf(v); }
		    virtual double eval (double v) { return ::ceil(v); }
		};
		UnaryCeiler f;
		return atomFactory->applyCommonNumeric(args[0], &f);
	    }

	    const TTerm* FUNC_numeric_floor (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		struct UnaryFloorer : public AtomFactory::UnaryFunctor {
		    UnaryFloorer () : AtomFactory::UnaryFunctor(NULL, NULL, NULL, NULL) {  } // @@ get rid of these
		    virtual int eval (int v) { return v; }
		    virtual float eval (float v) { return ::floorf(v); }
		    virtual double eval (double v) { return ::floor(v); }
		};
		UnaryFloorer f;
		return atomFactory->applyCommonNumeric(args[0], &f);
	    }

	    void checkArgumentCompatibility (const RDFLiteral* firstLit, const RDFLiteral* secondLit, const char* func) {
		if (firstLit == NULL || secondLit == NULL)
		    throw TypeError(std::string("unexpected ") + (secondLit ? secondLit->toString() : "NULL"), func);
		const LANGTAG* fl = firstLit->getLangtag();
		const URI* fd = firstLit->getDatatype();
		const LANGTAG* sl = secondLit->getLangtag();
		const URI* sd = firstLit->getDatatype();
		if (!
		    (// The arguments are simple literals or literals typed as xsd:string
		     (fl == NULL && (fd == NULL || fd == TTerm::URI_xsd_string) && sl == NULL && (sd == NULL || sd == TTerm::URI_xsd_string))
		     || 
		     // The arguments are plain literals with identical language tags
		     (fl && sl && (fl->getLexicalValue() == sl->getLexicalValue()))
		     || 
		     // The first argument is a plain literal with language tag and the second argument is a simple literal or literal typed as xsd:string
		     (fl != NULL && fd == NULL && sl == NULL && (sd == NULL || sd == TTerm::URI_xsd_string))
		     )
		    )
		    throw TypeError(std::string("mismatched language tags"), func);
	    }
	    const TTerm* FUNC_contains (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* firstLit  = dynamic_cast<const RDFLiteral*>(args[0]);
		const RDFLiteral* secondLit = dynamic_cast<const RDFLiteral*>(args[1]);
		checkArgumentCompatibility(firstLit, secondLit, "contains");

		std::string lookIn = firstLit->getLexicalValue();
		std::string lookFor = secondLit->getLexicalValue();
		size_t found = lookIn.find(lookFor);
		return found == std::string::npos ? TTerm::BOOL_false : TTerm::BOOL_true;
	    }

	    const TTerm* FUNC_substring_before (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* firstLit  = dynamic_cast<const RDFLiteral*>(args[0]);
		const RDFLiteral* secondLit = dynamic_cast<const RDFLiteral*>(args[1]);
		checkArgumentCompatibility(firstLit, secondLit, "strbefore");

		std::string lookIn = firstLit->getLexicalValue();
		std::string lookFor = secondLit->getLexicalValue();
		size_t found = lookIn.find(lookFor);
		if (found == std::string::npos)
		    return atomFactory->getRDFLiteral("", NULL, NULL, false);
		LANGTAG* l = firstLit->getLangtag() ? new LANGTAG(*firstLit->getLangtag()) : NULL;
		return atomFactory->getRDFLiteral(lookIn.substr(0, found), firstLit->getDatatype(), l, false);
	    }

	    const TTerm* FUNC_substring_after (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* firstLit  = dynamic_cast<const RDFLiteral*>(args[0]);
		const RDFLiteral* secondLit = dynamic_cast<const RDFLiteral*>(args[1]);
		checkArgumentCompatibility(firstLit, secondLit, "strafter");

		std::string lookIn = firstLit->getLexicalValue();
		std::string lookFor = secondLit->getLexicalValue();
		size_t found = lookIn.find(lookFor);
		if (found == std::string::npos)
		    return atomFactory->getRDFLiteral("", NULL, NULL, false);
		LANGTAG* l = firstLit->getLangtag() ? new LANGTAG(*firstLit->getLangtag()) : NULL;
		return atomFactory->getRDFLiteral(lookIn.substr(found + lookFor.size()), firstLit->getDatatype(), l, false);
	    }

	    const TTerm* FUNC_starts_with (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* firstLit  = dynamic_cast<const RDFLiteral*>(args[0]);
		const RDFLiteral* secondLit = dynamic_cast<const RDFLiteral*>(args[1]);
		checkArgumentCompatibility(firstLit, secondLit, "strStarts");

		std::string lookIn = firstLit->getLexicalValue();
		std::string lookFor = secondLit->getLexicalValue();
		return lookIn.compare(0, lookFor.size(), lookFor) ? TTerm::BOOL_false : TTerm::BOOL_true;
	    }

	    const TTerm* FUNC_ends_with (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* firstLit  = dynamic_cast<const RDFLiteral*>(args[0]);
		const RDFLiteral* secondLit = dynamic_cast<const RDFLiteral*>(args[1]);
		checkArgumentCompatibility(firstLit, secondLit, "strEnds");

		std::string lookIn = firstLit->getLexicalValue();
		std::string lookFor = secondLit->getLexicalValue();
		return lookIn.compare(lookIn.size()-lookFor.size(), lookFor.size(), lookFor) ? TTerm::BOOL_false : TTerm::BOOL_true;
	    }

	    std::string utf8_substr (std::string from, int start, int len = -1) {
		// std::cout << utf8::distance(from.begin(), from.end()) << ": " << from << "\n";

		std::string::iterator c = from.begin();
		try {
		    utf8::advance(c, start, from.end());
		} catch (utf8::not_enough_room& e) {
		    c = from.end();
		}
		from.erase(from.begin(), c);
		// std::cout << "trimmed beginning: " << utf8::distance(from.begin(), from.end()) << ": \"" << from << "\"\n";

		c = from.begin();
		if (len > 0) {
		    try {
			utf8::advance(c, len, from.end());
		    } catch (utf8::not_enough_room& e) {
			c = from.end();
		    }
		    from.erase(c, from.end());
		}

		// std::cout << "trimmed end: " << utf8::distance(from.begin(), from.end()) << ": \"" << from << "\"\n";
		return from;
	    }
			
	    const TTerm* FUNC_substring (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* firstLit  = dynamic_cast<const RDFLiteral*>(args[0]);
		if (firstLit == NULL)
		    throw TypeError(args[0]->toString(), "substring");

		const IntegerRDFLiteral* secondInt = dynamic_cast<const IntegerRDFLiteral*>(args[1]);
		if (secondInt == NULL)
		    throw TypeError(args[1]->toString(), "substring");

		int pos = secondInt->getInt() - 1;
		size_t firstLen = args[0]->getLexicalValue().length();
		if (pos < 0)
		    pos = 0;
		else if (size_t(pos) > firstLen)
		    pos = firstLen;
		const URI* dt = firstLit->getDatatype();
		const LANGTAG* langtag = (firstLit->getLangtag() == NULL) ? NULL : new LANGTAG(firstLit->getLangtag()->getLexicalValue());

		if (args.size() == 3) {
		    const IntegerRDFLiteral* thirdInt = dynamic_cast<const IntegerRDFLiteral*>(args[2]);
		    int len = thirdInt->getInt();
		    return atomFactory->getRDFLiteral(utf8_substr(firstLit->getLexicalValue(), pos, len), dt, langtag, false);
		} else {
		    return atomFactory->getRDFLiteral(utf8_substr(firstLit->getLexicalValue(), pos), dt, langtag, false);
		}
	    }

	    const TTerm* FUNC_matches (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* firstLit = dynamic_cast<const RDFLiteral*>(args[0]);
		if (firstLit == NULL || firstLit->getDatatype() != NULL || firstLit->getLangtag() != NULL)
		    throw TypeError(args[0]->toString(), "substring");

		const RDFLiteral* secondLit = dynamic_cast<const RDFLiteral*>(args[1]);
		if (secondLit == NULL || secondLit->getDatatype() != NULL || secondLit->getLangtag() != NULL)
		    throw TypeError(args[1]->toString(), "substring");

#if REGEX_LIB == SWOb_DISABLED
		throw std::string("matches -- no regular expression library was linked in");
#else /* REGEX_LIB != SWOb_DISABLED */
		boost::match_results<std::string::const_iterator> what;
		boost::match_flag_type flags = boost::match_perl;
		unsigned l_flags = boost::regex::no_mod_m | boost::regex::no_mod_s;
		if (args.size() == 3) {
		    const RDFLiteral* thirdLit = dynamic_cast<const RDFLiteral*>(args[2]);
		    if (thirdLit == NULL || thirdLit->getDatatype() != NULL || thirdLit->getLangtag() != NULL)
			throw TypeError(args[2]->toString(), "substring");

		    std::string smix = thirdLit->getLexicalValue();
		    if (smix.find_first_of('s') != std::string::npos)
			l_flags &= ~boost::regex::no_mod_s;
		    if (smix.find_first_of('m') != std::string::npos)
			l_flags &= ~boost::regex::no_mod_m;
		    if (smix.find_first_of('i') != std::string::npos)
			l_flags |= boost::regex::icase;
		    if (smix.find_first_of('x') != std::string::npos)
			l_flags |= boost::regex::mod_x;
		}
		const boost::regex pattern(secondLit->getLexicalValue(), l_flags);
		return regex_search(firstLit->getLexicalValue(), what, pattern, flags) ? TTerm::BOOL_true : TTerm::BOOL_false;
#endif /* REGEX_LIB != SWOb_DISABLED */
	    }

	    std::string newUUID()
	    {
#ifdef WIN32
		UUID uuid;
		UuidCreate ( &uuid );

		unsigned char * str;
		UuidToStringA ( &uuid, &str );

		std::string s( ( char* ) str );

		RpcStringFreeA ( &str );
#else
		uuid_t uuid;
		uuid_generate_random ( uuid );
		char s[37];
		uuid_unparse ( uuid, s );
#endif
		return s;
	    }

	    const TTerm* FUNC_uuid (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		return atomFactory->getURI("urn:uuid:" + newUUID());
	    }
	    
	    const TTerm* FUNC_struuid (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		return atomFactory->getRDFLiteral(newUUID());
	    }
	    

#ifdef CRYPT_LIB
	    std::string hashIntoHex (CryptoPP::HashTransformation &sh, std::string from) {
		CryptoPP::SecByteBlock digest(sh.DigestSize());
		sh.Update((const byte*)from.c_str(), from.size());
		sh.Final(digest);
		std::stringstream ss;
		for (unsigned j=0; j<sh.DigestSize(); j++)
		    ss << std::setw(2) << std::setfill('0') << std::hex << (int)digest[j];
		return ss.str();
	    }

	    const TTerm* FUNC_md5 (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* key  = dynamic_cast<const RDFLiteral*>(args[0]);
		if (key == NULL || key->getDatatype() != NULL || key->getLangtag() != NULL)
		    throw TypeError(args[2]->toString(), "MD5");
		CryptoPP::Weak::MD5 md;
		return atomFactory->getRDFLiteral(hashIntoHex(md, key->getLexicalValue()));
	    }

	    const TTerm* FUNC_sha1 (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* key  = dynamic_cast<const RDFLiteral*>(args[0]);
		if (key == NULL || key->getDatatype() != NULL || key->getLangtag() != NULL)
		    throw TypeError(args[2]->toString(), "SHA1");
		CryptoPP::SHA1 hash;
		return atomFactory->getRDFLiteral(hashIntoHex(hash, key->getLexicalValue()));
	    }
	    const TTerm* FUNC_sha256 (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* key  = dynamic_cast<const RDFLiteral*>(args[0]);
		if (key == NULL || key->getDatatype() != NULL || key->getLangtag() != NULL)
		    throw TypeError(args[2]->toString(), "SHA256");
		CryptoPP::SHA256 hash;
		return atomFactory->getRDFLiteral(hashIntoHex(hash, key->getLexicalValue()));
	    }
	    const TTerm* FUNC_sha512 (const URI* name, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* key  = dynamic_cast<const RDFLiteral*>(args[0]);
		if (key == NULL || key->getDatatype() != NULL || key->getLangtag() != NULL)
		    throw TypeError(args[2]->toString(), "SHA512");
		CryptoPP::SHA512 hash;
		return atomFactory->getRDFLiteral(hashIntoHex(hash, key->getLexicalValue()));
	    }
#endif /* CRYPT_LIB */

	    struct DateTimeDetails {
		int year, month, day, hours, minutes;
		float seconds;
		std::string timezone, tz;
	    };
	    DateTimeDetails parseDateTime (const RDFLiteral* dt) {
		DateTimeDetails ret;
#if REGEX_LIB == SWOb_DISABLED
		throw std::string("parseDateTime -- no regular expression library was linked in");
#else /* REGEX_LIB != SWOb_DISABLED */
		boost::match_results<std::string::const_iterator> what;
		boost::match_flag_type flags = boost::match_default;
		const boost::regex pattern(AtomFactory::datetimePattern);
		if (!regex_search(dt->getLexicalValue(), what, pattern, flags))
		    throw TypeError(dt->getLexicalValue(), "parseDateTime");
#endif /* REGEX_LIB != SWOb_DISABLED */
		ret.year     = boost::lexical_cast<int>(std::string(what[2].first, what[2].second)+std::string(what[3].first, what[3].second));
		ret.month    = boost::lexical_cast<int>(std::string(what[4].first, what[4].second));
		ret.day      = boost::lexical_cast<int>(std::string(what[5].first, what[5].second));
		ret.hours    = boost::lexical_cast<int>(std::string(what[6].first, what[6].second));
		ret.minutes  = boost::lexical_cast<int>(std::string(what[7].first, what[7].second));
		ret.seconds  = boost::lexical_cast<float>(std::string(what[8].first, what[8].second));
		ret.tz       = std::string(what[9].first, what[9].second);
		if (!what[9].matched) {
		    ret.timezone = "!!error";
		} else if (what[10].matched) {
		    ret.timezone = "PT0S";
		} else {
		    ret.timezone += *what[11].first == '-' ? "-" : ""; // sign
		    ret.timezone += "PT";
		    int timezoneHours = boost::lexical_cast<int>(std::string(what[12].first, what[12].second));
		    ret.timezone += boost::lexical_cast<std::string>(timezoneHours);
		    int timezoneMinutes = boost::lexical_cast<int>(std::string(what[13].first, what[13].second));
		    if (timezoneMinutes != 0)
			ret.timezone += "M" + boost::lexical_cast<std::string>(timezoneMinutes);
		    else
			ret.timezone += "H";
		}
		return ret;
	    }

	    const TTerm* FUNC_year_from_dateTime (const URI* /* name */, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* dt = dynamic_cast<const RDFLiteral*>(args[0]);
		if (dt == NULL)
		    throw TypeError(args[0]->toString(), "year");
		return atomFactory->getNumericRDFLiteral(parseDateTime(dt).year);
	    }
	    const TTerm* FUNC_month_from_dateTime (const URI* /* name */, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* dt = dynamic_cast<const RDFLiteral*>(args[0]);
		if (dt == NULL)
		    throw TypeError(args[0]->toString(), "month");
		return atomFactory->getNumericRDFLiteral(parseDateTime(dt).month);
	    }
	    const TTerm* FUNC_day_from_dateTime (const URI* /* name */, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* dt = dynamic_cast<const RDFLiteral*>(args[0]);
		if (dt == NULL)
		    throw TypeError(args[0]->toString(), "day");
		return atomFactory->getNumericRDFLiteral(parseDateTime(dt).day);
	    }
	    const TTerm* FUNC_hours_from_dateTime (const URI* /* name */, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* dt = dynamic_cast<const RDFLiteral*>(args[0]);
		if (dt == NULL)
		    throw TypeError(args[0]->toString(), "hours");
		return atomFactory->getNumericRDFLiteral(parseDateTime(dt).hours);
	    }
	    const TTerm* FUNC_minutes_from_dateTime (const URI* /* name */, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* dt = dynamic_cast<const RDFLiteral*>(args[0]);
		if (dt == NULL)
		    throw TypeError(args[0]->toString(), "minutes");
		return atomFactory->getNumericRDFLiteral(parseDateTime(dt).minutes);
	    }
	    const TTerm* FUNC_seconds_from_dateTime (const URI* /* name */, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* dt = dynamic_cast<const RDFLiteral*>(args[0]);
		if (dt == NULL)
		    throw TypeError(args[0]->toString(), "seconds");
		return atomFactory->getNumericRDFLiteral(parseDateTime(dt).seconds);
	    }
	    const TTerm* FUNC_timezone_from_dateTime (const URI* /* name */, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* dt = dynamic_cast<const RDFLiteral*>(args[0]);
		if (dt == NULL)
		    throw TypeError(args[0]->toString(), "timezone");
		DateTimeDetails ret = parseDateTime(dt);
		if (ret.tz.empty())
		    throw TypeError(args[0]->toString(), "timezone");
		return atomFactory->getRDFLiteral(ret.timezone, atomFactory->getURI(std::string() + NS_xsd + "dayTimeDuration"));
	    }
	    const TTerm* FUNC_tz_from_dateTime (const URI* /* name */, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		const RDFLiteral* dt = dynamic_cast<const RDFLiteral*>(args[0]);
		if (dt == NULL)
		    throw TypeError(args[0]->toString(), "seconds");
		return atomFactory->getRDFLiteral(parseDateTime(dt).tz);
	    }
	    const TTerm* FUNC_now (const URI* /* name */, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		time_t rawtime;
		struct tm t;

		::time(&rawtime);
		::localtime_r(&rawtime, &t);
		char space[40];
		::snprintf(space, sizeof(space)-1, "%04d-%02d-%02dT%02d:%02d:%02d", 
			   1900+t.tm_year, t.tm_mon, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);
		return atomFactory->getRDFLiteral(space, TTerm::URI_xsd_dateTime);
	    }
	    const TTerm* FUNC_rand (const URI* /* name */, std::vector<const TTerm*>& args, AtomFactory* atomFactory, TTerm::String2BNode* /* bnodeMap */, const RdfDB* /* db */) {
		static bool seeded = false;
		static struct drand48_data seed;
		if (!seeded) {
		    struct timeval tv;
		    gettimeofday(&tv, NULL);
		    srand48_r(tv.tv_sec * tv.tv_usec, &seed);
		    seeded = true;
		}
		double d;
		drand48_r(&seed, &d);
		return atomFactory->getNumericRDFLiteral(d);
	    }

	    Map::Initializer List[] = {
		Map::Initializer(TTerm::FUNC_normalize_space, 1, 1, &EXTFUNC_normalize_space),
		Map::Initializer(TTerm::FUNC_lastTail, 4, 4, &EXTFUNC_lastTail),
		Map::Initializer(TTerm::FUNC_newTail, 4, 4, &EXTFUNC_newTail),
		Map::Initializer(TTerm::FUNC_newNil, 4, 4, &EXTFUNC_newNil),
		Map::Initializer(TTerm::FUNC_curTail, 4, 4, &EXTFUNC_curTail),
		Map::Initializer(TTerm::FUNC_newObj, 1, 1, &EXTFUNC_newObj),

		Map::Initializer(TTerm::URI_xsd_float, 1, 1, &numericCast),
		Map::Initializer(TTerm::URI_xsd_double, 1, 1, &numericCast),
		Map::Initializer(TTerm::URI_xsd_decimal, 1, 1, &numericCast),
		Map::Initializer(TTerm::URI_xsd_integer, 1, 1, &numericCast),
		Map::Initializer(TTerm::URI_xsd_boolean, 1, 1, &numericCast),
		Map::Initializer(TTerm::URI_xsd_dateTime, 1, 1, &URI_xsd_dateTime),
		Map::Initializer(TTerm::URI_xsd_string, 1, 1, &URI_xsd_string),
		Map::Initializer(TTerm::FUNC_bound, 1, 1, &FUNC_bound),
		Map::Initializer(TTerm::FUNC_isIRI, 1, 1, &FUNC_isIRI),
		Map::Initializer(TTerm::FUNC_isURI, 1, 1, &FUNC_isIRI),
		Map::Initializer(TTerm::FUNC_isBlank, 1, 1, &FUNC_isBlank),
		Map::Initializer(TTerm::FUNC_isLiteral, 1, 1, &FUNC_isLiteral),
		Map::Initializer(TTerm::FUNC_isNumeric, 1, 1, &FUNC_isNumeric),
		Map::Initializer(TTerm::FUNC_str, 1, 1, &FUNC_str),
		Map::Initializer(TTerm::FUNC_lang, 1, 1, &FUNC_lang),
		Map::Initializer(TTerm::FUNC_iri, 2, 2, &FUNC_iri),
		Map::Initializer(TTerm::FUNC_uri, 2, 2, &FUNC_iri),
		Map::Initializer(TTerm::FUNC_strdt, 2, 2, &FUNC_strdt),
		Map::Initializer(TTerm::FUNC_strlang, 2, 2, &FUNC_strlang),
		Map::Initializer(TTerm::FUNC_bnode, 0, 1, &FUNC_bnode),
		Map::Initializer(TTerm::FUNC_datatype, 1, 1, &FUNC_datatype),
		Map::Initializer(TTerm::FUNC_lower_case, 1, 1, &FUNC_lower_case),
		Map::Initializer(TTerm::FUNC_upper_case, 1, 1, &FUNC_upper_case),
		Map::Initializer(TTerm::FUNC_string_length, 1, 1, &FUNC_string_length),
		Map::Initializer(TTerm::FUNC_encode_for_uri, 1, 1, &FUNC_encode_for_uri),
		Map::Initializer(TTerm::FUNC_concat, 1, 999, &FUNC_concat),
		Map::Initializer(TTerm::FUNC_replace, 3, 3, &FUNC_replace),
		Map::Initializer(TTerm::FUNC_sameTerm, 2, 2, &FUNC_sameTerm),
		Map::Initializer(TTerm::FUNC_langMatches, 2, 2, &FUNC_langMatches),
		Map::Initializer(TTerm::FUNC_numeric_abs, 1, 1, &FUNC_numeric_abs),
		Map::Initializer(TTerm::FUNC_numeric_round, 1, 1, &FUNC_numeric_round),
		Map::Initializer(TTerm::FUNC_numeric_ceil, 1, 1, &FUNC_numeric_ceil),
		Map::Initializer(TTerm::FUNC_numeric_floor, 1, 1, &FUNC_numeric_floor),
		Map::Initializer(TTerm::FUNC_contains, 2, 2, &FUNC_contains),
		Map::Initializer(TTerm::FUNC_substring_before, 2, 2, &FUNC_substring_before),
		Map::Initializer(TTerm::FUNC_substring_after, 2, 2, &FUNC_substring_after),
		Map::Initializer(TTerm::FUNC_uuid, 0, 0, &FUNC_uuid),
		Map::Initializer(TTerm::FUNC_struuid, 0, 0, &FUNC_struuid),
#ifdef CRYPT_LIB
		Map::Initializer(TTerm::FUNC_md5, 1, 1, &FUNC_md5),
		Map::Initializer(TTerm::FUNC_sha1, 1, 1, &FUNC_sha1),
		Map::Initializer(TTerm::FUNC_sha256, 1, 1, &FUNC_sha256),
		Map::Initializer(TTerm::FUNC_sha512, 1, 1, &FUNC_sha512),
#endif /* CRYPT_LIB */
		Map::Initializer(TTerm::FUNC_starts_with, 2, 2, &FUNC_starts_with),
		Map::Initializer(TTerm::FUNC_ends_with, 2, 2, &FUNC_ends_with),
		Map::Initializer(TTerm::FUNC_substring, 2, 3, &FUNC_substring),
		Map::Initializer(TTerm::FUNC_matches, 2, 3, &FUNC_matches),
		Map::Initializer(TTerm::FUNC_year_from_dateTime, 1, 1, &FUNC_year_from_dateTime),
		Map::Initializer(TTerm::FUNC_month_from_dateTime, 1, 1, &FUNC_month_from_dateTime),
		Map::Initializer(TTerm::FUNC_day_from_dateTime, 1, 1, &FUNC_day_from_dateTime),
		Map::Initializer(TTerm::FUNC_hours_from_dateTime, 1, 1, &FUNC_hours_from_dateTime),
		Map::Initializer(TTerm::FUNC_minutes_from_dateTime, 1, 1, &FUNC_minutes_from_dateTime),
		Map::Initializer(TTerm::FUNC_seconds_from_dateTime, 1, 1, &FUNC_seconds_from_dateTime),
		Map::Initializer(TTerm::FUNC_timezone_from_dateTime, 1, 1, &FUNC_timezone_from_dateTime),
		Map::Initializer(TTerm::FUNC_tz, 1, 1, &FUNC_tz_from_dateTime),
		Map::Initializer(TTerm::FUNC_now, 0, 0, &FUNC_now),
		Map::Initializer(TTerm::FUNC_rand, 0, 0, &FUNC_rand)
	    };
	} // namespace BuiltIn

	Map GlobalMap(BuiltIn::List, BuiltIn::List + (sizeof(BuiltIn::List)/sizeof(BuiltIn::List[0])));
    } // namespace AtomicFunction

    /* <AtomFactory> */

	const char* AtomFactory::longPattern =    "^[-+]?[0-9]+$";
	const char* AtomFactory::decimalPattern = "^[+\\-]?[0-9]+(\\.[0-9]+)?$";
	const char* AtomFactory::floatPattern =   "^[+\\-]?[0-9]+(\\.[0-9]+)?([eE][-+]?[0-9]+)?$";
	const char* AtomFactory::datetimePattern = "^("
	      "([\\-+]?)"	// optional sign @@ perhaps not supported by time(2)
	      "(\\d{4,})"	// 2004
	      "-(\\d{2})"	//     -12
	      "-(\\d{2})"	//        -31
	      "T(\\d{2})"	//           T19
	      ":(\\d{2})"	//              :01
	      "(?::(\\d{2}))?"	//                 :00
	      "((Z)|"		//                    Z
	       "(?:([+\\-])"	//                    -
	        "(\\d{2})"	//                     05
	        ":(\\d{2})"	//                       :00
	        "))?" ")$";		// 2004-12-31T19:01:00-05:00

    AtomFactory::AtomFactory () {

#if REGEX_LIB == SWOb_BOOST
	using std::numeric_limits;
  #define _VAL1(T, P) validators.insert(ValidatorElt("http://www.w3.org/2001/XMLSchema#" T, Validator(P)))
  #define _VALL(T, P, L, U) validators.insert(ValidatorElt("http://www.w3.org/2001/XMLSchema#" T, Validator(P, (long)L, (long)U)))
  #define _VALD(T, P, L, U) validators.insert(ValidatorElt("http://www.w3.org/2001/XMLSchema#" T, Validator(P, (long double)L, (long double)U)))
  #define _MIND RANGE_unlimited /* -numeric_limits<long double>::max() */
  #define _MAXD RANGE_unlimited /* numeric_limits<long double>::max() */
  #define _MINL RANGE_unlimited /* numeric_limits<long>::min() */
  #define _MAXL RANGE_unlimited /* numeric_limits<long>::max() */

	_VAL1("integer", 	    longPattern);
	_VAL1("decimal", 	    decimalPattern);
	_VALD("float", 		    floatPattern, _MIND, _MAXD); // -149E16777216, 104E16777216);
	_VALL("double", 	    floatPattern, _MIND, _MAXD); // -1075E2251799813685248, 970E2251799813685248);
	_VAL1("string", 	    ".*");
	_VAL1("boolean", 	    "^(true|false|1|0)$");
	_VAL1("dateTime",	    datetimePattern);		 // 2004-12-31T19:01:00-05:00

	    //derived numerics

	_VAL1("nonPositiveInteger", "^\\+?0+|-[0-9]+$");
	_VALL("negativeInteger",    "^-[0-9]+$", RANGE_unlimited, -1);
	_VALL("long", 		    longPattern, _MINL, _MAXL); // -9223372036854775808, 9223372036854775807);
	_VALL("int", 		    longPattern, _MINL, _MAXL); // -2147483648, 2147483647);
	_VALL("short", 		    longPattern, -32768, 32767);
	_VALL("byte",		    longPattern, -128, 127);
	_VALL("nonNegativeInteger", longPattern, 0, RANGE_unlimited);
	_VALL("unsignedLong", 	    longPattern, 0, _MAXL); // 18446744073709551615);
	_VALL("unsignedInt", 	    longPattern, 0, _MAXL); // 4294967295);
	_VALL("unsignedShort", 	    longPattern, 0, 65535);
	_VALL("unsignedByte", 	    longPattern, 0, 255);
	_VALL("positiveInteger",    longPattern, 1, RANGE_unlimited);

  #undef _VAL1
  #undef _VALL
  #undef _VALD
  #undef _MINL
  #undef _MAXL
  #undef _MIND
  #undef _MAXD
#endif /* REGEX_LIB == SWOb_BOOST */
    }
    AtomFactory::~AtomFactory () {

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

    const Variable* AtomFactory::getVariable (std::string name) {
	std::string key(name);
	VariableMap::const_iterator vi = variables.find(key);
	if (vi == variables.end()) {
	    Variable* ret = new Variable(name);
	    variables[key] = ret;
	    return ret;
	} else
	    return vi->second;
    }

    const BNode* AtomFactory::createBNode () {
	BNode* ret = new BNode();
	std::stringstream name;
	name << ret; // addr
	bnodes.insert(ret);
	return ret;
    }

    /** AtomFactory::getBNode maps a bnode label name to a BNode to that bnodeMap.
     * 
     * Usage: a parser or generator will create a String2BNode which
     * scopes blank node labels to a document. An e.g. parser
     * encountering a labeled blank node will call getBNode and get
     * back a BNode with that label unless that label has already been
     * allocated (to another String2BNode). It it has, an ordinal will
     * be appended, e.g. X_1. More ordinals will be appended if the
     * constructed name is has been allocated. The ordinal is recorded
     * and subsequent calls for a unique BNode with that label will
     * increment the ordinal.
     * 
     * Examples (all assuming a unique String2BNode):
     *   X	    X		First allocation gets preferred label.
     *   X	    X_1		Collision, add ordinal.
     *   X	    X_2		Increment _1 ordinal.
     *   X_3	    X_3		Preferred label (which confounds X_n).
     *   X_3_1	    X_3_1	Preferred label.
     *  *X	    X_3_1_1	X_3 allocated so add ordinals.
     *   X	    X_3_1_2	Increment the _3_1_1 ordinal.
     *   X_3_1	    X_3_1_1_1	...
     *   X_3	    X_3_1_2_1	
     *   X_3_1_2_1  X_3_1_2_1_1	
     * 
     * The 4th X returns instead of X_3_1_1 X_4 as the earlier
     * allocation of X_3 indicates a series, likely eventually
     * allocating X_4, X_5...
     * 
     * Improvements: could reap name allocations when String2BNodes
     * are declared expired.
     */

    const BNode* AtomFactory::getBNode (std::string name, TTerm::String2BNode* bnodeMap) {

	// Comments track the 4th X allocation (marked *X):
	typedef std::pair<std::string, unsigned int> Components_t;	// (X_3_1, 0)
	typedef std::map<std::string, Components_t> UsedBNodeLabel_t;	// (X     -> (X,     2),
									//  X_3_1 -> (X_3_1, 0))
	typedef std::pair<std::string, Components_t> UsedBNodeLabel_p;
	static UsedBNodeLabel_t UsedBNodeLabels;

	std::string key(name);
	TTerm::String2BNode::const_iterator vi = bnodeMap->find(key);
	if (vi == bnodeMap->end()) {
	    UsedBNodeLabel_t::const_iterator e = UsedBNodeLabels.end();
	    UsedBNodeLabel_t::const_iterator test = UsedBNodeLabels.find(name);
	    std::string base = name;
	    std::string lex = name;
	    unsigned int ord = 0;
	    if (test != e) {
		base = test->second.first;	// X
		ord = test->second.second + 1;	// 2
		lex = base + "_" + boost::lexical_cast<std::string>(ord); // X_3
		test = UsedBNodeLabels.find(lex);
		while (test != e) {	// two iterations: 1st   | 2nd
		    base = lex;				// X_3   | X_3_1
		    ord = test->second.second + 1;	// 1     | 1
		    lex = base + "_" + boost::lexical_cast<std::string>(ord);
		    test = UsedBNodeLabels.find(lex);	// X_3_1 | X_3_1_1
		}
	    }
	    UsedBNodeLabels[name] = Components_t(base, ord); // [X]       = (X_3_1, 1)
	    UsedBNodeLabels[lex] = Components_t(lex, 0);     // [X_3_1_1] = (X_3_1_1, 0)

	    BNode* ret = new BNode(lex);
	    bnodeMap->insert(make_pair(key, ret));
	    bnodes.insert(ret);
	    return ret;
	} else
	    return vi->second;
    }

    const URI* AtomFactory::getURI (std::string name) {
	std::string key(name);
	URIMap::const_iterator vi = uris_static.find(key);
	if (vi == uris_static.end()) {
	    vi = uris.find(key);
	    if (vi == uris.end()) {
		URI* ret = new URI(name);
		uris[key] = ret;
		return ret;
	    }
	}
	return vi->second;
    }

    const char* AtomFactory::getOperatorName (const URI* uri) {
	pURI_str::const_iterator vi = operatorNames_static.find(uri);
	return vi == operatorNames_static.end() ? NULL : vi->second;
    }

    std::string AtomFactory::unescapeStr (std::string p_String) {
	std::stringstream ss;
	std::ostreambuf_iterator<char> out(ss);
	bool escaped = false;
	for (std::string::const_iterator it = p_String.begin();
	     it != p_String.end(); ++it)
	    if (escaped) {
		switch (*it) {
		case 'b':  out = '\b'; break;
		case 'f':  out = '\f'; break;
		case 'n':  out = '\n'; break;
		case 'r':  out = '\r'; break;
		case 't':  out = '\t'; break;
		case '\\': out = '\\'; break;
		case  '"': out = '\"'; break;
		default:   out = *it;
		}
		escaped = false;
	    } else if (*it == '\\')
		escaped = true;
	    else
		out = *it;

	return ss.str();
    }

    const TTerm* AtomFactory::getTTerm (std::string posStr, TTerm::String2BNode* bnodeMap) {
	BOOST_LOG_SEV(Logger::DefaultLog::get(), Logger::engineer) << "creating RDF term for \"" << posStr << "\"." << std::endl;
	if (posStr[0] == '<' && posStr[posStr.size()-1] == '>')
	    return getURI(posStr.substr(1, posStr.size()-2));
	if (posStr[0] == '_' && posStr[1] == ':')
	    return getBNode(posStr.substr(2, posStr.size()-2), bnodeMap);
	if (posStr[0] == '"' ||
	    posStr[0] == '\'') {
	    char matchme = posStr[0];
	    if (posStr[posStr.size()-1] == matchme)
		return getRDFLiteral(unescapeStr(posStr.substr(1, posStr.size()-2)), NULL, NULL);
	    size_t i;
	    if (posStr[posStr.size()-1] == '>') {
		for (i = posStr.size()-2; i > 3; --i) // ""^^
		    if (posStr[i] == '<')
			break;
		if (posStr[i] == '<' && posStr[i-1] == '^' && posStr[i-2] == '^' && posStr[i-3] == matchme)
		    return getRDFLiteral(unescapeStr(posStr.substr(1, i-4)),
					 getURI(posStr.substr(i+1, posStr.size()-i-2)), NULL);
	    }
	    for (i = posStr.size()-2; i > 2; --i) // ""@
		if (posStr[i] == '@')
		    break;
	    if (posStr[i] == '@' && posStr[i-1] == matchme)
		return getRDFLiteral(unescapeStr(posStr.substr(1, i-2)), NULL, 
				     new LANGTAG(posStr.substr(i+1)));
	}
	if (posStr[0] == '?')
	    return getVariable(posStr.substr(1, posStr.size()-1));
	if (posStr[0] == '-' || (posStr[0] >= '0' && posStr[0] <= '9')) {
	    std::istringstream is(posStr);
	    int i;
	    is >> i;
	    return getNumericRDFLiteral(posStr, i);
	}
	throw(std::runtime_error("unable to getTTerm("+posStr+")"));
    }

     void AtomFactory::validate (std::string value, std::string datatype) {
#if REGEX_LIB == SWOb_BOOST
	 ValidatorSet::const_iterator it = validators.find(datatype);
	 if (it == validators.end())
	     return;
	 const Validator& v = it->second;
	 boost::match_results<std::string::const_iterator> what;
	 if (!regex_search(value, what, v.pattern, boost::match_default)) {
	     BOOST_LOG_SEV(Logger::GraphMatchLog::get(), Logger::info) << "pattern \"" << v.pattern << "\" failed to match \"" << value << "\"." << std::endl;
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
	 BOOST_LOG_SEV(Logger::GraphMatchLog::get(), Logger::info) << "unable to validate that \"" << value << "\" is a " << datatype << " without boost regular expression" << std::endl;
#endif /* REGEX_LIB != SWOb_BOOST */
    }

    const RDFLiteral* AtomFactory::getRDFLiteral (std::string p_String, const URI* p_URI, const LANGTAG* p_LANGTAG, bool needsValidation) {
	std::istringstream is(p_String);

	if (p_URI != NULL && needsValidation == true)
	    validate(p_String, p_URI->getLexicalValue());
	if (p_URI == TTerm::URI_xsd_integer || 
	    p_URI == TTerm::URI_xsd_nonPositiveInteger || 
	    p_URI == TTerm::URI_xsd_negativeInteger || 
	    p_URI == TTerm::URI_xsd_long || 
	    p_URI == TTerm::URI_xsd_int || 
	    p_URI == TTerm::URI_xsd_short || 
	    p_URI == TTerm::URI_xsd_byte || 
	    p_URI == TTerm::URI_xsd_nonNegativeInteger || 
	    p_URI == TTerm::URI_xsd_unsignedLong || 
	    p_URI == TTerm::URI_xsd_unsignedInt || 
	    p_URI == TTerm::URI_xsd_unsignedShort || 
	    p_URI == TTerm::URI_xsd_unsignedByte || 
	    p_URI == TTerm::URI_xsd_positiveInteger) {
	    int i;
	    is >> i;
// 	    return getNumericRDFLiteral(i);
	    return getNumericRDFLiteral(p_String.c_str(), i);
	} else if (p_URI == TTerm::URI_xsd_decimal || 
		   p_URI == TTerm::URI_xsd_float) {
	    float f;
	    is >> f;
// 	    return p_URI == TTerm::URI_xsd_float ? getNumericRDFLiteral(f, true) : getNumericRDFLiteral(f);
	    return p_URI == TTerm::URI_xsd_float ? 
		getNumericRDFLiteral(p_String.c_str(), f, true) :
		getNumericRDFLiteral(p_String.c_str(), f);
	} else if (p_URI == TTerm::URI_xsd_double) {
	    double d;
	    is >> d;
// 	    return getNumericRDFLiteral(d);
	    return getNumericRDFLiteral(p_String.c_str(), d);
	} else if (p_URI == TTerm::URI_xsd_dateTime) {
	    return getDateTimeRDFLiteral(p_String.c_str());
	} else if (p_URI == TTerm::URI_xsd_boolean) {
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
	RDFLiteralMap::const_iterator vi = rdfLiterals_static.find(key);
	if (vi == rdfLiterals_static.end()) {
	    vi = rdfLiterals.find(key);
	    if (vi == rdfLiterals.end()) {
		RDFLiteral* ret = new RDFLiteral(p_String, p_URI, p_LANGTAG);
		rdfLiterals[key] = ret;
		return ret;
	    }
	}
	delete p_LANGTAG; // will not be used to create an RDFLiteral.
	return vi->second;
    }

#define XSD "http://www.w3.org/2001/XMLSchema#"
#define LEN_XSD sizeof(XSD)

    static std::string canonical (int i) {
	std::stringstream canonical;
	canonical << i;
	return canonical.str();
    }

    const IntegerRDFLiteral* AtomFactory::getNumericRDFLiteral (int p_value) {
	class QuoteIntegerRDFLiteral : public MakeNumericRDFLiteral {
	private:
	    int m_value;
	    std::string m_lexval;
	public: QuoteIntegerRDFLiteral (int p_value, std::string m_lexval)
	    : m_value(p_value), m_lexval(m_lexval)
	    {  }
	    virtual std::string indexIt () const {
		return m_lexval;
	    }
	    virtual const NumericRDFLiteral* makeIt (std::string p_String, const URI* p_URI) const {
		return new IntegerRDFLiteral(p_String, p_URI, m_value);
	    }
	};

	std::string canon = canonical(p_value);
	QuoteIntegerRDFLiteral maker(p_value, canon);
	IntegerRDFLiteral* ret = (IntegerRDFLiteral*)getNumericRDFLiteral(canon, "integer", maker);
	return ret;
    }

    const IntegerRDFLiteral* AtomFactory::getNumericRDFLiteral (std::string p_String, int p_value) {
	class MakeIntegerRDFLiteral : public MakeNumericRDFLiteral {
	private: int m_value;
	public: MakeIntegerRDFLiteral (int p_value) : m_value(p_value) {  }
	    virtual std::string indexIt () const {
		return canonical(m_value);
	    }
	    virtual const NumericRDFLiteral* makeIt (std::string p_String, const URI* p_URI) const {
		return new IntegerRDFLiteral(p_String, p_URI, m_value);
	    }
	};
	MakeIntegerRDFLiteral maker(p_value);
	IntegerRDFLiteral* ret = (IntegerRDFLiteral*)getNumericRDFLiteral(p_String, "integer", maker);
	return ret;
    }

    static std::string canonical (float f) { // decimal notation
	std::stringstream canonical;
	canonical << f;
	if (canonical.str().find_first_of(".") == std::string::npos)
	    canonical << ".0";
	return canonical.str();
    }

    const DecimalRDFLiteral* AtomFactory::getNumericRDFLiteral (float p_value) {
	class QuoteDecimalRDFLiteral : public MakeNumericRDFLiteral {
	private:
	    float m_value;
	    std::string m_lexval;
	public: QuoteDecimalRDFLiteral (float p_value, std::string m_lexval)
	    : m_value(p_value), m_lexval(m_lexval)
	    {  }
	    virtual std::string indexIt () const {
		return m_lexval;
	    }
	    virtual const NumericRDFLiteral* makeIt (std::string p_String, const URI* p_URI) const {
		return new DecimalRDFLiteral(p_String, p_URI, m_value);
	    }
	};

	std::string canon = canonical(p_value);
	QuoteDecimalRDFLiteral maker(p_value, canon);
	DecimalRDFLiteral* ret = (DecimalRDFLiteral*)getNumericRDFLiteral(canon, "decimal", maker);
	return ret;
    }

    const DecimalRDFLiteral* AtomFactory::getNumericRDFLiteral (std::string p_String, float p_value) {
	class MakeDecimalRDFLiteral : public MakeNumericRDFLiteral {
	private: float m_value;
	public: MakeDecimalRDFLiteral (float p_value) : m_value(p_value) {  }
	    virtual std::string indexIt () const {
		return canonical(m_value);
	    }
	    virtual const NumericRDFLiteral* makeIt (std::string p_String, const URI* p_URI) const {
		return new DecimalRDFLiteral(p_String, p_URI, m_value);
	    }
	};
	MakeDecimalRDFLiteral maker(p_value);
	DecimalRDFLiteral* ret = (DecimalRDFLiteral*)getNumericRDFLiteral(p_String, "decimal", maker);
	return ret;
    }

    const FloatRDFLiteral* AtomFactory::getNumericRDFLiteral (float p_value, bool /* floatness */) {
	class QuoteFloatRDFLiteral : public MakeNumericRDFLiteral {
	private:
	    float m_value;
	    std::string m_lexval;
	public: QuoteFloatRDFLiteral (float p_value, std::string m_lexval)
	    : m_value(p_value), m_lexval(m_lexval)
	    {  }
	    virtual std::string indexIt () const {
		return m_lexval;
	    }
	    virtual const NumericRDFLiteral* makeIt (std::string p_String, const URI* p_URI) const {
		return new FloatRDFLiteral(p_String, p_URI, m_value);
	    }
	};

	std::string canon = canonical(p_value);
	QuoteFloatRDFLiteral maker(p_value, canon);
	FloatRDFLiteral* ret = (FloatRDFLiteral*)getNumericRDFLiteral(canon, "float", maker);
	return ret;
    }

    const FloatRDFLiteral* AtomFactory::getNumericRDFLiteral (std::string p_String, float p_value, bool /* floatness */) {
	class MakeFloatRDFLiteral : public MakeNumericRDFLiteral {
	private: float m_value;
	public: MakeFloatRDFLiteral (float p_value) : m_value(p_value) {  }
	    virtual std::string indexIt () const {
		return canonical(m_value);
	    }
	    virtual const NumericRDFLiteral* makeIt (std::string p_String, const URI* p_URI) const {
		return new FloatRDFLiteral(p_String, p_URI, m_value);
	    }
	};
	MakeFloatRDFLiteral maker(p_value);
	FloatRDFLiteral* ret = (FloatRDFLiteral*)getNumericRDFLiteral(p_String, "float", maker);
	return ret;
    }

    static std::string canonical (double d) {
	std::stringstream canonical;
	int ex = ::log10(d);
	if (d < 1)
	    --ex;
	double logOf10 = ::log(10);
	canonical << d/::exp(ex*logOf10);
	if (canonical.str().find('.') == std::string::npos)
	    canonical << ".0";
	canonical << "E" << ex;
	return canonical.str();
    }

    const DoubleRDFLiteral* AtomFactory::getNumericRDFLiteral (double p_value) {
	class QuoteDoubleRDFLiteral : public MakeNumericRDFLiteral {
	private:
	    double m_value;
	    std::string m_lexval;
	public: QuoteDoubleRDFLiteral (double p_value, std::string m_lexval)
	    : m_value(p_value), m_lexval(m_lexval)
	    {  }
	    virtual std::string indexIt () const {
		return m_lexval;
	    }
	    virtual const NumericRDFLiteral* makeIt (std::string p_String, const URI* p_URI) const {
		return new DoubleRDFLiteral(p_String, p_URI, m_value);
	    }
	};

	std::string canon = canonical(p_value);
	QuoteDoubleRDFLiteral maker(p_value, canon);
	DoubleRDFLiteral* ret = (DoubleRDFLiteral*)getNumericRDFLiteral(canon, "double", maker);
	return ret;
    }

    const DoubleRDFLiteral* AtomFactory::getNumericRDFLiteral (std::string p_String, double p_value) {
	class MakeDoubleRDFLiteral : public MakeNumericRDFLiteral {
	private: double m_value;
	public: MakeDoubleRDFLiteral (double p_value) : m_value(p_value) {  }
	    virtual std::string indexIt () const {
		return canonical(m_value);
	    }
	    virtual const NumericRDFLiteral* makeIt (std::string p_String, const URI* p_URI) const {
		return new DoubleRDFLiteral(p_String, p_URI, m_value);
	    }
	};
	MakeDoubleRDFLiteral maker(p_value);
	DoubleRDFLiteral* ret = (DoubleRDFLiteral*)getNumericRDFLiteral(p_String, "double", maker);
	return ret;
    }

    const DateTimeRDFLiteral* AtomFactory::getDateTimeRDFLiteral (std::string p_String) {
	std::stringstream buf;
	buf << "\"" << p_String << "\"^^<http://www.w3.org/2001/XMLSchema#dateTime>";
	std::string key(buf.str());
	RDFLiteralMap::const_iterator vi = rdfLiterals_static.find(key);
	if (vi == rdfLiterals_static.end()) {
	    vi = rdfLiterals.find(key);
	    if (vi == rdfLiterals.end()) {
		DateTimeRDFLiteral* ret = new DateTimeRDFLiteral(p_String, TTerm::URI_xsd_dateTime);
		rdfLiterals[key] = ret;
		return ret;
	    }
	}
	return (DateTimeRDFLiteral*)vi->second; // shameful downcast
    }

    const BooleanRDFLiteral* AtomFactory::getBooleanRDFLiteral (bool p_value) {
	std::stringstream buf;
	buf << "\"" << (p_value ? "true" : "false") << "\"^^<http://www.w3.org/2001/XMLSchema#boolean>";
	std::string key(buf.str());
	RDFLiteralMap::const_iterator vi = rdfLiterals_static.find(key);
	if (vi == rdfLiterals_static.end()) {
	    vi = rdfLiterals.find(key);
	    if (vi == rdfLiterals.end()) {
		BooleanRDFLiteral* ret = new BooleanRDFLiteral(buf.str(), TTerm::URI_xsd_boolean, p_value);
		rdfLiterals[key] = ret;
		return ret;
	    }
	}
	return (BooleanRDFLiteral*)vi->second; // shameful downcast
    }

    const BooleanRDFLiteral* AtomFactory::getBooleanRDFLiteral (std::string p_String, bool p_value) {
	std::stringstream buf;
	buf << "\"" << (p_value ? "true" : "false") << "\"^^<http://www.w3.org/2001/XMLSchema#boolean>";
	std::string key(buf.str());
	RDFLiteralMap::const_iterator vi = rdfLiterals_static.find(key);
	if (vi == rdfLiterals_static.end()) {
	    vi = rdfLiterals.find(key);
	    if (vi == rdfLiterals.end()) {
		BooleanRDFLiteral* ret = new BooleanRDFLiteral(p_String, TTerm::URI_xsd_boolean, p_value);
		rdfLiterals[key] = ret;
		return ret;
	    }
	}
	return (BooleanRDFLiteral*)vi->second; // shameful downcast
    }

    const NumericRDFLiteral* AtomFactory::getNumericRDFLiteral (std::string p_String, const char* type, const MakeNumericRDFLiteral& maker) {

	std::string uriStr(XSD);
	uriStr += type;
	const URI* uri = getURI(uriStr);

	// First look for the lexical value as given.
	std::string key = std::string() + '"' + p_String + '"' + "^^<" + uriStr + ">";
	RDFLiteralMap::const_iterator vi = rdfLiterals_static.find(key);
	if (vi == rdfLiterals_static.end()) {
	    vi = rdfLiterals.find(key);
	    if (vi == rdfLiterals.end()) {

		if (CanonicalRDFLiteral::format == CanonicalRDFLiteral::CANON_roundTrip) {
		    // Run expensive maker->indexIt() only when necessary.
		    // Presumes that hash lookups are < half as expensive as indexIt().
		    key = std::string() + '"' + maker.indexIt() + '"' + "^^<" + uriStr + ">";
		    vi = rdfLiterals_static.find(key);
		    if (vi == rdfLiterals_static.end()) {
			vi = rdfLiterals.find(key);
			if (vi == rdfLiterals.end()) {

			    // Create a new numeric object.
			    const NumericRDFLiteral* ret = maker.makeIt(p_String, uri);
			    rdfLiterals[key] = ret;
			    return ret;
			}
		    }
		} else {
			    const NumericRDFLiteral* ret = maker.makeIt(p_String, uri);
			    rdfLiterals[key] = ret;
			    return ret;
		}
	    }
	}
	return (const NumericRDFLiteral*)vi->second; // shameful downcast
    }

    const TriplePattern* AtomFactory::getTriple (const TTerm* s, const TTerm* p, const TTerm* o, bool weaklyBound) {
	if (s == NULL || s == TTerm::Unbound || 
	    p == NULL || p == TTerm::Unbound || 
	    o == NULL || o == TTerm::Unbound)
	    throw
		std::string("getTriple(")
		+ (s == NULL ? "NULLptr" : s->toString()) + ", " 
		+ (p == NULL ? "NULLptr" : p->toString()) + ", " 
		+ (o == NULL ? "NULLptr" : o->toString()) + ")";

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
    /** parseNTPatterns - parse forms like   _:a \<p2\> 's2' .\n
     */
    void AtomFactory::parseNTPatterns (BasicGraphPattern* g, std::string spo, TTerm::String2BNode* bnodeMap) {
	TTerm::String2BNode localMap;
	if (bnodeMap == NULL)
	    bnodeMap = &localMap; // All names are lost at the end of a parse.

	const boost::regex expression("\\G(?:"	// anchor at start
				      "[ \\t]*#([^\n]+)\n?"	// Comment
				      "|"			// or Triple
				      "[ \\t]*((?:<[^>]*>)|(?:_:[^ \\t]+)|(?:[?$][^ \\t]+)|(?:\"[^\"]+\")|(?:'[^']+'))"	// S
				      "[ \\t]*((?:<[^>]*>)|(?:_:[^ \\t]+)|(?:[?$][^ \\t]+)|(?:\"[^\"]+\")|(?:'[^']+'))"	// P
				      "[ \\t]*((?:<[^>]*>)|(?:_:[^ \\t]+)|(?:[?$][^ \\t]+)|(?:\"[^\"]+\")|(?:'[^']+'))"	// O
				      "[ \\t]*\\.[ \\t]*\\n?"								// EOL
				      "|"			// or Empty line
				      "\n"
				      "|"			// or Junk
				      "([^\n]+)\n?"
				      ")");
	std::string::const_iterator start, end; 
	start = spo.begin(); 
	end = spo.end(); 
	boost::match_results<std::string::const_iterator> what;
	boost::match_flag_type flags = boost::match_default;
	while (regex_search(start, end, what, expression, flags)) {
	    if (what[5].first != what[5].second)
		throw std::string("unparsable input: ") + std::string(what[5].first, what[5].second);
	    else if (what[1].first != what[1].second)
		; // std::cerr << "comment(" << std::string(what[1].first, what[1].second) << ")\n";
	    else if (*what[0].first != '\n')
		g->addTriplePattern(getTriple(getTTerm(std::string(what[2].first, what[2].second), bnodeMap), 
					      getTTerm(std::string(what[3].first, what[3].second), bnodeMap), 
					      getTTerm(std::string(what[4].first, what[4].second), bnodeMap), false));
	    start = what[0].second; 
	    // update flags: 
	    flags |= boost::match_prev_avail; 
	    flags |= boost::match_not_bob; 
	}
    }
#endif /* REGEX_LIB == SWOb_BOOST */

    /** applyCommonNumeric for unary functions*/
    const TTerm* AtomFactory::applyCommonNumeric (const Expression* arg, UnaryFunctor* func, const RdfDB* db) {
	const TTerm* v = arg->eval(func->res, this, func->evaluator, func->bnodeMap, db);
	return applyCommonNumeric(v, func);
    }

    /** applyCommonNumeric for unary functions*/
    const TTerm* AtomFactory::applyCommonNumeric (const TTerm* v, UnaryFunctor* func) {
	if (v == TTerm::Unbound)
	    throw TypeError("no value returned from argument evaluation", "AtomFactory::applyCommonNumeric");
	TTerm::e_TYPE dt = v->getTypeOrder();
	if (dt == TTerm::TYPE_Err)
	    throw std::string(typeid(*v).name()) + " is not a known datatype.";
	switch (dt) {
	case TTerm::TYPE_Integer: {
	    int i = func->eval(static_cast<const NumericRDFLiteral*>(v)->getInt());
	    v = getNumericRDFLiteral(i);
	    break;
	}
	case TTerm::TYPE_Float:
	case TTerm::TYPE_Decimal: {
	    float f = func->eval(static_cast<const NumericRDFLiteral*>(v)->getFloat());
	    v = dt == TTerm::TYPE_Float ? getNumericRDFLiteral(f, true) : getNumericRDFLiteral(f);
	    break;
	}
	case TTerm::TYPE_Double: {
	    double d = func->eval(static_cast<const NumericRDFLiteral*>(v)->getDouble());
	    v = getNumericRDFLiteral(d);
	    break;
	}
	default:
	    throw std::string(typeid(*v).name()) + " is not a numeric datatype: " + v->toString();
	}
	return v;
    }

    /** applyCommonNumeric for nary functions*/
    const TTerm* AtomFactory::applyCommonNumeric (std::vector<const Expression*> args, NaryFunctor* func, const RdfDB* db) {
	std::vector<const Expression*>::const_iterator it = args.begin();
	const TTerm* l = (*it)->eval(func->res, this, func->evaluator, func->bnodeMap, db);
	const NumericRDFLiteral* lnum = dynamic_cast<const NumericRDFLiteral*>(l);
	if (lnum == NULL)
	    throw TypeError(l->toString(), "integer operation");

	TTerm::e_TYPE dt = l->getTypeOrder();
	if (dt == TTerm::TYPE_Err)
	    throw TypeError(l->toString(), "numeric datatype");
	++it;
	while (it != args.end()) {
	    const TTerm* r = (*it)->eval(func->res, this, func->evaluator, func->bnodeMap, db);
	    TTerm::e_TYPE dtr = r->getTypeOrder();
	    if (dtr == TTerm::TYPE_Err)
		throw TypeError(r->toString(), "numeric datatype");
	    if (dtr > dt)
		dt = dtr;
	    switch (dt) {
	    case TTerm::TYPE_Integer: {
		const NumericRDFLiteral* rnum = dynamic_cast<const NumericRDFLiteral*>(r);
		if (rnum == NULL)
		    throw TypeError(r->toString(), "integer operation");
		try {
		    int i = func->eval(lnum->getInt(), rnum->getInt());
		    lnum = getNumericRDFLiteral(i);
		} catch (float f) {
		    /* NaryDivide(int, int) throws a float to support this operator mapping:
		       A / B op:numeric-divide(A, B) numeric; but xsd:decimal if both operands are xsd:integer
		       Is this a hack or brilliant extreme programming?
		     */
		    lnum = getNumericRDFLiteral(f);
		}
		break;
	    }
	    case TTerm::TYPE_Float:
	    case TTerm::TYPE_Decimal: {
		const NumericRDFLiteral* rnum = dynamic_cast<const NumericRDFLiteral*>(r);
		if (rnum == NULL)
		    throw TypeError(r->toString(), "float operation");
		float f = func->eval(lnum->getFloat(), rnum->getFloat());
		lnum = dt == TTerm::TYPE_Float ? getNumericRDFLiteral(f, true) : getNumericRDFLiteral(f);
		break;
	    }
	    case TTerm::TYPE_Double: {
		const NumericRDFLiteral* rnum = dynamic_cast<const NumericRDFLiteral*>(r);
		if (rnum == NULL)
		    throw TypeError(r->toString(), "double operation");
		double res = func->eval(lnum->getDouble(), rnum->getDouble());
		lnum = getNumericRDFLiteral(res);
		break;
	    }
	    default:
		throw TypeError(r->toString(), "numeric datatype");
	    }
	    ++it;
	}
	return lnum;
    }

    /* EBV (Better place for this?) */
    const TTerm* AtomFactory::ebv (const TTerm* tterm) {
	const BooleanRDFLiteral* b = dynamic_cast<const BooleanRDFLiteral*>(tterm);
	if (b != NULL)
	    return b->getValue() ? TTerm::BOOL_true : TTerm::BOOL_false;
	const IntegerRDFLiteral* i = dynamic_cast<const IntegerRDFLiteral*>(tterm);
	if (i != NULL)
	    return i->getValue() == 0 ? TTerm::BOOL_false : TTerm::BOOL_true;
	const DecimalRDFLiteral* f = dynamic_cast<const DecimalRDFLiteral*>(tterm);
	if (f != NULL)
	    return f->getValue() == 0.0 ? TTerm::BOOL_false : TTerm::BOOL_true;
	const FloatRDFLiteral* fl = dynamic_cast<const FloatRDFLiteral*>(tterm);
	if (fl != NULL)
	    return fl->getValue() == 0.0 ? TTerm::BOOL_false : TTerm::BOOL_true;
	const DoubleRDFLiteral* d = dynamic_cast<const DoubleRDFLiteral*>(tterm);
	if (d != NULL)
	    return d->getValue() == 0.0 ? TTerm::BOOL_false : TTerm::BOOL_true;
	const RDFLiteral* l = dynamic_cast<const RDFLiteral*>(tterm);
	const URI* dt = l == NULL ? NULL : l->getDatatype();
	if (l != NULL && 
	    (dt == NULL || dt == TTerm::URI_xsd_string))
	    return std::string(l->getLexicalValue()).empty() ? TTerm::BOOL_false : TTerm::BOOL_true;
	throw TypeError("beats me", "EBV");
    }

    /* </AtomFactory> */

    std::string TTerm::String2BNode::str () const { // for easy invocation
	std::string ret;
	for (const_iterator it = begin(); it != end(); ++it) {
	    if (it != begin())
		ret += ", ";
	    ret += it->first + "->" + it->second->toString();
	}
	return ret;
    }
    std::string TTerm::str () const { return toString(); } // for easy invocation

    const TTerm* BNode::evalTTerm (const Result* r, BNodeEvaluator* evaluator) const {
	return evaluator->evaluate(this, r);
    }
    const TTerm* Variable::evalTTerm (const Result* r, BNodeEvaluator*) const {
	const TTerm* ret = r->get(this);
	return ret == NULL ? TTerm::Unbound : ret;
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

    ResultSet* OperationSet::execute (RdfDB* db, ResultSet* rs) const {
	if (!rs) rs = new ResultSet(rs->getAtomFactory());
	for (std::vector<const Operation*>::const_iterator it = operations.begin();
	     it != operations.end(); ++it)
	    (*it)->execute(db, rs);
	return rs;
    }

    void LoadingOperation::load (RdfDB* db) const {
	for (std::vector<const DatasetClause*>::const_iterator ds = m_DatasetClauses->begin();
	     ds != m_DatasetClauses->end(); ds++)
	    (*ds)->loadData(db);
    }

    ResultSet* Select::executeQuery (const RdfDB* db, ResultSet* rs) const {
	if (!rs) rs = new ResultSet(rs->getAtomFactory());
	m_WhereClause->bindVariables(db, rs);
	if (m_SolutionModifier != NULL) {
	    m_VarSet->project(rs, m_SolutionModifier->groupBy, m_SolutionModifier->having,
			      m_SolutionModifier->m_OrderConditions, db);
	} else
	    m_VarSet->project(rs, NULL, NULL, NULL, db);
	if (m_SolutionModifier == NULL)
	    rs->trim(m_distinctness, -1, -1);
	else
	    rs->trim(m_distinctness, m_SolutionModifier->m_limit, m_SolutionModifier->m_offset);
	rs->resultType = ResultSet::RESULT_Tabular;
	return rs;
    }

    ResultSet* Construct::executeQuery (const RdfDB* db, ResultSet* rs) const {
	if (!rs) rs = new ResultSet(rs->getAtomFactory());
	m_WhereClause->bindVariables(db, rs);
	MakeNewBNode makeNewBNode(rs->getAtomFactory());
	rs->resultType = ResultSet::RESULT_Graphs;
	RdfDB* workingDB = rs->getRdfDB();
	m_ConstructTemplate->construct(workingDB, rs, &makeNewBNode, workingDB->ensureGraph(DefaultGraph));
	//w3c_sw_LINEN << "CONSTRUCTED: " << g << std::endl;
	return rs;
    }

    ResultSet* Describe::executeQuery (const RdfDB* db, ResultSet* rs) const {
	if (!rs) rs = new ResultSet(rs->getAtomFactory());
	m_WhereClause->bindVariables(db, rs);
	MakeNewBNode makeNewBNode(rs->getAtomFactory());
	rs->resultType = ResultSet::RESULT_Graphs;
	const RdfDB* workingDB = rs->getRdfDB();
	// @@ do a CBD
	//w3c_sw_LINEN << "CONSTRUCTED description: " << g << std::endl;
	return rs;
    }

    ResultSet* Ask::executeQuery (const RdfDB* db, ResultSet* rs) const {
	if (!rs) rs = new ResultSet(rs->getAtomFactory());
	m_WhereClause->bindVariables(db, rs);
	if (m_SolutionModifier != NULL) {
	    ExpressionAliasList vs;
	    vs.project(rs, m_SolutionModifier->groupBy, m_SolutionModifier->having,
			      m_SolutionModifier->m_OrderConditions, db);
	    rs->trim(DIST_reduced, m_SolutionModifier->m_limit, m_SolutionModifier->m_offset);
	}
	rs->resultType = ResultSet::RESULT_Boolean;
	return rs;
    }

    ResultSet* Modify::execute (RdfDB* db, ResultSet* rs) const {
	if (!rs) rs = new ResultSet(rs->getAtomFactory());
	if (m_WhereClause != NULL)
	    m_WhereClause->bindVariables(db, rs);
	rs->resultType = ResultSet::RESULT_Graphs;
	if (m_delete != NULL)
	    m_delete->execute(db, rs);
	if (m_insert != NULL)
	    m_insert->execute(db, rs);
	return rs;
    }

    void Modify::update (RdfDB* db, ResultSet* rs) const {
	if (m_delete != NULL)
	    m_delete->execute(db, rs);
	if (m_insert != NULL)
	    m_insert->execute(db, rs);
    }

    ResultSet* Insert::execute (RdfDB* db, ResultSet* rs) const {
	if (!rs) rs = new ResultSet(rs->getAtomFactory());
	if (m_WhereClause != NULL)
	    m_WhereClause->bindVariables(db, rs); // set rs->resultType = ResultSet::RESULT_Tabular\np rs->toString()
	MakeNewBNode makeNewBNode(rs->getAtomFactory());
	rs->resultType = ResultSet::RESULT_Graphs;
	m_GraphTemplate->construct(rs->getRdfDB() ? rs->getRdfDB() : db, rs, &makeNewBNode, NULL);
	return rs;
    }

    ResultSet* Delete::execute (RdfDB* db, ResultSet* rs) const {
	if (!rs) {
	    rs = new ResultSet(rs->getAtomFactory());
	    *rs->getRdfDB() = *db;
	}
	if (m_WhereClause != NULL)
	    m_WhereClause->bindVariables(db, rs);
	TreatAsVar treatAsVar;
	rs->resultType = ResultSet::RESULT_Graphs;
	m_GraphTemplate->deletePattern(rs->getRdfDB() ? rs->getRdfDB() : db, rs, &treatAsVar, NULL);
	return rs;
    }

    const TTerm* FunctionCall::eval (const Result* r, AtomFactory* atomFactory, BNodeEvaluator*  evaluator, TTerm::String2BNode* bnodeMap, const RdfDB*  db) const {

	// IF only evaluates the test and either arg2 or arg3 so it must be
	// evaluated before the subd substitutions.
	if (m_IRIref == TTerm::FUNC_if && m_ArgList->size() == 3) {
	    ArgList::ArgIterator it = m_ArgList->begin();
	    const TTerm* iff = (*it)->eval(r, atomFactory, evaluator, bnodeMap, db);
	    ++it; // now pointed at THEN. ELSE is next.
	    return atomFactory->ebv(iff) == TTerm::BOOL_true ?
		(*it)->eval(r, atomFactory, evaluator, bnodeMap, db) :
		(*++it)->eval(r, atomFactory, evaluator, bnodeMap, db);
	}

	// COALESCE evaluates arguments until the first bound non-error.
	if (m_IRIref == TTerm::FUNC_coalesce) {
	    for (ArgList::ArgIterator it = m_ArgList->begin(); it != m_ArgList->end();) {
		try {
		    const TTerm* ret = (*it)->eval(r, atomFactory, evaluator, bnodeMap, db);
		    if (ret != TTerm::Unbound)
			return ret;
		    ++it;
		} catch (SafeEvaluationError& e) {
		    ++it;
		    // re-throw any exception on the last argument.
		    if (it == m_ArgList->end())
			throw e;
		}
	    }
	}

	// Other than IF and COALESCE, all functions evaluate all arguments.
	// Place the evaluation results in args and pass to the function map.
	std::vector<const TTerm*> args;
	for (ArgList::ArgIterator it = m_ArgList->begin(); it != m_ArgList->end(); ++it)
	    args.push_back((*it)->eval(r, atomFactory, evaluator, bnodeMap, db));
	return AtomicFunction::GlobalMap.invoke(m_IRIref, args, atomFactory, bnodeMap, db);
    }

    const TTerm* AggregateCall::eval (const Result* r, AtomFactory* atomFactory, BNodeEvaluator*  /* evaluator */, TTerm::String2BNode* /* bnodeMap */, const RdfDB*  /* db */) const {
	SPARQLSerializer ss;
	express(&ss);
	return r->get(atomFactory->getRDFLiteral(ss.str()));
    }

    std::string Expression::toString (MediaType mediaType, NamespaceMap* namespaces) const {
	SPARQLSerializer s(mediaType, namespaces, "  ", SPARQLSerializer::DEBUG_none, "");
	express(&s);
	return s.str();
    }
    std::string Expression::str () const { return toString(); } // for easy invocation

    const TTerm* ExistsExpression::eval (const Result* r, AtomFactory* atomFactory, BNodeEvaluator*  /* evaluator */, TTerm::String2BNode* /* bnodeMap */, const RdfDB*  db) const {
	ResultSet* rowRS = r->makeResultSet(atomFactory);
	m_TableOperation->bindVariables(db, rowRS);
	const TTerm* ret = rowRS->size() == 0 ? TTerm::BOOL_false : TTerm::BOOL_true;
	delete rowRS;
	return ret;
    }

    void DatasetClause::loadGraph (RdfDB* db, const TTerm* name, BasicGraphPattern* target) const {
	std::string nameStr = name->getLexicalValue();
	IStreamContext iptr(nameStr, IStreamContext::NONE, NULL, db->webAgent);
	if (db->loadData(target, iptr, nameStr, nameStr, m_atomFactory))
	    throw nameStr + ":0: error: unable to parse web document";
    }
    void DefaultGraphClause::loadData (RdfDB* db) const {
	loadGraph(db, m_IRIref, db->ensureGraph(DefaultGraph));
    }
    void NamedGraphClause::loadData (RdfDB* db) const {
	loadGraph(db, m_IRIref, db->ensureGraph(m_IRIref));
    }

    BindingClause::BindingClause () : m_ResultSet(new ResultSet(NULL)) { // ResultSet will never create new atoms so it needs no AtomFactory
	// ResultSets in BindingClauses don't need to start with one empty row.
	ResultSet* rs = const_cast<ResultSet*>(m_ResultSet);
	rs->erase(rs->begin());
    }
    BindingClause::BindingClause (ResultSet* p_ResultSet) : m_ResultSet(p_ResultSet) {  }
    BindingClause::~BindingClause () {
	ResultSet* rs = const_cast<ResultSet*>(m_ResultSet);
	delete rs;
    }

    void WhereClause::bindVariables (const RdfDB* db, ResultSet* rs) const {
	m_GroupGraphPattern->bindVariables(db, rs);
    }

    void ExpressionAliasList::project (ResultSet* rs, ExpressionAliasList* groupBy, ProductionVector<const w3c_sw::Expression*>* having,
				       std::vector<s_OrderConditionPair>* orderConditions, const RdfDB* db) const {
	rs->project(&m_Expressions, groupBy, having, orderConditions, db);
    }

    void StarVarSet::project (ResultSet* /* rs */, ExpressionAliasList* /* groupBy */, ProductionVector<const w3c_sw::Expression*>* /* having */,
			      std::vector<s_OrderConditionPair>* /* orderConditions */, const RdfDB* /* db */) const {
    }

    void BindingClause::bindVariables (const RdfDB* db, ResultSet* rs) const {
	rs->joinIn(m_ResultSet);
	BOOST_LOG_SEV(Logger::GraphMatchLog::get(), Logger::engineer) << "BINDINGS produced\n" << *rs;
    }

    //@delme !!
    // void Binding::bindVariables (const RdfDB*, ResultSet* rs, Result* r, TTermList* p_Vars) const {
    // 	std::vector<const TTerm*>::const_iterator variable = p_Vars->begin();
    // 	std::vector<const TTerm*>::const_iterator value = begin();
    // 	while (value != end()) {
    // 	    if (variable == p_Vars->end())
    // 		throw std::string("binding ") + (*value)->toString() + " has no slot in the binding set";
    // 	    if (*value != TTerm::Unbound)
    // 		rs->set(r, *variable, *value, false);
    // 	    variable++;
    // 	    value++;
    // 	}
    // }

    void Print::bindVariables (const RdfDB* db, ResultSet* rs) const {
	SPARQLSerializer ss(NULL); // doesn't need to create new atoms.
	m_TableOperation->express(&ss);
	std::stringstream str;
	str << "Executing " << ss.str() << "on\n" << *rs;
	m_TableOperation->bindVariables(db, rs);
	str << "yielded\n" << *rs;
	std::cout << str.str();
    }

    void Filter::bindVariables (const RdfDB* db, ResultSet* rs) const {
	ResultSet island(rs->getAtomFactory());
	m_TableOperation->bindVariables(db, &island);
	for (std::vector<const Expression*>::const_iterator it = m_Expressions.begin();
	     it != m_Expressions.end(); it++)
	    island.restrictResults(*it, db);
	rs->joinIn(&island);
	BOOST_LOG_SEV(Logger::GraphMatchLog::get(), Logger::engineer) << "FILTER produced\n" << *rs;
    }

    void TableConjunction::bindVariables (const RdfDB* db, ResultSet* rs) const {
	ResultSet island(rs->getAtomFactory());
	for (std::vector<const TableOperation*>::const_iterator it = m_TableOperations.begin();
	     it != m_TableOperations.end() && rs->size() > 0; it++)
	    (*it)->bindVariables(db, &island);
	rs->joinIn(&island);
	BOOST_LOG_SEV(Logger::GraphMatchLog::get(), Logger::engineer) << "Conjunction produced\n" << *rs;
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

    void TableDisjunction::bindVariables (const RdfDB* db, ResultSet* rs) const {
	ResultSet island(rs->getAtomFactory());
	delete *(island.begin());
	island.erase(island.begin());
	for (std::vector<const TableOperation*>::const_iterator it = m_TableOperations.begin();
	     it != m_TableOperations.end(); it++) {
	    ResultSet disjoint(*rs);
	    (*it)->bindVariables(db, &disjoint);
#if 0
	    for (std::vector<const Filter*>::const_iterator it = m_Filters.begin();
		 it != m_Filters.end(); it++)
		disjoint.restrictResults(*it);
#endif
	    for (ResultSetIterator row = disjoint.begin() ; row != disjoint.end(); ) {
		island.insert(island.end(), (*row)->duplicate(&island, island.end()));
		delete *row;
		row = disjoint.erase(row);
	    }
	}
	rs->joinIn(&island);
	BOOST_LOG_SEV(Logger::GraphMatchLog::get(), Logger::engineer) << "UNION produced\n" << *rs;
    }

    void SubSelect::bindVariables (const RdfDB* db, ResultSet* rs) const {
	ResultSet island(rs->getAtomFactory());
	// Bypass LoadingOperation::execute so ignores any DatasetClauses.
	// (Such clauses are prohibted in the SPARQL grammar anyways.)
	m_Select->executeQuery(db, &island);
	rs->joinIn(&island);
    }

    /* wrapper function pushed into .cpp because RdfDB is incomplete. */
    void BasicGraphPattern::_bindVariables (const RdfDB* db, ResultSet* rs, const TTerm* p_name) const {
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
	ResultSet island(rs->getAtomFactory());
	db->bindVariables(&island, p_name, this);
	for (std::vector<const Filter*>::const_iterator it = m_Filters.begin();
	     it != m_Filters.end(); it++)
	    island.restrictResults(*it);
	rs->joinIn(&island, false);

	*/
    }

    CanonicalRDFLiteral::e_CANON CanonicalRDFLiteral::format = CANON_brief;
    std::ostream* BasicGraphPattern::DiffStream = NULL;
    bool (*BasicGraphPattern::MappableTerm)(const TTerm*) = &BasicGraphPattern::MapVarsAndBNodes;
    ServiceGraphPattern::e_HTTP_METHOD ServiceGraphPattern::defaultHTTPmethod = ServiceGraphPattern::HTTP_METHOD_GET;
    size_t ServiceGraphPattern::defaultFederationRowLimit = 1000; // don't try to federation more than 1000 rows.
    bool ServiceGraphPattern::useFilters = false;

    bool BasicGraphPattern::onto (const BasicGraphPattern& ref) const {
	ResultSet rs(NULL);
	bindVariables(&rs, &ref);
	// std::cerr << "rs: \n" << rs;
	// make sure there is at least one solution which is 1:1 for mappables.
	for (ResultSetIterator row = rs.begin(); row != rs.end(); ++row) {
	    std::set<const TTerm*> seen;
	    // std::cerr << "checking " << **row << "\n";
	    bool onto = true;
	    for (BindingSetConstIterator b = (*row)->begin(); b != (*row)->end(); ++b) {
		// std::cerr << "have we seen " << b->second.tterm->toString() << "?\n";
		if (seen.find(b->second.tterm) != seen.end()) {
		    // std::cerr << b->second.tterm->toString() << " already seen\n";
		    onto = false;
		    break;
		    // return false; // break and see if next row is 1:1?
		}
		seen.insert(b->second.tterm);
	    }
	    if (onto)
		return true;
	}
	return false;
    }

    void BasicGraphPattern::bindVariables (ResultSet* rs, const BasicGraphPattern* toMatch,
					   const TTerm* graphVar, const TTerm* graphName) const {
	BOOST_LOG_SEV(Logger::GraphMatchLog::get(), Logger::engineer) << "matching " << *toMatch;
	for (std::vector<const TriplePattern*>::const_iterator constraint = toMatch->m_TriplePatterns.begin();
	     constraint != toMatch->m_TriplePatterns.end(); constraint++) {
	    for (ResultSetIterator row = rs->begin() ; row != rs->end(); ) {
		bool rowMatched = false;
		const TTerm* s = (*constraint)->getS();
		if ((*BasicGraphPattern::MappableTerm)(s))
		    s = (*row)->get(s);
		const TTerm* p = (*constraint)->getP();
		if ((*BasicGraphPattern::MappableTerm)(p))
		    p = (*row)->get(p);
		const TTerm* o = (*constraint)->getO();
		if ((*BasicGraphPattern::MappableTerm)(o))
		    o = (*row)->get(o);

		triple_iterator mi = getTripleIterator(s, p, o);
		triple_iterator end;

		// TTerm2Triple_range mi.inner
		//     = dynamic_cast<const Bindable*>(pToMatch) 
		//     ? TTerm2Triple_range(TTerm2Triple.begin(), TTerm2Triple.end())
		//     : TTerm2Triple.equal_range (pToMatch);

		for ( ; mi != end; ++mi)
		    /* TODO: Could process filters here */
		    if ((*constraint)->bindVariables(*mi, toMatch->allOpts,
						     rs, row, graphVar, graphName, this))
			rowMatched = true;

		if (rowMatched || !toMatch->allOpts) {
		    delete *row;
		    row = rs->erase(row);
		} else {
		    row++;
		}
	    }
	}
	BOOST_LOG_SEV(Logger::GraphMatchLog::get(), Logger::engineer) << "produced\n" << *rs;
    }
    void BasicGraphPattern::triple_iterator::operator++ () {
	++triple;
	if (triple == inner.second) {
	    if (useOuter)
		if (++tterm2triple == outer.second)
		    atEnd = true;
		else {
		    inner = TTerm2Triple_range(tterm2triple->second.begin(), tterm2triple->second.end());
		    triple = inner.first;
		}
	    else
		atEnd = true;
	}
    }
    bool BasicGraphPattern::triple_iterator::operator!= (const BasicGraphPattern::triple_iterator& ref) const {
	if ((atEnd || triple == inner.second) && ref.atEnd)
	    return false;
	return true; // !! only good for ... it != end()
    }
    BasicGraphPattern::triple_iterator BasicGraphPattern::getTripleIterator (const TTerm* s, const TTerm* p, const TTerm* o) const {
	if (s)
	    if (p)
		return triple_iterator(SP.get(s, p));
	    else if (o)
		return triple_iterator(OS.get(o, s));
	    else {
		return triple_iterator(SP.get(s));
	    }
	else if (p)
	    if (o)
		return triple_iterator(PO.get(p, o));
	    else {
		return triple_iterator(PO.get(p));
	    }
	else if (o) {
	    return triple_iterator(OS.get(o));
	} else {
	    return triple_iterator(TTerm2TTerm2Triple_type::range(SP.begin(), SP.end()));
	}
    }
    bool TTerm::bindVariable (const TTerm* constant, ResultSet* rs, Result* provisional, bool weaklyBound) const {
	if (this == Unbound || constant == Unbound)
	    return true;
	TreatAsVar treatAsVar;
	const TTerm* curVal = evalTTerm(provisional, &treatAsVar); // doesn't need to generate symbols
	if (curVal == Unbound) {
	    rs->set(provisional, this, constant, weaklyBound);
	    return true;
	}
	return constant == curVal;
    }
    bool TTerm::symmetricBindVariable (const TTerm* constant, ResultSet* rs, Result* provisional, bool weaklyBound) const {
	if (this == Unbound || constant == Unbound)
	    return true;
	TreatAsVar treatAsVar;
	const TTerm* curVal = evalTTerm(provisional, &treatAsVar); // doesn't need to generate symbols
	if (curVal == Unbound) {
	    rs->set(provisional, this, constant, weaklyBound);
	    return true;
	} else {
	    const TTerm* curVal = constant->evalTTerm(provisional, &treatAsVar); // doesn't need to generate symbols
	    if (curVal == Unbound) {
		rs->set(provisional, constant, this, weaklyBound);
		return true;
	    }
	}
	return constant == curVal;
    }

    std::string Members::toString () const {
	std::stringstream ss;
	ss << "Members(";
	for (std::vector<const TTerm*>::const_iterator it = m_vars->begin();
	     it != m_vars->end(); ++it) {
	    if (it != m_vars->begin())
		ss << ", ";
	    ss << (*it)->toString();
	}
	ss << ")";
	return ss.str();
    }

    const TTerm* BasicGraphPattern::expectOneSubject (const TTerm* p, const TTerm* o) const {
	BasicGraphPattern::TTerm2Triple_range inner = PO.get(p, o);
	if (inner == TTerm2Triple_range())
	    throw GraphStructureError(std::string() + "no " + o->toString() + " found", "expectOneSubject");
	BasicGraphPattern::TTerm2Triple_type::const_iterator triple = inner.first;
	const TTerm* ret = triple->second->getS();
	if (++triple != inner.second)
	    throw GraphStructureError(std::string() + "two " + o->toString() + "s found", "expectOneSubject");
	return ret;
    }
    std::set<const TTerm*> BasicGraphPattern::expectNSubjects (const TTerm* p, const TTerm* o) const {
	BasicGraphPattern::TTerm2Triple_range inner = PO.get(p, o);
	if (inner == TTerm2Triple_range())
	    throw GraphStructureError(std::string() + "no " + o->toString() + " found", "expectOneSubject");
	std::set<const TTerm*> ret;
	for (BasicGraphPattern::TTerm2Triple_type::const_iterator triple = inner.first;
	     triple != inner.second; ++triple)
	    ret.insert(triple->second->getS());
	return ret;
    }

    const TTerm* BasicGraphPattern::expectOneObject (const TTerm* s, const TTerm* p) const {
	BasicGraphPattern::TTerm2Triple_range inner = SP.get(s, p);
	if (inner == TTerm2Triple_range())
	    throw GraphStructureError(std::string() + "no " + p->toString() + " found", "expectOneObject");
	BasicGraphPattern::TTerm2Triple_type::const_iterator triple = inner.first;
	const TTerm* ret = triple->second->getO();
	if (++triple != inner.second)
	    throw GraphStructureError(std::string() + "two " + p->toString() + "s found", "expectOneObject");
	return ret;
    }
    std::set<const TTerm*> BasicGraphPattern::expectNObjects (const TTerm* s, const TTerm* p) const {
	BasicGraphPattern::TTerm2Triple_range inner = SP.get(s, p);
	if (inner == TTerm2Triple_range())
	    throw GraphStructureError(std::string() + "no " + s->toString() + " found", "expectOneObject");
	std::set<const TTerm*> ret;
	for (BasicGraphPattern::TTerm2Triple_type::const_iterator triple = inner.first;
	     triple != inner.second; ++triple)
	    ret.insert(triple->second->getO());
	return ret;
    }

    bool PredicatePath::matchingTriples (const TriplePattern* start, const BasicGraphPattern* bgp, std::vector<SubObjPair>& tps) const {
	tps.push_back(SubObjPair(start->getS(), start->getO())); // !!!!
	return true;
    }

    bool Members::getListElements (const TTerm* from, const BasicGraphPattern* data, std::vector<VarValuePair>* vec) const {
	std::vector<const TTerm*>::const_iterator curVar = m_vars->begin();
	for (; from != TTerm::RDF_nil;) {
	    vec->push_back(VarValuePair(*curVar, data->expectOneObject(from, TTerm::RDF_first)));
	    from = data->expectOneObject(from, TTerm::RDF_rest);
	    if (++curVar == m_vars->end())
		curVar = m_vars->begin();
	}

	return true;
    }

    void Bind::bindVariables (const RdfDB* db, ResultSet* rs) const {
	if (m_TableOperation != NULL)
	    m_TableOperation->bindVariables(db, rs);
	rs->addKnownVar(m_label);
	for (ResultSetIterator row = rs->begin() ; row != rs->end(); ++row)
	    try {
		(*row)->set(m_label, m_expr->eval(*row, rs->getAtomFactory(), NULL, NULL, db), false, true);
		// atomFactory: NULL.
		// not a loose binding, whatever that means now.
		// replace: setting TTerm::Unbound deletes the binding.
	    } catch (SafeEvaluationError&) {
		// Don't (*row)->set(m_label, TTerm::Unbound, false) as RS contract is to leave unbounds NULL c.f. "setting ?d to Unbound is just wrong"
	    }
    }

    TableOperationOnOperation* Bind::makeANewThis (const TableOperation* p_TableOperation) const {
	SWObjectDuplicator dup(NULL); // doesn't need to create new atoms.
	m_expr->express(&dup);
	return new Bind(p_TableOperation, dup.last.expression, m_label);
    }

    void GraphGraphPattern::construct (RdfDB* target, const ResultSet* rs, BNodeEvaluator* evaluator, BasicGraphPattern* /* bgp */) const {
	const URI* graphName = dynamic_cast<const URI*>(m_VarOrIRIref);
	if (graphName != NULL) {
	    /* GRAPH <x> { ?s ?p ?o } */
	    BasicGraphPattern* bgp = target->ensureGraph(graphName);
	    m_TableOperation->construct(target, rs, evaluator, bgp);
	} else {
	    /* GRAPH ?g { ?s ?p ?o } */
	    for (ResultSetConstIterator result = rs->begin() ; result != rs->end(); result++) {
		const TTerm* evaldGraphName = m_VarOrIRIref->evalTTerm(*result, evaluator);
		if (evaldGraphName != TTerm::Unbound) {
		    BasicGraphPattern* bgp = target->ensureGraph(evaldGraphName);
		    const ResultSet* rowRS = (*result)->makeResultSet(rs->getAtomFactory());
		    m_TableOperation->construct(target, rowRS, evaluator, bgp);
		}
	    }
	}
    }

    void GraphGraphPattern::deletePattern (RdfDB* target, const ResultSet* rs, BNodeEvaluator* evaluator, BasicGraphPattern* /* bgp */) const {
	const URI* graphName = dynamic_cast<const URI*>(m_VarOrIRIref);
	if (graphName != NULL) {
	    /* GRAPH <x> { ?s ?p ?o } */
	    BasicGraphPattern* bgp = target->ensureGraph(graphName);
	    m_TableOperation->deletePattern(target, rs, evaluator, bgp);
	} else {
	    /* GRAPH ?g { ?s ?p ?o } */
	    for (ResultSetConstIterator result = rs->begin() ; result != rs->end(); result++) {
		const TTerm* evaldGraphName = m_VarOrIRIref->evalTTerm(*result, evaluator);
		if (evaldGraphName != TTerm::Unbound) {
		    BasicGraphPattern* bgp = target->ensureGraph(evaldGraphName);
		    m_TableOperation->deletePattern(target, rs, evaluator, bgp);
		}
	    }
	}
    }

    void _constructQuery (const URI* service, const TableOperation* op,
			  ResultSet* rs, AtomFactory* atomFactory,
			  SWSAXparser* xmlParser, SWWEBagent* agent) {

	/* The VarLister is a serializer which also records all variables.
	 */
	struct VarLister : public SPARQLSerializer {
	    std::set<const TTerm*> vars;
	    ExpressionAliasList* l;
	    VarLister () : l(new ExpressionAliasList()) {  }
	    virtual void variable (const Variable* const self, std::string lexicalValue) {
		if (vars.find(self) == vars.end()) {
		    vars.insert(self);
		    l->push_back(new ExpressionAlias(new TTermExpression(self)));
		}
		SPARQLSerializer::variable(self, lexicalValue);
	    }
	};

	VarLister vars;
	op->express(&vars);

	/* Copy graph pattern for inclusion in a new Select. */
	SWObjectDuplicator dup(NULL); // doesn't need to create new atoms.
	op->express(&dup);
	const Operation* query;
	const SubSelect* subsel = dynamic_cast<const SubSelect*>(dup.last.tableOperation);
	if (subsel == NULL) {
	    query = new Select(DIST_distinct, vars.l,
			       new ProductionVector<const DatasetClause*>(),
			       new WhereClause(dup.last.tableOperation),
			       new SolutionModifier(NULL, NULL, NULL, LIMIT_None, OFFSET_None)); // !!! groupBy, having
	} else {
	    query = subsel->getSelect();
	}

	/* Query parms for GET or POST */
	SWWEBagent::ParameterList p;

	// Sesame seems to ignore HTTP Accept headers but takes an Accept query
	// parameter with exactly one media type. You can force this with e.g.
	// -Dw3c_sw_FORCE_SESAME_XML_RESULTS "application/sparql-results+xml"
#ifdef w3c_sw_FORCE_SESAME_XML_RESULTS
	p.set("Accept", w3c_sw_FORCE_SESAME_XML_RESULTS);
#endif

	const VariableList* knownVars = rs->getKnownVars();
	// for (VariableList::const_iterator known = vars.vars.begin(); known != vars.vars.end(); ++known)
	//     w3c_sw_LINEN << "pattern " << op->toString() << " has " << (*known)->toString() << "\n";
	// for (VariableList::const_iterator known = knownVars->begin(); known != knownVars->end(); ++known)
	//     w3c_sw_LINEN << "rs " << *rs << " has " << (*known)->toString() << "\n";
	std::vector<const TTerm*> varsIntersection(vars.vars.size() + knownVars->size());
	std::vector<const TTerm*>::iterator end =
	    std::set_intersection (vars.vars.begin(), vars.vars.end(),
				   knownVars->begin(), knownVars->end(),
				   varsIntersection.begin());
	varsIntersection.resize(end - varsIntersection.begin());
	// for (std::vector<const TTerm*>::const_iterator isect = varsIntersection.begin(); isect != varsIntersection.end(); ++isect)
	//     w3c_sw_LINEN << "intersection " << (*isect)->toString() << "\n";

	if (rs->empty()
	    || varsIntersection.size() == 0
	    || rs->size() > ServiceGraphPattern::defaultFederationRowLimit) {
	    p.set("query", query->toString());
	    BOOST_LOG_SEV(Logger::ServiceLog::get(), Logger::info)
		<< "Querying <" << service->getLexicalValue() << "> for\n" << query->toString() << "\n";
	} else if (ServiceGraphPattern::useFilters) {
	    /*
	     * Constrain query with any existing result bindings.
	     */
	    // Either through a BINDINGS string ...
	    const Operation* rsConstrained =
		rs->getConstrainedOperation(query);
	    p.set("query", rsConstrained->toString());
	    BOOST_LOG_SEV(Logger::ServiceLog::get(), Logger::info)
		<< "Querying <" << service->getLexicalValue() << "> for\n" << rsConstrained->toString() << "\n";
	    delete rsConstrained;
	} else {
	    // ... or some FILTERs on the operation.
	    p.set("query", query->toString() + rs->getBindingsString(varsIntersection));
	    BOOST_LOG_SEV(Logger::ServiceLog::get(), Logger::info)
		<< "Querying <" << service->getLexicalValue() << "> for\n" << query->toString() + rs->getBindingsString(varsIntersection) << "\n";
	}
	delete query;

	/* Do an HTTP GET and parse results into a ResultSet. */
	boost::shared_ptr<IStreamContext> istr;
	std::string s;
	switch (ServiceGraphPattern::defaultHTTPmethod) {
	case ServiceGraphPattern::HTTP_METHOD_GET:
	    istr = agent->get(service->getLexicalValue().c_str(), p);
	    break;
	case ServiceGraphPattern::HTTP_METHOD_POST:
	    istr = agent->post(service->getLexicalValue().c_str(), p);
	    break;
	default:
	    throw "program flow exception -- unknown defaultHTTPmethod";
	}
	try {
	    ResultSet red(atomFactory, xmlParser, *istr);
	    if (Logger::Logging(Logger::ServiceLog_level, Logger::info)) {
		std::stringstream o;
		o << " yielded";
		size_t size = red.size();
		if (size > ResultSet::DebugEnumerateLimit)
		    o
			<< " " << size
			<< " result" << (size == 1 ? "" : "s")
			<< ".\n";
		else
		    o << "\n" << red;
		BOOST_LOG_SEV(Logger::ServiceLog::get(), Logger::info) << o.str();
	    }

	    /* Join those results against our initial results. */
	    rs->joinIn(&red);
	} catch (std::string e) {
	    throw e + "\nerror parsing response from service " + service->toString() + ".";
	}
    }
    void ServiceGraphPattern::bindVariables (const RdfDB* db, ResultSet* rs) const {
	const URI* graph = dynamic_cast<const URI*>(m_VarOrIRIref);
	if (graph != NULL)
	    try {
		_constructQuery(graph, m_TableOperation, rs, atomFactory, db->xmlParser, db->webAgent);
	    } catch (std::exception& e) {
		if (m_Silence == SILENT_Yes)
		    BOOST_LOG_SEV(Logger::GraphMatchLog::get(), Logger::warning) << "SERVICE " << graph->toString() << " produced error: " << e.what() << std::endl;
		else
		    throw std::string() + "SERVICE " + graph->toString() + " produced error: " + e.what();
	    } catch (std::string& s) {
		if (m_Silence == SILENT_Yes)
		    BOOST_LOG_SEV(Logger::GraphMatchLog::get(), Logger::warning) << "SERVICE " << graph->toString() << " produced error: " << s << std::endl;
		else
		    throw std::string() + "SERVICE " + graph->toString() + " produced error: " + s;
	    }
	else {
	    const Variable* graphVar = dynamic_cast<const Variable*>(m_VarOrIRIref);
	    if (graphVar != NULL) {
		for (ResultSetIterator outerRow = rs->begin() ; outerRow != rs->end(); ) {
		    const URI* graph = dynamic_cast<const URI*>((*outerRow)->get(graphVar));
		    try {
			if (graph != NULL) {
			    ResultSet* single = (*outerRow)->makeResultSet(atomFactory);
			    _constructQuery(graph, m_TableOperation, single, atomFactory, db->xmlParser, db->webAgent);
			    for (ResultSetIterator innerRow = single->begin() ; innerRow != single->end(); ) {
				rs->insert(outerRow, *innerRow);
				innerRow = single->erase(innerRow);
			    }
			} else {
			    // treat like a TypeError; no result
			}
			delete *outerRow;
			outerRow = rs->erase(outerRow);
		    } catch (std::exception& e) {
			if (m_Silence == SILENT_Yes) {
			    BOOST_LOG_SEV(Logger::GraphMatchLog::get(), Logger::warning) << "SERVICE " << graph->toString() << " produced error: " << e.what() << std::endl;
			    ++outerRow;
			} else
			    throw std::string() + "SERVICE " + graph->toString() + " produced error: " + e.what();
		    } catch (std::string& s) {
			if (m_Silence == SILENT_Yes) {
			    BOOST_LOG_SEV(Logger::GraphMatchLog::get(), Logger::warning) << "SERVICE " << graph->toString() << " produced error: " << s << std::endl;
			    ++outerRow;
			} else
			    throw std::string() + "SERVICE " + graph->toString() + " produced error: " + s;
		    }
		}
	    } else
		throw std::string("Service name must be an IRI; attempted to call SERVICE ").append(m_VarOrIRIref->toString());
	}
	BOOST_LOG_SEV(Logger::GraphMatchLog::get(), Logger::engineer) << "SERVICE produced\n" << *rs;
    }

    void ServiceGraphPattern::construct (RdfDB* /* target */, const ResultSet* /* rs */, BNodeEvaluator* /* evaluator */, BasicGraphPattern* /* bgp */) const {
	throw std::string("@@ServiceGraphPattern::construct not yet written");
	// const URI* serviceName = dynamic_cast<const URI*>(m_VarOrIRIref);
	// if (serviceName != NULL) {
	//     /* GRAPH <x> { ?s ?p ?o } */
	//     BasicGraphPattern* bgp = target->ensureGraph(graphName);
	//     m_TableOperation->construct(target, rs, evaluator, bgp);
	// } else {
	//     /* SERVICE ?g { ?s ?p ?o } */
	//     for (ResultSetConstIterator result = rs->begin() ; result != rs->end(); result++) {
	// 	const TTerm* evaldServiceName = m_VarOrIRIref->evalTTerm(*result, evaluator);
	// 	BasicGraphPattern* bgp = target->ensureGraph(evaldServiceName);
	// 	m_TableOperation->construct(target, rs, evaluator, bgp);
	//     }
	// }
    }

    void ServiceGraphPattern::deletePattern (RdfDB* /* target */, const ResultSet* /* rs */, BNodeEvaluator* /* evaluator */, BasicGraphPattern* /* bgp */) const {
	throw std::string("@@ServiceGraphPattern::delete not yet written");
	// const URI* serviceName = dynamic_cast<const URI*>(m_VarOrIRIref);
	// if (serviceName != NULL) {
	//     /* GRAPH <x> { ?s ?p ?o } */
	//     BasicGraphPattern* bgp = target->ensureGraph(graphName);
	//     m_TableOperation->deletePattern(target, rs, evaluator, bgp);
	// } else {
	//     /* SERVICE ?g { ?s ?p ?o } */
	//     for (ResultSetConstIterator result = rs->begin() ; result != rs->end(); result++) {
	// 	const TTerm* evaldServiceName = m_VarOrIRIref->evalTTerm(*result, evaluator);
	// 	BasicGraphPattern* bgp = target->ensureGraph(evaldServiceName);
	// 	m_TableOperation->deletePattern(target, rs, evaluator, bgp);
	//     }
	// }
    }


    SADIGraphPattern::SADIGraphPattern (const TTerm* p_TTerm, e_Silence p_Silence,
					const TableOperation* p_ConstructTemplate, WhereClause* p_WhereClause) : 
	m_VarOrIRIref(p_TTerm), m_Silence(p_Silence), atomFactory(atomFactory),
	m_ConstructTemplate(p_ConstructTemplate),
	m_WhereClause(p_WhereClause)
    {  }
    std::string SADIGraphPattern::str () {
	std::stringstream ss;
	ss << "SADIGraphPattern:\n";
	{
	    SPARQLSerializer s;
	    m_VarOrIRIref->express(&s);
	    ss << "TTerm: " << s.str();
	}
	{
	    SPARQLSerializer s;
	    m_ConstructTemplate->express(&s);
	    ss << "m_ConstructTemplate: " << s.str();
	}
	{
	    SPARQLSerializer s;
	    m_WhereClause->express(&s);
	    ss << "m_WhereClause: " << s.str();
	}
	return ss.str();
    }

    void _invokeSADI (const char* service, const TableOperation* op, ResultSet* rs,
		      AtomFactory* atomFactory, RdfDB* requestDB, RdfDB* responseDB) {
	MakeNewBNode makeNewBNode(rs->getAtomFactory());
	op->construct(requestDB, rs, &makeNewBNode, requestDB->ensureGraph(DefaultGraph));
	// w3c_sw_LINEN << "CONSTRUCTED: " << *requestDB << std::endl;

	boost::shared_ptr<IStreamContext> istr;
	const char* reqMediaType = requestDB->getGraphNames().size() > 0
	    ? "text/trig"
	    : "text/turtle";
	istr = requestDB->webAgent->post(service, reqMediaType,
					 requestDB->toString(reqMediaType).c_str());
	responseDB->loadData(responseDB->ensureGraph(DefaultGraph), *istr, service, 
			     service, rs->getAtomFactory() /* , &nsAccumulator, &grddlMap */ );
	if (Logger::Logging(Logger::IOLog_level, Logger::info)) {
	    std::stringstream o;
	    o << "POSTing [[\n" << requestDB->str() << "]] to " << service;
	    o << "yielded [[\n" << responseDB->str() << "]]";
	    if (istr->mediaType)
		o << " with media type " << *istr->mediaType;
	    o << ".\n";
	    BOOST_LOG_SEV(Logger::IOLog::get(), Logger::info) << o.str();
	}
    }
    void SADIGraphPattern::bindVariables (const RdfDB* db, ResultSet* rs) const {
	// RdfDB copyDB(*db);
	RdfDB* requestDB = const_cast<RdfDB*>(db);
	RdfDB responseDB(db->xmlParser);
	const URI* graph = dynamic_cast<const URI*>(m_VarOrIRIref);
	if (graph != NULL)
	    try {
		_invokeSADI(graph->getLexicalValue().c_str(), m_ConstructTemplate, rs, rs->getAtomFactory(), requestDB, &responseDB);
	    } catch (std::exception& e) {
		if (m_Silence == SILENT_Yes)
		    BOOST_LOG_SEV(Logger::GraphMatchLog::get(), Logger::warning) << "SADI " << graph->toString() << " produced error: " << e.what() << std::endl;
		else
		    throw std::string() + "SADI " + graph->toString() + " produced error: " + e.what();
	    } catch (std::string& s) {
		if (m_Silence == SILENT_Yes)
		    BOOST_LOG_SEV(Logger::GraphMatchLog::get(), Logger::warning) << "SADI " << graph->toString() << " produced error: " << s << std::endl;
		else
		    throw std::string() + "SADI " + graph->toString() + " produced error: " + s;
	    }
	else {
	    const Variable* graphVar = dynamic_cast<const Variable*>(m_VarOrIRIref);
	    if (graphVar != NULL) {
		for (ResultSetIterator outerRow = rs->begin() ; outerRow != rs->end(); ) {
		    const URI* graph = dynamic_cast<const URI*>((*outerRow)->get(graphVar));
		    try {
			if (graph != NULL) {
			    ResultSet* single = (*outerRow)->makeResultSet(atomFactory);
			    _invokeSADI(graph->getLexicalValue().c_str(), m_ConstructTemplate, single, rs->getAtomFactory(), requestDB, &responseDB);
			    for (ResultSetIterator innerRow = single->begin() ; innerRow != single->end(); ) {
				rs->insert(outerRow, *innerRow);
				innerRow = single->erase(innerRow);
			    }
			} else {
			    // treat like a TypeError; no result
			}
			delete *outerRow;
			outerRow = rs->erase(outerRow);
		    } catch (std::exception& e) {
			if (m_Silence == SILENT_Yes) {
			    BOOST_LOG_SEV(Logger::GraphMatchLog::get(), Logger::warning) << "SADI " << graph->toString() << " produced error: " << e.what() << std::endl;
			    ++outerRow;
			} else
			    throw std::string() + "SADI " + graph->toString() + " produced error: " + e.what();
		    } catch (std::string& s) {
			if (m_Silence == SILENT_Yes) {
			    BOOST_LOG_SEV(Logger::GraphMatchLog::get(), Logger::warning) << "SADI " << graph->toString() << " produced error: " << s << std::endl;
			    ++outerRow;
			} else
			    throw std::string() + "SADI " + graph->toString() + " produced error: " + s;
		    }
		}
	    } else
		throw std::string("Sadi name must be an IRI; attempted to call SADI ").append(m_VarOrIRIref->toString());
	}
	m_WhereClause->bindVariables(&responseDB, rs);
	BOOST_LOG_SEV(Logger::GraphMatchLog::get(), Logger::engineer) << "SADI produced\n" << *rs;
    }
    void SADIGraphPattern::construct (RdfDB* target, const ResultSet* rs, BNodeEvaluator* evaluator, BasicGraphPattern* bgp) const {
	w3c_sw_NEED_IMPL("@@SADIGraphPattern::construct not yet written");
    }
    void SADIGraphPattern::deletePattern (RdfDB* target, const ResultSet* rs, BNodeEvaluator* evaluator, BasicGraphPattern* bgp) const {
	w3c_sw_NEED_IMPL("@@SADIGraphPattern::delete not yet written");
    }
    TableOperation* SADIGraphPattern::getDNF () const {
	w3c_sw_NEED_IMPL("@@SADIGraphPattern::getDNF not yet written");
    }


    void OptionalGraphPattern::bindVariables (const RdfDB* db, ResultSet* rs) const {
	ResultSet optRS(rs->getAtomFactory()); // no AtomFactory
	m_TableOperation->bindVariables(db, &optRS);
	rs->joinIn(&optRS, &m_Expressions, ResultSet::OP_outer);
	BOOST_LOG_SEV(Logger::GraphMatchLog::get(), Logger::engineer) << "OPTIONAL produced\n" << *rs;
    }

    void MinusGraphPattern::bindVariables (const RdfDB* db, ResultSet* rs) const {
	ResultSet optRS(*rs); // no AtomFactory
	m_TableOperation->bindVariables(db, &optRS);
	rs->joinIn(&optRS, NULL, ResultSet::OP_minus);
	BOOST_LOG_SEV(Logger::GraphMatchLog::get(), Logger::engineer) << "MINUS produced\n" << *rs;
    }

    void BasicGraphPattern::construct (RdfDB* target, const ResultSet* rs, BNodeEvaluator* evaluator, BasicGraphPattern* bgp) const {
	if (bgp == NULL)
	    bgp = target->ensureGraph(NULL);
	for (ResultSetConstIterator result = rs->begin() ; result != rs->end(); result++)
	    for (std::vector<const TriplePattern*>::const_iterator triple = m_TriplePatterns.begin();
		 triple != m_TriplePatterns.end(); triple++)
		(*triple)->construct(bgp, *result, rs->getAtomFactory(), evaluator);
    }

    void BasicGraphPattern::deletePattern (RdfDB* target, const ResultSet* rs, BNodeEvaluator* /* evaluator */, BasicGraphPattern* bgp) const {
	if (bgp == NULL)
	    bgp = target->ensureGraph(NULL);
	for (std::vector<const TriplePattern*>::const_iterator constraint = m_TriplePatterns.begin();
	     constraint != m_TriplePatterns.end(); constraint++) {
	    for (ResultSetConstIterator row = rs->begin() ; row != rs->end(); ++row) {
		for (std::vector<const TriplePattern*>::iterator triple = bgp->m_TriplePatterns.begin();
		     triple != bgp->m_TriplePatterns.end(); ) {
		    ResultSet* island = (*row)->makeResultSet(rs->getAtomFactory());
		    if ((*constraint)->bindVariables(*triple, false, island, island->begin())) // may need graphVar, graphName?
			triple = bgp->erase(triple);
		    else
			triple++;
		    delete island;
		}
	    }
	}
    }

    std::string TriplePattern::str() const { return toString(); } // for easy invocation.

    bool TriplePattern::bindVariables (const TriplePattern* tp, bool, ResultSet* rs, const ResultSetIterator& row,
				       const TTerm* graphVar, const TTerm* graphName, const BasicGraphPattern* data) const {
	// return
	//     (graphVar == TTerm::Unbound || graphVar->bindVariable(graphName, rs, provisional, weaklyBound)) &&
	//     m_p->bindVariable(tp->m_p, rs, provisional, weaklyBound) && 
	//     m_s->bindVariable(tp->m_s, rs, provisional, weaklyBound) && 
	//     m_o->bindVariable(tp->m_o, rs, provisional, weaklyBound);
	Result* rowWithGandPbound = (*row)->duplicate(rs, row);

	if (!(graphVar == TTerm::Unbound || graphVar->bindVariable(graphName, rs, rowWithGandPbound, weaklyBound))) {
	    delete rowWithGandPbound;
	    return false;
	}

	std::vector<PredicatePath::SubObjPair> soPairs;
	const PredicatePath* asPath = dynamic_cast<const PredicatePath*>(m_p);
	if (asPath == NULL) {
	    if (!m_p->bindVariable(tp->m_p, rs, rowWithGandPbound, weaklyBound)) {
		delete rowWithGandPbound;
		return false;
	    }
	    soPairs.push_back(PredicatePath::SubObjPair(tp->getS(), tp->getO()));
	} else {
	    if (!asPath->matchingTriples(tp, data, soPairs)) {
		delete rowWithGandPbound;
		return false;		
	    }
	}
	bool ret = false;
	for (std::vector<PredicatePath::SubObjPair>::const_iterator curTP = soPairs.begin();
	     curTP != soPairs.end(); ++curTP) {

	    std::vector<ListTerm::VarValuePair> subjects, objects;

	    const ListTerm* sAsListTerm = dynamic_cast<const ListTerm*>(m_s);
	    if (sAsListTerm == NULL)
		subjects.push_back(ListTerm::VarValuePair(m_s, tp->m_s));
	    else
		if (!sAsListTerm->getListElements(curTP->subj, data, &subjects))
		    return false;

	    const ListTerm* oAsListTerm = dynamic_cast<const ListTerm*>(m_o);
	    if (oAsListTerm == NULL)
		objects.push_back(ListTerm::VarValuePair(m_o, tp->m_o));
	    else
		if (!oAsListTerm->getListElements(curTP->obj, data, &objects))
		    return false;

	    for (std::vector<ListTerm::VarValuePair>::const_iterator curS = subjects.begin();
		 curS != subjects.end(); ++curS) {
		for (std::vector<ListTerm::VarValuePair>::const_iterator curO = objects.begin();
		     curO != objects.end(); ++curO) {
		    Result* provisional = rowWithGandPbound->duplicate(rs, row);
		    if (curS->var->bindVariable(curS->value, rs, provisional, weaklyBound) &&
			curO->var->bindVariable(curO->value, rs, provisional, weaklyBound)) {
			rs->insert(row, provisional);
			ret = true;
		    } else
			delete provisional;
		}
	    }
	}
	delete rowWithGandPbound;
	return ret;
    }

    bool TriplePattern::construct (BasicGraphPattern* target, const Result* r, AtomFactory* atomFactory, BNodeEvaluator* evaluator) const {
	bool ret = false;
	const TTerm *s, *p, *o;
	if ((s = m_s->evalTTerm(r, evaluator)) != TTerm::Unbound && 
	    (p = m_p->evalTTerm(r, evaluator)) != TTerm::Unbound && 
	    (o = m_o->evalTTerm(r, evaluator)) != TTerm::Unbound) {
	    if (atomFactory == NULL) {
		if (s == m_s && p == m_p && o == m_o && !weaklyBound)
		    target->addTriplePattern(this);
		else
		    throw(std::runtime_error("TriplePattern::construct requires AtomFactory when constructing new triples."));
	    } else
		  target->addTriplePattern(atomFactory->getTriple(s, p, o));
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
	} else if (mediaType.match("application/rdf+xml")) {
	    if (dynamic_cast<const BNode*>(m_s) != NULL)
		s << "<rdf:Description rdf:nodeId='g" << m_s->getLexicalValue() << "'>";
	    else
		s << "<rdf:Description rdf:about='" << m_s->getLexicalValue() << "'>";
	    std::string p = m_p->getLexicalValue();
	    size_t end = p.find_last_of("/#"); ++end;
	    s << "<" << p.substr(end) << " xmlns='" << p.substr(0, end) << "'";
	    if (dynamic_cast<const BNode*>(m_o) != NULL)
		s << " rdf:nodeId='g" << m_o->getLexicalValue() << "'/>";
	    else if (dynamic_cast<const URI*>(m_o) != NULL)
		s << " rdf:resource='" << m_o->getLexicalValue() << "'/>";
	    else
		s << ">" << m_o->getLexicalValue() << "</" << p.substr(end) << ">";
	    s << "</rdf:Description>\n";
	} else {
	    s << "{" << m_s->toString() << " " << m_p->toString() << " " << m_o->toString() << "}";
	}
	return s.str();
    }
    std::string TableOperation::toString (MediaType mediaType, NamespaceMap* namespaces) const {
	SPARQLSerializer s(mediaType, namespaces, "  ", SPARQLSerializer::DEBUG_none, "");
	express(&s);
	return s.str();
    }
    std::string TableOperation::str () const { return toString(); } // for easy invocation
    std::string BasicGraphPattern::toString (MediaType mediaType, NamespaceMap* namespaces) const {
	std::stringstream ret;
	if (mediaType.match("text/trig")) {
	    SPARQLSerializer s(mediaType, namespaces, "  ", SPARQLSerializer::DEBUG_none, "");
	    express(&s);
	    ret << s.str();
	} else if (mediaType.match("application/rdf+xml")) {
	    ret << "<?xml version='1.0'?>\n<rdf:RDF xmlns:rdf='http://www.w3.org/1999/02/22-rdf-syntax-ns#'>\n";
	    for (std::vector<const TriplePattern*>::const_iterator triple = m_TriplePatterns.begin();
		 triple != m_TriplePatterns.end(); triple++)
		ret << (*triple)->toString(mediaType, namespaces);
	    ret << "</rdf:RDF>\n";
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


    /**
     * DisjointList - compile structure for a disjunctive normal form.
     * @method join takes TableOperations and sorts them into the DisjointList.
     */
    struct ConjointList;
    struct DisjointList;
    std::ostream& operator <<(std::ostream& os, const ConjointList& cl);
    std::ostream& operator <<(std::ostream& os, DisjointList& top);

    TableOperation* _copyTableOperation (const TableOperation& ref) {
	SWObjectDuplicator dup(NULL);
	ref.express(&dup);
	return dup.last.tableOperation;
    }

#if defined(SWIG)
} /* namespace w3c_sw */
namespace std {%template(vector_TableOperationstar) vector<const w3c_sw::TableOperation*>;}
namespace w3c_sw {
#endif /* defined(SWIG) */
    struct ConjointList : public std::vector<const TableOperation*> {

	ConjointList () : std::vector<const TableOperation*>() {  }
	void copy (const ConjointList& ref) {
	    const BasicGraphPattern* bgp;
	    for (std::vector<const TableOperation*>::const_iterator in = ref.begin();
		 in != ref.end(); ++in) {
		if ((bgp = dynamic_cast<const BasicGraphPattern*>(*in)) != NULL)
		    push_back(_copyTableOperation(*bgp));
		else
		    throw std::string("unknown type");
	    }
	}

	void free () {
	    for (std::vector<const TableOperation*>::const_iterator in = begin();
		 in != end(); ++in)
		delete *in;
	}

	TableOperation* toTableOperation () const {
	    if (size() == 0)
		throw std::string("empty ConjointList");
	    if (size() == 1)
		return (TableOperation*)at(0); // !!! Lies
	    TableConjunction* ret = new TableConjunction();
	    for (ConjointList::const_iterator con = begin();
		 con != end(); ++con)
		ret->addTableOperation(*con, false);
	    return ret;
	}

    };

    struct DisjointList;
    std::ostream& operator <<(std::ostream& os, DisjointList& top);
#if defined(SWIG)
} /* namespace w3c_sw */
namespace std {%template(vector_ConjointList) vector<w3c_sw::ConjointList>;}
namespace w3c_sw {
#endif /* defined(SWIG) */
    struct DisjointList : public std::vector<ConjointList> {

	DisjointList () {
	    push_back(ConjointList());
	}

	void free () {
	    for (std::vector<ConjointList>::iterator in = begin();
		 in != end(); ++in)
		in->free();
	}

	void disjoin (const TableDisjunction* ins) {
	    for (DisjointList::iterator dis = begin();
		 dis != end(); ) {
		for (std::vector<const TableOperation*>::const_iterator in = ins->begin();
		     in != ins->end(); ++in) {
		    ConjointList copy;
		    copy.copy(*dis);
		    dis = insert(dis, copy);
		    const TableConjunction* conjoints;
		    const BasicGraphPattern* bgp;
		    if ((conjoints = dynamic_cast<const TableConjunction*>(*in)) != NULL)
			for (std::vector<const TableOperation*>::const_iterator in2 = conjoints->begin();
			     in2 != conjoints->end(); ++in2) {
			    if ((bgp = dynamic_cast<const BasicGraphPattern*>(*in2)) != NULL)
				dis->push_back(_copyTableOperation(*bgp));
			    else
				throw std::string("unknown type");
			}
		    else if ((bgp = dynamic_cast<const BasicGraphPattern*>(*in)) != NULL)
			dis->push_back(_copyTableOperation(*bgp));
		    else
			throw std::string("unknown type");
		    ++dis;
		}
		dis->free();
		dis = erase(dis);
	    }
	}

	void conjoin (const TableConjunction* ins) {
	    for (std::vector<const TableOperation*>::const_iterator in = ins->begin();
		 in != ins->end(); ++in)
		join(*in);
	}

	void add (const BasicGraphPattern* ins) {
	    for (DisjointList::iterator dis = begin();
		 dis != end(); ++dis) {
		dis->push_back(_copyTableOperation(*ins));
	    }
	}

	void join (const TableOperation* ins) {
	    const TableDisjunction* disjoints;
	    const TableConjunction* conjoints;
	    const BasicGraphPattern* bgp;
	    if ((disjoints = dynamic_cast<const TableDisjunction*>(ins)) != NULL)
		disjoin(disjoints);
	    else if ((conjoints = dynamic_cast<const TableConjunction*>(ins)) != NULL)
		conjoin(conjoints);
	    else if ((bgp = dynamic_cast<const BasicGraphPattern*>(ins)) != NULL)
		add(bgp);
	    else
		throw std::string("unknown type");
	}

	TableOperation* toTableOperation () const {
	    if (size() == 1)
		return at(0).size() == 0
		    ? NULL
		    : at(0).toTableOperation();
	    TableDisjunction* ret = new TableDisjunction();
	    for (DisjointList::const_iterator dis = begin();
		 dis != end(); ++dis)
		ret->addTableOperation(dis->toTableOperation(), false);
	    return ret;
	}

    };

    std::ostream& operator << (std::ostream& os, const ConjointList& cl) {
	for (ConjointList::const_iterator con = cl.begin();
	     con != cl.end(); ++con) {
	    if (con != cl.begin())
		os << "·";
	    os << (*con)->toString();
	}
	return os;
    }

    std::ostream& operator << (std::ostream& os, DisjointList& dl) {
	for (DisjointList::const_iterator dis = dl.begin();
	     dis != dl.end(); ++dis) {
	    if (dis != dl.begin())
		os << " | ";
	    os << *dis;
	}
	return os;
    }

    TableOperation* TableConjunction::getDNF () const {
	/* Create a disjunction of conjunctions: (A & B) | (C & D) */
	DisjointList dl;

	/* for each of our elements... */
	for (std::vector<const TableOperation*>::const_iterator it = m_TableOperations.begin();
	     it != m_TableOperations.end(); ++it) {
	    TableOperation* op = (*it)->getDNF();
	    dl.join(op);
	    delete op;
	}
	return dl.toTableOperation();
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

    namespace Debugging {

 	void linkFunctions () {
	    if (false) TTerm::Unbound->str();
	    const TableOperation* op = NULL; if (false) op->str();
	    const TriplePattern* tp = NULL; if (false) tp->str();
	    const Expression* exp = NULL; if (false) exp->str();
	    const RdfDB* db = NULL; if (false) db->str();
	    const TTerm::String2BNode* s2b = NULL; if (false) s2b->str();
	}

    }
} // namespace w3c_sw

