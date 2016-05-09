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
 ** \file tmp/SQLParser/SQLParser.hpp
 ** Define the w3c_sw::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_W3C_SW_TMP_SQLPARSER_SQLPARSER_HPP_INCLUDED
# define YY_W3C_SW_TMP_SQLPARSER_SQLPARSER_HPP_INCLUDED
// //                    "%code requires" blocks.
#line 46 "lib/SQLParser.ypp" // lalr1.cc:377
 // ##bison2
/* Bison seems to test inclusion with PARSER_HEADER_H, rather than something
 * which varies by parser_class_name . Overriding with define specific to
 * this parser.
 */
#endif /* !PARSER_HEADER_H */
#ifndef SQL_PARSER_HPP
#define SQL_PARSER_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include "SWObjects.hpp" // for IStreamContext
#include "ParserCommon.hpp"
#include "SQL.hpp"

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define LINE std::cerr << __FILE__ "(" TOSTRING(__LINE__) "): warning LINE\n"

extern std::ostream* _Trace;

/* START ClassBlock */

class ProgramFlowException : public std::exception  {
private:
    const char* msg;
public:
    ProgramFlowException(const char* msg) : msg(msg) { }

    // This declaration is not useless:
    // http://gcc.gnu.org/onlinedocs/gcc-3.0.2/gcc_6.html#SEC118

    // See comment in eh_exception.cc.
};
/* END ClassBlock */

namespace w3c_sw {

    namespace parser {

	class IsNullProxy : public sql::BooleanComparator {
	public:
	    IsNullProxy () : BooleanComparator(NULL, NULL) {  }
	    virtual sql::Expression* clone () const {
		return new IsNullProxy();
	    }
	    virtual sql::e_PREC getPrecedence () const { return sql::PREC_GT; }
	    virtual bool mapsTo (const sql::Expression&, sql::AliasMapping::List&) const {
		throw "ProgramFlowException";
	    }
	    virtual bool finalEq (const sql::BooleanGE&) const {
		throw "ProgramFlowException";
	    }	    
	    virtual bool operator== (const sql::Expression&) const {
		throw "ProgramFlowException";
	    }
	    virtual const char* getComparisonNotation () const {
		throw "ProgramFlowException";
	    };
	};
	class IsNotNullProxy : public IsNullProxy {
	    virtual Expression* clone () const {
		return new IsNotNullProxy();
	    }
	};

	struct NoCtorDataType {
	    sql::DataType::e_TYPENAME name;
	    sql::DataType::e_NATIONALITY national;
	    sql::DataType::e_VARIABILITY variable;
	    bool operator== (const NoCtorDataType& ref) const {
		return name == ref.name
		    && national == ref.national
		    && variable == ref.variable;
	    }
	    void make ()
	    { this->name = sql::DataType::TYPENAME_error; national = sql::DataType::NATIONALITY_domestic; variable = sql::DataType::VARIABILITY_fixed; }
	    void make (sql::DataType::e_TYPENAME name)
	    { this->name = name; national = sql::DataType::NATIONALITY_domestic; variable = sql::DataType::VARIABILITY_fixed; }
	    void make (sql::DataType::e_TYPENAME name, sql::DataType::e_VARIABILITY variable)
	    { this->name = name; national = sql::DataType::NATIONALITY_domestic; this->variable = variable; }
	    void make (sql::DataType::e_TYPENAME name, sql::DataType::e_NATIONALITY national, sql::DataType::e_VARIABILITY variable)
	    { this->name = name; this->national = national; this->variable = variable; }
	};

	struct DataTypeProxy : sql::DataType {
	    DataTypeProxy (parser::NoCtorDataType noctor)
		: sql::DataType(noctor.name, noctor.national, noctor.variable)
	    {  }
	};
    } // namespace parser

/** The SQLDriver class brings together all components. It creates an instance of
 * the SQLParser and SQLScanner classes and connects them. Then the input stream is
 * fed into the scanner object and the parser gets it's token
 * sequence. Furthermore the driver object is available in the grammar rules as
 * a parameter. Therefore the driver class contains a reference to the
 * structure into which the parsed data is saved. */
class sqlContext {
public:
    ~sqlContext()
    {
    }
};

class SQLDriver : public YaccDriver
{
public:
    /// construct a new parser driver context
    SQLDriver(sqlContext& context);

    /// enable debug output in the flex scanner
    bool trace_scanning;

    /// enable debug output in the bison parser
    bool trace_parsing;

    /// stream name (file or input stream) used for error messages.
    std::string streamname;

    /** Invoke the scanner and parser for a stream.
     * @param in	input stream
     * @return		true if successfully parsed
     */
    sql::SQLQuery* parse(IStreamContext& in);
    sql::SQLQuery* parse(std::string queryStr);

    // To demonstrate pure handling of parse errors, instead of
    // simply dumping them on the standard error output, we will pass
    // them to the driver using the following two member functions.

    /** Error handling with associated line number. This can be modified to
     * output the error e.g. to a dialog box. */
    void error(const class location& l, const std::string& m);

    /** General error handling. This can be modified to output the error
     * e.g. to a dialog box. */
    void error(const std::string& m);

    /** Pointer to the current lexer instance, this is used to connect the
     * parser to the scanner. It is used in the yylex macro. */
    class SQLScanner* lexer;

    /** Reference to the context filled during parsing of the expressions. */
    sqlContext& context;
    sql::SQLQuery* root;

    sql::schema::Relation* curCreate;
    std::string* curAttributeName;
    sql::schema::Database tables;
    std::vector<const sql::Insert*> inserts;
};

typedef struct {sql::RelationName* relation; sql::SQLQuery* subselect; sql::RelVar* alias; bool optional;} l_TableAlias;
typedef struct {sql::Join* join; const sql::Expression* expr; bool optional;} l_JoinExpression;
typedef struct {std::vector<sql::Join*>* joins; std::vector<const sql::Expression*>* exprs;} l_TableList;
typedef struct {parser::NoCtorDataType type; int size;} l_TypeSize;

} // namespace w3c_sw

// %} // ##bison1

#line 210 "tmp/SQLParser/SQLParser.hpp" // lalr1.cc:377


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
#line 282 "tmp/SQLParser/SQLParser.hpp" // lalr1.cc:377





  /// A Bison parser.
  class SQLParser
  {
  public:
#ifndef YYSTYPE
    /// Symbol semantic values.
    union semantic_type
    {
    #line 214 "lib/SQLParser.ypp" // lalr1.cc:377

    /* Productions */
    std::string* p_NAME;
    sql::SQLQuery* p_Select;
    sql::RValue* p_RValue;
    std::vector<sql::SQLQuery*>* p_Selects;
    // struct {std::vector<sql::Join*>* joins; sql::Expression* where;} p_fromWhere;
    int p_int;
    bool p_bool;
    sql::DataType::e_NATIONALITY p_Nationality;
    sql::DataType::e_VARIABILITY p_Variability;
    std::vector<sql::AliasedSelect*>* p_AttributeList;
    sql::AliasedSelect* p_AliasedSelect;
    sql::AliasAttr* p_AliasAttr;
    l_TableAlias p_tableAlias;
    l_JoinExpression p_JoinExpression;
    sql::BooleanComparator* p_BooleanComparator;
    l_TableList p_TableList;
    const sql::Expression* p_Expression;
    std::vector<const sql::Expression*>* p_Expressions;

    std::vector<sql::Attribute>* p_Attributes;
    parser::NoCtorDataType p_SchemaDatatype;
    l_TypeSize p_TypeSize;

#line 322 "tmp/SQLParser/SQLParser.hpp" // lalr1.cc:377
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
        IT_SELECT = 258,
        IT_UNION = 259,
        IT_WHERE = 260,
        IT_FROM = 261,
        GT_TIMES = 262,
        IT_AS = 263,
        GT_DOT = 264,
        IT_INNER = 265,
        IT_LEFT = 266,
        IT_OUTER = 267,
        IT_ON = 268,
        IT_JOIN = 269,
        GT_OR = 270,
        IT_OR = 271,
        IT_AND = 272,
        IT_ROWNUM = 273,
        IT_LIMIT = 274,
        IT_OFFSET = 275,
        IT_IS = 276,
        IT_NOT = 277,
        IT_NULL = 278,
        GT_EQUAL = 279,
        GT_NEQUAL = 280,
        GT_LT = 281,
        GT_GT = 282,
        GT_LE = 283,
        GT_GE = 284,
        GT_PLUS = 285,
        GT_MINUS = 286,
        GT_DIVIDE = 287,
        GT_NOT = 288,
        IT_CONCAT = 289,
        IT_LCASE = 290,
        IT_UCASE = 291,
        IT_REGEX = 292,
        IT_INTEGER = 293,
        IT_VALUES = 294,
        IT_VARCHAR = 295,
        IT_UNIQUE = 296,
        IT_INSERT = 297,
        IT_DEFAULT = 298,
        IT_CONSTRAINT = 299,
        GT_SEMI = 300,
        IT_CREATE = 301,
        IT_TABLE = 302,
        GT_LPAREN = 303,
        GT_RPAREN = 304,
        GT_COMMA = 305,
        IT_FOREIGN = 306,
        IT_KEY = 307,
        IT_REFERENCES = 308,
        IT_PRIMARY = 309,
        IT_INT = 310,
        IT_DOUBLE = 311,
        IT_FLOAT = 312,
        IT_REAL = 313,
        IT_DATE = 314,
        IT_DATETIME = 315,
        IT_TIMESTAMP = 316,
        IT_CHAR = 317,
        IT_BOOLEAN = 318,
        IT_BINARY = 319,
        IT_VARBINARY = 320,
        IT_INTO = 321,
        IT_INTERVAL = 322,
        IT_WRITE = 323,
        IT_TABLES = 324,
        IT_READ = 325,
        IT_LARGE = 326,
        IT_SMALLINT = 327,
        IT_TIME = 328,
        IT_BIGINT = 329,
        IT_VARYING = 330,
        IT_EXISTS = 331,
        IT_UNLOCK = 332,
        IT_NATIONAL = 333,
        IT_DECIMAL = 334,
        IT_NUMERIC = 335,
        IT_LOCK = 336,
        IT_CHARACTER = 337,
        IT_PRECISION = 338,
        IT_IF = 339,
        IT_ALTER = 340,
        IT_ADD = 341,
        IT_DROP = 342,
        IT_OBJECT = 343,
        IT_CAST = 344,
        NAME = 345,
        STRING_LITERAL1 = 346,
        STRING_LITERAL2 = 347,
        INTEGER = 348,
        INTEGER_POSITIVE = 349,
        INTEGER_NEGATIVE = 350,
        DECIMAL = 351,
        DECIMAL_POSITIVE = 352,
        DECIMAL_NEGATIVE = 353,
        DOUBLE = 354,
        DOUBLE_POSITIVE = 355,
        DOUBLE_NEGATIVE = 356,
        HEX_LITERAL = 357,
        IT_TRUE = 358,
        IT_FALSE = 359
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
    SQLParser (class SQLDriver& driver_yyarg);
    virtual ~SQLParser ();

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
    SQLParser (const SQLParser&);
    SQLParser& operator= (const SQLParser&);

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
  static const unsigned char yydefact_[];

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
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

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
      yylast_ = 331,     ///< Last index in yytable_.
      yynnts_ = 117,  ///< Number of nonterminal symbols.
      yyfinal_ = 73, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 105  ///< Number of tokens.
    };


    // User arguments.
    class SQLDriver& driver;
  };



} // w3c_sw
#line 768 "tmp/SQLParser/SQLParser.hpp" // lalr1.cc:377




#endif // !YY_W3C_SW_TMP_SQLPARSER_SQLPARSER_HPP_INCLUDED
