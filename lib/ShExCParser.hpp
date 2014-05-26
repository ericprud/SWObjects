
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
# define PARSER_HEADER_H

/* "%code requires" blocks.  */

/* Line 35 of lalr1.cc  */
#line 46 "..\\..\\lib\\ShExCParser.ypp"
 // ##bison2
/* Bison seems to test inclusion with PARSER_HEADER_H, rather than something
 * which varies by parser_class_name . Overriding with define specific to
 * this parser.
 */
#endif /* !PARSER_HEADER_H */
#ifndef SWSEX_PARSER_HPP
#define SWSEX_PARSER_HPP

#include "SWObjects.hpp"
#include "RdfDB.hpp"
#include "ParserCommon.hpp"
#include "ShExSchema.hpp"
#include <stack>

namespace w3c_sw {

class SWSexDriver : public YaccDataDriver {
    location* yylloc; // can't move up into YaccDriver 'cause location.hh hasn't been included yet.
    friend class SWSexParser;
protected:
    SWSexSchema* curSchema;
    SWSexSchema::SetRule* curSetRule;
    SWSexSchema::AtomicRule::NameClass* curNameClass;
    SWSexSchema::RulePattern* curRulePattern;
    std::vector<const TTerm*>* curTTerms;
    const TTerm* curSubject;
    const TTerm* curPredicate;
public:
    void setSchema (SWSexSchema* schema) { curSchema = schema; }
    static size_t DefaultAbortErrorCount;

    SWSexDriver (std::string baseURI, AtomFactory* atomFactory, size_t abortErrorCount = DefaultAbortErrorCount)
	: YaccDataDriver(baseURI, atomFactory, abortErrorCount)
    {  }

    SWSexSchema* parse(IStreamContext& in);
    SWSexSchema* parse(IStreamContext& in, SWSexSchema* schema);
    SWSexSchema* parse(std::string swsexStr, SWSexSchema* schema);


    /** Pointer to the current lexer instance, this is used to connect the
     * parser to the scanner. It is used in the yylex macro. */
    class SWSexScanner* lexer;

    const BNode* createBNode () {
	if (descriptiveBNodeLabels) {
	    std::stringstream ss;
	    ss << *(yylloc->begin.filename) <<":"<< yylloc->begin.line <<":"<< yylloc->begin.column;
	    return atomFactory->getBNode(ss.str(), &bnodeMap);
	} else {
	    return atomFactory->createBNode();
	}
    }
};

} // namespace w3c_sw

// %} // ##bison1



/* Line 35 of lalr1.cc  */
#line 108 "C:\\Users\\Jelle\\Documents\\GitHub\\SWObjects\\lib\\ShExCParser.hpp"


#include <string>
#include <iostream>
#include "stack.hh"


/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace w3c_sw {

/* Line 35 of lalr1.cc  */
#line 122 "C:\\Users\\Jelle\\Documents\\GitHub\\SWObjects\\lib\\ShExCParser.hpp"
  class position;
  class location;

/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 35 of lalr1.cc  */
#line 132 "C:\\Users\\Jelle\\Documents\\GitHub\\SWObjects\\lib\\ShExCParser.hpp"

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
#line 180 "C:\\Users\\Jelle\\Documents\\GitHub\\SWObjects\\lib\\ShExCParser.hpp"

  /// A Bison parser.
  class SWSexParser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 35 of lalr1.cc  */
#line 109 "..\\..\\lib\\ShExCParser.ypp"

    struct {std::string* label; std::string* text;} p_CODE;
    int p_int;
    SWSexSchema::AtomicRule::NameClass* p_nameClass;
    bool p_bool;
    SWSexSchema::SetRule* p_setRule;
    SWSexSchema::RulePattern* p_rulePattern;
    SWSexSchema::RuleActions* p_ruleActions;
    SWSexSchema::AtomicRule::Value* p_value;
    SWSexSchema::AtomicRule::ValueSet* p_valueSet;
    struct {unsigned min; unsigned max;} p_RepeatRange;

    struct {const URI* uri; LANGTAG* langtag;} p_uri_or_langtag;

    /* Terminals */
    LANGTAG* p_LANGTAG;

    std::string* p_string;

    const NumericRDFLiteral* p_NumericRDFLiteral;
    SWSexSchema::URIstem p_URIstem;
    std::vector<SWSexSchema::URIstem>* p_URIstems;

    const TTerm* p_TTerm;
    const URI* p_URI;
    struct {const TTerm* subject; const TTerm* predicate;} p_SubjectPredicatePair;




/* Line 35 of lalr1.cc  */
#line 224 "C:\\Users\\Jelle\\Documents\\GitHub\\SWObjects\\lib\\ShExCParser.hpp"
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
     IT_start = 258,
     GT_EQUAL = 259,
     IT_BASE = 260,
     IT_PREFIX = 261,
     GT_LCURLEY = 262,
     GT_RCURLEY = 263,
     GT_PIPE = 264,
     GT_COMMA = 265,
     GT_DOLLAR = 266,
     GT_OPT = 267,
     GT_LPAREN = 268,
     GT_RPAREN = 269,
     GT_CARROT = 270,
     GT_DOT = 271,
     GT_AT = 272,
     IT_SPARQL_SRX = 273,
     GT_KINDA = 274,
     GT_SEMI = 275,
     GT_LBRACKET = 276,
     GT_RBRACKET = 277,
     GT_MINUS = 278,
     GT_TIMES = 279,
     GT_PLUS = 280,
     GT_DTYPE = 281,
     RDF_TYPE = 282,
     CODE = 283,
     IT_true = 284,
     IT_false = 285,
     BLANK_NODE_LABEL = 286,
     ANON = 287,
     INTEGER = 288,
     DECIMAL = 289,
     DOUBLE = 290,
     STRING_LITERAL1 = 291,
     STRING_LITERAL2 = 292,
     STRING_LITERAL_LONG1 = 293,
     STRING_LITERAL_LONG2 = 294,
     PNAME_NS = 295,
     PNAME_LN = 296,
     IRIREF = 297,
     LANGTAG = 298
   };

    };
    /// Token type.
    typedef token::yytokentype token_type;

    /// Build a parser object.
    SWSexParser (class SWSexDriver& driver_yyarg);
    virtual ~SWSexParser ();

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
    static const unsigned char yydefact_[];

    static const short int yypgoto_[];
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
    class SWSexDriver& driver;
  };

/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 35 of lalr1.cc  */
#line 454 "C:\\Users\\Jelle\\Documents\\GitHub\\SWObjects\\lib\\ShExCParser.hpp"



#endif /* ! defined PARSER_HEADER_H */
