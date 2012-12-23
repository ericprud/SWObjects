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
#line 260 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"

#include "../SPARQLalgebraScanner.hpp"

/* Line 299 of lalr1.cc  */
#line 318 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"

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
    driver.yylloc = &yylloc;
}

/* Line 565 of lalr1.cc  */
#line 348 "lib/SPARQLalgebraParser/SPARQLalgebraParser.cpp"

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
#line 335 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 338 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 348 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(4) - (3)].p_Operation);
    }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 355 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(4) - (3)].p_Operation);
    }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 362 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Select((yysemantic_stack_[(4) - (3)].p_protoSelect).distinctness, (yysemantic_stack_[(4) - (3)].p_protoSelect).varSet, (yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_protoSelect).p_WhereClause, (yysemantic_stack_[(4) - (3)].p_protoSelect).p_SolutionModifier);
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 365 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(4) - (2)].p_DatasetClauses), new WhereClause((yysemantic_stack_[(4) - (3)].p_op)), NULL); // !! add SliceOpt?
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 368 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Ask(new ProductionVector<const DatasetClause*>(), new WhereClause((yysemantic_stack_[(1) - (1)].p_op)), NULL); // !! add SliceOpt?
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 371 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Select((yysemantic_stack_[(1) - (1)].p_protoSelect).distinctness, (yysemantic_stack_[(1) - (1)].p_protoSelect).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(1) - (1)].p_protoSelect).p_WhereClause, (yysemantic_stack_[(1) - (1)].p_protoSelect).p_SolutionModifier);
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 377 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>((yysemantic_stack_[(1) - (1)].p_DatasetClause));
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 380 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 388 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(1) - (1)].p_protoSelect);
	(yyval.p_protoSelect).p_SolutionModifier = new SolutionModifier(NULL, NULL, NULL, -1, -1);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 396 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(1) - (1)].p_protoSelect);
	(yyval.p_protoSelect).distinctness = DIST_all;
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 404 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(1) - (1)].p_protoSelect);
	(yyval.p_protoSelect).varSet = new StarVarSet();
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 412 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(1) - (1)].p_protoSelect);
	(yyval.p_protoSelect).p_OrderConditions = NULL;
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 420 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(1) - (1)].p_protoSelect);
	(yyval.p_protoSelect).p_having = NULL;
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 427 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	throw std::string("ExtendOpt: not ready to parse aggregates");
	(yyval.p_protoSelect) = (yysemantic_stack_[(4) - (3)].p_protoSelect);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 431 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(1) - (1)].p_protoSelect);
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 438 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect).p_WhereClause = new WhereClause((yysemantic_stack_[(1) - (1)].p_op));
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 446 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = (yysemantic_stack_[(4) - (3)].p_op);
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 452 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 462 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 464 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 466 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(6) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(6) - (5)].p_URI));
      }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 478 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(7) - (6)].p_protoSelect);
	(yyval.p_protoSelect).varSet = (yysemantic_stack_[(7) - (4)].p_ExpressionAliaseList);
    }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 485 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList();
    }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 488 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_Variable))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 495 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	throw std::string("Extend: not ready to parse aggregates");
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 528 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(4) - (3)].p_protoSelect);
	(yyval.p_protoSelect).distinctness = DIST_distinct;
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 532 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(4) - (3)].p_protoSelect);
	(yyval.p_protoSelect).distinctness = DIST_reduced;
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 568 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	throw std::string("GroupClause: not ready to parse aggregates");
	(yyval.p_protoSelect).p_WhereClause = new WhereClause((yysemantic_stack_[(10) - (9)].p_op));
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 587 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(5) - (4)].p_protoSelect);
	(yyval.p_protoSelect).p_having = new w3c_sw::ProductionVector<const w3c_sw::Expression*>((yysemantic_stack_[(5) - (3)].p_Expression)); // !!!
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 596 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(7) - (6)].p_protoSelect);
	(yyval.p_protoSelect).p_OrderConditions = (yysemantic_stack_[(7) - (4)].p_OrderConditions);
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 603 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 607 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 615 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 622 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 626 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 632 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(4) - (2)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(4) - (3)].p_Expression);
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 639 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_protoSelect) = (yysemantic_stack_[(6) - (5)].p_protoSelect); // ($5.p_group, ...)
	(yyval.p_protoSelect).p_SolutionModifier = new SolutionModifier(NULL, (yysemantic_stack_[(6) - (5)].p_protoSelect).p_having, (yysemantic_stack_[(6) - (5)].p_protoSelect).p_OrderConditions, (yysemantic_stack_[(6) - (3)].p_int), (yysemantic_stack_[(6) - (4)].p_int)); // !!!
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 646 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_int) = ((IntegerRDFLiteral*)(yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 649 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_int) = LIMIT_None;
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 673 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(4) - (3)].p_Operation);
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 680 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(4) - (3)].p_Operation);
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 687 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(3) - (2)]. p_OperationSet);
}
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 693 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	OperationSet* ret = new OperationSet();
	ret->push_back((yysemantic_stack_[(1) - (1)].p_Operation));
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 697 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)]. p_OperationSet)->push_back((yysemantic_stack_[(2) - (2)].p_Operation));
	(yyval. p_OperationSet) = (yysemantic_stack_[(2) - (1)]. p_OperationSet);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 720 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(6) - (3)].p_Silence), (yysemantic_stack_[(6) - (4)].p_URI), (yysemantic_stack_[(6) - (5)].p_URI));
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 726 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 735 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(5) - (3)].p_Silence), (yysemantic_stack_[(5) - (4)].p_URI));
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 741 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 744 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
    }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 752 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(5) - (3)].p_Silence), (yysemantic_stack_[(5) - (4)].p_URI));
    }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 760 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(5) - (3)].p_Silence), (yysemantic_stack_[(5) - (4)].p_URI));
    }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 768 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(6) - (3)].p_Silence), (yysemantic_stack_[(6) - (4)].p_URI), (yysemantic_stack_[(6) - (5)].p_URI));
    }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 776 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(6) - (3)].p_Silence), (yysemantic_stack_[(6) - (4)].p_URI), (yysemantic_stack_[(6) - (5)].p_URI));
    }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 784 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(6) - (3)].p_Silence), (yysemantic_stack_[(6) - (4)].p_URI), (yysemantic_stack_[(6) - (5)].p_URI));
    }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 792 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Insert((yysemantic_stack_[(4) - (3)].p_op), NULL);
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 800 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Delete(false, (yysemantic_stack_[(4) - (3)].p_op), NULL);
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 808 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Delete(true, (yysemantic_stack_[(4) - (3)].p_op), NULL);
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 816 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(6) - (5)].p_DeleteInsert).del, (yysemantic_stack_[(6) - (5)].p_DeleteInsert).ins, new WhereClause((yysemantic_stack_[(6) - (4)].p_op)), NULL, NULL, NULL); // !! synch with SPARQLfedParser
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 822 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 825 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 832 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 839 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 843 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 852 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Delete) = new Delete(true, (yysemantic_stack_[(4) - (3)].p_op), NULL);
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 860 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Insert) = new Insert((yysemantic_stack_[(4) - (3)].p_op), NULL);
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 868 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(4) - (3)].p_URI), driver.atomFactory);
    }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 871 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(5) - (3)].p_URI), driver.atomFactory);
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 879 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 895 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	w3c_sw_NEED_IMPL("DEFAULT");
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 898 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	w3c_sw_NEED_IMPL("NAMED");
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 901 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	w3c_sw_NEED_IMPL("ALL");
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 917 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = (yysemantic_stack_[(1) - (1)].p_conj);
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 928 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_conj) = new ParserTableConjunction();
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 931 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_conj)->addTableOperation((yysemantic_stack_[(2) - (2)].p_op), false);
	(yyval.p_conj) = (yysemantic_stack_[(2) - (1)].p_conj);
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 938 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = driver.curGraphName;
	driver.curGraphName = (yysemantic_stack_[(2) - (2)].p_TTerm);
      }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 941 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	  (yyval.p_op) = (yysemantic_stack_[(4) - (4)].p_op);
	  driver.curGraphName = (yysemantic_stack_[(4) - (3)].p_TTerm);
      }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 948 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = (yysemantic_stack_[(4) - (3)].p_BasicGraphPattern);
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 951 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = driver.ensureGraphPattern();
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 957 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_BasicGraphPattern) = driver.ensureGraphPattern();
	(yyval.p_BasicGraphPattern)->addTriplePattern((yysemantic_stack_[(1) - (1)].p_TriplePattern), true);
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 961 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
      (yysemantic_stack_[(2) - (1)].p_BasicGraphPattern)->addTriplePattern((yysemantic_stack_[(2) - (2)].p_TriplePattern), true);
	(yyval.p_BasicGraphPattern) = (yysemantic_stack_[(2) - (1)].p_BasicGraphPattern);
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 970 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(5) - (4)].p_conj)->insertTableOperation((yysemantic_stack_[(5) - (3)].p_op));
	(yyval.p_op) = (yysemantic_stack_[(5) - (4)].p_conj);
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 979 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	throw new std::string("GroupGraphPatternNoSub: GT_LPAREN IT_path VarOrTerm Path VarOrTerm GT_RPAREN not implemented");
	(yyval.p_op) = driver.ensureGraphPattern();
    }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 991 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_conj) = new ParserTableConjunction();
	(yyval.p_conj)->addTableOperation((yysemantic_stack_[(1) - (1)].p_op), driver.unnestTree);
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 995 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_conj)->addTableOperation((yysemantic_stack_[(2) - (2)].p_op), driver.unnestTree);
	(yyval.p_conj) = (yysemantic_stack_[(2) - (1)].p_conj);
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1004 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(5) - (4)].p_conj)->addTableOperation((yysemantic_stack_[(5) - (3)].p_op), driver.unnestTree);
	(yyval.p_op) = (yysemantic_stack_[(5) - (4)].p_conj);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1013 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	throw new std::string("GroupGraphPatternSub: GT_LPAREN IT_path VarOrTerm Path VarOrTerm GT_RPAREN not implemented");
	(yyval.p_op) = driver.ensureGraphPattern();
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1017 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = new SubSelect(new Select((yysemantic_stack_[(1) - (1)].p_protoSelect).distinctness, (yysemantic_stack_[(1) - (1)].p_protoSelect).varSet, NULL, (yysemantic_stack_[(1) - (1)].p_protoSelect).p_WhereClause, (yysemantic_stack_[(1) - (1)].p_protoSelect).p_SolutionModifier));
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1023 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_conj) = new ParserTableConjunction();
	(yyval.p_conj)->addTableOperation((yysemantic_stack_[(1) - (1)].p_op), driver.unnestTree);
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1027 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_conj)->addTableOperation((yysemantic_stack_[(2) - (2)].p_op), driver.unnestTree);
	(yyval.p_conj) = (yysemantic_stack_[(2) - (1)].p_conj);
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1034 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(4) - (3)].p_Expressions);
    }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1040 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1043 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1050 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TriplePattern) = driver.atomFactory->getTriple((yysemantic_stack_[(6) - (3)].p_TTerm), (yysemantic_stack_[(6) - (4)].p_TTerm), (yysemantic_stack_[(6) - (5)].p_TTerm));
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1064 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
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
#line 1078 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
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
#line 1092 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1099 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = driver.curGraphName;
	driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1102 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	  (yyval.p_op) = (yysemantic_stack_[(6) - (5)].p_op);
	  driver.curGraphName = (yysemantic_stack_[(6) - (4)].p_TTerm);
      }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1109 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = new ServiceGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), (yysemantic_stack_[(6) - (5)].p_op), (yysemantic_stack_[(6) - (3)].p_Silence), driver.atomFactory, false);
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1117 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	TableConjunction* ret = new TableConjunction();
	ret->addTableOperation((yysemantic_stack_[(5) - (3)].p_op), driver.unnestTree);
	ret->addTableOperation(new MinusGraphPattern((yysemantic_stack_[(5) - (4)].p_op)), driver.unnestTree);
	(yyval.p_op) = ret;
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1126 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	TableDisjunction* ret = new TableDisjunction();
	ret->addTableOperation((yysemantic_stack_[(5) - (3)].p_op), driver.unnestTree);
	ret->addTableOperation((yysemantic_stack_[(5) - (4)].p_op), driver.unnestTree);
	(yyval.p_op) = ret;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1135 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_op) = new Filter((yysemantic_stack_[(5) - (4)].p_op), (yysemantic_stack_[(5) - (3)].p_Expressions)->begin(), (yysemantic_stack_[(5) - (3)].p_Expressions)->end());
	(yysemantic_stack_[(5) - (3)].p_Expressions)->clear();
	delete (yysemantic_stack_[(5) - (3)].p_Expressions);
    }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1151 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1154 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(4) - (3)].p_Expressions)->push_front((yysemantic_stack_[(4) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(4) - (3)].p_Expressions);
    }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1161 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1167 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1170 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1227 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	// $$ = new PathAlternative($3, $4);
    }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1233 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	// $$ = new PathSequence($3, $4);
    }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1241 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	// $$ = new PathEltOrInverse($3);
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1247 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	// $$ = $3;
    }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1250 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	// $$ = $5;
      }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1262 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1265 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1273 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(4) - (3)].p_TTerm);
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1280 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	// $1->push_back($2);
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (1)].p_TTerm);
    }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1287 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_NumericRDFLiteral) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1304 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1311 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1314 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1325 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1329 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1332 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1336 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil");
    }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 1351 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yysemantic_stack_[(5) - (3)].p_Expression));
	t->push_back((yysemantic_stack_[(5) - (4)].p_Expression));
	(yyval.p_Expression) = new BooleanDisjunction(t);
    }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 1360 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yysemantic_stack_[(5) - (3)].p_Expression));
	t->push_back((yysemantic_stack_[(5) - (4)].p_Expression));
	(yyval.p_Expression) = new BooleanConjunction(t);
    }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1378 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanEQ((yysemantic_stack_[(5) - (3)].p_Expression), (yysemantic_stack_[(5) - (4)].p_Expression));
    }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 1381 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNE((yysemantic_stack_[(5) - (3)].p_Expression), (yysemantic_stack_[(5) - (4)].p_Expression));
    }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 1384 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanLT((yysemantic_stack_[(5) - (3)].p_Expression), (yysemantic_stack_[(5) - (4)].p_Expression));
    }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 1387 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanGT((yysemantic_stack_[(5) - (3)].p_Expression), (yysemantic_stack_[(5) - (4)].p_Expression));
    }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 1390 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanLE((yysemantic_stack_[(5) - (3)].p_Expression), (yysemantic_stack_[(5) - (4)].p_Expression));
    }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 1393 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanGE((yysemantic_stack_[(5) - (3)].p_Expression), (yysemantic_stack_[(5) - (4)].p_Expression));
    }
    break;

  case 228:

/* Line 690 of lalr1.cc  */
#line 1396 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new NaryIn((yysemantic_stack_[(4) - (3)].p_Expressions));
    }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 1408 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yysemantic_stack_[(5) - (3)].p_Expression));
	t->push_back((yysemantic_stack_[(5) - (4)].p_Expression));
	(yyval.p_Expression) = new ArithmeticSum(t);
    }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 1414 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yysemantic_stack_[(5) - (3)].p_Expression));
	t->push_back(new ArithmeticNegation((yysemantic_stack_[(5) - (4)].p_Expression)));
	(yyval.p_Expression) = new ArithmeticSum(t);
    }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 1428 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yysemantic_stack_[(5) - (3)].p_Expression));
	t->push_back(new ArithmeticNegation((yysemantic_stack_[(5) - (4)].p_Expression)));
	(yyval.p_Expression) = new ArithmeticProduct(t);
    }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 1434 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	ProductionVector<const Expression*>* t = new ProductionVector<const Expression*>();
	t->push_back((yysemantic_stack_[(5) - (3)].p_Expression));
	t->push_back(new ArithmeticInverse((yysemantic_stack_[(5) - (4)].p_Expression)));
	(yyval.p_Expression) = new ArithmeticProduct(t);
    }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 1443 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(4) - (3)].p_Expression));
    }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 1446 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(4) - (3)].p_Expression);
    }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 1449 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(4) - (3)].p_Expression));
    }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 1457 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 1460 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 1463 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 1466 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 1469 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 1480 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 1483 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 1486 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 1489 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 1492 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 1495 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 250:

/* Line 690 of lalr1.cc  */
#line 1498 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 251:

/* Line 690 of lalr1.cc  */
#line 1501 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 1504 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 1507 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 1510 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ceil, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 1513 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 1516 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 1519 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(4) - (3)].p_Expressions))));
    }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 1523 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 1526 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 1529 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 1532 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 1535 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 1538 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 1541 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 1544 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 1547 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 1550 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 1553 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 1556 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 1559 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 1562 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 1565 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 1568 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 1571 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 1574 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 1577 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 1580 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 1583 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 1586 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 1589 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 1592 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 1596 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 1599 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 1602 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 1605 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 1608 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 1611 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 1614 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 1617 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 1620 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 1628 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 1637 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 1643 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 1650 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 1656 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.ensureGraphPattern(), NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 1678 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
 	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(3) - (2)].p_distinctness), (yysemantic_stack_[(3) - (3)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 1684 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 1687 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
}
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 1693 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 1700 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(3) - (1)].p_URI), (yysemantic_stack_[(3) - (2)].p_distinctness), (yysemantic_stack_[(3) - (3)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 1706 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 1709 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 1712 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 1715 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 1718 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 1724 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(3) - (2)].p_distinctness), (yysemantic_stack_[(3) - (3)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 1727 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
      (yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(4) - (2)].p_distinctness), (yysemantic_stack_[(4) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 1737 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 1740 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(4) - (2)].p_URI), new ArgList((yysemantic_stack_[(4) - (3)].p_Expressions))));
    }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 1746 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_TTerm) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 1753 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 1759 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 1763 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 1770 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 690 of lalr1.cc  */
#line 2524 "lib/SPARQLalgebraParser/SPARQLalgebraParser.cpp"
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
  const short int SPARQLalgebraParser::yypact_ninf_ = -648;
  const short int
  SPARQLalgebraParser::yypact_[] =
  {
       -29,   591,    52,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -102,   -26,   -12,    -6,    15,    15,
      22,  1764,    31,    42,    45,  -648,  -648,    42,    42,    42,
     154,  1455,    42,   -61,   -83,   116,  1187,    50,    56,    57,
      61,   -35,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,    63,  -648,  -648,  -648,  -648,
    -648,  1385,    40,    60,    66,   786,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,    42,  -648,    68,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,   -93,  -648,  -648,  1787,  1508,    87,   170,   -19,  -648,
      42,    81,    42,  -648,  -648,  -648,  -648,  -648,  -648,   -24,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,    42,  -648,   154,
    -648,  -648,   -83,  -648,    99,   109,  -648,   -61,   109,   -61,
     -61,   -61,   -61,  -648,   -61,  -648,  -648,   -61,   631,   114,
     125,  -648,  1188,   141,   142,  1241,   157,   158,    86,   160,
    -648,   293,  -648,  1351,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,    42,  -648,  -648,  -648,  -648,  -648,  -648,   -15,   -55,
      -9,  -648,  -648,   100,  -648,    -8,  1818,  1818,  1818,  1818,
    1818,  1818,  1818,  1818,  1818,  -105,  1818,  1818,  1818,  1818,
    1818,  1818,  1818,  1818,  1818,  1818,  1818,  1818,   -46,  1818,
    1818,  1818,  1818,  1818,  1818,  1818,  1818,  1818,  1818,  1818,
    1818,  1818,  1818,   163,  1818,  1818,  1818,  1818,  1818,  1818,
    1818,  1818,  1818,  1818,    42,  1818,  1818,  1818,  1818,  1818,
    1818,  1818,  1818,  1818,  1818,  1818,  1818,  1818,  1818,  1818,
     166,  1818,   171,  1433,   172,   109,  -648,  -648,  -648,  -648,
     663,  1478,  -648,  -648,  -648,    81,  -648,  1455,  -648,  -648,
      81,   168,  -648,   177,   178,    42,  -648,    30,  1455,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,   180,    42,   188,  -648,
     109,   193,   109,   203,   -84,   109,     7,   -84,   204,  -648,
     -59,   -84,   209,  -648,   211,     7,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  1455,    63,  -648,    13,  -648,  -648,  -648,
     216,  -648,  -648,  -105,  -648,  1818,   217,  -648,  1032,   198,
     227,   228,   231,   232,   235,   236,   238,   240,   241,  1540,
    -648,   242,  1563,  1818,   229,   230,  1818,   246,  1818,   248,
    -648,   249,   251,  -648,  1818,   254,   255,   244,   256,   259,
     260,  1818,  1625,   261,   262,   250,  1818,   252,   263,   265,
    -648,   268,   269,   270,   274,   275,  1648,   264,   266,   279,
    1818,   283,  1818,   271,   284,  1818,  1818,   272,   290,   292,
    1710,  1818,   297,   299,   300,   291,   294,  -648,  1733,  -648,
    -648,  -648,  -648,  -648,  1818,   302,  -648,  1455,   311,  -648,
    -648,   312,   -24,   -24,  -648,  -648,  -648,   -24,   -24,   -83,
     -24,   314,  -648,   317,  1324,   320,   324,   464,  -648,   318,
     327,  -648,  -648,  -648,   -84,  -648,   109,  -648,  -648,  -648,
    -648,   330,   -84,  -648,     1,   154,  -648,  -648,  -648,   -84,
    -648,  -648,   336,   -24,    63,  -648,  -648,   277,  1404,   340,
    1818,   341,   335,  1818,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,   344,  1818,  1818,
     345,  -648,   352,  -648,  -648,  -648,  -648,  -648,  -648,  1818,
    -648,  -648,  -648,   353,  -648,   355,  -648,  -648,  1818,   356,
    1818,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  1818,
    1818,  -648,   357,  -648,   358,  1818,  -648,   359,   360,  1818,
    -648,  -648,  -648,   361,   362,  -648,  -648,  -648,  1818,  1818,
    -648,   363,  1469,   364,  1455,  -648,  -648,   365,   -24,  -648,
     -28,   -24,   -83,   366,  -648,  -648,  -648,  -648,   -21,   367,
     370,  -648,  -648,   368,   371,  -648,  -648,   375,  -648,   386,
    -648,  1455,  -648,    14,  -648,  -648,   387,  -648,   328,  -648,
      41,   379,  -648,   380,   379,  -648,  -648,   -50,   395,  -648,
    -648,   396,  -648,   398,   399,   402,  -648,  -648,   403,  -648,
    -648,   404,  -648,  -648,   405,   408,  -648,  -648,   409,  -648,
     411,  -648,  -648,   413,   -24,  -648,  -648,  -648,  -648,   453,
    -648,  -648,  -648,  -648,  -648,   407,  -648,   416,  -648,  -648,
     369,  -648,   417,    42,  -648,  1818,  -648,   426,  1818,   434,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,   435,   436,   440,  -648,  -648,   446,
      32,   447,   449,  -648,  -648,   451,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,   484,  -648,  -648,   484,   454,  -648,
    -648,   484,  -648,  -648,  -648,  -648,  -648,  1416,  1841,  -648,
    1818,  -648,  -648,  -648,   909,  -648,  1818,  -648,   -13,  -648,
     458,  -648
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
      94,    94,    94,   127,    94,   127,   127,    94,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122,
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
       0,   117,   113,   115,     0,   116,    91,   120,   121,   119,
     118,     0,     0,   103,     0,     0,   128,   125,   126,     0,
     102,   101,     0,     0,     0,   137,   147,     0,     0,     0,
       0,     0,     0,     0,   261,   260,   279,   256,   273,   244,
     255,   272,   248,   228,   162,   271,   257,     0,     0,     0,
       0,   254,     0,   291,   251,   253,   177,   282,   259,     0,
     234,   290,   250,     0,   235,     0,   289,   281,     0,     0,
       0,   249,   280,   270,   288,   262,   275,   274,   160,     0,
       0,   269,     0,   300,     0,     0,   268,     0,     0,     0,
     287,   247,   236,     0,     0,   245,   278,   277,     0,     0,
     320,     0,     0,     0,     0,   164,   169,     0,     0,   196,
       0,     0,     0,     0,   143,   170,    68,   114,     0,     0,
     107,   110,    97,     0,     0,    92,    96,     0,   129,     0,
      93,     0,   158,     0,    33,    37,     0,    44,     0,    57,
       0,   297,   218,     0,   297,   227,   225,     0,     0,   223,
     230,     0,   232,     0,     0,     0,   217,   226,     0,   222,
     224,     0,   231,   233,     0,     0,    67,    60,     0,   187,
       0,   195,   197,     0,     0,   188,   127,   127,   104,     0,
     109,   108,    98,    90,    99,     0,   100,     0,   150,   159,
       0,    43,     0,     0,    58,     0,   298,     0,     0,     0,
     175,   178,   263,   284,   264,   285,   265,   286,   246,   266,
     267,   163,   185,   186,     0,     0,     0,   130,   156,     0,
       0,     0,     0,   176,   299,     0,   296,   189,   112,   111,
      34,   312,   313,   311,   306,   314,   315,   306,     0,   302,
     303,   306,   304,    45,    54,   283,   307,     0,     0,   301,
       0,   308,   309,   305,     0,   316,     0,   310,     0,   317,
       0,   318
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLalgebraParser::yypgoto_[] =
  {
      -648,  -648,  -648,  -648,   457,   499,  -648,   502,   243,    26,
     210,   127,   455,   506,   510,  -648,  -648,  -648,  -648,  -648,
    -648,   -71,  -648,  -648,  -648,  -648,   372,   -30,  -648,   -64,
     -42,  -648,  -648,  -648,   -58,   -57,  -648,   280,  -648,  -648,
     -54,  -153,  -648,  -648,   515,   516,  -648,   513,  -648,  -648,
    -648,    74,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,    -4,   -32,  -311,  -309,   247,
    -552,   401,   -52,  -648,  -648,  -648,  -648,   -73,  -648,   423,
     385,  -648,  -334,  -648,  -129,  -213,   441,   -53,   281,   -51,
    -648,   -40,   -39,   -38,   -36,  -648,   -22,  -648,  -416,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -267,  -154,
      94,  -648,   -41,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,   -20,  -648,  -648,  -648,
    -648,  -648,  -647,  -648,  -648,  -648,  -648,  -648,  -648,   -48,
    -648,  -648,  -648,   -45,  -648,  -648,  -648,   -23,  -135,   -43,
    -648,  -648
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLalgebraParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,     5,     6,    57,     7,     8,     9,
      10,    11,    12,    13,    14,    58,    59,   349,   487,   650,
     208,    15,   209,    60,   210,   354,   214,   599,   195,    16,
      17,    18,   215,   600,    19,    20,   291,   292,   434,   293,
      21,   162,    22,    23,    24,    25,    61,    62,    63,   584,
      64,   159,    65,    66,    67,    68,    69,    70,    71,    72,
      73,   321,   640,   579,   580,   581,    74,   464,   470,   471,
     328,   332,   329,   476,   330,   477,   645,    26,   138,    27,
      75,   346,   201,   593,   107,   369,   139,    28,   303,    29,
     305,    30,    31,    32,    33,   385,   656,   607,   308,   309,
     310,   311,   312,   450,   313,   314,   570,   163,   149,   143,
     108,   151,   370,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   381,   121,   657,   122,   123,   681,
     698,   699,   707,   713,   700,   701,   702,   716,   124,   125,
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
       109,   136,   200,   152,   194,   317,   153,   145,   155,   318,
     484,   196,   302,   460,    44,   372,   472,   197,   198,   306,
     479,   199,   202,   306,   203,   181,   567,   568,   154,   467,
     437,   569,   571,   468,   573,   204,   205,   206,   636,   207,
     285,   451,   281,   350,   463,   160,   406,   474,   660,   383,
     708,   442,    76,   469,   710,    77,   475,   637,   105,   106,
     384,   161,   655,   190,    82,    83,   158,   591,   428,   443,
     631,   191,   286,   101,   102,   103,   483,     1,   307,   298,
      78,   444,   307,   347,   675,   676,   445,   137,    55,   352,
     356,   348,   446,   294,    79,    40,   295,   353,   213,    44,
      80,    45,    46,    47,    48,    49,   315,   691,   105,   106,
      50,   485,   648,   692,   693,   694,   145,    51,   695,   135,
     193,    81,   320,   333,   333,   323,   696,    52,    84,   101,
     102,   103,   697,   101,   102,   103,   164,   134,   211,   653,
      97,    98,    99,   100,   144,   150,   447,   598,   135,   448,
     592,   137,   630,   583,   632,   633,   178,   585,   212,    53,
     449,   587,   182,   185,   101,   102,   103,   188,   589,   193,
     564,   302,   213,    55,   283,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   297,   296,   371,   301,   373,   374,
     375,   376,   377,   378,   379,   380,   382,   319,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   336,   401,   402,   403,   404,   405,   674,   407,
     408,   409,   410,   337,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   338,
     339,   322,   431,   324,   325,   326,   327,   281,   331,   152,
     294,   335,   153,   144,   155,   340,   341,   478,   342,   649,
     152,   400,   355,   153,   427,   155,   101,   102,   103,   429,
     430,   200,   259,   194,   154,   439,   440,   456,   452,   461,
     196,   465,   466,   461,   465,   154,   197,   198,   465,   458,
     199,   202,   461,   203,   454,   152,   572,   628,   153,   457,
     155,   462,   473,   351,   204,   205,   206,   480,   207,   481,
     493,   101,   102,   103,   491,   281,   166,   105,   106,   368,
     154,   588,   488,   492,   647,   494,   495,   167,   504,   496,
     497,   504,   507,   498,   499,   510,   500,   512,   501,   502,
     505,   508,   509,   516,   511,   169,   513,   514,   170,   515,
     523,   525,   517,   518,   520,   529,   519,   521,   522,   526,
     527,   531,   528,   532,   530,   504,   533,   534,   535,   542,
     171,   544,   536,   537,   547,   548,   539,   541,   540,   553,
     554,   543,   546,   545,   549,   172,   173,   504,   550,   152,
     551,   150,   153,   561,   155,   555,   174,   556,   557,   315,
     315,   175,   150,   558,   315,   315,   559,   315,   562,   565,
     566,   200,   574,   194,   154,   575,   176,   177,   576,   634,
     196,   465,   577,   461,   578,   582,   197,   198,   586,   465,
     199,   202,   145,   203,   590,   594,   465,   150,   595,   597,
     315,   598,   602,   605,   204,   205,   206,   490,   207,   596,
     606,   609,   601,   610,   612,   616,   617,   619,   620,   622,
     623,   626,   627,   629,   635,   638,   642,   603,   604,   643,
     140,   141,   142,   644,   295,   157,   639,    44,   608,    45,
      46,    47,    48,    49,   646,   651,   165,   611,    50,   613,
     652,   655,   658,   662,   663,    51,   664,   665,   614,   615,
     666,   667,   668,   669,   618,    52,   670,   671,   621,   672,
     168,   673,   636,   474,   678,   183,   152,   624,   625,   153,
     200,   155,   194,   680,   684,   315,   679,   315,   315,   196,
     282,   150,   686,   687,   688,   197,   198,    53,   689,   199,
     202,   154,   203,   152,   690,   703,   153,   704,   155,   705,
     706,    55,   709,   204,   205,   206,   721,   207,   186,   179,
     489,   455,   563,   300,   284,   304,   189,   180,   154,   144,
     654,   436,   677,   184,   192,   187,   641,   334,   344,   299,
     316,   438,   482,   720,   659,   661,     0,   357,     0,     0,
       0,   315,     0,     0,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,    48,
      49,   682,     0,     0,   683,    50,     0,   685,     0,     0,
       0,     0,    51,     0,   345,     0,     0,     0,     0,     0,
       0,     0,    52,     0,     0,     0,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,    48,
      49,     0,     0,   165,     0,    50,     0,     0,   150,     0,
       0,     0,    51,     0,    53,     0,   712,   715,     0,   717,
      54,   281,    52,     0,     0,   719,     0,   168,    55,     0,
       0,     0,     0,     0,     0,   150,     0,   411,   216,     0,
     217,   218,   219,   220,     0,   221,   222,    56,   432,   433,
     223,   224,     0,   225,    53,   226,   227,   228,   229,     0,
      54,     0,   230,   231,     0,     0,   232,   233,    55,     0,
       0,   234,     0,   235,   236,     0,   237,   238,   441,     0,
     239,   240,   241,   242,   243,   244,     0,   245,     0,   246,
     453,     0,     0,   247,   459,     0,     0,   248,   249,     0,
       0,   250,   251,   252,   253,     0,     0,     0,     0,   254,
     255,     0,   256,     0,   257,   258,     0,     0,   260,   486,
     261,     0,   262,   263,   264,     0,   265,   266,     0,     0,
     267,   268,     0,   269,     0,   270,     0,     0,     0,   271,
       0,     0,   272,     0,   273,   274,     0,   275,   276,     0,
       0,   277,   278,   279,   280,     0,     0,     0,     0,     0,
       0,   216,     0,   217,   218,   219,   220,     0,   221,   222,
     101,   102,   103,   223,   224,     0,   225,     0,   226,   227,
     228,   229,     0,     0,     0,   230,   231,     0,     0,   232,
     233,     0,     0,     0,   234,     0,   235,   236,     0,   237,
     238,     0,     0,   239,   240,   241,   242,   243,   244,     0,
     245,     0,   246,     0,     0,     0,   247,     0,     0,     0,
     248,   249,     0,     0,   250,   251,   252,   253,     0,     0,
       0,     0,   254,   255,     0,   256,     0,   257,   258,     0,
     259,   260,     0,   261,     0,   262,   263,   264,     0,   265,
     266,     0,     0,   267,   268,     0,   269,     0,   270,     0,
       0,     0,   271,     0,     0,   272,     0,   273,   274,     0,
     275,   276,     0,     0,   277,   278,   279,   280,     0,     0,
       0,     0,     0,     0,   216,     0,   217,   218,   219,   220,
       0,   221,   222,   101,   102,   103,   223,   224,     0,   225,
       0,   226,   227,   228,   229,     0,     0,     0,   230,   231,
       0,     0,   232,   233,     0,     0,   718,   234,     0,   235,
     236,     0,   237,   238,     0,     0,   239,   240,   241,   242,
     243,   244,     0,   245,     0,   246,     0,     0,     0,   247,
       0,     0,     0,   248,   249,     0,     0,   250,   251,   252,
     253,     0,     0,     0,     0,   254,   255,     0,   256,     0,
     257,   258,     0,     0,   260,     0,   261,     0,   262,   263,
     264,     0,   265,   266,     0,     0,   267,   268,     0,   269,
       0,   270,     0,     0,     0,   271,     0,     0,   272,     0,
     273,   274,     0,   275,   276,     0,     0,   277,   278,   279,
     280,     0,     0,     0,     0,     0,     0,   216,     0,   217,
     218,   219,   220,     0,   221,   222,   101,   102,   103,   223,
     224,     0,   225,     0,   226,   227,   228,   229,     0,     0,
       0,   230,   231,     0,     0,   232,   233,     0,     0,     0,
     234,     0,   235,   236,     0,   237,   238,     0,     0,   239,
     240,   241,   242,   243,   244,     0,   245,     0,   246,     0,
       0,     0,   247,     0,     0,     0,   248,   249,     0,     0,
     250,   251,   252,   253,     0,     0,     0,     0,   254,   255,
       0,   256,     0,   257,   258,     0,     0,   260,     0,   261,
       0,   262,   263,   264,     0,   265,   266,     0,     0,   267,
     268,     0,   269,     0,   270,     0,     0,     0,   271,     0,
       0,   272,     0,   273,   274,     0,   275,   276,     0,     0,
     277,   278,   279,   280,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   101,
     102,   103,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,     0,   165,
     166,     0,    50,     0,     0,     0,     0,     0,     0,    51,
       0,   167,     0,     0,     0,     0,     0,     0,     0,    52,
       0,     0,     0,   168,     0,     0,     0,     0,     0,   169,
       0,     0,   170,     0,     0,     0,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,    48,
      49,    53,     0,     0,   171,    50,     0,    54,     0,     0,
       0,     0,    51,     0,     0,    55,     0,     0,     0,   172,
     173,     0,    52,     0,     0,     0,     0,     0,     0,     0,
     174,     0,     0,     0,    56,   175,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     176,   177,     0,     0,    53,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,    55,    36,
      37,    38,    39,    40,    41,    42,     0,    44,     0,    45,
      46,    47,    48,    49,     0,     0,     0,    56,    50,     0,
       0,     0,     0,     0,     0,    51,    36,     0,    38,    39,
       0,    41,    42,     0,    44,    52,    45,    46,    47,    48,
      49,     0,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,   343,     0,     0,     0,     0,     0,     0,     0,
      36,    37,    52,     0,    40,    41,    42,    53,    44,     0,
      45,    46,    47,    48,    49,     0,     0,     0,     0,    50,
      37,    55,     0,    40,    41,    42,    51,    44,     0,    45,
      46,    47,    48,    49,    53,     0,    52,     0,    50,     0,
      54,     0,     0,     0,     0,    51,     0,     0,    55,    37,
       0,     0,    40,   295,     0,    52,    44,     0,    45,    46,
      47,    48,    49,     0,     0,     0,     0,    50,    53,     0,
       0,     0,     0,     0,    51,     0,     0,     0,     0,     0,
       0,     0,    55,     0,    52,    37,     0,    53,    40,    41,
       0,     0,    44,     0,    45,    46,    47,    48,    49,     0,
       0,    55,     0,    50,     0,     0,     0,     0,     0,     0,
      51,   711,     0,     0,     0,     0,    53,     0,     0,     0,
      52,     0,     0,     0,     0,     0,     0,     0,   295,     0,
      55,    44,   358,    45,    46,    47,    48,    49,     0,     0,
       0,     0,    50,     0,     0,     0,     0,     0,     0,    51,
       0,     0,    53,     0,     0,     0,     0,     0,     0,    52,
     146,     0,     0,     0,     0,     0,    55,     0,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   435,     0,   104,   105,
     106,    53,     0,     0,   290,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   147,   148,     0,   105,   106,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   503,     0,
     104,   105,   106,     0,     0,     0,   358,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   506,     0,     0,     0,     0,     0,     0,     0,   358,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
       0,     0,   104,   105,   106,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   524,     0,   104,   105,   106,     0,     0,
       0,   358,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   538,     0,     0,     0,
       0,     0,     0,     0,   358,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,     0,     0,   104,   105,   106,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   552,     0,
     104,   105,   106,     0,     0,     0,   358,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   560,     0,     0,     0,     0,     0,     0,     0,   358,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      85,     0,   104,   105,   106,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   290,     0,   104,   105,   106,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   358,     0,   104,   105,   106,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   714,     0,   104,
     105,   106,     0,     0,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,     0,
     104,   105,   106,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,     0,     0,   104,   105,   106
  };

  /* YYCHECK.  */
  const short int
  SPARQLalgebraParser::yycheck_[] =
  {
        41,    43,    75,    51,    75,   159,    51,    50,    51,   162,
     344,    75,   141,   322,    13,   228,   327,    75,    75,    47,
     331,    75,    75,    47,    75,    57,   442,   443,    51,    22,
     297,   447,   448,    26,   450,    75,    75,    75,    59,    75,
     133,   308,    85,    98,   128,   128,   259,   106,    98,    95,
     697,    21,     0,    46,   701,   157,   115,    78,   163,   164,
     106,   144,   112,    98,    38,    39,   127,   483,   281,    39,
      98,   106,   165,   157,   158,   159,   343,   106,   106,    98,
     106,    51,   106,    98,   636,   637,    56,   106,    87,    98,
      98,   106,    62,   134,   106,     9,    10,   106,   106,    13,
     106,    15,    16,    17,    18,    19,   149,    75,   163,   164,
      24,    98,    98,    81,    82,    83,   159,    31,    86,   106,
     106,   106,   165,   175,   176,   168,    94,    41,   106,   157,
     158,   159,   100,   157,   158,   159,    20,   106,    98,    98,
     153,   154,   155,   156,    50,    51,   116,   106,   106,   119,
     484,   106,   568,   464,   570,   571,   106,   466,    98,    73,
     130,   472,   106,   106,   157,   158,   159,   106,   479,   106,
     437,   300,   106,    87,   106,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    14,    98,   227,   106,   229,   230,
     231,   232,   233,   234,   235,   236,   237,    98,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,    98,   254,   255,   256,   257,   258,   634,   260,
     261,   262,   263,    98,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,    98,
      98,   167,   285,   169,   170,   171,   172,   290,   174,   297,
     291,   177,   297,   159,   297,    98,    98,   330,    98,   593,
     308,    98,   162,   308,    98,   308,   157,   158,   159,    98,
      98,   344,   104,   344,   297,    98,    98,   320,    98,   322,
     344,   324,   325,   326,   327,   308,   344,   344,   331,   321,
     344,   344,   335,   344,   106,   343,   449,   564,   343,   106,
     343,    98,    98,   209,   344,   344,   344,    98,   344,    98,
     112,   157,   158,   159,   355,   358,    23,   163,   164,   225,
     343,   475,   106,   106,   591,    98,    98,    34,   369,    98,
      98,   372,   373,    98,    98,   376,    98,   378,    98,    98,
      98,   112,   112,   384,    98,    52,    98,    98,    55,    98,
     391,   392,    98,    98,    98,   396,   112,    98,    98,    98,
      98,    98,   112,    98,   112,   406,    98,    98,    98,   410,
      77,   412,    98,    98,   415,   416,   112,    98,   112,   420,
     421,    98,    98,   112,   112,    92,    93,   428,    98,   437,
      98,   297,   437,   434,   437,    98,   103,    98,    98,   442,
     443,   108,   308,   112,   447,   448,   112,   450,   106,    98,
      98,   484,    98,   484,   437,    98,   123,   124,    98,   572,
     484,   464,    98,   466,   106,    98,   484,   484,    98,   472,
     484,   484,   475,   484,    98,   158,   479,   343,    98,    98,
     483,   106,    98,    98,   484,   484,   484,   353,   484,   490,
      98,    98,   493,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,   508,   509,    98,
      47,    48,    49,    98,    10,    52,   106,    13,   519,    15,
      16,    17,    18,    19,    98,    98,    22,   528,    24,   530,
     162,   112,   112,    98,    98,    31,    98,    98,   539,   540,
      98,    98,    98,    98,   545,    41,    98,    98,   549,    98,
      46,    98,    59,   106,    98,    58,   564,   558,   559,   564,
     593,   564,   593,   106,    98,   568,   157,   570,   571,   593,
     107,   437,    98,    98,    98,   593,   593,    73,    98,   593,
     593,   564,   593,   591,    98,    98,   591,    98,   591,    98,
      66,    87,    98,   593,   593,   593,    98,   593,    59,    57,
     350,   318,   435,   140,   109,   142,    60,    57,   591,   475,
     600,   291,   645,    58,    61,    59,   580,   176,   193,   138,
     157,   300,   335,   718,   604,   607,    -1,   215,    -1,    -1,
      -1,   634,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      19,   653,    -1,    -1,   655,    24,    -1,   658,    -1,    -1,
      -1,    -1,    31,    -1,   201,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    -1,    -1,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      19,    -1,    -1,    22,    -1,    24,    -1,    -1,   564,    -1,
      -1,    -1,    31,    -1,    73,    -1,   707,   708,    -1,   710,
      79,   714,    41,    -1,    -1,   716,    -1,    46,    87,    -1,
      -1,    -1,    -1,    -1,    -1,   591,    -1,   264,    25,    -1,
      27,    28,    29,    30,    -1,    32,    33,   106,    35,    36,
      37,    38,    -1,    40,    73,    42,    43,    44,    45,    -1,
      79,    -1,    49,    50,    -1,    -1,    53,    54,    87,    -1,
      -1,    58,    -1,    60,    61,    -1,    63,    64,   305,    -1,
      67,    68,    69,    70,    71,    72,    -1,    74,    -1,    76,
     317,    -1,    -1,    80,   321,    -1,    -1,    84,    85,    -1,
      -1,    88,    89,    90,    91,    -1,    -1,    -1,    -1,    96,
      97,    -1,    99,    -1,   101,   102,    -1,    -1,   105,   346,
     107,    -1,   109,   110,   111,    -1,   113,   114,    -1,    -1,
     117,   118,    -1,   120,    -1,   122,    -1,    -1,    -1,   126,
      -1,    -1,   129,    -1,   131,   132,    -1,   134,   135,    -1,
      -1,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    -1,    27,    28,    29,    30,    -1,    32,    33,
     157,   158,   159,    37,    38,    -1,    40,    -1,    42,    43,
      44,    45,    -1,    -1,    -1,    49,    50,    -1,    -1,    53,
      54,    -1,    -1,    -1,    58,    -1,    60,    61,    -1,    63,
      64,    -1,    -1,    67,    68,    69,    70,    71,    72,    -1,
      74,    -1,    76,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    85,    -1,    -1,    88,    89,    90,    91,    -1,    -1,
      -1,    -1,    96,    97,    -1,    99,    -1,   101,   102,    -1,
     104,   105,    -1,   107,    -1,   109,   110,   111,    -1,   113,
     114,    -1,    -1,   117,   118,    -1,   120,    -1,   122,    -1,
      -1,    -1,   126,    -1,    -1,   129,    -1,   131,   132,    -1,
     134,   135,    -1,    -1,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    -1,    27,    28,    29,    30,
      -1,    32,    33,   157,   158,   159,    37,    38,    -1,    40,
      -1,    42,    43,    44,    45,    -1,    -1,    -1,    49,    50,
      -1,    -1,    53,    54,    -1,    -1,    57,    58,    -1,    60,
      61,    -1,    63,    64,    -1,    -1,    67,    68,    69,    70,
      71,    72,    -1,    74,    -1,    76,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    84,    85,    -1,    -1,    88,    89,    90,
      91,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,    -1,
     101,   102,    -1,    -1,   105,    -1,   107,    -1,   109,   110,
     111,    -1,   113,   114,    -1,    -1,   117,   118,    -1,   120,
      -1,   122,    -1,    -1,    -1,   126,    -1,    -1,   129,    -1,
     131,   132,    -1,   134,   135,    -1,    -1,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    27,
      28,    29,    30,    -1,    32,    33,   157,   158,   159,    37,
      38,    -1,    40,    -1,    42,    43,    44,    45,    -1,    -1,
      -1,    49,    50,    -1,    -1,    53,    54,    -1,    -1,    -1,
      58,    -1,    60,    61,    -1,    63,    64,    -1,    -1,    67,
      68,    69,    70,    71,    72,    -1,    74,    -1,    76,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    85,    -1,    -1,
      88,    89,    90,    91,    -1,    -1,    -1,    -1,    96,    97,
      -1,    99,    -1,   101,   102,    -1,    -1,   105,    -1,   107,
      -1,   109,   110,   111,    -1,   113,   114,    -1,    -1,   117,
     118,    -1,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,
      -1,   129,    -1,   131,   132,    -1,   134,   135,    -1,    -1,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
     158,   159,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    15,    16,    17,    18,    19,    -1,    22,
      23,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    55,    -1,    -1,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      19,    73,    -1,    -1,    77,    24,    -1,    79,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    87,    -1,    -1,    -1,    92,
      93,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     103,    -1,    -1,    -1,   106,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     123,   124,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,     5,
       6,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    19,    -1,    -1,    -1,   106,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    31,     5,    -1,     7,     8,
      -1,    10,    11,    -1,    13,    41,    15,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       5,     6,    41,    -1,     9,    10,    11,    73,    13,    -1,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    24,
       6,    87,    -1,     9,    10,    11,    31,    13,    -1,    15,
      16,    17,    18,    19,    73,    -1,    41,    -1,    24,    -1,
      79,    -1,    -1,    -1,    -1,    31,    -1,    -1,    87,     6,
      -1,    -1,     9,    10,    -1,    41,    13,    -1,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    24,    73,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    -1,    41,     6,    -1,    73,     9,    10,
      -1,    -1,    13,    -1,    15,    16,    17,    18,    19,    -1,
      -1,    87,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    85,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,
      87,    13,   106,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      95,    -1,    -1,    -1,    -1,    -1,    87,    -1,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,    98,    -1,   162,   163,
     164,    73,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    -1,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,   163,   164,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,    98,    -1,
     162,   163,   164,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
      -1,    -1,   162,   163,   164,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,    98,    -1,   162,   163,   164,    -1,    -1,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,    -1,    -1,   162,   163,   164,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,    98,    -1,
     162,   163,   164,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     106,    -1,   162,   163,   164,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   106,    -1,   162,   163,   164,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   106,    -1,   162,   163,   164,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   106,    -1,   162,
     163,   164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,    -1,    -1,
     162,   163,   164,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,    -1,    -1,   162,   163,   164
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
     315,   227,   217,   315,   217,   217,   217,   217,   236,   238,
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
     234,   315,    98,   128,   233,   315,   315,    22,    26,    46,
     234,   235,   233,    98,   106,   115,   239,   241,   243,   233,
      98,    98,   235,   274,   248,    98,   245,   184,   106,   176,
     276,   278,   106,   112,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,   278,    98,    98,   278,   112,   112,
     278,    98,   278,    98,    98,    98,   278,    98,    98,   112,
      98,    98,    98,   278,    98,   278,    98,    98,   112,   278,
     112,    98,    98,    98,    98,    98,    98,    98,    98,   112,
     112,    98,   278,    98,   278,   112,    98,   278,   278,   112,
      98,    98,    98,   278,   278,    98,    98,    98,   112,   112,
      98,   278,   106,   177,   274,    98,    98,   264,   264,   264,
     272,   264,   207,   264,    98,    98,    98,    98,   106,   229,
     230,   231,    98,   233,   215,   234,    98,   233,   275,   233,
      98,   264,   248,   249,   158,    98,   278,    98,   106,   193,
     199,   278,    98,   278,   278,    98,    98,   263,   278,    98,
      98,   278,    98,   278,   278,   278,    98,    98,   278,    98,
      98,   278,    98,    98,   278,   278,    98,    98,   274,    98,
     264,    98,   264,   264,   207,    98,    59,    78,    98,   106,
     228,   231,    98,    98,    98,   242,    98,   274,    98,   248,
     185,    98,   162,    98,   193,   112,   262,   292,   112,   292,
      98,   262,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,   264,   236,   236,   243,    98,   157,
     106,   295,   196,   278,    98,   278,    98,    98,    98,    98,
      98,    75,    81,    82,    83,    86,    94,   100,   296,   297,
     300,   301,   302,    98,    98,    98,    66,   298,   298,    98,
     298,    85,   278,   299,   106,   278,   303,   278,    57,   278,
     314,    98
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
       6,     0,     1,     5,     0,     1,     5,     5,     6,     6,
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
     217,   315,   215,    98,    -1,    -1,   234,    -1,   106,   124,
     217,   235,    98,    -1,    -1,   127,    -1,   106,    77,   217,
     235,    98,    -1,   106,    34,   217,   234,    98,    -1,   106,
      52,   217,   233,   233,    98,    -1,   106,    92,   217,   233,
     233,    98,    -1,   106,   103,   217,   233,   233,    98,    -1,
     106,   123,   237,    98,    -1,   106,   108,   237,    98,    -1,
     106,    93,   236,    98,    -1,   106,    23,   227,   245,   229,
      98,    -1,    -1,   227,   232,    -1,    -1,   231,    -1,   230,
     228,    -1,   231,    -1,   106,    78,   236,    98,    -1,   106,
      59,   236,    98,    -1,   106,    46,   315,    98,    -1,   106,
      22,   315,   315,    98,    -1,   128,    -1,   315,    -1,   315,
      -1,   234,    -1,    46,    -1,    22,    -1,    26,    -1,   238,
      -1,   238,    -1,   240,    -1,   241,    -1,   243,    -1,    -1,
     240,   239,    -1,    -1,   115,   275,   242,   243,    -1,   106,
      13,   244,    98,    -1,   106,    87,    20,    98,    -1,   252,
      -1,   244,   252,    -1,   243,    -1,   260,    -1,   106,   246,
     248,   247,    98,    -1,   253,    -1,   255,    -1,   257,    -1,
     258,    -1,   259,    -1,   106,    31,   274,   264,   274,    98,
      -1,    15,    -1,    16,    -1,   245,    -1,   247,   245,    -1,
     243,    -1,   260,    -1,   106,   246,   248,   249,    98,    -1,
     253,    -1,   255,    -1,   257,    -1,   258,    -1,   259,    -1,
     106,    31,   274,   264,   274,    98,    -1,   194,    -1,   248,
      -1,   249,   248,    -1,   106,   104,   251,    98,    -1,   278,
      -1,   251,   278,    -1,   106,    14,   274,   274,   274,    98,
      -1,   106,    17,   245,   245,   254,    98,    -1,   106,    18,
     245,   254,    98,    -1,    -1,   250,    -1,    -1,   106,    24,
     275,   256,   245,    98,    -1,   106,    73,   217,   275,   245,
      98,    -1,   106,    41,   245,   245,    98,    -1,   106,    19,
     245,   245,    98,    -1,   106,    10,   250,   245,    98,    -1,
      95,    -1,   106,   278,   263,    98,    -1,   112,   278,    -1,
      -1,   263,   262,    -1,   265,    -1,   266,    -1,   267,    -1,
     268,    -1,   271,    -1,   270,    -1,   106,    39,   264,   264,
      98,    -1,   106,   119,   264,   264,    98,    -1,   106,    21,
     264,    98,    -1,   106,   269,   264,    98,    -1,   106,   130,
     207,   207,   264,    98,    -1,    62,    -1,    56,    -1,    51,
      -1,   315,    -1,    47,    -1,   106,   116,   272,    98,    -1,
     264,    -1,   272,   264,    -1,   144,    -1,   276,    -1,   277,
      -1,   276,    -1,   315,    -1,   163,    -1,   164,    -1,   315,
      -1,   305,    -1,   309,    -1,   313,    -1,   317,    -1,    95,
      -1,   279,    -1,   280,    -1,   281,    -1,   286,    -1,   287,
      -1,   288,    -1,   106,   110,   278,   278,    98,    -1,   106,
      45,   278,   278,    98,    -1,   282,    -1,   284,    -1,   283,
      -1,   106,   118,   278,   278,    98,    -1,   106,    72,   278,
     278,    98,    -1,   106,   120,   278,   278,    98,    -1,   106,
      58,   278,   278,    98,    -1,   106,   113,   278,   278,    98,
      -1,   106,    53,   278,   278,    98,    -1,   106,    42,   251,
      98,    -1,   285,    -1,   106,    74,   278,   278,    98,    -1,
     106,   131,   278,   278,    98,    -1,   106,    85,   278,   278,
      98,    -1,   106,   132,   278,   278,    98,    -1,   106,    69,
     278,    98,    -1,   106,    74,   278,    98,    -1,   106,   131,
     278,    98,    -1,   289,    -1,   304,    -1,   305,    -1,   309,
      -1,   313,    -1,   276,    -1,   162,    -1,   106,    33,   278,
      98,    -1,   106,   134,   278,    98,    -1,   106,   122,   278,
     112,   278,    98,    -1,   106,   129,   278,    98,    -1,   106,
      40,   276,    98,    -1,   106,    89,   278,    98,    -1,   106,
      71,   278,    98,    -1,   106,    61,   290,    98,    -1,   106,
     141,    98,    -1,   106,    63,   278,    98,    -1,   106,    54,
     278,    98,    -1,   106,    37,   278,    98,    -1,   106,    30,
     278,    98,    -1,   106,    44,   251,    98,    -1,   293,    -1,
     106,    67,   278,    98,    -1,   106,    28,   278,    98,    -1,
     106,    27,   278,    98,    -1,   106,    99,   278,    98,    -1,
     106,    68,   278,   112,   278,    98,    -1,   106,    88,   278,
     112,   278,    98,    -1,   106,   107,   278,   112,   278,    98,
      -1,   106,   139,   278,   112,   278,    98,    -1,   106,   140,
     278,   112,   278,    98,    -1,   106,   117,   278,    98,    -1,
     106,   109,   278,    98,    -1,   106,    96,   278,    98,    -1,
     106,    43,   278,    98,    -1,   106,    38,   278,    98,    -1,
     106,    32,   278,    98,    -1,   106,   102,   278,    98,    -1,
     106,   101,   278,    98,    -1,   106,    91,    98,    -1,   106,
     138,   278,    98,    -1,   106,   135,   278,    98,    -1,   106,
      29,   278,    98,    -1,   106,    90,   278,    98,    -1,   106,
      80,   278,    98,    -1,   106,    64,   261,    98,    -1,   106,
      49,   278,   112,   278,   112,   278,    98,    -1,   106,    84,
     278,   112,   278,    98,    -1,   106,   105,   278,   112,   278,
      98,    -1,   106,   114,   278,   112,   278,    98,    -1,   106,
     126,   278,    98,    -1,   106,    97,   278,    98,    -1,   106,
      76,   278,    98,    -1,   106,    70,   278,    98,    -1,   106,
      60,   278,    98,    -1,   291,    -1,   294,    -1,    -1,   278,
      -1,   106,    50,   278,   112,   278,   292,    98,    -1,    -1,
     262,    -1,   106,    25,   278,   112,   278,   292,    98,    -1,
     106,   111,   245,    98,    -1,   106,   296,    98,    -1,   297,
      -1,   300,    -1,   302,    -1,    83,   298,   299,    -1,    -1,
      66,    -1,    85,    -1,   278,    -1,   301,   298,   278,    -1,
      82,    -1,    75,    -1,    81,    -1,    86,    -1,    94,    -1,
     100,   298,   278,    -1,   100,   298,   303,   278,    -1,   106,
      57,   314,    98,    -1,   315,    -1,   106,   315,   251,    98,
      -1,   314,   308,    -1,   133,   315,    -1,   165,    -1,   306,
      -1,    -1,   307,    -1,   310,    -1,   311,    -1,   312,    -1,
     144,    -1,   145,    -1,   146,    -1,   147,    -1,   148,    -1,
     149,    -1,   150,    -1,   151,    -1,   152,    -1,   142,    -1,
     143,    -1,   153,    -1,   155,    -1,   154,    -1,   156,    -1,
     157,    -1,   316,    -1,   159,    -1,   158,    -1,   160,    -1,
     161,    -1
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
     268,   275,   276,   278,   284,   285,   287,   293,   299,   306,
     313,   320,   325,   330,   335,   342,   343,   346,   347,   349,
     352,   354,   359,   364,   369,   375,   377,   379,   381,   383,
     385,   387,   389,   391,   393,   395,   397,   399,   400,   403,
     404,   409,   414,   419,   421,   424,   426,   428,   434,   436,
     438,   440,   442,   444,   451,   453,   455,   457,   460,   462,
     464,   470,   472,   474,   476,   478,   480,   487,   489,   491,
     494,   499,   501,   504,   511,   518,   524,   525,   527,   528,
     535,   542,   548,   554,   560,   562,   567,   570,   571,   574,
     576,   578,   580,   582,   584,   586,   592,   598,   603,   608,
     615,   617,   619,   621,   623,   625,   630,   632,   635,   637,
     639,   641,   643,   645,   647,   649,   651,   653,   655,   657,
     659,   661,   663,   665,   667,   669,   671,   673,   679,   685,
     687,   689,   691,   697,   703,   709,   715,   721,   727,   732,
     734,   740,   746,   752,   758,   763,   768,   773,   775,   777,
     779,   781,   783,   785,   787,   792,   797,   804,   809,   814,
     819,   824,   829,   833,   838,   843,   848,   853,   858,   860,
     865,   870,   875,   880,   887,   894,   901,   908,   915,   920,
     925,   930,   935,   940,   945,   950,   955,   959,   964,   969,
     974,   979,   984,   989,   998,  1005,  1012,  1019,  1024,  1029,
    1034,  1039,  1044,  1046,  1048,  1049,  1051,  1059,  1060,  1062,
    1070,  1075,  1079,  1081,  1083,  1085,  1089,  1090,  1092,  1094,
    1096,  1100,  1102,  1104,  1106,  1108,  1110,  1114,  1119,  1124,
    1126,  1131,  1134,  1137,  1139,  1141,  1142,  1144,  1146,  1148,
    1150,  1152,  1154,  1156,  1158,  1160,  1162,  1164,  1166,  1168,
    1170,  1172,  1174,  1176,  1178,  1180,  1182,  1184,  1186,  1188,
    1190
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLalgebraParser::yyrline_[] =
  {
         0,   335,   335,   338,   344,   348,   351,   355,   358,   362,
     365,   368,   371,   377,   380,   387,   388,   395,   396,   403,
     404,   411,   412,   419,   420,   427,   431,   437,   438,   446,
     452,   458,   462,   464,   462,   472,   474,   478,   485,   488,
     495,   500,   502,   506,   510,   514,   520,   521,   522,   523,
     524,   528,   532,   562,   568,   575,   576,   580,   581,   587,
     596,   603,   607,   614,   615,   622,   626,   632,   639,   646,
     649,   669,   673,   676,   680,   683,   687,   693,   697,   706,
     707,   708,   709,   710,   711,   712,   713,   714,   715,   716,
     720,   726,   729,   735,   741,   744,   752,   760,   768,   776,
     784,   792,   800,   808,   816,   822,   825,   832,   835,   839,
     843,   852,   860,   868,   871,   879,   882,   888,   894,   895,
     898,   901,   909,   913,   917,   923,   924,   928,   931,   938,
     938,   948,   951,   957,   961,   968,   969,   970,   974,   975,
     976,   977,   978,   979,   986,   987,   991,   995,  1002,  1003,
    1004,  1008,  1009,  1010,  1011,  1012,  1013,  1017,  1023,  1027,
    1034,  1040,  1043,  1050,  1064,  1078,  1092,  1095,  1099,  1099,
    1109,  1117,  1126,  1135,  1151,  1154,  1161,  1167,  1170,  1218,
    1219,  1220,  1221,  1222,  1223,  1227,  1233,  1241,  1247,  1250,
    1256,  1257,  1258,  1262,  1265,  1273,  1279,  1280,  1287,  1304,
    1307,  1311,  1314,  1320,  1321,  1325,  1328,  1329,  1332,  1335,
    1336,  1342,  1343,  1344,  1345,  1346,  1347,  1351,  1360,  1369,
    1373,  1374,  1378,  1381,  1384,  1387,  1390,  1393,  1396,  1404,
    1408,  1414,  1428,  1434,  1443,  1446,  1449,  1455,  1456,  1457,
    1460,  1463,  1466,  1469,  1480,  1483,  1486,  1489,  1492,  1495,
    1498,  1501,  1504,  1507,  1510,  1513,  1516,  1519,  1522,  1523,
    1526,  1529,  1532,  1535,  1538,  1541,  1544,  1547,  1550,  1553,
    1556,  1559,  1562,  1565,  1568,  1571,  1574,  1577,  1580,  1583,
    1586,  1589,  1592,  1596,  1599,  1602,  1605,  1608,  1611,  1614,
    1617,  1620,  1623,  1624,  1628,  1631,  1637,  1643,  1646,  1650,
    1656,  1668,  1672,  1673,  1674,  1678,  1684,  1687,  1693,  1696,
    1700,  1706,  1709,  1712,  1715,  1718,  1724,  1727,  1733,  1737,
    1740,  1746,  1753,  1759,  1763,  1770,  1774,  1778,  1779,  1780,
    1784,  1785,  1786,  1790,  1791,  1792,  1796,  1797,  1798,  1802,
    1803,  1807,  1808,  1809,  1810,  1814,  1815,  1819,  1820,  1824,
    1825
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
  const int SPARQLalgebraParser::yylast_ = 2005;
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
#line 4018 "lib/SPARQLalgebraParser/SPARQLalgebraParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 1830 "lib/SPARQLalgebraParser/SPARQLalgebraParser.ypp"
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


