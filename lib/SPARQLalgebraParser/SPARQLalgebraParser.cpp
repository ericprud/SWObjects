
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
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

// Take the name prefix into account.
#define yylex   w3c_swlex

/* First part of user declarations.  */


/* Line 311 of lalr1.cc  */
#line 43 "lib/SPARQLalgebraParser/SPARQLalgebraParser.cpp"


#include "SPARQLalgebraParser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 262 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"

#include "../SPARQLalgebraScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 320 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"

#include <stdarg.h>
#include "SPARQLalgebraScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc  */
#line 69 "lib/SPARQLalgebraParser/SPARQLalgebraParser.cpp"

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


/* Line 380 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace w3c_sw {

/* Line 380 of lalr1.cc  */
#line 138 "lib/SPARQLalgebraParser/SPARQLalgebraParser.cpp"
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  SPARQLalgebraParser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  SPARQLalgebraParser::SPARQLalgebraParser (class SPARQLalgebraDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  SPARQLalgebraParser::~SPARQLalgebraParser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  SPARQLalgebraParser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  SPARQLalgebraParser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  SPARQLalgebraParser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  SPARQLalgebraParser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  SPARQLalgebraParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  SPARQLalgebraParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  SPARQLalgebraParser::debug_level_type
  SPARQLalgebraParser::debug_level () const
  {
    return yydebug_;
  }

  void
  SPARQLalgebraParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  SPARQLalgebraParser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 553 of lalr1.cc  */
#line 37 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 322 "lib/SPARQLalgebraParser/SPARQLalgebraParser.cpp"

    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:

/* Line 678 of lalr1.cc  */
#line 337 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 340 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 350 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(4) - (3)].p_Operation);
    }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 357 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(4) - (3)].p_Operation);
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 364 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Select((yysemantic_stack_[(4) - (3)].p_protoSelect).distinctness, (yysemantic_stack_[(4) - (3)].p_protoSelect).varSet, (yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_protoSelect).p_WhereClause, (yysemantic_stack_[(4) - (3)].p_protoSelect).p_SolutionModifier);
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 367 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(4) - (2)].p_DatasetClauses), new WhereClause((yysemantic_stack_[(4) - (3)].p_op)));
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 370 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Ask(new ProductionVector<const DatasetClause*>(), new WhereClause((yysemantic_stack_[(1) - (1)].p_op)));
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 373 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Select((yysemantic_stack_[(1) - (1)].p_protoSelect).distinctness, (yysemantic_stack_[(1) - (1)].p_protoSelect).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(1) - (1)].p_protoSelect).p_WhereClause, (yysemantic_stack_[(1) - (1)].p_protoSelect).p_SolutionModifier);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 379 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>((yysemantic_stack_[(1) - (1)].p_DatasetClause));
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 382 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 390 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(1) - (1)].p_protoSelect);
	(yyval.p_protoSelect).p_SolutionModifier = new SolutionModifier(NULL, NULL, NULL, -1, -1);
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 398 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(1) - (1)].p_protoSelect);
	(yyval.p_protoSelect).distinctness = DIST_all;
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 406 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(1) - (1)].p_protoSelect);
	(yyval.p_protoSelect).varSet = new StarVarSet();
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 414 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(1) - (1)].p_protoSelect);
	(yyval.p_protoSelect).p_OrderConditions = NULL;
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 422 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(1) - (1)].p_protoSelect);
	(yyval.p_protoSelect).p_having = NULL;
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 429 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	throw std::string("ExtendOpt: not ready to parse aggregates");
	(yyval.p_protoSelect) = (yysemantic_stack_[(4) - (3)].p_protoSelect);
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 433 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(1) - (1)].p_protoSelect);
    }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 440 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect).p_WhereClause = new WhereClause((yysemantic_stack_[(1) - (1)].p_op));
    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 448 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = (yysemantic_stack_[(4) - (3)].p_op);
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 454 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 464 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 466 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 468 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(6) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(6) - (5)].p_URI));
      }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 480 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(7) - (6)].p_protoSelect);
	(yyval.p_protoSelect).varSet = (yysemantic_stack_[(7) - (4)].p_ExpressionAliaseList);
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 487 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList();
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 490 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_Variable))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 497 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	throw std::string("Extend: not ready to parse aggregates");
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 530 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(4) - (3)].p_protoSelect);
	(yyval.p_protoSelect).distinctness = DIST_distinct;
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 534 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(4) - (3)].p_protoSelect);
	(yyval.p_protoSelect).distinctness = DIST_reduced;
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 570 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	throw std::string("GroupClause: not ready to parse aggregates");
	(yyval.p_protoSelect).p_WhereClause = new WhereClause((yysemantic_stack_[(10) - (9)].p_op));
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 589 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(5) - (4)].p_protoSelect);
	(yyval.p_protoSelect).p_having = new w3c_sw::ProductionVector<const w3c_sw::Expression*>((yysemantic_stack_[(5) - (3)].p_Expression)); // !!!
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 598 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(7) - (6)].p_protoSelect);
	(yyval.p_protoSelect).p_OrderConditions = (yysemantic_stack_[(7) - (4)].p_OrderConditions);
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 605 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 609 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 617 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 624 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 628 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 634 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(4) - (2)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(4) - (3)].p_Expression);
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 641 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(6) - (5)].p_protoSelect); // ($5.p_group, ...)
	(yyval.p_protoSelect).p_SolutionModifier = new SolutionModifier(NULL, (yysemantic_stack_[(6) - (5)].p_protoSelect).p_having, (yysemantic_stack_[(6) - (5)].p_protoSelect).p_OrderConditions, (yysemantic_stack_[(6) - (3)].p_int), (yysemantic_stack_[(6) - (4)].p_int)); // !!!
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 648 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_int) = ((IntegerRDFLiteral*)(yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 651 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_int) = LIMIT_None;
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 675 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(4) - (3)].p_Operation);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 682 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(4) - (3)].p_Operation);
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 689 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(3) - (2)]. p_OperationSet);
}
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 695 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	OperationSet* ret = new OperationSet();
	ret->push_back((yysemantic_stack_[(1) - (1)].p_Operation));
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 699 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)]. p_OperationSet)->push_back((yysemantic_stack_[(2) - (2)].p_Operation));
	(yyval. p_OperationSet) = (yysemantic_stack_[(2) - (1)]. p_OperationSet);
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 722 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (4)].p_URI));
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 728 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 737 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(5) - (3)].p_Silence), (yysemantic_stack_[(5) - (4)].p_URI));
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 743 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 746 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 754 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(5) - (3)].p_Silence), (yysemantic_stack_[(5) - (4)].p_URI));
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 762 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(5) - (3)].p_Silence), (yysemantic_stack_[(5) - (4)].p_URI));
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 770 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(6) - (3)].p_Silence), (yysemantic_stack_[(6) - (4)].p_URI), (yysemantic_stack_[(6) - (5)].p_URI));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 778 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(6) - (3)].p_Silence), (yysemantic_stack_[(6) - (4)].p_URI), (yysemantic_stack_[(6) - (5)].p_URI));
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 786 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(6) - (3)].p_Silence), (yysemantic_stack_[(6) - (4)].p_URI), (yysemantic_stack_[(6) - (5)].p_URI));
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 794 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Insert((yysemantic_stack_[(4) - (3)].p_op), NULL);
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 802 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(4) - (3)].p_op), NULL);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 810 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(4) - (3)].p_op), NULL);
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 818 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(6) - (5)].p_DeleteInsert).del, (yysemantic_stack_[(6) - (5)].p_DeleteInsert).ins, new WhereClause((yysemantic_stack_[(6) - (4)].p_op)));
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 824 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 827 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 834 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 841 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 845 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 854 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Delete) = new Delete((yysemantic_stack_[(4) - (3)].p_op), NULL);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 862 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Insert) = new Insert((yysemantic_stack_[(4) - (3)].p_op), NULL);
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 870 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(4) - (3)].p_URI), driver.atomFactory);
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 873 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(5) - (3)].p_URI), driver.atomFactory);
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 881 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 897 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	w3c_sw_NEED_IMPL("DEFAULT");
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 900 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	w3c_sw_NEED_IMPL("NAMED");
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 903 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	w3c_sw_NEED_IMPL("ALL");
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 919 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = (yysemantic_stack_[(1) - (1)].p_conj);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 930 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_conj) = new ParserTableConjunction();
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 933 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_conj)->addTableOperation((yysemantic_stack_[(2) - (2)].p_op), false);
	(yyval.p_conj) = (yysemantic_stack_[(2) - (1)].p_conj);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 940 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = driver.curGraphName;
	driver.curGraphName = (yysemantic_stack_[(2) - (2)].p_TTerm);
      }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 943 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	  (yyval.p_op) = (yysemantic_stack_[(4) - (4)].p_op);
	  driver.curGraphName = (yysemantic_stack_[(4) - (3)].p_TTerm);
      }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 950 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = (yysemantic_stack_[(4) - (3)].p_BasicGraphPattern);
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 953 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = driver.ensureGraphPattern();
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 959 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_BasicGraphPattern) = driver.ensureGraphPattern();
	(yyval.p_BasicGraphPattern)->addTriplePattern((yysemantic_stack_[(1) - (1)].p_TriplePattern));
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 963 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_BasicGraphPattern)->addTriplePattern((yysemantic_stack_[(2) - (2)].p_TriplePattern));
	(yyval.p_BasicGraphPattern) = (yysemantic_stack_[(2) - (1)].p_BasicGraphPattern);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 972 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(5) - (4)].p_conj)->insertTableOperation((yysemantic_stack_[(5) - (3)].p_op));
	(yyval.p_op) = (yysemantic_stack_[(5) - (4)].p_conj);
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 981 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	throw new std::string("GroupGraphPatternNoSub: GT_LPAREN IT_path VarOrTerm Path VarOrTerm GT_RPAREN not implemented");
	(yyval.p_op) = driver.ensureGraphPattern();
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 993 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_conj) = new ParserTableConjunction();
	(yyval.p_conj)->addTableOperation((yysemantic_stack_[(1) - (1)].p_op), driver.unnestTree);
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 997 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_conj)->addTableOperation((yysemantic_stack_[(2) - (2)].p_op), driver.unnestTree);
	(yyval.p_conj) = (yysemantic_stack_[(2) - (1)].p_conj);
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1006 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(5) - (4)].p_conj)->addTableOperation((yysemantic_stack_[(5) - (3)].p_op), driver.unnestTree);
	(yyval.p_op) = (yysemantic_stack_[(5) - (4)].p_conj);
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1015 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	throw new std::string("GroupGraphPatternSub: GT_LPAREN IT_path VarOrTerm Path VarOrTerm GT_RPAREN not implemented");
	(yyval.p_op) = driver.ensureGraphPattern();
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1019 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = new SubSelect(new Select((yysemantic_stack_[(1) - (1)].p_protoSelect).distinctness, (yysemantic_stack_[(1) - (1)].p_protoSelect).varSet, NULL, (yysemantic_stack_[(1) - (1)].p_protoSelect).p_WhereClause, (yysemantic_stack_[(1) - (1)].p_protoSelect).p_SolutionModifier));
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1025 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_conj) = new ParserTableConjunction();
	(yyval.p_conj)->addTableOperation((yysemantic_stack_[(1) - (1)].p_op), driver.unnestTree);
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1029 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_conj)->addTableOperation((yysemantic_stack_[(2) - (2)].p_op), driver.unnestTree);
	(yyval.p_conj) = (yysemantic_stack_[(2) - (1)].p_conj);
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1036 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(4) - (3)].p_Expressions);
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1042 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 1045 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 1052 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TriplePattern) = driver.atomFactory->getTriple((yysemantic_stack_[(6) - (3)].p_TTerm), (yysemantic_stack_[(6) - (4)].p_TTerm), (yysemantic_stack_[(6) - (5)].p_TTerm));
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 1066 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	OptionalGraphPattern* opt = new OptionalGraphPattern((yysemantic_stack_[(6) - (4)].p_op));
	TableConjunction* conj = new TableConjunction();
	conj->addTableOperation((yysemantic_stack_[(6) - (3)].p_op), driver.unnestTree);
	conj->addTableOperation(opt, driver.unnestTree);
	if ((yysemantic_stack_[(6) - (5)].p_Expressions) != NULL) {
	    for (std::vector<const Expression*>::const_iterator it = (yysemantic_stack_[(6) - (5)].p_Expressions)->begin();
		 it != (yysemantic_stack_[(6) - (5)].p_Expressions)->end(); ++it)
		opt->addExpression(*it);
	    (yysemantic_stack_[(6) - (5)].p_Expressions)->clear();
	    delete (yysemantic_stack_[(6) - (5)].p_Expressions);
	}
	(yyval.p_op) = conj;
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1080 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	OptionalGraphPattern* opt = new OptionalGraphPattern((yysemantic_stack_[(5) - (3)].p_op));
	if ((yysemantic_stack_[(5) - (4)].p_Expressions) != NULL) {
	    for (std::vector<const Expression*>::const_iterator it = (yysemantic_stack_[(5) - (4)].p_Expressions)->begin();
		 it != (yysemantic_stack_[(5) - (4)].p_Expressions)->end(); ++it)
		opt->addExpression(*it);
	    (yysemantic_stack_[(5) - (4)].p_Expressions)->clear();
	    delete (yysemantic_stack_[(5) - (4)].p_Expressions);
	}
	(yyval.p_op) = opt;
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1094 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1101 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = driver.curGraphName;
	driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1104 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	  (yyval.p_op) = (yysemantic_stack_[(6) - (5)].p_op);
	  driver.curGraphName = (yysemantic_stack_[(6) - (4)].p_TTerm);
      }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1111 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = new ServiceGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), (yysemantic_stack_[(6) - (5)].p_op), (yysemantic_stack_[(6) - (3)].p_Silence), driver.atomFactory, false);
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 1119 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	TableConjunction* ret = new TableConjunction();
	ret->addTableOperation((yysemantic_stack_[(5) - (3)].p_op), driver.unnestTree);
	ret->addTableOperation(new MinusGraphPattern((yysemantic_stack_[(5) - (4)].p_op)), driver.unnestTree);
	(yyval.p_op) = ret;
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 1128 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	TableDisjunction* ret = new TableDisjunction();
	ret->addTableOperation((yysemantic_stack_[(5) - (3)].p_op), driver.unnestTree);
	ret->addTableOperation((yysemantic_stack_[(5) - (4)].p_op), driver.unnestTree);
	(yyval.p_op) = ret;
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 1137 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = new Filter((yysemantic_stack_[(5) - (4)].p_op), (yysemantic_stack_[(5) - (3)].p_Expressions)->begin(), (yysemantic_stack_[(5) - (3)].p_Expressions)->end());
	(yysemantic_stack_[(5) - (3)].p_Expressions)->clear();
	delete (yysemantic_stack_[(5) - (3)].p_Expressions);
    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1153 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 1156 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(4) - (3)].p_Expressions)->push_front((yysemantic_stack_[(4) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(4) - (3)].p_Expressions);
    }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 1163 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 1169 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 1172 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 1229 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	// $$ = new PathAlternative($3, $4);
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 1235 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	// $$ = new PathSequence($3, $4);
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 1243 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	// $$ = new PathEltOrInverse($3);
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 1249 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	// $$ = $3;
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 1252 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	// $$ = $5;
      }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 1264 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 1267 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1275 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(4) - (3)].p_TTerm);
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1282 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	// $1->push_back($2);
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (1)].p_TTerm);
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1289 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 1306 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 1313 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 1316 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 1327 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 1331 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 1334 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 1338 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil");
    }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 1353 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yysemantic_stack_[(5) - (3)].p_Expression));
	t->push_back((yysemantic_stack_[(5) - (4)].p_Expression));
	(yyval.p_Expression) = new BooleanDisjunction(t);
    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 1362 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yysemantic_stack_[(5) - (3)].p_Expression));
	t->push_back((yysemantic_stack_[(5) - (4)].p_Expression));
	(yyval.p_Expression) = new BooleanConjunction(t);
    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 1380 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanEQ((yysemantic_stack_[(5) - (3)].p_Expression), (yysemantic_stack_[(5) - (4)].p_Expression));
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 1383 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNE((yysemantic_stack_[(5) - (3)].p_Expression), (yysemantic_stack_[(5) - (4)].p_Expression));
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 1386 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanLT((yysemantic_stack_[(5) - (3)].p_Expression), (yysemantic_stack_[(5) - (4)].p_Expression));
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 1389 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanGT((yysemantic_stack_[(5) - (3)].p_Expression), (yysemantic_stack_[(5) - (4)].p_Expression));
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 1392 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanLE((yysemantic_stack_[(5) - (3)].p_Expression), (yysemantic_stack_[(5) - (4)].p_Expression));
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 1395 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanGE((yysemantic_stack_[(5) - (3)].p_Expression), (yysemantic_stack_[(5) - (4)].p_Expression));
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 1398 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new NaryIn((yysemantic_stack_[(4) - (3)].p_Expressions));
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 1410 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yysemantic_stack_[(5) - (3)].p_Expression));
	t->push_back((yysemantic_stack_[(5) - (4)].p_Expression));
	(yyval.p_Expression) = new ArithmeticSum(t);
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 1416 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yysemantic_stack_[(5) - (3)].p_Expression));
	t->push_back(new ArithmeticNegation((yysemantic_stack_[(5) - (4)].p_Expression)));
	(yyval.p_Expression) = new ArithmeticSum(t);
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 1430 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yysemantic_stack_[(5) - (3)].p_Expression));
	t->push_back(new ArithmeticNegation((yysemantic_stack_[(5) - (4)].p_Expression)));
	(yyval.p_Expression) = new ArithmeticProduct(t);
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 1436 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yysemantic_stack_[(5) - (3)].p_Expression));
	t->push_back(new ArithmeticInverse((yysemantic_stack_[(5) - (4)].p_Expression)));
	(yyval.p_Expression) = new ArithmeticProduct(t);
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 1445 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(4) - (3)].p_Expression));
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 1448 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(4) - (3)].p_Expression);
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 1451 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(4) - (3)].p_Expression));
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 1459 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 1462 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 1465 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 1468 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 1471 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 1482 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 1485 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 1488 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 1491 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 1494 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 1497 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 1500 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 1503 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 1506 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 1509 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 1512 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ciel, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 1515 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 1518 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 1521 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(4) - (3)].p_Expressions))));
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 1525 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 1528 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 1531 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 1534 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 1537 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 1540 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 1543 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 1546 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 1549 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 1552 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 1555 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 1558 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 1561 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 1564 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 1567 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 1570 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 1573 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 1576 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha224, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 1579 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 1582 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 1585 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 1588 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 1592 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 1595 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 1598 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 1601 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 1604 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 1607 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 1610 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 1613 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 1616 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 1624 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 1633 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 1639 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 1646 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 1652 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.ensureGraphPattern(), NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 1674 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
 	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(3) - (2)].p_distinctness), (yysemantic_stack_[(3) - (3)].p_Expression)));
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 1680 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 1683 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
}
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 1689 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 1696 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(3) - (1)].p_URI), (yysemantic_stack_[(3) - (2)].p_distinctness), (yysemantic_stack_[(3) - (3)].p_Expression)));
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 1702 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 1705 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 1708 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 1711 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 1714 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 1720 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(3) - (2)].p_distinctness), (yysemantic_stack_[(3) - (3)].p_Expression)));
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 1723 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(4) - (2)].p_distinctness), (yysemantic_stack_[(4) - (4)].p_Expression)));
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 1733 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 1736 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(4) - (2)].p_URI), new ArgList((yysemantic_stack_[(4) - (3)].p_Expressions))));
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 1742 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 1749 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 1755 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 1759 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 1766 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 2480 "lib/SPARQLalgebraParser/SPARQLalgebraParser.cpp"
	default:
          break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  SPARQLalgebraParser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int SPARQLalgebraParser::yypact_ninf_ = -639;
  const short int
  SPARQLalgebraParser::yypact_[] =
  {
       -82,  1148,    34,  -639,  -639,  -639,  -639,  -639,  -639,  -639,
    -639,  -639,  -639,  -639,  -639,  -639,  -639,  -639,  -639,  -639,
    -639,  -639,  -639,  -639,  -639,  -639,  -639,  -639,  -639,  -639,
    -639,  -639,  -639,  -639,   -90,   -40,     3,    15,    18,    18,
      22,  1714,    26,    33,    35,  -639,  -639,    33,    33,    33,
      85,  1441,    33,   -67,   -94,    61,   518,    44,    50,    54,
      56,   -36,  -639,  -639,  -639,  -639,  -639,  -639,  -639,  -639,
    -639,  -639,  -639,  -639,  -639,    60,  -639,  -639,  -639,  -639,
    -639,  1389,    72,    74,    68,   757,  -639,  -639,  -639,  -639,
    -639,  -639,  -639,  -639,  -639,  -639,  -639,  -639,  -639,  -639,
    -639,  -639,  -639,  -639,  -639,  -639,  -639,    33,  -639,    82,
    -639,  -639,  -639,  -639,  -639,  -639,  -639,  -639,  -639,  -639,
    -639,  -639,  -639,  -639,  -639,  -639,  -639,  -639,  -639,  -639,
    -639,  -118,  -639,  -639,  1770,  1467,    99,    81,   -25,  -639,
      33,   107,    33,  -639,  -639,  -639,  -639,  -639,  -639,   -18,
    -639,  -639,  -639,  -639,  -639,  -639,  -639,    33,  -639,    85,
    -639,  -639,   -94,  -639,   119,   -10,  -639,   -67,   -10,   -67,
     -10,   -67,   -67,  -639,   -67,  -639,  -639,   -67,  1271,   124,
     143,  -639,  1187,   145,   148,  1231,   152,   153,   613,   155,
    -639,    19,  -639,  1349,  -639,  -639,  -639,  -639,  -639,  -639,
    -639,    33,  -639,  -639,  -639,  -639,  -639,  -639,   -20,   -58,
       0,  -639,  -639,    98,  -639,     1,  1795,  1795,  1795,  1795,
    1795,  1795,  1795,  1795,  1795,   -84,  1795,  1795,  1795,  1795,
    1795,  1795,  1795,  1795,  1795,  1795,  1795,  1795,   -45,  1795,
    1795,  1795,  1795,  1795,  1795,  1795,  1795,  1795,  1795,  1795,
    1795,  1795,  1795,   159,  1795,  1795,  1795,  1795,  1795,  1795,
    1795,  1795,  1795,    33,  1795,  1795,  1795,  1795,  1795,  1795,
    1795,  1795,  1795,  1795,  1795,  1795,  1795,  1795,   163,  1795,
     164,    73,   170,   -10,  -639,  -639,  -639,  -639,   638,  1501,
    -639,  -639,  -639,   107,  -639,  1441,  -639,  -639,   107,   167,
    -639,   177,   186,    33,  -639,    10,  1441,  -639,  -639,  -639,
    -639,  -639,  -639,  -639,   193,    33,   187,  -639,   -10,   191,
     -10,   199,   -97,   -10,    -1,   -97,   201,  -639,   -50,   -97,
     202,  -639,   203,    -1,  -639,  -639,  -639,  -639,  -639,  -639,
    -639,  1441,    60,  -639,     2,  -639,  -639,  -639,   197,  -639,
    -639,   -84,  -639,  1795,   208,  -639,   995,   195,   209,   217,
     218,   220,   221,   223,   230,   234,   236,  1524,  -639,   238,
    1582,  1795,   229,   232,  1795,   246,  1795,   247,  -639,   248,
     249,  -639,  1795,   253,   254,   243,   257,   259,   260,  1795,
    1605,   261,   262,   250,  1795,   252,   266,   267,  -639,   269,
     271,   272,   276,  1663,   264,   265,   281,  1795,   282,  1795,
     270,   286,  1795,  1795,   277,   288,   293,   296,  1686,  1795,
     298,   301,   303,  -639,  1744,  -639,  -639,  -639,  -639,  -639,
    1795,   268,  -639,  1441,   304,  -639,  -639,   305,   -18,   -18,
    -639,  -639,  -639,   -18,   -18,   -94,   -18,   306,  -639,   307,
    1314,   309,   312,  1448,  -639,   308,   313,  -639,  -639,  -639,
     -97,  -639,   320,  -639,  -639,  -639,  -639,  -639,   323,   -97,
    -639,     7,    85,  -639,  -639,  -639,   -97,  -639,  -639,   324,
     -18,    60,  -639,  -639,   273,  1408,   331,  1795,   333,   328,
    1795,  -639,  -639,  -639,  -639,  -639,  -639,  -639,  -639,  -639,
    -639,  -639,  -639,  -639,   337,  1795,  1795,   338,  -639,   339,
    -639,  -639,  -639,  -639,  -639,  -639,  1795,  -639,  -639,  -639,
     340,  -639,   341,  -639,  -639,  1795,   342,  1795,  -639,  -639,
    -639,  -639,  -639,  -639,  -639,  1795,  1795,  -639,   347,  -639,
     350,  1795,  -639,   354,   355,  1795,  -639,  -639,  -639,  -639,
     358,   359,  -639,  -639,  -639,  -639,   360,  1428,   363,  1441,
    -639,  -639,   365,   -18,  -639,   -21,   -18,   -94,   368,  -639,
    -639,  -639,  -639,   -27,   369,   364,  -639,  -639,   370,  -639,
    -639,   372,  -639,   373,  -639,  1441,  -639,    11,  -639,  -639,
     374,  -639,   315,  -639,    12,   366,  -639,   367,   366,  -639,
    -639,   -44,   376,  -639,  -639,   381,  -639,   382,   383,   384,
    -639,  -639,   385,  -639,  -639,   387,  -639,  -639,  -639,  -639,
     389,  -639,   390,  -639,  -639,   391,   -18,  -639,  -639,  -639,
    -639,   431,  -639,  -639,  -639,  -639,   386,  -639,   394,  -639,
    -639,   344,  -639,   388,    33,  -639,  1795,  -639,   400,  1795,
     401,  -639,  -639,  -639,  -639,  -639,  -639,  -639,  -639,  -639,
    -639,  -639,  -639,   403,   404,   405,  -639,  -639,   407,   256,
     408,   409,  -639,  -639,   410,  -639,  -639,  -639,  -639,  -639,
    -639,  -639,  -639,   443,  -639,  -639,   443,   412,  -639,  -639,
     443,  -639,  -639,  -639,  -639,  -639,  1417,  1821,  -639,  1795,
    -639,  -639,  -639,   876,  -639,  1795,  -639,   115,  -639,   414,
    -639
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  SPARQLalgebraParser::yydefact_[] =
  {
         0,     0,     0,     2,     4,     6,     8,    12,    16,    18,
      20,    22,    24,    26,    11,    19,    17,    28,    27,    23,
      21,    15,     3,    71,    73,    75,   135,    53,   138,   139,
     140,   141,   142,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   144,   145,     0,     0,     0,
       0,     0,     0,    94,     0,     0,     0,     0,     0,     0,
       0,     0,    77,    79,    80,    81,    85,    82,    83,    84,
      86,    87,    88,    89,    13,     0,     1,    30,    35,    38,
      41,     0,     0,     0,     0,     0,   337,   338,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   339,   341,   340,
     342,   343,   346,   345,   243,   203,   204,     0,   242,     0,
     211,   212,   213,   219,   221,   220,   229,   214,   215,   216,
     237,   290,   258,   291,   238,   239,   240,   325,   326,   327,
     241,   323,   317,   344,     0,     0,     0,     0,     0,   133,
       0,   166,     0,   168,   201,   202,   210,   347,   348,     0,
     199,   200,   206,   207,   208,   205,   209,     0,    95,     0,
      70,   198,     0,    69,     0,     0,   105,    94,     0,    94,
       0,    94,    94,   127,    94,   127,   127,    94,     0,     0,
       0,    14,     0,     0,     0,     0,     0,     0,     0,     0,
      76,     0,    78,     0,    48,   157,    47,    50,    49,    46,
     148,     0,   151,   152,   153,   154,   155,   149,     0,     0,
       0,    51,    52,     0,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   292,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   321,   322,   324,   319,     0,     0,
      61,    63,    64,     0,    29,     0,   131,   134,   166,     0,
     167,     0,     0,     0,   194,     0,     0,   179,   180,   181,
     182,   184,   183,   193,     0,     0,     0,   132,     0,     0,
       0,     0,     0,    91,     0,     0,     0,   122,   124,     0,
       0,   123,     0,     0,     9,    10,     5,    72,     7,    74,
      25,     0,     0,   146,     0,    31,    32,    36,     0,    39,
      40,     0,    42,     0,     0,    56,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   161,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   293,     0,
       0,   174,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   273,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   252,     0,   173,    59,   320,    65,    66,
       0,     0,    62,     0,     0,   165,   172,     0,     0,     0,
     192,   191,   190,     0,     0,     0,     0,     0,   171,     0,
       0,     0,     0,     0,   106,     0,     0,   117,   113,   115,
       0,   116,     0,    92,   120,   121,   119,   118,     0,     0,
     103,     0,     0,   128,   125,   126,     0,   102,   101,     0,
       0,     0,   137,   147,     0,     0,     0,     0,     0,     0,
       0,   261,   260,   277,   256,   271,   244,   255,   270,   248,
     228,   162,   269,   257,     0,     0,     0,     0,   254,     0,
     289,   251,   253,   177,   280,   259,     0,   234,   288,   250,
       0,   235,     0,   287,   279,     0,     0,     0,   249,   278,
     268,   286,   262,   272,   160,     0,     0,   267,     0,   298,
       0,     0,   266,     0,     0,     0,   285,   247,   276,   236,
       0,     0,   245,   275,   274,   318,     0,     0,     0,     0,
     164,   169,     0,     0,   196,     0,     0,     0,     0,   143,
     170,    68,   114,     0,     0,   107,   110,    97,     0,    90,
      96,     0,   129,     0,    93,     0,   158,     0,    33,    37,
       0,    44,     0,    57,     0,   295,   218,     0,   295,   227,
     225,     0,     0,   223,   230,     0,   232,     0,     0,     0,
     217,   226,     0,   222,   224,     0,   231,   233,    67,    60,
       0,   187,     0,   195,   197,     0,     0,   188,   127,   127,
     104,     0,   109,   108,    98,    99,     0,   100,     0,   150,
     159,     0,    43,     0,     0,    58,     0,   296,     0,     0,
       0,   175,   178,   263,   282,   264,   283,   265,   284,   246,
     163,   185,   186,     0,     0,     0,   130,   156,     0,     0,
       0,     0,   176,   297,     0,   294,   189,   112,   111,    34,
     310,   311,   309,   304,   312,   313,   304,     0,   300,   301,
     304,   302,    45,    54,   281,   305,     0,     0,   299,     0,
     306,   307,   303,     0,   314,     0,   308,     0,   315,     0,
     316
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLalgebraParser::yypgoto_[] =
  {
      -639,  -639,  -639,  -639,   457,   462,  -639,   465,   207,    91,
     176,    96,   419,   469,   475,  -639,  -639,  -639,  -639,  -639,
    -639,   -69,  -639,  -639,  -639,  -639,   321,   -51,  -639,   -62,
     -42,  -639,  -639,  -639,   -61,   -57,  -639,   255,  -639,  -639,
     -56,  -151,  -639,  -639,   487,   488,  -639,   485,  -639,  -639,
    -639,    -3,  -639,  -639,  -639,  -639,  -639,  -639,  -639,  -639,
    -639,  -639,  -639,  -639,  -639,   -17,   -29,  -313,  -205,   222,
    -471,   375,     9,  -639,  -639,  -639,  -639,   -73,  -639,   275,
     361,  -639,  -333,  -639,  -131,  -211,   421,   -53,   278,   -39,
    -639,   -38,   -37,   -34,   -31,  -639,   -35,  -639,    16,  -639,
    -639,  -639,  -639,  -639,  -639,  -639,  -639,  -639,  -271,  -152,
     100,  -639,   -41,  -639,  -639,  -639,  -639,  -639,  -639,  -639,
    -639,  -639,  -639,  -639,  -639,  -639,   -33,  -639,  -639,  -639,
    -639,  -639,  -638,  -639,  -639,  -639,  -639,  -639,  -639,   -48,
    -639,  -639,  -639,   -43,  -639,  -639,  -639,   -24,  -150,   -46,
    -639,  -639
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLalgebraParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,     5,     6,    57,     7,     8,     9,
      10,    11,    12,    13,    14,    58,    59,   347,   484,   641,
     208,    15,   209,    60,   210,   352,   214,   593,   195,    16,
      17,    18,   215,   594,    19,    20,   289,   290,   430,   291,
      21,   162,    22,    23,    24,    25,    61,    62,    63,   462,
      64,   159,    65,    66,    67,    68,    69,    70,    71,    72,
      73,   319,   632,   574,   575,   576,    74,   460,   467,   468,
     326,   330,   327,   473,   328,   474,   636,    26,   138,    27,
      75,   344,   201,   587,   107,   367,   139,    28,   301,    29,
     303,    30,    31,    32,    33,   383,   647,   601,   306,   307,
     308,   309,   310,   446,   311,   312,   565,   163,   149,   143,
     108,   151,   368,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   379,   121,   648,   122,   123,   670,
     687,   688,   696,   702,   689,   690,   691,   705,   124,   125,
     285,   286,   287,   126,   127,   128,   129,   130,   131,   132,
     133,   156
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char SPARQLalgebraParser::yytable_ninf_ = -1;
  const unsigned short int
  SPARQLalgebraParser::yytable_[] =
  {
       109,   136,   200,   152,   145,   155,   194,   315,   153,   481,
     300,   316,   469,   196,   197,   283,   476,   370,   198,   199,
      44,   464,   202,     1,   433,   465,   304,   154,   181,   304,
     459,   438,   628,   160,    76,   447,   203,   204,   205,   279,
     348,   206,   166,   284,   207,   466,   161,   403,   697,   439,
     381,   629,   699,   167,   651,   471,   101,   102,   103,   158,
     382,   440,   190,    77,   472,    78,   441,   646,   424,   191,
     480,   169,   442,   296,   170,   105,   106,   623,   345,    37,
     137,   164,    40,   293,   305,   346,    44,   305,    45,    46,
      47,    48,    49,   292,    55,   295,   171,    50,   350,   354,
     482,   105,   106,   313,    51,   351,   213,   135,    79,   639,
     644,   172,   173,   145,    52,   456,   193,   592,   463,   318,
      80,   174,   321,    81,   323,   443,   175,    84,   444,    82,
      83,   134,   101,   102,   103,   101,   102,   103,   135,   445,
     137,   176,   177,   101,   102,   103,    53,   578,   586,   178,
     144,   150,   101,   102,   103,   182,   581,   664,   665,   185,
      55,   188,   559,   583,   320,   193,   322,   300,   324,   325,
     211,   329,   212,   213,   333,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   331,   331,   369,   281,   371,   372,
     373,   374,   375,   376,   377,   378,   380,   294,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   299,   399,   400,   401,   402,   317,   404,   405,
     406,   407,   334,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   427,   101,   102,
     103,   335,   279,   336,   105,   106,   337,   152,   292,   155,
     338,   339,   153,   340,   640,   475,   353,   398,   152,   144,
     155,   423,   425,   153,    97,    98,    99,   100,   426,   200,
     258,   154,   452,   194,   457,   435,   461,   457,   457,   461,
     196,   197,   154,   461,   436,   198,   199,   457,   620,   202,
     454,   448,   450,   152,   567,   155,   453,   458,   153,   470,
     477,   478,   485,   203,   204,   205,   490,   491,   206,   349,
     279,   207,   488,   489,   638,   492,   493,   154,   494,   495,
     582,   496,   140,   141,   142,   366,   501,   157,   497,   501,
     504,   680,   498,   507,   499,   509,   502,   681,   682,   683,
     505,   513,   684,   506,   508,   510,   511,   512,   520,   522,
     685,   514,   515,   526,   516,   517,   686,   518,   519,   523,
     524,   525,   501,   527,   528,   529,   538,   530,   540,   531,
     532,   543,   544,   557,   533,   535,   536,   550,   551,   537,
     539,   541,   280,   501,   542,   152,   546,   155,   545,   556,
     153,   547,   313,   313,   548,   150,   552,   313,   313,   553,
     313,   554,   560,   561,   569,   570,   150,   571,   200,   154,
     572,   577,   194,   573,   461,   298,   626,   302,   579,   196,
     197,   580,   584,   461,   198,   199,   145,   588,   202,   589,
     461,   591,   314,   592,   313,   596,   599,   600,   603,   604,
     606,   150,   203,   204,   205,   610,   590,   206,   611,   595,
     207,   487,   613,   614,   562,   563,   616,   617,   618,   564,
     566,   619,   568,   621,   597,   598,   627,   630,   634,   631,
     635,   637,   642,   643,   653,   602,   343,   646,   649,   654,
     655,   656,   657,   658,   605,   659,   607,   660,   661,   662,
     628,   471,   667,   669,   608,   609,   585,   668,   673,   675,
     612,   676,   677,   678,   615,   679,   692,   693,   694,   695,
     698,   152,   710,   155,   200,   183,   153,   313,   194,   313,
     313,   186,   179,   451,   486,   196,   197,   558,   282,   189,
     198,   199,   180,   150,   202,   154,   355,   152,   408,   155,
     165,   166,   153,   645,   432,   184,   192,   187,   203,   204,
     205,   332,   167,   206,   342,   479,   207,   709,   633,   297,
       0,   154,     0,   666,   168,   650,   652,     0,     0,     0,
     169,     0,   144,   170,     0,     0,   434,     0,   437,   622,
     313,   624,   625,     0,     0,     0,     0,     0,     0,     0,
     449,     0,     0,     0,   455,   171,     0,     0,     0,     0,
       0,     0,   671,     0,     0,   672,     0,     0,   674,     0,
     172,   173,     0,     0,     0,     0,     0,     0,     0,   483,
     174,     0,    40,   293,     0,   175,    44,     0,    45,    46,
      47,    48,    49,     0,     0,     0,     0,    50,     0,     0,
     176,   177,   663,     0,    51,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,   701,   704,   279,   706,   150,
       0,     0,     0,   216,   708,   217,   218,   219,   220,     0,
     221,   222,     0,   428,   429,   223,   224,     0,   225,     0,
     226,   227,   228,   229,     0,   150,    53,   230,   231,     0,
       0,   232,   233,     0,     0,     0,   234,     0,   235,   236,
      55,   237,   238,     0,     0,   239,   240,   241,   242,   243,
     244,     0,   245,     0,   246,     0,     0,     0,   247,     0,
       0,     0,   248,   249,     0,     0,   250,   251,   252,   253,
       0,     0,     0,     0,   254,   255,     0,   256,     0,   257,
       0,     0,   259,     0,   260,     0,   261,   262,   263,     0,
     264,   265,     0,     0,   266,   267,     0,   268,     0,   269,
       0,     0,     0,   270,     0,     0,   271,     0,   272,   273,
     274,     0,   275,   276,   277,   278,     0,     0,     0,     0,
       0,     0,   216,     0,   217,   218,   219,   220,     0,   221,
     222,   101,   102,   103,   223,   224,     0,   225,     0,   226,
     227,   228,   229,     0,     0,     0,   230,   231,     0,     0,
     232,   233,     0,     0,     0,   234,     0,   235,   236,     0,
     237,   238,     0,     0,   239,   240,   241,   242,   243,   244,
       0,   245,     0,   246,     0,     0,     0,   247,     0,     0,
       0,   248,   249,     0,     0,   250,   251,   252,   253,     0,
       0,     0,     0,   254,   255,     0,   256,     0,   257,     0,
     258,   259,     0,   260,     0,   261,   262,   263,     0,   264,
     265,     0,     0,   266,   267,     0,   268,     0,   269,     0,
       0,     0,   270,     0,     0,   271,     0,   272,   273,   274,
       0,   275,   276,   277,   278,     0,     0,     0,     0,     0,
       0,   216,     0,   217,   218,   219,   220,     0,   221,   222,
     101,   102,   103,   223,   224,     0,   225,     0,   226,   227,
     228,   229,     0,     0,     0,   230,   231,     0,     0,   232,
     233,     0,     0,   707,   234,     0,   235,   236,     0,   237,
     238,     0,     0,   239,   240,   241,   242,   243,   244,     0,
     245,     0,   246,     0,     0,     0,   247,     0,     0,     0,
     248,   249,     0,     0,   250,   251,   252,   253,     0,     0,
       0,     0,   254,   255,     0,   256,     0,   257,     0,     0,
     259,     0,   260,     0,   261,   262,   263,     0,   264,   265,
       0,     0,   266,   267,     0,   268,     0,   269,     0,     0,
       0,   270,     0,     0,   271,     0,   272,   273,   274,     0,
     275,   276,   277,   278,     0,     0,     0,     0,     0,     0,
     216,     0,   217,   218,   219,   220,     0,   221,   222,   101,
     102,   103,   223,   224,     0,   225,     0,   226,   227,   228,
     229,     0,     0,     0,   230,   231,     0,     0,   232,   233,
       0,     0,     0,   234,     0,   235,   236,     0,   237,   238,
       0,     0,   239,   240,   241,   242,   243,   244,     0,   245,
       0,   246,     0,     0,     0,   247,     0,     0,     0,   248,
     249,     0,     0,   250,   251,   252,   253,     0,     0,     0,
       0,   254,   255,     0,   256,     0,   257,     0,     0,   259,
       0,   260,     0,   261,   262,   263,     0,   264,   265,     0,
       0,   266,   267,     0,   268,     0,   269,     0,     0,     0,
     270,     0,     0,   271,     0,   272,   273,   274,     0,   275,
     276,   277,   278,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   101,   102,
     103,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,     0,     0,
       0,     0,    50,     0,     0,     0,     0,     0,     0,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,    48,    49,     0,     0,     0,
       0,    50,     0,     0,     0,     0,     0,     0,    51,     0,
       0,    53,     0,     0,     0,     0,     0,    54,    52,     0,
       0,     0,     0,     0,     0,    55,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,    48,
      49,     0,     0,    56,     0,    50,     0,     0,     0,     0,
      53,     0,    51,     0,     0,     0,    54,     0,     0,     0,
       0,     0,    52,     0,    55,     0,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,    48,
      49,     0,    56,   165,     0,    50,     0,     0,     0,     0,
       0,     0,    51,     0,    53,     0,     0,     0,     0,     0,
      54,     0,    52,     0,     0,     0,     0,   168,    55,    36,
      37,    38,    39,    40,    41,    42,     0,    44,     0,    45,
      46,    47,    48,    49,     0,     0,    56,     0,    50,     0,
       0,     0,     0,     0,    53,    51,     0,     0,     0,     0,
      54,     0,     0,     0,    36,    52,    38,    39,    55,    41,
      42,     0,    44,     0,    45,    46,    47,    48,    49,     0,
       0,     0,     0,    50,     0,     0,     0,     0,     0,     0,
     341,     0,     0,     0,     0,     0,     0,    53,     0,     0,
      52,     0,     0,     0,    36,    37,     0,     0,    40,    41,
      42,    55,    44,     0,    45,    46,    47,    48,    49,     0,
       0,     0,     0,    50,    37,     0,     0,    40,    41,    42,
      51,    44,    53,    45,    46,    47,    48,    49,    54,     0,
      52,     0,    50,     0,    37,     0,    55,    40,    41,    51,
       0,    44,     0,    45,    46,    47,    48,    49,     0,    52,
       0,     0,    50,     0,     0,     0,     0,     0,   293,    51,
       0,    44,    53,    45,    46,    47,    48,    49,     0,    52,
     165,     0,    50,     0,     0,     0,    55,   293,     0,    51,
      44,    53,    45,    46,    47,    48,    49,     0,     0,    52,
       0,    50,     0,     0,   168,    55,     0,     0,    51,     0,
       0,    53,   700,     0,     0,     0,     0,     0,    52,     0,
       0,     0,     0,     0,     0,    55,     0,     0,     0,     0,
       0,    53,   356,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,   146,     0,     0,     0,
      53,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,     0,     0,   104,   105,   106,     0,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   147,   148,   431,
     105,   106,     0,     0,     0,     0,   288,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   500,     0,     0,     0,     0,     0,     0,   356,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,     0,     0,   104,
     105,   106,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     503,     0,   104,   105,   106,     0,     0,   356,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   521,     0,     0,     0,     0,     0,     0,
     356,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,     0,
     104,   105,   106,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   534,     0,   104,   105,   106,     0,     0,   356,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   549,     0,     0,     0,     0,     0,
       0,   356,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    85,
       0,   104,   105,   106,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   555,     0,   104,   105,   106,     0,     0,   356,
       0,     0,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
       0,     0,   104,   105,   106,   288,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     356,     0,   104,   105,   106,     0,     0,     0,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   703,     0,   104,   105,
     106,     0,     0,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,     0,     0,   104,   105,   106,     0,     0,     0,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,     0,     0,   104,
     105,   106
  };

  /* YYCHECK.  */
  const short int
  SPARQLalgebraParser::yycheck_[] =
  {
        41,    43,    75,    51,    50,    51,    75,   159,    51,   342,
     141,   162,   325,    75,    75,   133,   329,   228,    75,    75,
      13,    22,    75,   105,   295,    26,    47,    51,    57,    47,
     127,    21,    59,   127,     0,   306,    75,    75,    75,    85,
      98,    75,    23,   161,    75,    46,   140,   258,   686,    39,
      95,    78,   690,    34,    98,   105,   153,   154,   155,   126,
     105,    51,    98,   153,   114,   105,    56,   111,   279,   105,
     341,    52,    62,    98,    55,   159,   160,    98,    98,     6,
     105,    20,     9,    10,   105,   105,    13,   105,    15,    16,
      17,    18,    19,   134,    87,    14,    77,    24,    98,    98,
      98,   159,   160,   149,    31,   105,   105,   105,   105,    98,
      98,    92,    93,   159,    41,   320,   105,   105,   323,   165,
     105,   102,   168,   105,   170,   115,   107,   105,   118,    38,
      39,   105,   153,   154,   155,   153,   154,   155,   105,   129,
     105,   122,   123,   153,   154,   155,    73,   460,   481,   105,
      50,    51,   153,   154,   155,   105,   469,   628,   629,   105,
      87,   105,   433,   476,   167,   105,   169,   298,   171,   172,
      98,   174,    98,   105,   177,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   175,   176,   227,   105,   229,   230,
     231,   232,   233,   234,   235,   236,   237,    98,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   105,   254,   255,   256,   257,    98,   259,   260,
     261,   262,    98,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   283,   153,   154,
     155,    98,   288,    98,   159,   160,    98,   295,   289,   295,
      98,    98,   295,    98,   587,   328,   158,    98,   306,   159,
     306,    98,    98,   306,   149,   150,   151,   152,    98,   342,
     103,   295,   318,   342,   320,    98,   322,   323,   324,   325,
     342,   342,   306,   329,    98,   342,   342,   333,   559,   342,
     319,    98,   105,   341,   445,   341,   105,    98,   341,    98,
      98,    98,   105,   342,   342,   342,   111,    98,   342,   209,
     356,   342,   353,   105,   585,    98,    98,   341,    98,    98,
     472,    98,    47,    48,    49,   225,   367,    52,    98,   370,
     371,    75,    98,   374,    98,   376,    98,    81,    82,    83,
     111,   382,    86,   111,    98,    98,    98,    98,   389,   390,
      94,    98,    98,   394,   111,    98,   100,    98,    98,    98,
      98,   111,   403,   111,    98,    98,   407,    98,   409,    98,
      98,   412,   413,   105,    98,   111,   111,   418,   419,    98,
      98,   111,   107,   424,    98,   433,    98,   433,   111,   430,
     433,    98,   438,   439,    98,   295,    98,   443,   444,    98,
     446,    98,    98,    98,    98,    98,   306,    98,   481,   433,
      98,    98,   481,   105,   460,   140,   567,   142,    98,   481,
     481,    98,    98,   469,   481,   481,   472,   154,   481,    98,
     476,    98,   157,   105,   480,    98,    98,    98,    98,    98,
      98,   341,   481,   481,   481,    98,   487,   481,    98,   490,
     481,   351,    98,    98,   438,   439,    98,    98,    98,   443,
     444,    98,   446,    98,   505,   506,    98,    98,    98,   105,
      98,    98,    98,   158,    98,   516,   201,   111,   111,    98,
      98,    98,    98,    98,   525,    98,   527,    98,    98,    98,
      59,   105,    98,   105,   535,   536,   480,   153,    98,    98,
     541,    98,    98,    98,   545,    98,    98,    98,    98,    66,
      98,   559,    98,   559,   587,    58,   559,   563,   587,   565,
     566,    59,    57,   316,   348,   587,   587,   431,   109,    60,
     587,   587,    57,   433,   587,   559,   215,   585,   263,   585,
      22,    23,   585,   594,   289,    58,    61,    59,   587,   587,
     587,   176,    34,   587,   193,   333,   587,   707,   575,   138,
      -1,   585,    -1,   636,    46,   598,   601,    -1,    -1,    -1,
      52,    -1,   472,    55,    -1,    -1,   298,    -1,   303,   563,
     626,   565,   566,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     315,    -1,    -1,    -1,   319,    77,    -1,    -1,    -1,    -1,
      -1,    -1,   644,    -1,    -1,   646,    -1,    -1,   649,    -1,
      92,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   344,
     102,    -1,     9,    10,    -1,   107,    13,    -1,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    24,    -1,    -1,
     122,   123,   626,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,   696,   697,   703,   699,   559,
      -1,    -1,    -1,    25,   705,    27,    28,    29,    30,    -1,
      32,    33,    -1,    35,    36,    37,    38,    -1,    40,    -1,
      42,    43,    44,    45,    -1,   585,    73,    49,    50,    -1,
      -1,    53,    54,    -1,    -1,    -1,    58,    -1,    60,    61,
      87,    63,    64,    -1,    -1,    67,    68,    69,    70,    71,
      72,    -1,    74,    -1,    76,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    84,    85,    -1,    -1,    88,    89,    90,    91,
      -1,    -1,    -1,    -1,    96,    97,    -1,    99,    -1,   101,
      -1,    -1,   104,    -1,   106,    -1,   108,   109,   110,    -1,
     112,   113,    -1,    -1,   116,   117,    -1,   119,    -1,   121,
      -1,    -1,    -1,   125,    -1,    -1,   128,    -1,   130,   131,
     132,    -1,   134,   135,   136,   137,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    -1,    27,    28,    29,    30,    -1,    32,
      33,   153,   154,   155,    37,    38,    -1,    40,    -1,    42,
      43,    44,    45,    -1,    -1,    -1,    49,    50,    -1,    -1,
      53,    54,    -1,    -1,    -1,    58,    -1,    60,    61,    -1,
      63,    64,    -1,    -1,    67,    68,    69,    70,    71,    72,
      -1,    74,    -1,    76,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    85,    -1,    -1,    88,    89,    90,    91,    -1,
      -1,    -1,    -1,    96,    97,    -1,    99,    -1,   101,    -1,
     103,   104,    -1,   106,    -1,   108,   109,   110,    -1,   112,
     113,    -1,    -1,   116,   117,    -1,   119,    -1,   121,    -1,
      -1,    -1,   125,    -1,    -1,   128,    -1,   130,   131,   132,
      -1,   134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    -1,    27,    28,    29,    30,    -1,    32,    33,
     153,   154,   155,    37,    38,    -1,    40,    -1,    42,    43,
      44,    45,    -1,    -1,    -1,    49,    50,    -1,    -1,    53,
      54,    -1,    -1,    57,    58,    -1,    60,    61,    -1,    63,
      64,    -1,    -1,    67,    68,    69,    70,    71,    72,    -1,
      74,    -1,    76,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    85,    -1,    -1,    88,    89,    90,    91,    -1,    -1,
      -1,    -1,    96,    97,    -1,    99,    -1,   101,    -1,    -1,
     104,    -1,   106,    -1,   108,   109,   110,    -1,   112,   113,
      -1,    -1,   116,   117,    -1,   119,    -1,   121,    -1,    -1,
      -1,   125,    -1,    -1,   128,    -1,   130,   131,   132,    -1,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    -1,    27,    28,    29,    30,    -1,    32,    33,   153,
     154,   155,    37,    38,    -1,    40,    -1,    42,    43,    44,
      45,    -1,    -1,    -1,    49,    50,    -1,    -1,    53,    54,
      -1,    -1,    -1,    58,    -1,    60,    61,    -1,    63,    64,
      -1,    -1,    67,    68,    69,    70,    71,    72,    -1,    74,
      -1,    76,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,
      85,    -1,    -1,    88,    89,    90,    91,    -1,    -1,    -1,
      -1,    96,    97,    -1,    99,    -1,   101,    -1,    -1,   104,
      -1,   106,    -1,   108,   109,   110,    -1,   112,   113,    -1,
      -1,   116,   117,    -1,   119,    -1,   121,    -1,    -1,    -1,
     125,    -1,    -1,   128,    -1,   130,   131,   132,    -1,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,   154,
     155,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      -1,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    79,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    87,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      19,    -1,    -1,   105,    -1,    24,    -1,    -1,    -1,    -1,
      73,    -1,    31,    -1,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    41,    -1,    87,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      19,    -1,   105,    22,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    41,    -1,    -1,    -1,    -1,    46,    87,     5,
       6,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    19,    -1,    -1,   105,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    73,    31,    -1,    -1,    -1,    -1,
      79,    -1,    -1,    -1,     5,    41,     7,     8,    87,    10,
      11,    -1,    13,    -1,    15,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      41,    -1,    -1,    -1,     5,     6,    -1,    -1,     9,    10,
      11,    87,    13,    -1,    15,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    24,     6,    -1,    -1,     9,    10,    11,
      31,    13,    73,    15,    16,    17,    18,    19,    79,    -1,
      41,    -1,    24,    -1,     6,    -1,    87,     9,    10,    31,
      -1,    13,    -1,    15,    16,    17,    18,    19,    -1,    41,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    10,    31,
      -1,    13,    73,    15,    16,    17,    18,    19,    -1,    41,
      22,    -1,    24,    -1,    -1,    -1,    87,    10,    -1,    31,
      13,    73,    15,    16,    17,    18,    19,    -1,    -1,    41,
      -1,    24,    -1,    -1,    46,    87,    -1,    -1,    31,    -1,
      -1,    73,    85,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    73,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    95,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,   158,   159,   160,    -1,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,    98,
     159,   160,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,    -1,   158,
     159,   160,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      98,    -1,   158,   159,   160,    -1,    -1,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,    -1,    -1,
     158,   159,   160,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    98,    -1,   158,   159,   160,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   105,
      -1,   158,   159,   160,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    98,    -1,   158,   159,   160,    -1,    -1,   105,
      -1,    -1,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      -1,    -1,   158,   159,   160,   105,    -1,    -1,    -1,    -1,
      -1,    -1,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     105,    -1,   158,   159,   160,    -1,    -1,    -1,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   105,    -1,   158,   159,
     160,    -1,    -1,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,    -1,   158,   159,   160,    -1,    -1,    -1,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,    -1,   158,
     159,   160
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLalgebraParser::yystos_[] =
  {
         0,   105,   163,   164,   165,   166,   167,   169,   170,   171,
     172,   173,   174,   175,   176,   183,   191,   192,   193,   196,
     197,   202,   204,   205,   206,   207,   239,   241,   249,   251,
     253,   254,   255,   256,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    15,    16,    17,    18,    19,
      24,    31,    41,    73,    79,    87,   105,   168,   177,   178,
     185,   208,   209,   210,   212,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   228,   242,     0,   153,   105,   105,
     105,   105,   171,   171,   105,   105,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   158,   159,   160,   246,   272,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   287,   289,   290,   300,   301,   305,   306,   307,   308,
     309,   310,   311,   312,   105,   105,   192,   105,   240,   248,
     241,   241,   241,   271,   272,   311,    95,   156,   157,   270,
     272,   273,   301,   305,   309,   311,   313,   241,   126,   213,
     127,   140,   203,   269,    20,    22,    23,    34,    46,    52,
      55,    77,    92,    93,   102,   107,   122,   123,   105,   169,
     176,   228,   105,   166,   206,   105,   167,   207,   105,   175,
      98,   105,   209,   105,   183,   190,   191,   196,   197,   202,
     239,   244,   249,   251,   253,   254,   255,   256,   182,   184,
     186,    98,    98,   105,   188,   194,    25,    27,    28,    29,
      30,    32,    33,    37,    38,    40,    42,    43,    44,    45,
      49,    50,    53,    54,    58,    60,    61,    63,    64,    67,
      68,    69,    70,    71,    72,    74,    76,    80,    84,    85,
      88,    89,    90,    91,    96,    97,    99,   101,   103,   104,
     106,   108,   109,   110,   112,   113,   116,   117,   119,   121,
     125,   128,   130,   131,   132,   134,   135,   136,   137,   311,
     241,   105,   174,   133,   161,   302,   303,   304,   105,   198,
     199,   201,   274,    10,    98,    14,    98,   248,   241,   105,
     246,   250,   241,   252,    47,   105,   260,   261,   262,   263,
     264,   266,   267,   311,   241,   271,   203,    98,   311,   223,
     213,   311,   213,   311,   213,   213,   232,   234,   236,   213,
     233,   234,   233,   213,    98,    98,    98,    98,    98,    98,
      98,    31,   242,   241,   243,    98,   105,   179,    98,   272,
      98,   105,   187,   158,    98,   188,   105,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   272,   247,   274,   274,
     247,   274,   274,   274,   274,   274,   274,   274,   274,   286,
     274,    95,   105,   257,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,    98,   274,
     274,   274,   274,   247,   274,   274,   274,   274,   241,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,    98,   247,    98,    98,   311,    35,    36,
     200,    98,   199,   270,   250,    98,    98,   241,    21,    39,
      51,    56,    62,   115,   118,   129,   265,   270,    98,   241,
     105,   170,   311,   105,   228,   241,   230,   311,    98,   127,
     229,   311,   211,   230,    22,    26,    46,   230,   231,   229,
      98,   105,   114,   235,   237,   239,   229,    98,    98,   231,
     270,   244,    98,   241,   180,   105,   172,   272,   274,   105,
     111,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,   274,    98,    98,   274,   111,   111,   274,    98,   274,
      98,    98,    98,   274,    98,    98,   111,    98,    98,    98,
     274,    98,   274,    98,    98,   111,   274,   111,    98,    98,
      98,    98,    98,    98,    98,   111,   111,    98,   274,    98,
     274,   111,    98,   274,   274,   111,    98,    98,    98,    98,
     274,   274,    98,    98,    98,    98,   274,   105,   173,   270,
      98,    98,   260,   260,   260,   268,   260,   203,   260,    98,
      98,    98,    98,   105,   225,   226,   227,    98,   229,    98,
      98,   229,   271,   229,    98,   260,   244,   245,   154,    98,
     274,    98,   105,   189,   195,   274,    98,   274,   274,    98,
      98,   259,   274,    98,    98,   274,    98,   274,   274,   274,
      98,    98,   274,    98,    98,   274,    98,    98,    98,    98,
     270,    98,   260,    98,   260,   260,   203,    98,    59,    78,
      98,   105,   224,   227,    98,    98,   238,    98,   270,    98,
     244,   181,    98,   158,    98,   189,   111,   258,   288,   111,
     288,    98,   258,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,   260,   232,   232,   239,    98,   153,   105,
     291,   192,   274,    98,   274,    98,    98,    98,    98,    98,
      75,    81,    82,    83,    86,    94,   100,   292,   293,   296,
     297,   298,    98,    98,    98,    66,   294,   294,    98,   294,
      85,   274,   295,   105,   274,   299,   274,    57,   274,   310,
      98
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  SPARQLalgebraParser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  SPARQLalgebraParser::yyr1_[] =
  {
         0,   162,   163,   163,   164,   165,   165,   166,   166,   167,
     167,   167,   167,   168,   168,   169,   169,   170,   170,   171,
     171,   172,   172,   173,   173,   174,   174,   175,   175,   176,
     177,   178,   180,   181,   179,   182,   182,   183,   184,   184,
     185,   186,   186,   187,   188,   189,   190,   190,   190,   190,
     190,   191,   191,   192,   193,   194,   194,   195,   195,   196,
     197,   198,   198,   199,   199,   200,   200,   201,   202,   203,
     203,   204,   205,   205,   206,   206,   207,   208,   208,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     210,   211,   211,   212,   213,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   223,   224,   224,   225,
     225,   226,   227,   228,   228,   229,   229,   230,   231,   231,
     231,   231,   232,   233,   234,   235,   235,   236,   236,   238,
     237,   239,   239,   240,   240,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   242,   242,   243,   243,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   245,   245,
     246,   247,   247,   248,   249,   249,   250,   250,   252,   251,
     253,   254,   255,   256,   257,   257,   258,   259,   259,   260,
     260,   260,   260,   260,   260,   261,   262,   263,   264,   264,
     265,   265,   265,   266,   266,   267,   268,   268,   269,   270,
     270,   271,   271,   272,   272,   273,   273,   273,   273,   273,
     273,   274,   274,   274,   274,   274,   274,   275,   276,   277,
     278,   278,   279,   279,   279,   279,   279,   279,   279,   280,
     281,   281,   282,   282,   283,   283,   283,   284,   284,   284,
     284,   284,   284,   284,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   286,   286,   287,   288,   288,   289,   290,   291,
     292,   292,   292,   293,   294,   294,   295,   295,   296,   297,
     297,   297,   297,   297,   298,   298,   299,   300,   300,   301,
     302,   303,   303,   304,   304,   305,   305,   305,   306,   306,
     306,   307,   307,   307,   308,   308,   308,   309,   309,   310,
     310,   310,   310,   311,   311,   312,   312,   313,   313
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SPARQLalgebraParser::yyr2_[] =
  {
         0,     2,     1,     1,     1,     4,     1,     4,     1,     4,
       4,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     1,     1,     4,
       2,     4,     0,     0,     6,     0,     2,     7,     0,     2,
       4,     0,     2,     4,     4,     4,     1,     1,     1,     1,
       1,     4,     4,     1,    10,     1,     2,     1,     2,     5,
       7,     1,     2,     1,     1,     1,     1,     4,     6,     1,
       1,     1,     4,     1,     4,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     0,     1,     5,     0,     1,     5,     5,     6,     6,
       6,     4,     4,     4,     6,     0,     2,     0,     1,     2,
       1,     4,     4,     4,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     2,     0,
       4,     4,     4,     1,     2,     1,     1,     5,     1,     1,
       1,     1,     1,     6,     1,     1,     1,     2,     1,     1,
       5,     1,     1,     1,     1,     1,     6,     1,     1,     2,
       4,     1,     2,     6,     6,     5,     0,     1,     0,     6,
       6,     5,     5,     5,     1,     4,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     5,     5,     4,     4,     6,
       1,     1,     1,     1,     1,     4,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     5,     1,
       1,     1,     5,     5,     5,     5,     5,     5,     4,     1,
       5,     5,     5,     5,     4,     4,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     6,     4,     4,     4,
       4,     4,     3,     4,     4,     4,     4,     4,     1,     4,
       4,     4,     4,     6,     6,     6,     4,     4,     4,     4,
       4,     4,     4,     3,     4,     4,     4,     4,     4,     4,
       4,     8,     6,     6,     6,     4,     4,     4,     4,     4,
       1,     1,     0,     1,     7,     0,     1,     7,     4,     3,
       1,     1,     1,     3,     0,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     3,     4,     4,     1,     4,     2,
       2,     1,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const SPARQLalgebraParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "IT_base", "IT_prefix",
  "IT_project", "IT_extend", "IT_distinct", "IT_reduced", "IT_group",
  "IT_filter", "IT_order", "IT_ask", "IT_bgp", "IT_triple", "IT_join",
  "IT_sequence", "IT_leftjoin", "IT_optional", "IT_union", "IT_unit",
  "IT_reverse", "IT_named", "IT_modify", "IT_graph", "IT_substr", "IT_all",
  "IT_lcase", "IT_ucase", "IT_sha256", "IT_round", "IT_path", "IT_seconds",
  "IT_str", "IT_create", "IT_asc", "IT_desc", "IT_floor", "IT_minutes",
  "IT_alt", "IT_bound", "IT_minus", "IT_in", "IT_hours", "IT_concat",
  "GT_AND", "IT_default", "IT_a", "TriplesSameSubject", "IT_if",
  "IT_regex", "GT_path_PLUS", "IT_add", "GT_GE", "IT_ceil", "IT_load",
  "GT_path_TIMES", "IT_separator", "GT_GT", "IT_insert", "IT_isnumeric",
  "IT_bnode", "GT_path_OPT", "IT_abs", "IT_coalesce", "GT_RCURLEY",
  "IT_DISTINCT", "IT_strlen", "IT_contains", "GT_NOT", "IT_isliteral",
  "IT_uri", "GT_NEQUAL", "IT_service", "GT_PLUS", "IT_MIN", "IT_isblank",
  "IT_drop", "IT_delete", "IT_slice", "IT_sha512", "IT_MAX", "IT_SUM",
  "IT_COUNT", "IT_strlang", "GT_TIMES", "IT_AVG", "IT_table",
  "IT_strstarts", "IT_iri", "IT_sha384", "IT_now", "IT_move",
  "IT_deletewhere", "IT_SAMPLE", "NIL", "IT_day", "IT_isuri", "GT_RPAREN",
  "IT_encode_for_uri", "IT_GROUP_CONCAT", "IT_timezone", "IT_copy",
  "IT_exprlist", "IT_strdt", "GT_LPAREN", "IT_strends", "IT_deletedata",
  "IT_month", "GT_OR", "IT_exists", "GT_COMMA", "GT_LE", "IT_sameterm",
  "IT_quads", "IT_notoneof", "IT_year", "GT_EQUAL", "IT_seq", "GT_LT",
  "GT_LCURLEY", "IT_langmatches", "IT_insertdata", "IT_clear", "GT_DOT",
  "IT_isiri", "IT_silent", "IT__", "IT_datatype", "IT_mod", "IT_sha224",
  "GT_MINUS", "GT_DIVIDE", "GT_DTYPE", "IT_lang", "IT_sha1", "IT_md5",
  "IT_RAND", "IT_true", "IT_false", "INTEGER", "DECIMAL", "DOUBLE",
  "INTEGER_POSITIVE", "DECIMAL_POSITIVE", "DOUBLE_POSITIVE",
  "INTEGER_NEGATIVE", "DECIMAL_NEGATIVE", "DOUBLE_NEGATIVE",
  "STRING_LITERAL1", "STRING_LITERAL_LONG1", "STRING_LITERAL2",
  "STRING_LITERAL_LONG2", "IRI_REF", "PNAME_NS", "PNAME_LN",
  "BLANK_NODE_LABEL", "ANON", "POSITION", "VAR1", "VAR2", "LANGTAG",
  "$accept", "Top", "QueryUnit", "Query", "PrefixOpt", "UsingOpt",
  "_QUsingClause_E_Plus", "SliceOpt", "DistinctOpt", "ProjectOpt",
  "OrderOpt", "HavingOpt", "ExtendOpt", "GroupOpt", "AskQuery", "BaseDecl",
  "PrefixDecl",
  "_O_QGT_LPAREN_E_S_QPNAME_NS_E_S_QIRI_REF_E_S_QGT_RPAREN_E_C", "$@1",
  "$@2",
  "_Q_O_QGT_LPAREN_E_S_QPNAME_NS_E_S_QIRI_REF_E_S_QGT_RPAREN_E_C_E_Star",
  "Project", "_QVar_E_Star", "Extend", "_QBinding_E_Star", "Binding",
  "GroupExpression", "ProjectExpression", "SubSelect", "DistinctReduced",
  "WhereClause", "GroupClause", "_QGroupExpression_E_Plus",
  "_QProjectExpression_E_Plus", "HavingClause", "OrderClause",
  "_QOrderCondition_E_Plus", "OrderCondition",
  "_O_QIT_asc_E_Or_QIT_desc_E_C",
  "_O_QGT_LPAREN_E_S_QIT_asc_E_Or_QIT_desc_E_S_QExpression_E_S_QGT_RPAREN_E_C",
  "Slice", "_O_QInteger_E_Or_QIT___E_C", "UpdateUnit", "Update_Base",
  "Update_Prefix", "Updates", "_QUpdate1_E_Plus", "Update1", "Load",
  "_QGraphRef_E_Opt", "Clear", "_QIT_silent_E_Opt", "Drop", "Create",
  "Add", "Move", "Copy", "InsertData", "DeleteData", "DeleteWhere",
  "Modify", "_QUsingClause_E_Star", "_QInsertClause_E_Opt",
  "_O_QDeleteClause_E_S_QInsertClause_E_Opt_Or_QInsertClause_E_C",
  "DeleteClause", "InsertClause", "UsingClause", "GraphOrDefault",
  "GraphRef", "GraphRefAll", "QuadPattern", "QuadData", "Quads",
  "_O_QQuadsNotTriples_E_Or_QTriplesTemplate_E_C",
  "_Q_O_QQuadsNotTriples_E_Or_QTriplesTemplate_E_C_E_Star",
  "QuadsNotTriples", "@3", "TriplesTemplate", "_QMyTriple_E_Plus",
  "GroupGraphPatternNoSub", "_O_QIT_join_E_Or_QIT_sequence_E_C",
  "_QGroupGraphPatternNoSub_E_Plus", "GroupGraphPatternSub",
  "_QGroupGraphPatternSub_E_Plus", "ExprList", "_QExpression_E_Plus",
  "MyTriple", "OptionalGraphPattern", "_QExprList_E_Opt",
  "GraphGraphPattern", "@4", "ServiceGraphPattern", "MinusGraphPattern",
  "GroupOrUnionGraphPattern", "Filter", "ExpressionList",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "Path", "PathAlternative",
  "PathSequence", "PathEltOrInverse", "PathMod",
  "_O_QGT_path_OPT_E_Or_QGT_path_TIMES_E_Or_QGT_path_PLUS_E_C",
  "PathPrimary", "PathOneInPropertySet", "_QPath_E_Plus", "Integer",
  "VarOrTerm", "VarOrIRIref", "Var", "GraphTerm", "Expression",
  "ConditionalOrExpression", "ConditionalAndExpression", "ValueLogical",
  "RelationalExpression", "RelativeExpression", "NumericExpression",
  "AdditiveExpression", "MultiplicativeExpression", "UnaryExpression",
  "PrimaryExpression", "BuiltInCall", "_QExpression_E_Opt",
  "RegexExpression", "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Opt",
  "SubstringExpression", "ExistsFunc", "Aggregate",
  "_O_QCount_E_Or_QMiscAgg_E_Or_QGroupConcat_E_C", "Count",
  "_QIT_DISTINCT_E_Opt", "_O_QGT_TIMES_E_Or_QExpression_E_C", "MiscAgg",
  "_O_QIT_SUM_E_Or_QIT_MIN_E_Or_QIT_MAX_E_Or_QIT_AVG_E_Or_QIT_SAMPLE_E_C",
  "GroupConcat", "Separator", "IRIrefOrFunction", "RDFLiteral",
  "_O_QGT_DTYPE_E_S_QIRIref_E_C",
  "_O_QLANGTAG_E_Or_QGT_DTYPE_E_S_QIRIref_E_C",
  "_Q_O_QLANGTAG_E_Or_QGT_DTYPE_E_S_QIRIref_E_C_E_Opt", "NumericLiteral",
  "NumericLiteralUnsigned", "NumericLiteralPositive",
  "NumericLiteralNegative", "BooleanLiteral", "String", "IRIref",
  "PrefixedName", "BlankNode", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const SPARQLalgebraParser::rhs_number_type
  SPARQLalgebraParser::yyrhs_[] =
  {
       163,     0,    -1,   164,    -1,   204,    -1,   165,    -1,   105,
     177,   166,    98,    -1,   166,    -1,   105,   178,   167,    98,
      -1,   167,    -1,   105,   168,   169,    98,    -1,   105,   168,
     176,    98,    -1,   176,    -1,   169,    -1,   228,    -1,   168,
     228,    -1,   202,    -1,   170,    -1,   191,    -1,   171,    -1,
     183,    -1,   172,    -1,   197,    -1,   173,    -1,   196,    -1,
     174,    -1,   105,   185,   175,    98,    -1,   175,    -1,   193,
      -1,   192,    -1,   105,    12,   192,    98,    -1,     3,   153,
      -1,     4,   105,   182,    98,    -1,    -1,    -1,   105,   180,
     154,   181,   153,    98,    -1,    -1,   182,   179,    -1,   105,
       5,   105,   184,    98,   172,    98,    -1,    -1,   184,   272,
      -1,     6,   105,   186,    98,    -1,    -1,   186,   187,    -1,
     105,   272,   274,    98,    -1,   105,   158,   274,    98,    -1,
     105,   158,   291,    98,    -1,   202,    -1,   191,    -1,   183,
      -1,   197,    -1,   196,    -1,   105,     7,   171,    98,    -1,
     105,     8,   171,    98,    -1,   241,    -1,   105,     9,   105,
     194,    98,   105,   195,    98,   192,    98,    -1,   188,    -1,
     194,   188,    -1,   189,    -1,   195,   189,    -1,   105,    10,
     274,   174,    98,    -1,   105,    11,   105,   198,    98,   173,
      98,    -1,   199,    -1,   198,   199,    -1,   201,    -1,   274,
      -1,    35,    -1,    36,    -1,   105,   200,   274,    98,    -1,
     105,    79,   203,   203,   170,    98,    -1,   269,    -1,   127,
      -1,   205,    -1,   105,   177,   206,    98,    -1,   206,    -1,
     105,   178,   207,    98,    -1,   207,    -1,   105,   208,    98,
      -1,   209,    -1,   208,   209,    -1,   210,    -1,   212,    -1,
     214,    -1,   216,    -1,   217,    -1,   218,    -1,   215,    -1,
     219,    -1,   220,    -1,   221,    -1,   222,    -1,   105,    55,
     311,   211,    98,    -1,    -1,   230,    -1,   105,   123,   213,
     231,    98,    -1,    -1,   126,    -1,   105,    77,   213,   231,
      98,    -1,   105,    34,   213,   230,    98,    -1,   105,    52,
     213,   229,   229,    98,    -1,   105,    92,   213,   229,   229,
      98,    -1,   105,   102,   213,   229,   229,    98,    -1,   105,
     122,   233,    98,    -1,   105,   107,   233,    98,    -1,   105,
      93,   232,    98,    -1,   105,    23,   223,   241,   225,    98,
      -1,    -1,   223,   228,    -1,    -1,   227,    -1,   226,   224,
      -1,   227,    -1,   105,    78,   232,    98,    -1,   105,    59,
     232,    98,    -1,   105,    46,   311,    98,    -1,   105,    22,
     311,   311,    98,    -1,   127,    -1,   311,    -1,   311,    -1,
     230,    -1,    46,    -1,    22,    -1,    26,    -1,   234,    -1,
     234,    -1,   236,    -1,   237,    -1,   239,    -1,    -1,   236,
     235,    -1,    -1,   114,   271,   238,   239,    -1,   105,    13,
     240,    98,    -1,   105,    87,    20,    98,    -1,   248,    -1,
     240,   248,    -1,   239,    -1,   256,    -1,   105,   242,   244,
     243,    98,    -1,   249,    -1,   251,    -1,   253,    -1,   254,
      -1,   255,    -1,   105,    31,   270,   260,   270,    98,    -1,
      15,    -1,    16,    -1,   241,    -1,   243,   241,    -1,   239,
      -1,   256,    -1,   105,   242,   244,   245,    98,    -1,   249,
      -1,   251,    -1,   253,    -1,   254,    -1,   255,    -1,   105,
      31,   270,   260,   270,    98,    -1,   190,    -1,   244,    -1,
     245,   244,    -1,   105,   103,   247,    98,    -1,   274,    -1,
     247,   274,    -1,   105,    14,   270,   270,   270,    98,    -1,
     105,    17,   241,   241,   250,    98,    -1,   105,    18,   241,
     250,    98,    -1,    -1,   246,    -1,    -1,   105,    24,   271,
     252,   241,    98,    -1,   105,    73,   213,   271,   241,    98,
      -1,   105,    41,   241,   241,    98,    -1,   105,    19,   241,
     241,    98,    -1,   105,    10,   246,   241,    98,    -1,    95,
      -1,   105,   274,   259,    98,    -1,   111,   274,    -1,    -1,
     259,   258,    -1,   261,    -1,   262,    -1,   263,    -1,   264,
      -1,   267,    -1,   266,    -1,   105,    39,   260,   260,    98,
      -1,   105,   118,   260,   260,    98,    -1,   105,    21,   260,
      98,    -1,   105,   265,   260,    98,    -1,   105,   129,   203,
     203,   260,    98,    -1,    62,    -1,    56,    -1,    51,    -1,
     311,    -1,    47,    -1,   105,   115,   268,    98,    -1,   260,
      -1,   268,   260,    -1,   140,    -1,   272,    -1,   273,    -1,
     272,    -1,   311,    -1,   159,    -1,   160,    -1,   311,    -1,
     301,    -1,   305,    -1,   309,    -1,   313,    -1,    95,    -1,
     275,    -1,   276,    -1,   277,    -1,   282,    -1,   283,    -1,
     284,    -1,   105,   109,   274,   274,    98,    -1,   105,    45,
     274,   274,    98,    -1,   278,    -1,   280,    -1,   279,    -1,
     105,   117,   274,   274,    98,    -1,   105,    72,   274,   274,
      98,    -1,   105,   119,   274,   274,    98,    -1,   105,    58,
     274,   274,    98,    -1,   105,   112,   274,   274,    98,    -1,
     105,    53,   274,   274,    98,    -1,   105,    42,   247,    98,
      -1,   281,    -1,   105,    74,   274,   274,    98,    -1,   105,
     131,   274,   274,    98,    -1,   105,    85,   274,   274,    98,
      -1,   105,   132,   274,   274,    98,    -1,   105,    69,   274,
      98,    -1,   105,    74,   274,    98,    -1,   105,   131,   274,
      98,    -1,   285,    -1,   300,    -1,   301,    -1,   305,    -1,
     309,    -1,   272,    -1,   158,    -1,   105,    33,   274,    98,
      -1,   105,   134,   274,    98,    -1,   105,   121,   274,   111,
     274,    98,    -1,   105,   128,   274,    98,    -1,   105,    40,
     272,    98,    -1,   105,    89,   274,    98,    -1,   105,    71,
     274,    98,    -1,   105,    61,   286,    98,    -1,   105,   137,
      98,    -1,   105,    63,   274,    98,    -1,   105,    54,   274,
      98,    -1,   105,    37,   274,    98,    -1,   105,    30,   274,
      98,    -1,   105,    44,   247,    98,    -1,   289,    -1,   105,
      67,   274,    98,    -1,   105,    28,   274,    98,    -1,   105,
      27,   274,    98,    -1,   105,    99,   274,    98,    -1,   105,
      68,   274,   111,   274,    98,    -1,   105,    88,   274,   111,
     274,    98,    -1,   105,   106,   274,   111,   274,    98,    -1,
     105,   116,   274,    98,    -1,   105,   108,   274,    98,    -1,
     105,    96,   274,    98,    -1,   105,    43,   274,    98,    -1,
     105,    38,   274,    98,    -1,   105,    32,   274,    98,    -1,
     105,   101,   274,    98,    -1,   105,    91,    98,    -1,   105,
     136,   274,    98,    -1,   105,   135,   274,    98,    -1,   105,
     130,   274,    98,    -1,   105,    29,   274,    98,    -1,   105,
      90,   274,    98,    -1,   105,    80,   274,    98,    -1,   105,
      64,   257,    98,    -1,   105,    49,   274,   111,   274,   111,
     274,    98,    -1,   105,    84,   274,   111,   274,    98,    -1,
     105,   104,   274,   111,   274,    98,    -1,   105,   113,   274,
     111,   274,    98,    -1,   105,   125,   274,    98,    -1,   105,
      97,   274,    98,    -1,   105,    76,   274,    98,    -1,   105,
      70,   274,    98,    -1,   105,    60,   274,    98,    -1,   287,
      -1,   290,    -1,    -1,   274,    -1,   105,    50,   274,   111,
     274,   288,    98,    -1,    -1,   258,    -1,   105,    25,   274,
     111,   274,   288,    98,    -1,   105,   110,   241,    98,    -1,
     105,   292,    98,    -1,   293,    -1,   296,    -1,   298,    -1,
      83,   294,   295,    -1,    -1,    66,    -1,    85,    -1,   274,
      -1,   297,   294,   274,    -1,    82,    -1,    75,    -1,    81,
      -1,    86,    -1,    94,    -1,   100,   294,   274,    -1,   100,
     294,   299,   274,    -1,   105,    57,   310,    98,    -1,   311,
      -1,   105,   311,   247,    98,    -1,   310,   304,    -1,   133,
     311,    -1,   161,    -1,   302,    -1,    -1,   303,    -1,   306,
      -1,   307,    -1,   308,    -1,   140,    -1,   141,    -1,   142,
      -1,   143,    -1,   144,    -1,   145,    -1,   146,    -1,   147,
      -1,   148,    -1,   138,    -1,   139,    -1,   149,    -1,   151,
      -1,   150,    -1,   152,    -1,   153,    -1,   312,    -1,   155,
      -1,   154,    -1,   156,    -1,   157,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SPARQLalgebraParser::yyprhs_[] =
  {
         0,     0,     3,     5,     7,     9,    14,    16,    21,    23,
      28,    33,    35,    37,    39,    42,    44,    46,    48,    50,
      52,    54,    56,    58,    60,    62,    67,    69,    71,    73,
      78,    81,    86,    87,    88,    95,    96,    99,   107,   108,
     111,   116,   117,   120,   125,   130,   135,   137,   139,   141,
     143,   145,   150,   155,   157,   168,   170,   173,   175,   178,
     184,   192,   194,   197,   199,   201,   203,   205,   210,   217,
     219,   221,   223,   228,   230,   235,   237,   241,   243,   246,
     248,   250,   252,   254,   256,   258,   260,   262,   264,   266,
     268,   274,   275,   277,   283,   284,   286,   292,   298,   305,
     312,   319,   324,   329,   334,   341,   342,   345,   346,   348,
     351,   353,   358,   363,   368,   374,   376,   378,   380,   382,
     384,   386,   388,   390,   392,   394,   396,   398,   399,   402,
     403,   408,   413,   418,   420,   423,   425,   427,   433,   435,
     437,   439,   441,   443,   450,   452,   454,   456,   459,   461,
     463,   469,   471,   473,   475,   477,   479,   486,   488,   490,
     493,   498,   500,   503,   510,   517,   523,   524,   526,   527,
     534,   541,   547,   553,   559,   561,   566,   569,   570,   573,
     575,   577,   579,   581,   583,   585,   591,   597,   602,   607,
     614,   616,   618,   620,   622,   624,   629,   631,   634,   636,
     638,   640,   642,   644,   646,   648,   650,   652,   654,   656,
     658,   660,   662,   664,   666,   668,   670,   672,   678,   684,
     686,   688,   690,   696,   702,   708,   714,   720,   726,   731,
     733,   739,   745,   751,   757,   762,   767,   772,   774,   776,
     778,   780,   782,   784,   786,   791,   796,   803,   808,   813,
     818,   823,   828,   832,   837,   842,   847,   852,   857,   859,
     864,   869,   874,   879,   886,   893,   900,   905,   910,   915,
     920,   925,   930,   935,   939,   944,   949,   954,   959,   964,
     969,   974,   983,   990,   997,  1004,  1009,  1014,  1019,  1024,
    1029,  1031,  1033,  1034,  1036,  1044,  1045,  1047,  1055,  1060,
    1064,  1066,  1068,  1070,  1074,  1075,  1077,  1079,  1081,  1085,
    1087,  1089,  1091,  1093,  1095,  1099,  1104,  1109,  1111,  1116,
    1119,  1122,  1124,  1126,  1127,  1129,  1131,  1133,  1135,  1137,
    1139,  1141,  1143,  1145,  1147,  1149,  1151,  1153,  1155,  1157,
    1159,  1161,  1163,  1165,  1167,  1169,  1171,  1173,  1175
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLalgebraParser::yyrline_[] =
  {
         0,   337,   337,   340,   346,   350,   353,   357,   360,   364,
     367,   370,   373,   379,   382,   389,   390,   397,   398,   405,
     406,   413,   414,   421,   422,   429,   433,   439,   440,   448,
     454,   460,   464,   466,   464,   474,   476,   480,   487,   490,
     497,   502,   504,   508,   512,   516,   522,   523,   524,   525,
     526,   530,   534,   564,   570,   577,   578,   582,   583,   589,
     598,   605,   609,   616,   617,   624,   628,   634,   641,   648,
     651,   671,   675,   678,   682,   685,   689,   695,   699,   708,
     709,   710,   711,   712,   713,   714,   715,   716,   717,   718,
     722,   728,   731,   737,   743,   746,   754,   762,   770,   778,
     786,   794,   802,   810,   818,   824,   827,   834,   837,   841,
     845,   854,   862,   870,   873,   881,   884,   890,   896,   897,
     900,   903,   911,   915,   919,   925,   926,   930,   933,   940,
     940,   950,   953,   959,   963,   970,   971,   972,   976,   977,
     978,   979,   980,   981,   988,   989,   993,   997,  1004,  1005,
    1006,  1010,  1011,  1012,  1013,  1014,  1015,  1019,  1025,  1029,
    1036,  1042,  1045,  1052,  1066,  1080,  1094,  1097,  1101,  1101,
    1111,  1119,  1128,  1137,  1153,  1156,  1163,  1169,  1172,  1220,
    1221,  1222,  1223,  1224,  1225,  1229,  1235,  1243,  1249,  1252,
    1258,  1259,  1260,  1264,  1267,  1275,  1281,  1282,  1289,  1306,
    1309,  1313,  1316,  1322,  1323,  1327,  1330,  1331,  1334,  1337,
    1338,  1344,  1345,  1346,  1347,  1348,  1349,  1353,  1362,  1371,
    1375,  1376,  1380,  1383,  1386,  1389,  1392,  1395,  1398,  1406,
    1410,  1416,  1430,  1436,  1445,  1448,  1451,  1457,  1458,  1459,
    1462,  1465,  1468,  1471,  1482,  1485,  1488,  1491,  1494,  1497,
    1500,  1503,  1506,  1509,  1512,  1515,  1518,  1521,  1524,  1525,
    1528,  1531,  1534,  1537,  1540,  1543,  1546,  1549,  1552,  1555,
    1558,  1561,  1564,  1567,  1570,  1573,  1576,  1579,  1582,  1585,
    1588,  1592,  1595,  1598,  1601,  1604,  1607,  1610,  1613,  1616,
    1619,  1620,  1624,  1627,  1633,  1639,  1642,  1646,  1652,  1664,
    1668,  1669,  1670,  1674,  1680,  1683,  1689,  1692,  1696,  1702,
    1705,  1708,  1711,  1714,  1720,  1723,  1729,  1733,  1736,  1742,
    1749,  1755,  1759,  1766,  1770,  1774,  1775,  1776,  1780,  1781,
    1782,  1786,  1787,  1788,  1792,  1793,  1794,  1798,  1799,  1803,
    1804,  1805,  1806,  1810,  1811,  1815,  1816,  1820,  1821
  };

  // Print the state stack on the debug stream.
  void
  SPARQLalgebraParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  SPARQLalgebraParser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  SPARQLalgebraParser::token_number_type
  SPARQLalgebraParser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SPARQLalgebraParser::yyeof_ = 0;
  const int SPARQLalgebraParser::yylast_ = 1981;
  const int SPARQLalgebraParser::yynnts_ = 152;
  const int SPARQLalgebraParser::yyempty_ = -2;
  const int SPARQLalgebraParser::yyfinal_ = 76;
  const int SPARQLalgebraParser::yyterror_ = 1;
  const int SPARQLalgebraParser::yyerrcode_ = 256;
  const int SPARQLalgebraParser::yyntokens_ = 162;

  const unsigned int SPARQLalgebraParser::yyuser_token_number_max_ = 416;
  const SPARQLalgebraParser::token_number_type SPARQLalgebraParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 3893 "lib/SPARQLalgebraParser/SPARQLalgebraParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 1826 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
 /*** Additional Code ***/

void w3c_sw::SPARQLalgebraParser::error(const SPARQLalgebraParser::location_type& l,
				    const std::string& constM)
{
    driver.error(l, constM);
}

/* START Driver (@@ stand-alone would allow it to be shared with other parsers */

namespace w3c_sw {

    SPARQLalgebraDriver::SPARQLalgebraDriver (std::string baseURI, AtomFactory* atomFactory) : 
	YaccDriver(baseURI, atomFactory), curSubject(NULL), curPredicate(NULL), 
	curFilter(NULL), 
	curResultSet(NULL), curResult(NULL), curExprList(NULL), 
	root(NULL), unnestTree(false)
{
}

    SPARQLalgebraDriver::~SPARQLalgebraDriver ()
{
}

const Operation* SPARQLalgebraDriver::parse (IStreamContext& in)
{
    root = NULL;
    curGraphName = NULL;
    streamname = in.nameStr;

    SPARQLalgebraScanner scanner(this, in.p);
    scanner.set_debug(trace_scanning);
    lexer = &scanner;

    SPARQLalgebraParser parser(*this);
    parser.set_debug_level(trace_parsing);
    // !!! Clear out namespaces!
    ignorePrefixFlag = false;
    parser.parse();
    return root;
}

const Operation* SPARQLalgebraDriver::parse (std::string queryStr)
{
    IStreamContext in(queryStr.c_str(), IStreamContext::STRING);
    return parse(in);
}

void SPARQLalgebraDriver::executeSelect (IStreamContext& in, RdfDB* db, ResultSet* rs) {
    parse(in);
    root->execute(db, rs);
    delete root;
    root = NULL;
}
void SPARQLalgebraDriver::executeSelect (std::string queryStr, RdfDB* db, ResultSet* rs) {
    parse(queryStr);
    root->execute(db, rs);
    delete root;
    root = NULL;
}


} // namespace w3c_sw

/* END Driver */


