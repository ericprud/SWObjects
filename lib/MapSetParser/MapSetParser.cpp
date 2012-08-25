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
	Construct* constr = new Construct((yysemantic_stack_[(8) - (3)].p_TableOperation), (yysemantic_stack_[(8) - (5)].p_DatasetClauses), (yysemantic_stack_[(8) - (6)].p_WhereClause), (yysemantic_stack_[(8) - (7)].p_SolutionModifier));
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
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1087 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1093 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1099 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1101 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TableOperation) = driver.ensureGraphPattern();
	  driver.curOp = NULL;
      }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1129 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1134 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1137 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1140 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1162 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1164 "lib/MapSetParser/MapSetParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1241 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_BindingClause)) : (yysemantic_stack_[(1) - (1)].p_BindingClause);
    }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1247 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1251 "lib/MapSetParser/MapSetParser.ypp"
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

  case 188:

/* Line 690 of lalr1.cc  */
#line 1263 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1267 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1269 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1272 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1280 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1284 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1286 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1289 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(7) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(7) - (6)].p_TTerm), driver.curOp, (yysemantic_stack_[(7) - (5)].p_Silence), driver.atomFactory, false));
	  driver.curGraphName = (yysemantic_stack_[(7) - (4)].p_TTerm);
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
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
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

  case 237:

/* Line 690 of lalr1.cc  */
#line 1484 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 1488 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 1511 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
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
	} else if ((yysemantic_stack_[(4) - (1)].p_listModifier) == LIST_members) {
	    (yyval.p_TTerm) = new Members((yysemantic_stack_[(4) - (3)].p_TTerms));
	} else {
	    error((yyloc), "unsupported function");
	}
    }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 1762 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 1765 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 1768 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 1771 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 1774 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 1781 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 1789 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 1793 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 1805 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 1812 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 1815 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 1826 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 1829 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 1832 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 1835 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 1839 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 1850 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 1859 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 1866 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 1869 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 1877 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 1886 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 1893 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 1896 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 1908 "lib/MapSetParser/MapSetParser.ypp"
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
#line 1921 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = NULL;
    }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 1929 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 1933 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 1937 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 1941 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 1945 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 1949 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 1953 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 1957 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = true;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 1969 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 1978 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 1981 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 1988 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 1991 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 1998 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 2006 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 2009 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 2013 "lib/MapSetParser/MapSetParser.ypp"
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
#line 2027 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 2030 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 2038 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 2047 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 2050 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 2057 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 2060 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 2063 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 2073 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 2076 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 2079 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 2082 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 2089 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 2095 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 2098 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 2101 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 2104 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 2107 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 2110 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 2113 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 2117 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 2120 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 2123 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 2126 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ceil, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 2129 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 2132 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 2135 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 2139 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 2142 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 2145 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 2148 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 2151 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 2154 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 2157 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 2160 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 2163 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 2166 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 2169 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 2172 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 2175 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 2178 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 2181 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 2184 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 2187 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 2190 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 2193 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_uuid, NULL, NULL, NULL));
    }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 2196 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_struuid, NULL, NULL, NULL));
    }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 2199 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 2202 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 2205 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 2208 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 2211 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 2214 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 2217 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 2220 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 2223 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 2226 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 2229 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 2232 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 2235 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 2238 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 2241 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 2252 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 2255 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 2262 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 2269 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 2276 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 2282 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 2285 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 2288 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 2292 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_Expression) = new ExistsExpression(driver.ensureGraphPattern());
	  driver.curOp = (yysemantic_stack_[(5) - (4)].p_TableOperation);
	  driver.curGraphName = (yysemantic_stack_[(5) - (3)].p_TTerm);
	  driver.countStar = (yysemantic_stack_[(5) - (2)].p_parentCountStar);
      }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 2301 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 2304 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 2307 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 2311 "lib/MapSetParser/MapSetParser.ypp"
    {
	  // $$ = new ExistsExpression(false, driver.ensureGraphPattern());
	  (yyval.p_Expression) = new BooleanNegation(new ExistsExpression(driver.ensureGraphPattern()));
	  driver.curOp = (yysemantic_stack_[(6) - (5)].p_TableOperation);
	  driver.curGraphName = (yysemantic_stack_[(6) - (4)].p_TTerm);
	  driver.countStar = (yysemantic_stack_[(6) - (3)].p_parentCountStar);
      }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 2321 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 2325 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 2330 "lib/MapSetParser/MapSetParser.ypp"
    {
	  AggregateCall::ScalarVals svals;
	  if ((yysemantic_stack_[(6) - (5)].p_RDFLiteral) != NULL)
	      svals["separator"] = (yysemantic_stack_[(6) - (5)].p_RDFLiteral)->getLexicalValue();
	  (yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression), svals));
    }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 2339 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 2346 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 2349 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 2352 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 2355 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 2358 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 2364 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 2370 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 2377 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 2387 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 2395 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 2403 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 2410 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 2414 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 2422 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 690 of lalr1.cc  */
#line 3339 "lib/MapSetParser/MapSetParser.cpp"
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
  const short int MapSetParser::yypact_ninf_ = -664;
  const short int
  MapSetParser::yypact_[] =
  {
      -664,    43,    11,  -664,  -113,  -664,  -664,  -664,  -664,   418,
      41,   -98,   168,   168,   168,   168,   168,    64,     8,   106,
      47,    35,  -664,  -664,  -664,  -664,  -664,   168,  -664,  -664,
    -664,  -664,  -664,   -54,  -664,  -664,  -664,  -664,  -664,  -664,
    -664,  -664,  -664,   168,  -664,    59,  -664,  -664,  -664,  -664,
    -664,   652,  -664,    47,   652,  -664,  -664,    69,   -85,   168,
      64,  -664,  -664,  -664,  -664,    45,  -664,  -664,  -664,  -664,
    -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,
    -664,  -664,  -664,    62,  -664,  -664,  -664,  -664,  -664,  -664,
    -664,  -664,  -664,  -664,  -664,    72,  -664,  -664,  -664,  -664,
      42,   926,  -664,  -664,   -40,  -664,  -664,    89,  -664,  -664,
    -664,   102,   541,  -664,  -664,   168,  -664,  -664,  -664,  -664,
    -664,  -664,  -664,  -664,  -664,   108,  -664,  -664,  -664,  -664,
     119,  -664,    14,  -664,    90,   137,   541,  -664,  -664,    90,
    1288,    90,    -8,  -664,  -664,    70,   127,  -664,   120,  1288,
    -664,  -664,  -664,  -664,   136,   172,  -664,  -664,  -664,  -664,
    -664,  1253,  -664,  -664,  -664,    64,  -664,  -664,  -664,  -664,
    -664,   161,   157,   112,  -664,  -664,  -664,  -664,  -664,  -664,
    -664,  -664,   541,    46,  -664,  -664,  -664,  1792,  -664,  -664,
    -664,  1917,   187,  -664,   321,   166,   173,  -664,  -664,  1417,
     142,   184,   190,   -28,   -27,   191,   194,   195,  -664,   199,
     205,   207,   208,   219,   220,   221,   224,   225,   226,   229,
     -27,   239,   111,   117,   245,   250,   252,   253,   128,   259,
     132,   264,   265,   267,   278,   279,   281,   282,   284,   290,
     291,   294,   300,   301,   304,   305,   306,   310,   311,   312,
     318,   319,   320,  1792,  -664,  -664,  -664,  -664,  -664,  -664,
    -664,  -664,   -23,  -664,  1417,  1917,  -664,  -664,  -664,  -664,
    -664,   263,   115,  -664,  -664,  -664,   324,  -664,  -664,  -664,
     322,  -664,  -664,    90,  -664,  1288,  -664,   328,  1542,  1542,
    1542,   329,  -664,  -664,  -664,  -664,   331,  -664,  -664,   286,
    -664,  -664,  -664,  -664,   217,  -664,  -664,  -664,  -664,  -664,
    -664,  -664,   332,  -664,  -664,  -664,  -664,   -23,  -664,  1417,
    1417,  1417,  -664,  -664,  1417,  -664,  -664,  1417,  1417,  1417,
    -664,  1417,  1417,  1417,  1417,   -98,  1417,  1417,  1417,  1417,
    1417,  1417,  -664,  1417,  -664,  -664,  1417,  1417,  1417,  1417,
    -664,  1417,  -664,  1417,  1417,  1417,  1417,  1417,  1417,  1417,
    1417,  1417,  1417,  1417,  1417,  1417,  1417,  1417,  1417,  1417,
    1417,  1417,  1417,  1417,  1417,  -664,   350,  -664,  -664,   -29,
     333,  -664,  1229,   233,   234,  -664,  -664,   348,   356,   365,
    -664,   249,   541,  -664,  -664,    90,   231,  -664,  -664,  1288,
    -664,  -664,  -664,  -664,  -664,   350,   350,   -98,  -664,   347,
     335,   341,  1417,  1417,  1417,  1417,  1417,  1417,   323,   -27,
    -664,  -664,   254,     4,   350,  -664,  -664,  -664,   359,   360,
     361,  -664,   355,   363,   364,  -664,   373,   374,   377,   388,
     389,   382,   392,   394,   395,   396,   390,   397,   399,   398,
     401,   400,   402,   407,   410,   411,   412,   405,   414,   415,
     416,   413,   419,   420,   422,   417,   423,   424,   449,   451,
     452,   445,   454,   455,   458,  -664,  1417,  -664,  -664,  -664,
    -664,  -664,  1229,  -664,   357,  -664,  -664,  -664,  -664,  -664,
    -664,  -664,  -664,  -664,  -664,   152,  -664,  -664,  -664,  -664,
    -664,  1917,   460,  -664,  -664,   136,  -664,  -664,  -664,  -664,
    -664,  -664,  -664,  -664,  -664,  -664,  -664,    12,  -664,    34,
     185,  -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,
       3,  -664,  -664,  -664,  -664,   541,   889,  1417,  -664,  -664,
    1417,  -664,  1417,  -664,  -664,  -664,  -664,  -664,  -664,  -664,
     -27,  -664,  1417,  1417,     4,  -664,  -664,  -664,  1417,  1417,
    -664,  1417,  -664,  -664,  -664,  -664,  -664,  1417,  1417,  1417,
     127,  -664,  -664,  1417,  -664,  -664,  1417,  -664,  -664,  -664,
    -664,  1417,  -664,  -664,  1417,  1417,  -664,  -664,  -664,  -664,
    -664,  -664,  1417,  -664,  -664,  -664,  1417,  -664,  -664,  -664,
    1417,  -664,  -664,  -664,  -664,  -664,  1417,  -664,  -664,  -664,
    -664,    -7,  -664,  -664,  -664,  -664,  -664,  1091,   366,  -664,
    -664,   127,  -664,  -664,  1417,   541,   127,   461,    57,  -664,
      31,  -664,  -664,  -664,  -664,  -664,  -664,  1288,   404,   437,
    -664,   -20,  -664,  -664,  -664,  -664,  -664,   421,  -664,  -664,
     462,   459,  -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,
    -664,   463,   127,    10,   464,   467,   470,  -664,   471,   473,
     466,   475,   476,   477,   466,   478,   480,  -664,  -664,  -664,
    -664,  -664,  -664,  1417,  -664,  -664,  1667,  -664,  -664,  -664,
    -664,  -664,  -664,  -664,  -664,    70,    46,  -664,  -664,   127,
     433,  -664,  -664,  -664,  -664,   484,  -664,  -664,  -664,  -664,
    -664,    12,  -664,    12,  -664,   379,  -664,  -664,     6,  -664,
    -664,   450,  -664,   488,  -664,  -664,  -664,  1417,  -664,  1417,
    -664,  -664,  -664,  -664,  -664,   489,  -664,  -664,  -664,   490,
    -664,  -664,    13,  1814,   286,  -664,   157,  -664,   518,  -664,
     -98,   491,  -664,   432,   486,  -664,  -664,   499,  -664,   -19,
    -664,   483,  -664,  -664,   500,  -664,  -664,  -664,  -664,  -664,
    1564,  -664,  -664,  -664,  -664,  -664,  -664,   501,  -664,   127,
    -664,    46,   502,  -664,  -664,    57,  -664,   231,  -664,  -664,
    -664,  -664,   506,   168,  -664,  -664,  -664,  -664,  -664,   127,
    -664,   127,  -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,
    1288,  -664
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  MapSetParser::yydefact_[] =
  {
         2,     0,    39,     1,     0,     4,    41,    40,    43,     6,
      38,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     3,     5,    44,    42,   328,   329,     0,   489,   491,
     490,   492,     9,   473,    10,    11,    12,    13,   493,   496,
     495,    14,   494,     0,    15,    29,    28,    18,    20,    19,
      16,    21,    24,    17,     0,     7,    76,     0,     0,     0,
       0,   471,   472,   474,   469,     0,    33,    26,    30,   487,
     488,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     497,   498,   335,     0,    22,   331,   332,   475,   476,   477,
     333,   330,   334,    25,    74,     0,    45,     8,   470,    35,
       0,     0,   147,    72,     0,    31,    34,     0,    23,   324,
     325,     0,   149,    77,    46,     0,   146,   313,   314,   315,
     316,   317,   310,   154,   150,   162,   225,   309,   308,   319,
       0,   223,    86,    32,     0,   148,   149,   163,   160,   235,
     318,     0,     0,    87,    78,    89,     0,   238,     0,   318,
     237,   326,   327,   155,   151,     0,   161,   236,   226,   234,
     323,   318,   320,   322,   224,     0,    79,    80,    81,    82,
      84,     0,    36,    91,    90,   164,    85,   311,   232,   241,
     243,   152,   149,     0,   312,   321,    83,     0,   126,    73,
      37,     0,    93,    92,   169,   227,   239,   153,   157,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   445,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    98,   101,   103,   100,   436,   400,
     437,   438,     0,   128,     0,   104,   105,   107,   210,   208,
     209,     0,    95,    94,   166,    48,     0,   167,   172,   170,
     176,   246,   244,   229,   233,   318,   242,     0,     0,     0,
       0,     0,   458,   459,   460,   461,     0,   462,   383,    57,
     336,   339,   343,   345,   347,   357,   368,   371,   376,   377,
     378,   384,     0,   379,   380,   381,   382,   467,   449,     0,
       0,     0,   440,   393,     0,   220,   426,     0,     0,     0,
     446,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   399,     0,   419,   420,     0,     0,     0,     0,
     394,     0,   418,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   215,   212,   211,     0,
       0,   106,     0,     0,     0,    88,    96,   120,   122,     0,
     165,   168,   169,   177,   174,   235,     0,   230,   231,   318,
     240,   158,   374,   375,   373,   215,   215,     0,    58,     0,
     337,   341,     0,     0,     0,     0,     0,     0,     0,     0,
     346,   348,   358,   370,   215,   468,   466,   450,     0,     0,
       0,   221,     0,     0,     0,   447,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   216,     0,   135,   129,   385,
     113,   114,   108,   109,     0,   111,   112,   116,   117,   124,
     125,   118,   121,   119,   123,    54,    49,   188,   192,   186,
     197,     0,     0,   185,   173,   151,   179,   181,   182,   184,
     180,   178,   201,   183,   175,   259,   247,     0,   289,     0,
       0,   245,   248,   250,   251,   260,   262,   265,   274,   269,
     272,   287,   261,   288,   228,   149,     0,     0,    56,   102,
       0,   340,     0,   344,   349,   350,   351,   352,   353,   354,
       0,   355,     0,     0,   363,   369,   359,   360,     0,     0,
     372,     0,   451,   391,   392,   439,   218,     0,     0,     0,
       0,   386,   387,     0,   389,   390,     0,   431,   432,   433,
     434,     0,   435,   421,     0,     0,   410,   425,   417,   416,
     398,   424,     0,   415,   397,   414,     0,   423,   413,   404,
       0,   396,   412,   403,   395,   402,     0,   401,   422,   411,
     213,     0,   110,   115,    52,    53,    55,     0,    86,   189,
     193,     0,   198,   207,     0,   169,     0,     0,   297,   305,
       0,   290,   292,   299,   301,   304,   275,   318,   263,   267,
     283,     0,   285,   284,   271,   273,   276,     0,   456,   457,
       0,   464,   338,   342,   356,   365,   366,   364,   367,   361,
     362,     0,     0,     0,     0,     0,     0,   448,     0,     0,
     442,     0,     0,     0,   442,     0,     0,   218,   127,   132,
     134,   136,    71,     0,    67,    68,    70,    51,    63,    60,
      62,    61,    64,    65,    66,    89,     0,   194,   187,     0,
       0,   171,   205,   291,   298,     0,   294,   303,   306,   302,
     257,     0,   266,     0,   270,     0,   307,   286,     0,   159,
     453,     0,   465,     0,   454,   452,   222,     0,   219,     0,
     428,   429,   388,   430,   443,     0,   408,   409,   405,     0,
     406,   407,     0,     0,    57,    69,    36,   190,   144,   199,
       0,   202,   300,   296,   249,   264,   268,     0,   280,     0,
     281,     0,   455,   217,     0,   441,   444,   214,   141,   142,
       0,   130,   143,   138,   139,   140,   137,     0,    50,     0,
     145,     0,     0,   203,   206,     0,   295,   254,   258,   282,
     277,   279,     0,     0,   427,   133,   131,    59,   191,     0,
     196,     0,   293,   252,   255,   256,   278,   463,   195,   204,
     318,   253
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yypgoto_[] =
  {
      -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,   496,  -664,
    -664,  -664,  -664,  -664,  -664,  -664,  -664,  -202,  -664,  -664,
    -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,
    -664,  -664,  -664,  -194,  -664,  -135,  -664,  -664,  -664,  -664,
    -664,  -664,  -664,  -664,  -664,  -664,  -664,   387,   -65,  -664,
    -141,  -664,  -664,  -664,  -664,  -664,  -664,   303,  -664,  -664,
     292,  -664,  -664,    76,  -664,  -664,  -664,  -664,  -664,  -664,
     171,   174,   169,  -664,  -664,  -664,  -664,  -664,  -664,  -208,
    -664,  -664,  -664,  -664,  -128,    58,  -664,  -664,  -664,  -664,
    -664,  -664,  -664,  -664,  -664,  -546,  -664,  -664,  -664,  -381,
    -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,
    -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,
    -664,  -664,  -664,  -664,  -664,  -664,  -664,  -360,  -185,   247,
    -664,  -359,  -591,  -112,  -210,  -664,  -664,  -664,  -664,   -64,
    -664,  -664,  -664,  -664,  -664,   175,   283,  -390,  -664,  -664,
     287,  -664,  -664,  -664,  -664,  -664,  -220,  -664,  -664,  -664,
    -664,  -664,  -664,  -664,  -664,    51,  -664,  -664,  -664,  -142,
    -664,  -664,    55,  -664,  -137,  -664,  -664,  -664,  -664,  -664,
    -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,  -615,  -664,
    -664,  -663,   -97,  -664,  -664,  -664,  -664,  -664,  -664,  -100,
     -87,  -182,   -11,    81,   538,  -664,  -664,  -664,    44,  -664,
    -664,    40,  -664,  -664,  -664,   -99,  -664,  -664,    29,  -664,
    -664,  -664,  -371,  -664,  -372,    53,  -172,  -155,  -664,  -664,
     -88,  -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,
    -587,  -664,  -664,  -664,  -664,  -664,  -664,    -9,  -664,  -664,
    -664,   -25,  -664,   165,   176,   110,  -205,    54,  -664,  -664
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yydefgoto_[] =
  {
        -1,     1,     2,     9,    21,    22,    50,    83,    52,    53,
      44,    45,    67,    68,   106,   100,    46,   189,     5,     6,
      10,     7,    24,    58,   104,   274,   275,   389,   618,   496,
     616,   617,   408,   409,   684,   685,   686,   687,    55,   113,
      56,    57,   132,   144,   166,   167,   168,   169,   145,   146,
     172,   173,   192,   272,   385,   174,   253,   254,   193,   265,
     266,   273,   482,   483,   484,   485,   486,   386,   491,   493,
     387,   388,   190,   263,   379,   770,   681,   743,   611,   771,
     781,   103,   111,   112,   123,   182,   153,   135,   154,   155,
     287,   535,   124,   137,   138,   176,   194,   276,   277,   278,
     504,   391,   279,   393,   394,   505,   506,   621,   507,   619,
     696,   779,   508,   620,   697,   748,   509,   510,   622,   699,
     511,   512,   626,   784,   801,   751,   513,   267,   268,   378,
     677,   476,   728,   663,   326,   566,   125,   141,   139,   157,
     397,   398,   284,   195,   158,   159,   149,   178,   286,   196,
     179,   280,   396,   395,   521,   637,   522,   804,   810,   805,
     788,   754,   516,   523,   524,   525,   526,   712,   638,   527,
     714,   639,   528,   644,   529,   645,   791,   760,   717,   646,
     530,   531,   631,   786,   753,   704,   705,   632,   633,   708,
     634,   718,   160,   127,   134,   128,   129,   130,   161,   180,
     163,   150,   298,   110,   299,   300,   541,   410,   301,   543,
     411,   302,   303,   420,   421,   304,   305,   554,   560,   658,
     555,   422,   306,   423,   307,   308,   309,   310,   323,   258,
     735,   259,   260,   330,   435,   570,   261,   427,   562,   662,
     311,   650,   312,   722,   723,   313,   426,   314,    62,    63,
      64,   315,    87,    88,    89,   316,    33,   317,    42,    92
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int MapSetParser::yytable_ninf_ = -319;
  const short int
  MapSetParser::yytable_[] =
  {
        27,   198,   255,    32,    34,    35,    36,    37,   156,   534,
     342,   514,   477,   706,   108,   126,   321,   324,    59,   269,
     165,   376,   487,   790,   667,   131,    86,   640,   558,    86,
     691,     4,   257,   715,    65,   678,   270,   679,    60,   126,
     162,   142,    85,     3,   641,    85,   536,   537,   758,   131,
      97,    54,   757,     8,   197,   726,   517,   143,   767,   759,
     -75,   185,    23,   727,    43,   561,   727,   518,   255,   642,
     148,    41,   559,    25,    26,   698,    86,   164,   628,   734,
     702,   519,    96,   734,   105,   126,   707,    86,    51,   629,
     109,   107,    85,   269,    95,   131,   792,   281,   257,   691,
      66,   109,    99,    85,   101,    91,   133,   282,    91,   643,
     270,    86,   629,   102,    98,    86,   725,   520,    47,    61,
      48,    49,   487,   151,    86,   109,   114,    85,   151,   109,
     151,    85,    84,   716,   716,    94,    86,   115,   109,   630,
      85,   623,    25,    26,   116,   147,   322,   325,   383,   384,
     109,   377,    85,   749,  -156,    91,   136,    86,    38,    39,
      40,    90,   630,   140,    90,   171,    91,   680,   175,    86,
     802,   109,   151,    85,   614,   615,   256,   177,    38,    39,
      40,   655,   656,   109,   181,    85,   659,   660,   152,   183,
      91,   187,   188,   152,    91,   152,   170,    38,    39,    40,
      38,    39,    40,    91,    28,    29,    30,    31,   191,   551,
     269,    90,    38,    39,    40,    91,   271,    25,    26,   170,
     283,   318,    90,    38,    39,    40,   285,   270,   319,   517,
      38,    39,    40,   798,   320,   327,    91,   152,   328,   329,
     518,   262,   256,   331,   701,   262,    90,   710,    91,   332,
      90,   333,   334,   808,   519,   809,    38,    39,    40,    90,
      86,    25,    26,   335,   336,   337,   497,   498,   338,   339,
     340,    90,   151,   341,   109,   517,    85,   412,   413,   414,
     415,   416,   417,   343,   188,   344,   518,   418,   419,   346,
    -200,   345,    90,   382,   347,   281,   348,   349,   499,   500,
     519,   501,   350,   351,    90,   282,   352,   262,   353,   354,
     269,   355,   613,   544,   545,   546,   547,   548,   549,   262,
     552,   553,   356,   357,   440,   358,   359,   270,   360,   269,
      28,    29,    30,    31,   361,   362,   520,   152,   363,    91,
     654,   402,   403,   404,   364,   365,   270,   -47,   366,   367,
     368,    38,    39,    40,   369,   370,   371,   117,   118,   119,
     120,   121,   372,   373,   374,  -318,   390,    86,   478,   401,
     392,   488,   475,   405,    86,   406,   424,   122,   479,   502,
     407,   109,   384,    85,   151,   532,   489,   490,   109,   383,
      85,   495,   539,   540,   550,    90,   538,    38,    39,    40,
     542,   264,    25,    26,   563,   564,   565,   647,   567,   143,
      74,    75,    76,    77,    78,    79,   568,   569,   571,   572,
     811,    11,    12,    13,    14,    15,    16,    17,    18,    19,
     573,    20,   688,   574,   575,   576,   262,   577,   126,   578,
     579,   580,   582,   581,   583,   586,    91,   587,   131,   152,
     533,   584,   588,    91,   585,   589,   590,   591,   592,   593,
     594,   595,   690,   719,   597,   598,   596,   599,   601,   602,
     600,   488,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    28,    29,    30,    31,    38,    39,    40,
      80,    81,    25,    26,   603,    82,   604,   605,   606,   607,
     608,   688,    90,   609,   624,   713,   703,   720,   724,    90,
      86,   711,   730,   721,   747,   731,   732,   729,   733,   727,
     736,   737,   738,   740,   109,   741,    85,   750,   281,   752,
     761,   690,   716,   762,   765,   766,   262,   780,   282,   785,
     787,   789,   783,   793,   778,   794,   797,   800,   806,    93,
     777,   745,   186,   695,   746,   262,   375,   381,   612,   494,
     503,   492,   796,   625,   425,   742,   399,   803,   627,   755,
     515,   533,   400,   635,   533,   636,   756,   117,   118,   119,
     120,   121,   653,   657,   652,  -318,   739,   556,   807,    91,
       0,     0,   693,     0,     0,     0,     0,   122,   557,   799,
      86,     0,     0,     0,     0,     0,   689,     0,   692,     0,
       0,     0,    86,     0,   109,     0,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   109,     0,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   693,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   262,     0,     0,     0,   689,     0,   692,     0,    91,
       0,     0,   635,     0,   709,   151,     0,     0,     0,     0,
       0,    91,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    28,    29,    30,    31,    38,    39,    40,
      80,    81,    25,    26,     0,    82,     0,     0,   774,     0,
       0,     0,     0,     0,     0,     0,     0,   694,     0,     0,
       0,     0,   772,     0,   773,    90,     0,     0,     0,   782,
     262,     0,     0,     0,     0,   774,     0,    90,     0,     0,
     152,     0,     0,     0,     0,     0,     0,     0,     0,   772,
       0,   773,     0,     0,     0,   533,     0,   533,     0,     0,
     151,     0,     0,     0,     0,     0,   532,     0,     0,     0,
       0,     0,     0,     0,     0,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   694,   776,     0,   109,
       0,    85,   380,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    28,    29,    30,    31,    38,    39,
      40,    80,    81,     0,   776,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,   152,     0,     0,     0,   635,
       0,   533,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   775,     0,     0,     0,   428,   429,   430,
       0,     0,   431,     0,    91,   432,   433,   434,     0,   436,
     437,   438,   439,     0,   441,   442,   443,   444,   445,   446,
     775,   447,     0,     0,   448,   449,   450,   451,     0,   452,
       0,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   648,     0,     0,     0,     0,     0,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   264,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   288,   289,     0,   290,   200,
       0,   201,   202,   203,   204,   205,   206,   207,   208,     0,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     0,   220,     0,     0,     0,   291,   292,   293,   294,
     295,   296,   297,   221,     0,     0,     0,     0,     0,     0,
       0,   222,   223,   224,     0,   225,   226,   227,     0,     0,
     228,   229,     0,   230,   610,   231,   232,   233,   234,     0,
     235,   236,     0,   237,     0,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    28,    29,    30,    31,    38,    39,    40,     0,     0,
      25,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   649,   651,     0,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    28,    29,
      30,    31,    38,    39,    40,    80,    81,    25,    26,   661,
      82,     0,     0,     0,     0,   664,   665,   666,     0,     0,
       0,   668,     0,     0,   669,   682,     0,     0,     0,   670,
       0,     0,   671,   672,     0,     0,     0,     0,     0,     0,
     673,     0,     0,     0,   674,   683,     0,     0,   675,     0,
       0,     0,     0,     0,   676,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   200,   700,   201,   202,   203,   204,   205,   206,   207,
     208,     0,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,     0,   220,     0,     0,     0,   291,   292,
     293,   294,   295,   296,   297,   221,     0,     0,     0,     0,
       0,     0,     0,   222,   223,   224,     0,   225,   226,   227,
       0,     0,   228,   229,     0,   230,     0,   231,   232,   233,
     234,   744,   235,   236,     0,   237,     0,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    28,    29,    30,    31,    38,    39,    40,
     480,   481,    25,    26,     0,   763,     0,   764,     0,     0,
       0,     0,     0,   264,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   117,
     118,   119,   120,   121,     0,     0,     0,     0,   184,   200,
       0,   201,   202,   203,   204,   205,   206,   207,   208,   122,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     0,   220,     0,   117,   118,   119,   120,   121,     0,
       0,     0,     0,   221,     0,     0,     0,     0,     0,     0,
       0,   222,   223,   224,   122,   225,   226,   227,     0,     0,
     228,   229,     0,   230,     0,   231,   232,   233,   234,     0,
     235,   236,     0,   237,     0,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,    39,    40,     0,     0,
      25,    26,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    28,    29,    30,    31,    38,
      39,    40,    80,    81,    25,    26,     0,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      28,    29,    30,    31,    38,    39,    40,    80,    81,    25,
      26,   264,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   288,   289,     0,   290,   200,     0,   201,
     202,   203,   204,   205,   206,   207,   208,     0,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,     0,
     220,     0,     0,     0,   291,   292,   293,   294,   295,   296,
     297,   221,     0,     0,     0,     0,     0,     0,     0,   222,
     223,   224,     0,   225,   226,   227,     0,     0,   228,   229,
       0,   230,     0,   231,   232,   233,   234,     0,   235,   236,
       0,   237,     0,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    28,
      29,    30,    31,    38,    39,    40,   264,     0,    25,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   795,
     768,   769,   200,     0,   201,   202,   203,   204,   205,   206,
     207,   208,     0,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,     0,   220,     0,     0,     0,   291,
     292,   293,   294,   295,   296,   297,   221,     0,     0,     0,
       0,     0,     0,     0,   222,   223,   224,     0,   225,   226,
     227,     0,     0,   228,   229,     0,   230,     0,   231,   232,
     233,   234,     0,   235,   236,     0,   237,     0,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    28,    29,    30,    31,    38,    39,
      40,   683,     0,    25,    26,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    28,    29,    30,    31,
      38,    39,    40,     0,     0,    25,    26,   200,     0,   201,
     202,   203,   204,   205,   206,   207,   208,     0,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,     0,
     220,     0,     0,     0,   291,   292,   293,   294,   295,   296,
     297,   221,     0,     0,     0,     0,     0,     0,     0,   222,
     223,   224,     0,   225,   226,   227,     0,     0,   228,   229,
       0,   230,     0,   231,   232,   233,   234,     0,   235,   236,
       0,   237,     0,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    28,
      29,    30,    31,    38,    39,    40,   199,     0,    25,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     768,   769,   200,     0,   201,   202,   203,   204,   205,   206,
     207,   208,     0,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,     0,   220,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   221,     0,     0,     0,
       0,     0,     0,     0,   222,   223,   224,     0,   225,   226,
     227,     0,     0,   228,   229,     0,   230,     0,   231,   232,
     233,   234,     0,   235,   236,     0,   237,     0,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    39,
      40,   264,     0,    25,    26,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    28,    29,    30,    31,
      38,    39,    40,     0,     0,    25,    26,   200,     0,   201,
     202,   203,   204,   205,   206,   207,   208,     0,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,     0,
     220,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   221,     0,     0,     0,     0,     0,     0,     0,   222,
     223,   224,     0,   225,   226,   227,     0,     0,   228,   229,
       0,   230,     0,   231,   232,   233,   234,     0,   235,   236,
       0,   237,     0,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    39,    40
  };

  /* YYCHECK.  */
  const short int
  MapSetParser::yycheck_[] =
  {
        11,   183,   187,    12,    13,    14,    15,    16,   136,   399,
     220,   392,    41,   628,   101,   112,    44,    44,    27,   191,
      28,    44,   382,    42,   570,   112,    51,    24,    24,    54,
     617,    20,   187,    53,    43,    42,   191,    44,    92,   136,
     140,    27,    51,     0,    41,    54,   405,   406,    42,   136,
      59,    16,   715,   166,   182,    45,    44,    43,    45,    53,
      25,   161,    21,    53,    56,   424,    53,    55,   253,    66,
     134,    17,    68,   171,   172,   621,   101,   141,    44,   670,
     626,    69,   167,   674,    42,   182,    55,   112,    41,    55,
     101,   100,   101,   265,    25,   182,   759,   194,   253,   686,
      41,   112,    57,   112,    42,    51,   115,   194,    54,   106,
     265,   136,    55,    41,    60,   140,   662,   105,    12,   173,
      14,    15,   482,   134,   149,   136,   166,   136,   139,   140,
     141,   140,    51,   153,   153,    54,   161,    48,   149,   105,
     149,   501,   171,   172,    42,    55,   174,   174,    33,    34,
     161,   174,   161,   699,    17,   101,    48,   182,   166,   167,
     168,    51,   105,    44,    54,    95,   112,   174,    41,   194,
     785,   182,   183,   182,    22,    23,   187,    57,   166,   167,
     168,   552,   553,   194,    48,   194,   558,   559,   134,    17,
     136,    30,    35,   139,   140,   141,   142,   166,   167,   168,
     166,   167,   168,   149,   162,   163,   164,   165,    96,   419,
     382,   101,   166,   167,   168,   161,    29,   171,   172,   165,
      54,    79,   112,   166,   167,   168,    53,   382,    44,    44,
     166,   167,   168,   779,    44,    44,   182,   183,    44,    44,
      55,   187,   253,    44,   625,   191,   136,   637,   194,    44,
     140,    44,    44,   799,    69,   801,   166,   167,   168,   149,
     285,   171,   172,    44,    44,    44,    17,    18,    44,    44,
      44,   161,   283,    44,   285,    44,   285,    60,    61,    62,
      63,    64,    65,    44,    35,   174,    55,    70,    71,    44,
      41,   174,   182,    30,    44,   392,    44,    44,    49,    50,
      69,    52,   174,    44,   194,   392,   174,   253,    44,    44,
     482,    44,   484,   412,   413,   414,   415,   416,   417,   265,
      66,    67,    44,    44,   335,    44,    44,   482,    44,   501,
     162,   163,   164,   165,    44,    44,   105,   283,    44,   285,
     550,   288,   289,   290,    44,    44,   501,    26,    44,    44,
      44,   166,   167,   168,    44,    44,    44,    36,    37,    38,
      39,    40,    44,    44,    44,    44,    42,   392,   379,    41,
      48,   382,    22,    44,   399,    44,    44,    56,    45,   130,
      94,   392,    34,   392,   395,   396,   153,   153,   399,    33,
     399,    26,    45,    58,    71,   285,   407,   166,   167,   168,
      59,    44,   171,   172,    45,    45,    45,   535,    53,    43,
     156,   157,   158,   159,   160,   161,    53,    53,    45,    45,
     810,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      53,    13,   617,    45,    45,    53,   382,    45,   535,    45,
      45,    45,    45,    53,    45,    45,   392,    45,   535,   395,
     396,    53,    45,   399,    53,    45,    45,    45,    53,    45,
      45,    45,   617,    42,    45,    45,    53,    45,    45,    45,
      53,   482,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    45,   174,    45,    45,    53,    45,
      45,   686,   392,    45,    44,    68,    45,    45,    45,   399,
     535,   107,    45,    54,   696,    45,    45,    53,    45,    53,
      45,    45,    45,    45,   535,    45,   535,    94,   625,    45,
      80,   686,   153,    45,    45,    45,   482,    19,   625,   107,
      54,    42,    51,    60,   746,    45,    45,    45,    42,    53,
     744,   686,   165,   618,   695,   501,   253,   265,   482,   388,
     391,   387,   770,   505,   317,   677,   283,   787,   517,   711,
     395,   517,   285,   519,   520,   520,   713,    36,    37,    38,
      39,    40,   542,   554,   540,    44,   674,   422,   793,   535,
      -1,    -1,   617,    -1,    -1,    -1,    -1,    56,   422,   781,
     625,    -1,    -1,    -1,    -1,    -1,   617,    -1,   617,    -1,
      -1,    -1,   637,    -1,   625,    -1,   625,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   637,    -1,   637,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   535,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   686,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   617,    -1,    -1,    -1,   686,    -1,   686,    -1,   625,
      -1,    -1,   628,    -1,   630,   696,    -1,    -1,    -1,    -1,
      -1,   637,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,    -1,   743,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   617,    -1,    -1,
      -1,    -1,   743,    -1,   743,   625,    -1,    -1,    -1,   750,
     686,    -1,    -1,    -1,    -1,   770,    -1,   637,    -1,    -1,
     696,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   770,
      -1,   770,    -1,    -1,    -1,   711,    -1,   713,    -1,    -1,
     781,    -1,    -1,    -1,    -1,    -1,   787,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   810,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   686,   743,    -1,   810,
      -1,   810,   264,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,    -1,   770,    -1,   174,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   781,    -1,    -1,    -1,   785,
      -1,   787,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   743,    -1,    -1,    -1,   319,   320,   321,
      -1,    -1,   324,    -1,   810,   327,   328,   329,    -1,   331,
     332,   333,   334,    -1,   336,   337,   338,   339,   340,   341,
     770,   343,    -1,    -1,   346,   347,   348,   349,    -1,   351,
      -1,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,    24,    -1,    -1,    -1,    -1,    -1,    -1,
     810,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    69,    70,
      -1,    72,    73,    74,    75,    76,    77,    78,    79,    -1,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    -1,    -1,    -1,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,   113,   114,    -1,   116,   117,   118,    -1,    -1,
     121,   122,    -1,   124,   476,   126,   127,   128,   129,    -1,
     131,   132,    -1,   134,    -1,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   536,   537,    -1,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   561,
     174,    -1,    -1,    -1,    -1,   567,   568,   569,    -1,    -1,
      -1,   573,    -1,    -1,   576,    24,    -1,    -1,    -1,   581,
      -1,    -1,   584,   585,    -1,    -1,    -1,    -1,    -1,    -1,
     592,    -1,    -1,    -1,   596,    44,    -1,    -1,   600,    -1,
      -1,    -1,    -1,    -1,   606,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,   624,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    -1,    -1,    -1,    97,    98,
      99,   100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,   118,
      -1,    -1,   121,   122,    -1,   124,    -1,   126,   127,   128,
     129,   683,   131,   132,    -1,   134,    -1,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      31,    32,   171,   172,    -1,   727,    -1,   729,    -1,    -1,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,    70,
      -1,    72,    73,    74,    75,    76,    77,    78,    79,    56,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    -1,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,   113,   114,    56,   116,   117,   118,    -1,    -1,
     121,   122,    -1,   124,    -1,   126,   127,   128,   129,    -1,
     131,   132,    -1,   134,    -1,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   167,   168,    -1,    -1,
     171,   172,    -1,    -1,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,   174,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    44,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    -1,    69,    70,    -1,    72,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    70,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    -1,    -1,    -1,    97,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,
     118,    -1,    -1,   121,   122,    -1,   124,    -1,   126,   127,
     128,   129,    -1,   131,   132,    -1,   134,    -1,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,    44,    -1,   171,   172,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    -1,    -1,   171,   172,    70,    -1,    72,
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
      46,    47,    70,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,   113,   114,    -1,   116,   117,
     118,    -1,    -1,   121,   122,    -1,   124,    -1,   126,   127,
     128,   129,    -1,   131,   132,    -1,   134,    -1,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,   167,
     168,    44,    -1,   171,   172,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    -1,    -1,   171,   172,    70,    -1,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
     113,   114,    -1,   116,   117,   118,    -1,    -1,   121,   122,
      -1,   124,    -1,   126,   127,   128,   129,    -1,   131,   132,
      -1,   134,    -1,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   166,   167,   168
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  MapSetParser::yystos_[] =
  {
         0,   176,   177,     0,    20,   193,   194,   196,   166,   178,
     195,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      13,   179,   180,    21,   197,   171,   172,   377,   162,   163,
     164,   165,   422,   431,   422,   422,   422,   422,   166,   167,
     168,   432,   433,    56,   185,   186,   191,    12,    14,    15,
     181,    41,   183,   184,    16,   213,   215,   216,   198,   422,
      92,   173,   423,   424,   425,   422,    41,   187,   188,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     169,   170,   174,   182,   378,   422,   426,   427,   428,   429,
     430,   432,   434,   183,   378,    25,   167,   422,   432,    57,
     190,    42,    41,   256,   199,    42,   189,   422,   375,   377,
     378,   257,   258,   214,   166,    48,    42,    36,    37,    38,
      39,    40,    56,   259,   267,   311,   367,   368,   370,   371,
     372,   375,   217,   422,   369,   262,    48,   268,   269,   313,
      44,   312,    27,    43,   218,   223,   224,    55,   314,   321,
     376,   377,   432,   261,   263,   264,   259,   314,   319,   320,
     367,   373,   374,   375,   314,    28,   219,   220,   221,   222,
     432,    95,   225,   226,   230,    41,   270,    57,   322,   325,
     374,    48,   260,    17,    45,   374,   222,    30,    35,   192,
     247,    96,   227,   233,   271,   318,   324,   259,   376,    44,
      70,    72,    73,    74,    75,    76,    77,    78,    79,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      93,   104,   112,   113,   114,   116,   117,   118,   121,   122,
     124,   126,   127,   128,   129,   131,   132,   134,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   231,   232,   303,   377,   402,   404,   406,
     407,   411,   432,   248,    44,   234,   235,   302,   303,   401,
     402,    29,   228,   236,   200,   201,   272,   273,   274,   277,
     326,   367,   375,    54,   317,    53,   323,   265,    66,    67,
      69,    97,    98,    99,   100,   101,   102,   103,   377,   379,
     380,   383,   386,   387,   390,   391,   397,   399,   400,   401,
     402,   415,   417,   420,   422,   426,   430,   432,    79,    44,
      44,    44,   174,   403,    44,   174,   309,    44,    44,    44,
     408,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,   309,    44,   174,   174,    44,    44,    44,    44,
     174,    44,   174,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,   232,    44,   174,   304,   249,
     379,   235,    30,    33,    34,   229,   242,   245,   246,   202,
      42,   276,    48,   278,   279,   328,   327,   315,   316,   321,
     325,    41,   400,   400,   400,    44,    44,    94,   207,   208,
     382,   385,    60,    61,    62,    63,    64,    65,    70,    71,
     388,   389,   396,   398,    44,   304,   421,   412,   379,   379,
     379,   379,   379,   379,   379,   409,   379,   379,   379,   379,
     377,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,    22,   306,    41,   377,    45,
      31,    32,   237,   238,   239,   240,   241,   302,   377,   153,
     153,   243,   246,   244,   245,    26,   204,    17,    18,    49,
      50,    52,   130,   247,   275,   280,   281,   283,   287,   291,
     292,   295,   296,   301,   274,   320,   337,    44,    55,    69,
     105,   329,   331,   338,   339,   340,   341,   344,   347,   349,
     355,   356,   377,   432,   322,   266,   306,   306,   377,    45,
      58,   381,    59,   384,   390,   390,   390,   390,   390,   390,
      71,   309,    66,    67,   392,   395,   428,   429,    24,    68,
     393,   306,   413,    45,    45,    45,   310,    53,    53,    53,
     410,    45,    45,    53,    45,    45,    53,    45,    45,    45,
      45,    53,    45,    45,    53,    53,    45,    45,    45,    45,
      45,    45,    53,    45,    45,    45,    53,    45,    45,    45,
      53,    45,    45,    45,    45,    45,    53,    45,    45,    45,
     379,   253,   238,   401,    22,    23,   205,   206,   203,   284,
     288,   282,   293,   302,    44,   260,   297,   340,    44,    55,
     105,   357,   362,   363,   365,   432,   347,   330,   343,   346,
      24,    41,    66,   106,   348,   350,   354,   259,    24,   379,
     416,   379,   383,   386,   309,   397,   397,   393,   394,   399,
     399,   379,   414,   308,   379,   379,   379,   270,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   305,    42,    44,
     174,   251,    24,    44,   209,   210,   211,   212,   303,   377,
     402,   415,   422,   426,   430,   223,   285,   289,   270,   294,
     379,   274,   270,    45,   360,   361,   363,    55,   364,   432,
     322,   107,   342,    68,   345,    53,   153,   353,   366,    42,
      45,    54,   418,   419,    45,   270,    45,    53,   307,    53,
      45,    45,    45,    45,   307,   405,    45,    45,    45,   405,
      45,    45,   308,   252,   379,   210,   225,   376,   290,   270,
      94,   300,    45,   359,   336,   344,   349,   366,    42,    53,
     352,    80,    45,   379,   379,    45,    45,    45,    46,    47,
     250,   254,   377,   422,   426,   430,   432,   208,   192,   286,
      19,   255,   377,    51,   298,   107,   358,    54,   335,    42,
      42,   351,   366,    60,    45,    45,   254,    45,   270,   376,
      45,   299,   363,   331,   332,   334,    42,   431,   270,   270,
     333,   322
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
     254,   254,   254,   254,   255,   255,   256,   258,   257,   259,
     259,   260,   260,   261,   262,   262,   264,   265,   266,   263,
     267,   268,   269,   269,   271,   270,   272,   272,   273,   274,
     274,   275,   276,   276,   277,   278,   279,   279,   280,   280,
     280,   280,   280,   280,   280,   280,   282,   281,   284,   285,
     286,   283,   288,   289,   290,   287,   291,   293,   294,   292,
     296,   297,   295,   299,   298,   300,   300,   301,   302,   302,
     302,   303,   304,   305,   304,   306,   306,   307,   308,   308,
     309,   310,   309,   312,   311,   313,   311,   314,   315,   316,
     316,   317,   318,   318,   319,   320,   320,   321,   321,   322,
     323,   324,   324,   325,   327,   326,   328,   326,   330,   329,
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
     403,   404,   405,   405,   406,   408,   409,   410,   407,   412,
     413,   414,   411,   415,   415,   415,   416,   416,   417,   417,
     417,   417,   417,   418,   419,   419,   420,   421,   421,   422,
     423,   424,   424,   425,   425,   426,   426,   426,   427,   427,
     427,   428,   428,   428,   429,   429,   429,   430,   430,   431,
     431,   431,   431,   432,   432,   433,   433,   434,   434
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
       1,     1,     1,     1,     0,     1,     3,     0,     3,     0,
       1,     0,     1,     3,     0,     2,     0,     0,     0,     8,
       2,     2,     0,     1,     0,     4,     1,     1,     2,     0,
       1,     3,     0,     2,     2,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     3,     0,     0,
       0,     6,     0,     0,     0,     7,     6,     0,     0,     4,
       0,     0,     4,     0,     3,     0,     2,     2,     1,     1,
       1,     2,     1,     0,     6,     0,     1,     2,     0,     2,
       1,     0,     5,     0,     3,     0,     3,     3,     2,     0,
       1,     2,     0,     2,     1,     0,     1,     1,     1,     2,
       2,     0,     2,     1,     0,     3,     0,     3,     0,     4,
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
       1,     7,     0,     1,     7,     0,     0,     0,     5,     0,
       0,     0,     6,     5,     5,     6,     1,     1,     1,     1,
       1,     1,     1,     4,     0,     1,     2,     0,     1,     2,
       2,     1,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
  "DefaultPrimaryKey", "_QValuesClause_E_Opt", "Prologue",
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
  "OffsetClause", "ValuesClause", "$@8", "_QVar_E_Star",
  "_QBindingValue_E_Plus",
  "_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C",
  "$@9",
  "_Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star",
  "BindingValue", "_QIT_SILENT_E_Opt", "QuadPattern", "Quads", "$@10",
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
  "ServiceGraphPattern", "@19", "@20", "@21", "Bind", "MinusGraphPattern",
  "@22", "@23", "GroupOrUnionGraphPattern", "@24", "@25",
  "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@26",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "@27", "_QIT_DISTINCT_E_Opt",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ExpressionList", "@28",
  "TriplesSameSubject", "$@29", "$@30", "PropertyListNotEmpty",
  "_O_QVerb_E_S_QObjectList_E_C", "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "Verb", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "TriplesSameSubjectPath", "$@31", "$@32",
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
  "_O_Qiri_E_Or_QIT_a_E_Or_QGT_NOT_E_S_QPathNegatedPropertySet_E_Or_QGT_LPAREN_E_S_QPath_E_S_QGT_RPAREN_E_C",
  "PathNegatedPropertySet", "_O_QGT_PIPE_E_S_QPathOneInPropertySet_E_C",
  "_Q_O_QGT_PIPE_E_S_QPathOneInPropertySet_E_C_E_Star",
  "_O_QPathOneInPropertySet_E_S_QGT_PIPE_E_S_QPathOneInPropertySet_E_Star_C",
  "_Q_O_QPathOneInPropertySet_E_S_QGT_PIPE_E_S_QPathOneInPropertySet_E_Star_C_E_Opt",
  "_O_QPathOneInPropertySet_E_Or_QGT_LPAREN_E_S_QPathOneInPropertySet_E_S_QGT_PIPE_E_S_QPathOneInPropertySet_E_Star_Opt_S_QGT_RPAREN_E_C",
  "PathOneInPropertySet", "_O_Qiri_E_Or_QIT_a_E_C",
  "_O_Qiri_E_Or_QIT_a_E_Or_QGT_CARROT_E_S_Qiri_E_Or_QIT_a_E_C", "Integer",
  "TriplesNode", "BlankNodePropertyList", "@35", "Generator",
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
  "SubstringExpression", "ExistsFunc", "@36", "@37", "@38",
  "NotExistsFunc", "@39", "@40", "@41", "Aggregate",
  "_O_QGT_TIMES_E_Or_QExpression_E_C",
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
       176,     0,    -1,    -1,   177,   193,   178,   179,    -1,    -1,
     178,   180,    -1,    -1,   179,   213,    -1,     3,   377,   422,
     422,    -1,     4,   422,    -1,     5,   422,    -1,     6,   422,
      -1,     7,   422,    -1,     8,   422,    -1,     9,   432,    -1,
      10,   185,    -1,    11,   181,    -1,    13,   184,    -1,    12,
      -1,    15,    -1,    14,    -1,    -1,   378,    -1,    41,   182,
      42,   375,    -1,   183,    -1,   184,   183,    -1,   186,   187,
      -1,    -1,   191,    -1,    -1,   188,    -1,    41,   190,    42,
      -1,   422,    48,   422,    -1,    -1,   190,   189,    -1,    56,
     422,    57,    -1,    -1,   247,    -1,   194,   195,    -1,    -1,
     196,    -1,    -1,   195,   197,    -1,    20,   166,    -1,    -1,
      -1,    21,   198,   167,   199,   166,    -1,    -1,    -1,    -1,
     201,   202,   204,   203,   223,   225,   192,    -1,    26,   206,
     212,    -1,    22,    -1,    23,    -1,    -1,   205,    -1,    94,
     377,    -1,    -1,   207,    -1,    44,   379,   208,    45,    -1,
     377,    -1,   415,    -1,   402,    -1,   303,    -1,   422,    -1,
     426,    -1,   430,    -1,   209,    -1,   210,    -1,   211,   210,
      -1,   211,    -1,    24,    -1,    -1,   216,    25,   256,   214,
     217,   223,   225,   192,    -1,    16,   378,    -1,    -1,   215,
      -1,    -1,   217,   218,    -1,    27,   219,    -1,   220,    -1,
     221,    -1,   222,    -1,    28,   222,    -1,   432,    -1,   224,
     270,    -1,    -1,    43,    -1,   226,   227,   228,   229,    -1,
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
     253,   251,    -1,   432,    -1,   422,    -1,   426,    -1,   430,
      -1,    46,    -1,    47,    -1,   377,    -1,    -1,    19,    -1,
      41,   257,    42,    -1,    -1,   258,   259,   262,    -1,    -1,
     267,    -1,    -1,    48,    -1,   263,   260,   259,    -1,    -1,
     262,   261,    -1,    -1,    -1,    -1,   264,    17,   376,   265,
      41,   266,   259,    42,    -1,   311,   269,    -1,    48,   259,
      -1,    -1,   268,    -1,    -1,    41,   271,   272,    42,    -1,
     200,    -1,   273,    -1,   274,   276,    -1,    -1,   277,    -1,
     280,   260,   274,    -1,    -1,   276,   275,    -1,   326,   279,
      -1,    48,   274,    -1,    -1,   278,    -1,   295,    -1,   281,
      -1,   292,    -1,   283,    -1,   287,    -1,   301,    -1,   291,
      -1,   247,    -1,    -1,    49,   282,   270,    -1,    -1,    -1,
      -1,    17,   284,   285,   376,   286,   270,    -1,    -1,    -1,
      -1,    18,   288,   289,   290,   255,   376,   270,    -1,   130,
      44,   379,    94,   377,    45,    -1,    -1,    -1,    50,   293,
     294,   270,    -1,    -1,    -1,   296,   297,   270,   300,    -1,
      -1,    51,   299,   270,    -1,    -1,   300,   298,    -1,    52,
     302,    -1,   401,    -1,   402,    -1,   303,    -1,   432,   304,
      -1,   174,    -1,    -1,    44,   306,   379,   305,   308,    45,
      -1,    -1,    22,    -1,    53,   379,    -1,    -1,   308,   307,
      -1,   174,    -1,    -1,    44,   379,   310,   308,    45,    -1,
      -1,   375,   312,   314,    -1,    -1,   367,   313,   319,    -1,
     321,   322,   318,    -1,   321,   322,    -1,    -1,   315,    -1,
      54,   316,    -1,    -1,   318,   317,    -1,   320,    -1,    -1,
     314,    -1,   376,    -1,    55,    -1,   325,   324,    -1,    53,
     325,    -1,    -1,   324,   323,    -1,   374,    -1,    -1,   375,
     327,   329,    -1,    -1,   367,   328,   337,    -1,    -1,   331,
     330,   322,   336,    -1,   338,    -1,   339,    -1,    -1,   331,
     333,   322,    -1,    -1,   332,    -1,    54,   334,    -1,    -1,
     336,   335,    -1,   320,    -1,   340,    -1,   377,    -1,   341,
      -1,   344,   343,    -1,   107,   344,    -1,    -1,   343,   342,
      -1,   349,   346,    -1,    68,   349,    -1,    -1,   346,   345,
      -1,   355,   348,    -1,    -1,   350,    -1,   347,    -1,   105,
     347,    -1,   354,    -1,    42,    -1,   366,    42,    -1,    53,
     351,    -1,    42,    -1,   366,   352,    -1,    53,   366,    42,
      -1,    24,    -1,   106,    -1,    66,    -1,    41,   353,    -1,
     356,    -1,   432,    -1,    55,    -1,    69,   357,    -1,    44,
     340,    45,    -1,   362,    -1,   107,   363,    -1,    -1,   359,
     358,    -1,   363,   359,    -1,    -1,   360,    -1,   363,    -1,
      44,   361,    45,    -1,   365,    -1,   432,    -1,    55,    -1,
     432,    -1,    55,    -1,   105,   364,    -1,   153,    -1,   370,
      -1,   368,    -1,    -1,    56,   369,   314,    57,    -1,   372,
      44,   373,    45,    -1,    36,    -1,    37,    -1,    38,    -1,
      39,    -1,    40,    -1,    -1,   371,    -1,   374,    -1,   373,
     374,    -1,   375,    -1,   367,    -1,   377,    -1,   378,    -1,
     377,    -1,   432,    -1,   171,    -1,   172,    -1,   432,    -1,
     422,    -1,   426,    -1,   430,    -1,   434,    -1,   174,    -1,
     380,    -1,   383,   382,    -1,    58,   383,    -1,    -1,   382,
     381,    -1,   386,   385,    -1,    59,   386,    -1,    -1,   385,
     384,    -1,   387,    -1,   390,   388,    -1,    -1,   389,    -1,
      60,   390,    -1,    61,   390,    -1,    62,   390,    -1,    63,
     390,    -1,    64,   390,    -1,    65,   390,    -1,    71,   309,
      -1,    70,    71,   309,    -1,   391,    -1,   397,   396,    -1,
     428,    -1,   429,    -1,    24,   399,    -1,    68,   399,    -1,
      -1,   393,    -1,    66,   397,    -1,    67,   397,    -1,   392,
     394,    -1,    -1,   396,   395,    -1,   399,   398,    -1,    -1,
     398,   393,    -1,    69,   400,    -1,    66,   400,    -1,    67,
     400,    -1,   400,    -1,   401,    -1,   402,    -1,   420,    -1,
     422,    -1,   426,    -1,   430,    -1,   377,    -1,   415,    -1,
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
      -1,   407,    -1,   411,    -1,    44,   379,    45,    -1,   174,
      -1,    91,    44,   379,    53,   379,   405,    45,    -1,    -1,
     307,    -1,   137,    44,   379,    53,   379,   405,    45,    -1,
      -1,    -1,    -1,    79,   408,   409,   410,   270,    -1,    -1,
      -1,    -1,    70,    79,   412,   413,   414,   270,    -1,    97,
      44,   306,   416,    45,    -1,   417,    44,   306,   379,    45,
      -1,   102,    44,   306,   379,   419,    45,    -1,    24,    -1,
     379,    -1,    98,    -1,    99,    -1,   100,    -1,   101,    -1,
     103,    -1,    54,    80,    60,   431,    -1,    -1,   418,    -1,
     432,   421,    -1,    -1,   304,    -1,   431,   425,    -1,    92,
     432,    -1,   173,    -1,   423,    -1,    -1,   424,    -1,   427,
      -1,   428,    -1,   429,    -1,   153,    -1,   154,    -1,   155,
      -1,   156,    -1,   157,    -1,   158,    -1,   159,    -1,   160,
      -1,   161,    -1,   151,    -1,   152,    -1,   162,    -1,   164,
      -1,   163,    -1,   165,    -1,   166,    -1,   433,    -1,   168,
      -1,   167,    -1,   169,    -1,   170,    -1
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
     339,   341,   343,   345,   347,   348,   350,   354,   355,   359,
     360,   362,   363,   365,   369,   370,   373,   374,   375,   376,
     385,   388,   391,   392,   394,   395,   400,   402,   404,   407,
     408,   410,   414,   415,   418,   421,   424,   425,   427,   429,
     431,   433,   435,   437,   439,   441,   443,   444,   448,   449,
     450,   451,   458,   459,   460,   461,   469,   476,   477,   478,
     483,   484,   485,   490,   491,   495,   496,   499,   502,   504,
     506,   508,   511,   513,   514,   521,   522,   524,   527,   528,
     531,   533,   534,   540,   541,   545,   546,   550,   554,   557,
     558,   560,   563,   564,   567,   569,   570,   572,   574,   576,
     579,   582,   583,   586,   588,   589,   593,   594,   598,   599,
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
    1189,  1191,  1199,  1200,  1202,  1210,  1211,  1212,  1213,  1219,
    1220,  1221,  1222,  1229,  1235,  1241,  1248,  1250,  1252,  1254,
    1256,  1258,  1260,  1262,  1267,  1268,  1270,  1273,  1274,  1276,
    1279,  1282,  1284,  1286,  1287,  1289,  1291,  1293,  1295,  1297,
    1299,  1301,  1303,  1305,  1307,  1309,  1311,  1313,  1315,  1317,
    1319,  1321,  1323,  1325,  1327,  1329,  1331,  1333,  1335
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
    1069,  1072,  1075,  1078,  1084,  1087,  1093,  1099,  1099,  1107,
    1109,  1113,  1115,  1119,  1122,  1124,  1129,  1134,  1137,  1129,
    1148,  1152,  1155,  1157,  1162,  1162,  1173,  1174,  1179,  1183,
    1185,  1195,  1199,  1202,  1218,  1223,  1227,  1230,  1234,  1235,
    1236,  1237,  1238,  1239,  1240,  1241,  1247,  1247,  1263,  1267,
    1269,  1263,  1280,  1284,  1286,  1280,  1297,  1308,  1312,  1308,
    1322,  1326,  1322,  1336,  1336,  1348,  1350,  1354,  1364,  1365,
    1366,  1370,  1378,  1382,  1382,  1392,  1395,  1402,  1408,  1410,
    1424,  1427,  1427,  1437,  1437,  1440,  1440,  1447,  1452,  1456,
    1458,  1463,  1467,  1469,  1474,  1478,  1480,  1484,  1488,  1496,
    1501,  1505,  1507,  1511,  1519,  1519,  1522,  1522,  1528,  1528,
    1534,  1535,  1539,  1539,  1544,  1546,  1550,  1553,  1555,  1559,
    1563,  1567,  1573,  1577,  1581,  1584,  1586,  1590,  1594,  1599,
    1601,  1607,  1610,  1612,  1618,  1619,  1625,  1629,  1630,  1634,
    1635,  1639,  1640,  1644,  1645,  1646,  1647,  1651,  1655,  1658,
    1661,  1664,  1670,  1674,  1677,  1679,  1683,  1686,  1688,  1692,
    1693,  1697,  1701,  1702,  1706,  1707,  1708,  1712,  1717,  1718,
    1722,  1722,  1735,  1762,  1765,  1768,  1771,  1774,  1781,  1784,
    1789,  1793,  1800,  1801,  1805,  1808,  1812,  1815,  1821,  1822,
    1826,  1829,  1832,  1835,  1838,  1839,  1845,  1850,  1859,  1866,
    1869,  1877,  1886,  1893,  1896,  1903,  1908,  1921,  1925,  1929,
    1933,  1937,  1941,  1945,  1949,  1953,  1957,  1964,  1969,  1978,
    1981,  1988,  1991,  1998,  2001,  2006,  2009,  2013,  2027,  2030,
    2038,  2047,  2050,  2057,  2060,  2063,  2066,  2070,  2071,  2072,
    2073,  2076,  2079,  2082,  2085,  2089,  2095,  2098,  2101,  2104,
    2107,  2110,  2113,  2117,  2120,  2123,  2126,  2129,  2132,  2135,
    2138,  2139,  2142,  2145,  2148,  2151,  2154,  2157,  2160,  2163,
    2166,  2169,  2172,  2175,  2178,  2181,  2184,  2187,  2190,  2193,
    2196,  2199,  2202,  2205,  2208,  2211,  2214,  2217,  2220,  2223,
    2226,  2229,  2232,  2235,  2238,  2241,  2244,  2245,  2246,  2252,
    2255,  2262,  2269,  2272,  2276,  2282,  2285,  2288,  2282,  2301,
    2304,  2307,  2301,  2321,  2325,  2330,  2339,  2342,  2346,  2349,
    2352,  2355,  2358,  2364,  2370,  2373,  2377,  2387,  2390,  2395,
    2403,  2410,  2414,  2422,  2426,  2430,  2431,  2432,  2436,  2437,
    2438,  2442,  2443,  2444,  2448,  2449,  2450,  2454,  2455,  2459,
    2460,  2461,  2462,  2466,  2467,  2471,  2472,  2476,  2477
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
  const int MapSetParser::yylast_ = 2085;
  const int MapSetParser::yynnts_ = 260;
  const int MapSetParser::yyempty_ = -2;
  const int MapSetParser::yyfinal_ = 3;
  const int MapSetParser::yyterror_ = 1;
  const int MapSetParser::yyerrcode_ = 256;
  const int MapSetParser::yyntokens_ = 175;

  const unsigned int MapSetParser::yyuser_token_number_max_ = 429;
  const MapSetParser::token_number_type MapSetParser::yyundef_token_ = 2;


} // w3c_sw

/* Line 1136 of lalr1.cc  */
#line 5042 "lib/MapSetParser/MapSetParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 2483 "lib/MapSetParser/MapSetParser.ypp"
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


