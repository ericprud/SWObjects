/* XMLQueryExpressor.hpp - simple XML serializer for SPARQL compile trees.
 *
 * $Id: XMLQueryExpressor.hpp,v 1.3 2008-09-13 05:17:31 eric Exp $
 */

#ifndef XMLQueryExpressor_H
#define XMLQueryExpressor_H

#include "XMLSerializer.hpp"

namespace w3c_sw {

class XMLQueryExpressor : public ExpressorSerializer {
protected:
    bool createdXMLSerializer;
    bool sparqlx;
    XMLSerializer* xml;
public:
    XMLQueryExpressor (const char* p_tab = "  ", bool p_sparqlx = true) : ExpressorSerializer(), createdXMLSerializer(true), sparqlx(p_sparqlx) { xml = new XMLSerializer(p_tab); }
    XMLQueryExpressor (XMLSerializer* p_xml, bool p_sparqlx = true) : ExpressorSerializer(), createdXMLSerializer(false), sparqlx(p_sparqlx), xml(p_xml) {  }
    ~XMLQueryExpressor () { if (createdXMLSerializer) delete xml; }
    virtual std::string str () { return xml->str(); }
    virtual void str (std::string seed) { xml->str(seed); }
    //!!!
    virtual void base (const Base* const, std::string productionName) { throw(std::runtime_error(productionName)); };

    virtual void members(const Members* const /* self */, ProductionVector<const TTerm*>* p_vars) {
	xml->open("members");
	p_vars->express(this);
	xml->close();
    }
    virtual void uri (const URI* const, std::string lexicalValue) {
	xml->leaf("uri", lexicalValue);
    }
    virtual void variable (const Variable* const, std::string lexicalValue) {
	xml->empty("variable");
	xml->attribute("name", lexicalValue);
    }
    virtual void bnode (const BNode* const, std::string lexicalValue) {
	xml->leaf("bnode", lexicalValue);
    }
    virtual void rdfLiteral (const RDFLiteral* const, std::string lexicalValue, const URI* datatype, const LANGTAG* p_LANGTAG) {
	xml->leaf("literal", lexicalValue);
	if (datatype != NULL) xml->attribute("datatype", datatype->getLexicalValue()); //!!!
	if (p_LANGTAG != NULL) xml->attribute("xml:lang", p_LANGTAG->getLexicalValue());
    }
    virtual void rdfLiteral (const NumericRDFLiteral* const, int p_value, const URI* /* p_datatype */) {
	xml->leaf("literal", p_value);
	xml->attribute("datatype", "http://www.w3.org/2001/XMLSchema#integer");
    }
    virtual void rdfLiteral (const NumericRDFLiteral* const, float p_value, const URI* /* p_datatype */) {
	xml->leaf("literal", p_value);
	xml->attribute("datatype", "http://www.w3.org/2001/XMLSchema#float");
    }
    virtual void rdfLiteral (const NumericRDFLiteral* const, double p_value, const URI* /* p_datatype */) {
	xml->leaf("literal", p_value);
	xml->attribute("datatype", "http://www.w3.org/2001/XMLSchema#decimal");
    }
    virtual void rdfLiteral (const BooleanRDFLiteral* const, bool p_value) {
	xml->leaf("literal", p_value);
	xml->attribute("datatype", "http://www.w3.org/2001/XMLSchema#boolean");
    }
    virtual void nulltterm (const NULLtterm* const) {
	xml->empty("NULL");
    }

    virtual void predicate (const PropertyPath::Predicate* const, const URI* uri) {
	uri->express(this);
    }
    virtual void inverse (const PropertyPath::Inverse* const, const PropertyPath::PathBase* nested) {
	xml->open("reverse");
	nested->express(this);
	xml->close();
    }
    virtual void sequence (const PropertyPath::Sequence* const, const PropertyPath::PathBase* l, const PropertyPath::PathBase* r) {
	xml->open("seq");
	l->express(this);
	r->express(this);
	xml->close();
    }
    virtual void alternative (const PropertyPath::Alternative* const, const PropertyPath::PathBase* l, const PropertyPath::PathBase* r) {
	xml->open("alt");
	l->express(this);
	r->express(this);
	xml->close();
    }
    virtual void repeated (const PropertyPath::Repeated* const, const PropertyPath::PathBase* nested, unsigned min, unsigned max) {
	xml->open("mod");
	if (min != PropertyPath::Repeated::Unlimited) xml->attribute("min", boost::lexical_cast<std::string>(min));
	if (max != PropertyPath::Repeated::Unlimited) xml->attribute("max", boost::lexical_cast<std::string>(max));
	nested->express(this);
	xml->close();
    }
    virtual void negated (const PropertyPath::Negated* const, const PropertyPath::PathBase* nested) {
	xml->open("notoneof");
	nested->express(this);
	xml->close();
    }
    virtual void propertyPath (const PropertyPath* const, const PropertyPath::PathBase* nested) {
	xml->open("path");
	nested->express(this);
	xml->close();
    }

    virtual void triplePattern (const TriplePattern* const, const TTerm* p_s, const TTerm* p_p, const TTerm* p_o) {
	xml->open("TriplePattern");
	p_s->express(this);
	p_p->express(this);
	p_o->express(this);
	xml->close();
    }
    virtual void filter (const Filter* const, const TableOperation* p_op, const ProductionVector<const Expression*>* p_Constraints) {
	p_op->express(this);
	xml->open("Filter");
	p_Constraints->express(this);
	xml->close();
    }
    virtual void bind (const Bind* const, const TableOperation* p_op, const Expression* p_expr, const Variable* p_label) {
	p_op->express(this);
	xml->open("Bind"); {
	    p_expr->express(this);
	    p_label->express(this);
	} xml->close();
    }
    virtual void namedGraphPattern (const NamedGraphPattern* const, const TTerm* p_name, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	if (sparqlx)
	    xml->open("BasicGraphPattern");
	else {
	    xml->open("NamedGraphPattern");
	    p_name->express(this);
	}
	if (p_allOpts == true) xml->attribute("allOpts", "allOpts");
	p_TriplePatterns->express(this);
	xml->close();
    }
    virtual void defaultGraphPattern (const DefaultGraphPattern* const, bool p_allOpts, const ProductionVector<const TriplePattern*>* p_TriplePatterns) {
	if (sparqlx)
	    xml->open("BasicGraphPattern");
	else
	    xml->open("DefaultGraphPattern");
	if (p_allOpts == true) xml->attribute("allOpts", "allOpts");
	p_TriplePatterns->express(this);
	xml->close();
    }
    virtual void tableDisjunction (const TableDisjunction* const, const ProductionVector<const TableOperation*>* p_TableOperations) {
	xml->open("TableDisjunction");
	p_TableOperations->express(this);
	xml->close();
    }
    virtual void tableConjunction (const TableConjunction* const, const ProductionVector<const TableOperation*>* p_TableOperations) {
	xml->open("TableConjunction");
	p_TableOperations->express(this);
	xml->close();
    }
    virtual void optionalGraphPattern (const OptionalGraphPattern* const, const TableOperation* p_GroupGraphPattern, const ProductionVector<const Expression*>* p_Expressions) {
	xml->open("OptionalGraphPattern");
	p_GroupGraphPattern->express(this);
	p_Expressions->express(this);
	xml->close();
    }
    virtual void minusGraphPattern (const MinusGraphPattern* const, const TableOperation* p_GroupGraphPattern) {
	xml->open("MinusGraphPattern");
	p_GroupGraphPattern->express(this);
	xml->close();
    }
    virtual void graphGraphPattern (const GraphGraphPattern* const, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern) {
	if (sparqlx) {
	    xml->open("GraphGraphPattern");
	    p_TTerm->express(this);
	    p_GroupGraphPattern->express(this);
	    xml->close();
	} else
	    p_GroupGraphPattern->express(this);
    }
    virtual void serviceGraphPattern (const ServiceGraphPattern* const, const TTerm* p_TTerm, const TableOperation* p_GroupGraphPattern, e_Silence p_Silence, AtomFactory* /* atomFactory */, bool /* lexicalCompare */) {
	if (sparqlx) {
	    xml->open("ServiceGraphPattern");
	    if (p_Silence == SILENT_Yes) xml->attribute("silent", "YES");
	    p_TTerm->express(this);
	    p_GroupGraphPattern->express(this);
	    xml->close();
	} else
	    p_GroupGraphPattern->express(this);
    }
    virtual void expressionAlias (const ExpressionAlias* const, const Expression* expr, const Bindable* label) {
	if (label != NULL) {
	    xml->open("ExpressionAlias");
	    expr->express(this);
	    label->express(this);
	    xml->close();
	} else
	    expr->express(this);
    }
    virtual void expressionAliasList (const ExpressionAliasList* const, const ProductionVector<const ExpressionAlias*>* p_Expressions) {
	xml->open("ExpressionAliasList");
	p_Expressions->express(this);
	xml->close();
    }
    virtual void posList (const TTermList* const, const ProductionVector<const TTerm*>* p_TTerms) {
	xml->open("TTermList");
	p_TTerms->express(this);
	xml->close();
    }
    virtual void starVarSet (const StarVarSet* const) {
	xml->empty("StarVarSet");
    }
    virtual void defaultGraphClause (const DefaultGraphClause* const, const TTerm* p_IRIref) {
	xml->open("DefaultGraphClause");
	p_IRIref->express(this);
	xml->close();
    }
    virtual void namedGraphClause (const NamedGraphClause* const, const TTerm* p_IRIref) {
	xml->open("NamedGraphClause");
	p_IRIref->express(this);
	xml->close();
    }
    virtual void solutionModifier (const SolutionModifier* const, ExpressionAliasList* groupBy, ProductionVector<const Expression*>* having, std::vector<s_OrderConditionPair>* p_OrderConditions, int p_limit, int p_offset) {
	xml->open("SolutionModifier");
	if (groupBy) {
	    for (std::vector<const ExpressionAlias*>::const_iterator it = groupBy->begin();
		 it != groupBy->end(); ++it) {
		xml->open("GroupBy");
		(*it)->express(this);
		xml->close();
	    }
	}
	if (having) {
	    for (std::vector<const Expression*>::const_iterator it = having->begin();
		 it != having->end(); ++it) {
		xml->open("HAVING");
		(*it)->express(this);
		xml->close();
	    }
	}
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
    virtual void valuesClause (const ValuesClause* const, const ResultSet* p_ResultSet) {
	p_ResultSet->toXml(xml);
    }
    virtual void whereClause (const WhereClause* const, const TableOperation* p_GroupGraphPattern) {
	xml->open("WhereClause");
	p_GroupGraphPattern->express(this);
	xml->close();
    }
    virtual void operationSet (const OperationSet* const, const ProductionVector<const Operation*>* p_Operations) {
	xml->open("OperationSet");
	for (std::vector<const Operation*>::const_iterator it = p_Operations->begin();
	     it != p_Operations->end(); ++it) {
	    (*it)->express(this);
	}
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
    virtual void subSelect (const SubSelect* const, const Select* p_Select) {
	xml->open("SubSelect");
	p_Select->express(this);
	xml->close();
    }
    // !!!2 -- use ConstructableOperation for p_ConstructTemplate
    virtual void construct (const Construct* const, const TableOperation* p_ConstructTemplate, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
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
	if (p_WhereClause != NULL)
	    p_WhereClause->express(this);
	p_SolutionModifier->express(this);
	xml->close();
    }
    virtual void ask (const Ask* const, ProductionVector<const DatasetClause*>* p_DatasetClauses, WhereClause* p_WhereClause, SolutionModifier* p_SolutionModifier) {
	xml->open("Ask");
	p_DatasetClauses->express(this);
	p_WhereClause->express(this);
	p_SolutionModifier->express(this);
	xml->close();
    }
    virtual void modify (const Modify* const, const Delete* p_delete, const Insert* p_insert, WhereClause* p_WhereClause, const URI* with, std::vector<s_UsingPair>* usingGraphs) {
	xml->open("Modify");
	if (with)
	    xml->leaf("With", with->toString());
	if (p_delete != NULL)
	    p_delete->express(this);
	if (p_insert != NULL)
	    p_insert->express(this);
	p_WhereClause->express(this);
	if (usingGraphs) {
	    for (std::vector<s_UsingPair>::const_iterator it = usingGraphs->begin();
		 it != usingGraphs->end(); ++it) {
		xml->open("Using");
		if (it->named)
		    xml->attribute("Named", "true");
		xml->charData(it->name->getLexicalValue());
		xml->close();
	    }
	}
	xml->close();
    }
    virtual void insert (const Insert* const, const TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	xml->open("Insert");
	p_GraphTemplate->express(this);
	if (p_WhereClause) p_WhereClause->express(this);
	xml->close();
    }
    virtual void del (const Delete* const, bool rangeOverUnboundVars, const TableOperation* p_GraphTemplate, WhereClause* p_WhereClause) {
	xml->open(rangeOverUnboundVars ? "DeleteData":  "Delete");
	p_GraphTemplate->express(this);
	p_WhereClause->express(this);
	xml->close();
    }
    virtual void load (const Load* const, e_Silence p_Silence, const URI* p_from, const URI* p_into) {
	xml->open("Load");
	if (p_Silence == SILENT_Yes) xml->attribute("silent", "YES");
	p_from->express(this);
	if (p_into)
	    p_into->express(this);
	xml->close();
    }
    virtual void clear (const Clear* const, e_Silence p_Silence, const URI* p__QGraphIRI_E_Opt) {
	xml->open("Clear");
	if (p_Silence == SILENT_Yes) xml->attribute("silent", "YES");
	p__QGraphIRI_E_Opt->express(this);
	xml->close();
    }
    virtual void create (const Create* const, e_Silence p_Silence, const URI* p_GraphIRI) {
	xml->open("Create");
	if (p_Silence == SILENT_Yes) xml->attribute("silent", "YES");
	p_GraphIRI->express(this);
	xml->close();
    }
    virtual void drop (const Drop* const, e_Silence p_Silence, const URI* p_GraphIRI) {
	xml->open("Drop");
	if (p_Silence == SILENT_Yes) xml->attribute("silent", "YES");
	p_GraphIRI->express(this);
	xml->close();
    }
    virtual void add (const Add* const, e_Silence p_Silence, const URI* from, const URI* /* to */) {
	xml->open("Add"); {
	    if (p_Silence == SILENT_Yes) xml->attribute("silent", "YES");
	    xml->open("From"); {
		from->express(this);
	    } xml->close();
	    xml->open("To"); {
		from->express(this);
	    } xml->close();
	} xml->close();
    }
    virtual void move (const Move* const, e_Silence p_Silence, const URI* from, const URI* /* to */) {
	xml->open("Move"); {
	    if (p_Silence == SILENT_Yes) xml->attribute("silent", "YES");
	    xml->open("From"); {
		from->express(this);
	    } xml->close();
	    xml->open("To"); {
		from->express(this);
	    } xml->close();
	} xml->close();
    }
    virtual void copy (const Copy* const, e_Silence p_Silence, const URI* from, const URI* /* to */) {
	xml->open("Copy"); {
	    if (p_Silence == SILENT_Yes) xml->attribute("silent", "YES");
	    xml->open("From"); {
		from->express(this);
	    } xml->close();
	    xml->open("To"); {
		from->express(this);
	    } xml->close();
	} xml->close();
    }
    virtual void posExpression (const TTermExpression* const, const TTerm* p_TTerm) {
	xml->open("TTermExpression");
	p_TTerm->express(this);
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
    virtual void aggregateCall (const AggregateCall* const /* self */, const URI* p_IRIref, const ArgList* p_ArgList, e_distinctness distinctness, const AggregateCall::ScalarVals* scalarVals) {
	xml->open("AggregateCall");
	p_IRIref->express(this);
	p_ArgList->express(this);
	xml->attribute
	    ("cardinality", 
	     distinctness == DIST_distinct ? "DISTINCT" : "ALL");
	if (scalarVals)
	    for (AggregateCall::ScalarVals::const_iterator it = scalarVals->begin(); it != scalarVals->end(); ++it)
		xml->attribute(it->first, it->second);
	xml->close();
    }
    virtual void functionCallExpression (const FunctionCallExpression* const, FunctionCall* p_FunctionCall) {
	xml->open("FunctionCallExpression");
	p_FunctionCall->express(this);
	xml->close();
    }
    virtual void existsExpression (const ExistsExpression* const, const TableOperation* p_TableOperation) {
	xml->open("ExistsExpression");
	p_TableOperation->express(this);
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
    virtual void naryIn (const NaryIn* const, const Expression* p_left, const ProductionVector<const Expression*>* p_right) {
	xml->open("NaryIn");
	p_left->express(this);
	p_right->express(this);
	xml->close();
    }
    virtual void comparatorExpression (const ComparatorExpression* const, const GeneralComparator* p_GeneralComparator) {
	xml->open("ComparatorExpression");
	p_GeneralComparator->express(this);
	xml->close();
    }
    virtual void numberExpression (const NumberExpression* const, const NumericRDFLiteral* p_NumericRDFLiteral) {
	xml->open("NumberExpression");
	p_NumericRDFLiteral->express(this);
	xml->close();
    }
};

} // namespace w3c_sw

#endif // XMLQueryExpressor_H

