/* XMLQueryExpressor.hpp - simple XML serializer for SPARQL compile trees.
 *
 * $Id: XMLQueryExpressor.hpp,v 1.2 2008-08-27 02:21:43 eric Exp $
 */

#ifndef XMLQueryExpressor_H
#define XMLQueryExpressor_H

#include "XMLSerializer.hpp"

using namespace w3c_sw;

class XMLQueryExpressor : public Expressor {
protected:
    bool createdXMLSerializer;
    bool sparqlx;
    XMLSerializer* xml;
public:
    XMLQueryExpressor (const char* p_tab = "  ", bool p_sparqlx = true) : Expressor(), createdXMLSerializer(true), sparqlx(p_sparqlx) { xml = new XMLSerializer(p_tab); }
    XMLQueryExpressor (XMLSerializer* p_xml, bool p_sparqlx = true) : Expressor(), createdXMLSerializer(false), sparqlx(p_sparqlx), xml(p_xml) {  }
    ~XMLQueryExpressor () { if (createdXMLSerializer) delete xml; }
    std::string getXMLstring () { return xml->getXMLstring(); }
    //!!!
    virtual Base* base (std::string productionName) { throw(std::runtime_error(productionName)); };

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
    virtual RDFLiteral* rdfLiteral (std::string terminal, w3c_sw::URI* datatype, w3c_sw::LANGTAG* p_LANGTAG) {
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
    virtual TriplePattern* triplePattern (w3c_sw::POS* p_s, w3c_sw::POS* p_p, w3c_sw::POS* p_o) {
	xml->open("TriplePattern");
	p_s->express(this);
	p_p->express(this);
	p_o->express(this);
	xml->close();
	return NULL;
    }
    virtual Filter* filter (w3c_sw::Expression* p_Constraint) {
	xml->open("Filter");
	p_Constraint->express(this);
	xml->close();
	return NULL;
    }
    virtual NamedGraphPattern* namedGraphPattern (w3c_sw::POS* p_name, bool p_allOpts, ProductionVector<w3c_sw::TriplePattern*>* p_TriplePatterns, ProductionVector<w3c_sw::Filter*>* p_Filters) {
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
    virtual DefaultGraphPattern* defaultGraphPattern (bool p_allOpts, ProductionVector<w3c_sw::TriplePattern*>* p_TriplePatterns, ProductionVector<w3c_sw::Filter*>* p_Filters) {
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
    virtual TableDisjunction* tableDisjunction (ProductionVector<w3c_sw::TableOperation*>* p_TableOperations, ProductionVector<w3c_sw::Filter*>* p_Filters) {
	xml->open("TableDisjunction");
	p_TableOperations->express(this);
	p_Filters->express(this);
	xml->close();
	return NULL;
    }
    virtual TableConjunction* tableConjunction (ProductionVector<w3c_sw::TableOperation*>* p_TableOperations, ProductionVector<w3c_sw::Filter*>* p_Filters) {
	xml->open("TableConjunction");
	p_TableOperations->express(this);
	p_Filters->express(this);
	xml->close();
	return NULL;
    }
    virtual OptionalGraphPattern* optionalGraphPattern (w3c_sw::TableOperation* p_GroupGraphPattern) {
	xml->open("OptionalGraphPattern");
	p_GroupGraphPattern->express(this);
	xml->close();
	return NULL;
    }
    virtual GraphGraphPattern* graphGraphPattern (w3c_sw::POS* p_POS, w3c_sw::TableOperation* p_GroupGraphPattern) {
	if (sparqlx) {
	    xml->open("GraphGraphPattern");
	    p_POS->express(this);
	    p_GroupGraphPattern->express(this);
	    xml->close();
	} else
	    p_GroupGraphPattern->express(this);
	return NULL;
    }
    virtual POSList* posList (ProductionVector<w3c_sw::POS*>* p_POSs) {
	xml->open("POSList");
	p_POSs->express(this);
	xml->close();
	return NULL;
    }
    virtual StarVarSet* starVarSet () {
	xml->empty("StarVarSet");
	return NULL;
    }
    virtual DefaultGraphClause* defaultGraphClause (w3c_sw::POS* p_IRIref) {
	xml->open("DefaultGraphClause");
	p_IRIref->express(this);
	xml->close();
	return NULL;
    }
    virtual NamedGraphClause* namedGraphClause (w3c_sw::POS* p_IRIref) {
	xml->open("NamedGraphClause");
	p_IRIref->express(this);
	xml->close();
	return NULL;
    }
    virtual SolutionModifier* solutionModifier (std::vector<w3c_sw::s_OrderConditionPair>* p_OrderConditions, int p_limit, int p_offset) {
	xml->open("SolutionModifier");
	if (p_limit != LIMIT_None) xml->attribute("limit", p_limit);
	if (p_offset != OFFSET_None) xml->attribute("offset", p_offset);
	if (p_OrderConditions)
	    for (size_t i = 0; i < p_OrderConditions->size(); i++) {
		xml->open("Order");
		xml->attribute("", p_OrderConditions->at(i).ascOrDesc == w3c_sw::ORDER_Asc ? "ASK" :  "DESC");
		p_OrderConditions->at(i).expression->express(this);
		xml->close();
	    }
	xml->close();
	return NULL;
    }
    virtual Binding* binding (ProductionVector<w3c_sw::POS*>* values) {//!!!
	xml->open("BindingClause");
	for (size_t i = 0; i < values->size(); i++)
	    values->at(i)->express(this);
	xml->close();
	return NULL;
    }
    virtual BindingClause* bindingClause (w3c_sw::POSList* p_Vars, ProductionVector<w3c_sw::Binding*>* p_Bindings) {
	xml->open("BindingClause");
	p_Vars->express(this);
	p_Bindings->ProductionVector<w3c_sw::Binding*>::express(this);
	xml->close();
	return NULL;
    }
    virtual WhereClause* whereClause (w3c_sw::TableOperation* p_GroupGraphPattern, w3c_sw::BindingClause* p_BindingClause) {
	xml->open("WhereClause");
	p_GroupGraphPattern->express(this);
	if (p_BindingClause) p_BindingClause->express(this);
	xml->close();
	return NULL;
    }
    virtual Select* select (w3c_sw::e_distinctness p_distinctness, w3c_sw::VarSet* p_VarSet, ProductionVector<w3c_sw::DatasetClause*>* p_DatasetClauses, w3c_sw::WhereClause* p_WhereClause, w3c_sw::SolutionModifier* p_SolutionModifier) {
	xml->open("Select");
	xml->attribute("cardinality", 
		  p_distinctness == w3c_sw::DIST_distinct ? "DISTINCT" :
		  p_distinctness == w3c_sw::DIST_reduced ? "REDUCED" :
		  "ALL");
	p_VarSet->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
	xml->close();
	return NULL;
    }
    virtual Construct* construct (w3c_sw::DefaultGraphPattern* p_ConstructTemplate, ProductionVector<w3c_sw::DatasetClause*>* p_DatasetClauses, w3c_sw::WhereClause* p_WhereClause, w3c_sw::SolutionModifier* p_SolutionModifier) {
	xml->open("Construct");
	p_ConstructTemplate->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
	xml->close();
	return NULL;
    }
    virtual Describe* describe (w3c_sw::VarSet* p_VarSet, ProductionVector<w3c_sw::DatasetClause*>* p_DatasetClauses, w3c_sw::WhereClause* p_WhereClause, w3c_sw::SolutionModifier* p_SolutionModifier) {
	xml->open("Describe");
	p_VarSet->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
	xml->close();
	return NULL;
    }
    virtual Ask* ask (ProductionVector<w3c_sw::DatasetClause*>* p_DatasetClauses, w3c_sw::WhereClause* p_WhereClause) {
	xml->open("Ask");
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	xml->close();
	return NULL;
    }
    virtual Replace* replace (w3c_sw::WhereClause* p_WhereClause, w3c_sw::TableOperation* p_GraphTemplate) {
	xml->open("Replace");
	p_WhereClause->express(this);
	p_GraphTemplate->express(this);
	xml->close();
	return NULL;
    }
    virtual Insert* insert (w3c_sw::TableOperation* p_GraphTemplate, w3c_sw::WhereClause* p_WhereClause) {
	xml->open("Insert");
	p_GraphTemplate->express(this);
	if (p_WhereClause) p_WhereClause->express(this);
	xml->close();
	return NULL;
    }
    virtual Delete* del (w3c_sw::TableOperation* p_GraphTemplate, w3c_sw::WhereClause* p_WhereClause) {
	xml->open("Delete");
	p_GraphTemplate->express(this);
	p_WhereClause->express(this);
	xml->close();
	return NULL;
    }
    virtual Load* load (ProductionVector<w3c_sw::URI*>* p_IRIrefs, w3c_sw::URI* p_into) {
	xml->open("Load");
	p_IRIrefs->express(this);
	p_into->express(this);
	xml->close();
	return NULL;
    }
    virtual Clear* clear (w3c_sw::URI* p__QGraphIRI_E_Opt) {
	xml->open("Clear");
	p__QGraphIRI_E_Opt->express(this);
	xml->close();
	return NULL;
    }
    virtual Create* create (w3c_sw::e_Silence p_Silence, w3c_sw::URI* p_GraphIRI) {
	xml->open("Create");
	if (p_Silence != w3c_sw::SILENT_Yes) xml->attribute("silent", "YES");
	p_GraphIRI->express(this);
	xml->close();
	return NULL;
    }
    virtual Drop* drop (w3c_sw::e_Silence p_Silence, w3c_sw::URI* p_GraphIRI) {
	xml->open("Drop");
	if (p_Silence != w3c_sw::SILENT_Yes) xml->attribute("silent", "YES");
	p_GraphIRI->express(this);
	xml->close();
	return NULL;
    }
    virtual VarExpression* varExpression (w3c_sw::Variable* p_Variable) {
	xml->open("VarExpression");
	p_Variable->express(this);
	xml->close();
	return NULL;
    }
    virtual LiteralExpression* literalExpression (w3c_sw::RDFLiteral* p_RDFLiteral) {
	xml->open("LiteralExpression");
	p_RDFLiteral->express(this);
	xml->close();
	return NULL;
    }
    virtual BooleanExpression* booleanExpression (w3c_sw::BooleanRDFLiteral* p_BooleanRDFLiteral) {
	xml->open("BooleanExpression");
	p_BooleanRDFLiteral->express(this);
	xml->close();
	return NULL;
    }
    virtual URIExpression* uriExpression (w3c_sw::URI* p_URI) {
	xml->open("URIExpression");
	p_URI->express(this);
	xml->close();
	return NULL;
    }
    virtual ArgList* argList (ProductionVector<w3c_sw::Expression*>* p__O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C) {
	xml->open("ArgList");
	p__O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C->express(this);
	xml->close();
	return NULL;
    }
    virtual FunctionCall* functionCall (w3c_sw::URI* p_IRIref, w3c_sw::ArgList* p_ArgList) {
	xml->open("FunctionCall");
	p_IRIref->express(this);
	p_ArgList->express(this);
	xml->close();
	return NULL;
    }
    virtual FunctionCallExpression* functionCallExpression (w3c_sw::FunctionCall* p_FunctionCall) {
	xml->open("FunctionCallExpression");
	p_FunctionCall->express(this);
	xml->close();
	return NULL;
    }
/* Expressions */
    virtual BooleanNegation* booleanNegation (w3c_sw::Expression* p_Expression) {
	xml->open("BooleanNegation");
	p_Expression->express(this);
	xml->close();
	return NULL;
    }
    virtual ArithmeticNegation* arithmeticNegation (w3c_sw::Expression* p_Expression) {
	xml->open("ArithmeticNegation");
	p_Expression->express(this);
	xml->close();
	return NULL;
    }
    virtual ArithmeticInverse* arithmeticInverse (w3c_sw::Expression* p_Expression) {
	xml->open("ArithmeticInverse");
	p_Expression->express(this);
	xml->close();
	return NULL;
    }
    virtual BooleanConjunction* booleanConjunction (ProductionVector<w3c_sw::Expression*>* p_Expressions) {
	xml->open("BooleanConjunction");
	p_Expressions->express(this);
	xml->close();
	return NULL;
    }
    virtual BooleanDisjunction* booleanDisjunction (ProductionVector<w3c_sw::Expression*>* p_Expressions) {
	xml->open("BooleanDisjunction");
	p_Expressions->express(this);
	xml->close();
	return NULL;
    }
    virtual BooleanNegation* booleanNegation (ProductionVector<w3c_sw::Expression*>* p_Expressions) {
	xml->open("BooleanNegation");
	p_Expressions->express(this);
	xml->close();
	return NULL;
    }
    virtual ArithmeticSum* arithmeticSum (ProductionVector<w3c_sw::Expression*>* p_Expressions) {
	xml->open("ArithmeticSum");
	p_Expressions->express(this);
	xml->close();
	return NULL;
    }
    virtual ArithmeticProduct* arithmeticProduct (ProductionVector<w3c_sw::Expression*>* p_Expressions) {
	xml->open("ArithmeticProduct");
	p_Expressions->express(this);
	xml->close();
	return NULL;
    }
    virtual ArithmeticInverse* arithmeticInverse (ProductionVector<w3c_sw::Expression*>* p_Expressions) {
	xml->open("ArithmeticInverse");
	p_Expressions->express(this);
	xml->close();
	return NULL;
    }
    virtual BooleanEQ* booleanEQ (w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) {
	xml->open("BooleanEQ");
	p_left->express(this);
	p_right->express(this);
	xml->close();
	return NULL;
    }
    virtual BooleanNE* booleanNE (w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) {
	xml->open("BooleanNE");
	p_left->express(this);
	p_right->express(this);
	xml->close();
	return NULL;
    }
    virtual BooleanLT* booleanLT (w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) {
	xml->open("BooleanLT");
	p_left->express(this);
	p_right->express(this);
	xml->close();
	return NULL;
    }
    virtual BooleanGT* booleanGT (w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) {
	xml->open("BooleanGT");
	p_left->express(this);
	p_right->express(this);
	xml->close();
	return NULL;
    }
    virtual BooleanLE* booleanLE (w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) {
	xml->open("BooleanLE");
	p_left->express(this);
	p_right->express(this);
	xml->close();
	return NULL;
    }
    virtual BooleanGE* booleanGE (w3c_sw::Expression* p_left, w3c_sw::Expression* p_right) {
	xml->open("BooleanGE");
	p_left->express(this);
	p_right->express(this);
	xml->close();
	return NULL;
    }
    virtual ComparatorExpression* comparatorExpression (w3c_sw::BooleanComparator* p_BooleanComparator) {
	xml->open("ComparatorExpression");
	p_BooleanComparator->express(this);
	xml->close();
	return NULL;
    }
    virtual NumberExpression* numberExpression (w3c_sw::NumericRDFLiteral* p_NumericRDFLiteral) {
	xml->open("NumberExpression");
	p_NumericRDFLiteral->express(this);
	xml->close();
	return NULL;
    }
};

#endif // XMLQueryExpressor_H

