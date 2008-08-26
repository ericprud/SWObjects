/* XMLQueryExpressor.hpp - simple XML serializer for SPARQL compile trees.
 *
 * $Id: XMLQueryExpressor.hpp,v 1.1 2008-08-26 05:30:49 jnorthru Exp $
 */

#ifndef XMLQueryExpressor_H
#define XMLQueryExpressor_H

#include "XMLSerializer.hpp"

using namespace SPARQLfedNS;

class XMLQueryExpressor : public yacker::Expressor {
protected:
    bool createdXMLSerializer;
    bool sparqlx;
    XMLSerializer* xml;
public:
    XMLQueryExpressor (const char* p_tab = "  ", bool p_sparqlx = true) : yacker::Expressor(), createdXMLSerializer(true), sparqlx(p_sparqlx) { xml = new XMLSerializer(p_tab); }
    XMLQueryExpressor (XMLSerializer* p_xml, bool p_sparqlx = true) : yacker::Expressor(), createdXMLSerializer(false), sparqlx(p_sparqlx), xml(p_xml) {  }
    ~XMLQueryExpressor () { if (createdXMLSerializer) delete xml; }
    std::string getXMLstring () { return xml->getXMLstring(); }
    //!!!
    virtual yacker::Base* base (std::string productionName) { throw(std::runtime_error(productionName)); };

    virtual URI* uri (std::string terminal) {
	xml->leaf("uri", terminal);
	return NULL;
    }
    virtual Variable* variable (std::string terminal) {
	xml->empty("variable");
	xml->attribute("name", terminal);
	return NULL;
    }
    virtual BNode* bnode (std::string terminal) {
	xml->leaf("bnode", terminal);
	return NULL;
    }
    virtual RDFLiteral* rdfLiteral (std::string terminal, SPARQLfedNS::URI* datatype, SPARQLfedNS::LANGTAG* p_LANGTAG) {
	xml->leaf("literal", terminal);
	if (datatype != NULL) xml->attribute("xsd:datatype", datatype->getTerminal()); //!!!
	if (p_LANGTAG != NULL) xml->attribute("xml:lang", p_LANGTAG->getTerminal());
	return NULL;
    }
    virtual NumericRDFLiteral* rdfLiteral (int p_value) {
	xml->leaf("literal", p_value);
	xml->attribute("xsd:datatype", "http://www.w3.org/2001/XMLSchema/integer");
	return NULL;
    }
    virtual NumericRDFLiteral* rdfLiteral (float p_value) {
	xml->leaf("literal", p_value);
	xml->attribute("xsd:datatype", "http://www.w3.org/2001/XMLSchema/float");
	return NULL;
    }
    virtual NumericRDFLiteral* rdfLiteral (double p_value) {
	xml->leaf("literal", p_value);
	xml->attribute("xsd:datatype", "http://www.w3.org/2001/XMLSchema/decimal");
	return NULL;
    }
    virtual BooleanRDFLiteral* rdfLiteral (bool p_value) {
	xml->leaf("literal", p_value);
	xml->attribute("xsd:datatype", "http://www.w3.org/2001/XMLSchema/boolean");
	return NULL;
    }
    virtual NULLpos* nullpos () {
	xml->empty("NULL");
	return NULL;
    }
    virtual TriplePattern* triplePattern (SPARQLfedNS::POS* p_s, SPARQLfedNS::POS* p_p, SPARQLfedNS::POS* p_o) {
	xml->open("TriplePattern");
	p_s->express(this);
	p_p->express(this);
	p_o->express(this);
	xml->close();
	return NULL;
    }
    virtual Filter* filter (SPARQLfedNS::Expression* p_Constraint) {
	xml->open("Filter");
	p_Constraint->express(this);
	xml->close();
	return NULL;
    }
    virtual NamedGraphPattern* namedGraphPattern (SPARQLfedNS::POS* p_name, bool p_allOpts, yacker::ProductionVector<SPARQLfedNS::TriplePattern*>* p_TriplePatterns, yacker::ProductionVector<SPARQLfedNS::Filter*>* p_Filters) {
	if (sparqlx)
	    xml->open("BasicGraphPattern");
	else {
	    xml->open("NamedGraphPattern");
	    p_name->express(this);
	}
	if (p_allOpts == true) xml->attribute("allOpts", "allOpts");
	p_TriplePatterns->express(this);
	p_Filters->express(this);
	xml->close();
	return NULL;
    }
    virtual DefaultGraphPattern* defaultGraphPattern (bool p_allOpts, yacker::ProductionVector<SPARQLfedNS::TriplePattern*>* p_TriplePatterns, yacker::ProductionVector<SPARQLfedNS::Filter*>* p_Filters) {
	if (sparqlx)
	    xml->open("BasicGraphPattern");
	else
	    xml->open("DefaultGraphPattern");
	if (p_allOpts == true) xml->attribute("allOpts", "allOpts");
	p_TriplePatterns->express(this);
	p_Filters->express(this);
	xml->close();
	return NULL;
    }
    virtual TableDisjunction* tableDisjunction (yacker::ProductionVector<SPARQLfedNS::TableOperation*>* p_TableOperations, yacker::ProductionVector<SPARQLfedNS::Filter*>* p_Filters) {
	xml->open("TableDisjunction");
	p_TableOperations->express(this);
	p_Filters->express(this);
	xml->close();
	return NULL;
    }
    virtual TableConjunction* tableConjunction (yacker::ProductionVector<SPARQLfedNS::TableOperation*>* p_TableOperations, yacker::ProductionVector<SPARQLfedNS::Filter*>* p_Filters) {
	xml->open("TableConjunction");
	p_TableOperations->express(this);
	p_Filters->express(this);
	xml->close();
	return NULL;
    }
    virtual OptionalGraphPattern* optionalGraphPattern (SPARQLfedNS::TableOperation* p_GroupGraphPattern) {
	xml->open("OptionalGraphPattern");
	p_GroupGraphPattern->express(this);
	xml->close();
	return NULL;
    }
    virtual GraphGraphPattern* graphGraphPattern (SPARQLfedNS::POS* p_POS, SPARQLfedNS::TableOperation* p_GroupGraphPattern) {
	if (sparqlx) {
	    xml->open("GraphGraphPattern");
	    p_POS->express(this);
	    p_GroupGraphPattern->express(this);
	    xml->close();
	} else
	    p_GroupGraphPattern->express(this);
	return NULL;
    }
    virtual POSList* posList (yacker::ProductionVector<SPARQLfedNS::POS*>* p_POSs) {
	xml->open("POSList");
	p_POSs->express(this);
	xml->close();
	return NULL;
    }
    virtual StarVarSet* starVarSet () {
	xml->empty("StarVarSet");
	return NULL;
    }
    virtual DefaultGraphClause* defaultGraphClause (SPARQLfedNS::POS* p_IRIref) {
	xml->open("DefaultGraphClause");
	p_IRIref->express(this);
	xml->close();
	return NULL;
    }
    virtual NamedGraphClause* namedGraphClause (SPARQLfedNS::POS* p_IRIref) {
	xml->open("NamedGraphClause");
	p_IRIref->express(this);
	xml->close();
	return NULL;
    }
    virtual SolutionModifier* solutionModifier (std::vector<SPARQLfedNS::s_OrderConditionPair>* p_OrderConditions, int p_limit, int p_offset) {
	xml->open("SolutionModifier");
	if (p_limit != LIMIT_None) xml->attribute("limit", p_limit);
	if (p_offset != OFFSET_None) xml->attribute("offset", p_offset);
	if (p_OrderConditions)
	    for (size_t i = 0; i < p_OrderConditions->size(); i++) {
		xml->open("Order");
		xml->attribute("", p_OrderConditions->at(i).ascOrDesc == SPARQLfedNS::ORDER_Asc ? "ASK" :  "DESC");
		p_OrderConditions->at(i).expression->express(this);
		xml->close();
	    }
	xml->close();
	return NULL;
    }
    virtual Binding* binding (yacker::ProductionVector<SPARQLfedNS::POS*>* values) {//!!!
	xml->open("BindingClause");
	for (size_t i = 0; i < values->size(); i++)
	    values->at(i)->express(this);
	xml->close();
	return NULL;
    }
    virtual BindingClause* bindingClause (SPARQLfedNS::POSList* p_Vars, yacker::ProductionVector<SPARQLfedNS::Binding*>* p_Bindings) {
	xml->open("BindingClause");
	p_Vars->express(this);
	p_Bindings->yacker::ProductionVector<SPARQLfedNS::Binding*>::express(this);
	xml->close();
	return NULL;
    }
    virtual WhereClause* whereClause (SPARQLfedNS::TableOperation* p_GroupGraphPattern, SPARQLfedNS::BindingClause* p_BindingClause) {
	xml->open("WhereClause");
	p_GroupGraphPattern->express(this);
	if (p_BindingClause) p_BindingClause->express(this);
	xml->close();
	return NULL;
    }
    virtual Select* select (SPARQLfedNS::e_distinctness p_distinctness, SPARQLfedNS::VarSet* p_VarSet, yacker::ProductionVector<SPARQLfedNS::DatasetClause*>* p_DatasetClauses, SPARQLfedNS::WhereClause* p_WhereClause, SPARQLfedNS::SolutionModifier* p_SolutionModifier) {
	xml->open("Select");
	xml->attribute("cardinality", 
		  p_distinctness == SPARQLfedNS::DIST_distinct ? "DISTINCT" :
		  p_distinctness == SPARQLfedNS::DIST_reduced ? "REDUCED" :
		  "ALL");
	p_VarSet->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
	xml->close();
	return NULL;
    }
    virtual Construct* construct (SPARQLfedNS::DefaultGraphPattern* p_ConstructTemplate, yacker::ProductionVector<SPARQLfedNS::DatasetClause*>* p_DatasetClauses, SPARQLfedNS::WhereClause* p_WhereClause, SPARQLfedNS::SolutionModifier* p_SolutionModifier) {
	xml->open("Construct");
	p_ConstructTemplate->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
	xml->close();
	return NULL;
    }
    virtual Describe* describe (SPARQLfedNS::VarSet* p_VarSet, yacker::ProductionVector<SPARQLfedNS::DatasetClause*>* p_DatasetClauses, SPARQLfedNS::WhereClause* p_WhereClause, SPARQLfedNS::SolutionModifier* p_SolutionModifier) {
	xml->open("Describe");
	p_VarSet->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
	xml->close();
	return NULL;
    }
    virtual Ask* ask (yacker::ProductionVector<SPARQLfedNS::DatasetClause*>* p_DatasetClauses, SPARQLfedNS::WhereClause* p_WhereClause) {
	xml->open("Ask");
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	xml->close();
	return NULL;
    }
    virtual Replace* replace (SPARQLfedNS::WhereClause* p_WhereClause, SPARQLfedNS::TableOperation* p_GraphTemplate) {
	xml->open("Replace");
	p_WhereClause->express(this);
	p_GraphTemplate->express(this);
	xml->close();
	return NULL;
    }
    virtual Insert* insert (SPARQLfedNS::TableOperation* p_GraphTemplate, SPARQLfedNS::WhereClause* p_WhereClause) {
	xml->open("Insert");
	p_GraphTemplate->express(this);
	if (p_WhereClause) p_WhereClause->express(this);
	xml->close();
	return NULL;
    }
    virtual Delete* del (SPARQLfedNS::TableOperation* p_GraphTemplate, SPARQLfedNS::WhereClause* p_WhereClause) {
	xml->open("Delete");
	p_GraphTemplate->express(this);
	p_WhereClause->express(this);
	xml->close();
	return NULL;
    }
    virtual Load* load (yacker::ProductionVector<SPARQLfedNS::URI*>* p_IRIrefs, SPARQLfedNS::URI* p_into) {
	xml->open("Load");
	p_IRIrefs->express(this);
	p_into->express(this);
	xml->close();
	return NULL;
    }
    virtual Clear* clear (SPARQLfedNS::URI* p__QGraphIRI_E_Opt) {
	xml->open("Clear");
	p__QGraphIRI_E_Opt->express(this);
	xml->close();
	return NULL;
    }
    virtual Create* create (SPARQLfedNS::e_Silence p_Silence, SPARQLfedNS::URI* p_GraphIRI) {
	xml->open("Create");
	if (p_Silence != SPARQLfedNS::SILENT_Yes) xml->attribute("silent", "YES");
	p_GraphIRI->express(this);
	xml->close();
	return NULL;
    }
    virtual Drop* drop (SPARQLfedNS::e_Silence p_Silence, SPARQLfedNS::URI* p_GraphIRI) {
	xml->open("Drop");
	if (p_Silence != SPARQLfedNS::SILENT_Yes) xml->attribute("silent", "YES");
	p_GraphIRI->express(this);
	xml->close();
	return NULL;
    }
    virtual VarExpression* varExpression (SPARQLfedNS::Variable* p_Variable) {
	xml->open("VarExpression");
	p_Variable->express(this);
	xml->close();
	return NULL;
    }
    virtual LiteralExpression* literalExpression (SPARQLfedNS::RDFLiteral* p_RDFLiteral) {
	xml->open("LiteralExpression");
	p_RDFLiteral->express(this);
	xml->close();
	return NULL;
    }
    virtual BooleanExpression* booleanExpression (SPARQLfedNS::BooleanRDFLiteral* p_BooleanRDFLiteral) {
	xml->open("BooleanExpression");
	p_BooleanRDFLiteral->express(this);
	xml->close();
	return NULL;
    }
    virtual URIExpression* uriExpression (SPARQLfedNS::URI* p_URI) {
	xml->open("URIExpression");
	p_URI->express(this);
	xml->close();
	return NULL;
    }
    virtual ArgList* argList (yacker::ProductionVector<SPARQLfedNS::Expression*>* p__O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C) {
	xml->open("ArgList");
	p__O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C->express(this);
	xml->close();
	return NULL;
    }
    virtual FunctionCall* functionCall (SPARQLfedNS::URI* p_IRIref, SPARQLfedNS::ArgList* p_ArgList) {
	xml->open("FunctionCall");
	p_IRIref->express(this);
	p_ArgList->express(this);
	xml->close();
	return NULL;
    }
    virtual FunctionCallExpression* functionCallExpression (SPARQLfedNS::FunctionCall* p_FunctionCall) {
	xml->open("FunctionCallExpression");
	p_FunctionCall->express(this);
	xml->close();
	return NULL;
    }
/* Expressions */
    virtual BooleanNegation* booleanNegation (SPARQLfedNS::Expression* p_Expression) {
	xml->open("BooleanNegation");
	p_Expression->express(this);
	xml->close();
	return NULL;
    }
    virtual ArithmeticNegation* arithmeticNegation (SPARQLfedNS::Expression* p_Expression) {
	xml->open("ArithmeticNegation");
	p_Expression->express(this);
	xml->close();
	return NULL;
    }
    virtual ArithmeticInverse* arithmeticInverse (SPARQLfedNS::Expression* p_Expression) {
	xml->open("ArithmeticInverse");
	p_Expression->express(this);
	xml->close();
	return NULL;
    }
    virtual BooleanConjunction* booleanConjunction (yacker::ProductionVector<SPARQLfedNS::Expression*>* p_Expressions) {
	xml->open("BooleanConjunction");
	p_Expressions->express(this);
	xml->close();
	return NULL;
    }
    virtual BooleanDisjunction* booleanDisjunction (yacker::ProductionVector<SPARQLfedNS::Expression*>* p_Expressions) {
	xml->open("BooleanDisjunction");
	p_Expressions->express(this);
	xml->close();
	return NULL;
    }
    virtual BooleanNegation* booleanNegation (yacker::ProductionVector<SPARQLfedNS::Expression*>* p_Expressions) {
	xml->open("BooleanNegation");
	p_Expressions->express(this);
	xml->close();
	return NULL;
    }
    virtual ArithmeticSum* arithmeticSum (yacker::ProductionVector<SPARQLfedNS::Expression*>* p_Expressions) {
	xml->open("ArithmeticSum");
	p_Expressions->express(this);
	xml->close();
	return NULL;
    }
    virtual ArithmeticProduct* arithmeticProduct (yacker::ProductionVector<SPARQLfedNS::Expression*>* p_Expressions) {
	xml->open("ArithmeticProduct");
	p_Expressions->express(this);
	xml->close();
	return NULL;
    }
    virtual ArithmeticInverse* arithmeticInverse (yacker::ProductionVector<SPARQLfedNS::Expression*>* p_Expressions) {
	xml->open("ArithmeticInverse");
	p_Expressions->express(this);
	xml->close();
	return NULL;
    }
    virtual BooleanEQ* booleanEQ (SPARQLfedNS::Expression* p_left, SPARQLfedNS::Expression* p_right) {
	xml->open("BooleanEQ");
	p_left->express(this);
	p_right->express(this);
	xml->close();
	return NULL;
    }
    virtual BooleanNE* booleanNE (SPARQLfedNS::Expression* p_left, SPARQLfedNS::Expression* p_right) {
	xml->open("BooleanNE");
	p_left->express(this);
	p_right->express(this);
	xml->close();
	return NULL;
    }
    virtual BooleanLT* booleanLT (SPARQLfedNS::Expression* p_left, SPARQLfedNS::Expression* p_right) {
	xml->open("BooleanLT");
	p_left->express(this);
	p_right->express(this);
	xml->close();
	return NULL;
    }
    virtual BooleanGT* booleanGT (SPARQLfedNS::Expression* p_left, SPARQLfedNS::Expression* p_right) {
	xml->open("BooleanGT");
	p_left->express(this);
	p_right->express(this);
	xml->close();
	return NULL;
    }
    virtual BooleanLE* booleanLE (SPARQLfedNS::Expression* p_left, SPARQLfedNS::Expression* p_right) {
	xml->open("BooleanLE");
	p_left->express(this);
	p_right->express(this);
	xml->close();
	return NULL;
    }
    virtual BooleanGE* booleanGE (SPARQLfedNS::Expression* p_left, SPARQLfedNS::Expression* p_right) {
	xml->open("BooleanGE");
	p_left->express(this);
	p_right->express(this);
	xml->close();
	return NULL;
    }
    virtual ComparatorExpression* comparatorExpression (SPARQLfedNS::BooleanComparator* p_BooleanComparator) {
	xml->open("ComparatorExpression");
	p_BooleanComparator->express(this);
	xml->close();
	return NULL;
    }
    virtual NumberExpression* numberExpression (SPARQLfedNS::NumericRDFLiteral* p_NumericRDFLiteral) {
	xml->open("NumberExpression");
	p_NumericRDFLiteral->express(this);
	xml->close();
	return NULL;
    }
};

#endif // XMLQueryExpressor_H

