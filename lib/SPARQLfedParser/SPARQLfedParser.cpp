
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
#line 387 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

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
#line 401 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 404 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 415 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.lastWhereClause != NULL)
	    driver.lastWhereClause->m_BindingClause = (yysemantic_stack_[(3) - (3)].p_BindingsClause);
	(yyval.p_Operation) = (yysemantic_stack_[(3) - (2)].p_Operation);
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 432 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingsClause) = NULL;
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 456 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 462 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 464 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 466 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 474 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(4) - (3)].p_WhereClause);
	(yyval.p_Operation) = new Select((yysemantic_stack_[(4) - (1)].p_Project).distinctness, (yysemantic_stack_[(4) - (1)].p_Project).varSet, (yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 482 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 485 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 493 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 496 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yysemantic_stack_[(5) - (3)].p_WhereClause)->m_BindingClause = (yysemantic_stack_[(5) - (5)].p_BindingsClause);
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(5) - (1)].p_Project).distinctness, (yysemantic_stack_[(5) - (1)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(5) - (3)].p_WhereClause), (yysemantic_stack_[(5) - (4)].p_SolutionModifier))));
      }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 504 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 512 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 515 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 522 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 530 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 537 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 545 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 552 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 555 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 558 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 561 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 564 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 567 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 570 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 579 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 582 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 590 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 593 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 600 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause);
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	(yyval.p_Operation) = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(5) - (2)].p_BasicGraphPattern), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 609 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause);
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 617 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm))));
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 620 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_TTerm))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 628 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 631 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 638 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 646 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(3) - (3)].p_WhereClause);
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(3) - (2)].p_DatasetClauses), (yysemantic_stack_[(3) - (3)].p_WhereClause));
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 654 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 666 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 672 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 678 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 685 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp ? driver.curOp : new DefaultGraphPattern(), NULL);
	driver.curOp = NULL;
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 699 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 706 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 714 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 722 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 730 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 738 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 745 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 748 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 755 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 758 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 761 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 764 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 770 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 776 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 779 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 791 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 798 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 802 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 812 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 820 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 823 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 831 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 840 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 847 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 851 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 859 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 867 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 874 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 880 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 887 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingsClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_TTermList));
      }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 889 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingsClause) = driver.curBindingsClause;
	  driver.curBindingsClause = NULL;
      }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 897 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTermList) = new TTermList;
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 900 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTermList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_TTermList) = (yysemantic_stack_[(2) - (1)].p_TTermList);
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 907 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 910 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 916 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding = new Binding();
      }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 918 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingValue) = driver.curBinding;
	  driver.curBinding = NULL;
      }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 922 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding = new Binding();
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 928 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 931 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingsClause->push_back((yysemantic_stack_[(2) - (2)].p_BindingValue));
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 938 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 941 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 944 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 947 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 950 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 953 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 963 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	OperationSet* ret = driver.root ? dynamic_cast<OperationSet*>(driver.root) : new OperationSet();
	ret->push_back((yysemantic_stack_[(2) - (2)].p_Operation));
	driver.root = ret;
      }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 967 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Operation) = driver.root;
	}
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1001 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(3) - (2)].p_URI), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1008 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1015 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1022 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1028 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1031 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1037 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1043 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1049 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1055 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1061 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1067 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert(driver.curOp, NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1075 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete(driver.curOp, NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1083 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete(driver.curOp, NULL);
	driver.curOp = NULL;
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1091 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(5) - (1)].p_URI))
	    w3c_sw_NEED_IMPL("WITH <URI> (DELETE INSERT?|INSERT) ...");
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(5) - (2)].p_DeleteInsert).del, (yysemantic_stack_[(5) - (2)].p_DeleteInsert).ins, new WhereClause(driver.curOp, NULL));
	driver.curOp = NULL;
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1100 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1106 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1113 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1120 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1124 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 1132 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("_QUsingClause_E_Star");
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 1138 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Delete) = new Delete(driver.curOp, NULL);
	driver.curOp = NULL;
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1145 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = new Insert(driver.curOp, NULL);
	driver.curOp = NULL;
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1152 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
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
#line 1161 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1167 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1170 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 1181 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1187 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 1190 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("DEFAULT");
      }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 1193 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("NAMED");
      }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 1196 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("ALL");
      }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 1236 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curFilter = NULL;
      }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 1240 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 1243 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 1246 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1268 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1271 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 1352 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 1355 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 1367 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 1370 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 1372 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 1375 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 1383 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 1386 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 1388 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(5) - (4)].p_TTerm), driver.curOp, driver.atomFactory, false));
      }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 1395 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Bind(driver.curOp, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 1401 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 1404 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 1406 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.curOp));
      }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 1414 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 1417 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 1419 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 1427 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 1432 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 1447 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 1464 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 1472 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 1476 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 1478 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = NULL;
      }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 1485 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 1488 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 1495 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 1503 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 1517 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 1520 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 1522 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 1530 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 1532 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 1560 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 1563 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 1623 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 1630 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 1634 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 1642 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 1645 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 1651 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 1662 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 1690 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 1717 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 1724 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 1735 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 1742 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 1778 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 1781 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 1784 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 1787 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 1845 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 1849 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 1858 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 1883 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 1886 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 1889 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 1892 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 1895 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 1902 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 1910 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 1914 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 1926 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 1933 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 1936 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 1947 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 1950 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 1953 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 1956 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 1960 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 1971 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 1980 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 1987 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 1990 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 1998 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 2007 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 2014 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 2017 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 2029 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 2040 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 2047 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 2050 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 2053 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 2056 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 2059 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 2062 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 2065 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 2068 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 2079 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 2088 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 2091 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 2098 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 2101 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 2108 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 2116 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 2119 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 2123 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 2137 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 2140 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 2148 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 2157 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 2160 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 2167 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 2170 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 2173 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 2183 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 2186 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 2189 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 2192 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 2199 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 2205 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 2208 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 2211 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 2214 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 2217 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 2220 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 2223 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 2227 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_blank, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 2230 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 2233 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 2236 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ciel, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 2239 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 2242 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 2245 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::XPATH_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 2249 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlen, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 2252 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ucase, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 2255 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lcase, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 2258 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encodeForUri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 2261 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 2264 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strStarts, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 2267 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strEnds, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 2270 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 2273 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 2276 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 2279 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 2282 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 2285 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 2288 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 2291 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 2294 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 2297 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 2300 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha224, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 2303 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 2306 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 2309 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 2312 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 2316 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 2319 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 2322 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 2325 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 2328 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 2331 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 2334 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 2337 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 2340 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 2351 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 2354 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 2361 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_regex, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 2368 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 2375 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 2381 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 2388 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 2395 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 2398 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 2402 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 2404 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 2414 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
	driver.countStar = true;
    }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 2422 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 2425 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 2428 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 2431 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 2434 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 2440 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 2446 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 2453 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 2463 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 2471 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 2479 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 2486 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 2490 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 2498 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 3386 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -761;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        66,  -110,    58,  -761,  -761,   564,  -761,  -761,  -761,  -761,
    -761,  -761,    62,    56,    56,    56,    88,    81,    -1,  -761,
      62,    56,    56,    94,   102,    56,   102,    72,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,   193,    77,  -761,  -761,
    -761,   113,  -761,  -761,    32,   135,    32,  -761,  -761,  -761,
    1263,  -761,  -761,  -761,  -761,  -761,   199,  -761,  -761,  -761,
    -761,    50,  -761,    21,    21,   944,  -761,   944,  -761,    21,
    -761,  -761,  -761,  -761,    50,   126,    94,    94,  -761,   176,
    -761,  -761,  -761,   135,  -761,  -761,    62,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  1456,   114,   154,   162,   -18,
     -16,   169,   175,   183,   218,   231,   243,   251,   253,   256,
     264,   266,   273,   275,   276,   279,   -16,   280,  -761,  -761,
    -761,  -761,   281,  -761,   283,   286,   287,   166,   292,   168,
     294,   298,   307,   308,   319,   320,   323,   324,   325,   328,
     329,   330,   332,   333,   336,   339,   343,   344,   345,   346,
     347,   348,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  1576,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,   351,
    -761,  -761,  -761,  -761,  -761,  -761,   -51,     1,   944,    50,
    -761,    42,     6,  -761,  -761,  -761,   218,  -761,  -761,   150,
      62,   284,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,   356,  -761,  -761,   352,  -761,  -761,  -761,  -761,   354,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,   359,   289,
     -10,   309,    53,  -761,  -761,  -761,  -761,    36,  -761,  -761,
     240,  -761,  -761,  1456,  1696,  1696,  1696,  -761,   314,  -761,
    -761,  -761,  -761,   285,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,     1,   218,  1456,  1456,  1456,
    -761,  -761,  1456,  -761,  -761,  1456,  1456,  1456,  -761,  -761,
    1456,  1456,  1456,  1456,    84,  1456,  1456,  1456,  1456,  1456,
    1456,  -761,   387,   387,  1456,  1456,  1456,  -761,  1456,  -761,
    1456,  1456,  1456,  1456,  1456,  1456,  1456,  1456,  1456,  1456,
    1456,  1456,  1456,  1456,  1456,  1456,  1456,  1456,  1456,  1456,
    1456,  1456,  -761,   387,    62,  -761,  -761,  -761,  -761,   387,
    -761,  -761,   368,  -761,   363,   309,   309,  -761,    62,  -761,
    -761,  -761,  -761,  -761,  -761,    21,  -761,    21,   122,  -761,
     403,   944,  -761,  -761,   122,  1287,   122,  -761,    21,  -761,
    -761,   383,  -761,   321,  -761,   214,  -761,  -761,   218,    12,
    -761,  -761,   372,  -761,  -761,  -761,    84,  -761,   373,   362,
     370,  1456,  1456,  1456,  1456,  1456,  1456,   350,   -16,  -761,
    -761,   112,    25,  -761,  -761,  -761,   376,   381,   386,  -761,
     384,   385,   389,   780,   393,   394,   390,   398,   399,   395,
     400,   401,   404,   407,   405,  -761,  1121,  1456,   408,   409,
     410,   411,   413,   416,   417,   412,   418,   420,   421,   415,
     423,   424,   426,   422,   428,   430,   434,   435,   438,   439,
     433,   441,   442,   444,  1456,  -761,  1456,  -761,   944,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,   437,  1287,  -761,
    -761,   443,   481,  -761,  -761,  -761,  -761,  -761,  1332,  -761,
    -761,  -761,  -761,  -761,  1816,  1918,   466,  -761,  -761,    62,
    -761,  -761,   334,  -761,  -761,  -761,  1456,  -761,  1456,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,   -16,  -761,  1456,  1456,
      25,  -761,  -761,  -761,  1456,  1456,  -761,  -761,  -761,  -761,
    -761,  1456,  1456,  1456,  -761,  -761,   455,  -761,  -761,  -761,
     450,  -761,  -761,  -761,  -761,  1456,  -761,  -761,  1456,  -761,
    -761,  -761,  -761,  1456,  -761,  -761,   454,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  1456,  -761,  -761,  -761,  1456,
    -761,  -761,  -761,  1456,  -761,  -761,  -761,  -761,  -761,  -761,
    1456,  -761,  -761,  -761,   456,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,   944,   199,  -761,  -761,   -17,  1456,  1816,  -761,
    -761,  -761,  -761,  1918,  -761,  -761,  -761,  -761,  -761,   471,
     237,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,   143,   451,   457,   460,   463,  -761,    67,
     944,  -761,  -761,   122,    19,   462,   464,   458,  -761,   459,
     468,   458,   469,   470,  -761,  -761,   465,   467,  -761,  -761,
    -761,  -761,  -761,  -761,   314,  -761,  -761,   920,   360,   369,
    -761,  -761,   478,   484,  -761,  1456,  -761,  1456,  -761,  -761,
     309,  -761,  -761,  -761,  -761,  1918,   476,  -761,  -761,   443,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,    54,  -761,    59,    46,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,   234,  -761,  -761,  -761,  -761,  -761,
    -761,   477,   445,  -761,   480,  -761,   482,  -761,  -761,   144,
     122,  -761,  1287,  -761,   486,   402,   485,  -761,  -761,   920,
    -761,   487,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,   490,    72,  -761,  -761,   218,  -761,  -761,
    1456,   944,   218,   492,    93,  -761,   110,  -761,  -761,  -761,
    -761,  -761,  -761,  1287,   461,   473,  -761,    -9,  -761,  -761,
    -761,  -761,  -761,  -761,   511,  -761,  -761,  -761,  -761,  -761,
    1287,  -761,  -761,  -761,    86,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,   199,   199,  -761,   218,
     436,  -761,  -761,  -761,  -761,   496,  -761,  -761,  -761,  -761,
    -761,    54,  -761,    54,  -761,   396,  -761,  -761,     9,   134,
    -761,   944,  -761,  -761,  -761,   218,  -761,    84,   493,  -761,
     489,   479,  -761,  -761,   504,  -761,    -5,  -761,  -761,   530,
     218,  -761,   528,  -761,  -761,    93,  -761,    19,  -761,  -761,
    -761,  -761,   541,  -761,  -761,  -761,   218,  -761,  -761,  -761,
    -761,  -761,  -761,  1287,  -761
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        13,     0,     0,     2,     4,   156,    15,    14,     3,   120,
      17,     1,     0,   144,   144,   144,    29,     0,     0,    22,
       0,   144,   144,     0,     0,   144,     0,    10,     6,    22,
       7,     8,     9,   121,   128,   129,   130,   134,   131,   132,
     133,   135,   136,   137,   138,   157,     0,    12,   523,   526,
     525,   141,   524,   145,     0,     0,     0,    27,    28,    30,
       0,   254,    22,    52,   367,   368,    51,    22,    49,   365,
     366,    63,   155,   171,   171,   181,   153,   181,   152,   171,
     151,   105,     5,    11,    63,   126,     0,     0,   162,   158,
     161,    18,    16,     0,   142,   139,     0,   176,   175,   177,
     174,   143,   147,   146,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   488,   489,
     490,   491,     0,   492,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   517,   518,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   519,   521,   520,   522,    42,    43,    45,
      26,    38,    35,    37,   471,   439,   472,   473,    36,     0,
      39,    40,   505,   506,   507,    41,   503,     0,   256,    63,
      50,    53,     0,    64,    23,    55,     0,   172,   169,     0,
       0,     0,   352,   353,   354,   355,   356,   349,   527,   528,
     374,     0,   186,   182,   194,   264,   348,   347,   358,     0,
     262,   363,   364,   370,   371,   372,   369,   373,     0,     0,
       0,    66,    13,   127,   122,   164,   165,     0,   160,   159,
       0,   140,   173,     0,     0,     0,     0,   422,    32,   375,
     378,   382,   384,   386,   396,   407,   410,   415,   416,   417,
     423,   418,   419,   420,   421,   497,     0,     0,     0,     0,
     475,   432,     0,   251,   461,     0,     0,     0,   196,   480,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,   246,   246,     0,     0,     0,   433,     0,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,   246,     0,   501,   502,   504,   499,   246,
     243,   242,     0,   257,   260,    66,    66,    54,     0,    56,
      57,    58,    59,    61,    62,   171,   170,   171,     0,   178,
     180,   181,   195,   192,   274,   357,     0,   179,   171,   103,
     106,     0,    21,    68,    67,   156,   124,   125,     0,     0,
     163,    19,     0,   413,   414,   412,     0,    33,     0,   376,
     380,     0,     0,     0,     0,     0,     0,     0,     0,   385,
     387,   397,   409,   498,   496,   481,     0,     0,     0,   252,
       0,     0,     0,   201,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   247,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   500,     0,   255,   256,   261,
     258,    47,    48,    60,   148,   150,   282,     0,   357,   281,
     187,   183,     0,   193,   275,   265,   273,   362,   357,   359,
     361,   263,   149,   112,     0,     0,    70,    69,   154,     0,
     166,   167,     0,   424,    31,    34,     0,   379,     0,   383,
     388,   389,   390,   391,   392,   393,     0,   394,     0,     0,
     402,   408,   398,   399,     0,     0,   411,   430,   431,   474,
     249,     0,     0,     0,   198,    24,     0,   199,   204,   202,
     208,   285,   283,   425,   426,     0,   428,   429,     0,   466,
     467,   468,   469,     0,   486,   487,     0,   484,   470,   455,
     447,   460,   453,   437,   459,     0,   452,   436,   451,     0,
     458,   450,   443,     0,   435,   449,   442,   434,   441,   457,
       0,   440,   456,   448,     0,   244,   259,   350,   271,   278,
     280,   184,   181,     0,   351,   360,     0,     0,    74,    75,
      78,    80,    77,    81,    82,    84,   241,   239,   240,     0,
      72,    71,   168,    20,   377,   381,   395,   404,   405,   403,
     406,   400,   401,     0,     0,     0,     0,    63,   197,   200,
     201,   209,   206,   274,     0,     0,     0,   477,   482,   494,
       0,   477,     0,     0,   483,   249,   266,   276,   185,   189,
     104,   109,   111,   113,    32,    76,    83,     0,     0,     0,
      65,    73,    97,    99,   253,     0,   250,     0,   463,   464,
      66,   220,   224,   218,   228,     0,     0,   217,   205,   183,
     211,   213,   214,   216,   212,   210,   232,   215,   207,   298,
     286,     0,   328,     0,     0,   284,   287,   289,   290,   299,
     301,   304,   313,   308,   311,   326,   300,   327,   427,   465,
     478,     0,     0,   495,     0,   444,     0,   445,   446,     0,
     268,   272,   357,   279,     0,     0,     0,    90,    91,    85,
      86,     0,    88,    89,    93,    94,   101,   102,    95,    98,
      96,   100,   248,     0,    10,   221,   225,     0,   229,   238,
       0,   201,     0,     0,   336,   344,     0,   329,   331,   338,
     340,   343,   314,   357,   302,   306,   322,     0,   324,   323,
     310,   312,   315,   476,     0,   485,   479,   245,   269,   270,
     357,   277,   190,   118,     0,   107,   119,   115,   116,   117,
     114,    79,    87,    92,   462,    25,     0,     0,   219,     0,
       0,   203,   236,   330,   337,     0,   333,   342,   345,   341,
     296,     0,   305,     0,   309,     0,   346,   325,     0,     0,
     267,   181,   110,   108,   222,     0,   230,     0,   233,   339,
     335,   288,   303,   307,     0,   319,     0,   320,   493,     0,
       0,   226,     0,   234,   237,     0,   334,   293,   297,   321,
     316,   318,     0,   191,   223,   227,     0,   332,   291,   294,
     295,   317,   235,   357,   292
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -761,  -761,  -761,  -761,  -761,  -217,   337,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,    33,  -761,  -761,   170,  -761,  -761,
    -761,   -62,  -761,   414,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,   238,   -75,  -761,  -331,
    -761,  -761,  -761,  -761,  -761,  -761,     7,  -761,  -761,    -6,
    -761,  -761,  -130,  -761,  -761,  -761,  -761,  -761,  -761,   -57,
     -55,   -25,  -761,  -761,  -761,  -761,  -761,  -761,  -174,  -761,
     361,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
     185,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,   512,  -761,  -761,   -63,
    -761,     5,   549,   215,   581,   532,  -356,   -54,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -199,  -761,  -761,
    -761,  -595,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -604,   -56,
     335,  -761,  -232,  -575,   -22,  -116,  -761,  -761,  -761,   156,
    -761,  -761,  -761,  -186,  -761,  -761,  -250,  -761,  -761,  -761,
    -761,  -761,    -4,  -720,  -761,  -761,   -95,   -92,  -761,  -761,
    -761,  -761,  -761,  -216,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,   -61,  -761,  -761,  -761,  -179,  -761,  -761,   -60,
    -761,  -180,  -761,  -761,  -761,  -761,  -761,  -761,  -761,  -761,
    -761,  -761,  -761,  -761,  -761,  -704,  -761,  -761,  -760,  -334,
    -761,  -761,  -761,  -761,  -761,  -761,  -328,  -323,   -15,    16,
    -761,   589,  -761,  -761,  -761,   129,  -761,  -761,   128,  -761,
    -761,  -761,  -118,  -761,  -761,   117,  -761,  -761,  -761,  -200,
    -761,  -203,    44,  -464,   -59,  -761,  -761,    -3,  -761,  -761,
    -761,   -11,  -761,  -761,  -761,  -761,  -761,  -761,  -761,   -58,
    -761,  -761,  -761,   -47,  -761,   228,   232,    10,  -177,   -12,
    -761,  -761
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,    27,    82,     5,     6,    47,     7,
      92,   250,   492,    28,    71,   524,   617,    29,    59,    60,
     387,   388,   177,   178,   179,   180,    30,    31,    66,    67,
     346,    32,   204,   349,   350,   351,   352,   205,   206,   372,
     373,   486,   600,   650,   374,   588,   589,   487,   593,   594,
     601,   719,   720,   721,   722,   723,   651,   728,   730,   652,
     653,    83,   483,   240,   774,   643,   715,   586,   775,     8,
       9,    85,   377,   243,   244,    33,    34,    94,    95,    35,
      54,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,   248,    88,   247,    89,    90,   380,   490,   209,
     210,   100,   101,    76,    78,   221,   222,   582,   470,   360,
     471,   472,   714,   811,   223,   362,   363,   289,   413,   526,
     527,   528,   668,   619,   529,   621,   622,   669,   670,   737,
     671,   735,   786,   830,   672,   736,   787,   673,   674,   738,
     789,   675,   676,   742,   834,   846,   818,   677,   595,   596,
     341,   635,   426,   656,   613,   284,   520,    62,   198,   342,
     343,   459,   460,   224,   366,   364,   474,   768,   769,   711,
     636,   475,   476,   578,   713,   637,   579,   468,   530,   624,
     623,   685,   753,   686,   849,   853,   850,   838,   821,   680,
     687,   688,   689,   690,   802,   754,   691,   804,   755,   692,
     760,   693,   761,   841,   827,   807,   762,   694,   695,   747,
     836,   820,   794,   795,   748,   749,   798,   750,   808,   225,
     226,   358,   227,   228,   229,   478,   580,   230,   469,   257,
     232,   258,   259,   497,   389,   260,   499,   390,   261,   262,
     399,   400,   263,   264,   510,   516,   610,   511,   401,   265,
     402,   266,   267,   268,   269,   281,   184,   701,   185,   186,
     187,   270,   629,   546,   189,   703,   704,   271,   404,   272,
     336,   337,   338,   273,   192,   193,   194,   274,   196,   275,
      52,   237
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SPARQLfedParser::yytable_ninf_ = -358;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        51,   183,   190,    68,   181,   473,    70,   354,    72,   241,
     301,   211,   344,   191,   461,   462,   239,   233,    63,   233,
     640,   597,   279,   641,   282,   678,   369,   207,   234,   348,
     234,   477,   840,   800,    69,   489,   334,   479,    96,   805,
     796,   339,   480,   724,   514,   824,   825,    10,   197,   188,
     810,   200,   700,  -123,    70,    97,   700,   826,    11,   681,
     102,   739,    84,   236,   202,   236,   842,     1,    53,   682,
     195,   427,   202,   661,   662,   378,   182,   405,   -63,   531,
       1,   203,    69,   683,   252,   235,   681,   235,   515,   203,
     532,   231,    91,   231,   681,   199,   682,    81,   251,   744,
     201,   454,    81,  -231,   682,    57,    58,   456,   467,   745,
     683,   663,   664,   335,   665,   724,   481,    61,   683,   684,
     183,   190,    93,   181,   345,   208,   347,   812,   773,   597,
      75,   847,   191,   854,   477,   806,    98,    99,    77,   806,
     233,    96,   379,   745,   477,   480,   791,   280,   642,   283,
     585,   234,    64,    65,   684,   480,    48,    49,    50,   746,
     797,    64,    65,    48,    49,    50,   340,   197,   188,    48,
      49,    50,   466,   508,   509,   242,    48,    49,    50,   488,
      87,    64,    65,   597,   654,   767,   236,   666,   276,   195,
     353,   655,   655,   746,   277,   182,    86,    87,   356,    55,
      56,   597,   278,    48,    49,    50,    73,    74,   235,   285,
      79,    48,    49,    50,   231,   286,    48,    49,    50,    48,
      49,    50,    12,   287,    13,    14,   638,    15,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    48,    49,    50,    64,    65,    64,    65,
      48,    49,    50,   756,   288,   597,   370,   783,   355,   167,
     168,   169,   170,   171,   172,   648,   649,    48,    49,    50,
     757,   290,   344,   500,   501,   502,   503,   504,   505,    48,
      49,    50,   507,   291,    64,    65,   531,   173,   174,   175,
     176,   292,   464,   293,   465,   758,   294,   532,   383,   384,
     385,   245,   246,   233,   295,   482,   296,   233,   607,   608,
     418,   611,   612,   297,   234,   298,   299,    20,   234,   300,
     302,   303,   455,   304,    21,    22,   305,   306,    23,   734,
      24,   307,   308,   309,   310,   759,   353,    25,   311,    26,
     391,   392,   393,   394,   395,   396,    70,   312,   313,   236,
     397,   398,    70,   236,    70,   233,    48,    49,    50,   314,
     315,    64,    65,   316,   317,   318,   234,   491,   319,   320,
     321,   235,   322,   323,    69,   235,   324,   231,   477,   325,
      69,   231,    69,   326,   327,   328,   329,   330,   331,   480,
     606,   333,   357,   359,   365,   361,   367,   368,   381,   371,
     233,   236,   494,   386,   425,   457,   458,   531,   484,  -188,
     233,   234,   485,   493,   495,   496,   506,   517,   532,   477,
     233,   234,   518,   235,   498,   592,   598,   519,   590,   231,
     480,   234,   521,   522,   533,   534,   477,   523,   535,   536,
     537,   539,   540,   538,   773,   541,   236,   480,   542,   548,
     549,   550,   551,   543,   552,   829,   236,   553,   554,   556,
     555,   557,   558,   559,   560,   561,   236,   562,   235,   564,
     563,   565,   197,   197,   231,   566,   567,   602,   235,   568,
     569,   570,   571,   572,   231,   573,   581,   583,   235,   577,
     599,   603,   618,   620,   231,   628,   647,   634,   658,   657,
     591,   659,   203,   698,   726,   699,   655,   649,   702,   705,
     707,   708,   648,   727,   710,   712,   740,   785,   763,   477,
     764,   765,   772,   766,   233,   817,   781,   253,   837,   592,
     480,   784,   590,   793,   598,   234,   803,   819,   788,   833,
     806,   839,   660,   792,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    48,
      49,    50,   233,   801,    64,    65,   809,   843,   639,   845,
     236,    70,    12,   234,    13,    14,   197,    15,   851,   375,
      16,   197,   716,   525,    17,    18,   463,   646,   598,   782,
     816,   835,   235,   332,   667,   645,   731,   729,   231,    69,
     813,   249,    19,   376,   591,   103,   598,    80,   236,   238,
     403,    70,   697,   709,   576,   741,   831,   771,   770,   679,
     743,   848,   822,   823,   752,   604,   605,   609,   706,   512,
     235,   844,   828,   513,     0,   197,   231,     0,     0,    69,
     696,     0,     0,     0,     0,     0,     0,   852,     0,     0,
       0,     0,     0,   197,   233,     0,     0,   777,     0,     0,
     598,     0,     0,   725,     0,   234,     0,    20,   778,   697,
       0,   751,   697,     0,    21,    22,     0,     0,    23,     0,
      24,     0,     0,   233,     0,     0,     0,    25,     0,    26,
       0,     0,     0,     0,   234,   233,     0,     0,    70,     0,
     236,     0,     0,   780,     0,     0,   234,   197,     0,     0,
       0,     0,   233,     0,     0,     0,   777,     0,     0,     0,
       0,     0,   235,   234,     0,   779,    69,   778,   231,   236,
       0,   776,   751,     0,   799,   725,     0,     0,     0,     0,
       0,   236,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   235,     0,   233,     0,     0,     0,   231,   236,     0,
       0,     0,   780,   235,   234,     0,     0,     0,     0,   231,
       0,   814,   815,     0,    70,    70,     0,     0,     0,     0,
     235,     0,     0,     0,   779,     0,   231,     0,     0,   697,
     776,   697,     0,     0,     0,   233,    16,     0,     0,   236,
       0,     0,    69,    69,     0,     0,   234,     0,     0,     0,
       0,   212,   213,   214,   215,   216,     0,     0,     0,     0,
    -357,   235,     0,   751,     0,   697,     0,   231,     0,     0,
       0,   217,     0,   832,     0,     0,     0,     0,     0,     0,
       0,   236,   382,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   696,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   235,     0,     0,   406,   407,   408,   231,
       0,   409,     0,     0,   410,   411,   412,     0,     0,   414,
     415,   416,   417,     0,   419,   420,   421,   422,   423,   424,
       0,     0,     0,   428,   429,   430,     0,   431,     0,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,     0,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    48,    49,    50,
     218,   219,    64,    65,     0,   220,   717,   718,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     253,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   212,   213,   214,   215,   216,
       0,     0,     0,     0,  -357,   106,     0,   107,   108,   109,
     110,   111,   112,   113,   114,   217,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,     0,   126,     0,
       0,     0,     0,     0,     0,   545,   547,     0,     0,   134,
       0,     0,     0,     0,     0,     0,     0,   135,     0,   136,
       0,     0,   137,   138,     0,   139,     0,   140,   141,   142,
       0,   143,   144,   574,   145,   575,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    50,
       0,     0,    64,    65,     0,     0,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    48,    49,    50,   218,   219,    64,    65,     0,   220,
     614,   615,   616,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   625,     0,     0,   626,     0,     0,
       0,     0,   627,     0,     0,     0,     0,     0,     0,     0,
     544,     0,     0,     0,   630,     0,     0,     0,   631,     0,
       0,     0,   632,     0,     0,     0,     0,     0,     0,   633,
       0,   253,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   644,     0,     0,     0,
       0,     0,   254,   255,     0,   256,   106,     0,   107,   108,
     109,   110,   111,   112,   113,   114,     0,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,     0,     0,   127,   128,   129,   130,   131,   132,   133,
     134,     0,     0,     0,     0,     0,     0,     0,   135,     0,
     136,     0,     0,   137,   138,     0,   139,     0,   140,   141,
     142,     0,   143,   144,   732,   145,   733,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,    48,    49,
      50,     0,   104,    64,    65,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   212,   213,
     214,   215,   216,     0,     0,     0,     0,     0,   106,   790,
     107,   108,   109,   110,   111,   112,   113,   114,   217,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,     0,     0,   127,   128,   129,   130,   131,
     132,   133,   134,   212,   213,   214,   215,   216,     0,     0,
     135,     0,   136,   584,     0,   137,   138,     0,   139,     0,
     140,   141,   142,   217,   143,   144,     0,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
      48,    49,    50,     0,     0,    64,    65,     0,     0,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,    48,    49,    50,   218,   219,    64,
      65,     0,   220,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    48,
      49,    50,   218,   219,    64,    65,   253,   220,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   254,   255,     0,
     256,   106,     0,   107,   108,   109,   110,   111,   112,   113,
     114,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,     0,     0,   127,   128,
     129,   130,   131,   132,   133,   134,     0,     0,     0,     0,
       0,     0,     0,   135,     0,   136,     0,     0,   137,   138,
       0,   139,     0,   140,   141,   142,     0,   143,   144,     0,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    48,    49,    50,   105,     0,    64,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   106,     0,   107,   108,   109,   110,   111,   112,   113,
     114,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,     0,     0,   127,   128,
     129,   130,   131,   132,   133,   134,     0,     0,     0,     0,
       0,     0,     0,   135,     0,   136,     0,     0,   137,   138,
       0,   139,     0,   140,   141,   142,     0,   143,   144,     0,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    48,    49,    50,   253,     0,    64,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   106,     0,   107,   108,   109,   110,   111,   112,   113,
     114,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,     0,     0,   127,   128,
     129,   130,   131,   132,   133,   134,     0,     0,     0,     0,
       0,     0,     0,   135,     0,   136,     0,     0,   137,   138,
       0,   139,     0,   140,   141,   142,     0,   143,   144,     0,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    48,    49,    50,   587,     0,    64,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   106,     0,   107,   108,   109,   110,   111,   112,   113,
     114,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134,     0,     0,     0,     0,
       0,     0,     0,   135,     0,   136,     0,     0,   137,   138,
       0,   139,     0,   140,   141,   142,     0,   143,   144,     0,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   253,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,    49,    50,     0,     0,    64,    65,
       0,     0,     0,   106,     0,   107,   108,   109,   110,   111,
     112,   113,   114,     0,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,     0,     0,
       0,     0,     0,     0,     0,   135,     0,   136,     0,     0,
     137,   138,     0,   139,     0,   140,   141,   142,     0,   143,
     144,     0,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,    49,    50
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        12,    60,    60,    18,    60,   361,    18,   206,    20,    84,
     126,    74,   198,    60,   345,   346,    79,    75,    19,    77,
      37,   485,    40,    40,    40,   620,    36,     6,    75,    23,
      77,   365,    37,   753,    18,    23,    87,   365,     6,    48,
     744,    40,   365,   647,    19,   805,    37,   157,    60,    60,
     770,    66,   627,     0,    66,    23,   631,    48,     0,    40,
      55,   665,    29,    75,    22,    77,   826,    14,    12,    50,
      60,   303,    22,     6,     7,    39,    60,   276,    36,   413,
      14,    39,    66,    64,    96,    75,    40,    77,    63,    39,
     413,    75,    15,    77,    40,    62,    50,    30,    93,    40,
      67,   333,    30,    36,    50,    17,    18,   339,   358,    50,
      64,    44,    45,   164,    47,   719,   366,    36,    64,   100,
     179,   179,     9,   179,   199,   104,   201,    41,    42,   593,
      36,   835,   179,   853,   468,   144,   104,   105,    36,   144,
     198,     6,   106,    50,   478,   468,   741,   165,   165,   165,
     478,   198,   162,   163,   100,   478,   157,   158,   159,   100,
      50,   162,   163,   157,   158,   159,   165,   179,   179,   157,
     158,   159,    50,    61,    62,    49,   157,   158,   159,   378,
       4,   162,   163,   647,    41,    41,   198,   120,    74,   179,
     202,    48,    48,   100,    40,   179,     3,     4,   210,    14,
      15,   665,    40,   157,   158,   159,    21,    22,   198,    40,
      25,   157,   158,   159,   198,    40,   157,   158,   159,   157,
     158,   159,     8,    40,    10,    11,   582,    13,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   162,   163,   162,   163,
     157,   158,   159,    19,    36,   719,   240,   721,   108,   147,
     148,   149,   150,   151,   152,    28,    29,   157,   158,   159,
      36,    40,   458,   391,   392,   393,   394,   395,   396,   157,
     158,   159,   398,    40,   162,   163,   620,   153,   154,   155,
     156,    40,   355,    40,   357,    61,    40,   620,   254,   255,
     256,    86,    87,   361,    40,   368,    40,   365,   508,   509,
     294,   514,   515,    40,   361,    40,    40,   103,   365,    40,
      40,    40,   334,    40,   110,   111,    40,    40,   114,   660,
     116,   165,    40,   165,    40,   101,   348,   123,    40,   125,
      55,    56,    57,    58,    59,    60,   358,    40,    40,   361,
      65,    66,   364,   365,   366,   413,   157,   158,   159,    40,
      40,   162,   163,    40,    40,    40,   413,   379,    40,    40,
      40,   361,    40,    40,   358,   365,    40,   361,   712,    40,
     364,   365,   366,    40,    40,    40,    40,    40,    40,   712,
     506,    40,   108,    37,    40,    43,    37,   108,   158,    90,
     458,   413,   386,    89,    17,    37,    43,   741,    25,     6,
     468,   458,    91,    41,    41,    53,    66,    41,   741,   753,
     478,   468,    41,   413,    54,   484,   485,    41,   484,   413,
     753,   478,    48,    48,    41,    41,   770,    48,    48,    41,
      41,    41,    41,    48,    42,    41,   458,   770,    41,    41,
      41,    41,    41,    48,    41,   811,   468,    41,    41,    41,
      48,    41,    41,    48,    41,    41,   478,    41,   458,    41,
      48,    41,   484,   485,   458,    41,    41,   489,   468,    41,
      41,    48,    41,    41,   468,    41,    43,     6,   478,    52,
      24,   157,    37,    43,   478,    41,    25,    41,    41,    48,
     484,    41,    39,    41,   144,    41,    48,    29,    49,    41,
      41,    41,    28,   144,    49,    48,    40,   734,    41,   853,
      75,    41,    36,    41,   582,    89,    41,    40,    49,   588,
     853,    41,   588,    41,   593,   582,    63,    41,   737,    46,
     144,    37,   617,   742,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   620,   102,   162,   163,    55,    37,   583,    41,
     582,   583,     8,   620,    10,    11,   588,    13,    37,   242,
      16,   593,   644,   413,    20,    21,   348,   593,   647,   719,
     789,   102,   582,   179,   619,   588,   653,   652,   582,   583,
     774,    89,    38,   242,   588,    56,   665,    26,   620,    77,
     275,   623,   624,   635,   458,   669,   815,   712,   710,   623,
     681,   837,   801,   803,   684,   496,   498,   510,   631,   401,
     620,   830,   809,   401,    -1,   647,   620,    -1,    -1,   623,
     624,    -1,    -1,    -1,    -1,    -1,    -1,   846,    -1,    -1,
      -1,    -1,    -1,   665,   712,    -1,    -1,   715,    -1,    -1,
     719,    -1,    -1,   647,    -1,   712,    -1,   103,   715,   681,
      -1,   683,   684,    -1,   110,   111,    -1,    -1,   114,    -1,
     116,    -1,    -1,   741,    -1,    -1,    -1,   123,    -1,   125,
      -1,    -1,    -1,    -1,   741,   753,    -1,    -1,   710,    -1,
     712,    -1,    -1,   715,    -1,    -1,   753,   719,    -1,    -1,
      -1,    -1,   770,    -1,    -1,    -1,   774,    -1,    -1,    -1,
      -1,    -1,   712,   770,    -1,   715,   710,   774,   712,   741,
      -1,   715,   744,    -1,   746,   719,    -1,    -1,    -1,    -1,
      -1,   753,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   741,    -1,   811,    -1,    -1,    -1,   741,   770,    -1,
      -1,    -1,   774,   753,   811,    -1,    -1,    -1,    -1,   753,
      -1,   786,   787,    -1,   786,   787,    -1,    -1,    -1,    -1,
     770,    -1,    -1,    -1,   774,    -1,   770,    -1,    -1,   801,
     774,   803,    -1,    -1,    -1,   853,    16,    -1,    -1,   811,
      -1,    -1,   786,   787,    -1,    -1,   853,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      40,   811,    -1,   835,    -1,   837,    -1,   811,    -1,    -1,
      -1,    51,    -1,   817,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   853,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   837,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   853,    -1,    -1,   277,   278,   279,   853,
      -1,   282,    -1,    -1,   285,   286,   287,    -1,    -1,   290,
     291,   292,   293,    -1,   295,   296,   297,   298,   299,   300,
      -1,    -1,    -1,   304,   305,   306,    -1,   308,    -1,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,    -1,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,    -1,   165,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    40,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    51,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    -1,    88,    -1,
      -1,    -1,    -1,    -1,    -1,   426,   427,    -1,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,   109,
      -1,    -1,   112,   113,    -1,   115,    -1,   117,   118,   119,
      -1,   121,   122,   454,   124,   456,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,
      -1,    -1,   162,   163,    -1,    -1,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,    -1,   165,
     521,   522,   523,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   535,    -1,    -1,   538,    -1,    -1,
      -1,    -1,   543,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    -1,    -1,    -1,   555,    -1,    -1,    -1,   559,    -1,
      -1,    -1,   563,    -1,    -1,    -1,    -1,    -1,    -1,   570,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   587,    -1,    -1,    -1,
      -1,    -1,    61,    62,    -1,    64,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    88,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,
     109,    -1,    -1,   112,   113,    -1,   115,    -1,   117,   118,
     119,    -1,   121,   122,   655,   124,   657,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,    -1,    19,   162,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    65,   740,
      67,    68,    69,    70,    71,    72,    73,    74,    51,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    -1,    -1,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,    31,    32,    33,    34,    35,    -1,    -1,
     107,    -1,   109,    41,    -1,   112,   113,    -1,   115,    -1,
     117,   118,   119,    51,   121,   122,    -1,   124,    -1,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,    -1,    -1,   162,   163,    -1,    -1,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,    40,   165,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,
      64,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,    -1,   109,    -1,    -1,   112,   113,
      -1,   115,    -1,   117,   118,   119,    -1,   121,   122,    -1,
     124,    -1,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,    40,    -1,   162,   163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,    -1,   109,    -1,    -1,   112,   113,
      -1,   115,    -1,   117,   118,   119,    -1,   121,   122,    -1,
     124,    -1,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,    40,    -1,   162,   163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,    -1,   109,    -1,    -1,   112,   113,
      -1,   115,    -1,   117,   118,   119,    -1,   121,   122,    -1,
     124,    -1,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,    40,    -1,   162,   163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,    -1,   109,    -1,    -1,   112,   113,
      -1,   115,    -1,   117,   118,   119,    -1,   121,   122,    -1,
     124,    -1,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   157,   158,   159,    -1,    -1,   162,   163,
      -1,    -1,    -1,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,    -1,   109,    -1,    -1,
     112,   113,    -1,   115,    -1,   117,   118,   119,    -1,   121,
     122,    -1,   124,    -1,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,   158,   159
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    14,   167,   168,   169,   172,   173,   175,   235,   236,
     157,     0,     8,    10,    11,    13,    16,    20,    21,    38,
     103,   110,   111,   114,   116,   123,   125,   170,   179,   183,
     192,   193,   197,   241,   242,   245,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   174,   157,   158,
     159,   445,   446,    12,   246,   246,   246,    17,    18,   184,
     185,    36,   323,    19,   162,   163,   194,   195,   394,   395,
     445,   180,   445,   246,   246,    36,   269,    36,   270,   246,
     270,    30,   171,   227,   180,   237,     3,     4,   259,   261,
     262,    15,   176,     9,   243,   244,     6,    23,   104,   105,
     267,   268,   267,   268,    19,    40,    65,    67,    68,    69,
      70,    71,    72,    73,    74,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    88,    92,    93,    94,
      95,    96,    97,    98,    99,   107,   109,   112,   113,   115,
     117,   118,   119,   121,   122,   124,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   188,   189,   190,
     191,   315,   395,   420,   422,   424,   425,   426,   427,   430,
     435,   439,   440,   441,   442,   443,   444,   445,   324,   180,
     394,   180,    22,    39,   198,   203,   204,     6,   104,   265,
     266,   265,    31,    32,    33,    34,    35,    51,   160,   161,
     165,   271,   272,   280,   329,   385,   386,   388,   389,   390,
     393,   395,   396,   435,   439,   443,   445,   447,   271,   265,
     229,   203,    49,   239,   240,   269,   269,   260,   258,   262,
     177,   267,   445,    40,    61,    62,    64,   395,   397,   398,
     401,   404,   405,   408,   409,   415,   417,   418,   419,   420,
     427,   433,   435,   439,   443,   445,    74,    40,    40,    40,
     165,   421,    40,   165,   321,    40,    40,    40,    36,   283,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,   321,    40,    40,    40,    40,    40,   165,    40,   165,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,   189,    40,    87,   164,   436,   437,   438,    40,
     165,   316,   325,   326,   329,   203,   196,   203,    23,   199,
     200,   201,   202,   445,   283,   108,   445,   108,   387,    37,
     275,    43,   281,   282,   331,    40,   330,    37,   108,    36,
     395,    90,   205,   206,   210,   172,   236,   238,    39,   106,
     263,   158,   397,   418,   418,   418,    89,   186,   187,   400,
     403,    55,    56,    57,    58,    59,    60,    65,    66,   406,
     407,   414,   416,   316,   434,   283,   397,   397,   397,   397,
     397,   397,   397,   284,   397,   397,   397,   397,   395,   397,
     397,   397,   397,   397,   397,    17,   318,   318,   397,   397,
     397,   397,   397,   397,   397,   397,   397,   397,   397,   397,
     397,   397,   397,   397,   397,   397,   397,   397,   397,   397,
     397,   397,   397,   397,   318,   445,   318,    37,    43,   327,
     328,   205,   205,   202,   265,   265,    50,   332,   343,   394,
     274,   276,   277,   272,   332,   337,   338,   385,   391,   392,
     393,   332,   265,   228,    25,    91,   207,   213,   283,    23,
     264,   445,   178,    41,   395,    41,    53,   399,    54,   402,
     408,   408,   408,   408,   408,   408,    66,   321,    61,    62,
     410,   413,   441,   442,    19,    63,   411,    41,    41,    41,
     322,    48,    48,    48,   181,   183,   285,   286,   287,   290,
     344,   385,   393,    41,    41,    48,    41,    41,    48,    41,
      41,    41,    41,    48,    19,   397,   429,   397,    41,    41,
      41,    41,    41,    41,    41,    48,    41,    41,    41,    48,
      41,    41,    41,    48,    41,    41,    41,    41,    41,    41,
      48,    41,    41,    41,   397,   397,   325,    52,   339,   342,
     392,    43,   273,     6,    41,   392,   233,    40,   211,   212,
     315,   395,   420,   214,   215,   314,   315,   419,   420,    24,
     208,   216,   445,   157,   401,   404,   321,   415,   415,   411,
     412,   417,   417,   320,   397,   397,   397,   182,    37,   289,
      43,   291,   292,   346,   345,   397,   397,   397,    41,   428,
     397,   397,   397,   397,    41,   317,   336,   341,   272,   394,
      37,    40,   165,   231,   397,   212,   215,    25,    28,    29,
     209,   222,   225,   226,    41,    48,   319,    48,    41,    41,
     203,     6,     7,    44,    45,    47,   120,   227,   288,   293,
     294,   296,   300,   303,   304,   307,   308,   313,   287,   338,
     355,    40,    50,    64,   100,   347,   349,   356,   357,   358,
     359,   362,   365,   367,   373,   374,   395,   445,    41,    41,
     319,   423,    49,   431,   432,    41,   423,    41,    41,   320,
      49,   335,    48,   340,   278,   232,   187,    26,    27,   217,
     218,   219,   220,   221,   314,   395,   144,   144,   223,   226,
     224,   225,   397,   397,   205,   297,   301,   295,   305,   314,
      40,   273,   309,   358,    40,    50,   100,   375,   380,   381,
     383,   445,   365,   348,   361,   364,    19,    36,    61,   101,
     366,   368,   372,    41,    75,    41,    41,    41,   333,   334,
     343,   342,    36,    42,   230,   234,   395,   435,   439,   443,
     445,    41,   218,   419,    41,   171,   298,   302,   283,   306,
     397,   287,   283,    41,   378,   379,   381,    50,   382,   445,
     339,   102,   360,    63,   363,    48,   144,   371,   384,    55,
     339,   279,    41,   234,   394,   394,   283,    89,   312,    41,
     377,   354,   362,   367,   384,    37,    48,   370,   444,   272,
     299,   283,   395,    46,   310,   102,   376,    49,   353,    37,
      37,   369,   384,    37,   283,    41,   311,   381,   349,   350,
     352,    37,   283,   351,   339
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
     171,   171,   172,   173,   173,   174,   174,   175,   177,   178,
     176,   179,   180,   180,   182,   181,   183,   184,   184,   185,
     185,   186,   187,   187,   188,   189,   189,   189,   189,   189,
     189,   189,   189,   190,   190,   191,   191,   192,   193,   194,
     194,   195,   195,   196,   196,   197,   198,   199,   199,   200,
     201,   202,   203,   204,   204,   205,   206,   206,   207,   207,
     208,   208,   209,   209,   210,   211,   211,   212,   212,   212,
     212,   213,   214,   214,   215,   216,   217,   217,   218,   218,
     219,   219,   220,   221,   221,   222,   222,   223,   223,   224,
     224,   225,   226,   228,   227,   229,   229,   230,   230,   232,
     231,   231,   233,   233,   234,   234,   234,   234,   234,   234,
     235,   237,   236,   238,   238,   239,   240,   240,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   242,
     243,   244,   244,   245,   246,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   257,   258,   258,
     259,   259,   260,   260,   261,   262,   263,   264,   264,   265,
     265,   266,   266,   267,   268,   268,   268,   268,   269,   270,
     271,   272,   272,   273,   273,   274,   275,   275,   277,   278,
     279,   276,   280,   281,   282,   282,   284,   283,   285,   285,
     286,   287,   287,   288,   289,   289,   290,   291,   292,   292,
     293,   293,   293,   293,   293,   293,   293,   293,   295,   294,
     297,   298,   299,   296,   301,   302,   300,   303,   305,   306,
     304,   308,   309,   307,   311,   310,   312,   312,   313,   314,
     314,   314,   315,   316,   317,   316,   318,   318,   319,   320,
     320,   321,   322,   321,   324,   323,   325,   325,   326,   327,
     328,   328,   330,   329,   331,   329,   332,   333,   334,   334,
     335,   336,   336,   337,   338,   338,   339,   340,   341,   341,
     342,   343,   343,   345,   344,   346,   344,   348,   347,   349,
     349,   351,   350,   352,   352,   353,   354,   354,   355,   356,
     357,   358,   359,   360,   361,   361,   362,   363,   364,   364,
     365,   366,   366,   367,   367,   368,   369,   369,   370,   370,
     371,   371,   372,   372,   372,   372,   373,   374,   374,   374,
     374,   375,   376,   377,   377,   378,   379,   379,   380,   380,
     381,   382,   382,   383,   383,   383,   384,   385,   385,   387,
     386,   388,   389,   389,   389,   389,   389,   390,   390,   391,
     391,   392,   392,   393,   393,   394,   394,   395,   395,   396,
     396,   396,   396,   396,   396,   397,   398,   399,   400,   400,
     401,   402,   403,   403,   404,   405,   406,   406,   407,   407,
     407,   407,   407,   407,   407,   407,   408,   409,   410,   410,
     411,   411,   412,   412,   413,   413,   413,   414,   414,   415,
     416,   416,   417,   417,   417,   417,   418,   418,   418,   418,
     418,   418,   418,   418,   419,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   421,   421,   422,   423,   423,   424,
     425,   426,   427,   427,   428,   427,   429,   429,   430,   430,
     430,   430,   430,   431,   432,   432,   433,   434,   434,   435,
     436,   437,   437,   438,   438,   439,   439,   439,   440,   440,
     440,   441,   441,   441,   442,   442,   442,   443,   443,   444,
     444,   444,   444,   445,   445,   446,   446,   447,   447
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SPARQLfedParser::yyr2_[] =
  {
         0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       0,     1,     2,     0,     1,     0,     2,     2,     0,     0,
       5,     4,     0,     2,     0,     5,     3,     1,     1,     0,
       1,     2,     0,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     5,     5,     1,
       2,     1,     1,     0,     1,     3,     2,     1,     1,     1,
       2,     1,     2,     0,     1,     4,     0,     1,     0,     1,
       0,     1,     0,     1,     3,     1,     2,     1,     1,     4,
       1,     2,     1,     2,     1,     3,     1,     2,     1,     1,
       1,     1,     2,     1,     1,     2,     2,     0,     1,     0,
       1,     2,     2,     0,     6,     0,     2,     1,     2,     0,
       4,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     0,     1,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     0,     1,     3,     0,     1,     3,     3,     5,     5,
       5,     2,     2,     2,     5,     2,     0,     1,     0,     1,
       2,     1,     0,     2,     2,     2,     2,     1,     2,     1,
       2,     0,     1,     2,     1,     1,     1,     1,     3,     3,
       2,     0,     1,     0,     1,     3,     0,     2,     0,     0,
       0,     8,     2,     2,     0,     1,     0,     4,     1,     1,
       2,     0,     1,     3,     0,     2,     2,     2,     0,     1,
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
  "_QBindingsClause_E_Opt", "Prologue", "_QBaseDecl_E_Opt",
  "_QPrefixDecl_E_Star", "BaseDecl", "PrefixDecl", "$@1", "$@2",
  "SelectQuery", "_QDatasetClause_E_Star", "SubSelect", "@3",
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
  "OffsetClause", "BindingsClause", "$@4", "_QVar_E_Star",
  "_QBindingValue_E_Plus",
  "_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C",
  "$@5",
  "_Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star",
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
       167,     0,    -1,   168,    -1,   235,    -1,   169,    -1,   172,
     170,   171,    -1,   179,    -1,   192,    -1,   193,    -1,   197,
      -1,    -1,   227,    -1,   173,   174,    -1,    -1,   175,    -1,
      -1,   174,   176,    -1,    14,   157,    -1,    -1,    -1,    15,
     177,   158,   178,   157,    -1,   183,   180,   203,   205,    -1,
      -1,   180,   198,    -1,    -1,   183,   182,   203,   205,   171,
      -1,    16,   185,   191,    -1,    17,    -1,    18,    -1,    -1,
     184,    -1,    89,   395,    -1,    -1,   186,    -1,    40,   397,
     187,    41,    -1,   395,    -1,   427,    -1,   420,    -1,   315,
      -1,   435,    -1,   439,    -1,   443,    -1,   188,    -1,   189,
      -1,   190,   189,    -1,   190,    -1,    19,    -1,    20,   323,
     180,   203,   205,    -1,    21,   195,   180,   196,   205,    -1,
     394,    -1,   194,   394,    -1,   194,    -1,    19,    -1,    -1,
     203,    -1,    38,   180,   203,    -1,    22,   199,    -1,   200,
      -1,   201,    -1,   202,    -1,    23,   202,    -1,   445,    -1,
     204,   283,    -1,    -1,    39,    -1,   206,   207,   208,   209,
      -1,    -1,   210,    -1,    -1,   213,    -1,    -1,   216,    -1,
      -1,   222,    -1,    90,    25,   211,    -1,   212,    -1,   211,
     212,    -1,   420,    -1,   315,    -1,    40,   397,   187,    41,
      -1,   395,    -1,    91,   214,    -1,   215,    -1,   214,   215,
      -1,   314,    -1,    24,    25,   217,    -1,   218,    -1,   217,
     218,    -1,   220,    -1,   221,    -1,    26,    -1,    27,    -1,
     219,   419,    -1,   314,    -1,   395,    -1,   225,   223,    -1,
     226,   224,    -1,    -1,   226,    -1,    -1,   225,    -1,    28,
     144,    -1,    29,   144,    -1,    -1,    30,   229,    36,   228,
     233,    37,    -1,    -1,   229,   395,    -1,   234,    -1,   230,
     234,    -1,    -1,    40,   232,   230,    41,    -1,   165,    -1,
      -1,   233,   231,    -1,   445,    -1,   435,    -1,   439,    -1,
     443,    -1,    42,    -1,   395,    -1,   236,    -1,    -1,   172,
     241,   237,   240,    -1,    -1,   236,    -1,    49,   238,    -1,
      -1,   239,    -1,   242,    -1,   245,    -1,   247,    -1,   249,
      -1,   250,    -1,   251,    -1,   248,    -1,   252,    -1,   253,
      -1,   254,    -1,   255,    -1,     8,   445,   244,    -1,     9,
     267,    -1,    -1,   243,    -1,    10,   246,   268,    -1,    -1,
      12,    -1,    13,   246,   268,    -1,    11,   246,   267,    -1,
     110,   246,   265,   108,   265,    -1,   123,   246,   265,   108,
     265,    -1,   111,   246,   265,   108,   265,    -1,   125,   270,
      -1,   116,   270,    -1,   114,   269,    -1,   257,   259,   260,
      39,   283,    -1,   103,   445,    -1,    -1,   256,    -1,    -1,
     262,    -1,   261,   258,    -1,   262,    -1,    -1,   260,   263,
      -1,     3,   269,    -1,     4,   269,    -1,   106,   264,    -1,
     445,    -1,    23,   445,    -1,   104,    -1,   266,   445,    -1,
      -1,     6,    -1,     6,   445,    -1,   267,    -1,   104,    -1,
      23,    -1,   105,    -1,    36,   271,    37,    -1,    36,   271,
      37,    -1,   272,   275,    -1,    -1,   280,    -1,    -1,    43,
      -1,   276,   273,   272,    -1,    -1,   275,   274,    -1,    -1,
      -1,    -1,   277,     6,   394,   278,    36,   279,   272,    37,
      -1,   329,   282,    -1,    43,   272,    -1,    -1,   281,    -1,
      -1,    36,   284,   285,    37,    -1,   181,    -1,   286,    -1,
     287,   289,    -1,    -1,   290,    -1,   293,   273,   287,    -1,
      -1,   289,   288,    -1,   344,   292,    -1,    43,   287,    -1,
      -1,   291,    -1,   307,    -1,   294,    -1,   304,    -1,   296,
      -1,   300,    -1,   313,    -1,   303,    -1,   227,    -1,    -1,
      44,   295,   283,    -1,    -1,    -1,    -1,     6,   297,   298,
     394,   299,   283,    -1,    -1,    -1,     7,   301,   302,   394,
     283,    -1,   120,    40,   397,    89,   395,    41,    -1,    -1,
      -1,    45,   305,   306,   283,    -1,    -1,    -1,   308,   309,
     283,   312,    -1,    -1,    46,   311,   283,    -1,    -1,   312,
     310,    -1,    47,   314,    -1,   419,    -1,   420,    -1,   315,
      -1,   445,   316,    -1,   165,    -1,    -1,    40,   318,   397,
     317,   320,    41,    -1,    -1,    17,    -1,    48,   397,    -1,
      -1,   320,   319,    -1,   165,    -1,    -1,    40,   397,   322,
     320,    41,    -1,    -1,    36,   324,   325,    37,    -1,    -1,
     326,    -1,   329,   328,    -1,    43,   325,    -1,    -1,   327,
      -1,    -1,   393,   330,   332,    -1,    -1,   385,   331,   337,
      -1,   343,   339,   336,    -1,   343,   339,    -1,    -1,   333,
      -1,    49,   334,    -1,    -1,   336,   335,    -1,   338,    -1,
      -1,   332,    -1,   342,   341,    -1,    48,   342,    -1,    -1,
     341,   340,    -1,   392,    -1,   394,    -1,    50,    -1,    -1,
     393,   345,   347,    -1,    -1,   385,   346,   355,    -1,    -1,
     349,   348,   339,   354,    -1,   356,    -1,   357,    -1,    -1,
     349,   351,   339,    -1,    -1,   350,    -1,    49,   352,    -1,
      -1,   354,   353,    -1,   338,    -1,   358,    -1,   395,    -1,
     359,    -1,   362,   361,    -1,   102,   362,    -1,    -1,   361,
     360,    -1,   367,   364,    -1,    63,   367,    -1,    -1,   364,
     363,    -1,   373,   366,    -1,    -1,   368,    -1,   365,    -1,
     100,   365,    -1,   372,    -1,    37,    -1,   384,    37,    -1,
      48,   369,    -1,    37,    -1,   384,   370,    -1,    48,   384,
      37,    -1,    19,    -1,   101,    -1,    61,    -1,    36,   371,
      -1,   374,    -1,   445,    -1,    50,    -1,    64,   375,    -1,
      40,   358,    41,    -1,   380,    -1,   102,   381,    -1,    -1,
     377,   376,    -1,   381,   377,    -1,    -1,   378,    -1,   381,
      -1,    40,   379,    41,    -1,   383,    -1,   445,    -1,    50,
      -1,   445,    -1,    50,    -1,   100,   382,    -1,   144,    -1,
     388,    -1,   386,    -1,    -1,    51,   387,   332,    52,    -1,
     390,    40,   391,    41,    -1,    31,    -1,    32,    -1,    33,
      -1,    34,    -1,    35,    -1,    -1,   389,    -1,   392,    -1,
     391,   392,    -1,   393,    -1,   385,    -1,   395,    -1,   396,
      -1,   395,    -1,   445,    -1,   162,    -1,   163,    -1,   445,
      -1,   435,    -1,   439,    -1,   443,    -1,   447,    -1,   165,
      -1,   398,    -1,   401,   400,    -1,    53,   401,    -1,    -1,
     400,   399,    -1,   404,   403,    -1,    54,   404,    -1,    -1,
     403,   402,    -1,   405,    -1,   408,   406,    -1,    -1,   407,
      -1,    55,   408,    -1,    56,   408,    -1,    57,   408,    -1,
      58,   408,    -1,    59,   408,    -1,    60,   408,    -1,    66,
     321,    -1,    65,    66,   321,    -1,   409,    -1,   415,   414,
      -1,   441,    -1,   442,    -1,    19,   417,    -1,    63,   417,
      -1,    -1,   411,    -1,    61,   415,    -1,    62,   415,    -1,
     410,   412,    -1,    -1,   414,   413,    -1,   417,   416,    -1,
      -1,   416,   411,    -1,    64,   418,    -1,    61,   418,    -1,
      62,   418,    -1,   418,    -1,   419,    -1,   420,    -1,   433,
      -1,   435,    -1,   439,    -1,   443,    -1,   395,    -1,   427,
      -1,    40,   397,    41,    -1,    76,    40,   397,    41,    -1,
      77,    40,   397,    41,    -1,    78,    40,   397,    48,   397,
      41,    -1,    79,    40,   397,    41,    -1,    80,    40,   395,
      41,    -1,    67,    40,   397,    41,    -1,    68,    40,   397,
      41,    -1,    69,   421,    -1,   112,   165,    -1,   135,    40,
     397,    41,    -1,   132,    40,   397,    41,    -1,   124,    40,
     397,    41,    -1,   118,    40,   397,    41,    -1,    88,   321,
      -1,   424,    -1,   139,    40,   397,    41,    -1,   136,    40,
     397,    41,    -1,   134,    40,   397,    41,    -1,   130,    40,
     397,    41,    -1,   121,    40,   397,    48,   397,    41,    -1,
     131,    40,   397,    48,   397,    41,    -1,   138,    40,   397,
      48,   397,    41,    -1,   109,    40,   397,    41,    -1,   141,
      40,   397,    41,    -1,   133,    40,   397,    41,    -1,   129,
      40,   397,    41,    -1,   126,    40,   397,    41,    -1,   122,
      40,   397,    41,    -1,   117,    40,   397,    41,    -1,   115,
     165,    -1,   107,    40,   397,    41,    -1,   140,    40,   397,
      41,    -1,   137,    40,   397,    41,    -1,   128,    40,   397,
      41,    -1,   119,    40,   397,    41,    -1,   113,    40,   397,
      41,    -1,    70,   321,    -1,    71,    40,   397,    48,   397,
      48,   397,    41,    -1,    72,    40,   397,    48,   397,    41,
      -1,    73,    40,   397,    48,   397,    41,    -1,    81,    40,
     397,    48,   397,    41,    -1,    82,    40,   397,    41,    -1,
      83,    40,   397,    41,    -1,    84,    40,   397,    41,    -1,
      85,    40,   397,    41,    -1,    99,    40,   397,    41,    -1,
     422,    -1,   425,    -1,   426,    -1,    40,   397,    41,    -1,
     165,    -1,    86,    40,   397,    48,   397,   423,    41,    -1,
      -1,   319,    -1,   127,    40,   397,    48,   397,   423,    41,
      -1,    74,   283,    -1,    65,    74,   283,    -1,    92,    40,
     318,   429,    41,    -1,   430,    40,   318,   397,    41,    -1,
      -1,    97,    40,   318,   397,   428,   432,    41,    -1,    19,
      -1,   397,    -1,    93,    -1,    94,    -1,    95,    -1,    96,
      -1,    98,    -1,    49,    75,    55,   444,    -1,    -1,   431,
      -1,   445,   434,    -1,    -1,   316,    -1,   444,   438,    -1,
      87,   445,    -1,   164,    -1,   436,    -1,    -1,   437,    -1,
     440,    -1,   441,    -1,   442,    -1,   144,    -1,   145,    -1,
     146,    -1,   147,    -1,   148,    -1,   149,    -1,   150,    -1,
     151,    -1,   152,    -1,   142,    -1,   143,    -1,   153,    -1,
     155,    -1,   154,    -1,   156,    -1,   157,    -1,   446,    -1,
     159,    -1,   158,    -1,   160,    -1,   161,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SPARQLfedParser::yyprhs_[] =
  {
         0,     0,     3,     5,     7,     9,    13,    15,    17,    19,
      21,    22,    24,    27,    28,    30,    31,    34,    37,    38,
      39,    45,    50,    51,    54,    55,    61,    65,    67,    69,
      70,    72,    75,    76,    78,    83,    85,    87,    89,    91,
      93,    95,    97,    99,   101,   104,   106,   108,   114,   120,
     122,   125,   127,   129,   130,   132,   136,   139,   141,   143,
     145,   148,   150,   153,   154,   156,   161,   162,   164,   165,
     167,   168,   170,   171,   173,   177,   179,   182,   184,   186,
     191,   193,   196,   198,   201,   203,   207,   209,   212,   214,
     216,   218,   220,   223,   225,   227,   230,   233,   234,   236,
     237,   239,   242,   245,   246,   253,   254,   257,   259,   262,
     263,   268,   270,   271,   274,   276,   278,   280,   282,   284,
     286,   288,   289,   294,   295,   297,   300,   301,   303,   305,
     307,   309,   311,   313,   315,   317,   319,   321,   323,   325,
     329,   332,   333,   335,   339,   340,   342,   346,   350,   356,
     362,   368,   371,   374,   377,   383,   386,   387,   389,   390,
     392,   395,   397,   398,   401,   404,   407,   410,   412,   415,
     417,   420,   421,   423,   426,   428,   430,   432,   434,   438,
     442,   445,   446,   448,   449,   451,   455,   456,   459,   460,
     461,   462,   471,   474,   477,   478,   480,   481,   486,   488,
     490,   493,   494,   496,   500,   501,   504,   507,   510,   511,
     513,   515,   517,   519,   521,   523,   525,   527,   529,   530,
     534,   535,   536,   537,   544,   545,   546,   552,   559,   560,
     561,   566,   567,   568,   573,   574,   578,   579,   582,   585,
     587,   589,   591,   594,   596,   597,   604,   605,   607,   610,
     611,   614,   616,   617,   623,   624,   629,   630,   632,   635,
     638,   639,   641,   642,   646,   647,   651,   655,   658,   659,
     661,   664,   665,   668,   670,   671,   673,   676,   679,   680,
     683,   685,   687,   689,   690,   694,   695,   699,   700,   705,
     707,   709,   710,   714,   715,   717,   720,   721,   724,   726,
     728,   730,   732,   735,   738,   739,   742,   745,   748,   749,
     752,   755,   756,   758,   760,   763,   765,   767,   770,   773,
     775,   778,   782,   784,   786,   788,   791,   793,   795,   797,
     800,   804,   806,   809,   810,   813,   816,   817,   819,   821,
     825,   827,   829,   831,   833,   835,   838,   840,   842,   844,
     845,   850,   855,   857,   859,   861,   863,   865,   866,   868,
     870,   873,   875,   877,   879,   881,   883,   885,   887,   889,
     891,   893,   895,   897,   899,   901,   903,   906,   909,   910,
     913,   916,   919,   920,   923,   925,   928,   929,   931,   934,
     937,   940,   943,   946,   949,   952,   956,   958,   961,   963,
     965,   968,   971,   972,   974,   977,   980,   983,   984,   987,
     990,   991,   994,   997,  1000,  1003,  1005,  1007,  1009,  1011,
    1013,  1015,  1017,  1019,  1021,  1025,  1030,  1035,  1042,  1047,
    1052,  1057,  1062,  1065,  1068,  1073,  1078,  1083,  1088,  1091,
    1093,  1098,  1103,  1108,  1113,  1120,  1127,  1134,  1139,  1144,
    1149,  1154,  1159,  1164,  1169,  1172,  1177,  1182,  1187,  1192,
    1197,  1202,  1205,  1214,  1221,  1228,  1235,  1240,  1245,  1250,
    1255,  1260,  1262,  1264,  1266,  1270,  1272,  1280,  1281,  1283,
    1291,  1294,  1298,  1304,  1310,  1311,  1319,  1321,  1323,  1325,
    1327,  1329,  1331,  1333,  1338,  1339,  1341,  1344,  1345,  1347,
    1350,  1353,  1355,  1357,  1358,  1360,  1362,  1364,  1366,  1368,
    1370,  1372,  1374,  1376,  1378,  1380,  1382,  1384,  1386,  1388,
    1390,  1392,  1394,  1396,  1398,  1400,  1402,  1404,  1406
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   401,   401,   404,   410,   415,   424,   425,   426,   427,
     432,   435,   440,   444,   446,   450,   452,   456,   462,   464,
     462,   474,   482,   485,   493,   493,   504,   512,   515,   522,
     525,   530,   537,   540,   545,   552,   555,   558,   561,   564,
     567,   570,   574,   579,   582,   590,   593,   600,   609,   617,
     620,   628,   631,   638,   641,   646,   654,   661,   662,   666,
     672,   678,   685,   692,   694,   699,   706,   709,   714,   717,
     722,   725,   730,   734,   738,   745,   748,   755,   758,   761,
     764,   770,   776,   779,   786,   791,   798,   802,   810,   812,
     820,   823,   831,   839,   840,   847,   851,   859,   862,   867,
     870,   874,   880,   887,   887,   897,   900,   907,   910,   916,
     916,   922,   928,   931,   938,   941,   944,   947,   950,   953,
     959,   963,   963,   972,   974,   978,   981,   983,   987,   988,
     989,   990,   991,   992,   993,   994,   995,   996,   997,  1001,
    1008,  1015,  1018,  1022,  1028,  1031,  1037,  1043,  1049,  1055,
    1061,  1067,  1075,  1083,  1091,  1100,  1106,  1109,  1113,  1116,
    1120,  1124,  1130,  1132,  1138,  1145,  1152,  1158,  1161,  1167,
    1170,  1175,  1177,  1181,  1187,  1190,  1193,  1196,  1203,  1207,
    1211,  1214,  1216,  1220,  1222,  1226,  1229,  1231,  1236,  1240,
    1243,  1236,  1254,  1258,  1261,  1263,  1268,  1268,  1280,  1281,
    1286,  1290,  1292,  1302,  1306,  1309,  1325,  1330,  1334,  1337,
    1341,  1342,  1343,  1344,  1345,  1346,  1347,  1348,  1352,  1352,
    1367,  1370,  1372,  1367,  1383,  1386,  1383,  1395,  1401,  1404,
    1401,  1414,  1417,  1414,  1427,  1427,  1441,  1443,  1447,  1458,
    1459,  1460,  1464,  1472,  1476,  1476,  1485,  1488,  1495,  1501,
    1503,  1517,  1520,  1520,  1530,  1530,  1538,  1540,  1545,  1550,
    1554,  1556,  1560,  1560,  1563,  1563,  1570,  1575,  1579,  1581,
    1586,  1590,  1592,  1597,  1601,  1603,  1608,  1613,  1617,  1619,
    1623,  1630,  1634,  1642,  1642,  1645,  1645,  1651,  1651,  1657,
    1658,  1662,  1662,  1667,  1669,  1673,  1676,  1678,  1682,  1686,
    1690,  1696,  1700,  1704,  1707,  1709,  1713,  1717,  1722,  1724,
    1730,  1733,  1735,  1741,  1742,  1748,  1752,  1753,  1757,  1758,
    1762,  1763,  1767,  1768,  1769,  1770,  1774,  1778,  1781,  1784,
    1787,  1793,  1797,  1800,  1802,  1806,  1809,  1811,  1815,  1816,
    1820,  1824,  1825,  1829,  1830,  1831,  1835,  1840,  1841,  1845,
    1845,  1858,  1883,  1886,  1889,  1892,  1895,  1902,  1905,  1910,
    1914,  1921,  1922,  1926,  1929,  1933,  1936,  1942,  1943,  1947,
    1950,  1953,  1956,  1959,  1960,  1966,  1971,  1980,  1987,  1990,
    1998,  2007,  2014,  2017,  2024,  2029,  2040,  2043,  2047,  2050,
    2053,  2056,  2059,  2062,  2065,  2068,  2074,  2079,  2088,  2091,
    2098,  2101,  2108,  2111,  2116,  2119,  2123,  2137,  2140,  2148,
    2157,  2160,  2167,  2170,  2173,  2176,  2180,  2181,  2182,  2183,
    2186,  2189,  2192,  2195,  2199,  2205,  2208,  2211,  2214,  2217,
    2220,  2223,  2227,  2230,  2233,  2236,  2239,  2242,  2245,  2248,
    2249,  2252,  2255,  2258,  2261,  2264,  2267,  2270,  2273,  2276,
    2279,  2282,  2285,  2288,  2291,  2294,  2297,  2300,  2303,  2306,
    2309,  2312,  2316,  2319,  2322,  2325,  2328,  2331,  2334,  2337,
    2340,  2343,  2344,  2345,  2351,  2354,  2361,  2368,  2371,  2375,
    2381,  2388,  2395,  2398,  2402,  2402,  2414,  2418,  2422,  2425,
    2428,  2431,  2434,  2440,  2446,  2449,  2453,  2463,  2466,  2471,
    2479,  2486,  2490,  2498,  2502,  2506,  2507,  2508,  2512,  2513,
    2514,  2518,  2519,  2520,  2524,  2525,  2526,  2530,  2531,  2535,
    2536,  2537,  2538,  2542,  2543,  2547,  2548,  2552,  2553
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
  const int SPARQLfedParser::yylast_ = 2077;
  const int SPARQLfedParser::yynnts_ = 282;
  const int SPARQLfedParser::yyempty_ = -2;
  const int SPARQLfedParser::yyfinal_ = 11;
  const int SPARQLfedParser::yyterror_ = 1;
  const int SPARQLfedParser::yyerrcode_ = 256;
  const int SPARQLfedParser::yyntokens_ = 166;

  const unsigned int SPARQLfedParser::yyuser_token_number_max_ = 420;
  const SPARQLfedParser::token_number_type SPARQLfedParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 5063 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 2559 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


