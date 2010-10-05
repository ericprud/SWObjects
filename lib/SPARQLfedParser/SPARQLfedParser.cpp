
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
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 457 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(4) - (1)].p_Project).distinctness, (yysemantic_stack_[(4) - (1)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier))));
      }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 464 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 472 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 475 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 482 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 490 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 497 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 505 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 512 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 515 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 518 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
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
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 527 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 530 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 539 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 542 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 550 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 553 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 560 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	(yyval.p_Operation) = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(5) - (2)].p_BasicGraphPattern), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 568 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 575 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm))));
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 578 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_TTerm))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 586 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 589 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 596 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 604 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(3) - (2)].p_DatasetClauses), (yysemantic_stack_[(3) - (3)].p_WhereClause));
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 611 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 623 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 629 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 635 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 642 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp ? driver.curOp : new DefaultGraphPattern(), (yysemantic_stack_[(3) - (3)].p_BindingsClause));
	driver.curOp = NULL;
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 655 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 662 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 670 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 678 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 686 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 694 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 701 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 704 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 711 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 714 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 717 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 720 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 726 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 732 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 735 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 747 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 754 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 758 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 768 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 776 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 779 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 787 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 796 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 803 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 807 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 815 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 823 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 830 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 836 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 849 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTermList) = new TTermList;
	(yyval.p_TTermList)->push_back((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 853 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTermList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_TTermList) = (yysemantic_stack_[(2) - (1)].p_TTermList);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 860 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 863 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 869 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding = new Binding();
      }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 871 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingValue) = driver.curBinding;
	  driver.curBinding = NULL;
      }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 878 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 881 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingsClause->push_back((yysemantic_stack_[(2) - (2)].p_BindingValue));
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 888 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingsClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_TTermList));
      }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 890 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingsClause) = driver.curBindingsClause;
	  driver.curBindingsClause = NULL;
      }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 897 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingsClause) = NULL;
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 903 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 906 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 909 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 912 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 915 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 918 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 928 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	OperationSet* ret = new OperationSet();
	ret->push_back((yysemantic_stack_[(1) - (1)].p_Operation));
	(yyval.p_Operation) = ret;
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 933 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	dynamic_cast<OperationSet*>((yysemantic_stack_[(2) - (1)].p_Operation))->push_back((yysemantic_stack_[(2) - (2)].p_Operation));
	(yyval.p_Operation) = (yysemantic_stack_[(2) - (1)].p_Operation);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 940 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(2) - (1)].p_Operation);
}
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 964 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 967 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert((yysemantic_stack_[(5) - (4)].p_TableOperation), (yysemantic_stack_[(5) - (5)].p_WhereClause));
      }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 978 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 981 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(4) - (3)].p_TableOperation), (yysemantic_stack_[(4) - (4)].p_WhereClause));
      }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 987 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(2) - (2)].p_URI));
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 993 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1000 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(3) - (2)].p_URIs), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1007 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URIs) = new ProductionVector<const URI*>((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1010 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_URIs)->push_back((yysemantic_stack_[(2) - (2)].p_URI));
	(yyval.p_URIs) = (yysemantic_stack_[(2) - (1)].p_URIs);
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1018 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1025 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1032 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1038 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1041 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1047 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1053 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1060 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1063 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1113 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1116 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
      }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1123 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curFilter = NULL;
      }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1127 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1130 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(5) - (3)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(5) - (4)].p_TTerm);
      }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 1173 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 1176 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  OptionalGraphPattern* ret = new OptionalGraphPattern(driver.curOp);
	  if (driver.curFilter) {
	      driver.curFilter->copyExpressionsTo(ret);
	      delete driver.curFilter;
	      driver.curFilter = NULL;
	  }
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), ret);
      }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 1188 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 1191 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 1193 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 1196 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 1204 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 1207 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 1209 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(5) - (4)].p_TTerm), driver.curOp, driver.atomFactory, false));
      }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 1216 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 1219 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 1221 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.curOp));
      }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1229 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1232 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1234 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1242 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 1247 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      }
    break;

  case 202:

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

  case 206:

/* Line 678 of lalr1.cc  */
#line 1279 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 1287 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 1291 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 1293 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = NULL;
      }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 1300 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 1303 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 1310 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 1318 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 1325 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_DistExprPair).distinctness = (yysemantic_stack_[(4) - (2)].p_distinctness);
	  (yyval.p_DistExprPair).p_Expression = (yysemantic_stack_[(4) - (3)].p_Expression);
    }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 1336 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 1339 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 1341 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 1349 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 1351 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 1379 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 1382 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 1442 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 1449 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 1453 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 1465 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 1469 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 253:

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

  case 254:

/* Line 678 of lalr1.cc  */
#line 1503 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 1506 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 1509 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 1512 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 1515 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 1522 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 1530 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 1534 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 1546 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 1553 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 1556 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 1567 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 1570 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 1573 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 1576 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 1580 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 1591 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 1600 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 1607 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 1610 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 1618 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
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
#line 1634 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 1637 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 287:

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

  case 288:

/* Line 678 of lalr1.cc  */
#line 1660 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 1667 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 1670 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 1673 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 1676 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 1679 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 1682 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 1685 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 1688 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 1699 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 1708 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 1711 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 1718 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 1721 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 1728 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 1736 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 1739 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 1743 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 1757 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 1760 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 1768 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 1777 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 1780 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 1787 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 1790 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 1793 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 1803 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 1806 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 1809 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 1812 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 1819 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 1825 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 1828 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 1831 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 1834 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 1837 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 1840 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 1843 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 1847 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_blank, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 1850 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 1854 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 1857 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 1860 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 1863 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 1866 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 1869 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 1872 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 1875 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 1886 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 1889 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 1896 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_regex, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 1903 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 1910 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 1917 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 1924 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 1927 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_sum, (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 1930 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_min, (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 1933 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_max, (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 1936 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_avg, (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 1939 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_sample, (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 1943 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 1945 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  // x = new ArgList($2, driver.curExprList);
	  delete driver.curExprList;
	  driver.curExprList = NULL;
	  w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // $$ = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group-concat, $3, $4.p_Expression, $4.separator));
    }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 1955 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
	driver.countStar = true;
    }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 1963 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 1969 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 1976 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 1986 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 1994 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 2002 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 2009 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 2013 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 2021 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 2823 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -448;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        21,   -73,    84,   155,  -448,  -448,  -448,  -448,    75,    91,
      73,   109,   113,   113,    30,    85,    -5,  -448,  -448,  -448,
    -448,  -448,  -448,  -448,  -448,  -448,   234,  -448,    87,  -448,
    -448,  -448,  -448,  -448,  -448,  -448,   127,  -448,  -448,  -448,
      75,  -448,  -448,  -448,     9,  -448,  -448,    73,  -448,  -448,
    -448,    73,    73,  -448,  -448,  -448,   741,  -448,  -448,  -448,
    -448,  -448,   136,  -448,  -448,  -448,  -448,    17,    17,  -448,
    -448,  -448,  -448,  -448,   831,    32,  -448,   109,  -448,  -448,
    -448,  -448,  -448,  -448,  -448,  1026,    78,   124,   130,   -20,
     -16,   149,   151,   182,   131,   183,   185,   186,   187,   196,
     203,   206,   212,   213,   216,   217,   221,   223,   223,   223,
     223,   224,   223,  -448,  -448,  -448,  -448,  -448,  -448,  -448,
    -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,
    1102,  -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,
    -448,  -448,  -448,  -448,  -448,   -58,   -14,   831,    17,  -448,
      54,     4,  -448,  -448,  -448,   131,   181,   158,  -448,  -448,
    -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,   230,
    -448,  -448,  -448,  -448,   238,  -448,  -448,  -448,  -448,  -448,
    -448,  -448,  -448,  -448,  -448,    32,  -448,  1026,  1178,  1178,
    1178,  -448,   191,  -448,  -448,  -448,  -448,   174,  -448,  -448,
    -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,   -14,
     131,  1026,  1026,  1026,  -448,  -448,  1026,  -448,  -448,  -448,
    1026,  1026,  1026,  -448,  -448,  1026,  1026,  1026,  1026,   -60,
    1026,  1026,  1026,  1026,  1026,  1026,   264,   264,  -448,  -448,
    -448,  -448,   264,  -448,  -448,    73,  -448,  -448,  -448,  -448,
     264,  -448,  -448,   247,  -448,   243,   181,   181,    73,  -448,
    -448,  -448,  -448,  -448,   257,   265,  -448,   201,  -448,  -448,
      35,   256,   831,  -448,  -448,    35,   946,    35,  -448,   254,
    -448,  -448,  -448,   -60,  -448,   255,   245,   248,  1026,  1026,
    1026,  1026,  1026,  1026,   233,   -16,  -448,  -448,    77,    11,
    -448,  -448,  -448,   262,   263,   266,  -448,   258,   260,   269,
     100,   277,   279,   273,   281,   283,   278,   284,   286,   290,
     291,   285,  -448,   563,  1026,  1026,  -448,  1026,  -448,   831,
    -448,  -448,  -448,  -448,  -448,   -60,  -448,  -448,  -448,   955,
    1255,   313,  -448,   197,  -448,   287,   946,  -448,  -448,   297,
     335,  -448,  -448,  -448,  -448,  -448,  -448,   855,  -448,  -448,
    -448,  -448,  -448,  -448,  1026,  -448,  1026,  -448,  -448,  -448,
    -448,  -448,  -448,  -448,   -16,  -448,  1026,  1026,    11,  -448,
    -448,  -448,  1026,  1026,  -448,  -448,  -448,  -448,  -448,  1026,
    1026,  1026,  -448,  -448,   306,  -448,  -448,  -448,  -448,  1026,
    -448,  -448,  1026,  -448,  -448,  -448,  -448,  1026,  -448,  -448,
     303,   305,  -448,  -448,  -448,   -15,  -448,  1026,   955,  -448,
    -448,  -448,  -448,  1255,  -448,  -448,  -448,  -448,  -448,   330,
     116,  -448,  -448,  -448,  -448,  -448,  -448,  -448,   831,   136,
    -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,
    -448,     2,   309,   317,   319,   322,  -448,    47,   321,   323,
     315,  -448,  -448,  -448,  -448,  -448,  -448,   191,  -448,  -448,
     653,   268,   272,  -448,  -448,   336,   338,   320,   325,  -448,
    -448,  -448,  1026,  -448,  1026,  -448,  -448,   181,  -448,  -448,
    -448,  -448,  1255,   297,  -448,  -448,  -448,  -448,  -448,  -448,
    -448,  -448,  -448,  -448,  -448,  -448,   333,   108,    24,  -448,
     334,  -448,  -448,   653,  -448,   337,  -448,  -448,  -448,  -448,
    -448,  -448,  -448,  -448,  -448,  -448,    35,  -448,   946,  -448,
      75,  -448,   339,  -448,  -448,  -448,   131,  -448,  -448,   831,
     131,  -448,   301,  -448,   340,  -448,    23,  -448,  -448,  -448,
    -448,  -448,   946,  -448,  -448,  -448,   136,   136,  -448,   131,
    -448,  -448,   324,  -448,  -448,  -448,  -448,  -448,  -448,   131,
    -448,   332,   204,  1200,   131,  -448,  -448,  -448,  -448,  -448,
     643,  -448,  -448,  -448,  -448,  -448,  -448,  -448,   131,  -448,
    -448,  -448
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        10,     0,     0,     0,    12,    11,    14,     1,     0,   134,
       0,   139,   148,   148,    26,     0,     0,    19,     2,     3,
       5,    19,     6,     7,     8,     4,   119,   120,   128,   123,
     130,   131,   125,   124,   126,   127,     9,   166,   136,   135,
       0,   394,   397,   396,   145,   142,   395,     0,   138,   140,
     149,     0,     0,    24,    25,    27,     0,   220,    19,    49,
     269,   270,    48,    19,    46,   267,   268,    60,    60,   121,
     129,   122,    15,    13,   157,    50,   132,     0,   146,   141,
     143,   151,   150,   147,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   388,   389,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   390,   392,   391,   393,    39,    40,
      42,    23,    35,    32,    34,   344,   345,   346,    33,    36,
      37,   376,   377,   378,    38,   374,     0,   222,    60,    47,
      50,     0,    61,    20,    52,     0,    63,     0,   254,   255,
     256,   257,   258,   251,   398,   399,   276,   172,   158,   176,
     230,   250,   249,   260,     0,   228,   265,   266,   272,   273,
     274,   271,   275,   137,    51,    50,   144,     0,     0,     0,
       0,   324,    29,   277,   280,   284,   286,   288,   298,   309,
     312,   317,   318,   319,   325,   320,   321,   322,   323,   368,
       0,     0,     0,     0,   348,   334,     0,   217,   335,   216,
       0,     0,     0,   152,   352,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   210,   210,   355,   356,
     357,   358,   210,   359,    41,     0,   372,   373,   375,   370,
     210,   207,   206,     0,   223,   226,    63,    63,     0,    53,
      54,    55,    56,    58,   111,     0,    18,    65,    64,    16,
       0,   168,   157,   177,   174,   240,   259,     0,   133,     0,
     315,   316,   314,     0,    30,     0,   278,   282,     0,     0,
       0,     0,     0,     0,     0,     0,   287,   289,   299,   311,
     369,   367,   353,     0,     0,     0,   218,     0,     0,     0,
     157,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   211,     0,     0,     0,   371,     0,   221,   222,
     227,   224,    44,    45,    57,     0,    59,   112,   100,     0,
       0,    67,    66,     0,   248,     0,   259,   247,   167,   161,
       0,   173,   175,   241,   231,   239,   264,   259,   261,   263,
     229,   326,    28,    31,     0,   281,     0,   285,   290,   291,
     292,   293,   294,   295,     0,   296,     0,     0,   304,   310,
     300,   301,     0,     0,   313,   332,   333,   347,   213,     0,
       0,     0,   154,    21,     0,   155,   164,   327,   328,     0,
     330,   331,     0,   340,   341,   342,   343,     0,   362,   363,
       0,     0,   360,   208,   225,     0,   101,     0,    71,    72,
      75,    77,    74,    78,    79,    81,   205,   203,   204,     0,
      69,    68,    17,   252,   237,   244,   246,   162,   157,     0,
     253,   262,   279,   283,   297,   306,   307,   305,   308,   302,
     303,     0,     0,     0,     0,    60,   153,   156,     0,     0,
     350,   354,   215,   213,   213,   109,   102,    29,    73,    80,
       0,     0,     0,    62,    70,    94,    96,   232,   242,   171,
     169,   219,     0,   214,     0,   337,   338,    63,   185,   189,
     183,   192,     0,   161,   165,   159,   178,   181,   182,   179,
     180,   196,   160,   329,   339,   351,     0,   365,     0,   107,
       0,    87,    88,    82,    83,     0,    85,    86,    90,    91,
      98,    99,    92,    95,    93,    97,   234,   238,   259,   245,
       0,   212,     0,    22,   186,   190,     0,   193,   202,   157,
       0,   349,     0,   366,     0,   209,     0,    76,    84,    89,
     235,   236,   259,   243,   170,   336,     0,     0,   184,     0,
     163,   200,     0,   361,   110,   105,   108,   233,   187,     0,
     194,   197,     0,     0,     0,   191,   198,   201,   364,   117,
       0,   103,   118,   114,   115,   116,   113,   188,     0,   106,
     104,   199
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,
    -448,  -448,    12,  -448,  -448,    74,  -448,  -448,  -448,   -82,
    -448,   259,  -448,  -448,  -448,  -448,  -448,  -448,  -118,  -448,
    -448,  -448,  -448,  -448,   133,   -59,  -448,  -246,  -448,  -448,
    -448,  -448,  -448,  -448,   -30,  -448,  -448,   -31,  -448,  -448,
    -120,  -448,  -448,  -448,  -448,  -448,  -448,   -79,   -81,  -448,
    -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,  -182,  -448,
    -448,   373,  -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,
    -448,  -448,  -448,  -448,  -448,  -448,  -448,   387,  -448,   326,
    -153,  -448,  -448,  -448,  -259,  -448,   -92,  -448,  -448,   -39,
    -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,
    -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,
    -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,  -448,  -447,
     -51,   193,  -448,  -206,   -56,  -302,    18,  -276,  -448,  -448,
    -448,  -448,    76,  -448,  -448,  -448,  -135,  -448,  -448,  -195,
    -448,  -448,  -448,  -448,  -448,  -448,  -145,  -448,  -448,  -119,
    -116,  -269,  -448,  -448,  -448,  -448,  -448,  -448,  -251,  -260,
     -13,    -1,  -448,   388,  -448,  -448,  -448,    48,  -448,  -448,
      45,  -448,  -448,  -448,    60,  -448,  -448,    37,  -448,  -448,
    -448,  -203,  -448,  -205,     7,  -323,   -28,  -448,  -448,  -448,
    -448,  -448,   -18,  -448,  -448,  -448,  -448,  -448,  -448,   -52,
    -448,  -448,  -448,    13,  -448,   120,   121,    25,  -152,   -10,
    -448,  -448
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,    18,    19,     3,     4,    36,     5,    73,   157,
     343,    20,    67,   392,   455,    21,    55,    56,   284,   285,
     128,   129,   130,   131,    22,    23,    62,    63,   183,    24,
     153,   259,   260,   261,   262,   184,   155,   266,   267,   341,
     430,   473,   268,   418,   419,   342,   423,   424,   431,   513,
     514,   515,   516,   517,   474,   522,   524,   475,   476,   336,
     415,   580,   566,   573,   546,   337,   509,   338,   581,    25,
      26,    27,    28,    71,    29,    30,   185,    40,    31,    75,
      32,    48,    33,    44,    78,    79,    34,    51,    35,    49,
     224,   310,   394,   395,   167,   493,   438,   494,   457,    38,
      74,   349,   350,   530,   351,   271,   168,   273,   274,   495,
     496,   536,   497,   534,   556,   574,   498,   535,   557,   499,
     537,   559,   500,   501,   540,   577,   588,   571,   502,   425,
     426,   252,   464,   323,   483,   451,   238,   218,   219,   388,
      58,   147,   253,   254,   330,   331,   169,   277,   275,   345,
     550,   551,   527,   477,   354,   355,   434,   529,   478,   435,
     346,   170,   171,   270,   172,   173,   174,   357,   436,   175,
     347,   191,   177,   192,   193,   365,   286,   194,   367,   287,
     195,   196,   296,   297,   197,   198,   378,   384,   448,   379,
     298,   199,   299,   200,   201,   202,   203,   215,   135,   506,
     136,   137,   204,   463,   410,   543,   544,   205,   301,   206,
     247,   248,   249,   207,   141,   142,   143,   208,   145,   209,
      46,   182
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SPARQLfedParser::yytable_ninf_ = -260;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        45,    76,   264,    64,   139,   132,    66,   356,   154,   156,
     332,   333,   255,   352,    59,    65,   359,   427,    77,   375,
     213,   465,   178,   518,   216,   358,   250,   258,   134,   245,
     382,   324,   257,    68,    80,     1,   325,    81,   138,   151,
       6,    82,    83,   481,   327,   538,   146,    53,    54,   149,
     482,   396,    66,   488,   489,   133,   152,   302,    60,    61,
     564,    65,   246,   565,   181,   545,   518,   278,   -60,   140,
     148,   152,   482,   176,   383,   150,   151,   356,   139,   132,
     353,   144,   360,  -195,     7,   344,   359,   179,   356,   256,
     -60,   490,   491,   152,   492,   178,    39,   359,   444,   180,
     427,   214,   134,    60,    61,   217,   441,   251,    41,    42,
      43,    37,   138,    60,    61,    47,    14,    41,    42,    43,
     146,    57,    41,    42,    43,    50,   239,   240,   241,   133,
     243,   158,   159,   160,   161,   162,    70,   181,   376,   377,
    -259,   263,    72,   140,   471,   472,   176,   427,    41,    42,
      43,   163,   210,    60,    61,   144,   482,   542,     8,     9,
     179,   507,   508,    10,   211,    11,    12,   223,    13,   427,
     212,    14,   180,   445,   446,    15,    16,   449,   450,   479,
     118,   119,   120,   121,   122,   123,    41,    42,    43,   220,
     427,   221,   549,    17,   255,   280,   281,   282,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    41,    42,    43,   164,   165,    60,    61,
     178,   166,   222,   225,   178,   226,   227,   228,   315,   288,
     289,   290,   291,   292,   293,   326,   229,     8,     9,   294,
     295,   533,    10,   230,    11,    12,   231,    13,   263,    41,
      42,    43,   232,   233,    60,    61,   234,   235,   178,   356,
      66,   236,   181,   237,   242,    66,   181,    66,   359,    65,
     265,   176,   269,   272,    65,   176,    65,   178,   276,   283,
     560,   322,   362,   356,   328,   179,   329,   335,   420,   179,
     339,   340,   359,   348,   178,   361,   363,   180,   364,   374,
     181,   180,   366,   385,   386,   178,   389,   387,   390,   176,
     432,   422,   428,   124,   125,   126,   127,   391,   397,   181,
     398,   399,   400,   179,   401,   403,   402,   404,   176,   146,
     146,   405,   406,   407,   416,   180,   181,   429,   421,   433,
     437,   439,   179,   456,   461,   176,   462,   181,   368,   369,
     370,   371,   372,   373,   180,   470,   176,   484,   485,   179,
     486,   152,   503,   482,   504,   472,   471,   420,   520,   526,
     179,   180,   521,   528,   541,   547,   562,   187,   576,   572,
     555,   563,   180,   558,   393,   510,   178,   561,   468,   244,
     422,   334,   469,   548,   523,   428,   487,   525,   590,    69,
      52,   539,   300,   186,   505,   414,   570,   567,   146,   553,
     552,   443,   442,   146,   466,   447,   575,   421,   380,   381,
     578,   587,     0,     0,     0,     0,   480,     0,   181,    66,
       0,     0,     0,     0,     0,   591,     0,   176,    65,     0,
       0,     0,   428,     0,     0,     0,     0,     0,     0,     0,
       0,   179,     0,     0,     0,     0,     0,     0,     0,     0,
     146,     0,     0,   180,   428,     0,     0,     0,     0,   519,
       0,     0,     0,     0,     0,     0,   178,     0,     0,     0,
       0,     0,   146,     0,     0,   428,     0,   178,     0,     0,
       0,   554,     0,     0,     0,     0,     0,     0,     0,     0,
     178,     0,     0,   146,     0,     0,     0,     0,     0,     0,
       0,     0,   519,     0,     0,     0,    66,     0,   181,     0,
       0,   583,     0,     0,     0,    65,     0,   176,   583,   181,
       0,     0,     0,     0,     0,     0,     0,     0,   176,     0,
       0,   179,   181,   568,   569,     0,    66,    66,     0,     0,
       0,   176,   179,   180,     0,    65,    65,     0,     0,     0,
       0,     0,     0,   586,   180,   179,     0,     0,     0,     0,
     586,     0,   582,     0,     0,   279,     0,   180,     0,   582,
       0,     0,   408,     0,     0,     0,   584,     0,     0,     0,
       0,     0,     0,   584,     0,     0,     0,     0,   585,   303,
     304,   305,     0,   187,   306,   585,     0,     0,   307,   308,
     309,     0,     0,   311,   312,   313,   314,     0,   316,   317,
     318,   319,   320,   321,   188,   189,     0,   190,    86,     0,
      87,    88,    89,    90,    91,    92,    93,    94,     0,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,     0,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    41,    42,    43,   511,
     512,    60,    61,     0,   589,   579,     0,     0,     0,     0,
       0,     0,     0,   187,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   409,   411,   412,     0,   413,     0,     0,    86,     0,
      87,    88,    89,    90,    91,    92,    93,    94,     0,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
       0,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    41,    42,    43,     0,
      84,    60,    61,     0,     0,     0,    41,    42,    43,     0,
       0,    60,    61,     0,     0,     0,     0,   452,   453,   454,
       0,    85,     0,     0,     0,     0,     0,   458,     0,     0,
     459,     0,     0,     0,     0,   460,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   467,    86,     0,    87,    88,
      89,    90,    91,    92,    93,    94,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    41,    42,    43,     0,     0,    60,
      61,     0,   158,   159,   160,   161,   162,     0,     0,     0,
     531,  -259,   532,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   163,     0,     0,     0,   158,   159,   160,   161,
     162,     0,     0,     0,     0,     0,   440,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    41,    42,    43,   164,   165,    60,
      61,     0,   166,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,    41,    42,
      43,   164,   165,    60,    61,     0,   166,   158,   159,   160,
     161,   162,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   417,     0,   163,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      86,     0,    87,    88,    89,    90,    91,    92,    93,    94,
       0,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,     0,     0,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    41,
      42,    43,   164,   165,    60,    61,   187,   166,    41,    42,
      43,     0,     0,    60,    61,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   188,   189,     0,
     190,    86,     0,    87,    88,    89,    90,    91,    92,    93,
      94,     0,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,     0,     0,     0,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    41,
      42,    43,    85,     0,    60,    61,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,     0,    87,
      88,    89,    90,    91,    92,    93,    94,     0,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,     0,
       0,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    41,    42,    43,   187,     0,
      60,    61,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   579,    86,     0,    87,    88,    89,    90,    91,
      92,    93,    94,     0,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,     0,     0,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    41,    42,    43,     0,   187,    60,    61,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    41,    42,    43,     0,     0,    60,    61,
      86,     0,    87,    88,    89,    90,    91,    92,    93,    94,
       0,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,    42,
      43
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        10,    40,   155,    16,    56,    56,    16,   276,    67,    68,
     256,   257,   147,   272,    19,    16,   276,   340,     9,   295,
      40,    36,    74,   470,    40,   276,    40,    23,    56,    87,
      19,   237,   150,    21,    44,    14,   242,    47,    56,    22,
     113,    51,    52,    41,   250,   492,    56,    17,    18,    62,
      48,   310,    62,     6,     7,    56,    39,   210,   118,   119,
      37,    62,   120,    40,    74,    41,   513,   185,    36,    56,
      58,    39,    48,    74,    63,    63,    22,   346,   130,   130,
     275,    56,   277,    36,     0,    50,   346,    74,   357,   148,
      36,    44,    45,    39,    47,   147,     5,   357,   374,    74,
     423,   121,   130,   118,   119,   121,   357,   121,   113,   114,
     115,    36,   130,   118,   119,     6,    16,   113,   114,   115,
     130,    36,   113,   114,   115,    12,   108,   109,   110,   130,
     112,    31,    32,    33,    34,    35,    49,   147,    61,    62,
      40,   151,    15,   130,    28,    29,   147,   470,   113,   114,
     115,    51,    74,   118,   119,   130,    48,    49,     3,     4,
     147,   463,   464,     8,    40,    10,    11,    36,    13,   492,
      40,    16,   147,   376,   377,    20,    21,   382,   383,   438,
     103,   104,   105,   106,   107,   108,   113,   114,   115,    40,
     513,    40,   515,    38,   329,   188,   189,   190,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     272,   121,    40,    40,   276,    40,    40,    40,   229,    55,
      56,    57,    58,    59,    60,   245,    40,     3,     4,    65,
      66,   487,     8,    40,    10,    11,    40,    13,   258,   113,
     114,   115,    40,    40,   118,   119,    40,    40,   310,   528,
     270,    40,   272,    40,    40,   275,   276,   277,   528,   270,
      89,   272,   114,    43,   275,   276,   277,   329,    40,    88,
     539,    17,   283,   552,    37,   272,    43,    30,   339,   276,
      25,    90,   552,    37,   346,    41,    41,   272,    53,    66,
     310,   276,    54,    41,    41,   357,    48,    41,    48,   310,
     113,   339,   340,   109,   110,   111,   112,    48,    41,   329,
      41,    48,    41,   310,    41,    41,    48,    41,   329,   339,
     340,    41,    41,    48,   335,   310,   346,    24,   339,    52,
      43,     6,   329,    37,    41,   346,    41,   357,   288,   289,
     290,   291,   292,   293,   329,    25,   357,    48,    41,   346,
      41,    39,    41,    48,    41,    29,    28,   418,   100,    49,
     357,   346,   100,    48,    41,    41,    75,    40,    46,    55,
      41,    41,   357,   536,   310,   467,   438,   540,   418,   130,
     418,   258,   423,   513,   475,   423,   455,   476,   580,    26,
      13,   493,   209,    77,   460,   329,   559,   552,   418,   528,
     526,   366,   364,   423,   415,   378,   569,   418,   298,   298,
     572,   574,    -1,    -1,    -1,    -1,   439,    -1,   438,   439,
      -1,    -1,    -1,    -1,    -1,   588,    -1,   438,   439,    -1,
      -1,    -1,   470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   438,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     470,    -1,    -1,   438,   492,    -1,    -1,    -1,    -1,   470,
      -1,    -1,    -1,    -1,    -1,    -1,   528,    -1,    -1,    -1,
      -1,    -1,   492,    -1,    -1,   513,    -1,   539,    -1,    -1,
      -1,   530,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     552,    -1,    -1,   513,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   513,    -1,    -1,    -1,   526,    -1,   528,    -1,
      -1,   573,    -1,    -1,    -1,   526,    -1,   528,   580,   539,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   539,    -1,
      -1,   528,   552,   556,   557,    -1,   556,   557,    -1,    -1,
      -1,   552,   539,   528,    -1,   556,   557,    -1,    -1,    -1,
      -1,    -1,    -1,   573,   539,   552,    -1,    -1,    -1,    -1,
     580,    -1,   573,    -1,    -1,   187,    -1,   552,    -1,   580,
      -1,    -1,    19,    -1,    -1,    -1,   573,    -1,    -1,    -1,
      -1,    -1,    -1,   580,    -1,    -1,    -1,    -1,   573,   211,
     212,   213,    -1,    40,   216,   580,    -1,    -1,   220,   221,
     222,    -1,    -1,   225,   226,   227,   228,    -1,   230,   231,
     232,   233,   234,   235,    61,    62,    -1,    64,    65,    -1,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,    26,
      27,   118,   119,    -1,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   323,   324,   325,    -1,   327,    -1,    -1,    65,    -1,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,    -1,
      19,   118,   119,    -1,    -1,    -1,   113,   114,   115,    -1,
      -1,   118,   119,    -1,    -1,    -1,    -1,   389,   390,   391,
      -1,    40,    -1,    -1,    -1,    -1,    -1,   399,    -1,    -1,
     402,    -1,    -1,    -1,    -1,   407,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   417,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    -1,
      -1,    -1,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    -1,    -1,   118,
     119,    -1,    31,    32,    33,    34,    35,    -1,    -1,    -1,
     482,    40,   484,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    -1,   121,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,    -1,   121,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    40,   121,   113,   114,
     115,    -1,    -1,   118,   119,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,
      64,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    -1,    -1,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    40,    -1,   118,   119,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      -1,    -1,    -1,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    40,    -1,
     118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    -1,    -1,    -1,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,    40,   118,   119,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,    -1,   118,   119,
      65,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
     115
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    14,   123,   126,   127,   129,   113,     0,     3,     4,
       8,    10,    11,    13,    16,    20,    21,    38,   124,   125,
     133,   137,   146,   147,   151,   191,   192,   193,   194,   196,
     197,   200,   202,   204,   208,   210,   128,    36,   221,     5,
     199,   113,   114,   115,   205,   341,   342,     6,   203,   211,
      12,   209,   209,    17,    18,   138,   139,    36,   262,    19,
     118,   119,   148,   149,   292,   293,   341,   134,   134,   193,
      49,   195,    15,   130,   222,   201,   221,     9,   206,   207,
     341,   341,   341,   341,    19,    40,    65,    67,    68,    69,
      70,    71,    72,    73,    74,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   142,   143,
     144,   145,   252,   293,   318,   320,   322,   323,   324,   331,
     335,   336,   337,   338,   339,   340,   341,   263,   134,   292,
     134,    22,    39,   152,   157,   158,   157,   131,    31,    32,
      33,    34,    35,    51,   116,   117,   121,   216,   228,   268,
     283,   284,   286,   287,   288,   291,   293,   294,   331,   335,
     339,   341,   343,   150,   157,   198,   211,    40,    61,    62,
      64,   293,   295,   296,   299,   302,   303,   306,   307,   313,
     315,   316,   317,   318,   324,   329,   331,   335,   339,   341,
      74,    40,    40,    40,   121,   319,    40,   121,   259,   260,
      40,    40,    40,    36,   212,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,   258,   258,
     258,   258,    40,   258,   143,    87,   120,   332,   333,   334,
      40,   121,   253,   264,   265,   268,   157,   150,    23,   153,
     154,   155,   156,   341,   212,    89,   159,   160,   164,   114,
     285,   227,    43,   229,   230,   270,    40,   269,   150,   295,
     316,   316,   316,    88,   140,   141,   298,   301,    55,    56,
      57,    58,    59,    60,    65,    66,   304,   305,   312,   314,
     253,   330,   212,   295,   295,   295,   295,   295,   295,   295,
     213,   295,   295,   295,   295,   293,   295,   295,   295,   295,
     295,   295,    17,   255,   255,   255,   341,   255,    37,    43,
     266,   267,   159,   159,   156,    30,   181,   187,   189,    25,
      90,   161,   167,   132,    50,   271,   282,   292,    37,   223,
     224,   226,   216,   271,   276,   277,   283,   289,   290,   291,
     271,    41,   293,    41,    53,   297,    54,   300,   306,   306,
     306,   306,   306,   306,    66,   259,    61,    62,   308,   311,
     337,   338,    19,    63,   309,    41,    41,    41,   261,    48,
      48,    48,   135,   137,   214,   215,   216,    41,    41,    48,
      41,    41,    48,    41,    41,    41,    41,    48,    19,   295,
     326,   295,   295,   295,   264,   182,   293,    40,   165,   166,
     252,   293,   318,   168,   169,   251,   252,   317,   318,    24,
     162,   170,   113,    52,   278,   281,   290,    43,   218,     6,
      41,   290,   299,   302,   259,   313,   313,   309,   310,   315,
     315,   257,   295,   295,   295,   136,    37,   220,   295,   295,
     295,    41,    41,   325,   254,    36,   293,   295,   166,   169,
      25,    28,    29,   163,   176,   179,   180,   275,   280,   216,
     292,    41,    48,   256,    48,    41,    41,   157,     6,     7,
      44,    45,    47,   217,   219,   231,   232,   234,   238,   241,
     244,   245,   250,    41,    41,   256,   321,   257,   257,   188,
     141,    26,    27,   171,   172,   173,   174,   175,   251,   293,
     100,   100,   177,   180,   178,   179,    49,   274,    48,   279,
     225,   295,   295,   159,   235,   239,   233,   242,   251,   218,
     246,    41,    49,   327,   328,    41,   186,    41,   172,   317,
     272,   273,   282,   281,   221,    41,   236,   240,   212,   243,
     216,   212,    75,    41,    37,    40,   184,   278,   292,   292,
     212,   249,    55,   185,   237,   212,    46,   247,   340,    42,
     183,   190,   293,   331,   335,   339,   341,   212,   248,    41,
     190,   212
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
     134,   136,   135,   137,   138,   138,   139,   139,   140,   141,
     141,   142,   143,   143,   143,   143,   143,   143,   143,   143,
     144,   144,   145,   145,   146,   147,   148,   148,   149,   149,
     150,   150,   151,   152,   153,   153,   154,   155,   156,   157,
     158,   158,   159,   160,   160,   161,   161,   162,   162,   163,
     163,   164,   165,   165,   166,   166,   166,   166,   167,   168,
     168,   169,   170,   171,   171,   172,   172,   173,   173,   174,
     175,   175,   176,   176,   177,   177,   178,   178,   179,   180,
     181,   182,   182,   183,   183,   185,   184,   186,   186,   188,
     187,   189,   189,   190,   190,   190,   190,   190,   190,   191,
     192,   192,   193,   194,   194,   194,   194,   194,   195,   195,
     196,   196,   198,   197,   199,   199,   201,   200,   202,   203,
     203,   204,   205,   205,   206,   207,   207,   208,   209,   209,
     210,   211,   213,   212,   214,   214,   215,   216,   216,   217,
     217,   218,   218,   219,   220,   220,   222,   221,   224,   225,
     223,   226,   227,   227,   228,   229,   230,   230,   231,   231,
     231,   231,   231,   233,   232,   235,   236,   237,   234,   239,
     240,   238,   242,   243,   241,   245,   246,   244,   248,   247,
     249,   249,   250,   251,   251,   251,   252,   253,   254,   253,
     255,   255,   256,   257,   257,   258,   259,   260,   261,   260,
     263,   262,   264,   264,   265,   266,   267,   267,   269,   268,
     270,   268,   271,   272,   273,   273,   274,   275,   275,   276,
     277,   277,   278,   279,   280,   280,   281,   282,   282,   283,
     283,   285,   284,   286,   287,   287,   287,   287,   287,   288,
     288,   289,   289,   290,   290,   291,   291,   292,   292,   293,
     293,   294,   294,   294,   294,   294,   294,   295,   296,   297,
     298,   298,   299,   300,   301,   301,   302,   303,   304,   304,
     305,   305,   305,   305,   305,   305,   305,   305,   306,   307,
     308,   308,   309,   309,   310,   310,   311,   311,   311,   312,
     312,   313,   314,   314,   315,   315,   315,   315,   316,   316,
     316,   316,   316,   316,   316,   316,   317,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   319,   319,   320,
     321,   321,   322,   323,   324,   324,   324,   324,   324,   324,
     325,   324,   326,   326,   327,   328,   328,   329,   330,   330,
     331,   332,   333,   333,   334,   334,   335,   335,   335,   336,
     336,   336,   337,   337,   337,   338,   338,   338,   339,   339,
     340,   340,   340,   340,   341,   341,   342,   342,   343,   343
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SPARQLfedParser::yyr2_[] =
  {
         0,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       0,     1,     0,     2,     2,     0,     0,     5,     4,     0,
       2,     0,     4,     3,     1,     1,     0,     1,     2,     0,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     5,     5,     1,     2,     1,     1,
       0,     1,     3,     2,     1,     1,     1,     2,     1,     3,
       0,     1,     4,     0,     1,     0,     1,     0,     1,     0,
       1,     3,     1,     2,     1,     1,     4,     1,     2,     1,
       2,     1,     3,     1,     2,     1,     1,     1,     1,     2,
       1,     1,     2,     2,     0,     1,     0,     1,     2,     2,
       1,     1,     2,     1,     2,     0,     4,     0,     2,     0,
       6,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     0,     1,
       1,     1,     0,     5,     0,     1,     0,     4,     2,     0,
       1,     3,     1,     2,     2,     0,     1,     3,     0,     1,
       3,     2,     0,     4,     1,     1,     2,     0,     1,     1,
       1,     0,     1,     3,     0,     2,     0,     5,     0,     0,
       5,     3,     0,     2,     2,     2,     0,     1,     1,     1,
       1,     1,     1,     0,     3,     0,     0,     0,     6,     0,
       0,     5,     0,     0,     4,     0,     0,     4,     0,     3,
       0,     2,     2,     1,     1,     1,     2,     1,     0,     6,
       0,     1,     2,     0,     2,     4,     1,     1,     0,     5,
       0,     4,     0,     1,     2,     2,     0,     1,     0,     3,
       0,     3,     3,     2,     0,     1,     2,     0,     2,     1,
       0,     1,     2,     2,     0,     2,     1,     1,     1,     1,
       1,     0,     4,     4,     1,     1,     1,     1,     1,     0,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       0,     2,     2,     2,     0,     2,     1,     2,     0,     1,
       2,     2,     2,     2,     2,     2,     2,     3,     1,     2,
       1,     1,     2,     2,     0,     1,     2,     2,     2,     0,
       2,     2,     0,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     4,     4,     6,
       4,     4,     4,     4,     2,     2,     8,     6,     6,     6,
       4,     4,     4,     4,     1,     1,     1,     3,     1,     7,
       0,     1,     2,     3,     5,     2,     2,     2,     2,     2,
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
  "GT_MINUS", "GT_DIVIDE", "GT_NOT", "IT_NOT", "IT_IN", "IT_IRI", "IT_URI",
  "IT_BNODE", "IT_COALESCE", "IT_IF", "IT_STRLANG", "IT_STRDT",
  "IT_EXISTS", "IT_SEPARATOR", "IT_STR", "IT_LANG", "IT_LANGMATCHES",
  "IT_DATATYPE", "IT_BOUND", "IT_sameTerm", "IT_isIRI", "IT_isURI",
  "IT_isBLANK", "IT_isLITERAL", "IT_REGEX", "GT_DTYPE", "IT_AS",
  "IT_GROUP", "IT_HAVING", "IT_COUNT", "IT_SUM", "IT_MIN", "IT_MAX",
  "IT_AVG", "IT_GROUP_CONCAT", "IT_SAMPLE", "IT_true", "IT_false",
  "INTEGER", "DECIMAL", "DOUBLE", "INTEGER_POSITIVE", "DECIMAL_POSITIVE",
  "DOUBLE_POSITIVE", "INTEGER_NEGATIVE", "DECIMAL_NEGATIVE",
  "DOUBLE_NEGATIVE", "STRING_LITERAL1", "STRING_LITERAL_LONG1",
  "STRING_LITERAL2", "STRING_LITERAL_LONG2", "IRI_REF", "PNAME_NS",
  "PNAME_LN", "BLANK_NODE_LABEL", "ANON", "VAR1", "VAR2", "LANGTAG", "NIL",
  "$accept", "Top", "_O_QQuery_E_Or_QUpdate_E_C", "Query", "Prologue",
  "_QBaseDecl_E_Opt", "_QPrefixDecl_E_Star", "BaseDecl", "PrefixDecl",
  "$@1", "$@2", "SelectQuery", "_QDatasetClause_E_Star", "SubSelect", "@3",
  "SelectClause", "_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C",
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
  "_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_C", "$@4",
  "_Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_C_E_Star",
  "_O_QIT_BINDINGS_E_S_QVar_E_Plus_S_QGT_LCURLEY_E_S_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Star_S_QGT_RCURLEY_E_C",
  "$@5",
  "_Q_O_QIT_BINDINGS_E_S_QVar_E_Plus_S_QGT_LCURLEY_E_S_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Star_S_QGT_RCURLEY_E_C_E_Opt",
  "BindingValue", "Update", "_QUpdate1_E_Plus", "Update1",
  "_O_QModify_E_Or_QLoad_E_Or_QClear_E_Or_QDrop_E_Or_QCreate_E_C",
  "_QGT_SEMI_E_Opt", "Modify", "Insert", "@6", "_QIT_DATA_E_Opt", "Delete",
  "@7", "Clear", "_QGraphRef_E_Opt", "Load", "_QIRIref_E_Plus",
  "_O_QIT_INTO_E_S_QGraphRef_E_C", "_Q_O_QIT_INTO_E_S_QGraphRef_E_C_E_Opt",
  "Drop", "_QIT_SILENT_E_Opt", "Create", "GraphRef", "GroupGraphPattern",
  "$@8", "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C",
  "GroupGraphPatternSub", "_QTriplesBlock_E_Opt",
  "_O_QGraphPatternNotTriples_E_Or_QFilter_E_C", "_QGT_DOT_E_Opt",
  "_O_QGraphPatternNotTriples_E_Or_QFilter_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_Or_QFilter_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "GraphTemplate", "$@9",
  "_O_QIT_GRAPH_E_S_QVarOrIRIref_E_S_QGraphTemplate_E_C", "@10", "@11",
  "_O_QIT_GRAPH_E_S_QVarOrIRIref_E_S_QGraphTemplate_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QIT_GRAPH_E_S_QVarOrIRIref_E_S_QGraphTemplate_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "OptionalGraphPattern", "@12", "GraphGraphPattern", "@13", "@14", "@15",
  "ServiceGraphPattern", "@16", "@17", "MinusGraphPattern", "@18", "@19",
  "GroupOrUnionGraphPattern", "@20", "@21",
  "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@22",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "$@23", "_QIT_DISTINCT_E_Opt",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ExprAggArg",
  "ExpressionList",
  "_O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C",
  "$@24", "ConstructTemplate", "$@25", "_QConstructTriples_E_Opt",
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
  "RelationalExpression", "_QRelativeExpression_E_Opt",
  "RelativeExpression", "NumericExpression", "AdditiveExpression",
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
  "ExistsFunc", "NotExistsFunc", "Aggregate", "$@29",
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
       123,     0,    -1,   126,   124,    -1,   125,    -1,   191,    -1,
     133,    -1,   146,    -1,   147,    -1,   151,    -1,   127,   128,
      -1,    -1,   129,    -1,    -1,   128,   130,    -1,    14,   113,
      -1,    -1,    -1,    15,   131,   114,   132,   113,    -1,   137,
     134,   157,   159,    -1,    -1,   134,   152,    -1,    -1,   137,
     136,   157,   159,    -1,    16,   139,   145,    -1,    17,    -1,
      18,    -1,    -1,   138,    -1,    88,   293,    -1,    -1,   140,
      -1,    40,   295,   141,    41,    -1,   293,    -1,   324,    -1,
     318,    -1,   252,    -1,   331,    -1,   335,    -1,   339,    -1,
     142,    -1,   143,    -1,   144,   143,    -1,   144,    -1,    19,
      -1,    20,   262,   134,   157,   159,    -1,    21,   149,   134,
     150,   159,    -1,   292,    -1,   148,   292,    -1,   148,    -1,
      19,    -1,    -1,   157,    -1,    38,   134,   157,    -1,    22,
     153,    -1,   154,    -1,   155,    -1,   156,    -1,    23,   156,
      -1,   341,    -1,   158,   212,   181,    -1,    -1,    39,    -1,
     160,   161,   162,   163,    -1,    -1,   164,    -1,    -1,   167,
      -1,    -1,   170,    -1,    -1,   176,    -1,    89,    25,   165,
      -1,   166,    -1,   165,   166,    -1,   318,    -1,   252,    -1,
      40,   295,   141,    41,    -1,   293,    -1,    90,   168,    -1,
     169,    -1,   168,   169,    -1,   251,    -1,    24,    25,   171,
      -1,   172,    -1,   171,   172,    -1,   174,    -1,   175,    -1,
      26,    -1,    27,    -1,   173,   317,    -1,   251,    -1,   293,
      -1,   179,   177,    -1,   180,   178,    -1,    -1,   180,    -1,
      -1,   179,    -1,    28,   100,    -1,    29,   100,    -1,   189,
      -1,   293,    -1,   182,   293,    -1,   190,    -1,   183,   190,
      -1,    -1,    40,   185,   183,    41,    -1,    -1,   186,   184,
      -1,    -1,    30,   182,    36,   188,   186,    37,    -1,    -1,
     187,    -1,   341,    -1,   331,    -1,   335,    -1,   339,    -1,
      42,    -1,   293,    -1,   192,    -1,   193,    -1,   192,   193,
      -1,   194,   195,    -1,   196,    -1,   204,    -1,   202,    -1,
     208,    -1,   210,    -1,    -1,    49,    -1,   197,    -1,   200,
      -1,    -1,     4,   199,   221,   198,   150,    -1,    -1,     5,
      -1,    -1,     3,   221,   201,   150,    -1,    10,   203,    -1,
      -1,   211,    -1,     8,   205,   207,    -1,   341,    -1,   205,
     341,    -1,     9,   211,    -1,    -1,   206,    -1,    13,   209,
     341,    -1,    -1,    12,    -1,    11,   209,   341,    -1,     6,
     341,    -1,    -1,    36,   213,   214,    37,    -1,   135,    -1,
     215,    -1,   216,   220,    -1,    -1,   228,    -1,   231,    -1,
     250,    -1,    -1,    43,    -1,   217,   218,   216,    -1,    -1,
     220,   219,    -1,    -1,    36,   222,   216,   227,    37,    -1,
      -1,    -1,   224,     6,   292,   225,   221,    -1,   223,   218,
     216,    -1,    -1,   227,   226,    -1,   268,   230,    -1,    43,
     216,    -1,    -1,   229,    -1,   232,    -1,   241,    -1,   244,
      -1,   234,    -1,   238,    -1,    -1,    44,   233,   212,    -1,
      -1,    -1,    -1,     6,   235,   236,   292,   237,   212,    -1,
      -1,    -1,     7,   239,   240,   292,   212,    -1,    -1,    -1,
      45,   242,   243,   212,    -1,    -1,    -1,   245,   246,   212,
     249,    -1,    -1,    46,   248,   212,    -1,    -1,   249,   247,
      -1,    47,   251,    -1,   317,    -1,   318,    -1,   252,    -1,
     341,   253,    -1,   121,    -1,    -1,    40,   255,   295,   254,
     257,    41,    -1,    -1,    17,    -1,    48,   295,    -1,    -1,
     257,   256,    -1,    40,   255,   295,    41,    -1,   260,    -1,
     121,    -1,    -1,    40,   295,   261,   257,    41,    -1,    -1,
      36,   263,   264,    37,    -1,    -1,   265,    -1,   268,   267,
      -1,    43,   264,    -1,    -1,   266,    -1,    -1,   291,   269,
     271,    -1,    -1,   283,   270,   276,    -1,   282,   278,   275,
      -1,   282,   278,    -1,    -1,   272,    -1,    49,   273,    -1,
      -1,   275,   274,    -1,   277,    -1,    -1,   271,    -1,   281,
     280,    -1,    48,   281,    -1,    -1,   280,   279,    -1,   290,
      -1,   292,    -1,    50,    -1,   286,    -1,   284,    -1,    -1,
      51,   285,   271,    52,    -1,   288,    40,   289,    41,    -1,
      31,    -1,    32,    -1,    33,    -1,    34,    -1,    35,    -1,
      -1,   287,    -1,   290,    -1,   289,   290,    -1,   291,    -1,
     283,    -1,   293,    -1,   294,    -1,   293,    -1,   341,    -1,
     118,    -1,   119,    -1,   341,    -1,   331,    -1,   335,    -1,
     339,    -1,   343,    -1,   121,    -1,   296,    -1,   299,   298,
      -1,    53,   299,    -1,    -1,   298,   297,    -1,   302,   301,
      -1,    54,   302,    -1,    -1,   301,   300,    -1,   303,    -1,
     306,   304,    -1,    -1,   305,    -1,    55,   306,    -1,    56,
     306,    -1,    57,   306,    -1,    58,   306,    -1,    59,   306,
      -1,    60,   306,    -1,    66,   259,    -1,    65,    66,   259,
      -1,   307,    -1,   313,   312,    -1,   337,    -1,   338,    -1,
      19,   315,    -1,    63,   315,    -1,    -1,   309,    -1,    61,
     313,    -1,    62,   313,    -1,   308,   310,    -1,    -1,   312,
     311,    -1,   315,   314,    -1,    -1,   314,   309,    -1,    64,
     316,    -1,    61,   316,    -1,    62,   316,    -1,   316,    -1,
     317,    -1,   318,    -1,   329,    -1,   331,    -1,   335,    -1,
     339,    -1,   293,    -1,   324,    -1,    40,   295,    41,    -1,
      76,    40,   295,    41,    -1,    77,    40,   295,    41,    -1,
      78,    40,   295,    48,   295,    41,    -1,    79,    40,   295,
      41,    -1,    80,    40,   293,    41,    -1,    67,    40,   295,
      41,    -1,    68,    40,   295,    41,    -1,    69,   319,    -1,
      70,   259,    -1,    71,    40,   295,    48,   295,    48,   295,
      41,    -1,    72,    40,   295,    48,   295,    41,    -1,    73,
      40,   295,    48,   295,    41,    -1,    81,    40,   295,    48,
     295,    41,    -1,    82,    40,   295,    41,    -1,    83,    40,
     295,    41,    -1,    84,    40,   295,    41,    -1,    85,    40,
     295,    41,    -1,   320,    -1,   322,    -1,   323,    -1,    40,
     295,    41,    -1,   121,    -1,    86,    40,   295,    48,   295,
     321,    41,    -1,    -1,   256,    -1,    74,   212,    -1,    65,
      74,   212,    -1,    91,    40,   255,   326,    41,    -1,    92,
     258,    -1,    93,   258,    -1,    94,   258,    -1,    95,   258,
      -1,    97,   258,    -1,    -1,    96,    40,   255,   295,   325,
     257,   328,    41,    -1,    19,    -1,   295,    -1,    49,    75,
      55,   340,    -1,    -1,   327,    -1,   341,   330,    -1,    -1,
     253,    -1,   340,   334,    -1,    87,   341,    -1,   120,    -1,
     332,    -1,    -1,   333,    -1,   336,    -1,   337,    -1,   338,
      -1,   100,    -1,   101,    -1,   102,    -1,   103,    -1,   104,
      -1,   105,    -1,   106,    -1,   107,    -1,   108,    -1,    98,
      -1,    99,    -1,   109,    -1,   111,    -1,   110,    -1,   112,
      -1,   113,    -1,   342,    -1,   115,    -1,   114,    -1,   116,
      -1,   117,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SPARQLfedParser::yyprhs_[] =
  {
         0,     0,     3,     6,     8,    10,    12,    14,    16,    18,
      21,    22,    24,    25,    28,    31,    32,    33,    39,    44,
      45,    48,    49,    54,    58,    60,    62,    63,    65,    68,
      69,    71,    76,    78,    80,    82,    84,    86,    88,    90,
      92,    94,    97,    99,   101,   107,   113,   115,   118,   120,
     122,   123,   125,   129,   132,   134,   136,   138,   141,   143,
     147,   148,   150,   155,   156,   158,   159,   161,   162,   164,
     165,   167,   171,   173,   176,   178,   180,   185,   187,   190,
     192,   195,   197,   201,   203,   206,   208,   210,   212,   214,
     217,   219,   221,   224,   227,   228,   230,   231,   233,   236,
     239,   241,   243,   246,   248,   251,   252,   257,   258,   261,
     262,   269,   270,   272,   274,   276,   278,   280,   282,   284,
     286,   288,   291,   294,   296,   298,   300,   302,   304,   305,
     307,   309,   311,   312,   318,   319,   321,   322,   327,   330,
     331,   333,   337,   339,   342,   345,   346,   348,   352,   353,
     355,   359,   362,   363,   368,   370,   372,   375,   376,   378,
     380,   382,   383,   385,   389,   390,   393,   394,   400,   401,
     402,   408,   412,   413,   416,   419,   422,   423,   425,   427,
     429,   431,   433,   435,   436,   440,   441,   442,   443,   450,
     451,   452,   458,   459,   460,   465,   466,   467,   472,   473,
     477,   478,   481,   484,   486,   488,   490,   493,   495,   496,
     503,   504,   506,   509,   510,   513,   518,   520,   522,   523,
     529,   530,   535,   536,   538,   541,   544,   545,   547,   548,
     552,   553,   557,   561,   564,   565,   567,   570,   571,   574,
     576,   577,   579,   582,   585,   586,   589,   591,   593,   595,
     597,   599,   600,   605,   610,   612,   614,   616,   618,   620,
     621,   623,   625,   628,   630,   632,   634,   636,   638,   640,
     642,   644,   646,   648,   650,   652,   654,   656,   658,   661,
     664,   665,   668,   671,   674,   675,   678,   680,   683,   684,
     686,   689,   692,   695,   698,   701,   704,   707,   711,   713,
     716,   718,   720,   723,   726,   727,   729,   732,   735,   738,
     739,   742,   745,   746,   749,   752,   755,   758,   760,   762,
     764,   766,   768,   770,   772,   774,   776,   780,   785,   790,
     797,   802,   807,   812,   817,   820,   823,   832,   839,   846,
     853,   858,   863,   868,   873,   875,   877,   879,   883,   885,
     893,   894,   896,   899,   903,   909,   912,   915,   918,   921,
     924,   925,   934,   936,   938,   943,   944,   946,   949,   950,
     952,   955,   958,   960,   962,   963,   965,   967,   969,   971,
     973,   975,   977,   979,   981,   983,   985,   987,   989,   991,
     993,   995,   997,   999,  1001,  1003,  1005,  1007,  1009,  1011
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   382,   382,   388,   389,   394,   395,   396,   397,   402,
     406,   408,   412,   414,   418,   424,   426,   424,   436,   443,
     446,   454,   454,   464,   472,   475,   482,   485,   490,   497,
     500,   505,   512,   515,   518,   521,   524,   527,   530,   534,
     539,   542,   550,   553,   560,   568,   575,   578,   586,   589,
     596,   599,   604,   611,   618,   619,   623,   629,   635,   642,
     649,   651,   655,   662,   665,   670,   673,   678,   681,   686,
     690,   694,   701,   704,   711,   714,   717,   720,   726,   732,
     735,   742,   747,   754,   758,   766,   768,   776,   779,   787,
     795,   796,   803,   807,   815,   818,   823,   826,   830,   836,
     844,   849,   853,   860,   863,   869,   869,   878,   881,   888,
     888,   897,   900,   903,   906,   909,   912,   915,   918,   924,
     928,   933,   940,   946,   947,   948,   949,   950,   953,   955,
     959,   960,   964,   964,   972,   974,   978,   978,   987,   993,
     996,  1000,  1007,  1010,  1018,  1025,  1028,  1032,  1038,  1041,
    1047,  1053,  1060,  1060,  1072,  1073,  1078,  1082,  1084,  1089,
    1090,  1094,  1096,  1101,  1105,  1108,  1113,  1113,  1123,  1127,
    1123,  1138,  1142,  1144,  1149,  1154,  1158,  1161,  1165,  1166,
    1167,  1168,  1169,  1173,  1173,  1188,  1191,  1193,  1188,  1204,
    1207,  1204,  1216,  1219,  1216,  1229,  1232,  1229,  1242,  1242,
    1256,  1258,  1262,  1273,  1274,  1275,  1279,  1287,  1291,  1291,
    1300,  1303,  1310,  1316,  1318,  1325,  1332,  1336,  1339,  1339,
    1349,  1349,  1357,  1359,  1364,  1369,  1373,  1375,  1379,  1379,
    1382,  1382,  1389,  1394,  1398,  1400,  1405,  1409,  1411,  1416,
    1420,  1422,  1427,  1432,  1436,  1438,  1442,  1449,  1453,  1460,
    1461,  1465,  1465,  1478,  1503,  1506,  1509,  1512,  1515,  1522,
    1525,  1530,  1534,  1541,  1542,  1546,  1549,  1553,  1556,  1562,
    1563,  1567,  1570,  1573,  1576,  1579,  1580,  1586,  1591,  1600,
    1607,  1610,  1618,  1627,  1634,  1637,  1644,  1649,  1660,  1663,
    1667,  1670,  1673,  1676,  1679,  1682,  1685,  1688,  1694,  1699,
    1708,  1711,  1718,  1721,  1728,  1731,  1736,  1739,  1743,  1757,
    1760,  1768,  1777,  1780,  1787,  1790,  1793,  1796,  1800,  1801,
    1802,  1803,  1806,  1809,  1812,  1815,  1819,  1825,  1828,  1831,
    1834,  1837,  1840,  1843,  1847,  1850,  1854,  1857,  1860,  1863,
    1866,  1869,  1872,  1875,  1878,  1879,  1880,  1886,  1889,  1896,
    1903,  1906,  1910,  1917,  1924,  1927,  1930,  1933,  1936,  1939,
    1943,  1943,  1955,  1959,  1963,  1969,  1972,  1976,  1986,  1989,
    1994,  2002,  2009,  2013,  2021,  2025,  2029,  2030,  2031,  2035,
    2036,  2037,  2041,  2042,  2043,  2047,  2048,  2049,  2053,  2054,
    2058,  2059,  2060,  2061,  2065,  2066,  2070,  2071,  2075,  2076
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
  const int SPARQLfedParser::yylast_ = 1370;
  const int SPARQLfedParser::yynnts_ = 222;
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
#line 4128 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 2082 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
 /*** Additional Code ***/

void w3c_sw::SPARQLfedParser::error(const SPARQLfedParser::location_type& l,
				    const std::string& constM)
{
    std::string m = constM;
    static struct { const char* from; const char* to; } tokens[] = {
	{ "GT_LPAREN",		"'('" },
	{ "GT_RPAREN",		"')'" },
	{ "GT_TIMES",		"'*'" },
	{ "GT_LCURLEY",		"'{'" },
	{ "GT_RCURLEY",		"'}'" },
	{ "GT_SEMI",		"';'" },
	{ "GT_DOT",		"'.'" },
	{ "GT_COMMA",		"','" },
	{ "GT_LBRACKET",	"'['" },
	{ "GT_RBRACKET",	"']'" },
	{ "GT_OR",		"'||'" },
	{ "GT_AND",		"'&&'" },
	{ "GT_EQUAL",		"'='" },
	{ "GT_NEQUAL",		"'!='" },
	{ "GT_LT",		"'<'" },
	{ "GT_GT",		"'>'" },
	{ "GT_LE",		"'<='" },
	{ "GT_GE",		"'>='" },
	{ "GT_DIVIDE",		"'/'" },
	{ "GT_PLUS",		"'+'" },
	{ "GT_MINUS",		"'-'" },
	{ "GT_NOT",		"'!'" },
	{ "GT_DTYPE",		"'^^'" },
	{ "GT_", "" }
    };
    for (size_t i = 0; i < sizeof(tokens)/sizeof(tokens[0]); ++i) {
	size_t p = m.find(tokens[i].from);
	if (p != std::string::npos) {
	    m.replace(p, strlen(tokens[i].from) + 1, tokens[i].to);
	    break;
	}
    }
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

Operation* SPARQLfedDriver::parse (IStreamContext& in)
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

Operation* SPARQLfedDriver::parse (std::string queryStr)
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


