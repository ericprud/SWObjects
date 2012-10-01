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
#line 41 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


#include "SPARQLfedParser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 319 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"

/* Line 299 of lalr1.cc  */
#line 473 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lexWrapper


/* Line 299 of lalr1.cc  */
#line 66 "lib/SPARQLfedParser/SPARQLfedParser.cpp"

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
#line 152 "lib/SPARQLfedParser/SPARQLfedParser.cpp"

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  SPARQLfedParser::yytnamerr_ (const char *yystr)
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
  SPARQLfedParser::SPARQLfedParser (class SPARQLfedDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  SPARQLfedParser::~SPARQLfedParser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  SPARQLfedParser::yy_symbol_value_print_ (int yytype,
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
  SPARQLfedParser::yy_symbol_print_ (int yytype,
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
  SPARQLfedParser::yydestruct_ (const char* yymsg,
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
  SPARQLfedParser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  SPARQLfedParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  SPARQLfedParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  SPARQLfedParser::debug_level_type
  SPARQLfedParser::debug_level () const
  {
    return yydebug_;
  }

  void
  SPARQLfedParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  SPARQLfedParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  SPARQLfedParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  SPARQLfedParser::parse ()
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
#line 37 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
    driver.yylloc = &yylloc;
}

/* Line 565 of lalr1.cc  */
#line 347 "lib/SPARQLfedParser/SPARQLfedParser.cpp"

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
#line 487 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 490 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 501 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	assert(driver.lastWhereClause != NULL);
	if ((yysemantic_stack_[(3) - (3)].p_BindingClause) != NULL) // got a bindings clause
	    driver.lastWhereClause->m_GroupGraphPattern = 
		driver.makeConjunction((yysemantic_stack_[(3) - (3)].p_BindingClause), driver.lastWhereClause->m_GroupGraphPattern);
	(yyval.p_Operation) = (yysemantic_stack_[(3) - (2)].p_Operation);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 545 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.startBindingSet();
      }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 548 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  ResultSet* r = driver.endBindingSet();
	  if ((yysemantic_stack_[(3) - (1)].p_RSName) != NULL) {
	      std::string s = (yysemantic_stack_[(3) - (1)].p_RSName)->name;
	      delete (yysemantic_stack_[(3) - (1)].p_RSName);
	      driver.bindingsMap[s] = r;
	      driver.curOp = (yysemantic_stack_[(3) - (2)].p_TableOperation);
	  } else {
	      // if ($<p_TableOperation>2 != NULL)
	      driver.curOp = driver.makeConjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), new BindingClause(r));
	  }
      }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 563 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = (yysemantic_stack_[(2) - (1)].p_RSName);
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 569 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = NULL;
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 579 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	throw std::runtime_error("need to partition out results set part of SimpleEngine::loadDataOrResults");
    }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 613 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 615 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 621 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 659 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 661 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 667 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 686 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow(false);
      }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 688 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 708 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 711 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 714 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 720 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 726 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 728 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 730 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 738 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 741 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause);
	(yyval.p_Operation) = new Select((yysemantic_stack_[(5) - (2)].p_Project).distinctness, (yysemantic_stack_[(5) - (2)].p_Project).varSet, (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
	driver.countStar = (yysemantic_stack_[(5) - (1)].p_parentCountStar);
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 750 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 753 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 761 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 764 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 768 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if ((yysemantic_stack_[(6) - (6)].p_BindingClause) != NULL)
	      (yysemantic_stack_[(6) - (4)].p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yysemantic_stack_[(6) - (6)].p_BindingClause), (yysemantic_stack_[(6) - (4)].p_WhereClause)->m_GroupGraphPattern);
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (3)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(6) - (2)].p_Project).distinctness, (yysemantic_stack_[(6) - (2)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(6) - (4)].p_WhereClause), (yysemantic_stack_[(6) - (5)].p_SolutionModifier))));
	  driver.countStar = (yysemantic_stack_[(6) - (1)].p_parentCountStar);
      }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 778 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 786 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 789 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 796 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 804 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 811 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 819 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 826 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 829 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 832 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 835 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 838 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 841 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 844 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 853 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 856 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 864 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 867 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 873 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(2) - (2)].p_Operation);
    }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 879 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.lastWhereClause = (yysemantic_stack_[(4) - (3)].p_WhereClause);
	  /* $1 is NO LONGER known to be a DefaultGraphPattern because of grammar restrictions. */
	  (yyval.p_Operation) = new Construct((yysemantic_stack_[(4) - (1)].p_TableOperation), (yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
      }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 884 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	SWObjectDuplicator dup(driver.atomFactory);
	(yysemantic_stack_[(4) - (3)].p_TableOperation)->express(&dup);
	driver.lastWhereClause = new WhereClause((yysemantic_stack_[(4) - (3)].p_TableOperation));
	(yyval.p_Operation) = new Construct(dup.last.tableOperation, (yysemantic_stack_[(4) - (1)].p_DatasetClauses), driver.lastWhereClause, (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 894 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause) ? (yysemantic_stack_[(5) - (4)].p_WhereClause) : new WhereClause(new DefaultGraphPattern());
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 902 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm))));
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 905 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_TTerm))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 913 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 916 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 923 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 931 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(4) - (3)].p_WhereClause);
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 939 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 951 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 957 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 963 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 970 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.ensureGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 984 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 991 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 999 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1007 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1015 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1023 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1030 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1033 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1040 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1043 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1046 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1049 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1055 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1061 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1064 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1076 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1083 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1087 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1097 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1105 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1108 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1116 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1125 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1132 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1136 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1144 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1152 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1159 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1165 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1175 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = (yysemantic_stack_[(2) - (2)].p_BindingClause);
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1181 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1188 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	OperationSet* ret = driver.root ? dynamic_cast<OperationSet*>(driver.root) : new OperationSet();
	ret->push_back((yysemantic_stack_[(2) - (2)].p_Operation));
	driver.root = ret;
      }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1192 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Operation) = driver.root;
	}
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 1230 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(4) - (2)].p_Silence), (yysemantic_stack_[(4) - (3)].p_URI), (yysemantic_stack_[(4) - (4)].p_URI));
    }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1236 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1239 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1246 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1253 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1260 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1266 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1272 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1278 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1284 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1290 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1296 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1304 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1312 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1319 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(6) - (1)].p_URI))
	    w3c_sw_NEED_IMPL("WITH <URI> (DELETE INSERT?|INSERT) ...");
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(6) - (2)].p_DeleteInsert).del, (yysemantic_stack_[(6) - (2)].p_DeleteInsert).ins, new WhereClause(driver.ensureGraphPattern()), (yysemantic_stack_[(6) - (4)].p_TableOperation));
	driver.curOp = NULL;
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1328 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1334 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1341 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1348 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1352 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1360 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("_QUsingClause_E_Star");
    }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1366 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(2) - (2)].p_TableOperation);
    }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1372 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = NULL;
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1379 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Delete) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1385 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = new Insert((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1391 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 1397 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1400 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 1406 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 1409 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 1420 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 1426 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1429 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("DEFAULT");
      }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 1432 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("NAMED");
      }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1435 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("ALL");
      }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 1442 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
	driver.curOp = NULL;
    }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 1449 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
    }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 1455 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 1457 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TableOperation) = driver.ensureGraphPattern();
	  driver.curOp = NULL;
      }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 1485 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 1490 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 1493 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 1496 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 1518 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	BindingsMap::const_iterator rs = driver.bindingsMap.find((yysemantic_stack_[(1) - (1)].p_RSName)->name);
	if (rs == driver.bindingsMap.end())
	    error(yylloc, std::string("") + "unknown named result set " + (yysemantic_stack_[(1) - (1)].p_RSName)->name);
	ResultSet* copy = new ResultSet(*rs->second);
	delete (yysemantic_stack_[(1) - (1)].p_RSName);
	BindingClause* b = new BindingClause(copy);
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, b) : b;
      }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 1537 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 1539 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 1611 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_BindingClause)) : (yysemantic_stack_[(1) - (1)].p_BindingClause);
    }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 1618 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Print(driver.curOp);
    }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 1624 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 1628 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 271:

/* Line 690 of lalr1.cc  */
#line 1640 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 1644 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 1646 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 1649 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 1657 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 1661 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 1663 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(6) - (5)].p_TTerm), driver.curOp, (yysemantic_stack_[(6) - (4)].p_Silence), driver.atomFactory, false));
      }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 1670 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 1674 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 1676 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  /*
	    serviceID,
	    from,
	    e_Silence
	    where
	   */
	  driver.lastWhereClause = (yysemantic_stack_[(8) - (8)].p_WhereClause);
	  driver.restoreFilter((yysemantic_stack_[(8) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction
	      ((yysemantic_stack_[(8) - (2)].p_TableOperation), new SADIGraphPattern((yysemantic_stack_[(8) - (5)].p_TTerm), (yysemantic_stack_[(8) - (4)].p_Silence), (yysemantic_stack_[(8) - (7)].p_TableOperation), (yysemantic_stack_[(8) - (8)].p_WhereClause)));
    }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 1691 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Bind(driver.ensureGraphPattern(), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
	// no more triples go into the current BGP, per
	//   http://www.w3.org/TR/sparql11-query/#sparqlTranslateGraphPatterns
	// test reference:
	//   http://www.sparql.org/query-validator?query=ASK+{+%3Fs+%3Fp+%3Fo+FILTER+%281%29+BIND+%282+AS+%3Fb%29+%3Fs2+%3Fp2+%3Fo2+FILTER+%283%29+BIND+%284+AS+%3Fd%29}&languageSyntax=SPARQL&outputFormat=algebra&linenumbers=false
	driver.curBGP = NULL;
    }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 1702 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = (yysemantic_stack_[(2) - (2)].p_BindingClause);
    }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 1713 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 1715 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
      }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 1717 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 1728 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
	driver.endBindingRow();
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 1736 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 1738 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 1745 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 1757 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 1763 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 1765 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 1768 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 1780 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 1783 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 1786 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 1789 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 1792 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 1795 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 1798 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 1804 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 1808 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 1810 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 1818 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 1822 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 1824 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 1832 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 1837 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.ensureGraphPattern());
      }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 1850 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    driver.ensureGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 1866 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 1874 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 1878 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 1881 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yysemantic_stack_[(6) - (4)].p_Expressions);
      }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 1888 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 1891 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 1898 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 1906 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 1920 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 1923 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 1926 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(5) - (3)].p_Expressions);
      }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 1933 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 1936 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 1978 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 1982 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::RDF_type;
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 2005 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 2013 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 2016 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
        }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 2031 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 2042 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 2066 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 2085 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 2113 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 2120 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 2131 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 2138 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 2150 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 2153 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::RDF_type;
    }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 2156 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 2159 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 2206 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 2210 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 2219 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(4) - (1)].p_listModifier) == LIST_exact) {
	    (yyval.p_TTerm) = driver.createBNode();
	    const TTerm* tail = (yyval.p_TTerm);
	    ProductionVector<const TTerm*>* members = (yysemantic_stack_[(4) - (3)].p_TTerms);
	    driver.ensureBasicGraphPattern();
	    for (unsigned i = 0; i < members->size(); i++) {
		// driver.curBGP->addTriplePattern
		//     (driver.atomFactory->getTriple(tail, TTerm::RDF_type, TTerm::RDF_List));
		driver.curBGP->addTriplePattern
		    (driver.atomFactory->getTriple(tail, TTerm::RDF_first, members->at(i)));
		const TTerm* nextTail = i == members->size()-1 ? (const TTerm*)TTerm::RDF_nil : driver.createBNode();
		driver.curBGP->addTriplePattern
		    (driver.atomFactory->getTriple(tail, TTerm::RDF_rest, nextTail));
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

  case 422:

/* Line 690 of lalr1.cc  */
#line 2247 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 2250 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 2253 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 2256 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 2259 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 2266 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 2274 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 2278 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 2290 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 2294 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject;
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 2302 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(4) - (1)].p_listModifier) == LIST_exact) {
	    (yyval.p_TTerm) = driver.createBNode();
	    const TTerm* tail = (yyval.p_TTerm);
	    ProductionVector<const TTerm*>* members = (yysemantic_stack_[(4) - (3)].p_TTerms);
	    driver.ensureBasicGraphPattern();
	    for (unsigned i = 0; i < members->size(); i++) {
		// driver.curBGP->addTriplePattern
		//     (driver.atomFactory->getTriple(tail, TTerm::RDF_type, TTerm::RDF_List));
		driver.curBGP->addTriplePattern
		    (driver.atomFactory->getTriple(tail, TTerm::RDF_first, members->at(i)));
		const TTerm* nextTail = i == members->size()-1 ? (const TTerm*)TTerm::RDF_nil : driver.createBNode();
		driver.curBGP->addTriplePattern
		    (driver.atomFactory->getTriple(tail, TTerm::RDF_rest, nextTail));
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

  case 436:

/* Line 690 of lalr1.cc  */
#line 2329 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 2333 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 2350 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 2357 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 2360 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 2371 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 2374 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 2377 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 2380 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 2384 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::RDF_nil; // !!! new GraphTerm_rule5($1);
    }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 2395 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 2404 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 2411 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 2414 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 2422 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 2431 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 2438 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 2441 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 2453 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 465:

/* Line 690 of lalr1.cc  */
#line 2466 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = NULL;
    }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 2474 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 2478 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 2482 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 2486 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 2490 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 2494 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 2498 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 2502 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = true;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 2514 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 2523 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 2526 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 2533 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 2536 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 2543 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 2551 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 2554 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 2558 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 486:

/* Line 690 of lalr1.cc  */
#line 2572 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 2575 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 2583 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 2592 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 2595 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 2602 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 2605 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 2608 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 2618 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 2621 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 2624 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 2627 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 2634 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 2640 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 2643 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 2646 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 2649 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 2652 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 2655 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
      (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), new TTermExpression(driver.atomFactory->getURI(driver.getBase())), NULL));
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 2658 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
      (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), new TTermExpression(driver.atomFactory->getURI(driver.getBase())), NULL));
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 2662 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 2665 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 2668 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 2671 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ceil, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 2674 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 2677 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 2680 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 2684 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 2688 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 2691 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 2694 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 2697 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 2700 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 2703 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 2706 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 2709 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 2712 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 2715 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 2718 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 2721 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 2724 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 2727 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 2730 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 2733 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_tz, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 2736 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 2739 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_uuid, NULL, NULL, NULL));
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 2742 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_struuid, NULL, NULL, NULL));
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 2745 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 2748 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 2751 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 2754 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 2757 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 2760 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 2763 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 2766 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 2769 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 2772 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 2775 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 2778 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 2781 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 2784 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 2787 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 2798 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 2801 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 2808 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 2815 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 2822 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 2828 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_replace, (yysemantic_stack_[(9) - (3)].p_Expression), (yysemantic_stack_[(9) - (5)].p_Expression), (yysemantic_stack_[(9) - (7)].p_Expression))); // !! , $8
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 2834 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 2837 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 2841 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expression) = new ExistsExpression(driver.ensureGraphPattern());
	  driver.curOp = (yysemantic_stack_[(4) - (3)].p_TableOperation);
	  driver.countStar = (yysemantic_stack_[(4) - (2)].p_parentCountStar);
      }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 2849 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
      }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 2852 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 2856 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  // $$ = new ExistsExpression(false, driver.ensureGraphPattern());
	  (yyval.p_Expression) = new BooleanNegation(new ExistsExpression(driver.ensureGraphPattern()));
	  driver.curOp = (yysemantic_stack_[(5) - (4)].p_TableOperation);
	  driver.countStar = (yysemantic_stack_[(5) - (3)].p_parentCountStar);
      }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 2865 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 2869 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 2874 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  AggregateCall::ScalarVals svals;
	  if ((yysemantic_stack_[(6) - (5)].p_RDFLiteral) != NULL)
	      svals["separator"] = (yysemantic_stack_[(6) - (5)].p_RDFLiteral)->getLexicalValue();
	  (yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression), svals));
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 2883 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 2890 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 2893 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 2896 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 2899 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 2902 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 2908 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 2914 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 2921 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 2931 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 2939 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 2947 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 2954 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 2958 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 2966 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 690 of lalr1.cc  */
#line 3930 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  SPARQLfedParser::yysyntax_error_ (int yystate, int yytoken)
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
  const short int SPARQLfedParser::yypact_ninf_ = -856;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        45,  -100,    69,  -856,  -856,  -856,   695,  -856,  -856,  -856,
    -856,  -856,    71,    71,    71,    71,    55,     6,  -856,    43,
      71,    71,    55,    59,    71,    59,    51,  -856,    82,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,    84,   106,  -856,    43,    42,
     119,    42,  -856,    39,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,   146,  -856,  -856,  -856,  -856,  -856,    50,  -856,
      36,    36,  -856,  -856,  -856,    36,  -856,    -6,  -856,  -856,
    -856,    89,  -856,   463,    55,    55,  -856,   130,  -856,  -856,
      54,  -856,   126,    43,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,   100,  1271,    13,    55,  -856,    50,  -856,    38,  -856,
      60,     4,  -856,  -856,   108,    43,   118,   117,   161,  -856,
    -856,   -67,  -856,    -3,  -856,  -856,  -856,  1628,    50,  -856,
    -856,    97,  -856,  -856,    22,  -856,  -856,    -8,   125,  -856,
    -856,  -856,   119,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,   233,  -856,  -856,  -856,  -856,   240,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,   -55,  -856,
    -856,    43,  -856,  -856,  -856,  -856,  -856,    60,    60,    60,
    -856,   270,  -856,   195,  -856,  -856,  -856,  -856,  -856,    36,
    -856,    36,  -856,    36,  -856,  -856,  -856,   257,  -856,  2059,
     230,   266,   269,    12,    14,   274,   281,   282,   289,  -856,
     293,   297,   298,   301,   304,   305,   307,   309,   310,   314,
     315,    14,   316,  -856,  -856,  -856,  -856,   318,  -856,   320,
     123,   174,   324,   326,   328,   330,   184,   349,   204,   352,
     353,   355,   356,   360,   361,   362,   363,   364,   365,   370,
     373,   376,   377,   379,   382,   384,   385,   386,   388,   390,
     391,  -856,  -856,  2180,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,   392,  -856,  -856,  -856,    15,    60,
      45,  -856,  -856,    55,    16,  -856,   394,  -856,  -856,  -856,
      57,  -856,   155,   429,  1271,  -856,  -856,   155,  1889,   155,
      43,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  2422,
    2549,   413,  -856,   926,  -856,  -856,  -856,   402,    28,  -856,
    2059,  2301,  2301,  2301,  -856,   350,  -856,  -856,  -856,  -856,
     467,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,    15,  -856,  2059,  2059,  2059,  -856,  -856,  2059,
    -856,  -856,  2059,  2059,  2059,  2059,  -856,  2059,  2059,  2059,
    2059,   -67,  2059,  2059,  2059,  2059,  2059,  2059,  -856,   422,
     422,  2059,  -856,  -856,  2059,  2059,  2059,  2059,  -856,  2059,
    -856,  2059,  2059,  2059,  2059,  2059,  2059,  2059,  2059,  2059,
    2059,  2059,  2059,  2059,  2059,  2059,  2059,  2059,  2059,  2059,
    2059,  2059,  2059,  -856,   422,   422,  -856,  -856,  -856,   677,
    -856,  -856,    43,  -856,  -856,     4,   264,  -856,   573,  -856,
    -856,  1161,  -856,  -856,   338,  -856,  -856,   290,  -856,  -856,
    -856,  -856,   398,  1889,  -856,  -856,   403,   447,  -856,  -856,
    -856,  -856,  -856,    79,  -856,  -856,  -856,  -856,  2059,  2422,
    -856,  -856,  -856,  -856,  2549,  -856,  -856,  -856,  -856,  -856,
     428,    99,  -856,  -856,  -856,    82,   417,  -856,  -856,  -856,
     412,   418,  -856,  -856,  -856,  -856,  -856,  -856,  -856,    -5,
     416,  -856,  -856,  -856,   -67,  -856,   419,   411,   414,  2059,
    2059,  2059,  2059,  2059,  2059,   399,    14,  -856,  -856,   208,
      31,  -856,  -856,  -856,   425,   426,   436,  -856,   421,   430,
     431,   432,     4,   440,   442,   437,   443,   448,   444,   450,
     454,   455,   457,   451,  -856,  1465,  2059,   459,   460,   456,
     458,   464,   466,   469,   470,   471,   474,   468,   477,   478,
     479,   473,   487,   489,   494,   488,   496,   501,   502,   503,
     504,   505,   508,   509,   511,  2059,  2059,  -856,  -856,  -856,
      27,  -856,  -856,  -856,  1838,  -856,  -856,   367,  -856,  -856,
    -856,  -856,  -856,  -856,  1838,  -856,  -856,   334,  -856,    23,
    -856,     2,  -856,  -856,  -856,  -856,  -856,  1271,   146,  -856,
    -856,   350,  -856,  -856,  1749,   389,   393,  -856,  -856,   525,
     528,   227,  -856,  -856,    95,  1813,  -856,  -856,  1913,   227,
     227,  1075,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  2059,
    -856,  2059,  -856,  -856,  -856,  -856,  -856,  -856,  -856,    14,
    -856,  2059,  2059,    31,  -856,  -856,  -856,  2059,  2059,  -856,
       4,  -856,  -856,  -856,  -856,  2059,  2059,  2059,  2059,  -856,
    -856,  -856,  2059,  -856,  -856,  2059,  -856,  -856,  -856,  -856,
    2059,  -856,  -856,   516,   512,  -856,  -856,  2059,  2059,  -856,
    -856,  -856,  -856,  -856,  -856,  2059,  -856,  -856,  -856,  2059,
    -856,  -856,  -856,  2059,  -856,  -856,  -856,  -856,  -856,  2059,
    -856,  -856,  -856,   517,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,   -47,  -856,  -856,  -856,    78,  -856,  -856,  -856,
     514,   520,  -856,  -856,   523,  -856,  -856,  1749,  -856,   530,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
     268,  -856,   109,    94,   513,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,    61,  -856,  -856,   532,  -856,  -856,  -856,
      -6,  -856,  -856,  2549,   533,     4,  -856,   403,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  1865,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,    67,   524,   534,   536,   526,   539,   540,   535,
    -856,   510,  -856,   544,   546,   547,   550,   535,   552,   556,
    -856,  -856,  -856,  -856,  -856,   573,  -856,  -856,  1161,   155,
    -856,  1889,  -856,   562,  -856,  -856,  -856,   558,   218,  -856,
     103,  -856,  -856,  -856,  -856,  -856,  1913,   497,   538,  -856,
    -856,  -856,  -856,  -856,    60,  -856,  -856,  -856,  -856,     4,
    -856,  -856,  2059,  -856,  1813,     4,  -856,  -856,  1109,  -856,
    2059,  -856,  2059,  -856,  -856,  2059,  -856,  -856,  -856,   561,
     549,  -856,  -856,  -856,  -856,   564,  -856,  -856,    75,  2407,
    -856,  -856,  -856,  -856,  1889,  -856,  -856,  -856,  -856,   565,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,   268,  -856,   268,
    -856,    51,   146,    71,    71,  -856,     4,   518,  -856,  -856,
    -856,  -856,  -856,   568,   535,  -856,   198,  -856,  -856,  -856,
    -856,   571,    21,  -856,  1271,  -856,   519,   567,   572,  -856,
    -856,  -856,  -856,   146,   146,  -856,   -67,   575,  -856,   582,
    -856,  -856,  -856,  1838,  1838,  1838,   587,   218,  -856,   227,
    -856,  1913,  -856,     4,     4,   604,   586,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,    55,  -856,     4,  1889,   532,  -856,  -856,  -856
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        12,     0,     0,     2,     4,     3,   198,    14,    13,    10,
      68,     1,   182,   182,   182,   182,    74,     0,    74,     0,
     182,   182,     0,     0,   182,     0,   160,     6,     0,     7,
       8,     9,   162,   170,   171,   172,   176,   173,   174,   175,
     177,   178,   179,   180,   199,     0,    16,   183,     0,     0,
       0,     0,   225,     0,   100,    74,   107,   611,   614,   613,
     446,   447,   106,    74,   104,   444,   445,   612,   118,   197,
     216,   216,   195,   225,   194,   216,   193,   285,     5,   161,
     158,    82,    74,   198,     0,     0,   204,   200,   203,    69,
      11,    15,   185,     0,   221,   220,   222,   219,   187,   189,
     188,     0,   227,     0,     0,    75,   118,   105,   108,   119,
     121,     0,   217,   214,     0,     0,     0,     0,     0,   159,
     283,     0,   284,     0,    80,    81,    83,     0,   118,   169,
     163,   165,   209,   210,   207,   202,   201,     0,     0,    17,
      22,    18,     0,   186,   181,   218,   223,   422,   423,   424,
     425,   426,   419,   605,   606,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   607,   609,   608,   610,   615,   616,
     453,   232,   228,   240,   339,   418,   417,   428,     0,   337,
     442,   443,   449,   450,   593,   594,   595,   451,   591,   448,
     452,     0,   111,   112,   113,   114,   116,   121,   121,   121,
     109,     0,   110,   123,   122,   246,   243,   117,   242,   216,
     215,   216,   224,   216,   286,   293,   295,     0,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   565,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   576,   577,   578,   579,     0,   580,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    96,    98,    79,    94,    92,    88,   555,   518,
     520,   556,   557,    93,     0,    89,    90,    91,     0,   121,
      12,   166,   167,     0,     0,   208,     0,   205,    70,    20,
       0,   184,     0,   226,   227,   241,   238,   342,   427,     0,
       0,   589,   590,   592,   587,   115,   102,   101,   103,     0,
       0,   125,   124,   249,   190,   192,   191,     0,     0,   302,
       0,     0,     0,     0,   501,    85,   454,   457,   461,   463,
     465,   475,   486,   489,   494,   495,   496,   502,   497,   498,
     499,   500,   585,   568,     0,     0,     0,   559,   511,     0,
     334,   545,     0,     0,     0,     0,   566,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   517,   329,
     329,     0,   538,   539,     0,     0,     0,     0,   512,     0,
     537,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,   329,   329,   326,   325,    73,   198,
     164,   206,     0,   211,   212,     0,     0,    56,     0,    31,
      45,     0,    19,    23,     0,    29,    24,     0,    43,    25,
      26,   352,     0,   427,   351,   233,   229,     0,   239,   340,
     341,   343,   439,   427,   429,   438,   338,   588,     0,   129,
     130,   133,   135,   132,   136,   137,   139,   324,   322,   323,
       0,   127,   126,   433,   244,     0,     0,   245,   252,   250,
     256,     0,   360,   432,   431,   358,   288,   296,   294,     0,
       0,   492,   493,   491,     0,    86,     0,   455,   459,     0,
       0,     0,     0,     0,     0,     0,     0,   464,   466,   476,
     488,   586,   584,   569,     0,     0,     0,   335,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   330,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   213,   196,    71,
       0,   308,    35,   309,    36,    32,    33,     0,   310,   305,
     306,   307,   304,    49,    50,    46,    47,     0,    29,     0,
      43,     0,   420,   349,   355,   357,   230,   227,     0,   421,
     430,    85,   131,   138,     0,     0,     0,   120,   128,   152,
     154,     0,    77,   247,   314,   249,   257,   254,   427,   363,
       0,     0,   292,   299,   301,   303,   503,    84,    87,     0,
     458,     0,   462,   467,   468,   469,   470,   471,   472,     0,
     473,     0,     0,   481,   487,   477,   478,     0,     0,   490,
       0,   509,   510,   558,   332,     0,     0,     0,     0,   567,
     504,   505,     0,   507,   508,     0,   550,   551,   552,   553,
       0,   574,   575,     0,   582,   554,   540,     0,     0,   529,
     544,   536,   535,   516,   543,     0,   534,   515,   533,     0,
     542,   532,   523,     0,   514,   531,   522,   513,   521,     0,
     519,   541,   530,     0,   327,    55,    58,    57,    34,    39,
      48,    53,     0,    28,    37,    30,     0,    42,    51,    44,
     344,   353,   231,   235,     0,   145,   146,   140,   141,     0,
     143,   144,   148,   149,   156,   157,   150,   153,   151,   155,
       0,   401,     0,     0,     0,   365,   367,   368,   376,   383,
     386,   395,   390,   393,   377,   400,   118,   271,   275,   278,
     285,   269,   311,     0,     0,     0,   253,   229,   267,   259,
     261,   262,   263,   265,   266,   260,   258,   315,   264,   255,
     441,   427,   436,   440,   361,   362,   364,   359,   287,   289,
     290,   297,   456,   460,   474,   483,   484,   482,   485,   479,
     480,   570,     0,     0,     0,     0,     0,     0,     0,   561,
     571,     0,   583,     0,     0,     0,     0,   561,     0,     0,
     572,   332,    63,    40,    27,     0,    54,    41,     0,   346,
     350,   427,   356,     0,   134,   142,   147,     0,   410,   413,
       0,   402,   404,   412,   396,   434,   427,   384,   388,   398,
     399,   397,   392,   394,   121,   272,   276,   279,   282,     0,
     312,   321,     0,   268,   249,     0,   435,   437,     0,   336,
       0,   333,     0,   547,   548,     0,   506,   549,   562,     0,
       0,   573,   527,   528,   524,     0,   525,   526,     0,     0,
      38,    52,   347,   348,   427,   354,   236,   403,   411,     0,
     407,   416,   414,   415,   374,   380,   382,     0,   387,     0,
     391,   160,     0,   182,   182,   270,     0,     0,   251,   319,
     300,   298,   331,     0,   561,   560,     0,   563,   328,    59,
      64,    60,     0,   345,   227,   405,   409,   366,   378,   385,
     389,    78,   273,     0,     0,   313,     0,   316,   546,     0,
     581,    61,    62,     0,     0,     0,     0,     0,   408,   371,
     375,   427,   381,     0,     0,     0,     0,   317,   320,   564,
      67,    66,    65,   237,   406,   369,   372,   373,   379,   274,
     277,     0,   281,     0,   427,   118,   318,   370,   280
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -856,  -856,  -856,  -856,  -856,  -856,   331,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,    34,  -856,   190,  -856,
    -200,  -856,  -856,    52,  -856,  -856,    37,  -856,   191,  -856,
    -199,  -856,  -856,    47,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,   262,
    -856,  -856,  -856,   159,  -856,  -856,  -856,    40,  -856,   369,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,  -147,   -96,  -856,  -179,  -856,  -856,  -856,
    -856,  -856,  -856,   178,  -856,  -856,   172,  -856,  -856,   -89,
    -856,  -856,  -856,  -856,  -856,  -856,    30,    49,  -268,  -856,
    -856,   354,  -856,  -856,  -856,  -856,  -856,   574,  -856,    -7,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
     585,  -856,  -856,    18,  -856,     9,   608,   -21,   630,   596,
    -856,  -299,  -104,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -432,  -856,  -856,  -856,  -856,  -602,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,   -95,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,  -416,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,  -584,  -103,   312,  -856,  -319,  -754,
    -155,  -230,  -856,  -856,  -856,  -856,  -856,  -856,  -245,  -856,
    -856,  -856,  -856,  -161,  -855,  -856,  -856,  -162,  -856,  -856,
    -856,  -856,  -856,  -461,  -856,  -289,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -290,   -68,  -856,  -856,
    -856,  -234,  -856,  -856,   -66,  -856,  -229,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,  -801,  -856,   -98,  -856,  -856,  -856,
    -856,  -304,  -856,  -311,  -856,  -856,  -856,  -856,  -264,  -601,
     -93,   -12,    35,  -856,   804,  -856,  -856,  -856,    53,  -856,
    -856,    56,  -856,  -856,  -856,  -125,  -856,  -856,    41,  -856,
    -856,  -856,  -410,  -856,  -359,  -166,  -309,  -111,  -856,  -856,
    -788,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,   -99,
    -856,  -856,  -856,  -856,  -856,  -856,    77,  -856,  -856,  -856,
     177,  -856,   176,   180,   531,  -243,   -17,  -856,  -856
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,    26,     5,     6,     7,    46,    90,
     139,   310,   140,   141,   442,   443,   599,   444,   445,   584,
     585,   725,   835,   586,   834,   446,   601,   447,   448,   594,
     595,   729,   838,   596,   837,   449,   580,   717,   832,   962,
     940,   899,   941,     8,    91,   137,   436,    27,    28,    53,
     484,   485,   766,    82,   126,   127,   505,   506,   281,   282,
     283,   284,    29,    54,    30,    62,    63,   199,    31,   105,
     192,   193,   194,   195,   110,   111,   202,   203,   331,   481,
     617,   204,   469,   470,   332,   474,   475,   482,   737,   738,
     739,   740,   741,   618,   746,   748,   619,   620,    78,    79,
      80,     9,    83,   301,   302,   129,   130,    32,    33,    48,
     143,   144,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,   135,    86,   134,   305,   306,    87,
      88,   307,   433,   114,   115,    97,    98,    55,    74,   101,
     102,   171,   607,   455,   313,   456,   457,   843,   944,   172,
     315,   316,   207,   486,   208,   333,   487,   488,   776,   624,
     489,   626,   627,   777,   778,   779,   869,   780,   865,   922,
     973,   781,   866,   923,   782,   867,   924,   783,   784,   119,
     120,   121,   337,   631,   799,   122,   123,   338,   217,   878,
     635,   801,   499,   587,   785,   870,   926,   786,   787,   875,
     978,   993,   957,   788,   476,   477,   427,   831,   545,   888,
     812,   371,   664,   173,   319,   317,   459,   460,   452,   902,
     903,   840,   730,   453,   603,   842,   731,   604,   490,   630,
     629,   794,   795,   754,   856,   755,   986,   994,   987,   970,
     947,   756,   757,   914,   972,   948,   915,   758,   759,   918,
     857,   760,   920,   858,   761,   862,   762,   863,   763,   851,
     968,   946,   908,   909,   852,   912,   462,   175,   312,   176,
     177,   178,   463,   790,   493,   621,   494,   791,   605,   916,
     465,   454,   344,   181,   345,   346,   640,   507,   347,   642,
     508,   348,   349,   517,   518,   350,   351,   653,   659,   808,
     654,   519,   352,   520,   353,   354,   355,   356,   368,   288,
     889,   289,   290,   291,   376,   532,   292,   523,   660,   357,
     683,   294,   822,   823,   358,   522,   359,   322,   323,   324,
     360,   184,   185,   186,   361,   188,   362,    67,   190
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int SPARQLfedParser::yytable_ninf_ = -428;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        66,    72,    69,   578,   174,    64,    49,    50,    51,   179,
     198,   388,   200,    70,    71,   458,   287,    75,   326,   327,
     328,   478,   492,   789,   285,   597,    56,   792,   293,   491,
     742,    92,   299,   632,   320,  -291,   633,   191,   215,   895,
     432,   205,   112,   303,   325,    66,   727,   910,    93,   943,
     107,   657,    65,   366,   464,   369,   425,   724,   881,    99,
       1,   103,   103,   132,   133,   715,    94,   723,   716,    11,
     497,   546,   461,   103,   466,  -118,   145,   963,   109,   104,
      10,   859,    77,   197,    47,   189,   196,    84,    85,   116,
     109,   -21,    52,   118,   437,   658,    73,    65,   210,    81,
     669,   767,   768,   769,   833,   575,   576,   124,   125,   879,
     298,   147,   148,   149,   150,   151,   880,   938,    60,    61,
     428,   609,    89,   860,   880,    93,   770,   724,   615,   616,
     304,   152,   321,  -248,    85,   750,   142,   180,   146,   997,
     771,   772,   113,   773,   881,   751,   959,   300,    95,    96,
     848,   311,   201,   742,   911,   212,   214,   728,   -21,   752,
     849,   438,   286,   450,   861,   478,   984,   206,   796,   797,
     964,   965,   287,   308,   196,   501,   502,   503,   597,   182,
     285,   309,  -291,   634,   293,   216,    57,    58,    59,   871,
     877,    60,    61,    57,    58,    59,    57,    58,    59,   610,
     367,  -118,   370,   426,   295,   -21,   451,   -21,   439,   -21,
     440,   850,   441,    60,    61,   800,   174,   138,   473,   479,
     209,   179,   774,    57,    58,    59,   471,   334,   811,   335,
     211,   336,   836,   728,   -21,   -21,   -21,    57,    58,    59,
     495,   805,   806,   775,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    57,
      58,    59,   168,   169,    60,    61,   298,   170,   750,   849,
     651,   652,   928,   213,    57,    58,    59,   314,   751,   183,
      68,   318,   431,    57,    58,    59,   650,   434,   330,    57,
      58,    59,   752,   196,   339,    66,   329,   189,   809,   810,
      66,   189,    66,   467,   296,   478,   363,   364,   732,   750,
     365,   392,   298,   298,   492,   372,   189,   106,   286,   751,
     850,   491,   373,   374,   491,   108,    57,    58,    59,   753,
     375,    60,    61,   752,   377,    57,    58,    59,   378,   379,
      60,    61,   380,   873,   128,   381,   382,    65,   383,   180,
     384,   385,    65,   180,    65,   386,   387,   389,   473,   390,
     295,   391,   393,   479,   472,   394,   471,   395,   180,   396,
     753,   397,   398,   498,   164,   165,   166,   167,   158,   159,
     160,   161,   162,   163,   643,   644,   645,   646,   647,   648,
     399,   182,   400,   401,   402,   182,   403,   404,    57,    58,
      59,   405,   406,   407,   408,   409,   410,    57,    58,    59,
     182,   411,    60,    61,   412,   577,   537,   413,   414,   804,
     415,   592,   597,   416,   592,   417,   418,   419,   478,   420,
     846,   421,   422,   424,   435,  -234,   189,   925,   480,   496,
     544,   504,   438,   929,   579,   441,   189,   606,    57,    58,
      59,   602,   298,   608,   614,   623,   625,   298,   636,   628,
     296,   638,   931,  -168,   478,   639,   649,   661,   662,   641,
     665,   719,    12,   588,    13,    14,   588,    15,   663,   666,
     667,   668,   670,   942,   671,   673,   672,   491,   180,   721,
     674,   183,   676,   675,   955,   183,   677,   678,   180,   679,
     680,   685,   686,   479,   472,   687,   689,   688,   690,   174,
     183,   691,   692,   693,   179,   589,   694,   695,   589,   696,
     697,   698,   699,   509,   510,   511,   512,   513,   514,   700,
     182,   701,   495,   515,   516,   793,   702,   703,   704,   637,
     182,   989,   990,   705,   706,   707,   708,   980,   981,   982,
     710,   711,   491,   712,   709,   616,   744,   615,   820,   830,
     745,   996,   821,   492,   839,   844,   855,   592,    19,   841,
     491,   340,   109,   882,   872,   885,   883,   592,   884,    20,
      21,   886,   887,    22,   880,    23,   891,   890,   892,   893,
     189,    66,   894,    24,   896,    25,   733,   298,   897,   906,
     907,   917,   919,   935,   765,   936,   937,   945,   189,   956,
     958,   189,   765,   765,   592,   590,   581,   969,   590,   588,
     961,   971,   977,   967,   979,   983,   479,   991,   992,   588,
     183,   429,   722,   187,   598,   900,   718,   726,   600,   901,
     183,   720,   180,    65,   622,   966,   613,   612,   845,   743,
     749,   734,   423,   951,   430,    76,   764,   131,   297,   100,
     180,   589,   479,   180,   764,   764,   588,   491,   747,   117,
     864,   589,   136,   874,   521,   868,   898,   582,   904,   905,
     985,   988,   847,   949,   182,   921,    12,   854,    13,    14,
     950,    15,   802,   960,   807,   655,     0,   803,   793,   656,
       0,     0,   182,     0,    12,   182,    13,    14,   589,    15,
       0,     0,   -72,     0,     0,     0,    16,    17,     0,     0,
     298,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   765,    18,   853,   765,   583,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    57,    58,    59,   298,     0,    60,    61,
       0,   590,     0,   793,     0,     0,     0,     0,     0,     0,
       0,   590,   743,     0,   189,     0,     0,     0,     0,     0,
       0,   495,    19,     0,   183,     0,     0,     0,     0,     0,
       0,     0,     0,    20,    21,     0,     0,    22,     0,    23,
      19,     0,   183,     0,     0,   183,     0,    24,   590,    25,
       0,    20,    21,     0,   297,    22,     0,    23,   592,     0,
       0,   592,    66,     0,   189,    24,   180,    25,     0,     0,
       0,   853,     0,   913,     0,     0,     0,     0,     0,   189,
       0,     0,     0,     0,     0,   187,   174,     0,     0,   187,
       0,   179,     0,     0,     0,     0,     0,   189,     0,     0,
       0,   592,     0,     0,   187,     0,     0,     0,   182,     0,
     588,     0,     0,   588,    65,     0,   180,     0,   793,     0,
       0,     0,   592,     0,     0,     0,     0,   189,     0,     0,
       0,   180,     0,     0,     0,     0,     0,     0,     0,   998,
     765,     0,   765,     0,     0,    66,     0,     0,     0,   180,
     952,     0,   589,   588,     0,   589,   953,   954,   182,     0,
       0,     0,     0,     0,     0,     0,     0,   189,     0,     0,
       0,     0,     0,   182,   588,     0,    66,    66,     0,   180,
       0,   974,   975,   -76,     0,     0,   592,   592,   592,     0,
     853,   182,   765,     0,   189,   589,     0,    65,   147,   148,
     149,   150,   151,     0,     0,     0,     0,  -427,   183,   591,
     995,     0,   591,     0,     0,     0,   589,   189,   483,   180,
       0,   182,     0,     0,   187,     0,     0,     0,    65,    65,
       0,   976,     0,     0,   187,     0,     0,     0,   588,   588,
     588,     0,     0,     0,   764,     0,   180,     0,     0,     0,
       0,     0,   590,     0,     0,   590,     0,     0,   183,     0,
       0,   182,     0,     0,     0,     0,     0,     0,     0,   180,
       0,     0,     0,   183,     0,     0,     0,     0,     0,     0,
     589,   589,   589,     0,     0,     0,     0,     0,   182,     0,
       0,   183,     0,     0,     0,   590,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   182,     0,     0,     0,     0,   590,     0,     0,     0,
       0,   183,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    57,    58,    59,   168,
     169,    60,    61,   798,   170,   591,     0,     0,   581,     0,
       0,   183,     0,     0,     0,   591,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   187,     0,
     590,   590,   590,     0,   500,     0,     0,     0,   183,     0,
       0,   930,   581,     0,     0,     0,   187,     0,     0,   187,
       0,     0,   591,     0,     0,     0,     0,     0,   524,   525,
     526,   183,     0,   527,     0,     0,   528,   529,   530,   531,
       0,   533,   534,   535,   536,     0,   538,   539,   540,   541,
     542,   543,     0,     0,     0,   547,     0,     0,   548,   549,
     550,   551,     0,   552,   581,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   583,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    57,    58,    59,     0,     0,
      60,    61,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   611,   583,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    57,
      58,    59,     0,     0,    60,    61,     0,     0,     0,     0,
       0,     0,     0,   147,   148,   149,   150,   151,     0,     0,
       0,     0,  -427,     0,     0,     0,   593,     0,     0,     0,
       0,     0,   187,   152,     0,   583,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    57,    58,    59,     0,     0,    60,    61,     0,   682,
     684,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   591,     0,     0,   591,
       0,     0,   187,     0,     0,     0,     0,     0,     0,   713,
     714,     0,     0,     0,     0,     0,     0,   187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   187,     0,     0,     0,   591,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     591,     0,     0,     0,     0,   187,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    57,    58,    59,   168,   169,    60,    61,     0,   170,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   813,
     814,   815,   816,     0,     0,   187,   817,     0,     0,   818,
       0,     0,     0,     0,   819,   681,     0,     0,     0,     0,
       0,   824,   825,     0,   591,   591,   591,     0,     0,   826,
       0,     0,   187,   827,     0,     0,   340,   828,     0,     0,
       0,     0,     0,   829,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   187,     0,   341,   342,     0,
     343,   220,     0,   221,   222,   223,   224,   225,   226,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     0,   241,     0,     0,     0,   242,
     243,   244,   245,   246,   247,   248,   249,     0,     0,     0,
       0,     0,     0,     0,   250,   251,   252,     0,   253,   254,
     255,     0,     0,   256,   257,     0,   258,     0,   259,   260,
     261,   262,     0,   263,   264,     0,   265,     0,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    57,    58,    59,   218,     0,
      60,    61,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   219,
       0,     0,     0,     0,     0,     0,   927,     0,     0,     0,
       0,     0,     0,     0,   932,     0,   933,     0,     0,   934,
       0,     0,     0,     0,   220,     0,   221,   222,   223,   224,
     225,   226,   227,   228,   229,     0,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,     0,   241,     0,
       0,     0,   242,   243,   244,   245,   246,   247,   248,   249,
       0,     0,     0,     0,     0,     0,     0,   250,   251,   252,
       0,   253,   254,   255,     0,     0,   256,   257,     0,   258,
       0,   259,   260,   261,   262,     0,   263,   264,     0,   265,
       0,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   735,   736,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     340,     0,     0,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    57,    58,
      59,     0,     0,    60,    61,   220,     0,   221,   222,   223,
     224,   225,   226,   227,   228,   229,     0,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,     0,   241,
       0,     0,     0,     0,     0,   147,   148,   149,   150,   151,
     249,     0,     0,     0,  -427,     0,     0,     0,   250,   251,
     252,     0,   253,   254,   255,   483,     0,   256,   257,     0,
     258,     0,   259,   260,   261,   262,     0,   263,   264,     0,
     265,   581,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   147,   148,   149,
     150,   151,     0,     0,     0,     0,     0,   876,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   483,     0,     0,
       0,   147,   148,   149,   150,   151,     0,     0,     0,    57,
      58,    59,     0,     0,    60,    61,     0,     0,     0,     0,
       0,   152,     0,     0,     0,   147,   148,   149,   150,   151,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   483,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    57,    58,    59,   168,   169,    60,    61,
       0,   170,   583,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    57,    58,
      59,     0,     0,    60,    61,     0,     0,     0,     0,     0,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    57,    58,    59,   168,   169,
      60,    61,     0,   170,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    57,
      58,    59,   168,   169,    60,    61,     0,   170,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    57,    58,    59,   168,   169,    60,    61,
     340,   170,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   341,   342,     0,   343,   220,     0,   221,   222,   223,
     224,   225,   226,   227,   228,   229,     0,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,     0,   241,
       0,     0,     0,   242,   243,   244,   245,   246,   247,   248,
     249,     0,     0,     0,     0,     0,     0,     0,   250,   251,
     252,     0,   253,   254,   255,     0,     0,   256,   257,     0,
     258,     0,   259,   260,   261,   262,     0,   263,   264,     0,
     265,     0,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   219,     0,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    57,
      58,    59,     0,     0,    60,    61,   220,     0,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
     241,     0,     0,     0,   242,   243,   244,   245,   246,   247,
     248,   249,     0,     0,     0,     0,     0,     0,     0,   250,
     251,   252,     0,   253,   254,   255,     0,     0,   256,   257,
       0,   258,     0,   259,   260,   261,   262,     0,   263,   264,
       0,   265,     0,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   340,     0,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      57,    58,    59,     0,     0,    60,    61,   220,     0,   221,
     222,   223,   224,   225,   226,   227,   228,   229,     0,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
       0,   241,     0,     0,     0,   242,   243,   244,   245,   246,
     247,   248,   249,     0,     0,     0,     0,     0,     0,     0,
     250,   251,   252,     0,   253,   254,   255,     0,     0,   256,
     257,     0,   258,     0,   259,   260,   261,   262,     0,   263,
     264,     0,   265,     0,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   939,
     581,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   468,     0,     0,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    57,    58,    59,     0,     0,    60,    61,   220,     0,
     221,   222,   223,   224,   225,   226,   227,   228,   229,     0,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   249,     0,     0,     0,     0,     0,     0,
       0,   250,   251,   252,     0,   253,   254,   255,     0,     0,
     256,   257,     0,   258,     0,   259,   260,   261,   262,     0,
     263,   264,     0,   265,     0,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
       0,   583,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    57,    58,    59,
     340,     0,    60,    61,     0,     0,     0,     0,     0,     0,
       0,     0,    57,    58,    59,     0,     0,    60,    61,     0,
       0,     0,     0,     0,     0,   220,     0,   221,   222,   223,
     224,   225,   226,   227,   228,   229,     0,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,     0,   241,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     249,     0,     0,     0,     0,     0,     0,     0,   250,   251,
     252,     0,   253,   254,   255,     0,     0,   256,   257,     0,
     258,     0,   259,   260,   261,   262,     0,   263,   264,     0,
     265,     0,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
      58,    59
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        17,    22,    19,   435,   102,    17,    13,    14,    15,   102,
     106,   241,   108,    20,    21,   314,   127,    24,   197,   198,
     199,   330,   333,   625,   127,   441,    20,   628,   127,   333,
     614,    48,   128,    38,    89,    41,    41,    24,    41,   827,
      24,    37,     6,    21,   191,    62,    44,   848,     6,   904,
      62,    20,    17,    41,   318,    41,    41,   104,   812,    50,
      15,    23,    23,    84,    85,    38,    24,    44,    41,     0,
      42,   390,   317,    23,   319,    37,    93,    56,    40,    40,
     180,    20,    31,   104,    13,   102,   103,     3,     4,    71,
      40,    37,    37,    75,    37,    64,    37,    62,   115,    17,
     532,     6,     7,     8,   151,   424,   425,    18,    19,    42,
     127,    32,    33,    34,    35,    36,    49,    42,   185,   186,
     299,    42,    16,    62,    49,     6,    31,   104,    29,    30,
     108,    52,   187,    38,     4,    41,    10,   102,    38,   994,
      45,    46,   106,    48,   898,    51,   934,    50,   106,   107,
      41,   142,    92,   737,    51,    38,   121,   155,   104,    65,
      51,   104,   127,   310,   103,   474,   967,   163,   629,   630,
     149,   150,   283,   181,   191,   341,   342,   343,   594,   102,
     283,    56,   188,   188,   283,   188,   180,   181,   182,   773,
     791,   185,   186,   180,   181,   182,   180,   181,   182,   463,
     188,   163,   188,   188,   127,   151,    51,   153,   151,   155,
     153,   102,   155,   185,   186,   631,   314,   163,   329,   330,
     112,   314,   127,   180,   181,   182,   329,   209,   660,   211,
     112,   213,   154,   155,   180,   181,   182,   180,   181,   182,
     333,   651,   652,   148,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   283,   188,    41,    51,
      62,    63,   874,   112,   180,   181,   182,    44,    51,   102,
      18,    41,   303,   180,   181,   182,   516,   304,    93,   180,
     181,   182,    65,   310,    37,   312,    26,   314,   657,   658,
     317,   318,   319,   320,   127,   614,    76,    41,   607,    41,
      41,   188,   329,   330,   625,    41,   333,    55,   283,    51,
     102,   625,    41,    41,   628,    63,   180,   181,   182,   102,
      41,   185,   186,    65,    41,   180,   181,   182,    41,    41,
     185,   186,    41,   775,    82,    41,    41,   312,    41,   314,
      41,    41,   317,   318,   319,    41,    41,    41,   469,    41,
     283,    41,   188,   474,   329,    41,   469,    41,   333,    41,
     102,    41,   188,   338,   176,   177,   178,   179,   170,   171,
     172,   173,   174,   175,   509,   510,   511,   512,   513,   514,
      41,   314,   188,    41,    41,   318,    41,    41,   180,   181,
     182,    41,    41,    41,    41,    41,    41,   180,   181,   182,
     333,    41,   185,   186,    41,   432,   381,    41,    41,   649,
      41,   438,   838,    41,   441,    41,    41,    41,   737,    41,
     739,    41,    41,    41,    40,     6,   453,   869,    25,    37,
      18,    91,   104,   875,   180,   155,   463,    44,   180,   181,
     182,    53,   469,     6,    26,    38,    44,   474,    42,    41,
     283,    42,   878,     0,   773,    54,    67,    42,    42,    55,
      49,   104,     9,   438,    11,    12,   441,    14,    42,    49,
      49,    49,    42,   899,    42,    42,    49,   791,   453,   155,
      42,   314,    42,    49,   926,   318,    42,    42,   463,    42,
      49,    42,    42,   614,   469,    49,    42,    49,    42,   607,
     333,    42,    42,    42,   607,   438,    42,    49,   441,    42,
      42,    42,    49,    56,    57,    58,    59,    60,    61,    42,
     453,    42,   625,    66,    67,   628,    42,    49,    42,   504,
     463,   973,   974,    42,    42,    42,    42,   963,   964,   965,
      42,    42,   856,    42,    49,    30,   167,    29,    42,    42,
     167,   993,    50,   874,    50,    42,    53,   584,   105,    49,
     874,    41,    40,    49,    41,    49,    42,   594,    42,   116,
     117,    42,    42,   120,    49,   122,    42,    77,    42,    42,
     607,   608,    42,   130,    42,   132,   608,   614,    42,    37,
      42,   104,    64,    42,   621,    56,    42,    42,   625,    91,
      42,   628,   629,   630,   631,   438,    43,    50,   441,   584,
      49,    49,    47,   104,    42,    38,   737,    23,    42,   594,
     453,   300,   598,   102,   444,   835,   584,   600,   447,   838,
     463,   594,   607,   608,   485,   944,   474,   469,   737,   614,
     620,   611,   283,   921,   300,    25,   621,    83,   127,    51,
     625,   584,   773,   628,   629,   630,   631,   971,   619,    73,
     766,   594,    87,   777,   362,   770,   831,   104,   839,   841,
     969,   971,   750,   917,   607,   864,     9,   753,    11,    12,
     919,    14,   639,   936,   653,   519,    -1,   641,   791,   519,
      -1,    -1,   625,    -1,     9,   628,    11,    12,   631,    14,
      -1,    -1,    17,    -1,    -1,    -1,    21,    22,    -1,    -1,
     737,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   750,    39,   752,   753,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   773,    -1,   185,   186,
      -1,   584,    -1,   856,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   594,   737,    -1,   791,    -1,    -1,    -1,    -1,    -1,
      -1,   874,   105,    -1,   607,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,   117,    -1,    -1,   120,    -1,   122,
     105,    -1,   625,    -1,    -1,   628,    -1,   130,   631,   132,
      -1,   116,   117,    -1,   283,   120,    -1,   122,   835,    -1,
      -1,   838,   839,    -1,   841,   130,   791,   132,    -1,    -1,
      -1,   848,    -1,   850,    -1,    -1,    -1,    -1,    -1,   856,
      -1,    -1,    -1,    -1,    -1,   314,   944,    -1,    -1,   318,
      -1,   944,    -1,    -1,    -1,    -1,    -1,   874,    -1,    -1,
      -1,   878,    -1,    -1,   333,    -1,    -1,    -1,   791,    -1,
     835,    -1,    -1,   838,   839,    -1,   841,    -1,   971,    -1,
      -1,    -1,   899,    -1,    -1,    -1,    -1,   904,    -1,    -1,
      -1,   856,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   995,
     917,    -1,   919,    -1,    -1,   922,    -1,    -1,    -1,   874,
     922,    -1,   835,   878,    -1,   838,   923,   924,   841,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   944,    -1,    -1,
      -1,    -1,    -1,   856,   899,    -1,   953,   954,    -1,   904,
      -1,   953,   954,    17,    -1,    -1,   963,   964,   965,    -1,
     967,   874,   969,    -1,   971,   878,    -1,   922,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    41,   791,   438,
     991,    -1,   441,    -1,    -1,    -1,   899,   994,    52,   944,
      -1,   904,    -1,    -1,   453,    -1,    -1,    -1,   953,   954,
      -1,   956,    -1,    -1,   463,    -1,    -1,    -1,   963,   964,
     965,    -1,    -1,    -1,   969,    -1,   971,    -1,    -1,    -1,
      -1,    -1,   835,    -1,    -1,   838,    -1,    -1,   841,    -1,
      -1,   944,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   994,
      -1,    -1,    -1,   856,    -1,    -1,    -1,    -1,    -1,    -1,
     963,   964,   965,    -1,    -1,    -1,    -1,    -1,   971,    -1,
      -1,   874,    -1,    -1,    -1,   878,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   994,    -1,    -1,    -1,    -1,   899,    -1,    -1,    -1,
      -1,   904,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    38,   188,   584,    -1,    -1,    43,    -1,
      -1,   944,    -1,    -1,    -1,   594,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   607,    -1,
     963,   964,   965,    -1,   340,    -1,    -1,    -1,   971,    -1,
      -1,    42,    43,    -1,    -1,    -1,   625,    -1,    -1,   628,
      -1,    -1,   631,    -1,    -1,    -1,    -1,    -1,   364,   365,
     366,   994,    -1,   369,    -1,    -1,   372,   373,   374,   375,
      -1,   377,   378,   379,   380,    -1,   382,   383,   384,   385,
     386,   387,    -1,    -1,    -1,   391,    -1,    -1,   394,   395,
     396,   397,    -1,   399,    43,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,    -1,    -1,
     185,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   468,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,    -1,    -1,   185,   186,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    41,    -1,    -1,    -1,   155,    -1,    -1,    -1,
      -1,    -1,   791,    52,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,    -1,    -1,   185,   186,    -1,   545,
     546,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   835,    -1,    -1,   838,
      -1,    -1,   841,    -1,    -1,    -1,    -1,    -1,    -1,   575,
     576,    -1,    -1,    -1,    -1,    -1,    -1,   856,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   874,    -1,    -1,    -1,   878,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     899,    -1,    -1,    -1,    -1,   904,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,    -1,   188,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   665,
     666,   667,   668,    -1,    -1,   944,   672,    -1,    -1,   675,
      -1,    -1,    -1,    -1,   680,    20,    -1,    -1,    -1,    -1,
      -1,   687,   688,    -1,   963,   964,   965,    -1,    -1,   695,
      -1,    -1,   971,   699,    -1,    -1,    41,   703,    -1,    -1,
      -1,    -1,    -1,   709,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   994,    -1,    62,    63,    -1,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,   110,   111,    -1,   113,   114,
     115,    -1,    -1,   118,   119,    -1,   121,    -1,   123,   124,
     125,   126,    -1,   128,   129,    -1,   131,    -1,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,    20,    -1,
     185,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    -1,   872,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   880,    -1,   882,    -1,    -1,   885,
      -1,    -1,    -1,    -1,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    90,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,
      -1,   113,   114,   115,    -1,    -1,   118,   119,    -1,   121,
      -1,   123,   124,   125,   126,    -1,   128,   129,    -1,   131,
      -1,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,   185,   186,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    -1,    90,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
     101,    -1,    -1,    -1,    41,    -1,    -1,    -1,   109,   110,
     111,    -1,   113,   114,   115,    52,    -1,   118,   119,    -1,
     121,    -1,   123,   124,   125,   126,    -1,   128,   129,    -1,
     131,    43,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,   185,   186,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
      -1,   188,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,   185,   186,    -1,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,    -1,   188,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,    -1,   188,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
      41,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    -1,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    -1,    90,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,
     111,    -1,   113,   114,   115,    -1,    -1,   118,   119,    -1,
     121,    -1,   123,   124,   125,   126,    -1,   128,   129,    -1,
     131,    -1,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,    -1,    -1,   185,   186,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      90,    -1,    -1,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,
     110,   111,    -1,   113,   114,   115,    -1,    -1,   118,   119,
      -1,   121,    -1,   123,   124,   125,   126,    -1,   128,   129,
      -1,   131,    -1,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,    -1,    -1,   185,   186,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      -1,    90,    -1,    -1,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,   110,   111,    -1,   113,   114,   115,    -1,    -1,   118,
     119,    -1,   121,    -1,   123,   124,   125,   126,    -1,   128,
     129,    -1,   131,    -1,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,    -1,    -1,   185,   186,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   109,   110,   111,    -1,   113,   114,   115,    -1,    -1,
     118,   119,    -1,   121,    -1,   123,   124,   125,   126,    -1,
     128,   129,    -1,   131,    -1,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
      41,    -1,   185,   186,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,   185,   186,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    -1,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,
     111,    -1,   113,   114,   115,    -1,    -1,   118,   119,    -1,
     121,    -1,   123,   124,   125,   126,    -1,   128,   129,    -1,
     131,    -1,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    15,   190,   191,   192,   194,   195,   196,   232,   290,
     180,     0,     9,    11,    12,    14,    21,    22,    39,   105,
     116,   117,   120,   122,   130,   132,   193,   236,   237,   251,
     253,   257,   296,   297,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   197,    13,   298,   298,
     298,   298,    37,   238,   252,   326,    20,   180,   181,   182,
     185,   186,   254,   255,   470,   471,   525,   526,   238,   525,
     298,   298,   326,    37,   327,   298,   327,    31,   287,   288,
     289,    17,   242,   291,     3,     4,   314,   318,   319,    16,
     198,   233,   525,     6,    24,   106,   107,   324,   325,   324,
     325,   328,   329,    23,    40,   258,   238,   470,   238,    40,
     263,   264,     6,   106,   322,   323,   322,   328,   322,   368,
     369,   370,   374,   375,    18,    19,   243,   244,   238,   294,
     295,   296,   326,   326,   315,   313,   319,   234,   163,   199,
     201,   202,    10,   299,   300,   525,    38,    32,    33,    34,
      35,    36,    52,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   183,   184,
     188,   330,   338,   402,   455,   456,   458,   459,   460,   469,
     471,   472,   515,   519,   520,   521,   522,   523,   524,   525,
     527,    24,   259,   260,   261,   262,   525,   326,   263,   256,
     263,    92,   265,   266,   270,    37,   163,   341,   343,   112,
     525,   112,    38,   112,   471,    41,   188,   377,    20,    41,
      66,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    90,    94,    95,    96,    97,    98,    99,   100,   101,
     109,   110,   111,   113,   114,   115,   118,   119,   121,   123,
     124,   125,   126,   128,   129,   131,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   247,   248,   249,   250,   394,   471,   496,   498,   500,
     501,   502,   505,   508,   510,   515,   519,   523,   525,   263,
      50,   292,   293,    21,   108,   316,   317,   320,   181,    56,
     200,   324,   457,   333,    44,   339,   340,   404,    41,   403,
      89,   187,   516,   517,   518,   262,   265,   265,   265,    26,
      93,   267,   273,   344,   322,   322,   322,   371,   376,    37,
      41,    62,    63,    65,   471,   473,   474,   477,   480,   481,
     484,   485,   491,   493,   494,   495,   496,   508,   513,   515,
     519,   523,   525,    76,    41,    41,    41,   188,   497,    41,
     188,   400,    41,    41,    41,    41,   503,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,   400,    41,
      41,    41,   188,   188,    41,    41,    41,    41,   188,    41,
     188,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,   248,    41,    41,   188,   395,   265,   195,
     290,   326,    24,   321,   525,    40,   235,    37,   104,   151,
     153,   155,   203,   204,   206,   207,   214,   216,   217,   224,
     262,    51,   407,   412,   470,   332,   334,   335,   330,   405,
     406,   407,   455,   461,   467,   469,   407,   525,    41,   271,
     272,   394,   471,   496,   274,   275,   393,   394,   495,   496,
      25,   268,   276,    52,   239,   240,   342,   345,   346,   349,
     417,   460,   462,   463,   465,   469,    37,    42,   471,   381,
     473,   494,   494,   494,    91,   245,   246,   476,   479,    56,
      57,    58,    59,    60,    61,    66,    67,   482,   483,   490,
     492,   395,   514,   506,   473,   473,   473,   473,   473,   473,
     473,   473,   504,   473,   473,   473,   473,   471,   473,   473,
     473,   473,   473,   473,    18,   397,   397,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   397,   397,   525,   341,   180,
     225,    43,   104,   164,   208,   209,   212,   382,   471,   515,
     519,   523,   525,   155,   218,   219,   222,   382,   207,   205,
     217,   215,    53,   413,   416,   467,    44,   331,     6,    42,
     467,   473,   272,   275,    26,    29,    30,   269,   282,   285,
     286,   464,   242,    38,   348,    44,   350,   351,    41,   419,
     418,   372,    38,    41,   188,   379,    42,   471,    42,    54,
     475,    55,   478,   484,   484,   484,   484,   484,   484,    67,
     400,    62,    63,   486,   489,   521,   522,    20,    64,   487,
     507,    42,    42,    42,   401,    49,    49,    49,    49,   341,
      42,    42,    49,    42,    42,    49,    42,    42,    42,    42,
      49,    20,   473,   509,   473,    42,    42,    49,    49,    42,
      42,    42,    42,    42,    42,    49,    42,    42,    42,    49,
      42,    42,    42,    49,    42,    42,    42,    42,    42,    49,
      42,    42,    42,   473,   473,    38,    41,   226,   212,   104,
     222,   155,   205,    44,   104,   210,   215,    44,   155,   220,
     411,   415,   330,   470,   246,    27,    28,   277,   278,   279,
     280,   281,   393,   471,   167,   167,   283,   286,   284,   285,
      41,    51,    65,   102,   422,   424,   430,   431,   436,   437,
     440,   443,   445,   447,   471,   525,   241,     6,     7,     8,
      31,    45,    46,    48,   127,   148,   347,   352,   353,   354,
     356,   360,   363,   366,   367,   383,   386,   387,   392,   346,
     462,   466,   468,   469,   420,   421,   422,   422,    38,   373,
     382,   380,   477,   480,   400,   491,   491,   487,   488,   493,
     493,   341,   399,   473,   473,   473,   473,   473,   473,   473,
      42,    50,   511,   512,   473,   473,   473,   473,   473,   473,
      42,   396,   227,   151,   213,   211,   154,   223,   221,    50,
     410,    49,   414,   336,    42,   278,   495,   436,    41,    51,
     102,   448,   453,   525,   443,    53,   423,   439,   442,    20,
      62,   103,   444,   446,   263,   357,   361,   364,   368,   355,
     384,   393,    41,   341,   331,   388,    42,   468,   378,    42,
      49,   398,    49,    42,    42,    49,    42,    42,   398,   499,
      77,    42,    42,    42,    42,   499,    42,    42,   399,   230,
     209,   219,   408,   409,   412,   416,    37,    42,   451,   452,
     453,    51,   454,   525,   432,   435,   468,   104,   438,    64,
     441,   265,   358,   362,   365,   341,   385,   473,   346,   341,
      42,   382,   473,   473,   473,    42,    56,    42,    42,    42,
     229,   231,   382,   413,   337,    42,   450,   429,   434,   440,
     445,   287,   470,   298,   298,   341,    91,   391,    42,   499,
     524,    49,   228,    56,   149,   150,   330,   104,   449,    50,
     428,    49,   433,   359,   470,   470,   471,    47,   389,    42,
     382,   382,   382,    38,   453,   424,   425,   427,   435,   341,
     341,    23,    42,   390,   426,   326,   341,   413,   263
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  SPARQLfedParser::yytoken_number_[] =
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
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  SPARQLfedParser::yyr1_[] =
  {
         0,   189,   190,   190,   191,   192,   193,   193,   193,   193,
     194,   195,   196,   196,   197,   197,   198,   198,   200,   199,
     201,   202,   202,   203,   203,   203,   203,   204,   204,   205,
     205,   206,   207,   208,   208,   209,   209,   211,   210,   212,
     213,   214,   214,   215,   215,   216,   217,   218,   218,   219,
     219,   221,   220,   222,   223,   224,   225,   225,   227,   226,
     228,   228,   229,   230,   230,   231,   231,   231,   232,   234,
     235,   233,   237,   236,   238,   238,   240,   241,   239,   242,
     243,   243,   244,   244,   245,   246,   246,   247,   248,   248,
     248,   248,   248,   248,   248,   248,   249,   249,   250,   250,
     251,   252,   252,   253,   254,   254,   255,   255,   256,   256,
     257,   258,   259,   259,   260,   261,   262,   263,   264,   264,
     265,   266,   266,   267,   267,   268,   268,   269,   269,   270,
     271,   271,   272,   272,   272,   272,   273,   274,   274,   275,
     276,   277,   277,   278,   278,   279,   279,   280,   281,   281,
     282,   282,   283,   283,   284,   284,   285,   286,   287,   288,
     289,   289,   291,   290,   292,   293,   293,   294,   295,   295,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   297,   298,   298,   299,   300,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   312,
     313,   313,   314,   314,   315,   315,   316,   317,   317,   318,
     319,   320,   321,   321,   322,   322,   323,   323,   324,   325,
     325,   325,   325,   326,   327,   329,   328,   330,   330,   331,
     331,   332,   333,   333,   335,   336,   337,   334,   338,   339,
     340,   340,   341,   341,   342,   342,   344,   343,   345,   346,
     346,   347,   348,   348,   349,   350,   351,   351,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   353,   355,
     354,   357,   358,   359,   356,   361,   362,   360,   364,   365,
     363,   366,   367,   368,   368,   370,   371,   369,   372,   372,
     373,   375,   374,   376,   376,   377,   377,   378,   378,   380,
     379,   379,   381,   381,   382,   382,   382,   382,   382,   382,
     382,   384,   385,   383,   387,   388,   386,   390,   389,   391,
     391,   392,   393,   393,   393,   394,   395,   396,   395,   397,
     397,   398,   399,   399,   400,   401,   400,   403,   402,   404,
     402,   405,   406,   406,   407,   408,   409,   409,   410,   411,
     411,   412,   412,   413,   414,   415,   415,   416,   418,   417,
     419,   417,   420,   421,   421,   423,   422,   424,   424,   426,
     425,   427,   427,   428,   429,   429,   430,   431,   432,   433,
     434,   434,   435,   436,   437,   438,   439,   439,   440,   441,
     442,   442,   443,   444,   444,   445,   445,   446,   446,   446,
     447,   447,   447,   447,   448,   448,   449,   450,   450,   451,
     452,   452,   453,   453,   453,   454,   454,   455,   455,   457,
     456,   458,   459,   459,   459,   459,   459,   460,   460,   461,
     461,   462,   462,   464,   463,   465,   466,   466,   467,   467,
     468,   468,   469,   469,   470,   470,   471,   471,   472,   472,
     472,   472,   472,   472,   473,   474,   475,   476,   476,   477,
     478,   479,   479,   480,   481,   482,   482,   483,   483,   483,
     483,   483,   483,   483,   483,   484,   485,   486,   486,   487,
     487,   488,   488,   489,   489,   489,   490,   490,   491,   492,
     492,   493,   493,   493,   493,   494,   494,   494,   494,   494,
     494,   494,   494,   495,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   497,   497,
     498,   499,   499,   500,   501,   503,   504,   502,   506,   507,
     505,   508,   508,   508,   509,   509,   510,   510,   510,   510,
     510,   511,   512,   512,   513,   514,   514,   515,   516,   517,
     517,   518,   518,   519,   519,   519,   520,   520,   520,   521,
     521,   521,   522,   522,   522,   523,   523,   524,   524,   524,
     524,   525,   525,   526,   526,   527,   527
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SPARQLfedParser::yyr2_[] =
  {
         0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     3,     0,     1,     0,     2,     0,     2,     0,     3,
       2,     0,     1,     1,     1,     1,     1,     4,     3,     0,
       2,     1,     2,     1,     2,     1,     1,     0,     3,     2,
       1,     4,     3,     0,     2,     1,     2,     1,     2,     1,
       1,     0,     3,     2,     1,     3,     0,     2,     0,     4,
       0,     1,     2,     0,     2,     3,     3,     3,     2,     0,
       0,     5,     0,     5,     0,     2,     0,     0,     6,     3,
       1,     1,     0,     1,     2,     0,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       2,     4,     4,     5,     1,     2,     1,     1,     0,     1,
       4,     2,     1,     1,     1,     2,     1,     2,     0,     1,
       4,     0,     1,     0,     1,     0,     1,     0,     1,     3,
       1,     2,     1,     1,     4,     1,     2,     1,     2,     1,
       3,     1,     2,     1,     1,     1,     1,     2,     1,     1,
       2,     2,     0,     1,     0,     1,     2,     2,     1,     2,
       0,     1,     0,     4,     2,     0,     1,     2,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     0,     1,     2,     0,     1,     3,     3,     3,
       5,     5,     5,     2,     2,     2,     6,     2,     0,     1,
       0,     1,     2,     1,     0,     2,     2,     0,     1,     2,
       2,     2,     1,     2,     1,     2,     0,     1,     2,     1,
       1,     1,     1,     3,     3,     0,     3,     0,     1,     0,
       1,     3,     0,     2,     0,     0,     0,     8,     2,     2,
       0,     1,     1,     1,     1,     1,     0,     4,     2,     0,
       1,     3,     0,     2,     2,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     0,
       3,     0,     0,     0,     6,     0,     0,     6,     0,     0,
       8,     6,     2,     1,     1,     0,     0,     6,     0,     2,
       1,     0,     5,     0,     2,     1,     3,     0,     2,     0,
       4,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     0,     0,     4,     0,     0,     4,     0,     3,     0,
       2,     2,     1,     1,     1,     2,     1,     0,     6,     0,
       1,     2,     0,     2,     1,     0,     5,     0,     3,     0,
       3,     1,     0,     1,     3,     2,     0,     1,     2,     0,
       2,     1,     1,     2,     2,     0,     2,     1,     0,     3,
       0,     3,     1,     0,     1,     0,     4,     1,     1,     0,
       3,     0,     1,     2,     0,     2,     1,     1,     2,     2,
       0,     2,     1,     1,     2,     2,     0,     2,     2,     2,
       0,     2,     2,     0,     1,     1,     2,     1,     1,     1,
       1,     1,     2,     3,     1,     3,     2,     0,     2,     2,
       0,     1,     1,     1,     2,     1,     1,     1,     1,     0,
       4,     4,     1,     1,     1,     1,     1,     0,     1,     1,
       2,     1,     1,     0,     4,     4,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     0,     2,     2,
       2,     0,     2,     1,     2,     0,     1,     2,     2,     2,
       2,     2,     2,     2,     3,     1,     2,     1,     1,     2,
       2,     0,     1,     2,     2,     2,     0,     2,     2,     0,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     4,     6,     4,     4,     4,
       4,     2,     2,     4,     4,     4,     4,     2,     1,     4,
       1,     4,     4,     4,     6,     6,     6,     6,     6,     4,
       4,     4,     4,     4,     4,     4,     4,     2,     2,     2,
       4,     4,     4,     4,     4,     2,     8,     6,     6,     6,
       4,     4,     4,     4,     4,     1,     1,     1,     3,     1,
       7,     0,     1,     7,     9,     0,     0,     4,     0,     0,
       5,     5,     5,     6,     1,     1,     1,     1,     1,     1,
       1,     4,     0,     1,     2,     0,     1,     2,     2,     1,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const SPARQLfedParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "IT_DELETE", "IT_INSERT",
  "IT_DATA", "IT_GRAPH", "IT_SERVICE", "IT_SADI", "IT_LOAD", "IT_INTO",
  "IT_CLEAR", "IT_CREATE", "IT_SILENT", "IT_DROP", "IT_BASE", "IT_PREFIX",
  "IT_SELECT", "IT_DISTINCT", "IT_REDUCED", "GT_TIMES", "IT_CONSTRUCT",
  "IT_DESCRIBE", "IT_FROM", "IT_NAMED", "IT_ORDER", "IT_BY", "IT_ASC",
  "IT_DESC", "IT_LIMIT", "IT_OFFSET", "IT_VALUES", "IT_MEMBERS",
  "IT_STARTS", "IT_ENDS", "IT_ANY", "IT_UNORDERED", "GT_LCURLEY",
  "GT_RCURLEY", "IT_ASK", "IT_WHERE", "GT_LPAREN", "GT_RPAREN", "IT_UNDEF",
  "GT_DOT", "IT_OPTIONAL", "IT_MINUS", "IT_UNION", "IT_FILTER", "GT_COMMA",
  "GT_SEMI", "IT_a", "GT_LBRACKET", "GT_RBRACKET", "GT_OR", "GT_AND",
  "GT_EQUAL", "GT_NEQUAL", "GT_LT", "GT_GT", "GT_LE", "GT_GE", "GT_PLUS",
  "GT_MINUS", "GT_DIVIDE", "GT_NOT", "IT_NOT", "IT_IN", "IT_IRI", "IT_URI",
  "IT_BNODE", "IT_COALESCE", "IT_IF", "IT_STRLANG", "IT_STRDT",
  "IT_REPLACE", "IT_EXISTS", "IT_SEPARATOR", "IT_STR", "IT_LANG",
  "IT_LANGMATCHES", "IT_DATATYPE", "IT_BOUND", "IT_sameTerm", "IT_isIRI",
  "IT_isURI", "IT_isBLANK", "IT_isLITERAL", "IT_REGEX", "GT_DTYPE",
  "IT_CONCAT", "IT_AS", "IT_GROUP", "IT_HAVING", "IT_COUNT", "IT_SUM",
  "IT_MIN", "IT_MAX", "IT_AVG", "IT_GROUP_CONCAT", "IT_SAMPLE",
  "IT_isNUMERIC", "GT_CARROT", "GT_OPT", "GT_PIPE", "IT_WITH",
  "IT_DEFAULT", "IT_ALL", "IT_USING", "IT_UUID", "IT_STRUUID", "IT_MD5",
  "IT_TO", "IT_STRBEFORE", "IT_STRAFTER", "IT_YEAR", "IT_ADD", "IT_COPY",
  "IT_RAND", "IT_SHA512",
  "GT_DELETE_LBRACKET_SPACECHAR_TAB_RETURN_LINEFEED_RBRACKET_PLUS_WHERE",
  "IT_NOW",
  "GT_DELETE_LBRACKET_SPACECHAR_TAB_RETURN_LINEFEED_RBRACKET_PLUS_DATA",
  "IT_TZ", "IT_TIMEZONE", "IT_ROUND", "IT_SHA384", "IT_BIND",
  "IT_CONTAINS", "IT_SECONDS", "IT_MOVE", "IT_FLOOR",
  "GT_INSERT_LBRACKET_SPACECHAR_TAB_RETURN_LINEFEED_RBRACKET_PLUS_DATA",
  "IT_MINUTES", "IT_SUBSTR", "IT_SHA256", "IT_HOURS", "IT_ENCODE_FOR_URI",
  "IT_STRSTARTS", "IT_CEIL", "IT_DAY", "IT_LCASE", "IT_ABS", "IT_UCASE",
  "IT_STRENDS", "IT_STRLEN", "IT_SHA1", "IT_MONTH", "IT_PRINT",
  "GT_H_2192_", "GT_MINUS_GT", "ABOX_HR", "ABOX_CELL", "UBOX_UHR",
  "UBOX_LHR", "GT_H_2502_", "UBOX_UL", "UBOX_U", "UBOX_UR", "UBOX_SEP",
  "UBOX_LL", "UBOX_L", "UBOX_LR", "RSREF", "GT_MINUS_MINUS", "IT_true",
  "IT_false", "INTEGER", "DECIMAL", "DOUBLE", "INTEGER_POSITIVE",
  "DECIMAL_POSITIVE", "DOUBLE_POSITIVE", "INTEGER_NEGATIVE",
  "DECIMAL_NEGATIVE", "DOUBLE_NEGATIVE", "STRING_LITERAL1",
  "STRING_LITERAL_LONG1", "STRING_LITERAL2", "STRING_LITERAL_LONG2",
  "IRIREF", "PNAME_NS", "PNAME_LN", "BLANK_NODE_LABEL", "ANON", "VAR1",
  "VAR2", "LANGTAG", "NIL", "$accept", "Top", "QueryUnit", "Query",
  "_O_QSelectQuery_E_Or_QConstructQuery_E_Or_QDescribeQuery_E_Or_QAskQuery_E_C",
  "UpdateUnit", "Prologue", "_QBaseDecl_E_Opt", "_QPrefixDecl_E_Star",
  "_QLoadResults_E_Star", "LoadResults", "@1",
  "_O_QRSREF_E_S_QGT_EQUAL_E_C", "_Q_O_QRSREF_E_S_QGT_EQUAL_E_C_E_Opt",
  "Result", "ABox", "_QABoxRow_E_Star", "ABoxTop", "ABoxHeader",
  "_QABoxCell_E_Plus", "_O_QGT_PIPE_E_Or_QABoxCell_E_Plus_C", "ABoxRow",
  "$@2", "ABoxCell", "ABoxBottom", "UBox", "_QUBoxRow_E_Star", "UBoxTop",
  "UBoxHeader", "_QUBoxCell_E_Plus",
  "_O_QGT_H_2502__E_Or_QUBoxCell_E_Plus_C", "UBoxRow", "$@3", "UBoxCell",
  "UBoxBottom", "CurlySet", "_QMap_E_Star", "Map", "$@4",
  "_QGT_COMMA_E_Opt", "_O_QBinding_E_S_QGT_COMMA_E_Opt_C",
  "_Q_O_QBinding_E_S_QGT_COMMA_E_Opt_C_E_Star", "Binding", "BaseDecl",
  "PrefixDecl", "$@5", "$@6", "SelectQuery", "@7",
  "_QDatasetClause_E_Star", "SubSelect", "@8", "@9", "SelectClause",
  "_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C",
  "_Q_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C_E_Opt", "_O_QIT_AS_E_S_QVar_E_C",
  "_Q_O_QIT_AS_E_S_QVar_E_C_E_Opt",
  "_O_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_O_QBuiltInCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QVar_E_Or_QAggregate_E_Or_QFunctionCall_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_Q_O_QBuiltInCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QVar_E_Or_QAggregate_E_Or_QFunctionCall_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C_E_Plus",
  "_O_QBuiltInCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QVar_E_Or_QAggregate_E_Or_QFunctionCall_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_Plus_Or_QGT_TIMES_E_C",
  "ConstructQuery",
  "_O_QQuadPattern_E_S_QDatasetClause_E_Star_S_QWhereClause_E_S_QSolutionModifier_E_Or_QDatasetClause_E_Star_S_QIT_WHERE_E_S_QQuadPattern_E_S_QSolutionModifier_E_C",
  "DescribeQuery", "_QVarOrIri_E_Plus",
  "_O_QVarOrIri_E_Plus_Or_QGT_TIMES_E_C", "_QWhereClause_E_Opt",
  "AskQuery", "DatasetClause",
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
  "OffsetClause", "ValuesClause", "_O_QIT_VALUES_E_S_QDataBlock_E_C",
  "_Q_O_QIT_VALUES_E_S_QDataBlock_E_C_E_Opt", "Update", "$@10",
  "_O_QGT_SEMI_E_S_QUpdate_E_C", "_Q_O_QGT_SEMI_E_S_QUpdate_E_C_E_Opt",
  "_O_QUpdate1_E_S_QGT_SEMI_E_S_QUpdate_E_Opt_C",
  "_Q_O_QUpdate1_E_S_QGT_SEMI_E_S_QUpdate_E_Opt_C_E_Opt", "Update1",
  "Load", "_QIT_SILENT_E_Opt", "_O_QIT_INTO_E_S_QGraphRef_E_C",
  "_Q_O_QIT_INTO_E_S_QGraphRef_E_C_E_Opt", "Clear", "Drop", "Create",
  "Add", "Move", "Copy", "InsertData", "DeleteData", "DeleteWhere",
  "Modify", "_O_QIT_WITH_E_S_Qiri_E_C", "_Q_O_QIT_WITH_E_S_Qiri_E_C_E_Opt",
  "_QInsertClause_E_Opt",
  "_O_QDeleteClause_E_S_QInsertClause_E_Opt_Or_QInsertClause_E_C",
  "_QUsingClause_E_Star", "_O_QIT_CONSTRUCT_E_S_QQuadPattern_E_C",
  "_Q_O_QIT_CONSTRUCT_E_S_QQuadPattern_E_C_E_Opt", "DeleteClause",
  "InsertClause", "UsingClause", "_O_Qiri_E_Or_QIT_NAMED_E_S_Qiri_E_C",
  "GraphOrDefault", "_QIT_GRAPH_E_Opt", "GraphRef", "GraphRefAll",
  "QuadPattern", "QuadData", "Quads", "$@11", "_QTriplesTemplate_E_Opt",
  "_QGT_DOT_E_Opt",
  "_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C_E_Star",
  "QuadsNotTriples", "@12", "@13", "$@14", "TriplesTemplate",
  "_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C_E_Opt", "GroupGraphPattern",
  "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C",
  "_O_QGT_LCURLEY_E_S_QSubSelect_E_Or_QGroupGraphPatternSub_E_S_QGT_RCURLEY_E_C",
  "$@15", "GroupGraphPatternSub", "_QTriplesBlock_E_Opt",
  "_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "Print", "OptionalGraphPattern", "@16", "GraphGraphPattern", "@17",
  "@18", "@19", "ServiceGraphPattern", "@20", "@21", "SADIinvocation",
  "@22", "@23", "Bind", "InlineData", "DataBlock", "InlineDataOneVar",
  "$@24", "$@25", "_QSingleValueRow_E_Star", "SingleValueRow",
  "InlineDataFull", "$@26", "_QVar_E_Star",
  "_O_QNIL_E_Or_QGT_LPAREN_E_S_QVar_E_Star_S_QGT_RPAREN_E_C",
  "_QDataBlockValue_E_Star",
  "_O_QGT_LPAREN_E_S_QDataBlockValue_E_Star_S_QGT_RPAREN_E_Or_QNIL_E_C",
  "$@27",
  "_Q_O_QGT_LPAREN_E_S_QDataBlockValue_E_Star_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star",
  "DataBlockValue", "MinusGraphPattern", "@28", "@29",
  "GroupOrUnionGraphPattern", "@30", "@31",
  "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@32",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "@33", "_QIT_DISTINCT_E_Opt",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ExpressionList", "@34",
  "TriplesSameSubject", "$@35", "$@36", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "PropertyListNotEmpty",
  "_O_QVerb_E_S_QObjectList_E_C", "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "Verb",
  "ObjectList", "_O_QGT_COMMA_E_S_QObject_E_C",
  "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star", "Object",
  "TriplesSameSubjectPath", "$@37", "$@38", "PropertyListPath",
  "_QPropertyListPathNotEmpty_E_Opt", "PropertyListPathNotEmpty", "$@39",
  "_O_QVerbPath_E_Or_QVerbSimple_E_C",
  "_O_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_C", "$@40",
  "_Q_O_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_Opt_C_E_Star",
  "VerbPath", "VerbSimple", "ObjectListPath",
  "_O_QGT_COMMA_E_S_QObjectPath_E_C",
  "_Q_O_QGT_COMMA_E_S_QObjectPath_E_C_E_Star", "ObjectPath", "Path",
  "PathAlternative", "_O_QGT_PIPE_E_S_QPathSequence_E_C",
  "_Q_O_QGT_PIPE_E_S_QPathSequence_E_C_E_Star", "PathSequence",
  "_O_QGT_DIVIDE_E_S_QPathEltOrInverse_E_C",
  "_Q_O_QGT_DIVIDE_E_S_QPathEltOrInverse_E_C_E_Star", "PathElt",
  "_QPathMod_E_Opt", "PathEltOrInverse", "PathMod", "PathPrimary",
  "PathNegatedPropertySet", "_O_QGT_PIPE_E_S_QPathOneInPropertySet_E_C",
  "_Q_O_QGT_PIPE_E_S_QPathOneInPropertySet_E_C_E_Star",
  "_O_QPathOneInPropertySet_E_S_QGT_PIPE_E_S_QPathOneInPropertySet_E_Star_C",
  "_Q_O_QPathOneInPropertySet_E_S_QGT_PIPE_E_S_QPathOneInPropertySet_E_Star_C_E_Opt",
  "PathOneInPropertySet", "_O_Qiri_E_Or_QIT_a_E_C", "TriplesNode",
  "BlankNodePropertyList", "@41", "Generator",
  "_O_QIT_MEMBERS_E_Or_QIT_STARTS_E_Or_QIT_ENDS_E_Or_QIT_ANY_E_Or_QIT_UNORDERED_E_C",
  "_Q_O_QIT_MEMBERS_E_Or_QIT_STARTS_E_Or_QIT_ENDS_E_Or_QIT_ANY_E_Or_QIT_UNORDERED_E_C_E_Opt",
  "_QGraphNode_E_Plus", "TriplesNodePath", "BlankNodePropertyListPath",
  "@42", "GeneratorPath", "_QGraphNodePath_E_Plus", "GraphNode",
  "GraphNodePath", "VarOrTerm", "VarOrIri", "Var", "GraphTerm",
  "Expression", "ConditionalOrExpression",
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
  "SubstringExpression", "StrReplaceExpression", "ExistsFunc", "@43",
  "@44", "NotExistsFunc", "@45", "@46", "Aggregate",
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
  const SPARQLfedParser::rhs_number_type
  SPARQLfedParser::yyrhs_[] =
  {
       190,     0,    -1,   191,    -1,   194,    -1,   192,    -1,   195,
     193,   287,    -1,   236,    -1,   251,    -1,   253,    -1,   257,
      -1,   290,    -1,   196,   197,   198,    -1,    -1,   232,    -1,
      -1,   197,   233,    -1,    -1,   198,   199,    -1,    -1,   202,
     200,   203,    -1,   163,    56,    -1,    -1,   201,    -1,   204,
      -1,   214,    -1,   224,    -1,   262,    -1,   206,   207,   205,
     213,    -1,   207,   205,    44,    -1,    -1,   205,   210,    -1,
     151,    -1,   104,   209,    -1,   212,    -1,   208,   212,    -1,
     104,    -1,   208,    -1,    -1,   104,   211,   209,    -1,   382,
     104,    -1,   151,    -1,   216,   217,   215,   223,    -1,   217,
     215,    44,    -1,    -1,   215,   220,    -1,   153,    -1,   155,
     219,    -1,   222,    -1,   218,   222,    -1,   155,    -1,   218,
      -1,    -1,   155,   221,   219,    -1,   382,   155,    -1,   154,
      -1,    37,   225,    38,    -1,    -1,   225,   226,    -1,    -1,
      41,   227,   230,    42,    -1,    -1,    49,    -1,   231,   228,
      -1,    -1,   230,   229,    -1,   382,   150,   382,    -1,   382,
     149,   382,    -1,   382,    56,   382,    -1,    15,   180,    -1,
      -1,    -1,    16,   234,   181,   235,   180,    -1,    -1,   237,
     242,   238,   263,   265,    -1,    -1,   238,   258,    -1,    -1,
      -1,   240,   242,   241,   263,   265,   287,    -1,    17,   244,
     250,    -1,    18,    -1,    19,    -1,    -1,   243,    -1,    91,
     471,    -1,    -1,   245,    -1,    41,   473,   246,    42,    -1,
     496,    -1,   515,    -1,   519,    -1,   523,    -1,   471,    -1,
     508,    -1,   394,    -1,   247,    -1,   248,    -1,   249,   248,
      -1,   249,    -1,    20,    -1,    21,   252,    -1,   326,   238,
     263,   265,    -1,   238,    40,   326,   265,    -1,    22,   255,
     238,   256,   265,    -1,   470,    -1,   254,   470,    -1,   254,
      -1,    20,    -1,    -1,   263,    -1,    39,   238,   263,   265,
      -1,    23,   259,    -1,   260,    -1,   261,    -1,   262,    -1,
      24,   262,    -1,   525,    -1,   264,   341,    -1,    -1,    40,
      -1,   266,   267,   268,   269,    -1,    -1,   270,    -1,    -1,
     273,    -1,    -1,   276,    -1,    -1,   282,    -1,    92,    26,
     271,    -1,   272,    -1,   271,   272,    -1,   496,    -1,   394,
      -1,    41,   473,   246,    42,    -1,   471,    -1,    93,   274,
      -1,   275,    -1,   274,   275,    -1,   393,    -1,    25,    26,
     277,    -1,   278,    -1,   277,   278,    -1,   280,    -1,   281,
      -1,    27,    -1,    28,    -1,   279,   495,    -1,   393,    -1,
     471,    -1,   285,   283,    -1,   286,   284,    -1,    -1,   286,
      -1,    -1,   285,    -1,    29,   167,    -1,    30,   167,    -1,
     289,    -1,    31,   368,    -1,    -1,   288,    -1,    -1,   195,
     296,   291,   295,    -1,    50,   290,    -1,    -1,   292,    -1,
     296,   293,    -1,    -1,   294,    -1,   297,    -1,   301,    -1,
     302,    -1,   304,    -1,   305,    -1,   306,    -1,   303,    -1,
     307,    -1,   308,    -1,   309,    -1,   310,    -1,     9,   298,
     525,   300,    -1,    -1,    13,    -1,    10,   324,    -1,    -1,
     299,    -1,    11,   298,   325,    -1,    14,   298,   325,    -1,
      12,   298,   324,    -1,   116,   298,   322,   112,   322,    -1,
     130,   298,   322,   112,   322,    -1,   117,   298,   322,   112,
     322,    -1,   132,   327,    -1,   122,   327,    -1,   120,   326,
      -1,   312,   314,   315,   317,    40,   341,    -1,   105,   525,
      -1,    -1,   311,    -1,    -1,   319,    -1,   318,   313,    -1,
     319,    -1,    -1,   315,   320,    -1,    21,   326,    -1,    -1,
     316,    -1,     3,   326,    -1,     4,   326,    -1,   108,   321,
      -1,   525,    -1,    24,   525,    -1,   106,    -1,   323,   525,
      -1,    -1,     6,    -1,     6,   525,    -1,   324,    -1,   106,
      -1,    24,    -1,   107,    -1,    37,   328,    38,    -1,    37,
     328,    38,    -1,    -1,   329,   330,   333,    -1,    -1,   338,
      -1,    -1,    44,    -1,   334,   331,   330,    -1,    -1,   333,
     332,    -1,    -1,    -1,    -1,   335,     6,   470,   336,    37,
     337,   330,    38,    -1,   402,   340,    -1,    44,   330,    -1,
      -1,   339,    -1,   343,    -1,   163,    -1,   239,    -1,   345,
      -1,    -1,    37,   344,   342,    38,    -1,   346,   348,    -1,
      -1,   349,    -1,   352,   331,   346,    -1,    -1,   348,   347,
      -1,   417,   351,    -1,    44,   346,    -1,    -1,   350,    -1,
     386,    -1,   354,    -1,   383,    -1,   356,    -1,   360,    -1,
     363,    -1,   392,    -1,   366,    -1,   367,    -1,   353,    -1,
     148,   341,    -1,    -1,    45,   355,   341,    -1,    -1,    -1,
      -1,     6,   357,   358,   470,   359,   341,    -1,    -1,    -1,
       7,   361,   362,   298,   470,   341,    -1,    -1,    -1,     8,
     364,   365,   298,   470,    23,   326,   263,    -1,   127,    41,
     473,    91,   471,    42,    -1,    31,   368,    -1,   369,    -1,
     374,    -1,    -1,    -1,   370,   471,   371,    37,   372,    38,
      -1,    -1,   372,   373,    -1,   382,    -1,    -1,   375,   377,
      37,   381,    38,    -1,    -1,   376,   471,    -1,   188,    -1,
      41,   376,    42,    -1,    -1,   378,   382,    -1,    -1,    41,
     380,   378,    42,    -1,   188,    -1,    -1,   381,   379,    -1,
     525,    -1,   515,    -1,   519,    -1,   523,    -1,    43,    -1,
     164,    -1,   471,    -1,    -1,    -1,    46,   384,   385,   341,
      -1,    -1,    -1,   387,   388,   341,   391,    -1,    -1,    47,
     390,   341,    -1,    -1,   391,   389,    -1,    48,   393,    -1,
     495,    -1,   496,    -1,   394,    -1,   525,   395,    -1,   188,
      -1,    -1,    41,   397,   473,   396,   399,    42,    -1,    -1,
      18,    -1,    49,   473,    -1,    -1,   399,   398,    -1,   188,
      -1,    -1,    41,   473,   401,   399,    42,    -1,    -1,   469,
     403,   407,    -1,    -1,   455,   404,   405,    -1,   406,    -1,
      -1,   407,    -1,   412,   413,   411,    -1,   412,   413,    -1,
      -1,   408,    -1,    50,   409,    -1,    -1,   411,   410,    -1,
     470,    -1,    51,    -1,   416,   415,    -1,    49,   416,    -1,
      -1,   415,   414,    -1,   467,    -1,    -1,   469,   418,   422,
      -1,    -1,   462,   419,   420,    -1,   421,    -1,    -1,   422,
      -1,    -1,   424,   423,   432,   429,    -1,   430,    -1,   431,
      -1,    -1,   424,   426,   413,    -1,    -1,   425,    -1,    50,
     427,    -1,    -1,   429,   428,    -1,   436,    -1,   471,    -1,
     435,   434,    -1,    49,   435,    -1,    -1,   434,   433,    -1,
     468,    -1,   437,    -1,   440,   439,    -1,   104,   440,    -1,
      -1,   439,   438,    -1,   445,   442,    -1,    64,   445,    -1,
      -1,   442,   441,    -1,   447,   444,    -1,    -1,   446,    -1,
     443,    -1,   102,   443,    -1,   103,    -1,    20,    -1,    62,
      -1,   525,    -1,    51,    -1,    65,   448,    -1,    41,   436,
      42,    -1,   453,    -1,    41,   452,    42,    -1,   104,   453,
      -1,    -1,   450,   449,    -1,   453,   450,    -1,    -1,   451,
      -1,   525,    -1,    51,    -1,   102,   454,    -1,   525,    -1,
      51,    -1,   458,    -1,   456,    -1,    -1,    52,   457,   407,
      53,    -1,   460,    41,   461,    42,    -1,    32,    -1,    33,
      -1,    34,    -1,    35,    -1,    36,    -1,    -1,   459,    -1,
     467,    -1,   461,   467,    -1,   465,    -1,   463,    -1,    -1,
      52,   464,   422,    53,    -1,   460,    41,   466,    42,    -1,
     468,    -1,   466,   468,    -1,   469,    -1,   455,    -1,   469,
      -1,   462,    -1,   471,    -1,   472,    -1,   471,    -1,   525,
      -1,   185,    -1,   186,    -1,   525,    -1,   515,    -1,   519,
      -1,   523,    -1,   527,    -1,   188,    -1,   474,    -1,   477,
     476,    -1,    54,   477,    -1,    -1,   476,   475,    -1,   480,
     479,    -1,    55,   480,    -1,    -1,   479,   478,    -1,   481,
      -1,   484,   482,    -1,    -1,   483,    -1,    56,   484,    -1,
      57,   484,    -1,    58,   484,    -1,    59,   484,    -1,    60,
     484,    -1,    61,   484,    -1,    67,   400,    -1,    66,    67,
     400,    -1,   485,    -1,   491,   490,    -1,   521,    -1,   522,
      -1,    20,   493,    -1,    64,   493,    -1,    -1,   487,    -1,
      62,   491,    -1,    63,   491,    -1,   486,   488,    -1,    -1,
     490,   489,    -1,   493,   492,    -1,    -1,   492,   487,    -1,
      65,   494,    -1,    62,   494,    -1,    63,   494,    -1,   494,
      -1,   495,    -1,   496,    -1,   513,    -1,   515,    -1,   519,
      -1,   523,    -1,   471,    -1,   508,    -1,    41,   473,    42,
      -1,    78,    41,   473,    42,    -1,    79,    41,   473,    42,
      -1,    80,    41,   473,    49,   473,    42,    -1,    81,    41,
     473,    42,    -1,    82,    41,   471,    42,    -1,    68,    41,
     473,    42,    -1,    69,    41,   473,    42,    -1,    70,   497,
      -1,   118,   188,    -1,   142,    41,   473,    42,    -1,   139,
      41,   473,    42,    -1,   131,    41,   473,    42,    -1,   125,
      41,   473,    42,    -1,    90,   400,    -1,   500,    -1,   145,
      41,   473,    42,    -1,   501,    -1,   143,    41,   473,    42,
      -1,   141,    41,   473,    42,    -1,   137,    41,   473,    42,
      -1,   128,    41,   473,    49,   473,    42,    -1,   138,    41,
     473,    49,   473,    42,    -1,   144,    41,   473,    49,   473,
      42,    -1,   113,    41,   473,    49,   473,    42,    -1,   114,
      41,   473,    49,   473,    42,    -1,   115,    41,   473,    42,
      -1,   147,    41,   473,    42,    -1,   140,    41,   473,    42,
      -1,   136,    41,   473,    42,    -1,   133,    41,   473,    42,
      -1,   129,    41,   473,    42,    -1,   124,    41,   473,    42,
      -1,   123,    41,   473,    42,    -1,   121,   188,    -1,   109,
     188,    -1,   110,   188,    -1,   111,    41,   473,    42,    -1,
     146,    41,   473,    42,    -1,   135,    41,   473,    42,    -1,
     126,    41,   473,    42,    -1,   119,    41,   473,    42,    -1,
      71,   400,    -1,    72,    41,   473,    49,   473,    49,   473,
      42,    -1,    73,    41,   473,    49,   473,    42,    -1,    74,
      41,   473,    49,   473,    42,    -1,    83,    41,   473,    49,
     473,    42,    -1,    84,    41,   473,    42,    -1,    85,    41,
     473,    42,    -1,    86,    41,   473,    42,    -1,    87,    41,
     473,    42,    -1,   101,    41,   473,    42,    -1,   498,    -1,
     502,    -1,   505,    -1,    41,   473,    42,    -1,   188,    -1,
      88,    41,   473,    49,   473,   499,    42,    -1,    -1,   398,
      -1,   134,    41,   473,    49,   473,   499,    42,    -1,    75,
      41,   473,    49,   473,    49,   473,   499,    42,    -1,    -1,
      -1,    76,   503,   504,   341,    -1,    -1,    -1,    66,    76,
     506,   507,   341,    -1,    94,    41,   397,   509,    42,    -1,
     510,    41,   397,   473,    42,    -1,    99,    41,   397,   473,
     512,    42,    -1,    20,    -1,   473,    -1,    95,    -1,    96,
      -1,    97,    -1,    98,    -1,   100,    -1,    50,    77,    56,
     524,    -1,    -1,   511,    -1,   525,   514,    -1,    -1,   395,
      -1,   524,   518,    -1,    89,   525,    -1,   187,    -1,   516,
      -1,    -1,   517,    -1,   520,    -1,   521,    -1,   522,    -1,
     167,    -1,   168,    -1,   169,    -1,   170,    -1,   171,    -1,
     172,    -1,   173,    -1,   174,    -1,   175,    -1,   165,    -1,
     166,    -1,   176,    -1,   178,    -1,   177,    -1,   179,    -1,
     180,    -1,   526,    -1,   182,    -1,   181,    -1,   183,    -1,
     184,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SPARQLfedParser::yyprhs_[] =
  {
         0,     0,     3,     5,     7,     9,    13,    15,    17,    19,
      21,    23,    27,    28,    30,    31,    34,    35,    38,    39,
      43,    46,    47,    49,    51,    53,    55,    57,    62,    66,
      67,    70,    72,    75,    77,    80,    82,    84,    85,    89,
      92,    94,    99,   103,   104,   107,   109,   112,   114,   117,
     119,   121,   122,   126,   129,   131,   135,   136,   139,   140,
     145,   146,   148,   151,   152,   155,   159,   163,   167,   170,
     171,   172,   178,   179,   185,   186,   189,   190,   191,   198,
     202,   204,   206,   207,   209,   212,   213,   215,   220,   222,
     224,   226,   228,   230,   232,   234,   236,   238,   241,   243,
     245,   248,   253,   258,   264,   266,   269,   271,   273,   274,
     276,   281,   284,   286,   288,   290,   293,   295,   298,   299,
     301,   306,   307,   309,   310,   312,   313,   315,   316,   318,
     322,   324,   327,   329,   331,   336,   338,   341,   343,   346,
     348,   352,   354,   357,   359,   361,   363,   365,   368,   370,
     372,   375,   378,   379,   381,   382,   384,   387,   390,   392,
     395,   396,   398,   399,   404,   407,   408,   410,   413,   414,
     416,   418,   420,   422,   424,   426,   428,   430,   432,   434,
     436,   438,   443,   444,   446,   449,   450,   452,   456,   460,
     464,   470,   476,   482,   485,   488,   491,   498,   501,   502,
     504,   505,   507,   510,   512,   513,   516,   519,   520,   522,
     525,   528,   531,   533,   536,   538,   541,   542,   544,   547,
     549,   551,   553,   555,   559,   563,   564,   568,   569,   571,
     572,   574,   578,   579,   582,   583,   584,   585,   594,   597,
     600,   601,   603,   605,   607,   609,   611,   612,   617,   620,
     621,   623,   627,   628,   631,   634,   637,   638,   640,   642,
     644,   646,   648,   650,   652,   654,   656,   658,   660,   663,
     664,   668,   669,   670,   671,   678,   679,   680,   687,   688,
     689,   698,   705,   708,   710,   712,   713,   714,   721,   722,
     725,   727,   728,   734,   735,   738,   740,   744,   745,   748,
     749,   754,   756,   757,   760,   762,   764,   766,   768,   770,
     772,   774,   775,   776,   781,   782,   783,   788,   789,   793,
     794,   797,   800,   802,   804,   806,   809,   811,   812,   819,
     820,   822,   825,   826,   829,   831,   832,   838,   839,   843,
     844,   848,   850,   851,   853,   857,   860,   861,   863,   866,
     867,   870,   872,   874,   877,   880,   881,   884,   886,   887,
     891,   892,   896,   898,   899,   901,   902,   907,   909,   911,
     912,   916,   917,   919,   922,   923,   926,   928,   930,   933,
     936,   937,   940,   942,   944,   947,   950,   951,   954,   957,
     960,   961,   964,   967,   968,   970,   972,   975,   977,   979,
     981,   983,   985,   988,   992,   994,   998,  1001,  1002,  1005,
    1008,  1009,  1011,  1013,  1015,  1018,  1020,  1022,  1024,  1026,
    1027,  1032,  1037,  1039,  1041,  1043,  1045,  1047,  1048,  1050,
    1052,  1055,  1057,  1059,  1060,  1065,  1070,  1072,  1075,  1077,
    1079,  1081,  1083,  1085,  1087,  1089,  1091,  1093,  1095,  1097,
    1099,  1101,  1103,  1105,  1107,  1109,  1112,  1115,  1116,  1119,
    1122,  1125,  1126,  1129,  1131,  1134,  1135,  1137,  1140,  1143,
    1146,  1149,  1152,  1155,  1158,  1162,  1164,  1167,  1169,  1171,
    1174,  1177,  1178,  1180,  1183,  1186,  1189,  1190,  1193,  1196,
    1197,  1200,  1203,  1206,  1209,  1211,  1213,  1215,  1217,  1219,
    1221,  1223,  1225,  1227,  1231,  1236,  1241,  1248,  1253,  1258,
    1263,  1268,  1271,  1274,  1279,  1284,  1289,  1294,  1297,  1299,
    1304,  1306,  1311,  1316,  1321,  1328,  1335,  1342,  1349,  1356,
    1361,  1366,  1371,  1376,  1381,  1386,  1391,  1396,  1399,  1402,
    1405,  1410,  1415,  1420,  1425,  1430,  1433,  1442,  1449,  1456,
    1463,  1468,  1473,  1478,  1483,  1488,  1490,  1492,  1494,  1498,
    1500,  1508,  1509,  1511,  1519,  1529,  1530,  1531,  1536,  1537,
    1538,  1544,  1550,  1556,  1563,  1565,  1567,  1569,  1571,  1573,
    1575,  1577,  1582,  1583,  1585,  1588,  1589,  1591,  1594,  1597,
    1599,  1601,  1602,  1604,  1606,  1608,  1610,  1612,  1614,  1616,
    1618,  1620,  1622,  1624,  1626,  1628,  1630,  1632,  1634,  1636,
    1638,  1640,  1642,  1644,  1646,  1648,  1650
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   487,   487,   490,   496,   501,   512,   513,   514,   515,
     519,   524,   528,   530,   534,   536,   539,   541,   545,   545,
     563,   569,   572,   576,   577,   578,   579,   585,   586,   589,
     591,   595,   599,   603,   604,   608,   609,   613,   613,   621,
     627,   631,   632,   635,   637,   641,   645,   649,   650,   654,
     655,   659,   659,   667,   673,   677,   680,   682,   686,   686,
     693,   695,   699,   702,   704,   708,   711,   714,   720,   726,
     728,   726,   738,   738,   750,   753,   761,   764,   761,   778,
     786,   789,   796,   799,   804,   811,   814,   819,   826,   829,
     832,   835,   838,   841,   844,   848,   853,   856,   864,   867,
     873,   879,   884,   894,   902,   905,   913,   916,   923,   926,
     931,   939,   946,   947,   951,   957,   963,   970,   977,   979,
     984,   991,   994,   999,  1002,  1007,  1010,  1015,  1019,  1023,
    1030,  1033,  1040,  1043,  1046,  1049,  1055,  1061,  1064,  1071,
    1076,  1083,  1087,  1095,  1097,  1105,  1108,  1116,  1124,  1125,
    1132,  1136,  1144,  1147,  1152,  1155,  1159,  1165,  1171,  1175,
    1181,  1184,  1188,  1188,  1198,  1201,  1203,  1207,  1210,  1212,
    1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,  1225,
    1226,  1230,  1236,  1239,  1246,  1253,  1256,  1260,  1266,  1272,
    1278,  1284,  1290,  1296,  1304,  1312,  1319,  1328,  1334,  1337,
    1341,  1344,  1348,  1352,  1358,  1360,  1366,  1372,  1375,  1379,
    1385,  1391,  1397,  1400,  1406,  1409,  1414,  1416,  1420,  1426,
    1429,  1432,  1435,  1442,  1449,  1455,  1455,  1463,  1465,  1469,
    1471,  1475,  1478,  1480,  1485,  1490,  1493,  1485,  1504,  1508,
    1511,  1513,  1517,  1518,  1531,  1532,  1537,  1537,  1548,  1552,
    1554,  1564,  1568,  1571,  1587,  1592,  1596,  1599,  1603,  1604,
    1605,  1606,  1607,  1608,  1609,  1610,  1611,  1614,  1618,  1624,
    1624,  1640,  1644,  1646,  1640,  1657,  1661,  1657,  1670,  1674,
    1670,  1691,  1702,  1708,  1709,  1713,  1715,  1713,  1722,  1724,
    1728,  1736,  1736,  1743,  1745,  1751,  1752,  1755,  1757,  1763,
    1763,  1768,  1774,  1776,  1780,  1783,  1786,  1789,  1792,  1795,
    1798,  1804,  1808,  1804,  1818,  1822,  1818,  1832,  1832,  1844,
    1846,  1850,  1860,  1861,  1862,  1866,  1874,  1878,  1878,  1888,
    1891,  1898,  1904,  1906,  1920,  1923,  1923,  1933,  1933,  1936,
    1936,  1942,  1945,  1947,  1952,  1957,  1961,  1963,  1968,  1972,
    1974,  1978,  1982,  1990,  1995,  1999,  2001,  2005,  2013,  2013,
    2016,  2016,  2022,  2025,  2027,  2031,  2031,  2037,  2038,  2042,
    2042,  2047,  2049,  2053,  2056,  2058,  2062,  2066,  2072,  2076,
    2079,  2081,  2085,  2092,  2096,  2100,  2103,  2105,  2109,  2113,
    2118,  2120,  2126,  2129,  2131,  2137,  2138,  2144,  2145,  2146,
    2150,  2153,  2156,  2159,  2165,  2166,  2170,  2173,  2175,  2179,
    2182,  2184,  2188,  2189,  2190,  2194,  2195,  2201,  2202,  2206,
    2206,  2219,  2247,  2250,  2253,  2256,  2259,  2266,  2269,  2274,
    2278,  2285,  2286,  2290,  2290,  2302,  2329,  2333,  2340,  2341,
    2345,  2346,  2350,  2353,  2357,  2360,  2366,  2367,  2371,  2374,
    2377,  2380,  2383,  2384,  2390,  2395,  2404,  2411,  2414,  2422,
    2431,  2438,  2441,  2448,  2453,  2466,  2470,  2474,  2478,  2482,
    2486,  2490,  2494,  2498,  2502,  2509,  2514,  2523,  2526,  2533,
    2536,  2543,  2546,  2551,  2554,  2558,  2572,  2575,  2583,  2592,
    2595,  2602,  2605,  2608,  2611,  2615,  2616,  2617,  2618,  2621,
    2624,  2627,  2630,  2634,  2640,  2643,  2646,  2649,  2652,  2655,
    2658,  2662,  2665,  2668,  2671,  2674,  2677,  2680,  2683,  2684,
    2687,  2688,  2691,  2694,  2697,  2700,  2703,  2706,  2709,  2712,
    2715,  2718,  2721,  2724,  2727,  2730,  2733,  2736,  2739,  2742,
    2745,  2748,  2751,  2754,  2757,  2760,  2763,  2766,  2769,  2772,
    2775,  2778,  2781,  2784,  2787,  2790,  2791,  2792,  2798,  2801,
    2808,  2815,  2818,  2822,  2828,  2834,  2837,  2834,  2849,  2852,
    2849,  2865,  2869,  2874,  2883,  2886,  2890,  2893,  2896,  2899,
    2902,  2908,  2914,  2917,  2921,  2931,  2934,  2939,  2947,  2954,
    2958,  2966,  2970,  2974,  2975,  2976,  2980,  2981,  2982,  2986,
    2987,  2988,  2992,  2993,  2994,  2998,  2999,  3003,  3004,  3005,
    3006,  3010,  3011,  3015,  3016,  3020,  3021
  };

  // Print the state stack on the debug stream.
  void
  SPARQLfedParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  SPARQLfedParser::yy_reduce_print_ (int yyrule)
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
  SPARQLfedParser::token_number_type
  SPARQLfedParser::yytranslate_ (int t)
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
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SPARQLfedParser::yyeof_ = 0;
  const int SPARQLfedParser::yylast_ = 2731;
  const int SPARQLfedParser::yynnts_ = 339;
  const int SPARQLfedParser::yyempty_ = -2;
  const int SPARQLfedParser::yyfinal_ = 11;
  const int SPARQLfedParser::yyterror_ = 1;
  const int SPARQLfedParser::yyerrcode_ = 256;
  const int SPARQLfedParser::yyntokens_ = 189;

  const unsigned int SPARQLfedParser::yyuser_token_number_max_ = 443;
  const SPARQLfedParser::token_number_type SPARQLfedParser::yyundef_token_ = 2;


} // w3c_sw

/* Line 1136 of lalr1.cc  */
#line 5942 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 3027 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
 /*** Additional Code ***/

void w3c_sw::SPARQLfedParser::error(const SPARQLfedParser::location_type& l,
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

    SPARQLfedDriver::SPARQLfedDriver (std::string baseURI, AtomFactory* atomFactory) : 
	YaccDriver(baseURI, atomFactory), curSubject(NULL), curPredicate(NULL), 
	curBGP(NULL), curFilter(NULL), 
	curResultSet(NULL), curResult(NULL), curExprList(NULL), 
	root(NULL), unnestTree(false)
{
}

    SPARQLfedDriver::~SPARQLfedDriver ()
{
}

Operation* SPARQLfedDriver::parse (IStreamContext& in)
{
    root = NULL;
    curBGP = NULL;
    curOp = NULL;
    curGraphName = NULL;
    streamname = in.nameStr;
    // clear prefixes for nth run but keep them around for e.g. serialization.
    clearPrefixes();

    SPARQLfedScanner scanner(this, in.p);
    scanner.set_debug(trace_scanning);
    lexer = &scanner;

    SPARQLfedParser parser(*this);
    parser.set_debug_level(trace_parsing);
    // !!! Clear out namespaces!
    ignorePrefixFlag = false;
    parser.parse();
    return root;
}

Operation* SPARQLfedDriver::parse (std::string queryStr)
{
    IStreamContext in(queryStr.c_str(), IStreamContext::STRING);
    return parse(in);
}

void SPARQLfedDriver::executeSelect (IStreamContext& in, RdfDB* db, ResultSet* rs) {
    parse(in);
    root->execute(db, rs);
    delete root;
    root = NULL;
}
void SPARQLfedDriver::executeSelect (std::string queryStr, RdfDB* db, ResultSet* rs) {
    parse(queryStr);
    root->execute(db, rs);
    delete root;
    root = NULL;
}


} // namespace w3c_sw

/* END Driver */


