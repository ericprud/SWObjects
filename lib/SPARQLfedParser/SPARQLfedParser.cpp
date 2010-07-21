
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
#line 224 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 363 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

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
#line 377 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(2) - (2)].p_Operation);
}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 413 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 419 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 421 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 423 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 431 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Select((yysemantic_stack_[(4) - (1)].p_Project).distinctness, (yysemantic_stack_[(4) - (1)].p_Project).varSet, (yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 438 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 441 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 449 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 451 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 453 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(5) - (1)].p_Project).distinctness, (yysemantic_stack_[(5) - (1)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier))));
      }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 461 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 469 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 472 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 479 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 487 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 494 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 502 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 509 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 512 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 515 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 518 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 521 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new POSExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 524 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new POSExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 527 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new POSExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 536 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 539 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 547 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 550 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 557 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	(yyval.p_Operation) = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(5) - (2)].p_BasicGraphPattern), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 565 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 572 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new POSExpression((yysemantic_stack_[(1) - (1)].p_POS))));
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 575 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new POSExpression((yysemantic_stack_[(2) - (2)].p_POS))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 583 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 586 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 593 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 601 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(3) - (2)].p_DatasetClauses), (yysemantic_stack_[(3) - (3)].p_WhereClause));
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 608 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 620 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_POS), driver.posFactory);
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 626 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_POS), driver.posFactory);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 632 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 639 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp ? driver.curOp : new DefaultGraphPattern(), (yysemantic_stack_[(3) - (3)].p_BindingsClause));
	driver.curOp = NULL;
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 652 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 659 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = NULL;
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 667 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 675 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 683 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 691 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 698 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 701 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 708 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 711 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 714 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 717 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 723 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 729 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 732 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 744 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 751 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 755 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 765 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 773 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 776 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 784 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 793 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 800 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 804 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 812 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 820 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 827 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 833 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 846 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSList) = new POSList;
	(yyval.p_POSList)->push_back((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 850 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_POSList) = (yysemantic_stack_[(2) - (1)].p_POSList);
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 857 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_POS));
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 860 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_POS));
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 866 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding = new Binding();
      }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 868 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingValue) = driver.curBinding;
	  driver.curBinding = NULL;
      }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 875 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 878 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingsClause->push_back((yysemantic_stack_[(2) - (2)].p_BindingValue));
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 885 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingsClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_POSList));
      }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 887 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingsClause) = driver.curBindingsClause;
	  driver.curBindingsClause = NULL;
      }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 894 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingsClause) = NULL;
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 900 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 903 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 906 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 909 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 912 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getNULL();
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 915 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 925 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	OperationSet* ret = new OperationSet();
	ret->push_back((yysemantic_stack_[(1) - (1)].p_Operation));
	(yyval.p_Operation) = ret;
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 930 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	dynamic_cast<OperationSet*>((yysemantic_stack_[(2) - (1)].p_Operation))->push_back((yysemantic_stack_[(2) - (2)].p_Operation));
	(yyval.p_Operation) = (yysemantic_stack_[(2) - (1)].p_Operation);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 937 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(2) - (1)].p_Operation);
}
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 961 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 964 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert((yysemantic_stack_[(4) - (3)].p_TableOperation), (yysemantic_stack_[(4) - (4)].p_WhereClause));
      }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 970 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 973 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(4) - (3)].p_TableOperation), (yysemantic_stack_[(4) - (4)].p_WhereClause));
      }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 979 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(2) - (2)].p_URI));
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 985 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 992 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(3) - (2)].p_URIs), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 999 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URIs) = new ProductionVector<const URI*>((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1002 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_URIs)->push_back((yysemantic_stack_[(2) - (2)].p_URI));
	(yyval.p_URIs) = (yysemantic_stack_[(2) - (1)].p_URIs);
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1010 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1017 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1024 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1030 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1033 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1039 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1045 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1052 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1055 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1105 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1108 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
      }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1115 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curFilter = NULL;
      }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1118 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_POS);
      }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1121 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(5) - (3)].p_POS), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(5) - (4)].p_POS);
      }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 1164 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 1166 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.curFilter;
      }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 1168 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 185:

/* Line 678 of lalr1.cc  */
#line 1180 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 1182 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 1184 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_POS);
      }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 1187 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_POS), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_POS);
      }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 1195 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 1197 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 1199 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(5) - (4)].p_POS), driver.curOp, driver.posFactory, false));
      }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 1206 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 1208 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 1210 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.curOp));
      }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1218 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1221 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1223 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1231 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 1236 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 1251 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    if (driver.curOp == NULL)
		driver.ensureBasicGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 1268 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 1276 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 1280 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 1282 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = NULL;
      }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 1289 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 1292 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 1299 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 1307 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 1314 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_DistExprPair).distinctness = (yysemantic_stack_[(4) - (2)].p_distinctness);
	  (yyval.p_DistExprPair).p_Expression = (yysemantic_stack_[(4) - (3)].p_Expression);
    }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 1325 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 1328 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 1330 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 1338 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 1340 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 1368 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 1371 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 1431 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.posFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_POS)));
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 1438 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_POS);
	driver.curPredicate = (yyval.p_POS);
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 1442 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_POS);
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 1454 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 1458 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_POS) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 1467 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 254:

/* Line 678 of lalr1.cc  */
#line 1492 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 1495 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 1498 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 1501 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 1504 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 1511 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 1519 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POSs) = new ProductionVector<const POS*>();
	(yyval.p_POSs)->push_back((yysemantic_stack_[(1) - (1)].p_POS));
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 1523 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSs)->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = (yysemantic_stack_[(2) - (1)].p_POSs);
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 1535 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 1542 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 1545 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 1556 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 1559 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 1562 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 1565 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 1569 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 1580 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 1589 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 1596 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 1599 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 1607 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 1616 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 1623 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 1626 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 1638 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_GeneralComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_GeneralComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_GeneralComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 1649 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 1652 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 1655 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 1658 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 1661 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 1664 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 1667 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 1670 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 1677 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 1689 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 1698 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 1701 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 1708 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 1711 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 1718 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 1726 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 1729 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 1733 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_Expression) == NULL)
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
	else {
	    ProductionVector<const Expression*>* v = new ProductionVector<const Expression*>();
	    v->push_back((yysemantic_stack_[(2) - (1)].p_Expression));
	    v->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	    (yyval.p_Expression) = new BooleanConjunction(v);
	}
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 1747 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 1750 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 1758 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 1767 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 1770 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 1777 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 1780 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 1783 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 1793 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 1796 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 1799 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 1802 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 1809 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 1815 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-str"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 1818 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-lang"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 1821 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-langMatches"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 1824 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-datatype"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 1827 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-bound"), new POSExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 1830 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-iri"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 1833 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-iri"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 1837 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-bnode"), (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 1840 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-coalesce"), $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 1844 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-if"), (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 1847 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-strlang"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 1850 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-strdt"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 1853 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sameTerm"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 1856 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 1859 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 1862 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isBlank"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 1865 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isLiteral"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 1876 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 1879 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 1886 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-regex"), (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 1893 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 1900 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-exists"), driver.curOp, NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 1907 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-exists"), driver.curOp, NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 1914 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-count"), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 1917 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sum"), (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 1920 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-min"), (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 1923 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-max"), (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 1926 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-avg"), (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 1929 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sample"), (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 1933 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 1935 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  // x = new ArgList($2, driver.curExprList);
	  delete driver.curExprList;
	  driver.curExprList = NULL;
	  w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // $$ = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-group-concat"), $3, $4.p_Expression, $4.separator));
    }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 1945 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 1952 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 1958 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 1965 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new POSExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 1975 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 1983 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 1991 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 1998 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 2002 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 2010 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 2835 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -436;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        33,   -86,    62,   342,  -436,  -436,  -436,  -436,    36,    36,
     118,    71,    78,    78,    41,    47,    11,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,   292,  -436,    19,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,    80,  -436,  -436,  -436,
    -436,  -436,  -436,     8,  -436,  -436,   118,  -436,  -436,  -436,
     118,   118,  -436,  -436,  -436,   742,  -436,  -436,  -436,  -436,
    -436,    56,  -436,  -436,  -436,  -436,    23,    23,  -436,  -436,
    -436,  -436,  -436,   858,    14,    14,    71,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  1063,    59,    63,   -17,   -13,    76,
      88,   100,   106,   106,   138,   145,   149,   151,   177,   179,
     204,   213,   215,   216,   217,   224,   230,   230,   230,   230,
     232,   230,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  1140,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,   -55,    -5,   858,    23,  -436,    21,
      -2,  -436,  -436,  -436,   106,    58,    38,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,   235,  -436,
    -436,  -436,  -436,   239,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  1063,  1217,  1217,  1217,
    -436,   191,  -436,  -436,  -436,  -436,   108,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,    -5,  1063,
    1063,  1063,  -436,  -436,  1063,  -436,  -436,  -436,  1063,  1063,
    1063,  -436,  -436,  -436,  1063,  1063,  1063,  1063,    13,  1063,
    1063,  1063,  1063,  1063,  1063,   266,   266,  -436,  -436,  -436,
    -436,   266,  -436,  -436,   118,  -436,  -436,  -436,  -436,   266,
    -436,  -436,   247,  -436,   246,    58,    58,   118,  -436,  -436,
    -436,  -436,  -436,   261,   269,  -436,   223,  -436,  -436,    68,
     258,   858,  -436,  -436,    68,   982,    68,   265,  -436,  -436,
    -436,    13,  -436,   274,   263,   264,  1063,  1063,  1063,  1063,
    1063,  1063,   -13,   -13,  -436,  -436,   132,     6,  -436,  -436,
     278,   279,   281,  -436,   275,   277,   282,   542,   290,   294,
     285,   296,   297,   293,   301,   303,   307,   308,   309,  -436,
     644,  1063,  1063,  -436,  1063,  -436,   858,  -436,  -436,  -436,
    -436,  -436,    13,  -436,  -436,  -436,   551,  1294,   327,  -436,
     242,  -436,   312,   982,  -436,  -436,   317,   355,  -436,  -436,
    -436,  -436,  -436,  -436,   890,  -436,  -436,  -436,  -436,  -436,
    -436,  1063,  -436,  1063,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  1063,  1063,     6,  -436,  -436,  -436,  1063,
    1063,  -436,  -436,  -436,  -436,  -436,  1063,  1063,  1063,  -436,
    -436,   329,  -436,  -436,  -436,  -436,  1063,  -436,  -436,  1063,
    -436,  -436,  -436,  -436,  1063,  -436,  -436,   326,   328,  -436,
    -436,  -436,   -12,  -436,  1063,   551,  -436,  -436,  -436,  -436,
    1294,  -436,  -436,  -436,  -436,  -436,   343,   152,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,   858,    56,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,     3,   323,   332,
     333,  -436,  -436,   214,   334,   336,   330,  -436,  -436,  -436,
    -436,  -436,  -436,   191,  -436,  -436,   833,   280,   283,  -436,
    -436,   350,   357,   337,   335,  -436,  -436,  -436,  1063,  -436,
    1063,  -436,  -436,   349,  -436,  -436,  -436,  -436,  1294,   317,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,   348,   112,    26,  -436,   358,  -436,  -436,   833,
    -436,   360,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,    68,  -436,   982,  -436,    36,  -436,   361,    58,
    -436,  -436,  -436,  -436,  -436,   858,   106,  -436,   314,  -436,
     363,  -436,    54,  -436,  -436,  -436,  -436,  -436,   982,  -436,
    -436,  -436,  -436,    56,    56,   106,   106,  -436,  -436,   346,
    -436,  -436,  -436,  -436,  -436,  -436,   106,  -436,  -436,   352,
     113,    96,   106,  -436,  -436,  -436,  -436,  -436,   940,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,   106,  -436,  -436,  -436
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        10,     0,     0,     0,    12,    11,    14,     1,     0,     0,
       0,   138,   147,   147,    27,     0,     0,    19,     2,     3,
       5,    19,     6,     7,     8,     4,   120,   121,   129,   124,
     131,   132,   126,   125,   127,   128,     9,   165,   135,   133,
     394,   397,   396,   144,   141,   395,     0,   137,   139,   148,
       0,     0,    25,    26,    28,     0,   220,    19,    50,   269,
     270,    49,    19,    47,   267,   268,    61,    61,   122,   130,
     123,    15,    13,   156,    51,    51,     0,   145,   140,   142,
     150,   149,   146,    44,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   388,   389,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   390,   392,   391,   393,    40,    41,    43,
      24,    36,    33,    35,   344,   345,   346,    34,    37,    38,
     376,   377,   378,    39,   374,     0,   222,    61,    48,    51,
       0,    62,    20,    53,     0,    64,     0,   254,   255,   256,
     257,   258,   251,   398,   399,   276,   171,   157,   175,   230,
     250,   249,   260,     0,   228,   265,   266,   272,   273,   274,
     271,   275,   136,    52,   134,   143,     0,     0,     0,     0,
     324,    30,   277,   280,   284,   286,   296,   298,   309,   312,
     317,   318,   319,   325,   320,   321,   322,   323,   368,     0,
       0,     0,   348,   334,     0,   217,   335,   216,     0,     0,
       0,   151,   352,   353,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   210,   210,   355,   356,   357,
     358,   210,   359,    42,     0,   372,   373,   375,   370,   210,
     207,   206,     0,   223,   226,    64,    64,     0,    54,    55,
      56,    57,    59,   112,     0,    18,    66,    65,    16,     0,
     167,   156,   176,   173,   240,   259,     0,     0,   315,   316,
     314,     0,    31,     0,   278,   282,     0,     0,     0,     0,
       0,     0,     0,     0,   297,   287,   299,   311,   369,   367,
       0,     0,     0,   218,     0,     0,     0,   156,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   211,
       0,     0,     0,   371,     0,   221,   222,   227,   224,    45,
      46,    58,     0,    60,   113,   101,     0,     0,    68,    67,
       0,   248,     0,   259,   247,   166,   160,     0,   172,   174,
     241,   231,   239,   264,   259,   261,   263,   229,   326,    29,
      32,     0,   281,     0,   285,   288,   289,   290,   291,   292,
     293,   294,   295,     0,     0,   304,   310,   300,   301,     0,
       0,   313,   332,   333,   347,   213,     0,     0,     0,   153,
      21,     0,   154,   163,   327,   328,     0,   330,   331,     0,
     340,   341,   342,   343,     0,   362,   363,     0,     0,   360,
     208,   225,     0,   102,     0,    72,    73,    76,    78,    75,
      79,    80,    82,   205,   203,   204,     0,    70,    69,    17,
     252,   237,   244,   246,   161,   156,     0,   253,   262,   279,
     283,   306,   307,   305,   308,   302,   303,     0,     0,     0,
       0,    22,   152,   155,     0,     0,   350,   354,   215,   213,
     213,   110,   103,    30,    74,    81,     0,     0,     0,    63,
      71,    95,    97,   232,   242,   170,   168,   219,     0,   214,
       0,   337,   338,    61,   185,   189,   182,   192,     0,   160,
     164,   158,   177,   180,   181,   178,   179,   196,   159,   329,
     339,   351,     0,   365,     0,   108,     0,    88,    89,    83,
      84,     0,    86,    87,    91,    92,    99,   100,    93,    96,
      94,    98,   234,   238,   259,   245,     0,   212,     0,    64,
     186,   190,   183,   193,   202,   156,     0,   349,     0,   366,
       0,   209,     0,    77,    85,    90,   235,   236,   259,   243,
     169,   336,    23,     0,     0,     0,     0,   162,   200,     0,
     361,   111,   106,   109,   233,   187,     0,   184,   194,   197,
       0,     0,     0,   191,   198,   201,   364,   118,     0,   104,
     119,   115,   116,   117,   114,   188,     0,   107,   105,   199
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,    34,  -436,  -436,  -436,    99,  -436,  -436,  -436,
     -56,  -436,   284,  -436,  -436,  -436,  -436,  -436,  -436,   -50,
    -436,  -436,  -436,  -436,  -436,   155,   -59,  -436,  -242,  -436,
    -436,  -436,  -436,  -436,  -436,    -7,  -436,  -436,   -11,  -436,
    -436,   -93,  -436,  -436,  -436,  -436,  -436,  -436,   -53,   -48,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -161,
    -436,  -436,   392,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,   407,  -436,   345,
     -84,  -436,  -436,  -436,  -259,  -436,   -62,  -436,  -436,    -6,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -435,   -44,   220,  -436,  -172,   -27,  -247,   -28,   -64,  -436,
    -436,  -436,  -436,   104,  -436,  -436,  -436,  -141,  -436,  -436,
    -156,  -436,  -436,  -436,  -436,  -436,  -436,  -117,  -436,  -436,
     -92,   -89,  -257,  -436,  -436,  -436,  -436,  -436,  -436,  -245,
    -240,   -14,    -1,  -436,   -76,  -436,  -436,  -436,    75,  -436,
    -436,    77,  -436,  -436,  -436,   105,  -436,  -436,    64,  -436,
    -436,  -436,  -132,  -436,  -129,  -150,  -320,   -51,  -436,  -436,
    -436,  -436,  -436,   -34,  -436,  -436,  -436,  -436,  -436,  -436,
     -54,  -436,  -436,  -436,   -45,  -436,   142,   146,    32,  -127,
     -10,  -436,  -436
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,    18,    19,     3,     4,    36,     5,    72,   156,
     340,    20,    66,   389,   451,   483,    21,    54,    55,   282,
     283,   127,   128,   129,   130,    22,    23,    61,    62,   182,
      24,   152,   258,   259,   260,   261,   183,   154,   265,   266,
     338,   427,   469,   267,   415,   416,   339,   420,   421,   428,
     509,   510,   511,   512,   513,   470,   518,   520,   471,   472,
     333,   412,   578,   563,   571,   542,   334,   505,   335,   579,
      25,    26,    27,    28,    70,    29,    30,    75,    31,    74,
      32,    47,    33,    43,    77,    78,    34,    50,    35,    48,
     222,   307,   391,   392,   166,   489,   435,   490,   453,    38,
      73,   346,   347,   526,   348,   270,   167,   272,   273,   491,
     492,   532,   555,   493,   530,   553,   572,   494,   531,   554,
     495,   533,   556,   496,   497,   536,   575,   586,   569,   498,
     422,   423,   251,   460,   320,   479,   447,   237,   216,   217,
     385,    57,   146,   252,   253,   327,   328,   168,   276,   274,
     342,   546,   547,   523,   473,   351,   352,   431,   525,   474,
     432,   343,   169,   170,   269,   171,   172,   173,   354,   433,
     174,   344,   190,   176,   191,   192,   362,   284,   193,   364,
     285,   194,   195,   294,   295,   196,   197,   375,   381,   444,
     376,   296,   198,   297,   199,   200,   201,   202,   213,   134,
     502,   135,   136,   203,   459,   407,   539,   540,   204,   299,
     205,   246,   247,   248,   206,   140,   141,   142,   207,   144,
     208,    45,   181
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SPARQLfedParser::yytable_ninf_ = -260;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        44,   138,    63,    39,   133,   254,    65,   153,   155,   223,
     139,   131,   349,   329,   330,    64,    76,   424,   353,   177,
     257,   137,   211,   461,   379,   184,   214,     6,   178,    58,
     355,   514,   244,    79,   249,   356,    80,   278,   279,   280,
      81,    82,   150,   477,   150,   145,     1,   148,   393,   -61,
     478,    65,   151,   534,   132,    67,   -61,    52,    53,   151,
      64,   151,     7,   180,   321,   245,   541,    69,   380,   322,
     263,    37,   175,   478,   514,   138,    46,   324,   133,   238,
     239,   240,    56,   242,   139,   131,   353,   143,   255,    49,
     561,   147,   177,   562,    71,   137,   149,   353,   209,   256,
     424,   178,   210,   356,   212,   179,    59,    60,   215,   438,
     277,    40,    41,    42,   356,   218,   250,   341,   350,   145,
     357,    40,    41,    42,    40,    41,    42,   219,   132,    59,
      60,    59,    60,   300,   301,   302,   180,   577,   303,   220,
     262,   221,   304,   305,   306,   175,   424,   264,   308,   309,
     310,   311,   268,   313,   314,   315,   316,   317,   318,   478,
     538,   143,   286,   287,   288,   289,   290,   291,   424,    40,
      41,    42,   292,   293,    59,    60,   475,   224,   179,   467,
     468,    40,    41,    42,   225,   254,    59,    60,   226,   424,
     227,   545,   373,   374,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    40,
      41,    42,   503,   504,    59,    60,   228,   177,   229,   484,
     485,   177,   123,   124,   125,   126,   178,   312,   371,   372,
     178,    40,    41,    42,   323,   117,   118,   119,   120,   121,
     122,   441,   442,   230,   406,   408,   409,   262,   410,  -195,
     445,   446,   231,   177,   232,   233,   234,   486,   487,    65,
     488,   180,   178,   235,    65,   180,    65,   353,    64,   236,
     175,   241,   177,    64,   175,    64,   557,   271,   275,   281,
     359,   178,   319,   325,   356,   419,   425,   552,   326,   177,
     332,   353,   417,   336,   345,     8,     9,   180,   178,    10,
     177,    11,    12,   179,    13,   358,   175,   179,   356,   178,
     448,   449,   450,   337,   360,   361,   180,   363,   382,   383,
     454,   384,   386,   455,   387,   175,   145,   145,   456,   388,
     394,   413,   396,   180,   395,   418,   397,   398,   463,   179,
     399,   400,   175,   401,   180,     8,     9,   402,   403,    10,
     426,    11,    12,   175,    13,   429,   404,    14,   179,   434,
     436,    15,    16,   430,   419,   452,   457,   466,   458,   425,
     480,   417,   481,   482,   499,   179,   500,   478,   468,    17,
     516,   177,   524,   517,   467,   522,   179,   151,   537,   559,
     178,   365,   366,   367,   368,   369,   370,   574,   543,   186,
     570,   551,   527,   560,   528,   145,   390,   506,   464,   465,
     145,   462,   331,   243,   418,   425,   544,   588,    68,   521,
      51,   185,   476,   519,   529,   180,    65,   535,   298,   501,
     411,   564,   549,   548,   175,    64,   439,   425,   377,   443,
     440,     0,   378,   576,     0,     0,     0,     0,     0,     0,
       0,     0,   558,     0,     0,     0,   145,     0,   425,     0,
       0,     0,     0,     0,     0,   515,     0,   179,     0,     0,
     177,   567,   568,     0,     0,     0,     0,     0,   145,   178,
       0,   177,   573,     0,     0,     0,     0,     0,   585,     0,
     178,     0,     0,     0,   177,     0,     0,     0,     0,   145,
       0,     0,   589,   178,     0,     0,     0,     0,   515,     0,
       0,     0,    65,     0,   180,     0,     0,   581,     0,     0,
     550,    64,     0,   175,   581,   180,   582,     0,     0,     0,
       0,     0,     0,   582,   175,     0,     0,     0,   180,   565,
     566,     0,     0,    65,    65,     0,     0,   175,     0,     0,
       0,     0,    64,    64,     0,     0,   179,    14,     0,     0,
       0,   584,     0,     0,     0,     0,     0,   179,   584,     0,
     580,     0,   157,   158,   159,   160,   161,   580,     0,     0,
     179,  -259,     0,     0,     0,     0,     0,     0,     0,     0,
     414,     0,   162,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   583,     0,     0,     0,     0,     0,     0,
     583,     0,     0,     0,     0,     0,     0,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     0,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    40,    41,    42,   163,   164,
      59,    60,   405,   165,    40,    41,    42,     0,     0,    59,
      60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   186,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   187,   188,     0,   189,     0,     0,
      85,    86,    87,    88,    89,    90,    91,    92,    93,     0,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,     0,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    40,    41,    42,
      83,     0,    59,    60,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,    86,
      87,    88,    89,    90,    91,    92,    93,     0,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,     0,
       0,     0,     0,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    40,    41,    42,   507,   508,
      59,    60,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   186,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   157,   158,
     159,   160,   161,     0,     0,     0,     0,  -259,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,   162,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     157,   158,   159,   160,   161,     0,     0,     0,     0,     0,
     437,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     162,     0,     0,     0,     0,     0,    40,    41,    42,     0,
       0,    59,    60,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    40,    41,    42,   163,   164,    59,    60,     0,   165,
     587,   577,     0,     0,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    40,    41,    42,   163,   164,    59,    60,
       0,   165,   157,   158,   159,   160,   161,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   162,     0,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    40,    41,    42,     0,     0,    59,    60,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,    40,    41,    42,   163,   164,
      59,    60,   186,   165,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   187,   188,     0,   189,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
       0,     0,     0,     0,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    40,    41,    42,    84,
       0,    59,    60,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,    90,    91,    92,    93,     0,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,     0,     0,     0,
       0,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    40,    41,    42,   186,     0,    59,    60,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    85,    86,    87,    88,    89,    90,    91,
      92,    93,     0,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,     0,     0,     0,     0,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
      40,    41,    42,   186,     0,    59,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,    86,    87,    88,    89,    90,    91,    92,    93,     0,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    40,    41,    42
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        10,    55,    16,     9,    55,   146,    16,    66,    67,    93,
      55,    55,   271,   255,   256,    16,     8,   337,   275,    73,
      22,    55,    39,    35,    18,    75,    39,   113,    73,    18,
     275,   466,    87,    43,    39,   275,    46,   187,   188,   189,
      50,    51,    21,    40,    21,    55,    13,    61,   307,    35,
      47,    61,    38,   488,    55,    21,    35,    16,    17,    38,
      61,    38,     0,    73,   236,   120,    40,    48,    62,   241,
     154,    35,    73,    47,   509,   129,     5,   249,   129,   107,
     108,   109,    35,   111,   129,   129,   343,    55,   147,    11,
      36,    57,   146,    39,    14,   129,    62,   354,    39,   149,
     420,   146,    39,   343,   121,    73,   118,   119,   121,   354,
     186,   113,   114,   115,   354,    39,   121,    49,   274,   129,
     276,   113,   114,   115,   113,   114,   115,    39,   129,   118,
     119,   118,   119,   209,   210,   211,   146,    41,   214,    39,
     150,    35,   218,   219,   220,   146,   466,    89,   224,   225,
     226,   227,   114,   229,   230,   231,   232,   233,   234,    47,
      48,   129,    54,    55,    56,    57,    58,    59,   488,   113,
     114,   115,    64,    65,   118,   119,   435,    39,   146,    27,
      28,   113,   114,   115,    39,   326,   118,   119,    39,   509,
      39,   511,    60,    61,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   459,   460,   118,   119,    39,   271,    39,     5,
       6,   275,   109,   110,   111,   112,   271,   228,   292,   293,
     275,   113,   114,   115,   244,   103,   104,   105,   106,   107,
     108,   373,   374,    39,   320,   321,   322,   257,   324,    35,
     379,   380,    39,   307,    39,    39,    39,    43,    44,   269,
      46,   271,   307,    39,   274,   275,   276,   524,   269,    39,
     271,    39,   326,   274,   275,   276,   535,    42,    39,    88,
     281,   326,    16,    36,   524,   336,   337,   529,    42,   343,
      29,   548,   336,    24,    36,     3,     4,   307,   343,     7,
     354,     9,    10,   271,    12,    40,   307,   275,   548,   354,
     386,   387,   388,    90,    40,    52,   326,    53,    40,    40,
     396,    40,    47,   399,    47,   326,   336,   337,   404,    47,
      40,   332,    47,   343,    40,   336,    40,    40,   414,   307,
      47,    40,   343,    40,   354,     3,     4,    40,    40,     7,
      23,     9,    10,   354,    12,   113,    47,    15,   326,    42,
       5,    19,    20,    51,   415,    36,    40,    24,    40,   420,
      47,   415,    40,    40,    40,   343,    40,    47,    28,    37,
     100,   435,    47,   100,    27,    48,   354,    38,    40,    75,
     435,   286,   287,   288,   289,   290,   291,    45,    40,    39,
      54,    40,   478,    40,   480,   415,   307,   463,   415,   420,
     420,   412,   257,   129,   415,   466,   509,   578,    26,   472,
      13,    76,   436,   471,   483,   435,   436,   489,   208,   456,
     326,   548,   524,   522,   435,   436,   361,   488,   296,   375,
     363,    -1,   296,   570,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   536,    -1,    -1,    -1,   466,    -1,   509,    -1,
      -1,    -1,    -1,    -1,    -1,   466,    -1,   435,    -1,    -1,
     524,   555,   556,    -1,    -1,    -1,    -1,    -1,   488,   524,
      -1,   535,   566,    -1,    -1,    -1,    -1,    -1,   572,    -1,
     535,    -1,    -1,    -1,   548,    -1,    -1,    -1,    -1,   509,
      -1,    -1,   586,   548,    -1,    -1,    -1,    -1,   509,    -1,
      -1,    -1,   522,    -1,   524,    -1,    -1,   571,    -1,    -1,
     526,   522,    -1,   524,   578,   535,   571,    -1,    -1,    -1,
      -1,    -1,    -1,   578,   535,    -1,    -1,    -1,   548,   553,
     554,    -1,    -1,   553,   554,    -1,    -1,   548,    -1,    -1,
      -1,    -1,   553,   554,    -1,    -1,   524,    15,    -1,    -1,
      -1,   571,    -1,    -1,    -1,    -1,    -1,   535,   578,    -1,
     571,    -1,    30,    31,    32,    33,    34,   578,    -1,    -1,
     548,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   571,    -1,    -1,    -1,    -1,    -1,    -1,
     578,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    18,   121,   113,   114,   115,    -1,    -1,   118,
     119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    61,    -1,    63,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      18,    -1,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      -1,    -1,    -1,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    25,    26,
     118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    39,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    50,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,    -1,
      -1,   118,   119,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,   121,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,   121,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,    -1,   118,   119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    39,   121,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    61,    -1,    63,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,    39,
      -1,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    -1,    -1,    -1,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    39,    -1,   118,   119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    -1,    -1,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,    39,    -1,   118,   119,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,   115
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    13,   123,   126,   127,   129,   113,     0,     3,     4,
       7,     9,    10,    12,    15,    19,    20,    37,   124,   125,
     133,   138,   147,   148,   152,   192,   193,   194,   195,   197,
     198,   200,   202,   204,   208,   210,   128,    35,   221,   221,
     113,   114,   115,   205,   342,   343,     5,   203,   211,    11,
     209,   209,    16,    17,   139,   140,    35,   263,    18,   118,
     119,   149,   150,   293,   294,   342,   134,   134,   194,    48,
     196,    14,   130,   222,   201,   199,     8,   206,   207,   342,
     342,   342,   342,    18,    39,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   143,   144,   145,
     146,   253,   294,   319,   321,   323,   324,   325,   332,   336,
     337,   338,   339,   340,   341,   342,   264,   134,   293,   134,
      21,    38,   153,   158,   159,   158,   131,    30,    31,    32,
      33,    34,    50,   116,   117,   121,   216,   228,   269,   284,
     285,   287,   288,   289,   292,   294,   295,   332,   336,   340,
     342,   344,   151,   158,   151,   211,    39,    60,    61,    63,
     294,   296,   297,   300,   303,   304,   307,   308,   314,   316,
     317,   318,   319,   325,   330,   332,   336,   340,   342,    39,
      39,    39,   121,   320,    39,   121,   260,   261,    39,    39,
      39,    35,   212,   212,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,   259,   259,   259,
     259,    39,   259,   144,    87,   120,   333,   334,   335,    39,
     121,   254,   265,   266,   269,   158,   151,    22,   154,   155,
     156,   157,   342,   212,    89,   160,   161,   165,   114,   286,
     227,    42,   229,   230,   271,    39,   270,   296,   317,   317,
     317,    88,   141,   142,   299,   302,    54,    55,    56,    57,
      58,    59,    64,    65,   305,   306,   313,   315,   254,   331,
     296,   296,   296,   296,   296,   296,   296,   213,   296,   296,
     296,   296,   294,   296,   296,   296,   296,   296,   296,    16,
     256,   256,   256,   342,   256,    36,    42,   267,   268,   160,
     160,   157,    29,   182,   188,   190,    24,    90,   162,   168,
     132,    49,   272,   283,   293,    36,   223,   224,   226,   216,
     272,   277,   278,   284,   290,   291,   292,   272,    40,   294,
      40,    52,   298,    53,   301,   307,   307,   307,   307,   307,
     307,   260,   260,    60,    61,   309,   312,   338,   339,    18,
      62,   310,    40,    40,    40,   262,    47,    47,    47,   135,
     138,   214,   215,   216,    40,    40,    47,    40,    40,    47,
      40,    40,    40,    40,    47,    18,   296,   327,   296,   296,
     296,   265,   183,   294,    39,   166,   167,   253,   294,   319,
     169,   170,   252,   253,   318,   319,    23,   163,   171,   113,
      51,   279,   282,   291,    42,   218,     5,    40,   291,   300,
     303,   314,   314,   310,   311,   316,   316,   258,   296,   296,
     296,   136,    36,   220,   296,   296,   296,    40,    40,   326,
     255,    35,   294,   296,   167,   170,    24,    27,    28,   164,
     177,   180,   181,   276,   281,   216,   293,    40,    47,   257,
      47,    40,    40,   137,     5,     6,    43,    44,    46,   217,
     219,   231,   232,   235,   239,   242,   245,   246,   251,    40,
      40,   257,   322,   258,   258,   189,   142,    25,    26,   172,
     173,   174,   175,   176,   252,   294,   100,   100,   178,   181,
     179,   180,    48,   275,    47,   280,   225,   296,   296,   158,
     236,   240,   233,   243,   252,   218,   247,    40,    48,   328,
     329,    40,   187,    40,   173,   318,   273,   274,   283,   282,
     221,    40,   160,   237,   241,   234,   244,   216,   212,    75,
      40,    36,    39,   185,   279,   293,   293,   212,   212,   250,
      54,   186,   238,   212,    45,   248,   341,    41,   184,   191,
     294,   332,   336,   340,   342,   212,   249,    40,   191,   212
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
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  SPARQLfedParser::yyr1_[] =
  {
         0,   122,   123,   124,   124,   125,   125,   125,   125,   126,
     127,   127,   128,   128,   129,   131,   132,   130,   133,   134,
     134,   136,   137,   135,   138,   139,   139,   140,   140,   141,
     142,   142,   143,   144,   144,   144,   144,   144,   144,   144,
     144,   145,   145,   146,   146,   147,   148,   149,   149,   150,
     150,   151,   151,   152,   153,   154,   154,   155,   156,   157,
     158,   159,   159,   160,   161,   161,   162,   162,   163,   163,
     164,   164,   165,   166,   166,   167,   167,   167,   167,   168,
     169,   169,   170,   171,   172,   172,   173,   173,   174,   174,
     175,   176,   176,   177,   177,   178,   178,   179,   179,   180,
     181,   182,   183,   183,   184,   184,   186,   185,   187,   187,
     189,   188,   190,   190,   191,   191,   191,   191,   191,   191,
     192,   193,   193,   194,   195,   195,   195,   195,   195,   196,
     196,   197,   197,   199,   198,   201,   200,   202,   203,   203,
     204,   205,   205,   206,   207,   207,   208,   209,   209,   210,
     211,   213,   212,   214,   214,   215,   216,   216,   217,   217,
     218,   218,   219,   220,   220,   222,   221,   224,   225,   223,
     226,   227,   227,   228,   229,   230,   230,   231,   231,   231,
     231,   231,   233,   234,   232,   236,   237,   238,   235,   240,
     241,   239,   243,   244,   242,   246,   247,   245,   249,   248,
     250,   250,   251,   252,   252,   252,   253,   254,   255,   254,
     256,   256,   257,   258,   258,   259,   260,   261,   262,   261,
     264,   263,   265,   265,   266,   267,   268,   268,   270,   269,
     271,   269,   272,   273,   274,   274,   275,   276,   276,   277,
     278,   278,   279,   280,   281,   281,   282,   283,   283,   284,
     284,   286,   285,   287,   288,   288,   288,   288,   288,   289,
     289,   290,   290,   291,   291,   292,   292,   293,   293,   294,
     294,   295,   295,   295,   295,   295,   295,   296,   297,   298,
     299,   299,   300,   301,   302,   302,   303,   304,   305,   305,
     305,   305,   305,   305,   305,   305,   306,   306,   307,   308,
     309,   309,   310,   310,   311,   311,   312,   312,   312,   313,
     313,   314,   315,   315,   316,   316,   316,   316,   317,   317,
     317,   317,   317,   317,   317,   317,   318,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   320,   320,   321,
     322,   322,   323,   324,   325,   325,   325,   325,   325,   325,
     326,   325,   327,   327,   328,   329,   329,   330,   331,   331,
     332,   333,   334,   334,   335,   335,   336,   336,   336,   337,
     337,   337,   338,   338,   338,   339,   339,   339,   340,   340,
     341,   341,   341,   341,   342,   342,   343,   343,   344,   344
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SPARQLfedParser::yyr2_[] =
  {
         0,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       0,     1,     0,     2,     2,     0,     0,     5,     4,     0,
       2,     0,     0,     5,     3,     1,     1,     0,     1,     2,
       0,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     5,     5,     1,     2,     1,
       1,     0,     1,     3,     2,     1,     1,     1,     2,     1,
       3,     0,     1,     4,     0,     1,     0,     1,     0,     1,
       0,     1,     3,     1,     2,     1,     1,     4,     1,     2,
       1,     2,     1,     3,     1,     2,     1,     1,     1,     1,
       2,     1,     1,     2,     2,     0,     1,     0,     1,     2,
       2,     1,     1,     2,     1,     2,     0,     4,     0,     2,
       0,     6,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     0,
       1,     1,     1,     0,     4,     0,     4,     2,     0,     1,
       3,     1,     2,     2,     0,     1,     3,     0,     1,     3,
       2,     0,     4,     1,     1,     2,     0,     1,     1,     1,
       0,     1,     3,     0,     2,     0,     5,     0,     0,     5,
       3,     0,     2,     2,     2,     0,     1,     1,     1,     1,
       1,     1,     0,     0,     4,     0,     0,     0,     6,     0,
       0,     5,     0,     0,     4,     0,     0,     4,     0,     3,
       0,     2,     2,     1,     1,     1,     2,     1,     0,     6,
       0,     1,     2,     0,     2,     4,     1,     1,     0,     5,
       0,     4,     0,     1,     2,     2,     0,     1,     0,     3,
       0,     3,     3,     2,     0,     1,     2,     0,     2,     1,
       0,     1,     2,     2,     0,     2,     1,     1,     1,     1,
       1,     0,     4,     4,     1,     1,     1,     1,     1,     0,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       0,     2,     2,     2,     0,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     0,     1,     1,     2,
       1,     1,     2,     2,     0,     1,     2,     2,     2,     0,
       2,     2,     0,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     4,     4,     6,
       4,     4,     4,     4,     2,     2,     8,     6,     6,     6,
       4,     4,     4,     4,     1,     1,     1,     3,     1,     7,
       0,     1,     2,     2,     5,     2,     2,     2,     2,     2,
       0,     8,     1,     1,     4,     0,     1,     2,     0,     1,
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
    "\"end of file\"", "error", "$undefined", "IT_DELETE", "IT_INSERT",
  "IT_GRAPH", "IT_SERVICE", "IT_LOAD", "IT_INTO", "IT_CLEAR", "IT_CREATE",
  "IT_SILENT", "IT_DROP", "IT_BASE", "IT_PREFIX", "IT_SELECT",
  "IT_DISTINCT", "IT_REDUCED", "GT_TIMES", "IT_CONSTRUCT", "IT_DESCRIBE",
  "IT_FROM", "IT_NAMED", "IT_ORDER", "IT_BY", "IT_ASC", "IT_DESC",
  "IT_LIMIT", "IT_OFFSET", "IT_BINDINGS", "IT_MEMBERS", "IT_STARTS",
  "IT_ENDS", "IT_ANY", "IT_UNORDERED", "GT_LCURLEY", "GT_RCURLEY",
  "IT_ASK", "IT_WHERE", "GT_LPAREN", "GT_RPAREN", "IT_UNDEF", "GT_DOT",
  "IT_OPTIONAL", "IT_MINUS", "IT_UNION", "IT_FILTER", "GT_COMMA",
  "GT_SEMI", "IT_a", "GT_LBRACKET", "GT_RBRACKET", "GT_OR", "GT_AND",
  "GT_EQUAL", "GT_NEQUAL", "GT_LT", "GT_GT", "GT_LE", "GT_GE", "GT_PLUS",
  "GT_MINUS", "GT_DIVIDE", "GT_NOT", "IT_IN", "GT_NOT_SPACECHAR_IN",
  "IT_IRI", "IT_URI", "IT_BNODE", "IT_COALESCE", "IT_IF", "IT_STRLANG",
  "IT_STRDT", "IT_EXISTS", "GT_NOT_SPACECHAR_EXISTS", "IT_SEPARATOR",
  "IT_STR", "IT_LANG", "IT_LANGMATCHES", "IT_DATATYPE", "IT_BOUND",
  "IT_sameTerm", "IT_isIRI", "IT_isURI", "IT_isBLANK", "IT_isLITERAL",
  "IT_REGEX", "GT_DTYPE", "IT_AS", "IT_GROUP", "IT_HAVING", "IT_COUNT",
  "IT_SUM", "IT_MIN", "IT_MAX", "IT_AVG", "IT_GROUP_CONCAT", "IT_SAMPLE",
  "IT_true", "IT_false", "INTEGER", "DECIMAL", "DOUBLE",
  "INTEGER_POSITIVE", "DECIMAL_POSITIVE", "DOUBLE_POSITIVE",
  "INTEGER_NEGATIVE", "DECIMAL_NEGATIVE", "DOUBLE_NEGATIVE",
  "STRING_LITERAL1", "STRING_LITERAL_LONG1", "STRING_LITERAL2",
  "STRING_LITERAL_LONG2", "IRI_REF", "PNAME_NS", "PNAME_LN",
  "BLANK_NODE_LABEL", "ANON", "VAR1", "VAR2", "LANGTAG", "NIL", "$accept",
  "Top", "_O_QQuery_E_Or_QUpdate_E_C", "Query", "Prologue",
  "_QBaseDecl_E_Opt", "_QPrefixDecl_E_Star", "BaseDecl", "PrefixDecl",
  "$@1", "$@2", "SelectQuery", "_QDatasetClause_E_Star", "SubSelect", "@3",
  "@4", "SelectClause", "_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C",
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
  "WhereClause", "_QIT_WHERE_E_Opt", "SolutionModifier",
  "_QGroupClause_E_Opt", "_QHavingClause_E_Opt", "_QOrderClause_E_Opt",
  "_QLimitOffsetClauses_E_Opt", "GroupClause", "_QGroupCondition_E_Plus",
  "GroupCondition", "HavingClause", "_QHavingCondition_E_Plus",
  "HavingCondition", "OrderClause", "_QOrderCondition_E_Plus",
  "OrderCondition", "_O_QIT_ASC_E_Or_QIT_DESC_E_C",
  "_O_QIT_ASC_E_Or_QIT_DESC_E_S_QBrackettedExpression_E_C",
  "_O_QConstraint_E_Or_QVar_E_C", "LimitOffsetClauses",
  "_QOffsetClause_E_Opt", "_QLimitClause_E_Opt", "LimitClause",
  "OffsetClause", "BindingsClause", "_QVar_E_Plus",
  "_QBindingValue_E_Plus",
  "_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_C", "$@5",
  "_Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_C_E_Star",
  "_O_QIT_BINDINGS_E_S_QVar_E_Plus_S_QGT_LCURLEY_E_S_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Star_S_QGT_RCURLEY_E_C",
  "$@6",
  "_Q_O_QIT_BINDINGS_E_S_QVar_E_Plus_S_QGT_LCURLEY_E_S_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Star_S_QGT_RCURLEY_E_C_E_Opt",
  "BindingValue", "Update", "_QUpdate1_E_Plus", "Update1",
  "_O_QModify_E_Or_QLoad_E_Or_QClear_E_Or_QDrop_E_Or_QCreate_E_C",
  "_QGT_SEMI_E_Opt", "Modify", "Insert", "@7", "Delete", "@8", "Clear",
  "_QGraphRef_E_Opt", "Load", "_QIRIref_E_Plus",
  "_O_QIT_INTO_E_S_QGraphRef_E_C", "_Q_O_QIT_INTO_E_S_QGraphRef_E_C_E_Opt",
  "Drop", "_QIT_SILENT_E_Opt", "Create", "GraphRef", "GroupGraphPattern",
  "$@9", "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C",
  "GroupGraphPatternSub", "_QTriplesBlock_E_Opt",
  "_O_QGraphPatternNotTriples_E_Or_QFilter_E_C", "_QGT_DOT_E_Opt",
  "_O_QGraphPatternNotTriples_E_Or_QFilter_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_Or_QFilter_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "GraphTemplate", "$@10",
  "_O_QIT_GRAPH_E_S_QVarOrIRIref_E_S_QGraphTemplate_E_C", "@11", "@12",
  "_O_QIT_GRAPH_E_S_QVarOrIRIref_E_S_QGraphTemplate_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QIT_GRAPH_E_S_QVarOrIRIref_E_S_QGraphTemplate_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "OptionalGraphPattern", "@13", "@14", "GraphGraphPattern", "@15", "@16",
  "@17", "ServiceGraphPattern", "@18", "@19", "MinusGraphPattern", "@20",
  "@21", "GroupOrUnionGraphPattern", "@22", "@23",
  "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@24",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "$@25", "_QIT_DISTINCT_E_Opt",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ExprAggArg",
  "ExpressionList",
  "_O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C",
  "$@26", "ConstructTemplate", "$@27", "_QConstructTriples_E_Opt",
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
  "_O_QGT_EQUAL_E_S_QNumericExpression_E_Or_QGT_NEQUAL_E_S_QNumericExpression_E_Or_QGT_LT_E_S_QNumericExpression_E_Or_QGT_GT_E_S_QNumericExpression_E_Or_QGT_LE_E_S_QNumericExpression_E_Or_QGT_GE_E_S_QNumericExpression_E_Or_QIT_IN_E_S_QExpressionList_E_Or_QGT_NOT_SPACECHAR_IN_E_S_QExpressionList_E_C",
  "_Q_O_QGT_EQUAL_E_S_QNumericExpression_E_Or_QGT_NEQUAL_E_S_QNumericExpression_E_Or_QGT_LT_E_S_QNumericExpression_E_Or_QGT_GT_E_S_QNumericExpression_E_Or_QGT_LE_E_S_QNumericExpression_E_Or_QGT_GE_E_S_QNumericExpression_E_Or_QIT_IN_E_S_QExpressionList_E_Or_QGT_NOT_SPACECHAR_IN_E_S_QExpressionList_E_C_E_Opt",
  "NumericExpression", "AdditiveExpression",
  "_O_QNumericLiteralPositive_E_Or_QNumericLiteralNegative_E_C",
  "_O_QGT_TIMES_E_S_QUnaryExpression_E_Or_QGT_DIVIDE_E_S_QUnaryExpression_E_C",
  "_Q_O_QGT_TIMES_E_S_QUnaryExpression_E_Or_QGT_DIVIDE_E_S_QUnaryExpression_E_C_E_Opt",
  "_O_QGT_PLUS_E_S_QMultiplicativeExpression_E_Or_QGT_MINUS_E_S_QMultiplicativeExpression_E_Or_QNumericLiteralPositive_E_Or_QNumericLiteralNegative_E_S_QGT_TIMES_E_S_QUnaryExpression_E_Or_QGT_DIVIDE_E_S_QUnaryExpression_E_Opt_C",
  "_Q_O_QGT_PLUS_E_S_QMultiplicativeExpression_E_Or_QGT_MINUS_E_S_QMultiplicativeExpression_E_Or_QNumericLiteralPositive_E_Or_QNumericLiteralNegative_E_S_QGT_TIMES_E_S_QUnaryExpression_E_Or_QGT_DIVIDE_E_S_QUnaryExpression_E_Opt_C_E_Star",
  "MultiplicativeExpression",
  "_Q_O_QGT_TIMES_E_S_QUnaryExpression_E_Or_QGT_DIVIDE_E_S_QUnaryExpression_E_C_E_Star",
  "UnaryExpression", "PrimaryExpression", "BrackettedExpression",
  "BuiltInCall",
  "_O_QGT_LPAREN_E_S_QExpression_E_S_QGT_RPAREN_E_Or_QNIL_E_C",
  "RegexExpression", "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Opt",
  "ExistsFunc", "NotExistsFunc", "Aggregate", "$@31",
  "_O_QGT_TIMES_E_Or_QExpression_E_C",
  "_O_QGT_SEMI_E_S_QIT_SEPARATOR_E_S_QGT_EQUAL_E_S_QString_E_C",
  "_Q_O_QGT_SEMI_E_S_QIT_SEPARATOR_E_S_QGT_EQUAL_E_S_QString_E_C_E_Opt",
  "IRIrefOrFunction", "_QArgList_E_Opt", "RDFLiteral",
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
       123,     0,    -1,   126,   124,    -1,   125,    -1,   192,    -1,
     133,    -1,   147,    -1,   148,    -1,   152,    -1,   127,   128,
      -1,    -1,   129,    -1,    -1,   128,   130,    -1,    13,   113,
      -1,    -1,    -1,    14,   131,   114,   132,   113,    -1,   138,
     134,   158,   160,    -1,    -1,   134,   153,    -1,    -1,    -1,
     138,   136,   137,   158,   160,    -1,    15,   140,   146,    -1,
      16,    -1,    17,    -1,    -1,   139,    -1,    88,   294,    -1,
      -1,   141,    -1,    39,   296,   142,    40,    -1,   294,    -1,
     325,    -1,   319,    -1,   253,    -1,   332,    -1,   336,    -1,
     340,    -1,   143,    -1,   144,    -1,   145,   144,    -1,   145,
      -1,    18,    -1,    19,   263,   134,   158,   160,    -1,    20,
     150,   134,   151,   160,    -1,   293,    -1,   149,   293,    -1,
     149,    -1,    18,    -1,    -1,   158,    -1,    37,   134,   158,
      -1,    21,   154,    -1,   155,    -1,   156,    -1,   157,    -1,
      22,   157,    -1,   342,    -1,   159,   212,   182,    -1,    -1,
      38,    -1,   161,   162,   163,   164,    -1,    -1,   165,    -1,
      -1,   168,    -1,    -1,   171,    -1,    -1,   177,    -1,    89,
      24,   166,    -1,   167,    -1,   166,   167,    -1,   319,    -1,
     253,    -1,    39,   296,   142,    40,    -1,   294,    -1,    90,
     169,    -1,   170,    -1,   169,   170,    -1,   252,    -1,    23,
      24,   172,    -1,   173,    -1,   172,   173,    -1,   175,    -1,
     176,    -1,    25,    -1,    26,    -1,   174,   318,    -1,   252,
      -1,   294,    -1,   180,   178,    -1,   181,   179,    -1,    -1,
     181,    -1,    -1,   180,    -1,    27,   100,    -1,    28,   100,
      -1,   190,    -1,   294,    -1,   183,   294,    -1,   191,    -1,
     184,   191,    -1,    -1,    39,   186,   184,    40,    -1,    -1,
     187,   185,    -1,    -1,    29,   183,    35,   189,   187,    36,
      -1,    -1,   188,    -1,   342,    -1,   332,    -1,   336,    -1,
     340,    -1,    41,    -1,   294,    -1,   193,    -1,   194,    -1,
     193,   194,    -1,   195,   196,    -1,   197,    -1,   204,    -1,
     202,    -1,   208,    -1,   210,    -1,    -1,    48,    -1,   198,
      -1,   200,    -1,    -1,     4,   221,   199,   151,    -1,    -1,
       3,   221,   201,   151,    -1,     9,   203,    -1,    -1,   211,
      -1,     7,   205,   207,    -1,   342,    -1,   205,   342,    -1,
       8,   211,    -1,    -1,   206,    -1,    12,   209,   342,    -1,
      -1,    11,    -1,    10,   209,   342,    -1,     5,   342,    -1,
      -1,    35,   213,   214,    36,    -1,   135,    -1,   215,    -1,
     216,   220,    -1,    -1,   228,    -1,   231,    -1,   251,    -1,
      -1,    42,    -1,   217,   218,   216,    -1,    -1,   220,   219,
      -1,    -1,    35,   222,   216,   227,    36,    -1,    -1,    -1,
     224,     5,   293,   225,   221,    -1,   223,   218,   216,    -1,
      -1,   227,   226,    -1,   269,   230,    -1,    42,   216,    -1,
      -1,   229,    -1,   232,    -1,   242,    -1,   245,    -1,   235,
      -1,   239,    -1,    -1,    -1,    43,   233,   234,   212,    -1,
      -1,    -1,    -1,     5,   236,   237,   293,   238,   212,    -1,
      -1,    -1,     6,   240,   241,   293,   212,    -1,    -1,    -1,
      44,   243,   244,   212,    -1,    -1,    -1,   246,   247,   212,
     250,    -1,    -1,    45,   249,   212,    -1,    -1,   250,   248,
      -1,    46,   252,    -1,   318,    -1,   319,    -1,   253,    -1,
     342,   254,    -1,   121,    -1,    -1,    39,   256,   296,   255,
     258,    40,    -1,    -1,    16,    -1,    47,   296,    -1,    -1,
     258,   257,    -1,    39,   256,   296,    40,    -1,   261,    -1,
     121,    -1,    -1,    39,   296,   262,   258,    40,    -1,    -1,
      35,   264,   265,    36,    -1,    -1,   266,    -1,   269,   268,
      -1,    42,   265,    -1,    -1,   267,    -1,    -1,   292,   270,
     272,    -1,    -1,   284,   271,   277,    -1,   283,   279,   276,
      -1,   283,   279,    -1,    -1,   273,    -1,    48,   274,    -1,
      -1,   276,   275,    -1,   278,    -1,    -1,   272,    -1,   282,
     281,    -1,    47,   282,    -1,    -1,   281,   280,    -1,   291,
      -1,   293,    -1,    49,    -1,   287,    -1,   285,    -1,    -1,
      50,   286,   272,    51,    -1,   289,    39,   290,    40,    -1,
      30,    -1,    31,    -1,    32,    -1,    33,    -1,    34,    -1,
      -1,   288,    -1,   291,    -1,   290,   291,    -1,   292,    -1,
     284,    -1,   294,    -1,   295,    -1,   294,    -1,   342,    -1,
     118,    -1,   119,    -1,   342,    -1,   332,    -1,   336,    -1,
     340,    -1,   344,    -1,   121,    -1,   297,    -1,   300,   299,
      -1,    52,   300,    -1,    -1,   299,   298,    -1,   303,   302,
      -1,    53,   303,    -1,    -1,   302,   301,    -1,   304,    -1,
     307,   306,    -1,    54,   307,    -1,    55,   307,    -1,    56,
     307,    -1,    57,   307,    -1,    58,   307,    -1,    59,   307,
      -1,    64,   260,    -1,    65,   260,    -1,    -1,   305,    -1,
     308,    -1,   314,   313,    -1,   338,    -1,   339,    -1,    18,
     316,    -1,    62,   316,    -1,    -1,   310,    -1,    60,   314,
      -1,    61,   314,    -1,   309,   311,    -1,    -1,   313,   312,
      -1,   316,   315,    -1,    -1,   315,   310,    -1,    63,   317,
      -1,    60,   317,    -1,    61,   317,    -1,   317,    -1,   318,
      -1,   319,    -1,   330,    -1,   332,    -1,   336,    -1,   340,
      -1,   294,    -1,   325,    -1,    39,   296,    40,    -1,    76,
      39,   296,    40,    -1,    77,    39,   296,    40,    -1,    78,
      39,   296,    47,   296,    40,    -1,    79,    39,   296,    40,
      -1,    80,    39,   294,    40,    -1,    66,    39,   296,    40,
      -1,    67,    39,   296,    40,    -1,    68,   320,    -1,    69,
     260,    -1,    70,    39,   296,    47,   296,    47,   296,    40,
      -1,    71,    39,   296,    47,   296,    40,    -1,    72,    39,
     296,    47,   296,    40,    -1,    81,    39,   296,    47,   296,
      40,    -1,    82,    39,   296,    40,    -1,    83,    39,   296,
      40,    -1,    84,    39,   296,    40,    -1,    85,    39,   296,
      40,    -1,   321,    -1,   323,    -1,   324,    -1,    39,   296,
      40,    -1,   121,    -1,    86,    39,   296,    47,   296,   322,
      40,    -1,    -1,   257,    -1,    73,   212,    -1,    74,   212,
      -1,    91,    39,   256,   327,    40,    -1,    92,   259,    -1,
      93,   259,    -1,    94,   259,    -1,    95,   259,    -1,    97,
     259,    -1,    -1,    96,    39,   256,   296,   326,   258,   329,
      40,    -1,    18,    -1,   296,    -1,    48,    75,    54,   341,
      -1,    -1,   328,    -1,   342,   331,    -1,    -1,   254,    -1,
     341,   335,    -1,    87,   342,    -1,   120,    -1,   333,    -1,
      -1,   334,    -1,   337,    -1,   338,    -1,   339,    -1,   100,
      -1,   101,    -1,   102,    -1,   103,    -1,   104,    -1,   105,
      -1,   106,    -1,   107,    -1,   108,    -1,    98,    -1,    99,
      -1,   109,    -1,   111,    -1,   110,    -1,   112,    -1,   113,
      -1,   343,    -1,   115,    -1,   114,    -1,   116,    -1,   117,
      -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SPARQLfedParser::yyprhs_[] =
  {
         0,     0,     3,     6,     8,    10,    12,    14,    16,    18,
      21,    22,    24,    25,    28,    31,    32,    33,    39,    44,
      45,    48,    49,    50,    56,    60,    62,    64,    65,    67,
      70,    71,    73,    78,    80,    82,    84,    86,    88,    90,
      92,    94,    96,    99,   101,   103,   109,   115,   117,   120,
     122,   124,   125,   127,   131,   134,   136,   138,   140,   143,
     145,   149,   150,   152,   157,   158,   160,   161,   163,   164,
     166,   167,   169,   173,   175,   178,   180,   182,   187,   189,
     192,   194,   197,   199,   203,   205,   208,   210,   212,   214,
     216,   219,   221,   223,   226,   229,   230,   232,   233,   235,
     238,   241,   243,   245,   248,   250,   253,   254,   259,   260,
     263,   264,   271,   272,   274,   276,   278,   280,   282,   284,
     286,   288,   290,   293,   296,   298,   300,   302,   304,   306,
     307,   309,   311,   313,   314,   319,   320,   325,   328,   329,
     331,   335,   337,   340,   343,   344,   346,   350,   351,   353,
     357,   360,   361,   366,   368,   370,   373,   374,   376,   378,
     380,   381,   383,   387,   388,   391,   392,   398,   399,   400,
     406,   410,   411,   414,   417,   420,   421,   423,   425,   427,
     429,   431,   433,   434,   435,   440,   441,   442,   443,   450,
     451,   452,   458,   459,   460,   465,   466,   467,   472,   473,
     477,   478,   481,   484,   486,   488,   490,   493,   495,   496,
     503,   504,   506,   509,   510,   513,   518,   520,   522,   523,
     529,   530,   535,   536,   538,   541,   544,   545,   547,   548,
     552,   553,   557,   561,   564,   565,   567,   570,   571,   574,
     576,   577,   579,   582,   585,   586,   589,   591,   593,   595,
     597,   599,   600,   605,   610,   612,   614,   616,   618,   620,
     621,   623,   625,   628,   630,   632,   634,   636,   638,   640,
     642,   644,   646,   648,   650,   652,   654,   656,   658,   661,
     664,   665,   668,   671,   674,   675,   678,   680,   683,   686,
     689,   692,   695,   698,   701,   704,   707,   708,   710,   712,
     715,   717,   719,   722,   725,   726,   728,   731,   734,   737,
     738,   741,   744,   745,   748,   751,   754,   757,   759,   761,
     763,   765,   767,   769,   771,   773,   775,   779,   784,   789,
     796,   801,   806,   811,   816,   819,   822,   831,   838,   845,
     852,   857,   862,   867,   872,   874,   876,   878,   882,   884,
     892,   893,   895,   898,   901,   907,   910,   913,   916,   919,
     922,   923,   932,   934,   936,   941,   942,   944,   947,   948,
     950,   953,   956,   958,   960,   961,   963,   965,   967,   969,
     971,   973,   975,   977,   979,   981,   983,   985,   987,   989,
     991,   993,   995,   997,   999,  1001,  1003,  1005,  1007,  1009
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   377,   377,   383,   384,   389,   390,   391,   392,   397,
     401,   403,   407,   409,   413,   419,   421,   419,   431,   438,
     441,   449,   451,   449,   461,   469,   472,   479,   482,   487,
     494,   497,   502,   509,   512,   515,   518,   521,   524,   527,
     531,   536,   539,   547,   550,   557,   565,   572,   575,   583,
     586,   593,   596,   601,   608,   615,   616,   620,   626,   632,
     639,   646,   648,   652,   659,   662,   667,   670,   675,   678,
     683,   687,   691,   698,   701,   708,   711,   714,   717,   723,
     729,   732,   739,   744,   751,   755,   763,   765,   773,   776,
     784,   792,   793,   800,   804,   812,   815,   820,   823,   827,
     833,   841,   846,   850,   857,   860,   866,   866,   875,   878,
     885,   885,   894,   897,   900,   903,   906,   909,   912,   915,
     921,   925,   930,   937,   943,   944,   945,   946,   947,   950,
     952,   956,   957,   961,   961,   970,   970,   979,   985,   988,
     992,   999,  1002,  1010,  1017,  1020,  1024,  1030,  1033,  1039,
    1045,  1052,  1052,  1064,  1065,  1070,  1074,  1076,  1081,  1082,
    1086,  1088,  1093,  1097,  1100,  1105,  1105,  1115,  1118,  1115,
    1129,  1133,  1135,  1140,  1145,  1149,  1152,  1156,  1157,  1158,
    1159,  1160,  1164,  1166,  1164,  1180,  1182,  1184,  1180,  1195,
    1197,  1195,  1206,  1208,  1206,  1218,  1221,  1218,  1231,  1231,
    1245,  1247,  1251,  1262,  1263,  1264,  1268,  1276,  1280,  1280,
    1289,  1292,  1299,  1305,  1307,  1314,  1321,  1325,  1328,  1328,
    1338,  1338,  1346,  1348,  1353,  1358,  1362,  1364,  1368,  1368,
    1371,  1371,  1378,  1383,  1387,  1389,  1394,  1398,  1400,  1405,
    1409,  1411,  1416,  1421,  1425,  1427,  1431,  1438,  1442,  1449,
    1450,  1454,  1454,  1467,  1492,  1495,  1498,  1501,  1504,  1511,
    1514,  1519,  1523,  1530,  1531,  1535,  1538,  1542,  1545,  1551,
    1552,  1556,  1559,  1562,  1565,  1568,  1569,  1575,  1580,  1589,
    1596,  1599,  1607,  1616,  1623,  1626,  1633,  1638,  1649,  1652,
    1655,  1658,  1661,  1664,  1667,  1670,  1677,  1680,  1684,  1689,
    1698,  1701,  1708,  1711,  1718,  1721,  1726,  1729,  1733,  1747,
    1750,  1758,  1767,  1770,  1777,  1780,  1783,  1786,  1790,  1791,
    1792,  1793,  1796,  1799,  1802,  1805,  1809,  1815,  1818,  1821,
    1824,  1827,  1830,  1833,  1837,  1840,  1844,  1847,  1850,  1853,
    1856,  1859,  1862,  1865,  1868,  1869,  1870,  1876,  1879,  1886,
    1893,  1896,  1900,  1907,  1914,  1917,  1920,  1923,  1926,  1929,
    1933,  1933,  1945,  1948,  1952,  1958,  1961,  1965,  1975,  1978,
    1983,  1991,  1998,  2002,  2010,  2014,  2018,  2019,  2020,  2024,
    2025,  2026,  2030,  2031,  2032,  2036,  2037,  2038,  2042,  2043,
    2047,  2048,  2049,  2050,  2054,  2055,  2059,  2060,  2064,  2065
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
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SPARQLfedParser::yyeof_ = 0;
  const int SPARQLfedParser::yylast_ = 1409;
  const int SPARQLfedParser::yynnts_ = 223;
  const int SPARQLfedParser::yyempty_ = -2;
  const int SPARQLfedParser::yyfinal_ = 7;
  const int SPARQLfedParser::yyterror_ = 1;
  const int SPARQLfedParser::yyerrcode_ = 256;
  const int SPARQLfedParser::yyntokens_ = 122;

  const unsigned int SPARQLfedParser::yyuser_token_number_max_ = 376;
  const SPARQLfedParser::token_number_type SPARQLfedParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 4146 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 2071 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
	curBindingsClause(NULL), curBinding(NULL), curExprList(NULL), 
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


