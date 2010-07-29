
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
#line 43 "lib/MapSetParser/MapSetParser.cpp"


#include "MapSetParser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 226 "lib/MapSetParser/MapSetParser.ypp"

#include "../MapSetScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 356 "lib/MapSetParser/MapSetParser.ypp"

#include "../MapSetScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lexWrapper


/* Line 317 of lalr1.cc  */
#line 68 "lib/MapSetParser/MapSetParser.cpp"

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
#line 137 "lib/MapSetParser/MapSetParser.cpp"
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  MapSetParser::yytnamerr_ (const char *yystr)
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
  MapSetParser::MapSetParser (class MapSetDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  MapSetParser::~MapSetParser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  MapSetParser::yy_symbol_value_print_ (int yytype,
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
  MapSetParser::yy_symbol_print_ (int yytype,
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
  MapSetParser::yydestruct_ (const char* yymsg,
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
  MapSetParser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  MapSetParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  MapSetParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  MapSetParser::debug_level_type
  MapSetParser::debug_level () const
  {
    return yydebug_;
  }

  void
  MapSetParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  MapSetParser::parse ()
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
#line 37 "lib/MapSetParser/MapSetParser.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 321 "lib/MapSetParser/MapSetParser.cpp"

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
#line 371 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root = new MapSet();
	driver.root->sharedVars = MapSet::e_PROMISCUOUS;
      }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 389 "lib/MapSetParser/MapSetParser.ypp"
    {
#if REGEX_LIB == SWOb_DISABLED
      throw std::string("not compiled with REGEX_LIB: can't map ") + (yysemantic_stack_[(4) - (2)].p_Variable)->toString() + " from " + (yysemantic_stack_[(4) - (3)].p_RDFLiteral)->toString() + " to " + (yysemantic_stack_[(4) - (4)].p_RDFLiteral)->toString() + ".";
#else /* ! REGEX_LIB == SWOb_DISABLED */
#if NotYet // @@
      driver.root->rewriteVars.push_back(POSmap((yysemantic_stack_[(4) - (2)].p_Variable), (yysemantic_stack_[(4) - (3)].p_RDFLiteral)->getLexicalValue(), (yysemantic_stack_[(4) - (4)].p_RDFLiteral)->getLexicalValue()));
#endif /* NotYet */
#endif /* ! REGEX_LIB == SWOb_DISABLED */
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 398 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->server = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 401 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->user = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 404 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->password = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 407 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->database = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 410 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->stemURI = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 413 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->primaryKey = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 416 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.sharedVarsSet = true;
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 419 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.lastRuleTermSet = false;
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 425 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_PROMISCUOUS;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 428 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_VARNAMES;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 431 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_DRACONIAN;
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 437 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = NULL;
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 444 "lib/MapSetParser/MapSetParser.ypp"
    {
	RuleTerm nextRuleTerm = RuleTerm((yysemantic_stack_[(4) - (2)].p_POS), (yysemantic_stack_[(4) - (4)].p_POS));
	if (driver.lastRuleTermSet)
	    static_cast<MapSet*>(driver.root)->nodeShare.addIntersection(driver.lastRuleTerm, nextRuleTerm);
	driver.lastRuleTerm = nextRuleTerm;
	driver.lastRuleTermSet = true;
	if (!driver.sharedVarsSet)
	    driver.root->sharedVars = MapSet::e_DRACONIAN;
    }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 478 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 484 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 486 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 488 "lib/MapSetParser/MapSetParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 496 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 498 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 500 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(5) - (1)].p_Project).distinctness, (yysemantic_stack_[(5) - (1)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier))));
      }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 508 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 516 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 519 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 526 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 534 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 541 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 549 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 556 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 559 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 562 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 565 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 568 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new POSExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 571 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new POSExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 574 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new POSExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 583 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 586 "lib/MapSetParser/MapSetParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 594 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 597 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 604 "lib/MapSetParser/MapSetParser.ypp"
    {
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	Construct* constr = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(6) - (3)].p_BasicGraphPattern), (yysemantic_stack_[(6) - (4)].p_DatasetClauses), (yysemantic_stack_[(6) - (5)].p_WhereClause), (yysemantic_stack_[(6) - (6)].p_SolutionModifier));
	driver.root->maps.push_back(LabeledConstruct((yysemantic_stack_[(6) - (1)].p_POS), constr));
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 613 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 616 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 624 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 636 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_POS), driver.posFactory);
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 642 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_POS), driver.posFactory);
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 648 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 655 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp ? driver.curOp : new DefaultGraphPattern(), (yysemantic_stack_[(3) - (3)].p_BindingsClause));
	driver.curOp = NULL;
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 668 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 675 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = NULL;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 683 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 691 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 699 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 707 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 714 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 717 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 724 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 727 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 730 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 733 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 739 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 745 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 748 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 760 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 767 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 771 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 781 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 789 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 792 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 800 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 809 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 816 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 820 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 828 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 836 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 843 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 849 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 862 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POSList) = new POSList;
	(yyval.p_POSList)->push_back((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 866 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_POSList) = (yysemantic_stack_[(2) - (1)].p_POSList);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 873 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_POS));
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 876 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_POS));
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 882 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding = new Binding();
      }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 884 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BindingValue) = driver.curBinding;
	  driver.curBinding = NULL;
      }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 891 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 894 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBindingsClause->push_back((yysemantic_stack_[(2) - (2)].p_BindingValue));
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 901 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBindingsClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_POSList));
      }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 903 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BindingsClause) = driver.curBindingsClause;
	  driver.curBindingsClause = NULL;
      }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 910 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BindingsClause) = NULL;
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 917 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 920 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 923 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 926 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 929 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = driver.getNULL();
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 932 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 939 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 942 "lib/MapSetParser/MapSetParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1016 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1018 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.curFilter;
      }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1020 "lib/MapSetParser/MapSetParser.ypp"
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

  case 153:

/* Line 678 of lalr1.cc  */
#line 1032 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1034 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1036 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_POS) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_POS);
      }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1039 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_POS), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_POS);
      }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1047 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1049 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1051 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(5) - (4)].p_POS), driver.curOp, driver.posFactory, false));
      }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1058 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1060 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 1062 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.curOp));
      }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 1070 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 1073 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1075 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1083 "lib/MapSetParser/MapSetParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1088 "lib/MapSetParser/MapSetParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1103 "lib/MapSetParser/MapSetParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    if (driver.curOp == NULL)
		driver.ensureBasicGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1120 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 1128 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 1132 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 1134 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = NULL;
      }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 1141 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 1144 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 1151 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 1159 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 1166 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_DistExprPair).distinctness = (yysemantic_stack_[(4) - (2)].p_distinctness);
	  (yyval.p_DistExprPair).p_Expression = (yysemantic_stack_[(4) - (3)].p_Expression);
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 1177 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 1180 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 1182 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 1190 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 1192 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1220 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1223 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_POS);
    }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 1283 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.posFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_POS)));
    }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 1290 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_POS);
	driver.curPredicate = (yyval.p_POS);
    }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 1294 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_POS);
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 1306 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 1310 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_POS) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 1319 "lib/MapSetParser/MapSetParser.ypp"
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

  case 222:

/* Line 678 of lalr1.cc  */
#line 1344 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 1347 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 1350 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 1353 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 1356 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 1363 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 1371 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POSs) = new ProductionVector<const POS*>();
	(yyval.p_POSs)->push_back((yysemantic_stack_[(1) - (1)].p_POS));
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 1375 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_POSs)->push_back((yysemantic_stack_[(2) - (2)].p_POS));
	(yyval.p_POSs) = (yysemantic_stack_[(2) - (1)].p_POSs);
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 1387 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 1394 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 1397 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 1408 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 1411 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 1414 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 1417 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 1421 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_POS) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 1432 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 1441 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 1448 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 1451 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 1459 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 1468 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 1475 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 1478 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 1490 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_GeneralComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_GeneralComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_GeneralComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 1501 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 1504 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 1507 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 1510 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 1513 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 1516 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 1519 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 1522 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 1529 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 1541 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 1550 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 1553 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 1560 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 1563 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 1570 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 1578 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 1581 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 1585 "lib/MapSetParser/MapSetParser.ypp"
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

  case 277:

/* Line 678 of lalr1.cc  */
#line 1599 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 1602 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 1610 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 1619 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 1622 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 1629 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 1632 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 1635 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 1645 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 1648 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 1651 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 1654 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new POSExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 1661 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 1667 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-str"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 1670 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-lang"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 1673 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-langMatches"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 1676 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-datatype"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 1679 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-bound"), new POSExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 1682 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-iri"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 1685 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-iri"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 1689 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-bnode"), (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 1692 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-coalesce"), $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 1696 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-if"), (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 1699 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-strlang"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 1702 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-strdt"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 1705 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sameTerm"), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 1708 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 1711 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isIRI"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 1714 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isBlank"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 1717 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-isLiteral"), (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 1728 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 1731 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 1738 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-regex"), (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 1745 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 1752 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-exists"), driver.curOp, NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 1759 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-exists"), driver.curOp, NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 1766 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-count"), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 1769 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sum"), (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 1772 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-min"), (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 1775 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-max"), (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 1778 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-avg"), (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 1781 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-sample"), (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 1785 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 1787 "lib/MapSetParser/MapSetParser.ypp"
    {
	  // x = new ArgList($2, driver.curExprList);
	  delete driver.curExprList;
	  driver.curExprList = NULL;
	  w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // $$ = new FunctionCallExpression(new AggregateCall(driver.getURI("http://www.w3.org/TR/rdf-sparql-query/#func-group-concat"), $3, $4.p_Expression, $4.separator));
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 1797 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 1804 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 1810 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 1817 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new POSExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 1827 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 1835 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 1843 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 1850 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 1854 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 1862 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 2676 "lib/MapSetParser/MapSetParser.cpp"
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
  MapSetParser::yysyntax_error_ (int yystate, int tok)
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
  const short int MapSetParser::yypact_ninf_ = -443;
  const short int
  MapSetParser::yypact_[] =
  {
      -443,    24,    13,  -443,   -80,  -443,  -443,  -443,  -443,   332,
      25,   -33,    50,    50,    50,    50,   -35,    50,    54,     8,
     355,  -443,  -443,  -443,  -443,  -443,    50,  -443,  -443,  -443,
    -443,  -443,   -88,  -443,  -443,  -443,  -443,  -443,  -443,  -443,
    -443,  -443,  -443,  -443,  -443,  -443,  1206,  -443,     8,  -443,
    -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,
    -443,  -443,  -443,    37,  -443,  -443,  -443,  -443,  -443,  -443,
    -443,  -443,  -443,  -443,   -54,    50,   -35,  -443,  -443,  -443,
    -443,    53,  -443,    67,  -443,  -443,  -443,   858,  -443,  -443,
      14,  -443,  -443,  -443,   783,     4,  -443,  -443,  -443,  -443,
    -443,  -443,  -443,    85,  -443,    91,  -443,  -443,  -443,  -443,
      97,  -443,     6,  -443,  -443,    49,   105,    93,  -443,   783,
    -443,  -443,    93,   905,    93,   -35,  -443,  -443,  -443,  -443,
    -443,   122,  -443,    82,  -443,  -443,   139,  -443,   131,   905,
    -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,   814,  -443,
    -443,  -443,  -443,   914,  1217,   162,  -443,   662,   -33,  -443,
    -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,   986,   148,
     150,   -25,   -16,   156,   158,   159,   105,   105,   160,   163,
     165,   166,   170,   174,   178,   179,   182,   183,   184,   914,
    -443,  -443,  -443,  -443,  -443,  -443,  -443,    -8,   986,  1217,
    -443,  -443,  -443,  -443,  -443,   176,    66,  -443,   112,  -443,
    -443,   187,  -443,  -443,  -443,   185,   -20,  -443,   181,   186,
    1063,  1063,  1063,   192,   196,   196,   196,   196,   197,   196,
    -443,   138,  -443,  -443,  -443,  -443,   248,  -443,  -443,  -443,
    -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,    -8,   986,
     986,   986,  -443,  -443,   986,  -443,  -443,  -443,   986,   986,
     986,  -443,  -443,   986,   986,   986,   986,   -33,   986,   986,
     986,   986,   986,   986,  -443,   220,  -443,  -443,   198,  -443,
     758,   145,   149,  -443,  -443,   219,   222,  -443,  -443,  -443,
     637,  -443,  -443,    88,   783,  -443,  -443,  -443,  -443,    93,
    -443,   905,  -443,  -443,  -443,  -443,   220,   220,  -443,  -443,
    -443,  -443,   220,  -443,   -33,  -443,   215,   208,   216,   986,
     986,   986,   986,   986,   986,   -16,   -16,  -443,  -443,   -36,
       0,  -443,  -443,   228,   238,   240,  -443,   235,   242,   244,
     245,   247,   250,   258,   259,   253,   268,   269,   270,   274,
     271,  -443,   986,  -443,  -443,  -443,   758,  -443,   277,  -443,
    -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,
     986,  -443,  -443,  1140,  -443,  -443,  -443,  -443,  -443,  -443,
    -443,  -443,   279,  -443,  -443,  -443,  -443,  1217,   278,  -443,
    -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,
    -443,  -443,   905,  -443,   540,   986,   986,  -443,  -443,   986,
    -443,   986,  -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,
    -443,   986,   986,     0,  -443,  -443,  -443,   986,   986,  -443,
    -443,  -443,  -443,  -443,   986,   986,   986,  -443,  -443,   986,
    -443,  -443,   986,  -443,  -443,  -443,  -443,   986,  -443,  -443,
    -443,   138,  -443,    49,  -443,  -443,  -443,  -443,  -443,  -443,
     783,   105,    36,  -443,  -443,  -443,   282,   286,  -443,  -443,
    -443,  -443,  -443,  -443,  -443,  -443,  -443,    -2,   272,   287,
     288,   289,   291,   294,  -443,   304,  -443,   -26,   -26,   105,
     105,  -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,
     986,  -443,   986,  -443,  -443,  -443,  -443,  -443,   307,    -1,
    -443,  -443,   105,  -443,  -443,   303,   463,   104,  -443,   309,
    -443,  -443,   105,  -443,  -443,  -443,  -443,  1085,  -443,  -443,
    -443,  -443,  -443,  -443,   275,  -443,   311,  -443,  -443,   105,
    -443,  -443,   298,  -443,  -443,    50,  -443
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  MapSetParser::yydefact_[] =
  {
         2,     0,    26,     1,     0,     4,    28,    27,    30,     6,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     5,    31,    29,   237,   238,     0,   358,   360,   359,
     361,     9,   342,    10,    11,    12,   362,   365,   364,    13,
     363,    14,    17,    19,    18,    15,    20,    23,    16,   356,
     357,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     366,   367,   244,     0,     7,    21,   240,   241,   344,   345,
     346,   242,   239,   243,     0,     0,     0,   340,   341,   343,
     338,     0,    24,     0,    32,     8,   339,     0,   188,    59,
       0,    22,   233,   234,   190,    68,    33,   222,   223,   224,
     225,   226,   219,     0,   191,   194,   198,   218,   217,   228,
       0,   196,     0,    69,    60,    71,     0,     0,   189,   190,
     195,   192,   208,   227,     0,     0,    61,    62,    63,    64,
      66,     0,    58,    73,    72,   127,   119,   216,     0,   227,
     215,   235,   236,   193,   209,   199,   207,   232,   227,   229,
     231,   197,    65,     0,     0,    75,    74,   132,     0,    67,
     120,   108,   220,   205,   212,   214,   221,   230,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    79,
      80,    83,    85,    82,   312,   313,   314,     0,     0,    86,
      87,    89,   173,   171,   172,     0,    77,    76,    40,   129,
      34,     0,   130,   139,   133,   143,     0,   109,   200,   210,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     292,    43,   245,   248,   252,   254,   264,   266,   277,   280,
     285,   286,   287,   293,   288,   289,   290,   291,   336,     0,
       0,     0,   316,   302,     0,   185,   303,   184,     0,     0,
       0,   320,   321,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,   178,   175,   174,     0,    88,
       0,     0,     0,    70,    78,   102,   104,    38,    39,    41,
       0,    35,   128,   131,   132,   144,   141,   117,   110,   202,
     206,   227,   213,   283,   284,   282,   178,   178,   323,   324,
     325,   326,   178,   327,     0,    44,     0,   246,   250,     0,
       0,     0,     0,     0,     0,     0,     0,   265,   255,   267,
     279,   337,   335,     0,     0,     0,   186,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   179,     0,   294,    95,    96,    90,    91,     0,    93,
      94,    98,    99,   106,   107,   100,   103,   101,   105,    57,
       0,    53,    54,    56,    37,    49,    46,    48,    47,    50,
      51,    52,    68,   153,   157,   150,   160,     0,   136,   140,
     134,   145,   148,   149,   146,   147,   164,   135,   142,   115,
     203,   204,   227,   211,     0,     0,     0,    42,    84,     0,
     249,     0,   253,   256,   257,   258,   259,   260,   261,   262,
     263,     0,     0,   272,   278,   268,   269,     0,     0,   281,
     300,   301,   315,   181,     0,     0,     0,   295,   296,     0,
     298,   299,     0,   308,   309,   310,   311,     0,   176,    92,
      97,    43,    55,    71,   154,   158,   151,   161,   170,   137,
     132,     0,     0,   201,   330,   331,     0,     0,   328,   247,
     251,   274,   275,   273,   276,   270,   271,     0,     0,     0,
       0,     0,     0,   318,   181,     0,    36,     0,     0,     0,
       0,   138,   168,   118,   113,   116,   322,   183,   181,   187,
       0,   182,     0,   305,   306,   297,   307,   319,     0,     0,
      45,   155,     0,   152,   162,   165,     0,   333,   180,     0,
     317,   177,     0,   159,   166,   169,   125,     0,   111,   126,
     122,   123,   124,   121,     0,   334,     0,   304,   156,     0,
     114,   112,     0,   329,   167,     0,   332
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yypgoto_[] =
  {
      -443,  -443,  -443,  -443,  -443,  -443,  -443,   310,   312,  -443,
    -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,
    -443,  -443,  -443,  -443,   -96,  -443,   -14,  -443,  -443,  -443,
    -443,  -443,  -443,  -443,  -443,   232,   -21,  -443,   -83,  -443,
    -443,  -443,  -443,  -443,  -443,   177,  -443,  -443,   169,  -443,
    -443,    15,  -443,  -443,  -443,  -443,  -443,  -443,    86,    94,
    -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,  -151,
    -164,  -443,  -443,  -443,  -285,  -443,  -443,  -443,  -443,  -443,
    -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,
    -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,  -443,
    -443,  -443,  -443,  -270,  -131,   130,  -443,  -255,  -102,  -442,
      69,  -149,  -443,  -443,  -443,  -443,   263,  -443,  -443,  -443,
     -74,  -443,  -443,    -6,  -443,  -443,  -443,  -443,  -443,  -443,
     -19,  -443,  -443,    83,    87,  -116,  -443,  -443,  -443,  -443,
    -443,  -443,   -87,   -85,  -308,   -11,     9,    -5,  -443,  -443,
    -443,   -24,  -443,  -443,   -23,  -443,  -443,  -443,   -46,  -443,
    -443,   -31,  -443,  -443,  -443,  -239,  -443,  -233,   -52,  -115,
    -139,  -443,  -443,  -443,  -443,  -443,  -271,  -443,  -443,  -443,
    -443,  -443,  -443,    -9,  -443,  -443,  -443,    73,  -443,    58,
      61,    79,  -150,    33,  -443,  -443
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yydefgoto_[] =
  {
        -1,     1,     2,     9,    20,    21,    45,    63,    47,    48,
       5,     6,    10,     7,    23,    74,    90,   209,   291,   382,
     210,   289,   290,   315,   316,   371,   372,   373,   374,    64,
      95,   114,   126,   127,   128,   129,   115,   116,   132,   133,
     155,   206,   283,   134,   189,   190,   156,   199,   200,   207,
     356,   357,   358,   359,   360,   284,   365,   367,   285,   286,
     159,   216,   527,   495,   516,   462,   160,   399,   161,   528,
     136,   157,   211,   212,   213,   388,   460,   389,   293,   214,
     295,   296,   390,   391,   456,   489,   392,   454,   487,   522,
     393,   455,   488,   394,   457,   490,   395,   396,   461,   525,
     539,   515,   397,   201,   202,   277,   484,   352,   501,   477,
     308,   256,   257,   433,    89,    94,   103,   104,   120,   121,
     215,   124,   122,   138,   400,   401,   300,   218,   145,   146,
     163,   302,   219,   164,   139,   106,   107,   117,   108,   109,
     110,   148,   165,   111,   140,   230,    93,   231,   232,   410,
     317,   233,   412,   318,   234,   235,   327,   328,   236,   237,
     423,   429,   474,   424,   329,   238,   330,   239,   240,   241,
     242,   253,   194,   508,   195,   196,   243,   498,   466,   535,
     536,   244,   332,   245,    78,    79,    80,   246,    68,    69,
      70,   247,    32,   248,    40,    73
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int MapSetParser::yytable_ninf_ = -228;
  const short int
  MapSetParser::yytable_[] =
  {
        26,    76,    91,    31,    33,    34,    35,   147,    41,   398,
     361,    66,   261,   262,   193,   204,   251,    75,   297,   378,
     105,   427,   191,   147,     3,   254,   421,   422,   112,    65,
       4,   125,   147,   275,    77,     8,   149,    66,   150,   203,
     499,   521,   509,    22,   113,   105,    46,   500,   500,    39,
     193,   404,   405,    72,   150,    65,   517,   406,   191,    83,
     204,   167,    84,   150,   428,    42,    85,    43,    44,    54,
      55,    56,    57,    58,    59,   493,    92,   494,    66,    72,
      36,    37,    38,    92,   203,    66,   361,    24,    25,    36,
      37,    38,    87,    67,    24,    25,   281,   282,   252,    71,
      24,    25,   378,   383,   384,    88,   141,   255,    92,    86,
      66,   141,    92,   141,    66,   276,   144,   458,   151,    67,
      72,    36,    37,    38,   118,    71,  -163,    72,    92,    96,
      66,   287,   288,   385,   386,   119,   387,    92,   123,    66,
     131,   204,   192,   135,   137,   130,    92,   217,    66,   153,
     142,   377,    72,   500,   534,   142,    72,   142,   130,   375,
      67,    27,    28,    29,    30,   203,    71,    67,   303,   304,
     305,   158,    72,    71,   154,   491,   419,   420,   192,   511,
     512,    72,   471,   472,   162,   147,   197,   197,   205,   249,
      72,   250,    67,   278,   475,   476,    67,   258,    71,   259,
     260,   263,    71,   280,   264,   298,   265,   266,    36,    37,
      38,   267,    67,    24,    25,   268,   150,   204,    71,   269,
     270,    67,   197,   271,   272,   273,   292,    71,   314,   294,
      67,   299,   197,   306,   377,   301,    71,   307,   312,   351,
     353,   203,   375,   450,   333,   334,   335,   363,   204,   336,
     282,   364,   281,   337,   338,   339,   344,   408,   340,   341,
     342,   343,   409,   345,   346,   347,   348,   349,   350,   362,
     430,   411,   203,   413,   414,   415,   416,   417,   418,   376,
     431,   379,   432,    92,   434,    66,   147,   437,   141,   438,
      92,   435,    66,   436,   309,   310,   311,   492,   313,   439,
     440,   441,   442,   407,   319,   320,   321,   322,   323,   324,
     443,   444,   445,   197,   325,   326,   446,   150,   198,   113,
     447,   502,   459,   197,   496,   513,   514,    72,   497,   503,
     504,   505,   142,   506,    72,    11,    12,    13,    14,    15,
      16,    17,    18,   500,    19,   362,   510,   448,   523,   520,
     524,   537,   542,   543,   545,   485,    81,   152,   538,   452,
      82,   453,   376,   380,   379,   451,   274,    67,   279,   381,
     486,   449,   368,    71,    67,   544,   541,   -20,   331,   366,
      71,   507,   143,   463,   403,   469,   402,   425,   470,   197,
     426,    92,   473,    66,     0,   546,     0,     0,     0,   465,
     467,   468,     0,     0,     0,     0,   197,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     197,     0,     0,     0,     0,     0,     0,     0,     0,   478,
     479,   480,     0,     0,   481,    72,     0,   482,     0,     0,
       0,     0,   483,     0,     0,     0,   380,     0,     0,    92,
       0,    66,   381,     0,     0,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    27,    28,    29,    30,
      36,    37,    38,    60,    61,    67,   141,   141,    62,     0,
       0,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    72,     0,   518,     0,   519,     0,     0,
       0,     0,     0,     0,     0,   529,   526,   530,     0,     0,
       0,     0,     0,     0,     0,     0,   529,     0,   530,     0,
     142,   142,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    67,     0,     0,     0,     0,     0,    71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   533,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     533,   464,     0,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    27,    28,    29,    30,    36,    37,
      38,   198,     0,    24,    25,     0,     0,     0,     0,   531,
       0,     0,     0,     0,     0,   532,     0,     0,     0,     0,
     531,     0,   220,   221,     0,   222,   532,     0,   169,   170,
     171,   172,   173,   174,   175,   176,   177,     0,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
       0,     0,     0,   223,   224,   225,   226,   227,   228,   229,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    27,    28,    29,    30,    36,    37,    38,   369,     0,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   370,     0,
       0,     0,     0,     0,     0,   208,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,    98,    99,   100,   101,
       0,     0,     0,  -227,     0,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   102,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,     0,     0,     0,
     223,   224,   225,   226,   227,   228,   229,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    27,    28,
      29,    30,    36,    37,    38,     0,     0,    24,    25,     0,
       0,     0,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    27,    28,    29,    30,    36,    37,    38,
      60,    61,    24,    25,     0,    62,   354,   355,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   198,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    97,    98,    99,   100,
     101,     0,     0,     0,  -227,     0,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   102,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    97,    98,    99,
     100,   101,     0,     0,     0,     0,   166,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   102,     0,     0,     0,
       0,     0,     0,    36,    37,    38,     0,     0,    24,    25,
       0,     0,     0,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    27,    28,    29,    30,    36,    37,
      38,    60,    61,    24,    25,     0,    62,     0,     0,     0,
       0,     0,     0,     0,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    27,    28,    29,    30,    36,
      37,    38,    60,    61,    24,    25,     0,    62,    97,    98,
      99,   100,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   168,     0,   102,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    27,
      28,    29,    30,    36,    37,    38,    60,    61,    24,    25,
       0,    62,   169,   170,   171,   172,   173,   174,   175,   176,
     177,     0,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     0,     0,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    27,    28,    29,    30,
      36,    37,    38,    60,    61,    24,    25,   198,    62,    36,
      37,    38,     0,     0,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,   221,
       0,   222,     0,     0,   169,   170,   171,   172,   173,   174,
     175,   176,   177,     0,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,     0,     0,     0,   223,
     224,   225,   226,   227,   228,   229,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    27,    28,    29,
      30,    36,    37,    38,   198,     0,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   540,   526,     0,
       0,   169,   170,   171,   172,   173,   174,   175,   176,   177,
       0,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,     0,     0,     0,   223,   224,   225,   226,
     227,   228,   229,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    27,    28,    29,    30,    36,    37,
      38,   370,     0,    24,    25,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    27,    28,    29,    30,
      36,    37,    38,     0,     0,    24,    25,     0,   169,   170,
     171,   172,   173,   174,   175,   176,   177,     0,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
       0,     0,     0,   223,   224,   225,   226,   227,   228,   229,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    27,    28,    29,    30,    36,    37,    38,   198,     0,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   169,   170,   171,   172,   173,
     174,   175,   176,   177,     0,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    27,    28,    29,
      30,    36,    37,    38,    60,    61,     0,     0,     0,    62,
       0,     0,    36,    37,    38
  };

  /* YYCHECK.  */
  const short int
  MapSetParser::yycheck_[] =
  {
        11,    89,    87,    12,    13,    14,    15,   123,    17,   294,
     280,    20,   176,   177,   153,   154,    41,    26,    38,   290,
      94,    21,   153,   139,     0,    41,    62,    63,    24,    20,
      17,    25,   148,    41,   122,   115,   123,    46,   123,   154,
      42,    42,   484,    18,    40,   119,    38,    49,    49,    16,
     189,   306,   307,    20,   139,    46,   498,   312,   189,    22,
     199,   148,   116,   148,    64,    11,    75,    13,    14,   105,
     106,   107,   108,   109,   110,    39,    87,    41,    87,    46,
     115,   116,   117,    94,   199,    94,   356,   120,   121,   115,
     116,   117,    39,    20,   120,   121,    30,    31,   123,    20,
     120,   121,   373,    15,    16,    38,   117,   123,   119,    76,
     119,   122,   123,   124,   123,   123,   122,   387,   124,    46,
      87,   115,   116,   117,    39,    46,    38,    94,   139,   115,
     139,    19,    20,    45,    46,    44,    48,   148,    41,   148,
      91,   280,   153,    38,    51,   112,   157,   158,   157,    27,
     117,   290,   119,    49,    50,   122,   123,   124,   125,   290,
      87,   111,   112,   113,   114,   280,    87,    94,   220,   221,
     222,    32,   139,    94,    92,   460,   325,   326,   189,   487,
     488,   148,   421,   422,    53,   301,   153,   154,    26,    41,
     157,    41,   119,   198,   427,   428,   123,    41,   119,    41,
      41,    41,   123,    27,    41,   216,    41,    41,   115,   116,
     117,    41,   139,   120,   121,    41,   301,   356,   139,    41,
      41,   148,   189,    41,    41,    41,    39,   148,    90,    44,
     157,    50,   199,    41,   373,    49,   157,    41,    41,    19,
      42,   356,   373,   358,   249,   250,   251,   102,   387,   254,
      31,   102,    30,   258,   259,   260,   267,    42,   263,   264,
     265,   266,    54,   268,   269,   270,   271,   272,   273,   280,
      42,    55,   387,   319,   320,   321,   322,   323,   324,   290,
      42,   290,    42,   294,    49,   294,   402,    42,   299,    42,
     301,    49,   301,    49,   225,   226,   227,   461,   229,    49,
      42,    42,    49,   314,    56,    57,    58,    59,    60,    61,
      42,    42,    42,   280,    66,    67,    42,   402,    41,    40,
      49,    49,    44,   290,    42,   489,   490,   294,    42,    42,
      42,    42,   299,    42,   301,     3,     4,     5,     6,     7,
       8,     9,    10,    49,    12,   356,    42,   352,   512,    42,
      47,    42,    77,    42,    56,   451,    46,   125,   522,   373,
      48,   382,   373,   290,   373,   370,   189,   294,   199,   290,
     453,   356,   286,   294,   301,   539,   527,    22,   248,   285,
     301,   483,   119,   402,   301,   409,   299,   329,   411,   356,
     329,   402,   423,   402,    -1,   545,    -1,    -1,    -1,   404,
     405,   406,    -1,    -1,    -1,    -1,   373,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     387,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   434,
     435,   436,    -1,    -1,   439,   402,    -1,   442,    -1,    -1,
      -1,    -1,   447,    -1,    -1,    -1,   373,    -1,    -1,   460,
      -1,   460,   373,    -1,    -1,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   402,   487,   488,   123,    -1,
      -1,   402,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   460,    -1,   500,    -1,   502,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   516,    43,   516,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   527,    -1,   527,    -1,
     487,   488,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   460,    -1,    -1,    -1,    -1,    -1,   460,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   516,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     527,    21,    -1,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    41,    -1,   120,   121,    -1,    -1,    -1,    -1,   516,
      -1,    -1,    -1,    -1,    -1,   516,    -1,    -1,    -1,    -1,
     527,    -1,    62,    63,    -1,    65,   527,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    -1,    -1,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    21,    -1,
     120,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    41,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    52,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    -1,    -1,    -1,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,   120,   121,    -1,
      -1,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    -1,   123,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    41,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    52,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,   115,   116,   117,    -1,    -1,   120,   121,
      -1,    -1,    -1,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    -1,   123,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    -1,    52,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,   123,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    -1,    -1,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    41,   123,   115,
     116,   117,    -1,    -1,   120,   121,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      -1,    65,    -1,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    41,    -1,   120,   121,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    -1,    -1,    -1,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    41,    -1,   120,   121,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    -1,    -1,   120,   121,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    -1,    -1,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    41,    -1,
     120,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,   123,
      -1,    -1,   115,   116,   117
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  MapSetParser::yystos_[] =
  {
         0,   125,   126,     0,    17,   134,   135,   137,   115,   127,
     136,     3,     4,     5,     6,     7,     8,     9,    10,    12,
     128,   129,    18,   138,   120,   121,   269,   111,   112,   113,
     114,   307,   316,   307,   307,   307,   115,   116,   117,   317,
     318,   307,    11,    13,    14,   130,    38,   132,   133,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     118,   119,   123,   131,   153,   270,   307,   311,   312,   313,
     314,   315,   317,   319,   139,   307,    89,   122,   308,   309,
     310,   131,   132,    22,   116,   307,   317,    39,    38,   238,
     140,   267,   269,   270,   239,   154,   115,    33,    34,    35,
      36,    37,    52,   240,   241,   244,   259,   260,   262,   263,
     264,   267,    24,    40,   155,   160,   161,   261,    39,    44,
     242,   243,   246,    41,   245,    25,   156,   157,   158,   159,
     317,    91,   162,   163,   167,    38,   194,    51,   247,   258,
     268,   269,   317,   240,   247,   252,   253,   259,   265,   266,
     267,   247,   159,    27,    92,   164,   170,   195,    32,   184,
     190,   192,    53,   254,   257,   266,    42,   266,    41,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,   168,
     169,   228,   269,   294,   296,   298,   299,   317,    41,   171,
     172,   227,   228,   293,   294,    26,   165,   173,    23,   141,
     144,   196,   197,   198,   203,   244,   185,   269,   251,   256,
      62,    63,    65,    93,    94,    95,    96,    97,    98,    99,
     269,   271,   272,   275,   278,   279,   282,   283,   289,   291,
     292,   293,   294,   300,   305,   307,   311,   315,   317,    41,
      41,    41,   123,   295,    41,   123,   235,   236,    41,    41,
      41,   194,   194,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,   169,    41,   123,   229,   271,   172,
      27,    30,    31,   166,   179,   182,   183,    19,    20,   145,
     146,   142,    39,   202,    44,   204,   205,    38,   269,    50,
     250,    49,   255,   292,   292,   292,    41,    41,   234,   234,
     234,   234,    41,   234,    90,   147,   148,   274,   277,    56,
      57,    58,    59,    60,    61,    66,    67,   280,   281,   288,
     290,   229,   306,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   269,   271,   271,   271,   271,   271,
     271,    19,   231,    42,    28,    29,   174,   175,   176,   177,
     178,   227,   269,   102,   102,   180,   183,   181,   182,    21,
      41,   149,   150,   151,   152,   228,   269,   294,   300,   307,
     311,   315,   143,    15,    16,    45,    46,    48,   199,   201,
     206,   207,   210,   214,   217,   220,   221,   226,   198,   191,
     248,   249,   258,   257,   231,   231,   231,   269,    42,    54,
     273,    55,   276,   282,   282,   282,   282,   282,   282,   235,
     235,    62,    63,   284,   287,   313,   314,    21,    64,   285,
      42,    42,    42,   237,    49,    49,    49,    42,    42,    49,
      42,    42,    49,    42,    42,    42,    42,    49,   271,   175,
     293,   271,   150,   160,   211,   215,   208,   218,   227,    44,
     200,   222,   189,   254,    21,   271,   302,   271,   271,   275,
     278,   289,   289,   285,   286,   291,   291,   233,   271,   271,
     271,   271,   271,   271,   230,   148,   162,   212,   216,   209,
     219,   198,   194,    39,    41,   187,    42,    42,   301,    42,
      49,   232,    49,    42,    42,    42,    42,   232,   297,   233,
      42,   268,   268,   194,   194,   225,   188,   233,   271,   271,
      42,    42,   213,   194,    47,   223,    43,   186,   193,   269,
     307,   311,   315,   317,    50,   303,   304,    42,   194,   224,
      42,   193,    77,    42,   194,    56,   316
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  MapSetParser::yytoken_number_[] =
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
     375,   376,   377,   378
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  MapSetParser::yyr1_[] =
  {
         0,   124,   126,   125,   127,   127,   128,   128,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   130,   130,   130,
     131,   131,   132,   133,   133,   134,   135,   135,   136,   136,
     137,   139,   140,   138,   142,   143,   141,   144,   145,   145,
     146,   146,   147,   148,   148,   149,   150,   150,   150,   150,
     150,   150,   150,   150,   151,   151,   152,   152,   153,   154,
     154,   155,   156,   156,   157,   158,   159,   160,   161,   161,
     162,   163,   163,   164,   164,   165,   165,   166,   166,   167,
     168,   168,   169,   169,   169,   169,   170,   171,   171,   172,
     173,   174,   174,   175,   175,   176,   176,   177,   178,   178,
     179,   179,   180,   180,   181,   181,   182,   183,   184,   185,
     185,   186,   186,   188,   187,   189,   189,   191,   190,   192,
     192,   193,   193,   193,   193,   193,   193,   195,   194,   196,
     196,   197,   198,   198,   199,   199,   200,   200,   201,   202,
     202,   203,   204,   205,   205,   206,   206,   206,   206,   206,
     208,   209,   207,   211,   212,   213,   210,   215,   216,   214,
     218,   219,   217,   221,   222,   220,   224,   223,   225,   225,
     226,   227,   227,   227,   228,   229,   230,   229,   231,   231,
     232,   233,   233,   234,   235,   236,   237,   236,   239,   238,
     240,   240,   241,   242,   243,   243,   245,   244,   246,   244,
     247,   248,   249,   249,   250,   251,   251,   252,   253,   253,
     254,   255,   256,   256,   257,   258,   258,   259,   259,   261,
     260,   262,   263,   263,   263,   263,   263,   264,   264,   265,
     265,   266,   266,   267,   267,   268,   268,   269,   269,   270,
     270,   270,   270,   270,   270,   271,   272,   273,   274,   274,
     275,   276,   277,   277,   278,   279,   280,   280,   280,   280,
     280,   280,   280,   280,   281,   281,   282,   283,   284,   284,
     285,   285,   286,   286,   287,   287,   287,   288,   288,   289,
     290,   290,   291,   291,   291,   291,   292,   292,   292,   292,
     292,   292,   292,   292,   293,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   295,   295,   296,   297,   297,
     298,   299,   300,   300,   300,   300,   300,   300,   301,   300,
     302,   302,   303,   304,   304,   305,   306,   306,   307,   308,
     309,   309,   310,   310,   311,   311,   311,   312,   312,   312,
     313,   313,   313,   314,   314,   314,   315,   315,   316,   316,
     316,   316,   317,   317,   318,   318,   319,   319
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  MapSetParser::yyr2_[] =
  {
         0,     2,     0,     4,     0,     2,     0,     2,     4,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       0,     1,     4,     1,     2,     2,     0,     1,     0,     2,
       2,     0,     0,     5,     0,     0,     5,     3,     1,     1,
       0,     1,     2,     0,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     6,     0,
       2,     2,     1,     1,     1,     2,     1,     3,     0,     1,
       4,     0,     1,     0,     1,     0,     1,     0,     1,     3,
       1,     2,     1,     1,     4,     1,     2,     1,     2,     1,
       3,     1,     2,     1,     1,     1,     1,     2,     1,     1,
       2,     2,     0,     1,     0,     1,     2,     2,     1,     1,
       2,     1,     2,     0,     4,     0,     2,     0,     6,     0,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     1,
       1,     2,     0,     1,     1,     1,     0,     1,     3,     0,
       2,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       0,     0,     4,     0,     0,     0,     6,     0,     0,     5,
       0,     0,     4,     0,     0,     4,     0,     3,     0,     2,
       2,     1,     1,     1,     2,     1,     0,     6,     0,     1,
       2,     0,     2,     4,     1,     1,     0,     5,     0,     4,
       0,     1,     2,     2,     0,     1,     0,     3,     0,     3,
       3,     2,     0,     1,     2,     0,     2,     1,     0,     1,
       2,     2,     0,     2,     1,     1,     1,     1,     1,     0,
       4,     4,     1,     1,     1,     1,     1,     0,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     0,     2,
       2,     2,     0,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     0,     1,     1,     2,     1,     1,
       2,     2,     0,     1,     2,     2,     2,     0,     2,     2,
       0,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     4,     6,     4,     4,
       4,     4,     2,     2,     8,     6,     6,     6,     4,     4,
       4,     4,     1,     1,     1,     3,     1,     7,     0,     1,
       2,     2,     5,     2,     2,     2,     2,     2,     0,     8,
       1,     1,     4,     0,     1,     2,     0,     1,     2,     2,
       1,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const MapSetParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "IT_REWRITEVAR", "IT_SERVER",
  "IT_USER", "IT_PASSWORD", "IT_DATABASE", "IT_STEMURI", "IT_PRIMARYKEY",
  "IT_SHAREDVARS", "IT_PROMISCUOUS", "IT_INTERSECTION", "IT_DRACONIAN",
  "IT_VARNAMES", "IT_GRAPH", "IT_SERVICE", "IT_BASE", "IT_PREFIX",
  "IT_DISTINCT", "IT_REDUCED", "GT_TIMES", "IT_CONSTRUCT", "IT_SELECT",
  "IT_FROM", "IT_NAMED", "IT_ORDER", "IT_BY", "IT_ASC", "IT_DESC",
  "IT_LIMIT", "IT_OFFSET", "IT_BINDINGS", "IT_MEMBERS", "IT_STARTS",
  "IT_ENDS", "IT_ANY", "IT_UNORDERED", "GT_LCURLEY", "GT_RCURLEY",
  "IT_WHERE", "GT_LPAREN", "GT_RPAREN", "IT_UNDEF", "GT_DOT",
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
  "MapSet", "$@1", "_QAccessParm_E_Star", "_QConstructQuery_E_Star",
  "AccessParm",
  "_O_QIT_PROMISCUOUS_E_Or_QIT_VARNAMES_E_Or_QIT_DRACONIAN_E_C",
  "_QGraphTerm_E_Opt",
  "_O_QGT_LCURLEY_E_S_QGraphTerm_E_Opt_S_QGT_RCURLEY_E_S_QVarOrTerm_E_C",
  "_Q_O_QGT_LCURLEY_E_S_QGraphTerm_E_Opt_S_QGT_RCURLEY_E_S_QVarOrTerm_E_C_E_Plus",
  "Prologue", "_QBaseDecl_E_Opt", "_QPrefixDecl_E_Star", "BaseDecl",
  "PrefixDecl", "$@2", "$@3", "SubSelect", "@4", "@5", "SelectClause",
  "_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C",
  "_Q_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C_E_Opt", "_O_QIT_AS_E_S_QVar_E_C",
  "_Q_O_QIT_AS_E_S_QVar_E_C_E_Opt",
  "_O_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_Q_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C_E_Plus",
  "_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_Plus_Or_QGT_TIMES_E_C",
  "ConstructQuery", "_QDatasetClause_E_Star", "DatasetClause",
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
  "_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_C", "$@6",
  "_Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_C_E_Star",
  "_O_QIT_BINDINGS_E_S_QVar_E_Plus_S_QGT_LCURLEY_E_S_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Star_S_QGT_RCURLEY_E_C",
  "$@7",
  "_Q_O_QIT_BINDINGS_E_S_QVar_E_Plus_S_QGT_LCURLEY_E_S_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Star_S_QGT_RCURLEY_E_C_E_Opt",
  "BindingValue", "GroupGraphPattern", "$@8",
  "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C", "GroupGraphPatternSub",
  "_QTriplesBlock_E_Opt", "_O_QGraphPatternNotTriples_E_Or_QFilter_E_C",
  "_QGT_DOT_E_Opt",
  "_O_QGraphPatternNotTriples_E_Or_QFilter_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_Or_QFilter_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "OptionalGraphPattern", "@9", "@10", "GraphGraphPattern", "@11", "@12",
  "@13", "ServiceGraphPattern", "@14", "@15", "MinusGraphPattern", "@16",
  "@17", "GroupOrUnionGraphPattern", "@18", "@19",
  "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@20",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "$@21", "_QIT_DISTINCT_E_Opt",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ExprAggArg",
  "ExpressionList",
  "_O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C",
  "$@22", "ConstructTemplate", "$@23", "_QConstructTriples_E_Opt",
  "ConstructTriples", "_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C_E_Opt", "TriplesSameSubject",
  "$@24", "$@25", "PropertyListNotEmpty", "_O_QVerb_E_S_QObjectList_E_C",
  "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "Verb", "TriplesNode", "BlankNodePropertyList", "@26",
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
  "ExistsFunc", "NotExistsFunc", "Aggregate", "$@27",
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
  const MapSetParser::rhs_number_type
  MapSetParser::yyrhs_[] =
  {
       125,     0,    -1,    -1,   126,   134,   127,   128,    -1,    -1,
     127,   129,    -1,    -1,   128,   153,    -1,     3,   269,   307,
     307,    -1,     4,   307,    -1,     5,   307,    -1,     6,   307,
      -1,     7,   307,    -1,     8,   317,    -1,     9,   307,    -1,
      10,   130,    -1,    12,   133,    -1,    11,    -1,    14,    -1,
      13,    -1,    -1,   270,    -1,    38,   131,    39,   267,    -1,
     132,    -1,   133,   132,    -1,   135,   136,    -1,    -1,   137,
      -1,    -1,   136,   138,    -1,    17,   115,    -1,    -1,    -1,
      18,   139,   116,   140,   115,    -1,    -1,    -1,   144,   142,
     143,   160,   162,    -1,    23,   146,   152,    -1,    19,    -1,
      20,    -1,    -1,   145,    -1,    90,   269,    -1,    -1,   147,
      -1,    41,   271,   148,    42,    -1,   269,    -1,   300,    -1,
     294,    -1,   228,    -1,   307,    -1,   311,    -1,   315,    -1,
     149,    -1,   150,    -1,   151,   150,    -1,   151,    -1,    21,
      -1,   131,    22,   238,   154,   160,   162,    -1,    -1,   154,
     155,    -1,    24,   156,    -1,   157,    -1,   158,    -1,   159,
      -1,    25,   159,    -1,   317,    -1,   161,   194,   184,    -1,
      -1,    40,    -1,   163,   164,   165,   166,    -1,    -1,   167,
      -1,    -1,   170,    -1,    -1,   173,    -1,    -1,   179,    -1,
      91,    27,   168,    -1,   169,    -1,   168,   169,    -1,   294,
      -1,   228,    -1,    41,   271,   148,    42,    -1,   269,    -1,
      92,   171,    -1,   172,    -1,   171,   172,    -1,   227,    -1,
      26,    27,   174,    -1,   175,    -1,   174,   175,    -1,   177,
      -1,   178,    -1,    28,    -1,    29,    -1,   176,   293,    -1,
     227,    -1,   269,    -1,   182,   180,    -1,   183,   181,    -1,
      -1,   183,    -1,    -1,   182,    -1,    30,   102,    -1,    31,
     102,    -1,   192,    -1,   269,    -1,   185,   269,    -1,   193,
      -1,   186,   193,    -1,    -1,    41,   188,   186,    42,    -1,
      -1,   189,   187,    -1,    -1,    32,   185,    38,   191,   189,
      39,    -1,    -1,   190,    -1,   317,    -1,   307,    -1,   311,
      -1,   315,    -1,    43,    -1,   269,    -1,    -1,    38,   195,
     196,    39,    -1,   141,    -1,   197,    -1,   198,   202,    -1,
      -1,   203,    -1,   206,    -1,   226,    -1,    -1,    44,    -1,
     199,   200,   198,    -1,    -1,   202,   201,    -1,   244,   205,
      -1,    44,   198,    -1,    -1,   204,    -1,   207,    -1,   217,
      -1,   220,    -1,   210,    -1,   214,    -1,    -1,    -1,    45,
     208,   209,   194,    -1,    -1,    -1,    -1,    15,   211,   212,
     268,   213,   194,    -1,    -1,    -1,    16,   215,   216,   268,
     194,    -1,    -1,    -1,    46,   218,   219,   194,    -1,    -1,
      -1,   221,   222,   194,   225,    -1,    -1,    47,   224,   194,
      -1,    -1,   225,   223,    -1,    48,   227,    -1,   293,    -1,
     294,    -1,   228,    -1,   317,   229,    -1,   123,    -1,    -1,
      41,   231,   271,   230,   233,    42,    -1,    -1,    19,    -1,
      49,   271,    -1,    -1,   233,   232,    -1,    41,   231,   271,
      42,    -1,   236,    -1,   123,    -1,    -1,    41,   271,   237,
     233,    42,    -1,    -1,    38,   239,   240,    39,    -1,    -1,
     241,    -1,   244,   243,    -1,    44,   240,    -1,    -1,   242,
      -1,    -1,   267,   245,   247,    -1,    -1,   259,   246,   252,
      -1,   258,   254,   251,    -1,   258,   254,    -1,    -1,   248,
      -1,    50,   249,    -1,    -1,   251,   250,    -1,   253,    -1,
      -1,   247,    -1,   257,   256,    -1,    49,   257,    -1,    -1,
     256,   255,    -1,   266,    -1,   268,    -1,    51,    -1,   262,
      -1,   260,    -1,    -1,    52,   261,   247,    53,    -1,   264,
      41,   265,    42,    -1,    33,    -1,    34,    -1,    35,    -1,
      36,    -1,    37,    -1,    -1,   263,    -1,   266,    -1,   265,
     266,    -1,   267,    -1,   259,    -1,   269,    -1,   270,    -1,
     269,    -1,   317,    -1,   120,    -1,   121,    -1,   317,    -1,
     307,    -1,   311,    -1,   315,    -1,   319,    -1,   123,    -1,
     272,    -1,   275,   274,    -1,    54,   275,    -1,    -1,   274,
     273,    -1,   278,   277,    -1,    55,   278,    -1,    -1,   277,
     276,    -1,   279,    -1,   282,   281,    -1,    56,   282,    -1,
      57,   282,    -1,    58,   282,    -1,    59,   282,    -1,    60,
     282,    -1,    61,   282,    -1,    66,   235,    -1,    67,   235,
      -1,    -1,   280,    -1,   283,    -1,   289,   288,    -1,   313,
      -1,   314,    -1,    21,   291,    -1,    64,   291,    -1,    -1,
     285,    -1,    62,   289,    -1,    63,   289,    -1,   284,   286,
      -1,    -1,   288,   287,    -1,   291,   290,    -1,    -1,   290,
     285,    -1,    65,   292,    -1,    62,   292,    -1,    63,   292,
      -1,   292,    -1,   293,    -1,   294,    -1,   305,    -1,   307,
      -1,   311,    -1,   315,    -1,   269,    -1,   300,    -1,    41,
     271,    42,    -1,    78,    41,   271,    42,    -1,    79,    41,
     271,    42,    -1,    80,    41,   271,    49,   271,    42,    -1,
      81,    41,   271,    42,    -1,    82,    41,   269,    42,    -1,
      68,    41,   271,    42,    -1,    69,    41,   271,    42,    -1,
      70,   295,    -1,    71,   235,    -1,    72,    41,   271,    49,
     271,    49,   271,    42,    -1,    73,    41,   271,    49,   271,
      42,    -1,    74,    41,   271,    49,   271,    42,    -1,    83,
      41,   271,    49,   271,    42,    -1,    84,    41,   271,    42,
      -1,    85,    41,   271,    42,    -1,    86,    41,   271,    42,
      -1,    87,    41,   271,    42,    -1,   296,    -1,   298,    -1,
     299,    -1,    41,   271,    42,    -1,   123,    -1,    88,    41,
     271,    49,   271,   297,    42,    -1,    -1,   232,    -1,    75,
     194,    -1,    76,   194,    -1,    93,    41,   231,   302,    42,
      -1,    94,   234,    -1,    95,   234,    -1,    96,   234,    -1,
      97,   234,    -1,    99,   234,    -1,    -1,    98,    41,   231,
     271,   301,   233,   304,    42,    -1,    21,    -1,   271,    -1,
      50,    77,    56,   316,    -1,    -1,   303,    -1,   317,   306,
      -1,    -1,   229,    -1,   316,   310,    -1,    89,   317,    -1,
     122,    -1,   308,    -1,    -1,   309,    -1,   312,    -1,   313,
      -1,   314,    -1,   102,    -1,   103,    -1,   104,    -1,   105,
      -1,   106,    -1,   107,    -1,   108,    -1,   109,    -1,   110,
      -1,   100,    -1,   101,    -1,   111,    -1,   113,    -1,   112,
      -1,   114,    -1,   115,    -1,   318,    -1,   117,    -1,   116,
      -1,   118,    -1,   119,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  MapSetParser::yyprhs_[] =
  {
         0,     0,     3,     4,     9,    10,    13,    14,    17,    22,
      25,    28,    31,    34,    37,    40,    43,    46,    48,    50,
      52,    53,    55,    60,    62,    65,    68,    69,    71,    72,
      75,    78,    79,    80,    86,    87,    88,    94,    98,   100,
     102,   103,   105,   108,   109,   111,   116,   118,   120,   122,
     124,   126,   128,   130,   132,   134,   137,   139,   141,   148,
     149,   152,   155,   157,   159,   161,   164,   166,   170,   171,
     173,   178,   179,   181,   182,   184,   185,   187,   188,   190,
     194,   196,   199,   201,   203,   208,   210,   213,   215,   218,
     220,   224,   226,   229,   231,   233,   235,   237,   240,   242,
     244,   247,   250,   251,   253,   254,   256,   259,   262,   264,
     266,   269,   271,   274,   275,   280,   281,   284,   285,   292,
     293,   295,   297,   299,   301,   303,   305,   307,   308,   313,
     315,   317,   320,   321,   323,   325,   327,   328,   330,   334,
     335,   338,   341,   344,   345,   347,   349,   351,   353,   355,
     357,   358,   359,   364,   365,   366,   367,   374,   375,   376,
     382,   383,   384,   389,   390,   391,   396,   397,   401,   402,
     405,   408,   410,   412,   414,   417,   419,   420,   427,   428,
     430,   433,   434,   437,   442,   444,   446,   447,   453,   454,
     459,   460,   462,   465,   468,   469,   471,   472,   476,   477,
     481,   485,   488,   489,   491,   494,   495,   498,   500,   501,
     503,   506,   509,   510,   513,   515,   517,   519,   521,   523,
     524,   529,   534,   536,   538,   540,   542,   544,   545,   547,
     549,   552,   554,   556,   558,   560,   562,   564,   566,   568,
     570,   572,   574,   576,   578,   580,   582,   585,   588,   589,
     592,   595,   598,   599,   602,   604,   607,   610,   613,   616,
     619,   622,   625,   628,   631,   632,   634,   636,   639,   641,
     643,   646,   649,   650,   652,   655,   658,   661,   662,   665,
     668,   669,   672,   675,   678,   681,   683,   685,   687,   689,
     691,   693,   695,   697,   699,   703,   708,   713,   720,   725,
     730,   735,   740,   743,   746,   755,   762,   769,   776,   781,
     786,   791,   796,   798,   800,   802,   806,   808,   816,   817,
     819,   822,   825,   831,   834,   837,   840,   843,   846,   847,
     856,   858,   860,   865,   866,   868,   871,   872,   874,   877,
     880,   882,   884,   885,   887,   889,   891,   893,   895,   897,
     899,   901,   903,   905,   907,   909,   911,   913,   915,   917,
     919,   921,   923,   925,   927,   929,   931,   933
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  MapSetParser::yyrline_[] =
  {
         0,   371,   371,   371,   377,   379,   383,   385,   389,   398,
     401,   404,   407,   410,   413,   416,   419,   425,   428,   431,
     437,   440,   444,   456,   457,   462,   466,   468,   472,   474,
     478,   484,   486,   484,   496,   498,   496,   508,   516,   519,
     526,   529,   534,   541,   544,   549,   556,   559,   562,   565,
     568,   571,   574,   578,   583,   586,   594,   597,   604,   613,
     616,   624,   631,   632,   636,   642,   648,   655,   662,   664,
     668,   675,   678,   683,   686,   691,   694,   699,   703,   707,
     714,   717,   724,   727,   730,   733,   739,   745,   748,   755,
     760,   767,   771,   779,   781,   789,   792,   800,   808,   809,
     816,   820,   828,   831,   836,   839,   843,   849,   857,   862,
     866,   873,   876,   882,   882,   891,   894,   901,   901,   910,
     913,   917,   920,   923,   926,   929,   932,   939,   939,   951,
     952,   957,   961,   963,   968,   969,   973,   975,   980,   984,
     987,   992,   997,  1001,  1004,  1008,  1009,  1010,  1011,  1012,
    1016,  1018,  1016,  1032,  1034,  1036,  1032,  1047,  1049,  1047,
    1058,  1060,  1058,  1070,  1073,  1070,  1083,  1083,  1097,  1099,
    1103,  1114,  1115,  1116,  1120,  1128,  1132,  1132,  1141,  1144,
    1151,  1157,  1159,  1166,  1173,  1177,  1180,  1180,  1190,  1190,
    1198,  1200,  1205,  1210,  1214,  1216,  1220,  1220,  1223,  1223,
    1230,  1235,  1239,  1241,  1246,  1250,  1252,  1257,  1261,  1263,
    1268,  1273,  1277,  1279,  1283,  1290,  1294,  1301,  1302,  1306,
    1306,  1319,  1344,  1347,  1350,  1353,  1356,  1363,  1366,  1371,
    1375,  1382,  1383,  1387,  1390,  1394,  1397,  1403,  1404,  1408,
    1411,  1414,  1417,  1420,  1421,  1427,  1432,  1441,  1448,  1451,
    1459,  1468,  1475,  1478,  1485,  1490,  1501,  1504,  1507,  1510,
    1513,  1516,  1519,  1522,  1529,  1532,  1536,  1541,  1550,  1553,
    1560,  1563,  1570,  1573,  1578,  1581,  1585,  1599,  1602,  1610,
    1619,  1622,  1629,  1632,  1635,  1638,  1642,  1643,  1644,  1645,
    1648,  1651,  1654,  1657,  1661,  1667,  1670,  1673,  1676,  1679,
    1682,  1685,  1689,  1692,  1696,  1699,  1702,  1705,  1708,  1711,
    1714,  1717,  1720,  1721,  1722,  1728,  1731,  1738,  1745,  1748,
    1752,  1759,  1766,  1769,  1772,  1775,  1778,  1781,  1785,  1785,
    1797,  1800,  1804,  1810,  1813,  1817,  1827,  1830,  1835,  1843,
    1850,  1854,  1862,  1866,  1870,  1871,  1872,  1876,  1877,  1878,
    1882,  1883,  1884,  1888,  1889,  1890,  1894,  1895,  1899,  1900,
    1901,  1902,  1906,  1907,  1911,  1912,  1916,  1917
  };

  // Print the state stack on the debug stream.
  void
  MapSetParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  MapSetParser::yy_reduce_print_ (int yyrule)
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
  MapSetParser::token_number_type
  MapSetParser::yytranslate_ (int t)
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
     115,   116,   117,   118,   119,   120,   121,   122,   123
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int MapSetParser::yyeof_ = 0;
  const int MapSetParser::yylast_ = 1334;
  const int MapSetParser::yynnts_ = 196;
  const int MapSetParser::yyempty_ = -2;
  const int MapSetParser::yyfinal_ = 3;
  const int MapSetParser::yyterror_ = 1;
  const int MapSetParser::yyerrcode_ = 256;
  const int MapSetParser::yyntokens_ = 124;

  const unsigned int MapSetParser::yyuser_token_number_max_ = 378;
  const MapSetParser::token_number_type MapSetParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 3930 "lib/MapSetParser/MapSetParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 1923 "lib/MapSetParser/MapSetParser.ypp"
 /*** Additional Code ***/

void w3c_sw::MapSetParser::error(const MapSetParser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

/* START Driver (@@ stand-alone would allow it to be shared with other parsers */

namespace w3c_sw {

    MapSetDriver::MapSetDriver (std::string baseURI, POSFactory* posFactory) : 
	YaccDriver(baseURI, posFactory), curSubject(NULL), curPredicate(NULL), 
	curBGP(NULL), curFilter(NULL), 
	curBindingsClause(NULL), curBinding(NULL), curExprList(NULL), 
	root(NULL), lastRuleTerm(posFactory->getNULL(), posFactory->getNULL()),
	lastRuleTermSet(false), sharedVarsSet(false)
{
}

    MapSetDriver::~MapSetDriver ()
{
}

bool MapSetDriver::parse(IStreamContext& in)
{
    streamname = in.nameStr;

    MapSetScanner scanner(this, in.p);
    scanner.set_debug(trace_scanning);
    lexer = &scanner;

    MapSetParser parser(*this);
    parser.set_debug_level(trace_parsing);
    // !!! Clear out namespaces!
    ignorePrefixFlag = false;
    return (parser.parse());
}

} // namespace w3c_sw

/* END Driver */


