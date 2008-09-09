/* SWObjects: components for capturing and manipulating compile trees of RDF
   languages. This should capture all of SPARQL and most of N3 (no graphs as
   parts of an RDF triple).

 * $Id: SWObjects.cpp,v 1.4 2008-09-09 09:36:27 eric Exp $
 */

#include "SWObjects.hpp"
#include "ResultSet.hpp"
#include "TurtleSParser.hpp"
#include <string.h>
#include "SPARQLSerializer.hpp"

namespace w3c_sw {

Base* Base::express (Expressor* p_expressor) {
    return p_expressor->base(typeid(*this).name());
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
		p = -1;

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

URI* URI::express (Expressor* p_expressor) {
    return p_expressor->uri(terminal);
}
Variable* Variable::express (Expressor* p_expressor) {
    return p_expressor->variable(terminal);
}
BNode* BNode::express (Expressor* p_expressor) {
    return p_expressor->bnode(terminal);
}
RDFLiteral* RDFLiteral::express (Expressor* p_expressor) {
    return p_expressor->rdfLiteral(m_String, datatype, m_LANGTAG);
}
NumericRDFLiteral* IntegerRDFLiteral::express (Expressor* p_expressor) {
    return p_expressor->rdfLiteral(m_value);
}
NumericRDFLiteral* DecimalRDFLiteral::express (Expressor* p_expressor) {
    return p_expressor->rdfLiteral(m_value);
}
NumericRDFLiteral* DoubleRDFLiteral::express (Expressor* p_expressor) {
    return p_expressor->rdfLiteral(m_value);
}
BooleanRDFLiteral* BooleanRDFLiteral::express (Expressor* p_expressor) {
    return p_expressor->rdfLiteral(m_value);
}
NULLpos* NULLpos::express (Expressor* p_expressor) {
    return p_expressor->nullpos();
}
TriplePattern* TriplePattern::express (Expressor* p_expressor) {
    return p_expressor->triplePattern(m_s,m_p,m_o);
}
Filter* Filter::express (Expressor* p_expressor) {
    return p_expressor->filter(m_Constraint);
}
NamedGraphPattern* NamedGraphPattern::express (Expressor* p_expressor) {
    return p_expressor->namedGraphPattern(m_name, allOpts, &m_TriplePatterns, &m_Filters);
}
DefaultGraphPattern* DefaultGraphPattern::express (Expressor* p_expressor) {
    return p_expressor->defaultGraphPattern(allOpts, &m_TriplePatterns, &m_Filters);
}
TableDisjunction* TableDisjunction::express (Expressor* p_expressor) {
    return p_expressor->tableDisjunction(&m_TableOperations, &m_Filters);
}
TableConjunction* TableConjunction::express (Expressor* p_expressor) {
    return p_expressor->tableConjunction(&m_TableOperations, &m_Filters);
}
OptionalGraphPattern* OptionalGraphPattern::express (Expressor* p_expressor) {
    return p_expressor->optionalGraphPattern(m_TableOperation);
}
GraphGraphPattern* GraphGraphPattern::express (Expressor* p_expressor) {
    return p_expressor->graphGraphPattern(m_VarOrIRIref, m_TableOperation);
}
POSList* POSList::express (Expressor* p_expressor) {
    return p_expressor->posList(&m_POSs);
}
StarVarSet* StarVarSet::express (Expressor* p_expressor) {
    return p_expressor->starVarSet();
}
DefaultGraphClause* DefaultGraphClause::express (Expressor* p_expressor) {
    return p_expressor->defaultGraphClause(m_IRIref);
}
NamedGraphClause* NamedGraphClause::express (Expressor* p_expressor) {
    return p_expressor->namedGraphClause(m_IRIref);
}
SolutionModifier* SolutionModifier::express (Expressor* p_expressor) {
    return p_expressor->solutionModifier(m_OrderConditions, m_limit,m_offset);
}
Binding* Binding::express (Expressor* p_expressor) {
    return p_expressor->binding(this);
}
BindingClause* BindingClause::express (Expressor* p_expressor) {
    return p_expressor->bindingClause(m_Vars, this);
}
WhereClause* WhereClause::express (Expressor* p_expressor) {
    return p_expressor->whereClause(m_GroupGraphPattern,m_BindingClause);
}
Select* Select::express (Expressor* p_expressor) {
    return p_expressor->select(m_distinctness, m_VarSet, m_DatasetClauses, m_WhereClause,m_SolutionModifier);
}
Construct* Construct::express (Expressor* p_expressor) {
    return p_expressor->construct(m_ConstructTemplate, m_DatasetClauses, m_WhereClause,m_SolutionModifier);
}
Describe* Describe::express (Expressor* p_expressor) {
    return p_expressor->describe(m_VarSet, m_DatasetClauses, m_WhereClause,m_SolutionModifier);
}
Ask* Ask::express (Expressor* p_expressor) {
    return p_expressor->ask(m_DatasetClauses,m_WhereClause);
}
Replace* Replace::express (Expressor* p_expressor) {
    return p_expressor->replace(m_WhereClause,m_GraphTemplate);
}
Insert* Insert::express (Expressor* p_expressor) {
    return p_expressor->insert(m_GraphTemplate,m_WhereClause);
}
Delete* Delete::express (Expressor* p_expressor) {
    return p_expressor->del(m_GraphTemplate,m_WhereClause);
}
Load* Load::express (Expressor* p_expressor) {
    return p_expressor->load(m_IRIrefs,m_into);
}
Clear* Clear::express (Expressor* p_expressor) {
    return p_expressor->clear(m__QGraphIRI_E_Opt);
}
Create* Create::express (Expressor* p_expressor) {
    return p_expressor->create(m_Silence,m_GraphIRI);
}
Drop* Drop::express (Expressor* p_expressor) {
    return p_expressor->drop(m_Silence,m_GraphIRI);
}
VarExpression* VarExpression::express (Expressor* p_expressor) {
    return p_expressor->varExpression(m_Variable);
}
LiteralExpression* LiteralExpression::express (Expressor* p_expressor) {
    return p_expressor->literalExpression(m_RDFLiteral);
}
BooleanExpression* BooleanExpression::express (Expressor* p_expressor) {
    return p_expressor->booleanExpression(m_BooleanRDFLiteral);
}
URIExpression* URIExpression::express (Expressor* p_expressor) {
    return p_expressor->uriExpression(m_URI);
}
ArgList* ArgList::express (Expressor* p_expressor) {
    return p_expressor->argList(m__O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C);
}
FunctionCall* FunctionCall::express (Expressor* p_expressor) {
    return p_expressor->functionCall(m_IRIref,m_ArgList);
}
FunctionCallExpression* FunctionCallExpression::express (Expressor* p_expressor) {
    return p_expressor->functionCallExpression(m_FunctionCall);
}
/* Expressions */
BooleanNegation* BooleanNegation::express (Expressor* p_expressor) {
    return p_expressor->booleanNegation(m_Expression);
}
ArithmeticNegation* ArithmeticNegation::express (Expressor* p_expressor) {
    return p_expressor->arithmeticNegation(m_Expression);
}
ArithmeticInverse* ArithmeticInverse::express (Expressor* p_expressor) {
    return p_expressor->arithmeticInverse(m_Expression);
}
BooleanConjunction* BooleanConjunction::express (Expressor* p_expressor) {
    return p_expressor->booleanConjunction(&m_Expressions);
}
BooleanDisjunction* BooleanDisjunction::express (Expressor* p_expressor) {
    return p_expressor->booleanDisjunction(&m_Expressions);
}
ArithmeticSum* ArithmeticSum::express (Expressor* p_expressor) {
    return p_expressor->arithmeticSum(&m_Expressions);
}
ArithmeticProduct* ArithmeticProduct::express (Expressor* p_expressor) {
    return p_expressor->arithmeticProduct(&m_Expressions);
}
BooleanEQ* BooleanEQ::express (Expressor* p_expressor) {
    return p_expressor->booleanEQ(left,right);
}
BooleanNE* BooleanNE::express (Expressor* p_expressor) {
    return p_expressor->booleanNE(left,right);
}
BooleanLT* BooleanLT::express (Expressor* p_expressor) {
    return p_expressor->booleanLT(left,right);
}
BooleanGT* BooleanGT::express (Expressor* p_expressor) {
    return p_expressor->booleanGT(left,right);
}
BooleanLE* BooleanLE::express (Expressor* p_expressor) {
    return p_expressor->booleanLE(left,right);
}
BooleanGE* BooleanGE::express (Expressor* p_expressor) {
    return p_expressor->booleanGE(left,right);
}
ComparatorExpression* ComparatorExpression::express (Expressor* p_expressor) {
    return p_expressor->comparatorExpression(m_BooleanComparator);
}
NumberExpression* NumberExpression::express (Expressor* p_expressor) {
    return p_expressor->numberExpression(m_NumericRDFLiteral);
}


    POSsorter* ThePOSsorter;

    POSFactory::~POSFactory () {

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

	char space[LEN_XSD+strlen(type)+1];
	strcpy(space, XSD);
	strcpy(space+LEN_XSD-1, type);
	URI* uri = getURI(space);

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

    bool Bindable::bindVariable (const POS* p, ResultSet* rs, Result* provisional, bool weaklyBound) const {
	POS* curVal = provisional->get(this);
	if (curVal == NULL) {
	    rs->set(provisional, this, p, weaklyBound);
	    return true;
	}
	bool ret = typeid(*p) == typeid(*curVal) && p->getTerminal() == curVal->getTerminal();
	//SPARQLSerializer s, s2; ((POS*)curVal)->express(&s); std::cerr << "   " << s.getSPARQLstring() << " == "; ((POS*)p)->express(&s2); std::cerr << s2.getSPARQLstring() << " : " << ret << std::endl;
	return ret;
    }
    POS* Variable::eval (Result* r) {
	return r->get(this);
    }

    ResultSet* Select::execute (RdfDB* db, ResultSet* rs) {
	if (!rs) rs = new ResultSet();
	for (std::vector<DatasetClause*>::iterator ds = m_DatasetClauses->begin();
	     ds != m_DatasetClauses->end(); ds++)
	    (*ds)->loadData(db);
	m_WhereClause->bindVariables(db, rs);
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
	SPARQLSerializer s; g.express(&s); std::cerr << "CONSTRUCTED: " << s.getSPARQLstring() << std::endl;
	return rs;
    }

    void DatasetClause::_loadData (BasicGraphPattern* target) {
	TurtleSDriver turtleParser("http://example.org/", m_posFactory);
	if (turtleParser.parse_file(m_IRIref->getTerminal())) {
	    std::cerr << m_IRIref->getTerminal() << ":0: error: unable to parse document" << std::endl;
	} else {
	    DefaultGraphPattern* graph = turtleParser.root;
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
		(*row)->duplicate(rs, rs->end());
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
	bool matched = true;
	for (std::vector<TriplePattern*>::iterator constraint = toMatch->m_TriplePatterns.begin();
	     constraint != toMatch->m_TriplePatterns.end() && (matched || toMatch->allOpts); constraint++) {
	    for (ResultSetIterator row = rs->begin() ; row != rs->end(); ) {
		matched = false;
		for (std::vector<TriplePattern*>::iterator triple = m_TriplePatterns.begin();
		     triple != m_TriplePatterns.end(); triple++)
		    matched |= (*triple)->bindVariables(*constraint, toMatch->allOpts, rs, graphVar, row, graphName);
		delete *row;
		rs->erase(row++);
	    }
	}
    }
    bool TriplePattern::bindVariables (TriplePattern* tp, bool optional, ResultSet* rs, POS* graphVar, ResultSetIterator row, POS* graphName) {
	bool ret = false;
	Result* r = *row; // convenience variable.
	ResultSetIterator newIt = r->duplicate(rs, row);
	Result* newRow = *newIt;
	if (graphVar->bindVariable(graphName, rs, newRow, weaklyBound) && 
	    tp->m_s->bindVariable(m_s, rs, newRow, weaklyBound) && 
	    tp->m_p->bindVariable(m_p, rs, newRow, weaklyBound) && 
	    tp->m_o->bindVariable(m_o, rs, newRow, weaklyBound))
	    ret = true;
	else if (!optional)
	    rs->remove(newIt, *newIt);
	return ret;
    }

    void OptionalGraphPattern::bindVariables (RdfDB* db, ResultSet* rs) {
	for (ResultSetIterator row = rs->begin() ; row != rs->end(); ) {
	    ResultSet* rowRS = (*row)->makeResultSet();
	    m_TableOperation->bindVariables(db, rowRS);
	    bool empty = true;
	    for (ResultSetIterator optRow = rowRS->begin() ; optRow != rowRS->end(); ) {
		empty = false;
		ResultSetIterator newIt = (*row)->duplicate(rs, row);
		(*newIt)->assumeNewBindings(*optRow);
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
		(*triple)->construct(target, *result);
    }

    bool TriplePattern::construct (BasicGraphPattern* target, Result* r) {
	bool ret = false;
	POS *s, *p, *o;
	if ((s = m_s->eval(r)) != NULL && 
	    (p = m_p->eval(r)) != NULL && 
	    (o = m_o->eval(r)) != NULL)
	    target->addTriplePattern(s, p, o);
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

} // namespace w3c_sw

