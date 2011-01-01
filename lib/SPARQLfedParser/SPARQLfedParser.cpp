
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
#line 379 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

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
#line 393 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 396 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 402 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(2) - (2)].p_Operation);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 433 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 439 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 441 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 443 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 451 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(5) - (3)].p_WhereClause)->m_BindingClause = (yysemantic_stack_[(5) - (5)].p_BindingsClause);
	(yyval.p_Operation) = new Select((yysemantic_stack_[(5) - (1)].p_Project).distinctness, (yysemantic_stack_[(5) - (1)].p_Project).varSet, (yysemantic_stack_[(5) - (2)].p_DatasetClauses), (yysemantic_stack_[(5) - (3)].p_WhereClause), (yysemantic_stack_[(5) - (4)].p_SolutionModifier));
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 459 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 462 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 470 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 473 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yysemantic_stack_[(5) - (3)].p_WhereClause)->m_BindingClause = (yysemantic_stack_[(5) - (5)].p_BindingsClause);
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(5) - (1)].p_Project).distinctness, (yysemantic_stack_[(5) - (1)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(5) - (3)].p_WhereClause), (yysemantic_stack_[(5) - (4)].p_SolutionModifier))));
      }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 481 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 489 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 492 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 499 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 507 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 514 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 522 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 529 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 532 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 535 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 538 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 541 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 544 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 547 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 556 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 559 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 567 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 570 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 577 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(6) - (4)].p_WhereClause)->m_BindingClause = (yysemantic_stack_[(6) - (6)].p_BindingsClause);
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	(yyval.p_Operation) = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(6) - (2)].p_BasicGraphPattern), (yysemantic_stack_[(6) - (3)].p_DatasetClauses), (yysemantic_stack_[(6) - (4)].p_WhereClause), (yysemantic_stack_[(6) - (5)].p_SolutionModifier));
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 586 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(6) - (4)].p_WhereClause))
	    (yysemantic_stack_[(6) - (4)].p_WhereClause)->m_BindingClause = (yysemantic_stack_[(6) - (6)].p_BindingsClause);
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(6) - (2)].p_VarSet), (yysemantic_stack_[(6) - (3)].p_DatasetClauses), (yysemantic_stack_[(6) - (4)].p_WhereClause), (yysemantic_stack_[(6) - (5)].p_SolutionModifier));
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 595 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm))));
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 598 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_TTerm))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 606 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 609 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 616 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 624 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(4) - (3)].p_WhereClause)->m_BindingClause = (yysemantic_stack_[(4) - (4)].p_BindingsClause);
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause));
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 632 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 644 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 650 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 656 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 663 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp ? driver.curOp : new DefaultGraphPattern(), NULL);
	driver.curOp = NULL;
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 677 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 684 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 692 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 700 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 708 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 716 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 723 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 726 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 733 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 736 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 739 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 742 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 748 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 754 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 757 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 769 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 776 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 780 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 790 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 798 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 801 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 809 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 818 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 825 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 829 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 837 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 845 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 852 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 858 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 871 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTermList) = new TTermList;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 874 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTermList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_TTermList) = (yysemantic_stack_[(2) - (1)].p_TTermList);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 881 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 884 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 890 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding = new Binding();
      }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 892 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingValue) = driver.curBinding;
	  driver.curBinding = NULL;
      }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 896 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding = new Binding();
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 902 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 905 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingsClause->push_back((yysemantic_stack_[(2) - (2)].p_BindingValue));
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 912 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingsClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_TTermList));
      }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 914 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingsClause) = driver.curBindingsClause;
	  driver.curBindingsClause = NULL;
      }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 921 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingsClause) = NULL;
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 928 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 931 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 934 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 937 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 940 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 943 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 953 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	OperationSet* ret = driver.root ? dynamic_cast<OperationSet*>(driver.root) : new OperationSet();
	ret->push_back((yysemantic_stack_[(2) - (2)].p_Operation));
	driver.root = ret;
      }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 957 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Operation) = driver.root;
	}
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 988 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(3) - (2)].p_URI), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 995 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1002 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1009 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1015 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1018 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1024 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1030 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1036 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert(driver.curOp, NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1058 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete(driver.curOp, NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1066 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1069 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(5) - (3)].p_TableOperation), NULL);
      }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1076 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(4) - (1)].p_DeleteInsert).del, (yysemantic_stack_[(4) - (1)].p_DeleteInsert).ins, new WhereClause(driver.curOp, NULL));
	driver.curOp = NULL;
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1080 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1086 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1093 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1097 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1105 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("_QUsingClause_E_Star");
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1111 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1117 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Delete) = new Delete(driver.curOp, NULL);
	driver.curOp = NULL;
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1124 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = new Insert(driver.curOp, NULL);
	driver.curOp = NULL;
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1131 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1137 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 1140 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 1197 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 1203 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1206 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("DEFAULT");
      }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1209 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("NAMED");
      }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1212 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("ALL");
      }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 1247 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curFilter = NULL;
      }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 1251 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 1254 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 1257 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 1279 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 1282 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 1361 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 1364 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 207:

/* Line 678 of lalr1.cc  */
#line 1376 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 1379 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 1381 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 1384 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 1392 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 1395 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 1397 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(5) - (4)].p_TTerm), driver.curOp, driver.atomFactory, false));
      }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 1404 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 1407 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 1409 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.curOp));
      }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 1417 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 1420 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 1422 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 1430 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 1435 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 1450 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    if (driver.curOp == NULL)
		driver.ensureBasicGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 1467 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 1475 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 1479 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 1481 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = NULL;
      }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 1488 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 1491 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 1498 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 1506 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 1520 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 1523 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 1525 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 1533 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 1535 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 1563 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 1566 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 1626 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 1633 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 1637 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 1645 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 1648 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 1654 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 1665 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 1693 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 1720 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 1727 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 1738 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 1745 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 1781 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 1784 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 1787 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 1790 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 1848 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 1852 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 1861 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 338:

/* Line 678 of lalr1.cc  */
#line 1886 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 1889 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 1892 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 1895 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 1898 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 1905 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 1913 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 1917 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 1929 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 1936 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 1939 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 1950 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 1953 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 1956 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 1959 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 1963 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 1974 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 1983 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 1990 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 1993 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 2001 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 2010 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 2017 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 2020 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 2032 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_GeneralComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_GeneralComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_GeneralComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 2043 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 2050 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 2053 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 2056 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 2059 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 2062 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 2065 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 2068 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 2071 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 2082 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 2091 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 2094 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 2101 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 2104 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 2111 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 2119 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 2122 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 2126 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 393:

/* Line 678 of lalr1.cc  */
#line 2140 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 2143 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 2151 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 2160 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 2163 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 2170 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 2173 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 2176 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 2186 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 2189 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 2192 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 2195 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 2202 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 2208 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 2211 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 2214 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 2217 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 2220 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 2223 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 2226 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 2230 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_blank, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 2233 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 2237 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 2240 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 2243 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 2246 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 2249 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 2252 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 2255 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 2258 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 2261 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 2264 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::XPATH_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 2275 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 2278 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 2285 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_regex, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 2292 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 2299 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 2306 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 2313 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 2316 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 2320 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 2322 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  // x = new ArgList($2, driver.curExprList);
	  delete driver.curExprList;
	  driver.curExprList = NULL;
	  w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // $$ = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group-concat, $3, $4.p_Expression, $4.separator));
    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 2332 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
	driver.countStar = true;
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 2340 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 2343 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 2346 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 2349 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 2352 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 2358 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 2364 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 2371 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 2381 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 2389 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 2397 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 2404 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 2408 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 2416 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 3095 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -616;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        19,   -66,    70,  -616,    58,  -616,  -616,  -616,  -616,  -616,
    -616,    45,    55,    69,    73,    73,    73,    65,    62,    15,
    -616,    69,  -616,  -616,  -616,  -616,  -616,  -616,  -616,  -616,
    -616,  -616,  -616,  -616,  -616,  -616,  -616,  -616,   195,   107,
    -616,   109,   104,  1067,   104,  -616,   104,  -616,  -616,  -616,
    -616,   141,  -616,  -616,    18,   150,    18,  -616,  -616,  -616,
     945,  -616,  -616,  -616,  -616,  -616,   203,  -616,  -616,  -616,
    -616,    37,  -616,    37,   110,   -19,   104,   104,  -616,  -616,
    -616,  -616,  -616,  -616,  -616,  -616,  -616,  -616,  -616,  -616,
    -616,  -616,  -616,  -616,  -616,  -616,  -616,  -616,  -616,  -616,
    -616,  -616,  -616,  -616,  -616,  -616,  -616,  -616,   126,  -616,
    -616,   127,  -616,  -616,  -616,  -616,   137,  -616,  -616,  -616,
    -616,  -616,  -616,  -616,  -616,  -616,   -39,  -616,  -616,  -616,
    -616,   150,  -616,  -616,    69,  -616,  -616,  -616,  -616,  -616,
    -616,  -616,  -616,  1206,   111,   177,   184,    -4,     0,   186,
     196,   201,   175,   214,   216,   223,   229,   231,   236,   241,
     254,   258,   259,   261,     0,   262,  -616,  -616,  -616,  -616,
     263,  -616,   268,  -616,  -616,  1270,  -616,  -616,  -616,  -616,
    -616,  -616,  -616,  -616,   269,  -616,  -616,  -616,     2,  1067,
      37,  -616,   135,    22,  -616,  -616,   281,   175,   224,   100,
    -616,  -616,   175,    31,  -616,   -12,   189,    59,  -616,   311,
    1067,  -616,  -616,    59,  1117,    59,    69,  -616,  -616,  -616,
    -616,   282,  -616,  -616,  1206,  1334,  1334,  1334,  -616,   234,
    -616,  -616,  -616,  -616,   425,  -616,  -616,  -616,  -616,  -616,
    -616,  -616,  -616,  -616,  -616,  -616,     2,   175,  1206,  1206,
    1206,  -616,  -616,  1206,  -616,  -616,  1206,  1206,  1206,  -616,
    -616,  1206,  1206,  1206,  1206,   101,  1206,  1206,  1206,  1206,
    1206,  1206,  -616,   303,   303,  1206,  -616,   303,   303,  -616,
    -616,   287,  -616,   285,   224,   224,  -616,    69,  -616,  -616,
    -616,  -616,  -616,  -616,  -616,  -616,  -616,  -616,   307,   281,
     243,  -616,   102,  -616,  -616,  -616,    69,  -616,  -616,   175,
    -616,  -616,   283,  1117,  -616,  -616,   294,   338,  -616,  -616,
    -616,  -616,  -616,  1093,  -616,  -616,  -616,  -616,  -616,   304,
    -616,  -616,  -616,   101,  -616,   305,   296,   297,  1206,  1206,
    1206,  1206,  1206,  1206,   284,     0,  -616,  -616,   278,    25,
    -616,  -616,  -616,   313,   314,   315,  -616,   309,   312,   316,
     731,   318,   321,   319,   329,   330,   324,   333,   335,   336,
     337,   334,  -616,   860,  1206,   340,  1206,  1206,  -616,  1067,
    -616,  -616,   281,   281,  -616,    39,  1398,  -616,  1487,   359,
    -616,  -616,  -616,   266,  -616,  -616,  -616,  -616,  -616,  1067,
     203,  -616,  -616,  -616,  -616,  -616,  1206,  -616,  1206,  -616,
    -616,  -616,  -616,  -616,  -616,  -616,     0,  -616,  1206,  1206,
      25,  -616,  -616,  -616,  1206,  1206,  -616,  -616,  -616,  -616,
    -616,  1206,  1206,  1206,  -616,  -616,   347,  -616,  -616,  -616,
     353,  -616,  -616,  -616,  -616,  1206,  -616,  -616,  1206,  -616,
    -616,  -616,  -616,  1206,  -616,  -616,   356,  -616,  -616,   357,
    -616,  -616,  -616,  -616,  -616,  -616,  1206,  1398,  -616,  -616,
    -616,  -616,  1487,  -616,  -616,  -616,  -616,  -616,   375,   222,
    -616,  -616,   352,   354,  -616,  -616,  -616,  -616,  -616,  -616,
    -616,  -616,  -616,  -616,  -616,    17,   355,   363,   366,   282,
    -616,   271,  1067,  -616,  -616,    59,   125,   374,   377,   373,
    -616,   376,  -616,  -616,  -616,   234,  -616,  -616,  1009,   317,
     320,  -616,  -616,   393,   395,    59,  -616,  1117,  -616,   388,
    -616,  1206,  -616,  1206,  -616,  -616,   224,  -616,  -616,  -616,
    -616,  1487,  -616,   294,  -616,  -616,  -616,  -616,  -616,  -616,
    -616,  -616,  -616,  -616,   173,  -616,   138,   182,  -616,  -616,
    -616,  -616,  -616,  -616,  -616,  -616,  -616,    16,  -616,  -616,
    -616,  -616,  -616,  -616,   389,   358,  -616,   390,    88,   -11,
     396,  -616,  -616,  1009,  -616,   394,  -616,  -616,  -616,  -616,
    -616,  -616,  -616,  -616,  -616,  -616,  -616,  -616,  1117,  -616,
    -616,  -616,   397,   281,  -616,  -616,   175,  -616,  -616,  1067,
     175,   398,   164,  -616,    97,  -616,  -616,  -616,  -616,  -616,
    -616,  1117,   339,   379,  -616,    -5,  -616,  -616,  -616,  -616,
    -616,  -616,   391,  -616,  -616,  -616,  -616,  -616,  -616,  -616,
    -616,  -616,  -616,  1067,  -616,  -616,   203,   203,  -616,   175,
    -616,  -616,  -616,  -616,   402,  -616,  -616,  -616,  -616,  -616,
     173,  -616,   173,  -616,   341,  -616,  -616,     9,   171,  1422,
     408,  -616,   175,  -616,   401,  -616,   346,   403,  -616,  -616,
     414,  -616,    -6,  -616,  -616,  -616,   691,  -616,  -616,  -616,
    -616,  -616,  -616,  -616,   175,  -616,  -616,  -616,   164,  -616,
     125,  -616,  -616,  -616,  -616,   416,  -616,  -616,  -616,   175,
    -616,  -616,  -616,  -616,  -616,  -616,  1117,  -616
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        10,     0,     0,     2,     0,    12,    11,     3,   120,    14,
       1,     0,     0,     0,   141,   141,   141,    26,     0,     0,
      19,     0,     4,     5,    19,     6,     7,     8,   121,   128,
     129,   130,   131,   132,   133,   134,   135,   155,     0,   151,
     154,     9,     0,   170,     0,   158,     0,   159,   481,   484,
     483,   138,   482,   142,     0,     0,     0,    24,    25,    27,
       0,   240,    19,    49,   353,   354,    48,    19,    46,   351,
     352,    60,   157,    60,   126,     0,     0,     0,   155,   153,
     152,    15,    13,   146,   338,   339,   340,   341,   342,   335,
     475,   476,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   477,   479,   478,   480,   485,   486,   360,     0,   175,
     171,   183,   250,   334,   333,   344,     0,   248,   349,   350,
     356,   357,   463,   464,   465,   358,   461,   355,   359,   147,
     145,     0,   139,   136,     0,   166,   165,   167,   164,   140,
     144,   143,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   446,   447,   448,   449,
       0,   450,     0,    39,    40,    42,    23,    35,    32,    34,
     430,   431,   432,    33,     0,    36,    37,    38,     0,   242,
      60,    47,    50,     0,    61,    20,   112,     0,    63,    10,
     127,   122,     0,     0,   156,     0,     0,     0,   168,   169,
     170,   184,   181,   260,   343,     0,     0,   459,   460,   462,
     457,    60,   137,   163,     0,     0,     0,     0,   408,    29,
     361,   364,   368,   370,   372,   382,   393,   396,   401,   402,
     403,   409,   404,   405,   406,   407,   455,     0,     0,     0,
       0,   434,   418,     0,   237,   419,     0,     0,     0,   185,
     438,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   429,   232,   232,     0,    41,   232,   232,   229,
     228,     0,   243,   246,    63,    63,    51,     0,    53,    54,
      55,    56,    58,   101,    52,   113,   100,    59,     0,   112,
      65,    64,     0,   124,   125,   149,     0,   160,   161,     0,
      16,   268,     0,   343,   267,   176,   172,     0,   182,   261,
     251,   259,   348,   343,   345,   347,   249,   458,   148,     0,
     399,   400,   398,     0,    30,     0,   362,   366,     0,     0,
       0,     0,     0,     0,     0,     0,   371,   373,   383,   395,
     456,   454,   439,     0,     0,     0,   238,     0,     0,     0,
     190,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   233,     0,     0,     0,     0,     0,   241,   242,
     247,   244,   112,   112,    57,     0,     0,    18,     0,    67,
      66,   162,   150,     0,   336,   257,   264,   266,   173,   170,
       0,   337,   346,   410,    28,    31,     0,   365,     0,   369,
     374,   375,   376,   377,   378,   379,     0,   380,     0,     0,
     388,   394,   384,   385,     0,     0,   397,   416,   417,   433,
     235,     0,     0,     0,   187,    21,     0,   188,   193,   191,
     197,   271,   269,   411,   412,     0,   414,   415,     0,   424,
     425,   426,   427,     0,   444,   445,     0,   442,   428,     0,
     230,   245,    44,    45,   110,   102,     0,    71,    72,    75,
      77,    74,    78,    79,    81,   227,   225,   226,     0,    69,
      68,    17,   252,   262,   174,   178,   363,   367,   381,   390,
     391,   389,   392,   386,   387,     0,     0,     0,     0,    60,
     186,   189,   190,   198,   195,   260,     0,     0,     0,   436,
     440,   452,   441,   235,   108,    29,    73,    80,     0,     0,
       0,    62,    70,    94,    96,   254,   258,   343,   265,     0,
     239,     0,   236,     0,   421,   422,    63,   207,   211,   205,
     214,     0,   194,   172,   200,   202,   203,   201,   199,   218,
     204,   196,   284,   272,     0,   314,     0,     0,   270,   273,
     275,   276,   285,   287,   290,   299,   294,   297,   312,   286,
     313,   413,   423,   437,     0,     0,   453,     0,     0,     0,
       0,    87,    88,    82,    83,     0,    85,    86,    90,    91,
      98,    99,    92,    95,    93,    97,   255,   256,   343,   263,
     179,   234,     0,   112,   208,   212,     0,   215,   224,   190,
       0,     0,   322,   330,     0,   315,   317,   324,   326,   329,
     300,   343,   288,   292,   308,     0,   310,   309,   296,   298,
     301,   435,     0,   443,   231,   111,   105,   107,   109,    76,
      84,    89,   253,   170,   420,    22,     0,     0,   206,     0,
     192,   222,   316,   323,     0,   319,   328,   331,   327,   282,
       0,   291,     0,   295,     0,   332,   311,     0,     0,     0,
       0,   209,     0,   216,   219,   325,   321,   274,   289,   293,
       0,   305,     0,   306,   451,   118,     0,   103,   119,   115,
     116,   117,   114,   180,     0,   213,   220,   223,     0,   320,
     279,   283,   307,   302,   304,     0,   106,   104,   210,     0,
     318,   277,   280,   281,   303,   221,   343,   278
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -616,  -616,  -616,  -616,   257,  -616,  -616,  -616,  -616,  -616,
    -616,  -616,    40,  -616,  -616,    98,  -616,  -616,  -616,   -58,
    -616,   288,  -616,  -616,  -616,  -616,  -616,  -616,  -616,  -616,
    -616,  -616,  -616,  -616,   178,   -72,  -616,  -271,  -616,  -616,
    -616,  -616,  -616,  -616,    -7,  -616,  -616,   -10,  -616,  -616,
    -117,  -616,  -616,  -616,  -616,  -616,  -616,   -57,   -55,  -290,
    -616,  -616,  -616,  -616,  -616,  -616,  -616,  -616,  -217,  -616,
     273,  -616,  -616,  -616,  -616,  -616,  -616,  -616,  -616,  -616,
     252,  -616,  -616,  -616,  -616,  -616,  -616,  -616,  -616,   432,
     399,  -616,  -616,   434,  -616,  -616,   -30,   418,   198,  -616,
    -203,   -67,  -616,  -616,  -616,  -616,  -616,  -616,  -616,  -616,
    -616,  -174,  -616,  -616,  -616,  -481,  -616,  -616,  -616,  -616,
    -616,  -616,  -616,  -616,  -616,  -616,  -616,  -616,  -616,  -616,
    -616,  -616,  -616,  -616,  -616,  -616,  -616,  -616,  -616,  -616,
    -616,  -486,   -50,   232,  -616,   -62,   -21,   -34,  -161,  -616,
    -616,  -616,   115,  -616,  -616,  -616,  -172,  -616,  -616,   -47,
    -616,  -616,  -616,  -616,  -616,    -9,  -583,  -616,  -616,   -28,
     -25,  -616,  -616,  -616,  -616,  -616,  -199,  -616,  -616,  -616,
    -616,  -616,  -616,  -616,  -616,   -52,  -616,  -616,  -616,  -163,
    -616,  -616,   -54,  -616,  -158,  -616,  -616,  -616,  -616,  -616,
    -616,  -616,  -616,  -616,  -616,  -616,  -616,  -616,  -590,  -616,
    -616,  -615,   -38,  -616,  -616,  -616,  -616,  -616,  -616,  -196,
     -31,   -15,    20,  -616,   460,  -616,  -616,  -616,   103,  -616,
    -616,    99,  -616,  -616,  -616,    71,  -616,  -616,    86,  -616,
    -616,  -616,  -139,  -616,  -141,    32,  -377,   -23,  -616,  -616,
    -616,  -616,  -616,   -44,  -616,  -616,  -616,  -616,  -616,  -616,
    -616,   -41,  -616,  -616,  -616,    29,  -616,   160,   162,    56,
    -157,   -13,  -616,  -616
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,     3,    22,     4,     5,    41,     6,    82,   206,
     393,    23,    71,   434,   499,    24,    59,    60,   334,   335,
     173,   174,   175,   176,    25,    26,    66,    67,   285,    27,
     195,   288,   289,   290,   291,   196,   197,   299,   300,   389,
     479,   521,   301,   467,   468,   390,   472,   473,   480,   583,
     584,   585,   586,   587,   522,   592,   594,   523,   524,   294,
     385,   686,   638,   669,   579,   295,   514,   296,   687,     7,
       8,    74,   304,   200,   201,    28,    29,   132,   133,    30,
      54,    31,    32,    33,    34,    35,   221,    36,    79,    37,
      75,    38,    39,    40,   204,   307,   138,   139,    45,   108,
     109,   399,   315,   209,   316,   317,   529,   643,   110,   211,
     212,   260,   360,   436,   437,   438,   542,   501,   439,   503,
     504,   543,   544,   606,   545,   604,   646,   694,   546,   605,
     647,   547,   607,   649,   548,   549,   610,   697,   709,   674,
     550,   474,   475,   280,   513,   373,   532,   495,   255,   430,
      62,   189,   281,   282,   380,   381,   111,   215,   213,   319,
     596,   597,   526,   482,   320,   321,   395,   528,   483,   396,
     313,   440,   506,   505,   558,   621,   559,   712,   716,   713,
     701,   677,   553,   560,   561,   562,   563,   661,   622,   564,
     663,   623,   565,   628,   566,   629,   704,   683,   666,   630,
     567,   568,   615,   699,   676,   653,   654,   616,   617,   657,
     618,   667,   322,   113,   207,   114,   115,   116,   323,   397,
     325,   314,   228,   119,   229,   230,   407,   336,   231,   409,
     337,   232,   233,   346,   347,   234,   235,   420,   426,   492,
     421,   348,   236,   349,   237,   238,   239,   240,   252,   180,
     574,   181,   182,   241,   511,   456,   184,   576,   577,   242,
     351,   243,   218,   219,   220,   244,   122,   123,   124,   245,
     126,   246,    52,   128
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SPARQLfedParser::yytable_ninf_ = -344;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        51,   198,   120,   272,    68,   112,    70,   318,    72,   387,
     177,   476,   117,   382,   383,   642,   183,   283,   324,   185,
     202,   551,   655,   297,   134,   140,   635,   309,   305,   636,
     127,   703,   588,     1,    63,   624,   250,   179,   659,    69,
     253,   135,   278,   664,   424,   287,   681,   188,   216,   680,
      42,   191,   625,    70,   306,   608,     9,   682,   530,   193,
      46,    11,    12,   118,    73,   531,    13,   705,    14,    15,
      10,    16,   121,   352,    17,   464,   194,   626,    18,    19,
     178,    43,    57,    58,    44,    53,    69,   203,   425,   186,
     217,    43,   462,   463,   203,   476,    20,   588,    61,   125,
    -123,   222,   190,   665,   665,    11,    12,   192,   710,   311,
      13,    77,    14,    15,     1,    16,   187,   627,   284,   637,
     286,   223,   136,   137,    81,   177,   251,   402,   650,   634,
     254,   183,   279,   717,   185,   392,   531,    48,    49,    50,
      43,   476,    64,    65,    48,    49,    50,   656,   120,   328,
     131,   112,   179,    48,    49,    50,   134,   193,   117,   199,
     312,    21,   188,   208,   476,   554,    64,    65,   326,   120,
     210,   -60,   112,   120,   194,   555,   127,   214,   612,   117,
     292,    48,    49,    50,   417,   247,    64,    65,   613,   556,
     308,    48,    49,    50,    70,   178,   484,   127,    76,    77,
      70,   127,    70,   327,   186,    21,   476,   283,   641,   118,
      47,   259,   374,   554,   613,   376,   377,   248,   121,    48,
      49,    50,   554,   555,   249,   557,   256,    69,    64,    65,
     118,   187,   555,    69,   118,    69,   257,   556,   614,   121,
      83,   258,   129,   121,   130,   125,   556,    48,    49,    50,
     519,   520,    64,    65,   261,   488,   262,   330,   331,   332,
      48,    49,    50,   263,   614,   603,   125,    55,    56,   264,
     125,   265,   120,   557,   292,    47,   266,   537,   538,   489,
     490,   267,   120,   493,   494,   365,    48,    49,    50,   101,
     102,   103,   104,   391,   268,    48,    49,    50,   269,   270,
     127,   271,   273,   274,    48,    49,    50,  -217,   275,   277,
     127,   293,   310,   645,   298,   539,   540,  -177,   541,   120,
     372,   194,   441,   333,   378,    48,    49,    50,   379,   442,
      64,    65,   386,   118,   388,   394,   469,   398,   120,   418,
     419,   112,   121,   118,   400,   403,   405,   127,   117,   406,
     416,   408,   121,   404,   427,   428,   429,   431,   120,   443,
     432,   112,   444,   471,   433,   477,   127,   445,   117,   125,
     446,   447,   448,   188,   449,   188,   450,   451,   452,   125,
     118,   458,   453,   478,   500,   485,   127,    70,   481,   121,
      95,    96,    97,    98,    99,   100,   502,   510,   512,   118,
     518,   525,   527,   533,   534,   465,   470,   535,   121,   410,
     411,   412,   413,   414,   415,   571,   125,   469,   572,   118,
      69,   531,   520,   519,   600,   575,   590,   536,   121,   591,
     631,   633,   648,   632,   224,   125,   651,   639,   644,   652,
     670,   660,   662,   675,   471,   693,   668,   696,   698,   477,
     665,   702,   700,   714,   188,   125,   302,   580,   435,   188,
     516,   120,   517,   276,   441,   384,   640,   595,   593,   707,
      78,   442,   303,    80,   141,   673,   609,   205,   350,   578,
     338,   339,   340,   341,   342,   343,   120,   470,   573,   127,
     344,   345,    70,   570,   461,   477,   552,   678,   695,   599,
     598,   711,   611,   620,   679,   188,   491,   487,   422,   486,
     423,   684,    70,     0,   127,     0,     0,     0,   477,     0,
     708,     0,   118,     0,     0,    69,   569,     0,   188,     0,
       0,   121,     0,     0,     0,   715,     0,     0,   589,     0,
       0,   570,     0,   619,   570,    69,     0,   118,     0,     0,
       0,     0,     0,     0,     0,     0,   121,   120,   125,     0,
     477,     0,     0,     0,     0,     0,     0,     0,   120,     0,
     188,   441,     0,     0,     0,     0,     0,     0,   442,     0,
     120,     0,     0,   125,     0,   127,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   127,     0,     0,   619,
       0,   658,   120,   589,     0,   112,     0,     0,   127,     0,
       0,     0,   117,     0,     0,     0,     0,     0,   118,     0,
       0,     0,     0,     0,     0,     0,     0,   121,   689,   118,
     127,   671,   672,    70,    70,     0,     0,     0,   121,     0,
       0,   118,     0,     0,     0,   689,     0,   570,     0,   570,
     121,     0,     0,     0,   125,     0,   692,     0,     0,     0,
       0,     0,     0,   118,     0,   125,    69,    69,     0,     0,
       0,     0,   121,   692,     0,   120,     0,   125,     0,     0,
       0,     0,     0,     0,   329,   619,     0,   570,     0,   688,
       0,     0,     0,     0,     0,     0,     0,     0,   690,   125,
       0,     0,     0,   127,     0,     0,   688,     0,   353,   354,
     355,     0,     0,   356,     0,   690,   357,   358,   359,     0,
     569,   361,   362,   363,   364,   691,   366,   367,   368,   369,
     370,   371,   706,   685,     0,   375,   118,     0,     0,     0,
       0,     0,   691,     0,     0,   121,     0,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,    85,    86,    87,    88,     0,     0,     0,
       0,  -343,   125,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    48,    49,    50,     0,     0,    64,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   455,   457,     0,   459,   460,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    48,    49,    50,   105,   106,    64,    65,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   496,   497,   498,     0,     0,     0,     0,     0,     0,
     224,     0,     0,     0,     0,   507,     0,     0,   508,     0,
       0,     0,     0,   509,     0,     0,     0,     0,     0,     0,
       0,   225,   226,     0,   227,   144,   515,   145,   146,   147,
     148,   149,   150,   151,   152,     0,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,     0,   164,     0,
       0,     0,   165,   166,   167,   168,   169,   170,   171,   172,
       0,     0,     0,     0,   142,     0,     0,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    48,    49,    50,   143,     0,    64,    65,     0,
       0,   601,     0,   602,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     144,     0,   145,   146,   147,   148,   149,   150,   151,   152,
       0,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,     0,   164,     0,   581,   582,   165,   166,   167,
     168,   169,   170,   171,   172,     0,     0,     0,     0,   224,
       0,     0,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    48,    49,    50,
       0,     0,    64,    65,   144,     0,   145,   146,   147,   148,
     149,   150,   151,   152,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,     0,   164,    84,    85,
      86,    87,    88,     0,     0,     0,     0,  -343,   172,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,     0,
       0,     0,     0,     0,    84,    85,    86,    87,    88,     0,
       0,    48,    49,    50,   401,     0,    64,    65,     0,     0,
       0,     0,     0,     0,    89,     0,     0,     0,    84,    85,
      86,    87,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,     0,
       0,     0,     0,     0,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    48,
      49,    50,   105,   106,    64,    65,     0,   107,     0,     0,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,    48,    49,    50,   105,   106,
      64,    65,     0,   107,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    48,
      49,    50,   105,   106,    64,    65,   224,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   225,   226,     0,
     227,   144,     0,   145,   146,   147,   148,   149,   150,   151,
     152,     0,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,     0,   164,     0,     0,     0,   165,   166,
     167,   168,   169,   170,   171,   172,     0,     0,     0,     0,
     143,     0,     0,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    48,    49,
      50,     0,     0,    64,    65,   144,     0,   145,   146,   147,
     148,   149,   150,   151,   152,     0,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,     0,   164,     0,
       0,     0,   165,   166,   167,   168,   169,   170,   171,   172,
       0,     0,     0,     0,   224,     0,     0,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    48,    49,    50,     0,     0,    64,    65,   144,
       0,   145,   146,   147,   148,   149,   150,   151,   152,     0,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,     0,   164,     0,     0,     0,   165,   166,   167,   168,
     169,   170,   171,   172,     0,     0,     0,     0,   466,     0,
       0,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    48,    49,    50,     0,
       0,    64,    65,   144,   685,   145,   146,   147,   148,   149,
     150,   151,   152,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,     0,   164,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   172,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,    49,    50,     0,     0,    64,    65,   224,     0,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    48,    49,    50,     0,     0,    64,
      65,     0,   144,     0,   145,   146,   147,   148,   149,   150,
     151,   152,     0,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,     0,   164,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   172,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
      49,    50
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        13,    73,    43,   164,    19,    43,    19,   210,    21,   299,
      60,   388,    43,   284,   285,   598,    60,   189,   214,    60,
      39,   502,   612,   197,     6,    55,    37,    39,   202,    40,
      43,    37,   518,    14,    19,    19,    40,    60,   621,    19,
      40,    23,    40,    48,    19,    23,    37,    60,    87,   664,
       5,    66,    36,    66,    23,   541,   122,    48,    41,    22,
       5,     3,     4,    43,    24,    48,     8,   682,    10,    11,
       0,    13,    43,   247,    16,    36,    39,    61,    20,    21,
      60,    36,    17,    18,    39,    12,    66,   106,    63,    60,
     129,    36,   382,   383,   106,   472,    38,   583,    36,    43,
       0,   131,    62,   109,   109,     3,     4,    67,   698,    50,
       8,     4,    10,    11,    14,    13,    60,   101,   190,   130,
     192,   134,   104,   105,    15,   175,   130,   323,   609,    41,
     130,   175,   130,   716,   175,   309,    48,   122,   123,   124,
      36,   518,   127,   128,   122,   123,   124,    50,   189,   221,
       9,   189,   175,   122,   123,   124,     6,    22,   189,    49,
     207,   103,   175,    37,   541,    40,   127,   128,   215,   210,
      43,    36,   210,   214,    39,    50,   189,    40,    40,   210,
     193,   122,   123,   124,   345,    74,   127,   128,    50,    64,
     203,   122,   123,   124,   207,   175,   399,   210,     3,     4,
     213,   214,   215,   216,   175,   103,   583,   379,   585,   189,
      12,    36,   274,    40,    50,   277,   278,    40,   189,   122,
     123,   124,    40,    50,    40,   100,    40,   207,   127,   128,
     210,   175,    50,   213,   214,   215,    40,    64,   100,   210,
      42,    40,    44,   214,    46,   189,    64,   122,   123,   124,
      28,    29,   127,   128,    40,   416,    40,   225,   226,   227,
     122,   123,   124,    40,   100,   536,   210,    15,    16,    40,
     214,    40,   313,   100,   287,    77,    40,     6,     7,   418,
     419,    40,   323,   424,   425,   265,   122,   123,   124,   118,
     119,   120,   121,   306,    40,   122,   123,   124,    40,    40,
     313,    40,    40,    40,   122,   123,   124,    36,    40,    40,
     323,    30,   123,   603,    90,    44,    45,     6,    47,   360,
      17,    39,   360,    89,    37,   122,   123,   124,    43,   360,
     127,   128,    25,   313,    91,    52,   386,    43,   379,    61,
      62,   379,   313,   323,     6,    41,    41,   360,   379,    53,
      66,    54,   323,   333,    41,    41,    41,    48,   399,    41,
      48,   399,    41,   386,    48,   388,   379,    48,   399,   313,
      41,    41,    48,   386,    41,   388,    41,    41,    41,   323,
     360,    41,    48,    24,    37,   400,   399,   400,   122,   360,
     112,   113,   114,   115,   116,   117,    43,    41,    41,   379,
      25,    49,    48,    48,    41,   385,   386,    41,   379,   338,
     339,   340,   341,   342,   343,    41,   360,   467,    41,   399,
     400,    48,    29,    28,    36,    49,   109,   499,   399,   109,
      41,    41,   606,    75,    40,   379,   610,    41,    41,    41,
     643,   102,    63,    41,   467,    37,    55,    46,   102,   472,
     109,    37,    49,    37,   467,   399,   199,   515,   360,   472,
     467,   502,   472,   175,   502,   287,   583,   524,   523,   686,
      38,   502,   199,    39,    56,   649,   543,    78,   246,   513,
      55,    56,    57,    58,    59,    60,   527,   467,   509,   502,
      65,    66,   505,   506,   379,   518,   505,   660,   672,   527,
     525,   700,   554,   557,   662,   518,   420,   408,   348,   406,
     348,   668,   525,    -1,   527,    -1,    -1,    -1,   541,    -1,
     694,    -1,   502,    -1,    -1,   505,   506,    -1,   541,    -1,
      -1,   502,    -1,    -1,    -1,   709,    -1,    -1,   518,    -1,
      -1,   554,    -1,   556,   557,   525,    -1,   527,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   527,   598,   502,    -1,
     583,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   609,    -1,
     583,   609,    -1,    -1,    -1,    -1,    -1,    -1,   609,    -1,
     621,    -1,    -1,   527,    -1,   598,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   609,    -1,    -1,   612,
      -1,   614,   643,   583,    -1,   643,    -1,    -1,   621,    -1,
      -1,    -1,   643,    -1,    -1,    -1,    -1,    -1,   598,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   598,   669,   609,
     643,   646,   647,   646,   647,    -1,    -1,    -1,   609,    -1,
      -1,   621,    -1,    -1,    -1,   686,    -1,   660,    -1,   662,
     621,    -1,    -1,    -1,   598,    -1,   669,    -1,    -1,    -1,
      -1,    -1,    -1,   643,    -1,   609,   646,   647,    -1,    -1,
      -1,    -1,   643,   686,    -1,   716,    -1,   621,    -1,    -1,
      -1,    -1,    -1,    -1,   224,   698,    -1,   700,    -1,   669,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   669,   643,
      -1,    -1,    -1,   716,    -1,    -1,   686,    -1,   248,   249,
     250,    -1,    -1,   253,    -1,   686,   256,   257,   258,    -1,
     700,   261,   262,   263,   264,   669,   266,   267,   268,   269,
     270,   271,    41,    42,    -1,   275,   716,    -1,    -1,    -1,
      -1,    -1,   686,    -1,    -1,   716,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    40,   716,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,   127,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   373,   374,    -1,   376,   377,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   431,   432,   433,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,   445,    -1,    -1,   448,    -1,
      -1,    -1,    -1,   453,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    62,    -1,    64,    65,   466,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    -1,    88,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
      -1,    -1,    -1,    -1,    19,    -1,    -1,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    40,    -1,   127,   128,    -1,
      -1,   531,    -1,   533,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    -1,    26,    27,    92,    93,    94,
      95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,    40,
      -1,    -1,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,   127,   128,    65,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    40,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    -1,
      -1,   122,   123,   124,    41,    -1,   127,   128,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,   130,    -1,    -1,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,   130,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    40,   130,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,
      64,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      40,    -1,    -1,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,    -1,   127,   128,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    -1,    88,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
      -1,    -1,    -1,    -1,    40,    -1,    -1,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,   127,   128,    65,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    -1,    88,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,    -1,    -1,    -1,    -1,    40,    -1,
      -1,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
      -1,   127,   128,    65,    42,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     122,   123,   124,    -1,    -1,   127,   128,    40,    -1,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    -1,    -1,   127,
     128,    -1,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,
     123,   124
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    14,   132,   133,   135,   136,   138,   200,   201,   122,
       0,     3,     4,     8,    10,    11,    13,    16,    20,    21,
      38,   103,   134,   142,   146,   155,   156,   160,   206,   207,
     210,   212,   213,   214,   215,   216,   218,   220,   222,   223,
     224,   137,     5,    36,    39,   229,     5,   229,   122,   123,
     124,   402,   403,    12,   211,   211,   211,    17,    18,   147,
     148,    36,   281,    19,   127,   128,   157,   158,   352,   353,
     402,   143,   402,   143,   202,   221,     3,     4,   220,   219,
     224,    15,   139,   229,    31,    32,    33,    34,    35,    51,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   125,   126,   130,   230,   231,
     239,   287,   343,   344,   346,   347,   348,   351,   353,   354,
     392,   396,   397,   398,   399,   400,   401,   402,   404,   229,
     229,     9,   208,   209,     6,    23,   104,   105,   227,   228,
     227,   228,    19,    40,    65,    67,    68,    69,    70,    71,
      72,    73,    74,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    88,    92,    93,    94,    95,    96,
      97,    98,    99,   151,   152,   153,   154,   273,   353,   378,
     380,   382,   383,   384,   387,   392,   396,   400,   402,   282,
     143,   352,   143,    22,    39,   161,   166,   167,   166,    49,
     204,   205,    39,   106,   225,   221,   140,   345,    37,   234,
      43,   240,   241,   289,    40,   288,    87,   129,   393,   394,
     395,   217,   227,   402,    40,    61,    62,    64,   353,   355,
     356,   359,   362,   363,   366,   367,   373,   375,   376,   377,
     378,   384,   390,   392,   396,   400,   402,    74,    40,    40,
      40,   130,   379,    40,   130,   279,    40,    40,    40,    36,
     242,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,   279,    40,    40,    40,   152,    40,    40,   130,
     274,   283,   284,   287,   166,   159,   166,    23,   162,   163,
     164,   165,   402,    30,   190,   196,   198,   242,    90,   168,
     169,   173,   135,   201,   203,   242,    23,   226,   402,    39,
     123,    50,   290,   301,   352,   233,   235,   236,   231,   290,
     295,   296,   343,   349,   350,   351,   290,   402,   166,   355,
     376,   376,   376,    89,   149,   150,   358,   361,    55,    56,
      57,    58,    59,    60,    65,    66,   364,   365,   372,   374,
     274,   391,   242,   355,   355,   355,   355,   355,   355,   355,
     243,   355,   355,   355,   355,   353,   355,   355,   355,   355,
     355,   355,    17,   276,   276,   355,   276,   276,    37,    43,
     285,   286,   168,   168,   165,   191,    25,   190,    91,   170,
     176,   402,   242,   141,    52,   297,   300,   350,    43,   232,
       6,    41,   350,    41,   353,    41,    53,   357,    54,   360,
     366,   366,   366,   366,   366,   366,    66,   279,    61,    62,
     368,   371,   398,   399,    19,    63,   369,    41,    41,    41,
     280,    48,    48,    48,   144,   146,   244,   245,   246,   249,
     302,   343,   351,    41,    41,    48,    41,    41,    48,    41,
      41,    41,    41,    48,    19,   355,   386,   355,    41,   355,
     355,   283,   190,   190,    36,   353,    40,   174,   175,   273,
     353,   378,   177,   178,   272,   273,   377,   378,    24,   171,
     179,   122,   294,   299,   231,   352,   359,   362,   279,   373,
     373,   369,   370,   375,   375,   278,   355,   355,   355,   145,
      37,   248,    43,   250,   251,   304,   303,   355,   355,   355,
      41,   385,    41,   275,   197,   355,   175,   178,    25,    28,
      29,   172,   185,   188,   189,    49,   293,    48,   298,   237,
      41,    48,   277,    48,    41,    41,   166,     6,     7,    44,
      45,    47,   247,   252,   253,   255,   259,   262,   265,   266,
     271,   246,   296,   313,    40,    50,    64,   100,   305,   307,
     314,   315,   316,   317,   320,   323,   325,   331,   332,   353,
     402,    41,    41,   277,   381,    49,   388,   389,   278,   195,
     150,    26,    27,   180,   181,   182,   183,   184,   272,   353,
     109,   109,   186,   189,   187,   188,   291,   292,   301,   300,
      36,   355,   355,   168,   256,   260,   254,   263,   272,   232,
     267,   316,    40,    50,   100,   333,   338,   339,   341,   402,
     323,   306,   319,   322,    19,    36,    61,   101,   324,   326,
     330,    41,    75,    41,    41,    37,    40,   130,   193,    41,
     181,   377,   297,   238,    41,   190,   257,   261,   242,   264,
     246,   242,    41,   336,   337,   339,    50,   340,   402,   297,
     102,   318,    63,   321,    48,   109,   329,   342,    55,   194,
     231,   352,   352,   242,   270,    41,   335,   312,   320,   325,
     342,    37,    48,   328,   401,    42,   192,   199,   353,   392,
     396,   400,   402,    37,   258,   242,    46,   268,   102,   334,
      49,   311,    37,    37,   327,   342,    41,   199,   242,   269,
     339,   307,   308,   310,    37,   242,   309,   297
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
     385
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  SPARQLfedParser::yyr1_[] =
  {
         0,   131,   132,   132,   133,   134,   134,   134,   134,   135,
     136,   136,   137,   137,   138,   140,   141,   139,   142,   143,
     143,   145,   144,   146,   147,   147,   148,   148,   149,   150,
     150,   151,   152,   152,   152,   152,   152,   152,   152,   152,
     153,   153,   154,   154,   155,   156,   157,   157,   158,   158,
     159,   159,   160,   161,   162,   162,   163,   164,   165,   166,
     167,   167,   168,   169,   169,   170,   170,   171,   171,   172,
     172,   173,   174,   174,   175,   175,   175,   175,   176,   177,
     177,   178,   179,   180,   180,   181,   181,   182,   182,   183,
     184,   184,   185,   185,   186,   186,   187,   187,   188,   189,
     190,   191,   191,   192,   192,   194,   193,   193,   195,   195,
     197,   196,   198,   198,   199,   199,   199,   199,   199,   199,
     200,   202,   201,   203,   203,   204,   205,   205,   206,   206,
     206,   206,   206,   206,   206,   206,   207,   208,   209,   209,
     210,   211,   211,   212,   213,   214,   215,   217,   216,   218,
     218,   219,   219,   220,   220,   221,   221,   222,   223,   224,
     225,   226,   226,   227,   228,   228,   228,   228,   229,   230,
     231,   231,   232,   232,   233,   234,   234,   236,   237,   238,
     235,   239,   240,   241,   241,   243,   242,   244,   244,   245,
     246,   246,   247,   248,   248,   249,   250,   251,   251,   252,
     252,   252,   252,   252,   252,   254,   253,   256,   257,   258,
     255,   260,   261,   259,   263,   264,   262,   266,   267,   265,
     269,   268,   270,   270,   271,   272,   272,   272,   273,   274,
     275,   274,   276,   276,   277,   278,   278,   279,   280,   279,
     282,   281,   283,   283,   284,   285,   286,   286,   288,   287,
     289,   287,   290,   291,   292,   292,   293,   294,   294,   295,
     296,   296,   297,   298,   299,   299,   300,   301,   301,   303,
     302,   304,   302,   306,   305,   307,   307,   309,   308,   310,
     310,   311,   312,   312,   313,   314,   315,   316,   317,   318,
     319,   319,   320,   321,   322,   322,   323,   324,   324,   325,
     325,   326,   327,   327,   328,   328,   329,   329,   330,   330,
     330,   330,   331,   332,   332,   332,   332,   333,   334,   335,
     335,   336,   337,   337,   338,   338,   339,   340,   340,   341,
     341,   341,   342,   343,   343,   345,   344,   346,   347,   347,
     347,   347,   347,   348,   348,   349,   349,   350,   350,   351,
     351,   352,   352,   353,   353,   354,   354,   354,   354,   354,
     354,   355,   356,   357,   358,   358,   359,   360,   361,   361,
     362,   363,   364,   364,   365,   365,   365,   365,   365,   365,
     365,   365,   366,   367,   368,   368,   369,   369,   370,   370,
     371,   371,   371,   372,   372,   373,   374,   374,   375,   375,
     375,   375,   376,   376,   376,   376,   376,   376,   376,   376,
     377,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   379,   379,   380,   381,   381,   382,   383,
     384,   384,   385,   384,   386,   386,   387,   387,   387,   387,
     387,   388,   389,   389,   390,   391,   391,   392,   393,   394,
     394,   395,   395,   396,   396,   396,   397,   397,   397,   398,
     398,   398,   399,   399,   399,   400,   400,   401,   401,   401,
     401,   402,   402,   403,   403,   404,   404
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SPARQLfedParser::yyr2_[] =
  {
         0,     2,     1,     1,     2,     1,     1,     1,     1,     2,
       0,     1,     0,     2,     2,     0,     0,     5,     5,     0,
       2,     0,     5,     3,     1,     1,     0,     1,     2,     0,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     6,     6,     1,     2,     1,     1,
       0,     1,     4,     2,     1,     1,     1,     2,     1,     2,
       0,     1,     4,     0,     1,     0,     1,     0,     1,     0,
       1,     3,     1,     2,     1,     1,     4,     1,     2,     1,
       2,     1,     3,     1,     2,     1,     1,     1,     1,     2,
       1,     1,     2,     2,     0,     1,     0,     1,     2,     2,
       1,     0,     2,     1,     2,     0,     4,     1,     0,     2,
       0,     6,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     0,     1,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     0,     1,
       3,     0,     1,     3,     3,     3,     3,     0,     5,     4,
       5,     0,     1,     2,     1,     0,     2,     2,     2,     2,
       2,     1,     2,     2,     1,     1,     1,     1,     3,     2,
       0,     1,     0,     1,     3,     0,     2,     0,     0,     0,
       8,     2,     2,     0,     1,     0,     4,     1,     1,     2,
       0,     1,     3,     0,     2,     2,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     0,     3,     0,     0,     0,
       6,     0,     0,     5,     0,     0,     4,     0,     0,     4,
       0,     3,     0,     2,     2,     1,     1,     1,     2,     1,
       0,     6,     0,     1,     2,     0,     2,     1,     0,     5,
       0,     4,     0,     1,     2,     2,     0,     1,     0,     3,
       0,     3,     3,     2,     0,     1,     2,     0,     2,     1,
       0,     1,     2,     2,     0,     2,     1,     1,     1,     0,
       3,     0,     3,     0,     4,     1,     1,     0,     3,     0,
       1,     2,     0,     2,     1,     1,     1,     1,     2,     2,
       0,     2,     2,     2,     0,     2,     2,     0,     1,     1,
       2,     1,     1,     2,     2,     1,     2,     3,     1,     1,
       1,     2,     1,     1,     1,     2,     3,     1,     2,     0,
       2,     2,     0,     1,     1,     3,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     0,     4,     4,     1,     1,
       1,     1,     1,     0,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     0,     2,     2,     2,     0,     2,
       1,     2,     0,     1,     2,     2,     2,     2,     2,     2,
       2,     3,     1,     2,     1,     1,     2,     2,     0,     1,
       2,     2,     2,     0,     2,     2,     0,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     4,     6,     4,     4,     4,     4,     2,     2,
       8,     6,     6,     6,     4,     4,     4,     4,     4,     2,
       1,     1,     1,     3,     1,     7,     0,     1,     2,     3,
       5,     5,     0,     7,     1,     1,     1,     1,     1,     1,
       1,     4,     0,     1,     2,     0,     1,     2,     2,     1,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
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
  "IT_USING", "IT_true", "IT_false", "INTEGER", "DECIMAL", "DOUBLE",
  "INTEGER_POSITIVE", "DECIMAL_POSITIVE", "DOUBLE_POSITIVE",
  "INTEGER_NEGATIVE", "DECIMAL_NEGATIVE", "DOUBLE_NEGATIVE",
  "STRING_LITERAL1", "STRING_LITERAL_LONG1", "STRING_LITERAL2",
  "STRING_LITERAL_LONG2", "IRI_REF", "PNAME_NS", "PNAME_LN",
  "BLANK_NODE_LABEL", "ANON", "VAR1", "VAR2", "LANGTAG", "NIL", "$accept",
  "Top", "QueryUnit", "Query", "Prologue", "_QBaseDecl_E_Opt",
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
  "Clear", "_QIT_SILENT_E_Opt", "Drop", "Create", "InsertData",
  "DeleteData", "DeleteWhere", "@7", "Modify", "_QInsertClause_E_Opt",
  "_O_QDeleteClause_E_S_QInsertClause_E_Opt_Or_QInsertClause_E_C",
  "_QUsingClause_E_Star", "_O_QIT_WITH_E_S_QIRIref_E_C", "DeleteClause",
  "InsertClause", "UsingClause",
  "_O_QIRIref_E_Or_QIT_NAMED_E_S_QIRIref_E_C", "GraphRef", "GraphRefAll",
  "QuadData", "Quads", "_QTriplesTemplate_E_Opt", "_QGT_DOT_E_Opt",
  "_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C_E_Star",
  "QuadsNotTriples", "@8", "@9", "$@10", "TriplesTemplate",
  "_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C_E_Opt", "GroupGraphPattern",
  "$@11", "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C",
  "GroupGraphPatternSub", "_QTriplesBlock_E_Opt",
  "_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "OptionalGraphPattern", "@12", "GraphGraphPattern", "@13", "@14", "@15",
  "ServiceGraphPattern", "@16", "@17", "MinusGraphPattern", "@18", "@19",
  "GroupOrUnionGraphPattern", "@20", "@21",
  "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@22",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "$@23", "_QIT_DISTINCT_E_Opt",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ExpressionList", "$@24",
  "ConstructTemplate", "$@25", "_QConstructTriples_E_Opt",
  "ConstructTriples", "_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C_E_Opt", "TriplesSameSubject",
  "$@26", "$@27", "PropertyListNotEmpty", "_O_QVerb_E_S_QObjectList_E_C",
  "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "Verb", "TriplesSameSubjectPath", "$@28", "$@29",
  "PropertyListNotEmptyPath", "$@30", "_O_QVerbPath_E_Or_QVerbSimple_E_C",
  "_O_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_C", "$@31",
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
  "Integer", "TriplesNode", "BlankNodePropertyList", "@32", "Generator",
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
  "ExistsFunc", "NotExistsFunc", "Aggregate", "$@33",
  "_O_QGT_TIMES_E_Or_QExpression_E_C",
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
       132,     0,    -1,   133,    -1,   200,    -1,   135,   134,    -1,
     142,    -1,   155,    -1,   156,    -1,   160,    -1,   136,   137,
      -1,    -1,   138,    -1,    -1,   137,   139,    -1,    14,   122,
      -1,    -1,    -1,    15,   140,   123,   141,   122,    -1,   146,
     143,   166,   168,   190,    -1,    -1,   143,   161,    -1,    -1,
     146,   145,   166,   168,   190,    -1,    16,   148,   154,    -1,
      17,    -1,    18,    -1,    -1,   147,    -1,    89,   353,    -1,
      -1,   149,    -1,    40,   355,   150,    41,    -1,   353,    -1,
     384,    -1,   378,    -1,   273,    -1,   392,    -1,   396,    -1,
     400,    -1,   151,    -1,   152,    -1,   153,   152,    -1,   153,
      -1,    19,    -1,    20,   281,   143,   166,   168,   190,    -1,
      21,   158,   143,   159,   168,   190,    -1,   352,    -1,   157,
     352,    -1,   157,    -1,    19,    -1,    -1,   166,    -1,    38,
     143,   166,   190,    -1,    22,   162,    -1,   163,    -1,   164,
      -1,   165,    -1,    23,   165,    -1,   402,    -1,   167,   242,
      -1,    -1,    39,    -1,   169,   170,   171,   172,    -1,    -1,
     173,    -1,    -1,   176,    -1,    -1,   179,    -1,    -1,   185,
      -1,    90,    25,   174,    -1,   175,    -1,   174,   175,    -1,
     378,    -1,   273,    -1,    40,   355,   150,    41,    -1,   353,
      -1,    91,   177,    -1,   178,    -1,   177,   178,    -1,   272,
      -1,    24,    25,   180,    -1,   181,    -1,   180,   181,    -1,
     183,    -1,   184,    -1,    26,    -1,    27,    -1,   182,   377,
      -1,   272,    -1,   353,    -1,   188,   186,    -1,   189,   187,
      -1,    -1,   189,    -1,    -1,   188,    -1,    28,   109,    -1,
      29,   109,    -1,   198,    -1,    -1,   191,   353,    -1,   199,
      -1,   192,   199,    -1,    -1,    40,   194,   192,    41,    -1,
     130,    -1,    -1,   195,   193,    -1,    -1,    30,   191,    36,
     197,   195,    37,    -1,    -1,   196,    -1,   402,    -1,   392,
      -1,   396,    -1,   400,    -1,    42,    -1,   353,    -1,   201,
      -1,    -1,   135,   206,   202,   205,    -1,    -1,   201,    -1,
      49,   203,    -1,    -1,   204,    -1,   207,    -1,   210,    -1,
     212,    -1,   213,    -1,   214,    -1,   215,    -1,   216,    -1,
     218,    -1,     8,   402,   209,    -1,     9,   227,    -1,    -1,
     208,    -1,    10,   211,   228,    -1,    -1,    12,    -1,    13,
     211,   228,    -1,    11,   211,   227,    -1,     4,     5,   229,
      -1,     3,     5,   229,    -1,    -1,     3,    39,   229,   217,
     166,    -1,   220,   221,    39,   242,    -1,   222,   220,   221,
      39,   242,    -1,    -1,   224,    -1,   223,   219,    -1,   224,
      -1,    -1,   221,   225,    -1,   103,   402,    -1,     3,   229,
      -1,     4,   229,    -1,   106,   226,    -1,   402,    -1,    23,
     402,    -1,     6,   402,    -1,   227,    -1,   104,    -1,    23,
      -1,   105,    -1,    36,   230,    37,    -1,   231,   234,    -1,
      -1,   239,    -1,    -1,    43,    -1,   235,   232,   231,    -1,
      -1,   234,   233,    -1,    -1,    -1,    -1,   236,     6,   352,
     237,    36,   238,   231,    37,    -1,   287,   241,    -1,    43,
     231,    -1,    -1,   240,    -1,    -1,    36,   243,   244,    37,
      -1,   144,    -1,   245,    -1,   246,   248,    -1,    -1,   249,
      -1,   252,   232,   246,    -1,    -1,   248,   247,    -1,   302,
     251,    -1,    43,   246,    -1,    -1,   250,    -1,   265,    -1,
     253,    -1,   262,    -1,   255,    -1,   259,    -1,   271,    -1,
      -1,    44,   254,   242,    -1,    -1,    -1,    -1,     6,   256,
     257,   352,   258,   242,    -1,    -1,    -1,     7,   260,   261,
     352,   242,    -1,    -1,    -1,    45,   263,   264,   242,    -1,
      -1,    -1,   266,   267,   242,   270,    -1,    -1,    46,   269,
     242,    -1,    -1,   270,   268,    -1,    47,   272,    -1,   377,
      -1,   378,    -1,   273,    -1,   402,   274,    -1,   130,    -1,
      -1,    40,   276,   355,   275,   278,    41,    -1,    -1,    17,
      -1,    48,   355,    -1,    -1,   278,   277,    -1,   130,    -1,
      -1,    40,   355,   280,   278,    41,    -1,    -1,    36,   282,
     283,    37,    -1,    -1,   284,    -1,   287,   286,    -1,    43,
     283,    -1,    -1,   285,    -1,    -1,   351,   288,   290,    -1,
      -1,   343,   289,   295,    -1,   301,   297,   294,    -1,   301,
     297,    -1,    -1,   291,    -1,    49,   292,    -1,    -1,   294,
     293,    -1,   296,    -1,    -1,   290,    -1,   300,   299,    -1,
      48,   300,    -1,    -1,   299,   298,    -1,   350,    -1,   352,
      -1,    50,    -1,    -1,   351,   303,   305,    -1,    -1,   343,
     304,   313,    -1,    -1,   307,   306,   297,   312,    -1,   314,
      -1,   315,    -1,    -1,   307,   309,   297,    -1,    -1,   308,
      -1,    49,   310,    -1,    -1,   312,   311,    -1,   296,    -1,
     316,    -1,   353,    -1,   317,    -1,   320,   319,    -1,   102,
     320,    -1,    -1,   319,   318,    -1,   325,   322,    -1,    63,
     325,    -1,    -1,   322,   321,    -1,   331,   324,    -1,    -1,
     326,    -1,   323,    -1,   100,   323,    -1,   330,    -1,    37,
      -1,   342,    37,    -1,    48,   327,    -1,    37,    -1,   342,
     328,    -1,    48,   342,    37,    -1,    19,    -1,   101,    -1,
      61,    -1,    36,   329,    -1,   332,    -1,   402,    -1,    50,
      -1,    64,   333,    -1,    40,   316,    41,    -1,   338,    -1,
     102,   339,    -1,    -1,   335,   334,    -1,   339,   335,    -1,
      -1,   336,    -1,   339,    -1,    40,   337,    41,    -1,   341,
      -1,   402,    -1,    50,    -1,   402,    -1,    50,    -1,   100,
     340,    -1,   109,    -1,   346,    -1,   344,    -1,    -1,    51,
     345,   290,    52,    -1,   348,    40,   349,    41,    -1,    31,
      -1,    32,    -1,    33,    -1,    34,    -1,    35,    -1,    -1,
     347,    -1,   350,    -1,   349,   350,    -1,   351,    -1,   343,
      -1,   353,    -1,   354,    -1,   353,    -1,   402,    -1,   127,
      -1,   128,    -1,   402,    -1,   392,    -1,   396,    -1,   400,
      -1,   404,    -1,   130,    -1,   356,    -1,   359,   358,    -1,
      53,   359,    -1,    -1,   358,   357,    -1,   362,   361,    -1,
      54,   362,    -1,    -1,   361,   360,    -1,   363,    -1,   366,
     364,    -1,    -1,   365,    -1,    55,   366,    -1,    56,   366,
      -1,    57,   366,    -1,    58,   366,    -1,    59,   366,    -1,
      60,   366,    -1,    66,   279,    -1,    65,    66,   279,    -1,
     367,    -1,   373,   372,    -1,   398,    -1,   399,    -1,    19,
     375,    -1,    63,   375,    -1,    -1,   369,    -1,    61,   373,
      -1,    62,   373,    -1,   368,   370,    -1,    -1,   372,   371,
      -1,   375,   374,    -1,    -1,   374,   369,    -1,    64,   376,
      -1,    61,   376,    -1,    62,   376,    -1,   376,    -1,   377,
      -1,   378,    -1,   390,    -1,   392,    -1,   396,    -1,   400,
      -1,   353,    -1,   384,    -1,    40,   355,    41,    -1,    76,
      40,   355,    41,    -1,    77,    40,   355,    41,    -1,    78,
      40,   355,    48,   355,    41,    -1,    79,    40,   355,    41,
      -1,    80,    40,   353,    41,    -1,    67,    40,   355,    41,
      -1,    68,    40,   355,    41,    -1,    69,   379,    -1,    70,
     279,    -1,    71,    40,   355,    48,   355,    48,   355,    41,
      -1,    72,    40,   355,    48,   355,    41,    -1,    73,    40,
     355,    48,   355,    41,    -1,    81,    40,   355,    48,   355,
      41,    -1,    82,    40,   355,    41,    -1,    83,    40,   355,
      41,    -1,    84,    40,   355,    41,    -1,    85,    40,   355,
      41,    -1,    99,    40,   355,    41,    -1,    88,   279,    -1,
     380,    -1,   382,    -1,   383,    -1,    40,   355,    41,    -1,
     130,    -1,    86,    40,   355,    48,   355,   381,    41,    -1,
      -1,   277,    -1,    74,   242,    -1,    65,    74,   242,    -1,
      92,    40,   276,   386,    41,    -1,   387,    40,   276,   355,
      41,    -1,    -1,    97,    40,   276,   355,   385,   389,    41,
      -1,    19,    -1,   355,    -1,    93,    -1,    94,    -1,    95,
      -1,    96,    -1,    98,    -1,    49,    75,    55,   401,    -1,
      -1,   388,    -1,   402,   391,    -1,    -1,   274,    -1,   401,
     395,    -1,    87,   402,    -1,   129,    -1,   393,    -1,    -1,
     394,    -1,   397,    -1,   398,    -1,   399,    -1,   109,    -1,
     110,    -1,   111,    -1,   112,    -1,   113,    -1,   114,    -1,
     115,    -1,   116,    -1,   117,    -1,   107,    -1,   108,    -1,
     118,    -1,   120,    -1,   119,    -1,   121,    -1,   122,    -1,
     403,    -1,   124,    -1,   123,    -1,   125,    -1,   126,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SPARQLfedParser::yyprhs_[] =
  {
         0,     0,     3,     5,     7,    10,    12,    14,    16,    18,
      21,    22,    24,    25,    28,    31,    32,    33,    39,    45,
      46,    49,    50,    56,    60,    62,    64,    65,    67,    70,
      71,    73,    78,    80,    82,    84,    86,    88,    90,    92,
      94,    96,    99,   101,   103,   110,   117,   119,   122,   124,
     126,   127,   129,   134,   137,   139,   141,   143,   146,   148,
     151,   152,   154,   159,   160,   162,   163,   165,   166,   168,
     169,   171,   175,   177,   180,   182,   184,   189,   191,   194,
     196,   199,   201,   205,   207,   210,   212,   214,   216,   218,
     221,   223,   225,   228,   231,   232,   234,   235,   237,   240,
     243,   245,   246,   249,   251,   254,   255,   260,   262,   263,
     266,   267,   274,   275,   277,   279,   281,   283,   285,   287,
     289,   291,   292,   297,   298,   300,   303,   304,   306,   308,
     310,   312,   314,   316,   318,   320,   322,   326,   329,   330,
     332,   336,   337,   339,   343,   347,   351,   355,   356,   362,
     367,   373,   374,   376,   379,   381,   382,   385,   388,   391,
     394,   397,   399,   402,   405,   407,   409,   411,   413,   417,
     420,   421,   423,   424,   426,   430,   431,   434,   435,   436,
     437,   446,   449,   452,   453,   455,   456,   461,   463,   465,
     468,   469,   471,   475,   476,   479,   482,   485,   486,   488,
     490,   492,   494,   496,   498,   500,   501,   505,   506,   507,
     508,   515,   516,   517,   523,   524,   525,   530,   531,   532,
     537,   538,   542,   543,   546,   549,   551,   553,   555,   558,
     560,   561,   568,   569,   571,   574,   575,   578,   580,   581,
     587,   588,   593,   594,   596,   599,   602,   603,   605,   606,
     610,   611,   615,   619,   622,   623,   625,   628,   629,   632,
     634,   635,   637,   640,   643,   644,   647,   649,   651,   653,
     654,   658,   659,   663,   664,   669,   671,   673,   674,   678,
     679,   681,   684,   685,   688,   690,   692,   694,   696,   699,
     702,   703,   706,   709,   712,   713,   716,   719,   720,   722,
     724,   727,   729,   731,   734,   737,   739,   742,   746,   748,
     750,   752,   755,   757,   759,   761,   764,   768,   770,   773,
     774,   777,   780,   781,   783,   785,   789,   791,   793,   795,
     797,   799,   802,   804,   806,   808,   809,   814,   819,   821,
     823,   825,   827,   829,   830,   832,   834,   837,   839,   841,
     843,   845,   847,   849,   851,   853,   855,   857,   859,   861,
     863,   865,   867,   870,   873,   874,   877,   880,   883,   884,
     887,   889,   892,   893,   895,   898,   901,   904,   907,   910,
     913,   916,   920,   922,   925,   927,   929,   932,   935,   936,
     938,   941,   944,   947,   948,   951,   954,   955,   958,   961,
     964,   967,   969,   971,   973,   975,   977,   979,   981,   983,
     985,   989,   994,   999,  1006,  1011,  1016,  1021,  1026,  1029,
    1032,  1041,  1048,  1055,  1062,  1067,  1072,  1077,  1082,  1087,
    1090,  1092,  1094,  1096,  1100,  1102,  1110,  1111,  1113,  1116,
    1120,  1126,  1132,  1133,  1141,  1143,  1145,  1147,  1149,  1151,
    1153,  1155,  1160,  1161,  1163,  1166,  1167,  1169,  1172,  1175,
    1177,  1179,  1180,  1182,  1184,  1186,  1188,  1190,  1192,  1194,
    1196,  1198,  1200,  1202,  1204,  1206,  1208,  1210,  1212,  1214,
    1216,  1218,  1220,  1222,  1224,  1226,  1228
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   393,   393,   396,   402,   409,   410,   411,   412,   417,
     421,   423,   427,   429,   433,   439,   441,   439,   451,   459,
     462,   470,   470,   481,   489,   492,   499,   502,   507,   514,
     517,   522,   529,   532,   535,   538,   541,   544,   547,   551,
     556,   559,   567,   570,   577,   586,   595,   598,   606,   609,
     616,   619,   624,   632,   639,   640,   644,   650,   656,   663,
     670,   672,   677,   684,   687,   692,   695,   700,   703,   708,
     712,   716,   723,   726,   733,   736,   739,   742,   748,   754,
     757,   764,   769,   776,   780,   788,   790,   798,   801,   809,
     817,   818,   825,   829,   837,   840,   845,   848,   852,   858,
     866,   871,   874,   881,   884,   890,   890,   896,   902,   905,
     912,   912,   921,   924,   928,   931,   934,   937,   940,   943,
     949,   953,   953,   962,   964,   968,   971,   973,   977,   978,
     979,   980,   981,   982,   983,   984,   988,   995,  1002,  1005,
    1009,  1015,  1018,  1024,  1030,  1036,  1058,  1066,  1066,  1076,
    1080,  1086,  1089,  1093,  1097,  1103,  1105,  1111,  1117,  1124,
    1131,  1137,  1140,  1197,  1203,  1206,  1209,  1212,  1218,  1222,
    1225,  1227,  1231,  1233,  1237,  1240,  1242,  1247,  1251,  1254,
    1247,  1265,  1269,  1272,  1274,  1279,  1279,  1291,  1292,  1297,
    1301,  1303,  1313,  1317,  1320,  1336,  1341,  1345,  1348,  1352,
    1353,  1354,  1355,  1356,  1357,  1361,  1361,  1376,  1379,  1381,
    1376,  1392,  1395,  1392,  1404,  1407,  1404,  1417,  1420,  1417,
    1430,  1430,  1444,  1446,  1450,  1461,  1462,  1463,  1467,  1475,
    1479,  1479,  1488,  1491,  1498,  1504,  1506,  1520,  1523,  1523,
    1533,  1533,  1541,  1543,  1548,  1553,  1557,  1559,  1563,  1563,
    1566,  1566,  1573,  1578,  1582,  1584,  1589,  1593,  1595,  1600,
    1604,  1606,  1611,  1616,  1620,  1622,  1626,  1633,  1637,  1645,
    1645,  1648,  1648,  1654,  1654,  1660,  1661,  1665,  1665,  1670,
    1672,  1676,  1679,  1681,  1685,  1689,  1693,  1699,  1703,  1707,
    1710,  1712,  1716,  1720,  1725,  1727,  1733,  1736,  1738,  1744,
    1745,  1751,  1755,  1756,  1760,  1761,  1765,  1766,  1770,  1771,
    1772,  1773,  1777,  1781,  1784,  1787,  1790,  1796,  1800,  1803,
    1805,  1809,  1812,  1814,  1818,  1819,  1823,  1827,  1828,  1832,
    1833,  1834,  1838,  1843,  1844,  1848,  1848,  1861,  1886,  1889,
    1892,  1895,  1898,  1905,  1908,  1913,  1917,  1924,  1925,  1929,
    1932,  1936,  1939,  1945,  1946,  1950,  1953,  1956,  1959,  1962,
    1963,  1969,  1974,  1983,  1990,  1993,  2001,  2010,  2017,  2020,
    2027,  2032,  2043,  2046,  2050,  2053,  2056,  2059,  2062,  2065,
    2068,  2071,  2077,  2082,  2091,  2094,  2101,  2104,  2111,  2114,
    2119,  2122,  2126,  2140,  2143,  2151,  2160,  2163,  2170,  2173,
    2176,  2179,  2183,  2184,  2185,  2186,  2189,  2192,  2195,  2198,
    2202,  2208,  2211,  2214,  2217,  2220,  2223,  2226,  2230,  2233,
    2237,  2240,  2243,  2246,  2249,  2252,  2255,  2258,  2261,  2264,
    2267,  2268,  2269,  2275,  2278,  2285,  2292,  2295,  2299,  2306,
    2313,  2316,  2320,  2320,  2332,  2336,  2340,  2343,  2346,  2349,
    2352,  2358,  2364,  2367,  2371,  2381,  2384,  2389,  2397,  2404,
    2408,  2416,  2420,  2424,  2425,  2426,  2430,  2431,  2432,  2436,
    2437,  2438,  2442,  2443,  2444,  2448,  2449,  2453,  2454,  2455,
    2456,  2460,  2461,  2465,  2466,  2470,  2471
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
     125,   126,   127,   128,   129,   130
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SPARQLfedParser::yyeof_ = 0;
  const int SPARQLfedParser::yylast_ = 1611;
  const int SPARQLfedParser::yynnts_ = 274;
  const int SPARQLfedParser::yyempty_ = -2;
  const int SPARQLfedParser::yyfinal_ = 10;
  const int SPARQLfedParser::yyterror_ = 1;
  const int SPARQLfedParser::yyerrcode_ = 256;
  const int SPARQLfedParser::yyntokens_ = 131;

  const unsigned int SPARQLfedParser::yyuser_token_number_max_ = 385;
  const SPARQLfedParser::token_number_type SPARQLfedParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 4584 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 2477 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


