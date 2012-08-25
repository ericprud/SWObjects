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
#line 312 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"

/* Line 299 of lalr1.cc  */
#line 464 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

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
#line 478 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 481 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 492 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	assert(driver.lastWhereClause != NULL);
	if ((yysemantic_stack_[(3) - (3)].p_BindingClause) != NULL) // got a bindings clause
	    driver.lastWhereClause->m_GroupGraphPattern = 
		driver.makeConjunction((yysemantic_stack_[(3) - (3)].p_BindingClause), driver.lastWhereClause->m_GroupGraphPattern);
	(yyval.p_Operation) = (yysemantic_stack_[(3) - (2)].p_Operation);
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 511 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 544 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.startBindingSet();
      }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 547 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 22:

/* Line 690 of lalr1.cc  */
#line 562 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = (yysemantic_stack_[(2) - (1)].p_RSName);
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 568 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = NULL;
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 578 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	throw std::runtime_error("need to partition out results set part of SimpleEngine::loadDataOrResults");
    }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 612 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 614 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 620 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 658 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 660 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 666 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 685 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow(false);
      }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 687 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 707 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 710 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 713 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 719 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 725 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 727 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 729 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 737 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 740 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause);
	(yyval.p_Operation) = new Select((yysemantic_stack_[(5) - (2)].p_Project).distinctness, (yysemantic_stack_[(5) - (2)].p_Project).varSet, (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
	driver.countStar = (yysemantic_stack_[(5) - (1)].p_parentCountStar);
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 749 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 752 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 760 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 763 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 766 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 770 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if ((yysemantic_stack_[(7) - (7)].p_BindingClause) != NULL)
	      (yysemantic_stack_[(7) - (5)].p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yysemantic_stack_[(7) - (7)].p_BindingClause), (yysemantic_stack_[(7) - (5)].p_WhereClause)->m_GroupGraphPattern);
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (4)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(7) - (3)].p_Project).distinctness, (yysemantic_stack_[(7) - (3)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(7) - (5)].p_WhereClause), (yysemantic_stack_[(7) - (6)].p_SolutionModifier))));
	  driver.curGraphName = (yysemantic_stack_[(7) - (2)].p_TTerm);
	  driver.countStar = (yysemantic_stack_[(7) - (1)].p_parentCountStar);
      }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 781 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 789 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 792 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 799 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 807 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 814 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 822 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 829 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 832 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 835 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 838 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 841 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 844 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 847 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 856 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 859 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 867 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 870 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 877 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = NULL;
      }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 879 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.lastWhereClause = (yysemantic_stack_[(6) - (5)].p_WhereClause);
	  /* $2 is NO LONGER known to be a DefaultGraphPattern because of grammar restrictions. */
	  (yyval.p_Operation) = new Construct((yysemantic_stack_[(6) - (2)].p_TableOperation), (yysemantic_stack_[(6) - (4)].p_DatasetClauses), (yysemantic_stack_[(6) - (5)].p_WhereClause), (yysemantic_stack_[(6) - (6)].p_SolutionModifier));
      }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 888 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause) ? (yysemantic_stack_[(5) - (4)].p_WhereClause) : new WhereClause(new DefaultGraphPattern());
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 896 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm))));
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 899 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_TTerm))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 907 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 910 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 917 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 925 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(3) - (3)].p_WhereClause);
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(3) - (2)].p_DatasetClauses), (yysemantic_stack_[(3) - (3)].p_WhereClause));
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 933 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 945 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 951 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 957 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 964 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.ensureGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 978 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 985 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 993 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1001 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1009 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1017 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1024 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1027 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1034 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1037 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1040 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1043 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1049 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1055 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1058 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1070 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1077 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1081 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1091 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1099 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1102 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1110 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1119 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1126 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1130 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1138 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1146 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1153 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1159 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1166 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1168 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1176 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1182 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1185 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1191 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow(); // @@ push down to _Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star?
      }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1193 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1196 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1208 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1211 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1214 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1217 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1220 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1223 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 1226 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1232 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	OperationSet* ret = driver.root ? dynamic_cast<OperationSet*>(driver.root) : new OperationSet();
	ret->push_back((yysemantic_stack_[(2) - (2)].p_Operation));
	driver.root = ret;
      }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 1236 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Operation) = driver.root;
	}
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1270 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(3) - (2)].p_URI), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1277 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1284 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1291 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1297 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1300 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1306 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1312 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1318 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1324 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1330 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1336 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1344 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1352 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1359 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(5) - (1)].p_URI))
	    w3c_sw_NEED_IMPL("WITH <URI> (DELETE INSERT?|INSERT) ...");
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(5) - (2)].p_DeleteInsert).del, (yysemantic_stack_[(5) - (2)].p_DeleteInsert).ins, new WhereClause(driver.ensureGraphPattern()));
	driver.curOp = NULL;
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 1368 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1374 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 1381 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 1388 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 1392 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1400 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("_QUsingClause_E_Star");
    }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 1406 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Delete) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1412 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = new Insert((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 1418 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 1424 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 1427 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 1433 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 1436 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 1447 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 1453 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 1456 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("DEFAULT");
      }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 1459 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("NAMED");
      }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 1462 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("ALL");
      }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 1469 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
    }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 1475 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 1481 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 1483 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TableOperation) = driver.ensureGraphPattern();
	  driver.curOp = NULL;
      }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 1511 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 1516 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 1519 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 1522 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 1544 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 258:

/* Line 690 of lalr1.cc  */
#line 1563 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 1565 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 1636 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_BindingClause)) : (yysemantic_stack_[(1) - (1)].p_BindingClause);
    }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 1643 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Print(driver.curOp);
    }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 1649 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 1653 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 282:

/* Line 690 of lalr1.cc  */
#line 1665 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 1669 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 1671 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 1674 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 1682 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 1686 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 1688 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 1691 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(7) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(7) - (6)].p_TTerm), driver.curOp, (yysemantic_stack_[(7) - (5)].p_Silence), driver.atomFactory, false));
	  driver.curGraphName = (yysemantic_stack_[(7) - (4)].p_TTerm);
      }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 1699 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Bind(driver.ensureGraphPattern(), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
	// no more triples go into the current BGP, per
	//   http://www.w3.org/TR/sparql11-query/#sparqlTranslateGraphPatterns
	// test reference:
	//   http://www.sparql.org/query-validator?query=ASK+{+%3Fs+%3Fp+%3Fo+FILTER+%281%29+BIND+%282+AS+%3Fb%29+%3Fs2+%3Fp2+%3Fo2+FILTER+%283%29+BIND+%284+AS+%3Fd%29}&languageSyntax=SPARQL&outputFormat=algebra&linenumbers=false
	driver.curBGP = NULL;
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 1710 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 1714 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 1716 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 1724 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 1728 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 1730 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 1738 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 1743 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.ensureGraphPattern());
      }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 1756 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    driver.ensureGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 1772 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 1780 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 1784 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 1787 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yysemantic_stack_[(6) - (4)].p_Expressions);
      }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 1794 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 1797 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 1804 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 1812 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 1826 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 1829 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 1832 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(5) - (3)].p_Expressions);
      }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 1839 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 1842 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 1886 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 1890 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 1913 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 1921 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 1924 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 1930 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 1941 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 1969 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 1996 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 2003 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 2014 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 2021 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 2057 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 2060 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 2063 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 2066 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 2124 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 2128 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 2137 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 407:

/* Line 690 of lalr1.cc  */
#line 2164 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 2167 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 2170 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 2173 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 2176 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 2183 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 2191 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 2195 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 2207 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 2214 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 2217 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 2228 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 2231 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 2234 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 2237 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 2241 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 2252 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 2261 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 2268 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 2271 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 2279 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 2288 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 2295 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 2298 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 2310 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 441:

/* Line 690 of lalr1.cc  */
#line 2323 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = NULL;
    }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 2331 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 2335 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 2339 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 2343 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 2347 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 2351 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 2355 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 2359 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = true;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 2371 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 2380 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 2383 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 2390 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 2393 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 2400 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 2408 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 2411 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 2415 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 462:

/* Line 690 of lalr1.cc  */
#line 2429 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 2432 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 2440 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 2449 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 2452 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 2459 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 2462 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 2465 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 2475 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 2478 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 2481 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 2484 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 2491 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 2497 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 2500 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 2503 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 2506 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 2509 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 2512 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 2515 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 2519 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 2522 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 2525 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 2528 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ceil, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 2531 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 2534 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 2537 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 2541 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 2544 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 2547 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 2550 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 2553 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 2556 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 2559 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 2562 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 2565 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 2568 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 2571 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 2574 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 2577 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 2580 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 2583 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 2586 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 2589 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 2592 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 2595 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_uuid, NULL, NULL, NULL));
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 2598 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_struuid, NULL, NULL, NULL));
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 2601 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 2604 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 2607 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 2610 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 2613 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 2616 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 2619 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 2622 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 2625 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 2628 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 2631 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 2634 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 2637 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 2640 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 2643 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 2654 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 2657 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 2664 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 2671 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 2678 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 2684 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 2687 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 2690 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 2694 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expression) = new ExistsExpression(driver.ensureGraphPattern());
	  driver.curOp = (yysemantic_stack_[(5) - (4)].p_TableOperation);
	  driver.curGraphName = (yysemantic_stack_[(5) - (3)].p_TTerm);
	  driver.countStar = (yysemantic_stack_[(5) - (2)].p_parentCountStar);
      }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 2703 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 2706 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 2709 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 2713 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  // $$ = new ExistsExpression(false, driver.ensureGraphPattern());
	  (yyval.p_Expression) = new BooleanNegation(new ExistsExpression(driver.ensureGraphPattern()));
	  driver.curOp = (yysemantic_stack_[(6) - (5)].p_TableOperation);
	  driver.curGraphName = (yysemantic_stack_[(6) - (4)].p_TTerm);
	  driver.countStar = (yysemantic_stack_[(6) - (3)].p_parentCountStar);
      }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 2723 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 2727 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 2732 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  AggregateCall::ScalarVals svals;
	  if ((yysemantic_stack_[(6) - (5)].p_RDFLiteral) != NULL)
	      svals["separator"] = (yysemantic_stack_[(6) - (5)].p_RDFLiteral)->getLexicalValue();
	  (yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression), svals));
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 2741 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 2748 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 2751 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 2754 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 2757 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 2760 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 2766 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 2772 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 2779 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 2789 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 2797 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 2805 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 2812 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 2816 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 2824 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 690 of lalr1.cc  */
#line 3766 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -827;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        55,   -94,   107,  -827,  -827,  -827,   398,  -827,  -827,  -827,
    -827,  -827,    77,   101,   101,   101,    83,     0,  -827,    77,
     101,   101,    83,    92,   101,    92,    87,  -827,   127,  -827,
    -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,
    -827,  -827,  -827,  -827,  -827,   132,   140,  -827,  -827,  -827,
     194,  -827,  -827,    44,   169,    44,  -827,  -827,  -827,  -827,
    -827,   166,  -827,  -827,  -827,  -827,    29,  -827,    42,    42,
    -827,  -827,  -827,    42,  -827,  -827,  -827,  -827,   135,  -827,
     160,    83,    83,  -827,   210,  -827,  -827,    43,  -827,   169,
    -827,  -827,    77,  -827,  -827,  -827,  -827,  -827,  -827,  -827,
     190,  1057,  -827,  -827,     3,     7,  -827,  -827,  -827,    -7,
    -827,  -827,   121,    77,   128,   211,   158,  -827,  -827,  -827,
    -827,  1562,    29,    64,  -827,  -827,  -827,  -827,     4,  -827,
    -827,    91,   220,  -827,  -827,  -827,  -827,  -827,  -827,  -827,
    -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,
    -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,
    -827,  -827,  -827,  -827,  -827,   233,  -827,  -827,  -827,  -827,
     240,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,
     -47,  -827,  -827,    29,   192,  -827,    77,  -827,  -827,  -827,
    -827,  -827,  -827,  -827,  -827,  -827,    42,  -827,    42,  -827,
      42,   -14,  -827,  1731,   221,   243,   257,    -9,    -4,   261,
     263,   269,  -827,   271,   273,   280,   281,   292,   293,   297,
     307,   311,   312,   314,    -4,   315,  -827,  -827,  -827,  -827,
     317,  -827,   321,   110,   176,   323,   324,   325,   326,   181,
     328,   183,   332,   333,   335,   337,   338,   340,   341,   342,
     343,   345,   347,   348,   349,   350,   352,   355,   356,   357,
     359,   360,   362,   363,  -827,  -827,  1851,  -827,  -827,  -827,
    -827,  -827,  -827,  -827,  -827,  -827,   364,  -827,  -827,  -827,
       5,   192,   256,  -827,  -827,    -7,    10,  -827,  -827,  -827,
      93,   -22,   399,  1057,  -827,  -827,   -22,  1586,   -22,    77,
    -827,  -827,  -827,  -827,   192,   382,  -827,   319,  -827,  -827,
    1033,  -827,  -827,  -827,  -827,  -827,  1731,  1971,  1971,  1971,
    -827,   327,  -827,  -827,  -827,  -827,   234,  -827,  -827,  -827,
    -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,     5,  -827,
    1731,  1731,  1731,  -827,  -827,  1731,  -827,  -827,  1731,  1731,
    1731,  -827,  1731,  1731,  1731,  1731,    36,  1731,  1731,  1731,
    1731,  1731,  1731,  -827,   395,   395,  1731,  -827,  -827,  1731,
    1731,  1731,  1731,  -827,  1731,  -827,  1731,  1731,  1731,  1731,
    1731,  1731,  1731,  1731,  1731,  1731,  1731,  1731,  1731,  1731,
    1731,  1731,  1731,  1731,  1731,  1731,  1731,  1731,  -827,   395,
     395,  -827,  -827,  -827,  -827,    77,  -827,  -827,   237,  -827,
    2163,  -827,  -827,  2115,  -827,  -827,   318,  -827,  -827,   264,
    -827,  -827,  -827,  -827,   369,  1586,  -827,  -827,   379,   418,
    -827,  -827,  -827,  -827,  -827,  1081,  -827,  -827,  -827,  -827,
    -827,  2091,  2315,   401,  -827,  -827,  -827,   389,  -827,  -827,
    -827,   384,  -827,  -827,   -13,   387,  -827,  -827,  -827,    36,
    -827,   391,   380,   383,  1731,  1731,  1731,  1731,  1731,  1731,
     368,    -4,  -827,  -827,   146,    52,  -827,  -827,  -827,   397,
     400,   402,  -827,   392,   394,   396,  -827,   404,   405,   406,
     408,   409,   407,   411,   416,   417,   420,   422,  -827,  1392,
    1731,   425,   427,   424,   426,   435,   436,   439,   442,   443,
     444,   438,   447,   448,   449,   445,   450,   451,   454,   452,
     455,   458,   462,   463,   464,   459,   467,   468,   469,  1731,
    1731,  -827,  -827,   100,  -827,  -827,  -827,  2195,  -827,  -827,
     412,  -827,  -827,  -827,  -827,  -827,  -827,  2195,  -827,  -827,
     286,  -827,     1,  -827,    63,  -827,  -827,  -827,  -827,  -827,
    1057,   166,  -827,  -827,  1731,  2091,  -827,  -827,  -827,  -827,
    2315,  -827,  -827,  -827,  -827,  -827,   490,   207,  -827,   127,
    -827,    51,  1057,  -827,  -827,   -22,    22,  -827,  -827,  -827,
    -827,  -827,  -827,  -827,  1731,  -827,  1731,  -827,  -827,  -827,
    -827,  -827,  -827,  -827,    -4,  -827,  1731,  1731,    52,  -827,
    -827,  -827,  1731,  1731,  -827,  -827,  -827,  -827,  -827,  -827,
    1731,  1731,  1731,    -7,  -827,  -827,  1731,  -827,  -827,  1731,
    -827,  -827,  -827,  -827,  1731,  -827,  -827,   476,   471,  -827,
    -827,  1731,  1731,  -827,  -827,  -827,  -827,  -827,  -827,  1731,
    -827,  -827,  -827,  1731,  -827,  -827,  -827,  1731,  -827,  -827,
    -827,  -827,  -827,  1731,  -827,  -827,  -827,   483,  -827,  -827,
    -827,  -827,  -827,  -827,  -827,  -827,   -41,  -827,  -827,  -827,
      88,  -827,  -827,  -827,   478,   481,  -827,  -827,   327,  -827,
    -827,  1262,   282,   366,  -827,  -827,   503,   505,  -827,  -827,
    -827,  -827,  -827,  2315,   494,    -7,  -827,  -827,   379,  -827,
    -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,
    -827,    33,  -827,    50,    54,  -827,  -827,  -827,  -827,  -827,
    -827,  -827,  -827,  -827,    41,  -827,  -827,  -827,  2195,  -827,
    -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,    -7,    15,
     489,   497,   498,  -827,   499,   500,   495,  -827,   470,  -827,
     501,   506,   509,   510,   495,   511,   513,  -827,  -827,  -827,
    -827,  -827,  2163,  -827,  -827,  2115,   -22,  -827,  1586,  -827,
     508,   514,  -827,  -827,  1262,  -827,   516,  -827,  -827,  -827,
    -827,  -827,  -827,  -827,  -827,  -827,  -827,   518,  -827,  -827,
      -7,  -827,  -827,  1731,  -827,  1057,    -7,   519,    81,  -827,
      71,  -827,  -827,  -827,  -827,  -827,  -827,  1586,   457,   502,
    -827,    34,  -827,  -827,  -827,  -827,  -827,  2076,  -827,  -827,
    -827,  1731,  -827,  1731,  -827,  -827,  -827,  -827,  -827,   520,
     507,  -827,  -827,  -827,  -827,   522,  -827,  -827,    18,  2139,
    -827,  -827,  -827,  -827,  1586,  -827,  -827,  -827,  -827,  -827,
     192,   166,  -827,  -827,    -7,   475,  -827,  -827,  -827,  -827,
     525,  -827,  -827,  -827,  -827,  -827,    33,  -827,    33,  -827,
     403,  -827,  -827,    28,  -827,  -827,  -827,   526,  -827,   131,
    -827,  -827,  -827,  -827,   521,    70,  -827,  1057,    87,  -827,
     101,  -827,    36,   530,  -827,   477,   523,  -827,  -827,   534,
    -827,    -5,  -827,  -827,  -827,  -827,  -827,  2195,  2195,  2195,
     540,  -827,    -7,   166,   537,  -827,  -827,    81,  -827,    22,
    -827,  -827,  -827,  -827,   543,  -827,  -827,  -827,  -827,  -827,
      -7,  -827,    -7,  -827,  -827,  -827,  -827,  -827,  -827,  -827,
    1586,  -827
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        14,     0,     0,     2,     4,     3,   213,    16,    15,    12,
      70,     1,     0,   201,   201,   201,     0,     0,    76,     0,
     201,   201,     0,     0,   201,     0,    10,     6,     0,     7,
       8,     9,   178,   185,   186,   187,   191,   188,   189,   190,
     192,   193,   194,   195,   214,     0,    18,   587,   590,   589,
     198,   588,   202,     0,     0,     0,   237,   103,   109,   422,
     423,   108,    76,   106,   420,   421,   120,   212,   228,   228,
     210,   237,   209,   228,   208,   160,     5,    11,    85,    76,
     183,     0,     0,   219,   215,   218,    71,    13,    17,     0,
     199,   196,     0,   233,   232,   234,   231,   200,   204,   203,
       0,   239,    76,   107,   110,     0,   121,    77,   112,     0,
     229,   226,     0,     0,     0,     0,     0,   162,    83,    84,
      86,     0,   120,    14,   184,   179,   221,   222,     0,   217,
     216,     0,     0,    19,    24,    20,   197,   230,   235,   407,
     408,   409,   410,   411,   404,   581,   582,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   583,   585,   584,   586,
     591,   592,   429,   244,   240,   252,   319,   403,   402,   413,
       0,   317,   418,   419,   425,   426,   569,   570,   571,   427,
     567,   424,   428,   120,   123,   111,     0,   113,   114,   115,
     116,   118,   258,   255,   119,   254,   228,   227,   228,   236,
     228,     0,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   539,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   552,   553,   554,   555,
       0,   556,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    98,    99,   101,    82,    94,    91,
      93,   530,   494,   531,   532,    92,     0,    95,    96,    97,
       0,   123,   213,   181,   182,     0,     0,   220,    72,    22,
       0,     0,   238,   239,   253,   250,   329,   412,     0,     0,
     565,   566,   568,   563,   123,     0,   105,   125,   124,   117,
     261,   205,   207,   206,   169,   163,     0,     0,     0,     0,
     477,    88,   430,   433,   437,   439,   441,   451,   462,   465,
     470,   471,   472,   478,   473,   474,   475,   476,   561,   543,
       0,     0,     0,   534,   487,     0,   314,   520,     0,     0,
       0,   540,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   493,   309,   309,     0,   513,   514,     0,
       0,     0,     0,   488,     0,   512,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   100,   309,
     309,   306,   305,    75,   211,     0,   223,   224,     0,    58,
       0,    33,    47,     0,    21,    25,     0,    31,    26,     0,
      45,    27,    28,   332,     0,   412,   331,   245,   241,     0,
     251,   330,   320,   328,   417,   412,   414,   416,   318,   564,
     104,     0,     0,   127,   126,   256,    79,     0,   257,   264,
     262,   268,   340,   338,     0,     0,   468,   469,   467,     0,
      89,     0,   431,   435,     0,     0,     0,     0,     0,     0,
       0,     0,   440,   442,   452,   464,   562,   560,   544,     0,
       0,     0,   315,     0,     0,     0,   541,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   310,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   225,    73,     0,   175,    37,   176,    38,    34,    35,
       0,   177,   172,   173,   174,   171,    51,    52,    48,    49,
       0,    31,     0,    45,     0,   405,   326,   335,   337,   242,
     239,     0,   406,   415,     0,   131,   132,   135,   137,   134,
     138,   139,   141,   304,   302,   303,     0,   129,   128,     0,
     259,   294,   261,   269,   266,   329,     0,   161,   166,   168,
     170,   479,    87,    90,     0,   434,     0,   438,   443,   444,
     445,   446,   447,   448,     0,   449,     0,     0,   457,   463,
     453,   454,     0,     0,   466,   545,   485,   486,   533,   312,
       0,     0,     0,     0,   480,   481,     0,   483,   484,     0,
     525,   526,   527,   528,     0,   550,   551,     0,   558,   529,
     515,     0,     0,   504,   519,   511,   510,   492,   518,     0,
     509,   491,   508,     0,   517,   507,   498,     0,   490,   506,
     497,   489,   496,     0,   495,   516,   505,     0,   307,    57,
      60,    59,    36,    41,    50,    55,     0,    30,    39,    32,
       0,    44,    53,    46,   321,   333,   243,   247,    88,   133,
     140,     0,     0,     0,   122,   130,   154,   156,    80,   282,
     286,   280,   291,     0,     0,     0,   277,   265,   241,   278,
     271,   273,   274,   276,   272,   270,   295,   275,   267,   353,
     341,     0,   383,     0,     0,   339,   342,   344,   345,   354,
     356,   359,   368,   363,   366,   381,   355,   382,     0,   432,
     436,   450,   459,   460,   458,   461,   455,   456,     0,     0,
       0,     0,     0,   542,     0,     0,   536,   547,     0,   559,
       0,     0,     0,     0,   536,     0,     0,   548,   312,    65,
      42,    29,     0,    56,    43,     0,   323,   327,   412,   336,
       0,     0,   147,   148,   142,   143,     0,   145,   146,   150,
     151,   158,   159,   152,   155,   153,   157,   120,   283,   287,
       0,   292,   301,     0,   279,   261,     0,     0,   391,   399,
       0,   384,   386,   393,   395,   398,   369,   412,   357,   361,
     377,     0,   379,   378,   365,   367,   370,     0,   164,   546,
     316,     0,   313,     0,   522,   523,   482,   524,   537,     0,
       0,   549,   502,   503,   499,     0,   500,   501,     0,     0,
      40,    54,   324,   325,   412,   334,   248,   136,   144,   149,
     123,     0,   288,   281,     0,     0,   263,   299,   385,   392,
       0,   388,   397,   400,   396,   351,     0,   360,     0,   364,
       0,   401,   380,     0,   167,   165,   311,     0,   535,     0,
     538,   308,    61,    66,    62,     0,   322,   239,    10,   284,
     201,   293,     0,   296,   394,   390,   343,   358,   362,     0,
     374,     0,   375,   521,   557,    63,    64,     0,     0,     0,
       0,    81,     0,     0,     0,   297,   300,     0,   389,   348,
     352,   376,   371,   373,     0,    69,    68,    67,   249,   285,
       0,   290,     0,   387,   346,   349,   350,   372,   289,   298,
     412,   347
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -827,  -827,  -827,  -827,  -827,  -317,  -827,   461,  -827,  -827,
    -827,  -827,  -827,  -827,  -827,  -827,  -827,    31,  -827,   170,
    -827,  -185,  -827,  -827,    58,  -827,  -827,    35,  -827,   173,
    -827,  -186,  -827,  -827,    49,  -827,  -827,  -827,  -827,  -827,
    -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,
      12,  -827,  -827,  -827,  -827,    21,  -827,  -827,  -827,   -91,
    -827,   339,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,
    -827,  -827,  -827,  -827,  -827,  -149,   -96,  -827,  -269,  -827,
    -827,  -827,  -827,  -827,  -827,    39,  -827,  -827,    37,  -827,
    -827,  -183,  -827,  -827,  -827,  -827,  -827,  -827,   -89,   -87,
      32,  -827,  -827,  -827,  -827,  -827,  -827,  -396,   487,  -827,
    -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,   -11,  -827,
    -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,
    -827,  -827,  -827,  -827,   528,  -827,  -827,    47,  -827,    16,
     560,    30,   591,   546,  -827,  -272,   -90,  -827,  -827,  -827,
    -827,  -827,  -827,  -827,  -827,  -827,  -270,  -827,  -827,  -827,
    -827,  -568,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,
    -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,
    -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,
    -650,  -103,   283,  -827,  -273,  -632,  -139,  -213,  -827,  -827,
    -827,  -827,  -168,  -827,  -827,  -827,  -827,  -827,    45,  -145,
    -779,  -827,  -827,  -151,  -827,  -827,  -827,  -827,  -827,  -297,
    -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,   -88,  -827,
    -827,  -827,  -241,  -827,  -827,   -86,  -827,  -239,  -827,  -827,
    -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,  -827,
    -827,  -761,  -827,  -827,  -826,  -100,  -827,  -827,  -827,  -827,
    -827,  -827,  -263,   -95,   -15,    38,  -827,   795,  -827,  -827,
    -827,    48,  -827,  -827,    53,  -827,  -827,  -827,  -141,  -827,
    -827,    40,  -827,  -827,  -827,  -354,  -827,  -350,   -93,  -426,
    -101,  -827,  -827,  -127,  -827,  -827,  -827,  -827,  -827,  -827,
    -827,  -827,  -827,   -98,  -827,  -827,  -827,  -827,  -827,  -827,
      46,  -827,  -827,  -827,   201,  -827,   167,   171,   209,  -249,
     -12,  -827,  -827
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,    26,    76,     5,     6,     7,    46,
      87,   133,   290,   134,   135,   414,   415,   552,   416,   417,
     537,   538,   679,   772,   539,   771,   418,   554,   419,   420,
     547,   548,   683,   775,   549,   774,   421,   533,   671,   769,
     916,   893,   849,   894,     8,    88,   131,   408,    27,    28,
      66,   445,   446,   579,   797,    79,   120,   121,   460,   461,
     264,   265,   266,   267,    29,   102,    30,    61,    62,   184,
      31,   107,   187,   188,   189,   190,   108,   109,   306,   307,
     443,   577,   694,   308,   565,   566,   444,   570,   571,   578,
     784,   785,   786,   787,   788,   695,   793,   795,   696,   697,
      77,   117,   201,   827,   590,   738,   454,   540,     9,    80,
     284,   124,   125,    32,    33,    90,    91,    34,    53,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
     129,    83,   128,    84,    85,   287,   406,   112,   113,    96,
      97,    57,    72,   100,   101,   163,   560,   427,   292,   428,
     429,   780,   897,   164,   294,   295,   194,   447,   195,   310,
     448,   449,   707,   581,   450,   583,   584,   708,   709,   710,
     800,   711,   798,   861,   922,   712,   799,   862,   900,   713,
     714,   801,   864,   715,   716,   806,   926,   942,   903,   717,
     572,   573,   402,   768,   499,   832,   749,   347,   619,   165,
     298,   296,   431,   852,   853,   777,   684,   432,   433,   425,
     556,   779,   685,   557,   451,   586,   585,   725,   817,   726,
     945,   950,   946,   930,   906,   720,   727,   728,   729,   730,
     877,   818,   731,   879,   819,   732,   824,   733,   825,   933,
     912,   882,   826,   734,   735,   811,   928,   905,   869,   870,
     812,   813,   873,   814,   883,   434,   167,   291,   168,   169,
     170,   435,   558,   437,   426,   320,   173,   321,   322,   595,
     462,   323,   597,   463,   324,   325,   472,   473,   326,   327,
     608,   614,   745,   609,   474,   328,   475,   329,   330,   331,
     332,   344,   271,   839,   272,   273,   351,   486,   623,   274,
     478,   615,   748,   333,   637,   276,   759,   760,   334,   477,
     335,   301,   302,   303,   336,   176,   177,   178,   337,   180,
     338,    51,   182
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int SPARQLfedParser::yytable_ninf_ = -413;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        50,   166,    63,    54,    55,    65,   171,    67,   185,    68,
      69,   363,   403,    73,   718,   404,   574,   550,   268,    58,
     270,   430,   314,   275,   587,   105,   281,   588,   423,   192,
     186,   342,   932,   405,   436,   440,   345,   309,   875,  -120,
     299,   789,   106,   285,   677,   400,   103,   871,   110,    65,
      92,   105,    70,   802,   909,    64,   830,   699,   700,   891,
     820,   678,   721,   831,  -180,   910,   831,    93,   106,     1,
      98,   612,   722,   721,   104,   896,   911,   821,     1,   -23,
     137,    75,   880,   722,    10,   934,   723,   304,  -260,   181,
     808,   122,   500,   191,   721,   701,   702,   723,   703,    64,
     809,   197,   822,   678,   722,   136,   681,    11,   770,   280,
     286,   126,   127,    52,   183,   613,   114,    75,   723,    56,
     116,   872,   724,   424,   838,   917,   529,   530,    71,   409,
     438,   809,   838,   724,   789,    81,    82,   669,   300,   172,
     670,   422,   823,    78,   574,   -23,   111,   174,    94,    95,
     810,   550,   118,   119,   193,    86,    47,    48,    49,   269,
     881,    59,    60,   268,  -120,   270,   943,   277,   275,    59,
      60,   951,   563,   589,   191,    92,   704,   343,    47,    48,
      49,   810,   346,    59,    60,    47,    48,    49,    47,    48,
      49,   401,   -23,   166,   -23,   410,   -23,   705,   171,   881,
      47,    48,    49,    89,   132,    59,    60,   606,   607,   123,
     452,    47,    48,    49,    82,   453,   682,   918,   919,    59,
      60,   -23,   -23,   -23,   456,   457,   458,   138,    47,    48,
      49,   196,    47,    48,    49,   692,   693,   866,   198,   315,
     773,   682,   411,   311,   412,   312,   413,   313,   199,    47,
      48,    49,   742,   743,   280,    47,    48,    49,   605,    47,
      48,    49,   746,   747,    12,   574,    13,    14,   200,    15,
     288,    47,    48,    49,   407,   289,   293,   574,   191,    65,
     297,   181,   305,   340,    65,   181,    65,   439,   686,   464,
     465,   466,   467,   468,   469,   339,   367,   341,   181,   470,
     471,   348,   175,   349,   269,   156,   157,   158,   159,   350,
     179,   352,   277,   353,   150,   151,   152,   153,   154,   155,
     354,   355,   278,   598,   599,   600,   601,   602,   603,    64,
     279,   172,   356,   357,    64,   172,    64,   358,   567,   174,
     569,   575,   828,   174,    47,    48,    49,   359,   172,    59,
      60,   360,   361,   753,   362,   364,   174,   365,   574,    19,
     859,   366,   368,   369,   370,   371,   372,   373,   374,   375,
      20,    21,   376,   377,    22,   378,    23,   379,   380,   550,
     381,   382,   383,   384,    24,   385,    25,   386,   387,   388,
     389,   741,   390,   531,   491,   391,   392,   393,   545,   394,
     395,   545,   396,   397,   399,  -246,    12,   441,    13,    14,
     442,    15,   498,   181,   -74,   532,   459,   413,    16,    17,
     410,   555,   559,   181,   561,   576,   580,   582,   591,   280,
     280,   885,   593,   594,   604,   804,    18,   596,   616,   675,
     620,   617,   621,   618,   622,   624,   625,   791,   541,   627,
     628,   541,   630,   895,   626,   629,   542,   631,   632,   542,
     166,   633,   567,   172,   569,   171,   639,   278,   640,   575,
     634,   174,   641,   172,   642,   279,   643,   644,   829,   568,
     645,   174,   452,   646,   647,   648,   649,   453,   650,   651,
     652,   654,   655,   653,   175,   656,   658,   592,   175,   659,
     657,    19,   179,   660,   661,   662,   179,   663,   664,   665,
     666,   175,    20,    21,   673,   691,    22,   757,    23,   179,
     758,   935,   936,   937,   767,   545,    24,   776,    25,   778,
     863,   792,   693,   692,   803,   545,   867,   833,   834,   835,
     836,   837,   841,   831,   856,   840,   687,   842,   181,    65,
     843,   844,   846,   280,   847,   857,   316,   106,   280,   876,
     868,   888,   889,   890,   902,   878,   904,   913,   881,   915,
     181,   931,   929,    65,   737,   541,   925,   938,   941,   927,
     947,   921,   676,   542,   282,   541,   551,   850,   680,   851,
     575,   898,   553,   542,   901,   672,   674,   781,   172,    64,
     698,   858,   575,   568,   689,   398,   174,   690,   796,   794,
     283,   543,   130,   706,   543,    99,    74,   115,   805,   544,
     172,   476,   544,    64,   736,   920,   175,   855,   174,   848,
     719,   854,   944,   807,   179,   907,   175,   845,   816,   908,
     914,   610,   739,     0,   179,   611,     0,     0,   744,   740,
       0,     0,   939,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     948,     0,   949,     0,     0,     0,     0,     0,     0,   280,
       0,     0,     0,   575,     0,     0,     0,     0,     0,     0,
       0,   280,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   860,     0,     0,     0,   452,     0,     0,     0,   737,
     453,   815,   737,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   545,     0,     0,   790,
       0,     0,     0,     0,     0,     0,     0,     0,   543,     0,
       0,     0,     0,     0,     0,     0,   544,     0,   543,     0,
       0,     0,     0,     0,     0,     0,   544,     0,     0,     0,
     545,   175,     0,   545,    65,     0,   181,     0,     0,   179,
       0,     0,   280,     0,     0,     0,   541,     0,     0,     0,
       0,     0,     0,   175,   542,     0,     0,     0,     0,     0,
       0,   179,     0,   181,     0,     0,   815,   166,   874,     0,
       0,     0,   171,     0,     0,   181,     0,     0,     0,     0,
     541,     0,     0,   541,    64,   545,   172,     0,   542,     0,
       0,   542,   790,     0,   174,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   545,     0,     0,
       0,     0,   181,   172,     0,     0,   899,     0,     0,    65,
       0,   174,     0,     0,     0,   172,     0,     0,     0,     0,
       0,     0,     0,   174,   737,   541,   737,     0,     0,     0,
       0,     0,     0,   542,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,     0,   541,     0,   923,
       0,     0,   172,     0,     0,   542,     0,     0,     0,    64,
     174,     0,     0,     0,     0,   545,   545,   545,   940,     0,
       0,    65,     0,     0,     0,   815,     0,   737,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   172,     0,     0,   181,   543,
     924,     0,     0,   174,     0,     0,     0,   544,     0,     0,
       0,     0,     0,     0,     0,   541,   541,   541,     0,     0,
       0,    64,     0,   542,   542,   542,     0,   736,     0,     0,
       0,     0,     0,   543,     0,     0,   543,     0,     0,   175,
       0,   544,     0,     0,   544,     0,     0,   179,   172,     0,
       0,     0,     0,     0,     0,     0,   174,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   175,     0,     0,     0,
       0,     0,     0,     0,   179,     0,     0,     0,   175,     0,
       0,     0,     0,     0,     0,     0,   179,     0,   543,     0,
       0,     0,     0,     0,     0,     0,   544,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -78,
     543,     0,     0,     0,     0,   175,     0,     0,   544,     0,
       0,     0,     0,   179,   139,   140,   141,   142,   143,     0,
       0,     0,     0,  -412,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   144,     0,     0,     0,   139,   140,
     141,   142,   143,     0,     0,     0,     0,  -412,   175,     0,
       0,     0,     0,     0,     0,     0,   179,     0,   144,     0,
       0,   455,   139,   140,   141,   142,   143,     0,   543,   543,
     543,     0,   562,     0,     0,     0,   544,   544,   544,     0,
       0,     0,   144,     0,     0,   479,   480,   481,     0,     0,
     482,     0,     0,   483,   484,   485,     0,   487,   488,   489,
     490,   175,   492,   493,   494,   495,   496,   497,     0,   179,
       0,   501,     0,     0,   502,   503,   504,   505,     0,   506,
       0,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,     0,     0,     0,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,    47,    48,    49,   160,   161,    59,    60,     0,   162,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,    47,    48,    49,   160,   161,
      59,    60,     0,   162,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,    47,
      48,    49,   160,   161,    59,    60,     0,   162,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   782,   783,
       0,     0,     0,     0,   636,   638,     0,     0,     0,     0,
       0,     0,   316,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   667,   668,     0,   204,     0,   205,
     206,   207,   208,   209,   210,   211,   212,     0,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,   688,
       0,   232,     0,     0,     0,     0,     0,     0,     0,   233,
     234,   235,     0,   236,   237,   238,     0,     0,   239,   240,
       0,   241,     0,   242,   243,   244,   245,     0,   246,   247,
       0,   248,     0,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,     0,     0,
       0,   635,     0,     0,     0,   750,   751,   752,     0,     0,
       0,   754,     0,     0,   755,     0,     0,     0,     0,   756,
       0,     0,   316,     0,     0,     0,   761,   762,     0,     0,
      47,    48,    49,     0,   763,    59,    60,     0,   764,     0,
       0,     0,   765,   317,   318,     0,   319,   204,   766,   205,
     206,   207,   208,   209,   210,   211,   212,     0,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,     0,
     224,     0,     0,     0,   225,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,     0,     0,   233,
     234,   235,     0,   236,   237,   238,     0,     0,   239,   240,
       0,   241,     0,   242,   243,   244,   245,     0,   246,   247,
       0,   248,     0,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
      47,    48,    49,     0,     0,    59,    60,     0,     0,     0,
       0,   202,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   865,     0,
       0,     0,   203,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   139,   140,   141,
     142,   143,     0,     0,     0,     0,   886,   204,   887,   205,
     206,   207,   208,   209,   210,   211,   212,   144,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,     0,
     224,     0,     0,     0,   225,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,     0,     0,   233,
     234,   235,     0,   236,   237,   238,     0,     0,   239,   240,
       0,   241,     0,   242,   243,   244,   245,     0,   246,   247,
       0,   248,     0,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
      47,    48,    49,     0,     0,    59,    60,     0,     0,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,    47,    48,    49,   160,   161,    59,
      60,   316,   162,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   317,   318,     0,   319,   204,     0,   205,   206,
     207,   208,   209,   210,   211,   212,     0,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,     0,   224,
       0,     0,     0,   225,   226,   227,   228,   229,   230,   231,
     232,     0,     0,     0,     0,     0,     0,     0,   233,   234,
     235,     0,   236,   237,   238,     0,     0,   239,   240,     0,
     241,     0,   242,   243,   244,   245,     0,   246,   247,     0,
     248,     0,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   203,     0,     0,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,    47,
      48,    49,     0,     0,    59,    60,   204,     0,   205,   206,
     207,   208,   209,   210,   211,   212,     0,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,     0,   224,
       0,     0,     0,   225,   226,   227,   228,   229,   230,   231,
     232,     0,     0,     0,     0,     0,     0,     0,   233,   234,
     235,     0,   236,   237,   238,     0,     0,   239,   240,     0,
     241,     0,   242,   243,   244,   245,     0,   246,   247,     0,
     248,     0,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   316,     0,     0,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,    47,
      48,    49,     0,     0,    59,    60,   204,     0,   205,   206,
     207,   208,   209,   210,   211,   212,     0,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,     0,   224,
       0,     0,     0,   225,   226,   227,   228,   229,   230,   231,
     232,     0,     0,     0,     0,     0,     0,     0,   233,   234,
     235,     0,   236,   237,   238,     0,     0,   239,   240,     0,
     241,     0,   242,   243,   244,   245,     0,   246,   247,     0,
     248,     0,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   884,   534,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   564,     0,     0,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,    47,
      48,    49,     0,     0,    59,    60,   204,   534,   205,   206,
     207,   208,   209,   210,   211,   212,     0,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,     0,   224,
     892,   534,     0,     0,     0,     0,     0,     0,     0,     0,
     232,     0,     0,     0,     0,     0,     0,     0,   233,   234,
     235,     0,   236,   237,   238,   534,     0,   239,   240,     0,
     241,     0,   242,   243,   244,   245,     0,   246,   247,     0,
     248,     0,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   534,   536,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,    47,    48,    49,     0,     0,    59,
      60,     0,     0,     0,     0,   535,     0,     0,   546,    47,
      48,    49,     0,     0,    59,    60,     0,   536,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,    47,    48,    49,     0,     0,    59,    60,
       0,   536,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,    47,    48,    49,
       0,     0,    59,    60,     0,   536,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,    47,    48,    49,     0,     0,    59,    60,     0,     0,
       0,     0,     0,     0,     0,   316,     0,   536,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,    47,    48,    49,     0,     0,    59,    60,
     204,     0,   205,   206,   207,   208,   209,   210,   211,   212,
       0,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   232,     0,     0,     0,     0,     0,
       0,     0,   233,   234,   235,     0,   236,   237,   238,     0,
       0,   239,   240,     0,   241,     0,   242,   243,   244,   245,
       0,   246,   247,     0,   248,     0,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47,    48,    49
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        12,   101,    17,    14,    15,    17,   101,    19,   104,    20,
      21,   224,   281,    24,   582,   285,   442,   413,   121,    19,
     121,   293,    36,   121,    37,    22,   122,    40,    50,    36,
      23,    40,    37,    23,   297,   304,    40,   186,   817,    36,
      87,   691,    39,    39,    43,    40,    61,   808,     6,    61,
       6,    22,    22,   703,   880,    17,    41,     6,     7,    41,
      19,   102,    40,    48,     0,    37,    48,    23,    39,    14,
      54,    19,    50,    40,    62,   854,    48,    36,    14,    36,
      92,    30,    48,    50,   178,   911,    64,   183,    37,   101,
      40,    79,   365,   105,    40,    44,    45,    64,    47,    61,
      50,   113,    61,   102,    50,    89,    43,     0,   149,   121,
     106,    81,    82,    12,   102,    63,    69,    30,    64,    36,
      73,    50,   100,   291,   756,    55,   399,   400,    36,    36,
     298,    50,   764,   100,   784,     3,     4,    37,   185,   101,
      40,   290,   101,    16,   570,   102,   104,   101,   104,   105,
     100,   547,    17,    18,   161,    15,   178,   179,   180,   121,
     165,   183,   184,   266,   161,   266,   927,   121,   266,   183,
     184,   950,   435,   186,   186,     6,   125,   186,   178,   179,
     180,   100,   186,   183,   184,   178,   179,   180,   178,   179,
     180,   186,   149,   293,   151,   102,   153,   146,   293,   165,
     178,   179,   180,     9,   161,   183,   184,    61,    62,    49,
     310,   178,   179,   180,     4,   310,   153,   147,   148,   183,
     184,   178,   179,   180,   317,   318,   319,    37,   178,   179,
     180,   110,   178,   179,   180,    28,    29,   805,   110,   201,
     152,   153,   149,   196,   151,   198,   153,   200,    37,   178,
     179,   180,   606,   607,   266,   178,   179,   180,   471,   178,
     179,   180,   612,   613,     8,   691,    10,    11,   110,    13,
     179,   178,   179,   180,   286,    55,    43,   703,   290,   291,
      40,   293,    90,    40,   296,   297,   298,   299,   560,    55,
      56,    57,    58,    59,    60,    74,   186,    40,   310,    65,
      66,    40,   101,    40,   266,   174,   175,   176,   177,    40,
     101,    40,   266,    40,   168,   169,   170,   171,   172,   173,
      40,    40,   121,   464,   465,   466,   467,   468,   469,   291,
     121,   293,    40,    40,   296,   297,   298,    40,   441,   293,
     441,   442,   738,   297,   178,   179,   180,    40,   310,   183,
     184,    40,    40,   623,    40,    40,   310,    40,   784,   103,
     786,    40,   186,    40,    40,    40,    40,   186,    40,   186,
     114,   115,    40,    40,   118,    40,   120,    40,    40,   775,
      40,    40,    40,    40,   128,    40,   130,    40,    40,    40,
      40,   604,    40,   405,   356,    40,    40,    40,   410,    40,
      40,   413,    40,    40,    40,     6,     8,    25,    10,    11,
      91,    13,    17,   425,    16,   178,    89,   153,    20,    21,
     102,    52,    43,   435,     6,    24,    37,    43,    41,   441,
     442,   827,    41,    53,    66,   705,    38,    54,    41,   153,
      48,    41,    48,    41,    48,    41,    41,   165,   410,    41,
      41,   413,    41,   849,    48,    48,   410,    41,    41,   413,
     560,    41,   565,   425,   565,   560,    41,   266,    41,   570,
      48,   425,    48,   435,    48,   266,    41,    41,   748,   441,
      41,   435,   582,    41,    41,    41,    48,   582,    41,    41,
      41,    41,    41,    48,   293,    41,    41,   459,   297,    41,
      48,   103,   293,    41,    41,    41,   297,    48,    41,    41,
      41,   310,   114,   115,   102,    25,   118,    41,   120,   310,
      49,   917,   918,   919,    41,   537,   128,    49,   130,    48,
     800,   165,    29,    28,    40,   547,   806,    48,    41,    41,
      41,    41,    41,    48,    36,    75,   561,    41,   560,   561,
      41,    41,    41,   565,    41,    41,    40,    39,   570,   102,
      41,    41,    55,    41,    89,    63,    41,    41,   165,    48,
     582,    37,    49,   585,   586,   537,    46,    37,    41,   102,
      37,   898,   551,   537,   123,   547,   416,   772,   553,   775,
     691,   860,   419,   547,   864,   537,   547,   688,   560,   561,
     579,   784,   703,   565,   565,   266,   560,   570,   697,   696,
     123,   410,    84,   581,   413,    55,    25,    71,   708,   410,
     582,   338,   413,   585,   586,   897,   425,   778,   582,   768,
     585,   776,   929,   721,   425,   876,   435,   764,   724,   878,
     889,   474,   594,    -1,   435,   474,    -1,    -1,   608,   596,
      -1,    -1,   922,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     940,    -1,   942,    -1,    -1,    -1,    -1,    -1,    -1,   691,
      -1,    -1,    -1,   784,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   703,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   797,    -1,    -1,    -1,   805,    -1,    -1,    -1,   721,
     805,   723,   724,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   738,    -1,    -1,   691,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,   547,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   547,    -1,    -1,    -1,
     772,   560,    -1,   775,   776,    -1,   778,    -1,    -1,   560,
      -1,    -1,   784,    -1,    -1,    -1,   738,    -1,    -1,    -1,
      -1,    -1,    -1,   582,   738,    -1,    -1,    -1,    -1,    -1,
      -1,   582,    -1,   805,    -1,    -1,   808,   897,   810,    -1,
      -1,    -1,   897,    -1,    -1,   817,    -1,    -1,    -1,    -1,
     772,    -1,    -1,   775,   776,   827,   778,    -1,   772,    -1,
      -1,   775,   784,    -1,   778,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   849,    -1,    -1,
      -1,    -1,   854,   805,    -1,    -1,   861,    -1,    -1,   861,
      -1,   805,    -1,    -1,    -1,   817,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   817,   876,   827,   878,    -1,    -1,    -1,
      -1,    -1,    -1,   827,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   897,    -1,   849,    -1,   900,
      -1,    -1,   854,    -1,    -1,   849,    -1,    -1,    -1,   861,
     854,    -1,    -1,    -1,    -1,   917,   918,   919,   923,    -1,
      -1,   923,    -1,    -1,    -1,   927,    -1,   929,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   897,    -1,    -1,   950,   738,
     902,    -1,    -1,   897,    -1,    -1,    -1,   738,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   917,   918,   919,    -1,    -1,
      -1,   923,    -1,   917,   918,   919,    -1,   929,    -1,    -1,
      -1,    -1,    -1,   772,    -1,    -1,   775,    -1,    -1,   778,
      -1,   772,    -1,    -1,   775,    -1,    -1,   778,   950,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   950,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   805,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   805,    -1,    -1,    -1,   817,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   817,    -1,   827,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   827,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,
     849,    -1,    -1,    -1,    -1,   854,    -1,    -1,   849,    -1,
      -1,    -1,    -1,   854,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    40,   897,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   897,    -1,    51,    -1,
      -1,   316,    31,    32,    33,    34,    35,    -1,   917,   918,
     919,    -1,    41,    -1,    -1,    -1,   917,   918,   919,    -1,
      -1,    -1,    51,    -1,    -1,   340,   341,   342,    -1,    -1,
     345,    -1,    -1,   348,   349,   350,    -1,   352,   353,   354,
     355,   950,   357,   358,   359,   360,   361,   362,    -1,   950,
      -1,   366,    -1,    -1,   369,   370,   371,   372,    -1,   374,
      -1,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,    -1,    -1,    -1,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,    -1,   186,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,    -1,   186,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,
      -1,    -1,    -1,    -1,   499,   500,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   529,   530,    -1,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   564,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,    -1,   111,   112,   113,    -1,    -1,   116,   117,
      -1,   119,    -1,   121,   122,   123,   124,    -1,   126,   127,
      -1,   129,    -1,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,    19,    -1,    -1,    -1,   620,   621,   622,    -1,    -1,
      -1,   626,    -1,    -1,   629,    -1,    -1,    -1,    -1,   634,
      -1,    -1,    40,    -1,    -1,    -1,   641,   642,    -1,    -1,
     178,   179,   180,    -1,   649,   183,   184,    -1,   653,    -1,
      -1,    -1,   657,    61,    62,    -1,    64,    65,   663,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,    -1,   111,   112,   113,    -1,    -1,   116,   117,
      -1,   119,    -1,   121,   122,   123,   124,    -1,   126,   127,
      -1,   129,    -1,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,    -1,    -1,   183,   184,    -1,    -1,    -1,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   803,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,   831,    65,   833,    67,
      68,    69,    70,    71,    72,    73,    74,    51,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,    -1,   111,   112,   113,    -1,    -1,   116,   117,
      -1,   119,    -1,   121,   122,   123,   124,    -1,   126,   127,
      -1,   129,    -1,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,    -1,    -1,   183,   184,    -1,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,    40,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    -1,    64,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    88,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,    -1,   111,   112,   113,    -1,    -1,   116,   117,    -1,
     119,    -1,   121,   122,   123,   124,    -1,   126,   127,    -1,
     129,    -1,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,   183,   184,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    88,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,    -1,   111,   112,   113,    -1,    -1,   116,   117,    -1,
     119,    -1,   121,   122,   123,   124,    -1,   126,   127,    -1,
     129,    -1,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,   183,   184,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    88,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,    -1,   111,   112,   113,    -1,    -1,   116,   117,    -1,
     119,    -1,   121,   122,   123,   124,    -1,   126,   127,    -1,
     129,    -1,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,   183,   184,    65,    42,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    88,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,    -1,   111,   112,   113,    42,    -1,   116,   117,    -1,
     119,    -1,   121,   122,   123,   124,    -1,   126,   127,    -1,
     129,    -1,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,    42,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    -1,    -1,   183,
     184,    -1,    -1,    -1,    -1,   102,    -1,    -1,   153,   178,
     179,   180,    -1,    -1,   183,   184,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,   183,   184,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,   183,   184,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,   183,   184,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,   183,   184,
      65,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   107,   108,   109,    -1,   111,   112,   113,    -1,
      -1,   116,   117,    -1,   119,    -1,   121,   122,   123,   124,
      -1,   126,   127,    -1,   129,    -1,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   178,   179,   180
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    14,   188,   189,   190,   193,   194,   195,   231,   295,
     178,     0,     8,    10,    11,    13,    20,    21,    38,   103,
     114,   115,   118,   120,   128,   130,   191,   235,   236,   251,
     253,   257,   300,   301,   304,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   196,   178,   179,   180,
     507,   508,    12,   305,   305,   305,    36,   328,    19,   183,
     184,   254,   255,   451,   452,   507,   237,   507,   305,   305,
     328,    36,   329,   305,   329,    30,   192,   287,    16,   242,
     296,     3,     4,   318,   320,   321,    15,   197,   232,     9,
     302,   303,     6,    23,   104,   105,   326,   327,   326,   327,
     330,   331,   252,   451,   237,    22,    39,   258,   263,   264,
       6,   104,   324,   325,   324,   330,   324,   288,    17,    18,
     243,   244,   237,    49,   298,   299,   328,   328,   319,   317,
     321,   233,   161,   198,   200,   201,   326,   507,    37,    31,
      32,    33,    34,    35,    51,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     181,   182,   186,   332,   340,   386,   442,   443,   445,   446,
     447,   450,   452,   453,   497,   501,   502,   503,   504,   505,
     506,   507,   509,   237,   256,   263,    23,   259,   260,   261,
     262,   507,    36,   161,   343,   345,   110,   507,   110,    37,
     110,   289,    19,    40,    65,    67,    68,    69,    70,    71,
      72,    73,    74,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    88,    92,    93,    94,    95,    96,
      97,    98,    99,   107,   108,   109,   111,   112,   113,   116,
     117,   119,   121,   122,   123,   124,   126,   127,   129,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   247,   248,   249,   250,   378,   452,
     477,   479,   481,   482,   486,   490,   492,   497,   501,   505,
     507,   263,   194,   295,   297,    39,   106,   322,   179,    55,
     199,   444,   335,    43,   341,   342,   388,    40,   387,    87,
     185,   498,   499,   500,   263,    90,   265,   266,   270,   262,
     346,   324,   324,   324,    36,   452,    40,    61,    62,    64,
     452,   454,   455,   458,   461,   462,   465,   466,   472,   474,
     475,   476,   477,   490,   495,   497,   501,   505,   507,    74,
      40,    40,    40,   186,   478,    40,   186,   384,    40,    40,
      40,   483,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,   384,    40,    40,    40,   186,   186,    40,
      40,    40,    40,   186,    40,   186,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,   248,    40,
      40,   186,   379,   265,   343,    23,   323,   507,   234,    36,
     102,   149,   151,   153,   202,   203,   205,   206,   213,   215,
     216,   223,   262,    50,   389,   396,   451,   334,   336,   337,
     332,   389,   394,   395,   442,   448,   449,   450,   389,   507,
     265,    25,    91,   267,   273,   238,   239,   344,   347,   348,
     351,   401,   442,   450,   293,   454,   475,   475,   475,    89,
     245,   246,   457,   460,    55,    56,    57,    58,    59,    60,
      65,    66,   463,   464,   471,   473,   379,   496,   487,   454,
     454,   454,   454,   454,   454,   454,   484,   454,   454,   454,
     454,   452,   454,   454,   454,   454,   454,   454,    17,   381,
     381,   454,   454,   454,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   381,
     381,   507,   178,   224,    42,   102,   162,   207,   208,   211,
     294,   452,   497,   501,   505,   507,   153,   217,   218,   221,
     294,   206,   204,   216,   214,    52,   397,   400,   449,    43,
     333,     6,    41,   449,    40,   271,   272,   378,   452,   477,
     274,   275,   377,   378,   476,   477,    24,   268,   276,   240,
      37,   350,    43,   352,   353,   403,   402,    37,    40,   186,
     291,    41,   452,    41,    53,   456,    54,   459,   465,   465,
     465,   465,   465,   465,    66,   384,    61,    62,   467,   470,
     503,   504,    19,    63,   468,   488,    41,    41,    41,   385,
      48,    48,    48,   485,    41,    41,    48,    41,    41,    48,
      41,    41,    41,    41,    48,    19,   454,   491,   454,    41,
      41,    48,    48,    41,    41,    41,    41,    41,    41,    48,
      41,    41,    41,    48,    41,    41,    41,    48,    41,    41,
      41,    41,    41,    48,    41,    41,    41,   454,   454,    37,
      40,   225,   211,   102,   221,   153,   204,    43,   102,   209,
     214,    43,   153,   219,   393,   399,   332,   451,   454,   272,
     275,    25,    28,    29,   269,   282,   285,   286,   242,     6,
       7,    44,    45,    47,   125,   146,   287,   349,   354,   355,
     356,   358,   362,   366,   367,   370,   371,   376,   348,   395,
     412,    40,    50,    64,   100,   404,   406,   413,   414,   415,
     416,   419,   422,   424,   430,   431,   452,   507,   292,   458,
     461,   384,   472,   472,   468,   469,   474,   474,   489,   383,
     454,   454,   454,   343,   454,   454,   454,    41,    49,   493,
     494,   454,   454,   454,   454,   454,   454,    41,   380,   226,
     149,   212,   210,   152,   222,   220,    49,   392,    48,   398,
     338,   246,    26,    27,   277,   278,   279,   280,   281,   377,
     452,   165,   165,   283,   286,   284,   285,   241,   359,   363,
     357,   368,   377,    40,   343,   333,   372,   415,    40,    50,
     100,   432,   437,   438,   440,   507,   422,   405,   418,   421,
      19,    36,    61,   101,   423,   425,   429,   290,   294,   343,
      41,    48,   382,    48,    41,    41,    41,    41,   382,   480,
      75,    41,    41,    41,    41,   480,    41,    41,   383,   229,
     208,   218,   390,   391,   396,   400,    36,    41,   278,   476,
     263,   360,   364,   343,   369,   454,   348,   343,    41,   435,
     436,   438,    50,   439,   507,   397,   102,   417,    63,   420,
      48,   165,   428,   441,    41,   294,   454,   454,    41,    55,
      41,    41,    41,   228,   230,   294,   397,   339,   265,   451,
     365,   343,    89,   375,    41,   434,   411,   419,   424,   441,
      37,    48,   427,    41,   506,    48,   227,    55,   147,   148,
     332,   192,   361,   305,   452,    46,   373,   102,   433,    49,
     410,    37,    37,   426,   441,   294,   294,   294,    37,   343,
     451,    41,   374,   438,   406,   407,   409,    37,   343,   343,
     408,   397
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
     435,   436,   437,   438,   439,   440,   441
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  SPARQLfedParser::yyr1_[] =
  {
         0,   187,   188,   188,   189,   190,   191,   191,   191,   191,
     192,   192,   193,   194,   195,   195,   196,   196,   197,   197,
     199,   198,   200,   201,   201,   202,   202,   202,   202,   203,
     203,   204,   204,   205,   206,   207,   207,   208,   208,   210,
     209,   211,   212,   213,   213,   214,   214,   215,   216,   217,
     217,   218,   218,   220,   219,   221,   222,   223,   224,   224,
     226,   225,   227,   227,   228,   229,   229,   230,   230,   230,
     231,   233,   234,   232,   236,   235,   237,   237,   239,   240,
     241,   238,   242,   243,   243,   244,   244,   245,   246,   246,
     247,   248,   248,   248,   248,   248,   248,   248,   248,   249,
     249,   250,   250,   252,   251,   253,   254,   254,   255,   255,
     256,   256,   257,   258,   259,   259,   260,   261,   262,   263,
     264,   264,   265,   266,   266,   267,   267,   268,   268,   269,
     269,   270,   271,   271,   272,   272,   272,   272,   273,   274,
     274,   275,   276,   277,   277,   278,   278,   279,   279,   280,
     281,   281,   282,   282,   283,   283,   284,   284,   285,   286,
     288,   287,   289,   289,   290,   290,   292,   291,   291,   293,
     293,   294,   294,   294,   294,   294,   294,   294,   296,   295,
     297,   297,   298,   299,   299,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   301,   302,   303,   303,
     304,   305,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   316,   317,   317,   318,   318,   319,
     319,   320,   321,   322,   323,   323,   324,   324,   325,   325,
     326,   327,   327,   327,   327,   328,   329,   331,   330,   332,
     332,   333,   333,   334,   335,   335,   337,   338,   339,   336,
     340,   341,   342,   342,   343,   343,   344,   344,   346,   345,
     347,   348,   348,   349,   350,   350,   351,   352,   353,   353,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   355,
     357,   356,   359,   360,   361,   358,   363,   364,   365,   362,
     366,   368,   369,   367,   371,   372,   370,   374,   373,   375,
     375,   376,   377,   377,   377,   378,   379,   380,   379,   381,
     381,   382,   383,   383,   384,   385,   384,   387,   386,   388,
     386,   389,   390,   391,   391,   392,   393,   393,   394,   395,
     395,   396,   396,   397,   398,   399,   399,   400,   402,   401,
     403,   401,   405,   404,   406,   406,   408,   407,   409,   409,
     410,   411,   411,   412,   413,   414,   415,   416,   417,   418,
     418,   419,   420,   421,   421,   422,   423,   423,   424,   424,
     425,   426,   426,   427,   427,   428,   428,   429,   429,   429,
     429,   430,   431,   431,   431,   431,   432,   433,   434,   434,
     435,   436,   436,   437,   437,   438,   439,   439,   440,   440,
     440,   441,   442,   442,   444,   443,   445,   446,   446,   446,
     446,   446,   447,   447,   448,   448,   449,   449,   450,   450,
     451,   451,   452,   452,   453,   453,   453,   453,   453,   453,
     454,   455,   456,   457,   457,   458,   459,   460,   460,   461,
     462,   463,   463,   464,   464,   464,   464,   464,   464,   464,
     464,   465,   466,   467,   467,   468,   468,   469,   469,   470,
     470,   470,   471,   471,   472,   473,   473,   474,   474,   474,
     474,   475,   475,   475,   475,   475,   475,   475,   475,   476,
     477,   477,   477,   477,   477,   477,   477,   477,   477,   477,
     477,   477,   477,   477,   477,   477,   477,   477,   477,   477,
     477,   477,   477,   477,   477,   477,   477,   477,   477,   477,
     477,   477,   477,   477,   477,   477,   477,   477,   477,   477,
     477,   477,   477,   477,   477,   477,   477,   477,   477,   477,
     477,   477,   477,   478,   478,   479,   480,   480,   481,   483,
     484,   485,   482,   487,   488,   489,   486,   490,   490,   490,
     491,   491,   492,   492,   492,   492,   492,   493,   494,   494,
     495,   496,   496,   497,   498,   499,   499,   500,   500,   501,
     501,   501,   502,   502,   502,   503,   503,   503,   504,   504,
     504,   505,   505,   506,   506,   506,   506,   507,   507,   508,
     508,   509,   509
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SPARQLfedParser::yyr2_[] =
  {
         0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       0,     1,     1,     3,     0,     1,     0,     2,     0,     2,
       0,     3,     2,     0,     1,     1,     1,     1,     1,     4,
       3,     0,     2,     1,     2,     1,     2,     1,     1,     0,
       3,     2,     1,     4,     3,     0,     2,     1,     2,     1,
       2,     1,     1,     0,     3,     2,     1,     3,     0,     2,
       0,     4,     0,     1,     2,     0,     2,     3,     3,     3,
       2,     0,     0,     5,     0,     5,     0,     2,     0,     0,
       0,     7,     3,     1,     1,     0,     1,     2,     0,     1,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     0,     6,     5,     1,     2,     1,     1,
       0,     1,     3,     2,     1,     1,     1,     2,     1,     2,
       0,     1,     4,     0,     1,     0,     1,     0,     1,     0,
       1,     3,     1,     2,     1,     1,     4,     1,     2,     1,
       2,     1,     3,     1,     2,     1,     1,     1,     1,     2,
       1,     1,     2,     2,     0,     1,     0,     1,     2,     2,
       0,     6,     0,     2,     1,     2,     0,     4,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     0,     4,
       0,     1,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     0,     1,
       3,     0,     1,     3,     3,     5,     5,     5,     2,     2,
       2,     5,     2,     0,     1,     0,     1,     2,     1,     0,
       2,     2,     2,     2,     1,     2,     1,     2,     0,     1,
       2,     1,     1,     1,     1,     3,     3,     0,     3,     0,
       1,     0,     1,     3,     0,     2,     0,     0,     0,     8,
       2,     2,     0,     1,     1,     1,     1,     1,     0,     4,
       2,     0,     1,     3,     0,     2,     2,     2,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     3,     0,     0,     0,     6,     0,     0,     0,     7,
       6,     0,     0,     4,     0,     0,     4,     0,     3,     0,
       2,     2,     1,     1,     1,     2,     1,     0,     6,     0,
       1,     2,     0,     2,     1,     0,     5,     0,     3,     0,
       3,     3,     2,     0,     1,     2,     0,     2,     1,     0,
       1,     1,     1,     2,     2,     0,     2,     1,     0,     3,
       0,     3,     0,     4,     1,     1,     0,     3,     0,     1,
       2,     0,     2,     1,     1,     1,     1,     2,     2,     0,
       2,     2,     2,     0,     2,     2,     0,     1,     1,     2,
       1,     1,     2,     2,     1,     2,     3,     1,     1,     1,
       2,     1,     1,     1,     2,     3,     1,     2,     0,     2,
       2,     0,     1,     1,     3,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     0,     4,     4,     1,     1,     1,
       1,     1,     0,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     0,     2,     2,     2,     0,     2,     1,
       2,     0,     1,     2,     2,     2,     2,     2,     2,     2,
       3,     1,     2,     1,     1,     2,     2,     0,     1,     2,
       2,     2,     0,     2,     2,     0,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     4,     6,     4,     4,     4,     4,     2,     2,     4,
       4,     4,     4,     2,     1,     4,     4,     4,     4,     6,
       6,     6,     6,     6,     4,     4,     4,     4,     4,     4,
       4,     4,     2,     2,     2,     4,     4,     4,     4,     4,
       2,     8,     6,     6,     6,     4,     4,     4,     4,     4,
       1,     1,     1,     3,     1,     7,     0,     1,     7,     0,
       0,     0,     5,     0,     0,     0,     6,     5,     5,     6,
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
  const SPARQLfedParser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "IT_DELETE", "IT_INSERT",
  "IT_DATA", "IT_GRAPH", "IT_SERVICE", "IT_LOAD", "IT_INTO", "IT_CLEAR",
  "IT_CREATE", "IT_SILENT", "IT_DROP", "IT_BASE", "IT_PREFIX", "IT_SELECT",
  "IT_DISTINCT", "IT_REDUCED", "GT_TIMES", "IT_CONSTRUCT", "IT_DESCRIBE",
  "IT_FROM", "IT_NAMED", "IT_ORDER", "IT_BY", "IT_ASC", "IT_DESC",
  "IT_LIMIT", "IT_OFFSET", "IT_BINDINGS", "IT_MEMBERS", "IT_STARTS",
  "IT_ENDS", "IT_ANY", "IT_UNORDERED", "GT_LCURLEY", "GT_RCURLEY",
  "IT_ASK", "IT_WHERE", "GT_LPAREN", "GT_RPAREN", "IT_UNDEF", "GT_DOT",
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
  "IT_USING", "IT_UUID", "IT_STRUUID", "IT_MD5", "IT_TO", "IT_STRBEFORE",
  "IT_STRAFTER", "IT_YEAR", "IT_ADD", "IT_COPY", "IT_RAND", "IT_SHA512",
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
  "_QValuesClause_E_Opt", "UpdateUnit", "Prologue", "_QBaseDecl_E_Opt",
  "_QPrefixDecl_E_Star", "_QLoadResults_E_Star", "LoadResults", "@1",
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
  "_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_Q_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C_E_Plus",
  "_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_Plus_Or_QGT_TIMES_E_C",
  "ConstructQuery", "$@11", "DescribeQuery", "_QVarOrIri_E_Plus",
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
  "OffsetClause", "ValuesClause", "$@12", "_QVar_E_Star",
  "_QBindingValue_E_Plus",
  "_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C",
  "$@13",
  "_Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star",
  "BindingValue", "Update", "$@14", "_QUpdate_E_Opt",
  "_O_QGT_SEMI_E_S_QUpdate_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QUpdate_E_Opt_C_E_Opt", "Update1", "Load",
  "_O_QIT_INTO_E_S_QGraphRef_E_C", "_Q_O_QIT_INTO_E_S_QGraphRef_E_C_E_Opt",
  "Clear", "_QIT_SILENT_E_Opt", "Drop", "Create", "Add", "Move", "Copy",
  "InsertData", "DeleteData", "DeleteWhere", "Modify",
  "_O_QIT_WITH_E_S_Qiri_E_C", "_Q_O_QIT_WITH_E_S_Qiri_E_C_E_Opt",
  "_QInsertClause_E_Opt",
  "_O_QDeleteClause_E_S_QInsertClause_E_Opt_Or_QInsertClause_E_C",
  "_QUsingClause_E_Star", "DeleteClause", "InsertClause", "UsingClause",
  "_O_Qiri_E_Or_QIT_NAMED_E_S_Qiri_E_C", "GraphOrDefault",
  "_QIT_GRAPH_E_Opt", "GraphRef", "GraphRefAll", "QuadPattern", "QuadData",
  "Quads", "$@15", "_QTriplesTemplate_E_Opt", "_QGT_DOT_E_Opt",
  "_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C_E_Star",
  "QuadsNotTriples", "@16", "@17", "$@18", "TriplesTemplate",
  "_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C_E_Opt", "GroupGraphPattern",
  "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C",
  "_O_QGT_LCURLEY_E_S_QSubSelect_E_Or_QGroupGraphPatternSub_E_S_QGT_RCURLEY_E_C",
  "$@19", "GroupGraphPatternSub", "_QTriplesBlock_E_Opt",
  "_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "Print", "OptionalGraphPattern", "@20", "GraphGraphPattern", "@21",
  "@22", "@23", "ServiceGraphPattern", "@24", "@25", "@26", "Bind",
  "MinusGraphPattern", "@27", "@28", "GroupOrUnionGraphPattern", "@29",
  "@30", "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@31",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "@32", "_QIT_DISTINCT_E_Opt",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ExpressionList", "@33",
  "TriplesSameSubject", "$@34", "$@35", "PropertyListNotEmpty",
  "_O_QVerb_E_S_QObjectList_E_C", "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "Verb", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "TriplesSameSubjectPath", "$@36", "$@37",
  "PropertyListNotEmptyPath", "$@38", "_O_QVerbPath_E_Or_QVerbSimple_E_C",
  "_O_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_C", "$@39",
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
  "TriplesNode", "BlankNodePropertyList", "@40", "Generator",
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
  "SubstringExpression", "ExistsFunc", "@41", "@42", "@43",
  "NotExistsFunc", "@44", "@45", "@46", "Aggregate",
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
       188,     0,    -1,   189,    -1,   193,    -1,   190,    -1,   194,
     191,   192,    -1,   235,    -1,   251,    -1,   253,    -1,   257,
      -1,    -1,   287,    -1,   295,    -1,   195,   196,   197,    -1,
      -1,   231,    -1,    -1,   196,   232,    -1,    -1,   197,   198,
      -1,    -1,   201,   199,   202,    -1,   161,    55,    -1,    -1,
     200,    -1,   203,    -1,   213,    -1,   223,    -1,   262,    -1,
     205,   206,   204,   212,    -1,   206,   204,    43,    -1,    -1,
     204,   209,    -1,   149,    -1,   102,   208,    -1,   211,    -1,
     207,   211,    -1,   102,    -1,   207,    -1,    -1,   102,   210,
     208,    -1,   294,   102,    -1,   149,    -1,   215,   216,   214,
     222,    -1,   216,   214,    43,    -1,    -1,   214,   219,    -1,
     151,    -1,   153,   218,    -1,   221,    -1,   217,   221,    -1,
     153,    -1,   217,    -1,    -1,   153,   220,   218,    -1,   294,
     153,    -1,   152,    -1,    36,   224,    37,    -1,    -1,   224,
     225,    -1,    -1,    40,   226,   229,    41,    -1,    -1,    48,
      -1,   230,   227,    -1,    -1,   229,   228,    -1,   294,   148,
     294,    -1,   294,   147,   294,    -1,   294,    55,   294,    -1,
      14,   178,    -1,    -1,    -1,    15,   233,   179,   234,   178,
      -1,    -1,   236,   242,   237,   263,   265,    -1,    -1,   237,
     258,    -1,    -1,    -1,    -1,   239,   240,   242,   241,   263,
     265,   192,    -1,    16,   244,   250,    -1,    17,    -1,    18,
      -1,    -1,   243,    -1,    89,   452,    -1,    -1,   245,    -1,
      40,   454,   246,    41,    -1,   452,    -1,   490,    -1,   477,
      -1,   378,    -1,   497,    -1,   501,    -1,   505,    -1,   247,
      -1,   248,    -1,   249,   248,    -1,   249,    -1,    19,    -1,
      -1,    20,   328,   252,   237,   263,   265,    -1,    21,   255,
     237,   256,   265,    -1,   451,    -1,   254,   451,    -1,   254,
      -1,    19,    -1,    -1,   263,    -1,    38,   237,   263,    -1,
      22,   259,    -1,   260,    -1,   261,    -1,   262,    -1,    23,
     262,    -1,   507,    -1,   264,   343,    -1,    -1,    39,    -1,
     266,   267,   268,   269,    -1,    -1,   270,    -1,    -1,   273,
      -1,    -1,   276,    -1,    -1,   282,    -1,    90,    25,   271,
      -1,   272,    -1,   271,   272,    -1,   477,    -1,   378,    -1,
      40,   454,   246,    41,    -1,   452,    -1,    91,   274,    -1,
     275,    -1,   274,   275,    -1,   377,    -1,    24,    25,   277,
      -1,   278,    -1,   277,   278,    -1,   280,    -1,   281,    -1,
      26,    -1,    27,    -1,   279,   476,    -1,   377,    -1,   452,
      -1,   285,   283,    -1,   286,   284,    -1,    -1,   286,    -1,
      -1,   285,    -1,    28,   165,    -1,    29,   165,    -1,    -1,
      30,   288,   289,    36,   293,    37,    -1,    -1,   289,   452,
      -1,   294,    -1,   290,   294,    -1,    -1,    40,   292,   290,
      41,    -1,   186,    -1,    -1,   293,   291,    -1,   507,    -1,
     497,    -1,   501,    -1,   505,    -1,    42,    -1,   162,    -1,
     452,    -1,    -1,   194,   300,   296,   299,    -1,    -1,   295,
      -1,    49,   297,    -1,    -1,   298,    -1,   301,    -1,   304,
      -1,   306,    -1,   308,    -1,   309,    -1,   310,    -1,   307,
      -1,   311,    -1,   312,    -1,   313,    -1,   314,    -1,     8,
     507,   303,    -1,     9,   326,    -1,    -1,   302,    -1,    10,
     305,   327,    -1,    -1,    12,    -1,    13,   305,   327,    -1,
      11,   305,   326,    -1,   114,   305,   324,   110,   324,    -1,
     128,   305,   324,   110,   324,    -1,   115,   305,   324,   110,
     324,    -1,   130,   329,    -1,   120,   329,    -1,   118,   328,
      -1,   316,   318,   319,    39,   343,    -1,   103,   507,    -1,
      -1,   315,    -1,    -1,   321,    -1,   320,   317,    -1,   321,
      -1,    -1,   319,   322,    -1,     3,   328,    -1,     4,   328,
      -1,   106,   323,    -1,   507,    -1,    23,   507,    -1,   104,
      -1,   325,   507,    -1,    -1,     6,    -1,     6,   507,    -1,
     326,    -1,   104,    -1,    23,    -1,   105,    -1,    36,   330,
      37,    -1,    36,   330,    37,    -1,    -1,   331,   332,   335,
      -1,    -1,   340,    -1,    -1,    43,    -1,   336,   333,   332,
      -1,    -1,   335,   334,    -1,    -1,    -1,    -1,   337,     6,
     451,   338,    36,   339,   332,    37,    -1,   386,   342,    -1,
      43,   332,    -1,    -1,   341,    -1,   345,    -1,   161,    -1,
     238,    -1,   347,    -1,    -1,    36,   346,   344,    37,    -1,
     348,   350,    -1,    -1,   351,    -1,   354,   333,   348,    -1,
      -1,   350,   349,    -1,   401,   353,    -1,    43,   348,    -1,
      -1,   352,    -1,   370,    -1,   356,    -1,   367,    -1,   358,
      -1,   362,    -1,   376,    -1,   366,    -1,   287,    -1,   355,
      -1,   146,   343,    -1,    -1,    44,   357,   343,    -1,    -1,
      -1,    -1,     6,   359,   360,   451,   361,   343,    -1,    -1,
      -1,    -1,     7,   363,   364,   365,   305,   451,   343,    -1,
     125,    40,   454,    89,   452,    41,    -1,    -1,    -1,    45,
     368,   369,   343,    -1,    -1,    -1,   371,   372,   343,   375,
      -1,    -1,    46,   374,   343,    -1,    -1,   375,   373,    -1,
      47,   377,    -1,   476,    -1,   477,    -1,   378,    -1,   507,
     379,    -1,   186,    -1,    -1,    40,   381,   454,   380,   383,
      41,    -1,    -1,    17,    -1,    48,   454,    -1,    -1,   383,
     382,    -1,   186,    -1,    -1,    40,   454,   385,   383,    41,
      -1,    -1,   450,   387,   389,    -1,    -1,   442,   388,   394,
      -1,   396,   397,   393,    -1,   396,   397,    -1,    -1,   390,
      -1,    49,   391,    -1,    -1,   393,   392,    -1,   395,    -1,
      -1,   389,    -1,   451,    -1,    50,    -1,   400,   399,    -1,
      48,   400,    -1,    -1,   399,   398,    -1,   449,    -1,    -1,
     450,   402,   404,    -1,    -1,   442,   403,   412,    -1,    -1,
     406,   405,   397,   411,    -1,   413,    -1,   414,    -1,    -1,
     406,   408,   397,    -1,    -1,   407,    -1,    49,   409,    -1,
      -1,   411,   410,    -1,   395,    -1,   415,    -1,   452,    -1,
     416,    -1,   419,   418,    -1,   102,   419,    -1,    -1,   418,
     417,    -1,   424,   421,    -1,    63,   424,    -1,    -1,   421,
     420,    -1,   430,   423,    -1,    -1,   425,    -1,   422,    -1,
     100,   422,    -1,   429,    -1,    37,    -1,   441,    37,    -1,
      48,   426,    -1,    37,    -1,   441,   427,    -1,    48,   441,
      37,    -1,    19,    -1,   101,    -1,    61,    -1,    36,   428,
      -1,   431,    -1,   507,    -1,    50,    -1,    64,   432,    -1,
      40,   415,    41,    -1,   437,    -1,   102,   438,    -1,    -1,
     434,   433,    -1,   438,   434,    -1,    -1,   435,    -1,   438,
      -1,    40,   436,    41,    -1,   440,    -1,   507,    -1,    50,
      -1,   507,    -1,    50,    -1,   100,   439,    -1,   165,    -1,
     445,    -1,   443,    -1,    -1,    51,   444,   389,    52,    -1,
     447,    40,   448,    41,    -1,    31,    -1,    32,    -1,    33,
      -1,    34,    -1,    35,    -1,    -1,   446,    -1,   449,    -1,
     448,   449,    -1,   450,    -1,   442,    -1,   452,    -1,   453,
      -1,   452,    -1,   507,    -1,   183,    -1,   184,    -1,   507,
      -1,   497,    -1,   501,    -1,   505,    -1,   509,    -1,   186,
      -1,   455,    -1,   458,   457,    -1,    53,   458,    -1,    -1,
     457,   456,    -1,   461,   460,    -1,    54,   461,    -1,    -1,
     460,   459,    -1,   462,    -1,   465,   463,    -1,    -1,   464,
      -1,    55,   465,    -1,    56,   465,    -1,    57,   465,    -1,
      58,   465,    -1,    59,   465,    -1,    60,   465,    -1,    66,
     384,    -1,    65,    66,   384,    -1,   466,    -1,   472,   471,
      -1,   503,    -1,   504,    -1,    19,   474,    -1,    63,   474,
      -1,    -1,   468,    -1,    61,   472,    -1,    62,   472,    -1,
     467,   469,    -1,    -1,   471,   470,    -1,   474,   473,    -1,
      -1,   473,   468,    -1,    64,   475,    -1,    61,   475,    -1,
      62,   475,    -1,   475,    -1,   476,    -1,   477,    -1,   495,
      -1,   497,    -1,   501,    -1,   505,    -1,   452,    -1,   490,
      -1,    40,   454,    41,    -1,    76,    40,   454,    41,    -1,
      77,    40,   454,    41,    -1,    78,    40,   454,    48,   454,
      41,    -1,    79,    40,   454,    41,    -1,    80,    40,   452,
      41,    -1,    67,    40,   454,    41,    -1,    68,    40,   454,
      41,    -1,    69,   478,    -1,   116,   186,    -1,   140,    40,
     454,    41,    -1,   137,    40,   454,    41,    -1,   129,    40,
     454,    41,    -1,   123,    40,   454,    41,    -1,    88,   384,
      -1,   481,    -1,   143,    40,   454,    41,    -1,   141,    40,
     454,    41,    -1,   139,    40,   454,    41,    -1,   135,    40,
     454,    41,    -1,   126,    40,   454,    48,   454,    41,    -1,
     136,    40,   454,    48,   454,    41,    -1,   142,    40,   454,
      48,   454,    41,    -1,   111,    40,   454,    48,   454,    41,
      -1,   112,    40,   454,    48,   454,    41,    -1,   113,    40,
     454,    41,    -1,   145,    40,   454,    41,    -1,   138,    40,
     454,    41,    -1,   134,    40,   454,    41,    -1,   131,    40,
     454,    41,    -1,   127,    40,   454,    41,    -1,   122,    40,
     454,    41,    -1,   121,    40,   454,    41,    -1,   119,   186,
      -1,   107,   186,    -1,   108,   186,    -1,   109,    40,   454,
      41,    -1,   144,    40,   454,    41,    -1,   133,    40,   454,
      41,    -1,   124,    40,   454,    41,    -1,   117,    40,   454,
      41,    -1,    70,   384,    -1,    71,    40,   454,    48,   454,
      48,   454,    41,    -1,    72,    40,   454,    48,   454,    41,
      -1,    73,    40,   454,    48,   454,    41,    -1,    81,    40,
     454,    48,   454,    41,    -1,    82,    40,   454,    41,    -1,
      83,    40,   454,    41,    -1,    84,    40,   454,    41,    -1,
      85,    40,   454,    41,    -1,    99,    40,   454,    41,    -1,
     479,    -1,   482,    -1,   486,    -1,    40,   454,    41,    -1,
     186,    -1,    86,    40,   454,    48,   454,   480,    41,    -1,
      -1,   382,    -1,   132,    40,   454,    48,   454,   480,    41,
      -1,    -1,    -1,    -1,    74,   483,   484,   485,   343,    -1,
      -1,    -1,    -1,    65,    74,   487,   488,   489,   343,    -1,
      92,    40,   381,   491,    41,    -1,   492,    40,   381,   454,
      41,    -1,    97,    40,   381,   454,   494,    41,    -1,    19,
      -1,   454,    -1,    93,    -1,    94,    -1,    95,    -1,    96,
      -1,    98,    -1,    49,    75,    55,   506,    -1,    -1,   493,
      -1,   507,   496,    -1,    -1,   379,    -1,   506,   500,    -1,
      87,   507,    -1,   185,    -1,   498,    -1,    -1,   499,    -1,
     502,    -1,   503,    -1,   504,    -1,   165,    -1,   166,    -1,
     167,    -1,   168,    -1,   169,    -1,   170,    -1,   171,    -1,
     172,    -1,   173,    -1,   163,    -1,   164,    -1,   174,    -1,
     176,    -1,   175,    -1,   177,    -1,   178,    -1,   508,    -1,
     180,    -1,   179,    -1,   181,    -1,   182,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SPARQLfedParser::yyprhs_[] =
  {
         0,     0,     3,     5,     7,     9,    13,    15,    17,    19,
      21,    22,    24,    26,    30,    31,    33,    34,    37,    38,
      41,    42,    46,    49,    50,    52,    54,    56,    58,    60,
      65,    69,    70,    73,    75,    78,    80,    83,    85,    87,
      88,    92,    95,    97,   102,   106,   107,   110,   112,   115,
     117,   120,   122,   124,   125,   129,   132,   134,   138,   139,
     142,   143,   148,   149,   151,   154,   155,   158,   162,   166,
     170,   173,   174,   175,   181,   182,   188,   189,   192,   193,
     194,   195,   203,   207,   209,   211,   212,   214,   217,   218,
     220,   225,   227,   229,   231,   233,   235,   237,   239,   241,
     243,   246,   248,   250,   251,   258,   264,   266,   269,   271,
     273,   274,   276,   280,   283,   285,   287,   289,   292,   294,
     297,   298,   300,   305,   306,   308,   309,   311,   312,   314,
     315,   317,   321,   323,   326,   328,   330,   335,   337,   340,
     342,   345,   347,   351,   353,   356,   358,   360,   362,   364,
     367,   369,   371,   374,   377,   378,   380,   381,   383,   386,
     389,   390,   397,   398,   401,   403,   406,   407,   412,   414,
     415,   418,   420,   422,   424,   426,   428,   430,   432,   433,
     438,   439,   441,   444,   445,   447,   449,   451,   453,   455,
     457,   459,   461,   463,   465,   467,   469,   473,   476,   477,
     479,   483,   484,   486,   490,   494,   500,   506,   512,   515,
     518,   521,   527,   530,   531,   533,   534,   536,   539,   541,
     542,   545,   548,   551,   554,   556,   559,   561,   564,   565,
     567,   570,   572,   574,   576,   578,   582,   586,   587,   591,
     592,   594,   595,   597,   601,   602,   605,   606,   607,   608,
     617,   620,   623,   624,   626,   628,   630,   632,   634,   635,
     640,   643,   644,   646,   650,   651,   654,   657,   660,   661,
     663,   665,   667,   669,   671,   673,   675,   677,   679,   681,
     684,   685,   689,   690,   691,   692,   699,   700,   701,   702,
     710,   717,   718,   719,   724,   725,   726,   731,   732,   736,
     737,   740,   743,   745,   747,   749,   752,   754,   755,   762,
     763,   765,   768,   769,   772,   774,   775,   781,   782,   786,
     787,   791,   795,   798,   799,   801,   804,   805,   808,   810,
     811,   813,   815,   817,   820,   823,   824,   827,   829,   830,
     834,   835,   839,   840,   845,   847,   849,   850,   854,   855,
     857,   860,   861,   864,   866,   868,   870,   872,   875,   878,
     879,   882,   885,   888,   889,   892,   895,   896,   898,   900,
     903,   905,   907,   910,   913,   915,   918,   922,   924,   926,
     928,   931,   933,   935,   937,   940,   944,   946,   949,   950,
     953,   956,   957,   959,   961,   965,   967,   969,   971,   973,
     975,   978,   980,   982,   984,   985,   990,   995,   997,   999,
    1001,  1003,  1005,  1006,  1008,  1010,  1013,  1015,  1017,  1019,
    1021,  1023,  1025,  1027,  1029,  1031,  1033,  1035,  1037,  1039,
    1041,  1043,  1046,  1049,  1050,  1053,  1056,  1059,  1060,  1063,
    1065,  1068,  1069,  1071,  1074,  1077,  1080,  1083,  1086,  1089,
    1092,  1096,  1098,  1101,  1103,  1105,  1108,  1111,  1112,  1114,
    1117,  1120,  1123,  1124,  1127,  1130,  1131,  1134,  1137,  1140,
    1143,  1145,  1147,  1149,  1151,  1153,  1155,  1157,  1159,  1161,
    1165,  1170,  1175,  1182,  1187,  1192,  1197,  1202,  1205,  1208,
    1213,  1218,  1223,  1228,  1231,  1233,  1238,  1243,  1248,  1253,
    1260,  1267,  1274,  1281,  1288,  1293,  1298,  1303,  1308,  1313,
    1318,  1323,  1328,  1331,  1334,  1337,  1342,  1347,  1352,  1357,
    1362,  1365,  1374,  1381,  1388,  1395,  1400,  1405,  1410,  1415,
    1420,  1422,  1424,  1426,  1430,  1432,  1440,  1441,  1443,  1451,
    1452,  1453,  1454,  1460,  1461,  1462,  1463,  1470,  1476,  1482,
    1489,  1491,  1493,  1495,  1497,  1499,  1501,  1503,  1508,  1509,
    1511,  1514,  1515,  1517,  1520,  1523,  1525,  1527,  1528,  1530,
    1532,  1534,  1536,  1538,  1540,  1542,  1544,  1546,  1548,  1550,
    1552,  1554,  1556,  1558,  1560,  1562,  1564,  1566,  1568,  1570,
    1572,  1574,  1576
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   478,   478,   481,   487,   492,   503,   504,   505,   506,
     511,   514,   518,   523,   527,   529,   533,   535,   538,   540,
     544,   544,   562,   568,   571,   575,   576,   577,   578,   584,
     585,   588,   590,   594,   598,   602,   603,   607,   608,   612,
     612,   620,   626,   630,   631,   634,   636,   640,   644,   648,
     649,   653,   654,   658,   658,   666,   672,   676,   679,   681,
     685,   685,   692,   694,   698,   701,   703,   707,   710,   713,
     719,   725,   727,   725,   737,   737,   749,   752,   760,   763,
     766,   760,   781,   789,   792,   799,   802,   807,   814,   817,
     822,   829,   832,   835,   838,   841,   844,   847,   851,   856,
     859,   867,   870,   877,   877,   888,   896,   899,   907,   910,
     917,   920,   925,   933,   940,   941,   945,   951,   957,   964,
     971,   973,   978,   985,   988,   993,   996,  1001,  1004,  1009,
    1013,  1017,  1024,  1027,  1034,  1037,  1040,  1043,  1049,  1055,
    1058,  1065,  1070,  1077,  1081,  1089,  1091,  1099,  1102,  1110,
    1118,  1119,  1126,  1130,  1138,  1141,  1146,  1149,  1153,  1159,
    1166,  1166,  1174,  1176,  1182,  1185,  1191,  1191,  1196,  1202,
    1204,  1208,  1211,  1214,  1217,  1220,  1223,  1226,  1232,  1232,
    1241,  1243,  1247,  1250,  1252,  1256,  1257,  1258,  1259,  1260,
    1261,  1262,  1263,  1264,  1265,  1266,  1270,  1277,  1284,  1287,
    1291,  1297,  1300,  1306,  1312,  1318,  1324,  1330,  1336,  1344,
    1352,  1359,  1368,  1374,  1377,  1381,  1384,  1388,  1392,  1398,
    1400,  1406,  1412,  1418,  1424,  1427,  1433,  1436,  1441,  1443,
    1447,  1453,  1456,  1459,  1462,  1469,  1475,  1481,  1481,  1489,
    1491,  1495,  1497,  1501,  1504,  1506,  1511,  1516,  1519,  1511,
    1530,  1534,  1537,  1539,  1543,  1544,  1557,  1558,  1563,  1563,
    1574,  1578,  1580,  1590,  1594,  1597,  1613,  1618,  1622,  1625,
    1629,  1630,  1631,  1632,  1633,  1634,  1635,  1636,  1639,  1643,
    1649,  1649,  1665,  1669,  1671,  1665,  1682,  1686,  1688,  1682,
    1699,  1710,  1714,  1710,  1724,  1728,  1724,  1738,  1738,  1750,
    1752,  1756,  1766,  1767,  1768,  1772,  1780,  1784,  1784,  1794,
    1797,  1804,  1810,  1812,  1826,  1829,  1829,  1839,  1839,  1842,
    1842,  1849,  1854,  1858,  1860,  1865,  1869,  1871,  1876,  1880,
    1882,  1886,  1890,  1898,  1903,  1907,  1909,  1913,  1921,  1921,
    1924,  1924,  1930,  1930,  1936,  1937,  1941,  1941,  1946,  1948,
    1952,  1955,  1957,  1961,  1965,  1969,  1975,  1979,  1983,  1986,
    1988,  1992,  1996,  2001,  2003,  2009,  2012,  2014,  2020,  2021,
    2027,  2031,  2032,  2036,  2037,  2041,  2042,  2046,  2047,  2048,
    2049,  2053,  2057,  2060,  2063,  2066,  2072,  2076,  2079,  2081,
    2085,  2088,  2090,  2094,  2095,  2099,  2103,  2104,  2108,  2109,
    2110,  2114,  2119,  2120,  2124,  2124,  2137,  2164,  2167,  2170,
    2173,  2176,  2183,  2186,  2191,  2195,  2202,  2203,  2207,  2210,
    2214,  2217,  2223,  2224,  2228,  2231,  2234,  2237,  2240,  2241,
    2247,  2252,  2261,  2268,  2271,  2279,  2288,  2295,  2298,  2305,
    2310,  2323,  2327,  2331,  2335,  2339,  2343,  2347,  2351,  2355,
    2359,  2366,  2371,  2380,  2383,  2390,  2393,  2400,  2403,  2408,
    2411,  2415,  2429,  2432,  2440,  2449,  2452,  2459,  2462,  2465,
    2468,  2472,  2473,  2474,  2475,  2478,  2481,  2484,  2487,  2491,
    2497,  2500,  2503,  2506,  2509,  2512,  2515,  2519,  2522,  2525,
    2528,  2531,  2534,  2537,  2540,  2541,  2544,  2547,  2550,  2553,
    2556,  2559,  2562,  2565,  2568,  2571,  2574,  2577,  2580,  2583,
    2586,  2589,  2592,  2595,  2598,  2601,  2604,  2607,  2610,  2613,
    2616,  2619,  2622,  2625,  2628,  2631,  2634,  2637,  2640,  2643,
    2646,  2647,  2648,  2654,  2657,  2664,  2671,  2674,  2678,  2684,
    2687,  2690,  2684,  2703,  2706,  2709,  2703,  2723,  2727,  2732,
    2741,  2744,  2748,  2751,  2754,  2757,  2760,  2766,  2772,  2775,
    2779,  2789,  2792,  2797,  2805,  2812,  2816,  2824,  2828,  2832,
    2833,  2834,  2838,  2839,  2840,  2844,  2845,  2846,  2850,  2851,
    2852,  2856,  2857,  2861,  2862,  2863,  2864,  2868,  2869,  2873,
    2874,  2878,  2879
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
     185,   186
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SPARQLfedParser::yyeof_ = 0;
  const int SPARQLfedParser::yylast_ = 2495;
  const int SPARQLfedParser::yynnts_ = 323;
  const int SPARQLfedParser::yyempty_ = -2;
  const int SPARQLfedParser::yyfinal_ = 11;
  const int SPARQLfedParser::yyterror_ = 1;
  const int SPARQLfedParser::yyerrcode_ = 256;
  const int SPARQLfedParser::yyntokens_ = 187;

  const unsigned int SPARQLfedParser::yyuser_token_number_max_ = 441;
  const SPARQLfedParser::token_number_type SPARQLfedParser::yyundef_token_ = 2;


} // w3c_sw

/* Line 1136 of lalr1.cc  */
#line 5691 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 2885 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


