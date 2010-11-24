
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
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(5) - (3)].p_TableOperation), (yysemantic_stack_[(5) - (5)].p_WhereClause));
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

  case 432:

/* Line 678 of lalr1.cc  */
#line 2272 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 2275 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 2282 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_regex, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 2289 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 2296 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 2303 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 2310 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 2313 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 2317 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 2319 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  // x = new ArgList($2, driver.curExprList);
	  delete driver.curExprList;
	  driver.curExprList = NULL;
	  w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // $$ = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group-concat, $3, $4.p_Expression, $4.separator));
    }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 2329 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
	driver.countStar = true;
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 2337 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 2340 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 2343 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 2346 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 2349 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 2355 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 2361 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 2368 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 2378 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 2386 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 2394 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 2401 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 2405 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 2413 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 3086 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -625;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        31,   -63,    70,  -625,    58,  -625,  -625,  -625,  -625,  -625,
    -625,   180,    47,   156,    52,    52,    52,    37,    68,    14,
    -625,   156,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,    91,    73,
    -625,   130,    78,   965,    78,  -625,    78,  -625,  -625,  -625,
    -625,    79,  -625,  -625,    19,   160,    19,  -625,  -625,  -625,
     941,  -625,  -625,  -625,  -625,  -625,   114,  -625,  -625,  -625,
    -625,    26,  -625,    26,   121,     7,    78,    78,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,   145,  -625,
    -625,   148,  -625,  -625,  -625,  -625,   157,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,   -52,  -625,  -625,  -625,
    -625,   160,  -625,  -625,   156,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  1176,   133,   172,   191,   -16,    -9,   242,
     246,   254,   152,   262,   266,   270,   275,   276,   285,   286,
     288,   289,   292,   295,   297,  -625,  -625,  -625,  -625,   298,
    -625,   302,  -625,  -625,  1239,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,   303,  -625,  -625,  -625,    10,   965,    26,
    -625,   151,     9,  -625,  -625,   209,   152,   218,    43,  -625,
    -625,   152,    21,  -625,    51,   222,    32,  -625,   341,   965,
    -625,  -625,    32,  1088,    32,   156,  -625,  -625,  -625,  -625,
     309,  -625,  -625,  1176,  1302,  1302,  1302,  -625,   261,  -625,
    -625,  -625,  -625,   449,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,    10,   152,  1176,  1176,  1176,
    -625,  -625,  1176,  -625,  -625,  1176,  1176,  1176,  -625,  -625,
    1176,  1176,  1176,  1176,    88,  1176,  1176,  1176,  1176,  1176,
    1176,   338,   338,  1176,  -625,   338,   338,  -625,  -625,   323,
    -625,   326,   218,   218,  -625,   156,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,   340,   209,   280,  -625,
     173,  -625,  -625,  -625,   156,  -625,  -625,   152,  -625,  -625,
     324,  1088,  -625,  -625,   331,   369,  -625,  -625,  -625,  -625,
    -625,  1064,  -625,  -625,  -625,  -625,  -625,   339,  -625,  -625,
    -625,    88,  -625,   345,   328,   325,  1176,  1176,  1176,  1176,
    1176,  1176,   316,    -9,  -625,  -625,   366,    22,  -625,  -625,
    -625,   347,   348,   352,  -625,   346,   350,   351,   729,   354,
     355,   353,   359,   361,   357,   372,   375,   378,   379,   374,
    -625,   857,  1176,   382,  1176,  1176,  -625,   965,  -625,  -625,
     209,   209,  -625,   -18,  1365,  -625,  1453,   400,  -625,  -625,
    -625,   308,  -625,  -625,  -625,  -625,  -625,   965,   114,  -625,
    -625,  -625,  -625,  -625,  1176,  -625,  1176,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,    -9,  -625,  1176,  1176,    22,  -625,
    -625,  -625,  1176,  1176,  -625,  -625,  -625,  -625,  -625,  1176,
    1176,  1176,  -625,  -625,   393,  -625,  -625,  -625,   389,  -625,
    -625,  -625,  -625,  1176,  -625,  -625,  1176,  -625,  -625,  -625,
    -625,  1176,  -625,  -625,   395,  -625,  -625,   396,  -625,  -625,
    -625,  -625,  -625,  -625,  1176,  1365,  -625,  -625,  -625,  -625,
    1453,  -625,  -625,  -625,  -625,  -625,   409,   199,  -625,  -625,
     391,   390,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,    62,   398,   407,   408,   309,  -625,   267,
     965,  -625,  -625,    32,   231,   410,   413,   402,  -625,   392,
    -625,  -625,  -625,   261,  -625,  -625,   178,   356,   358,  -625,
    -625,   426,   428,    32,  -625,  1088,  -625,   422,  -625,  1176,
    -625,  1176,  -625,  -625,   218,  -625,  -625,  -625,  -625,  1453,
    -625,   331,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,   269,  -625,   322,    41,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,    65,  -625,  -625,  -625,  -625,
    -625,  -625,   419,   386,  -625,   424,   126,   -11,   427,  -625,
    -625,   178,  -625,   423,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,  1088,  -625,  -625,  -625,
     429,   209,  -625,  -625,   152,  -625,  -625,   965,   152,   430,
      99,  -625,   102,  -625,  -625,  -625,  -625,  -625,  -625,  1088,
     371,   404,  -625,   -21,  -625,  -625,  -625,  -625,  -625,  -625,
     418,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,   965,  -625,  -625,   114,   114,  -625,   152,  -625,  -625,
    -625,  -625,   434,  -625,  -625,  -625,  -625,  -625,   269,  -625,
     269,  -625,   368,  -625,  -625,    12,   204,  1389,   446,  -625,
     152,  -625,   440,  -625,   387,   443,  -625,  -625,   452,  -625,
      -1,  -625,  -625,  -625,   689,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,   152,  -625,  -625,  -625,    99,  -625,   231,  -625,
    -625,  -625,  -625,   457,  -625,  -625,  -625,   152,  -625,  -625,
    -625,  -625,  -625,  -625,  1088,  -625
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
     154,     9,     0,   170,     0,   158,     0,   159,   480,   483,
     482,   138,   481,   142,     0,     0,     0,    24,    25,    27,
       0,   240,    19,    49,   353,   354,    48,    19,    46,   351,
     352,    60,   157,    60,   126,     0,     0,     0,   155,   153,
     152,    15,    13,   146,   338,   339,   340,   341,   342,   335,
     474,   475,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   476,   478,   477,   479,   484,   485,   360,     0,   175,
     171,   183,   250,   334,   333,   344,     0,   248,   349,   350,
     356,   357,   462,   463,   464,   358,   460,   355,   359,   147,
     145,     0,   139,   136,     0,   166,   165,   167,   164,   140,
     144,   143,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   445,   446,   447,   448,     0,
     449,     0,    39,    40,    42,    23,    35,    32,    34,   429,
     430,   431,    33,     0,    36,    37,    38,     0,   242,    60,
      47,    50,     0,    61,    20,   112,     0,    63,    10,   127,
     122,     0,     0,   156,     0,     0,     0,   168,   169,   170,
     184,   181,   260,   343,     0,     0,   458,   459,   461,   456,
      60,   137,   163,     0,     0,     0,     0,   408,    29,   361,
     364,   368,   370,   372,   382,   393,   396,   401,   402,   403,
     409,   404,   405,   406,   407,   454,     0,     0,     0,     0,
     433,   418,     0,   237,   419,     0,     0,     0,   185,   437,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   232,   232,     0,    41,   232,   232,   229,   228,     0,
     243,   246,    63,    63,    51,     0,    53,    54,    55,    56,
      58,   101,    52,   113,   100,    59,     0,   112,    65,    64,
       0,   124,   125,   149,     0,   160,   161,     0,    16,   268,
       0,   343,   267,   176,   172,     0,   182,   261,   251,   259,
     348,   343,   345,   347,   249,   457,   148,     0,   399,   400,
     398,     0,    30,     0,   362,   366,     0,     0,     0,     0,
       0,     0,     0,     0,   371,   373,   383,   395,   455,   453,
     438,     0,     0,     0,   238,     0,     0,     0,   190,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     233,     0,     0,     0,     0,     0,   241,   242,   247,   244,
     112,   112,    57,     0,     0,    18,     0,    67,    66,   162,
     150,     0,   336,   257,   264,   266,   173,   170,     0,   337,
     346,   410,    28,    31,     0,   365,     0,   369,   374,   375,
     376,   377,   378,   379,     0,   380,     0,     0,   388,   394,
     384,   385,     0,     0,   397,   416,   417,   432,   235,     0,
       0,     0,   187,    21,     0,   188,   193,   191,   197,   271,
     269,   411,   412,     0,   414,   415,     0,   424,   425,   426,
     427,     0,   443,   444,     0,   441,   428,     0,   230,   245,
      44,    45,   110,   102,     0,    71,    72,    75,    77,    74,
      78,    79,    81,   227,   225,   226,     0,    69,    68,    17,
     252,   262,   174,   178,   363,   367,   381,   390,   391,   389,
     392,   386,   387,     0,     0,     0,     0,    60,   186,   189,
     190,   198,   195,   260,     0,     0,     0,   435,   439,   451,
     440,   235,   108,    29,    73,    80,     0,     0,     0,    62,
      70,    94,    96,   254,   258,   343,   265,     0,   239,     0,
     236,     0,   421,   422,    63,   207,   211,   205,   214,     0,
     194,   172,   200,   202,   203,   201,   199,   218,   204,   196,
     284,   272,     0,   314,     0,     0,   270,   273,   275,   276,
     285,   287,   290,   299,   294,   297,   312,   286,   313,   413,
     423,   436,     0,     0,   452,     0,     0,     0,     0,    87,
      88,    82,    83,     0,    85,    86,    90,    91,    98,    99,
      92,    95,    93,    97,   255,   256,   343,   263,   179,   234,
       0,   112,   208,   212,     0,   215,   224,   190,     0,     0,
     322,   330,     0,   315,   317,   324,   326,   329,   300,   343,
     288,   292,   308,     0,   310,   309,   296,   298,   301,   434,
       0,   442,   231,   111,   105,   107,   109,    76,    84,    89,
     253,   170,   420,    22,     0,     0,   206,     0,   192,   222,
     316,   323,     0,   319,   328,   331,   327,   282,     0,   291,
       0,   295,     0,   332,   311,     0,     0,     0,     0,   209,
       0,   216,   219,   325,   321,   274,   289,   293,     0,   305,
       0,   306,   450,   118,     0,   103,   119,   115,   116,   117,
     114,   180,     0,   213,   220,   223,     0,   320,   279,   283,
     307,   302,   304,     0,   106,   104,   210,     0,   318,   277,
     280,   281,   303,   221,   343,   278
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -625,  -625,  -625,  -625,   300,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,    35,  -625,  -625,   137,  -625,  -625,  -625,   -17,
    -625,   327,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,   214,   -72,  -625,  -268,  -625,  -625,
    -625,  -625,  -625,  -625,    46,  -625,  -625,    30,  -625,  -625,
     -79,  -625,  -625,  -625,  -625,  -625,  -625,    -5,    -8,  -288,
    -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -166,  -625,
     329,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
     252,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,   483,
     444,  -625,  -625,   486,  -625,  -625,   -33,   472,   241,  -625,
    -202,   -10,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -173,  -625,  -625,  -625,  -479,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,  -401,   -50,   287,  -625,   -66,    23,    24,  -303,  -625,
    -625,  -625,   161,  -625,  -625,  -625,  -185,  -625,  -625,  -139,
    -625,  -625,  -625,  -625,  -625,    34,  -585,  -625,  -625,     8,
      17,  -625,  -625,  -625,  -625,  -625,  -154,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,    -6,  -625,  -625,  -625,  -111,
    -625,  -625,    -7,  -625,  -110,  -625,  -625,  -625,  -625,  -625,
    -625,  -625,  -625,  -625,  -625,  -625,  -625,  -625,  -590,  -625,
    -625,  -624,   -38,  -625,  -625,  -625,  -625,  -625,  -625,  -196,
     -31,   -15,    20,  -625,   459,  -625,  -625,  -625,   147,  -625,
    -625,   143,  -625,  -625,  -625,    71,  -625,  -625,   134,  -625,
    -625,  -625,  -124,  -625,  -126,    64,  -370,   -23,  -625,  -625,
    -625,  -625,  -625,   -47,  -625,  -625,  -625,  -625,  -625,  -625,
    -625,   -41,  -625,  -625,  -625,    29,  -625,   207,   211,    56,
    -107,   -13,  -625,  -625
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,     3,    22,     4,     5,    41,     6,    82,   205,
     391,    23,    71,   432,   497,    24,    59,    60,   332,   333,
     172,   173,   174,   175,    25,    26,    66,    67,   283,    27,
     194,   286,   287,   288,   289,   195,   196,   297,   298,   387,
     477,   519,   299,   465,   466,   388,   470,   471,   478,   581,
     582,   583,   584,   585,   520,   590,   592,   521,   522,   292,
     383,   684,   636,   667,   577,   293,   512,   294,   685,     7,
       8,    74,   302,   199,   200,    28,    29,   132,   133,    30,
      54,    31,    32,    33,    34,    35,   220,    36,    79,    37,
      75,    38,    39,    40,   203,   305,   138,   139,    45,   108,
     109,   397,   313,   208,   314,   315,   527,   641,   110,   210,
     211,   259,   358,   434,   435,   436,   540,   499,   437,   501,
     502,   541,   542,   604,   543,   602,   644,   692,   544,   603,
     645,   545,   605,   647,   546,   547,   608,   695,   707,   672,
     548,   472,   473,   278,   511,   371,   530,   493,   254,   428,
      62,   188,   279,   280,   378,   379,   111,   214,   212,   317,
     594,   595,   524,   480,   318,   319,   393,   526,   481,   394,
     311,   438,   504,   503,   556,   619,   557,   710,   714,   711,
     699,   675,   551,   558,   559,   560,   561,   659,   620,   562,
     661,   621,   563,   626,   564,   627,   702,   681,   664,   628,
     565,   566,   613,   697,   674,   651,   652,   614,   615,   655,
     616,   665,   320,   113,   206,   114,   115,   116,   321,   395,
     323,   312,   227,   119,   228,   229,   405,   334,   230,   407,
     335,   231,   232,   344,   345,   233,   234,   418,   424,   490,
     419,   346,   235,   347,   236,   237,   238,   239,   251,   179,
     572,   180,   181,   240,   509,   454,   183,   574,   575,   241,
     349,   242,   217,   218,   219,   243,   122,   123,   124,   244,
     126,   245,    52,   128
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SPARQLfedParser::yytable_ninf_ = -344;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        51,   197,   120,   281,    68,   112,    70,   316,    72,   385,
     176,   640,   117,   182,   380,   381,   474,   322,   462,   184,
     653,   549,   140,   295,   249,   134,   633,   662,   303,   634,
     127,   252,   285,    63,   657,   215,   701,   178,   678,    69,
     415,   422,   135,  -123,   304,     1,   201,   187,   192,   679,
     276,   190,    46,    70,    57,    58,   703,     1,     9,    73,
     680,    11,    12,   118,    53,   193,    13,   310,    14,    15,
      10,    16,   121,   350,    17,   324,   216,    77,    18,    19,
     177,   552,   309,    43,   622,   423,    69,   663,   131,   185,
     307,   553,   460,   461,    76,    77,    20,   189,   221,   125,
     474,   623,   191,   528,    61,   554,   708,   663,    64,    65,
     529,   486,   202,   250,    43,   586,   186,   282,   635,   284,
     253,   222,   136,   137,   176,   400,   624,   182,   648,   715,
      48,    49,    50,   184,   390,    48,    49,    50,   606,   277,
      64,    65,    48,    49,    50,    81,   474,   120,   326,   611,
     112,   178,   654,    48,    49,    50,   202,   117,    64,    65,
      21,   187,    48,    49,    50,   625,   134,   632,   120,   474,
     198,   112,   120,   192,   529,   127,    11,    12,   117,   290,
     586,    13,   207,    14,    15,    42,    16,   -60,   258,   306,
     193,   209,   281,    70,   177,   482,   127,   213,   612,    70,
     127,    70,   325,   185,   579,   580,   372,   246,   118,   374,
     375,   474,   247,   639,    64,    65,    43,   121,   223,    44,
      48,    49,    50,    48,    49,    50,    69,   517,   518,   118,
     186,   248,    69,   118,    69,    48,    49,    50,   121,   291,
      64,    65,   121,   144,   125,   145,   146,   147,   148,   149,
     150,   151,   152,    47,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   125,   601,    55,    56,   125,
     120,   552,   290,   535,   536,    21,   171,    48,    49,    50,
     120,   553,   255,    83,   363,   129,   256,   130,   328,   329,
     330,   389,   487,   488,   257,   554,   491,   492,   127,    48,
      49,    50,   260,  -217,    64,    65,   261,   296,   127,   552,
     262,   537,   538,   643,   539,   263,   264,   120,    47,   553,
     439,   101,   102,   103,   104,   265,   266,   440,   267,   268,
     555,   118,   269,   554,   467,   270,   120,   271,   272,   112,
     121,   118,   273,   275,   308,   127,   117,  -177,   193,   331,
     121,   402,    48,    49,    50,   370,   120,    64,    65,   112,
     376,   469,   610,   475,   127,   384,   117,   125,   555,   377,
     386,   187,   611,   187,   396,   398,   392,   125,   118,   406,
     401,   404,   414,   483,   127,    70,   403,   121,   425,   426,
      48,    49,    50,   427,   429,   441,   442,   118,   430,   431,
     444,   443,   445,   463,   468,   446,   121,   408,   409,   410,
     411,   412,   413,   447,   125,   467,   448,   118,    69,   449,
     450,   612,   451,   456,   476,   534,   121,   416,   417,   479,
     498,   646,   500,   125,   516,   649,   508,   510,   525,   668,
     523,   573,   469,    48,    49,    50,   531,   475,   532,   533,
     529,   569,   187,   125,   570,   518,   517,   187,   598,   120,
     629,   630,   439,   223,   588,   631,   589,   660,   637,   440,
     642,   650,   658,   666,   671,   673,   663,    95,    96,    97,
      98,    99,   100,   691,   120,   468,   694,   127,   696,   700,
      70,   568,   698,   475,   712,   433,   578,   693,   300,   382,
     515,   274,   638,   187,   336,   337,   338,   339,   340,   341,
      70,   514,   127,   591,   342,   343,   475,   593,   705,   706,
     118,    78,   204,    69,   567,    80,   187,   301,   141,   121,
     571,   607,   348,   597,   713,   576,   587,   550,   459,   568,
     596,   617,   568,    69,   709,   118,   609,   676,   618,   485,
     677,   484,   489,   420,   121,   120,   125,   421,   475,   682,
       0,     0,     0,     0,     0,     0,   120,     0,   187,   439,
       0,     0,     0,     0,     0,     0,   440,     0,   120,     0,
       0,   125,     0,   127,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   127,     0,     0,   617,     0,   656,
     120,   587,     0,   112,     0,     0,   127,     0,     0,     0,
     117,     0,     0,     0,     0,     0,   118,     0,     0,     0,
       0,     0,     0,     0,     0,   121,   687,   118,   127,   669,
     670,    70,    70,     0,     0,     0,   121,     0,     0,   118,
       0,     0,     0,   687,     0,   568,     0,   568,   121,     0,
       0,     0,   125,     0,   690,     0,     0,     0,     0,     0,
       0,   118,     0,   125,    69,    69,     0,     0,     0,     0,
     121,   690,     0,   120,     0,   125,     0,     0,     0,     0,
       0,     0,   327,   617,     0,   568,     0,   686,     0,     0,
       0,     0,     0,     0,     0,     0,   688,   125,     0,     0,
       0,   127,     0,     0,   686,     0,   351,   352,   353,     0,
       0,   354,     0,   688,   355,   356,   357,     0,   567,   359,
     360,   361,   362,   689,   364,   365,   366,   367,   368,   369,
     704,   683,   373,     0,   118,     0,     0,     0,     0,     0,
     689,     0,     0,   121,     0,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,    85,    86,    87,    88,     0,     0,     0,     0,  -343,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      48,    49,    50,     0,     0,    64,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     453,   455,     0,   457,   458,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      48,    49,    50,   105,   106,    64,    65,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   452,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   494,   495,
     496,     0,     0,     0,     0,     0,     0,   223,     0,     0,
       0,     0,   505,     0,     0,   506,     0,     0,     0,     0,
     507,     0,     0,     0,     0,     0,     0,     0,   224,   225,
       0,   226,   144,   513,   145,   146,   147,   148,   149,   150,
     151,   152,     0,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,     0,     0,     0,     0,   164,   165,
     166,   167,   168,   169,   170,   171,     0,     0,     0,     0,
     142,     0,     0,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    48,    49,
      50,   143,     0,    64,    65,     0,     0,     0,   599,     0,
     600,     0,     0,     0,     0,     0,    84,    85,    86,    87,
      88,     0,     0,     0,     0,  -343,   144,     0,   145,   146,
     147,   148,   149,   150,   151,   152,    89,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,     0,     0,
       0,     0,   164,   165,   166,   167,   168,   169,   170,   171,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    48,    49,    50,     0,     0,    64,    65,     0,
       0,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    48,    49,    50,   105,
     106,    64,    65,     0,   107,    84,    85,    86,    87,    88,
       0,     0,     0,     0,     0,   399,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    89,     0,     0,     0,    84,
      85,    86,    87,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,    48,    49,    50,   105,   106,
      64,    65,     0,   107,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    48,
      49,    50,   105,   106,    64,    65,   223,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   224,   225,     0,
     226,   144,     0,   145,   146,   147,   148,   149,   150,   151,
     152,     0,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,     0,     0,     0,     0,   164,   165,   166,
     167,   168,   169,   170,   171,     0,     0,     0,     0,   143,
       0,     0,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    48,    49,    50,
       0,     0,    64,    65,   144,     0,   145,   146,   147,   148,
     149,   150,   151,   152,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,     0,     0,     0,     0,
     164,   165,   166,   167,   168,   169,   170,   171,     0,     0,
       0,     0,   223,     0,     0,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      48,    49,    50,     0,     0,    64,    65,   144,     0,   145,
     146,   147,   148,   149,   150,   151,   152,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,     0,
       0,     0,     0,   164,   165,   166,   167,   168,   169,   170,
     171,     0,     0,     0,     0,   464,     0,     0,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    48,    49,    50,     0,     0,    64,    65,
     144,   683,   145,   146,   147,   148,   149,   150,   151,   152,
       0,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   171,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,    49,    50,     0,
       0,    64,    65,   223,     0,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      48,    49,    50,     0,     0,    64,    65,     0,   144,     0,
     145,   146,   147,   148,   149,   150,   151,   152,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   171,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,    49,    50
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        13,    73,    43,   188,    19,    43,    19,   209,    21,   297,
      60,   596,    43,    60,   282,   283,   386,   213,    36,    60,
     610,   500,    55,   196,    40,     6,    37,    48,   201,    40,
      43,    40,    23,    19,   619,    87,    37,    60,   662,    19,
     343,    19,    23,     0,    23,    14,    39,    60,    22,    37,
      40,    66,     5,    66,    17,    18,   680,    14,   121,    24,
      48,     3,     4,    43,    12,    39,     8,   206,    10,    11,
       0,    13,    43,   246,    16,   214,   128,     4,    20,    21,
      60,    40,    50,    36,    19,    63,    66,   108,     9,    60,
      39,    50,   380,   381,     3,     4,    38,    62,   131,    43,
     470,    36,    67,    41,    36,    64,   696,   108,   126,   127,
      48,   414,   105,   129,    36,   516,    60,   189,   129,   191,
     129,   134,   103,   104,   174,   321,    61,   174,   607,   714,
     121,   122,   123,   174,   307,   121,   122,   123,   539,   129,
     126,   127,   121,   122,   123,    15,   516,   188,   220,    50,
     188,   174,    50,   121,   122,   123,   105,   188,   126,   127,
     102,   174,   121,   122,   123,   100,     6,    41,   209,   539,
      49,   209,   213,    22,    48,   188,     3,     4,   209,   192,
     581,     8,    37,    10,    11,     5,    13,    36,    36,   202,
      39,    43,   377,   206,   174,   397,   209,    40,    99,   212,
     213,   214,   215,   174,    26,    27,   272,    74,   188,   275,
     276,   581,    40,   583,   126,   127,    36,   188,    40,    39,
     121,   122,   123,   121,   122,   123,   206,    28,    29,   209,
     174,    40,   212,   213,   214,   121,   122,   123,   209,    30,
     126,   127,   213,    65,   188,    67,    68,    69,    70,    71,
      72,    73,    74,    12,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,   209,   534,    15,    16,   213,
     311,    40,   285,     6,     7,   102,    98,   121,   122,   123,
     321,    50,    40,    42,   264,    44,    40,    46,   224,   225,
     226,   304,   416,   417,    40,    64,   422,   423,   311,   121,
     122,   123,    40,    36,   126,   127,    40,    89,   321,    40,
      40,    44,    45,   601,    47,    40,    40,   358,    77,    50,
     358,   117,   118,   119,   120,    40,    40,   358,    40,    40,
      99,   311,    40,    64,   384,    40,   377,    40,    40,   377,
     311,   321,    40,    40,   122,   358,   377,     6,    39,    88,
     321,   331,   121,   122,   123,    17,   397,   126,   127,   397,
      37,   384,    40,   386,   377,    25,   397,   311,    99,    43,
      90,   384,    50,   386,    43,     6,    52,   321,   358,    54,
      41,    53,    66,   398,   397,   398,    41,   358,    41,    41,
     121,   122,   123,    41,    48,    41,    41,   377,    48,    48,
      41,    48,    41,   383,   384,    48,   377,   336,   337,   338,
     339,   340,   341,    41,   358,   465,    41,   397,   398,    41,
      41,    99,    48,    41,    24,   497,   397,    61,    62,   121,
      37,   604,    43,   377,    25,   608,    41,    41,    48,   641,
      49,    49,   465,   121,   122,   123,    48,   470,    41,    41,
      48,    41,   465,   397,    41,    29,    28,   470,    36,   500,
      41,    75,   500,    40,   108,    41,   108,    63,    41,   500,
      41,    41,   101,    55,   647,    41,   108,   111,   112,   113,
     114,   115,   116,    37,   525,   465,    46,   500,   101,    37,
     503,   504,    49,   516,    37,   358,   513,   670,   198,   285,
     470,   174,   581,   516,    55,    56,    57,    58,    59,    60,
     523,   465,   525,   521,    65,    66,   539,   522,   684,   692,
     500,    38,    78,   503,   504,    39,   539,   198,    56,   500,
     507,   541,   245,   525,   707,   511,   516,   503,   377,   552,
     523,   554,   555,   523,   698,   525,   552,   658,   555,   406,
     660,   404,   418,   346,   525,   596,   500,   346,   581,   666,
      -1,    -1,    -1,    -1,    -1,    -1,   607,    -1,   581,   607,
      -1,    -1,    -1,    -1,    -1,    -1,   607,    -1,   619,    -1,
      -1,   525,    -1,   596,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   607,    -1,    -1,   610,    -1,   612,
     641,   581,    -1,   641,    -1,    -1,   619,    -1,    -1,    -1,
     641,    -1,    -1,    -1,    -1,    -1,   596,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   596,   667,   607,   641,   644,
     645,   644,   645,    -1,    -1,    -1,   607,    -1,    -1,   619,
      -1,    -1,    -1,   684,    -1,   658,    -1,   660,   619,    -1,
      -1,    -1,   596,    -1,   667,    -1,    -1,    -1,    -1,    -1,
      -1,   641,    -1,   607,   644,   645,    -1,    -1,    -1,    -1,
     641,   684,    -1,   714,    -1,   619,    -1,    -1,    -1,    -1,
      -1,    -1,   223,   696,    -1,   698,    -1,   667,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   667,   641,    -1,    -1,
      -1,   714,    -1,    -1,   684,    -1,   247,   248,   249,    -1,
      -1,   252,    -1,   684,   255,   256,   257,    -1,   698,   260,
     261,   262,   263,   667,   265,   266,   267,   268,   269,   270,
      41,    42,   273,    -1,   714,    -1,    -1,    -1,    -1,    -1,
     684,    -1,    -1,   714,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    40,
     714,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,    -1,    -1,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     371,   372,    -1,   374,   375,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   429,   430,
     431,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,   443,    -1,    -1,   446,    -1,    -1,    -1,    -1,
     451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      -1,    64,    65,   464,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    -1,    -1,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    -1,    -1,    -1,    -1,
      19,    -1,    -1,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,    40,    -1,   126,   127,    -1,    -1,    -1,   529,    -1,
     531,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    40,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    51,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    -1,
      -1,    -1,    91,    92,    93,    94,    95,    96,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,    -1,    -1,   126,   127,    -1,
      -1,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,   129,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,    -1,   129,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    40,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,
      64,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    -1,    -1,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    -1,    -1,    -1,    -1,    40,
      -1,    -1,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
      -1,    -1,   126,   127,    65,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    -1,    -1,    -1,
      91,    92,    93,    94,    95,    96,    97,    98,    -1,    -1,
      -1,    -1,    40,    -1,    -1,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,    -1,    -1,   126,   127,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      -1,    -1,    -1,    91,    92,    93,    94,    95,    96,    97,
      98,    -1,    -1,    -1,    -1,    40,    -1,    -1,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    -1,    -1,   126,   127,
      65,    42,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,    -1,
      -1,   126,   127,    40,    -1,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,    -1,    -1,   126,   127,    -1,    65,    -1,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,   122,   123
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    14,   131,   132,   134,   135,   137,   199,   200,   121,
       0,     3,     4,     8,    10,    11,    13,    16,    20,    21,
      38,   102,   133,   141,   145,   154,   155,   159,   205,   206,
     209,   211,   212,   213,   214,   215,   217,   219,   221,   222,
     223,   136,     5,    36,    39,   228,     5,   228,   121,   122,
     123,   401,   402,    12,   210,   210,   210,    17,    18,   146,
     147,    36,   280,    19,   126,   127,   156,   157,   351,   352,
     401,   142,   401,   142,   201,   220,     3,     4,   219,   218,
     223,    15,   138,   228,    31,    32,    33,    34,    35,    51,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   124,   125,   129,   229,   230,
     238,   286,   342,   343,   345,   346,   347,   350,   352,   353,
     391,   395,   396,   397,   398,   399,   400,   401,   403,   228,
     228,     9,   207,   208,     6,    23,   103,   104,   226,   227,
     226,   227,    19,    40,    65,    67,    68,    69,    70,    71,
      72,    73,    74,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    91,    92,    93,    94,    95,    96,
      97,    98,   150,   151,   152,   153,   272,   352,   377,   379,
     381,   382,   383,   386,   391,   395,   399,   401,   281,   142,
     351,   142,    22,    39,   160,   165,   166,   165,    49,   203,
     204,    39,   105,   224,   220,   139,   344,    37,   233,    43,
     239,   240,   288,    40,   287,    87,   128,   392,   393,   394,
     216,   226,   401,    40,    61,    62,    64,   352,   354,   355,
     358,   361,   362,   365,   366,   372,   374,   375,   376,   377,
     383,   389,   391,   395,   399,   401,    74,    40,    40,    40,
     129,   378,    40,   129,   278,    40,    40,    40,    36,   241,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,   151,    40,    40,   129,   273,   282,
     283,   286,   165,   158,   165,    23,   161,   162,   163,   164,
     401,    30,   189,   195,   197,   241,    89,   167,   168,   172,
     134,   200,   202,   241,    23,   225,   401,    39,   122,    50,
     289,   300,   351,   232,   234,   235,   230,   289,   294,   295,
     342,   348,   349,   350,   289,   401,   165,   354,   375,   375,
     375,    88,   148,   149,   357,   360,    55,    56,    57,    58,
      59,    60,    65,    66,   363,   364,   371,   373,   273,   390,
     241,   354,   354,   354,   354,   354,   354,   354,   242,   354,
     354,   354,   354,   352,   354,   354,   354,   354,   354,   354,
      17,   275,   275,   354,   275,   275,    37,    43,   284,   285,
     167,   167,   164,   190,    25,   189,    90,   169,   175,   401,
     241,   140,    52,   296,   299,   349,    43,   231,     6,    41,
     349,    41,   352,    41,    53,   356,    54,   359,   365,   365,
     365,   365,   365,   365,    66,   278,    61,    62,   367,   370,
     397,   398,    19,    63,   368,    41,    41,    41,   279,    48,
      48,    48,   143,   145,   243,   244,   245,   248,   301,   342,
     350,    41,    41,    48,    41,    41,    48,    41,    41,    41,
      41,    48,    19,   354,   385,   354,    41,   354,   354,   282,
     189,   189,    36,   352,    40,   173,   174,   272,   352,   377,
     176,   177,   271,   272,   376,   377,    24,   170,   178,   121,
     293,   298,   230,   351,   358,   361,   278,   372,   372,   368,
     369,   374,   374,   277,   354,   354,   354,   144,    37,   247,
      43,   249,   250,   303,   302,   354,   354,   354,    41,   384,
      41,   274,   196,   354,   174,   177,    25,    28,    29,   171,
     184,   187,   188,    49,   292,    48,   297,   236,    41,    48,
     276,    48,    41,    41,   165,     6,     7,    44,    45,    47,
     246,   251,   252,   254,   258,   261,   264,   265,   270,   245,
     295,   312,    40,    50,    64,    99,   304,   306,   313,   314,
     315,   316,   319,   322,   324,   330,   331,   352,   401,    41,
      41,   276,   380,    49,   387,   388,   277,   194,   149,    26,
      27,   179,   180,   181,   182,   183,   271,   352,   108,   108,
     185,   188,   186,   187,   290,   291,   300,   299,    36,   354,
     354,   167,   255,   259,   253,   262,   271,   231,   266,   315,
      40,    50,    99,   332,   337,   338,   340,   401,   322,   305,
     318,   321,    19,    36,    61,   100,   323,   325,   329,    41,
      75,    41,    41,    37,    40,   129,   192,    41,   180,   376,
     296,   237,    41,   189,   256,   260,   241,   263,   245,   241,
      41,   335,   336,   338,    50,   339,   401,   296,   101,   317,
      63,   320,    48,   108,   328,   341,    55,   193,   230,   351,
     351,   241,   269,    41,   334,   311,   319,   324,   341,    37,
      48,   327,   400,    42,   191,   198,   352,   391,   395,   399,
     401,    37,   257,   241,    46,   267,   101,   333,    49,   310,
      37,    37,   326,   341,    41,   198,   241,   268,   338,   306,
     307,   309,    37,   241,   308,   296
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
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  SPARQLfedParser::yyr1_[] =
  {
         0,   130,   131,   131,   132,   133,   133,   133,   133,   134,
     135,   135,   136,   136,   137,   139,   140,   138,   141,   142,
     142,   144,   143,   145,   146,   146,   147,   147,   148,   149,
     149,   150,   151,   151,   151,   151,   151,   151,   151,   151,
     152,   152,   153,   153,   154,   155,   156,   156,   157,   157,
     158,   158,   159,   160,   161,   161,   162,   163,   164,   165,
     166,   166,   167,   168,   168,   169,   169,   170,   170,   171,
     171,   172,   173,   173,   174,   174,   174,   174,   175,   176,
     176,   177,   178,   179,   179,   180,   180,   181,   181,   182,
     183,   183,   184,   184,   185,   185,   186,   186,   187,   188,
     189,   190,   190,   191,   191,   193,   192,   192,   194,   194,
     196,   195,   197,   197,   198,   198,   198,   198,   198,   198,
     199,   201,   200,   202,   202,   203,   204,   204,   205,   205,
     205,   205,   205,   205,   205,   205,   206,   207,   208,   208,
     209,   210,   210,   211,   212,   213,   214,   216,   215,   217,
     217,   218,   218,   219,   219,   220,   220,   221,   222,   223,
     224,   225,   225,   226,   227,   227,   227,   227,   228,   229,
     230,   230,   231,   231,   232,   233,   233,   235,   236,   237,
     234,   238,   239,   240,   240,   242,   241,   243,   243,   244,
     245,   245,   246,   247,   247,   248,   249,   250,   250,   251,
     251,   251,   251,   251,   251,   253,   252,   255,   256,   257,
     254,   259,   260,   258,   262,   263,   261,   265,   266,   264,
     268,   267,   269,   269,   270,   271,   271,   271,   272,   273,
     274,   273,   275,   275,   276,   277,   277,   278,   279,   278,
     281,   280,   282,   282,   283,   284,   285,   285,   287,   286,
     288,   286,   289,   290,   291,   291,   292,   293,   293,   294,
     295,   295,   296,   297,   298,   298,   299,   300,   300,   302,
     301,   303,   301,   305,   304,   306,   306,   308,   307,   309,
     309,   310,   311,   311,   312,   313,   314,   315,   316,   317,
     318,   318,   319,   320,   321,   321,   322,   323,   323,   324,
     324,   325,   326,   326,   327,   327,   328,   328,   329,   329,
     329,   329,   330,   331,   331,   331,   331,   332,   333,   334,
     334,   335,   336,   336,   337,   337,   338,   339,   339,   340,
     340,   340,   341,   342,   342,   344,   343,   345,   346,   346,
     346,   346,   346,   347,   347,   348,   348,   349,   349,   350,
     350,   351,   351,   352,   352,   353,   353,   353,   353,   353,
     353,   354,   355,   356,   357,   357,   358,   359,   360,   360,
     361,   362,   363,   363,   364,   364,   364,   364,   364,   364,
     364,   364,   365,   366,   367,   367,   368,   368,   369,   369,
     370,   370,   370,   371,   371,   372,   373,   373,   374,   374,
     374,   374,   375,   375,   375,   375,   375,   375,   375,   375,
     376,   377,   377,   377,   377,   377,   377,   377,   377,   377,
     377,   377,   377,   377,   377,   377,   377,   377,   377,   377,
     377,   377,   378,   378,   379,   380,   380,   381,   382,   383,
     383,   384,   383,   385,   385,   386,   386,   386,   386,   386,
     387,   388,   388,   389,   390,   390,   391,   392,   393,   393,
     394,   394,   395,   395,   395,   396,   396,   396,   397,   397,
     397,   398,   398,   398,   399,   399,   400,   400,   400,   400,
     401,   401,   402,   402,   403,   403
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
       8,     6,     6,     6,     4,     4,     4,     4,     4,     1,
       1,     1,     3,     1,     7,     0,     1,     2,     3,     5,
       5,     0,     7,     1,     1,     1,     1,     1,     1,     1,
       4,     0,     1,     2,     0,     1,     2,     2,     1,     1,
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
  "IT_AVG", "IT_GROUP_CONCAT", "IT_SAMPLE", "IT_isNUMERIC", "GT_CARROT",
  "GT_OPT", "GT_PIPE", "IT_WITH", "IT_DEFAULT", "IT_ALL", "IT_USING",
  "IT_true", "IT_false", "INTEGER", "DECIMAL", "DOUBLE",
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
       131,     0,    -1,   132,    -1,   199,    -1,   134,   133,    -1,
     141,    -1,   154,    -1,   155,    -1,   159,    -1,   135,   136,
      -1,    -1,   137,    -1,    -1,   136,   138,    -1,    14,   121,
      -1,    -1,    -1,    15,   139,   122,   140,   121,    -1,   145,
     142,   165,   167,   189,    -1,    -1,   142,   160,    -1,    -1,
     145,   144,   165,   167,   189,    -1,    16,   147,   153,    -1,
      17,    -1,    18,    -1,    -1,   146,    -1,    88,   352,    -1,
      -1,   148,    -1,    40,   354,   149,    41,    -1,   352,    -1,
     383,    -1,   377,    -1,   272,    -1,   391,    -1,   395,    -1,
     399,    -1,   150,    -1,   151,    -1,   152,   151,    -1,   152,
      -1,    19,    -1,    20,   280,   142,   165,   167,   189,    -1,
      21,   157,   142,   158,   167,   189,    -1,   351,    -1,   156,
     351,    -1,   156,    -1,    19,    -1,    -1,   165,    -1,    38,
     142,   165,   189,    -1,    22,   161,    -1,   162,    -1,   163,
      -1,   164,    -1,    23,   164,    -1,   401,    -1,   166,   241,
      -1,    -1,    39,    -1,   168,   169,   170,   171,    -1,    -1,
     172,    -1,    -1,   175,    -1,    -1,   178,    -1,    -1,   184,
      -1,    89,    25,   173,    -1,   174,    -1,   173,   174,    -1,
     377,    -1,   272,    -1,    40,   354,   149,    41,    -1,   352,
      -1,    90,   176,    -1,   177,    -1,   176,   177,    -1,   271,
      -1,    24,    25,   179,    -1,   180,    -1,   179,   180,    -1,
     182,    -1,   183,    -1,    26,    -1,    27,    -1,   181,   376,
      -1,   271,    -1,   352,    -1,   187,   185,    -1,   188,   186,
      -1,    -1,   188,    -1,    -1,   187,    -1,    28,   108,    -1,
      29,   108,    -1,   197,    -1,    -1,   190,   352,    -1,   198,
      -1,   191,   198,    -1,    -1,    40,   193,   191,    41,    -1,
     129,    -1,    -1,   194,   192,    -1,    -1,    30,   190,    36,
     196,   194,    37,    -1,    -1,   195,    -1,   401,    -1,   391,
      -1,   395,    -1,   399,    -1,    42,    -1,   352,    -1,   200,
      -1,    -1,   134,   205,   201,   204,    -1,    -1,   200,    -1,
      49,   202,    -1,    -1,   203,    -1,   206,    -1,   209,    -1,
     211,    -1,   212,    -1,   213,    -1,   214,    -1,   215,    -1,
     217,    -1,     8,   401,   208,    -1,     9,   226,    -1,    -1,
     207,    -1,    10,   210,   227,    -1,    -1,    12,    -1,    13,
     210,   227,    -1,    11,   210,   226,    -1,     4,     5,   228,
      -1,     3,     5,   228,    -1,    -1,     3,    39,   228,   216,
     165,    -1,   219,   220,    39,   241,    -1,   221,   219,   220,
      39,   241,    -1,    -1,   223,    -1,   222,   218,    -1,   223,
      -1,    -1,   220,   224,    -1,   102,   401,    -1,     3,   228,
      -1,     4,   228,    -1,   105,   225,    -1,   401,    -1,    23,
     401,    -1,     6,   401,    -1,   226,    -1,   103,    -1,    23,
      -1,   104,    -1,    36,   229,    37,    -1,   230,   233,    -1,
      -1,   238,    -1,    -1,    43,    -1,   234,   231,   230,    -1,
      -1,   233,   232,    -1,    -1,    -1,    -1,   235,     6,   351,
     236,    36,   237,   230,    37,    -1,   286,   240,    -1,    43,
     230,    -1,    -1,   239,    -1,    -1,    36,   242,   243,    37,
      -1,   143,    -1,   244,    -1,   245,   247,    -1,    -1,   248,
      -1,   251,   231,   245,    -1,    -1,   247,   246,    -1,   301,
     250,    -1,    43,   245,    -1,    -1,   249,    -1,   264,    -1,
     252,    -1,   261,    -1,   254,    -1,   258,    -1,   270,    -1,
      -1,    44,   253,   241,    -1,    -1,    -1,    -1,     6,   255,
     256,   351,   257,   241,    -1,    -1,    -1,     7,   259,   260,
     351,   241,    -1,    -1,    -1,    45,   262,   263,   241,    -1,
      -1,    -1,   265,   266,   241,   269,    -1,    -1,    46,   268,
     241,    -1,    -1,   269,   267,    -1,    47,   271,    -1,   376,
      -1,   377,    -1,   272,    -1,   401,   273,    -1,   129,    -1,
      -1,    40,   275,   354,   274,   277,    41,    -1,    -1,    17,
      -1,    48,   354,    -1,    -1,   277,   276,    -1,   129,    -1,
      -1,    40,   354,   279,   277,    41,    -1,    -1,    36,   281,
     282,    37,    -1,    -1,   283,    -1,   286,   285,    -1,    43,
     282,    -1,    -1,   284,    -1,    -1,   350,   287,   289,    -1,
      -1,   342,   288,   294,    -1,   300,   296,   293,    -1,   300,
     296,    -1,    -1,   290,    -1,    49,   291,    -1,    -1,   293,
     292,    -1,   295,    -1,    -1,   289,    -1,   299,   298,    -1,
      48,   299,    -1,    -1,   298,   297,    -1,   349,    -1,   351,
      -1,    50,    -1,    -1,   350,   302,   304,    -1,    -1,   342,
     303,   312,    -1,    -1,   306,   305,   296,   311,    -1,   313,
      -1,   314,    -1,    -1,   306,   308,   296,    -1,    -1,   307,
      -1,    49,   309,    -1,    -1,   311,   310,    -1,   295,    -1,
     315,    -1,   352,    -1,   316,    -1,   319,   318,    -1,   101,
     319,    -1,    -1,   318,   317,    -1,   324,   321,    -1,    63,
     324,    -1,    -1,   321,   320,    -1,   330,   323,    -1,    -1,
     325,    -1,   322,    -1,    99,   322,    -1,   329,    -1,    37,
      -1,   341,    37,    -1,    48,   326,    -1,    37,    -1,   341,
     327,    -1,    48,   341,    37,    -1,    19,    -1,   100,    -1,
      61,    -1,    36,   328,    -1,   331,    -1,   401,    -1,    50,
      -1,    64,   332,    -1,    40,   315,    41,    -1,   337,    -1,
     101,   338,    -1,    -1,   334,   333,    -1,   338,   334,    -1,
      -1,   335,    -1,   338,    -1,    40,   336,    41,    -1,   340,
      -1,   401,    -1,    50,    -1,   401,    -1,    50,    -1,    99,
     339,    -1,   108,    -1,   345,    -1,   343,    -1,    -1,    51,
     344,   289,    52,    -1,   347,    40,   348,    41,    -1,    31,
      -1,    32,    -1,    33,    -1,    34,    -1,    35,    -1,    -1,
     346,    -1,   349,    -1,   348,   349,    -1,   350,    -1,   342,
      -1,   352,    -1,   353,    -1,   352,    -1,   401,    -1,   126,
      -1,   127,    -1,   401,    -1,   391,    -1,   395,    -1,   399,
      -1,   403,    -1,   129,    -1,   355,    -1,   358,   357,    -1,
      53,   358,    -1,    -1,   357,   356,    -1,   361,   360,    -1,
      54,   361,    -1,    -1,   360,   359,    -1,   362,    -1,   365,
     363,    -1,    -1,   364,    -1,    55,   365,    -1,    56,   365,
      -1,    57,   365,    -1,    58,   365,    -1,    59,   365,    -1,
      60,   365,    -1,    66,   278,    -1,    65,    66,   278,    -1,
     366,    -1,   372,   371,    -1,   397,    -1,   398,    -1,    19,
     374,    -1,    63,   374,    -1,    -1,   368,    -1,    61,   372,
      -1,    62,   372,    -1,   367,   369,    -1,    -1,   371,   370,
      -1,   374,   373,    -1,    -1,   373,   368,    -1,    64,   375,
      -1,    61,   375,    -1,    62,   375,    -1,   375,    -1,   376,
      -1,   377,    -1,   389,    -1,   391,    -1,   395,    -1,   399,
      -1,   352,    -1,   383,    -1,    40,   354,    41,    -1,    76,
      40,   354,    41,    -1,    77,    40,   354,    41,    -1,    78,
      40,   354,    48,   354,    41,    -1,    79,    40,   354,    41,
      -1,    80,    40,   352,    41,    -1,    67,    40,   354,    41,
      -1,    68,    40,   354,    41,    -1,    69,   378,    -1,    70,
     278,    -1,    71,    40,   354,    48,   354,    48,   354,    41,
      -1,    72,    40,   354,    48,   354,    41,    -1,    73,    40,
     354,    48,   354,    41,    -1,    81,    40,   354,    48,   354,
      41,    -1,    82,    40,   354,    41,    -1,    83,    40,   354,
      41,    -1,    84,    40,   354,    41,    -1,    85,    40,   354,
      41,    -1,    98,    40,   354,    41,    -1,   379,    -1,   381,
      -1,   382,    -1,    40,   354,    41,    -1,   129,    -1,    86,
      40,   354,    48,   354,   380,    41,    -1,    -1,   276,    -1,
      74,   241,    -1,    65,    74,   241,    -1,    91,    40,   275,
     385,    41,    -1,   386,    40,   275,   354,    41,    -1,    -1,
      96,    40,   275,   354,   384,   388,    41,    -1,    19,    -1,
     354,    -1,    92,    -1,    93,    -1,    94,    -1,    95,    -1,
      97,    -1,    49,    75,    55,   400,    -1,    -1,   387,    -1,
     401,   390,    -1,    -1,   273,    -1,   400,   394,    -1,    87,
     401,    -1,   128,    -1,   392,    -1,    -1,   393,    -1,   396,
      -1,   397,    -1,   398,    -1,   108,    -1,   109,    -1,   110,
      -1,   111,    -1,   112,    -1,   113,    -1,   114,    -1,   115,
      -1,   116,    -1,   106,    -1,   107,    -1,   117,    -1,   119,
      -1,   118,    -1,   120,    -1,   121,    -1,   402,    -1,   123,
      -1,   122,    -1,   124,    -1,   125,    -1
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
    1089,  1091,  1093,  1097,  1099,  1107,  1108,  1110,  1113,  1117,
    1123,  1129,  1130,  1138,  1140,  1142,  1144,  1146,  1148,  1150,
    1152,  1157,  1158,  1160,  1163,  1164,  1166,  1169,  1172,  1174,
    1176,  1177,  1179,  1181,  1183,  1185,  1187,  1189,  1191,  1193,
    1195,  1197,  1199,  1201,  1203,  1205,  1207,  1209,  1211,  1213,
    1215,  1217,  1219,  1221,  1223,  1225
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
    2265,  2266,  2272,  2275,  2282,  2289,  2292,  2296,  2303,  2310,
    2313,  2317,  2317,  2329,  2333,  2337,  2340,  2343,  2346,  2349,
    2355,  2361,  2364,  2368,  2378,  2381,  2386,  2394,  2401,  2405,
    2413,  2417,  2421,  2422,  2423,  2427,  2428,  2429,  2433,  2434,
    2435,  2439,  2440,  2441,  2445,  2446,  2450,  2451,  2452,  2453,
    2457,  2458,  2462,  2463,  2467,  2468
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
     125,   126,   127,   128,   129
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SPARQLfedParser::yyeof_ = 0;
  const int SPARQLfedParser::yylast_ = 1576;
  const int SPARQLfedParser::yynnts_ = 274;
  const int SPARQLfedParser::yyempty_ = -2;
  const int SPARQLfedParser::yyfinal_ = 10;
  const int SPARQLfedParser::yyterror_ = 1;
  const int SPARQLfedParser::yyerrcode_ = 256;
  const int SPARQLfedParser::yyntokens_ = 130;

  const unsigned int SPARQLfedParser::yyuser_token_number_max_ = 384;
  const SPARQLfedParser::token_number_type SPARQLfedParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 4566 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 2474 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


