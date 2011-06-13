
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

  case 5:

/* Line 678 of lalr1.cc  */
#line 416 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.lastWhereClause != NULL)
	    driver.lastWhereClause->m_BindingClause = (yysemantic_stack_[(3) - (3)].p_BindingsClause);
	(yyval.p_Operation) = (yysemantic_stack_[(3) - (2)].p_Operation);
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 433 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingsClause) = NULL;
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 457 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 463 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 465 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 467 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 475 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(4) - (3)].p_WhereClause);
	(yyval.p_Operation) = new Select((yysemantic_stack_[(4) - (1)].p_Project).distinctness, (yysemantic_stack_[(4) - (1)].p_Project).varSet, (yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 483 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 486 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 494 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 497 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yysemantic_stack_[(5) - (3)].p_WhereClause)->m_BindingClause = (yysemantic_stack_[(5) - (5)].p_BindingsClause);
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(5) - (1)].p_Project).distinctness, (yysemantic_stack_[(5) - (1)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(5) - (3)].p_WhereClause), (yysemantic_stack_[(5) - (4)].p_SolutionModifier))));
      }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 505 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 513 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 516 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 523 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 531 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 538 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 546 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 553 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 556 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 559 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 562 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 565 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 568 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 571 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 580 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 583 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 591 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 594 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 601 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause);
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	(yyval.p_Operation) = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(5) - (2)].p_BasicGraphPattern), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 610 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause);
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 618 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm))));
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 621 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_TTerm))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 629 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 632 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 639 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 647 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(3) - (3)].p_WhereClause);
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(3) - (2)].p_DatasetClauses), (yysemantic_stack_[(3) - (3)].p_WhereClause));
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 655 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 667 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 673 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 679 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 686 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp ? driver.curOp : new DefaultGraphPattern(), NULL);
	driver.curOp = NULL;
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 700 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 707 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 715 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 723 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 731 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 739 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 746 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 749 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 756 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 759 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 762 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 765 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 771 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 777 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 780 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 792 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 799 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 803 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 813 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 821 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 824 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 832 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 841 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 848 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 852 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 860 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 868 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 875 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 881 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 888 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingsClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_TTermList));
      }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 890 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingsClause) = driver.curBindingsClause;
	  driver.curBindingsClause = NULL;
      }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 898 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTermList) = new TTermList;
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 901 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTermList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_TTermList) = (yysemantic_stack_[(2) - (1)].p_TTermList);
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 908 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curBinding->size() + 1 > driver.curBindingsClause->getVars()->size()) {
	    std::stringstream ss;
	    ss << "atom " << (yysemantic_stack_[(1) - (1)].p_TTerm)->toString() << " binding tuple wider than first argument to BINDINGS.";
	    error(*(yylocation_stack_.begin()), ss.str().c_str());
	}
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 916 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 922 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBinding = new Binding();
      }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 924 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingValue) = driver.curBinding;
	  driver.curBinding = NULL;
      }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 928 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingValue) = new Binding();
	driver.curBinding = NULL;
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 935 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 938 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBindingsClause->push_back((yysemantic_stack_[(2) - (2)].p_BindingValue));
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 945 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 948 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 951 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 954 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 957 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 960 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 970 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	OperationSet* ret = driver.root ? dynamic_cast<OperationSet*>(driver.root) : new OperationSet();
	ret->push_back((yysemantic_stack_[(2) - (2)].p_Operation));
	driver.root = ret;
      }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 974 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Operation) = driver.root;
	}
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1008 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(3) - (2)].p_URI), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1015 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1022 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1029 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1035 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1038 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1044 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1050 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1056 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1062 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1068 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1074 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert(driver.curOp, NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1082 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete(driver.curOp, NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1090 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete(driver.curOp, NULL);
	driver.curOp = NULL;
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1098 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(5) - (1)].p_URI))
	    w3c_sw_NEED_IMPL("WITH <URI> (DELETE INSERT?|INSERT) ...");
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(5) - (2)].p_DeleteInsert).del, (yysemantic_stack_[(5) - (2)].p_DeleteInsert).ins, new WhereClause(driver.curOp, NULL));
	driver.curOp = NULL;
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1107 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1113 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1120 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1127 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1131 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 1139 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("_QUsingClause_E_Star");
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 1145 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Delete) = new Delete(driver.curOp, NULL);
	driver.curOp = NULL;
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1152 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = new Insert(driver.curOp, NULL);
	driver.curOp = NULL;
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1159 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1165 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1168 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1174 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1177 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 1188 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1194 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 1197 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("DEFAULT");
      }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 1200 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("NAMED");
      }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 1203 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("ALL");
      }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 1243 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curFilter = NULL;
      }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 1247 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 1250 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 1253 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1275 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1278 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 1355 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_BindingsClause)) : (yysemantic_stack_[(1) - (1)].p_BindingsClause);
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 1362 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Print(driver.curOp);
    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 1368 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 1371 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 222:

/* Line 678 of lalr1.cc  */
#line 1383 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 1386 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 1388 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 1391 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 1399 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 1402 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 1404 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(5) - (4)].p_TTerm), driver.curOp, driver.atomFactory, false));
      }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 1411 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Bind(driver.curOp, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 1417 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 1420 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 1422 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.curOp));
      }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 1430 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 1433 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 1435 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 1443 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 1448 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 1463 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    if (driver.curOp == NULL)
		driver.ensureBasicGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 1480 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 1488 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 1492 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 1494 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = NULL;
      }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 1501 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 1504 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 1511 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 1519 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 1533 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 1536 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 1538 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 1546 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 1548 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 1576 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 1579 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 1639 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 1646 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 1650 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 1658 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 1661 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 1667 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 1678 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 1706 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 1733 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 1740 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 1751 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 1758 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 1794 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 1797 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 1800 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 1803 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 1861 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 1865 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 1874 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 354:

/* Line 678 of lalr1.cc  */
#line 1899 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 1902 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 1905 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 1908 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 1911 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 1918 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 1926 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 1930 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 1942 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 1949 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 1952 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 1963 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 1966 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 1969 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 1972 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 1976 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 1987 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 1996 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 2003 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 2006 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 2014 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 2023 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 2030 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 2033 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 2045 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_GeneralComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_GeneralComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_GeneralComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 2056 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 2063 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 2066 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 2069 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 2072 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 2075 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 2078 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 2081 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 2084 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 2095 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 2104 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 2107 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 2114 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 2117 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 2124 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 2132 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 2135 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 2139 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 409:

/* Line 678 of lalr1.cc  */
#line 2153 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 2156 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 2164 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 2173 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 2176 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 2183 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 2186 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 2189 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 2199 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 2202 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 2205 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 2208 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 2215 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 2221 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 2224 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 2227 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 2230 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 2233 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 2236 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 2239 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 2243 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_blank, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 2246 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 2249 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 2252 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ciel, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 2255 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 2258 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 2261 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::XPATH_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 2265 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlen, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 2268 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ucase, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 2271 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lcase, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 2274 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encodeForUri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 2277 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 2280 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strStarts, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 2283 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strEnds, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 2286 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 2289 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 2292 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 2295 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 2298 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 2301 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 2304 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 2307 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 2310 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 2313 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 2316 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha224, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 2319 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 2322 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 2325 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 2328 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 2332 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 2335 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 2338 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 2341 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 2344 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 2347 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 2350 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 2353 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 2356 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 2367 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 2370 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 2377 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_regex, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 2384 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 2391 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 2397 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 2404 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 2411 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 2414 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 2418 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 2420 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  // x = new ArgList($2, driver.curExprList);
	  delete driver.curExprList;
	  driver.curExprList = NULL;
	  w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // $$ = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group-concat, $3, $4.p_Expression, $4.separator));
    }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 2430 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
	driver.countStar = true;
    }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 2438 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 2441 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 2444 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 2447 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 2450 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 2456 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 2462 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 2469 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 2479 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 2487 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 2495 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 2502 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 2506 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 2514 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 3410 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -740;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        39,  -100,    60,  -740,  -740,   515,  -740,  -740,  -740,  -740,
    -740,  -740,   175,    70,    70,    70,    29,    94,    -1,  -740,
     175,    70,    70,   106,   111,    70,   111,    74,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,    91,   141,  -740,  -740,
    -740,   198,  -740,  -740,    32,   178,    32,  -740,  -740,  -740,
    1256,  -740,  -740,  -740,  -740,  -740,   119,  -740,  -740,  -740,
    -740,    50,  -740,    27,    27,   802,  -740,   802,  -740,    27,
    -740,  -740,  -740,  -740,    50,   187,   106,   106,  -740,   245,
    -740,  -740,  -740,   178,  -740,  -740,   175,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  1405,   193,   233,   236,   -17,
      -6,   240,   250,   251,   257,   256,   258,   260,   281,   283,
     284,   286,   297,   298,   304,   305,    -6,   308,  -740,  -740,
    -740,  -740,   310,  -740,   311,   316,   318,   199,   319,   200,
     320,   324,   329,   330,   332,   333,   337,   342,   345,   347,
     348,   350,   351,   354,   357,   358,   359,   362,   363,   366,
     367,   368,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  1507,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,   371,
    -740,  -740,  -740,  -740,  -740,  -740,   -51,    12,   802,    50,
    -740,    76,    -7,  -740,  -740,  -740,   257,  -740,  -740,   306,
     175,   307,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,   375,  -740,  -740,   370,  -740,  -740,  -740,  -740,   376,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,   380,   321,
       7,   328,    66,  -740,  -740,  -740,  -740,     5,  -740,  -740,
     265,  -740,  -740,  1405,  1609,  1609,  1609,  -740,   338,  -740,
    -740,  -740,  -740,   206,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,    12,   257,  1405,  1405,  1405,
    -740,  -740,  1405,  -740,  -740,  1405,  1405,  1405,  -740,  -740,
    1405,  1405,  1405,  1405,    24,  1405,  1405,  1405,  1405,  1405,
    1405,  -740,   402,   402,  1405,  1405,  1405,  -740,  1405,  -740,
    1405,  1405,  1405,  1405,  1405,  1405,  1405,  1405,  1405,  1405,
    1405,  1405,  1405,  1405,  1405,  1405,  1405,  1405,  1405,  1405,
    1405,  1405,  -740,   402,   175,  -740,  -740,  -740,  -740,   402,
    -740,  -740,   393,  -740,   388,   328,   328,  -740,   175,  -740,
    -740,  -740,  -740,  -740,  -740,    27,  -740,    27,    88,  -740,
     426,   802,  -740,  -740,    88,  1280,    88,  -740,    27,  -740,
    -740,   408,  -740,   343,  -740,   373,  -740,  -740,   257,     6,
    -740,  -740,   394,  -740,  -740,  -740,    24,  -740,   395,   384,
     385,  1405,  1405,  1405,  1405,  1405,  1405,   372,    -6,  -740,
    -740,   179,    20,  -740,  -740,  -740,   400,   401,   403,  -740,
     397,   399,   404,   772,   407,   410,   405,   414,   416,   411,
     417,   420,   421,   422,   419,  -740,  1110,  1405,   428,   429,
     430,   434,   438,   439,   440,   437,   441,   445,   449,   443,
     451,   452,   454,   453,   456,   458,   459,   461,   462,   465,
     460,   466,   468,   469,  1405,  -740,  1405,  -740,   802,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,   391,  1280,  -740,
    -740,   406,   505,  -740,  -740,  -740,  -740,  -740,    68,  -740,
    -740,  -740,  -740,  -740,  1711,  1833,   488,  -740,  -740,   175,
    -740,  -740,   355,  -740,  -740,  -740,  1405,  -740,  1405,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,    -6,  -740,  1405,  1405,
      20,  -740,  -740,  -740,  1405,  1405,  -740,  -740,  -740,  -740,
    -740,  1405,  1405,  1405,  -740,  -740,   477,  -740,  -740,  -740,
     472,  -740,  -740,  -740,  -740,  1405,  -740,  -740,  1405,  -740,
    -740,  -740,  -740,  1405,  -740,  -740,   475,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  1405,  -740,  -740,  -740,  1405,
    -740,  -740,  -740,  1405,  -740,  -740,  -740,  -740,  -740,  -740,
    1405,  -740,  -740,  -740,   476,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,   802,   119,  -740,  -740,   -16,  1405,  1711,  -740,
    -740,  -740,  -740,  1833,  -740,  -740,  -740,  -740,  -740,   493,
     145,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,   151,   471,   479,   480,   483,  -740,    61,
     802,  -740,  -740,    88,    46,   486,   489,   485,  -740,   490,
     496,   485,   500,   501,  -740,  -740,   494,   497,  -740,  -740,
    -740,  -740,  -740,  -740,   338,  -740,  -740,   945,   409,   412,
    -740,  -740,   517,   519,  -740,  1405,  -740,  1405,  -740,  -740,
     328,  -740,  -740,  -740,  -740,  1833,   508,    34,  -740,  -740,
     406,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,   220,  -740,    85,   129,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,   238,  -740,  -740,  -740,
    -740,  -740,  -740,   509,   474,  -740,   510,  -740,   511,  -740,
    -740,   194,    88,  -740,  1280,  -740,   520,   843,   514,  -740,
    -740,   945,  -740,   518,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,   522,    74,  -740,  -740,   257,
    -740,  -740,  1405,  -740,   802,   257,   524,    95,  -740,    79,
    -740,  -740,  -740,  -740,  -740,  -740,  1280,   457,   498,  -740,
     -11,  -740,  -740,  -740,  -740,  -740,  -740,   512,  -740,  -740,
    -740,  -740,  -740,  1280,  -740,  -740,  -740,  1733,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,   119,
     119,  -740,   257,   484,  -740,  -740,  -740,  -740,   525,  -740,
    -740,  -740,  -740,  -740,   220,  -740,   220,  -740,   415,  -740,
    -740,    96,   161,  -740,   802,  -740,  -740,  -740,   257,  -740,
      24,   523,  -740,   470,   526,  -740,  -740,   537,  -740,    -2,
    -740,  -740,   540,   257,  -740,   538,  -740,  -740,    95,  -740,
      46,  -740,  -740,  -740,  -740,   543,  -740,  -740,  -740,   257,
    -740,  -740,  -740,  -740,  -740,  -740,  1280,  -740
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
     133,   135,   136,   137,   138,   157,     0,    12,   525,   528,
     527,   141,   526,   145,     0,     0,     0,    27,    28,    30,
       0,   256,    22,    52,   369,   370,    51,    22,    49,   367,
     368,    63,   155,   171,   171,   181,   153,   181,   152,   171,
     151,   105,     5,    11,    63,   126,     0,     0,   162,   158,
     161,    18,    16,     0,   142,   139,     0,   176,   175,   177,
     174,   143,   147,   146,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   490,   491,
     492,   493,     0,   494,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   519,   520,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   521,   523,   522,   524,    42,    43,    45,
      26,    38,    35,    37,   473,   441,   474,   475,    36,     0,
      39,    40,   507,   508,   509,    41,   505,     0,   258,    63,
      50,    53,     0,    64,    23,    55,     0,   172,   169,     0,
       0,     0,   354,   355,   356,   357,   358,   351,   529,   530,
     376,     0,   186,   182,   194,   266,   350,   349,   360,     0,
     264,   365,   366,   372,   373,   374,   371,   375,     0,     0,
       0,    66,    13,   127,   122,   164,   165,     0,   160,   159,
       0,   140,   173,     0,     0,     0,     0,   424,    32,   377,
     380,   384,   386,   388,   398,   409,   412,   417,   418,   419,
     425,   420,   421,   422,   423,   499,     0,     0,     0,     0,
     477,   434,     0,   253,   463,     0,     0,     0,   196,   482,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   440,   248,   248,     0,     0,     0,   435,     0,   456,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,   248,     0,   503,   504,   506,   501,   248,
     245,   244,     0,   259,   262,    66,    66,    54,     0,    56,
      57,    58,    59,    61,    62,   171,   170,   171,     0,   178,
     180,   181,   195,   192,   276,   359,     0,   179,   171,   103,
     106,     0,    21,    68,    67,   156,   124,   125,     0,     0,
     163,    19,     0,   415,   416,   414,     0,    33,     0,   378,
     382,     0,     0,     0,     0,     0,     0,     0,     0,   387,
     389,   399,   411,   500,   498,   483,     0,     0,     0,   254,
       0,     0,     0,   201,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   249,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   502,     0,   257,   258,   263,
     260,    47,    48,    60,   148,   150,   284,     0,   359,   283,
     187,   183,     0,   193,   277,   267,   275,   364,   359,   361,
     363,   265,   149,   112,     0,     0,    70,    69,   154,     0,
     166,   167,     0,   426,    31,    34,     0,   381,     0,   385,
     390,   391,   392,   393,   394,   395,     0,   396,     0,     0,
     404,   410,   400,   401,     0,     0,   413,   432,   433,   476,
     251,     0,     0,     0,   198,    24,     0,   199,   204,   202,
     208,   287,   285,   427,   428,     0,   430,   431,     0,   468,
     469,   470,   471,     0,   488,   489,     0,   486,   472,   457,
     449,   462,   455,   439,   461,     0,   454,   438,   453,     0,
     460,   452,   445,     0,   437,   451,   444,   436,   443,   459,
       0,   442,   458,   450,     0,   246,   261,   352,   273,   280,
     282,   184,   181,     0,   353,   362,     0,     0,    74,    75,
      78,    80,    77,    81,    82,    84,   243,   241,   242,     0,
      72,    71,   168,    20,   379,   383,   397,   406,   407,   405,
     408,   402,   403,     0,     0,     0,     0,    63,   197,   200,
     201,   209,   206,   276,     0,     0,     0,   479,   484,   496,
       0,   479,     0,     0,   485,   251,   268,   278,   185,   189,
     104,   109,   111,   113,    32,    76,    83,     0,     0,     0,
      65,    73,    97,    99,   255,     0,   252,     0,   465,   466,
      66,   222,   226,   220,   230,     0,     0,   233,   217,   205,
     183,   218,   211,   213,   214,   216,   212,   210,   234,   215,
     207,   300,   288,     0,   330,     0,     0,   286,   289,   291,
     292,   301,   303,   306,   315,   310,   313,   328,   302,   329,
     429,   467,   480,     0,     0,   497,     0,   446,     0,   447,
     448,     0,   270,   274,   359,   281,     0,     0,     0,    90,
      91,    85,    86,     0,    88,    89,    93,    94,   101,   102,
      95,    98,    96,   100,   250,     0,    10,   223,   227,     0,
     231,   240,     0,   219,   201,     0,     0,   338,   346,     0,
     331,   333,   340,   342,   345,   316,   359,   304,   308,   324,
       0,   326,   325,   312,   314,   317,   478,     0,   487,   481,
     247,   271,   272,   359,   279,   190,   118,     0,   107,   119,
     115,   116,   117,   114,    79,    87,    92,   464,    25,     0,
       0,   221,     0,     0,   203,   238,   332,   339,     0,   335,
     344,   347,   343,   298,     0,   307,     0,   311,     0,   348,
     327,     0,     0,   269,   181,   110,   108,   224,     0,   232,
       0,   235,   341,   337,   290,   305,   309,     0,   321,     0,
     322,   495,     0,     0,   228,     0,   236,   239,     0,   336,
     295,   299,   323,   318,   320,     0,   191,   225,   229,     0,
     334,   293,   296,   297,   319,   237,   359,   294
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -740,  -740,  -740,  -740,  -740,  -154,   341,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,   230,  -740,  -740,   171,  -740,  -740,
    -740,   -57,  -740,   418,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,   237,   -77,  -740,  -335,
    -740,  -740,  -740,  -740,  -740,  -740,     1,  -740,  -740,    -3,
    -740,  -740,  -135,  -740,  -740,  -740,  -740,  -740,  -740,   -54,
     -52,  -574,  -740,  -740,  -740,  -740,  -740,  -740,  -182,  -740,
     352,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
     280,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,   507,  -740,  -740,   -49,
    -740,    -5,   545,   110,   577,   527,  -349,   -65,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -201,  -740,  -740,
    -740,  -589,  -740,  -740,  -740,  -740,  -740,   -60,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -573,
     -56,   334,  -740,  -226,  -459,   -25,  -117,  -740,  -740,  -740,
     155,  -740,  -740,  -740,  -183,  -740,  -740,  -175,  -740,  -740,
    -740,  -740,  -740,    -9,  -724,  -740,  -740,   -99,   -93,  -740,
    -740,  -740,  -740,  -740,  -220,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,   -62,  -740,  -740,  -740,  -181,  -740,  -740,
     -64,  -740,  -179,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -720,  -740,  -740,  -739,
    -352,  -740,  -740,  -740,  -740,  -740,  -740,  -339,  -351,   -15,
      10,  -740,   578,  -740,  -740,  -740,   128,  -740,  -740,   130,
    -740,  -740,  -740,   -82,  -740,  -740,   126,  -740,  -740,  -740,
    -307,  -740,  -229,    86,  -465,   -59,  -740,  -740,     8,  -740,
    -740,  -740,   -38,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
     -58,  -740,  -740,  -740,   -18,  -740,   241,   242,    -4,  -171,
     -12,  -740,  -740
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
     601,   721,   722,   723,   724,   725,   651,   730,   732,   652,
     653,    83,   483,   240,   777,   643,   717,   586,   778,     8,
       9,    85,   377,   243,   244,    33,    34,    94,    95,    35,
      54,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,   248,    88,   247,    89,    90,   380,   490,   209,
     210,   100,   101,    76,    78,   221,   222,   582,   470,   360,
     471,   472,   716,   814,   223,   362,   363,   289,   413,   526,
     527,   528,   669,   619,   529,   621,   622,   670,   671,   672,
     739,   673,   737,   789,   833,   674,   738,   790,   675,   676,
     740,   792,   677,   678,   745,   837,   849,   821,   679,   595,
     596,   341,   635,   426,   656,   613,   284,   520,    62,   198,
     342,   343,   459,   460,   224,   366,   364,   474,   771,   772,
     713,   636,   475,   476,   578,   715,   637,   579,   468,   530,
     624,   623,   687,   756,   688,   852,   856,   853,   841,   824,
     682,   689,   690,   691,   692,   805,   757,   693,   807,   758,
     694,   763,   695,   764,   844,   830,   810,   765,   696,   697,
     750,   839,   823,   797,   798,   751,   752,   801,   753,   811,
     225,   226,   358,   227,   228,   229,   478,   580,   230,   469,
     257,   232,   258,   259,   497,   389,   260,   499,   390,   261,
     262,   399,   400,   263,   264,   510,   516,   610,   511,   401,
     265,   402,   266,   267,   268,   269,   281,   184,   703,   185,
     186,   187,   270,   629,   546,   189,   705,   706,   271,   404,
     272,   336,   337,   338,   273,   192,   193,   194,   274,   196,
     275,    52,   237
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SPARQLfedParser::yytable_ninf_ = -360;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        51,   183,   190,    68,   181,   354,    70,   241,    72,   301,
     461,   462,   473,   477,   480,   344,   348,   233,    63,   233,
     597,   640,   188,   279,   641,   211,   479,   799,    69,   489,
     239,   680,   803,   207,   282,   843,   334,   808,    96,   514,
     661,   662,   191,   369,   378,   668,    57,    58,   197,   813,
     102,   200,   339,     1,    70,    97,   195,   234,    10,   234,
      11,   531,   532,   236,    81,   236,  -123,   661,   662,   827,
     182,   235,   202,   235,   726,   405,    69,   427,   663,   664,
       1,   665,    53,   515,   252,   231,   683,   231,   251,   203,
     845,    81,   741,   668,    86,    87,   684,  -233,   202,   212,
     213,   214,   215,   216,    81,   663,   664,   454,   665,   584,
     685,   379,   -63,   456,   335,   203,   477,   480,   850,   217,
     183,   190,   345,   181,   347,   747,   477,   480,   597,   800,
      61,   208,   857,   828,   809,   748,    98,    99,   466,   585,
     233,   188,    75,   809,   829,   748,   686,    77,   726,   280,
     642,    48,    49,    50,   666,   794,    91,    48,    49,    50,
     283,   191,    64,    65,    48,    49,    50,   197,   702,   683,
      64,    65,   702,   648,   649,   195,   667,   488,   340,   684,
     234,   666,   597,   467,    96,   749,   236,    64,    65,   182,
     353,   481,   654,   685,   235,   749,   245,   246,   356,   655,
     597,   607,   608,   667,    48,    49,    50,    93,   231,    64,
      65,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,    48,    49,    50,   218,
     219,    64,    65,   638,   220,   770,   242,    48,    49,    50,
     508,   509,   655,    48,    49,    50,    48,    49,    50,    87,
     370,    64,    65,    48,    49,    50,   597,   759,   786,    84,
     683,   391,   392,   393,   394,   395,   396,   276,   531,   532,
     684,   397,   398,   277,   760,   344,   278,    48,    49,    50,
     285,   507,    64,    65,   685,   611,   612,    48,    49,    50,
     286,   287,   199,   288,    55,    56,   290,   201,   291,   761,
     292,    73,    74,   233,   418,    79,   464,   233,   465,   500,
     501,   502,   503,   504,   505,   173,   174,   175,   176,   482,
     686,   293,   455,   294,   295,   736,   296,   167,   168,   169,
     170,   171,   172,    48,    49,    50,   353,   297,   298,   762,
     383,   384,   385,   234,   299,   300,    70,   234,   302,   236,
     303,   304,    70,   236,    70,   233,   305,   235,   306,   308,
     310,   235,   477,   480,   311,   307,   309,   491,    69,   312,
     313,   231,   314,   315,    69,   231,    69,   316,    48,    49,
      50,    12,   317,    13,    14,   318,    15,   319,   320,   606,
     321,   322,   531,   532,   323,   234,   494,   324,   325,   326,
     233,   236,   327,   328,   477,   480,   329,   330,   331,   235,
     233,   333,   359,   361,   355,   357,   365,   367,   371,   425,
     233,   477,   480,   231,   381,   592,   598,   386,   590,   368,
     457,   458,  -188,   484,   485,   493,   495,   496,   506,   498,
     234,   517,   518,   577,   519,   521,   236,   522,   533,   581,
     234,   534,   523,   535,   235,   536,   236,   537,   539,   538,
     234,   540,   541,   542,   235,   832,   236,   543,   231,   548,
     549,   550,   197,   197,   235,   551,    20,   602,   231,   552,
     553,   554,   556,    21,    22,   555,   557,    23,   231,    24,
     558,   559,   560,   561,   591,   562,    25,   564,    26,   565,
     566,   563,   567,   568,   477,   480,   569,   571,   570,   572,
     573,   583,   599,   603,   618,   620,   628,   634,   647,   657,
     658,   659,   203,    12,   233,    13,    14,   700,    15,   592,
     701,    16,   590,   655,   598,    17,    18,   707,   791,   704,
     660,   709,   710,   712,   795,   714,   649,   648,   742,   767,
     766,   768,   769,    19,   728,   784,   775,   729,   253,   804,
     809,   806,   233,   787,   234,   796,   822,   812,   639,   836,
     236,    70,   838,   820,   842,   840,   197,   846,   235,   848,
     854,   197,   788,   375,   525,   463,   785,   718,   598,   645,
     646,   819,   231,    69,   376,   816,   249,   332,   591,   733,
     731,   103,   234,    80,   238,   744,   598,   743,   236,   403,
     711,    70,   699,   576,   681,   774,   235,   834,    20,   773,
     851,   746,   755,   825,   604,    21,    22,   826,   605,    23,
     231,    24,   847,    69,   698,   197,   609,     0,    25,   708,
      26,   831,   512,   513,     0,     0,     0,     0,   855,     0,
       0,     0,     0,   197,     0,     0,   233,   727,     0,   780,
       0,     0,   598,     0,     0,     0,     0,     0,     0,     0,
       0,   699,     0,   754,   699,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   233,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   234,     0,   233,   781,
      70,     0,   236,     0,     0,   783,     0,     0,     0,   197,
     235,     0,     0,   782,     0,   233,     0,     0,     0,   780,
       0,     0,    69,     0,   231,     0,   234,   779,     0,     0,
       0,   727,   236,     0,     0,   754,     0,   802,   234,     0,
     235,     0,     0,     0,   236,     0,     0,     0,     0,     0,
       0,     0,   235,     0,   231,   234,   233,     0,     0,   781,
       0,   236,     0,     0,     0,   783,   231,     0,     0,   235,
       0,     0,     0,   782,   817,   818,     0,    70,    70,     0,
       0,     0,     0,   231,     0,     0,     0,   779,    16,     0,
       0,     0,   699,     0,   699,     0,   234,     0,   233,    69,
      69,     0,   236,   212,   213,   214,   215,   216,     0,     0,
     235,     0,  -359,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   217,   231,     0,   754,     0,   699,     0,
     835,   382,     0,   212,   213,   214,   215,   216,   234,     0,
       0,     0,  -359,     0,   236,     0,     0,     0,     0,     0,
     698,     0,   235,   217,     0,   406,   407,   408,     0,     0,
     409,     0,     0,   410,   411,   412,   231,     0,   414,   415,
     416,   417,     0,   419,   420,   421,   422,   423,   424,     0,
       0,     0,   428,   429,   430,   776,   431,     0,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
       0,     0,     0,     0,     0,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
      48,    49,    50,   218,   219,    64,    65,     0,   220,     0,
       0,     0,     0,     0,     0,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
      48,    49,    50,   218,   219,    64,    65,     0,   220,     0,
       0,   719,   720,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   253,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    48,    49,    50,   545,   547,    64,    65,     0,     0,
     106,     0,   107,   108,   109,   110,   111,   112,   113,   114,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   574,   126,   575,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,     0,     0,     0,     0,     0,
       0,     0,   135,     0,   136,     0,     0,   137,   138,     0,
     139,     0,   140,   141,   142,     0,   143,   144,     0,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   614,
     615,   616,     0,    48,    49,    50,     0,     0,    64,    65,
       0,     0,     0,   625,     0,     0,   626,     0,     0,     0,
       0,   627,     0,     0,     0,     0,     0,     0,     0,   544,
       0,     0,     0,   630,     0,     0,     0,   631,     0,     0,
       0,   632,     0,     0,     0,     0,     0,     0,   633,     0,
     253,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   644,     0,     0,     0,     0,
       0,   254,   255,     0,   256,   106,     0,   107,   108,   109,
     110,   111,   112,   113,   114,     0,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,     0,   126,     0,
       0,     0,   127,   128,   129,   130,   131,   132,   133,   134,
       0,     0,     0,     0,     0,     0,     0,   135,     0,   136,
       0,     0,   137,   138,     0,   139,     0,   140,   141,   142,
       0,   143,   144,   734,   145,   735,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,     0,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,    48,    49,
      50,     0,     0,    64,    65,   104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   212,   213,   214,   215,   216,     0,     0,     0,     0,
     793,   106,     0,   107,   108,   109,   110,   111,   112,   113,
     114,   217,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,     0,     0,   127,   128,
     129,   130,   131,   132,   133,   134,     0,     0,     0,     0,
       0,     0,     0,   135,     0,   136,     0,     0,   137,   138,
       0,   139,     0,   140,   141,   142,     0,   143,   144,     0,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,     0,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,    48,    49,    50,     0,     0,    64,
      65,     0,     0,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,    48,    49,
      50,   218,   219,    64,    65,   253,   220,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   254,   255,     0,   256,
     106,     0,   107,   108,   109,   110,   111,   112,   113,   114,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,     0,     0,   127,   128,   129,
     130,   131,   132,   133,   134,     0,     0,     0,     0,     0,
       0,     0,   135,     0,   136,     0,     0,   137,   138,     0,
     139,     0,   140,   141,   142,     0,   143,   144,     0,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   105,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    48,    49,    50,     0,     0,    64,    65,
       0,     0,   106,     0,   107,   108,   109,   110,   111,   112,
     113,   114,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,     0,     0,   127,
     128,   129,   130,   131,   132,   133,   134,     0,     0,     0,
       0,     0,     0,     0,   135,     0,   136,     0,     0,   137,
     138,     0,   139,     0,   140,   141,   142,     0,   143,   144,
       0,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   253,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    48,    49,    50,     0,     0,
      64,    65,     0,     0,   106,     0,   107,   108,   109,   110,
     111,   112,   113,   114,     0,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,     0,
       0,   127,   128,   129,   130,   131,   132,   133,   134,     0,
       0,     0,     0,     0,     0,     0,   135,     0,   136,     0,
       0,   137,   138,     0,   139,     0,   140,   141,   142,     0,
     143,   144,     0,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   587,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    48,    49,    50,
       0,     0,    64,    65,   815,   776,   106,     0,   107,   108,
     109,   110,   111,   112,   113,   114,     0,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,     0,     0,     0,     0,     0,     0,     0,   135,     0,
     136,     0,     0,   137,   138,     0,   139,     0,   140,   141,
     142,     0,   143,   144,     0,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
      49,    50,     0,   253,    64,    65,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    48,    49,    50,     0,     0,    64,    65,   106,     0,
     107,   108,   109,   110,   111,   112,   113,   114,     0,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,     0,     0,     0,     0,     0,     0,     0,
     135,     0,   136,     0,     0,   137,   138,     0,   139,     0,
     140,   141,   142,     0,   143,   144,     0,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,    49,    50
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        12,    60,    60,    18,    60,   206,    18,    84,    20,   126,
     345,   346,   361,   365,   365,   198,    23,    75,    19,    77,
     485,    37,    60,    40,    40,    74,   365,   747,    18,    23,
      79,   620,   756,     6,    40,    37,    87,    48,     6,    19,
       6,     7,    60,    36,    39,   619,    17,    18,    60,   773,
      55,    66,    40,    14,    66,    23,    60,    75,   158,    77,
       0,   413,   413,    75,    30,    77,     0,     6,     7,   808,
      60,    75,    22,    77,   647,   276,    66,   303,    44,    45,
      14,    47,    12,    63,    96,    75,    40,    77,    93,    39,
     829,    30,   665,   667,     3,     4,    50,    36,    22,    31,
      32,    33,    34,    35,    30,    44,    45,   333,    47,    41,
      64,   106,    36,   339,   165,    39,   468,   468,   838,    51,
     179,   179,   199,   179,   201,    40,   478,   478,   593,    50,
      36,   104,   856,    37,   145,    50,   104,   105,    50,   478,
     198,   179,    36,   145,    48,    50,   100,    36,   721,   166,
     166,   158,   159,   160,   120,   744,    15,   158,   159,   160,
     166,   179,   163,   164,   158,   159,   160,   179,   627,    40,
     163,   164,   631,    28,    29,   179,   142,   378,   166,    50,
     198,   120,   647,   358,     6,   100,   198,   163,   164,   179,
     202,   366,    41,    64,   198,   100,    86,    87,   210,    48,
     665,   508,   509,   142,   158,   159,   160,     9,   198,   163,
     164,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   582,   166,    41,    49,   158,   159,   160,
      61,    62,    48,   158,   159,   160,   158,   159,   160,     4,
     240,   163,   164,   158,   159,   160,   721,    19,   723,    29,
      40,    55,    56,    57,    58,    59,    60,    74,   620,   620,
      50,    65,    66,    40,    36,   458,    40,   158,   159,   160,
      40,   398,   163,   164,    64,   514,   515,   158,   159,   160,
      40,    40,    62,    36,    14,    15,    40,    67,    40,    61,
      40,    21,    22,   361,   294,    25,   355,   365,   357,   391,
     392,   393,   394,   395,   396,   154,   155,   156,   157,   368,
     100,    40,   334,    40,    40,   660,    40,   148,   149,   150,
     151,   152,   153,   158,   159,   160,   348,    40,    40,   101,
     254,   255,   256,   361,    40,    40,   358,   365,    40,   361,
      40,    40,   364,   365,   366,   413,    40,   361,    40,    40,
      40,   365,   714,   714,    40,   166,   166,   379,   358,    40,
      40,   361,    40,    40,   364,   365,   366,    40,   158,   159,
     160,     8,    40,    10,    11,    40,    13,    40,    40,   506,
      40,    40,   744,   744,    40,   413,   386,    40,    40,    40,
     458,   413,    40,    40,   756,   756,    40,    40,    40,   413,
     468,    40,    37,    43,   108,   108,    40,    37,    90,    17,
     478,   773,   773,   413,   159,   484,   485,    89,   484,   108,
      37,    43,     6,    25,    91,    41,    41,    53,    66,    54,
     458,    41,    41,    52,    41,    48,   458,    48,    41,    43,
     468,    41,    48,    48,   458,    41,   468,    41,    41,    48,
     478,    41,    41,    41,   468,   814,   478,    48,   458,    41,
      41,    41,   484,   485,   478,    41,   103,   489,   468,    41,
      41,    41,    41,   110,   111,    48,    41,   114,   478,   116,
      41,    48,    41,    41,   484,    41,   123,    41,   125,    41,
      41,    48,    41,    41,   856,   856,    41,    41,    48,    41,
      41,     6,    24,   158,    37,    43,    41,    41,    25,    48,
      41,    41,    39,     8,   582,    10,    11,    41,    13,   588,
      41,    16,   588,    48,   593,    20,    21,    41,   739,    49,
     617,    41,    41,    49,   745,    48,    29,    28,    40,    75,
      41,    41,    41,    38,   145,    41,    36,   145,    40,   102,
     145,    63,   620,    41,   582,    41,    41,    55,   583,    46,
     582,   583,   102,    89,    37,    49,   588,    37,   582,    41,
      37,   593,   736,   242,   413,   348,   721,   644,   647,   588,
     593,   792,   582,   583,   242,   777,    89,   179,   588,   653,
     652,    56,   620,    26,    77,   670,   665,   667,   620,   275,
     635,   623,   624,   458,   623,   714,   620,   818,   103,   712,
     840,   683,   686,   804,   496,   110,   111,   806,   498,   114,
     620,   116,   833,   623,   624,   647,   510,    -1,   123,   631,
     125,   812,   401,   401,    -1,    -1,    -1,    -1,   849,    -1,
      -1,    -1,    -1,   665,    -1,    -1,   714,   647,    -1,   717,
      -1,    -1,   721,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   683,    -1,   685,   686,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   744,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   714,    -1,   756,   717,
     712,    -1,   714,    -1,    -1,   717,    -1,    -1,    -1,   721,
     714,    -1,    -1,   717,    -1,   773,    -1,    -1,    -1,   777,
      -1,    -1,   712,    -1,   714,    -1,   744,   717,    -1,    -1,
      -1,   721,   744,    -1,    -1,   747,    -1,   749,   756,    -1,
     744,    -1,    -1,    -1,   756,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   756,    -1,   744,   773,   814,    -1,    -1,   777,
      -1,   773,    -1,    -1,    -1,   777,   756,    -1,    -1,   773,
      -1,    -1,    -1,   777,   789,   790,    -1,   789,   790,    -1,
      -1,    -1,    -1,   773,    -1,    -1,    -1,   777,    16,    -1,
      -1,    -1,   804,    -1,   806,    -1,   814,    -1,   856,   789,
     790,    -1,   814,    31,    32,    33,    34,    35,    -1,    -1,
     814,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,   814,    -1,   838,    -1,   840,    -1,
     820,   253,    -1,    31,    32,    33,    34,    35,   856,    -1,
      -1,    -1,    40,    -1,   856,    -1,    -1,    -1,    -1,    -1,
     840,    -1,   856,    51,    -1,   277,   278,   279,    -1,    -1,
     282,    -1,    -1,   285,   286,   287,   856,    -1,   290,   291,
     292,   293,    -1,   295,   296,   297,   298,   299,   300,    -1,
      -1,    -1,   304,   305,   306,    42,   308,    -1,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
      -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,   166,    -1,
      -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,   166,    -1,
      -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   426,   427,   163,   164,    -1,    -1,
      65,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,   454,    88,   456,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   107,    -1,   109,    -1,    -1,   112,   113,    -1,
     115,    -1,   117,   118,   119,    -1,   121,   122,    -1,   124,
      -1,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   521,
     522,   523,    -1,   158,   159,   160,    -1,    -1,   163,   164,
      -1,    -1,    -1,   535,    -1,    -1,   538,    -1,    -1,    -1,
      -1,   543,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    -1,    -1,   555,    -1,    -1,    -1,   559,    -1,    -1,
      -1,   563,    -1,    -1,    -1,    -1,    -1,    -1,   570,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   587,    -1,    -1,    -1,    -1,
      -1,    61,    62,    -1,    64,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    -1,    88,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,   109,
      -1,    -1,   112,   113,    -1,   115,    -1,   117,   118,   119,
      -1,   121,   122,   655,   124,   657,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,    -1,    -1,   163,   164,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
     742,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    51,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,    -1,   109,    -1,    -1,   112,   113,
      -1,   115,    -1,   117,   118,   119,    -1,   121,   122,    -1,
     124,    -1,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    -1,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,    -1,    -1,   163,
     164,    -1,    -1,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    40,   166,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,    64,
      65,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   107,    -1,   109,    -1,    -1,   112,   113,    -1,
     115,    -1,   117,   118,   119,    -1,   121,   122,    -1,   124,
      -1,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,    40,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,    -1,    -1,   163,   164,
      -1,    -1,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,    -1,   109,    -1,    -1,   112,
     113,    -1,   115,    -1,   117,   118,   119,    -1,   121,   122,
      -1,   124,    -1,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,    40,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,    -1,    -1,
     163,   164,    -1,    -1,    65,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    -1,    -1,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,   109,    -1,
      -1,   112,   113,    -1,   115,    -1,   117,   118,   119,    -1,
     121,   122,    -1,   124,    -1,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,    40,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
      -1,    -1,   163,   164,    41,    42,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,
     109,    -1,    -1,   112,   113,    -1,   115,    -1,   117,   118,
     119,    -1,   121,   122,    -1,   124,    -1,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     159,   160,    -1,    40,   163,   164,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,    -1,    -1,   163,   164,    65,    -1,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,   109,    -1,    -1,   112,   113,    -1,   115,    -1,
     117,   118,   119,    -1,   121,   122,    -1,   124,    -1,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   159,   160
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    14,   168,   169,   170,   173,   174,   176,   236,   237,
     158,     0,     8,    10,    11,    13,    16,    20,    21,    38,
     103,   110,   111,   114,   116,   123,   125,   171,   180,   184,
     193,   194,   198,   242,   243,   246,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   175,   158,   159,
     160,   447,   448,    12,   247,   247,   247,    17,    18,   185,
     186,    36,   325,    19,   163,   164,   195,   196,   396,   397,
     447,   181,   447,   247,   247,    36,   270,    36,   271,   247,
     271,    30,   172,   228,   181,   238,     3,     4,   260,   262,
     263,    15,   177,     9,   244,   245,     6,    23,   104,   105,
     268,   269,   268,   269,    19,    40,    65,    67,    68,    69,
      70,    71,    72,    73,    74,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    88,    92,    93,    94,
      95,    96,    97,    98,    99,   107,   109,   112,   113,   115,
     117,   118,   119,   121,   122,   124,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   189,   190,   191,
     192,   317,   397,   422,   424,   426,   427,   428,   429,   432,
     437,   441,   442,   443,   444,   445,   446,   447,   326,   181,
     396,   181,    22,    39,   199,   204,   205,     6,   104,   266,
     267,   266,    31,    32,    33,    34,    35,    51,   161,   162,
     166,   272,   273,   281,   331,   387,   388,   390,   391,   392,
     395,   397,   398,   437,   441,   445,   447,   449,   272,   266,
     230,   204,    49,   240,   241,   270,   270,   261,   259,   263,
     178,   268,   447,    40,    61,    62,    64,   397,   399,   400,
     403,   406,   407,   410,   411,   417,   419,   420,   421,   422,
     429,   435,   437,   441,   445,   447,    74,    40,    40,    40,
     166,   423,    40,   166,   323,    40,    40,    40,    36,   284,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,   323,    40,    40,    40,    40,    40,   166,    40,   166,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,   190,    40,    87,   165,   438,   439,   440,    40,
     166,   318,   327,   328,   331,   204,   197,   204,    23,   200,
     201,   202,   203,   447,   284,   108,   447,   108,   389,    37,
     276,    43,   282,   283,   333,    40,   332,    37,   108,    36,
     397,    90,   206,   207,   211,   173,   237,   239,    39,   106,
     264,   159,   399,   420,   420,   420,    89,   187,   188,   402,
     405,    55,    56,    57,    58,    59,    60,    65,    66,   408,
     409,   416,   418,   318,   436,   284,   399,   399,   399,   399,
     399,   399,   399,   285,   399,   399,   399,   399,   397,   399,
     399,   399,   399,   399,   399,    17,   320,   320,   399,   399,
     399,   399,   399,   399,   399,   399,   399,   399,   399,   399,
     399,   399,   399,   399,   399,   399,   399,   399,   399,   399,
     399,   399,   399,   399,   320,   447,   320,    37,    43,   329,
     330,   206,   206,   203,   266,   266,    50,   334,   345,   396,
     275,   277,   278,   273,   334,   339,   340,   387,   393,   394,
     395,   334,   266,   229,    25,    91,   208,   214,   284,    23,
     265,   447,   179,    41,   397,    41,    53,   401,    54,   404,
     410,   410,   410,   410,   410,   410,    66,   323,    61,    62,
     412,   415,   443,   444,    19,    63,   413,    41,    41,    41,
     324,    48,    48,    48,   182,   184,   286,   287,   288,   291,
     346,   387,   395,    41,    41,    48,    41,    41,    48,    41,
      41,    41,    41,    48,    19,   399,   431,   399,    41,    41,
      41,    41,    41,    41,    41,    48,    41,    41,    41,    48,
      41,    41,    41,    48,    41,    41,    41,    41,    41,    41,
      48,    41,    41,    41,   399,   399,   327,    52,   341,   344,
     394,    43,   274,     6,    41,   394,   234,    40,   212,   213,
     317,   397,   422,   215,   216,   316,   317,   421,   422,    24,
     209,   217,   447,   158,   403,   406,   323,   417,   417,   413,
     414,   419,   419,   322,   399,   399,   399,   183,    37,   290,
      43,   292,   293,   348,   347,   399,   399,   399,    41,   430,
     399,   399,   399,   399,    41,   319,   338,   343,   273,   396,
      37,    40,   166,   232,   399,   213,   216,    25,    28,    29,
     210,   223,   226,   227,    41,    48,   321,    48,    41,    41,
     204,     6,     7,    44,    45,    47,   120,   142,   228,   289,
     294,   295,   296,   298,   302,   305,   306,   309,   310,   315,
     288,   340,   357,    40,    50,    64,   100,   349,   351,   358,
     359,   360,   361,   364,   367,   369,   375,   376,   397,   447,
      41,    41,   321,   425,    49,   433,   434,    41,   425,    41,
      41,   322,    49,   337,    48,   342,   279,   233,   188,    26,
      27,   218,   219,   220,   221,   222,   316,   397,   145,   145,
     224,   227,   225,   226,   399,   399,   206,   299,   303,   297,
     307,   316,    40,   294,   274,   311,   360,    40,    50,   100,
     377,   382,   383,   385,   447,   367,   350,   363,   366,    19,
      36,    61,   101,   368,   370,   374,    41,    75,    41,    41,
      41,   335,   336,   345,   344,    36,    42,   231,   235,   397,
     437,   441,   445,   447,    41,   219,   421,    41,   172,   300,
     304,   284,   308,   399,   288,   284,    41,   380,   381,   383,
      50,   384,   447,   341,   102,   362,    63,   365,    48,   145,
     373,   386,    55,   341,   280,    41,   235,   396,   396,   284,
      89,   314,    41,   379,   356,   364,   369,   386,    37,    48,
     372,   446,   273,   301,   284,   397,    46,   312,   102,   378,
      49,   355,    37,    37,   371,   386,    37,   284,    41,   313,
     383,   351,   352,   354,    37,   284,   353,   341
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
     415,   416,   417,   418,   419,   420,   421
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  SPARQLfedParser::yyr1_[] =
  {
         0,   167,   168,   168,   169,   170,   171,   171,   171,   171,
     172,   172,   173,   174,   174,   175,   175,   176,   178,   179,
     177,   180,   181,   181,   183,   182,   184,   185,   185,   186,
     186,   187,   188,   188,   189,   190,   190,   190,   190,   190,
     190,   190,   190,   191,   191,   192,   192,   193,   194,   195,
     195,   196,   196,   197,   197,   198,   199,   200,   200,   201,
     202,   203,   204,   205,   205,   206,   207,   207,   208,   208,
     209,   209,   210,   210,   211,   212,   212,   213,   213,   213,
     213,   214,   215,   215,   216,   217,   218,   218,   219,   219,
     220,   220,   221,   222,   222,   223,   223,   224,   224,   225,
     225,   226,   227,   229,   228,   230,   230,   231,   231,   233,
     232,   232,   234,   234,   235,   235,   235,   235,   235,   235,
     236,   238,   237,   239,   239,   240,   241,   241,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   243,
     244,   245,   245,   246,   247,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   258,   259,   259,
     260,   260,   261,   261,   262,   263,   264,   265,   265,   266,
     266,   267,   267,   268,   269,   269,   269,   269,   270,   271,
     272,   273,   273,   274,   274,   275,   276,   276,   278,   279,
     280,   277,   281,   282,   283,   283,   285,   284,   286,   286,
     287,   288,   288,   289,   290,   290,   291,   292,   293,   293,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   295,
     297,   296,   299,   300,   301,   298,   303,   304,   302,   305,
     307,   308,   306,   310,   311,   309,   313,   312,   314,   314,
     315,   316,   316,   316,   317,   318,   319,   318,   320,   320,
     321,   322,   322,   323,   324,   323,   326,   325,   327,   327,
     328,   329,   330,   330,   332,   331,   333,   331,   334,   335,
     336,   336,   337,   338,   338,   339,   340,   340,   341,   342,
     343,   343,   344,   345,   345,   347,   346,   348,   346,   350,
     349,   351,   351,   353,   352,   354,   354,   355,   356,   356,
     357,   358,   359,   360,   361,   362,   363,   363,   364,   365,
     366,   366,   367,   368,   368,   369,   369,   370,   371,   371,
     372,   372,   373,   373,   374,   374,   374,   374,   375,   376,
     376,   376,   376,   377,   378,   379,   379,   380,   381,   381,
     382,   382,   383,   384,   384,   385,   385,   385,   386,   387,
     387,   389,   388,   390,   391,   391,   391,   391,   391,   392,
     392,   393,   393,   394,   394,   395,   395,   396,   396,   397,
     397,   398,   398,   398,   398,   398,   398,   399,   400,   401,
     402,   402,   403,   404,   405,   405,   406,   407,   408,   408,
     409,   409,   409,   409,   409,   409,   409,   409,   410,   411,
     412,   412,   413,   413,   414,   414,   415,   415,   415,   416,
     416,   417,   418,   418,   419,   419,   419,   419,   420,   420,
     420,   420,   420,   420,   420,   420,   421,   422,   422,   422,
     422,   422,   422,   422,   422,   422,   422,   422,   422,   422,
     422,   422,   422,   422,   422,   422,   422,   422,   422,   422,
     422,   422,   422,   422,   422,   422,   422,   422,   422,   422,
     422,   422,   422,   422,   422,   422,   422,   422,   422,   422,
     422,   422,   422,   422,   422,   422,   423,   423,   424,   425,
     425,   426,   427,   428,   429,   429,   430,   429,   431,   431,
     432,   432,   432,   432,   432,   433,   434,   434,   435,   436,
     436,   437,   438,   439,   439,   440,   440,   441,   441,   441,
     442,   442,   442,   443,   443,   443,   444,   444,   444,   445,
     445,   446,   446,   446,   446,   447,   447,   448,   448,   449,
     449
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     3,     0,     0,     0,     6,     0,     0,     5,     6,
       0,     0,     4,     0,     0,     4,     0,     3,     0,     2,
       2,     1,     1,     1,     2,     1,     0,     6,     0,     1,
       2,     0,     2,     1,     0,     5,     0,     4,     0,     1,
       2,     2,     0,     1,     0,     3,     0,     3,     3,     2,
       0,     1,     2,     0,     2,     1,     0,     1,     2,     2,
       0,     2,     1,     1,     1,     0,     3,     0,     3,     0,
       4,     1,     1,     0,     3,     0,     1,     2,     0,     2,
       1,     1,     1,     1,     2,     2,     0,     2,     2,     2,
       0,     2,     2,     0,     1,     1,     2,     1,     1,     2,
       2,     1,     2,     3,     1,     1,     1,     2,     1,     1,
       1,     2,     3,     1,     2,     0,     2,     2,     0,     1,
       1,     3,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     0,     4,     4,     1,     1,     1,     1,     1,     0,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       0,     2,     2,     2,     0,     2,     1,     2,     0,     1,
       2,     2,     2,     2,     2,     2,     2,     3,     1,     2,
       1,     1,     2,     2,     0,     1,     2,     2,     2,     0,
       2,     2,     0,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     4,     4,     6,
       4,     4,     4,     4,     2,     2,     4,     4,     4,     4,
       2,     1,     4,     4,     4,     4,     6,     6,     6,     4,
       4,     4,     4,     4,     4,     4,     2,     4,     4,     4,
       4,     4,     4,     2,     8,     6,     6,     6,     4,     4,
       4,     4,     4,     1,     1,     1,     3,     1,     7,     0,
       1,     7,     2,     3,     5,     5,     0,     7,     1,     1,
       1,     1,     1,     1,     1,     4,     0,     1,     2,     0,
       1,     2,     2,     1,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
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
  "IT_SHA224", "IT_STRENDS", "IT_STRLEN", "IT_SHA1", "IT_MONTH",
  "IT_PRINT", "IT_true", "IT_false", "INTEGER", "DECIMAL", "DOUBLE",
  "INTEGER_POSITIVE", "DECIMAL_POSITIVE", "DOUBLE_POSITIVE",
  "INTEGER_NEGATIVE", "DECIMAL_NEGATIVE", "DOUBLE_NEGATIVE",
  "STRING_LITERAL1", "STRING_LITERAL_LONG1", "STRING_LITERAL2",
  "STRING_LITERAL_LONG2", "IRI_REF", "PNAME_NS", "PNAME_LN",
  "BLANK_NODE_LABEL", "ANON", "VAR1", "VAR2", "LANGTAG", "NIL", "$accept",
  "Top", "QueryUnit", "Query",
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
  "Print", "OptionalGraphPattern", "@11", "GraphGraphPattern", "@12",
  "@13", "@14", "ServiceGraphPattern", "@15", "@16", "Bind",
  "MinusGraphPattern", "@17", "@18", "GroupOrUnionGraphPattern", "@19",
  "@20", "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@21",
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
       168,     0,    -1,   169,    -1,   236,    -1,   170,    -1,   173,
     171,   172,    -1,   180,    -1,   193,    -1,   194,    -1,   198,
      -1,    -1,   228,    -1,   174,   175,    -1,    -1,   176,    -1,
      -1,   175,   177,    -1,    14,   158,    -1,    -1,    -1,    15,
     178,   159,   179,   158,    -1,   184,   181,   204,   206,    -1,
      -1,   181,   199,    -1,    -1,   184,   183,   204,   206,   172,
      -1,    16,   186,   192,    -1,    17,    -1,    18,    -1,    -1,
     185,    -1,    89,   397,    -1,    -1,   187,    -1,    40,   399,
     188,    41,    -1,   397,    -1,   429,    -1,   422,    -1,   317,
      -1,   437,    -1,   441,    -1,   445,    -1,   189,    -1,   190,
      -1,   191,   190,    -1,   191,    -1,    19,    -1,    20,   325,
     181,   204,   206,    -1,    21,   196,   181,   197,   206,    -1,
     396,    -1,   195,   396,    -1,   195,    -1,    19,    -1,    -1,
     204,    -1,    38,   181,   204,    -1,    22,   200,    -1,   201,
      -1,   202,    -1,   203,    -1,    23,   203,    -1,   447,    -1,
     205,   284,    -1,    -1,    39,    -1,   207,   208,   209,   210,
      -1,    -1,   211,    -1,    -1,   214,    -1,    -1,   217,    -1,
      -1,   223,    -1,    90,    25,   212,    -1,   213,    -1,   212,
     213,    -1,   422,    -1,   317,    -1,    40,   399,   188,    41,
      -1,   397,    -1,    91,   215,    -1,   216,    -1,   215,   216,
      -1,   316,    -1,    24,    25,   218,    -1,   219,    -1,   218,
     219,    -1,   221,    -1,   222,    -1,    26,    -1,    27,    -1,
     220,   421,    -1,   316,    -1,   397,    -1,   226,   224,    -1,
     227,   225,    -1,    -1,   227,    -1,    -1,   226,    -1,    28,
     145,    -1,    29,   145,    -1,    -1,    30,   230,    36,   229,
     234,    37,    -1,    -1,   230,   397,    -1,   235,    -1,   231,
     235,    -1,    -1,    40,   233,   231,    41,    -1,   166,    -1,
      -1,   234,   232,    -1,   447,    -1,   437,    -1,   441,    -1,
     445,    -1,    42,    -1,   397,    -1,   237,    -1,    -1,   173,
     242,   238,   241,    -1,    -1,   237,    -1,    49,   239,    -1,
      -1,   240,    -1,   243,    -1,   246,    -1,   248,    -1,   250,
      -1,   251,    -1,   252,    -1,   249,    -1,   253,    -1,   254,
      -1,   255,    -1,   256,    -1,     8,   447,   245,    -1,     9,
     268,    -1,    -1,   244,    -1,    10,   247,   269,    -1,    -1,
      12,    -1,    13,   247,   269,    -1,    11,   247,   268,    -1,
     110,   247,   266,   108,   266,    -1,   123,   247,   266,   108,
     266,    -1,   111,   247,   266,   108,   266,    -1,   125,   271,
      -1,   116,   271,    -1,   114,   270,    -1,   258,   260,   261,
      39,   284,    -1,   103,   447,    -1,    -1,   257,    -1,    -1,
     263,    -1,   262,   259,    -1,   263,    -1,    -1,   261,   264,
      -1,     3,   270,    -1,     4,   270,    -1,   106,   265,    -1,
     447,    -1,    23,   447,    -1,   104,    -1,   267,   447,    -1,
      -1,     6,    -1,     6,   447,    -1,   268,    -1,   104,    -1,
      23,    -1,   105,    -1,    36,   272,    37,    -1,    36,   272,
      37,    -1,   273,   276,    -1,    -1,   281,    -1,    -1,    43,
      -1,   277,   274,   273,    -1,    -1,   276,   275,    -1,    -1,
      -1,    -1,   278,     6,   396,   279,    36,   280,   273,    37,
      -1,   331,   283,    -1,    43,   273,    -1,    -1,   282,    -1,
      -1,    36,   285,   286,    37,    -1,   182,    -1,   287,    -1,
     288,   290,    -1,    -1,   291,    -1,   294,   274,   288,    -1,
      -1,   290,   289,    -1,   346,   293,    -1,    43,   288,    -1,
      -1,   292,    -1,   309,    -1,   296,    -1,   306,    -1,   298,
      -1,   302,    -1,   315,    -1,   305,    -1,   228,    -1,   295,
      -1,   142,   294,    -1,    -1,    44,   297,   284,    -1,    -1,
      -1,    -1,     6,   299,   300,   396,   301,   284,    -1,    -1,
      -1,     7,   303,   304,   396,   284,    -1,   120,    40,   399,
      89,   397,    41,    -1,    -1,    -1,    45,   307,   308,   284,
      -1,    -1,    -1,   310,   311,   284,   314,    -1,    -1,    46,
     313,   284,    -1,    -1,   314,   312,    -1,    47,   316,    -1,
     421,    -1,   422,    -1,   317,    -1,   447,   318,    -1,   166,
      -1,    -1,    40,   320,   399,   319,   322,    41,    -1,    -1,
      17,    -1,    48,   399,    -1,    -1,   322,   321,    -1,   166,
      -1,    -1,    40,   399,   324,   322,    41,    -1,    -1,    36,
     326,   327,    37,    -1,    -1,   328,    -1,   331,   330,    -1,
      43,   327,    -1,    -1,   329,    -1,    -1,   395,   332,   334,
      -1,    -1,   387,   333,   339,    -1,   345,   341,   338,    -1,
     345,   341,    -1,    -1,   335,    -1,    49,   336,    -1,    -1,
     338,   337,    -1,   340,    -1,    -1,   334,    -1,   344,   343,
      -1,    48,   344,    -1,    -1,   343,   342,    -1,   394,    -1,
     396,    -1,    50,    -1,    -1,   395,   347,   349,    -1,    -1,
     387,   348,   357,    -1,    -1,   351,   350,   341,   356,    -1,
     358,    -1,   359,    -1,    -1,   351,   353,   341,    -1,    -1,
     352,    -1,    49,   354,    -1,    -1,   356,   355,    -1,   340,
      -1,   360,    -1,   397,    -1,   361,    -1,   364,   363,    -1,
     102,   364,    -1,    -1,   363,   362,    -1,   369,   366,    -1,
      63,   369,    -1,    -1,   366,   365,    -1,   375,   368,    -1,
      -1,   370,    -1,   367,    -1,   100,   367,    -1,   374,    -1,
      37,    -1,   386,    37,    -1,    48,   371,    -1,    37,    -1,
     386,   372,    -1,    48,   386,    37,    -1,    19,    -1,   101,
      -1,    61,    -1,    36,   373,    -1,   376,    -1,   447,    -1,
      50,    -1,    64,   377,    -1,    40,   360,    41,    -1,   382,
      -1,   102,   383,    -1,    -1,   379,   378,    -1,   383,   379,
      -1,    -1,   380,    -1,   383,    -1,    40,   381,    41,    -1,
     385,    -1,   447,    -1,    50,    -1,   447,    -1,    50,    -1,
     100,   384,    -1,   145,    -1,   390,    -1,   388,    -1,    -1,
      51,   389,   334,    52,    -1,   392,    40,   393,    41,    -1,
      31,    -1,    32,    -1,    33,    -1,    34,    -1,    35,    -1,
      -1,   391,    -1,   394,    -1,   393,   394,    -1,   395,    -1,
     387,    -1,   397,    -1,   398,    -1,   397,    -1,   447,    -1,
     163,    -1,   164,    -1,   447,    -1,   437,    -1,   441,    -1,
     445,    -1,   449,    -1,   166,    -1,   400,    -1,   403,   402,
      -1,    53,   403,    -1,    -1,   402,   401,    -1,   406,   405,
      -1,    54,   406,    -1,    -1,   405,   404,    -1,   407,    -1,
     410,   408,    -1,    -1,   409,    -1,    55,   410,    -1,    56,
     410,    -1,    57,   410,    -1,    58,   410,    -1,    59,   410,
      -1,    60,   410,    -1,    66,   323,    -1,    65,    66,   323,
      -1,   411,    -1,   417,   416,    -1,   443,    -1,   444,    -1,
      19,   419,    -1,    63,   419,    -1,    -1,   413,    -1,    61,
     417,    -1,    62,   417,    -1,   412,   414,    -1,    -1,   416,
     415,    -1,   419,   418,    -1,    -1,   418,   413,    -1,    64,
     420,    -1,    61,   420,    -1,    62,   420,    -1,   420,    -1,
     421,    -1,   422,    -1,   435,    -1,   437,    -1,   441,    -1,
     445,    -1,   397,    -1,   429,    -1,    40,   399,    41,    -1,
      76,    40,   399,    41,    -1,    77,    40,   399,    41,    -1,
      78,    40,   399,    48,   399,    41,    -1,    79,    40,   399,
      41,    -1,    80,    40,   397,    41,    -1,    67,    40,   399,
      41,    -1,    68,    40,   399,    41,    -1,    69,   423,    -1,
     112,   166,    -1,   135,    40,   399,    41,    -1,   132,    40,
     399,    41,    -1,   124,    40,   399,    41,    -1,   118,    40,
     399,    41,    -1,    88,   323,    -1,   426,    -1,   139,    40,
     399,    41,    -1,   136,    40,   399,    41,    -1,   134,    40,
     399,    41,    -1,   130,    40,   399,    41,    -1,   121,    40,
     399,    48,   399,    41,    -1,   131,    40,   399,    48,   399,
      41,    -1,   138,    40,   399,    48,   399,    41,    -1,   109,
      40,   399,    41,    -1,   141,    40,   399,    41,    -1,   133,
      40,   399,    41,    -1,   129,    40,   399,    41,    -1,   126,
      40,   399,    41,    -1,   122,    40,   399,    41,    -1,   117,
      40,   399,    41,    -1,   115,   166,    -1,   107,    40,   399,
      41,    -1,   140,    40,   399,    41,    -1,   137,    40,   399,
      41,    -1,   128,    40,   399,    41,    -1,   119,    40,   399,
      41,    -1,   113,    40,   399,    41,    -1,    70,   323,    -1,
      71,    40,   399,    48,   399,    48,   399,    41,    -1,    72,
      40,   399,    48,   399,    41,    -1,    73,    40,   399,    48,
     399,    41,    -1,    81,    40,   399,    48,   399,    41,    -1,
      82,    40,   399,    41,    -1,    83,    40,   399,    41,    -1,
      84,    40,   399,    41,    -1,    85,    40,   399,    41,    -1,
      99,    40,   399,    41,    -1,   424,    -1,   427,    -1,   428,
      -1,    40,   399,    41,    -1,   166,    -1,    86,    40,   399,
      48,   399,   425,    41,    -1,    -1,   321,    -1,   127,    40,
     399,    48,   399,   425,    41,    -1,    74,   284,    -1,    65,
      74,   284,    -1,    92,    40,   320,   431,    41,    -1,   432,
      40,   320,   399,    41,    -1,    -1,    97,    40,   320,   399,
     430,   434,    41,    -1,    19,    -1,   399,    -1,    93,    -1,
      94,    -1,    95,    -1,    96,    -1,    98,    -1,    49,    75,
      55,   446,    -1,    -1,   433,    -1,   447,   436,    -1,    -1,
     318,    -1,   446,   440,    -1,    87,   447,    -1,   165,    -1,
     438,    -1,    -1,   439,    -1,   442,    -1,   443,    -1,   444,
      -1,   145,    -1,   146,    -1,   147,    -1,   148,    -1,   149,
      -1,   150,    -1,   151,    -1,   152,    -1,   153,    -1,   143,
      -1,   144,    -1,   154,    -1,   156,    -1,   155,    -1,   157,
      -1,   158,    -1,   448,    -1,   160,    -1,   159,    -1,   161,
      -1,   162,    -1
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
     513,   515,   517,   519,   521,   523,   525,   527,   529,   531,
     534,   535,   539,   540,   541,   542,   549,   550,   551,   557,
     564,   565,   566,   571,   572,   573,   578,   579,   583,   584,
     587,   590,   592,   594,   596,   599,   601,   602,   609,   610,
     612,   615,   616,   619,   621,   622,   628,   629,   634,   635,
     637,   640,   643,   644,   646,   647,   651,   652,   656,   660,
     663,   664,   666,   669,   670,   673,   675,   676,   678,   681,
     684,   685,   688,   690,   692,   694,   695,   699,   700,   704,
     705,   710,   712,   714,   715,   719,   720,   722,   725,   726,
     729,   731,   733,   735,   737,   740,   743,   744,   747,   750,
     753,   754,   757,   760,   761,   763,   765,   768,   770,   772,
     775,   778,   780,   783,   787,   789,   791,   793,   796,   798,
     800,   802,   805,   809,   811,   814,   815,   818,   821,   822,
     824,   826,   830,   832,   834,   836,   838,   840,   843,   845,
     847,   849,   850,   855,   860,   862,   864,   866,   868,   870,
     871,   873,   875,   878,   880,   882,   884,   886,   888,   890,
     892,   894,   896,   898,   900,   902,   904,   906,   908,   911,
     914,   915,   918,   921,   924,   925,   928,   930,   933,   934,
     936,   939,   942,   945,   948,   951,   954,   957,   961,   963,
     966,   968,   970,   973,   976,   977,   979,   982,   985,   988,
     989,   992,   995,   996,   999,  1002,  1005,  1008,  1010,  1012,
    1014,  1016,  1018,  1020,  1022,  1024,  1026,  1030,  1035,  1040,
    1047,  1052,  1057,  1062,  1067,  1070,  1073,  1078,  1083,  1088,
    1093,  1096,  1098,  1103,  1108,  1113,  1118,  1125,  1132,  1139,
    1144,  1149,  1154,  1159,  1164,  1169,  1174,  1177,  1182,  1187,
    1192,  1197,  1202,  1207,  1210,  1219,  1226,  1233,  1240,  1245,
    1250,  1255,  1260,  1265,  1267,  1269,  1271,  1275,  1277,  1285,
    1286,  1288,  1296,  1299,  1303,  1309,  1315,  1316,  1324,  1326,
    1328,  1330,  1332,  1334,  1336,  1338,  1343,  1344,  1346,  1349,
    1350,  1352,  1355,  1358,  1360,  1362,  1363,  1365,  1367,  1369,
    1371,  1373,  1375,  1377,  1379,  1381,  1383,  1385,  1387,  1389,
    1391,  1393,  1395,  1397,  1399,  1401,  1403,  1405,  1407,  1409,
    1411
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   402,   402,   405,   411,   416,   425,   426,   427,   428,
     433,   436,   441,   445,   447,   451,   453,   457,   463,   465,
     463,   475,   483,   486,   494,   494,   505,   513,   516,   523,
     526,   531,   538,   541,   546,   553,   556,   559,   562,   565,
     568,   571,   575,   580,   583,   591,   594,   601,   610,   618,
     621,   629,   632,   639,   642,   647,   655,   662,   663,   667,
     673,   679,   686,   693,   695,   700,   707,   710,   715,   718,
     723,   726,   731,   735,   739,   746,   749,   756,   759,   762,
     765,   771,   777,   780,   787,   792,   799,   803,   811,   813,
     821,   824,   832,   840,   841,   848,   852,   860,   863,   868,
     871,   875,   881,   888,   888,   898,   901,   908,   916,   922,
     922,   928,   935,   938,   945,   948,   951,   954,   957,   960,
     966,   970,   970,   979,   981,   985,   988,   990,   994,   995,
     996,   997,   998,   999,  1000,  1001,  1002,  1003,  1004,  1008,
    1015,  1022,  1025,  1029,  1035,  1038,  1044,  1050,  1056,  1062,
    1068,  1074,  1082,  1090,  1098,  1107,  1113,  1116,  1120,  1123,
    1127,  1131,  1137,  1139,  1145,  1152,  1159,  1165,  1168,  1174,
    1177,  1182,  1184,  1188,  1194,  1197,  1200,  1203,  1210,  1214,
    1218,  1221,  1223,  1227,  1229,  1233,  1236,  1238,  1243,  1247,
    1250,  1243,  1261,  1265,  1268,  1270,  1275,  1275,  1287,  1288,
    1293,  1297,  1299,  1309,  1313,  1316,  1332,  1337,  1341,  1344,
    1348,  1349,  1350,  1351,  1352,  1353,  1354,  1355,  1358,  1362,
    1368,  1368,  1383,  1386,  1388,  1383,  1399,  1402,  1399,  1411,
    1417,  1420,  1417,  1430,  1433,  1430,  1443,  1443,  1457,  1459,
    1463,  1474,  1475,  1476,  1480,  1488,  1492,  1492,  1501,  1504,
    1511,  1517,  1519,  1533,  1536,  1536,  1546,  1546,  1554,  1556,
    1561,  1566,  1570,  1572,  1576,  1576,  1579,  1579,  1586,  1591,
    1595,  1597,  1602,  1606,  1608,  1613,  1617,  1619,  1624,  1629,
    1633,  1635,  1639,  1646,  1650,  1658,  1658,  1661,  1661,  1667,
    1667,  1673,  1674,  1678,  1678,  1683,  1685,  1689,  1692,  1694,
    1698,  1702,  1706,  1712,  1716,  1720,  1723,  1725,  1729,  1733,
    1738,  1740,  1746,  1749,  1751,  1757,  1758,  1764,  1768,  1769,
    1773,  1774,  1778,  1779,  1783,  1784,  1785,  1786,  1790,  1794,
    1797,  1800,  1803,  1809,  1813,  1816,  1818,  1822,  1825,  1827,
    1831,  1832,  1836,  1840,  1841,  1845,  1846,  1847,  1851,  1856,
    1857,  1861,  1861,  1874,  1899,  1902,  1905,  1908,  1911,  1918,
    1921,  1926,  1930,  1937,  1938,  1942,  1945,  1949,  1952,  1958,
    1959,  1963,  1966,  1969,  1972,  1975,  1976,  1982,  1987,  1996,
    2003,  2006,  2014,  2023,  2030,  2033,  2040,  2045,  2056,  2059,
    2063,  2066,  2069,  2072,  2075,  2078,  2081,  2084,  2090,  2095,
    2104,  2107,  2114,  2117,  2124,  2127,  2132,  2135,  2139,  2153,
    2156,  2164,  2173,  2176,  2183,  2186,  2189,  2192,  2196,  2197,
    2198,  2199,  2202,  2205,  2208,  2211,  2215,  2221,  2224,  2227,
    2230,  2233,  2236,  2239,  2243,  2246,  2249,  2252,  2255,  2258,
    2261,  2264,  2265,  2268,  2271,  2274,  2277,  2280,  2283,  2286,
    2289,  2292,  2295,  2298,  2301,  2304,  2307,  2310,  2313,  2316,
    2319,  2322,  2325,  2328,  2332,  2335,  2338,  2341,  2344,  2347,
    2350,  2353,  2356,  2359,  2360,  2361,  2367,  2370,  2377,  2384,
    2387,  2391,  2397,  2404,  2411,  2414,  2418,  2418,  2430,  2434,
    2438,  2441,  2444,  2447,  2450,  2456,  2462,  2465,  2469,  2479,
    2482,  2487,  2495,  2502,  2506,  2514,  2518,  2522,  2523,  2524,
    2528,  2529,  2530,  2534,  2535,  2536,  2540,  2541,  2542,  2546,
    2547,  2551,  2552,  2553,  2554,  2558,  2559,  2563,  2564,  2568,
    2569
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
     165,   166
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SPARQLfedParser::yyeof_ = 0;
  const int SPARQLfedParser::yylast_ = 1993;
  const int SPARQLfedParser::yynnts_ = 283;
  const int SPARQLfedParser::yyempty_ = -2;
  const int SPARQLfedParser::yyfinal_ = 11;
  const int SPARQLfedParser::yyterror_ = 1;
  const int SPARQLfedParser::yyerrcode_ = 256;
  const int SPARQLfedParser::yyntokens_ = 167;

  const unsigned int SPARQLfedParser::yyuser_token_number_max_ = 421;
  const SPARQLfedParser::token_number_type SPARQLfedParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 5077 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 2575 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


