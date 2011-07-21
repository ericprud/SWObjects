
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
#line 299 "lib/MapSetParser/MapSetParser.ypp"

#include "../MapSetScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 438 "lib/MapSetParser/MapSetParser.ypp"

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
#line 453 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root = new MapSet();
	driver.root->sharedVars = MapSet::e_PROMISCUOUS;
      }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 471 "lib/MapSetParser/MapSetParser.ypp"
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
#line 480 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->driver = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 483 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->server = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 486 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->user = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 489 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->password = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 492 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->database = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 495 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->stemURI = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 500 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.sharedVarsSet = true;
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 504 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.lastRuleTermSet = false;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 510 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_PROMISCUOUS;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 513 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_VARNAMES;
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 516 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_DRACONIAN;
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 522 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = NULL;
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 529 "lib/MapSetParser/MapSetParser.ypp"
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
#line 564 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->keyMap[(yysemantic_stack_[(3) - (1)].p_RDFLiteral)->getLexicalValue()] = (yysemantic_stack_[(3) - (3)].p_RDFLiteral)->getLexicalValue();
    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 575 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->primaryKey = (yysemantic_stack_[(3) - (2)].p_RDFLiteral);
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 598 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 604 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 606 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 608 "lib/MapSetParser/MapSetParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 616 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 619 "lib/MapSetParser/MapSetParser.ypp"
    {
	  if ((yysemantic_stack_[(5) - (5)].p_BindingClause) != NULL)
	      (yysemantic_stack_[(5) - (3)].p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yysemantic_stack_[(5) - (5)].p_BindingClause), (yysemantic_stack_[(5) - (3)].p_WhereClause)->m_GroupGraphPattern);
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(5) - (1)].p_Project).distinctness, (yysemantic_stack_[(5) - (1)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(5) - (3)].p_WhereClause), (yysemantic_stack_[(5) - (4)].p_SolutionModifier))));
      }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 627 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 635 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 643 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 646 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 653 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 661 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 668 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 676 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 683 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 686 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 689 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 692 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 695 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 698 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 701 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 710 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 713 "lib/MapSetParser/MapSetParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 721 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 724 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 731 "lib/MapSetParser/MapSetParser.ypp"
    {
	/* $3 is known to be a DefaultGraphPattern because of grammar restrictions. */
	if ((yysemantic_stack_[(7) - (7)].p_BindingClause) != NULL)
	    (yysemantic_stack_[(7) - (5)].p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yysemantic_stack_[(7) - (7)].p_BindingClause), (yysemantic_stack_[(7) - (5)].p_WhereClause)->m_GroupGraphPattern);
	Construct* constr = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(7) - (3)].p_BasicGraphPattern), (yysemantic_stack_[(7) - (4)].p_DatasetClauses), (yysemantic_stack_[(7) - (5)].p_WhereClause), (yysemantic_stack_[(7) - (6)].p_SolutionModifier));
	driver.root->maps.push_back(LabeledConstruct((yysemantic_stack_[(7) - (1)].p_TTerm), constr));
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 741 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (2)].p_TTerm);
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 747 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = NULL;
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 755 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 758 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 766 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 778 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 784 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 790 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 797 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp ? driver.curOp : new DefaultGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 811 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 818 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 826 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 834 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 842 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 850 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 857 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 860 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 867 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 870 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 873 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 876 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 882 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 888 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 891 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 903 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 910 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 914 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 924 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 932 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 935 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 943 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 952 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 959 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 963 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 971 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 979 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 986 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 992 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 999 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1001 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BindingClause) = driver.endBindingSet();
      }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1009 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1015 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1018 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1024 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.startBindingRow(); // @@ push down to _Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star?
      }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1026 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1029 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1041 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1044 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1047 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1050 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1053 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1056 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1059 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1066 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1069 "lib/MapSetParser/MapSetParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 1151 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_BindingClause)) : (yysemantic_stack_[(1) - (1)].p_BindingClause);
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1157 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1160 "lib/MapSetParser/MapSetParser.ypp"
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

  case 167:

/* Line 678 of lalr1.cc  */
#line 1172 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1175 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1177 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1180 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 1188 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 1191 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 1193 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(5) - (4)].p_TTerm), driver.curOp, driver.atomFactory, false));
      }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1200 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = new Bind(driver.curOp, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 1206 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 1209 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 1211 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.curOp));
      }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 1219 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 1222 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 1224 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 1232 "lib/MapSetParser/MapSetParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 1237 "lib/MapSetParser/MapSetParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 1252 "lib/MapSetParser/MapSetParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    if (driver.curOp == NULL)
		driver.ensureBasicGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 1269 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 1277 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 1281 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 1283 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = NULL;
      }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 1290 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 1293 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1300 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1308 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1322 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 1325 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 1327 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 1335 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 1337 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 1365 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 1368 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 1428 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 1435 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 1439 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 1447 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 1450 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 1456 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 1467 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 1495 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 1522 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 1529 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 1540 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 1547 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 1583 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 1586 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 1589 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 1592 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 1650 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 1654 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 1663 "lib/MapSetParser/MapSetParser.ypp"
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

  case 299:

/* Line 678 of lalr1.cc  */
#line 1688 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 1691 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 1694 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 1697 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 1700 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 1707 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 1715 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 1719 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 1731 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 1738 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 1741 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 1752 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 1755 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 1758 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 1761 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 1765 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 1776 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 1785 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 1792 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 1795 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 1803 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 1812 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 1819 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 1822 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 1834 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_GeneralComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_GeneralComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_GeneralComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 1845 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 1852 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 1855 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 1858 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 1861 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 1864 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 1867 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 1870 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 1873 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 1884 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 1893 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 1896 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 1903 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 1906 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 1913 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 1921 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 1924 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 1928 "lib/MapSetParser/MapSetParser.ypp"
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

  case 354:

/* Line 678 of lalr1.cc  */
#line 1942 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 1945 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 1953 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 1962 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 1965 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 1972 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 1975 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 1978 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 1988 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 1991 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 1994 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 1997 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 2004 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 2010 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 2013 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 2016 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 2019 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 2022 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 2025 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 2028 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 2032 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_blank, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 2035 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 2038 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 2041 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ciel, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 2044 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 2047 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 2050 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::XPATH_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 2054 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlen, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 2057 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ucase, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 2060 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lcase, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 2063 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encodeForUri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 2066 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 2069 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strStarts, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 2072 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strEnds, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 2075 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 2078 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 2081 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 2084 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 2087 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 2090 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 2093 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 2096 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 2099 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 2102 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 2105 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha224, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 2108 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 2111 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 2114 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 2117 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 2121 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 2124 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 2127 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 2130 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 2133 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 2136 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 2139 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 2142 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 2145 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 2156 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 2159 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 2166 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_regex, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 2173 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 2180 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 2186 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 2193 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 2200 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 2203 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 2207 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 2209 "lib/MapSetParser/MapSetParser.ypp"
    {
	  // x = new ArgList($2, driver.curExprList);
	  delete driver.curExprList;
	  driver.curExprList = NULL;
	  w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // $$ = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group-concat, $3, $4.p_Expression, $4.separator));
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 2219 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
	driver.countStar = true;
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 2227 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 2230 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 2233 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 2236 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 2239 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 2245 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 2251 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 2258 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 2268 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 2276 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 2284 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 2291 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 2295 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 2303 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 3085 "lib/MapSetParser/MapSetParser.cpp"
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
  const short int MapSetParser::yypact_ninf_ = -656;
  const short int
  MapSetParser::yypact_[] =
  {
      -656,    48,    44,  -656,   -86,  -656,  -656,  -656,  -656,   346,
      74,  -113,    72,    72,    72,    72,    72,    73,    51,    89,
      59,    27,  -656,  -656,  -656,  -656,  -656,    72,  -656,  -656,
    -656,  -656,  -656,   -71,  -656,  -656,  -656,  -656,  -656,  -656,
    -656,  -656,  -656,    72,  -656,    98,  -656,  -656,  -656,  -656,
    -656,   488,  -656,    59,   488,  -656,  -656,    96,   -20,    72,
      73,  -656,  -656,  -656,  -656,   111,  -656,  -656,  -656,  -656,
    -656,  -656,  -656,  -656,  -656,  -656,  -656,  -656,  -656,  -656,
    -656,  -656,  -656,   128,  -656,  -656,  -656,  -656,  -656,  -656,
    -656,  -656,  -656,  -656,  -656,   142,  -656,  -656,  -656,  -656,
      52,   886,  -656,  -656,    25,  -656,  -656,   143,  -656,  -656,
    -656,  1235,    14,  -656,    72,  -656,  -656,  -656,  -656,  -656,
    -656,   147,  -656,   151,  -656,  -656,  -656,  -656,   158,  -656,
     -10,  -656,  -656,   113,   174,  -656,   -26,  -656,  1235,  -656,
    -656,   -26,  1324,   -26,    73,  -656,  -656,  -656,  -656,  -656,
     189,   186,   129,  -656,  -656,  -656,  -656,   195,  1324,  -656,
    -656,  -656,  -656,  -656,  -656,  -656,  -656,  1271,  -656,  -656,
    -656,  -656,  1812,  -656,  -656,  -656,  1915,   233,  -656,   243,
    -656,  -656,  -656,  -656,  -656,  -656,  1449,   167,   219,   220,
     -24,   -12,   222,   223,   224,   174,   226,   227,   228,   229,
     231,   232,   234,   240,   241,   242,   251,   -12,   256,   257,
     261,   107,   265,   145,   267,   268,   269,   272,   273,   274,
     275,   276,   278,   279,   280,   282,   283,   285,   286,   287,
     288,   289,   290,   291,   298,   300,  1812,  -656,  -656,  -656,
    -656,  -656,  -656,  -656,  -656,    -4,  -656,  1449,  1915,  -656,
    -656,  -656,  -656,  -656,   315,    56,  -656,   217,  -656,  -656,
     305,  -656,  -656,  -656,   314,  -656,  -656,   294,   311,  1570,
    1570,  1570,   325,  -656,  -656,  -656,  -656,   327,  -656,  -656,
     281,  -656,  -656,  -656,  -656,   355,  -656,  -656,  -656,  -656,
    -656,  -656,  -656,   329,  -656,  -656,  -656,  -656,    -4,   174,
    1449,  1449,  1449,  -656,  -656,  1449,  -656,  -656,  1449,  1449,
    1449,  -656,  1449,  1449,  1449,  1449,  -113,  1449,  1449,  1449,
    1449,  1449,  1449,  -656,  1449,  1449,  1449,  -656,  1449,  -656,
    1449,  1449,  1449,  1449,  1449,  1449,  1449,  1449,  1449,  1449,
    1449,  1449,  1449,  1449,  1449,  1449,  1449,  1449,  1449,  1449,
    1449,  1449,  -656,   352,  -656,  -656,    -7,   334,  -656,  1211,
     235,   236,  -656,  -656,   347,   350,  -656,  -656,  -656,  1077,
     343,  -656,    47,  1235,  -656,  -656,   -26,   140,   -26,  -656,
    1324,  -656,  -656,  -656,  -656,   352,   352,  -113,  -656,   367,
     330,   363,  1449,  1449,  1449,  1449,  1449,  1449,   356,   -12,
    -656,  -656,   184,     4,   352,  -656,  -656,  -656,   369,   378,
     383,  -656,   376,   379,   380,   389,   391,   384,   396,   398,
     392,   399,   401,   402,   403,   397,   406,   407,   408,   409,
     410,   411,   412,   405,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   424,   426,   427,   428,   430,   423,   432,
     433,   434,  -656,  1449,  -656,  -656,  -656,  -656,  -656,  1211,
    -656,   436,  -656,  -656,  -656,  -656,  -656,  -656,  -656,  -656,
    -656,  -656,  -656,  1449,  -656,  -656,  1691,  -656,  -656,  -656,
    -656,  -656,  -656,  -656,  -656,   113,  -656,  -656,  -656,  -656,
    1915,   437,  -656,  -656,   438,  -656,  -656,  -656,  -656,  -656,
    -656,  -656,  -656,  -656,  -656,  -656,    18,  -656,    85,    15,
    -656,  -656,  -656,  -656,  -656,  -656,  -656,  -656,  -656,     9,
    -656,  -656,  -656,  -656,  -656,  1324,  -656,   846,  1449,  -656,
    -656,  1449,  -656,  1449,  -656,  -656,  -656,  -656,  -656,  -656,
    -656,   -12,  -656,  1449,  1449,     4,  -656,  -656,  -656,  1449,
    1449,  -656,  1449,  -656,  -656,  -656,  -656,  1449,  1449,  1449,
    -656,  -656,  1449,  -656,  -656,  1449,  -656,  -656,  -656,  -656,
    1449,  -656,  -656,  -656,  -656,  -656,  -656,  -656,  1449,  -656,
    -656,  -656,  1449,  -656,  -656,  -656,  1449,  -656,  -656,  -656,
    -656,  -656,  -656,  1449,  -656,  -656,  -656,  -656,    -6,  -656,
    -656,   281,  -656,   186,  -656,  -656,   174,  -656,  -656,  1449,
    -656,  1235,   174,   439,    80,  -656,    54,  -656,  -656,  -656,
    -656,  -656,  -656,  1324,   375,   394,  -656,   -30,  -656,  -656,
    -656,  -656,  -656,  -656,  -656,  -656,   443,  -656,  -656,  -656,
    -656,  -656,  -656,  -656,  -656,  -656,  -656,   444,     3,   440,
     445,   446,   447,   449,   442,   451,   442,   452,   453,  -656,
    -656,  -656,  -656,  -656,   454,  -656,    60,    60,  -656,   174,
     413,  -656,  -656,  -656,  -656,   455,  -656,  -656,  -656,  -656,
    -656,    18,  -656,    18,  -656,   353,  -656,  -656,     0,  -656,
     450,  -656,  -656,  1449,  -656,  1449,  -656,  -656,  -656,  -656,
    -656,   456,  -656,   460,  -656,  -656,    24,   975,  -656,  -656,
     174,  -656,  -113,   457,  -656,   404,   459,  -656,  -656,   464,
    -656,    -5,  -656,   429,  -656,   465,  -656,   469,  -656,  -656,
    -656,  -656,  -656,   725,  -656,  -656,  -656,  -656,  -656,  -656,
     174,  -656,   471,  -656,  -656,    80,  -656,   140,  -656,  -656,
    -656,  -656,   476,   462,  -656,  -656,  -656,  -656,  -656,  -656,
     174,  -656,  -656,  -656,  -656,  -656,    72,  -656,  1324,  -656,
    -656
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  MapSetParser::yydefact_[] =
  {
         2,     0,    37,     1,     0,     4,    39,    38,    41,     6,
      36,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     3,     5,    42,    40,   314,   315,     0,   466,   468,
     467,   469,     9,   450,    10,    11,    12,    13,   470,   473,
     472,    14,   471,     0,    15,    29,    28,    18,    20,    19,
      16,    21,    24,    17,     0,     7,    73,     0,     0,     0,
       0,   448,   449,   451,   446,     0,    33,    26,    30,   464,
     465,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     474,   475,   321,     0,    22,   317,   318,   452,   453,   454,
     319,   316,   320,    25,    71,     0,    43,     8,   447,    35,
       0,     0,   201,    74,     0,    31,    34,     0,    23,   310,
     311,   203,    83,    44,     0,   299,   300,   301,   302,   303,
     296,     0,   204,   207,   211,   295,   294,   305,     0,   209,
       0,    84,    75,    86,     0,    32,     0,   202,   203,   208,
     205,   221,   304,     0,     0,    76,    77,    78,    79,    81,
       0,    47,    88,    87,   141,    82,   229,     0,   304,   228,
     312,   313,   206,   222,   212,   220,   309,   304,   306,   308,
     210,    80,     0,   123,    70,    48,     0,    90,    89,   146,
     297,   218,   225,   227,   298,   307,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    98,   100,
      97,   418,   386,   419,   420,     0,   125,     0,   101,   102,
     104,   188,   186,   187,     0,    92,    91,    52,   143,    45,
       0,   144,   151,   147,   155,   232,   230,   213,   223,     0,
       0,     0,     0,   435,   436,   437,   438,     0,   439,   369,
      55,   322,   325,   329,   331,   333,   343,   354,   357,   362,
     363,   364,   370,     0,   365,   366,   367,   368,   444,     0,
       0,     0,     0,   422,   379,     0,   198,   408,     0,     0,
       0,   427,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   385,     0,     0,     0,   380,     0,   401,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,   193,   190,   189,     0,     0,   103,     0,
       0,     0,    85,    93,   117,   119,    50,    51,    53,     0,
      83,   142,   145,   146,   156,   153,   221,     0,   215,   219,
     304,   226,   360,   361,   359,   193,   193,     0,    56,     0,
     323,   327,     0,     0,     0,     0,     0,     0,     0,     0,
     332,   334,   344,   356,   193,   445,   443,   428,     0,     0,
       0,   199,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   194,     0,   132,   126,   371,   110,   111,   105,
     106,     0,   108,   109,   113,   114,   121,   122,   115,   118,
     116,   120,    69,     0,    65,    66,    68,    49,    61,    58,
      60,    59,    62,    63,    64,    86,   167,   171,   165,   175,
       0,     0,   164,   152,   148,   158,   160,   161,   163,   159,
     157,   179,   162,   154,   245,   233,     0,   275,     0,     0,
     231,   234,   236,   237,   246,   248,   251,   260,   255,   258,
     273,   247,   274,   216,   217,   304,   224,     0,     0,    54,
      99,     0,   326,     0,   330,   335,   336,   337,   338,   339,
     340,     0,   341,     0,     0,   349,   355,   345,   346,     0,
       0,   358,     0,   377,   378,   421,   196,     0,     0,     0,
     372,   373,     0,   375,   376,     0,   413,   414,   415,   416,
       0,   417,   402,   394,   407,   400,   384,   406,     0,   399,
     383,   398,     0,   405,   397,   390,     0,   382,   396,   389,
     381,   388,   404,     0,   387,   403,   395,   191,     0,   107,
     112,    55,    67,    47,   168,   172,     0,   176,   185,     0,
     149,   146,     0,     0,   283,   291,     0,   276,   278,   285,
     287,   290,   261,   304,   249,   253,   269,     0,   271,   270,
     257,   259,   262,   214,   433,   434,     0,   431,   324,   328,
     342,   351,   352,   350,   353,   347,   348,     0,     0,     0,
       0,     0,     0,     0,   424,     0,   424,     0,     0,   196,
     124,   129,   131,   133,     0,    46,     0,     0,   166,     0,
       0,   150,   183,   277,   284,     0,   280,   289,   292,   288,
     243,     0,   252,     0,   256,     0,   293,   272,     0,   429,
     441,   430,   200,     0,   197,     0,   410,   411,   374,   412,
     425,     0,   391,     0,   392,   393,     0,     0,    57,   169,
       0,   177,     0,   180,   286,   282,   235,   250,   254,     0,
     266,     0,   267,     0,   442,     0,   195,     0,   423,   426,
     192,   138,   139,     0,   127,   140,   135,   136,   137,   134,
       0,   173,     0,   181,   184,     0,   281,   240,   244,   268,
     263,   265,     0,     0,   432,   409,   130,   128,   170,   174,
       0,   279,   238,   241,   242,   264,     0,   182,   304,   440,
     239
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yypgoto_[] =
  {
      -656,  -656,  -656,  -656,  -656,  -656,  -656,  -656,   466,  -656,
    -656,  -656,  -656,  -656,  -656,  -656,  -656,  -656,  -656,  -656,
    -656,  -656,  -656,  -656,  -656,  -656,   -85,  -656,  -656,  -656,
    -656,   -79,  -656,    49,  -656,  -656,  -656,  -656,  -656,  -656,
    -656,  -656,  -656,  -656,   382,   153,  -656,    39,  -656,  -656,
    -656,  -656,  -656,  -656,   292,  -656,  -656,   284,  -656,  -656,
      70,  -656,  -656,  -656,  -656,  -656,  -656,   165,   170,   163,
    -656,  -656,  -656,  -656,  -656,  -656,  -197,  -183,  -656,  -656,
    -656,  -359,  -656,  -656,  -656,  -656,  -656,  -656,  -656,  -656,
    -656,  -656,  -656,  -656,  -656,  -656,  -656,  -656,  -656,  -656,
    -656,  -656,  -656,  -656,  -656,  -656,  -656,  -656,  -656,  -336,
    -156,   244,  -656,  -360,  -530,  -120,  -199,  -656,  -656,  -656,
     400,  -656,  -656,  -656,  -656,  -656,  -656,   -59,  -656,  -656,
    -656,  -656,  -656,   164,  -510,  -656,  -656,   161,   166,  -656,
    -656,  -656,  -656,  -656,  -204,  -656,  -656,  -656,  -656,  -656,
    -656,  -656,  -656,    40,  -656,  -656,  -656,  -136,  -656,  -656,
      38,  -656,  -135,  -656,  -656,  -656,  -656,  -656,  -656,  -656,
    -656,  -656,  -656,  -656,  -656,  -656,  -590,  -656,  -656,  -655,
    -109,  -656,  -656,  -656,  -656,  -656,  -656,  -121,  -100,  -556,
     -11,   141,   502,  -656,  -656,  -656,    19,  -656,  -656,    16,
    -656,  -656,  -656,  -105,  -656,  -656,     7,  -656,  -656,  -656,
    -287,  -656,  -290,   -16,  -166,  -163,  -656,  -656,  -103,  -656,
    -656,  -656,  -302,  -656,  -656,  -656,  -656,  -656,  -656,  -656,
      -9,  -656,  -656,  -656,     6,  -656,   152,   154,     8,  -211,
      61,  -656,  -656
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yydefgoto_[] =
  {
        -1,     1,     2,     9,    21,    22,    50,    83,    52,    53,
      44,    45,    67,    68,   106,   100,    46,     5,     6,    10,
       7,    24,    58,   104,   258,   370,   174,   259,   368,   369,
     388,   389,   474,   475,   476,   477,    55,    56,    57,   112,
     132,   145,   146,   147,   148,   133,   134,   151,   152,   177,
     255,   362,   153,   236,   237,   178,   248,   249,   256,   459,
     460,   461,   462,   463,   363,   468,   470,   364,   365,   175,
     246,   356,   733,   663,   707,   598,   734,   155,   179,   260,
     261,   262,   611,   493,   372,   263,   374,   375,   494,   495,
     606,   496,   604,   666,   740,   497,   605,   667,   498,   499,
     607,   669,   500,   501,   612,   744,   760,   713,   502,   250,
     251,   355,   659,   453,   694,   648,   307,   556,   103,   111,
     121,   122,   139,   140,   123,   143,   141,   163,   523,   524,
     379,   267,   164,   165,   181,   381,   268,   182,   158,   264,
     377,   376,   510,   623,   511,   763,   768,   764,   748,   716,
     505,   512,   513,   514,   515,   682,   624,   516,   684,   625,
     517,   630,   518,   631,   751,   722,   687,   632,   519,   520,
     617,   746,   715,   674,   675,   618,   619,   678,   620,   688,
     166,   125,   136,   126,   127,   128,   167,   183,   169,   159,
     279,   110,   280,   281,   532,   390,   282,   534,   391,   283,
     284,   400,   401,   285,   286,   545,   551,   644,   546,   402,
     287,   403,   288,   289,   290,   291,   304,   241,   701,   242,
     243,   244,   292,   690,   636,   293,   724,   725,   294,   406,
     295,    62,    63,    64,   296,    87,    88,    89,   297,    33,
     298,    42,    92
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int MapSetParser::yytable_ninf_ = -305;
  const short int
  MapSetParser::yytable_[] =
  {
        27,   108,   124,    32,    34,    35,    36,    37,   323,   240,
     252,   129,   311,   253,   503,   633,   238,   144,    59,   302,
      60,   168,   685,   464,   676,   527,   528,   549,   156,   124,
     719,   305,   626,   454,    65,   660,   750,   661,   129,   353,
     130,   720,    85,    54,   552,    85,   185,   692,     3,   627,
      97,   -72,   721,    25,    26,   693,   131,    86,   506,    90,
      86,   506,    90,     4,   486,   487,   752,   481,   730,   507,
     265,   550,   507,   240,   628,     8,   693,   157,    41,   266,
     238,   173,   252,   508,   170,   253,   508,  -178,   360,   361,
     109,   107,    85,   105,    23,   488,   489,    61,   490,    51,
     109,    47,    85,    48,    49,   135,    43,    86,   677,    90,
     709,   710,    91,   680,   629,    91,   407,    86,   686,    90,
      95,    98,   509,   464,   700,   160,   700,   109,   614,    85,
     160,   109,   160,    85,   615,    38,    39,    40,    66,   615,
      25,    26,    96,   686,    86,   303,    90,   109,    86,    85,
      90,    38,    39,    40,   608,   761,   109,   306,    85,    25,
      26,   239,    91,   662,    86,   354,    90,    99,   109,   101,
      85,   491,    91,    86,   481,    90,    38,    39,    40,    38,
      39,    40,   102,   506,   616,    86,   113,    90,   137,   616,
     114,   149,    84,   252,   507,    94,   253,   161,   138,    91,
     542,   142,   161,    91,   161,   149,   480,   150,   508,    28,
      29,    30,    31,   478,   154,    38,    39,    40,   172,    91,
     173,    38,    39,    40,   176,   239,    25,    26,    91,    28,
      29,    30,    31,   245,    38,    39,    40,   245,   366,   367,
      91,    38,    39,    40,   509,   299,    38,    39,    40,   543,
     544,   180,   671,   382,   383,   384,   641,   642,   770,   645,
     646,   254,   300,   301,   265,   308,   309,   310,   257,   312,
     313,   314,   315,   266,   316,   317,   327,   318,   115,   116,
     117,   118,   119,   319,   320,   321,  -304,   535,   536,   537,
     538,   539,   540,   252,   322,   600,   253,   245,   120,   324,
     325,    38,    39,    40,   326,   419,    25,    26,   328,   245,
     330,   331,   332,   480,   329,   333,   334,   335,   336,   337,
     478,   338,   339,   340,   252,   341,   342,   253,   343,   344,
     345,   346,   347,   348,   349,    74,    75,    76,    77,    78,
      79,   350,   640,   351,   359,   455,   371,   378,   465,    11,
      12,    13,    14,    15,    16,    17,    18,    19,   479,    20,
     482,   373,   109,   380,    85,   160,   521,   160,   385,   109,
     386,    85,   404,   452,   387,   483,   529,   484,   456,    86,
     361,    90,   360,   466,   467,   131,    86,   531,    90,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      28,    29,    30,    31,    38,    39,    40,    80,    81,    25,
      26,   530,    82,   553,   392,   393,   394,   395,   396,   397,
     245,   533,   554,   668,   398,   399,   541,   555,   557,   672,
     245,   558,   559,   560,    91,   561,   562,   161,   522,   161,
     563,    91,   564,   566,   565,   567,   568,   569,   465,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   683,   583,   584,   585,   479,   587,   482,   588,   582,
     589,   590,   591,   586,   592,   593,   594,   595,   596,   247,
     609,   681,   483,   673,   484,   610,   711,   689,   691,   696,
     697,   698,   695,   699,   693,   702,   704,   705,   708,   714,
     728,   686,   265,   723,   729,   749,   712,   743,   753,   754,
     745,   266,   747,   755,   109,   759,    85,   765,   665,    93,
     245,   766,   664,   485,   603,   602,   171,   741,   352,   599,
     471,    86,   358,    90,   469,   492,   757,   245,   162,   706,
     504,   526,   405,   762,   525,   717,   613,   622,   718,   639,
     638,   245,   643,   703,   547,   769,   548,   758,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   522,     0,   621,
     522,     0,     0,     0,     0,     0,     0,   767,     0,     0,
       0,     0,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,     0,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   109,     0,    85,     0,     0,    86,     0,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
       0,    90,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    28,    29,    30,    31,    38,
      39,    40,    80,    81,     0,   160,   160,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,     0,     0,   621,     0,   679,     0,     0,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   735,     0,   736,     0,
       0,   742,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   737,     0,   738,     0,     0,     0,     0,
       0,     0,   735,     0,   736,     0,     0,   161,   161,     0,
       0,     0,     0,     0,     0,     0,   521,     0,     0,   737,
       0,   738,   522,     0,   522,     0,     0,     0,     0,   357,
       0,     0,     0,     0,     0,     0,     0,   109,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,   739,   756,
     731,   732,     0,     0,    86,     0,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   739,     0,     0,     0,     0,     0,
       0,     0,   408,   409,   410,     0,   621,   411,   522,     0,
     412,   413,   414,     0,   415,   416,   417,   418,     0,   420,
     421,   422,   423,   424,   425,     0,   426,   427,   428,    91,
     429,     0,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   634,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    28,    29,    30,    31,    38,    39,    40,   247,
       0,    25,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   269,   270,     0,   271,   187,     0,   188,   189,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,     0,   207,     0,
       0,     0,   272,   273,   274,   275,   276,   277,   278,   208,
       0,     0,     0,     0,     0,   597,     0,   209,     0,   210,
       0,     0,   211,   212,     0,   213,     0,   214,   215,   216,
       0,   217,   218,     0,   219,   601,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    28,    29,    30,    31,    38,    39,    40,
       0,     0,    25,    26,     0,     0,     0,     0,     0,     0,
     731,   732,     0,     0,     0,     0,     0,     0,     0,   635,
     637,     0,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    28,    29,    30,    31,    38,    39,    40,
      80,    81,    25,    26,   647,    82,     0,     0,     0,   649,
     650,   651,     0,     0,   652,     0,     0,   653,     0,     0,
       0,     0,   654,     0,     0,     0,     0,     0,     0,     0,
     655,     0,     0,     0,   656,     0,     0,     0,   657,     0,
       0,     0,     0,     0,     0,   658,     0,     0,     0,     0,
     472,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   670,     0,     0,     0,     0,     0,     0,     0,     0,
     473,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    28,    29,    30,    31,    38,    39,    40,     0,
       0,    25,    26,     0,     0,     0,   187,     0,   188,   189,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,     0,   207,
       0,     0,     0,   272,   273,   274,   275,   276,   277,   278,
     208,     0,     0,     0,     0,     0,     0,     0,   209,     0,
     210,     0,     0,   211,   212,   726,   213,   727,   214,   215,
     216,     0,   217,   218,     0,   219,     0,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    28,    29,    30,    31,    38,    39,
      40,   457,   458,    25,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   247,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,   116,   117,   118,   119,     0,     0,     0,  -304,     0,
     187,     0,   188,   189,   190,   191,   192,   193,   194,   195,
     120,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,     0,   207,     0,     0,   115,   116,   117,   118,
     119,     0,     0,     0,   208,   184,     0,     0,     0,     0,
       0,     0,   209,     0,   210,     0,   120,   211,   212,     0,
     213,     0,   214,   215,   216,     0,   217,   218,     0,   219,
       0,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,     0,     0,   115,
     116,   117,   118,   119,     0,     0,     0,     0,     0,     0,
       0,     0,    38,    39,    40,     0,     0,    25,    26,   120,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    28,    29,    30,    31,    38,    39,    40,    80,
      81,    25,    26,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    28,    29,
      30,    31,    38,    39,    40,    80,    81,    25,    26,     0,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    28,    29,    30,    31,    38,    39,    40,    80,    81,
      25,    26,   247,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   269,   270,     0,   271,   187,     0,
     188,   189,   190,   191,   192,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
       0,   207,     0,     0,     0,   272,   273,   274,   275,   276,
     277,   278,   208,     0,     0,     0,     0,     0,     0,     0,
     209,     0,   210,     0,     0,   211,   212,     0,   213,     0,
     214,   215,   216,     0,   217,   218,     0,   219,     0,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    28,    29,    30,    31,
      38,    39,    40,   247,     0,    25,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   187,
       0,   188,   189,   190,   191,   192,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,     0,   207,     0,     0,     0,   272,   273,   274,   275,
     276,   277,   278,   208,     0,     0,     0,     0,     0,     0,
       0,   209,     0,   210,     0,     0,   211,   212,     0,   213,
       0,   214,   215,   216,     0,   217,   218,     0,   219,     0,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    28,    29,    30,
      31,    38,    39,    40,   473,     0,    25,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     187,     0,   188,   189,   190,   191,   192,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,     0,   207,     0,     0,     0,   272,   273,   274,
     275,   276,   277,   278,   208,     0,     0,     0,     0,     0,
       0,     0,   209,     0,   210,     0,     0,   211,   212,     0,
     213,     0,   214,   215,   216,     0,   217,   218,     0,   219,
       0,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    28,    29,
      30,    31,    38,    39,    40,   186,     0,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   187,     0,   188,   189,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,     0,   207,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   208,     0,     0,     0,     0,
       0,     0,     0,   209,     0,   210,     0,     0,   211,   212,
       0,   213,     0,   214,   215,   216,     0,   217,   218,     0,
     219,     0,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   247,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    39,    40,     0,     0,    25,    26,
       0,     0,     0,     0,   187,     0,   188,   189,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,     0,   207,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   208,     0,
       0,     0,     0,     0,     0,     0,   209,     0,   210,     0,
       0,   211,   212,     0,   213,     0,   214,   215,   216,     0,
     217,   218,     0,   219,     0,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    39,    40
  };

  /* YYCHECK.  */
  const short int
  MapSetParser::yycheck_[] =
  {
        11,   101,   111,    12,    13,    14,    15,    16,   207,   172,
     176,   111,   195,   176,   373,   525,   172,    27,    27,    43,
      91,   142,    52,   359,   614,   385,   386,    23,    54,   138,
     685,    43,    23,    40,    43,    41,    41,    43,   138,    43,
      26,    41,    51,    16,   404,    54,   167,    44,     0,    40,
      59,    24,    52,   166,   167,    52,    42,    51,    43,    51,
      54,    43,    54,    19,    17,    18,   721,   369,    44,    54,
     179,    67,    54,   236,    65,   161,    52,   136,    17,   179,
     236,    34,   248,    68,   143,   248,    68,    40,    32,    33,
     101,   100,   101,    41,    20,    48,    49,   168,    51,    40,
     111,    12,   111,    14,    15,   114,    55,   101,    54,   101,
     666,   667,    51,   623,   105,    54,   299,   111,   148,   111,
      24,    60,   104,   459,   654,   136,   656,   138,    43,   138,
     141,   142,   143,   142,    54,   161,   162,   163,    40,    54,
     166,   167,   162,   148,   138,   169,   138,   158,   142,   158,
     142,   161,   162,   163,   490,   745,   167,   169,   167,   166,
     167,   172,   101,   169,   158,   169,   158,    56,   179,    41,
     179,   124,   111,   167,   476,   167,   161,   162,   163,   161,
     162,   163,    40,    43,   104,   179,   161,   179,    41,   104,
      47,   130,    51,   359,    54,    54,   359,   136,    47,   138,
     399,    43,   141,   142,   143,   144,   369,    94,    68,   157,
     158,   159,   160,   369,    40,   161,   162,   163,    29,   158,
      34,   161,   162,   163,    95,   236,   166,   167,   167,   157,
     158,   159,   160,   172,   161,   162,   163,   176,    21,    22,
     179,   161,   162,   163,   104,    78,   161,   162,   163,    65,
      66,    56,   611,   269,   270,   271,   543,   544,   768,   549,
     550,    28,    43,    43,   373,    43,    43,    43,    25,    43,
      43,    43,    43,   373,    43,    43,   169,    43,    35,    36,
      37,    38,    39,    43,    43,    43,    43,   392,   393,   394,
     395,   396,   397,   459,    43,   461,   459,   236,    55,    43,
      43,   161,   162,   163,    43,   316,   166,   167,    43,   248,
      43,    43,    43,   476,   169,    43,    43,    43,    43,    43,
     476,    43,    43,    43,   490,    43,    43,   490,    43,    43,
      43,    43,    43,    43,    43,   151,   152,   153,   154,   155,
     156,    43,   541,    43,    29,   356,    41,    53,   359,     3,
       4,     5,     6,     7,     8,     9,    10,    11,   369,    13,
     369,    47,   373,    52,   373,   376,   377,   378,    43,   380,
      43,   380,    43,    21,    93,   369,   387,   369,    44,   373,
      33,   373,    32,   148,   148,    42,   380,    57,   380,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    44,   169,    44,    59,    60,    61,    62,    63,    64,
     359,    58,    44,   606,    69,    70,    70,    44,    52,   612,
     369,    52,    52,    44,   373,    44,    52,   376,   377,   378,
      44,   380,    44,    44,    52,    44,    44,    44,   459,    52,
      44,    44,    44,    44,    44,    44,    44,    52,    44,    44,
      44,    67,    44,    44,    44,   476,    44,   476,    44,    52,
      44,    44,    44,    52,    44,    52,    44,    44,    44,    43,
      43,   106,   476,    44,   476,    47,   669,    44,    44,    44,
      44,    44,    52,    44,    52,    44,    44,    44,    44,    44,
      44,   148,   611,    53,    44,    41,    93,    50,    79,    44,
     106,   611,    53,    44,   525,    44,   525,    41,   603,    53,
     459,    59,   601,   370,   485,   476,   144,   710,   236,   459,
     365,   525,   248,   525,   364,   372,   733,   476,   138,   659,
     376,   380,   298,   747,   378,   681,   506,   509,   683,   533,
     531,   490,   545,   656,   402,   766,   402,   740,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   506,    -1,   508,
     509,    -1,    -1,    -1,    -1,    -1,    -1,   760,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   525,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     611,    -1,   611,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   623,    -1,   623,    -1,    -1,   611,    -1,   611,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   623,
      -1,   623,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,   666,   667,   169,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   611,    -1,    -1,   614,    -1,   616,    -1,    -1,
      -1,    -1,    -1,    -1,   623,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   707,    -1,   707,    -1,
      -1,   712,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   707,    -1,   707,    -1,    -1,    -1,    -1,
      -1,    -1,   733,    -1,   733,    -1,    -1,   666,   667,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   747,    -1,    -1,   733,
      -1,   733,   681,    -1,   683,    -1,    -1,    -1,    -1,   247,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   768,    -1,   768,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   707,    44,
      45,    46,    -1,    -1,   768,    -1,   768,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   733,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   300,   301,   302,    -1,   745,   305,   747,    -1,
     308,   309,   310,    -1,   312,   313,   314,   315,    -1,   317,
     318,   319,   320,   321,   322,    -1,   324,   325,   326,   768,
     328,    -1,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      -1,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    43,
      -1,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,    -1,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    -1,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    92,    -1,
      -1,    -1,    96,    97,    98,    99,   100,   101,   102,   103,
      -1,    -1,    -1,    -1,    -1,   453,    -1,   111,    -1,   113,
      -1,    -1,   116,   117,    -1,   119,    -1,   121,   122,   123,
      -1,   125,   126,    -1,   128,   473,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
      -1,    -1,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   527,
     528,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   552,   169,    -1,    -1,    -1,   557,
     558,   559,    -1,    -1,   562,    -1,    -1,   565,    -1,    -1,
      -1,    -1,   570,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     578,    -1,    -1,    -1,   582,    -1,    -1,    -1,   586,    -1,
      -1,    -1,    -1,    -1,    -1,   593,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   609,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,   166,   167,    -1,    -1,    -1,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    -1,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      -1,    -1,    -1,    96,    97,    98,    99,   100,   101,   102,
     103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,
     113,    -1,    -1,   116,   117,   693,   119,   695,   121,   122,
     123,    -1,   125,   126,    -1,   128,    -1,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    30,    31,   166,   167,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    43,    -1,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      55,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    92,    -1,    -1,    35,    36,    37,    38,
      39,    -1,    -1,    -1,   103,    44,    -1,    -1,    -1,    -1,
      -1,    -1,   111,    -1,   113,    -1,    55,   116,   117,    -1,
     119,    -1,   121,   122,   123,    -1,   125,   126,    -1,   128,
      -1,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,    -1,    -1,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   161,   162,   163,    -1,    -1,   166,   167,    55,
      -1,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,   169,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    -1,
     169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    43,   169,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    -1,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    92,    -1,    -1,    -1,    96,    97,    98,    99,   100,
     101,   102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,    -1,   113,    -1,    -1,   116,   117,    -1,   119,    -1,
     121,   122,   123,    -1,   125,   126,    -1,   128,    -1,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    43,    -1,   166,   167,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    -1,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    92,    -1,    -1,    -1,    96,    97,    98,    99,
     100,   101,   102,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,    -1,   113,    -1,    -1,   116,   117,    -1,   119,
      -1,   121,   122,   123,    -1,   125,   126,    -1,   128,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,    43,    -1,   166,   167,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    92,    -1,    -1,    -1,    96,    97,    98,
      99,   100,   101,   102,   103,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,    -1,   113,    -1,    -1,   116,   117,    -1,
     119,    -1,   121,   122,   123,    -1,   125,   126,    -1,   128,
      -1,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    43,    -1,   166,   167,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    -1,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,    -1,   113,    -1,    -1,   116,   117,
      -1,   119,    -1,   121,   122,   123,    -1,   125,   126,    -1,
     128,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,   163,    -1,    -1,   166,   167,
      -1,    -1,    -1,    -1,    69,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,   113,    -1,
      -1,   116,   117,    -1,   119,    -1,   121,   122,   123,    -1,
     125,   126,    -1,   128,    -1,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  MapSetParser::yystos_[] =
  {
         0,   171,   172,     0,    19,   187,   188,   190,   161,   173,
     189,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      13,   174,   175,    20,   191,   166,   167,   360,   157,   158,
     159,   160,   400,   409,   400,   400,   400,   400,   161,   162,
     163,   410,   411,    55,   180,   181,   186,    12,    14,    15,
     176,    40,   178,   179,    16,   206,   207,   208,   192,   400,
      91,   168,   401,   402,   403,   400,    40,   182,   183,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     164,   165,   169,   177,   361,   400,   404,   405,   406,   407,
     408,   410,   412,   178,   361,    24,   162,   400,   410,    56,
     185,    41,    40,   288,   193,    41,   184,   400,   358,   360,
     361,   289,   209,   161,    47,    35,    36,    37,    38,    39,
      55,   290,   291,   294,   350,   351,   353,   354,   355,   358,
      26,    42,   210,   215,   216,   400,   352,    41,    47,   292,
     293,   296,    43,   295,    27,   211,   212,   213,   214,   410,
      94,   217,   218,   222,    40,   247,    54,   297,   308,   359,
     360,   410,   290,   297,   302,   303,   350,   356,   357,   358,
     297,   214,    29,    34,   196,   239,    95,   219,   225,   248,
      56,   304,   307,   357,    44,   357,    43,    69,    71,    72,
      73,    74,    75,    76,    77,    78,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    92,   103,   111,
     113,   116,   117,   119,   121,   122,   123,   125,   126,   128,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   223,   224,   280,   360,
     385,   387,   389,   390,   391,   410,   240,    43,   226,   227,
     279,   280,   384,   385,    28,   220,   228,    25,   194,   197,
     249,   250,   251,   255,   309,   350,   358,   301,   306,    65,
      66,    68,    96,    97,    98,    99,   100,   101,   102,   360,
     362,   363,   366,   369,   370,   373,   374,   380,   382,   383,
     384,   385,   392,   395,   398,   400,   404,   408,   410,    78,
      43,    43,    43,   169,   386,    43,   169,   286,    43,    43,
      43,   247,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,   286,    43,    43,    43,   169,    43,   169,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,   224,    43,   169,   281,   241,   362,   227,    29,
      32,    33,   221,   234,   237,   238,    21,    22,   198,   199,
     195,    41,   254,    47,   256,   257,   311,   310,    53,   300,
      52,   305,   383,   383,   383,    43,    43,    93,   200,   201,
     365,   368,    59,    60,    61,    62,    63,    64,    69,    70,
     371,   372,   379,   381,    43,   281,   399,   247,   362,   362,
     362,   362,   362,   362,   362,   362,   362,   362,   362,   360,
     362,   362,   362,   362,   362,   362,   362,   362,   362,   362,
     362,   362,   362,   362,   362,   362,   362,   362,   362,   362,
     362,   362,   362,   362,   362,   362,   362,   362,   362,   362,
     362,   362,    21,   283,    40,   360,    44,    30,    31,   229,
     230,   231,   232,   233,   279,   360,   148,   148,   235,   238,
     236,   237,    23,    43,   202,   203,   204,   205,   280,   360,
     385,   392,   400,   404,   408,   215,    17,    18,    48,    49,
      51,   124,   239,   253,   258,   259,   261,   265,   268,   269,
     272,   273,   278,   251,   303,   320,    43,    54,    68,   104,
     312,   314,   321,   322,   323,   324,   327,   330,   332,   338,
     339,   360,   410,   298,   299,   308,   307,   283,   283,   360,
      44,    57,   364,    58,   367,   373,   373,   373,   373,   373,
     373,    70,   286,    65,    66,   375,   378,   406,   407,    23,
      67,   376,   283,    44,    44,    44,   287,    52,    52,    52,
      44,    44,    52,    44,    44,    52,    44,    44,    44,    44,
      52,    44,    44,    44,    44,    44,    44,    44,    52,    44,
      44,    44,    52,    44,    44,    44,    52,    44,    44,    44,
      44,    44,    44,    52,    44,    44,    44,   362,   245,   230,
     384,   362,   203,   217,   262,   266,   260,   270,   279,    43,
      47,   252,   274,   323,    43,    54,   104,   340,   345,   346,
     348,   410,   330,   313,   326,   329,    23,    40,    65,   105,
     331,   333,   337,   304,    23,   362,   394,   362,   366,   369,
     286,   380,   380,   376,   377,   382,   382,   362,   285,   362,
     362,   362,   362,   362,   362,   362,   362,   362,   362,   282,
      41,    43,   169,   243,   201,   196,   263,   267,   247,   271,
     362,   251,   247,    44,   343,   344,   346,    54,   347,   410,
     304,   106,   325,    67,   328,    52,   148,   336,   349,    44,
     393,    44,    44,    52,   284,    52,    44,    44,    44,    44,
     284,   388,    44,   388,    44,    44,   285,   244,    44,   359,
     359,   247,    93,   277,    44,   342,   319,   327,   332,   349,
      41,    52,   335,    53,   396,   397,   362,   362,    44,    44,
      44,    45,    46,   242,   246,   360,   400,   404,   408,   410,
     264,   247,   360,    50,   275,   106,   341,    53,   318,    41,
      41,   334,   349,    79,    44,    44,    44,   246,   247,    44,
     276,   346,   314,   315,   317,    41,    59,   247,   316,   409,
     304
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
     206,   207,   208,   208,   209,   209,   210,   211,   211,   212,
     213,   214,   215,   216,   216,   217,   218,   218,   219,   219,
     220,   220,   221,   221,   222,   223,   223,   224,   224,   224,
     224,   225,   226,   226,   227,   228,   229,   229,   230,   230,
     231,   231,   232,   233,   233,   234,   234,   235,   235,   236,
     236,   237,   238,   240,   239,   241,   241,   242,   242,   244,
     243,   243,   245,   245,   246,   246,   246,   246,   246,   246,
     246,   248,   247,   249,   249,   250,   251,   251,   252,   252,
     253,   254,   254,   255,   256,   257,   257,   258,   258,   258,
     258,   258,   258,   258,   258,   260,   259,   262,   263,   264,
     261,   266,   267,   265,   268,   270,   271,   269,   273,   274,
     272,   276,   275,   277,   277,   278,   279,   279,   279,   280,
     281,   282,   281,   283,   283,   284,   285,   285,   286,   287,
     286,   289,   288,   290,   290,   291,   292,   293,   293,   295,
     294,   296,   294,   297,   298,   299,   299,   300,   301,   301,
     302,   303,   303,   304,   305,   306,   306,   307,   308,   308,
     310,   309,   311,   309,   313,   312,   314,   314,   316,   315,
     317,   317,   318,   319,   319,   320,   321,   322,   323,   324,
     325,   326,   326,   327,   328,   329,   329,   330,   331,   331,
     332,   332,   333,   334,   334,   335,   335,   336,   336,   337,
     337,   337,   337,   338,   339,   339,   339,   339,   340,   341,
     342,   342,   343,   344,   344,   345,   345,   346,   347,   347,
     348,   348,   348,   349,   350,   350,   352,   351,   353,   354,
     354,   354,   354,   354,   355,   355,   356,   356,   357,   357,
     358,   358,   359,   359,   360,   360,   361,   361,   361,   361,
     361,   361,   362,   363,   364,   365,   365,   366,   367,   368,
     368,   369,   370,   371,   371,   372,   372,   372,   372,   372,
     372,   372,   372,   373,   374,   375,   375,   376,   376,   377,
     377,   378,   378,   378,   379,   379,   380,   381,   381,   382,
     382,   382,   382,   383,   383,   383,   383,   383,   383,   383,
     383,   384,   385,   385,   385,   385,   385,   385,   385,   385,
     385,   385,   385,   385,   385,   385,   385,   385,   385,   385,
     385,   385,   385,   385,   385,   385,   385,   385,   385,   385,
     385,   385,   385,   385,   385,   385,   385,   385,   385,   385,
     385,   385,   385,   385,   385,   385,   385,   385,   385,   385,
     385,   386,   386,   387,   388,   388,   389,   390,   391,   392,
     392,   393,   392,   394,   394,   395,   395,   395,   395,   395,
     396,   397,   397,   398,   399,   399,   400,   401,   402,   402,
     403,   403,   404,   404,   404,   405,   405,   405,   406,   406,
     406,   407,   407,   407,   408,   408,   409,   409,   409,   409,
     410,   410,   411,   411,   412,   412
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
       7,     2,     0,     1,     0,     2,     2,     1,     1,     1,
       2,     1,     2,     0,     1,     4,     0,     1,     0,     1,
       0,     1,     0,     1,     3,     1,     2,     1,     1,     4,
       1,     2,     1,     2,     1,     3,     1,     2,     1,     1,
       1,     1,     2,     1,     1,     2,     2,     0,     1,     0,
       1,     2,     2,     0,     6,     0,     2,     1,     2,     0,
       4,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     1,     1,     2,     0,     1,     0,     1,
       3,     0,     2,     2,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     3,     0,     0,     0,
       6,     0,     0,     5,     6,     0,     0,     4,     0,     0,
       4,     0,     3,     0,     2,     2,     1,     1,     1,     2,
       1,     0,     6,     0,     1,     2,     0,     2,     1,     0,
       5,     0,     4,     0,     1,     2,     2,     0,     1,     0,
       3,     0,     3,     3,     2,     0,     1,     2,     0,     2,
       1,     0,     1,     2,     2,     0,     2,     1,     1,     1,
       0,     3,     0,     3,     0,     4,     1,     1,     0,     3,
       0,     1,     2,     0,     2,     1,     1,     1,     1,     2,
       2,     0,     2,     2,     2,     0,     2,     2,     0,     1,
       1,     2,     1,     1,     2,     2,     1,     2,     3,     1,
       1,     1,     2,     1,     1,     1,     2,     3,     1,     2,
       0,     2,     2,     0,     1,     1,     3,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     0,     4,     4,     1,
       1,     1,     1,     1,     0,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     0,     2,     2,     2,     0,
       2,     1,     2,     0,     1,     2,     2,     2,     2,     2,
       2,     2,     3,     1,     2,     1,     1,     2,     2,     0,
       1,     2,     2,     2,     0,     2,     2,     0,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     4,     6,     4,     4,     4,     4,     2,
       2,     4,     4,     4,     4,     2,     1,     4,     4,     4,
       4,     6,     6,     6,     4,     4,     4,     4,     4,     4,
       4,     2,     4,     4,     4,     4,     4,     4,     2,     8,
       6,     6,     6,     4,     4,     4,     4,     4,     1,     1,
       1,     3,     1,     7,     0,     1,     7,     2,     3,     5,
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
  "ConstructQuery", "_O_QIT_LABEL_E_S_QGraphTerm_E_C",
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
  "OffsetClause", "BindingsClause", "$@5", "_QVar_E_Star",
  "_QBindingValue_E_Plus",
  "_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C",
  "$@6",
  "_Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star",
  "BindingValue", "GroupGraphPattern", "$@7",
  "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C", "GroupGraphPatternSub",
  "_QTriplesBlock_E_Opt", "_QGT_DOT_E_Opt",
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
       171,     0,    -1,    -1,   172,   187,   173,   174,    -1,    -1,
     173,   175,    -1,    -1,   174,   206,    -1,     3,   360,   400,
     400,    -1,     4,   400,    -1,     5,   400,    -1,     6,   400,
      -1,     7,   400,    -1,     8,   400,    -1,     9,   410,    -1,
      10,   180,    -1,    11,   176,    -1,    13,   179,    -1,    12,
      -1,    15,    -1,    14,    -1,    -1,   361,    -1,    40,   177,
      41,   358,    -1,   178,    -1,   179,   178,    -1,   181,   182,
      -1,    -1,   186,    -1,    -1,   183,    -1,    40,   185,    41,
      -1,   400,    47,   400,    -1,    -1,   185,   184,    -1,    55,
     400,    56,    -1,   188,   189,    -1,    -1,   190,    -1,    -1,
     189,   191,    -1,    19,   161,    -1,    -1,    -1,    20,   192,
     162,   193,   161,    -1,    -1,   197,   195,   215,   217,   196,
      -1,    -1,   239,    -1,    25,   199,   205,    -1,    21,    -1,
      22,    -1,    -1,   198,    -1,    93,   360,    -1,    -1,   200,
      -1,    43,   362,   201,    44,    -1,   360,    -1,   392,    -1,
     385,    -1,   280,    -1,   400,    -1,   404,    -1,   408,    -1,
     202,    -1,   203,    -1,   204,   203,    -1,   204,    -1,    23,
      -1,   208,    24,   288,   209,   215,   217,   196,    -1,    16,
     361,    -1,    -1,   207,    -1,    -1,   209,   210,    -1,    26,
     211,    -1,   212,    -1,   213,    -1,   214,    -1,    27,   214,
      -1,   410,    -1,   216,   247,    -1,    -1,    42,    -1,   218,
     219,   220,   221,    -1,    -1,   222,    -1,    -1,   225,    -1,
      -1,   228,    -1,    -1,   234,    -1,    94,    29,   223,    -1,
     224,    -1,   223,   224,    -1,   385,    -1,   280,    -1,    43,
     362,   201,    44,    -1,   360,    -1,    95,   226,    -1,   227,
      -1,   226,   227,    -1,   279,    -1,    28,    29,   229,    -1,
     230,    -1,   229,   230,    -1,   232,    -1,   233,    -1,    30,
      -1,    31,    -1,   231,   384,    -1,   279,    -1,   360,    -1,
     237,   235,    -1,   238,   236,    -1,    -1,   238,    -1,    -1,
     237,    -1,    32,   148,    -1,    33,   148,    -1,    -1,    34,
     240,   241,    40,   245,    41,    -1,    -1,   241,   360,    -1,
     246,    -1,   242,   246,    -1,    -1,    43,   244,   242,    44,
      -1,   169,    -1,    -1,   245,   243,    -1,   410,    -1,   400,
      -1,   404,    -1,   408,    -1,    45,    -1,    46,    -1,   360,
      -1,    -1,    40,   248,   249,    41,    -1,   194,    -1,   250,
      -1,   251,   254,    -1,    -1,   255,    -1,    -1,    47,    -1,
     258,   252,   251,    -1,    -1,   254,   253,    -1,   309,   257,
      -1,    47,   251,    -1,    -1,   256,    -1,   272,    -1,   259,
      -1,   269,    -1,   261,    -1,   265,    -1,   278,    -1,   268,
      -1,   239,    -1,    -1,    48,   260,   247,    -1,    -1,    -1,
      -1,    17,   262,   263,   359,   264,   247,    -1,    -1,    -1,
      18,   266,   267,   359,   247,    -1,   124,    43,   362,    93,
     360,    44,    -1,    -1,    -1,    49,   270,   271,   247,    -1,
      -1,    -1,   273,   274,   247,   277,    -1,    -1,    50,   276,
     247,    -1,    -1,   277,   275,    -1,    51,   279,    -1,   384,
      -1,   385,    -1,   280,    -1,   410,   281,    -1,   169,    -1,
      -1,    43,   283,   362,   282,   285,    44,    -1,    -1,    21,
      -1,    52,   362,    -1,    -1,   285,   284,    -1,   169,    -1,
      -1,    43,   362,   287,   285,    44,    -1,    -1,    40,   289,
     290,    41,    -1,    -1,   291,    -1,   294,   293,    -1,    47,
     290,    -1,    -1,   292,    -1,    -1,   358,   295,   297,    -1,
      -1,   350,   296,   302,    -1,   308,   304,   301,    -1,   308,
     304,    -1,    -1,   298,    -1,    53,   299,    -1,    -1,   301,
     300,    -1,   303,    -1,    -1,   297,    -1,   307,   306,    -1,
      52,   307,    -1,    -1,   306,   305,    -1,   357,    -1,   359,
      -1,    54,    -1,    -1,   358,   310,   312,    -1,    -1,   350,
     311,   320,    -1,    -1,   314,   313,   304,   319,    -1,   321,
      -1,   322,    -1,    -1,   314,   316,   304,    -1,    -1,   315,
      -1,    53,   317,    -1,    -1,   319,   318,    -1,   303,    -1,
     323,    -1,   360,    -1,   324,    -1,   327,   326,    -1,   106,
     327,    -1,    -1,   326,   325,    -1,   332,   329,    -1,    67,
     332,    -1,    -1,   329,   328,    -1,   338,   331,    -1,    -1,
     333,    -1,   330,    -1,   104,   330,    -1,   337,    -1,    41,
      -1,   349,    41,    -1,    52,   334,    -1,    41,    -1,   349,
     335,    -1,    52,   349,    41,    -1,    23,    -1,   105,    -1,
      65,    -1,    40,   336,    -1,   339,    -1,   410,    -1,    54,
      -1,    68,   340,    -1,    43,   323,    44,    -1,   345,    -1,
     106,   346,    -1,    -1,   342,   341,    -1,   346,   342,    -1,
      -1,   343,    -1,   346,    -1,    43,   344,    44,    -1,   348,
      -1,   410,    -1,    54,    -1,   410,    -1,    54,    -1,   104,
     347,    -1,   148,    -1,   353,    -1,   351,    -1,    -1,    55,
     352,   297,    56,    -1,   355,    43,   356,    44,    -1,    35,
      -1,    36,    -1,    37,    -1,    38,    -1,    39,    -1,    -1,
     354,    -1,   357,    -1,   356,   357,    -1,   358,    -1,   350,
      -1,   360,    -1,   361,    -1,   360,    -1,   410,    -1,   166,
      -1,   167,    -1,   410,    -1,   400,    -1,   404,    -1,   408,
      -1,   412,    -1,   169,    -1,   363,    -1,   366,   365,    -1,
      57,   366,    -1,    -1,   365,   364,    -1,   369,   368,    -1,
      58,   369,    -1,    -1,   368,   367,    -1,   370,    -1,   373,
     371,    -1,    -1,   372,    -1,    59,   373,    -1,    60,   373,
      -1,    61,   373,    -1,    62,   373,    -1,    63,   373,    -1,
      64,   373,    -1,    70,   286,    -1,    69,    70,   286,    -1,
     374,    -1,   380,   379,    -1,   406,    -1,   407,    -1,    23,
     382,    -1,    67,   382,    -1,    -1,   376,    -1,    65,   380,
      -1,    66,   380,    -1,   375,   377,    -1,    -1,   379,   378,
      -1,   382,   381,    -1,    -1,   381,   376,    -1,    68,   383,
      -1,    65,   383,    -1,    66,   383,    -1,   383,    -1,   384,
      -1,   385,    -1,   398,    -1,   400,    -1,   404,    -1,   408,
      -1,   360,    -1,   392,    -1,    43,   362,    44,    -1,    80,
      43,   362,    44,    -1,    81,    43,   362,    44,    -1,    82,
      43,   362,    52,   362,    44,    -1,    83,    43,   362,    44,
      -1,    84,    43,   360,    44,    -1,    71,    43,   362,    44,
      -1,    72,    43,   362,    44,    -1,    73,   386,    -1,   116,
     169,    -1,   139,    43,   362,    44,    -1,   136,    43,   362,
      44,    -1,   128,    43,   362,    44,    -1,   122,    43,   362,
      44,    -1,    92,   286,    -1,   389,    -1,   143,    43,   362,
      44,    -1,   140,    43,   362,    44,    -1,   138,    43,   362,
      44,    -1,   134,    43,   362,    44,    -1,   125,    43,   362,
      52,   362,    44,    -1,   135,    43,   362,    52,   362,    44,
      -1,   142,    43,   362,    52,   362,    44,    -1,   113,    43,
     362,    44,    -1,   145,    43,   362,    44,    -1,   137,    43,
     362,    44,    -1,   133,    43,   362,    44,    -1,   130,    43,
     362,    44,    -1,   126,    43,   362,    44,    -1,   121,    43,
     362,    44,    -1,   119,   169,    -1,   111,    43,   362,    44,
      -1,   144,    43,   362,    44,    -1,   141,    43,   362,    44,
      -1,   132,    43,   362,    44,    -1,   123,    43,   362,    44,
      -1,   117,    43,   362,    44,    -1,    74,   286,    -1,    75,
      43,   362,    52,   362,    52,   362,    44,    -1,    76,    43,
     362,    52,   362,    44,    -1,    77,    43,   362,    52,   362,
      44,    -1,    85,    43,   362,    52,   362,    44,    -1,    86,
      43,   362,    44,    -1,    87,    43,   362,    44,    -1,    88,
      43,   362,    44,    -1,    89,    43,   362,    44,    -1,   103,
      43,   362,    44,    -1,   387,    -1,   390,    -1,   391,    -1,
      43,   362,    44,    -1,   169,    -1,    90,    43,   362,    52,
     362,   388,    44,    -1,    -1,   284,    -1,   131,    43,   362,
      52,   362,   388,    44,    -1,    78,   247,    -1,    69,    78,
     247,    -1,    96,    43,   283,   394,    44,    -1,   395,    43,
     283,   362,    44,    -1,    -1,   101,    43,   283,   362,   393,
     397,    44,    -1,    23,    -1,   362,    -1,    97,    -1,    98,
      -1,    99,    -1,   100,    -1,   102,    -1,    53,    79,    59,
     409,    -1,    -1,   396,    -1,   410,   399,    -1,    -1,   281,
      -1,   409,   403,    -1,    91,   410,    -1,   168,    -1,   401,
      -1,    -1,   402,    -1,   405,    -1,   406,    -1,   407,    -1,
     148,    -1,   149,    -1,   150,    -1,   151,    -1,   152,    -1,
     153,    -1,   154,    -1,   155,    -1,   156,    -1,   146,    -1,
     147,    -1,   157,    -1,   159,    -1,   158,    -1,   160,    -1,
     161,    -1,   411,    -1,   163,    -1,   162,    -1,   164,    -1,
     165,    -1
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
     171,   179,   182,   183,   185,   186,   189,   192,   194,   196,
     198,   201,   203,   206,   207,   209,   214,   215,   217,   218,
     220,   221,   223,   224,   226,   230,   232,   235,   237,   239,
     244,   246,   249,   251,   254,   256,   260,   262,   265,   267,
     269,   271,   273,   276,   278,   280,   283,   286,   287,   289,
     290,   292,   295,   298,   299,   306,   307,   310,   312,   315,
     316,   321,   323,   324,   327,   329,   331,   333,   335,   337,
     339,   341,   342,   347,   349,   351,   354,   355,   357,   358,
     360,   364,   365,   368,   371,   374,   375,   377,   379,   381,
     383,   385,   387,   389,   391,   393,   394,   398,   399,   400,
     401,   408,   409,   410,   416,   423,   424,   425,   430,   431,
     432,   437,   438,   442,   443,   446,   449,   451,   453,   455,
     458,   460,   461,   468,   469,   471,   474,   475,   478,   480,
     481,   487,   488,   493,   494,   496,   499,   502,   503,   505,
     506,   510,   511,   515,   519,   522,   523,   525,   528,   529,
     532,   534,   535,   537,   540,   543,   544,   547,   549,   551,
     553,   554,   558,   559,   563,   564,   569,   571,   573,   574,
     578,   579,   581,   584,   585,   588,   590,   592,   594,   596,
     599,   602,   603,   606,   609,   612,   613,   616,   619,   620,
     622,   624,   627,   629,   631,   634,   637,   639,   642,   646,
     648,   650,   652,   655,   657,   659,   661,   664,   668,   670,
     673,   674,   677,   680,   681,   683,   685,   689,   691,   693,
     695,   697,   699,   702,   704,   706,   708,   709,   714,   719,
     721,   723,   725,   727,   729,   730,   732,   734,   737,   739,
     741,   743,   745,   747,   749,   751,   753,   755,   757,   759,
     761,   763,   765,   767,   770,   773,   774,   777,   780,   783,
     784,   787,   789,   792,   793,   795,   798,   801,   804,   807,
     810,   813,   816,   820,   822,   825,   827,   829,   832,   835,
     836,   838,   841,   844,   847,   848,   851,   854,   855,   858,
     861,   864,   867,   869,   871,   873,   875,   877,   879,   881,
     883,   885,   889,   894,   899,   906,   911,   916,   921,   926,
     929,   932,   937,   942,   947,   952,   955,   957,   962,   967,
     972,   977,   984,   991,   998,  1003,  1008,  1013,  1018,  1023,
    1028,  1033,  1036,  1041,  1046,  1051,  1056,  1061,  1066,  1069,
    1078,  1085,  1092,  1099,  1104,  1109,  1114,  1119,  1124,  1126,
    1128,  1130,  1134,  1136,  1144,  1145,  1147,  1155,  1158,  1162,
    1168,  1174,  1175,  1183,  1185,  1187,  1189,  1191,  1193,  1195,
    1197,  1202,  1203,  1205,  1208,  1209,  1211,  1214,  1217,  1219,
    1221,  1222,  1224,  1226,  1228,  1230,  1232,  1234,  1236,  1238,
    1240,  1242,  1244,  1246,  1248,  1250,  1252,  1254,  1256,  1258,
    1260,  1262,  1264,  1266,  1268,  1270
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  MapSetParser::yyrline_[] =
  {
         0,   453,   453,   453,   459,   461,   465,   467,   471,   480,
     483,   486,   489,   492,   495,   498,   500,   504,   510,   513,
     516,   522,   525,   529,   541,   542,   546,   549,   551,   554,
     556,   560,   564,   569,   571,   575,   582,   586,   588,   592,
     594,   598,   604,   606,   604,   616,   616,   627,   630,   635,
     643,   646,   653,   656,   661,   668,   671,   676,   683,   686,
     689,   692,   695,   698,   701,   705,   710,   713,   721,   724,
     731,   741,   747,   750,   755,   758,   766,   773,   774,   778,
     784,   790,   797,   804,   806,   811,   818,   821,   826,   829,
     834,   837,   842,   846,   850,   857,   860,   867,   870,   873,
     876,   882,   888,   891,   898,   903,   910,   914,   922,   924,
     932,   935,   943,   951,   952,   959,   963,   971,   974,   979,
     982,   986,   992,   999,   999,  1007,  1009,  1015,  1018,  1024,
    1024,  1029,  1035,  1037,  1041,  1044,  1047,  1050,  1053,  1056,
    1059,  1066,  1066,  1078,  1079,  1084,  1088,  1090,  1098,  1100,
    1105,  1109,  1112,  1128,  1133,  1137,  1140,  1144,  1145,  1146,
    1147,  1148,  1149,  1150,  1151,  1157,  1157,  1172,  1175,  1177,
    1172,  1188,  1191,  1188,  1200,  1206,  1209,  1206,  1219,  1222,
    1219,  1232,  1232,  1246,  1248,  1252,  1263,  1264,  1265,  1269,
    1277,  1281,  1281,  1290,  1293,  1300,  1306,  1308,  1322,  1325,
    1325,  1335,  1335,  1343,  1345,  1350,  1355,  1359,  1361,  1365,
    1365,  1368,  1368,  1375,  1380,  1384,  1386,  1391,  1395,  1397,
    1402,  1406,  1408,  1413,  1418,  1422,  1424,  1428,  1435,  1439,
    1447,  1447,  1450,  1450,  1456,  1456,  1462,  1463,  1467,  1467,
    1472,  1474,  1478,  1481,  1483,  1487,  1491,  1495,  1501,  1505,
    1509,  1512,  1514,  1518,  1522,  1527,  1529,  1535,  1538,  1540,
    1546,  1547,  1553,  1557,  1558,  1562,  1563,  1567,  1568,  1572,
    1573,  1574,  1575,  1579,  1583,  1586,  1589,  1592,  1598,  1602,
    1605,  1607,  1611,  1614,  1616,  1620,  1621,  1625,  1629,  1630,
    1634,  1635,  1636,  1640,  1645,  1646,  1650,  1650,  1663,  1688,
    1691,  1694,  1697,  1700,  1707,  1710,  1715,  1719,  1726,  1727,
    1731,  1734,  1738,  1741,  1747,  1748,  1752,  1755,  1758,  1761,
    1764,  1765,  1771,  1776,  1785,  1792,  1795,  1803,  1812,  1819,
    1822,  1829,  1834,  1845,  1848,  1852,  1855,  1858,  1861,  1864,
    1867,  1870,  1873,  1879,  1884,  1893,  1896,  1903,  1906,  1913,
    1916,  1921,  1924,  1928,  1942,  1945,  1953,  1962,  1965,  1972,
    1975,  1978,  1981,  1985,  1986,  1987,  1988,  1991,  1994,  1997,
    2000,  2004,  2010,  2013,  2016,  2019,  2022,  2025,  2028,  2032,
    2035,  2038,  2041,  2044,  2047,  2050,  2053,  2054,  2057,  2060,
    2063,  2066,  2069,  2072,  2075,  2078,  2081,  2084,  2087,  2090,
    2093,  2096,  2099,  2102,  2105,  2108,  2111,  2114,  2117,  2121,
    2124,  2127,  2130,  2133,  2136,  2139,  2142,  2145,  2148,  2149,
    2150,  2156,  2159,  2166,  2173,  2176,  2180,  2186,  2193,  2200,
    2203,  2207,  2207,  2219,  2223,  2227,  2230,  2233,  2236,  2239,
    2245,  2251,  2254,  2258,  2268,  2271,  2276,  2284,  2291,  2295,
    2303,  2307,  2311,  2312,  2313,  2317,  2318,  2319,  2323,  2324,
    2325,  2329,  2330,  2331,  2335,  2336,  2340,  2341,  2342,  2343,
    2347,  2348,  2352,  2353,  2357,  2358
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
  const int MapSetParser::yylast_ = 2078;
  const int MapSetParser::yynnts_ = 243;
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
#line 4687 "lib/MapSetParser/MapSetParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 2364 "lib/MapSetParser/MapSetParser.ypp"
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


