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
#line 307 "lib/MapSetParser/MapSetParser.ypp"

#include "../MapSetScanner.hpp"

/* Line 299 of lalr1.cc  */
#line 447 "lib/MapSetParser/MapSetParser.ypp"

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
#line 462 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root = new MapSet();
	driver.root->sharedVars = MapSet::e_PROMISCUOUS;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
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

/* Line 690 of lalr1.cc  */
#line 489 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->driver = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 492 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->server = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 495 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->user = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 498 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->password = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 501 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->database = (yysemantic_stack_[(2) - (2)].p_RDFLiteral);
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 504 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->stemURI = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 509 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.sharedVarsSet = true;
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 513 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.lastRuleTermSet = false;
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 519 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_PROMISCUOUS;
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 522 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_VARNAMES;
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 525 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.root->sharedVars = MapSet::e_DRACONIAN;
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 531 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = NULL;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
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

/* Line 690 of lalr1.cc  */
#line 573 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->keyMap[(yysemantic_stack_[(3) - (1)].p_RDFLiteral)->getLexicalValue()] = (yysemantic_stack_[(3) - (3)].p_RDFLiteral)->getLexicalValue();
    }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 584 "lib/MapSetParser/MapSetParser.ypp"
    {
	static_cast<MapSet*>(driver.root)->primaryKey = (yysemantic_stack_[(3) - (2)].p_RDFLiteral);
    }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 607 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 613 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 615 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 617 "lib/MapSetParser/MapSetParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 625 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 628 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 632 "lib/MapSetParser/MapSetParser.ypp"
    {
	  if ((yysemantic_stack_[(6) - (6)].p_BindingClause) != NULL)
	      (yysemantic_stack_[(6) - (4)].p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yysemantic_stack_[(6) - (6)].p_BindingClause), (yysemantic_stack_[(6) - (4)].p_WhereClause)->m_GroupGraphPattern);
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(6) - (2)].p_Project).distinctness, (yysemantic_stack_[(6) - (2)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(6) - (4)].p_WhereClause), (yysemantic_stack_[(6) - (5)].p_SolutionModifier))));
	  driver.curGraphName = (yysemantic_stack_[(6) - (1)].p_TTerm);
      }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 641 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 649 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 657 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 660 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 667 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 675 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 682 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 690 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 697 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 700 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
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
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 712 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 715 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 724 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 727 "lib/MapSetParser/MapSetParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 735 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 738 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 745 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = NULL;
      }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
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

/* Line 690 of lalr1.cc  */
#line 757 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(2) - (2)].p_TTerm);
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 763 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = NULL;
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 771 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 774 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 782 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 794 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 800 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 806 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 813 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.ensureGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 827 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 834 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 842 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 850 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 858 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 866 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 873 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 876 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 883 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
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
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 892 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 898 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 904 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 907 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 919 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 926 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 930 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 940 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 948 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 951 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 959 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 968 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 975 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 979 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 987 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 995 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1002 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1008 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1015 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1017 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1025 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1031 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1034 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1040 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.startBindingRow(); // @@ push down to _Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star?
      }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1042 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1045 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1057 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1060 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1063 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1066 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1069 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
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
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1081 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_BasicGraphPattern) = (yysemantic_stack_[(3) - (2)].p_BasicGraphPattern);
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1087 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1089 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1115 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1120 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1123 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1126 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1148 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1150 "lib/MapSetParser/MapSetParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1227 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.ensureGraphPattern(), (yysemantic_stack_[(1) - (1)].p_BindingClause)) : (yysemantic_stack_[(1) - (1)].p_BindingClause);
    }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1233 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1237 "lib/MapSetParser/MapSetParser.ypp"
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

  case 185:

/* Line 690 of lalr1.cc  */
#line 1249 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1253 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1255 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1258 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1266 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1270 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1272 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1275 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(7) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(7) - (6)].p_TTerm), driver.curOp, (yysemantic_stack_[(7) - (5)].p_Silence), driver.atomFactory, false));
	  driver.curGraphName = (yysemantic_stack_[(7) - (4)].p_TTerm);
      }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1283 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1286 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1292 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = new Bind(driver.ensureGraphPattern(), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1298 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1302 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1304 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1312 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1316 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1318 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1326 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1331 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.ensureGraphPattern());
      }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1344 "lib/MapSetParser/MapSetParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    driver.ensureGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1360 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1368 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 1372 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1375 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yysemantic_stack_[(6) - (4)].p_Expressions);
      }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 1382 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 1385 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 1392 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 1400 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 1414 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1417 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 1420 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(5) - (3)].p_Expressions);
      }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1427 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 1430 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 1490 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 1497 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 1501 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 1509 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 1512 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 1518 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 251:

/* Line 690 of lalr1.cc  */
#line 1529 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 1557 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 1584 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 1591 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 1602 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 1609 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 1645 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 1648 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 1651 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 1654 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 1712 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 1716 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 1725 "lib/MapSetParser/MapSetParser.ypp"
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

  case 312:

/* Line 690 of lalr1.cc  */
#line 1750 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 1753 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 1756 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 1759 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 1762 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 1769 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 1777 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 1781 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 1793 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 1800 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 1803 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 1814 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 1817 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 1820 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 1823 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 1827 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 1838 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 1847 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 1854 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 1857 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 1865 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 1874 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 1881 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 1884 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 1896 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_GeneralComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_GeneralComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_GeneralComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 1907 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 1914 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 1917 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 1920 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 1923 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 1926 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 1929 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 1932 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 1935 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 1946 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 1955 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 1958 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 1965 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 1968 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 1975 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 1983 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 1986 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 1990 "lib/MapSetParser/MapSetParser.ypp"
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

  case 367:

/* Line 690 of lalr1.cc  */
#line 2004 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 368:

/* Line 690 of lalr1.cc  */
#line 2007 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 2015 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 2024 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 2027 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 2034 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 2037 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 2040 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 2050 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 2053 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 2056 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 2059 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 2066 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 2072 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 2075 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 2078 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 2081 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 2084 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 2087 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 2090 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 2094 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 2097 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 2100 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 2103 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ciel, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 2106 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 2109 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 2112 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 2116 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 2119 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 2122 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 2125 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 2128 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 2131 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 2134 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 2137 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 2140 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 2143 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 2146 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 2149 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 2152 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 2155 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 2158 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 2161 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 2164 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 2167 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 2170 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 2173 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 2176 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 2179 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 2182 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 2185 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 2189 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 2192 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 2195 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 2198 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 2201 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 2204 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 2207 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 2210 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 2213 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 2224 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 2227 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 2234 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 2241 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 2248 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 2254 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.ensureGraphPattern(), NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 2261 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.ensureGraphPattern(), NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 2268 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 2271 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 2275 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 2278 "lib/MapSetParser/MapSetParser.ypp"
    {
	  // x = new ArgList($2, driver.curExprList);
	  delete driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(7) - (5)].p_Expressions);
	  w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // $$ = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group-concat, $3, $4.p_Expression, $4.separator));
    }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 2288 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
	driver.countStar = true;
    }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 2296 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 2299 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 2302 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 2305 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 2308 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 2314 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 2320 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 2327 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 2337 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 2345 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 2353 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 2360 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 2364 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 2372 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 690 of lalr1.cc  */
#line 3234 "lib/MapSetParser/MapSetParser.cpp"
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
  const short int MapSetParser::yypact_ninf_ = -673;
  const short int
  MapSetParser::yypact_[] =
  {
      -673,    40,    26,  -673,  -114,  -673,  -673,  -673,  -673,   348,
      37,   -78,    89,    89,    89,    89,    89,   116,     7,   204,
      39,    50,  -673,  -673,  -673,  -673,  -673,    89,  -673,  -673,
    -673,  -673,  -673,   -61,  -673,  -673,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,    89,  -673,    44,  -673,  -673,  -673,  -673,
    -673,  1371,  -673,    39,  1371,  -673,  -673,    64,   -69,    89,
     116,  -673,  -673,  -673,  -673,    43,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,    80,  -673,  -673,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,    85,  -673,  -673,  -673,  -673,
      82,   919,  -673,  -673,   -30,  -673,  -673,    91,  -673,  -673,
    -673,   102,  1308,  -673,  -673,    89,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,    98,  -673,  -673,  -673,  -673,
     125,  -673,    17,  -673,   109,   158,  1308,  -673,  -673,   109,
    1401,   109,    -5,  -673,  -673,    96,   145,  -673,   143,  1401,
    -673,  -673,  -673,  -673,   159,   193,  -673,  -673,  -673,  -673,
    -673,  1347,  -673,  -673,  -673,   116,  -673,  -673,  -673,  -673,
    -673,   181,   179,   133,  -673,  -673,  -673,  -673,  -673,  -673,
    -673,  -673,  1308,    54,  -673,  -673,  -673,  1905,  -673,  -673,
    -673,  2012,   207,  -673,  1140,   187,   190,  -673,  -673,  1530,
     170,   212,   214,   -23,   -19,   215,   227,   234,   145,   247,
     248,   256,   258,   259,   268,   269,   270,   274,   275,   276,
     -19,   277,   280,   281,   283,   288,   163,   289,   164,   296,
     298,   299,   300,   301,   302,   303,   304,   316,   318,   319,
     321,   322,   324,   325,   326,   327,   328,   329,   330,   331,
     332,  1905,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,
     -16,  -673,  1530,  2012,  -673,  -673,  -673,  -673,  -673,   347,
      71,  -673,  -673,   353,   341,  -673,  -673,  -673,   336,  -673,
    -673,   109,  -673,  1401,  -673,   345,  1655,  1655,  1655,   344,
    -673,  -673,  -673,  -673,   346,  -673,  -673,   295,  -673,  -673,
    -673,  -673,   245,  -673,  -673,  -673,  -673,  -673,  -673,  -673,
     350,  -673,  -673,  -673,  -673,   -16,   145,  1530,  1530,  1530,
    -673,  -673,  1530,  -673,  -673,  1530,  1530,  1530,  -673,  1530,
    1530,  1530,  1530,   -78,  1530,  1530,  1530,  1530,  1530,  1530,
    -673,  1530,  1530,  1530,  1530,  1530,  -673,  1530,  -673,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  -673,   369,  -673,  -673,   -24,   351,  -673,  1284,   239,
     242,  -673,  -673,   363,   365,    93,  -673,  -673,    12,  1308,
    -673,  -673,   109,    27,  -673,  -673,  1401,  -673,  -673,  -673,
    -673,  -673,   369,   369,   -78,  -673,   354,   342,   343,  1530,
    1530,  1530,  1530,  1530,  1530,   333,   -19,  -673,  -673,   137,
       9,   369,  -673,  -673,  -673,   356,   358,   360,  -673,   355,
     357,   359,   361,   364,   362,   368,   371,   366,   372,   373,
     375,   376,   370,   377,   380,   374,   378,   383,   384,   387,
     388,   389,   391,   386,   397,   398,   401,   395,   405,   406,
     408,   403,   409,   412,   413,   414,   415,   410,   416,   419,
     420,  -673,  1530,  -673,  -673,  -673,  -673,  -673,  1284,  -673,
     422,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  1116,   425,  -673,  -673,  -673,  -673,
    2012,   426,  -673,  -673,   159,  -673,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,   168,  -673,    13,   101,
    -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,    15,
    -673,  -673,  -673,  -673,  1308,   879,  1530,  -673,  -673,  1530,
    -673,  1530,  -673,  -673,  -673,  -673,  -673,  -673,  -673,   -19,
    -673,  1530,  1530,     9,  -673,  -673,  -673,  1530,  1530,  -673,
    1530,  -673,  -673,  -673,  -673,  1530,  1530,  1530,  -673,  -673,
    1530,  -673,  -673,  1530,  -673,  -673,  -673,  -673,  1530,  -673,
    -673,  1530,  1530,  -673,  -673,  -673,  -673,  -673,  -673,  1530,
    -673,  -673,  -673,  1530,  -673,  -673,  -673,  1530,  -673,  -673,
    -673,  -673,  -673,  1530,  -673,  -673,  -673,  -673,   -20,  -673,
    -673,  -673,  1530,  -673,  -673,  1780,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,    96,  -673,  -673,   145,  -673,  -673,
    1530,  1308,   145,   424,   119,  -673,   122,  -673,  -673,  -673,
    -673,  -673,  -673,  1401,   307,   404,  -673,   -18,  -673,  -673,
    -673,  -673,  -673,   429,  -673,  -673,   428,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,  -673,   430,    25,   421,
     431,   432,   433,   434,   427,   436,   437,   439,   427,   441,
     442,  -673,  -673,  -673,  -673,  -673,   295,  -673,   179,    54,
    -673,  -673,   145,   394,  -673,  -673,  -673,  -673,   444,  -673,
    -673,  -673,  -673,  -673,   168,  -673,   168,  -673,   337,  -673,
    -673,     1,  -673,  -673,   438,  -673,  -673,  1530,  -673,  1530,
    -673,  -673,  -673,  -673,  -673,   446,  -673,  -673,  -673,   448,
    -673,  -673,    34,   754,   449,  -673,  -673,   477,  -673,   -78,
     447,  -673,   390,   445,  -673,  -673,   458,  -673,   -10,  -673,
     423,  -673,   456,  -673,   457,  -673,  -673,  -673,  -673,  -673,
     484,  -673,  -673,  -673,  -673,  -673,  -673,  -673,   145,  -673,
      54,   459,  -673,  -673,   119,  -673,    27,  -673,  -673,  -673,
    -673,   463,   450,  -673,  -673,  -673,  -673,  -673,   145,  -673,
     145,  -673,  -673,  -673,  -673,  -673,    89,  -673,  -673,  1401,
    -673,  -673
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  MapSetParser::yydefact_[] =
  {
         2,     0,    37,     1,     0,     4,    39,    38,    41,     6,
      36,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     3,     5,    42,    40,   327,   328,     0,   481,   483,
     482,   484,     9,   465,    10,    11,    12,    13,   485,   488,
     487,    14,   486,     0,    15,    29,    28,    18,    20,    19,
      16,    21,    24,    17,     0,     7,    75,     0,     0,     0,
       0,   463,   464,   466,   461,     0,    33,    26,    30,   479,
     480,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     489,   490,   334,     0,    22,   330,   331,   467,   468,   469,
     332,   329,   333,    25,    73,     0,    43,     8,   462,    35,
       0,     0,   144,    71,     0,    31,    34,     0,    23,   323,
     324,     0,   146,    76,    44,     0,   143,   312,   313,   314,
     315,   316,   309,   151,   147,   159,   224,   308,   307,   318,
       0,   222,    85,    32,     0,   145,   146,   160,   157,   234,
     317,     0,     0,    86,    77,    88,     0,   242,     0,   317,
     241,   325,   326,   152,   148,     0,   158,   235,   225,   233,
     322,   317,   319,   321,   223,     0,    78,    79,    80,    81,
      83,     0,    48,    90,    89,   161,    84,   310,   231,   238,
     240,   149,   146,     0,   311,   320,    82,     0,   125,    72,
      49,     0,    92,    91,   166,   226,   236,   150,   154,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,   100,   102,    99,   433,   399,   434,   435,
       0,   127,     0,   103,   104,   106,   209,   207,   208,     0,
      94,    93,   163,     0,     0,   164,   169,   167,   173,   245,
     243,   228,   232,   317,   239,     0,     0,     0,     0,     0,
     450,   451,   452,   453,     0,   454,   382,    56,   335,   338,
     342,   344,   346,   356,   367,   370,   375,   376,   377,   383,
       0,   378,   379,   380,   381,   459,     0,     0,     0,     0,
     437,   392,     0,   219,   423,     0,     0,     0,   442,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     398,     0,     0,     0,     0,     0,   393,     0,   417,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,   214,   211,   210,     0,     0,   105,     0,     0,
       0,    87,    95,   119,   121,    53,    46,   162,   165,   166,
     174,   171,   234,     0,   229,   230,   317,   237,   155,   373,
     374,   372,   214,   214,     0,    57,     0,   336,   340,     0,
       0,     0,     0,     0,     0,     0,     0,   345,   347,   357,
     369,   214,   460,   458,   443,     0,     0,     0,   220,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   215,     0,   134,   128,   384,   112,   113,   107,   108,
       0,   110,   111,   115,   116,   123,   124,   117,   120,   118,
     122,    51,    52,    54,     0,    85,   185,   189,   183,   196,
       0,     0,   182,   170,   148,   176,   178,   179,   181,   177,
     175,   200,   180,   172,   258,   246,     0,   288,     0,     0,
     244,   247,   249,   250,   259,   261,   264,   273,   268,   271,
     286,   260,   287,   227,   146,     0,     0,    55,   101,     0,
     339,     0,   343,   348,   349,   350,   351,   352,   353,     0,
     354,     0,     0,   362,   368,   358,   359,     0,     0,   371,
       0,   390,   391,   436,   217,     0,     0,     0,   385,   386,
       0,   388,   389,     0,   428,   429,   430,   431,     0,   432,
     418,     0,     0,   409,   422,   416,   415,   397,   421,     0,
     414,   396,   413,     0,   420,   412,   403,     0,   395,   411,
     402,   394,   401,     0,   400,   419,   410,   212,     0,   109,
     114,    70,     0,    66,    67,    69,    50,    62,    59,    61,
      60,    63,    64,    65,    88,   186,   190,     0,   197,   206,
       0,   166,     0,     0,   296,   304,     0,   289,   291,   298,
     300,   303,   274,   317,   262,   266,   282,     0,   284,   283,
     270,   272,   275,     0,   448,   449,     0,   446,   337,   341,
     355,   364,   365,   363,   366,   360,   361,     0,     0,     0,
       0,     0,     0,     0,   439,     0,     0,     0,   439,     0,
       0,   217,   126,   131,   133,   135,    56,    68,    48,     0,
     191,   184,     0,     0,   168,   204,   290,   297,     0,   293,
     302,   305,   301,   256,     0,   265,     0,   269,     0,   306,
     285,     0,   156,   444,   456,   445,   221,     0,   218,     0,
     425,   426,   387,   427,   440,     0,   407,   408,   404,     0,
     405,   406,     0,     0,     0,    47,   187,   193,   198,     0,
     201,   299,   295,   248,   263,   267,     0,   279,     0,   280,
       0,   457,     0,   216,     0,   438,   441,   213,   140,   141,
       0,   129,   142,   137,   138,   139,   136,    58,     0,   194,
       0,     0,   202,   205,     0,   294,   253,   257,   281,   276,
     278,     0,     0,   447,   424,   132,   130,   188,     0,   195,
       0,   292,   251,   254,   255,   277,     0,   192,   203,   317,
     455,   252
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yypgoto_[] =
  {
      -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,   453,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,  -673,  -180,  -673,  -673,
    -673,  -673,  -175,  -673,  -106,  -673,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,   349,    18,  -673,  -112,
    -673,  -673,  -673,  -673,  -673,  -673,   264,  -673,  -673,   253,
    -673,  -673,    41,  -673,  -673,  -673,  -673,  -673,  -673,   134,
     139,   129,  -673,  -673,  -673,  -673,  -673,  -673,  -240,  -673,
    -673,  -673,  -127,    20,  -673,  -673,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,  -197,  -673,  -673,  -673,  -374,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,  -341,  -168,   213,  -673,
    -354,  -605,  -154,  -208,  -673,  -673,  -673,  -673,   -46,  -673,
    -673,  -673,  -673,  -673,   140,  -388,  -673,  -673,   250,   254,
    -673,  -673,  -673,  -673,  -673,  -242,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,    21,  -673,  -673,  -673,  -166,  -673,
    -673,    22,  -673,  -170,  -673,  -673,  -673,  -673,  -673,  -673,
    -673,  -673,  -673,  -673,  -673,  -673,  -673,  -621,  -673,  -673,
    -672,  -110,  -673,  -673,  -673,  -673,  -673,  -673,  -102,   -85,
    -182,   -11,    60,   532,  -673,  -673,  -673,     0,  -673,  -673,
      -1,  -673,  -673,  -673,  -148,  -673,  -673,    -8,  -673,  -673,
    -673,  -418,  -673,  -392,   -54,  -150,  -177,  -673,  -673,  -135,
    -673,  -673,  -673,  -474,  -673,  -673,  -673,  -673,  -673,  -673,
    -673,    -9,  -673,  -673,  -673,    56,  -673,   128,   130,    66,
    -252,    48,  -673,  -673
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yydefgoto_[] =
  {
        -1,     1,     2,     9,    21,    22,    50,    83,    52,    53,
      44,    45,    67,    68,   106,   100,    46,     5,     6,    10,
       7,    24,    58,   104,   272,   273,   495,   189,   386,   493,
     494,   405,   406,   613,   614,   615,   616,    55,   113,    56,
      57,   132,   144,   166,   167,   168,   169,   145,   146,   172,
     173,   192,   270,   381,   174,   251,   252,   193,   263,   264,
     271,   478,   479,   480,   481,   482,   382,   487,   489,   383,
     384,   190,   261,   375,   760,   685,   733,   608,   761,   103,
     111,   112,   123,   182,   153,   135,   154,   155,   285,   534,
     124,   137,   138,   176,   194,   274,   275,   276,   503,   388,
     277,   390,   391,   504,   505,   627,   506,   625,   689,   768,
     507,   626,   690,   737,   770,   508,   509,   628,   692,   510,
     511,   632,   773,   790,   740,   512,   265,   266,   374,   681,
     472,   718,   668,   324,   564,   125,   141,   139,   157,   394,
     395,   282,   195,   158,   159,   178,   284,   196,   179,   149,
     278,   393,   392,   520,   643,   521,   793,   799,   794,   777,
     743,   515,   522,   523,   524,   525,   705,   644,   526,   707,
     645,   527,   650,   528,   651,   780,   749,   710,   652,   529,
     530,   637,   775,   742,   697,   698,   638,   639,   701,   640,
     711,   160,   127,   134,   128,   129,   130,   161,   180,   163,
     150,   296,   110,   297,   298,   540,   407,   299,   542,   408,
     300,   301,   417,   418,   302,   303,   553,   559,   664,   554,
     419,   304,   420,   305,   306,   307,   308,   321,   256,   725,
     257,   258,   259,   309,   714,   656,   310,   751,   752,   311,
     423,   312,    62,    63,    64,   313,    87,    88,    89,   314,
      33,   315,    42,    92
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int MapSetParser::yytable_ninf_ = -318;
  const short int
  MapSetParser::yytable_[] =
  {
        27,   198,   126,    32,    34,    35,    36,    37,   533,   156,
     255,   328,   340,   699,   268,   513,   108,   473,    59,   253,
     620,   319,   682,   165,   683,   322,   126,   131,   372,   496,
     497,    60,   779,   557,    65,   708,   746,   483,   162,   646,
       3,   267,    85,   747,   142,    85,     4,   188,   535,   536,
      97,   131,     8,  -199,   748,   197,   647,   634,    23,   185,
     143,   498,   499,    43,   500,    41,    54,   560,   635,   724,
     716,   516,   126,   724,   255,   -74,   781,   558,   717,   757,
      51,   648,   517,   253,   279,    66,   268,   717,   148,    95,
     109,   107,    85,    25,    26,   164,   518,   131,    96,    91,
      99,   109,    91,    85,   379,   380,   133,    86,    98,   280,
      86,    84,    61,   267,    94,   491,   492,    90,   636,   424,
      90,   649,   101,   151,   105,   109,   102,    85,   151,   109,
     151,    85,   519,   661,   662,   709,   114,   483,   109,   115,
      85,   620,   501,   709,   116,   516,   136,    25,    26,    91,
     109,   320,    85,   791,   684,   323,   517,    86,   373,   629,
      91,    38,    39,    40,   147,   665,   666,    90,    86,   140,
     518,   109,   151,    85,   635,  -153,   254,   700,    90,    38,
      39,    40,   152,   109,    91,    85,   175,   152,    91,   152,
     170,   171,    86,    38,    39,    40,    86,    91,    25,    26,
     177,   268,    90,   551,   552,    86,    90,   181,   550,    91,
     183,   187,   516,   170,   188,    90,    47,    86,    48,    49,
      38,    39,    40,   517,   636,    25,    26,    90,   267,   191,
      91,   152,   399,   400,   401,   260,   269,   518,    86,   260,
     254,   281,    91,   283,    28,    29,    30,    31,    90,   316,
      86,    28,    29,    30,    31,   703,   317,   694,   318,   325,
      90,   543,   544,   545,   546,   547,   548,    38,    39,    40,
     151,   326,   109,   519,    85,    38,    39,    40,   327,   279,
      25,    26,    38,    39,    40,    38,    39,    40,    38,    39,
      40,   329,   330,    74,    75,    76,    77,    78,    79,   260,
     331,   268,   332,   333,   280,   409,   410,   411,   412,   413,
     414,   260,   334,   335,   336,   415,   416,   619,   337,   338,
     339,   341,   436,   268,   342,   343,   617,   344,   267,   152,
     610,    91,   345,   347,    38,    39,    40,   346,   348,    86,
     349,   660,   350,   351,   352,   353,   354,   355,   356,    90,
     267,    11,    12,    13,    14,    15,    16,    17,    18,    19,
     357,    20,   358,   359,   474,   360,   361,   484,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   378,   109,   385,
      85,   151,   531,   387,   389,   109,   398,    85,   402,   404,
     403,   471,   485,   537,   421,   486,   475,   380,   379,   538,
     539,   561,   541,   562,   549,   563,   568,   653,   565,   569,
     566,   801,   567,   571,   704,   570,   572,   574,   575,   573,
     576,   577,   579,   578,   126,   580,   260,   581,   583,   584,
     691,   582,   585,   586,   587,   695,   588,    91,   619,   589,
     152,   532,   590,   591,    91,    86,   592,   617,   593,   131,
     594,   595,    86,   596,   598,    90,   597,   599,   600,   601,
     602,   604,    90,   603,   605,   606,   262,   484,   143,   696,
     630,   712,   706,   713,   719,   715,   720,   721,   722,   723,
     717,   726,   727,   618,   728,   621,   730,   731,   739,   741,
     709,   755,   750,   756,   767,   738,   769,   774,   772,   776,
     778,   783,   784,   782,   789,   795,    93,   736,   735,   687,
     796,   734,   688,   624,   186,   371,   377,   502,   490,   609,
     786,   279,   488,   109,   631,    85,   260,   732,   422,   785,
     758,   759,   514,   397,   792,   396,   745,   633,   744,   658,
     659,   642,   260,   729,   800,   663,   280,   555,   260,   556,
     622,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     623,     0,     0,     0,   532,     0,   641,   532,     0,     0,
       0,   787,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,   788,     0,
      86,   797,     0,   798,     0,     0,     0,     0,     0,     0,
      90,     0,     0,     0,   618,     0,   621,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,     0,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   109,     0,    85,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    28,    29,    30,    31,
      38,    39,    40,     0,     0,    25,    26,     0,     0,     0,
       0,     0,     0,   260,     0,     0,     0,     0,     0,     0,
       0,   622,     0,     0,     0,     0,     0,     0,   151,    91,
       0,   623,   641,     0,   702,     0,     0,    86,     0,     0,
       0,    91,     0,     0,     0,     0,     0,    90,     0,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   762,     0,   763,     0,     0,     0,   771,     0,
       0,     0,     0,     0,     0,     0,     0,   152,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   762,
       0,   763,   532,     0,   532,     0,     0,     0,     0,   151,
       0,     0,     0,     0,     0,   531,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   766,     0,     0,     0,     0,     0,     0,   109,   764,
      85,     0,     0,     0,   376,     0,     0,     0,     0,   765,
     758,   759,     0,     0,     0,     0,     0,     0,   766,     0,
       0,     0,     0,     0,     0,     0,   764,     0,   152,     0,
       0,     0,   641,     0,   532,     0,   765,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    91,     0,   425,
     426,   427,     0,     0,   428,    86,     0,   429,   430,   431,
       0,   432,   433,   434,   435,    90,   437,   438,   439,   440,
     441,   442,     0,   443,   444,   445,   446,   447,     0,   448,
       0,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   654,     0,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    28,    29,    30,    31,
      38,    39,    40,   262,     0,    25,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   286,   287,     0,   288,   200,
       0,   201,   202,   203,   204,   205,   206,   207,   208,     0,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     0,   220,     0,     0,     0,   289,   290,   291,   292,
     293,   294,   295,   221,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   222,     0,   223,   224,   225,     0,     0,
     226,   227,     0,   228,   607,   229,   230,   231,   232,     0,
     233,   234,     0,   235,     0,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    28,    29,    30,    31,    38,    39,    40,     0,     0,
      25,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   655,   657,     0,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    28,    29,    30,    31,    38,    39,    40,    80,    81,
      25,    26,   667,    82,     0,     0,     0,   669,   670,   671,
       0,     0,   672,     0,     0,   673,     0,     0,     0,     0,
     674,     0,     0,   675,   676,     0,     0,     0,     0,     0,
       0,   677,     0,     0,     0,   678,     0,     0,     0,   679,
       0,     0,     0,     0,     0,   680,     0,     0,     0,     0,
     611,     0,     0,     0,   686,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     612,     0,   693,     0,     0,     0,   -45,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   117,   118,   119,   120,
     121,     0,     0,     0,  -317,     0,   200,     0,   201,   202,
     203,   204,   205,   206,   207,   208,   122,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,     0,   220,
       0,     0,     0,   289,   290,   291,   292,   293,   294,   295,
     221,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     222,     0,   223,   224,   225,     0,     0,   226,   227,     0,
     228,     0,   229,   230,   231,   232,     0,   233,   234,   753,
     235,   754,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    28,    29,
      30,    31,    38,    39,    40,     0,     0,    25,    26,     0,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    28,    29,    30,    31,    38,    39,    40,    80,
      81,    25,    26,     0,    82,   476,   477,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   262,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   117,   118,   119,   120,   121,     0,
       0,     0,  -317,     0,   200,     0,   201,   202,   203,   204,
     205,   206,   207,   208,   122,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,     0,   220,     0,     0,
       0,     0,     0,   117,   118,   119,   120,   121,   221,     0,
       0,     0,   184,     0,     0,     0,     0,     0,   222,     0,
     223,   224,   225,   122,     0,   226,   227,     0,   228,     0,
     229,   230,   231,   232,     0,   233,   234,     0,   235,     0,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,     0,     0,   117,   118,   119,
     120,   121,     0,     0,     0,     0,     0,     0,     0,     0,
      38,    39,    40,     0,     0,    25,    26,   122,     0,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      28,    29,    30,    31,    38,    39,    40,    80,    81,    25,
      26,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    28,
      29,    30,    31,    38,    39,    40,    80,    81,    25,    26,
       0,    82,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    28,    29,    30,    31,    38,    39,    40,
      80,    81,     0,     0,     0,    82,     0,     0,     0,     0,
       0,     0,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    28,    29,    30,    31,    38,    39,    40,
      80,    81,    25,    26,   262,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   286,   287,     0,   288,
     200,     0,   201,   202,   203,   204,   205,   206,   207,   208,
       0,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,     0,   220,     0,     0,     0,   289,   290,   291,
     292,   293,   294,   295,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   222,     0,   223,   224,   225,     0,
       0,   226,   227,     0,   228,     0,   229,   230,   231,   232,
       0,   233,   234,     0,   235,     0,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    28,    29,    30,    31,    38,    39,    40,   262,
       0,    25,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   200,     0,   201,   202,   203,
     204,   205,   206,   207,   208,     0,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,     0,   220,     0,
       0,     0,   289,   290,   291,   292,   293,   294,   295,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   222,
       0,   223,   224,   225,     0,     0,   226,   227,     0,   228,
       0,   229,   230,   231,   232,     0,   233,   234,     0,   235,
       0,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    28,    29,    30,
      31,    38,    39,    40,   612,     0,    25,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     200,     0,   201,   202,   203,   204,   205,   206,   207,   208,
       0,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,     0,   220,     0,     0,     0,   289,   290,   291,
     292,   293,   294,   295,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   222,     0,   223,   224,   225,     0,
       0,   226,   227,     0,   228,     0,   229,   230,   231,   232,
       0,   233,   234,     0,   235,     0,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    28,    29,    30,    31,    38,    39,    40,   199,
       0,    25,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   200,     0,   201,   202,   203,
     204,   205,   206,   207,   208,     0,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,     0,   220,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   222,
       0,   223,   224,   225,     0,     0,   226,   227,     0,   228,
       0,   229,   230,   231,   232,     0,   233,   234,     0,   235,
       0,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   262,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,    39,    40,     0,     0,    25,    26,     0,     0,
       0,     0,   200,     0,   201,   202,   203,   204,   205,   206,
     207,   208,     0,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,     0,   220,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   221,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   222,     0,   223,   224,
     225,     0,     0,   226,   227,     0,   228,     0,   229,   230,
     231,   232,     0,   233,   234,     0,   235,     0,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    39,
      40
  };

  /* YYCHECK.  */
  const short int
  MapSetParser::yycheck_[] =
  {
        11,   183,   112,    12,    13,    14,    15,    16,   396,   136,
     187,   208,   220,   634,   191,   389,   101,    41,    27,   187,
     494,    44,    42,    28,    44,    44,   136,   112,    44,    17,
      18,    92,    42,    24,    43,    53,   708,   378,   140,    24,
       0,   191,    51,    42,    27,    54,    20,    35,   402,   403,
      59,   136,   166,    41,    53,   182,    41,    44,    21,   161,
      43,    49,    50,    56,    52,    17,    16,   421,    55,   674,
      45,    44,   182,   678,   251,    25,   748,    68,    53,    45,
      41,    66,    55,   251,   194,    41,   263,    53,   134,    25,
     101,   100,   101,   171,   172,   141,    69,   182,   167,    51,
      57,   112,    54,   112,    33,    34,   115,    51,    60,   194,
      54,    51,   173,   263,    54,    22,    23,    51,   105,   316,
      54,   106,    42,   134,    42,   136,    41,   136,   139,   140,
     141,   140,   105,   551,   552,   153,   166,   478,   149,    48,
     149,   615,   130,   153,    42,    44,    48,   171,   172,   101,
     161,   174,   161,   774,   174,   174,    55,   101,   174,   500,
     112,   166,   167,   168,    55,   557,   558,   101,   112,    44,
      69,   182,   183,   182,    55,    17,   187,    55,   112,   166,
     167,   168,   134,   194,   136,   194,    41,   139,   140,   141,
     142,    95,   136,   166,   167,   168,   140,   149,   171,   172,
      57,   378,   136,    66,    67,   149,   140,    48,   416,   161,
      17,    30,    44,   165,    35,   149,    12,   161,    14,    15,
     166,   167,   168,    55,   105,   171,   172,   161,   378,    96,
     182,   183,   286,   287,   288,   187,    29,    69,   182,   191,
     251,    54,   194,    53,   162,   163,   164,   165,   182,    79,
     194,   162,   163,   164,   165,   643,    44,   631,    44,    44,
     194,   409,   410,   411,   412,   413,   414,   166,   167,   168,
     281,    44,   283,   105,   283,   166,   167,   168,    44,   389,
     171,   172,   166,   167,   168,   166,   167,   168,   166,   167,
     168,    44,    44,   156,   157,   158,   159,   160,   161,   251,
      44,   478,    44,    44,   389,    60,    61,    62,    63,    64,
      65,   263,    44,    44,    44,    70,    71,   494,    44,    44,
      44,    44,   333,   500,    44,    44,   494,    44,   478,   281,
     480,   283,    44,    44,   166,   167,   168,   174,   174,   283,
      44,   549,    44,    44,    44,    44,    44,    44,    44,   283,
     500,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      44,    13,    44,    44,   375,    44,    44,   378,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    30,   389,    26,
     389,   392,   393,    42,    48,   396,    41,   396,    44,    94,
      44,    22,   153,   404,    44,   153,    45,    34,    33,    45,
      58,    45,    59,    45,    71,    45,    45,   534,    53,    45,
      53,   799,    53,    45,   107,    53,    45,    45,    45,    53,
      45,    45,    45,    53,   534,    45,   378,    53,    45,    45,
     627,    53,    45,    45,    45,   632,    45,   389,   615,    53,
     392,   393,    45,    45,   396,   389,    45,   615,    53,   534,
      45,    45,   396,    45,    45,   389,    53,    45,    45,    45,
      45,    45,   396,    53,    45,    45,    44,   478,    43,    45,
      44,    42,    68,    45,    53,    45,    45,    45,    45,    45,
      53,    45,    45,   494,    45,   494,    45,    45,    94,    45,
     153,    45,    54,    45,    45,   692,    19,   107,    51,    54,
      42,    45,    45,    80,    45,    42,    53,   689,   688,   615,
      60,   686,   624,   495,   165,   251,   263,   388,   384,   478,
     760,   631,   383,   534,   504,   534,   478,   681,   315,    45,
      46,    47,   392,   283,   776,   281,   706,   516,   704,   539,
     541,   519,   494,   678,   796,   553,   631,   419,   500,   419,
     494,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     494,    -1,    -1,    -1,   516,    -1,   518,   519,    -1,    -1,
      -1,   768,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   534,    -1,    -1,    -1,    -1,    -1,   770,    -1,
     534,   788,    -1,   790,    -1,    -1,    -1,    -1,    -1,    -1,
     534,    -1,    -1,    -1,   615,    -1,   615,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     631,    -1,   631,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   643,    -1,   643,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    -1,    -1,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,   615,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   615,    -1,    -1,    -1,    -1,    -1,    -1,   689,   631,
      -1,   615,   634,    -1,   636,    -1,    -1,   631,    -1,    -1,
      -1,   643,    -1,    -1,    -1,    -1,    -1,   631,    -1,   643,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   643,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   733,    -1,   733,    -1,    -1,    -1,   739,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   689,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   760,
      -1,   760,   704,    -1,   706,    -1,    -1,    -1,    -1,   770,
      -1,    -1,    -1,    -1,    -1,   776,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   733,    -1,    -1,    -1,    -1,    -1,    -1,   799,   733,
     799,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,   733,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,   760,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   760,    -1,   770,    -1,
      -1,    -1,   774,    -1,   776,    -1,   760,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   799,    -1,   317,
     318,   319,    -1,    -1,   322,   799,    -1,   325,   326,   327,
      -1,   329,   330,   331,   332,   799,   334,   335,   336,   337,
     338,   339,    -1,   341,   342,   343,   344,   345,    -1,   347,
      -1,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,    24,    -1,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    44,    -1,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    69,    70,
      -1,    72,    73,    74,    75,    76,    77,    78,    79,    -1,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    -1,    -1,    -1,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,   116,   117,   118,    -1,    -1,
     121,   122,    -1,   124,   472,   126,   127,   128,   129,    -1,
     131,   132,    -1,   134,    -1,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   535,   536,    -1,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   560,   174,    -1,    -1,    -1,   565,   566,   567,
      -1,    -1,   570,    -1,    -1,   573,    -1,    -1,    -1,    -1,
     578,    -1,    -1,   581,   582,    -1,    -1,    -1,    -1,    -1,
      -1,   589,    -1,    -1,    -1,   593,    -1,    -1,    -1,   597,
      -1,    -1,    -1,    -1,    -1,   603,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,   612,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    -1,   630,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    44,    -1,    70,    -1,    72,    73,
      74,    75,    76,    77,    78,    79,    56,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      -1,    -1,    -1,    97,    98,    99,   100,   101,   102,   103,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,    -1,   116,   117,   118,    -1,    -1,   121,   122,    -1,
     124,    -1,   126,   127,   128,   129,    -1,   131,   132,   717,
     134,   719,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    -1,    -1,   171,   172,    -1,
      -1,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    44,    -1,    70,    -1,    72,    73,    74,    75,
      76,    77,    78,    79,    56,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    39,    40,   104,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,   114,    -1,
     116,   117,   118,    56,    -1,   121,   122,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,   132,    -1,   134,    -1,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,    -1,    -1,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     166,   167,   168,    -1,    -1,   171,   172,    56,    -1,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,
      -1,    -1,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    44,   174,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    69,
      70,    -1,    72,    73,    74,    75,    76,    77,    78,    79,
      -1,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    -1,    93,    -1,    -1,    -1,    97,    98,    99,
     100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,   116,   117,   118,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
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
      -1,    -1,    -1,    -1,   114,    -1,   116,   117,   118,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,   116,   117,   118,    -1,    -1,   121,   122,    -1,   124,
      -1,   126,   127,   128,   129,    -1,   131,   132,    -1,   134,
      -1,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   166,   167,   168,    -1,    -1,   171,   172,    -1,    -1,
      -1,    -1,    70,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,   116,   117,
     118,    -1,    -1,   121,   122,    -1,   124,    -1,   126,   127,
     128,   129,    -1,   131,   132,    -1,   134,    -1,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,   167,
     168
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  MapSetParser::yystos_[] =
  {
         0,   176,   177,     0,    20,   192,   193,   195,   166,   178,
     194,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      13,   179,   180,    21,   196,   171,   172,   376,   162,   163,
     164,   165,   416,   425,   416,   416,   416,   416,   166,   167,
     168,   426,   427,    56,   185,   186,   191,    12,    14,    15,
     181,    41,   183,   184,    16,   212,   214,   215,   197,   416,
      92,   173,   417,   418,   419,   416,    41,   187,   188,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     169,   170,   174,   182,   377,   416,   420,   421,   422,   423,
     424,   426,   428,   183,   377,    25,   167,   416,   426,    57,
     190,    42,    41,   254,   198,    42,   189,   416,   374,   376,
     377,   255,   256,   213,   166,    48,    42,    36,    37,    38,
      39,    40,    56,   257,   265,   310,   366,   367,   369,   370,
     371,   374,   216,   416,   368,   260,    48,   266,   267,   312,
      44,   311,    27,    43,   217,   222,   223,    55,   313,   324,
     375,   376,   426,   259,   261,   262,   257,   313,   318,   319,
     366,   372,   373,   374,   313,    28,   218,   219,   220,   221,
     426,    95,   224,   225,   229,    41,   268,    57,   320,   323,
     373,    48,   258,    17,    45,   373,   221,    30,    35,   202,
     246,    96,   226,   232,   269,   317,   322,   257,   375,    44,
      70,    72,    73,    74,    75,    76,    77,    78,    79,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      93,   104,   114,   116,   117,   118,   121,   122,   124,   126,
     127,   128,   129,   131,   132,   134,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   230,   231,   302,   376,   401,   403,   405,   406,   407,
     426,   247,    44,   233,   234,   301,   302,   400,   401,    29,
     227,   235,   199,   200,   270,   271,   272,   275,   325,   366,
     374,    54,   316,    53,   321,   263,    66,    67,    69,    97,
      98,    99,   100,   101,   102,   103,   376,   378,   379,   382,
     385,   386,   389,   390,   396,   398,   399,   400,   401,   408,
     411,   414,   416,   420,   424,   426,    79,    44,    44,    44,
     174,   402,    44,   174,   308,    44,    44,    44,   268,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
     308,    44,    44,    44,    44,    44,   174,    44,   174,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,   231,    44,   174,   303,   248,   378,   234,    30,    33,
      34,   228,   241,   244,   245,    26,   203,    42,   274,    48,
     276,   277,   327,   326,   314,   315,   324,   323,    41,   399,
     399,   399,    44,    44,    94,   206,   207,   381,   384,    60,
      61,    62,    63,    64,    65,    70,    71,   387,   388,   395,
     397,    44,   303,   415,   268,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   376,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,    22,   305,    41,   376,    45,    31,    32,   236,   237,
     238,   239,   240,   301,   376,   153,   153,   242,   245,   243,
     244,    22,    23,   204,   205,   201,    17,    18,    49,    50,
      52,   130,   246,   273,   278,   279,   281,   285,   290,   291,
     294,   295,   300,   272,   319,   336,    44,    55,    69,   105,
     328,   330,   337,   338,   339,   340,   343,   346,   348,   354,
     355,   376,   426,   320,   264,   305,   305,   376,    45,    58,
     380,    59,   383,   389,   389,   389,   389,   389,   389,    71,
     308,    66,    67,   391,   394,   422,   423,    24,    68,   392,
     305,    45,    45,    45,   309,    53,    53,    53,    45,    45,
      53,    45,    45,    53,    45,    45,    45,    45,    53,    45,
      45,    53,    53,    45,    45,    45,    45,    45,    45,    53,
      45,    45,    45,    53,    45,    45,    45,    53,    45,    45,
      45,    45,    45,    53,    45,    45,    45,   378,   252,   237,
     400,    24,    44,   208,   209,   210,   211,   302,   376,   401,
     408,   416,   420,   424,   222,   282,   286,   280,   292,   301,
      44,   258,   296,   339,    44,    55,   105,   356,   361,   362,
     364,   426,   346,   329,   342,   345,    24,    41,    66,   106,
     347,   349,   353,   257,    24,   378,   410,   378,   382,   385,
     308,   396,   396,   392,   393,   398,   398,   378,   307,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   304,    42,    44,   174,   250,   378,   209,   224,   283,
     287,   268,   293,   378,   272,   268,    45,   359,   360,   362,
      55,   363,   426,   320,   107,   341,    68,   344,    53,   153,
     352,   365,    42,    45,   409,    45,    45,    53,   306,    53,
      45,    45,    45,    45,   306,   404,    45,    45,    45,   404,
      45,    45,   307,   251,   207,   202,   375,   288,   268,    94,
     299,    45,   358,   335,   343,   348,   365,    42,    53,   351,
      54,   412,   413,   378,   378,    45,    45,    45,    46,    47,
     249,   253,   376,   416,   420,   424,   426,    45,   284,    19,
     289,   376,    51,   297,   107,   357,    54,   334,    42,    42,
     350,   365,    80,    45,    45,    45,   253,   268,   375,    45,
     298,   362,   330,   331,   333,    42,    60,   268,   268,   332,
     425,   320
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
     194,   195,   197,   198,   196,   200,   201,   199,   202,   202,
     203,   204,   204,   205,   205,   206,   207,   207,   208,   209,
     209,   209,   209,   209,   209,   209,   209,   210,   210,   211,
     211,   213,   212,   214,   215,   215,   216,   216,   217,   218,
     218,   219,   220,   221,   222,   223,   223,   224,   225,   225,
     226,   226,   227,   227,   228,   228,   229,   230,   230,   231,
     231,   231,   231,   232,   233,   233,   234,   235,   236,   236,
     237,   237,   238,   238,   239,   240,   240,   241,   241,   242,
     242,   243,   243,   244,   245,   247,   246,   248,   248,   249,
     249,   251,   250,   250,   252,   252,   253,   253,   253,   253,
     253,   253,   253,   254,   256,   255,   257,   257,   258,   258,
     259,   260,   260,   262,   263,   264,   261,   265,   266,   267,
     267,   269,   268,   270,   270,   271,   272,   272,   273,   274,
     274,   275,   276,   277,   277,   278,   278,   278,   278,   278,
     278,   278,   278,   280,   279,   282,   283,   284,   281,   286,
     287,   288,   285,   289,   289,   290,   292,   293,   291,   295,
     296,   294,   298,   297,   299,   299,   300,   301,   301,   301,
     302,   303,   304,   303,   305,   305,   306,   307,   307,   308,
     309,   308,   311,   310,   312,   310,   313,   314,   315,   315,
     316,   317,   317,   318,   319,   319,   320,   321,   322,   322,
     323,   324,   324,   326,   325,   327,   325,   329,   328,   330,
     330,   332,   331,   333,   333,   334,   335,   335,   336,   337,
     338,   339,   340,   341,   342,   342,   343,   344,   345,   345,
     346,   347,   347,   348,   348,   349,   350,   350,   351,   351,
     352,   352,   353,   353,   353,   353,   354,   355,   355,   355,
     355,   356,   357,   358,   358,   359,   360,   360,   361,   361,
     362,   363,   363,   364,   364,   364,   365,   366,   366,   368,
     367,   369,   370,   370,   370,   370,   370,   371,   371,   372,
     372,   373,   373,   374,   374,   375,   375,   376,   376,   377,
     377,   377,   377,   377,   377,   378,   379,   380,   381,   381,
     382,   383,   384,   384,   385,   386,   387,   387,   388,   388,
     388,   388,   388,   388,   388,   388,   389,   390,   391,   391,
     392,   392,   393,   393,   394,   394,   394,   395,   395,   396,
     397,   397,   398,   398,   398,   398,   399,   399,   399,   399,
     399,   399,   399,   399,   400,   401,   401,   401,   401,   401,
     401,   401,   401,   401,   401,   401,   401,   401,   401,   401,
     401,   401,   401,   401,   401,   401,   401,   401,   401,   401,
     401,   401,   401,   401,   401,   401,   401,   401,   401,   401,
     401,   401,   401,   401,   401,   401,   401,   401,   401,   401,
     401,   401,   401,   401,   401,   401,   402,   402,   403,   404,
     404,   405,   406,   407,   408,   408,   409,   408,   410,   410,
     411,   411,   411,   411,   411,   412,   413,   413,   414,   415,
     415,   416,   417,   418,   418,   419,   419,   420,   420,   420,
     421,   421,   421,   422,   422,   422,   423,   423,   423,   424,
     424,   425,   425,   425,   425,   426,   426,   427,   427,   428,
     428
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
       1,     1,     1,     3,     0,     3,     0,     1,     0,     1,
       3,     0,     2,     0,     0,     0,     8,     2,     2,     0,
       1,     0,     4,     1,     1,     2,     0,     1,     3,     0,
       2,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     3,     0,     0,     0,     6,     0,
       0,     0,     7,     0,     1,     6,     0,     0,     4,     0,
       0,     4,     0,     3,     0,     2,     2,     1,     1,     1,
       2,     1,     0,     6,     0,     1,     2,     0,     2,     1,
       0,     5,     0,     3,     0,     3,     3,     2,     0,     1,
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
       4,     4,     2,     2,     4,     4,     4,     4,     2,     1,
       4,     4,     4,     4,     6,     6,     6,     6,     6,     4,
       4,     4,     4,     4,     4,     4,     4,     2,     4,     4,
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
  "BindingValue", "QuadPattern", "Quads", "$@9", "_QTriplesTemplate_E_Opt",
  "_QGT_DOT_E_Opt",
  "_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C_E_Star",
  "QuadsNotTriples", "@10", "@11", "$@12", "TriplesTemplate",
  "_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C_E_Opt", "GroupGraphPattern",
  "$@13", "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C",
  "GroupGraphPatternSub", "_QTriplesBlock_E_Opt",
  "_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "OptionalGraphPattern", "@14", "GraphGraphPattern", "@15", "@16", "@17",
  "ServiceGraphPattern", "@18", "@19", "@20", "_QIT_SILENT_E_Opt", "Bind",
  "MinusGraphPattern", "@21", "@22", "GroupOrUnionGraphPattern", "@23",
  "@24", "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@25",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "@26", "_QIT_DISTINCT_E_Opt",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ExpressionList", "@27",
  "TriplesSameSubject", "$@28", "$@29", "PropertyListNotEmpty",
  "_O_QVerb_E_S_QObjectList_E_C", "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "Verb", "TriplesSameSubjectPath", "$@30", "$@31",
  "PropertyListNotEmptyPath", "$@32", "_O_QVerbPath_E_Or_QVerbSimple_E_C",
  "_O_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_C", "$@33",
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
  "Integer", "TriplesNode", "BlankNodePropertyList", "@34", "Generator",
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
  "SubstringExpression", "ExistsFunc", "NotExistsFunc", "Aggregate", "@35",
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
       176,     0,    -1,    -1,   177,   192,   178,   179,    -1,    -1,
     178,   180,    -1,    -1,   179,   212,    -1,     3,   376,   416,
     416,    -1,     4,   416,    -1,     5,   416,    -1,     6,   416,
      -1,     7,   416,    -1,     8,   416,    -1,     9,   426,    -1,
      10,   185,    -1,    11,   181,    -1,    13,   184,    -1,    12,
      -1,    15,    -1,    14,    -1,    -1,   377,    -1,    41,   182,
      42,   374,    -1,   183,    -1,   184,   183,    -1,   186,   187,
      -1,    -1,   191,    -1,    -1,   188,    -1,    41,   190,    42,
      -1,   416,    48,   416,    -1,    -1,   190,   189,    -1,    56,
     416,    57,    -1,   193,   194,    -1,    -1,   195,    -1,    -1,
     194,   196,    -1,    20,   166,    -1,    -1,    -1,    21,   197,
     167,   198,   166,    -1,    -1,    -1,   200,   203,   201,   222,
     224,   202,    -1,    -1,   246,    -1,    26,   205,   211,    -1,
      22,    -1,    23,    -1,    -1,   204,    -1,    94,   376,    -1,
      -1,   206,    -1,    44,   378,   207,    45,    -1,   376,    -1,
     408,    -1,   401,    -1,   302,    -1,   416,    -1,   420,    -1,
     424,    -1,   208,    -1,   209,    -1,   210,   209,    -1,   210,
      -1,    24,    -1,    -1,   215,    25,   254,   213,   216,   222,
     224,   202,    -1,    16,   377,    -1,    -1,   214,    -1,    -1,
     216,   217,    -1,    27,   218,    -1,   219,    -1,   220,    -1,
     221,    -1,    28,   221,    -1,   426,    -1,   223,   268,    -1,
      -1,    43,    -1,   225,   226,   227,   228,    -1,    -1,   229,
      -1,    -1,   232,    -1,    -1,   235,    -1,    -1,   241,    -1,
      95,    30,   230,    -1,   231,    -1,   230,   231,    -1,   401,
      -1,   302,    -1,    44,   378,   207,    45,    -1,   376,    -1,
      96,   233,    -1,   234,    -1,   233,   234,    -1,   301,    -1,
      29,    30,   236,    -1,   237,    -1,   236,   237,    -1,   239,
      -1,   240,    -1,    31,    -1,    32,    -1,   238,   400,    -1,
     301,    -1,   376,    -1,   244,   242,    -1,   245,   243,    -1,
      -1,   245,    -1,    -1,   244,    -1,    33,   153,    -1,    34,
     153,    -1,    -1,    35,   247,   248,    41,   252,    42,    -1,
      -1,   248,   376,    -1,   253,    -1,   249,   253,    -1,    -1,
      44,   251,   249,    45,    -1,   174,    -1,    -1,   252,   250,
      -1,   426,    -1,   416,    -1,   420,    -1,   424,    -1,    46,
      -1,    47,    -1,   376,    -1,    41,   255,    42,    -1,    -1,
     256,   257,   260,    -1,    -1,   265,    -1,    -1,    48,    -1,
     261,   258,   257,    -1,    -1,   260,   259,    -1,    -1,    -1,
      -1,   262,    17,   375,   263,    41,   264,   257,    42,    -1,
     310,   267,    -1,    48,   257,    -1,    -1,   266,    -1,    -1,
      41,   269,   270,    42,    -1,   199,    -1,   271,    -1,   272,
     274,    -1,    -1,   275,    -1,   278,   258,   272,    -1,    -1,
     274,   273,    -1,   325,   277,    -1,    48,   272,    -1,    -1,
     276,    -1,   294,    -1,   279,    -1,   291,    -1,   281,    -1,
     285,    -1,   300,    -1,   290,    -1,   246,    -1,    -1,    49,
     280,   268,    -1,    -1,    -1,    -1,    17,   282,   283,   375,
     284,   268,    -1,    -1,    -1,    -1,    18,   286,   287,   288,
     289,   375,   268,    -1,    -1,    19,    -1,   130,    44,   378,
      94,   376,    45,    -1,    -1,    -1,    50,   292,   293,   268,
      -1,    -1,    -1,   295,   296,   268,   299,    -1,    -1,    51,
     298,   268,    -1,    -1,   299,   297,    -1,    52,   301,    -1,
     400,    -1,   401,    -1,   302,    -1,   426,   303,    -1,   174,
      -1,    -1,    44,   305,   378,   304,   307,    45,    -1,    -1,
      22,    -1,    53,   378,    -1,    -1,   307,   306,    -1,   174,
      -1,    -1,    44,   378,   309,   307,    45,    -1,    -1,   374,
     311,   313,    -1,    -1,   366,   312,   318,    -1,   324,   320,
     317,    -1,   324,   320,    -1,    -1,   314,    -1,    54,   315,
      -1,    -1,   317,   316,    -1,   319,    -1,    -1,   313,    -1,
     323,   322,    -1,    53,   323,    -1,    -1,   322,   321,    -1,
     373,    -1,   375,    -1,    55,    -1,    -1,   374,   326,   328,
      -1,    -1,   366,   327,   336,    -1,    -1,   330,   329,   320,
     335,    -1,   337,    -1,   338,    -1,    -1,   330,   332,   320,
      -1,    -1,   331,    -1,    54,   333,    -1,    -1,   335,   334,
      -1,   319,    -1,   339,    -1,   376,    -1,   340,    -1,   343,
     342,    -1,   107,   343,    -1,    -1,   342,   341,    -1,   348,
     345,    -1,    68,   348,    -1,    -1,   345,   344,    -1,   354,
     347,    -1,    -1,   349,    -1,   346,    -1,   105,   346,    -1,
     353,    -1,    42,    -1,   365,    42,    -1,    53,   350,    -1,
      42,    -1,   365,   351,    -1,    53,   365,    42,    -1,    24,
      -1,   106,    -1,    66,    -1,    41,   352,    -1,   355,    -1,
     426,    -1,    55,    -1,    69,   356,    -1,    44,   339,    45,
      -1,   361,    -1,   107,   362,    -1,    -1,   358,   357,    -1,
     362,   358,    -1,    -1,   359,    -1,   362,    -1,    44,   360,
      45,    -1,   364,    -1,   426,    -1,    55,    -1,   426,    -1,
      55,    -1,   105,   363,    -1,   153,    -1,   369,    -1,   367,
      -1,    -1,    56,   368,   313,    57,    -1,   371,    44,   372,
      45,    -1,    36,    -1,    37,    -1,    38,    -1,    39,    -1,
      40,    -1,    -1,   370,    -1,   373,    -1,   372,   373,    -1,
     374,    -1,   366,    -1,   376,    -1,   377,    -1,   376,    -1,
     426,    -1,   171,    -1,   172,    -1,   426,    -1,   416,    -1,
     420,    -1,   424,    -1,   428,    -1,   174,    -1,   379,    -1,
     382,   381,    -1,    58,   382,    -1,    -1,   381,   380,    -1,
     385,   384,    -1,    59,   385,    -1,    -1,   384,   383,    -1,
     386,    -1,   389,   387,    -1,    -1,   388,    -1,    60,   389,
      -1,    61,   389,    -1,    62,   389,    -1,    63,   389,    -1,
      64,   389,    -1,    65,   389,    -1,    71,   308,    -1,    70,
      71,   308,    -1,   390,    -1,   396,   395,    -1,   422,    -1,
     423,    -1,    24,   398,    -1,    68,   398,    -1,    -1,   392,
      -1,    66,   396,    -1,    67,   396,    -1,   391,   393,    -1,
      -1,   395,   394,    -1,   398,   397,    -1,    -1,   397,   392,
      -1,    69,   399,    -1,    66,   399,    -1,    67,   399,    -1,
     399,    -1,   400,    -1,   401,    -1,   414,    -1,   416,    -1,
     420,    -1,   424,    -1,   376,    -1,   408,    -1,    44,   378,
      45,    -1,    81,    44,   378,    45,    -1,    82,    44,   378,
      45,    -1,    83,    44,   378,    53,   378,    45,    -1,    84,
      44,   378,    45,    -1,    85,    44,   376,    45,    -1,    72,
      44,   378,    45,    -1,    73,    44,   378,    45,    -1,    74,
     402,    -1,   121,   174,    -1,   145,    44,   378,    45,    -1,
     142,    44,   378,    45,    -1,   134,    44,   378,    45,    -1,
     128,    44,   378,    45,    -1,    93,   308,    -1,   405,    -1,
     148,    44,   378,    45,    -1,   146,    44,   378,    45,    -1,
     144,    44,   378,    45,    -1,   140,    44,   378,    45,    -1,
     131,    44,   378,    53,   378,    45,    -1,   141,    44,   378,
      53,   378,    45,    -1,   147,    44,   378,    53,   378,    45,
      -1,   116,    44,   378,    53,   378,    45,    -1,   117,    44,
     378,    53,   378,    45,    -1,   118,    44,   378,    45,    -1,
     150,    44,   378,    45,    -1,   143,    44,   378,    45,    -1,
     139,    44,   378,    45,    -1,   136,    44,   378,    45,    -1,
     132,    44,   378,    45,    -1,   127,    44,   378,    45,    -1,
     126,    44,   378,    45,    -1,   124,   174,    -1,   114,    44,
     378,    45,    -1,   149,    44,   378,    45,    -1,   138,    44,
     378,    45,    -1,   129,    44,   378,    45,    -1,   122,    44,
     378,    45,    -1,    75,   308,    -1,    76,    44,   378,    53,
     378,    53,   378,    45,    -1,    77,    44,   378,    53,   378,
      45,    -1,    78,    44,   378,    53,   378,    45,    -1,    86,
      44,   378,    53,   378,    45,    -1,    87,    44,   378,    45,
      -1,    88,    44,   378,    45,    -1,    89,    44,   378,    45,
      -1,    90,    44,   378,    45,    -1,   104,    44,   378,    45,
      -1,   403,    -1,   406,    -1,   407,    -1,    44,   378,    45,
      -1,   174,    -1,    91,    44,   378,    53,   378,   404,    45,
      -1,    -1,   306,    -1,   137,    44,   378,    53,   378,   404,
      45,    -1,    79,   268,    -1,    70,    79,   268,    -1,    97,
      44,   305,   410,    45,    -1,   411,    44,   305,   378,    45,
      -1,    -1,   102,    44,   305,   378,   409,   413,    45,    -1,
      24,    -1,   378,    -1,    98,    -1,    99,    -1,   100,    -1,
     101,    -1,   103,    -1,    54,    80,    60,   425,    -1,    -1,
     412,    -1,   426,   415,    -1,    -1,   303,    -1,   425,   419,
      -1,    92,   426,    -1,   173,    -1,   417,    -1,    -1,   418,
      -1,   421,    -1,   422,    -1,   423,    -1,   153,    -1,   154,
      -1,   155,    -1,   156,    -1,   157,    -1,   158,    -1,   159,
      -1,   160,    -1,   161,    -1,   151,    -1,   152,    -1,   162,
      -1,   164,    -1,   163,    -1,   165,    -1,   166,    -1,   427,
      -1,   168,    -1,   167,    -1,   169,    -1,   170,    -1
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
     339,   341,   343,   345,   349,   350,   354,   355,   357,   358,
     360,   364,   365,   368,   369,   370,   371,   380,   383,   386,
     387,   389,   390,   395,   397,   399,   402,   403,   405,   409,
     410,   413,   416,   419,   420,   422,   424,   426,   428,   430,
     432,   434,   436,   438,   439,   443,   444,   445,   446,   453,
     454,   455,   456,   464,   465,   467,   474,   475,   476,   481,
     482,   483,   488,   489,   493,   494,   497,   500,   502,   504,
     506,   509,   511,   512,   519,   520,   522,   525,   526,   529,
     531,   532,   538,   539,   543,   544,   548,   552,   555,   556,
     558,   561,   562,   565,   567,   568,   570,   573,   576,   577,
     580,   582,   584,   586,   587,   591,   592,   596,   597,   602,
     604,   606,   607,   611,   612,   614,   617,   618,   621,   623,
     625,   627,   629,   632,   635,   636,   639,   642,   645,   646,
     649,   652,   653,   655,   657,   660,   662,   664,   667,   670,
     672,   675,   679,   681,   683,   685,   688,   690,   692,   694,
     697,   701,   703,   706,   707,   710,   713,   714,   716,   718,
     722,   724,   726,   728,   730,   732,   735,   737,   739,   741,
     742,   747,   752,   754,   756,   758,   760,   762,   763,   765,
     767,   770,   772,   774,   776,   778,   780,   782,   784,   786,
     788,   790,   792,   794,   796,   798,   800,   803,   806,   807,
     810,   813,   816,   817,   820,   822,   825,   826,   828,   831,
     834,   837,   840,   843,   846,   849,   853,   855,   858,   860,
     862,   865,   868,   869,   871,   874,   877,   880,   881,   884,
     887,   888,   891,   894,   897,   900,   902,   904,   906,   908,
     910,   912,   914,   916,   918,   922,   927,   932,   939,   944,
     949,   954,   959,   962,   965,   970,   975,   980,   985,   988,
     990,   995,  1000,  1005,  1010,  1017,  1024,  1031,  1038,  1045,
    1050,  1055,  1060,  1065,  1070,  1075,  1080,  1085,  1088,  1093,
    1098,  1103,  1108,  1113,  1116,  1125,  1132,  1139,  1146,  1151,
    1156,  1161,  1166,  1171,  1173,  1175,  1177,  1181,  1183,  1191,
    1192,  1194,  1202,  1205,  1209,  1215,  1221,  1222,  1230,  1232,
    1234,  1236,  1238,  1240,  1242,  1244,  1249,  1250,  1252,  1255,
    1256,  1258,  1261,  1264,  1266,  1268,  1269,  1271,  1273,  1275,
    1277,  1279,  1281,  1283,  1285,  1287,  1289,  1291,  1293,  1295,
    1297,  1299,  1301,  1303,  1305,  1307,  1309,  1311,  1313,  1315,
    1317
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
    1069,  1072,  1075,  1081,  1087,  1087,  1094,  1096,  1099,  1101,
    1105,  1108,  1110,  1115,  1120,  1123,  1115,  1134,  1138,  1141,
    1143,  1148,  1148,  1159,  1160,  1165,  1169,  1171,  1181,  1185,
    1188,  1204,  1209,  1213,  1216,  1220,  1221,  1222,  1223,  1224,
    1225,  1226,  1227,  1233,  1233,  1249,  1253,  1255,  1249,  1266,
    1270,  1272,  1266,  1283,  1286,  1292,  1298,  1302,  1298,  1312,
    1316,  1312,  1326,  1326,  1338,  1340,  1344,  1354,  1355,  1356,
    1360,  1368,  1372,  1372,  1382,  1385,  1392,  1398,  1400,  1414,
    1417,  1417,  1427,  1427,  1430,  1430,  1437,  1442,  1446,  1448,
    1453,  1457,  1459,  1464,  1468,  1470,  1475,  1480,  1484,  1486,
    1490,  1497,  1501,  1509,  1509,  1512,  1512,  1518,  1518,  1524,
    1525,  1529,  1529,  1534,  1536,  1540,  1543,  1545,  1549,  1553,
    1557,  1563,  1567,  1571,  1574,  1576,  1580,  1584,  1589,  1591,
    1597,  1600,  1602,  1608,  1609,  1615,  1619,  1620,  1624,  1625,
    1629,  1630,  1634,  1635,  1636,  1637,  1641,  1645,  1648,  1651,
    1654,  1660,  1664,  1667,  1669,  1673,  1676,  1678,  1682,  1683,
    1687,  1691,  1692,  1696,  1697,  1698,  1702,  1707,  1708,  1712,
    1712,  1725,  1750,  1753,  1756,  1759,  1762,  1769,  1772,  1777,
    1781,  1788,  1789,  1793,  1796,  1800,  1803,  1809,  1810,  1814,
    1817,  1820,  1823,  1826,  1827,  1833,  1838,  1847,  1854,  1857,
    1865,  1874,  1881,  1884,  1891,  1896,  1907,  1910,  1914,  1917,
    1920,  1923,  1926,  1929,  1932,  1935,  1941,  1946,  1955,  1958,
    1965,  1968,  1975,  1978,  1983,  1986,  1990,  2004,  2007,  2015,
    2024,  2027,  2034,  2037,  2040,  2043,  2047,  2048,  2049,  2050,
    2053,  2056,  2059,  2062,  2066,  2072,  2075,  2078,  2081,  2084,
    2087,  2090,  2094,  2097,  2100,  2103,  2106,  2109,  2112,  2115,
    2116,  2119,  2122,  2125,  2128,  2131,  2134,  2137,  2140,  2143,
    2146,  2149,  2152,  2155,  2158,  2161,  2164,  2167,  2170,  2173,
    2176,  2179,  2182,  2185,  2189,  2192,  2195,  2198,  2201,  2204,
    2207,  2210,  2213,  2216,  2217,  2218,  2224,  2227,  2234,  2241,
    2244,  2248,  2254,  2261,  2268,  2271,  2275,  2275,  2288,  2292,
    2296,  2299,  2302,  2305,  2308,  2314,  2320,  2323,  2327,  2337,
    2340,  2345,  2353,  2360,  2364,  2372,  2376,  2380,  2381,  2382,
    2386,  2387,  2388,  2392,  2393,  2394,  2398,  2399,  2400,  2404,
    2405,  2409,  2410,  2411,  2412,  2416,  2417,  2421,  2422,  2426,
    2427
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
  const int MapSetParser::yylast_ = 2180;
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
#line 4952 "lib/MapSetParser/MapSetParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 2433 "lib/MapSetParser/MapSetParser.ypp"
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


