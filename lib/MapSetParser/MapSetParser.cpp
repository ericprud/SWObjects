
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
#line 379 "lib/MapSetParser/MapSetParser.ypp"

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
#line 394 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root = new MapSet();
	driver.root->sharedVars = MapSet::e_PROMISCUOUS;
      }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 412 "lib/MapSetParser/MapSetParser.ypp"
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
#line 421 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->driver = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 424 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->server = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 427 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->user = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 430 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->password = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 433 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->database = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 436 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->stemURI = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 441 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.sharedVarsSet = true;
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 445 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.lastRuleTermSet = false;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 451 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_PROMISCUOUS;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 454 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_VARNAMES;
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 457 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_DRACONIAN;
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 463 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = NULL;
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 470 "lib/MapSetParser/MapSetParser.ypp"
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

  case 32:

/* Line 678 of lalr1.cc  */
#line 505 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->keyMap[(yysemantic_stack_[(3) - (1)].p_RDFLiteral)->getLexicalValue()] = (yysemantic_stack_[(3) - (3)].p_RDFLiteral)->getLexicalValue();
    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 516 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->primaryKey = (yysemantic_stack_[(3) - (2)].p_RDFLiteral);
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 539 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 545 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 547 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 549 "lib/MapSetParser/MapSetParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 557 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 560 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 568 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 571 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yysemantic_stack_[(5) - (3)].p_WhereClause)->m_BindingClause = (yysemantic_stack_[(5) - (5)].p_BindingsClause);
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(5) - (1)].p_Project).distinctness, (yysemantic_stack_[(5) - (1)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(5) - (3)].p_WhereClause), (yysemantic_stack_[(5) - (4)].p_SolutionModifier))));
      }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 579 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 587 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 590 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 597 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 605 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 612 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 620 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 627 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 630 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 633 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 636 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 639 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 642 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 645 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 654 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 657 "lib/MapSetParser/MapSetParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 665 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 668 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 674 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = NULL;
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 677 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (2)].p_TTerm);
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 684 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(7) - (5)].p_WhereClause)->m_BindingClause = (yysemantic_stack_[(7) - (7)].p_BindingsClause);
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	Construct* constr = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(7) - (3)].p_BasicGraphPattern), (yysemantic_stack_[(7) - (4)].p_DatasetClauses), (yysemantic_stack_[(7) - (5)].p_WhereClause), (yysemantic_stack_[(7) - (6)].p_SolutionModifier));
	driver.root->maps.push_back(LabeledConstruct((yysemantic_stack_[(7) - (1)].p_TTerm), constr));
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 694 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 706 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 712 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 718 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 725 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp ? driver.curOp : new DefaultGraphPattern(), NULL);
	driver.curOp = NULL;
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 739 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 746 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 754 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 762 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 770 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 778 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 785 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 788 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 795 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 798 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 801 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 804 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 810 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 816 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 819 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 831 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 838 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 842 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 852 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 860 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 863 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 871 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 880 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 887 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 891 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 899 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 907 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 914 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 920 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 933 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTermList) = new TTermList;
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 936 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTermList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_TTermList) = (yysemantic_stack_[(2) - (1)].p_TTermList);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 943 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 946 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 952 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding = new Binding();
      }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 954 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BindingValue) = driver.curBinding;
	  driver.curBinding = NULL;
      }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 958 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding = new Binding();
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 964 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 967 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBindingsClause->push_back((yysemantic_stack_[(2) - (2)].p_BindingValue));
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 974 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBindingsClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_TTermList));
      }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 976 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BindingsClause) = driver.curBindingsClause;
	  driver.curBindingsClause = NULL;
      }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 983 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BindingsClause) = NULL;
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 990 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 993 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 996 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 999 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1002 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1005 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1018 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1021 "lib/MapSetParser/MapSetParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 1101 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 1104 "lib/MapSetParser/MapSetParser.ypp"
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

  case 165:

/* Line 678 of lalr1.cc  */
#line 1116 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1119 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1121 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1124 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1132 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1135 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 1137 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(5) - (4)].p_TTerm), driver.curOp, driver.atomFactory, false));
      }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 1144 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = new Bind(driver.curOp, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 1150 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1153 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 1155 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.curOp));
      }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 1163 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 1166 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 1168 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 1176 "lib/MapSetParser/MapSetParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 1181 "lib/MapSetParser/MapSetParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 1196 "lib/MapSetParser/MapSetParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    if (driver.curOp == NULL)
		driver.ensureBasicGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 1213 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 1221 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 1225 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 1227 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = NULL;
      }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 1234 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 1237 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 1244 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1252 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1266 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1269 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1271 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 1279 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 1281 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 1309 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 1312 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 1372 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 1379 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 1383 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 1391 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 1394 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 1400 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 1411 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 1439 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 1466 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 1473 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 1484 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 1491 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 1527 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 1530 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 1533 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 1536 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 1594 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 1598 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 1607 "lib/MapSetParser/MapSetParser.ypp"
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

  case 297:

/* Line 678 of lalr1.cc  */
#line 1632 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 1635 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 1638 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 1641 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 1644 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 1651 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 1659 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 1663 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 1675 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 1682 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 1685 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 1696 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 1699 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 1702 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 1705 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 1709 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 1720 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 1729 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 1736 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 1739 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 1747 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 1756 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 1763 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 1766 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 1778 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_GeneralComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_GeneralComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_GeneralComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 1789 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 1796 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 1799 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 1802 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 1805 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 1808 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 1811 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 1814 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 1817 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 1828 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 1837 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 1840 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 1847 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 1850 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 1857 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 1865 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 1868 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 1872 "lib/MapSetParser/MapSetParser.ypp"
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

  case 352:

/* Line 678 of lalr1.cc  */
#line 1886 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 1889 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 1897 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 1906 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 1909 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 1916 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 1919 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 1922 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 1932 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 1935 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 1938 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 1941 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 1948 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 1954 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 1957 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 1960 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 1963 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 1966 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 1969 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 1972 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 1976 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_blank, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 1979 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 1982 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 1985 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ciel, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 1988 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 1991 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 1994 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::XPATH_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 1998 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlen, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 2001 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ucase, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 2004 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lcase, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 2007 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encodeForUri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 2010 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 2013 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strStarts, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 2016 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strEnds, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 2019 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 2022 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 2025 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 2028 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 2031 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 2034 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 2037 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 2040 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 2043 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 2046 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 2049 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha224, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 2052 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 2055 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 2058 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 2061 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 2065 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 2068 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 2071 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 2074 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 2077 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 2080 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 2083 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 2086 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 2089 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 2100 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 2103 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 2110 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_regex, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 2117 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 2124 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 2130 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 2137 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 2144 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 2147 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 2151 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 2153 "lib/MapSetParser/MapSetParser.ypp"
    {
	  // x = new ArgList($2, driver.curExprList);
	  delete driver.curExprList;
	  driver.curExprList = NULL;
	  w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // $$ = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group-concat, $3, $4.p_Expression, $4.separator));
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 2163 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
	driver.countStar = true;
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 2171 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 2174 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 2177 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 2180 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 2183 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 2189 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 2195 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 2202 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 2212 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 2220 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 2228 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 2235 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 2239 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 2247 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 3095 "lib/MapSetParser/MapSetParser.cpp"
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
  const short int MapSetParser::yypact_ninf_ = -645;
  const short int
  MapSetParser::yypact_[] =
  {
      -645,    39,    69,  -645,   -55,  -645,  -645,  -645,  -645,   389,
      95,   -81,   104,   104,   104,   104,   104,    56,    71,   167,
      77,    63,  -645,  -645,  -645,  -645,  -645,   104,  -645,  -645,
    -645,  -645,  -645,   -64,  -645,  -645,  -645,  -645,  -645,  -645,
    -645,  -645,  -645,   104,  -645,    98,  -645,  -645,  -645,  -645,
    -645,   281,  -645,    77,   281,    72,  -645,    16,   104,    56,
    -645,  -645,  -645,  -645,   133,  -645,  -645,  -645,  -645,  -645,
    -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,
    -645,  -645,   158,  -645,  -645,  -645,  -645,  -645,  -645,  -645,
    -645,  -645,  -645,  -645,   161,  -645,  -645,  -645,  -645,    34,
     866,  -645,  -645,    70,  -645,  -645,   183,  -645,  -645,  -645,
    1235,    25,  -645,   104,  -645,  -645,  -645,  -645,  -645,  -645,
     192,  -645,   188,  -645,  -645,  -645,  -645,   197,  -645,     1,
    -645,  -645,   146,   207,  -645,    45,  -645,  1235,  -645,  -645,
      45,  1321,    45,    56,  -645,  -645,  -645,  -645,  -645,   220,
     239,   184,  -645,  -645,  -645,  -645,   222,  1321,  -645,  -645,
    -645,  -645,  -645,  -645,  -645,  -645,  1268,  -645,  -645,  -645,
    -645,  1805,  -645,  -645,  -645,  -645,  1907,   252,  -645,  1072,
    -645,  -645,  -645,  -645,  -645,  -645,  1445,   204,   240,   241,
     -16,   -14,   242,   243,   245,   207,   246,   247,   249,   250,
     261,   263,   264,   265,   266,   267,   268,   -14,   269,   270,
     272,   114,   273,   127,   274,   275,   276,   277,   279,   280,
     284,   286,   287,   288,   289,   290,   292,   293,   294,   295,
     296,   298,   299,   300,   302,   303,  1805,  -645,  -645,  -645,
    -645,  -645,  -645,  -645,  -645,   -12,    -7,  1445,  1907,  -645,
    -645,  -645,  -645,  -645,   318,    80,  -645,   101,  -645,  -645,
     283,  -645,  -645,  -645,   304,  -645,  -645,   301,   297,  1565,
    1565,  1565,   309,  -645,  -645,  -645,  -645,   311,  -645,  -645,
     282,  -645,  -645,  -645,  -645,   196,  -645,  -645,  -645,  -645,
    -645,  -645,  -645,   312,  -645,  -645,  -645,  -645,   -12,   207,
    1445,  1445,  1445,  -645,  -645,  1445,  -645,  -645,  1445,  1445,
    1445,  -645,  1445,  1445,  1445,  1445,   -81,  1445,  1445,  1445,
    1445,  1445,  1445,  -645,  1445,  1445,  1445,  -645,  1445,  -645,
    1445,  1445,  1445,  1445,  1445,  1445,  1445,  1445,  1445,  1445,
    1445,  1445,  1445,  1445,  1445,  1445,  1445,  1445,  1445,  1445,
    1445,  1445,  -645,   335,  -645,  -645,  -645,  -645,   313,  -645,
    1211,   211,   213,  -645,  -645,   329,   332,  -645,  -645,  -645,
    1048,   327,  -645,   203,  1235,  -645,  -645,    45,    66,    45,
    -645,  1321,  -645,  -645,  -645,  -645,   335,   335,   -81,  -645,
     331,   315,   316,  1445,  1445,  1445,  1445,  1445,  1445,   307,
     -14,  -645,  -645,   148,     7,   335,  -645,  -645,  -645,   334,
     337,   338,  -645,   328,   336,   339,   341,   342,   350,   344,
     345,   353,   361,   362,   363,   364,   358,   366,   367,   370,
     371,   372,   375,   379,   374,   403,   406,   407,   401,   409,
     410,   411,   405,   413,   414,   415,   416,   417,   418,   412,
     420,   422,   424,  -645,  1445,  -645,  -645,  -645,  -645,  1211,
    -645,   340,  -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,
    -645,  -645,  -645,  1445,  -645,  -645,  1685,  -645,  -645,  -645,
    -645,  -645,  -645,  -645,  -645,   146,  -645,  -645,  -645,  -645,
    1907,   426,  -645,   425,  -645,  -645,  -645,  -645,  -645,  -645,
    -645,  -645,  -645,  -645,  -645,   -21,  -645,    13,     4,  -645,
    -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,    14,  -645,
    -645,  -645,  -645,  -645,  1321,  -645,   827,  1445,  -645,  -645,
    1445,  -645,  1445,  -645,  -645,  -645,  -645,  -645,  -645,  -645,
     -14,  -645,  1445,  1445,     7,  -645,  -645,  -645,  1445,  1445,
    -645,  1445,  -645,  -645,  -645,  -645,  1445,  1445,  1445,  -645,
    -645,  1445,  -645,  -645,  1445,  -645,  -645,  -645,  -645,  1445,
    -645,  -645,  -645,  -645,  -645,  -645,  -645,  1445,  -645,  -645,
    -645,  1445,  -645,  -645,  -645,  1445,  -645,  -645,  -645,  -645,
    -645,  -645,  1445,  -645,  -645,  -645,  -645,   -24,  -645,  -645,
     282,  -645,   239,  -645,  -645,   207,  -645,  -645,  1445,  -645,
    1235,   207,   428,    84,  -645,    42,  -645,  -645,  -645,  -645,
    -645,  -645,  1321,   365,   408,  -645,   -26,  -645,  -645,  -645,
    -645,  -645,  -645,  -645,  -645,   429,  -645,  -645,  -645,  -645,
    -645,  -645,  -645,  -645,  -645,  -645,   432,    -3,   427,   433,
     435,   436,   437,   431,   439,   431,   440,   441,  -645,  -645,
    -645,  -645,  -645,   443,  -645,    76,    76,  -645,   207,   396,
    -645,  -645,  -645,  -645,   445,  -645,  -645,  -645,  -645,  -645,
     -21,  -645,   -21,  -645,   343,  -645,  -645,    17,  -645,   444,
    -645,  -645,  1445,  -645,  1445,  -645,  -645,  -645,  -645,  -645,
     447,  -645,   448,  -645,  -645,     8,  1292,  -645,  -645,   207,
    -645,   -81,   446,  -645,   388,   449,  -645,  -645,   456,  -645,
      -5,  -645,   421,  -645,   454,  -645,   459,  -645,  -645,  -645,
    -645,   706,  -645,  -645,  -645,  -645,  -645,  -645,   207,  -645,
     460,  -645,  -645,    84,  -645,    66,  -645,  -645,  -645,  -645,
     464,   442,  -645,  -645,  -645,  -645,  -645,  -645,   207,  -645,
    -645,  -645,  -645,  -645,   104,  -645,  1321,  -645,  -645
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  MapSetParser::yydefact_[] =
  {
         2,     0,    37,     1,     0,     4,    39,    38,    41,     6,
      36,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     3,     5,    42,    40,   312,   313,     0,   464,   466,
     465,   467,     9,   448,    10,    11,    12,    13,   468,   471,
     470,    14,   469,     0,    15,    29,    28,    18,    20,    19,
      16,    21,    24,    17,     0,     0,     7,     0,     0,     0,
     446,   447,   449,   444,     0,    33,    26,    30,   462,   463,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   472,
     473,   319,     0,    22,   315,   316,   450,   451,   452,   317,
     314,   318,    25,    71,     0,    43,     8,   445,    35,     0,
       0,   199,    45,     0,    31,    34,     0,    23,   308,   309,
     201,    80,    44,     0,   297,   298,   299,   300,   301,   294,
       0,   202,   205,   209,   293,   292,   303,     0,   207,     0,
      81,    46,    83,     0,    32,     0,   200,   201,   206,   203,
     219,   302,     0,     0,    73,    74,    75,    76,    78,     0,
     132,    85,    84,   142,    79,   227,     0,   302,   226,   310,
     311,   204,   220,   210,   218,   307,   302,   304,   306,   208,
      77,     0,   121,    72,   133,   120,     0,    87,    86,   147,
     295,   216,   223,   225,   296,   305,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    95,    97,
      94,   416,   384,   417,   418,     0,     0,     0,    98,    99,
     101,   186,   184,   185,     0,    89,    88,    52,   144,    47,
       0,   145,   150,   148,   154,   230,   228,   211,   221,     0,
       0,     0,     0,   433,   434,   435,   436,     0,   437,   367,
      55,   320,   323,   327,   329,   331,   341,   352,   355,   360,
     361,   362,   368,     0,   363,   364,   365,   366,   442,     0,
       0,     0,     0,   420,   377,     0,   196,   406,     0,     0,
       0,   425,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   383,     0,     0,     0,   378,     0,   399,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,   191,   188,   187,   130,   122,     0,   100,
       0,     0,     0,    82,    90,   114,   116,    50,    51,    53,
       0,    80,   143,   146,   147,   155,   152,   219,     0,   213,
     217,   302,   224,   358,   359,   357,   191,   191,     0,    56,
       0,   321,   325,     0,     0,     0,     0,     0,     0,     0,
       0,   330,   332,   342,   354,   191,   443,   441,   426,     0,
       0,     0,   197,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   192,     0,   128,   369,   107,   108,   102,
     103,     0,   105,   106,   110,   111,   118,   119,   112,   115,
     113,   117,    69,     0,    65,    66,    68,    49,    61,    58,
      60,    59,    62,    63,    64,    83,   165,   169,   163,   173,
       0,     0,   151,   140,   157,   159,   160,   162,   158,   156,
     177,   161,   153,   243,   231,     0,   273,     0,     0,   229,
     232,   234,   235,   244,   246,   249,   258,   253,   256,   271,
     245,   272,   214,   215,   302,   222,     0,     0,    54,    96,
       0,   324,     0,   328,   333,   334,   335,   336,   337,   338,
       0,   339,     0,     0,   347,   353,   343,   344,     0,     0,
     356,     0,   375,   376,   419,   194,     0,     0,     0,   370,
     371,     0,   373,   374,     0,   411,   412,   413,   414,     0,
     415,   400,   392,   405,   398,   382,   404,     0,   397,   381,
     396,     0,   403,   395,   388,     0,   380,   394,   387,   379,
     386,   402,     0,   385,   401,   393,   189,     0,   104,   109,
      55,    67,   132,   166,   170,     0,   174,   183,     0,   141,
     147,     0,     0,   281,   289,     0,   274,   276,   283,   285,
     288,   259,   302,   247,   251,   267,     0,   269,   268,   255,
     257,   260,   212,   431,   432,     0,   429,   322,   326,   340,
     349,   350,   348,   351,   345,   346,     0,     0,     0,     0,
       0,     0,     0,   422,     0,   422,     0,     0,   194,   131,
     125,   127,   129,     0,    48,     0,     0,   164,     0,     0,
     149,   181,   275,   282,     0,   278,   287,   290,   286,   241,
       0,   250,     0,   254,     0,   291,   270,     0,   427,   439,
     428,   198,     0,   195,     0,   408,   409,   372,   410,   423,
       0,   389,     0,   390,   391,     0,     0,    57,   167,     0,
     175,     0,   178,   284,   280,   233,   248,   252,     0,   264,
       0,   265,     0,   440,     0,   193,     0,   421,   424,   190,
     138,     0,   123,   139,   135,   136,   137,   134,     0,   171,
       0,   179,   182,     0,   279,   238,   242,   266,   261,   263,
       0,     0,   430,   407,   126,   124,   168,   172,     0,   277,
     236,   239,   240,   262,     0,   180,   302,   438,   237
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yypgoto_[] =
  {
      -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,   453,  -645,
    -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,
    -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,
    -645,   -93,  -645,    33,  -645,  -645,  -645,  -645,  -645,  -645,
    -645,  -645,   368,   139,  -645,    27,  -645,  -645,  -645,  -645,
    -645,  -645,   278,  -645,  -645,   291,  -645,  -645,    58,  -645,
    -645,  -645,  -645,  -645,  -645,   152,   155,   -80,  -645,  -645,
    -645,  -645,  -645,  -645,  -645,  -645,  -210,  -645,  -193,  -645,
    -645,  -645,  -362,  -645,  -645,  -645,  -645,  -645,  -645,  -645,
    -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,
    -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,  -345,
    -155,   226,  -645,  -343,  -600,  -133,  -206,  -645,  -645,  -645,
     390,  -645,  -645,  -645,  -645,  -645,  -645,   -42,  -645,  -645,
    -645,  -645,  -645,   149,  -514,  -645,  -645,   147,   150,  -645,
    -645,  -645,  -645,  -645,  -215,  -645,  -645,  -645,  -645,  -645,
    -645,  -645,  -645,    26,  -645,  -645,  -645,  -148,  -645,  -645,
      28,  -645,  -147,  -645,  -645,  -645,  -645,  -645,  -645,  -645,
    -645,  -645,  -645,  -645,  -645,  -645,  -593,  -645,  -645,  -644,
    -102,  -645,  -645,  -645,  -645,  -645,  -645,  -103,   -87,  -531,
     -11,    18,   482,  -645,  -645,  -645,    11,  -645,  -645,     6,
    -645,  -645,  -645,  -127,  -645,  -645,    -4,  -645,  -645,  -645,
    -346,  -645,  -325,     5,  -165,  -162,  -645,  -645,  -118,  -645,
    -645,  -645,  -305,  -645,  -645,  -645,  -645,  -645,  -645,  -645,
      -9,  -645,  -645,  -645,   -30,  -645,   140,   141,    10,  -222,
      43,  -645,  -645
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yydefgoto_[] =
  {
        -1,     1,     2,     9,    21,    22,    50,    82,    52,    53,
      44,    45,    66,    67,   105,    99,    46,     5,     6,    10,
       7,    24,    57,   103,   111,   258,   371,   259,   369,   370,
     389,   390,   474,   475,   476,   477,    55,    56,   131,   144,
     145,   146,   147,   132,   133,   150,   151,   177,   255,   363,
     152,   236,   237,   178,   248,   249,   256,   459,   460,   461,
     462,   463,   364,   468,   470,   365,   366,   173,   246,   731,
     662,   706,   597,   174,   455,   175,   732,   610,   154,   179,
     260,   261,   262,   492,   373,   263,   375,   376,   493,   494,
     605,   495,   603,   665,   738,   496,   604,   666,   497,   498,
     606,   668,   499,   500,   611,   742,   758,   712,   501,   250,
     251,   355,   658,   454,   693,   647,   307,   555,   102,   110,
     120,   121,   138,   139,   122,   142,   140,   162,   522,   523,
     380,   267,   163,   164,   181,   382,   268,   182,   157,   264,
     378,   377,   509,   622,   510,   761,   766,   762,   746,   715,
     504,   511,   512,   513,   514,   681,   623,   515,   683,   624,
     516,   629,   517,   630,   749,   721,   686,   631,   518,   519,
     616,   744,   714,   673,   674,   617,   618,   677,   619,   687,
     165,   124,   135,   125,   126,   127,   166,   183,   168,   158,
     279,   109,   280,   281,   531,   391,   282,   533,   392,   283,
     284,   401,   402,   285,   286,   544,   550,   643,   545,   403,
     287,   404,   288,   289,   290,   291,   304,   241,   700,   242,
     243,   244,   292,   689,   635,   293,   723,   724,   294,   407,
     295,    61,    62,    63,   296,    86,    87,    88,   297,    33,
     298,    42,    91
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int MapSetParser::yytable_ninf_ = -303;
  const short int
  MapSetParser::yytable_[] =
  {
        27,   323,   311,    32,    34,    35,    36,    37,   123,   240,
     632,   252,   502,   107,   253,   464,   238,   659,    58,   660,
     675,    85,   505,   128,    85,   684,    59,   302,   143,   305,
     548,   353,   506,   356,    64,   123,   748,   625,   167,     3,
     718,   691,    84,   526,   527,    84,   507,   505,   692,    96,
     128,   129,   729,   699,   626,   699,   613,   506,   719,   692,
      41,    89,   551,   185,    89,   481,   614,   130,   720,    83,
      85,   507,    93,   549,   240,   104,   750,   265,   627,    54,
      85,   238,   508,   252,    25,    26,   253,   -70,     4,   108,
     106,    84,   266,   156,    90,   676,    94,    90,   155,   108,
     169,    84,    97,    60,   134,     8,   408,    85,   679,   505,
      89,    85,   361,   362,   464,    23,   615,    51,   628,   506,
      89,   685,   367,   368,   159,    43,   108,    85,    84,   159,
     108,   159,    84,   507,   708,   709,    85,   614,    65,    38,
      39,    40,   685,    90,   661,   607,   108,    89,    84,    85,
     759,    89,   303,    90,   306,   108,   354,    84,    25,    26,
     239,    38,    39,    40,    38,    39,    40,    89,   108,   508,
      84,   481,   148,    38,    39,    40,    89,    95,   160,    47,
      90,    48,    49,   160,    90,   160,   148,   615,    98,    89,
      28,    29,    30,    31,   541,   252,   640,   641,   253,   100,
      90,   101,    38,    39,    40,    38,    39,    40,   480,    90,
      25,    26,   542,   543,   245,   478,    38,    39,    40,   245,
     486,   487,    90,   644,   645,   239,    38,    39,    40,   113,
     112,    25,    26,   136,   137,   357,    38,    39,    40,   149,
     141,    25,    26,  -176,    38,    39,    40,   153,   670,   171,
     488,   489,   768,   490,   393,   394,   395,   396,   397,   398,
      28,    29,    30,    31,   399,   400,   534,   535,   536,   537,
     538,   539,   265,   172,   383,   384,   385,   180,   176,   245,
     254,   299,   327,   300,   301,   308,   309,   266,   310,   312,
     313,   245,   314,   315,   252,   329,   599,   253,    73,    74,
      75,    76,    77,    78,   316,   420,   317,   318,   319,   320,
     321,   322,   324,   325,   480,   326,   328,   330,   331,   332,
     333,   478,   334,   335,   372,   252,   491,   336,   253,   337,
     338,   339,   340,   341,   639,   342,   343,   344,   345,   346,
     483,   347,   348,   349,    85,   350,   351,   360,   381,   465,
     374,    85,   386,   379,   387,   405,   453,   456,   466,   479,
     467,   482,   362,   108,   361,    84,   159,   520,   159,   130,
     108,   530,    84,   532,   388,   529,   540,   528,   552,   556,
     484,   553,   554,   247,    89,   559,   560,   557,   562,   563,
     558,    89,    11,    12,    13,    14,    15,    16,    17,    18,
      19,   561,    20,   245,   564,   565,   566,   567,   568,   569,
     570,   571,   667,   245,   572,   573,   574,    90,   671,   575,
     160,   521,   160,   576,    90,   577,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    28,    29,    30,
      31,    38,    39,    40,    79,    80,   483,   578,   465,    81,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   479,   594,   482,   595,   608,
     680,   609,   672,   688,   682,   710,   690,   695,   694,   696,
     697,   698,   692,   701,   703,   704,   484,   707,   711,   713,
     685,   727,   728,   743,    85,   741,   722,   747,   752,   751,
     764,   745,   245,   753,   757,   763,    92,   663,   265,   601,
     485,   170,   602,   108,   352,    84,   739,   598,   471,   245,
     469,   755,   664,   266,   406,   705,   503,   161,   525,   524,
     760,   612,   716,   245,    89,   717,   621,   702,   638,   359,
     642,   637,   767,   546,   547,   756,     0,     0,   521,     0,
     620,   521,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   765,     0,    90,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    85,     0,     0,     0,     0,     0,     0,   108,
       0,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,     0,    84,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,   159,   159,   620,     0,   678,     0,
       0,     0,     0,     0,     0,    90,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   735,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   733,     0,   734,     0,     0,
     740,   735,     0,     0,     0,     0,     0,     0,   160,   160,
       0,     0,     0,     0,     0,     0,   736,     0,     0,     0,
     733,     0,   734,   521,     0,   521,     0,     0,     0,   358,
       0,     0,     0,     0,   520,     0,    85,     0,     0,     0,
       0,   736,     0,     0,     0,     0,     0,     0,     0,   737,
     754,   730,     0,     0,     0,   108,     0,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   737,     0,    89,     0,     0,     0,
       0,     0,   409,   410,   411,     0,   620,   412,   521,     0,
     413,   414,   415,     0,   416,   417,   418,   419,     0,   421,
     422,   423,   424,   425,   426,     0,   427,   428,   429,    90,
     430,     0,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     633,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    28,    29,    30,    31,    38,    39,    40,     0,
     247,    25,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   269,   270,     0,   271,   187,     0,   188,   189,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,     0,   207,     0,
       0,     0,   272,   273,   274,   275,   276,   277,   278,   208,
       0,     0,     0,     0,     0,     0,   596,   209,     0,   210,
       0,     0,   211,   212,     0,   213,     0,   214,   215,   216,
       0,   217,   218,     0,   219,   600,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    28,    29,    30,    31,    38,    39,    40,
       0,     0,    25,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   634,   636,
       0,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    28,    29,    30,    31,    38,    39,    40,    79,
      80,    25,    26,   646,    81,     0,     0,     0,   648,   649,
     650,     0,     0,   651,     0,     0,   652,     0,     0,     0,
       0,   653,     0,     0,     0,     0,     0,     0,     0,   654,
       0,     0,     0,   655,     0,     0,     0,   656,     0,     0,
       0,   472,     0,     0,   657,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     669,   473,     0,     0,     0,     0,     0,   257,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,   115,   116,
     117,   118,     0,     0,     0,  -302,   187,     0,   188,   189,
     190,   191,   192,   193,   194,   195,   119,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,     0,   207,
       0,     0,     0,   272,   273,   274,   275,   276,   277,   278,
     208,     0,     0,     0,     0,     0,     0,     0,   209,     0,
     210,     0,     0,   211,   212,     0,   213,     0,   214,   215,
     216,     0,   217,   218,   725,   219,   726,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    28,    29,    30,    31,    38,    39,
      40,     0,     0,    25,    26,     0,     0,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    28,    29,
      30,    31,    38,    39,    40,    79,    80,    25,    26,     0,
      81,   457,   458,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   247,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,   116,   117,   118,     0,     0,     0,  -302,   187,
       0,   188,   189,   190,   191,   192,   193,   194,   195,   119,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,     0,   207,   114,   115,   116,   117,   118,     0,     0,
       0,     0,   184,   208,     0,     0,     0,     0,     0,     0,
       0,   209,   119,   210,     0,     0,   211,   212,     0,   213,
       0,   214,   215,   216,     0,   217,   218,   730,   219,     0,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   114,   115,   116,   117,
     118,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,    39,    40,     0,   119,    25,    26,     0,     0,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    28,    29,    30,    31,    38,    39,    40,    79,    80,
      25,    26,     0,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    28,    29,    30,    31,    38,    39,
      40,    79,    80,    25,    26,     0,    81,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    28,    29,
      30,    31,    38,    39,    40,     0,     0,    25,    26,     0,
       0,     0,     0,     0,     0,     0,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    28,    29,    30,
      31,    38,    39,    40,    79,    80,    25,    26,   247,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   269,
     270,     0,   271,   187,     0,   188,   189,   190,   191,   192,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,     0,   207,     0,     0,     0,
     272,   273,   274,   275,   276,   277,   278,   208,     0,     0,
       0,     0,     0,     0,     0,   209,     0,   210,     0,     0,
     211,   212,     0,   213,     0,   214,   215,   216,     0,   217,
     218,     0,   219,     0,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    28,    29,    30,    31,    38,    39,    40,   247,     0,
      25,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   187,     0,   188,   189,   190,   191,   192,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,     0,   207,     0,     0,     0,
     272,   273,   274,   275,   276,   277,   278,   208,     0,     0,
       0,     0,     0,     0,     0,   209,     0,   210,     0,     0,
     211,   212,     0,   213,     0,   214,   215,   216,     0,   217,
     218,     0,   219,     0,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    28,    29,    30,    31,    38,    39,    40,   473,     0,
      25,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   187,     0,   188,   189,   190,   191,   192,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,     0,   207,     0,     0,     0,
     272,   273,   274,   275,   276,   277,   278,   208,     0,     0,
       0,     0,     0,     0,     0,   209,     0,   210,     0,     0,
     211,   212,     0,   213,     0,   214,   215,   216,     0,   217,
     218,     0,   219,     0,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    28,    29,    30,    31,    38,    39,    40,   186,     0,
      25,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   187,     0,   188,   189,   190,   191,   192,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,     0,   207,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   208,     0,     0,
       0,     0,     0,     0,     0,   209,     0,   210,     0,     0,
     211,   212,     0,   213,     0,   214,   215,   216,     0,   217,
     218,     0,   219,     0,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     247,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,    39,    40,     0,     0,
      25,    26,     0,     0,     0,   187,     0,   188,   189,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,     0,   207,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   208,
       0,     0,     0,     0,     0,     0,     0,   209,     0,   210,
       0,     0,   211,   212,     0,   213,     0,   214,   215,   216,
       0,   217,   218,     0,   219,     0,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,    39,    40
  };

  /* YYCHECK.  */
  const short int
  MapSetParser::yycheck_[] =
  {
        11,   207,   195,    12,    13,    14,    15,    16,   110,   171,
     524,   176,   374,   100,   176,   360,   171,    41,    27,    43,
     613,    51,    43,   110,    54,    51,    90,    43,    27,    43,
      23,    43,    53,    40,    43,   137,    41,    23,   141,     0,
     684,    44,    51,   386,   387,    54,    67,    43,    51,    58,
     137,    26,    44,   653,    40,   655,    43,    53,    41,    51,
      17,    51,   405,   166,    54,   370,    53,    42,    51,    51,
     100,    67,    54,    66,   236,    41,   720,   179,    64,    16,
     110,   236,   103,   248,   165,   166,   248,    24,    19,   100,
      99,   100,   179,   135,    51,    53,    24,    54,    53,   110,
     142,   110,    59,   167,   113,   160,   299,   137,   622,    43,
     100,   141,    32,    33,   459,    20,   103,    40,   104,    53,
     110,   147,    21,    22,   135,    54,   137,   157,   137,   140,
     141,   142,   141,    67,   665,   666,   166,    53,    40,   160,
     161,   162,   147,   100,   168,   490,   157,   137,   157,   179,
     743,   141,   168,   110,   168,   166,   168,   166,   165,   166,
     171,   160,   161,   162,   160,   161,   162,   157,   179,   103,
     179,   476,   129,   160,   161,   162,   166,   161,   135,    12,
     137,    14,    15,   140,   141,   142,   143,   103,    55,   179,
     156,   157,   158,   159,   400,   360,   542,   543,   360,    41,
     157,    40,   160,   161,   162,   160,   161,   162,   370,   166,
     165,   166,    64,    65,   171,   370,   160,   161,   162,   176,
      17,    18,   179,   548,   549,   236,   160,   161,   162,    46,
     160,   165,   166,    41,    46,   246,   160,   161,   162,    93,
      43,   165,   166,    40,   160,   161,   162,    40,   610,    29,
      47,    48,   766,    50,    58,    59,    60,    61,    62,    63,
     156,   157,   158,   159,    68,    69,   393,   394,   395,   396,
     397,   398,   374,    34,   269,   270,   271,    55,    94,   236,
      28,    77,   168,    43,    43,    43,    43,   374,    43,    43,
      43,   248,    43,    43,   459,   168,   461,   459,   150,   151,
     152,   153,   154,   155,    43,   316,    43,    43,    43,    43,
      43,    43,    43,    43,   476,    43,    43,    43,    43,    43,
      43,   476,    43,    43,    41,   490,   123,    43,   490,    43,
      43,    43,    43,    43,   540,    43,    43,    43,    43,    43,
     370,    43,    43,    43,   374,    43,    43,    29,    51,   360,
      46,   381,    43,    52,    43,    43,    21,    44,   147,   370,
     147,   370,    33,   374,    32,   374,   377,   378,   379,    42,
     381,    56,   381,    57,    92,    44,    69,   388,    44,    51,
     370,    44,    44,    43,   374,    44,    44,    51,    44,    44,
      51,   381,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    51,    13,   360,    51,    44,    44,    44,    44,    51,
      44,    44,   605,   370,    44,    44,    44,   374,   611,    44,
     377,   378,   379,    44,   381,    51,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   476,    44,   459,   168,
      44,    44,    51,    44,    44,    44,    51,    44,    44,    44,
      44,    44,    44,    51,    44,   476,    44,   476,    44,    43,
     105,    46,    44,    44,    66,   668,    44,    44,    51,    44,
      44,    44,    51,    44,    44,    44,   476,    44,    92,    44,
     147,    44,    44,   105,   524,    49,    52,    41,    44,    78,
      58,    52,   459,    44,    44,    41,    53,   600,   610,   476,
     371,   143,   485,   524,   236,   524,   709,   459,   366,   476,
     365,   731,   602,   610,   298,   658,   377,   137,   381,   379,
     745,   505,   680,   490,   524,   682,   508,   655,   532,   248,
     544,   530,   764,   403,   403,   738,    -1,    -1,   505,    -1,
     507,   508,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   758,    -1,   524,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     610,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   622,    -1,    -1,    -1,    -1,    -1,    -1,   610,
      -1,   610,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   622,    -1,   622,    -1,    -1,    -1,    -1,    -1,    -1,
     610,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   622,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   610,   665,   666,   613,    -1,   615,    -1,
      -1,    -1,    -1,    -1,    -1,   622,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   706,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   706,    -1,   706,    -1,    -1,
     711,   731,    -1,    -1,    -1,    -1,    -1,    -1,   665,   666,
      -1,    -1,    -1,    -1,    -1,    -1,   706,    -1,    -1,    -1,
     731,    -1,   731,   680,    -1,   682,    -1,    -1,    -1,   247,
      -1,    -1,    -1,    -1,   745,    -1,   766,    -1,    -1,    -1,
      -1,   731,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   706,
      44,    45,    -1,    -1,    -1,   766,    -1,   766,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   731,    -1,   766,    -1,    -1,    -1,
      -1,    -1,   300,   301,   302,    -1,   743,   305,   745,    -1,
     308,   309,   310,    -1,   312,   313,   314,   315,    -1,   317,
     318,   319,   320,   321,   322,    -1,   324,   325,   326,   766,
     328,    -1,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,    -1,
      43,   165,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    -1,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    91,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,   101,   102,
      -1,    -1,    -1,    -1,    -1,    -1,   454,   110,    -1,   112,
      -1,    -1,   115,   116,    -1,   118,    -1,   120,   121,   122,
      -1,   124,   125,    -1,   127,   473,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
      -1,    -1,   165,   166,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   526,   527,
      -1,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   551,   168,    -1,    -1,    -1,   556,   557,
     558,    -1,    -1,   561,    -1,    -1,   564,    -1,    -1,    -1,
      -1,   569,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   577,
      -1,    -1,    -1,   581,    -1,    -1,    -1,   585,    -1,    -1,
      -1,    23,    -1,    -1,   592,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     608,    43,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    43,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    54,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    91,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,   101,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,
     112,    -1,    -1,   115,   116,    -1,   118,    -1,   120,   121,
     122,    -1,   124,   125,   692,   127,   694,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,    -1,    -1,   165,   166,    -1,    -1,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,    -1,
     168,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    43,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    54,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    91,    35,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    44,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   110,    54,   112,    -1,    -1,   115,   116,    -1,   118,
      -1,   120,   121,   122,    -1,   124,   125,    45,   127,    -1,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   160,   161,   162,    -1,    54,   165,   166,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,    -1,   168,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,    -1,    -1,   165,   166,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,    43,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      65,    -1,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    91,    -1,    -1,    -1,
      95,    96,    97,    98,    99,   100,   101,   102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,    -1,   112,    -1,    -1,
     115,   116,    -1,   118,    -1,   120,   121,   122,    -1,   124,
     125,    -1,   127,    -1,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,    43,    -1,
     165,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    91,    -1,    -1,    -1,
      95,    96,    97,    98,    99,   100,   101,   102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,    -1,   112,    -1,    -1,
     115,   116,    -1,   118,    -1,   120,   121,   122,    -1,   124,
     125,    -1,   127,    -1,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,    43,    -1,
     165,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    91,    -1,    -1,    -1,
      95,    96,    97,    98,    99,   100,   101,   102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,    -1,   112,    -1,    -1,
     115,   116,    -1,   118,    -1,   120,   121,   122,    -1,   124,
     125,    -1,   127,    -1,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,    43,    -1,
     165,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,    -1,   112,    -1,    -1,
     115,   116,    -1,   118,    -1,   120,   121,   122,    -1,   124,
     125,    -1,   127,    -1,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   160,   161,   162,    -1,    -1,
     165,   166,    -1,    -1,    -1,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,   112,
      -1,    -1,   115,   116,    -1,   118,    -1,   120,   121,   122,
      -1,   124,   125,    -1,   127,    -1,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,   162
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  MapSetParser::yystos_[] =
  {
         0,   170,   171,     0,    19,   186,   187,   189,   160,   172,
     188,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      13,   173,   174,    20,   190,   165,   166,   359,   156,   157,
     158,   159,   399,   408,   399,   399,   399,   399,   160,   161,
     162,   409,   410,    54,   179,   180,   185,    12,    14,    15,
     175,    40,   177,   178,    16,   205,   206,   191,   399,    90,
     167,   400,   401,   402,   399,    40,   181,   182,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   163,
     164,   168,   176,   360,   399,   403,   404,   405,   406,   407,
     409,   411,   177,   360,    24,   161,   399,   409,    55,   184,
      41,    40,   287,   192,    41,   183,   399,   357,   359,   360,
     288,   193,   160,    46,    35,    36,    37,    38,    39,    54,
     289,   290,   293,   349,   350,   352,   353,   354,   357,    26,
      42,   207,   212,   213,   399,   351,    41,    46,   291,   292,
     295,    43,   294,    27,   208,   209,   210,   211,   409,    93,
     214,   215,   219,    40,   247,    53,   296,   307,   358,   359,
     409,   289,   296,   301,   302,   349,   355,   356,   357,   296,
     211,    29,    34,   236,   242,   244,    94,   216,   222,   248,
      55,   303,   306,   356,    44,   356,    43,    68,    70,    71,
      72,    73,    74,    75,    76,    77,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    91,   102,   110,
     112,   115,   116,   118,   120,   121,   122,   124,   125,   127,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   220,   221,   279,   359,
     384,   386,   388,   389,   390,   409,   237,    43,   223,   224,
     278,   279,   383,   384,    28,   217,   225,    25,   194,   196,
     249,   250,   251,   254,   308,   349,   357,   300,   305,    64,
      65,    67,    95,    96,    97,    98,    99,   100,   101,   359,
     361,   362,   365,   368,   369,   372,   373,   379,   381,   382,
     383,   384,   391,   394,   397,   399,   403,   407,   409,    77,
      43,    43,    43,   168,   385,    43,   168,   285,    43,    43,
      43,   247,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,   285,    43,    43,    43,   168,    43,   168,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,   221,    43,   168,   280,    40,   359,   361,   224,
      29,    32,    33,   218,   231,   234,   235,    21,    22,   197,
     198,   195,    41,   253,    46,   255,   256,   310,   309,    52,
     299,    51,   304,   382,   382,   382,    43,    43,    92,   199,
     200,   364,   367,    58,    59,    60,    61,    62,    63,    68,
      69,   370,   371,   378,   380,    43,   280,   398,   247,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     359,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,    21,   282,   243,    44,    30,    31,   226,
     227,   228,   229,   230,   278,   359,   147,   147,   232,   235,
     233,   234,    23,    43,   201,   202,   203,   204,   279,   359,
     384,   391,   399,   403,   407,   212,    17,    18,    47,    48,
      50,   123,   252,   257,   258,   260,   264,   267,   268,   271,
     272,   277,   251,   302,   319,    43,    53,    67,   103,   311,
     313,   320,   321,   322,   323,   326,   329,   331,   337,   338,
     359,   409,   297,   298,   307,   306,   282,   282,   359,    44,
      56,   363,    57,   366,   372,   372,   372,   372,   372,   372,
      69,   285,    64,    65,   374,   377,   405,   406,    23,    66,
     375,   282,    44,    44,    44,   286,    51,    51,    51,    44,
      44,    51,    44,    44,    51,    44,    44,    44,    44,    51,
      44,    44,    44,    44,    44,    44,    44,    51,    44,    44,
      44,    51,    44,    44,    44,    51,    44,    44,    44,    44,
      44,    44,    51,    44,    44,    44,   361,   241,   227,   383,
     361,   202,   214,   261,   265,   259,   269,   278,    43,    46,
     246,   273,   322,    43,    53,   103,   339,   344,   345,   347,
     409,   329,   312,   325,   328,    23,    40,    64,   104,   330,
     332,   336,   303,    23,   361,   393,   361,   365,   368,   285,
     379,   379,   375,   376,   381,   381,   361,   284,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   281,    41,
      43,   168,   239,   200,   236,   262,   266,   247,   270,   361,
     251,   247,    44,   342,   343,   345,    53,   346,   409,   303,
     105,   324,    66,   327,    51,   147,   335,   348,    44,   392,
      44,    44,    51,   283,    51,    44,    44,    44,    44,   283,
     387,    44,   387,    44,    44,   284,   240,    44,   358,   358,
     247,    92,   276,    44,   341,   318,   326,   331,   348,    41,
      51,   334,    52,   395,   396,   361,   361,    44,    44,    44,
      45,   238,   245,   359,   399,   403,   407,   409,   263,   247,
     359,    49,   274,   105,   340,    52,   317,    41,    41,   333,
     348,    78,    44,    44,    44,   245,   247,    44,   275,   345,
     313,   314,   316,    41,    58,   247,   315,   408,   303
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
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  MapSetParser::yyr1_[] =
  {
         0,   169,   171,   170,   172,   172,   173,   173,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   175,   175,
     175,   176,   176,   177,   178,   178,   179,   180,   180,   181,
     181,   182,   183,   184,   184,   185,   186,   187,   187,   188,
     188,   189,   191,   192,   190,   193,   193,   195,   194,   196,
     197,   197,   198,   198,   199,   200,   200,   201,   202,   202,
     202,   202,   202,   202,   202,   202,   203,   203,   204,   204,
     205,   205,   206,   207,   208,   208,   209,   210,   211,   212,
     213,   213,   214,   215,   215,   216,   216,   217,   217,   218,
     218,   219,   220,   220,   221,   221,   221,   221,   222,   223,
     223,   224,   225,   226,   226,   227,   227,   228,   228,   229,
     230,   230,   231,   231,   232,   232,   233,   233,   234,   235,
     236,   237,   237,   238,   238,   240,   239,   239,   241,   241,
     243,   242,   244,   244,   245,   245,   245,   245,   245,   245,
     246,   246,   248,   247,   249,   249,   250,   251,   251,   252,
     253,   253,   254,   255,   256,   256,   257,   257,   257,   257,
     257,   257,   257,   259,   258,   261,   262,   263,   260,   265,
     266,   264,   267,   269,   270,   268,   272,   273,   271,   275,
     274,   276,   276,   277,   278,   278,   278,   279,   280,   281,
     280,   282,   282,   283,   284,   284,   285,   286,   285,   288,
     287,   289,   289,   290,   291,   292,   292,   294,   293,   295,
     293,   296,   297,   298,   298,   299,   300,   300,   301,   302,
     302,   303,   304,   305,   305,   306,   307,   307,   309,   308,
     310,   308,   312,   311,   313,   313,   315,   314,   316,   316,
     317,   318,   318,   319,   320,   321,   322,   323,   324,   325,
     325,   326,   327,   328,   328,   329,   330,   330,   331,   331,
     332,   333,   333,   334,   334,   335,   335,   336,   336,   336,
     336,   337,   338,   338,   338,   338,   339,   340,   341,   341,
     342,   343,   343,   344,   344,   345,   346,   346,   347,   347,
     347,   348,   349,   349,   351,   350,   352,   353,   353,   353,
     353,   353,   354,   354,   355,   355,   356,   356,   357,   357,
     358,   358,   359,   359,   360,   360,   360,   360,   360,   360,
     361,   362,   363,   364,   364,   365,   366,   367,   367,   368,
     369,   370,   370,   371,   371,   371,   371,   371,   371,   371,
     371,   372,   373,   374,   374,   375,   375,   376,   376,   377,
     377,   377,   378,   378,   379,   380,   380,   381,   381,   381,
     381,   382,   382,   382,   382,   382,   382,   382,   382,   383,
     384,   384,   384,   384,   384,   384,   384,   384,   384,   384,
     384,   384,   384,   384,   384,   384,   384,   384,   384,   384,
     384,   384,   384,   384,   384,   384,   384,   384,   384,   384,
     384,   384,   384,   384,   384,   384,   384,   384,   384,   384,
     384,   384,   384,   384,   384,   384,   384,   384,   384,   385,
     385,   386,   387,   387,   388,   389,   390,   391,   391,   392,
     391,   393,   393,   394,   394,   394,   394,   394,   395,   396,
     396,   397,   398,   398,   399,   400,   401,   401,   402,   402,
     403,   403,   403,   404,   404,   404,   405,   405,   405,   406,
     406,   406,   407,   407,   408,   408,   408,   408,   409,   409,
     410,   410,   411,   411
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  MapSetParser::yyr2_[] =
  {
         0,     2,     0,     4,     0,     2,     0,     2,     4,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     0,     1,     4,     1,     2,     2,     0,     1,     0,
       1,     3,     3,     0,     2,     3,     2,     0,     1,     0,
       2,     2,     0,     0,     5,     0,     2,     0,     5,     3,
       1,     1,     0,     1,     2,     0,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       0,     2,     7,     2,     1,     1,     1,     2,     1,     2,
       0,     1,     4,     0,     1,     0,     1,     0,     1,     0,
       1,     3,     1,     2,     1,     1,     4,     1,     2,     1,
       2,     1,     3,     1,     2,     1,     1,     1,     1,     2,
       1,     1,     2,     2,     0,     1,     0,     1,     2,     2,
       1,     0,     2,     1,     2,     0,     4,     1,     0,     2,
       0,     6,     0,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     0,     4,     1,     1,     2,     0,     1,     3,
       0,     2,     2,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     3,     0,     0,     0,     6,     0,
       0,     5,     6,     0,     0,     4,     0,     0,     4,     0,
       3,     0,     2,     2,     1,     1,     1,     2,     1,     0,
       6,     0,     1,     2,     0,     2,     1,     0,     5,     0,
       4,     0,     1,     2,     2,     0,     1,     0,     3,     0,
       3,     3,     2,     0,     1,     2,     0,     2,     1,     0,
       1,     2,     2,     0,     2,     1,     1,     1,     0,     3,
       0,     3,     0,     4,     1,     1,     0,     3,     0,     1,
       2,     0,     2,     1,     1,     1,     1,     2,     2,     0,
       2,     2,     2,     0,     2,     2,     0,     1,     1,     2,
       1,     1,     2,     2,     1,     2,     3,     1,     1,     1,
       2,     1,     1,     1,     2,     3,     1,     2,     0,     2,
       2,     0,     1,     1,     3,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     0,     4,     4,     1,     1,     1,
       1,     1,     0,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     0,     2,     2,     2,     0,     2,     1,
       2,     0,     1,     2,     2,     2,     2,     2,     2,     2,
       3,     1,     2,     1,     1,     2,     2,     0,     1,     2,
       2,     2,     0,     2,     2,     0,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     4,     6,     4,     4,     4,     4,     2,     2,     4,
       4,     4,     4,     2,     1,     4,     4,     4,     4,     6,
       6,     6,     4,     4,     4,     4,     4,     4,     4,     2,
       4,     4,     4,     4,     4,     4,     2,     8,     6,     6,
       6,     4,     4,     4,     4,     4,     1,     1,     1,     3,
       1,     7,     0,     1,     7,     2,     3,     5,     5,     0,
       7,     1,     1,     1,     1,     1,     1,     1,     4,     0,
       1,     2,     0,     1,     2,     2,     1,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const MapSetParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "IT_REWRITEVAR", "IT_DRIVER",
  "IT_SERVER", "IT_USER", "IT_PASSWORD", "IT_DATABASE", "IT_STEMURI",
  "IT_PRIMARYKEY", "IT_SHAREDVARS", "IT_PROMISCUOUS", "IT_INTERSECTION",
  "IT_DRACONIAN", "IT_VARNAMES", "IT_LABEL", "IT_GRAPH", "IT_SERVICE",
  "IT_BASE", "IT_PREFIX", "IT_DISTINCT", "IT_REDUCED", "GT_TIMES",
  "IT_CONSTRUCT", "IT_SELECT", "IT_FROM", "IT_NAMED", "IT_ORDER", "IT_BY",
  "IT_ASC", "IT_DESC", "IT_LIMIT", "IT_OFFSET", "IT_BINDINGS",
  "IT_MEMBERS", "IT_STARTS", "IT_ENDS", "IT_ANY", "IT_UNORDERED",
  "GT_LCURLEY", "GT_RCURLEY", "IT_WHERE", "GT_LPAREN", "GT_RPAREN",
  "IT_UNDEF", "GT_DOT", "IT_OPTIONAL", "IT_MINUS", "IT_UNION", "IT_FILTER",
  "GT_COMMA", "GT_SEMI", "IT_a", "GT_LBRACKET", "GT_RBRACKET", "GT_OR",
  "GT_AND", "GT_EQUAL", "GT_NEQUAL", "GT_LT", "GT_GT", "GT_LE", "GT_GE",
  "GT_PLUS", "GT_MINUS", "GT_DIVIDE", "GT_NOT", "IT_NOT", "IT_IN",
  "IT_IRI", "IT_URI", "IT_BNODE", "IT_COALESCE", "IT_IF", "IT_STRLANG",
  "IT_STRDT", "IT_EXISTS", "IT_SEPARATOR", "IT_STR", "IT_LANG",
  "IT_LANGMATCHES", "IT_DATATYPE", "IT_BOUND", "IT_sameTerm", "IT_isIRI",
  "IT_isURI", "IT_isBLANK", "IT_isLITERAL", "IT_REGEX", "GT_DTYPE",
  "IT_CONCAT", "IT_AS", "IT_GROUP", "IT_HAVING", "IT_COUNT", "IT_SUM",
  "IT_MIN", "IT_MAX", "IT_AVG", "IT_GROUP_CONCAT", "IT_SAMPLE",
  "IT_isNUMERIC", "GT_CARROT", "GT_OPT", "GT_PIPE", "IT_WITH",
  "IT_DEFAULT", "IT_ALL", "IT_USING", "IT_MD5", "IT_TO", "IT_YEAR",
  "IT_ADD", "IT_COPY", "IT_RAND", "IT_SHA512",
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
  "VAR2", "LANGTAG", "NIL", "$accept", "MapSet", "$@1",
  "_QAccessParm_E_Star", "_QConstructQuery_E_Star", "AccessParm",
  "_O_QIT_PROMISCUOUS_E_Or_QIT_VARNAMES_E_Or_QIT_DRACONIAN_E_C",
  "_QGraphTerm_E_Opt",
  "_O_QGT_LCURLEY_E_S_QGraphTerm_E_Opt_S_QGT_RCURLEY_E_S_QVarOrTerm_E_C",
  "_Q_O_QGT_LCURLEY_E_S_QGraphTerm_E_Opt_S_QGT_RCURLEY_E_S_QVarOrTerm_E_C_E_Plus",
  "PrimaryKeySpec", "_QDefaultPrimaryKey_E_Opt", "_QPrimaryKeySet_E_Opt",
  "PrimaryKeySet", "_O_QRDFLiteral_E_S_QGT_DOT_E_S_QRDFLiteral_E_C",
  "_Q_O_QRDFLiteral_E_S_QGT_DOT_E_S_QRDFLiteral_E_C_E_Star",
  "DefaultPrimaryKey", "Prologue", "_QBaseDecl_E_Opt",
  "_QPrefixDecl_E_Star", "BaseDecl", "PrefixDecl", "$@2", "$@3",
  "_QDatasetClause_E_Star", "SubSelect", "@4", "SelectClause",
  "_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C",
  "_Q_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C_E_Opt", "_O_QIT_AS_E_S_QVar_E_C",
  "_Q_O_QIT_AS_E_S_QVar_E_C_E_Opt",
  "_O_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_Q_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C_E_Plus",
  "_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_Plus_Or_QGT_TIMES_E_C",
  "_QIT_LABEL_GraphTerm_E_Opt", "ConstructQuery", "DatasetClause",
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
  "$@5",
  "_Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star",
  "_O_QIT_BINDINGS_E_S_QVar_E_Star_S_QGT_LCURLEY_E_S_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_Star_S_QGT_RCURLEY_E_C",
  "$@6",
  "_Q_O_QIT_BINDINGS_E_S_QVar_E_Star_S_QGT_LCURLEY_E_S_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_Star_S_QGT_RCURLEY_E_C_E_Opt",
  "BindingValue", "_QGT_DOT_E_Opt", "GroupGraphPattern", "$@7",
  "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C", "GroupGraphPatternSub",
  "_QTriplesBlock_E_Opt",
  "_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "OptionalGraphPattern", "@8", "GraphGraphPattern", "@9", "@10", "@11",
  "ServiceGraphPattern", "@12", "@13", "Bind", "MinusGraphPattern", "@14",
  "@15", "GroupOrUnionGraphPattern", "@16", "@17",
  "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@18",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "$@19", "_QIT_DISTINCT_E_Opt",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ExpressionList", "$@20",
  "ConstructTemplate", "$@21", "_QConstructTriples_E_Opt",
  "ConstructTriples", "_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C_E_Opt", "TriplesSameSubject",
  "$@22", "$@23", "PropertyListNotEmpty", "_O_QVerb_E_S_QObjectList_E_C",
  "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "Verb", "TriplesSameSubjectPath", "$@24", "$@25",
  "PropertyListNotEmptyPath", "$@26", "_O_QVerbPath_E_Or_QVerbSimple_E_C",
  "_O_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_C", "$@27",
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
  "Integer", "TriplesNode", "BlankNodePropertyList", "@28", "Generator",
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
  "$@29", "_O_QGT_TIMES_E_Or_QExpression_E_C",
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
  const MapSetParser::rhs_number_type
  MapSetParser::yyrhs_[] =
  {
       170,     0,    -1,    -1,   171,   186,   172,   173,    -1,    -1,
     172,   174,    -1,    -1,   173,   206,    -1,     3,   359,   399,
     399,    -1,     4,   399,    -1,     5,   399,    -1,     6,   399,
      -1,     7,   399,    -1,     8,   399,    -1,     9,   409,    -1,
      10,   179,    -1,    11,   175,    -1,    13,   178,    -1,    12,
      -1,    15,    -1,    14,    -1,    -1,   360,    -1,    40,   176,
      41,   357,    -1,   177,    -1,   178,   177,    -1,   180,   181,
      -1,    -1,   185,    -1,    -1,   182,    -1,    40,   184,    41,
      -1,   399,    46,   399,    -1,    -1,   184,   183,    -1,    54,
     399,    55,    -1,   187,   188,    -1,    -1,   189,    -1,    -1,
     188,   190,    -1,    19,   160,    -1,    -1,    -1,    20,   191,
     161,   192,   160,    -1,    -1,   193,   207,    -1,    -1,   196,
     195,   212,   214,   236,    -1,    25,   198,   204,    -1,    21,
      -1,    22,    -1,    -1,   197,    -1,    92,   359,    -1,    -1,
     199,    -1,    43,   361,   200,    44,    -1,   359,    -1,   391,
      -1,   384,    -1,   279,    -1,   399,    -1,   403,    -1,   407,
      -1,   201,    -1,   202,    -1,   203,   202,    -1,   203,    -1,
      23,    -1,    -1,    16,   360,    -1,   205,    24,   287,   193,
     212,   214,   236,    -1,    26,   208,    -1,   209,    -1,   210,
      -1,   211,    -1,    27,   211,    -1,   409,    -1,   213,   247,
      -1,    -1,    42,    -1,   215,   216,   217,   218,    -1,    -1,
     219,    -1,    -1,   222,    -1,    -1,   225,    -1,    -1,   231,
      -1,    93,    29,   220,    -1,   221,    -1,   220,   221,    -1,
     384,    -1,   279,    -1,    43,   361,   200,    44,    -1,   359,
      -1,    94,   223,    -1,   224,    -1,   223,   224,    -1,   278,
      -1,    28,    29,   226,    -1,   227,    -1,   226,   227,    -1,
     229,    -1,   230,    -1,    30,    -1,    31,    -1,   228,   383,
      -1,   278,    -1,   359,    -1,   234,   232,    -1,   235,   233,
      -1,    -1,   235,    -1,    -1,   234,    -1,    32,   147,    -1,
      33,   147,    -1,   244,    -1,    -1,   237,   359,    -1,   245,
      -1,   238,   245,    -1,    -1,    43,   240,   238,    44,    -1,
     168,    -1,    -1,   241,   239,    -1,    -1,    34,   237,    40,
     243,   241,    41,    -1,    -1,   242,    -1,   409,    -1,   399,
      -1,   403,    -1,   407,    -1,    45,    -1,   359,    -1,    -1,
      46,    -1,    -1,    40,   248,   249,    41,    -1,   194,    -1,
     250,    -1,   251,   253,    -1,    -1,   254,    -1,   257,   246,
     251,    -1,    -1,   253,   252,    -1,   308,   256,    -1,    46,
     251,    -1,    -1,   255,    -1,   271,    -1,   258,    -1,   268,
      -1,   260,    -1,   264,    -1,   277,    -1,   267,    -1,    -1,
      47,   259,   247,    -1,    -1,    -1,    -1,    17,   261,   262,
     358,   263,   247,    -1,    -1,    -1,    18,   265,   266,   358,
     247,    -1,   123,    43,   361,    92,   359,    44,    -1,    -1,
      -1,    48,   269,   270,   247,    -1,    -1,    -1,   272,   273,
     247,   276,    -1,    -1,    49,   275,   247,    -1,    -1,   276,
     274,    -1,    50,   278,    -1,   383,    -1,   384,    -1,   279,
      -1,   409,   280,    -1,   168,    -1,    -1,    43,   282,   361,
     281,   284,    44,    -1,    -1,    21,    -1,    51,   361,    -1,
      -1,   284,   283,    -1,   168,    -1,    -1,    43,   361,   286,
     284,    44,    -1,    -1,    40,   288,   289,    41,    -1,    -1,
     290,    -1,   293,   292,    -1,    46,   289,    -1,    -1,   291,
      -1,    -1,   357,   294,   296,    -1,    -1,   349,   295,   301,
      -1,   307,   303,   300,    -1,   307,   303,    -1,    -1,   297,
      -1,    52,   298,    -1,    -1,   300,   299,    -1,   302,    -1,
      -1,   296,    -1,   306,   305,    -1,    51,   306,    -1,    -1,
     305,   304,    -1,   356,    -1,   358,    -1,    53,    -1,    -1,
     357,   309,   311,    -1,    -1,   349,   310,   319,    -1,    -1,
     313,   312,   303,   318,    -1,   320,    -1,   321,    -1,    -1,
     313,   315,   303,    -1,    -1,   314,    -1,    52,   316,    -1,
      -1,   318,   317,    -1,   302,    -1,   322,    -1,   359,    -1,
     323,    -1,   326,   325,    -1,   105,   326,    -1,    -1,   325,
     324,    -1,   331,   328,    -1,    66,   331,    -1,    -1,   328,
     327,    -1,   337,   330,    -1,    -1,   332,    -1,   329,    -1,
     103,   329,    -1,   336,    -1,    41,    -1,   348,    41,    -1,
      51,   333,    -1,    41,    -1,   348,   334,    -1,    51,   348,
      41,    -1,    23,    -1,   104,    -1,    64,    -1,    40,   335,
      -1,   338,    -1,   409,    -1,    53,    -1,    67,   339,    -1,
      43,   322,    44,    -1,   344,    -1,   105,   345,    -1,    -1,
     341,   340,    -1,   345,   341,    -1,    -1,   342,    -1,   345,
      -1,    43,   343,    44,    -1,   347,    -1,   409,    -1,    53,
      -1,   409,    -1,    53,    -1,   103,   346,    -1,   147,    -1,
     352,    -1,   350,    -1,    -1,    54,   351,   296,    55,    -1,
     354,    43,   355,    44,    -1,    35,    -1,    36,    -1,    37,
      -1,    38,    -1,    39,    -1,    -1,   353,    -1,   356,    -1,
     355,   356,    -1,   357,    -1,   349,    -1,   359,    -1,   360,
      -1,   359,    -1,   409,    -1,   165,    -1,   166,    -1,   409,
      -1,   399,    -1,   403,    -1,   407,    -1,   411,    -1,   168,
      -1,   362,    -1,   365,   364,    -1,    56,   365,    -1,    -1,
     364,   363,    -1,   368,   367,    -1,    57,   368,    -1,    -1,
     367,   366,    -1,   369,    -1,   372,   370,    -1,    -1,   371,
      -1,    58,   372,    -1,    59,   372,    -1,    60,   372,    -1,
      61,   372,    -1,    62,   372,    -1,    63,   372,    -1,    69,
     285,    -1,    68,    69,   285,    -1,   373,    -1,   379,   378,
      -1,   405,    -1,   406,    -1,    23,   381,    -1,    66,   381,
      -1,    -1,   375,    -1,    64,   379,    -1,    65,   379,    -1,
     374,   376,    -1,    -1,   378,   377,    -1,   381,   380,    -1,
      -1,   380,   375,    -1,    67,   382,    -1,    64,   382,    -1,
      65,   382,    -1,   382,    -1,   383,    -1,   384,    -1,   397,
      -1,   399,    -1,   403,    -1,   407,    -1,   359,    -1,   391,
      -1,    43,   361,    44,    -1,    79,    43,   361,    44,    -1,
      80,    43,   361,    44,    -1,    81,    43,   361,    51,   361,
      44,    -1,    82,    43,   361,    44,    -1,    83,    43,   359,
      44,    -1,    70,    43,   361,    44,    -1,    71,    43,   361,
      44,    -1,    72,   385,    -1,   115,   168,    -1,   138,    43,
     361,    44,    -1,   135,    43,   361,    44,    -1,   127,    43,
     361,    44,    -1,   121,    43,   361,    44,    -1,    91,   285,
      -1,   388,    -1,   142,    43,   361,    44,    -1,   139,    43,
     361,    44,    -1,   137,    43,   361,    44,    -1,   133,    43,
     361,    44,    -1,   124,    43,   361,    51,   361,    44,    -1,
     134,    43,   361,    51,   361,    44,    -1,   141,    43,   361,
      51,   361,    44,    -1,   112,    43,   361,    44,    -1,   144,
      43,   361,    44,    -1,   136,    43,   361,    44,    -1,   132,
      43,   361,    44,    -1,   129,    43,   361,    44,    -1,   125,
      43,   361,    44,    -1,   120,    43,   361,    44,    -1,   118,
     168,    -1,   110,    43,   361,    44,    -1,   143,    43,   361,
      44,    -1,   140,    43,   361,    44,    -1,   131,    43,   361,
      44,    -1,   122,    43,   361,    44,    -1,   116,    43,   361,
      44,    -1,    73,   285,    -1,    74,    43,   361,    51,   361,
      51,   361,    44,    -1,    75,    43,   361,    51,   361,    44,
      -1,    76,    43,   361,    51,   361,    44,    -1,    84,    43,
     361,    51,   361,    44,    -1,    85,    43,   361,    44,    -1,
      86,    43,   361,    44,    -1,    87,    43,   361,    44,    -1,
      88,    43,   361,    44,    -1,   102,    43,   361,    44,    -1,
     386,    -1,   389,    -1,   390,    -1,    43,   361,    44,    -1,
     168,    -1,    89,    43,   361,    51,   361,   387,    44,    -1,
      -1,   283,    -1,   130,    43,   361,    51,   361,   387,    44,
      -1,    77,   247,    -1,    68,    77,   247,    -1,    95,    43,
     282,   393,    44,    -1,   394,    43,   282,   361,    44,    -1,
      -1,   100,    43,   282,   361,   392,   396,    44,    -1,    23,
      -1,   361,    -1,    96,    -1,    97,    -1,    98,    -1,    99,
      -1,   101,    -1,    52,    78,    58,   408,    -1,    -1,   395,
      -1,   409,   398,    -1,    -1,   280,    -1,   408,   402,    -1,
      90,   409,    -1,   167,    -1,   400,    -1,    -1,   401,    -1,
     404,    -1,   405,    -1,   406,    -1,   147,    -1,   148,    -1,
     149,    -1,   150,    -1,   151,    -1,   152,    -1,   153,    -1,
     154,    -1,   155,    -1,   145,    -1,   146,    -1,   156,    -1,
     158,    -1,   157,    -1,   159,    -1,   160,    -1,   410,    -1,
     162,    -1,   161,    -1,   163,    -1,   164,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  MapSetParser::yyprhs_[] =
  {
         0,     0,     3,     4,     9,    10,    13,    14,    17,    22,
      25,    28,    31,    34,    37,    40,    43,    46,    49,    51,
      53,    55,    56,    58,    63,    65,    68,    71,    72,    74,
      75,    77,    81,    85,    86,    89,    93,    96,    97,    99,
     100,   103,   106,   107,   108,   114,   115,   118,   119,   125,
     129,   131,   133,   134,   136,   139,   140,   142,   147,   149,
     151,   153,   155,   157,   159,   161,   163,   165,   168,   170,
     172,   173,   176,   184,   187,   189,   191,   193,   196,   198,
     201,   202,   204,   209,   210,   212,   213,   215,   216,   218,
     219,   221,   225,   227,   230,   232,   234,   239,   241,   244,
     246,   249,   251,   255,   257,   260,   262,   264,   266,   268,
     271,   273,   275,   278,   281,   282,   284,   285,   287,   290,
     293,   295,   296,   299,   301,   304,   305,   310,   312,   313,
     316,   317,   324,   325,   327,   329,   331,   333,   335,   337,
     339,   340,   342,   343,   348,   350,   352,   355,   356,   358,
     362,   363,   366,   369,   372,   373,   375,   377,   379,   381,
     383,   385,   387,   389,   390,   394,   395,   396,   397,   404,
     405,   406,   412,   419,   420,   421,   426,   427,   428,   433,
     434,   438,   439,   442,   445,   447,   449,   451,   454,   456,
     457,   464,   465,   467,   470,   471,   474,   476,   477,   483,
     484,   489,   490,   492,   495,   498,   499,   501,   502,   506,
     507,   511,   515,   518,   519,   521,   524,   525,   528,   530,
     531,   533,   536,   539,   540,   543,   545,   547,   549,   550,
     554,   555,   559,   560,   565,   567,   569,   570,   574,   575,
     577,   580,   581,   584,   586,   588,   590,   592,   595,   598,
     599,   602,   605,   608,   609,   612,   615,   616,   618,   620,
     623,   625,   627,   630,   633,   635,   638,   642,   644,   646,
     648,   651,   653,   655,   657,   660,   664,   666,   669,   670,
     673,   676,   677,   679,   681,   685,   687,   689,   691,   693,
     695,   698,   700,   702,   704,   705,   710,   715,   717,   719,
     721,   723,   725,   726,   728,   730,   733,   735,   737,   739,
     741,   743,   745,   747,   749,   751,   753,   755,   757,   759,
     761,   763,   766,   769,   770,   773,   776,   779,   780,   783,
     785,   788,   789,   791,   794,   797,   800,   803,   806,   809,
     812,   816,   818,   821,   823,   825,   828,   831,   832,   834,
     837,   840,   843,   844,   847,   850,   851,   854,   857,   860,
     863,   865,   867,   869,   871,   873,   875,   877,   879,   881,
     885,   890,   895,   902,   907,   912,   917,   922,   925,   928,
     933,   938,   943,   948,   951,   953,   958,   963,   968,   973,
     980,   987,   994,   999,  1004,  1009,  1014,  1019,  1024,  1029,
    1032,  1037,  1042,  1047,  1052,  1057,  1062,  1065,  1074,  1081,
    1088,  1095,  1100,  1105,  1110,  1115,  1120,  1122,  1124,  1126,
    1130,  1132,  1140,  1141,  1143,  1151,  1154,  1158,  1164,  1170,
    1171,  1179,  1181,  1183,  1185,  1187,  1189,  1191,  1193,  1198,
    1199,  1201,  1204,  1205,  1207,  1210,  1213,  1215,  1217,  1218,
    1220,  1222,  1224,  1226,  1228,  1230,  1232,  1234,  1236,  1238,
    1240,  1242,  1244,  1246,  1248,  1250,  1252,  1254,  1256,  1258,
    1260,  1262,  1264,  1266
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  MapSetParser::yyrline_[] =
  {
         0,   394,   394,   394,   400,   402,   406,   408,   412,   421,
     424,   427,   430,   433,   436,   439,   441,   445,   451,   454,
     457,   463,   466,   470,   482,   483,   487,   490,   492,   495,
     497,   501,   505,   510,   512,   516,   523,   527,   529,   533,
     535,   539,   545,   547,   545,   557,   560,   568,   568,   579,
     587,   590,   597,   600,   605,   612,   615,   620,   627,   630,
     633,   636,   639,   642,   645,   649,   654,   657,   665,   668,
     674,   677,   684,   694,   701,   702,   706,   712,   718,   725,
     732,   734,   739,   746,   749,   754,   757,   762,   765,   770,
     774,   778,   785,   788,   795,   798,   801,   804,   810,   816,
     819,   826,   831,   838,   842,   850,   852,   860,   863,   871,
     879,   880,   887,   891,   899,   902,   907,   910,   914,   920,
     928,   933,   936,   943,   946,   952,   952,   958,   964,   967,
     974,   974,   983,   986,   990,   993,   996,   999,  1002,  1005,
    1011,  1013,  1018,  1018,  1030,  1031,  1036,  1040,  1042,  1052,
    1056,  1059,  1075,  1080,  1084,  1087,  1091,  1092,  1093,  1094,
    1095,  1096,  1097,  1101,  1101,  1116,  1119,  1121,  1116,  1132,
    1135,  1132,  1144,  1150,  1153,  1150,  1163,  1166,  1163,  1176,
    1176,  1190,  1192,  1196,  1207,  1208,  1209,  1213,  1221,  1225,
    1225,  1234,  1237,  1244,  1250,  1252,  1266,  1269,  1269,  1279,
    1279,  1287,  1289,  1294,  1299,  1303,  1305,  1309,  1309,  1312,
    1312,  1319,  1324,  1328,  1330,  1335,  1339,  1341,  1346,  1350,
    1352,  1357,  1362,  1366,  1368,  1372,  1379,  1383,  1391,  1391,
    1394,  1394,  1400,  1400,  1406,  1407,  1411,  1411,  1416,  1418,
    1422,  1425,  1427,  1431,  1435,  1439,  1445,  1449,  1453,  1456,
    1458,  1462,  1466,  1471,  1473,  1479,  1482,  1484,  1490,  1491,
    1497,  1501,  1502,  1506,  1507,  1511,  1512,  1516,  1517,  1518,
    1519,  1523,  1527,  1530,  1533,  1536,  1542,  1546,  1549,  1551,
    1555,  1558,  1560,  1564,  1565,  1569,  1573,  1574,  1578,  1579,
    1580,  1584,  1589,  1590,  1594,  1594,  1607,  1632,  1635,  1638,
    1641,  1644,  1651,  1654,  1659,  1663,  1670,  1671,  1675,  1678,
    1682,  1685,  1691,  1692,  1696,  1699,  1702,  1705,  1708,  1709,
    1715,  1720,  1729,  1736,  1739,  1747,  1756,  1763,  1766,  1773,
    1778,  1789,  1792,  1796,  1799,  1802,  1805,  1808,  1811,  1814,
    1817,  1823,  1828,  1837,  1840,  1847,  1850,  1857,  1860,  1865,
    1868,  1872,  1886,  1889,  1897,  1906,  1909,  1916,  1919,  1922,
    1925,  1929,  1930,  1931,  1932,  1935,  1938,  1941,  1944,  1948,
    1954,  1957,  1960,  1963,  1966,  1969,  1972,  1976,  1979,  1982,
    1985,  1988,  1991,  1994,  1997,  1998,  2001,  2004,  2007,  2010,
    2013,  2016,  2019,  2022,  2025,  2028,  2031,  2034,  2037,  2040,
    2043,  2046,  2049,  2052,  2055,  2058,  2061,  2065,  2068,  2071,
    2074,  2077,  2080,  2083,  2086,  2089,  2092,  2093,  2094,  2100,
    2103,  2110,  2117,  2120,  2124,  2130,  2137,  2144,  2147,  2151,
    2151,  2163,  2167,  2171,  2174,  2177,  2180,  2183,  2189,  2195,
    2198,  2202,  2212,  2215,  2220,  2228,  2235,  2239,  2247,  2251,
    2255,  2256,  2257,  2261,  2262,  2263,  2267,  2268,  2269,  2273,
    2274,  2275,  2279,  2280,  2284,  2285,  2286,  2287,  2291,  2292,
    2296,  2297,  2301,  2302
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
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int MapSetParser::yyeof_ = 0;
  const int MapSetParser::yylast_ = 2069;
  const int MapSetParser::yynnts_ = 243;
  const int MapSetParser::yyempty_ = -2;
  const int MapSetParser::yyfinal_ = 3;
  const int MapSetParser::yyterror_ = 1;
  const int MapSetParser::yyerrcode_ = 256;
  const int MapSetParser::yyntokens_ = 169;

  const unsigned int MapSetParser::yyuser_token_number_max_ = 423;
  const MapSetParser::token_number_type MapSetParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 4693 "lib/MapSetParser/MapSetParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 2308 "lib/MapSetParser/MapSetParser.ypp"
 /*** Additional Code ***/

void w3c_sw::MapSetParser::error(const MapSetParser::location_type& l,
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

    MapSetDriver::MapSetDriver (std::string baseURI, AtomFactory* atomFactory) : 
	YaccDriver(baseURI, atomFactory), curSubject(NULL), curPredicate(NULL), 
	curBGP(NULL), curFilter(NULL), 
	curBindingsClause(NULL), curBinding(NULL), curExprList(NULL), 
	countStar(false), root(NULL), unnestTree(false), 
	lastRuleTerm(TTerm::Unbound, TTerm::Unbound),
	lastRuleTermSet(false)
{
}

    MapSetDriver::~MapSetDriver ()
{
}

MapSet* MapSetDriver::parse (IStreamContext& in)
{
    sharedVarsSet = false;
    root = NULL;
    curBGP = NULL;
    curOp = NULL;
    curGraphName = NULL;
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


