// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

/**
 ** \file tmp/SPARQLParser/SPARQLParser.hpp
 ** Define the w3c_sw::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_W3C_SW_TMP_SPARQLPARSER_SPARQLPARSER_HPP_INCLUDED
# define YY_W3C_SW_TMP_SPARQLPARSER_SPARQLPARSER_HPP_INCLUDED
// //                    "%code requires" blocks.
#line 53 "lib/SPARQLParser.ypp" // lalr1.cc:377
 // ##bison2
/* Bison seems to test inclusion with PARSER_HEADER_H, rather than something
 * which varies by parser_class_name . Overriding with define specific to
 * this parser.
 */
#endif /* !PARSER_HEADER_H */
#ifndef SPARQL_PARSER_HPP
#define SPARQL_PARSER_HPP

#include "SWObjects.hpp"
#include "ResultSet.hpp"
#include "ParserCommon.hpp"
#include "SWObjectDuplicator.hpp"

namespace w3c_sw {

struct RSName {
    RSName (std::string name) : name(name) {  }
    std::string name;
};

struct BindingsMap : public std::map<std::string, const TableOperation*> {
    ~BindingsMap () {
	for (const_iterator it = begin(); it != end(); ++it)
	    delete it->second;
    }
};

class SPARQLScanner;

/** The Driver class brings together all components. It creates an instance of
 * the SPARQLParser and SPARQLScanner classes and connects them. Then the input stream is
 * fed into the scanner object and the parser gets it's token
 * sequence. Furthermore the driver object is available in the grammar rules as
 * a parameter. Therefore the driver class contains a reference to the
 * structure into which the parsed data is saved. */

class SPARQLDriver : public YaccDriver {
    friend class SPARQLParser;
    friend class SPARQLScanner;
protected:
    const TTerm* curSubject;
    const TTerm* curPredicate;
    const TTerm* curTail; // tail of the list currently being assembled.
    BasicGraphPattern* curBGP;
    FilterExpressions* curFilter;
    const TableOperation* curOp; // needed to make right-descending tree for e.g. TriplesBlock? ( ( GraphPatternNotTriples | Filter ) '.'? TriplesBlock? )*
    ResultSet* curResultSet;
    Result* curResult;
    VariableVector termList;
    std::vector<const TTerm*>::const_iterator curTTerm;
    BindingsMap bindingsMap;
    ProductionVector<const Expression*>* curExprList;
    const TTerm* curGraphName;
    ProductionVector<const Expression*> filterExpressions;
    bool countStar;
    WhereClause* lastWhereClause;
    location* yylloc; // can't move up into YaccDriver 'cause location.hh hasn't been included yet.
    PropertyPath::PathBase* lastPropertyPathAlternative;
    PropertyPath::PathBase* lastPropertyPathSequence;
    PropertyPath::PathBase* lastPropertyPathSetAlternative;
    std::map<const TTerm*, BasicGraphPattern*> bnode2bgp;
    std::set<const TTerm*> bnodesInOldOpperations;
    std::set<const TTerm*> bnodesInThisOpperation;
    bool inINSERTQUAD;
    bool inINSERTDATA;
    bool inDELETEDATA;
    bool inDELETEWHERE;
    bool inDELETECLAUSE;
public:
    static size_t DefaultAbortErrorCount;
    typedef enum {VALIDATE_none = 0,
		  VALIDATE_selectGrouped = 1, VALIDATE_uniqueProjection = 2,
		  VALIDATE_namedProjection = 4, VALIDATE_noReassign = 8,
		  VALIDATE_constructNoQuads = 0x10, VALIDATE_bnodeScope = 0x20,
		  VALIDATE_all = 0x3f} e_Validation;
    e_Validation validate;
    static e_Validation DefaultValidation;

    SPARQLDriver (std::string baseURI, AtomFactory* atomFactory,
		     size_t abortErrorCount = DefaultAbortErrorCount) : 
	YaccDriver(baseURI, atomFactory, abortErrorCount), curSubject(NULL), curPredicate(NULL), 
	curBGP(NULL), curFilter(NULL), curResultSet(NULL), curResult(NULL),
	curExprList(NULL), validate(DefaultValidation), root(NULL), unnestTree(false)
    {  }

    ~SPARQLDriver ()
    {  }

protected:

    const Variable* getVariable (std::string name) {
	if (inINSERTDATA || inDELETEDATA) // || inDELETEWHERE per http://www.w3.org/2009/sparql/docs/query-1.1/rq25.xml#sparqlGrammar note 7, but that breaks dawg_delete_where_01 dawg_delete_where_02 dawg_delete_where_03 dawg_delete_where_04 dawg_delete_where_05 dawg_delete_where_06 update_1_test_35
	    error(*yylloc, "variable ?" + name + " not allowed in fixed data block.");
	return YaccDriver::atomFactory->getVariable(name);
    }
    const BNode* createBNode () {
	if (inDELETEDATA || inDELETEWHERE || inDELETECLAUSE)
	    error(*yylloc, "anonymous blank node not allowed in fixed data block.");
	return YaccDriver::atomFactory->createBNode();
    }
    const BNode* getBNode (std::string name) {
	if (inDELETEDATA || inDELETEWHERE || inDELETECLAUSE)
	    error(*yylloc, "blank node _:" + name + " not allowed in fixed data block.");
	return YaccDriver::atomFactory->getBNode(name, &bnodeMap);
    }

    void ensureBasicGraphPattern ( ) {
	if (curBGP == NULL) {
	    curBGP = curGraphName == NULL ? 
		static_cast<BasicGraphPattern*>(new DefaultGraphPattern()) : 
		static_cast<BasicGraphPattern*>(new NamedGraphPattern(curGraphName));
	    curOp = makeConjunction(curOp, curBGP);
	}
    }

    const TableOperation* ensureGraphPattern ( ) {
	if (curOp == NULL)
	    ensureBasicGraphPattern();
	return curOp;
    }

    FilterExpressions* saveFilter () {
	FilterExpressions* ret = curFilter;
	curFilter = NULL;
	return ret;
    }

    void restoreFilter (FilterExpressions* was) {
	if (curFilter != NULL) {
	    if (curOp == NULL)
		ensureBasicGraphPattern();
	    curOp = new Filter(curOp, curFilter->m_Expressions.begin(), curFilter->m_Expressions.end());
	}
	curFilter = was;
    }

    const TableOperation* makeConjunction (const TableOperation* l, const TableOperation* r) {
	if (l != NULL) {
	    if (r != NULL) {
		TableConjunction* ret = new TableConjunction();
		ret->addTableOperation(l, unnestTree);
		ret->addTableOperation(r, unnestTree);
		return ret;
	    } else
		return l;
	}
	if (r != NULL)
	    return r;
	return NULL;
    }

    const TableOperation* makeDisjunction (const TableOperation* l, const TableOperation* r) {
	TableDisjunction* ret = new TableDisjunction();
	ret->addTableOperation(l, unnestTree);
	ret->addTableOperation(r, unnestTree);
	return ret;
    }

    /**
     * Interface to normalize the zillion ways to parse a ResultSet.
     */

    void startBindingSet () {
	curResultSet = new ResultSet(atomFactory);
	delete *curResultSet->begin();
	curResultSet->erase(curResultSet->begin());
    }

    void addBindingVar (const TTerm* var) {
	curResultSet->addOrderedVar(var);
	termList.push_back(var);
    }

    void startBindingRow (bool iterateBindingVars = true) {
	curResult = new Result(curResultSet);
	curResultSet->insert(curResultSet->end(), curResult);
	curTTerm = iterateBindingVars ? termList.begin() : termList.end();
    }

    void addBinding (const TTerm* variable, const TTerm* value) {
	assert (curResult != NULL);
	curResultSet->addOrderedVar(variable);
	if (value != TTerm::Unbound)
	    curResultSet->set(curResult, variable, value, false);
    }

    void addBindingValue (const TTerm* value) {
	if (curTTerm == termList.end()) {
	    std::stringstream ss;
	    ss << "atom " << value->toString() << " binding tuple wider than BINDINGS variable list.";
	    error(*yylloc, ss.str().c_str());
	}
	if (value != TTerm::Unbound)
	    curResultSet->set(curResult, *curTTerm, value, false);
	++curTTerm;
    }

    void addBindingVarOrValue (const TTerm* term) {
	if (curResult == NULL)
	    addBindingVar(term);
	else
	    addBindingValue(term);
    }

    Result* endBindingRow () {
	if (curTTerm != termList.end())
	    error(*yylloc, "insufficient bindings for result set row.");
	Result* ret = curResult;
	curResult = NULL;
	return ret;
    }

    ResultSet* endBindingSet () {
	ResultSet* ret = curResultSet;
	curResultSet = NULL;
	termList.clear();
	return ret;
    }

public:

    Operation* parse(IStreamContext& in);
    Operation* parse(std::string queryStr);
    void executeSelect(IStreamContext& in, RdfDB* db, ResultSet* rs);
    void executeSelect(std::string queryStr, RdfDB* db, ResultSet* rs);


    /** Pointer to the current lexer instance, this is used to connect the
     * parser to the scanner. It is used in the yylex macro. */
    class SPARQLScanner* lexer;

    /** Reference to the object created during parsing of the SPARQL stream. */
    Operation* root;

    /** Control attributes. */
    bool unnestTree;	/* conj(conj(A, B), C) => conj(A, B, C) */
};

} // namespace w3c_sw

// %} // ##bison1

#line 288 "tmp/SPARQLParser/SPARQLParser.hpp" // lalr1.cc:377


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>
# include "stack.hh"



#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif


namespace w3c_sw {
#line 360 "tmp/SPARQLParser/SPARQLParser.hpp" // lalr1.cc:377





  /// A Bison parser.
  class SPARQLParser
  {
  public:
#ifndef YYSTYPE
    /// Symbol semantic values.
    union semantic_type
    {
    #line 299 "lib/SPARQLParser.ypp" // lalr1.cc:377

    struct {const TTerm* subject; const TTerm* predicate;} p_SubjectPredicatePair;
    struct {int limit; int offset;} p_LimitOffsetPair;
    struct {const URI* uri; LANGTAG* langtag;} p_uri_or_langtag;
    struct {Operation* operation; WhereClause* whereClause;} p_OperationWhereClausePair;
    struct {e_distinctness distinctness; VarSet* varSet;} p_Project;
    struct {e_distinctness distinctness; const Expression* p_Expression;} p_DistExprPair;
    s_OrderConditionPair p_OrderConditionPair;
    std::vector<s_OrderConditionPair>* p_OrderConditions;
    s_UsingPair p_UsingPair;
    std::vector<s_UsingPair>* p_UsingPairs;
    TableConjunction* p_TableConjunction;
    TableDisjunction* p_TableDisjunction;

    /* Terminals */
    LANGTAG* p_LANGTAG;

    std::string* p_string;
    RSName* p_RSName;

    const NumericRDFLiteral* p_NumericRDFLiteral;
    const BooleanRDFLiteral* p_BooleanRDFLiteral;

    /* Productions */
    Operation* p_Operation;
    struct {const Delete* del; const Insert* ins;} p_DeleteInsert;
    Delete* p_Delete;
    Insert* p_Insert;
    OperationSet* p_OperationSet;
    const Variable* p_Variable;

    Select* p_Select;
    e_distinctness p_distinctness;
    e_listModifier p_listModifier;
    e_Silence p_Silence;
    TTermList* p_TTermList;
    ExpressionAliasList* p_ExpressionAliaseList;
    ExpressionAlias* p_ExpressionAlias;
    VarSet* p_VarSet;
    ProductionVector<const DatasetClause*>* p_DatasetClauses;
    Construct* p_Construct;
    Describe* p_Describe;
    Ask* p_Ask;
    DatasetClause* p_DatasetClause;
    DefaultGraphClause* p_DefaultGraphClause;
    NamedGraphClause* p_NamedGraphClause;
    WhereClause* p_WhereClause;
    SolutionModifier* p_SolutionModifier;
    e_ASCorDESC p_e_ASCorDESC;
    ValuesClause* p_ValuesClause;
    const TableOperation* p_TableOperation;
    const TTerm* p_GraphName;
    ProductionVector<const TableOperation*>* p_TableOperations;
    OptionalGraphPattern* p_OptionalGraphPattern;
    BasicGraphPattern* p_BasicGraphPattern;
    FilterExpressions* p_FilterExpressions;
    FunctionCall* p_FunctionCall;
    ArgList* p_ArgList;
    const TTerm* p_TTerm;
    ProductionVector<const TTerm*>* p_TTerms;
    Expression* p_Expression;
    ProductionVector<const Expression*>* p_Expressions;
    struct { bool neg; GeneralComparator* comp; } p_ComparatorSense;
    const URI* p_URI;
    ProductionVector<const URI*>* p_URIs;
    const RDFLiteral* p_RDFLiteral;
    const BNode* p_BNode;
    bool p_parentCountStar;
    PropertyPath::PathBase* p_PropertyPath;
    struct {unsigned min; unsigned max;} p_RepeatRange;

#line 446 "tmp/SPARQLParser/SPARQLParser.hpp" // lalr1.cc:377
    };
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef w3c_sw::location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m);
      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        __EOF__ = 0,
        IT_DELETE = 258,
        IT_INSERT = 259,
        IT_DATA = 260,
        IT_GRAPH = 261,
        IT_SERVICE = 262,
        IT_SADI = 263,
        IT_LOAD = 264,
        IT_INTO = 265,
        IT_CLEAR = 266,
        IT_CREATE = 267,
        IT_SILENT = 268,
        IT_DROP = 269,
        IT_BASE = 270,
        IT_PREFIX = 271,
        IT_SELECT = 272,
        IT_DISTINCT = 273,
        IT_REDUCED = 274,
        GT_TIMES = 275,
        IT_CONSTRUCT = 276,
        IT_DESCRIBE = 277,
        IT_FROM = 278,
        IT_NAMED = 279,
        IT_ORDER = 280,
        IT_BY = 281,
        IT_ASC = 282,
        IT_DESC = 283,
        IT_LIMIT = 284,
        IT_OFFSET = 285,
        IT_VALUES = 286,
        IT_MEMBERS = 287,
        IT_STARTS = 288,
        IT_ENDS = 289,
        IT_ANY = 290,
        IT_UNORDERED = 291,
        GT_LCURLEY = 292,
        GT_RCURLEY = 293,
        IT_ASK = 294,
        IT_WHERE = 295,
        GT_LPAREN = 296,
        GT_RPAREN = 297,
        IT_UNDEF = 298,
        GT_DOT = 299,
        IT_OPTIONAL = 300,
        IT_MINUS = 301,
        IT_UNION = 302,
        IT_FILTER = 303,
        GT_COMMA = 304,
        GT_SEMI = 305,
        IT_a = 306,
        GT_LBRACKET = 307,
        GT_RBRACKET = 308,
        GT_OR = 309,
        GT_AND = 310,
        GT_EQUAL = 311,
        GT_NEQUAL = 312,
        GT_LT = 313,
        GT_GT = 314,
        GT_LE = 315,
        GT_GE = 316,
        GT_PLUS = 317,
        GT_MINUS = 318,
        GT_DIVIDE = 319,
        GT_NOT = 320,
        IT_NOT = 321,
        IT_IN = 322,
        IT_IRI = 323,
        IT_URI = 324,
        IT_BNODE = 325,
        IT_COALESCE = 326,
        IT_IF = 327,
        IT_STRLANG = 328,
        IT_STRDT = 329,
        IT_REPLACE = 330,
        IT_EXISTS = 331,
        IT_SEPARATOR = 332,
        IT_STR = 333,
        IT_LANG = 334,
        IT_LANGMATCHES = 335,
        IT_DATATYPE = 336,
        IT_BOUND = 337,
        IT_sameTerm = 338,
        IT_isIRI = 339,
        IT_isURI = 340,
        IT_isBLANK = 341,
        IT_isLITERAL = 342,
        IT_REGEX = 343,
        GT_DTYPE = 344,
        IT_CONCAT = 345,
        IT_AS = 346,
        IT_GROUP = 347,
        IT_HAVING = 348,
        IT_COUNT = 349,
        IT_SUM = 350,
        IT_MIN = 351,
        IT_MAX = 352,
        IT_AVG = 353,
        IT_GROUP_CONCAT = 354,
        IT_SAMPLE = 355,
        IT_isNUMERIC = 356,
        GT_CARROT = 357,
        GT_OPT = 358,
        GT_PIPE = 359,
        IT_WITH = 360,
        IT_DEFAULT = 361,
        IT_ALL = 362,
        IT_USING = 363,
        IT_UUID = 364,
        IT_STRUUID = 365,
        IT_MD5 = 366,
        IT_TO = 367,
        IT_STRBEFORE = 368,
        IT_STRAFTER = 369,
        IT_YEAR = 370,
        IT_ADD = 371,
        IT_COPY = 372,
        IT_RAND = 373,
        IT_SHA512 = 374,
        IT_NOW = 375,
        IT_TZ = 376,
        IT_TIMEZONE = 377,
        IT_ROUND = 378,
        IT_SHA384 = 379,
        IT_BIND = 380,
        IT_CONTAINS = 381,
        IT_SECONDS = 382,
        IT_MOVE = 383,
        IT_FLOOR = 384,
        INSERTDATA = 385,
        DELETEDATA = 386,
        DELETEWHERE = 387,
        IT_MINUTES = 388,
        IT_SUBSTR = 389,
        IT_SHA256 = 390,
        IT_HOURS = 391,
        IT_ENCODE_FOR_URI = 392,
        IT_STRSTARTS = 393,
        IT_CEIL = 394,
        IT_DAY = 395,
        IT_LCASE = 396,
        IT_ABS = 397,
        IT_UCASE = 398,
        IT_STRENDS = 399,
        IT_STRLEN = 400,
        IT_SHA1 = 401,
        IT_MONTH = 402,
        IT_PRINT = 403,
        GT_H_2192_ = 404,
        GT_MINUS_GT = 405,
        ABOX_HR = 406,
        UBOX_UHR = 407,
        UBOX_LHR = 408,
        GT_H_2502_ = 409,
        UBOX_UL = 410,
        UBOX_U = 411,
        UBOX_UR = 412,
        UBOX_LL = 413,
        UBOX_L = 414,
        UBOX_LR = 415,
        RSREF = 416,
        GT_MINUS_MINUS = 417,
        IT_true = 418,
        IT_false = 419,
        INTEGER = 420,
        DECIMAL = 421,
        DOUBLE = 422,
        INTEGER_POSITIVE = 423,
        DECIMAL_POSITIVE = 424,
        DOUBLE_POSITIVE = 425,
        INTEGER_NEGATIVE = 426,
        DECIMAL_NEGATIVE = 427,
        DOUBLE_NEGATIVE = 428,
        STRING_LITERAL1 = 429,
        STRING_LITERAL_LONG1 = 430,
        STRING_LITERAL2 = 431,
        STRING_LITERAL_LONG2 = 432,
        IRIREF = 433,
        PNAME_NS = 434,
        PNAME_LN = 435,
        BLANK_NODE_LABEL = 436,
        ANON = 437,
        VAR1 = 438,
        VAR2 = 439,
        LANGTAG = 440,
        NIL = 441
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Copy constructor.
      basic_symbol (const basic_symbol& other);

      /// Constructor for valueless symbols.
      basic_symbol (typename Base::kind_type t,
                    const location_type& l);

      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    const semantic_type& v,
                    const location_type& l);

      /// Destroy the symbol.
      ~basic_symbol ();

      /// Destroy contents, and record that is empty.
      void clear ();

      /// Whether empty.
      bool empty () const;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;


    /// Build a parser object.
    SPARQLParser (class SPARQLDriver& driver_yyarg);
    virtual ~SPARQLParser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

  private:
    /// This class is not copyable.
    SPARQLParser (const SPARQLParser&);
    SPARQLParser& operator= (const SPARQLParser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short int yypact_ninf_;
    static const short int yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (int t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const short int yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned short int yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const short int yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const short int yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const short int yytable_[];

  static const short int yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned short int yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned short int yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short int yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    // Debugging.
    int yydebug_;
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state ();

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s);

      /// Copy constructor.
      by_state (const by_state& other);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, symbol_type& sym);
      /// Assignment, needed by push_back.
      stack_symbol_type& operator= (const stack_symbol_type& that);
    };

    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, stack_symbol_type& s);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, state_type s, symbol_type& sym);

    /// Pop \a n symbols the three stacks.
    void yypop_ (unsigned int n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 2937,     ///< Last index in yytable_.
      yynnts_ = 348,  ///< Number of nonterminal symbols.
      yyfinal_ = 11, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 187  ///< Number of tokens.
    };


    // User arguments.
    class SPARQLDriver& driver;
  };



} // w3c_sw
#line 974 "tmp/SPARQLParser/SPARQLParser.hpp" // lalr1.cc:377




#endif // !YY_W3C_SW_TMP_SPARQLPARSER_SPARQLPARSER_HPP_INCLUDED
