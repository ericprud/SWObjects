
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
#line 43 "C:\\Users\\Jelle\\Documents\\GitHub\\SWObjects\\lib\\MapSetParser.cpp"


#include "MapSetParser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 305 "..\\..\\lib\\MapSetParser.ypp"

#include "MapSetScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 445 "..\\..\\lib\\MapSetParser.ypp"

#include "MapSetScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lexWrapper


/* Line 317 of lalr1.cc  */
#line 68 "C:\\Users\\Jelle\\Documents\\GitHub\\SWObjects\\lib\\MapSetParser.cpp"

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
#line 137 "C:\\Users\\Jelle\\Documents\\GitHub\\SWObjects\\lib\\MapSetParser.cpp"
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
#line 45 "..\\..\\lib\\MapSetParser.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
    driver.yylloc = &yylloc;
}

/* Line 553 of lalr1.cc  */
#line 322 "C:\\Users\\Jelle\\Documents\\GitHub\\SWObjects\\lib\\MapSetParser.cpp"

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
#line 460 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.root = new MapSet();
	driver.root->sharedVars = MapSet::e_PROMISCUOUS;
      }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 478 "..\\..\\lib\\MapSetParser.ypp"
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
#line 487 "..\\..\\lib\\MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->driver = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 490 "..\\..\\lib\\MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->server = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 493 "..\\..\\lib\\MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->user = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 496 "..\\..\\lib\\MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->password = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 499 "..\\..\\lib\\MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->database = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 502 "..\\..\\lib\\MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->stemURI = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 507 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.sharedVarsSet = true;
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 511 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.lastRuleTermSet = false;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 517 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_PROMISCUOUS;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 520 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_VARNAMES;
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 523 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_DRACONIAN;
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 529 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_TTerm) = NULL;
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 536 "..\\..\\lib\\MapSetParser.ypp"
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
#line 571 "..\\..\\lib\\MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->keyMap[(yysemantic_stack_[(3) - (1)].p_RDFLiteral)->getLexicalValue()] = (yysemantic_stack_[(3) - (3)].p_RDFLiteral)->getLexicalValue();
    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 582 "..\\..\\lib\\MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->primaryKey = (yysemantic_stack_[(3) - (2)].p_RDFLiteral);
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 605 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 611 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 613 "..\\..\\lib\\MapSetParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 615 "..\\..\\lib\\MapSetParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 623 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 626 "..\\..\\lib\\MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 629 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 633 "..\\..\\lib\\MapSetParser.ypp"
    {
	  if ((yysemantic_stack_[(7) - (7)].p_ValuesClause) != NULL)
	      (yysemantic_stack_[(7) - (5)].p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yysemantic_stack_[(7) - (7)].p_ValuesClause), (yysemantic_stack_[(7) - (5)].p_WhereClause)->m_GroupGraphPattern);
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (4)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(7) - (3)].p_Project).distinctness, (yysemantic_stack_[(7) - (3)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(7) - (5)].p_WhereClause), (yysemantic_stack_[(7) - (6)].p_SolutionModifier))));
	  driver.curGraphName = (yysemantic_stack_[(7) - (2)].p_TTerm);
	  driver.countStar = (yysemantic_stack_[(7) - (1)].p_parentCountStar);
      }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 644 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 652 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 655 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 662 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 670 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 677 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 685 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 692 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 695 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 698 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 701 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 704 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 707 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 710 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 719 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 722 "..\\..\\lib\\MapSetParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 730 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 733 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 740 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.curOp = NULL;
      }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 742 "..\\..\\lib\\MapSetParser.ypp"
    {
	/* $3 is NO LONGER known to be a DefaultGraphPattern because of grammar restrictions. */
	if ((yysemantic_stack_[(8) - (8)].p_ValuesClause) != NULL)
	    (yysemantic_stack_[(8) - (6)].p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yysemantic_stack_[(8) - (8)].p_ValuesClause), (yysemantic_stack_[(8) - (6)].p_WhereClause)->m_GroupGraphPattern);
	Construct* constr = new Construct((yysemantic_stack_[(8) - (3)].p_TableOperation), (yysemantic_stack_[(8) - (5)].p_DatasetClauses), (yysemantic_stack_[(8) - (6)].p_WhereClause), (yysemantic_stack_[(8) - (7)].p_SolutionModifier));
	driver.root->maps.push_back(LabeledConstruct((yysemantic_stack_[(8) - (1)].p_TTerm), constr));
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 752 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (2)].p_TTerm);
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 758 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_TTerm) = NULL;
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 766 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 769 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 777 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 789 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 795 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 801 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 808 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.ensureGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 822 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 829 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 837 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 845 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 853 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 861 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 868 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 871 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 878 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 881 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 884 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 887 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 893 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 899 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 902 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 914 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 921 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 925 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 935 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 943 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 946 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 954 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 963 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 970 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 974 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 982 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 990 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 997 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1003 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1013 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ValuesClause) = (yysemantic_stack_[(2) - (2)].p_ValuesClause);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1019 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ValuesClause) = NULL;
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1026 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1029 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1035 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1041 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1043 "..\\..\\lib\\MapSetParser.ypp"
    {
	  (yyval.p_TableOperation) = driver.ensureGraphPattern();
	  driver.curOp = NULL;
      }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1071 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1076 "..\\..\\lib\\MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1079 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1082 "..\\..\\lib\\MapSetParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1104 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1106 "..\\..\\lib\\MapSetParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1183 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_ValuesClause)) : (yysemantic_stack_[(1) - (1)].p_ValuesClause);
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1189 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 1193 "..\\..\\lib\\MapSetParser.ypp"
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

  case 172:

/* Line 678 of lalr1.cc  */
#line 1205 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 1209 "..\\..\\lib\\MapSetParser.ypp"
    {
	  (yyval.p_FilterExpressions) = driver.saveFilter();
      }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1211 "..\\..\\lib\\MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 1214 "..\\..\\lib\\MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_FilterExpressions));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 1222 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 1226 "..\\..\\lib\\MapSetParser.ypp"
    {
	  (yyval.p_FilterExpressions) = driver.saveFilter();
      }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 1228 "..\\..\\lib\\MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 1231 "..\\..\\lib\\MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(7) - (3)].p_FilterExpressions));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(7) - (6)].p_TTerm), driver.curOp, (yysemantic_stack_[(7) - (5)].p_Silence), driver.atomFactory, false));
	  driver.curGraphName = (yysemantic_stack_[(7) - (4)].p_TTerm);
      }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 1239 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.curOp = new Bind(driver.ensureGraphPattern(), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
	// no more triples go into the current BGP, per
	//   http://www.w3.org/TR/sparql11-query/#sparqlTranslateGraphPatterns
	// test reference:
	//   http://www.sparql.org/query-validator?query=ASK+{+%3Fs+%3Fp+%3Fo+FILTER+%281%29+BIND+%282+AS+%3Fb%29+%3Fs2+%3Fp2+%3Fo2+FILTER+%283%29+BIND+%284+AS+%3Fd%29}&languageSyntax=SPARQL&outputFormat=algebra&linenumbers=false
	driver.curBGP = NULL;
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 1250 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ValuesClause) = (yysemantic_stack_[(2) - (2)].p_ValuesClause);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 1261 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 1263 "..\\..\\lib\\MapSetParser.ypp"
    {
	  driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
      }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 1265 "..\\..\\lib\\MapSetParser.ypp"
    {
	  (yyval.p_ValuesClause) = new ValuesClause(driver.endBindingSet());
      }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 1276 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.startBindingRow();
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
	driver.endBindingRow();
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 1284 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.startBindingSet();
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 1286 "..\\..\\lib\\MapSetParser.ypp"
    {
	  (yyval.p_ValuesClause) = new ValuesClause(driver.endBindingSet());
      }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 1293 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1305 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1311 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 1313 "..\\..\\lib\\MapSetParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 1316 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 1328 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 1331 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 1334 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 1337 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 1340 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 1343 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 1346 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 1352 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 1356 "..\\..\\lib\\MapSetParser.ypp"
    {
	  (yyval.p_FilterExpressions) = driver.saveFilter();
      }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 1358 "..\\..\\lib\\MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_FilterExpressions));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 1366 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 1370 "..\\..\\lib\\MapSetParser.ypp"
    {
	  (yyval.p_FilterExpressions) = driver.saveFilter();
      }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 1372 "..\\..\\lib\\MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_FilterExpressions));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 1380 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 1385 "..\\..\\lib\\MapSetParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.ensureGraphPattern());
      }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 1398 "..\\..\\lib\\MapSetParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    driver.ensureGraphPattern();
	    driver.curFilter = new FilterExpressions();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 1414 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 1422 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 1426 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 1429 "..\\..\\lib\\MapSetParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yysemantic_stack_[(6) - (4)].p_Expressions);
      }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 1436 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 1439 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 1446 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 1454 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 1468 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 1471 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 1474 "..\\..\\lib\\MapSetParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(5) - (3)].p_Expressions);
      }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 1481 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 1484 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 1528 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 1532 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 1555 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)), true);
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 1563 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 1566 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 1572 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 1583 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 1611 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 1638 "..\\..\\lib\\MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 1645 "..\\..\\lib\\MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 1656 "..\\..\\lib\\MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 1663 "..\\..\\lib\\MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 1699 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 1702 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 1705 "..\\..\\lib\\MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 1708 "..\\..\\lib\\MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 1766 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 1770 "..\\..\\lib\\MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 1779 "..\\..\\lib\\MapSetParser.ypp"
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
		driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(tail, first, members->at(i)), true);
		const TTerm* nextTail = i == members->size()-1 ? nil : driver.createBNode();
		driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(tail, rest, nextTail), true);
		tail = nextTail;
	    }
	    members->clear();
	    delete members;
	} else if ((yysemantic_stack_[(4) - (1)].p_listModifier) == LIST_members) {
	    (yyval.p_TTerm) = new Members((yysemantic_stack_[(4) - (3)].p_TTerms));
	} else {
	    error((yyloc), "unsupported function");
	}
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 1806 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 1809 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 1812 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 1815 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 1818 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 1825 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 1833 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 1837 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 1849 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 1856 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 1859 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 1870 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 1873 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 1876 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 1879 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 1883 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 1894 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 1903 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 1910 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 1913 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 1921 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 1930 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 1937 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 1940 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 1952 "..\\..\\lib\\MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ComparatorSense).comp) {
	    (yysemantic_stack_[(2) - (2)].p_ComparatorSense).comp->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_ComparatorSense).comp); // !!!
	    if ((yysemantic_stack_[(2) - (2)].p_ComparatorSense).neg)
		(yyval.p_Expression) = new BooleanNegation((yyval.p_Expression));
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 1965 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = NULL;
    }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 1973 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 1977 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 1981 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 1985 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 1989 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 1993 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 1997 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 2001 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = true;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 2013 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 2022 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 2025 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 2032 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 2035 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 2042 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 2050 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 2053 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 2057 "..\\..\\lib\\MapSetParser.ypp"
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

  case 381:

/* Line 678 of lalr1.cc  */
#line 2071 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 2074 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 2082 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 2091 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 2094 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 2101 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 2104 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 2107 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 2117 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 2120 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 2123 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 2126 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 2133 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 2139 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 2142 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 2145 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 2148 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 2151 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 2154 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 2157 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 2161 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 2164 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 2167 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 2170 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ceil, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 2173 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 2176 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 2179 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 2183 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 2186 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 2189 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 2192 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 2195 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 2198 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 2201 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 2204 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 2207 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 2210 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 2213 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 2216 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 2219 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 2222 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 2225 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 2228 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 2231 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 2234 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 2237 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_uuid, NULL, NULL, NULL));
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 2240 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_struuid, NULL, NULL, NULL));
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 2243 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 2246 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 2249 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 2252 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 2255 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 2258 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 2261 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 2264 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 2267 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 2270 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 2273 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 2276 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 2279 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 2282 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 2285 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 2296 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 2299 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 2306 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 2313 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 2320 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 2326 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
      }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 2329 "..\\..\\lib\\MapSetParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 2333 "..\\..\\lib\\MapSetParser.ypp"
    {
	  (yyval.p_Expression) = new ExistsExpression(driver.ensureGraphPattern());
	  driver.curOp = (yysemantic_stack_[(4) - (3)].p_TableOperation);
	  driver.countStar = (yysemantic_stack_[(4) - (2)].p_parentCountStar);
      }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 2341 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
      }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 2344 "..\\..\\lib\\MapSetParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 2348 "..\\..\\lib\\MapSetParser.ypp"
    {
	  // $$ = new ExistsExpression(false, driver.ensureGraphPattern());
	  (yyval.p_Expression) = new BooleanNegation(new ExistsExpression(driver.ensureGraphPattern()));
	  driver.curOp = (yysemantic_stack_[(5) - (4)].p_TableOperation);
	  driver.countStar = (yysemantic_stack_[(5) - (3)].p_parentCountStar);
      }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 2357 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 2361 "..\\..\\lib\\MapSetParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 2366 "..\\..\\lib\\MapSetParser.ypp"
    {
	  AggregateCall::ScalarVals svals;
	  if ((yysemantic_stack_[(6) - (5)].p_RDFLiteral) != NULL)
	      svals["separator"] = (yysemantic_stack_[(6) - (5)].p_RDFLiteral)->getLexicalValue();
	  (yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression), svals));
    }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 2375 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 2382 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 2385 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 2388 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 2391 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 2394 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 2400 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 2406 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 2413 "..\\..\\lib\\MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 2423 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 2431 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 2439 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 2446 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 2450 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 2458 "..\\..\\lib\\MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 3339 "C:\\Users\\Jelle\\Documents\\GitHub\\SWObjects\\lib\\MapSetParser.cpp"
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
  const short int MapSetParser::yypact_ninf_ = -684;
  const short int
  MapSetParser::yypact_[] =
  {
      -684,    56,    48,  -684,   -92,  -684,  -684,  -684,  -684,   408,
      59,   -59,   120,   120,   120,   120,   120,    50,    29,    95,
      47,    38,  -684,  -684,  -684,  -684,  -684,   120,  -684,  -684,
    -684,  -684,  -684,   -57,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,   120,  -684,    76,  -684,  -684,  -684,  -684,
    -684,   746,  -684,    47,   746,  -684,  -684,    75,   -41,   120,
      50,  -684,  -684,  -684,  -684,    78,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,    99,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,    96,  -684,  -684,  -684,  -684,
      62,  1252,  -684,  -684,   -19,  -684,  -684,    97,  -684,  -684,
    -684,   114,  1189,  -684,  -684,   120,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,   127,  -684,  -684,  -684,  -684,
     141,  -684,    17,  -684,    63,   170,  1189,  -684,  -684,    63,
    1282,    63,    -7,  -684,  -684,    94,   150,  -684,   153,  1282,
    -684,  -684,  -684,  -684,   159,   195,  -684,  -684,  -684,  -684,
    -684,  1228,  -684,  -684,  -684,    50,  -684,  -684,  -684,  -684,
    -684,   191,   197,   137,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  1189,   144,  -684,  -684,  -684,  1786,   -21,  -684,
    -684,  -684,  1893,   211,  -684,  1021,   188,   192,  -684,  -684,
    1411,   165,   203,   210,   -16,    -6,   213,   216,   217,  -684,
     219,   220,   224,   228,   230,   231,   232,   234,   236,   242,
     248,    -6,   252,   124,   125,   258,   259,   260,   261,   133,
     265,   139,   273,   275,   276,   277,   278,   282,   283,   284,
     286,   287,   288,   289,   291,   292,   293,   294,   296,   297,
     310,   311,   325,   326,  1786,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,    -5,  -684,  -684,   -59,  -684,     3,  1411,
    1893,  -684,  -684,  -684,  -684,  -684,   341,    88,  -684,  -684,
    -684,   332,  -684,  -684,  -684,   328,  -684,  -684,    63,  -684,
    1282,  -684,   336,  1536,  1536,  1536,   334,  -684,  -684,  -684,
    -684,   337,  -684,  -684,   290,  -684,  -684,  -684,  -684,   302,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,   339,  -684,  -684,
    -684,  -684,    -5,  -684,  1411,  1411,  1411,  -684,  -684,  1411,
    -684,  -684,  1411,  1411,  1411,  -684,  1411,  1411,  1411,  1411,
     -59,  1411,  1411,  1411,  1411,  1411,  1411,  -684,  1411,  -684,
    -684,  1411,  1411,  1411,  1411,  -684,  1411,  -684,  1411,  1411,
    1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,
    1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,
    -684,   358,  -684,  -684,  -684,  -684,  -684,   344,   342,  -684,
    1165,   233,   241,  -684,  -684,   361,   364,   373,  -684,   221,
    1189,  -684,  -684,    63,   123,  -684,  -684,  1282,  -684,  -684,
    -684,  -684,  -684,   358,   358,   -59,  -684,   355,   343,   346,
    1411,  1411,  1411,  1411,  1411,  1411,   331,    -6,  -684,  -684,
     200,     1,   358,  -684,  -684,  -684,   362,   363,   365,  -684,
     350,   353,   369,   150,   378,   379,   372,   381,   383,   376,
     385,   386,   387,   388,   382,   389,   391,   384,   390,   393,
     394,   395,   396,   397,   403,   399,   404,   405,   410,   406,
     411,   415,   417,   414,   418,   423,   425,   426,   442,   436,
     445,   450,   452,  -684,  1411,   481,   -23,  -684,  -684,  -684,
    -684,  1165,  -684,   480,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,   110,  -684,  -684,  -684,   -21,  -684,
    -684,  1893,   482,  -684,   159,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,    15,  -684,    34,
      -3,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,
     182,  -684,  -684,  -684,  -684,  1189,   852,  1411,  -684,  -684,
    1411,  -684,  1411,  -684,  -684,  -684,  -684,  -684,  -684,  -684,
      -6,  -684,  1411,  1411,     1,  -684,  -684,  -684,  1411,  1411,
    -684,  1411,   150,  -684,  -684,  -684,  -684,  1411,  1411,  1411,
    -684,  -684,  -684,  1411,  -684,  -684,  1411,  -684,  -684,  -684,
    -684,  1411,  -684,  -684,  1411,  1411,  -684,  -684,  -684,  -684,
    -684,  -684,  1411,  -684,  -684,  -684,  1411,  -684,  -684,  -684,
    1411,  -684,  -684,  -684,  -684,  -684,  1411,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,   -12,  -684,  -684,  -684,  -684,  -684,
     997,   484,  -684,  -684,  -684,   150,  -684,  -684,  1411,  1189,
     150,   483,   -24,  -684,    31,  -684,  -684,  -684,  -684,  -684,
    -684,  1282,   424,   457,  -684,   -34,  -684,  -684,  -684,  -684,
    -684,   488,  -684,  -684,   487,   479,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,   490,  -684,     8,   491,   492,
     501,   502,   503,   497,   504,   506,   507,   497,   508,   509,
    -684,   496,  -684,  -684,  -684,  -684,  -684,  1411,  -684,  -684,
    1661,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,    94,
     144,  -684,  -684,   150,   447,  -684,  -684,  -684,  -684,   510,
    -684,  -684,  -684,  -684,  -684,    15,  -684,    15,  -684,   407,
    -684,  -684,     9,  -684,  -684,   476,  -684,   513,  -684,  -684,
    1411,  -684,  1411,  -684,  -684,  -684,  -684,  -684,   514,  -684,
    -684,  -684,   516,  -684,  -684,    20,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,   290,  -684,   197,
    -684,   543,  -684,   -59,   512,  -684,   459,   515,  -684,  -684,
     525,  -684,    -2,  -684,   511,  -684,  -684,   523,  -684,  -684,
    -684,   667,   527,  -684,   150,  -684,   144,   528,  -684,  -684,
     -24,  -684,   123,  -684,  -684,  -684,  -684,   532,   120,  -684,
    -684,  -684,  -684,  -684,   150,  -684,   150,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  1282,  -684
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  MapSetParser::yydefact_[] =
  {
         2,     0,    37,     1,     0,     4,    39,    38,    41,     6,
      36,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     3,     5,    42,    40,   341,   342,     0,   500,   502,
     501,   503,     9,   484,    10,    11,    12,    13,   504,   507,
     506,    14,   505,     0,    15,    29,    28,    18,    20,    19,
      16,    21,    24,    17,     0,     7,    74,     0,     0,     0,
       0,   482,   483,   485,   480,     0,    33,    26,    30,   498,
     499,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     508,   509,   348,     0,    22,   344,   345,   486,   487,   488,
     346,   343,   347,    25,    72,     0,    43,     8,   481,    35,
       0,     0,   131,    70,     0,    31,    34,     0,    23,   337,
     338,     0,   133,    75,    44,     0,   130,   326,   327,   328,
     329,   330,   323,   138,   134,   146,   238,   322,   321,   332,
       0,   236,    84,    32,     0,   132,   133,   147,   144,   248,
     331,     0,     0,    85,    76,    87,     0,   251,     0,   331,
     250,   339,   340,   139,   135,     0,   145,   249,   239,   247,
     336,   331,   333,   335,   237,     0,    77,    78,    79,    80,
      82,     0,   126,    89,    88,   148,    83,   324,   245,   254,
     256,   136,   133,     0,   325,   334,    81,     0,   184,    71,
     127,   124,     0,    91,    90,   153,   240,   252,   137,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   458,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,    96,    99,   101,    98,   449,
     413,   450,   451,     0,   125,   182,     0,   183,     0,     0,
     102,   103,   105,   223,   221,   222,     0,    93,    92,   150,
      46,     0,   151,   156,   154,   160,   259,   257,   242,   246,
     331,   255,     0,     0,     0,     0,     0,   469,   470,   471,
     472,     0,   473,   396,    55,   349,   352,   356,   358,   360,
     370,   381,   384,   389,   390,   391,   397,     0,   392,   393,
     394,   395,   478,   461,     0,     0,     0,   453,   406,     0,
     233,   439,     0,     0,     0,   459,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   412,     0,   432,
     433,     0,     0,     0,     0,   407,     0,   431,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      97,   228,   225,   224,   185,   192,   194,     0,     0,   104,
       0,     0,     0,    86,    94,   118,   120,     0,   149,   152,
     153,   161,   158,   248,     0,   243,   244,   331,   253,   142,
     387,   388,   386,   228,   228,     0,    56,     0,   350,   354,
       0,     0,     0,     0,     0,     0,     0,     0,   359,   361,
     371,   383,   228,   479,   477,   462,     0,     0,     0,   234,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   229,     0,     0,     0,   201,   398,   111,
     112,   106,   107,     0,   109,   110,   114,   115,   122,   123,
     116,   119,   117,   121,    52,    47,   172,   176,   184,   170,
     210,     0,     0,   157,   135,   163,   165,   166,   168,   169,
     164,   162,   214,   167,   159,   272,   260,     0,   302,     0,
       0,   258,   261,   263,   264,   273,   275,   278,   287,   282,
     285,   300,   274,   301,   241,   133,     0,     0,    54,   100,
       0,   353,     0,   357,   362,   363,   364,   365,   366,   367,
       0,   368,     0,     0,   376,   382,   372,   373,     0,     0,
     385,     0,     0,   404,   405,   452,   231,     0,     0,     0,
     460,   399,   400,     0,   402,   403,     0,   444,   445,   446,
     447,     0,   448,   434,     0,     0,   423,   438,   430,   429,
     411,   437,     0,   428,   410,   427,     0,   436,   426,   417,
       0,   409,   425,   416,   408,   415,     0,   414,   435,   424,
     226,   187,   195,   193,     0,   108,   113,    50,    51,    53,
       0,    84,   173,   177,   181,     0,   211,   220,     0,   153,
       0,     0,   310,   318,     0,   303,   305,   312,   314,   317,
     288,   331,   276,   280,   296,     0,   298,   297,   284,   286,
     289,     0,   467,   468,     0,   475,   351,   355,   369,   378,
     379,   377,   380,   374,   375,     0,   463,     0,     0,     0,
       0,     0,     0,   455,     0,     0,     0,   455,     0,     0,
     231,     0,   191,   198,   200,   202,    69,     0,    65,    66,
      68,    49,    64,    62,    58,    63,    59,    60,    61,    87,
       0,   178,   171,     0,     0,   155,   218,   304,   311,     0,
     307,   316,   319,   315,   270,     0,   279,     0,   283,     0,
     320,   299,     0,   143,   464,     0,   476,     0,   465,   235,
       0,   232,     0,   441,   442,   401,   443,   456,     0,   421,
     422,   418,     0,   419,   420,     0,   186,   207,   208,   188,
     189,   209,   204,   205,   206,   203,   196,    55,    67,   126,
     174,   128,   212,     0,   215,   313,   309,   262,   277,   281,
       0,   293,     0,   294,     0,   466,   230,     0,   454,   457,
     227,     0,     0,    48,     0,   129,     0,     0,   216,   219,
       0,   308,   267,   271,   295,   290,   292,     0,     0,   440,
     199,   197,    57,   175,     0,   180,     0,   306,   265,   268,
     269,   291,   474,   179,   217,   331,   266
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yypgoto_[] =
  {
      -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,   517,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -192,  -684,  -124,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,   412,   -53,  -684,  -130,
    -684,  -684,  -684,  -684,  -684,  -684,   333,  -684,  -684,   312,
    -684,  -684,    89,  -684,  -684,  -684,  -684,  -684,  -684,   189,
     193,  -183,  -684,  -684,  -684,  -684,  -684,  -684,  -125,    77,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -426,
    -684,  -684,  -684,  -380,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,    81,  -684,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -201,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,  -357,  -179,   270,
    -684,  -365,  -589,   -96,  -207,  -684,  -684,  -684,  -684,   -62,
    -684,  -684,  -684,  -684,  -684,   190,   307,  -398,  -684,  -684,
     306,  -684,  -684,  -684,  -684,  -684,  -205,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,    71,  -684,  -684,  -684,  -123,
    -684,  -684,    70,  -684,  -126,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -626,  -684,
    -684,  -683,   -99,  -684,  -684,  -684,  -684,  -684,  -684,   -97,
    -100,  -181,   -11,     4,   140,  -684,  -684,  -684,    53,  -684,
    -684,    52,  -684,  -684,  -684,   -75,  -684,  -684,    42,  -684,
    -684,  -684,  -383,  -684,  -364,   -43,  -168,  -177,  -684,  -684,
     -80,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -603,  -684,
    -684,  -684,  -684,  -684,  -684,    -9,  -684,  -684,  -684,   -25,
    -684,   178,   179,   157,  -198,    54,  -684,  -684
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yydefgoto_[] =
  {
        -1,     1,     2,     9,    21,    22,    50,    83,    52,    53,
      44,    45,    67,    68,   106,   100,    46,     5,     6,    10,
       7,    24,    58,   104,   279,   280,   397,   631,   505,   629,
     630,   416,   417,   698,   699,   700,   701,    55,   113,    56,
      57,   132,   144,   166,   167,   168,   169,   145,   146,   172,
     173,   193,   277,   393,   174,   254,   255,   194,   270,   271,
     278,   491,   492,   493,   494,   495,   394,   500,   502,   395,
     396,   189,   190,   191,   796,   103,   111,   112,   123,   182,
     153,   135,   154,   155,   292,   545,   124,   137,   138,   176,
     195,   281,   282,   283,   513,   399,   284,   401,   402,   514,
     515,   635,   516,   632,   710,   794,   517,   633,   711,   771,
     518,   519,   264,   265,   266,   485,   691,   759,   267,   268,
     486,   387,   791,   695,   766,   624,   760,   520,   636,   713,
     521,   522,   640,   799,   816,   774,   523,   272,   273,   383,
     690,   484,   741,   677,   331,   576,   125,   141,   139,   157,
     405,   406,   289,   196,   158,   159,   149,   178,   291,   197,
     179,   285,   404,   403,   531,   651,   532,   819,   825,   820,
     803,   777,   526,   533,   534,   535,   536,   726,   652,   537,
     728,   653,   538,   658,   539,   659,   806,   783,   731,   660,
     540,   541,   645,   801,   776,   718,   719,   646,   647,   722,
     648,   732,   160,   127,   134,   128,   129,   130,   161,   180,
     163,   150,   303,   110,   304,   305,   551,   418,   306,   553,
     419,   307,   308,   428,   429,   309,   310,   564,   570,   672,
     565,   430,   311,   431,   312,   313,   314,   315,   328,   259,
     748,   260,   261,   335,   443,   262,   435,   572,   316,   664,
     317,   736,   737,   318,   434,   319,    62,    63,    64,   320,
      87,    88,    89,   321,    33,   322,    42,    92
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int MapSetParser::yytable_ninf_ = -332;
  const short int
  MapSetParser::yytable_[] =
  {
        27,   108,   199,    32,    34,    35,    36,    37,   256,   544,
     258,   156,   131,   126,   347,   275,   720,   580,    59,   729,
     524,   165,   622,  -190,   274,   568,    86,   705,   326,    86,
     692,   643,   693,   496,    65,    60,   131,   126,   329,   381,
     805,   527,    85,   162,   142,    85,   780,   385,   546,   547,
      97,   781,   528,   739,    54,    84,     3,   198,    94,   527,
     143,   740,   782,   -73,   185,   790,   529,   571,     4,   569,
     528,    41,   148,   740,     8,   256,    86,   258,   642,   164,
      23,   644,   131,   126,   529,    43,   721,    86,    51,   643,
     109,   107,    85,   275,   747,   287,   286,   705,   747,   807,
      95,   109,   274,    85,   105,    91,   133,    47,    91,    48,
      49,    86,    25,    26,    98,    86,    61,    66,   147,   730,
     530,   391,   392,   151,    86,   109,    96,    85,   151,   109,
     151,    85,   627,   628,   496,    99,    86,   102,   109,   644,
      85,   101,    38,    39,    40,   115,   676,   114,    25,    26,
     109,   730,    85,  -190,   637,    91,   116,    86,   327,    38,
      39,    40,   694,    38,    39,    40,    91,   527,   330,   382,
      86,   109,   151,    85,   817,   136,   257,   386,   528,   669,
     670,    38,    39,    40,   109,   140,    85,  -140,   152,   171,
      91,   175,   529,   152,    91,   152,   170,    38,    39,    40,
      38,    39,    40,    91,   673,   674,   654,   181,    90,   712,
     177,    90,   183,   275,   716,    91,    38,    39,    40,   170,
     561,   187,   274,   655,    28,    29,    30,    31,   530,    38,
      39,    40,   188,   192,    25,    26,    91,   152,   506,   507,
     276,   263,   288,   257,   323,   290,   263,   324,   656,    91,
     410,   411,   412,   724,   325,   384,   508,   332,    90,   715,
     333,   334,  -213,   336,   337,    86,   562,   563,   338,    90,
     509,   510,   339,   511,   340,   341,   342,   151,   343,   109,
     344,    85,    28,    29,    30,    31,   345,   772,   657,    38,
      39,    40,   346,    90,    25,    26,   348,    90,   349,   350,
     287,   286,   351,   352,   353,   354,    90,   355,   263,   356,
      38,    39,    40,   357,   275,    25,    26,   358,    90,   359,
     360,   361,   362,   274,   263,   626,   363,   364,   365,   448,
     366,   367,   368,   369,   275,   370,   371,   372,   373,    90,
     374,   375,   152,   274,    91,   554,   555,   556,   557,   558,
     559,   512,    90,   668,   376,   377,    74,    75,    76,    77,
      78,    79,   420,   421,   422,   423,   424,   425,   813,   378,
     379,   390,   426,   427,   398,    86,   400,   409,   413,   497,
     483,   414,    86,   432,   415,   487,   498,   488,   823,   109,
     824,    85,   151,   542,   499,   392,   109,   391,    85,   504,
     549,   550,   560,   577,   548,   552,   578,   573,   574,   388,
     575,    11,    12,    13,    14,    15,    16,    17,    18,    19,
     661,    20,   579,   581,   582,   583,   584,   826,   585,   586,
     587,   588,   589,   590,   592,   591,   593,   594,   596,   597,
     598,   599,   600,   595,   263,   131,   126,    90,   601,   603,
     604,   702,   602,   704,    91,   605,   607,   152,   543,   606,
     608,    91,   609,   611,   436,   437,   438,   610,   612,   439,
     613,   614,   440,   441,   442,   623,   444,   445,   446,   447,
     497,   449,   450,   451,   452,   453,   454,   615,   455,   616,
     617,   456,   457,   458,   459,   618,   460,   619,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
      86,   702,   621,   704,   269,   727,   638,   143,   717,   770,
     733,   725,   734,   735,   109,   738,    85,   743,   756,   287,
     286,   773,   757,   758,   742,   263,   744,   745,   746,   749,
     740,   750,   751,   753,   754,   775,   784,    90,   785,   788,
     730,   789,   795,   798,    90,   263,   800,   804,   809,   802,
      93,   808,   812,   815,   821,   792,   768,   186,   709,   769,
     625,   543,   389,   649,   543,   503,   793,   380,   501,   634,
     811,   639,   433,   525,   755,   407,   408,   818,   641,    91,
     650,   779,   778,   666,   667,   707,   671,   752,   566,   567,
     822,     0,     0,     0,    86,   814,     0,     0,     0,   703,
       0,   706,     0,     0,   620,     0,    86,     0,   109,     0,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,     0,    85,     0,     0,     0,     0,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    28,    29,
      30,    31,    38,    39,    40,     0,   763,    25,    26,     0,
       0,     0,     0,     0,     0,   707,     0,     0,     0,     0,
     761,     0,   762,     0,   263,     0,   663,   665,     0,   703,
       0,   706,     0,    91,     0,     0,   649,     0,   723,   151,
       0,     0,    90,     0,     0,    91,     0,     0,     0,     0,
       0,   675,   810,   757,   758,     0,     0,   678,   679,   680,
       0,     0,     0,   681,     0,     0,   682,     0,     0,     0,
       0,   683,     0,     0,   684,   685,     0,     0,     0,     0,
       0,     0,   686,     0,     0,   765,   687,     0,     0,     0,
     688,     0,     0,     0,   263,     0,   689,     0,     0,     0,
       0,     0,   797,     0,   152,     0,   763,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   714,   543,
     761,   543,   762,     0,     0,   151,     0,   708,     0,     0,
       0,   542,     0,     0,     0,     0,    90,     0,     0,     0,
      86,     0,     0,     0,     0,     0,     0,     0,    90,     0,
       0,     0,     0,     0,   109,     0,    85,     0,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    28,
      29,    30,    31,    38,    39,    40,     0,   767,    25,    26,
       0,     0,     0,     0,     0,   765,     0,     0,   764,     0,
     152,     0,     0,     0,   649,     0,   543,   708,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   662,     0,     0,    91,
     786,     0,   787,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   269,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    28,    29,
      30,    31,    38,    39,    40,    80,    81,     0,   293,   294,
      82,   295,   201,     0,   202,   203,   204,   205,   206,   207,
     208,   209,     0,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,     0,   221,     0,     0,   764,   296,
     297,   298,   299,   300,   301,   302,   222,     0,     0,     0,
       0,     0,     0,     0,   223,   224,   225,     0,   226,   227,
     228,     0,     0,   229,   230,     0,   231,     0,   232,   233,
     234,   235,    90,   236,   237,     0,   238,     0,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    28,    29,    30,    31,    38,    39,
      40,   696,     0,    25,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   697,     0,     0,     0,     0,     0,   -45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   117,   118,   119,
     120,   121,     0,     0,     0,  -331,     0,   201,     0,   202,
     203,   204,   205,   206,   207,   208,   209,   122,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,     0,
     221,     0,     0,     0,   296,   297,   298,   299,   300,   301,
     302,   222,     0,     0,     0,     0,     0,     0,     0,   223,
     224,   225,     0,   226,   227,   228,     0,     0,   229,   230,
       0,   231,     0,   232,   233,   234,   235,     0,   236,   237,
       0,   238,     0,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    28,
      29,    30,    31,    38,    39,    40,     0,     0,    25,    26,
       0,     0,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    28,    29,    30,    31,    38,    39,    40,
      80,    81,    25,    26,     0,    82,   489,   490,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   269,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   117,   118,   119,   120,   121,
       0,     0,     0,  -331,     0,   201,     0,   202,   203,   204,
     205,   206,   207,   208,   209,   122,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,     0,   221,     0,
       0,     0,     0,     0,   117,   118,   119,   120,   121,   222,
       0,     0,     0,   184,     0,     0,     0,   223,   224,   225,
       0,   226,   227,   228,   122,     0,   229,   230,     0,   231,
       0,   232,   233,   234,   235,     0,   236,   237,     0,   238,
       0,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,     0,     0,   117,   118,
     119,   120,   121,     0,     0,     0,     0,     0,     0,     0,
       0,    38,    39,    40,     0,     0,    25,    26,   122,     0,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    28,    29,    30,    31,    38,    39,    40,    80,    81,
      25,    26,     0,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      28,    29,    30,    31,    38,    39,    40,    80,    81,    25,
      26,     0,    82,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    28,    29,    30,    31,    38,    39,
      40,    80,    81,    25,    26,     0,    82,     0,     0,     0,
       0,     0,     0,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    28,    29,    30,    31,    38,    39,
      40,    80,    81,    25,    26,   269,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   293,   294,     0,
     295,   201,     0,   202,   203,   204,   205,   206,   207,   208,
     209,     0,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,     0,   221,     0,     0,     0,   296,   297,
     298,   299,   300,   301,   302,   222,     0,     0,     0,     0,
       0,     0,     0,   223,   224,   225,     0,   226,   227,   228,
       0,     0,   229,   230,     0,   231,     0,   232,   233,   234,
     235,     0,   236,   237,     0,   238,     0,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    28,    29,    30,    31,    38,    39,    40,
     269,     0,    25,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   201,     0,   202,   203,
     204,   205,   206,   207,   208,   209,     0,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,     0,   221,
       0,     0,     0,   296,   297,   298,   299,   300,   301,   302,
     222,     0,     0,     0,     0,     0,     0,     0,   223,   224,
     225,     0,   226,   227,   228,     0,     0,   229,   230,     0,
     231,     0,   232,   233,   234,   235,     0,   236,   237,     0,
     238,     0,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    28,    29,
      30,    31,    38,    39,    40,   697,     0,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   201,     0,   202,   203,   204,   205,   206,   207,   208,
     209,     0,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,     0,   221,     0,     0,     0,   296,   297,
     298,   299,   300,   301,   302,   222,     0,     0,     0,     0,
       0,     0,     0,   223,   224,   225,     0,   226,   227,   228,
       0,     0,   229,   230,     0,   231,     0,   232,   233,   234,
     235,     0,   236,   237,     0,   238,     0,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    28,    29,    30,    31,    38,    39,    40,
     200,     0,    25,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   201,     0,   202,   203,
     204,   205,   206,   207,   208,   209,     0,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     222,     0,     0,     0,     0,     0,     0,     0,   223,   224,
     225,     0,   226,   227,   228,     0,     0,   229,   230,     0,
     231,     0,   232,   233,   234,   235,     0,   236,   237,     0,
     238,     0,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   269,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,    39,    40,     0,     0,    25,    26,     0,
       0,     0,     0,   201,     0,   202,   203,   204,   205,   206,
     207,   208,   209,     0,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,     0,   221,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   222,     0,     0,
       0,     0,     0,     0,     0,   223,   224,   225,     0,   226,
     227,   228,     0,     0,   229,   230,     0,   231,     0,   232,
     233,   234,   235,     0,   236,   237,     0,   238,     0,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      39,    40
  };

  /* YYCHECK.  */
  const short int
  MapSetParser::yycheck_[] =
  {
        11,   101,   183,    12,    13,    14,    15,    16,   187,   407,
     187,   136,   112,   112,   221,   192,   642,   443,    27,    53,
     400,    28,    45,    44,   192,    24,    51,   630,    44,    54,
      42,    55,    44,   390,    43,    92,   136,   136,    44,    44,
      42,    44,    51,   140,    27,    54,   729,    44,   413,   414,
      59,    42,    55,    45,    16,    51,     0,   182,    54,    44,
      43,    53,    53,    25,   161,    45,    69,   432,    20,    68,
      55,    17,   134,    53,   166,   254,   101,   254,    44,   141,
      21,   105,   182,   182,    69,    56,    55,   112,    41,    55,
     101,   100,   101,   270,   683,   195,   195,   700,   687,   782,
      25,   112,   270,   112,    42,    51,   115,    12,    54,    14,
      15,   136,   171,   172,    60,   140,   173,    41,    55,   153,
     105,    33,    34,   134,   149,   136,   167,   136,   139,   140,
     141,   140,    22,    23,   491,    57,   161,    41,   149,   105,
     149,    42,   166,   167,   168,    48,   572,   166,   171,   172,
     161,   153,   161,   174,   511,   101,    42,   182,   174,   166,
     167,   168,   174,   166,   167,   168,   112,    44,   174,   174,
     195,   182,   183,   182,   800,    48,   187,   174,    55,   562,
     563,   166,   167,   168,   195,    44,   195,    17,   134,    95,
     136,    41,    69,   139,   140,   141,   142,   166,   167,   168,
     166,   167,   168,   149,   568,   569,    24,    48,    51,   635,
      57,    54,    17,   390,   640,   161,   166,   167,   168,   165,
     427,    30,   390,    41,   162,   163,   164,   165,   105,   166,
     167,   168,    35,    96,   171,   172,   182,   183,    17,    18,
      29,   187,    54,   254,    79,    53,   192,    44,    66,   195,
     293,   294,   295,   651,    44,   266,    35,    44,   101,   639,
      44,    44,    41,    44,    44,   290,    66,    67,    44,   112,
      49,    50,    44,    52,    44,    44,    44,   288,    44,   290,
      44,   290,   162,   163,   164,   165,    44,   713,   106,   166,
     167,   168,    44,   136,   171,   172,    44,   140,   174,   174,
     400,   400,    44,    44,    44,    44,   149,   174,   254,    44,
     166,   167,   168,   174,   491,   171,   172,    44,   161,    44,
      44,    44,    44,   491,   270,   493,    44,    44,    44,   340,
      44,    44,    44,    44,   511,    44,    44,    44,    44,   182,
      44,    44,   288,   511,   290,   420,   421,   422,   423,   424,
     425,   130,   195,   560,    44,    44,   156,   157,   158,   159,
     160,   161,    60,    61,    62,    63,    64,    65,   794,    44,
      44,    30,    70,    71,    42,   400,    48,    41,    44,   390,
      22,    44,   407,    44,    94,    41,   153,    45,   814,   400,
     816,   400,   403,   404,   153,    34,   407,    33,   407,    26,
      45,    58,    71,    53,   415,    59,    53,    45,    45,   269,
      45,     3,     4,     5,     6,     7,     8,     9,    10,    11,
     545,    13,    53,    45,    45,    53,    45,   825,    45,    53,
      45,    45,    45,    45,    45,    53,    45,    53,    45,    45,
      45,    45,    45,    53,   390,   545,   545,   290,    45,    45,
      45,   630,    53,   630,   400,    45,    45,   403,   404,    53,
      45,   407,    45,    45,   324,   325,   326,    53,    45,   329,
      45,    45,   332,   333,   334,   486,   336,   337,   338,   339,
     491,   341,   342,   343,   344,   345,   346,    45,   348,    53,
      45,   351,   352,   353,   354,    45,   356,    45,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     545,   700,    41,   700,    44,    68,    44,    43,    45,   710,
      42,   107,    45,    54,   545,    45,   545,    45,    42,   639,
     639,    94,    46,    47,    53,   491,    45,    45,    45,    45,
      53,    45,    45,    45,    45,    45,    80,   400,    45,    45,
     153,    45,    19,    51,   407,   511,   107,    42,    45,    54,
      53,    60,    45,    45,    42,   767,   700,   165,   631,   709,
     491,   527,   270,   529,   530,   396,   769,   254,   395,   508,
     791,   514,   322,   403,   690,   288,   290,   802,   527,   545,
     530,   727,   725,   550,   552,   630,   564,   687,   430,   430,
     808,    -1,    -1,    -1,   639,   796,    -1,    -1,    -1,   630,
      -1,   630,    -1,    -1,   484,    -1,   651,    -1,   639,    -1,
     639,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     651,    -1,   651,    -1,    -1,    -1,    -1,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    -1,   691,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,   700,    -1,    -1,    -1,    -1,
     691,    -1,   691,    -1,   630,    -1,   546,   547,    -1,   700,
      -1,   700,    -1,   639,    -1,    -1,   642,    -1,   644,   710,
      -1,    -1,   545,    -1,    -1,   651,    -1,    -1,    -1,    -1,
      -1,   571,    45,    46,    47,    -1,    -1,   577,   578,   579,
      -1,    -1,    -1,   583,    -1,    -1,   586,    -1,    -1,    -1,
      -1,   591,    -1,    -1,   594,   595,    -1,    -1,    -1,    -1,
      -1,    -1,   602,    -1,    -1,   691,   606,    -1,    -1,    -1,
     610,    -1,    -1,    -1,   700,    -1,   616,    -1,    -1,    -1,
      -1,    -1,   773,    -1,   710,    -1,   791,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   638,   725,
     791,   727,   791,    -1,    -1,   796,    -1,   630,    -1,    -1,
      -1,   802,    -1,    -1,    -1,    -1,   639,    -1,    -1,    -1,
     825,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   651,    -1,
      -1,    -1,    -1,    -1,   825,    -1,   825,    -1,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,   697,   171,   172,
      -1,    -1,    -1,    -1,    -1,   791,    -1,    -1,   691,    -1,
     796,    -1,    -1,    -1,   800,    -1,   802,   700,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,   825,
     740,    -1,   742,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,    -1,    66,    67,
     174,    69,    70,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    -1,    -1,   791,    97,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,
     118,    -1,    -1,   121,   122,    -1,   124,    -1,   126,   127,
     128,   129,   825,   131,   132,    -1,   134,    -1,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,    24,    -1,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    44,    -1,    70,    -1,    72,
      73,    74,    75,    76,    77,    78,    79,    56,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
     113,   114,    -1,   116,   117,   118,    -1,    -1,   121,   122,
      -1,   124,    -1,   126,   127,   128,   129,    -1,   131,   132,
      -1,   134,    -1,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,   171,   172,
      -1,    -1,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    44,    -1,    70,    -1,    72,    73,    74,
      75,    76,    77,    78,    79,    56,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,   104,
      -1,    -1,    -1,    45,    -1,    -1,    -1,   112,   113,   114,
      -1,   116,   117,   118,    56,    -1,   121,   122,    -1,   124,
      -1,   126,   127,   128,   129,    -1,   131,   132,    -1,   134,
      -1,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,    -1,    -1,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   166,   167,   168,    -1,    -1,   171,   172,    56,    -1,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,   174,    -1,    -1,    -1,
      -1,    -1,    -1,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    44,   174,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,
      69,    70,    -1,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    -1,    -1,    -1,    97,    98,
      99,   100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,   118,
      -1,    -1,   121,   122,    -1,   124,    -1,   126,   127,   128,
     129,    -1,   131,   132,    -1,   134,    -1,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      44,    -1,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      -1,    -1,    -1,    97,    98,    99,   100,   101,   102,   103,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,
     114,    -1,   116,   117,   118,    -1,    -1,   121,   122,    -1,
     124,    -1,   126,   127,   128,   129,    -1,   131,   132,    -1,
     134,    -1,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    44,    -1,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    -1,    -1,    -1,    97,    98,
      99,   100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,   118,
      -1,    -1,   121,   122,    -1,   124,    -1,   126,   127,   128,
     129,    -1,   131,   132,    -1,   134,    -1,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      44,    -1,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,
     114,    -1,   116,   117,   118,    -1,    -1,   121,   122,    -1,
     124,    -1,   126,   127,   128,   129,    -1,   131,   132,    -1,
     134,    -1,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   166,   167,   168,    -1,    -1,   171,   172,    -1,
      -1,    -1,    -1,    70,    -1,    72,    73,    74,    75,    76,
      77,    78,    79,    -1,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,   113,   114,    -1,   116,
     117,   118,    -1,    -1,   121,   122,    -1,   124,    -1,   126,
     127,   128,   129,    -1,   131,   132,    -1,   134,    -1,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,
     167,   168
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  MapSetParser::yystos_[] =
  {
         0,   176,   177,     0,    20,   192,   193,   195,   166,   178,
     194,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      13,   179,   180,    21,   196,   171,   172,   387,   162,   163,
     164,   165,   430,   439,   430,   430,   430,   430,   166,   167,
     168,   440,   441,    56,   185,   186,   191,    12,    14,    15,
     181,    41,   183,   184,    16,   212,   214,   215,   197,   430,
      92,   173,   431,   432,   433,   430,    41,   187,   188,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     169,   170,   174,   182,   388,   430,   434,   435,   436,   437,
     438,   440,   442,   183,   388,    25,   167,   430,   440,    57,
     190,    42,    41,   250,   198,    42,   189,   430,   385,   387,
     388,   251,   252,   213,   166,    48,    42,    36,    37,    38,
      39,    40,    56,   253,   261,   321,   377,   378,   380,   381,
     382,   385,   216,   430,   379,   256,    48,   262,   263,   323,
      44,   322,    27,    43,   217,   222,   223,    55,   324,   331,
     386,   387,   440,   255,   257,   258,   253,   324,   329,   330,
     377,   383,   384,   385,   324,    28,   218,   219,   220,   221,
     440,    95,   224,   225,   229,    41,   264,    57,   332,   335,
     384,    48,   254,    17,    45,   384,   221,    30,    35,   246,
     247,   248,    96,   226,   232,   265,   328,   334,   253,   386,
      44,    70,    72,    73,    74,    75,    76,    77,    78,    79,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    93,   104,   112,   113,   114,   116,   117,   118,   121,
     122,   124,   126,   127,   128,   129,   131,   132,   134,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   230,   231,   313,   387,   412,   414,
     416,   417,   420,   440,   287,   288,   289,   293,   294,    44,
     233,   234,   312,   313,   411,   412,    29,   227,   235,   199,
     200,   266,   267,   268,   271,   336,   377,   385,    54,   327,
      53,   333,   259,    66,    67,    69,    97,    98,    99,   100,
     101,   102,   103,   387,   389,   390,   393,   396,   397,   400,
     401,   407,   409,   410,   411,   412,   423,   425,   428,   430,
     434,   438,   440,    79,    44,    44,    44,   174,   413,    44,
     174,   319,    44,    44,    44,   418,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,   319,    44,   174,
     174,    44,    44,    44,    44,   174,    44,   174,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
     231,    44,   174,   314,   387,    44,   174,   296,   389,   234,
      30,    33,    34,   228,   241,   244,   245,   201,    42,   270,
      48,   272,   273,   338,   337,   325,   326,   331,   335,    41,
     410,   410,   410,    44,    44,    94,   206,   207,   392,   395,
      60,    61,    62,    63,    64,    65,    70,    71,   398,   399,
     406,   408,    44,   314,   429,   421,   389,   389,   389,   389,
     389,   389,   389,   419,   389,   389,   389,   389,   387,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   389,   389,    22,   316,   290,   295,    41,    45,    31,
      32,   236,   237,   238,   239,   240,   312,   387,   153,   153,
     242,   245,   243,   244,    26,   203,    17,    18,    35,    49,
      50,    52,   130,   269,   274,   275,   277,   281,   285,   286,
     302,   305,   306,   311,   268,   330,   347,    44,    55,    69,
     105,   339,   341,   348,   349,   350,   351,   354,   357,   359,
     365,   366,   387,   440,   332,   260,   316,   316,   387,    45,
      58,   391,    59,   394,   400,   400,   400,   400,   400,   400,
      71,   319,    66,    67,   402,   405,   436,   437,    24,    68,
     403,   316,   422,    45,    45,    45,   320,    53,    53,    53,
     264,    45,    45,    53,    45,    45,    53,    45,    45,    45,
      45,    53,    45,    45,    53,    53,    45,    45,    45,    45,
      45,    45,    53,    45,    45,    45,    53,    45,    45,    45,
      53,    45,    45,    45,    45,    45,    53,    45,    45,    45,
     389,    41,    45,   387,   300,   237,   411,    22,    23,   204,
     205,   202,   278,   282,   287,   276,   303,   312,    44,   254,
     307,   350,    44,    55,   105,   367,   372,   373,   375,   440,
     357,   340,   353,   356,    24,    41,    66,   106,   358,   360,
     364,   253,    24,   389,   424,   389,   393,   396,   319,   407,
     407,   403,   404,   409,   409,   389,   264,   318,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     315,   291,    42,    44,   174,   298,    24,    44,   208,   209,
     210,   211,   313,   387,   412,   423,   430,   434,   438,   222,
     279,   283,   264,   304,   389,   268,   264,    45,   370,   371,
     373,    55,   374,   440,   332,   107,   352,    68,   355,    53,
     153,   363,   376,    42,    45,    54,   426,   427,    45,    45,
      53,   317,    53,    45,    45,    45,    45,   317,   415,    45,
      45,    45,   415,    45,    45,   318,    42,    46,    47,   292,
     301,   387,   430,   434,   438,   440,   299,   389,   209,   224,
     386,   284,   264,    94,   310,    45,   369,   346,   354,   359,
     376,    42,    53,   362,    80,    45,   389,   389,    45,    45,
      45,   297,   207,   246,   280,    19,   249,   387,    51,   308,
     107,   368,    54,   345,    42,    42,   361,   376,    60,    45,
      45,   301,    45,   264,   386,    45,   309,   373,   341,   342,
     344,    42,   439,   264,   264,   343,   332
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
     425,   426,   427,   428,   429
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  MapSetParser::yyr1_[] =
  {
         0,   175,   177,   176,   178,   178,   179,   179,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   181,   181,
     181,   182,   182,   183,   184,   184,   185,   186,   186,   187,
     187,   188,   189,   190,   190,   191,   192,   193,   193,   194,
     194,   195,   197,   198,   196,   200,   201,   202,   199,   203,
     204,   204,   205,   205,   206,   207,   207,   208,   209,   209,
     209,   209,   209,   209,   209,   209,   210,   210,   211,   211,
     213,   212,   214,   215,   215,   216,   216,   217,   218,   218,
     219,   220,   221,   222,   223,   223,   224,   225,   225,   226,
     226,   227,   227,   228,   228,   229,   230,   230,   231,   231,
     231,   231,   232,   233,   233,   234,   235,   236,   236,   237,
     237,   238,   238,   239,   240,   240,   241,   241,   242,   242,
     243,   243,   244,   245,   246,   247,   248,   248,   249,   249,
     250,   252,   251,   253,   253,   254,   254,   255,   256,   256,
     258,   259,   260,   257,   261,   262,   263,   263,   265,   264,
     266,   266,   267,   268,   268,   269,   270,   270,   271,   272,
     273,   273,   274,   274,   274,   274,   274,   274,   274,   274,
     276,   275,   278,   279,   280,   277,   282,   283,   284,   281,
     285,   286,   287,   287,   289,   290,   288,   291,   291,   292,
     294,   293,   295,   295,   296,   296,   297,   297,   299,   298,
     298,   300,   300,   301,   301,   301,   301,   301,   301,   301,
     303,   304,   302,   306,   307,   305,   309,   308,   310,   310,
     311,   312,   312,   312,   313,   314,   315,   314,   316,   316,
     317,   318,   318,   319,   320,   319,   322,   321,   323,   321,
     324,   325,   326,   326,   327,   328,   328,   329,   330,   330,
     331,   331,   332,   333,   334,   334,   335,   337,   336,   338,
     336,   340,   339,   341,   341,   343,   342,   344,   344,   345,
     346,   346,   347,   348,   349,   350,   351,   352,   353,   353,
     354,   355,   356,   356,   357,   358,   358,   359,   359,   360,
     361,   361,   362,   362,   363,   363,   364,   364,   364,   364,
     365,   366,   366,   366,   366,   367,   368,   369,   369,   370,
     371,   371,   372,   372,   373,   374,   374,   375,   375,   375,
     376,   377,   377,   379,   378,   380,   381,   381,   381,   381,
     381,   382,   382,   383,   383,   384,   384,   385,   385,   386,
     386,   387,   387,   388,   388,   388,   388,   388,   388,   389,
     390,   391,   392,   392,   393,   394,   395,   395,   396,   397,
     398,   398,   399,   399,   399,   399,   399,   399,   399,   399,
     400,   401,   402,   402,   403,   403,   404,   404,   405,   405,
     405,   406,   406,   407,   408,   408,   409,   409,   409,   409,
     410,   410,   410,   410,   410,   410,   410,   410,   411,   412,
     412,   412,   412,   412,   412,   412,   412,   412,   412,   412,
     412,   412,   412,   412,   412,   412,   412,   412,   412,   412,
     412,   412,   412,   412,   412,   412,   412,   412,   412,   412,
     412,   412,   412,   412,   412,   412,   412,   412,   412,   412,
     412,   412,   412,   412,   412,   412,   412,   412,   412,   412,
     412,   412,   413,   413,   414,   415,   415,   416,   418,   419,
     417,   421,   422,   420,   423,   423,   423,   424,   424,   425,
     425,   425,   425,   425,   426,   427,   427,   428,   429,   429,
     430,   431,   432,   432,   433,   433,   434,   434,   434,   435,
     435,   435,   436,   436,   436,   437,   437,   437,   438,   438,
     439,   439,   439,   439,   440,   440,   441,   441,   442,   442
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  MapSetParser::yyr2_[] =
  {
         0,     2,     0,     4,     0,     2,     0,     2,     4,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     0,     1,     4,     1,     2,     2,     0,     1,     0,
       1,     3,     3,     0,     2,     3,     2,     0,     1,     0,
       2,     2,     0,     0,     5,     0,     0,     0,     7,     3,
       1,     1,     0,     1,     2,     0,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       0,     8,     2,     0,     1,     0,     2,     2,     1,     1,
       1,     2,     1,     2,     0,     1,     4,     0,     1,     0,
       1,     0,     1,     0,     1,     3,     1,     2,     1,     1,
       4,     1,     2,     1,     2,     1,     3,     1,     2,     1,
       1,     1,     1,     2,     1,     1,     2,     2,     0,     1,
       0,     1,     2,     2,     1,     2,     0,     1,     0,     1,
       3,     0,     3,     0,     1,     0,     1,     3,     0,     2,
       0,     0,     0,     8,     2,     2,     0,     1,     0,     4,
       1,     1,     2,     0,     1,     3,     0,     2,     2,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     3,     0,     0,     0,     6,     0,     0,     0,     7,
       6,     2,     1,     1,     0,     0,     6,     0,     2,     1,
       0,     5,     0,     2,     1,     3,     0,     2,     0,     4,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       0,     0,     4,     0,     0,     4,     0,     3,     0,     2,
       2,     1,     1,     1,     2,     1,     0,     6,     0,     1,
       2,     0,     2,     1,     0,     5,     0,     3,     0,     3,
       3,     2,     0,     1,     2,     0,     2,     1,     0,     1,
       1,     1,     2,     2,     0,     2,     1,     0,     3,     0,
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
       6,     6,     6,     4,     4,     4,     4,     4,     4,     4,
       4,     2,     2,     2,     4,     4,     4,     4,     4,     2,
       8,     6,     6,     6,     4,     4,     4,     4,     4,     1,
       1,     1,     3,     1,     7,     0,     1,     7,     0,     0,
       4,     0,     0,     5,     5,     5,     6,     1,     1,     1,
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
    "\"end of file\"", "error", "$undefined", "IT_REWRITEVAR", "IT_DRIVER",
  "IT_SERVER", "IT_USER", "IT_PASSWORD", "IT_DATABASE", "IT_STEMURI",
  "IT_PRIMARYKEY", "IT_SHAREDVARS", "IT_PROMISCUOUS", "IT_INTERSECTION",
  "IT_DRACONIAN", "IT_VARNAMES", "IT_LABEL", "IT_GRAPH", "IT_SERVICE",
  "IT_SILENT", "IT_BASE", "IT_PREFIX", "IT_DISTINCT", "IT_REDUCED",
  "GT_TIMES", "IT_CONSTRUCT", "IT_SELECT", "IT_FROM", "IT_NAMED",
  "IT_ORDER", "IT_BY", "IT_ASC", "IT_DESC", "IT_LIMIT", "IT_OFFSET",
  "IT_VALUES", "IT_MEMBERS", "IT_STARTS", "IT_ENDS", "IT_ANY",
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
  "GT_PIPE", "IT_WITH", "IT_DEFAULT", "IT_ALL", "IT_USING", "IT_UUID",
  "IT_STRUUID", "IT_MD5", "IT_TO", "IT_STRBEFORE", "IT_STRAFTER",
  "IT_YEAR", "IT_ADD", "IT_COPY", "IT_RAND", "IT_SHA512",
  "GT_DELETE_LBRACKET_SPACECHAR_TAB_RETURN_LINEFEED_RBRACKET_PLUS_WHERE",
  "IT_NOW",
  "GT_DELETE_LBRACKET_SPACECHAR_TAB_RETURN_LINEFEED_RBRACKET_PLUS_DATA",
  "IT_TZ", "IT_TIMEZONE", "IT_ROUND", "IT_SHA384", "IT_BIND",
  "IT_CONTAINS", "IT_SECONDS", "IT_MOVE", "IT_FLOOR",
  "GT_INSERT_LBRACKET_SPACECHAR_TAB_RETURN_LINEFEED_RBRACKET_PLUS_DATA",
  "IT_MINUTES", "IT_SUBSTR", "IT_SHA256", "IT_HOURS", "IT_ENCODE_FOR_URI",
  "IT_STRSTARTS", "IT_CEIL", "IT_DAY", "IT_LCASE", "IT_ABS", "IT_UCASE",
  "IT_STRENDS", "IT_STRLEN", "IT_SHA1", "IT_MONTH", "IT_true", "IT_false",
  "INTEGER", "DECIMAL", "DOUBLE", "INTEGER_POSITIVE", "DECIMAL_POSITIVE",
  "DOUBLE_POSITIVE", "INTEGER_NEGATIVE", "DECIMAL_NEGATIVE",
  "DOUBLE_NEGATIVE", "STRING_LITERAL1", "STRING_LITERAL_LONG1",
  "STRING_LITERAL2", "STRING_LITERAL_LONG2", "IRIREF", "PNAME_NS",
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
  "SubSelect", "@4", "@5", "@6", "SelectClause",
  "_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C",
  "_Q_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C_E_Opt", "_O_QIT_AS_E_S_QVar_E_C",
  "_Q_O_QIT_AS_E_S_QVar_E_C_E_Opt",
  "_O_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_O_QBuiltInCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QVar_E_Or_QAggregate_E_Or_QFunctionCall_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_Q_O_QBuiltInCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QVar_E_Or_QAggregate_E_Or_QFunctionCall_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C_E_Plus",
  "_O_QBuiltInCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QVar_E_Or_QAggregate_E_Or_QFunctionCall_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_Plus_Or_QGT_TIMES_E_C",
  "ConstructQuery", "$@7", "_O_QIT_LABEL_E_S_QGraphTerm_E_C",
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
  "OffsetClause", "ValuesClause", "_O_QIT_VALUES_E_S_QDataBlock_E_C",
  "_Q_O_QIT_VALUES_E_S_QDataBlock_E_C_E_Opt", "_QIT_SILENT_E_Opt",
  "QuadPattern", "Quads", "$@8", "_QTriplesTemplate_E_Opt",
  "_QGT_DOT_E_Opt",
  "_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C_E_Star",
  "QuadsNotTriples", "@9", "@10", "$@11", "TriplesTemplate",
  "_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C_E_Opt", "GroupGraphPattern",
  "$@12", "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C",
  "GroupGraphPatternSub", "_QTriplesBlock_E_Opt",
  "_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "OptionalGraphPattern", "@13", "GraphGraphPattern", "@14", "@15", "@16",
  "ServiceGraphPattern", "@17", "@18", "@19", "Bind", "InlineData",
  "DataBlock", "InlineDataOneVar", "$@20", "$@21",
  "_QSingleValueRow_E_Star", "SingleValueRow", "InlineDataFull", "$@22",
  "_QVar_E_Star",
  "_O_QNIL_E_Or_QGT_LPAREN_E_S_QVar_E_Star_S_QGT_RPAREN_E_C",
  "_QDataBlockValue_E_Star",
  "_O_QGT_LPAREN_E_S_QDataBlockValue_E_Star_S_QGT_RPAREN_E_Or_QNIL_E_C",
  "$@23",
  "_Q_O_QGT_LPAREN_E_S_QDataBlockValue_E_Star_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star",
  "DataBlockValue", "MinusGraphPattern", "@24", "@25",
  "GroupOrUnionGraphPattern", "@26", "@27",
  "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@28",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "@29", "_QIT_DISTINCT_E_Opt",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ExpressionList", "@30",
  "TriplesSameSubject", "$@31", "$@32", "PropertyListNotEmpty",
  "_O_QVerb_E_S_QObjectList_E_C", "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "Verb", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "TriplesSameSubjectPath", "$@33", "$@34",
  "PropertyListNotEmptyPath", "$@35", "_O_QVerbPath_E_Or_QVerbSimple_E_C",
  "_O_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_C", "$@36",
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
  "_O_Qiri_E_Or_QIT_a_E_Or_QGT_NOT_E_S_QPathNegatedPropertySet_E_Or_QGT_LPAREN_E_S_QPath_E_S_QGT_RPAREN_E_C",
  "PathNegatedPropertySet", "_O_QGT_PIPE_E_S_QPathOneInPropertySet_E_C",
  "_Q_O_QGT_PIPE_E_S_QPathOneInPropertySet_E_C_E_Star",
  "_O_QPathOneInPropertySet_E_S_QGT_PIPE_E_S_QPathOneInPropertySet_E_Star_C",
  "_Q_O_QPathOneInPropertySet_E_S_QGT_PIPE_E_S_QPathOneInPropertySet_E_Star_C_E_Opt",
  "_O_QPathOneInPropertySet_E_Or_QGT_LPAREN_E_S_QPathOneInPropertySet_E_S_QGT_PIPE_E_S_QPathOneInPropertySet_E_Star_Opt_S_QGT_RPAREN_E_C",
  "PathOneInPropertySet", "_O_Qiri_E_Or_QIT_a_E_C",
  "_O_Qiri_E_Or_QIT_a_E_Or_QGT_CARROT_E_S_Qiri_E_Or_QIT_a_E_C", "Integer",
  "TriplesNode", "BlankNodePropertyList", "@37", "Generator",
  "_O_QIT_MEMBERS_E_Or_QIT_STARTS_E_Or_QIT_ENDS_E_Or_QIT_ANY_E_Or_QIT_UNORDERED_E_C",
  "_Q_O_QIT_MEMBERS_E_Or_QIT_STARTS_E_Or_QIT_ENDS_E_Or_QIT_ANY_E_Or_QIT_UNORDERED_E_C_E_Opt",
  "_QGraphNode_E_Plus", "GraphNode", "VarOrTerm", "VarOrIri", "Var",
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
  "SubstringExpression", "ExistsFunc", "@38", "@39", "NotExistsFunc",
  "@40", "@41", "Aggregate", "_O_QGT_TIMES_E_Or_QExpression_E_C",
  "_O_QIT_SUM_E_Or_QIT_MIN_E_Or_QIT_MAX_E_Or_QIT_AVG_E_Or_QIT_SAMPLE_E_C",
  "_O_QGT_SEMI_E_S_QIT_SEPARATOR_E_S_QGT_EQUAL_E_S_QString_E_C",
  "_Q_O_QGT_SEMI_E_S_QIT_SEPARATOR_E_S_QGT_EQUAL_E_S_QString_E_C_E_Opt",
  "iriOrFunction", "_QArgList_E_Opt", "RDFLiteral",
  "_O_QGT_DTYPE_E_S_Qiri_E_C", "_O_QLANGTAG_E_Or_QGT_DTYPE_E_S_Qiri_E_C",
  "_Q_O_QLANGTAG_E_Or_QGT_DTYPE_E_S_Qiri_E_C_E_Opt", "NumericLiteral",
  "NumericLiteralUnsigned", "NumericLiteralPositive",
  "NumericLiteralNegative", "BooleanLiteral", "String", "iri",
  "PrefixedName", "BlankNode", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const MapSetParser::rhs_number_type
  MapSetParser::yyrhs_[] =
  {
       176,     0,    -1,    -1,   177,   192,   178,   179,    -1,    -1,
     178,   180,    -1,    -1,   179,   212,    -1,     3,   387,   430,
     430,    -1,     4,   430,    -1,     5,   430,    -1,     6,   430,
      -1,     7,   430,    -1,     8,   430,    -1,     9,   440,    -1,
      10,   185,    -1,    11,   181,    -1,    13,   184,    -1,    12,
      -1,    15,    -1,    14,    -1,    -1,   388,    -1,    41,   182,
      42,   385,    -1,   183,    -1,   184,   183,    -1,   186,   187,
      -1,    -1,   191,    -1,    -1,   188,    -1,    41,   190,    42,
      -1,   430,    48,   430,    -1,    -1,   190,   189,    -1,    56,
     430,    57,    -1,   193,   194,    -1,    -1,   195,    -1,    -1,
     194,   196,    -1,    20,   166,    -1,    -1,    -1,    21,   197,
     167,   198,   166,    -1,    -1,    -1,    -1,   200,   201,   203,
     202,   222,   224,   246,    -1,    26,   205,   211,    -1,    22,
      -1,    23,    -1,    -1,   204,    -1,    94,   387,    -1,    -1,
     206,    -1,    44,   389,   207,    45,    -1,   412,    -1,   430,
      -1,   434,    -1,   438,    -1,   387,    -1,   423,    -1,   313,
      -1,   208,    -1,   209,    -1,   210,   209,    -1,   210,    -1,
      24,    -1,    -1,   215,    25,   250,   213,   216,   222,   224,
     246,    -1,    16,   388,    -1,    -1,   214,    -1,    -1,   216,
     217,    -1,    27,   218,    -1,   219,    -1,   220,    -1,   221,
      -1,    28,   221,    -1,   440,    -1,   223,   264,    -1,    -1,
      43,    -1,   225,   226,   227,   228,    -1,    -1,   229,    -1,
      -1,   232,    -1,    -1,   235,    -1,    -1,   241,    -1,    95,
      30,   230,    -1,   231,    -1,   230,   231,    -1,   412,    -1,
     313,    -1,    44,   389,   207,    45,    -1,   387,    -1,    96,
     233,    -1,   234,    -1,   233,   234,    -1,   312,    -1,    29,
      30,   236,    -1,   237,    -1,   236,   237,    -1,   239,    -1,
     240,    -1,    31,    -1,    32,    -1,   238,   411,    -1,   312,
      -1,   387,    -1,   244,   242,    -1,   245,   243,    -1,    -1,
     245,    -1,    -1,   244,    -1,    33,   153,    -1,    34,   153,
      -1,   248,    -1,    35,   287,    -1,    -1,   247,    -1,    -1,
      19,    -1,    41,   251,    42,    -1,    -1,   252,   253,   256,
      -1,    -1,   261,    -1,    -1,    48,    -1,   257,   254,   253,
      -1,    -1,   256,   255,    -1,    -1,    -1,    -1,   258,    17,
     386,   259,    41,   260,   253,    42,    -1,   321,   263,    -1,
      48,   253,    -1,    -1,   262,    -1,    -1,    41,   265,   266,
      42,    -1,   199,    -1,   267,    -1,   268,   270,    -1,    -1,
     271,    -1,   274,   254,   268,    -1,    -1,   270,   269,    -1,
     336,   273,    -1,    48,   268,    -1,    -1,   272,    -1,   305,
      -1,   275,    -1,   302,    -1,   277,    -1,   281,    -1,   311,
      -1,   285,    -1,   286,    -1,    -1,    49,   276,   264,    -1,
      -1,    -1,    -1,    17,   278,   279,   386,   280,   264,    -1,
      -1,    -1,    -1,    18,   282,   283,   284,   249,   386,   264,
      -1,   130,    44,   389,    94,   387,    45,    -1,    35,   287,
      -1,   288,    -1,   293,    -1,    -1,    -1,   289,   387,   290,
      41,   291,    42,    -1,    -1,   291,   292,    -1,   301,    -1,
      -1,   294,   296,    41,   300,    42,    -1,    -1,   295,   387,
      -1,   174,    -1,    44,   295,    45,    -1,    -1,   297,   301,
      -1,    -1,    44,   299,   297,    45,    -1,   174,    -1,    -1,
     300,   298,    -1,   440,    -1,   430,    -1,   434,    -1,   438,
      -1,    46,    -1,    47,    -1,   387,    -1,    -1,    -1,    50,
     303,   304,   264,    -1,    -1,    -1,   306,   307,   264,   310,
      -1,    -1,    51,   309,   264,    -1,    -1,   310,   308,    -1,
      52,   312,    -1,   411,    -1,   412,    -1,   313,    -1,   440,
     314,    -1,   174,    -1,    -1,    44,   316,   389,   315,   318,
      45,    -1,    -1,    22,    -1,    53,   389,    -1,    -1,   318,
     317,    -1,   174,    -1,    -1,    44,   389,   320,   318,    45,
      -1,    -1,   385,   322,   324,    -1,    -1,   377,   323,   329,
      -1,   331,   332,   328,    -1,   331,   332,    -1,    -1,   325,
      -1,    54,   326,    -1,    -1,   328,   327,    -1,   330,    -1,
      -1,   324,    -1,   386,    -1,    55,    -1,   335,   334,    -1,
      53,   335,    -1,    -1,   334,   333,    -1,   384,    -1,    -1,
     385,   337,   339,    -1,    -1,   377,   338,   347,    -1,    -1,
     341,   340,   332,   346,    -1,   348,    -1,   349,    -1,    -1,
     341,   343,   332,    -1,    -1,   342,    -1,    54,   344,    -1,
      -1,   346,   345,    -1,   330,    -1,   350,    -1,   387,    -1,
     351,    -1,   354,   353,    -1,   107,   354,    -1,    -1,   353,
     352,    -1,   359,   356,    -1,    68,   359,    -1,    -1,   356,
     355,    -1,   365,   358,    -1,    -1,   360,    -1,   357,    -1,
     105,   357,    -1,   364,    -1,    42,    -1,   376,    42,    -1,
      53,   361,    -1,    42,    -1,   376,   362,    -1,    53,   376,
      42,    -1,    24,    -1,   106,    -1,    66,    -1,    41,   363,
      -1,   366,    -1,   440,    -1,    55,    -1,    69,   367,    -1,
      44,   350,    45,    -1,   372,    -1,   107,   373,    -1,    -1,
     369,   368,    -1,   373,   369,    -1,    -1,   370,    -1,   373,
      -1,    44,   371,    45,    -1,   375,    -1,   440,    -1,    55,
      -1,   440,    -1,    55,    -1,   105,   374,    -1,   153,    -1,
     380,    -1,   378,    -1,    -1,    56,   379,   324,    57,    -1,
     382,    44,   383,    45,    -1,    36,    -1,    37,    -1,    38,
      -1,    39,    -1,    40,    -1,    -1,   381,    -1,   384,    -1,
     383,   384,    -1,   385,    -1,   377,    -1,   387,    -1,   388,
      -1,   387,    -1,   440,    -1,   171,    -1,   172,    -1,   440,
      -1,   430,    -1,   434,    -1,   438,    -1,   442,    -1,   174,
      -1,   390,    -1,   393,   392,    -1,    58,   393,    -1,    -1,
     392,   391,    -1,   396,   395,    -1,    59,   396,    -1,    -1,
     395,   394,    -1,   397,    -1,   400,   398,    -1,    -1,   399,
      -1,    60,   400,    -1,    61,   400,    -1,    62,   400,    -1,
      63,   400,    -1,    64,   400,    -1,    65,   400,    -1,    71,
     319,    -1,    70,    71,   319,    -1,   401,    -1,   407,   406,
      -1,   436,    -1,   437,    -1,    24,   409,    -1,    68,   409,
      -1,    -1,   403,    -1,    66,   407,    -1,    67,   407,    -1,
     402,   404,    -1,    -1,   406,   405,    -1,   409,   408,    -1,
      -1,   408,   403,    -1,    69,   410,    -1,    66,   410,    -1,
      67,   410,    -1,   410,    -1,   411,    -1,   412,    -1,   428,
      -1,   430,    -1,   434,    -1,   438,    -1,   387,    -1,   423,
      -1,    44,   389,    45,    -1,    81,    44,   389,    45,    -1,
      82,    44,   389,    45,    -1,    83,    44,   389,    53,   389,
      45,    -1,    84,    44,   389,    45,    -1,    85,    44,   387,
      45,    -1,    72,    44,   389,    45,    -1,    73,    44,   389,
      45,    -1,    74,   413,    -1,   121,   174,    -1,   145,    44,
     389,    45,    -1,   142,    44,   389,    45,    -1,   134,    44,
     389,    45,    -1,   128,    44,   389,    45,    -1,    93,   319,
      -1,   416,    -1,   148,    44,   389,    45,    -1,   146,    44,
     389,    45,    -1,   144,    44,   389,    45,    -1,   140,    44,
     389,    45,    -1,   131,    44,   389,    53,   389,    45,    -1,
     141,    44,   389,    53,   389,    45,    -1,   147,    44,   389,
      53,   389,    45,    -1,   116,    44,   389,    53,   389,    45,
      -1,   117,    44,   389,    53,   389,    45,    -1,   118,    44,
     389,    45,    -1,   150,    44,   389,    45,    -1,   143,    44,
     389,    45,    -1,   139,    44,   389,    45,    -1,   136,    44,
     389,    45,    -1,   132,    44,   389,    45,    -1,   127,    44,
     389,    45,    -1,   126,    44,   389,    45,    -1,   124,   174,
      -1,   112,   174,    -1,   113,   174,    -1,   114,    44,   389,
      45,    -1,   149,    44,   389,    45,    -1,   138,    44,   389,
      45,    -1,   129,    44,   389,    45,    -1,   122,    44,   389,
      45,    -1,    75,   319,    -1,    76,    44,   389,    53,   389,
      53,   389,    45,    -1,    77,    44,   389,    53,   389,    45,
      -1,    78,    44,   389,    53,   389,    45,    -1,    86,    44,
     389,    53,   389,    45,    -1,    87,    44,   389,    45,    -1,
      88,    44,   389,    45,    -1,    89,    44,   389,    45,    -1,
      90,    44,   389,    45,    -1,   104,    44,   389,    45,    -1,
     414,    -1,   417,    -1,   420,    -1,    44,   389,    45,    -1,
     174,    -1,    91,    44,   389,    53,   389,   415,    45,    -1,
      -1,   317,    -1,   137,    44,   389,    53,   389,   415,    45,
      -1,    -1,    -1,    79,   418,   419,   264,    -1,    -1,    -1,
      70,    79,   421,   422,   264,    -1,    97,    44,   316,   424,
      45,    -1,   425,    44,   316,   389,    45,    -1,   102,    44,
     316,   389,   427,    45,    -1,    24,    -1,   389,    -1,    98,
      -1,    99,    -1,   100,    -1,   101,    -1,   103,    -1,    54,
      80,    60,   439,    -1,    -1,   426,    -1,   440,   429,    -1,
      -1,   314,    -1,   439,   433,    -1,    92,   440,    -1,   173,
      -1,   431,    -1,    -1,   432,    -1,   435,    -1,   436,    -1,
     437,    -1,   153,    -1,   154,    -1,   155,    -1,   156,    -1,
     157,    -1,   158,    -1,   159,    -1,   160,    -1,   161,    -1,
     151,    -1,   152,    -1,   162,    -1,   164,    -1,   163,    -1,
     165,    -1,   166,    -1,   441,    -1,   168,    -1,   167,    -1,
     169,    -1,   170,    -1
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
     100,   103,   106,   107,   108,   114,   115,   116,   117,   125,
     129,   131,   133,   134,   136,   139,   140,   142,   147,   149,
     151,   153,   155,   157,   159,   161,   163,   165,   168,   170,
     172,   173,   182,   185,   186,   188,   189,   192,   195,   197,
     199,   201,   204,   206,   209,   210,   212,   217,   218,   220,
     221,   223,   224,   226,   227,   229,   233,   235,   238,   240,
     242,   247,   249,   252,   254,   257,   259,   263,   265,   268,
     270,   272,   274,   276,   279,   281,   283,   286,   289,   290,
     292,   293,   295,   298,   301,   303,   306,   307,   309,   310,
     312,   316,   317,   321,   322,   324,   325,   327,   331,   332,
     335,   336,   337,   338,   347,   350,   353,   354,   356,   357,
     362,   364,   366,   369,   370,   372,   376,   377,   380,   383,
     386,   387,   389,   391,   393,   395,   397,   399,   401,   403,
     405,   406,   410,   411,   412,   413,   420,   421,   422,   423,
     431,   438,   441,   443,   445,   446,   447,   454,   455,   458,
     460,   461,   467,   468,   471,   473,   477,   478,   481,   482,
     487,   489,   490,   493,   495,   497,   499,   501,   503,   505,
     507,   508,   509,   514,   515,   516,   521,   522,   526,   527,
     530,   533,   535,   537,   539,   542,   544,   545,   552,   553,
     555,   558,   559,   562,   564,   565,   571,   572,   576,   577,
     581,   585,   588,   589,   591,   594,   595,   598,   600,   601,
     603,   605,   607,   610,   613,   614,   617,   619,   620,   624,
     625,   629,   630,   635,   637,   639,   640,   644,   645,   647,
     650,   651,   654,   656,   658,   660,   662,   665,   668,   669,
     672,   675,   678,   679,   682,   685,   686,   688,   690,   693,
     695,   697,   700,   703,   705,   708,   712,   714,   716,   718,
     721,   723,   725,   727,   730,   734,   736,   739,   740,   743,
     746,   747,   749,   751,   755,   757,   759,   761,   763,   765,
     768,   770,   772,   774,   775,   780,   785,   787,   789,   791,
     793,   795,   796,   798,   800,   803,   805,   807,   809,   811,
     813,   815,   817,   819,   821,   823,   825,   827,   829,   831,
     833,   836,   839,   840,   843,   846,   849,   850,   853,   855,
     858,   859,   861,   864,   867,   870,   873,   876,   879,   882,
     886,   888,   891,   893,   895,   898,   901,   902,   904,   907,
     910,   913,   914,   917,   920,   921,   924,   927,   930,   933,
     935,   937,   939,   941,   943,   945,   947,   949,   951,   955,
     960,   965,   972,   977,   982,   987,   992,   995,   998,  1003,
    1008,  1013,  1018,  1021,  1023,  1028,  1033,  1038,  1043,  1050,
    1057,  1064,  1071,  1078,  1083,  1088,  1093,  1098,  1103,  1108,
    1113,  1118,  1121,  1124,  1127,  1132,  1137,  1142,  1147,  1152,
    1155,  1164,  1171,  1178,  1185,  1190,  1195,  1200,  1205,  1210,
    1212,  1214,  1216,  1220,  1222,  1230,  1231,  1233,  1241,  1242,
    1243,  1248,  1249,  1250,  1256,  1262,  1268,  1275,  1277,  1279,
    1281,  1283,  1285,  1287,  1289,  1294,  1295,  1297,  1300,  1301,
    1303,  1306,  1309,  1311,  1313,  1314,  1316,  1318,  1320,  1322,
    1324,  1326,  1328,  1330,  1332,  1334,  1336,  1338,  1340,  1342,
    1344,  1346,  1348,  1350,  1352,  1354,  1356,  1358,  1360,  1362
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  MapSetParser::yyrline_[] =
  {
         0,   460,   460,   460,   466,   468,   472,   474,   478,   487,
     490,   493,   496,   499,   502,   505,   507,   511,   517,   520,
     523,   529,   532,   536,   548,   549,   553,   556,   558,   561,
     563,   567,   571,   576,   578,   582,   589,   593,   595,   599,
     601,   605,   611,   613,   611,   623,   626,   629,   623,   644,
     652,   655,   662,   665,   670,   677,   680,   685,   692,   695,
     698,   701,   704,   707,   710,   714,   719,   722,   730,   733,
     740,   740,   752,   758,   761,   766,   769,   777,   784,   785,
     789,   795,   801,   808,   815,   817,   822,   829,   832,   837,
     840,   845,   848,   853,   857,   861,   868,   871,   878,   881,
     884,   887,   893,   899,   902,   909,   914,   921,   925,   933,
     935,   943,   946,   954,   962,   963,   970,   974,   982,   985,
     990,   993,   997,  1003,  1009,  1013,  1019,  1022,  1026,  1029,
    1035,  1041,  1041,  1049,  1051,  1055,  1057,  1061,  1064,  1066,
    1071,  1076,  1079,  1071,  1090,  1094,  1097,  1099,  1104,  1104,
    1115,  1116,  1121,  1125,  1127,  1137,  1141,  1144,  1160,  1165,
    1169,  1172,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,
    1189,  1189,  1205,  1209,  1211,  1205,  1222,  1226,  1228,  1222,
    1239,  1250,  1256,  1257,  1261,  1263,  1261,  1270,  1272,  1276,
    1284,  1284,  1291,  1293,  1299,  1300,  1303,  1305,  1311,  1311,
    1316,  1322,  1324,  1328,  1331,  1334,  1337,  1340,  1343,  1346,
    1352,  1356,  1352,  1366,  1370,  1366,  1380,  1380,  1392,  1394,
    1398,  1408,  1409,  1410,  1414,  1422,  1426,  1426,  1436,  1439,
    1446,  1452,  1454,  1468,  1471,  1471,  1481,  1481,  1484,  1484,
    1491,  1496,  1500,  1502,  1507,  1511,  1513,  1518,  1522,  1524,
    1528,  1532,  1540,  1545,  1549,  1551,  1555,  1563,  1563,  1566,
    1566,  1572,  1572,  1578,  1579,  1583,  1583,  1588,  1590,  1594,
    1597,  1599,  1603,  1607,  1611,  1617,  1621,  1625,  1628,  1630,
    1634,  1638,  1643,  1645,  1651,  1654,  1656,  1662,  1663,  1669,
    1673,  1674,  1678,  1679,  1683,  1684,  1688,  1689,  1690,  1691,
    1695,  1699,  1702,  1705,  1708,  1714,  1718,  1721,  1723,  1727,
    1730,  1732,  1736,  1737,  1741,  1745,  1746,  1750,  1751,  1752,
    1756,  1761,  1762,  1766,  1766,  1779,  1806,  1809,  1812,  1815,
    1818,  1825,  1828,  1833,  1837,  1844,  1845,  1849,  1852,  1856,
    1859,  1865,  1866,  1870,  1873,  1876,  1879,  1882,  1883,  1889,
    1894,  1903,  1910,  1913,  1921,  1930,  1937,  1940,  1947,  1952,
    1965,  1969,  1973,  1977,  1981,  1985,  1989,  1993,  1997,  2001,
    2008,  2013,  2022,  2025,  2032,  2035,  2042,  2045,  2050,  2053,
    2057,  2071,  2074,  2082,  2091,  2094,  2101,  2104,  2107,  2110,
    2114,  2115,  2116,  2117,  2120,  2123,  2126,  2129,  2133,  2139,
    2142,  2145,  2148,  2151,  2154,  2157,  2161,  2164,  2167,  2170,
    2173,  2176,  2179,  2182,  2183,  2186,  2189,  2192,  2195,  2198,
    2201,  2204,  2207,  2210,  2213,  2216,  2219,  2222,  2225,  2228,
    2231,  2234,  2237,  2240,  2243,  2246,  2249,  2252,  2255,  2258,
    2261,  2264,  2267,  2270,  2273,  2276,  2279,  2282,  2285,  2288,
    2289,  2290,  2296,  2299,  2306,  2313,  2316,  2320,  2326,  2329,
    2326,  2341,  2344,  2341,  2357,  2361,  2366,  2375,  2378,  2382,
    2385,  2388,  2391,  2394,  2400,  2406,  2409,  2413,  2423,  2426,
    2431,  2439,  2446,  2450,  2458,  2462,  2466,  2467,  2468,  2472,
    2473,  2474,  2478,  2479,  2480,  2484,  2485,  2486,  2490,  2491,
    2495,  2496,  2497,  2498,  2502,  2503,  2507,  2508,  2512,  2513
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
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int MapSetParser::yyeof_ = 0;
  const int MapSetParser::yylast_ = 2061;
  const int MapSetParser::yynnts_ = 268;
  const int MapSetParser::yyempty_ = -2;
  const int MapSetParser::yyfinal_ = 3;
  const int MapSetParser::yyterror_ = 1;
  const int MapSetParser::yyerrcode_ = 256;
  const int MapSetParser::yyntokens_ = 175;

  const unsigned int MapSetParser::yyuser_token_number_max_ = 429;
  const MapSetParser::token_number_type MapSetParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 4989 "C:\\Users\\Jelle\\Documents\\GitHub\\SWObjects\\lib\\MapSetParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 2519 "..\\..\\lib\\MapSetParser.ypp"
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
	root(NULL), unnestTree(false), 
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
    // clear prefixes for nth run but keep them around for e.g. serialization.
    clearPrefixes();

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


