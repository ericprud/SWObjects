
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
#line 235 "lib/MapSetParser/MapSetParser.ypp"

#include "../MapSetScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 365 "lib/MapSetParser/MapSetParser.ypp"

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
#line 45 "lib/MapSetParser/MapSetParser.ypp"
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
#line 380 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root = new MapSet();
	driver.root->sharedVars = MapSet::e_PROMISCUOUS;
      }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 398 "lib/MapSetParser/MapSetParser.ypp"
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
#line 407 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->server = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 410 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->user = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 413 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->password = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 416 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->database = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 419 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->stemURI = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 424 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.sharedVarsSet = true;
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 428 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.lastRuleTermSet = false;
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 434 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_PROMISCUOUS;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 437 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_VARNAMES;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 440 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_DRACONIAN;
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 446 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = NULL;
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 453 "lib/MapSetParser/MapSetParser.ypp"
    {
	RuleTerm nextRuleTerm = RuleTerm((yysemantic_stack_[(4) - (2)].p_TTerm), (yysemantic_stack_[(4) - (4)].p_TTerm));
	if (driver.lastRuleTermSet)
	    static_cast<MapSet*>(driver.root)->nodeShare.addIntersection(driver.lastRuleTerm, nextRuleTerm);
	driver.lastRuleTerm = nextRuleTerm;
	driver.lastRuleTermSet = true;
	if (!driver.sharedVarsSet)
	    driver.root->sharedVars = MapSet::e_DRACONIAN;
    }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 488 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->keyMap[(yysemantic_stack_[(3) - (1)].p_RDFLiteral)->getLexicalValue()] = (yysemantic_stack_[(3) - (3)].p_RDFLiteral)->getLexicalValue();
    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 499 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->primaryKey = (yysemantic_stack_[(3) - (2)].p_RDFLiteral);
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 522 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 528 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 530 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 532 "lib/MapSetParser/MapSetParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 540 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 542 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(4) - (1)].p_Project).distinctness, (yysemantic_stack_[(4) - (1)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier))));
      }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 549 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 557 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 560 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 567 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 575 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 582 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 590 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 597 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 600 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 603 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 606 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 609 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 612 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 615 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 624 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 627 "lib/MapSetParser/MapSetParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 635 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 638 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 645 "lib/MapSetParser/MapSetParser.ypp"
    {
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	Construct* constr = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(6) - (3)].p_BasicGraphPattern), (yysemantic_stack_[(6) - (4)].p_DatasetClauses), (yysemantic_stack_[(6) - (5)].p_WhereClause), (yysemantic_stack_[(6) - (6)].p_SolutionModifier));
	driver.root->maps.push_back(LabeledConstruct((yysemantic_stack_[(6) - (1)].p_TTerm), constr));
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 654 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 657 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 665 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 677 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 683 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 689 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 696 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp ? driver.curOp : new DefaultGraphPattern(), (yysemantic_stack_[(3) - (3)].p_BindingsClause));
	driver.curOp = NULL;
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 709 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 716 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = NULL;
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 724 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 732 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 740 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 748 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 755 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 758 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 765 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 768 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 771 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 774 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 780 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 786 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 789 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 801 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 808 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 812 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 822 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 830 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 833 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 841 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 850 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 857 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 861 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 869 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 877 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 884 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 890 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 903 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTermList) = new TTermList;
	(yyval.p_TTermList)->push_back((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 907 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTermList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_TTermList) = (yysemantic_stack_[(2) - (1)].p_TTermList);
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 914 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 917 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 923 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding = new Binding();
      }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 925 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BindingValue) = driver.curBinding;
	  driver.curBinding = NULL;
      }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 932 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 935 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBindingsClause->push_back((yysemantic_stack_[(2) - (2)].p_BindingValue));
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 942 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBindingsClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_TTermList));
      }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 944 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BindingsClause) = driver.curBindingsClause;
	  driver.curBindingsClause = NULL;
      }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 951 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BindingsClause) = NULL;
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 958 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 961 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 964 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 967 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 970 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 973 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 980 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 983 "lib/MapSetParser/MapSetParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1057 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1060 "lib/MapSetParser/MapSetParser.ypp"
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

  case 161:

/* Line 678 of lalr1.cc  */
#line 1072 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 1075 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 1077 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 1080 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1088 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1091 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1093 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(5) - (4)].p_TTerm), driver.curOp, driver.atomFactory, false));
      }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1100 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1103 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1105 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.curOp));
      }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 1113 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 1116 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 1118 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1126 "lib/MapSetParser/MapSetParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 1131 "lib/MapSetParser/MapSetParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 1146 "lib/MapSetParser/MapSetParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    if (driver.curOp == NULL)
		driver.ensureBasicGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 1163 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 1171 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 1175 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 1177 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = NULL;
      }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 1184 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 1187 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 1194 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 1202 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 1209 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_DistExprPair).distinctness = (yysemantic_stack_[(4) - (2)].p_distinctness);
	  (yyval.p_DistExprPair).p_Expression = (yysemantic_stack_[(4) - (3)].p_Expression);
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 1220 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 1223 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1225 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1233 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1235 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 1263 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 1266 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 1326 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 1333 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 1337 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 1349 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 1353 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 1362 "lib/MapSetParser/MapSetParser.ypp"
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

  case 230:

/* Line 678 of lalr1.cc  */
#line 1387 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 1390 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 1393 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 1396 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 1399 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 1406 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 1414 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 1418 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 1430 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 1437 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 1440 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 1451 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 1454 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 1457 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 1460 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 1464 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 1475 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 1484 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 1491 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 1494 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 1502 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 1511 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 1518 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 1521 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 1533 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_GeneralComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_GeneralComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_GeneralComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 1543 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 1551 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 1554 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 1557 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 1560 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 1563 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 1566 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 1569 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 1572 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 1583 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 1592 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 1595 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 1602 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 1605 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 1612 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 1620 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 1623 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 1627 "lib/MapSetParser/MapSetParser.ypp"
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

  case 285:

/* Line 678 of lalr1.cc  */
#line 1641 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 1644 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 1652 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 1661 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 1664 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 1671 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 1674 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 1677 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 1687 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 1690 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 1693 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 1696 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 1703 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 1709 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 1712 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 1715 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 1718 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 1721 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 1724 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 1727 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 1731 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_blank, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 1734 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 1738 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 1741 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 1744 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 1747 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 1750 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 1753 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 1756 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 1759 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 1770 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 1773 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 1780 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_regex, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 1787 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 1794 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 1801 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 1808 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 1811 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_sum, (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 1814 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_min, (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 1817 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_max, (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 1820 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_avg, (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 1823 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_sample, (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 1827 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 1829 "lib/MapSetParser/MapSetParser.ypp"
    {
	  // x = new ArgList($2, driver.curExprList);
	  delete driver.curExprList;
	  driver.curExprList = NULL;
	  w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // $$ = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group-concat, $3, $4.p_Expression, $4.separator));
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 1839 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 1846 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 1852 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 1859 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 1869 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 1877 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 1885 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 1892 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 1896 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 1904 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 2670 "lib/MapSetParser/MapSetParser.cpp"
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
  const short int MapSetParser::yypact_ninf_ = -471;
  const short int
  MapSetParser::yypact_[] =
  {
      -471,    37,    24,  -471,   -67,  -471,  -471,  -471,  -471,   406,
      45,    16,   -40,   -40,   -40,   -40,    75,    29,    78,    50,
     371,  -471,  -471,  -471,  -471,  -471,   -40,  -471,  -471,  -471,
    -471,  -471,   -66,  -471,  -471,  -471,  -471,  -471,  -471,  -471,
    -471,   -40,  -471,    55,  -471,  -471,  -471,  -471,  -471,  1236,
    -471,    50,  -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,
    -471,  -471,  -471,  -471,  -471,  -471,    61,  -471,  -471,  -471,
    -471,  -471,  -471,  -471,  -471,  -471,  -471,   -19,   -40,    75,
    -471,  -471,  -471,  -471,    46,  -471,  -471,  -471,    68,  -471,
      76,  -471,  -471,  -471,  -471,    21,  1207,  -471,  -471,     5,
    -471,  -471,    77,  -471,  -471,  -471,   795,     4,  -471,   -40,
    -471,  -471,  -471,  -471,  -471,  -471,    84,  -471,    94,  -471,
    -471,  -471,  -471,   102,  -471,   -10,  -471,  -471,    58,   112,
    -471,    65,  -471,   795,  -471,  -471,    65,   909,    65,    75,
    -471,  -471,  -471,  -471,  -471,   125,  -471,    63,  -471,  -471,
     127,  -471,   104,   909,  -471,  -471,  -471,  -471,  -471,  -471,
    -471,  -471,   819,  -471,  -471,  -471,  -471,   194,  1218,   137,
    -471,   705,    16,  -471,  -471,  -471,  -471,  -471,  -471,  -471,
    -471,  -471,   989,    90,   132,   135,   -28,   -20,   152,   161,
     170,   112,   172,   176,   189,   191,   203,   206,   207,   208,
     209,   210,   214,   194,  -471,  -471,  -471,  -471,  -471,  -471,
    -471,   -14,   989,  1218,  -471,  -471,  -471,  -471,  -471,   197,
     110,  -471,   148,  -471,  -471,   217,  -471,  -471,  -471,   201,
      -2,  -471,   211,   235,  1065,  1065,  1065,   216,   218,   218,
     218,   218,   244,   218,  -471,   169,  -471,  -471,  -471,  -471,
     149,  -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,
    -471,  -471,   -14,   112,   989,   989,   989,  -471,  -471,   989,
    -471,  -471,  -471,   989,   989,   989,  -471,   989,   989,   989,
     989,    16,   989,   989,   989,   989,   989,   989,  -471,   267,
    -471,  -471,   246,  -471,   517,   188,   190,  -471,  -471,   261,
     264,  -471,  -471,  -471,   681,   256,  -471,   183,   795,  -471,
    -471,  -471,  -471,    65,  -471,   909,  -471,  -471,  -471,  -471,
     267,   267,  -471,  -471,  -471,  -471,   267,  -471,    16,  -471,
     258,   247,   243,   989,   989,   989,   989,   989,   989,   236,
     -20,  -471,  -471,   -29,    -5,  -471,  -471,  -471,   263,   265,
     269,  -471,   266,   272,   276,   270,   284,   279,   287,   288,
     282,   290,   291,   292,   293,   294,  -471,   989,  -471,  -471,
    -471,   517,  -471,   295,  -471,  -471,  -471,  -471,  -471,  -471,
    -471,  -471,  -471,  -471,  -471,   989,  -471,  -471,  1141,  -471,
    -471,  -471,  -471,  -471,  -471,  -471,  -471,    58,  -471,  -471,
    -471,  -471,  1218,   296,  -471,  -471,  -471,  -471,  -471,  -471,
    -471,  -471,  -471,  -471,  -471,  -471,  -471,   909,  -471,   585,
     989,   989,  -471,  -471,   989,  -471,   989,  -471,  -471,  -471,
    -471,  -471,  -471,  -471,   -20,  -471,   989,   989,    -5,  -471,
    -471,  -471,   989,   989,  -471,  -471,  -471,  -471,  -471,   989,
     989,   989,  -471,  -471,   989,  -471,  -471,   989,  -471,  -471,
    -471,  -471,   989,  -471,  -471,  -471,   169,  -471,  -471,  -471,
    -471,   112,  -471,  -471,  -471,   795,   112,    27,  -471,  -471,
    -471,   297,   300,  -471,  -471,  -471,  -471,  -471,  -471,  -471,
    -471,  -471,  -471,    -4,   308,   302,   316,   317,   319,   313,
    -471,   321,   204,   204,  -471,   112,  -471,  -471,  -471,  -471,
    -471,  -471,  -471,  -471,  -471,   989,  -471,   989,  -471,  -471,
    -471,  -471,  -471,   323,    -3,  -471,  -471,   112,  -471,   320,
     873,   133,  -471,   324,  -471,  -471,   112,  -471,  -471,  -471,
    -471,  1163,  -471,  -471,  -471,  -471,  -471,  -471,   298,  -471,
     326,  -471,  -471,   112,  -471,  -471,   314,  -471,  -471,   -40,
    -471
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  MapSetParser::yydefact_[] =
  {
         2,     0,    36,     1,     0,     4,    38,    37,    40,     6,
      35,     0,     0,     0,     0,     0,     0,    26,     0,     0,
       3,     5,    41,    39,   245,   246,     0,   366,   368,   367,
     369,     9,   350,    10,    11,    12,   370,   373,   372,    13,
     371,     0,    14,    28,    27,    17,    19,    18,    15,    20,
      23,    16,   364,   365,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   374,   375,   252,     0,     7,    21,   248,
     249,   352,   353,   354,   250,   247,   251,     0,     0,     0,
     348,   349,   351,   346,     0,    32,    25,    29,     0,    24,
       0,    42,     8,   347,    34,     0,     0,   196,    68,     0,
      30,    33,     0,    22,   241,   242,   198,    77,    43,     0,
     230,   231,   232,   233,   234,   227,     0,   199,   202,   206,
     226,   225,   236,     0,   204,     0,    78,    69,    80,     0,
      31,     0,   197,   198,   203,   200,   216,   235,     0,     0,
      70,    71,    72,    73,    75,     0,    67,    82,    81,   136,
     128,   224,     0,   235,   223,   243,   244,   201,   217,   207,
     215,   240,   235,   237,   239,   205,    74,     0,     0,    84,
      83,   141,     0,    76,   129,   117,   228,   213,   220,   222,
     229,   238,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    92,    94,    91,   320,   321,
     322,     0,     0,    95,    96,    98,   181,   179,   180,     0,
      86,    85,    49,   138,    44,     0,   139,   148,   142,   152,
       0,   118,   208,   218,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   300,    52,   253,   256,   260,   262,
     264,   274,   285,   288,   293,   294,   295,   301,   296,   297,
     298,   299,   344,     0,     0,     0,     0,   324,   310,     0,
     193,   311,   192,     0,     0,     0,   328,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,   186,
     183,   182,     0,    97,     0,     0,     0,    79,    87,   111,
     113,    47,    48,    50,     0,    77,   137,   140,   141,   153,
     150,   126,   119,   210,   214,   235,   221,   291,   292,   290,
     186,   186,   331,   332,   333,   334,   186,   335,     0,    53,
       0,   254,   258,     0,     0,     0,     0,     0,     0,     0,
       0,   263,   265,   275,   287,   345,   343,   329,     0,     0,
       0,   194,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   187,     0,   302,   104,
     105,    99,   100,     0,   102,   103,   107,   108,   115,   116,
     109,   112,   110,   114,    66,     0,    62,    63,    65,    46,
      58,    55,    57,    56,    59,    60,    61,    80,   161,   165,
     159,   168,     0,   145,   149,   143,   154,   157,   158,   155,
     156,   172,   144,   151,   124,   211,   212,   235,   219,     0,
       0,     0,    51,    93,     0,   257,     0,   261,   266,   267,
     268,   269,   270,   271,     0,   272,     0,     0,   280,   286,
     276,   277,     0,     0,   289,   308,   309,   323,   189,     0,
       0,     0,   303,   304,     0,   306,   307,     0,   316,   317,
     318,   319,     0,   184,   101,   106,    52,    64,    45,   162,
     166,     0,   169,   178,   146,   141,     0,     0,   209,   338,
     339,     0,     0,   336,   255,   259,   273,   282,   283,   281,
     284,   278,   279,     0,     0,     0,     0,     0,     0,   326,
     189,     0,     0,     0,   160,     0,   147,   176,   127,   122,
     125,   330,   191,   189,   195,     0,   190,     0,   313,   314,
     305,   315,   327,     0,     0,    54,   163,     0,   170,   173,
       0,   341,   188,     0,   325,   185,     0,   167,   174,   177,
     134,     0,   120,   135,   131,   132,   133,   130,     0,   342,
       0,   312,   164,     0,   123,   121,     0,   337,   175,     0,
     340
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yypgoto_[] =
  {
      -471,  -471,  -471,  -471,  -471,  -471,  -471,   327,   318,  -471,
    -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,
    -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,
     -94,  -471,   -15,  -471,  -471,  -471,  -471,  -471,  -471,  -471,
    -471,   239,    70,  -471,   -17,  -471,  -471,  -471,  -471,  -471,
    -471,   178,  -471,  -471,   171,  -471,  -471,    11,  -471,  -471,
    -471,  -471,  -471,  -471,    83,    87,  -471,  -471,  -471,  -471,
    -471,  -471,  -471,  -471,  -471,  -154,  -189,  -471,  -471,  -471,
    -300,  -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,
    -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,
    -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,  -287,  -155,
     126,  -471,  -264,  -109,  -470,  -130,  -331,  -471,  -471,  -471,
    -471,   259,  -471,  -471,  -471,   -82,  -471,  -471,  -107,  -471,
    -471,  -471,  -471,  -471,  -471,   -26,  -471,  -471,    79,    82,
    -127,  -471,  -471,  -471,  -471,  -471,  -471,  -112,   -95,  -306,
     -11,     3,   159,  -471,  -471,  -471,   -27,  -471,  -471,   -25,
    -471,  -471,  -471,    17,  -471,  -471,   -39,  -471,  -471,  -471,
    -210,  -471,  -205,     6,  -148,  -149,  -471,  -471,  -471,  -471,
    -471,  -290,  -471,  -471,  -471,  -471,  -471,  -471,    -9,  -471,
    -471,  -471,    41,  -471,    57,    59,    81,  -161,    33,  -471,
    -471
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yydefgoto_[] =
  {
        -1,     1,     2,     9,    20,    21,    48,    66,    50,    51,
      42,    43,    86,    87,   101,    95,    44,     5,     6,    10,
       7,    23,    77,    99,   223,   305,   224,   303,   304,   329,
     330,   386,   387,   388,   389,    67,   107,   127,   140,   141,
     142,   143,   128,   129,   146,   147,   169,   220,   297,   148,
     203,   204,   170,   213,   214,   221,   371,   372,   373,   374,
     375,   298,   380,   382,   299,   300,   173,   230,   541,   510,
     530,   477,   174,   414,   175,   542,   150,   171,   225,   226,
     227,   403,   475,   404,   307,   228,   309,   310,   405,   406,
     471,   407,   469,   502,   536,   408,   470,   503,   409,   472,
     505,   410,   411,   476,   539,   553,   529,   412,   215,   216,
     291,   500,   367,   516,   493,   322,   271,   272,   448,    98,
     106,   116,   117,   134,   135,   229,   138,   136,   152,   415,
     416,   314,   232,   159,   160,   177,   316,   233,   178,   153,
     119,   120,   131,   121,   122,   123,   162,   179,   124,   154,
     244,   105,   245,   246,   425,   331,   247,   427,   332,   248,
     249,   341,   342,   250,   251,   438,   444,   490,   439,   343,
     252,   344,   253,   254,   255,   256,   268,   208,   523,   209,
     210,   257,   513,   481,   549,   550,   258,   346,   259,    81,
      82,    83,   260,    71,    72,    73,   261,    32,   262,    40,
      76
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int MapSetParser::yytable_ninf_ = -236;
  const short int
  MapSetParser::yytable_[] =
  {
        26,   103,   276,    31,    33,    34,    35,   376,   413,   435,
     161,    69,   205,   266,   393,   139,   442,    78,   207,   218,
     217,   269,    79,    68,   118,   163,   161,   289,   125,   158,
     524,   165,    84,   436,   437,   161,   311,     3,   514,   535,
      69,     4,   164,   531,   126,   515,   515,     8,   205,    39,
     181,   118,    68,    75,   207,    80,   419,   420,   164,   443,
     100,    70,   421,    22,   218,   217,   508,   164,   509,    92,
      27,    28,    29,    30,   347,    57,    58,    59,    60,    61,
      62,    41,    75,    90,   376,   104,   102,    69,    49,    45,
      70,    46,    47,    85,   267,   104,    91,    69,   393,    94,
     130,    74,   270,   486,    36,    37,    38,    96,   290,   323,
     324,   325,    93,   327,    97,   473,   151,    24,    25,   108,
     155,   109,   104,   132,    69,   155,   104,   155,    69,    75,
      74,    27,    28,    29,    30,    24,    25,    70,   133,    75,
     295,   296,   104,   137,    69,   218,   217,    70,   145,   390,
     149,   104,   167,    69,   168,   392,   206,   176,   144,   172,
     104,   231,    69,   219,   156,   263,    75,   301,   302,   156,
      75,   156,   144,   264,    70,   506,   265,    74,    70,    36,
      37,    38,   515,   548,    24,    25,    75,    74,   161,    36,
      37,    38,   206,   273,    70,    75,   526,   527,   398,   399,
     211,   211,   274,    70,    75,   333,   334,   335,   336,   337,
     338,   275,    70,   277,    74,   339,   340,   278,    74,   312,
     164,  -171,   218,   217,   294,   465,   487,   488,   400,   401,
     279,   402,   280,   390,    74,   182,   211,   491,   492,   392,
     317,   318,   319,    74,   281,   308,   211,   282,   283,   284,
     285,   286,    74,   218,   217,   287,   306,   320,   328,   321,
     183,   313,   184,   185,   186,   187,   188,   189,   190,   191,
     359,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   504,   377,   315,   326,   366,   507,   368,   378,
     161,   379,   296,   391,   295,   394,   126,   104,   426,    69,
     423,   424,   155,   434,   104,   445,    69,   446,    36,    37,
      38,   447,   452,    24,    25,   449,   528,   422,    36,    37,
      38,   450,   164,    24,    25,   451,   453,   211,   454,   455,
     456,   457,   458,   459,   460,   461,   212,   211,   537,   511,
     474,    75,   512,   462,   518,   395,   156,   552,    75,    70,
     428,   429,   430,   431,   432,   433,    70,   517,   519,   520,
     377,   521,   515,   525,   558,   534,   551,   538,   557,    89,
     559,   292,   501,   467,   556,   397,    88,   391,   166,   394,
     468,   288,   464,   383,   293,   396,   381,   555,   345,    74,
     522,   478,   157,   -20,   418,   417,    74,   484,   560,   489,
     440,   485,   441,     0,   211,     0,   104,     0,    69,    11,
      12,    13,    14,    15,    16,    17,    18,     0,    19,     0,
       0,   211,     0,   348,   349,   350,     0,     0,   351,   395,
       0,     0,   352,   353,   354,   211,   355,   356,   357,   358,
       0,   360,   361,   362,   363,   364,   365,     0,     0,     0,
      75,     0,     0,     0,     0,     0,     0,     0,    70,     0,
       0,     0,     0,     0,   104,     0,    69,     0,     0,   396,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    27,    28,    29,    30,    36,    37,    38,    63,    64,
       0,   155,   155,    65,     0,     0,     0,     0,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,    70,     0,     0,   543,
       0,   544,     0,     0,     0,     0,   463,     0,     0,     0,
     543,     0,   544,     0,     0,   156,   156,     0,     0,     0,
       0,     0,     0,     0,   466,   369,   370,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,     0,   212,     0,
       0,     0,     0,   547,     0,     0,     0,     0,     0,     0,
       0,   545,     0,     0,   547,     0,     0,     0,   480,   482,
     483,     0,   545,   183,     0,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,     0,   479,     0,   494,   495,
     496,   546,     0,   497,     0,     0,   498,     0,     0,     0,
       0,   499,   546,     0,     0,     0,   212,     0,     0,     0,
       0,    36,    37,    38,     0,     0,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   234,   235,     0,
     236,   183,     0,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,     0,   532,     0,   533,   237,   238,   239,
     240,   241,   242,   243,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    27,    28,    29,    30,    36,
      37,    38,   384,     0,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   385,     0,     0,     0,     0,     0,   222,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   110,   111,
     112,   113,   114,     0,     0,     0,  -235,   183,     0,   184,
     185,   186,   187,   188,   189,   190,   191,   115,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,     0,
       0,     0,     0,   237,   238,   239,   240,   241,   242,   243,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    27,    28,    29,    30,    36,    37,    38,     0,     0,
      24,    25,     0,     0,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    27,    28,    29,    30,    36,
      37,    38,    63,    64,    24,    25,     0,    65,   110,   111,
     112,   113,   114,     0,     0,     0,  -235,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   115,     0,     0,
       0,     0,   110,   111,   112,   113,   114,     0,     0,     0,
       0,   180,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   115,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    27,    28,    29,    30,    36,
      37,    38,    63,    64,    24,    25,   540,    65,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    27,
      28,    29,    30,    36,    37,    38,    63,    64,    24,    25,
       0,    65,   110,   111,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   115,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    27,    28,    29,    30,    36,    37,    38,
       0,     0,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    27,
      28,    29,    30,    36,    37,    38,    63,    64,    24,    25,
     212,    65,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   234,   235,     0,   236,   183,     0,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,     0,     0,     0,
       0,   237,   238,   239,   240,   241,   242,   243,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    27,
      28,    29,    30,    36,    37,    38,   212,     0,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,     0,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,     0,     0,     0,     0,   237,   238,   239,
     240,   241,   242,   243,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    27,    28,    29,    30,    36,
      37,    38,   385,     0,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   554,   540,   183,     0,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,     0,
       0,     0,     0,   237,   238,   239,   240,   241,   242,   243,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    27,    28,    29,    30,    36,    37,    38,     0,   212,
      24,    25,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    27,    28,    29,    30,    36,    37,    38,
       0,     0,    24,    25,   183,     0,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    27,    28,    29,
      30,    36,    37,    38,    63,    64,    24,    25,     0,    65,
       0,     0,    36,    37,    38,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    27,    28,    29,    30,
      36,    37,    38,    63,    64,     0,     0,     0,    65
  };

  /* YYCHECK.  */
  const short int
  MapSetParser::yycheck_[] =
  {
        11,    96,   191,    12,    13,    14,    15,   294,   308,   340,
     137,    20,   167,    41,   304,    25,    21,    26,   167,   168,
     168,    41,    88,    20,   106,   137,   153,    41,    24,   136,
     500,   138,    41,    62,    63,   162,    38,     0,    42,    42,
      49,    17,   137,   513,    40,    49,    49,   114,   203,    16,
     162,   133,    49,    20,   203,   121,   320,   321,   153,    64,
      39,    20,   326,    18,   213,   213,    39,   162,    41,    78,
     110,   111,   112,   113,   263,   104,   105,   106,   107,   108,
     109,    52,    49,    22,   371,    96,    95,    96,    38,    11,
      49,    13,    14,    38,   122,   106,   115,   106,   388,    53,
     109,    20,   122,   434,   114,   115,   116,    39,   122,   239,
     240,   241,    79,   243,    38,   402,    51,   119,   120,   114,
     131,    44,   133,    39,   133,   136,   137,   138,   137,    96,
      49,   110,   111,   112,   113,   119,   120,    96,    44,   106,
      30,    31,   153,    41,   153,   294,   294,   106,    90,   304,
      38,   162,    27,   162,    91,   304,   167,    53,   125,    32,
     171,   172,   171,    26,   131,    75,   133,    19,    20,   136,
     137,   138,   139,    41,   133,   475,    41,    96,   137,   114,
     115,   116,    49,    50,   119,   120,   153,   106,   315,   114,
     115,   116,   203,    41,   153,   162,   502,   503,    15,    16,
     167,   168,    41,   162,   171,    56,    57,    58,    59,    60,
      61,    41,   171,    41,   133,    66,    67,    41,   137,   230,
     315,    38,   371,   371,    27,   373,   436,   437,    45,    46,
      41,    48,    41,   388,   153,    41,   203,   442,   443,   388,
     234,   235,   236,   162,    41,    44,   213,    41,    41,    41,
      41,    41,   171,   402,   402,    41,    39,    41,    89,    41,
      66,    50,    68,    69,    70,    71,    72,    73,    74,    75,
     281,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,   471,   294,    49,    41,    19,   476,    42,   101,
     417,   101,    31,   304,    30,   304,    40,   308,    55,   308,
      42,    54,   313,    67,   315,    42,   315,    42,   114,   115,
     116,    42,    42,   119,   120,    49,   505,   328,   114,   115,
     116,    49,   417,   119,   120,    49,    42,   294,    49,    42,
      42,    49,    42,    42,    42,    42,    41,   304,   527,    42,
      44,   308,    42,    49,    42,   304,   313,   536,   315,   308,
     333,   334,   335,   336,   337,   338,   315,    49,    42,    42,
     371,    42,    49,    42,   553,    42,    42,    47,    42,    51,
      56,   212,   466,   388,    76,   305,    49,   388,   139,   388,
     397,   203,   371,   300,   213,   304,   299,   541,   262,   308,
     499,   417,   133,    22,   315,   313,   315,   424,   559,   438,
     343,   426,   343,    -1,   371,    -1,   417,    -1,   417,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    -1,
      -1,   388,    -1,   264,   265,   266,    -1,    -1,   269,   388,
      -1,    -1,   273,   274,   275,   402,   277,   278,   279,   280,
      -1,   282,   283,   284,   285,   286,   287,    -1,    -1,    -1,
     417,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   417,    -1,
      -1,    -1,    -1,    -1,   475,    -1,   475,    -1,    -1,   388,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
      -1,   502,   503,   122,    -1,    -1,    -1,    -1,   417,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   475,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   475,    -1,    -1,   530,
      -1,   530,    -1,    -1,    -1,    -1,   367,    -1,    -1,    -1,
     541,    -1,   541,    -1,    -1,   502,   503,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   385,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   475,    -1,    41,    -1,
      -1,    -1,    -1,   530,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   530,    -1,    -1,   541,    -1,    -1,    -1,   419,   420,
     421,    -1,   541,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    21,    -1,   449,   450,
     451,   530,    -1,   454,    -1,    -1,   457,    -1,    -1,    -1,
      -1,   462,   541,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      -1,   114,   115,   116,    -1,    -1,   119,   120,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,   515,    -1,   517,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,    21,    -1,   119,   120,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    41,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    52,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    -1,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,    -1,    -1,
     119,   120,    -1,    -1,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,   122,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    43,   122,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,   122,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
      -1,    -1,   119,   120,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      41,   122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    -1,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    -1,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    -1,    -1,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    41,    -1,   119,   120,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,    41,    -1,   119,   120,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    -1,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    -1,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,    -1,    41,
     119,   120,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
      -1,    -1,   119,   120,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    -1,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,   122,
      -1,    -1,   114,   115,   116,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    -1,    -1,    -1,   122
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  MapSetParser::yystos_[] =
  {
         0,   124,   125,     0,    17,   140,   141,   143,   114,   126,
     142,     3,     4,     5,     6,     7,     8,     9,    10,    12,
     127,   128,    18,   144,   119,   120,   273,   110,   111,   112,
     113,   311,   320,   311,   311,   311,   114,   115,   116,   321,
     322,    52,   133,   134,   139,    11,    13,    14,   129,    38,
     131,   132,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   117,   118,   122,   130,   158,   274,   311,
     315,   316,   317,   318,   319,   321,   323,   145,   311,    88,
     121,   312,   313,   314,   311,    38,   135,   136,   130,   131,
      22,   115,   311,   321,    53,   138,    39,    38,   242,   146,
      39,   137,   311,   271,   273,   274,   243,   159,   114,    44,
      33,    34,    35,    36,    37,    52,   244,   245,   248,   263,
     264,   266,   267,   268,   271,    24,    40,   160,   165,   166,
     311,   265,    39,    44,   246,   247,   250,    41,   249,    25,
     161,   162,   163,   164,   321,    90,   167,   168,   172,    38,
     199,    51,   251,   262,   272,   273,   321,   244,   251,   256,
     257,   263,   269,   270,   271,   251,   164,    27,    91,   169,
     175,   200,    32,   189,   195,   197,    53,   258,   261,   270,
      42,   270,    41,    66,    68,    69,    70,    71,    72,    73,
      74,    75,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,   173,   174,   232,   273,   298,   300,   302,
     303,   321,    41,   176,   177,   231,   232,   297,   298,    26,
     170,   178,    23,   147,   149,   201,   202,   203,   208,   248,
     190,   273,   255,   260,    62,    63,    65,    92,    93,    94,
      95,    96,    97,    98,   273,   275,   276,   279,   282,   283,
     286,   287,   293,   295,   296,   297,   298,   304,   309,   311,
     315,   319,   321,    75,    41,    41,    41,   122,   299,    41,
     122,   239,   240,    41,    41,    41,   199,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,   174,    41,
     122,   233,   275,   177,    27,    30,    31,   171,   184,   187,
     188,    19,    20,   150,   151,   148,    39,   207,    44,   209,
     210,    38,   273,    50,   254,    49,   259,   296,   296,   296,
      41,    41,   238,   238,   238,   238,    41,   238,    89,   152,
     153,   278,   281,    56,    57,    58,    59,    60,    61,    66,
      67,   284,   285,   292,   294,   233,   310,   199,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   273,
     275,   275,   275,   275,   275,   275,    19,   235,    42,    28,
      29,   179,   180,   181,   182,   183,   231,   273,   101,   101,
     185,   188,   186,   187,    21,    41,   154,   155,   156,   157,
     232,   273,   298,   304,   311,   315,   319,   165,    15,    16,
      45,    46,    48,   204,   206,   211,   212,   214,   218,   221,
     224,   225,   230,   203,   196,   252,   253,   262,   261,   235,
     235,   235,   273,    42,    54,   277,    55,   280,   286,   286,
     286,   286,   286,   286,    67,   239,    62,    63,   288,   291,
     317,   318,    21,    64,   289,    42,    42,    42,   241,    49,
      49,    49,    42,    42,    49,    42,    42,    49,    42,    42,
      42,    42,    49,   275,   180,   297,   275,   155,   167,   215,
     219,   213,   222,   231,    44,   205,   226,   194,   258,    21,
     275,   306,   275,   275,   279,   282,   239,   293,   293,   289,
     290,   295,   295,   237,   275,   275,   275,   275,   275,   275,
     234,   153,   216,   220,   199,   223,   203,   199,    39,    41,
     192,    42,    42,   305,    42,    49,   236,    49,    42,    42,
      42,    42,   236,   301,   237,    42,   272,   272,   199,   229,
     193,   237,   275,   275,    42,    42,   217,   199,    47,   227,
      43,   191,   198,   273,   311,   315,   319,   321,    50,   307,
     308,    42,   199,   228,    42,   198,    76,    42,   199,    56,
     320
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
     375,   376,   377
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  MapSetParser::yyr1_[] =
  {
         0,   123,   125,   124,   126,   126,   127,   127,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   129,   129,   129,
     130,   130,   131,   132,   132,   133,   134,   134,   135,   135,
     136,   137,   138,   138,   139,   140,   141,   141,   142,   142,
     143,   145,   146,   144,   148,   147,   149,   150,   150,   151,
     151,   152,   153,   153,   154,   155,   155,   155,   155,   155,
     155,   155,   155,   156,   156,   157,   157,   158,   159,   159,
     160,   161,   161,   162,   163,   164,   165,   166,   166,   167,
     168,   168,   169,   169,   170,   170,   171,   171,   172,   173,
     173,   174,   174,   174,   174,   175,   176,   176,   177,   178,
     179,   179,   180,   180,   181,   181,   182,   183,   183,   184,
     184,   185,   185,   186,   186,   187,   188,   189,   190,   190,
     191,   191,   193,   192,   194,   194,   196,   195,   197,   197,
     198,   198,   198,   198,   198,   198,   200,   199,   201,   201,
     202,   203,   203,   204,   204,   205,   205,   206,   207,   207,
     208,   209,   210,   210,   211,   211,   211,   211,   211,   213,
     212,   215,   216,   217,   214,   219,   220,   218,   222,   223,
     221,   225,   226,   224,   228,   227,   229,   229,   230,   231,
     231,   231,   232,   233,   234,   233,   235,   235,   236,   237,
     237,   238,   239,   240,   241,   240,   243,   242,   244,   244,
     245,   246,   247,   247,   249,   248,   250,   248,   251,   252,
     253,   253,   254,   255,   255,   256,   257,   257,   258,   259,
     260,   260,   261,   262,   262,   263,   263,   265,   264,   266,
     267,   267,   267,   267,   267,   268,   268,   269,   269,   270,
     270,   271,   271,   272,   272,   273,   273,   274,   274,   274,
     274,   274,   274,   275,   276,   277,   278,   278,   279,   280,
     281,   281,   282,   283,   284,   284,   285,   285,   285,   285,
     285,   285,   285,   285,   286,   287,   288,   288,   289,   289,
     290,   290,   291,   291,   291,   292,   292,   293,   294,   294,
     295,   295,   295,   295,   296,   296,   296,   296,   296,   296,
     296,   296,   297,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   299,   299,   300,   301,   301,   302,   303,
     304,   304,   304,   304,   304,   304,   305,   304,   306,   306,
     307,   308,   308,   309,   310,   310,   311,   312,   313,   313,
     314,   314,   315,   315,   315,   316,   316,   316,   317,   317,
     317,   318,   318,   318,   319,   319,   320,   320,   320,   320,
     321,   321,   322,   322,   323,   323
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  MapSetParser::yyr2_[] =
  {
         0,     2,     0,     4,     0,     2,     0,     2,     4,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       0,     1,     4,     1,     2,     2,     0,     1,     0,     1,
       3,     3,     0,     2,     3,     2,     0,     1,     0,     2,
       2,     0,     0,     5,     0,     4,     3,     1,     1,     0,
       1,     2,     0,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     6,     0,     2,
       2,     1,     1,     1,     2,     1,     3,     0,     1,     4,
       0,     1,     0,     1,     0,     1,     0,     1,     3,     1,
       2,     1,     1,     4,     1,     2,     1,     2,     1,     3,
       1,     2,     1,     1,     1,     1,     2,     1,     1,     2,
       2,     0,     1,     0,     1,     2,     2,     1,     1,     2,
       1,     2,     0,     4,     0,     2,     0,     6,     0,     1,
       1,     1,     1,     1,     1,     1,     0,     4,     1,     1,
       2,     0,     1,     1,     1,     0,     1,     3,     0,     2,
       2,     2,     0,     1,     1,     1,     1,     1,     1,     0,
       3,     0,     0,     0,     6,     0,     0,     5,     0,     0,
       4,     0,     0,     4,     0,     3,     0,     2,     2,     1,
       1,     1,     2,     1,     0,     6,     0,     1,     2,     0,
       2,     4,     1,     1,     0,     5,     0,     4,     0,     1,
       2,     2,     0,     1,     0,     3,     0,     3,     3,     2,
       0,     1,     2,     0,     2,     1,     0,     1,     2,     2,
       0,     2,     1,     1,     1,     1,     1,     0,     4,     4,
       1,     1,     1,     1,     1,     0,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     0,     2,     2,     2,
       0,     2,     1,     2,     0,     1,     2,     2,     2,     2,
       2,     2,     2,     3,     1,     2,     1,     1,     2,     2,
       0,     1,     2,     2,     2,     0,     2,     2,     0,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     4,     6,     4,     4,     4,     4,
       2,     2,     8,     6,     6,     6,     4,     4,     4,     4,
       1,     1,     1,     3,     1,     7,     0,     1,     2,     3,
       5,     2,     2,     2,     2,     2,     0,     8,     1,     1,
       4,     0,     1,     2,     0,     1,     2,     2,     1,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
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
  "$accept", "MapSet", "$@1", "_QAccessParm_E_Star",
  "_QConstructQuery_E_Star", "AccessParm",
  "_O_QIT_PROMISCUOUS_E_Or_QIT_VARNAMES_E_Or_QIT_DRACONIAN_E_C",
  "_QGraphTerm_E_Opt",
  "_O_QGT_LCURLEY_E_S_QGraphTerm_E_Opt_S_QGT_RCURLEY_E_S_QVarOrTerm_E_C",
  "_Q_O_QGT_LCURLEY_E_S_QGraphTerm_E_Opt_S_QGT_RCURLEY_E_S_QVarOrTerm_E_C_E_Plus",
  "PrimaryKeySpec", "_QDefaultPrimaryKey_E_Opt", "_QPrimaryKeySet_E_Opt",
  "PrimaryKeySet", "_O_QRDFLiteral_E_S_QGT_DOT_E_S_QRDFLiteral_E_C",
  "_Q_O_QRDFLiteral_E_S_QGT_DOT_E_S_QRDFLiteral_E_C_E_Star",
  "DefaultPrimaryKey", "Prologue", "_QBaseDecl_E_Opt",
  "_QPrefixDecl_E_Star", "BaseDecl", "PrefixDecl", "$@2", "$@3",
  "SubSelect", "@4", "SelectClause",
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
  "_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_C", "$@5",
  "_Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_C_E_Star",
  "_O_QIT_BINDINGS_E_S_QVar_E_Plus_S_QGT_LCURLEY_E_S_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Star_S_QGT_RCURLEY_E_C",
  "$@6",
  "_Q_O_QIT_BINDINGS_E_S_QVar_E_Plus_S_QGT_LCURLEY_E_S_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Star_S_QGT_RCURLEY_E_C_E_Opt",
  "BindingValue", "GroupGraphPattern", "$@7",
  "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C", "GroupGraphPatternSub",
  "_QTriplesBlock_E_Opt", "_O_QGraphPatternNotTriples_E_Or_QFilter_E_C",
  "_QGT_DOT_E_Opt",
  "_O_QGraphPatternNotTriples_E_Or_QFilter_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_Or_QFilter_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "OptionalGraphPattern", "@8", "GraphGraphPattern", "@9", "@10", "@11",
  "ServiceGraphPattern", "@12", "@13", "MinusGraphPattern", "@14", "@15",
  "GroupOrUnionGraphPattern", "@16", "@17",
  "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@18",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "$@19", "_QIT_DISTINCT_E_Opt",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ExprAggArg",
  "ExpressionList",
  "_O_QNIL_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QGT_COMMA_E_S_QExpression_E_Star_S_QGT_RPAREN_E_C",
  "$@20", "ConstructTemplate", "$@21", "_QConstructTriples_E_Opt",
  "ConstructTriples", "_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C_E_Opt", "TriplesSameSubject",
  "$@22", "$@23", "PropertyListNotEmpty", "_O_QVerb_E_S_QObjectList_E_C",
  "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "Verb", "TriplesNode", "BlankNodePropertyList", "@24",
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
  "ExistsFunc", "NotExistsFunc", "Aggregate", "$@25",
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
       124,     0,    -1,    -1,   125,   140,   126,   127,    -1,    -1,
     126,   128,    -1,    -1,   127,   158,    -1,     3,   273,   311,
     311,    -1,     4,   311,    -1,     5,   311,    -1,     6,   311,
      -1,     7,   311,    -1,     8,   321,    -1,     9,   133,    -1,
      10,   129,    -1,    12,   132,    -1,    11,    -1,    14,    -1,
      13,    -1,    -1,   274,    -1,    38,   130,    39,   271,    -1,
     131,    -1,   132,   131,    -1,   134,   135,    -1,    -1,   139,
      -1,    -1,   136,    -1,    38,   138,    39,    -1,   311,    44,
     311,    -1,    -1,   138,   137,    -1,    52,   311,    53,    -1,
     141,   142,    -1,    -1,   143,    -1,    -1,   142,   144,    -1,
      17,   114,    -1,    -1,    -1,    18,   145,   115,   146,   114,
      -1,    -1,   149,   148,   165,   167,    -1,    23,   151,   157,
      -1,    19,    -1,    20,    -1,    -1,   150,    -1,    89,   273,
      -1,    -1,   152,    -1,    41,   275,   153,    42,    -1,   273,
      -1,   304,    -1,   298,    -1,   232,    -1,   311,    -1,   315,
      -1,   319,    -1,   154,    -1,   155,    -1,   156,   155,    -1,
     156,    -1,    21,    -1,   130,    22,   242,   159,   165,   167,
      -1,    -1,   159,   160,    -1,    24,   161,    -1,   162,    -1,
     163,    -1,   164,    -1,    25,   164,    -1,   321,    -1,   166,
     199,   189,    -1,    -1,    40,    -1,   168,   169,   170,   171,
      -1,    -1,   172,    -1,    -1,   175,    -1,    -1,   178,    -1,
      -1,   184,    -1,    90,    27,   173,    -1,   174,    -1,   173,
     174,    -1,   298,    -1,   232,    -1,    41,   275,   153,    42,
      -1,   273,    -1,    91,   176,    -1,   177,    -1,   176,   177,
      -1,   231,    -1,    26,    27,   179,    -1,   180,    -1,   179,
     180,    -1,   182,    -1,   183,    -1,    28,    -1,    29,    -1,
     181,   297,    -1,   231,    -1,   273,    -1,   187,   185,    -1,
     188,   186,    -1,    -1,   188,    -1,    -1,   187,    -1,    30,
     101,    -1,    31,   101,    -1,   197,    -1,   273,    -1,   190,
     273,    -1,   198,    -1,   191,   198,    -1,    -1,    41,   193,
     191,    42,    -1,    -1,   194,   192,    -1,    -1,    32,   190,
      38,   196,   194,    39,    -1,    -1,   195,    -1,   321,    -1,
     311,    -1,   315,    -1,   319,    -1,    43,    -1,   273,    -1,
      -1,    38,   200,   201,    39,    -1,   147,    -1,   202,    -1,
     203,   207,    -1,    -1,   208,    -1,   211,    -1,   230,    -1,
      -1,    44,    -1,   204,   205,   203,    -1,    -1,   207,   206,
      -1,   248,   210,    -1,    44,   203,    -1,    -1,   209,    -1,
     212,    -1,   221,    -1,   224,    -1,   214,    -1,   218,    -1,
      -1,    45,   213,   199,    -1,    -1,    -1,    -1,    15,   215,
     216,   272,   217,   199,    -1,    -1,    -1,    16,   219,   220,
     272,   199,    -1,    -1,    -1,    46,   222,   223,   199,    -1,
      -1,    -1,   225,   226,   199,   229,    -1,    -1,    47,   228,
     199,    -1,    -1,   229,   227,    -1,    48,   231,    -1,   297,
      -1,   298,    -1,   232,    -1,   321,   233,    -1,   122,    -1,
      -1,    41,   235,   275,   234,   237,    42,    -1,    -1,    19,
      -1,    49,   275,    -1,    -1,   237,   236,    -1,    41,   235,
     275,    42,    -1,   240,    -1,   122,    -1,    -1,    41,   275,
     241,   237,    42,    -1,    -1,    38,   243,   244,    39,    -1,
      -1,   245,    -1,   248,   247,    -1,    44,   244,    -1,    -1,
     246,    -1,    -1,   271,   249,   251,    -1,    -1,   263,   250,
     256,    -1,   262,   258,   255,    -1,   262,   258,    -1,    -1,
     252,    -1,    50,   253,    -1,    -1,   255,   254,    -1,   257,
      -1,    -1,   251,    -1,   261,   260,    -1,    49,   261,    -1,
      -1,   260,   259,    -1,   270,    -1,   272,    -1,    51,    -1,
     266,    -1,   264,    -1,    -1,    52,   265,   251,    53,    -1,
     268,    41,   269,    42,    -1,    33,    -1,    34,    -1,    35,
      -1,    36,    -1,    37,    -1,    -1,   267,    -1,   270,    -1,
     269,   270,    -1,   271,    -1,   263,    -1,   273,    -1,   274,
      -1,   273,    -1,   321,    -1,   119,    -1,   120,    -1,   321,
      -1,   311,    -1,   315,    -1,   319,    -1,   323,    -1,   122,
      -1,   276,    -1,   279,   278,    -1,    54,   279,    -1,    -1,
     278,   277,    -1,   282,   281,    -1,    55,   282,    -1,    -1,
     281,   280,    -1,   283,    -1,   286,   284,    -1,    -1,   285,
      -1,    56,   286,    -1,    57,   286,    -1,    58,   286,    -1,
      59,   286,    -1,    60,   286,    -1,    61,   286,    -1,    67,
     239,    -1,    66,    67,   239,    -1,   287,    -1,   293,   292,
      -1,   317,    -1,   318,    -1,    21,   295,    -1,    64,   295,
      -1,    -1,   289,    -1,    62,   293,    -1,    63,   293,    -1,
     288,   290,    -1,    -1,   292,   291,    -1,   295,   294,    -1,
      -1,   294,   289,    -1,    65,   296,    -1,    62,   296,    -1,
      63,   296,    -1,   296,    -1,   297,    -1,   298,    -1,   309,
      -1,   311,    -1,   315,    -1,   319,    -1,   273,    -1,   304,
      -1,    41,   275,    42,    -1,    77,    41,   275,    42,    -1,
      78,    41,   275,    42,    -1,    79,    41,   275,    49,   275,
      42,    -1,    80,    41,   275,    42,    -1,    81,    41,   273,
      42,    -1,    68,    41,   275,    42,    -1,    69,    41,   275,
      42,    -1,    70,   299,    -1,    71,   239,    -1,    72,    41,
     275,    49,   275,    49,   275,    42,    -1,    73,    41,   275,
      49,   275,    42,    -1,    74,    41,   275,    49,   275,    42,
      -1,    82,    41,   275,    49,   275,    42,    -1,    83,    41,
     275,    42,    -1,    84,    41,   275,    42,    -1,    85,    41,
     275,    42,    -1,    86,    41,   275,    42,    -1,   300,    -1,
     302,    -1,   303,    -1,    41,   275,    42,    -1,   122,    -1,
      87,    41,   275,    49,   275,   301,    42,    -1,    -1,   236,
      -1,    75,   199,    -1,    66,    75,   199,    -1,    92,    41,
     235,   306,    42,    -1,    93,   238,    -1,    94,   238,    -1,
      95,   238,    -1,    96,   238,    -1,    98,   238,    -1,    -1,
      97,    41,   235,   275,   305,   237,   308,    42,    -1,    21,
      -1,   275,    -1,    50,    76,    56,   320,    -1,    -1,   307,
      -1,   321,   310,    -1,    -1,   233,    -1,   320,   314,    -1,
      88,   321,    -1,   121,    -1,   312,    -1,    -1,   313,    -1,
     316,    -1,   317,    -1,   318,    -1,   101,    -1,   102,    -1,
     103,    -1,   104,    -1,   105,    -1,   106,    -1,   107,    -1,
     108,    -1,   109,    -1,    99,    -1,   100,    -1,   110,    -1,
     112,    -1,   111,    -1,   113,    -1,   114,    -1,   322,    -1,
     116,    -1,   115,    -1,   117,    -1,   118,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  MapSetParser::yyprhs_[] =
  {
         0,     0,     3,     4,     9,    10,    13,    14,    17,    22,
      25,    28,    31,    34,    37,    40,    43,    46,    48,    50,
      52,    53,    55,    60,    62,    65,    68,    69,    71,    72,
      74,    78,    82,    83,    86,    90,    93,    94,    96,    97,
     100,   103,   104,   105,   111,   112,   117,   121,   123,   125,
     126,   128,   131,   132,   134,   139,   141,   143,   145,   147,
     149,   151,   153,   155,   157,   160,   162,   164,   171,   172,
     175,   178,   180,   182,   184,   187,   189,   193,   194,   196,
     201,   202,   204,   205,   207,   208,   210,   211,   213,   217,
     219,   222,   224,   226,   231,   233,   236,   238,   241,   243,
     247,   249,   252,   254,   256,   258,   260,   263,   265,   267,
     270,   273,   274,   276,   277,   279,   282,   285,   287,   289,
     292,   294,   297,   298,   303,   304,   307,   308,   315,   316,
     318,   320,   322,   324,   326,   328,   330,   331,   336,   338,
     340,   343,   344,   346,   348,   350,   351,   353,   357,   358,
     361,   364,   367,   368,   370,   372,   374,   376,   378,   380,
     381,   385,   386,   387,   388,   395,   396,   397,   403,   404,
     405,   410,   411,   412,   417,   418,   422,   423,   426,   429,
     431,   433,   435,   438,   440,   441,   448,   449,   451,   454,
     455,   458,   463,   465,   467,   468,   474,   475,   480,   481,
     483,   486,   489,   490,   492,   493,   497,   498,   502,   506,
     509,   510,   512,   515,   516,   519,   521,   522,   524,   527,
     530,   531,   534,   536,   538,   540,   542,   544,   545,   550,
     555,   557,   559,   561,   563,   565,   566,   568,   570,   573,
     575,   577,   579,   581,   583,   585,   587,   589,   591,   593,
     595,   597,   599,   601,   603,   606,   609,   610,   613,   616,
     619,   620,   623,   625,   628,   629,   631,   634,   637,   640,
     643,   646,   649,   652,   656,   658,   661,   663,   665,   668,
     671,   672,   674,   677,   680,   683,   684,   687,   690,   691,
     694,   697,   700,   703,   705,   707,   709,   711,   713,   715,
     717,   719,   721,   725,   730,   735,   742,   747,   752,   757,
     762,   765,   768,   777,   784,   791,   798,   803,   808,   813,
     818,   820,   822,   824,   828,   830,   838,   839,   841,   844,
     848,   854,   857,   860,   863,   866,   869,   870,   879,   881,
     883,   888,   889,   891,   894,   895,   897,   900,   903,   905,
     907,   908,   910,   912,   914,   916,   918,   920,   922,   924,
     926,   928,   930,   932,   934,   936,   938,   940,   942,   944,
     946,   948,   950,   952,   954,   956
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  MapSetParser::yyrline_[] =
  {
         0,   380,   380,   380,   386,   388,   392,   394,   398,   407,
     410,   413,   416,   419,   422,   424,   428,   434,   437,   440,
     446,   449,   453,   465,   466,   470,   473,   475,   478,   480,
     484,   488,   493,   495,   499,   506,   510,   512,   516,   518,
     522,   528,   530,   528,   540,   540,   549,   557,   560,   567,
     570,   575,   582,   585,   590,   597,   600,   603,   606,   609,
     612,   615,   619,   624,   627,   635,   638,   645,   654,   657,
     665,   672,   673,   677,   683,   689,   696,   703,   705,   709,
     716,   719,   724,   727,   732,   735,   740,   744,   748,   755,
     758,   765,   768,   771,   774,   780,   786,   789,   796,   801,
     808,   812,   820,   822,   830,   833,   841,   849,   850,   857,
     861,   869,   872,   877,   880,   884,   890,   898,   903,   907,
     914,   917,   923,   923,   932,   935,   942,   942,   951,   954,
     958,   961,   964,   967,   970,   973,   980,   980,   992,   993,
     998,  1002,  1004,  1009,  1010,  1014,  1016,  1021,  1025,  1028,
    1033,  1038,  1042,  1045,  1049,  1050,  1051,  1052,  1053,  1057,
    1057,  1072,  1075,  1077,  1072,  1088,  1091,  1088,  1100,  1103,
    1100,  1113,  1116,  1113,  1126,  1126,  1140,  1142,  1146,  1157,
    1158,  1159,  1163,  1171,  1175,  1175,  1184,  1187,  1194,  1200,
    1202,  1209,  1216,  1220,  1223,  1223,  1233,  1233,  1241,  1243,
    1248,  1253,  1257,  1259,  1263,  1263,  1266,  1266,  1273,  1278,
    1282,  1284,  1289,  1293,  1295,  1300,  1304,  1306,  1311,  1316,
    1320,  1322,  1326,  1333,  1337,  1344,  1345,  1349,  1349,  1362,
    1387,  1390,  1393,  1396,  1399,  1406,  1409,  1414,  1418,  1425,
    1426,  1430,  1433,  1437,  1440,  1446,  1447,  1451,  1454,  1457,
    1460,  1463,  1464,  1470,  1475,  1484,  1491,  1494,  1502,  1511,
    1518,  1521,  1528,  1533,  1543,  1546,  1551,  1554,  1557,  1560,
    1563,  1566,  1569,  1572,  1578,  1583,  1592,  1595,  1602,  1605,
    1612,  1615,  1620,  1623,  1627,  1641,  1644,  1652,  1661,  1664,
    1671,  1674,  1677,  1680,  1684,  1685,  1686,  1687,  1690,  1693,
    1696,  1699,  1703,  1709,  1712,  1715,  1718,  1721,  1724,  1727,
    1731,  1734,  1738,  1741,  1744,  1747,  1750,  1753,  1756,  1759,
    1762,  1763,  1764,  1770,  1773,  1780,  1787,  1790,  1794,  1801,
    1808,  1811,  1814,  1817,  1820,  1823,  1827,  1827,  1839,  1842,
    1846,  1852,  1855,  1859,  1869,  1872,  1877,  1885,  1892,  1896,
    1904,  1908,  1912,  1913,  1914,  1918,  1919,  1920,  1924,  1925,
    1926,  1930,  1931,  1932,  1936,  1937,  1941,  1942,  1943,  1944,
    1948,  1949,  1953,  1954,  1958,  1959
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
     115,   116,   117,   118,   119,   120,   121,   122
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int MapSetParser::yyeof_ = 0;
  const int MapSetParser::yylast_ = 1358;
  const int MapSetParser::yynnts_ = 201;
  const int MapSetParser::yyempty_ = -2;
  const int MapSetParser::yyfinal_ = 3;
  const int MapSetParser::yyterror_ = 1;
  const int MapSetParser::yyerrcode_ = 256;
  const int MapSetParser::yyntokens_ = 123;

  const unsigned int MapSetParser::yyuser_token_number_max_ = 377;
  const MapSetParser::token_number_type MapSetParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 3943 "lib/MapSetParser/MapSetParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 1965 "lib/MapSetParser/MapSetParser.ypp"
 /*** Additional Code ***/

void w3c_sw::MapSetParser::error(const MapSetParser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

/* START Driver (@@ stand-alone would allow it to be shared with other parsers */

namespace w3c_sw {

    MapSetDriver::MapSetDriver (std::string baseURI, AtomFactory* atomFactory) : 
	YaccDriver(baseURI, atomFactory), curSubject(NULL), curPredicate(NULL), 
	curBGP(NULL), curFilter(NULL), curOp(NULL), 
	curBindingsClause(NULL), curBinding(NULL), curExprList(NULL), 
	root(NULL), lastRuleTerm(TTerm::Unbound, TTerm::Unbound),
	lastRuleTermSet(false)
{
}

    MapSetDriver::~MapSetDriver ()
{
}

MapSet* MapSetDriver::parse (IStreamContext& in)
{
    sharedVarsSet = false;
    streamname = in.nameStr;

    MapSetScanner scanner(this, in.p);
    scanner.set_debug(trace_scanning);
    lexer = &scanner;

    MapSetParser parser(*this);
    parser.set_debug_level(trace_parsing);
    // !!! Clear out namespaces!
    ignorePrefixFlag = false;
    parser.parse();
    return root;
}

MapSet* MapSetDriver::parse (std::string queryStr)
{
    IStreamContext in(queryStr.c_str(), IStreamContext::STRING);
    return parse(in);
}

} // namespace w3c_sw

/* END Driver */


