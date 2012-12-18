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
#line 327 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"

/* Line 299 of lalr1.cc  */
#line 494 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

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
#line 508 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 511 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 522 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	assert(driver.lastWhereClause != NULL);
	if ((yysemantic_stack_[(3) - (3)].p_BindingClause) != NULL) // got a bindings clause
	    driver.lastWhereClause->m_GroupGraphPattern = 
		driver.makeConjunction(driver.lastWhereClause->m_GroupGraphPattern, (yysemantic_stack_[(3) - (3)].p_BindingClause));
	(yyval.p_Operation) = (yysemantic_stack_[(3) - (2)].p_Operation);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 566 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.startBindingSet();
      }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 569 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 584 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = (yysemantic_stack_[(2) - (1)].p_RSName);
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 590 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = NULL;
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 600 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	throw std::runtime_error("need to partition out results set part of SimpleEngine::loadDataOrResults");
    }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 634 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 636 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 642 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 680 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 682 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 688 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 707 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow(false);
      }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 709 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 729 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 732 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 735 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 741 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 747 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 749 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 751 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 759 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 762 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause);
	(yyval.p_Operation) = new Select((yysemantic_stack_[(5) - (2)].p_Project).distinctness, (yysemantic_stack_[(5) - (2)].p_Project).varSet, (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
	driver.countStar = (yysemantic_stack_[(5) - (1)].p_parentCountStar);
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 771 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 774 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 782 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
      }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 785 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 789 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if (!driver.curGraphName || (yysemantic_stack_[(3) - (2)].p_Project).varSet->includes(driver.curGraphName)) {
	      (yyval.p_GraphName) = NULL;
	  } else {
	      (yyval.p_GraphName) = driver.curGraphName;
	      driver.curGraphName = driver.createBNode();
	  }
      }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 796 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if ((yysemantic_stack_[(7) - (4)].p_GraphName) != NULL)
	      driver.curGraphName = (yysemantic_stack_[(7) - (4)].p_GraphName);
	  if ((yysemantic_stack_[(7) - (7)].p_BindingClause) != NULL)
	      (yysemantic_stack_[(7) - (5)].p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yysemantic_stack_[(7) - (5)].p_WhereClause)->m_GroupGraphPattern, (yysemantic_stack_[(7) - (7)].p_BindingClause));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (3)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(7) - (2)].p_Project).distinctness, (yysemantic_stack_[(7) - (2)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(7) - (5)].p_WhereClause), (yysemantic_stack_[(7) - (6)].p_SolutionModifier))));
	  driver.countStar = (yysemantic_stack_[(7) - (1)].p_parentCountStar);
      }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 808 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 816 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 819 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 826 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 834 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 841 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 849 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 856 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 859 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 862 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 865 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 868 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 871 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 874 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 883 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 886 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 894 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 897 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 903 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(2) - (2)].p_Operation);
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 909 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.lastWhereClause = (yysemantic_stack_[(4) - (3)].p_WhereClause);
	  /* $1 is NO LONGER known to be a DefaultGraphPattern because of grammar restrictions. */
	  (yyval.p_Operation) = new Construct((yysemantic_stack_[(4) - (1)].p_TableOperation), (yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
      }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 914 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	SWObjectDuplicator dup(driver.atomFactory);
	(yysemantic_stack_[(4) - (3)].p_TableOperation)->express(&dup);
	driver.lastWhereClause = new WhereClause((yysemantic_stack_[(4) - (3)].p_TableOperation));
	(yyval.p_Operation) = new Construct(dup.last.tableOperation, (yysemantic_stack_[(4) - (1)].p_DatasetClauses), driver.lastWhereClause, (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 924 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause) ? (yysemantic_stack_[(5) - (4)].p_WhereClause) : new WhereClause(new DefaultGraphPattern());
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 932 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm))));
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 935 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_TTerm))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 943 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 946 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 953 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 961 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(4) - (3)].p_WhereClause);
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 969 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 981 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 987 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 993 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1000 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.ensureGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1014 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1021 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1029 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1037 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1045 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1053 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1060 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1063 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1070 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1073 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1076 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1079 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1085 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1091 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1094 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1106 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1113 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1117 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1127 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1135 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1138 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1146 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1155 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1162 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1166 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1174 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1182 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1189 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1195 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1205 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = (yysemantic_stack_[(2) - (2)].p_BindingClause);
    }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1211 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1218 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Operation) = driver.root;
      }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1233 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	OperationSet* ret = driver.root ? dynamic_cast<OperationSet*>(driver.root) : new OperationSet();
	ret->push_back((yysemantic_stack_[(1) - (1)].p_Operation));
	driver.root = ret;
      }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1260 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(4) - (2)].p_Silence), (yysemantic_stack_[(4) - (3)].p_URI), (yysemantic_stack_[(4) - (4)].p_URI));
    }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1266 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1269 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1276 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1283 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1290 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1296 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1302 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1308 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1314 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1320 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1326 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1334 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete(true, (yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1342 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete(true, (yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1350 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(6) - (2)].p_DeleteInsert).del, (yysemantic_stack_[(6) - (2)].p_DeleteInsert).ins, new WhereClause(driver.ensureGraphPattern()), (yysemantic_stack_[(6) - (4)].p_TableOperation), (yysemantic_stack_[(6) - (1)].p_URI), (yysemantic_stack_[(6) - (3)].p_UsingPairs));
	driver.curOp = NULL;
    }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1357 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1363 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1370 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1377 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1381 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1388 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_UsingPairs) = NULL;
    }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1391 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (1)].p_UsingPairs) == NULL)
	    (yysemantic_stack_[(2) - (1)].p_UsingPairs) = new std::vector<s_UsingPair>();
	(yysemantic_stack_[(2) - (1)].p_UsingPairs)->push_back((yysemantic_stack_[(2) - (2)].p_UsingPair));
	(yyval.p_UsingPairs) = (yysemantic_stack_[(2) - (1)].p_UsingPairs);
    }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1400 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(2) - (2)].p_TableOperation);
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1406 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = NULL;
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1413 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Delete) = new Delete(false, (yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1419 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = new Insert((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 1425 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_UsingPair) = (yysemantic_stack_[(2) - (2)].p_UsingPair);
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1431 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_UsingPair).named = false;
	(yyval.p_UsingPair).name = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 1435 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_UsingPair).named = true;
	(yyval.p_UsingPair).name = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 1442 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 1445 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 1456 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1462 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 1465 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = driver.atomFactory->getURI("tag:eric@w3.org,2012-swobjparm/DEFAULT");
    }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1468 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = driver.atomFactory->getURI("tag:eric@w3.org,2012-swobjparm/NAMED");
    }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 1471 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = driver.atomFactory->getURI("tag:eric@w3.org,2012-swobjparm/ALL");
    }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 1478 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
	driver.curOp = NULL;
    }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 1485 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
    }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 1491 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 1493 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TableOperation) = driver.ensureGraphPattern();
	  driver.curOp = NULL;
      }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 1521 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 1526 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 1529 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 1532 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.ensureGraphPattern()));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 1554 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 1573 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 1575 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 1647 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_BindingClause)) : (yysemantic_stack_[(1) - (1)].p_BindingClause);
    }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 1654 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Print(driver.ensureGraphPattern());
    }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 1660 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 1664 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 1676 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 1680 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 1682 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 1685 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.ensureGraphPattern()));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 1693 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 1697 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 1699 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(6) - (5)].p_TTerm), driver.ensureGraphPattern(), (yysemantic_stack_[(6) - (4)].p_Silence), driver.atomFactory, false));
      }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 1706 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 1710 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 1712 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 282:

/* Line 690 of lalr1.cc  */
#line 1727 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Bind(driver.ensureGraphPattern(), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
	// no more triples go into the current BGP, per
	//   http://www.w3.org/TR/sparql11-query/#sparqlTranslateGraphPatterns
	// test reference:
	//   http://www.sparql.org/query-validator?query=ASK+{+%3Fs+%3Fp+%3Fo+FILTER+%281%29+BIND+%282+AS+%3Fb%29+%3Fs2+%3Fp2+%3Fo2+FILTER+%283%29+BIND+%284+AS+%3Fd%29}&languageSyntax=SPARQL&outputFormat=algebra&linenumbers=false
	driver.curBGP = NULL;
    }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 1738 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = (yysemantic_stack_[(2) - (2)].p_BindingClause);
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 1749 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 1751 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
      }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 1753 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 1764 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
	driver.endBindingRow();
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 1772 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 1774 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 1781 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 1793 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 1799 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 1801 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 1804 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 1816 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 1819 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 1822 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 1825 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 1828 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 1831 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 1834 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 1840 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 1844 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 1846 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 1854 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 1858 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 1860 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 1868 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 1873 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.ensureGraphPattern());
      }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 1886 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    driver.ensureGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 1902 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 1910 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 1914 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 1917 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yysemantic_stack_[(6) - (4)].p_Expressions);
      }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 1924 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 1927 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 1934 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 1942 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 1956 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 1959 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 1962 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(5) - (3)].p_Expressions);
      }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 1969 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 1972 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 2014 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 2018 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::RDF_type;
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 2041 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 2049 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 2052 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
        }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 2067 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 2078 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 2098 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	const URI* t = (yysemantic_stack_[(1) - (1)].p_PropertyPath)->release();
	// if (!t)
	//     w3c_sw_LINEN << "property path: " << $1->str() << "\n";
	(yyval.p_TTerm) = t ? t : (const TTerm*)new PropertyPath((yysemantic_stack_[(1) - (1)].p_PropertyPath));
    }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 2107 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 2126 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 2137 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = driver.lastPropertyPathAlternative;
	driver.lastPropertyPathAlternative = (yysemantic_stack_[(1) - (1)].p_PropertyPath);
      }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 2140 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (3)].p_PropertyPath) ? (yysemantic_stack_[(3) - (3)].p_PropertyPath) : (yysemantic_stack_[(3) - (1)].p_PropertyPath);
	  driver.lastPropertyPathAlternative = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
      }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 2147 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(2) - (2)].p_PropertyPath);
    }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 2153 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = NULL;
    }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 2156 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Alternative((yysemantic_stack_[(2) - (1)].p_PropertyPath) ? (yysemantic_stack_[(2) - (1)].p_PropertyPath) : driver.lastPropertyPathAlternative, (yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 2162 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = driver.lastPropertyPathSequence;
	driver.lastPropertyPathSequence = (yysemantic_stack_[(1) - (1)].p_PropertyPath);
      }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 2165 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {	
	  (yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (3)].p_PropertyPath) ? (yysemantic_stack_[(3) - (3)].p_PropertyPath) : (yysemantic_stack_[(3) - (1)].p_PropertyPath);
	  driver.lastPropertyPathSequence = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
      }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 2172 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(2) - (2)].p_PropertyPath);
    }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 2178 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = NULL;
    }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 2181 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Sequence((yysemantic_stack_[(2) - (1)].p_PropertyPath) ? (yysemantic_stack_[(2) - (1)].p_PropertyPath) : driver.lastPropertyPathSequence, (yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 2187 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(2) - (2)].p_RepeatRange).min == 1 && (yysemantic_stack_[(2) - (2)].p_RepeatRange).max == 1 ? (yysemantic_stack_[(2) - (1)].p_PropertyPath) : new PropertyPath::Repeated((yysemantic_stack_[(2) - (1)].p_PropertyPath), (yysemantic_stack_[(2) - (2)].p_RepeatRange).min, (yysemantic_stack_[(2) - (2)].p_RepeatRange).max);
    }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 2193 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RepeatRange).min = 1; (yyval.p_RepeatRange).max = 1;
    }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 2201 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Inverse((yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 2207 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RepeatRange).min = 0; (yyval.p_RepeatRange).max = 1;
    }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 2210 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RepeatRange).min = 0; (yyval.p_RepeatRange).max = PropertyPath::Repeated::Unlimited;
    }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 2213 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RepeatRange).min = 1; (yyval.p_RepeatRange).max = PropertyPath::Repeated::Unlimited;
    }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 2219 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 2222 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate(TTerm::RDF_type);
    }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 2225 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Negated((yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 2228 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
    }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 2235 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
    }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 2241 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(2) - (2)].p_PropertyPath);
    }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 2247 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = NULL;
    }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 2250 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Alternative((yysemantic_stack_[(2) - (1)].p_PropertyPath) ? (yysemantic_stack_[(2) - (1)].p_PropertyPath) : driver.lastPropertyPathSetAlternative, (yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 2256 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = driver.lastPropertyPathSetAlternative;
	driver.lastPropertyPathSetAlternative = (yysemantic_stack_[(1) - (1)].p_PropertyPath);
      }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 2259 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.lastPropertyPathSetAlternative = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
	  (yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (3)].p_PropertyPath);
      }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 2266 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = NULL;
    }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 2273 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 2276 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate(TTerm::RDF_type);
    }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 2279 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Inverse((yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 2285 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 2288 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate(TTerm::RDF_type);
    }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 2301 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 2305 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 425:

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

  case 426:

/* Line 690 of lalr1.cc  */
#line 2342 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 2345 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 2348 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 2351 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 2354 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 2361 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 2369 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 2373 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 2385 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 2389 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject;
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 2397 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 440:

/* Line 690 of lalr1.cc  */
#line 2424 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 2428 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 2445 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 2452 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 2455 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 2466 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 2469 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 2472 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 2475 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 2479 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::RDF_nil; // !!! new GraphTerm_rule5($1);
    }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 2490 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 2499 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 2506 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 2509 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 2517 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 2526 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 2533 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 2536 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 2548 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 469:

/* Line 690 of lalr1.cc  */
#line 2561 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = NULL;
    }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 2569 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 2573 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 2577 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 2581 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 2585 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 2589 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 2593 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 2597 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = true;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 2609 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 2618 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 2621 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 2628 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 2631 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 2638 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 2646 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 2649 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 2653 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 490:

/* Line 690 of lalr1.cc  */
#line 2667 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 2670 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 2678 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 2687 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 2690 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 2697 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 2700 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 2703 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 2713 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 2716 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 2719 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 2722 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 2729 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 2735 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 2738 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 2741 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 2744 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 2747 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 2750 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
      (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), new TTermExpression(driver.atomFactory->getURI(driver.getBase())), NULL));
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 2753 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
      (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), new TTermExpression(driver.atomFactory->getURI(driver.getBase())), NULL));
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 2757 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 2760 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 2763 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 2766 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ceil, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 2769 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 2772 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 2775 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 2779 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 2783 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 2786 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 2789 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 2792 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 2795 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 2798 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 2801 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 2804 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 2807 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 2810 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 2813 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 2816 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 2819 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 2822 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 2825 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 2828 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_tz, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 2831 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 2834 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_uuid, NULL, NULL, NULL));
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 2837 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_struuid, NULL, NULL, NULL));
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 2840 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 2843 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 2846 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 2849 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 2852 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 2855 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 2858 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 2861 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 2864 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 2867 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 2870 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 2873 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 2876 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 2879 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 2882 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 2893 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 2896 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 2903 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 2910 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 2917 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 2923 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_replace, (yysemantic_stack_[(9) - (3)].p_Expression), (yysemantic_stack_[(9) - (5)].p_Expression), (yysemantic_stack_[(9) - (7)].p_Expression))); // !! , $8
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 2929 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 2932 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 2936 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expression) = new ExistsExpression(driver.ensureGraphPattern());
	  driver.curOp = (yysemantic_stack_[(4) - (3)].p_TableOperation);
	  driver.countStar = (yysemantic_stack_[(4) - (2)].p_parentCountStar);
      }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 2944 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
      }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 2947 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 2951 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  // $$ = new ExistsExpression(false, driver.ensureGraphPattern());
	  (yyval.p_Expression) = new BooleanNegation(new ExistsExpression(driver.ensureGraphPattern()));
	  driver.curOp = (yysemantic_stack_[(5) - (4)].p_TableOperation);
	  driver.countStar = (yysemantic_stack_[(5) - (3)].p_parentCountStar);
      }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 2960 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 2964 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 2969 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  AggregateCall::ScalarVals svals;
	  if ((yysemantic_stack_[(6) - (5)].p_RDFLiteral) != NULL)
	      svals["separator"] = (yysemantic_stack_[(6) - (5)].p_RDFLiteral)->getLexicalValue();
	  (yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression), svals));
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 2978 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 2985 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 2988 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 2991 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 2994 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 2997 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 3003 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 3009 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 3016 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 3026 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 3034 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 3042 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 3049 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 3053 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 3061 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 690 of lalr1.cc  */
#line 4192 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -847;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        44,   -91,    85,  -847,  -847,  -847,   563,  -847,  -847,  -847,
    -847,  -847,    86,    86,    86,    86,    69,    29,  -847,   154,
      86,    86,    86,    71,    71,    69,    90,  -847,   111,  -847,
    -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,
    -847,  -847,  -847,  -847,  -847,  -847,  -847,   112,   118,  -847,
     154,    67,   126,    67,  -847,    52,  -847,  -847,  -847,  -847,
    -847,  -847,  -847,  -847,   176,  -847,  -847,  -847,  -847,  -847,
      70,  -847,    39,    39,    39,  -847,  -847,  -847,  -847,    -7,
    -847,  -847,  -847,    77,  -847,   127,    69,    69,  -847,   209,
    -847,  -847,   216,  -847,   211,   154,  -847,  -847,  -847,  -847,
    -847,  -847,  -847,   198,   922,    47,    69,  -847,    70,  -847,
      74,  -847,   162,     6,  -847,  -847,   146,   154,   147,   150,
     227,  -847,  -847,   -60,  -847,    -5,  -847,  -847,  -847,  1607,
      70,    44,  -847,  -847,  -847,  -847,    59,  -847,  -847,    94,
     220,  -847,  -847,  -847,   126,  -847,  -847,  -847,  -847,  -847,
    -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,
    -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,
    -847,  -847,  -847,  -847,  -847,   240,  -847,  -847,  -847,  -847,
     244,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,
     -41,  -847,  -847,   154,  -847,  -847,  -847,  -847,  -847,   162,
     162,   162,  -847,   273,  -847,   207,  -847,  -847,  -847,  -847,
    -847,    39,  -847,    39,    39,  -847,  -847,  -847,  -847,   270,
    -847,  2025,   233,   274,   277,    28,    35,   281,   282,   285,
     288,  -847,   290,   291,   296,   298,   305,   307,   318,   324,
     325,   329,   331,    35,   334,  -847,  -847,  -847,  -847,   335,
    -847,   340,   195,   197,   365,   366,   367,   371,   225,   374,
     230,   376,   381,   383,   384,   386,   388,   390,   393,   395,
     396,   397,   398,   400,   401,   402,   408,   409,   411,   412,
     413,   414,   416,  -847,  -847,  2146,  -847,  -847,  -847,  -847,
    -847,  -847,  -847,  -847,  -847,  -847,   417,  -847,  -847,  -847,
      36,   162,   316,  -847,    69,    50,  -847,   420,  -847,  -847,
    -847,   229,  -847,    92,   434,   922,  -847,  -847,    92,  1834,
      92,   154,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,
    2388,  2534,   436,  -847,    20,  -847,  -847,  -847,   425,   -15,
    -847,  2025,  2267,  2267,  2267,  -847,   372,  -847,  -847,  -847,
    -847,   284,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,
    -847,  -847,  -847,    36,  -847,  2025,  2025,  2025,  -847,  -847,
    2025,  -847,  -847,  2025,  2025,  2025,  2025,  -847,  2025,  2025,
    2025,  2025,   -60,  2025,  2025,  2025,  2025,  2025,  2025,  -847,
     447,   447,  2025,  -847,  -847,  2025,  2025,  2025,  2025,  -847,
    2025,  -847,  2025,  2025,  2025,  2025,  2025,  2025,  2025,  2025,
    2025,  2025,  2025,  2025,  2025,  2025,  2025,  2025,  2025,  2025,
    2025,  2025,  2025,  2025,  -847,   447,   447,  -847,  -847,  -847,
    -847,   154,  -847,  -847,     6,   286,  -847,  2412,  -847,  -847,
     897,  -847,  -847,   364,  -847,  -847,   314,  -847,  -847,  -847,
    -847,   422,  1834,  -847,  -847,   426,   467,  -847,  -847,  -847,
    -847,  -847,  1762,  -847,  -847,  -847,  -847,  2025,  2388,  -847,
    -847,  -847,  -847,  2534,  -847,  -847,  -847,  -847,  -847,   450,
     107,  -847,  -847,  -847,   111,   439,  -847,  -847,  -847,   435,
     440,  -847,  -847,  -847,  -847,  -847,  -847,  -847,    -9,   441,
    -847,  -847,  -847,   -60,  -847,   442,   428,   430,  2025,  2025,
    2025,  2025,  2025,  2025,   421,    35,  -847,  -847,   478,    45,
    -847,  -847,  -847,   448,   449,   451,  -847,   443,   445,   446,
     455,     6,   456,   457,   458,   463,   464,   459,   468,   470,
     471,   472,   460,  -847,  1431,  2025,   473,   476,   474,   475,
     477,   479,   480,   483,   484,   487,   482,   490,   491,   492,
     493,   494,   497,   505,   499,   507,   508,   509,   511,   512,
     506,   514,   515,   516,  2025,  2025,  -847,  -847,  -847,    43,
    -847,  -847,  -847,  1465,  -847,  -847,   385,  -847,  -847,  -847,
    -847,  -847,  -847,  1465,  -847,  -847,   405,  -847,    16,  -847,
      -2,  -847,  -847,  -847,  -847,  -847,   922,   176,  -847,  -847,
     372,  -847,  -847,  1301,   404,   406,  -847,  -847,   532,   536,
      53,  -847,  -847,   116,  1786,  -847,  -847,  1858,    53,    53,
    1883,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  2025,  -847,
    2025,  -847,  -847,  -847,  -847,  -847,  -847,  -847,    35,  -847,
    2025,  2025,    45,  -847,  -847,  -847,  2025,  2025,  -847,     6,
    -847,  -847,  -847,  -847,  2025,  2025,  2025,  2025,  -847,  -847,
    -847,  2025,  -847,  -847,  2025,  -847,  -847,  -847,  -847,  2025,
    -847,  -847,   526,   519,  -847,  -847,  2025,  2025,  -847,  -847,
    -847,  -847,  -847,  -847,  2025,  -847,  -847,  -847,  2025,  -847,
    -847,  -847,  2025,  -847,  -847,  -847,  -847,  -847,  2025,  -847,
    -847,  -847,   539,  -847,  -847,  -847,  -847,  -847,  -847,  -847,
    -847,   -46,  -847,  -847,  -847,   -13,  -847,  -847,  -847,   533,
     537,  -847,  -847,   540,  -847,  -847,  1301,  -847,   546,  -847,
    -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,    66,
    -847,   210,    62,   535,  -847,  -847,  -847,  -847,  -847,  -847,
    -847,  -847,   235,  -847,  -847,  -847,  -847,  -847,  -847,    -7,
    -847,  -847,  2534,   550,     6,  -847,   426,  -847,  -847,  -847,
    -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,
    1810,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,
    -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,
    -847,    37,   543,   552,   553,   548,   556,   558,   555,  -847,
     524,  -847,   564,   566,   567,   572,   555,   573,   574,  -847,
    -847,  -847,  -847,  -847,  2412,  -847,  -847,   897,    92,  -847,
    1834,  -847,   568,  -847,  -847,  -847,   576,   206,  -847,   101,
    -847,  -847,  -847,  -847,  -847,  1858,  -847,  -847,  -847,  -847,
    -847,  -847,  -847,   580,  -847,  -847,  -847,  -847,     6,  -847,
    -847,  2025,  -847,  1786,     6,  -847,  -847,  1141,  -847,  2025,
    -847,  2025,  -847,  -847,  2025,  -847,  -847,  -847,   579,   569,
    -847,  -847,  -847,  -847,   582,  -847,  -847,    41,  2373,  -847,
    -847,  -847,  -847,  1834,  -847,  -847,  -847,  -847,   584,  -847,
    -847,  -847,  -847,  -847,  -847,  -847,   525,   571,   162,   176,
      86,    86,  -847,     6,   541,  -847,  -847,  -847,  -847,  -847,
     586,   555,  -847,   113,  -847,  -847,  -847,  -847,   587,   -10,
    -847,   922,  -847,  -847,   581,   588,    66,  -847,    66,  -847,
      90,  -847,   176,   176,  -847,   -60,   591,  -847,   597,  -847,
    -847,  -847,  1465,  1465,  1465,   595,   538,    53,  -847,  1858,
    -847,  -847,  -847,  -847,     6,     6,   620,   603,  -847,  -847,
    -847,  -847,  -847,  -847,  -847,   206,  -847,  -847,  -847,  -847,
    -847,  -847,  -847,    69,  -847,     6,  -847,  1834,   580,  -847,
    -847,  -847
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        12,     0,     0,     2,     4,     3,   199,    14,    13,    10,
      68,     1,   183,   183,   183,   183,    74,     0,    74,     0,
     183,   183,   183,     0,     0,     0,   161,     6,     0,     7,
       8,     9,   170,   163,   167,   171,   172,   173,   177,   174,
     175,   176,   178,   179,   180,   181,   200,     0,    16,   184,
       0,     0,     0,     0,   226,     0,   101,    74,   108,   615,
     618,   617,   450,   451,   107,    74,   105,   448,   449,   616,
     119,   198,   217,   217,   217,   226,   194,   195,   196,   286,
       5,   162,   159,    83,    74,   165,     0,     0,   205,   201,
     204,    69,    11,    15,   186,     0,   222,   221,   223,   220,
     188,   190,   189,     0,   228,     0,     0,    75,   119,   106,
     109,   120,   122,     0,   218,   215,     0,     0,     0,     0,
       0,   160,   284,     0,   285,     0,    81,    82,    84,     0,
     119,    12,   166,   168,   210,   211,   208,   203,   202,     0,
       0,    17,    22,    18,     0,   187,   182,   219,   224,   426,
     427,   428,   429,   430,   423,   609,   610,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   611,   613,   612,   614,
     619,   620,   457,   233,   229,   241,   340,   422,   421,   432,
       0,   338,   446,   447,   453,   454,   597,   598,   599,   455,
     595,   452,   456,     0,   112,   113,   114,   115,   117,   122,
     122,   122,   110,     0,   111,   124,   123,   247,   244,   118,
     243,   217,   216,   217,   217,   225,   287,   294,   296,     0,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   569,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   580,   581,   582,   583,     0,
     584,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    96,    97,    99,    80,    95,    93,    89,
     559,   522,   524,   560,   561,    94,     0,    90,    91,    92,
       0,   122,   199,   164,     0,     0,   209,     0,   206,    70,
      20,     0,   185,     0,   227,   228,   242,   239,   343,   431,
       0,     0,   593,   594,   596,   591,   116,   103,   102,   104,
       0,     0,   126,   125,   250,   191,   193,   192,     0,     0,
     303,     0,     0,     0,     0,   505,    86,   458,   461,   465,
     467,   469,   479,   490,   493,   498,   499,   500,   506,   501,
     502,   503,   504,   589,   572,     0,     0,     0,   563,   515,
       0,   335,   549,     0,     0,     0,     0,   570,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   521,
     330,   330,     0,   542,   543,     0,     0,     0,     0,   516,
       0,   541,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    98,   330,   330,   327,   326,    73,
     207,     0,   212,   213,     0,     0,    56,     0,    31,    45,
       0,    19,    23,     0,    29,    24,     0,    43,    25,    26,
     353,     0,   431,   352,   234,   230,     0,   240,   341,   342,
     344,   443,   431,   433,   442,   339,   592,     0,   130,   131,
     134,   136,   133,   137,   138,   140,   325,   323,   324,     0,
     128,   127,   437,   245,     0,     0,   246,   253,   251,   257,
       0,   361,   436,   435,   359,   289,   297,   295,     0,     0,
     496,   497,   495,     0,    87,     0,   459,   463,     0,     0,
       0,     0,     0,     0,     0,     0,   468,   470,   480,   492,
     590,   588,   573,     0,     0,     0,   336,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   331,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   214,   197,    71,     0,
     309,    35,   310,    36,    32,    33,     0,   311,   306,   307,
     308,   305,    49,    50,    46,    47,     0,    29,     0,    43,
       0,   424,   350,   356,   358,   231,   228,     0,   425,   434,
      86,   132,   139,     0,     0,     0,   121,   129,   153,   155,
       0,    77,   248,   315,   250,   258,   255,   431,   364,     0,
       0,   293,   300,   302,   304,   507,    85,    88,     0,   462,
       0,   466,   471,   472,   473,   474,   475,   476,     0,   477,
       0,     0,   485,   491,   481,   482,     0,     0,   494,     0,
     513,   514,   562,   333,     0,     0,     0,     0,   571,   508,
     509,     0,   511,   512,     0,   554,   555,   556,   557,     0,
     578,   579,     0,   586,   558,   544,     0,     0,   533,   548,
     540,   539,   520,   547,     0,   538,   519,   537,     0,   546,
     536,   527,     0,   518,   535,   526,   517,   525,     0,   523,
     545,   534,     0,   328,    55,    58,    57,    34,    39,    48,
      53,     0,    28,    37,    30,     0,    42,    51,    44,   345,
     354,   232,   236,     0,   146,   147,   141,   142,     0,   144,
     145,   149,   150,   157,   158,   151,   154,   152,   156,     0,
     404,     0,     0,     0,   366,   368,   369,   377,   384,   385,
     398,   390,   396,   378,   403,    78,   272,   276,   279,   286,
     270,   312,     0,     0,     0,   254,   230,   268,   260,   262,
     263,   264,   266,   267,   261,   259,   316,   265,   256,   445,
     431,   440,   444,   362,   363,   365,   360,   288,   290,   291,
     298,   460,   464,   478,   487,   488,   486,   489,   483,   484,
     574,     0,     0,     0,     0,     0,     0,     0,   565,   575,
       0,   587,     0,     0,     0,     0,   565,     0,     0,   576,
     333,    63,    40,    27,     0,    54,    41,     0,   347,   351,
     431,   357,     0,   135,   143,   148,     0,   414,   417,     0,
     405,   407,   416,   399,   438,   431,   388,   393,   401,   402,
     400,   395,   397,   119,   273,   277,   280,   283,     0,   313,
     322,     0,   269,   250,     0,   439,   441,     0,   337,     0,
     334,     0,   551,   552,     0,   510,   553,   566,     0,     0,
     577,   531,   532,   528,     0,   529,   530,     0,     0,    38,
      52,   348,   349,   431,   355,   237,   406,   415,     0,   412,
     420,   418,   419,   375,   381,   383,   386,   391,   122,     0,
     183,   183,   271,     0,     0,   252,   320,   301,   299,   332,
       0,   565,   564,     0,   567,   329,    59,    64,    60,     0,
     346,   228,   408,   410,   367,   379,     0,   389,     0,   394,
     161,   274,     0,     0,   314,     0,   317,   550,     0,   585,
      61,    62,     0,     0,     0,     0,   413,   372,   376,   431,
     382,   387,   392,    79,     0,     0,     0,     0,   318,   321,
     568,    67,    66,    65,   238,     0,   411,   370,   373,   374,
     380,   275,   278,     0,   282,     0,   409,   431,   119,   319,
     371,   281
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -847,  -847,  -847,  -847,  -847,  -847,   529,  -847,  -847,  -847,
    -847,  -847,  -847,  -847,  -847,  -847,    49,  -847,   212,  -847,
    -178,  -847,  -847,    82,  -847,  -847,    58,  -847,   221,  -847,
    -168,  -847,  -847,    78,  -847,  -847,  -847,  -847,  -847,  -847,
    -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,   222,
    -847,  -847,  -847,  -847,   186,  -847,  -847,  -847,    63,  -847,
     387,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,
    -847,  -847,  -847,  -847,  -153,  -100,  -847,  -182,  -847,  -847,
    -847,  -847,  -847,  -847,   208,  -847,  -847,   201,  -847,  -847,
     -61,  -847,  -847,  -847,  -847,  -847,  -847,    64,    60,  -273,
    -847,  -847,   551,  -847,  -847,  -847,  -847,  -847,  -847,  -847,
      -8,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,
    -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,
    -847,   592,  -847,  -847,    56,  -847,    12,   632,   -24,   662,
     612,  -847,  -311,   -88,  -847,  -847,  -847,  -847,  -847,  -847,
    -847,  -847,  -847,  -396,  -847,  -847,  -847,  -847,  -613,  -847,
    -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,
    -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,
     -80,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,
    -847,  -847,  -847,  -847,  -418,  -847,  -847,  -847,  -847,  -847,
    -847,  -847,  -847,  -847,  -847,  -588,  -105,   327,  -847,  -324,
    -678,  -138,  -222,  -847,  -847,  -847,  -847,  -847,  -847,  -250,
    -847,  -847,  -847,  -847,  -142,  -846,  -847,  -847,  -143,  -847,
    -847,  -847,  -847,  -847,  -479,  -847,  -269,  -847,  -847,  -847,
    -847,  -847,  -847,  -847,  -847,  -847,  -847,  -270,   -49,  -847,
    -847,  -847,  -847,  -244,  -847,  -847,  -847,   -48,  -847,  -245,
    -847,  -847,  -847,  -847,  -847,  -847,  -847,  -847,  -819,  -847,
     -95,  -847,  -847,  -847,  -847,  -303,  -847,  -314,  -847,  -847,
    -847,  -847,  -284,  -583,   -89,   -14,    34,  -847,   790,  -847,
    -847,  -847,    68,  -847,  -847,    65,  -847,  -847,  -847,  -108,
    -847,  -847,    55,  -847,  -847,  -847,  -491,  -847,  -407,    51,
    -308,  -113,  -847,  -847,  -787,  -847,  -847,  -847,  -847,  -847,
    -847,  -847,  -847,  -103,  -847,  -847,  -847,  -847,  -847,  -847,
     -63,  -847,  -847,  -847,   182,  -847,   190,   191,   399,  -223,
     -17,  -847,  -847
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,    26,     5,     6,     7,    48,    92,
     141,   311,   142,   143,   441,   442,   598,   443,   444,   583,
     584,   724,   834,   585,   833,   445,   600,   446,   447,   593,
     594,   728,   837,   595,   836,   448,   579,   716,   831,   961,
     937,   898,   938,     8,    93,   139,   435,    27,    28,    55,
     483,   484,   765,   863,    84,   128,   129,   504,   505,   283,
     284,   285,   286,    29,    56,    30,    64,    65,   201,    31,
     107,   194,   195,   196,   197,   112,   113,   204,   205,   332,
     480,   616,   206,   468,   469,   333,   473,   474,   481,   736,
     737,   738,   739,   740,   617,   745,   747,   618,   619,    80,
      81,    82,     9,   132,   133,    32,    85,    33,    34,    35,
      50,   145,   146,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,   137,    88,   136,   306,   307,
      89,    90,   308,   432,   116,   117,    99,   100,    57,    76,
     103,   104,   173,   606,   454,   314,   455,   456,   842,   941,
     174,   316,   317,   209,   485,   210,   334,   486,   487,   775,
     623,   488,   625,   626,   776,   777,   778,   868,   779,   864,
     919,   974,   780,   865,   920,   781,   866,   921,   782,   783,
     121,   122,   123,   338,   630,   798,   124,   125,   339,   219,
     877,   634,   800,   498,   586,   784,   869,   923,   785,   786,
     874,   979,   995,   956,   787,   475,   476,   428,   830,   544,
     887,   811,   372,   663,   175,   320,   318,   458,   459,   451,
     901,   902,   839,   729,   452,   602,   841,   730,   603,   489,
     629,   628,   793,   794,   753,   855,   754,   988,   997,   989,
     968,   944,   755,   756,   913,   970,   945,   914,   757,   758,
     856,   947,   916,   759,   857,   949,   917,   760,   861,   761,
     862,   762,   850,   986,   966,   907,   943,   908,   851,   911,
     461,   177,   313,   178,   179,   180,   462,   789,   492,   620,
     493,   790,   604,   915,   464,   453,   345,   183,   346,   347,
     639,   506,   348,   641,   507,   349,   350,   516,   517,   351,
     352,   652,   658,   807,   653,   518,   353,   519,   354,   355,
     356,   357,   369,   290,   888,   291,   292,   293,   377,   531,
     294,   522,   659,   358,   682,   296,   821,   822,   359,   521,
     360,   323,   324,   325,   361,   186,   187,   188,   362,   190,
     363,    69,   192
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int SPARQLfedParser::yytable_ninf_ = -432;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        68,    78,    71,    66,   457,    51,    52,    53,   200,   176,
     202,   788,    72,    73,    74,   181,   289,   327,   328,   329,
     491,   389,   596,   477,   287,   741,   295,   496,   909,   631,
     301,   490,   632,    94,  -292,   463,   217,   -76,   577,   894,
     326,   184,   726,   207,   791,   114,   962,    68,   321,    58,
     109,    67,   149,   150,   151,   152,   153,   940,   723,     1,
     722,  -431,   134,   135,   101,   656,   297,   545,   460,   367,
     465,   193,   482,    95,   431,   105,   370,   426,   147,   878,
     304,   714,   199,   935,   715,    11,   879,   191,   198,    10,
     879,    96,   106,   105,   749,   126,   127,   105,    67,    49,
     212,   574,   575,   749,   750,   832,    54,   749,    75,   657,
     111,  -119,   300,   750,   111,    86,    87,   750,   751,   429,
     723,    79,   766,   767,   768,    62,    63,   751,    83,   118,
     119,   751,    95,   880,    91,   668,   614,   615,   182,   963,
     964,   835,   727,   450,   958,   115,   322,   769,   741,   795,
     796,  1000,   910,   727,  -249,   752,   312,   216,   449,   804,
     805,   770,   771,   288,   772,   477,   996,   305,   752,   208,
      62,    63,   289,    97,    98,   596,   198,   131,   609,   633,
     287,  -292,   295,   218,   870,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
      59,    60,    61,   170,   171,    62,    63,   876,   172,    59,
      60,    61,   799,    87,    62,    63,   368,   472,   478,   880,
     176,   144,   297,   371,   427,   470,   181,    59,    60,    61,
      59,    60,    61,    59,    60,    61,   148,  -119,    62,    63,
      70,   773,    59,    60,    61,   494,    59,    60,    61,   808,
     809,   847,   184,   -21,   203,   858,   184,   848,   211,   213,
     925,   848,   214,   810,   774,   215,   436,   335,   300,   336,
     337,   184,    59,    60,    61,   309,   310,    62,    63,   108,
     430,    59,    60,    61,   315,   319,   185,   110,   433,   166,
     167,   168,   169,   649,   198,   731,    68,   859,   191,   330,
     331,    68,   191,    68,   466,   477,   130,   340,   849,   364,
     491,   298,   849,   300,   300,   365,  -169,   191,   366,   288,
     -21,   490,   373,   374,   490,    12,   375,    13,    14,   376,
      15,   378,   379,   437,    59,    60,    61,   380,   860,   381,
     508,   509,   510,   511,   512,   513,   382,    67,   383,   182,
     514,   515,    67,   182,    67,   472,    59,    60,    61,   384,
     478,    62,    63,   470,   471,   385,   386,   -21,   182,   -21,
     387,   -21,   388,   497,   588,   390,   391,   588,   872,   140,
     438,   392,   439,   393,   440,   394,    59,    60,    61,   184,
      59,    60,    61,   500,   501,   502,   -21,   -21,   -21,   184,
     642,   643,   644,   645,   646,   647,   395,   396,   397,    59,
      60,    61,   398,   399,   576,   400,   536,   402,   401,   596,
     591,    19,   403,   591,   404,   405,   803,   406,   477,   407,
     845,   408,    20,    21,   409,   191,   410,   411,   412,   413,
    -235,   414,   415,   416,    22,   191,    23,    24,    25,   417,
     418,   300,   419,   420,   421,   422,   300,   423,   425,   928,
     434,   479,   495,   503,   477,   543,   578,   298,   437,   440,
     605,   587,   922,   607,   587,   601,   613,   622,   926,   624,
     939,   627,   638,   635,   637,   640,   182,   490,   648,   718,
     660,   661,   664,   662,   665,   666,   182,   185,   669,   670,
     478,   185,   471,   189,   667,   672,   673,   671,   674,   679,
     675,   176,   676,   677,   678,   684,   185,   181,   685,   688,
     588,   689,   690,   686,   687,   691,   692,   954,   299,   693,
     588,   694,   695,   696,   697,   494,   699,   636,   792,   700,
     650,   651,   698,   184,   981,   982,   983,   701,   702,   703,
     704,   705,   490,   706,   707,   708,   709,   710,   711,   491,
     720,   184,   615,  -169,   184,   614,   591,   588,   819,   820,
     490,   743,    12,   744,    13,    14,   591,    15,   991,   992,
     -72,   829,   843,   838,    16,    17,   840,   341,   854,   191,
      68,   871,   881,   732,   882,   883,   300,   884,   885,   999,
     886,   889,    18,   764,   879,   905,   890,   191,   891,   892,
     191,   764,   764,   591,   893,   895,   896,   587,   906,   589,
     111,   932,   589,   478,   934,   933,   942,   587,   957,   946,
     965,   967,   955,   984,   185,   948,   960,   969,   978,   980,
     182,    67,   985,   993,   185,   994,   721,   742,   160,   161,
     162,   163,   164,   165,   763,   597,   899,   725,   182,   478,
     302,   182,   763,   763,   587,   717,   490,   599,    19,   900,
     621,   719,   424,   733,   612,   844,   611,   973,   746,    20,
      21,   138,   303,   748,   299,   102,    77,   120,   873,   867,
     520,    22,   897,    23,    24,    25,   903,   904,   987,   990,
     846,   792,   971,   972,   853,   802,   801,   806,   654,   655,
     959,     0,     0,     0,   189,     0,     0,     0,   189,   300,
       0,     0,     0,     0,     0,     0,     0,   184,     0,     0,
       0,     0,   764,   189,   852,   764,   950,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   300,     0,     0,     0,     0,
       0,     0,     0,   918,     0,   589,   792,     0,     0,     0,
     742,   588,     0,   191,   588,   589,     0,   184,     0,     0,
       0,     0,     0,     0,   494,     0,     0,     0,   185,     0,
       0,     0,   184,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   185,     0,     0,   185,
     184,     0,   589,     0,   588,     0,     0,   591,     0,     0,
     591,    68,     0,   191,   182,     0,     0,     0,     0,     0,
     852,     0,   912,     0,     0,   588,   590,     0,   191,   590,
     184,     0,     0,     0,     0,     0,   176,     0,     0,     0,
       0,   189,   181,     0,     0,     0,   191,     0,     0,     0,
     591,   189,     0,     0,     0,     0,     0,     0,   587,     0,
       0,   587,    67,     0,   182,     0,     0,     0,   184,     0,
     792,   591,     0,     0,     0,     0,   191,     0,     0,   182,
       0,     0,     0,     0,     0,     0,     0,     0,  1001,   588,
     588,   588,    68,     0,     0,   951,   184,   182,     0,     0,
       0,   587,   952,   953,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   191,     0,     0,     0,     0,   764,
       0,   764,   587,     0,   184,    68,    68,   182,   975,   976,
     580,     0,     0,     0,     0,   591,   591,   591,     0,     0,
     764,     0,   191,    67,   149,   150,   151,   152,   153,     0,
       0,     0,     0,  -431,     0,     0,     0,     0,   852,   998,
       0,     0,   185,     0,   154,   182,     0,     0,     0,     0,
     191,     0,   590,     0,     0,     0,    67,    67,     0,   977,
       0,     0,   590,     0,     0,     0,   587,   587,   587,     0,
       0,   763,     0,   182,     0,   189,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   589,     0,     0,   589,
       0,     0,   185,   189,     0,     0,   189,     0,     0,   590,
       0,   182,     0,     0,     0,     0,     0,   185,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   592,     0,     0,   185,     0,     0,     0,   589,
       0,   582,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    59,    60,    61,
     589,     0,    62,    63,     0,   185,     0,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,    59,    60,    61,   170,   171,    62,    63,     0,
     172,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   185,     0,     0,     0,     0,     0,     0,
       0,   499,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   589,   589,   589,     0,     0,     0,
       0,   185,     0,     0,     0,   523,   524,   525,     0,     0,
     526,     0,     0,   527,   528,   529,   530,     0,   532,   533,
     534,   535,     0,   537,   538,   539,   540,   541,   542,   185,
       0,     0,   546,   927,   580,   547,   548,   549,   550,   189,
     551,     0,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   590,     0,     0,   590,     0,     0,   189,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   189,     0,     0,   610,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   189,     0,     0,     0,   590,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   590,     0,     0,
       0,     0,   189,     0,     0,   582,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    59,    60,    61,     0,     0,    62,    63,   734,   735,
       0,     0,     0,     0,   681,   683,     0,     0,     0,     0,
     189,     0,   341,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   590,   590,   590,   712,   713,     0,   222,   189,   223,
     224,   225,   226,   227,   228,   229,   230,   231,     0,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       0,   243,     0,     0,     0,     0,   189,     0,     0,     0,
       0,     0,   251,     0,     0,     0,     0,     0,     0,     0,
     252,   253,   254,     0,   255,   256,   257,     0,     0,   258,
     259,   260,   261,   262,   263,   264,     0,   265,   266,     0,
     267,     0,     0,     0,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,     0,
       0,   680,     0,     0,   812,   813,   814,   815,     0,     0,
       0,   816,     0,     0,   817,     0,     0,     0,     0,   818,
       0,     0,   341,     0,     0,     0,   823,   824,     0,     0,
       0,    59,    60,    61,   825,     0,    62,    63,   826,     0,
       0,     0,   827,   342,   343,     0,   344,   222,   828,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   580,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       0,   243,     0,     0,     0,   244,   245,   246,   247,   248,
     249,   250,   251,     0,     0,     0,     0,     0,     0,     0,
     252,   253,   254,     0,   255,   256,   257,     0,     0,   258,
     259,   260,   261,   262,   263,   264,     0,   265,   266,     0,
     267,     0,     0,     0,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    59,    60,    61,     0,     0,    62,    63,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   220,     0,   582,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    59,    60,    61,   221,     0,
      62,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   924,     0,     0,     0,     0,     0,     0,     0,   929,
       0,   930,     0,   222,   931,   223,   224,   225,   226,   227,
     228,   229,   230,   231,     0,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,   243,     0,     0,
       0,   244,   245,   246,   247,   248,   249,   250,   251,     0,
       0,     0,     0,     0,     0,     0,   252,   253,   254,     0,
     255,   256,   257,     0,     0,   258,   259,   260,   261,   262,
     263,   264,     0,   265,   266,     0,   267,     0,     0,     0,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    59,    60,    61,
       0,     0,    62,    63,   149,   150,   151,   152,   153,     0,
       0,     0,     0,     0,   608,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   154,     0,     0,     0,   149,   150,
     151,   152,   153,     0,     0,     0,     0,  -431,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   482,     0,
       0,     0,   149,   150,   151,   152,   153,     0,     0,     0,
       0,     0,   875,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   482,     0,     0,     0,   149,   150,   151,   152,
     153,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   154,     0,     0,     0,
     149,   150,   151,   152,   153,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     482,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   797,     0,     0,     0,     0,   580,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,    59,    60,    61,   170,   171,    62,    63,     0,
     172,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,    59,    60,    61,   170,
     171,    62,    63,     0,   172,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
      59,    60,    61,   170,   171,    62,    63,     0,   172,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,    59,    60,    61,   170,   171,    62,
      63,     0,   172,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,    59,    60,
      61,   170,   171,    62,    63,     0,   172,   582,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    59,    60,    61,   341,     0,    62,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   342,   343,     0,
     344,   222,     0,   223,   224,   225,   226,   227,   228,   229,
     230,   231,     0,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     0,   243,     0,     0,     0,   244,
     245,   246,   247,   248,   249,   250,   251,     0,     0,     0,
       0,     0,     0,     0,   252,   253,   254,     0,   255,   256,
     257,     0,     0,   258,   259,   260,   261,   262,   263,   264,
       0,   265,   266,     0,   267,     0,     0,     0,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   221,     0,     0,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    59,    60,    61,     0,     0,
      62,    63,   222,     0,   223,   224,   225,   226,   227,   228,
     229,   230,   231,     0,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,   243,     0,     0,     0,
     244,   245,   246,   247,   248,   249,   250,   251,     0,     0,
       0,     0,     0,     0,     0,   252,   253,   254,     0,   255,
     256,   257,     0,     0,   258,   259,   260,   261,   262,   263,
     264,     0,   265,   266,     0,   267,     0,     0,     0,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   341,     0,
       0,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,    59,    60,    61,     0,
       0,    62,    63,   222,     0,   223,   224,   225,   226,   227,
     228,   229,   230,   231,     0,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,   243,     0,     0,
       0,   244,   245,   246,   247,   248,   249,   250,   251,     0,
       0,     0,     0,     0,     0,     0,   252,   253,   254,     0,
     255,   256,   257,     0,     0,   258,   259,   260,   261,   262,
     263,   264,     0,   265,   266,     0,   267,     0,     0,     0,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   936,   580,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   467,
       0,     0,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    59,    60,    61,
       0,     0,    62,    63,   222,   580,   223,   224,   225,   226,
     227,   228,   229,   230,   231,     0,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,   243,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   251,
       0,     0,     0,     0,     0,     0,     0,   252,   253,   254,
       0,   255,   256,   257,     0,     0,   258,   259,   260,   261,
     262,   263,   264,     0,   265,   266,   581,   267,     0,     0,
       0,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,     0,   582,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    59,    60,    61,     0,     0,    62,    63,
       0,     0,     0,     0,     0,     0,     0,     0,    59,    60,
      61,     0,     0,    62,    63,   341,   582,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,    59,    60,    61,     0,     0,    62,    63,     0,
     222,     0,   223,   224,   225,   226,   227,   228,   229,   230,
     231,     0,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,   243,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   251,     0,     0,     0,     0,
       0,     0,     0,   252,   253,   254,     0,   255,   256,   257,
       0,     0,   258,   259,   260,   261,   262,   263,   264,     0,
     265,   266,     0,   267,     0,     0,     0,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    59,    60,    61
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        17,    25,    19,    17,   315,    13,    14,    15,   108,   104,
     110,   624,    20,    21,    22,   104,   129,   199,   200,   201,
     334,   243,   440,   331,   129,   613,   129,    42,   847,    38,
     130,   334,    41,    50,    41,   319,    41,    17,   434,   826,
     193,   104,    44,    37,   627,     6,    56,    64,    89,    20,
      64,    17,    32,    33,    34,    35,    36,   903,   104,    15,
      44,    41,    86,    87,    52,    20,   129,   391,   318,    41,
     320,    24,    52,     6,    24,    23,    41,    41,    95,    42,
      21,    38,   106,    42,    41,     0,    49,   104,   105,   180,
      49,    24,    40,    23,    41,    18,    19,    23,    64,    13,
     117,   425,   426,    41,    51,   151,    37,    41,    37,    64,
      40,    37,   129,    51,    40,     3,     4,    51,    65,   301,
     104,    31,     6,     7,     8,   185,   186,    65,    17,    73,
      74,    65,     6,   811,    16,   531,    29,    30,   104,   149,
     150,   154,   155,    51,   931,   106,   187,    31,   736,   628,
     629,   997,    51,   155,    38,   102,   144,   123,   311,   650,
     651,    45,    46,   129,    48,   473,   985,   108,   102,   163,
     185,   186,   285,   106,   107,   593,   193,    50,   462,   188,
     285,   188,   285,   188,   772,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   790,   188,   180,
     181,   182,   630,     4,   185,   186,   188,   330,   331,   897,
     315,    10,   285,   188,   188,   330,   315,   180,   181,   182,
     180,   181,   182,   180,   181,   182,    38,   163,   185,   186,
      18,   125,   180,   181,   182,   334,   180,   181,   182,   656,
     657,    41,   315,    37,    92,    20,   319,    51,   112,   112,
     873,    51,   112,   659,   148,    38,    37,   211,   285,   213,
     214,   334,   180,   181,   182,   181,    56,   185,   186,    57,
     304,   180,   181,   182,    44,    41,   104,    65,   305,   176,
     177,   178,   179,   515,   311,   606,   313,    62,   315,    26,
      93,   318,   319,   320,   321,   613,    84,    37,   102,    76,
     624,   129,   102,   330,   331,    41,     0,   334,    41,   285,
     104,   624,    41,    41,   627,     9,    41,    11,    12,    41,
      14,    41,    41,   104,   180,   181,   182,    41,   103,    41,
      56,    57,    58,    59,    60,    61,    41,   313,    41,   315,
      66,    67,   318,   319,   320,   468,   180,   181,   182,    41,
     473,   185,   186,   468,   330,    41,    41,   151,   334,   153,
      41,   155,    41,   339,   437,    41,    41,   440,   774,   163,
     151,    41,   153,   188,   155,   188,   180,   181,   182,   452,
     180,   181,   182,   342,   343,   344,   180,   181,   182,   462,
     508,   509,   510,   511,   512,   513,    41,    41,    41,   180,
     181,   182,    41,   188,   431,    41,   382,    41,   188,   837,
     437,   105,    41,   440,    41,    41,   648,    41,   736,    41,
     738,    41,   116,   117,    41,   452,    41,    41,    41,    41,
       6,    41,    41,    41,   128,   462,   130,   131,   132,    41,
      41,   468,    41,    41,    41,    41,   473,    41,    41,   877,
      40,    25,    37,    91,   772,    18,   180,   285,   104,   155,
      44,   437,   868,     6,   440,    53,    26,    38,   874,    44,
     898,    41,    54,    42,    42,    55,   452,   790,    67,   104,
      42,    42,    49,    42,    49,    49,   462,   315,    42,    42,
     613,   319,   468,   104,    49,    42,    42,    49,    49,    49,
      42,   606,    42,    42,    42,    42,   334,   606,    42,    42,
     583,    42,    42,    49,    49,    42,    42,   923,   129,    42,
     593,    49,    42,    42,    42,   624,    42,   503,   627,    42,
      62,    63,    49,   606,   962,   963,   964,    42,    49,    42,
      42,    42,   855,    42,    42,    49,    42,    42,    42,   873,
     155,   624,    30,     0,   627,    29,   583,   630,    42,    50,
     873,   167,     9,   167,    11,    12,   593,    14,   974,   975,
      17,    42,    42,    50,    21,    22,    49,    41,    53,   606,
     607,    41,    49,   607,    42,    42,   613,    49,    42,   995,
      42,    77,    39,   620,    49,    37,    42,   624,    42,    42,
     627,   628,   629,   630,    42,    42,    42,   583,    42,   437,
      40,    42,   440,   736,    42,    56,    42,   593,    42,   104,
     941,    50,    91,    38,   452,    64,    49,    49,    47,    42,
     606,   607,   104,    23,   462,    42,   597,   613,   170,   171,
     172,   173,   174,   175,   620,   443,   834,   599,   624,   772,
     131,   627,   628,   629,   630,   583,   969,   446,   105,   837,
     484,   593,   285,   610,   473,   736,   468,   950,   618,   116,
     117,    89,   131,   619,   285,    53,    24,    75,   776,   769,
     363,   128,   830,   130,   131,   132,   838,   840,   967,   969,
     749,   790,   946,   948,   752,   640,   638,   652,   518,   518,
     933,    -1,    -1,    -1,   315,    -1,    -1,    -1,   319,   736,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   790,    -1,    -1,
      -1,    -1,   749,   334,   751,   752,   918,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   772,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   863,    -1,   583,   855,    -1,    -1,    -1,
     736,   834,    -1,   790,   837,   593,    -1,   840,    -1,    -1,
      -1,    -1,    -1,    -1,   873,    -1,    -1,    -1,   606,    -1,
      -1,    -1,   855,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   624,    -1,    -1,   627,
     873,    -1,   630,    -1,   877,    -1,    -1,   834,    -1,    -1,
     837,   838,    -1,   840,   790,    -1,    -1,    -1,    -1,    -1,
     847,    -1,   849,    -1,    -1,   898,   437,    -1,   855,   440,
     903,    -1,    -1,    -1,    -1,    -1,   941,    -1,    -1,    -1,
      -1,   452,   941,    -1,    -1,    -1,   873,    -1,    -1,    -1,
     877,   462,    -1,    -1,    -1,    -1,    -1,    -1,   834,    -1,
      -1,   837,   838,    -1,   840,    -1,    -1,    -1,   941,    -1,
     969,   898,    -1,    -1,    -1,    -1,   903,    -1,    -1,   855,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   998,   962,
     963,   964,   919,    -1,    -1,   919,   969,   873,    -1,    -1,
      -1,   877,   920,   921,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   941,    -1,    -1,    -1,    -1,   946,
      -1,   948,   898,    -1,   997,   952,   953,   903,   952,   953,
      43,    -1,    -1,    -1,    -1,   962,   963,   964,    -1,    -1,
     967,    -1,   969,   919,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,   985,   993,
      -1,    -1,   790,    -1,    52,   941,    -1,    -1,    -1,    -1,
     997,    -1,   583,    -1,    -1,    -1,   952,   953,    -1,   955,
      -1,    -1,   593,    -1,    -1,    -1,   962,   963,   964,    -1,
      -1,   967,    -1,   969,    -1,   606,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   834,    -1,    -1,   837,
      -1,    -1,   840,   624,    -1,    -1,   627,    -1,    -1,   630,
      -1,   997,    -1,    -1,    -1,    -1,    -1,   855,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   155,    -1,    -1,   873,    -1,    -1,    -1,   877,
      -1,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     898,    -1,   185,   186,    -1,   903,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
     188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   941,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   341,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   962,   963,   964,    -1,    -1,    -1,
      -1,   969,    -1,    -1,    -1,   365,   366,   367,    -1,    -1,
     370,    -1,    -1,   373,   374,   375,   376,    -1,   378,   379,
     380,   381,    -1,   383,   384,   385,   386,   387,   388,   997,
      -1,    -1,   392,    42,    43,   395,   396,   397,   398,   790,
     400,    -1,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   834,    -1,    -1,   837,    -1,    -1,   840,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   855,    -1,    -1,   467,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   873,    -1,    -1,    -1,   877,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   898,    -1,    -1,
      -1,    -1,   903,    -1,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,    -1,    -1,   185,   186,    27,    28,
      -1,    -1,    -1,    -1,   544,   545,    -1,    -1,    -1,    -1,
     941,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   962,   963,   964,   574,   575,    -1,    66,   969,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      -1,    90,    -1,    -1,    -1,    -1,   997,    -1,    -1,    -1,
      -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,   110,   111,    -1,   113,   114,   115,    -1,    -1,   118,
     119,   120,   121,   122,   123,   124,    -1,   126,   127,    -1,
     129,    -1,    -1,    -1,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,    -1,
      -1,    20,    -1,    -1,   664,   665,   666,   667,    -1,    -1,
      -1,   671,    -1,    -1,   674,    -1,    -1,    -1,    -1,   679,
      -1,    -1,    41,    -1,    -1,    -1,   686,   687,    -1,    -1,
      -1,   180,   181,   182,   694,    -1,   185,   186,   698,    -1,
      -1,    -1,   702,    62,    63,    -1,    65,    66,   708,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    43,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      -1,    90,    -1,    -1,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,   110,   111,    -1,   113,   114,   115,    -1,    -1,   118,
     119,   120,   121,   122,   123,   124,    -1,   126,   127,    -1,
     129,    -1,    -1,    -1,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,    -1,    -1,   185,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,    41,    -1,
     185,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   871,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   879,
      -1,   881,    -1,    66,   884,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    90,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,
     113,   114,   115,    -1,    -1,   118,   119,   120,   121,   122,
     123,   124,    -1,   126,   127,    -1,   129,    -1,    -1,    -1,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
      -1,    -1,   185,   186,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    43,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
     188,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    -1,   188,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,   188,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,   188,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,   188,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,    41,    -1,   185,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,   110,   111,    -1,   113,   114,
     115,    -1,    -1,   118,   119,   120,   121,   122,   123,   124,
      -1,   126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,
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
     114,   115,    -1,    -1,   118,   119,   120,   121,   122,   123,
     124,    -1,   126,   127,    -1,   129,    -1,    -1,    -1,   133,
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
     113,   114,   115,    -1,    -1,   118,   119,   120,   121,   122,
     123,   124,    -1,   126,   127,    -1,   129,    -1,    -1,    -1,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
      -1,    -1,   185,   186,    66,    43,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    90,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,
      -1,   113,   114,   115,    -1,    -1,   118,   119,   120,   121,
     122,   123,   124,    -1,   126,   127,   104,   129,    -1,    -1,
      -1,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,    -1,    -1,   185,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,   185,   186,    41,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    -1,    -1,   185,   186,    -1,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    -1,    90,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,   110,   111,    -1,   113,   114,   115,
      -1,    -1,   118,   119,   120,   121,   122,   123,   124,    -1,
     126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,
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
     116,   117,   128,   130,   131,   132,   193,   236,   237,   252,
     254,   258,   294,   296,   297,   298,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   197,    13,
     299,   299,   299,   299,    37,   238,   253,   327,    20,   180,
     181,   182,   185,   186,   255,   256,   474,   475,   529,   530,
     238,   529,   299,   299,   299,    37,   328,   328,   327,    31,
     288,   289,   290,    17,   243,   295,     3,     4,   315,   319,
     320,    16,   198,   233,   529,     6,    24,   106,   107,   325,
     326,   325,   326,   329,   330,    23,    40,   259,   238,   474,
     238,    40,   264,   265,     6,   106,   323,   324,   323,   323,
     329,   369,   370,   371,   375,   376,    18,    19,   244,   245,
     238,    50,   292,   293,   327,   327,   316,   314,   320,   234,
     163,   199,   201,   202,    10,   300,   301,   529,    38,    32,
      33,    34,    35,    36,    52,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     183,   184,   188,   331,   339,   403,   459,   460,   462,   463,
     464,   473,   475,   476,   519,   523,   524,   525,   526,   527,
     528,   529,   531,    24,   260,   261,   262,   263,   529,   327,
     264,   257,   264,    92,   266,   267,   271,    37,   163,   342,
     344,   112,   529,   112,   112,    38,   475,    41,   188,   378,
      20,    41,    66,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    90,    94,    95,    96,    97,    98,    99,
     100,   101,   109,   110,   111,   113,   114,   115,   118,   119,
     120,   121,   122,   123,   124,   126,   127,   129,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   248,   249,   250,   251,   395,   475,   500,
     502,   504,   505,   506,   509,   512,   514,   519,   523,   527,
     529,   264,   195,   291,    21,   108,   317,   318,   321,   181,
      56,   200,   325,   461,   334,    44,   340,   341,   405,    41,
     404,    89,   187,   520,   521,   522,   263,   266,   266,   266,
      26,    93,   268,   274,   345,   323,   323,   323,   372,   377,
      37,    41,    62,    63,    65,   475,   477,   478,   481,   484,
     485,   488,   489,   495,   497,   498,   499,   500,   512,   517,
     519,   523,   527,   529,    76,    41,    41,    41,   188,   501,
      41,   188,   401,    41,    41,    41,    41,   507,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,   401,
      41,    41,    41,   188,   188,    41,    41,    41,    41,   188,
      41,   188,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,   249,    41,    41,   188,   396,   266,
     327,    24,   322,   529,    40,   235,    37,   104,   151,   153,
     155,   203,   204,   206,   207,   214,   216,   217,   224,   263,
      51,   408,   413,   474,   333,   335,   336,   331,   406,   407,
     408,   459,   465,   471,   473,   408,   529,    41,   272,   273,
     395,   475,   500,   275,   276,   394,   395,   499,   500,    25,
     269,   277,    52,   239,   240,   343,   346,   347,   350,   418,
     464,   466,   467,   469,   473,    37,    42,   475,   382,   477,
     498,   498,   498,    91,   246,   247,   480,   483,    56,    57,
      58,    59,    60,    61,    66,    67,   486,   487,   494,   496,
     396,   518,   510,   477,   477,   477,   477,   477,   477,   477,
     477,   508,   477,   477,   477,   477,   475,   477,   477,   477,
     477,   477,   477,    18,   398,   398,   477,   477,   477,   477,
     477,   477,   477,   477,   477,   477,   477,   477,   477,   477,
     477,   477,   477,   477,   477,   477,   477,   477,   477,   477,
     477,   477,   477,   477,   398,   398,   529,   342,   180,   225,
      43,   104,   164,   208,   209,   212,   383,   475,   519,   523,
     527,   529,   155,   218,   219,   222,   383,   207,   205,   217,
     215,    53,   414,   417,   471,    44,   332,     6,    42,   471,
     477,   273,   276,    26,    29,    30,   270,   283,   286,   287,
     468,   243,    38,   349,    44,   351,   352,    41,   420,   419,
     373,    38,    41,   188,   380,    42,   475,    42,    54,   479,
      55,   482,   488,   488,   488,   488,   488,   488,    67,   401,
      62,    63,   490,   493,   525,   526,    20,    64,   491,   511,
      42,    42,    42,   402,    49,    49,    49,    49,   342,    42,
      42,    49,    42,    42,    49,    42,    42,    42,    42,    49,
      20,   477,   513,   477,    42,    42,    49,    49,    42,    42,
      42,    42,    42,    42,    49,    42,    42,    42,    49,    42,
      42,    42,    49,    42,    42,    42,    42,    42,    49,    42,
      42,    42,   477,   477,    38,    41,   226,   212,   104,   222,
     155,   205,    44,   104,   210,   215,    44,   155,   220,   412,
     416,   331,   474,   247,    27,    28,   278,   279,   280,   281,
     282,   394,   475,   167,   167,   284,   287,   285,   286,    41,
      51,    65,   102,   423,   425,   431,   432,   437,   438,   442,
     446,   448,   450,   475,   529,   241,     6,     7,     8,    31,
      45,    46,    48,   125,   148,   348,   353,   354,   355,   357,
     361,   364,   367,   368,   384,   387,   388,   393,   347,   466,
     470,   472,   473,   421,   422,   423,   423,    38,   374,   383,
     381,   481,   484,   401,   495,   495,   491,   492,   497,   497,
     342,   400,   477,   477,   477,   477,   477,   477,   477,    42,
      50,   515,   516,   477,   477,   477,   477,   477,   477,    42,
     397,   227,   151,   213,   211,   154,   223,   221,    50,   411,
      49,   415,   337,    42,   279,   499,   437,    41,    51,   102,
     451,   457,   529,   446,    53,   424,   439,   443,    20,    62,
     103,   447,   449,   242,   358,   362,   365,   369,   356,   385,
     394,    41,   342,   332,   389,    42,   472,   379,    42,    49,
     399,    49,    42,    42,    49,    42,    42,   399,   503,    77,
      42,    42,    42,    42,   503,    42,    42,   400,   230,   209,
     219,   409,   410,   413,   417,    37,    42,   454,   456,   457,
      51,   458,   529,   433,   436,   472,   441,   445,   264,   359,
     363,   366,   342,   386,   477,   347,   342,    42,   383,   477,
     477,   477,    42,    56,    42,    42,    42,   229,   231,   383,
     414,   338,    42,   455,   430,   435,   104,   440,    64,   444,
     266,   474,   299,   299,   342,    91,   392,    42,   503,   528,
      49,   228,    56,   149,   150,   331,   453,    50,   429,    49,
     434,   442,   448,   288,   360,   474,   474,   475,    47,   390,
      42,   383,   383,   383,    38,   104,   452,   425,   426,   428,
     436,   342,   342,    23,    42,   391,   457,   427,   327,   342,
     414,   264
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
     289,   290,   290,   291,   292,   293,   293,   295,   294,   296,
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
     356,   355,   358,   359,   360,   357,   362,   363,   361,   365,
     366,   364,   367,   368,   369,   369,   371,   372,   370,   373,
     373,   374,   376,   375,   377,   377,   378,   378,   379,   379,
     381,   380,   380,   382,   382,   383,   383,   383,   383,   383,
     383,   383,   385,   386,   384,   388,   389,   387,   391,   390,
     392,   392,   393,   394,   394,   394,   395,   396,   397,   396,
     398,   398,   399,   400,   400,   401,   402,   401,   404,   403,
     405,   403,   406,   407,   407,   408,   409,   410,   410,   411,
     412,   412,   413,   413,   414,   415,   416,   416,   417,   419,
     418,   420,   418,   421,   422,   422,   424,   423,   425,   425,
     427,   426,   428,   428,   429,   430,   430,   431,   432,   433,
     434,   435,   435,   436,   437,   439,   438,   440,   441,   441,
     443,   442,   444,   445,   445,   446,   447,   447,   448,   448,
     449,   449,   449,   450,   450,   450,   450,   451,   451,   452,
     453,   453,   455,   454,   456,   456,   457,   457,   457,   458,
     458,   459,   459,   461,   460,   462,   463,   463,   463,   463,
     463,   464,   464,   465,   465,   466,   466,   468,   467,   469,
     470,   470,   471,   471,   472,   472,   473,   473,   474,   474,
     475,   475,   476,   476,   476,   476,   476,   476,   477,   478,
     479,   480,   480,   481,   482,   483,   483,   484,   485,   486,
     486,   487,   487,   487,   487,   487,   487,   487,   487,   488,
     489,   490,   490,   491,   491,   492,   492,   493,   493,   493,
     494,   494,   495,   496,   496,   497,   497,   497,   497,   498,
     498,   498,   498,   498,   498,   498,   498,   499,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   501,   501,   502,   503,   503,   504,   505,   507,
     508,   506,   510,   511,   509,   512,   512,   512,   513,   513,
     514,   514,   514,   514,   514,   515,   516,   516,   517,   518,
     518,   519,   520,   521,   521,   522,   522,   523,   523,   523,
     524,   524,   524,   525,   525,   525,   526,   526,   526,   527,
     527,   528,   528,   528,   528,   529,   529,   530,   530,   531,
     531
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
       2,     0,     1,     2,     2,     0,     1,     0,     3,     0,
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
       0,     3,     0,     0,     0,     6,     0,     0,     6,     0,
       0,     8,     6,     2,     1,     1,     0,     0,     6,     0,
       2,     1,     0,     5,     0,     2,     1,     3,     0,     2,
       0,     4,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     0,     0,     4,     0,     0,     4,     0,     3,
       0,     2,     2,     1,     1,     1,     2,     1,     0,     6,
       0,     1,     2,     0,     2,     1,     0,     5,     0,     3,
       0,     3,     1,     0,     1,     3,     2,     0,     1,     2,
       0,     2,     1,     1,     2,     2,     0,     2,     1,     0,
       3,     0,     3,     1,     0,     1,     0,     4,     1,     1,
       0,     3,     0,     1,     2,     0,     2,     1,     1,     2,
       2,     0,     2,     1,     1,     0,     3,     2,     0,     2,
       0,     3,     2,     0,     2,     2,     0,     1,     1,     2,
       1,     1,     1,     1,     1,     2,     3,     1,     3,     2,
       0,     2,     0,     3,     0,     1,     1,     1,     2,     1,
       1,     1,     1,     0,     4,     4,     1,     1,     1,     1,
       1,     0,     1,     1,     2,     1,     1,     0,     4,     4,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     0,     2,     2,     2,     0,     2,     1,     2,     0,
       1,     2,     2,     2,     2,     2,     2,     2,     3,     1,
       2,     1,     1,     2,     2,     0,     1,     2,     2,     2,
       0,     2,     2,     0,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     4,     4,
       6,     4,     4,     4,     4,     2,     2,     4,     4,     4,
       4,     2,     1,     4,     1,     4,     4,     4,     6,     6,
       6,     6,     6,     4,     4,     4,     4,     4,     4,     4,
       4,     2,     2,     2,     4,     4,     4,     4,     4,     2,
       8,     6,     6,     6,     4,     4,     4,     4,     4,     1,
       1,     1,     3,     1,     7,     0,     1,     7,     9,     0,
       0,     4,     0,     0,     5,     5,     5,     6,     1,     1,
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
  "IT_RAND", "IT_SHA512", "IT_NOW", "IT_TZ", "IT_TIMEZONE", "IT_ROUND",
  "IT_SHA384", "IT_BIND", "IT_CONTAINS", "IT_SECONDS", "IT_MOVE",
  "IT_FLOOR", "INSERTDATA", "DELETEDATA", "DELETEWHERE", "IT_MINUTES",
  "IT_SUBSTR", "IT_SHA256", "IT_HOURS", "IT_ENCODE_FOR_URI",
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
  "_Q_O_QIT_VALUES_E_S_QDataBlock_E_C_E_Opt", "Update",
  "_O_QGT_SEMI_E_S_QUpdate_E_C", "_Q_O_QGT_SEMI_E_S_QUpdate_E_C_E_Opt",
  "_O_QUpdate1_E_S_QGT_SEMI_E_S_QUpdate_E_Opt_C", "$@11",
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
  "@19", "@20", "ServiceGraphPattern", "@21", "@22", "SADIinvocation",
  "@23", "@24", "Bind", "InlineData", "DataBlock", "InlineDataOneVar",
  "$@25", "$@26", "_QSingleValueRow_E_Star", "SingleValueRow",
  "InlineDataFull", "$@27", "_QVar_E_Star",
  "_O_QNIL_E_Or_QGT_LPAREN_E_S_QVar_E_Star_S_QGT_RPAREN_E_C",
  "_QDataBlockValue_E_Star",
  "_O_QGT_LPAREN_E_S_QDataBlockValue_E_Star_S_QGT_RPAREN_E_Or_QNIL_E_C",
  "$@28",
  "_Q_O_QGT_LPAREN_E_S_QDataBlockValue_E_Star_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star",
  "DataBlockValue", "MinusGraphPattern", "@29", "@30",
  "GroupOrUnionGraphPattern", "@31", "@32",
  "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@33",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "@34", "_QIT_DISTINCT_E_Opt",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ExpressionList", "@35",
  "TriplesSameSubject", "$@36", "$@37", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "PropertyListNotEmpty",
  "_O_QVerb_E_S_QObjectList_E_C", "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "Verb",
  "ObjectList", "_O_QGT_COMMA_E_S_QObject_E_C",
  "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star", "Object",
  "TriplesSameSubjectPath", "$@38", "$@39", "PropertyListPath",
  "_QPropertyListPathNotEmpty_E_Opt", "PropertyListPathNotEmpty", "$@40",
  "_O_QVerbPath_E_Or_QVerbSimple_E_C",
  "_O_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_C", "$@41",
  "_Q_O_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_Opt_C_E_Star",
  "VerbPath", "VerbSimple", "ObjectListPath",
  "_O_QGT_COMMA_E_S_QObjectPath_E_C",
  "_Q_O_QGT_COMMA_E_S_QObjectPath_E_C_E_Star", "ObjectPath", "Path",
  "PathAlternative", "@42", "_O_QGT_PIPE_E_S_QPathSequence_E_C",
  "_Q_O_QGT_PIPE_E_S_QPathSequence_E_C_E_Star", "PathSequence", "@43",
  "_O_QGT_DIVIDE_E_S_QPathEltOrInverse_E_C",
  "_Q_O_QGT_DIVIDE_E_S_QPathEltOrInverse_E_C_E_Star", "PathElt",
  "_QPathMod_E_Opt", "PathEltOrInverse", "PathMod", "PathPrimary",
  "PathNegatedPropertySet", "_O_QGT_PIPE_E_S_QPathOneInPropertySet_E_C",
  "_Q_O_QGT_PIPE_E_S_QPathOneInPropertySet_E_C_E_Star",
  "_O_QPathOneInPropertySet_E_S_QGT_PIPE_E_S_QPathOneInPropertySet_E_Star_C",
  "@44",
  "_Q_O_QPathOneInPropertySet_E_S_QGT_PIPE_E_S_QPathOneInPropertySet_E_Star_C_E_Opt",
  "PathOneInPropertySet", "_O_Qiri_E_Or_QIT_a_E_C", "TriplesNode",
  "BlankNodePropertyList", "@45", "Generator",
  "_O_QIT_MEMBERS_E_Or_QIT_STARTS_E_Or_QIT_ENDS_E_Or_QIT_ANY_E_Or_QIT_UNORDERED_E_C",
  "_Q_O_QIT_MEMBERS_E_Or_QIT_STARTS_E_Or_QIT_ENDS_E_Or_QIT_ANY_E_Or_QIT_UNORDERED_E_C_E_Opt",
  "_QGraphNode_E_Plus", "TriplesNodePath", "BlankNodePropertyListPath",
  "@46", "GeneratorPath", "_QGraphNodePath_E_Plus", "GraphNode",
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
  "SubstringExpression", "StrReplaceExpression", "ExistsFunc", "@47",
  "@48", "NotExistsFunc", "@49", "@50", "Aggregate",
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
     104,    -1,   208,    -1,    -1,   104,   211,   209,    -1,   383,
     104,    -1,   151,    -1,   216,   217,   215,   223,    -1,   217,
     215,    44,    -1,    -1,   215,   220,    -1,   153,    -1,   155,
     219,    -1,   222,    -1,   218,   222,    -1,   155,    -1,   218,
      -1,    -1,   155,   221,   219,    -1,   383,   155,    -1,   154,
      -1,    37,   225,    38,    -1,    -1,   225,   226,    -1,    -1,
      41,   227,   230,    42,    -1,    -1,    49,    -1,   231,   228,
      -1,    -1,   230,   229,    -1,   383,   150,   383,    -1,   383,
     149,   383,    -1,   383,    56,   383,    -1,    15,   180,    -1,
      -1,    -1,    16,   234,   181,   235,   180,    -1,    -1,   237,
     243,   238,   264,   266,    -1,    -1,   238,   259,    -1,    -1,
      -1,    -1,   240,   243,   241,   242,   264,   266,   288,    -1,
      17,   245,   251,    -1,    18,    -1,    19,    -1,    -1,   244,
      -1,    91,   475,    -1,    -1,   246,    -1,    41,   477,   247,
      42,    -1,   500,    -1,   519,    -1,   523,    -1,   527,    -1,
     475,    -1,   512,    -1,   395,    -1,   248,    -1,   249,    -1,
     250,   249,    -1,   250,    -1,    20,    -1,    21,   253,    -1,
     327,   238,   264,   266,    -1,   238,    40,   327,   266,    -1,
      22,   256,   238,   257,   266,    -1,   474,    -1,   255,   474,
      -1,   255,    -1,    20,    -1,    -1,   264,    -1,    39,   238,
     264,   266,    -1,    23,   260,    -1,   261,    -1,   262,    -1,
     263,    -1,    24,   263,    -1,   529,    -1,   265,   342,    -1,
      -1,    40,    -1,   267,   268,   269,   270,    -1,    -1,   271,
      -1,    -1,   274,    -1,    -1,   277,    -1,    -1,   283,    -1,
      92,    26,   272,    -1,   273,    -1,   272,   273,    -1,   500,
      -1,   395,    -1,    41,   477,   247,    42,    -1,   475,    -1,
      93,   275,    -1,   276,    -1,   275,   276,    -1,   394,    -1,
      25,    26,   278,    -1,   279,    -1,   278,   279,    -1,   281,
      -1,   282,    -1,    27,    -1,    28,    -1,   280,   499,    -1,
     394,    -1,   475,    -1,   286,   284,    -1,   287,   285,    -1,
      -1,   287,    -1,    -1,   286,    -1,    29,   167,    -1,    30,
     167,    -1,   290,    -1,    31,   369,    -1,    -1,   289,    -1,
     195,   296,    -1,    50,   291,    -1,    -1,   292,    -1,    -1,
     297,   295,   293,    -1,    -1,   294,    -1,   298,    -1,   302,
      -1,   303,    -1,   305,    -1,   306,    -1,   307,    -1,   304,
      -1,   308,    -1,   309,    -1,   310,    -1,   311,    -1,     9,
     299,   529,   301,    -1,    -1,    13,    -1,    10,   325,    -1,
      -1,   300,    -1,    11,   299,   326,    -1,    14,   299,   326,
      -1,    12,   299,   325,    -1,   116,   299,   323,   112,   323,
      -1,   128,   299,   323,   112,   323,    -1,   117,   299,   323,
     112,   323,    -1,   130,   328,    -1,   131,   328,    -1,   132,
     327,    -1,   313,   315,   316,   318,    40,   342,    -1,   105,
     529,    -1,    -1,   312,    -1,    -1,   320,    -1,   319,   314,
      -1,   320,    -1,    -1,   316,   321,    -1,    21,   327,    -1,
      -1,   317,    -1,     3,   327,    -1,     4,   327,    -1,   108,
     322,    -1,   529,    -1,    24,   529,    -1,   106,    -1,   324,
     529,    -1,    -1,     6,    -1,     6,   529,    -1,   325,    -1,
     106,    -1,    24,    -1,   107,    -1,    37,   329,    38,    -1,
      37,   329,    38,    -1,    -1,   330,   331,   334,    -1,    -1,
     339,    -1,    -1,    44,    -1,   335,   332,   331,    -1,    -1,
     334,   333,    -1,    -1,    -1,    -1,   336,     6,   474,   337,
      37,   338,   331,    38,    -1,   403,   341,    -1,    44,   331,
      -1,    -1,   340,    -1,   344,    -1,   163,    -1,   239,    -1,
     346,    -1,    -1,    37,   345,   343,    38,    -1,   347,   349,
      -1,    -1,   350,    -1,   353,   332,   347,    -1,    -1,   349,
     348,    -1,   418,   352,    -1,    44,   347,    -1,    -1,   351,
      -1,   387,    -1,   355,    -1,   384,    -1,   357,    -1,   361,
      -1,   364,    -1,   393,    -1,   367,    -1,   368,    -1,   354,
      -1,   148,   342,    -1,    -1,    45,   356,   342,    -1,    -1,
      -1,    -1,     6,   358,   359,   474,   360,   342,    -1,    -1,
      -1,     7,   362,   363,   299,   474,   342,    -1,    -1,    -1,
       8,   365,   366,   299,   474,    23,   327,   264,    -1,   125,
      41,   477,    91,   475,    42,    -1,    31,   369,    -1,   370,
      -1,   375,    -1,    -1,    -1,   371,   475,   372,    37,   373,
      38,    -1,    -1,   373,   374,    -1,   383,    -1,    -1,   376,
     378,    37,   382,    38,    -1,    -1,   377,   475,    -1,   188,
      -1,    41,   377,    42,    -1,    -1,   379,   383,    -1,    -1,
      41,   381,   379,    42,    -1,   188,    -1,    -1,   382,   380,
      -1,   529,    -1,   519,    -1,   523,    -1,   527,    -1,    43,
      -1,   164,    -1,   475,    -1,    -1,    -1,    46,   385,   386,
     342,    -1,    -1,    -1,   388,   389,   342,   392,    -1,    -1,
      47,   391,   342,    -1,    -1,   392,   390,    -1,    48,   394,
      -1,   499,    -1,   500,    -1,   395,    -1,   529,   396,    -1,
     188,    -1,    -1,    41,   398,   477,   397,   400,    42,    -1,
      -1,    18,    -1,    49,   477,    -1,    -1,   400,   399,    -1,
     188,    -1,    -1,    41,   477,   402,   400,    42,    -1,    -1,
     473,   404,   408,    -1,    -1,   459,   405,   406,    -1,   407,
      -1,    -1,   408,    -1,   413,   414,   412,    -1,   413,   414,
      -1,    -1,   409,    -1,    50,   410,    -1,    -1,   412,   411,
      -1,   474,    -1,    51,    -1,   417,   416,    -1,    49,   417,
      -1,    -1,   416,   415,    -1,   471,    -1,    -1,   473,   419,
     423,    -1,    -1,   466,   420,   421,    -1,   422,    -1,    -1,
     423,    -1,    -1,   425,   424,   433,   430,    -1,   431,    -1,
     432,    -1,    -1,   425,   427,   414,    -1,    -1,   426,    -1,
      50,   428,    -1,    -1,   430,   429,    -1,   437,    -1,   475,
      -1,   436,   435,    -1,    49,   436,    -1,    -1,   435,   434,
      -1,   472,    -1,   438,    -1,    -1,   442,   439,   441,    -1,
     104,   442,    -1,    -1,   441,   440,    -1,    -1,   448,   443,
     445,    -1,    64,   448,    -1,    -1,   445,   444,    -1,   450,
     447,    -1,    -1,   449,    -1,   446,    -1,   102,   446,    -1,
     103,    -1,    20,    -1,    62,    -1,   529,    -1,    51,    -1,
      65,   451,    -1,    41,   437,    42,    -1,   457,    -1,    41,
     456,    42,    -1,   104,   457,    -1,    -1,   453,   452,    -1,
      -1,   457,   455,   453,    -1,    -1,   454,    -1,   529,    -1,
      51,    -1,   102,   458,    -1,   529,    -1,    51,    -1,   462,
      -1,   460,    -1,    -1,    52,   461,   408,    53,    -1,   464,
      41,   465,    42,    -1,    32,    -1,    33,    -1,    34,    -1,
      35,    -1,    36,    -1,    -1,   463,    -1,   471,    -1,   465,
     471,    -1,   469,    -1,   467,    -1,    -1,    52,   468,   423,
      53,    -1,   464,    41,   470,    42,    -1,   472,    -1,   470,
     472,    -1,   473,    -1,   459,    -1,   473,    -1,   466,    -1,
     475,    -1,   476,    -1,   475,    -1,   529,    -1,   185,    -1,
     186,    -1,   529,    -1,   519,    -1,   523,    -1,   527,    -1,
     531,    -1,   188,    -1,   478,    -1,   481,   480,    -1,    54,
     481,    -1,    -1,   480,   479,    -1,   484,   483,    -1,    55,
     484,    -1,    -1,   483,   482,    -1,   485,    -1,   488,   486,
      -1,    -1,   487,    -1,    56,   488,    -1,    57,   488,    -1,
      58,   488,    -1,    59,   488,    -1,    60,   488,    -1,    61,
     488,    -1,    67,   401,    -1,    66,    67,   401,    -1,   489,
      -1,   495,   494,    -1,   525,    -1,   526,    -1,    20,   497,
      -1,    64,   497,    -1,    -1,   491,    -1,    62,   495,    -1,
      63,   495,    -1,   490,   492,    -1,    -1,   494,   493,    -1,
     497,   496,    -1,    -1,   496,   491,    -1,    65,   498,    -1,
      62,   498,    -1,    63,   498,    -1,   498,    -1,   499,    -1,
     500,    -1,   517,    -1,   519,    -1,   523,    -1,   527,    -1,
     475,    -1,   512,    -1,    41,   477,    42,    -1,    78,    41,
     477,    42,    -1,    79,    41,   477,    42,    -1,    80,    41,
     477,    49,   477,    42,    -1,    81,    41,   477,    42,    -1,
      82,    41,   475,    42,    -1,    68,    41,   477,    42,    -1,
      69,    41,   477,    42,    -1,    70,   501,    -1,   118,   188,
      -1,   142,    41,   477,    42,    -1,   139,    41,   477,    42,
      -1,   129,    41,   477,    42,    -1,   123,    41,   477,    42,
      -1,    90,   401,    -1,   504,    -1,   145,    41,   477,    42,
      -1,   505,    -1,   143,    41,   477,    42,    -1,   141,    41,
     477,    42,    -1,   137,    41,   477,    42,    -1,   126,    41,
     477,    49,   477,    42,    -1,   138,    41,   477,    49,   477,
      42,    -1,   144,    41,   477,    49,   477,    42,    -1,   113,
      41,   477,    49,   477,    42,    -1,   114,    41,   477,    49,
     477,    42,    -1,   115,    41,   477,    42,    -1,   147,    41,
     477,    42,    -1,   140,    41,   477,    42,    -1,   136,    41,
     477,    42,    -1,   133,    41,   477,    42,    -1,   127,    41,
     477,    42,    -1,   122,    41,   477,    42,    -1,   121,    41,
     477,    42,    -1,   120,   188,    -1,   109,   188,    -1,   110,
     188,    -1,   111,    41,   477,    42,    -1,   146,    41,   477,
      42,    -1,   135,    41,   477,    42,    -1,   124,    41,   477,
      42,    -1,   119,    41,   477,    42,    -1,    71,   401,    -1,
      72,    41,   477,    49,   477,    49,   477,    42,    -1,    73,
      41,   477,    49,   477,    42,    -1,    74,    41,   477,    49,
     477,    42,    -1,    83,    41,   477,    49,   477,    42,    -1,
      84,    41,   477,    42,    -1,    85,    41,   477,    42,    -1,
      86,    41,   477,    42,    -1,    87,    41,   477,    42,    -1,
     101,    41,   477,    42,    -1,   502,    -1,   506,    -1,   509,
      -1,    41,   477,    42,    -1,   188,    -1,    88,    41,   477,
      49,   477,   503,    42,    -1,    -1,   399,    -1,   134,    41,
     477,    49,   477,   503,    42,    -1,    75,    41,   477,    49,
     477,    49,   477,   503,    42,    -1,    -1,    -1,    76,   507,
     508,   342,    -1,    -1,    -1,    66,    76,   510,   511,   342,
      -1,    94,    41,   398,   513,    42,    -1,   514,    41,   398,
     477,    42,    -1,    99,    41,   398,   477,   516,    42,    -1,
      20,    -1,   477,    -1,    95,    -1,    96,    -1,    97,    -1,
      98,    -1,   100,    -1,    50,    77,    56,   528,    -1,    -1,
     515,    -1,   529,   518,    -1,    -1,   396,    -1,   528,   522,
      -1,    89,   529,    -1,   187,    -1,   520,    -1,    -1,   521,
      -1,   524,    -1,   525,    -1,   526,    -1,   167,    -1,   168,
      -1,   169,    -1,   170,    -1,   171,    -1,   172,    -1,   173,
      -1,   174,    -1,   175,    -1,   165,    -1,   166,    -1,   176,
      -1,   178,    -1,   177,    -1,   179,    -1,   180,    -1,   530,
      -1,   182,    -1,   181,    -1,   183,    -1,   184,    -1
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
     394,   397,   398,   400,   403,   406,   407,   409,   410,   414,
     415,   417,   419,   421,   423,   425,   427,   429,   431,   433,
     435,   437,   439,   444,   445,   447,   450,   451,   453,   457,
     461,   465,   471,   477,   483,   486,   489,   492,   499,   502,
     503,   505,   506,   508,   511,   513,   514,   517,   520,   521,
     523,   526,   529,   532,   534,   537,   539,   542,   543,   545,
     548,   550,   552,   554,   556,   560,   564,   565,   569,   570,
     572,   573,   575,   579,   580,   583,   584,   585,   586,   595,
     598,   601,   602,   604,   606,   608,   610,   612,   613,   618,
     621,   622,   624,   628,   629,   632,   635,   638,   639,   641,
     643,   645,   647,   649,   651,   653,   655,   657,   659,   661,
     664,   665,   669,   670,   671,   672,   679,   680,   681,   688,
     689,   690,   699,   706,   709,   711,   713,   714,   715,   722,
     723,   726,   728,   729,   735,   736,   739,   741,   745,   746,
     749,   750,   755,   757,   758,   761,   763,   765,   767,   769,
     771,   773,   775,   776,   777,   782,   783,   784,   789,   790,
     794,   795,   798,   801,   803,   805,   807,   810,   812,   813,
     820,   821,   823,   826,   827,   830,   832,   833,   839,   840,
     844,   845,   849,   851,   852,   854,   858,   861,   862,   864,
     867,   868,   871,   873,   875,   878,   881,   882,   885,   887,
     888,   892,   893,   897,   899,   900,   902,   903,   908,   910,
     912,   913,   917,   918,   920,   923,   924,   927,   929,   931,
     934,   937,   938,   941,   943,   945,   946,   950,   953,   954,
     957,   958,   962,   965,   966,   969,   972,   973,   975,   977,
     980,   982,   984,   986,   988,   990,   993,   997,   999,  1003,
    1006,  1007,  1010,  1011,  1015,  1016,  1018,  1020,  1022,  1025,
    1027,  1029,  1031,  1033,  1034,  1039,  1044,  1046,  1048,  1050,
    1052,  1054,  1055,  1057,  1059,  1062,  1064,  1066,  1067,  1072,
    1077,  1079,  1082,  1084,  1086,  1088,  1090,  1092,  1094,  1096,
    1098,  1100,  1102,  1104,  1106,  1108,  1110,  1112,  1114,  1116,
    1119,  1122,  1123,  1126,  1129,  1132,  1133,  1136,  1138,  1141,
    1142,  1144,  1147,  1150,  1153,  1156,  1159,  1162,  1165,  1169,
    1171,  1174,  1176,  1178,  1181,  1184,  1185,  1187,  1190,  1193,
    1196,  1197,  1200,  1203,  1204,  1207,  1210,  1213,  1216,  1218,
    1220,  1222,  1224,  1226,  1228,  1230,  1232,  1234,  1238,  1243,
    1248,  1255,  1260,  1265,  1270,  1275,  1278,  1281,  1286,  1291,
    1296,  1301,  1304,  1306,  1311,  1313,  1318,  1323,  1328,  1335,
    1342,  1349,  1356,  1363,  1368,  1373,  1378,  1383,  1388,  1393,
    1398,  1403,  1406,  1409,  1412,  1417,  1422,  1427,  1432,  1437,
    1440,  1449,  1456,  1463,  1470,  1475,  1480,  1485,  1490,  1495,
    1497,  1499,  1501,  1505,  1507,  1515,  1516,  1518,  1526,  1536,
    1537,  1538,  1543,  1544,  1545,  1551,  1557,  1563,  1570,  1572,
    1574,  1576,  1578,  1580,  1582,  1584,  1589,  1590,  1592,  1595,
    1596,  1598,  1601,  1604,  1606,  1608,  1609,  1611,  1613,  1615,
    1617,  1619,  1621,  1623,  1625,  1627,  1629,  1631,  1633,  1635,
    1637,  1639,  1641,  1643,  1645,  1647,  1649,  1651,  1653,  1655,
    1657
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   508,   508,   511,   517,   522,   533,   534,   535,   536,
     540,   545,   549,   551,   555,   557,   560,   562,   566,   566,
     584,   590,   593,   597,   598,   599,   600,   606,   607,   610,
     612,   616,   620,   624,   625,   629,   630,   634,   634,   642,
     648,   652,   653,   656,   658,   662,   666,   670,   671,   675,
     676,   680,   680,   688,   694,   698,   701,   703,   707,   707,
     714,   716,   720,   723,   725,   729,   732,   735,   741,   747,
     749,   747,   759,   759,   771,   774,   782,   785,   789,   782,
     808,   816,   819,   826,   829,   834,   841,   844,   849,   856,
     859,   862,   865,   868,   871,   874,   878,   883,   886,   894,
     897,   903,   909,   914,   924,   932,   935,   943,   946,   953,
     956,   961,   969,   976,   977,   981,   987,   993,  1000,  1007,
    1009,  1014,  1021,  1024,  1029,  1032,  1037,  1040,  1045,  1049,
    1053,  1060,  1063,  1070,  1073,  1076,  1079,  1085,  1091,  1094,
    1101,  1106,  1113,  1117,  1125,  1127,  1135,  1138,  1146,  1154,
    1155,  1162,  1166,  1174,  1177,  1182,  1185,  1189,  1195,  1201,
    1205,  1211,  1214,  1218,  1224,  1227,  1229,  1233,  1233,  1240,
    1242,  1246,  1247,  1248,  1249,  1250,  1251,  1252,  1253,  1254,
    1255,  1256,  1260,  1266,  1269,  1276,  1283,  1286,  1290,  1296,
    1302,  1308,  1314,  1320,  1326,  1334,  1342,  1350,  1357,  1363,
    1366,  1370,  1373,  1377,  1381,  1388,  1391,  1400,  1406,  1409,
    1413,  1419,  1425,  1431,  1435,  1442,  1445,  1450,  1452,  1456,
    1462,  1465,  1468,  1471,  1478,  1485,  1491,  1491,  1499,  1501,
    1505,  1507,  1511,  1514,  1516,  1521,  1526,  1529,  1521,  1540,
    1544,  1547,  1549,  1553,  1554,  1567,  1568,  1573,  1573,  1584,
    1588,  1590,  1600,  1604,  1607,  1623,  1628,  1632,  1635,  1639,
    1640,  1641,  1642,  1643,  1644,  1645,  1646,  1647,  1650,  1654,
    1660,  1660,  1676,  1680,  1682,  1676,  1693,  1697,  1693,  1706,
    1710,  1706,  1727,  1738,  1744,  1745,  1749,  1751,  1749,  1758,
    1760,  1764,  1772,  1772,  1779,  1781,  1787,  1788,  1791,  1793,
    1799,  1799,  1804,  1810,  1812,  1816,  1819,  1822,  1825,  1828,
    1831,  1834,  1840,  1844,  1840,  1854,  1858,  1854,  1868,  1868,
    1880,  1882,  1886,  1896,  1897,  1898,  1902,  1910,  1914,  1914,
    1924,  1927,  1934,  1940,  1942,  1956,  1959,  1959,  1969,  1969,
    1972,  1972,  1978,  1981,  1983,  1988,  1993,  1997,  1999,  2004,
    2008,  2010,  2014,  2018,  2026,  2031,  2035,  2037,  2041,  2049,
    2049,  2052,  2052,  2058,  2061,  2063,  2067,  2067,  2073,  2074,
    2078,  2078,  2083,  2085,  2089,  2092,  2094,  2098,  2107,  2113,
    2117,  2120,  2122,  2126,  2133,  2137,  2137,  2147,  2153,  2156,
    2162,  2162,  2172,  2178,  2181,  2187,  2193,  2196,  2200,  2201,
    2207,  2210,  2213,  2219,  2222,  2225,  2228,  2234,  2235,  2241,
    2247,  2250,  2256,  2256,  2266,  2269,  2273,  2276,  2279,  2285,
    2288,  2296,  2297,  2301,  2301,  2314,  2342,  2345,  2348,  2351,
    2354,  2361,  2364,  2369,  2373,  2380,  2381,  2385,  2385,  2397,
    2424,  2428,  2435,  2436,  2440,  2441,  2445,  2448,  2452,  2455,
    2461,  2462,  2466,  2469,  2472,  2475,  2478,  2479,  2485,  2490,
    2499,  2506,  2509,  2517,  2526,  2533,  2536,  2543,  2548,  2561,
    2565,  2569,  2573,  2577,  2581,  2585,  2589,  2593,  2597,  2604,
    2609,  2618,  2621,  2628,  2631,  2638,  2641,  2646,  2649,  2653,
    2667,  2670,  2678,  2687,  2690,  2697,  2700,  2703,  2706,  2710,
    2711,  2712,  2713,  2716,  2719,  2722,  2725,  2729,  2735,  2738,
    2741,  2744,  2747,  2750,  2753,  2757,  2760,  2763,  2766,  2769,
    2772,  2775,  2778,  2779,  2782,  2783,  2786,  2789,  2792,  2795,
    2798,  2801,  2804,  2807,  2810,  2813,  2816,  2819,  2822,  2825,
    2828,  2831,  2834,  2837,  2840,  2843,  2846,  2849,  2852,  2855,
    2858,  2861,  2864,  2867,  2870,  2873,  2876,  2879,  2882,  2885,
    2886,  2887,  2893,  2896,  2903,  2910,  2913,  2917,  2923,  2929,
    2932,  2929,  2944,  2947,  2944,  2960,  2964,  2969,  2978,  2981,
    2985,  2988,  2991,  2994,  2997,  3003,  3009,  3012,  3016,  3026,
    3029,  3034,  3042,  3049,  3053,  3061,  3065,  3069,  3070,  3071,
    3075,  3076,  3077,  3081,  3082,  3083,  3087,  3088,  3089,  3093,
    3094,  3098,  3099,  3100,  3101,  3105,  3106,  3110,  3111,  3115,
    3116
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
  const int SPARQLfedParser::yylast_ = 2716;
  const int SPARQLfedParser::yynnts_ = 343;
  const int SPARQLfedParser::yyempty_ = -2;
  const int SPARQLfedParser::yyfinal_ = 11;
  const int SPARQLfedParser::yyterror_ = 1;
  const int SPARQLfedParser::yyerrcode_ = 256;
  const int SPARQLfedParser::yyntokens_ = 189;

  const unsigned int SPARQLfedParser::yyuser_token_number_max_ = 443;
  const SPARQLfedParser::token_number_type SPARQLfedParser::yyundef_token_ = 2;


} // w3c_sw

/* Line 1136 of lalr1.cc  */
#line 6206 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 3122 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


