
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
#line 388 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

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
#line 402 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 405 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 411 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(2) - (2)].p_Operation);
    }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 418 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(2) - (2)].p_Operation);
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 449 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 455 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 457 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 459 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 467 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(5) - (3)].p_WhereClause)->m_BindingClause = (yysemantic_stack_[(5) - (5)].p_BindingsClause);
	(yyval.p_Operation) = new Select((yysemantic_stack_[(5) - (1)].p_Project).distinctness, (yysemantic_stack_[(5) - (1)].p_Project).varSet, (yysemantic_stack_[(5) - (2)].p_DatasetClauses), (yysemantic_stack_[(5) - (3)].p_WhereClause), (yysemantic_stack_[(5) - (4)].p_SolutionModifier));
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 475 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 478 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 486 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 489 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yysemantic_stack_[(5) - (3)].p_WhereClause)->m_BindingClause = (yysemantic_stack_[(5) - (5)].p_BindingsClause);
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(5) - (1)].p_Project).distinctness, (yysemantic_stack_[(5) - (1)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(5) - (3)].p_WhereClause), (yysemantic_stack_[(5) - (4)].p_SolutionModifier))));
      }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 497 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 505 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 508 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 515 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 523 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 530 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 538 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 545 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 548 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 551 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 554 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 557 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 560 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 563 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 572 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 575 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 583 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 586 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 593 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(6) - (4)].p_WhereClause)->m_BindingClause = (yysemantic_stack_[(6) - (6)].p_BindingsClause);
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	(yyval.p_Operation) = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(6) - (2)].p_BasicGraphPattern), (yysemantic_stack_[(6) - (3)].p_DatasetClauses), (yysemantic_stack_[(6) - (4)].p_WhereClause), (yysemantic_stack_[(6) - (5)].p_SolutionModifier));
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 602 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(6) - (4)].p_WhereClause))
	    (yysemantic_stack_[(6) - (4)].p_WhereClause)->m_BindingClause = (yysemantic_stack_[(6) - (6)].p_BindingsClause);
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(6) - (2)].p_VarSet), (yysemantic_stack_[(6) - (3)].p_DatasetClauses), (yysemantic_stack_[(6) - (4)].p_WhereClause), (yysemantic_stack_[(6) - (5)].p_SolutionModifier));
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 611 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm))));
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 614 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_TTerm))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 622 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 625 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 632 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 640 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(4) - (3)].p_WhereClause)->m_BindingClause = (yysemantic_stack_[(4) - (4)].p_BindingsClause);
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause));
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 648 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 660 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 666 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 672 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 679 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp ? driver.curOp : new DefaultGraphPattern(), NULL);
	driver.curOp = NULL;
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 693 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 700 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 708 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 716 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 724 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 732 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 739 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 742 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 749 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 752 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 755 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 758 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 764 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 770 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 773 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 785 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 792 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 796 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 806 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 814 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 817 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 825 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 834 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 841 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 845 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 853 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 861 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 868 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 874 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 887 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTermList) = new TTermList;
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 890 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTermList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_TTermList) = (yysemantic_stack_[(2) - (1)].p_TTermList);
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 897 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 900 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 906 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding = new Binding();
      }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 908 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingValue) = driver.curBinding;
	  driver.curBinding = NULL;
      }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 912 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding = new Binding();
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 918 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 921 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingsClause->push_back((yysemantic_stack_[(2) - (2)].p_BindingValue));
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 928 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingsClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_TTermList));
      }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 930 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingsClause) = driver.curBindingsClause;
	  driver.curBindingsClause = NULL;
      }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 937 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingsClause) = NULL;
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 944 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 947 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 950 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 953 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 956 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 959 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 969 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	OperationSet* ret = driver.root ? dynamic_cast<OperationSet*>(driver.root) : new OperationSet();
	ret->push_back((yysemantic_stack_[(2) - (2)].p_Operation));
	driver.root = ret;
      }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 973 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Operation) = driver.root;
	}
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1007 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(3) - (2)].p_URI), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1014 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1021 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1028 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1034 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1037 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1043 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1049 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1055 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1061 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1067 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1073 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert(driver.curOp, NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1081 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete(driver.curOp, NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1089 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete(driver.curOp, NULL);
	driver.curOp = NULL;
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1097 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(5) - (1)].p_URI))
	    w3c_sw_NEED_IMPL("WITH <URI> (DELETE INSERT?|INSERT) ...");
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(5) - (2)].p_DeleteInsert).del, (yysemantic_stack_[(5) - (2)].p_DeleteInsert).ins, new WhereClause(driver.curOp, NULL));
	driver.curOp = NULL;
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1106 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1112 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1119 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1126 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 1130 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 1138 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("_QUsingClause_E_Star");
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1144 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Delete) = new Delete(driver.curOp, NULL);
	driver.curOp = NULL;
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1151 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = new Insert(driver.curOp, NULL);
	driver.curOp = NULL;
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1158 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1164 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1167 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1173 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 1176 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1187 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 1193 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 1196 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("DEFAULT");
      }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 1199 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("NAMED");
      }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 1202 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("ALL");
      }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 1242 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curFilter = NULL;
      }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 1246 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 1249 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 1252 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1274 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1277 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 1357 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 1360 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 220:

/* Line 678 of lalr1.cc  */
#line 1372 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 1375 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 1377 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 1380 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 1388 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 1391 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 1393 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(5) - (4)].p_TTerm), driver.curOp, driver.atomFactory, false));
      }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 1400 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Bind(driver.curOp, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 1406 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 1409 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 1411 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.curOp));
      }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 1419 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 1422 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 1424 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 1432 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 1437 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 1452 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    if (driver.curOp == NULL)
		driver.ensureBasicGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 1469 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 1477 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 1481 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 1483 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = NULL;
      }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 1490 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 1493 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 1500 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 1508 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 1522 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 1525 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 1527 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 1535 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 1537 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 1565 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 1568 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 1628 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 1635 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 1639 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 1647 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 1650 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 1656 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 1667 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 1695 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 1722 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 1729 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 1740 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 1747 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 1783 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 1786 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 1789 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 1792 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 1850 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 1854 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 1863 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 352:

/* Line 678 of lalr1.cc  */
#line 1888 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 1891 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 1894 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 1897 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 1900 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 1907 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 1915 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 1919 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 1931 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 1938 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 1941 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 1952 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 1955 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 1958 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 1961 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 1965 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 1976 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 1985 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 1992 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 1995 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 2003 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 2012 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 2019 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 2022 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 2034 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_GeneralComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_GeneralComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_GeneralComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 2045 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 2052 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 2055 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 2058 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 2061 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 2064 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 2067 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 2070 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 2073 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 2084 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 2093 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 2096 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 2103 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 2106 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 2113 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 2121 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 2124 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 2128 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 407:

/* Line 678 of lalr1.cc  */
#line 2142 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 2145 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 2153 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 2162 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 2165 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 2172 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 2175 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 2178 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 2188 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 2191 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 2194 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 2197 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 2204 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 2210 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 2213 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 2216 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 2219 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 2222 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 2225 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 2228 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 2232 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_blank, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 2235 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 2238 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 2241 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ciel, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 2244 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 2247 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 2250 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::XPATH_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 2254 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlen, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 2257 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ucase, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 2260 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lcase, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 2263 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encodeForUri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 2266 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 2269 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strStarts, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 2272 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strEnds, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 2275 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 2278 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 2281 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 2284 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 2287 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 2290 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 2293 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 2296 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 2299 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 2302 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 2305 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha224, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 2308 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 2311 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 2314 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 2317 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 2321 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 2324 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 2327 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 2330 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 2333 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 2336 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 2339 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 2342 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 2345 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 2356 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 2359 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 2366 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_regex, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 2373 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 2380 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 2386 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 2393 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 2400 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 2403 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 2407 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 2409 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  // x = new ArgList($2, driver.curExprList);
	  delete driver.curExprList;
	  driver.curExprList = NULL;
	  w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // $$ = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group-concat, $3, $4.p_Expression, $4.separator));
    }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 2419 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
	driver.countStar = true;
    }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 2427 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 2430 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 2433 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 2436 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 2439 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 2445 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 2451 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 2458 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 2468 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 2476 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 2484 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 2491 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 2495 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 2503 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 3394 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -771;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        51,   -85,    75,  -771,   293,  -771,  -771,  -771,  -771,  -771,
    -771,    70,    66,    66,    66,    70,    66,    66,    47,    47,
      66,    47,  -771,    25,  -771,  -771,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,  -771,  -771,   136,    84,  -771,
    -771,  -771,    72,  -771,  -771,    68,    88,    68,  -771,    29,
      29,   887,  -771,  -771,    29,  -771,   188,    61,    24,  -771,
    -771,  -771,  -771,  -771,  -771,  -771,    53,   106,   106,  -771,
     107,  -771,  -771,  -771,    88,  -771,  -771,    70,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,  -771,  -771,    46,    70,    69,
    -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,  -771,   131,  -771,  -771,   142,
    -771,  -771,  -771,  -771,   151,  -771,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,  -771,   -63,  -771,  -771,    87,  -771,  -771,
    -771,  1223,  -771,  -771,  -771,   152,  -771,  -771,  -771,  -771,
      16,    16,    59,  -771,  -771,   887,  -771,  -771,   -10,  -771,
    -771,    52,  -771,  -771,    29,  -771,    29,   191,  -771,   206,
     887,  -771,  -771,   191,  1381,   191,    70,  -771,  -771,  -771,
    -771,    29,  -771,  1540,   123,   174,   182,   -12,     4,   190,
     192,   200,   220,   218,   222,   230,   233,   235,   247,   248,
     250,   254,   258,   259,     4,   262,  -771,  -771,  -771,  -771,
     265,  -771,   268,   279,   280,    95,   283,   179,   305,   311,
     320,   323,   325,   326,   329,   330,   333,   336,   340,   343,
     349,   350,   352,   353,   354,   358,   359,   362,   366,   370,
    -771,  -771,  1660,  -771,  -771,  -771,  -771,  -771,  -771,  -771,
    -771,  -771,   372,  -771,  -771,  -771,    10,   887,    16,  -771,
      17,    31,  -771,  -771,   194,   220,   315,   261,  -771,  -771,
     227,   220,    35,  -771,  -771,  -771,  -771,  -771,   361,  1381,
    -771,  -771,   371,   413,  -771,  -771,  -771,  -771,  -771,  1416,
    -771,  -771,  -771,  -771,  -771,  1540,  1780,  1780,  1780,  -771,
     331,  -771,  -771,  -771,  -771,   368,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,  -771,  -771,    10,   220,  1540,
    1540,  1540,  -771,  -771,  1540,  -771,  -771,  1540,  1540,  1540,
    -771,  -771,  1540,  1540,  1540,  1540,    82,  1540,  1540,  1540,
    1540,  1540,  1540,  -771,   404,   404,  1540,  1540,  1540,  -771,
    1540,  -771,  1540,  1540,  1540,  1540,  1540,  1540,  1540,  1540,
    1540,  1540,  1540,  1540,  1540,  1540,  1540,  1540,  1540,  1540,
    1540,  1540,  1540,  1540,  -771,   404,   404,  -771,  -771,   399,
    -771,   394,   315,   315,  -771,    70,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,  -771,   414,   194,   347,  -771,
    -771,  -771,    70,  -771,  -771,   284,  -771,  -771,  -771,  -771,
    -771,   887,   152,  -771,  -771,   401,  -771,  -771,  -771,    82,
    -771,   406,   387,   391,  1540,  1540,  1540,  1540,  1540,  1540,
     382,     4,  -771,  -771,   306,    13,  -771,  -771,  -771,   409,
     410,   419,  -771,   417,   421,   422,   805,   420,   426,   423,
     433,   434,   428,   436,   437,   439,   440,   435,  -771,  1082,
    1540,   441,   443,   450,   452,   454,   463,   464,   458,   466,
     467,   468,   462,   470,   471,   472,   486,   497,   498,   499,
     500,   501,   502,   496,   504,   505,   506,  1540,  1540,  -771,
     887,  -771,  -771,   194,   194,  -771,    -5,  1900,  -771,  2002,
     524,  -771,  -771,  -771,   503,   507,  -771,  -771,  -771,  -771,
    -771,  1540,  -771,  1540,  -771,  -771,  -771,  -771,  -771,  -771,
    -771,     4,  -771,  1540,  1540,    13,  -771,  -771,  -771,  1540,
    1540,  -771,  -771,  -771,  -771,  -771,  1540,  1540,  1540,  -771,
    -771,   512,  -771,  -771,  -771,   508,  -771,  -771,  -771,  -771,
    1540,  -771,  -771,  1540,  -771,  -771,  -771,  -771,  1540,  -771,
    -771,   509,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,
    1540,  -771,  -771,  -771,  1540,  -771,  -771,  -771,  1540,  -771,
    -771,  -771,  -771,  -771,  -771,  1540,  -771,  -771,  -771,   513,
    -771,  -771,  -771,  -771,  -771,  -771,  1540,  1900,  -771,  -771,
    -771,  -771,  2002,  -771,  -771,  -771,  -771,  -771,   528,   224,
    -771,   191,  -771,  1381,  -771,   520,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,    21,   510,   518,   519,   522,
    -771,   277,   887,  -771,  -771,   191,    45,   521,   523,   515,
    -771,   516,   525,   515,   526,   527,  -771,  -771,  -771,   331,
    -771,  -771,  1357,   427,   430,  -771,  -771,   541,   544,  -771,
    -771,  1381,  -771,  -771,  -771,  1540,  -771,  1540,  -771,  -771,
     315,  -771,  -771,  -771,  -771,  2002,   535,  -771,   371,  -771,
    -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,
     159,  -771,    79,    58,  -771,  -771,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,    99,  -771,  -771,  -771,  -771,  -771,  -771,
     536,   517,  -771,   539,  -771,   543,  -771,  -771,    39,   -17,
     547,  -771,  -771,  1357,  -771,   542,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,  -771,  -771,   887,  -771,   552,
     194,  -771,  -771,   220,  -771,  -771,  1540,   887,   220,   553,
     134,  -771,    62,  -771,  -771,  -771,  -771,  -771,  -771,  1381,
     474,   534,  -771,   -18,  -771,  -771,  -771,  -771,  -771,  -771,
     546,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,
    -771,   561,  -771,  -771,   152,   152,  -771,   220,   492,  -771,
    -771,  -771,  -771,   558,  -771,  -771,  -771,  -771,  -771,   159,
    -771,   159,  -771,   459,  -771,  -771,    12,   276,   373,  -771,
    -771,   220,  -771,    82,   559,  -771,   514,   555,  -771,  -771,
     569,  -771,   -21,  -771,  -771,  -771,   184,  -771,  -771,  -771,
    -771,  -771,  -771,   220,  -771,   566,  -771,  -771,   134,  -771,
      45,  -771,  -771,  -771,  -771,   572,  -771,  -771,  -771,  -771,
     220,  -771,  -771,  -771,  -771,  -771,  -771,  1381,  -771
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        11,     0,     0,     2,    11,    13,    12,     3,   121,    15,
       1,     0,   145,   145,   145,     0,   145,   145,     0,     0,
     145,     0,     4,     0,   122,   129,   130,   131,   135,   132,
     133,   134,   136,   137,   138,   139,   158,     0,    10,   523,
     526,   525,   142,   524,   146,     0,     0,     0,   156,   172,
     172,   182,   154,   153,   172,   152,    27,     0,     0,    20,
       5,     6,    20,     7,     8,     9,   127,     0,     0,   163,
     159,   162,    16,    14,     0,   143,   140,     0,   177,   176,
     178,   175,   144,   148,   147,   173,   170,     0,     0,     0,
     352,   353,   354,   355,   356,   349,   517,   518,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   519,   521,   520,
     522,   527,   528,   367,   368,   374,     0,   187,   183,   195,
     264,   348,   347,   358,     0,   262,   363,   364,   370,   371,
     505,   506,   507,   372,   503,   369,   373,     0,    25,    26,
      28,     0,   254,    20,    50,    49,    20,    47,   365,   366,
      61,    61,    11,   128,   123,   182,   165,   166,     0,   161,
     160,     0,   141,   174,   172,   171,   172,     0,   180,   181,
     182,   196,   193,   274,   357,     0,     0,   501,   502,   504,
     499,   172,    44,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   488,   489,   490,   491,
       0,   492,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      40,    41,    43,    24,    36,    33,    35,   471,   439,   472,
     473,    34,     0,    37,    38,    39,     0,   256,    61,    48,
      51,     0,    62,    21,   113,     0,    64,   157,   125,   126,
       0,     0,     0,   164,    17,   149,   151,   282,     0,   357,
     281,   188,   184,     0,   194,   275,   265,   273,   362,   357,
     359,   361,   263,   500,   150,     0,     0,     0,     0,   422,
      30,   375,   378,   382,   384,   386,   396,   407,   410,   415,
     416,   417,   423,   418,   419,   420,   421,   497,     0,     0,
       0,     0,   475,   432,     0,   251,   461,     0,     0,     0,
     197,   480,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   438,   246,   246,     0,     0,     0,   433,
       0,   454,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    42,   246,   246,   243,   242,     0,
     257,   260,    64,    64,    52,     0,    54,    55,    56,    57,
      59,   102,    53,   114,   101,    60,     0,   113,    66,    65,
     179,   155,     0,   167,   168,     0,   350,   271,   278,   280,
     185,   182,     0,   351,   360,     0,   413,   414,   412,     0,
      31,     0,   376,   380,     0,     0,     0,     0,     0,     0,
       0,     0,   385,   387,   397,   409,   498,   496,   481,     0,
       0,     0,   252,     0,     0,     0,   202,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   247,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
     256,   261,   258,   113,   113,    58,     0,     0,    19,     0,
      68,    67,   169,    18,   266,   276,   186,   190,   424,    29,
      32,     0,   379,     0,   383,   388,   389,   390,   391,   392,
     393,     0,   394,     0,     0,   402,   408,   398,   399,     0,
       0,   411,   430,   431,   474,   249,     0,     0,     0,   199,
      22,     0,   200,   205,   203,   209,   285,   283,   425,   426,
       0,   428,   429,     0,   466,   467,   468,   469,     0,   486,
     487,     0,   484,   470,   455,   447,   460,   453,   437,   459,
       0,   452,   436,   451,     0,   458,   450,   443,     0,   435,
     449,   442,   434,   441,   457,     0,   440,   456,   448,     0,
     244,   259,    45,    46,   111,   103,     0,    72,    73,    76,
      78,    75,    79,    80,    82,   241,   239,   240,     0,    70,
      69,   268,   272,   357,   279,     0,   377,   381,   395,   404,
     405,   403,   406,   400,   401,     0,     0,     0,     0,    61,
     198,   201,   202,   210,   207,   274,     0,     0,     0,   477,
     482,   494,     0,   477,     0,     0,   483,   249,   109,    30,
      74,    81,     0,     0,     0,    63,    71,    95,    97,   269,
     270,   357,   277,   191,   253,     0,   250,     0,   463,   464,
      64,   220,   224,   218,   228,     0,     0,   206,   184,   212,
     214,   215,   217,   213,   211,   232,   216,   208,   298,   286,
       0,   328,     0,     0,   284,   287,   289,   290,   299,   301,
     304,   313,   308,   311,   326,   300,   327,   427,   465,   478,
       0,     0,   495,     0,   444,     0,   445,   446,     0,     0,
       0,    88,    89,    83,    84,     0,    86,    87,    91,    92,
      99,   100,    93,    96,    94,    98,   267,   182,   248,     0,
     113,   221,   225,     0,   229,   238,     0,   202,     0,     0,
     336,   344,     0,   329,   331,   338,   340,   343,   314,   357,
     302,   306,   322,     0,   324,   323,   310,   312,   315,   476,
       0,   485,   479,   245,   112,   106,   108,   110,    77,    85,
      90,     0,   462,    23,     0,     0,   219,     0,     0,   204,
     236,   330,   337,     0,   333,   342,   345,   341,   296,     0,
     305,     0,   309,     0,   346,   325,     0,     0,     0,   192,
     222,     0,   230,     0,   233,   339,   335,   288,   303,   307,
       0,   319,     0,   320,   493,   119,     0,   104,   120,   116,
     117,   118,   115,     0,   226,     0,   234,   237,     0,   334,
     293,   297,   321,   316,   318,     0,   107,   105,   223,   227,
       0,   332,   291,   294,   295,   317,   235,   357,   292
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -771,  -771,  -771,  -771,  -771,    14,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,   -43,  -771,  -771,   168,  -771,  -771,  -771,
     -34,  -771,   375,  -771,  -771,  -771,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,   237,  -144,  -771,  -370,  -771,
    -771,  -771,  -771,  -771,  -771,    23,  -771,  -771,    28,  -771,
    -771,  -105,  -771,  -771,  -771,  -771,  -771,  -771,   -35,   -31,
    -388,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -199,
    -771,   479,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,
    -771,   365,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,  -771,  -771,   563,  -771,  -771,
      32,  -771,    -4,   587,   567,    71,   481,  -168,   -39,  -771,
    -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -254,  -771,
    -771,  -771,  -611,  -771,  -771,  -771,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -771,  -591,
    -135,   327,  -771,  -308,  -550,    -7,  -196,  -771,  -771,  -771,
     153,  -771,  -771,  -771,  -243,  -771,  -771,   -96,  -771,  -771,
    -771,  -771,  -771,     7,  -646,  -771,  -771,    33,    34,  -771,
    -771,  -771,  -771,  -771,  -193,  -771,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,   -42,  -771,  -771,  -771,  -150,  -771,  -771,
     -41,  -771,  -148,  -771,  -771,  -771,  -771,  -771,  -771,  -771,
    -771,  -771,  -771,  -771,  -771,  -771,  -714,  -771,  -771,  -770,
    -169,  -771,  -771,  -771,  -771,  -771,  -771,  -152,  -164,   -57,
     -24,  -771,   540,  -771,  -771,  -771,   140,  -771,  -771,   141,
    -771,  -771,  -771,    74,  -771,  -771,   130,  -771,  -771,  -771,
    -257,  -771,  -249,    60,  -474,  -138,  -771,  -771,    19,  -771,
    -771,  -771,  -115,  -771,  -771,  -771,  -771,  -771,  -771,  -771,
      -3,  -771,  -771,  -771,     0,  -771,   223,   225,     6,  -151,
     -11,  -771,  -771
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,     3,    22,    60,     4,     5,    38,     6,    73,
     161,   405,    61,   150,   539,   629,    62,   140,   141,   420,
     421,   240,   241,   242,   243,    63,    64,   145,   146,   383,
      65,   263,   386,   387,   388,   389,   264,   265,   397,   398,
     500,   609,   655,   399,   597,   598,   501,   602,   603,   610,
     723,   724,   725,   726,   727,   656,   732,   734,   657,   658,
     392,   496,   826,   777,   808,   719,   393,   648,   394,   827,
       7,     8,    66,   269,   153,   154,    24,    25,    75,    76,
      26,    45,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,   159,    69,   158,    70,    71,   273,   403,
      87,    88,    81,    82,   156,    52,   116,   117,   411,   281,
     169,   282,   283,   615,   737,   118,   171,   172,   331,   446,
     541,   542,   543,   677,   631,   544,   633,   634,   678,   679,
     743,   680,   741,   784,   833,   681,   742,   785,   682,   683,
     744,   787,   684,   685,   748,   837,   850,   814,   686,   604,
     605,   378,   647,   459,   666,   625,   326,   535,   143,   257,
     379,   380,   491,   492,   119,   175,   173,   285,   659,   660,
     612,   504,   286,   287,   407,   614,   505,   408,   279,   545,
     636,   635,   694,   759,   695,   853,   857,   854,   841,   817,
     689,   696,   697,   698,   699,   800,   760,   700,   802,   761,
     701,   766,   702,   767,   844,   823,   805,   768,   703,   704,
     753,   839,   816,   792,   793,   754,   755,   796,   756,   806,
     120,   121,   167,   122,   123,   124,   289,   409,   125,   280,
     299,   127,   300,   301,   512,   422,   302,   514,   423,   303,
     304,   432,   433,   305,   306,   525,   531,   622,   526,   434,
     307,   435,   308,   309,   310,   311,   323,   247,   710,   248,
     249,   250,   312,   641,   561,   252,   712,   713,   313,   437,
     314,   178,   179,   180,   315,   130,   131,   132,   316,   134,
     317,    43,   136
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SPARQLfedParser::yytable_ninf_ = -358;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        42,   147,   284,   246,    48,   288,   244,   266,   343,   498,
     291,   395,   493,   494,   381,   736,   843,   401,    23,   151,
     774,   687,   290,   775,   176,   606,   251,   126,   321,   271,
     803,   594,   529,   820,   148,    85,   794,   460,   261,   261,
     135,    56,    83,   144,   324,    57,    58,   149,   128,   821,
     376,   129,   845,   -61,   385,   262,   262,   133,   402,  -124,
     822,   728,   664,    59,   438,     1,   163,   487,   488,   665,
     162,   278,     9,     1,    77,    10,   530,   165,    44,   292,
     773,    74,    89,    51,   745,   690,   137,   665,   259,   709,
      53,    78,    55,   709,    77,   691,   272,   142,   690,    72,
     258,   177,   152,   260,   246,   592,   593,   244,   691,   692,
     288,    68,   795,   798,   382,   291,   384,   245,   762,   750,
     288,   148,   692,   804,   851,   291,   804,   251,   606,   751,
     256,   126,   728,    86,   149,   763,   789,   414,   253,    67,
      68,   254,   155,   148,   135,   693,   126,   255,   776,   148,
     126,   148,   128,   322,   164,   129,   149,   113,   114,   135,
     764,   133,   149,   135,   149,   293,   267,   128,   168,   325,
     129,   128,    79,    80,   129,   377,   133,   166,   606,   752,
     133,    39,    40,    41,   751,   170,   113,   114,    39,    40,
      41,   174,    39,    40,    41,   181,   275,   318,   276,   690,
     765,   606,    39,    40,    41,   138,   139,   113,   114,   691,
     274,   858,  -189,   294,   319,    39,    40,    41,   245,    39,
      40,    41,   320,   692,   391,   846,   825,    39,    40,    41,
     327,   256,   328,   126,   752,   522,    39,    40,    41,   253,
     329,   277,   254,   506,   113,   114,   135,   381,   255,   606,
     390,   780,   653,   654,   128,   126,   330,   129,   332,   693,
     349,   404,   333,   133,   400,   126,   619,   620,   135,    11,
     334,    12,    13,   335,    14,   336,   128,   546,   135,   129,
     623,   624,   547,   671,   672,   133,   128,   337,   338,   129,
     339,    39,    40,    41,   340,   133,  -157,  -157,   341,   342,
     740,    11,   344,    12,    13,   345,    14,     1,   346,    39,
      40,    41,   451,  -231,   113,   114,    39,    40,    41,   347,
     348,   673,   674,   350,   675,   618,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    39,    40,    41,   351,   352,   113,   114,    39,    40,
      41,   353,   783,   113,   114,   507,   416,   417,   418,   601,
     354,   607,   599,   355,    15,   356,   357,   523,   524,   358,
     359,    16,    17,   360,   390,    18,   361,    19,    46,    47,
     362,    49,    50,   363,    20,    54,    21,   126,   148,   364,
     365,   502,   366,   367,   368,   509,    15,   676,   369,   370,
     135,   149,   371,    16,    17,   396,   372,    18,   128,    19,
     373,   129,   375,   406,   410,   825,    20,   133,    21,   412,
     419,   458,   126,   424,   425,   426,   427,   428,   429,   107,
     108,   109,   110,   430,   431,   135,   489,   490,   499,   497,
     511,   503,   508,   128,   288,   513,   129,   510,   521,   291,
     532,   533,   133,   101,   102,   103,   104,   105,   106,   601,
     534,   548,   599,   546,   607,   536,   126,   549,   547,   537,
     538,   550,   595,   600,   551,   552,   553,   554,   555,   135,
     556,   557,   563,   558,   564,   670,   256,   128,   256,   786,
     129,   565,   288,   566,   790,   567,   133,   291,   515,   516,
     517,   518,   519,   520,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   607,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      39,    40,    41,   812,   578,   113,   114,   607,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   608,   630,
     640,   632,   611,   652,   646,   613,   663,   834,   667,   668,
     669,   262,   707,   665,   708,   711,   714,   716,   717,   781,
     654,   730,   653,   600,   731,   746,   799,   769,   546,   848,
     771,   813,   295,   547,   772,   607,   256,   148,   778,   126,
     288,   256,   770,   782,   791,   291,   856,   801,   809,   815,
     149,   807,   135,   804,   840,   836,   842,   849,   126,   855,
     128,   148,   705,   129,   540,   720,   838,   374,   779,   133,
     650,   135,   495,   735,   149,   706,   733,   847,   729,   128,
     651,   268,   129,   160,    84,   157,   270,   126,   133,   747,
     718,   256,   688,   591,   436,   661,   662,   852,   749,   818,
     135,   616,   758,   819,   617,   621,   824,   527,   128,   528,
       0,   129,   715,     0,   256,     0,     0,   133,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   706,
       0,   757,   706,     0,     0,     0,     0,     0,   288,     0,
       0,     0,     0,   291,     0,     0,     0,     0,     0,   729,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   256,   126,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,     0,     0,   135,   810,   811,     0,
       0,     0,     0,     0,   128,   126,   135,   129,     0,   757,
       0,   797,     0,   133,   128,     0,     0,   129,   135,     0,
       0,     0,     0,   133,     0,     0,   128,     0,     0,   129,
     148,   148,     0,     0,     0,   133,     0,     0,     0,     0,
       0,     0,     0,   149,   149,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   828,     0,     0,     0,   706,   835,
     706,     0,     0,     0,     0,     0,     0,   832,     0,     0,
       0,     0,   828,     0,     0,   829,     0,     0,   830,     0,
       0,     0,     0,     0,   831,   832,   705,     0,     0,     0,
       0,    56,     0,   829,     0,     0,   830,   757,     0,   706,
       0,     0,   831,   126,     0,   415,    90,    91,    92,    93,
      94,     0,     0,     0,     0,  -357,   135,     0,     0,     0,
       0,     0,     0,     0,   128,     0,    95,   129,     0,   439,
     440,   441,     0,   133,   442,     0,     0,   443,   444,   445,
       0,     0,   447,   448,   449,   450,     0,   452,   453,   454,
     455,   456,   457,     0,     0,     0,   461,   462,   463,     0,
     464,     0,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,     0,     0,     0,     0,    90,    91,
      92,    93,    94,     0,     0,     0,     0,  -357,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,     0,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    39,    40,    41,   111,   112,   113,   114,     0,
     115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   560,
     562,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   589,   590,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    39,    40,    41,   111,   112,   113,
     114,     0,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   626,   627,   628,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     637,     0,     0,   638,     0,     0,     0,     0,   639,     0,
       0,   559,     0,     0,     0,     0,     0,     0,     0,     0,
     642,     0,     0,     0,   643,     0,     0,     0,   644,     0,
       0,     0,   295,     0,     0,   645,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   649,     0,     0,     0,
       0,     0,     0,   296,   297,     0,   298,   184,     0,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,     0,
     204,     0,     0,     0,   205,   206,   207,   208,   209,   210,
     211,   212,     0,     0,     0,     0,     0,     0,     0,   213,
       0,   214,     0,     0,   215,   216,     0,   217,     0,   218,
     219,   220,     0,   221,   222,   738,   223,   739,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    39,
      40,    41,   182,     0,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   183,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   788,     0,   184,     0,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
       0,   204,     0,     0,     0,   205,   206,   207,   208,   209,
     210,   211,   212,     0,     0,     0,     0,     0,     0,     0,
     213,     0,   214,     0,     0,   215,   216,     0,   217,     0,
     218,   219,   220,     0,   221,   222,     0,   223,     0,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      39,    40,    41,   721,   722,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,    93,    94,     0,     0,     0,
       0,     0,   184,     0,   185,   186,   187,   188,   189,   190,
     191,   192,    95,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,     0,   204,     0,    90,    91,    92,
      93,    94,     0,     0,     0,     0,   212,   413,     0,     0,
       0,     0,     0,     0,   213,     0,   214,    95,     0,   215,
     216,     0,   217,     0,   218,   219,   220,     0,   221,   222,
       0,   223,     0,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,    40,    41,     0,     0,   113,
     114,     0,     0,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    39,    40,
      41,   111,   112,   113,   114,     0,   115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    39,    40,    41,   111,   112,   113,   114,
     295,   115,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   296,   297,     0,   298,   184,     0,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,     0,   204,     0,
       0,     0,   205,   206,   207,   208,   209,   210,   211,   212,
       0,     0,     0,     0,     0,     0,     0,   213,     0,   214,
       0,     0,   215,   216,     0,   217,     0,   218,   219,   220,
       0,   221,   222,     0,   223,     0,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    39,    40,    41,
     183,     0,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   184,     0,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,     0,   204,     0,
       0,     0,   205,   206,   207,   208,   209,   210,   211,   212,
       0,     0,     0,     0,     0,     0,     0,   213,     0,   214,
       0,     0,   215,   216,     0,   217,     0,   218,   219,   220,
       0,   221,   222,     0,   223,     0,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    39,    40,    41,
     295,     0,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   184,     0,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,     0,   204,     0,
       0,     0,   205,   206,   207,   208,   209,   210,   211,   212,
       0,     0,     0,     0,     0,     0,     0,   213,     0,   214,
       0,     0,   215,   216,     0,   217,     0,   218,   219,   220,
       0,   221,   222,     0,   223,     0,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    39,    40,    41,
     596,     0,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   184,     0,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,     0,   204,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   212,
       0,     0,     0,     0,     0,     0,     0,   213,     0,   214,
       0,     0,   215,   216,     0,   217,     0,   218,   219,   220,
       0,   221,   222,     0,   223,     0,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   295,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    39,    40,    41,
       0,     0,   113,   114,     0,     0,     0,   184,     0,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,     0,
     204,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   212,     0,     0,     0,     0,     0,     0,     0,   213,
       0,   214,     0,     0,   215,   216,     0,   217,     0,   218,
     219,   220,     0,   221,   222,     0,   223,     0,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
      40,    41
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        11,    58,   170,   141,    15,   174,   141,   151,   204,   397,
     174,   265,   382,   383,   257,   661,    37,   271,     4,    62,
      37,   632,   174,    40,    87,   499,   141,    51,    40,    39,
      48,    36,    19,   803,    58,     6,   750,   345,    22,    22,
      51,    16,    46,    19,    40,    20,    21,    58,    51,    37,
      40,    51,   822,    36,    23,    39,    39,    51,    23,     0,
      48,   652,    41,    38,   318,    14,    77,   375,   376,    48,
      74,   167,   157,    14,     6,     0,    63,    88,    12,   175,
      41,     9,    50,    36,   675,    40,    54,    48,   145,   639,
      19,    23,    21,   643,     6,    50,   106,    36,    40,    15,
     143,   164,    49,   146,   242,   493,   494,   242,    50,    64,
     279,     4,    50,   759,   258,   279,   260,   141,    19,    40,
     289,   145,    64,   144,   838,   289,   144,   242,   602,    50,
     141,   155,   723,   104,   145,    36,   747,   289,   141,     3,
       4,   141,    36,   167,   155,   100,   170,   141,   165,   173,
     174,   175,   155,   165,   108,   155,   167,   162,   163,   170,
      61,   155,   173,   174,   175,   176,   152,   170,    37,   165,
     170,   174,   104,   105,   174,   165,   170,   108,   652,   100,
     174,   157,   158,   159,    50,    43,   162,   163,   157,   158,
     159,    40,   157,   158,   159,   108,   164,    74,   166,    40,
     101,   675,   157,   158,   159,    17,    18,   162,   163,    50,
     158,   857,     6,   181,    40,   157,   158,   159,   242,   157,
     158,   159,    40,    64,    30,    41,    42,   157,   158,   159,
      40,   242,    40,   257,   100,   431,   157,   158,   159,   242,
      40,    50,   242,   411,   162,   163,   257,   490,   242,   723,
     261,   725,    28,    29,   257,   279,    36,   257,    40,   100,
     165,   272,    40,   257,    37,   289,   523,   524,   279,     8,
      40,    10,    11,    40,    13,    40,   279,   446,   289,   279,
     529,   530,   446,     6,     7,   279,   289,    40,    40,   289,
      40,   157,   158,   159,    40,   289,     3,     4,    40,    40,
     670,     8,    40,    10,    11,    40,    13,    14,    40,   157,
     158,   159,   336,    36,   162,   163,   157,   158,   159,    40,
      40,    44,    45,    40,    47,   521,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   165,    40,   162,   163,   157,   158,
     159,    40,   740,   162,   163,   412,   296,   297,   298,   497,
      40,   499,   497,    40,   103,    40,    40,    61,    62,    40,
      40,   110,   111,    40,   385,   114,    40,   116,    13,    14,
      40,    16,    17,    40,   123,    20,   125,   411,   412,    40,
      40,   402,    40,    40,    40,   419,   103,   120,    40,    40,
     411,   412,    40,   110,   111,    90,    40,   114,   411,   116,
      40,   411,    40,    52,    43,    42,   123,   411,   125,     6,
      89,    17,   446,    55,    56,    57,    58,    59,    60,   153,
     154,   155,   156,    65,    66,   446,    37,    43,    91,    25,
      53,   157,    41,   446,   613,    54,   446,    41,    66,   613,
      41,    41,   446,   147,   148,   149,   150,   151,   152,   597,
      41,    41,   597,   632,   602,    48,   490,    41,   632,    48,
      48,    48,   496,   497,    41,    41,    48,    41,    41,   490,
      41,    41,    41,    48,    41,   629,   497,   490,   499,   743,
     490,    41,   661,    41,   748,    41,   490,   661,   424,   425,
     426,   427,   428,   429,    41,    41,    48,    41,    41,    41,
      48,    41,    41,    41,   652,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   787,    48,   162,   163,   675,    41,    41,
      41,    41,    41,    41,    48,    41,    41,    41,    24,    37,
      41,    43,    49,    25,    41,    48,    36,   811,    48,    41,
      41,    39,    41,    48,    41,    49,    41,    41,    41,   737,
      29,   144,    28,   597,   144,    40,   102,    41,   747,   833,
      41,    89,    40,   747,    41,   723,   597,   611,    41,   613,
     759,   602,    75,    41,    41,   759,   850,    63,    37,    41,
     611,    55,   613,   144,    49,    46,    37,    41,   632,    37,
     613,   635,   636,   613,   446,   649,   102,   242,   723,   613,
     597,   632,   385,   658,   635,   636,   657,   826,   652,   632,
     602,   152,   632,    70,    47,    68,   155,   661,   632,   678,
     647,   652,   635,   490,   317,   611,   613,   840,   690,   799,
     661,   511,   693,   801,   513,   525,   807,   434,   661,   434,
      -1,   661,   643,    -1,   675,    -1,    -1,   661,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   690,
      -1,   692,   693,    -1,    -1,    -1,    -1,    -1,   857,    -1,
      -1,    -1,    -1,   857,    -1,    -1,    -1,    -1,    -1,   723,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   723,   737,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   747,    -1,    -1,   737,   784,   785,    -1,
      -1,    -1,    -1,    -1,   737,   759,   747,   737,    -1,   750,
      -1,   752,    -1,   737,   747,    -1,    -1,   747,   759,    -1,
      -1,    -1,    -1,   747,    -1,    -1,   759,    -1,    -1,   759,
     784,   785,    -1,    -1,    -1,   759,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   784,   785,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   808,    -1,    -1,    -1,   799,   813,
     801,    -1,    -1,    -1,    -1,    -1,    -1,   808,    -1,    -1,
      -1,    -1,   826,    -1,    -1,   808,    -1,    -1,   808,    -1,
      -1,    -1,    -1,    -1,   808,   826,   840,    -1,    -1,    -1,
      -1,    16,    -1,   826,    -1,    -1,   826,   838,    -1,   840,
      -1,    -1,   826,   857,    -1,   295,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    40,   857,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   857,    -1,    51,   857,    -1,   319,
     320,   321,    -1,   857,   324,    -1,    -1,   327,   328,   329,
      -1,    -1,   332,   333,   334,   335,    -1,   337,   338,   339,
     340,   341,   342,    -1,    -1,    -1,   346,   347,   348,    -1,
     350,    -1,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,    -1,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
     165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   459,
     460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   487,   488,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   536,   537,   538,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     550,    -1,    -1,   553,    -1,    -1,    -1,    -1,   558,    -1,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     570,    -1,    -1,    -1,   574,    -1,    -1,    -1,   578,    -1,
      -1,    -1,    40,    -1,    -1,   585,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   596,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    -1,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
      -1,   109,    -1,    -1,   112,   113,    -1,   115,    -1,   117,
     118,   119,    -1,   121,   122,   665,   124,   667,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,    19,    -1,   162,   163,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   746,    -1,    65,    -1,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    -1,    -1,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,   109,    -1,    -1,   112,   113,    -1,   115,    -1,
     117,   118,   119,    -1,   121,   122,    -1,   124,    -1,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,    26,    27,   162,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    51,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    -1,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    99,    41,    -1,    -1,
      -1,    -1,    -1,    -1,   107,    -1,   109,    51,    -1,   112,
     113,    -1,   115,    -1,   117,   118,   119,    -1,   121,   122,
      -1,   124,    -1,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   158,   159,    -1,    -1,   162,
     163,    -1,    -1,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,   165,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
      40,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    62,    -1,    64,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    -1,    88,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,   109,
      -1,    -1,   112,   113,    -1,   115,    -1,   117,   118,   119,
      -1,   121,   122,    -1,   124,    -1,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
      40,    -1,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    -1,    88,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,   109,
      -1,    -1,   112,   113,    -1,   115,    -1,   117,   118,   119,
      -1,   121,   122,    -1,   124,    -1,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
      40,    -1,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    -1,    88,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,   109,
      -1,    -1,   112,   113,    -1,   115,    -1,   117,   118,   119,
      -1,   121,   122,    -1,   124,    -1,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
      40,    -1,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    -1,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,   109,
      -1,    -1,   112,   113,    -1,   115,    -1,   117,   118,   119,
      -1,   121,   122,    -1,   124,    -1,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,
      -1,    -1,   162,   163,    -1,    -1,    -1,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
      -1,   109,    -1,    -1,   112,   113,    -1,   115,    -1,   117,
     118,   119,    -1,   121,   122,    -1,   124,    -1,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
     158,   159
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    14,   167,   168,   171,   172,   174,   236,   237,   157,
       0,     8,    10,    11,    13,   103,   110,   111,   114,   116,
     123,   125,   169,   171,   242,   243,   246,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   173,   157,
     158,   159,   446,   447,    12,   247,   247,   247,   446,   247,
     247,    36,   271,   271,   247,   271,    16,    20,    21,    38,
     170,   178,   182,   191,   192,   196,   238,     3,     4,   260,
     262,   263,    15,   175,     9,   244,   245,     6,    23,   104,
     105,   268,   269,   268,   269,     6,   104,   266,   267,   266,
      31,    32,    33,    34,    35,    51,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   160,   161,   162,   163,   165,   272,   273,   281,   330,
     386,   387,   389,   390,   391,   394,   396,   397,   436,   440,
     441,   442,   443,   444,   445,   446,   448,   266,    17,    18,
     183,   184,    36,   324,    19,   193,   194,   395,   396,   446,
     179,   179,    49,   240,   241,    36,   270,   270,   261,   259,
     263,   176,   268,   446,   108,   446,   108,   388,    37,   276,
      43,   282,   283,   332,    40,   331,    87,   164,   437,   438,
     439,   108,    19,    40,    65,    67,    68,    69,    70,    71,
      72,    73,    74,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    88,    92,    93,    94,    95,    96,
      97,    98,    99,   107,   109,   112,   113,   115,   117,   118,
     119,   121,   122,   124,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     187,   188,   189,   190,   316,   396,   421,   423,   425,   426,
     427,   428,   431,   436,   440,   444,   446,   325,   179,   395,
     179,    22,    39,   197,   202,   203,   202,   171,   237,   239,
     272,    39,   106,   264,   158,   266,   266,    50,   333,   344,
     395,   275,   277,   278,   273,   333,   338,   339,   386,   392,
     393,   394,   333,   446,   266,    40,    61,    62,    64,   396,
     398,   399,   402,   405,   406,   409,   410,   416,   418,   419,
     420,   421,   428,   434,   436,   440,   444,   446,    74,    40,
      40,    40,   165,   422,    40,   165,   322,    40,    40,    40,
      36,   284,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,   322,    40,    40,    40,    40,    40,   165,
      40,   165,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,   188,    40,    40,   165,   317,   326,
     327,   330,   202,   195,   202,    23,   198,   199,   200,   201,
     446,    30,   226,   232,   234,   284,    90,   204,   205,   209,
      37,   284,    23,   265,   446,   177,    52,   340,   343,   393,
      43,   274,     6,    41,   393,   398,   419,   419,   419,    89,
     185,   186,   401,   404,    55,    56,    57,    58,    59,    60,
      65,    66,   407,   408,   415,   417,   317,   435,   284,   398,
     398,   398,   398,   398,   398,   398,   285,   398,   398,   398,
     398,   396,   398,   398,   398,   398,   398,   398,    17,   319,
     319,   398,   398,   398,   398,   398,   398,   398,   398,   398,
     398,   398,   398,   398,   398,   398,   398,   398,   398,   398,
     398,   398,   398,   398,   398,   398,   398,   319,   319,    37,
      43,   328,   329,   204,   204,   201,   227,    25,   226,    91,
     206,   212,   446,   157,   337,   342,   273,   395,    41,   396,
      41,    53,   400,    54,   403,   409,   409,   409,   409,   409,
     409,    66,   322,    61,    62,   411,   414,   442,   443,    19,
      63,   412,    41,    41,    41,   323,    48,    48,    48,   180,
     182,   286,   287,   288,   291,   345,   386,   394,    41,    41,
      48,    41,    41,    48,    41,    41,    41,    41,    48,    19,
     398,   430,   398,    41,    41,    41,    41,    41,    41,    41,
      48,    41,    41,    41,    48,    41,    41,    41,    48,    41,
      41,    41,    41,    41,    41,    48,    41,    41,    41,   398,
     398,   326,   226,   226,    36,   396,    40,   210,   211,   316,
     396,   421,   213,   214,   315,   316,   420,   421,    24,   207,
     215,    49,   336,    48,   341,   279,   402,   405,   322,   416,
     416,   412,   413,   418,   418,   321,   398,   398,   398,   181,
      37,   290,    43,   292,   293,   347,   346,   398,   398,   398,
      41,   429,   398,   398,   398,   398,    41,   318,   233,   398,
     211,   214,    25,    28,    29,   208,   221,   224,   225,   334,
     335,   344,   343,    36,    41,    48,   320,    48,    41,    41,
     202,     6,     7,    44,    45,    47,   120,   289,   294,   295,
     297,   301,   304,   305,   308,   309,   314,   288,   339,   356,
      40,    50,    64,   100,   348,   350,   357,   358,   359,   360,
     363,   366,   368,   374,   375,   396,   446,    41,    41,   320,
     424,    49,   432,   433,    41,   424,    41,    41,   321,   231,
     186,    26,    27,   216,   217,   218,   219,   220,   315,   396,
     144,   144,   222,   225,   223,   224,   340,   280,   398,   398,
     204,   298,   302,   296,   306,   315,    40,   274,   310,   359,
      40,    50,   100,   376,   381,   382,   384,   446,   366,   349,
     362,   365,    19,    36,    61,   101,   367,   369,   373,    41,
      75,    41,    41,    41,    37,    40,   165,   229,    41,   217,
     420,   273,    41,   226,   299,   303,   284,   307,   398,   288,
     284,    41,   379,   380,   382,    50,   383,   446,   340,   102,
     361,    63,   364,    48,   144,   372,   385,    55,   230,    37,
     395,   395,   284,    89,   313,    41,   378,   355,   363,   368,
     385,    37,    48,   371,   445,    42,   228,   235,   396,   436,
     440,   444,   446,   300,   284,   396,    46,   311,   102,   377,
      49,   354,    37,    37,   370,   385,    41,   235,   284,    41,
     312,   382,   350,   351,   353,    37,   284,   352,   340
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
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  SPARQLfedParser::yyr1_[] =
  {
         0,   166,   167,   167,   168,   169,   170,   170,   170,   170,
     171,   172,   172,   173,   173,   174,   176,   177,   175,   178,
     179,   179,   181,   180,   182,   183,   183,   184,   184,   185,
     186,   186,   187,   188,   188,   188,   188,   188,   188,   188,
     188,   189,   189,   190,   190,   191,   192,   193,   193,   194,
     194,   195,   195,   196,   197,   198,   198,   199,   200,   201,
     202,   203,   203,   204,   205,   205,   206,   206,   207,   207,
     208,   208,   209,   210,   210,   211,   211,   211,   211,   212,
     213,   213,   214,   215,   216,   216,   217,   217,   218,   218,
     219,   220,   220,   221,   221,   222,   222,   223,   223,   224,
     225,   226,   227,   227,   228,   228,   230,   229,   229,   231,
     231,   233,   232,   234,   234,   235,   235,   235,   235,   235,
     235,   236,   238,   237,   239,   239,   240,   241,   241,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     243,   244,   245,   245,   246,   247,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   258,   259,
     259,   260,   260,   261,   261,   262,   263,   264,   265,   265,
     266,   266,   267,   267,   268,   269,   269,   269,   269,   270,
     271,   272,   273,   273,   274,   274,   275,   276,   276,   278,
     279,   280,   277,   281,   282,   283,   283,   285,   284,   286,
     286,   287,   288,   288,   289,   290,   290,   291,   292,   293,
     293,   294,   294,   294,   294,   294,   294,   294,   296,   295,
     298,   299,   300,   297,   302,   303,   301,   304,   306,   307,
     305,   309,   310,   308,   312,   311,   313,   313,   314,   315,
     315,   315,   316,   317,   318,   317,   319,   319,   320,   321,
     321,   322,   323,   322,   325,   324,   326,   326,   327,   328,
     329,   329,   331,   330,   332,   330,   333,   334,   335,   335,
     336,   337,   337,   338,   339,   339,   340,   341,   342,   342,
     343,   344,   344,   346,   345,   347,   345,   349,   348,   350,
     350,   352,   351,   353,   353,   354,   355,   355,   356,   357,
     358,   359,   360,   361,   362,   362,   363,   364,   365,   365,
     366,   367,   367,   368,   368,   369,   370,   370,   371,   371,
     372,   372,   373,   373,   373,   373,   374,   375,   375,   375,
     375,   376,   377,   378,   378,   379,   380,   380,   381,   381,
     382,   383,   383,   384,   384,   384,   385,   386,   386,   388,
     387,   389,   390,   390,   390,   390,   390,   391,   391,   392,
     392,   393,   393,   394,   394,   395,   395,   396,   396,   397,
     397,   397,   397,   397,   397,   398,   399,   400,   401,   401,
     402,   403,   404,   404,   405,   406,   407,   407,   408,   408,
     408,   408,   408,   408,   408,   408,   409,   410,   411,   411,
     412,   412,   413,   413,   414,   414,   414,   415,   415,   416,
     417,   417,   418,   418,   418,   418,   419,   419,   419,   419,
     419,   419,   419,   419,   420,   421,   421,   421,   421,   421,
     421,   421,   421,   421,   421,   421,   421,   421,   421,   421,
     421,   421,   421,   421,   421,   421,   421,   421,   421,   421,
     421,   421,   421,   421,   421,   421,   421,   421,   421,   421,
     421,   421,   421,   421,   421,   421,   421,   421,   421,   421,
     421,   421,   421,   421,   422,   422,   423,   424,   424,   425,
     426,   427,   428,   428,   429,   428,   430,   430,   431,   431,
     431,   431,   431,   432,   433,   433,   434,   435,   435,   436,
     437,   438,   438,   439,   439,   440,   440,   440,   441,   441,
     441,   442,   442,   442,   443,   443,   443,   444,   444,   445,
     445,   445,   445,   446,   446,   447,   447,   448,   448
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SPARQLfedParser::yyr2_[] =
  {
         0,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       2,     0,     1,     0,     2,     2,     0,     0,     5,     5,
       0,     2,     0,     5,     3,     1,     1,     0,     1,     2,
       0,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     6,     6,     1,     2,     1,
       1,     0,     1,     4,     2,     1,     1,     1,     2,     1,
       2,     0,     1,     4,     0,     1,     0,     1,     0,     1,
       0,     1,     3,     1,     2,     1,     1,     4,     1,     2,
       1,     2,     1,     3,     1,     2,     1,     1,     1,     1,
       2,     1,     1,     2,     2,     0,     1,     0,     1,     2,
       2,     1,     0,     2,     1,     2,     0,     4,     1,     0,
       2,     0,     6,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     0,     1,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     0,     1,     3,     0,     1,     3,     3,     5,
       5,     5,     2,     2,     2,     5,     2,     0,     1,     0,
       1,     2,     1,     0,     2,     2,     2,     2,     1,     2,
       1,     2,     0,     1,     2,     1,     1,     1,     1,     3,
       3,     2,     0,     1,     0,     1,     3,     0,     2,     0,
       0,     0,     8,     2,     2,     0,     1,     0,     4,     1,
       1,     2,     0,     1,     3,     0,     2,     2,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     3,
       0,     0,     0,     6,     0,     0,     5,     6,     0,     0,
       4,     0,     0,     4,     0,     3,     0,     2,     2,     1,
       1,     1,     2,     1,     0,     6,     0,     1,     2,     0,
       2,     1,     0,     5,     0,     4,     0,     1,     2,     2,
       0,     1,     0,     3,     0,     3,     3,     2,     0,     1,
       2,     0,     2,     1,     0,     1,     2,     2,     0,     2,
       1,     1,     1,     0,     3,     0,     3,     0,     4,     1,
       1,     0,     3,     0,     1,     2,     0,     2,     1,     1,
       1,     1,     2,     2,     0,     2,     2,     2,     0,     2,
       2,     0,     1,     1,     2,     1,     1,     2,     2,     1,
       2,     3,     1,     1,     1,     2,     1,     1,     1,     2,
       3,     1,     2,     0,     2,     2,     0,     1,     1,     3,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     0,
       4,     4,     1,     1,     1,     1,     1,     0,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     0,     2,
       2,     2,     0,     2,     1,     2,     0,     1,     2,     2,
       2,     2,     2,     2,     2,     3,     1,     2,     1,     1,
       2,     2,     0,     1,     2,     2,     2,     0,     2,     2,
       0,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     4,     6,     4,     4,
       4,     4,     2,     2,     4,     4,     4,     4,     2,     1,
       4,     4,     4,     4,     6,     6,     6,     4,     4,     4,
       4,     4,     4,     4,     2,     4,     4,     4,     4,     4,
       4,     2,     8,     6,     6,     6,     4,     4,     4,     4,
       4,     1,     1,     1,     3,     1,     7,     0,     1,     7,
       2,     3,     5,     5,     0,     7,     1,     1,     1,     1,
       1,     1,     1,     4,     0,     1,     2,     0,     1,     2,
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
  "IT_isBLANK", "IT_isLITERAL", "IT_REGEX", "GT_DTYPE", "IT_CONCAT",
  "IT_AS", "IT_GROUP", "IT_HAVING", "IT_COUNT", "IT_SUM", "IT_MIN",
  "IT_MAX", "IT_AVG", "IT_GROUP_CONCAT", "IT_SAMPLE", "IT_isNUMERIC",
  "GT_CARROT", "GT_OPT", "GT_PIPE", "IT_WITH", "IT_DEFAULT", "IT_ALL",
  "IT_USING", "IT_MD5", "IT_TO", "IT_YEAR", "IT_ADD", "IT_COPY", "IT_RAND",
  "IT_SHA512",
  "GT_DELETE_LBRACKET_SPACECHAR_TAB_RETURN_LINEFEED_RBRACKET_PLUS_WHERE",
  "IT_NOW",
  "GT_DELETE_LBRACKET_SPACECHAR_TAB_RETURN_LINEFEED_RBRACKET_PLUS_DATA",
  "IT_TIMEZONE", "IT_ROUND", "IT_SHA384", "IT_BIND", "IT_CONTAINS",
  "IT_SECONDS", "IT_MOVE", "IT_FLOOR",
  "GT_INSERT_LBRACKET_SPACECHAR_TAB_RETURN_LINEFEED_RBRACKET_PLUS_DATA",
  "IT_MINUTES", "IT_SUBSTR", "IT_SHA256", "IT_HOURS", "IT_ENCODE_FOR_URI",
  "IT_STRSTARTS", "IT_CEIL", "IT_DAY", "IT_LCASE", "IT_ABS", "IT_UCASE",
  "IT_SHA224", "IT_STRENDS", "IT_STRLEN", "IT_SHA1", "IT_MONTH", "IT_true",
  "IT_false", "INTEGER", "DECIMAL", "DOUBLE", "INTEGER_POSITIVE",
  "DECIMAL_POSITIVE", "DOUBLE_POSITIVE", "INTEGER_NEGATIVE",
  "DECIMAL_NEGATIVE", "DOUBLE_NEGATIVE", "STRING_LITERAL1",
  "STRING_LITERAL_LONG1", "STRING_LITERAL2", "STRING_LITERAL_LONG2",
  "IRI_REF", "PNAME_NS", "PNAME_LN", "BLANK_NODE_LABEL", "ANON", "VAR1",
  "VAR2", "LANGTAG", "NIL", "$accept", "Top", "QueryUnit", "Query",
  "_O_QSelectQuery_E_Or_QConstructQuery_E_Or_QDescribeQuery_E_Or_QAskQuery_E_C",
  "Prologue", "_QBaseDecl_E_Opt", "_QPrefixDecl_E_Star", "BaseDecl",
  "PrefixDecl", "$@1", "$@2", "SelectQuery", "_QDatasetClause_E_Star",
  "SubSelect", "@3", "SelectClause",
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
  "WhereClause", "_QIT_WHERE_E_Opt", "SolutionModifier",
  "_QGroupClause_E_Opt", "_QHavingClause_E_Opt", "_QOrderClause_E_Opt",
  "_QLimitOffsetClauses_E_Opt", "GroupClause", "_QGroupCondition_E_Plus",
  "GroupCondition", "HavingClause", "_QHavingCondition_E_Plus",
  "HavingCondition", "OrderClause", "_QOrderCondition_E_Plus",
  "OrderCondition", "_O_QIT_ASC_E_Or_QIT_DESC_E_C",
  "_O_QIT_ASC_E_Or_QIT_DESC_E_S_QBrackettedExpression_E_C",
  "_O_QConstraint_E_Or_QVar_E_C", "LimitOffsetClauses",
  "_QOffsetClause_E_Opt", "_QLimitClause_E_Opt", "LimitClause",
  "OffsetClause", "BindingsClause", "_QVar_E_Star",
  "_QBindingValue_E_Plus",
  "_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C",
  "$@4",
  "_Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star",
  "_O_QIT_BINDINGS_E_S_QVar_E_Star_S_QGT_LCURLEY_E_S_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_Star_S_QGT_RCURLEY_E_C",
  "$@5",
  "_Q_O_QIT_BINDINGS_E_S_QVar_E_Star_S_QGT_LCURLEY_E_S_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_Star_S_QGT_RCURLEY_E_C_E_Opt",
  "BindingValue", "UpdateUnit", "Update", "$@6", "_QUpdate_E_Opt",
  "_O_QGT_SEMI_E_S_QUpdate_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QUpdate_E_Opt_C_E_Opt", "Update1", "Load",
  "_O_QIT_INTO_E_S_QGraphRef_E_C", "_Q_O_QIT_INTO_E_S_QGraphRef_E_C_E_Opt",
  "Clear", "_QIT_SILENT_E_Opt", "Drop", "Create", "Add", "Move", "Copy",
  "InsertData", "DeleteData", "DeleteWhere", "Modify",
  "_O_QIT_WITH_E_S_QIRIref_E_C", "_Q_O_QIT_WITH_E_S_QIRIref_E_C_E_Opt",
  "_QInsertClause_E_Opt",
  "_O_QDeleteClause_E_S_QInsertClause_E_Opt_Or_QInsertClause_E_C",
  "_QUsingClause_E_Star", "DeleteClause", "InsertClause", "UsingClause",
  "_O_QIRIref_E_Or_QIT_NAMED_E_S_QIRIref_E_C", "GraphOrDefault",
  "_QIT_GRAPH_E_Opt", "GraphRef", "GraphRefAll", "QuadPattern", "QuadData",
  "Quads", "_QTriplesTemplate_E_Opt", "_QGT_DOT_E_Opt",
  "_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C_E_Star",
  "QuadsNotTriples", "@7", "@8", "$@9", "TriplesTemplate",
  "_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C_E_Opt", "GroupGraphPattern",
  "$@10", "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C",
  "GroupGraphPatternSub", "_QTriplesBlock_E_Opt",
  "_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "OptionalGraphPattern", "@11", "GraphGraphPattern", "@12", "@13", "@14",
  "ServiceGraphPattern", "@15", "@16", "Bind", "MinusGraphPattern", "@17",
  "@18", "GroupOrUnionGraphPattern", "@19", "@20",
  "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@21",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "$@22", "_QIT_DISTINCT_E_Opt",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ExpressionList", "$@23",
  "ConstructTemplate", "$@24", "_QConstructTriples_E_Opt",
  "ConstructTriples", "_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C_E_Opt", "TriplesSameSubject",
  "$@25", "$@26", "PropertyListNotEmpty", "_O_QVerb_E_S_QObjectList_E_C",
  "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "Verb", "TriplesSameSubjectPath", "$@27", "$@28",
  "PropertyListNotEmptyPath", "$@29", "_O_QVerbPath_E_Or_QVerbSimple_E_C",
  "_O_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_C", "$@30",
  "_Q_O_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_Opt_C_E_Star",
  "PropertyListPath", "VerbPath", "VerbSimple", "Path", "PathAlternative",
  "_O_QGT_PIPE_E_S_QPathSequence_E_C",
  "_Q_O_QGT_PIPE_E_S_QPathSequence_E_C_E_Star", "PathSequence",
  "_O_QGT_DIVIDE_E_S_QPathEltOrInverse_E_C",
  "_Q_O_QGT_DIVIDE_E_S_QPathEltOrInverse_E_C_E_Star", "PathElt",
  "_QPathMod_E_Opt", "PathEltOrInverse", "PathMod",
  "_O_QGT_RCURLEY_E_Or_QInteger_E_S_QGT_RCURLEY_E_C",
  "_O_QGT_COMMA_E_S_QGT_RCURLEY_E_Or_QInteger_E_S_QGT_RCURLEY_E_Or_QGT_RCURLEY_E_C",
  "_O_QInteger_E_S_QGT_COMMA_E_S_QGT_RCURLEY_E_Or_QInteger_E_S_QGT_RCURLEY_E_Or_QGT_RCURLEY_E_Or_QGT_COMMA_E_S_QInteger_E_S_QGT_RCURLEY_E_C",
  "_O_QGT_TIMES_E_Or_QGT_OPT_E_Or_QGT_PLUS_E_Or_QGT_LCURLEY_E_S_QInteger_E_S_QGT_COMMA_E_S_QGT_RCURLEY_E_Or_QInteger_E_S_QGT_RCURLEY_E_Or_QGT_RCURLEY_E_Or_QGT_COMMA_E_S_QInteger_E_S_QGT_RCURLEY_E_C",
  "PathPrimary",
  "_O_QIRIref_E_Or_QIT_a_E_Or_QGT_NOT_E_S_QPathNegatedPropertySet_E_Or_QGT_LPAREN_E_S_QPath_E_S_QGT_RPAREN_E_C",
  "PathNegatedPropertySet", "_O_QGT_PIPE_E_S_QPathOneInPropertySet_E_C",
  "_Q_O_QGT_PIPE_E_S_QPathOneInPropertySet_E_C_E_Star",
  "_O_QPathOneInPropertySet_E_S_QGT_PIPE_E_S_QPathOneInPropertySet_E_Star_C",
  "_Q_O_QPathOneInPropertySet_E_S_QGT_PIPE_E_S_QPathOneInPropertySet_E_Star_C_E_Opt",
  "_O_QPathOneInPropertySet_E_Or_QGT_LPAREN_E_S_QPathOneInPropertySet_E_S_QGT_PIPE_E_S_QPathOneInPropertySet_E_Star_Opt_S_QGT_RPAREN_E_C",
  "PathOneInPropertySet", "_O_QIRIref_E_Or_QIT_a_E_C",
  "_O_QIRIref_E_Or_QIT_a_E_Or_QGT_CARROT_E_S_QIRIref_E_Or_QIT_a_E_C",
  "Integer", "TriplesNode", "BlankNodePropertyList", "@31", "Generator",
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
  "SubstringExpression", "ExistsFunc", "NotExistsFunc", "Aggregate",
  "$@32", "_O_QGT_TIMES_E_Or_QExpression_E_C",
  "_O_QIT_SUM_E_Or_QIT_MIN_E_Or_QIT_MAX_E_Or_QIT_AVG_E_Or_QIT_SAMPLE_E_C",
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
       167,     0,    -1,   168,    -1,   236,    -1,   171,   169,    -1,
     171,   170,    -1,   178,    -1,   191,    -1,   192,    -1,   196,
      -1,   172,   173,    -1,    -1,   174,    -1,    -1,   173,   175,
      -1,    14,   157,    -1,    -1,    -1,    15,   176,   158,   177,
     157,    -1,   182,   179,   202,   204,   226,    -1,    -1,   179,
     197,    -1,    -1,   182,   181,   202,   204,   226,    -1,    16,
     184,   190,    -1,    17,    -1,    18,    -1,    -1,   183,    -1,
      89,   396,    -1,    -1,   185,    -1,    40,   398,   186,    41,
      -1,   396,    -1,   428,    -1,   421,    -1,   316,    -1,   436,
      -1,   440,    -1,   444,    -1,   187,    -1,   188,    -1,   189,
     188,    -1,   189,    -1,    19,    -1,    20,   324,   179,   202,
     204,   226,    -1,    21,   194,   179,   195,   204,   226,    -1,
     395,    -1,   193,   395,    -1,   193,    -1,    19,    -1,    -1,
     202,    -1,    38,   179,   202,   226,    -1,    22,   198,    -1,
     199,    -1,   200,    -1,   201,    -1,    23,   201,    -1,   446,
      -1,   203,   284,    -1,    -1,    39,    -1,   205,   206,   207,
     208,    -1,    -1,   209,    -1,    -1,   212,    -1,    -1,   215,
      -1,    -1,   221,    -1,    90,    25,   210,    -1,   211,    -1,
     210,   211,    -1,   421,    -1,   316,    -1,    40,   398,   186,
      41,    -1,   396,    -1,    91,   213,    -1,   214,    -1,   213,
     214,    -1,   315,    -1,    24,    25,   216,    -1,   217,    -1,
     216,   217,    -1,   219,    -1,   220,    -1,    26,    -1,    27,
      -1,   218,   420,    -1,   315,    -1,   396,    -1,   224,   222,
      -1,   225,   223,    -1,    -1,   225,    -1,    -1,   224,    -1,
      28,   144,    -1,    29,   144,    -1,   234,    -1,    -1,   227,
     396,    -1,   235,    -1,   228,   235,    -1,    -1,    40,   230,
     228,    41,    -1,   165,    -1,    -1,   231,   229,    -1,    -1,
      30,   227,    36,   233,   231,    37,    -1,    -1,   232,    -1,
     446,    -1,   436,    -1,   440,    -1,   444,    -1,    42,    -1,
     396,    -1,   237,    -1,    -1,   171,   242,   238,   241,    -1,
      -1,   237,    -1,    49,   239,    -1,    -1,   240,    -1,   243,
      -1,   246,    -1,   248,    -1,   250,    -1,   251,    -1,   252,
      -1,   249,    -1,   253,    -1,   254,    -1,   255,    -1,   256,
      -1,     8,   446,   245,    -1,     9,   268,    -1,    -1,   244,
      -1,    10,   247,   269,    -1,    -1,    12,    -1,    13,   247,
     269,    -1,    11,   247,   268,    -1,   110,   247,   266,   108,
     266,    -1,   123,   247,   266,   108,   266,    -1,   111,   247,
     266,   108,   266,    -1,   125,   271,    -1,   116,   271,    -1,
     114,   271,    -1,   258,   260,   261,    39,   284,    -1,   103,
     446,    -1,    -1,   257,    -1,    -1,   263,    -1,   262,   259,
      -1,   263,    -1,    -1,   261,   264,    -1,     3,   270,    -1,
       4,   270,    -1,   106,   265,    -1,   446,    -1,    23,   446,
      -1,   104,    -1,   267,   446,    -1,    -1,     6,    -1,     6,
     446,    -1,   268,    -1,   104,    -1,    23,    -1,   105,    -1,
      36,   272,    37,    -1,    36,   272,    37,    -1,   273,   276,
      -1,    -1,   281,    -1,    -1,    43,    -1,   277,   274,   273,
      -1,    -1,   276,   275,    -1,    -1,    -1,    -1,   278,     6,
     395,   279,    36,   280,   273,    37,    -1,   330,   283,    -1,
      43,   273,    -1,    -1,   282,    -1,    -1,    36,   285,   286,
      37,    -1,   180,    -1,   287,    -1,   288,   290,    -1,    -1,
     291,    -1,   294,   274,   288,    -1,    -1,   290,   289,    -1,
     345,   293,    -1,    43,   288,    -1,    -1,   292,    -1,   308,
      -1,   295,    -1,   305,    -1,   297,    -1,   301,    -1,   314,
      -1,   304,    -1,    -1,    44,   296,   284,    -1,    -1,    -1,
      -1,     6,   298,   299,   395,   300,   284,    -1,    -1,    -1,
       7,   302,   303,   395,   284,    -1,   120,    40,   398,    89,
     396,    41,    -1,    -1,    -1,    45,   306,   307,   284,    -1,
      -1,    -1,   309,   310,   284,   313,    -1,    -1,    46,   312,
     284,    -1,    -1,   313,   311,    -1,    47,   315,    -1,   420,
      -1,   421,    -1,   316,    -1,   446,   317,    -1,   165,    -1,
      -1,    40,   319,   398,   318,   321,    41,    -1,    -1,    17,
      -1,    48,   398,    -1,    -1,   321,   320,    -1,   165,    -1,
      -1,    40,   398,   323,   321,    41,    -1,    -1,    36,   325,
     326,    37,    -1,    -1,   327,    -1,   330,   329,    -1,    43,
     326,    -1,    -1,   328,    -1,    -1,   394,   331,   333,    -1,
      -1,   386,   332,   338,    -1,   344,   340,   337,    -1,   344,
     340,    -1,    -1,   334,    -1,    49,   335,    -1,    -1,   337,
     336,    -1,   339,    -1,    -1,   333,    -1,   343,   342,    -1,
      48,   343,    -1,    -1,   342,   341,    -1,   393,    -1,   395,
      -1,    50,    -1,    -1,   394,   346,   348,    -1,    -1,   386,
     347,   356,    -1,    -1,   350,   349,   340,   355,    -1,   357,
      -1,   358,    -1,    -1,   350,   352,   340,    -1,    -1,   351,
      -1,    49,   353,    -1,    -1,   355,   354,    -1,   339,    -1,
     359,    -1,   396,    -1,   360,    -1,   363,   362,    -1,   102,
     363,    -1,    -1,   362,   361,    -1,   368,   365,    -1,    63,
     368,    -1,    -1,   365,   364,    -1,   374,   367,    -1,    -1,
     369,    -1,   366,    -1,   100,   366,    -1,   373,    -1,    37,
      -1,   385,    37,    -1,    48,   370,    -1,    37,    -1,   385,
     371,    -1,    48,   385,    37,    -1,    19,    -1,   101,    -1,
      61,    -1,    36,   372,    -1,   375,    -1,   446,    -1,    50,
      -1,    64,   376,    -1,    40,   359,    41,    -1,   381,    -1,
     102,   382,    -1,    -1,   378,   377,    -1,   382,   378,    -1,
      -1,   379,    -1,   382,    -1,    40,   380,    41,    -1,   384,
      -1,   446,    -1,    50,    -1,   446,    -1,    50,    -1,   100,
     383,    -1,   144,    -1,   389,    -1,   387,    -1,    -1,    51,
     388,   333,    52,    -1,   391,    40,   392,    41,    -1,    31,
      -1,    32,    -1,    33,    -1,    34,    -1,    35,    -1,    -1,
     390,    -1,   393,    -1,   392,   393,    -1,   394,    -1,   386,
      -1,   396,    -1,   397,    -1,   396,    -1,   446,    -1,   162,
      -1,   163,    -1,   446,    -1,   436,    -1,   440,    -1,   444,
      -1,   448,    -1,   165,    -1,   399,    -1,   402,   401,    -1,
      53,   402,    -1,    -1,   401,   400,    -1,   405,   404,    -1,
      54,   405,    -1,    -1,   404,   403,    -1,   406,    -1,   409,
     407,    -1,    -1,   408,    -1,    55,   409,    -1,    56,   409,
      -1,    57,   409,    -1,    58,   409,    -1,    59,   409,    -1,
      60,   409,    -1,    66,   322,    -1,    65,    66,   322,    -1,
     410,    -1,   416,   415,    -1,   442,    -1,   443,    -1,    19,
     418,    -1,    63,   418,    -1,    -1,   412,    -1,    61,   416,
      -1,    62,   416,    -1,   411,   413,    -1,    -1,   415,   414,
      -1,   418,   417,    -1,    -1,   417,   412,    -1,    64,   419,
      -1,    61,   419,    -1,    62,   419,    -1,   419,    -1,   420,
      -1,   421,    -1,   434,    -1,   436,    -1,   440,    -1,   444,
      -1,   396,    -1,   428,    -1,    40,   398,    41,    -1,    76,
      40,   398,    41,    -1,    77,    40,   398,    41,    -1,    78,
      40,   398,    48,   398,    41,    -1,    79,    40,   398,    41,
      -1,    80,    40,   396,    41,    -1,    67,    40,   398,    41,
      -1,    68,    40,   398,    41,    -1,    69,   422,    -1,   112,
     165,    -1,   135,    40,   398,    41,    -1,   132,    40,   398,
      41,    -1,   124,    40,   398,    41,    -1,   118,    40,   398,
      41,    -1,    88,   322,    -1,   425,    -1,   139,    40,   398,
      41,    -1,   136,    40,   398,    41,    -1,   134,    40,   398,
      41,    -1,   130,    40,   398,    41,    -1,   121,    40,   398,
      48,   398,    41,    -1,   131,    40,   398,    48,   398,    41,
      -1,   138,    40,   398,    48,   398,    41,    -1,   109,    40,
     398,    41,    -1,   141,    40,   398,    41,    -1,   133,    40,
     398,    41,    -1,   129,    40,   398,    41,    -1,   126,    40,
     398,    41,    -1,   122,    40,   398,    41,    -1,   117,    40,
     398,    41,    -1,   115,   165,    -1,   107,    40,   398,    41,
      -1,   140,    40,   398,    41,    -1,   137,    40,   398,    41,
      -1,   128,    40,   398,    41,    -1,   119,    40,   398,    41,
      -1,   113,    40,   398,    41,    -1,    70,   322,    -1,    71,
      40,   398,    48,   398,    48,   398,    41,    -1,    72,    40,
     398,    48,   398,    41,    -1,    73,    40,   398,    48,   398,
      41,    -1,    81,    40,   398,    48,   398,    41,    -1,    82,
      40,   398,    41,    -1,    83,    40,   398,    41,    -1,    84,
      40,   398,    41,    -1,    85,    40,   398,    41,    -1,    99,
      40,   398,    41,    -1,   423,    -1,   426,    -1,   427,    -1,
      40,   398,    41,    -1,   165,    -1,    86,    40,   398,    48,
     398,   424,    41,    -1,    -1,   320,    -1,   127,    40,   398,
      48,   398,   424,    41,    -1,    74,   284,    -1,    65,    74,
     284,    -1,    92,    40,   319,   430,    41,    -1,   431,    40,
     319,   398,    41,    -1,    -1,    97,    40,   319,   398,   429,
     433,    41,    -1,    19,    -1,   398,    -1,    93,    -1,    94,
      -1,    95,    -1,    96,    -1,    98,    -1,    49,    75,    55,
     445,    -1,    -1,   432,    -1,   446,   435,    -1,    -1,   317,
      -1,   445,   439,    -1,    87,   446,    -1,   164,    -1,   437,
      -1,    -1,   438,    -1,   441,    -1,   442,    -1,   443,    -1,
     144,    -1,   145,    -1,   146,    -1,   147,    -1,   148,    -1,
     149,    -1,   150,    -1,   151,    -1,   152,    -1,   142,    -1,
     143,    -1,   153,    -1,   155,    -1,   154,    -1,   156,    -1,
     157,    -1,   447,    -1,   159,    -1,   158,    -1,   160,    -1,
     161,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SPARQLfedParser::yyprhs_[] =
  {
         0,     0,     3,     5,     7,    10,    13,    15,    17,    19,
      21,    24,    25,    27,    28,    31,    34,    35,    36,    42,
      48,    49,    52,    53,    59,    63,    65,    67,    68,    70,
      73,    74,    76,    81,    83,    85,    87,    89,    91,    93,
      95,    97,    99,   102,   104,   106,   113,   120,   122,   125,
     127,   129,   130,   132,   137,   140,   142,   144,   146,   149,
     151,   154,   155,   157,   162,   163,   165,   166,   168,   169,
     171,   172,   174,   178,   180,   183,   185,   187,   192,   194,
     197,   199,   202,   204,   208,   210,   213,   215,   217,   219,
     221,   224,   226,   228,   231,   234,   235,   237,   238,   240,
     243,   246,   248,   249,   252,   254,   257,   258,   263,   265,
     266,   269,   270,   277,   278,   280,   282,   284,   286,   288,
     290,   292,   294,   295,   300,   301,   303,   306,   307,   309,
     311,   313,   315,   317,   319,   321,   323,   325,   327,   329,
     331,   335,   338,   339,   341,   345,   346,   348,   352,   356,
     362,   368,   374,   377,   380,   383,   389,   392,   393,   395,
     396,   398,   401,   403,   404,   407,   410,   413,   416,   418,
     421,   423,   426,   427,   429,   432,   434,   436,   438,   440,
     444,   448,   451,   452,   454,   455,   457,   461,   462,   465,
     466,   467,   468,   477,   480,   483,   484,   486,   487,   492,
     494,   496,   499,   500,   502,   506,   507,   510,   513,   516,
     517,   519,   521,   523,   525,   527,   529,   531,   533,   534,
     538,   539,   540,   541,   548,   549,   550,   556,   563,   564,
     565,   570,   571,   572,   577,   578,   582,   583,   586,   589,
     591,   593,   595,   598,   600,   601,   608,   609,   611,   614,
     615,   618,   620,   621,   627,   628,   633,   634,   636,   639,
     642,   643,   645,   646,   650,   651,   655,   659,   662,   663,
     665,   668,   669,   672,   674,   675,   677,   680,   683,   684,
     687,   689,   691,   693,   694,   698,   699,   703,   704,   709,
     711,   713,   714,   718,   719,   721,   724,   725,   728,   730,
     732,   734,   736,   739,   742,   743,   746,   749,   752,   753,
     756,   759,   760,   762,   764,   767,   769,   771,   774,   777,
     779,   782,   786,   788,   790,   792,   795,   797,   799,   801,
     804,   808,   810,   813,   814,   817,   820,   821,   823,   825,
     829,   831,   833,   835,   837,   839,   842,   844,   846,   848,
     849,   854,   859,   861,   863,   865,   867,   869,   870,   872,
     874,   877,   879,   881,   883,   885,   887,   889,   891,   893,
     895,   897,   899,   901,   903,   905,   907,   910,   913,   914,
     917,   920,   923,   924,   927,   929,   932,   933,   935,   938,
     941,   944,   947,   950,   953,   956,   960,   962,   965,   967,
     969,   972,   975,   976,   978,   981,   984,   987,   988,   991,
     994,   995,   998,  1001,  1004,  1007,  1009,  1011,  1013,  1015,
    1017,  1019,  1021,  1023,  1025,  1029,  1034,  1039,  1046,  1051,
    1056,  1061,  1066,  1069,  1072,  1077,  1082,  1087,  1092,  1095,
    1097,  1102,  1107,  1112,  1117,  1124,  1131,  1138,  1143,  1148,
    1153,  1158,  1163,  1168,  1173,  1176,  1181,  1186,  1191,  1196,
    1201,  1206,  1209,  1218,  1225,  1232,  1239,  1244,  1249,  1254,
    1259,  1264,  1266,  1268,  1270,  1274,  1276,  1284,  1285,  1287,
    1295,  1298,  1302,  1308,  1314,  1315,  1323,  1325,  1327,  1329,
    1331,  1333,  1335,  1337,  1342,  1343,  1345,  1348,  1349,  1351,
    1354,  1357,  1359,  1361,  1362,  1364,  1366,  1368,  1370,  1372,
    1374,  1376,  1378,  1380,  1382,  1384,  1386,  1388,  1390,  1392,
    1394,  1396,  1398,  1400,  1402,  1404,  1406,  1408,  1410
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   402,   402,   405,   411,   418,   425,   426,   427,   428,
     433,   437,   439,   443,   445,   449,   455,   457,   455,   467,
     475,   478,   486,   486,   497,   505,   508,   515,   518,   523,
     530,   533,   538,   545,   548,   551,   554,   557,   560,   563,
     567,   572,   575,   583,   586,   593,   602,   611,   614,   622,
     625,   632,   635,   640,   648,   655,   656,   660,   666,   672,
     679,   686,   688,   693,   700,   703,   708,   711,   716,   719,
     724,   728,   732,   739,   742,   749,   752,   755,   758,   764,
     770,   773,   780,   785,   792,   796,   804,   806,   814,   817,
     825,   833,   834,   841,   845,   853,   856,   861,   864,   868,
     874,   882,   887,   890,   897,   900,   906,   906,   912,   918,
     921,   928,   928,   937,   940,   944,   947,   950,   953,   956,
     959,   965,   969,   969,   978,   980,   984,   987,   989,   993,
     994,   995,   996,   997,   998,   999,  1000,  1001,  1002,  1003,
    1007,  1014,  1021,  1024,  1028,  1034,  1037,  1043,  1049,  1055,
    1061,  1067,  1073,  1081,  1089,  1097,  1106,  1112,  1115,  1119,
    1122,  1126,  1130,  1136,  1138,  1144,  1151,  1158,  1164,  1167,
    1173,  1176,  1181,  1183,  1187,  1193,  1196,  1199,  1202,  1209,
    1213,  1217,  1220,  1222,  1226,  1228,  1232,  1235,  1237,  1242,
    1246,  1249,  1242,  1260,  1264,  1267,  1269,  1274,  1274,  1286,
    1287,  1292,  1296,  1298,  1308,  1312,  1315,  1331,  1336,  1340,
    1343,  1347,  1348,  1349,  1350,  1351,  1352,  1353,  1357,  1357,
    1372,  1375,  1377,  1372,  1388,  1391,  1388,  1400,  1406,  1409,
    1406,  1419,  1422,  1419,  1432,  1432,  1446,  1448,  1452,  1463,
    1464,  1465,  1469,  1477,  1481,  1481,  1490,  1493,  1500,  1506,
    1508,  1522,  1525,  1525,  1535,  1535,  1543,  1545,  1550,  1555,
    1559,  1561,  1565,  1565,  1568,  1568,  1575,  1580,  1584,  1586,
    1591,  1595,  1597,  1602,  1606,  1608,  1613,  1618,  1622,  1624,
    1628,  1635,  1639,  1647,  1647,  1650,  1650,  1656,  1656,  1662,
    1663,  1667,  1667,  1672,  1674,  1678,  1681,  1683,  1687,  1691,
    1695,  1701,  1705,  1709,  1712,  1714,  1718,  1722,  1727,  1729,
    1735,  1738,  1740,  1746,  1747,  1753,  1757,  1758,  1762,  1763,
    1767,  1768,  1772,  1773,  1774,  1775,  1779,  1783,  1786,  1789,
    1792,  1798,  1802,  1805,  1807,  1811,  1814,  1816,  1820,  1821,
    1825,  1829,  1830,  1834,  1835,  1836,  1840,  1845,  1846,  1850,
    1850,  1863,  1888,  1891,  1894,  1897,  1900,  1907,  1910,  1915,
    1919,  1926,  1927,  1931,  1934,  1938,  1941,  1947,  1948,  1952,
    1955,  1958,  1961,  1964,  1965,  1971,  1976,  1985,  1992,  1995,
    2003,  2012,  2019,  2022,  2029,  2034,  2045,  2048,  2052,  2055,
    2058,  2061,  2064,  2067,  2070,  2073,  2079,  2084,  2093,  2096,
    2103,  2106,  2113,  2116,  2121,  2124,  2128,  2142,  2145,  2153,
    2162,  2165,  2172,  2175,  2178,  2181,  2185,  2186,  2187,  2188,
    2191,  2194,  2197,  2200,  2204,  2210,  2213,  2216,  2219,  2222,
    2225,  2228,  2232,  2235,  2238,  2241,  2244,  2247,  2250,  2253,
    2254,  2257,  2260,  2263,  2266,  2269,  2272,  2275,  2278,  2281,
    2284,  2287,  2290,  2293,  2296,  2299,  2302,  2305,  2308,  2311,
    2314,  2317,  2321,  2324,  2327,  2330,  2333,  2336,  2339,  2342,
    2345,  2348,  2349,  2350,  2356,  2359,  2366,  2373,  2376,  2380,
    2386,  2393,  2400,  2403,  2407,  2407,  2419,  2423,  2427,  2430,
    2433,  2436,  2439,  2445,  2451,  2454,  2458,  2468,  2471,  2476,
    2484,  2491,  2495,  2503,  2507,  2511,  2512,  2513,  2517,  2518,
    2519,  2523,  2524,  2525,  2529,  2530,  2531,  2535,  2536,  2540,
    2541,  2542,  2543,  2547,  2548,  2552,  2553,  2557,  2558
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

  const int SPARQLfedParser::yyeof_ = 0;
  const int SPARQLfedParser::yylast_ = 2161;
  const int SPARQLfedParser::yynnts_ = 283;
  const int SPARQLfedParser::yyempty_ = -2;
  const int SPARQLfedParser::yyfinal_ = 10;
  const int SPARQLfedParser::yyterror_ = 1;
  const int SPARQLfedParser::yyerrcode_ = 256;
  const int SPARQLfedParser::yyntokens_ = 166;

  const unsigned int SPARQLfedParser::yyuser_token_number_max_ = 420;
  const SPARQLfedParser::token_number_type SPARQLfedParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 5093 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 2564 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
	countStar(false), root(NULL), unnestTree(false)
{
}

    SPARQLfedDriver::~SPARQLfedDriver ()
{
}

Operation* SPARQLfedDriver::parse (IStreamContext& in)
{
    root = NULL;
    curBGP = NULL;
    curOp = NULL;
    curGraphName = NULL;
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


