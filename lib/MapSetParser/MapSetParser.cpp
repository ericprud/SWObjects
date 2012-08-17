/* A Bison parser, made by GNU Bison 2.5.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2011 Free Software Foundation, Inc.
   
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


/* Line 293 of lalr1.cc  */
#line 41 "lib/MapSetParser/MapSetParser.cpp"


#include "MapSetParser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 306 "lib/MapSetParser/MapSetParser.ypp"

#include "../MapSetScanner.hpp"

/* Line 299 of lalr1.cc  */
#line 445 "lib/MapSetParser/MapSetParser.ypp"

#include "../MapSetScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lexWrapper


/* Line 299 of lalr1.cc  */
#line 66 "lib/MapSetParser/MapSetParser.cpp"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                               \
 do                                                                    \
   if (N)                                                              \
     {                                                                 \
       (Current).begin = YYRHSLOC (Rhs, 1).begin;                      \
       (Current).end   = YYRHSLOC (Rhs, N).end;                        \
     }                                                                 \
   else                                                                \
     {                                                                 \
       (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;        \
     }                                                                 \
 while (false)
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


namespace w3c_sw {

/* Line 382 of lalr1.cc  */
#line 152 "lib/MapSetParser/MapSetParser.cpp"

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

  inline bool
  MapSetParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  MapSetParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

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
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 565 of lalr1.cc  */
#line 45 "lib/MapSetParser/MapSetParser.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
    driver.yylloc = &yylloc;
}

/* Line 565 of lalr1.cc  */
#line 347 "lib/MapSetParser/MapSetParser.cpp"

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
    if (yy_pact_value_is_default_ (yyn))
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
	if (yy_table_value_is_error_ (yyn))
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

/* Line 690 of lalr1.cc  */
#line 460 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root = new MapSet();
	driver.root->sharedVars = MapSet::e_PROMISCUOUS;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 478 "lib/MapSetParser/MapSetParser.ypp"
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

/* Line 690 of lalr1.cc  */
#line 487 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->driver = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 490 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->server = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 493 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->user = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 496 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->password = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 499 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->database = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 502 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->stemURI = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 507 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.sharedVarsSet = true;
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 511 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.lastRuleTermSet = false;
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 517 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_PROMISCUOUS;
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 520 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_VARNAMES;
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 523 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_DRACONIAN;
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 529 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = NULL;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 536 "lib/MapSetParser/MapSetParser.ypp"
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

/* Line 690 of lalr1.cc  */
#line 571 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->keyMap[(yysemantic_stack_[(3) - (1)].p_RDFLiteral)->getLexicalValue()] = (yysemantic_stack_[(3) - (3)].p_RDFLiteral)->getLexicalValue();
    }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 582 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->primaryKey = (yysemantic_stack_[(3) - (2)].p_RDFLiteral);
    }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 589 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 613 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 619 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 621 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 623 "lib/MapSetParser/MapSetParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 631 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 634 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 637 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 641 "lib/MapSetParser/MapSetParser.ypp"
    {
	  if ((yysemantic_stack_[(7) - (7)].p_BindingClause) != NULL)
	      (yysemantic_stack_[(7) - (5)].p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yysemantic_stack_[(7) - (7)].p_BindingClause), (yysemantic_stack_[(7) - (5)].p_WhereClause)->m_GroupGraphPattern);
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (4)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(7) - (3)].p_Project).distinctness, (yysemantic_stack_[(7) - (3)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(7) - (5)].p_WhereClause), (yysemantic_stack_[(7) - (6)].p_SolutionModifier))));
	  driver.curGraphName = (yysemantic_stack_[(7) - (2)].p_TTerm);
	  driver.countStar = (yysemantic_stack_[(7) - (1)].p_parentCountStar);
      }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 652 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 660 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 663 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 670 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 678 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 685 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 693 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 700 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 703 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 706 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 709 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 712 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 715 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 718 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 727 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 730 "lib/MapSetParser/MapSetParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 738 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 741 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 748 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = NULL;
      }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 750 "lib/MapSetParser/MapSetParser.ypp"
    {
	/* $3 is NO LONGER known to be a DefaultGraphPattern because of grammar restrictions. */
	if ((yysemantic_stack_[(8) - (8)].p_BindingClause) != NULL)
	    (yysemantic_stack_[(8) - (6)].p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yysemantic_stack_[(8) - (8)].p_BindingClause), (yysemantic_stack_[(8) - (6)].p_WhereClause)->m_GroupGraphPattern);
	Construct* constr = new Construct((DefaultGraphPattern*)((yysemantic_stack_[(8) - (3)].p_TableOperation) ? (yysemantic_stack_[(8) - (3)].p_TableOperation) : new DefaultGraphPattern()), (yysemantic_stack_[(8) - (5)].p_DatasetClauses), (yysemantic_stack_[(8) - (6)].p_WhereClause), (yysemantic_stack_[(8) - (7)].p_SolutionModifier));
	driver.root->maps.push_back(LabeledConstruct((yysemantic_stack_[(8) - (1)].p_TTerm), constr));
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 760 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (2)].p_TTerm);
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 766 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = NULL;
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 774 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 777 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 785 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 797 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 803 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 809 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 816 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.ensureGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 830 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 837 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 845 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 853 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 861 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 869 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 876 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 879 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 886 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 889 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 892 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 895 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 901 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 907 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 910 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 922 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 929 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 933 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 943 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 951 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 954 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 962 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 971 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 978 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 982 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 990 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 998 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1005 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1011 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1018 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1020 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1028 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1034 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1037 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1043 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.startBindingRow(); // @@ push down to _Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star?
      }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1045 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1048 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1060 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1063 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1066 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1069 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1072 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1075 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1078 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1084 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
    }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1090 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1092 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TableOperation) = driver.ensureGraphPattern();
	  driver.curOp = NULL;
      }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1120 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1125 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1128 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1131 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1153 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1155 "lib/MapSetParser/MapSetParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1232 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_BindingClause)) : (yysemantic_stack_[(1) - (1)].p_BindingClause);
    }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1238 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1242 "lib/MapSetParser/MapSetParser.ypp"
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

  case 186:

/* Line 690 of lalr1.cc  */
#line 1254 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1258 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1260 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1263 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1271 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1275 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1277 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1280 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(7) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(7) - (6)].p_TTerm), driver.curOp, (yysemantic_stack_[(7) - (5)].p_Silence), driver.atomFactory, false));
	  driver.curGraphName = (yysemantic_stack_[(7) - (4)].p_TTerm);
      }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1288 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1291 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1297 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = new Bind(driver.ensureGraphPattern(), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
	// no more triples go into the current BGP, per
	//   http://www.w3.org/TR/sparql11-query/#sparqlTranslateGraphPatterns
	// test reference:
	//   http://www.sparql.org/query-validator?query=ASK+{+%3Fs+%3Fp+%3Fo+FILTER+%281%29+BIND+%282+AS+%3Fb%29+%3Fs2+%3Fp2+%3Fo2+FILTER+%283%29+BIND+%284+AS+%3Fd%29}&languageSyntax=SPARQL&outputFormat=algebra&linenumbers=false
	driver.curBGP = NULL;
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1308 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1312 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1314 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1322 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1326 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1328 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1336 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1341 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.ensureGraphPattern());
      }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1354 "lib/MapSetParser/MapSetParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    driver.ensureGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1370 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 1378 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1382 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 1385 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yysemantic_stack_[(6) - (4)].p_Expressions);
      }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 1392 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 1395 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 1402 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 1410 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1424 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 1427 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1430 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(5) - (3)].p_Expressions);
      }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 1437 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 1440 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 1500 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 1507 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 1511 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 1519 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 1522 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 1528 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 1539 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 1567 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 1594 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 1601 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 1612 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 1619 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 1655 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 1658 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 1661 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 1664 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 1722 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 1726 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 1735 "lib/MapSetParser/MapSetParser.ypp"
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
	    error(yylloc, "unsupported function");
	}
    }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 1760 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 1763 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 1766 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 1769 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 1772 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 1779 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 1787 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 1791 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 1803 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 1810 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 1813 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 1824 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 1827 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 1830 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 1833 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 1837 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 1848 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 1857 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 1864 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 1867 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 1875 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 1884 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 1891 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 1894 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 1906 "lib/MapSetParser/MapSetParser.ypp"
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

  case 347:

/* Line 690 of lalr1.cc  */
#line 1919 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = NULL;
    }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 1927 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 1931 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 1935 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 1939 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 1943 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 1947 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 1951 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 1955 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = true;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 1967 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 1976 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 1979 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 1986 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 1989 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 1996 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 2004 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 2007 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 2011 "lib/MapSetParser/MapSetParser.ypp"
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

  case 368:

/* Line 690 of lalr1.cc  */
#line 2025 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 2028 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 2036 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 2045 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 2048 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 2055 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 2058 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 2061 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 2071 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 2074 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 2077 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 2080 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 2087 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 2093 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 2096 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 2099 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 2102 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 2105 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 2108 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 2111 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 2115 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 2118 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 2121 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 2124 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ceil, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 2127 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 2130 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 2133 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 2137 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 2140 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 2143 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 2146 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 2149 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 2152 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 2155 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 2158 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 2161 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 2164 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 2167 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 2170 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 2173 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 2176 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 2179 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 2182 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 2185 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 2188 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 2191 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_uuid, NULL, NULL, NULL));
    }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 2194 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_struuid, NULL, NULL, NULL));
    }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 2197 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 2200 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 2203 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 2206 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 2209 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 2212 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 2215 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 2218 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 2221 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 2224 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 2227 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 2230 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 2233 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 2236 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 2239 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 2250 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 2253 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 2260 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 2267 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 2274 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 2280 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.ensureGraphPattern(), NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 2287 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.ensureGraphPattern(), NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 2294 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 2298 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 2303 "lib/MapSetParser/MapSetParser.ypp"
    {
	  if ((yysemantic_stack_[(6) - (5)].p_RDFLiteral) != NULL) {
	      std::stringstream ss;
	      ss << "GROUP_CONCAT ; " << (yysemantic_stack_[(6) - (5)].p_RDFLiteral)->getLexicalValue();
	      w3c_sw_NEED_IMPL(ss.str());
	  }
	  (yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression)));
    }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 2314 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 2321 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 2324 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 2327 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 2330 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 2333 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 2339 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 2345 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 2352 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 2362 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 2370 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 2378 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 2385 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 2389 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 2397 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 690 of lalr1.cc  */
#line 3272 "lib/MapSetParser/MapSetParser.cpp"
	default:
          break;
      }
    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
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
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
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

    yyerror_range[1] = yylocation_stack_[yylen - 1];
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
	if (!yy_pact_value_is_default_ (yyn))
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

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
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
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

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
  MapSetParser::yysyntax_error_ (int yystate, int yytoken)
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yychar.
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            /* Stay within bounds of both yycheck and yytname.  */
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = 0;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int MapSetParser::yypact_ninf_ = -686;
  const short int
  MapSetParser::yypact_[] =
  {
      -686,    57,    40,  -686,   -88,  -686,  -686,  -686,  -686,   451,
      59,   -99,    62,    62,    62,    62,    62,    83,    48,   172,
      75,    39,  -686,  -686,  -686,  -686,  -686,    62,  -686,  -686,
    -686,  -686,  -686,   -73,  -686,  -686,  -686,  -686,  -686,  -686,
    -686,  -686,  -686,    62,  -686,    81,  -686,  -686,  -686,  -686,
    -686,   647,  -686,    75,   647,  -686,  -686,   101,   -34,    62,
      83,  -686,  -686,  -686,  -686,    78,  -686,  -686,  -686,  -686,
    -686,  -686,  -686,  -686,  -686,  -686,  -686,  -686,  -686,  -686,
    -686,  -686,  -686,    95,  -686,  -686,  -686,  -686,  -686,  -686,
    -686,  -686,  -686,  -686,  -686,   115,  -686,  -686,  -686,  -686,
      35,   539,  -686,  -686,    -7,  -686,  -686,   127,  -686,  -686,
    -686,   137,  1021,  -686,  -686,    62,  -686,  -686,  -686,  -686,
    -686,  -686,  -686,  -686,  -686,   141,  -686,  -686,  -686,  -686,
     158,  -686,    22,  -686,   -24,   199,  1021,  -686,  -686,   -24,
    1323,   -24,    -6,  -686,  -686,   123,   191,  -686,   176,  1323,
    -686,  -686,  -686,  -686,   190,   222,  -686,  -686,  -686,  -686,
    -686,  1288,  -686,  -686,  -686,    83,  -686,  -686,  -686,  -686,
    -686,   217,   218,   162,  -686,  -686,  -686,  -686,  -686,  -686,
    -686,  -686,  1021,   122,  -686,  -686,  -686,  1827,  -686,  -686,
    -686,  1934,   230,  -686,   320,   207,   220,  -686,  -686,  1452,
     196,   243,   247,   -20,   -16,   251,   253,   255,   191,   256,
     257,   258,   259,   260,   261,   262,   264,   265,   268,   270,
     -16,   272,   143,   144,   276,   277,   278,   279,   151,   282,
     153,   284,   285,   287,   289,   290,   292,   294,   296,   297,
     298,   300,   301,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   317,  1827,  -686,  -686,  -686,  -686,  -686,  -686,
    -686,  -686,     3,  -686,  1452,  1934,  -686,  -686,  -686,  -686,
    -686,   332,    55,  -686,  -686,  -686,   321,  -686,  -686,  -686,
     318,  -686,  -686,   -24,  -686,  1323,  -686,   324,  1577,  1577,
    1577,   325,  -686,  -686,  -686,  -686,   326,  -686,  -686,   281,
    -686,  -686,  -686,  -686,   342,  -686,  -686,  -686,  -686,  -686,
    -686,  -686,   328,  -686,  -686,  -686,  -686,     3,   191,  1452,
    1452,  1452,  -686,  -686,  1452,  -686,  -686,  1452,  1452,  1452,
    -686,  1452,  1452,  1452,  1452,   -99,  1452,  1452,  1452,  1452,
    1452,  1452,  -686,  1452,  -686,  -686,  1452,  1452,  1452,  1452,
    -686,  1452,  -686,  1452,  1452,  1452,  1452,  1452,  1452,  1452,
    1452,  1452,  1452,  1452,  1452,  1452,  1452,  1452,  1452,  1452,
    1452,  1452,  1452,  1452,  1452,  -686,   351,  -686,  -686,   -26,
     333,  -686,  1264,   224,   226,  -686,  -686,   346,   349,   360,
    -686,   205,  1021,  -686,  -686,   -24,    63,  -686,  -686,  1323,
    -686,  -686,  -686,  -686,  -686,   351,   351,   -99,  -686,   344,
     329,   334,  1452,  1452,  1452,  1452,  1452,  1452,   323,   -16,
    -686,  -686,   125,    13,   351,  -686,  -686,  -686,   347,   350,
     352,  -686,   338,   345,   356,   354,   355,   357,   366,   370,
     363,   372,   373,   374,   375,   369,   378,   379,   376,   380,
     382,   383,   392,   394,   395,   396,   389,   398,   400,   402,
     399,   403,   406,   418,   412,   421,   422,   423,   424,   448,
     442,   453,   454,   455,  -686,  1452,  -686,  -686,  -686,  -686,
    -686,  1264,  -686,   381,  -686,  -686,  -686,  -686,  -686,  -686,
    -686,  -686,  -686,  -686,    90,  -686,  -686,  -686,  -686,  -686,
    1934,   452,  -686,  -686,   190,  -686,  -686,  -686,  -686,  -686,
    -686,  -686,  -686,  -686,  -686,  -686,    -3,  -686,    14,    41,
    -686,  -686,  -686,  -686,  -686,  -686,  -686,  -686,  -686,    43,
    -686,  -686,  -686,  -686,  1021,   880,  1452,  -686,  -686,  1452,
    -686,  1452,  -686,  -686,  -686,  -686,  -686,  -686,  -686,   -16,
    -686,  1452,  1452,    13,  -686,  -686,  -686,  1452,  1452,  -686,
    1452,  -686,  -686,  -686,  -686,  1452,  1452,  1452,  -686,  -686,
    1452,  -686,  -686,  1452,  -686,  -686,  -686,  -686,  1452,  -686,
    -686,  1452,  1452,  -686,  -686,  -686,  -686,  -686,  -686,  1452,
    -686,  -686,  -686,  1452,  -686,  -686,  -686,  1452,  -686,  -686,
    -686,  -686,  -686,  1452,  -686,  -686,  -686,  -686,     4,  -686,
    -686,  -686,  -686,  -686,  1126,   458,  -686,  -686,   191,  -686,
    -686,  1452,  1021,   191,   459,    96,  -686,    38,  -686,  -686,
    -686,  -686,  -686,  -686,  1323,   405,   435,  -686,   -14,  -686,
    -686,  -686,  -686,  -686,   463,  -686,  -686,   461,   460,  -686,
    -686,  -686,  -686,  -686,  -686,  -686,  -686,  -686,   462,     6,
     464,   468,   471,   473,   474,   467,   476,   479,   484,   467,
     485,   486,  -686,  -686,  -686,  -686,  -686,  -686,  1452,  -686,
    -686,  1702,  -686,  -686,  -686,  -686,  -686,  -686,  -686,  -686,
     123,   122,  -686,  -686,   191,   438,  -686,  -686,  -686,  -686,
     488,  -686,  -686,  -686,  -686,  -686,    -3,  -686,    -3,  -686,
     407,  -686,  -686,   -15,  -686,  -686,   475,  -686,   489,  -686,
    -686,  1452,  -686,  1452,  -686,  -686,  -686,  -686,  -686,   513,
    -686,  -686,  -686,   514,  -686,  -686,     8,   481,   281,  -686,
     218,  -686,   542,  -686,   -99,   511,  -686,   456,   510,  -686,
    -686,   523,  -686,   -12,  -686,   506,  -686,  -686,   522,  -686,
    -686,  -686,  -686,  -686,   385,  -686,  -686,  -686,  -686,  -686,
    -686,   524,  -686,   191,  -686,   122,   526,  -686,  -686,    96,
    -686,    63,  -686,  -686,  -686,  -686,   532,    62,  -686,  -686,
    -686,  -686,  -686,   191,  -686,   191,  -686,  -686,  -686,  -686,
    -686,  -686,  -686,  -686,  1323,  -686
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  MapSetParser::yydefact_[] =
  {
         2,     0,    39,     1,     0,     4,    41,    40,    43,     6,
      38,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     3,     5,    44,    42,   328,   329,     0,   483,   485,
     484,   486,     9,   467,    10,    11,    12,    13,   487,   490,
     489,    14,   488,     0,    15,    29,    28,    18,    20,    19,
      16,    21,    24,    17,     0,     7,    76,     0,     0,     0,
       0,   465,   466,   468,   463,     0,    33,    26,    30,   481,
     482,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     491,   492,   335,     0,    22,   331,   332,   469,   470,   471,
     333,   330,   334,    25,    74,     0,    45,     8,   464,    35,
       0,     0,   145,    72,     0,    31,    34,     0,    23,   324,
     325,     0,   147,    77,    46,     0,   144,   313,   314,   315,
     316,   317,   310,   152,   148,   160,   225,   309,   308,   319,
       0,   223,    86,    32,     0,   146,   147,   161,   158,   235,
     318,     0,     0,    87,    78,    89,     0,   243,     0,   318,
     242,   326,   327,   153,   149,     0,   159,   236,   226,   234,
     323,   318,   320,   322,   224,     0,    79,    80,    81,    82,
      84,     0,    36,    91,    90,   162,    85,   311,   232,   239,
     241,   150,   147,     0,   312,   321,    83,     0,   126,    73,
      37,     0,    93,    92,   167,   227,   237,   151,   155,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    98,   101,   103,   100,   436,   400,
     437,   438,     0,   128,     0,   104,   105,   107,   210,   208,
     209,     0,    95,    94,   164,    48,     0,   165,   170,   168,
     174,   246,   244,   229,   233,   318,   240,     0,     0,     0,
       0,     0,   452,   453,   454,   455,     0,   456,   383,    57,
     336,   339,   343,   345,   347,   357,   368,   371,   376,   377,
     378,   384,     0,   379,   380,   381,   382,   461,     0,     0,
       0,     0,   440,   393,     0,   220,   426,     0,     0,     0,
     445,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   399,     0,   419,   420,     0,     0,     0,     0,
     394,     0,   418,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   215,   212,   211,     0,
       0,   106,     0,     0,     0,    88,    96,   120,   122,     0,
     163,   166,   167,   175,   172,   235,     0,   230,   231,   318,
     238,   156,   374,   375,   373,   215,   215,     0,    58,     0,
     337,   341,     0,     0,     0,     0,     0,     0,     0,     0,
     346,   348,   358,   370,   215,   462,   460,   446,     0,     0,
       0,   221,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   216,     0,   135,   129,   385,   113,
     114,   108,   109,     0,   111,   112,   116,   117,   124,   125,
     118,   121,   119,   123,    54,    49,   186,   190,   184,   197,
       0,     0,   183,   171,   149,   177,   179,   180,   182,   178,
     176,   201,   181,   173,   259,   247,     0,   289,     0,     0,
     245,   248,   250,   251,   260,   262,   265,   274,   269,   272,
     287,   261,   288,   228,   147,     0,     0,    56,   102,     0,
     340,     0,   344,   349,   350,   351,   352,   353,   354,     0,
     355,     0,     0,   363,   369,   359,   360,     0,     0,   372,
       0,   391,   392,   439,   218,     0,     0,     0,   386,   387,
       0,   389,   390,     0,   431,   432,   433,   434,     0,   435,
     421,     0,     0,   410,   425,   417,   416,   398,   424,     0,
     415,   397,   414,     0,   423,   413,   404,     0,   396,   412,
     403,   395,   402,     0,   401,   422,   411,   213,     0,   110,
     115,    52,    53,    55,     0,    86,   187,   191,     0,   198,
     207,     0,   167,     0,     0,   297,   305,     0,   290,   292,
     299,   301,   304,   275,   318,   263,   267,   283,     0,   285,
     284,   271,   273,   276,     0,   450,   451,     0,   458,   338,
     342,   356,   365,   366,   364,   367,   361,   362,     0,     0,
       0,     0,     0,     0,     0,   442,     0,     0,     0,   442,
       0,     0,   218,   127,   132,   134,   136,    71,     0,    67,
      68,    70,    51,    63,    60,    62,    61,    64,    65,    66,
      89,     0,   192,   185,     0,     0,   169,   205,   291,   298,
       0,   294,   303,   306,   302,   257,     0,   266,     0,   270,
       0,   307,   286,     0,   157,   447,     0,   459,     0,   448,
     222,     0,   219,     0,   428,   429,   388,   430,   443,     0,
     408,   409,   405,     0,   406,   407,     0,     0,    57,    69,
      36,   188,   194,   199,     0,   202,   300,   296,   249,   264,
     268,     0,   280,     0,   281,     0,   449,   217,     0,   441,
     444,   214,   141,   142,     0,   130,   143,   138,   139,   140,
     137,     0,    50,     0,   195,     0,     0,   203,   206,     0,
     295,   254,   258,   282,   277,   279,     0,     0,   427,   133,
     131,    59,   189,     0,   196,     0,   293,   252,   255,   256,
     278,   457,   193,   204,   318,   253
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yypgoto_[] =
  {
      -686,  -686,  -686,  -686,  -686,  -686,  -686,  -686,   515,  -686,
    -686,  -686,  -686,  -686,  -686,  -686,  -686,  -165,  -686,  -686,
    -686,  -686,  -686,  -686,  -686,  -686,  -686,  -686,  -686,  -686,
    -686,  -686,  -686,  -161,  -686,  -103,  -686,  -686,  -686,  -686,
    -686,  -686,  -686,  -686,  -686,  -686,  -686,   414,   -35,  -686,
    -109,  -686,  -686,  -686,  -686,  -686,  -686,   330,  -686,  -686,
     319,  -686,  -686,   104,  -686,  -686,  -686,  -686,  -686,  -686,
     194,   200,   195,  -686,  -686,  -686,  -686,  -686,  -686,  -174,
    -686,  -686,  -686,  -126,    87,  -686,  -686,  -686,  -686,  -686,
    -686,  -686,  -686,  -686,  -197,  -686,  -686,  -686,  -379,  -686,
    -686,  -686,  -686,  -686,  -686,  -686,  -686,  -686,  -686,  -686,
    -686,  -686,  -686,  -686,  -686,  -686,  -686,  -686,  -686,  -686,
    -686,  -686,  -686,  -686,  -686,  -686,  -686,  -347,  -179,   275,
    -686,  -362,  -590,   -79,  -206,  -686,  -686,  -686,  -686,   -71,
    -686,  -686,  -686,  -686,  -686,   204,  -390,  -686,  -686,   315,
     312,  -686,  -686,  -686,  -686,  -686,  -180,  -686,  -686,  -686,
    -686,  -686,  -686,  -686,  -686,    86,  -686,  -686,  -686,  -102,
    -686,  -686,    88,  -686,   -98,  -686,  -686,  -686,  -686,  -686,
    -686,  -686,  -686,  -686,  -686,  -686,  -686,  -686,  -605,  -686,
    -686,  -685,   -96,  -686,  -686,  -686,  -686,  -686,  -686,  -107,
    -100,  -181,   -11,    66,   528,  -686,  -686,  -686,    67,  -686,
    -686,    71,  -686,  -686,  -686,  -146,  -686,  -686,    61,  -686,
    -686,  -686,  -341,  -686,  -337,   -10,  -168,  -170,  -686,  -686,
     -61,  -686,  -686,  -686,  -582,  -686,  -686,  -686,  -686,  -686,
    -686,    -9,  -686,  -686,  -686,   -25,  -686,   193,   197,   116,
    -171,    54,  -686,  -686
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yydefgoto_[] =
  {
        -1,     1,     2,     9,    21,    22,    50,    83,    52,    53,
      44,    45,    67,    68,   106,   100,    46,   189,     5,     6,
      10,     7,    24,    58,   104,   274,   275,   389,   615,   495,
     613,   614,   408,   409,   679,   680,   681,   682,    55,   113,
      56,    57,   132,   144,   166,   167,   168,   169,   145,   146,
     172,   173,   192,   272,   385,   174,   253,   254,   193,   265,
     266,   273,   481,   482,   483,   484,   485,   386,   490,   492,
     387,   388,   190,   263,   379,   764,   676,   737,   608,   765,
     103,   111,   112,   123,   182,   153,   135,   154,   155,   287,
     534,   124,   137,   138,   176,   194,   276,   277,   278,   503,
     391,   279,   393,   394,   504,   505,   618,   506,   616,   691,
     773,   507,   617,   692,   742,   775,   508,   509,   619,   694,
     510,   511,   623,   778,   795,   745,   512,   267,   268,   378,
     672,   475,   722,   659,   326,   564,   125,   141,   139,   157,
     397,   398,   284,   195,   158,   159,   178,   286,   196,   179,
     149,   280,   396,   395,   520,   634,   521,   798,   804,   799,
     782,   748,   515,   522,   523,   524,   525,   707,   635,   526,
     709,   636,   527,   641,   528,   642,   785,   754,   712,   643,
     529,   530,   628,   780,   747,   699,   700,   629,   630,   703,
     631,   713,   160,   127,   134,   128,   129,   130,   161,   180,
     163,   150,   298,   110,   299,   300,   540,   410,   301,   542,
     411,   302,   303,   420,   421,   304,   305,   553,   559,   655,
     554,   422,   306,   423,   307,   308,   309,   310,   323,   258,
     729,   259,   260,   261,   311,   647,   312,   717,   718,   313,
     426,   314,    62,    63,    64,   315,    87,    88,    89,   316,
      33,   317,    42,    92
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int MapSetParser::yytable_ninf_ = -319;
  const short int
  MapSetParser::yytable_[] =
  {
        27,   108,   198,    32,    34,    35,    36,    37,   255,   533,
     156,   330,   131,   513,   342,   476,   126,   257,    59,    60,
     701,   270,   165,   269,   321,   751,    86,   752,   324,    86,
     784,   147,   686,   162,    65,   486,   131,   557,   753,   710,
     126,   516,    85,   535,   536,    85,   673,   376,   674,   142,
      97,   720,   517,   761,   185,    54,   197,     3,   625,   721,
       4,   721,   560,   148,   -75,   143,   518,   637,   786,   626,
     164,    41,    25,    26,   255,   728,    86,   105,     8,   728,
      23,   558,   131,   257,   638,   516,   126,    86,   383,   384,
     109,   107,    85,   702,   282,   270,   517,   269,   281,   686,
      61,   109,   519,    85,    43,    91,   133,   516,    91,   639,
     518,    86,   611,   612,    98,    86,    51,    84,   517,   627,
      94,   427,    66,   151,    86,   109,    95,    85,   151,   109,
     151,    85,   518,    96,   486,    99,    86,   101,   109,   711,
      85,   711,    38,    39,    40,    25,    26,    25,    26,   640,
     109,   626,    85,   620,   322,    91,   102,    86,   325,   114,
      38,    39,    40,    38,    39,    40,    91,    90,   519,    86,
      90,   109,   151,    85,   796,   115,   256,   377,   675,   116,
      38,    39,    40,   109,    47,    85,    48,    49,   152,   136,
      91,   551,   552,   152,    91,   152,   170,    28,    29,    30,
      31,   627,   140,    91,    38,    39,    40,    38,    39,    40,
     652,   653,   270,   550,   269,    91,  -154,    90,   171,   170,
     656,   657,   496,   497,    28,    29,    30,    31,    90,    38,
      39,    40,   175,   177,    25,    26,    91,   152,   181,   183,
     188,   262,   256,   696,   705,   262,  -200,   187,    91,    38,
      39,    40,    90,   188,   498,   499,    90,   500,   191,   271,
      86,   283,    38,    39,    40,    90,   543,   544,   545,   546,
     547,   548,   151,   285,   109,   318,    85,    90,   402,   403,
     404,    74,    75,    76,    77,    78,    79,   319,    38,    39,
      40,   320,   282,    25,    26,   327,   281,   328,    90,   329,
     331,   332,   333,   334,   335,   336,   337,   262,   338,   339,
      90,   270,   340,   269,   341,   610,   343,   344,   345,   262,
     346,   347,   348,   349,   439,   350,   351,   352,   353,   354,
     270,   355,   269,   356,   357,   501,   358,   152,   359,    91,
     360,   361,   362,   651,   363,   364,   -47,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   117,   118,   119,   120,
     121,   374,   382,   390,  -318,   401,   392,    86,   477,   405,
     406,   487,   424,   474,    86,   407,   122,   488,   478,   489,
     384,   109,   383,    85,   151,   531,   494,   539,   109,   538,
      85,   565,   561,   541,   549,   562,   537,   563,   566,   568,
     569,    90,   412,   413,   414,   415,   416,   417,   644,   567,
     570,   571,   418,   419,   805,   572,   573,   574,   575,   576,
     577,   693,   578,   579,   580,   264,   697,   583,   584,   581,
     789,   762,   763,   582,   131,   683,   262,   585,   126,   586,
     587,   588,   589,   590,   685,   591,    91,   592,   594,   152,
     532,   595,   593,    91,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   596,    20,   597,   598,   599,   600,   601,
     487,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    28,    29,    30,    31,    38,    39,    40,    80,
      81,    25,    26,   602,    82,   603,   621,   743,   604,   605,
     606,   143,   683,   708,   698,   714,   715,   719,    90,    86,
     741,   685,   706,   724,   716,    90,   725,   723,   726,   727,
     721,   730,   282,   109,   731,    85,   281,   762,   763,   732,
     734,   735,   744,   746,   756,   262,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    28,    29,    30,
      31,    38,    39,    40,   262,   755,    25,    26,   759,   760,
     711,   774,   777,   779,   781,   783,   787,   788,    93,   791,
     532,   794,   632,   532,   800,   772,   792,   771,   739,   186,
     690,   740,   493,   375,   381,   609,   502,   491,    91,   688,
     790,   622,   425,   736,   793,   399,   802,    86,   803,   514,
     400,   797,   624,   684,   749,   687,   649,   633,   733,    86,
     750,   109,   650,    85,   654,   555,   801,     0,     0,   556,
       0,     0,     0,   109,     0,    85,     0,     0,     0,     0,
       0,     0,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    28,    29,    30,    31,    38,    39,    40,
      90,     0,    25,    26,     0,     0,   688,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   262,     0,
     684,     0,   687,     0,     0,     0,    91,     0,     0,   632,
     151,   704,     0,     0,     0,     0,     0,     0,    91,     0,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    28,    29,    30,    31,    38,    39,    40,    80,    81,
      25,    26,   768,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   766,     0,   767,     0,
     689,     0,     0,   776,     0,   262,     0,     0,    90,   768,
       0,     0,     0,     0,     0,   152,     0,     0,     0,     0,
      90,     0,     0,   766,     0,   767,     0,     0,     0,     0,
     532,     0,   532,     0,   151,     0,     0,     0,     0,     0,
     531,     0,     0,     0,     0,     0,     0,     0,     0,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   770,   380,   109,     0,    85,     0,   689,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    28,
      29,    30,    31,    38,    39,    40,    80,    81,   770,     0,
       0,    82,     0,     0,     0,     0,     0,     0,     0,   152,
       0,     0,     0,   632,     0,   532,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   428,   429,   430,
       0,     0,   431,   769,     0,   432,   433,   434,    91,   435,
     436,   437,   438,     0,   440,   441,   442,   443,   444,   445,
       0,   446,     0,     0,   447,   448,   449,   450,     0,   451,
     769,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,     0,   645,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,     0,     0,     0,   264,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   288,   289,     0,   290,
     200,     0,   201,   202,   203,   204,   205,   206,   207,   208,
       0,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,     0,   220,     0,     0,     0,   291,   292,   293,
     294,   295,   296,   297,   221,     0,     0,     0,     0,     0,
       0,     0,   222,   223,   224,     0,   225,   226,   227,     0,
       0,   228,   229,   607,   230,     0,   231,   232,   233,   234,
       0,   235,   236,     0,   237,     0,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    28,    29,    30,    31,    38,    39,    40,     0,
       0,    25,    26,     0,     0,     0,     0,   117,   118,   119,
     120,   121,     0,   646,   648,  -318,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   658,     0,
       0,     0,     0,   660,   661,   662,     0,     0,   663,     0,
       0,   664,     0,     0,     0,     0,   665,     0,     0,   666,
     667,     0,     0,     0,     0,     0,     0,   668,     0,     0,
       0,   669,     0,     0,     0,   670,     0,     0,     0,     0,
       0,   671,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   695,
     677,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     678,     0,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    28,    29,    30,    31,    38,    39,    40,
      80,    81,    25,    26,     0,    82,   200,     0,   201,   202,
     203,   204,   205,   206,   207,   208,   738,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,     0,   220,
       0,     0,     0,   291,   292,   293,   294,   295,   296,   297,
     221,     0,     0,     0,     0,     0,     0,     0,   222,   223,
     224,     0,   225,   226,   227,     0,     0,   228,   229,   757,
     230,   758,   231,   232,   233,   234,     0,   235,   236,     0,
     237,     0,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    28,    29,
      30,    31,    38,    39,    40,   479,   480,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   264,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   117,   118,   119,   120,   121,     0,
       0,     0,     0,   184,   200,     0,   201,   202,   203,   204,
     205,   206,   207,   208,   122,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     0,   220,     0,   117,
     118,   119,   120,   121,     0,     0,     0,     0,   221,     0,
       0,     0,     0,     0,     0,     0,   222,   223,   224,   122,
     225,   226,   227,     0,     0,   228,   229,     0,   230,     0,
     231,   232,   233,   234,     0,   235,   236,     0,   237,     0,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,    39,    40,     0,     0,    25,    26,     0,     0,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      28,    29,    30,    31,    38,    39,    40,    80,    81,    25,
      26,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    28,    29,    30,    31,    38,
      39,    40,    80,    81,    25,    26,   264,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   288,   289,
       0,   290,   200,     0,   201,   202,   203,   204,   205,   206,
     207,   208,     0,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,     0,   220,     0,     0,     0,   291,
     292,   293,   294,   295,   296,   297,   221,     0,     0,     0,
       0,     0,     0,     0,   222,   223,   224,     0,   225,   226,
     227,     0,     0,   228,   229,     0,   230,     0,   231,   232,
     233,   234,     0,   235,   236,     0,   237,     0,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    28,    29,    30,    31,    38,    39,
      40,   264,     0,    25,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   200,     0,   201,
     202,   203,   204,   205,   206,   207,   208,     0,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,     0,
     220,     0,     0,     0,   291,   292,   293,   294,   295,   296,
     297,   221,     0,     0,     0,     0,     0,     0,     0,   222,
     223,   224,     0,   225,   226,   227,     0,     0,   228,   229,
       0,   230,     0,   231,   232,   233,   234,     0,   235,   236,
       0,   237,     0,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    28,
      29,    30,    31,    38,    39,    40,   678,     0,    25,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   200,     0,   201,   202,   203,   204,   205,   206,
     207,   208,     0,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,     0,   220,     0,     0,     0,   291,
     292,   293,   294,   295,   296,   297,   221,     0,     0,     0,
       0,     0,     0,     0,   222,   223,   224,     0,   225,   226,
     227,     0,     0,   228,   229,     0,   230,     0,   231,   232,
     233,   234,     0,   235,   236,     0,   237,     0,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    28,    29,    30,    31,    38,    39,
      40,   199,     0,    25,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   200,     0,   201,
     202,   203,   204,   205,   206,   207,   208,     0,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,     0,
     220,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   221,     0,     0,     0,     0,     0,     0,     0,   222,
     223,   224,     0,   225,   226,   227,     0,     0,   228,   229,
       0,   230,     0,   231,   232,   233,   234,     0,   235,   236,
       0,   237,     0,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   264,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    39,    40,     0,     0,    25,    26,
       0,     0,     0,     0,   200,     0,   201,   202,   203,   204,
     205,   206,   207,   208,     0,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     0,   220,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   221,     0,
       0,     0,     0,     0,     0,     0,   222,   223,   224,     0,
     225,   226,   227,     0,     0,   228,   229,     0,   230,     0,
     231,   232,   233,   234,     0,   235,   236,     0,   237,     0,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,    39,    40
  };

  /* YYCHECK.  */
  const short int
  MapSetParser::yycheck_[] =
  {
        11,   101,   183,    12,    13,    14,    15,    16,   187,   399,
     136,   208,   112,   392,   220,    41,   112,   187,    27,    92,
     625,   191,    28,   191,    44,   710,    51,    42,    44,    54,
      42,    55,   614,   140,    43,   382,   136,    24,    53,    53,
     136,    44,    51,   405,   406,    54,    42,    44,    44,    27,
      59,    45,    55,    45,   161,    16,   182,     0,    44,    53,
      20,    53,   424,   134,    25,    43,    69,    24,   753,    55,
     141,    17,   171,   172,   253,   665,   101,    42,   166,   669,
      21,    68,   182,   253,    41,    44,   182,   112,    33,    34,
     101,   100,   101,    55,   194,   265,    55,   265,   194,   681,
     173,   112,   105,   112,    56,    51,   115,    44,    54,    66,
      69,   136,    22,    23,    60,   140,    41,    51,    55,   105,
      54,   318,    41,   134,   149,   136,    25,   136,   139,   140,
     141,   140,    69,   167,   481,    57,   161,    42,   149,   153,
     149,   153,   166,   167,   168,   171,   172,   171,   172,   106,
     161,    55,   161,   500,   174,   101,    41,   182,   174,   166,
     166,   167,   168,   166,   167,   168,   112,    51,   105,   194,
      54,   182,   183,   182,   779,    48,   187,   174,   174,    42,
     166,   167,   168,   194,    12,   194,    14,    15,   134,    48,
     136,    66,    67,   139,   140,   141,   142,   162,   163,   164,
     165,   105,    44,   149,   166,   167,   168,   166,   167,   168,
     551,   552,   382,   419,   382,   161,    17,   101,    95,   165,
     557,   558,    17,    18,   162,   163,   164,   165,   112,   166,
     167,   168,    41,    57,   171,   172,   182,   183,    48,    17,
      35,   187,   253,   622,   634,   191,    41,    30,   194,   166,
     167,   168,   136,    35,    49,    50,   140,    52,    96,    29,
     285,    54,   166,   167,   168,   149,   412,   413,   414,   415,
     416,   417,   283,    53,   285,    79,   285,   161,   288,   289,
     290,   156,   157,   158,   159,   160,   161,    44,   166,   167,
     168,    44,   392,   171,   172,    44,   392,    44,   182,    44,
      44,    44,    44,    44,    44,    44,    44,   253,    44,    44,
     194,   481,    44,   481,    44,   483,    44,   174,   174,   265,
      44,    44,    44,    44,   335,   174,    44,   174,    44,    44,
     500,    44,   500,    44,    44,   130,    44,   283,    44,   285,
      44,    44,    44,   549,    44,    44,    26,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    36,    37,    38,    39,
      40,    44,    30,    42,    44,    41,    48,   392,   379,    44,
      44,   382,    44,    22,   399,    94,    56,   153,    45,   153,
      34,   392,    33,   392,   395,   396,    26,    58,   399,    45,
     399,    53,    45,    59,    71,    45,   407,    45,    53,    45,
      45,   285,    60,    61,    62,    63,    64,    65,   534,    53,
      53,    45,    70,    71,   804,    45,    53,    45,    45,    45,
      45,   618,    53,    45,    45,    44,   623,    45,    45,    53,
      45,    46,    47,    53,   534,   614,   382,    45,   534,    45,
      45,    45,    53,    45,   614,    45,   392,    45,    45,   395,
     396,    45,    53,   399,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    45,    13,    53,    45,    45,    45,    45,
     481,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    45,   174,    53,    44,   694,    45,    45,
      45,    43,   681,    68,    45,    42,    45,    45,   392,   534,
     691,   681,   107,    45,    54,   399,    45,    53,    45,    45,
      53,    45,   622,   534,    45,   534,   622,    46,    47,    45,
      45,    45,    94,    45,    45,   481,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   500,    80,   171,   172,    45,    45,
     153,    19,    51,   107,    54,    42,    60,    45,    53,    45,
     516,    45,   518,   519,    42,   740,   773,   738,   681,   165,
     615,   690,   388,   253,   265,   481,   391,   387,   534,   614,
     764,   504,   317,   672,   775,   283,   793,   622,   795,   395,
     285,   781,   516,   614,   706,   614,   539,   519,   669,   634,
     708,   622,   541,   622,   553,   422,   787,    -1,    -1,   422,
      -1,    -1,    -1,   634,    -1,   634,    -1,    -1,    -1,    -1,
      -1,    -1,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     534,    -1,   171,   172,    -1,    -1,   681,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   614,    -1,
     681,    -1,   681,    -1,    -1,    -1,   622,    -1,    -1,   625,
     691,   627,    -1,    -1,    -1,    -1,    -1,    -1,   634,    -1,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   737,   174,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   737,    -1,   737,    -1,
     614,    -1,    -1,   744,    -1,   681,    -1,    -1,   622,   764,
      -1,    -1,    -1,    -1,    -1,   691,    -1,    -1,    -1,    -1,
     634,    -1,    -1,   764,    -1,   764,    -1,    -1,    -1,    -1,
     706,    -1,   708,    -1,   775,    -1,    -1,    -1,    -1,    -1,
     781,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   804,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   737,   264,   804,    -1,   804,    -1,   681,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   764,    -1,
      -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   775,
      -1,    -1,    -1,   779,    -1,   781,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   319,   320,   321,
      -1,    -1,   324,   737,    -1,   327,   328,   329,   804,   331,
     332,   333,   334,    -1,   336,   337,   338,   339,   340,   341,
      -1,   343,    -1,    -1,   346,   347,   348,   349,    -1,   351,
     764,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     804,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    69,
      70,    -1,    72,    73,    74,    75,    76,    77,    78,    79,
      -1,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    -1,    93,    -1,    -1,    -1,    97,    98,    99,
     100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   113,   114,    -1,   116,   117,   118,    -1,
      -1,   121,   122,   475,   124,    -1,   126,   127,   128,   129,
      -1,   131,   132,    -1,   134,    -1,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
      -1,   171,   172,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    -1,   535,   536,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   560,    -1,
      -1,    -1,    -1,   565,   566,   567,    -1,    -1,   570,    -1,
      -1,   573,    -1,    -1,    -1,    -1,   578,    -1,    -1,   581,
     582,    -1,    -1,    -1,    -1,    -1,    -1,   589,    -1,    -1,
      -1,   593,    -1,    -1,    -1,   597,    -1,    -1,    -1,    -1,
      -1,   603,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   621,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    -1,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    70,    -1,    72,    73,
      74,    75,    76,    77,    78,    79,   678,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      -1,    -1,    -1,    97,    98,    99,   100,   101,   102,   103,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,
     114,    -1,   116,   117,   118,    -1,    -1,   121,   122,   721,
     124,   723,   126,   127,   128,   129,    -1,   131,   132,    -1,
     134,    -1,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    31,    32,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    45,    70,    -1,    72,    73,    74,    75,
      76,    77,    78,    79,    56,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    -1,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,   113,   114,    56,
     116,   117,   118,    -1,    -1,   121,   122,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,   132,    -1,   134,    -1,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     166,   167,   168,    -1,    -1,   171,   172,    -1,    -1,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    44,   174,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,
      -1,    69,    70,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    -1,    -1,    -1,    97,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,
     118,    -1,    -1,   121,   122,    -1,   124,    -1,   126,   127,
     128,   129,    -1,   131,   132,    -1,   134,    -1,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,    44,    -1,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
     113,   114,    -1,   116,   117,   118,    -1,    -1,   121,   122,
      -1,   124,    -1,   126,   127,   128,   129,    -1,   131,   132,
      -1,   134,    -1,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    44,    -1,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    -1,    -1,    -1,    97,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,
     118,    -1,    -1,   121,   122,    -1,   124,    -1,   126,   127,
     128,   129,    -1,   131,   132,    -1,   134,    -1,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,    44,    -1,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
     113,   114,    -1,   116,   117,   118,    -1,    -1,   121,   122,
      -1,   124,    -1,   126,   127,   128,   129,    -1,   131,   132,
      -1,   134,    -1,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   166,   167,   168,    -1,    -1,   171,   172,
      -1,    -1,    -1,    -1,    70,    -1,    72,    73,    74,    75,
      76,    77,    78,    79,    -1,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,   113,   114,    -1,
     116,   117,   118,    -1,    -1,   121,   122,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,   132,    -1,   134,    -1,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     166,   167,   168
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  MapSetParser::yystos_[] =
  {
         0,   176,   177,     0,    20,   193,   194,   196,   166,   178,
     195,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      13,   179,   180,    21,   197,   171,   172,   377,   162,   163,
     164,   165,   416,   425,   416,   416,   416,   416,   166,   167,
     168,   426,   427,    56,   185,   186,   191,    12,    14,    15,
     181,    41,   183,   184,    16,   213,   215,   216,   198,   416,
      92,   173,   417,   418,   419,   416,    41,   187,   188,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     169,   170,   174,   182,   378,   416,   420,   421,   422,   423,
     424,   426,   428,   183,   378,    25,   167,   416,   426,    57,
     190,    42,    41,   255,   199,    42,   189,   416,   375,   377,
     378,   256,   257,   214,   166,    48,    42,    36,    37,    38,
      39,    40,    56,   258,   266,   311,   367,   368,   370,   371,
     372,   375,   217,   416,   369,   261,    48,   267,   268,   313,
      44,   312,    27,    43,   218,   223,   224,    55,   314,   325,
     376,   377,   426,   260,   262,   263,   258,   314,   319,   320,
     367,   373,   374,   375,   314,    28,   219,   220,   221,   222,
     426,    95,   225,   226,   230,    41,   269,    57,   321,   324,
     374,    48,   259,    17,    45,   374,   222,    30,    35,   192,
     247,    96,   227,   233,   270,   318,   323,   258,   376,    44,
      70,    72,    73,    74,    75,    76,    77,    78,    79,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      93,   104,   112,   113,   114,   116,   117,   118,   121,   122,
     124,   126,   127,   128,   129,   131,   132,   134,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   231,   232,   303,   377,   402,   404,   406,
     407,   408,   426,   248,    44,   234,   235,   302,   303,   401,
     402,    29,   228,   236,   200,   201,   271,   272,   273,   276,
     326,   367,   375,    54,   317,    53,   322,   264,    66,    67,
      69,    97,    98,    99,   100,   101,   102,   103,   377,   379,
     380,   383,   386,   387,   390,   391,   397,   399,   400,   401,
     402,   409,   411,   414,   416,   420,   424,   426,    79,    44,
      44,    44,   174,   403,    44,   174,   309,    44,    44,    44,
     269,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,   309,    44,   174,   174,    44,    44,    44,    44,
     174,    44,   174,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,   232,    44,   174,   304,   249,
     379,   235,    30,    33,    34,   229,   242,   245,   246,   202,
      42,   275,    48,   277,   278,   328,   327,   315,   316,   325,
     324,    41,   400,   400,   400,    44,    44,    94,   207,   208,
     382,   385,    60,    61,    62,    63,    64,    65,    70,    71,
     388,   389,   396,   398,    44,   304,   415,   269,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   377,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,    22,   306,    41,   377,    45,    31,
      32,   237,   238,   239,   240,   241,   302,   377,   153,   153,
     243,   246,   244,   245,    26,   204,    17,    18,    49,    50,
      52,   130,   247,   274,   279,   280,   282,   286,   291,   292,
     295,   296,   301,   273,   320,   337,    44,    55,    69,   105,
     329,   331,   338,   339,   340,   341,   344,   347,   349,   355,
     356,   377,   426,   321,   265,   306,   306,   377,    45,    58,
     381,    59,   384,   390,   390,   390,   390,   390,   390,    71,
     309,    66,    67,   392,   395,   422,   423,    24,    68,   393,
     306,    45,    45,    45,   310,    53,    53,    53,    45,    45,
      53,    45,    45,    53,    45,    45,    45,    45,    53,    45,
      45,    53,    53,    45,    45,    45,    45,    45,    45,    53,
      45,    45,    45,    53,    45,    45,    45,    53,    45,    45,
      45,    45,    45,    53,    45,    45,    45,   379,   253,   238,
     401,    22,    23,   205,   206,   203,   283,   287,   281,   293,
     302,    44,   259,   297,   340,    44,    55,   105,   357,   362,
     363,   365,   426,   347,   330,   343,   346,    24,    41,    66,
     106,   348,   350,   354,   258,    24,   379,   410,   379,   383,
     386,   309,   397,   397,   393,   394,   399,   399,   379,   308,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   305,    42,    44,   174,   251,    24,    44,   209,
     210,   211,   212,   303,   377,   402,   409,   416,   420,   424,
     223,   284,   288,   269,   294,   379,   273,   269,    45,   360,
     361,   363,    55,   364,   426,   321,   107,   342,    68,   345,
      53,   153,   353,   366,    42,    45,    54,   412,   413,    45,
      45,    53,   307,    53,    45,    45,    45,    45,   307,   405,
      45,    45,    45,   405,    45,    45,   308,   252,   379,   210,
     225,   376,   289,   269,    94,   300,    45,   359,   336,   344,
     349,   366,    42,    53,   352,    80,    45,   379,   379,    45,
      45,    45,    46,    47,   250,   254,   377,   416,   420,   424,
     426,   208,   192,   285,    19,   290,   377,    51,   298,   107,
     358,    54,   335,    42,    42,   351,   366,    60,    45,    45,
     254,    45,   269,   376,    45,   299,   363,   331,   332,   334,
      42,   425,   269,   269,   333,   321
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
     187,   188,   189,   190,   190,   191,   192,   192,   193,   194,
     194,   195,   195,   196,   198,   199,   197,   201,   202,   203,
     200,   204,   205,   205,   206,   206,   207,   208,   208,   209,
     210,   210,   210,   210,   210,   210,   210,   210,   211,   211,
     212,   212,   214,   213,   215,   216,   216,   217,   217,   218,
     219,   219,   220,   221,   222,   223,   224,   224,   225,   226,
     226,   227,   227,   228,   228,   229,   229,   230,   231,   231,
     232,   232,   232,   232,   233,   234,   234,   235,   236,   237,
     237,   238,   238,   239,   239,   240,   241,   241,   242,   242,
     243,   243,   244,   244,   245,   246,   248,   247,   249,   249,
     250,   250,   252,   251,   251,   253,   253,   254,   254,   254,
     254,   254,   254,   254,   255,   257,   256,   258,   258,   259,
     259,   260,   261,   261,   263,   264,   265,   262,   266,   267,
     268,   268,   270,   269,   271,   271,   272,   273,   273,   274,
     275,   275,   276,   277,   278,   278,   279,   279,   279,   279,
     279,   279,   279,   279,   281,   280,   283,   284,   285,   282,
     287,   288,   289,   286,   290,   290,   291,   293,   294,   292,
     296,   297,   295,   299,   298,   300,   300,   301,   302,   302,
     302,   303,   304,   305,   304,   306,   306,   307,   308,   308,
     309,   310,   309,   312,   311,   313,   311,   314,   315,   316,
     316,   317,   318,   318,   319,   320,   320,   321,   322,   323,
     323,   324,   325,   325,   327,   326,   328,   326,   330,   329,
     331,   331,   333,   332,   334,   334,   335,   336,   336,   337,
     338,   339,   340,   341,   342,   343,   343,   344,   345,   346,
     346,   347,   348,   348,   349,   349,   350,   351,   351,   352,
     352,   353,   353,   354,   354,   354,   354,   355,   356,   356,
     356,   356,   357,   358,   359,   359,   360,   361,   361,   362,
     362,   363,   364,   364,   365,   365,   365,   366,   367,   367,
     369,   368,   370,   371,   371,   371,   371,   371,   372,   372,
     373,   373,   374,   374,   375,   375,   376,   376,   377,   377,
     378,   378,   378,   378,   378,   378,   379,   380,   381,   382,
     382,   383,   384,   385,   385,   386,   387,   388,   388,   389,
     389,   389,   389,   389,   389,   389,   389,   390,   391,   392,
     392,   393,   393,   394,   394,   395,   395,   395,   396,   396,
     397,   398,   398,   399,   399,   399,   399,   400,   400,   400,
     400,   400,   400,   400,   400,   401,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   402,   402,   403,
     403,   404,   405,   405,   406,   407,   408,   409,   409,   409,
     410,   410,   411,   411,   411,   411,   411,   412,   413,   413,
     414,   415,   415,   416,   417,   418,   418,   419,   419,   420,
     420,   420,   421,   421,   421,   422,   422,   422,   423,   423,
     423,   424,   424,   425,   425,   425,   425,   426,   426,   427,
     427,   428,   428
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  MapSetParser::yyr2_[] =
  {
         0,     2,     0,     4,     0,     2,     0,     2,     4,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     0,     1,     4,     1,     2,     2,     0,     1,     0,
       1,     3,     3,     0,     2,     3,     0,     1,     2,     0,
       1,     0,     2,     2,     0,     0,     5,     0,     0,     0,
       7,     3,     1,     1,     0,     1,     2,     0,     1,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     0,     8,     2,     0,     1,     0,     2,     2,
       1,     1,     1,     2,     1,     2,     0,     1,     4,     0,
       1,     0,     1,     0,     1,     0,     1,     3,     1,     2,
       1,     1,     4,     1,     2,     1,     2,     1,     3,     1,
       2,     1,     1,     1,     1,     2,     1,     1,     2,     2,
       0,     1,     0,     1,     2,     2,     0,     6,     0,     2,
       1,     2,     0,     4,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     0,     3,     0,     1,     0,
       1,     3,     0,     2,     0,     0,     0,     8,     2,     2,
       0,     1,     0,     4,     1,     1,     2,     0,     1,     3,
       0,     2,     2,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     3,     0,     0,     0,     6,
       0,     0,     0,     7,     0,     1,     6,     0,     0,     4,
       0,     0,     4,     0,     3,     0,     2,     2,     1,     1,
       1,     2,     1,     0,     6,     0,     1,     2,     0,     2,
       1,     0,     5,     0,     3,     0,     3,     3,     2,     0,
       1,     2,     0,     2,     1,     0,     1,     2,     2,     0,
       2,     1,     1,     1,     0,     3,     0,     3,     0,     4,
       1,     1,     0,     3,     0,     1,     2,     0,     2,     1,
       1,     1,     1,     2,     2,     0,     2,     2,     2,     0,
       2,     2,     0,     1,     1,     2,     1,     1,     2,     2,
       1,     2,     3,     1,     1,     1,     2,     1,     1,     1,
       2,     3,     1,     2,     0,     2,     2,     0,     1,     1,
       3,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       0,     4,     4,     1,     1,     1,     1,     1,     0,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     0,
       2,     2,     2,     0,     2,     1,     2,     0,     1,     2,
       2,     2,     2,     2,     2,     2,     3,     1,     2,     1,
       1,     2,     2,     0,     1,     2,     2,     2,     0,     2,
       2,     0,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     4,     4,     6,     4,
       4,     4,     4,     2,     2,     4,     4,     4,     4,     2,
       1,     4,     4,     4,     4,     6,     6,     6,     6,     6,
       4,     4,     4,     4,     4,     4,     4,     4,     2,     2,
       2,     4,     4,     4,     4,     4,     2,     8,     6,     6,
       6,     4,     4,     4,     4,     4,     1,     1,     1,     3,
       1,     7,     0,     1,     7,     2,     3,     5,     5,     6,
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
  "DefaultPrimaryKey", "_QBindingsClause_E_Opt", "Prologue",
  "_QBaseDecl_E_Opt", "_QPrefixDecl_E_Star", "BaseDecl", "PrefixDecl",
  "$@2", "$@3", "SubSelect", "@4", "@5", "@6", "SelectClause",
  "_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C",
  "_Q_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C_E_Opt", "_O_QIT_AS_E_S_QVar_E_C",
  "_Q_O_QIT_AS_E_S_QVar_E_C_E_Opt",
  "_O_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_Q_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C_E_Plus",
  "_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_Plus_Or_QGT_TIMES_E_C",
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
  "OffsetClause", "BindingsClause", "$@8", "_QVar_E_Star",
  "_QBindingValue_E_Plus",
  "_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C",
  "$@9",
  "_Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star",
  "BindingValue", "QuadPattern", "Quads", "$@10",
  "_QTriplesTemplate_E_Opt", "_QGT_DOT_E_Opt",
  "_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C_E_Star",
  "QuadsNotTriples", "@11", "@12", "$@13", "TriplesTemplate",
  "_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C_E_Opt", "GroupGraphPattern",
  "$@14", "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C",
  "GroupGraphPatternSub", "_QTriplesBlock_E_Opt",
  "_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "OptionalGraphPattern", "@15", "GraphGraphPattern", "@16", "@17", "@18",
  "ServiceGraphPattern", "@19", "@20", "@21", "_QIT_SILENT_E_Opt", "Bind",
  "MinusGraphPattern", "@22", "@23", "GroupOrUnionGraphPattern", "@24",
  "@25", "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@26",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "@27", "_QIT_DISTINCT_E_Opt",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ExpressionList", "@28",
  "TriplesSameSubject", "$@29", "$@30", "PropertyListNotEmpty",
  "_O_QVerb_E_S_QObjectList_E_C", "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "Verb", "TriplesSameSubjectPath", "$@31", "$@32",
  "PropertyListNotEmptyPath", "$@33", "_O_QVerbPath_E_Or_QVerbSimple_E_C",
  "_O_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_C", "$@34",
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
  "Integer", "TriplesNode", "BlankNodePropertyList", "@35", "Generator",
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
       176,     0,    -1,    -1,   177,   193,   178,   179,    -1,    -1,
     178,   180,    -1,    -1,   179,   213,    -1,     3,   377,   416,
     416,    -1,     4,   416,    -1,     5,   416,    -1,     6,   416,
      -1,     7,   416,    -1,     8,   416,    -1,     9,   426,    -1,
      10,   185,    -1,    11,   181,    -1,    13,   184,    -1,    12,
      -1,    15,    -1,    14,    -1,    -1,   378,    -1,    41,   182,
      42,   375,    -1,   183,    -1,   184,   183,    -1,   186,   187,
      -1,    -1,   191,    -1,    -1,   188,    -1,    41,   190,    42,
      -1,   416,    48,   416,    -1,    -1,   190,   189,    -1,    56,
     416,    57,    -1,    -1,   247,    -1,   194,   195,    -1,    -1,
     196,    -1,    -1,   195,   197,    -1,    20,   166,    -1,    -1,
      -1,    21,   198,   167,   199,   166,    -1,    -1,    -1,    -1,
     201,   202,   204,   203,   223,   225,   192,    -1,    26,   206,
     212,    -1,    22,    -1,    23,    -1,    -1,   205,    -1,    94,
     377,    -1,    -1,   207,    -1,    44,   379,   208,    45,    -1,
     377,    -1,   409,    -1,   402,    -1,   303,    -1,   416,    -1,
     420,    -1,   424,    -1,   209,    -1,   210,    -1,   211,   210,
      -1,   211,    -1,    24,    -1,    -1,   216,    25,   255,   214,
     217,   223,   225,   192,    -1,    16,   378,    -1,    -1,   215,
      -1,    -1,   217,   218,    -1,    27,   219,    -1,   220,    -1,
     221,    -1,   222,    -1,    28,   222,    -1,   426,    -1,   224,
     269,    -1,    -1,    43,    -1,   226,   227,   228,   229,    -1,
      -1,   230,    -1,    -1,   233,    -1,    -1,   236,    -1,    -1,
     242,    -1,    95,    30,   231,    -1,   232,    -1,   231,   232,
      -1,   402,    -1,   303,    -1,    44,   379,   208,    45,    -1,
     377,    -1,    96,   234,    -1,   235,    -1,   234,   235,    -1,
     302,    -1,    29,    30,   237,    -1,   238,    -1,   237,   238,
      -1,   240,    -1,   241,    -1,    31,    -1,    32,    -1,   239,
     401,    -1,   302,    -1,   377,    -1,   245,   243,    -1,   246,
     244,    -1,    -1,   246,    -1,    -1,   245,    -1,    33,   153,
      -1,    34,   153,    -1,    -1,    35,   248,   249,    41,   253,
      42,    -1,    -1,   249,   377,    -1,   254,    -1,   250,   254,
      -1,    -1,    44,   252,   250,    45,    -1,   174,    -1,    -1,
     253,   251,    -1,   426,    -1,   416,    -1,   420,    -1,   424,
      -1,    46,    -1,    47,    -1,   377,    -1,    41,   256,    42,
      -1,    -1,   257,   258,   261,    -1,    -1,   266,    -1,    -1,
      48,    -1,   262,   259,   258,    -1,    -1,   261,   260,    -1,
      -1,    -1,    -1,   263,    17,   376,   264,    41,   265,   258,
      42,    -1,   311,   268,    -1,    48,   258,    -1,    -1,   267,
      -1,    -1,    41,   270,   271,    42,    -1,   200,    -1,   272,
      -1,   273,   275,    -1,    -1,   276,    -1,   279,   259,   273,
      -1,    -1,   275,   274,    -1,   326,   278,    -1,    48,   273,
      -1,    -1,   277,    -1,   295,    -1,   280,    -1,   292,    -1,
     282,    -1,   286,    -1,   301,    -1,   291,    -1,   247,    -1,
      -1,    49,   281,   269,    -1,    -1,    -1,    -1,    17,   283,
     284,   376,   285,   269,    -1,    -1,    -1,    -1,    18,   287,
     288,   289,   290,   376,   269,    -1,    -1,    19,    -1,   130,
      44,   379,    94,   377,    45,    -1,    -1,    -1,    50,   293,
     294,   269,    -1,    -1,    -1,   296,   297,   269,   300,    -1,
      -1,    51,   299,   269,    -1,    -1,   300,   298,    -1,    52,
     302,    -1,   401,    -1,   402,    -1,   303,    -1,   426,   304,
      -1,   174,    -1,    -1,    44,   306,   379,   305,   308,    45,
      -1,    -1,    22,    -1,    53,   379,    -1,    -1,   308,   307,
      -1,   174,    -1,    -1,    44,   379,   310,   308,    45,    -1,
      -1,   375,   312,   314,    -1,    -1,   367,   313,   319,    -1,
     325,   321,   318,    -1,   325,   321,    -1,    -1,   315,    -1,
      54,   316,    -1,    -1,   318,   317,    -1,   320,    -1,    -1,
     314,    -1,   324,   323,    -1,    53,   324,    -1,    -1,   323,
     322,    -1,   374,    -1,   376,    -1,    55,    -1,    -1,   375,
     327,   329,    -1,    -1,   367,   328,   337,    -1,    -1,   331,
     330,   321,   336,    -1,   338,    -1,   339,    -1,    -1,   331,
     333,   321,    -1,    -1,   332,    -1,    54,   334,    -1,    -1,
     336,   335,    -1,   320,    -1,   340,    -1,   377,    -1,   341,
      -1,   344,   343,    -1,   107,   344,    -1,    -1,   343,   342,
      -1,   349,   346,    -1,    68,   349,    -1,    -1,   346,   345,
      -1,   355,   348,    -1,    -1,   350,    -1,   347,    -1,   105,
     347,    -1,   354,    -1,    42,    -1,   366,    42,    -1,    53,
     351,    -1,    42,    -1,   366,   352,    -1,    53,   366,    42,
      -1,    24,    -1,   106,    -1,    66,    -1,    41,   353,    -1,
     356,    -1,   426,    -1,    55,    -1,    69,   357,    -1,    44,
     340,    45,    -1,   362,    -1,   107,   363,    -1,    -1,   359,
     358,    -1,   363,   359,    -1,    -1,   360,    -1,   363,    -1,
      44,   361,    45,    -1,   365,    -1,   426,    -1,    55,    -1,
     426,    -1,    55,    -1,   105,   364,    -1,   153,    -1,   370,
      -1,   368,    -1,    -1,    56,   369,   314,    57,    -1,   372,
      44,   373,    45,    -1,    36,    -1,    37,    -1,    38,    -1,
      39,    -1,    40,    -1,    -1,   371,    -1,   374,    -1,   373,
     374,    -1,   375,    -1,   367,    -1,   377,    -1,   378,    -1,
     377,    -1,   426,    -1,   171,    -1,   172,    -1,   426,    -1,
     416,    -1,   420,    -1,   424,    -1,   428,    -1,   174,    -1,
     380,    -1,   383,   382,    -1,    58,   383,    -1,    -1,   382,
     381,    -1,   386,   385,    -1,    59,   386,    -1,    -1,   385,
     384,    -1,   387,    -1,   390,   388,    -1,    -1,   389,    -1,
      60,   390,    -1,    61,   390,    -1,    62,   390,    -1,    63,
     390,    -1,    64,   390,    -1,    65,   390,    -1,    71,   309,
      -1,    70,    71,   309,    -1,   391,    -1,   397,   396,    -1,
     422,    -1,   423,    -1,    24,   399,    -1,    68,   399,    -1,
      -1,   393,    -1,    66,   397,    -1,    67,   397,    -1,   392,
     394,    -1,    -1,   396,   395,    -1,   399,   398,    -1,    -1,
     398,   393,    -1,    69,   400,    -1,    66,   400,    -1,    67,
     400,    -1,   400,    -1,   401,    -1,   402,    -1,   414,    -1,
     416,    -1,   420,    -1,   424,    -1,   377,    -1,   409,    -1,
      44,   379,    45,    -1,    81,    44,   379,    45,    -1,    82,
      44,   379,    45,    -1,    83,    44,   379,    53,   379,    45,
      -1,    84,    44,   379,    45,    -1,    85,    44,   377,    45,
      -1,    72,    44,   379,    45,    -1,    73,    44,   379,    45,
      -1,    74,   403,    -1,   121,   174,    -1,   145,    44,   379,
      45,    -1,   142,    44,   379,    45,    -1,   134,    44,   379,
      45,    -1,   128,    44,   379,    45,    -1,    93,   309,    -1,
     406,    -1,   148,    44,   379,    45,    -1,   146,    44,   379,
      45,    -1,   144,    44,   379,    45,    -1,   140,    44,   379,
      45,    -1,   131,    44,   379,    53,   379,    45,    -1,   141,
      44,   379,    53,   379,    45,    -1,   147,    44,   379,    53,
     379,    45,    -1,   116,    44,   379,    53,   379,    45,    -1,
     117,    44,   379,    53,   379,    45,    -1,   118,    44,   379,
      45,    -1,   150,    44,   379,    45,    -1,   143,    44,   379,
      45,    -1,   139,    44,   379,    45,    -1,   136,    44,   379,
      45,    -1,   132,    44,   379,    45,    -1,   127,    44,   379,
      45,    -1,   126,    44,   379,    45,    -1,   124,   174,    -1,
     112,   174,    -1,   113,   174,    -1,   114,    44,   379,    45,
      -1,   149,    44,   379,    45,    -1,   138,    44,   379,    45,
      -1,   129,    44,   379,    45,    -1,   122,    44,   379,    45,
      -1,    75,   309,    -1,    76,    44,   379,    53,   379,    53,
     379,    45,    -1,    77,    44,   379,    53,   379,    45,    -1,
      78,    44,   379,    53,   379,    45,    -1,    86,    44,   379,
      53,   379,    45,    -1,    87,    44,   379,    45,    -1,    88,
      44,   379,    45,    -1,    89,    44,   379,    45,    -1,    90,
      44,   379,    45,    -1,   104,    44,   379,    45,    -1,   404,
      -1,   407,    -1,   408,    -1,    44,   379,    45,    -1,   174,
      -1,    91,    44,   379,    53,   379,   405,    45,    -1,    -1,
     307,    -1,   137,    44,   379,    53,   379,   405,    45,    -1,
      79,   269,    -1,    70,    79,   269,    -1,    97,    44,   306,
     410,    45,    -1,   411,    44,   306,   379,    45,    -1,   102,
      44,   306,   379,   413,    45,    -1,    24,    -1,   379,    -1,
      98,    -1,    99,    -1,   100,    -1,   101,    -1,   103,    -1,
      54,    80,    60,   425,    -1,    -1,   412,    -1,   426,   415,
      -1,    -1,   304,    -1,   425,   419,    -1,    92,   426,    -1,
     173,    -1,   417,    -1,    -1,   418,    -1,   421,    -1,   422,
      -1,   423,    -1,   153,    -1,   154,    -1,   155,    -1,   156,
      -1,   157,    -1,   158,    -1,   159,    -1,   160,    -1,   161,
      -1,   151,    -1,   152,    -1,   162,    -1,   164,    -1,   163,
      -1,   165,    -1,   166,    -1,   427,    -1,   168,    -1,   167,
      -1,   169,    -1,   170,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  MapSetParser::yyprhs_[] =
  {
         0,     0,     3,     4,     9,    10,    13,    14,    17,    22,
      25,    28,    31,    34,    37,    40,    43,    46,    49,    51,
      53,    55,    56,    58,    63,    65,    68,    71,    72,    74,
      75,    77,    81,    85,    86,    89,    93,    94,    96,    99,
     100,   102,   103,   106,   109,   110,   111,   117,   118,   119,
     120,   128,   132,   134,   136,   137,   139,   142,   143,   145,
     150,   152,   154,   156,   158,   160,   162,   164,   166,   168,
     171,   173,   175,   176,   185,   188,   189,   191,   192,   195,
     198,   200,   202,   204,   207,   209,   212,   213,   215,   220,
     221,   223,   224,   226,   227,   229,   230,   232,   236,   238,
     241,   243,   245,   250,   252,   255,   257,   260,   262,   266,
     268,   271,   273,   275,   277,   279,   282,   284,   286,   289,
     292,   293,   295,   296,   298,   301,   304,   305,   312,   313,
     316,   318,   321,   322,   327,   329,   330,   333,   335,   337,
     339,   341,   343,   345,   347,   351,   352,   356,   357,   359,
     360,   362,   366,   367,   370,   371,   372,   373,   382,   385,
     388,   389,   391,   392,   397,   399,   401,   404,   405,   407,
     411,   412,   415,   418,   421,   422,   424,   426,   428,   430,
     432,   434,   436,   438,   440,   441,   445,   446,   447,   448,
     455,   456,   457,   458,   466,   467,   469,   476,   477,   478,
     483,   484,   485,   490,   491,   495,   496,   499,   502,   504,
     506,   508,   511,   513,   514,   521,   522,   524,   527,   528,
     531,   533,   534,   540,   541,   545,   546,   550,   554,   557,
     558,   560,   563,   564,   567,   569,   570,   572,   575,   578,
     579,   582,   584,   586,   588,   589,   593,   594,   598,   599,
     604,   606,   608,   609,   613,   614,   616,   619,   620,   623,
     625,   627,   629,   631,   634,   637,   638,   641,   644,   647,
     648,   651,   654,   655,   657,   659,   662,   664,   666,   669,
     672,   674,   677,   681,   683,   685,   687,   690,   692,   694,
     696,   699,   703,   705,   708,   709,   712,   715,   716,   718,
     720,   724,   726,   728,   730,   732,   734,   737,   739,   741,
     743,   744,   749,   754,   756,   758,   760,   762,   764,   765,
     767,   769,   772,   774,   776,   778,   780,   782,   784,   786,
     788,   790,   792,   794,   796,   798,   800,   802,   805,   808,
     809,   812,   815,   818,   819,   822,   824,   827,   828,   830,
     833,   836,   839,   842,   845,   848,   851,   855,   857,   860,
     862,   864,   867,   870,   871,   873,   876,   879,   882,   883,
     886,   889,   890,   893,   896,   899,   902,   904,   906,   908,
     910,   912,   914,   916,   918,   920,   924,   929,   934,   941,
     946,   951,   956,   961,   964,   967,   972,   977,   982,   987,
     990,   992,   997,  1002,  1007,  1012,  1019,  1026,  1033,  1040,
    1047,  1052,  1057,  1062,  1067,  1072,  1077,  1082,  1087,  1090,
    1093,  1096,  1101,  1106,  1111,  1116,  1121,  1124,  1133,  1140,
    1147,  1154,  1159,  1164,  1169,  1174,  1179,  1181,  1183,  1185,
    1189,  1191,  1199,  1200,  1202,  1210,  1213,  1217,  1223,  1229,
    1236,  1238,  1240,  1242,  1244,  1246,  1248,  1250,  1255,  1256,
    1258,  1261,  1262,  1264,  1267,  1270,  1272,  1274,  1275,  1277,
    1279,  1281,  1283,  1285,  1287,  1289,  1291,  1293,  1295,  1297,
    1299,  1301,  1303,  1305,  1307,  1309,  1311,  1313,  1315,  1317,
    1319,  1321,  1323
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  MapSetParser::yyrline_[] =
  {
         0,   460,   460,   460,   466,   468,   472,   474,   478,   487,
     490,   493,   496,   499,   502,   505,   507,   511,   517,   520,
     523,   529,   532,   536,   548,   549,   553,   556,   558,   561,
     563,   567,   571,   576,   578,   582,   589,   592,   597,   601,
     603,   607,   609,   613,   619,   621,   619,   631,   634,   637,
     631,   652,   660,   663,   670,   673,   678,   685,   688,   693,
     700,   703,   706,   709,   712,   715,   718,   722,   727,   730,
     738,   741,   748,   748,   760,   766,   769,   774,   777,   785,
     792,   793,   797,   803,   809,   816,   823,   825,   830,   837,
     840,   845,   848,   853,   856,   861,   865,   869,   876,   879,
     886,   889,   892,   895,   901,   907,   910,   917,   922,   929,
     933,   941,   943,   951,   954,   962,   970,   971,   978,   982,
     990,   993,   998,  1001,  1005,  1011,  1018,  1018,  1026,  1028,
    1034,  1037,  1043,  1043,  1048,  1054,  1056,  1060,  1063,  1066,
    1069,  1072,  1075,  1078,  1084,  1090,  1090,  1098,  1100,  1104,
    1106,  1110,  1113,  1115,  1120,  1125,  1128,  1120,  1139,  1143,
    1146,  1148,  1153,  1153,  1164,  1165,  1170,  1174,  1176,  1186,
    1190,  1193,  1209,  1214,  1218,  1221,  1225,  1226,  1227,  1228,
    1229,  1230,  1231,  1232,  1238,  1238,  1254,  1258,  1260,  1254,
    1271,  1275,  1277,  1271,  1288,  1291,  1297,  1308,  1312,  1308,
    1322,  1326,  1322,  1336,  1336,  1348,  1350,  1354,  1364,  1365,
    1366,  1370,  1378,  1382,  1382,  1392,  1395,  1402,  1408,  1410,
    1424,  1427,  1427,  1437,  1437,  1440,  1440,  1447,  1452,  1456,
    1458,  1463,  1467,  1469,  1474,  1478,  1480,  1485,  1490,  1494,
    1496,  1500,  1507,  1511,  1519,  1519,  1522,  1522,  1528,  1528,
    1534,  1535,  1539,  1539,  1544,  1546,  1550,  1553,  1555,  1559,
    1563,  1567,  1573,  1577,  1581,  1584,  1586,  1590,  1594,  1599,
    1601,  1607,  1610,  1612,  1618,  1619,  1625,  1629,  1630,  1634,
    1635,  1639,  1640,  1644,  1645,  1646,  1647,  1651,  1655,  1658,
    1661,  1664,  1670,  1674,  1677,  1679,  1683,  1686,  1688,  1692,
    1693,  1697,  1701,  1702,  1706,  1707,  1708,  1712,  1717,  1718,
    1722,  1722,  1735,  1760,  1763,  1766,  1769,  1772,  1779,  1782,
    1787,  1791,  1798,  1799,  1803,  1806,  1810,  1813,  1819,  1820,
    1824,  1827,  1830,  1833,  1836,  1837,  1843,  1848,  1857,  1864,
    1867,  1875,  1884,  1891,  1894,  1901,  1906,  1919,  1923,  1927,
    1931,  1935,  1939,  1943,  1947,  1951,  1955,  1962,  1967,  1976,
    1979,  1986,  1989,  1996,  1999,  2004,  2007,  2011,  2025,  2028,
    2036,  2045,  2048,  2055,  2058,  2061,  2064,  2068,  2069,  2070,
    2071,  2074,  2077,  2080,  2083,  2087,  2093,  2096,  2099,  2102,
    2105,  2108,  2111,  2115,  2118,  2121,  2124,  2127,  2130,  2133,
    2136,  2137,  2140,  2143,  2146,  2149,  2152,  2155,  2158,  2161,
    2164,  2167,  2170,  2173,  2176,  2179,  2182,  2185,  2188,  2191,
    2194,  2197,  2200,  2203,  2206,  2209,  2212,  2215,  2218,  2221,
    2224,  2227,  2230,  2233,  2236,  2239,  2242,  2243,  2244,  2250,
    2253,  2260,  2267,  2270,  2274,  2280,  2287,  2294,  2298,  2303,
    2314,  2317,  2321,  2324,  2327,  2330,  2333,  2339,  2345,  2348,
    2352,  2362,  2365,  2370,  2378,  2385,  2389,  2397,  2401,  2405,
    2406,  2407,  2411,  2412,  2413,  2417,  2418,  2419,  2423,  2424,
    2425,  2429,  2430,  2434,  2435,  2436,  2437,  2441,  2442,  2446,
    2447,  2451,  2452
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
  const int MapSetParser::yylast_ = 2102;
  const int MapSetParser::yynnts_ = 254;
  const int MapSetParser::yyempty_ = -2;
  const int MapSetParser::yyfinal_ = 3;
  const int MapSetParser::yyterror_ = 1;
  const int MapSetParser::yyerrcode_ = 256;
  const int MapSetParser::yyntokens_ = 175;

  const unsigned int MapSetParser::yyuser_token_number_max_ = 429;
  const MapSetParser::token_number_type MapSetParser::yyundef_token_ = 2;


} // w3c_sw

/* Line 1136 of lalr1.cc  */
#line 4975 "lib/MapSetParser/MapSetParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 2458 "lib/MapSetParser/MapSetParser.ypp"
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


