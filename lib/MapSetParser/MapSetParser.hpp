
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
   Foundation, Inc.
   
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
#line 59 "lib/MapSetParser/MapSetParser.ypp"
 // ##bison2
/* Bison seems to test inclusion with PARSER_HEADER_H, rather than something
 * which varies by parser_class_name . Overriding with define specific to
 * this parser.
 */
#endif /* !PARSER_HEADER_H */
#ifndef MAPSET_PARSER_HPP
#define MAPSET_PARSER_HPP

#include "SWObjects.hpp"
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
    TableOperation* curOp; // needed to make right-descending tree for e.g. TriplesBlock? ( ( GraphPatternNotTriples | Filter ) '.'? TriplesBlock? )*
    BindingClause* curBindingsClause;
    Binding* curBinding;
    ProductionVector<const Expression*>* curExprList;
    const TTerm* curGraphName;
    ProductionVector<const Expression*> filterExpressions;
    bool countStar;

    void ensureBasicGraphPattern ( ) {
	if (curBGP == NULL) {
	    curBGP = curGraphName == NULL ? 
		static_cast<BasicGraphPattern*>(new DefaultGraphPattern()) : 
		static_cast<BasicGraphPattern*>(new NamedGraphPattern(curGraphName));
	    curOp = makeConjunction(curOp, curBGP);
	}
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

    TableOperation* makeConjunction (TableOperation* l, TableOperation* r) {
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

    TableOperation* makeDisjunction (TableOperation* l, TableOperation* r) {
	TableDisjunction* ret = new TableDisjunction();
	ret->addTableOperation(l, unnestTree);
	ret->addTableOperation(r, unnestTree);
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
#line 159 "lib/MapSetParser/MapSetParser.hpp"


#include <string>
#include <iostream>
#include "stack.hh"


/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace w3c_sw {

/* Line 35 of lalr1.cc  */
#line 173 "lib/MapSetParser/MapSetParser.hpp"
  class position;
  class location;

/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 35 of lalr1.cc  */
#line 183 "lib/MapSetParser/MapSetParser.hpp"

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

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)		\
do {							\
  if (N)						\
    {							\
      (Current).begin = (Rhs)[1].begin;			\
      (Current).end   = (Rhs)[N].end;			\
    }							\
  else							\
    {							\
      (Current).begin = (Current).end = (Rhs)[0].end;	\
    }							\
} while (false)
#endif


/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace w3c_sw {

/* Line 35 of lalr1.cc  */
#line 231 "lib/MapSetParser/MapSetParser.hpp"

  /// A Bison parser.
  class MapSetParser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 35 of lalr1.cc  */
#line 173 "lib/MapSetParser/MapSetParser.ypp"

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
    BindingClause* p_BindingsClause;
    ProductionVector<const Binding*>* p_BindingValues;
    Binding* p_BindingValue;
    TableOperation* p_TableOperation;
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
    GeneralComparator* p_GeneralComparator;
    const URI* p_URI;
    ProductionVector<const URI*>* p_URIs;
    const RDFLiteral* p_RDFLiteral;
    const BNode* p_BNode;




/* Line 35 of lalr1.cc  */
#line 308 "lib/MapSetParser/MapSetParser.hpp"
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
     IT_SERVER = 259,
     IT_USER = 260,
     IT_PASSWORD = 261,
     IT_DATABASE = 262,
     IT_STEMURI = 263,
     IT_PRIMARYKEY = 264,
     IT_SHAREDVARS = 265,
     IT_PROMISCUOUS = 266,
     IT_INTERSECTION = 267,
     IT_DRACONIAN = 268,
     IT_VARNAMES = 269,
     IT_LABEL = 270,
     IT_GRAPH = 271,
     IT_SERVICE = 272,
     IT_BASE = 273,
     IT_PREFIX = 274,
     IT_DISTINCT = 275,
     IT_REDUCED = 276,
     GT_TIMES = 277,
     IT_CONSTRUCT = 278,
     IT_SELECT = 279,
     IT_FROM = 280,
     IT_NAMED = 281,
     IT_ORDER = 282,
     IT_BY = 283,
     IT_ASC = 284,
     IT_DESC = 285,
     IT_LIMIT = 286,
     IT_OFFSET = 287,
     IT_BINDINGS = 288,
     IT_MEMBERS = 289,
     IT_STARTS = 290,
     IT_ENDS = 291,
     IT_ANY = 292,
     IT_UNORDERED = 293,
     GT_LCURLEY = 294,
     GT_RCURLEY = 295,
     IT_WHERE = 296,
     GT_LPAREN = 297,
     GT_RPAREN = 298,
     IT_UNDEF = 299,
     GT_DOT = 300,
     IT_OPTIONAL = 301,
     IT_MINUS = 302,
     IT_UNION = 303,
     IT_FILTER = 304,
     GT_COMMA = 305,
     GT_SEMI = 306,
     IT_a = 307,
     GT_LBRACKET = 308,
     GT_RBRACKET = 309,
     GT_OR = 310,
     GT_AND = 311,
     GT_EQUAL = 312,
     GT_NEQUAL = 313,
     GT_LT = 314,
     GT_GT = 315,
     GT_LE = 316,
     GT_GE = 317,
     GT_PLUS = 318,
     GT_MINUS = 319,
     GT_DIVIDE = 320,
     GT_NOT = 321,
     IT_NOT = 322,
     IT_IN = 323,
     IT_IRI = 324,
     IT_URI = 325,
     IT_BNODE = 326,
     IT_COALESCE = 327,
     IT_IF = 328,
     IT_STRLANG = 329,
     IT_STRDT = 330,
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
     IT_MD5 = 364,
     IT_TO = 365,
     IT_YEAR = 366,
     IT_ADD = 367,
     IT_COPY = 368,
     IT_RAND = 369,
     IT_SHA512 = 370,
     GT_DELETE_LBRACKET_SPACECHAR_TAB_RETURN_LINEFEED_RBRACKET_PLUS_WHERE = 371,
     IT_NOW = 372,
     GT_DELETE_LBRACKET_SPACECHAR_TAB_RETURN_LINEFEED_RBRACKET_PLUS_DATA = 373,
     IT_TIMEZONE = 374,
     IT_ROUND = 375,
     IT_SHA384 = 376,
     IT_BIND = 377,
     IT_CONTAINS = 378,
     IT_SECONDS = 379,
     IT_MOVE = 380,
     IT_FLOOR = 381,
     GT_INSERT_LBRACKET_SPACECHAR_TAB_RETURN_LINEFEED_RBRACKET_PLUS_DATA = 382,
     IT_MINUTES = 383,
     IT_SUBSTR = 384,
     IT_SHA256 = 385,
     IT_HOURS = 386,
     IT_ENCODE_FOR_URI = 387,
     IT_STRSTARTS = 388,
     IT_CEIL = 389,
     IT_DAY = 390,
     IT_LCASE = 391,
     IT_ABS = 392,
     IT_UCASE = 393,
     IT_SHA224 = 394,
     IT_STRENDS = 395,
     IT_STRLEN = 396,
     IT_SHA1 = 397,
     IT_MONTH = 398,
     IT_true = 399,
     IT_false = 400,
     INTEGER = 401,
     DECIMAL = 402,
     DOUBLE = 403,
     INTEGER_POSITIVE = 404,
     DECIMAL_POSITIVE = 405,
     DOUBLE_POSITIVE = 406,
     INTEGER_NEGATIVE = 407,
     DECIMAL_NEGATIVE = 408,
     DOUBLE_NEGATIVE = 409,
     STRING_LITERAL1 = 410,
     STRING_LITERAL_LONG1 = 411,
     STRING_LITERAL2 = 412,
     STRING_LITERAL_LONG2 = 413,
     IRI_REF = 414,
     PNAME_NS = 415,
     PNAME_LN = 416,
     BLANK_NODE_LABEL = 417,
     ANON = 418,
     VAR1 = 419,
     VAR2 = 420,
     LANGTAG = 421,
     NIL = 422
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

    /// Internal symbol numbers.
    typedef unsigned char token_number_type;
    /* Tables.  */
    /// For a state, the index in \a yytable_ of its portion.
    static const short int yypact_[];
    static const short int yypact_ninf_;

    /// For a state, default rule to reduce.
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

#if YYERROR_VERBOSE
    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    virtual std::string yytnamerr_ (const char *n);
#endif

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

/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 35 of lalr1.cc  */
#line 662 "lib/MapSetParser/MapSetParser.hpp"



#endif /* ! defined PARSER_HEADER_H */
