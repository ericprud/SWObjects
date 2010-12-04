
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
#line 236 "lib/MapSetParser/MapSetParser.ypp"

#include "../MapSetScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 372 "lib/MapSetParser/MapSetParser.ypp"

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
#line 387 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root = new MapSet();
	driver.root->sharedVars = MapSet::e_PROMISCUOUS;
      }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 405 "lib/MapSetParser/MapSetParser.ypp"
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
#line 414 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->server = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 417 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->user = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 420 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->password = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 423 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->database = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 426 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->stemURI = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 431 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.sharedVarsSet = true;
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 435 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.lastRuleTermSet = false;
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 441 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_PROMISCUOUS;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 444 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_VARNAMES;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 447 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_DRACONIAN;
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 453 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = NULL;
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 460 "lib/MapSetParser/MapSetParser.ypp"
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
#line 495 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->keyMap[(yysemantic_stack_[(3) - (1)].p_RDFLiteral)->getLexicalValue()] = (yysemantic_stack_[(3) - (3)].p_RDFLiteral)->getLexicalValue();
    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 506 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->primaryKey = (yysemantic_stack_[(3) - (2)].p_RDFLiteral);
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 529 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 535 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 537 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 539 "lib/MapSetParser/MapSetParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 547 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 550 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 558 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 561 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yysemantic_stack_[(5) - (3)].p_WhereClause)->m_BindingClause = (yysemantic_stack_[(5) - (5)].p_BindingsClause);
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(5) - (1)].p_Project).distinctness, (yysemantic_stack_[(5) - (1)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(5) - (3)].p_WhereClause), (yysemantic_stack_[(5) - (4)].p_SolutionModifier))));
      }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 569 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 577 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 580 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 587 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 595 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 602 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 610 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 617 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 620 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 623 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 626 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 629 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 632 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 635 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 644 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 647 "lib/MapSetParser/MapSetParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 655 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 658 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 665 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(7) - (5)].p_WhereClause)->m_BindingClause = (yysemantic_stack_[(7) - (7)].p_BindingsClause);
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	Construct* constr = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(7) - (3)].p_BasicGraphPattern), (yysemantic_stack_[(7) - (4)].p_DatasetClauses), (yysemantic_stack_[(7) - (5)].p_WhereClause), (yysemantic_stack_[(7) - (6)].p_SolutionModifier));
	driver.root->maps.push_back(LabeledConstruct((yysemantic_stack_[(7) - (1)].p_TTerm), constr));
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 675 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 687 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 693 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 699 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 706 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp ? driver.curOp : new DefaultGraphPattern(), NULL);
	driver.curOp = NULL;
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 720 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 727 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 735 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 743 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 751 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 759 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 766 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 769 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 776 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 779 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 782 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 785 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 791 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 797 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 800 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 812 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 819 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 823 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 833 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 841 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 844 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 852 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 861 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 868 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 872 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 880 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 888 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 895 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 901 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 914 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTermList) = new TTermList;
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 917 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTermList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_TTermList) = (yysemantic_stack_[(2) - (1)].p_TTermList);
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 924 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 927 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 933 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding = new Binding();
      }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 935 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BindingValue) = driver.curBinding;
	  driver.curBinding = NULL;
      }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 939 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding = new Binding();
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 945 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 948 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBindingsClause->push_back((yysemantic_stack_[(2) - (2)].p_BindingValue));
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 955 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBindingsClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_TTermList));
      }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 957 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BindingsClause) = driver.curBindingsClause;
	  driver.curBindingsClause = NULL;
      }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 964 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BindingsClause) = NULL;
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 971 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 974 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 977 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 980 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 983 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 986 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 999 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1002 "lib/MapSetParser/MapSetParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1081 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1084 "lib/MapSetParser/MapSetParser.ypp"
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
#line 1096 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 1099 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 1101 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 1104 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1112 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1115 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1117 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(5) - (4)].p_TTerm), driver.curOp, driver.atomFactory, false));
      }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1124 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1127 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1129 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.curOp));
      }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 1137 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 1140 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 1142 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1150 "lib/MapSetParser/MapSetParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 1155 "lib/MapSetParser/MapSetParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 1170 "lib/MapSetParser/MapSetParser.ypp"
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
#line 1187 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 1195 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 1199 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 1201 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = NULL;
      }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 1208 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 1211 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 1218 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 1226 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 1240 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 1243 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 1245 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 1253 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1255 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 1283 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 1286 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 1346 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 1353 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 1357 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 1365 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 1368 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 1374 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 1385 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 1413 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 1440 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 1447 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 1458 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 1465 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 1501 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 1504 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 1507 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 1510 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 1568 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 1572 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 1581 "lib/MapSetParser/MapSetParser.ypp"
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

  case 292:

/* Line 678 of lalr1.cc  */
#line 1606 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 1609 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 1612 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 1615 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 1618 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 1625 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 1633 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 1637 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 1649 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 1656 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 1659 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 1670 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 1673 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 1676 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 1679 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 1683 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 1694 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 1703 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 1710 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 1713 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 1721 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 1730 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 1737 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 1740 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 1752 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_GeneralComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_GeneralComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_GeneralComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 1763 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 1770 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 1773 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 1776 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 1779 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 1782 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 1785 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 1788 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 1791 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 1802 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 1811 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 1814 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 1821 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 1824 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 1831 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 1839 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 1842 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 1846 "lib/MapSetParser/MapSetParser.ypp"
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

  case 347:

/* Line 678 of lalr1.cc  */
#line 1860 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 1863 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 1871 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 1880 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 1883 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 1890 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 1893 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 1896 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 1906 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 1909 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 1912 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 1915 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 1922 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 1928 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 1931 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 1934 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 1937 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 1940 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 1943 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 1946 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 1950 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_blank, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 1953 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 1957 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 1960 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 1963 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 1966 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 1969 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 1972 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 1975 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 1978 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 1981 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 1992 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 1995 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 2002 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_regex, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 2009 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 2016 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 2023 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 2030 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 2033 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 2037 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 2039 "lib/MapSetParser/MapSetParser.ypp"
    {
	  // x = new ArgList($2, driver.curExprList);
	  delete driver.curExprList;
	  driver.curExprList = NULL;
	  w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // $$ = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group-concat, $3, $4.p_Expression, $4.separator));
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 2049 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
	driver.countStar = true;
    }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 2057 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 2060 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 2063 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 2066 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 2069 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 2075 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 2081 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 2088 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 2098 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 2106 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 2114 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 2121 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 2125 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 2133 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 2807 "lib/MapSetParser/MapSetParser.cpp"
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
  const short int MapSetParser::yypact_ninf_ = -530;
  const short int
  MapSetParser::yypact_[] =
  {
      -530,    46,    31,  -530,   -67,  -530,  -530,  -530,  -530,   361,
      43,   -33,   222,   222,   222,   222,   -44,     7,   246,    33,
     656,  -530,  -530,  -530,  -530,  -530,   222,  -530,  -530,  -530,
    -530,  -530,   -62,  -530,  -530,  -530,  -530,  -530,  -530,  -530,
    -530,   222,  -530,    42,  -530,  -530,  -530,  -530,  -530,  1476,
    -530,    33,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,
    -530,  -530,  -530,  -530,  -530,  -530,    62,  -530,  -530,  -530,
    -530,  -530,  -530,  -530,  -530,  -530,  -530,   -23,   222,   -44,
    -530,  -530,  -530,  -530,    45,  -530,  -530,  -530,    55,  -530,
      66,  -530,  -530,  -530,  -530,    84,  1452,  -530,  -530,    25,
    -530,  -530,   106,  -530,  -530,  -530,   989,    17,  -530,   222,
    -530,  -530,  -530,  -530,  -530,  -530,   119,  -530,   128,  -530,
    -530,  -530,  -530,   137,  -530,    -6,  -530,  -530,    96,   156,
    -530,   123,  -530,   989,  -530,  -530,   123,  1114,   123,   -44,
    -530,  -530,  -530,  -530,  -530,   168,   174,   116,  -530,  -530,
    -530,  -530,   157,  1114,  -530,  -530,  -530,  -530,  -530,  -530,
    -530,  -530,  1020,  -530,  -530,  -530,  -530,  1375,  -530,  -530,
    -530,  -530,  1434,   189,  -530,   866,  -530,  -530,  -530,  -530,
    -530,  -530,  1198,   154,   177,   190,   -25,   -19,   192,   194,
     195,   156,   196,   204,   208,   213,   221,   223,   224,   232,
     239,   245,   248,   250,  1375,  -530,  -530,  -530,  -530,  -530,
    -530,  -530,   -10,   -14,  1198,  1434,  -530,  -530,  -530,  -530,
    -530,   260,   124,  -530,   143,  -530,  -530,   253,  -530,  -530,
    -530,   252,  -530,  -530,   247,   254,  1257,  1257,  1257,   258,
    -530,  -530,  -530,  -530,   267,  -530,  -530,   226,  -530,  -530,
    -530,  -530,   218,  -530,  -530,  -530,  -530,  -530,  -530,  -530,
     269,  -530,  -530,  -530,  -530,   -10,   156,  1198,  1198,  1198,
    -530,  -530,  1198,  -530,  -530,  1198,  1198,  1198,  -530,  1198,
    1198,  1198,  1198,   -33,  1198,  1198,  1198,  1198,  1198,  1198,
    1198,  -530,   293,  -530,  -530,  -530,  -530,   271,  -530,   965,
     212,   215,  -530,  -530,   287,   291,  -530,  -530,  -530,   842,
     285,  -530,   307,   989,  -530,  -530,   123,   132,   123,  -530,
    1114,  -530,  -530,  -530,  -530,   293,   293,   -33,  -530,   284,
     273,   286,  1198,  1198,  1198,  1198,  1198,  1198,   275,   -19,
    -530,  -530,   158,     9,   293,  -530,  -530,  -530,   298,   302,
     304,  -530,   299,   300,   301,   309,   314,   308,   316,   317,
     311,   319,   321,   332,   333,   327,   335,  -530,  1198,  -530,
    -530,  -530,  -530,   965,  -530,   337,  -530,  -530,  -530,  -530,
    -530,  -530,  -530,  -530,  -530,  -530,  -530,  1198,  -530,  -530,
    1316,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,    96,
    -530,  -530,  -530,  -530,  1434,  -530,   336,  -530,  -530,  -530,
    -530,  -530,  -530,  -530,  -530,  -530,  -530,   163,  -530,    41,
     175,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,
       4,  -530,  -530,  -530,  -530,  -530,  1114,  -530,   762,  1198,
    -530,  -530,  1198,  -530,  1198,  -530,  -530,  -530,  -530,  -530,
    -530,  -530,   -19,  -530,  1198,  1198,     9,  -530,  -530,  -530,
    1198,  1198,  -530,  1198,  -530,  -530,  -530,  -530,  1198,  1198,
    1198,  -530,  -530,  1198,  -530,  -530,  1198,  -530,  -530,  -530,
    -530,  1198,  -530,  -530,   -18,  -530,  -530,   226,  -530,   174,
    -530,  -530,   156,  -530,  -530,  -530,   989,   156,   340,    -1,
    -530,    27,  -530,  -530,  -530,  -530,  -530,  -530,  1114,   281,
     320,  -530,    28,  -530,  -530,  -530,  -530,  -530,  -530,  -530,
    -530,   344,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,
    -530,  -530,   345,    11,   339,   347,   348,   350,   351,   349,
    -530,  -530,  -530,  -530,  -530,   352,  -530,    61,    61,  -530,
     156,  -530,  -530,  -530,  -530,   354,  -530,  -530,  -530,  -530,
    -530,   163,  -530,   163,  -530,   292,  -530,  -530,     0,  -530,
     357,  -530,  -530,  1198,  -530,  1198,  -530,  -530,  -530,  -530,
    -530,   358,    16,  1071,  -530,  -530,   156,  -530,   362,  -530,
     310,   363,  -530,  -530,   372,  -530,   -12,  -530,   325,  -530,
     373,  -530,   374,  -530,  -530,  -530,   681,  -530,  -530,  -530,
    -530,  -530,  -530,   156,  -530,  -530,  -530,    -1,  -530,   132,
    -530,  -530,  -530,  -530,   375,   364,  -530,  -530,  -530,  -530,
    -530,   156,  -530,  -530,  -530,  -530,  -530,   222,  -530,  1114,
    -530,  -530
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  MapSetParser::yydefact_[] =
  {
         2,     0,    36,     1,     0,     4,    38,    37,    40,     6,
      35,     0,     0,     0,     0,     0,     0,    26,     0,     0,
       3,     5,    41,    39,   307,   308,     0,   430,   432,   431,
     433,     9,   414,    10,    11,    12,   434,   437,   436,    13,
     435,     0,    14,    28,    27,    17,    19,    18,    15,    20,
      23,    16,   428,   429,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   438,   439,   314,     0,     7,    21,   310,
     311,   416,   417,   418,   312,   309,   313,     0,     0,     0,
     412,   413,   415,   410,     0,    32,    25,    29,     0,    24,
       0,    42,     8,   411,    34,     0,     0,   194,    44,     0,
      30,    33,     0,    22,   303,   304,   196,    77,    43,     0,
     292,   293,   294,   295,   296,   289,     0,   197,   200,   204,
     288,   287,   298,     0,   202,     0,    78,    45,    80,     0,
      31,     0,   195,   196,   201,   198,   214,   297,     0,     0,
      70,    71,    72,    73,    75,     0,   129,    82,    81,   139,
      76,   222,     0,   297,   221,   305,   306,   199,   215,   205,
     213,   302,   297,   299,   301,   203,    74,     0,   118,    69,
     130,   117,     0,    84,    83,   144,   290,   211,   218,   220,
     291,   300,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    92,    94,    91,   383,
     384,   385,     0,     0,     0,    95,    96,    98,   181,   179,
     180,     0,    86,    85,    51,   141,    46,     0,   142,   147,
     145,   151,   225,   223,   206,   216,     0,     0,     0,     0,
     399,   400,   401,   402,     0,   403,   362,    54,   315,   318,
     322,   324,   326,   336,   347,   350,   355,   356,   357,   363,
       0,   358,   359,   360,   361,   408,     0,     0,     0,     0,
     387,   372,     0,   191,   373,     0,     0,     0,   391,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,   186,   183,   182,   127,   119,     0,    97,     0,
       0,     0,    79,    87,   111,   113,    49,    50,    52,     0,
      77,   140,   143,   144,   152,   149,   214,     0,   208,   212,
     297,   219,   353,   354,   352,   186,   186,     0,    55,     0,
     316,   320,     0,     0,     0,     0,     0,     0,     0,     0,
     325,   327,   337,   349,   186,   409,   407,   392,     0,     0,
       0,   192,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   187,     0,   125,
     364,   104,   105,    99,   100,     0,   102,   103,   107,   108,
     115,   116,   109,   112,   110,   114,    68,     0,    64,    65,
      67,    48,    60,    57,    59,    58,    61,    62,    63,    80,
     161,   165,   159,   168,     0,   148,   137,   154,   156,   157,
     155,   153,   172,   158,   150,   238,   226,     0,   268,     0,
       0,   224,   227,   229,   230,   239,   241,   244,   253,   248,
     251,   266,   240,   267,   209,   210,   297,   217,     0,     0,
      53,    93,     0,   319,     0,   323,   328,   329,   330,   331,
     332,   333,     0,   334,     0,     0,   342,   348,   338,   339,
       0,     0,   351,     0,   370,   371,   386,   189,     0,     0,
       0,   365,   366,     0,   368,   369,     0,   378,   379,   380,
     381,     0,   382,   184,     0,   101,   106,    54,    66,   129,
     162,   166,     0,   169,   178,   138,   144,     0,     0,   276,
     284,     0,   269,   271,   278,   280,   283,   254,   297,   242,
     246,   262,     0,   264,   263,   250,   252,   255,   207,   397,
     398,     0,   395,   317,   321,   335,   344,   345,   343,   346,
     340,   341,     0,     0,     0,     0,     0,     0,     0,   389,
     189,   128,   122,   124,   126,     0,    47,     0,     0,   160,
       0,   146,   176,   270,   277,     0,   273,   282,   285,   281,
     236,     0,   245,     0,   249,     0,   286,   265,     0,   393,
     405,   394,   193,     0,   190,     0,   375,   376,   367,   377,
     390,     0,     0,     0,    56,   163,     0,   170,   173,   279,
     275,   228,   243,   247,     0,   259,     0,   260,     0,   406,
       0,   188,     0,   388,   185,   135,     0,   120,   136,   132,
     133,   134,   131,     0,   167,   174,   177,     0,   274,   233,
     237,   261,   256,   258,     0,     0,   396,   374,   123,   121,
     164,     0,   272,   231,   234,   235,   257,     0,   175,   297,
     404,   232
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yypgoto_[] =
  {
      -530,  -530,  -530,  -530,  -530,  -530,  -530,   368,   367,  -530,
    -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,
    -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,
    -530,   -68,  -530,    32,  -530,  -530,  -530,  -530,  -530,  -530,
    -530,   282,   113,  -530,    29,  -530,  -530,  -530,  -530,  -530,
    -530,   225,  -530,  -530,   211,  -530,  -530,    57,  -530,  -530,
    -530,  -530,  -530,  -530,   126,   129,   -57,  -530,  -530,  -530,
    -530,  -530,  -530,  -530,  -530,  -172,  -530,  -178,  -530,  -530,
    -530,  -305,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,
    -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,
    -530,  -530,  -530,  -530,  -530,  -530,  -530,  -270,  -152,   171,
    -530,  -288,  -102,  -101,  -321,  -530,  -530,  -530,   305,  -530,
    -530,  -530,  -530,  -530,  -530,   -59,  -530,  -530,  -530,  -530,
    -530,   125,  -427,  -530,  -530,   120,   127,  -530,  -530,  -530,
    -530,  -530,  -177,  -530,  -530,  -530,  -530,  -530,  -530,  -530,
    -530,    26,  -530,  -530,  -530,  -117,  -530,  -530,    30,  -530,
    -116,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,  -530,
    -530,  -530,  -530,  -530,  -485,  -530,  -530,  -529,  -105,  -530,
    -530,  -530,  -530,  -530,  -530,   -94,   -86,  -378,   -11,    13,
     277,  -530,  -530,  -530,     6,  -530,  -530,     2,  -530,  -530,
    -530,    -3,  -530,  -530,    -7,  -530,  -530,  -530,  -279,  -530,
    -272,  -100,  -170,  -160,  -530,  -530,  -530,  -530,  -530,  -275,
    -530,  -530,  -530,  -530,  -530,  -530,  -530,    -9,  -530,  -530,
    -530,    15,  -530,   110,   112,    34,  -182,    86,  -530,  -530
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yydefgoto_[] =
  {
        -1,     1,     2,     9,    20,    21,    48,    66,    50,    51,
      42,    43,    86,    87,   101,    95,    44,     5,     6,    10,
       7,    23,    77,    99,   107,   225,   310,   226,   308,   309,
     328,   329,   388,   389,   390,   391,    67,   127,   140,   141,
     142,   143,   128,   129,   146,   147,   173,   222,   302,   148,
     204,   205,   174,   215,   216,   223,   373,   374,   375,   376,
     377,   303,   382,   384,   304,   305,   169,   213,   606,   544,
     583,   484,   170,   369,   171,   607,   496,   150,   175,   227,
     228,   229,   405,   312,   230,   314,   315,   406,   407,   492,
     408,   490,   547,   613,   409,   491,   548,   410,   493,   550,
     411,   412,   497,   616,   631,   588,   413,   217,   218,   294,
     540,   368,   574,   533,   274,   467,    98,   106,   116,   117,
     134,   135,   118,   138,   136,   158,   434,   435,   319,   234,
     159,   160,   177,   321,   235,   178,   153,   231,   317,   316,
     421,   508,   422,   634,   639,   635,   620,   591,   416,   423,
     424,   425,   426,   562,   509,   427,   564,   510,   428,   515,
     429,   516,   623,   597,   567,   517,   430,   431,   502,   618,
     590,   554,   555,   503,   504,   558,   505,   568,   161,   120,
     131,   121,   122,   123,   162,   179,   164,   154,   246,   105,
     247,   248,   443,   330,   249,   445,   331,   250,   251,   340,
     341,   252,   253,   456,   462,   529,   457,   342,   254,   343,
     255,   256,   257,   258,   271,   209,   581,   210,   211,   259,
     570,   521,   260,   599,   600,   261,   346,   262,    81,    82,
      83,   263,    71,    72,    73,   264,    32,   265,    40,    76
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int MapSetParser::yytable_ninf_ = -298;
  const short int
  MapSetParser::yytable_[] =
  {
        26,   119,   219,    31,    33,    34,    35,   208,   414,   518,
     103,    69,   220,   278,   556,   206,   269,    78,   453,   139,
     124,   541,   272,   542,   295,   511,    79,   622,   119,   378,
     460,   292,    84,    68,   395,    70,   594,   438,   439,   595,
      69,   125,   512,   163,   208,   219,     3,   124,     4,   596,
     500,     8,   206,   572,    74,   220,   463,   126,   604,    41,
     573,    22,    68,    80,    70,   573,   513,   624,   181,    92,
     232,    49,   152,   461,    36,    37,    38,   565,   557,   165,
      85,   560,   499,    74,    90,   104,   102,    69,   347,   233,
      24,    25,   500,   566,    96,   104,    91,    69,    94,   501,
     130,   270,    39,   378,    97,   514,    75,   273,   543,    24,
      25,    70,    36,    37,    38,   395,   293,    36,    37,    38,
     155,    70,   104,   100,    69,   155,   104,   155,    69,   219,
      74,   525,   632,   566,   494,    75,   322,   323,   324,   220,
      74,   501,   104,   108,    69,    36,    37,    38,    70,   394,
     109,   104,    70,    69,   300,   301,   207,   392,   132,    36,
      37,    38,   306,   307,   104,    93,    69,    74,    70,   585,
     586,    74,   133,   417,   151,   526,   527,    70,   137,    36,
      37,    38,    75,   418,    24,    25,   145,    74,   530,   531,
      70,   551,    75,   207,   149,   167,    74,   419,    27,    28,
      29,    30,   296,   219,   417,   486,   168,   172,   232,    74,
     176,   144,   641,   220,   418,   221,   417,   156,   267,    75,
     454,   455,   156,    75,   156,   144,   418,   233,   419,   266,
     394,   268,   420,   275,   219,   276,   277,   279,   392,    75,
     419,    36,    37,    38,   220,   280,    24,    25,    75,   281,
      36,    37,    38,   212,   282,    24,    25,    45,   212,    46,
      47,    75,   283,   420,   284,   285,    57,    58,    59,    60,
      61,    62,   359,   286,   332,   333,   334,   335,   336,   337,
     287,    36,    37,    38,   338,   339,   288,   299,   379,   289,
     212,   290,   311,    36,    37,    38,   313,   318,   393,   325,
     396,   212,   104,   320,    69,   155,   432,   155,   326,   104,
     344,    69,   367,   370,   549,   327,   440,   380,   301,   552,
     381,   300,   400,   401,   397,   126,   441,   442,    70,   446,
     447,   448,   449,   450,   451,    70,    27,    28,    29,    30,
     464,   444,   452,   398,   465,  -171,   466,    74,   468,   469,
     470,   471,   402,   403,    74,   404,   472,   473,   474,   475,
     476,   477,   379,   478,    11,    12,    13,    14,    15,    16,
      17,    18,   587,    19,   479,   480,   481,   482,   214,   393,
     495,   396,   553,   561,   563,   212,   569,   571,   575,   576,
     577,   232,   578,   579,   584,   212,   589,   566,   573,    75,
     603,   625,   156,   433,   156,   397,    75,   598,   614,   615,
     233,   621,   617,   619,   636,   626,   627,    88,    89,   545,
     637,   166,   488,   399,   398,   104,   298,    69,   489,   291,
     485,   385,   546,   383,   629,   630,   345,   580,   157,   582,
     437,   415,   633,   498,   592,   436,   524,   593,   523,   528,
     507,    70,   458,   638,   459,   640,     0,     0,     0,   212,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,     0,     0,     0,     0,     0,   212,     0,     0,     0,
       0,     0,     0,     0,     0,   104,     0,    69,     0,     0,
     212,   297,     0,     0,     0,     0,     0,   104,     0,    69,
       0,     0,     0,   433,     0,   506,   433,     0,     0,     0,
       0,    70,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,    70,     0,     0,     0,     0,     0,     0,
      74,     0,     0,     0,     0,     0,   155,   155,     0,     0,
       0,     0,    74,     0,   348,   349,   350,     0,     0,   351,
       0,     0,   352,   353,   354,     0,   355,   356,   357,   358,
       0,   360,   361,   362,   363,   364,   365,   366,     0,     0,
       0,     0,   608,     0,   609,     0,     0,     0,     0,     0,
       0,     0,    75,     0,     0,   506,     0,   559,     0,     0,
       0,     0,     0,     0,    75,   608,     0,   609,   610,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   432,     0,
       0,     0,     0,     0,     0,     0,     0,   611,     0,     0,
       0,   610,     0,     0,     0,     0,     0,     0,   104,     0,
      69,     0,     0,   156,   156,     0,     0,     0,     0,     0,
     611,     0,     0,     0,     0,   483,     0,   433,     0,   433,
       0,     0,     0,     0,    70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   487,     0,     0,     0,     0,   612,
       0,     0,     0,    74,     0,     0,     0,     0,   -20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   612,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   506,     0,   433,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   520,   522,     0,     0,     0,
       0,     0,     0,   628,   605,    75,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     532,     0,     0,     0,     0,   534,   535,   536,     0,     0,
     537,     0,     0,   538,     0,     0,     0,     0,   539,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      27,    28,    29,    30,    36,    37,    38,    63,    64,     0,
       0,     0,    65,   519,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    27,    28,    29,    30,    36,
      37,    38,     0,   214,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,   237,     0,   238,   183,     0,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     601,     0,   602,     0,   239,   240,   241,   242,   243,   244,
     245,   203,     0,   386,     0,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    27,    28,    29,    30,
      36,    37,    38,   387,     0,    24,    25,     0,     0,   224,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
     111,   112,   113,   114,     0,     0,     0,  -297,   183,     0,
     184,   185,   186,   187,   188,   189,   190,   191,   115,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
       0,     0,     0,     0,   239,   240,   241,   242,   243,   244,
     245,   203,     0,     0,     0,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    27,    28,    29,    30,
      36,    37,    38,     0,     0,    24,    25,     0,     0,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      27,    28,    29,    30,    36,    37,    38,    63,    64,    24,
      25,     0,    65,   371,   372,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   214,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   110,   111,   112,   113,   114,     0,     0,     0,
    -297,   183,     0,   184,   185,   186,   187,   188,   189,   190,
     191,   115,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   110,   111,   112,   113,   114,     0,     0,
       0,     0,   180,     0,   203,     0,     0,     0,     0,     0,
       0,     0,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,    37,    38,     0,     0,    24,    25,
       0,     0,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    27,    28,    29,    30,    36,    37,    38,
      63,    64,    24,    25,   605,    65,     0,     0,     0,     0,
       0,     0,     0,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    27,    28,    29,    30,    36,    37,
      38,    63,    64,    24,    25,     0,    65,   110,   111,   112,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   115,     0,     0,     0,
       0,     0,     0,     0,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    27,    28,    29,    30,    36,
      37,    38,     0,     0,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    27,    28,
      29,    30,    36,    37,    38,    63,    64,    24,    25,   214,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,   237,     0,   238,   183,     0,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,     0,     0,     0,     0,
     239,   240,   241,   242,   243,   244,   245,   203,   214,     0,
       0,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    27,    28,    29,    30,    36,    37,    38,     0,
       0,    24,    25,   183,     0,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,     0,     0,     0,     0,   239,
     240,   241,   242,   243,   244,   245,   203,   387,     0,     0,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    27,    28,    29,    30,    36,    37,    38,     0,     0,
      24,    25,   183,     0,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,     0,     0,     0,     0,   239,   240,
     241,   242,   243,   244,   245,   203,   182,     0,     0,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      27,    28,    29,    30,    36,    37,    38,     0,     0,    24,
      25,   183,     0,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   203,   214,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,    37,    38,     0,     0,    24,    25,
     183,     0,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   203,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    36,    37,    38,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    27,    28,    29,    30,
      36,    37,    38,    63,    64,    24,    25,     0,    65,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      27,    28,    29,    30,    36,    37,    38,    63,    64,     0,
       0,     0,    65
  };

  /* YYCHECK.  */
  const short int
  MapSetParser::yycheck_[] =
  {
        11,   106,   172,    12,    13,    14,    15,   167,   313,   436,
      96,    20,   172,   191,   499,   167,    41,    26,   339,    25,
     106,    39,    41,    41,    38,    21,    88,    39,   133,   299,
      21,    41,    41,    20,   309,    20,   565,   325,   326,    39,
      49,    24,    38,   137,   204,   215,     0,   133,    17,    49,
      51,   118,   204,    42,    20,   215,   344,    40,    42,    52,
      49,    18,    49,   125,    49,    49,    62,   596,   162,    78,
     175,    38,   131,    64,   118,   119,   120,    49,    51,   138,
      38,   508,    41,    49,    22,    96,    95,    96,   266,   175,
     123,   124,    51,   105,    39,   106,   119,   106,    53,   100,
     109,   126,    16,   373,    38,   101,    20,   126,   126,   123,
     124,    96,   118,   119,   120,   390,   126,   118,   119,   120,
     131,   106,   133,    39,   133,   136,   137,   138,   137,   299,
      96,   452,   617,   105,   404,    49,   236,   237,   238,   299,
     106,   100,   153,   118,   153,   118,   119,   120,   133,   309,
      44,   162,   137,   162,    30,    31,   167,   309,    39,   118,
     119,   120,    19,    20,   175,    79,   175,   133,   153,   547,
     548,   137,    44,    41,    51,   454,   455,   162,    41,   118,
     119,   120,    96,    51,   123,   124,    90,   153,   460,   461,
     175,   496,   106,   204,    38,    27,   162,    65,   114,   115,
     116,   117,   213,   373,    41,   375,    32,    91,   313,   175,
      53,   125,   639,   373,    51,    26,    41,   131,    41,   133,
      62,    63,   136,   137,   138,   139,    51,   313,    65,    75,
     390,    41,   100,    41,   404,    41,    41,    41,   390,   153,
      65,   118,   119,   120,   404,    41,   123,   124,   162,    41,
     118,   119,   120,   167,    41,   123,   124,    11,   172,    13,
      14,   175,    41,   100,    41,    41,   108,   109,   110,   111,
     112,   113,   283,    41,    56,    57,    58,    59,    60,    61,
      41,   118,   119,   120,    66,    67,    41,    27,   299,    41,
     204,    41,    39,   118,   119,   120,    44,    50,   309,    41,
     309,   215,   313,    49,   313,   316,   317,   318,    41,   320,
      41,   320,    19,    42,   492,    89,   327,   105,    31,   497,
     105,    30,    15,    16,   309,    40,    42,    54,   313,   332,
     333,   334,   335,   336,   337,   320,   114,   115,   116,   117,
      42,    55,    67,   309,    42,    38,    42,   313,    49,    49,
      49,    42,    45,    46,   320,    48,    42,    49,    42,    42,
      49,    42,   373,    42,     3,     4,     5,     6,     7,     8,
       9,    10,   550,    12,    42,    42,    49,    42,    41,   390,
      44,   390,    42,   102,    64,   299,    42,    42,    49,    42,
      42,   496,    42,    42,    42,   309,    42,   105,    49,   313,
      42,    76,   316,   317,   318,   390,   320,    50,   586,    47,
     496,    39,   102,    50,    39,    42,    42,    49,    51,   487,
      56,   139,   390,   310,   390,   436,   215,   436,   399,   204,
     373,   305,   489,   304,   606,   613,   265,   539,   133,   540,
     320,   316,   619,   417,   561,   318,   444,   563,   442,   456,
     420,   436,   342,   631,   342,   637,    -1,    -1,    -1,   373,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     436,    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   496,    -1,   496,    -1,    -1,
     404,   214,    -1,    -1,    -1,    -1,    -1,   508,    -1,   508,
      -1,    -1,    -1,   417,    -1,   419,   420,    -1,    -1,    -1,
      -1,   496,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   436,   508,    -1,    -1,    -1,    -1,    -1,    -1,
     496,    -1,    -1,    -1,    -1,    -1,   547,   548,    -1,    -1,
      -1,    -1,   508,    -1,   267,   268,   269,    -1,    -1,   272,
      -1,    -1,   275,   276,   277,    -1,   279,   280,   281,   282,
      -1,   284,   285,   286,   287,   288,   289,   290,    -1,    -1,
      -1,    -1,   583,    -1,   583,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   496,    -1,    -1,   499,    -1,   501,    -1,    -1,
      -1,    -1,    -1,    -1,   508,   606,    -1,   606,   583,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   619,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   583,    -1,    -1,
      -1,   606,    -1,    -1,    -1,    -1,    -1,    -1,   639,    -1,
     639,    -1,    -1,   547,   548,    -1,    -1,    -1,    -1,    -1,
     606,    -1,    -1,    -1,    -1,   368,    -1,   561,    -1,   563,
      -1,    -1,    -1,    -1,   639,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   387,    -1,    -1,    -1,    -1,   583,
      -1,    -1,    -1,   639,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   606,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   617,    -1,   619,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   438,   439,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,   639,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     463,    -1,    -1,    -1,    -1,   468,   469,   470,    -1,    -1,
     473,    -1,    -1,   476,    -1,    -1,    -1,    -1,   481,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
      -1,    -1,   126,    21,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,    41,   123,   124,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    -1,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    -1,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
     573,    -1,   575,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,    21,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    41,    -1,   123,   124,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    41,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    52,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,    -1,   123,   124,    -1,    -1,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,   126,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      41,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    52,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    42,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,   119,   120,    -1,    -1,   123,   124,
      -1,    -1,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    43,   126,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,   126,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,   123,   124,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    41,
     126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    -1,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    -1,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,    41,    -1,
      -1,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,   123,   124,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    41,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
     123,   124,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    -1,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,    41,    -1,    -1,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,    -1,   123,
     124,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,   119,   120,    -1,    -1,   123,   124,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      -1,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,   119,   120,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    -1,   126,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
      -1,    -1,   126
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  MapSetParser::yystos_[] =
  {
         0,   128,   129,     0,    17,   144,   145,   147,   118,   130,
     146,     3,     4,     5,     6,     7,     8,     9,    10,    12,
     131,   132,    18,   148,   123,   124,   315,   114,   115,   116,
     117,   354,   363,   354,   354,   354,   118,   119,   120,   364,
     365,    52,   137,   138,   143,    11,    13,    14,   133,    38,
     135,   136,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   121,   122,   126,   134,   163,   316,   354,
     358,   359,   360,   361,   362,   364,   366,   149,   354,    88,
     125,   355,   356,   357,   354,    38,   139,   140,   134,   135,
      22,   119,   354,   364,    53,   142,    39,    38,   243,   150,
      39,   141,   354,   313,   315,   316,   244,   151,   118,    44,
      33,    34,    35,    36,    37,    52,   245,   246,   249,   305,
     306,   308,   309,   310,   313,    24,    40,   164,   169,   170,
     354,   307,    39,    44,   247,   248,   251,    41,   250,    25,
     165,   166,   167,   168,   364,    90,   171,   172,   176,    38,
     204,    51,   252,   263,   314,   315,   364,   245,   252,   257,
     258,   305,   311,   312,   313,   252,   168,    27,    32,   193,
     199,   201,    91,   173,   179,   205,    53,   259,   262,   312,
      42,   312,    41,    66,    68,    69,    70,    71,    72,    73,
      74,    75,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    99,   177,   178,   235,   315,   340,   342,
     344,   345,   364,   194,    41,   180,   181,   234,   235,   339,
     340,    26,   174,   182,    23,   152,   154,   206,   207,   208,
     211,   264,   305,   313,   256,   261,    62,    63,    65,    92,
      93,    94,    95,    96,    97,    98,   315,   317,   318,   321,
     324,   325,   328,   329,   335,   337,   338,   339,   340,   346,
     349,   352,   354,   358,   362,   364,    75,    41,    41,    41,
     126,   341,    41,   126,   241,    41,    41,    41,   204,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,   178,    41,   126,   236,    38,   315,   317,   181,    27,
      30,    31,   175,   188,   191,   192,    19,    20,   155,   156,
     153,    39,   210,    44,   212,   213,   266,   265,    50,   255,
      49,   260,   338,   338,   338,    41,    41,    89,   157,   158,
     320,   323,    56,    57,    58,    59,    60,    61,    66,    67,
     326,   327,   334,   336,    41,   236,   353,   204,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   315,
     317,   317,   317,   317,   317,   317,   317,    19,   238,   200,
      42,    28,    29,   183,   184,   185,   186,   187,   234,   315,
     105,   105,   189,   192,   190,   191,    21,    41,   159,   160,
     161,   162,   235,   315,   340,   346,   354,   358,   362,   169,
      15,    16,    45,    46,    48,   209,   214,   215,   217,   221,
     224,   227,   228,   233,   208,   258,   275,    41,    51,    65,
     100,   267,   269,   276,   277,   278,   279,   282,   285,   287,
     293,   294,   315,   364,   253,   254,   263,   262,   238,   238,
     315,    42,    54,   319,    55,   322,   328,   328,   328,   328,
     328,   328,    67,   241,    62,    63,   330,   333,   360,   361,
      21,    64,   331,   238,    42,    42,    42,   242,    49,    49,
      49,    42,    42,    49,    42,    42,    49,    42,    42,    42,
      42,    49,    42,   317,   198,   184,   339,   317,   160,   171,
     218,   222,   216,   225,   234,    44,   203,   229,   278,    41,
      51,   100,   295,   300,   301,   303,   364,   285,   268,   281,
     284,    21,    38,    62,   101,   286,   288,   292,   259,    21,
     317,   348,   317,   321,   324,   241,   335,   335,   331,   332,
     337,   337,   317,   240,   317,   317,   317,   317,   317,   317,
     237,    39,    41,   126,   196,   158,   193,   219,   223,   204,
     226,   208,   204,    42,   298,   299,   301,    51,   302,   364,
     259,   102,   280,    64,   283,    49,   105,   291,   304,    42,
     347,    42,    42,    49,   239,    49,    42,    42,    42,    42,
     239,   343,   240,   197,    42,   314,   314,   204,   232,    42,
     297,   274,   282,   287,   304,    39,    49,   290,    50,   350,
     351,   317,   317,    42,    42,    43,   195,   202,   315,   354,
     358,   362,   364,   220,   204,    47,   230,   102,   296,    50,
     273,    39,    39,   289,   304,    76,    42,    42,    42,   202,
     204,   231,   301,   269,   270,   272,    39,    56,   204,   271,
     363,   259
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
     375,   376,   377,   378,   379,   380,   381
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  MapSetParser::yyr1_[] =
  {
         0,   127,   129,   128,   130,   130,   131,   131,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   133,   133,   133,
     134,   134,   135,   136,   136,   137,   138,   138,   139,   139,
     140,   141,   142,   142,   143,   144,   145,   145,   146,   146,
     147,   149,   150,   148,   151,   151,   153,   152,   154,   155,
     155,   156,   156,   157,   158,   158,   159,   160,   160,   160,
     160,   160,   160,   160,   160,   161,   161,   162,   162,   163,
     164,   165,   165,   166,   167,   168,   169,   170,   170,   171,
     172,   172,   173,   173,   174,   174,   175,   175,   176,   177,
     177,   178,   178,   178,   178,   179,   180,   180,   181,   182,
     183,   183,   184,   184,   185,   185,   186,   187,   187,   188,
     188,   189,   189,   190,   190,   191,   192,   193,   194,   194,
     195,   195,   197,   196,   196,   198,   198,   200,   199,   201,
     201,   202,   202,   202,   202,   202,   202,   203,   203,   205,
     204,   206,   206,   207,   208,   208,   209,   210,   210,   211,
     212,   213,   213,   214,   214,   214,   214,   214,   214,   216,
     215,   218,   219,   220,   217,   222,   223,   221,   225,   226,
     224,   228,   229,   227,   231,   230,   232,   232,   233,   234,
     234,   234,   235,   236,   237,   236,   238,   238,   239,   240,
     240,   241,   242,   241,   244,   243,   245,   245,   246,   247,
     248,   248,   250,   249,   251,   249,   252,   253,   254,   254,
     255,   256,   256,   257,   258,   258,   259,   260,   261,   261,
     262,   263,   263,   265,   264,   266,   264,   268,   267,   269,
     269,   271,   270,   272,   272,   273,   274,   274,   275,   276,
     277,   278,   279,   280,   281,   281,   282,   283,   284,   284,
     285,   286,   286,   287,   287,   288,   289,   289,   290,   290,
     291,   291,   292,   292,   292,   292,   293,   294,   294,   294,
     294,   295,   296,   297,   297,   298,   299,   299,   300,   300,
     301,   302,   302,   303,   303,   303,   304,   305,   305,   307,
     306,   308,   309,   309,   309,   309,   309,   310,   310,   311,
     311,   312,   312,   313,   313,   314,   314,   315,   315,   316,
     316,   316,   316,   316,   316,   317,   318,   319,   320,   320,
     321,   322,   323,   323,   324,   325,   326,   326,   327,   327,
     327,   327,   327,   327,   327,   327,   328,   329,   330,   330,
     331,   331,   332,   332,   333,   333,   333,   334,   334,   335,
     336,   336,   337,   337,   337,   337,   338,   338,   338,   338,
     338,   338,   338,   338,   339,   340,   340,   340,   340,   340,
     340,   340,   340,   340,   340,   340,   340,   340,   340,   340,
     340,   340,   340,   340,   340,   340,   341,   341,   342,   343,
     343,   344,   345,   346,   346,   347,   346,   348,   348,   349,
     349,   349,   349,   349,   350,   351,   351,   352,   353,   353,
     354,   355,   356,   356,   357,   357,   358,   358,   358,   359,
     359,   359,   360,   360,   360,   361,   361,   361,   362,   362,
     363,   363,   363,   363,   364,   364,   365,   365,   366,   366
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  MapSetParser::yyr2_[] =
  {
         0,     2,     0,     4,     0,     2,     0,     2,     4,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       0,     1,     4,     1,     2,     2,     0,     1,     0,     1,
       3,     3,     0,     2,     3,     2,     0,     1,     0,     2,
       2,     0,     0,     5,     0,     2,     0,     5,     3,     1,
       1,     0,     1,     2,     0,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     7,
       2,     1,     1,     1,     2,     1,     2,     0,     1,     4,
       0,     1,     0,     1,     0,     1,     0,     1,     3,     1,
       2,     1,     1,     4,     1,     2,     1,     2,     1,     3,
       1,     2,     1,     1,     1,     1,     2,     1,     1,     2,
       2,     0,     1,     0,     1,     2,     2,     1,     0,     2,
       1,     2,     0,     4,     1,     0,     2,     0,     6,     0,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     0,
       4,     1,     1,     2,     0,     1,     3,     0,     2,     2,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     0,
       3,     0,     0,     0,     6,     0,     0,     5,     0,     0,
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
       4,     4,     2,     2,     8,     6,     6,     6,     4,     4,
       4,     4,     4,     1,     1,     1,     3,     1,     7,     0,
       1,     2,     3,     5,     5,     0,     7,     1,     1,     1,
       1,     1,     1,     1,     4,     0,     1,     2,     0,     1,
       2,     2,     1,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
  "IT_AVG", "IT_GROUP_CONCAT", "IT_SAMPLE", "IT_isNUMERIC", "GT_CARROT",
  "GT_OPT", "GT_PIPE", "IT_true", "IT_false", "INTEGER", "DECIMAL",
  "DOUBLE", "INTEGER_POSITIVE", "DECIMAL_POSITIVE", "DOUBLE_POSITIVE",
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
  "_QDatasetClause_E_Star", "SubSelect", "@4", "SelectClause",
  "_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C",
  "_Q_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C_E_Opt", "_O_QIT_AS_E_S_QVar_E_C",
  "_Q_O_QIT_AS_E_S_QVar_E_C_E_Opt",
  "_O_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_Q_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C_E_Plus",
  "_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_Plus_Or_QGT_TIMES_E_C",
  "ConstructQuery", "DatasetClause",
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
  "ServiceGraphPattern", "@12", "@13", "MinusGraphPattern", "@14", "@15",
  "GroupOrUnionGraphPattern", "@16", "@17",
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
  "ExistsFunc", "NotExistsFunc", "Aggregate", "$@29",
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
  const MapSetParser::rhs_number_type
  MapSetParser::yyrhs_[] =
  {
       128,     0,    -1,    -1,   129,   144,   130,   131,    -1,    -1,
     130,   132,    -1,    -1,   131,   163,    -1,     3,   315,   354,
     354,    -1,     4,   354,    -1,     5,   354,    -1,     6,   354,
      -1,     7,   354,    -1,     8,   364,    -1,     9,   137,    -1,
      10,   133,    -1,    12,   136,    -1,    11,    -1,    14,    -1,
      13,    -1,    -1,   316,    -1,    38,   134,    39,   313,    -1,
     135,    -1,   136,   135,    -1,   138,   139,    -1,    -1,   143,
      -1,    -1,   140,    -1,    38,   142,    39,    -1,   354,    44,
     354,    -1,    -1,   142,   141,    -1,    52,   354,    53,    -1,
     145,   146,    -1,    -1,   147,    -1,    -1,   146,   148,    -1,
      17,   118,    -1,    -1,    -1,    18,   149,   119,   150,   118,
      -1,    -1,   151,   164,    -1,    -1,   154,   153,   169,   171,
     193,    -1,    23,   156,   162,    -1,    19,    -1,    20,    -1,
      -1,   155,    -1,    89,   315,    -1,    -1,   157,    -1,    41,
     317,   158,    42,    -1,   315,    -1,   346,    -1,   340,    -1,
     235,    -1,   354,    -1,   358,    -1,   362,    -1,   159,    -1,
     160,    -1,   161,   160,    -1,   161,    -1,    21,    -1,   134,
      22,   243,   151,   169,   171,   193,    -1,    24,   165,    -1,
     166,    -1,   167,    -1,   168,    -1,    25,   168,    -1,   364,
      -1,   170,   204,    -1,    -1,    40,    -1,   172,   173,   174,
     175,    -1,    -1,   176,    -1,    -1,   179,    -1,    -1,   182,
      -1,    -1,   188,    -1,    90,    27,   177,    -1,   178,    -1,
     177,   178,    -1,   340,    -1,   235,    -1,    41,   317,   158,
      42,    -1,   315,    -1,    91,   180,    -1,   181,    -1,   180,
     181,    -1,   234,    -1,    26,    27,   183,    -1,   184,    -1,
     183,   184,    -1,   186,    -1,   187,    -1,    28,    -1,    29,
      -1,   185,   339,    -1,   234,    -1,   315,    -1,   191,   189,
      -1,   192,   190,    -1,    -1,   192,    -1,    -1,   191,    -1,
      30,   105,    -1,    31,   105,    -1,   201,    -1,    -1,   194,
     315,    -1,   202,    -1,   195,   202,    -1,    -1,    41,   197,
     195,    42,    -1,   126,    -1,    -1,   198,   196,    -1,    -1,
      32,   194,    38,   200,   198,    39,    -1,    -1,   199,    -1,
     364,    -1,   354,    -1,   358,    -1,   362,    -1,    43,    -1,
     315,    -1,    -1,    44,    -1,    -1,    38,   205,   206,    39,
      -1,   152,    -1,   207,    -1,   208,   210,    -1,    -1,   211,
      -1,   214,   203,   208,    -1,    -1,   210,   209,    -1,   264,
     213,    -1,    44,   208,    -1,    -1,   212,    -1,   227,    -1,
     215,    -1,   224,    -1,   217,    -1,   221,    -1,   233,    -1,
      -1,    45,   216,   204,    -1,    -1,    -1,    -1,    15,   218,
     219,   314,   220,   204,    -1,    -1,    -1,    16,   222,   223,
     314,   204,    -1,    -1,    -1,    46,   225,   226,   204,    -1,
      -1,    -1,   228,   229,   204,   232,    -1,    -1,    47,   231,
     204,    -1,    -1,   232,   230,    -1,    48,   234,    -1,   339,
      -1,   340,    -1,   235,    -1,   364,   236,    -1,   126,    -1,
      -1,    41,   238,   317,   237,   240,    42,    -1,    -1,    19,
      -1,    49,   317,    -1,    -1,   240,   239,    -1,   126,    -1,
      -1,    41,   317,   242,   240,    42,    -1,    -1,    38,   244,
     245,    39,    -1,    -1,   246,    -1,   249,   248,    -1,    44,
     245,    -1,    -1,   247,    -1,    -1,   313,   250,   252,    -1,
      -1,   305,   251,   257,    -1,   263,   259,   256,    -1,   263,
     259,    -1,    -1,   253,    -1,    50,   254,    -1,    -1,   256,
     255,    -1,   258,    -1,    -1,   252,    -1,   262,   261,    -1,
      49,   262,    -1,    -1,   261,   260,    -1,   312,    -1,   314,
      -1,    51,    -1,    -1,   313,   265,   267,    -1,    -1,   305,
     266,   275,    -1,    -1,   269,   268,   259,   274,    -1,   276,
      -1,   277,    -1,    -1,   269,   271,   259,    -1,    -1,   270,
      -1,    50,   272,    -1,    -1,   274,   273,    -1,   258,    -1,
     278,    -1,   315,    -1,   279,    -1,   282,   281,    -1,   102,
     282,    -1,    -1,   281,   280,    -1,   287,   284,    -1,    64,
     287,    -1,    -1,   284,   283,    -1,   293,   286,    -1,    -1,
     288,    -1,   285,    -1,   100,   285,    -1,   292,    -1,    39,
      -1,   304,    39,    -1,    49,   289,    -1,    39,    -1,   304,
     290,    -1,    49,   304,    39,    -1,    21,    -1,   101,    -1,
      62,    -1,    38,   291,    -1,   294,    -1,   364,    -1,    51,
      -1,    65,   295,    -1,    41,   278,    42,    -1,   300,    -1,
     102,   301,    -1,    -1,   297,   296,    -1,   301,   297,    -1,
      -1,   298,    -1,   301,    -1,    41,   299,    42,    -1,   303,
      -1,   364,    -1,    51,    -1,   364,    -1,    51,    -1,   100,
     302,    -1,   105,    -1,   308,    -1,   306,    -1,    -1,    52,
     307,   252,    53,    -1,   310,    41,   311,    42,    -1,    33,
      -1,    34,    -1,    35,    -1,    36,    -1,    37,    -1,    -1,
     309,    -1,   312,    -1,   311,   312,    -1,   313,    -1,   305,
      -1,   315,    -1,   316,    -1,   315,    -1,   364,    -1,   123,
      -1,   124,    -1,   364,    -1,   354,    -1,   358,    -1,   362,
      -1,   366,    -1,   126,    -1,   318,    -1,   321,   320,    -1,
      54,   321,    -1,    -1,   320,   319,    -1,   324,   323,    -1,
      55,   324,    -1,    -1,   323,   322,    -1,   325,    -1,   328,
     326,    -1,    -1,   327,    -1,    56,   328,    -1,    57,   328,
      -1,    58,   328,    -1,    59,   328,    -1,    60,   328,    -1,
      61,   328,    -1,    67,   241,    -1,    66,    67,   241,    -1,
     329,    -1,   335,   334,    -1,   360,    -1,   361,    -1,    21,
     337,    -1,    64,   337,    -1,    -1,   331,    -1,    62,   335,
      -1,    63,   335,    -1,   330,   332,    -1,    -1,   334,   333,
      -1,   337,   336,    -1,    -1,   336,   331,    -1,    65,   338,
      -1,    62,   338,    -1,    63,   338,    -1,   338,    -1,   339,
      -1,   340,    -1,   352,    -1,   354,    -1,   358,    -1,   362,
      -1,   315,    -1,   346,    -1,    41,   317,    42,    -1,    77,
      41,   317,    42,    -1,    78,    41,   317,    42,    -1,    79,
      41,   317,    49,   317,    42,    -1,    80,    41,   317,    42,
      -1,    81,    41,   315,    42,    -1,    68,    41,   317,    42,
      -1,    69,    41,   317,    42,    -1,    70,   341,    -1,    71,
     241,    -1,    72,    41,   317,    49,   317,    49,   317,    42,
      -1,    73,    41,   317,    49,   317,    42,    -1,    74,    41,
     317,    49,   317,    42,    -1,    82,    41,   317,    49,   317,
      42,    -1,    83,    41,   317,    42,    -1,    84,    41,   317,
      42,    -1,    85,    41,   317,    42,    -1,    86,    41,   317,
      42,    -1,    99,    41,   317,    42,    -1,   342,    -1,   344,
      -1,   345,    -1,    41,   317,    42,    -1,   126,    -1,    87,
      41,   317,    49,   317,   343,    42,    -1,    -1,   239,    -1,
      75,   204,    -1,    66,    75,   204,    -1,    92,    41,   238,
     348,    42,    -1,   349,    41,   238,   317,    42,    -1,    -1,
      97,    41,   238,   317,   347,   351,    42,    -1,    21,    -1,
     317,    -1,    93,    -1,    94,    -1,    95,    -1,    96,    -1,
      98,    -1,    50,    76,    56,   363,    -1,    -1,   350,    -1,
     364,   353,    -1,    -1,   236,    -1,   363,   357,    -1,    88,
     364,    -1,   125,    -1,   355,    -1,    -1,   356,    -1,   359,
      -1,   360,    -1,   361,    -1,   105,    -1,   106,    -1,   107,
      -1,   108,    -1,   109,    -1,   110,    -1,   111,    -1,   112,
      -1,   113,    -1,   103,    -1,   104,    -1,   114,    -1,   116,
      -1,   115,    -1,   117,    -1,   118,    -1,   365,    -1,   120,
      -1,   119,    -1,   121,    -1,   122,    -1
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
     100,   103,   104,   105,   111,   112,   115,   116,   122,   126,
     128,   130,   131,   133,   136,   137,   139,   144,   146,   148,
     150,   152,   154,   156,   158,   160,   162,   165,   167,   169,
     177,   180,   182,   184,   186,   189,   191,   194,   195,   197,
     202,   203,   205,   206,   208,   209,   211,   212,   214,   218,
     220,   223,   225,   227,   232,   234,   237,   239,   242,   244,
     248,   250,   253,   255,   257,   259,   261,   264,   266,   268,
     271,   274,   275,   277,   278,   280,   283,   286,   288,   289,
     292,   294,   297,   298,   303,   305,   306,   309,   310,   317,
     318,   320,   322,   324,   326,   328,   330,   332,   333,   335,
     336,   341,   343,   345,   348,   349,   351,   355,   356,   359,
     362,   365,   366,   368,   370,   372,   374,   376,   378,   380,
     381,   385,   386,   387,   388,   395,   396,   397,   403,   404,
     405,   410,   411,   412,   417,   418,   422,   423,   426,   429,
     431,   433,   435,   438,   440,   441,   448,   449,   451,   454,
     455,   458,   460,   461,   467,   468,   473,   474,   476,   479,
     482,   483,   485,   486,   490,   491,   495,   499,   502,   503,
     505,   508,   509,   512,   514,   515,   517,   520,   523,   524,
     527,   529,   531,   533,   534,   538,   539,   543,   544,   549,
     551,   553,   554,   558,   559,   561,   564,   565,   568,   570,
     572,   574,   576,   579,   582,   583,   586,   589,   592,   593,
     596,   599,   600,   602,   604,   607,   609,   611,   614,   617,
     619,   622,   626,   628,   630,   632,   635,   637,   639,   641,
     644,   648,   650,   653,   654,   657,   660,   661,   663,   665,
     669,   671,   673,   675,   677,   679,   682,   684,   686,   688,
     689,   694,   699,   701,   703,   705,   707,   709,   710,   712,
     714,   717,   719,   721,   723,   725,   727,   729,   731,   733,
     735,   737,   739,   741,   743,   745,   747,   750,   753,   754,
     757,   760,   763,   764,   767,   769,   772,   773,   775,   778,
     781,   784,   787,   790,   793,   796,   800,   802,   805,   807,
     809,   812,   815,   816,   818,   821,   824,   827,   828,   831,
     834,   835,   838,   841,   844,   847,   849,   851,   853,   855,
     857,   859,   861,   863,   865,   869,   874,   879,   886,   891,
     896,   901,   906,   909,   912,   921,   928,   935,   942,   947,
     952,   957,   962,   967,   969,   971,   973,   977,   979,   987,
     988,   990,   993,   997,  1003,  1009,  1010,  1018,  1020,  1022,
    1024,  1026,  1028,  1030,  1032,  1037,  1038,  1040,  1043,  1044,
    1046,  1049,  1052,  1054,  1056,  1057,  1059,  1061,  1063,  1065,
    1067,  1069,  1071,  1073,  1075,  1077,  1079,  1081,  1083,  1085,
    1087,  1089,  1091,  1093,  1095,  1097,  1099,  1101,  1103,  1105
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  MapSetParser::yyrline_[] =
  {
         0,   387,   387,   387,   393,   395,   399,   401,   405,   414,
     417,   420,   423,   426,   429,   431,   435,   441,   444,   447,
     453,   456,   460,   472,   473,   477,   480,   482,   485,   487,
     491,   495,   500,   502,   506,   513,   517,   519,   523,   525,
     529,   535,   537,   535,   547,   550,   558,   558,   569,   577,
     580,   587,   590,   595,   602,   605,   610,   617,   620,   623,
     626,   629,   632,   635,   639,   644,   647,   655,   658,   665,
     675,   682,   683,   687,   693,   699,   706,   713,   715,   720,
     727,   730,   735,   738,   743,   746,   751,   755,   759,   766,
     769,   776,   779,   782,   785,   791,   797,   800,   807,   812,
     819,   823,   831,   833,   841,   844,   852,   860,   861,   868,
     872,   880,   883,   888,   891,   895,   901,   909,   914,   917,
     924,   927,   933,   933,   939,   945,   948,   955,   955,   964,
     967,   971,   974,   977,   980,   983,   986,   992,   994,   999,
     999,  1011,  1012,  1017,  1021,  1023,  1033,  1037,  1040,  1056,
    1061,  1065,  1068,  1072,  1073,  1074,  1075,  1076,  1077,  1081,
    1081,  1096,  1099,  1101,  1096,  1112,  1115,  1112,  1124,  1127,
    1124,  1137,  1140,  1137,  1150,  1150,  1164,  1166,  1170,  1181,
    1182,  1183,  1187,  1195,  1199,  1199,  1208,  1211,  1218,  1224,
    1226,  1240,  1243,  1243,  1253,  1253,  1261,  1263,  1268,  1273,
    1277,  1279,  1283,  1283,  1286,  1286,  1293,  1298,  1302,  1304,
    1309,  1313,  1315,  1320,  1324,  1326,  1331,  1336,  1340,  1342,
    1346,  1353,  1357,  1365,  1365,  1368,  1368,  1374,  1374,  1380,
    1381,  1385,  1385,  1390,  1392,  1396,  1399,  1401,  1405,  1409,
    1413,  1419,  1423,  1427,  1430,  1432,  1436,  1440,  1445,  1447,
    1453,  1456,  1458,  1464,  1465,  1471,  1475,  1476,  1480,  1481,
    1485,  1486,  1490,  1491,  1492,  1493,  1497,  1501,  1504,  1507,
    1510,  1516,  1520,  1523,  1525,  1529,  1532,  1534,  1538,  1539,
    1543,  1547,  1548,  1552,  1553,  1554,  1558,  1563,  1564,  1568,
    1568,  1581,  1606,  1609,  1612,  1615,  1618,  1625,  1628,  1633,
    1637,  1644,  1645,  1649,  1652,  1656,  1659,  1665,  1666,  1670,
    1673,  1676,  1679,  1682,  1683,  1689,  1694,  1703,  1710,  1713,
    1721,  1730,  1737,  1740,  1747,  1752,  1763,  1766,  1770,  1773,
    1776,  1779,  1782,  1785,  1788,  1791,  1797,  1802,  1811,  1814,
    1821,  1824,  1831,  1834,  1839,  1842,  1846,  1860,  1863,  1871,
    1880,  1883,  1890,  1893,  1896,  1899,  1903,  1904,  1905,  1906,
    1909,  1912,  1915,  1918,  1922,  1928,  1931,  1934,  1937,  1940,
    1943,  1946,  1950,  1953,  1957,  1960,  1963,  1966,  1969,  1972,
    1975,  1978,  1981,  1984,  1985,  1986,  1992,  1995,  2002,  2009,
    2012,  2016,  2023,  2030,  2033,  2037,  2037,  2049,  2053,  2057,
    2060,  2063,  2066,  2069,  2075,  2081,  2084,  2088,  2098,  2101,
    2106,  2114,  2121,  2125,  2133,  2137,  2141,  2142,  2143,  2147,
    2148,  2149,  2153,  2154,  2155,  2159,  2160,  2161,  2165,  2166,
    2170,  2171,  2172,  2173,  2177,  2178,  2182,  2183,  2187,  2188
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
     125,   126
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int MapSetParser::yyeof_ = 0;
  const int MapSetParser::yylast_ = 1602;
  const int MapSetParser::yynnts_ = 240;
  const int MapSetParser::yyempty_ = -2;
  const int MapSetParser::yyfinal_ = 3;
  const int MapSetParser::yyterror_ = 1;
  const int MapSetParser::yyerrcode_ = 256;
  const int MapSetParser::yyntokens_ = 127;

  const unsigned int MapSetParser::yyuser_token_number_max_ = 381;
  const MapSetParser::token_number_type MapSetParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 4224 "lib/MapSetParser/MapSetParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 2194 "lib/MapSetParser/MapSetParser.ypp"
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


