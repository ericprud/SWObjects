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
#line 52 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
 // ##bison2
/* Bison seems to test inclusion with PARSER_HEADER_H, rather than something
 * which varies by parser_class_name . Overriding with define specific to
 * this parser.
 */
#endif /* !PARSER_HEADER_H */
#ifndef SPARQLALGEBRA_PARSER_HPP
#define SPARQLALGEBRA_PARSER_HPP

#include "SWObjects.hpp"
#include "ResultSet.hpp"
#include "ParserCommon.hpp"

namespace w3c_sw {

struct ParserTableConjunction : public TableConjunction {
    ParserTableConjunction () : TableConjunction() {  }
    void insertTableOperation (const TableOperation* tableOp) {
	m_TableOperations.push_front(tableOp);
    }
};

class SPARQLalgebraScanner;

/** The Driver class brings together all components. It creates an instance of
 * the SPARQLalgebraParser and SPARQLalgebraScanner classes and connects them. Then the input stream is
 * fed into the scanner object and the parser gets it's token
 * sequence. Furthermore the driver object is available in the grammar rules as
 * a parameter. Therefore the driver class contains a reference to the
 * structure into which the parsed data is saved. */

class SPARQLalgebraDriver : public YaccDriver {
    friend class SPARQLalgebraParser;
protected:
    const TTerm* curSubject;
    const TTerm* curPredicate;
    ParserFilter* curFilter;
    // const TableOperation* curOp; // needed to make right-descending tree for e.g. TriplesBlock? ( ( GraphPatternNotTriples | Filter ) '.'? TriplesBlock? )*
    ResultSet* curResultSet;
    Result* curResult;
    VariableVector termList;
    std::vector<const TTerm*>::const_iterator curTTerm;
    ProductionVector<const Expression*>* curExprList;
    const TTerm* curGraphName;
    ProductionVector<const Expression*> filterExpressions;
    bool countStar;
    WhereClause* lastWhereClause;
    location* yylloc;

    BasicGraphPattern* ensureGraphPattern ( ) {
	return curGraphName == NULL ? 
	    static_cast<BasicGraphPattern*>(new DefaultGraphPattern()) : 
	    static_cast<BasicGraphPattern*>(new NamedGraphPattern(curGraphName));
    }

    ParserFilter* saveFilter () {
	ParserFilter* ret = curFilter;
	curFilter = NULL;
	return ret;
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
    SPARQLalgebraDriver(std::string baseURI, AtomFactory* atomFactory);
    ~SPARQLalgebraDriver();

    const Operation* parse(IStreamContext& in);
    const Operation* parse(std::string queryStr);
    void executeSelect(IStreamContext& in, RdfDB* db, ResultSet* rs);
    void executeSelect(std::string queryStr, RdfDB* db, ResultSet* rs);


    /** Pointer to the current lexer instance, this is used to connect the
     * parser to the scanner. It is used in the yylex macro. */
    class SPARQLalgebraScanner* lexer;

    /** Reference to the object created during parsing of the SPARQL stream. */
    const Operation* root;

    /** Control attributes. */
    bool unnestTree;	/* conj(conj(A, B), C) => conj(A, B, C) */
};

} // namespace w3c_sw

// %} // ##bison1



/* Line 35 of lalr1.cc  */
#line 213 "lib/SPARQLalgebraParser/SPARQLalgebraParser.hpp"


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
#line 243 "lib/SPARQLalgebraParser/SPARQLalgebraParser.hpp"

  /// A Bison parser.
  class SPARQLalgebraParser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 35 of lalr1.cc  */
#line 222 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"

    const NumericRDFLiteral* p_NumericRDFLiteral;
    const Operation* p_Operation;
    const Delete* p_Delete;
    const Insert* p_Insert;
    OperationSet* p_OperationSet;
    struct {e_distinctness distinctness; VarSet* varSet; SolutionModifier* p_SolutionModifier;
	    std::vector<s_OrderConditionPair>* p_OrderConditions; ProductionVector<const Expression*>* p_having;
	    WhereClause* p_WhereClause;
    } p_protoSelect;
    Expression* p_Expression;
    ProductionVector<const Expression*>* p_Expressions;
    s_OrderConditionPair p_OrderConditionPair;
    std::vector<s_OrderConditionPair>* p_OrderConditions;
    ExpressionAliasList* p_ExpressionAliaseList;
    const TableOperation* p_op;
    ParserTableConjunction* p_conj;
    BasicGraphPattern* p_BasicGraphPattern; // used to accumulate triple patterns
    const TriplePattern* p_TriplePattern;
    // std::vector<TableOperation>* p_ops;
    const Variable* p_Variable;
    DatasetClause* p_DatasetClause;
    ProductionVector<const DatasetClause*>* p_DatasetClauses;
    e_ASCorDESC p_e_ASCorDESC;
    int p_int;
    e_Silence p_Silence;
    struct {const Delete* del; const Insert* ins;} p_DeleteInsert;
    const TTerm* p_TTerm;
    const URI* p_URI;
    bool p_bool;
    std::string* p_string;
    struct {const URI* uri; LANGTAG* langtag;} p_uri_or_langtag;
    e_distinctness p_distinctness;
    LANGTAG* p_LANGTAG;
    const BooleanRDFLiteral* p_BooleanRDFLiteral;
    /* Terminals */



/* Line 35 of lalr1.cc  */
#line 296 "lib/SPARQLalgebraParser/SPARQLalgebraParser.hpp"
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
     IT_base = 258,
     IT_prefix = 259,
     IT_project = 260,
     IT_extend = 261,
     IT_distinct = 262,
     IT_reduced = 263,
     IT_group = 264,
     IT_filter = 265,
     IT_order = 266,
     IT_ask = 267,
     IT_bgp = 268,
     IT_triple = 269,
     IT_join = 270,
     IT_sequence = 271,
     IT_leftjoin = 272,
     IT_optional = 273,
     IT_union = 274,
     IT_unit = 275,
     IT_reverse = 276,
     IT_named = 277,
     IT_modify = 278,
     IT_graph = 279,
     IT_substr = 280,
     IT_all = 281,
     IT_lcase = 282,
     IT_ucase = 283,
     IT_sha256 = 284,
     IT_round = 285,
     IT_path = 286,
     IT_seconds = 287,
     IT_str = 288,
     IT_create = 289,
     IT_asc = 290,
     IT_desc = 291,
     IT_floor = 292,
     IT_minutes = 293,
     IT_alt = 294,
     IT_bound = 295,
     IT_minus = 296,
     IT_in = 297,
     IT_hours = 298,
     IT_concat = 299,
     GT_AND = 300,
     IT_default = 301,
     IT_a = 302,
     TriplesSameSubject = 303,
     IT_if = 304,
     IT_regex = 305,
     GT_path_PLUS = 306,
     IT_add = 307,
     GT_GE = 308,
     IT_ceil = 309,
     IT_load = 310,
     GT_path_TIMES = 311,
     IT_separator = 312,
     GT_GT = 313,
     IT_insert = 314,
     IT_isnumeric = 315,
     IT_bnode = 316,
     GT_path_OPT = 317,
     IT_abs = 318,
     IT_coalesce = 319,
     GT_RCURLEY = 320,
     IT_DISTINCT = 321,
     IT_strlen = 322,
     IT_contains = 323,
     GT_NOT = 324,
     IT_isliteral = 325,
     IT_uri = 326,
     GT_NEQUAL = 327,
     IT_service = 328,
     GT_PLUS = 329,
     IT_MIN = 330,
     IT_isblank = 331,
     IT_drop = 332,
     IT_delete = 333,
     IT_slice = 334,
     IT_sha512 = 335,
     IT_MAX = 336,
     IT_SUM = 337,
     IT_COUNT = 338,
     IT_strlang = 339,
     GT_TIMES = 340,
     IT_AVG = 341,
     IT_table = 342,
     IT_strstarts = 343,
     IT_iri = 344,
     IT_sha384 = 345,
     IT_now = 346,
     IT_move = 347,
     IT_deletewhere = 348,
     IT_SAMPLE = 349,
     NIL = 350,
     IT_day = 351,
     IT_isuri = 352,
     GT_RPAREN = 353,
     IT_encode_for_uri = 354,
     IT_GROUP_CONCAT = 355,
     IT_tz = 356,
     IT_timezone = 357,
     IT_copy = 358,
     IT_exprlist = 359,
     IT_strdt = 360,
     GT_LPAREN = 361,
     IT_strends = 362,
     IT_deletedata = 363,
     IT_month = 364,
     GT_OR = 365,
     IT_exists = 366,
     GT_COMMA = 367,
     GT_LE = 368,
     IT_sameterm = 369,
     IT_quads = 370,
     IT_notoneof = 371,
     IT_year = 372,
     GT_EQUAL = 373,
     IT_seq = 374,
     GT_LT = 375,
     GT_LCURLEY = 376,
     IT_langmatches = 377,
     IT_insertdata = 378,
     IT_clear = 379,
     GT_DOT = 380,
     IT_isiri = 381,
     IT_silent = 382,
     IT__ = 383,
     IT_datatype = 384,
     IT_mod = 385,
     GT_MINUS = 386,
     GT_DIVIDE = 387,
     GT_DTYPE = 388,
     IT_lang = 389,
     IT_sha1 = 390,
     IT_uuid = 391,
     IT_struuid = 392,
     IT_md5 = 393,
     IT_strbefore = 394,
     IT_strafter = 395,
     IT_rand = 396,
     IT_true = 397,
     IT_false = 398,
     INTEGER = 399,
     DECIMAL = 400,
     DOUBLE = 401,
     INTEGER_POSITIVE = 402,
     DECIMAL_POSITIVE = 403,
     DOUBLE_POSITIVE = 404,
     INTEGER_NEGATIVE = 405,
     DECIMAL_NEGATIVE = 406,
     DOUBLE_NEGATIVE = 407,
     STRING_LITERAL1 = 408,
     STRING_LITERAL_LONG1 = 409,
     STRING_LITERAL2 = 410,
     STRING_LITERAL_LONG2 = 411,
     IRI_REF = 412,
     PNAME_NS = 413,
     PNAME_LN = 414,
     BLANK_NODE_LABEL = 415,
     ANON = 416,
     POSITION = 417,
     VAR1 = 418,
     VAR2 = 419,
     LANGTAG = 420
   };

    };
    /// Token type.
    typedef token::yytokentype token_type;

    /// Build a parser object.
    SPARQLalgebraParser (class SPARQLalgebraDriver& driver_yyarg);
    virtual ~SPARQLalgebraParser ();

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
    static const unsigned short int yytable_[];
    static const signed char yytable_ninf_;

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
    class SPARQLalgebraDriver& driver;
  };

} // w3c_sw

/* Line 35 of lalr1.cc  */
#line 651 "lib/SPARQLalgebraParser/SPARQLalgebraParser.hpp"



#endif /* ! defined PARSER_HEADER_H */
