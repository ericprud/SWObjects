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
    virtual void base (const Base* const, std::string productionName) { throw(std::runtime_error(productionName)); };

    virtual void uri (const URI* const, std::string terminal) {
	xml->leaf("uri", terminal);
    }
    virtual void variable (const Variable* const, std::string terminal) {
	xml->empty("variable");
	xml->attribute("name", terminal);
    }
    virtual void bnode (const BNode* const, std::string terminal) {
	xml->leaf("bnode", terminal);
    }
    virtual void rdfLiteral (const RDFLiteral* const, std::string terminal, URI* datatype, LANGTAG* p_LANGTAG) {
	xml->leaf("literal", terminal);
	if (datatype != NULL) xml->attribute("xsd:datatype", datatype->getTerminal()); //!!!
	if (p_LANGTAG != NULL) xml->attribute("xml:lang", p_LANGTAG->getTerminal());
    }
    virtual void rdfLiteral (const NumericRDFLiteral* const, int p_value) {
	xml->leaf("literal", p_value);
	xml->attribute("xsd:datatype", "http://www.w3.org/2001/XMLSchema/integer");
    }
    virtual void rdfLiteral (const NumericRDFLiteral* const, float p_value) {
	xml->leaf("literal", p_value);
	xml->attribute("xsd:datatype", "http://www.w3.org/2001/XMLSchema/float");
    }
    virtual void rdfLiteral (const NumericRDFLiteral* const, double p_value) {
	xml->leaf("literal", p_value);
	xml->attribute("xsd:datatype", "http://www.w3.org/2001/XMLSchema/decimal");
    }
    virtual void rdfLiteral (const BooleanRDFLiteral* const, bool p_value) {
	xml->leaf("literal", p_value);
	xml->attribute("xsd:datatype", "http://www.w3.org/2001/XMLSchema/boolean");
    }
    virtual void nullpos (const NULLpos* const) {
	xml->empty("NULL");
    }
    virtual void triplePattern (const TriplePattern* const, const POS* p_s, const POS* p_p, const POS* p_o) {
	xml->open("TriplePattern");
	p_s->express(this);
	p_p->express(this);
	p_o->express(this);
	xml->close();
    }
    virtual void filter (const Filter* const, const Expression* p_Constraint) {
	xml->open("Filter");
	p_Constraint->express(this);
	xml->close();
    }
    virtual void namedGraphPattern (const NamedGraphPattern* const, const POS* p_name, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns, const ProductionVector<const Filter*>* p_Filters) {
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
    virtual void defaultGraphPattern (const DefaultGraphPattern* const, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns, const ProductionVector<const Filter*>* p_Filters) {
	if (sparqlx)
	    xml->open("BasicGraphPattern");
	else
	    xml->open("DefaultGraphPattern");
	if (p_allOpts == true) xml->attribute("allOpts", "allOpts");
	p_TriplePatterns->express(this);
	p_Filters->express(this);
	xml->close();
    }
    virtual void tableDisjunction (const TableDisjunction* const, const ProductionVector<const TableOperation*>* p_TableOperations, const ProductionVector<const Filter*>* p_Filters) {
	xml->open("TableDisjunction");
	p_TableOperations->express(this);
	p_Filters->express(this);
	xml->close();
    }
    virtual void tableConjunction (const TableConjunction* const, const ProductionVector<const TableOperation*>* p_TableOperations, const ProductionVector<const Filter*>* p_Filters) {
	xml->open("TableConjunction");
	p_TableOperations->express(this);
	p_Filters->express(this);
	xml->close();
    }
    virtual void optionalGraphPattern (const OptionalGraphPattern* const, const TableOperation* p_GroupGraphPattern) {
	xml->open("OptionalGraphPattern");
	p_GroupGraphPattern->express(this);
	xml->close();
    }
    virtual void graphGraphPattern (const GraphGraphPattern* const, const POS* p_POS, const TableOperation* p_GroupGraphPattern) {
	if (sparqlx) {
	    xml->open("GraphGraphPattern");
	    p_POS->express(this);
	    p_GroupGraphPattern->express(this);
	    xml->close();
	} else
	    p_GroupGraphPattern->express(this);
    }
    virtual void posList (const POSList* const, const ProductionVector<const POS*>* p_POSs) {
	xml->open("POSList");
	p_POSs->express(this);
	xml->close();
    }
    virtual void starVarSet (const StarVarSet* const) {
	xml->empty("StarVarSet");
    }
    virtual void defaultGraphClause (const DefaultGraphClause* const, const POS* p_IRIref) {
	xml->open("DefaultGraphClause");
	p_IRIref->express(this);
	xml->close();
    }
    virtual void namedGraphClause (const NamedGraphClause* const, const POS* p_IRIref) {
	xml->open("NamedGraphClause");
	p_IRIref->express(this);
	xml->close();
    }
    virtual void solutionModifier (const SolutionModifier* const, std::vector<s_OrderConditionPair>* p_OrderConditions, int p_limit, int p_offset) {
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
    virtual void binding (const Binding* const, const ProductionVector<const POS*>* values) {//!!!
	xml->open("BindingClause");
	for (std::vector<const POS*>::const_iterator it = values->begin();
	     it != values->end(); ++it)
	    (*it)->express(this);
	xml->close();
    }
    virtual void bindingClause (const BindingClause* const, POSList* p_Vars, const ProductionVector<const Binding*>* p_Bindings) {
	xml->open("BindingClause");
	p_Vars->express(this);
	p_Bindings->ProductionVector<const Binding*>::express(this);
	xml->close();
    }
    virtual void whereClause (const WhereClause* const, const TableOperation* p_GroupGraphPattern, const BindingClause* p_BindingClause) {
	xml->open("WhereClause");
	p_GroupGraphPattern->express(this);
	if (p_BindingClause) p_BindingClause->express(this);
	xml->close();
    }
    virtual void select (const Select* const, e_distinctness p_distinctness, VarSet* p_VarSet, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
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
    virtual void construct (const Construct* const, DefaultGraphPattern* p_ConstructTemplate, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	xml->open("Construct");
	p_ConstructTemplate->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
	xml->close();
    }
    virtual void describe (const Describe* const, VarSet* p_VarSet, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	xml->open("Describe");
	p_VarSet->express(this);
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
	xml->close();
    }
    virtual void ask (const Ask* const, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause) {
	xml->open("Ask");
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	xml->close();
    }
    virtual void replace (const Replace* const, WhereClause* p_WhereClause, TableOperation* p_GraphTemplate) {
	xml->open("Replace");
	p_WhereClause->express(this);
	p_GraphTemplate->express(this);
	xml->close();
    }
    virtual void insert (const Insert* const, TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	xml->open("Insert");
	p_GraphTemplate->express(this);
	if (p_WhereClause) p_WhereClause->express(this);
	xml->close();
    }
    virtual void del (const Delete* const, TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	xml->open("Delete");
	p_GraphTemplate->express(this);
	p_WhereClause->express(this);
	xml->close();
    }
    virtual void load (const Load* const, ProductionVector<const URI*>* p_IRIrefs, const URI* p_into) {
	xml->open("Load");
	p_IRIrefs->express(this);
	p_into->express(this);
	xml->close();
    }
    virtual void clear (const Clear* const, const URI* p__QGraphIRI_E_Opt) {
	xml->open("Clear");
	p__QGraphIRI_E_Opt->express(this);
	xml->close();
    }
    virtual void create (const Create* const, e_Silence p_Silence, const URI* p_GraphIRI) {
	xml->open("Create");
	if (p_Silence != SILENT_Yes) xml->attribute("silent", "YES");
	p_GraphIRI->express(this);
	xml->close();
    }
    virtual void drop (const Drop* const, e_Silence p_Silence, const URI* p_GraphIRI) {
	xml->open("Drop");
	if (p_Silence != SILENT_Yes) xml->attribute("silent", "YES");
	p_GraphIRI->express(this);
	xml->close();
    }
    virtual void varExpression (const VarExpression* const, const Variable* p_Variable) {
	xml->open("VarExpression");
	p_Variable->express(this);
	xml->close();
    }
    virtual void literalExpression (const LiteralExpression* const, const RDFLiteral* p_RDFLiteral) {
	xml->open("LiteralExpression");
	p_RDFLiteral->express(this);
	xml->close();
    }
    virtual void booleanExpression (const BooleanExpression* const, const BooleanRDFLiteral* p_BooleanRDFLiteral) {
	xml->open("BooleanExpression");
	p_BooleanRDFLiteral->express(this);
	xml->close();
    }
    virtual void uriExpression (const URIExpression* const, const URI* p_URI) {
	xml->open("URIExpression");
	p_URI->express(this);
	xml->close();
    }
    virtual void argList (const ArgList* const, ProductionVector<const Expression*>* expressions) {
	xml->open("ArgList");
	expressions->express(this);
	xml->close();
    }
    virtual void functionCall (const FunctionCall* const, const URI* p_IRIref, const ArgList* p_ArgList) {
	xml->open("FunctionCall");
	p_IRIref->express(this);
	p_ArgList->express(this);
	xml->close();
    }
    virtual void functionCallExpression (const FunctionCallExpression* const, FunctionCall* p_FunctionCall) {
	xml->open("FunctionCallExpression");
	p_FunctionCall->express(this);
	xml->close();
    }
/* Expressions */
    virtual void booleanNegation (const BooleanNegation* const, const Expression* p_Expression) {
	xml->open("BooleanNegation");
	p_Expression->express(this);
	xml->close();
    }
    virtual void arithmeticNegation (const ArithmeticNegation* const, const Expression* p_Expression) {
	xml->open("ArithmeticNegation");
	p_Expression->express(this);
	xml->close();
    }
    virtual void arithmeticInverse (const ArithmeticInverse* const, const Expression* p_Expression) {
	xml->open("ArithmeticInverse");
	p_Expression->express(this);
	xml->close();
    }
    virtual void booleanConjunction (const BooleanConjunction* const, const ProductionVector<const Expression*>* p_Expressions) {
	xml->open("BooleanConjunction");
	p_Expressions->express(this);
	xml->close();
    }
    virtual void booleanDisjunction (const BooleanDisjunction* const, const ProductionVector<const Expression*>* p_Expressions) {
	xml->open("BooleanDisjunction");
	p_Expressions->express(this);
	xml->close();
    }
    virtual void arithmeticSum (const ArithmeticSum* const, const ProductionVector<const Expression*>* p_Expressions) {
	xml->open("ArithmeticSum");
	p_Expressions->express(this);
	xml->close();
    }
    virtual void arithmeticProduct (const ArithmeticProduct* const, const ProductionVector<const Expression*>* p_Expressions) {
	xml->open("ArithmeticProduct");
	p_Expressions->express(this);
	xml->close();
    }
    virtual void arithmeticInverse (const ArithmeticInverse* const, ProductionVector<const Expression*>* p_Expressions) {
	xml->open("ArithmeticInverse");
	p_Expressions->express(this);
	xml->close();
    }
    virtual void booleanEQ (const BooleanEQ* const, const Expression* p_left, const Expression* p_right) {
	xml->open("BooleanEQ");
	p_left->express(this);
	p_right->express(this);
	xml->close();
    }
    virtual void booleanNE (const BooleanNE* const, const Expression* p_left, const Expression* p_right) {
	xml->open("BooleanNE");
	p_left->express(this);
	p_right->express(this);
	xml->close();
    }
    virtual void booleanLT (const BooleanLT* const, const Expression* p_left, const Expression* p_right) {
	xml->open("BooleanLT");
	p_left->express(this);
	p_right->express(this);
	xml->close();
    }
    virtual void booleanGT (const BooleanGT* const, const Expression* p_left, const Expression* p_right) {
	xml->open("BooleanGT");
	p_left->express(this);
	p_right->express(this);
	xml->close();
    }
    virtual void booleanLE (const BooleanLE* const, const Expression* p_left, const Expression* p_right) {
	xml->open("BooleanLE");
	p_left->express(this);
	p_right->express(this);
	xml->close();
    }
    virtual void booleanGE (const BooleanGE* const, const Expression* p_left, const Expression* p_right) {
	xml->open("BooleanGE");
	p_left->express(this);
	p_right->express(this);
	xml->close();
    }
    virtual void comparatorExpression (const ComparatorExpression* const, const BooleanComparator* p_BooleanComparator) {
	xml->open("ComparatorExpression");
	p_BooleanComparator->express(this);
	xml->close();
    }
    virtual void numberExpression (const NumberExpression* const, const NumericRDFLiteral* p_NumericRDFLiteral) {
	xml->open("NumberExpression");
	p_NumericRDFLiteral->express(this);
	xml->close();
    }
};

#endif // XMLQueryExpressor_H

