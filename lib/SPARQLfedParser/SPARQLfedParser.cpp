
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
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 456 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 458 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(5) - (1)].p_Project).distinctness, (yysemantic_stack_[(5) - (1)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier))));
      }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 466 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 474 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 477 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 484 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 492 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 499 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 507 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    { // _SPACECHAR ?
	(yyval.p_Expression) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new AliasedExpression((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : (yysemantic_stack_[(4) - (2)].p_Expression);
    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 514 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 520 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 523 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 526 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 535 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExprList) = new ExprList((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 538 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExprList)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    (yyval.p_ExprList) = (yysemantic_stack_[(2) - (1)].p_ExprList);
}
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 545 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExprList); // Grammar action needed for implicit upcast.
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 548 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 555 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	(yyval.p_Operation) = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(5) - (2)].p_BasicGraphPattern), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 563 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 570 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExprList) = new ExprList();
	(yyval.p_ExprList)->push_back(new POSExpression((yysemantic_stack_[(1) - (1)].p_POS)));
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 574 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
      (yysemantic_stack_[(2) - (1)].p_ExprList)->push_back(new POSExpression((yysemantic_stack_[(2) - (2)].p_POS)));
	(yyval.p_ExprList) = (yysemantic_stack_[(2) - (1)].p_ExprList);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 582 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExprList);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 585 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 592 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 600 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(3) - (2)].p_DatasetClauses), (yysemantic_stack_[(3) - (3)].p_WhereClause));
    }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 607 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 619 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_POS), driver.posFactory);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 625 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_POS), driver.posFactory);
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 631 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 638 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp, (yysemantic_stack_[(3) - (3)].p_BindingClause));
	driver.curOp = NULL;
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 651 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 659 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 666 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 674 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 682 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 690 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 698 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(3) - (3)].p_Expressions);
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 705 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 708 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 717 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new AliasedExpression((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : (yysemantic_stack_[(4) - (2)].p_Expression);
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 720 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 726 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 732 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 735 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 747 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 754 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 758 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 768 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 776 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 779 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 787 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 796 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 803 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 807 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 815 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 823 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 830 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 836 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 855 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 858 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert((yysemantic_stack_[(4) - (3)].p_TableOperation), (yysemantic_stack_[(4) - (4)].p_WhereClause));
      }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 864 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 867 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(4) - (3)].p_TableOperation), (yysemantic_stack_[(4) - (4)].p_WhereClause));
      }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 873 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(2) - (2)].p_URI));
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 879 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 886 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(3) - (2)].p_URIs), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 893 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URIs) = new ProductionVector<const URI*>((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 896 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_URIs)->push_back((yysemantic_stack_[(2) - (2)].p_URI));
	(yyval.p_URIs) = (yysemantic_stack_[(2) - (1)].p_URIs);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 904 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 911 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 918 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 924 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 927 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 933 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 939 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 946 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_POSList));
      }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 948 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = driver.curBindingClause;
	  driver.curBindingClause = NULL;
      }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 956 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSList) = new POSList;
	(yyval.p_POSList)->push_back((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 960 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_POSList) = (yysemantic_stack_[(2) - (1)].p_POSList);
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 968 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Bindings) = NULL;
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 971 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingClause->push_back((yysemantic_stack_[(2) - (2)].p_Binding));
	(yyval.p_Bindings) = NULL;
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 979 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding = new Binding();
      }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 981 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Binding) = driver.curBinding;
	  driver.curBinding = NULL;
      }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 990 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getNULL();
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 997 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_POS));
	(yyval.p_POSs) = NULL;
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1001 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = NULL;
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1009 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1012 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1062 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1065 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
      }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1072 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curFilter = NULL;
      }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1075 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_POS);
      }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1078 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(5) - (3)].p_POS), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(5) - (4)].p_POS);
      }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 1121 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 1123 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.curFilter;
      }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1125 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 175:

/* Line 678 of lalr1.cc  */
#line 1137 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 1139 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 1141 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.curOp));
      }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 1148 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 1150 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 1152 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_POS);
      }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 1155 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_POS), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_POS);
      }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 1163 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 1165 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 1167 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(5) - (4)].p_POS), driver.curOp, driver.posFactory, false));
      }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 1175 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 1178 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 1180 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 1188 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 1193 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 1208 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    if (driver.curOp == NULL)
		driver.ensureBasicGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1225 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1232 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1236 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 1238 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList);
	  driver.curExprList = NULL;
      }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 1246 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 1254 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 1261 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 1263 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 1271 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 1273 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 1301 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 1304 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 1364 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.posFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_POS)));
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 1371 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_POS);
	driver.curPredicate = (yyval.p_POS);
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 1375 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_POS);
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 1387 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 1391 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 1400 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 239:

/* Line 678 of lalr1.cc  */
#line 1425 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 1428 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 1431 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 1434 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 1437 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 1444 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 1452 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSs) = new ProductionVector<const POS*>();
	(yyval.p_POSs)->push_back((yysemantic_stack_[(1) - (1)].p_POS));
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 1457 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSs)->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = (yysemantic_stack_[(2) - (1)].p_POSs);
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 1469 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 1476 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 1479 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 1490 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 1493 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 1496 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 1499 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 1503 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 1514 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 1523 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 1530 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 1533 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 1541 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 1550 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 1557 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 1560 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 1572 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_BooleanComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_BooleanComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_BooleanComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 1583 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 1586 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 1589 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 1592 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 1595 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yyval.p_BooleanComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 1598 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 1605 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = NULL;
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 1618 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 1627 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 1630 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 1633 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 1636 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 1643 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 1646 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 1654 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 1663 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 1666 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 1673 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 1676 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 1683 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 1686 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 1689 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 1699 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 1702 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 1705 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 1708 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 1714 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 1720 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-str"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 1723 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-lang"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 1726 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-langMatches"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 1729 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-datatype"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 1732 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-bound"), new POSExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 1735 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sameTerm"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 1738 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 1741 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 1744 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isBlank"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 1747 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isLiteral"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 1755 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-regex"), (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 1762 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 1769 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-count"), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 1772 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sum"), (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression)));
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 1775 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-min"), (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression)));
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 1778 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-max"), (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression)));
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 1781 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-avg"), (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression)));
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 1784 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	throw NotImplemented("CONCAT");
	// $$ = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-group-concat"), $4, $2));
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 1788 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sample"), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 1794 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 1797 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 1803 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 1810 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 1817 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new POSExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 1827 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 1835 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 1843 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 1850 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 1854 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 1862 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 2543 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -373;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        43,   -54,    61,   607,  -373,  -373,  -373,  -373,    37,    42,
      42,    49,    83,    79,    79,    35,    70,    17,  -373,  -373,
    -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,
    -373,  -373,  -373,  -373,    88,  -373,   107,    78,  -373,  -373,
    -373,  -373,  -373,  -373,     8,  -373,  -373,    49,  -373,  -373,
    -373,    49,    49,  -373,  -373,  -373,   581,  -373,  -373,  -373,
    -373,  -373,    57,  -373,  -373,  -373,  -373,    20,    20,  -373,
    -373,    42,  -373,    86,   747,     2,     2,    83,  -373,  -373,
    -373,  -373,  -373,  -373,  -373,  1012,    89,    91,    92,    95,
     108,   118,   123,   128,   135,   136,   142,   143,   144,   146,
     148,   160,    72,   161,  -373,  -373,  -373,  -373,  -373,  -373,
    -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,
    -373,   946,  -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,
    -373,  -373,  -373,  -373,   -52,   -17,   747,    20,  -373,     9,
      33,  -373,  -373,   132,   111,  -373,   490,   -27,  -373,  -373,
    -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,
    -373,   169,  -373,  -373,  -373,  -373,   178,  -373,  -373,  -373,
    -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,  1012,
    1057,  1057,  1057,  -373,   145,  -373,  -373,  -373,  -373,   194,
    -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,
     -17,  1012,  1012,  1012,  1012,   -27,  1012,  1012,  1012,  1012,
    1012,  1012,   203,   203,   203,   203,   203,  1012,  -373,   181,
     203,  -373,    49,  -373,  -373,  -373,  -373,  1012,  -373,  -373,
     187,  -373,   182,   132,   132,    49,  -373,  -373,  -373,  -373,
    -373,   205,  -373,   151,  -373,  -373,  -373,  -373,   197,  -373,
    -373,   -23,  -373,    38,   198,   747,  -373,  -373,    38,   852,
      38,   196,  -373,  -373,  -373,   -27,  -373,   201,   185,   190,
    1012,  1012,  1012,  1012,  1012,  1012,  -373,  -373,   109,     3,
    -373,  -373,   204,   214,   191,   217,   220,   215,   224,   225,
     232,   234,   231,  -373,   668,  1012,  1012,  1012,  1012,  -373,
     203,  1012,  -373,  -373,  -373,   747,  -373,  -373,  -373,  -373,
    -373,   312,   499,   257,  -373,   180,  -373,  -373,   172,  -373,
    -373,  -373,   233,   852,  -373,  -373,   241,   281,  -373,  -373,
    -373,  -373,  -373,  -373,   771,  -373,  -373,  -373,  -373,  -373,
    -373,  1012,  -373,  1012,  -373,  -373,  -373,  -373,  -373,  -373,
    -373,  1012,  1012,  -373,  -373,  -373,  1012,  1012,  -373,  -373,
    -373,  1012,  -373,  -373,  1012,  -373,  -373,  -373,  -373,  1012,
    -373,  -373,   249,   250,   253,   254,   255,  -373,   -17,   261,
    -373,  -373,  1012,   312,  -373,  -373,  -373,  -373,   499,  -373,
    -373,  -373,  -373,  -373,   272,    67,  -373,  -373,    37,  -373,
    -373,  -373,  -373,   499,   241,  -373,  -373,  -373,  -373,  -373,
    -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,
     747,    57,  -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,
     262,   271,   265,  -373,   275,   276,   278,   280,    -5,   282,
    -373,   -14,   145,  -373,  -373,   124,   208,   235,  -373,  -373,
     295,   298,   132,  -373,  -373,  -373,  -373,  -373,   747,    78,
      14,   284,   279,  -373,  -373,  -373,  -373,  1012,  -373,   289,
    -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,   290,  -373,
    -373,   124,  -373,   294,  -373,  -373,  -373,  -373,  -373,  -373,
    -373,  -373,  -373,  -373,  -373,    57,    57,    78,    78,  -373,
    -373,  -373,  -373,  -373,    38,  -373,   852,  -373,    42,  -373,
    -373,  -373,  -373,  -373,  -373,    78,  -373,  -373,   291,  1091,
    -373,  -373,   852,  -373,  -373,    78,  -373,  -373,  -373,  -373,
    -373,   876,  -373,  -373,  -373,    78,  -373,  -373,  -373
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        11,     0,     0,     0,    13,    12,    15,     1,    62,     0,
       0,     0,   116,   125,   125,    28,     0,     0,    20,     2,
       7,     3,    20,     4,     5,     6,     8,   104,   109,   110,
     106,   105,   107,   108,    10,    63,     0,     0,   155,   113,
     111,   360,   363,   362,   122,   119,   361,     0,   115,   117,
     126,     0,     0,    26,    27,    29,     0,   205,    20,    51,
     254,   255,    50,    20,    48,   252,   253,    62,    62,    16,
      14,     0,   141,    64,   146,    52,    52,     0,   123,   118,
     120,   128,   127,   124,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   331,     0,   354,   355,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   356,   358,   357,   359,    41,
      42,    44,    25,    37,    34,    36,   316,    35,    38,    39,
     342,   343,   344,    40,   340,     0,   207,    62,    49,    52,
       0,    21,    54,    67,     0,     9,   146,     0,    61,    65,
     239,   240,   241,   242,   243,   236,   364,   365,   261,   161,
     147,   165,   215,   235,   234,   245,     0,   213,   250,   251,
     257,   258,   259,   256,   260,   114,    53,   112,   121,     0,
       0,     0,     0,   304,    31,   262,   265,   269,   271,   279,
     281,   287,   292,   297,   298,   299,   300,   301,   302,   303,
     334,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   327,   327,   327,   327,   327,     0,   332,     0,
     327,    43,     0,   338,   339,   341,   336,     0,   197,   196,
       0,   208,   211,    67,    67,     0,    55,    56,    57,    58,
      60,     0,    19,    69,    68,    17,   143,    22,     0,   144,
     153,     0,   131,     0,   157,   146,   166,   163,   225,   244,
       0,     0,   295,   296,   294,     0,    32,     0,   263,   267,
       0,     0,     0,     0,     0,     0,   280,   272,   282,   289,
     335,   333,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   328,     0,     0,     0,     0,     0,   203,
     327,     0,   337,   198,   206,   207,   212,   209,    46,    47,
      59,     0,     0,    71,    70,     0,    23,   142,   145,   129,
     132,   233,     0,   244,   232,   156,   150,     0,   162,   164,
     226,   216,   224,   249,   244,   246,   248,   214,   305,    30,
      33,     0,   266,     0,   270,   273,   274,   275,   276,   277,
     278,     0,     0,   288,   285,   286,     0,     0,   293,   306,
     307,     0,   309,   310,     0,   312,   313,   314,   315,     0,
     329,   330,     0,     0,     0,     0,     0,   201,     0,     0,
     201,   210,     0,    75,    76,    79,    81,    78,    82,    83,
      85,   195,   193,   194,     0,    73,    72,    18,    62,   178,
     182,   172,   175,     0,   150,   154,   148,   167,   168,   170,
     171,   169,   186,   149,   133,   237,   222,   229,   231,   151,
     146,     0,   238,   247,   264,   268,   283,   284,   290,   291,
       0,     0,   318,   320,     0,     0,     0,     0,     0,     0,
     326,     0,    31,    77,    84,     0,     0,     0,    66,    74,
      98,   100,    67,   179,   183,   173,   176,   192,   146,     0,
       0,   217,   227,   160,   158,   308,   311,     0,   319,     0,
     321,   322,   323,   324,   204,   202,   325,   199,     0,    91,
      92,    86,    87,     0,    89,    90,    94,    95,   102,   103,
      96,    99,    97,   101,    24,     0,     0,     0,     0,   152,
     190,   130,   135,   134,   219,   223,   244,   230,     0,   200,
     317,    80,    88,    93,   180,     0,   174,   177,   187,     0,
     220,   221,   244,   228,   159,     0,   184,   188,   191,   138,
     139,     0,   137,   218,   181,     0,   136,   140,   189
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,
    -373,  -373,    12,  -373,  -373,  -373,   193,  -373,  -373,  -373,
    -106,  -373,   216,  -373,  -373,  -373,  -373,  -373,  -373,   -61,
    -373,  -373,  -373,  -373,  -373,   105,    -3,  -373,  -373,  -225,
    -373,  -373,  -373,  -373,  -373,  -373,   -42,  -373,  -373,   -46,
    -373,  -373,  -136,  -373,  -373,  -373,  -373,  -373,  -373,  -105,
    -101,  -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,
    -373,  -373,  -373,  -373,   336,  -373,   274,  -373,  -373,  -373,
    -373,  -373,  -373,  -179,  -373,  -357,  -373,  -373,  -373,  -139,
    -373,   -50,  -373,  -373,    -9,  -373,  -373,  -373,  -373,  -373,
    -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,
    -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,
    -373,  -373,  -373,  -373,  -373,  -372,   -53,  -196,  -373,   -77,
     -24,  -373,  -373,  -373,  -373,    52,  -373,  -373,  -373,  -124,
    -373,  -373,  -189,  -373,  -373,  -373,  -373,  -373,  -373,  -163,
    -373,  -373,  -146,  -143,  -249,  -373,  -373,  -373,  -373,  -373,
    -373,  -246,  -229,   -15,    10,  -373,   256,  -373,  -373,  -373,
      21,  -373,  -373,    22,  -373,  -373,  -373,    36,  -373,  -373,
    -373,  -252,  -373,  -373,  -237,    -7,  -295,   -40,  -373,  -373,
    -373,  -194,  -373,  -373,  -373,  -373,   -45,  -373,  -373,  -373,
     -18,  -373,    90,    93,    24,  -373,   -11,  -373,  -373
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,    19,    20,     3,     4,    34,     5,    70,   144,
     315,    21,    67,   246,   316,   398,    22,    55,    56,   266,
     267,   119,   120,   121,   122,    23,    24,    62,    63,   175,
      25,   141,   236,   237,   238,   239,   176,    37,   148,   242,
     243,   313,   395,   448,   244,   383,   384,   314,   388,   389,
     396,   481,   482,   483,   484,   485,   449,   490,   492,   450,
     451,    26,    27,    28,    76,    29,    75,    30,    48,    31,
      44,    78,    79,    32,    51,    33,    49,   149,   414,   251,
     460,   503,   519,   530,   531,    73,   146,   248,   249,   159,
     404,   420,   405,   318,    39,    74,   326,   327,   508,   328,
     254,   160,   256,   257,   406,   407,   455,   497,   408,   456,
     498,   409,   453,   495,   525,   410,   454,   496,   411,   412,
     459,   528,   535,   518,   413,   390,   391,   229,   380,   475,
     438,   218,   377,    58,   136,   230,   231,   306,   307,   161,
     260,   258,   322,   520,   521,   505,   461,   331,   332,   416,
     507,   462,   417,   323,   162,   163,   253,   164,   165,   166,
     334,   418,   167,   324,   183,   169,   184,   185,   342,   268,
     186,   344,   269,   187,   188,   276,   277,   189,   190,   353,
     278,   191,   358,   279,   192,   193,   194,   195,   126,   469,
     127,   294,   372,   219,   196,   281,   197,   224,   225,   226,
     198,   130,   131,   132,   199,   134,   200,    46,   174
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SPARQLfedParser::yytable_ninf_ = -245;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        45,    40,    64,   123,   280,    36,    66,   250,   308,   309,
     333,   128,   232,   335,   319,   177,   125,   392,    77,   295,
     296,   297,   298,   356,   227,   222,   301,    65,   477,   170,
     336,   457,   140,    80,    68,   467,    81,    59,   129,   -62,
      82,    83,    35,   140,   467,   135,   -62,   138,   474,    35,
       6,    66,   501,    53,    54,   502,   171,   235,     1,   223,
      35,     7,   145,   173,   142,   143,   124,   357,   123,   330,
     137,   337,    65,   486,   333,   139,   128,    35,   234,    38,
     133,   125,    60,    61,   168,   333,    60,    61,   423,   321,
      47,   170,    50,   392,   336,   228,   446,   447,   172,   426,
     427,   170,   500,   129,    69,   336,   378,    57,   392,   486,
     135,    71,    41,    42,    43,    72,   329,   147,   171,   428,
     429,    41,    42,    43,   217,   173,    60,    61,   171,   240,
     201,   124,   202,   203,   233,   173,   204,    41,    42,    43,
     516,   517,    41,    42,    43,   133,   168,    60,    61,   205,
     392,   479,   480,    41,    42,    43,   168,   252,   526,   206,
     172,    41,    42,    43,   207,   179,    60,    61,   534,   208,
     172,   351,   352,   262,   263,   264,   209,   210,   538,   399,
     400,   232,   439,   211,   212,   213,   392,   214,   513,   215,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,   216,   220,   109,   110,   111,   112,   113,   114,  -185,
     170,   302,   241,   255,   170,   286,   245,   401,   402,   259,
     403,   293,   300,   265,   240,   304,   305,   494,    41,    42,
      43,   311,   312,    60,    61,   317,   325,   171,   338,   341,
     361,   171,    66,   340,   173,   343,   359,    66,   173,    66,
     270,   271,   272,   273,   274,   275,   360,   333,   385,   362,
     170,   320,   363,    65,   364,   168,   365,   366,    65,   168,
      65,   387,   393,   333,   367,   339,   368,   336,   170,   172,
     369,   463,   394,   172,   397,   419,   415,   171,   421,   170,
     532,   433,   434,   336,   173,   435,   436,   437,   445,   488,
     135,   135,   532,   440,   465,   171,   345,   346,   347,   348,
     349,   350,   173,   466,   467,   168,   171,   470,   471,   499,
     472,   386,   473,   173,   476,   447,   489,   446,   506,   172,
     385,   510,   511,   168,   504,   179,   478,   221,   527,   247,
     310,   443,   444,   387,   168,   512,   493,   172,   393,   491,
      52,   178,   537,   382,   458,   468,   441,   381,   172,   533,
     523,   522,   424,   393,     0,   425,     0,     0,   354,     0,
       0,   355,   135,     0,     0,   170,     0,   135,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,     0,
       0,     0,   135,   386,     0,   452,     0,     0,     0,     0,
       0,     0,   171,     0,     0,   393,   464,     0,     0,   173,
      66,     0,     0,   170,     0,     0,    41,    42,    43,     0,
       0,    60,    61,     0,     0,     0,     0,     0,     0,     0,
     168,    65,     0,     0,   135,   261,     0,     0,     0,     0,
     171,   393,     0,     0,   172,     0,     0,   173,     0,     0,
       0,     0,     0,     0,     0,   487,     0,   282,   283,   284,
     285,   170,   287,   288,   289,   290,   291,   292,   168,     0,
     135,     0,     0,   299,   170,     0,     0,   170,     0,     0,
     514,   515,   172,   303,    66,    66,   170,     0,   171,     0,
       0,   487,     0,    66,     0,   173,     0,     0,     0,   524,
       0,   171,     0,     0,   171,    65,    65,    15,   173,     0,
       0,   173,     0,   171,    65,     0,   168,     0,     0,     0,
     173,     0,   150,   151,   152,   153,   154,     0,     0,   168,
     172,  -244,   168,     0,     0,     0,     0,     0,     0,     0,
     179,   168,   155,   172,     0,     0,   172,     0,     0,     0,
     371,   373,   374,   375,   376,   172,     0,   379,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    41,    42,    43,   156,   157,    60,
      61,    84,   158,    41,    42,    43,     0,     0,     0,     0,
       8,     0,     9,    10,     0,     0,    11,   430,    12,    13,
     431,    14,    85,     0,    15,   432,     0,     0,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,   442,     0,
       0,     0,     0,     0,     0,     0,    18,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,     0,     0,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    41,    42,    43,   370,     0,
      60,    61,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   509,     0,     0,     0,     0,     0,     0,
     180,   181,     0,   182,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    41,    42,    43,     0,     0,    60,    61,   150,
     151,   152,   153,   154,     0,     0,     0,     0,  -244,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   155,
       0,     0,     0,   150,   151,   152,   153,   154,     0,     0,
       0,     0,     0,   422,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   155,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    41,    42,    43,   156,   157,    60,    61,     0,   158,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    41,    42,    43,   156,   157,
      60,    61,     0,   158,   150,   151,   152,   153,   154,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   155,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   536,   529,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    41,    42,    43,   156,
     157,    60,    61,     0,   158,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
      41,    42,    43,   156,   157,    60,    61,    85,   158,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,     0,     0,     0,     0,     0,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
      41,    42,    43,   179,     0,    60,    61,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   180,   181,     0,   182,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   179,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    41,    42,    43,     0,
       0,    60,    61,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,   529,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    41,    42,    43,     0,     0,    60,    61,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    41,    42,    43,   156,   157,
      60,    61,     0,   158
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        11,    10,    17,    56,   200,     8,    17,   146,   233,   234,
     259,    56,   136,   259,    37,    76,    56,   312,    10,   213,
     214,   215,   216,    20,    41,    77,   220,    17,    42,    74,
     259,   403,    23,    44,    22,    49,    47,    20,    56,    37,
      51,    52,    40,    23,    49,    56,    37,    62,    53,    40,
     104,    62,    38,    18,    19,    41,    74,    24,    15,   111,
      40,     0,    71,    74,    67,    68,    56,    64,   121,   258,
      58,   260,    62,   445,   323,    63,   121,    40,   139,    37,
      56,   121,   109,   110,    74,   334,   109,   110,   334,    51,
       7,   136,    13,   388,   323,   112,    29,    30,    74,   351,
     352,   146,   459,   121,    16,   334,   300,    37,   403,   481,
     121,     4,   104,   105,   106,    37,   255,    31,   136,   356,
     357,   104,   105,   106,    52,   136,   109,   110,   146,   140,
      41,   121,    41,    41,   137,   146,    41,   104,   105,   106,
     497,   498,   104,   105,   106,   121,   136,   109,   110,    41,
     445,    27,    28,   104,   105,   106,   146,   147,   515,    41,
     136,   104,   105,   106,    41,    41,   109,   110,   525,    41,
     146,    62,    63,   180,   181,   182,    41,    41,   535,     7,
       8,   305,   378,    41,    41,    41,   481,    41,   483,    41,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    41,    41,    94,    95,    96,    97,    98,    99,    37,
     255,   222,    80,    44,   259,   205,   105,    45,    46,    41,
      48,    18,    41,    78,   235,    38,    44,   452,   104,   105,
     106,    26,    81,   109,   110,    38,    38,   255,    42,    54,
      49,   259,   253,    42,   255,    55,    42,   258,   259,   260,
      56,    57,    58,    59,    60,    61,    42,   506,   311,    42,
     305,   251,    42,   253,    49,   255,    42,    42,   258,   259,
     260,   311,   312,   522,    42,   265,    42,   506,   323,   255,
      49,   420,    25,   259,   104,    44,    53,   305,     7,   334,
     519,    42,    42,   522,   305,    42,    42,    42,    26,    91,
     311,   312,   531,    42,    42,   323,   270,   271,   272,   273,
     274,   275,   323,    42,    49,   305,   334,    42,    42,   458,
      42,   311,    42,   334,    42,    30,    91,    29,    49,   305,
     383,    42,    42,   323,    50,    41,   442,   121,    47,   146,
     235,   383,   388,   383,   334,   481,   451,   323,   388,   450,
      14,    77,   531,    41,   404,   432,   380,   305,   334,   522,
     506,   504,   341,   403,    -1,   343,    -1,    -1,   278,    -1,
      -1,   278,   383,    -1,    -1,   420,    -1,   388,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,   403,   383,    -1,   398,    -1,    -1,    -1,    -1,
      -1,    -1,   420,    -1,    -1,   445,   421,    -1,    -1,   420,
     421,    -1,    -1,   458,    -1,    -1,   104,   105,   106,    -1,
      -1,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     420,   421,    -1,    -1,   445,   179,    -1,    -1,    -1,    -1,
     458,   481,    -1,    -1,   420,    -1,    -1,   458,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   445,    -1,   201,   202,   203,
     204,   506,   206,   207,   208,   209,   210,   211,   458,    -1,
     481,    -1,    -1,   217,   519,    -1,    -1,   522,    -1,    -1,
     495,   496,   458,   227,   495,   496,   531,    -1,   506,    -1,
      -1,   481,    -1,   504,    -1,   506,    -1,    -1,    -1,   508,
      -1,   519,    -1,    -1,   522,   495,   496,    17,   519,    -1,
      -1,   522,    -1,   531,   504,    -1,   506,    -1,    -1,    -1,
     531,    -1,    32,    33,    34,    35,    36,    -1,    -1,   519,
     506,    41,   522,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,   531,    52,   519,    -1,    -1,   522,    -1,    -1,    -1,
     294,   295,   296,   297,   298,   531,    -1,   301,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    20,   112,   104,   105,   106,    -1,    -1,    -1,    -1,
       3,    -1,     5,     6,    -1,    -1,     9,   361,    11,    12,
     364,    14,    41,    -1,    17,   369,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   382,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,    20,    -1,
     109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   467,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    -1,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,    -1,    -1,   109,   110,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    -1,   112,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    -1,   112,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    -1,   112,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    41,   112,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    41,    -1,   109,   110,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    -1,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,    -1,
      -1,   109,   110,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    -1,    -1,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    -1,   112
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    15,   114,   117,   118,   120,   104,     0,     3,     5,
       6,     9,    11,    12,    14,    17,    21,    22,    39,   115,
     116,   124,   129,   138,   139,   143,   174,   175,   176,   178,
     180,   182,   186,   188,   119,    40,   149,   150,    37,   207,
     207,   104,   105,   106,   183,   319,   320,     7,   181,   189,
      13,   187,   187,    18,    19,   130,   131,    37,   246,    20,
     109,   110,   140,   141,   276,   277,   319,   125,   125,    16,
     121,     4,    37,   198,   208,   179,   177,    10,   184,   185,
     319,   319,   319,   319,    20,    41,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   134,
     135,   136,   137,   239,   277,   300,   301,   303,   309,   313,
     314,   315,   316,   317,   318,   319,   247,   125,   276,   125,
      23,   144,   149,   149,   122,   207,   199,    31,   151,   190,
      32,    33,    34,    35,    36,    52,   107,   108,   112,   202,
     214,   252,   267,   268,   270,   271,   272,   275,   277,   278,
     309,   313,   317,   319,   321,   142,   149,   142,   189,    41,
      62,    63,    65,   277,   279,   280,   283,   286,   287,   290,
     291,   294,   297,   298,   299,   300,   307,   309,   313,   317,
     319,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    52,   244,   306,
      41,   135,    77,   111,   310,   311,   312,    41,   112,   240,
     248,   249,   252,   149,   142,    24,   145,   146,   147,   148,
     319,    80,   152,   153,   157,   105,   126,   129,   200,   201,
     202,   192,   277,   269,   213,    44,   215,   216,   254,    41,
     253,   279,   298,   298,   298,    78,   132,   133,   282,   285,
      56,    57,    58,    59,    60,    61,   288,   289,   293,   296,
     240,   308,   279,   279,   279,   279,   277,   279,   279,   279,
     279,   279,   279,    18,   304,   304,   304,   304,   304,   279,
      41,   304,   319,   279,    38,    44,   250,   251,   152,   152,
     148,    26,    81,   154,   160,   123,   127,    38,   206,    37,
     277,    51,   255,   266,   276,    38,   209,   210,   212,   202,
     255,   260,   261,   267,   273,   274,   275,   255,    42,   277,
      42,    54,   281,    55,   284,   290,   290,   290,   290,   290,
     290,    62,    63,   292,   315,   316,    20,    64,   295,    42,
      42,    49,    42,    42,    49,    42,    42,    42,    42,    49,
      20,   279,   305,   279,   279,   279,   279,   245,   304,   279,
     241,   248,    41,   158,   159,   239,   277,   300,   161,   162,
     238,   239,   299,   300,    25,   155,   163,   104,   128,     7,
       8,    45,    46,    48,   203,   205,   217,   218,   221,   224,
     228,   231,   232,   237,   191,    53,   262,   265,   274,    44,
     204,     7,    42,   274,   283,   286,   294,   294,   297,   297,
     279,   279,   279,    42,    42,    42,    42,    42,   243,   240,
      42,   243,   279,   159,   162,    26,    29,    30,   156,   169,
     172,   173,   149,   225,   229,   219,   222,   238,   204,   233,
     193,   259,   264,   202,   276,    42,    42,    49,   242,   302,
      42,    42,    42,    42,    53,   242,    42,    42,   133,    27,
      28,   164,   165,   166,   167,   168,   238,   277,    91,    91,
     170,   173,   171,   172,   152,   226,   230,   220,   223,   202,
     198,    38,    41,   194,    50,   258,    49,   263,   211,   279,
      42,    42,   165,   299,   276,   276,   198,   198,   236,   195,
     256,   257,   266,   265,   207,   227,   198,    47,   234,    43,
     196,   197,   275,   262,   198,   235,    42,   196,   198
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
     125,   125,   127,   128,   126,   129,   130,   130,   131,   131,
     132,   133,   133,   134,   135,   135,   135,   135,   135,   135,
     135,   135,   136,   136,   137,   137,   138,   139,   140,   140,
     141,   141,   142,   142,   143,   144,   145,   145,   146,   147,
     148,   149,   150,   150,   151,   151,   152,   153,   153,   154,
     154,   155,   155,   156,   156,   157,   158,   158,   159,   159,
     159,   159,   160,   161,   161,   162,   163,   164,   164,   165,
     165,   166,   166,   167,   168,   168,   169,   169,   170,   170,
     171,   171,   172,   173,   174,   174,   174,   174,   174,   175,
     175,   177,   176,   179,   178,   180,   181,   181,   182,   183,
     183,   184,   185,   185,   186,   187,   187,   188,   189,   191,
     190,   192,   192,   193,   193,   195,   194,   196,   196,   197,
     197,   199,   198,   200,   200,   201,   202,   202,   203,   203,
     204,   204,   205,   206,   206,   208,   207,   210,   211,   209,
     212,   213,   213,   214,   215,   216,   216,   217,   217,   217,
     217,   217,   219,   220,   218,   222,   223,   221,   225,   226,
     227,   224,   229,   230,   228,   232,   233,   231,   235,   234,
     236,   236,   237,   238,   238,   238,   239,   240,   241,   240,
     242,   243,   243,   245,   244,   247,   246,   248,   248,   249,
     250,   251,   251,   253,   252,   254,   252,   255,   256,   257,
     257,   258,   259,   259,   260,   261,   261,   262,   263,   264,
     264,   265,   266,   266,   267,   267,   269,   268,   270,   271,
     271,   271,   271,   271,   272,   272,   273,   273,   274,   274,
     275,   275,   276,   276,   277,   277,   278,   278,   278,   278,
     278,   278,   279,   280,   281,   282,   282,   283,   284,   285,
     285,   286,   287,   288,   288,   288,   288,   288,   288,   289,
     289,   290,   291,   292,   292,   292,   292,   293,   293,   294,
     295,   295,   296,   296,   297,   297,   297,   297,   298,   298,
     298,   298,   298,   298,   298,   299,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   301,   302,   302,
     303,   303,   303,   303,   303,   303,   303,   304,   304,   305,
     305,   306,   306,   307,   308,   308,   309,   310,   311,   311,
     312,   312,   313,   313,   313,   314,   314,   314,   315,   315,
     315,   316,   316,   316,   317,   317,   318,   318,   318,   318,
     319,   319,   320,   320,   321,   321
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SPARQLfedParser::yyr2_[] =
  {
         0,     2,     2,     1,     1,     1,     1,     1,     1,     4,
       2,     0,     1,     0,     2,     2,     0,     0,     5,     4,
       0,     2,     0,     0,     5,     3,     1,     1,     0,     1,
       2,     0,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     5,     5,     1,     2,
       1,     1,     0,     1,     3,     2,     1,     1,     1,     2,
       1,     3,     0,     1,     0,     1,     4,     0,     1,     0,
       1,     0,     1,     0,     1,     3,     1,     2,     1,     1,
       4,     1,     2,     1,     2,     1,     3,     1,     2,     1,
       1,     1,     1,     2,     1,     1,     2,     2,     0,     1,
       0,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     0,     4,     2,     0,     1,     3,     1,
       2,     2,     0,     1,     3,     0,     1,     3,     2,     0,
       6,     1,     2,     0,     2,     0,     4,     1,     1,     1,
       2,     0,     4,     1,     1,     2,     0,     1,     1,     1,
       0,     1,     3,     0,     2,     0,     5,     0,     0,     5,
       3,     0,     2,     2,     2,     0,     1,     1,     1,     1,
       1,     1,     0,     0,     4,     0,     0,     4,     0,     0,
       0,     6,     0,     0,     5,     0,     0,     4,     0,     3,
       0,     2,     2,     1,     1,     1,     2,     1,     0,     5,
       2,     0,     2,     0,     5,     0,     4,     0,     1,     2,
       2,     0,     1,     0,     3,     0,     3,     3,     2,     0,
       1,     2,     0,     2,     1,     0,     1,     2,     2,     0,
       2,     1,     1,     1,     1,     1,     0,     4,     4,     1,
       1,     1,     1,     1,     0,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     0,     2,     2,     2,     0,
       2,     1,     2,     2,     2,     2,     2,     2,     2,     0,
       1,     1,     2,     2,     2,     1,     1,     0,     2,     2,
       2,     2,     0,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     4,     4,     6,     4,
       4,     6,     4,     4,     4,     4,     1,     7,     0,     1,
       5,     6,     6,     6,     6,     6,     5,     0,     1,     1,
       1,     0,     1,     2,     0,     1,     2,     2,     1,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
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
  "_QDatasetClause_E_Star", "SubSelect", "@3", "@4", "Project",
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
  "OffsetClause", "Update", "Modify", "Insert", "@5", "Delete", "@6",
  "Clear", "_QGraphRef_E_Opt", "Load", "_QIRIref_E_Plus",
  "_O_QIT_INTO_E_S_QGraphRef_E_C", "_Q_O_QIT_INTO_E_S_QGraphRef_E_C_E_Opt",
  "Drop", "_QIT_SILENT_E_Opt", "Create", "GraphRef", "BindingClause",
  "$@7", "_QVar_E_Plus", "_QBinding_E_Star", "Binding", "$@8",
  "_O_QVarOrTerm_E_Or_QIT_NULL_E_C",
  "_Q_O_QVarOrTerm_E_Or_QIT_NULL_E_C_E_Plus", "GroupGraphPattern", "$@9",
  "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C", "GroupGraphPatternSub",
  "_QTriplesBlock_E_Opt", "_O_QGraphPatternNotTriples_E_Or_QFilter_E_C",
  "_QGT_DOT_E_Opt",
  "_O_QGraphPatternNotTriples_E_Or_QFilter_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_Or_QFilter_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "GraphTemplate", "$@10",
  "_O_QIT_GRAPH_E_S_QVarOrIRIref_E_S_QGraphTemplate_E_C", "@11", "@12",
  "_O_QIT_GRAPH_E_S_QVarOrIRIref_E_S_QGraphTemplate_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QIT_GRAPH_E_S_QVarOrIRIref_E_S_QGraphTemplate_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "OptionalGraphPattern", "@13", "@14", "MinusGraphPattern", "@15", "@16",
  "GraphGraphPattern", "@17", "@18", "@19", "ServiceGraphPattern", "@20",
  "@21", "GroupOrUnionGraphPattern", "@22", "@23",
  "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@24",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "$@25",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ParamList", "$@26",
  "ConstructTemplate", "$@27", "_QConstructTriples_E_Opt",
  "ConstructTriples", "_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C_E_Opt", "TriplesSameSubject",
  "$@28", "$@29", "PropertyListNotEmpty", "_O_QVerb_E_S_QObjectList_E_C",
  "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "Verb", "TriplesNode", "BlankNodePropertyList", "@30",
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
       114,     0,    -1,   117,   115,    -1,   124,    -1,   138,    -1,
     139,    -1,   143,    -1,   116,    -1,   174,    -1,     3,   149,
       4,   207,    -1,   118,   119,    -1,    -1,   120,    -1,    -1,
     119,   121,    -1,    15,   104,    -1,    -1,    -1,    16,   122,
     105,   123,   104,    -1,   129,   125,   149,   152,    -1,    -1,
     125,   144,    -1,    -1,    -1,   129,   127,   128,   149,   152,
      -1,    17,   131,   137,    -1,    18,    -1,    19,    -1,    -1,
     130,    -1,    78,   277,    -1,    -1,   132,    -1,    41,   279,
     133,    42,    -1,   277,    -1,   303,    -1,   300,    -1,   239,
      -1,   309,    -1,   313,    -1,   317,    -1,   134,    -1,   135,
      -1,   136,   135,    -1,   136,    -1,    20,    -1,    21,   246,
     125,   149,   152,    -1,    22,   141,   125,   142,   152,    -1,
     276,    -1,   140,   276,    -1,   140,    -1,    20,    -1,    -1,
     149,    -1,    39,   125,   149,    -1,    23,   145,    -1,   146,
      -1,   147,    -1,   148,    -1,    24,   148,    -1,   319,    -1,
     150,   198,   151,    -1,    -1,    40,    -1,    -1,   190,    -1,
     153,   154,   155,   156,    -1,    -1,   157,    -1,    -1,   160,
      -1,    -1,   163,    -1,    -1,   169,    -1,    80,    26,   158,
      -1,   159,    -1,   158,   159,    -1,   300,    -1,   239,    -1,
      41,   279,   133,    42,    -1,   277,    -1,    81,   161,    -1,
     162,    -1,   161,   162,    -1,   238,    -1,    25,    26,   164,
      -1,   165,    -1,   164,   165,    -1,   167,    -1,   168,    -1,
      27,    -1,    28,    -1,   166,   299,    -1,   238,    -1,   277,
      -1,   172,   170,    -1,   173,   171,    -1,    -1,   173,    -1,
      -1,   172,    -1,    29,    91,    -1,    30,    91,    -1,   175,
      -1,   182,    -1,   180,    -1,   186,    -1,   188,    -1,   176,
      -1,   178,    -1,    -1,     6,   207,   177,   142,    -1,    -1,
       5,   207,   179,   142,    -1,    11,   181,    -1,    -1,   189,
      -1,     9,   183,   185,    -1,   319,    -1,   183,   319,    -1,
      10,   189,    -1,    -1,   184,    -1,    14,   187,   319,    -1,
      -1,    13,    -1,    12,   187,   319,    -1,     7,   319,    -1,
      -1,    31,   192,    37,   191,   193,    38,    -1,   277,    -1,
     192,   277,    -1,    -1,   193,   194,    -1,    -1,    41,   195,
     197,    42,    -1,   275,    -1,    43,    -1,   196,    -1,   197,
     196,    -1,    -1,    37,   199,   200,    38,    -1,   126,    -1,
     201,    -1,   202,   206,    -1,    -1,   214,    -1,   217,    -1,
     237,    -1,    -1,    44,    -1,   203,   204,   202,    -1,    -1,
     206,   205,    -1,    -1,    37,   208,   202,   213,    38,    -1,
      -1,    -1,   210,     7,   276,   211,   207,    -1,   209,   204,
     202,    -1,    -1,   213,   212,    -1,   252,   216,    -1,    44,
     202,    -1,    -1,   215,    -1,   218,    -1,   221,    -1,   231,
      -1,   224,    -1,   228,    -1,    -1,    -1,    45,   219,   220,
     198,    -1,    -1,    -1,    46,   222,   223,   198,    -1,    -1,
      -1,    -1,     7,   225,   226,   276,   227,   198,    -1,    -1,
      -1,     8,   229,   230,   276,   198,    -1,    -1,    -1,   232,
     233,   198,   236,    -1,    -1,    47,   235,   198,    -1,    -1,
     236,   234,    -1,    48,   238,    -1,   299,    -1,   300,    -1,
     239,    -1,   319,   240,    -1,   112,    -1,    -1,    41,   279,
     241,   243,    42,    -1,    49,   279,    -1,    -1,   243,   242,
      -1,    -1,    52,   279,   245,   243,    53,    -1,    -1,    37,
     247,   248,    38,    -1,    -1,   249,    -1,   252,   251,    -1,
      44,   248,    -1,    -1,   250,    -1,    -1,   275,   253,   255,
      -1,    -1,   267,   254,   260,    -1,   266,   262,   259,    -1,
     266,   262,    -1,    -1,   256,    -1,    50,   257,    -1,    -1,
     259,   258,    -1,   261,    -1,    -1,   255,    -1,   265,   264,
      -1,    49,   265,    -1,    -1,   264,   263,    -1,   274,    -1,
     276,    -1,    51,    -1,   270,    -1,   268,    -1,    -1,    52,
     269,   255,    53,    -1,   272,    41,   273,    42,    -1,    32,
      -1,    33,    -1,    34,    -1,    35,    -1,    36,    -1,    -1,
     271,    -1,   274,    -1,   273,   274,    -1,   275,    -1,   267,
      -1,   277,    -1,   278,    -1,   277,    -1,   319,    -1,   109,
      -1,   110,    -1,   319,    -1,   309,    -1,   313,    -1,   317,
      -1,   321,    -1,   112,    -1,   280,    -1,   283,   282,    -1,
      54,   283,    -1,    -1,   282,   281,    -1,   286,   285,    -1,
      55,   286,    -1,    -1,   285,   284,    -1,   287,    -1,   290,
     289,    -1,    56,   290,    -1,    57,   290,    -1,    58,   290,
      -1,    59,   290,    -1,    60,   290,    -1,    61,   290,    -1,
      -1,   288,    -1,   291,    -1,   294,   293,    -1,    62,   294,
      -1,    63,   294,    -1,   315,    -1,   316,    -1,    -1,   293,
     292,    -1,   297,   296,    -1,    20,   297,    -1,    64,   297,
      -1,    -1,   296,   295,    -1,    65,   298,    -1,    62,   298,
      -1,    63,   298,    -1,   298,    -1,   299,    -1,   300,    -1,
     307,    -1,   309,    -1,   313,    -1,   317,    -1,   277,    -1,
      41,   279,    42,    -1,    66,    41,   279,    42,    -1,    67,
      41,   279,    42,    -1,    68,    41,   279,    49,   279,    42,
      -1,    69,    41,   279,    42,    -1,    70,    41,   277,    42,
      -1,    71,    41,   279,    49,   279,    42,    -1,    72,    41,
     279,    42,    -1,    73,    41,   279,    42,    -1,    74,    41,
     279,    42,    -1,    75,    41,   279,    42,    -1,   301,    -1,
      76,    41,   279,    49,   279,   302,    42,    -1,    -1,   242,
      -1,    82,    41,   304,   305,    42,    -1,    83,    41,   304,
     279,    42,    42,    -1,    84,    41,   304,   279,    42,    42,
      -1,    85,    41,   304,   279,    42,    42,    -1,    86,    41,
     304,   279,    42,    42,    -1,    87,   306,    41,   304,   240,
      42,    -1,    88,    41,   304,   279,    42,    -1,    -1,    18,
      -1,    20,    -1,   279,    -1,    -1,   244,    -1,   319,   308,
      -1,    -1,   240,    -1,   318,   312,    -1,    77,   319,    -1,
     111,    -1,   310,    -1,    -1,   311,    -1,   314,    -1,   315,
      -1,   316,    -1,    91,    -1,    92,    -1,    93,    -1,    94,
      -1,    95,    -1,    96,    -1,    97,    -1,    98,    -1,    99,
      -1,    89,    -1,    90,    -1,   100,    -1,   102,    -1,   101,
      -1,   103,    -1,   104,    -1,   320,    -1,   106,    -1,   105,
      -1,   107,    -1,   108,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SPARQLfedParser::yyprhs_[] =
  {
         0,     0,     3,     6,     8,    10,    12,    14,    16,    18,
      23,    26,    27,    29,    30,    33,    36,    37,    38,    44,
      49,    50,    53,    54,    55,    61,    65,    67,    69,    70,
      72,    75,    76,    78,    83,    85,    87,    89,    91,    93,
      95,    97,    99,   101,   104,   106,   108,   114,   120,   122,
     125,   127,   129,   130,   132,   136,   139,   141,   143,   145,
     148,   150,   154,   155,   157,   158,   160,   165,   166,   168,
     169,   171,   172,   174,   175,   177,   181,   183,   186,   188,
     190,   195,   197,   200,   202,   205,   207,   211,   213,   216,
     218,   220,   222,   224,   227,   229,   231,   234,   237,   238,
     240,   241,   243,   246,   249,   251,   253,   255,   257,   259,
     261,   263,   264,   269,   270,   275,   278,   279,   281,   285,
     287,   290,   293,   294,   296,   300,   301,   303,   307,   310,
     311,   318,   320,   323,   324,   327,   328,   333,   335,   337,
     339,   342,   343,   348,   350,   352,   355,   356,   358,   360,
     362,   363,   365,   369,   370,   373,   374,   380,   381,   382,
     388,   392,   393,   396,   399,   402,   403,   405,   407,   409,
     411,   413,   415,   416,   417,   422,   423,   424,   429,   430,
     431,   432,   439,   440,   441,   447,   448,   449,   454,   455,
     459,   460,   463,   466,   468,   470,   472,   475,   477,   478,
     484,   487,   488,   491,   492,   498,   499,   504,   505,   507,
     510,   513,   514,   516,   517,   521,   522,   526,   530,   533,
     534,   536,   539,   540,   543,   545,   546,   548,   551,   554,
     555,   558,   560,   562,   564,   566,   568,   569,   574,   579,
     581,   583,   585,   587,   589,   590,   592,   594,   597,   599,
     601,   603,   605,   607,   609,   611,   613,   615,   617,   619,
     621,   623,   625,   627,   630,   633,   634,   637,   640,   643,
     644,   647,   649,   652,   655,   658,   661,   664,   667,   670,
     671,   673,   675,   678,   681,   684,   686,   688,   689,   692,
     695,   698,   701,   702,   705,   708,   711,   714,   716,   718,
     720,   722,   724,   726,   728,   730,   734,   739,   744,   751,
     756,   761,   768,   773,   778,   783,   788,   790,   798,   799,
     801,   807,   814,   821,   828,   835,   842,   848,   849,   851,
     853,   855,   856,   858,   861,   862,   864,   867,   870,   872,
     874,   875,   877,   879,   881,   883,   885,   887,   889,   891,
     893,   895,   897,   899,   901,   903,   905,   907,   909,   911,
     913,   915,   917,   919,   921,   923
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   375,   375,   382,   383,   384,   385,   386,   387,   391,
     399,   403,   405,   409,   411,   415,   421,   423,   421,   433,
     440,   443,   454,   456,   454,   466,   474,   477,   484,   487,
     492,   499,   502,   507,   514,   517,   518,   519,   520,   523,
     526,   530,   535,   538,   545,   548,   555,   563,   570,   574,
     582,   585,   592,   595,   600,   607,   614,   615,   619,   625,
     631,   638,   645,   647,   651,   654,   659,   666,   669,   674,
     677,   682,   685,   690,   694,   698,   705,   708,   715,   716,
     717,   720,   726,   732,   735,   742,   747,   754,   758,   766,
     768,   776,   779,   787,   795,   796,   803,   807,   815,   818,
     823,   826,   830,   836,   842,   843,   844,   845,   846,   850,
     851,   855,   855,   864,   864,   873,   879,   882,   886,   893,
     896,   904,   911,   914,   918,   924,   927,   933,   939,   946,
     946,   956,   960,   968,   971,   979,   979,   989,   990,   997,
    1001,  1009,  1009,  1021,  1022,  1027,  1031,  1033,  1038,  1039,
    1043,  1045,  1050,  1054,  1057,  1062,  1062,  1072,  1075,  1072,
    1086,  1090,  1092,  1097,  1102,  1106,  1109,  1113,  1114,  1115,
    1116,  1117,  1121,  1123,  1121,  1137,  1139,  1137,  1148,  1150,
    1152,  1148,  1163,  1165,  1163,  1175,  1178,  1175,  1188,  1188,
    1202,  1204,  1208,  1219,  1220,  1221,  1225,  1232,  1236,  1236,
    1246,  1252,  1254,  1261,  1261,  1271,  1271,  1279,  1281,  1286,
    1291,  1295,  1297,  1301,  1301,  1304,  1304,  1311,  1316,  1320,
    1322,  1327,  1331,  1333,  1338,  1342,  1344,  1349,  1354,  1358,
    1360,  1364,  1371,  1375,  1382,  1383,  1387,  1387,  1400,  1425,
    1428,  1431,  1434,  1437,  1444,  1447,  1452,  1457,  1464,  1465,
    1469,  1472,  1476,  1479,  1485,  1486,  1490,  1493,  1496,  1499,
    1502,  1503,  1509,  1514,  1523,  1530,  1533,  1541,  1550,  1557,
    1560,  1567,  1572,  1583,  1586,  1589,  1592,  1595,  1598,  1605,
    1609,  1613,  1618,  1627,  1630,  1633,  1636,  1643,  1646,  1654,
    1663,  1666,  1673,  1676,  1683,  1686,  1689,  1692,  1696,  1697,
    1698,  1699,  1702,  1705,  1708,  1714,  1720,  1723,  1726,  1729,
    1732,  1735,  1738,  1741,  1744,  1747,  1750,  1755,  1762,  1765,
    1769,  1772,  1775,  1778,  1781,  1784,  1788,  1794,  1797,  1803,
    1806,  1810,  1813,  1817,  1827,  1830,  1835,  1843,  1850,  1854,
    1862,  1866,  1870,  1871,  1872,  1876,  1877,  1878,  1882,  1883,
    1884,  1888,  1889,  1890,  1894,  1895,  1899,  1900,  1901,  1902,
    1906,  1907,  1911,  1912,  1916,  1917
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
  const int SPARQLfedParser::yylast_ = 1203;
  const int SPARQLfedParser::yynnts_ = 209;
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
#line 3758 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 1923 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


