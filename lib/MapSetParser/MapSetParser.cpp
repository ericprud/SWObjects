
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
#line 307 "lib/MapSetParser/MapSetParser.ypp"

#include "../MapSetScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 447 "lib/MapSetParser/MapSetParser.ypp"

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
#line 462 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root = new MapSet();
	driver.root->sharedVars = MapSet::e_PROMISCUOUS;
      }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 480 "lib/MapSetParser/MapSetParser.ypp"
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
#line 489 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->driver = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 492 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->server = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 495 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->user = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 498 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->password = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 501 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->database = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 504 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->stemURI = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 509 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.sharedVarsSet = true;
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 513 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.lastRuleTermSet = false;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 519 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_PROMISCUOUS;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 522 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_VARNAMES;
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 525 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_DRACONIAN;
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 531 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = NULL;
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 538 "lib/MapSetParser/MapSetParser.ypp"
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
#line 573 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->keyMap[(yysemantic_stack_[(3) - (1)].p_RDFLiteral)->getLexicalValue()] = (yysemantic_stack_[(3) - (3)].p_RDFLiteral)->getLexicalValue();
    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 584 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->primaryKey = (yysemantic_stack_[(3) - (2)].p_RDFLiteral);
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 607 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 613 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 615 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 617 "lib/MapSetParser/MapSetParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 625 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 628 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 632 "lib/MapSetParser/MapSetParser.ypp"
    {
	  if ((yysemantic_stack_[(6) - (6)].p_BindingClause) != NULL)
	      (yysemantic_stack_[(6) - (4)].p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yysemantic_stack_[(6) - (6)].p_BindingClause), (yysemantic_stack_[(6) - (4)].p_WhereClause)->m_GroupGraphPattern);
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(6) - (2)].p_Project).distinctness, (yysemantic_stack_[(6) - (2)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(6) - (4)].p_WhereClause), (yysemantic_stack_[(6) - (5)].p_SolutionModifier))));
	  driver.curGraphName = (yysemantic_stack_[(6) - (1)].p_TTerm);
      }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 641 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 649 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 657 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 660 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 667 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 675 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 682 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 690 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 697 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 700 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 703 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 706 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 709 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 712 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 715 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 724 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 727 "lib/MapSetParser/MapSetParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 735 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 738 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 745 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = NULL;
      }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 747 "lib/MapSetParser/MapSetParser.ypp"
    {
	/* $3 is known to be a DefaultGraphPattern because of grammar restrictions. */
	if ((yysemantic_stack_[(8) - (8)].p_BindingClause) != NULL)
	    (yysemantic_stack_[(8) - (6)].p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yysemantic_stack_[(8) - (8)].p_BindingClause), (yysemantic_stack_[(8) - (6)].p_WhereClause)->m_GroupGraphPattern);
	Construct* constr = new Construct((DefaultGraphPattern*)((yysemantic_stack_[(8) - (3)].p_BasicGraphPattern) ? (yysemantic_stack_[(8) - (3)].p_BasicGraphPattern) : new DefaultGraphPattern()), (yysemantic_stack_[(8) - (5)].p_DatasetClauses), (yysemantic_stack_[(8) - (6)].p_WhereClause), (yysemantic_stack_[(8) - (7)].p_SolutionModifier));
	driver.root->maps.push_back(LabeledConstruct((yysemantic_stack_[(8) - (1)].p_TTerm), constr));
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 757 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (2)].p_TTerm);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 763 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = NULL;
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 771 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 774 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 782 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 794 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 800 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 806 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 813 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.ensureGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 827 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 834 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 842 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 850 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 858 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 866 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 873 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 876 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 883 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 886 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 889 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 892 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 898 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 904 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 907 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 919 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 926 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 930 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 940 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 948 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 951 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 959 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 968 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 975 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 979 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 987 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 995 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1002 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1008 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1015 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1017 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1025 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1031 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1034 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1040 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.startBindingRow(); // @@ push down to _Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star?
      }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1042 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1045 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1057 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1060 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1063 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1066 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1069 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1072 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1075 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1081 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1084 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1091 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1093 "lib/MapSetParser/MapSetParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1175 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.ensureGraphPattern(), (yysemantic_stack_[(1) - (1)].p_BindingClause)) : (yysemantic_stack_[(1) - (1)].p_BindingClause);
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1181 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1185 "lib/MapSetParser/MapSetParser.ypp"
    {
	  OptionalGraphPattern* ret = new OptionalGraphPattern(driver.ensureGraphPattern());
	  if (driver.curFilter) {
	      driver.curFilter->copyExpressionsTo(ret);
	      delete driver.curFilter;
	      driver.curFilter = NULL;
	  }
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), ret);
      }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 1197 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 1201 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 1203 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1206 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 1214 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 1218 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 1220 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 1223 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(7) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(7) - (6)].p_TTerm), driver.curOp, (yysemantic_stack_[(7) - (5)].p_Silence), driver.atomFactory, false));
	  driver.curGraphName = (yysemantic_stack_[(7) - (4)].p_TTerm);
      }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 1231 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = new Bind(driver.ensureGraphPattern(), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 1237 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 1241 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 1243 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 1251 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 1255 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 1257 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 1265 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 1270 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.ensureGraphPattern());
      }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 1283 "lib/MapSetParser/MapSetParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    driver.ensureGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 1299 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1307 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1311 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1314 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yysemantic_stack_[(6) - (4)].p_Expressions);
      }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1321 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 1324 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 1331 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 1339 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 1353 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 1356 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 1359 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(5) - (3)].p_Expressions);
      }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 1367 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 1369 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 1397 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 1400 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 1460 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 1467 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 1471 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 1479 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 1482 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 1488 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 1499 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 1527 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 1554 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 1561 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 1572 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 1579 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 1615 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 1618 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 1621 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 1624 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 1682 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 1686 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 1695 "lib/MapSetParser/MapSetParser.ypp"
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

  case 304:

/* Line 678 of lalr1.cc  */
#line 1720 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 1723 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 1726 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 1729 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 1732 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 1739 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 1747 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 1751 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 1763 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 1770 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 1773 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 1784 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 1787 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 1790 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 1793 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 1797 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 1808 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 1817 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 1824 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 1827 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 1835 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 1844 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 1851 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 1854 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 1866 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_GeneralComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_GeneralComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_GeneralComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 1877 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 1884 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 1887 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 1890 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 1893 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 1896 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 1899 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 1902 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 1905 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 1916 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 1925 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 1928 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 1935 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 1938 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 1945 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 1953 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 1956 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 1960 "lib/MapSetParser/MapSetParser.ypp"
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

  case 359:

/* Line 678 of lalr1.cc  */
#line 1974 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 1977 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 1985 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 1994 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 1997 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 2004 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 2007 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 2010 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 2020 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 2023 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 2026 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 2029 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 2036 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 2042 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 2045 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 2048 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 2051 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 2054 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 2057 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 2060 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 2064 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 2067 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 2070 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 2073 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ciel, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 2076 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 2079 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 2082 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 2086 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 2089 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 2092 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 2095 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 2098 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 2101 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 2104 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 2107 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 2110 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 2113 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 2116 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 2119 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 2122 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 2125 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 2128 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 2131 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 2134 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 2137 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha224, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 2140 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 2143 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 2146 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 2149 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 2153 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 2156 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 2159 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 2162 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 2165 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 2168 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 2171 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 2174 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 2177 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 2188 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 2191 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 2198 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 2205 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 2212 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 2218 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.ensureGraphPattern(), NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 2225 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.ensureGraphPattern(), NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 2232 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 2235 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 2239 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 2242 "lib/MapSetParser/MapSetParser.ypp"
    {
	  // x = new ArgList($2, driver.curExprList);
	  delete driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(7) - (5)].p_Expressions);
	  w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // $$ = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group-concat, $3, $4.p_Expression, $4.separator));
    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 2252 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
	driver.countStar = true;
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 2260 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 2263 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 2266 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 2269 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 2272 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 2278 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 2284 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 2291 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 2301 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 2309 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 2317 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 2324 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 2328 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 2336 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 3139 "lib/MapSetParser/MapSetParser.cpp"
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
  const short int MapSetParser::yypact_ninf_ = -649;
  const short int
  MapSetParser::yypact_[] =
  {
      -649,    60,    52,  -649,   -96,  -649,  -649,  -649,  -649,   351,
      90,   -90,    39,    39,    39,    39,    39,    46,    66,    74,
      78,    32,  -649,  -649,  -649,  -649,  -649,    39,  -649,  -649,
    -649,  -649,  -649,   -70,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,    39,  -649,    92,  -649,  -649,  -649,  -649,
    -649,   333,  -649,    78,   333,  -649,  -649,   106,   -26,    39,
      46,  -649,  -649,  -649,  -649,   100,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,   123,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,   129,  -649,  -649,  -649,  -649,
       2,   892,  -649,  -649,    26,  -649,  -649,   128,  -649,  -649,
    -649,   232,  -649,  -649,    39,  -649,  -649,  -649,  -649,  -649,
    -649,   136,  -649,   145,  -649,  -649,  -649,  -649,   157,  -649,
      20,  -649,    75,  -649,   232,  -649,  -649,    75,  1317,    75,
     -12,  -649,  -649,   122,   177,  -649,   163,  1317,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,  1282,  -649,  -649,  -649,
      46,  -649,  -649,  -649,  -649,  -649,   194,   190,   131,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  1805,
    -649,  -649,  -649,  1908,   202,  -649,  1118,   178,   187,  1442,
     162,   201,   205,   -16,   -15,   210,   211,   212,   177,   213,
     215,   217,   219,   222,   223,   233,   234,   238,   243,   245,
     -15,   246,   247,   249,   124,   251,   126,   253,   256,   257,
     258,   262,   263,   266,   267,   268,   269,   271,   273,   275,
     276,   277,   282,   286,   287,   289,   290,   291,   292,  1805,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,   -14,  -649,
    1442,  1908,  -649,  -649,  -649,  -649,  -649,   307,    63,  -649,
    -649,   318,   303,  -649,  -649,  -649,   298,  -649,  -649,    75,
    -649,  1317,  -649,  1563,  1563,  1563,   304,  -649,  -649,  -649,
    -649,   306,  -649,  -649,   259,  -649,  -649,  -649,  -649,   373,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,   324,  -649,  -649,
    -649,  -649,   -14,   177,  1442,  1442,  1442,  -649,  -649,  1442,
    -649,  -649,  1442,  1442,  1442,  -649,  1442,  1442,  1442,  1442,
     -90,  1442,  1442,  1442,  1442,  1442,  1442,  -649,  1442,  1442,
    1442,  -649,  1442,  -649,  1442,  1442,  1442,  1442,  1442,  1442,
    1442,  1442,  1442,  1442,  1442,  1442,  1442,  1442,  1442,  1442,
    1442,  1442,  1442,  1442,  1442,  1442,  -649,   325,  -649,  -649,
     -27,   326,  -649,  1258,   220,   224,  -649,  -649,   317,   341,
      94,  -649,  -649,    18,   232,  -649,  -649,    75,   160,  -649,
    -649,  1317,  -649,  -649,  -649,  -649,   325,   325,   -90,  -649,
     330,   320,   344,  1442,  1442,  1442,  1442,  1442,  1442,   305,
     -15,  -649,  -649,   186,     7,   325,  -649,  -649,  -649,   359,
     360,   361,  -649,   355,   356,   358,   367,   368,   362,   374,
     375,   365,   378,   382,   384,   385,   387,   386,   396,   397,
     400,   401,   402,   403,   404,   411,   413,   414,   407,   416,
     417,   418,   415,   419,   421,   424,   425,   426,   427,   420,
     429,   430,   431,  -649,  1442,  -649,  -649,  -649,  -649,  -649,
    1258,  -649,   433,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,  1094,   435,  -649,  -649,
    -649,  -649,  1908,   456,  -649,  -649,   454,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,    10,  -649,
      59,    49,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,    14,  -649,  -649,  -649,  -649,   853,  1442,  -649,  -649,
    1442,  -649,  1442,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
     -15,  -649,  1442,  1442,     7,  -649,  -649,  -649,  1442,  1442,
    -649,  1442,  -649,  -649,  -649,  -649,  1442,  1442,  1442,  -649,
    -649,  1442,  -649,  -649,  1442,  -649,  -649,  -649,  -649,  1442,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,  1442,  -649,  -649,
    -649,  1442,  -649,  -649,  -649,  1442,  -649,  -649,  -649,  -649,
    -649,  -649,  1442,  -649,  -649,  -649,  -649,   -21,  -649,  -649,
    -649,  1442,  -649,  -649,  1684,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,   122,  -649,  -649,   177,  -649,  -649,  1442,
    -649,   232,   177,   459,   111,  -649,    84,  -649,  -649,  -649,
    -649,  -649,  -649,  1317,   398,   438,  -649,    -7,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,   463,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,   465,    16,   458,   467,
     468,   469,   470,   464,   471,   464,   473,   474,  -649,  -649,
    -649,  -649,  -649,   259,  -649,   190,   117,  -649,  -649,   177,
     428,  -649,  -649,  -649,  -649,   476,  -649,  -649,  -649,  -649,
    -649,    10,  -649,    10,  -649,   376,  -649,  -649,    -1,  -649,
     472,  -649,  -649,  1442,  -649,  1442,  -649,  -649,  -649,  -649,
    -649,   479,  -649,   482,  -649,  -649,    28,  1585,   483,  -649,
    -649,   511,  -649,   -90,   480,  -649,   432,   478,  -649,  -649,
     491,  -649,   -17,  -649,   455,  -649,   492,  -649,   493,  -649,
    -649,  -649,  -649,  -649,   731,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,   177,  -649,   117,   495,  -649,  -649,   111,  -649,
     160,  -649,  -649,  -649,  -649,   494,   481,  -649,  -649,  -649,
    -649,  -649,   177,  -649,   177,  -649,  -649,  -649,  -649,  -649,
      39,  -649,  -649,  1317,  -649,  -649
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  MapSetParser::yydefact_[] =
  {
         2,     0,    37,     1,     0,     4,    39,    38,    41,     6,
      36,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     3,     5,    42,    40,   319,   320,     0,   471,   473,
     472,   474,     9,   455,    10,    11,    12,    13,   475,   478,
     477,    14,   476,     0,    15,    29,    28,    18,    20,    19,
      16,    21,    24,    17,     0,     7,    75,     0,     0,     0,
       0,   453,   454,   456,   451,     0,    33,    26,    30,   469,
     470,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     479,   480,   326,     0,    22,   322,   323,   457,   458,   459,
     324,   321,   325,    25,    73,     0,    43,     8,   452,    35,
       0,     0,   206,    71,     0,    31,    34,     0,    23,   315,
     316,   208,    76,    44,     0,   304,   305,   306,   307,   308,
     301,     0,   209,   212,   216,   300,   299,   310,     0,   214,
      85,    32,     0,   207,   208,   213,   210,   226,   309,     0,
       0,    86,    77,    88,     0,   234,     0,   309,   233,   317,
     318,   211,   227,   217,   225,   314,   309,   311,   313,   215,
       0,    78,    79,    80,    81,    83,     0,    48,    90,    89,
     145,    84,   302,   223,   230,   232,   303,   312,    82,     0,
     125,    72,    49,     0,    92,    91,   150,   218,   228,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,   100,   102,    99,   423,   391,   424,   425,     0,   127,
       0,   103,   104,   106,   193,   191,   192,     0,    94,    93,
     147,     0,     0,   148,   155,   151,   159,   237,   235,   220,
     224,   309,   231,     0,     0,     0,     0,   440,   441,   442,
     443,     0,   444,   374,    56,   327,   330,   334,   336,   338,
     348,   359,   362,   367,   368,   369,   375,     0,   370,   371,
     372,   373,   449,     0,     0,     0,     0,   427,   384,     0,
     203,   413,     0,     0,     0,   432,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   390,     0,     0,
       0,   385,     0,   406,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    98,   198,   195,   194,
       0,     0,   105,     0,     0,     0,    87,    95,   119,   121,
      53,    46,   146,   149,   150,   160,   157,   226,     0,   221,
     222,   309,   229,   365,   366,   364,   198,   198,     0,    57,
       0,   328,   332,     0,     0,     0,     0,     0,     0,     0,
       0,   337,   339,   349,   361,   198,   450,   448,   433,     0,
       0,     0,   204,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   199,     0,   134,   128,   376,   112,   113,
     107,   108,     0,   110,   111,   115,   116,   123,   124,   117,
     120,   118,   122,    51,    52,    54,     0,    85,   171,   175,
     169,   180,     0,     0,   168,   156,   152,   162,   164,   165,
     167,   163,   161,   184,   166,   158,   250,   238,     0,   280,
       0,     0,   236,   239,   241,   242,   251,   253,   256,   265,
     260,   263,   278,   252,   279,   219,     0,     0,    55,   101,
       0,   331,     0,   335,   340,   341,   342,   343,   344,   345,
       0,   346,     0,     0,   354,   360,   350,   351,     0,     0,
     363,     0,   382,   383,   426,   201,     0,     0,     0,   377,
     378,     0,   380,   381,     0,   418,   419,   420,   421,     0,
     422,   407,   399,   412,   405,   389,   411,     0,   404,   388,
     403,     0,   410,   402,   395,     0,   387,   401,   394,   386,
     393,   409,     0,   392,   408,   400,   196,     0,   109,   114,
      70,     0,    66,    67,    69,    50,    62,    59,    61,    60,
      63,    64,    65,    88,   172,   176,     0,   181,   190,     0,
     153,   150,     0,     0,   288,   296,     0,   281,   283,   290,
     292,   295,   266,   309,   254,   258,   274,     0,   276,   275,
     262,   264,   267,   438,   439,     0,   436,   329,   333,   347,
     356,   357,   355,   358,   352,   353,     0,     0,     0,     0,
       0,     0,     0,   429,     0,   429,     0,     0,   201,   126,
     131,   133,   135,    56,    68,    48,     0,   177,   170,     0,
       0,   154,   188,   282,   289,     0,   285,   294,   297,   293,
     248,     0,   257,     0,   261,     0,   298,   277,     0,   434,
     446,   435,   205,     0,   202,     0,   415,   416,   379,   417,
     430,     0,   396,     0,   397,   398,     0,     0,     0,    47,
     173,   143,   182,     0,   185,   291,   287,   240,   255,   259,
       0,   271,     0,   272,     0,   447,     0,   200,     0,   428,
     431,   197,   140,   141,     0,   129,   142,   137,   138,   139,
     136,    58,     0,   144,     0,     0,   186,   189,     0,   286,
     245,   249,   273,   268,   270,     0,     0,   437,   414,   132,
     130,   174,     0,   179,     0,   284,   243,   246,   247,   269,
       0,   178,   187,   309,   445,   244
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yypgoto_[] =
  {
      -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,   489,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,  -122,  -649,  -649,
    -649,  -649,  -119,  -649,   -48,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,   389,    73,  -649,   -52,
    -649,  -649,  -649,  -649,  -649,  -649,   314,  -649,  -649,   308,
    -649,  -649,    95,  -649,  -649,  -649,  -649,  -649,  -649,   185,
     188,   184,  -649,  -649,  -649,  -649,  -649,  -649,  -176,  -649,
    -190,  -649,  -649,  -649,  -361,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -336,  -177,   260,  -649,  -347,  -547,   -98,
    -198,  -649,  -649,  -649,   434,  -649,  -649,  -649,  -649,  -649,
    -649,   -83,  -649,  -649,  -649,  -649,  -649,   189,  -372,  -649,
    -649,   293,   294,  -649,  -649,  -649,  -649,  -649,  -189,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,    67,  -649,  -649,
    -649,  -114,  -649,  -649,    68,  -649,  -113,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    -595,  -649,  -649,  -648,  -110,  -649,  -649,  -649,  -649,  -649,
    -649,  -105,   -91,  -634,   -11,    31,   520,  -649,  -649,  -649,
      51,  -649,  -649,    53,  -649,  -649,  -649,    57,  -649,  -649,
      42,  -649,  -649,  -649,  -350,  -649,  -348,   -39,  -157,  -168,
    -649,  -649,   -82,  -649,  -649,  -649,  -459,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,    -9,  -649,  -649,  -649,    33,  -649,
     174,   175,    58,  -191,    47,  -649,  -649
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yydefgoto_[] =
  {
        -1,     1,     2,     9,    21,    22,    50,    83,    52,    53,
      44,    45,    67,    68,   106,   100,    46,     5,     6,    10,
       7,    24,    58,   104,   260,   261,   477,   181,   371,   475,
     476,   389,   390,   592,   593,   594,   595,    55,   112,    56,
      57,   130,   142,   161,   162,   163,   164,   143,   144,   167,
     168,   184,   258,   366,   169,   239,   240,   185,   251,   252,
     259,   460,   461,   462,   463,   464,   367,   469,   471,   368,
     369,   182,   249,   360,   734,   662,   707,   587,   735,   744,
     171,   186,   262,   263,   264,   611,   485,   373,   265,   375,
     376,   486,   487,   606,   488,   604,   666,   742,   489,   605,
     667,   711,   490,   491,   607,   669,   492,   493,   612,   747,
     764,   714,   494,   253,   254,   359,   658,   454,   694,   647,
     311,   545,   103,   111,   121,   122,   135,   136,   123,   139,
     137,   152,   379,   380,   270,   187,   153,   154,   173,   272,
     188,   174,   147,   266,   378,   377,   502,   623,   503,   767,
     773,   768,   751,   717,   497,   504,   505,   506,   507,   682,
     624,   508,   684,   625,   509,   630,   510,   631,   754,   723,
     687,   632,   511,   512,   617,   749,   716,   674,   675,   618,
     619,   678,   620,   688,   155,   125,   132,   126,   127,   128,
     156,   175,   158,   148,   283,   110,   284,   285,   521,   391,
     286,   523,   392,   287,   288,   401,   402,   289,   290,   534,
     540,   643,   535,   403,   291,   404,   292,   293,   294,   295,
     308,   244,   701,   245,   246,   247,   296,   690,   635,   297,
     725,   726,   298,   407,   299,    62,    63,    64,   300,    87,
      88,    89,   301,    33,   302,    42,    92
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int MapSetParser::yytable_ninf_ = -310;
  const short int
  MapSetParser::yytable_[] =
  {
        27,   124,   241,    32,    34,    35,    36,    37,   315,   515,
     108,   243,   327,   495,   455,   256,   160,   599,    59,   676,
     129,   659,    60,   660,   124,   753,   255,   465,   306,   309,
     357,   538,   710,   157,    65,   478,   479,   720,   626,   516,
     517,   721,    85,   129,   105,    85,   685,   140,    54,   146,
      97,   177,   722,   180,   498,   627,   159,   -74,   541,  -183,
       3,   692,   241,   141,    41,   499,     8,   480,   481,   693,
     482,   243,     4,   731,   755,   539,   267,    25,    26,   500,
     628,   693,    84,   256,    86,    94,    47,    86,    48,    49,
     109,   107,    85,   498,   255,   268,   364,   365,    91,    61,
     109,    91,    85,   614,   499,   131,   700,    98,   700,    90,
     762,    23,    90,   408,   615,   501,   473,   474,   500,    51,
     629,   149,    43,   109,   465,    85,   149,   109,   149,    85,
     145,    95,   686,    66,    86,   599,   109,    96,    85,   677,
      25,    26,   686,   483,    86,   109,   608,    85,    91,   661,
      38,    39,    40,   765,   307,   310,   358,    99,    91,    90,
      28,    29,    30,    31,   616,   101,   615,    86,   242,    90,
     102,    86,    38,    39,    40,   109,   114,    85,   133,   150,
      86,    91,   640,   641,   150,    91,   150,   165,   113,    86,
     644,   645,    90,   134,    91,   256,    90,    28,    29,    30,
      31,   138,   531,    91,   498,    90,   255,   165,    38,    39,
      40,    38,    39,    40,    90,   499,   616,   166,   170,    86,
     172,    38,    39,    40,   179,   180,   248,   183,   242,   500,
     248,   257,   269,    91,   383,   384,   385,    38,    39,    40,
     271,   303,    25,    26,    90,   304,    38,    39,    40,   305,
     671,   680,   532,   533,   312,   313,   314,   316,   149,   317,
     109,   318,    85,   319,   267,   501,   320,   321,   115,   116,
     117,   118,   119,    38,    39,    40,  -309,   322,   323,    38,
      39,    40,   324,   268,    25,    26,   248,   325,   120,   326,
     328,   329,   256,   330,   331,   332,   333,   334,   248,   596,
     335,   336,   337,   255,    86,   589,   338,   339,   598,   420,
     340,   341,   342,   343,   256,   344,   150,   345,    91,   346,
     347,   348,    38,    39,    40,   255,   349,    25,    26,    90,
     350,   351,   639,   352,   353,   354,   355,   363,    74,    75,
      76,    77,    78,    79,   370,   372,   374,   453,   386,   456,
     387,   365,   466,   388,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   109,    20,    85,   149,   513,   405,   467,
     109,   457,    85,   468,   364,   519,   530,   518,   520,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      28,    29,    30,    31,    38,    39,    40,    80,    81,    25,
      26,   775,    82,   522,   542,   543,   544,    86,   546,   547,
     248,   548,   549,   550,    86,   551,   668,   596,   554,   552,
     553,    91,   672,   555,   150,   514,   598,   556,    91,   557,
     558,   560,    90,   393,   394,   395,   396,   397,   398,    90,
     559,   561,   562,   399,   400,   563,   564,   565,   566,   466,
     524,   525,   526,   527,   528,   529,   568,   567,   569,   570,
     571,   572,   573,   574,   576,   597,   577,   600,   575,   578,
     579,   580,   581,   582,   583,   584,   585,   250,   141,   712,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    28,    29,    30,    31,    38,    39,    40,    80,    81,
     609,   267,   610,    82,   673,   681,   683,   248,   689,   601,
     691,   695,   696,   697,   698,   699,   702,   693,   704,   705,
     268,   715,   713,   248,   729,   686,   724,   730,   741,   248,
     743,   746,   750,   752,   602,   756,   769,   757,   758,   748,
     763,   770,    93,   709,   708,   514,   664,   621,   514,   178,
     603,   665,   761,   356,   472,   588,   470,   484,   760,   362,
     706,   766,   406,   381,   382,   613,   496,   718,   151,   622,
     719,   637,   771,   703,   772,   638,   642,   536,   537,   774,
       0,     0,     0,   597,     0,   600,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,     0,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   109,     0,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   601,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   248,     0,     0,    86,     0,     0,     0,     0,     0,
       0,     0,   602,     0,     0,   149,    86,     0,    91,     0,
       0,   621,     0,   679,     0,     0,     0,     0,     0,    90,
      91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   736,     0,   737,     0,
       0,     0,   745,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   150,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   736,     0,   737,     0,     0,   514,     0,
     514,     0,     0,   149,     0,     0,     0,     0,     0,   513,
     738,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   740,     0,     0,     0,     0,     0,
       0,     0,   109,     0,    85,   739,     0,   738,     0,     0,
     361,     0,     0,     0,     0,     0,   759,   732,   733,     0,
       0,   740,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   150,   739,     0,     0,   621,     0,   514,     0,     0,
       0,     0,     0,     0,     0,     0,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      91,     0,     0,     0,   409,   410,   411,     0,     0,   412,
       0,    90,   413,   414,   415,     0,   416,   417,   418,   419,
       0,   421,   422,   423,   424,   425,   426,     0,   427,   428,
     429,     0,   430,     0,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,     0,   633,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    28,
      29,    30,    31,    38,    39,    40,     0,   250,    25,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   273,
     274,     0,   275,   190,     0,   191,   192,   193,   194,   195,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,     0,   210,     0,     0,     0,
     276,   277,   278,   279,   280,   281,   282,   211,     0,     0,
       0,     0,     0,     0,     0,   212,     0,   213,     0,     0,
     214,   215,     0,   216,   586,   217,   218,   219,     0,   220,
     221,     0,   222,     0,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    28,    29,    30,    31,    38,    39,    40,     0,     0,
      25,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   634,   636,     0,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      28,    29,    30,    31,    38,    39,    40,    80,    81,    25,
      26,   646,    82,     0,     0,     0,   648,   649,   650,     0,
       0,   651,     0,     0,   652,     0,     0,     0,     0,   653,
       0,     0,     0,     0,     0,     0,     0,   654,     0,     0,
       0,   655,     0,     0,     0,   656,     0,     0,     0,     0,
       0,     0,   657,     0,     0,     0,     0,     0,     0,     0,
       0,   663,     0,     0,     0,     0,     0,     0,   590,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   670,
       0,     0,     0,     0,     0,     0,     0,     0,   591,     0,
       0,     0,     0,     0,   -45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   115,   116,   117,   118,   119,     0,
       0,     0,  -309,     0,   190,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   120,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,     0,   210,     0,     0,
       0,   276,   277,   278,   279,   280,   281,   282,   211,     0,
       0,     0,     0,     0,     0,     0,   212,     0,   213,     0,
       0,   214,   215,   727,   216,   728,   217,   218,   219,     0,
     220,   221,     0,   222,     0,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    28,    29,    30,    31,    38,    39,    40,     0,
       0,    25,    26,     0,     0,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    28,    29,    30,    31,
      38,    39,    40,    80,    81,    25,    26,     0,    82,   458,
     459,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   250,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   115,   116,
     117,   118,   119,     0,     0,     0,     0,   176,   190,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   120,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
       0,   210,     0,   115,   116,   117,   118,   119,     0,     0,
       0,     0,   211,     0,     0,     0,     0,     0,     0,     0,
     212,     0,   213,   120,     0,   214,   215,     0,   216,     0,
     217,   218,   219,     0,   220,   221,     0,   222,     0,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,    39,    40,     0,     0,    25,    26,     0,     0,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      28,    29,    30,    31,    38,    39,    40,    80,    81,    25,
      26,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    28,    29,    30,    31,    38,
      39,    40,    80,    81,    25,    26,   250,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   273,   274,
       0,   275,   190,     0,   191,   192,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,     0,   210,     0,     0,     0,   276,
     277,   278,   279,   280,   281,   282,   211,     0,     0,     0,
       0,     0,     0,     0,   212,     0,   213,     0,     0,   214,
     215,     0,   216,     0,   217,   218,   219,     0,   220,   221,
       0,   222,     0,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      28,    29,    30,    31,    38,    39,    40,   250,     0,    25,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   732,   733,   190,     0,   191,   192,   193,   194,   195,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,     0,   210,     0,     0,     0,
     276,   277,   278,   279,   280,   281,   282,   211,     0,     0,
       0,     0,     0,     0,     0,   212,     0,   213,     0,     0,
     214,   215,     0,   216,     0,   217,   218,   219,     0,   220,
     221,     0,   222,     0,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    28,    29,    30,    31,    38,    39,    40,   591,     0,
      25,    26,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    28,    29,    30,    31,    38,    39,    40,
       0,     0,    25,    26,   190,     0,   191,   192,   193,   194,
     195,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,     0,   210,     0,     0,
       0,   276,   277,   278,   279,   280,   281,   282,   211,     0,
       0,     0,     0,     0,     0,     0,   212,     0,   213,     0,
       0,   214,   215,     0,   216,     0,   217,   218,   219,     0,
     220,   221,     0,   222,     0,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    28,    29,    30,    31,    38,    39,    40,   189,
       0,    25,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   190,     0,   191,   192,   193,
     194,   195,   196,   197,   198,     0,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,     0,   210,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   211,
       0,     0,     0,     0,     0,     0,     0,   212,     0,   213,
       0,     0,   214,   215,     0,   216,     0,   217,   218,   219,
       0,   220,   221,     0,   222,     0,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   250,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,    39,    40,
       0,     0,    25,    26,     0,     0,     0,     0,   190,     0,
     191,   192,   193,   194,   195,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
       0,   210,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   211,     0,     0,     0,     0,     0,     0,     0,
     212,     0,   213,     0,     0,   214,   215,     0,   216,     0,
     217,   218,   219,     0,   220,   221,     0,   222,     0,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,    39,    40
  };

  /* YYCHECK.  */
  const short int
  MapSetParser::yycheck_[] =
  {
        11,   111,   179,    12,    13,    14,    15,    16,   198,   381,
     101,   179,   210,   374,    41,   183,    28,   476,    27,   614,
     111,    42,    92,    44,   134,    42,   183,   363,    44,    44,
      44,    24,   666,   138,    43,    17,    18,   685,    24,   386,
     387,    42,    51,   134,    42,    54,    53,    27,    16,   132,
      59,   156,    53,    35,    44,    41,   139,    25,   405,    41,
       0,    45,   239,    43,    17,    55,   162,    49,    50,    53,
      52,   239,    20,    45,   722,    68,   186,   167,   168,    69,
      66,    53,    51,   251,    51,    54,    12,    54,    14,    15,
     101,   100,   101,    44,   251,   186,    33,    34,    51,   169,
     111,    54,   111,    44,    55,   114,   653,    60,   655,    51,
     744,    21,    54,   303,    55,   105,    22,    23,    69,    41,
     106,   132,    56,   134,   460,   134,   137,   138,   139,   138,
      55,    25,   149,    41,   101,   594,   147,   163,   147,    55,
     167,   168,   149,   125,   111,   156,   482,   156,   101,   170,
     162,   163,   164,   748,   170,   170,   170,    57,   111,   101,
     158,   159,   160,   161,   105,    42,    55,   134,   179,   111,
      41,   138,   162,   163,   164,   186,    48,   186,    42,   132,
     147,   134,   532,   533,   137,   138,   139,   140,   162,   156,
     538,   539,   134,    48,   147,   363,   138,   158,   159,   160,
     161,    44,   400,   156,    44,   147,   363,   160,   162,   163,
     164,   162,   163,   164,   156,    55,   105,    95,    41,   186,
      57,   162,   163,   164,    30,    35,   179,    96,   239,    69,
     183,    29,    54,   186,   273,   274,   275,   162,   163,   164,
      53,    79,   167,   168,   186,    44,   162,   163,   164,    44,
     611,   623,    66,    67,    44,    44,    44,    44,   269,    44,
     271,    44,   271,    44,   374,   105,    44,    44,    36,    37,
      38,    39,    40,   162,   163,   164,    44,    44,    44,   162,
     163,   164,    44,   374,   167,   168,   239,    44,    56,    44,
      44,    44,   460,    44,   170,    44,   170,    44,   251,   476,
      44,    44,    44,   460,   271,   462,    44,    44,   476,   320,
      44,    44,    44,    44,   482,    44,   269,    44,   271,    44,
      44,    44,   162,   163,   164,   482,    44,   167,   168,   271,
      44,    44,   530,    44,    44,    44,    44,    30,   152,   153,
     154,   155,   156,   157,    26,    42,    48,    22,    44,   360,
      44,    34,   363,    94,     3,     4,     5,     6,     7,     8,
       9,    10,    11,   374,    13,   374,   377,   378,    44,   149,
     381,    45,   381,   149,    33,    45,    71,   388,    58,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   773,   170,    59,    45,    45,    45,   374,    53,    53,
     363,    53,    45,    45,   381,    53,   606,   594,    53,    45,
      45,   374,   612,    45,   377,   378,   594,    45,   381,    45,
      45,    45,   374,    60,    61,    62,    63,    64,    65,   381,
      53,    45,    45,    70,    71,    45,    45,    45,    45,   460,
     393,   394,   395,   396,   397,   398,    45,    53,    45,    45,
      53,    45,    45,    45,    45,   476,    45,   476,    53,    45,
      45,    45,    45,    53,    45,    45,    45,    44,    43,   669,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
      44,   611,    48,   170,    45,   107,    68,   460,    45,   476,
      45,    53,    45,    45,    45,    45,    45,    53,    45,    45,
     611,    45,    94,   476,    45,   149,    54,    45,    45,   482,
      19,    51,    54,    42,   476,    80,    42,    45,    45,   107,
      45,    60,    53,   665,   663,   498,   594,   500,   501,   160,
     477,   603,   742,   239,   369,   460,   368,   373,   734,   251,
     658,   750,   302,   269,   271,   498,   377,   681,   134,   501,
     683,   520,   762,   655,   764,   522,   534,   403,   403,   770,
      -1,    -1,    -1,   594,    -1,   594,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     611,    -1,   611,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   623,    -1,   623,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   594,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   594,    -1,    -1,   611,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   594,    -1,    -1,   666,   623,    -1,   611,    -1,
      -1,   614,    -1,   616,    -1,    -1,    -1,    -1,    -1,   611,
     623,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   623,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   707,    -1,   707,    -1,
      -1,    -1,   713,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   666,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   734,    -1,   734,    -1,    -1,   681,    -1,
     683,    -1,    -1,   744,    -1,    -1,    -1,    -1,    -1,   750,
     707,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   707,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   773,    -1,   773,   707,    -1,   734,    -1,    -1,
     250,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      -1,   734,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   744,   734,    -1,    -1,   748,    -1,   750,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   773,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     773,    -1,    -1,    -1,   304,   305,   306,    -1,    -1,   309,
      -1,   773,   312,   313,   314,    -1,   316,   317,   318,   319,
      -1,   321,   322,   323,   324,   325,   326,    -1,   328,   329,
     330,    -1,   332,    -1,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,    -1,    24,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,    44,   167,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    -1,    69,    70,    -1,    72,    73,    74,    75,    76,
      77,    78,    79,    -1,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    -1,    -1,    -1,
      97,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,    -1,   114,    -1,    -1,
     117,   118,    -1,   120,   454,   122,   123,   124,    -1,   126,
     127,    -1,   129,    -1,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,    -1,
     167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   516,   517,    -1,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   541,   170,    -1,    -1,    -1,   546,   547,   548,    -1,
      -1,   551,    -1,    -1,   554,    -1,    -1,    -1,    -1,   559,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   567,    -1,    -1,
      -1,   571,    -1,    -1,    -1,   575,    -1,    -1,    -1,    -1,
      -1,    -1,   582,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   591,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   609,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    44,    -1,    70,    -1,    72,    73,    74,    75,
      76,    77,    78,    79,    56,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    -1,    -1,
      -1,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,   114,    -1,
      -1,   117,   118,   693,   120,   695,   122,   123,   124,    -1,
     126,   127,    -1,   129,    -1,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    -1,
      -1,   167,   168,    -1,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,    -1,   170,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    45,    70,    -1,
      72,    73,    74,    75,    76,    77,    78,    79,    56,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    93,    -1,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     112,    -1,   114,    56,    -1,   117,   118,    -1,   120,    -1,
     122,   123,   124,    -1,   126,   127,    -1,   129,    -1,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     162,   163,   164,    -1,    -1,   167,   168,    -1,    -1,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    44,   170,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,
      -1,    69,    70,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    -1,    -1,    -1,    97,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,    -1,   114,    -1,    -1,   117,
     118,    -1,   120,    -1,   122,   123,   124,    -1,   126,   127,
      -1,   129,    -1,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    44,    -1,   167,
     168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    70,    -1,    72,    73,    74,    75,    76,
      77,    78,    79,    -1,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    -1,    -1,    -1,
      97,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,    -1,   114,    -1,    -1,
     117,   118,    -1,   120,    -1,   122,   123,   124,    -1,   126,
     127,    -1,   129,    -1,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    44,    -1,
     167,   168,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,    -1,   167,   168,    70,    -1,    72,    73,    74,    75,
      76,    77,    78,    79,    -1,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    -1,    -1,
      -1,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,   114,    -1,
      -1,   117,   118,    -1,   120,    -1,   122,   123,   124,    -1,
     126,   127,    -1,   129,    -1,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    44,
      -1,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,   114,
      -1,    -1,   117,   118,    -1,   120,    -1,   122,   123,   124,
      -1,   126,   127,    -1,   129,    -1,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,   164,
      -1,    -1,   167,   168,    -1,    -1,    -1,    -1,    70,    -1,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     112,    -1,   114,    -1,    -1,   117,   118,    -1,   120,    -1,
     122,   123,   124,    -1,   126,   127,    -1,   129,    -1,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     162,   163,   164
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  MapSetParser::yystos_[] =
  {
         0,   172,   173,     0,    20,   188,   189,   191,   162,   174,
     190,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      13,   175,   176,    21,   192,   167,   168,   365,   158,   159,
     160,   161,   405,   414,   405,   405,   405,   405,   162,   163,
     164,   415,   416,    56,   181,   182,   187,    12,    14,    15,
     177,    41,   179,   180,    16,   208,   210,   211,   193,   405,
      92,   169,   406,   407,   408,   405,    41,   183,   184,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     165,   166,   170,   178,   366,   405,   409,   410,   411,   412,
     413,   415,   417,   179,   366,    25,   163,   405,   415,    57,
     186,    42,    41,   293,   194,    42,   185,   405,   363,   365,
     366,   294,   209,   162,    48,    36,    37,    38,    39,    40,
      56,   295,   296,   299,   355,   356,   358,   359,   360,   363,
     212,   405,   357,    42,    48,   297,   298,   301,    44,   300,
      27,    43,   213,   218,   219,    55,   302,   313,   364,   365,
     415,   295,   302,   307,   308,   355,   361,   362,   363,   302,
      28,   214,   215,   216,   217,   415,    95,   220,   221,   225,
      41,   251,    57,   309,   312,   362,    45,   362,   217,    30,
      35,   198,   242,    96,   222,   228,   252,   306,   311,    44,
      70,    72,    73,    74,    75,    76,    77,    78,    79,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      93,   104,   112,   114,   117,   118,   120,   122,   123,   124,
     126,   127,   129,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   226,
     227,   285,   365,   390,   392,   394,   395,   396,   415,   243,
      44,   229,   230,   284,   285,   389,   390,    29,   223,   231,
     195,   196,   253,   254,   255,   259,   314,   355,   363,    54,
     305,    53,   310,    66,    67,    69,    97,    98,    99,   100,
     101,   102,   103,   365,   367,   368,   371,   374,   375,   378,
     379,   385,   387,   388,   389,   390,   397,   400,   403,   405,
     409,   413,   415,    79,    44,    44,    44,   170,   391,    44,
     170,   291,    44,    44,    44,   251,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,   291,    44,    44,
      44,   170,    44,   170,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,   227,    44,   170,   286,
     244,   367,   230,    30,    33,    34,   224,   237,   240,   241,
      26,   199,    42,   258,    48,   260,   261,   316,   315,   303,
     304,   313,   312,   388,   388,   388,    44,    44,    94,   202,
     203,   370,   373,    60,    61,    62,    63,    64,    65,    70,
      71,   376,   377,   384,   386,    44,   286,   404,   251,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     365,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,    22,   288,    41,   365,    45,    31,    32,
     232,   233,   234,   235,   236,   284,   365,   149,   149,   238,
     241,   239,   240,    22,    23,   200,   201,   197,    17,    18,
      49,    50,    52,   125,   242,   257,   262,   263,   265,   269,
     273,   274,   277,   278,   283,   255,   308,   325,    44,    55,
      69,   105,   317,   319,   326,   327,   328,   329,   332,   335,
     337,   343,   344,   365,   415,   309,   288,   288,   365,    45,
      58,   369,    59,   372,   378,   378,   378,   378,   378,   378,
      71,   291,    66,    67,   380,   383,   411,   412,    24,    68,
     381,   288,    45,    45,    45,   292,    53,    53,    53,    45,
      45,    53,    45,    45,    53,    45,    45,    45,    45,    53,
      45,    45,    45,    45,    45,    45,    45,    53,    45,    45,
      45,    53,    45,    45,    45,    53,    45,    45,    45,    45,
      45,    45,    53,    45,    45,    45,   367,   248,   233,   389,
      24,    44,   204,   205,   206,   207,   285,   365,   390,   397,
     405,   409,   413,   218,   266,   270,   264,   275,   284,    44,
      48,   256,   279,   328,    44,    55,   105,   345,   350,   351,
     353,   415,   335,   318,   331,   334,    24,    41,    66,   106,
     336,   338,   342,    24,   367,   399,   367,   371,   374,   291,
     385,   385,   381,   382,   387,   387,   367,   290,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   287,    42,
      44,   170,   246,   367,   205,   220,   267,   271,   251,   276,
     367,   255,   251,    45,   348,   349,   351,    55,   352,   415,
     309,   107,   330,    68,   333,    53,   149,   341,   354,    45,
     398,    45,    45,    53,   289,    53,    45,    45,    45,    45,
     289,   393,    45,   393,    45,    45,   290,   247,   203,   198,
     364,   272,   251,    94,   282,    45,   347,   324,   332,   337,
     354,    42,    53,   340,    54,   401,   402,   367,   367,    45,
      45,    45,    46,    47,   245,   249,   365,   405,   409,   413,
     415,    45,   268,    19,   250,   365,    51,   280,   107,   346,
      54,   323,    42,    42,   339,   354,    80,    45,    45,    45,
     249,   251,   364,    45,   281,   351,   319,   320,   322,    42,
      60,   251,   251,   321,   414,   309
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
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  MapSetParser::yyr1_[] =
  {
         0,   171,   173,   172,   174,   174,   175,   175,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   177,   177,
     177,   178,   178,   179,   180,   180,   181,   182,   182,   183,
     183,   184,   185,   186,   186,   187,   188,   189,   189,   190,
     190,   191,   193,   194,   192,   196,   197,   195,   198,   198,
     199,   200,   200,   201,   201,   202,   203,   203,   204,   205,
     205,   205,   205,   205,   205,   205,   205,   206,   206,   207,
     207,   209,   208,   210,   211,   211,   212,   212,   213,   214,
     214,   215,   216,   217,   218,   219,   219,   220,   221,   221,
     222,   222,   223,   223,   224,   224,   225,   226,   226,   227,
     227,   227,   227,   228,   229,   229,   230,   231,   232,   232,
     233,   233,   234,   234,   235,   236,   236,   237,   237,   238,
     238,   239,   239,   240,   241,   243,   242,   244,   244,   245,
     245,   247,   246,   246,   248,   248,   249,   249,   249,   249,
     249,   249,   249,   250,   250,   252,   251,   253,   253,   254,
     255,   255,   256,   256,   257,   258,   258,   259,   260,   261,
     261,   262,   262,   262,   262,   262,   262,   262,   262,   264,
     263,   266,   267,   268,   265,   270,   271,   272,   269,   273,
     275,   276,   274,   278,   279,   277,   281,   280,   282,   282,
     283,   284,   284,   284,   285,   286,   287,   286,   288,   288,
     289,   290,   290,   291,   292,   291,   294,   293,   295,   295,
     296,   297,   298,   298,   300,   299,   301,   299,   302,   303,
     304,   304,   305,   306,   306,   307,   308,   308,   309,   310,
     311,   311,   312,   313,   313,   315,   314,   316,   314,   318,
     317,   319,   319,   321,   320,   322,   322,   323,   324,   324,
     325,   326,   327,   328,   329,   330,   331,   331,   332,   333,
     334,   334,   335,   336,   336,   337,   337,   338,   339,   339,
     340,   340,   341,   341,   342,   342,   342,   342,   343,   344,
     344,   344,   344,   345,   346,   347,   347,   348,   349,   349,
     350,   350,   351,   352,   352,   353,   353,   353,   354,   355,
     355,   357,   356,   358,   359,   359,   359,   359,   359,   360,
     360,   361,   361,   362,   362,   363,   363,   364,   364,   365,
     365,   366,   366,   366,   366,   366,   366,   367,   368,   369,
     370,   370,   371,   372,   373,   373,   374,   375,   376,   376,
     377,   377,   377,   377,   377,   377,   377,   377,   378,   379,
     380,   380,   381,   381,   382,   382,   383,   383,   383,   384,
     384,   385,   386,   386,   387,   387,   387,   387,   388,   388,
     388,   388,   388,   388,   388,   388,   389,   390,   390,   390,
     390,   390,   390,   390,   390,   390,   390,   390,   390,   390,
     390,   390,   390,   390,   390,   390,   390,   390,   390,   390,
     390,   390,   390,   390,   390,   390,   390,   390,   390,   390,
     390,   390,   390,   390,   390,   390,   390,   390,   390,   390,
     390,   390,   390,   390,   390,   390,   391,   391,   392,   393,
     393,   394,   395,   396,   397,   397,   398,   397,   399,   399,
     400,   400,   400,   400,   400,   401,   402,   402,   403,   404,
     404,   405,   406,   407,   407,   408,   408,   409,   409,   409,
     410,   410,   410,   411,   411,   411,   412,   412,   412,   413,
     413,   414,   414,   414,   414,   415,   415,   416,   416,   417,
     417
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  MapSetParser::yyr2_[] =
  {
         0,     2,     0,     4,     0,     2,     0,     2,     4,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     0,     1,     4,     1,     2,     2,     0,     1,     0,
       1,     3,     3,     0,     2,     3,     2,     0,     1,     0,
       2,     2,     0,     0,     5,     0,     0,     6,     0,     1,
       3,     1,     1,     0,     1,     2,     0,     1,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     0,     8,     2,     0,     1,     0,     2,     2,     1,
       1,     1,     2,     1,     2,     0,     1,     4,     0,     1,
       0,     1,     0,     1,     0,     1,     3,     1,     2,     1,
       1,     4,     1,     2,     1,     2,     1,     3,     1,     2,
       1,     1,     1,     1,     2,     1,     1,     2,     2,     0,
       1,     0,     1,     2,     2,     0,     6,     0,     2,     1,
       2,     0,     4,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     0,     4,     1,     1,     2,
       0,     1,     0,     1,     3,     0,     2,     2,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       3,     0,     0,     0,     6,     0,     0,     0,     7,     6,
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
  const MapSetParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "IT_REWRITEVAR", "IT_DRIVER",
  "IT_SERVER", "IT_USER", "IT_PASSWORD", "IT_DATABASE", "IT_STEMURI",
  "IT_PRIMARYKEY", "IT_SHAREDVARS", "IT_PROMISCUOUS", "IT_INTERSECTION",
  "IT_DRACONIAN", "IT_VARNAMES", "IT_LABEL", "IT_GRAPH", "IT_SERVICE",
  "IT_SILENT", "IT_BASE", "IT_PREFIX", "IT_DISTINCT", "IT_REDUCED",
  "GT_TIMES", "IT_CONSTRUCT", "IT_SELECT", "IT_FROM", "IT_NAMED",
  "IT_ORDER", "IT_BY", "IT_ASC", "IT_DESC", "IT_LIMIT", "IT_OFFSET",
  "IT_BINDINGS", "IT_MEMBERS", "IT_STARTS", "IT_ENDS", "IT_ANY",
  "IT_UNORDERED", "GT_LCURLEY", "GT_RCURLEY", "IT_WHERE", "GT_LPAREN",
  "GT_RPAREN", "IT_UNDEF", "GT_MINUS_MINUS", "GT_DOT", "IT_OPTIONAL",
  "IT_MINUS", "IT_UNION", "IT_FILTER", "GT_COMMA", "GT_SEMI", "IT_a",
  "GT_LBRACKET", "GT_RBRACKET", "GT_OR", "GT_AND", "GT_EQUAL", "GT_NEQUAL",
  "GT_LT", "GT_GT", "GT_LE", "GT_GE", "GT_PLUS", "GT_MINUS", "GT_DIVIDE",
  "GT_NOT", "IT_NOT", "IT_IN", "IT_IRI", "IT_URI", "IT_BNODE",
  "IT_COALESCE", "IT_IF", "IT_STRLANG", "IT_STRDT", "IT_EXISTS",
  "IT_SEPARATOR", "IT_STR", "IT_LANG", "IT_LANGMATCHES", "IT_DATATYPE",
  "IT_BOUND", "IT_sameTerm", "IT_isIRI", "IT_isURI", "IT_isBLANK",
  "IT_isLITERAL", "IT_REGEX", "GT_DTYPE", "IT_CONCAT", "IT_AS", "IT_GROUP",
  "IT_HAVING", "IT_COUNT", "IT_SUM", "IT_MIN", "IT_MAX", "IT_AVG",
  "IT_GROUP_CONCAT", "IT_SAMPLE", "IT_isNUMERIC", "GT_CARROT", "GT_OPT",
  "GT_PIPE", "IT_WITH", "IT_DEFAULT", "IT_ALL", "IT_USING", "IT_MD5",
  "IT_TO", "IT_YEAR", "IT_ADD", "IT_COPY", "IT_RAND", "IT_SHA512",
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
  "SubSelect", "@4", "@5", "_QBindingsClause_E_Opt", "SelectClause",
  "_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C",
  "_Q_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C_E_Opt", "_O_QIT_AS_E_S_QVar_E_C",
  "_Q_O_QIT_AS_E_S_QVar_E_C_E_Opt",
  "_O_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_Q_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C_E_Plus",
  "_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_Plus_Or_QGT_TIMES_E_C",
  "ConstructQuery", "$@6", "_O_QIT_LABEL_E_S_QGraphTerm_E_C",
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
  "OffsetClause", "BindingsClause", "$@7", "_QVar_E_Star",
  "_QBindingValue_E_Plus",
  "_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C",
  "$@8",
  "_Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star",
  "BindingValue", "_QIT_SILENT_E_Opt", "GroupGraphPattern", "$@9",
  "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C", "GroupGraphPatternSub",
  "_QTriplesBlock_E_Opt", "_QGT_DOT_E_Opt",
  "_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "OptionalGraphPattern", "@10", "GraphGraphPattern", "@11", "@12", "@13",
  "ServiceGraphPattern", "@14", "@15", "@16", "Bind", "MinusGraphPattern",
  "@17", "@18", "GroupOrUnionGraphPattern", "@19", "@20",
  "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@21",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "@22", "_QIT_DISTINCT_E_Opt",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ExpressionList", "@23",
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
  "SubstringExpression", "ExistsFunc", "NotExistsFunc", "Aggregate", "@32",
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
       172,     0,    -1,    -1,   173,   188,   174,   175,    -1,    -1,
     174,   176,    -1,    -1,   175,   208,    -1,     3,   365,   405,
     405,    -1,     4,   405,    -1,     5,   405,    -1,     6,   405,
      -1,     7,   405,    -1,     8,   405,    -1,     9,   415,    -1,
      10,   181,    -1,    11,   177,    -1,    13,   180,    -1,    12,
      -1,    15,    -1,    14,    -1,    -1,   366,    -1,    41,   178,
      42,   363,    -1,   179,    -1,   180,   179,    -1,   182,   183,
      -1,    -1,   187,    -1,    -1,   184,    -1,    41,   186,    42,
      -1,   405,    48,   405,    -1,    -1,   186,   185,    -1,    56,
     405,    57,    -1,   189,   190,    -1,    -1,   191,    -1,    -1,
     190,   192,    -1,    20,   162,    -1,    -1,    -1,    21,   193,
     163,   194,   162,    -1,    -1,    -1,   196,   199,   197,   218,
     220,   198,    -1,    -1,   242,    -1,    26,   201,   207,    -1,
      22,    -1,    23,    -1,    -1,   200,    -1,    94,   365,    -1,
      -1,   202,    -1,    44,   367,   203,    45,    -1,   365,    -1,
     397,    -1,   390,    -1,   285,    -1,   405,    -1,   409,    -1,
     413,    -1,   204,    -1,   205,    -1,   206,   205,    -1,   206,
      -1,    24,    -1,    -1,   211,    25,   293,   209,   212,   218,
     220,   198,    -1,    16,   366,    -1,    -1,   210,    -1,    -1,
     212,   213,    -1,    27,   214,    -1,   215,    -1,   216,    -1,
     217,    -1,    28,   217,    -1,   415,    -1,   219,   251,    -1,
      -1,    43,    -1,   221,   222,   223,   224,    -1,    -1,   225,
      -1,    -1,   228,    -1,    -1,   231,    -1,    -1,   237,    -1,
      95,    30,   226,    -1,   227,    -1,   226,   227,    -1,   390,
      -1,   285,    -1,    44,   367,   203,    45,    -1,   365,    -1,
      96,   229,    -1,   230,    -1,   229,   230,    -1,   284,    -1,
      29,    30,   232,    -1,   233,    -1,   232,   233,    -1,   235,
      -1,   236,    -1,    31,    -1,    32,    -1,   234,   389,    -1,
     284,    -1,   365,    -1,   240,   238,    -1,   241,   239,    -1,
      -1,   241,    -1,    -1,   240,    -1,    33,   149,    -1,    34,
     149,    -1,    -1,    35,   243,   244,    41,   248,    42,    -1,
      -1,   244,   365,    -1,   249,    -1,   245,   249,    -1,    -1,
      44,   247,   245,    45,    -1,   170,    -1,    -1,   248,   246,
      -1,   415,    -1,   405,    -1,   409,    -1,   413,    -1,    46,
      -1,    47,    -1,   365,    -1,    -1,    19,    -1,    -1,    41,
     252,   253,    42,    -1,   195,    -1,   254,    -1,   255,   258,
      -1,    -1,   259,    -1,    -1,    48,    -1,   262,   256,   255,
      -1,    -1,   258,   257,    -1,   314,   261,    -1,    48,   255,
      -1,    -1,   260,    -1,   277,    -1,   263,    -1,   274,    -1,
     265,    -1,   269,    -1,   283,    -1,   273,    -1,   242,    -1,
      -1,    49,   264,   251,    -1,    -1,    -1,    -1,    17,   266,
     267,   364,   268,   251,    -1,    -1,    -1,    -1,    18,   270,
     271,   272,   250,   364,   251,    -1,   125,    44,   367,    94,
     365,    45,    -1,    -1,    -1,    50,   275,   276,   251,    -1,
      -1,    -1,   278,   279,   251,   282,    -1,    -1,    51,   281,
     251,    -1,    -1,   282,   280,    -1,    52,   284,    -1,   389,
      -1,   390,    -1,   285,    -1,   415,   286,    -1,   170,    -1,
      -1,    44,   288,   367,   287,   290,    45,    -1,    -1,    22,
      -1,    53,   367,    -1,    -1,   290,   289,    -1,   170,    -1,
      -1,    44,   367,   292,   290,    45,    -1,    -1,    41,   294,
     295,    42,    -1,    -1,   296,    -1,   299,   298,    -1,    48,
     295,    -1,    -1,   297,    -1,    -1,   363,   300,   302,    -1,
      -1,   355,   301,   307,    -1,   313,   309,   306,    -1,   313,
     309,    -1,    -1,   303,    -1,    54,   304,    -1,    -1,   306,
     305,    -1,   308,    -1,    -1,   302,    -1,   312,   311,    -1,
      53,   312,    -1,    -1,   311,   310,    -1,   362,    -1,   364,
      -1,    55,    -1,    -1,   363,   315,   317,    -1,    -1,   355,
     316,   325,    -1,    -1,   319,   318,   309,   324,    -1,   326,
      -1,   327,    -1,    -1,   319,   321,   309,    -1,    -1,   320,
      -1,    54,   322,    -1,    -1,   324,   323,    -1,   308,    -1,
     328,    -1,   365,    -1,   329,    -1,   332,   331,    -1,   107,
     332,    -1,    -1,   331,   330,    -1,   337,   334,    -1,    68,
     337,    -1,    -1,   334,   333,    -1,   343,   336,    -1,    -1,
     338,    -1,   335,    -1,   105,   335,    -1,   342,    -1,    42,
      -1,   354,    42,    -1,    53,   339,    -1,    42,    -1,   354,
     340,    -1,    53,   354,    42,    -1,    24,    -1,   106,    -1,
      66,    -1,    41,   341,    -1,   344,    -1,   415,    -1,    55,
      -1,    69,   345,    -1,    44,   328,    45,    -1,   350,    -1,
     107,   351,    -1,    -1,   347,   346,    -1,   351,   347,    -1,
      -1,   348,    -1,   351,    -1,    44,   349,    45,    -1,   353,
      -1,   415,    -1,    55,    -1,   415,    -1,    55,    -1,   105,
     352,    -1,   149,    -1,   358,    -1,   356,    -1,    -1,    56,
     357,   302,    57,    -1,   360,    44,   361,    45,    -1,    36,
      -1,    37,    -1,    38,    -1,    39,    -1,    40,    -1,    -1,
     359,    -1,   362,    -1,   361,   362,    -1,   363,    -1,   355,
      -1,   365,    -1,   366,    -1,   365,    -1,   415,    -1,   167,
      -1,   168,    -1,   415,    -1,   405,    -1,   409,    -1,   413,
      -1,   417,    -1,   170,    -1,   368,    -1,   371,   370,    -1,
      58,   371,    -1,    -1,   370,   369,    -1,   374,   373,    -1,
      59,   374,    -1,    -1,   373,   372,    -1,   375,    -1,   378,
     376,    -1,    -1,   377,    -1,    60,   378,    -1,    61,   378,
      -1,    62,   378,    -1,    63,   378,    -1,    64,   378,    -1,
      65,   378,    -1,    71,   291,    -1,    70,    71,   291,    -1,
     379,    -1,   385,   384,    -1,   411,    -1,   412,    -1,    24,
     387,    -1,    68,   387,    -1,    -1,   381,    -1,    66,   385,
      -1,    67,   385,    -1,   380,   382,    -1,    -1,   384,   383,
      -1,   387,   386,    -1,    -1,   386,   381,    -1,    69,   388,
      -1,    66,   388,    -1,    67,   388,    -1,   388,    -1,   389,
      -1,   390,    -1,   403,    -1,   405,    -1,   409,    -1,   413,
      -1,   365,    -1,   397,    -1,    44,   367,    45,    -1,    81,
      44,   367,    45,    -1,    82,    44,   367,    45,    -1,    83,
      44,   367,    53,   367,    45,    -1,    84,    44,   367,    45,
      -1,    85,    44,   365,    45,    -1,    72,    44,   367,    45,
      -1,    73,    44,   367,    45,    -1,    74,   391,    -1,   117,
     170,    -1,   140,    44,   367,    45,    -1,   137,    44,   367,
      45,    -1,   129,    44,   367,    45,    -1,   123,    44,   367,
      45,    -1,    93,   291,    -1,   394,    -1,   144,    44,   367,
      45,    -1,   141,    44,   367,    45,    -1,   139,    44,   367,
      45,    -1,   135,    44,   367,    45,    -1,   126,    44,   367,
      53,   367,    45,    -1,   136,    44,   367,    53,   367,    45,
      -1,   143,    44,   367,    53,   367,    45,    -1,   114,    44,
     367,    45,    -1,   146,    44,   367,    45,    -1,   138,    44,
     367,    45,    -1,   134,    44,   367,    45,    -1,   131,    44,
     367,    45,    -1,   127,    44,   367,    45,    -1,   122,    44,
     367,    45,    -1,   120,   170,    -1,   112,    44,   367,    45,
      -1,   145,    44,   367,    45,    -1,   142,    44,   367,    45,
      -1,   133,    44,   367,    45,    -1,   124,    44,   367,    45,
      -1,   118,    44,   367,    45,    -1,    75,   291,    -1,    76,
      44,   367,    53,   367,    53,   367,    45,    -1,    77,    44,
     367,    53,   367,    45,    -1,    78,    44,   367,    53,   367,
      45,    -1,    86,    44,   367,    53,   367,    45,    -1,    87,
      44,   367,    45,    -1,    88,    44,   367,    45,    -1,    89,
      44,   367,    45,    -1,    90,    44,   367,    45,    -1,   104,
      44,   367,    45,    -1,   392,    -1,   395,    -1,   396,    -1,
      44,   367,    45,    -1,   170,    -1,    91,    44,   367,    53,
     367,   393,    45,    -1,    -1,   289,    -1,   132,    44,   367,
      53,   367,   393,    45,    -1,    79,   251,    -1,    70,    79,
     251,    -1,    97,    44,   288,   399,    45,    -1,   400,    44,
     288,   367,    45,    -1,    -1,   102,    44,   288,   367,   398,
     402,    45,    -1,    24,    -1,   367,    -1,    98,    -1,    99,
      -1,   100,    -1,   101,    -1,   103,    -1,    54,    80,    60,
     414,    -1,    -1,   401,    -1,   415,   404,    -1,    -1,   286,
      -1,   414,   408,    -1,    92,   415,    -1,   169,    -1,   406,
      -1,    -1,   407,    -1,   410,    -1,   411,    -1,   412,    -1,
     149,    -1,   150,    -1,   151,    -1,   152,    -1,   153,    -1,
     154,    -1,   155,    -1,   156,    -1,   157,    -1,   147,    -1,
     148,    -1,   158,    -1,   160,    -1,   159,    -1,   161,    -1,
     162,    -1,   416,    -1,   164,    -1,   163,    -1,   165,    -1,
     166,    -1
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
     100,   103,   106,   107,   108,   114,   115,   116,   123,   124,
     126,   130,   132,   134,   135,   137,   140,   141,   143,   148,
     150,   152,   154,   156,   158,   160,   162,   164,   166,   169,
     171,   173,   174,   183,   186,   187,   189,   190,   193,   196,
     198,   200,   202,   205,   207,   210,   211,   213,   218,   219,
     221,   222,   224,   225,   227,   228,   230,   234,   236,   239,
     241,   243,   248,   250,   253,   255,   258,   260,   264,   266,
     269,   271,   273,   275,   277,   280,   282,   284,   287,   290,
     291,   293,   294,   296,   299,   302,   303,   310,   311,   314,
     316,   319,   320,   325,   327,   328,   331,   333,   335,   337,
     339,   341,   343,   345,   346,   348,   349,   354,   356,   358,
     361,   362,   364,   365,   367,   371,   372,   375,   378,   381,
     382,   384,   386,   388,   390,   392,   394,   396,   398,   400,
     401,   405,   406,   407,   408,   415,   416,   417,   418,   426,
     433,   434,   435,   440,   441,   442,   447,   448,   452,   453,
     456,   459,   461,   463,   465,   468,   470,   471,   478,   479,
     481,   484,   485,   488,   490,   491,   497,   498,   503,   504,
     506,   509,   512,   513,   515,   516,   520,   521,   525,   529,
     532,   533,   535,   538,   539,   542,   544,   545,   547,   550,
     553,   554,   557,   559,   561,   563,   564,   568,   569,   573,
     574,   579,   581,   583,   584,   588,   589,   591,   594,   595,
     598,   600,   602,   604,   606,   609,   612,   613,   616,   619,
     622,   623,   626,   629,   630,   632,   634,   637,   639,   641,
     644,   647,   649,   652,   656,   658,   660,   662,   665,   667,
     669,   671,   674,   678,   680,   683,   684,   687,   690,   691,
     693,   695,   699,   701,   703,   705,   707,   709,   712,   714,
     716,   718,   719,   724,   729,   731,   733,   735,   737,   739,
     740,   742,   744,   747,   749,   751,   753,   755,   757,   759,
     761,   763,   765,   767,   769,   771,   773,   775,   777,   780,
     783,   784,   787,   790,   793,   794,   797,   799,   802,   803,
     805,   808,   811,   814,   817,   820,   823,   826,   830,   832,
     835,   837,   839,   842,   845,   846,   848,   851,   854,   857,
     858,   861,   864,   865,   868,   871,   874,   877,   879,   881,
     883,   885,   887,   889,   891,   893,   895,   899,   904,   909,
     916,   921,   926,   931,   936,   939,   942,   947,   952,   957,
     962,   965,   967,   972,   977,   982,   987,   994,  1001,  1008,
    1013,  1018,  1023,  1028,  1033,  1038,  1043,  1046,  1051,  1056,
    1061,  1066,  1071,  1076,  1079,  1088,  1095,  1102,  1109,  1114,
    1119,  1124,  1129,  1134,  1136,  1138,  1140,  1144,  1146,  1154,
    1155,  1157,  1165,  1168,  1172,  1178,  1184,  1185,  1193,  1195,
    1197,  1199,  1201,  1203,  1205,  1207,  1212,  1213,  1215,  1218,
    1219,  1221,  1224,  1227,  1229,  1231,  1232,  1234,  1236,  1238,
    1240,  1242,  1244,  1246,  1248,  1250,  1252,  1254,  1256,  1258,
    1260,  1262,  1264,  1266,  1268,  1270,  1272,  1274,  1276,  1278,
    1280
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  MapSetParser::yyrline_[] =
  {
         0,   462,   462,   462,   468,   470,   474,   476,   480,   489,
     492,   495,   498,   501,   504,   507,   509,   513,   519,   522,
     525,   531,   534,   538,   550,   551,   555,   558,   560,   563,
     565,   569,   573,   578,   580,   584,   591,   595,   597,   601,
     603,   607,   613,   615,   613,   625,   628,   625,   641,   644,
     649,   657,   660,   667,   670,   675,   682,   685,   690,   697,
     700,   703,   706,   709,   712,   715,   719,   724,   727,   735,
     738,   745,   745,   757,   763,   766,   771,   774,   782,   789,
     790,   794,   800,   806,   813,   820,   822,   827,   834,   837,
     842,   845,   850,   853,   858,   862,   866,   873,   876,   883,
     886,   889,   892,   898,   904,   907,   914,   919,   926,   930,
     938,   940,   948,   951,   959,   967,   968,   975,   979,   987,
     990,   995,   998,  1002,  1008,  1015,  1015,  1023,  1025,  1031,
    1034,  1040,  1040,  1045,  1051,  1053,  1057,  1060,  1063,  1066,
    1069,  1072,  1075,  1081,  1084,  1091,  1091,  1102,  1103,  1108,
    1112,  1114,  1122,  1124,  1129,  1133,  1136,  1152,  1157,  1161,
    1164,  1168,  1169,  1170,  1171,  1172,  1173,  1174,  1175,  1181,
    1181,  1197,  1201,  1203,  1197,  1214,  1218,  1220,  1214,  1231,
    1237,  1241,  1237,  1251,  1255,  1251,  1265,  1265,  1277,  1279,
    1283,  1293,  1294,  1295,  1299,  1307,  1311,  1311,  1321,  1324,
    1331,  1337,  1339,  1353,  1356,  1356,  1367,  1367,  1375,  1377,
    1382,  1387,  1391,  1393,  1397,  1397,  1400,  1400,  1407,  1412,
    1416,  1418,  1423,  1427,  1429,  1434,  1438,  1440,  1445,  1450,
    1454,  1456,  1460,  1467,  1471,  1479,  1479,  1482,  1482,  1488,
    1488,  1494,  1495,  1499,  1499,  1504,  1506,  1510,  1513,  1515,
    1519,  1523,  1527,  1533,  1537,  1541,  1544,  1546,  1550,  1554,
    1559,  1561,  1567,  1570,  1572,  1578,  1579,  1585,  1589,  1590,
    1594,  1595,  1599,  1600,  1604,  1605,  1606,  1607,  1611,  1615,
    1618,  1621,  1624,  1630,  1634,  1637,  1639,  1643,  1646,  1648,
    1652,  1653,  1657,  1661,  1662,  1666,  1667,  1668,  1672,  1677,
    1678,  1682,  1682,  1695,  1720,  1723,  1726,  1729,  1732,  1739,
    1742,  1747,  1751,  1758,  1759,  1763,  1766,  1770,  1773,  1779,
    1780,  1784,  1787,  1790,  1793,  1796,  1797,  1803,  1808,  1817,
    1824,  1827,  1835,  1844,  1851,  1854,  1861,  1866,  1877,  1880,
    1884,  1887,  1890,  1893,  1896,  1899,  1902,  1905,  1911,  1916,
    1925,  1928,  1935,  1938,  1945,  1948,  1953,  1956,  1960,  1974,
    1977,  1985,  1994,  1997,  2004,  2007,  2010,  2013,  2017,  2018,
    2019,  2020,  2023,  2026,  2029,  2032,  2036,  2042,  2045,  2048,
    2051,  2054,  2057,  2060,  2064,  2067,  2070,  2073,  2076,  2079,
    2082,  2085,  2086,  2089,  2092,  2095,  2098,  2101,  2104,  2107,
    2110,  2113,  2116,  2119,  2122,  2125,  2128,  2131,  2134,  2137,
    2140,  2143,  2146,  2149,  2153,  2156,  2159,  2162,  2165,  2168,
    2171,  2174,  2177,  2180,  2181,  2182,  2188,  2191,  2198,  2205,
    2208,  2212,  2218,  2225,  2232,  2235,  2239,  2239,  2252,  2256,
    2260,  2263,  2266,  2269,  2272,  2278,  2284,  2287,  2291,  2301,
    2304,  2309,  2317,  2324,  2328,  2336,  2340,  2344,  2345,  2346,
    2350,  2351,  2352,  2356,  2357,  2358,  2362,  2363,  2364,  2368,
    2369,  2373,  2374,  2375,  2376,  2380,  2381,  2385,  2386,  2390,
    2391
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
     165,   166,   167,   168,   169,   170
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int MapSetParser::yyeof_ = 0;
  const int MapSetParser::yylast_ = 2072;
  const int MapSetParser::yynnts_ = 247;
  const int MapSetParser::yyempty_ = -2;
  const int MapSetParser::yyfinal_ = 3;
  const int MapSetParser::yyterror_ = 1;
  const int MapSetParser::yyerrcode_ = 256;
  const int MapSetParser::yyntokens_ = 171;

  const unsigned int MapSetParser::yyuser_token_number_max_ = 425;
  const MapSetParser::token_number_type MapSetParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 4747 "lib/MapSetParser/MapSetParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 2397 "lib/MapSetParser/MapSetParser.ypp"
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


