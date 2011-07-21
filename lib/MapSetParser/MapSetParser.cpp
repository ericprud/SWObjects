
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
#line 300 "lib/MapSetParser/MapSetParser.ypp"

#include "../MapSetScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 439 "lib/MapSetParser/MapSetParser.ypp"

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
#line 454 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root = new MapSet();
	driver.root->sharedVars = MapSet::e_PROMISCUOUS;
      }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 472 "lib/MapSetParser/MapSetParser.ypp"
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
#line 481 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->driver = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 484 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->server = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 487 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->user = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 490 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->password = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 493 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->database = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 496 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->stemURI = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 501 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.sharedVarsSet = true;
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 505 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.lastRuleTermSet = false;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 511 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_PROMISCUOUS;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 514 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_VARNAMES;
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 517 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_DRACONIAN;
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 523 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = NULL;
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 530 "lib/MapSetParser/MapSetParser.ypp"
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
#line 565 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->keyMap[(yysemantic_stack_[(3) - (1)].p_RDFLiteral)->getLexicalValue()] = (yysemantic_stack_[(3) - (3)].p_RDFLiteral)->getLexicalValue();
    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 576 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->primaryKey = (yysemantic_stack_[(3) - (2)].p_RDFLiteral);
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 599 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 605 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 607 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 609 "lib/MapSetParser/MapSetParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 617 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 621 "lib/MapSetParser/MapSetParser.ypp"
    {
	  if ((yysemantic_stack_[(5) - (5)].p_BindingClause) != NULL)
	      (yysemantic_stack_[(5) - (3)].p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yysemantic_stack_[(5) - (5)].p_BindingClause), (yysemantic_stack_[(5) - (3)].p_WhereClause)->m_GroupGraphPattern);
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(5) - (1)].p_Project).distinctness, (yysemantic_stack_[(5) - (1)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(5) - (3)].p_WhereClause), (yysemantic_stack_[(5) - (4)].p_SolutionModifier))));
      }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 629 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 637 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 645 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 648 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 655 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 663 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 670 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 678 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 685 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 688 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 691 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 694 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 697 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 700 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 703 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 712 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 715 "lib/MapSetParser/MapSetParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 723 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 726 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 733 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = NULL;
      }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 735 "lib/MapSetParser/MapSetParser.ypp"
    {
	/* $3 is known to be a DefaultGraphPattern because of grammar restrictions. */
	if ((yysemantic_stack_[(8) - (8)].p_BindingClause) != NULL)
	    (yysemantic_stack_[(8) - (6)].p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yysemantic_stack_[(8) - (8)].p_BindingClause), (yysemantic_stack_[(8) - (6)].p_WhereClause)->m_GroupGraphPattern);
	Construct* constr = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(8) - (3)].p_BasicGraphPattern), (yysemantic_stack_[(8) - (5)].p_DatasetClauses), (yysemantic_stack_[(8) - (6)].p_WhereClause), (yysemantic_stack_[(8) - (7)].p_SolutionModifier));
	driver.root->maps.push_back(LabeledConstruct((yysemantic_stack_[(8) - (1)].p_TTerm), constr));
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 745 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (2)].p_TTerm);
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 751 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = NULL;
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 759 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 762 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 770 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 782 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 788 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 794 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 801 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp ? driver.curOp : new DefaultGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 815 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 822 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 830 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 838 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 846 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 854 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 861 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 864 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 871 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 874 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 877 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 880 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 886 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 892 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 895 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 907 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 914 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 918 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 928 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 936 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 939 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 947 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 956 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 963 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 967 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 975 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 983 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 990 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 996 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1003 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1005 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1013 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1019 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1022 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1028 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.startBindingRow(); // @@ push down to _Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star?
      }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1030 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1033 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1045 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1048 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1051 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1054 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1057 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1060 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1063 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1070 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1072 "lib/MapSetParser/MapSetParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1154 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_BindingClause)) : (yysemantic_stack_[(1) - (1)].p_BindingClause);
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1160 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1164 "lib/MapSetParser/MapSetParser.ypp"
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

  case 168:

/* Line 678 of lalr1.cc  */
#line 1176 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1180 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1182 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 1185 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 1193 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 1197 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1199 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(5) - (4)].p_TTerm), driver.curOp, driver.atomFactory, false));
      }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 1206 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = new Bind(driver.curOp, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
    }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 1212 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 1216 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 1218 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.curOp));
      }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 1226 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 1230 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 1232 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 1240 "lib/MapSetParser/MapSetParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 1246 "lib/MapSetParser/MapSetParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 1261 "lib/MapSetParser/MapSetParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    if (driver.curOp == NULL)
		driver.ensureBasicGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 1278 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 1286 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 1290 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 1292 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = NULL;
      }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 1299 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1302 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1309 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1317 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 1331 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 1334 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 1336 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 1344 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 1346 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 1374 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 1377 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 1437 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 1444 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 1448 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 1456 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 1459 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 1465 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 1476 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 1504 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 1531 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 1538 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 1549 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 1556 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 1592 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 1595 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 1598 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 1601 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 1659 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 1663 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 1672 "lib/MapSetParser/MapSetParser.ypp"
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

  case 300:

/* Line 678 of lalr1.cc  */
#line 1697 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 1700 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 1703 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 1706 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 1709 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 1716 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 1724 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 1728 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 1740 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 1747 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 1750 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 1761 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 1764 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 1767 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 1770 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 1774 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 1785 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 1794 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 1801 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 1804 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 1812 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 1821 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 1828 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 1831 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 1843 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_GeneralComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_GeneralComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_GeneralComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 1854 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 1861 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 1864 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 1867 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 1870 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 1873 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 1876 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 1879 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 1882 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 1893 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 1902 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 1905 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 1912 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 1915 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 1922 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 1930 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 1933 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 1937 "lib/MapSetParser/MapSetParser.ypp"
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

  case 355:

/* Line 678 of lalr1.cc  */
#line 1951 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 1954 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 1962 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 1971 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 1974 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 1981 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 1984 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 1987 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 1997 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 2000 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 2003 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 2006 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 2013 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 2019 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 2022 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 2025 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 2028 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 2031 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 2034 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 2037 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 2041 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_blank, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 2044 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 2047 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 2050 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ciel, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 2053 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 2056 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 2059 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::XPATH_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 2063 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlen, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 2066 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ucase, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 2069 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lcase, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 2072 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encodeForUri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 2075 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 2078 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strStarts, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 2081 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strEnds, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 2084 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 2087 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 2090 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 2093 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 2096 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 2099 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 2102 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 2105 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 2108 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 2111 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 2114 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha224, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 2117 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 2120 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 2123 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 2126 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 2130 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 2133 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 2136 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 2139 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 2142 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 2145 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 2148 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 2151 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 2154 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 2165 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 2168 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 2175 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_regex, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 2182 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 2189 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 2195 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 2202 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 2209 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 2212 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 2216 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 2218 "lib/MapSetParser/MapSetParser.ypp"
    {
	  // x = new ArgList($2, driver.curExprList);
	  delete driver.curExprList;
	  driver.curExprList = NULL;
	  w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // $$ = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group-concat, $3, $4.p_Expression, $4.separator));
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 2228 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
	driver.countStar = true;
    }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 2236 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 2239 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 2242 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 2245 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 2248 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 2254 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 2260 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 2267 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 2277 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 2285 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 2293 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 2300 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 2304 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 2312 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 3100 "lib/MapSetParser/MapSetParser.cpp"
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
  const short int MapSetParser::yypact_ninf_ = -660;
  const short int
  MapSetParser::yypact_[] =
  {
      -660,    64,    59,  -660,   -73,  -660,  -660,  -660,  -660,   351,
      73,   -49,   132,   132,   132,   132,   132,  -105,    44,    53,
      57,    30,  -660,  -660,  -660,  -660,  -660,   132,  -660,  -660,
    -660,  -660,  -660,   -62,  -660,  -660,  -660,  -660,  -660,  -660,
    -660,  -660,  -660,   132,  -660,    63,  -660,  -660,  -660,  -660,
    -660,   523,  -660,    57,   523,  -660,  -660,    85,   -51,   132,
    -105,  -660,  -660,  -660,  -660,    66,  -660,  -660,  -660,  -660,
    -660,  -660,  -660,  -660,  -660,  -660,  -660,  -660,  -660,  -660,
    -660,  -660,  -660,    79,  -660,  -660,  -660,  -660,  -660,  -660,
    -660,  -660,  -660,  -660,  -660,    91,  -660,  -660,  -660,  -660,
      60,  1261,  -660,  -660,   -26,  -660,  -660,   122,  -660,  -660,
    -660,  1192,  -660,  -660,   132,  -660,  -660,  -660,  -660,  -660,
    -660,   109,  -660,   129,  -660,  -660,  -660,  -660,   123,  -660,
      11,  -660,    19,  -660,  1192,  -660,  -660,    19,  1237,    19,
     -10,  -660,  -660,    84,   150,  -660,   137,  1237,  -660,  -660,
    -660,  -660,  -660,  -660,  -660,  -660,  1327,  -660,  -660,  -660,
    -105,  -660,  -660,  -660,  -660,  -660,   172,   189,   113,  -660,
    -660,  -660,  -660,  -660,  -660,  -660,  -660,  -660,  -660,  1815,
    -660,  -660,  -660,  1918,   199,  -660,   683,   176,   178,  1452,
     162,   198,   203,   -15,    -4,   205,   207,   212,   150,   217,
     230,   232,   241,   242,   243,   253,   255,   258,   261,   264,
      -4,   265,   266,   275,   155,   282,   157,   284,   286,   287,
     289,   290,   292,   293,   294,   296,   300,   301,   304,   305,
     306,   308,   309,   323,   325,   329,   330,   332,   334,  1815,
    -660,  -660,  -660,  -660,  -660,  -660,  -660,  -660,    -2,  -660,
    1452,  1918,  -660,  -660,  -660,  -660,  -660,   213,   140,  -660,
     174,  -660,  -660,   278,  -660,  -660,  -660,   333,  -660,  -660,
      19,  -660,  1237,  -660,  1573,  1573,  1573,   336,  -660,  -660,
    -660,  -660,   339,  -660,  -660,   291,  -660,  -660,  -660,  -660,
     175,  -660,  -660,  -660,  -660,  -660,  -660,  -660,   340,  -660,
    -660,  -660,  -660,    -2,   150,  1452,  1452,  1452,  -660,  -660,
    1452,  -660,  -660,  1452,  1452,  1452,  -660,  1452,  1452,  1452,
    1452,   -49,  1452,  1452,  1452,  1452,  1452,  1452,  -660,  1452,
    1452,  1452,  -660,  1452,  -660,  1452,  1452,  1452,  1452,  1452,
    1452,  1452,  1452,  1452,  1452,  1452,  1452,  1452,  1452,  1452,
    1452,  1452,  1452,  1452,  1452,  1452,  1452,  -660,   364,  -660,
    -660,   -18,   342,  -660,   839,   240,   246,  -660,  -660,   356,
     358,  -660,  -660,  -660,  1168,   349,  -660,   254,  1192,  -660,
    -660,    19,    90,  -660,  -660,  1237,  -660,  -660,  -660,  -660,
     364,   364,   -49,  -660,   352,   338,   341,  1452,  1452,  1452,
    1452,  1452,  1452,   328,    -4,  -660,  -660,   126,    12,   364,
    -660,  -660,  -660,   359,   362,   363,  -660,   348,   350,   357,
     366,   367,   361,   370,   371,   365,   372,   375,   376,   377,
     388,   403,   404,   405,   406,   407,   408,   410,   392,   411,
     412,   413,   409,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   427,   429,   431,  -660,  1452,  -660,
    -660,  -660,  -660,  -660,   839,  -660,   425,  -660,  -660,  -660,
    -660,  -660,  -660,  -660,  -660,  -660,  -660,  -660,  1452,  -660,
    -660,  1694,  -660,  -660,  -660,  -660,  -660,  -660,  -660,  -660,
      84,  -660,  -660,  -660,  -660,  1918,   434,  -660,  -660,   432,
    -660,  -660,  -660,  -660,  -660,  -660,  -660,  -660,  -660,  -660,
    -660,   179,  -660,    26,    42,  -660,  -660,  -660,  -660,  -660,
    -660,  -660,  -660,  -660,   119,  -660,  -660,  -660,  -660,  1027,
    1452,  -660,  -660,  1452,  -660,  1452,  -660,  -660,  -660,  -660,
    -660,  -660,  -660,    -4,  -660,  1452,  1452,    12,  -660,  -660,
    -660,  1452,  1452,  -660,  1452,  -660,  -660,  -660,  -660,  1452,
    1452,  1452,  -660,  -660,  1452,  -660,  -660,  1452,  -660,  -660,
    -660,  -660,  1452,  -660,  -660,  -660,  -660,  -660,  -660,  -660,
    1452,  -660,  -660,  -660,  1452,  -660,  -660,  -660,  1452,  -660,
    -660,  -660,  -660,  -660,  -660,  1452,  -660,  -660,  -660,  -660,
      -5,  -660,  -660,   291,  -660,   189,  -660,  -660,   150,  -660,
    -660,  1452,  -660,  1192,   150,   436,   -22,  -660,    50,  -660,
    -660,  -660,  -660,  -660,  -660,  1237,   378,   426,  -660,   -29,
    -660,  -660,  -660,  -660,  -660,  -660,  -660,   437,  -660,  -660,
    -660,  -660,  -660,  -660,  -660,  -660,  -660,  -660,   438,     7,
     433,   439,   442,   444,   445,   440,   446,   440,   447,   451,
    -660,  -660,  -660,  -660,  -660,   452,  -660,   103,   103,  -660,
     150,   385,  -660,  -660,  -660,  -660,   453,  -660,  -660,  -660,
    -660,  -660,   179,  -660,   179,  -660,   353,  -660,  -660,    -8,
    -660,   449,  -660,  -660,  1452,  -660,  1452,  -660,  -660,  -660,
    -660,  -660,   455,  -660,   456,  -660,  -660,     8,   400,  -660,
    -660,   150,  -660,   -49,   457,  -660,   402,   458,  -660,  -660,
     465,  -660,   -16,  -660,   430,  -660,   466,  -660,   468,  -660,
    -660,  -660,  -660,  -660,   276,  -660,  -660,  -660,  -660,  -660,
    -660,   150,  -660,   469,  -660,  -660,   -22,  -660,    90,  -660,
    -660,  -660,  -660,   473,   461,  -660,  -660,  -660,  -660,  -660,
    -660,   150,  -660,  -660,  -660,  -660,  -660,   132,  -660,  1237,
    -660,  -660
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  MapSetParser::yydefact_[] =
  {
         2,     0,    37,     1,     0,     4,    39,    38,    41,     6,
      36,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     3,     5,    42,    40,   315,   316,     0,   467,   469,
     468,   470,     9,   451,    10,    11,    12,    13,   471,   474,
     473,    14,   472,     0,    15,    29,    28,    18,    20,    19,
      16,    21,    24,    17,     0,     7,    74,     0,     0,     0,
       0,   449,   450,   452,   447,     0,    33,    26,    30,   465,
     466,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     475,   476,   322,     0,    22,   318,   319,   453,   454,   455,
     320,   317,   321,    25,    72,     0,    43,     8,   448,    35,
       0,     0,   202,    70,     0,    31,    34,     0,    23,   311,
     312,   204,    75,    44,     0,   300,   301,   302,   303,   304,
     297,     0,   205,   208,   212,   296,   295,   306,     0,   210,
      84,    32,     0,   203,   204,   209,   206,   222,   305,     0,
       0,    85,    76,    87,     0,   230,     0,   305,   229,   313,
     314,   207,   223,   213,   221,   310,   305,   307,   309,   211,
       0,    77,    78,    79,    80,    82,     0,    47,    89,    88,
     142,    83,   298,   219,   226,   228,   299,   308,    81,     0,
     124,    71,    48,     0,    91,    90,   147,   214,   224,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
      96,    99,   101,    98,   419,   387,   420,   421,     0,   126,
       0,   102,   103,   105,   189,   187,   188,     0,    93,    92,
      52,   144,    45,     0,   145,   152,   148,   156,   233,   231,
     216,   220,   305,   227,     0,     0,     0,     0,   436,   437,
     438,   439,     0,   440,   370,    55,   323,   326,   330,   332,
     334,   344,   355,   358,   363,   364,   365,   371,     0,   366,
     367,   368,   369,   445,     0,     0,     0,     0,   423,   380,
       0,   199,   409,     0,     0,     0,   428,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   386,     0,
       0,     0,   381,     0,   402,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,   194,   191,
     190,     0,     0,   104,     0,     0,     0,    86,    94,   118,
     120,    50,    51,    53,     0,    84,   143,   146,   147,   157,
     154,   222,     0,   217,   218,   305,   225,   361,   362,   360,
     194,   194,     0,    56,     0,   324,   328,     0,     0,     0,
       0,     0,     0,     0,     0,   333,   335,   345,   357,   194,
     446,   444,   429,     0,     0,     0,   200,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   195,     0,   133,
     127,   372,   111,   112,   106,   107,     0,   109,   110,   114,
     115,   122,   123,   116,   119,   117,   121,    69,     0,    65,
      66,    68,    49,    61,    58,    60,    59,    62,    63,    64,
      87,   168,   172,   166,   176,     0,     0,   165,   153,   149,
     159,   161,   162,   164,   160,   158,   180,   163,   155,   246,
     234,     0,   276,     0,     0,   232,   235,   237,   238,   247,
     249,   252,   261,   256,   259,   274,   248,   275,   215,     0,
       0,    54,   100,     0,   327,     0,   331,   336,   337,   338,
     339,   340,   341,     0,   342,     0,     0,   350,   356,   346,
     347,     0,     0,   359,     0,   378,   379,   422,   197,     0,
       0,     0,   373,   374,     0,   376,   377,     0,   414,   415,
     416,   417,     0,   418,   403,   395,   408,   401,   385,   407,
       0,   400,   384,   399,     0,   406,   398,   391,     0,   383,
     397,   390,   382,   389,   405,     0,   388,   404,   396,   192,
       0,   108,   113,    55,    67,    47,   169,   173,     0,   177,
     186,     0,   150,   147,     0,     0,   284,   292,     0,   277,
     279,   286,   288,   291,   262,   305,   250,   254,   270,     0,
     272,   271,   258,   260,   263,   434,   435,     0,   432,   325,
     329,   343,   352,   353,   351,   354,   348,   349,     0,     0,
       0,     0,     0,     0,     0,   425,     0,   425,     0,     0,
     197,   125,   130,   132,   134,     0,    46,     0,     0,   167,
       0,     0,   151,   184,   278,   285,     0,   281,   290,   293,
     289,   244,     0,   253,     0,   257,     0,   294,   273,     0,
     430,   442,   431,   201,     0,   198,     0,   411,   412,   375,
     413,   426,     0,   392,     0,   393,   394,     0,     0,    57,
     170,     0,   178,     0,   181,   287,   283,   236,   251,   255,
       0,   267,     0,   268,     0,   443,     0,   196,     0,   424,
     427,   193,   139,   140,     0,   128,   141,   136,   137,   138,
     135,     0,   174,     0,   182,   185,     0,   282,   241,   245,
     269,   264,   266,     0,     0,   433,   410,   131,   129,   171,
     175,     0,   280,   239,   242,   243,   265,     0,   183,   305,
     441,   240
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yypgoto_[] =
  {
      -660,  -660,  -660,  -660,  -660,  -660,  -660,  -660,   463,  -660,
    -660,  -660,  -660,  -660,  -660,  -660,  -660,  -660,  -660,  -660,
    -660,  -660,  -660,  -660,  -660,  -660,   -88,  -660,  -660,  -660,
    -660,   -84,  -660,    40,  -660,  -660,  -660,  -660,  -660,  -660,
    -660,  -660,  -660,  -660,  -660,   368,   148,  -660,    34,  -660,
    -660,  -660,  -660,  -660,  -660,   288,  -660,  -660,   274,  -660,
    -660,    62,  -660,  -660,  -660,  -660,  -660,  -660,   159,   161,
     154,  -660,  -660,  -660,  -660,  -660,  -660,  -202,  -196,  -660,
    -660,  -660,  -370,  -660,  -660,  -660,  -660,  -660,  -660,  -660,
    -660,  -660,  -660,  -660,  -660,  -660,  -660,  -660,  -660,  -660,
    -660,  -660,  -660,  -660,  -660,  -660,  -660,  -660,  -660,  -660,
    -352,  -158,   235,  -660,  -343,  -585,  -127,  -197,  -660,  -660,
    -660,   401,  -660,  -660,  -660,  -660,  -660,  -660,   -77,  -660,
    -660,  -660,  -660,  -660,   158,  -376,  -660,  -660,   268,   271,
    -660,  -660,  -660,  -660,  -660,  -206,  -660,  -660,  -660,  -660,
    -660,  -660,  -660,  -660,    32,  -660,  -660,  -660,  -138,  -660,
    -660,    54,  -660,  -120,  -660,  -660,  -660,  -660,  -660,  -660,
    -660,  -660,  -660,  -660,  -660,  -660,  -660,  -590,  -660,  -660,
    -659,  -110,  -660,  -660,  -660,  -660,  -660,  -660,  -107,   -91,
    -469,   -11,    35,   460,  -660,  -660,  -660,    36,  -660,  -660,
      37,  -660,  -660,  -660,   -86,  -660,  -660,    24,  -660,  -660,
    -660,  -331,  -660,  -326,  -161,  -167,  -164,  -660,  -660,   -87,
    -660,  -660,  -660,  -344,  -660,  -660,  -660,  -660,  -660,  -660,
    -660,    -9,  -660,  -660,  -660,   -40,  -660,   167,   168,   120,
    -191,    23,  -660,  -660
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yydefgoto_[] =
  {
        -1,     1,     2,     9,    21,    22,    50,    83,    52,    53,
      44,    45,    67,    68,   106,   100,    46,     5,     6,    10,
       7,    24,    58,   104,   261,   375,   181,   262,   373,   374,
     393,   394,   479,   480,   481,   482,    55,   112,    56,    57,
     130,   142,   161,   162,   163,   164,   143,   144,   167,   168,
     184,   258,   367,   169,   239,   240,   185,   251,   252,   259,
     464,   465,   466,   467,   468,   368,   473,   475,   369,   370,
     182,   249,   361,   734,   664,   708,   600,   735,   171,   186,
     263,   264,   265,   613,   498,   377,   266,   379,   380,   499,
     500,   608,   501,   606,   667,   741,   502,   607,   668,   503,
     504,   609,   670,   505,   506,   614,   745,   761,   714,   507,
     253,   254,   360,   660,   458,   695,   649,   312,   558,   103,
     111,   121,   122,   135,   136,   123,   139,   137,   152,   383,
     384,   271,   187,   153,   154,   173,   273,   188,   174,   147,
     267,   382,   381,   515,   625,   516,   764,   769,   765,   749,
     717,   510,   517,   518,   519,   520,   683,   626,   521,   685,
     627,   522,   632,   523,   633,   752,   723,   688,   634,   524,
     525,   619,   747,   716,   675,   676,   620,   621,   679,   622,
     689,   155,   125,   132,   126,   127,   128,   156,   175,   158,
     148,   284,   110,   285,   286,   534,   395,   287,   536,   396,
     288,   289,   405,   406,   290,   291,   547,   553,   645,   548,
     407,   292,   408,   293,   294,   295,   296,   309,   244,   702,
     245,   246,   247,   297,   691,   637,   298,   725,   726,   299,
     411,   300,    62,    63,    64,   301,    87,    88,    89,   302,
      33,   303,    42,    92
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int MapSetParser::yytable_ninf_ = -306;
  const short int
  MapSetParser::yytable_[] =
  {
        27,   124,   316,    32,    34,    35,    36,    37,   508,   528,
     108,    86,   469,   328,    86,   243,   255,   160,    59,   256,
     129,   241,   459,   686,   124,   751,   677,   720,   307,    60,
     486,   157,   617,   721,    65,   551,   661,   140,   662,   310,
      41,   358,    85,   129,   722,    85,    54,   529,   530,   177,
      97,   693,   731,   141,   -73,   146,    38,    39,    40,   694,
     694,    86,   159,   753,     3,    47,   554,    48,    49,   616,
     701,    86,   701,   145,    91,   243,   268,    91,     4,   552,
     617,   241,   618,    98,   255,   511,    84,   256,     8,    94,
     109,   107,    85,    23,    86,   269,   512,    51,    86,    43,
     109,   105,    85,    66,   678,   131,    61,    86,   412,    95,
     513,    96,   469,   387,   388,   389,    86,    25,    26,   687,
     101,   149,    99,   109,    91,    85,   149,   109,   149,    85,
     618,   102,   687,   511,    91,   113,   109,   486,    85,    38,
      39,    40,   628,   610,   512,   109,    86,    85,    25,    26,
     133,    38,    39,    40,   308,   150,   762,    91,   513,   629,
     150,    91,   150,   165,   663,   311,   138,   359,   242,   114,
      91,    90,   365,   366,    90,   109,   134,    85,   166,    91,
      38,    39,    40,   165,   630,    25,    26,    38,    39,    40,
     170,   545,   546,   172,   514,   371,   372,   255,   710,   711,
     256,   179,   248,    38,    39,    40,   248,   544,   183,    91,
     485,    38,    39,    40,   642,   643,   483,    28,    29,    30,
      31,    90,   511,   180,   631,   646,   647,   257,   242,   270,
     272,    90,    86,   512,   397,   398,   399,   400,   401,   402,
     304,   305,   364,   672,   403,   404,   306,   513,   313,   681,
     314,    38,    39,    40,    90,   315,    25,    26,    90,   149,
     317,   109,   248,    85,    38,    39,    40,    90,   268,    25,
      26,   491,   492,   318,   248,   319,    90,    74,    75,    76,
      77,    78,    79,   514,   320,   321,   322,   269,   180,    28,
      29,    30,    31,   150,  -179,    91,   323,   255,   324,   602,
     256,   325,   493,   494,   326,   495,    90,   327,   329,   330,
     424,   537,   538,   539,   540,   541,   542,   485,   331,   376,
     757,   732,   733,   483,   332,   333,   334,   335,   255,   336,
     337,   256,   338,   339,   488,   340,   341,   342,    86,   343,
      38,    39,    40,   344,   345,    86,   641,   346,   347,   348,
     460,   349,   350,   470,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   484,    20,   487,   351,   109,   352,    85,
     149,   526,   353,   354,   109,   355,    85,   356,   496,   390,
     378,   531,   391,   409,   392,   457,   461,   248,   471,   366,
     365,   141,    90,   771,   472,   533,   532,   248,   543,   535,
     559,    91,   560,   555,   150,   527,   556,   557,    91,   561,
     562,   563,   669,   564,   565,   566,   568,   567,   673,   569,
     570,   571,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    28,    29,    30,    31,    38,    39,    40,
     572,   488,    25,    26,   580,   732,   733,   573,   574,   575,
     576,   577,   578,   470,   579,   581,   582,   583,   585,   586,
     587,   584,   589,   590,   591,   592,   593,   594,   250,   588,
     484,   596,   487,   597,   712,   598,   595,   611,   713,   612,
     674,   690,   692,   697,   682,   696,   698,   248,   699,   700,
     703,   705,   694,   684,   489,   706,   709,   715,    90,   729,
     730,   687,   724,   268,   248,    90,   750,   744,   746,   754,
     755,   748,   756,   760,   766,   742,    93,   666,   248,   665,
     767,   604,   269,   490,   605,   363,   601,   357,   178,   476,
     474,   497,   758,   707,   527,   151,   623,   527,   410,   509,
     386,   385,   763,   615,   718,   759,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    28,    29,    30,
      31,    38,    39,    40,   719,   768,    25,    26,   624,   639,
     704,   644,   640,    86,   549,   550,   770,     0,     0,     0,
       0,     0,     0,     0,     0,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   489,   109,     0,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   109,     0,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,     0,     0,   623,
       0,   680,     0,     0,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,   149,   149,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   738,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      28,    29,    30,    31,    38,    39,    40,    80,    81,     0,
     150,   150,    82,     0,   738,     0,     0,   736,     0,   737,
       0,     0,   743,     0,     0,   527,     0,   527,   260,     0,
     362,     0,     0,     0,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   736,     0,   737,  -305,     0,     0,    86,
       0,   740,     0,    90,     0,     0,     0,   526,   120,     0,
       0,     0,     0,     0,     0,    90,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   740,   109,     0,
      85,     0,     0,     0,     0,   413,   414,   415,     0,   623,
     416,   527,     0,   417,   418,   419,     0,   420,   421,   422,
     423,     0,   425,   426,   427,   428,   429,   430,     0,   431,
     432,   433,    91,   434,     0,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   739,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      28,    29,    30,    31,    38,    39,    40,    80,    81,    25,
      26,     0,    82,     0,   739,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   462,
     463,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   250,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   190,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   599,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
       0,   210,     0,     0,     0,     0,     0,     0,   603,     0,
       0,     0,   211,     0,     0,     0,     0,     0,     0,     0,
     212,     0,   213,     0,     0,   214,   215,     0,   216,     0,
     217,   218,   219,     0,   220,   221,     0,   222,     0,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,     0,     0,     0,     0,   636,
     638,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,    39,    40,     0,     0,    25,    26,     0,     0,     0,
       0,     0,     0,     0,   648,     0,     0,     0,     0,   650,
     651,   652,     0,     0,   653,     0,     0,   654,     0,     0,
       0,     0,   655,     0,     0,     0,     0,     0,     0,     0,
     656,     0,     0,     0,   657,     0,     0,     0,   658,     0,
     635,     0,     0,     0,     0,   659,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     250,   671,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   274,   275,     0,   276,   190,     0,   191,   192,
     193,   194,   195,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,     0,   210,
       0,     0,     0,   277,   278,   279,   280,   281,   282,   283,
     211,     0,     0,     0,     0,     0,     0,     0,   212,     0,
     213,     0,     0,   214,   215,     0,   216,     0,   217,   218,
     219,     0,   220,   221,   727,   222,   728,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    28,    29,    30,    31,    38,    39,
      40,   477,     0,    25,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   478,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   115,   116,   117,
     118,   119,     0,     0,     0,  -305,     0,   190,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   120,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,     0,
     210,     0,     0,     0,   277,   278,   279,   280,   281,   282,
     283,   211,   115,   116,   117,   118,   119,     0,     0,   212,
       0,   213,     0,     0,   214,   215,     0,   216,     0,   217,
     218,   219,   120,   220,   221,     0,   222,     0,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    28,    29,    30,    31,    38,
      39,    40,     0,     0,    25,    26,     0,     0,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    28,
      29,    30,    31,    38,    39,    40,    80,    81,    25,    26,
       0,    82,   115,   116,   117,   118,   119,     0,     0,     0,
       0,   176,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   120,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    28,    29,    30,    31,    38,    39,
      40,    80,    81,    25,    26,     0,    82,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    28,    29,
      30,    31,    38,    39,    40,    80,    81,    25,    26,     0,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    28,    29,    30,    31,    38,    39,
      40,    80,    81,    25,    26,   250,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   274,   275,     0,
     276,   190,     0,   191,   192,   193,   194,   195,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,     0,   210,     0,     0,     0,   277,   278,
     279,   280,   281,   282,   283,   211,     0,     0,     0,     0,
       0,     0,     0,   212,     0,   213,     0,     0,   214,   215,
       0,   216,     0,   217,   218,   219,     0,   220,   221,     0,
     222,     0,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    28,
      29,    30,    31,    38,    39,    40,   250,     0,    25,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   190,     0,   191,   192,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,     0,   210,     0,     0,     0,   277,
     278,   279,   280,   281,   282,   283,   211,     0,     0,     0,
       0,     0,     0,     0,   212,     0,   213,     0,     0,   214,
     215,     0,   216,     0,   217,   218,   219,     0,   220,   221,
       0,   222,     0,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      28,    29,    30,    31,    38,    39,    40,   478,     0,    25,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   190,     0,   191,   192,   193,   194,   195,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,     0,   210,     0,     0,     0,
     277,   278,   279,   280,   281,   282,   283,   211,     0,     0,
       0,     0,     0,     0,     0,   212,     0,   213,     0,     0,
     214,   215,     0,   216,     0,   217,   218,   219,     0,   220,
     221,     0,   222,     0,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    28,    29,    30,    31,    38,    39,    40,   189,     0,
      25,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   190,     0,   191,   192,   193,   194,
     195,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,     0,   210,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   211,     0,
       0,     0,     0,     0,     0,     0,   212,     0,   213,     0,
       0,   214,   215,     0,   216,     0,   217,   218,   219,     0,
     220,   221,     0,   222,     0,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   250,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    39,    40,     0,
       0,    25,    26,     0,     0,     0,     0,   190,     0,   191,
     192,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,     0,
     210,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   211,     0,     0,     0,     0,     0,     0,     0,   212,
       0,   213,     0,     0,   214,   215,     0,   216,     0,   217,
     218,   219,     0,   220,   221,     0,   222,     0,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      39,    40
  };

  /* YYCHECK.  */
  const short int
  MapSetParser::yycheck_[] =
  {
        11,   111,   198,    12,    13,    14,    15,    16,   378,   385,
     101,    51,   364,   210,    54,   179,   183,    27,    27,   183,
     111,   179,    40,    52,   134,    41,   616,   686,    43,    91,
     374,   138,    54,    41,    43,    23,    41,    26,    43,    43,
      17,    43,    51,   134,    52,    54,    16,   390,   391,   156,
      59,    44,    44,    42,    24,   132,   161,   162,   163,    52,
      52,   101,   139,   722,     0,    12,   409,    14,    15,    43,
     655,   111,   657,    54,    51,   239,   186,    54,    19,    67,
      54,   239,   104,    60,   251,    43,    51,   251,   161,    54,
     101,   100,   101,    20,   134,   186,    54,    40,   138,    55,
     111,    41,   111,    40,    54,   114,   168,   147,   304,    24,
      68,   162,   464,   274,   275,   276,   156,   166,   167,   148,
      41,   132,    56,   134,   101,   134,   137,   138,   139,   138,
     104,    40,   148,    43,   111,   161,   147,   481,   147,   161,
     162,   163,    23,   495,    54,   156,   186,   156,   166,   167,
      41,   161,   162,   163,   169,   132,   746,   134,    68,    40,
     137,   138,   139,   140,   169,   169,    43,   169,   179,    47,
     147,    51,    32,    33,    54,   186,    47,   186,    94,   156,
     161,   162,   163,   160,    65,   166,   167,   161,   162,   163,
      40,    65,    66,    56,   104,    21,    22,   364,   667,   668,
     364,    29,   179,   161,   162,   163,   183,   404,    95,   186,
     374,   161,   162,   163,   545,   546,   374,   157,   158,   159,
     160,   101,    43,    34,   105,   551,   552,    28,   239,    53,
      52,   111,   272,    54,    59,    60,    61,    62,    63,    64,
      78,    43,    29,   613,    69,    70,    43,    68,    43,   625,
      43,   161,   162,   163,   134,    43,   166,   167,   138,   270,
      43,   272,   239,   272,   161,   162,   163,   147,   378,   166,
     167,    17,    18,    43,   251,    43,   156,   151,   152,   153,
     154,   155,   156,   104,    43,    43,    43,   378,    34,   157,
     158,   159,   160,   270,    40,   272,    43,   464,    43,   466,
     464,    43,    48,    49,    43,    51,   186,    43,    43,    43,
     321,   397,   398,   399,   400,   401,   402,   481,    43,    41,
      44,    45,    46,   481,   169,    43,   169,    43,   495,    43,
      43,   495,    43,    43,   374,    43,    43,    43,   378,    43,
     161,   162,   163,    43,    43,   385,   543,    43,    43,    43,
     361,    43,    43,   364,     3,     4,     5,     6,     7,     8,
       9,    10,    11,   374,    13,   374,    43,   378,    43,   378,
     381,   382,    43,    43,   385,    43,   385,    43,   124,    43,
      47,   392,    43,    43,    93,    21,    44,   364,   148,    33,
      32,    42,   272,   769,   148,    57,    44,   374,    70,    58,
      52,   378,    52,    44,   381,   382,    44,    44,   385,    52,
      44,    44,   608,    52,    44,    44,    44,    52,   614,    44,
      44,    44,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
      52,   481,   166,   167,    52,    45,    46,    44,    44,    44,
      44,    44,    44,   464,    44,    44,    44,    44,    44,    44,
      44,    52,    44,    44,    44,    44,    44,    44,    43,    52,
     481,    44,   481,    44,   670,    44,    52,    43,    93,    47,
      44,    44,    44,    44,   106,    52,    44,   464,    44,    44,
      44,    44,    52,    67,   374,    44,    44,    44,   378,    44,
      44,   148,    53,   613,   481,   385,    41,    50,   106,    79,
      44,    53,    44,    44,    41,   711,    53,   605,   495,   603,
      59,   481,   613,   375,   490,   251,   464,   239,   160,   370,
     369,   377,   734,   660,   511,   134,   513,   514,   303,   381,
     272,   270,   748,   511,   682,   741,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   684,   761,   166,   167,   514,   533,
     657,   547,   535,   613,   407,   407,   767,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   625,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   481,   613,    -1,   613,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   625,    -1,   625,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   613,    -1,    -1,   616,
      -1,   618,    -1,    -1,    -1,    -1,    -1,    -1,   625,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   667,   668,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   708,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
     667,   668,   169,    -1,   734,    -1,    -1,   708,    -1,   708,
      -1,    -1,   713,    -1,    -1,   682,    -1,   684,    25,    -1,
     250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    39,   734,    -1,   734,    43,    -1,    -1,   769,
      -1,   708,    -1,   613,    -1,    -1,    -1,   748,    55,    -1,
      -1,    -1,    -1,    -1,    -1,   625,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   734,   769,    -1,
     769,    -1,    -1,    -1,    -1,   305,   306,   307,    -1,   746,
     310,   748,    -1,   313,   314,   315,    -1,   317,   318,   319,
     320,    -1,   322,   323,   324,   325,   326,   327,    -1,   329,
     330,   331,   769,   333,    -1,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   708,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,   169,    -1,   734,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,   769,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,   458,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,   478,    -1,
      -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,    -1,   113,    -1,    -1,   116,   117,    -1,   119,    -1,
     121,   122,   123,    -1,   125,   126,    -1,   128,    -1,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,   529,
     530,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,   163,    -1,    -1,   166,   167,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   554,    -1,    -1,    -1,    -1,   559,
     560,   561,    -1,    -1,   564,    -1,    -1,   567,    -1,    -1,
      -1,    -1,   572,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     580,    -1,    -1,    -1,   584,    -1,    -1,    -1,   588,    -1,
      23,    -1,    -1,    -1,    -1,   595,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,   611,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    66,    -1,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    -1,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      -1,    -1,    -1,    96,    97,    98,    99,   100,   101,   102,
     103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,
     113,    -1,    -1,   116,   117,    -1,   119,    -1,   121,   122,
     123,    -1,   125,   126,   694,   128,   696,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    23,    -1,   166,   167,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    43,    -1,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    55,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      92,    -1,    -1,    -1,    96,    97,    98,    99,   100,   101,
     102,   103,    35,    36,    37,    38,    39,    -1,    -1,   111,
      -1,   113,    -1,    -1,   116,   117,    -1,   119,    -1,   121,
     122,   123,    55,   125,   126,    -1,   128,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,    -1,    -1,   166,   167,    -1,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,   169,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    -1,   169,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
     169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    43,   169,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    -1,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    -1,    -1,    -1,    96,    97,
      98,    99,   100,   101,   102,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,    -1,   113,    -1,    -1,   116,   117,
      -1,   119,    -1,   121,   122,   123,    -1,   125,   126,    -1,
     128,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,    43,    -1,   166,   167,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    -1,    -1,    -1,    96,
      97,    98,    99,   100,   101,   102,   103,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,   113,    -1,    -1,   116,
     117,    -1,   119,    -1,   121,   122,   123,    -1,   125,   126,
      -1,   128,    -1,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    43,    -1,   166,
     167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    -1,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,    92,    -1,    -1,    -1,
      96,    97,    98,    99,   100,   101,   102,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,    -1,   113,    -1,    -1,
     116,   117,    -1,   119,    -1,   121,   122,   123,    -1,   125,
     126,    -1,   128,    -1,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,    43,    -1,
     166,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,   113,    -1,
      -1,   116,   117,    -1,   119,    -1,   121,   122,   123,    -1,
     125,   126,    -1,   128,    -1,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,
      -1,   166,   167,    -1,    -1,    -1,    -1,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      -1,   113,    -1,    -1,   116,   117,    -1,   119,    -1,   121,
     122,   123,    -1,   125,   126,    -1,   128,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,   163
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  MapSetParser::yystos_[] =
  {
         0,   171,   172,     0,    19,   187,   188,   190,   161,   173,
     189,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      13,   174,   175,    20,   191,   166,   167,   361,   157,   158,
     159,   160,   401,   410,   401,   401,   401,   401,   161,   162,
     163,   411,   412,    55,   180,   181,   186,    12,    14,    15,
     176,    40,   178,   179,    16,   206,   208,   209,   192,   401,
      91,   168,   402,   403,   404,   401,    40,   182,   183,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     164,   165,   169,   177,   362,   401,   405,   406,   407,   408,
     409,   411,   413,   178,   362,    24,   162,   401,   411,    56,
     185,    41,    40,   289,   193,    41,   184,   401,   359,   361,
     362,   290,   207,   161,    47,    35,    36,    37,    38,    39,
      55,   291,   292,   295,   351,   352,   354,   355,   356,   359,
     210,   401,   353,    41,    47,   293,   294,   297,    43,   296,
      26,    42,   211,   216,   217,    54,   298,   309,   360,   361,
     411,   291,   298,   303,   304,   351,   357,   358,   359,   298,
      27,   212,   213,   214,   215,   411,    94,   218,   219,   223,
      40,   248,    56,   305,   308,   358,    44,   358,   215,    29,
      34,   196,   240,    95,   220,   226,   249,   302,   307,    43,
      69,    71,    72,    73,    74,    75,    76,    77,    78,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      92,   103,   111,   113,   116,   117,   119,   121,   122,   123,
     125,   126,   128,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   224,
     225,   281,   361,   386,   388,   390,   391,   392,   411,   241,
      43,   227,   228,   280,   281,   385,   386,    28,   221,   229,
      25,   194,   197,   250,   251,   252,   256,   310,   351,   359,
      53,   301,    52,   306,    65,    66,    68,    96,    97,    98,
      99,   100,   101,   102,   361,   363,   364,   367,   370,   371,
     374,   375,   381,   383,   384,   385,   386,   393,   396,   399,
     401,   405,   409,   411,    78,    43,    43,    43,   169,   387,
      43,   169,   287,    43,    43,    43,   248,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,   287,    43,
      43,    43,   169,    43,   169,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,   225,    43,   169,
     282,   242,   363,   228,    29,    32,    33,   222,   235,   238,
     239,    21,    22,   198,   199,   195,    41,   255,    47,   257,
     258,   312,   311,   299,   300,   309,   308,   384,   384,   384,
      43,    43,    93,   200,   201,   366,   369,    59,    60,    61,
      62,    63,    64,    69,    70,   372,   373,   380,   382,    43,
     282,   400,   248,   363,   363,   363,   363,   363,   363,   363,
     363,   363,   363,   363,   361,   363,   363,   363,   363,   363,
     363,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     363,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     363,   363,   363,   363,   363,   363,   363,    21,   284,    40,
     361,    44,    30,    31,   230,   231,   232,   233,   234,   280,
     361,   148,   148,   236,   239,   237,   238,    23,    43,   202,
     203,   204,   205,   281,   361,   386,   393,   401,   405,   409,
     216,    17,    18,    48,    49,    51,   124,   240,   254,   259,
     260,   262,   266,   269,   270,   273,   274,   279,   252,   304,
     321,    43,    54,    68,   104,   313,   315,   322,   323,   324,
     325,   328,   331,   333,   339,   340,   361,   411,   305,   284,
     284,   361,    44,    57,   365,    58,   368,   374,   374,   374,
     374,   374,   374,    70,   287,    65,    66,   376,   379,   407,
     408,    23,    67,   377,   284,    44,    44,    44,   288,    52,
      52,    52,    44,    44,    52,    44,    44,    52,    44,    44,
      44,    44,    52,    44,    44,    44,    44,    44,    44,    44,
      52,    44,    44,    44,    52,    44,    44,    44,    52,    44,
      44,    44,    44,    44,    44,    52,    44,    44,    44,   363,
     246,   231,   385,   363,   203,   218,   263,   267,   261,   271,
     280,    43,    47,   253,   275,   324,    43,    54,   104,   341,
     346,   347,   349,   411,   331,   314,   327,   330,    23,    40,
      65,   105,   332,   334,   338,    23,   363,   395,   363,   367,
     370,   287,   381,   381,   377,   378,   383,   383,   363,   286,
     363,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     283,    41,    43,   169,   244,   201,   196,   264,   268,   248,
     272,   363,   252,   248,    44,   344,   345,   347,    54,   348,
     411,   305,   106,   326,    67,   329,    52,   148,   337,   350,
      44,   394,    44,    44,    52,   285,    52,    44,    44,    44,
      44,   285,   389,    44,   389,    44,    44,   286,   245,    44,
     360,   360,   248,    93,   278,    44,   343,   320,   328,   333,
     350,    41,    52,   336,    53,   397,   398,   363,   363,    44,
      44,    44,    45,    46,   243,   247,   361,   401,   405,   409,
     411,   265,   248,   361,    50,   276,   106,   342,    53,   319,
      41,    41,   335,   350,    79,    44,    44,    44,   247,   248,
      44,   277,   347,   315,   316,   318,    41,    59,   248,   317,
     410,   305
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
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  MapSetParser::yyr1_[] =
  {
         0,   170,   172,   171,   173,   173,   174,   174,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   176,   176,
     176,   177,   177,   178,   179,   179,   180,   181,   181,   182,
     182,   183,   184,   185,   185,   186,   187,   188,   188,   189,
     189,   190,   192,   193,   191,   195,   194,   196,   196,   197,
     198,   198,   199,   199,   200,   201,   201,   202,   203,   203,
     203,   203,   203,   203,   203,   203,   204,   204,   205,   205,
     207,   206,   208,   209,   209,   210,   210,   211,   212,   212,
     213,   214,   215,   216,   217,   217,   218,   219,   219,   220,
     220,   221,   221,   222,   222,   223,   224,   224,   225,   225,
     225,   225,   226,   227,   227,   228,   229,   230,   230,   231,
     231,   232,   232,   233,   234,   234,   235,   235,   236,   236,
     237,   237,   238,   239,   241,   240,   242,   242,   243,   243,
     245,   244,   244,   246,   246,   247,   247,   247,   247,   247,
     247,   247,   249,   248,   250,   250,   251,   252,   252,   253,
     253,   254,   255,   255,   256,   257,   258,   258,   259,   259,
     259,   259,   259,   259,   259,   259,   261,   260,   263,   264,
     265,   262,   267,   268,   266,   269,   271,   272,   270,   274,
     275,   273,   277,   276,   278,   278,   279,   280,   280,   280,
     281,   282,   283,   282,   284,   284,   285,   286,   286,   287,
     288,   287,   290,   289,   291,   291,   292,   293,   294,   294,
     296,   295,   297,   295,   298,   299,   300,   300,   301,   302,
     302,   303,   304,   304,   305,   306,   307,   307,   308,   309,
     309,   311,   310,   312,   310,   314,   313,   315,   315,   317,
     316,   318,   318,   319,   320,   320,   321,   322,   323,   324,
     325,   326,   327,   327,   328,   329,   330,   330,   331,   332,
     332,   333,   333,   334,   335,   335,   336,   336,   337,   337,
     338,   338,   338,   338,   339,   340,   340,   340,   340,   341,
     342,   343,   343,   344,   345,   345,   346,   346,   347,   348,
     348,   349,   349,   349,   350,   351,   351,   353,   352,   354,
     355,   355,   355,   355,   355,   356,   356,   357,   357,   358,
     358,   359,   359,   360,   360,   361,   361,   362,   362,   362,
     362,   362,   362,   363,   364,   365,   366,   366,   367,   368,
     369,   369,   370,   371,   372,   372,   373,   373,   373,   373,
     373,   373,   373,   373,   374,   375,   376,   376,   377,   377,
     378,   378,   379,   379,   379,   380,   380,   381,   382,   382,
     383,   383,   383,   383,   384,   384,   384,   384,   384,   384,
     384,   384,   385,   386,   386,   386,   386,   386,   386,   386,
     386,   386,   386,   386,   386,   386,   386,   386,   386,   386,
     386,   386,   386,   386,   386,   386,   386,   386,   386,   386,
     386,   386,   386,   386,   386,   386,   386,   386,   386,   386,
     386,   386,   386,   386,   386,   386,   386,   386,   386,   386,
     386,   386,   387,   387,   388,   389,   389,   390,   391,   392,
     393,   393,   394,   393,   395,   395,   396,   396,   396,   396,
     396,   397,   398,   398,   399,   400,   400,   401,   402,   403,
     403,   404,   404,   405,   405,   405,   406,   406,   406,   407,
     407,   407,   408,   408,   408,   409,   409,   410,   410,   410,
     410,   411,   411,   412,   412,   413,   413
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  MapSetParser::yyr2_[] =
  {
         0,     2,     0,     4,     0,     2,     0,     2,     4,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     0,     1,     4,     1,     2,     2,     0,     1,     0,
       1,     3,     3,     0,     2,     3,     2,     0,     1,     0,
       2,     2,     0,     0,     5,     0,     5,     0,     1,     3,
       1,     1,     0,     1,     2,     0,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       0,     8,     2,     0,     1,     0,     2,     2,     1,     1,
       1,     2,     1,     2,     0,     1,     4,     0,     1,     0,
       1,     0,     1,     0,     1,     3,     1,     2,     1,     1,
       4,     1,     2,     1,     2,     1,     3,     1,     2,     1,
       1,     1,     1,     2,     1,     1,     2,     2,     0,     1,
       0,     1,     2,     2,     0,     6,     0,     2,     1,     2,
       0,     4,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     1,     1,     2,     0,     1,     0,
       1,     3,     0,     2,     2,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     3,     0,     0,
       0,     6,     0,     0,     5,     6,     0,     0,     4,     0,
       0,     4,     0,     3,     0,     2,     2,     1,     1,     1,
       2,     1,     0,     6,     0,     1,     2,     0,     2,     1,
       0,     5,     0,     4,     0,     1,     2,     2,     0,     1,
       0,     3,     0,     3,     3,     2,     0,     1,     2,     0,
       2,     1,     0,     1,     2,     2,     0,     2,     1,     1,
       1,     0,     3,     0,     3,     0,     4,     1,     1,     0,
       3,     0,     1,     2,     0,     2,     1,     1,     1,     1,
       2,     2,     0,     2,     2,     2,     0,     2,     2,     0,
       1,     1,     2,     1,     1,     2,     2,     1,     2,     3,
       1,     1,     1,     2,     1,     1,     1,     2,     3,     1,
       2,     0,     2,     2,     0,     1,     1,     3,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     0,     4,     4,
       1,     1,     1,     1,     1,     0,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     0,     2,     2,     2,
       0,     2,     1,     2,     0,     1,     2,     2,     2,     2,
       2,     2,     2,     3,     1,     2,     1,     1,     2,     2,
       0,     1,     2,     2,     2,     0,     2,     2,     0,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     4,     6,     4,     4,     4,     4,
       2,     2,     4,     4,     4,     4,     2,     1,     4,     4,
       4,     4,     6,     6,     6,     4,     4,     4,     4,     4,
       4,     4,     2,     4,     4,     4,     4,     4,     4,     2,
       8,     6,     6,     6,     4,     4,     4,     4,     4,     1,
       1,     1,     3,     1,     7,     0,     1,     7,     2,     3,
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
  "IT_UNDEF", "GT_MINUS_MINUS", "GT_DOT", "IT_OPTIONAL", "IT_MINUS",
  "IT_UNION", "IT_FILTER", "GT_COMMA", "GT_SEMI", "IT_a", "GT_LBRACKET",
  "GT_RBRACKET", "GT_OR", "GT_AND", "GT_EQUAL", "GT_NEQUAL", "GT_LT",
  "GT_GT", "GT_LE", "GT_GE", "GT_PLUS", "GT_MINUS", "GT_DIVIDE", "GT_NOT",
  "IT_NOT", "IT_IN", "IT_IRI", "IT_URI", "IT_BNODE", "IT_COALESCE",
  "IT_IF", "IT_STRLANG", "IT_STRDT", "IT_EXISTS", "IT_SEPARATOR", "IT_STR",
  "IT_LANG", "IT_LANGMATCHES", "IT_DATATYPE", "IT_BOUND", "IT_sameTerm",
  "IT_isIRI", "IT_isURI", "IT_isBLANK", "IT_isLITERAL", "IT_REGEX",
  "GT_DTYPE", "IT_CONCAT", "IT_AS", "IT_GROUP", "IT_HAVING", "IT_COUNT",
  "IT_SUM", "IT_MIN", "IT_MAX", "IT_AVG", "IT_GROUP_CONCAT", "IT_SAMPLE",
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
  "SubSelect", "@4", "_QBindingsClause_E_Opt", "SelectClause",
  "_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C",
  "_Q_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C_E_Opt", "_O_QIT_AS_E_S_QVar_E_C",
  "_Q_O_QIT_AS_E_S_QVar_E_C_E_Opt",
  "_O_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_Q_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C_E_Plus",
  "_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_Plus_Or_QGT_TIMES_E_C",
  "ConstructQuery", "$@5", "_O_QIT_LABEL_E_S_QGraphTerm_E_C",
  "_Q_O_QIT_LABEL_E_S_QGraphTerm_E_C_E_Opt", "_QDatasetClause_E_Star",
  "DatasetClause", "_O_QDefaultGraphClause_E_Or_QNamedGraphClause_E_C",
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
  "OffsetClause", "BindingsClause", "$@6", "_QVar_E_Star",
  "_QBindingValue_E_Plus",
  "_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C",
  "$@7",
  "_Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star",
  "BindingValue", "GroupGraphPattern", "$@8",
  "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C", "GroupGraphPatternSub",
  "_QTriplesBlock_E_Opt", "_QGT_DOT_E_Opt",
  "_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "OptionalGraphPattern", "@9", "GraphGraphPattern", "@10", "@11", "@12",
  "ServiceGraphPattern", "@13", "@14", "Bind", "MinusGraphPattern", "@15",
  "@16", "GroupOrUnionGraphPattern", "@17", "@18",
  "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@19",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "$@20", "_QIT_DISTINCT_E_Opt",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ExpressionList", "$@21",
  "ConstructTemplate", "$@22", "_QConstructTriples_E_Opt",
  "ConstructTriples", "_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C_E_Opt", "TriplesSameSubject",
  "$@23", "$@24", "PropertyListNotEmpty", "_O_QVerb_E_S_QObjectList_E_C",
  "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "Verb", "TriplesSameSubjectPath", "$@25", "$@26",
  "PropertyListNotEmptyPath", "$@27", "_O_QVerbPath_E_Or_QVerbSimple_E_C",
  "_O_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_C", "$@28",
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
  "Integer", "TriplesNode", "BlankNodePropertyList", "@29", "Generator",
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
  "$@30", "_O_QGT_TIMES_E_Or_QExpression_E_C",
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
       171,     0,    -1,    -1,   172,   187,   173,   174,    -1,    -1,
     173,   175,    -1,    -1,   174,   206,    -1,     3,   361,   401,
     401,    -1,     4,   401,    -1,     5,   401,    -1,     6,   401,
      -1,     7,   401,    -1,     8,   401,    -1,     9,   411,    -1,
      10,   180,    -1,    11,   176,    -1,    13,   179,    -1,    12,
      -1,    15,    -1,    14,    -1,    -1,   362,    -1,    40,   177,
      41,   359,    -1,   178,    -1,   179,   178,    -1,   181,   182,
      -1,    -1,   186,    -1,    -1,   183,    -1,    40,   185,    41,
      -1,   401,    47,   401,    -1,    -1,   185,   184,    -1,    55,
     401,    56,    -1,   188,   189,    -1,    -1,   190,    -1,    -1,
     189,   191,    -1,    19,   161,    -1,    -1,    -1,    20,   192,
     162,   193,   161,    -1,    -1,   197,   195,   216,   218,   196,
      -1,    -1,   240,    -1,    25,   199,   205,    -1,    21,    -1,
      22,    -1,    -1,   198,    -1,    93,   361,    -1,    -1,   200,
      -1,    43,   363,   201,    44,    -1,   361,    -1,   393,    -1,
     386,    -1,   281,    -1,   401,    -1,   405,    -1,   409,    -1,
     202,    -1,   203,    -1,   204,   203,    -1,   204,    -1,    23,
      -1,    -1,   209,    24,   289,   207,   210,   216,   218,   196,
      -1,    16,   362,    -1,    -1,   208,    -1,    -1,   210,   211,
      -1,    26,   212,    -1,   213,    -1,   214,    -1,   215,    -1,
      27,   215,    -1,   411,    -1,   217,   248,    -1,    -1,    42,
      -1,   219,   220,   221,   222,    -1,    -1,   223,    -1,    -1,
     226,    -1,    -1,   229,    -1,    -1,   235,    -1,    94,    29,
     224,    -1,   225,    -1,   224,   225,    -1,   386,    -1,   281,
      -1,    43,   363,   201,    44,    -1,   361,    -1,    95,   227,
      -1,   228,    -1,   227,   228,    -1,   280,    -1,    28,    29,
     230,    -1,   231,    -1,   230,   231,    -1,   233,    -1,   234,
      -1,    30,    -1,    31,    -1,   232,   385,    -1,   280,    -1,
     361,    -1,   238,   236,    -1,   239,   237,    -1,    -1,   239,
      -1,    -1,   238,    -1,    32,   148,    -1,    33,   148,    -1,
      -1,    34,   241,   242,    40,   246,    41,    -1,    -1,   242,
     361,    -1,   247,    -1,   243,   247,    -1,    -1,    43,   245,
     243,    44,    -1,   169,    -1,    -1,   246,   244,    -1,   411,
      -1,   401,    -1,   405,    -1,   409,    -1,    45,    -1,    46,
      -1,   361,    -1,    -1,    40,   249,   250,    41,    -1,   194,
      -1,   251,    -1,   252,   255,    -1,    -1,   256,    -1,    -1,
      47,    -1,   259,   253,   252,    -1,    -1,   255,   254,    -1,
     310,   258,    -1,    47,   252,    -1,    -1,   257,    -1,   273,
      -1,   260,    -1,   270,    -1,   262,    -1,   266,    -1,   279,
      -1,   269,    -1,   240,    -1,    -1,    48,   261,   248,    -1,
      -1,    -1,    -1,    17,   263,   264,   360,   265,   248,    -1,
      -1,    -1,    18,   267,   268,   360,   248,    -1,   124,    43,
     363,    93,   361,    44,    -1,    -1,    -1,    49,   271,   272,
     248,    -1,    -1,    -1,   274,   275,   248,   278,    -1,    -1,
      50,   277,   248,    -1,    -1,   278,   276,    -1,    51,   280,
      -1,   385,    -1,   386,    -1,   281,    -1,   411,   282,    -1,
     169,    -1,    -1,    43,   284,   363,   283,   286,    44,    -1,
      -1,    21,    -1,    52,   363,    -1,    -1,   286,   285,    -1,
     169,    -1,    -1,    43,   363,   288,   286,    44,    -1,    -1,
      40,   290,   291,    41,    -1,    -1,   292,    -1,   295,   294,
      -1,    47,   291,    -1,    -1,   293,    -1,    -1,   359,   296,
     298,    -1,    -1,   351,   297,   303,    -1,   309,   305,   302,
      -1,   309,   305,    -1,    -1,   299,    -1,    53,   300,    -1,
      -1,   302,   301,    -1,   304,    -1,    -1,   298,    -1,   308,
     307,    -1,    52,   308,    -1,    -1,   307,   306,    -1,   358,
      -1,   360,    -1,    54,    -1,    -1,   359,   311,   313,    -1,
      -1,   351,   312,   321,    -1,    -1,   315,   314,   305,   320,
      -1,   322,    -1,   323,    -1,    -1,   315,   317,   305,    -1,
      -1,   316,    -1,    53,   318,    -1,    -1,   320,   319,    -1,
     304,    -1,   324,    -1,   361,    -1,   325,    -1,   328,   327,
      -1,   106,   328,    -1,    -1,   327,   326,    -1,   333,   330,
      -1,    67,   333,    -1,    -1,   330,   329,    -1,   339,   332,
      -1,    -1,   334,    -1,   331,    -1,   104,   331,    -1,   338,
      -1,    41,    -1,   350,    41,    -1,    52,   335,    -1,    41,
      -1,   350,   336,    -1,    52,   350,    41,    -1,    23,    -1,
     105,    -1,    65,    -1,    40,   337,    -1,   340,    -1,   411,
      -1,    54,    -1,    68,   341,    -1,    43,   324,    44,    -1,
     346,    -1,   106,   347,    -1,    -1,   343,   342,    -1,   347,
     343,    -1,    -1,   344,    -1,   347,    -1,    43,   345,    44,
      -1,   349,    -1,   411,    -1,    54,    -1,   411,    -1,    54,
      -1,   104,   348,    -1,   148,    -1,   354,    -1,   352,    -1,
      -1,    55,   353,   298,    56,    -1,   356,    43,   357,    44,
      -1,    35,    -1,    36,    -1,    37,    -1,    38,    -1,    39,
      -1,    -1,   355,    -1,   358,    -1,   357,   358,    -1,   359,
      -1,   351,    -1,   361,    -1,   362,    -1,   361,    -1,   411,
      -1,   166,    -1,   167,    -1,   411,    -1,   401,    -1,   405,
      -1,   409,    -1,   413,    -1,   169,    -1,   364,    -1,   367,
     366,    -1,    57,   367,    -1,    -1,   366,   365,    -1,   370,
     369,    -1,    58,   370,    -1,    -1,   369,   368,    -1,   371,
      -1,   374,   372,    -1,    -1,   373,    -1,    59,   374,    -1,
      60,   374,    -1,    61,   374,    -1,    62,   374,    -1,    63,
     374,    -1,    64,   374,    -1,    70,   287,    -1,    69,    70,
     287,    -1,   375,    -1,   381,   380,    -1,   407,    -1,   408,
      -1,    23,   383,    -1,    67,   383,    -1,    -1,   377,    -1,
      65,   381,    -1,    66,   381,    -1,   376,   378,    -1,    -1,
     380,   379,    -1,   383,   382,    -1,    -1,   382,   377,    -1,
      68,   384,    -1,    65,   384,    -1,    66,   384,    -1,   384,
      -1,   385,    -1,   386,    -1,   399,    -1,   401,    -1,   405,
      -1,   409,    -1,   361,    -1,   393,    -1,    43,   363,    44,
      -1,    80,    43,   363,    44,    -1,    81,    43,   363,    44,
      -1,    82,    43,   363,    52,   363,    44,    -1,    83,    43,
     363,    44,    -1,    84,    43,   361,    44,    -1,    71,    43,
     363,    44,    -1,    72,    43,   363,    44,    -1,    73,   387,
      -1,   116,   169,    -1,   139,    43,   363,    44,    -1,   136,
      43,   363,    44,    -1,   128,    43,   363,    44,    -1,   122,
      43,   363,    44,    -1,    92,   287,    -1,   390,    -1,   143,
      43,   363,    44,    -1,   140,    43,   363,    44,    -1,   138,
      43,   363,    44,    -1,   134,    43,   363,    44,    -1,   125,
      43,   363,    52,   363,    44,    -1,   135,    43,   363,    52,
     363,    44,    -1,   142,    43,   363,    52,   363,    44,    -1,
     113,    43,   363,    44,    -1,   145,    43,   363,    44,    -1,
     137,    43,   363,    44,    -1,   133,    43,   363,    44,    -1,
     130,    43,   363,    44,    -1,   126,    43,   363,    44,    -1,
     121,    43,   363,    44,    -1,   119,   169,    -1,   111,    43,
     363,    44,    -1,   144,    43,   363,    44,    -1,   141,    43,
     363,    44,    -1,   132,    43,   363,    44,    -1,   123,    43,
     363,    44,    -1,   117,    43,   363,    44,    -1,    74,   287,
      -1,    75,    43,   363,    52,   363,    52,   363,    44,    -1,
      76,    43,   363,    52,   363,    44,    -1,    77,    43,   363,
      52,   363,    44,    -1,    85,    43,   363,    52,   363,    44,
      -1,    86,    43,   363,    44,    -1,    87,    43,   363,    44,
      -1,    88,    43,   363,    44,    -1,    89,    43,   363,    44,
      -1,   103,    43,   363,    44,    -1,   388,    -1,   391,    -1,
     392,    -1,    43,   363,    44,    -1,   169,    -1,    90,    43,
     363,    52,   363,   389,    44,    -1,    -1,   285,    -1,   131,
      43,   363,    52,   363,   389,    44,    -1,    78,   248,    -1,
      69,    78,   248,    -1,    96,    43,   284,   395,    44,    -1,
     396,    43,   284,   363,    44,    -1,    -1,   101,    43,   284,
     363,   394,   398,    44,    -1,    23,    -1,   363,    -1,    97,
      -1,    98,    -1,    99,    -1,   100,    -1,   102,    -1,    53,
      79,    59,   410,    -1,    -1,   397,    -1,   411,   400,    -1,
      -1,   282,    -1,   410,   404,    -1,    91,   411,    -1,   168,
      -1,   402,    -1,    -1,   403,    -1,   406,    -1,   407,    -1,
     408,    -1,   148,    -1,   149,    -1,   150,    -1,   151,    -1,
     152,    -1,   153,    -1,   154,    -1,   155,    -1,   156,    -1,
     146,    -1,   147,    -1,   157,    -1,   159,    -1,   158,    -1,
     160,    -1,   161,    -1,   412,    -1,   163,    -1,   162,    -1,
     164,    -1,   165,    -1
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
     100,   103,   106,   107,   108,   114,   115,   121,   122,   124,
     128,   130,   132,   133,   135,   138,   139,   141,   146,   148,
     150,   152,   154,   156,   158,   160,   162,   164,   167,   169,
     171,   172,   181,   184,   185,   187,   188,   191,   194,   196,
     198,   200,   203,   205,   208,   209,   211,   216,   217,   219,
     220,   222,   223,   225,   226,   228,   232,   234,   237,   239,
     241,   246,   248,   251,   253,   256,   258,   262,   264,   267,
     269,   271,   273,   275,   278,   280,   282,   285,   288,   289,
     291,   292,   294,   297,   300,   301,   308,   309,   312,   314,
     317,   318,   323,   325,   326,   329,   331,   333,   335,   337,
     339,   341,   343,   344,   349,   351,   353,   356,   357,   359,
     360,   362,   366,   367,   370,   373,   376,   377,   379,   381,
     383,   385,   387,   389,   391,   393,   395,   396,   400,   401,
     402,   403,   410,   411,   412,   418,   425,   426,   427,   432,
     433,   434,   439,   440,   444,   445,   448,   451,   453,   455,
     457,   460,   462,   463,   470,   471,   473,   476,   477,   480,
     482,   483,   489,   490,   495,   496,   498,   501,   504,   505,
     507,   508,   512,   513,   517,   521,   524,   525,   527,   530,
     531,   534,   536,   537,   539,   542,   545,   546,   549,   551,
     553,   555,   556,   560,   561,   565,   566,   571,   573,   575,
     576,   580,   581,   583,   586,   587,   590,   592,   594,   596,
     598,   601,   604,   605,   608,   611,   614,   615,   618,   621,
     622,   624,   626,   629,   631,   633,   636,   639,   641,   644,
     648,   650,   652,   654,   657,   659,   661,   663,   666,   670,
     672,   675,   676,   679,   682,   683,   685,   687,   691,   693,
     695,   697,   699,   701,   704,   706,   708,   710,   711,   716,
     721,   723,   725,   727,   729,   731,   732,   734,   736,   739,
     741,   743,   745,   747,   749,   751,   753,   755,   757,   759,
     761,   763,   765,   767,   769,   772,   775,   776,   779,   782,
     785,   786,   789,   791,   794,   795,   797,   800,   803,   806,
     809,   812,   815,   818,   822,   824,   827,   829,   831,   834,
     837,   838,   840,   843,   846,   849,   850,   853,   856,   857,
     860,   863,   866,   869,   871,   873,   875,   877,   879,   881,
     883,   885,   887,   891,   896,   901,   908,   913,   918,   923,
     928,   931,   934,   939,   944,   949,   954,   957,   959,   964,
     969,   974,   979,   986,   993,  1000,  1005,  1010,  1015,  1020,
    1025,  1030,  1035,  1038,  1043,  1048,  1053,  1058,  1063,  1068,
    1071,  1080,  1087,  1094,  1101,  1106,  1111,  1116,  1121,  1126,
    1128,  1130,  1132,  1136,  1138,  1146,  1147,  1149,  1157,  1160,
    1164,  1170,  1176,  1177,  1185,  1187,  1189,  1191,  1193,  1195,
    1197,  1199,  1204,  1205,  1207,  1210,  1211,  1213,  1216,  1219,
    1221,  1223,  1224,  1226,  1228,  1230,  1232,  1234,  1236,  1238,
    1240,  1242,  1244,  1246,  1248,  1250,  1252,  1254,  1256,  1258,
    1260,  1262,  1264,  1266,  1268,  1270,  1272
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  MapSetParser::yyrline_[] =
  {
         0,   454,   454,   454,   460,   462,   466,   468,   472,   481,
     484,   487,   490,   493,   496,   499,   501,   505,   511,   514,
     517,   523,   526,   530,   542,   543,   547,   550,   552,   555,
     557,   561,   565,   570,   572,   576,   583,   587,   589,   593,
     595,   599,   605,   607,   605,   617,   617,   629,   632,   637,
     645,   648,   655,   658,   663,   670,   673,   678,   685,   688,
     691,   694,   697,   700,   703,   707,   712,   715,   723,   726,
     733,   733,   745,   751,   754,   759,   762,   770,   777,   778,
     782,   788,   794,   801,   808,   810,   815,   822,   825,   830,
     833,   838,   841,   846,   850,   854,   861,   864,   871,   874,
     877,   880,   886,   892,   895,   902,   907,   914,   918,   926,
     928,   936,   939,   947,   955,   956,   963,   967,   975,   978,
     983,   986,   990,   996,  1003,  1003,  1011,  1013,  1019,  1022,
    1028,  1028,  1033,  1039,  1041,  1045,  1048,  1051,  1054,  1057,
    1060,  1063,  1070,  1070,  1081,  1082,  1087,  1091,  1093,  1101,
    1103,  1108,  1112,  1115,  1131,  1136,  1140,  1143,  1147,  1148,
    1149,  1150,  1151,  1152,  1153,  1154,  1160,  1160,  1176,  1180,
    1182,  1176,  1193,  1197,  1193,  1206,  1212,  1216,  1212,  1226,
    1230,  1226,  1240,  1240,  1255,  1257,  1261,  1272,  1273,  1274,
    1278,  1286,  1290,  1290,  1299,  1302,  1309,  1315,  1317,  1331,
    1334,  1334,  1344,  1344,  1352,  1354,  1359,  1364,  1368,  1370,
    1374,  1374,  1377,  1377,  1384,  1389,  1393,  1395,  1400,  1404,
    1406,  1411,  1415,  1417,  1422,  1427,  1431,  1433,  1437,  1444,
    1448,  1456,  1456,  1459,  1459,  1465,  1465,  1471,  1472,  1476,
    1476,  1481,  1483,  1487,  1490,  1492,  1496,  1500,  1504,  1510,
    1514,  1518,  1521,  1523,  1527,  1531,  1536,  1538,  1544,  1547,
    1549,  1555,  1556,  1562,  1566,  1567,  1571,  1572,  1576,  1577,
    1581,  1582,  1583,  1584,  1588,  1592,  1595,  1598,  1601,  1607,
    1611,  1614,  1616,  1620,  1623,  1625,  1629,  1630,  1634,  1638,
    1639,  1643,  1644,  1645,  1649,  1654,  1655,  1659,  1659,  1672,
    1697,  1700,  1703,  1706,  1709,  1716,  1719,  1724,  1728,  1735,
    1736,  1740,  1743,  1747,  1750,  1756,  1757,  1761,  1764,  1767,
    1770,  1773,  1774,  1780,  1785,  1794,  1801,  1804,  1812,  1821,
    1828,  1831,  1838,  1843,  1854,  1857,  1861,  1864,  1867,  1870,
    1873,  1876,  1879,  1882,  1888,  1893,  1902,  1905,  1912,  1915,
    1922,  1925,  1930,  1933,  1937,  1951,  1954,  1962,  1971,  1974,
    1981,  1984,  1987,  1990,  1994,  1995,  1996,  1997,  2000,  2003,
    2006,  2009,  2013,  2019,  2022,  2025,  2028,  2031,  2034,  2037,
    2041,  2044,  2047,  2050,  2053,  2056,  2059,  2062,  2063,  2066,
    2069,  2072,  2075,  2078,  2081,  2084,  2087,  2090,  2093,  2096,
    2099,  2102,  2105,  2108,  2111,  2114,  2117,  2120,  2123,  2126,
    2130,  2133,  2136,  2139,  2142,  2145,  2148,  2151,  2154,  2157,
    2158,  2159,  2165,  2168,  2175,  2182,  2185,  2189,  2195,  2202,
    2209,  2212,  2216,  2216,  2228,  2232,  2236,  2239,  2242,  2245,
    2248,  2254,  2260,  2263,  2267,  2277,  2280,  2285,  2293,  2300,
    2304,  2312,  2316,  2320,  2321,  2322,  2326,  2327,  2328,  2332,
    2333,  2334,  2338,  2339,  2340,  2344,  2345,  2349,  2350,  2351,
    2352,  2356,  2357,  2361,  2362,  2366,  2367
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
     165,   166,   167,   168,   169
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int MapSetParser::yyeof_ = 0;
  const int MapSetParser::yylast_ = 2081;
  const int MapSetParser::yynnts_ = 244;
  const int MapSetParser::yyempty_ = -2;
  const int MapSetParser::yyfinal_ = 3;
  const int MapSetParser::yyterror_ = 1;
  const int MapSetParser::yyerrcode_ = 256;
  const int MapSetParser::yyntokens_ = 170;

  const unsigned int MapSetParser::yyuser_token_number_max_ = 424;
  const MapSetParser::token_number_type MapSetParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 4704 "lib/MapSetParser/MapSetParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 2373 "lib/MapSetParser/MapSetParser.ypp"
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
	curResultSet(NULL), curResult(NULL), curExprList(NULL), 
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


