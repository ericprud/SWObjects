
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
#line 234 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 364 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

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
#line 379 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(2) - (2)].p_Operation);
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 395 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Replace((yysemantic_stack_[(4) - (2)].p_WhereClause), driver.curOp);
	driver.curOp = NULL;
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 419 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 425 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 427 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 429 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 437 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Select((yysemantic_stack_[(4) - (1)].p_Project).distinctness, (yysemantic_stack_[(4) - (1)].p_Project).varSet, (yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 444 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 447 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 458 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 460 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 462 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(5) - (1)].p_Project).distinctness, (yysemantic_stack_[(5) - (1)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier))));
      }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 470 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 478 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 481 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 488 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 496 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 503 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 511 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 518 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 521 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 524 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 527 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 530 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new POSExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 533 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new POSExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 536 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new POSExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 545 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 548 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 556 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 559 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 566 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	(yyval.p_Operation) = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(5) - (2)].p_BasicGraphPattern), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 574 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 581 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new POSExpression((yysemantic_stack_[(1) - (1)].p_POS))));
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 584 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new POSExpression((yysemantic_stack_[(2) - (2)].p_POS))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 592 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 595 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 602 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 610 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(3) - (2)].p_DatasetClauses), (yysemantic_stack_[(3) - (3)].p_WhereClause));
    }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 617 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 629 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_POS), driver.posFactory);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 635 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_POS), driver.posFactory);
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 641 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 648 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp, (yysemantic_stack_[(3) - (3)].p_BindingClause));
	driver.curOp = NULL;
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 661 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 669 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 676 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = NULL;
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 684 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 692 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 700 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 708 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 715 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 718 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 725 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 728 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 731 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 734 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 740 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 746 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 749 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 761 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 768 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 772 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 782 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 790 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 793 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 801 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 810 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 817 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 821 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 829 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 837 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 844 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 850 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 869 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 872 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert((yysemantic_stack_[(4) - (3)].p_TableOperation), (yysemantic_stack_[(4) - (4)].p_WhereClause));
      }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 878 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 881 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(4) - (3)].p_TableOperation), (yysemantic_stack_[(4) - (4)].p_WhereClause));
      }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 887 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(2) - (2)].p_URI));
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 893 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 900 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(3) - (2)].p_URIs), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 907 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URIs) = new ProductionVector<const URI*>((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 910 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_URIs)->push_back((yysemantic_stack_[(2) - (2)].p_URI));
	(yyval.p_URIs) = (yysemantic_stack_[(2) - (1)].p_URIs);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 918 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 925 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 932 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 938 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 941 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 947 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 953 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 960 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_POSList));
      }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 962 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = driver.curBindingClause;
	  driver.curBindingClause = NULL;
      }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 970 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSList) = new POSList;
	(yyval.p_POSList)->push_back((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 974 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_POSList) = (yysemantic_stack_[(2) - (1)].p_POSList);
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 982 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Bindings) = NULL;
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 985 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingClause->push_back((yysemantic_stack_[(2) - (2)].p_Binding));
	(yyval.p_Bindings) = NULL;
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 993 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding = new Binding();
      }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 995 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Binding) = driver.curBinding;
	  driver.curBinding = NULL;
      }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1004 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getNULL();
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1011 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_POS));
	(yyval.p_POSs) = NULL;
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1015 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = NULL;
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1023 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1026 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1076 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1079 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
      }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1086 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curFilter = NULL;
      }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1089 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_POS);
      }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1092 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(5) - (3)].p_POS), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(5) - (4)].p_POS);
      }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 1135 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 1137 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.curFilter;
      }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1139 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 1151 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 1153 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 1155 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.curOp));
      }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 1162 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 1164 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 1166 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_POS);
      }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 1169 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_POS), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_POS);
      }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 1177 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 1179 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 1181 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(5) - (4)].p_POS), driver.curOp, driver.posFactory, false));
      }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 1189 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 1192 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 1194 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 1202 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 1207 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 1222 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 1239 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1246 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1250 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 1252 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList);
	  driver.curExprList = NULL;
      }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 1260 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 1268 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 1275 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 1277 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 1285 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 1287 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 1315 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 1318 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 1378 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.posFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_POS)));
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 1385 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_POS);
	driver.curPredicate = (yyval.p_POS);
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 1389 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_POS);
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 1401 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 1405 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 1414 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 1439 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 1442 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 1445 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 1448 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 1451 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 1458 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 1466 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSs) = new ProductionVector<const POS*>();
	(yyval.p_POSs)->push_back((yysemantic_stack_[(1) - (1)].p_POS));
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 1471 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSs)->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = (yysemantic_stack_[(2) - (1)].p_POSs);
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 1483 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 1490 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 1493 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 1504 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 1507 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 1510 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 1513 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 1517 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 1528 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 1537 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 1544 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 1547 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 1555 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 1564 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 1571 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 1574 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 1586 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 1597 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 1600 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 1603 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 1606 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 1609 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yyval.p_BooleanComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 1612 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 1619 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BooleanComparator) = NULL;
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 1632 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 1641 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 1644 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 1647 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 1650 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 1657 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 1660 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 1668 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 1677 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 1680 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 1687 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 1690 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 1697 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 1700 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 1703 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 1713 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 1716 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 1719 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 1722 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 1728 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 1734 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-str"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 1737 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-lang"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 1740 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-langMatches"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 1743 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-datatype"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 1746 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-bound"), new POSExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 1749 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sameTerm"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 1752 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 1755 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 1758 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isBlank"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 1761 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isLiteral"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 1769 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-regex"), (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 1776 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 1783 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-count"), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 1786 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sum"), (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression)));
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 1789 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-min"), (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression)));
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 1792 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-max"), (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression)));
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 1795 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-avg"), (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression)));
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 1798 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	throw NotImplemented("CONCAT");
	// $$ = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-group-concat"), $4, $2));
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 1802 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sample"), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 1808 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 1811 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 1817 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 1824 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 1831 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new POSExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 1841 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 1849 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 1857 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 1864 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 1868 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 1876 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 2587 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -412;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        29,   -80,    39,   602,  -412,  -412,  -412,  -412,    17,    34,
      34,    44,    54,    79,    79,    71,    46,    33,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,    62,  -412,    93,    80,  -412,  -412,
    -412,  -412,  -412,  -412,     8,  -412,  -412,    44,  -412,  -412,
    -412,    44,    44,  -412,  -412,  -412,   580,  -412,  -412,  -412,
    -412,  -412,   205,  -412,  -412,  -412,  -412,    20,    20,  -412,
    -412,    34,  -412,    99,   744,    15,    15,    54,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,  1006,    61,    98,   102,   103,
     110,   113,   114,   117,   118,   123,   124,   130,   133,   134,
     135,   136,    88,   139,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,   941,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,   -52,    -4,   744,    20,  -412,     9,
      18,  -412,  -412,   104,    81,  -412,   490,    11,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,   140,  -412,  -412,  -412,  -412,   148,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  1006,
    1050,  1050,  1050,  -412,   109,  -412,  -412,  -412,  -412,   146,
    -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
      -4,  1006,  1006,  1006,  1006,    11,  1006,  1006,  1006,  1006,
    1006,  1006,   172,   172,   172,   172,   172,  1006,  -412,   168,
     172,  -412,    44,  -412,  -412,  -412,  -412,  1006,  -412,  -412,
     174,  -412,   169,   104,   104,    44,  -412,  -412,  -412,  -412,
    -412,   192,  -412,   142,  -412,  -412,  -412,  -412,   185,  -412,
    -412,   -13,  -412,    64,   187,   744,  -412,  -412,    64,   848,
      64,   184,  -412,  -412,  -412,    11,  -412,   189,   178,   180,
    1006,  1006,  1006,  1006,  1006,  1006,  -412,  -412,   158,    -5,
    -412,  -412,   194,   196,   190,   198,   201,   197,   203,   208,
     217,   220,   215,  -412,   666,  1006,  1006,  1006,  1006,  -412,
     172,  1006,  -412,  -412,  -412,   744,  -412,  -412,  -412,  -412,
    -412,   312,   499,   241,  -412,   164,  -412,  -412,   171,  -412,
    -412,  -412,   221,   848,  -412,  -412,   232,   273,  -412,  -412,
    -412,  -412,  -412,  -412,   768,  -412,  -412,  -412,  -412,  -412,
    -412,  1006,  -412,  1006,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  1006,  1006,  -412,  -412,  -412,  1006,  1006,  -412,  -412,
    -412,  1006,  -412,  -412,  1006,  -412,  -412,  -412,  -412,  1006,
    -412,  -412,   240,   242,   243,   244,   246,  -412,    -4,   249,
    -412,  -412,  1006,   312,  -412,  -412,  -412,  -412,   499,  -412,
    -412,  -412,  -412,  -412,   266,    70,  -412,  -412,    17,  -412,
    -412,  -412,  -412,   499,   232,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
     744,   205,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
     253,   254,   248,  -412,   257,   261,   262,   264,     1,   265,
    -412,   -14,   109,  -412,  -412,   125,   227,   228,  -412,  -412,
     268,   282,   104,  -412,  -412,  -412,  -412,  -412,   744,    80,
      41,   270,   275,  -412,  -412,  -412,  -412,  1006,  -412,   280,
    -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,   283,  -412,
    -412,   125,  -412,   285,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,   205,   205,    80,    80,  -412,
    -412,  -412,  -412,  -412,    64,  -412,   848,  -412,    34,  -412,
    -412,  -412,  -412,  -412,  -412,    80,  -412,  -412,   281,  1084,
    -412,  -412,   848,  -412,  -412,    80,  -412,  -412,  -412,  -412,
    -412,   872,  -412,  -412,  -412,    80,  -412,  -412,  -412
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
      -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,    12,  -412,  -412,  -412,   181,  -412,  -412,  -412,
    -111,  -412,   211,  -412,  -412,  -412,  -412,  -412,  -412,   -62,
    -412,  -412,  -412,  -412,  -412,   106,    -3,  -412,  -412,  -225,
    -412,  -412,  -412,  -412,  -412,  -412,   -49,  -412,  -412,   -46,
    -412,  -412,  -136,  -412,  -412,  -412,  -412,  -412,  -412,  -105,
    -101,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,   336,  -412,   274,  -412,  -412,  -412,
    -412,  -412,  -412,  -179,  -412,  -411,  -412,  -412,  -412,  -139,
    -412,   -50,  -412,  -412,    -9,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,  -372,   -53,  -196,  -412,   -77,
     -24,  -412,  -412,  -412,  -412,    52,  -412,  -412,  -412,  -124,
    -412,  -412,  -191,  -412,  -412,  -412,  -412,  -412,  -412,  -163,
    -412,  -412,  -146,  -143,  -249,  -412,  -412,  -412,  -412,  -412,
    -412,  -246,  -229,   -15,    10,  -412,   256,  -412,  -412,  -412,
      21,  -412,  -412,    22,  -412,  -412,  -412,    65,  -412,  -412,
    -412,  -219,  -412,  -412,  -230,   -19,  -295,   -40,  -412,  -412,
    -412,  -194,  -412,  -412,  -412,  -412,   -45,  -412,  -412,  -412,
     -18,  -412,    86,    89,    24,  -412,   -11,  -412,  -412
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
     333,   128,   232,   335,   177,   356,   125,   392,    77,   295,
     296,   297,   298,     6,   319,   222,   301,    65,   477,   170,
     336,   457,   140,    80,    68,   467,    81,   227,   129,     7,
      82,    83,   235,   140,     1,   135,   -62,   138,   500,    35,
     467,    66,   -62,    59,   474,    35,   171,    35,   223,   357,
      35,    47,   145,   173,   142,   143,   124,   330,   123,   337,
     137,    38,    65,   486,   333,   139,   128,   234,    69,   501,
     133,   125,   502,    57,   168,   333,   516,   517,   423,    53,
      54,   170,    50,   392,   336,    60,    61,    71,   172,   446,
     447,   170,   201,   129,   526,   336,   378,   228,   392,   486,
     135,    41,    42,    43,   534,   321,   329,    72,   171,    60,
      61,    41,    42,    43,   538,   173,   428,   429,   171,   240,
     147,   124,   426,   427,   233,   173,    41,    42,    43,   202,
     217,    60,    61,   203,   204,   133,   168,    41,    42,    43,
     392,   205,   479,   480,   206,   207,   168,   252,   208,   209,
     172,   262,   263,   264,   210,   211,   179,    41,    42,    43,
     172,   212,    60,    61,   213,   214,   215,   216,   399,   400,
     220,   232,   439,   241,   255,   245,   392,   265,   513,   259,
     293,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,   270,   271,   272,   273,   274,   275,  -185,   300,
     170,   302,   304,   305,   170,   286,   401,   402,   311,   403,
     351,   352,   312,   317,   240,   325,   338,   494,    41,    42,
      43,   340,   341,    60,    61,   343,   359,   171,   360,   361,
     362,   171,    66,   363,   173,   365,   364,    66,   173,    66,
     366,   109,   110,   111,   112,   113,   114,   333,   385,   367,
     170,   320,   368,    65,   369,   168,   394,   397,    65,   168,
      65,   387,   393,   333,   415,   339,   419,   336,   170,   172,
     421,   463,   433,   172,   434,   435,   436,   171,   437,   170,
     532,   440,   445,   336,   173,   465,   466,   467,   447,   470,
     135,   135,   532,   471,   472,   171,   473,   476,    41,    42,
      43,   446,   173,    60,    61,   168,   171,   488,   489,   499,
     504,   386,   510,   173,   506,   511,   179,   247,   527,   172,
     385,   478,   221,   168,   443,   345,   346,   347,   348,   349,
     350,   310,   444,   387,   168,   512,   493,   172,   393,   491,
      52,   178,   537,   382,   458,   468,   441,   381,   172,   533,
     523,   522,   424,   393,   354,   425,     0,   355,     0,     0,
       0,     0,   135,     0,     0,   170,     0,   135,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,     0,
       0,     0,   135,   386,     0,   452,     0,     0,     0,     0,
       0,     0,   171,     0,     0,   393,   464,     0,     0,   173,
      66,     0,     0,   170,     0,    41,    42,    43,     0,     0,
      60,    61,     0,     0,     0,     0,     0,     0,     0,     0,
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
      91,    92,    93,    94,    95,    96,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    41,    42,    43,   156,   157,    60,    61,
      84,   158,    41,    42,    43,     8,     0,     9,    10,     0,
       0,    11,     0,    12,    13,     0,    14,   430,     0,    15,
     431,    85,     0,    16,    17,   432,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   442,     0,
       0,    18,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    41,    42,    43,   370,     0,    60,    61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   509,     0,     0,     0,     0,   180,   181,
       0,   182,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    41,
      42,    43,     0,     0,    60,    61,   150,   151,   152,   153,
     154,     0,     0,     0,     0,  -244,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   155,     0,     0,     0,
     150,   151,   152,   153,   154,     0,     0,     0,     0,     0,
     422,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     155,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,    41,    42,    43,
     156,   157,    60,    61,     0,   158,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    41,    42,    43,   156,   157,    60,    61,     0,   158,
     150,   151,   152,   153,   154,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     155,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   536,   529,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    41,    42,    43,   156,   157,    60,    61,     0,   158,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    41,    42,    43,   156,   157,
      60,    61,    85,   158,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    41,    42,    43,   179,     0,    60,
      61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,   181,
       0,   182,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,     0,     0,     0,     0,     0,     0,     0,
       0,   179,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    41,
      42,    43,     0,     0,    60,    61,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,   529,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    41,    42,    43,     0,     0,    60,    61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,    41,    42,    43,
     156,   157,    60,    61,     0,   158
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        11,    10,    17,    56,   200,     8,    17,   146,   233,   234,
     259,    56,   136,   259,    76,    20,    56,   312,    10,   213,
     214,   215,   216,   103,    37,    77,   220,    17,    42,    74,
     259,   403,    23,    44,    22,    49,    47,    41,    56,     0,
      51,    52,    24,    23,    15,    56,    37,    62,   459,    40,
      49,    62,    37,    20,    53,    40,    74,    40,   110,    64,
      40,     7,    71,    74,    67,    68,    56,   258,   121,   260,
      58,    37,    62,   445,   323,    63,   121,   139,    16,    38,
      56,   121,    41,    37,    74,   334,   497,   498,   334,    18,
      19,   136,    13,   388,   323,   108,   109,     4,    74,    29,
      30,   146,    41,   121,   515,   334,   300,   111,   403,   481,
     121,   103,   104,   105,   525,    51,   255,    37,   136,   108,
     109,   103,   104,   105,   535,   136,   356,   357,   146,   140,
      31,   121,   351,   352,   137,   146,   103,   104,   105,    41,
      52,   108,   109,    41,    41,   121,   136,   103,   104,   105,
     445,    41,    27,    28,    41,    41,   146,   147,    41,    41,
     136,   180,   181,   182,    41,    41,    41,   103,   104,   105,
     146,    41,   108,   109,    41,    41,    41,    41,     7,     8,
      41,   305,   378,    79,    44,   104,   481,    78,   483,    41,
      18,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    56,    57,    58,    59,    60,    61,    37,    41,
     255,   222,    38,    44,   259,   205,    45,    46,    26,    48,
      62,    63,    80,    38,   235,    38,    42,   452,   103,   104,
     105,    42,    54,   108,   109,    55,    42,   255,    42,    49,
      42,   259,   253,    42,   255,    42,    49,   258,   259,   260,
      42,    93,    94,    95,    96,    97,    98,   506,   311,    42,
     305,   251,    42,   253,    49,   255,    25,   103,   258,   259,
     260,   311,   312,   522,    53,   265,    44,   506,   323,   255,
       7,   420,    42,   259,    42,    42,    42,   305,    42,   334,
     519,    42,    26,   522,   305,    42,    42,    49,    30,    42,
     311,   312,   531,    42,    42,   323,    42,    42,   103,   104,
     105,    29,   323,   108,   109,   305,   334,    90,    90,   458,
      50,   311,    42,   334,    49,    42,    41,   146,    47,   305,
     383,   442,   121,   323,   383,   270,   271,   272,   273,   274,
     275,   235,   388,   383,   334,   481,   451,   323,   388,   450,
      14,    77,   531,    41,   404,   432,   380,   305,   334,   522,
     506,   504,   341,   403,   278,   343,    -1,   278,    -1,    -1,
      -1,    -1,   383,    -1,    -1,   420,    -1,   388,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,   403,   383,    -1,   398,    -1,    -1,    -1,    -1,
      -1,    -1,   420,    -1,    -1,   445,   421,    -1,    -1,   420,
     421,    -1,    -1,   458,    -1,   103,   104,   105,    -1,    -1,
     108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      71,    72,    73,    74,    75,    76,    -1,    -1,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
      20,   111,   103,   104,   105,     3,    -1,     5,     6,    -1,
      -1,     9,    -1,    11,    12,    -1,    14,   361,    -1,    17,
     364,    41,    -1,    21,    22,   369,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   382,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    20,    -1,   108,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   467,    -1,    -1,    -1,    -1,    62,    63,
      -1,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,    -1,    -1,   108,   109,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,    -1,   111,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,   111,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,   111,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    41,   111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,    41,    -1,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      -1,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    -1,    -1,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,    -1,    -1,   108,   109,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    -1,    -1,   108,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,    -1,   111
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    15,   113,   116,   117,   119,   103,     0,     3,     5,
       6,     9,    11,    12,    14,    17,    21,    22,    39,   114,
     115,   123,   128,   137,   138,   142,   173,   174,   175,   177,
     179,   181,   185,   187,   118,    40,   148,   149,    37,   206,
     206,   103,   104,   105,   182,   318,   319,     7,   180,   188,
      13,   186,   186,    18,    19,   129,   130,    37,   245,    20,
     108,   109,   139,   140,   275,   276,   318,   124,   124,    16,
     120,     4,    37,   197,   207,   178,   176,    10,   183,   184,
     318,   318,   318,   318,    20,    41,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   133,
     134,   135,   136,   238,   276,   299,   300,   302,   308,   312,
     313,   314,   315,   316,   317,   318,   246,   124,   275,   124,
      23,   143,   148,   148,   121,   206,   198,    31,   150,   189,
      32,    33,    34,    35,    36,    52,   106,   107,   111,   201,
     213,   251,   266,   267,   269,   270,   271,   274,   276,   277,
     308,   312,   316,   318,   320,   141,   148,   141,   188,    41,
      62,    63,    65,   276,   278,   279,   282,   285,   286,   289,
     290,   293,   296,   297,   298,   299,   306,   308,   312,   316,
     318,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    52,   243,   305,
      41,   134,    77,   110,   309,   310,   311,    41,   111,   239,
     247,   248,   251,   148,   141,    24,   144,   145,   146,   147,
     318,    79,   151,   152,   156,   104,   125,   128,   199,   200,
     201,   191,   276,   268,   212,    44,   214,   215,   253,    41,
     252,   278,   297,   297,   297,    78,   131,   132,   281,   284,
      56,    57,    58,    59,    60,    61,   287,   288,   292,   295,
     239,   307,   278,   278,   278,   278,   276,   278,   278,   278,
     278,   278,   278,    18,   303,   303,   303,   303,   303,   278,
      41,   303,   318,   278,    38,    44,   249,   250,   151,   151,
     147,    26,    80,   153,   159,   122,   126,    38,   205,    37,
     276,    51,   254,   265,   275,    38,   208,   209,   211,   201,
     254,   259,   260,   266,   272,   273,   274,   254,    42,   276,
      42,    54,   280,    55,   283,   289,   289,   289,   289,   289,
     289,    62,    63,   291,   314,   315,    20,    64,   294,    42,
      42,    49,    42,    42,    49,    42,    42,    42,    42,    49,
      20,   278,   304,   278,   278,   278,   278,   244,   303,   278,
     240,   247,    41,   157,   158,   238,   276,   299,   160,   161,
     237,   238,   298,   299,    25,   154,   162,   103,   127,     7,
       8,    45,    46,    48,   202,   204,   216,   217,   220,   223,
     227,   230,   231,   236,   190,    53,   261,   264,   273,    44,
     203,     7,    42,   273,   282,   285,   293,   293,   296,   296,
     278,   278,   278,    42,    42,    42,    42,    42,   242,   239,
      42,   242,   278,   158,   161,    26,    29,    30,   155,   168,
     171,   172,   148,   224,   228,   218,   221,   237,   203,   232,
     192,   258,   263,   201,   275,    42,    42,    49,   241,   301,
      42,    42,    42,    42,    53,   241,    42,    42,   132,    27,
      28,   163,   164,   165,   166,   167,   237,   276,    90,    90,
     169,   172,   170,   171,   151,   225,   229,   219,   222,   201,
     197,    38,    41,   193,    50,   257,    49,   262,   210,   278,
      42,    42,   164,   298,   275,   275,   197,   197,   235,   194,
     255,   256,   265,   264,   206,   226,   197,    47,   233,    43,
     195,   196,   274,   261,   197,   234,    42,   195,   197
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
     365,   366
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  SPARQLfedParser::yyr1_[] =
  {
         0,   112,   113,   114,   114,   114,   114,   114,   114,   115,
     116,   117,   117,   118,   118,   119,   121,   122,   120,   123,
     124,   124,   126,   127,   125,   128,   129,   129,   130,   130,
     131,   132,   132,   133,   134,   134,   134,   134,   134,   134,
     134,   134,   135,   135,   136,   136,   137,   138,   139,   139,
     140,   140,   141,   141,   142,   143,   144,   144,   145,   146,
     147,   148,   149,   149,   150,   150,   151,   152,   152,   153,
     153,   154,   154,   155,   155,   156,   157,   157,   158,   158,
     158,   158,   159,   160,   160,   161,   162,   163,   163,   164,
     164,   165,   165,   166,   167,   167,   168,   168,   169,   169,
     170,   170,   171,   172,   173,   173,   173,   173,   173,   174,
     174,   176,   175,   178,   177,   179,   180,   180,   181,   182,
     182,   183,   184,   184,   185,   186,   186,   187,   188,   190,
     189,   191,   191,   192,   192,   194,   193,   195,   195,   196,
     196,   198,   197,   199,   199,   200,   201,   201,   202,   202,
     203,   203,   204,   205,   205,   207,   206,   209,   210,   208,
     211,   212,   212,   213,   214,   215,   215,   216,   216,   216,
     216,   216,   218,   219,   217,   221,   222,   220,   224,   225,
     226,   223,   228,   229,   227,   231,   232,   230,   234,   233,
     235,   235,   236,   237,   237,   237,   238,   239,   240,   239,
     241,   242,   242,   244,   243,   246,   245,   247,   247,   248,
     249,   250,   250,   252,   251,   253,   251,   254,   255,   256,
     256,   257,   258,   258,   259,   260,   260,   261,   262,   263,
     263,   264,   265,   265,   266,   266,   268,   267,   269,   270,
     270,   270,   270,   270,   271,   271,   272,   272,   273,   273,
     274,   274,   275,   275,   276,   276,   277,   277,   277,   277,
     277,   277,   278,   279,   280,   281,   281,   282,   283,   284,
     284,   285,   286,   287,   287,   287,   287,   287,   287,   288,
     288,   289,   290,   291,   291,   291,   291,   292,   292,   293,
     294,   294,   295,   295,   296,   296,   296,   296,   297,   297,
     297,   297,   297,   297,   297,   298,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   300,   301,   301,
     302,   302,   302,   302,   302,   302,   302,   303,   303,   304,
     304,   305,   305,   306,   307,   307,   308,   309,   310,   310,
     311,   311,   312,   312,   312,   313,   313,   313,   314,   314,
     314,   315,   315,   315,   316,   316,   317,   317,   317,   317,
     318,   318,   319,   319,   320,   320
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
  "IT_GROUP", "IT_HAVING", "IT_COUNT", "IT_SUM", "IT_MIN", "IT_MAX",
  "IT_AVG", "IT_GROUP_CONCAT", "IT_SAMPLE", "IT_true", "IT_false",
  "INTEGER", "DECIMAL", "DOUBLE", "INTEGER_POSITIVE", "DECIMAL_POSITIVE",
  "DOUBLE_POSITIVE", "INTEGER_NEGATIVE", "DECIMAL_NEGATIVE",
  "DOUBLE_NEGATIVE", "STRING_LITERAL1", "STRING_LITERAL_LONG1",
  "STRING_LITERAL2", "STRING_LITERAL_LONG2", "IRI_REF", "PNAME_NS",
  "PNAME_LN", "BLANK_NODE_LABEL", "ANON", "VAR1", "VAR2", "LANGTAG", "NIL",
  "$accept", "Query",
  "_O_QSelectQuery_E_Or_QConstructQuery_E_Or_QDescribeQuery_E_Or_QAskQuery_E_Or_QReplace_E_Or_QUpdate_E_C",
  "Replace", "Prologue", "_QBaseDecl_E_Opt", "_QPrefixDecl_E_Star",
  "BaseDecl", "PrefixDecl", "$@1", "$@2", "SelectQuery",
  "_QDatasetClause_E_Star", "SubSelect", "@3", "@4", "Project",
  "_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C",
  "_Q_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C_E_Opt", "_O_QIT_AS_E_S_QVar_E_C",
  "_Q_O_QIT_AS_E_S_QVar_E_C_E_Opt",
  "_O_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_Q_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C_E_Plus",
  "_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_Plus_Or_QGT_TIMES_E_C",
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
       113,     0,    -1,   116,   114,    -1,   123,    -1,   137,    -1,
     138,    -1,   142,    -1,   115,    -1,   173,    -1,     3,   148,
       4,   206,    -1,   117,   118,    -1,    -1,   119,    -1,    -1,
     118,   120,    -1,    15,   103,    -1,    -1,    -1,    16,   121,
     104,   122,   103,    -1,   128,   124,   148,   151,    -1,    -1,
     124,   143,    -1,    -1,    -1,   128,   126,   127,   148,   151,
      -1,    17,   130,   136,    -1,    18,    -1,    19,    -1,    -1,
     129,    -1,    78,   276,    -1,    -1,   131,    -1,    41,   278,
     132,    42,    -1,   276,    -1,   302,    -1,   299,    -1,   238,
      -1,   308,    -1,   312,    -1,   316,    -1,   133,    -1,   134,
      -1,   135,   134,    -1,   135,    -1,    20,    -1,    21,   245,
     124,   148,   151,    -1,    22,   140,   124,   141,   151,    -1,
     275,    -1,   139,   275,    -1,   139,    -1,    20,    -1,    -1,
     148,    -1,    39,   124,   148,    -1,    23,   144,    -1,   145,
      -1,   146,    -1,   147,    -1,    24,   147,    -1,   318,    -1,
     149,   197,   150,    -1,    -1,    40,    -1,    -1,   189,    -1,
     152,   153,   154,   155,    -1,    -1,   156,    -1,    -1,   159,
      -1,    -1,   162,    -1,    -1,   168,    -1,    79,    26,   157,
      -1,   158,    -1,   157,   158,    -1,   299,    -1,   238,    -1,
      41,   278,   132,    42,    -1,   276,    -1,    80,   160,    -1,
     161,    -1,   160,   161,    -1,   237,    -1,    25,    26,   163,
      -1,   164,    -1,   163,   164,    -1,   166,    -1,   167,    -1,
      27,    -1,    28,    -1,   165,   298,    -1,   237,    -1,   276,
      -1,   171,   169,    -1,   172,   170,    -1,    -1,   172,    -1,
      -1,   171,    -1,    29,    90,    -1,    30,    90,    -1,   174,
      -1,   181,    -1,   179,    -1,   185,    -1,   187,    -1,   175,
      -1,   177,    -1,    -1,     6,   206,   176,   141,    -1,    -1,
       5,   206,   178,   141,    -1,    11,   180,    -1,    -1,   188,
      -1,     9,   182,   184,    -1,   318,    -1,   182,   318,    -1,
      10,   188,    -1,    -1,   183,    -1,    14,   186,   318,    -1,
      -1,    13,    -1,    12,   186,   318,    -1,     7,   318,    -1,
      -1,    31,   191,    37,   190,   192,    38,    -1,   276,    -1,
     191,   276,    -1,    -1,   192,   193,    -1,    -1,    41,   194,
     196,    42,    -1,   274,    -1,    43,    -1,   195,    -1,   196,
     195,    -1,    -1,    37,   198,   199,    38,    -1,   125,    -1,
     200,    -1,   201,   205,    -1,    -1,   213,    -1,   216,    -1,
     236,    -1,    -1,    44,    -1,   202,   203,   201,    -1,    -1,
     205,   204,    -1,    -1,    37,   207,   201,   212,    38,    -1,
      -1,    -1,   209,     7,   275,   210,   206,    -1,   208,   203,
     201,    -1,    -1,   212,   211,    -1,   251,   215,    -1,    44,
     201,    -1,    -1,   214,    -1,   217,    -1,   220,    -1,   230,
      -1,   223,    -1,   227,    -1,    -1,    -1,    45,   218,   219,
     197,    -1,    -1,    -1,    46,   221,   222,   197,    -1,    -1,
      -1,    -1,     7,   224,   225,   275,   226,   197,    -1,    -1,
      -1,     8,   228,   229,   275,   197,    -1,    -1,    -1,   231,
     232,   197,   235,    -1,    -1,    47,   234,   197,    -1,    -1,
     235,   233,    -1,    48,   237,    -1,   298,    -1,   299,    -1,
     238,    -1,   318,   239,    -1,   111,    -1,    -1,    41,   278,
     240,   242,    42,    -1,    49,   278,    -1,    -1,   242,   241,
      -1,    -1,    52,   278,   244,   242,    53,    -1,    -1,    37,
     246,   247,    38,    -1,    -1,   248,    -1,   251,   250,    -1,
      44,   247,    -1,    -1,   249,    -1,    -1,   274,   252,   254,
      -1,    -1,   266,   253,   259,    -1,   265,   261,   258,    -1,
     265,   261,    -1,    -1,   255,    -1,    50,   256,    -1,    -1,
     258,   257,    -1,   260,    -1,    -1,   254,    -1,   264,   263,
      -1,    49,   264,    -1,    -1,   263,   262,    -1,   273,    -1,
     275,    -1,    51,    -1,   269,    -1,   267,    -1,    -1,    52,
     268,   254,    53,    -1,   271,    41,   272,    42,    -1,    32,
      -1,    33,    -1,    34,    -1,    35,    -1,    36,    -1,    -1,
     270,    -1,   273,    -1,   272,   273,    -1,   274,    -1,   266,
      -1,   276,    -1,   277,    -1,   276,    -1,   318,    -1,   108,
      -1,   109,    -1,   318,    -1,   308,    -1,   312,    -1,   316,
      -1,   320,    -1,   111,    -1,   279,    -1,   282,   281,    -1,
      54,   282,    -1,    -1,   281,   280,    -1,   285,   284,    -1,
      55,   285,    -1,    -1,   284,   283,    -1,   286,    -1,   289,
     288,    -1,    56,   289,    -1,    57,   289,    -1,    58,   289,
      -1,    59,   289,    -1,    60,   289,    -1,    61,   289,    -1,
      -1,   287,    -1,   290,    -1,   293,   292,    -1,    62,   293,
      -1,    63,   293,    -1,   314,    -1,   315,    -1,    -1,   292,
     291,    -1,   296,   295,    -1,    20,   296,    -1,    64,   296,
      -1,    -1,   295,   294,    -1,    65,   297,    -1,    62,   297,
      -1,    63,   297,    -1,   297,    -1,   298,    -1,   299,    -1,
     306,    -1,   308,    -1,   312,    -1,   316,    -1,   276,    -1,
      41,   278,    42,    -1,    66,    41,   278,    42,    -1,    67,
      41,   278,    42,    -1,    68,    41,   278,    49,   278,    42,
      -1,    69,    41,   278,    42,    -1,    70,    41,   276,    42,
      -1,    71,    41,   278,    49,   278,    42,    -1,    72,    41,
     278,    42,    -1,    73,    41,   278,    42,    -1,    74,    41,
     278,    42,    -1,    75,    41,   278,    42,    -1,   300,    -1,
      76,    41,   278,    49,   278,   301,    42,    -1,    -1,   241,
      -1,    81,    41,   303,   304,    42,    -1,    82,    41,   303,
     278,    42,    42,    -1,    83,    41,   303,   278,    42,    42,
      -1,    84,    41,   303,   278,    42,    42,    -1,    85,    41,
     303,   278,    42,    42,    -1,    86,   305,    41,   303,   239,
      42,    -1,    87,    41,   303,   278,    42,    -1,    -1,    18,
      -1,    20,    -1,   278,    -1,    -1,   243,    -1,   318,   307,
      -1,    -1,   239,    -1,   317,   311,    -1,    77,   318,    -1,
     110,    -1,   309,    -1,    -1,   310,    -1,   313,    -1,   314,
      -1,   315,    -1,    90,    -1,    91,    -1,    92,    -1,    93,
      -1,    94,    -1,    95,    -1,    96,    -1,    97,    -1,    98,
      -1,    88,    -1,    89,    -1,    99,    -1,   101,    -1,   100,
      -1,   102,    -1,   103,    -1,   319,    -1,   105,    -1,   104,
      -1,   106,    -1,   107,    -1
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
         0,   379,   379,   386,   387,   388,   389,   390,   391,   395,
     403,   407,   409,   413,   415,   419,   425,   427,   425,   437,
     444,   447,   458,   460,   458,   470,   478,   481,   488,   491,
     496,   503,   506,   511,   518,   521,   524,   527,   530,   533,
     536,   540,   545,   548,   556,   559,   566,   574,   581,   584,
     592,   595,   602,   605,   610,   617,   624,   625,   629,   635,
     641,   648,   655,   657,   661,   664,   669,   676,   679,   684,
     687,   692,   695,   700,   704,   708,   715,   718,   725,   728,
     731,   734,   740,   746,   749,   756,   761,   768,   772,   780,
     782,   790,   793,   801,   809,   810,   817,   821,   829,   832,
     837,   840,   844,   850,   856,   857,   858,   859,   860,   864,
     865,   869,   869,   878,   878,   887,   893,   896,   900,   907,
     910,   918,   925,   928,   932,   938,   941,   947,   953,   960,
     960,   970,   974,   982,   985,   993,   993,  1003,  1004,  1011,
    1015,  1023,  1023,  1035,  1036,  1041,  1045,  1047,  1052,  1053,
    1057,  1059,  1064,  1068,  1071,  1076,  1076,  1086,  1089,  1086,
    1100,  1104,  1106,  1111,  1116,  1120,  1123,  1127,  1128,  1129,
    1130,  1131,  1135,  1137,  1135,  1151,  1153,  1151,  1162,  1164,
    1166,  1162,  1177,  1179,  1177,  1189,  1192,  1189,  1202,  1202,
    1216,  1218,  1222,  1233,  1234,  1235,  1239,  1246,  1250,  1250,
    1260,  1266,  1268,  1275,  1275,  1285,  1285,  1293,  1295,  1300,
    1305,  1309,  1311,  1315,  1315,  1318,  1318,  1325,  1330,  1334,
    1336,  1341,  1345,  1347,  1352,  1356,  1358,  1363,  1368,  1372,
    1374,  1378,  1385,  1389,  1396,  1397,  1401,  1401,  1414,  1439,
    1442,  1445,  1448,  1451,  1458,  1461,  1466,  1471,  1478,  1479,
    1483,  1486,  1490,  1493,  1499,  1500,  1504,  1507,  1510,  1513,
    1516,  1517,  1523,  1528,  1537,  1544,  1547,  1555,  1564,  1571,
    1574,  1581,  1586,  1597,  1600,  1603,  1606,  1609,  1612,  1619,
    1623,  1627,  1632,  1641,  1644,  1647,  1650,  1657,  1660,  1668,
    1677,  1680,  1687,  1690,  1697,  1700,  1703,  1706,  1710,  1711,
    1712,  1713,  1716,  1719,  1722,  1728,  1734,  1737,  1740,  1743,
    1746,  1749,  1752,  1755,  1758,  1761,  1764,  1769,  1776,  1779,
    1783,  1786,  1789,  1792,  1795,  1798,  1802,  1808,  1811,  1817,
    1820,  1824,  1827,  1831,  1841,  1844,  1849,  1857,  1864,  1868,
    1876,  1880,  1884,  1885,  1886,  1890,  1891,  1892,  1896,  1897,
    1898,  1902,  1903,  1904,  1908,  1909,  1913,  1914,  1915,  1916,
    1920,  1921,  1925,  1926,  1930,  1931
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
     105,   106,   107,   108,   109,   110,   111
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SPARQLfedParser::yyeof_ = 0;
  const int SPARQLfedParser::yylast_ = 1195;
  const int SPARQLfedParser::yynnts_ = 209;
  const int SPARQLfedParser::yyempty_ = -2;
  const int SPARQLfedParser::yyfinal_ = 7;
  const int SPARQLfedParser::yyterror_ = 1;
  const int SPARQLfedParser::yyerrcode_ = 256;
  const int SPARQLfedParser::yyntokens_ = 112;

  const unsigned int SPARQLfedParser::yyuser_token_number_max_ = 366;
  const SPARQLfedParser::token_number_type SPARQLfedParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 3800 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 1937 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


