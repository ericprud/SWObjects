
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
#line 231 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

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

  case 3:

/* Line 678 of lalr1.cc  */
#line 369 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
	(yyval.p_Operation) = new Select((yysemantic_stack_[(6) - (2)].p_distinctness), (yysemantic_stack_[(6) - (3)].p_VarSet), (yysemantic_stack_[(6) - (4)].p_DatasetClauses), (yysemantic_stack_[(6) - (5)].p_WhereClause), (yysemantic_stack_[(6) - (6)].p_SolutionModifier));
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 428 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 431 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 438 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 446 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSList) = new POSList;
	(yyval.p_POSList)->push_back((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 450 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_POSList) = (yysemantic_stack_[(2) - (1)].p_POSList);
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 458 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_POSList);
    }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 461 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 468 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 471 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 479 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	(yyval.p_Operation) = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(5) - (2)].p_BasicGraphPattern), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 487 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 494 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSList) = new POSList;
	(yyval.p_POSList)->push_back((yysemantic_stack_[(1) - (1)].p_POS));
    }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 498 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSList)->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSList) = (yysemantic_stack_[(2) - (1)].p_POSList);
    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 506 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_POSList);
    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 509 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 516 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 524 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(3) - (2)].p_DatasetClauses), (yysemantic_stack_[(3) - (3)].p_WhereClause));
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 531 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 543 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_POS), driver.posFactory);
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 549 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_POS), driver.posFactory);
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 555 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 562 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp, (yysemantic_stack_[(3) - (3)].p_BindingClause));
	driver.curOp = NULL;
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 575 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 583 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(2) - (1)].p_OrderConditions), (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit, (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 590 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 598 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 612 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 620 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 628 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 632 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 640 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 647 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 651 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 661 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 669 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 672 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 680 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 689 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 695 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 701 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 716 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 719 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert((yysemantic_stack_[(4) - (3)].p_TableOperation), (yysemantic_stack_[(4) - (4)].p_WhereClause));
      }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 725 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 728 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(4) - (3)].p_TableOperation), (yysemantic_stack_[(4) - (4)].p_WhereClause));
      }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 734 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(2) - (2)].p_URI));
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 740 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(3) - (2)].p_URIs), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 747 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URIs) = new ProductionVector<const URI*>((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 750 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_URIs)->push_back((yysemantic_stack_[(2) - (2)].p_URI));
	(yyval.p_URIs) = (yysemantic_stack_[(2) - (1)].p_URIs);
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 758 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 765 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 772 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 779 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 782 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 788 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 794 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 800 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 807 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_POSList));
      }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 809 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = driver.curBindingClause;
	  driver.curBindingClause = NULL;
      }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 817 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Bindings) = NULL;
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 820 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingClause->push_back((yysemantic_stack_[(2) - (2)].p_Binding));
	(yyval.p_Bindings) = NULL;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 828 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding = new Binding();
      }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 830 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Binding) = driver.curBinding;
	  driver.curBinding = NULL;
      }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 839 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getNULL();
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 846 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_POS));
	(yyval.p_POSs) = NULL;
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 850 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = NULL;
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 858 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 861 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 900 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 903 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
      }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 910 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curFilter = NULL;
      }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 913 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_POS);
      }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 916 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(5) - (3)].p_POS), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(5) - (4)].p_POS);
      }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 959 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 961 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.curFilter;
      }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 963 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 139:

/* Line 678 of lalr1.cc  */
#line 975 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 977 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 979 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.curOp));
      }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 986 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 988 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 990 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_POS);
      }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 993 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_POS), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_POS);
      }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1001 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1003 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1005 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(5) - (4)].p_POS), driver.curOp, driver.posFactory, false));
      }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1013 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1016 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1018 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1026 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1031 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1046 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    if (driver.curOp == NULL)
		driver.ensureBasicGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1063 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1070 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = new ArgList((yysemantic_stack_[(1) - (1)].p_Expressions));
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 1077 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 1085 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1092 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1096 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1098 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1106 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1108 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 1136 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 1139 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 1199 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.posFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_POS)));
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1206 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_POS);
	driver.curPredicate = (yyval.p_POS);
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1210 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_POS);
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 1222 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 1226 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 1235 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 202:

/* Line 678 of lalr1.cc  */
#line 1260 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 1263 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 1266 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 1269 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 1272 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 1279 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 1287 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSs) = new ProductionVector<const POS*>();
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 1290 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSs)->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = (yysemantic_stack_[(2) - (1)].p_POSs);
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 1298 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 212:

/* Line 678 of lalr1.cc  */
#line 1315 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSs) = new ProductionVector<const POS*>();
    }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 1327 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 1334 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 1337 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 1348 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 1351 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 1354 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 1357 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 1361 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 1372 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 1381 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 1388 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 1391 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 1399 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 1408 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 1415 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 1418 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 1430 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_BooleanComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_BooleanComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_BooleanComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 1441 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 1444 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 1447 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 1450 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 1453 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yyval.p_BooleanComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 1456 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 1463 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = NULL;
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 1476 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 1485 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 1488 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 1491 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 1494 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 1501 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 1504 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 1512 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 1521 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 1524 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 1531 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 1534 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 1541 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 1544 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 1547 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 1557 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 1560 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 1563 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 1566 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 1572 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 1578 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-str"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 1581 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-lang"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 1584 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-langMatches"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 1587 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-datatype"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 1590 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-bound"), new POSExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 1593 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sameTerm"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 1596 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 1599 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 1602 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isBlank"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 1605 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isLiteral"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 1613 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-regex"), (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 1620 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 1627 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new POSExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 1637 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 1645 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 1653 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 1660 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 1664 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 1672 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 2248 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -262;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        61,   -14,    65,   253,  -262,  -262,  -262,  -262,   -29,    52,
      52,    22,    92,    97,    97,    74,    87,     7,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,   114,  -262,   129,   118,  -262,  -262,  -262,  -262,
    -262,  -262,     3,  -262,  -262,    22,  -262,  -262,  -262,    22,
      22,  -262,  -262,  -262,    10,  -262,  -262,  -262,  -262,  -262,
     117,  -262,  -262,  -262,  -262,     1,  -262,  -262,    52,  -262,
      90,   420,    11,    11,    92,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,   -77,  -262,  -262,   420,     1,  -262,    50,    19,
    -262,  -262,    69,  -262,   420,   -77,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,   125,  -262,  -262,  -262,  -262,   131,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,   -60,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,     1,   136,  -262,
     135,   150,   150,    22,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,   -28,    33,   144,   420,  -262,  -262,    33,   493,    33,
      22,  -262,  -262,  -262,  -262,   150,  -262,   420,  -262,  -262,
     159,  -262,    89,  -262,  -262,  -262,   101,   190,  -262,  -262,
     143,   587,  -262,  -262,   157,   196,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,   162,  -262,  -262,  -262,  -262,  -262,  -262,
     345,   126,   128,  -262,  -262,  -262,   188,   191,  -262,  -262,
    -262,  -262,  -262,  -262,   787,   157,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,   420,   117,  -262,   517,  -262,  -262,   670,   181,   182,
     193,   198,   199,   200,   201,   203,   204,   205,   206,   345,
    -262,   208,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
     -33,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,   420,   118,    15,   179,   183,  -262,  -262,  -262,
     706,   706,   706,  -262,   195,  -262,  -262,  -262,  -262,    88,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
     -33,   670,   670,   670,   670,   -77,   670,   670,   670,   670,
     670,   670,  -262,  -262,   670,  -262,  -262,  -262,   117,   117,
     118,   118,  -262,   207,  -262,  -262,  -262,    33,  -262,   587,
    -262,    52,  -262,  -262,  -262,  -262,   212,   197,   670,   670,
     670,   670,   670,   670,  -262,  -262,   105,    -2,  -262,  -262,
     215,   218,   220,   219,   230,   224,   241,   242,   243,   244,
     238,  -262,  -262,   118,  -262,  -262,  -262,   207,  -262,   728,
    -262,  -262,   587,  -262,  -262,   670,  -262,   670,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,   670,   670,  -262,  -262,  -262,
     670,   670,  -262,  -262,  -262,   670,  -262,  -262,   670,  -262,
    -262,  -262,  -262,   670,  -262,   118,  -262,   118,  -262,  -262,
    -262,   611,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
     246,   247,   245,   -26,  -262,  -262,  -262,  -262,  -262,  -262,
     670,  -262,   248,  -262,  -262,  -262,  -262
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        11,     0,     0,     0,    13,    12,    15,     1,    46,     0,
       0,     0,    91,    93,    93,    22,     0,     0,    28,     8,
       2,     4,     5,     6,     7,     9,    74,    75,    77,    76,
      78,    79,    10,    47,     0,     0,   119,    82,    80,   313,
     316,   315,    89,    86,   314,     0,    84,    92,    94,     0,
       0,    20,    21,    23,     0,   168,    28,    35,   220,   221,
      34,    28,    32,   218,   219,    46,    16,    14,     0,   108,
      48,   110,    36,    36,     0,    90,    85,    87,    97,    96,
      95,    27,    26,    28,    24,   170,    46,    33,    36,     0,
      29,    38,     0,     3,   110,     0,    45,    49,   202,   203,
     204,   205,   206,   199,   307,   308,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   309,   311,   310,   312,   317,
     318,   227,   125,   111,   129,   178,   198,   197,   208,     0,
     176,   216,   217,   223,   224,   295,   296,   297,   225,   293,
     222,   226,    83,    37,    81,    88,    25,    46,     0,   171,
     174,    51,    51,     0,    39,    40,    41,    42,    44,    17,
     117,     0,     0,   121,   110,   130,   127,   188,   207,     0,
       0,   291,   292,   294,   289,    51,   169,   170,   175,   172,
       0,    30,    53,    52,    31,    43,     0,   149,    98,   196,
       0,   207,   195,   120,   114,     0,   126,   128,   189,   179,
     187,   215,   213,     0,   209,   214,   177,   290,    19,   173,
       0,     0,     0,    50,    54,    55,    56,    58,    18,   142,
     146,   109,   136,   139,     0,   114,   118,   112,   131,   132,
     134,   135,   133,   150,   113,   100,   200,   185,   192,   194,
     115,   110,     0,   201,   207,    67,    68,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
      63,     0,    65,    66,    70,   159,    71,   157,   158,   282,
       0,    72,    73,    60,    57,    61,    59,   143,   147,   137,
     140,   156,   110,     0,     0,   180,   190,   124,   122,   210,
       0,     0,     0,   270,     0,   228,   231,   235,   237,   245,
     247,   253,   258,   263,   264,   265,   266,   267,   268,   269,
     287,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    64,    69,     0,   165,   160,   161,     0,     0,
       0,     0,   116,   154,    99,   102,   101,   182,   186,   207,
     193,     0,   261,   262,   260,   271,   229,   233,     0,     0,
       0,     0,     0,     0,   246,   238,   248,   255,   288,   286,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   166,   144,     0,   138,   141,   152,   154,   151,     0,
     183,   184,   207,   191,   123,     0,   232,     0,   236,   239,
     240,   241,   242,   243,   244,     0,     0,   254,   251,   252,
       0,     0,   259,   272,   273,     0,   275,   276,     0,   278,
     279,   280,   281,     0,   163,     0,   148,     0,   155,   105,
     106,     0,   104,   181,   230,   234,   249,   250,   256,   257,
       0,     0,   284,     0,   145,   153,   103,   107,   274,   277,
       0,   285,     0,   167,   164,   162,   283
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,   202,  -262,   -36,  -262,  -262,  -262,
    -262,   -16,  -262,  -262,  -262,  -262,  -262,   140,    -4,  -262,
    -262,  -133,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
      36,  -262,  -262,  -262,    79,    82,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,   285,  -262,  -262,
     227,  -262,  -262,  -262,  -262,  -262,  -119,  -262,  -208,  -262,
     -87,  -262,    78,  -262,  -262,    -9,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,   -73,  -262,    81,  -262,    -3,  -127,
    -262,  -262,  -262,  -262,  -262,   132,  -262,  -262,  -262,   -82,
    -262,  -262,  -115,  -262,  -262,  -262,  -262,  -262,  -262,   -74,
    -262,  -262,   -24,   -21,  -156,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -163,  -158,   -15,     9,  -262,    84,  -262,
    -262,  -262,   -75,  -262,  -262,   -76,  -262,  -262,  -262,   -72,
    -262,  -262,  -262,  -260,  -262,  -262,  -261,  -130,  -195,  -174,
    -262,  -262,  -262,  -262,   -57,  -262,  -262,  -262,   -39,  -262,
     -37,   -35,   -27,  -262,   -11,  -262,  -262
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,    19,    20,     3,     4,    32,     5,    67,    92,
     186,    21,    53,    54,    82,    83,    65,    22,    23,    60,
      61,   142,    24,    90,   154,   155,   156,   157,   143,    35,
      96,   181,   182,   213,   214,   273,   275,   215,   183,   259,
     260,   261,   262,   263,   216,   217,    25,    26,    73,    27,
      72,    28,    29,    42,    75,    76,    46,    49,    30,    31,
      47,    97,   235,   284,   336,   379,   420,   421,    70,    94,
     122,   225,   241,   226,   187,    37,    71,   194,   195,   341,
     196,   163,   123,   165,   166,   227,   228,   279,   330,   229,
     280,   331,   230,   277,   328,   415,   231,   278,   329,   232,
     233,   283,   377,   417,   378,   234,   264,   265,   326,   441,
     433,   327,   414,    56,    85,   148,   149,   178,   179,   124,
     169,   167,   190,   380,   381,   338,   285,   199,   200,   237,
     340,   286,   238,   191,   125,   126,   162,   127,   128,   129,
     244,   202,   203,   239,   130,   192,   293,   132,   294,   295,
     386,   346,   296,   388,   347,   297,   298,   354,   355,   299,
     300,   397,   356,   301,   402,   357,   302,   303,   304,   305,
     269,   442,   306,   359,   307,   172,   173,   174,   308,   135,
     136,   137,   309,   139,   310,    44,   141
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SPARQLfedParser::yytable_ninf_ = -213;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        43,    38,    62,   150,    34,   204,    64,   160,   324,   188,
     205,    33,   201,    74,   133,   267,   443,   170,   400,   184,
      86,    58,    59,   440,    89,    88,    63,    57,   133,   267,
      81,    77,   134,   205,    78,   201,   268,   133,    79,    80,
     171,    33,   208,   153,   138,    87,   134,   147,   -46,    64,
     268,    33,   198,   334,   206,   134,   335,   144,   138,    93,
     140,    91,   401,    84,   267,     7,   323,   138,   325,    63,
      58,    59,   152,    89,   140,   333,     1,   197,   158,     6,
     131,   289,   151,   140,   189,   268,   205,   -46,   201,    36,
      33,   146,    51,    52,   131,   150,    39,    40,    41,    45,
      39,    40,    41,   131,    84,    58,    59,   133,    58,    59,
      48,   133,    39,    40,    41,    39,    40,    41,   211,   212,
     133,    95,   374,   375,    55,   134,    39,    40,    41,   134,
      66,    58,    59,    68,   133,   426,   427,   138,   134,   428,
     429,   138,   158,   175,   348,   349,   350,   351,   352,   353,
     138,    64,   134,   140,   287,    69,    64,   140,    64,   207,
     342,   343,   344,   159,   138,   416,   140,   395,   396,   164,
     146,    63,   168,   131,   176,   180,    63,   131,    63,   177,
     140,   205,   193,   201,   133,   210,   131,   133,   109,   110,
     111,   112,   113,   114,   218,   332,   236,   219,   220,   270,
     131,   240,   134,   242,   243,   134,   271,   434,   272,   435,
      39,    40,    41,   270,   138,    58,    59,   138,   212,   266,
     211,   422,   311,   312,   205,   133,   201,   288,   221,   337,
     140,    64,   339,   140,   313,   222,   223,   345,   224,   314,
     315,   316,   317,   134,   318,   319,   320,   321,   270,   247,
     131,    63,   387,   131,   376,   138,     8,   403,     9,    10,
     404,   406,    11,   422,    12,    13,   385,    14,   266,   405,
      15,   140,   407,   408,    16,    17,   389,   390,   391,   392,
     393,   394,   133,   409,   410,   411,   412,   413,   438,   439,
     446,   131,    18,   185,   440,   322,   276,   161,   274,    50,
     134,   145,   437,   282,   418,   281,   444,   358,   423,   209,
     424,   425,   138,   372,   373,   383,   382,    64,    64,   398,
       0,   399,   133,     0,   364,   133,    64,     0,   140,     0,
       0,     0,   384,     0,     0,     0,     0,    63,    63,     0,
     134,     0,     0,   134,     0,     0,    63,     0,   131,     0,
       0,     0,   138,     0,     0,   138,     0,     0,     0,     0,
       0,     0,     0,     0,   133,     0,     0,     0,   140,     0,
       0,   140,   245,   246,     0,     0,     0,     0,     0,     0,
       0,     0,   134,     0,     0,     0,   247,     0,   131,     0,
       0,   131,     0,     0,   138,   360,   361,   362,   363,     0,
     365,   366,   367,   368,   369,   370,     0,     0,   371,     0,
     140,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,     0,     0,     0,     0,     0,     0,     0,     0,
     131,     0,     0,     0,     0,     0,     0,     0,    39,    40,
      41,     0,     0,    58,    59,     0,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,     0,     0,     0,
       0,  -207,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   430,
       0,     0,   431,     0,     0,     0,     0,   432,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    39,    40,    41,   119,   120,    58,    59,
       0,   121,     0,     0,   445,    98,    99,   100,   101,   102,
       0,     0,     0,     0,     0,  -212,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,     0,     0,     0,    98,
      99,   100,   101,   102,     0,     0,     0,     0,     0,  -211,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    39,    40,    41,   119,
     120,    58,    59,     0,   121,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
      39,    40,    41,   119,   120,    58,    59,     0,   121,    98,
      99,   100,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   436,   419,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
      39,    40,    41,   119,   120,    58,    59,     0,   121,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    39,    40,    41,   119,   120,    58,
      59,   247,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   290,   291,     0,   292,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   247,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    39,    40,    41,     0,     0,    58,    59,
       0,   419,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    39,
      40,    41,     0,     0,    58,    59,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    39,    40,    41,   119,   120,    58,    59,   247,   121,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      39,    40,    41
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        11,    10,    17,    85,     8,   168,    17,    94,    41,    37,
     168,    40,   168,    10,    71,   210,    42,    77,    20,   152,
      56,    98,    99,    49,    23,    61,    17,    20,    85,   224,
      20,    42,    71,   191,    45,   191,   210,    94,    49,    50,
     100,    40,   175,    24,    71,    60,    85,    83,    37,    60,
     224,    40,   167,    38,   169,    94,    41,    73,    85,    68,
      71,    65,    64,    54,   259,     0,   261,    94,   101,    60,
      98,    99,    88,    23,    85,   283,    15,   164,    89,    93,
      71,   244,    86,    94,    51,   259,   244,    37,   244,    37,
      40,    82,    18,    19,    85,   177,    93,    94,    95,     7,
      93,    94,    95,    94,    95,    98,    99,   164,    98,    99,
      13,   168,    93,    94,    95,    93,    94,    95,    29,    30,
     177,    31,   330,   331,    37,   164,    93,    94,    95,   168,
      16,    98,    99,     4,   191,   395,   396,   164,   177,   400,
     401,   168,   153,   147,    56,    57,    58,    59,    60,    61,
     177,   162,   191,   164,   241,    37,   167,   168,   169,   170,
     290,   291,   292,    94,   191,   373,   177,    62,    63,    44,
     161,   162,    41,   164,    38,    25,   167,   168,   169,    44,
     191,   339,    38,   339,   241,    26,   177,   244,    83,    84,
      85,    86,    87,    88,    93,   282,    53,     7,     8,   210,
     191,    44,   241,     7,    42,   244,    80,   415,    80,   417,
      93,    94,    95,   224,   241,    98,    99,   244,    30,   210,
      29,   379,    41,    41,   382,   282,   382,   242,    38,    50,
     241,   242,    49,   244,    41,    45,    46,    42,    48,    41,
      41,    41,    41,   282,    41,    41,    41,    41,   259,    41,
     241,   242,    55,   244,    47,   282,     3,    42,     5,     6,
      42,    42,     9,   421,    11,    12,    54,    14,   259,    49,
      17,   282,    42,    49,    21,    22,   348,   349,   350,   351,
     352,   353,   339,    42,    42,    42,    42,    49,    42,    42,
      42,   282,    39,   153,    49,   259,   217,    95,   216,    14,
     339,    74,   421,   225,   377,   224,   433,   310,   382,   177,
     385,   387,   339,   328,   329,   339,   337,   328,   329,   356,
      -1,   356,   379,    -1,   315,   382,   337,    -1,   339,    -1,
      -1,    -1,   341,    -1,    -1,    -1,    -1,   328,   329,    -1,
     379,    -1,    -1,   382,    -1,    -1,   337,    -1,   339,    -1,
      -1,    -1,   379,    -1,    -1,   382,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,   379,    -1,
      -1,   382,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   421,    -1,    -1,    -1,    41,    -1,   379,    -1,
      -1,   382,    -1,    -1,   421,   311,   312,   313,   314,    -1,
     316,   317,   318,   319,   320,   321,    -1,    -1,   324,    -1,
     421,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   405,
      -1,    -1,   408,    -1,    -1,    -1,    -1,   413,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
      -1,   101,    -1,    -1,   440,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
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
      92,    93,    94,    95,    96,    97,    98,    99,    41,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    95
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    15,   103,   106,   107,   109,    93,     0,     3,     5,
       6,     9,    11,    12,    14,    17,    21,    22,    39,   104,
     105,   113,   119,   120,   124,   148,   149,   151,   153,   154,
     160,   161,   108,    40,   130,   131,    37,   177,   177,    93,
      94,    95,   155,   286,   287,     7,   158,   162,    13,   159,
     159,    18,    19,   114,   115,    37,   215,    20,    98,    99,
     121,   122,   247,   248,   286,   118,    16,   110,     4,    37,
     170,   178,   152,   150,    10,   156,   157,   286,   286,   286,
     286,    20,   116,   117,   248,   216,   118,   247,   118,    23,
     125,   130,   111,   177,   171,    31,   132,   163,    32,    33,
      34,    35,    36,    52,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    96,
      97,   101,   172,   184,   221,   236,   237,   239,   240,   241,
     246,   248,   249,   276,   280,   281,   282,   283,   284,   285,
     286,   288,   123,   130,   123,   162,   248,   118,   217,   218,
     221,   130,   123,    24,   126,   127,   128,   129,   286,    94,
     172,   116,   238,   183,    44,   185,   186,   223,    41,   222,
      77,   100,   277,   278,   279,   130,    38,    44,   219,   220,
      25,   133,   134,   140,   133,   129,   112,   176,    37,    51,
     224,   235,   247,    38,   179,   180,   182,   172,   224,   229,
     230,   236,   243,   244,   245,   246,   224,   286,   133,   217,
      26,    29,    30,   135,   136,   139,   146,   147,    93,     7,
       8,    38,    45,    46,    48,   173,   175,   187,   188,   191,
     194,   198,   201,   202,   207,   164,    53,   231,   234,   245,
      44,   174,     7,    42,   242,    27,    28,    41,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,   141,
     142,   143,   144,   145,   208,   209,   248,   270,   271,   272,
     286,    80,    80,   137,   147,   138,   146,   195,   199,   189,
     192,   208,   174,   203,   165,   228,   233,   172,   247,   245,
      62,    63,    65,   248,   250,   251,   254,   257,   258,   261,
     262,   265,   268,   269,   270,   271,   274,   276,   280,   284,
     286,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,   142,   270,    41,   101,   210,   213,   196,   200,
     190,   193,   172,   170,    38,    41,   166,    50,   227,    49,
     232,   181,   269,   269,   269,    42,   253,   256,    56,    57,
      58,    59,    60,    61,   259,   260,   264,   267,   210,   275,
     250,   250,   250,   250,   248,   250,   250,   250,   250,   250,
     250,   250,   247,   247,   170,   170,    47,   204,   206,   167,
     225,   226,   235,   234,   177,    54,   252,    55,   255,   261,
     261,   261,   261,   261,   261,    62,    63,   263,   282,   283,
      20,    64,   266,    42,    42,    49,    42,    42,    49,    42,
      42,    42,    42,    49,   214,   197,   170,   205,   206,    43,
     168,   169,   246,   231,   254,   257,   265,   265,   268,   268,
     250,   250,   250,   212,   170,   170,    42,   168,    42,    42,
      49,   211,   273,    42,   211,   250,    42
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
     114,   114,   115,   115,   116,   116,   117,   117,   118,   118,
     119,   120,   121,   121,   122,   122,   123,   123,   124,   125,
     126,   126,   127,   128,   129,   130,   131,   131,   132,   132,
     133,   134,   134,   135,   135,   136,   137,   137,   138,   138,
     139,   139,   140,   141,   141,   142,   142,   143,   143,   144,
     145,   145,   146,   147,   148,   148,   148,   148,   148,   148,
     150,   149,   152,   151,   153,   154,   155,   155,   156,   157,
     157,   158,   158,   159,   159,   160,   161,   162,   164,   163,
     165,   165,   167,   166,   168,   168,   169,   169,   171,   170,
     172,   172,   173,   173,   174,   174,   175,   176,   176,   178,
     177,   180,   181,   179,   182,   183,   183,   184,   185,   186,
     186,   187,   187,   187,   187,   187,   189,   190,   188,   192,
     193,   191,   195,   196,   197,   194,   199,   200,   198,   202,
     203,   201,   205,   204,   206,   206,   207,   208,   208,   208,
     209,   210,   211,   212,   212,   213,   214,   213,   216,   215,
     217,   217,   218,   219,   220,   220,   222,   221,   223,   221,
     224,   225,   226,   226,   227,   228,   228,   229,   230,   230,
     231,   232,   233,   233,   234,   235,   235,   236,   236,   238,
     237,   239,   240,   240,   240,   240,   240,   241,   241,   242,
     242,   243,   244,   244,   245,   245,   246,   246,   247,   247,
     248,   248,   249,   249,   249,   249,   249,   249,   250,   251,
     252,   253,   253,   254,   255,   256,   256,   257,   258,   259,
     259,   259,   259,   259,   259,   260,   260,   261,   262,   263,
     263,   263,   263,   264,   264,   265,   266,   266,   267,   267,
     268,   268,   268,   268,   269,   269,   269,   269,   269,   269,
     269,   270,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   272,   273,   273,   274,   275,   275,   276,
     277,   278,   278,   279,   279,   280,   280,   280,   281,   281,
     281,   282,   282,   282,   283,   283,   283,   284,   284,   285,
     285,   285,   285,   286,   286,   287,   287,   288,   288
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SPARQLfedParser::yyr2_[] =
  {
         0,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       2,     0,     1,     0,     2,     2,     0,     0,     5,     6,
       1,     1,     0,     1,     1,     2,     1,     1,     0,     2,
       5,     5,     1,     2,     1,     1,     0,     1,     3,     2,
       1,     1,     1,     2,     1,     3,     0,     1,     0,     1,
       2,     0,     1,     0,     1,     1,     0,     1,     0,     1,
       2,     2,     3,     1,     2,     1,     1,     1,     1,     2,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       0,     4,     0,     4,     2,     3,     1,     2,     2,     0,
       1,     0,     1,     0,     1,     3,     3,     2,     0,     6,
       0,     2,     0,     4,     1,     1,     1,     2,     0,     5,
       0,     1,     1,     1,     0,     1,     3,     0,     2,     0,
       5,     0,     0,     5,     3,     0,     2,     2,     2,     0,
       1,     1,     1,     1,     1,     1,     0,     0,     4,     0,
       0,     4,     0,     0,     0,     6,     0,     0,     5,     0,
       0,     4,     0,     3,     0,     2,     2,     1,     1,     1,
       2,     1,     2,     0,     2,     1,     0,     5,     0,     4,
       0,     1,     2,     2,     0,     1,     0,     3,     0,     3,
       3,     2,     0,     1,     2,     0,     2,     1,     0,     1,
       2,     2,     0,     2,     1,     1,     1,     1,     1,     0,
       4,     4,     1,     1,     1,     1,     1,     0,     1,     0,
       2,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     0,     2,     2,     2,     0,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     0,     1,     1,     2,     2,
       2,     1,     1,     0,     2,     2,     2,     2,     0,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     4,     6,     4,     4,     6,     4,     4,
       4,     4,     1,     7,     0,     1,     2,     0,     1,     2,
       2,     1,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
  "PrefixDecl", "$@1", "$@2", "Select",
  "_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C",
  "_Q_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C_E_Opt", "_QVar_E_Plus",
  "_O_QVar_E_Plus_Or_QGT_TIMES_E_C", "_QDatasetClause_E_Star", "Construct",
  "Describe", "_QVarOrIRIref_E_Plus",
  "_O_QVarOrIRIref_E_Plus_Or_QGT_TIMES_E_C", "_QWhereClause_E_Opt", "Ask",
  "DatasetClause", "_O_QDefaultGraphClause_E_Or_QNamedGraphClause_E_C",
  "DefaultGraphClause", "NamedGraphClause", "SourceSelector",
  "WhereClause", "_QIT_WHERE_E_Opt", "_QBindingClause_E_Opt",
  "SolutionModifier", "_QOrderClause_E_Opt", "_QLimitOffsetClauses_E_Opt",
  "LimitOffsetClauses", "_QOffsetClause_E_Opt", "_QLimitClause_E_Opt",
  "_QLimitClause_E_S_QOffsetClause_E_Opt_Or_QOffsetClause_E_S_QLimitClause_E_Opt",
  "OrderClause", "_QOrderCondition_E_Plus", "OrderCondition",
  "_O_QIT_ASC_E_Or_QIT_DESC_E_C",
  "_O_QIT_ASC_E_Or_QIT_DESC_E_S_QBrackettedExpression_E_C",
  "_O_QConstraint_E_Or_QVar_E_C", "LimitClause", "OffsetClause", "Update",
  "Insert", "@3", "Delete", "@4", "Clear", "Load", "_QIRIref_E_Plus",
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
       103,     0,    -1,   106,   105,    -1,     3,   130,     4,   177,
      -1,   113,    -1,   119,    -1,   120,    -1,   124,    -1,   104,
      -1,   148,    -1,   107,   108,    -1,    -1,   109,    -1,    -1,
     108,   110,    -1,    15,    93,    -1,    -1,    -1,    16,   111,
      94,   112,    93,    -1,    17,   115,   117,   118,   130,   133,
      -1,    18,    -1,    19,    -1,    -1,   114,    -1,   248,    -1,
     116,   248,    -1,   116,    -1,    20,    -1,    -1,   118,   125,
      -1,    21,   215,   118,   130,   133,    -1,    22,   122,   118,
     123,   133,    -1,   247,    -1,   121,   247,    -1,   121,    -1,
      20,    -1,    -1,   130,    -1,    39,   118,   130,    -1,    23,
     126,    -1,   127,    -1,   128,    -1,   129,    -1,    24,   129,
      -1,   286,    -1,   131,   170,   132,    -1,    -1,    40,    -1,
      -1,   163,    -1,   134,   135,    -1,    -1,   140,    -1,    -1,
     136,    -1,   139,    -1,    -1,   147,    -1,    -1,   146,    -1,
     146,   137,    -1,   147,   138,    -1,    25,    26,   141,    -1,
     142,    -1,   141,   142,    -1,   144,    -1,   145,    -1,    27,
      -1,    28,    -1,   143,   270,    -1,   208,    -1,   248,    -1,
      29,    80,    -1,    30,    80,    -1,   149,    -1,   151,    -1,
     154,    -1,   153,    -1,   160,    -1,   161,    -1,    -1,     6,
     177,   150,   123,    -1,    -1,     5,   177,   152,   123,    -1,
      11,   158,    -1,     9,   155,   157,    -1,   286,    -1,   155,
     286,    -1,    10,   162,    -1,    -1,   156,    -1,    -1,   162,
      -1,    -1,    13,    -1,    14,   159,   286,    -1,    12,   159,
     286,    -1,     7,   286,    -1,    -1,    31,   116,    37,   164,
     165,    38,    -1,    -1,   165,   166,    -1,    -1,    41,   167,
     169,    42,    -1,   246,    -1,    43,    -1,   168,    -1,   169,
     168,    -1,    -1,    37,   171,   172,   176,    38,    -1,    -1,
     184,    -1,   187,    -1,   207,    -1,    -1,    44,    -1,   173,
     174,   172,    -1,    -1,   176,   175,    -1,    -1,    37,   178,
     172,   183,    38,    -1,    -1,    -1,   180,     7,   247,   181,
     177,    -1,   179,   174,   172,    -1,    -1,   183,   182,    -1,
     221,   186,    -1,    44,   172,    -1,    -1,   185,    -1,   188,
      -1,   191,    -1,   201,    -1,   194,    -1,   198,    -1,    -1,
      -1,    45,   189,   190,   170,    -1,    -1,    -1,    46,   192,
     193,   170,    -1,    -1,    -1,    -1,     7,   195,   196,   247,
     197,   170,    -1,    -1,    -1,     8,   199,   200,   247,   170,
      -1,    -1,    -1,   202,   203,   170,   206,    -1,    -1,    47,
     205,   170,    -1,    -1,   204,   206,    -1,    48,   208,    -1,
     270,    -1,   271,    -1,   209,    -1,   286,   210,    -1,   213,
      -1,    49,   250,    -1,    -1,   212,   211,    -1,   101,    -1,
      -1,    41,   250,   214,   212,    42,    -1,    -1,    37,   216,
     217,    38,    -1,    -1,   218,    -1,   221,   220,    -1,    44,
     217,    -1,    -1,   219,    -1,    -1,   246,   222,   224,    -1,
      -1,   236,   223,   229,    -1,   235,   231,   228,    -1,   235,
     231,    -1,    -1,   225,    -1,    50,   226,    -1,    -1,   228,
     227,    -1,   230,    -1,    -1,   224,    -1,   234,   233,    -1,
      49,   234,    -1,    -1,   233,   232,    -1,   245,    -1,   247,
      -1,    51,    -1,   239,    -1,   237,    -1,    -1,    52,   238,
     224,    53,    -1,   241,    41,   244,    42,    -1,    32,    -1,
      33,    -1,    34,    -1,    35,    -1,    36,    -1,    -1,   240,
      -1,    -1,   242,   245,    -1,   245,   242,    -1,    -1,   243,
      -1,   246,    -1,   236,    -1,   248,    -1,   249,    -1,   248,
      -1,   286,    -1,    98,    -1,    99,    -1,   286,    -1,   276,
      -1,   280,    -1,   284,    -1,   288,    -1,   101,    -1,   251,
      -1,   254,   253,    -1,    54,   254,    -1,    -1,   253,   252,
      -1,   257,   256,    -1,    55,   257,    -1,    -1,   256,   255,
      -1,   258,    -1,   261,   260,    -1,    56,   261,    -1,    57,
     261,    -1,    58,   261,    -1,    59,   261,    -1,    60,   261,
      -1,    61,   261,    -1,    -1,   259,    -1,   262,    -1,   265,
     264,    -1,    62,   265,    -1,    63,   265,    -1,   282,    -1,
     283,    -1,    -1,   264,   263,    -1,   268,   267,    -1,    20,
     268,    -1,    64,   268,    -1,    -1,   267,   266,    -1,    65,
     269,    -1,    62,   269,    -1,    63,   269,    -1,   269,    -1,
     270,    -1,   271,    -1,   274,    -1,   276,    -1,   280,    -1,
     284,    -1,   248,    -1,    41,   250,    42,    -1,    66,    41,
     250,    42,    -1,    67,    41,   250,    42,    -1,    68,    41,
     250,    49,   250,    42,    -1,    69,    41,   250,    42,    -1,
      70,    41,   248,    42,    -1,    71,    41,   250,    49,   250,
      42,    -1,    72,    41,   250,    42,    -1,    73,    41,   250,
      42,    -1,    74,    41,   250,    42,    -1,    75,    41,   250,
      42,    -1,   272,    -1,    76,    41,   250,    49,   250,   273,
      42,    -1,    -1,   211,    -1,   286,   275,    -1,    -1,   210,
      -1,   285,   279,    -1,    77,   286,    -1,   100,    -1,   277,
      -1,    -1,   278,    -1,   281,    -1,   282,    -1,   283,    -1,
      80,    -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,
      85,    -1,    86,    -1,    87,    -1,    88,    -1,    78,    -1,
      79,    -1,    89,    -1,    91,    -1,    90,    -1,    92,    -1,
      93,    -1,   287,    -1,    95,    -1,    94,    -1,    96,    -1,
      97,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SPARQLfedParser::yyprhs_[] =
  {
         0,     0,     3,     6,    11,    13,    15,    17,    19,    21,
      23,    26,    27,    29,    30,    33,    36,    37,    38,    44,
      51,    53,    55,    56,    58,    60,    63,    65,    67,    68,
      71,    77,    83,    85,    88,    90,    92,    93,    95,    99,
     102,   104,   106,   108,   111,   113,   117,   118,   120,   121,
     123,   126,   127,   129,   130,   132,   134,   135,   137,   138,
     140,   143,   146,   150,   152,   155,   157,   159,   161,   163,
     166,   168,   170,   173,   176,   178,   180,   182,   184,   186,
     188,   189,   194,   195,   200,   203,   207,   209,   212,   215,
     216,   218,   219,   221,   222,   224,   228,   232,   235,   236,
     243,   244,   247,   248,   253,   255,   257,   259,   262,   263,
     269,   270,   272,   274,   276,   277,   279,   283,   284,   287,
     288,   294,   295,   296,   302,   306,   307,   310,   313,   316,
     317,   319,   321,   323,   325,   327,   329,   330,   331,   336,
     337,   338,   343,   344,   345,   346,   353,   354,   355,   361,
     362,   363,   368,   369,   373,   374,   377,   380,   382,   384,
     386,   389,   391,   394,   395,   398,   400,   401,   407,   408,
     413,   414,   416,   419,   422,   423,   425,   426,   430,   431,
     435,   439,   442,   443,   445,   448,   449,   452,   454,   455,
     457,   460,   463,   464,   467,   469,   471,   473,   475,   477,
     478,   483,   488,   490,   492,   494,   496,   498,   499,   501,
     502,   505,   508,   509,   511,   513,   515,   517,   519,   521,
     523,   525,   527,   529,   531,   533,   535,   537,   539,   541,
     544,   547,   548,   551,   554,   557,   558,   561,   563,   566,
     569,   572,   575,   578,   581,   584,   585,   587,   589,   592,
     595,   598,   600,   602,   603,   606,   609,   612,   615,   616,
     619,   622,   625,   628,   630,   632,   634,   636,   638,   640,
     642,   644,   648,   653,   658,   665,   670,   675,   682,   687,
     692,   697,   702,   704,   712,   713,   715,   718,   719,   721,
     724,   727,   729,   731,   732,   734,   736,   738,   740,   742,
     744,   746,   748,   750,   752,   754,   756,   758,   760,   762,
     764,   766,   768,   770,   772,   774,   776,   778,   780
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   363,   363,   369,   377,   378,   379,   380,   381,   382,
     387,   391,   393,   397,   399,   403,   409,   411,   409,   421,
     428,   431,   438,   441,   446,   450,   458,   461,   468,   471,
     479,   487,   494,   498,   506,   509,   516,   519,   524,   531,
     538,   539,   543,   549,   555,   562,   569,   571,   575,   578,
     583,   590,   593,   598,   602,   607,   612,   615,   620,   623,
     628,   632,   640,   647,   651,   659,   661,   669,   672,   680,
     688,   689,   695,   701,   707,   708,   709,   710,   711,   712,
     716,   716,   725,   725,   734,   740,   747,   750,   758,   765,
     768,   772,   775,   779,   782,   788,   794,   800,   807,   807,
     817,   820,   828,   828,   838,   839,   846,   850,   858,   858,
     869,   871,   876,   877,   881,   883,   888,   892,   895,   900,
     900,   910,   913,   910,   924,   928,   930,   935,   940,   944,
     947,   951,   952,   953,   954,   955,   959,   961,   959,   975,
     977,   975,   986,   988,   990,   986,  1001,  1003,  1001,  1013,
    1016,  1013,  1026,  1026,  1040,  1042,  1046,  1057,  1058,  1059,
    1063,  1070,  1077,  1083,  1085,  1092,  1096,  1096,  1106,  1106,
    1114,  1116,  1121,  1126,  1130,  1132,  1136,  1136,  1139,  1139,
    1146,  1151,  1155,  1157,  1162,  1166,  1168,  1173,  1177,  1179,
    1184,  1189,  1193,  1195,  1199,  1206,  1210,  1217,  1218,  1222,
    1222,  1235,  1260,  1263,  1266,  1269,  1272,  1279,  1282,  1287,
    1290,  1298,  1315,  1318,  1322,  1323,  1327,  1330,  1334,  1337,
    1343,  1344,  1348,  1351,  1354,  1357,  1360,  1361,  1367,  1372,
    1381,  1388,  1391,  1399,  1408,  1415,  1418,  1425,  1430,  1441,
    1444,  1447,  1450,  1453,  1456,  1463,  1467,  1471,  1476,  1485,
    1488,  1491,  1494,  1501,  1504,  1512,  1521,  1524,  1531,  1534,
    1541,  1544,  1547,  1550,  1554,  1555,  1556,  1557,  1560,  1563,
    1566,  1572,  1578,  1581,  1584,  1587,  1590,  1593,  1596,  1599,
    1602,  1605,  1608,  1613,  1620,  1623,  1627,  1637,  1640,  1645,
    1653,  1660,  1664,  1672,  1676,  1680,  1681,  1682,  1686,  1687,
    1688,  1692,  1693,  1694,  1698,  1699,  1700,  1704,  1705,  1709,
    1710,  1711,  1712,  1716,  1717,  1721,  1722,  1726,  1727
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
  const int SPARQLfedParser::yylast_ = 882;
  const int SPARQLfedParser::yynnts_ = 187;
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
#line 3320 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 1733 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


