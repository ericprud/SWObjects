
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
#line 229 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 368 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

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
#line 382 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(2) - (2)].p_Operation);
}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 418 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 424 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 426 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 428 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 436 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Select((yysemantic_stack_[(4) - (1)].p_Project).distinctness, (yysemantic_stack_[(4) - (1)].p_Project).varSet, (yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 443 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 446 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 454 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 456 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 458 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(5) - (1)].p_Project).distinctness, (yysemantic_stack_[(5) - (1)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier))));
      }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 466 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 474 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 477 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 484 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 492 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 499 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 507 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 514 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 517 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 520 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 523 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 526 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 529 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 532 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 541 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 544 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 552 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 555 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 562 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	(yyval.p_Operation) = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(5) - (2)].p_BasicGraphPattern), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 570 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 577 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm))));
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 580 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_TTerm))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 588 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 591 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 598 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 606 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(3) - (2)].p_DatasetClauses), (yysemantic_stack_[(3) - (3)].p_WhereClause));
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 613 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 625 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 631 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 637 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 644 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp ? driver.curOp : new DefaultGraphPattern(), (yysemantic_stack_[(3) - (3)].p_BindingsClause));
	driver.curOp = NULL;
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 657 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 664 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 672 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 680 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 688 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 696 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 703 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 706 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 713 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 716 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 719 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 722 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 728 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 734 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 737 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 749 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 756 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 760 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 770 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 778 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 781 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 789 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 798 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 805 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 809 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 817 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 825 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 832 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 838 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 851 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTermList) = new TTermList;
	(yyval.p_TTermList)->push_back((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 855 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTermList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_TTermList) = (yysemantic_stack_[(2) - (1)].p_TTermList);
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 862 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 865 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 871 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding = new Binding();
      }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 873 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingValue) = driver.curBinding;
	  driver.curBinding = NULL;
      }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 880 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 883 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingsClause->push_back((yysemantic_stack_[(2) - (2)].p_BindingValue));
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 890 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingsClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_TTermList));
      }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 892 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingsClause) = driver.curBindingsClause;
	  driver.curBindingsClause = NULL;
      }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 899 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingsClause) = NULL;
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 905 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 908 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 911 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 914 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 917 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 920 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 930 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	OperationSet* ret = new OperationSet();
	ret->push_back((yysemantic_stack_[(1) - (1)].p_Operation));
	(yyval.p_Operation) = ret;
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 935 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	dynamic_cast<OperationSet*>((yysemantic_stack_[(2) - (1)].p_Operation))->push_back((yysemantic_stack_[(2) - (2)].p_Operation));
	(yyval.p_Operation) = (yysemantic_stack_[(2) - (1)].p_Operation);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 942 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(2) - (1)].p_Operation);
}
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 971 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 974 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert((yysemantic_stack_[(5) - (4)].p_TableOperation), (yysemantic_stack_[(5) - (5)].p_WhereClause));
      }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 980 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 983 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(4) - (3)].p_TableOperation), (yysemantic_stack_[(4) - (4)].p_WhereClause));
      }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 989 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(2) - (2)].p_URI));
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 995 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1002 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(3) - (2)].p_URIs), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1009 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URIs) = new ProductionVector<const URI*>((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1012 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_URIs)->push_back((yysemantic_stack_[(2) - (2)].p_URI));
	(yyval.p_URIs) = (yysemantic_stack_[(2) - (1)].p_URIs);
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1020 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1027 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1034 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1040 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1043 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1049 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1055 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1062 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1065 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1115 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1118 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
      }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1125 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curFilter = NULL;
      }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1128 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 1131 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(5) - (3)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(5) - (4)].p_TTerm);
      }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 1174 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 1176 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.curFilter;
      }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 1178 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  OptionalGraphPattern* ret = new OptionalGraphPattern(driver.curOp);
	  if (driver.curFilter) {
	      driver.curFilter->copyExpressionsTo(ret);
	      delete driver.curFilter;
	      driver.curFilter = NULL;
	  }
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), ret);
	  driver.curFilter = (yysemantic_stack_[(4) - (3)].p_ParserFilter);
      }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 1191 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 1193 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 1195 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 1198 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 1206 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 1208 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 1210 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(5) - (4)].p_TTerm), driver.curOp, driver.atomFactory, false));
      }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 1217 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1219 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1221 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.curOp));
      }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1229 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1232 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 1234 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 1242 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 1247 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 1262 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    if (driver.curOp == NULL)
		driver.ensureBasicGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 1279 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 1287 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 1291 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 1293 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = NULL;
      }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 1300 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 1303 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 1310 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 1318 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 1325 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_DistExprPair).distinctness = (yysemantic_stack_[(4) - (2)].p_distinctness);
	  (yyval.p_DistExprPair).p_Expression = (yysemantic_stack_[(4) - (3)].p_Expression);
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 1336 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 1339 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 1341 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 1349 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 1351 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 1379 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 1382 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 1442 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 1449 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 1453 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 1465 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 1469 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 1478 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(4) - (1)].p_listModifier) == LIST_exact) {
	    (yyval.p_TTerm) = driver.createBNode();
	    const TTerm* tail = (yyval.p_TTerm);
	    ProductionVector<const TTerm*>* members = (yysemantic_stack_[(4) - (3)].p_TTerms);
	    const URI* first = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#first");
	    const URI* rest = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#rest");
	    const TTerm* nil = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil");
	    driver.ensureBasicGraphPattern();
	    for (unsigned i = 0; i < members->size(); i++) {
		driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(tail, first, members->at(i)));
		const TTerm* nextTail = i == members->size()-1 ? nil : driver.createBNode();
		driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(tail, rest, nextTail));
		tail = nextTail;
	    }
	    members->clear();
	    delete members;
	} else {
	    error(*(yylocation_stack_.end()), "unsupported function");
	}
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 1503 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 1506 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 1509 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 1512 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 1515 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 1522 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 1530 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 1534 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 1546 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 1553 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 1556 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 1567 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 1570 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 1573 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 1576 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 1580 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 1591 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 1600 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 1607 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 1610 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 1618 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 1627 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 1634 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 1637 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 1649 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_GeneralComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_GeneralComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_GeneralComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 1660 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 1663 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 1666 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 1669 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 1672 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 1675 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 1678 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 1681 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 1688 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 1700 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 1709 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 1712 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 1719 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 1722 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 1729 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 1737 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 1740 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 1744 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 311:

/* Line 678 of lalr1.cc  */
#line 1758 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 1761 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 1769 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 1778 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 1781 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 1788 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 1791 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 1794 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 1804 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 1807 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 1810 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 1813 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 1820 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 1826 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 1829 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 1832 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 1835 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 1838 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 1841 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 1844 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 1848 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_blank, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 1851 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 1855 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 1858 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 1861 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 1864 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 1867 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 1870 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 1873 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 1876 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 1887 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 1890 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 1897 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_regex, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 1904 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 1911 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 1918 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 1925 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 1928 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_sum, (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 1931 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_min, (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 1934 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_max, (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 1937 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_avg, (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 1940 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_sample, (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 1944 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 1946 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  // x = new ArgList($2, driver.curExprList);
	  delete driver.curExprList;
	  driver.curExprList = NULL;
	  w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // $$ = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group-concat, $3, $4.p_Expression, $4.separator));
    }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 1956 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
	driver.countStar = true;
    }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 1964 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 1970 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 1977 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 1987 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 1995 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 2003 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 2010 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 2014 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 2022 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 2837 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -437;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        21,   -56,    70,   230,  -437,  -437,  -437,  -437,    36,    69,
     138,    72,    74,    74,    88,    46,    28,  -437,  -437,  -437,
    -437,  -437,  -437,  -437,  -437,  -437,   165,  -437,    51,  -437,
    -437,  -437,  -437,  -437,  -437,  -437,   102,  -437,  -437,  -437,
      36,  -437,  -437,  -437,     9,  -437,  -437,   138,  -437,  -437,
    -437,   138,   138,  -437,  -437,  -437,   721,  -437,  -437,  -437,
    -437,  -437,   -25,  -437,  -437,  -437,  -437,    17,    17,  -437,
    -437,  -437,  -437,  -437,   811,    23,  -437,    72,  -437,  -437,
    -437,  -437,  -437,  -437,  -437,  1008,    96,    99,   -15,   -13,
     105,   116,   119,   141,   141,   127,   134,   140,   142,   144,
     158,   186,   192,   199,   202,   204,   205,   207,   207,   207,
     207,   209,   207,  -437,  -437,  -437,  -437,  -437,  -437,  -437,
    -437,  -437,  -437,  -437,  -437,  -437,  -437,  -437,  -437,  -437,
    1085,  -437,  -437,  -437,  -437,  -437,  -437,  -437,  -437,  -437,
    -437,  -437,  -437,  -437,  -437,   -50,    -9,   811,    17,  -437,
      14,    -4,  -437,  -437,  -437,   141,   166,   146,  -437,  -437,
    -437,  -437,  -437,  -437,  -437,  -437,  -437,  -437,  -437,   212,
    -437,  -437,  -437,  -437,   219,  -437,  -437,  -437,  -437,  -437,
    -437,  -437,  -437,  -437,  -437,    23,  -437,  1008,  1162,  1162,
    1162,  -437,   174,  -437,  -437,  -437,  -437,   131,  -437,  -437,
    -437,  -437,  -437,  -437,  -437,  -437,  -437,  -437,  -437,    -9,
    1008,  1008,  1008,  -437,  -437,  1008,  -437,  -437,  -437,  1008,
    1008,  1008,  -437,  -437,  -437,  1008,  1008,  1008,  1008,    -5,
    1008,  1008,  1008,  1008,  1008,  1008,   253,   253,  -437,  -437,
    -437,  -437,   253,  -437,  -437,   138,  -437,  -437,  -437,  -437,
     253,  -437,  -437,   235,  -437,   237,   166,   166,   138,  -437,
    -437,  -437,  -437,  -437,   243,   259,  -437,   198,  -437,  -437,
      38,   258,   811,  -437,  -437,    38,   927,    38,  -437,   249,
    -437,  -437,  -437,    -5,  -437,   255,   245,   250,  1008,  1008,
    1008,  1008,  1008,  1008,   -13,   -13,  -437,  -437,    57,     3,
    -437,  -437,   262,   265,   266,  -437,   271,   272,   273,   100,
     281,   282,   276,   284,   285,   283,   289,   291,   295,   297,
     292,  -437,   557,  1008,  1008,  -437,  1008,  -437,   811,  -437,
    -437,  -437,  -437,  -437,    -5,  -437,  -437,  -437,   936,  1239,
     317,  -437,   228,  -437,   293,   927,  -437,  -437,   300,   343,
    -437,  -437,  -437,  -437,  -437,  -437,   835,  -437,  -437,  -437,
    -437,  -437,  -437,  1008,  -437,  1008,  -437,  -437,  -437,  -437,
    -437,  -437,  -437,  -437,  -437,  1008,  1008,     3,  -437,  -437,
    -437,  1008,  1008,  -437,  -437,  -437,  -437,  -437,  1008,  1008,
    1008,  -437,  -437,   314,  -437,  -437,  -437,  -437,  1008,  -437,
    -437,  1008,  -437,  -437,  -437,  -437,  1008,  -437,  -437,   311,
     313,  -437,  -437,  -437,   -16,  -437,  1008,   936,  -437,  -437,
    -437,  -437,  1239,  -437,  -437,  -437,  -437,  -437,   331,    93,
    -437,  -437,  -437,  -437,  -437,  -437,  -437,   811,   -25,  -437,
    -437,  -437,  -437,  -437,  -437,  -437,  -437,  -437,  -437,    -8,
     309,   318,   319,  -437,  -437,   303,   320,   321,   310,  -437,
    -437,  -437,  -437,  -437,  -437,   174,  -437,  -437,   648,   264,
     267,  -437,  -437,   334,   338,   323,   325,  -437,  -437,  -437,
    1008,  -437,  1008,  -437,  -437,   328,  -437,  -437,  -437,  -437,
    1239,   300,  -437,  -437,  -437,  -437,  -437,  -437,  -437,  -437,
    -437,  -437,  -437,  -437,   333,   101,    19,  -437,   336,  -437,
    -437,   648,  -437,   329,  -437,  -437,  -437,  -437,  -437,  -437,
    -437,  -437,  -437,  -437,    38,  -437,   927,  -437,    36,  -437,
     337,   166,  -437,  -437,  -437,  -437,  -437,   811,   141,  -437,
     299,  -437,   339,  -437,    43,  -437,  -437,  -437,  -437,  -437,
     927,  -437,  -437,  -437,  -437,   -25,   -25,   141,   141,  -437,
    -437,   324,  -437,  -437,  -437,  -437,  -437,  -437,   141,  -437,
    -437,   341,    82,  1031,   141,  -437,  -437,  -437,  -437,  -437,
    1107,  -437,  -437,  -437,  -437,  -437,  -437,  -437,   141,  -437,
    -437,  -437
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        10,     0,     0,     0,    12,    11,    14,     1,     0,   133,
       0,   140,   149,   149,    27,     0,     0,    19,     2,     3,
       5,    19,     6,     7,     8,     4,   120,   121,   129,   124,
     131,   132,   126,   125,   127,   128,     9,   167,   137,   134,
       0,   396,   399,   398,   146,   143,   397,     0,   139,   141,
     150,     0,     0,    25,    26,    28,     0,   222,    19,    50,
     271,   272,    49,    19,    47,   269,   270,    61,    61,   122,
     130,   123,    15,    13,   158,    51,   135,     0,   147,   142,
     144,   152,   151,   148,    44,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   390,   391,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   392,   394,   393,   395,    40,    41,
      43,    24,    36,    33,    35,   346,   347,   348,    34,    37,
      38,   378,   379,   380,    39,   376,     0,   224,    61,    48,
      51,     0,    62,    20,    53,     0,    64,     0,   256,   257,
     258,   259,   260,   253,   400,   401,   278,   173,   159,   177,
     232,   252,   251,   262,     0,   230,   267,   268,   274,   275,
     276,   273,   277,   138,    52,    51,   145,     0,     0,     0,
       0,   326,    30,   279,   282,   286,   288,   298,   300,   311,
     314,   319,   320,   321,   327,   322,   323,   324,   325,   370,
       0,     0,     0,   350,   336,     0,   219,   337,   218,     0,
       0,     0,   153,   354,   355,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   212,   212,   357,   358,
     359,   360,   212,   361,    42,     0,   374,   375,   377,   372,
     212,   209,   208,     0,   225,   228,    64,    64,     0,    54,
      55,    56,    57,    59,   112,     0,    18,    66,    65,    16,
       0,   169,   158,   178,   175,   242,   261,     0,   136,     0,
     317,   318,   316,     0,    31,     0,   280,   284,     0,     0,
       0,     0,     0,     0,     0,     0,   299,   289,   301,   313,
     371,   369,     0,     0,     0,   220,     0,     0,     0,   158,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   213,     0,     0,     0,   373,     0,   223,   224,   229,
     226,    45,    46,    58,     0,    60,   113,   101,     0,     0,
      68,    67,     0,   250,     0,   261,   249,   168,   162,     0,
     174,   176,   243,   233,   241,   266,   261,   263,   265,   231,
     328,    29,    32,     0,   283,     0,   287,   290,   291,   292,
     293,   294,   295,   296,   297,     0,     0,   306,   312,   302,
     303,     0,     0,   315,   334,   335,   349,   215,     0,     0,
       0,   155,    21,     0,   156,   165,   329,   330,     0,   332,
     333,     0,   342,   343,   344,   345,     0,   364,   365,     0,
       0,   362,   210,   227,     0,   102,     0,    72,    73,    76,
      78,    75,    79,    80,    82,   207,   205,   206,     0,    70,
      69,    17,   254,   239,   246,   248,   163,   158,     0,   255,
     264,   281,   285,   308,   309,   307,   310,   304,   305,     0,
       0,     0,     0,    22,   154,   157,     0,     0,   352,   356,
     217,   215,   215,   110,   103,    30,    74,    81,     0,     0,
       0,    63,    71,    95,    97,   234,   244,   172,   170,   221,
       0,   216,     0,   339,   340,    61,   187,   191,   184,   194,
       0,   162,   166,   160,   179,   182,   183,   180,   181,   198,
     161,   331,   341,   353,     0,   367,     0,   108,     0,    88,
      89,    83,    84,     0,    86,    87,    91,    92,    99,   100,
      93,    96,    94,    98,   236,   240,   261,   247,     0,   214,
       0,    64,   188,   192,   185,   195,   204,   158,     0,   351,
       0,   368,     0,   211,     0,    77,    85,    90,   237,   238,
     261,   245,   171,   338,    23,     0,     0,     0,     0,   164,
     202,     0,   363,   111,   106,   109,   235,   189,     0,   186,
     196,   199,     0,     0,     0,   193,   200,   203,   366,   118,
       0,   104,   119,   115,   116,   117,   114,   190,     0,   107,
     105,   201
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -437,  -437,  -437,  -437,  -437,  -437,  -437,  -437,  -437,  -437,
    -437,  -437,     5,  -437,  -437,  -437,    73,  -437,  -437,  -437,
     -82,  -437,   254,  -437,  -437,  -437,  -437,  -437,  -437,  -120,
    -437,  -437,  -437,  -437,  -437,   130,   -55,  -437,  -240,  -437,
    -437,  -437,  -437,  -437,  -437,   -28,  -437,  -437,   -37,  -437,
    -437,  -121,  -437,  -437,  -437,  -437,  -437,  -437,   -83,   -80,
    -437,  -437,  -437,  -437,  -437,  -437,  -437,  -437,  -437,  -186,
    -437,  -437,   369,  -437,  -437,  -437,  -437,  -437,  -437,  -437,
    -437,  -437,  -437,  -437,  -437,  -437,  -437,  -437,   383,  -437,
     322,   -86,  -437,  -437,  -437,  -258,  -437,   -94,  -437,  -437,
     -39,  -437,  -437,  -437,  -437,  -437,  -437,  -437,  -437,  -437,
    -437,  -437,  -437,  -437,  -437,  -437,  -437,  -437,  -437,  -437,
    -437,  -437,  -437,  -437,  -437,  -437,  -437,  -437,  -437,  -437,
    -437,  -436,   -53,   189,  -437,  -193,   -58,  -291,    18,   -71,
    -437,  -437,  -437,  -437,    75,  -437,  -437,  -437,  -143,  -437,
    -437,  -232,  -437,  -437,  -437,  -437,  -437,  -437,  -149,  -437,
    -437,  -124,  -119,  -269,  -437,  -437,  -437,  -437,  -437,  -437,
    -255,  -248,   -14,    -1,  -437,   381,  -437,  -437,  -437,    41,
    -437,  -437,    44,  -437,  -437,  -437,    24,  -437,  -437,    29,
    -437,  -437,  -437,  -146,  -437,  -145,    98,  -330,   -46,  -437,
    -437,  -437,  -437,  -437,   -32,  -437,  -437,  -437,  -437,  -437,
    -437,   -51,  -437,  -437,  -437,   -45,  -437,   110,   112,    25,
    -161,   -10,  -437,  -437
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,    18,    19,     3,     4,    36,     5,    73,   157,
     342,    20,    67,   391,   453,   485,    21,    55,    56,   284,
     285,   128,   129,   130,   131,    22,    23,    62,    63,   183,
      24,   153,   259,   260,   261,   262,   184,   155,   266,   267,
     340,   429,   471,   268,   417,   418,   341,   422,   423,   430,
     511,   512,   513,   514,   515,   472,   520,   522,   473,   474,
     335,   414,   580,   565,   573,   544,   336,   507,   337,   581,
      25,    26,    27,    28,    71,    29,    40,    30,   185,    31,
      75,    32,    48,    33,    44,    78,    79,    34,    51,    35,
      49,   223,   309,   393,   394,   167,   491,   437,   492,   455,
      38,    74,   348,   349,   528,   350,   271,   168,   273,   274,
     493,   494,   534,   557,   495,   532,   555,   574,   496,   533,
     556,   497,   535,   558,   498,   499,   538,   577,   588,   571,
     500,   424,   425,   252,   462,   322,   481,   449,   238,   217,
     218,   387,    58,   147,   253,   254,   329,   330,   169,   277,
     275,   344,   548,   549,   525,   475,   353,   354,   433,   527,
     476,   434,   345,   170,   171,   270,   172,   173,   174,   356,
     435,   175,   346,   191,   177,   192,   193,   364,   286,   194,
     366,   287,   195,   196,   296,   297,   197,   198,   377,   383,
     446,   378,   298,   199,   299,   200,   201,   202,   203,   214,
     135,   504,   136,   137,   204,   461,   409,   541,   542,   205,
     301,   206,   247,   248,   249,   207,   141,   142,   143,   208,
     145,   209,    46,   182
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SPARQLfedParser::yytable_ninf_ = -262;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        45,    76,    64,   132,   255,   139,    66,   355,   224,   426,
     134,   140,   154,   156,   351,    65,   331,   332,    77,   258,
     463,   357,   381,   178,   138,   212,    68,   215,   358,   179,
     257,   250,   516,   479,    80,     1,   151,    81,   245,   151,
     480,    82,    83,   352,   323,   359,   146,    59,   149,   324,
     -61,   395,    66,   152,   536,   133,   152,   326,     6,   -61,
     543,    65,   152,   148,   181,   278,   382,   480,   150,   264,
       7,   246,    37,   176,    39,   516,   355,   132,    47,   139,
     563,   144,    57,   564,   134,   140,    50,   355,   343,    41,
      42,    43,   426,   256,    60,    61,   178,   358,   138,   180,
      70,   440,   179,    60,    61,    53,    54,   213,   358,   216,
      41,    42,    43,   251,    60,    61,    14,    72,   375,   376,
     146,   469,   470,    41,    42,    43,   239,   240,   241,   133,
     243,   158,   159,   160,   161,   162,   210,   181,   426,   211,
    -261,   263,    41,    42,    43,   219,   176,    60,    61,   480,
     540,   163,    41,    42,    43,   144,   220,    60,    61,   221,
     426,   118,   119,   120,   121,   122,   123,   225,     8,     9,
     505,   506,   180,    10,   226,    11,    12,   222,    13,   477,
     227,   426,   228,   547,   229,   255,   288,   289,   290,   291,
     292,   293,   124,   125,   126,   127,   294,   295,   230,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    41,    42,    43,   164,   165,    60,
      61,   178,   166,   373,   374,   178,   231,   179,   314,   443,
     444,   179,   232,     8,     9,   325,   447,   448,    10,   233,
      11,    12,   234,    13,   235,   236,    14,   237,   263,   242,
      15,    16,    41,    42,    43,   272,   265,   355,   178,   276,
      66,   269,   181,   283,   179,    66,   181,    66,    17,    65,
     321,   176,   327,   334,    65,   176,    65,   178,   358,   559,
     328,   355,   361,   179,   338,   419,   280,   281,   282,   339,
     360,   554,   421,   427,   178,   347,   362,   180,   363,   181,
     179,   180,   358,   384,   365,   178,   385,   386,   176,   486,
     487,   179,   367,   368,   369,   370,   371,   372,   181,   388,
     389,   390,   396,   397,   398,   399,   400,   176,   146,   146,
     402,   401,   403,   415,   180,   181,   404,   420,   405,  -197,
     406,   428,   431,   436,   176,   432,   181,   488,   489,   438,
     490,   454,   459,   180,   460,   176,   468,   482,   480,   483,
     484,   501,   502,   470,   419,   518,   469,   152,   519,   187,
     180,   421,   524,   526,   539,   561,   427,   545,   553,   572,
     562,   180,   392,   508,   244,   467,   178,   576,   333,   466,
     546,   523,   179,   521,   590,    69,    52,   537,   300,   186,
     503,   566,   551,   413,   441,   550,   445,   146,   379,   442,
     380,   578,   146,   464,     0,     0,   420,     0,     0,     0,
       0,     0,   427,     0,   478,     0,     0,   181,    66,     0,
     531,     0,     0,     0,     0,     0,   176,    65,     0,     0,
       0,     0,     0,     0,   427,     0,     0,     0,     0,     0,
       0,     0,   560,     0,     0,     0,     0,     0,   146,     0,
       0,     0,   180,     0,     0,   427,     0,   517,     0,     0,
       0,   569,   570,     0,     0,   178,     0,     0,     0,     0,
     146,   179,   575,     0,     0,     0,   178,     0,   587,   552,
       0,     0,   179,     0,     0,     0,     0,     0,     0,   178,
       0,   146,   591,     0,     0,   179,     0,     0,     0,     0,
     517,     0,     0,     0,    66,     0,   181,     0,     0,     0,
       0,     0,   583,    65,     0,   176,     0,   181,   584,   583,
       0,     0,     0,     0,     0,   584,   176,     0,     0,     0,
     181,   567,   568,     0,     0,    66,    66,     0,     0,   176,
       0,   180,     0,     0,    65,    65,     0,     0,     0,     0,
       0,     0,   180,   586,     0,     0,     0,     0,   279,     0,
     586,     0,   582,     0,     0,   180,   407,     0,     0,   582,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   302,   303,   304,     0,     0,   305,   187,   585,     0,
     306,   307,   308,     0,     0,   585,   310,   311,   312,   313,
       0,   315,   316,   317,   318,   319,   320,     0,   188,   189,
       0,   190,     0,     0,    86,    87,    88,    89,    90,    91,
      92,    93,    94,     0,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,     0,     0,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    41,    42,    43,   509,   510,    60,    61,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   187,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   408,   410,   411,     0,   412,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
      91,    92,    93,    94,     0,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,     0,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    85,    41,    42,    43,     0,     0,    60,    61,   450,
     451,   452,     0,     0,     0,     0,     0,     0,     0,   456,
       0,     0,   457,     0,     0,     0,     0,   458,    86,    87,
      88,    89,    90,    91,    92,    93,    94,   465,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,     0,
       0,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    41,    42,    43,     0,     0,
      60,    61,   158,   159,   160,   161,   162,     0,     0,     0,
       0,  -261,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   529,   163,   530,     0,     0,   158,   159,   160,   161,
     162,     0,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    41,    42,    43,   164,   165,
      60,    61,     0,   166,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    41,
      42,    43,   164,   165,    60,    61,     0,   166,   158,   159,
     160,   161,   162,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   416,     0,   163,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,    91,    92,
      93,    94,     0,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,     0,     0,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    41,    42,    43,   164,   165,    60,    61,   187,   166,
      41,    42,    43,     0,     0,    60,    61,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   188,
     189,     0,   190,   579,     0,    86,    87,    88,    89,    90,
      91,    92,    93,    94,     0,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,    41,    42,    43,    85,     0,    60,    61,     0,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    41,    42,    43,   589,   579,
      60,    61,    86,    87,    88,    89,    90,    91,    92,    93,
      94,     0,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,     0,     0,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    41,
      42,    43,   187,     0,    60,    61,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    41,    42,    43,     0,     0,    60,    61,     0,    86,
      87,    88,    89,    90,    91,    92,    93,    94,     0,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,     0,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    41,    42,    43,   187,
       0,    60,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,    92,    93,    94,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,    42,    43
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        10,    40,    16,    56,   147,    56,    16,   276,    94,   339,
      56,    56,    67,    68,   272,    16,   256,   257,     9,    23,
      36,   276,    19,    74,    56,    40,    21,    40,   276,    74,
     150,    40,   468,    41,    44,    14,    22,    47,    88,    22,
      48,    51,    52,   275,   237,   277,    56,    19,    62,   242,
      36,   309,    62,    39,   490,    56,    39,   250,   114,    36,
      41,    62,    39,    58,    74,   185,    63,    48,    63,   155,
       0,   121,    36,    74,     5,   511,   345,   130,     6,   130,
      37,    56,    36,    40,   130,   130,    12,   356,    50,   114,
     115,   116,   422,   148,   119,   120,   147,   345,   130,    74,
      49,   356,   147,   119,   120,    17,    18,   122,   356,   122,
     114,   115,   116,   122,   119,   120,    16,    15,    61,    62,
     130,    28,    29,   114,   115,   116,   108,   109,   110,   130,
     112,    31,    32,    33,    34,    35,    40,   147,   468,    40,
      40,   151,   114,   115,   116,    40,   147,   119,   120,    48,
      49,    51,   114,   115,   116,   130,    40,   119,   120,    40,
     490,   104,   105,   106,   107,   108,   109,    40,     3,     4,
     461,   462,   147,     8,    40,    10,    11,    36,    13,   437,
      40,   511,    40,   513,    40,   328,    55,    56,    57,    58,
      59,    60,   110,   111,   112,   113,    65,    66,    40,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   272,   122,   294,   295,   276,    40,   272,   229,   375,
     376,   276,    40,     3,     4,   245,   381,   382,     8,    40,
      10,    11,    40,    13,    40,    40,    16,    40,   258,    40,
      20,    21,   114,   115,   116,    43,    90,   526,   309,    40,
     270,   115,   272,    89,   309,   275,   276,   277,    38,   270,
      17,   272,    37,    30,   275,   276,   277,   328,   526,   537,
      43,   550,   283,   328,    25,   338,   188,   189,   190,    91,
      41,   531,   338,   339,   345,    37,    41,   272,    53,   309,
     345,   276,   550,    41,    54,   356,    41,    41,   309,     6,
       7,   356,   288,   289,   290,   291,   292,   293,   328,    48,
      48,    48,    41,    41,    48,    41,    41,   328,   338,   339,
      41,    48,    41,   334,   309,   345,    41,   338,    41,    36,
      48,    24,   114,    43,   345,    52,   356,    44,    45,     6,
      47,    37,    41,   328,    41,   356,    25,    48,    48,    41,
      41,    41,    41,    29,   417,   101,    28,    39,   101,    40,
     345,   417,    49,    48,    41,    76,   422,    41,    41,    55,
      41,   356,   309,   465,   130,   422,   437,    46,   258,   417,
     511,   474,   437,   473,   580,    26,    13,   491,   209,    77,
     458,   550,   526,   328,   363,   524,   377,   417,   298,   365,
     298,   572,   422,   414,    -1,    -1,   417,    -1,    -1,    -1,
      -1,    -1,   468,    -1,   438,    -1,    -1,   437,   438,    -1,
     485,    -1,    -1,    -1,    -1,    -1,   437,   438,    -1,    -1,
      -1,    -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   538,    -1,    -1,    -1,    -1,    -1,   468,    -1,
      -1,    -1,   437,    -1,    -1,   511,    -1,   468,    -1,    -1,
      -1,   557,   558,    -1,    -1,   526,    -1,    -1,    -1,    -1,
     490,   526,   568,    -1,    -1,    -1,   537,    -1,   574,   528,
      -1,    -1,   537,    -1,    -1,    -1,    -1,    -1,    -1,   550,
      -1,   511,   588,    -1,    -1,   550,    -1,    -1,    -1,    -1,
     511,    -1,    -1,    -1,   524,    -1,   526,    -1,    -1,    -1,
      -1,    -1,   573,   524,    -1,   526,    -1,   537,   573,   580,
      -1,    -1,    -1,    -1,    -1,   580,   537,    -1,    -1,    -1,
     550,   555,   556,    -1,    -1,   555,   556,    -1,    -1,   550,
      -1,   526,    -1,    -1,   555,   556,    -1,    -1,    -1,    -1,
      -1,    -1,   537,   573,    -1,    -1,    -1,    -1,   187,    -1,
     580,    -1,   573,    -1,    -1,   550,    19,    -1,    -1,   580,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   210,   211,   212,    -1,    -1,   215,    40,   573,    -1,
     219,   220,   221,    -1,    -1,   580,   225,   226,   227,   228,
      -1,   230,   231,   232,   233,   234,   235,    -1,    61,    62,
      -1,    64,    -1,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    26,    27,   119,   120,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   322,   323,   324,    -1,   326,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    -1,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    -1,    -1,    -1,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,   114,   115,   116,    -1,    -1,   119,   120,   388,
     389,   390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   398,
      -1,    -1,   401,    -1,    -1,    -1,    -1,   406,    67,    68,
      69,    70,    71,    72,    73,    74,    75,   416,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    -1,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,    -1,    -1,
     119,   120,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   480,    51,   482,    -1,    -1,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,   122,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,   122,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    -1,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    -1,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    40,   122,
     114,   115,   116,    -1,    -1,   119,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    -1,    64,    42,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    -1,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,    40,    -1,   119,   120,    -1,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,    41,    42,
     119,   120,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,    40,    -1,   119,   120,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    -1,    -1,   119,   120,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    -1,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,    40,
      -1,   119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    -1,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,   115,   116
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    14,   124,   127,   128,   130,   114,     0,     3,     4,
       8,    10,    11,    13,    16,    20,    21,    38,   125,   126,
     134,   139,   148,   149,   153,   193,   194,   195,   196,   198,
     200,   202,   204,   206,   210,   212,   129,    36,   223,     5,
     199,   114,   115,   116,   207,   344,   345,     6,   205,   213,
      12,   211,   211,    17,    18,   140,   141,    36,   265,    19,
     119,   120,   150,   151,   295,   296,   344,   135,   135,   195,
      49,   197,    15,   131,   224,   203,   223,     9,   208,   209,
     344,   344,   344,   344,    19,    40,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   144,   145,
     146,   147,   255,   296,   321,   323,   325,   326,   327,   334,
     338,   339,   340,   341,   342,   343,   344,   266,   135,   295,
     135,    22,    39,   154,   159,   160,   159,   132,    31,    32,
      33,    34,    35,    51,   117,   118,   122,   218,   230,   271,
     286,   287,   289,   290,   291,   294,   296,   297,   334,   338,
     342,   344,   346,   152,   159,   201,   213,    40,    61,    62,
      64,   296,   298,   299,   302,   305,   306,   309,   310,   316,
     318,   319,   320,   321,   327,   332,   334,   338,   342,   344,
      40,    40,    40,   122,   322,    40,   122,   262,   263,    40,
      40,    40,    36,   214,   214,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,   261,   261,
     261,   261,    40,   261,   145,    88,   121,   335,   336,   337,
      40,   122,   256,   267,   268,   271,   159,   152,    23,   155,
     156,   157,   158,   344,   214,    90,   161,   162,   166,   115,
     288,   229,    43,   231,   232,   273,    40,   272,   152,   298,
     319,   319,   319,    89,   142,   143,   301,   304,    55,    56,
      57,    58,    59,    60,    65,    66,   307,   308,   315,   317,
     256,   333,   298,   298,   298,   298,   298,   298,   298,   215,
     298,   298,   298,   298,   296,   298,   298,   298,   298,   298,
     298,    17,   258,   258,   258,   344,   258,    37,    43,   269,
     270,   161,   161,   158,    30,   183,   189,   191,    25,    91,
     163,   169,   133,    50,   274,   285,   295,    37,   225,   226,
     228,   218,   274,   279,   280,   286,   292,   293,   294,   274,
      41,   296,    41,    53,   300,    54,   303,   309,   309,   309,
     309,   309,   309,   262,   262,    61,    62,   311,   314,   340,
     341,    19,    63,   312,    41,    41,    41,   264,    48,    48,
      48,   136,   139,   216,   217,   218,    41,    41,    48,    41,
      41,    48,    41,    41,    41,    41,    48,    19,   298,   329,
     298,   298,   298,   267,   184,   296,    40,   167,   168,   255,
     296,   321,   170,   171,   254,   255,   320,   321,    24,   164,
     172,   114,    52,   281,   284,   293,    43,   220,     6,    41,
     293,   302,   305,   316,   316,   312,   313,   318,   318,   260,
     298,   298,   298,   137,    37,   222,   298,   298,   298,    41,
      41,   328,   257,    36,   296,   298,   168,   171,    25,    28,
      29,   165,   178,   181,   182,   278,   283,   218,   295,    41,
      48,   259,    48,    41,    41,   138,     6,     7,    44,    45,
      47,   219,   221,   233,   234,   237,   241,   244,   247,   248,
     253,    41,    41,   259,   324,   260,   260,   190,   143,    26,
      27,   173,   174,   175,   176,   177,   254,   296,   101,   101,
     179,   182,   180,   181,    49,   277,    48,   282,   227,   298,
     298,   159,   238,   242,   235,   245,   254,   220,   249,    41,
      49,   330,   331,    41,   188,    41,   174,   320,   275,   276,
     285,   284,   223,    41,   161,   239,   243,   236,   246,   218,
     214,    76,    41,    37,    40,   186,   281,   295,   295,   214,
     214,   252,    55,   187,   240,   214,    46,   250,   343,    42,
     185,   192,   296,   334,   338,   342,   344,   214,   251,    41,
     192,   214
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
     375,   376,   377
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  SPARQLfedParser::yyr1_[] =
  {
         0,   123,   124,   125,   125,   126,   126,   126,   126,   127,
     128,   128,   129,   129,   130,   132,   133,   131,   134,   135,
     135,   137,   138,   136,   139,   140,   140,   141,   141,   142,
     143,   143,   144,   145,   145,   145,   145,   145,   145,   145,
     145,   146,   146,   147,   147,   148,   149,   150,   150,   151,
     151,   152,   152,   153,   154,   155,   155,   156,   157,   158,
     159,   160,   160,   161,   162,   162,   163,   163,   164,   164,
     165,   165,   166,   167,   167,   168,   168,   168,   168,   169,
     170,   170,   171,   172,   173,   173,   174,   174,   175,   175,
     176,   177,   177,   178,   178,   179,   179,   180,   180,   181,
     182,   183,   184,   184,   185,   185,   187,   186,   188,   188,
     190,   189,   191,   191,   192,   192,   192,   192,   192,   192,
     193,   194,   194,   195,   196,   196,   196,   196,   196,   197,
     197,   198,   198,   199,   199,   201,   200,   203,   202,   204,
     205,   205,   206,   207,   207,   208,   209,   209,   210,   211,
     211,   212,   213,   215,   214,   216,   216,   217,   218,   218,
     219,   219,   220,   220,   221,   222,   222,   224,   223,   226,
     227,   225,   228,   229,   229,   230,   231,   232,   232,   233,
     233,   233,   233,   233,   235,   236,   234,   238,   239,   240,
     237,   242,   243,   241,   245,   246,   244,   248,   249,   247,
     251,   250,   252,   252,   253,   254,   254,   254,   255,   256,
     257,   256,   258,   258,   259,   260,   260,   261,   262,   263,
     264,   263,   266,   265,   267,   267,   268,   269,   270,   270,
     272,   271,   273,   271,   274,   275,   276,   276,   277,   278,
     278,   279,   280,   280,   281,   282,   283,   283,   284,   285,
     285,   286,   286,   288,   287,   289,   290,   290,   290,   290,
     290,   291,   291,   292,   292,   293,   293,   294,   294,   295,
     295,   296,   296,   297,   297,   297,   297,   297,   297,   298,
     299,   300,   301,   301,   302,   303,   304,   304,   305,   306,
     307,   307,   307,   307,   307,   307,   307,   307,   308,   308,
     309,   310,   311,   311,   312,   312,   313,   313,   314,   314,
     314,   315,   315,   316,   317,   317,   318,   318,   318,   318,
     319,   319,   319,   319,   319,   319,   319,   319,   320,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   322,
     322,   323,   324,   324,   325,   326,   327,   327,   327,   327,
     327,   327,   328,   327,   329,   329,   330,   331,   331,   332,
     333,   333,   334,   335,   336,   336,   337,   337,   338,   338,
     338,   339,   339,   339,   340,   340,   340,   341,   341,   341,
     342,   342,   343,   343,   343,   343,   344,   344,   345,   345,
     346,   346
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
       1,     1,     1,     0,     1,     0,     5,     0,     4,     2,
       0,     1,     3,     1,     2,     2,     0,     1,     3,     0,
       1,     3,     2,     0,     4,     1,     1,     2,     0,     1,
       1,     1,     0,     1,     3,     0,     2,     0,     5,     0,
       0,     5,     3,     0,     2,     2,     2,     0,     1,     1,
       1,     1,     1,     1,     0,     0,     4,     0,     0,     0,
       6,     0,     0,     5,     0,     0,     4,     0,     0,     4,
       0,     3,     0,     2,     2,     1,     1,     1,     2,     1,
       0,     6,     0,     1,     2,     0,     2,     4,     1,     1,
       0,     5,     0,     4,     0,     1,     2,     2,     0,     1,
       0,     3,     0,     3,     3,     2,     0,     1,     2,     0,
       2,     1,     0,     1,     2,     2,     0,     2,     1,     1,
       1,     1,     1,     0,     4,     4,     1,     1,     1,     1,
       1,     0,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     0,     2,     2,     2,     0,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     0,     1,
       1,     2,     1,     1,     2,     2,     0,     1,     2,     2,
       2,     0,     2,     2,     0,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     4,
       4,     6,     4,     4,     4,     4,     2,     2,     8,     6,
       6,     6,     4,     4,     4,     4,     1,     1,     1,     3,
       1,     7,     0,     1,     2,     2,     5,     2,     2,     2,
       2,     2,     0,     8,     1,     1,     4,     0,     1,     2,
       0,     1,     2,     2,     1,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const SPARQLfedParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "IT_DELETE", "IT_INSERT",
  "IT_DATA", "IT_GRAPH", "IT_SERVICE", "IT_LOAD", "IT_INTO", "IT_CLEAR",
  "IT_CREATE", "IT_SILENT", "IT_DROP", "IT_BASE", "IT_PREFIX", "IT_SELECT",
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
  "_QGT_SEMI_E_Opt", "Modify", "_QIT_DATA_E_Opt", "Insert", "@7", "Delete",
  "@8", "Clear", "_QGraphRef_E_Opt", "Load", "_QIRIref_E_Plus",
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
       124,     0,    -1,   127,   125,    -1,   126,    -1,   193,    -1,
     134,    -1,   148,    -1,   149,    -1,   153,    -1,   128,   129,
      -1,    -1,   130,    -1,    -1,   129,   131,    -1,    14,   114,
      -1,    -1,    -1,    15,   132,   115,   133,   114,    -1,   139,
     135,   159,   161,    -1,    -1,   135,   154,    -1,    -1,    -1,
     139,   137,   138,   159,   161,    -1,    16,   141,   147,    -1,
      17,    -1,    18,    -1,    -1,   140,    -1,    89,   296,    -1,
      -1,   142,    -1,    40,   298,   143,    41,    -1,   296,    -1,
     327,    -1,   321,    -1,   255,    -1,   334,    -1,   338,    -1,
     342,    -1,   144,    -1,   145,    -1,   146,   145,    -1,   146,
      -1,    19,    -1,    20,   265,   135,   159,   161,    -1,    21,
     151,   135,   152,   161,    -1,   295,    -1,   150,   295,    -1,
     150,    -1,    19,    -1,    -1,   159,    -1,    38,   135,   159,
      -1,    22,   155,    -1,   156,    -1,   157,    -1,   158,    -1,
      23,   158,    -1,   344,    -1,   160,   214,   183,    -1,    -1,
      39,    -1,   162,   163,   164,   165,    -1,    -1,   166,    -1,
      -1,   169,    -1,    -1,   172,    -1,    -1,   178,    -1,    90,
      25,   167,    -1,   168,    -1,   167,   168,    -1,   321,    -1,
     255,    -1,    40,   298,   143,    41,    -1,   296,    -1,    91,
     170,    -1,   171,    -1,   170,   171,    -1,   254,    -1,    24,
      25,   173,    -1,   174,    -1,   173,   174,    -1,   176,    -1,
     177,    -1,    26,    -1,    27,    -1,   175,   320,    -1,   254,
      -1,   296,    -1,   181,   179,    -1,   182,   180,    -1,    -1,
     182,    -1,    -1,   181,    -1,    28,   101,    -1,    29,   101,
      -1,   191,    -1,   296,    -1,   184,   296,    -1,   192,    -1,
     185,   192,    -1,    -1,    40,   187,   185,    41,    -1,    -1,
     188,   186,    -1,    -1,    30,   184,    36,   190,   188,    37,
      -1,    -1,   189,    -1,   344,    -1,   334,    -1,   338,    -1,
     342,    -1,    42,    -1,   296,    -1,   194,    -1,   195,    -1,
     194,   195,    -1,   196,   197,    -1,   198,    -1,   206,    -1,
     204,    -1,   210,    -1,   212,    -1,    -1,    49,    -1,   200,
      -1,   202,    -1,    -1,     5,    -1,    -1,     4,   199,   223,
     201,   152,    -1,    -1,     3,   223,   203,   152,    -1,    10,
     205,    -1,    -1,   213,    -1,     8,   207,   209,    -1,   344,
      -1,   207,   344,    -1,     9,   213,    -1,    -1,   208,    -1,
      13,   211,   344,    -1,    -1,    12,    -1,    11,   211,   344,
      -1,     6,   344,    -1,    -1,    36,   215,   216,    37,    -1,
     136,    -1,   217,    -1,   218,   222,    -1,    -1,   230,    -1,
     233,    -1,   253,    -1,    -1,    43,    -1,   219,   220,   218,
      -1,    -1,   222,   221,    -1,    -1,    36,   224,   218,   229,
      37,    -1,    -1,    -1,   226,     6,   295,   227,   223,    -1,
     225,   220,   218,    -1,    -1,   229,   228,    -1,   271,   232,
      -1,    43,   218,    -1,    -1,   231,    -1,   234,    -1,   244,
      -1,   247,    -1,   237,    -1,   241,    -1,    -1,    -1,    44,
     235,   236,   214,    -1,    -1,    -1,    -1,     6,   238,   239,
     295,   240,   214,    -1,    -1,    -1,     7,   242,   243,   295,
     214,    -1,    -1,    -1,    45,   245,   246,   214,    -1,    -1,
      -1,   248,   249,   214,   252,    -1,    -1,    46,   251,   214,
      -1,    -1,   252,   250,    -1,    47,   254,    -1,   320,    -1,
     321,    -1,   255,    -1,   344,   256,    -1,   122,    -1,    -1,
      40,   258,   298,   257,   260,    41,    -1,    -1,    17,    -1,
      48,   298,    -1,    -1,   260,   259,    -1,    40,   258,   298,
      41,    -1,   263,    -1,   122,    -1,    -1,    40,   298,   264,
     260,    41,    -1,    -1,    36,   266,   267,    37,    -1,    -1,
     268,    -1,   271,   270,    -1,    43,   267,    -1,    -1,   269,
      -1,    -1,   294,   272,   274,    -1,    -1,   286,   273,   279,
      -1,   285,   281,   278,    -1,   285,   281,    -1,    -1,   275,
      -1,    49,   276,    -1,    -1,   278,   277,    -1,   280,    -1,
      -1,   274,    -1,   284,   283,    -1,    48,   284,    -1,    -1,
     283,   282,    -1,   293,    -1,   295,    -1,    50,    -1,   289,
      -1,   287,    -1,    -1,    51,   288,   274,    52,    -1,   291,
      40,   292,    41,    -1,    31,    -1,    32,    -1,    33,    -1,
      34,    -1,    35,    -1,    -1,   290,    -1,   293,    -1,   292,
     293,    -1,   294,    -1,   286,    -1,   296,    -1,   297,    -1,
     296,    -1,   344,    -1,   119,    -1,   120,    -1,   344,    -1,
     334,    -1,   338,    -1,   342,    -1,   346,    -1,   122,    -1,
     299,    -1,   302,   301,    -1,    53,   302,    -1,    -1,   301,
     300,    -1,   305,   304,    -1,    54,   305,    -1,    -1,   304,
     303,    -1,   306,    -1,   309,   308,    -1,    55,   309,    -1,
      56,   309,    -1,    57,   309,    -1,    58,   309,    -1,    59,
     309,    -1,    60,   309,    -1,    65,   262,    -1,    66,   262,
      -1,    -1,   307,    -1,   310,    -1,   316,   315,    -1,   340,
      -1,   341,    -1,    19,   318,    -1,    63,   318,    -1,    -1,
     312,    -1,    61,   316,    -1,    62,   316,    -1,   311,   313,
      -1,    -1,   315,   314,    -1,   318,   317,    -1,    -1,   317,
     312,    -1,    64,   319,    -1,    61,   319,    -1,    62,   319,
      -1,   319,    -1,   320,    -1,   321,    -1,   332,    -1,   334,
      -1,   338,    -1,   342,    -1,   296,    -1,   327,    -1,    40,
     298,    41,    -1,    77,    40,   298,    41,    -1,    78,    40,
     298,    41,    -1,    79,    40,   298,    48,   298,    41,    -1,
      80,    40,   298,    41,    -1,    81,    40,   296,    41,    -1,
      67,    40,   298,    41,    -1,    68,    40,   298,    41,    -1,
      69,   322,    -1,    70,   262,    -1,    71,    40,   298,    48,
     298,    48,   298,    41,    -1,    72,    40,   298,    48,   298,
      41,    -1,    73,    40,   298,    48,   298,    41,    -1,    82,
      40,   298,    48,   298,    41,    -1,    83,    40,   298,    41,
      -1,    84,    40,   298,    41,    -1,    85,    40,   298,    41,
      -1,    86,    40,   298,    41,    -1,   323,    -1,   325,    -1,
     326,    -1,    40,   298,    41,    -1,   122,    -1,    87,    40,
     298,    48,   298,   324,    41,    -1,    -1,   259,    -1,    74,
     214,    -1,    75,   214,    -1,    92,    40,   258,   329,    41,
      -1,    93,   261,    -1,    94,   261,    -1,    95,   261,    -1,
      96,   261,    -1,    98,   261,    -1,    -1,    97,    40,   258,
     298,   328,   260,   331,    41,    -1,    19,    -1,   298,    -1,
      49,    76,    55,   343,    -1,    -1,   330,    -1,   344,   333,
      -1,    -1,   256,    -1,   343,   337,    -1,    88,   344,    -1,
     121,    -1,   335,    -1,    -1,   336,    -1,   339,    -1,   340,
      -1,   341,    -1,   101,    -1,   102,    -1,   103,    -1,   104,
      -1,   105,    -1,   106,    -1,   107,    -1,   108,    -1,   109,
      -1,    99,    -1,   100,    -1,   110,    -1,   112,    -1,   111,
      -1,   113,    -1,   114,    -1,   345,    -1,   116,    -1,   115,
      -1,   117,    -1,   118,    -1
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
     307,   309,   311,   313,   314,   316,   317,   323,   324,   329,
     332,   333,   335,   339,   341,   344,   347,   348,   350,   354,
     355,   357,   361,   364,   365,   370,   372,   374,   377,   378,
     380,   382,   384,   385,   387,   391,   392,   395,   396,   402,
     403,   404,   410,   414,   415,   418,   421,   424,   425,   427,
     429,   431,   433,   435,   437,   438,   439,   444,   445,   446,
     447,   454,   455,   456,   462,   463,   464,   469,   470,   471,
     476,   477,   481,   482,   485,   488,   490,   492,   494,   497,
     499,   500,   507,   508,   510,   513,   514,   517,   522,   524,
     526,   527,   533,   534,   539,   540,   542,   545,   548,   549,
     551,   552,   556,   557,   561,   565,   568,   569,   571,   574,
     575,   578,   580,   581,   583,   586,   589,   590,   593,   595,
     597,   599,   601,   603,   604,   609,   614,   616,   618,   620,
     622,   624,   625,   627,   629,   632,   634,   636,   638,   640,
     642,   644,   646,   648,   650,   652,   654,   656,   658,   660,
     662,   665,   668,   669,   672,   675,   678,   679,   682,   684,
     687,   690,   693,   696,   699,   702,   705,   708,   711,   712,
     714,   716,   719,   721,   723,   726,   729,   730,   732,   735,
     738,   741,   742,   745,   748,   749,   752,   755,   758,   761,
     763,   765,   767,   769,   771,   773,   775,   777,   779,   783,
     788,   793,   800,   805,   810,   815,   820,   823,   826,   835,
     842,   849,   856,   861,   866,   871,   876,   878,   880,   882,
     886,   888,   896,   897,   899,   902,   905,   911,   914,   917,
     920,   923,   926,   927,   936,   938,   940,   945,   946,   948,
     951,   952,   954,   957,   960,   962,   964,   965,   967,   969,
     971,   973,   975,   977,   979,   981,   983,   985,   987,   989,
     991,   993,   995,   997,   999,  1001,  1003,  1005,  1007,  1009,
    1011,  1013
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   382,   382,   388,   389,   394,   395,   396,   397,   402,
     406,   408,   412,   414,   418,   424,   426,   424,   436,   443,
     446,   454,   456,   454,   466,   474,   477,   484,   487,   492,
     499,   502,   507,   514,   517,   520,   523,   526,   529,   532,
     536,   541,   544,   552,   555,   562,   570,   577,   580,   588,
     591,   598,   601,   606,   613,   620,   621,   625,   631,   637,
     644,   651,   653,   657,   664,   667,   672,   675,   680,   683,
     688,   692,   696,   703,   706,   713,   716,   719,   722,   728,
     734,   737,   744,   749,   756,   760,   768,   770,   778,   781,
     789,   797,   798,   805,   809,   817,   820,   825,   828,   832,
     838,   846,   851,   855,   862,   865,   871,   871,   880,   883,
     890,   890,   899,   902,   905,   908,   911,   914,   917,   920,
     926,   930,   935,   942,   948,   949,   950,   951,   952,   955,
     957,   961,   962,   965,   967,   971,   971,   980,   980,   989,
     995,   998,  1002,  1009,  1012,  1020,  1027,  1030,  1034,  1040,
    1043,  1049,  1055,  1062,  1062,  1074,  1075,  1080,  1084,  1086,
    1091,  1092,  1096,  1098,  1103,  1107,  1110,  1115,  1115,  1125,
    1128,  1125,  1139,  1143,  1145,  1150,  1155,  1159,  1162,  1166,
    1167,  1168,  1169,  1170,  1174,  1176,  1174,  1191,  1193,  1195,
    1191,  1206,  1208,  1206,  1217,  1219,  1217,  1229,  1232,  1229,
    1242,  1242,  1256,  1258,  1262,  1273,  1274,  1275,  1279,  1287,
    1291,  1291,  1300,  1303,  1310,  1316,  1318,  1325,  1332,  1336,
    1339,  1339,  1349,  1349,  1357,  1359,  1364,  1369,  1373,  1375,
    1379,  1379,  1382,  1382,  1389,  1394,  1398,  1400,  1405,  1409,
    1411,  1416,  1420,  1422,  1427,  1432,  1436,  1438,  1442,  1449,
    1453,  1460,  1461,  1465,  1465,  1478,  1503,  1506,  1509,  1512,
    1515,  1522,  1525,  1530,  1534,  1541,  1542,  1546,  1549,  1553,
    1556,  1562,  1563,  1567,  1570,  1573,  1576,  1579,  1580,  1586,
    1591,  1600,  1607,  1610,  1618,  1627,  1634,  1637,  1644,  1649,
    1660,  1663,  1666,  1669,  1672,  1675,  1678,  1681,  1688,  1691,
    1695,  1700,  1709,  1712,  1719,  1722,  1729,  1732,  1737,  1740,
    1744,  1758,  1761,  1769,  1778,  1781,  1788,  1791,  1794,  1797,
    1801,  1802,  1803,  1804,  1807,  1810,  1813,  1816,  1820,  1826,
    1829,  1832,  1835,  1838,  1841,  1844,  1848,  1851,  1855,  1858,
    1861,  1864,  1867,  1870,  1873,  1876,  1879,  1880,  1881,  1887,
    1890,  1897,  1904,  1907,  1911,  1918,  1925,  1928,  1931,  1934,
    1937,  1940,  1944,  1944,  1956,  1960,  1964,  1970,  1973,  1977,
    1987,  1990,  1995,  2003,  2010,  2014,  2022,  2026,  2030,  2031,
    2032,  2036,  2037,  2038,  2042,  2043,  2044,  2048,  2049,  2050,
    2054,  2055,  2059,  2060,  2061,  2062,  2066,  2067,  2071,  2072,
    2076,  2077
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
     115,   116,   117,   118,   119,   120,   121,   122
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SPARQLfedParser::yyeof_ = 0;
  const int SPARQLfedParser::yylast_ = 1355;
  const int SPARQLfedParser::yynnts_ = 224;
  const int SPARQLfedParser::yyempty_ = -2;
  const int SPARQLfedParser::yyfinal_ = 7;
  const int SPARQLfedParser::yyterror_ = 1;
  const int SPARQLfedParser::yyerrcode_ = 256;
  const int SPARQLfedParser::yyntokens_ = 123;

  const unsigned int SPARQLfedParser::yyuser_token_number_max_ = 377;
  const SPARQLfedParser::token_number_type SPARQLfedParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 4145 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 2083 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
 /*** Additional Code ***/

void w3c_sw::SPARQLfedParser::error(const SPARQLfedParser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

/* START Driver (@@ stand-alone would allow it to be shared with other parsers */

namespace w3c_sw {

    SPARQLfedDriver::SPARQLfedDriver (std::string baseURI, AtomFactory* atomFactory) : 
	YaccDriver(baseURI, atomFactory), curSubject(NULL), curPredicate(NULL), 
	curBGP(NULL), curFilter(NULL), 
	curBindingsClause(NULL), curBinding(NULL), curExprList(NULL), 
	curGraphName(NULL), countStar(false), root(NULL),  unnestTree(false)
{
}

    SPARQLfedDriver::~SPARQLfedDriver ()
{
}

Operation* SPARQLfedDriver::parse(IStreamContext& in)
{
    streamname = in.nameStr;

    SPARQLfedScanner scanner(this, in.p);
    scanner.set_debug(trace_scanning);
    lexer = &scanner;

    SPARQLfedParser parser(*this);
    parser.set_debug_level(trace_parsing);
    // !!! Clear out namespaces!
    ignorePrefixFlag = false;
    parser.parse();
    return root;
}

Operation* SPARQLfedDriver::parse(std::string queryStr)
{
    IStreamContext in(queryStr.c_str(), IStreamContext::STRING);
    return parse(in);
}

void SPARQLfedDriver::executeSelect (IStreamContext& in, RdfDB* db, ResultSet* rs) {
    parse(in);
    root->execute(db, rs);
    delete root;
    root = NULL;
}
void SPARQLfedDriver::executeSelect (std::string queryStr, RdfDB* db, ResultSet* rs) {
    parse(queryStr);
    root->execute(db, rs);
    delete root;
    root = NULL;
}


} // namespace w3c_sw

/* END Driver */


