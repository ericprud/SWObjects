/* A Bison parser, made by GNU Bison 2.5.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
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

// Take the name prefix into account.
#define yylex   w3c_swlex

/* First part of user declarations.  */


/* Line 293 of lalr1.cc  */
#line 41 "lib/SPARQLalgebraParser/SPARQLalgebraParser.cpp"


#include "SPARQLalgebraParser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 262 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"

#include "../SPARQLalgebraScanner.hpp"

/* Line 299 of lalr1.cc  */
#line 320 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"

#include <stdarg.h>
#include "SPARQLalgebraScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex


/* Line 299 of lalr1.cc  */
#line 67 "lib/SPARQLalgebraParser/SPARQLalgebraParser.cpp"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                               \
 do                                                                    \
   if (N)                                                              \
     {                                                                 \
       (Current).begin = YYRHSLOC (Rhs, 1).begin;                      \
       (Current).end   = YYRHSLOC (Rhs, N).end;                        \
     }                                                                 \
   else                                                                \
     {                                                                 \
       (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;        \
     }                                                                 \
 while (false)
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


namespace w3c_sw {

/* Line 382 of lalr1.cc  */
#line 153 "lib/SPARQLalgebraParser/SPARQLalgebraParser.cpp"

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

  inline bool
  SPARQLalgebraParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  SPARQLalgebraParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

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
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 565 of lalr1.cc  */
#line 37 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 565 of lalr1.cc  */
#line 347 "lib/SPARQLalgebraParser/SPARQLalgebraParser.cpp"

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
    if (yy_pact_value_is_default_ (yyn))
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
	if (yy_table_value_is_error_ (yyn))
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

/* Line 690 of lalr1.cc  */
#line 337 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 340 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 350 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(4) - (3)].p_Operation);
    }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 357 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(4) - (3)].p_Operation);
    }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 364 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Select((yysemantic_stack_[(4) - (3)].p_protoSelect).distinctness, (yysemantic_stack_[(4) - (3)].p_protoSelect).varSet, (yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_protoSelect).p_WhereClause, (yysemantic_stack_[(4) - (3)].p_protoSelect).p_SolutionModifier);
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 367 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(4) - (2)].p_DatasetClauses), new WhereClause((yysemantic_stack_[(4) - (3)].p_op)));
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 370 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Ask(new ProductionVector<const DatasetClause*>(), new WhereClause((yysemantic_stack_[(1) - (1)].p_op)));
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 373 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Select((yysemantic_stack_[(1) - (1)].p_protoSelect).distinctness, (yysemantic_stack_[(1) - (1)].p_protoSelect).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(1) - (1)].p_protoSelect).p_WhereClause, (yysemantic_stack_[(1) - (1)].p_protoSelect).p_SolutionModifier);
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 379 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>((yysemantic_stack_[(1) - (1)].p_DatasetClause));
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 382 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 390 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(1) - (1)].p_protoSelect);
	(yyval.p_protoSelect).p_SolutionModifier = new SolutionModifier(NULL, NULL, NULL, -1, -1);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 398 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(1) - (1)].p_protoSelect);
	(yyval.p_protoSelect).distinctness = DIST_all;
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 406 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(1) - (1)].p_protoSelect);
	(yyval.p_protoSelect).varSet = new StarVarSet();
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 414 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(1) - (1)].p_protoSelect);
	(yyval.p_protoSelect).p_OrderConditions = NULL;
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 422 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(1) - (1)].p_protoSelect);
	(yyval.p_protoSelect).p_having = NULL;
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 429 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	throw std::string("ExtendOpt: not ready to parse aggregates");
	(yyval.p_protoSelect) = (yysemantic_stack_[(4) - (3)].p_protoSelect);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 433 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(1) - (1)].p_protoSelect);
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 440 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect).p_WhereClause = new WhereClause((yysemantic_stack_[(1) - (1)].p_op));
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 448 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = (yysemantic_stack_[(4) - (3)].p_op);
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 454 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 464 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 466 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 468 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(6) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(6) - (5)].p_URI));
      }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 480 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(7) - (6)].p_protoSelect);
	(yyval.p_protoSelect).varSet = (yysemantic_stack_[(7) - (4)].p_ExpressionAliaseList);
    }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 487 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList();
    }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 490 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_Variable))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 497 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	throw std::string("Extend: not ready to parse aggregates");
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 530 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(4) - (3)].p_protoSelect);
	(yyval.p_protoSelect).distinctness = DIST_distinct;
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 534 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(4) - (3)].p_protoSelect);
	(yyval.p_protoSelect).distinctness = DIST_reduced;
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 570 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	throw std::string("GroupClause: not ready to parse aggregates");
	(yyval.p_protoSelect).p_WhereClause = new WhereClause((yysemantic_stack_[(10) - (9)].p_op));
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 589 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(5) - (4)].p_protoSelect);
	(yyval.p_protoSelect).p_having = new w3c_sw::ProductionVector<const w3c_sw::Expression*>((yysemantic_stack_[(5) - (3)].p_Expression)); // !!!
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 598 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(7) - (6)].p_protoSelect);
	(yyval.p_protoSelect).p_OrderConditions = (yysemantic_stack_[(7) - (4)].p_OrderConditions);
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 605 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 609 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 617 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 624 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 628 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 634 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(4) - (2)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(4) - (3)].p_Expression);
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 641 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(6) - (5)].p_protoSelect); // ($5.p_group, ...)
	(yyval.p_protoSelect).p_SolutionModifier = new SolutionModifier(NULL, (yysemantic_stack_[(6) - (5)].p_protoSelect).p_having, (yysemantic_stack_[(6) - (5)].p_protoSelect).p_OrderConditions, (yysemantic_stack_[(6) - (3)].p_int), (yysemantic_stack_[(6) - (4)].p_int)); // !!!
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 648 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_int) = ((IntegerRDFLiteral*)(yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 651 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_int) = LIMIT_None;
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 675 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(4) - (3)].p_Operation);
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 682 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(4) - (3)].p_Operation);
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 689 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(3) - (2)]. p_OperationSet);
}
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 695 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	OperationSet* ret = new OperationSet();
	ret->push_back((yysemantic_stack_[(1) - (1)].p_Operation));
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 699 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)]. p_OperationSet)->push_back((yysemantic_stack_[(2) - (2)].p_Operation));
	(yyval. p_OperationSet) = (yysemantic_stack_[(2) - (1)]. p_OperationSet);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 722 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (4)].p_URI));
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 728 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 737 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(5) - (3)].p_Silence), (yysemantic_stack_[(5) - (4)].p_URI));
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 743 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 746 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
    }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 754 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(5) - (3)].p_Silence), (yysemantic_stack_[(5) - (4)].p_URI));
    }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 762 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(5) - (3)].p_Silence), (yysemantic_stack_[(5) - (4)].p_URI));
    }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 770 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(6) - (3)].p_Silence), (yysemantic_stack_[(6) - (4)].p_URI), (yysemantic_stack_[(6) - (5)].p_URI));
    }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 778 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(6) - (3)].p_Silence), (yysemantic_stack_[(6) - (4)].p_URI), (yysemantic_stack_[(6) - (5)].p_URI));
    }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 786 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(6) - (3)].p_Silence), (yysemantic_stack_[(6) - (4)].p_URI), (yysemantic_stack_[(6) - (5)].p_URI));
    }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 794 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Insert((yysemantic_stack_[(4) - (3)].p_op), NULL);
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 802 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(4) - (3)].p_op), NULL);
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 810 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(4) - (3)].p_op), NULL);
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 818 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(6) - (5)].p_DeleteInsert).del, (yysemantic_stack_[(6) - (5)].p_DeleteInsert).ins, new WhereClause((yysemantic_stack_[(6) - (4)].p_op)));
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 824 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 827 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 834 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 841 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 845 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 854 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Delete) = new Delete((yysemantic_stack_[(4) - (3)].p_op), NULL);
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 862 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Insert) = new Insert((yysemantic_stack_[(4) - (3)].p_op), NULL);
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 870 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(4) - (3)].p_URI), driver.atomFactory);
    }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 873 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(5) - (3)].p_URI), driver.atomFactory);
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 881 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 897 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	w3c_sw_NEED_IMPL("DEFAULT");
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 900 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	w3c_sw_NEED_IMPL("NAMED");
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 903 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	w3c_sw_NEED_IMPL("ALL");
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 919 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = (yysemantic_stack_[(1) - (1)].p_conj);
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 930 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_conj) = new ParserTableConjunction();
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 933 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_conj)->addTableOperation((yysemantic_stack_[(2) - (2)].p_op), false);
	(yyval.p_conj) = (yysemantic_stack_[(2) - (1)].p_conj);
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 940 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = driver.curGraphName;
	driver.curGraphName = (yysemantic_stack_[(2) - (2)].p_TTerm);
      }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 943 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	  (yyval.p_op) = (yysemantic_stack_[(4) - (4)].p_op);
	  driver.curGraphName = (yysemantic_stack_[(4) - (3)].p_TTerm);
      }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 950 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = (yysemantic_stack_[(4) - (3)].p_BasicGraphPattern);
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 953 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = driver.ensureGraphPattern();
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 959 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_BasicGraphPattern) = driver.ensureGraphPattern();
	(yyval.p_BasicGraphPattern)->addTriplePattern((yysemantic_stack_[(1) - (1)].p_TriplePattern));
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 963 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_BasicGraphPattern)->addTriplePattern((yysemantic_stack_[(2) - (2)].p_TriplePattern));
	(yyval.p_BasicGraphPattern) = (yysemantic_stack_[(2) - (1)].p_BasicGraphPattern);
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 972 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(5) - (4)].p_conj)->insertTableOperation((yysemantic_stack_[(5) - (3)].p_op));
	(yyval.p_op) = (yysemantic_stack_[(5) - (4)].p_conj);
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 981 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	throw new std::string("GroupGraphPatternNoSub: GT_LPAREN IT_path VarOrTerm Path VarOrTerm GT_RPAREN not implemented");
	(yyval.p_op) = driver.ensureGraphPattern();
    }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 993 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_conj) = new ParserTableConjunction();
	(yyval.p_conj)->addTableOperation((yysemantic_stack_[(1) - (1)].p_op), driver.unnestTree);
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 997 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_conj)->addTableOperation((yysemantic_stack_[(2) - (2)].p_op), driver.unnestTree);
	(yyval.p_conj) = (yysemantic_stack_[(2) - (1)].p_conj);
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1006 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(5) - (4)].p_conj)->addTableOperation((yysemantic_stack_[(5) - (3)].p_op), driver.unnestTree);
	(yyval.p_op) = (yysemantic_stack_[(5) - (4)].p_conj);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1015 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	throw new std::string("GroupGraphPatternSub: GT_LPAREN IT_path VarOrTerm Path VarOrTerm GT_RPAREN not implemented");
	(yyval.p_op) = driver.ensureGraphPattern();
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1019 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = new SubSelect(new Select((yysemantic_stack_[(1) - (1)].p_protoSelect).distinctness, (yysemantic_stack_[(1) - (1)].p_protoSelect).varSet, NULL, (yysemantic_stack_[(1) - (1)].p_protoSelect).p_WhereClause, (yysemantic_stack_[(1) - (1)].p_protoSelect).p_SolutionModifier));
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1025 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_conj) = new ParserTableConjunction();
	(yyval.p_conj)->addTableOperation((yysemantic_stack_[(1) - (1)].p_op), driver.unnestTree);
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1029 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_conj)->addTableOperation((yysemantic_stack_[(2) - (2)].p_op), driver.unnestTree);
	(yyval.p_conj) = (yysemantic_stack_[(2) - (1)].p_conj);
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1036 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(4) - (3)].p_Expressions);
    }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1042 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1045 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1052 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TriplePattern) = driver.atomFactory->getTriple((yysemantic_stack_[(6) - (3)].p_TTerm), (yysemantic_stack_[(6) - (4)].p_TTerm), (yysemantic_stack_[(6) - (5)].p_TTerm));
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
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

/* Line 690 of lalr1.cc  */
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

/* Line 690 of lalr1.cc  */
#line 1094 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1101 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = driver.curGraphName;
	driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1104 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	  (yyval.p_op) = (yysemantic_stack_[(6) - (5)].p_op);
	  driver.curGraphName = (yysemantic_stack_[(6) - (4)].p_TTerm);
      }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1111 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = new ServiceGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), (yysemantic_stack_[(6) - (5)].p_op), (yysemantic_stack_[(6) - (3)].p_Silence), driver.atomFactory, false);
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1119 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	TableConjunction* ret = new TableConjunction();
	ret->addTableOperation((yysemantic_stack_[(5) - (3)].p_op), driver.unnestTree);
	ret->addTableOperation(new MinusGraphPattern((yysemantic_stack_[(5) - (4)].p_op)), driver.unnestTree);
	(yyval.p_op) = ret;
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1128 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	TableDisjunction* ret = new TableDisjunction();
	ret->addTableOperation((yysemantic_stack_[(5) - (3)].p_op), driver.unnestTree);
	ret->addTableOperation((yysemantic_stack_[(5) - (4)].p_op), driver.unnestTree);
	(yyval.p_op) = ret;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1137 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = new Filter((yysemantic_stack_[(5) - (4)].p_op), (yysemantic_stack_[(5) - (3)].p_Expressions)->begin(), (yysemantic_stack_[(5) - (3)].p_Expressions)->end());
	(yysemantic_stack_[(5) - (3)].p_Expressions)->clear();
	delete (yysemantic_stack_[(5) - (3)].p_Expressions);
    }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1153 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1156 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(4) - (3)].p_Expressions)->push_front((yysemantic_stack_[(4) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(4) - (3)].p_Expressions);
    }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1163 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1169 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1172 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1229 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	// $$ = new PathAlternative($3, $4);
    }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1235 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	// $$ = new PathSequence($3, $4);
    }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1243 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	// $$ = new PathEltOrInverse($3);
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1249 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	// $$ = $3;
    }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1252 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	// $$ = $5;
      }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1264 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1267 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1275 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(4) - (3)].p_TTerm);
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1282 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	// $1->push_back($2);
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (1)].p_TTerm);
    }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1289 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1306 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1313 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1316 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1327 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1331 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1334 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1338 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil");
    }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 1353 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yysemantic_stack_[(5) - (3)].p_Expression));
	t->push_back((yysemantic_stack_[(5) - (4)].p_Expression));
	(yyval.p_Expression) = new BooleanDisjunction(t);
    }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 1362 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yysemantic_stack_[(5) - (3)].p_Expression));
	t->push_back((yysemantic_stack_[(5) - (4)].p_Expression));
	(yyval.p_Expression) = new BooleanConjunction(t);
    }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1380 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanEQ((yysemantic_stack_[(5) - (3)].p_Expression), (yysemantic_stack_[(5) - (4)].p_Expression));
    }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 1383 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNE((yysemantic_stack_[(5) - (3)].p_Expression), (yysemantic_stack_[(5) - (4)].p_Expression));
    }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 1386 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanLT((yysemantic_stack_[(5) - (3)].p_Expression), (yysemantic_stack_[(5) - (4)].p_Expression));
    }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 1389 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanGT((yysemantic_stack_[(5) - (3)].p_Expression), (yysemantic_stack_[(5) - (4)].p_Expression));
    }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 1392 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanLE((yysemantic_stack_[(5) - (3)].p_Expression), (yysemantic_stack_[(5) - (4)].p_Expression));
    }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 1395 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanGE((yysemantic_stack_[(5) - (3)].p_Expression), (yysemantic_stack_[(5) - (4)].p_Expression));
    }
    break;

  case 228:

/* Line 690 of lalr1.cc  */
#line 1398 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new NaryIn((yysemantic_stack_[(4) - (3)].p_Expressions));
    }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 1410 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yysemantic_stack_[(5) - (3)].p_Expression));
	t->push_back((yysemantic_stack_[(5) - (4)].p_Expression));
	(yyval.p_Expression) = new ArithmeticSum(t);
    }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 1416 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yysemantic_stack_[(5) - (3)].p_Expression));
	t->push_back(new ArithmeticNegation((yysemantic_stack_[(5) - (4)].p_Expression)));
	(yyval.p_Expression) = new ArithmeticSum(t);
    }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 1430 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yysemantic_stack_[(5) - (3)].p_Expression));
	t->push_back(new ArithmeticNegation((yysemantic_stack_[(5) - (4)].p_Expression)));
	(yyval.p_Expression) = new ArithmeticProduct(t);
    }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 1436 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yysemantic_stack_[(5) - (3)].p_Expression));
	t->push_back(new ArithmeticInverse((yysemantic_stack_[(5) - (4)].p_Expression)));
	(yyval.p_Expression) = new ArithmeticProduct(t);
    }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 1445 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(4) - (3)].p_Expression));
    }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 1448 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(4) - (3)].p_Expression);
    }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 1451 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(4) - (3)].p_Expression));
    }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 1459 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 1462 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 1465 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 1468 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 1471 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 1482 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 1485 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 1488 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 1491 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 1494 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 1497 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 250:

/* Line 690 of lalr1.cc  */
#line 1500 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 251:

/* Line 690 of lalr1.cc  */
#line 1503 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 1506 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 1509 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 1512 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ciel, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 1515 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 1518 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 1521 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(4) - (3)].p_Expressions))));
    }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 1525 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 1528 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 1531 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 1534 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 1537 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 1540 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 1543 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 1546 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 1549 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 1552 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 1555 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 1558 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 1561 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 1564 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 1567 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 1570 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 1573 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 1576 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 1579 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 1582 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 1585 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 1588 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 1591 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 1594 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 1598 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 1601 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 1604 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 1607 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 1610 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 1613 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 1616 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 1619 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 1622 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 1630 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 1639 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 1645 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 1652 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 1658 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.ensureGraphPattern(), NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 1680 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
 	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(3) - (2)].p_distinctness), (yysemantic_stack_[(3) - (3)].p_Expression)));
    }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 1686 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 1689 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
}
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 1695 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 1702 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(3) - (1)].p_URI), (yysemantic_stack_[(3) - (2)].p_distinctness), (yysemantic_stack_[(3) - (3)].p_Expression)));
    }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 1708 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 1711 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 1714 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 1717 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 1720 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 1726 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(3) - (2)].p_distinctness), (yysemantic_stack_[(3) - (3)].p_Expression)));
    }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 1729 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(4) - (2)].p_distinctness), (yysemantic_stack_[(4) - (4)].p_Expression)));
    }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 1739 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 1742 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(4) - (2)].p_URI), new ArgList((yysemantic_stack_[(4) - (3)].p_Expressions))));
    }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 1748 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 1755 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 1761 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 1765 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 1772 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 690 of lalr1.cc  */
#line 2523 "lib/SPARQLalgebraParser/SPARQLalgebraParser.cpp"
	default:
          break;
      }
    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
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
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
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

    yyerror_range[1] = yylocation_stack_[yylen - 1];
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
	if (!yy_pact_value_is_default_ (yyn))
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

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
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
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

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
  SPARQLalgebraParser::yysyntax_error_ (int yystate, int yytoken)
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yychar.
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            /* Stay within bounds of both yycheck and yytname.  */
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = 0;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int SPARQLalgebraParser::yypact_ninf_ = -611;
  const short int
  SPARQLalgebraParser::yypact_[] =
  {
       -80,   570,    41,  -611,  -611,  -611,  -611,  -611,  -611,  -611,
    -611,  -611,  -611,  -611,  -611,  -611,  -611,  -611,  -611,  -611,
    -611,  -611,  -611,  -611,  -611,  -611,  -611,  -611,  -611,  -611,
    -611,  -611,  -611,  -611,  -110,    30,    33,    36,    40,    40,
      46,  1748,    52,    54,    61,  -611,  -611,    54,    54,    54,
    -105,  1438,    54,   -78,   -88,    35,   363,    66,    78,    81,
      91,   -28,  -611,  -611,  -611,  -611,  -611,  -611,  -611,  -611,
    -611,  -611,  -611,  -611,  -611,   112,  -611,  -611,  -611,  -611,
    -611,  1255,   -13,    19,   117,   773,  -611,  -611,  -611,  -611,
    -611,  -611,  -611,  -611,  -611,  -611,  -611,  -611,  -611,  -611,
    -611,  -611,  -611,  -611,  -611,  -611,  -611,    54,  -611,   135,
    -611,  -611,  -611,  -611,  -611,  -611,  -611,  -611,  -611,  -611,
    -611,  -611,  -611,  -611,  -611,  -611,  -611,  -611,  -611,  -611,
    -611,  -108,  -611,  -611,  1771,  1491,    72,   237,   -17,  -611,
      54,   147,    54,  -611,  -611,  -611,  -611,  -611,  -611,    -8,
    -611,  -611,  -611,  -611,  -611,  -611,  -611,    54,  -611,  -105,
    -611,  -611,   -88,  -611,   158,   -62,  -611,   -78,   -62,   -78,
     -62,   -78,   -78,  -611,   -78,  -611,  -611,   -78,  1295,   160,
     166,  -611,  1175,   168,   169,  1212,   170,   172,   465,   174,
    -611,    11,  -611,  1373,  -611,  -611,  -611,  -611,  -611,  -611,
    -611,    54,  -611,  -611,  -611,  -611,  -611,  -611,   -14,   -84,
       9,  -611,  -611,  -102,  -611,    14,  1802,  1802,  1802,  1802,
    1802,  1802,  1802,  1802,  1802,   -89,  1802,  1802,  1802,  1802,
    1802,  1802,  1802,  1802,  1802,  1802,  1802,  1802,   -45,  1802,
    1802,  1802,  1802,  1802,  1802,  1802,  1802,  1802,  1802,  1802,
    1802,  1802,  1802,   175,  1802,  1802,  1802,  1802,  1802,  1802,
    1802,  1802,  1802,  1802,    54,  1802,  1802,  1802,  1802,  1802,
    1802,  1802,  1802,  1802,  1802,  1802,  1802,  1802,  1802,  1802,
     177,  1802,   182,  1432,   188,   -62,  -611,  -611,  -611,  -611,
     650,  1462,  -611,  -611,  -611,   147,  -611,  1438,  -611,  -611,
     147,   190,  -611,   198,   205,    54,  -611,    43,  1438,  -611,
    -611,  -611,  -611,  -611,  -611,  -611,   210,    54,   204,  -611,
     -62,   206,   -62,   213,   -57,   -62,    -3,   -57,   218,  -611,
     -39,   -57,   219,  -611,   221,    -3,  -611,  -611,  -611,  -611,
    -611,  -611,  -611,  1438,   112,  -611,    15,  -611,  -611,  -611,
     214,  -611,  -611,   -89,  -611,  1802,   217,  -611,  1019,   215,
     227,   228,   231,   235,   236,   238,   241,   243,   244,  1524,
    -611,   249,  1547,  1802,   240,   242,  1802,   250,  1802,   255,
    -611,   258,   260,  -611,  1802,   261,   262,   252,   264,   269,
     270,  1802,  1609,   272,   274,   265,  1802,   266,   275,   278,
    -611,   283,   284,   285,   286,   290,  1632,   279,   280,   297,
    1802,   298,  1802,   294,   300,  1802,  1802,   296,   304,   312,
    1694,  1802,   313,   315,   316,   305,   308,  -611,  1717,  -611,
    -611,  -611,  -611,  -611,  1802,   318,  -611,  1438,   324,  -611,
    -611,   327,    -8,    -8,  -611,  -611,  -611,    -8,    -8,   -88,
      -8,   329,  -611,   330,  1338,   331,   337,  1472,  -611,   336,
     345,  -611,  -611,  -611,   -57,  -611,   346,  -611,  -611,  -611,
    -611,  -611,   351,   -57,  -611,     0,  -105,  -611,  -611,  -611,
     -57,  -611,  -611,   353,    -8,   112,  -611,  -611,   203,  1413,
     354,  1802,   359,   352,  1802,  -611,  -611,  -611,  -611,  -611,
    -611,  -611,  -611,  -611,  -611,  -611,  -611,  -611,   361,  1802,
    1802,   362,  -611,   364,  -611,  -611,  -611,  -611,  -611,  -611,
    1802,  -611,  -611,  -611,   365,  -611,   366,  -611,  -611,  1802,
     367,  1802,  -611,  -611,  -611,  -611,  -611,  -611,  -611,  -611,
    1802,  1802,  -611,   369,  -611,   372,  1802,  -611,   374,   375,
    1802,  -611,  -611,  -611,   378,   379,  -611,  -611,  -611,  1802,
    1802,  -611,   387,  1452,   393,  1438,  -611,  -611,   394,    -8,
    -611,   -29,    -8,   -88,   395,  -611,  -611,  -611,  -611,   -32,
     396,   355,  -611,  -611,   397,  -611,  -611,   399,  -611,   400,
    -611,  1438,  -611,    25,  -611,  -611,   403,  -611,   340,  -611,
      47,   391,  -611,   392,   391,  -611,  -611,   -50,   409,  -611,
    -611,   410,  -611,   412,   413,   414,  -611,  -611,   415,  -611,
    -611,   416,  -611,  -611,   417,   418,  -611,  -611,   423,  -611,
     425,  -611,  -611,   426,    -8,  -611,  -611,  -611,  -611,   466,
    -611,  -611,  -611,  -611,   427,  -611,   434,  -611,  -611,   380,
    -611,   429,    54,  -611,  1802,  -611,   438,  1802,   443,  -611,
    -611,  -611,  -611,  -611,  -611,  -611,  -611,  -611,  -611,  -611,
    -611,  -611,  -611,   447,   451,   452,  -611,  -611,   453,   263,
     456,   460,  -611,  -611,   461,  -611,  -611,  -611,  -611,  -611,
    -611,  -611,  -611,   494,  -611,  -611,   494,   463,  -611,  -611,
     494,  -611,  -611,  -611,  -611,  -611,   478,  1825,  -611,  1802,
    -611,  -611,  -611,   896,  -611,  1802,  -611,    90,  -611,   467,
    -611
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
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
      41,     0,     0,     0,     0,     0,   339,   340,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   341,   343,   342,
     344,   345,   348,   347,   243,   203,   204,     0,   242,     0,
     211,   212,   213,   219,   221,   220,   229,   214,   215,   216,
     237,   292,   258,   293,   238,   239,   240,   327,   328,   329,
     241,   325,   319,   346,     0,     0,     0,     0,     0,   133,
       0,   166,     0,   168,   201,   202,   210,   349,   350,     0,
     199,   200,   206,   207,   208,   205,   209,     0,    95,     0,
      70,   198,     0,    69,     0,     0,   105,    94,     0,    94,
       0,    94,    94,   127,    94,   127,   127,    94,     0,     0,
       0,    14,     0,     0,     0,     0,     0,     0,     0,     0,
      76,     0,    78,     0,    48,   157,    47,    50,    49,    46,
     148,     0,   151,   152,   153,   154,   155,   149,     0,     0,
       0,    51,    52,     0,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   294,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   323,   324,   326,   321,
       0,     0,    61,    63,    64,     0,    29,     0,   131,   134,
     166,     0,   167,     0,     0,     0,   194,     0,     0,   179,
     180,   181,   182,   184,   183,   193,     0,     0,     0,   132,
       0,     0,     0,     0,     0,    91,     0,     0,     0,   122,
     124,     0,     0,   123,     0,     0,     9,    10,     5,    72,
       7,    74,    25,     0,     0,   146,     0,    31,    32,    36,
       0,    39,    40,     0,    42,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     161,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     295,     0,     0,   174,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     276,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   252,     0,   173,
      59,   322,    65,    66,     0,     0,    62,     0,     0,   165,
     172,     0,     0,     0,   192,   191,   190,     0,     0,     0,
       0,     0,   171,     0,     0,     0,     0,     0,   106,     0,
       0,   117,   113,   115,     0,   116,     0,    92,   120,   121,
     119,   118,     0,     0,   103,     0,     0,   128,   125,   126,
       0,   102,   101,     0,     0,     0,   137,   147,     0,     0,
       0,     0,     0,     0,     0,   261,   260,   279,   256,   273,
     244,   255,   272,   248,   228,   162,   271,   257,     0,     0,
       0,     0,   254,     0,   291,   251,   253,   177,   282,   259,
       0,   234,   290,   250,     0,   235,     0,   289,   281,     0,
       0,     0,   249,   280,   270,   288,   262,   275,   274,   160,
       0,     0,   269,     0,   300,     0,     0,   268,     0,     0,
       0,   287,   247,   236,     0,     0,   245,   278,   277,     0,
       0,   320,     0,     0,     0,     0,   164,   169,     0,     0,
     196,     0,     0,     0,     0,   143,   170,    68,   114,     0,
       0,   107,   110,    97,     0,    90,    96,     0,   129,     0,
      93,     0,   158,     0,    33,    37,     0,    44,     0,    57,
       0,   297,   218,     0,   297,   227,   225,     0,     0,   223,
     230,     0,   232,     0,     0,     0,   217,   226,     0,   222,
     224,     0,   231,   233,     0,     0,    67,    60,     0,   187,
       0,   195,   197,     0,     0,   188,   127,   127,   104,     0,
     109,   108,    98,    99,     0,   100,     0,   150,   159,     0,
      43,     0,     0,    58,     0,   298,     0,     0,     0,   175,
     178,   263,   284,   264,   285,   265,   286,   246,   266,   267,
     163,   185,   186,     0,     0,     0,   130,   156,     0,     0,
       0,     0,   176,   299,     0,   296,   189,   112,   111,    34,
     312,   313,   311,   306,   314,   315,   306,     0,   302,   303,
     306,   304,    45,    54,   283,   307,     0,     0,   301,     0,
     308,   309,   305,     0,   316,     0,   310,     0,   317,     0,
     318
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLalgebraParser::yypgoto_[] =
  {
      -611,  -611,  -611,  -611,   506,   507,  -611,   510,   254,    70,
     245,   133,   481,   532,   536,  -611,  -611,  -611,  -611,  -611,
    -611,   -66,  -611,  -611,  -611,  -611,   381,    -2,  -611,   -59,
     -42,  -611,  -611,  -611,   -54,   -53,  -611,   306,  -611,  -611,
     -51,  -150,  -611,  -611,   541,   543,  -611,   539,  -611,  -611,
    -611,    -6,  -611,  -611,  -611,  -611,  -611,  -611,  -611,  -611,
    -611,  -611,  -611,  -611,  -611,    22,   -52,  -316,  -257,   271,
    -526,   428,    64,  -611,  -611,  -611,  -611,   -73,  -611,   -16,
     419,  -611,  -338,  -611,  -131,  -208,   469,   -47,   309,   -46,
    -611,   -40,   -38,   -37,   -31,  -611,     1,  -611,  -310,  -611,
    -611,  -611,  -611,  -611,  -611,  -611,  -611,  -611,  -225,  -155,
      93,  -611,   -41,  -611,  -611,  -611,  -611,  -611,  -611,  -611,
    -611,  -611,  -611,  -611,  -611,  -611,    10,  -611,  -611,  -611,
    -611,  -611,  -610,  -611,  -611,  -611,  -611,  -611,  -611,   -48,
    -611,  -611,  -611,   -34,  -611,  -611,  -611,   -21,  -112,   -43,
    -611,  -611
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLalgebraParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,     5,     6,    57,     7,     8,     9,
      10,    11,    12,    13,    14,    58,    59,   349,   488,   649,
     208,    15,   209,    60,   210,   354,   214,   599,   195,    16,
      17,    18,   215,   600,    19,    20,   291,   292,   434,   293,
      21,   162,    22,    23,    24,    25,    61,    62,    63,   466,
      64,   159,    65,    66,    67,    68,    69,    70,    71,    72,
      73,   321,   640,   580,   581,   582,    74,   464,   471,   472,
     328,   332,   329,   477,   330,   478,   644,    26,   138,    27,
      75,   346,   201,   593,   107,   369,   139,    28,   303,    29,
     305,    30,    31,    32,    33,   385,   655,   607,   308,   309,
     310,   311,   312,   450,   313,   314,   571,   163,   149,   143,
     108,   151,   370,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   381,   121,   656,   122,   123,   680,
     697,   698,   706,   712,   699,   700,   701,   715,   124,   125,
     287,   288,   289,   126,   127,   128,   129,   130,   131,   132,
     133,   156
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char SPARQLalgebraParser::yytable_ninf_ = -1;
  const unsigned short int
  SPARQLalgebraParser::yytable_[] =
  {
       109,   136,   200,   152,   317,   181,   485,   145,   155,   194,
     302,   473,   318,    44,   350,   480,   196,   153,   306,   468,
     372,   197,   198,   469,   199,   285,     1,   636,   202,   203,
     154,   140,   141,   142,   166,   204,   157,   205,   206,   306,
     160,    76,   281,   470,   207,   167,   637,    77,   659,   158,
     383,   406,   101,   102,   103,   164,   161,   286,   105,   106,
     355,   384,   654,   169,   442,   460,   170,   475,   467,   631,
     190,   463,   437,   428,   105,   106,   476,   307,   191,   105,
     106,   298,   443,   451,   347,   211,   707,    55,   171,   137,
     709,   282,   348,   294,   444,   101,   102,   103,   307,   445,
     101,   102,   103,   172,   173,   446,   315,   352,    82,    83,
     674,   675,   356,   486,   174,   353,   145,   212,   484,   175,
     213,   135,   320,   647,   300,   323,   304,   325,   101,   102,
     103,   193,   568,   569,   176,   177,    78,   570,   572,    79,
     574,   316,    80,   144,   150,   652,    81,   592,   584,   101,
     102,   103,    84,   598,   101,   102,   103,   587,   134,   447,
     135,   322,   448,   324,   589,   326,   327,   137,   331,   302,
     296,   335,   178,   449,   591,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   182,   345,   371,   185,   373,   374,
     375,   376,   377,   378,   379,   380,   382,   188,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   565,   401,   402,   403,   404,   405,   193,   407,
     408,   409,   410,   213,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   333,
     333,   283,   431,    97,    98,    99,   100,   281,   411,   152,
     294,   297,   144,   301,   155,   648,   319,   479,   336,   630,
     152,   632,   633,   153,   337,   155,   338,   339,   340,   458,
     341,   200,   342,   400,   153,   427,   154,   456,   194,   461,
     429,   465,   461,   461,   465,   196,   430,   154,   465,   441,
     197,   198,   461,   199,   259,   152,   439,   202,   203,   573,
     155,   453,   351,   440,   204,   459,   205,   206,   452,   153,
     454,   462,   457,   207,   492,   281,   474,   481,   368,   482,
     489,   588,   154,   493,   673,   495,   496,   494,   505,   497,
     487,   505,   508,   498,   499,   511,   500,   513,   690,   501,
     628,   502,   503,   517,   691,   692,   693,   506,   512,   694,
     524,   526,   509,   514,   510,   530,   515,   695,   516,   518,
     519,   594,   521,   696,   520,   505,   646,   522,   523,   543,
     527,   545,   528,   532,   548,   549,   533,   529,   531,   554,
     555,   534,   535,   536,   537,   165,   166,   505,   538,   152,
     150,   540,   541,   562,   155,   542,   544,   167,   547,   315,
     315,   150,   551,   153,   315,   315,   546,   315,   550,   168,
     552,   556,   200,   557,   558,   169,   154,   559,   170,   194,
     560,   465,   566,   634,   563,   567,   196,   575,   576,   577,
     465,   197,   198,   145,   199,   578,   150,   465,   202,   203,
     171,   315,   579,   583,   585,   204,   491,   205,   206,   586,
     596,   590,   595,   601,   207,   172,   173,   597,   598,   602,
     605,   639,   606,   609,   610,   612,   174,   616,   603,   604,
     617,   175,   619,   620,    40,   295,   622,   623,    44,   608,
      45,    46,    47,    48,    49,   626,   176,   177,   611,    50,
     613,   627,   629,   635,   638,   642,    51,   643,   645,   614,
     615,   650,   651,   654,   657,   618,    52,   661,   662,   621,
     663,   664,   665,   666,   667,   668,   669,   152,   624,   625,
     200,   670,   155,   671,   672,   636,   315,   194,   315,   315,
     150,   153,   677,   475,   196,   679,   683,   678,    53,   197,
     198,   685,   199,   152,   154,   686,   202,   203,   155,   687,
     688,   689,    55,   204,   702,   205,   206,   153,   703,   704,
     705,   708,   207,   710,   183,   720,   186,   179,   564,   144,
     154,   676,   455,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,   358,    45,    46,    47,    48,    49,
     284,   315,   189,   180,    50,   490,   357,   436,   653,   184,
     192,    51,   187,   641,   334,   719,   483,   299,   660,   438,
     681,    52,   344,   682,   658,     0,   684,     0,     0,     0,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,     0,
     104,   105,   106,    53,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,    55,   150,     0,
       0,     0,     0,     0,     0,   711,   714,     0,   716,     0,
     281,     0,     0,     0,   718,   216,    56,   217,   218,   219,
     220,     0,   221,   222,   150,   432,   433,   223,   224,     0,
     225,     0,   226,   227,   228,   229,     0,     0,     0,   230,
     231,     0,     0,   232,   233,     0,     0,     0,   234,     0,
     235,   236,     0,   237,   238,     0,     0,   239,   240,   241,
     242,   243,   244,     0,   245,     0,   246,     0,     0,     0,
     247,     0,     0,     0,   248,   249,     0,     0,   250,   251,
     252,   253,     0,     0,     0,     0,   254,   255,     0,   256,
       0,   257,   258,     0,     0,   260,     0,   261,     0,   262,
     263,   264,     0,   265,   266,     0,     0,   267,   268,     0,
     269,     0,   270,     0,     0,     0,   271,     0,     0,   272,
       0,   273,   274,     0,   275,   276,     0,     0,   277,   278,
     279,   280,     0,     0,     0,     0,     0,     0,   216,     0,
     217,   218,   219,   220,     0,   221,   222,   101,   102,   103,
     223,   224,     0,   225,     0,   226,   227,   228,   229,     0,
       0,     0,   230,   231,     0,     0,   232,   233,     0,     0,
       0,   234,     0,   235,   236,     0,   237,   238,     0,     0,
     239,   240,   241,   242,   243,   244,     0,   245,     0,   246,
       0,     0,     0,   247,     0,     0,     0,   248,   249,     0,
       0,   250,   251,   252,   253,     0,     0,     0,     0,   254,
     255,     0,   256,     0,   257,   258,     0,   259,   260,     0,
     261,     0,   262,   263,   264,     0,   265,   266,     0,     0,
     267,   268,     0,   269,     0,   270,     0,     0,     0,   271,
       0,     0,   272,     0,   273,   274,     0,   275,   276,     0,
       0,   277,   278,   279,   280,     0,     0,     0,     0,     0,
       0,   216,     0,   217,   218,   219,   220,     0,   221,   222,
     101,   102,   103,   223,   224,     0,   225,     0,   226,   227,
     228,   229,     0,     0,     0,   230,   231,     0,     0,   232,
     233,     0,     0,   717,   234,     0,   235,   236,     0,   237,
     238,     0,     0,   239,   240,   241,   242,   243,   244,     0,
     245,     0,   246,     0,     0,     0,   247,     0,     0,     0,
     248,   249,     0,     0,   250,   251,   252,   253,     0,     0,
       0,     0,   254,   255,     0,   256,     0,   257,   258,     0,
       0,   260,     0,   261,     0,   262,   263,   264,     0,   265,
     266,     0,     0,   267,   268,     0,   269,     0,   270,     0,
       0,     0,   271,     0,     0,   272,     0,   273,   274,     0,
     275,   276,     0,     0,   277,   278,   279,   280,     0,     0,
       0,     0,     0,     0,   216,     0,   217,   218,   219,   220,
       0,   221,   222,   101,   102,   103,   223,   224,     0,   225,
       0,   226,   227,   228,   229,     0,     0,     0,   230,   231,
       0,     0,   232,   233,     0,     0,     0,   234,     0,   235,
     236,     0,   237,   238,     0,     0,   239,   240,   241,   242,
     243,   244,     0,   245,     0,   246,     0,     0,     0,   247,
       0,     0,     0,   248,   249,     0,     0,   250,   251,   252,
     253,     0,     0,     0,     0,   254,   255,     0,   256,     0,
     257,   258,     0,     0,   260,     0,   261,     0,   262,   263,
     264,     0,   265,   266,     0,     0,   267,   268,     0,   269,
       0,   270,     0,     0,     0,   271,     0,     0,   272,     0,
     273,   274,     0,   275,   276,     0,     0,   277,   278,   279,
     280,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   101,   102,   103,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,    48,    49,     0,     0,     0,     0,    50,
       0,     0,     0,     0,     0,     0,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
      48,    49,     0,     0,     0,     0,    50,     0,     0,     0,
       0,     0,     0,    51,     0,     0,     0,     0,    53,     0,
       0,     0,     0,    52,    54,     0,     0,     0,     0,     0,
      36,    37,    55,     0,    40,    41,    42,     0,    44,     0,
      45,    46,    47,    48,    49,     0,     0,     0,     0,    50,
       0,    56,     0,     0,     0,    53,    51,     0,     0,     0,
       0,    54,     0,     0,     0,     0,    52,     0,     0,    55,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,    48,    49,     0,     0,   165,    56,    50,
       0,     0,     0,     0,     0,     0,    51,     0,    53,     0,
       0,     0,     0,     0,     0,     0,    52,     0,     0,     0,
       0,   168,    55,    36,    37,    38,    39,    40,    41,    42,
       0,    44,     0,    45,    46,    47,    48,    49,     0,     0,
       0,     0,    50,     0,     0,     0,     0,     0,    53,    51,
       0,     0,     0,     0,    54,     0,     0,     0,    36,    52,
      38,    39,    55,    41,    42,     0,    44,     0,    45,    46,
      47,    48,    49,     0,     0,     0,     0,    50,     0,     0,
       0,     0,     0,     0,   343,     0,     0,     0,     0,     0,
       0,    53,     0,     0,    52,     0,     0,     0,     0,    37,
       0,     0,    40,    41,    42,    55,    44,     0,    45,    46,
      47,    48,    49,     0,     0,     0,     0,    50,    37,     0,
       0,    40,   295,     0,    51,    44,    53,    45,    46,    47,
      48,    49,    54,     0,    52,     0,    50,     0,    37,     0,
      55,    40,    41,    51,     0,    44,     0,    45,    46,    47,
      48,    49,     0,    52,     0,     0,    50,     0,     0,     0,
       0,     0,   295,    51,     0,    44,    53,    45,    46,    47,
      48,    49,     0,    52,   165,     0,    50,     0,     0,     0,
      55,   295,     0,    51,    44,    53,    45,    46,    47,    48,
      49,     0,     0,    52,     0,    50,     0,     0,   168,    55,
       0,     0,    51,     0,     0,    53,     0,     0,     0,     0,
       0,     0,    52,   146,     0,     0,     0,     0,     0,    55,
       0,     0,     0,     0,     0,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
     435,     0,     0,     0,    53,     0,     0,     0,   290,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   147,   148,
       0,   105,   106,     0,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   504,     0,   104,   105,   106,     0,     0,     0,
     358,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   507,     0,     0,     0,     0,
       0,     0,     0,   358,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,     0,     0,   104,   105,   106,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   525,     0,   104,
     105,   106,     0,     0,     0,   358,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     539,     0,     0,     0,     0,     0,     0,     0,   358,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,     0,
       0,   104,   105,   106,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   553,     0,   104,   105,   106,     0,     0,     0,
     358,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   561,     0,     0,     0,     0,
       0,     0,     0,   358,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,    85,     0,   104,   105,   106,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   290,     0,   104,
     105,   106,     0,     0,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   358,     0,
     104,   105,   106,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   713,     0,   104,   105,   106,     0,     0,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,     0,     0,   104,   105,   106,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,     0,     0,   104,   105,   106
  };

  /* YYCHECK.  */
  const short int
  SPARQLalgebraParser::yycheck_[] =
  {
        41,    43,    75,    51,   159,    57,   344,    50,    51,    75,
     141,   327,   162,    13,    98,   331,    75,    51,    47,    22,
     228,    75,    75,    26,    75,   133,   106,    59,    75,    75,
      51,    47,    48,    49,    23,    75,    52,    75,    75,    47,
     128,     0,    85,    46,    75,    34,    78,   157,    98,   127,
      95,   259,   157,   158,   159,    20,   144,   165,   163,   164,
     162,   106,   112,    52,    21,   322,    55,   106,   325,    98,
      98,   128,   297,   281,   163,   164,   115,   106,   106,   163,
     164,    98,    39,   308,    98,    98,   696,    87,    77,   106,
     700,   107,   106,   134,    51,   157,   158,   159,   106,    56,
     157,   158,   159,    92,    93,    62,   149,    98,    38,    39,
     636,   637,    98,    98,   103,   106,   159,    98,   343,   108,
     106,   106,   165,    98,   140,   168,   142,   170,   157,   158,
     159,   106,   442,   443,   123,   124,   106,   447,   448,   106,
     450,   157,   106,    50,    51,    98,   106,   485,   464,   157,
     158,   159,   106,   106,   157,   158,   159,   473,   106,   116,
     106,   167,   119,   169,   480,   171,   172,   106,   174,   300,
      98,   177,   106,   130,   484,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   106,   201,   227,   106,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   106,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   437,   254,   255,   256,   257,   258,   106,   260,
     261,   262,   263,   106,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   175,
     176,   106,   285,   153,   154,   155,   156,   290,   264,   297,
     291,    14,   159,   106,   297,   593,    98,   330,    98,   569,
     308,   571,   572,   297,    98,   308,    98,    98,    98,   321,
      98,   344,    98,    98,   308,    98,   297,   320,   344,   322,
      98,   324,   325,   326,   327,   344,    98,   308,   331,   305,
     344,   344,   335,   344,   104,   343,    98,   344,   344,   449,
     343,   317,   209,    98,   344,   321,   344,   344,    98,   343,
     106,    98,   106,   344,   355,   358,    98,    98,   225,    98,
     106,   476,   343,   106,   634,    98,    98,   112,   369,    98,
     346,   372,   373,    98,    98,   376,    98,   378,    75,    98,
     565,    98,    98,   384,    81,    82,    83,    98,    98,    86,
     391,   392,   112,    98,   112,   396,    98,    94,    98,    98,
      98,   158,    98,   100,   112,   406,   591,    98,    98,   410,
      98,   412,    98,    98,   415,   416,    98,   112,   112,   420,
     421,    98,    98,    98,    98,    22,    23,   428,    98,   437,
     297,   112,   112,   434,   437,    98,    98,    34,    98,   442,
     443,   308,    98,   437,   447,   448,   112,   450,   112,    46,
      98,    98,   485,    98,    98,    52,   437,   112,    55,   485,
     112,   464,    98,   573,   106,    98,   485,    98,    98,    98,
     473,   485,   485,   476,   485,    98,   343,   480,   485,   485,
      77,   484,   106,    98,    98,   485,   353,   485,   485,    98,
     491,    98,    98,   494,   485,    92,    93,    98,   106,    98,
      98,   106,    98,    98,    98,    98,   103,    98,   509,   510,
      98,   108,    98,    98,     9,    10,    98,    98,    13,   520,
      15,    16,    17,    18,    19,    98,   123,   124,   529,    24,
     531,    98,    98,    98,    98,    98,    31,    98,    98,   540,
     541,    98,   162,   112,   112,   546,    41,    98,    98,   550,
      98,    98,    98,    98,    98,    98,    98,   565,   559,   560,
     593,    98,   565,    98,    98,    59,   569,   593,   571,   572,
     437,   565,    98,   106,   593,   106,    98,   157,    73,   593,
     593,    98,   593,   591,   565,    98,   593,   593,   591,    98,
      98,    98,    87,   593,    98,   593,   593,   591,    98,    98,
      66,    98,   593,    85,    58,    98,    59,    57,   435,   476,
     591,   644,   318,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,   106,    15,    16,    17,    18,    19,
     109,   634,    60,    57,    24,   350,   215,   291,   600,    58,
      61,    31,    59,   581,   176,   717,   335,   138,   607,   300,
     652,    41,   193,   654,   604,    -1,   657,    -1,    -1,    -1,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,    -1,    -1,
     162,   163,   164,    73,    -1,    -1,    -1,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,   565,    -1,
      -1,    -1,    -1,    -1,    -1,   706,   707,    -1,   709,    -1,
     713,    -1,    -1,    -1,   715,    25,   106,    27,    28,    29,
      30,    -1,    32,    33,   591,    35,    36,    37,    38,    -1,
      40,    -1,    42,    43,    44,    45,    -1,    -1,    -1,    49,
      50,    -1,    -1,    53,    54,    -1,    -1,    -1,    58,    -1,
      60,    61,    -1,    63,    64,    -1,    -1,    67,    68,    69,
      70,    71,    72,    -1,    74,    -1,    76,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    85,    -1,    -1,    88,    89,
      90,    91,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,
      -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,   109,
     110,   111,    -1,   113,   114,    -1,    -1,   117,   118,    -1,
     120,    -1,   122,    -1,    -1,    -1,   126,    -1,    -1,   129,
      -1,   131,   132,    -1,   134,   135,    -1,    -1,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,
      27,    28,    29,    30,    -1,    32,    33,   157,   158,   159,
      37,    38,    -1,    40,    -1,    42,    43,    44,    45,    -1,
      -1,    -1,    49,    50,    -1,    -1,    53,    54,    -1,    -1,
      -1,    58,    -1,    60,    61,    -1,    63,    64,    -1,    -1,
      67,    68,    69,    70,    71,    72,    -1,    74,    -1,    76,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    85,    -1,
      -1,    88,    89,    90,    91,    -1,    -1,    -1,    -1,    96,
      97,    -1,    99,    -1,   101,   102,    -1,   104,   105,    -1,
     107,    -1,   109,   110,   111,    -1,   113,   114,    -1,    -1,
     117,   118,    -1,   120,    -1,   122,    -1,    -1,    -1,   126,
      -1,    -1,   129,    -1,   131,   132,    -1,   134,   135,    -1,
      -1,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    -1,    27,    28,    29,    30,    -1,    32,    33,
     157,   158,   159,    37,    38,    -1,    40,    -1,    42,    43,
      44,    45,    -1,    -1,    -1,    49,    50,    -1,    -1,    53,
      54,    -1,    -1,    57,    58,    -1,    60,    61,    -1,    63,
      64,    -1,    -1,    67,    68,    69,    70,    71,    72,    -1,
      74,    -1,    76,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    85,    -1,    -1,    88,    89,    90,    91,    -1,    -1,
      -1,    -1,    96,    97,    -1,    99,    -1,   101,   102,    -1,
      -1,   105,    -1,   107,    -1,   109,   110,   111,    -1,   113,
     114,    -1,    -1,   117,   118,    -1,   120,    -1,   122,    -1,
      -1,    -1,   126,    -1,    -1,   129,    -1,   131,   132,    -1,
     134,   135,    -1,    -1,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    -1,    27,    28,    29,    30,
      -1,    32,    33,   157,   158,   159,    37,    38,    -1,    40,
      -1,    42,    43,    44,    45,    -1,    -1,    -1,    49,    50,
      -1,    -1,    53,    54,    -1,    -1,    -1,    58,    -1,    60,
      61,    -1,    63,    64,    -1,    -1,    67,    68,    69,    70,
      71,    72,    -1,    74,    -1,    76,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    84,    85,    -1,    -1,    88,    89,    90,
      91,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,    -1,
     101,   102,    -1,    -1,   105,    -1,   107,    -1,   109,   110,
     111,    -1,   113,   114,    -1,    -1,   117,   118,    -1,   120,
      -1,   122,    -1,    -1,    -1,   126,    -1,    -1,   129,    -1,
     131,   132,    -1,   134,   135,    -1,    -1,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    19,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    41,    79,    -1,    -1,    -1,    -1,    -1,
       5,     6,    87,    -1,     9,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    24,
      -1,   106,    -1,    -1,    -1,    73,    31,    -1,    -1,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    41,    -1,    -1,    87,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      15,    16,    17,    18,    19,    -1,    -1,    22,   106,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    46,    87,     5,     6,     7,     8,     9,    10,    11,
      -1,    13,    -1,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    73,    31,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,     5,    41,
       7,     8,    87,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    -1,    -1,    41,    -1,    -1,    -1,    -1,     6,
      -1,    -1,     9,    10,    11,    87,    13,    -1,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    24,     6,    -1,
      -1,     9,    10,    -1,    31,    13,    73,    15,    16,    17,
      18,    19,    79,    -1,    41,    -1,    24,    -1,     6,    -1,
      87,     9,    10,    31,    -1,    13,    -1,    15,    16,    17,
      18,    19,    -1,    41,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    10,    31,    -1,    13,    73,    15,    16,    17,
      18,    19,    -1,    41,    22,    -1,    24,    -1,    -1,    -1,
      87,    10,    -1,    31,    13,    73,    15,    16,    17,    18,
      19,    -1,    -1,    41,    -1,    24,    -1,    -1,    46,    87,
      -1,    -1,    31,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    95,    -1,    -1,    -1,    -1,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      98,    -1,    -1,    -1,    73,    -1,    -1,    -1,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,   163,   164,    -1,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,    98,    -1,   162,   163,   164,    -1,    -1,    -1,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,    -1,    -1,   162,   163,   164,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,    98,    -1,   162,
     163,   164,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,    -1,
      -1,   162,   163,   164,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,    98,    -1,   162,   163,   164,    -1,    -1,    -1,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   106,    -1,   162,   163,   164,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   106,    -1,   162,
     163,   164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   106,    -1,
     162,   163,   164,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   106,    -1,   162,   163,   164,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,    -1,    -1,   162,   163,   164,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,    -1,    -1,   162,   163,   164
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLalgebraParser::yystos_[] =
  {
         0,   106,   167,   168,   169,   170,   171,   173,   174,   175,
     176,   177,   178,   179,   180,   187,   195,   196,   197,   200,
     201,   206,   208,   209,   210,   211,   243,   245,   253,   255,
     257,   258,   259,   260,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    15,    16,    17,    18,    19,
      24,    31,    41,    73,    79,    87,   106,   172,   181,   182,
     189,   212,   213,   214,   216,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   232,   246,     0,   157,   106,   106,
     106,   106,   175,   175,   106,   106,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   162,   163,   164,   250,   276,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   291,   293,   294,   304,   305,   309,   310,   311,   312,
     313,   314,   315,   316,   106,   106,   196,   106,   244,   252,
     245,   245,   245,   275,   276,   315,    95,   160,   161,   274,
     276,   277,   305,   309,   313,   315,   317,   245,   127,   217,
     128,   144,   207,   273,    20,    22,    23,    34,    46,    52,
      55,    77,    92,    93,   103,   108,   123,   124,   106,   173,
     180,   232,   106,   170,   210,   106,   171,   211,   106,   179,
      98,   106,   213,   106,   187,   194,   195,   200,   201,   206,
     243,   248,   253,   255,   257,   258,   259,   260,   186,   188,
     190,    98,    98,   106,   192,   198,    25,    27,    28,    29,
      30,    32,    33,    37,    38,    40,    42,    43,    44,    45,
      49,    50,    53,    54,    58,    60,    61,    63,    64,    67,
      68,    69,    70,    71,    72,    74,    76,    80,    84,    85,
      88,    89,    90,    91,    96,    97,    99,   101,   102,   104,
     105,   107,   109,   110,   111,   113,   114,   117,   118,   120,
     122,   126,   129,   131,   132,   134,   135,   138,   139,   140,
     141,   315,   245,   106,   178,   133,   165,   306,   307,   308,
     106,   202,   203,   205,   278,    10,    98,    14,    98,   252,
     245,   106,   250,   254,   245,   256,    47,   106,   264,   265,
     266,   267,   268,   270,   271,   315,   245,   275,   207,    98,
     315,   227,   217,   315,   217,   315,   217,   217,   236,   238,
     240,   217,   237,   238,   237,   217,    98,    98,    98,    98,
      98,    98,    98,    31,   246,   245,   247,    98,   106,   183,
      98,   276,    98,   106,   191,   162,    98,   192,   106,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   276,   251,
     278,   278,   251,   278,   278,   278,   278,   278,   278,   278,
     278,   290,   278,    95,   106,   261,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
      98,   278,   278,   278,   278,   278,   251,   278,   278,   278,
     278,   245,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,    98,   251,    98,
      98,   315,    35,    36,   204,    98,   203,   274,   254,    98,
      98,   245,    21,    39,    51,    56,    62,   116,   119,   130,
     269,   274,    98,   245,   106,   174,   315,   106,   232,   245,
     234,   315,    98,   128,   233,   315,   215,   234,    22,    26,
      46,   234,   235,   233,    98,   106,   115,   239,   241,   243,
     233,    98,    98,   235,   274,   248,    98,   245,   184,   106,
     176,   276,   278,   106,   112,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,   278,    98,    98,   278,   112,
     112,   278,    98,   278,    98,    98,    98,   278,    98,    98,
     112,    98,    98,    98,   278,    98,   278,    98,    98,   112,
     278,   112,    98,    98,    98,    98,    98,    98,    98,    98,
     112,   112,    98,   278,    98,   278,   112,    98,   278,   278,
     112,    98,    98,    98,   278,   278,    98,    98,    98,   112,
     112,    98,   278,   106,   177,   274,    98,    98,   264,   264,
     264,   272,   264,   207,   264,    98,    98,    98,    98,   106,
     229,   230,   231,    98,   233,    98,    98,   233,   275,   233,
      98,   264,   248,   249,   158,    98,   278,    98,   106,   193,
     199,   278,    98,   278,   278,    98,    98,   263,   278,    98,
      98,   278,    98,   278,   278,   278,    98,    98,   278,    98,
      98,   278,    98,    98,   278,   278,    98,    98,   274,    98,
     264,    98,   264,   264,   207,    98,    59,    78,    98,   106,
     228,   231,    98,    98,   242,    98,   274,    98,   248,   185,
      98,   162,    98,   193,   112,   262,   292,   112,   292,    98,
     262,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,   264,   236,   236,   243,    98,   157,   106,
     295,   196,   278,    98,   278,    98,    98,    98,    98,    98,
      75,    81,    82,    83,    86,    94,   100,   296,   297,   300,
     301,   302,    98,    98,    98,    66,   298,   298,    98,   298,
      85,   278,   299,   106,   278,   303,   278,    57,   278,   314,
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
     415,   416,   417,   418,   419,   420
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  SPARQLalgebraParser::yyr1_[] =
  {
         0,   166,   167,   167,   168,   169,   169,   170,   170,   171,
     171,   171,   171,   172,   172,   173,   173,   174,   174,   175,
     175,   176,   176,   177,   177,   178,   178,   179,   179,   180,
     181,   182,   184,   185,   183,   186,   186,   187,   188,   188,
     189,   190,   190,   191,   192,   193,   194,   194,   194,   194,
     194,   195,   195,   196,   197,   198,   198,   199,   199,   200,
     201,   202,   202,   203,   203,   204,   204,   205,   206,   207,
     207,   208,   209,   209,   210,   210,   211,   212,   212,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     214,   215,   215,   216,   217,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   227,   228,   228,   229,
     229,   230,   231,   232,   232,   233,   233,   234,   235,   235,
     235,   235,   236,   237,   238,   239,   239,   240,   240,   242,
     241,   243,   243,   244,   244,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   246,   246,   247,   247,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   249,   249,
     250,   251,   251,   252,   253,   253,   254,   254,   256,   255,
     257,   258,   259,   260,   261,   261,   262,   263,   263,   264,
     264,   264,   264,   264,   264,   265,   266,   267,   268,   268,
     269,   269,   269,   270,   270,   271,   272,   272,   273,   274,
     274,   275,   275,   276,   276,   277,   277,   277,   277,   277,
     277,   278,   278,   278,   278,   278,   278,   279,   280,   281,
     282,   282,   283,   283,   283,   283,   283,   283,   283,   284,
     285,   285,   286,   286,   287,   287,   287,   288,   288,   288,
     288,   288,   288,   288,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   290,   290,   291,   292,   292,   293,
     294,   295,   296,   296,   296,   297,   298,   298,   299,   299,
     300,   301,   301,   301,   301,   301,   302,   302,   303,   304,
     304,   305,   306,   307,   307,   308,   308,   309,   309,   309,
     310,   310,   310,   311,   311,   311,   312,   312,   312,   313,
     313,   314,   314,   314,   314,   315,   315,   316,   316,   317,
     317
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
       4,     4,     4,     6,     6,     6,     6,     6,     4,     4,
       4,     4,     4,     4,     4,     4,     3,     4,     4,     4,
       4,     4,     4,     8,     6,     6,     6,     4,     4,     4,
       4,     4,     1,     1,     0,     1,     7,     0,     1,     7,
       4,     3,     1,     1,     1,     3,     0,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     3,     4,     4,     1,
       4,     2,     2,     1,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
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
  "IT_encode_for_uri", "IT_GROUP_CONCAT", "IT_tz", "IT_timezone",
  "IT_copy", "IT_exprlist", "IT_strdt", "GT_LPAREN", "IT_strends",
  "IT_deletedata", "IT_month", "GT_OR", "IT_exists", "GT_COMMA", "GT_LE",
  "IT_sameterm", "IT_quads", "IT_notoneof", "IT_year", "GT_EQUAL",
  "IT_seq", "GT_LT", "GT_LCURLEY", "IT_langmatches", "IT_insertdata",
  "IT_clear", "GT_DOT", "IT_isiri", "IT_silent", "IT__", "IT_datatype",
  "IT_mod", "GT_MINUS", "GT_DIVIDE", "GT_DTYPE", "IT_lang", "IT_sha1",
  "IT_uuid", "IT_struuid", "IT_md5", "IT_strbefore", "IT_strafter",
  "IT_rand", "IT_true", "IT_false", "INTEGER", "DECIMAL", "DOUBLE",
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
       167,     0,    -1,   168,    -1,   208,    -1,   169,    -1,   106,
     181,   170,    98,    -1,   170,    -1,   106,   182,   171,    98,
      -1,   171,    -1,   106,   172,   173,    98,    -1,   106,   172,
     180,    98,    -1,   180,    -1,   173,    -1,   232,    -1,   172,
     232,    -1,   206,    -1,   174,    -1,   195,    -1,   175,    -1,
     187,    -1,   176,    -1,   201,    -1,   177,    -1,   200,    -1,
     178,    -1,   106,   189,   179,    98,    -1,   179,    -1,   197,
      -1,   196,    -1,   106,    12,   196,    98,    -1,     3,   157,
      -1,     4,   106,   186,    98,    -1,    -1,    -1,   106,   184,
     158,   185,   157,    98,    -1,    -1,   186,   183,    -1,   106,
       5,   106,   188,    98,   176,    98,    -1,    -1,   188,   276,
      -1,     6,   106,   190,    98,    -1,    -1,   190,   191,    -1,
     106,   276,   278,    98,    -1,   106,   162,   278,    98,    -1,
     106,   162,   295,    98,    -1,   206,    -1,   195,    -1,   187,
      -1,   201,    -1,   200,    -1,   106,     7,   175,    98,    -1,
     106,     8,   175,    98,    -1,   245,    -1,   106,     9,   106,
     198,    98,   106,   199,    98,   196,    98,    -1,   192,    -1,
     198,   192,    -1,   193,    -1,   199,   193,    -1,   106,    10,
     278,   178,    98,    -1,   106,    11,   106,   202,    98,   177,
      98,    -1,   203,    -1,   202,   203,    -1,   205,    -1,   278,
      -1,    35,    -1,    36,    -1,   106,   204,   278,    98,    -1,
     106,    79,   207,   207,   174,    98,    -1,   273,    -1,   128,
      -1,   209,    -1,   106,   181,   210,    98,    -1,   210,    -1,
     106,   182,   211,    98,    -1,   211,    -1,   106,   212,    98,
      -1,   213,    -1,   212,   213,    -1,   214,    -1,   216,    -1,
     218,    -1,   220,    -1,   221,    -1,   222,    -1,   219,    -1,
     223,    -1,   224,    -1,   225,    -1,   226,    -1,   106,    55,
     315,   215,    98,    -1,    -1,   234,    -1,   106,   124,   217,
     235,    98,    -1,    -1,   127,    -1,   106,    77,   217,   235,
      98,    -1,   106,    34,   217,   234,    98,    -1,   106,    52,
     217,   233,   233,    98,    -1,   106,    92,   217,   233,   233,
      98,    -1,   106,   103,   217,   233,   233,    98,    -1,   106,
     123,   237,    98,    -1,   106,   108,   237,    98,    -1,   106,
      93,   236,    98,    -1,   106,    23,   227,   245,   229,    98,
      -1,    -1,   227,   232,    -1,    -1,   231,    -1,   230,   228,
      -1,   231,    -1,   106,    78,   236,    98,    -1,   106,    59,
     236,    98,    -1,   106,    46,   315,    98,    -1,   106,    22,
     315,   315,    98,    -1,   128,    -1,   315,    -1,   315,    -1,
     234,    -1,    46,    -1,    22,    -1,    26,    -1,   238,    -1,
     238,    -1,   240,    -1,   241,    -1,   243,    -1,    -1,   240,
     239,    -1,    -1,   115,   275,   242,   243,    -1,   106,    13,
     244,    98,    -1,   106,    87,    20,    98,    -1,   252,    -1,
     244,   252,    -1,   243,    -1,   260,    -1,   106,   246,   248,
     247,    98,    -1,   253,    -1,   255,    -1,   257,    -1,   258,
      -1,   259,    -1,   106,    31,   274,   264,   274,    98,    -1,
      15,    -1,    16,    -1,   245,    -1,   247,   245,    -1,   243,
      -1,   260,    -1,   106,   246,   248,   249,    98,    -1,   253,
      -1,   255,    -1,   257,    -1,   258,    -1,   259,    -1,   106,
      31,   274,   264,   274,    98,    -1,   194,    -1,   248,    -1,
     249,   248,    -1,   106,   104,   251,    98,    -1,   278,    -1,
     251,   278,    -1,   106,    14,   274,   274,   274,    98,    -1,
     106,    17,   245,   245,   254,    98,    -1,   106,    18,   245,
     254,    98,    -1,    -1,   250,    -1,    -1,   106,    24,   275,
     256,   245,    98,    -1,   106,    73,   217,   275,   245,    98,
      -1,   106,    41,   245,   245,    98,    -1,   106,    19,   245,
     245,    98,    -1,   106,    10,   250,   245,    98,    -1,    95,
      -1,   106,   278,   263,    98,    -1,   112,   278,    -1,    -1,
     263,   262,    -1,   265,    -1,   266,    -1,   267,    -1,   268,
      -1,   271,    -1,   270,    -1,   106,    39,   264,   264,    98,
      -1,   106,   119,   264,   264,    98,    -1,   106,    21,   264,
      98,    -1,   106,   269,   264,    98,    -1,   106,   130,   207,
     207,   264,    98,    -1,    62,    -1,    56,    -1,    51,    -1,
     315,    -1,    47,    -1,   106,   116,   272,    98,    -1,   264,
      -1,   272,   264,    -1,   144,    -1,   276,    -1,   277,    -1,
     276,    -1,   315,    -1,   163,    -1,   164,    -1,   315,    -1,
     305,    -1,   309,    -1,   313,    -1,   317,    -1,    95,    -1,
     279,    -1,   280,    -1,   281,    -1,   286,    -1,   287,    -1,
     288,    -1,   106,   110,   278,   278,    98,    -1,   106,    45,
     278,   278,    98,    -1,   282,    -1,   284,    -1,   283,    -1,
     106,   118,   278,   278,    98,    -1,   106,    72,   278,   278,
      98,    -1,   106,   120,   278,   278,    98,    -1,   106,    58,
     278,   278,    98,    -1,   106,   113,   278,   278,    98,    -1,
     106,    53,   278,   278,    98,    -1,   106,    42,   251,    98,
      -1,   285,    -1,   106,    74,   278,   278,    98,    -1,   106,
     131,   278,   278,    98,    -1,   106,    85,   278,   278,    98,
      -1,   106,   132,   278,   278,    98,    -1,   106,    69,   278,
      98,    -1,   106,    74,   278,    98,    -1,   106,   131,   278,
      98,    -1,   289,    -1,   304,    -1,   305,    -1,   309,    -1,
     313,    -1,   276,    -1,   162,    -1,   106,    33,   278,    98,
      -1,   106,   134,   278,    98,    -1,   106,   122,   278,   112,
     278,    98,    -1,   106,   129,   278,    98,    -1,   106,    40,
     276,    98,    -1,   106,    89,   278,    98,    -1,   106,    71,
     278,    98,    -1,   106,    61,   290,    98,    -1,   106,   141,
      98,    -1,   106,    63,   278,    98,    -1,   106,    54,   278,
      98,    -1,   106,    37,   278,    98,    -1,   106,    30,   278,
      98,    -1,   106,    44,   251,    98,    -1,   293,    -1,   106,
      67,   278,    98,    -1,   106,    28,   278,    98,    -1,   106,
      27,   278,    98,    -1,   106,    99,   278,    98,    -1,   106,
      68,   278,   112,   278,    98,    -1,   106,    88,   278,   112,
     278,    98,    -1,   106,   107,   278,   112,   278,    98,    -1,
     106,   139,   278,   112,   278,    98,    -1,   106,   140,   278,
     112,   278,    98,    -1,   106,   117,   278,    98,    -1,   106,
     109,   278,    98,    -1,   106,    96,   278,    98,    -1,   106,
      43,   278,    98,    -1,   106,    38,   278,    98,    -1,   106,
      32,   278,    98,    -1,   106,   102,   278,    98,    -1,   106,
     101,   278,    98,    -1,   106,    91,    98,    -1,   106,   138,
     278,    98,    -1,   106,   135,   278,    98,    -1,   106,    29,
     278,    98,    -1,   106,    90,   278,    98,    -1,   106,    80,
     278,    98,    -1,   106,    64,   261,    98,    -1,   106,    49,
     278,   112,   278,   112,   278,    98,    -1,   106,    84,   278,
     112,   278,    98,    -1,   106,   105,   278,   112,   278,    98,
      -1,   106,   114,   278,   112,   278,    98,    -1,   106,   126,
     278,    98,    -1,   106,    97,   278,    98,    -1,   106,    76,
     278,    98,    -1,   106,    70,   278,    98,    -1,   106,    60,
     278,    98,    -1,   291,    -1,   294,    -1,    -1,   278,    -1,
     106,    50,   278,   112,   278,   292,    98,    -1,    -1,   262,
      -1,   106,    25,   278,   112,   278,   292,    98,    -1,   106,
     111,   245,    98,    -1,   106,   296,    98,    -1,   297,    -1,
     300,    -1,   302,    -1,    83,   298,   299,    -1,    -1,    66,
      -1,    85,    -1,   278,    -1,   301,   298,   278,    -1,    82,
      -1,    75,    -1,    81,    -1,    86,    -1,    94,    -1,   100,
     298,   278,    -1,   100,   298,   303,   278,    -1,   106,    57,
     314,    98,    -1,   315,    -1,   106,   315,   251,    98,    -1,
     314,   308,    -1,   133,   315,    -1,   165,    -1,   306,    -1,
      -1,   307,    -1,   310,    -1,   311,    -1,   312,    -1,   144,
      -1,   145,    -1,   146,    -1,   147,    -1,   148,    -1,   149,
      -1,   150,    -1,   151,    -1,   152,    -1,   142,    -1,   143,
      -1,   153,    -1,   155,    -1,   154,    -1,   156,    -1,   157,
      -1,   316,    -1,   159,    -1,   158,    -1,   160,    -1,   161,
      -1
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
     864,   869,   874,   879,   886,   893,   900,   907,   914,   919,
     924,   929,   934,   939,   944,   949,   954,   958,   963,   968,
     973,   978,   983,   988,   997,  1004,  1011,  1018,  1023,  1028,
    1033,  1038,  1043,  1045,  1047,  1048,  1050,  1058,  1059,  1061,
    1069,  1074,  1078,  1080,  1082,  1084,  1088,  1089,  1091,  1093,
    1095,  1099,  1101,  1103,  1105,  1107,  1109,  1113,  1118,  1123,
    1125,  1130,  1133,  1136,  1138,  1140,  1141,  1143,  1145,  1147,
    1149,  1151,  1153,  1155,  1157,  1159,  1161,  1163,  1165,  1167,
    1169,  1171,  1173,  1175,  1177,  1179,  1181,  1183,  1185,  1187,
    1189
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
    1588,  1591,  1594,  1598,  1601,  1604,  1607,  1610,  1613,  1616,
    1619,  1622,  1625,  1626,  1630,  1633,  1639,  1645,  1648,  1652,
    1658,  1670,  1674,  1675,  1676,  1680,  1686,  1689,  1695,  1698,
    1702,  1708,  1711,  1714,  1717,  1720,  1726,  1729,  1735,  1739,
    1742,  1748,  1755,  1761,  1765,  1772,  1776,  1780,  1781,  1782,
    1786,  1787,  1788,  1792,  1793,  1794,  1798,  1799,  1800,  1804,
    1805,  1809,  1810,  1811,  1812,  1816,  1817,  1821,  1822,  1826,
    1827
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
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SPARQLalgebraParser::yyeof_ = 0;
  const int SPARQLalgebraParser::yylast_ = 1989;
  const int SPARQLalgebraParser::yynnts_ = 152;
  const int SPARQLalgebraParser::yyempty_ = -2;
  const int SPARQLalgebraParser::yyfinal_ = 76;
  const int SPARQLalgebraParser::yyterror_ = 1;
  const int SPARQLalgebraParser::yyerrcode_ = 256;
  const int SPARQLalgebraParser::yyntokens_ = 166;

  const unsigned int SPARQLalgebraParser::yyuser_token_number_max_ = 420;
  const SPARQLalgebraParser::token_number_type SPARQLalgebraParser::yyundef_token_ = 2;


} // w3c_sw

/* Line 1136 of lalr1.cc  */
#line 4013 "lib/SPARQLalgebraParser/SPARQLalgebraParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 1832 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
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
    // clear prefixes for nth run but keep them around for e.g. serialization.
    clearPrefixes();

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


