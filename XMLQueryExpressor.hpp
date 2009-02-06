/* XMLQueryExpressor.hpp - simple XML serializer for SPARQL compile trees.
 *
 * $Id: XMLQueryExpressor.hpp,v 1.3 2008-09-13 05:17:31 eric Exp $
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
    virtual void base (Base*, std::string productionName) { throw(std::runtime_error(productionName)); };

    virtual void uri (URI*, std::string terminal) {
	xml->leaf("uri", terminal);
    }
    virtual void variable (Variable*, std::string terminal) {
	xml->empty("variable");
	xml->attribute("name", terminal);
    }
    virtual void bnode (BNode*, std::string terminal) {
	xml->leaf("bnode", terminal);
    }
    virtual void rdfLiteral (RDFLiteral*, std::string terminal, URI* datatype, LANGTAG* p_LANGTAG) {
	xml->leaf("literal", terminal);
	if (datatype != NULL) xml->attribute("xsd:datatype", datatype->getTerminal()); //!!!
	if (p_LANGTAG != NULL) xml->attribute("xml:lang", p_LANGTAG->getTerminal());
    }
    virtual void rdfLiteral (NumericRDFLiteral*, int p_value) {
	xml->leaf("literal", p_value);
	xml->attribute("xsd:datatype", "http://www.w3.org/2001/XMLSchema/integer");
    }
    virtual void rdfLiteral (NumericRDFLiteral*, float p_value) {
	xml->leaf("literal", p_value);
	xml->attribute("xsd:datatype", "http://www.w3.org/2001/XMLSchema/float");
    }
    virtual void rdfLiteral (NumericRDFLiteral*, double p_value) {
	xml->leaf("literal", p_value);
	xml->attribute("xsd:datatype", "http://www.w3.org/2001/XMLSchema/decimal");
    }
    virtual void rdfLiteral (BooleanRDFLiteral*, bool p_value) {
	xml->leaf("literal", p_value);
	xml->attribute("xsd:datatype", "http://www.w3.org/2001/XMLSchema/boolean");
    }
    virtual void nullpos (NULLpos*) {
	xml->empty("NULL");
    }
    virtual void triplePattern (TriplePattern*, POS* p_s, POS* p_p, POS* p_o) {
	xml->open("TriplePattern");
	p_s->express(this);
	p_p->express(this);
	p_o->express(this);
	xml->close();
    }
    virtual void filter (Filter*, Expression* p_Constraint) {
	xml->open("Filter");
	p_Constraint->express(this);
	xml->close();
    }
    virtual void namedGraphPattern (NamedGraphPattern*, POS* p_name, bool p_allOpts, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
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
    }
    virtual void defaultGraphPattern (DefaultGraphPattern*, bool p_allOpts, ProductionVector<TriplePattern*>* p_TriplePatterns, ProductionVector<Filter*>* p_Filters) {
	if (sparqlx)
	    xml->open("BasicGraphPattern");
	else
	    xml->open("DefaultGraphPattern");
	if (p_allOpts == true) xml->attribute("allOpts", "allOpts");
	p_TriplePatterns->express(this);
	p_Filters->express(this);
	xml->close();
    }
    virtual void tableDisjunction (TableDisjunction*, ProductionVector<TableOperation*>* p_TableOperations, ProductionVector<Filter*>* p_Filters) {
	xml->open("TableDisjunction");
	p_TableOperations->express(this);
	p_Filters->express(this);
	xml->close();
    }
    virtual void tableConjunction (TableConjunction*, ProductionVector<TableOperation*>* p_TableOperations, ProductionVector<Filter*>* p_Filters) {
	xml->open("TableConjunction");
	p_TableOperations->express(this);
	p_Filters->express(this);
	xml->close();
    }
    virtual void optionalGraphPattern (OptionalGraphPattern*, TableOperation* p_GroupGraphPattern) {
	xml->open("OptionalGraphPattern");
	p_GroupGraphPattern->express(this);
	xml->close();
    }
    virtual void graphGraphPattern (GraphGraphPattern*, POS* p_POS, TableOperation* p_GroupGraphPattern) {
	if (sparqlx) {
	    xml->open("GraphGraphPattern");
	    p_POS->express(this);
	    p_GroupGraphPattern->express(this);
	    xml->close();
	} else
	    p_GroupGraphPattern->express(this);
    }
    virtual void posList (POSList*, ProductionVector<POS*>* p_POSs) {
	xml->open("POSList");
	p_POSs->express(this);
	xml->close();
    }
    virtual void starVarSet (StarVarSet*) {
	xml->empty("StarVarSet");
    }
    virtual void defaultGraphClause (DefaultGraphClause*, POS* p_IRIref) {
	xml->open("DefaultGraphClause");
	p_IRIref->express(this);
	xml->close();
    }
    virtual void namedGraphClause (NamedGraphClause*, POS* p_IRIref) {
	xml->open("NamedGraphClause");
	p_IRIref->express(this);
	xml->close();
    }
    virtual void solutionModifier (SolutionModifier*, std::vector<s_OrderConditionPair>* p_OrderConditions, int p_limit, int p_offset) {
	xml->open("SolutionModifier");
	if (p_limit != LIMIT_None) xml->attribute("limit", p_limit);
	if (p_offset != OFFSET_None) xml->attribute("offset", p_offset);
	if (p_OrderConditions)
	    for (size_t i = 0; i < p_OrderConditions->size(); i++) {
		xml->open("Order");
		xml->attribute("", p_OrderConditions->at(i).ascOrDesc == ORDER_Asc ? "ASK" :  "DESC");
		p_OrderConditions->at(i).expression->express(this);
		xml->close();
	    }
	xml->close();
    }
    virtual void binding (Binding*, ProductionVector<POS*>* values) {//!!!
	xml->open("BindingClause");
	for (std::vector<POS*>::iterator it = values->begin();
	     it != values->end(); ++it)
	    (*it)->express(this);
	xml->close();
    }
    virtual void bindingClause (BindingClause*, POSList* p_Vars, ProductionVector<Binding*>* p_Bindings) {
	xml->open("BindingClause");
	p_Vars->express(this);
	p_Bindings->ProductionVector<Binding*>::express(this);
	xml->close();
    }
    virtual void whereClause (WhereClause*, TableOperation* p_GroupGraphPattern, BindingClause* p_BindingClause) {
	xml->open("WhereClause");
	p_GroupGraphPattern->express(this);
	if (p_BindingClause) p_BindingClause->express(this);
	xml->close();
    }
    virtual void select (Select*, e_distinctness p_distinctness, VarSet* p_VarSet, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	xml->open("Select");
	xml->attribute("cardinality", 
		  p_distinctness == DIST_distinct ? "DISTINCT" :
		  p_distinctness == DIST_reduced ? "REDUCED" :
		  "ALL");
	p_VarSet->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
	xml->close();
    }
    virtual void construct (Construct*, DefaultGraphPattern* p_ConstructTemplate, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	xml->open("Construct");
	p_ConstructTemplate->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
	xml->close();
    }
    virtual void describe (Describe*, VarSet* p_VarSet, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	xml->open("Describe");
	p_VarSet->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
	xml->close();
    }
    virtual void ask (Ask*, ProductionVector<DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause) {
	xml->open("Ask");
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	xml->close();
    }
    virtual void replace (Replace*, WhereClause* p_WhereClause, TableOperation* p_GraphTemplate) {
	xml->open("Replace");
	p_WhereClause->express(this);
	p_GraphTemplate->express(this);
	xml->close();
    }
    virtual void insert (Insert*, TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	xml->open("Insert");
	p_GraphTemplate->express(this);
	if (p_WhereClause) p_WhereClause->express(this);
	xml->close();
    }
    virtual void del (Delete*, TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	xml->open("Delete");
	p_GraphTemplate->express(this);
	p_WhereClause->express(this);
	xml->close();
    }
    virtual void load (Load*, ProductionVector<URI*>* p_IRIrefs, URI* p_into) {
	xml->open("Load");
	p_IRIrefs->express(this);
	p_into->express(this);
	xml->close();
    }
    virtual void clear (Clear*, URI* p__QGraphIRI_E_Opt) {
	xml->open("Clear");
	p__QGraphIRI_E_Opt->express(this);
	xml->close();
    }
    virtual void create (Create*, e_Silence p_Silence, URI* p_GraphIRI) {
	xml->open("Create");
	if (p_Silence != SILENT_Yes) xml->attribute("silent", "YES");
	p_GraphIRI->express(this);
	xml->close();
    }
    virtual void drop (Drop*, e_Silence p_Silence, URI* p_GraphIRI) {
	xml->open("Drop");
	if (p_Silence != SILENT_Yes) xml->attribute("silent", "YES");
	p_GraphIRI->express(this);
	xml->close();
    }
    virtual void varExpression (VarExpression*, Variable* p_Variable) {
	xml->open("VarExpression");
	p_Variable->express(this);
	xml->close();
    }
    virtual void literalExpression (LiteralExpression*, RDFLiteral* p_RDFLiteral) {
	xml->open("LiteralExpression");
	p_RDFLiteral->express(this);
	xml->close();
    }
    virtual void booleanExpression (BooleanExpression*, BooleanRDFLiteral* p_BooleanRDFLiteral) {
	xml->open("BooleanExpression");
	p_BooleanRDFLiteral->express(this);
	xml->close();
    }
    virtual void uriExpression (URIExpression*, URI* p_URI) {
	xml->open("URIExpression");
	p_URI->express(this);
	xml->close();
    }
    virtual void argList (ArgList*, ProductionVector<Expression*>* p__O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C) {
	xml->open("ArgList");
	p__O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C->express(this);
	xml->close();
    }
    virtual void functionCall (FunctionCall*, URI* p_IRIref, ArgList* p_ArgList) {
	xml->open("FunctionCall");
	p_IRIref->express(this);
	p_ArgList->express(this);
	xml->close();
    }
    virtual void functionCallExpression (FunctionCallExpression*, FunctionCall* p_FunctionCall) {
	xml->open("FunctionCallExpression");
	p_FunctionCall->express(this);
	xml->close();
    }
/* Expressions */
    virtual void booleanNegation (BooleanNegation*, Expression* p_Expression) {
	xml->open("BooleanNegation");
	p_Expression->express(this);
	xml->close();
    }
    virtual void arithmeticNegation (ArithmeticNegation*, Expression* p_Expression) {
	xml->open("ArithmeticNegation");
	p_Expression->express(this);
	xml->close();
    }
    virtual void arithmeticInverse (ArithmeticInverse*, Expression* p_Expression) {
	xml->open("ArithmeticInverse");
	p_Expression->express(this);
	xml->close();
    }
    virtual void booleanConjunction (BooleanConjunction*, ProductionVector<Expression*>* p_Expressions) {
	xml->open("BooleanConjunction");
	p_Expressions->express(this);
	xml->close();
    }
    virtual void booleanDisjunction (BooleanDisjunction*, ProductionVector<Expression*>* p_Expressions) {
	xml->open("BooleanDisjunction");
	p_Expressions->express(this);
	xml->close();
    }
    virtual void booleanNegation (BooleanNegation*, ProductionVector<Expression*>* p_Expressions) {
	xml->open("BooleanNegation");
	p_Expressions->express(this);
	xml->close();
    }
    virtual void arithmeticSum (ArithmeticSum*, ProductionVector<Expression*>* p_Expressions) {
	xml->open("ArithmeticSum");
	p_Expressions->express(this);
	xml->close();
    }
    virtual void arithmeticProduct (ArithmeticProduct*, ProductionVector<Expression*>* p_Expressions) {
	xml->open("ArithmeticProduct");
	p_Expressions->express(this);
	xml->close();
    }
    virtual void arithmeticInverse (ArithmeticInverse*, ProductionVector<Expression*>* p_Expressions) {
	xml->open("ArithmeticInverse");
	p_Expressions->express(this);
	xml->close();
    }
    virtual void booleanEQ (BooleanEQ*, Expression* p_left, Expression* p_right) {
	xml->open("BooleanEQ");
	p_left->express(this);
	p_right->express(this);
	xml->close();
    }
    virtual void booleanNE (BooleanNE*, Expression* p_left, Expression* p_right) {
	xml->open("BooleanNE");
	p_left->express(this);
	p_right->express(this);
	xml->close();
    }
    virtual void booleanLT (BooleanLT*, Expression* p_left, Expression* p_right) {
	xml->open("BooleanLT");
	p_left->express(this);
	p_right->express(this);
	xml->close();
    }
    virtual void booleanGT (BooleanGT*, Expression* p_left, Expression* p_right) {
	xml->open("BooleanGT");
	p_left->express(this);
	p_right->express(this);
	xml->close();
    }
    virtual void booleanLE (BooleanLE*, Expression* p_left, Expression* p_right) {
	xml->open("BooleanLE");
	p_left->express(this);
	p_right->express(this);
	xml->close();
    }
    virtual void booleanGE (BooleanGE*, Expression* p_left, Expression* p_right) {
	xml->open("BooleanGE");
	p_left->express(this);
	p_right->express(this);
	xml->close();
    }
    virtual void comparatorExpression (ComparatorExpression*, BooleanComparator* p_BooleanComparator) {
	xml->open("ComparatorExpression");
	p_BooleanComparator->express(this);
	xml->close();
    }
    virtual void numberExpression (NumberExpression*, NumericRDFLiteral* p_NumericRDFLiteral) {
	xml->open("NumberExpression");
	p_NumericRDFLiteral->express(this);
	xml->close();
    }
};

#endif // XMLQueryExpressor_H

