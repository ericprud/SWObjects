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
 ** \file tmp/MapSetParser/MapSetParser.hpp
 ** Define the w3c_sw::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_W3C_SW_TMP_MAPSETPARSER_MAPSETPARSER_HPP_INCLUDED
# define YY_W3C_SW_TMP_MAPSETPARSER_MAPSETPARSER_HPP_INCLUDED
// //                    "%code requires" blocks.
#line 60 "lib/MapSetParser.ypp" // lalr1.cc:377
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
    FilterExpressions* curFilter;
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

#line 226 "tmp/MapSetParser/MapSetParser.hpp" // lalr1.cc:377


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>
# include "stack.hh"
# include "location.hh"


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
#line 298 "tmp/MapSetParser/MapSetParser.hpp" // lalr1.cc:377





  /// A Bison parser.
  class MapSetParser
  {
  public:
#ifndef YYSTYPE
    /// Symbol semantic values.
    union semantic_type
    {
    #line 244 "lib/MapSetParser.ypp" // lalr1.cc:377

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
    ValuesClause* p_ValuesClause;
    const TableOperation* p_TableOperation;
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

#line 373 "tmp/MapSetParser/MapSetParser.hpp" // lalr1.cc:377
    };
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

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
    MapSetParser (class MapSetDriver& driver_yyarg);
    virtual ~MapSetParser ();

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
    MapSetParser (const MapSetParser&);
    MapSetParser& operator= (const MapSetParser&);

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
      yylast_ = 2061,     ///< Last index in yytable_.
      yynnts_ = 268,  ///< Number of nonterminal symbols.
      yyfinal_ = 3, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 175  ///< Number of tokens.
    };


    // User arguments.
    class MapSetDriver& driver;
  };



} // w3c_sw
#line 889 "tmp/MapSetParser/MapSetParser.hpp" // lalr1.cc:377




#endif // !YY_W3C_SW_TMP_MAPSETPARSER_MAPSETPARSER_HPP_INCLUDED
