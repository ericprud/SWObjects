
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
#line 664 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = NULL;
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 667 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (2)].p_TTerm);
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 674 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(7) - (5)].p_WhereClause)->m_BindingClause = (yysemantic_stack_[(7) - (7)].p_BindingsClause);
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	Construct* constr = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(7) - (3)].p_BasicGraphPattern), (yysemantic_stack_[(7) - (4)].p_DatasetClauses), (yysemantic_stack_[(7) - (5)].p_WhereClause), (yysemantic_stack_[(7) - (6)].p_SolutionModifier));
	driver.root->maps.push_back(LabeledConstruct((yysemantic_stack_[(7) - (1)].p_TTerm), constr));
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 684 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 696 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 702 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 708 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 715 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp ? driver.curOp : new DefaultGraphPattern(), NULL);
	driver.curOp = NULL;
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 729 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 736 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 744 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 752 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 760 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 768 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 775 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 778 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 785 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 788 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 791 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 794 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 800 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 806 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 809 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 821 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 828 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 832 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 842 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 850 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 853 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 861 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 870 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 877 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 881 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 889 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 897 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 904 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 910 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 923 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTermList) = new TTermList;
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 926 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTermList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_TTermList) = (yysemantic_stack_[(2) - (1)].p_TTermList);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 933 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 936 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 942 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding = new Binding();
      }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 944 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BindingValue) = driver.curBinding;
	  driver.curBinding = NULL;
      }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 948 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding = new Binding();
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 954 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 957 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBindingsClause->push_back((yysemantic_stack_[(2) - (2)].p_BindingValue));
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 964 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBindingsClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_TTermList));
      }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 966 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BindingsClause) = driver.curBindingsClause;
	  driver.curBindingsClause = NULL;
      }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 973 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BindingsClause) = NULL;
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 980 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 983 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 986 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 989 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 992 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 995 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1008 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1011 "lib/MapSetParser/MapSetParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1090 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 1093 "lib/MapSetParser/MapSetParser.ypp"
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

  case 163:

/* Line 678 of lalr1.cc  */
#line 1105 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 1108 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1110 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1113 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1121 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1124 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1126 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(5) - (4)].p_TTerm), driver.curOp, driver.atomFactory, false));
      }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1133 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 1136 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 1138 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.curOp));
      }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 1146 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1149 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 1151 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 1159 "lib/MapSetParser/MapSetParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 1164 "lib/MapSetParser/MapSetParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 1179 "lib/MapSetParser/MapSetParser.ypp"
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
#line 1196 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 1204 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 1208 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 1210 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = NULL;
      }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 1217 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 1220 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 1227 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 1235 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 1249 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 1252 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1254 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1262 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1264 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 1292 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 1295 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 1355 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 1362 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 1366 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 1374 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 1377 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 1383 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 1394 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 1422 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 1449 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 1456 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 1467 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 1474 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 1510 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 1513 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 1516 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 1519 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 1577 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 1581 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 1590 "lib/MapSetParser/MapSetParser.ypp"
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

  case 294:

/* Line 678 of lalr1.cc  */
#line 1615 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 1618 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 1621 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 1624 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 1627 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 1634 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 1642 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 1646 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 1658 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 1665 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 1668 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 1679 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 1682 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 1685 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 1688 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 1692 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 1703 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 1712 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 1719 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 1722 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 1730 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 1739 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 1746 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 1749 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 1761 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_GeneralComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_GeneralComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_GeneralComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 1772 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 1779 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 1782 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 1785 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 1788 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 1791 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 1794 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 1797 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 1800 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 1811 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 1820 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 1823 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 1830 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 1833 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 1840 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 1848 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 1851 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 1855 "lib/MapSetParser/MapSetParser.ypp"
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

  case 349:

/* Line 678 of lalr1.cc  */
#line 1869 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 1872 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 1880 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 1889 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 1892 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 1899 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 1902 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 1905 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 1915 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 1918 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 1921 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 1924 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 1931 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 1937 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 1940 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 1943 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 1946 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 1949 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 1952 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 1955 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 1959 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_blank, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 1962 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 1966 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 1969 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 1972 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 1975 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 1978 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 1981 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 1984 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 1987 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 1990 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 2001 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 2004 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 2011 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_regex, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 2018 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 2025 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 2032 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 2039 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 2042 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 2046 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 2048 "lib/MapSetParser/MapSetParser.ypp"
    {
	  // x = new ArgList($2, driver.curExprList);
	  delete driver.curExprList;
	  driver.curExprList = NULL;
	  w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // $$ = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group-concat, $3, $4.p_Expression, $4.separator));
    }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 2058 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
	driver.countStar = true;
    }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 2066 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 2069 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 2072 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 2075 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 2078 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 2084 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 2090 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 2097 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 2107 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 2115 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 2123 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 2130 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 2134 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 2142 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 2825 "lib/MapSetParser/MapSetParser.cpp"
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
  const short int MapSetParser::yypact_ninf_ = -527;
  const short int
  MapSetParser::yypact_[] =
  {
      -527,    48,    36,  -527,   -36,  -527,  -527,  -527,  -527,   416,
      74,   -50,   162,   162,   162,   162,   232,    32,    66,    76,
      27,  -527,  -527,  -527,  -527,  -527,   162,  -527,  -527,  -527,
    -527,  -527,   -58,  -527,  -527,  -527,  -527,  -527,  -527,  -527,
    -527,   162,  -527,    81,  -527,  -527,  -527,  -527,  -527,  1366,
    -527,    76,  1366,    90,  -527,     3,   162,   232,  -527,  -527,
    -527,  -527,    71,  -527,  -527,  -527,  -527,  -527,  -527,  -527,
    -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,
      96,  -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,
    -527,  -527,   103,  -527,  -527,  -527,  -527,   117,  1342,  -527,
    -527,    33,  -527,  -527,   100,  -527,  -527,  -527,   879,    20,
    -527,   162,  -527,  -527,  -527,  -527,  -527,  -527,   114,  -527,
     111,  -527,  -527,  -527,  -527,   122,  -527,   -12,  -527,  -527,
      68,   128,  -527,   151,  -527,   879,  -527,  -527,   151,  1004,
     151,   232,  -527,  -527,  -527,  -527,  -527,   146,   144,    93,
    -527,  -527,  -527,  -527,   126,  1004,  -527,  -527,  -527,  -527,
    -527,  -527,  -527,  -527,   910,  -527,  -527,  -527,  -527,  1265,
    -527,  -527,  -527,  -527,  1324,   160,  -527,   756,  -527,  -527,
    -527,  -527,  -527,  -527,  1088,   112,   149,   152,   -17,   -15,
     155,   157,   159,   128,   168,   174,   176,   179,   194,   195,
     197,   200,   203,   208,   209,   211,  1265,  -527,  -527,  -527,
    -527,  -527,  -527,  -527,   -13,   -19,  1088,  1324,  -527,  -527,
    -527,  -527,  -527,   226,    86,  -527,   113,  -527,  -527,   219,
    -527,  -527,  -527,   217,  -527,  -527,   212,   216,  1147,  1147,
    1147,   231,  -527,  -527,  -527,  -527,   239,  -527,  -527,   196,
    -527,  -527,  -527,  -527,   288,  -527,  -527,  -527,  -527,  -527,
    -527,  -527,   243,  -527,  -527,  -527,  -527,   -13,   128,  1088,
    1088,  1088,  -527,  -527,  1088,  -527,  -527,  1088,  1088,  1088,
    -527,  1088,  1088,  1088,  1088,   -50,  1088,  1088,  1088,  1088,
    1088,  1088,  1088,  -527,   269,  -527,  -527,  -527,  -527,   248,
    -527,   855,   199,   204,  -527,  -527,   271,   270,  -527,  -527,
    -527,   732,   279,  -527,    18,   879,  -527,  -527,   151,   163,
     151,  -527,  1004,  -527,  -527,  -527,  -527,   269,   269,   -50,
    -527,   278,   275,   301,  1088,  1088,  1088,  1088,  1088,  1088,
     257,   -15,  -527,  -527,   229,     8,   269,  -527,  -527,  -527,
     316,   317,   326,  -527,   327,   329,   330,   333,   341,   335,
     343,   344,   338,   347,   349,   350,   351,   345,   353,  -527,
    1088,  -527,  -527,  -527,  -527,   855,  -527,   355,  -527,  -527,
    -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,  1088,
    -527,  -527,  1206,  -527,  -527,  -527,  -527,  -527,  -527,  -527,
    -527,    68,  -527,  -527,  -527,  -527,  1324,  -527,   356,  -527,
    -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,   127,
    -527,    42,   148,  -527,  -527,  -527,  -527,  -527,  -527,  -527,
    -527,  -527,    -1,  -527,  -527,  -527,  -527,  -527,  1004,  -527,
     652,  1088,  -527,  -527,  1088,  -527,  1088,  -527,  -527,  -527,
    -527,  -527,  -527,  -527,   -15,  -527,  1088,  1088,     8,  -527,
    -527,  -527,  1088,  1088,  -527,  1088,  -527,  -527,  -527,  -527,
    1088,  1088,  1088,  -527,  -527,  1088,  -527,  -527,  1088,  -527,
    -527,  -527,  -527,  1088,  -527,  -527,   -16,  -527,  -527,   196,
    -527,   144,  -527,  -527,   128,  -527,  -527,  -527,   879,   128,
     357,   137,  -527,    52,  -527,  -527,  -527,  -527,  -527,  -527,
    1004,   295,   339,  -527,   -28,  -527,  -527,  -527,  -527,  -527,
    -527,  -527,  -527,   362,  -527,  -527,  -527,  -527,  -527,  -527,
    -527,  -527,  -527,  -527,   364,     6,   358,   366,   368,   369,
     370,   367,  -527,  -527,  -527,  -527,  -527,   371,  -527,   247,
     247,  -527,   128,  -527,  -527,  -527,  -527,   373,  -527,  -527,
    -527,  -527,  -527,   127,  -527,   127,  -527,   324,  -527,  -527,
      -4,  -527,   380,  -527,  -527,  1088,  -527,  1088,  -527,  -527,
    -527,  -527,  -527,   389,    26,   961,  -527,  -527,   128,  -527,
     388,  -527,   334,   387,  -527,  -527,   399,  -527,    -3,  -527,
     363,  -527,   398,  -527,   400,  -527,  -527,  -527,   529,  -527,
    -527,  -527,  -527,  -527,  -527,   128,  -527,  -527,  -527,   137,
    -527,   163,  -527,  -527,  -527,  -527,   402,   390,  -527,  -527,
    -527,  -527,  -527,   128,  -527,  -527,  -527,  -527,  -527,   162,
    -527,  1004,  -527,  -527
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  MapSetParser::yydefact_[] =
  {
         2,     0,    36,     1,     0,     4,    38,    37,    40,     6,
      35,     0,     0,     0,     0,     0,     0,    26,     0,     0,
       3,     5,    41,    39,   309,   310,     0,   432,   434,   433,
     435,     9,   416,    10,    11,    12,   436,   439,   438,    13,
     437,     0,    14,    28,    27,    17,    19,    18,    15,    20,
      23,    16,     0,     0,     7,     0,     0,     0,   414,   415,
     417,   412,     0,    32,    25,    29,   430,   431,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   440,   441,   316,
       0,    21,   312,   313,   418,   419,   420,   314,   311,   315,
      24,    70,     0,    42,     8,   413,    34,     0,     0,   196,
      44,     0,    30,    33,     0,    22,   305,   306,   198,    79,
      43,     0,   294,   295,   296,   297,   298,   291,     0,   199,
     202,   206,   290,   289,   300,     0,   204,     0,    80,    45,
      82,     0,    31,     0,   197,   198,   203,   200,   216,   299,
       0,     0,    72,    73,    74,    75,    77,     0,   131,    84,
      83,   141,    78,   224,     0,   299,   223,   307,   308,   201,
     217,   207,   215,   304,   299,   301,   303,   205,    76,     0,
     120,    71,   132,   119,     0,    86,    85,   146,   292,   213,
     220,   222,   293,   302,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    94,    96,
      93,   385,   386,   387,     0,     0,     0,    97,    98,   100,
     183,   181,   182,     0,    88,    87,    51,   143,    46,     0,
     144,   149,   147,   153,   227,   225,   208,   218,     0,     0,
       0,     0,   401,   402,   403,   404,     0,   405,   364,    54,
     317,   320,   324,   326,   328,   338,   349,   352,   357,   358,
     359,   365,     0,   360,   361,   362,   363,   410,     0,     0,
       0,     0,   389,   374,     0,   193,   375,     0,     0,     0,
     393,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,   188,   185,   184,   129,   121,     0,
      99,     0,     0,     0,    81,    89,   113,   115,    49,    50,
      52,     0,    79,   142,   145,   146,   154,   151,   216,     0,
     210,   214,   299,   221,   355,   356,   354,   188,   188,     0,
      55,     0,   318,   322,     0,     0,     0,     0,     0,     0,
       0,     0,   327,   329,   339,   351,   188,   411,   409,   394,
       0,     0,     0,   194,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   189,
       0,   127,   366,   106,   107,   101,   102,     0,   104,   105,
     109,   110,   117,   118,   111,   114,   112,   116,    68,     0,
      64,    65,    67,    48,    60,    57,    59,    58,    61,    62,
      63,    82,   163,   167,   161,   170,     0,   150,   139,   156,
     158,   159,   157,   155,   174,   160,   152,   240,   228,     0,
     270,     0,     0,   226,   229,   231,   232,   241,   243,   246,
     255,   250,   253,   268,   242,   269,   211,   212,   299,   219,
       0,     0,    53,    95,     0,   321,     0,   325,   330,   331,
     332,   333,   334,   335,     0,   336,     0,     0,   344,   350,
     340,   341,     0,     0,   353,     0,   372,   373,   388,   191,
       0,     0,     0,   367,   368,     0,   370,   371,     0,   380,
     381,   382,   383,     0,   384,   186,     0,   103,   108,    54,
      66,   131,   164,   168,     0,   171,   180,   140,   146,     0,
       0,   278,   286,     0,   271,   273,   280,   282,   285,   256,
     299,   244,   248,   264,     0,   266,   265,   252,   254,   257,
     209,   399,   400,     0,   397,   319,   323,   337,   346,   347,
     345,   348,   342,   343,     0,     0,     0,     0,     0,     0,
       0,   391,   191,   130,   124,   126,   128,     0,    47,     0,
       0,   162,     0,   148,   178,   272,   279,     0,   275,   284,
     287,   283,   238,     0,   247,     0,   251,     0,   288,   267,
       0,   395,   407,   396,   195,     0,   192,     0,   377,   378,
     369,   379,   392,     0,     0,     0,    56,   165,     0,   172,
     175,   281,   277,   230,   245,   249,     0,   261,     0,   262,
       0,   408,     0,   190,     0,   390,   187,   137,     0,   122,
     138,   134,   135,   136,   133,     0,   169,   176,   179,     0,
     276,   235,   239,   263,   258,   260,     0,     0,   398,   376,
     125,   123,   166,     0,   274,   233,   236,   237,   259,     0,
     177,   299,   406,   234
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yypgoto_[] =
  {
      -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,   393,  -527,
    -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,
    -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,
    -527,   -44,  -527,    54,  -527,  -527,  -527,  -527,  -527,  -527,
    -527,  -527,   307,   138,  -527,    51,  -527,  -527,  -527,  -527,
    -527,  -527,   249,  -527,  -527,   236,  -527,  -527,    79,  -527,
    -527,  -527,  -527,  -527,  -527,   150,   154,   -35,  -527,  -527,
    -527,  -527,  -527,  -527,  -527,  -527,  -150,  -527,  -182,  -527,
    -527,  -527,  -306,  -527,  -527,  -527,  -527,  -527,  -527,  -527,
    -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,
    -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,  -285,  -162,
     201,  -527,  -275,   -80,   -79,  -322,  -527,  -527,  -527,   331,
    -527,  -527,  -527,  -527,  -527,  -527,   -42,  -527,  -527,  -527,
    -527,  -527,   153,  -428,  -527,  -527,   145,   156,  -527,  -527,
    -527,  -527,  -527,  -152,  -527,  -527,  -527,  -527,  -527,  -527,
    -527,  -527,    53,  -527,  -527,  -527,   -93,  -527,  -527,    55,
    -527,   -92,  -527,  -527,  -527,  -527,  -527,  -527,  -527,  -527,
    -527,  -527,  -527,  -527,  -527,  -488,  -527,  -527,  -526,  -107,
    -527,  -527,  -527,  -527,  -527,  -527,  -106,   -96,  -411,   -11,
      11,    45,  -527,  -527,  -527,    30,  -527,  -527,    29,  -527,
    -527,  -527,   -40,  -527,  -527,    21,  -527,  -527,  -527,  -309,
    -527,  -237,   135,  -166,  -151,  -527,  -527,  -527,  -527,  -527,
    -296,  -527,  -527,  -527,  -527,  -527,  -527,  -527,    -9,  -527,
    -527,  -527,    67,  -527,   134,   139,    88,  -157,    43,  -527,
    -527
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yydefgoto_[] =
  {
        -1,     1,     2,     9,    20,    21,    48,    80,    50,    51,
      42,    43,    64,    65,   103,    97,    44,     5,     6,    10,
       7,    23,    55,   101,   109,   227,   312,   228,   310,   311,
     330,   331,   390,   391,   392,   393,    53,    54,   129,   142,
     143,   144,   145,   130,   131,   148,   149,   175,   224,   304,
     150,   206,   207,   176,   217,   218,   225,   375,   376,   377,
     378,   379,   305,   384,   386,   306,   307,   171,   215,   608,
     546,   585,   486,   172,   371,   173,   609,   498,   152,   177,
     229,   230,   231,   407,   314,   232,   316,   317,   408,   409,
     494,   410,   492,   549,   615,   411,   493,   550,   412,   495,
     552,   413,   414,   499,   618,   633,   590,   415,   219,   220,
     296,   542,   370,   576,   535,   276,   469,   100,   108,   118,
     119,   136,   137,   120,   140,   138,   160,   436,   437,   321,
     236,   161,   162,   179,   323,   237,   180,   155,   233,   319,
     318,   423,   510,   424,   636,   641,   637,   622,   593,   418,
     425,   426,   427,   428,   564,   511,   429,   566,   512,   430,
     517,   431,   518,   625,   599,   569,   519,   432,   433,   504,
     620,   592,   556,   557,   505,   506,   560,   507,   570,   163,
     122,   133,   123,   124,   125,   164,   181,   166,   156,   248,
     107,   249,   250,   445,   332,   251,   447,   333,   252,   253,
     342,   343,   254,   255,   458,   464,   531,   459,   344,   256,
     345,   257,   258,   259,   260,   273,   211,   583,   212,   213,
     261,   572,   523,   262,   601,   602,   263,   348,   264,    59,
      60,    61,   265,    84,    85,    86,   266,    32,   267,    40,
      89
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int MapSetParser::yytable_ninf_ = -300;
  const short int
  MapSetParser::yytable_[] =
  {
        26,   121,   105,    31,    33,    34,    35,   208,   221,   416,
     520,   280,   126,   558,   141,   397,   380,    56,   210,   455,
     297,   513,   567,   222,   543,   271,   544,   274,   121,   294,
     462,    57,    62,   165,   402,   403,   597,   624,   514,   126,
      82,   596,    52,    82,   208,   127,   598,    94,     3,   574,
     -69,   221,   440,   441,     4,   210,   575,  -173,   183,    39,
      81,   128,   515,    91,   404,   405,   222,   406,    58,   606,
     234,   465,   626,   463,    24,    25,   575,    45,   568,    46,
      47,   235,   562,     8,   501,    41,   349,   106,   104,    82,
     380,   154,    88,    22,   502,    88,   397,   106,   167,    82,
      95,   516,   132,   568,   559,    24,    25,    36,    37,    38,
     272,   545,   275,    92,   295,    49,    83,   302,   303,    83,
      63,   496,   157,    93,   106,    96,    82,   157,   106,   157,
      82,   634,   527,   308,   309,   221,    98,    87,   587,   588,
      87,    88,    99,   503,   106,   111,    82,   528,   529,   394,
     222,    88,   110,   106,   134,    82,   135,   102,   209,   147,
     396,    36,    37,    38,   139,    83,   106,   151,    82,   419,
     146,    36,    37,    38,   169,    83,   158,   170,    88,   420,
     178,   158,    88,   158,   146,   174,    87,   223,   268,   502,
     419,   269,   553,   421,   270,   209,    87,   277,    88,   278,
     420,   279,    83,   153,   298,   419,    83,    88,   234,   221,
     281,   488,   214,   643,   421,   420,   282,   214,   283,   235,
      88,   284,    83,    87,   222,   532,   533,    87,   422,   421,
     394,    83,    27,    28,    29,    30,   285,   286,   503,   287,
     221,   396,   288,    87,    83,   289,    36,    37,    38,   214,
     290,   291,    87,   292,   301,   222,    36,    37,    38,   313,
     214,   299,   315,   320,   422,    87,   322,    36,    37,    38,
      36,    37,    38,   327,   361,    24,    25,    27,    28,    29,
      30,   328,    36,    37,    38,   346,   329,    24,    25,   369,
     381,   372,   456,   457,   448,   449,   450,   451,   452,   453,
     395,   302,   398,   303,   106,   382,    82,   157,   434,   157,
     383,   106,   551,    82,   350,   351,   352,   554,   442,   353,
     128,   443,   354,   355,   356,   454,   357,   358,   359,   360,
     444,   362,   363,   364,   365,   366,   367,   368,    71,    72,
      73,    74,    75,    76,   214,   334,   335,   336,   337,   338,
     339,    36,    37,    38,   214,   340,   341,   446,    88,   466,
     467,   158,   435,   158,   381,    88,    36,    37,    38,   468,
     589,    24,    25,   324,   325,   326,   473,   470,   399,   471,
     472,   395,    83,   398,   474,   475,   476,   477,   478,    83,
     479,   234,   480,   481,   482,   483,   484,   216,   563,   400,
     555,   497,   235,    87,   565,   571,   616,   573,   577,   578,
      87,   579,   580,   581,   586,   485,   591,   575,   214,    11,
      12,    13,    14,    15,    16,    17,    18,   106,    19,    82,
     568,   600,   605,   632,   489,   214,   617,   619,   621,   623,
     627,   628,   638,   629,    90,   547,   490,   639,   168,   214,
     401,   640,   491,   300,   487,   293,   548,   387,   631,   399,
     385,   582,   435,   584,   508,   435,   159,   439,   347,   635,
     594,   417,   500,   595,   525,   526,   438,   509,   460,   530,
     400,    88,   642,   461,     0,   522,   524,   106,     0,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   106,
       0,    82,     0,     0,     0,    83,     0,     0,     0,     0,
     534,     0,     0,     0,     0,   536,   537,   538,     0,     0,
     539,     0,     0,   540,     0,     0,    87,     0,   541,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   157,   157,
       0,    88,     0,     0,   508,     0,   561,     0,     0,     0,
       0,     0,     0,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    83,     0,     0,     0,     0,
       0,     0,   630,   607,   610,     0,   611,    83,     0,     0,
       0,     0,     0,     0,     0,     0,    87,     0,     0,     0,
       0,     0,   158,   158,     0,     0,     0,   610,    87,   611,
       0,     0,     0,     0,     0,     0,   435,     0,   435,     0,
     434,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     603,     0,   604,     0,     0,     0,     0,     0,   614,     0,
     106,     0,    82,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    27,    28,    29,    30,    36,    37,
      38,   614,   612,    24,    25,     0,     0,     0,     0,     0,
       0,     0,   508,     0,   435,     0,     0,     0,     0,     0,
       0,     0,     0,   613,   521,   612,     0,     0,     0,     0,
       0,     0,     0,     0,    88,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   216,     0,   613,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,     0,
       0,     0,     0,     0,     0,   238,   239,     0,   240,   185,
       0,   186,   187,   188,   189,   190,   191,   192,   193,    87,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,     0,     0,     0,     0,   241,   242,   243,   244,   245,
     246,   247,   205,     0,   388,     0,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    27,    28,    29,
      30,    36,    37,    38,   389,     0,    24,    25,     0,     0,
     226,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     112,   113,   114,   115,   116,     0,     0,     0,  -299,   185,
       0,   186,   187,   188,   189,   190,   191,   192,   193,   117,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,     0,     0,     0,     0,   241,   242,   243,   244,   245,
     246,   247,   205,     0,     0,     0,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    27,    28,    29,
      30,    36,    37,    38,     0,     0,    24,    25,     0,     0,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    27,    28,    29,    30,    36,    37,    38,    77,    78,
      24,    25,     0,    79,   373,   374,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   216,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   112,   113,   114,   115,   116,     0,     0,
       0,  -299,   185,     0,   186,   187,   188,   189,   190,   191,
     192,   193,   117,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   112,   113,   114,   115,   116,     0,
       0,     0,     0,   182,     0,   205,     0,     0,     0,     0,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    36,    37,    38,     0,     0,    24,
      25,     0,     0,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    27,    28,    29,    30,    36,    37,
      38,    77,    78,    24,    25,   607,    79,     0,     0,     0,
       0,     0,     0,     0,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    27,    28,    29,    30,    36,
      37,    38,    77,    78,    24,    25,     0,    79,   112,   113,
     114,   115,   116,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   117,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    27,    28,    29,    30,
      36,    37,    38,     0,     0,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    27,
      28,    29,    30,    36,    37,    38,    77,    78,    24,    25,
     216,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   238,   239,     0,   240,   185,     0,   186,   187,   188,
     189,   190,   191,   192,   193,     0,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,     0,     0,     0,
       0,   241,   242,   243,   244,   245,   246,   247,   205,   216,
       0,     0,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    27,    28,    29,    30,    36,    37,    38,
       0,     0,    24,    25,   185,     0,   186,   187,   188,   189,
     190,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,     0,     0,     0,     0,
     241,   242,   243,   244,   245,   246,   247,   205,   389,     0,
       0,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    27,    28,    29,    30,    36,    37,    38,     0,
       0,    24,    25,   185,     0,   186,   187,   188,   189,   190,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,     0,     0,     0,     0,   241,
     242,   243,   244,   245,   246,   247,   205,   184,     0,     0,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    27,    28,    29,    30,    36,    37,    38,     0,     0,
      24,    25,   185,     0,   186,   187,   188,   189,   190,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,   216,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    36,    37,    38,     0,     0,    24,
      25,   185,     0,   186,   187,   188,   189,   190,   191,   192,
     193,     0,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   205,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,    37,    38,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    27,    28,    29,
      30,    36,    37,    38,    77,    78,    24,    25,     0,    79,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    27,    28,    29,    30,    36,    37,    38,    77,    78,
       0,     0,     0,    79
  };

  /* YYCHECK.  */
  const short int
  MapSetParser::yycheck_[] =
  {
        11,   108,    98,    12,    13,    14,    15,   169,   174,   315,
     438,   193,   108,   501,    26,   311,   301,    26,   169,   341,
      39,    22,    50,   174,    40,    42,    42,    42,   135,    42,
      22,    89,    41,   139,    16,    17,    40,    40,    39,   135,
      49,   567,    15,    52,   206,    25,    50,    56,     0,    43,
      23,   217,   327,   328,    18,   206,    50,    39,   164,    16,
      49,    41,    63,    52,    46,    47,   217,    49,   126,    43,
     177,   346,   598,    65,   124,   125,    50,    11,   106,    13,
      14,   177,   510,   119,    42,    53,   268,    98,    97,    98,
     375,   133,    49,    19,    52,    52,   392,   108,   140,   108,
      57,   102,   111,   106,    52,   124,   125,   119,   120,   121,
     127,   127,   127,    23,   127,    39,    49,    31,    32,    52,
      39,   406,   133,   120,   135,    54,   135,   138,   139,   140,
     139,   619,   454,    20,    21,   301,    40,    49,   549,   550,
      52,    98,    39,   101,   155,    45,   155,   456,   457,   311,
     301,   108,   119,   164,    40,   164,    45,    40,   169,    91,
     311,   119,   120,   121,    42,    98,   177,    39,   177,    42,
     127,   119,   120,   121,    28,   108,   133,    33,   135,    52,
      54,   138,   139,   140,   141,    92,    98,    27,    76,    52,
      42,    42,   498,    66,    42,   206,   108,    42,   155,    42,
      52,    42,   135,    52,   215,    42,   139,   164,   315,   375,
      42,   377,   169,   641,    66,    52,    42,   174,    42,   315,
     177,    42,   155,   135,   375,   462,   463,   139,   101,    66,
     392,   164,   115,   116,   117,   118,    42,    42,   101,    42,
     406,   392,    42,   155,   177,    42,   119,   120,   121,   206,
      42,    42,   164,    42,    28,   406,   119,   120,   121,    40,
     217,   216,    45,    51,   101,   177,    50,   119,   120,   121,
     119,   120,   121,    42,   285,   124,   125,   115,   116,   117,
     118,    42,   119,   120,   121,    42,    90,   124,   125,    20,
     301,    43,    63,    64,   334,   335,   336,   337,   338,   339,
     311,    31,   311,    32,   315,   106,   315,   318,   319,   320,
     106,   322,   494,   322,   269,   270,   271,   499,   329,   274,
      41,    43,   277,   278,   279,    68,   281,   282,   283,   284,
      55,   286,   287,   288,   289,   290,   291,   292,   109,   110,
     111,   112,   113,   114,   301,    57,    58,    59,    60,    61,
      62,   119,   120,   121,   311,    67,    68,    56,   315,    43,
      43,   318,   319,   320,   375,   322,   119,   120,   121,    43,
     552,   124,   125,   238,   239,   240,    43,    50,   311,    50,
      50,   392,   315,   392,    43,    50,    43,    43,    50,   322,
      43,   498,    43,    43,    43,    50,    43,    42,   103,   311,
      43,    45,   498,   315,    65,    43,   588,    43,    50,    43,
     322,    43,    43,    43,    43,   370,    43,    50,   375,     3,
       4,     5,     6,     7,     8,     9,    10,   438,    12,   438,
     106,    51,    43,   615,   389,   392,    48,   103,    51,    40,
      77,    43,    40,    43,    51,   489,   392,    57,   141,   406,
     312,   633,   401,   217,   375,   206,   491,   307,   608,   392,
     306,   541,   419,   542,   421,   422,   135,   322,   267,   621,
     563,   318,   419,   565,   444,   446,   320,   422,   344,   458,
     392,   438,   639,   344,    -1,   440,   441,   498,    -1,   498,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   510,
      -1,   510,    -1,    -1,    -1,   438,    -1,    -1,    -1,    -1,
     465,    -1,    -1,    -1,    -1,   470,   471,   472,    -1,    -1,
     475,    -1,    -1,   478,    -1,    -1,   438,    -1,   483,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   549,   550,
      -1,   498,    -1,    -1,   501,    -1,   503,    -1,    -1,    -1,
      -1,    -1,    -1,   510,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   498,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,   585,    -1,   585,   510,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   498,    -1,    -1,    -1,
      -1,    -1,   549,   550,    -1,    -1,    -1,   608,   510,   608,
      -1,    -1,    -1,    -1,    -1,    -1,   563,    -1,   565,    -1,
     621,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     575,    -1,   577,    -1,    -1,    -1,    -1,    -1,   585,    -1,
     641,    -1,   641,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   608,   585,   124,   125,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   619,    -1,   621,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   585,    22,   608,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   641,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,   608,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   641,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,   641,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    -1,    -1,    -1,    -1,    93,    94,    95,    96,    97,
      98,    99,   100,    -1,    22,    -1,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    42,    -1,   124,   125,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    42,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    53,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    -1,    -1,    -1,    -1,    93,    94,    95,    96,    97,
      98,    99,   100,    -1,    -1,    -1,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    -1,    -1,   124,   125,    -1,    -1,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    -1,   127,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    42,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    53,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    43,    -1,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,   120,   121,    -1,    -1,   124,
     125,    -1,    -1,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    44,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    -1,   127,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,    -1,   124,   125,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      42,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    -1,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    -1,    -1,
      -1,    93,    94,    95,    96,    97,    98,    99,   100,    42,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,   124,   125,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    -1,    -1,    -1,
      93,    94,    95,    96,    97,    98,    99,   100,    42,    -1,
      -1,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,   124,   125,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    98,    99,   100,    42,    -1,    -1,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    -1,    -1,
     124,   125,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   100,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,   120,   121,    -1,    -1,   124,
     125,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,   120,   121,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,   127,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
      -1,    -1,    -1,   127
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  MapSetParser::yystos_[] =
  {
         0,   129,   130,     0,    18,   145,   146,   148,   119,   131,
     147,     3,     4,     5,     6,     7,     8,     9,    10,    12,
     132,   133,    19,   149,   124,   125,   317,   115,   116,   117,
     118,   356,   365,   356,   356,   356,   119,   120,   121,   366,
     367,    53,   138,   139,   144,    11,    13,    14,   134,    39,
     136,   137,    15,   164,   165,   150,   356,    89,   126,   357,
     358,   359,   356,    39,   140,   141,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   122,   123,   127,
     135,   318,   356,   360,   361,   362,   363,   364,   366,   368,
     136,   318,    23,   120,   356,   366,    54,   143,    40,    39,
     245,   151,    40,   142,   356,   315,   317,   318,   246,   152,
     119,    45,    34,    35,    36,    37,    38,    53,   247,   248,
     251,   307,   308,   310,   311,   312,   315,    25,    41,   166,
     171,   172,   356,   309,    40,    45,   249,   250,   253,    42,
     252,    26,   167,   168,   169,   170,   366,    91,   173,   174,
     178,    39,   206,    52,   254,   265,   316,   317,   366,   247,
     254,   259,   260,   307,   313,   314,   315,   254,   170,    28,
      33,   195,   201,   203,    92,   175,   181,   207,    54,   261,
     264,   314,    43,   314,    42,    67,    69,    70,    71,    72,
      73,    74,    75,    76,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,   100,   179,   180,   237,   317,
     342,   344,   346,   347,   366,   196,    42,   182,   183,   236,
     237,   341,   342,    27,   176,   184,    24,   153,   155,   208,
     209,   210,   213,   266,   307,   315,   258,   263,    63,    64,
      66,    93,    94,    95,    96,    97,    98,    99,   317,   319,
     320,   323,   326,   327,   330,   331,   337,   339,   340,   341,
     342,   348,   351,   354,   356,   360,   364,   366,    76,    42,
      42,    42,   127,   343,    42,   127,   243,    42,    42,    42,
     206,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,   180,    42,   127,   238,    39,   317,   319,
     183,    28,    31,    32,   177,   190,   193,   194,    20,    21,
     156,   157,   154,    40,   212,    45,   214,   215,   268,   267,
      51,   257,    50,   262,   340,   340,   340,    42,    42,    90,
     158,   159,   322,   325,    57,    58,    59,    60,    61,    62,
      67,    68,   328,   329,   336,   338,    42,   238,   355,   206,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   317,   319,   319,   319,   319,   319,   319,   319,    20,
     240,   202,    43,    29,    30,   185,   186,   187,   188,   189,
     236,   317,   106,   106,   191,   194,   192,   193,    22,    42,
     160,   161,   162,   163,   237,   317,   342,   348,   356,   360,
     364,   171,    16,    17,    46,    47,    49,   211,   216,   217,
     219,   223,   226,   229,   230,   235,   210,   260,   277,    42,
      52,    66,   101,   269,   271,   278,   279,   280,   281,   284,
     287,   289,   295,   296,   317,   366,   255,   256,   265,   264,
     240,   240,   317,    43,    55,   321,    56,   324,   330,   330,
     330,   330,   330,   330,    68,   243,    63,    64,   332,   335,
     362,   363,    22,    65,   333,   240,    43,    43,    43,   244,
      50,    50,    50,    43,    43,    50,    43,    43,    50,    43,
      43,    43,    43,    50,    43,   319,   200,   186,   341,   319,
     161,   173,   220,   224,   218,   227,   236,    45,   205,   231,
     280,    42,    52,   101,   297,   302,   303,   305,   366,   287,
     270,   283,   286,    22,    39,    63,   102,   288,   290,   294,
     261,    22,   319,   350,   319,   323,   326,   243,   337,   337,
     333,   334,   339,   339,   319,   242,   319,   319,   319,   319,
     319,   319,   239,    40,    42,   127,   198,   159,   195,   221,
     225,   206,   228,   210,   206,    43,   300,   301,   303,    52,
     304,   366,   261,   103,   282,    65,   285,    50,   106,   293,
     306,    43,   349,    43,    43,    50,   241,    50,    43,    43,
      43,    43,   241,   345,   242,   199,    43,   316,   316,   206,
     234,    43,   299,   276,   284,   289,   306,    40,    50,   292,
      51,   352,   353,   319,   319,    43,    43,    44,   197,   204,
     317,   356,   360,   364,   366,   222,   206,    48,   232,   103,
     298,    51,   275,    40,    40,   291,   306,    77,    43,    43,
      43,   204,   206,   233,   303,   271,   272,   274,    40,    57,
     206,   273,   365,   261
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
     375,   376,   377,   378,   379,   380,   381,   382
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  MapSetParser::yyr1_[] =
  {
         0,   128,   130,   129,   131,   131,   132,   132,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   134,   134,   134,
     135,   135,   136,   137,   137,   138,   139,   139,   140,   140,
     141,   142,   143,   143,   144,   145,   146,   146,   147,   147,
     148,   150,   151,   149,   152,   152,   154,   153,   155,   156,
     156,   157,   157,   158,   159,   159,   160,   161,   161,   161,
     161,   161,   161,   161,   161,   162,   162,   163,   163,   164,
     164,   165,   166,   167,   167,   168,   169,   170,   171,   172,
     172,   173,   174,   174,   175,   175,   176,   176,   177,   177,
     178,   179,   179,   180,   180,   180,   180,   181,   182,   182,
     183,   184,   185,   185,   186,   186,   187,   187,   188,   189,
     189,   190,   190,   191,   191,   192,   192,   193,   194,   195,
     196,   196,   197,   197,   199,   198,   198,   200,   200,   202,
     201,   203,   203,   204,   204,   204,   204,   204,   204,   205,
     205,   207,   206,   208,   208,   209,   210,   210,   211,   212,
     212,   213,   214,   215,   215,   216,   216,   216,   216,   216,
     216,   218,   217,   220,   221,   222,   219,   224,   225,   223,
     227,   228,   226,   230,   231,   229,   233,   232,   234,   234,
     235,   236,   236,   236,   237,   238,   239,   238,   240,   240,
     241,   242,   242,   243,   244,   243,   246,   245,   247,   247,
     248,   249,   250,   250,   252,   251,   253,   251,   254,   255,
     256,   256,   257,   258,   258,   259,   260,   260,   261,   262,
     263,   263,   264,   265,   265,   267,   266,   268,   266,   270,
     269,   271,   271,   273,   272,   274,   274,   275,   276,   276,
     277,   278,   279,   280,   281,   282,   283,   283,   284,   285,
     286,   286,   287,   288,   288,   289,   289,   290,   291,   291,
     292,   292,   293,   293,   294,   294,   294,   294,   295,   296,
     296,   296,   296,   297,   298,   299,   299,   300,   301,   301,
     302,   302,   303,   304,   304,   305,   305,   305,   306,   307,
     307,   309,   308,   310,   311,   311,   311,   311,   311,   312,
     312,   313,   313,   314,   314,   315,   315,   316,   316,   317,
     317,   318,   318,   318,   318,   318,   318,   319,   320,   321,
     322,   322,   323,   324,   325,   325,   326,   327,   328,   328,
     329,   329,   329,   329,   329,   329,   329,   329,   330,   331,
     332,   332,   333,   333,   334,   334,   335,   335,   335,   336,
     336,   337,   338,   338,   339,   339,   339,   339,   340,   340,
     340,   340,   340,   340,   340,   340,   341,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   343,   343,
     344,   345,   345,   346,   347,   348,   348,   349,   348,   350,
     350,   351,   351,   351,   351,   351,   352,   353,   353,   354,
     355,   355,   356,   357,   358,   358,   359,   359,   360,   360,
     360,   361,   361,   361,   362,   362,   362,   363,   363,   363,
     364,   364,   365,   365,   365,   365,   366,   366,   367,   367,
     368,   368
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
       1,     1,     1,     1,     1,     1,     2,     1,     1,     0,
       2,     7,     2,     1,     1,     1,     2,     1,     2,     0,
       1,     4,     0,     1,     0,     1,     0,     1,     0,     1,
       3,     1,     2,     1,     1,     4,     1,     2,     1,     2,
       1,     3,     1,     2,     1,     1,     1,     1,     2,     1,
       1,     2,     2,     0,     1,     0,     1,     2,     2,     1,
       0,     2,     1,     2,     0,     4,     1,     0,     2,     0,
       6,     0,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     0,     4,     1,     1,     2,     0,     1,     3,     0,
       2,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     0,     3,     0,     0,     0,     6,     0,     0,     5,
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
       4,     4,     4,     4,     2,     2,     8,     6,     6,     6,
       4,     4,     4,     4,     4,     1,     1,     1,     3,     1,
       7,     0,     1,     2,     3,     5,     5,     0,     7,     1,
       1,     1,     1,     1,     1,     1,     4,     0,     1,     2,
       0,     1,     2,     2,     1,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
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
  "IT_VARNAMES", "IT_LABEL", "IT_GRAPH", "IT_SERVICE", "IT_BASE",
  "IT_PREFIX", "IT_DISTINCT", "IT_REDUCED", "GT_TIMES", "IT_CONSTRUCT",
  "IT_SELECT", "IT_FROM", "IT_NAMED", "IT_ORDER", "IT_BY", "IT_ASC",
  "IT_DESC", "IT_LIMIT", "IT_OFFSET", "IT_BINDINGS", "IT_MEMBERS",
  "IT_STARTS", "IT_ENDS", "IT_ANY", "IT_UNORDERED", "GT_LCURLEY",
  "GT_RCURLEY", "IT_WHERE", "GT_LPAREN", "GT_RPAREN", "IT_UNDEF", "GT_DOT",
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
       129,     0,    -1,    -1,   130,   145,   131,   132,    -1,    -1,
     131,   133,    -1,    -1,   132,   165,    -1,     3,   317,   356,
     356,    -1,     4,   356,    -1,     5,   356,    -1,     6,   356,
      -1,     7,   356,    -1,     8,   366,    -1,     9,   138,    -1,
      10,   134,    -1,    12,   137,    -1,    11,    -1,    14,    -1,
      13,    -1,    -1,   318,    -1,    39,   135,    40,   315,    -1,
     136,    -1,   137,   136,    -1,   139,   140,    -1,    -1,   144,
      -1,    -1,   141,    -1,    39,   143,    40,    -1,   356,    45,
     356,    -1,    -1,   143,   142,    -1,    53,   356,    54,    -1,
     146,   147,    -1,    -1,   148,    -1,    -1,   147,   149,    -1,
      18,   119,    -1,    -1,    -1,    19,   150,   120,   151,   119,
      -1,    -1,   152,   166,    -1,    -1,   155,   154,   171,   173,
     195,    -1,    24,   157,   163,    -1,    20,    -1,    21,    -1,
      -1,   156,    -1,    90,   317,    -1,    -1,   158,    -1,    42,
     319,   159,    43,    -1,   317,    -1,   348,    -1,   342,    -1,
     237,    -1,   356,    -1,   360,    -1,   364,    -1,   160,    -1,
     161,    -1,   162,   161,    -1,   162,    -1,    22,    -1,    -1,
      15,   318,    -1,   164,    23,   245,   152,   171,   173,   195,
      -1,    25,   167,    -1,   168,    -1,   169,    -1,   170,    -1,
      26,   170,    -1,   366,    -1,   172,   206,    -1,    -1,    41,
      -1,   174,   175,   176,   177,    -1,    -1,   178,    -1,    -1,
     181,    -1,    -1,   184,    -1,    -1,   190,    -1,    91,    28,
     179,    -1,   180,    -1,   179,   180,    -1,   342,    -1,   237,
      -1,    42,   319,   159,    43,    -1,   317,    -1,    92,   182,
      -1,   183,    -1,   182,   183,    -1,   236,    -1,    27,    28,
     185,    -1,   186,    -1,   185,   186,    -1,   188,    -1,   189,
      -1,    29,    -1,    30,    -1,   187,   341,    -1,   236,    -1,
     317,    -1,   193,   191,    -1,   194,   192,    -1,    -1,   194,
      -1,    -1,   193,    -1,    31,   106,    -1,    32,   106,    -1,
     203,    -1,    -1,   196,   317,    -1,   204,    -1,   197,   204,
      -1,    -1,    42,   199,   197,    43,    -1,   127,    -1,    -1,
     200,   198,    -1,    -1,    33,   196,    39,   202,   200,    40,
      -1,    -1,   201,    -1,   366,    -1,   356,    -1,   360,    -1,
     364,    -1,    44,    -1,   317,    -1,    -1,    45,    -1,    -1,
      39,   207,   208,    40,    -1,   153,    -1,   209,    -1,   210,
     212,    -1,    -1,   213,    -1,   216,   205,   210,    -1,    -1,
     212,   211,    -1,   266,   215,    -1,    45,   210,    -1,    -1,
     214,    -1,   229,    -1,   217,    -1,   226,    -1,   219,    -1,
     223,    -1,   235,    -1,    -1,    46,   218,   206,    -1,    -1,
      -1,    -1,    16,   220,   221,   316,   222,   206,    -1,    -1,
      -1,    17,   224,   225,   316,   206,    -1,    -1,    -1,    47,
     227,   228,   206,    -1,    -1,    -1,   230,   231,   206,   234,
      -1,    -1,    48,   233,   206,    -1,    -1,   234,   232,    -1,
      49,   236,    -1,   341,    -1,   342,    -1,   237,    -1,   366,
     238,    -1,   127,    -1,    -1,    42,   240,   319,   239,   242,
      43,    -1,    -1,    20,    -1,    50,   319,    -1,    -1,   242,
     241,    -1,   127,    -1,    -1,    42,   319,   244,   242,    43,
      -1,    -1,    39,   246,   247,    40,    -1,    -1,   248,    -1,
     251,   250,    -1,    45,   247,    -1,    -1,   249,    -1,    -1,
     315,   252,   254,    -1,    -1,   307,   253,   259,    -1,   265,
     261,   258,    -1,   265,   261,    -1,    -1,   255,    -1,    51,
     256,    -1,    -1,   258,   257,    -1,   260,    -1,    -1,   254,
      -1,   264,   263,    -1,    50,   264,    -1,    -1,   263,   262,
      -1,   314,    -1,   316,    -1,    52,    -1,    -1,   315,   267,
     269,    -1,    -1,   307,   268,   277,    -1,    -1,   271,   270,
     261,   276,    -1,   278,    -1,   279,    -1,    -1,   271,   273,
     261,    -1,    -1,   272,    -1,    51,   274,    -1,    -1,   276,
     275,    -1,   260,    -1,   280,    -1,   317,    -1,   281,    -1,
     284,   283,    -1,   103,   284,    -1,    -1,   283,   282,    -1,
     289,   286,    -1,    65,   289,    -1,    -1,   286,   285,    -1,
     295,   288,    -1,    -1,   290,    -1,   287,    -1,   101,   287,
      -1,   294,    -1,    40,    -1,   306,    40,    -1,    50,   291,
      -1,    40,    -1,   306,   292,    -1,    50,   306,    40,    -1,
      22,    -1,   102,    -1,    63,    -1,    39,   293,    -1,   296,
      -1,   366,    -1,    52,    -1,    66,   297,    -1,    42,   280,
      43,    -1,   302,    -1,   103,   303,    -1,    -1,   299,   298,
      -1,   303,   299,    -1,    -1,   300,    -1,   303,    -1,    42,
     301,    43,    -1,   305,    -1,   366,    -1,    52,    -1,   366,
      -1,    52,    -1,   101,   304,    -1,   106,    -1,   310,    -1,
     308,    -1,    -1,    53,   309,   254,    54,    -1,   312,    42,
     313,    43,    -1,    34,    -1,    35,    -1,    36,    -1,    37,
      -1,    38,    -1,    -1,   311,    -1,   314,    -1,   313,   314,
      -1,   315,    -1,   307,    -1,   317,    -1,   318,    -1,   317,
      -1,   366,    -1,   124,    -1,   125,    -1,   366,    -1,   356,
      -1,   360,    -1,   364,    -1,   368,    -1,   127,    -1,   320,
      -1,   323,   322,    -1,    55,   323,    -1,    -1,   322,   321,
      -1,   326,   325,    -1,    56,   326,    -1,    -1,   325,   324,
      -1,   327,    -1,   330,   328,    -1,    -1,   329,    -1,    57,
     330,    -1,    58,   330,    -1,    59,   330,    -1,    60,   330,
      -1,    61,   330,    -1,    62,   330,    -1,    68,   243,    -1,
      67,    68,   243,    -1,   331,    -1,   337,   336,    -1,   362,
      -1,   363,    -1,    22,   339,    -1,    65,   339,    -1,    -1,
     333,    -1,    63,   337,    -1,    64,   337,    -1,   332,   334,
      -1,    -1,   336,   335,    -1,   339,   338,    -1,    -1,   338,
     333,    -1,    66,   340,    -1,    63,   340,    -1,    64,   340,
      -1,   340,    -1,   341,    -1,   342,    -1,   354,    -1,   356,
      -1,   360,    -1,   364,    -1,   317,    -1,   348,    -1,    42,
     319,    43,    -1,    78,    42,   319,    43,    -1,    79,    42,
     319,    43,    -1,    80,    42,   319,    50,   319,    43,    -1,
      81,    42,   319,    43,    -1,    82,    42,   317,    43,    -1,
      69,    42,   319,    43,    -1,    70,    42,   319,    43,    -1,
      71,   343,    -1,    72,   243,    -1,    73,    42,   319,    50,
     319,    50,   319,    43,    -1,    74,    42,   319,    50,   319,
      43,    -1,    75,    42,   319,    50,   319,    43,    -1,    83,
      42,   319,    50,   319,    43,    -1,    84,    42,   319,    43,
      -1,    85,    42,   319,    43,    -1,    86,    42,   319,    43,
      -1,    87,    42,   319,    43,    -1,   100,    42,   319,    43,
      -1,   344,    -1,   346,    -1,   347,    -1,    42,   319,    43,
      -1,   127,    -1,    88,    42,   319,    50,   319,   345,    43,
      -1,    -1,   241,    -1,    76,   206,    -1,    67,    76,   206,
      -1,    93,    42,   240,   350,    43,    -1,   351,    42,   240,
     319,    43,    -1,    -1,    98,    42,   240,   319,   349,   353,
      43,    -1,    22,    -1,   319,    -1,    94,    -1,    95,    -1,
      96,    -1,    97,    -1,    99,    -1,    51,    77,    57,   365,
      -1,    -1,   352,    -1,   366,   355,    -1,    -1,   238,    -1,
     365,   359,    -1,    89,   366,    -1,   126,    -1,   357,    -1,
      -1,   358,    -1,   361,    -1,   362,    -1,   363,    -1,   106,
      -1,   107,    -1,   108,    -1,   109,    -1,   110,    -1,   111,
      -1,   112,    -1,   113,    -1,   114,    -1,   104,    -1,   105,
      -1,   115,    -1,   117,    -1,   116,    -1,   118,    -1,   119,
      -1,   367,    -1,   121,    -1,   120,    -1,   122,    -1,   123,
      -1
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
     170,   173,   181,   184,   186,   188,   190,   193,   195,   198,
     199,   201,   206,   207,   209,   210,   212,   213,   215,   216,
     218,   222,   224,   227,   229,   231,   236,   238,   241,   243,
     246,   248,   252,   254,   257,   259,   261,   263,   265,   268,
     270,   272,   275,   278,   279,   281,   282,   284,   287,   290,
     292,   293,   296,   298,   301,   302,   307,   309,   310,   313,
     314,   321,   322,   324,   326,   328,   330,   332,   334,   336,
     337,   339,   340,   345,   347,   349,   352,   353,   355,   359,
     360,   363,   366,   369,   370,   372,   374,   376,   378,   380,
     382,   384,   385,   389,   390,   391,   392,   399,   400,   401,
     407,   408,   409,   414,   415,   416,   421,   422,   426,   427,
     430,   433,   435,   437,   439,   442,   444,   445,   452,   453,
     455,   458,   459,   462,   464,   465,   471,   472,   477,   478,
     480,   483,   486,   487,   489,   490,   494,   495,   499,   503,
     506,   507,   509,   512,   513,   516,   518,   519,   521,   524,
     527,   528,   531,   533,   535,   537,   538,   542,   543,   547,
     548,   553,   555,   557,   558,   562,   563,   565,   568,   569,
     572,   574,   576,   578,   580,   583,   586,   587,   590,   593,
     596,   597,   600,   603,   604,   606,   608,   611,   613,   615,
     618,   621,   623,   626,   630,   632,   634,   636,   639,   641,
     643,   645,   648,   652,   654,   657,   658,   661,   664,   665,
     667,   669,   673,   675,   677,   679,   681,   683,   686,   688,
     690,   692,   693,   698,   703,   705,   707,   709,   711,   713,
     714,   716,   718,   721,   723,   725,   727,   729,   731,   733,
     735,   737,   739,   741,   743,   745,   747,   749,   751,   754,
     757,   758,   761,   764,   767,   768,   771,   773,   776,   777,
     779,   782,   785,   788,   791,   794,   797,   800,   804,   806,
     809,   811,   813,   816,   819,   820,   822,   825,   828,   831,
     832,   835,   838,   839,   842,   845,   848,   851,   853,   855,
     857,   859,   861,   863,   865,   867,   869,   873,   878,   883,
     890,   895,   900,   905,   910,   913,   916,   925,   932,   939,
     946,   951,   956,   961,   966,   971,   973,   975,   977,   981,
     983,   991,   992,   994,   997,  1001,  1007,  1013,  1014,  1022,
    1024,  1026,  1028,  1030,  1032,  1034,  1036,  1041,  1042,  1044,
    1047,  1048,  1050,  1053,  1056,  1058,  1060,  1061,  1063,  1065,
    1067,  1069,  1071,  1073,  1075,  1077,  1079,  1081,  1083,  1085,
    1087,  1089,  1091,  1093,  1095,  1097,  1099,  1101,  1103,  1105,
    1107,  1109
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
     626,   629,   632,   635,   639,   644,   647,   655,   658,   664,
     667,   674,   684,   691,   692,   696,   702,   708,   715,   722,
     724,   729,   736,   739,   744,   747,   752,   755,   760,   764,
     768,   775,   778,   785,   788,   791,   794,   800,   806,   809,
     816,   821,   828,   832,   840,   842,   850,   853,   861,   869,
     870,   877,   881,   889,   892,   897,   900,   904,   910,   918,
     923,   926,   933,   936,   942,   942,   948,   954,   957,   964,
     964,   973,   976,   980,   983,   986,   989,   992,   995,  1001,
    1003,  1008,  1008,  1020,  1021,  1026,  1030,  1032,  1042,  1046,
    1049,  1065,  1070,  1074,  1077,  1081,  1082,  1083,  1084,  1085,
    1086,  1090,  1090,  1105,  1108,  1110,  1105,  1121,  1124,  1121,
    1133,  1136,  1133,  1146,  1149,  1146,  1159,  1159,  1173,  1175,
    1179,  1190,  1191,  1192,  1196,  1204,  1208,  1208,  1217,  1220,
    1227,  1233,  1235,  1249,  1252,  1252,  1262,  1262,  1270,  1272,
    1277,  1282,  1286,  1288,  1292,  1292,  1295,  1295,  1302,  1307,
    1311,  1313,  1318,  1322,  1324,  1329,  1333,  1335,  1340,  1345,
    1349,  1351,  1355,  1362,  1366,  1374,  1374,  1377,  1377,  1383,
    1383,  1389,  1390,  1394,  1394,  1399,  1401,  1405,  1408,  1410,
    1414,  1418,  1422,  1428,  1432,  1436,  1439,  1441,  1445,  1449,
    1454,  1456,  1462,  1465,  1467,  1473,  1474,  1480,  1484,  1485,
    1489,  1490,  1494,  1495,  1499,  1500,  1501,  1502,  1506,  1510,
    1513,  1516,  1519,  1525,  1529,  1532,  1534,  1538,  1541,  1543,
    1547,  1548,  1552,  1556,  1557,  1561,  1562,  1563,  1567,  1572,
    1573,  1577,  1577,  1590,  1615,  1618,  1621,  1624,  1627,  1634,
    1637,  1642,  1646,  1653,  1654,  1658,  1661,  1665,  1668,  1674,
    1675,  1679,  1682,  1685,  1688,  1691,  1692,  1698,  1703,  1712,
    1719,  1722,  1730,  1739,  1746,  1749,  1756,  1761,  1772,  1775,
    1779,  1782,  1785,  1788,  1791,  1794,  1797,  1800,  1806,  1811,
    1820,  1823,  1830,  1833,  1840,  1843,  1848,  1851,  1855,  1869,
    1872,  1880,  1889,  1892,  1899,  1902,  1905,  1908,  1912,  1913,
    1914,  1915,  1918,  1921,  1924,  1927,  1931,  1937,  1940,  1943,
    1946,  1949,  1952,  1955,  1959,  1962,  1966,  1969,  1972,  1975,
    1978,  1981,  1984,  1987,  1990,  1993,  1994,  1995,  2001,  2004,
    2011,  2018,  2021,  2025,  2032,  2039,  2042,  2046,  2046,  2058,
    2062,  2066,  2069,  2072,  2075,  2078,  2084,  2090,  2093,  2097,
    2107,  2110,  2115,  2123,  2130,  2134,  2142,  2146,  2150,  2151,
    2152,  2156,  2157,  2158,  2162,  2163,  2164,  2168,  2169,  2170,
    2174,  2175,  2179,  2180,  2181,  2182,  2186,  2187,  2191,  2192,
    2196,  2197
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
     125,   126,   127
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int MapSetParser::yyeof_ = 0;
  const int MapSetParser::yylast_ = 1493;
  const int MapSetParser::yynnts_ = 241;
  const int MapSetParser::yyempty_ = -2;
  const int MapSetParser::yyfinal_ = 3;
  const int MapSetParser::yyterror_ = 1;
  const int MapSetParser::yyerrcode_ = 256;
  const int MapSetParser::yyntokens_ = 128;

  const unsigned int MapSetParser::yyuser_token_number_max_ = 382;
  const MapSetParser::token_number_type MapSetParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 4227 "lib/MapSetParser/MapSetParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 2203 "lib/MapSetParser/MapSetParser.ypp"
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


