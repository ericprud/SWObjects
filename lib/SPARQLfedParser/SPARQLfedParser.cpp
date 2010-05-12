
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
#line 43 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


#include "SPARQLfedParser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 232 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 348 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lexWrapper


/* Line 317 of lalr1.cc  */
#line 68 "lib/SPARQLfedParser/SPARQLfedParser.cpp"

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
#line 137 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  SPARQLfedParser::yytnamerr_ (const char *yystr)
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
  SPARQLfedParser::SPARQLfedParser (class SPARQLfedDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  SPARQLfedParser::~SPARQLfedParser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  SPARQLfedParser::yy_symbol_value_print_ (int yytype,
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
  SPARQLfedParser::yy_symbol_print_ (int yytype,
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
  SPARQLfedParser::yydestruct_ (const char* yymsg,
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
  SPARQLfedParser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  SPARQLfedParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  SPARQLfedParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  SPARQLfedParser::debug_level_type
  SPARQLfedParser::debug_level () const
  {
    return yydebug_;
  }

  void
  SPARQLfedParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  SPARQLfedParser::parse ()
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
#line 37 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 321 "lib/SPARQLfedParser/SPARQLfedParser.cpp"

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
#line 363 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(2) - (2)].p_Operation);
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 379 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Replace((yysemantic_stack_[(4) - (2)].p_WhereClause), driver.curOp);
	driver.curOp = NULL;
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 403 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 409 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 411 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 413 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 421 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Select((yysemantic_stack_[(4) - (1)].p_Project).distinctness, (yysemantic_stack_[(4) - (1)].p_Project).varSet, (yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 428 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 431 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 442 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Select((yysemantic_stack_[(3) - (1)].p_Project).distinctness, (yysemantic_stack_[(3) - (1)].p_Project).varSet, NULL, (yysemantic_stack_[(3) - (2)].p_WhereClause), (yysemantic_stack_[(3) - (3)].p_SolutionModifier));
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 449 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 457 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 460 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 467 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 475 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSList) = new POSList;
	(yyval.p_POSList)->push_back((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 479 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_POSList) = (yysemantic_stack_[(2) - (1)].p_POSList);
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 487 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_POSList);
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 490 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 497 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	(yyval.p_Operation) = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(5) - (2)].p_BasicGraphPattern), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 505 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 512 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSList) = new POSList;
	(yyval.p_POSList)->push_back((yysemantic_stack_[(1) - (1)].p_POS));
    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 516 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSList)->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSList) = (yysemantic_stack_[(2) - (1)].p_POSList);
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 524 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_POSList);
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 527 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 534 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 542 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(3) - (2)].p_DatasetClauses), (yysemantic_stack_[(3) - (3)].p_WhereClause));
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 549 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 561 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_POS), driver.posFactory);
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 567 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_POS), driver.posFactory);
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 573 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 580 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp ? driver.curOp : new DefaultGraphPattern(), (yysemantic_stack_[(3) - (3)].p_BindingClause));
	driver.curOp = NULL;
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 593 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 601 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(2) - (1)].p_OrderConditions), (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit, (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset);
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 608 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 616 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 625 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 632 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 636 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 646 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 654 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 657 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 665 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 674 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 681 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 685 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 693 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 701 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 708 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 714 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 733 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 736 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert((yysemantic_stack_[(4) - (3)].p_TableOperation), (yysemantic_stack_[(4) - (4)].p_WhereClause));
      }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 742 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 745 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(4) - (3)].p_TableOperation), (yysemantic_stack_[(4) - (4)].p_WhereClause));
      }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 751 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(2) - (2)].p_URI));
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 757 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 764 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(3) - (2)].p_URIs), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 771 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URIs) = new ProductionVector<const URI*>((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 774 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_URIs)->push_back((yysemantic_stack_[(2) - (2)].p_URI));
	(yyval.p_URIs) = (yysemantic_stack_[(2) - (1)].p_URIs);
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 782 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 789 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 796 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 802 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 805 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 811 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 817 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 824 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_POSList));
      }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 826 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = driver.curBindingClause;
	  driver.curBindingClause = NULL;
      }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 834 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Bindings) = NULL;
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 837 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingClause->push_back((yysemantic_stack_[(2) - (2)].p_Binding));
	(yyval.p_Bindings) = NULL;
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 845 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding = new Binding();
      }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 847 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Binding) = driver.curBinding;
	  driver.curBinding = NULL;
      }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 856 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getNULL();
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 863 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_POS));
	(yyval.p_POSs) = NULL;
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 867 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = NULL;
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 875 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 878 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 928 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 931 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
      }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 938 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curFilter = NULL;
      }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 941 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_POS);
      }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 944 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(5) - (3)].p_POS), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(5) - (4)].p_POS);
      }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 987 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 989 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.curFilter;
      }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 991 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  OptionalGraphPattern* ret = new OptionalGraphPattern(driver.curOp);
	  if (driver.curFilter) {
	      driver.curFilter->copyExpressionsTo(ret);
	      delete driver.curFilter;
	  }
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), ret);
	  driver.curFilter = (yysemantic_stack_[(4) - (3)].p_ParserFilter);
      }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1003 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1005 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1007 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.curOp));
      }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1014 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1016 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1018 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_POS);
      }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1021 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_POS), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_POS);
      }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1029 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1031 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1033 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(5) - (4)].p_POS), driver.curOp, driver.posFactory, false));
      }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1041 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1044 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1046 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1054 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1059 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1074 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    if (driver.curOp == NULL)
		driver.ensureBasicGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1091 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1098 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1102 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1104 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList);
	  driver.curExprList = NULL;
      }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1112 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 1120 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 1127 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 1129 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 1157 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 1160 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1220 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.posFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_POS)));
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 1227 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_POS);
	driver.curPredicate = (yyval.p_POS);
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 1231 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_POS);
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 1243 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 1247 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 1256 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(4) - (1)].p_listModifier) == LIST_exact) {
	    (yyval.p_POS) = driver.createBNode();
	    const POS* tail = (yyval.p_POS);
	    ProductionVector<const POS*>* members = (yysemantic_stack_[(4) - (3)].p_POSs);
	    const URI* first = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#first");
	    const URI* rest = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#rest");
	    const POS* nil = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil");
	    driver.ensureBasicGraphPattern();
	    for (unsigned i = 0; i < members->size(); i++) {
		driver.curBGP->addTriplePattern(driver.posFactory->getTriple(tail, first, members->at(i)));
		const POS* nextTail = i == members->size()-1 ? nil : driver.createBNode();
		driver.curBGP->addTriplePattern(driver.posFactory->getTriple(tail, rest, nextTail));
		tail = nextTail;
	    }
	    members->clear();
	    delete members;
	} else {
	    error(*(yylocation_stack_.end()), "unsupported function");
	}
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 1281 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 1284 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 1287 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 1290 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 1293 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 1300 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 1308 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSs) = new ProductionVector<const POS*>();
	(yyval.p_POSs)->push_back((yysemantic_stack_[(1) - (1)].p_POS));
    }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 1313 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSs)->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = (yysemantic_stack_[(2) - (1)].p_POSs);
    }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 1325 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 1332 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 1335 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 1346 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 1349 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 1352 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 1355 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 1359 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 1370 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 1379 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 1386 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 1389 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 1397 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 1406 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 1413 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 1416 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 1428 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_BooleanComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_BooleanComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_BooleanComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 1439 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 1442 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 1445 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 1448 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 1451 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yyval.p_BooleanComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 1454 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 1461 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = NULL;
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 1474 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 1483 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 1486 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 1489 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 1492 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 1499 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 1502 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 1510 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 1519 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 1522 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 1529 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 1532 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 1539 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 1542 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 1545 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 1555 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 1558 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 1561 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 1564 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 1570 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 1576 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-str"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 1579 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-lang"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 1582 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-langMatches"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 1585 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-datatype"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 1588 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-bound"), new POSExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 1591 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sameTerm"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 1594 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 1597 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 1600 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isBlank"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 1603 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isLiteral"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 1611 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-regex"), (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 1618 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 1625 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new POSExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 1635 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 1643 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 1651 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 1658 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 1662 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 1670 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 2231 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  SPARQLfedParser::yysyntax_error_ (int yystate, int tok)
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
  const short int SPARQLfedParser::yypact_ninf_ = -263;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        16,   -56,    43,   269,  -263,  -263,  -263,  -263,    13,    20,
      20,    47,    73,    56,    56,    95,    46,    62,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,    72,  -263,    90,    63,  -263,  -263,
    -263,  -263,  -263,  -263,     2,  -263,  -263,    47,  -263,  -263,
    -263,    47,    47,  -263,  -263,  -263,     0,  -263,  -263,  -263,
    -263,  -263,   146,  -263,  -263,  -263,  -263,     9,     9,  -263,
    -263,    20,  -263,    71,   433,    15,    15,    73,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,    48,  -263,  -263,   433,     9,
    -263,     7,    26,  -263,  -263,    82,    22,  -263,   363,    48,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,    78,  -263,
    -263,  -263,  -263,    89,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,   -62,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,   106,  -263,   119,    82,    82,    47,  -263,  -263,  -263,
    -263,  -263,   149,  -263,   123,  -263,  -263,  -263,    13,   141,
    -263,  -263,   -24,   139,   143,   433,  -263,  -263,   139,   527,
     139,    47,  -263,  -263,  -263,  -263,  -263,   433,  -263,  -263,
    -263,  -263,  -263,   226,   107,   108,  -263,  -263,   156,   162,
     101,    82,  -263,   158,  -263,  -263,   144,   527,  -263,  -263,
     155,   193,  -263,  -263,  -263,  -263,  -263,  -263,   457,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,   610,   161,   164,   167,
     173,   175,   176,   178,   179,   181,   183,   184,   226,  -263,
     187,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,   -25,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,   315,   155,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,   433,
     146,  -263,  -263,   646,   646,   646,  -263,   189,  -263,  -263,
    -263,  -263,   314,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,   -25,   610,   610,   610,   610,    48,   610,
     610,   610,   610,   610,   610,  -263,  -263,   610,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,   433,    63,    27,   186,   180,
    -263,  -263,  -263,  -263,  -263,  -263,   192,   195,   610,   610,
     610,   610,   610,   610,  -263,  -263,   248,    -6,  -263,  -263,
     205,   206,   208,   216,   217,   213,   221,   222,   223,   228,
     224,  -263,   146,   146,    63,    63,  -263,  -263,  -263,  -263,
    -263,   139,  -263,   527,  -263,    20,   610,  -263,   610,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,   610,   610,  -263,  -263,
    -263,   610,   610,  -263,  -263,  -263,   610,  -263,  -263,   610,
    -263,  -263,  -263,  -263,   610,  -263,  -263,    63,  -263,  -263,
     229,   668,  -263,  -263,   527,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,   235,   237,   233,    24,    63,  -263,  -263,
    -263,  -263,  -263,   551,  -263,  -263,  -263,  -263,   610,  -263,
     245,  -263,  -263,  -263,    63,  -263,  -263,  -263,  -263,  -263
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        11,     0,     0,     0,    13,    12,    15,     1,    48,     0,
       0,     0,    87,    96,    96,    26,     0,     0,    20,     2,
       7,     3,    20,     4,     5,     6,     8,    75,    80,    81,
      77,    76,    78,    79,    10,    49,     0,     0,   124,    84,
      82,   314,   317,   316,    93,    90,   315,     0,    86,    88,
      97,     0,     0,    24,    25,    27,     0,   172,    20,    37,
     221,   222,    36,    20,    34,   219,   220,    48,    48,    16,
      14,     0,   110,    50,   115,    38,    38,     0,    94,    89,
      91,    99,    98,    95,    31,    30,    23,    28,   174,    48,
      35,    38,     0,    21,    40,    53,     0,     9,   115,     0,
      47,    51,   206,   207,   208,   209,   210,   203,   308,   309,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   310,
     312,   311,   313,   318,   319,   228,   130,   116,   134,   182,
     202,   201,   212,     0,   180,   217,   218,   224,   225,   296,
     297,   298,   226,   294,   223,   227,    85,    39,    83,    92,
      29,     0,   175,   178,    53,    53,     0,    41,    42,    43,
      44,    46,     0,    19,    55,    54,    17,   112,    48,     0,
     113,   122,     0,     0,   126,   115,   135,   132,   192,   211,
       0,     0,   292,   293,   295,   290,   173,   174,   179,   176,
      32,    33,    45,     0,     0,     0,    52,    56,    69,    71,
       0,    53,   111,   114,   100,   200,     0,   211,   199,   125,
     119,     0,   131,   133,   193,   183,   191,   216,   211,   213,
     215,   181,   291,   177,    62,    63,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    57,    58,
       0,    60,    61,    65,   164,    66,   162,   163,   283,     0,
      73,    74,    67,    70,    68,    72,    18,    22,   147,   151,
     141,   144,     0,   119,   123,   117,   136,   137,   139,   140,
     138,   155,   118,   102,   204,   189,   196,   198,   120,   115,
       0,   205,   214,     0,     0,     0,   271,     0,   229,   232,
     236,   238,   246,   248,   254,   259,   264,   265,   266,   267,
     268,   269,   270,   288,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    59,    64,     0,   166,   165,
     148,   152,   142,   145,   161,   115,     0,     0,   184,   194,
     129,   127,   262,   263,   261,   272,   230,   234,     0,     0,
       0,     0,     0,     0,   247,   239,   249,   256,   289,   287,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   167,     0,     0,     0,     0,   121,   159,   101,   104,
     103,   186,   190,   211,   197,     0,     0,   233,     0,   237,
     240,   241,   242,   243,   244,   245,     0,     0,   255,   252,
     253,     0,     0,   260,   273,   274,     0,   276,   277,     0,
     279,   280,   281,   282,     0,   170,   149,     0,   143,   146,
     156,     0,   187,   188,   211,   195,   128,   231,   235,   250,
     251,   257,   258,     0,     0,   285,     0,     0,   153,   157,
     160,   107,   108,     0,   106,   185,   275,   278,     0,   286,
       0,   168,   171,   150,     0,   105,   109,   169,   284,   158
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,     1,  -263,   190,  -263,  -263,   207,  -263,  -263,
    -263,  -263,  -263,   -49,  -263,  -263,  -263,  -263,  -263,   133,
       3,  -263,  -263,  -129,  -263,  -263,  -263,  -263,    67,  -263,
    -263,  -263,  -263,  -263,  -263,   113,   109,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
     301,  -263,   239,  -263,  -263,  -263,  -263,  -263,  -116,  -263,
    -214,  -263,  -263,  -263,   -90,  -263,    55,  -263,  -263,    -9,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
      60,  -263,    23,  -263,  -103,  -263,  -263,  -263,   140,  -263,
    -263,  -263,   -86,  -263,  -263,   -89,  -263,  -263,  -263,  -263,
    -263,  -263,   -85,  -263,  -263,   -45,   -34,  -172,  -263,  -263,
    -263,  -263,  -263,  -263,  -158,  -162,   -14,     5,  -263,  -178,
    -263,  -263,  -263,   -38,  -263,  -263,   -39,  -263,  -263,  -263,
      85,  -263,  -263,  -263,  -262,  -263,  -263,  -233,  -111,  -154,
    -184,  -263,  -263,  -263,  -263,   -70,  -263,  -263,  -263,   -69,
    -263,    -3,     8,   -64,  -263,   -11,  -263,  -263
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,    19,    20,     3,     4,    34,     5,    70,    96,
     200,    21,    67,   167,    22,    55,    56,    85,    86,    23,
      24,    62,    63,   146,    25,    93,   157,   158,   159,   160,
     147,    37,   100,   163,   164,   196,   165,   238,   239,   240,
     241,   242,   197,   252,   254,   198,   199,    26,    27,    28,
      76,    29,    75,    30,    48,    31,    44,    78,    79,    32,
      51,    33,    49,   101,   273,   327,   370,   411,   432,   433,
      73,    98,   169,   170,   126,   263,   279,   264,   203,    39,
      74,   210,   211,   375,   212,   174,   127,   176,   177,   265,
     266,   322,   364,   267,   323,   365,   268,   320,   362,   427,
     269,   321,   363,   270,   271,   326,   430,   444,   410,   272,
     243,   244,   319,   405,   439,   426,    58,    88,   151,   152,
     188,   189,   128,   180,   178,   206,   412,   413,   372,   328,
     215,   216,   275,   374,   329,   276,   207,   129,   130,   173,
     131,   132,   133,   218,   277,   134,   208,   286,   136,   287,
     288,   377,   336,   289,   379,   337,   290,   291,   344,   345,
     292,   293,   388,   346,   294,   393,   347,   295,   296,   297,
     298,   248,   440,   299,   349,   300,   183,   184,   185,   301,
     139,   140,   141,   302,   143,   303,    46,   145
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SPARQLfedParser::yytable_ninf_ = -212;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        45,    40,   153,    64,   137,   138,    66,   217,   171,   247,
     142,    36,    77,   204,   391,   181,   317,   220,   137,   138,
      84,   219,    65,    68,   142,   190,   191,   148,   137,   138,
      92,     1,    92,    80,   142,   217,    81,     6,   182,   246,
      82,    83,   155,     7,   -48,   220,   217,    35,    90,    35,
     156,    66,   -48,    35,   247,    35,   220,    38,   392,    89,
     282,    87,    97,   144,    91,   368,   441,    65,   369,    50,
      94,    95,   257,   438,    60,    61,   318,   144,   247,   135,
      47,   161,    59,    57,   246,   213,   316,   144,    69,   214,
     150,   221,   154,   135,    71,    41,    42,    43,    60,    61,
      72,   153,    99,   135,    87,   137,   138,   162,   246,   137,
     138,   142,   367,    53,    54,   142,   166,   137,   138,    41,
      42,    43,   175,   142,   419,   420,   350,   351,   352,   353,
     179,   355,   356,   357,   358,   359,   360,   137,   138,   361,
      41,    42,    43,   142,   186,   161,    60,    61,   137,   138,
     408,   409,   194,   195,   142,    41,    42,    43,   421,   422,
      60,    61,    66,   187,   144,   258,   259,    66,   144,    66,
     222,   201,   332,   333,   334,   193,   144,   150,    65,   202,
     135,   209,   249,    65,   135,    65,   195,   250,   251,   330,
     205,   194,   135,   428,   256,  -154,   144,   274,   245,   278,
     280,   217,   304,   260,   261,   305,   262,   144,   306,   137,
     138,   220,   135,   443,   307,   142,   308,   309,   423,   310,
     311,   424,   312,   135,   313,   314,   425,   249,   226,   373,
     449,   335,    41,    42,    43,   366,   371,    60,    61,    41,
      42,    43,   217,   245,    60,    61,   376,   394,   395,   434,
     378,   249,   220,   224,   225,   137,   138,   396,   397,   398,
     447,   142,   399,   400,   401,   402,   331,   226,   144,    66,
     403,   434,     8,   404,     9,    10,   429,   436,    11,   437,
      12,    13,   438,    14,   135,    65,    15,   448,   168,   192,
      16,    17,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   137,   138,   315,   172,   253,    18,   142,
     386,   387,   255,   354,   144,    52,   149,   446,   325,    41,
      42,    43,   324,   442,    60,    61,   348,   223,   415,   435,
     135,   113,   114,   115,   116,   117,   118,   414,   417,   418,
       0,   137,   138,   389,   137,   138,     0,   142,   406,   407,
     142,    66,    66,     0,   390,     0,   226,     0,     0,     0,
      66,     0,   144,   137,   138,     0,   416,    65,    65,   142,
     338,   339,   340,   341,   342,   343,    65,     0,   135,     0,
      15,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     0,     0,     0,   102,   103,   104,   105,   106,
     144,     0,     0,   144,  -211,     0,     0,     0,    41,    42,
      43,     0,     0,     0,     0,   107,   135,     0,     0,   135,
       0,     0,   144,   380,   381,   382,   383,   384,   385,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   135,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    41,    42,    43,   123,
     124,    60,    61,     0,   125,   102,   103,   104,   105,   106,
       0,     0,     0,     0,  -211,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   107,     0,     0,     0,   102,
     103,   104,   105,   106,     0,     0,     0,     0,     0,   281,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   107,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    41,    42,    43,   123,
     124,    60,    61,     0,   125,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      41,    42,    43,   123,   124,    60,    61,     0,   125,   102,
     103,   104,   105,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   445,   431,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      41,    42,    43,   123,   124,    60,    61,     0,   125,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,    41,    42,    43,   123,   124,    60,
      61,   226,   125,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   283,   284,     0,   285,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   226,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    41,    42,    43,     0,     0,    60,    61,
       0,   431,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    41,
      42,    43,     0,     0,    60,    61,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,    41,    42,    43,   123,   124,    60,    61,     0,   125
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        11,    10,    88,    17,    74,    74,    17,   179,    98,   193,
      74,     8,    10,    37,    20,    77,    41,   179,    88,    88,
      20,   179,    17,    22,    88,   154,   155,    76,    98,    98,
      23,    15,    23,    44,    98,   207,    47,    93,   100,   193,
      51,    52,    91,     0,    37,   207,   218,    40,    62,    40,
      24,    62,    37,    40,   238,    40,   218,    37,    64,    58,
     218,    56,    71,    74,    63,    38,    42,    62,    41,    13,
      67,    68,   201,    49,    98,    99,   101,    88,   262,    74,
       7,    92,    20,    37,   238,   175,   240,    98,    16,   178,
      85,   180,    89,    88,     4,    93,    94,    95,    98,    99,
      37,   187,    31,    98,    99,   175,   175,    25,   262,   179,
     179,   175,   326,    18,    19,   179,    94,   187,   187,    93,
      94,    95,    44,   187,   386,   387,   304,   305,   306,   307,
      41,   309,   310,   311,   312,   313,   314,   207,   207,   317,
      93,    94,    95,   207,    38,   156,    98,    99,   218,   218,
     364,   365,    29,    30,   218,    93,    94,    95,   391,   392,
      98,    99,   173,    44,   175,     7,     8,   178,   179,   180,
     181,   168,   283,   284,   285,    26,   187,   172,   173,    38,
     175,    38,   193,   178,   179,   180,    30,    80,    80,   279,
      51,    29,   187,   407,    93,    37,   207,    53,   193,    44,
       7,   373,    41,    45,    46,    41,    48,   218,    41,   279,
     279,   373,   207,   427,    41,   279,    41,    41,   396,    41,
      41,   399,    41,   218,    41,    41,   404,   238,    41,    49,
     444,    42,    93,    94,    95,   325,    50,    98,    99,    93,
      94,    95,   414,   238,    98,    99,    54,    42,    42,   411,
      55,   262,   414,    27,    28,   325,   325,    49,    42,    42,
     438,   325,    49,    42,    42,    42,   280,    41,   279,   280,
      42,   433,     3,    49,     5,     6,    47,    42,     9,    42,
      11,    12,    49,    14,   279,   280,    17,    42,    98,   156,
      21,    22,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,   373,   373,   238,    99,   198,    39,   373,
      62,    63,   199,   308,   325,    14,    77,   433,   263,    93,
      94,    95,   262,   426,    98,    99,   303,   187,   373,   414,
     325,    83,    84,    85,    86,    87,    88,   371,   376,   378,
      -1,   411,   411,   346,   414,   414,    -1,   411,   362,   363,
     414,   362,   363,    -1,   346,    -1,    41,    -1,    -1,    -1,
     371,    -1,   373,   433,   433,    -1,   375,   362,   363,   433,
      56,    57,    58,    59,    60,    61,   371,    -1,   373,    -1,
      17,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    32,    33,    34,    35,    36,
     411,    -1,    -1,   414,    41,    -1,    -1,    -1,    93,    94,
      95,    -1,    -1,    -1,    -1,    52,   411,    -1,    -1,   414,
      -1,    -1,   433,   338,   339,   340,   341,   342,   343,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   433,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,    -1,   101,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,    -1,   101,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,   101,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,   101,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,    41,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    -1,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    41,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    -1,    -1,    98,    99,
      -1,    43,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    -1,    -1,    98,    99,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,    -1,   101
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    15,   103,   106,   107,   109,    93,     0,     3,     5,
       6,     9,    11,    12,    14,    17,    21,    22,    39,   104,
     105,   113,   116,   121,   122,   126,   149,   150,   151,   153,
     155,   157,   161,   163,   108,    40,   132,   133,    37,   181,
     181,    93,    94,    95,   158,   287,   288,     7,   156,   164,
      13,   162,   162,    18,    19,   117,   118,    37,   218,    20,
      98,    99,   123,   124,   248,   249,   287,   114,   114,    16,
     110,     4,    37,   172,   182,   154,   152,    10,   159,   160,
     287,   287,   287,   287,    20,   119,   120,   249,   219,   114,
     248,   114,    23,   127,   132,   132,   111,   181,   173,    31,
     134,   165,    32,    33,    34,    35,    36,    52,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    96,    97,   101,   176,   188,   224,   239,
     240,   242,   243,   244,   247,   249,   250,   277,   281,   282,
     283,   284,   285,   286,   287,   289,   125,   132,   125,   164,
     249,   220,   221,   224,   132,   125,    24,   128,   129,   130,
     131,   287,    25,   135,   136,   138,    94,   115,   116,   174,
     175,   176,   119,   241,   187,    44,   189,   190,   226,    41,
     225,    77,   100,   278,   279,   280,    38,    44,   222,   223,
     135,   135,   131,    26,    29,    30,   137,   144,   147,   148,
     112,   132,    38,   180,    37,    51,   227,   238,   248,    38,
     183,   184,   186,   176,   227,   232,   233,   239,   245,   246,
     247,   227,   287,   220,    27,    28,    41,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,   139,   140,
     141,   142,   143,   212,   213,   249,   271,   272,   273,   287,
      80,    80,   145,   148,   146,   147,    93,   135,     7,     8,
      45,    46,    48,   177,   179,   191,   192,   195,   198,   202,
     205,   206,   211,   166,    53,   234,   237,   246,    44,   178,
       7,    42,   246,    62,    63,    65,   249,   251,   252,   255,
     258,   259,   262,   263,   266,   269,   270,   271,   272,   275,
     277,   281,   285,   287,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,   140,   271,    41,   101,   214,
     199,   203,   193,   196,   212,   178,   207,   167,   231,   236,
     176,   248,   270,   270,   270,    42,   254,   257,    56,    57,
      58,    59,    60,    61,   260,   261,   265,   268,   214,   276,
     251,   251,   251,   251,   249,   251,   251,   251,   251,   251,
     251,   251,   200,   204,   194,   197,   176,   172,    38,    41,
     168,    50,   230,    49,   235,   185,    54,   253,    55,   256,
     262,   262,   262,   262,   262,   262,    62,    63,   264,   283,
     284,    20,    64,   267,    42,    42,    49,    42,    42,    49,
      42,    42,    42,    42,    49,   215,   248,   248,   172,   172,
     210,   169,   228,   229,   238,   237,   181,   255,   258,   266,
     266,   269,   269,   251,   251,   251,   217,   201,   172,    47,
     208,    43,   170,   171,   247,   234,    42,    42,    49,   216,
     274,    42,   216,   172,   209,    42,   170,   251,    42,   172
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  SPARQLfedParser::yytoken_number_[] =
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
     355,   356
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  SPARQLfedParser::yyr1_[] =
  {
         0,   102,   103,   104,   104,   104,   104,   104,   104,   105,
     106,   107,   107,   108,   108,   109,   111,   112,   110,   113,
     114,   114,   115,   116,   117,   117,   118,   118,   119,   119,
     120,   120,   121,   122,   123,   123,   124,   124,   125,   125,
     126,   127,   128,   128,   129,   130,   131,   132,   133,   133,
     134,   134,   135,   136,   136,   137,   137,   138,   139,   139,
     140,   140,   141,   141,   142,   143,   143,   144,   144,   145,
     145,   146,   146,   147,   148,   149,   149,   149,   149,   149,
     150,   150,   152,   151,   154,   153,   155,   156,   156,   157,
     158,   158,   159,   160,   160,   161,   162,   162,   163,   164,
     166,   165,   167,   167,   169,   168,   170,   170,   171,   171,
     173,   172,   174,   174,   175,   176,   176,   177,   177,   178,
     178,   179,   180,   180,   182,   181,   184,   185,   183,   186,
     187,   187,   188,   189,   190,   190,   191,   191,   191,   191,
     191,   193,   194,   192,   196,   197,   195,   199,   200,   201,
     198,   203,   204,   202,   206,   207,   205,   209,   208,   210,
     210,   211,   212,   212,   212,   213,   214,   215,   214,   216,
     217,   217,   219,   218,   220,   220,   221,   222,   223,   223,
     225,   224,   226,   224,   227,   228,   229,   229,   230,   231,
     231,   232,   233,   233,   234,   235,   236,   236,   237,   238,
     238,   239,   239,   241,   240,   242,   243,   243,   243,   243,
     243,   244,   244,   245,   245,   246,   246,   247,   247,   248,
     248,   249,   249,   250,   250,   250,   250,   250,   250,   251,
     252,   253,   254,   254,   255,   256,   257,   257,   258,   259,
     260,   260,   260,   260,   260,   260,   261,   261,   262,   263,
     264,   264,   264,   264,   265,   265,   266,   267,   267,   268,
     268,   269,   269,   269,   269,   270,   270,   270,   270,   270,
     270,   270,   271,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   273,   274,   274,   275,   276,   276,
     277,   278,   279,   279,   280,   280,   281,   281,   281,   282,
     282,   282,   283,   283,   283,   284,   284,   284,   285,   285,
     286,   286,   286,   286,   287,   287,   288,   288,   289,   289
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SPARQLfedParser::yyr2_[] =
  {
         0,     2,     2,     1,     1,     1,     1,     1,     1,     4,
       2,     0,     1,     0,     2,     2,     0,     0,     5,     4,
       0,     2,     3,     3,     1,     1,     0,     1,     1,     2,
       1,     1,     5,     5,     1,     2,     1,     1,     0,     1,
       3,     2,     1,     1,     1,     2,     1,     3,     0,     1,
       0,     1,     2,     0,     1,     0,     1,     3,     1,     2,
       1,     1,     1,     1,     2,     1,     1,     2,     2,     0,
       1,     0,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     0,     4,     2,     0,     1,     3,
       1,     2,     2,     0,     1,     3,     0,     1,     3,     2,
       0,     6,     0,     2,     0,     4,     1,     1,     1,     2,
       0,     4,     1,     1,     2,     0,     1,     1,     1,     0,
       1,     3,     0,     2,     0,     5,     0,     0,     5,     3,
       0,     2,     2,     2,     0,     1,     1,     1,     1,     1,
       1,     0,     0,     4,     0,     0,     4,     0,     0,     0,
       6,     0,     0,     5,     0,     0,     4,     0,     3,     0,
       2,     2,     1,     1,     1,     2,     1,     0,     5,     2,
       0,     2,     0,     4,     0,     1,     2,     2,     0,     1,
       0,     3,     0,     3,     3,     2,     0,     1,     2,     0,
       2,     1,     0,     1,     2,     2,     0,     2,     1,     1,
       1,     1,     1,     0,     4,     4,     1,     1,     1,     1,
       1,     0,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     0,     2,     2,     2,     0,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     0,     1,     1,     2,
       2,     2,     1,     1,     0,     2,     2,     2,     2,     0,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     4,     6,     4,     4,     6,     4,
       4,     4,     4,     1,     7,     0,     1,     2,     0,     1,
       2,     2,     1,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const SPARQLfedParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "IT_REPLACE", "IT_WITH",
  "IT_DELETE", "IT_INSERT", "IT_GRAPH", "IT_SERVICE", "IT_LOAD", "IT_INTO",
  "IT_CLEAR", "IT_CREATE", "IT_SILENT", "IT_DROP", "IT_BASE", "IT_PREFIX",
  "IT_SELECT", "IT_DISTINCT", "IT_REDUCED", "GT_TIMES", "IT_CONSTRUCT",
  "IT_DESCRIBE", "IT_FROM", "IT_NAMED", "IT_ORDER", "IT_BY", "IT_ASC",
  "IT_DESC", "IT_LIMIT", "IT_OFFSET", "IT_BINDINGS", "IT_MEMBERS",
  "IT_STARTS", "IT_ENDS", "IT_ANY", "IT_UNORDERED", "GT_LCURLEY",
  "GT_RCURLEY", "IT_ASK", "IT_WHERE", "GT_LPAREN", "GT_RPAREN", "IT_NULL",
  "GT_DOT", "IT_OPTIONAL", "IT_MINUS", "IT_UNION", "IT_FILTER", "GT_COMMA",
  "GT_SEMI", "IT_a", "GT_LBRACKET", "GT_RBRACKET", "GT_OR", "GT_AND",
  "GT_EQUAL", "GT_NEQUAL", "GT_LT", "GT_GT", "GT_LE", "GT_GE", "GT_PLUS",
  "GT_MINUS", "GT_DIVIDE", "GT_NOT", "IT_STR", "IT_LANG", "IT_LANGMATCHES",
  "IT_DATATYPE", "IT_BOUND", "IT_sameTerm", "IT_isIRI", "IT_isURI",
  "IT_isBLANK", "IT_isLITERAL", "IT_REGEX", "GT_DTYPE", "IT_true",
  "IT_false", "INTEGER", "DECIMAL", "DOUBLE", "INTEGER_POSITIVE",
  "DECIMAL_POSITIVE", "DOUBLE_POSITIVE", "INTEGER_NEGATIVE",
  "DECIMAL_NEGATIVE", "DOUBLE_NEGATIVE", "STRING_LITERAL1",
  "STRING_LITERAL_LONG1", "STRING_LITERAL2", "STRING_LITERAL_LONG2",
  "IRI_REF", "PNAME_NS", "PNAME_LN", "BLANK_NODE_LABEL", "ANON", "VAR1",
  "VAR2", "LANGTAG", "NIL", "$accept", "Query",
  "_O_QSelectQuery_E_Or_QConstructQuery_E_Or_QDescribeQuery_E_Or_QAskQuery_E_Or_QReplace_E_Or_QUpdate_E_C",
  "Replace", "Prologue", "_QBaseDecl_E_Opt", "_QPrefixDecl_E_Star",
  "BaseDecl", "PrefixDecl", "$@1", "$@2", "SelectQuery",
  "_QDatasetClause_E_Star", "SubSelect", "Project",
  "_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C",
  "_Q_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C_E_Opt", "_QVar_E_Plus",
  "_O_QVar_E_Plus_Or_QGT_TIMES_E_C", "ConstructQuery", "DescribeQuery",
  "_QVarOrIRIref_E_Plus", "_O_QVarOrIRIref_E_Plus_Or_QGT_TIMES_E_C",
  "_QWhereClause_E_Opt", "AskQuery", "DatasetClause",
  "_O_QDefaultGraphClause_E_Or_QNamedGraphClause_E_C",
  "DefaultGraphClause", "NamedGraphClause", "SourceSelector",
  "WhereClause", "_QIT_WHERE_E_Opt", "_QBindingClause_E_Opt",
  "SolutionModifier", "_QOrderClause_E_Opt", "_QLimitOffsetClauses_E_Opt",
  "OrderClause", "_QOrderCondition_E_Plus", "OrderCondition",
  "_O_QIT_ASC_E_Or_QIT_DESC_E_C",
  "_O_QIT_ASC_E_Or_QIT_DESC_E_S_QBrackettedExpression_E_C",
  "_O_QConstraint_E_Or_QVar_E_C", "LimitOffsetClauses",
  "_QOffsetClause_E_Opt", "_QLimitClause_E_Opt", "LimitClause",
  "OffsetClause", "Update", "Modify", "Insert", "@3", "Delete", "@4",
  "Clear", "_QGraphRef_E_Opt", "Load", "_QIRIref_E_Plus",
  "_O_QIT_INTO_E_S_QGraphRef_E_C", "_Q_O_QIT_INTO_E_S_QGraphRef_E_C_E_Opt",
  "Drop", "_QIT_SILENT_E_Opt", "Create", "GraphRef", "BindingClause",
  "$@5", "_QBinding_E_Star", "Binding", "$@6",
  "_O_QVarOrTerm_E_Or_QIT_NULL_E_C",
  "_Q_O_QVarOrTerm_E_Or_QIT_NULL_E_C_E_Plus", "GroupGraphPattern", "$@7",
  "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C", "GroupGraphPatternSub",
  "_QTriplesBlock_E_Opt", "_O_QGraphPatternNotTriples_E_Or_QFilter_E_C",
  "_QGT_DOT_E_Opt",
  "_O_QGraphPatternNotTriples_E_Or_QFilter_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_Or_QFilter_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "GraphTemplate", "$@8",
  "_O_QIT_GRAPH_E_S_QVarOrIRIref_E_S_QGraphTemplate_E_C", "@9", "@10",
  "_O_QIT_GRAPH_E_S_QVarOrIRIref_E_S_QGraphTemplate_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QIT_GRAPH_E_S_QVarOrIRIref_E_S_QGraphTemplate_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "OptionalGraphPattern", "@11", "@12", "MinusGraphPattern", "@13", "@14",
  "GraphGraphPattern", "@15", "@16", "@17", "ServiceGraphPattern", "@18",
  "@19", "GroupOrUnionGraphPattern", "@20", "@21",
  "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@22",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "$@23",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ConstructTemplate", "$@24",
  "_QConstructTriples_E_Opt", "ConstructTriples",
  "_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C_E_Opt", "TriplesSameSubject",
  "$@25", "$@26", "PropertyListNotEmpty", "_O_QVerb_E_S_QObjectList_E_C",
  "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "Verb", "TriplesNode", "BlankNodePropertyList", "@27",
  "Generator",
  "_O_QIT_MEMBERS_E_Or_QIT_STARTS_E_Or_QIT_ENDS_E_Or_QIT_ANY_E_Or_QIT_UNORDERED_E_C",
  "_Q_O_QIT_MEMBERS_E_Or_QIT_STARTS_E_Or_QIT_ENDS_E_Or_QIT_ANY_E_Or_QIT_UNORDERED_E_C_E_Opt",
  "_QGraphNode_E_Plus", "GraphNode", "VarOrTerm", "VarOrIRIref", "Var",
  "GraphTerm", "Expression", "ConditionalOrExpression",
  "_O_QGT_OR_E_S_QConditionalAndExpression_E_C",
  "_Q_O_QGT_OR_E_S_QConditionalAndExpression_E_C_E_Star",
  "ConditionalAndExpression", "_O_QGT_AND_E_S_QValueLogical_E_C",
  "_Q_O_QGT_AND_E_S_QValueLogical_E_C_E_Star", "ValueLogical",
  "RelationalExpression",
  "_O_QGT_EQUAL_E_S_QNumericExpression_E_Or_QGT_NEQUAL_E_S_QNumericExpression_E_Or_QGT_LT_E_S_QNumericExpression_E_Or_QGT_GT_E_S_QNumericExpression_E_Or_QGT_LE_E_S_QNumericExpression_E_Or_QGT_GE_E_S_QNumericExpression_E_C",
  "_Q_O_QGT_EQUAL_E_S_QNumericExpression_E_Or_QGT_NEQUAL_E_S_QNumericExpression_E_Or_QGT_LT_E_S_QNumericExpression_E_Or_QGT_GT_E_S_QNumericExpression_E_Or_QGT_LE_E_S_QNumericExpression_E_Or_QGT_GE_E_S_QNumericExpression_E_C_E_Opt",
  "NumericExpression", "AdditiveExpression",
  "_O_QGT_PLUS_E_S_QMultiplicativeExpression_E_Or_QGT_MINUS_E_S_QMultiplicativeExpression_E_Or_QNumericLiteralPositive_E_Or_QNumericLiteralNegative_E_C",
  "_Q_O_QGT_PLUS_E_S_QMultiplicativeExpression_E_Or_QGT_MINUS_E_S_QMultiplicativeExpression_E_Or_QNumericLiteralPositive_E_Or_QNumericLiteralNegative_E_C_E_Star",
  "MultiplicativeExpression",
  "_O_QGT_TIMES_E_S_QUnaryExpression_E_Or_QGT_DIVIDE_E_S_QUnaryExpression_E_C",
  "_Q_O_QGT_TIMES_E_S_QUnaryExpression_E_Or_QGT_DIVIDE_E_S_QUnaryExpression_E_C_E_Star",
  "UnaryExpression", "PrimaryExpression", "BrackettedExpression",
  "BuiltInCall", "RegexExpression",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Opt", "IRIrefOrFunction",
  "_QArgList_E_Opt", "RDFLiteral", "_O_QGT_DTYPE_E_S_QIRIref_E_C",
  "_O_QLANGTAG_E_Or_QGT_DTYPE_E_S_QIRIref_E_C",
  "_Q_O_QLANGTAG_E_Or_QGT_DTYPE_E_S_QIRIref_E_C_E_Opt", "NumericLiteral",
  "NumericLiteralUnsigned", "NumericLiteralPositive",
  "NumericLiteralNegative", "BooleanLiteral", "String", "IRIref",
  "PrefixedName", "BlankNode", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const SPARQLfedParser::rhs_number_type
  SPARQLfedParser::yyrhs_[] =
  {
       103,     0,    -1,   106,   104,    -1,   113,    -1,   121,    -1,
     122,    -1,   126,    -1,   105,    -1,   149,    -1,     3,   132,
       4,   181,    -1,   107,   108,    -1,    -1,   109,    -1,    -1,
     108,   110,    -1,    15,    93,    -1,    -1,    -1,    16,   111,
      94,   112,    93,    -1,   116,   114,   132,   135,    -1,    -1,
     114,   127,    -1,   116,   132,   135,    -1,    17,   118,   120,
      -1,    18,    -1,    19,    -1,    -1,   117,    -1,   249,    -1,
     119,   249,    -1,   119,    -1,    20,    -1,    21,   218,   114,
     132,   135,    -1,    22,   124,   114,   125,   135,    -1,   248,
      -1,   123,   248,    -1,   123,    -1,    20,    -1,    -1,   132,
      -1,    39,   114,   132,    -1,    23,   128,    -1,   129,    -1,
     130,    -1,   131,    -1,    24,   131,    -1,   287,    -1,   133,
     172,   134,    -1,    -1,    40,    -1,    -1,   165,    -1,   136,
     137,    -1,    -1,   138,    -1,    -1,   144,    -1,    25,    26,
     139,    -1,   140,    -1,   139,   140,    -1,   142,    -1,   143,
      -1,    27,    -1,    28,    -1,   141,   271,    -1,   212,    -1,
     249,    -1,   147,   145,    -1,   148,   146,    -1,    -1,   148,
      -1,    -1,   147,    -1,    29,    80,    -1,    30,    80,    -1,
     150,    -1,   157,    -1,   155,    -1,   161,    -1,   163,    -1,
     151,    -1,   153,    -1,    -1,     6,   181,   152,   125,    -1,
      -1,     5,   181,   154,   125,    -1,    11,   156,    -1,    -1,
     164,    -1,     9,   158,   160,    -1,   287,    -1,   158,   287,
      -1,    10,   164,    -1,    -1,   159,    -1,    14,   162,   287,
      -1,    -1,    13,    -1,    12,   162,   287,    -1,     7,   287,
      -1,    -1,    31,   119,    37,   166,   167,    38,    -1,    -1,
     167,   168,    -1,    -1,    41,   169,   171,    42,    -1,   247,
      -1,    43,    -1,   170,    -1,   171,   170,    -1,    -1,    37,
     173,   174,    38,    -1,   115,    -1,   175,    -1,   176,   180,
      -1,    -1,   188,    -1,   191,    -1,   211,    -1,    -1,    44,
      -1,   177,   178,   176,    -1,    -1,   180,   179,    -1,    -1,
      37,   182,   176,   187,    38,    -1,    -1,    -1,   184,     7,
     248,   185,   181,    -1,   183,   178,   176,    -1,    -1,   187,
     186,    -1,   224,   190,    -1,    44,   176,    -1,    -1,   189,
      -1,   192,    -1,   195,    -1,   205,    -1,   198,    -1,   202,
      -1,    -1,    -1,    45,   193,   194,   172,    -1,    -1,    -1,
      46,   196,   197,   172,    -1,    -1,    -1,    -1,     7,   199,
     200,   248,   201,   172,    -1,    -1,    -1,     8,   203,   204,
     248,   172,    -1,    -1,    -1,   206,   207,   172,   210,    -1,
      -1,    47,   209,   172,    -1,    -1,   210,   208,    -1,    48,
     212,    -1,   271,    -1,   272,    -1,   213,    -1,   287,   214,
      -1,   101,    -1,    -1,    41,   251,   215,   217,    42,    -1,
      49,   251,    -1,    -1,   217,   216,    -1,    -1,    37,   219,
     220,    38,    -1,    -1,   221,    -1,   224,   223,    -1,    44,
     220,    -1,    -1,   222,    -1,    -1,   247,   225,   227,    -1,
      -1,   239,   226,   232,    -1,   238,   234,   231,    -1,   238,
     234,    -1,    -1,   228,    -1,    50,   229,    -1,    -1,   231,
     230,    -1,   233,    -1,    -1,   227,    -1,   237,   236,    -1,
      49,   237,    -1,    -1,   236,   235,    -1,   246,    -1,   248,
      -1,    51,    -1,   242,    -1,   240,    -1,    -1,    52,   241,
     227,    53,    -1,   244,    41,   245,    42,    -1,    32,    -1,
      33,    -1,    34,    -1,    35,    -1,    36,    -1,    -1,   243,
      -1,   246,    -1,   245,   246,    -1,   247,    -1,   239,    -1,
     249,    -1,   250,    -1,   249,    -1,   287,    -1,    98,    -1,
      99,    -1,   287,    -1,   277,    -1,   281,    -1,   285,    -1,
     289,    -1,   101,    -1,   252,    -1,   255,   254,    -1,    54,
     255,    -1,    -1,   254,   253,    -1,   258,   257,    -1,    55,
     258,    -1,    -1,   257,   256,    -1,   259,    -1,   262,   261,
      -1,    56,   262,    -1,    57,   262,    -1,    58,   262,    -1,
      59,   262,    -1,    60,   262,    -1,    61,   262,    -1,    -1,
     260,    -1,   263,    -1,   266,   265,    -1,    62,   266,    -1,
      63,   266,    -1,   283,    -1,   284,    -1,    -1,   265,   264,
      -1,   269,   268,    -1,    20,   269,    -1,    64,   269,    -1,
      -1,   268,   267,    -1,    65,   270,    -1,    62,   270,    -1,
      63,   270,    -1,   270,    -1,   271,    -1,   272,    -1,   275,
      -1,   277,    -1,   281,    -1,   285,    -1,   249,    -1,    41,
     251,    42,    -1,    66,    41,   251,    42,    -1,    67,    41,
     251,    42,    -1,    68,    41,   251,    49,   251,    42,    -1,
      69,    41,   251,    42,    -1,    70,    41,   249,    42,    -1,
      71,    41,   251,    49,   251,    42,    -1,    72,    41,   251,
      42,    -1,    73,    41,   251,    42,    -1,    74,    41,   251,
      42,    -1,    75,    41,   251,    42,    -1,   273,    -1,    76,
      41,   251,    49,   251,   274,    42,    -1,    -1,   216,    -1,
     287,   276,    -1,    -1,   214,    -1,   286,   280,    -1,    77,
     287,    -1,   100,    -1,   278,    -1,    -1,   279,    -1,   282,
      -1,   283,    -1,   284,    -1,    80,    -1,    81,    -1,    82,
      -1,    83,    -1,    84,    -1,    85,    -1,    86,    -1,    87,
      -1,    88,    -1,    78,    -1,    79,    -1,    89,    -1,    91,
      -1,    90,    -1,    92,    -1,    93,    -1,   288,    -1,    95,
      -1,    94,    -1,    96,    -1,    97,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SPARQLfedParser::yyprhs_[] =
  {
         0,     0,     3,     6,     8,    10,    12,    14,    16,    18,
      23,    26,    27,    29,    30,    33,    36,    37,    38,    44,
      49,    50,    53,    57,    61,    63,    65,    66,    68,    70,
      73,    75,    77,    83,    89,    91,    94,    96,    98,    99,
     101,   105,   108,   110,   112,   114,   117,   119,   123,   124,
     126,   127,   129,   132,   133,   135,   136,   138,   142,   144,
     147,   149,   151,   153,   155,   158,   160,   162,   165,   168,
     169,   171,   172,   174,   177,   180,   182,   184,   186,   188,
     190,   192,   194,   195,   200,   201,   206,   209,   210,   212,
     216,   218,   221,   224,   225,   227,   231,   232,   234,   238,
     241,   242,   249,   250,   253,   254,   259,   261,   263,   265,
     268,   269,   274,   276,   278,   281,   282,   284,   286,   288,
     289,   291,   295,   296,   299,   300,   306,   307,   308,   314,
     318,   319,   322,   325,   328,   329,   331,   333,   335,   337,
     339,   341,   342,   343,   348,   349,   350,   355,   356,   357,
     358,   365,   366,   367,   373,   374,   375,   380,   381,   385,
     386,   389,   392,   394,   396,   398,   401,   403,   404,   410,
     413,   414,   417,   418,   423,   424,   426,   429,   432,   433,
     435,   436,   440,   441,   445,   449,   452,   453,   455,   458,
     459,   462,   464,   465,   467,   470,   473,   474,   477,   479,
     481,   483,   485,   487,   488,   493,   498,   500,   502,   504,
     506,   508,   509,   511,   513,   516,   518,   520,   522,   524,
     526,   528,   530,   532,   534,   536,   538,   540,   542,   544,
     546,   549,   552,   553,   556,   559,   562,   563,   566,   568,
     571,   574,   577,   580,   583,   586,   589,   590,   592,   594,
     597,   600,   603,   605,   607,   608,   611,   614,   617,   620,
     621,   624,   627,   630,   633,   635,   637,   639,   641,   643,
     645,   647,   649,   653,   658,   663,   670,   675,   680,   687,
     692,   697,   702,   707,   709,   717,   718,   720,   723,   724,
     726,   729,   732,   734,   736,   737,   739,   741,   743,   745,
     747,   749,   751,   753,   755,   757,   759,   761,   763,   765,
     767,   769,   771,   773,   775,   777,   779,   781,   783,   785
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   363,   363,   370,   371,   372,   373,   374,   375,   379,
     387,   391,   393,   397,   399,   403,   409,   411,   409,   421,
     428,   431,   442,   449,   457,   460,   467,   470,   475,   479,
     487,   490,   497,   505,   512,   516,   524,   527,   534,   537,
     542,   549,   556,   557,   561,   567,   573,   580,   587,   589,
     593,   596,   601,   608,   611,   616,   620,   625,   632,   636,
     644,   646,   654,   657,   665,   673,   674,   681,   685,   693,
     696,   701,   704,   708,   714,   720,   721,   722,   723,   724,
     728,   729,   733,   733,   742,   742,   751,   757,   760,   764,
     771,   774,   782,   789,   792,   796,   802,   805,   811,   817,
     824,   824,   834,   837,   845,   845,   855,   856,   863,   867,
     875,   875,   887,   888,   893,   897,   899,   904,   905,   909,
     911,   916,   920,   923,   928,   928,   938,   941,   938,   952,
     956,   958,   963,   968,   972,   975,   979,   980,   981,   982,
     983,   987,   989,   987,  1003,  1005,  1003,  1014,  1016,  1018,
    1014,  1029,  1031,  1029,  1041,  1044,  1041,  1054,  1054,  1068,
    1070,  1074,  1085,  1086,  1087,  1091,  1098,  1102,  1102,  1112,
    1118,  1120,  1127,  1127,  1135,  1137,  1142,  1147,  1151,  1153,
    1157,  1157,  1160,  1160,  1167,  1172,  1176,  1178,  1183,  1187,
    1189,  1194,  1198,  1200,  1205,  1210,  1214,  1216,  1220,  1227,
    1231,  1238,  1239,  1243,  1243,  1256,  1281,  1284,  1287,  1290,
    1293,  1300,  1303,  1308,  1313,  1320,  1321,  1325,  1328,  1332,
    1335,  1341,  1342,  1346,  1349,  1352,  1355,  1358,  1359,  1365,
    1370,  1379,  1386,  1389,  1397,  1406,  1413,  1416,  1423,  1428,
    1439,  1442,  1445,  1448,  1451,  1454,  1461,  1465,  1469,  1474,
    1483,  1486,  1489,  1492,  1499,  1502,  1510,  1519,  1522,  1529,
    1532,  1539,  1542,  1545,  1548,  1552,  1553,  1554,  1555,  1558,
    1561,  1564,  1570,  1576,  1579,  1582,  1585,  1588,  1591,  1594,
    1597,  1600,  1603,  1606,  1611,  1618,  1621,  1625,  1635,  1638,
    1643,  1651,  1658,  1662,  1670,  1674,  1678,  1679,  1680,  1684,
    1685,  1686,  1690,  1691,  1692,  1696,  1697,  1698,  1702,  1703,
    1707,  1708,  1709,  1710,  1714,  1715,  1719,  1720,  1724,  1725
  };

  // Print the state stack on the debug stream.
  void
  SPARQLfedParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  SPARQLfedParser::yy_reduce_print_ (int yyrule)
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
  SPARQLfedParser::token_number_type
  SPARQLfedParser::yytranslate_ (int t)
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
      95,    96,    97,    98,    99,   100,   101
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SPARQLfedParser::yyeof_ = 0;
  const int SPARQLfedParser::yylast_ = 769;
  const int SPARQLfedParser::yynnts_ = 188;
  const int SPARQLfedParser::yyempty_ = -2;
  const int SPARQLfedParser::yyfinal_ = 7;
  const int SPARQLfedParser::yyterror_ = 1;
  const int SPARQLfedParser::yyerrcode_ = 256;
  const int SPARQLfedParser::yyntokens_ = 102;

  const unsigned int SPARQLfedParser::yyuser_token_number_max_ = 356;
  const SPARQLfedParser::token_number_type SPARQLfedParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 3279 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 1731 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
 /*** Additional Code ***/

void w3c_sw::SPARQLfedParser::error(const SPARQLfedParser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

/* START Driver (@@ stand-alone would allow it to be shared with other parsers */

namespace w3c_sw {

    SPARQLfedDriver::SPARQLfedDriver (std::string baseURI, POSFactory* posFactory) : 
	YaccDriver(baseURI, posFactory), curSubject(NULL), curPredicate(NULL), 
	curBGP(NULL), curFilter(NULL), 
	curBindingClause(NULL), curBinding(NULL), curExprList(NULL), 
	curGraphName(NULL), root(NULL),  unnestTree(false)
{
}

    SPARQLfedDriver::~SPARQLfedDriver ()
{
}

bool SPARQLfedDriver::parse(IStreamContext& in)
{
    streamname = in.nameStr;

    SPARQLfedScanner scanner(this, in.p);
    scanner.set_debug(trace_scanning);
    lexer = &scanner;

    SPARQLfedParser parser(*this);
    parser.set_debug_level(trace_parsing);
    // !!! Clear out namespaces!
    ignorePrefixFlag = false;
    return (parser.parse());
}

} // namespace w3c_sw

/* END Driver */


