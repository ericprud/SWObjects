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
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1084 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1091 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1093 "lib/MapSetParser/MapSetParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1175 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.ensureGraphPattern(), (yysemantic_stack_[(1) - (1)].p_BindingClause)) : (yysemantic_stack_[(1) - (1)].p_BindingClause);
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1181 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
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

/* Line 690 of lalr1.cc  */
#line 1197 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1201 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1203 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1206 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1214 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1218 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1220 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1223 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(7) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(7) - (6)].p_TTerm), driver.curOp, (yysemantic_stack_[(7) - (5)].p_Silence), driver.atomFactory, false));
	  driver.curGraphName = (yysemantic_stack_[(7) - (4)].p_TTerm);
      }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 1231 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curOp = new Bind(driver.ensureGraphPattern(), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
    }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 1237 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 1241 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1243 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1251 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1255 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1257 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1265 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1270 "lib/MapSetParser/MapSetParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.ensureGraphPattern());
      }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
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

/* Line 690 of lalr1.cc  */
#line 1299 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1307 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1311 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1314 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yysemantic_stack_[(6) - (4)].p_Expressions);
      }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1321 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1324 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1331 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1339 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1353 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1356 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1359 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(5) - (3)].p_Expressions);
      }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1367 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1369 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 1397 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 1400 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 1460 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 1467 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 1471 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 1479 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 1482 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 1488 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 1499 "lib/MapSetParser/MapSetParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 1527 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 1554 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 1561 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 1572 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 1579 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 1615 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 1618 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 1621 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 1624 "lib/MapSetParser/MapSetParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 1682 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 1686 "lib/MapSetParser/MapSetParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
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

/* Line 690 of lalr1.cc  */
#line 1720 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 1723 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 1726 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 1729 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 1732 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 1739 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 1747 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 1751 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 1763 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 1770 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 1773 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 1784 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 1787 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 1790 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 1793 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 1797 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 1808 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 1817 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 1824 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 1827 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 1835 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 1844 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 1851 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 1854 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
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

/* Line 690 of lalr1.cc  */
#line 1877 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 1884 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 1887 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 1890 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 1893 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 1896 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 1899 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 1902 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 1905 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 1916 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 1925 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 1928 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 1935 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 1938 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 1945 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 1953 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 1956 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
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

/* Line 690 of lalr1.cc  */
#line 1974 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 1977 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 1985 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 1994 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 1997 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 2004 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 2007 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 2010 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 2020 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 2023 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 2026 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 2029 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 2036 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 2042 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 2045 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 2048 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 2051 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 2054 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 2057 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 2060 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 2064 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 2067 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 2070 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 2073 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ciel, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 2076 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 2079 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 2082 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 2086 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 2089 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 2092 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 2095 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 2098 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 2101 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 2104 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 2107 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 2110 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 2113 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 2116 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 2119 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 2122 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 2125 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 2128 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 2131 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 2134 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 2137 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 2140 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 2143 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 2146 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 2149 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 2152 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 2155 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 2159 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 2162 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 2165 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 2168 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 2171 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 2174 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 2177 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 2180 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 2183 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 2194 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 2197 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 2204 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 2211 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 2218 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 2224 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.ensureGraphPattern(), NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 2231 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.ensureGraphPattern(), NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 2238 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 2241 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 2245 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 2248 "lib/MapSetParser/MapSetParser.ypp"
    {
	  // x = new ArgList($2, driver.curExprList);
	  delete driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(7) - (5)].p_Expressions);
	  w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // $$ = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group-concat, $3, $4.p_Expression, $4.separator));
    }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 2258 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_Expression) = NULL;
	driver.countStar = true;
    }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 2266 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 2269 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 2272 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 2275 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 2278 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 2284 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 2290 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 2297 "lib/MapSetParser/MapSetParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 2307 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 2315 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 2323 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 2330 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 2334 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 2342 "lib/MapSetParser/MapSetParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 690 of lalr1.cc  */
#line 3182 "lib/MapSetParser/MapSetParser.cpp"
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
  const short int MapSetParser::yypact_ninf_ = -665;
  const short int
  MapSetParser::yypact_[] =
  {
      -665,    46,    42,  -665,  -118,  -665,  -665,  -665,  -665,   355,
      43,   -78,   -76,   -76,   -76,   -76,   -76,   -49,    21,   101,
      30,    28,  -665,  -665,  -665,  -665,  -665,   -76,  -665,  -665,
    -665,  -665,  -665,   -62,  -665,  -665,  -665,  -665,  -665,  -665,
    -665,  -665,  -665,   -76,  -665,    38,  -665,  -665,  -665,  -665,
    -665,   744,  -665,    30,   744,  -665,  -665,    59,   -60,   -76,
     -49,  -665,  -665,  -665,  -665,    55,  -665,  -665,  -665,  -665,
    -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,
    -665,  -665,  -665,    80,  -665,  -665,  -665,  -665,  -665,  -665,
    -665,  -665,  -665,  -665,  -665,    83,  -665,  -665,  -665,  -665,
     -21,   333,  -665,  -665,   -34,  -665,  -665,    87,  -665,  -665,
    -665,  1245,  -665,  -665,   -76,  -665,  -665,  -665,  -665,  -665,
    -665,    95,  -665,    91,  -665,  -665,  -665,  -665,   116,  -665,
      13,  -665,    51,  -665,  1245,  -665,  -665,    51,  1338,    51,
      -2,  -665,  -665,    85,   137,  -665,   129,  1338,  -665,  -665,
    -665,  -665,  -665,  -665,  -665,  -665,  1284,  -665,  -665,  -665,
     -49,  -665,  -665,  -665,  -665,  -665,   161,   163,   104,  -665,
    -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  1842,
    -665,  -665,  -665,  1949,   180,  -665,   533,   157,   167,  1467,
     142,   172,   182,   -17,   -16,   184,   188,   193,   137,   194,
     196,   197,   204,   207,   209,   212,   213,   215,   221,   226,
     -16,   227,   228,   241,   242,   244,   118,   249,   120,   252,
     262,   263,   264,   265,   266,   268,   269,   271,   275,   278,
     283,   284,   287,   290,   301,   302,   304,   305,   306,   307,
     308,  1842,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,
     -15,  -665,  1467,  1949,  -665,  -665,  -665,  -665,  -665,   324,
      64,  -665,  -665,   198,   313,  -665,  -665,  -665,   309,  -665,
    -665,    51,  -665,  1338,  -665,  1592,  1592,  1592,   328,  -665,
    -665,  -665,  -665,   329,  -665,  -665,   281,  -665,  -665,  -665,
    -665,   219,  -665,  -665,  -665,  -665,  -665,  -665,  -665,   334,
    -665,  -665,  -665,  -665,   -15,   137,  1467,  1467,  1467,  -665,
    -665,  1467,  -665,  -665,  1467,  1467,  1467,  -665,  1467,  1467,
    1467,  1467,   -78,  1467,  1467,  1467,  1467,  1467,  1467,  -665,
    1467,  1467,  1467,  1467,  1467,  -665,  1467,  -665,  1467,  1467,
    1467,  1467,  1467,  1467,  1467,  1467,  1467,  1467,  1467,  1467,
    1467,  1467,  1467,  1467,  1467,  1467,  1467,  1467,  1467,  1467,
    -665,   239,  -665,  -665,   -19,   332,  -665,  1221,   247,   248,
    -665,  -665,   345,   347,   151,  -665,  -665,   217,  1245,  -665,
    -665,    51,   158,  -665,  -665,  1338,  -665,  -665,  -665,  -665,
     239,   239,   -78,  -665,   359,   348,   346,  1467,  1467,  1467,
    1467,  1467,  1467,   338,   -16,  -665,  -665,   183,     1,   239,
    -665,  -665,  -665,   365,   366,   367,  -665,   360,   362,   363,
     374,   375,   368,   377,   380,   373,   382,   384,   388,   411,
     412,   421,   422,   415,   416,   425,   427,   429,   430,   431,
     432,   426,   433,   435,   436,   453,   437,   463,   465,   459,
     468,   469,   470,   472,   473,   466,   475,   476,   477,  -665,
    1467,  -665,  -665,  -665,  -665,  -665,  1221,  -665,   479,  -665,
    -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,
    -665,  -665,  1083,   481,  -665,  -665,  -665,  -665,  1949,   482,
    -665,  -665,   483,  -665,  -665,  -665,  -665,  -665,  -665,  -665,
    -665,  -665,  -665,  -665,     3,  -665,    76,   170,  -665,  -665,
    -665,  -665,  -665,  -665,  -665,  -665,  -665,     8,  -665,  -665,
    -665,  -665,   850,  1467,  -665,  -665,  1467,  -665,  1467,  -665,
    -665,  -665,  -665,  -665,  -665,  -665,   -16,  -665,  1467,  1467,
       1,  -665,  -665,  -665,  1467,  1467,  -665,  1467,  -665,  -665,
    -665,  -665,  1467,  1467,  1467,  -665,  -665,  1467,  -665,  -665,
    1467,  -665,  -665,  -665,  -665,  1467,  -665,  -665,  1467,  1467,
    -665,  -665,  -665,  -665,  -665,  -665,  1467,  -665,  -665,  -665,
    1467,  -665,  -665,  -665,  1467,  -665,  -665,  -665,  -665,  -665,
    1467,  -665,  -665,  -665,  -665,   -25,  -665,  -665,  -665,  1467,
    -665,  -665,  1717,  -665,  -665,  -665,  -665,  -665,  -665,  -665,
    -665,    85,  -665,  -665,   137,  -665,  -665,  1467,  -665,  1245,
     137,   480,   107,  -665,    79,  -665,  -665,  -665,  -665,  -665,
    -665,  1338,   423,   461,  -665,   -20,  -665,  -665,  -665,  -665,
    -665,  -665,  -665,   488,  -665,  -665,  -665,  -665,  -665,  -665,
    -665,  -665,  -665,  -665,   489,    10,   484,   490,   491,   494,
     495,   492,   496,   497,   498,   492,   499,   501,  -665,  -665,
    -665,  -665,  -665,   281,  -665,   163,   133,  -665,  -665,   137,
     454,  -665,  -665,  -665,  -665,   502,  -665,  -665,  -665,  -665,
    -665,     3,  -665,     3,  -665,   396,  -665,  -665,    -1,  -665,
     506,  -665,  -665,  1467,  -665,  1467,  -665,  -665,  -665,  -665,
    -665,   505,  -665,  -665,  -665,   507,  -665,  -665,    15,   286,
     508,  -665,  -665,   532,  -665,   -78,   504,  -665,   455,   509,
    -665,  -665,   519,  -665,    -5,  -665,   485,  -665,   521,  -665,
     522,  -665,  -665,  -665,  -665,  -665,   231,  -665,  -665,  -665,
    -665,  -665,  -665,  -665,   137,  -665,   133,   523,  -665,  -665,
     107,  -665,   158,  -665,  -665,  -665,  -665,   534,   514,  -665,
    -665,  -665,  -665,  -665,   137,  -665,   137,  -665,  -665,  -665,
    -665,  -665,   -76,  -665,  -665,  1338,  -665,  -665
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  MapSetParser::yydefact_[] =
  {
         2,     0,    37,     1,     0,     4,    39,    38,    41,     6,
      36,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     3,     5,    42,    40,   319,   320,     0,   473,   475,
     474,   476,     9,   457,    10,    11,    12,    13,   477,   480,
     479,    14,   478,     0,    15,    29,    28,    18,    20,    19,
      16,    21,    24,    17,     0,     7,    75,     0,     0,     0,
       0,   455,   456,   458,   453,     0,    33,    26,    30,   471,
     472,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     481,   482,   326,     0,    22,   322,   323,   459,   460,   461,
     324,   321,   325,    25,    73,     0,    43,     8,   454,    35,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,   100,   102,    99,   425,   391,   426,   427,
       0,   127,     0,   103,   104,   106,   193,   191,   192,     0,
      94,    93,   147,     0,     0,   148,   155,   151,   159,   237,
     235,   220,   224,   309,   231,     0,     0,     0,     0,   442,
     443,   444,   445,     0,   446,   374,    56,   327,   330,   334,
     336,   338,   348,   359,   362,   367,   368,   369,   375,     0,
     370,   371,   372,   373,   451,     0,     0,     0,     0,   429,
     384,     0,   203,   415,     0,     0,     0,   434,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   390,
       0,     0,     0,     0,     0,   385,     0,   409,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      98,   198,   195,   194,     0,     0,   105,     0,     0,     0,
      87,    95,   119,   121,    53,    46,   146,   149,   150,   160,
     157,   226,     0,   221,   222,   309,   229,   365,   366,   364,
     198,   198,     0,    57,     0,   328,   332,     0,     0,     0,
       0,     0,     0,     0,     0,   337,   339,   349,   361,   198,
     452,   450,   435,     0,     0,     0,   204,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   199,
       0,   134,   128,   376,   112,   113,   107,   108,     0,   110,
     111,   115,   116,   123,   124,   117,   120,   118,   122,    51,
      52,    54,     0,    85,   171,   175,   169,   180,     0,     0,
     168,   156,   152,   162,   164,   165,   167,   163,   161,   184,
     166,   158,   250,   238,     0,   280,     0,     0,   236,   239,
     241,   242,   251,   253,   256,   265,   260,   263,   278,   252,
     279,   219,     0,     0,    55,   101,     0,   331,     0,   335,
     340,   341,   342,   343,   344,   345,     0,   346,     0,     0,
     354,   360,   350,   351,     0,     0,   363,     0,   382,   383,
     428,   201,     0,     0,     0,   377,   378,     0,   380,   381,
       0,   420,   421,   422,   423,     0,   424,   410,     0,     0,
     401,   414,   408,   407,   389,   413,     0,   406,   388,   405,
       0,   412,   404,   395,     0,   387,   403,   394,   386,   393,
       0,   392,   411,   402,   196,     0,   109,   114,    70,     0,
      66,    67,    69,    50,    62,    59,    61,    60,    63,    64,
      65,    88,   172,   176,     0,   181,   190,     0,   153,   150,
       0,     0,   288,   296,     0,   281,   283,   290,   292,   295,
     266,   309,   254,   258,   274,     0,   276,   275,   262,   264,
     267,   440,   441,     0,   438,   329,   333,   347,   356,   357,
     355,   358,   352,   353,     0,     0,     0,     0,     0,     0,
       0,   431,     0,     0,     0,   431,     0,     0,   201,   126,
     131,   133,   135,    56,    68,    48,     0,   177,   170,     0,
       0,   154,   188,   282,   289,     0,   285,   294,   297,   293,
     248,     0,   257,     0,   261,     0,   298,   277,     0,   436,
     448,   437,   205,     0,   202,     0,   417,   418,   379,   419,
     432,     0,   399,   400,   396,     0,   397,   398,     0,     0,
       0,    47,   173,   143,   182,     0,   185,   291,   287,   240,
     255,   259,     0,   271,     0,   272,     0,   449,     0,   200,
       0,   430,   433,   197,   140,   141,     0,   129,   142,   137,
     138,   139,   136,    58,     0,   144,     0,     0,   186,   189,
       0,   286,   245,   249,   273,   268,   270,     0,     0,   439,
     416,   132,   130,   174,     0,   179,     0,   284,   243,   246,
     247,   269,     0,   178,   187,   309,   447,   244
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yypgoto_[] =
  {
      -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,   511,  -665,
    -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,
    -665,  -665,  -665,  -665,  -665,  -665,  -665,  -100,  -665,  -665,
    -665,  -665,   -94,  -665,   -18,  -665,  -665,  -665,  -665,  -665,
    -665,  -665,  -665,  -665,  -665,  -665,   428,    98,  -665,   -29,
    -665,  -665,  -665,  -665,  -665,  -665,   342,  -665,  -665,   337,
    -665,  -665,   119,  -665,  -665,  -665,  -665,  -665,  -665,   214,
     220,   218,  -665,  -665,  -665,  -665,  -665,  -665,  -160,  -665,
    -196,  -665,  -665,  -665,  -364,  -665,  -665,  -665,  -665,  -665,
    -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,
    -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,
    -665,  -665,  -665,  -316,  -166,   292,  -665,  -352,  -600,   -74,
    -201,  -665,  -665,  -665,   464,  -665,  -665,  -665,  -665,  -665,
    -665,   -73,  -665,  -665,  -665,  -665,  -665,   216,  -377,  -665,
    -665,   326,   330,  -665,  -665,  -665,  -665,  -665,  -162,  -665,
    -665,  -665,  -665,  -665,  -665,  -665,  -665,    99,  -665,  -665,
    -665,   -89,  -665,  -665,    97,  -665,   -88,  -665,  -665,  -665,
    -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,  -665,
    -606,  -665,  -665,  -664,  -110,  -665,  -665,  -665,  -665,  -665,
    -665,  -102,   -91,  -653,   -11,    27,   513,  -665,  -665,  -665,
      81,  -665,  -665,    78,  -665,  -665,  -665,    62,  -665,  -665,
      69,  -665,  -665,  -665,  -334,  -665,  -337,   -82,  -171,  -168,
    -665,  -665,   -54,  -665,  -665,  -665,  -447,  -665,  -665,  -665,
    -665,  -665,  -665,  -665,    -9,  -665,  -665,  -665,    29,  -665,
     205,   206,    45,  -167,    50,  -665,  -665
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  MapSetParser::yydefgoto_[] =
  {
        -1,     1,     2,     9,    21,    22,    50,    83,    52,    53,
      44,    45,    67,    68,   106,   100,    46,     5,     6,    10,
       7,    24,    58,   104,   262,   263,   483,   181,   375,   481,
     482,   393,   394,   600,   601,   602,   603,    55,   112,    56,
      57,   130,   142,   161,   162,   163,   164,   143,   144,   167,
     168,   184,   260,   370,   169,   241,   242,   185,   253,   254,
     261,   466,   467,   468,   469,   470,   371,   475,   477,   372,
     373,   182,   251,   364,   746,   672,   719,   595,   747,   756,
     171,   186,   264,   265,   266,   619,   491,   377,   267,   379,
     380,   492,   493,   614,   494,   612,   676,   754,   495,   613,
     677,   723,   496,   497,   615,   679,   498,   499,   620,   759,
     776,   726,   500,   255,   256,   363,   668,   460,   704,   655,
     313,   551,   103,   111,   121,   122,   135,   136,   123,   139,
     137,   152,   383,   384,   272,   187,   153,   154,   173,   274,
     188,   174,   147,   268,   382,   381,   508,   631,   509,   779,
     785,   780,   763,   729,   503,   510,   511,   512,   513,   692,
     632,   514,   694,   633,   515,   638,   516,   639,   766,   735,
     697,   640,   517,   518,   625,   761,   728,   684,   685,   626,
     627,   688,   628,   698,   155,   125,   132,   126,   127,   128,
     156,   175,   158,   148,   285,   110,   286,   287,   527,   395,
     288,   529,   396,   289,   290,   405,   406,   291,   292,   540,
     546,   651,   541,   407,   293,   408,   294,   295,   296,   297,
     310,   246,   711,   247,   248,   249,   298,   700,   643,   299,
     737,   738,   300,   411,   301,    62,    63,    64,   302,    87,
      88,    89,   303,    33,   304,    42,    92
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int MapSetParser::yytable_ninf_ = -310;
  const short int
  MapSetParser::yytable_[] =
  {
        27,   124,   317,    32,    34,    35,    36,    37,   521,   329,
     108,   245,   257,   243,   501,   258,   686,   669,    59,   670,
     129,   105,   461,   722,   124,   544,   160,   308,   311,   361,
      60,   732,   634,   695,    65,   607,   157,   765,   522,   523,
     140,   733,    85,   129,    54,    85,     3,   504,     8,   635,
      97,   471,   734,   -74,   177,   702,   141,   547,   505,   146,
     743,   710,     4,   703,    23,   710,   159,    41,   703,   545,
     767,    51,   506,   245,   636,   243,   269,    43,    84,    66,
      86,    94,   257,    86,    95,   258,    28,    29,    30,    31,
     109,   107,    85,    25,    26,   270,    90,   368,   369,    90,
     109,    91,    85,   774,    91,   131,   145,    96,   507,   412,
      98,    61,    99,    47,   637,    48,    49,    38,    39,    40,
     622,   149,   101,   109,   102,    85,   149,   109,   149,    85,
      86,   623,   113,   696,   687,   114,   109,   133,    85,   134,
      86,    28,    29,    30,    31,   109,    90,    85,   696,   671,
     471,    91,    25,    26,   777,   607,    90,   309,   312,   362,
     138,    91,   623,    86,    38,    39,    40,    86,   244,    38,
      39,    40,   616,   479,   480,   109,    86,    85,   170,    90,
     166,   624,   150,    90,    91,    86,   172,   150,    91,   150,
     165,   179,    90,   387,   388,   389,   257,    91,   180,   258,
     183,    90,   504,   537,   648,   649,    91,   652,   653,   259,
     165,   271,   624,   505,   504,    86,   306,    38,    39,    40,
     273,   305,    25,    26,   374,   505,   307,   506,   314,   250,
     244,    90,   315,   250,   484,   485,    91,   316,   318,   506,
     319,   320,    38,    39,    40,    38,    39,    40,   321,   538,
     539,   322,   180,   323,   690,   681,   324,   325,  -183,   326,
     149,   459,   109,   507,    85,   327,   486,   487,   269,   488,
     328,   330,   331,    38,    39,    40,   771,   744,   745,   397,
     398,   399,   400,   401,   402,   332,   333,   270,   334,   403,
     404,   250,   335,   336,   337,   257,   338,   597,   258,    38,
      39,    40,    86,   250,    25,    26,   339,   340,   341,   342,
     343,   424,   344,   345,   606,   346,   604,   257,    90,   347,
     258,   150,   348,    91,    38,    39,    40,   349,   350,    25,
      26,   351,   744,   745,   352,   647,    38,    39,    40,    74,
      75,    76,    77,    78,    79,   353,   354,   489,   355,   356,
     357,   358,   359,   462,   367,   376,   472,   378,    11,    12,
      13,    14,    15,    16,    17,    18,    19,   109,    20,    85,
     149,   519,   390,   391,   109,   392,    85,   463,   409,   369,
     368,   524,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    28,    29,    30,    31,    38,    39,    40,
     473,   474,    25,    26,   525,   528,   526,    86,   787,   536,
     548,   549,   550,   552,    86,   553,   554,   250,   678,   555,
     556,   557,   558,    90,   682,   559,   560,   561,    91,   562,
      90,   150,   520,   563,   606,    91,   604,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    28,    29,
      30,    31,    38,    39,    40,   472,   564,    25,    26,   530,
     531,   532,   533,   534,   535,   565,   566,   567,   568,   569,
     570,   605,   571,   608,   572,   573,   574,   575,   577,   576,
     578,   579,   581,   724,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    28,    29,    30,    31,    38,
      39,    40,    80,    81,    25,    26,   580,    82,   582,   269,
     583,   609,   584,   585,   586,   587,   250,   588,   589,   590,
     591,   592,   593,   252,   141,   683,   617,   610,   270,   693,
     691,   618,   250,   699,   701,   706,   707,   705,   250,   708,
     709,   712,   713,   714,   716,   703,   717,   727,   725,   696,
     741,   755,   742,   753,   520,   758,   629,   520,   773,   -45,
     736,   764,   760,   762,    93,   768,   769,   770,   775,   115,
     116,   117,   118,   119,   782,   721,   781,  -309,   783,   720,
     784,   611,   675,   360,   674,   596,   772,   478,   178,   120,
     366,   605,   476,   608,   718,   490,   410,   502,   151,   386,
     778,   385,   730,   621,   630,   731,   646,   645,   109,   650,
      85,   715,   542,   543,     0,   786,     0,     0,     0,     0,
     109,     0,    85,     0,     0,     0,     0,     0,     0,     0,
       0,   609,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   610,    86,     0,
       0,     0,   250,     0,     0,     0,     0,     0,     0,     0,
      86,     0,     0,     0,    90,   149,     0,     0,     0,    91,
       0,     0,   629,     0,   689,     0,    90,     0,     0,     0,
       0,    91,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    28,    29,    30,    31,    38,
      39,    40,    80,    81,    25,    26,     0,    82,   748,     0,
     749,     0,     0,     0,   757,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   150,     0,     0,     0,
       0,     0,     0,     0,     0,   748,     0,   749,     0,     0,
       0,   520,     0,   520,     0,   149,     0,     0,   750,     0,
       0,   519,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   751,   365,     0,     0,     0,   752,
       0,     0,     0,     0,   109,   750,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   751,     0,     0,     0,     0,   752,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   150,     0,     0,     0,
     629,     0,   520,     0,    86,     0,     0,     0,     0,   413,
     414,   415,     0,     0,   416,     0,     0,   417,   418,   419,
      90,   420,   421,   422,   423,    91,   425,   426,   427,   428,
     429,   430,     0,   431,   432,   433,   434,   435,     0,   436,
       0,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,     0,   641,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   252,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    28,    29,    30,    31,
      38,    39,    40,    80,    81,     0,   275,   276,    82,   277,
     190,     0,   191,   192,   193,   194,   195,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,     0,   210,     0,     0,     0,   278,   279,   280,
     281,   282,   283,   284,   211,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   212,     0,   213,   214,   215,     0,
       0,   216,   217,   594,   218,     0,   219,   220,   221,   222,
       0,   223,   224,     0,   225,     0,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    28,    29,    30,    31,    38,    39,    40,     0,
       0,    25,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   642,   644,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     654,     0,     0,     0,     0,   656,   657,   658,     0,     0,
     659,     0,     0,   660,     0,     0,     0,     0,   661,     0,
       0,   662,   663,     0,     0,     0,     0,     0,     0,   664,
       0,     0,     0,   665,     0,     0,     0,   666,     0,     0,
       0,     0,     0,   667,     0,     0,     0,   598,     0,     0,
       0,     0,   673,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   599,     0,     0,
     680,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   190,     0,   191,   192,   193,   194,   195,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,     0,   210,     0,     0,     0,
     278,   279,   280,   281,   282,   283,   284,   211,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   212,     0,   213,
     214,   215,     0,     0,   216,   217,     0,   218,     0,   219,
     220,   221,   222,     0,   223,   224,   739,   225,   740,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    28,    29,    30,    31,    38,
      39,    40,   464,   465,    25,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   252,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   115,   116,   117,   118,   119,     0,     0,     0,  -309,
       0,   190,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   120,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,     0,   210,     0,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   211,     0,     0,     0,   176,
       0,     0,     0,     0,     0,   212,     0,   213,   214,   215,
     120,     0,   216,   217,     0,   218,     0,   219,   220,   221,
     222,     0,   223,   224,     0,   225,     0,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,     0,     0,   115,   116,   117,   118,   119,     0,
       0,     0,     0,     0,     0,     0,     0,    38,    39,    40,
       0,     0,    25,    26,   120,     0,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    28,    29,    30,
      31,    38,    39,    40,    80,    81,    25,    26,     0,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    28,    29,    30,    31,
      38,    39,    40,    80,    81,    25,    26,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      28,    29,    30,    31,    38,    39,    40,    80,    81,    25,
      26,   252,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   275,   276,     0,   277,   190,     0,   191,
     192,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,     0,
     210,     0,     0,     0,   278,   279,   280,   281,   282,   283,
     284,   211,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   212,     0,   213,   214,   215,     0,     0,   216,   217,
       0,   218,     0,   219,   220,   221,   222,     0,   223,   224,
       0,   225,     0,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    28,
      29,    30,    31,    38,    39,    40,   252,     0,    25,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   190,     0,   191,   192,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,     0,   210,     0,     0,     0,   278,
     279,   280,   281,   282,   283,   284,   211,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   212,     0,   213,   214,
     215,     0,     0,   216,   217,     0,   218,     0,   219,   220,
     221,   222,     0,   223,   224,     0,   225,     0,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    28,    29,    30,    31,    38,    39,
      40,   599,     0,    25,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   190,     0,   191,
     192,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,     0,
     210,     0,     0,     0,   278,   279,   280,   281,   282,   283,
     284,   211,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   212,     0,   213,   214,   215,     0,     0,   216,   217,
       0,   218,     0,   219,   220,   221,   222,     0,   223,   224,
       0,   225,     0,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    28,
      29,    30,    31,    38,    39,    40,   189,     0,    25,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   190,     0,   191,   192,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,     0,   210,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   211,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   212,     0,   213,   214,
     215,     0,     0,   216,   217,     0,   218,     0,   219,   220,
     221,   222,     0,   223,   224,     0,   225,     0,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   252,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    39,
      40,     0,     0,    25,    26,     0,     0,     0,     0,   190,
       0,   191,   192,   193,   194,   195,   196,   197,   198,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,     0,   210,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   211,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   212,     0,   213,   214,   215,     0,     0,
     216,   217,     0,   218,     0,   219,   220,   221,   222,     0,
     223,   224,     0,   225,     0,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,    39,    40
  };

  /* YYCHECK.  */
  const short int
  MapSetParser::yycheck_[] =
  {
        11,   111,   198,    12,    13,    14,    15,    16,   385,   210,
     101,   179,   183,   179,   378,   183,   622,    42,    27,    44,
     111,    42,    41,   676,   134,    24,    28,    44,    44,    44,
      92,   695,    24,    53,    43,   482,   138,    42,   390,   391,
      27,    42,    51,   134,    16,    54,     0,    44,   166,    41,
      59,   367,    53,    25,   156,    45,    43,   409,    55,   132,
      45,   661,    20,    53,    21,   665,   139,    17,    53,    68,
     734,    41,    69,   241,    66,   241,   186,    56,    51,    41,
      51,    54,   253,    54,    25,   253,   162,   163,   164,   165,
     101,   100,   101,   171,   172,   186,    51,    33,    34,    54,
     111,    51,   111,   756,    54,   114,    55,   167,   105,   305,
      60,   173,    57,    12,   106,    14,    15,   166,   167,   168,
      44,   132,    42,   134,    41,   134,   137,   138,   139,   138,
     101,    55,   166,   153,    55,    48,   147,    42,   147,    48,
     111,   162,   163,   164,   165,   156,   101,   156,   153,   174,
     466,   101,   171,   172,   760,   602,   111,   174,   174,   174,
      44,   111,    55,   134,   166,   167,   168,   138,   179,   166,
     167,   168,   488,    22,    23,   186,   147,   186,    41,   134,
      95,   105,   132,   138,   134,   156,    57,   137,   138,   139,
     140,    30,   147,   275,   276,   277,   367,   147,    35,   367,
      96,   156,    44,   404,   538,   539,   156,   544,   545,    29,
     160,    54,   105,    55,    44,   186,    44,   166,   167,   168,
      53,    79,   171,   172,    26,    55,    44,    69,    44,   179,
     241,   186,    44,   183,    17,    18,   186,    44,    44,    69,
      44,    44,   166,   167,   168,   166,   167,   168,    44,    66,
      67,    44,    35,    44,   631,   619,    44,    44,    41,    44,
     271,    22,   273,   105,   273,    44,    49,    50,   378,    52,
      44,    44,    44,   166,   167,   168,    45,    46,    47,    60,
      61,    62,    63,    64,    65,    44,    44,   378,    44,    70,
      71,   241,   174,    44,   174,   466,    44,   468,   466,   166,
     167,   168,   273,   253,   171,   172,    44,    44,    44,    44,
      44,   322,    44,    44,   482,    44,   482,   488,   273,    44,
     488,   271,    44,   273,   166,   167,   168,    44,    44,   171,
     172,    44,    46,    47,    44,   536,   166,   167,   168,   156,
     157,   158,   159,   160,   161,    44,    44,   130,    44,    44,
      44,    44,    44,   364,    30,    42,   367,    48,     3,     4,
       5,     6,     7,     8,     9,    10,    11,   378,    13,   378,
     381,   382,    44,    44,   385,    94,   385,    45,    44,    34,
      33,   392,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     153,   153,   171,   172,    45,    59,    58,   378,   785,    71,
      45,    45,    45,    53,   385,    53,    53,   367,   614,    45,
      45,    53,    45,   378,   620,    45,    53,    45,   378,    45,
     385,   381,   382,    45,   602,   385,   602,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   466,    45,   171,   172,   397,
     398,   399,   400,   401,   402,    53,    45,    45,    53,    53,
      45,   482,    45,   482,    45,    45,    45,    45,    45,    53,
      45,    45,    45,   679,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    53,   174,    45,   619,
      45,   482,    53,    45,    45,    45,   466,    45,    45,    53,
      45,    45,    45,    44,    43,    45,    44,   482,   619,    68,
     107,    48,   482,    45,    45,    45,    45,    53,   488,    45,
      45,    45,    45,    45,    45,    53,    45,    45,    94,   153,
      45,    19,    45,    45,   504,    51,   506,   507,   754,    26,
      54,    42,   107,    54,    53,    80,    45,    45,    45,    36,
      37,    38,    39,    40,    60,   675,    42,    44,   774,   673,
     776,   483,   611,   241,   602,   466,   746,   373,   160,    56,
     253,   602,   372,   602,   668,   377,   304,   381,   134,   273,
     762,   271,   691,   504,   507,   693,   528,   526,   619,   540,
     619,   665,   407,   407,    -1,   782,    -1,    -1,    -1,    -1,
     631,    -1,   631,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   602,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   602,   619,    -1,
      -1,    -1,   602,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     631,    -1,    -1,    -1,   619,   676,    -1,    -1,    -1,   619,
      -1,    -1,   622,    -1,   624,    -1,   631,    -1,    -1,    -1,
      -1,   631,    -1,    -1,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,   174,   719,    -1,
     719,    -1,    -1,    -1,   725,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   676,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   746,    -1,   746,    -1,    -1,
      -1,   691,    -1,   693,    -1,   756,    -1,    -1,   719,    -1,
      -1,   762,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   719,   252,    -1,    -1,    -1,   719,
      -1,    -1,    -1,    -1,   785,   746,   785,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   746,    -1,    -1,    -1,    -1,   746,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   756,    -1,    -1,    -1,
     760,    -1,   762,    -1,   785,    -1,    -1,    -1,    -1,   306,
     307,   308,    -1,    -1,   311,    -1,    -1,   314,   315,   316,
     785,   318,   319,   320,   321,   785,   323,   324,   325,   326,
     327,   328,    -1,   330,   331,   332,   333,   334,    -1,   336,
      -1,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,    -1,    66,    67,   174,    69,
      70,    -1,    72,    73,    74,    75,    76,    77,    78,    79,
      -1,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    -1,    93,    -1,    -1,    -1,    97,    98,    99,
     100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,   116,   117,   118,    -1,
      -1,   121,   122,   460,   124,    -1,   126,   127,   128,   129,
      -1,   131,   132,    -1,   134,    -1,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
      -1,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   522,   523,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     547,    -1,    -1,    -1,    -1,   552,   553,   554,    -1,    -1,
     557,    -1,    -1,   560,    -1,    -1,    -1,    -1,   565,    -1,
      -1,   568,   569,    -1,    -1,    -1,    -1,    -1,    -1,   576,
      -1,    -1,    -1,   580,    -1,    -1,    -1,   584,    -1,    -1,
      -1,    -1,    -1,   590,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,   599,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,
     617,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    72,    73,    74,    75,    76,
      77,    78,    79,    -1,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    -1,    -1,    -1,
      97,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,   116,
     117,   118,    -1,    -1,   121,   122,    -1,   124,    -1,   126,
     127,   128,   129,    -1,   131,   132,   703,   134,   705,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    31,    32,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    -1,    -1,    -1,    44,
      -1,    70,    -1,    72,    73,    74,    75,    76,    77,    78,
      79,    56,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    40,   104,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,   114,    -1,   116,   117,   118,
      56,    -1,   121,   122,    -1,   124,    -1,   126,   127,   128,
     129,    -1,   131,   132,    -1,   134,    -1,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,    -1,    -1,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,   167,   168,
      -1,    -1,   171,   172,    56,    -1,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    44,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    -1,    69,    70,    -1,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,   116,   117,   118,    -1,    -1,   121,   122,
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
      -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,   116,   117,
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
     103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,   116,   117,   118,    -1,    -1,   121,   122,
      -1,   124,    -1,   126,   127,   128,   129,    -1,   131,   132,
      -1,   134,    -1,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    44,    -1,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    -1,    93,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,   116,   117,
     118,    -1,    -1,   121,   122,    -1,   124,    -1,   126,   127,
     128,   129,    -1,   131,   132,    -1,   134,    -1,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,   167,
     168,    -1,    -1,   171,   172,    -1,    -1,    -1,    -1,    70,
      -1,    72,    73,    74,    75,    76,    77,    78,    79,    -1,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,   116,   117,   118,    -1,    -1,
     121,   122,    -1,   124,    -1,   126,   127,   128,   129,    -1,
     131,   132,    -1,   134,    -1,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   167,   168
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  MapSetParser::yystos_[] =
  {
         0,   176,   177,     0,    20,   192,   193,   195,   166,   178,
     194,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      13,   179,   180,    21,   196,   171,   172,   369,   162,   163,
     164,   165,   409,   418,   409,   409,   409,   409,   166,   167,
     168,   419,   420,    56,   185,   186,   191,    12,    14,    15,
     181,    41,   183,   184,    16,   212,   214,   215,   197,   409,
      92,   173,   410,   411,   412,   409,    41,   187,   188,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     169,   170,   174,   182,   370,   409,   413,   414,   415,   416,
     417,   419,   421,   183,   370,    25,   167,   409,   419,    57,
     190,    42,    41,   297,   198,    42,   189,   409,   367,   369,
     370,   298,   213,   166,    48,    36,    37,    38,    39,    40,
      56,   299,   300,   303,   359,   360,   362,   363,   364,   367,
     216,   409,   361,    42,    48,   301,   302,   305,    44,   304,
      27,    43,   217,   222,   223,    55,   306,   317,   368,   369,
     419,   299,   306,   311,   312,   359,   365,   366,   367,   306,
      28,   218,   219,   220,   221,   419,    95,   224,   225,   229,
      41,   255,    57,   313,   316,   366,    45,   366,   221,    30,
      35,   202,   246,    96,   226,   232,   256,   310,   315,    44,
      70,    72,    73,    74,    75,    76,    77,    78,    79,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      93,   104,   114,   116,   117,   118,   121,   122,   124,   126,
     127,   128,   129,   131,   132,   134,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   230,   231,   289,   369,   394,   396,   398,   399,   400,
     419,   247,    44,   233,   234,   288,   289,   393,   394,    29,
     227,   235,   199,   200,   257,   258,   259,   263,   318,   359,
     367,    54,   309,    53,   314,    66,    67,    69,    97,    98,
      99,   100,   101,   102,   103,   369,   371,   372,   375,   378,
     379,   382,   383,   389,   391,   392,   393,   394,   401,   404,
     407,   409,   413,   417,   419,    79,    44,    44,    44,   174,
     395,    44,   174,   295,    44,    44,    44,   255,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,   295,
      44,    44,    44,    44,    44,   174,    44,   174,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
     231,    44,   174,   290,   248,   371,   234,    30,    33,    34,
     228,   241,   244,   245,    26,   203,    42,   262,    48,   264,
     265,   320,   319,   307,   308,   317,   316,   392,   392,   392,
      44,    44,    94,   206,   207,   374,   377,    60,    61,    62,
      63,    64,    65,    70,    71,   380,   381,   388,   390,    44,
     290,   408,   255,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   369,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,    22,
     292,    41,   369,    45,    31,    32,   236,   237,   238,   239,
     240,   288,   369,   153,   153,   242,   245,   243,   244,    22,
      23,   204,   205,   201,    17,    18,    49,    50,    52,   130,
     246,   261,   266,   267,   269,   273,   277,   278,   281,   282,
     287,   259,   312,   329,    44,    55,    69,   105,   321,   323,
     330,   331,   332,   333,   336,   339,   341,   347,   348,   369,
     419,   313,   292,   292,   369,    45,    58,   373,    59,   376,
     382,   382,   382,   382,   382,   382,    71,   295,    66,    67,
     384,   387,   415,   416,    24,    68,   385,   292,    45,    45,
      45,   296,    53,    53,    53,    45,    45,    53,    45,    45,
      53,    45,    45,    45,    45,    53,    45,    45,    53,    53,
      45,    45,    45,    45,    45,    45,    53,    45,    45,    45,
      53,    45,    45,    45,    53,    45,    45,    45,    45,    45,
      53,    45,    45,    45,   371,   252,   237,   393,    24,    44,
     208,   209,   210,   211,   289,   369,   394,   401,   409,   413,
     417,   222,   270,   274,   268,   279,   288,    44,    48,   260,
     283,   332,    44,    55,   105,   349,   354,   355,   357,   419,
     339,   322,   335,   338,    24,    41,    66,   106,   340,   342,
     346,    24,   371,   403,   371,   375,   378,   295,   389,   389,
     385,   386,   391,   391,   371,   294,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   291,    42,
      44,   174,   250,   371,   209,   224,   271,   275,   255,   280,
     371,   259,   255,    45,   352,   353,   355,    55,   356,   419,
     313,   107,   334,    68,   337,    53,   153,   345,   358,    45,
     402,    45,    45,    53,   293,    53,    45,    45,    45,    45,
     293,   397,    45,    45,    45,   397,    45,    45,   294,   251,
     207,   202,   368,   276,   255,    94,   286,    45,   351,   328,
     336,   341,   358,    42,    53,   344,    54,   405,   406,   371,
     371,    45,    45,    45,    46,    47,   249,   253,   369,   409,
     413,   417,   419,    45,   272,    19,   254,   369,    51,   284,
     107,   350,    54,   327,    42,    42,   343,   358,    80,    45,
      45,    45,   253,   255,   368,    45,   285,   355,   323,   324,
     326,    42,    60,   255,   255,   325,   418,   313
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
     253,   253,   253,   254,   254,   256,   255,   257,   257,   258,
     259,   259,   260,   260,   261,   262,   262,   263,   264,   265,
     265,   266,   266,   266,   266,   266,   266,   266,   266,   268,
     267,   270,   271,   272,   269,   274,   275,   276,   273,   277,
     279,   280,   278,   282,   283,   281,   285,   284,   286,   286,
     287,   288,   288,   288,   289,   290,   291,   290,   292,   292,
     293,   294,   294,   295,   296,   295,   298,   297,   299,   299,
     300,   301,   302,   302,   304,   303,   305,   303,   306,   307,
     308,   308,   309,   310,   310,   311,   312,   312,   313,   314,
     315,   315,   316,   317,   317,   319,   318,   320,   318,   322,
     321,   323,   323,   325,   324,   326,   326,   327,   328,   328,
     329,   330,   331,   332,   333,   334,   335,   335,   336,   337,
     338,   338,   339,   340,   340,   341,   341,   342,   343,   343,
     344,   344,   345,   345,   346,   346,   346,   346,   347,   348,
     348,   348,   348,   349,   350,   351,   351,   352,   353,   353,
     354,   354,   355,   356,   356,   357,   357,   357,   358,   359,
     359,   361,   360,   362,   363,   363,   363,   363,   363,   364,
     364,   365,   365,   366,   366,   367,   367,   368,   368,   369,
     369,   370,   370,   370,   370,   370,   370,   371,   372,   373,
     374,   374,   375,   376,   377,   377,   378,   379,   380,   380,
     381,   381,   381,   381,   381,   381,   381,   381,   382,   383,
     384,   384,   385,   385,   386,   386,   387,   387,   387,   388,
     388,   389,   390,   390,   391,   391,   391,   391,   392,   392,
     392,   392,   392,   392,   392,   392,   393,   394,   394,   394,
     394,   394,   394,   394,   394,   394,   394,   394,   394,   394,
     394,   394,   394,   394,   394,   394,   394,   394,   394,   394,
     394,   394,   394,   394,   394,   394,   394,   394,   394,   394,
     394,   394,   394,   394,   394,   394,   394,   394,   394,   394,
     394,   394,   394,   394,   394,   394,   394,   394,   395,   395,
     396,   397,   397,   398,   399,   400,   401,   401,   402,   401,
     403,   403,   404,   404,   404,   404,   404,   405,   406,   406,
     407,   408,   408,   409,   410,   411,   411,   412,   412,   413,
     413,   413,   414,   414,   414,   415,   415,   415,   416,   416,
     416,   417,   417,   418,   418,   418,   418,   419,   419,   420,
     420,   421,   421
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
       2,     1,     4,     4,     4,     4,     6,     6,     6,     6,
       6,     4,     4,     4,     4,     4,     4,     4,     4,     2,
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
       176,     0,    -1,    -1,   177,   192,   178,   179,    -1,    -1,
     178,   180,    -1,    -1,   179,   212,    -1,     3,   369,   409,
     409,    -1,     4,   409,    -1,     5,   409,    -1,     6,   409,
      -1,     7,   409,    -1,     8,   409,    -1,     9,   419,    -1,
      10,   185,    -1,    11,   181,    -1,    13,   184,    -1,    12,
      -1,    15,    -1,    14,    -1,    -1,   370,    -1,    41,   182,
      42,   367,    -1,   183,    -1,   184,   183,    -1,   186,   187,
      -1,    -1,   191,    -1,    -1,   188,    -1,    41,   190,    42,
      -1,   409,    48,   409,    -1,    -1,   190,   189,    -1,    56,
     409,    57,    -1,   193,   194,    -1,    -1,   195,    -1,    -1,
     194,   196,    -1,    20,   166,    -1,    -1,    -1,    21,   197,
     167,   198,   166,    -1,    -1,    -1,   200,   203,   201,   222,
     224,   202,    -1,    -1,   246,    -1,    26,   205,   211,    -1,
      22,    -1,    23,    -1,    -1,   204,    -1,    94,   369,    -1,
      -1,   206,    -1,    44,   371,   207,    45,    -1,   369,    -1,
     401,    -1,   394,    -1,   289,    -1,   409,    -1,   413,    -1,
     417,    -1,   208,    -1,   209,    -1,   210,   209,    -1,   210,
      -1,    24,    -1,    -1,   215,    25,   297,   213,   216,   222,
     224,   202,    -1,    16,   370,    -1,    -1,   214,    -1,    -1,
     216,   217,    -1,    27,   218,    -1,   219,    -1,   220,    -1,
     221,    -1,    28,   221,    -1,   419,    -1,   223,   255,    -1,
      -1,    43,    -1,   225,   226,   227,   228,    -1,    -1,   229,
      -1,    -1,   232,    -1,    -1,   235,    -1,    -1,   241,    -1,
      95,    30,   230,    -1,   231,    -1,   230,   231,    -1,   394,
      -1,   289,    -1,    44,   371,   207,    45,    -1,   369,    -1,
      96,   233,    -1,   234,    -1,   233,   234,    -1,   288,    -1,
      29,    30,   236,    -1,   237,    -1,   236,   237,    -1,   239,
      -1,   240,    -1,    31,    -1,    32,    -1,   238,   393,    -1,
     288,    -1,   369,    -1,   244,   242,    -1,   245,   243,    -1,
      -1,   245,    -1,    -1,   244,    -1,    33,   153,    -1,    34,
     153,    -1,    -1,    35,   247,   248,    41,   252,    42,    -1,
      -1,   248,   369,    -1,   253,    -1,   249,   253,    -1,    -1,
      44,   251,   249,    45,    -1,   174,    -1,    -1,   252,   250,
      -1,   419,    -1,   409,    -1,   413,    -1,   417,    -1,    46,
      -1,    47,    -1,   369,    -1,    -1,    19,    -1,    -1,    41,
     256,   257,    42,    -1,   199,    -1,   258,    -1,   259,   262,
      -1,    -1,   263,    -1,    -1,    48,    -1,   266,   260,   259,
      -1,    -1,   262,   261,    -1,   318,   265,    -1,    48,   259,
      -1,    -1,   264,    -1,   281,    -1,   267,    -1,   278,    -1,
     269,    -1,   273,    -1,   287,    -1,   277,    -1,   246,    -1,
      -1,    49,   268,   255,    -1,    -1,    -1,    -1,    17,   270,
     271,   368,   272,   255,    -1,    -1,    -1,    -1,    18,   274,
     275,   276,   254,   368,   255,    -1,   130,    44,   371,    94,
     369,    45,    -1,    -1,    -1,    50,   279,   280,   255,    -1,
      -1,    -1,   282,   283,   255,   286,    -1,    -1,    51,   285,
     255,    -1,    -1,   286,   284,    -1,    52,   288,    -1,   393,
      -1,   394,    -1,   289,    -1,   419,   290,    -1,   174,    -1,
      -1,    44,   292,   371,   291,   294,    45,    -1,    -1,    22,
      -1,    53,   371,    -1,    -1,   294,   293,    -1,   174,    -1,
      -1,    44,   371,   296,   294,    45,    -1,    -1,    41,   298,
     299,    42,    -1,    -1,   300,    -1,   303,   302,    -1,    48,
     299,    -1,    -1,   301,    -1,    -1,   367,   304,   306,    -1,
      -1,   359,   305,   311,    -1,   317,   313,   310,    -1,   317,
     313,    -1,    -1,   307,    -1,    54,   308,    -1,    -1,   310,
     309,    -1,   312,    -1,    -1,   306,    -1,   316,   315,    -1,
      53,   316,    -1,    -1,   315,   314,    -1,   366,    -1,   368,
      -1,    55,    -1,    -1,   367,   319,   321,    -1,    -1,   359,
     320,   329,    -1,    -1,   323,   322,   313,   328,    -1,   330,
      -1,   331,    -1,    -1,   323,   325,   313,    -1,    -1,   324,
      -1,    54,   326,    -1,    -1,   328,   327,    -1,   312,    -1,
     332,    -1,   369,    -1,   333,    -1,   336,   335,    -1,   107,
     336,    -1,    -1,   335,   334,    -1,   341,   338,    -1,    68,
     341,    -1,    -1,   338,   337,    -1,   347,   340,    -1,    -1,
     342,    -1,   339,    -1,   105,   339,    -1,   346,    -1,    42,
      -1,   358,    42,    -1,    53,   343,    -1,    42,    -1,   358,
     344,    -1,    53,   358,    42,    -1,    24,    -1,   106,    -1,
      66,    -1,    41,   345,    -1,   348,    -1,   419,    -1,    55,
      -1,    69,   349,    -1,    44,   332,    45,    -1,   354,    -1,
     107,   355,    -1,    -1,   351,   350,    -1,   355,   351,    -1,
      -1,   352,    -1,   355,    -1,    44,   353,    45,    -1,   357,
      -1,   419,    -1,    55,    -1,   419,    -1,    55,    -1,   105,
     356,    -1,   153,    -1,   362,    -1,   360,    -1,    -1,    56,
     361,   306,    57,    -1,   364,    44,   365,    45,    -1,    36,
      -1,    37,    -1,    38,    -1,    39,    -1,    40,    -1,    -1,
     363,    -1,   366,    -1,   365,   366,    -1,   367,    -1,   359,
      -1,   369,    -1,   370,    -1,   369,    -1,   419,    -1,   171,
      -1,   172,    -1,   419,    -1,   409,    -1,   413,    -1,   417,
      -1,   421,    -1,   174,    -1,   372,    -1,   375,   374,    -1,
      58,   375,    -1,    -1,   374,   373,    -1,   378,   377,    -1,
      59,   378,    -1,    -1,   377,   376,    -1,   379,    -1,   382,
     380,    -1,    -1,   381,    -1,    60,   382,    -1,    61,   382,
      -1,    62,   382,    -1,    63,   382,    -1,    64,   382,    -1,
      65,   382,    -1,    71,   295,    -1,    70,    71,   295,    -1,
     383,    -1,   389,   388,    -1,   415,    -1,   416,    -1,    24,
     391,    -1,    68,   391,    -1,    -1,   385,    -1,    66,   389,
      -1,    67,   389,    -1,   384,   386,    -1,    -1,   388,   387,
      -1,   391,   390,    -1,    -1,   390,   385,    -1,    69,   392,
      -1,    66,   392,    -1,    67,   392,    -1,   392,    -1,   393,
      -1,   394,    -1,   407,    -1,   409,    -1,   413,    -1,   417,
      -1,   369,    -1,   401,    -1,    44,   371,    45,    -1,    81,
      44,   371,    45,    -1,    82,    44,   371,    45,    -1,    83,
      44,   371,    53,   371,    45,    -1,    84,    44,   371,    45,
      -1,    85,    44,   369,    45,    -1,    72,    44,   371,    45,
      -1,    73,    44,   371,    45,    -1,    74,   395,    -1,   121,
     174,    -1,   145,    44,   371,    45,    -1,   142,    44,   371,
      45,    -1,   134,    44,   371,    45,    -1,   128,    44,   371,
      45,    -1,    93,   295,    -1,   398,    -1,   148,    44,   371,
      45,    -1,   146,    44,   371,    45,    -1,   144,    44,   371,
      45,    -1,   140,    44,   371,    45,    -1,   131,    44,   371,
      53,   371,    45,    -1,   141,    44,   371,    53,   371,    45,
      -1,   147,    44,   371,    53,   371,    45,    -1,   116,    44,
     371,    53,   371,    45,    -1,   117,    44,   371,    53,   371,
      45,    -1,   118,    44,   371,    45,    -1,   150,    44,   371,
      45,    -1,   143,    44,   371,    45,    -1,   139,    44,   371,
      45,    -1,   136,    44,   371,    45,    -1,   132,    44,   371,
      45,    -1,   127,    44,   371,    45,    -1,   126,    44,   371,
      45,    -1,   124,   174,    -1,   114,    44,   371,    45,    -1,
     149,    44,   371,    45,    -1,   138,    44,   371,    45,    -1,
     129,    44,   371,    45,    -1,   122,    44,   371,    45,    -1,
      75,   295,    -1,    76,    44,   371,    53,   371,    53,   371,
      45,    -1,    77,    44,   371,    53,   371,    45,    -1,    78,
      44,   371,    53,   371,    45,    -1,    86,    44,   371,    53,
     371,    45,    -1,    87,    44,   371,    45,    -1,    88,    44,
     371,    45,    -1,    89,    44,   371,    45,    -1,    90,    44,
     371,    45,    -1,   104,    44,   371,    45,    -1,   396,    -1,
     399,    -1,   400,    -1,    44,   371,    45,    -1,   174,    -1,
      91,    44,   371,    53,   371,   397,    45,    -1,    -1,   293,
      -1,   137,    44,   371,    53,   371,   397,    45,    -1,    79,
     255,    -1,    70,    79,   255,    -1,    97,    44,   292,   403,
      45,    -1,   404,    44,   292,   371,    45,    -1,    -1,   102,
      44,   292,   371,   402,   406,    45,    -1,    24,    -1,   371,
      -1,    98,    -1,    99,    -1,   100,    -1,   101,    -1,   103,
      -1,    54,    80,    60,   418,    -1,    -1,   405,    -1,   419,
     408,    -1,    -1,   290,    -1,   418,   412,    -1,    92,   419,
      -1,   173,    -1,   410,    -1,    -1,   411,    -1,   414,    -1,
     415,    -1,   416,    -1,   153,    -1,   154,    -1,   155,    -1,
     156,    -1,   157,    -1,   158,    -1,   159,    -1,   160,    -1,
     161,    -1,   151,    -1,   152,    -1,   162,    -1,   164,    -1,
     163,    -1,   165,    -1,   166,    -1,   420,    -1,   168,    -1,
     167,    -1,   169,    -1,   170,    -1
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
    1015,  1022,  1027,  1032,  1037,  1042,  1047,  1052,  1057,  1062,
    1065,  1070,  1075,  1080,  1085,  1090,  1093,  1102,  1109,  1116,
    1123,  1128,  1133,  1138,  1143,  1148,  1150,  1152,  1154,  1158,
    1160,  1168,  1169,  1171,  1179,  1182,  1186,  1192,  1198,  1199,
    1207,  1209,  1211,  1213,  1215,  1217,  1219,  1221,  1226,  1227,
    1229,  1232,  1233,  1235,  1238,  1241,  1243,  1245,  1246,  1248,
    1250,  1252,  1254,  1256,  1258,  1260,  1262,  1264,  1266,  1268,
    1270,  1272,  1274,  1276,  1278,  1280,  1282,  1284,  1286,  1288,
    1290,  1292,  1294
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
    2140,  2143,  2146,  2149,  2152,  2155,  2159,  2162,  2165,  2168,
    2171,  2174,  2177,  2180,  2183,  2186,  2187,  2188,  2194,  2197,
    2204,  2211,  2214,  2218,  2224,  2231,  2238,  2241,  2245,  2245,
    2258,  2262,  2266,  2269,  2272,  2275,  2278,  2284,  2290,  2293,
    2297,  2307,  2310,  2315,  2323,  2330,  2334,  2342,  2346,  2350,
    2351,  2352,  2356,  2357,  2358,  2362,  2363,  2364,  2368,  2369,
    2370,  2374,  2375,  2379,  2380,  2381,  2382,  2386,  2387,  2391,
    2392,  2396,  2397
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
  const int MapSetParser::yylast_ = 2117;
  const int MapSetParser::yynnts_ = 247;
  const int MapSetParser::yyempty_ = -2;
  const int MapSetParser::yyfinal_ = 3;
  const int MapSetParser::yyterror_ = 1;
  const int MapSetParser::yyerrcode_ = 256;
  const int MapSetParser::yyntokens_ = 175;

  const unsigned int MapSetParser::yyuser_token_number_max_ = 429;
  const MapSetParser::token_number_type MapSetParser::yyundef_token_ = 2;


} // w3c_sw

/* Line 1136 of lalr1.cc  */
#line 4869 "lib/MapSetParser/MapSetParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 2403 "lib/MapSetParser/MapSetParser.ypp"
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


