
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
	static_cast<MapSet*>(driver.root)->server = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 424 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->user = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 427 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->password = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 430 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->database = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 433 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->stemURI = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 438 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.sharedVarsSet = true;
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 442 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.lastRuleTermSet = false;
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 448 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_PROMISCUOUS;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 451 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_VARNAMES;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 454 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_DRACONIAN;
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 460 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = NULL;
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 467 "lib/MapSetParser/MapSetParser.ypp"
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
#line 502 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->keyMap[(yysemantic_stack_[(3) - (1)].p_RDFLiteral)->getLexicalValue()] = (yysemantic_stack_[(3) - (3)].p_RDFLiteral)->getLexicalValue();
    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 513 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->primaryKey = (yysemantic_stack_[(3) - (2)].p_RDFLiteral);
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 536 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 542 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 544 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 546 "lib/MapSetParser/MapSetParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 554 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 557 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 565 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 568 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yysemantic_stack_[(5) - (3)].p_WhereClause)->m_BindingClause = (yysemantic_stack_[(5) - (5)].p_BindingsClause);
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(5) - (1)].p_Project).distinctness, (yysemantic_stack_[(5) - (1)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(5) - (3)].p_WhereClause), (yysemantic_stack_[(5) - (4)].p_SolutionModifier))));
      }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 576 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 584 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 587 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 594 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 602 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 609 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 617 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 624 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 627 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
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
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 639 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 642 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 651 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 654 "lib/MapSetParser/MapSetParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 662 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 665 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 671 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = NULL;
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 674 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (2)].p_TTerm);
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 681 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(7) - (5)].p_WhereClause)->m_BindingClause = (yysemantic_stack_[(7) - (7)].p_BindingsClause);
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	Construct* constr = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(7) - (3)].p_BasicGraphPattern), (yysemantic_stack_[(7) - (4)].p_DatasetClauses), (yysemantic_stack_[(7) - (5)].p_WhereClause), (yysemantic_stack_[(7) - (6)].p_SolutionModifier));
	driver.root->maps.push_back(LabeledConstruct((yysemantic_stack_[(7) - (1)].p_TTerm), constr));
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 691 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 703 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 709 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 715 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 722 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp ? driver.curOp : new DefaultGraphPattern(), NULL);
	driver.curOp = NULL;
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 736 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 743 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 751 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 759 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 767 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 775 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 782 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 785 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 792 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
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
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 801 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 807 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 813 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 816 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 828 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 835 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 839 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 849 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 857 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 860 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 868 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 877 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 884 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 888 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 896 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 904 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 911 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 917 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 930 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTermList) = new TTermList;
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 933 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTermList)->push_back((yysemantic_stack_[(2) - (2)].p_Variable));
	(yyval.p_TTermList) = (yysemantic_stack_[(2) - (1)].p_TTermList);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 940 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 943 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 949 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding = new Binding();
      }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 951 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BindingValue) = driver.curBinding;
	  driver.curBinding = NULL;
      }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 955 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBinding = new Binding();
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 961 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 964 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBindingsClause->push_back((yysemantic_stack_[(2) - (2)].p_BindingValue));
	(yyval.p_BindingValues) = NULL;
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 971 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBindingsClause = new BindingClause((yysemantic_stack_[(3) - (2)].p_TTermList));
      }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 973 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BindingsClause) = driver.curBindingsClause;
	  driver.curBindingsClause = NULL;
      }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 980 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BindingsClause) = NULL;
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 987 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 990 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 993 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 996 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 999 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1002 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1015 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1018 "lib/MapSetParser/MapSetParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 1098 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 1101 "lib/MapSetParser/MapSetParser.ypp"
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

  case 164:

/* Line 678 of lalr1.cc  */
#line 1113 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1116 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1118 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1121 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1129 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1132 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1134 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(5) - (4)].p_TTerm), driver.curOp, driver.atomFactory, false));
      }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 1141 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = new Bind(driver.curOp, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 1147 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 1150 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1152 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.curOp));
      }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 1160 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 1163 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 1165 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 1173 "lib/MapSetParser/MapSetParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
      }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 1178 "lib/MapSetParser/MapSetParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 1193 "lib/MapSetParser/MapSetParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    if (driver.curOp == NULL)
		driver.ensureBasicGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 1210 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 1218 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 1222 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 1224 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = NULL;
      }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 1231 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
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
#line 1241 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 1249 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1263 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1266 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1268 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1276 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 1278 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 1306 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 1309 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 1369 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 1376 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 1380 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 1388 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 1391 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 1397 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 1408 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 1436 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 1463 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 1470 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 1481 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 1488 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 1524 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 1527 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 1530 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 1533 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 1591 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 1595 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 1604 "lib/MapSetParser/MapSetParser.ypp"
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

  case 296:

/* Line 678 of lalr1.cc  */
#line 1629 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 1632 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 1635 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 1638 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 1641 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 1648 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 1656 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 1660 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 1672 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 1679 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 1682 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 1693 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 1696 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 1699 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 1702 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 1706 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 1717 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 1726 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 1733 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 1736 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 1744 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 1753 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 1760 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 1763 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 1775 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_GeneralComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_GeneralComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_GeneralComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 1786 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 1793 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 1796 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 1799 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 1802 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 1805 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 1808 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 1811 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 1814 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 1825 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 1834 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
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
#line 1844 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 1847 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 1854 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 1862 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 1865 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 1869 "lib/MapSetParser/MapSetParser.ypp"
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

  case 351:

/* Line 678 of lalr1.cc  */
#line 1883 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 1886 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 1894 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 1903 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 1906 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 1913 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 1916 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 1919 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 1929 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 1932 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 1935 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 1938 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 1945 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 1951 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 1954 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 1957 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 1960 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 1963 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 1966 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
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
#line 1973 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_blank, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 1976 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 1979 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 1982 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ciel, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 1985 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 1988 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 1991 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::XPATH_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 1995 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlen, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 1998 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ucase, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 2001 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lcase, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 2004 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encodeForUri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 2007 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 2010 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strStarts, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 2013 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strEnds, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 2016 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 2019 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 2022 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 2025 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 2028 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 2031 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 2034 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 2037 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 2040 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 2043 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 2046 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha224, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 2049 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 2052 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 2055 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 2058 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 2062 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 2065 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 2068 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 2071 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 2074 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
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
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 2083 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 2086 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 2097 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 2100 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 2107 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_regex, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 2114 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 2121 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 2127 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 2134 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 2141 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 2144 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 2148 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 2150 "lib/MapSetParser/MapSetParser.ypp"
    {
	  // x = new ArgList($2, driver.curExprList);
	  delete driver.curExprList;
	  driver.curExprList = NULL;
	  w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // $$ = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group-concat, $3, $4.p_Expression, $4.separator));
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 2160 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
	driver.countStar = true;
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 2168 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 2171 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 2174 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 2177 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 2180 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 2186 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 2192 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 2199 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 2209 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 2217 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 2225 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 2232 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 2236 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 2244 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 3086 "lib/MapSetParser/MapSetParser.cpp"
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
  const short int MapSetParser::yypact_ninf_ = -650;
  const short int
  MapSetParser::yypact_[] =
  {
      -650,    57,    49,  -650,   -98,  -650,  -650,  -650,  -650,   373,
      56,  -112,   103,   103,   103,   103,    78,    37,   221,    62,
      33,  -650,  -650,  -650,  -650,  -650,   103,  -650,  -650,  -650,
    -650,  -650,   -68,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,   103,  -650,    74,  -650,  -650,  -650,  -650,  -650,   280,
    -650,    62,   280,    95,  -650,    -3,   103,    78,  -650,  -650,
    -650,  -650,   102,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
     125,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,   128,  -650,  -650,  -650,  -650,   -20,   876,  -650,
    -650,    18,  -650,  -650,   129,  -650,  -650,  -650,  1245,     9,
    -650,   103,  -650,  -650,  -650,  -650,  -650,  -650,   135,  -650,
     140,  -650,  -650,  -650,  -650,   144,  -650,    12,  -650,  -650,
      96,   161,  -650,    31,  -650,  1245,  -650,  -650,    31,  1331,
      31,    78,  -650,  -650,  -650,  -650,  -650,   178,   175,   126,
    -650,  -650,  -650,  -650,   164,  1331,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  1278,  -650,  -650,  -650,  -650,  1815,
    -650,  -650,  -650,  -650,  1917,   203,  -650,  1082,  -650,  -650,
    -650,  -650,  -650,  -650,  1455,   148,   189,   199,   -18,   -15,
     200,   206,   208,   161,   222,   233,   236,   237,   239,   240,
     248,   252,   254,   255,   256,   -15,   257,   258,   259,   146,
     260,   150,   273,   276,   278,   279,   281,   283,   284,   285,
     286,   287,   288,   290,   291,   292,   293,   294,   295,   297,
     298,   301,   302,   304,  1815,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,   -13,   -25,  1455,  1917,  -650,  -650,  -650,
    -650,  -650,   217,    40,  -650,    59,  -650,  -650,   282,  -650,
    -650,  -650,   303,  -650,  -650,   299,   305,  1575,  1575,  1575,
     309,  -650,  -650,  -650,  -650,   310,  -650,  -650,   262,  -650,
    -650,  -650,  -650,   195,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,   312,  -650,  -650,  -650,  -650,   -13,   161,  1455,  1455,
    1455,  -650,  -650,  1455,  -650,  -650,  1455,  1455,  1455,  -650,
    1455,  1455,  1455,  1455,  -112,  1455,  1455,  1455,  1455,  1455,
    1455,  -650,  1455,  1455,  1455,  -650,  1455,  -650,  1455,  1455,
    1455,  1455,  1455,  1455,  1455,  1455,  1455,  1455,  1455,  1455,
    1455,  1455,  1455,  1455,  1455,  1455,  1455,  1455,  1455,  1455,
    -650,   336,  -650,  -650,  -650,  -650,   315,  -650,  1221,   214,
     216,  -650,  -650,   335,   338,  -650,  -650,  -650,  1058,   330,
    -650,   197,  1245,  -650,  -650,    31,   127,    31,  -650,  1331,
    -650,  -650,  -650,  -650,   336,   336,  -112,  -650,   329,   318,
     328,  1455,  1455,  1455,  1455,  1455,  1455,   306,   -15,  -650,
    -650,   158,     8,   336,  -650,  -650,  -650,   343,   344,   345,
    -650,   339,   340,   341,   349,   351,   346,   352,   355,   350,
     356,   359,   360,   362,   357,   363,   365,   366,   367,   369,
     370,   371,   395,   378,   405,   406,   400,   408,   409,   410,
     404,   412,   413,   414,   415,   416,   417,   411,   419,   421,
     423,  -650,  1455,  -650,  -650,  -650,  -650,  1221,  -650,   374,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  1455,  -650,  -650,  1695,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,    96,  -650,  -650,  -650,  -650,  1917,   425,
    -650,   424,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,   145,  -650,     2,    44,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,   177,  -650,  -650,  -650,
    -650,  -650,  1331,  -650,   837,  1455,  -650,  -650,  1455,  -650,
    1455,  -650,  -650,  -650,  -650,  -650,  -650,  -650,   -15,  -650,
    1455,  1455,     8,  -650,  -650,  -650,  1455,  1455,  -650,  1455,
    -650,  -650,  -650,  -650,  1455,  1455,  1455,  -650,  -650,  1455,
    -650,  -650,  1455,  -650,  -650,  -650,  -650,  1455,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  1455,  -650,  -650,  -650,  1455,
    -650,  -650,  -650,  1455,  -650,  -650,  -650,  -650,  -650,  -650,
    1455,  -650,  -650,  -650,  -650,   -17,  -650,  -650,   262,  -650,
     175,  -650,  -650,   161,  -650,  -650,  1455,  -650,  1245,   161,
     427,   107,  -650,    67,  -650,  -650,  -650,  -650,  -650,  -650,
    1331,   364,   407,  -650,   -34,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,   428,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,   430,    -1,   426,   431,   432,   434,
     435,   429,   438,   429,   439,   440,  -650,  -650,  -650,  -650,
    -650,   441,  -650,   -44,   -44,  -650,   161,   394,  -650,  -650,
    -650,  -650,   443,  -650,  -650,  -650,  -650,  -650,   145,  -650,
     145,  -650,   342,  -650,  -650,     1,  -650,   436,  -650,  -650,
    1455,  -650,  1455,  -650,  -650,  -650,  -650,  -650,   446,  -650,
     447,  -650,  -650,    15,   716,  -650,  -650,   161,  -650,  -112,
     445,  -650,   387,   444,  -650,  -650,   454,  -650,    -4,  -650,
     420,  -650,   453,  -650,   455,  -650,  -650,  -650,  -650,   471,
    -650,  -650,  -650,  -650,  -650,  -650,   161,  -650,   459,  -650,
    -650,   107,  -650,   127,  -650,  -650,  -650,  -650,   463,   448,
    -650,  -650,  -650,  -650,  -650,  -650,   161,  -650,  -650,  -650,
    -650,  -650,   103,  -650,  1331,  -650,  -650
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  MapSetParser::yydefact_[] =
  {
         2,     0,    36,     1,     0,     4,    38,    37,    40,     6,
      35,     0,     0,     0,     0,     0,     0,    26,     0,     0,
       3,     5,    41,    39,   311,   312,     0,   463,   465,   464,
     466,     9,   447,    10,    11,    12,   467,   470,   469,    13,
     468,     0,    14,    28,    27,    17,    19,    18,    15,    20,
      23,    16,     0,     0,     7,     0,     0,     0,   445,   446,
     448,   443,     0,    32,    25,    29,   461,   462,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   471,   472,   318,
       0,    21,   314,   315,   449,   450,   451,   316,   313,   317,
      24,    70,     0,    42,     8,   444,    34,     0,     0,   198,
      44,     0,    30,    33,     0,    22,   307,   308,   200,    79,
      43,     0,   296,   297,   298,   299,   300,   293,     0,   201,
     204,   208,   292,   291,   302,     0,   206,     0,    80,    45,
      82,     0,    31,     0,   199,   200,   205,   202,   218,   301,
       0,     0,    72,    73,    74,    75,    77,     0,   131,    84,
      83,   141,    78,   226,     0,   301,   225,   309,   310,   203,
     219,   209,   217,   306,   301,   303,   305,   207,    76,     0,
     120,    71,   132,   119,     0,    86,    85,   146,   294,   215,
     222,   224,   295,   304,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    94,    96,    93,   415,
     383,   416,   417,     0,     0,     0,    97,    98,   100,   185,
     183,   184,     0,    88,    87,    51,   143,    46,     0,   144,
     149,   147,   153,   229,   227,   210,   220,     0,     0,     0,
       0,   432,   433,   434,   435,     0,   436,   366,    54,   319,
     322,   326,   328,   330,   340,   351,   354,   359,   360,   361,
     367,     0,   362,   363,   364,   365,   441,     0,     0,     0,
       0,   419,   376,     0,   195,   405,     0,     0,     0,   424,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   382,     0,     0,     0,   377,     0,   398,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,   190,   187,   186,   129,   121,     0,    99,     0,     0,
       0,    81,    89,   113,   115,    49,    50,    52,     0,    79,
     142,   145,   146,   154,   151,   218,     0,   212,   216,   301,
     223,   357,   358,   356,   190,   190,     0,    55,     0,   320,
     324,     0,     0,     0,     0,     0,     0,     0,     0,   329,
     331,   341,   353,   190,   442,   440,   425,     0,     0,     0,
     196,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   191,     0,   127,   368,   106,   107,   101,   102,     0,
     104,   105,   109,   110,   117,   118,   111,   114,   112,   116,
      68,     0,    64,    65,    67,    48,    60,    57,    59,    58,
      61,    62,    63,    82,   164,   168,   162,   172,     0,     0,
     150,   139,   156,   158,   159,   161,   157,   155,   176,   160,
     152,   242,   230,     0,   272,     0,     0,   228,   231,   233,
     234,   243,   245,   248,   257,   252,   255,   270,   244,   271,
     213,   214,   301,   221,     0,     0,    53,    95,     0,   323,
       0,   327,   332,   333,   334,   335,   336,   337,     0,   338,
       0,     0,   346,   352,   342,   343,     0,     0,   355,     0,
     374,   375,   418,   193,     0,     0,     0,   369,   370,     0,
     372,   373,     0,   410,   411,   412,   413,     0,   414,   399,
     391,   404,   397,   381,   403,     0,   396,   380,   395,     0,
     402,   394,   387,     0,   379,   393,   386,   378,   385,   401,
       0,   384,   400,   392,   188,     0,   103,   108,    54,    66,
     131,   165,   169,     0,   173,   182,     0,   140,   146,     0,
       0,   280,   288,     0,   273,   275,   282,   284,   287,   258,
     301,   246,   250,   266,     0,   268,   267,   254,   256,   259,
     211,   430,   431,     0,   428,   321,   325,   339,   348,   349,
     347,   350,   344,   345,     0,     0,     0,     0,     0,     0,
       0,   421,     0,   421,     0,     0,   193,   130,   124,   126,
     128,     0,    47,     0,     0,   163,     0,     0,   148,   180,
     274,   281,     0,   277,   286,   289,   285,   240,     0,   249,
       0,   253,     0,   290,   269,     0,   426,   438,   427,   197,
       0,   194,     0,   407,   408,   371,   409,   422,     0,   388,
       0,   389,   390,     0,     0,    56,   166,     0,   174,     0,
     177,   283,   279,   232,   247,   251,     0,   263,     0,   264,
       0,   439,     0,   192,     0,   420,   423,   189,   137,     0,
     122,   138,   134,   135,   136,   133,     0,   170,     0,   178,
     181,     0,   278,   237,   241,   265,   260,   262,     0,     0,
     429,   406,   125,   123,   167,   171,     0,   276,   235,   238,
     239,   261,     0,   179,   301,   437,   236
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yypgoto_[] =
  {
      -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,   456,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,   -94,  -650,    32,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,   368,   139,  -650,    27,  -650,  -650,  -650,  -650,
    -650,  -650,   289,  -650,  -650,   270,  -650,  -650,    61,  -650,
    -650,  -650,  -650,  -650,  -650,   155,   157,   -76,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -207,  -650,  -186,  -650,
    -650,  -650,  -359,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -343,
    -158,   229,  -650,  -339,  -545,  -130,  -197,  -650,  -650,  -650,
     392,  -650,  -650,  -650,  -650,  -650,  -650,   -78,  -650,  -650,
    -650,  -650,  -650,   153,  -513,  -650,  -650,   151,   152,  -650,
    -650,  -650,  -650,  -650,  -211,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,    30,  -650,  -650,  -650,  -144,  -650,  -650,
      29,  -650,  -142,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -593,  -650,  -650,  -649,
    -107,  -650,  -650,  -650,  -650,  -650,  -650,  -104,   -96,  -579,
     -11,    14,   493,  -650,  -650,  -650,    11,  -650,  -650,     6,
    -650,  -650,  -650,  -122,  -650,  -650,    -5,  -650,  -650,  -650,
    -447,  -650,  -415,    16,  -164,  -143,  -650,  -650,  -113,  -650,
    -650,  -650,  -331,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
      -9,  -650,  -650,  -650,   -30,  -650,   141,   142,    25,  -221,
      43,  -650,  -650
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yydefgoto_[] =
  {
        -1,     1,     2,     9,    20,    21,    48,    80,    50,    51,
      42,    43,    64,    65,   103,    97,    44,     5,     6,    10,
       7,    23,    55,   101,   109,   256,   369,   257,   367,   368,
     387,   388,   472,   473,   474,   475,    53,    54,   129,   142,
     143,   144,   145,   130,   131,   148,   149,   175,   253,   361,
     150,   234,   235,   176,   246,   247,   254,   457,   458,   459,
     460,   461,   362,   466,   468,   363,   364,   171,   244,   729,
     660,   704,   595,   172,   453,   173,   730,   608,   152,   177,
     258,   259,   260,   490,   371,   261,   373,   374,   491,   492,
     603,   493,   601,   663,   736,   494,   602,   664,   495,   496,
     604,   666,   497,   498,   609,   740,   756,   710,   499,   248,
     249,   353,   656,   452,   691,   645,   305,   553,   100,   108,
     118,   119,   136,   137,   120,   140,   138,   160,   520,   521,
     378,   265,   161,   162,   179,   380,   266,   180,   155,   262,
     376,   375,   507,   620,   508,   759,   764,   760,   744,   713,
     502,   509,   510,   511,   512,   679,   621,   513,   681,   622,
     514,   627,   515,   628,   747,   719,   684,   629,   516,   517,
     614,   742,   712,   671,   672,   615,   616,   675,   617,   685,
     163,   122,   133,   123,   124,   125,   164,   181,   166,   156,
     277,   107,   278,   279,   529,   389,   280,   531,   390,   281,
     282,   399,   400,   283,   284,   542,   548,   641,   543,   401,
     285,   402,   286,   287,   288,   289,   302,   239,   698,   240,
     241,   242,   290,   687,   633,   291,   721,   722,   292,   405,
     293,    59,    60,    61,   294,    84,    85,    86,   295,    32,
     296,    40,    89
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int MapSetParser::yytable_ninf_ = -302;
  const short int
  MapSetParser::yytable_[] =
  {
        26,   121,   105,    31,    33,    34,    35,   309,   321,   630,
     250,   236,   126,   500,   354,   462,   682,    56,   673,    83,
     102,    57,    83,   657,   300,   658,   238,   303,   121,   351,
     546,   251,    62,   716,   127,   165,   746,   479,   141,   126,
      82,   717,   689,    82,   611,   524,   525,    94,    52,   690,
     128,   718,    24,    25,   612,   154,   -69,     3,   727,    39,
     183,     8,   167,    81,   549,   690,    91,     4,    83,   748,
     263,   359,   360,   547,    87,    22,   236,    87,    83,   365,
     366,   264,   250,   153,   706,   707,   503,   106,   104,    82,
      41,   238,    88,   638,   639,    88,   504,   106,    58,    82,
      95,    49,   132,   251,   613,    83,   697,   677,   697,    83,
     505,   406,   683,    63,   462,    36,    37,    38,    92,   674,
      24,    25,   157,    87,   106,    83,    82,   157,   106,   157,
      82,   642,   643,    87,    83,    27,    28,    29,    30,    24,
      25,    88,   683,   479,   106,   605,    82,    83,   757,   301,
     659,    88,   304,   106,   352,    82,    96,    93,   237,   612,
      87,    36,    37,    38,    87,    98,   106,    99,    82,   503,
     146,    36,    37,    38,   111,   134,   158,   110,    88,   504,
      87,   158,    88,   158,   146,   135,   139,   503,   147,    87,
      36,    37,    38,   505,   250,    24,    25,   504,    88,   623,
     151,   539,    87,    36,    37,    38,   169,    88,   170,   613,
     476,   505,   243,   484,   485,   251,   624,   243,   178,   174,
      88,   540,   541,   237,   297,   478,    36,    37,    38,   506,
     252,   298,    45,   355,    46,    47,  -175,    36,    37,    38,
     625,   299,   306,   486,   487,   358,   488,   506,   307,   668,
     308,   766,   391,   392,   393,   394,   395,   396,    27,    28,
      29,    30,   397,   398,   310,   263,    36,    37,    38,   532,
     533,   534,   535,   536,   537,   311,   264,   243,   312,   313,
     626,   314,   315,   381,   382,   383,    36,    37,    38,   243,
     316,    24,    25,   250,   317,   597,   318,   319,   320,   322,
     323,   324,   326,   418,    36,    37,    38,    71,    72,    73,
      74,    75,    76,   325,   251,   328,   476,   327,   329,   489,
     330,   331,   370,   332,   250,   333,   334,   335,   336,   337,
     338,   478,   339,   340,   341,   342,   343,   344,   481,   345,
     346,   637,    83,   347,   348,   251,   349,   463,   372,    83,
     377,   384,   385,   386,   403,   379,   451,   477,   454,   480,
     464,   106,   465,    82,   157,   518,   157,   360,   106,   359,
      82,   128,   527,   528,   538,   526,    11,    12,    13,    14,
      15,    16,    17,    18,   530,    19,   550,   551,   552,   554,
     555,   556,   557,   482,   558,   560,   559,    87,   561,   563,
     562,   243,   564,   565,    87,   566,   568,   567,   569,   570,
     571,   243,   572,   573,   574,    88,   245,   665,   158,   519,
     158,   576,    88,   669,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    27,    28,    29,    30,    36,
      37,    38,    77,    78,   481,   575,   463,    79,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   477,   592,   480,   593,   606,   678,   607,
     670,   686,   680,   688,   693,   694,   692,   695,   696,   690,
     708,   699,   701,   702,   705,   709,   711,   720,   683,   725,
     726,   741,    83,   739,   745,   743,   750,   749,   751,   482,
     243,   263,   755,   761,   661,   762,   599,    90,   483,   168,
     600,   106,   264,    82,   752,   728,   357,   243,   596,   469,
     467,   737,   753,   350,   662,   404,   703,   159,   501,   522,
     523,   243,   758,   610,   714,   619,   636,   640,   715,   635,
     700,   765,   544,   545,     0,     0,   519,    87,   618,   519,
     754,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,     0,     0,     0,     0,
     763,     0,     0,     0,     0,     0,     0,     0,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,     0,     0,     0,     0,     0,     0,   106,     0,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   106,
       0,    82,     0,     0,     0,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    27,    28,    29,    30,
      36,    37,    38,    87,     0,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,    87,     0,     0,     0,     0,
       0,    88,   157,   157,   618,     0,   676,     0,     0,     0,
       0,     0,     0,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   733,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   731,     0,   732,     0,     0,   738,   733,
       0,     0,     0,     0,     0,     0,   158,   158,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   731,     0,
     732,   519,     0,   519,     0,     0,     0,     0,     0,   734,
       0,     0,   518,     0,    83,     0,     0,     0,   356,     0,
       0,     0,     0,     0,     0,     0,     0,   735,     0,     0,
       0,     0,     0,   106,   734,    82,     0,     0,     0,     0,
     728,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   735,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   618,     0,   519,     0,     0,    87,
       0,   407,   408,   409,     0,     0,   410,     0,     0,   411,
     412,   413,     0,   414,   415,   416,   417,    88,   419,   420,
     421,   422,   423,   424,     0,   425,   426,   427,     0,   428,
       0,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   631,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    27,    28,    29,    30,    36,    37,    38,     0,   245,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     267,   268,     0,   269,   185,     0,   186,   187,   188,   189,
     190,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,     0,   205,     0,     0,
       0,   270,   271,   272,   273,   274,   275,   276,   206,     0,
       0,     0,     0,     0,     0,   594,   207,     0,   208,     0,
       0,   209,   210,     0,   211,     0,   212,   213,   214,     0,
     215,   216,     0,   217,   598,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    27,    28,    29,    30,    36,    37,    38,     0,
       0,    24,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   632,   634,     0,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    27,    28,    29,    30,    36,    37,    38,    77,    78,
      24,    25,   644,    79,     0,     0,     0,   646,   647,   648,
       0,     0,   649,     0,     0,   650,     0,     0,     0,     0,
     651,     0,     0,     0,     0,     0,     0,     0,   652,     0,
       0,     0,   653,     0,     0,     0,   654,     0,     0,     0,
     470,     0,     0,   655,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   667,
     471,     0,     0,     0,     0,     0,   255,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   112,   113,   114,   115,
     116,     0,     0,     0,  -301,   185,     0,   186,   187,   188,
     189,   190,   191,   192,   193,   117,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,     0,   205,     0,
       0,     0,   270,   271,   272,   273,   274,   275,   276,   206,
       0,     0,     0,     0,     0,     0,     0,   207,     0,   208,
       0,     0,   209,   210,     0,   211,     0,   212,   213,   214,
       0,   215,   216,   723,   217,   724,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    27,    28,    29,    30,    36,    37,    38,
       0,     0,    24,    25,     0,     0,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    27,    28,    29,
      30,    36,    37,    38,    77,    78,    24,    25,     0,    79,
     455,   456,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   245,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   112,
     113,   114,   115,   116,     0,     0,     0,  -301,   185,     0,
     186,   187,   188,   189,   190,   191,   192,   193,   117,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
       0,   205,   112,   113,   114,   115,   116,     0,     0,     0,
       0,   182,   206,     0,     0,     0,     0,     0,     0,     0,
     207,   117,   208,     0,     0,   209,   210,     0,   211,     0,
     212,   213,   214,     0,   215,   216,     0,   217,     0,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   112,   113,   114,   115,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,    37,    38,     0,   117,    24,    25,     0,     0,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      27,    28,    29,    30,    36,    37,    38,    77,    78,    24,
      25,     0,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    27,    28,    29,    30,    36,    37,    38,
      77,    78,    24,    25,     0,    79,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    27,    28,    29,    30,
      36,    37,    38,    77,    78,    24,    25,   245,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   267,   268,
       0,   269,   185,     0,   186,   187,   188,   189,   190,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,     0,   205,     0,     0,     0,   270,
     271,   272,   273,   274,   275,   276,   206,     0,     0,     0,
       0,     0,     0,     0,   207,     0,   208,     0,     0,   209,
     210,     0,   211,     0,   212,   213,   214,     0,   215,   216,
       0,   217,     0,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      27,    28,    29,    30,    36,    37,    38,   245,     0,    24,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   185,     0,   186,   187,   188,   189,   190,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,     0,   205,     0,     0,     0,   270,
     271,   272,   273,   274,   275,   276,   206,     0,     0,     0,
       0,     0,     0,     0,   207,     0,   208,     0,     0,   209,
     210,     0,   211,     0,   212,   213,   214,     0,   215,   216,
       0,   217,     0,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      27,    28,    29,    30,    36,    37,    38,   471,     0,    24,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   185,     0,   186,   187,   188,   189,   190,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,     0,   205,     0,     0,     0,   270,
     271,   272,   273,   274,   275,   276,   206,     0,     0,     0,
       0,     0,     0,     0,   207,     0,   208,     0,     0,   209,
     210,     0,   211,     0,   212,   213,   214,     0,   215,   216,
       0,   217,     0,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      27,    28,    29,    30,    36,    37,    38,   184,     0,    24,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   185,     0,   186,   187,   188,   189,   190,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,     0,   205,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   206,     0,     0,     0,
       0,     0,     0,     0,   207,     0,   208,     0,     0,   209,
     210,     0,   211,     0,   212,   213,   214,     0,   215,   216,
       0,   217,     0,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   245,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    36,    37,    38,     0,     0,    24,
      25,     0,     0,     0,   185,     0,   186,   187,   188,   189,
     190,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,     0,   205,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   206,     0,
       0,     0,     0,     0,     0,     0,   207,     0,   208,     0,
       0,   209,   210,     0,   211,     0,   212,   213,   214,     0,
     215,   216,     0,   217,     0,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,    37,    38
  };

  /* YYCHECK.  */
  const short int
  MapSetParser::yycheck_[] =
  {
        11,   108,    98,    12,    13,    14,    15,   193,   205,   522,
     174,   169,   108,   372,    39,   358,    50,    26,   611,    49,
      40,    89,    52,    40,    42,    42,   169,    42,   135,    42,
      22,   174,    41,   682,    25,   139,    40,   368,    26,   135,
      49,    40,    43,    52,    42,   384,   385,    56,    15,    50,
      41,    50,   164,   165,    52,   133,    23,     0,    43,    16,
     164,   159,   140,    49,   403,    50,    52,    18,    98,   718,
     177,    31,    32,    65,    49,    19,   234,    52,   108,    20,
      21,   177,   246,    52,   663,   664,    42,    98,    97,    98,
      53,   234,    49,   540,   541,    52,    52,   108,   166,   108,
      57,    39,   111,   246,   102,   135,   651,   620,   653,   139,
      66,   297,   146,    39,   457,   159,   160,   161,    23,    52,
     164,   165,   133,    98,   135,   155,   135,   138,   139,   140,
     139,   546,   547,   108,   164,   155,   156,   157,   158,   164,
     165,    98,   146,   474,   155,   488,   155,   177,   741,   167,
     167,   108,   167,   164,   167,   164,    54,   160,   169,    52,
     135,   159,   160,   161,   139,    40,   177,    39,   177,    42,
     127,   159,   160,   161,    45,    40,   133,   159,   135,    52,
     155,   138,   139,   140,   141,    45,    42,    42,    92,   164,
     159,   160,   161,    66,   358,   164,   165,    52,   155,    22,
      39,   398,   177,   159,   160,   161,    28,   164,    33,   102,
     368,    66,   169,    16,    17,   358,    39,   174,    54,    93,
     177,    63,    64,   234,    76,   368,   159,   160,   161,   102,
      27,    42,    11,   244,    13,    14,    39,   159,   160,   161,
      63,    42,    42,    46,    47,    28,    49,   102,    42,   608,
      42,   764,    57,    58,    59,    60,    61,    62,   155,   156,
     157,   158,    67,    68,    42,   372,   159,   160,   161,   391,
     392,   393,   394,   395,   396,    42,   372,   234,    42,    42,
     103,    42,    42,   267,   268,   269,   159,   160,   161,   246,
      42,   164,   165,   457,    42,   459,    42,    42,    42,    42,
      42,    42,    42,   314,   159,   160,   161,   149,   150,   151,
     152,   153,   154,   167,   457,    42,   474,   167,    42,   122,
      42,    42,    40,    42,   488,    42,    42,    42,    42,    42,
      42,   474,    42,    42,    42,    42,    42,    42,   368,    42,
      42,   538,   372,    42,    42,   488,    42,   358,    45,   379,
      51,    42,    42,    91,    42,    50,    20,   368,    43,   368,
     146,   372,   146,   372,   375,   376,   377,    32,   379,    31,
     379,    41,    43,    55,    68,   386,     3,     4,     5,     6,
       7,     8,     9,    10,    56,    12,    43,    43,    43,    50,
      50,    50,    43,   368,    43,    43,    50,   372,    43,    43,
      50,   358,    43,    43,   379,    43,    43,    50,    43,    43,
      43,   368,    43,    43,    43,   372,    42,   603,   375,   376,
     377,    43,   379,   609,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   474,    50,   457,   167,    43,    43,
      50,    43,    43,    43,    50,    43,    43,    43,    43,    43,
      43,    50,    43,   474,    43,   474,    43,    42,   104,    45,
      43,    43,    65,    43,    43,    43,    50,    43,    43,    50,
     666,    43,    43,    43,    43,    91,    43,    51,   146,    43,
      43,   104,   522,    48,    40,    51,    43,    77,    43,   474,
     457,   608,    43,    40,   598,    57,   474,    51,   369,   141,
     483,   522,   608,   522,    43,    44,   246,   474,   457,   364,
     363,   707,   729,   234,   600,   296,   656,   135,   375,   377,
     379,   488,   743,   503,   678,   506,   530,   542,   680,   528,
     653,   762,   401,   401,    -1,    -1,   503,   522,   505,   506,
     736,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   522,    -1,    -1,    -1,    -1,
     756,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   608,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     620,    -1,    -1,    -1,    -1,    -1,    -1,   608,    -1,   608,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   620,
      -1,   620,    -1,    -1,    -1,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   608,    -1,   164,   165,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   620,    -1,    -1,    -1,    -1,
      -1,   608,   663,   664,   611,    -1,   613,    -1,    -1,    -1,
      -1,    -1,    -1,   620,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   704,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   704,    -1,   704,    -1,    -1,   709,   729,
      -1,    -1,    -1,    -1,    -1,    -1,   663,   664,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   729,    -1,
     729,   678,    -1,   680,    -1,    -1,    -1,    -1,    -1,   704,
      -1,    -1,   743,    -1,   764,    -1,    -1,    -1,   245,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   704,    -1,    -1,
      -1,    -1,    -1,   764,   729,   764,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   729,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   741,    -1,   743,    -1,    -1,   764,
      -1,   298,   299,   300,    -1,    -1,   303,    -1,    -1,   306,
     307,   308,    -1,   310,   311,   312,   313,   764,   315,   316,
     317,   318,   319,   320,    -1,   322,   323,   324,    -1,   326,
      -1,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,    42,
     164,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    -1,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    90,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
      -1,    -1,    -1,    -1,    -1,   452,   109,    -1,   111,    -1,
      -1,   114,   115,    -1,   117,    -1,   119,   120,   121,    -1,
     123,   124,    -1,   126,   471,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,    -1,
      -1,   164,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   524,   525,    -1,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   549,   167,    -1,    -1,    -1,   554,   555,   556,
      -1,    -1,   559,    -1,    -1,   562,    -1,    -1,    -1,    -1,
     567,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   575,    -1,
      -1,    -1,   579,    -1,    -1,    -1,   583,    -1,    -1,    -1,
      22,    -1,    -1,   590,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   606,
      42,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    42,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    53,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    90,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,   111,
      -1,    -1,   114,   115,    -1,   117,    -1,   119,   120,   121,
      -1,   123,   124,   690,   126,   692,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,   164,   165,    -1,    -1,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,   167,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    42,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    53,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      -1,    90,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    43,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,    53,   111,    -1,    -1,   114,   115,    -1,   117,    -1,
     119,   120,   121,    -1,   123,   124,    -1,   126,    -1,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,   160,   161,    -1,    53,   164,   165,    -1,    -1,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,   167,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    42,   167,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,    -1,   111,    -1,    -1,   114,
     115,    -1,   117,    -1,   119,   120,   121,    -1,   123,   124,
      -1,   126,    -1,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    42,    -1,   164,
     165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,    -1,   111,    -1,    -1,   114,
     115,    -1,   117,    -1,   119,   120,   121,    -1,   123,   124,
      -1,   126,    -1,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    42,    -1,   164,
     165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,    -1,   111,    -1,    -1,   114,
     115,    -1,   117,    -1,   119,   120,   121,    -1,   123,   124,
      -1,   126,    -1,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    42,    -1,   164,
     165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,    -1,   111,    -1,    -1,   114,
     115,    -1,   117,    -1,   119,   120,   121,    -1,   123,   124,
      -1,   126,    -1,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   160,   161,    -1,    -1,   164,
     165,    -1,    -1,    -1,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    90,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,   111,    -1,
      -1,   114,   115,    -1,   117,    -1,   119,   120,   121,    -1,
     123,   124,    -1,   126,    -1,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   160,   161
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  MapSetParser::yystos_[] =
  {
         0,   169,   170,     0,    18,   185,   186,   188,   159,   171,
     187,     3,     4,     5,     6,     7,     8,     9,    10,    12,
     172,   173,    19,   189,   164,   165,   358,   155,   156,   157,
     158,   398,   407,   398,   398,   398,   159,   160,   161,   408,
     409,    53,   178,   179,   184,    11,    13,    14,   174,    39,
     176,   177,    15,   204,   205,   190,   398,    89,   166,   399,
     400,   401,   398,    39,   180,   181,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   162,   163,   167,
     175,   359,   398,   402,   403,   404,   405,   406,   408,   410,
     176,   359,    23,   160,   398,   408,    54,   183,    40,    39,
     286,   191,    40,   182,   398,   356,   358,   359,   287,   192,
     159,    45,    34,    35,    36,    37,    38,    53,   288,   289,
     292,   348,   349,   351,   352,   353,   356,    25,    41,   206,
     211,   212,   398,   350,    40,    45,   290,   291,   294,    42,
     293,    26,   207,   208,   209,   210,   408,    92,   213,   214,
     218,    39,   246,    52,   295,   306,   357,   358,   408,   288,
     295,   300,   301,   348,   354,   355,   356,   295,   210,    28,
      33,   235,   241,   243,    93,   215,   221,   247,    54,   302,
     305,   355,    43,   355,    42,    67,    69,    70,    71,    72,
      73,    74,    75,    76,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    90,   101,   109,   111,   114,
     115,   117,   119,   120,   121,   123,   124,   126,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   219,   220,   278,   358,   383,   385,
     387,   388,   389,   408,   236,    42,   222,   223,   277,   278,
     382,   383,    27,   216,   224,    24,   193,   195,   248,   249,
     250,   253,   307,   348,   356,   299,   304,    63,    64,    66,
      94,    95,    96,    97,    98,    99,   100,   358,   360,   361,
     364,   367,   368,   371,   372,   378,   380,   381,   382,   383,
     390,   393,   396,   398,   402,   406,   408,    76,    42,    42,
      42,   167,   384,    42,   167,   284,    42,    42,    42,   246,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,   284,    42,    42,    42,   167,    42,   167,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
     220,    42,   167,   279,    39,   358,   360,   223,    28,    31,
      32,   217,   230,   233,   234,    20,    21,   196,   197,   194,
      40,   252,    45,   254,   255,   309,   308,    51,   298,    50,
     303,   381,   381,   381,    42,    42,    91,   198,   199,   363,
     366,    57,    58,    59,    60,    61,    62,    67,    68,   369,
     370,   377,   379,    42,   279,   397,   246,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   358,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   360,   360,
     360,    20,   281,   242,    43,    29,    30,   225,   226,   227,
     228,   229,   277,   358,   146,   146,   231,   234,   232,   233,
      22,    42,   200,   201,   202,   203,   278,   358,   383,   390,
     398,   402,   406,   211,    16,    17,    46,    47,    49,   122,
     251,   256,   257,   259,   263,   266,   267,   270,   271,   276,
     250,   301,   318,    42,    52,    66,   102,   310,   312,   319,
     320,   321,   322,   325,   328,   330,   336,   337,   358,   408,
     296,   297,   306,   305,   281,   281,   358,    43,    55,   362,
      56,   365,   371,   371,   371,   371,   371,   371,    68,   284,
      63,    64,   373,   376,   404,   405,    22,    65,   374,   281,
      43,    43,    43,   285,    50,    50,    50,    43,    43,    50,
      43,    43,    50,    43,    43,    43,    43,    50,    43,    43,
      43,    43,    43,    43,    43,    50,    43,    43,    43,    50,
      43,    43,    43,    50,    43,    43,    43,    43,    43,    43,
      50,    43,    43,    43,   360,   240,   226,   382,   360,   201,
     213,   260,   264,   258,   268,   277,    42,    45,   245,   272,
     321,    42,    52,   102,   338,   343,   344,   346,   408,   328,
     311,   324,   327,    22,    39,    63,   103,   329,   331,   335,
     302,    22,   360,   392,   360,   364,   367,   284,   378,   378,
     374,   375,   380,   380,   360,   283,   360,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   280,    40,    42,   167,
     238,   199,   235,   261,   265,   246,   269,   360,   250,   246,
      43,   341,   342,   344,    52,   345,   408,   302,   104,   323,
      65,   326,    50,   146,   334,   347,    43,   391,    43,    43,
      50,   282,    50,    43,    43,    43,    43,   282,   386,    43,
     386,    43,    43,   283,   239,    43,   357,   357,   246,    91,
     275,    43,   340,   317,   325,   330,   347,    40,    50,   333,
      51,   394,   395,   360,   360,    43,    43,    43,    44,   237,
     244,   358,   398,   402,   406,   408,   262,   246,   358,    48,
     273,   104,   339,    51,   316,    40,    40,   332,   347,    77,
      43,    43,    43,   244,   246,    43,   274,   344,   312,   313,
     315,    40,    57,   246,   314,   407,   302
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
     415,   416,   417,   418,   419,   420,   421,   422
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  MapSetParser::yyr1_[] =
  {
         0,   168,   170,   169,   171,   171,   172,   172,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   174,   174,   174,
     175,   175,   176,   177,   177,   178,   179,   179,   180,   180,
     181,   182,   183,   183,   184,   185,   186,   186,   187,   187,
     188,   190,   191,   189,   192,   192,   194,   193,   195,   196,
     196,   197,   197,   198,   199,   199,   200,   201,   201,   201,
     201,   201,   201,   201,   201,   202,   202,   203,   203,   204,
     204,   205,   206,   207,   207,   208,   209,   210,   211,   212,
     212,   213,   214,   214,   215,   215,   216,   216,   217,   217,
     218,   219,   219,   220,   220,   220,   220,   221,   222,   222,
     223,   224,   225,   225,   226,   226,   227,   227,   228,   229,
     229,   230,   230,   231,   231,   232,   232,   233,   234,   235,
     236,   236,   237,   237,   239,   238,   238,   240,   240,   242,
     241,   243,   243,   244,   244,   244,   244,   244,   244,   245,
     245,   247,   246,   248,   248,   249,   250,   250,   251,   252,
     252,   253,   254,   255,   255,   256,   256,   256,   256,   256,
     256,   256,   258,   257,   260,   261,   262,   259,   264,   265,
     263,   266,   268,   269,   267,   271,   272,   270,   274,   273,
     275,   275,   276,   277,   277,   277,   278,   279,   280,   279,
     281,   281,   282,   283,   283,   284,   285,   284,   287,   286,
     288,   288,   289,   290,   291,   291,   293,   292,   294,   292,
     295,   296,   297,   297,   298,   299,   299,   300,   301,   301,
     302,   303,   304,   304,   305,   306,   306,   308,   307,   309,
     307,   311,   310,   312,   312,   314,   313,   315,   315,   316,
     317,   317,   318,   319,   320,   321,   322,   323,   324,   324,
     325,   326,   327,   327,   328,   329,   329,   330,   330,   331,
     332,   332,   333,   333,   334,   334,   335,   335,   335,   335,
     336,   337,   337,   337,   337,   338,   339,   340,   340,   341,
     342,   342,   343,   343,   344,   345,   345,   346,   346,   346,
     347,   348,   348,   350,   349,   351,   352,   352,   352,   352,
     352,   353,   353,   354,   354,   355,   355,   356,   356,   357,
     357,   358,   358,   359,   359,   359,   359,   359,   359,   360,
     361,   362,   363,   363,   364,   365,   366,   366,   367,   368,
     369,   369,   370,   370,   370,   370,   370,   370,   370,   370,
     371,   372,   373,   373,   374,   374,   375,   375,   376,   376,
     376,   377,   377,   378,   379,   379,   380,   380,   380,   380,
     381,   381,   381,   381,   381,   381,   381,   381,   382,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   384,   384,
     385,   386,   386,   387,   388,   389,   390,   390,   391,   390,
     392,   392,   393,   393,   393,   393,   393,   394,   395,   395,
     396,   397,   397,   398,   399,   400,   400,   401,   401,   402,
     402,   402,   403,   403,   403,   404,   404,   404,   405,   405,
     405,   406,   406,   407,   407,   407,   407,   408,   408,   409,
     409,   410,   410
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
       1,     1,     0,     3,     0,     0,     0,     6,     0,     0,
       5,     6,     0,     0,     4,     0,     0,     4,     0,     3,
       0,     2,     2,     1,     1,     1,     2,     1,     0,     6,
       0,     1,     2,     0,     2,     1,     0,     5,     0,     4,
       0,     1,     2,     2,     0,     1,     0,     3,     0,     3,
       3,     2,     0,     1,     2,     0,     2,     1,     0,     1,
       2,     2,     0,     2,     1,     1,     1,     0,     3,     0,
       3,     0,     4,     1,     1,     0,     3,     0,     1,     2,
       0,     2,     1,     1,     1,     1,     2,     2,     0,     2,
       2,     2,     0,     2,     2,     0,     1,     1,     2,     1,
       1,     2,     2,     1,     2,     3,     1,     1,     1,     2,
       1,     1,     1,     2,     3,     1,     2,     0,     2,     2,
       0,     1,     1,     3,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     0,     4,     4,     1,     1,     1,     1,
       1,     0,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     0,     2,     2,     2,     0,     2,     1,     2,
       0,     1,     2,     2,     2,     2,     2,     2,     2,     3,
       1,     2,     1,     1,     2,     2,     0,     1,     2,     2,
       2,     0,     2,     2,     0,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     4,
       4,     6,     4,     4,     4,     4,     2,     2,     4,     4,
       4,     4,     2,     1,     4,     4,     4,     4,     6,     6,
       6,     4,     4,     4,     4,     4,     4,     4,     2,     4,
       4,     4,     4,     4,     4,     2,     8,     6,     6,     6,
       4,     4,     4,     4,     4,     1,     1,     1,     3,     1,
       7,     0,     1,     7,     2,     3,     5,     5,     0,     7,
       1,     1,     1,     1,     1,     1,     1,     4,     0,     1,
       2,     0,     1,     2,     2,     1,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
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
       169,     0,    -1,    -1,   170,   185,   171,   172,    -1,    -1,
     171,   173,    -1,    -1,   172,   205,    -1,     3,   358,   398,
     398,    -1,     4,   398,    -1,     5,   398,    -1,     6,   398,
      -1,     7,   398,    -1,     8,   408,    -1,     9,   178,    -1,
      10,   174,    -1,    12,   177,    -1,    11,    -1,    14,    -1,
      13,    -1,    -1,   359,    -1,    39,   175,    40,   356,    -1,
     176,    -1,   177,   176,    -1,   179,   180,    -1,    -1,   184,
      -1,    -1,   181,    -1,    39,   183,    40,    -1,   398,    45,
     398,    -1,    -1,   183,   182,    -1,    53,   398,    54,    -1,
     186,   187,    -1,    -1,   188,    -1,    -1,   187,   189,    -1,
      18,   159,    -1,    -1,    -1,    19,   190,   160,   191,   159,
      -1,    -1,   192,   206,    -1,    -1,   195,   194,   211,   213,
     235,    -1,    24,   197,   203,    -1,    20,    -1,    21,    -1,
      -1,   196,    -1,    91,   358,    -1,    -1,   198,    -1,    42,
     360,   199,    43,    -1,   358,    -1,   390,    -1,   383,    -1,
     278,    -1,   398,    -1,   402,    -1,   406,    -1,   200,    -1,
     201,    -1,   202,   201,    -1,   202,    -1,    22,    -1,    -1,
      15,   359,    -1,   204,    23,   286,   192,   211,   213,   235,
      -1,    25,   207,    -1,   208,    -1,   209,    -1,   210,    -1,
      26,   210,    -1,   408,    -1,   212,   246,    -1,    -1,    41,
      -1,   214,   215,   216,   217,    -1,    -1,   218,    -1,    -1,
     221,    -1,    -1,   224,    -1,    -1,   230,    -1,    92,    28,
     219,    -1,   220,    -1,   219,   220,    -1,   383,    -1,   278,
      -1,    42,   360,   199,    43,    -1,   358,    -1,    93,   222,
      -1,   223,    -1,   222,   223,    -1,   277,    -1,    27,    28,
     225,    -1,   226,    -1,   225,   226,    -1,   228,    -1,   229,
      -1,    29,    -1,    30,    -1,   227,   382,    -1,   277,    -1,
     358,    -1,   233,   231,    -1,   234,   232,    -1,    -1,   234,
      -1,    -1,   233,    -1,    31,   146,    -1,    32,   146,    -1,
     243,    -1,    -1,   236,   358,    -1,   244,    -1,   237,   244,
      -1,    -1,    42,   239,   237,    43,    -1,   167,    -1,    -1,
     240,   238,    -1,    -1,    33,   236,    39,   242,   240,    40,
      -1,    -1,   241,    -1,   408,    -1,   398,    -1,   402,    -1,
     406,    -1,    44,    -1,   358,    -1,    -1,    45,    -1,    -1,
      39,   247,   248,    40,    -1,   193,    -1,   249,    -1,   250,
     252,    -1,    -1,   253,    -1,   256,   245,   250,    -1,    -1,
     252,   251,    -1,   307,   255,    -1,    45,   250,    -1,    -1,
     254,    -1,   270,    -1,   257,    -1,   267,    -1,   259,    -1,
     263,    -1,   276,    -1,   266,    -1,    -1,    46,   258,   246,
      -1,    -1,    -1,    -1,    16,   260,   261,   357,   262,   246,
      -1,    -1,    -1,    17,   264,   265,   357,   246,    -1,   122,
      42,   360,    91,   358,    43,    -1,    -1,    -1,    47,   268,
     269,   246,    -1,    -1,    -1,   271,   272,   246,   275,    -1,
      -1,    48,   274,   246,    -1,    -1,   275,   273,    -1,    49,
     277,    -1,   382,    -1,   383,    -1,   278,    -1,   408,   279,
      -1,   167,    -1,    -1,    42,   281,   360,   280,   283,    43,
      -1,    -1,    20,    -1,    50,   360,    -1,    -1,   283,   282,
      -1,   167,    -1,    -1,    42,   360,   285,   283,    43,    -1,
      -1,    39,   287,   288,    40,    -1,    -1,   289,    -1,   292,
     291,    -1,    45,   288,    -1,    -1,   290,    -1,    -1,   356,
     293,   295,    -1,    -1,   348,   294,   300,    -1,   306,   302,
     299,    -1,   306,   302,    -1,    -1,   296,    -1,    51,   297,
      -1,    -1,   299,   298,    -1,   301,    -1,    -1,   295,    -1,
     305,   304,    -1,    50,   305,    -1,    -1,   304,   303,    -1,
     355,    -1,   357,    -1,    52,    -1,    -1,   356,   308,   310,
      -1,    -1,   348,   309,   318,    -1,    -1,   312,   311,   302,
     317,    -1,   319,    -1,   320,    -1,    -1,   312,   314,   302,
      -1,    -1,   313,    -1,    51,   315,    -1,    -1,   317,   316,
      -1,   301,    -1,   321,    -1,   358,    -1,   322,    -1,   325,
     324,    -1,   104,   325,    -1,    -1,   324,   323,    -1,   330,
     327,    -1,    65,   330,    -1,    -1,   327,   326,    -1,   336,
     329,    -1,    -1,   331,    -1,   328,    -1,   102,   328,    -1,
     335,    -1,    40,    -1,   347,    40,    -1,    50,   332,    -1,
      40,    -1,   347,   333,    -1,    50,   347,    40,    -1,    22,
      -1,   103,    -1,    63,    -1,    39,   334,    -1,   337,    -1,
     408,    -1,    52,    -1,    66,   338,    -1,    42,   321,    43,
      -1,   343,    -1,   104,   344,    -1,    -1,   340,   339,    -1,
     344,   340,    -1,    -1,   341,    -1,   344,    -1,    42,   342,
      43,    -1,   346,    -1,   408,    -1,    52,    -1,   408,    -1,
      52,    -1,   102,   345,    -1,   146,    -1,   351,    -1,   349,
      -1,    -1,    53,   350,   295,    54,    -1,   353,    42,   354,
      43,    -1,    34,    -1,    35,    -1,    36,    -1,    37,    -1,
      38,    -1,    -1,   352,    -1,   355,    -1,   354,   355,    -1,
     356,    -1,   348,    -1,   358,    -1,   359,    -1,   358,    -1,
     408,    -1,   164,    -1,   165,    -1,   408,    -1,   398,    -1,
     402,    -1,   406,    -1,   410,    -1,   167,    -1,   361,    -1,
     364,   363,    -1,    55,   364,    -1,    -1,   363,   362,    -1,
     367,   366,    -1,    56,   367,    -1,    -1,   366,   365,    -1,
     368,    -1,   371,   369,    -1,    -1,   370,    -1,    57,   371,
      -1,    58,   371,    -1,    59,   371,    -1,    60,   371,    -1,
      61,   371,    -1,    62,   371,    -1,    68,   284,    -1,    67,
      68,   284,    -1,   372,    -1,   378,   377,    -1,   404,    -1,
     405,    -1,    22,   380,    -1,    65,   380,    -1,    -1,   374,
      -1,    63,   378,    -1,    64,   378,    -1,   373,   375,    -1,
      -1,   377,   376,    -1,   380,   379,    -1,    -1,   379,   374,
      -1,    66,   381,    -1,    63,   381,    -1,    64,   381,    -1,
     381,    -1,   382,    -1,   383,    -1,   396,    -1,   398,    -1,
     402,    -1,   406,    -1,   358,    -1,   390,    -1,    42,   360,
      43,    -1,    78,    42,   360,    43,    -1,    79,    42,   360,
      43,    -1,    80,    42,   360,    50,   360,    43,    -1,    81,
      42,   360,    43,    -1,    82,    42,   358,    43,    -1,    69,
      42,   360,    43,    -1,    70,    42,   360,    43,    -1,    71,
     384,    -1,   114,   167,    -1,   137,    42,   360,    43,    -1,
     134,    42,   360,    43,    -1,   126,    42,   360,    43,    -1,
     120,    42,   360,    43,    -1,    90,   284,    -1,   387,    -1,
     141,    42,   360,    43,    -1,   138,    42,   360,    43,    -1,
     136,    42,   360,    43,    -1,   132,    42,   360,    43,    -1,
     123,    42,   360,    50,   360,    43,    -1,   133,    42,   360,
      50,   360,    43,    -1,   140,    42,   360,    50,   360,    43,
      -1,   111,    42,   360,    43,    -1,   143,    42,   360,    43,
      -1,   135,    42,   360,    43,    -1,   131,    42,   360,    43,
      -1,   128,    42,   360,    43,    -1,   124,    42,   360,    43,
      -1,   119,    42,   360,    43,    -1,   117,   167,    -1,   109,
      42,   360,    43,    -1,   142,    42,   360,    43,    -1,   139,
      42,   360,    43,    -1,   130,    42,   360,    43,    -1,   121,
      42,   360,    43,    -1,   115,    42,   360,    43,    -1,    72,
     284,    -1,    73,    42,   360,    50,   360,    50,   360,    43,
      -1,    74,    42,   360,    50,   360,    43,    -1,    75,    42,
     360,    50,   360,    43,    -1,    83,    42,   360,    50,   360,
      43,    -1,    84,    42,   360,    43,    -1,    85,    42,   360,
      43,    -1,    86,    42,   360,    43,    -1,    87,    42,   360,
      43,    -1,   101,    42,   360,    43,    -1,   385,    -1,   388,
      -1,   389,    -1,    42,   360,    43,    -1,   167,    -1,    88,
      42,   360,    50,   360,   386,    43,    -1,    -1,   282,    -1,
     129,    42,   360,    50,   360,   386,    43,    -1,    76,   246,
      -1,    67,    76,   246,    -1,    94,    42,   281,   392,    43,
      -1,   393,    42,   281,   360,    43,    -1,    -1,    99,    42,
     281,   360,   391,   395,    43,    -1,    22,    -1,   360,    -1,
      95,    -1,    96,    -1,    97,    -1,    98,    -1,   100,    -1,
      51,    77,    57,   407,    -1,    -1,   394,    -1,   408,   397,
      -1,    -1,   279,    -1,   407,   401,    -1,    89,   408,    -1,
     166,    -1,   399,    -1,    -1,   400,    -1,   403,    -1,   404,
      -1,   405,    -1,   146,    -1,   147,    -1,   148,    -1,   149,
      -1,   150,    -1,   151,    -1,   152,    -1,   153,    -1,   154,
      -1,   144,    -1,   145,    -1,   155,    -1,   157,    -1,   156,
      -1,   158,    -1,   159,    -1,   409,    -1,   161,    -1,   160,
      -1,   162,    -1,   163,    -1
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
     382,   384,   386,   387,   391,   392,   393,   394,   401,   402,
     403,   409,   416,   417,   418,   423,   424,   425,   430,   431,
     435,   436,   439,   442,   444,   446,   448,   451,   453,   454,
     461,   462,   464,   467,   468,   471,   473,   474,   480,   481,
     486,   487,   489,   492,   495,   496,   498,   499,   503,   504,
     508,   512,   515,   516,   518,   521,   522,   525,   527,   528,
     530,   533,   536,   537,   540,   542,   544,   546,   547,   551,
     552,   556,   557,   562,   564,   566,   567,   571,   572,   574,
     577,   578,   581,   583,   585,   587,   589,   592,   595,   596,
     599,   602,   605,   606,   609,   612,   613,   615,   617,   620,
     622,   624,   627,   630,   632,   635,   639,   641,   643,   645,
     648,   650,   652,   654,   657,   661,   663,   666,   667,   670,
     673,   674,   676,   678,   682,   684,   686,   688,   690,   692,
     695,   697,   699,   701,   702,   707,   712,   714,   716,   718,
     720,   722,   723,   725,   727,   730,   732,   734,   736,   738,
     740,   742,   744,   746,   748,   750,   752,   754,   756,   758,
     760,   763,   766,   767,   770,   773,   776,   777,   780,   782,
     785,   786,   788,   791,   794,   797,   800,   803,   806,   809,
     813,   815,   818,   820,   822,   825,   828,   829,   831,   834,
     837,   840,   841,   844,   847,   848,   851,   854,   857,   860,
     862,   864,   866,   868,   870,   872,   874,   876,   878,   882,
     887,   892,   899,   904,   909,   914,   919,   922,   925,   930,
     935,   940,   945,   948,   950,   955,   960,   965,   970,   977,
     984,   991,   996,  1001,  1006,  1011,  1016,  1021,  1026,  1029,
    1034,  1039,  1044,  1049,  1054,  1059,  1062,  1071,  1078,  1085,
    1092,  1097,  1102,  1107,  1112,  1117,  1119,  1121,  1123,  1127,
    1129,  1137,  1138,  1140,  1148,  1151,  1155,  1161,  1167,  1168,
    1176,  1178,  1180,  1182,  1184,  1186,  1188,  1190,  1195,  1196,
    1198,  1201,  1202,  1204,  1207,  1210,  1212,  1214,  1215,  1217,
    1219,  1221,  1223,  1225,  1227,  1229,  1231,  1233,  1235,  1237,
    1239,  1241,  1243,  1245,  1247,  1249,  1251,  1253,  1255,  1257,
    1259,  1261,  1263
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  MapSetParser::yyrline_[] =
  {
         0,   394,   394,   394,   400,   402,   406,   408,   412,   421,
     424,   427,   430,   433,   436,   438,   442,   448,   451,   454,
     460,   463,   467,   479,   480,   484,   487,   489,   492,   494,
     498,   502,   507,   509,   513,   520,   524,   526,   530,   532,
     536,   542,   544,   542,   554,   557,   565,   565,   576,   584,
     587,   594,   597,   602,   609,   612,   617,   624,   627,   630,
     633,   636,   639,   642,   646,   651,   654,   662,   665,   671,
     674,   681,   691,   698,   699,   703,   709,   715,   722,   729,
     731,   736,   743,   746,   751,   754,   759,   762,   767,   771,
     775,   782,   785,   792,   795,   798,   801,   807,   813,   816,
     823,   828,   835,   839,   847,   849,   857,   860,   868,   876,
     877,   884,   888,   896,   899,   904,   907,   911,   917,   925,
     930,   933,   940,   943,   949,   949,   955,   961,   964,   971,
     971,   980,   983,   987,   990,   993,   996,   999,  1002,  1008,
    1010,  1015,  1015,  1027,  1028,  1033,  1037,  1039,  1049,  1053,
    1056,  1072,  1077,  1081,  1084,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1098,  1098,  1113,  1116,  1118,  1113,  1129,  1132,
    1129,  1141,  1147,  1150,  1147,  1160,  1163,  1160,  1173,  1173,
    1187,  1189,  1193,  1204,  1205,  1206,  1210,  1218,  1222,  1222,
    1231,  1234,  1241,  1247,  1249,  1263,  1266,  1266,  1276,  1276,
    1284,  1286,  1291,  1296,  1300,  1302,  1306,  1306,  1309,  1309,
    1316,  1321,  1325,  1327,  1332,  1336,  1338,  1343,  1347,  1349,
    1354,  1359,  1363,  1365,  1369,  1376,  1380,  1388,  1388,  1391,
    1391,  1397,  1397,  1403,  1404,  1408,  1408,  1413,  1415,  1419,
    1422,  1424,  1428,  1432,  1436,  1442,  1446,  1450,  1453,  1455,
    1459,  1463,  1468,  1470,  1476,  1479,  1481,  1487,  1488,  1494,
    1498,  1499,  1503,  1504,  1508,  1509,  1513,  1514,  1515,  1516,
    1520,  1524,  1527,  1530,  1533,  1539,  1543,  1546,  1548,  1552,
    1555,  1557,  1561,  1562,  1566,  1570,  1571,  1575,  1576,  1577,
    1581,  1586,  1587,  1591,  1591,  1604,  1629,  1632,  1635,  1638,
    1641,  1648,  1651,  1656,  1660,  1667,  1668,  1672,  1675,  1679,
    1682,  1688,  1689,  1693,  1696,  1699,  1702,  1705,  1706,  1712,
    1717,  1726,  1733,  1736,  1744,  1753,  1760,  1763,  1770,  1775,
    1786,  1789,  1793,  1796,  1799,  1802,  1805,  1808,  1811,  1814,
    1820,  1825,  1834,  1837,  1844,  1847,  1854,  1857,  1862,  1865,
    1869,  1883,  1886,  1894,  1903,  1906,  1913,  1916,  1919,  1922,
    1926,  1927,  1928,  1929,  1932,  1935,  1938,  1941,  1945,  1951,
    1954,  1957,  1960,  1963,  1966,  1969,  1973,  1976,  1979,  1982,
    1985,  1988,  1991,  1994,  1995,  1998,  2001,  2004,  2007,  2010,
    2013,  2016,  2019,  2022,  2025,  2028,  2031,  2034,  2037,  2040,
    2043,  2046,  2049,  2052,  2055,  2058,  2062,  2065,  2068,  2071,
    2074,  2077,  2080,  2083,  2086,  2089,  2090,  2091,  2097,  2100,
    2107,  2114,  2117,  2121,  2127,  2134,  2141,  2144,  2148,  2148,
    2160,  2164,  2168,  2171,  2174,  2177,  2180,  2186,  2192,  2195,
    2199,  2209,  2212,  2217,  2225,  2232,  2236,  2244,  2248,  2252,
    2253,  2254,  2258,  2259,  2260,  2264,  2265,  2266,  2270,  2271,
    2272,  2276,  2277,  2281,  2282,  2283,  2284,  2288,  2289,  2293,
    2294,  2298,  2299
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
     165,   166,   167
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
  const int MapSetParser::yyntokens_ = 168;

  const unsigned int MapSetParser::yyuser_token_number_max_ = 422;
  const MapSetParser::token_number_type MapSetParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 4686 "lib/MapSetParser/MapSetParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 2305 "lib/MapSetParser/MapSetParser.ypp"
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


