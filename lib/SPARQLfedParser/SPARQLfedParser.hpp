/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison LALR(1) parsers in C++

   Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
# define PARSER_HEADER_H

#include <string>
#include <iostream>
#include "stack.hh"

namespace w3c_sw
{
  class position;
  class location;
}

/* First part of user declarations.  */
#line 50 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
 /*** C/C++ Declarations ***/
/* Bison seems to test inclusion with PARSER_HEADER_H, rather than something
 * which varies by parser_class_name . Overriding with define specific to
 * this parser.
 */
#endif /* !PARSER_HEADER_H */
#ifndef SPARQLFED_PARSER_HPP
#define SPARQLFED_PARSER_HPP

#include "SWObjects.hpp"
#include "ParserCommon.hpp"

namespace w3c_sw {

class SPARQLfedScanner;

    class ParserFilter : public Filter {
    public:
	ParserFilter () : Filter(NULL) {  }
	void setOp (TableOperation* newOp) { op = newOp; }
    };

    class FilterHolder : public ParserFilter {
    public:
	void copyExpressionsTo (OptionalGraphPattern* target) {
	    for (std::vector<const Expression*>::const_iterator it = m_Expressions.begin();
		 it != m_Expressions.end(); ++it)
		target->addExpression(*it);
	    m_Expressions.clear();
	}
    };

/** The Driver class brings together all components. It creates an instance of
 * the SPARQLfedParser and SPARQLfedScanner classes and connects them. Then the input stream is
 * fed into the scanner object and the parser gets it's token
 * sequence. Furthermore the driver object is available in the grammar rules as
 * a parameter. Therefore the driver class contains a reference to the
 * structure into which the parsed data is saved. */

class SPARQLfedDriver : public Driver {
    friend class SPARQLfedParser;
protected:
    const POS* curSubject;
    const POS* curPredicate;
    BasicGraphPattern* curBGP;
    ParserFilter* curFilter;
    TableOperation* curOp; // needed to make right-descending tree for e.g. TriplesBlock? ( ( GraphPatternNotTriples | Filter ) '.'? TriplesBlock? )*
    BindingClause* curBindingClause;
    Binding* curBinding;
    ProductionVector<const Expression*>* curExprList;
    const POS* curGraphName;
    ProductionVector<const Expression*> filterExpressions;

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
    SPARQLfedDriver(std::string baseURI, POSFactory* posFactory);
    ~SPARQLfedDriver();

    virtual bool parse_stream(std::istream& in,
		      const std::string& sname = "stream input");

    /** Pointer to the current lexer instance, this is used to connect the
     * parser to the scanner. It is used in the yylex macro. */
    class SPARQLfedScanner* lexer;

    /** Reference to the object created during parsing of the SPARQL stream. */
    Operation* root;

    /** Control attributes. */
    bool unnestTree;	/* conj(conj(A, B), C) => conj(A, B, C) */
};

} // namespace w3c_sw



/* Line 35 of lalr1.cc.  */
#line 176 "\\\\vboxsvr\\sparul\\lib\\SPARQLfedParser\\SPARQLfedParser.hpp"

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

namespace w3c_sw
{

  /// A Bison parser.
  class SPARQLfedParser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
#line 174 "..\\lib\\SPARQLfedParser\\SPARQLfedParser.ypp"
{
    struct {const POS* subject; const POS* predicate;} p_SubjectPredicatePair;
    struct {int limit; int offset;} p_LimitOffsetPair;
    struct {const URI* uri; LANGTAG* langtag;} p_uri_or_langtag;
    struct {Operation* operation; WhereClause* whereClause;} p_OperationWhereClausePair;
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
    POSList* p_POSList;
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
    ProductionVector<const Binding*>* p_Bindings;
    Binding* p_Binding;
    TableOperation* p_TableOperation;
    ProductionVector<const TableOperation*>* p_TableOperations;
    OptionalGraphPattern* p_OptionalGraphPattern;
    BasicGraphPattern* p_BasicGraphPattern;
    ParserFilter* p_FilterHolder;
    FunctionCall* p_FunctionCall;
    ArgList* p_ArgList;
    const POS* p_POS;
    ProductionVector<const POS*>* p_POSs;
    Expression* p_Expression;
    ProductionVector<const Expression*>* p_Expressions;
    BooleanComparator* p_BooleanComparator;
    const URI* p_URI;
    ProductionVector<const URI*>* p_URIs;
    const RDFLiteral* p_RDFLiteral;
    const BNode* p_BNode;

}
/* Line 35 of lalr1.cc.  */
#line 288 "\\\\vboxsvr\\sparul\\lib\\SPARQLfedParser\\SPARQLfedParser.hpp"
	;
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
     IT_REPLACE = 258,
     IT_WITH = 259,
     IT_DELETE = 260,
     IT_INSERT = 261,
     IT_GRAPH = 262,
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
     IT_BINDINGS = 285,
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
     IT_NULL = 297,
     GT_DOT = 298,
     IT_OPTIONAL = 299,
     IT_UNION = 300,
     IT_FILTER = 301,
     GT_COMMA = 302,
     GT_SEMI = 303,
     IT_a = 304,
     GT_LBRACKET = 305,
     GT_RBRACKET = 306,
     GT_OR = 307,
     GT_AND = 308,
     GT_EQUAL = 309,
     GT_NEQUAL = 310,
     GT_LT = 311,
     GT_GT = 312,
     GT_LE = 313,
     GT_GE = 314,
     GT_PLUS = 315,
     GT_MINUS = 316,
     GT_DIVIDE = 317,
     GT_NOT = 318,
     IT_STR = 319,
     IT_LANG = 320,
     IT_LANGMATCHES = 321,
     IT_DATATYPE = 322,
     IT_BOUND = 323,
     IT_sameTerm = 324,
     IT_isIRI = 325,
     IT_isURI = 326,
     IT_isBLANK = 327,
     IT_isLITERAL = 328,
     IT_REGEX = 329,
     GT_DTYPE = 330,
     IT_true = 331,
     IT_false = 332,
     INTEGER = 333,
     DECIMAL = 334,
     DOUBLE = 335,
     INTEGER_POSITIVE = 336,
     DECIMAL_POSITIVE = 337,
     DOUBLE_POSITIVE = 338,
     INTEGER_NEGATIVE = 339,
     DECIMAL_NEGATIVE = 340,
     DOUBLE_NEGATIVE = 341,
     STRING_LITERAL1 = 342,
     STRING_LITERAL_LONG1 = 343,
     STRING_LITERAL2 = 344,
     STRING_LITERAL_LONG2 = 345,
     IRI_REF = 346,
     PNAME_NS = 347,
     PNAME_LN = 348,
     BLANK_NODE_LABEL = 349,
     ANON = 350,
     VAR1 = 351,
     VAR2 = 352,
     LANGTAG = 353,
     NIL = 354
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

  private:
    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Generate an error message.
    /// \param state   the state where the error occurred.
    /// \param tok     the look-ahead token.
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
#endif /* ! YYDEBUG */


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

    /* Debugging.  */
    int yydebug_;
    std::ostream* yycdebug_;


    /* User arguments.  */
    class SPARQLfedDriver& driver;
  };
}


#endif /* ! defined PARSER_HEADER_H */