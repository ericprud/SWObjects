
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
#line 350 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

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
#line 365 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(2) - (2)].p_Operation);
    }
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 371 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Replace((yysemantic_stack_[(4) - (2)].p_WhereClause), driver.curOp);
	driver.curOp = NULL;
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 405 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 411 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 413 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 415 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 423 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Select((yysemantic_stack_[(5) - (2)].p_Project).distinctness, (yysemantic_stack_[(5) - (2)].p_Project).varSet, (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 430 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(2) - (1)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(2) - (2)].p_VarSet);
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 438 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 441 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 448 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 456 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSList) = new POSList;
	(yyval.p_POSList)->push_back((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 460 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_POSList) = (yysemantic_stack_[(2) - (1)].p_POSList);
    }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 468 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_POSList);
    }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 471 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 478 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 481 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 489 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	(yyval.p_Operation) = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(5) - (2)].p_BasicGraphPattern), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 497 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 504 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSList) = new POSList;
	(yyval.p_POSList)->push_back((yysemantic_stack_[(1) - (1)].p_POS));
    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 508 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSList)->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSList) = (yysemantic_stack_[(2) - (1)].p_POSList);
    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 516 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_POSList);
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 519 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 526 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 534 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(3) - (2)].p_DatasetClauses), (yysemantic_stack_[(3) - (3)].p_WhereClause));
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 541 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 553 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_POS), driver.posFactory);
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 559 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_POS), driver.posFactory);
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 565 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 572 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp, (yysemantic_stack_[(3) - (3)].p_BindingClause));
	driver.curOp = NULL;
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 585 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 593 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(2) - (1)].p_OrderConditions), (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit, (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 600 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 608 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 617 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 625 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 633 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 640 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 644 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 654 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 662 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 665 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 673 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 682 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 694 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 698 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 705 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 711 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 730 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 733 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert((yysemantic_stack_[(4) - (3)].p_TableOperation), (yysemantic_stack_[(4) - (4)].p_WhereClause));
      }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 739 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 742 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(4) - (3)].p_TableOperation), (yysemantic_stack_[(4) - (4)].p_WhereClause));
      }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 748 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(2) - (2)].p_URI));
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 754 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(3) - (2)].p_URIs), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 761 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URIs) = new ProductionVector<const URI*>((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 764 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_URIs)->push_back((yysemantic_stack_[(2) - (2)].p_URI));
	(yyval.p_URIs) = (yysemantic_stack_[(2) - (1)].p_URIs);
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 772 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 779 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 786 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 793 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 796 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 802 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 808 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 814 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 821 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_POSList));
      }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 823 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = driver.curBindingClause;
	  driver.curBindingClause = NULL;
      }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 831 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Bindings) = NULL;
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 834 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingClause->push_back((yysemantic_stack_[(2) - (2)].p_Binding));
	(yyval.p_Bindings) = NULL;
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 842 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding = new Binding();
      }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 844 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Binding) = driver.curBinding;
	  driver.curBinding = NULL;
      }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 853 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getNULL();
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 860 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_POS));
	(yyval.p_POSs) = NULL;
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 864 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = NULL;
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 872 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 875 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 914 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 917 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
      }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 924 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curFilter = NULL;
      }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 927 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_POS);
      }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 930 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(5) - (3)].p_POS), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(5) - (4)].p_POS);
      }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 973 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 975 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.curFilter;
      }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 977 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 141:

/* Line 678 of lalr1.cc  */
#line 989 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 991 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 993 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.curOp));
      }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1000 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1002 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1004 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_POS);
      }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1007 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_POS), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_POS);
      }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1015 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1017 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1019 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(5) - (4)].p_POS), driver.curOp, driver.posFactory, false));
      }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1027 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1030 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1032 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1040 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1045 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1060 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    if (driver.curOp == NULL)
		driver.ensureBasicGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 1077 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 1084 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = new ArgList((yysemantic_stack_[(1) - (1)].p_Expressions));
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 1091 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1099 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1106 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1110 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1112 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1120 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 1122 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 1150 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 1153 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1213 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.posFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_POS)));
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1220 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_POS);
	driver.curPredicate = (yyval.p_POS);
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1224 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_POS);
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 1236 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 1240 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 1249 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 204:

/* Line 678 of lalr1.cc  */
#line 1274 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 1277 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 1280 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 1283 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 1286 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 1293 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 1301 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSs) = new ProductionVector<const POS*>();
    }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 1304 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSs)->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = (yysemantic_stack_[(2) - (1)].p_POSs);
    }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 1312 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	/* no push_front
	   $2->push_front($1);
	   $$ = $2;
	   so copy the vector. */
	(yyval.p_POSs) = new ProductionVector<const POS*>();
	(yyval.p_POSs)->push_back((yysemantic_stack_[(2) - (1)].p_POS));
	for (std::vector<const POS*>::iterator it = (yysemantic_stack_[(2) - (2)].p_POSs)->begin();
	     it != (yysemantic_stack_[(2) - (2)].p_POSs)->end(); ++it)
	    (yyval.p_POSs)->push_back(*it);
	(yysemantic_stack_[(2) - (2)].p_POSs)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_POSs);
    }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 1329 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSs) = new ProductionVector<const POS*>();
    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 1341 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 1348 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 1351 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 1362 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 1365 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 1368 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 1371 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 1375 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 1386 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 1395 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 1402 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 1405 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 1413 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 1422 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 1429 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 1432 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 1444 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_BooleanComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_BooleanComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_BooleanComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 1455 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 1458 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 1461 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 1464 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 1467 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yyval.p_BooleanComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 1470 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 1477 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = NULL;
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 1490 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 1499 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 1502 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 1505 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 1508 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 1515 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 1518 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 1526 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 1535 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 1538 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 1545 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 1548 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 1555 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 1558 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 1561 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 1571 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 1574 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 1577 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 1580 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 1586 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 1592 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-str"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 1595 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-lang"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 1598 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-langMatches"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 1601 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-datatype"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 1604 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-bound"), new POSExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 1607 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sameTerm"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 1610 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 1613 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 1616 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isBlank"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 1619 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isLiteral"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 1627 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-regex"), (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 1634 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 1641 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new POSExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 1651 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 1659 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 1667 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 1674 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 1678 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 1686 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 2258 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -281;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        30,   -36,    70,   205,  -281,  -281,  -281,  -281,    40,    39,
      39,    36,    81,    83,    83,    86,    61,    22,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,   106,  -281,   130,    99,  -281,  -281,  -281,
    -281,  -281,  -281,    -3,  -281,  -281,    36,  -281,  -281,  -281,
      36,    36,  -281,  -281,  -281,  -281,     2,  -281,  -281,  -281,
    -281,  -281,   100,  -281,  -281,  -281,  -281,    14,  -281,  -281,
      39,  -281,   107,   383,   -20,   -20,    81,  -281,  -281,  -281,
    -281,  -281,  -281,    14,  -281,   -74,  -281,  -281,   383,    14,
    -281,    10,    32,  -281,  -281,    59,  -281,   383,   -74,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,   113,  -281,  -281,
    -281,  -281,   122,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,   -56,  -281,  -281,  -281,  -281,  -281,  -281,   139,
    -281,   137,  -281,   124,   139,   139,    36,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,   -24,    72,   140,   383,  -281,  -281,
      72,   407,    72,    36,  -281,  -281,  -281,  -281,   151,  -281,
      80,  -281,  -281,   383,  -281,  -281,  -281,  -281,  -281,    89,
      95,  -281,  -281,   132,   501,  -281,  -281,   142,   182,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,   149,  -281,  -281,  -281,
    -281,   335,   116,   117,  -281,  -281,  -281,   171,   173,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,   692,   142,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,   383,   100,  -281,   477,  -281,  -281,   620,
     164,   168,   172,   183,   187,   188,   189,   193,   195,   197,
     200,   335,  -281,   201,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,   -22,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,   383,    99,   -26,   162,   174,  -281,
    -281,  -281,   656,   656,   656,  -281,   206,  -281,  -281,  -281,
    -281,   218,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,   -22,   620,   620,   620,   620,   -74,   620,   620,
     620,   620,   620,   620,  -281,  -281,   620,  -281,  -281,  -281,
     100,   100,    99,    99,  -281,   196,  -281,  -281,  -281,    72,
    -281,   501,  -281,    39,  -281,  -281,  -281,  -281,   202,   192,
     620,   620,   620,   620,   620,   620,  -281,  -281,   177,   -18,
    -281,  -281,   209,   212,   208,   216,   224,   219,   225,   227,
     229,   230,   231,  -281,  -281,    99,  -281,  -281,  -281,   196,
    -281,   534,  -281,  -281,   501,  -281,  -281,   620,  -281,   620,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,   620,   620,  -281,
    -281,  -281,   620,   620,  -281,  -281,  -281,   620,  -281,  -281,
     620,  -281,  -281,  -281,  -281,   620,  -281,    99,  -281,    99,
    -281,  -281,  -281,   561,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,   239,   241,   235,   -19,  -281,  -281,  -281,  -281,
    -281,  -281,   620,  -281,   243,  -281,  -281,  -281,  -281
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        11,     0,     0,     0,    13,    12,    15,     1,    47,     0,
       0,     0,    93,    95,    95,    23,     0,     0,    29,     8,
       2,     4,     5,     6,     7,     9,    75,    80,    81,    77,
      76,    78,    79,    10,    48,     0,     0,   121,    84,    82,
     315,   318,   317,    91,    88,   316,     0,    86,    94,    96,
       0,     0,    21,    22,    29,    24,     0,   170,    29,    36,
     222,   223,    35,    29,    33,   220,   221,    47,    16,    14,
       0,   110,    49,   112,    37,    37,     0,    92,    87,    89,
      99,    98,    97,    47,    28,    27,    20,    25,   172,    47,
      34,    37,     0,    30,    39,     0,     3,   112,     0,    46,
      50,   204,   205,   206,   207,   208,   201,   309,   310,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   311,   313,
     312,   314,   319,   320,   229,   127,   113,   131,   180,   200,
     199,   210,     0,   178,   218,   219,   225,   226,   297,   298,
     299,   227,   295,   224,   228,    85,    38,    83,    90,    52,
      26,     0,   173,   176,    52,    52,     0,    40,    41,    42,
      43,    45,    17,   119,     0,     0,   123,   112,   132,   129,
     190,   209,     0,     0,   293,   294,   296,   291,     0,    19,
      54,    53,   171,   172,   177,   174,    31,    32,    44,     0,
     151,   100,   198,     0,   209,   197,   122,   116,     0,   128,
     130,   191,   181,   189,   217,   215,     0,   211,   216,   179,
     292,     0,     0,     0,    51,    55,    70,    56,    58,   175,
      18,   144,   148,   111,   138,   141,     0,   116,   120,   114,
     133,   134,   136,   137,   135,   152,   115,   102,   202,   187,
     194,   196,   117,   112,     0,   203,   209,    65,    66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    60,    61,     0,    63,    64,    68,   161,    69,   159,
     160,   284,     0,    73,    74,    71,    57,    72,    59,   145,
     149,   139,   142,   158,   112,     0,     0,   182,   192,   126,
     124,   212,     0,     0,     0,   272,     0,   230,   233,   237,
     239,   247,   249,   255,   260,   265,   266,   267,   268,   269,
     270,   271,   289,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    62,    67,     0,   167,   162,   163,
       0,     0,     0,     0,   118,   156,   101,   104,   103,   184,
     188,   209,   195,     0,   263,   264,   262,   273,   231,   235,
       0,     0,     0,     0,     0,     0,   248,   240,   250,   257,
     290,   288,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   168,   146,     0,   140,   143,   154,   156,
     153,     0,   185,   186,   209,   193,   125,     0,   234,     0,
     238,   241,   242,   243,   244,   245,   246,     0,     0,   256,
     253,   254,     0,     0,   261,   274,   275,     0,   277,   278,
       0,   280,   281,   282,   283,     0,   165,     0,   150,     0,
     157,   107,   108,     0,   106,   183,   232,   236,   251,   252,
     258,   259,     0,     0,   286,     0,   147,   155,   105,   109,
     276,   279,     0,   287,     0,   169,   166,   164,   285
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,   191,  -281,     6,  -281,  -281,
    -281,  -281,   -64,  -281,  -281,  -281,  -281,  -281,   131,     0,
    -281,  -281,   -41,  -281,  -281,  -281,  -281,  -281,  -281,    25,
    -281,  -281,  -281,  -281,  -281,    73,    75,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,   276,
    -281,  -281,   220,  -281,  -281,  -281,  -281,  -281,  -129,  -281,
    -280,  -281,   -94,  -281,    68,  -281,  -281,    -9,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,   -82,  -281,    84,  -281,
       1,  -126,  -281,  -281,  -281,  -281,  -281,   129,  -281,  -281,
    -281,   -84,  -281,  -281,   -85,  -281,  -281,  -281,  -281,  -281,
    -281,   -70,  -281,  -281,   -23,   -12,  -153,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -162,  -135,    -7,     9,  -281,
     -15,  -281,  -281,  -281,   -72,  -281,  -281,   -68,  -281,  -281,
    -281,    27,  -281,  -281,  -281,  -279,  -281,  -281,  -255,  -142,
    -195,  -183,  -281,  -281,  -281,  -281,   -59,  -281,  -281,  -281,
     -39,  -281,   -29,   -27,   -25,  -281,   -11,  -281,  -281
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,    19,    20,     3,     4,    33,     5,    69,    95,
     189,    21,    54,    55,    56,    85,    86,    67,    22,    23,
      62,    63,   145,    24,    93,   157,   158,   159,   160,   146,
      36,    99,   179,   180,   214,   275,   277,   181,   261,   262,
     263,   264,   265,   215,   216,   217,   218,    25,    26,    27,
      75,    28,    74,    29,    30,    43,    77,    78,    47,    50,
      31,    32,    48,   100,   237,   286,   338,   381,   422,   423,
      72,    97,   125,   227,   243,   228,   190,    38,    73,   197,
     198,   343,   199,   166,   126,   168,   169,   229,   230,   281,
     332,   231,   282,   333,   232,   279,   330,   417,   233,   280,
     331,   234,   235,   285,   379,   419,   380,   236,   266,   267,
     328,   443,   435,   329,   416,    58,    88,   151,   152,   184,
     185,   127,   172,   170,   193,   382,   383,   340,   287,   202,
     203,   239,   342,   288,   240,   194,   128,   129,   165,   130,
     131,   132,   246,   205,   206,   241,   133,   195,   295,   135,
     296,   297,   388,   348,   298,   390,   349,   299,   300,   356,
     357,   301,   302,   399,   358,   303,   404,   359,   304,   305,
     306,   307,   271,   444,   308,   361,   309,   175,   176,   177,
     310,   138,   139,   140,   311,   142,   312,    45,   144
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SPARQLfedParser::yytable_ninf_ = -215;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        44,    39,   402,   163,   153,   335,    66,    76,    35,   207,
      64,   147,   336,   191,   136,   337,   269,   -47,   204,   326,
      34,   173,    84,   445,    60,    61,    65,   155,   270,   136,
     442,   269,    79,    92,   137,    80,   208,    92,   136,    81,
      82,   204,    59,   270,   174,     1,   403,   -47,   141,   137,
      34,    66,   376,   377,    34,    90,   156,     6,   137,   208,
      83,    96,   143,   141,    89,    87,   269,    94,   325,    91,
       7,    65,   141,   200,    60,    61,    37,   143,   270,   327,
      34,   161,   134,   149,   291,   201,   143,   209,    46,   154,
      40,    41,    42,   204,   150,   418,    49,   134,    57,   153,
      60,    61,   221,   222,    52,    53,   134,    87,   136,   212,
     213,   208,   136,   186,   187,    40,    41,    42,   428,   429,
      60,    61,    68,   192,   136,    40,    41,    42,   137,    40,
      41,    42,   137,   223,    70,   136,    71,   436,    98,   437,
     224,   225,   141,   226,   137,   161,   141,   430,   431,   289,
     344,   345,   346,   162,    66,   137,   143,   167,   141,    66,
     143,    66,   210,   171,   178,    40,    41,    42,   183,   141,
      60,    61,   143,   150,    65,   182,   134,   211,   196,    65,
     134,    65,   220,   143,   136,   238,   242,   136,   204,   244,
     334,   245,   134,    40,    41,    42,   273,   274,    60,    61,
     272,   213,   212,   134,   137,   313,   208,   137,     8,   314,
       9,    10,   339,   315,    11,   272,    12,    13,   141,    14,
     268,   141,    15,   341,   316,   136,    16,    17,   317,   318,
     319,   204,   143,    66,   320,   143,   321,   290,   322,   397,
     398,   323,   249,   378,    18,   137,   424,   389,   347,   208,
     272,   405,   134,    65,   406,   134,   387,   407,   408,   141,
     112,   113,   114,   115,   116,   117,   409,   411,   410,   412,
     268,   413,   414,   143,   350,   351,   352,   353,   354,   355,
     415,   440,   136,   441,   442,   448,   324,   188,   424,   164,
      51,   278,   276,   134,   439,   284,   148,   420,   362,   363,
     364,   365,   137,   367,   368,   369,   370,   371,   372,   446,
     283,   373,   219,   360,   425,   426,   141,     0,   385,    66,
      66,   427,   136,   374,   375,   136,   366,   384,    66,   400,
     143,   401,     0,     0,   386,     0,     0,     0,     0,    65,
      65,     0,   137,     0,     0,   137,     0,     0,    65,     0,
     134,     0,     0,     0,     0,     0,   141,     0,     0,   141,
       0,     0,   247,   248,   136,     0,     0,     0,     0,     0,
     143,     0,     0,   143,     0,     0,   249,   391,   392,   393,
     394,   395,   396,     0,   137,     0,     0,     0,     0,     0,
     134,     0,   432,   134,     0,   433,     0,     0,   141,     0,
     434,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   143,     0,     0,   101,   102,   103,   104,   105,
       0,     0,     0,     0,  -209,     0,     0,   447,    40,    41,
      42,     0,   134,    60,    61,   106,     0,     0,     0,   101,
     102,   103,   104,   105,     0,     0,     0,     0,     0,  -214,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   106,
       0,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    40,    41,    42,   122,
     123,    60,    61,     0,   124,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      40,    41,    42,   122,   123,    60,    61,     0,   124,   101,
     102,   103,   104,   105,     0,     0,     0,     0,     0,  -213,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   106,
       0,     0,     0,   101,   102,   103,   104,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,     0,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      40,    41,    42,   122,   123,    60,    61,   421,   124,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    40,    41,    42,   122,   123,    60,
      61,     0,   124,   438,   421,     0,     0,     0,     0,     0,
       0,     0,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    40,    41,    42,
     122,   123,    60,    61,     0,   124,     0,     0,     0,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    40,    41,    42,   122,   123,    60,
      61,   249,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   292,   293,     0,   294,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   249,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    40,    41,    42,     0,     0,    60,    61,
       0,     0,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   249,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    40,
      41,    42,     0,     0,    60,    61,     0,     0,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    40,    41,    42
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        11,    10,    20,    97,    88,   285,    17,    10,     8,   171,
      17,    75,    38,    37,    73,    41,   211,    37,   171,    41,
      40,    77,    20,    42,    98,    99,    17,    91,   211,    88,
      49,   226,    43,    23,    73,    46,   171,    23,    97,    50,
      51,   194,    20,   226,   100,    15,    64,    37,    73,    88,
      40,    62,   332,   333,    40,    62,    24,    93,    97,   194,
      54,    70,    73,    88,    58,    56,   261,    67,   263,    63,
       0,    62,    97,   167,    98,    99,    37,    88,   261,   101,
      40,    92,    73,    83,   246,   170,    97,   172,     7,    89,
      93,    94,    95,   246,    85,   375,    13,    88,    37,   183,
      98,    99,     7,     8,    18,    19,    97,    98,   167,    29,
      30,   246,   171,   154,   155,    93,    94,    95,   397,   398,
      98,    99,    16,    51,   183,    93,    94,    95,   167,    93,
      94,    95,   171,    38,     4,   194,    37,   417,    31,   419,
      45,    46,   167,    48,   183,   156,   171,   402,   403,   243,
     292,   293,   294,    94,   165,   194,   167,    44,   183,   170,
     171,   172,   173,    41,    25,    93,    94,    95,    44,   194,
      98,    99,   183,   164,   165,    38,   167,    26,    38,   170,
     171,   172,    93,   194,   243,    53,    44,   246,   341,     7,
     284,    42,   183,    93,    94,    95,    80,    80,    98,    99,
     211,    30,    29,   194,   243,    41,   341,   246,     3,    41,
       5,     6,    50,    41,     9,   226,    11,    12,   243,    14,
     211,   246,    17,    49,    41,   284,    21,    22,    41,    41,
      41,   384,   243,   244,    41,   246,    41,   244,    41,    62,
      63,    41,    41,    47,    39,   284,   381,    55,    42,   384,
     261,    42,   243,   244,    42,   246,    54,    49,    42,   284,
      83,    84,    85,    86,    87,    88,    42,    42,    49,    42,
     261,    42,    42,   284,    56,    57,    58,    59,    60,    61,
      49,    42,   341,    42,    49,    42,   261,   156,   423,    98,
      14,   218,   217,   284,   423,   227,    76,   379,   313,   314,
     315,   316,   341,   318,   319,   320,   321,   322,   323,   435,
     226,   326,   183,   312,   384,   387,   341,    -1,   341,   330,
     331,   389,   381,   330,   331,   384,   317,   339,   339,   358,
     341,   358,    -1,    -1,   343,    -1,    -1,    -1,    -1,   330,
     331,    -1,   381,    -1,    -1,   384,    -1,    -1,   339,    -1,
     341,    -1,    -1,    -1,    -1,    -1,   381,    -1,    -1,   384,
      -1,    -1,    27,    28,   423,    -1,    -1,    -1,    -1,    -1,
     381,    -1,    -1,   384,    -1,    -1,    41,   350,   351,   352,
     353,   354,   355,    -1,   423,    -1,    -1,    -1,    -1,    -1,
     381,    -1,   407,   384,    -1,   410,    -1,    -1,   423,    -1,
     415,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,   423,    -1,    -1,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    41,    -1,    -1,   442,    93,    94,
      95,    -1,   423,    98,    99,    52,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,    -1,   101,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,   101,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,    43,   101,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,    -1,   101,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,    -1,   101,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,    41,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    -1,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    41,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    -1,    -1,    98,    99,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    41,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    -1,    -1,    98,    99,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    94,    95
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    15,   103,   106,   107,   109,    93,     0,     3,     5,
       6,     9,    11,    12,    14,    17,    21,    22,    39,   104,
     105,   113,   120,   121,   125,   149,   150,   151,   153,   155,
     156,   162,   163,   108,    40,   131,   132,    37,   179,   179,
      93,    94,    95,   157,   288,   289,     7,   160,   164,    13,
     161,   161,    18,    19,   114,   115,   116,    37,   217,    20,
      98,    99,   122,   123,   249,   250,   288,   119,    16,   110,
       4,    37,   172,   180,   154,   152,    10,   158,   159,   288,
     288,   288,   288,   119,    20,   117,   118,   250,   218,   119,
     249,   119,    23,   126,   131,   111,   179,   173,    31,   133,
     165,    32,    33,    34,    35,    36,    52,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    96,    97,   101,   174,   186,   223,   238,   239,
     241,   242,   243,   248,   250,   251,   278,   282,   283,   284,
     285,   286,   287,   288,   290,   124,   131,   124,   164,   131,
     250,   219,   220,   223,   131,   124,    24,   127,   128,   129,
     130,   288,    94,   174,   117,   240,   185,    44,   187,   188,
     225,    41,   224,    77,   100,   279,   280,   281,    25,   134,
     135,   139,    38,    44,   221,   222,   134,   134,   130,   112,
     178,    37,    51,   226,   237,   249,    38,   181,   182,   184,
     174,   226,   231,   232,   238,   245,   246,   247,   248,   226,
     288,    26,    29,    30,   136,   145,   146,   147,   148,   219,
      93,     7,     8,    38,    45,    46,    48,   175,   177,   189,
     190,   193,   196,   200,   203,   204,   209,   166,    53,   233,
     236,   247,    44,   176,     7,    42,   244,    27,    28,    41,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,   140,   141,   142,   143,   144,   210,   211,   250,   272,
     273,   274,   288,    80,    80,   137,   148,   138,   147,   197,
     201,   191,   194,   210,   176,   205,   167,   230,   235,   174,
     249,   247,    62,    63,    65,   250,   252,   253,   256,   259,
     260,   263,   264,   267,   270,   271,   272,   273,   276,   278,
     282,   286,   288,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,   141,   272,    41,   101,   212,   215,
     198,   202,   192,   195,   174,   172,    38,    41,   168,    50,
     229,    49,   234,   183,   271,   271,   271,    42,   255,   258,
      56,    57,    58,    59,    60,    61,   261,   262,   266,   269,
     212,   277,   252,   252,   252,   252,   250,   252,   252,   252,
     252,   252,   252,   252,   249,   249,   172,   172,    47,   206,
     208,   169,   227,   228,   237,   236,   179,    54,   254,    55,
     257,   263,   263,   263,   263,   263,   263,    62,    63,   265,
     284,   285,    20,    64,   268,    42,    42,    49,    42,    42,
      49,    42,    42,    42,    42,    49,   216,   199,   172,   207,
     208,    43,   170,   171,   248,   233,   256,   259,   267,   267,
     270,   270,   252,   252,   252,   214,   172,   172,    42,   170,
      42,    42,    49,   213,   275,    42,   213,   252,    42
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
         0,   102,   103,   104,   105,   105,   105,   105,   105,   105,
     106,   107,   107,   108,   108,   109,   111,   112,   110,   113,
     114,   115,   115,   116,   116,   117,   117,   118,   118,   119,
     119,   120,   121,   122,   122,   123,   123,   124,   124,   125,
     126,   127,   127,   128,   129,   130,   131,   132,   132,   133,
     133,   134,   135,   135,   136,   136,   137,   137,   138,   138,
     139,   140,   140,   141,   141,   142,   142,   143,   144,   144,
     145,   146,   146,   147,   148,   149,   149,   149,   149,   149,
     150,   150,   152,   151,   154,   153,   155,   156,   157,   157,
     158,   159,   159,   160,   160,   161,   161,   162,   163,   164,
     166,   165,   167,   167,   169,   168,   170,   170,   171,   171,
     173,   172,   174,   174,   175,   175,   176,   176,   177,   178,
     178,   180,   179,   182,   183,   181,   184,   185,   185,   186,
     187,   188,   188,   189,   189,   189,   189,   189,   191,   192,
     190,   194,   195,   193,   197,   198,   199,   196,   201,   202,
     200,   204,   205,   203,   207,   206,   208,   208,   209,   210,
     210,   210,   211,   212,   213,   214,   214,   215,   216,   215,
     218,   217,   219,   219,   220,   221,   222,   222,   224,   223,
     225,   223,   226,   227,   228,   228,   229,   230,   230,   231,
     232,   232,   233,   234,   235,   235,   236,   237,   237,   238,
     238,   240,   239,   241,   242,   242,   242,   242,   242,   243,
     243,   244,   244,   245,   246,   246,   247,   247,   248,   248,
     249,   249,   250,   250,   251,   251,   251,   251,   251,   251,
     252,   253,   254,   255,   255,   256,   257,   258,   258,   259,
     260,   261,   261,   261,   261,   261,   261,   262,   262,   263,
     264,   265,   265,   265,   265,   266,   266,   267,   268,   268,
     269,   269,   270,   270,   270,   270,   271,   271,   271,   271,
     271,   271,   271,   272,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   274,   275,   275,   276,   277,
     277,   278,   279,   280,   280,   281,   281,   282,   282,   282,
     283,   283,   283,   284,   284,   284,   285,   285,   285,   286,
     286,   287,   287,   287,   287,   288,   288,   289,   289,   290,
     290
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SPARQLfedParser::yyr2_[] =
  {
         0,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       2,     0,     1,     0,     2,     2,     0,     0,     5,     5,
       2,     1,     1,     0,     1,     1,     2,     1,     1,     0,
       2,     5,     5,     1,     2,     1,     1,     0,     1,     3,
       2,     1,     1,     1,     2,     1,     3,     0,     1,     0,
       1,     2,     0,     1,     0,     1,     0,     1,     0,     1,
       3,     1,     2,     1,     1,     1,     1,     2,     1,     1,
       1,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     0,     4,     2,     3,     1,     2,
       2,     0,     1,     0,     1,     0,     1,     3,     3,     2,
       0,     6,     0,     2,     0,     4,     1,     1,     1,     2,
       0,     5,     0,     1,     1,     1,     0,     1,     3,     0,
       2,     0,     5,     0,     0,     5,     3,     0,     2,     2,
       2,     0,     1,     1,     1,     1,     1,     1,     0,     0,
       4,     0,     0,     4,     0,     0,     0,     6,     0,     0,
       5,     0,     0,     4,     0,     3,     0,     2,     2,     1,
       1,     1,     2,     1,     2,     0,     2,     1,     0,     5,
       0,     4,     0,     1,     2,     2,     0,     1,     0,     3,
       0,     3,     3,     2,     0,     1,     2,     0,     2,     1,
       0,     1,     2,     2,     0,     2,     1,     1,     1,     1,
       1,     0,     4,     4,     1,     1,     1,     1,     1,     0,
       1,     0,     2,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     0,     2,     2,     2,     0,     2,     1,
       2,     2,     2,     2,     2,     2,     2,     0,     1,     1,
       2,     2,     2,     1,     1,     0,     2,     2,     2,     2,
       0,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     4,     6,     4,     4,     6,
       4,     4,     4,     4,     1,     7,     0,     1,     2,     0,
       1,     2,     2,     1,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
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
  "VAR2", "LANGTAG", "NIL", "$accept", "Query", "Replace",
  "_O_QSelect_E_Or_QConstruct_E_Or_QDescribe_E_Or_QAsk_E_Or_QReplace_E_Or_QUpdate_E_C",
  "Prologue", "_QBaseDecl_E_Opt", "_QPrefixDecl_E_Star", "BaseDecl",
  "PrefixDecl", "$@1", "$@2", "Select", "Project",
  "_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C",
  "_Q_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C_E_Opt", "_QVar_E_Plus",
  "_O_QVar_E_Plus_Or_QGT_TIMES_E_C", "_QDatasetClause_E_Star", "Construct",
  "Describe", "_QVarOrIRIref_E_Plus",
  "_O_QVarOrIRIref_E_Plus_Or_QGT_TIMES_E_C", "_QWhereClause_E_Opt", "Ask",
  "DatasetClause", "_O_QDefaultGraphClause_E_Or_QNamedGraphClause_E_C",
  "DefaultGraphClause", "NamedGraphClause", "SourceSelector",
  "WhereClause", "_QIT_WHERE_E_Opt", "_QBindingClause_E_Opt",
  "SolutionModifier", "_QOrderClause_E_Opt", "_QLimitOffsetClauses_E_Opt",
  "_QOffsetClause_E_Opt", "_QLimitClause_E_Opt", "OrderClause",
  "_QOrderCondition_E_Plus", "OrderCondition",
  "_O_QIT_ASC_E_Or_QIT_DESC_E_C",
  "_O_QIT_ASC_E_Or_QIT_DESC_E_S_QBrackettedExpression_E_C",
  "_O_QConstraint_E_Or_QVar_E_C", "LimitOffsetClauses",
  "_QLimitClause_E_S_QOffsetClause_E_Opt_Or_QOffsetClause_E_S_QLimitClause_E_Opt",
  "LimitClause", "OffsetClause", "Update", "Modify", "Insert", "@3",
  "Delete", "@4", "Clear", "Load", "_QIRIref_E_Plus",
  "_O_QIT_INTO_E_S_QGraphRef_E_C", "_Q_O_QIT_INTO_E_S_QGraphRef_E_C_E_Opt",
  "_QGraphRef_E_Opt", "_QIT_SILENT_E_Opt", "Drop", "Create", "GraphRef",
  "BindingClause", "$@5", "_QBinding_E_Star", "Binding", "$@6",
  "_O_QVarOrTerm_E_Or_QIT_NULL_E_C",
  "_Q_O_QVarOrTerm_E_Or_QIT_NULL_E_C_E_Plus", "GroupGraphPattern", "$@7",
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
  "Constraint", "FunctionCall", "ArgList",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star",
  "_O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C",
  "$@23", "ConstructTemplate", "$@24", "_QConstructTriples_E_Opt",
  "ConstructTriples", "_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C",
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
  "_QGraphNode_E_Star", "_O_QGraphNode_E_S_QGraphNode_E_Star_C",
  "_Q_O_QGraphNode_E_S_QGraphNode_E_Star_C_E_Opt", "GraphNode",
  "VarOrTerm", "VarOrIRIref", "Var", "GraphTerm", "Expression",
  "ConditionalOrExpression", "_O_QGT_OR_E_S_QConditionalAndExpression_E_C",
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
       103,     0,    -1,   106,   105,    -1,     3,   131,     4,   179,
      -1,   113,    -1,   120,    -1,   121,    -1,   125,    -1,   104,
      -1,   149,    -1,   107,   108,    -1,    -1,   109,    -1,    -1,
     108,   110,    -1,    15,    93,    -1,    -1,    -1,    16,   111,
      94,   112,    93,    -1,    17,   114,   119,   131,   134,    -1,
     116,   118,    -1,    18,    -1,    19,    -1,    -1,   115,    -1,
     250,    -1,   117,   250,    -1,   117,    -1,    20,    -1,    -1,
     119,   126,    -1,    21,   217,   119,   131,   134,    -1,    22,
     123,   119,   124,   134,    -1,   249,    -1,   122,   249,    -1,
     122,    -1,    20,    -1,    -1,   131,    -1,    39,   119,   131,
      -1,    23,   127,    -1,   128,    -1,   129,    -1,   130,    -1,
      24,   130,    -1,   288,    -1,   132,   172,   133,    -1,    -1,
      40,    -1,    -1,   165,    -1,   135,   136,    -1,    -1,   139,
      -1,    -1,   145,    -1,    -1,   148,    -1,    -1,   147,    -1,
      25,    26,   140,    -1,   141,    -1,   140,   141,    -1,   143,
      -1,   144,    -1,    27,    -1,    28,    -1,   142,   272,    -1,
     210,    -1,   250,    -1,   146,    -1,   147,   137,    -1,   148,
     138,    -1,    29,    80,    -1,    30,    80,    -1,   150,    -1,
     156,    -1,   155,    -1,   162,    -1,   163,    -1,   151,    -1,
     153,    -1,    -1,     6,   179,   152,   124,    -1,    -1,     5,
     179,   154,   124,    -1,    11,   160,    -1,     9,   157,   159,
      -1,   288,    -1,   157,   288,    -1,    10,   164,    -1,    -1,
     158,    -1,    -1,   164,    -1,    -1,    13,    -1,    14,   161,
     288,    -1,    12,   161,   288,    -1,     7,   288,    -1,    -1,
      31,   117,    37,   166,   167,    38,    -1,    -1,   167,   168,
      -1,    -1,    41,   169,   171,    42,    -1,   248,    -1,    43,
      -1,   170,    -1,   171,   170,    -1,    -1,    37,   173,   174,
     178,    38,    -1,    -1,   186,    -1,   189,    -1,   209,    -1,
      -1,    44,    -1,   175,   176,   174,    -1,    -1,   178,   177,
      -1,    -1,    37,   180,   174,   185,    38,    -1,    -1,    -1,
     182,     7,   249,   183,   179,    -1,   181,   176,   174,    -1,
      -1,   185,   184,    -1,   223,   188,    -1,    44,   174,    -1,
      -1,   187,    -1,   190,    -1,   193,    -1,   203,    -1,   196,
      -1,   200,    -1,    -1,    -1,    45,   191,   192,   172,    -1,
      -1,    -1,    46,   194,   195,   172,    -1,    -1,    -1,    -1,
       7,   197,   198,   249,   199,   172,    -1,    -1,    -1,     8,
     201,   202,   249,   172,    -1,    -1,    -1,   204,   205,   172,
     208,    -1,    -1,    47,   207,   172,    -1,    -1,   206,   208,
      -1,    48,   210,    -1,   272,    -1,   273,    -1,   211,    -1,
     288,   212,    -1,   215,    -1,    49,   252,    -1,    -1,   214,
     213,    -1,   101,    -1,    -1,    41,   252,   216,   214,    42,
      -1,    -1,    37,   218,   219,    38,    -1,    -1,   220,    -1,
     223,   222,    -1,    44,   219,    -1,    -1,   221,    -1,    -1,
     248,   224,   226,    -1,    -1,   238,   225,   231,    -1,   237,
     233,   230,    -1,   237,   233,    -1,    -1,   227,    -1,    50,
     228,    -1,    -1,   230,   229,    -1,   232,    -1,    -1,   226,
      -1,   236,   235,    -1,    49,   236,    -1,    -1,   235,   234,
      -1,   247,    -1,   249,    -1,    51,    -1,   241,    -1,   239,
      -1,    -1,    52,   240,   226,    53,    -1,   243,    41,   246,
      42,    -1,    32,    -1,    33,    -1,    34,    -1,    35,    -1,
      36,    -1,    -1,   242,    -1,    -1,   244,   247,    -1,   247,
     244,    -1,    -1,   245,    -1,   248,    -1,   238,    -1,   250,
      -1,   251,    -1,   250,    -1,   288,    -1,    98,    -1,    99,
      -1,   288,    -1,   278,    -1,   282,    -1,   286,    -1,   290,
      -1,   101,    -1,   253,    -1,   256,   255,    -1,    54,   256,
      -1,    -1,   255,   254,    -1,   259,   258,    -1,    55,   259,
      -1,    -1,   258,   257,    -1,   260,    -1,   263,   262,    -1,
      56,   263,    -1,    57,   263,    -1,    58,   263,    -1,    59,
     263,    -1,    60,   263,    -1,    61,   263,    -1,    -1,   261,
      -1,   264,    -1,   267,   266,    -1,    62,   267,    -1,    63,
     267,    -1,   284,    -1,   285,    -1,    -1,   266,   265,    -1,
     270,   269,    -1,    20,   270,    -1,    64,   270,    -1,    -1,
     269,   268,    -1,    65,   271,    -1,    62,   271,    -1,    63,
     271,    -1,   271,    -1,   272,    -1,   273,    -1,   276,    -1,
     278,    -1,   282,    -1,   286,    -1,   250,    -1,    41,   252,
      42,    -1,    66,    41,   252,    42,    -1,    67,    41,   252,
      42,    -1,    68,    41,   252,    49,   252,    42,    -1,    69,
      41,   252,    42,    -1,    70,    41,   250,    42,    -1,    71,
      41,   252,    49,   252,    42,    -1,    72,    41,   252,    42,
      -1,    73,    41,   252,    42,    -1,    74,    41,   252,    42,
      -1,    75,    41,   252,    42,    -1,   274,    -1,    76,    41,
     252,    49,   252,   275,    42,    -1,    -1,   213,    -1,   288,
     277,    -1,    -1,   212,    -1,   287,   281,    -1,    77,   288,
      -1,   100,    -1,   279,    -1,    -1,   280,    -1,   283,    -1,
     284,    -1,   285,    -1,    80,    -1,    81,    -1,    82,    -1,
      83,    -1,    84,    -1,    85,    -1,    86,    -1,    87,    -1,
      88,    -1,    78,    -1,    79,    -1,    89,    -1,    91,    -1,
      90,    -1,    92,    -1,    93,    -1,   289,    -1,    95,    -1,
      94,    -1,    96,    -1,    97,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SPARQLfedParser::yyprhs_[] =
  {
         0,     0,     3,     6,    11,    13,    15,    17,    19,    21,
      23,    26,    27,    29,    30,    33,    36,    37,    38,    44,
      50,    53,    55,    57,    58,    60,    62,    65,    67,    69,
      70,    73,    79,    85,    87,    90,    92,    94,    95,    97,
     101,   104,   106,   108,   110,   113,   115,   119,   120,   122,
     123,   125,   128,   129,   131,   132,   134,   135,   137,   138,
     140,   144,   146,   149,   151,   153,   155,   157,   160,   162,
     164,   166,   169,   172,   175,   178,   180,   182,   184,   186,
     188,   190,   192,   193,   198,   199,   204,   207,   211,   213,
     216,   219,   220,   222,   223,   225,   226,   228,   232,   236,
     239,   240,   247,   248,   251,   252,   257,   259,   261,   263,
     266,   267,   273,   274,   276,   278,   280,   281,   283,   287,
     288,   291,   292,   298,   299,   300,   306,   310,   311,   314,
     317,   320,   321,   323,   325,   327,   329,   331,   333,   334,
     335,   340,   341,   342,   347,   348,   349,   350,   357,   358,
     359,   365,   366,   367,   372,   373,   377,   378,   381,   384,
     386,   388,   390,   393,   395,   398,   399,   402,   404,   405,
     411,   412,   417,   418,   420,   423,   426,   427,   429,   430,
     434,   435,   439,   443,   446,   447,   449,   452,   453,   456,
     458,   459,   461,   464,   467,   468,   471,   473,   475,   477,
     479,   481,   482,   487,   492,   494,   496,   498,   500,   502,
     503,   505,   506,   509,   512,   513,   515,   517,   519,   521,
     523,   525,   527,   529,   531,   533,   535,   537,   539,   541,
     543,   545,   548,   551,   552,   555,   558,   561,   562,   565,
     567,   570,   573,   576,   579,   582,   585,   588,   589,   591,
     593,   596,   599,   602,   604,   606,   607,   610,   613,   616,
     619,   620,   623,   626,   629,   632,   634,   636,   638,   640,
     642,   644,   646,   648,   652,   657,   662,   669,   674,   679,
     686,   691,   696,   701,   706,   708,   716,   717,   719,   722,
     723,   725,   728,   731,   733,   735,   736,   738,   740,   742,
     744,   746,   748,   750,   752,   754,   756,   758,   760,   762,
     764,   766,   768,   770,   772,   774,   776,   778,   780,   782,
     784
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   365,   365,   371,   379,   380,   381,   382,   383,   384,
     389,   393,   395,   399,   401,   405,   411,   413,   411,   423,
     430,   438,   441,   448,   451,   456,   460,   468,   471,   478,
     481,   489,   497,   504,   508,   516,   519,   526,   529,   534,
     541,   548,   549,   553,   559,   565,   572,   579,   581,   585,
     588,   593,   600,   603,   608,   612,   617,   620,   625,   628,
     633,   640,   644,   652,   654,   662,   665,   673,   681,   682,
     689,   694,   698,   705,   711,   717,   718,   719,   720,   721,
     725,   726,   730,   730,   739,   739,   748,   754,   761,   764,
     772,   779,   782,   786,   789,   793,   796,   802,   808,   814,
     821,   821,   831,   834,   842,   842,   852,   853,   860,   864,
     872,   872,   883,   885,   890,   891,   895,   897,   902,   906,
     909,   914,   914,   924,   927,   924,   938,   942,   944,   949,
     954,   958,   961,   965,   966,   967,   968,   969,   973,   975,
     973,   989,   991,   989,  1000,  1002,  1004,  1000,  1015,  1017,
    1015,  1027,  1030,  1027,  1040,  1040,  1054,  1056,  1060,  1071,
    1072,  1073,  1077,  1084,  1091,  1097,  1099,  1106,  1110,  1110,
    1120,  1120,  1128,  1130,  1135,  1140,  1144,  1146,  1150,  1150,
    1153,  1153,  1160,  1165,  1169,  1171,  1176,  1180,  1182,  1187,
    1191,  1193,  1198,  1203,  1207,  1209,  1213,  1220,  1224,  1231,
    1232,  1236,  1236,  1249,  1274,  1277,  1280,  1283,  1286,  1293,
    1296,  1301,  1304,  1312,  1329,  1332,  1336,  1337,  1341,  1344,
    1348,  1351,  1357,  1358,  1362,  1365,  1368,  1371,  1374,  1375,
    1381,  1386,  1395,  1402,  1405,  1413,  1422,  1429,  1432,  1439,
    1444,  1455,  1458,  1461,  1464,  1467,  1470,  1477,  1481,  1485,
    1490,  1499,  1502,  1505,  1508,  1515,  1518,  1526,  1535,  1538,
    1545,  1548,  1555,  1558,  1561,  1564,  1568,  1569,  1570,  1571,
    1574,  1577,  1580,  1586,  1592,  1595,  1598,  1601,  1604,  1607,
    1610,  1613,  1616,  1619,  1622,  1627,  1634,  1637,  1641,  1651,
    1654,  1659,  1667,  1674,  1678,  1686,  1690,  1694,  1695,  1696,
    1700,  1701,  1702,  1706,  1707,  1708,  1712,  1713,  1714,  1718,
    1719,  1723,  1724,  1725,  1726,  1730,  1731,  1735,  1736,  1740,
    1741
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
  const int SPARQLfedParser::yylast_ = 787;
  const int SPARQLfedParser::yynnts_ = 189;
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
#line 3315 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 1747 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


