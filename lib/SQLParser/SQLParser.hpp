
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
#line 45 "lib/SQLParser/SQLParser.ypp"
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
#include "SQL.hpp"

#define w3c_sw_STRINGIFY(x) #x
#define w3c_sw_TOSTRING(x) w3c_sw_STRINGIFY(x)
#define w3c_sw_LINE std::cerr << __FILE__ "(" w3c_sw_TOSTRING(__LINE__) "): warning LINE\n"

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

class SQLDriver
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
    bool parse(IStreamContext& in);

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
};
    typedef struct {std::string* relation; sql::SQLQuery* subselect; std::string* alias;} l_TableAlias;
    typedef struct {sql::Join* join; const sql::Expression* expr;} l_JoinExpression;
    typedef struct {std::vector<sql::Join*>* joins; std::vector<const sql::Expression*>* exprs;} l_TableList;

} // namespace w3c_sw

// %} // ##bison1



/* Line 35 of lalr1.cc  */
#line 150 "lib/SQLParser/SQLParser.hpp"


#include <string>
#include <iostream>
#include "stack.hh"


/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace w3c_sw {

/* Line 35 of lalr1.cc  */
#line 164 "lib/SQLParser/SQLParser.hpp"
  class position;
  class location;

/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 35 of lalr1.cc  */
#line 174 "lib/SQLParser/SQLParser.hpp"

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
#line 222 "lib/SQLParser/SQLParser.hpp"

  /// A Bison parser.
  class SQLParser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 35 of lalr1.cc  */
#line 150 "lib/SQLParser/SQLParser.ypp"

    /* Productions */
    std::string* p_NAME;
    sql::SQLQuery* p_Select;
    std::vector<sql::SQLQuery*>* p_Selects;
    // struct {std::vector<sql::Join*>* joins; sql::WhereConstraint* where;} p_fromWhere;
    std::vector<sql::AliasedSelect*>* p_AttributeList;
    sql::AliasedSelect* p_AliasedSelect;
    sql::AliasAttr* p_AliasAttr;
    l_TableAlias p_tableAlias;
    l_JoinExpression p_JoinExpression;
    sql::BooleanComparator* p_BooleanComparator;
    l_TableList p_TableList;
    const sql::Expression* p_Expression;
    std::vector<const sql::Expression*>* p_Expressions;




/* Line 35 of lalr1.cc  */
#line 255 "lib/SQLParser/SQLParser.hpp"
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
     GT_COMMA = 263,
     IT_AS = 264,
     GT_DOT = 265,
     IT_INNER = 266,
     IT_JOIN = 267,
     IT_ON = 268,
     GT_OR = 269,
     GT_AND = 270,
     GT_EQUAL = 271,
     GT_NEQUAL = 272,
     GT_LT = 273,
     GT_GT = 274,
     GT_LE = 275,
     GT_GE = 276,
     GT_PLUS = 277,
     GT_MINUS = 278,
     GT_DIVIDE = 279,
     GT_NOT = 280,
     GT_LPAREN = 281,
     GT_RPAREN = 282,
     IT_CONCAT = 283,
     IT_REGEX = 284,
     NAME = 285,
     INTEGER = 286,
     INTEGER_POSITIVE = 287,
     INTEGER_NEGATIVE = 288,
     DECIMAL = 289,
     DECIMAL_POSITIVE = 290,
     DECIMAL_NEGATIVE = 291,
     DOUBLE = 292,
     DOUBLE_POSITIVE = 293,
     DOUBLE_NEGATIVE = 294,
     STRING_LITERAL1 = 295,
     STRING_LITERAL2 = 296,
     STRING_LITERAL_LONG1 = 297,
     STRING_LITERAL_LONG2 = 298,
     IT_true = 299,
     IT_false = 300
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

    /// Internal symbol numbers.
    typedef unsigned char token_number_type;
    /* Tables.  */
    /// For a state, the index in \a yytable_ of its portion.
    static const signed char yypact_[];
    static const signed char yypact_ninf_;

    /// For a state, default rule to reduce.
    /// Unless\a  yytable_ specifies something else to do.
    /// Zero means the default is an error.
    static const unsigned char yydefact_[];

    static const signed char yypgoto_[];
    static const short int yydefgoto_[];

    /// What to do in a state.
    /// \a yytable_[yypact_[s]]: what to do in state \a s.
    /// - if positive, shift that token.
    /// - if negative, reduce the rule which number is the opposite.
    /// - if zero, do what YYDEFACT says.
    static const unsigned char yytable_[];
    static const signed char yytable_ninf_;

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

#if YYERROR_VERBOSE
    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    virtual std::string yytnamerr_ (const char *n);
#endif

#if YYDEBUG
    /// A type to store symbol numbers and -1.
    typedef signed char rhs_number_type;
    /// A `-1'-separated list of the rules' RHS.
    static const rhs_number_type yyrhs_[];
    /// For each rule, the index of the first RHS symbol in \a yyrhs_.
    static const unsigned char yyprhs_[];
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

/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 35 of lalr1.cc  */
#line 487 "lib/SQLParser/SQLParser.hpp"



#endif /* ! defined PARSER_HEADER_H */
