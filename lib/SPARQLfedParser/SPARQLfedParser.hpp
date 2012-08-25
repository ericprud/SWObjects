/* A Bison parser, made by GNU Bison 2.5.  */

/* Skeleton interface for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C++ LALR(1) parser skeleton written by Akim Demaille.  */

#ifndef PARSER_HEADER_H
#pragma once

/* "%code requires" blocks.  */

/* Line 35 of lalr1.cc  */
#line 52 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
 // ##bison2
/* Bison seems to test inclusion with PARSER_HEADER_H, rather than something
 * which varies by parser_class_name . Overriding with define specific to
 * this parser.
 */
#endif /* !PARSER_HEADER_H */
#ifndef SPARQLFED_PARSER_HPP
#define SPARQLFED_PARSER_HPP

#include "SWObjects.hpp"
#include "ResultSet.hpp"
#include "ParserCommon.hpp"
#include "SWObjectDuplicator.hpp"

namespace w3c_sw {

struct RSName {
    RSName (std::string name) : name(name) {  }
    std::string name;
};

class BindingsMap : public std::map<std::string, ResultSet*> {
};

class SPARQLfedScanner;

/** The Driver class brings together all components. It creates an instance of
 * the SPARQLfedParser and SPARQLfedScanner classes and connects them. Then the input stream is
 * fed into the scanner object and the parser gets it's token
 * sequence. Furthermore the driver object is available in the grammar rules as
 * a parameter. Therefore the driver class contains a reference to the
 * structure into which the parsed data is saved. */

class SPARQLfedDriver : public YaccDriver {
    friend class SPARQLfedParser;
protected:
    const TTerm* curSubject;
    const TTerm* curPredicate;
    BasicGraphPattern* curBGP;
    ParserFilter* curFilter;
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

    ParserFilter* saveFilter () {
	ParserFilter* ret = curFilter;
	curFilter = NULL;
	return ret;
    }

    void restoreFilter (ParserFilter* was) {
	if (curFilter != NULL) {
	    if (curOp == NULL)
		ensureBasicGraphPattern();
	    curFilter->setOp(curOp);
	    curOp = curFilter;
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
    SPARQLfedDriver(std::string baseURI, AtomFactory* atomFactory);
    ~SPARQLfedDriver();

    Operation* parse(IStreamContext& in);
    Operation* parse(std::string queryStr);
    void executeSelect(IStreamContext& in, RdfDB* db, ResultSet* rs);
    void executeSelect(std::string queryStr, RdfDB* db, ResultSet* rs);


    /** Pointer to the current lexer instance, this is used to connect the
     * parser to the scanner. It is used in the yylex macro. */
    class SPARQLfedScanner* lexer;

    /** Reference to the object created during parsing of the SPARQL stream. */
    Operation* root;

    /** Control attributes. */
    bool unnestTree;	/* conj(conj(A, B), C) => conj(A, B, C) */
};

} // namespace w3c_sw

// %} // ##bison1



/* Line 35 of lalr1.cc  */
#line 237 "lib/SPARQLfedParser/SPARQLfedParser.hpp"


#include <string>
#include <iostream>
#include "stack.hh"
#include "location.hh"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


namespace w3c_sw {

/* Line 35 of lalr1.cc  */
#line 267 "lib/SPARQLfedParser/SPARQLfedParser.hpp"

  /// A Bison parser.
  class SPARQLfedParser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 35 of lalr1.cc  */
#line 246 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

    struct {const TTerm* subject; const TTerm* predicate;} p_SubjectPredicatePair;
    struct {int limit; int offset;} p_LimitOffsetPair;
    struct {const URI* uri; LANGTAG* langtag;} p_uri_or_langtag;
    struct {Operation* operation; WhereClause* whereClause;} p_OperationWhereClausePair;
    struct {e_distinctness distinctness; VarSet* varSet;} p_Project;
    struct {e_distinctness distinctness; const Expression* p_Expression;} p_DistExprPair;
    s_OrderConditionPair p_OrderConditionPair;
    std::vector<s_OrderConditionPair>* p_OrderConditions;
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
    BindingClause* p_BindingClause;
    const TableOperation* p_TableOperation;
    ProductionVector<const TableOperation*>* p_TableOperations;
    OptionalGraphPattern* p_OptionalGraphPattern;
    BasicGraphPattern* p_BasicGraphPattern;
    ParserFilter* p_ParserFilter;
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



/* Line 35 of lalr1.cc  */
#line 349 "lib/SPARQLfedParser/SPARQLfedParser.hpp"
    };
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;
    /// Tokens.
    struct token
    {
      /* Tokens.  */
   enum yytokentype {
     __EOF__ = 0,
     IT_DELETE = 258,
     IT_INSERT = 259,
     IT_DATA = 260,
     IT_GRAPH = 261,
     IT_SERVICE = 262,
     IT_LOAD = 263,
     IT_INTO = 264,
     IT_CLEAR = 265,
     IT_CREATE = 266,
     IT_SILENT = 267,
     IT_DROP = 268,
     IT_BASE = 269,
     IT_PREFIX = 270,
     IT_SELECT = 271,
     IT_DISTINCT = 272,
     IT_REDUCED = 273,
     GT_TIMES = 274,
     IT_CONSTRUCT = 275,
     IT_DESCRIBE = 276,
     IT_FROM = 277,
     IT_NAMED = 278,
     IT_ORDER = 279,
     IT_BY = 280,
     IT_ASC = 281,
     IT_DESC = 282,
     IT_LIMIT = 283,
     IT_OFFSET = 284,
     IT_VALUES = 285,
     IT_MEMBERS = 286,
     IT_STARTS = 287,
     IT_ENDS = 288,
     IT_ANY = 289,
     IT_UNORDERED = 290,
     GT_LCURLEY = 291,
     GT_RCURLEY = 292,
     IT_ASK = 293,
     IT_WHERE = 294,
     GT_LPAREN = 295,
     GT_RPAREN = 296,
     IT_UNDEF = 297,
     GT_DOT = 298,
     IT_OPTIONAL = 299,
     IT_MINUS = 300,
     IT_UNION = 301,
     IT_FILTER = 302,
     GT_COMMA = 303,
     GT_SEMI = 304,
     IT_a = 305,
     GT_LBRACKET = 306,
     GT_RBRACKET = 307,
     GT_OR = 308,
     GT_AND = 309,
     GT_EQUAL = 310,
     GT_NEQUAL = 311,
     GT_LT = 312,
     GT_GT = 313,
     GT_LE = 314,
     GT_GE = 315,
     GT_PLUS = 316,
     GT_MINUS = 317,
     GT_DIVIDE = 318,
     GT_NOT = 319,
     IT_NOT = 320,
     IT_IN = 321,
     IT_IRI = 322,
     IT_URI = 323,
     IT_BNODE = 324,
     IT_COALESCE = 325,
     IT_IF = 326,
     IT_STRLANG = 327,
     IT_STRDT = 328,
     IT_EXISTS = 329,
     IT_SEPARATOR = 330,
     IT_STR = 331,
     IT_LANG = 332,
     IT_LANGMATCHES = 333,
     IT_DATATYPE = 334,
     IT_BOUND = 335,
     IT_sameTerm = 336,
     IT_isIRI = 337,
     IT_isURI = 338,
     IT_isBLANK = 339,
     IT_isLITERAL = 340,
     IT_REGEX = 341,
     GT_DTYPE = 342,
     IT_CONCAT = 343,
     IT_AS = 344,
     IT_GROUP = 345,
     IT_HAVING = 346,
     IT_COUNT = 347,
     IT_SUM = 348,
     IT_MIN = 349,
     IT_MAX = 350,
     IT_AVG = 351,
     IT_GROUP_CONCAT = 352,
     IT_SAMPLE = 353,
     IT_isNUMERIC = 354,
     GT_CARROT = 355,
     GT_OPT = 356,
     GT_PIPE = 357,
     IT_WITH = 358,
     IT_DEFAULT = 359,
     IT_ALL = 360,
     IT_USING = 361,
     IT_UUID = 362,
     IT_STRUUID = 363,
     IT_MD5 = 364,
     IT_TO = 365,
     IT_STRBEFORE = 366,
     IT_STRAFTER = 367,
     IT_YEAR = 368,
     IT_ADD = 369,
     IT_COPY = 370,
     IT_RAND = 371,
     IT_SHA512 = 372,
     GT_DELETE_LBRACKET_SPACECHAR_TAB_RETURN_LINEFEED_RBRACKET_PLUS_WHERE = 373,
     IT_NOW = 374,
     GT_DELETE_LBRACKET_SPACECHAR_TAB_RETURN_LINEFEED_RBRACKET_PLUS_DATA = 375,
     IT_TZ = 376,
     IT_TIMEZONE = 377,
     IT_ROUND = 378,
     IT_SHA384 = 379,
     IT_BIND = 380,
     IT_CONTAINS = 381,
     IT_SECONDS = 382,
     IT_MOVE = 383,
     IT_FLOOR = 384,
     GT_INSERT_LBRACKET_SPACECHAR_TAB_RETURN_LINEFEED_RBRACKET_PLUS_DATA = 385,
     IT_MINUTES = 386,
     IT_SUBSTR = 387,
     IT_SHA256 = 388,
     IT_HOURS = 389,
     IT_ENCODE_FOR_URI = 390,
     IT_STRSTARTS = 391,
     IT_CEIL = 392,
     IT_DAY = 393,
     IT_LCASE = 394,
     IT_ABS = 395,
     IT_UCASE = 396,
     IT_STRENDS = 397,
     IT_STRLEN = 398,
     IT_SHA1 = 399,
     IT_MONTH = 400,
     IT_PRINT = 401,
     GT_H_2192_ = 402,
     GT_MINUS_GT = 403,
     ABOX_HR = 404,
     ABOX_CELL = 405,
     UBOX_UHR = 406,
     UBOX_LHR = 407,
     GT_H_2502_ = 408,
     UBOX_UL = 409,
     UBOX_U = 410,
     UBOX_UR = 411,
     UBOX_SEP = 412,
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
    /// Token type.
    typedef token::yytokentype token_type;

    /// Build a parser object.
    SPARQLfedParser (class SPARQLfedDriver& driver_yyarg);
    virtual ~SPARQLfedParser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

  private:
    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Generate an error message.
    /// \param state   the state where the error occurred.
    /// \param tok     the lookahead token.
    virtual std::string yysyntax_error_ (int yystate, int tok);

#if YYDEBUG
    /// \brief Report a symbol value on the debug stream.
    /// \param yytype       The token type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    virtual void yy_symbol_value_print_ (int yytype,
					 const semantic_type* yyvaluep,
					 const location_type* yylocationp);
    /// \brief Report a symbol on the debug stream.
    /// \param yytype       The token type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    virtual void yy_symbol_print_ (int yytype,
				   const semantic_type* yyvaluep,
				   const location_type* yylocationp);
#endif


    /// State numbers.
    typedef int state_type;
    /// State stack type.
    typedef stack<state_type>    state_stack_type;
    /// Semantic value stack type.
    typedef stack<semantic_type> semantic_stack_type;
    /// location stack type.
    typedef stack<location_type> location_stack_type;

    /// The state stack.
    state_stack_type yystate_stack_;
    /// The semantic value stack.
    semantic_stack_type yysemantic_stack_;
    /// The location stack.
    location_stack_type yylocation_stack_;

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    /// Internal symbol numbers.
    typedef unsigned char token_number_type;
    /* Tables.  */
    /// For a state, the index in \a yytable_ of its portion.
    static const short int yypact_[];
    static const short int yypact_ninf_;

    /// For a state, default reduction number.
    /// Unless\a  yytable_ specifies something else to do.
    /// Zero means the default is an error.
    static const unsigned short int yydefact_[];

    static const short int yypgoto_[];
    static const short int yydefgoto_[];

    /// What to do in a state.
    /// \a yytable_[yypact_[s]]: what to do in state \a s.
    /// - if positive, shift that token.
    /// - if negative, reduce the rule which number is the opposite.
    /// - if zero, do what YYDEFACT says.
    static const short int yytable_[];
    static const short int yytable_ninf_;

    static const short int yycheck_[];

    /// For a state, its accessing symbol.
    static const unsigned short int yystos_[];

    /// For a rule, its LHS.
    static const unsigned short int yyr1_[];
    /// For a rule, its RHS length.
    static const unsigned char yyr2_[];

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);

#if YYDEBUG
    /// A type to store symbol numbers and -1.
    typedef short int rhs_number_type;
    /// A `-1'-separated list of the rules' RHS.
    static const rhs_number_type yyrhs_[];
    /// For each rule, the index of the first RHS symbol in \a yyrhs_.
    static const unsigned short int yyprhs_[];
    /// For each rule, its source line number.
    static const unsigned short int yyrline_[];
    /// For each scanner token number, its symbol number.
    static const unsigned short int yytoken_number_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /* Debugging.  */
    int yydebug_;
    std::ostream* yycdebug_;
#endif

    /// Convert a scanner token number \a t to a symbol number.
    token_number_type yytranslate_ (int t);

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg        Why this token is reclaimed.
    /// \param yytype       The symbol type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    inline void yydestruct_ (const char* yymsg,
			     int yytype,
			     semantic_type* yyvaluep,
			     location_type* yylocationp);

    /// Pop \a n symbols the three stacks.
    inline void yypop_ (unsigned int n = 1);

    /* Constants.  */
    static const int yyeof_;
    /* LAST_ -- Last index in TABLE_.  */
    static const int yylast_;
    static const int yynnts_;
    static const int yyempty_;
    static const int yyfinal_;
    static const int yyterror_;
    static const int yyerrcode_;
    static const int yyntokens_;
    static const unsigned int yyuser_token_number_max_;
    static const token_number_type yyundef_token_;

    /* User arguments.  */
    class SPARQLfedDriver& driver;
  };

} // w3c_sw

/* Line 35 of lalr1.cc  */
#line 725 "lib/SPARQLfedParser/SPARQLfedParser.hpp"



#endif /* ! defined PARSER_HEADER_H */
