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
#line 308 "lib/MapSetParser/MapSetParser.ypp"

#include "../MapSetScanner.hpp"

/* Line 299 of lalr1.cc  */
#line 448 "lib/MapSetParser/MapSetParser.ypp"

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
}

/* Line 565 of lalr1.cc  */
#line 346 "lib/MapSetParser/MapSetParser.cpp"

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
#line 463 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root = new MapSet();
	driver.root->sharedVars = MapSet::e_PROMISCUOUS;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 481 "lib/MapSetParser/MapSetParser.ypp"
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
#line 490 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->driver = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 493 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->server = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 496 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->user = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 499 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->password = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 502 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->database = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 505 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->stemURI = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 510 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.sharedVarsSet = true;
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 514 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.lastRuleTermSet = false;
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 520 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_PROMISCUOUS;
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 523 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_VARNAMES;
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 526 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_DRACONIAN;
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 532 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = NULL;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 539 "lib/MapSetParser/MapSetParser.ypp"
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
#line 574 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->keyMap[(yysemantic_stack_[(3) - (1)].p_RDFLiteral)->getLexicalValue()] = (yysemantic_stack_[(3) - (3)].p_RDFLiteral)->getLexicalValue();
    }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 585 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->primaryKey = (yysemantic_stack_[(3) - (2)].p_RDFLiteral);
    }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 592 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 616 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 622 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 624 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 626 "lib/MapSetParser/MapSetParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 634 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 637 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 640 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 644 "lib/MapSetParser/MapSetParser.ypp"
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
#line 655 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 663 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 666 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 673 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 681 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 688 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 696 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 703 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 706 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 709 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 712 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 715 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 718 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 721 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 730 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 733 "lib/MapSetParser/MapSetParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 741 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 744 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 751 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = NULL;
      }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 753 "lib/MapSetParser/MapSetParser.ypp"
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
#line 763 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (2)].p_TTerm);
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 769 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = NULL;
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 777 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 780 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 788 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 800 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 806 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 812 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 819 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.ensureGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 833 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 840 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 848 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 856 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 864 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 872 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 879 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 882 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 889 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 892 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 895 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 898 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 904 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 910 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 913 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 925 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 932 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 936 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 946 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 954 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 957 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 965 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 974 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 981 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 985 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 993 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1001 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1008 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1014 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1021 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1023 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1031 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1037 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1040 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1046 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.startBindingRow(); // @@ push down to _Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star?
      }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1048 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1051 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1063 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1066 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1069 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1072 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1075 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1078 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1081 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1087 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
    }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1093 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1095 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TableOperation) = driver.ensureGraphPattern();
	  driver.curOp = NULL;
      }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1123 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1128 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1131 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1134 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1156 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1158 "lib/MapSetParser/MapSetParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1235 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_BindingClause)) : (yysemantic_stack_[(1) - (1)].p_BindingClause);
    }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1241 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1245 "lib/MapSetParser/MapSetParser.ypp"
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
#line 1257 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1261 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1263 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1266 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1274 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1278 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1280 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1283 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(7) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(7) - (6)].p_TTerm), driver.curOp, (yysemantic_stack_[(7) - (5)].p_Silence), driver.atomFactory, false));
	  driver.curGraphName = (yysemantic_stack_[(7) - (4)].p_TTerm);
      }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1291 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1294 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1300 "lib/MapSetParser/MapSetParser.ypp"
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
#line 1311 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1315 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1317 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1325 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1329 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1331 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1339 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1344 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.ensureGraphPattern());
      }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1357 "lib/MapSetParser/MapSetParser.ypp"
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
#line 1373 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 1381 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1385 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 1388 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yysemantic_stack_[(6) - (4)].p_Expressions);
      }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 1395 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 1398 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 1405 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 1413 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1427 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 1430 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1433 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(5) - (3)].p_Expressions);
      }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 1440 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 1443 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 1503 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 1510 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 1514 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 1522 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 1525 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 1531 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 1542 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 1570 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 1597 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 1604 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 1615 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 1622 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 1658 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 1661 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 1664 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 1667 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 1725 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 1729 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 1738 "lib/MapSetParser/MapSetParser.ypp"
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

  case 313:

/* Line 690 of lalr1.cc  */
#line 1763 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 1766 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 1769 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 1772 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 1775 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 1782 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 1790 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 1794 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 1806 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 1813 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 1816 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 1827 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 1830 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 1833 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 1836 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 1840 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 1851 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 1860 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 1867 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 1870 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 1878 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 1887 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 1894 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 1897 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 1909 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_GeneralComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_GeneralComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_GeneralComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 1920 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 1927 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 1930 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 1933 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 1936 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 1939 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 1942 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 1945 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 1948 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 1959 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 1968 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 1971 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 1978 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 1981 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 1988 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 1996 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 1999 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 2003 "lib/MapSetParser/MapSetParser.ypp"
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
#line 2017 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 2020 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 2028 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 2037 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 2040 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 2047 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 2050 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 2053 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 2063 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 2066 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 2069 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 2072 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 2079 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 2085 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 2088 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 2091 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 2094 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 2097 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 2100 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 2103 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 2107 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 2110 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 2113 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 2116 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ceil, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 2119 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 2122 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 2125 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 2129 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 2132 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 2135 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 2138 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 2141 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 2144 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 2147 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 2150 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 2153 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 2156 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 2159 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 2162 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 2165 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 2168 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 2171 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 2174 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 2177 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 2180 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 2183 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_uuid, NULL, NULL, NULL));
    }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 2186 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_struuid, NULL, NULL, NULL));
    }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 2189 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 2192 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 2195 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 2198 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 2201 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 2204 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 2208 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 2211 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 2214 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 2217 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 2220 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 2223 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 2226 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 2229 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 2232 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 2243 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 2246 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 2253 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 2260 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 2267 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 2273 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.ensureGraphPattern(), NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 2280 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.ensureGraphPattern(), NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 2287 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 2291 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 2296 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 2300 "lib/MapSetParser/MapSetParser.ypp"
    {
	  if ((yysemantic_stack_[(7) - (6)].p_RDFLiteral) != NULL) {
	      std::stringstream ss;
	      ss << "GROUP_CONCAT ; " << (yysemantic_stack_[(7) - (6)].p_RDFLiteral)->getLexicalValue();
	      w3c_sw_NEED_IMPL(ss.str());
	  }
	  (yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(7) - (3)].p_distinctness), (yysemantic_stack_[(7) - (4)].p_Expression)));
	  // // x = new ArgList($2, driver.curExprList);
	  // delete driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(7) - (5)].p_Expressions);
	  // w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // // $$ = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group-concat, $3, $4.p_Expression, $4.separator));
    }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 2316 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 2323 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 2326 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 2329 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 2332 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 2335 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 2341 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 2347 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 2354 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 2364 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 2372 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 2380 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 2387 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 2391 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 2399 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 690 of lalr1.cc  */
#line 3277 "lib/MapSetParser/MapSetParser.cpp"
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
  const short int MapSetParser::yypact_ninf_ = -684;
  const short int
  MapSetParser::yypact_[] =
  {
      -684,    39,    58,  -684,   -77,  -684,  -684,  -684,  -684,   274,
      72,     3,   106,   106,   106,   106,   106,    60,    44,   177,
      79,    33,  -684,  -684,  -684,  -684,  -684,   106,  -684,  -684,
    -684,  -684,  -684,   -60,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,   106,  -684,    85,  -684,  -684,  -684,  -684,
    -684,  1013,  -684,    79,  1013,  -684,  -684,   117,   -63,   106,
      60,  -684,  -684,  -684,  -684,    87,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,   104,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,   108,  -684,  -684,  -684,  -684,
      35,   920,  -684,  -684,    -4,  -684,  -684,   122,  -684,  -684,
    -684,   135,   475,  -684,  -684,   106,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,   154,  -684,  -684,  -684,  -684,
     161,  -684,     8,  -684,    86,   193,   475,  -684,  -684,    86,
    1316,    86,    -8,  -684,  -684,   119,   197,  -684,   187,  1316,
    -684,  -684,  -684,  -684,   198,   230,  -684,  -684,  -684,  -684,
    -684,  1281,  -684,  -684,  -684,    60,  -684,  -684,  -684,  -684,
    -684,   225,   224,   165,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,   475,   134,  -684,  -684,  -684,  1820,  -684,  -684,
    -684,  1927,   234,  -684,   322,   212,   220,  -684,  -684,  1445,
     196,   244,   245,   -21,   -20,   247,   249,   250,   197,   251,
     253,   254,   259,   260,   266,   268,   269,   270,   272,   276,
     -20,   277,   144,   149,   278,   287,   289,   291,   162,   296,
     167,   298,   302,   303,   305,   306,   307,   308,   309,   310,
     311,   312,   319,   320,   321,   325,   326,   328,   329,   331,
     332,   333,   335,  1820,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,   -13,  -684,  1445,  1927,  -684,  -684,  -684,  -684,
    -684,   350,   148,  -684,  -684,  -684,   340,  -684,  -684,  -684,
     338,  -684,  -684,    86,  -684,  1316,  -684,   346,  1570,  1570,
    1570,   345,  -684,  -684,  -684,  -684,   347,  -684,  -684,   299,
    -684,  -684,  -684,  -684,    -1,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,   348,  -684,  -684,  -684,  -684,   -13,   197,  1445,
    1445,  1445,  -684,  -684,  1445,  -684,  -684,  1445,  1445,  1445,
    -684,  1445,  1445,  1445,  1445,     3,  1445,  1445,  1445,  1445,
    1445,  1445,  -684,  1445,  -684,  -684,  1445,  1445,  1445,  1445,
    -684,  1445,  -684,  1445,  1445,  1445,  1445,  1445,  1445,  1445,
    1445,  1445,  1445,  1445,  1445,  1445,  1445,  1445,  1445,  1445,
    1445,  1445,  1445,  1445,  1445,  -684,   372,  -684,  -684,   -24,
     352,  -684,  1257,   252,   255,  -684,  -684,   361,   371,   380,
    -684,   215,   475,  -684,  -684,    86,    40,  -684,  -684,  1316,
    -684,  -684,  -684,  -684,  -684,   372,   372,     3,  -684,   364,
     353,   351,  1445,  1445,  1445,  1445,  1445,  1445,   341,   -20,
    -684,  -684,   242,    13,   372,  -684,  -684,  -684,   369,   370,
     373,  -684,   363,   366,   367,   377,   378,   374,   379,   383,
     376,   385,   386,   387,   388,   384,   394,   396,   389,   390,
     399,   400,   402,   403,   406,   407,   401,   410,   411,   412,
     405,   414,   415,   416,   409,   418,   419,   420,   421,   422,
     442,   423,   424,   427,  -684,  1445,  -684,  -684,  -684,  -684,
    -684,  1257,  -684,   381,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,   164,  -684,  -684,  -684,  -684,  -684,
    1927,   454,  -684,  -684,   198,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,    -3,  -684,    12,    63,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,   143,
    -684,  -684,  -684,  -684,   475,   893,  1445,  -684,  -684,  1445,
    -684,  1445,  -684,  -684,  -684,  -684,  -684,  -684,  -684,   -20,
    -684,  1445,  1445,    13,  -684,  -684,  -684,  1445,  1445,  -684,
    1445,  -684,  -684,  -684,  -684,  1445,  1445,  1445,  -684,  -684,
    1445,  -684,  -684,  1445,  -684,  -684,  -684,  -684,  1445,  -684,
    -684,  1445,  1445,  -684,  -684,  -684,  -684,  -684,  -684,  1445,
    -684,  -684,  -684,  1445,  -684,  -684,  -684,  1445,  -684,  -684,
    -684,  -684,  -684,  1445,  -684,  -684,  -684,  -684,   -23,  -684,
    -684,  -684,  -684,  -684,  1119,   456,  -684,  -684,   197,  -684,
    -684,  1445,   475,   197,   455,   -33,  -684,    57,  -684,  -684,
    -684,  -684,  -684,  -684,  1316,   395,   349,  -684,   -10,  -684,
    -684,  -684,  -684,  -684,   459,  -684,  -684,   458,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,   460,    30,
     451,   461,   463,   471,   472,   465,   476,   479,   482,   465,
     483,   484,  -684,  -684,  -684,  -684,  -684,  -684,  1445,  -684,
    -684,  1695,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,
     119,   134,  -684,  -684,   197,   426,  -684,  -684,  -684,  -684,
     485,  -684,  -684,  -684,  -684,  -684,    -3,  -684,    -3,  -684,
     391,  -684,  -684,    32,  -684,  -684,   478,  -684,  -684,  1445,
    -684,  1445,  -684,  -684,  -684,  -684,  -684,   488,  -684,  -684,
    -684,   489,  -684,  -684,    43,   767,   299,  -684,   224,  -684,
     517,  -684,     3,   486,  -684,   432,   487,  -684,  -684,   498,
    -684,   -14,  -684,   466,  -684,   500,  -684,   502,  -684,  -684,
    -684,  -684,  -684,   540,  -684,  -684,  -684,  -684,  -684,  -684,
     503,  -684,   197,  -684,   134,   505,  -684,  -684,   -33,  -684,
      40,  -684,  -684,  -684,  -684,   501,   491,  -684,  -684,  -684,
    -684,  -684,  -684,   197,  -684,   197,  -684,  -684,  -684,  -684,
    -684,   106,  -684,  -684,  1316,  -684,  -684
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  MapSetParser::yydefact_[] =
  {
         2,     0,    39,     1,     0,     4,    41,    40,    43,     6,
      38,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     3,     5,    44,    42,   328,   329,     0,   484,   486,
     485,   487,     9,   468,    10,    11,    12,    13,   488,   491,
     490,    14,   489,     0,    15,    29,    28,    18,    20,    19,
      16,    21,    24,    17,     0,     7,    76,     0,     0,     0,
       0,   466,   467,   469,   464,     0,    33,    26,    30,   482,
     483,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     492,   493,   335,     0,    22,   331,   332,   470,   471,   472,
     333,   330,   334,    25,    74,     0,    45,     8,   465,    35,
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
       0,     0,   453,   454,   455,   456,     0,   457,   383,    57,
     336,   339,   343,   345,   347,   357,   368,   371,   376,   377,
     378,   384,     0,   379,   380,   381,   382,   462,     0,     0,
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
     346,   348,   358,   370,   215,   463,   461,   446,     0,     0,
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
     284,   271,   273,   276,     0,   451,   452,     0,   449,   338,
     342,   356,   365,   366,   364,   367,   361,   362,     0,     0,
       0,     0,     0,     0,     0,   442,     0,     0,     0,   442,
       0,     0,   218,   127,   132,   134,   136,    71,     0,    67,
      68,    70,    51,    63,    60,    62,    61,    64,    65,    66,
      89,     0,   192,   185,     0,     0,   169,   205,   291,   298,
       0,   294,   303,   306,   302,   257,     0,   266,     0,   270,
       0,   307,   286,     0,   157,   447,   459,   448,   222,     0,
     219,     0,   428,   429,   388,   430,   443,     0,   408,   409,
     405,     0,   406,   407,     0,     0,    57,    69,    36,   188,
     194,   199,     0,   202,   300,   296,   249,   264,   268,     0,
     280,     0,   281,     0,   460,     0,   217,     0,   441,   444,
     214,   141,   142,     0,   130,   143,   138,   139,   140,   137,
       0,    50,     0,   195,     0,     0,   203,   206,     0,   295,
     254,   258,   282,   277,   279,     0,     0,   450,   427,   133,
     131,    59,   189,     0,   196,     0,   293,   252,   255,   256,
     278,     0,   193,   204,   318,   458,   253
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yypgoto_[] =
  {
      -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,   499,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,  -185,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -180,  -684,  -126,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,   392,   -57,  -684,
    -131,  -684,  -684,  -684,  -684,  -684,  -684,   313,  -684,  -684,
     295,  -684,  -684,    80,  -684,  -684,  -684,  -684,  -684,  -684,
     174,   176,   173,  -684,  -684,  -684,  -684,  -684,  -684,  -198,
    -684,  -684,  -684,  -127,    64,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -197,  -684,  -684,  -684,  -382,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,  -344,  -174,   257,
    -684,  -359,  -612,  -105,  -206,  -684,  -684,  -684,  -684,   -61,
    -684,  -684,  -684,  -684,  -684,   181,  -391,  -684,  -684,   284,
     288,  -684,  -684,  -684,  -684,  -684,  -203,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,    62,  -684,  -684,  -684,  -125,
    -684,  -684,    61,  -684,  -129,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -610,  -684,
    -684,  -683,   -96,  -684,  -684,  -684,  -684,  -684,  -684,  -107,
    -100,  -181,   -11,    65,   533,  -684,  -684,  -684,    45,  -684,
    -684,    41,  -684,  -684,  -684,   -87,  -684,  -684,    37,  -684,
    -684,  -684,  -334,  -684,  -323,   -68,  -166,  -143,  -684,  -684,
     -86,  -684,  -684,  -684,  -584,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,    -9,  -684,  -684,  -684,   -25,  -684,   169,   170,
     150,  -207,    54,  -684,  -684
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
     387,   388,   190,   263,   379,   763,   676,   735,   608,   764,
     103,   111,   112,   123,   182,   153,   135,   154,   155,   287,
     534,   124,   137,   138,   176,   194,   276,   277,   278,   503,
     391,   279,   393,   394,   504,   505,   618,   506,   616,   691,
     772,   507,   617,   692,   740,   774,   508,   509,   619,   694,
     510,   511,   623,   777,   795,   743,   512,   267,   268,   378,
     672,   475,   720,   659,   326,   564,   125,   141,   139,   157,
     397,   398,   284,   195,   158,   159,   178,   286,   196,   179,
     149,   280,   396,   395,   520,   634,   521,   798,   804,   799,
     781,   746,   515,   522,   523,   524,   525,   707,   635,   526,
     709,   636,   527,   641,   528,   642,   784,   752,   712,   643,
     529,   530,   628,   779,   745,   699,   700,   629,   630,   703,
     631,   713,   160,   127,   134,   128,   129,   130,   161,   180,
     163,   150,   298,   110,   299,   300,   540,   410,   301,   542,
     411,   302,   303,   420,   421,   304,   305,   553,   559,   655,
     554,   422,   306,   423,   307,   308,   309,   310,   323,   258,
     727,   259,   260,   261,   311,   716,   647,   312,   754,   755,
     313,   426,   314,    62,    63,    64,   315,    87,    88,    89,
     316,    33,   317,    42,    92
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int MapSetParser::yytable_ninf_ = -319;
  const short int
  MapSetParser::yytable_[] =
  {
        27,   108,   198,    32,    34,    35,    36,    37,   533,   156,
     513,   330,   131,   255,   342,   701,   126,   476,    59,   673,
     165,   674,   626,   321,   324,   269,    86,   749,   783,    86,
     686,   376,    60,   162,    65,   142,   131,   557,   486,     3,
     126,   516,    85,   710,   257,    85,   535,   536,   270,    54,
      97,   143,   517,   726,   185,   197,   625,   726,   -75,   412,
     413,   414,   415,   416,   417,   560,   518,   626,   785,   418,
     419,    41,   627,   148,   750,   718,    86,   105,     4,   255,
     164,   558,   131,   719,   516,   751,   126,    86,   760,     8,
     109,   107,    85,    23,   282,   517,   719,   686,   281,   269,
      43,   109,   519,    85,    96,    91,   133,   516,    91,   518,
     257,    86,   702,    61,    98,    86,    84,   627,   517,    94,
      51,   427,   270,   151,    86,   109,    66,    85,   151,   109,
     151,    85,   518,    38,    39,    40,    86,   486,   109,   711,
      85,   147,    95,   711,    99,   519,   101,    25,    26,   102,
     109,   675,    85,   322,   325,    91,   620,    86,    38,    39,
      40,   377,   114,    38,    39,    40,    91,   637,   796,    86,
     115,   109,   151,    85,    25,    26,   256,   116,    38,    39,
      40,   383,   384,   109,   638,    85,   611,   612,   152,    47,
      91,    48,    49,   152,    91,   152,   170,    28,    29,    30,
      31,    90,   136,    91,    90,   140,    38,    39,    40,   639,
    -154,    25,    26,   550,   171,    91,   269,   652,   653,   170,
     402,   403,   404,    38,    39,    40,    38,    39,    40,    38,
      39,    40,   496,   497,   656,   657,    91,   152,   175,   270,
     696,   262,   256,   705,   177,   262,   181,   183,    91,   640,
     188,    90,    38,    39,    40,   187,  -200,    25,    26,   188,
      86,   191,    90,   271,   498,   499,   283,   500,    28,    29,
      30,    31,   151,   285,   109,   318,    85,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    90,    20,   319,   320,
      90,   327,   282,   328,   329,   331,   281,   332,   333,    90,
      38,    39,    40,   334,   335,    25,    26,   262,   551,   552,
     336,    90,   337,   338,   339,   269,   340,   610,   344,   262,
     341,   343,   346,   345,   439,   543,   544,   545,   546,   547,
     548,   347,    90,   348,   269,   349,   350,   152,   270,    91,
     351,   352,   353,   651,    90,   501,   354,   355,   -47,   356,
     357,   358,   359,   360,   361,   362,   363,   270,   117,   118,
     119,   120,   121,   364,   365,   366,  -318,    86,   477,   367,
     368,   487,   369,   370,    86,   371,   372,   373,   122,   374,
     382,   109,   390,    85,   151,   531,   392,   401,   109,   405,
      85,   406,   424,   407,   474,   384,   537,   478,    74,    75,
      76,    77,    78,    79,   383,   488,   494,   644,   489,   538,
     541,   539,   549,   806,   561,   562,   565,   708,   563,   566,
     567,   693,   568,   569,   571,   264,   697,   570,   572,   573,
     574,   575,   576,   577,   131,    90,   262,   578,   126,   579,
     683,   580,   581,   582,   583,   584,    91,   585,   586,   152,
     532,   587,   588,    91,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   604,   605,
     487,   685,   606,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    28,    29,    30,    31,    38,    39,
      40,    80,    81,    25,    26,   603,    82,   741,   621,   143,
     698,   714,   706,   715,   721,   717,   722,   683,   723,    86,
     739,   117,   118,   119,   120,   121,   724,   725,   719,  -318,
     742,   728,   282,   109,   729,    85,   281,   730,   732,   733,
     744,   122,   753,   758,   759,   262,   773,   776,   685,   778,
     782,   780,    90,   800,   711,   787,   786,   788,   791,    90,
     794,   801,    93,   771,   262,   737,   770,   186,   690,   738,
     381,   609,   493,   491,   502,   790,   375,   734,   622,   400,
     532,   399,   632,   532,   425,   792,   514,   797,   624,   748,
     633,   747,   650,   731,   649,   789,   761,   762,    91,   688,
     654,   555,   556,   793,   805,     0,   802,    86,   803,     0,
       0,     0,     0,   684,     0,   687,     0,     0,     0,    86,
       0,   109,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   109,     0,    85,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    28,    29,    30,
      31,    38,    39,    40,    80,    81,    25,    26,     0,    82,
       0,     0,     0,     0,     0,     0,   688,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   262,     0,
     684,     0,   687,     0,     0,     0,    91,     0,     0,   632,
     151,   704,     0,     0,    90,     0,     0,     0,    91,     0,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    28,    29,    30,    31,    38,    39,    40,     0,
     767,    25,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   765,     0,   766,     0,     0,     0,
       0,   775,     0,     0,     0,   262,     0,     0,   767,     0,
       0,     0,     0,     0,     0,   152,     0,     0,     0,     0,
       0,     0,   765,     0,   766,     0,     0,     0,     0,     0,
     532,     0,   532,   151,   689,     0,     0,     0,     0,   531,
       0,     0,    90,     0,     0,     0,     0,     0,     0,    86,
       0,     0,     0,     0,    90,     0,     0,     0,     0,   769,
       0,     0,     0,   109,     0,    85,     0,   380,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   761,   762,     0,     0,   769,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   152,     0,
       0,   689,   632,     0,   532,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   428,   429,   430,     0,     0,   431,    91,     0,
     432,   433,   434,     0,   435,   436,   437,   438,     0,   440,
     441,   442,   443,   444,   445,     0,   446,     0,     0,   447,
     448,   449,   450,     0,   451,   768,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,     0,   768,     0,     0,     0,   645,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    28,
      29,    30,    31,    38,    39,    40,     0,   264,    25,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,     0,     0,     0,     0,   288,
     289,     0,   290,   200,     0,   201,   202,   203,   204,   205,
     206,   207,   208,     0,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,     0,   220,     0,     0,     0,
     291,   292,   293,   294,   295,   296,   297,   221,     0,     0,
       0,     0,     0,     0,     0,   222,   223,   224,   607,   225,
     226,   227,     0,     0,   228,   229,     0,   230,     0,   231,
     232,   233,   234,     0,   235,   236,     0,   237,     0,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    28,    29,    30,    31,    38,
      39,    40,     0,     0,    25,    26,     0,     0,   646,   648,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    28,    29,    30,    31,    38,    39,    40,    80,
      81,    25,    26,   658,    82,     0,     0,     0,   660,   661,
     662,     0,     0,   663,     0,     0,   664,     0,     0,     0,
       0,   665,     0,     0,   666,   667,     0,     0,     0,     0,
       0,     0,   668,     0,     0,     0,   669,     0,     0,     0,
     670,     0,     0,     0,     0,     0,   671,     0,     0,     0,
       0,     0,     0,   677,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   695,     0,     0,     0,     0,     0,
       0,     0,     0,   678,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    28,    29,    30,    31,    38,
      39,    40,    80,    81,     0,     0,     0,    82,     0,   200,
       0,   201,   202,   203,   204,   205,   206,   207,   208,     0,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   736,   220,     0,     0,     0,   291,   292,   293,   294,
     295,   296,   297,   221,     0,     0,     0,     0,     0,     0,
       0,   222,   223,   224,     0,   225,   226,   227,     0,     0,
     228,   229,     0,   230,     0,   231,   232,   233,   234,     0,
     235,   236,   756,   237,   757,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    28,    29,    30,    31,    38,    39,    40,   479,   480,
      25,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   264,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   117,   118,   119,
     120,   121,     0,     0,     0,     0,   184,   200,     0,   201,
     202,   203,   204,   205,   206,   207,   208,   122,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,     0,
     220,     0,   117,   118,   119,   120,   121,     0,     0,     0,
       0,   221,     0,     0,     0,     0,     0,     0,     0,   222,
     223,   224,   122,   225,   226,   227,     0,     0,   228,   229,
       0,   230,     0,   231,   232,   233,   234,     0,   235,   236,
       0,   237,     0,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    39,    40,     0,     0,    25,    26,
       0,     0,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    28,    29,    30,    31,    38,    39,    40,
      80,    81,    25,    26,     0,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    28,    29,
      30,    31,    38,    39,    40,    80,    81,    25,    26,   264,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   288,   289,     0,   290,   200,     0,   201,   202,   203,
     204,   205,   206,   207,   208,     0,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,     0,   220,     0,
       0,     0,   291,   292,   293,   294,   295,   296,   297,   221,
       0,     0,     0,     0,     0,     0,     0,   222,   223,   224,
       0,   225,   226,   227,     0,     0,   228,   229,     0,   230,
       0,   231,   232,   233,   234,     0,   235,   236,     0,   237,
       0,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    28,    29,    30,
      31,    38,    39,    40,   264,     0,    25,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     200,     0,   201,   202,   203,   204,   205,   206,   207,   208,
       0,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,     0,   220,     0,     0,     0,   291,   292,   293,
     294,   295,   296,   297,   221,     0,     0,     0,     0,     0,
       0,     0,   222,   223,   224,     0,   225,   226,   227,     0,
       0,   228,   229,     0,   230,     0,   231,   232,   233,   234,
       0,   235,   236,     0,   237,     0,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    28,    29,    30,    31,    38,    39,    40,   678,
       0,    25,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   200,     0,   201,   202,   203,
     204,   205,   206,   207,   208,     0,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,     0,   220,     0,
       0,     0,   291,   292,   293,   294,   295,   296,   297,   221,
       0,     0,     0,     0,     0,     0,     0,   222,   223,   224,
       0,   225,   226,   227,     0,     0,   228,   229,     0,   230,
       0,   231,   232,   233,   234,     0,   235,   236,     0,   237,
       0,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    28,    29,    30,
      31,    38,    39,    40,   199,     0,    25,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     200,     0,   201,   202,   203,   204,   205,   206,   207,   208,
       0,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,     0,   220,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   221,     0,     0,     0,     0,     0,
       0,     0,   222,   223,   224,     0,   225,   226,   227,     0,
       0,   228,   229,     0,   230,     0,   231,   232,   233,   234,
       0,   235,   236,     0,   237,     0,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   264,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    39,    40,     0,
       0,    25,    26,     0,     0,     0,     0,   200,     0,   201,
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
        11,   101,   183,    12,    13,    14,    15,    16,   399,   136,
     392,   208,   112,   187,   220,   625,   112,    41,    27,    42,
      28,    44,    55,    44,    44,   191,    51,   710,    42,    54,
     614,    44,    92,   140,    43,    27,   136,    24,   382,     0,
     136,    44,    51,    53,   187,    54,   405,   406,   191,    16,
      59,    43,    55,   665,   161,   182,    44,   669,    25,    60,
      61,    62,    63,    64,    65,   424,    69,    55,   751,    70,
      71,    17,   105,   134,    42,    45,   101,    42,    20,   253,
     141,    68,   182,    53,    44,    53,   182,   112,    45,   166,
     101,   100,   101,    21,   194,    55,    53,   681,   194,   265,
      56,   112,   105,   112,   167,    51,   115,    44,    54,    69,
     253,   136,    55,   173,    60,   140,    51,   105,    55,    54,
      41,   318,   265,   134,   149,   136,    41,   136,   139,   140,
     141,   140,    69,   166,   167,   168,   161,   481,   149,   153,
     149,    55,    25,   153,    57,   105,    42,   171,   172,    41,
     161,   174,   161,   174,   174,   101,   500,   182,   166,   167,
     168,   174,   166,   166,   167,   168,   112,    24,   778,   194,
      48,   182,   183,   182,   171,   172,   187,    42,   166,   167,
     168,    33,    34,   194,    41,   194,    22,    23,   134,    12,
     136,    14,    15,   139,   140,   141,   142,   162,   163,   164,
     165,    51,    48,   149,    54,    44,   166,   167,   168,    66,
      17,   171,   172,   419,    95,   161,   382,   551,   552,   165,
     288,   289,   290,   166,   167,   168,   166,   167,   168,   166,
     167,   168,    17,    18,   557,   558,   182,   183,    41,   382,
     622,   187,   253,   634,    57,   191,    48,    17,   194,   106,
      35,   101,   166,   167,   168,    30,    41,   171,   172,    35,
     285,    96,   112,    29,    49,    50,    54,    52,   162,   163,
     164,   165,   283,    53,   285,    79,   285,     3,     4,     5,
       6,     7,     8,     9,    10,    11,   136,    13,    44,    44,
     140,    44,   392,    44,    44,    44,   392,    44,    44,   149,
     166,   167,   168,    44,    44,   171,   172,   253,    66,    67,
      44,   161,    44,    44,    44,   481,    44,   483,   174,   265,
      44,    44,    44,   174,   335,   412,   413,   414,   415,   416,
     417,    44,   182,    44,   500,    44,   174,   283,   481,   285,
      44,   174,    44,   549,   194,   130,    44,    44,    26,    44,
      44,    44,    44,    44,    44,    44,    44,   500,    36,    37,
      38,    39,    40,    44,    44,    44,    44,   392,   379,    44,
      44,   382,    44,    44,   399,    44,    44,    44,    56,    44,
      30,   392,    42,   392,   395,   396,    48,    41,   399,    44,
     399,    44,    44,    94,    22,    34,   407,    45,   156,   157,
     158,   159,   160,   161,    33,   153,    26,   534,   153,    45,
      59,    58,    71,   804,    45,    45,    53,    68,    45,    53,
      53,   618,    45,    45,    45,    44,   623,    53,    45,    53,
      45,    45,    45,    45,   534,   285,   382,    53,   534,    45,
     614,    45,    53,    53,    45,    45,   392,    45,    45,   395,
     396,    45,    45,   399,    53,    45,    45,    45,    53,    45,
      45,    45,    53,    45,    45,    45,    45,    45,    45,    45,
     481,   614,    45,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    53,   174,   694,    44,    43,
      45,    42,   107,    45,    53,    45,    45,   681,    45,   534,
     691,    36,    37,    38,    39,    40,    45,    45,    53,    44,
      94,    45,   622,   534,    45,   534,   622,    45,    45,    45,
      45,    56,    54,    45,    45,   481,    19,    51,   681,   107,
      42,    54,   392,    42,   153,    45,    80,    45,    45,   399,
      45,    60,    53,   738,   500,   681,   736,   165,   615,   690,
     265,   481,   388,   387,   391,   763,   253,   672,   504,   285,
     516,   283,   518,   519,   317,   772,   395,   780,   516,   708,
     519,   706,   541,   669,   539,    45,    46,    47,   534,   614,
     553,   422,   422,   774,   801,    -1,   793,   622,   795,    -1,
      -1,    -1,    -1,   614,    -1,   614,    -1,    -1,    -1,   634,
      -1,   622,    -1,   622,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   634,    -1,   634,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,    -1,    -1,    -1,    -1,    -1,   681,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   614,    -1,
     681,    -1,   681,    -1,    -1,    -1,   622,    -1,    -1,   625,
     691,   627,    -1,    -1,   534,    -1,    -1,    -1,   634,    -1,
      -1,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
     735,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   735,    -1,   735,    -1,    -1,    -1,
      -1,   742,    -1,    -1,    -1,   681,    -1,    -1,   763,    -1,
      -1,    -1,    -1,    -1,    -1,   691,    -1,    -1,    -1,    -1,
      -1,    -1,   763,    -1,   763,    -1,    -1,    -1,    -1,    -1,
     706,    -1,   708,   774,   614,    -1,    -1,    -1,    -1,   780,
      -1,    -1,   622,    -1,    -1,    -1,    -1,    -1,    -1,   804,
      -1,    -1,    -1,    -1,   634,    -1,    -1,    -1,    -1,   735,
      -1,    -1,    -1,   804,    -1,   804,    -1,   264,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    -1,    -1,   763,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   774,    -1,
      -1,   681,   778,    -1,   780,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   319,   320,   321,    -1,    -1,   324,   804,    -1,
     327,   328,   329,    -1,   331,   332,   333,   334,    -1,   336,
     337,   338,   339,   340,   341,    -1,   343,    -1,    -1,   346,
     347,   348,   349,    -1,   351,   735,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,    -1,    -1,
      -1,    -1,    -1,   763,    -1,    -1,    -1,    24,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    44,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   804,    -1,    -1,    -1,    -1,    66,
      67,    -1,    69,    70,    -1,    72,    73,    74,    75,    76,
      77,    78,    79,    -1,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    -1,    -1,    -1,
      97,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,   113,   114,   475,   116,
     117,   118,    -1,    -1,   121,   122,    -1,   124,    -1,   126,
     127,   128,   129,    -1,   131,   132,    -1,   134,    -1,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,   171,   172,    -1,    -1,   535,   536,
      -1,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   560,   174,    -1,    -1,    -1,   565,   566,
     567,    -1,    -1,   570,    -1,    -1,   573,    -1,    -1,    -1,
      -1,   578,    -1,    -1,   581,   582,    -1,    -1,    -1,    -1,
      -1,    -1,   589,    -1,    -1,    -1,   593,    -1,    -1,    -1,
     597,    -1,    -1,    -1,    -1,    -1,   603,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   621,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,    -1,    -1,    -1,   174,    -1,    70,
      -1,    72,    73,    74,    75,    76,    77,    78,    79,    -1,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,   678,    93,    -1,    -1,    -1,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,   113,   114,    -1,   116,   117,   118,    -1,    -1,
     121,   122,    -1,   124,    -1,   126,   127,   128,   129,    -1,
     131,   132,   719,   134,   721,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    31,    32,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    45,    70,    -1,    72,
      73,    74,    75,    76,    77,    78,    79,    56,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    -1,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
     113,   114,    56,   116,   117,   118,    -1,    -1,   121,   122,
      -1,   124,    -1,   126,   127,   128,   129,    -1,   131,   132,
      -1,   134,    -1,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   166,   167,   168,    -1,    -1,   171,   172,
      -1,    -1,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,    44,
     174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    -1,    69,    70,    -1,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    -1,
      -1,    -1,    97,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,   114,
      -1,   116,   117,   118,    -1,    -1,   121,   122,    -1,   124,
      -1,   126,   127,   128,   129,    -1,   131,   132,    -1,   134,
      -1,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    44,    -1,   171,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    73,    74,    75,    76,    77,    78,    79,
      -1,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    -1,    93,    -1,    -1,    -1,    97,    98,    99,
     100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   113,   114,    -1,   116,   117,   118,    -1,
      -1,   121,   122,    -1,   124,    -1,   126,   127,   128,   129,
      -1,   131,   132,    -1,   134,    -1,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    44,
      -1,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    -1,
      -1,    -1,    97,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,   114,
      -1,   116,   117,   118,    -1,    -1,   121,   122,    -1,   124,
      -1,   126,   127,   128,   129,    -1,   131,   132,    -1,   134,
      -1,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    44,    -1,   171,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    73,    74,    75,    76,    77,    78,    79,
      -1,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   113,   114,    -1,   116,   117,   118,    -1,
      -1,   121,   122,    -1,   124,    -1,   126,   127,   128,   129,
      -1,   131,   132,    -1,   134,    -1,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   166,   167,   168,    -1,
      -1,   171,   172,    -1,    -1,    -1,    -1,    70,    -1,    72,
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
     164,   165,   417,   426,   417,   417,   417,   417,   166,   167,
     168,   427,   428,    56,   185,   186,   191,    12,    14,    15,
     181,    41,   183,   184,    16,   213,   215,   216,   198,   417,
      92,   173,   418,   419,   420,   417,    41,   187,   188,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     169,   170,   174,   182,   378,   417,   421,   422,   423,   424,
     425,   427,   429,   183,   378,    25,   167,   417,   427,    57,
     190,    42,    41,   255,   199,    42,   189,   417,   375,   377,
     378,   256,   257,   214,   166,    48,    42,    36,    37,    38,
      39,    40,    56,   258,   266,   311,   367,   368,   370,   371,
     372,   375,   217,   417,   369,   261,    48,   267,   268,   313,
      44,   312,    27,    43,   218,   223,   224,    55,   314,   325,
     376,   377,   427,   260,   262,   263,   258,   314,   319,   320,
     367,   373,   374,   375,   314,    28,   219,   220,   221,   222,
     427,    95,   225,   226,   230,    41,   269,    57,   321,   324,
     374,    48,   259,    17,    45,   374,   222,    30,    35,   192,
     247,    96,   227,   233,   270,   318,   323,   258,   376,    44,
      70,    72,    73,    74,    75,    76,    77,    78,    79,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      93,   104,   112,   113,   114,   116,   117,   118,   121,   122,
     124,   126,   127,   128,   129,   131,   132,   134,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   231,   232,   303,   377,   402,   404,   406,
     407,   408,   427,   248,    44,   234,   235,   302,   303,   401,
     402,    29,   228,   236,   200,   201,   271,   272,   273,   276,
     326,   367,   375,    54,   317,    53,   322,   264,    66,    67,
      69,    97,    98,    99,   100,   101,   102,   103,   377,   379,
     380,   383,   386,   387,   390,   391,   397,   399,   400,   401,
     402,   409,   412,   415,   417,   421,   425,   427,    79,    44,
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
     388,   389,   396,   398,    44,   304,   416,   269,   379,   379,
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
     356,   377,   427,   321,   265,   306,   306,   377,    45,    58,
     381,    59,   384,   390,   390,   390,   390,   390,   390,    71,
     309,    66,    67,   392,   395,   423,   424,    24,    68,   393,
     306,    45,    45,    45,   310,    53,    53,    53,    45,    45,
      53,    45,    45,    53,    45,    45,    45,    45,    53,    45,
      45,    53,    53,    45,    45,    45,    45,    45,    45,    53,
      45,    45,    45,    53,    45,    45,    45,    53,    45,    45,
      45,    45,    45,    53,    45,    45,    45,   379,   253,   238,
     401,    22,    23,   205,   206,   203,   283,   287,   281,   293,
     302,    44,   259,   297,   340,    44,    55,   105,   357,   362,
     363,   365,   427,   347,   330,   343,   346,    24,    41,    66,
     106,   348,   350,   354,   258,    24,   379,   411,   379,   383,
     386,   309,   397,   397,   393,   394,   399,   399,   379,   308,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   305,    42,    44,   174,   251,    24,    44,   209,
     210,   211,   212,   303,   377,   402,   409,   417,   421,   425,
     223,   284,   288,   269,   294,   379,   273,   269,    45,   360,
     361,   363,    55,   364,   427,   321,   107,   342,    68,   345,
      53,   153,   353,   366,    42,    45,   410,    45,    45,    53,
     307,    53,    45,    45,    45,    45,   307,   405,    45,    45,
      45,   405,    45,    45,   308,   252,   379,   210,   225,   376,
     289,   269,    94,   300,    45,   359,   336,   344,   349,   366,
      42,    53,   352,    54,   413,   414,   379,   379,    45,    45,
      45,    46,    47,   250,   254,   377,   417,   421,   425,   427,
     208,   192,   285,    19,   290,   377,    51,   298,   107,   358,
      54,   335,    42,    42,   351,   366,    80,    45,    45,    45,
     254,    45,   269,   376,    45,   299,   363,   331,   332,   334,
      42,    60,   269,   269,   333,   426,   321
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
     403,   404,   405,   405,   406,   407,   408,   409,   409,   410,
     409,   411,   411,   412,   412,   412,   412,   412,   413,   414,
     414,   415,   416,   416,   417,   418,   419,   419,   420,   420,
     421,   421,   421,   422,   422,   422,   423,   423,   423,   424,
     424,   424,   425,   425,   426,   426,   426,   426,   427,   427,
     428,   428,   429,   429
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
       1,     7,     0,     1,     7,     2,     3,     5,     5,     0,
       7,     1,     1,     1,     1,     1,     1,     1,     4,     0,
       1,     2,     0,     1,     2,     2,     1,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
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
  "SubstringExpression", "ExistsFunc", "NotExistsFunc", "Aggregate", "@36",
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
     178,   180,    -1,    -1,   179,   213,    -1,     3,   377,   417,
     417,    -1,     4,   417,    -1,     5,   417,    -1,     6,   417,
      -1,     7,   417,    -1,     8,   417,    -1,     9,   427,    -1,
      10,   185,    -1,    11,   181,    -1,    13,   184,    -1,    12,
      -1,    15,    -1,    14,    -1,    -1,   378,    -1,    41,   182,
      42,   375,    -1,   183,    -1,   184,   183,    -1,   186,   187,
      -1,    -1,   191,    -1,    -1,   188,    -1,    41,   190,    42,
      -1,   417,    48,   417,    -1,    -1,   190,   189,    -1,    56,
     417,    57,    -1,    -1,   247,    -1,   194,   195,    -1,    -1,
     196,    -1,    -1,   195,   197,    -1,    20,   166,    -1,    -1,
      -1,    21,   198,   167,   199,   166,    -1,    -1,    -1,    -1,
     201,   202,   204,   203,   223,   225,   192,    -1,    26,   206,
     212,    -1,    22,    -1,    23,    -1,    -1,   205,    -1,    94,
     377,    -1,    -1,   207,    -1,    44,   379,   208,    45,    -1,
     377,    -1,   409,    -1,   402,    -1,   303,    -1,   417,    -1,
     421,    -1,   425,    -1,   209,    -1,   210,    -1,   211,   210,
      -1,   211,    -1,    24,    -1,    -1,   216,    25,   255,   214,
     217,   223,   225,   192,    -1,    16,   378,    -1,    -1,   215,
      -1,    -1,   217,   218,    -1,    27,   219,    -1,   220,    -1,
     221,    -1,   222,    -1,    28,   222,    -1,   427,    -1,   224,
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
     253,   251,    -1,   427,    -1,   417,    -1,   421,    -1,   425,
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
     302,    -1,   401,    -1,   402,    -1,   303,    -1,   427,   304,
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
     356,    -1,   427,    -1,    55,    -1,    69,   357,    -1,    44,
     340,    45,    -1,   362,    -1,   107,   363,    -1,    -1,   359,
     358,    -1,   363,   359,    -1,    -1,   360,    -1,   363,    -1,
      44,   361,    45,    -1,   365,    -1,   427,    -1,    55,    -1,
     427,    -1,    55,    -1,   105,   364,    -1,   153,    -1,   370,
      -1,   368,    -1,    -1,    56,   369,   314,    57,    -1,   372,
      44,   373,    45,    -1,    36,    -1,    37,    -1,    38,    -1,
      39,    -1,    40,    -1,    -1,   371,    -1,   374,    -1,   373,
     374,    -1,   375,    -1,   367,    -1,   377,    -1,   378,    -1,
     377,    -1,   427,    -1,   171,    -1,   172,    -1,   427,    -1,
     417,    -1,   421,    -1,   425,    -1,   429,    -1,   174,    -1,
     380,    -1,   383,   382,    -1,    58,   383,    -1,    -1,   382,
     381,    -1,   386,   385,    -1,    59,   386,    -1,    -1,   385,
     384,    -1,   387,    -1,   390,   388,    -1,    -1,   389,    -1,
      60,   390,    -1,    61,   390,    -1,    62,   390,    -1,    63,
     390,    -1,    64,   390,    -1,    65,   390,    -1,    71,   309,
      -1,    70,    71,   309,    -1,   391,    -1,   397,   396,    -1,
     423,    -1,   424,    -1,    24,   399,    -1,    68,   399,    -1,
      -1,   393,    -1,    66,   397,    -1,    67,   397,    -1,   392,
     394,    -1,    -1,   396,   395,    -1,   399,   398,    -1,    -1,
     398,   393,    -1,    69,   400,    -1,    66,   400,    -1,    67,
     400,    -1,   400,    -1,   401,    -1,   402,    -1,   415,    -1,
     417,    -1,   421,    -1,   425,    -1,   377,    -1,   409,    -1,
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
     411,    45,    -1,   412,    44,   306,   379,    45,    -1,    -1,
     102,    44,   306,   379,   410,   414,    45,    -1,    24,    -1,
     379,    -1,    98,    -1,    99,    -1,   100,    -1,   101,    -1,
     103,    -1,    54,    80,    60,   426,    -1,    -1,   413,    -1,
     427,   416,    -1,    -1,   304,    -1,   426,   420,    -1,    92,
     427,    -1,   173,    -1,   418,    -1,    -1,   419,    -1,   422,
      -1,   423,    -1,   424,    -1,   153,    -1,   154,    -1,   155,
      -1,   156,    -1,   157,    -1,   158,    -1,   159,    -1,   160,
      -1,   161,    -1,   151,    -1,   152,    -1,   162,    -1,   164,
      -1,   163,    -1,   165,    -1,   166,    -1,   428,    -1,   168,
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
    1230,  1238,  1240,  1242,  1244,  1246,  1248,  1250,  1252,  1257,
    1258,  1260,  1263,  1264,  1266,  1269,  1272,  1274,  1276,  1277,
    1279,  1281,  1283,  1285,  1287,  1289,  1291,  1293,  1295,  1297,
    1299,  1301,  1303,  1305,  1307,  1309,  1311,  1313,  1315,  1317,
    1319,  1321,  1323,  1325
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  MapSetParser::yyrline_[] =
  {
         0,   463,   463,   463,   469,   471,   475,   477,   481,   490,
     493,   496,   499,   502,   505,   508,   510,   514,   520,   523,
     526,   532,   535,   539,   551,   552,   556,   559,   561,   564,
     566,   570,   574,   579,   581,   585,   592,   595,   600,   604,
     606,   610,   612,   616,   622,   624,   622,   634,   637,   640,
     634,   655,   663,   666,   673,   676,   681,   688,   691,   696,
     703,   706,   709,   712,   715,   718,   721,   725,   730,   733,
     741,   744,   751,   751,   763,   769,   772,   777,   780,   788,
     795,   796,   800,   806,   812,   819,   826,   828,   833,   840,
     843,   848,   851,   856,   859,   864,   868,   872,   879,   882,
     889,   892,   895,   898,   904,   910,   913,   920,   925,   932,
     936,   944,   946,   954,   957,   965,   973,   974,   981,   985,
     993,   996,  1001,  1004,  1008,  1014,  1021,  1021,  1029,  1031,
    1037,  1040,  1046,  1046,  1051,  1057,  1059,  1063,  1066,  1069,
    1072,  1075,  1078,  1081,  1087,  1093,  1093,  1101,  1103,  1107,
    1109,  1113,  1116,  1118,  1123,  1128,  1131,  1123,  1142,  1146,
    1149,  1151,  1156,  1156,  1167,  1168,  1173,  1177,  1179,  1189,
    1193,  1196,  1212,  1217,  1221,  1224,  1228,  1229,  1230,  1231,
    1232,  1233,  1234,  1235,  1241,  1241,  1257,  1261,  1263,  1257,
    1274,  1278,  1280,  1274,  1291,  1294,  1300,  1311,  1315,  1311,
    1325,  1329,  1325,  1339,  1339,  1351,  1353,  1357,  1367,  1368,
    1369,  1373,  1381,  1385,  1385,  1395,  1398,  1405,  1411,  1413,
    1427,  1430,  1430,  1440,  1440,  1443,  1443,  1450,  1455,  1459,
    1461,  1466,  1470,  1472,  1477,  1481,  1483,  1488,  1493,  1497,
    1499,  1503,  1510,  1514,  1522,  1522,  1525,  1525,  1531,  1531,
    1537,  1538,  1542,  1542,  1547,  1549,  1553,  1556,  1558,  1562,
    1566,  1570,  1576,  1580,  1584,  1587,  1589,  1593,  1597,  1602,
    1604,  1610,  1613,  1615,  1621,  1622,  1628,  1632,  1633,  1637,
    1638,  1642,  1643,  1647,  1648,  1649,  1650,  1654,  1658,  1661,
    1664,  1667,  1673,  1677,  1680,  1682,  1686,  1689,  1691,  1695,
    1696,  1700,  1704,  1705,  1709,  1710,  1711,  1715,  1720,  1721,
    1725,  1725,  1738,  1763,  1766,  1769,  1772,  1775,  1782,  1785,
    1790,  1794,  1801,  1802,  1806,  1809,  1813,  1816,  1822,  1823,
    1827,  1830,  1833,  1836,  1839,  1840,  1846,  1851,  1860,  1867,
    1870,  1878,  1887,  1894,  1897,  1904,  1909,  1920,  1923,  1927,
    1930,  1933,  1936,  1939,  1942,  1945,  1948,  1954,  1959,  1968,
    1971,  1978,  1981,  1988,  1991,  1996,  1999,  2003,  2017,  2020,
    2028,  2037,  2040,  2047,  2050,  2053,  2056,  2060,  2061,  2062,
    2063,  2066,  2069,  2072,  2075,  2079,  2085,  2088,  2091,  2094,
    2097,  2100,  2103,  2107,  2110,  2113,  2116,  2119,  2122,  2125,
    2128,  2129,  2132,  2135,  2138,  2141,  2144,  2147,  2150,  2153,
    2156,  2159,  2162,  2165,  2168,  2171,  2174,  2177,  2180,  2183,
    2186,  2189,  2192,  2195,  2198,  2201,  2204,  2208,  2211,  2214,
    2217,  2220,  2223,  2226,  2229,  2232,  2235,  2236,  2237,  2243,
    2246,  2253,  2260,  2263,  2267,  2273,  2280,  2287,  2291,  2296,
    2296,  2316,  2319,  2323,  2326,  2329,  2332,  2335,  2341,  2347,
    2350,  2354,  2364,  2367,  2372,  2380,  2387,  2391,  2399,  2403,
    2407,  2408,  2409,  2413,  2414,  2415,  2419,  2420,  2421,  2425,
    2426,  2427,  2431,  2432,  2436,  2437,  2438,  2439,  2443,  2444,
    2448,  2449,  2453,  2454
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
  const int MapSetParser::yylast_ = 2095;
  const int MapSetParser::yynnts_ = 255;
  const int MapSetParser::yyempty_ = -2;
  const int MapSetParser::yyfinal_ = 3;
  const int MapSetParser::yyterror_ = 1;
  const int MapSetParser::yyerrcode_ = 256;
  const int MapSetParser::yyntokens_ = 175;

  const unsigned int MapSetParser::yyuser_token_number_max_ = 429;
  const MapSetParser::token_number_type MapSetParser::yyundef_token_ = 2;


} // w3c_sw

/* Line 1136 of lalr1.cc  */
#line 4978 "lib/MapSetParser/MapSetParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 2460 "lib/MapSetParser/MapSetParser.ypp"
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


