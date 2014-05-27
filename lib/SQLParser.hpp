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
# define PARSER_HEADER_H

/* "%code requires" blocks.  */

/* Line 35 of lalr1.cc  */
#line 46 "lib/SQLParser.ypp"
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



/* Line 35 of lalr1.cc  */
#line 211 "tmp/SQLParser/SQLParser.hpp"


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
#line 241 "tmp/SQLParser/SQLParser.hpp"

  /// A Bison parser.
  class SQLParser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 35 of lalr1.cc  */
#line 214 "lib/SQLParser.ypp"

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



/* Line 35 of lalr1.cc  */
#line 282 "tmp/SQLParser/SQLParser.hpp"
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
    /// Token type.
    typedef token::yytokentype token_type;

    /// Build a parser object.
    SQLParser (class SQLDriver& driver_yyarg);
    virtual ~SQLParser ();

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
    static const unsigned char yydefact_[];

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
    static const unsigned char yystos_[];

    /// For a rule, its LHS.
    static const unsigned char yyr1_[];
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
    class SQLDriver& driver;
  };

} // w3c_sw

/* Line 35 of lalr1.cc  */
#line 576 "tmp/SQLParser/SQLParser.hpp"



#endif /* ! defined PARSER_HEADER_H */
