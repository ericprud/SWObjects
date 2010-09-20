
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

  case 15:

/* Line 678 of lalr1.cc  */
#line 414 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.sharedVarsSet = true;
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 417 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.lastRuleTermSet = false;
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 423 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_PROMISCUOUS;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 426 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_VARNAMES;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 429 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_DRACONIAN;
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 435 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = NULL;
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 442 "lib/MapSetParser/MapSetParser.ypp"
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
#line 478 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->keyMap[(yysemantic_stack_[(3) - (1)].p_RDFLiteral)->getLexicalValue()] = (yysemantic_stack_[(3) - (3)].p_RDFLiteral)->getLexicalValue();
    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 489 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->primaryKey = (yysemantic_stack_[(3) - (2)].p_RDFLiteral);
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 512 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 518 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 520 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 522 "lib/MapSetParser/MapSetParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 530 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 532 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 534 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(5) - (1)].p_Project).distinctness, (yysemantic_stack_[(5) - (1)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier))));
      }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 542 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 550 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 553 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 560 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 568 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 575 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 583 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 590 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 593 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 596 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 599 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 602 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 605 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 608 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 617 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 620 "lib/MapSetParser/MapSetParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 628 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 631 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 638 "lib/MapSetParser/MapSetParser.ypp"
    {
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	Construct* constr = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(6) - (3)].p_BasicGraphPattern), (yysemantic_stack_[(6) - (4)].p_DatasetClauses), (yysemantic_stack_[(6) - (5)].p_WhereClause), (yysemantic_stack_[(6) - (6)].p_SolutionModifier));
	driver.root->maps.push_back(LabeledConstruct((yysemantic_stack_[(6) - (1)].p_TTerm), constr));
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 647 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 650 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 658 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 670 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 676 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 682 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 689 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp ? driver.curOp : new DefaultGraphPattern(), (yysemantic_stack_[(3) - (3)].p_BindingsClause));
	driver.curOp = NULL;
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 702 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 709 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = NULL;
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 717 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 725 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 733 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 741 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 748 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 751 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 758 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 761 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 764 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 767 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 773 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 779 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 782 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 794 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 801 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 805 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 815 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 823 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 826 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 834 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 843 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 850 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 854 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 862 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 870 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 877 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 883 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 896 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTermList) = new TTermList;
	(yyval.p_TTermList)->push_back((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 900 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTermList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_TTermList) = (yysemantic_stack_[(2) - (1)].p_TTermList);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 907 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 910 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 916 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding = new Binding();
      }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 918 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BindingValue) = driver.curBinding;
	  driver.curBinding = NULL;
      }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 925 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 928 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBindingsClause->push_back((yysemantic_stack_[(2) - (2)].p_BindingValue));
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 935 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBindingsClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_TTermList));
      }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 937 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BindingsClause) = driver.curBindingsClause;
	  driver.curBindingsClause = NULL;
      }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 944 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BindingsClause) = NULL;
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 951 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 954 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 957 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 960 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 963 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 966 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 973 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 976 "lib/MapSetParser/MapSetParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1050 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1052 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.curFilter;
      }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 1054 "lib/MapSetParser/MapSetParser.ypp"
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

  case 163:

/* Line 678 of lalr1.cc  */
#line 1066 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 1068 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1070 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1073 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1081 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1083 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1085 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(5) - (4)].p_TTerm), driver.curOp, driver.atomFactory, false));
      }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1092 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 1094 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 1096 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.curOp));
      }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 1104 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1107 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 1109 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 1117 "lib/MapSetParser/MapSetParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 1122 "lib/MapSetParser/MapSetParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 1137 "lib/MapSetParser/MapSetParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    if (driver.curOp == NULL)
		driver.ensureBasicGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 1154 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 1162 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 1166 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 1168 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = NULL;
      }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 1175 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 1178 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 1185 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 1193 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 1200 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_DistExprPair).distinctness = (yysemantic_stack_[(4) - (2)].p_distinctness);
	  (yyval.p_DistExprPair).p_Expression = (yysemantic_stack_[(4) - (3)].p_Expression);
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1211 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1214 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1216 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1224 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 1226 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 1254 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 1257 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 1317 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 1324 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 1328 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 1340 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 1344 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 1353 "lib/MapSetParser/MapSetParser.ypp"
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

  case 232:

/* Line 678 of lalr1.cc  */
#line 1378 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 1381 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 1384 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 1387 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 1390 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 1397 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 1405 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 1409 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 1421 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 1428 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 1431 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 1442 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 1445 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 1448 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 1451 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 1455 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 1466 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 1475 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 1482 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 1485 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 1493 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 1502 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 1509 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 1512 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 1524 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_GeneralComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_GeneralComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_GeneralComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 1535 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 1538 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 1541 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 1544 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 1547 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 1550 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 1553 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 1556 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 1563 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 1575 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 1584 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 1587 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 1594 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 1597 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 1604 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 1612 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 1615 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 1619 "lib/MapSetParser/MapSetParser.ypp"
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

  case 287:

/* Line 678 of lalr1.cc  */
#line 1633 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 1636 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 1644 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 1653 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 1656 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 1663 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 1666 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 1669 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 1679 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 1682 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 1685 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 1688 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 1695 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 1701 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 1704 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 1707 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 1710 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 1713 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 1716 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 1719 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 1723 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_blank, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 1726 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 1730 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 1733 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 1736 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 1739 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 1742 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 1745 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 1748 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 1751 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 1762 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 1765 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 1772 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_regex, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 1779 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 1786 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 1793 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 1800 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 1803 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_sum, (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 1806 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_min, (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 1809 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_max, (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 1812 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_avg, (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 1815 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_sample, (yysemantic_stack_[(2) - (2)].p_DistExprPair).distinctness, (yysemantic_stack_[(2) - (2)].p_DistExprPair).p_Expression));
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 1819 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 1821 "lib/MapSetParser/MapSetParser.ypp"
    {
	  // x = new ArgList($2, driver.curExprList);
	  delete driver.curExprList;
	  driver.curExprList = NULL;
	  w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // $$ = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group-concat, $3, $4.p_Expression, $4.separator));
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 1831 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 1838 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 1844 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 1851 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 1861 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 1869 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 1877 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 1884 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 1888 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 1896 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 2685 "lib/MapSetParser/MapSetParser.cpp"
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
  const short int MapSetParser::yypact_ninf_ = -463;
  const short int
  MapSetParser::yypact_[] =
  {
      -463,    35,    21,  -463,   -74,  -463,  -463,  -463,  -463,   248,
      36,   -73,    96,    96,    96,    96,   108,    29,    49,    50,
     517,  -463,  -463,  -463,  -463,  -463,    96,  -463,  -463,  -463,
    -463,  -463,   -67,  -463,  -463,  -463,  -463,  -463,  -463,  -463,
    -463,    96,  -463,    75,  -463,  -463,  -463,  -463,  -463,  1286,
    -463,    50,  -463,  -463,  -463,  -463,  -463,  -463,  -463,  -463,
    -463,  -463,  -463,  -463,  -463,  -463,    85,  -463,  -463,  -463,
    -463,  -463,  -463,  -463,  -463,  -463,  -463,     5,    96,   108,
    -463,  -463,  -463,  -463,    63,  -463,  -463,  -463,    84,  -463,
      98,  -463,  -463,  -463,  -463,   -20,   938,  -463,  -463,    28,
    -463,  -463,   106,  -463,  -463,  -463,   863,     2,  -463,    96,
    -463,  -463,  -463,  -463,  -463,  -463,   116,  -463,   119,  -463,
    -463,  -463,  -463,   118,  -463,   -12,  -463,  -463,    77,   135,
    -463,    -6,  -463,   863,  -463,  -463,    -6,   985,    -6,   108,
    -463,  -463,  -463,  -463,  -463,   150,  -463,    93,  -463,  -463,
     156,  -463,   143,   985,  -463,  -463,  -463,  -463,  -463,  -463,
    -463,  -463,   894,  -463,  -463,  -463,  -463,   994,  1297,   173,
    -463,   742,   -73,  -463,  -463,  -463,  -463,  -463,  -463,  -463,
    -463,  -463,  1066,   164,   170,   -27,   -21,   172,   174,   185,
     135,   135,   191,   193,   203,   208,   218,   222,   228,   230,
     231,   232,   233,   994,  -463,  -463,  -463,  -463,  -463,  -463,
    -463,   -17,  1066,  1297,  -463,  -463,  -463,  -463,  -463,   202,
     115,  -463,   198,  -463,  -463,   200,  -463,  -463,  -463,   234,
     -22,  -463,   225,   227,  1143,  1143,  1143,   236,   238,   238,
     238,   238,   239,   238,  -463,   192,  -463,  -463,  -463,  -463,
      74,  -463,  -463,  -463,  -463,  -463,  -463,  -463,  -463,  -463,
    -463,  -463,   -17,  1066,  1066,  1066,  -463,  -463,  1066,  -463,
    -463,  -463,  1066,  1066,  1066,  -463,  -463,  1066,  1066,  1066,
    1066,   -73,  1066,  1066,  1066,  1066,  1066,  1066,  -463,   262,
    -463,  -463,   242,  -463,   838,   183,   184,  -463,  -463,   256,
     259,  -463,  -463,  -463,   717,  -463,  -463,   182,   863,  -463,
    -463,  -463,  -463,    -6,  -463,   985,  -463,  -463,  -463,  -463,
     262,   262,  -463,  -463,  -463,  -463,   262,  -463,   -73,  -463,
     249,   240,   235,  1066,  1066,  1066,  1066,  1066,  1066,   -21,
     -21,  -463,  -463,   -35,     0,  -463,  -463,   254,   258,   261,
    -463,   252,   260,   263,   265,   266,   264,   268,   269,   267,
     272,   273,   276,   277,   274,  -463,  1066,  -463,  -463,  -463,
     838,  -463,   257,  -463,  -463,  -463,  -463,  -463,  -463,  -463,
    -463,  -463,  -463,  -463,  1066,  -463,  -463,  1220,  -463,  -463,
    -463,  -463,  -463,  -463,  -463,  -463,   284,  -463,  -463,  -463,
    -463,  1297,   281,  -463,  -463,  -463,  -463,  -463,  -463,  -463,
    -463,  -463,  -463,  -463,  -463,  -463,   985,  -463,   620,  1066,
    1066,  -463,  -463,  1066,  -463,  1066,  -463,  -463,  -463,  -463,
    -463,  -463,  -463,  -463,  -463,  1066,  1066,     0,  -463,  -463,
    -463,  1066,  1066,  -463,  -463,  -463,  -463,  -463,  1066,  1066,
    1066,  -463,  -463,  1066,  -463,  -463,  1066,  -463,  -463,  -463,
    -463,  1066,  -463,  -463,  -463,   192,  -463,    77,  -463,  -463,
    -463,  -463,  -463,  -463,   863,   135,    26,  -463,  -463,  -463,
     286,   287,  -463,  -463,  -463,  -463,  -463,  -463,  -463,  -463,
    -463,    -5,   282,   288,   290,   291,   292,   289,  -463,   293,
    -463,   -37,   -37,   135,   135,  -463,  -463,  -463,  -463,  -463,
    -463,  -463,  -463,  -463,  1066,  -463,  1066,  -463,  -463,  -463,
    -463,  -463,   294,    -3,  -463,  -463,   135,  -463,  -463,   279,
    1089,   188,  -463,   297,  -463,  -463,   135,  -463,  -463,  -463,
    -463,   444,  -463,  -463,  -463,  -463,  -463,  -463,   270,  -463,
     298,  -463,  -463,   135,  -463,  -463,   295,  -463,  -463,    96,
    -463
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  MapSetParser::yydefact_[] =
  {
         2,     0,    36,     1,     0,     4,    38,    37,    40,     6,
      35,     0,     0,     0,     0,     0,     0,    26,     0,     0,
       3,     5,    41,    39,   247,   248,     0,   368,   370,   369,
     371,     9,   352,    10,    11,    12,   372,   375,   374,    13,
     373,     0,    14,    28,    27,    17,    19,    18,    15,    20,
      23,    16,   366,   367,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   376,   377,   254,     0,     7,    21,   250,
     251,   354,   355,   356,   252,   249,   253,     0,     0,     0,
     350,   351,   353,   348,     0,    32,    25,    29,     0,    24,
       0,    42,     8,   349,    34,     0,     0,   198,    69,     0,
      30,    33,     0,    22,   243,   244,   200,    78,    43,     0,
     232,   233,   234,   235,   236,   229,     0,   201,   204,   208,
     228,   227,   238,     0,   206,     0,    79,    70,    81,     0,
      31,     0,   199,   200,   205,   202,   218,   237,     0,     0,
      71,    72,    73,    74,    76,     0,    68,    83,    82,   137,
     129,   226,     0,   237,   225,   245,   246,   203,   219,   209,
     217,   242,   237,   239,   241,   207,    75,     0,     0,    85,
      84,   142,     0,    77,   130,   118,   230,   215,   222,   224,
     231,   240,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,    90,    93,    95,    92,   322,   323,
     324,     0,     0,    96,    97,    99,   183,   181,   182,     0,
      87,    86,    50,   139,    44,     0,   140,   149,   143,   153,
       0,   119,   210,   220,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   302,    53,   255,   258,   262,   264,
     274,   276,   287,   290,   295,   296,   297,   303,   298,   299,
     300,   301,   346,     0,     0,     0,   326,   312,     0,   195,
     313,   194,     0,     0,     0,   330,   331,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    91,   188,
     185,   184,     0,    98,     0,     0,     0,    80,    88,   112,
     114,    48,    49,    51,     0,    45,   138,   141,   142,   154,
     151,   127,   120,   212,   216,   237,   223,   293,   294,   292,
     188,   188,   333,   334,   335,   336,   188,   337,     0,    54,
       0,   256,   260,     0,     0,     0,     0,     0,     0,     0,
       0,   275,   265,   277,   289,   347,   345,     0,     0,     0,
     196,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   189,     0,   304,   105,   106,
     100,   101,     0,   103,   104,   108,   109,   116,   117,   110,
     113,   111,   115,    67,     0,    63,    64,    66,    47,    59,
      56,    58,    57,    60,    61,    62,    78,   163,   167,   160,
     170,     0,   146,   150,   144,   155,   158,   159,   156,   157,
     174,   145,   152,   125,   213,   214,   237,   221,     0,     0,
       0,    52,    94,     0,   259,     0,   263,   266,   267,   268,
     269,   270,   271,   272,   273,     0,     0,   282,   288,   278,
     279,     0,     0,   291,   310,   311,   325,   191,     0,     0,
       0,   305,   306,     0,   308,   309,     0,   318,   319,   320,
     321,     0,   186,   102,   107,    53,    65,    81,   164,   168,
     161,   171,   180,   147,   142,     0,     0,   211,   340,   341,
       0,     0,   338,   257,   261,   284,   285,   283,   286,   280,
     281,     0,     0,     0,     0,     0,     0,   328,   191,     0,
      46,     0,     0,     0,     0,   148,   178,   128,   123,   126,
     332,   193,   191,   197,     0,   192,     0,   315,   316,   307,
     317,   329,     0,     0,    55,   165,     0,   162,   172,   175,
       0,   343,   190,     0,   327,   187,     0,   169,   176,   179,
     135,     0,   121,   136,   132,   133,   134,   131,     0,   344,
       0,   314,   166,     0,   124,   122,     0,   339,   177,     0,
     342
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yypgoto_[] =
  {
      -463,  -463,  -463,  -463,  -463,  -463,  -463,   301,   303,  -463,
    -463,  -463,  -463,  -463,  -463,  -463,  -463,  -463,  -463,  -463,
    -463,  -463,  -463,  -463,  -463,  -463,  -463,  -463,  -463,  -463,
    -463,  -160,  -463,   -45,  -463,  -463,  -463,  -463,  -463,  -463,
    -463,  -463,   205,   -44,  -463,  -112,  -463,  -463,  -463,  -463,
    -463,  -463,   154,  -463,  -463,   145,  -463,  -463,   -10,  -463,
    -463,  -463,  -463,  -463,  -463,    61,    64,  -463,  -463,  -463,
    -463,  -463,  -463,  -463,  -463,  -463,  -179,  -183,  -463,  -463,
    -463,  -298,  -463,  -463,  -463,  -463,  -463,  -463,  -463,  -463,
    -463,  -463,  -463,  -463,  -463,  -463,  -463,  -463,  -463,  -463,
    -463,  -463,  -463,  -463,  -463,  -463,  -463,  -463,  -463,  -463,
    -293,  -152,   102,  -463,  -172,  -132,  -462,   -50,   -92,  -463,
    -463,  -463,  -463,   241,  -463,  -463,  -463,   -77,  -463,  -463,
     -19,  -463,  -463,  -463,  -463,  -463,  -463,   -49,  -463,  -463,
      51,    55,  -128,  -463,  -463,  -463,  -463,  -463,  -463,  -104,
     -94,  -240,   -11,     3,   196,  -463,  -463,  -463,   -54,  -463,
    -463,   -53,  -463,  -463,  -463,  -154,  -463,  -463,   -66,  -463,
    -463,  -463,  -170,  -463,  -174,     7,  -156,  -137,  -463,  -463,
    -463,  -463,  -463,  -286,  -463,  -463,  -463,  -463,  -463,  -463,
      -9,  -463,  -463,  -463,    41,  -463,    32,    37,    69,  -180,
      33,  -463,  -463
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yydefgoto_[] =
  {
        -1,     1,     2,     9,    20,    21,    48,    66,    50,    51,
      42,    43,    86,    87,   101,    95,    44,     5,     6,    10,
       7,    23,    77,    99,   223,   305,   396,   224,   303,   304,
     329,   330,   385,   386,   387,   388,    67,   107,   127,   140,
     141,   142,   143,   128,   129,   146,   147,   169,   220,   297,
     148,   203,   204,   170,   213,   214,   221,   370,   371,   372,
     373,   374,   298,   379,   381,   299,   300,   173,   230,   541,
     509,   530,   476,   174,   413,   175,   542,   150,   171,   225,
     226,   227,   402,   474,   403,   307,   228,   309,   310,   404,
     405,   470,   503,   406,   468,   501,   536,   407,   469,   502,
     408,   471,   504,   409,   410,   475,   539,   553,   529,   411,
     215,   216,   291,   498,   366,   515,   491,   322,   270,   271,
     447,    98,   106,   116,   117,   134,   135,   229,   138,   136,
     152,   414,   415,   314,   232,   159,   160,   177,   316,   233,
     178,   153,   119,   120,   131,   121,   122,   123,   162,   179,
     124,   154,   244,   105,   245,   246,   424,   331,   247,   426,
     332,   248,   249,   341,   342,   250,   251,   437,   443,   488,
     438,   343,   252,   344,   253,   254,   255,   256,   267,   208,
     522,   209,   210,   257,   512,   480,   549,   550,   258,   346,
     259,    81,    82,    83,   260,    71,    72,    73,   261,    32,
     262,    40,    76
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int MapSetParser::yytable_ninf_ = -238;
  const short int
  MapSetParser::yytable_[] =
  {
        26,   375,   103,    31,    33,    34,    35,   275,   276,   161,
     412,    69,   217,   139,   265,   205,   311,    78,   392,   100,
     268,   441,    79,    68,   289,   161,   125,   435,   436,   118,
     207,   218,    84,   163,   161,     3,   523,   513,     4,   535,
      69,     8,   126,   164,   514,   151,   514,    24,    25,    39,
     531,   205,    68,    75,    22,    80,   118,   217,   181,   164,
      45,    70,    46,    47,   442,   507,   207,   508,   164,    92,
      57,    58,    59,    60,    61,    62,   218,   375,    36,    37,
      38,    41,    75,    24,    25,   104,   102,    69,    49,    74,
      70,    27,    28,    29,    30,   104,   266,    69,    24,    25,
     130,   392,   269,    36,    37,    38,   290,    90,   472,    36,
      37,    38,    93,    85,    24,    25,    94,   158,    74,   165,
     155,    91,   104,    96,    69,   155,   104,   155,    69,    75,
     333,   334,   335,   336,   337,   338,    97,    70,   217,    75,
     339,   340,   104,   108,    69,   295,   296,    70,   418,   419,
     109,   104,   389,    69,   420,   132,   206,   218,   144,   137,
     104,   231,    69,   133,   156,    74,    75,   391,   145,   156,
      75,   156,   144,   149,    70,    74,   505,   167,    70,   427,
     428,   429,   430,   431,   432,   168,    75,   161,   172,   323,
     324,   325,   206,   327,    70,    75,   176,   397,   398,   219,
     211,   211,    74,    70,    75,   263,    74,    27,    28,    29,
      30,   264,    70,   272,   217,   273,   464,   301,   302,   312,
    -173,   164,    74,    36,    37,    38,   274,   399,   400,   294,
     401,    74,   277,   218,   278,   389,   211,   514,   548,   306,
      74,   317,   318,   319,   279,   217,   211,   433,   434,   280,
     391,    11,    12,    13,    14,    15,    16,    17,    18,   281,
      19,   525,   526,   282,   218,   485,   486,   489,   490,   283,
     358,   284,   285,   286,   287,   313,   315,   320,   308,   321,
     326,   365,   328,   376,   367,   377,   378,   296,   161,   295,
     425,   422,   506,   390,   423,   393,   444,   104,   212,    69,
     445,   448,   155,   446,   104,   499,    69,   451,   452,   449,
     454,   455,   450,   453,   457,   458,   456,   421,   459,   460,
     527,   528,   164,   461,   126,   473,   538,   211,   510,   511,
     517,   516,   518,   519,   520,   524,   534,   211,   514,   551,
     557,    75,   466,   537,   166,   394,   156,   556,    75,    70,
      88,   559,   467,   552,    89,   500,    70,   288,   293,   376,
     463,   382,   555,   380,   345,   521,   417,   477,   416,   483,
     558,   487,   484,   395,   157,   439,   390,    74,   393,   560,
     440,     0,     0,     0,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   211,     0,   104,     0,    69,   292,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     211,     0,     0,     0,     0,     0,     0,     0,   394,     0,
       0,     0,     0,     0,   211,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
       0,     0,     0,     0,     0,     0,   395,    70,     0,   347,
     348,   349,     0,   104,   350,    69,     0,     0,   351,   352,
     353,     0,     0,   354,   355,   356,   357,     0,   359,   360,
     361,   362,   363,   364,     0,    74,   554,   540,     0,     0,
     155,   155,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    75,     0,     0,
       0,     0,     0,     0,     0,    70,     0,     0,     0,   543,
       0,   544,     0,     0,     0,     0,     0,     0,     0,     0,
     543,     0,   544,     0,   156,   156,     0,     0,     0,   -20,
       0,     0,     0,    74,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    27,    28,    29,    30,    36,
      37,    38,   462,   547,    24,    25,     0,     0,     0,     0,
       0,   545,     0,     0,   547,     0,     0,     0,     0,     0,
     465,     0,   545,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   546,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     546,     0,     0,     0,   479,   481,   482,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    27,    28,
      29,    30,    36,    37,    38,    63,    64,     0,     0,     0,
      65,   478,     0,     0,   492,   493,   494,     0,     0,   495,
       0,     0,   496,     0,     0,     0,     0,   497,     0,     0,
       0,   212,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   234,   235,     0,   236,     0,     0,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,     0,
     532,     0,   533,   237,   238,   239,   240,   241,   242,   243,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    27,    28,    29,    30,    36,    37,    38,   383,     0,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   384,     0,
       0,     0,     0,     0,     0,   222,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,   111,   112,   113,   114,
       0,     0,     0,  -237,     0,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   115,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,     0,     0,     0,     0,
     237,   238,   239,   240,   241,   242,   243,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    27,    28,
      29,    30,    36,    37,    38,     0,     0,    24,    25,     0,
       0,     0,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    27,    28,    29,    30,    36,    37,    38,
      63,    64,    24,    25,     0,    65,   368,   369,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   212,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,   111,   112,   113,
     114,     0,     0,     0,  -237,     0,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   115,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   110,   111,   112,
     113,   114,     0,     0,     0,     0,   180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   115,     0,     0,     0,
       0,     0,     0,    36,    37,    38,     0,     0,    24,    25,
       0,     0,     0,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    27,    28,    29,    30,    36,    37,
      38,    63,    64,    24,    25,     0,    65,     0,     0,     0,
       0,     0,     0,     0,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    27,    28,    29,    30,    36,
      37,    38,    63,    64,    24,    25,     0,    65,   110,   111,
     112,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   182,     0,   115,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    27,
      28,    29,    30,    36,    37,    38,    63,    64,    24,    25,
       0,    65,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,     0,     0,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    27,    28,    29,    30,
      36,    37,    38,    63,    64,    24,    25,   212,    65,    36,
      37,    38,     0,     0,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   234,   235,
       0,   236,   540,     0,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,     0,     0,     0,     0,   237,
     238,   239,   240,   241,   242,   243,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    27,    28,    29,
      30,    36,    37,    38,   212,     0,    24,    25,     0,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      27,    28,    29,    30,    36,    37,    38,     0,     0,    24,
      25,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,     0,     0,     0,     0,   237,   238,   239,   240,
     241,   242,   243,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    27,    28,    29,    30,    36,    37,
      38,   384,     0,    24,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,     0,
       0,     0,     0,   237,   238,   239,   240,   241,   242,   243,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    27,    28,    29,    30,    36,    37,    38,   212,     0,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    27,    28,    29,
      30,    36,    37,    38,    63,    64,     0,     0,     0,    65,
       0,     0,    36,    37,    38
  };

  /* YYCHECK.  */
  const short int
  MapSetParser::yycheck_[] =
  {
        11,   294,    96,    12,    13,    14,    15,   190,   191,   137,
     308,    20,   168,    25,    41,   167,    38,    26,   304,    39,
      41,    21,    89,    20,    41,   153,    24,    62,    63,   106,
     167,   168,    41,   137,   162,     0,   498,    42,    17,    42,
      49,   115,    40,   137,    49,    51,    49,   120,   121,    16,
     512,   203,    49,    20,    18,   122,   133,   213,   162,   153,
      11,    20,    13,    14,    64,    39,   203,    41,   162,    78,
     105,   106,   107,   108,   109,   110,   213,   370,   115,   116,
     117,    52,    49,   120,   121,    96,    95,    96,    38,    20,
      49,   111,   112,   113,   114,   106,   123,   106,   120,   121,
     109,   387,   123,   115,   116,   117,   123,    22,   401,   115,
     116,   117,    79,    38,   120,   121,    53,   136,    49,   138,
     131,   116,   133,    39,   133,   136,   137,   138,   137,    96,
      56,    57,    58,    59,    60,    61,    38,    96,   294,   106,
      66,    67,   153,   115,   153,    30,    31,   106,   320,   321,
      44,   162,   304,   162,   326,    39,   167,   294,   125,    41,
     171,   172,   171,    44,   131,    96,   133,   304,    91,   136,
     137,   138,   139,    38,   133,   106,   474,    27,   137,   333,
     334,   335,   336,   337,   338,    92,   153,   315,    32,   239,
     240,   241,   203,   243,   153,   162,    53,    15,    16,    26,
     167,   168,   133,   162,   171,    41,   137,   111,   112,   113,
     114,    41,   171,    41,   370,    41,   372,    19,    20,   230,
      38,   315,   153,   115,   116,   117,    41,    45,    46,    27,
      48,   162,    41,   370,    41,   387,   203,    49,    50,    39,
     171,   234,   235,   236,    41,   401,   213,   339,   340,    41,
     387,     3,     4,     5,     6,     7,     8,     9,    10,    41,
      12,   501,   502,    41,   401,   435,   436,   441,   442,    41,
     281,    41,    41,    41,    41,    50,    49,    41,    44,    41,
      41,    19,    90,   294,    42,   102,   102,    31,   416,    30,
      55,    42,   475,   304,    54,   304,    42,   308,    41,   308,
      42,    49,   313,    42,   315,   465,   315,    42,    42,    49,
      42,    42,    49,    49,    42,    42,    49,   328,    42,    42,
     503,   504,   416,    49,    40,    44,    47,   294,    42,    42,
      42,    49,    42,    42,    42,    42,    42,   304,    49,    42,
      42,   308,   387,   526,   139,   304,   313,    77,   315,   308,
      49,    56,   396,   536,    51,   467,   315,   203,   213,   370,
     370,   300,   541,   299,   262,   497,   315,   416,   313,   423,
     553,   437,   425,   304,   133,   343,   387,   308,   387,   559,
     343,    -1,    -1,    -1,   315,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   370,    -1,   416,    -1,   416,   212,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     387,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   387,    -1,
      -1,    -1,    -1,    -1,   401,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   416,
      -1,    -1,    -1,    -1,    -1,    -1,   387,   416,    -1,   263,
     264,   265,    -1,   474,   268,   474,    -1,    -1,   272,   273,
     274,    -1,    -1,   277,   278,   279,   280,    -1,   282,   283,
     284,   285,   286,   287,    -1,   416,    42,    43,    -1,    -1,
     501,   502,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,   530,
      -1,   530,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     541,    -1,   541,    -1,   501,   502,    -1,    -1,    -1,    22,
      -1,    -1,    -1,   474,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   366,   530,   120,   121,    -1,    -1,    -1,    -1,
      -1,   530,    -1,    -1,   541,    -1,    -1,    -1,    -1,    -1,
     384,    -1,   541,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   530,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     541,    -1,    -1,    -1,   418,   419,   420,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,    -1,    -1,    -1,
     123,    21,    -1,    -1,   448,   449,   450,    -1,    -1,   453,
      -1,    -1,   456,    -1,    -1,    -1,    -1,   461,    -1,    -1,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    -1,    65,    -1,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
     514,    -1,   516,    93,    94,    95,    96,    97,    98,    99,
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
      -1,    65,    43,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    41,    -1,   120,   121,    -1,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,   120,
     121,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    -1,    -1,    -1,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    41,    -1,   120,   121,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
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
         0,   125,   126,     0,    17,   141,   142,   144,   115,   127,
     143,     3,     4,     5,     6,     7,     8,     9,    10,    12,
     128,   129,    18,   145,   120,   121,   276,   111,   112,   113,
     114,   314,   323,   314,   314,   314,   115,   116,   117,   324,
     325,    52,   134,   135,   140,    11,    13,    14,   130,    38,
     132,   133,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   118,   119,   123,   131,   160,   277,   314,
     318,   319,   320,   321,   322,   324,   326,   146,   314,    89,
     122,   315,   316,   317,   314,    38,   136,   137,   131,   132,
      22,   116,   314,   324,    53,   139,    39,    38,   245,   147,
      39,   138,   314,   274,   276,   277,   246,   161,   115,    44,
      33,    34,    35,    36,    37,    52,   247,   248,   251,   266,
     267,   269,   270,   271,   274,    24,    40,   162,   167,   168,
     314,   268,    39,    44,   249,   250,   253,    41,   252,    25,
     163,   164,   165,   166,   324,    91,   169,   170,   174,    38,
     201,    51,   254,   265,   275,   276,   324,   247,   254,   259,
     260,   266,   272,   273,   274,   254,   166,    27,    92,   171,
     177,   202,    32,   191,   197,   199,    53,   261,   264,   273,
      42,   273,    41,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,   175,   176,   235,   276,   301,   303,   305,
     306,   324,    41,   178,   179,   234,   235,   300,   301,    26,
     172,   180,    23,   148,   151,   203,   204,   205,   210,   251,
     192,   276,   258,   263,    62,    63,    65,    93,    94,    95,
      96,    97,    98,    99,   276,   278,   279,   282,   285,   286,
     289,   290,   296,   298,   299,   300,   301,   307,   312,   314,
     318,   322,   324,    41,    41,    41,   123,   302,    41,   123,
     242,   243,    41,    41,    41,   201,   201,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,   176,    41,
     123,   236,   278,   179,    27,    30,    31,   173,   186,   189,
     190,    19,    20,   152,   153,   149,    39,   209,    44,   211,
     212,    38,   276,    50,   257,    49,   262,   299,   299,   299,
      41,    41,   241,   241,   241,   241,    41,   241,    90,   154,
     155,   281,   284,    56,    57,    58,    59,    60,    61,    66,
      67,   287,   288,   295,   297,   236,   313,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   276,   278,
     278,   278,   278,   278,   278,    19,   238,    42,    28,    29,
     181,   182,   183,   184,   185,   234,   276,   102,   102,   187,
     190,   188,   189,    21,    41,   156,   157,   158,   159,   235,
     276,   301,   307,   314,   318,   322,   150,    15,    16,    45,
      46,    48,   206,   208,   213,   214,   217,   221,   224,   227,
     228,   233,   205,   198,   255,   256,   265,   264,   238,   238,
     238,   276,    42,    54,   280,    55,   283,   289,   289,   289,
     289,   289,   289,   242,   242,    62,    63,   291,   294,   320,
     321,    21,    64,   292,    42,    42,    42,   244,    49,    49,
      49,    42,    42,    49,    42,    42,    49,    42,    42,    42,
      42,    49,   278,   182,   300,   278,   157,   167,   218,   222,
     215,   225,   234,    44,   207,   229,   196,   261,    21,   278,
     309,   278,   278,   282,   285,   296,   296,   292,   293,   298,
     298,   240,   278,   278,   278,   278,   278,   278,   237,   155,
     169,   219,   223,   216,   226,   205,   201,    39,    41,   194,
      42,    42,   308,    42,    49,   239,    49,    42,    42,    42,
      42,   239,   304,   240,    42,   275,   275,   201,   201,   232,
     195,   240,   278,   278,    42,    42,   220,   201,    47,   230,
      43,   193,   200,   276,   314,   318,   322,   324,    50,   310,
     311,    42,   201,   231,    42,   200,    77,    42,   201,    56,
     323
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
     137,   138,   139,   139,   140,   141,   142,   142,   143,   143,
     144,   146,   147,   145,   149,   150,   148,   151,   152,   152,
     153,   153,   154,   155,   155,   156,   157,   157,   157,   157,
     157,   157,   157,   157,   158,   158,   159,   159,   160,   161,
     161,   162,   163,   163,   164,   165,   166,   167,   168,   168,
     169,   170,   170,   171,   171,   172,   172,   173,   173,   174,
     175,   175,   176,   176,   176,   176,   177,   178,   178,   179,
     180,   181,   181,   182,   182,   183,   183,   184,   185,   185,
     186,   186,   187,   187,   188,   188,   189,   190,   191,   192,
     192,   193,   193,   195,   194,   196,   196,   198,   197,   199,
     199,   200,   200,   200,   200,   200,   200,   202,   201,   203,
     203,   204,   205,   205,   206,   206,   207,   207,   208,   209,
     209,   210,   211,   212,   212,   213,   213,   213,   213,   213,
     215,   216,   214,   218,   219,   220,   217,   222,   223,   221,
     225,   226,   224,   228,   229,   227,   231,   230,   232,   232,
     233,   234,   234,   234,   235,   236,   237,   236,   238,   238,
     239,   240,   240,   241,   242,   243,   244,   243,   246,   245,
     247,   247,   248,   249,   250,   250,   252,   251,   253,   251,
     254,   255,   256,   256,   257,   258,   258,   259,   260,   260,
     261,   262,   263,   263,   264,   265,   265,   266,   266,   268,
     267,   269,   270,   270,   270,   270,   270,   271,   271,   272,
     272,   273,   273,   274,   274,   275,   275,   276,   276,   277,
     277,   277,   277,   277,   277,   278,   279,   280,   281,   281,
     282,   283,   284,   284,   285,   286,   287,   287,   287,   287,
     287,   287,   287,   287,   288,   288,   289,   290,   291,   291,
     292,   292,   293,   293,   294,   294,   294,   295,   295,   296,
     297,   297,   298,   298,   298,   298,   299,   299,   299,   299,
     299,   299,   299,   299,   300,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   302,   302,   303,   304,   304,
     305,   306,   307,   307,   307,   307,   307,   307,   308,   307,
     309,   309,   310,   311,   311,   312,   313,   313,   314,   315,
     316,   316,   317,   317,   318,   318,   318,   319,   319,   319,
     320,   320,   320,   321,   321,   321,   322,   322,   323,   323,
     323,   323,   324,   324,   325,   325,   326,   326
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  MapSetParser::yyr2_[] =
  {
         0,     2,     0,     4,     0,     2,     0,     2,     4,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       0,     1,     4,     1,     2,     2,     0,     1,     0,     1,
       3,     3,     0,     2,     3,     2,     0,     1,     0,     2,
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
  "PrimaryKeySpec", "_QDefaultPrimaryKey_E_Opt", "_QPrimaryKeySet_E_Opt",
  "PrimaryKeySet", "_O_QRDFLiteral_E_S_QGT_DOT_E_S_QRDFLiteral_E_C",
  "_Q_O_QRDFLiteral_E_S_QGT_DOT_E_S_QRDFLiteral_E_C_E_Star",
  "DefaultPrimaryKey", "Prologue", "_QBaseDecl_E_Opt",
  "_QPrefixDecl_E_Star", "BaseDecl", "PrefixDecl", "$@2", "$@3",
  "SubSelect", "@4", "@5", "SelectClause",
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
       125,     0,    -1,    -1,   126,   141,   127,   128,    -1,    -1,
     127,   129,    -1,    -1,   128,   160,    -1,     3,   276,   314,
     314,    -1,     4,   314,    -1,     5,   314,    -1,     6,   314,
      -1,     7,   314,    -1,     8,   324,    -1,     9,   134,    -1,
      10,   130,    -1,    12,   133,    -1,    11,    -1,    14,    -1,
      13,    -1,    -1,   277,    -1,    38,   131,    39,   274,    -1,
     132,    -1,   133,   132,    -1,   135,   136,    -1,    -1,   140,
      -1,    -1,   137,    -1,    38,   139,    39,    -1,   314,    44,
     314,    -1,    -1,   139,   138,    -1,    52,   314,    53,    -1,
     142,   143,    -1,    -1,   144,    -1,    -1,   143,   145,    -1,
      17,   115,    -1,    -1,    -1,    18,   146,   116,   147,   115,
      -1,    -1,    -1,   151,   149,   150,   167,   169,    -1,    23,
     153,   159,    -1,    19,    -1,    20,    -1,    -1,   152,    -1,
      90,   276,    -1,    -1,   154,    -1,    41,   278,   155,    42,
      -1,   276,    -1,   307,    -1,   301,    -1,   235,    -1,   314,
      -1,   318,    -1,   322,    -1,   156,    -1,   157,    -1,   158,
     157,    -1,   158,    -1,    21,    -1,   131,    22,   245,   161,
     167,   169,    -1,    -1,   161,   162,    -1,    24,   163,    -1,
     164,    -1,   165,    -1,   166,    -1,    25,   166,    -1,   324,
      -1,   168,   201,   191,    -1,    -1,    40,    -1,   170,   171,
     172,   173,    -1,    -1,   174,    -1,    -1,   177,    -1,    -1,
     180,    -1,    -1,   186,    -1,    91,    27,   175,    -1,   176,
      -1,   175,   176,    -1,   301,    -1,   235,    -1,    41,   278,
     155,    42,    -1,   276,    -1,    92,   178,    -1,   179,    -1,
     178,   179,    -1,   234,    -1,    26,    27,   181,    -1,   182,
      -1,   181,   182,    -1,   184,    -1,   185,    -1,    28,    -1,
      29,    -1,   183,   300,    -1,   234,    -1,   276,    -1,   189,
     187,    -1,   190,   188,    -1,    -1,   190,    -1,    -1,   189,
      -1,    30,   102,    -1,    31,   102,    -1,   199,    -1,   276,
      -1,   192,   276,    -1,   200,    -1,   193,   200,    -1,    -1,
      41,   195,   193,    42,    -1,    -1,   196,   194,    -1,    -1,
      32,   192,    38,   198,   196,    39,    -1,    -1,   197,    -1,
     324,    -1,   314,    -1,   318,    -1,   322,    -1,    43,    -1,
     276,    -1,    -1,    38,   202,   203,    39,    -1,   148,    -1,
     204,    -1,   205,   209,    -1,    -1,   210,    -1,   213,    -1,
     233,    -1,    -1,    44,    -1,   206,   207,   205,    -1,    -1,
     209,   208,    -1,   251,   212,    -1,    44,   205,    -1,    -1,
     211,    -1,   214,    -1,   224,    -1,   227,    -1,   217,    -1,
     221,    -1,    -1,    -1,    45,   215,   216,   201,    -1,    -1,
      -1,    -1,    15,   218,   219,   275,   220,   201,    -1,    -1,
      -1,    16,   222,   223,   275,   201,    -1,    -1,    -1,    46,
     225,   226,   201,    -1,    -1,    -1,   228,   229,   201,   232,
      -1,    -1,    47,   231,   201,    -1,    -1,   232,   230,    -1,
      48,   234,    -1,   300,    -1,   301,    -1,   235,    -1,   324,
     236,    -1,   123,    -1,    -1,    41,   238,   278,   237,   240,
      42,    -1,    -1,    19,    -1,    49,   278,    -1,    -1,   240,
     239,    -1,    41,   238,   278,    42,    -1,   243,    -1,   123,
      -1,    -1,    41,   278,   244,   240,    42,    -1,    -1,    38,
     246,   247,    39,    -1,    -1,   248,    -1,   251,   250,    -1,
      44,   247,    -1,    -1,   249,    -1,    -1,   274,   252,   254,
      -1,    -1,   266,   253,   259,    -1,   265,   261,   258,    -1,
     265,   261,    -1,    -1,   255,    -1,    50,   256,    -1,    -1,
     258,   257,    -1,   260,    -1,    -1,   254,    -1,   264,   263,
      -1,    49,   264,    -1,    -1,   263,   262,    -1,   273,    -1,
     275,    -1,    51,    -1,   269,    -1,   267,    -1,    -1,    52,
     268,   254,    53,    -1,   271,    41,   272,    42,    -1,    33,
      -1,    34,    -1,    35,    -1,    36,    -1,    37,    -1,    -1,
     270,    -1,   273,    -1,   272,   273,    -1,   274,    -1,   266,
      -1,   276,    -1,   277,    -1,   276,    -1,   324,    -1,   120,
      -1,   121,    -1,   324,    -1,   314,    -1,   318,    -1,   322,
      -1,   326,    -1,   123,    -1,   279,    -1,   282,   281,    -1,
      54,   282,    -1,    -1,   281,   280,    -1,   285,   284,    -1,
      55,   285,    -1,    -1,   284,   283,    -1,   286,    -1,   289,
     288,    -1,    56,   289,    -1,    57,   289,    -1,    58,   289,
      -1,    59,   289,    -1,    60,   289,    -1,    61,   289,    -1,
      66,   242,    -1,    67,   242,    -1,    -1,   287,    -1,   290,
      -1,   296,   295,    -1,   320,    -1,   321,    -1,    21,   298,
      -1,    64,   298,    -1,    -1,   292,    -1,    62,   296,    -1,
      63,   296,    -1,   291,   293,    -1,    -1,   295,   294,    -1,
     298,   297,    -1,    -1,   297,   292,    -1,    65,   299,    -1,
      62,   299,    -1,    63,   299,    -1,   299,    -1,   300,    -1,
     301,    -1,   312,    -1,   314,    -1,   318,    -1,   322,    -1,
     276,    -1,   307,    -1,    41,   278,    42,    -1,    78,    41,
     278,    42,    -1,    79,    41,   278,    42,    -1,    80,    41,
     278,    49,   278,    42,    -1,    81,    41,   278,    42,    -1,
      82,    41,   276,    42,    -1,    68,    41,   278,    42,    -1,
      69,    41,   278,    42,    -1,    70,   302,    -1,    71,   242,
      -1,    72,    41,   278,    49,   278,    49,   278,    42,    -1,
      73,    41,   278,    49,   278,    42,    -1,    74,    41,   278,
      49,   278,    42,    -1,    83,    41,   278,    49,   278,    42,
      -1,    84,    41,   278,    42,    -1,    85,    41,   278,    42,
      -1,    86,    41,   278,    42,    -1,    87,    41,   278,    42,
      -1,   303,    -1,   305,    -1,   306,    -1,    41,   278,    42,
      -1,   123,    -1,    88,    41,   278,    49,   278,   304,    42,
      -1,    -1,   239,    -1,    75,   201,    -1,    76,   201,    -1,
      93,    41,   238,   309,    42,    -1,    94,   241,    -1,    95,
     241,    -1,    96,   241,    -1,    97,   241,    -1,    99,   241,
      -1,    -1,    98,    41,   238,   278,   308,   240,   311,    42,
      -1,    21,    -1,   278,    -1,    50,    77,    56,   323,    -1,
      -1,   310,    -1,   324,   313,    -1,    -1,   236,    -1,   323,
     317,    -1,    89,   324,    -1,   122,    -1,   315,    -1,    -1,
     316,    -1,   319,    -1,   320,    -1,   321,    -1,   102,    -1,
     103,    -1,   104,    -1,   105,    -1,   106,    -1,   107,    -1,
     108,    -1,   109,    -1,   110,    -1,   100,    -1,   101,    -1,
     111,    -1,   113,    -1,   112,    -1,   114,    -1,   115,    -1,
     325,    -1,   117,    -1,   116,    -1,   118,    -1,   119,    -1
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
     100,   103,   104,   105,   111,   112,   113,   119,   123,   125,
     127,   128,   130,   133,   134,   136,   141,   143,   145,   147,
     149,   151,   153,   155,   157,   159,   162,   164,   166,   173,
     174,   177,   180,   182,   184,   186,   189,   191,   195,   196,
     198,   203,   204,   206,   207,   209,   210,   212,   213,   215,
     219,   221,   224,   226,   228,   233,   235,   238,   240,   243,
     245,   249,   251,   254,   256,   258,   260,   262,   265,   267,
     269,   272,   275,   276,   278,   279,   281,   284,   287,   289,
     291,   294,   296,   299,   300,   305,   306,   309,   310,   317,
     318,   320,   322,   324,   326,   328,   330,   332,   333,   338,
     340,   342,   345,   346,   348,   350,   352,   353,   355,   359,
     360,   363,   366,   369,   370,   372,   374,   376,   378,   380,
     382,   383,   384,   389,   390,   391,   392,   399,   400,   401,
     407,   408,   409,   414,   415,   416,   421,   422,   426,   427,
     430,   433,   435,   437,   439,   442,   444,   445,   452,   453,
     455,   458,   459,   462,   467,   469,   471,   472,   478,   479,
     484,   485,   487,   490,   493,   494,   496,   497,   501,   502,
     506,   510,   513,   514,   516,   519,   520,   523,   525,   526,
     528,   531,   534,   535,   538,   540,   542,   544,   546,   548,
     549,   554,   559,   561,   563,   565,   567,   569,   570,   572,
     574,   577,   579,   581,   583,   585,   587,   589,   591,   593,
     595,   597,   599,   601,   603,   605,   607,   610,   613,   614,
     617,   620,   623,   624,   627,   629,   632,   635,   638,   641,
     644,   647,   650,   653,   656,   657,   659,   661,   664,   666,
     668,   671,   674,   675,   677,   680,   683,   686,   687,   690,
     693,   694,   697,   700,   703,   706,   708,   710,   712,   714,
     716,   718,   720,   722,   724,   728,   733,   738,   745,   750,
     755,   760,   765,   768,   771,   780,   787,   794,   801,   806,
     811,   816,   821,   823,   825,   827,   831,   833,   841,   842,
     844,   847,   850,   856,   859,   862,   865,   868,   871,   872,
     881,   883,   885,   890,   891,   893,   896,   897,   899,   902,
     905,   907,   909,   910,   912,   914,   916,   918,   920,   922,
     924,   926,   928,   930,   932,   934,   936,   938,   940,   942,
     944,   946,   948,   950,   952,   954,   956,   958
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  MapSetParser::yyrline_[] =
  {
         0,   371,   371,   371,   377,   379,   383,   385,   389,   398,
     401,   404,   407,   410,   413,   414,   417,   423,   426,   429,
     435,   438,   442,   454,   455,   460,   463,   465,   468,   470,
     474,   478,   483,   485,   489,   496,   500,   502,   506,   508,
     512,   518,   520,   518,   530,   532,   530,   542,   550,   553,
     560,   563,   568,   575,   578,   583,   590,   593,   596,   599,
     602,   605,   608,   612,   617,   620,   628,   631,   638,   647,
     650,   658,   665,   666,   670,   676,   682,   689,   696,   698,
     702,   709,   712,   717,   720,   725,   728,   733,   737,   741,
     748,   751,   758,   761,   764,   767,   773,   779,   782,   789,
     794,   801,   805,   813,   815,   823,   826,   834,   842,   843,
     850,   854,   862,   865,   870,   873,   877,   883,   891,   896,
     900,   907,   910,   916,   916,   925,   928,   935,   935,   944,
     947,   951,   954,   957,   960,   963,   966,   973,   973,   985,
     986,   991,   995,   997,  1002,  1003,  1007,  1009,  1014,  1018,
    1021,  1026,  1031,  1035,  1038,  1042,  1043,  1044,  1045,  1046,
    1050,  1052,  1050,  1066,  1068,  1070,  1066,  1081,  1083,  1081,
    1092,  1094,  1092,  1104,  1107,  1104,  1117,  1117,  1131,  1133,
    1137,  1148,  1149,  1150,  1154,  1162,  1166,  1166,  1175,  1178,
    1185,  1191,  1193,  1200,  1207,  1211,  1214,  1214,  1224,  1224,
    1232,  1234,  1239,  1244,  1248,  1250,  1254,  1254,  1257,  1257,
    1264,  1269,  1273,  1275,  1280,  1284,  1286,  1291,  1295,  1297,
    1302,  1307,  1311,  1313,  1317,  1324,  1328,  1335,  1336,  1340,
    1340,  1353,  1378,  1381,  1384,  1387,  1390,  1397,  1400,  1405,
    1409,  1416,  1417,  1421,  1424,  1428,  1431,  1437,  1438,  1442,
    1445,  1448,  1451,  1454,  1455,  1461,  1466,  1475,  1482,  1485,
    1493,  1502,  1509,  1512,  1519,  1524,  1535,  1538,  1541,  1544,
    1547,  1550,  1553,  1556,  1563,  1566,  1570,  1575,  1584,  1587,
    1594,  1597,  1604,  1607,  1612,  1615,  1619,  1633,  1636,  1644,
    1653,  1656,  1663,  1666,  1669,  1672,  1676,  1677,  1678,  1679,
    1682,  1685,  1688,  1691,  1695,  1701,  1704,  1707,  1710,  1713,
    1716,  1719,  1723,  1726,  1730,  1733,  1736,  1739,  1742,  1745,
    1748,  1751,  1754,  1755,  1756,  1762,  1765,  1772,  1779,  1782,
    1786,  1793,  1800,  1803,  1806,  1809,  1812,  1815,  1819,  1819,
    1831,  1834,  1838,  1844,  1847,  1851,  1861,  1864,  1869,  1877,
    1884,  1888,  1896,  1900,  1904,  1905,  1906,  1910,  1911,  1912,
    1916,  1917,  1918,  1922,  1923,  1924,  1928,  1929,  1933,  1934,
    1935,  1936,  1940,  1941,  1945,  1946,  1950,  1951
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
  const int MapSetParser::yylast_ = 1414;
  const int MapSetParser::yynnts_ = 203;
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
#line 3973 "lib/MapSetParser/MapSetParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 1957 "lib/MapSetParser/MapSetParser.ypp"
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
	curBGP(NULL), curFilter(NULL), 
	curBindingsClause(NULL), curBinding(NULL), curExprList(NULL), 
	root(NULL), lastRuleTerm(TTerm::Unbound, TTerm::Unbound),
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


