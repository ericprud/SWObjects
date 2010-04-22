
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
#line 233 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 360 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

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
#line 375 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(2) - (2)].p_Operation);
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 391 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Replace((yysemantic_stack_[(4) - (2)].p_WhereClause), driver.curOp);
	driver.curOp = NULL;
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 415 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 421 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 423 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 425 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 433 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Select((yysemantic_stack_[(4) - (1)].p_Project).distinctness, (yysemantic_stack_[(4) - (1)].p_Project).varSet, (yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 440 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 443 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 454 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Select((yysemantic_stack_[(3) - (1)].p_Project).distinctness, (yysemantic_stack_[(3) - (1)].p_Project).varSet, NULL, (yysemantic_stack_[(3) - (2)].p_WhereClause), (yysemantic_stack_[(3) - (3)].p_SolutionModifier));
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 461 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 469 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 472 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 479 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 487 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 494 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 502 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    { // _SPACECHAR ?
	(yyval.p_Expression) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new AliasedExpression((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : (yysemantic_stack_[(4) - (2)].p_Expression);
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 509 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 515 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 518 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 521 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 530 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExprList) = new ExprList((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 533 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExprList)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    (yyval.p_ExprList) = (yysemantic_stack_[(2) - (1)].p_ExprList);
}
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 540 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExprList); // Grammar action needed for implicit upcast.
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 543 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 550 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	(yyval.p_Operation) = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(5) - (2)].p_BasicGraphPattern), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 558 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 565 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExprList) = new ExprList();
	(yyval.p_ExprList)->push_back(new POSExpression((yysemantic_stack_[(1) - (1)].p_POS)));
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 569 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
      (yysemantic_stack_[(2) - (1)].p_ExprList)->push_back(new POSExpression((yysemantic_stack_[(2) - (2)].p_POS)));
	(yyval.p_ExprList) = (yysemantic_stack_[(2) - (1)].p_ExprList);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 577 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExprList);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 580 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 587 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 595 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(3) - (2)].p_DatasetClauses), (yysemantic_stack_[(3) - (3)].p_WhereClause));
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 602 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 614 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_POS), driver.posFactory);
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 620 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_POS), driver.posFactory);
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 626 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 633 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp, (yysemantic_stack_[(3) - (3)].p_BindingClause));
	driver.curOp = NULL;
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 646 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 654 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 661 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 669 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 677 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 685 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 693 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(3) - (3)].p_Expressions);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 700 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 703 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 712 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new AliasedExpression((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : (yysemantic_stack_[(4) - (2)].p_Expression);
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 715 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 721 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 727 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 730 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 742 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 749 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 753 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 763 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 771 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 774 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 782 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 791 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 798 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 802 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 810 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 818 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 825 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 831 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 850 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 853 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert((yysemantic_stack_[(4) - (3)].p_TableOperation), (yysemantic_stack_[(4) - (4)].p_WhereClause));
      }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 859 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 862 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(4) - (3)].p_TableOperation), (yysemantic_stack_[(4) - (4)].p_WhereClause));
      }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 868 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(2) - (2)].p_URI));
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 874 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 881 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(3) - (2)].p_URIs), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 888 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URIs) = new ProductionVector<const URI*>((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 891 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_URIs)->push_back((yysemantic_stack_[(2) - (2)].p_URI));
	(yyval.p_URIs) = (yysemantic_stack_[(2) - (1)].p_URIs);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 899 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 906 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 913 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 919 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 922 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 928 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 934 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 941 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_POSList));
      }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 943 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = driver.curBindingClause;
	  driver.curBindingClause = NULL;
      }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 951 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSList) = new POSList;
	(yyval.p_POSList)->push_back((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 955 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_POSList) = (yysemantic_stack_[(2) - (1)].p_POSList);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 963 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Bindings) = NULL;
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 966 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingClause->push_back((yysemantic_stack_[(2) - (2)].p_Binding));
	(yyval.p_Bindings) = NULL;
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 974 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding = new Binding();
      }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 976 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Binding) = driver.curBinding;
	  driver.curBinding = NULL;
      }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 985 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getNULL();
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 992 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_POS));
	(yyval.p_POSs) = NULL;
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 996 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = NULL;
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1004 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1007 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1057 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1060 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
      }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1067 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curFilter = NULL;
      }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1070 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_POS);
      }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1073 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(5) - (3)].p_POS), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(5) - (4)].p_POS);
      }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1116 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 1118 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.curFilter;
      }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 1120 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 173:

/* Line 678 of lalr1.cc  */
#line 1132 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1134 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 1136 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.curOp));
      }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 1143 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 1145 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 1147 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_POS);
      }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 1150 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_POS), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_POS);
      }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 1158 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 1160 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 1162 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(5) - (4)].p_POS), driver.curOp, driver.posFactory, false));
      }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 1170 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 1173 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 1175 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 1183 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 1188 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 1203 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    if (driver.curOp == NULL)
		driver.ensureBasicGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 1220 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1227 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1231 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1233 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList);
	  driver.curExprList = NULL;
      }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1241 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 1249 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 1256 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 1258 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 1266 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 1268 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 1296 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 1299 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 1359 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.posFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_POS)));
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 1366 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_POS);
	driver.curPredicate = (yyval.p_POS);
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 1370 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_POS);
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 1382 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 1386 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 1395 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 237:

/* Line 678 of lalr1.cc  */
#line 1420 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 1423 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 1426 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 1429 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 1432 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 1439 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 1447 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSs) = new ProductionVector<const POS*>();
	(yyval.p_POSs)->push_back((yysemantic_stack_[(1) - (1)].p_POS));
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 1452 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSs)->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = (yysemantic_stack_[(2) - (1)].p_POSs);
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 1464 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 1471 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 1474 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 1485 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 1488 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 1491 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 1494 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 1498 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 1509 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 1518 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 1525 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 1528 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 1536 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 1545 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 1552 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 1555 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 1567 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_BooleanComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_BooleanComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_BooleanComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 1578 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 1581 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 1584 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 1587 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 1590 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yyval.p_BooleanComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 1593 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 1600 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = NULL;
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 1613 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 1622 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 1625 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 1628 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 1631 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 1638 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 1641 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 1649 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 1658 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 1661 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 1668 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 1671 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 1678 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 1681 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 1684 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 1694 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 1697 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 1700 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 1703 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 1709 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 1715 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-str"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 1718 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-lang"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 1721 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-langMatches"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 1724 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-datatype"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 1727 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-bound"), new POSExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 1730 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sameTerm"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 1733 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 1736 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 1739 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isBlank"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 1742 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isLiteral"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 1750 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-regex"), (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 1757 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 1764 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-count"), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 1767 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sum"), (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression)));
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 1770 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-min"), (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression)));
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 1773 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-max"), (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression)));
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 1776 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-avg"), (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression)));
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 1779 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	throw NotImplemented("CONCAT");
	// $$ = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-group-concat"), $4, $2));
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 1783 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sample"), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 1789 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 1792 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 1798 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 1805 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 1812 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new POSExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 1822 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 1830 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 1838 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 1845 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 1849 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 1857 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 2524 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -389;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        33,   -72,    64,   459,  -389,  -389,  -389,  -389,    38,    34,
      34,    -6,    75,    74,    74,    25,    65,    11,  -389,  -389,
    -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,
    -389,  -389,  -389,  -389,    91,  -389,   105,    93,  -389,  -389,
    -389,  -389,  -389,  -389,     0,  -389,  -389,    -6,  -389,  -389,
    -389,    -6,    -6,  -389,  -389,  -389,   638,  -389,  -389,  -389,
    -389,  -389,   116,  -389,  -389,  -389,  -389,    -3,    -3,  -389,
    -389,    34,  -389,    80,   547,     9,     9,    75,  -389,  -389,
    -389,  -389,  -389,  -389,  -389,   925,    95,   100,   101,   103,
     104,   106,   107,   114,   118,   119,   122,   136,   137,   138,
     140,   141,   132,   145,  -389,  -389,  -389,  -389,  -389,  -389,
    -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,
    -389,   859,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,
    -389,  -389,  -389,  -389,   -59,   -32,   547,    -3,  -389,     2,
     -16,  -389,  -389,   126,   102,  -389,   514,   -56,  -389,  -389,
    -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,
    -389,   168,  -389,  -389,  -389,  -389,   172,  -389,  -389,  -389,
    -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,   925,
     970,   970,   970,  -389,   155,  -389,  -389,  -389,  -389,   171,
    -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,
     -32,   925,   925,   925,   925,   -56,   925,   925,   925,   925,
     925,   925,   198,   198,   198,   198,   198,   925,  -389,   178,
     198,  -389,    -6,  -389,  -389,  -389,  -389,   925,  -389,  -389,
     185,  -389,   190,   126,   126,    -6,  -389,  -389,  -389,  -389,
    -389,   210,  -389,   158,  -389,  -389,  -389,    38,   202,  -389,
    -389,    13,  -389,    28,   205,   547,  -389,  -389,    28,   741,
      28,   204,  -389,  -389,  -389,   -56,  -389,   212,   203,   201,
     925,   925,   925,   925,   925,   925,  -389,  -389,   262,     4,
    -389,  -389,   225,   231,   227,   232,   239,   234,   242,   243,
     244,   246,   241,  -389,    99,   925,   925,   925,   925,  -389,
     198,   925,  -389,  -389,  -389,   547,  -389,  -389,  -389,  -389,
    -389,  1015,  1036,   267,  -389,   189,   126,  -389,   290,  -389,
    -389,  -389,   249,   741,  -389,  -389,   251,   289,  -389,  -389,
    -389,  -389,  -389,  -389,   717,  -389,  -389,  -389,  -389,  -389,
    -389,   925,  -389,   925,  -389,  -389,  -389,  -389,  -389,  -389,
    -389,   925,   925,  -389,  -389,  -389,   925,   925,  -389,  -389,
    -389,   925,  -389,  -389,   925,  -389,  -389,  -389,  -389,   925,
    -389,  -389,   257,   261,   264,   265,   268,  -389,   -32,   269,
    -389,  -389,   925,  1015,  -389,  -389,  -389,  -389,  1036,  -389,
    -389,  -389,  -389,  -389,   278,    31,  -389,  -389,  -389,  -389,
    -389,  -389,  -389,  1036,   251,  -389,  -389,  -389,  -389,  -389,
    -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,
     547,   116,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,
     271,   275,   260,  -389,   276,   277,   280,   286,   -23,   287,
    -389,   -14,   155,  -389,  -389,   312,   229,   250,  -389,  -389,
     300,   303,  -389,  -389,  -389,  -389,  -389,   547,    93,    17,
     284,   293,  -389,  -389,  -389,  -389,   925,  -389,   304,  -389,
    -389,  -389,  -389,  -389,  -389,  -389,  -389,   305,  -389,  -389,
     312,  -389,   308,  -389,  -389,  -389,  -389,  -389,  -389,  -389,
    -389,  -389,  -389,   116,   116,    93,    93,  -389,  -389,  -389,
    -389,  -389,    28,  -389,   741,  -389,    34,  -389,  -389,  -389,
    -389,  -389,  -389,    93,  -389,  -389,   298,   785,  -389,  -389,
     741,  -389,  -389,    93,  -389,  -389,  -389,  -389,  -389,   812,
    -389,  -389,  -389,    93,  -389,  -389,  -389
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        11,     0,     0,     0,    13,    12,    15,     1,    60,     0,
       0,     0,   114,   123,   123,    26,     0,     0,    20,     2,
       7,     3,    20,     4,     5,     6,     8,   102,   107,   108,
     104,   103,   105,   106,    10,    61,     0,     0,   153,   111,
     109,   358,   361,   360,   120,   117,   359,     0,   113,   115,
     124,     0,     0,    24,    25,    27,     0,   203,    20,    49,
     252,   253,    48,    20,    46,   250,   251,    60,    60,    16,
      14,     0,   139,    62,   144,    50,    50,     0,   121,   116,
     118,   126,   125,   122,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   329,     0,   352,   353,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   354,   356,   355,   357,    39,
      40,    42,    23,    35,    32,    34,   314,    33,    36,    37,
     340,   341,   342,    38,   338,     0,   205,    60,    47,    50,
       0,    21,    52,    65,     0,     9,   144,     0,    59,    63,
     237,   238,   239,   240,   241,   234,   362,   363,   259,   159,
     145,   163,   213,   233,   232,   243,     0,   211,   248,   249,
     255,   256,   257,   254,   258,   112,    51,   110,   119,     0,
       0,     0,     0,   302,    29,   260,   263,   267,   269,   277,
     279,   285,   290,   295,   296,   297,   298,   299,   300,   301,
     332,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   325,   325,   325,   325,   325,     0,   330,     0,
     325,    41,     0,   336,   337,   339,   334,     0,   195,   194,
       0,   206,   209,    65,    65,     0,    53,    54,    55,    56,
      58,     0,    19,    67,    66,    17,   141,    60,     0,   142,
     151,     0,   129,     0,   155,   144,   164,   161,   223,   242,
       0,     0,   293,   294,   292,     0,    30,     0,   261,   265,
       0,     0,     0,     0,     0,     0,   278,   270,   280,   287,
     333,   331,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   326,     0,     0,     0,     0,     0,   201,
     325,     0,   335,   196,   204,   205,   210,   207,    44,    45,
      57,     0,     0,    69,    68,     0,    65,   140,   143,   127,
     130,   231,     0,   242,   230,   154,   148,     0,   160,   162,
     224,   214,   222,   247,   242,   244,   246,   212,   303,    28,
      31,     0,   264,     0,   268,   271,   272,   273,   274,   275,
     276,     0,     0,   286,   283,   284,     0,     0,   291,   304,
     305,     0,   307,   308,     0,   310,   311,   312,   313,     0,
     327,   328,     0,     0,     0,     0,     0,   199,     0,     0,
     199,   208,     0,    73,    74,    77,    79,    76,    80,    81,
      83,   193,   191,   192,     0,    71,    70,    18,    22,   176,
     180,   170,   173,     0,   148,   152,   146,   165,   166,   168,
     169,   167,   184,   147,   131,   235,   220,   227,   229,   149,
     144,     0,   236,   245,   262,   266,   281,   282,   288,   289,
       0,     0,   316,   318,     0,     0,     0,     0,     0,     0,
     324,     0,    29,    75,    82,     0,     0,     0,    64,    72,
      96,    98,   177,   181,   171,   174,   190,   144,     0,     0,
     215,   225,   158,   156,   306,   309,     0,   317,     0,   319,
     320,   321,   322,   202,   200,   323,   197,     0,    89,    90,
      84,    85,     0,    87,    88,    92,    93,   100,   101,    94,
      97,    95,    99,     0,     0,     0,     0,   150,   188,   128,
     133,   132,   217,   221,   242,   228,     0,   198,   315,    78,
      86,    91,   178,     0,   172,   175,   185,     0,   218,   219,
     242,   226,   157,     0,   182,   186,   189,   136,   137,     0,
     135,   216,   179,     0,   134,   138,   187
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,
    -389,  -389,    12,  -389,   206,  -389,  -389,  -389,   -92,  -389,
     230,  -389,  -389,  -389,  -389,  -389,  -389,   -53,  -389,  -389,
    -389,  -389,  -389,   120,     6,  -389,  -389,  -221,  -389,  -389,
    -389,  -389,  -389,  -389,   -29,  -389,  -389,   -26,  -389,  -389,
    -110,  -389,  -389,  -389,  -389,  -389,  -389,   -80,   -77,  -389,
    -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,
    -389,  -389,   360,  -389,   299,  -389,  -389,  -389,  -389,  -389,
    -389,  -140,  -389,  -278,  -389,  -389,  -389,  -143,  -389,   -13,
    -389,  -389,    -9,  -389,  -389,  -389,  -389,  -389,  -389,  -389,
    -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,
    -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,
    -389,  -389,  -389,  -388,   -52,  -195,  -389,   -42,    14,  -389,
    -389,  -389,  -389,    90,  -389,  -389,  -389,  -129,  -389,  -389,
    -193,  -389,  -389,  -389,  -389,  -389,  -389,  -124,  -389,  -389,
    -107,  -104,  -240,  -389,  -389,  -389,  -389,  -389,  -389,  -237,
    -238,   -15,    10,  -389,   334,  -389,  -389,  -389,    58,  -389,
    -389,    57,  -389,  -389,  -389,    94,  -389,  -389,  -389,  -225,
    -389,  -389,  -243,    70,  -295,   -40,  -389,  -389,  -389,   -62,
    -389,  -389,  -389,  -389,   -45,  -389,  -389,  -389,   -18,  -389,
     123,   125,     3,  -389,   -11,  -389,  -389
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,    19,    20,     3,     4,    34,     5,    70,   144,
     315,    21,    67,   246,    22,    55,    56,   266,   267,   119,
     120,   121,   122,    23,    24,    62,    63,   175,    25,   141,
     236,   237,   238,   239,   176,    37,   148,   242,   243,   313,
     395,   448,   244,   383,   384,   314,   388,   389,   396,   480,
     481,   482,   483,   484,   449,   489,   491,   450,   451,    26,
      27,    28,    76,    29,    75,    30,    48,    31,    44,    78,
      79,    32,    51,    33,    49,   149,   414,   251,   459,   501,
     517,   528,   529,    73,   146,   248,   249,   159,   404,   420,
     405,   318,    39,    74,   326,   327,   506,   328,   254,   160,
     256,   257,   406,   407,   454,   495,   408,   455,   496,   409,
     452,   493,   523,   410,   453,   494,   411,   412,   458,   526,
     533,   516,   413,   390,   391,   229,   380,   474,   438,   218,
     377,    58,   136,   230,   231,   306,   307,   161,   260,   258,
     322,   518,   519,   503,   460,   331,   332,   416,   505,   461,
     417,   323,   162,   163,   253,   164,   165,   166,   334,   418,
     167,   324,   183,   169,   184,   185,   342,   268,   186,   344,
     269,   187,   188,   276,   277,   189,   190,   353,   278,   191,
     358,   279,   192,   193,   194,   195,   126,   468,   127,   294,
     372,   219,   196,   281,   197,   224,   225,   226,   198,   130,
     131,   132,   199,   134,   200,    46,   174
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SPARQLfedParser::yytable_ninf_ = -243;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        45,    40,    64,   250,   123,   280,    66,   232,   235,   227,
      77,   128,   308,   309,    36,   456,   125,   392,   222,   333,
     140,   336,   335,   177,   356,   140,   466,    65,   476,   170,
     473,    59,     6,    80,    68,   466,    81,    35,   129,   -60,
      82,    83,    35,    53,    54,   135,   -60,   138,     1,    35,
     319,    66,   223,    60,    61,   499,   171,   485,   500,   133,
     446,   447,   145,   173,     7,   330,   124,   337,   357,   123,
     137,    38,    65,   142,   143,   139,   128,   172,    35,   321,
     228,   125,    47,   333,   168,   336,   234,    50,    41,    42,
      43,   170,   485,   392,   333,   398,   336,   423,    41,    42,
      43,   170,    57,   129,    41,    42,    43,    69,   392,    71,
     135,   147,   329,   428,   429,    41,    42,    43,   171,   370,
      60,    61,    60,    61,   133,   173,   426,   427,   171,   240,
      72,   124,    41,    42,    43,   173,   201,    60,    61,   172,
     179,   202,   203,   233,   204,   205,   168,   206,   207,   172,
     392,   295,   296,   297,   298,   208,   168,   252,   301,   209,
     210,   180,   181,   211,   182,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,   232,   212,   213,   214,
     498,   215,   216,   439,   217,   392,   220,   511,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    41,    42,    43,   241,   245,    60,    61,
     170,   302,   255,   259,   170,   286,   293,   514,   515,   300,
      41,    42,    43,   304,   240,    60,    61,   270,   271,   272,
     273,   274,   275,   265,   305,   524,   311,   171,   378,   312,
     317,   171,    66,   325,   173,   532,   338,    66,   173,    66,
     262,   263,   264,   316,   340,   536,   343,   341,   172,   385,
     170,   320,   172,    65,   333,   168,   336,   359,    65,   168,
      65,   387,   393,   360,   362,   339,   361,   462,   170,   530,
     333,   363,   336,   364,   365,   366,   367,   171,   368,   170,
     369,   530,   394,   397,   173,   419,   421,   399,   400,   433,
     135,   135,   415,   434,   445,   171,   435,   436,   172,   466,
     437,   440,   173,   464,   497,   168,   171,   465,   469,   470,
     487,   386,   471,   173,   351,   352,   172,  -183,   472,   475,
     447,   385,   446,   168,   502,   401,   402,   172,   403,   478,
     479,   488,   504,   387,   168,   525,   508,   509,   393,   179,
     477,   221,   247,   179,   443,   310,   109,   110,   111,   112,
     113,   114,   444,   393,   345,   346,   347,   348,   349,   350,
     510,   492,   135,   490,    52,   170,   178,   135,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,   535,
     467,   457,   135,   386,   441,   381,   531,   521,   520,   424,
     425,   354,   171,   355,     0,   393,   463,     0,     0,   173,
      66,     0,   170,     0,     0,     0,    41,    42,    43,     0,
       0,    60,    61,   172,     0,     0,     0,     0,     0,     0,
     168,    65,     0,     0,   135,     0,     0,     0,     0,   171,
     393,     0,     0,     0,     0,     0,   173,     0,     0,     0,
       0,     0,     0,     0,     0,   486,     0,     0,     0,   170,
     172,     0,     8,     0,     9,    10,     0,   168,    11,   135,
      12,    13,   170,    14,     0,   170,    15,     0,   512,   513,
      16,    17,    66,    66,   170,     0,   171,     0,     0,     0,
     486,    66,     0,   173,     0,     0,     0,   522,    18,   171,
       0,     0,   171,    65,    65,     0,   173,   172,     0,   173,
       0,   171,    65,   261,   168,     0,     0,     0,   173,     0,
     172,     0,     0,   172,     0,     0,     0,   168,     0,     0,
     168,    15,   172,     0,     0,   282,   283,   284,   285,   168,
     287,   288,   289,   290,   291,   292,   150,   151,   152,   153,
     154,   299,     0,     0,     0,  -242,     0,     0,     0,     0,
       0,   303,     0,     0,     0,     0,   155,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   150,
     151,   152,   153,   154,     0,     0,     0,     0,  -242,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   155,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,    41,    42,
      43,   156,   157,    60,    61,     0,   158,     0,   371,   373,
     374,   375,   376,     0,     0,   379,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    41,    42,    43,   156,   157,    60,    61,    84,   158,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   430,     0,     0,   431,     0,
       0,     0,     0,   432,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,     0,   442,     0,     0,     0,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    41,    42,    43,     0,     0,    60,    61,   150,
     151,   152,   153,   154,     0,     0,     0,     0,     0,   422,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   155,
       0,     0,     0,   150,   151,   152,   153,   154,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   155,     0,     0,     0,     0,     0,     0,
     507,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    41,    42,    43,   156,   157,    60,    61,   527,   158,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    41,    42,    43,   156,   157,
      60,    61,     0,   158,   534,   527,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    41,
      42,    43,   156,   157,    60,    61,     0,   158,     0,     0,
      85,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    41,    42,    43,   156,
     157,    60,    61,     0,   158,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    41,    42,    43,   179,     0,    60,    61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   180,   181,     0,
     182,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   179,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    41,
      42,    43,     0,     0,    60,    61,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   382,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    41,    42,    43,   179,     0,    60,
      61,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,     0,     0,     0,     0,     0,     0,    41,
      42,    43,     0,     0,    60,    61,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,    42,    43
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        11,    10,    17,   146,    56,   200,    17,   136,    24,    41,
      10,    56,   233,   234,     8,   403,    56,   312,    77,   259,
      23,   259,   259,    76,    20,    23,    49,    17,    42,    74,
      53,    20,   104,    44,    22,    49,    47,    40,    56,    37,
      51,    52,    40,    18,    19,    56,    37,    62,    15,    40,
      37,    62,   111,   109,   110,    38,    74,   445,    41,    56,
      29,    30,    71,    74,     0,   258,    56,   260,    64,   121,
      58,    37,    62,    67,    68,    63,   121,    74,    40,    51,
     112,   121,     7,   323,    74,   323,   139,    13,   104,   105,
     106,   136,   480,   388,   334,   316,   334,   334,   104,   105,
     106,   146,    37,   121,   104,   105,   106,    16,   403,     4,
     121,    31,   255,   356,   357,   104,   105,   106,   136,    20,
     109,   110,   109,   110,   121,   136,   351,   352,   146,   140,
      37,   121,   104,   105,   106,   146,    41,   109,   110,   136,
      41,    41,    41,   137,    41,    41,   136,    41,    41,   146,
     445,   213,   214,   215,   216,    41,   146,   147,   220,    41,
      41,    62,    63,    41,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,   305,    41,    41,    41,
     458,    41,    41,   378,    52,   480,    41,   482,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,    80,   105,   109,   110,
     255,   222,    44,    41,   259,   205,    18,   495,   496,    41,
     104,   105,   106,    38,   235,   109,   110,    56,    57,    58,
      59,    60,    61,    78,    44,   513,    26,   255,   300,    81,
      38,   259,   253,    38,   255,   523,    42,   258,   259,   260,
     180,   181,   182,   247,    42,   533,    55,    54,   255,   311,
     305,   251,   259,   253,   504,   255,   504,    42,   258,   259,
     260,   311,   312,    42,    42,   265,    49,   420,   323,   517,
     520,    42,   520,    49,    42,    42,    42,   305,    42,   334,
      49,   529,    25,   104,   305,    44,     7,     7,     8,    42,
     311,   312,    53,    42,    26,   323,    42,    42,   305,    49,
      42,    42,   323,    42,   457,   305,   334,    42,    42,    42,
      91,   311,    42,   334,    62,    63,   323,    37,    42,    42,
      30,   383,    29,   323,    50,    45,    46,   334,    48,    27,
      28,    91,    49,   383,   334,    47,    42,    42,   388,    41,
     442,   121,   146,    41,   383,   235,    94,    95,    96,    97,
      98,    99,   388,   403,   270,   271,   272,   273,   274,   275,
     480,   451,   383,   450,    14,   420,    77,   388,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,   529,
     432,   404,   403,   383,   380,   305,   520,   504,   502,   341,
     343,   278,   420,   278,    -1,   445,   421,    -1,    -1,   420,
     421,    -1,   457,    -1,    -1,    -1,   104,   105,   106,    -1,
      -1,   109,   110,   420,    -1,    -1,    -1,    -1,    -1,    -1,
     420,   421,    -1,    -1,   445,    -1,    -1,    -1,    -1,   457,
     480,    -1,    -1,    -1,    -1,    -1,   457,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   445,    -1,    -1,    -1,   504,
     457,    -1,     3,    -1,     5,     6,    -1,   457,     9,   480,
      11,    12,   517,    14,    -1,   520,    17,    -1,   493,   494,
      21,    22,   493,   494,   529,    -1,   504,    -1,    -1,    -1,
     480,   502,    -1,   504,    -1,    -1,    -1,   506,    39,   517,
      -1,    -1,   520,   493,   494,    -1,   517,   504,    -1,   520,
      -1,   529,   502,   179,   504,    -1,    -1,    -1,   529,    -1,
     517,    -1,    -1,   520,    -1,    -1,    -1,   517,    -1,    -1,
     520,    17,   529,    -1,    -1,   201,   202,   203,   204,   529,
     206,   207,   208,   209,   210,   211,    32,    33,    34,    35,
      36,   217,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,    -1,   112,    -1,   294,   295,
     296,   297,   298,    -1,    -1,   301,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    20,   112,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   361,    -1,    -1,   364,    -1,
      -1,    -1,    -1,   369,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,   382,    -1,    -1,    -1,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,    -1,    -1,   109,   110,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
     466,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    43,   112,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    -1,   112,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,   112,    -1,    -1,
      41,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    -1,   112,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,    41,    -1,   109,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    -1,    -1,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,    -1,    -1,   109,   110,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    41,    -1,   109,
     110,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,   104,
     105,   106,    -1,    -1,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,   105,   106
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    15,   114,   117,   118,   120,   104,     0,     3,     5,
       6,     9,    11,    12,    14,    17,    21,    22,    39,   115,
     116,   124,   127,   136,   137,   141,   172,   173,   174,   176,
     178,   180,   184,   186,   119,    40,   147,   148,    37,   205,
     205,   104,   105,   106,   181,   317,   318,     7,   179,   187,
      13,   185,   185,    18,    19,   128,   129,    37,   244,    20,
     109,   110,   138,   139,   274,   275,   317,   125,   125,    16,
     121,     4,    37,   196,   206,   177,   175,    10,   182,   183,
     317,   317,   317,   317,    20,    41,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   132,
     133,   134,   135,   237,   275,   298,   299,   301,   307,   311,
     312,   313,   314,   315,   316,   317,   245,   125,   274,   125,
      23,   142,   147,   147,   122,   205,   197,    31,   149,   188,
      32,    33,    34,    35,    36,    52,   107,   108,   112,   200,
     212,   250,   265,   266,   268,   269,   270,   273,   275,   276,
     307,   311,   315,   317,   319,   140,   147,   140,   187,    41,
      62,    63,    65,   275,   277,   278,   281,   284,   285,   288,
     289,   292,   295,   296,   297,   298,   305,   307,   311,   315,
     317,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    52,   242,   304,
      41,   133,    77,   111,   308,   309,   310,    41,   112,   238,
     246,   247,   250,   147,   140,    24,   143,   144,   145,   146,
     317,    80,   150,   151,   155,   105,   126,   127,   198,   199,
     200,   190,   275,   267,   211,    44,   213,   214,   252,    41,
     251,   277,   296,   296,   296,    78,   130,   131,   280,   283,
      56,    57,    58,    59,    60,    61,   286,   287,   291,   294,
     238,   306,   277,   277,   277,   277,   275,   277,   277,   277,
     277,   277,   277,    18,   302,   302,   302,   302,   302,   277,
      41,   302,   317,   277,    38,    44,   248,   249,   150,   150,
     146,    26,    81,   152,   158,   123,   147,    38,   204,    37,
     275,    51,   253,   264,   274,    38,   207,   208,   210,   200,
     253,   258,   259,   265,   271,   272,   273,   253,    42,   275,
      42,    54,   279,    55,   282,   288,   288,   288,   288,   288,
     288,    62,    63,   290,   313,   314,    20,    64,   293,    42,
      42,    49,    42,    42,    49,    42,    42,    42,    42,    49,
      20,   277,   303,   277,   277,   277,   277,   243,   302,   277,
     239,   246,    41,   156,   157,   237,   275,   298,   159,   160,
     236,   237,   297,   298,    25,   153,   161,   104,   150,     7,
       8,    45,    46,    48,   201,   203,   215,   216,   219,   222,
     226,   229,   230,   235,   189,    53,   260,   263,   272,    44,
     202,     7,    42,   272,   281,   284,   292,   292,   295,   295,
     277,   277,   277,    42,    42,    42,    42,    42,   241,   238,
      42,   241,   277,   157,   160,    26,    29,    30,   154,   167,
     170,   171,   223,   227,   217,   220,   236,   202,   231,   191,
     257,   262,   200,   274,    42,    42,    49,   240,   300,    42,
      42,    42,    42,    53,   240,    42,    42,   131,    27,    28,
     162,   163,   164,   165,   166,   236,   275,    91,    91,   168,
     171,   169,   170,   224,   228,   218,   221,   200,   196,    38,
      41,   192,    50,   256,    49,   261,   209,   277,    42,    42,
     163,   297,   274,   274,   196,   196,   234,   193,   254,   255,
     264,   263,   205,   225,   196,    47,   232,    43,   194,   195,
     273,   260,   196,   233,    42,   194,   196
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
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  SPARQLfedParser::yyr1_[] =
  {
         0,   113,   114,   115,   115,   115,   115,   115,   115,   116,
     117,   118,   118,   119,   119,   120,   122,   123,   121,   124,
     125,   125,   126,   127,   128,   128,   129,   129,   130,   131,
     131,   132,   133,   133,   133,   133,   133,   133,   133,   133,
     134,   134,   135,   135,   136,   137,   138,   138,   139,   139,
     140,   140,   141,   142,   143,   143,   144,   145,   146,   147,
     148,   148,   149,   149,   150,   151,   151,   152,   152,   153,
     153,   154,   154,   155,   156,   156,   157,   157,   157,   157,
     158,   159,   159,   160,   161,   162,   162,   163,   163,   164,
     164,   165,   166,   166,   167,   167,   168,   168,   169,   169,
     170,   171,   172,   172,   172,   172,   172,   173,   173,   175,
     174,   177,   176,   178,   179,   179,   180,   181,   181,   182,
     183,   183,   184,   185,   185,   186,   187,   189,   188,   190,
     190,   191,   191,   193,   192,   194,   194,   195,   195,   197,
     196,   198,   198,   199,   200,   200,   201,   201,   202,   202,
     203,   204,   204,   206,   205,   208,   209,   207,   210,   211,
     211,   212,   213,   214,   214,   215,   215,   215,   215,   215,
     217,   218,   216,   220,   221,   219,   223,   224,   225,   222,
     227,   228,   226,   230,   231,   229,   233,   232,   234,   234,
     235,   236,   236,   236,   237,   238,   239,   238,   240,   241,
     241,   243,   242,   245,   244,   246,   246,   247,   248,   249,
     249,   251,   250,   252,   250,   253,   254,   255,   255,   256,
     257,   257,   258,   259,   259,   260,   261,   262,   262,   263,
     264,   264,   265,   265,   267,   266,   268,   269,   269,   269,
     269,   269,   270,   270,   271,   271,   272,   272,   273,   273,
     274,   274,   275,   275,   276,   276,   276,   276,   276,   276,
     277,   278,   279,   280,   280,   281,   282,   283,   283,   284,
     285,   286,   286,   286,   286,   286,   286,   287,   287,   288,
     289,   290,   290,   290,   290,   291,   291,   292,   293,   293,
     294,   294,   295,   295,   295,   295,   296,   296,   296,   296,
     296,   296,   296,   297,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   299,   300,   300,   301,   301,
     301,   301,   301,   301,   301,   302,   302,   303,   303,   304,
     304,   305,   306,   306,   307,   308,   309,   309,   310,   310,
     311,   311,   311,   312,   312,   312,   313,   313,   313,   314,
     314,   314,   315,   315,   316,   316,   316,   316,   317,   317,
     318,   318,   319,   319
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SPARQLfedParser::yyr2_[] =
  {
         0,     2,     2,     1,     1,     1,     1,     1,     1,     4,
       2,     0,     1,     0,     2,     2,     0,     0,     5,     4,
       0,     2,     3,     3,     1,     1,     0,     1,     2,     0,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     5,     5,     1,     2,     1,     1,
       0,     1,     3,     2,     1,     1,     1,     2,     1,     3,
       0,     1,     0,     1,     4,     0,     1,     0,     1,     0,
       1,     0,     1,     3,     1,     2,     1,     1,     4,     1,
       2,     1,     2,     1,     3,     1,     2,     1,     1,     1,
       1,     2,     1,     1,     2,     2,     0,     1,     0,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     0,
       4,     0,     4,     2,     0,     1,     3,     1,     2,     2,
       0,     1,     3,     0,     1,     3,     2,     0,     6,     1,
       2,     0,     2,     0,     4,     1,     1,     1,     2,     0,
       4,     1,     1,     2,     0,     1,     1,     1,     0,     1,
       3,     0,     2,     0,     5,     0,     0,     5,     3,     0,
       2,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       0,     0,     4,     0,     0,     4,     0,     0,     0,     6,
       0,     0,     5,     0,     0,     4,     0,     3,     0,     2,
       2,     1,     1,     1,     2,     1,     0,     5,     2,     0,
       2,     0,     5,     0,     4,     0,     1,     2,     2,     0,
       1,     0,     3,     0,     3,     3,     2,     0,     1,     2,
       0,     2,     1,     0,     1,     2,     2,     0,     2,     1,
       1,     1,     1,     1,     0,     4,     4,     1,     1,     1,
       1,     1,     0,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     0,     2,     2,     2,     0,     2,     1,
       2,     2,     2,     2,     2,     2,     2,     0,     1,     1,
       2,     2,     2,     1,     1,     0,     2,     2,     2,     2,
       0,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     4,     6,     4,     4,     6,
       4,     4,     4,     4,     1,     7,     0,     1,     5,     6,
       6,     6,     6,     6,     5,     0,     1,     1,     1,     0,
       1,     2,     0,     1,     2,     2,     1,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
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
  "IT_isBLANK", "IT_isLITERAL", "IT_REGEX", "GT_DTYPE", "IT_AS",
  "GT_RPAREN_SPACECHAR", "IT_GROUP", "IT_HAVING", "IT_COUNT", "IT_SUM",
  "IT_MIN", "IT_MAX", "IT_AVG", "IT_GROUP_CONCAT", "IT_SAMPLE", "IT_true",
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
  "_Q_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C_E_Opt", "_O_QIT_AS_E_S_QVar_E_C",
  "_Q_O_QIT_AS_E_S_QVar_E_C_E_Opt",
  "_O_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_SPACECHAR_E_C",
  "_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_SPACECHAR_E_C",
  "_Q_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_SPACECHAR_E_C_E_Plus",
  "_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_SPACECHAR_E_Plus_Or_QGT_TIMES_E_C",
  "ConstructQuery", "DescribeQuery", "_QVarOrIRIref_E_Plus",
  "_O_QVarOrIRIref_E_Plus_Or_QGT_TIMES_E_C", "_QWhereClause_E_Opt",
  "AskQuery", "DatasetClause",
  "_O_QDefaultGraphClause_E_Or_QNamedGraphClause_E_C",
  "DefaultGraphClause", "NamedGraphClause", "SourceSelector",
  "WhereClause", "_QIT_WHERE_E_Opt", "_QBindingClause_E_Opt",
  "SolutionModifier", "_QGroupClause_E_Opt", "_QHavingClause_E_Opt",
  "_QOrderClause_E_Opt", "_QLimitOffsetClauses_E_Opt", "GroupClause",
  "_QGroupCondition_E_Plus", "GroupCondition", "HavingClause",
  "_QHavingCondition_E_Plus", "HavingCondition", "OrderClause",
  "_QOrderCondition_E_Plus", "OrderCondition",
  "_O_QIT_ASC_E_Or_QIT_DESC_E_C",
  "_O_QIT_ASC_E_Or_QIT_DESC_E_S_QBrackettedExpression_E_C",
  "_O_QConstraint_E_Or_QVar_E_C", "LimitOffsetClauses",
  "_QOffsetClause_E_Opt", "_QLimitClause_E_Opt", "LimitClause",
  "OffsetClause", "Update", "Modify", "Insert", "@3", "Delete", "@4",
  "Clear", "_QGraphRef_E_Opt", "Load", "_QIRIref_E_Plus",
  "_O_QIT_INTO_E_S_QGraphRef_E_C", "_Q_O_QIT_INTO_E_S_QGraphRef_E_C_E_Opt",
  "Drop", "_QIT_SILENT_E_Opt", "Create", "GraphRef", "BindingClause",
  "$@5", "_QVar_E_Plus", "_QBinding_E_Star", "Binding", "$@6",
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
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ParamList", "$@24",
  "ConstructTemplate", "$@25", "_QConstructTriples_E_Opt",
  "ConstructTriples", "_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C_E_Opt", "TriplesSameSubject",
  "$@26", "$@27", "PropertyListNotEmpty", "_O_QVerb_E_S_QObjectList_E_C",
  "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "Verb", "TriplesNode", "BlankNodePropertyList", "@28",
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
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Opt", "Aggregate",
  "_QIT_DISTINCT_E_Opt", "_O_QGT_TIMES_E_Or_QExpression_E_C",
  "_QParamList_E_Opt", "IRIrefOrFunction", "_QArgList_E_Opt", "RDFLiteral",
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
  const SPARQLfedParser::rhs_number_type
  SPARQLfedParser::yyrhs_[] =
  {
       114,     0,    -1,   117,   115,    -1,   124,    -1,   136,    -1,
     137,    -1,   141,    -1,   116,    -1,   172,    -1,     3,   147,
       4,   205,    -1,   118,   119,    -1,    -1,   120,    -1,    -1,
     119,   121,    -1,    15,   104,    -1,    -1,    -1,    16,   122,
     105,   123,   104,    -1,   127,   125,   147,   150,    -1,    -1,
     125,   142,    -1,   127,   147,   150,    -1,    17,   129,   135,
      -1,    18,    -1,    19,    -1,    -1,   128,    -1,    78,   275,
      -1,    -1,   130,    -1,    41,   277,   131,    42,    -1,   275,
      -1,   301,    -1,   298,    -1,   237,    -1,   307,    -1,   311,
      -1,   315,    -1,   132,    -1,   133,    -1,   134,   133,    -1,
     134,    -1,    20,    -1,    21,   244,   125,   147,   150,    -1,
      22,   139,   125,   140,   150,    -1,   274,    -1,   138,   274,
      -1,   138,    -1,    20,    -1,    -1,   147,    -1,    39,   125,
     147,    -1,    23,   143,    -1,   144,    -1,   145,    -1,   146,
      -1,    24,   146,    -1,   317,    -1,   148,   196,   149,    -1,
      -1,    40,    -1,    -1,   188,    -1,   151,   152,   153,   154,
      -1,    -1,   155,    -1,    -1,   158,    -1,    -1,   161,    -1,
      -1,   167,    -1,    80,    26,   156,    -1,   157,    -1,   156,
     157,    -1,   298,    -1,   237,    -1,    41,   277,   131,    42,
      -1,   275,    -1,    81,   159,    -1,   160,    -1,   159,   160,
      -1,   236,    -1,    25,    26,   162,    -1,   163,    -1,   162,
     163,    -1,   165,    -1,   166,    -1,    27,    -1,    28,    -1,
     164,   297,    -1,   236,    -1,   275,    -1,   170,   168,    -1,
     171,   169,    -1,    -1,   171,    -1,    -1,   170,    -1,    29,
      91,    -1,    30,    91,    -1,   173,    -1,   180,    -1,   178,
      -1,   184,    -1,   186,    -1,   174,    -1,   176,    -1,    -1,
       6,   205,   175,   140,    -1,    -1,     5,   205,   177,   140,
      -1,    11,   179,    -1,    -1,   187,    -1,     9,   181,   183,
      -1,   317,    -1,   181,   317,    -1,    10,   187,    -1,    -1,
     182,    -1,    14,   185,   317,    -1,    -1,    13,    -1,    12,
     185,   317,    -1,     7,   317,    -1,    -1,    31,   190,    37,
     189,   191,    38,    -1,   275,    -1,   190,   275,    -1,    -1,
     191,   192,    -1,    -1,    41,   193,   195,    42,    -1,   273,
      -1,    43,    -1,   194,    -1,   195,   194,    -1,    -1,    37,
     197,   198,    38,    -1,   126,    -1,   199,    -1,   200,   204,
      -1,    -1,   212,    -1,   215,    -1,   235,    -1,    -1,    44,
      -1,   201,   202,   200,    -1,    -1,   204,   203,    -1,    -1,
      37,   206,   200,   211,    38,    -1,    -1,    -1,   208,     7,
     274,   209,   205,    -1,   207,   202,   200,    -1,    -1,   211,
     210,    -1,   250,   214,    -1,    44,   200,    -1,    -1,   213,
      -1,   216,    -1,   219,    -1,   229,    -1,   222,    -1,   226,
      -1,    -1,    -1,    45,   217,   218,   196,    -1,    -1,    -1,
      46,   220,   221,   196,    -1,    -1,    -1,    -1,     7,   223,
     224,   274,   225,   196,    -1,    -1,    -1,     8,   227,   228,
     274,   196,    -1,    -1,    -1,   230,   231,   196,   234,    -1,
      -1,    47,   233,   196,    -1,    -1,   234,   232,    -1,    48,
     236,    -1,   297,    -1,   298,    -1,   237,    -1,   317,   238,
      -1,   112,    -1,    -1,    41,   277,   239,   241,    42,    -1,
      49,   277,    -1,    -1,   241,   240,    -1,    -1,    52,   277,
     243,   241,    53,    -1,    -1,    37,   245,   246,    38,    -1,
      -1,   247,    -1,   250,   249,    -1,    44,   246,    -1,    -1,
     248,    -1,    -1,   273,   251,   253,    -1,    -1,   265,   252,
     258,    -1,   264,   260,   257,    -1,   264,   260,    -1,    -1,
     254,    -1,    50,   255,    -1,    -1,   257,   256,    -1,   259,
      -1,    -1,   253,    -1,   263,   262,    -1,    49,   263,    -1,
      -1,   262,   261,    -1,   272,    -1,   274,    -1,    51,    -1,
     268,    -1,   266,    -1,    -1,    52,   267,   253,    53,    -1,
     270,    41,   271,    42,    -1,    32,    -1,    33,    -1,    34,
      -1,    35,    -1,    36,    -1,    -1,   269,    -1,   272,    -1,
     271,   272,    -1,   273,    -1,   265,    -1,   275,    -1,   276,
      -1,   275,    -1,   317,    -1,   109,    -1,   110,    -1,   317,
      -1,   307,    -1,   311,    -1,   315,    -1,   319,    -1,   112,
      -1,   278,    -1,   281,   280,    -1,    54,   281,    -1,    -1,
     280,   279,    -1,   284,   283,    -1,    55,   284,    -1,    -1,
     283,   282,    -1,   285,    -1,   288,   287,    -1,    56,   288,
      -1,    57,   288,    -1,    58,   288,    -1,    59,   288,    -1,
      60,   288,    -1,    61,   288,    -1,    -1,   286,    -1,   289,
      -1,   292,   291,    -1,    62,   292,    -1,    63,   292,    -1,
     313,    -1,   314,    -1,    -1,   291,   290,    -1,   295,   294,
      -1,    20,   295,    -1,    64,   295,    -1,    -1,   294,   293,
      -1,    65,   296,    -1,    62,   296,    -1,    63,   296,    -1,
     296,    -1,   297,    -1,   298,    -1,   305,    -1,   307,    -1,
     311,    -1,   315,    -1,   275,    -1,    41,   277,    42,    -1,
      66,    41,   277,    42,    -1,    67,    41,   277,    42,    -1,
      68,    41,   277,    49,   277,    42,    -1,    69,    41,   277,
      42,    -1,    70,    41,   275,    42,    -1,    71,    41,   277,
      49,   277,    42,    -1,    72,    41,   277,    42,    -1,    73,
      41,   277,    42,    -1,    74,    41,   277,    42,    -1,    75,
      41,   277,    42,    -1,   299,    -1,    76,    41,   277,    49,
     277,   300,    42,    -1,    -1,   240,    -1,    82,    41,   302,
     303,    42,    -1,    83,    41,   302,   277,    42,    42,    -1,
      84,    41,   302,   277,    42,    42,    -1,    85,    41,   302,
     277,    42,    42,    -1,    86,    41,   302,   277,    42,    42,
      -1,    87,   304,    41,   302,   238,    42,    -1,    88,    41,
     302,   277,    42,    -1,    -1,    18,    -1,    20,    -1,   277,
      -1,    -1,   242,    -1,   317,   306,    -1,    -1,   238,    -1,
     316,   310,    -1,    77,   317,    -1,   111,    -1,   308,    -1,
      -1,   309,    -1,   312,    -1,   313,    -1,   314,    -1,    91,
      -1,    92,    -1,    93,    -1,    94,    -1,    95,    -1,    96,
      -1,    97,    -1,    98,    -1,    99,    -1,    89,    -1,    90,
      -1,   100,    -1,   102,    -1,   101,    -1,   103,    -1,   104,
      -1,   318,    -1,   106,    -1,   105,    -1,   107,    -1,   108,
      -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SPARQLfedParser::yyprhs_[] =
  {
         0,     0,     3,     6,     8,    10,    12,    14,    16,    18,
      23,    26,    27,    29,    30,    33,    36,    37,    38,    44,
      49,    50,    53,    57,    61,    63,    65,    66,    68,    71,
      72,    74,    79,    81,    83,    85,    87,    89,    91,    93,
      95,    97,   100,   102,   104,   110,   116,   118,   121,   123,
     125,   126,   128,   132,   135,   137,   139,   141,   144,   146,
     150,   151,   153,   154,   156,   161,   162,   164,   165,   167,
     168,   170,   171,   173,   177,   179,   182,   184,   186,   191,
     193,   196,   198,   201,   203,   207,   209,   212,   214,   216,
     218,   220,   223,   225,   227,   230,   233,   234,   236,   237,
     239,   242,   245,   247,   249,   251,   253,   255,   257,   259,
     260,   265,   266,   271,   274,   275,   277,   281,   283,   286,
     289,   290,   292,   296,   297,   299,   303,   306,   307,   314,
     316,   319,   320,   323,   324,   329,   331,   333,   335,   338,
     339,   344,   346,   348,   351,   352,   354,   356,   358,   359,
     361,   365,   366,   369,   370,   376,   377,   378,   384,   388,
     389,   392,   395,   398,   399,   401,   403,   405,   407,   409,
     411,   412,   413,   418,   419,   420,   425,   426,   427,   428,
     435,   436,   437,   443,   444,   445,   450,   451,   455,   456,
     459,   462,   464,   466,   468,   471,   473,   474,   480,   483,
     484,   487,   488,   494,   495,   500,   501,   503,   506,   509,
     510,   512,   513,   517,   518,   522,   526,   529,   530,   532,
     535,   536,   539,   541,   542,   544,   547,   550,   551,   554,
     556,   558,   560,   562,   564,   565,   570,   575,   577,   579,
     581,   583,   585,   586,   588,   590,   593,   595,   597,   599,
     601,   603,   605,   607,   609,   611,   613,   615,   617,   619,
     621,   623,   626,   629,   630,   633,   636,   639,   640,   643,
     645,   648,   651,   654,   657,   660,   663,   666,   667,   669,
     671,   674,   677,   680,   682,   684,   685,   688,   691,   694,
     697,   698,   701,   704,   707,   710,   712,   714,   716,   718,
     720,   722,   724,   726,   730,   735,   740,   747,   752,   757,
     764,   769,   774,   779,   784,   786,   794,   795,   797,   803,
     810,   817,   824,   831,   838,   844,   845,   847,   849,   851,
     852,   854,   857,   858,   860,   863,   866,   868,   870,   871,
     873,   875,   877,   879,   881,   883,   885,   887,   889,   891,
     893,   895,   897,   899,   901,   903,   905,   907,   909,   911,
     913,   915,   917,   919
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   375,   375,   382,   383,   384,   385,   386,   387,   391,
     399,   403,   405,   409,   411,   415,   421,   423,   421,   433,
     440,   443,   454,   461,   469,   472,   479,   482,   487,   494,
     497,   502,   509,   512,   513,   514,   515,   518,   521,   525,
     530,   533,   540,   543,   550,   558,   565,   569,   577,   580,
     587,   590,   595,   602,   609,   610,   614,   620,   626,   633,
     640,   642,   646,   649,   654,   661,   664,   669,   672,   677,
     680,   685,   689,   693,   700,   703,   710,   711,   712,   715,
     721,   727,   730,   737,   742,   749,   753,   761,   763,   771,
     774,   782,   790,   791,   798,   802,   810,   813,   818,   821,
     825,   831,   837,   838,   839,   840,   841,   845,   846,   850,
     850,   859,   859,   868,   874,   877,   881,   888,   891,   899,
     906,   909,   913,   919,   922,   928,   934,   941,   941,   951,
     955,   963,   966,   974,   974,   984,   985,   992,   996,  1004,
    1004,  1016,  1017,  1022,  1026,  1028,  1033,  1034,  1038,  1040,
    1045,  1049,  1052,  1057,  1057,  1067,  1070,  1067,  1081,  1085,
    1087,  1092,  1097,  1101,  1104,  1108,  1109,  1110,  1111,  1112,
    1116,  1118,  1116,  1132,  1134,  1132,  1143,  1145,  1147,  1143,
    1158,  1160,  1158,  1170,  1173,  1170,  1183,  1183,  1197,  1199,
    1203,  1214,  1215,  1216,  1220,  1227,  1231,  1231,  1241,  1247,
    1249,  1256,  1256,  1266,  1266,  1274,  1276,  1281,  1286,  1290,
    1292,  1296,  1296,  1299,  1299,  1306,  1311,  1315,  1317,  1322,
    1326,  1328,  1333,  1337,  1339,  1344,  1349,  1353,  1355,  1359,
    1366,  1370,  1377,  1378,  1382,  1382,  1395,  1420,  1423,  1426,
    1429,  1432,  1439,  1442,  1447,  1452,  1459,  1460,  1464,  1467,
    1471,  1474,  1480,  1481,  1485,  1488,  1491,  1494,  1497,  1498,
    1504,  1509,  1518,  1525,  1528,  1536,  1545,  1552,  1555,  1562,
    1567,  1578,  1581,  1584,  1587,  1590,  1593,  1600,  1604,  1608,
    1613,  1622,  1625,  1628,  1631,  1638,  1641,  1649,  1658,  1661,
    1668,  1671,  1678,  1681,  1684,  1687,  1691,  1692,  1693,  1694,
    1697,  1700,  1703,  1709,  1715,  1718,  1721,  1724,  1727,  1730,
    1733,  1736,  1739,  1742,  1745,  1750,  1757,  1760,  1764,  1767,
    1770,  1773,  1776,  1779,  1783,  1789,  1792,  1798,  1801,  1805,
    1808,  1812,  1822,  1825,  1830,  1838,  1845,  1849,  1857,  1861,
    1865,  1866,  1867,  1871,  1872,  1873,  1877,  1878,  1879,  1883,
    1884,  1885,  1889,  1890,  1894,  1895,  1896,  1897,  1901,  1902,
    1906,  1907,  1911,  1912
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
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SPARQLfedParser::yyeof_ = 0;
  const int SPARQLfedParser::yylast_ = 1142;
  const int SPARQLfedParser::yynnts_ = 207;
  const int SPARQLfedParser::yyempty_ = -2;
  const int SPARQLfedParser::yyfinal_ = 7;
  const int SPARQLfedParser::yyterror_ = 1;
  const int SPARQLfedParser::yyerrcode_ = 256;
  const int SPARQLfedParser::yyntokens_ = 113;

  const unsigned int SPARQLfedParser::yyuser_token_number_max_ = 367;
  const SPARQLfedParser::token_number_type SPARQLfedParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 3727 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 1918 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


