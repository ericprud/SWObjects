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
#line 60 "lib/MapSetParser/MapSetParser.ypp"
 // ##bison2
/* Bison seems to test inclusion with PARSER_HEADER_H, rather than something
 * which varies by parser_class_name . Overriding with define specific to
 * this parser.
 */
#endif /* !PARSER_HEADER_H */
#ifndef MAPSET_PARSER_HPP
#define MAPSET_PARSER_HPP

#include "SWObjects.hpp"
#include "ResultSet.hpp"
#include "ParserCommon.hpp"
#include "QueryMapper.hpp"

namespace w3c_sw {

class MapSetScanner;

/** The Driver class brings together all components. It creates an instance of
 * the MapSetParser and MapSetScanner classes and connects them. Then the input stream is
 * fed into the scanner object and the parser gets it's token
 * sequence. Furthermore the driver object is available in the grammar rules as
 * a parameter. Therefore the driver class contains a reference to the
 * structure into which the parsed data is saved. */

class MapSetDriver : public YaccDriver {
    friend class MapSetParser;
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
    ProductionVector<const Expression*>* curExprList;
    const TTerm* curGraphName;
    ProductionVector<const Expression*> filterExpressions;
    bool countStar;
    location* yylloc;

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
	    ss << "atom " << value->toString() << " binding tuple wider than VALUES variable list.";
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
    MapSetDriver(std::string baseURI, AtomFactory* atomFactory);
    ~MapSetDriver();

    MapSet* parse(IStreamContext& in);
    MapSet* parse(std::string queryStr);


    /** Pointer to the current lexer instance, this is used to connect the
     * parser to the scanner. It is used in the yylex macro. */
    class MapSetScanner* lexer;

    /** Reference to the object created during parsing of the SPARQL stream. */
    MapSet* root;

    /** Control attributes. */
    bool unnestTree;	/* conj(conj(A, B), C) => conj(A, B, C) */
    RuleTerm lastRuleTerm;
    bool lastRuleTermSet;
    bool sharedVarsSet;
};

} // namespace w3c_sw

// %} // ##bison1



/* Line 35 of lalr1.cc  */
#line 228 "lib/MapSetParser/MapSetParser.hpp"


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
#line 258 "lib/MapSetParser/MapSetParser.hpp"

  /// A Bison parser.
  class MapSetParser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 35 of lalr1.cc  */
#line 245 "lib/MapSetParser/MapSetParser.ypp"

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

    const NumericRDFLiteral* p_NumericRDFLiteral;
    const BooleanRDFLiteral* p_BooleanRDFLiteral;

    /* Productions */
    Operation* p_Operation;
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
    MapSet* p_MapSet;
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
#line 334 "lib/MapSetParser/MapSetParser.hpp"
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
     IT_REWRITEVAR = 258,
     IT_DRIVER = 259,
     IT_SERVER = 260,
     IT_USER = 261,
     IT_PASSWORD = 262,
     IT_DATABASE = 263,
     IT_STEMURI = 264,
     IT_PRIMARYKEY = 265,
     IT_SHAREDVARS = 266,
     IT_PROMISCUOUS = 267,
     IT_INTERSECTION = 268,
     IT_DRACONIAN = 269,
     IT_VARNAMES = 270,
     IT_LABEL = 271,
     IT_GRAPH = 272,
     IT_SERVICE = 273,
     IT_SILENT = 274,
     IT_BASE = 275,
     IT_PREFIX = 276,
     IT_DISTINCT = 277,
     IT_REDUCED = 278,
     GT_TIMES = 279,
     IT_CONSTRUCT = 280,
     IT_SELECT = 281,
     IT_FROM = 282,
     IT_NAMED = 283,
     IT_ORDER = 284,
     IT_BY = 285,
     IT_ASC = 286,
     IT_DESC = 287,
     IT_LIMIT = 288,
     IT_OFFSET = 289,
     IT_VALUES = 290,
     IT_MEMBERS = 291,
     IT_STARTS = 292,
     IT_ENDS = 293,
     IT_ANY = 294,
     IT_UNORDERED = 295,
     GT_LCURLEY = 296,
     GT_RCURLEY = 297,
     IT_WHERE = 298,
     GT_LPAREN = 299,
     GT_RPAREN = 300,
     IT_UNDEF = 301,
     GT_MINUS_MINUS = 302,
     GT_DOT = 303,
     IT_OPTIONAL = 304,
     IT_MINUS = 305,
     IT_UNION = 306,
     IT_FILTER = 307,
     GT_COMMA = 308,
     GT_SEMI = 309,
     IT_a = 310,
     GT_LBRACKET = 311,
     GT_RBRACKET = 312,
     GT_OR = 313,
     GT_AND = 314,
     GT_EQUAL = 315,
     GT_NEQUAL = 316,
     GT_LT = 317,
     GT_GT = 318,
     GT_LE = 319,
     GT_GE = 320,
     GT_PLUS = 321,
     GT_MINUS = 322,
     GT_DIVIDE = 323,
     GT_NOT = 324,
     IT_NOT = 325,
     IT_IN = 326,
     IT_IRI = 327,
     IT_URI = 328,
     IT_BNODE = 329,
     IT_COALESCE = 330,
     IT_IF = 331,
     IT_STRLANG = 332,
     IT_STRDT = 333,
     IT_EXISTS = 334,
     IT_SEPARATOR = 335,
     IT_STR = 336,
     IT_LANG = 337,
     IT_LANGMATCHES = 338,
     IT_DATATYPE = 339,
     IT_BOUND = 340,
     IT_sameTerm = 341,
     IT_isIRI = 342,
     IT_isURI = 343,
     IT_isBLANK = 344,
     IT_isLITERAL = 345,
     IT_REGEX = 346,
     GT_DTYPE = 347,
     IT_CONCAT = 348,
     IT_AS = 349,
     IT_GROUP = 350,
     IT_HAVING = 351,
     IT_COUNT = 352,
     IT_SUM = 353,
     IT_MIN = 354,
     IT_MAX = 355,
     IT_AVG = 356,
     IT_GROUP_CONCAT = 357,
     IT_SAMPLE = 358,
     IT_isNUMERIC = 359,
     GT_CARROT = 360,
     GT_OPT = 361,
     GT_PIPE = 362,
     IT_WITH = 363,
     IT_DEFAULT = 364,
     IT_ALL = 365,
     IT_USING = 366,
     IT_UUID = 367,
     IT_STRUUID = 368,
     IT_MD5 = 369,
     IT_TO = 370,
     IT_STRBEFORE = 371,
     IT_STRAFTER = 372,
     IT_YEAR = 373,
     IT_ADD = 374,
     IT_COPY = 375,
     IT_RAND = 376,
     IT_SHA512 = 377,
     GT_DELETE_LBRACKET_SPACECHAR_TAB_RETURN_LINEFEED_RBRACKET_PLUS_WHERE = 378,
     IT_NOW = 379,
     GT_DELETE_LBRACKET_SPACECHAR_TAB_RETURN_LINEFEED_RBRACKET_PLUS_DATA = 380,
     IT_TZ = 381,
     IT_TIMEZONE = 382,
     IT_ROUND = 383,
     IT_SHA384 = 384,
     IT_BIND = 385,
     IT_CONTAINS = 386,
     IT_SECONDS = 387,
     IT_MOVE = 388,
     IT_FLOOR = 389,
     GT_INSERT_LBRACKET_SPACECHAR_TAB_RETURN_LINEFEED_RBRACKET_PLUS_DATA = 390,
     IT_MINUTES = 391,
     IT_SUBSTR = 392,
     IT_SHA256 = 393,
     IT_HOURS = 394,
     IT_ENCODE_FOR_URI = 395,
     IT_STRSTARTS = 396,
     IT_CEIL = 397,
     IT_DAY = 398,
     IT_LCASE = 399,
     IT_ABS = 400,
     IT_UCASE = 401,
     IT_STRENDS = 402,
     IT_STRLEN = 403,
     IT_SHA1 = 404,
     IT_MONTH = 405,
     IT_true = 406,
     IT_false = 407,
     INTEGER = 408,
     DECIMAL = 409,
     DOUBLE = 410,
     INTEGER_POSITIVE = 411,
     DECIMAL_POSITIVE = 412,
     DOUBLE_POSITIVE = 413,
     INTEGER_NEGATIVE = 414,
     DECIMAL_NEGATIVE = 415,
     DOUBLE_NEGATIVE = 416,
     STRING_LITERAL1 = 417,
     STRING_LITERAL_LONG1 = 418,
     STRING_LITERAL2 = 419,
     STRING_LITERAL_LONG2 = 420,
     IRIREF = 421,
     PNAME_NS = 422,
     PNAME_LN = 423,
     BLANK_NODE_LABEL = 424,
     ANON = 425,
     VAR1 = 426,
     VAR2 = 427,
     LANGTAG = 428,
     NIL = 429
   };

    };
    /// Token type.
    typedef token::yytokentype token_type;

    /// Build a parser object.
    MapSetParser (class MapSetDriver& driver_yyarg);
    virtual ~MapSetParser ();

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
    class MapSetDriver& driver;
  };

} // w3c_sw

/* Line 35 of lalr1.cc  */
#line 698 "lib/MapSetParser/MapSetParser.hpp"



#endif /* ! defined PARSER_HEADER_H */
