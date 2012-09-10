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
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 767 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 771 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if ((yysemantic_stack_[(7) - (7)].p_BindingClause) != NULL)
	      (yysemantic_stack_[(7) - (5)].p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yysemantic_stack_[(7) - (7)].p_BindingClause), (yysemantic_stack_[(7) - (5)].p_WhereClause)->m_GroupGraphPattern);
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (4)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(7) - (3)].p_Project).distinctness, (yysemantic_stack_[(7) - (3)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(7) - (5)].p_WhereClause), (yysemantic_stack_[(7) - (6)].p_SolutionModifier))));
	  driver.curGraphName = (yysemantic_stack_[(7) - (2)].p_TTerm);
	  driver.countStar = (yysemantic_stack_[(7) - (1)].p_parentCountStar);
      }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 782 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 790 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 793 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 800 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 808 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 815 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 823 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 830 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 833 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 836 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 839 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 842 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 845 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 848 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 857 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 860 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 868 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 871 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 877 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(2) - (2)].p_Operation);
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 883 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.lastWhereClause = (yysemantic_stack_[(4) - (3)].p_WhereClause);
	  /* $1 is NO LONGER known to be a DefaultGraphPattern because of grammar restrictions. */
	  (yyval.p_Operation) = new Construct((yysemantic_stack_[(4) - (1)].p_TableOperation), (yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
      }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 888 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	SWObjectDuplicator dup(driver.atomFactory);
	(yysemantic_stack_[(4) - (3)].p_TableOperation)->express(&dup);
	driver.lastWhereClause = new WhereClause((yysemantic_stack_[(4) - (3)].p_TableOperation));
	(yyval.p_Operation) = new Construct(dup.last.tableOperation, (yysemantic_stack_[(4) - (1)].p_DatasetClauses), driver.lastWhereClause, (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 898 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause) ? (yysemantic_stack_[(5) - (4)].p_WhereClause) : new WhereClause(new DefaultGraphPattern());
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 906 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm))));
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 909 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_TTerm))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 917 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 920 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 927 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 935 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(4) - (3)].p_WhereClause);
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 943 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 955 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 961 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 967 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 974 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.ensureGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 988 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 995 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1003 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1011 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1019 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1027 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1034 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1037 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1044 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1047 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1050 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1053 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1059 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1065 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1068 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1080 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1087 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1091 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1101 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1109 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1112 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1120 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1129 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1136 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1140 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1148 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1156 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1163 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1169 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1179 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = (yysemantic_stack_[(2) - (2)].p_BindingClause);
    }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1185 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1192 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	OperationSet* ret = driver.root ? dynamic_cast<OperationSet*>(driver.root) : new OperationSet();
	ret->push_back((yysemantic_stack_[(2) - (2)].p_Operation));
	driver.root = ret;
      }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1196 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Operation) = driver.root;
	}
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1234 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(4) - (2)].p_Silence), (yysemantic_stack_[(4) - (3)].p_URI), (yysemantic_stack_[(4) - (4)].p_URI));
    }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1240 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1243 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1250 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1257 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1264 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1270 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1276 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1282 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1288 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1294 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1300 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1308 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1316 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1323 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(6) - (1)].p_URI))
	    w3c_sw_NEED_IMPL("WITH <URI> (DELETE INSERT?|INSERT) ...");
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(6) - (2)].p_DeleteInsert).del, (yysemantic_stack_[(6) - (2)].p_DeleteInsert).ins, new WhereClause(driver.ensureGraphPattern()), (yysemantic_stack_[(6) - (4)].p_TableOperation));
	driver.curOp = NULL;
    }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1332 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1338 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1345 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1352 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1356 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1364 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("_QUsingClause_E_Star");
    }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1370 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(2) - (2)].p_TableOperation);
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1376 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = NULL;
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1383 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Delete) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1389 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = new Insert((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 1395 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1401 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 1404 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 1410 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 1413 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 1424 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1430 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 1433 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("DEFAULT");
      }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1436 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("NAMED");
      }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 1439 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("ALL");
      }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 1446 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
	driver.curOp = NULL;
    }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 1453 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
    }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 1459 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 1461 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TableOperation) = driver.ensureGraphPattern();
	  driver.curOp = NULL;
      }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 1489 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 1494 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 1497 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 1500 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 1522 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 247:

/* Line 690 of lalr1.cc  */
#line 1541 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 1543 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 1615 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_BindingClause)) : (yysemantic_stack_[(1) - (1)].p_BindingClause);
    }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 1622 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Print(driver.curOp);
    }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 1628 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 1632 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 272:

/* Line 690 of lalr1.cc  */
#line 1644 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 1648 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 1650 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 1653 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 1661 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 1665 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 1667 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 1670 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(7) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(7) - (6)].p_TTerm), driver.curOp, (yysemantic_stack_[(7) - (5)].p_Silence), driver.atomFactory, false));
	  driver.curGraphName = (yysemantic_stack_[(7) - (4)].p_TTerm);
      }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 1678 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 1682 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 1684 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 1687 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  /*
	    serviceID,
	    from,
	    e_Silence
	    where
	   */
	  driver.lastWhereClause = (yysemantic_stack_[(9) - (9)].p_WhereClause);
	  driver.restoreFilter((yysemantic_stack_[(9) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction
	      ((yysemantic_stack_[(9) - (2)].p_TableOperation), new SADIGraphPattern((yysemantic_stack_[(9) - (6)].p_TTerm), (yysemantic_stack_[(9) - (5)].p_Silence), (yysemantic_stack_[(9) - (8)].p_TableOperation), (yysemantic_stack_[(9) - (9)].p_WhereClause)));
	  driver.curGraphName = (yysemantic_stack_[(9) - (4)].p_TTerm);
    }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 1703 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Bind(driver.ensureGraphPattern(), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
	// no more triples go into the current BGP, per
	//   http://www.w3.org/TR/sparql11-query/#sparqlTranslateGraphPatterns
	// test reference:
	//   http://www.sparql.org/query-validator?query=ASK+{+%3Fs+%3Fp+%3Fo+FILTER+%281%29+BIND+%282+AS+%3Fb%29+%3Fs2+%3Fp2+%3Fo2+FILTER+%283%29+BIND+%284+AS+%3Fd%29}&languageSyntax=SPARQL&outputFormat=algebra&linenumbers=false
	driver.curBGP = NULL;
    }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 1714 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = (yysemantic_stack_[(2) - (2)].p_BindingClause);
    }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 1725 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 1727 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
      }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 1729 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 1740 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
	driver.endBindingRow();
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 1748 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 1750 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 1757 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 1769 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 1775 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 1777 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 1780 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 1792 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 1795 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 1798 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 1801 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 1804 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 1807 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 1810 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 1816 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 1820 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 1822 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 1830 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 1834 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 1836 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 1844 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 1849 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.ensureGraphPattern());
      }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 1862 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    driver.ensureGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 1878 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 1886 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 1890 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 1893 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yysemantic_stack_[(6) - (4)].p_Expressions);
      }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 1900 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 1903 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 1910 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 1918 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 1932 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 1935 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 1938 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(5) - (3)].p_Expressions);
      }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 1945 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 1948 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 1990 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 1994 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::RDF_type;
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 2017 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 2025 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 2028 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
        }
    break;

  case 368:

/* Line 690 of lalr1.cc  */
#line 2043 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 2054 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 2078 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 2097 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 2125 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 2132 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 2143 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 2150 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 2162 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 2165 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::RDF_type;
    }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 2168 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 2171 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 2218 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 2222 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 2231 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 425:

/* Line 690 of lalr1.cc  */
#line 2259 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 2262 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 2265 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 2268 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 2271 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 2278 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 2286 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 2290 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 2302 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 2306 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject;
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 2314 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 439:

/* Line 690 of lalr1.cc  */
#line 2341 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 2345 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 2362 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 2369 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 2372 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 2383 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 2386 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 2389 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 2392 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 2396 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::RDF_nil; // !!! new GraphTerm_rule5($1);
    }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 2407 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 2416 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 2423 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 2426 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 2434 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 2443 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 2450 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 2453 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 2465 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 468:

/* Line 690 of lalr1.cc  */
#line 2478 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = NULL;
    }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 2486 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 2490 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 2494 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 2498 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 2502 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 2506 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 2510 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 2514 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = true;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 2526 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 2535 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 2538 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 2545 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 2548 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 2555 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 2563 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 2566 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 2570 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 489:

/* Line 690 of lalr1.cc  */
#line 2584 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 2587 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 2595 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 2604 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 2607 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 2614 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 2617 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 2620 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 2630 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 2633 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 2636 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 2639 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 2646 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 2652 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 2655 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 2658 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 2661 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 2664 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 2667 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 2670 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 2674 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 2677 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 2680 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 2683 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ceil, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 2686 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 2689 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 2692 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 2696 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 2700 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 2703 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 2706 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 2709 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 2712 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 2715 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 2718 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 2721 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 2724 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 2727 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 2730 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 2733 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 2736 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 2739 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 2742 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 2745 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 2748 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 2751 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_uuid, NULL, NULL, NULL));
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 2754 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_struuid, NULL, NULL, NULL));
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 2757 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 2760 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 2763 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 2766 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 2769 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 2772 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 2775 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 2778 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 2781 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 2784 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 2787 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 2790 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 2793 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 2796 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 2799 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 2810 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 2813 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 2820 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 2827 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 2834 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 2840 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_replace, (yysemantic_stack_[(9) - (3)].p_Expression), (yysemantic_stack_[(9) - (5)].p_Expression), (yysemantic_stack_[(9) - (7)].p_Expression))); // !! , $8
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 2846 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 2849 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 2853 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expression) = new ExistsExpression(driver.ensureGraphPattern());
	  driver.curOp = (yysemantic_stack_[(4) - (3)].p_TableOperation);
	  driver.countStar = (yysemantic_stack_[(4) - (2)].p_parentCountStar);
      }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 2861 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
      }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 2864 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 2868 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  // $$ = new ExistsExpression(false, driver.ensureGraphPattern());
	  (yyval.p_Expression) = new BooleanNegation(new ExistsExpression(driver.ensureGraphPattern()));
	  driver.curOp = (yysemantic_stack_[(5) - (4)].p_TableOperation);
	  driver.countStar = (yysemantic_stack_[(5) - (3)].p_parentCountStar);
      }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 2877 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 2881 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 2886 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  AggregateCall::ScalarVals svals;
	  if ((yysemantic_stack_[(6) - (5)].p_RDFLiteral) != NULL)
	      svals["separator"] = (yysemantic_stack_[(6) - (5)].p_RDFLiteral)->getLexicalValue();
	  (yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression), svals));
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 2895 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 2902 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 2905 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 2908 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 2911 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 2914 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 2920 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 2926 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 2933 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 2943 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 2951 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 2959 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 2966 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 2970 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 2978 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 690 of lalr1.cc  */
#line 3963 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -844;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        65,  -114,    71,  -844,  -844,  -844,   387,  -844,  -844,  -844,
    -844,  -844,    75,    75,    75,    75,    67,     3,  -844,   -67,
      75,    75,    67,    82,    75,    82,    60,  -844,    91,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,   142,   113,  -844,   -67,    57,
     160,    57,  -844,    50,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,   189,  -844,  -844,  -844,  -844,  -844,    56,  -844,
      53,    53,  -844,  -844,  -844,    53,  -844,    -7,  -844,  -844,
    -844,   187,  -844,   318,    67,    67,  -844,   171,  -844,  -844,
      66,  -844,   168,   -67,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,   172,  1234,    17,    67,  -844,    56,  -844,    14,  -844,
      88,    -1,  -844,  -844,   103,   -67,   111,   196,   130,  -844,
    -844,    52,  -844,    -6,  -844,  -844,  -844,  1614,    56,  -844,
    -844,   175,  -844,  -844,    41,  -844,  -844,    64,   198,  -844,
    -844,  -844,   160,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,   240,  -844,  -844,  -844,  -844,   251,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,   -31,  -844,
    -844,   -67,  -844,  -844,  -844,  -844,  -844,    88,    88,    88,
    -844,   270,  -844,   205,  -844,  -844,  -844,  -844,  -844,    53,
    -844,    53,  -844,    53,  -844,  -844,  -844,   262,  -844,  2045,
     229,   266,   267,     6,     8,   268,   273,   274,   278,  -844,
     287,   290,   293,   295,   296,   300,   301,   302,   303,   307,
     308,     8,   311,  -844,  -844,  -844,  -844,   312,  -844,   314,
     123,   169,   320,   321,   322,   324,   178,   327,   184,   335,
     336,   337,   339,   340,   341,   342,   343,   344,   345,   347,
     349,   351,   352,   353,   356,   359,   362,   364,   365,   366,
     370,  -844,  -844,  2166,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,   372,  -844,  -844,  -844,    15,    88,
      65,  -844,  -844,    67,    20,  -844,   374,  -844,  -844,  -844,
      69,  -844,   100,   412,  1234,  -844,  -844,   100,  1875,   100,
     -67,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  2408,
    2494,   395,  -844,  1210,  -844,  -844,  -844,   385,    22,  -844,
    2045,  2287,  2287,  2287,  -844,   334,  -844,  -844,  -844,  -844,
     478,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,    15,  -844,  2045,  2045,  2045,  -844,  -844,  2045,
    -844,  -844,  2045,  2045,  2045,  2045,  -844,  2045,  2045,  2045,
    2045,    52,  2045,  2045,  2045,  2045,  2045,  2045,  -844,   409,
     409,  2045,  -844,  -844,  2045,  2045,  2045,  2045,  -844,  2045,
    -844,  2045,  2045,  2045,  2045,  2045,  2045,  2045,  2045,  2045,
    2045,  2045,  2045,  2045,  2045,  2045,  2045,  2045,  2045,  2045,
    2045,  2045,  2045,  -844,   409,   409,  -844,  -844,  -844,   569,
    -844,  -844,   -67,  -844,  -844,    -1,   248,  -844,  1151,  -844,
    -844,  1472,  -844,  -844,   325,  -844,  -844,   275,  -844,  -844,
    -844,  -844,   378,  1875,  -844,  -844,   388,   427,  -844,  -844,
    -844,  -844,  -844,  1258,  -844,  -844,  -844,  -844,  2045,  2408,
    -844,  -844,  -844,  -844,  2494,  -844,  -844,  -844,  -844,  -844,
     413,   223,  -844,  -844,  -844,  -844,   403,  -844,  -844,  -844,
     398,   402,  -844,  -844,  -844,  -844,  -844,  -844,  -844,   -12,
     405,  -844,  -844,  -844,    52,  -844,   407,   390,   396,  2045,
    2045,  2045,  2045,  2045,  2045,   389,     8,  -844,  -844,   450,
      48,  -844,  -844,  -844,   416,   418,   419,  -844,   406,   414,
     415,   417,    -1,   423,   426,   420,   428,   429,   430,   433,
     434,   436,   438,   432,  -844,  1438,  2045,   440,   443,   437,
     439,   445,   447,   449,   451,   452,   453,   448,   457,   458,
     459,   456,   460,   466,   469,   465,   474,   479,   480,   481,
     484,   482,   485,   486,   490,  2045,  2045,  -844,  -844,  -844,
      83,  -844,  -844,  -844,  1824,  -844,  -844,   350,  -844,  -844,
    -844,  -844,  -844,  -844,  1824,  -844,  -844,   317,  -844,    23,
    -844,     2,  -844,  -844,  -844,  -844,  -844,  1234,   189,  -844,
    -844,   334,  -844,  -844,  1735,   375,   376,  -844,  -844,   511,
     517,    93,    91,  -844,    87,  1799,  -844,  -844,  1899,    93,
      93,   885,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  2045,
    -844,  2045,  -844,  -844,  -844,  -844,  -844,  -844,  -844,     8,
    -844,  2045,  2045,    48,  -844,  -844,  -844,  2045,  2045,  -844,
      -1,  -844,  -844,  -844,  -844,  2045,  2045,  2045,  2045,  -844,
    -844,  -844,  2045,  -844,  -844,  2045,  -844,  -844,  -844,  -844,
    2045,  -844,  -844,   507,   502,  -844,  -844,  2045,  2045,  -844,
    -844,  -844,  -844,  -844,  -844,  2045,  -844,  -844,  -844,  2045,
    -844,  -844,  -844,  2045,  -844,  -844,  -844,  -844,  -844,  2045,
    -844,  -844,  -844,   513,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,   -44,  -844,  -844,  -844,   102,  -844,  -844,  -844,
     503,   509,  -844,  -844,   514,  -844,  -844,  1735,  -844,   404,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
      51,  -844,    90,    46,   508,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,    58,  -844,  -844,  -844,  -844,  -844,  -844,
      -7,  -844,  -844,  2494,   519,    -1,  -844,   388,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  1851,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,    33,   516,   527,   528,   522,   531,   532,   526,
    -844,   499,  -844,   537,   540,   542,   543,   526,   544,   545,
    -844,  -844,  -844,  -844,  -844,  1151,  -844,  -844,  1472,   100,
    -844,  1875,  -844,   551,  -844,  -844,  -844,   553,   165,  -844,
     109,  -844,  -844,  -844,  -844,  -844,  1899,   489,   534,  -844,
    -844,  -844,  -844,  -844,   556,  -844,  -844,  -844,  -844,    -1,
    -844,  -844,  2045,  -844,  1799,    -1,  -844,  -844,   914,  -844,
    2045,  -844,  2045,  -844,  -844,  2045,  -844,  -844,  -844,   558,
     546,  -844,  -844,  -844,  -844,   559,  -844,  -844,    35,  1179,
    -844,  -844,  -844,  -844,  1875,  -844,  -844,  -844,  -844,   564,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,    51,  -844,    51,
    -844,    88,   189,  -844,  -844,  -844,    -1,   518,  -844,  -844,
    -844,  -844,  -844,   565,   526,  -844,   -39,  -844,  -844,  -844,
    -844,   561,    18,  -844,  1234,  -844,   512,   567,   577,  -844,
    -844,    60,  -844,    75,    75,  -844,    52,   580,  -844,   588,
    -844,  -844,  -844,  1824,  1824,  1824,   593,   165,  -844,    93,
    -844,  1899,  -844,  -844,    -1,   189,   189,   590,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,    -1,   610,  -844,    -1,  1875,  -844,    67,  -844,  -844,
     556,  -844
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        12,     0,     0,     2,     4,     3,   199,    14,    13,    10,
      68,     1,   183,   183,   183,   183,    74,     0,    74,     0,
     183,   183,     0,     0,   183,     0,   161,     6,     0,     7,
       8,     9,   163,   171,   172,   173,   177,   174,   175,   176,
     178,   179,   180,   181,   200,     0,    16,   184,     0,     0,
       0,     0,   226,     0,   101,    74,   108,   614,   617,   616,
     449,   450,   107,    74,   105,   447,   448,   615,   119,   198,
     217,   217,   196,   226,   195,   217,   194,   288,     5,   162,
     159,    83,    74,   199,     0,     0,   205,   201,   204,    69,
      11,    15,   186,     0,   222,   221,   223,   220,   188,   190,
     189,     0,   228,     0,     0,    75,   119,   106,   109,   120,
     122,     0,   218,   215,     0,     0,     0,     0,     0,   160,
     286,     0,   287,     0,    81,    82,    84,     0,   119,   170,
     164,   166,   210,   211,   208,   203,   202,     0,     0,    17,
      22,    18,     0,   187,   182,   219,   224,   425,   426,   427,
     428,   429,   422,   608,   609,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   610,   612,   611,   613,   618,   619,
     456,   233,   229,   241,   342,   421,   420,   431,     0,   340,
     445,   446,   452,   453,   596,   597,   598,   454,   594,   451,
     455,     0,   112,   113,   114,   115,   117,   122,   122,   122,
     110,     0,   111,   124,   123,   247,   244,   118,   243,   217,
     216,   217,   225,   217,   289,   296,   298,     0,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   568,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   579,   580,   581,   582,     0,   583,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    99,    80,    95,    93,    89,   558,   521,
     523,   559,   560,    94,     0,    90,    91,    92,     0,   122,
      12,   167,   168,     0,     0,   209,     0,   206,    70,    20,
       0,   185,     0,   227,   228,   242,   239,   345,   430,     0,
       0,   592,   593,   595,   590,   116,   103,   102,   104,     0,
       0,   126,   125,   250,   191,   193,   192,     0,     0,   305,
       0,     0,     0,     0,   504,    86,   457,   460,   464,   466,
     468,   478,   489,   492,   497,   498,   499,   505,   500,   501,
     502,   503,   588,   571,     0,     0,     0,   562,   514,     0,
     337,   548,     0,     0,     0,     0,   569,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   520,   332,
     332,     0,   541,   542,     0,     0,     0,     0,   515,     0,
     540,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    98,   332,   332,   329,   328,    73,   199,
     165,   207,     0,   212,   213,     0,     0,    56,     0,    31,
      45,     0,    19,    23,     0,    29,    24,     0,    43,    25,
      26,   355,     0,   430,   354,   234,   230,     0,   240,   343,
     344,   346,   442,   430,   432,   441,   341,   591,     0,   130,
     131,   134,   136,   133,   137,   138,   140,   327,   325,   326,
       0,   128,   127,   436,   245,    77,     0,   246,   253,   251,
     257,     0,   363,   435,   434,   361,   291,   299,   297,     0,
       0,   495,   496,   494,     0,    87,     0,   458,   462,     0,
       0,     0,     0,     0,     0,     0,     0,   467,   469,   479,
     491,   589,   587,   572,     0,     0,     0,   338,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   333,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   214,   197,    71,
       0,   311,    35,   312,    36,    32,    33,     0,   313,   308,
     309,   310,   307,    49,    50,    46,    47,     0,    29,     0,
      43,     0,   423,   352,   358,   360,   231,   228,     0,   424,
     433,    86,   132,   139,     0,     0,     0,   121,   129,   153,
     155,     0,     0,   248,   317,   250,   258,   255,   430,   366,
       0,     0,   295,   302,   304,   306,   506,    85,    88,     0,
     461,     0,   465,   470,   471,   472,   473,   474,   475,     0,
     476,     0,     0,   484,   490,   480,   481,     0,     0,   493,
       0,   512,   513,   561,   335,     0,     0,     0,     0,   570,
     507,   508,     0,   510,   511,     0,   553,   554,   555,   556,
       0,   577,   578,     0,   585,   557,   543,     0,     0,   532,
     547,   539,   538,   519,   546,     0,   537,   518,   536,     0,
     545,   535,   526,     0,   517,   534,   525,   516,   524,     0,
     522,   544,   533,     0,   330,    55,    58,    57,    34,    39,
      48,    53,     0,    28,    37,    30,     0,    42,    51,    44,
     347,   356,   232,   236,     0,   146,   147,   141,   142,     0,
     144,   145,   149,   150,   157,   158,   151,   154,   152,   156,
       0,   404,     0,     0,     0,   368,   370,   371,   379,   386,
     389,   398,   393,   396,   380,   403,    78,   272,   276,   280,
     288,   270,   314,     0,     0,     0,   254,   230,   268,   260,
     262,   263,   264,   266,   267,   261,   259,   318,   265,   256,
     444,   430,   439,   443,   364,   365,   367,   362,   290,   292,
     293,   300,   459,   463,   477,   486,   487,   485,   488,   482,
     483,   573,     0,     0,     0,     0,     0,     0,     0,   564,
     574,     0,   586,     0,     0,     0,     0,   564,     0,     0,
     575,   335,    63,    40,    27,     0,    54,    41,     0,   349,
     353,   430,   359,     0,   135,   143,   148,     0,   413,   416,
       0,   405,   407,   415,   399,   437,   430,   387,   391,   401,
     402,   400,   395,   397,   119,   273,   277,   281,   285,     0,
     315,   324,     0,   269,   250,     0,   438,   440,     0,   339,
       0,   336,     0,   550,   551,     0,   509,   552,   565,     0,
       0,   576,   530,   531,   527,     0,   528,   529,     0,     0,
      38,    52,   350,   351,   430,   357,   237,   406,   414,     0,
     410,   419,   417,   418,   377,   383,   385,     0,   390,     0,
     394,   122,     0,   278,   282,   271,     0,     0,   252,   322,
     303,   301,   334,     0,   564,   563,     0,   566,   331,    59,
      64,    60,     0,   348,   228,   408,   412,   369,   381,   388,
     392,   161,   274,   183,   183,   316,     0,   319,   549,     0,
     584,    61,    62,     0,     0,     0,     0,     0,   411,   374,
     378,   430,   384,    79,     0,     0,     0,     0,   320,   323,
     567,    67,    66,    65,   238,   409,   372,   375,   376,   382,
     275,     0,     0,   284,     0,   430,   279,     0,   321,   373,
     119,   283
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -844,  -844,  -844,  -844,  -844,  -844,   338,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,    36,  -844,   192,  -844,
    -198,  -844,  -844,    55,  -844,  -844,    40,  -844,   194,  -844,
    -194,  -844,  -844,    59,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,    54,
    -844,  -844,  -844,  -844,    25,  -844,  -844,  -844,    34,  -844,
     371,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -141,   -89,  -844,  -177,  -844,  -844,
    -844,  -844,  -844,  -844,   179,  -844,  -844,   182,  -844,  -844,
     -80,  -844,  -844,  -844,  -844,  -844,  -844,    38,    43,  -292,
    -844,  -844,   360,  -844,  -844,  -844,  -844,  -844,   581,  -844,
      -9,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,   578,  -844,  -844,    30,  -844,     5,   615,   -15,   642,
     595,  -844,  -301,  -108,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -402,  -844,  -844,  -844,  -844,  -611,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -100,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -401,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -582,  -111,   310,
    -844,  -325,  -755,  -158,  -233,  -844,  -844,  -844,  -844,  -844,
    -844,  -191,  -844,  -844,  -844,  -844,  -164,  -843,  -844,  -844,
    -165,  -844,  -844,  -844,  -844,  -844,  -365,  -844,  -291,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -294,
     -71,  -844,  -844,  -844,  -237,  -844,  -844,   -72,  -844,  -236,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -796,  -844,  -101,
    -844,  -844,  -844,  -844,  -308,  -844,  -315,  -844,  -844,  -844,
    -844,  -276,  -601,   -78,   -14,    21,  -844,   796,  -844,  -844,
    -844,    49,  -844,  -844,    62,  -844,  -844,  -844,  -188,  -844,
    -844,    29,  -844,  -844,  -844,  -383,  -844,  -381,   -81,  -320,
    -118,  -844,  -844,  -784,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,   -97,  -844,  -844,  -844,  -844,  -844,  -844,   -74,
    -844,  -844,  -844,    77,  -844,   173,   174,   285,  -249,   -17,
    -844,  -844
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
     484,   485,   622,   864,    82,   126,   127,   505,   506,   281,
     282,   283,   284,    29,    54,    30,    62,    63,   199,    31,
     105,   192,   193,   194,   195,   110,   111,   202,   203,   331,
     481,   617,   204,   469,   470,   332,   474,   475,   482,   737,
     738,   739,   740,   741,   618,   746,   748,   619,   620,    78,
      79,    80,     9,    83,   301,   302,   129,   130,    32,    33,
      48,   143,   144,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,   135,    86,   134,   305,   306,
      87,    88,   307,   433,   114,   115,    97,    98,    55,    74,
     101,   102,   171,   607,   455,   313,   456,   457,   843,   944,
     172,   315,   316,   207,   486,   208,   333,   487,   488,   776,
     624,   489,   626,   627,   777,   778,   779,   869,   780,   865,
     922,   974,   781,   866,   923,   953,   782,   867,   924,   954,
     783,   784,   119,   120,   121,   337,   631,   799,   122,   123,
     338,   217,   878,   635,   801,   499,   587,   785,   870,   926,
     786,   787,   875,   979,   994,   957,   788,   476,   477,   427,
     831,   545,   888,   812,   371,   664,   173,   319,   317,   459,
     460,   452,   902,   903,   840,   730,   453,   603,   842,   731,
     604,   490,   630,   629,   794,   795,   754,   856,   755,   987,
     995,   988,   970,   947,   756,   757,   914,   972,   948,   915,
     758,   759,   918,   857,   760,   920,   858,   761,   862,   762,
     863,   763,   851,   968,   946,   908,   909,   852,   912,   462,
     175,   312,   176,   177,   178,   463,   790,   493,   621,   494,
     791,   605,   916,   465,   454,   344,   181,   345,   346,   640,
     507,   347,   642,   508,   348,   349,   517,   518,   350,   351,
     653,   659,   808,   654,   519,   352,   520,   353,   354,   355,
     356,   368,   288,   889,   289,   290,   291,   376,   532,   292,
     523,   660,   357,   683,   294,   822,   823,   358,   522,   359,
     322,   323,   324,   360,   184,   185,   186,   361,   188,   362,
      67,   190
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int SPARQLfedParser::yytable_ninf_ = -431;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        66,   174,    69,    64,    49,    50,    51,    72,   388,   287,
     478,    70,    71,   458,   789,    75,   285,   198,   492,   200,
     326,   327,   328,    56,   179,   491,   632,   792,   182,   633,
     293,    92,   742,   578,  -294,   215,   205,   103,    65,   299,
     597,   191,   464,   895,   432,    66,   727,   366,   107,   369,
     325,  -119,   910,   295,   109,    99,   425,   881,   320,   112,
     724,   943,   303,    93,   497,   546,    10,   723,   657,   132,
     133,    11,    68,   103,   963,   879,   145,   938,   859,   103,
       1,    94,   880,    65,   880,   189,   196,   750,    47,   197,
     104,    77,   750,   767,   768,   769,   109,   751,   210,   575,
     576,   116,   751,   -21,    52,   118,   437,   833,    81,   106,
     298,   752,   658,    57,    58,    59,   752,   108,   770,    73,
     860,   715,   428,   180,   716,  -249,   461,   724,   466,    89,
     669,   848,   771,   772,   750,   773,   128,   164,   165,   166,
     167,   849,   214,   881,   751,    84,    85,   311,   286,   304,
     959,   451,   999,   753,   478,   742,   321,   728,   752,   113,
     911,   861,   206,    95,    96,   287,    93,   964,   965,   450,
     -21,   985,   285,   438,   196,    85,   634,  -119,   142,   183,
     201,  -294,   216,    57,    58,    59,   293,   610,    60,    61,
     877,   871,   850,   597,   367,   753,   370,    57,    58,    59,
      57,    58,    59,   426,   296,   124,   125,    60,    61,   295,
     146,   473,   479,   174,   774,   209,   849,   -21,   471,   -21,
     439,   -21,   440,   211,   441,   300,    57,    58,    59,   138,
     800,    57,    58,    59,   212,   775,   179,    60,    61,   334,
     182,   335,   213,   336,   182,   308,   -21,   -21,   -21,    57,
      58,    59,   615,   616,   309,   495,   836,   728,   811,   182,
     501,   502,   503,   928,   796,   797,   298,   850,   805,   806,
      57,    58,    59,    57,    58,    59,   809,   810,    60,    61,
      57,    58,    59,   650,   314,    60,    61,   434,   431,    57,
      58,    59,   318,   196,   478,    66,   329,   189,   330,   339,
      66,   189,    66,   467,   286,   363,   732,   364,   365,   372,
     492,   392,   298,   298,   373,   374,   189,   491,  -169,   375,
     491,   643,   644,   645,   646,   647,   648,    12,   377,    13,
      14,   378,    15,    65,   379,   180,   380,   381,    65,   180,
      65,   382,   383,   384,   385,    57,    58,    59,   386,   387,
     472,   473,   389,   390,   180,   391,   479,   393,   471,   498,
     296,   394,   395,   396,   589,   397,   398,   589,   399,    57,
      58,    59,   400,   873,    60,    61,   401,   402,   403,   182,
     404,   405,   406,   407,   408,   409,   410,   187,   411,   182,
     412,   183,   413,   414,   415,   183,    12,   416,    13,    14,
     417,    15,   537,   418,   -72,   419,   420,   421,    16,    17,
     183,   422,   297,   424,   435,   577,   804,   478,  -235,   846,
     480,   592,   496,    19,   592,   504,    18,   544,   579,   438,
     441,   602,   606,   608,    20,    21,   189,   597,    22,   614,
      23,   623,   625,   628,   639,   340,   189,   636,    24,   638,
      25,   641,   298,   478,   719,   665,   649,   298,   661,   588,
     662,   663,   588,   666,   667,   670,   668,   925,   671,   672,
     673,   674,   721,   929,   180,   676,   677,   931,   678,   675,
     679,   680,   685,   491,   180,   686,   687,   689,   688,   690,
     472,   691,    19,   692,   693,   694,   479,   695,   942,   696,
     697,   698,   700,    20,    21,   699,   174,    22,   701,    23,
     589,   702,   651,   652,   703,   590,   704,    24,   590,    25,
     589,   705,   706,   707,   955,   637,   708,   710,   711,   179,
     183,   709,   712,   182,   509,   510,   511,   512,   513,   514,
     183,   616,   744,   745,   515,   516,   615,   495,   491,   820,
     793,   182,   821,   839,   182,   830,   844,   589,   841,   492,
     872,   855,   981,   982,   983,   882,   491,   592,   297,   883,
     884,   885,   990,   886,   887,   880,   890,   592,    12,   891,
      13,    14,   892,    15,   893,   894,   896,   897,   906,   996,
     189,    66,   998,   917,   733,   907,   109,   298,   919,   187,
     935,   937,   936,   187,   765,   588,   945,   958,   189,   956,
     961,   189,   765,   765,   592,   588,   967,   969,   187,   479,
     158,   159,   160,   161,   162,   163,   971,   978,   180,    65,
     980,   984,   993,   997,   722,   743,   598,   900,   429,   718,
     726,   600,   764,   966,   901,   734,   180,   766,   612,   180,
     764,   764,   588,   720,   423,   479,   613,   845,   749,   973,
     430,   590,   747,   491,   131,   136,   100,    76,   117,   874,
     868,   590,   521,   898,    19,   904,   905,   989,   986,   847,
     949,   854,   807,   950,   183,    20,    21,   960,   802,    22,
       0,    23,   655,   656,     0,     0,     0,     0,     0,    24,
       0,    25,   183,   803,     0,   183,     0,     0,   590,     0,
       0,     0,     0,   793,     0,     0,     0,   182,     0,     0,
     298,     0,     0,   591,     0,     0,   591,     0,     0,     0,
       0,     0,     0,   765,     0,   853,   765,     0,   187,     0,
       0,     0,     0,     0,   951,     0,     0,     0,   187,     0,
       0,     0,     0,     0,     0,     0,   298,     0,   743,     0,
       0,   589,     0,     0,   589,     0,     0,   182,     0,     0,
       0,     0,     0,     0,   189,   921,     0,     0,   793,     0,
       0,     0,   182,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   495,     0,     0,     0,
     182,     0,     0,     0,   589,     0,     0,     0,     0,     0,
       0,     0,   180,     0,     0,     0,     0,     0,   592,     0,
       0,   592,    66,     0,   189,   589,     0,     0,     0,     0,
     182,   853,     0,   913,     0,     0,     0,     0,     0,   189,
       0,     0,     0,   174,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   588,   189,     0,   588,
      65,   592,   180,     0,     0,     0,   179,     0,   183,   591,
     182,     0,     0,     0,     0,     0,     0,   180,     0,   591,
       0,     0,   592,     0,     0,     0,     0,   189,     0,   589,
     589,   589,   187,   793,     0,   180,     0,   182,     0,   588,
     765,     0,   765,     0,     0,    66,     0,     0,   952,     0,
     187,  1001,   590,   187,     0,   590,   591,     0,   183,     0,
     588,   182,     0,   798,     0,   180,     0,   189,   581,     0,
       0,     0,     0,   183,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    65,   975,   976,   592,   592,   592,     0,
     853,   183,   765,     0,   189,   590,   930,   581,    66,    66,
       0,   991,   992,     0,     0,   180,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   590,   977,   189,     0,
       0,   183,  1000,     0,   588,   588,   588,     0,     0,     0,
     764,     0,   180,     0,     0,     0,    65,    65,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   180,     0,     0,     0,
       0,   183,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     590,   590,   590,     0,     0,     0,     0,     0,   183,   583,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    57,    58,    59,     0,     0,
      60,    61,   183,     0,     0,     0,   187,     0,   583,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    57,    58,    59,     0,     0,    60,
      61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     591,     0,     0,   591,     0,     0,   187,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   500,     0,     0,     0,
       0,   187,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   187,
     524,   525,   526,   591,     0,   527,     0,     0,   528,   529,
     530,   531,     0,   533,   534,   535,   536,     0,   538,   539,
     540,   541,   542,   543,   591,     0,     0,   547,     0,   187,
     548,   549,   550,   551,   581,   552,     0,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,     0,
       0,   939,   581,     0,     0,     0,     0,   -76,     0,   187,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   147,   148,   149,   150,   151,     0,   591,   591,
     591,  -430,     0,     0,     0,   582,   187,     0,     0,     0,
       0,     0,   483,     0,   611,     0,   147,   148,   149,   150,
     151,     0,     0,     0,     0,  -430,     0,     0,     0,     0,
     187,     0,     0,     0,     0,     0,   152,     0,     0,     0,
     147,   148,   149,   150,   151,     0,     0,     0,     0,     0,
     609,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     152,     0,     0,     0,     0,   583,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    57,    58,    59,     0,     0,    60,    61,     0,     0,
       0,   682,   684,   583,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    57,
      58,    59,     0,     0,    60,    61,     0,     0,     0,     0,
       0,   713,   714,     0,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      57,    58,    59,   168,   169,    60,    61,     0,   170,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    57,    58,    59,   168,   169,    60,
      61,     0,   170,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    57,    58,
      59,   168,   169,    60,    61,     0,   170,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   681,     0,
       0,   813,   814,   815,   816,     0,     0,     0,   817,     0,
       0,   818,     0,     0,     0,     0,   819,     0,     0,   340,
       0,     0,     0,   824,   825,     0,     0,     0,     0,     0,
       0,   826,     0,     0,     0,   827,     0,     0,     0,   828,
     341,   342,     0,   343,   220,   829,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   581,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,     0,   241,     0,
       0,     0,   242,   243,   244,   245,   246,   247,   248,   249,
       0,     0,     0,     0,     0,     0,     0,   250,   251,   252,
       0,   253,   254,   255,     0,     0,   256,   257,     0,   258,
       0,   259,   260,   261,   262,     0,   263,   264,     0,   265,
       0,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    57,    58,
      59,     0,     0,    60,    61,     0,     0,   593,     0,     0,
       0,     0,     0,     0,   218,     0,   583,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    57,    58,    59,   219,     0,    60,    61,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   927,     0,
       0,     0,     0,     0,     0,     0,   932,     0,   933,     0,
     220,   934,   221,   222,   223,   224,   225,   226,   227,   228,
     229,     0,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,   241,     0,     0,     0,   242,   243,
     244,   245,   246,   247,   248,   249,     0,     0,     0,     0,
       0,     0,     0,   250,   251,   252,     0,   253,   254,   255,
       0,     0,   256,   257,     0,   258,     0,   259,   260,   261,
     262,     0,   263,   264,     0,   265,     0,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   735,   736,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   340,     0,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    57,    58,    59,     0,     0,    60,
      61,   220,     0,   221,   222,   223,   224,   225,   226,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     0,   241,     0,     0,     0,     0,
       0,   147,   148,   149,   150,   151,   249,     0,     0,     0,
    -430,     0,     0,     0,   250,   251,   252,     0,   253,   254,
     255,   483,     0,   256,   257,     0,   258,     0,   259,   260,
     261,   262,     0,   263,   264,     0,   265,   581,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   147,   148,   149,   150,   151,     0,     0,
       0,     0,     0,   876,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   483,     0,     0,     0,   147,   148,   149,
     150,   151,     0,     0,     0,    57,    58,    59,     0,     0,
      60,    61,     0,     0,     0,     0,     0,   152,     0,     0,
       0,   147,   148,   149,   150,   151,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   483,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    57,
      58,    59,   168,   169,    60,    61,     0,   170,   583,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    57,    58,    59,     0,     0,    60,
      61,     0,     0,     0,     0,     0,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    57,    58,    59,   168,   169,    60,    61,     0,   170,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    57,    58,    59,   168,   169,
      60,    61,     0,   170,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    57,
      58,    59,   168,   169,    60,    61,   340,   170,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   341,   342,     0,
     343,   220,     0,   221,   222,   223,   224,   225,   226,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     0,   241,     0,     0,     0,   242,
     243,   244,   245,   246,   247,   248,   249,     0,     0,     0,
       0,     0,     0,     0,   250,   251,   252,     0,   253,   254,
     255,     0,     0,   256,   257,     0,   258,     0,   259,   260,
     261,   262,     0,   263,   264,     0,   265,     0,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   219,     0,     0,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    57,    58,    59,     0,     0,
      60,    61,   220,     0,   221,   222,   223,   224,   225,   226,
     227,   228,   229,     0,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,   241,     0,     0,     0,
     242,   243,   244,   245,   246,   247,   248,   249,     0,     0,
       0,     0,     0,     0,     0,   250,   251,   252,     0,   253,
     254,   255,     0,     0,   256,   257,     0,   258,     0,   259,
     260,   261,   262,     0,   263,   264,     0,   265,     0,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   340,     0,
       0,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    57,    58,    59,     0,
       0,    60,    61,   220,     0,   221,   222,   223,   224,   225,
     226,   227,   228,   229,     0,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,     0,   241,     0,     0,
       0,   242,   243,   244,   245,   246,   247,   248,   249,     0,
       0,     0,     0,     0,     0,     0,   250,   251,   252,     0,
     253,   254,   255,     0,     0,   256,   257,     0,   258,     0,
     259,   260,   261,   262,     0,   263,   264,     0,   265,     0,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   468,
       0,     0,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    57,    58,    59,
       0,     0,    60,    61,   220,     0,   221,   222,   223,   224,
     225,   226,   227,   228,   229,     0,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,     0,   241,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   249,
       0,     0,     0,     0,     0,     0,     0,   250,   251,   252,
       0,   253,   254,   255,     0,     0,   256,   257,     0,   258,
       0,   259,   260,   261,   262,   340,   263,   264,     0,   265,
       0,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,     0,     0,     0,     0,
     220,     0,   221,   222,   223,   224,   225,   226,   227,   228,
     229,     0,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,   241,     0,     0,     0,    57,    58,
      59,     0,     0,    60,    61,   249,     0,     0,     0,     0,
       0,     0,     0,   250,   251,   252,     0,   253,   254,   255,
       0,     0,   256,   257,     0,   258,     0,   259,   260,   261,
     262,     0,   263,   264,     0,   265,     0,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    57,    58,    59
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        17,   102,    19,    17,    13,    14,    15,    22,   241,   127,
     330,    20,    21,   314,   625,    24,   127,   106,   333,   108,
     197,   198,   199,    20,   102,   333,    38,   628,   102,    41,
     127,    48,   614,   435,    41,    41,    37,    23,    17,   128,
     441,    24,   318,   827,    24,    62,    44,    41,    62,    41,
     191,    37,   848,   127,    40,    50,    41,   812,    89,     6,
     104,   904,    21,     6,    42,   390,   180,    44,    20,    84,
      85,     0,    18,    23,    56,    42,    93,    42,    20,    23,
      15,    24,    49,    62,    49,   102,   103,    41,    13,   104,
      40,    31,    41,     6,     7,     8,    40,    51,   115,   424,
     425,    71,    51,    37,    37,    75,    37,   151,    17,    55,
     127,    65,    64,   180,   181,   182,    65,    63,    31,    37,
      62,    38,   299,   102,    41,    38,   317,   104,   319,    16,
     532,    41,    45,    46,    41,    48,    82,   176,   177,   178,
     179,    51,   121,   898,    51,     3,     4,   142,   127,   108,
     934,    51,   995,   102,   474,   737,   187,   155,    65,   106,
      51,   103,   163,   106,   107,   283,     6,   149,   150,   310,
     104,   967,   283,   104,   191,     4,   188,   163,    10,   102,
      92,   188,   188,   180,   181,   182,   283,   463,   185,   186,
     791,   773,   102,   594,   188,   102,   188,   180,   181,   182,
     180,   181,   182,   188,   127,    18,    19,   185,   186,   283,
      38,   329,   330,   314,   127,   112,    51,   151,   329,   153,
     151,   155,   153,   112,   155,    50,   180,   181,   182,   163,
     631,   180,   181,   182,    38,   148,   314,   185,   186,   209,
     314,   211,   112,   213,   318,   181,   180,   181,   182,   180,
     181,   182,    29,    30,    56,   333,   154,   155,   660,   333,
     341,   342,   343,   874,   629,   630,   283,   102,   651,   652,
     180,   181,   182,   180,   181,   182,   657,   658,   185,   186,
     180,   181,   182,   516,    44,   185,   186,   304,   303,   180,
     181,   182,    41,   310,   614,   312,    26,   314,    93,    37,
     317,   318,   319,   320,   283,    76,   607,    41,    41,    41,
     625,   188,   329,   330,    41,    41,   333,   625,     0,    41,
     628,   509,   510,   511,   512,   513,   514,     9,    41,    11,
      12,    41,    14,   312,    41,   314,    41,    41,   317,   318,
     319,    41,    41,    41,    41,   180,   181,   182,    41,    41,
     329,   469,    41,    41,   333,    41,   474,   188,   469,   338,
     283,    41,    41,    41,   438,    41,   188,   441,    41,   180,
     181,   182,   188,   775,   185,   186,    41,    41,    41,   453,
      41,    41,    41,    41,    41,    41,    41,   102,    41,   463,
      41,   314,    41,    41,    41,   318,     9,    41,    11,    12,
      41,    14,   381,    41,    17,    41,    41,    41,    21,    22,
     333,    41,   127,    41,    40,   432,   649,   737,     6,   739,
      25,   438,    37,   105,   441,    91,    39,    18,   180,   104,
     155,    53,    44,     6,   116,   117,   453,   838,   120,    26,
     122,    38,    44,    41,    54,    41,   463,    42,   130,    42,
     132,    55,   469,   773,   104,    49,    67,   474,    42,   438,
      42,    42,   441,    49,    49,    42,    49,   869,    42,    49,
      42,    42,   155,   875,   453,    42,    42,   878,    42,    49,
      42,    49,    42,   791,   463,    42,    49,    42,    49,    42,
     469,    42,   105,    42,    42,    42,   614,    49,   899,    42,
      42,    42,    42,   116,   117,    49,   607,   120,    42,   122,
     584,    42,    62,    63,    49,   438,    42,   130,   441,   132,
     594,    42,    42,    42,   926,   504,    42,    42,    42,   607,
     453,    49,    42,   607,    56,    57,    58,    59,    60,    61,
     463,    30,   167,   167,    66,    67,    29,   625,   856,    42,
     628,   625,    50,    50,   628,    42,    42,   631,    49,   874,
      41,    53,   963,   964,   965,    49,   874,   584,   283,    42,
      42,    49,   974,    42,    42,    49,    77,   594,     9,    42,
      11,    12,    42,    14,    42,    42,    42,    42,    37,   991,
     607,   608,   994,   104,   608,    42,    40,   614,    64,   314,
      42,    42,    56,   318,   621,   584,    42,    42,   625,    91,
      49,   628,   629,   630,   631,   594,   104,    50,   333,   737,
     170,   171,   172,   173,   174,   175,    49,    47,   607,   608,
      42,    38,    42,    23,   598,   614,   444,   835,   300,   584,
     600,   447,   621,   944,   838,   611,   625,   622,   469,   628,
     629,   630,   631,   594,   283,   773,   474,   737,   620,   951,
     300,   584,   619,   971,    83,    87,    51,    25,    73,   777,
     770,   594,   362,   831,   105,   839,   841,   971,   969,   750,
     917,   753,   653,   919,   607,   116,   117,   936,   639,   120,
      -1,   122,   519,   519,    -1,    -1,    -1,    -1,    -1,   130,
      -1,   132,   625,   641,    -1,   628,    -1,    -1,   631,    -1,
      -1,    -1,    -1,   791,    -1,    -1,    -1,   791,    -1,    -1,
     737,    -1,    -1,   438,    -1,    -1,   441,    -1,    -1,    -1,
      -1,    -1,    -1,   750,    -1,   752,   753,    -1,   453,    -1,
      -1,    -1,    -1,    -1,   921,    -1,    -1,    -1,   463,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   773,    -1,   737,    -1,
      -1,   835,    -1,    -1,   838,    -1,    -1,   841,    -1,    -1,
      -1,    -1,    -1,    -1,   791,   864,    -1,    -1,   856,    -1,
      -1,    -1,   856,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   874,    -1,    -1,    -1,
     874,    -1,    -1,    -1,   878,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   791,    -1,    -1,    -1,    -1,    -1,   835,    -1,
      -1,   838,   839,    -1,   841,   899,    -1,    -1,    -1,    -1,
     904,   848,    -1,   850,    -1,    -1,    -1,    -1,    -1,   856,
      -1,    -1,    -1,   944,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   835,   874,    -1,   838,
     839,   878,   841,    -1,    -1,    -1,   944,    -1,   791,   584,
     944,    -1,    -1,    -1,    -1,    -1,    -1,   856,    -1,   594,
      -1,    -1,   899,    -1,    -1,    -1,    -1,   904,    -1,   963,
     964,   965,   607,   971,    -1,   874,    -1,   971,    -1,   878,
     917,    -1,   919,    -1,    -1,   922,    -1,    -1,   922,    -1,
     625,  1000,   835,   628,    -1,   838,   631,    -1,   841,    -1,
     899,   995,    -1,    38,    -1,   904,    -1,   944,    43,    -1,
      -1,    -1,    -1,   856,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   922,   953,   954,   963,   964,   965,    -1,
     967,   874,   969,    -1,   971,   878,    42,    43,   975,   976,
      -1,   975,   976,    -1,    -1,   944,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   899,   956,   995,    -1,
      -1,   904,   997,    -1,   963,   964,   965,    -1,    -1,    -1,
     969,    -1,   971,    -1,    -1,    -1,   975,   976,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   995,    -1,    -1,    -1,
      -1,   944,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     963,   964,   965,    -1,    -1,    -1,    -1,    -1,   971,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,    -1,    -1,
     185,   186,   995,    -1,    -1,    -1,   791,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,   185,
     186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     835,    -1,    -1,   838,    -1,    -1,   841,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   340,    -1,    -1,    -1,
      -1,   856,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   874,
     364,   365,   366,   878,    -1,   369,    -1,    -1,   372,   373,
     374,   375,    -1,   377,   378,   379,   380,    -1,   382,   383,
     384,   385,   386,   387,   899,    -1,    -1,   391,    -1,   904,
     394,   395,   396,   397,    43,   399,    -1,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    17,    -1,   944,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    -1,   963,   964,
     965,    41,    -1,    -1,    -1,   104,   971,    -1,    -1,    -1,
      -1,    -1,    52,    -1,   468,    -1,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,
     995,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,    -1,    -1,   185,   186,    -1,    -1,
      -1,   545,   546,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,    -1,    -1,   185,   186,    -1,    -1,    -1,    -1,
      -1,   575,   576,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,   188,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,   188,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,   188,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,
      -1,   665,   666,   667,   668,    -1,    -1,    -1,   672,    -1,
      -1,   675,    -1,    -1,    -1,    -1,   680,    -1,    -1,    41,
      -1,    -1,    -1,   687,   688,    -1,    -1,    -1,    -1,    -1,
      -1,   695,    -1,    -1,    -1,   699,    -1,    -1,    -1,   703,
      62,    63,    -1,    65,    66,   709,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    43,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    90,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,
      -1,   113,   114,   115,    -1,    -1,   118,   119,    -1,   121,
      -1,   123,   124,   125,   126,    -1,   128,   129,    -1,   131,
      -1,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,   185,   186,    -1,    -1,   155,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    41,    -1,   185,   186,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   872,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   880,    -1,   882,    -1,
      66,   885,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    -1,    90,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,   110,   111,    -1,   113,   114,   115,
      -1,    -1,   118,   119,    -1,   121,    -1,   123,   124,   125,
     126,    -1,   128,   129,    -1,   131,    -1,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,   185,
     186,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,   101,    -1,    -1,    -1,
      41,    -1,    -1,    -1,   109,   110,   111,    -1,   113,   114,
     115,    52,    -1,   118,   119,    -1,   121,    -1,   123,   124,
     125,   126,    -1,   128,   129,    -1,   131,    43,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,
     185,   186,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,    -1,   188,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,   185,
     186,    -1,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,    -1,   188,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,    -1,   188,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,    41,   188,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,   110,   111,    -1,   113,   114,
     115,    -1,    -1,   118,   119,    -1,   121,    -1,   123,   124,
     125,   126,    -1,   128,   129,    -1,   131,    -1,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,    -1,    -1,
     185,   186,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,   113,
     114,   115,    -1,    -1,   118,   119,    -1,   121,    -1,   123,
     124,   125,   126,    -1,   128,   129,    -1,   131,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,   185,   186,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    90,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,
     113,   114,   115,    -1,    -1,   118,   119,    -1,   121,    -1,
     123,   124,   125,   126,    -1,   128,   129,    -1,   131,    -1,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
      -1,    -1,   185,   186,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    90,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,
      -1,   113,   114,   115,    -1,    -1,   118,   119,    -1,   121,
      -1,   123,   124,   125,   126,    41,   128,   129,    -1,   131,
      -1,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    -1,    90,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,   185,   186,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,   110,   111,    -1,   113,   114,   115,
      -1,    -1,   118,   119,    -1,   121,    -1,   123,   124,   125,
     126,    -1,   128,   129,    -1,   131,    -1,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    15,   190,   191,   192,   194,   195,   196,   232,   291,
     180,     0,     9,    11,    12,    14,    21,    22,    39,   105,
     116,   117,   120,   122,   130,   132,   193,   236,   237,   252,
     254,   258,   297,   298,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   197,    13,   299,   299,
     299,   299,    37,   238,   253,   327,    20,   180,   181,   182,
     185,   186,   255,   256,   473,   474,   528,   529,   238,   528,
     299,   299,   327,    37,   328,   299,   328,    31,   288,   289,
     290,    17,   243,   292,     3,     4,   315,   319,   320,    16,
     198,   233,   528,     6,    24,   106,   107,   325,   326,   325,
     326,   329,   330,    23,    40,   259,   238,   473,   238,    40,
     264,   265,     6,   106,   323,   324,   323,   329,   323,   371,
     372,   373,   377,   378,    18,    19,   244,   245,   238,   295,
     296,   297,   327,   327,   316,   314,   320,   234,   163,   199,
     201,   202,    10,   300,   301,   528,    38,    32,    33,    34,
      35,    36,    52,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   183,   184,
     188,   331,   339,   405,   458,   459,   461,   462,   463,   472,
     474,   475,   518,   522,   523,   524,   525,   526,   527,   528,
     530,    24,   260,   261,   262,   263,   528,   327,   264,   257,
     264,    92,   266,   267,   271,    37,   163,   342,   344,   112,
     528,   112,    38,   112,   474,    41,   188,   380,    20,    41,
      66,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    90,    94,    95,    96,    97,    98,    99,   100,   101,
     109,   110,   111,   113,   114,   115,   118,   119,   121,   123,
     124,   125,   126,   128,   129,   131,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   248,   249,   250,   251,   397,   474,   499,   501,   503,
     504,   505,   508,   511,   513,   518,   522,   526,   528,   264,
      50,   293,   294,    21,   108,   317,   318,   321,   181,    56,
     200,   325,   460,   334,    44,   340,   341,   407,    41,   406,
      89,   187,   519,   520,   521,   263,   266,   266,   266,    26,
      93,   268,   274,   345,   323,   323,   323,   374,   379,    37,
      41,    62,    63,    65,   474,   476,   477,   480,   483,   484,
     487,   488,   494,   496,   497,   498,   499,   511,   516,   518,
     522,   526,   528,    76,    41,    41,    41,   188,   500,    41,
     188,   403,    41,    41,    41,    41,   506,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,   403,    41,
      41,    41,   188,   188,    41,    41,    41,    41,   188,    41,
     188,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,   249,    41,    41,   188,   398,   266,   195,
     291,   327,    24,   322,   528,    40,   235,    37,   104,   151,
     153,   155,   203,   204,   206,   207,   214,   216,   217,   224,
     263,    51,   410,   415,   473,   333,   335,   336,   331,   408,
     409,   410,   458,   464,   470,   472,   410,   528,    41,   272,
     273,   397,   474,   499,   275,   276,   396,   397,   498,   499,
      25,   269,   277,    52,   239,   240,   343,   346,   347,   350,
     420,   463,   465,   466,   468,   472,    37,    42,   474,   384,
     476,   497,   497,   497,    91,   246,   247,   479,   482,    56,
      57,    58,    59,    60,    61,    66,    67,   485,   486,   493,
     495,   398,   517,   509,   476,   476,   476,   476,   476,   476,
     476,   476,   507,   476,   476,   476,   476,   474,   476,   476,
     476,   476,   476,   476,    18,   400,   400,   476,   476,   476,
     476,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     476,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     476,   476,   476,   476,   476,   400,   400,   528,   342,   180,
     225,    43,   104,   164,   208,   209,   212,   385,   474,   518,
     522,   526,   528,   155,   218,   219,   222,   385,   207,   205,
     217,   215,    53,   416,   419,   470,    44,   332,     6,    42,
     470,   476,   273,   276,    26,    29,    30,   270,   283,   286,
     287,   467,   241,    38,   349,    44,   351,   352,    41,   422,
     421,   375,    38,    41,   188,   382,    42,   474,    42,    54,
     478,    55,   481,   487,   487,   487,   487,   487,   487,    67,
     403,    62,    63,   489,   492,   524,   525,    20,    64,   490,
     510,    42,    42,    42,   404,    49,    49,    49,    49,   342,
      42,    42,    49,    42,    42,    49,    42,    42,    42,    42,
      49,    20,   476,   512,   476,    42,    42,    49,    49,    42,
      42,    42,    42,    42,    42,    49,    42,    42,    42,    49,
      42,    42,    42,    49,    42,    42,    42,    42,    42,    49,
      42,    42,    42,   476,   476,    38,    41,   226,   212,   104,
     222,   155,   205,    44,   104,   210,   215,    44,   155,   220,
     414,   418,   331,   473,   247,    27,    28,   278,   279,   280,
     281,   282,   396,   474,   167,   167,   284,   287,   285,   286,
      41,    51,    65,   102,   425,   427,   433,   434,   439,   440,
     443,   446,   448,   450,   474,   528,   243,     6,     7,     8,
      31,    45,    46,    48,   127,   148,   348,   353,   354,   355,
     357,   361,   365,   369,   370,   386,   389,   390,   395,   347,
     465,   469,   471,   472,   423,   424,   425,   425,    38,   376,
     385,   383,   480,   483,   403,   494,   494,   490,   491,   496,
     496,   342,   402,   476,   476,   476,   476,   476,   476,   476,
      42,    50,   514,   515,   476,   476,   476,   476,   476,   476,
      42,   399,   227,   151,   213,   211,   154,   223,   221,    50,
     413,    49,   417,   337,    42,   279,   498,   439,    41,    51,
     102,   451,   456,   528,   446,    53,   426,   442,   445,    20,
      62,   103,   447,   449,   242,   358,   362,   366,   371,   356,
     387,   396,    41,   342,   332,   391,    42,   471,   381,    42,
      49,   401,    49,    42,    42,    49,    42,    42,   401,   502,
      77,    42,    42,    42,    42,   502,    42,    42,   402,   230,
     209,   219,   411,   412,   415,   419,    37,    42,   454,   455,
     456,    51,   457,   528,   435,   438,   471,   104,   441,    64,
     444,   264,   359,   363,   367,   342,   388,   476,   347,   342,
      42,   385,   476,   476,   476,    42,    56,    42,    42,    42,
     229,   231,   385,   416,   338,    42,   453,   432,   437,   443,
     448,   266,   473,   364,   368,   342,    91,   394,    42,   502,
     527,    49,   228,    56,   149,   150,   331,   104,   452,    50,
     431,    49,   436,   288,   360,   299,   299,   474,    47,   392,
      42,   385,   385,   385,    38,   456,   427,   428,   430,   438,
     342,   473,   473,    42,   393,   429,   342,    23,   342,   416,
     327,   264
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
     235,   233,   237,   236,   238,   238,   240,   241,   242,   239,
     243,   244,   244,   245,   245,   246,   247,   247,   248,   249,
     249,   249,   249,   249,   249,   249,   249,   250,   250,   251,
     251,   252,   253,   253,   254,   255,   255,   256,   256,   257,
     257,   258,   259,   260,   260,   261,   262,   263,   264,   265,
     265,   266,   267,   267,   268,   268,   269,   269,   270,   270,
     271,   272,   272,   273,   273,   273,   273,   274,   275,   275,
     276,   277,   278,   278,   279,   279,   280,   280,   281,   282,
     282,   283,   283,   284,   284,   285,   285,   286,   287,   288,
     289,   290,   290,   292,   291,   293,   294,   294,   295,   296,
     296,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   298,   299,   299,   300,   301,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     313,   314,   314,   315,   315,   316,   316,   317,   318,   318,
     319,   320,   321,   322,   322,   323,   323,   324,   324,   325,
     326,   326,   326,   326,   327,   328,   330,   329,   331,   331,
     332,   332,   333,   334,   334,   336,   337,   338,   335,   339,
     340,   341,   341,   342,   342,   343,   343,   345,   344,   346,
     347,   347,   348,   349,   349,   350,   351,   352,   352,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   354,
     356,   355,   358,   359,   360,   357,   362,   363,   364,   361,
     366,   367,   368,   365,   369,   370,   371,   371,   373,   374,
     372,   375,   375,   376,   378,   377,   379,   379,   380,   380,
     381,   381,   383,   382,   382,   384,   384,   385,   385,   385,
     385,   385,   385,   385,   387,   388,   386,   390,   391,   389,
     393,   392,   394,   394,   395,   396,   396,   396,   397,   398,
     399,   398,   400,   400,   401,   402,   402,   403,   404,   403,
     406,   405,   407,   405,   408,   409,   409,   410,   411,   412,
     412,   413,   414,   414,   415,   415,   416,   417,   418,   418,
     419,   421,   420,   422,   420,   423,   424,   424,   426,   425,
     427,   427,   429,   428,   430,   430,   431,   432,   432,   433,
     434,   435,   436,   437,   437,   438,   439,   440,   441,   442,
     442,   443,   444,   445,   445,   446,   447,   447,   448,   448,
     449,   449,   449,   450,   450,   450,   450,   451,   451,   452,
     453,   453,   454,   455,   455,   456,   456,   456,   457,   457,
     458,   458,   460,   459,   461,   462,   462,   462,   462,   462,
     463,   463,   464,   464,   465,   465,   467,   466,   468,   469,
     469,   470,   470,   471,   471,   472,   472,   473,   473,   474,
     474,   475,   475,   475,   475,   475,   475,   476,   477,   478,
     479,   479,   480,   481,   482,   482,   483,   484,   485,   485,
     486,   486,   486,   486,   486,   486,   486,   486,   487,   488,
     489,   489,   490,   490,   491,   491,   492,   492,   492,   493,
     493,   494,   495,   495,   496,   496,   496,   496,   497,   497,
     497,   497,   497,   497,   497,   497,   498,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   500,   500,   501,   502,   502,   503,   504,   506,   507,
     505,   509,   510,   508,   511,   511,   511,   512,   512,   513,
     513,   513,   513,   513,   514,   515,   515,   516,   517,   517,
     518,   519,   520,   520,   521,   521,   522,   522,   522,   523,
     523,   523,   524,   524,   524,   525,   525,   525,   526,   526,
     527,   527,   527,   527,   528,   528,   529,   529,   530,   530
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
       0,     5,     0,     5,     0,     2,     0,     0,     0,     7,
       3,     1,     1,     0,     1,     2,     0,     1,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     2,     4,     4,     5,     1,     2,     1,     1,     0,
       1,     4,     2,     1,     1,     1,     2,     1,     2,     0,
       1,     4,     0,     1,     0,     1,     0,     1,     0,     1,
       3,     1,     2,     1,     1,     4,     1,     2,     1,     2,
       1,     3,     1,     2,     1,     1,     1,     1,     2,     1,
       1,     2,     2,     0,     1,     0,     1,     2,     2,     1,
       2,     0,     1,     0,     4,     2,     0,     1,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     0,     1,     2,     0,     1,     3,     3,
       3,     5,     5,     5,     2,     2,     2,     6,     2,     0,
       1,     0,     1,     2,     1,     0,     2,     2,     0,     1,
       2,     2,     2,     1,     2,     1,     2,     0,     1,     2,
       1,     1,     1,     1,     3,     3,     0,     3,     0,     1,
       0,     1,     3,     0,     2,     0,     0,     0,     8,     2,
       2,     0,     1,     1,     1,     1,     1,     0,     4,     2,
       0,     1,     3,     0,     2,     2,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     3,     0,     0,     0,     6,     0,     0,     0,     7,
       0,     0,     0,     9,     6,     2,     1,     1,     0,     0,
       6,     0,     2,     1,     0,     5,     0,     2,     1,     3,
       0,     2,     0,     4,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     0,     0,     4,     0,     0,     4,
       0,     3,     0,     2,     2,     1,     1,     1,     2,     1,
       0,     6,     0,     1,     2,     0,     2,     1,     0,     5,
       0,     3,     0,     3,     1,     0,     1,     3,     2,     0,
       1,     2,     0,     2,     1,     1,     2,     2,     0,     2,
       1,     0,     3,     0,     3,     1,     0,     1,     0,     4,
       1,     1,     0,     3,     0,     1,     2,     0,     2,     1,
       1,     2,     2,     0,     2,     1,     1,     2,     2,     0,
       2,     2,     2,     0,     2,     2,     0,     1,     1,     2,
       1,     1,     1,     1,     1,     2,     3,     1,     3,     2,
       0,     2,     2,     0,     1,     1,     1,     2,     1,     1,
       1,     1,     0,     4,     4,     1,     1,     1,     1,     1,
       0,     1,     1,     2,     1,     1,     0,     4,     4,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       0,     2,     2,     2,     0,     2,     1,     2,     0,     1,
       2,     2,     2,     2,     2,     2,     2,     3,     1,     2,
       1,     1,     2,     2,     0,     1,     2,     2,     2,     0,
       2,     2,     0,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     4,     4,     6,
       4,     4,     4,     4,     2,     2,     4,     4,     4,     4,
       2,     1,     4,     1,     4,     4,     4,     6,     6,     6,
       6,     6,     4,     4,     4,     4,     4,     4,     4,     4,
       2,     2,     2,     4,     4,     4,     4,     4,     2,     8,
       6,     6,     6,     4,     4,     4,     4,     4,     1,     1,
       1,     3,     1,     7,     0,     1,     7,     9,     0,     0,
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
  "_QDatasetClause_E_Star", "SubSelect", "@8", "@9", "@10", "SelectClause",
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
  "_Q_O_QIT_VALUES_E_S_QDataBlock_E_C_E_Opt", "Update", "$@11",
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
  "QuadPattern", "QuadData", "Quads", "$@12", "_QTriplesTemplate_E_Opt",
  "_QGT_DOT_E_Opt",
  "_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C_E_Star",
  "QuadsNotTriples", "@13", "@14", "$@15", "TriplesTemplate",
  "_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C_E_Opt", "GroupGraphPattern",
  "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C",
  "_O_QGT_LCURLEY_E_S_QSubSelect_E_Or_QGroupGraphPatternSub_E_S_QGT_RCURLEY_E_C",
  "$@16", "GroupGraphPatternSub", "_QTriplesBlock_E_Opt",
  "_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "Print", "OptionalGraphPattern", "@17", "GraphGraphPattern", "@18",
  "@19", "@20", "ServiceGraphPattern", "@21", "@22", "@23",
  "SADIinvocation", "@24", "@25", "@26", "Bind", "InlineData", "DataBlock",
  "InlineDataOneVar", "$@27", "$@28", "_QSingleValueRow_E_Star",
  "SingleValueRow", "InlineDataFull", "$@29", "_QVar_E_Star",
  "_O_QNIL_E_Or_QGT_LPAREN_E_S_QVar_E_Star_S_QGT_RPAREN_E_C",
  "_QDataBlockValue_E_Star",
  "_O_QGT_LPAREN_E_S_QDataBlockValue_E_Star_S_QGT_RPAREN_E_Or_QNIL_E_C",
  "$@30",
  "_Q_O_QGT_LPAREN_E_S_QDataBlockValue_E_Star_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star",
  "DataBlockValue", "MinusGraphPattern", "@31", "@32",
  "GroupOrUnionGraphPattern", "@33", "@34",
  "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@35",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "@36", "_QIT_DISTINCT_E_Opt",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ExpressionList", "@37",
  "TriplesSameSubject", "$@38", "$@39", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "PropertyListNotEmpty",
  "_O_QVerb_E_S_QObjectList_E_C", "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "Verb",
  "ObjectList", "_O_QGT_COMMA_E_S_QObject_E_C",
  "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star", "Object",
  "TriplesSameSubjectPath", "$@40", "$@41", "PropertyListPath",
  "_QPropertyListPathNotEmpty_E_Opt", "PropertyListPathNotEmpty", "$@42",
  "_O_QVerbPath_E_Or_QVerbSimple_E_C",
  "_O_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_C", "$@43",
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
  "BlankNodePropertyList", "@44", "Generator",
  "_O_QIT_MEMBERS_E_Or_QIT_STARTS_E_Or_QIT_ENDS_E_Or_QIT_ANY_E_Or_QIT_UNORDERED_E_C",
  "_Q_O_QIT_MEMBERS_E_Or_QIT_STARTS_E_Or_QIT_ENDS_E_Or_QIT_ANY_E_Or_QIT_UNORDERED_E_C_E_Opt",
  "_QGraphNode_E_Plus", "TriplesNodePath", "BlankNodePropertyListPath",
  "@45", "GeneratorPath", "_QGraphNodePath_E_Plus", "GraphNode",
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
  "SubstringExpression", "StrReplaceExpression", "ExistsFunc", "@46",
  "@47", "NotExistsFunc", "@48", "@49", "Aggregate",
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
     193,   288,    -1,   236,    -1,   252,    -1,   254,    -1,   258,
      -1,   291,    -1,   196,   197,   198,    -1,    -1,   232,    -1,
      -1,   197,   233,    -1,    -1,   198,   199,    -1,    -1,   202,
     200,   203,    -1,   163,    56,    -1,    -1,   201,    -1,   204,
      -1,   214,    -1,   224,    -1,   263,    -1,   206,   207,   205,
     213,    -1,   207,   205,    44,    -1,    -1,   205,   210,    -1,
     151,    -1,   104,   209,    -1,   212,    -1,   208,   212,    -1,
     104,    -1,   208,    -1,    -1,   104,   211,   209,    -1,   385,
     104,    -1,   151,    -1,   216,   217,   215,   223,    -1,   217,
     215,    44,    -1,    -1,   215,   220,    -1,   153,    -1,   155,
     219,    -1,   222,    -1,   218,   222,    -1,   155,    -1,   218,
      -1,    -1,   155,   221,   219,    -1,   385,   155,    -1,   154,
      -1,    37,   225,    38,    -1,    -1,   225,   226,    -1,    -1,
      41,   227,   230,    42,    -1,    -1,    49,    -1,   231,   228,
      -1,    -1,   230,   229,    -1,   385,   150,   385,    -1,   385,
     149,   385,    -1,   385,    56,   385,    -1,    15,   180,    -1,
      -1,    -1,    16,   234,   181,   235,   180,    -1,    -1,   237,
     243,   238,   264,   266,    -1,    -1,   238,   259,    -1,    -1,
      -1,    -1,   240,   241,   243,   242,   264,   266,   288,    -1,
      17,   245,   251,    -1,    18,    -1,    19,    -1,    -1,   244,
      -1,    91,   474,    -1,    -1,   246,    -1,    41,   476,   247,
      42,    -1,   499,    -1,   518,    -1,   522,    -1,   526,    -1,
     474,    -1,   511,    -1,   397,    -1,   248,    -1,   249,    -1,
     250,   249,    -1,   250,    -1,    20,    -1,    21,   253,    -1,
     327,   238,   264,   266,    -1,   238,    40,   327,   266,    -1,
      22,   256,   238,   257,   266,    -1,   473,    -1,   255,   473,
      -1,   255,    -1,    20,    -1,    -1,   264,    -1,    39,   238,
     264,   266,    -1,    23,   260,    -1,   261,    -1,   262,    -1,
     263,    -1,    24,   263,    -1,   528,    -1,   265,   342,    -1,
      -1,    40,    -1,   267,   268,   269,   270,    -1,    -1,   271,
      -1,    -1,   274,    -1,    -1,   277,    -1,    -1,   283,    -1,
      92,    26,   272,    -1,   273,    -1,   272,   273,    -1,   499,
      -1,   397,    -1,    41,   476,   247,    42,    -1,   474,    -1,
      93,   275,    -1,   276,    -1,   275,   276,    -1,   396,    -1,
      25,    26,   278,    -1,   279,    -1,   278,   279,    -1,   281,
      -1,   282,    -1,    27,    -1,    28,    -1,   280,   498,    -1,
     396,    -1,   474,    -1,   286,   284,    -1,   287,   285,    -1,
      -1,   287,    -1,    -1,   286,    -1,    29,   167,    -1,    30,
     167,    -1,   290,    -1,    31,   371,    -1,    -1,   289,    -1,
      -1,   195,   297,   292,   296,    -1,    50,   291,    -1,    -1,
     293,    -1,   297,   294,    -1,    -1,   295,    -1,   298,    -1,
     302,    -1,   303,    -1,   305,    -1,   306,    -1,   307,    -1,
     304,    -1,   308,    -1,   309,    -1,   310,    -1,   311,    -1,
       9,   299,   528,   301,    -1,    -1,    13,    -1,    10,   325,
      -1,    -1,   300,    -1,    11,   299,   326,    -1,    14,   299,
     326,    -1,    12,   299,   325,    -1,   116,   299,   323,   112,
     323,    -1,   130,   299,   323,   112,   323,    -1,   117,   299,
     323,   112,   323,    -1,   132,   328,    -1,   122,   328,    -1,
     120,   327,    -1,   313,   315,   316,   318,    40,   342,    -1,
     105,   528,    -1,    -1,   312,    -1,    -1,   320,    -1,   319,
     314,    -1,   320,    -1,    -1,   316,   321,    -1,    21,   327,
      -1,    -1,   317,    -1,     3,   327,    -1,     4,   327,    -1,
     108,   322,    -1,   528,    -1,    24,   528,    -1,   106,    -1,
     324,   528,    -1,    -1,     6,    -1,     6,   528,    -1,   325,
      -1,   106,    -1,    24,    -1,   107,    -1,    37,   329,    38,
      -1,    37,   329,    38,    -1,    -1,   330,   331,   334,    -1,
      -1,   339,    -1,    -1,    44,    -1,   335,   332,   331,    -1,
      -1,   334,   333,    -1,    -1,    -1,    -1,   336,     6,   473,
     337,    37,   338,   331,    38,    -1,   405,   341,    -1,    44,
     331,    -1,    -1,   340,    -1,   344,    -1,   163,    -1,   239,
      -1,   346,    -1,    -1,    37,   345,   343,    38,    -1,   347,
     349,    -1,    -1,   350,    -1,   353,   332,   347,    -1,    -1,
     349,   348,    -1,   420,   352,    -1,    44,   347,    -1,    -1,
     351,    -1,   389,    -1,   355,    -1,   386,    -1,   357,    -1,
     361,    -1,   365,    -1,   395,    -1,   369,    -1,   370,    -1,
     354,    -1,   148,   342,    -1,    -1,    45,   356,   342,    -1,
      -1,    -1,    -1,     6,   358,   359,   473,   360,   342,    -1,
      -1,    -1,    -1,     7,   362,   363,   364,   299,   473,   342,
      -1,    -1,    -1,    -1,     8,   366,   367,   368,   299,   473,
      23,   327,   264,    -1,   127,    41,   476,    91,   474,    42,
      -1,    31,   371,    -1,   372,    -1,   377,    -1,    -1,    -1,
     373,   474,   374,    37,   375,    38,    -1,    -1,   375,   376,
      -1,   385,    -1,    -1,   378,   380,    37,   384,    38,    -1,
      -1,   379,   474,    -1,   188,    -1,    41,   379,    42,    -1,
      -1,   381,   385,    -1,    -1,    41,   383,   381,    42,    -1,
     188,    -1,    -1,   384,   382,    -1,   528,    -1,   518,    -1,
     522,    -1,   526,    -1,    43,    -1,   164,    -1,   474,    -1,
      -1,    -1,    46,   387,   388,   342,    -1,    -1,    -1,   390,
     391,   342,   394,    -1,    -1,    47,   393,   342,    -1,    -1,
     394,   392,    -1,    48,   396,    -1,   498,    -1,   499,    -1,
     397,    -1,   528,   398,    -1,   188,    -1,    -1,    41,   400,
     476,   399,   402,    42,    -1,    -1,    18,    -1,    49,   476,
      -1,    -1,   402,   401,    -1,   188,    -1,    -1,    41,   476,
     404,   402,    42,    -1,    -1,   472,   406,   410,    -1,    -1,
     458,   407,   408,    -1,   409,    -1,    -1,   410,    -1,   415,
     416,   414,    -1,   415,   416,    -1,    -1,   411,    -1,    50,
     412,    -1,    -1,   414,   413,    -1,   473,    -1,    51,    -1,
     419,   418,    -1,    49,   419,    -1,    -1,   418,   417,    -1,
     470,    -1,    -1,   472,   421,   425,    -1,    -1,   465,   422,
     423,    -1,   424,    -1,    -1,   425,    -1,    -1,   427,   426,
     435,   432,    -1,   433,    -1,   434,    -1,    -1,   427,   429,
     416,    -1,    -1,   428,    -1,    50,   430,    -1,    -1,   432,
     431,    -1,   439,    -1,   474,    -1,   438,   437,    -1,    49,
     438,    -1,    -1,   437,   436,    -1,   471,    -1,   440,    -1,
     443,   442,    -1,   104,   443,    -1,    -1,   442,   441,    -1,
     448,   445,    -1,    64,   448,    -1,    -1,   445,   444,    -1,
     450,   447,    -1,    -1,   449,    -1,   446,    -1,   102,   446,
      -1,   103,    -1,    20,    -1,    62,    -1,   528,    -1,    51,
      -1,    65,   451,    -1,    41,   439,    42,    -1,   456,    -1,
      41,   455,    42,    -1,   104,   456,    -1,    -1,   453,   452,
      -1,   456,   453,    -1,    -1,   454,    -1,   528,    -1,    51,
      -1,   102,   457,    -1,   528,    -1,    51,    -1,   461,    -1,
     459,    -1,    -1,    52,   460,   410,    53,    -1,   463,    41,
     464,    42,    -1,    32,    -1,    33,    -1,    34,    -1,    35,
      -1,    36,    -1,    -1,   462,    -1,   470,    -1,   464,   470,
      -1,   468,    -1,   466,    -1,    -1,    52,   467,   425,    53,
      -1,   463,    41,   469,    42,    -1,   471,    -1,   469,   471,
      -1,   472,    -1,   458,    -1,   472,    -1,   465,    -1,   474,
      -1,   475,    -1,   474,    -1,   528,    -1,   185,    -1,   186,
      -1,   528,    -1,   518,    -1,   522,    -1,   526,    -1,   530,
      -1,   188,    -1,   477,    -1,   480,   479,    -1,    54,   480,
      -1,    -1,   479,   478,    -1,   483,   482,    -1,    55,   483,
      -1,    -1,   482,   481,    -1,   484,    -1,   487,   485,    -1,
      -1,   486,    -1,    56,   487,    -1,    57,   487,    -1,    58,
     487,    -1,    59,   487,    -1,    60,   487,    -1,    61,   487,
      -1,    67,   403,    -1,    66,    67,   403,    -1,   488,    -1,
     494,   493,    -1,   524,    -1,   525,    -1,    20,   496,    -1,
      64,   496,    -1,    -1,   490,    -1,    62,   494,    -1,    63,
     494,    -1,   489,   491,    -1,    -1,   493,   492,    -1,   496,
     495,    -1,    -1,   495,   490,    -1,    65,   497,    -1,    62,
     497,    -1,    63,   497,    -1,   497,    -1,   498,    -1,   499,
      -1,   516,    -1,   518,    -1,   522,    -1,   526,    -1,   474,
      -1,   511,    -1,    41,   476,    42,    -1,    78,    41,   476,
      42,    -1,    79,    41,   476,    42,    -1,    80,    41,   476,
      49,   476,    42,    -1,    81,    41,   476,    42,    -1,    82,
      41,   474,    42,    -1,    68,    41,   476,    42,    -1,    69,
      41,   476,    42,    -1,    70,   500,    -1,   118,   188,    -1,
     142,    41,   476,    42,    -1,   139,    41,   476,    42,    -1,
     131,    41,   476,    42,    -1,   125,    41,   476,    42,    -1,
      90,   403,    -1,   503,    -1,   145,    41,   476,    42,    -1,
     504,    -1,   143,    41,   476,    42,    -1,   141,    41,   476,
      42,    -1,   137,    41,   476,    42,    -1,   128,    41,   476,
      49,   476,    42,    -1,   138,    41,   476,    49,   476,    42,
      -1,   144,    41,   476,    49,   476,    42,    -1,   113,    41,
     476,    49,   476,    42,    -1,   114,    41,   476,    49,   476,
      42,    -1,   115,    41,   476,    42,    -1,   147,    41,   476,
      42,    -1,   140,    41,   476,    42,    -1,   136,    41,   476,
      42,    -1,   133,    41,   476,    42,    -1,   129,    41,   476,
      42,    -1,   124,    41,   476,    42,    -1,   123,    41,   476,
      42,    -1,   121,   188,    -1,   109,   188,    -1,   110,   188,
      -1,   111,    41,   476,    42,    -1,   146,    41,   476,    42,
      -1,   135,    41,   476,    42,    -1,   126,    41,   476,    42,
      -1,   119,    41,   476,    42,    -1,    71,   403,    -1,    72,
      41,   476,    49,   476,    49,   476,    42,    -1,    73,    41,
     476,    49,   476,    42,    -1,    74,    41,   476,    49,   476,
      42,    -1,    83,    41,   476,    49,   476,    42,    -1,    84,
      41,   476,    42,    -1,    85,    41,   476,    42,    -1,    86,
      41,   476,    42,    -1,    87,    41,   476,    42,    -1,   101,
      41,   476,    42,    -1,   501,    -1,   505,    -1,   508,    -1,
      41,   476,    42,    -1,   188,    -1,    88,    41,   476,    49,
     476,   502,    42,    -1,    -1,   401,    -1,   134,    41,   476,
      49,   476,   502,    42,    -1,    75,    41,   476,    49,   476,
      49,   476,   502,    42,    -1,    -1,    -1,    76,   506,   507,
     342,    -1,    -1,    -1,    66,    76,   509,   510,   342,    -1,
      94,    41,   400,   512,    42,    -1,   513,    41,   400,   476,
      42,    -1,    99,    41,   400,   476,   515,    42,    -1,    20,
      -1,   476,    -1,    95,    -1,    96,    -1,    97,    -1,    98,
      -1,   100,    -1,    50,    77,    56,   527,    -1,    -1,   514,
      -1,   528,   517,    -1,    -1,   398,    -1,   527,   521,    -1,
      89,   528,    -1,   187,    -1,   519,    -1,    -1,   520,    -1,
     523,    -1,   524,    -1,   525,    -1,   167,    -1,   168,    -1,
     169,    -1,   170,    -1,   171,    -1,   172,    -1,   173,    -1,
     174,    -1,   175,    -1,   165,    -1,   166,    -1,   176,    -1,
     178,    -1,   177,    -1,   179,    -1,   180,    -1,   529,    -1,
     182,    -1,   181,    -1,   183,    -1,   184,    -1
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
     171,   172,   178,   179,   185,   186,   189,   190,   191,   192,
     200,   204,   206,   208,   209,   211,   214,   215,   217,   222,
     224,   226,   228,   230,   232,   234,   236,   238,   240,   243,
     245,   247,   250,   255,   260,   266,   268,   271,   273,   275,
     276,   278,   283,   286,   288,   290,   292,   295,   297,   300,
     301,   303,   308,   309,   311,   312,   314,   315,   317,   318,
     320,   324,   326,   329,   331,   333,   338,   340,   343,   345,
     348,   350,   354,   356,   359,   361,   363,   365,   367,   370,
     372,   374,   377,   380,   381,   383,   384,   386,   389,   392,
     394,   397,   398,   400,   401,   406,   409,   410,   412,   415,
     416,   418,   420,   422,   424,   426,   428,   430,   432,   434,
     436,   438,   440,   445,   446,   448,   451,   452,   454,   458,
     462,   466,   472,   478,   484,   487,   490,   493,   500,   503,
     504,   506,   507,   509,   512,   514,   515,   518,   521,   522,
     524,   527,   530,   533,   535,   538,   540,   543,   544,   546,
     549,   551,   553,   555,   557,   561,   565,   566,   570,   571,
     573,   574,   576,   580,   581,   584,   585,   586,   587,   596,
     599,   602,   603,   605,   607,   609,   611,   613,   614,   619,
     622,   623,   625,   629,   630,   633,   636,   639,   640,   642,
     644,   646,   648,   650,   652,   654,   656,   658,   660,   662,
     665,   666,   670,   671,   672,   673,   680,   681,   682,   683,
     691,   692,   693,   694,   704,   711,   714,   716,   718,   719,
     720,   727,   728,   731,   733,   734,   740,   741,   744,   746,
     750,   751,   754,   755,   760,   762,   763,   766,   768,   770,
     772,   774,   776,   778,   780,   781,   782,   787,   788,   789,
     794,   795,   799,   800,   803,   806,   808,   810,   812,   815,
     817,   818,   825,   826,   828,   831,   832,   835,   837,   838,
     844,   845,   849,   850,   854,   856,   857,   859,   863,   866,
     867,   869,   872,   873,   876,   878,   880,   883,   886,   887,
     890,   892,   893,   897,   898,   902,   904,   905,   907,   908,
     913,   915,   917,   918,   922,   923,   925,   928,   929,   932,
     934,   936,   939,   942,   943,   946,   948,   950,   953,   956,
     957,   960,   963,   966,   967,   970,   973,   974,   976,   978,
     981,   983,   985,   987,   989,   991,   994,   998,  1000,  1004,
    1007,  1008,  1011,  1014,  1015,  1017,  1019,  1021,  1024,  1026,
    1028,  1030,  1032,  1033,  1038,  1043,  1045,  1047,  1049,  1051,
    1053,  1054,  1056,  1058,  1061,  1063,  1065,  1066,  1071,  1076,
    1078,  1081,  1083,  1085,  1087,  1089,  1091,  1093,  1095,  1097,
    1099,  1101,  1103,  1105,  1107,  1109,  1111,  1113,  1115,  1118,
    1121,  1122,  1125,  1128,  1131,  1132,  1135,  1137,  1140,  1141,
    1143,  1146,  1149,  1152,  1155,  1158,  1161,  1164,  1168,  1170,
    1173,  1175,  1177,  1180,  1183,  1184,  1186,  1189,  1192,  1195,
    1196,  1199,  1202,  1203,  1206,  1209,  1212,  1215,  1217,  1219,
    1221,  1223,  1225,  1227,  1229,  1231,  1233,  1237,  1242,  1247,
    1254,  1259,  1264,  1269,  1274,  1277,  1280,  1285,  1290,  1295,
    1300,  1303,  1305,  1310,  1312,  1317,  1322,  1327,  1334,  1341,
    1348,  1355,  1362,  1367,  1372,  1377,  1382,  1387,  1392,  1397,
    1402,  1405,  1408,  1411,  1416,  1421,  1426,  1431,  1436,  1439,
    1448,  1455,  1462,  1469,  1474,  1479,  1484,  1489,  1494,  1496,
    1498,  1500,  1504,  1506,  1514,  1515,  1517,  1525,  1535,  1536,
    1537,  1542,  1543,  1544,  1550,  1556,  1562,  1569,  1571,  1573,
    1575,  1577,  1579,  1581,  1583,  1588,  1589,  1591,  1594,  1595,
    1597,  1600,  1603,  1605,  1607,  1608,  1610,  1612,  1614,  1616,
    1618,  1620,  1622,  1624,  1626,  1628,  1630,  1632,  1634,  1636,
    1638,  1640,  1642,  1644,  1646,  1648,  1650,  1652,  1654,  1656
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
     728,   726,   738,   738,   750,   753,   761,   764,   767,   761,
     782,   790,   793,   800,   803,   808,   815,   818,   823,   830,
     833,   836,   839,   842,   845,   848,   852,   857,   860,   868,
     871,   877,   883,   888,   898,   906,   909,   917,   920,   927,
     930,   935,   943,   950,   951,   955,   961,   967,   974,   981,
     983,   988,   995,   998,  1003,  1006,  1011,  1014,  1019,  1023,
    1027,  1034,  1037,  1044,  1047,  1050,  1053,  1059,  1065,  1068,
    1075,  1080,  1087,  1091,  1099,  1101,  1109,  1112,  1120,  1128,
    1129,  1136,  1140,  1148,  1151,  1156,  1159,  1163,  1169,  1175,
    1179,  1185,  1188,  1192,  1192,  1202,  1205,  1207,  1211,  1214,
    1216,  1220,  1221,  1222,  1223,  1224,  1225,  1226,  1227,  1228,
    1229,  1230,  1234,  1240,  1243,  1250,  1257,  1260,  1264,  1270,
    1276,  1282,  1288,  1294,  1300,  1308,  1316,  1323,  1332,  1338,
    1341,  1345,  1348,  1352,  1356,  1362,  1364,  1370,  1376,  1379,
    1383,  1389,  1395,  1401,  1404,  1410,  1413,  1418,  1420,  1424,
    1430,  1433,  1436,  1439,  1446,  1453,  1459,  1459,  1467,  1469,
    1473,  1475,  1479,  1482,  1484,  1489,  1494,  1497,  1489,  1508,
    1512,  1515,  1517,  1521,  1522,  1535,  1536,  1541,  1541,  1552,
    1556,  1558,  1568,  1572,  1575,  1591,  1596,  1600,  1603,  1607,
    1608,  1609,  1610,  1611,  1612,  1613,  1614,  1615,  1618,  1622,
    1628,  1628,  1644,  1648,  1650,  1644,  1661,  1665,  1667,  1661,
    1678,  1682,  1684,  1678,  1703,  1714,  1720,  1721,  1725,  1727,
    1725,  1734,  1736,  1740,  1748,  1748,  1755,  1757,  1763,  1764,
    1767,  1769,  1775,  1775,  1780,  1786,  1788,  1792,  1795,  1798,
    1801,  1804,  1807,  1810,  1816,  1820,  1816,  1830,  1834,  1830,
    1844,  1844,  1856,  1858,  1862,  1872,  1873,  1874,  1878,  1886,
    1890,  1890,  1900,  1903,  1910,  1916,  1918,  1932,  1935,  1935,
    1945,  1945,  1948,  1948,  1954,  1957,  1959,  1964,  1969,  1973,
    1975,  1980,  1984,  1986,  1990,  1994,  2002,  2007,  2011,  2013,
    2017,  2025,  2025,  2028,  2028,  2034,  2037,  2039,  2043,  2043,
    2049,  2050,  2054,  2054,  2059,  2061,  2065,  2068,  2070,  2074,
    2078,  2084,  2088,  2091,  2093,  2097,  2104,  2108,  2112,  2115,
    2117,  2121,  2125,  2130,  2132,  2138,  2141,  2143,  2149,  2150,
    2156,  2157,  2158,  2162,  2165,  2168,  2171,  2177,  2178,  2182,
    2185,  2187,  2191,  2194,  2196,  2200,  2201,  2202,  2206,  2207,
    2213,  2214,  2218,  2218,  2231,  2259,  2262,  2265,  2268,  2271,
    2278,  2281,  2286,  2290,  2297,  2298,  2302,  2302,  2314,  2341,
    2345,  2352,  2353,  2357,  2358,  2362,  2365,  2369,  2372,  2378,
    2379,  2383,  2386,  2389,  2392,  2395,  2396,  2402,  2407,  2416,
    2423,  2426,  2434,  2443,  2450,  2453,  2460,  2465,  2478,  2482,
    2486,  2490,  2494,  2498,  2502,  2506,  2510,  2514,  2521,  2526,
    2535,  2538,  2545,  2548,  2555,  2558,  2563,  2566,  2570,  2584,
    2587,  2595,  2604,  2607,  2614,  2617,  2620,  2623,  2627,  2628,
    2629,  2630,  2633,  2636,  2639,  2642,  2646,  2652,  2655,  2658,
    2661,  2664,  2667,  2670,  2674,  2677,  2680,  2683,  2686,  2689,
    2692,  2695,  2696,  2699,  2700,  2703,  2706,  2709,  2712,  2715,
    2718,  2721,  2724,  2727,  2730,  2733,  2736,  2739,  2742,  2745,
    2748,  2751,  2754,  2757,  2760,  2763,  2766,  2769,  2772,  2775,
    2778,  2781,  2784,  2787,  2790,  2793,  2796,  2799,  2802,  2803,
    2804,  2810,  2813,  2820,  2827,  2830,  2834,  2840,  2846,  2849,
    2846,  2861,  2864,  2861,  2877,  2881,  2886,  2895,  2898,  2902,
    2905,  2908,  2911,  2914,  2920,  2926,  2929,  2933,  2943,  2946,
    2951,  2959,  2966,  2970,  2978,  2982,  2986,  2987,  2988,  2992,
    2993,  2994,  2998,  2999,  3000,  3004,  3005,  3006,  3010,  3011,
    3015,  3016,  3017,  3018,  3022,  3023,  3027,  3028,  3032,  3033
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
  const int SPARQLfedParser::yylast_ = 2676;
  const int SPARQLfedParser::yynnts_ = 342;
  const int SPARQLfedParser::yyempty_ = -2;
  const int SPARQLfedParser::yyfinal_ = 11;
  const int SPARQLfedParser::yyterror_ = 1;
  const int SPARQLfedParser::yyerrcode_ = 256;
  const int SPARQLfedParser::yyntokens_ = 189;

  const unsigned int SPARQLfedParser::yyuser_token_number_max_ = 443;
  const SPARQLfedParser::token_number_type SPARQLfedParser::yyundef_token_ = 2;


} // w3c_sw

/* Line 1136 of lalr1.cc  */
#line 5968 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 3039 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


