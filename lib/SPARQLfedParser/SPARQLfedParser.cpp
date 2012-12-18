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
#line 348 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"

/* Line 299 of lalr1.cc  */
#line 515 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

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
#line 529 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 532 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 543 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 587 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.startBindingSet();
      }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 590 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 605 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = (yysemantic_stack_[(2) - (1)].p_RSName);
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 611 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = NULL;
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 621 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	throw std::runtime_error("need to partition out results set part of SimpleEngine::loadDataOrResults");
    }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 655 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 657 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 663 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 701 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 703 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 709 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 728 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow(false);
      }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 730 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 750 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 753 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 756 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 762 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 768 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 770 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 772 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 780 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 783 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause);
	(yyval.p_Operation) = new Select((yysemantic_stack_[(5) - (2)].p_Project).distinctness, (yysemantic_stack_[(5) - (2)].p_Project).varSet, (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
	driver.countStar = (yysemantic_stack_[(5) - (1)].p_parentCountStar);
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 792 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 795 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 803 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
      }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 806 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 810 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 817 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 829 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 837 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 840 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 847 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 855 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 862 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 870 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 877 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 880 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 883 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 886 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 889 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 892 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 895 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 904 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 907 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 915 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 918 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 924 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(2) - (2)].p_Operation);
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 930 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.lastWhereClause = (yysemantic_stack_[(4) - (3)].p_WhereClause);
	  /* $1 is NO LONGER known to be a DefaultGraphPattern because of grammar restrictions. */
	  (yyval.p_Operation) = new Construct((yysemantic_stack_[(4) - (1)].p_TableOperation), (yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
      }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 935 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	SWObjectDuplicator dup(driver.atomFactory);
	(yysemantic_stack_[(4) - (3)].p_TableOperation)->express(&dup);
	driver.lastWhereClause = new WhereClause((yysemantic_stack_[(4) - (3)].p_TableOperation));
	(yyval.p_Operation) = new Construct(dup.last.tableOperation, (yysemantic_stack_[(4) - (1)].p_DatasetClauses), driver.lastWhereClause, (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 945 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause) ? (yysemantic_stack_[(5) - (4)].p_WhereClause) : new WhereClause(new DefaultGraphPattern());
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 953 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm))));
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 956 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_TTerm))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 964 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 967 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 974 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 982 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(4) - (3)].p_WhereClause);
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 990 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1002 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1008 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1014 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1021 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.ensureGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1035 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1042 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1050 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1058 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1066 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1074 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1081 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1084 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1091 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1094 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1097 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1100 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1106 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1112 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1115 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1127 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1134 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1138 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1148 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1156 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1159 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1167 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1176 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1183 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1187 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1195 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1203 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1210 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1216 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1226 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = (yysemantic_stack_[(2) - (2)].p_BindingClause);
    }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1232 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1239 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Operation) = driver.root;
      }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1254 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	OperationSet* ret = driver.root ? dynamic_cast<OperationSet*>(driver.root) : new OperationSet();
	ret->push_back((yysemantic_stack_[(1) - (1)].p_Operation));
	driver.root = ret;
      }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1281 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(4) - (2)].p_Silence), (yysemantic_stack_[(4) - (3)].p_URI), (yysemantic_stack_[(4) - (4)].p_URI));
    }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1287 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1290 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1297 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1304 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1311 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1317 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1323 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1329 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1335 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1341 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1347 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.inINSERTDATA = true;
      }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1349 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.inINSERTDATA = false;
	  (yyval.p_Operation) = new Insert((yysemantic_stack_[(3) - (3)].p_TableOperation), NULL);
	  driver.curOp = NULL;
	  driver.curBGP = NULL;
	}
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1358 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.inDELETEDATA = true;
      }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1360 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.inDELETEDATA = false;
	  (yyval.p_Operation) = new Delete(true, (yysemantic_stack_[(3) - (3)].p_TableOperation), NULL);
	  driver.curOp = NULL;
	  driver.curBGP = NULL;
	}
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1369 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.inDELETEWHERE = true;
      }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1371 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.inDELETEWHERE = false;
	  (yyval.p_Operation) = new Delete(true, (yysemantic_stack_[(3) - (3)].p_TableOperation), NULL);
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1380 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(6) - (2)].p_DeleteInsert).del, (yysemantic_stack_[(6) - (2)].p_DeleteInsert).ins, new WhereClause(driver.ensureGraphPattern()), (yysemantic_stack_[(6) - (4)].p_TableOperation), (yysemantic_stack_[(6) - (1)].p_URI), (yysemantic_stack_[(6) - (3)].p_UsingPairs));
	driver.curOp = NULL;
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1387 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1393 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1400 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1407 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1411 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1418 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_UsingPairs) = NULL;
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1421 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (1)].p_UsingPairs) == NULL)
	    (yysemantic_stack_[(2) - (1)].p_UsingPairs) = new std::vector<s_UsingPair>();
	(yysemantic_stack_[(2) - (1)].p_UsingPairs)->push_back((yysemantic_stack_[(2) - (2)].p_UsingPair));
	(yyval.p_UsingPairs) = (yysemantic_stack_[(2) - (1)].p_UsingPairs);
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1430 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(2) - (2)].p_TableOperation);
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1436 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = NULL;
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1443 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.inDELETECLAUSE = true;
      }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 1445 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.inDELETECLAUSE = false;
	  (yyval.p_Delete) = new Delete(false, (yysemantic_stack_[(3) - (3)].p_TableOperation), NULL);
      }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 1452 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = new Insert((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 1458 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_UsingPair) = (yysemantic_stack_[(2) - (2)].p_UsingPair);
    }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 1464 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_UsingPair).named = false;
	(yyval.p_UsingPair).name = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 1468 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_UsingPair).named = true;
	(yyval.p_UsingPair).name = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 1475 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1478 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 1489 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 1495 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 1498 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = driver.atomFactory->getURI("tag:eric@w3.org,2012-swobjparm/DEFAULT");
    }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 1501 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = driver.atomFactory->getURI("tag:eric@w3.org,2012-swobjparm/NAMED");
    }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 1504 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = driver.atomFactory->getURI("tag:eric@w3.org,2012-swobjparm/ALL");
    }
    break;

  case 228:

/* Line 690 of lalr1.cc  */
#line 1511 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
	driver.curOp = NULL;
    }
    break;

  case 229:

/* Line 690 of lalr1.cc  */
#line 1518 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
    }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 1524 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 1526 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TableOperation) = driver.ensureGraphPattern();
	  driver.curOp = NULL;
      }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 1554 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 1559 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 1562 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 1565 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.ensureGraphPattern()));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 1587 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 251:

/* Line 690 of lalr1.cc  */
#line 1606 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 1608 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 1680 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_BindingClause)) : (yysemantic_stack_[(1) - (1)].p_BindingClause);
    }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 1687 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Print(driver.ensureGraphPattern());
    }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 1693 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 1697 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 276:

/* Line 690 of lalr1.cc  */
#line 1709 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 1713 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 1715 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 1718 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.ensureGraphPattern()));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 1726 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 1730 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 1732 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(6) - (5)].p_TTerm), driver.ensureGraphPattern(), (yysemantic_stack_[(6) - (4)].p_Silence), driver.atomFactory, false));
      }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 1739 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 1743 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 1745 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 286:

/* Line 690 of lalr1.cc  */
#line 1760 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Bind(driver.ensureGraphPattern(), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
	// no more triples go into the current BGP, per
	//   http://www.w3.org/TR/sparql11-query/#sparqlTranslateGraphPatterns
	// test reference:
	//   http://www.sparql.org/query-validator?query=ASK+{+%3Fs+%3Fp+%3Fo+FILTER+%281%29+BIND+%282+AS+%3Fb%29+%3Fs2+%3Fp2+%3Fo2+FILTER+%283%29+BIND+%284+AS+%3Fd%29}&languageSyntax=SPARQL&outputFormat=algebra&linenumbers=false
	driver.curBGP = NULL;
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 1771 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = (yysemantic_stack_[(2) - (2)].p_BindingClause);
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 1782 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 1784 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
      }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 1786 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 1797 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
	driver.endBindingRow();
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 1805 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 1807 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 1814 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 1826 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 1832 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 1834 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 1837 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 1849 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 1852 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 1855 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 1858 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 1861 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 1864 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 1867 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 1873 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 1877 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 1879 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 1887 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 1891 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 1893 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 1901 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 1906 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.ensureGraphPattern());
      }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 1919 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    driver.ensureGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 1935 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 1943 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 1947 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 1950 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yysemantic_stack_[(6) - (4)].p_Expressions);
      }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 1957 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 1960 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 1967 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 1975 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 1989 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 1992 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 1995 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(5) - (3)].p_Expressions);
      }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 2002 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 2005 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 2047 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 2051 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::RDF_type;
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 2074 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 2082 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 2085 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 2100 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 2111 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 2131 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	const URI* t = (yysemantic_stack_[(1) - (1)].p_PropertyPath)->release();
	// if (!t)
	//     w3c_sw_LINEN << "property path: " << $1->str() << "\n";
	(yyval.p_TTerm) = t ? t : (const TTerm*)new PropertyPath((yysemantic_stack_[(1) - (1)].p_PropertyPath));
    }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 2140 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 2159 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 2170 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = driver.lastPropertyPathAlternative;
	driver.lastPropertyPathAlternative = (yysemantic_stack_[(1) - (1)].p_PropertyPath);
      }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 2173 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (3)].p_PropertyPath) ? (yysemantic_stack_[(3) - (3)].p_PropertyPath) : (yysemantic_stack_[(3) - (1)].p_PropertyPath);
	  driver.lastPropertyPathAlternative = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
      }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 2180 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(2) - (2)].p_PropertyPath);
    }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 2186 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = NULL;
    }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 2189 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Alternative((yysemantic_stack_[(2) - (1)].p_PropertyPath) ? (yysemantic_stack_[(2) - (1)].p_PropertyPath) : driver.lastPropertyPathAlternative, (yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 2195 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = driver.lastPropertyPathSequence;
	driver.lastPropertyPathSequence = (yysemantic_stack_[(1) - (1)].p_PropertyPath);
      }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 2198 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {	
	  (yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (3)].p_PropertyPath) ? (yysemantic_stack_[(3) - (3)].p_PropertyPath) : (yysemantic_stack_[(3) - (1)].p_PropertyPath);
	  driver.lastPropertyPathSequence = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
      }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 2205 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(2) - (2)].p_PropertyPath);
    }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 2211 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = NULL;
    }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 2214 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Sequence((yysemantic_stack_[(2) - (1)].p_PropertyPath) ? (yysemantic_stack_[(2) - (1)].p_PropertyPath) : driver.lastPropertyPathSequence, (yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 2220 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(2) - (2)].p_RepeatRange).min == 1 && (yysemantic_stack_[(2) - (2)].p_RepeatRange).max == 1 ? (yysemantic_stack_[(2) - (1)].p_PropertyPath) : new PropertyPath::Repeated((yysemantic_stack_[(2) - (1)].p_PropertyPath), (yysemantic_stack_[(2) - (2)].p_RepeatRange).min, (yysemantic_stack_[(2) - (2)].p_RepeatRange).max);
    }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 2226 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RepeatRange).min = 1; (yyval.p_RepeatRange).max = 1;
    }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 2234 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Inverse((yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 2240 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RepeatRange).min = 0; (yyval.p_RepeatRange).max = 1;
    }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 2243 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RepeatRange).min = 0; (yyval.p_RepeatRange).max = PropertyPath::Repeated::Unlimited;
    }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 2246 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RepeatRange).min = 1; (yyval.p_RepeatRange).max = PropertyPath::Repeated::Unlimited;
    }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 2252 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 2255 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate(TTerm::RDF_type);
    }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 2258 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Negated((yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 2261 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
    }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 2268 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
    }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 2274 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(2) - (2)].p_PropertyPath);
    }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 2280 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = NULL;
    }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 2283 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Alternative((yysemantic_stack_[(2) - (1)].p_PropertyPath) ? (yysemantic_stack_[(2) - (1)].p_PropertyPath) : driver.lastPropertyPathSetAlternative, (yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 2289 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = driver.lastPropertyPathSetAlternative;
	driver.lastPropertyPathSetAlternative = (yysemantic_stack_[(1) - (1)].p_PropertyPath);
      }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 2292 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.lastPropertyPathSetAlternative = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
	  (yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (3)].p_PropertyPath);
      }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 2299 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = NULL;
    }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 2306 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 2309 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate(TTerm::RDF_type);
    }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 2312 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Inverse((yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 2318 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 2321 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate(TTerm::RDF_type);
    }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 2334 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 2338 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 2347 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 430:

/* Line 690 of lalr1.cc  */
#line 2375 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 2378 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 2381 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 2384 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 2387 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 2394 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 2402 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 2406 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 2418 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 2422 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject;
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 2430 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 444:

/* Line 690 of lalr1.cc  */
#line 2457 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 2461 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 2478 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 2485 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 2488 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 2499 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 2502 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 2505 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 2508 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 2512 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::RDF_nil; // !!! new GraphTerm_rule5($1);
    }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 2523 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 2532 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 2539 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 2542 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 2550 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 2559 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 2566 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 2569 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 2581 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 473:

/* Line 690 of lalr1.cc  */
#line 2594 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = NULL;
    }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 2602 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 2606 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 2610 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 2614 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 2618 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 2622 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 2626 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 2630 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = true;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 2642 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 2651 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 2654 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 2661 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 2664 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 2671 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 2679 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 2682 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 2686 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 494:

/* Line 690 of lalr1.cc  */
#line 2700 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 2703 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 2711 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 2720 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 2723 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 2730 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 2733 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 2736 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 2746 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 2749 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 2752 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 2755 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 2762 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 2768 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 2771 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 2774 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 2777 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 2780 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 2783 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
      (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), new TTermExpression(driver.atomFactory->getURI(driver.getBase())), NULL));
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 2786 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
      (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), new TTermExpression(driver.atomFactory->getURI(driver.getBase())), NULL));
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 2790 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 2793 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 2796 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 2799 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ceil, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 2802 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 2805 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 2808 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 2812 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 2816 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 2819 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 2822 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 2825 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 2828 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 2831 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 2834 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 2837 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 2840 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 2843 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 2846 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 2849 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 2852 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 2855 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 2858 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 2861 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_tz, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 2864 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 2867 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_uuid, NULL, NULL, NULL));
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 2870 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_struuid, NULL, NULL, NULL));
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 2873 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 2876 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 2879 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 2882 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 2885 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 2888 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 2891 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 2894 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 2897 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 2900 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 2903 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 2906 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 2909 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 2912 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 2915 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 2926 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 2929 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 2936 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 2943 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 2950 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 2956 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_replace, (yysemantic_stack_[(9) - (3)].p_Expression), (yysemantic_stack_[(9) - (5)].p_Expression), (yysemantic_stack_[(9) - (7)].p_Expression))); // !! , $8
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 2962 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 2965 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 2969 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expression) = new ExistsExpression(driver.ensureGraphPattern());
	  driver.curOp = (yysemantic_stack_[(4) - (3)].p_TableOperation);
	  driver.countStar = (yysemantic_stack_[(4) - (2)].p_parentCountStar);
      }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 2977 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
      }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 2980 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 2984 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  // $$ = new ExistsExpression(false, driver.ensureGraphPattern());
	  (yyval.p_Expression) = new BooleanNegation(new ExistsExpression(driver.ensureGraphPattern()));
	  driver.curOp = (yysemantic_stack_[(5) - (4)].p_TableOperation);
	  driver.countStar = (yysemantic_stack_[(5) - (3)].p_parentCountStar);
      }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 2993 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 2997 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 3002 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  AggregateCall::ScalarVals svals;
	  if ((yysemantic_stack_[(6) - (5)].p_RDFLiteral) != NULL)
	      svals["separator"] = (yysemantic_stack_[(6) - (5)].p_RDFLiteral)->getLexicalValue();
	  (yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression), svals));
    }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 3011 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 3018 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 3021 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 3024 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 3027 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 3030 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 3036 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 3042 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 3049 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 3059 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 3067 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 3075 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 3082 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 3086 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 3094 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 690 of lalr1.cc  */
#line 4232 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -835;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        56,  -115,    82,  -835,  -835,  -835,   471,  -835,  -835,  -835,
    -835,  -835,    72,    72,    72,    72,    54,     4,  -835,   142,
      72,    72,    72,  -835,  -835,  -835,    64,  -835,    89,  -835,
    -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,
    -835,  -835,  -835,  -835,  -835,  -835,  -835,   122,    85,  -835,
     142,    50,   105,    50,  -835,    49,  -835,  -835,  -835,  -835,
    -835,  -835,  -835,  -835,   154,  -835,  -835,  -835,  -835,  -835,
      57,  -835,    43,    43,    43,    92,    92,    54,    -9,  -835,
    -835,  -835,   125,  -835,    65,  -835,    54,  -835,   129,  -835,
    -835,    59,  -835,   144,   142,  -835,  -835,  -835,  -835,  -835,
    -835,  -835,   136,  1185,    14,    54,  -835,    57,  -835,    29,
    -835,    90,     9,  -835,  -835,    95,   142,    97,   111,  -835,
    -835,  -835,  -835,  -835,  -835,    47,  -835,     0,  -835,  -835,
    -835,  1565,    57,    56,  -835,  -835,    54,  -835,    60,  -835,
    -835,    35,   169,  -835,  -835,  -835,   105,  -835,  -835,  -835,
    -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,
    -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,
    -835,  -835,  -835,  -835,  -835,  -835,  -835,   194,  -835,  -835,
    -835,  -835,   206,  -835,  -835,  -835,  -835,  -835,  -835,  -835,
    -835,  -835,   -41,  -835,  -835,   142,  -835,  -835,  -835,  -835,
    -835,    90,    90,    90,  -835,   223,  -835,   161,  -835,  -835,
    -835,  -835,  -835,    43,  -835,    43,    43,   220,  -835,  -835,
    -835,   230,  -835,  1996,   193,   234,   249,    12,    17,   251,
     255,   257,   267,  -835,   269,   271,   272,   274,   277,   278,
     288,   289,   292,   296,   300,    17,   304,  -835,  -835,  -835,
    -835,   305,  -835,   306,   160,   163,   308,   312,   313,   317,
     171,   319,   173,   321,   323,   324,   329,   333,   334,   338,
     339,   342,   344,   345,   354,   355,   363,   364,   374,   375,
     376,   378,   380,   382,   384,  -835,  -835,  2117,  -835,  -835,
    -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,   385,  -835,
    -835,  -835,    20,    90,   685,  -835,  -835,    54,    21,  -835,
     388,  -835,  -835,  -835,   113,  -835,   146,   423,  1185,  -835,
    -835,   146,  1826,   146,   142,  -835,  -835,  -835,  -835,  -835,
    -835,  -835,  -835,  2359,  2446,   357,  -835,  1159,  -835,  -835,
    -835,  -835,   393,    42,  -835,  1996,  2238,  2238,  2238,  -835,
     340,  -835,  -835,  -835,  -835,   341,  -835,  -835,  -835,  -835,
    -835,  -835,  -835,  -835,  -835,  -835,  -835,    20,  -835,  1996,
    1996,  1996,  -835,  -835,  1996,  -835,  -835,  1996,  1996,  1996,
    1996,  -835,  1996,  1996,  1996,  1996,    47,  1996,  1996,  1996,
    1996,  1996,  1996,  -835,   415,   415,  1996,  -835,  -835,  1996,
    1996,  1996,  1996,  -835,  1996,  -835,  1996,  1996,  1996,  1996,
    1996,  1996,  1996,  1996,  1996,  1996,  1996,  1996,  1996,  1996,
    1996,  1996,  1996,  1996,  1996,  1996,  1996,  1996,  -835,   415,
     415,  -835,  -835,  -835,  -835,   142,  -835,  -835,     9,   256,
    -835,   876,  -835,  -835,  1098,  -835,  -835,   331,  -835,  -835,
     282,  -835,  -835,  -835,  -835,   387,  1826,  -835,  -835,   394,
     435,  -835,  -835,  -835,  -835,  -835,  1209,  -835,  -835,  -835,
    -835,  1996,  2359,  -835,  -835,  -835,  -835,  2446,  -835,  -835,
    -835,  -835,  -835,   416,   147,  -835,  -835,  -835,    89,   405,
    -835,  -835,  -835,   400,   404,  -835,  -835,  -835,  -835,  -835,
    -835,  -835,    16,   406,  -835,  -835,  -835,    47,  -835,   408,
     397,   392,  1996,  1996,  1996,  1996,  1996,  1996,   386,    17,
    -835,  -835,   217,    44,  -835,  -835,  -835,   410,   412,   414,
    -835,   409,   413,   417,   420,     9,   419,   422,   421,   430,
     431,   425,   434,   437,   439,   442,   438,  -835,  1389,  1996,
     444,   447,   445,   446,   449,   454,   455,   456,   457,   459,
     453,   461,   462,   463,   458,   466,   467,   472,   468,   474,
     477,   478,   479,   481,   480,   484,   485,   486,  1996,  1996,
    -835,  -835,  -835,    78,  -835,  -835,  -835,  1130,  -835,  -835,
     361,  -835,  -835,  -835,  -835,  -835,  -835,  1130,  -835,  -835,
     389,  -835,    31,  -835,    -2,  -835,  -835,  -835,  -835,  -835,
    1185,   154,  -835,  -835,   340,  -835,  -835,  1686,   368,   370,
    -835,  -835,   429,   501,    71,  -835,  -835,    86,  1750,  -835,
    -835,  1850,    71,    71,   539,  -835,  -835,  -835,  -835,  -835,
    -835,  -835,  1996,  -835,  1996,  -835,  -835,  -835,  -835,  -835,
    -835,  -835,    17,  -835,  1996,  1996,    44,  -835,  -835,  -835,
    1996,  1996,  -835,     9,  -835,  -835,  -835,  -835,  1996,  1996,
    1996,  1996,  -835,  -835,  -835,  1996,  -835,  -835,  1996,  -835,
    -835,  -835,  -835,  1996,  -835,  -835,   498,   493,  -835,  -835,
    1996,  1996,  -835,  -835,  -835,  -835,  -835,  -835,  1996,  -835,
    -835,  -835,  1996,  -835,  -835,  -835,  1996,  -835,  -835,  -835,
    -835,  -835,  1996,  -835,  -835,  -835,   503,  -835,  -835,  -835,
    -835,  -835,  -835,  -835,  -835,   -42,  -835,  -835,  -835,    81,
    -835,  -835,  -835,   496,   499,  -835,  -835,   507,  -835,  -835,
    1686,  -835,   509,  -835,  -835,  -835,  -835,  -835,  -835,  -835,
    -835,  -835,  -835,    62,  -835,   104,   101,   502,  -835,  -835,
    -835,  -835,  -835,  -835,  -835,  -835,    68,  -835,  -835,  -835,
    -835,  -835,  -835,    -9,  -835,  -835,  2446,   510,     9,  -835,
     394,  -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,
    -835,  -835,  -835,  -835,  1802,  -835,  -835,  -835,  -835,  -835,
    -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,
    -835,  -835,  -835,  -835,  -835,    41,   505,   516,   519,   517,
     525,   527,   524,  -835,   475,  -835,   533,   536,   537,   541,
     524,   543,   544,  -835,  -835,  -835,  -835,  -835,   876,  -835,
    -835,  1098,   146,  -835,  1826,  -835,   552,  -835,  -835,  -835,
     548,    96,  -835,   162,  -835,  -835,  -835,  -835,  -835,  1850,
    -835,  -835,  -835,  -835,  -835,  -835,  -835,   551,  -835,  -835,
    -835,  -835,     9,  -835,  -835,  1996,  -835,  1750,     9,  -835,
    -835,   576,  -835,  1996,  -835,  1996,  -835,  -835,  1996,  -835,
    -835,  -835,   550,   540,  -835,  -835,  -835,  -835,   553,  -835,
    -835,    58,   845,  -835,  -835,  -835,  -835,  1826,  -835,  -835,
    -835,  -835,   556,  -835,  -835,  -835,  -835,  -835,  -835,  -835,
     500,   542,    90,   154,    72,    72,  -835,     9,   490,  -835,
    -835,  -835,  -835,  -835,   563,   524,  -835,    84,  -835,  -835,
    -835,  -835,   559,    11,  -835,  1185,  -835,  -835,   560,   564,
      62,  -835,    62,  -835,    64,  -835,   154,   154,  -835,    47,
     562,  -835,   570,  -835,  -835,  -835,  1130,  1130,  1130,   582,
     518,    71,  -835,  1850,  -835,  -835,  -835,  -835,     9,     9,
     600,   583,  -835,  -835,  -835,  -835,  -835,  -835,  -835,    96,
    -835,  -835,  -835,  -835,  -835,  -835,  -835,    54,  -835,     9,
    -835,  1826,   551,  -835,  -835,  -835
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        12,     0,     0,     2,     4,     3,   202,    14,    13,    10,
      68,     1,   183,   183,   183,   183,    74,     0,    74,     0,
     183,   183,   183,   194,   196,   198,   161,     6,     0,     7,
       8,     9,   170,   163,   167,   171,   172,   173,   177,   174,
     175,   176,   178,   179,   180,   181,   203,     0,    16,   184,
       0,     0,     0,     0,   230,     0,   101,    74,   108,   619,
     622,   621,   454,   455,   107,    74,   105,   452,   453,   620,
     119,   201,   221,   221,   221,     0,     0,     0,   290,     5,
     162,   159,    83,    74,   165,   213,     0,   208,   204,   207,
      69,    11,    15,   186,     0,   226,   225,   227,   224,   188,
     190,   189,     0,   232,     0,     0,    75,   119,   106,   109,
     120,   122,     0,   222,   219,     0,     0,     0,     0,   230,
     195,   197,   199,   160,   288,     0,   289,     0,    81,    82,
      84,     0,   119,    12,   166,   168,     0,   215,   211,   206,
     205,     0,     0,    17,    22,    18,     0,   187,   182,   223,
     228,   430,   431,   432,   433,   434,   427,   613,   614,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   615,   617,
     616,   618,   623,   624,   461,   237,   233,   245,   344,   426,
     425,   436,     0,   342,   450,   451,   457,   458,   601,   602,
     603,   459,   599,   456,   460,     0,   112,   113,   114,   115,
     117,   122,   122,   122,   110,     0,   111,   124,   123,   251,
     248,   118,   247,   221,   220,   221,   221,     0,   291,   298,
     300,     0,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   573,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   584,   585,   586,
     587,     0,   588,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    99,    80,    95,
      93,    89,   563,   526,   528,   564,   565,    94,     0,    90,
      91,    92,     0,   122,   202,   164,   214,     0,     0,   212,
       0,   209,    70,    20,     0,   185,     0,   231,   232,   246,
     243,   347,   435,     0,     0,   597,   598,   600,   595,   116,
     103,   102,   104,     0,     0,   126,   125,   254,   191,   193,
     192,   229,     0,     0,   307,     0,     0,     0,     0,   509,
      86,   462,   465,   469,   471,   473,   483,   494,   497,   502,
     503,   504,   510,   505,   506,   507,   508,   593,   576,     0,
       0,     0,   567,   519,     0,   339,   553,     0,     0,     0,
       0,   574,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   525,   334,   334,     0,   546,   547,     0,
       0,     0,     0,   520,     0,   545,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    98,   334,
     334,   331,   330,    73,   210,     0,   216,   217,     0,     0,
      56,     0,    31,    45,     0,    19,    23,     0,    29,    24,
       0,    43,    25,    26,   357,     0,   435,   356,   238,   234,
       0,   244,   345,   346,   348,   447,   435,   437,   446,   343,
     596,     0,   130,   131,   134,   136,   133,   137,   138,   140,
     329,   327,   328,     0,   128,   127,   441,   249,     0,     0,
     250,   257,   255,   261,     0,   365,   440,   439,   363,   293,
     301,   299,     0,     0,   500,   501,   499,     0,    87,     0,
     463,   467,     0,     0,     0,     0,     0,     0,     0,     0,
     472,   474,   484,   496,   594,   592,   577,     0,     0,     0,
     340,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   335,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     218,   200,    71,     0,   313,    35,   314,    36,    32,    33,
       0,   315,   310,   311,   312,   309,    49,    50,    46,    47,
       0,    29,     0,    43,     0,   428,   354,   360,   362,   235,
     232,     0,   429,   438,    86,   132,   139,     0,     0,     0,
     121,   129,   153,   155,     0,    77,   252,   319,   254,   262,
     259,   435,   368,     0,     0,   297,   304,   306,   308,   511,
      85,    88,     0,   466,     0,   470,   475,   476,   477,   478,
     479,   480,     0,   481,     0,     0,   489,   495,   485,   486,
       0,     0,   498,     0,   517,   518,   566,   337,     0,     0,
       0,     0,   575,   512,   513,     0,   515,   516,     0,   558,
     559,   560,   561,     0,   582,   583,     0,   590,   562,   548,
       0,     0,   537,   552,   544,   543,   524,   551,     0,   542,
     523,   541,     0,   550,   540,   531,     0,   522,   539,   530,
     521,   529,     0,   527,   549,   538,     0,   332,    55,    58,
      57,    34,    39,    48,    53,     0,    28,    37,    30,     0,
      42,    51,    44,   349,   358,   236,   240,     0,   146,   147,
     141,   142,     0,   144,   145,   149,   150,   157,   158,   151,
     154,   152,   156,     0,   408,     0,     0,     0,   370,   372,
     373,   381,   388,   389,   402,   394,   400,   382,   407,    78,
     276,   280,   283,   290,   274,   316,     0,     0,     0,   258,
     234,   272,   264,   266,   267,   268,   270,   271,   265,   263,
     320,   269,   260,   449,   435,   444,   448,   366,   367,   369,
     364,   292,   294,   295,   302,   464,   468,   482,   491,   492,
     490,   493,   487,   488,   578,     0,     0,     0,     0,     0,
       0,     0,   569,   579,     0,   591,     0,     0,     0,     0,
     569,     0,     0,   580,   337,    63,    40,    27,     0,    54,
      41,     0,   351,   355,   435,   361,     0,   135,   143,   148,
       0,   418,   421,     0,   409,   411,   420,   403,   442,   435,
     392,   397,   405,   406,   404,   399,   401,   119,   277,   281,
     284,   287,     0,   317,   326,     0,   273,   254,     0,   443,
     445,     0,   341,     0,   338,     0,   555,   556,     0,   514,
     557,   570,     0,     0,   581,   535,   536,   532,     0,   533,
     534,     0,     0,    38,    52,   352,   353,   435,   359,   241,
     410,   419,     0,   416,   424,   422,   423,   379,   385,   387,
     390,   395,   122,     0,   183,   183,   275,     0,     0,   256,
     324,   305,   303,   336,     0,   569,   568,     0,   571,   333,
      59,    64,    60,     0,   350,   232,   412,   414,   371,   383,
       0,   393,     0,   398,   161,   278,     0,     0,   318,     0,
     321,   554,     0,   589,    61,    62,     0,     0,     0,     0,
     417,   376,   380,   435,   386,   391,   396,    79,     0,     0,
       0,     0,   322,   325,   572,    67,    66,    65,   242,     0,
     415,   374,   377,   378,   384,   279,   282,     0,   286,     0,
     413,   435,   119,   323,   375,   285
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -835,  -835,  -835,  -835,  -835,  -835,   491,  -835,  -835,  -835,
    -835,  -835,  -835,  -835,  -835,  -835,    25,  -835,   180,  -835,
    -210,  -835,  -835,    46,  -835,  -835,    26,  -835,   182,  -835,
    -211,  -835,  -835,    37,  -835,  -835,  -835,  -835,  -835,  -835,
    -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,    45,
    -835,  -835,  -835,  -835,   149,  -835,  -835,  -835,    27,  -835,
     351,  -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,
    -835,  -835,  -835,  -835,  -156,   -88,  -835,  -185,  -835,  -835,
    -835,  -835,  -835,  -835,   167,  -835,  -835,   165,  -835,  -835,
    -100,  -835,  -835,  -835,  -835,  -835,  -835,    23,    28,  -311,
    -835,  -835,   514,  -835,  -835,  -835,  -835,  -835,  -835,  -835,
      -8,  -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,
    -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,
    -835,  -835,  -835,  -835,  -835,   561,  -835,  -835,     5,  -835,
      24,   595,   -76,   577,   535,  -835,  -310,  -128,  -835,  -835,
    -835,  -835,  -835,  -835,  -835,  -835,  -835,  -415,  -835,  -835,
    -835,  -835,  -606,  -835,  -835,  -835,  -835,  -835,  -835,  -835,
    -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,
    -835,  -835,  -835,  -835,  -118,  -835,  -835,  -835,  -835,  -835,
    -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,  -435,  -835,
    -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,  -589,
     -96,   290,  -835,  -325,  -760,  -175,  -230,  -835,  -835,  -835,
    -835,  -835,  -835,  -200,  -835,  -835,  -835,  -835,  -182,  -834,
    -835,  -835,  -183,  -835,  -835,  -835,  -835,  -835,  -360,  -835,
    -307,  -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,  -835,
    -835,  -304,   -90,  -835,  -835,  -835,  -835,  -280,  -835,  -835,
    -835,   -85,  -835,  -279,  -835,  -835,  -835,  -835,  -835,  -835,
    -835,  -835,  -814,  -835,   -99,  -835,  -835,  -835,  -835,  -317,
    -835,  -303,  -835,  -835,  -835,  -835,  -286,  -601,   -92,   -14,
      34,  -835,   744,  -835,  -835,  -835,    32,  -835,  -835,    33,
    -835,  -835,  -835,  -103,  -835,  -835,    19,  -835,  -835,  -835,
    -367,  -835,  -358,  -208,  -308,  -104,  -835,  -835,  -787,  -835,
    -835,  -835,  -835,  -835,  -835,  -835,  -835,  -106,  -835,  -835,
    -835,  -835,  -835,  -835,   -72,  -835,  -835,  -835,   -63,  -835,
     156,   158,   235,  -256,   -17,  -835,  -835
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,    26,     5,     6,     7,    48,    91,
     143,   314,   144,   145,   445,   446,   602,   447,   448,   587,
     588,   728,   838,   589,   837,   449,   604,   450,   451,   597,
     598,   732,   841,   599,   840,   452,   583,   720,   835,   965,
     941,   902,   942,     8,    92,   141,   439,    27,    28,    55,
     487,   488,   769,   867,    83,   130,   131,   508,   509,   285,
     286,   287,   288,    29,    56,    30,    64,    65,   203,    31,
     106,   196,   197,   198,   199,   111,   112,   206,   207,   335,
     484,   620,   208,   472,   473,   336,   477,   478,   485,   740,
     741,   742,   743,   744,   621,   749,   751,   622,   623,    79,
      80,    81,     9,   134,   135,    32,    84,    33,    34,    35,
      50,   147,   148,    36,    37,    38,    39,    40,    41,    42,
      75,    43,    76,    44,    77,    45,    46,    47,   139,    87,
     138,   309,   310,    88,   136,    89,   311,   436,   115,   116,
      98,    99,    57,   120,   102,   103,   175,   610,   458,   317,
     459,   460,   846,   945,   176,   319,   320,   211,   489,   212,
     337,   490,   491,   779,   627,   492,   629,   630,   780,   781,
     782,   872,   783,   868,   923,   978,   784,   869,   924,   785,
     870,   925,   786,   787,   123,   124,   125,   342,   634,   802,
     126,   127,   343,   221,   881,   638,   804,   502,   590,   788,
     873,   927,   789,   790,   878,   983,   999,   960,   791,   479,
     480,   432,   834,   548,   891,   815,   376,   667,   177,   323,
     321,   462,   463,   455,   905,   906,   843,   733,   456,   606,
     845,   734,   607,   493,   633,   632,   797,   798,   757,   859,
     758,   992,  1001,   993,   972,   948,   759,   760,   917,   974,
     949,   918,   761,   762,   860,   951,   920,   763,   861,   953,
     921,   764,   865,   765,   866,   766,   854,   990,   970,   911,
     947,   912,   855,   915,   465,   179,   316,   180,   181,   182,
     466,   793,   496,   624,   497,   794,   608,   919,   468,   457,
     349,   185,   350,   351,   643,   510,   352,   645,   511,   353,
     354,   520,   521,   355,   356,   656,   662,   811,   657,   522,
     357,   523,   358,   359,   360,   361,   373,   292,   892,   293,
     294,   295,   381,   535,   296,   526,   663,   362,   686,   298,
     825,   826,   363,   525,   364,   326,   327,   328,   365,   188,
     189,   190,   366,   192,   367,    69,   194
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int SPARQLfedParser::yytable_ninf_ = -436;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        68,   122,    71,    66,   178,    51,    52,    53,   461,   600,
     137,   183,    72,    73,    74,   393,   330,   331,   332,   202,
     494,   204,   792,   581,    58,   297,   481,   291,   745,   201,
     795,   186,  -296,    93,   495,   289,   467,   913,   195,   329,
     187,   219,   730,   898,   303,   435,   209,    68,   324,   113,
     108,    67,   104,   371,   635,   884,    94,   636,   374,   299,
     306,   430,   727,    70,   660,    10,  -119,   966,   300,   110,
     549,     1,   104,   944,    95,   726,   100,   149,   117,   118,
     104,   307,    11,   882,   500,    49,   193,   200,   862,   105,
     883,    54,   770,   771,   772,    78,   -21,   110,    67,   214,
     939,    90,   107,   753,   578,   579,    82,   883,   661,   836,
     109,    94,   753,   754,   302,   133,   718,   773,   433,   719,
     672,   464,   754,   469,  -253,    85,    86,   755,   132,   119,
     863,   774,   775,    86,   776,   727,   755,   184,   504,   505,
     506,   884,   753,   128,   129,   851,   325,   852,   962,   114,
     440,   745,   754,   731,   146,   852,    96,    97,   453,   218,
     967,   968,   600,   -21,   756,   290,   755,  1004,   308,   481,
     315,   864,   210,   756,   150,  1000,   618,   619,   200,  -296,
     613,   297,   205,   291,    59,    60,    61,   874,   220,    62,
      63,   289,  -119,   880,    59,    60,    61,   454,   853,   803,
     372,    59,    60,    61,   637,   375,   853,   213,   431,   215,
     -21,   777,   -21,   914,   -21,   299,   312,   441,   338,   178,
     339,   340,   142,   216,   300,   313,   183,    62,    63,   476,
     482,   434,    62,    63,   778,   839,   731,   474,   318,   -21,
     -21,   -21,    59,    60,    61,   498,   186,   322,   814,   333,
     186,    59,    60,    61,   334,   187,    62,    63,   341,   187,
     168,   169,   170,   171,   442,   186,   443,   344,   444,   368,
     302,   929,   799,   800,   187,   369,    59,    60,    61,   654,
     655,    59,    60,    61,    59,    60,    61,   808,   809,   653,
     370,   437,   377,    59,    60,    61,   378,   200,   379,    68,
     735,   193,   812,   813,    68,   193,    68,   470,   380,   481,
     382,   494,   383,   384,   494,   385,   302,   302,   386,   387,
     193,   290,    59,    60,    61,   495,    59,    60,    61,   388,
     389,    62,    63,   390,    59,    60,    61,   391,   191,    62,
      63,   392,    59,    60,    61,   394,   395,   396,   397,   399,
      67,   398,   184,   400,   401,    67,   184,    67,   402,   403,
     404,   405,   406,   876,   407,   408,   301,   475,   476,   592,
     409,   184,   592,   482,   410,   411,   474,   501,   593,   412,
     413,   593,   483,   414,   186,   415,   416,   162,   163,   164,
     165,   166,   167,   187,   186,   417,   418,   512,   513,   514,
     515,   516,   517,   187,   419,   420,   600,   518,   519,   646,
     647,   648,   649,   650,   651,   421,   422,   423,   580,   424,
     540,   425,   807,   426,   595,   427,   429,   595,   438,  -239,
     499,   507,   481,   547,   849,   441,   582,   444,   609,   193,
     605,   611,   617,   626,   628,   631,   932,   644,   639,   193,
     641,   642,   664,   652,   665,   302,   666,   926,   668,   619,
     302,   673,   669,   930,   674,   722,   670,   943,   481,   671,
     675,  -169,   676,   677,   678,   591,   679,   494,   591,   680,
      12,   681,    13,    14,   682,    15,   688,   683,   -72,   689,
     184,   692,    16,    17,   690,   691,   693,   694,   695,   696,
     184,   697,   698,   699,   700,   701,   475,   702,   703,   704,
      18,   178,   958,   482,   705,   592,   707,   706,   183,   708,
     709,   710,   301,   711,   593,   592,   713,   714,   715,   712,
     618,   985,   986,   987,   593,   747,   498,   748,   186,   796,
     823,   640,   494,   824,   724,   833,   842,   187,   844,   847,
     345,   875,   893,   191,   885,   858,   186,   191,   886,   186,
     494,   887,   592,   995,   996,   187,   888,   889,   187,   890,
     595,   593,   191,   883,   495,   894,    19,   801,   895,   896,
     595,   959,   584,   897,  1003,   899,   900,    20,    21,   909,
     910,   110,   936,   193,    68,   938,   937,   736,   946,    22,
     302,    23,    24,    25,   950,   961,   952,   768,   964,   982,
     971,   193,   984,   973,   193,   768,   768,   595,   931,   584,
     988,   591,   989,   997,   304,   998,   725,   601,   903,   729,
     904,   591,   603,   721,   723,   969,   482,   625,   428,   615,
     848,   737,   616,   977,   184,    67,   752,   305,   101,   140,
     750,   746,   877,   121,   217,   871,   494,   524,   767,   901,
     907,   908,   184,   850,   991,   184,   767,   767,   591,   994,
     975,   857,   482,   976,   805,   810,   594,   806,   658,   594,
     659,   963,     0,     0,     0,  -169,     0,     0,     0,     0,
       0,   191,     0,     0,    12,     0,    13,    14,     0,    15,
       0,   191,   796,   586,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,    59,
      60,    61,   186,   302,    62,    63,     0,     0,     0,     0,
       0,   187,     0,     0,     0,     0,   768,   954,   856,   768,
     586,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    59,    60,    61,   302,
       0,    62,    63,     0,     0,     0,   592,   796,     0,   592,
       0,     0,   186,     0,   746,   593,     0,   193,   593,   922,
       0,   187,     0,     0,     0,   498,     0,   186,     0,     0,
      19,     0,     0,     0,     0,     0,   187,     0,     0,     0,
       0,    20,    21,     0,     0,   186,     0,     0,     0,   592,
       0,     0,     0,    22,   187,    23,    24,    25,   593,     0,
       0,   595,   594,     0,   595,    68,     0,   193,   184,     0,
     592,     0,   594,     0,   856,   186,   916,     0,     0,   593,
       0,     0,   193,     0,   187,   191,   178,     0,     0,     0,
       0,     0,     0,   183,     0,     0,     0,     0,     0,     0,
     193,     0,     0,   191,   595,     0,   191,     0,     0,   594,
       0,     0,   591,   186,     0,   591,    67,     0,   184,     0,
       0,   796,   187,     0,     0,   595,     0,   940,   584,     0,
     193,     0,     0,   184,   592,   592,   592,     0,     0,     0,
       0,   186,     0,   593,   593,   593,    68,     0,     0,   955,
     187,   184,     0,     0,  1005,   591,   956,   957,     0,   584,
       0,  1002,     0,     0,     0,     0,     0,     0,   193,   186,
       0,     0,     0,   768,     0,   768,   591,     0,   187,    68,
      68,   184,   979,   980,     0,     0,     0,     0,     0,   595,
     595,   595,     0,     0,   768,     0,   193,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   856,     0,     0,     0,     0,     0,     0,   184,
     585,     0,     0,     0,   193,     0,     0,     0,     0,     0,
      67,    67,     0,   981,     0,     0,     0,     0,     0,     0,
     591,   591,   591,     0,     0,   767,     0,   184,     0,   586,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    59,    60,    61,     0,   191,
      62,    63,     0,     0,     0,   184,     0,     0,     0,     0,
     586,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    59,    60,    61,     0,
       0,    62,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   594,     0,     0,   594,     0,     0,   191,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   503,
       0,     0,     0,     0,   191,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   191,   527,   528,   529,   594,     0,   530,     0,
       0,   531,   532,   533,   534,     0,   536,   537,   538,   539,
       0,   541,   542,   543,   544,   545,   546,   594,     0,     0,
     550,   584,   191,   551,   552,   553,   554,     0,   555,     0,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,     0,   584,     0,     0,   -76,     0,     0,     0,
     191,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   151,   152,   153,   154,   155,     0,     0,     0,     0,
    -435,   594,   594,   594,     0,     0,     0,     0,   191,     0,
       0,   486,     0,     0,     0,   614,     0,   151,   152,   153,
     154,   155,     0,     0,     0,     0,  -435,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   191,   156,     0,     0,
       0,   151,   152,   153,   154,   155,     0,     0,     0,     0,
       0,   612,     0,   596,     0,     0,     0,     0,     0,     0,
       0,   156,   586,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    59,    60,
      61,     0,     0,    62,    63,     0,     0,     0,     0,     0,
       0,     0,   685,   687,   586,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      59,    60,    61,     0,     0,    62,    63,     0,     0,     0,
       0,     0,   716,   717,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,    59,
      60,    61,   172,   173,    62,    63,     0,   174,     0,     0,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    59,    60,    61,   172,   173,
      62,    63,     0,   174,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,    59,
      60,    61,   172,   173,    62,    63,     0,   174,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   684,
       0,     0,   816,   817,   818,   819,     0,     0,     0,   820,
       0,     0,   821,     0,     0,     0,     0,   822,     0,     0,
     345,     0,     0,     0,   827,   828,     0,     0,     0,     0,
       0,     0,   829,     0,     0,     0,   830,     0,     0,     0,
     831,   346,   347,     0,   348,   224,   832,   225,   226,   227,
     228,   229,   230,   231,   232,   233,     0,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,     0,   245,
       0,     0,     0,   246,   247,   248,   249,   250,   251,   252,
     253,     0,     0,     0,     0,     0,     0,     0,   254,   255,
     256,     0,   257,   258,   259,     0,     0,   260,   261,   262,
     263,   264,   265,   266,     0,   267,   268,     0,   269,     0,
       0,     0,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,    59,
      60,    61,     0,     0,    62,    63,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   222,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   223,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   928,
       0,     0,     0,     0,     0,     0,     0,   933,     0,   934,
       0,   224,   935,   225,   226,   227,   228,   229,   230,   231,
     232,   233,     0,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,     0,   245,     0,     0,     0,   246,
     247,   248,   249,   250,   251,   252,   253,     0,     0,     0,
       0,     0,     0,     0,   254,   255,   256,     0,   257,   258,
     259,     0,     0,   260,   261,   262,   263,   264,   265,   266,
       0,   267,   268,     0,   269,     0,     0,     0,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   738,   739,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   345,     0,     0,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    59,    60,    61,     0,     0,
      62,    63,   224,     0,   225,   226,   227,   228,   229,   230,
     231,   232,   233,     0,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,     0,   245,     0,     0,     0,
       0,     0,   151,   152,   153,   154,   155,   253,     0,     0,
       0,  -435,     0,     0,     0,   254,   255,   256,     0,   257,
     258,   259,   486,     0,   260,   261,   262,   263,   264,   265,
     266,     0,   267,   268,     0,   269,     0,     0,     0,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   151,   152,   153,   154,   155,     0,
       0,     0,     0,     0,   879,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   486,     0,     0,     0,   151,   152,
     153,   154,   155,     0,     0,     0,    59,    60,    61,     0,
       0,    62,    63,     0,     0,     0,     0,     0,   156,     0,
       0,     0,   151,   152,   153,   154,   155,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   486,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      59,    60,    61,   172,   173,    62,    63,     0,   174,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    59,    60,    61,   172,   173,    62,    63,     0,
     174,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    59,    60,    61,   172,
     173,    62,    63,     0,   174,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      59,    60,    61,   172,   173,    62,    63,   345,   174,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   346,   347,
       0,   348,   224,     0,   225,   226,   227,   228,   229,   230,
     231,   232,   233,     0,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,     0,   245,     0,     0,     0,
     246,   247,   248,   249,   250,   251,   252,   253,     0,     0,
       0,     0,     0,     0,     0,   254,   255,   256,     0,   257,
     258,   259,     0,     0,   260,   261,   262,   263,   264,   265,
     266,     0,   267,   268,     0,   269,     0,     0,     0,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   223,     0,
       0,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    59,    60,    61,     0,
       0,    62,    63,   224,     0,   225,   226,   227,   228,   229,
     230,   231,   232,   233,     0,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,     0,   245,     0,     0,
       0,   246,   247,   248,   249,   250,   251,   252,   253,     0,
       0,     0,     0,     0,     0,     0,   254,   255,   256,     0,
     257,   258,   259,     0,     0,   260,   261,   262,   263,   264,
     265,   266,     0,   267,   268,     0,   269,     0,     0,     0,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   345,
       0,     0,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,    59,    60,    61,
       0,     0,    62,    63,   224,     0,   225,   226,   227,   228,
     229,   230,   231,   232,   233,     0,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,     0,   245,     0,
       0,     0,   246,   247,   248,   249,   250,   251,   252,   253,
       0,     0,     0,     0,     0,     0,     0,   254,   255,   256,
       0,   257,   258,   259,     0,     0,   260,   261,   262,   263,
     264,   265,   266,     0,   267,   268,     0,   269,     0,     0,
       0,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     471,     0,     0,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    59,    60,
      61,     0,     0,    62,    63,   224,     0,   225,   226,   227,
     228,   229,   230,   231,   232,   233,     0,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,     0,   245,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     253,     0,     0,     0,     0,     0,     0,     0,   254,   255,
     256,     0,   257,   258,   259,     0,     0,   260,   261,   262,
     263,   264,   265,   266,     0,   267,   268,   345,   269,     0,
       0,     0,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,     0,     0,     0,
       0,     0,   224,     0,   225,   226,   227,   228,   229,   230,
     231,   232,   233,     0,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,     0,   245,     0,     0,    59,
      60,    61,     0,     0,    62,    63,     0,   253,     0,     0,
       0,     0,     0,     0,     0,   254,   255,   256,     0,   257,
     258,   259,     0,     0,   260,   261,   262,   263,   264,   265,
     266,     0,   267,   268,     0,   269,     0,     0,     0,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    59,    60,    61
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        17,    77,    19,    17,   103,    13,    14,    15,   318,   444,
      86,   103,    20,    21,    22,   245,   201,   202,   203,   107,
     337,   109,   628,   438,    20,   131,   334,   131,   617,   105,
     631,   103,    41,    50,   337,   131,   322,   851,    24,   195,
     103,    41,    44,   830,   132,    24,    37,    64,    89,     6,
      64,    17,    23,    41,    38,   815,     6,    41,    41,   131,
     136,    41,   104,    18,    20,   180,    37,    56,   131,    40,
     395,    15,    23,   907,    24,    44,    52,    94,    73,    74,
      23,    21,     0,    42,    42,    13,   103,   104,    20,    40,
      49,    37,     6,     7,     8,    31,    37,    40,    64,   116,
      42,    16,    57,    41,   429,   430,    17,    49,    64,   151,
      65,     6,    41,    51,   131,    50,    38,    31,   303,    41,
     535,   321,    51,   323,    38,     3,     4,    65,    83,    37,
      62,    45,    46,     4,    48,   104,    65,   103,   346,   347,
     348,   901,    41,    18,    19,    41,   187,    51,   935,   106,
      37,   740,    51,   155,    10,    51,   106,   107,   314,   125,
     149,   150,   597,   104,   102,   131,    65,  1001,   108,   477,
     146,   103,   163,   102,    38,   989,    29,    30,   195,   188,
     466,   287,    92,   287,   180,   181,   182,   776,   188,   185,
     186,   287,   163,   794,   180,   181,   182,    51,   102,   634,
     188,   180,   181,   182,   188,   188,   102,   112,   188,   112,
     151,   125,   153,    51,   155,   287,   181,   104,   213,   318,
     215,   216,   163,   112,   287,    56,   318,   185,   186,   333,
     334,   307,   185,   186,   148,   154,   155,   333,    44,   180,
     181,   182,   180,   181,   182,   337,   318,    41,   663,    26,
     322,   180,   181,   182,    93,   318,   185,   186,    38,   322,
     176,   177,   178,   179,   151,   337,   153,    37,   155,    76,
     287,   877,   632,   633,   337,    41,   180,   181,   182,    62,
      63,   180,   181,   182,   180,   181,   182,   654,   655,   519,
      41,   308,    41,   180,   181,   182,    41,   314,    41,   316,
     610,   318,   660,   661,   321,   322,   323,   324,    41,   617,
      41,   628,    41,    41,   631,    41,   333,   334,    41,    41,
     337,   287,   180,   181,   182,   628,   180,   181,   182,    41,
      41,   185,   186,    41,   180,   181,   182,    41,   103,   185,
     186,    41,   180,   181,   182,    41,    41,    41,   188,    41,
     316,   188,   318,    41,    41,   321,   322,   323,    41,   188,
      41,   188,    41,   778,    41,    41,   131,   333,   472,   441,
      41,   337,   444,   477,    41,    41,   472,   343,   441,    41,
      41,   444,    25,    41,   456,    41,    41,   170,   171,   172,
     173,   174,   175,   456,   466,    41,    41,    56,    57,    58,
      59,    60,    61,   466,    41,    41,   841,    66,    67,   512,
     513,   514,   515,   516,   517,    41,    41,    41,   435,    41,
     386,    41,   652,    41,   441,    41,    41,   444,    40,     6,
      37,    91,   740,    18,   742,   104,   180,   155,    44,   456,
      53,     6,    26,    38,    44,    41,   881,    55,    42,   466,
      42,    54,    42,    67,    42,   472,    42,   872,    49,    30,
     477,    42,    49,   878,    42,   104,    49,   902,   776,    49,
      49,     0,    42,    42,    49,   441,    42,   794,   444,    42,
       9,    42,    11,    12,    42,    14,    42,    49,    17,    42,
     456,    42,    21,    22,    49,    49,    42,    42,    42,    42,
     466,    42,    49,    42,    42,    42,   472,    49,    42,    42,
      39,   610,   927,   617,    42,   587,    42,    49,   610,    42,
      42,    42,   287,    42,   587,   597,    42,    42,    42,    49,
      29,   966,   967,   968,   597,   167,   628,   167,   610,   631,
      42,   507,   859,    50,   155,    42,    50,   610,    49,    42,
      41,    41,    77,   318,    49,    53,   628,   322,    42,   631,
     877,    42,   634,   978,   979,   628,    49,    42,   631,    42,
     587,   634,   337,    49,   877,    42,   105,    38,    42,    42,
     597,    91,    43,    42,   999,    42,    42,   116,   117,    37,
      42,    40,    42,   610,   611,    42,    56,   611,    42,   128,
     617,   130,   131,   132,   104,    42,    64,   624,    49,    47,
      50,   628,    42,    49,   631,   632,   633,   634,    42,    43,
      38,   587,   104,    23,   133,    42,   601,   447,   838,   603,
     841,   597,   450,   587,   597,   945,   740,   488,   287,   472,
     740,   614,   477,   954,   610,   611,   623,   133,    53,    88,
     622,   617,   780,    76,   119,   773,   973,   367,   624,   834,
     842,   844,   628,   753,   971,   631,   632,   633,   634,   973,
     950,   756,   776,   952,   642,   656,   441,   644,   522,   444,
     522,   937,    -1,    -1,    -1,     0,    -1,    -1,    -1,    -1,
      -1,   456,    -1,    -1,     9,    -1,    11,    12,    -1,    14,
      -1,   466,   794,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   794,   740,   185,   186,    -1,    -1,    -1,    -1,
      -1,   794,    -1,    -1,    -1,    -1,   753,   922,   755,   756,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   776,
      -1,   185,   186,    -1,    -1,    -1,   838,   859,    -1,   841,
      -1,    -1,   844,    -1,   740,   838,    -1,   794,   841,   867,
      -1,   844,    -1,    -1,    -1,   877,    -1,   859,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,   859,    -1,    -1,    -1,
      -1,   116,   117,    -1,    -1,   877,    -1,    -1,    -1,   881,
      -1,    -1,    -1,   128,   877,   130,   131,   132,   881,    -1,
      -1,   838,   587,    -1,   841,   842,    -1,   844,   794,    -1,
     902,    -1,   597,    -1,   851,   907,   853,    -1,    -1,   902,
      -1,    -1,   859,    -1,   907,   610,   945,    -1,    -1,    -1,
      -1,    -1,    -1,   945,    -1,    -1,    -1,    -1,    -1,    -1,
     877,    -1,    -1,   628,   881,    -1,   631,    -1,    -1,   634,
      -1,    -1,   838,   945,    -1,   841,   842,    -1,   844,    -1,
      -1,   973,   945,    -1,    -1,   902,    -1,    42,    43,    -1,
     907,    -1,    -1,   859,   966,   967,   968,    -1,    -1,    -1,
      -1,   973,    -1,   966,   967,   968,   923,    -1,    -1,   923,
     973,   877,    -1,    -1,  1002,   881,   924,   925,    -1,    43,
      -1,   997,    -1,    -1,    -1,    -1,    -1,    -1,   945,  1001,
      -1,    -1,    -1,   950,    -1,   952,   902,    -1,  1001,   956,
     957,   907,   956,   957,    -1,    -1,    -1,    -1,    -1,   966,
     967,   968,    -1,    -1,   971,    -1,   973,   923,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   989,    -1,    -1,    -1,    -1,    -1,    -1,   945,
     104,    -1,    -1,    -1,  1001,    -1,    -1,    -1,    -1,    -1,
     956,   957,    -1,   959,    -1,    -1,    -1,    -1,    -1,    -1,
     966,   967,   968,    -1,    -1,   971,    -1,   973,    -1,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,    -1,   794,
     185,   186,    -1,    -1,    -1,  1001,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,   185,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   838,    -1,    -1,   841,    -1,    -1,   844,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   345,
      -1,    -1,    -1,    -1,   859,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   877,   369,   370,   371,   881,    -1,   374,    -1,
      -1,   377,   378,   379,   380,    -1,   382,   383,   384,   385,
      -1,   387,   388,   389,   390,   391,   392,   902,    -1,    -1,
     396,    43,   907,   399,   400,   401,   402,    -1,   404,    -1,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,    -1,    43,    -1,    -1,    17,    -1,    -1,    -1,
     945,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      41,   966,   967,   968,    -1,    -1,    -1,    -1,   973,    -1,
      -1,    52,    -1,    -1,    -1,   471,    -1,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1001,    52,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    42,    -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,   185,   186,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   548,   549,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,    -1,    -1,   185,   186,    -1,    -1,    -1,
      -1,    -1,   578,   579,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,    -1,   188,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,    -1,   188,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,    -1,   188,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      -1,    -1,   668,   669,   670,   671,    -1,    -1,    -1,   675,
      -1,    -1,   678,    -1,    -1,    -1,    -1,   683,    -1,    -1,
      41,    -1,    -1,    -1,   690,   691,    -1,    -1,    -1,    -1,
      -1,    -1,   698,    -1,    -1,    -1,   702,    -1,    -1,    -1,
     706,    62,    63,    -1,    65,    66,   712,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    -1,    90,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,
     111,    -1,   113,   114,   115,    -1,    -1,   118,   119,   120,
     121,   122,   123,   124,    -1,   126,   127,    -1,   129,    -1,
      -1,    -1,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,    -1,    -1,   185,   186,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   875,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   883,    -1,   885,
      -1,    66,   888,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,   110,   111,    -1,   113,   114,
     115,    -1,    -1,   118,   119,   120,   121,   122,   123,   124,
      -1,   126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,    -1,    -1,
     185,   186,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,   101,    -1,    -1,
      -1,    41,    -1,    -1,    -1,   109,   110,   111,    -1,   113,
     114,   115,    52,    -1,   118,   119,   120,   121,   122,   123,
     124,    -1,   126,   127,    -1,   129,    -1,    -1,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,   185,   186,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
     188,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    -1,   188,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    41,   188,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      -1,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
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
     143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
      -1,    -1,   185,   186,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    90,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,
      -1,   113,   114,   115,    -1,    -1,   118,   119,   120,   121,
     122,   123,   124,    -1,   126,   127,    -1,   129,    -1,    -1,
      -1,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,   185,   186,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    -1,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,
     111,    -1,   113,   114,   115,    -1,    -1,   118,   119,   120,
     121,   122,   123,   124,    -1,   126,   127,    41,   129,    -1,
      -1,    -1,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    90,    -1,    -1,   180,
     181,   182,    -1,    -1,   185,   186,    -1,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,   113,
     114,   115,    -1,    -1,   118,   119,   120,   121,   122,   123,
     124,    -1,   126,   127,    -1,   129,    -1,    -1,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182
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
     306,   307,   308,   310,   312,   314,   315,   316,   197,    13,
     299,   299,   299,   299,    37,   238,   253,   331,    20,   180,
     181,   182,   185,   186,   255,   256,   478,   479,   533,   534,
     238,   533,   299,   299,   299,   309,   311,   313,    31,   288,
     289,   290,    17,   243,   295,     3,     4,   318,   322,   324,
      16,   198,   233,   533,     6,    24,   106,   107,   329,   330,
     329,   330,   333,   334,    23,    40,   259,   238,   478,   238,
      40,   264,   265,     6,   106,   327,   328,   327,   327,    37,
     332,   332,   331,   373,   374,   375,   379,   380,    18,    19,
     244,   245,   238,    50,   292,   293,   323,   331,   319,   317,
     324,   234,   163,   199,   201,   202,    10,   300,   301,   533,
      38,    32,    33,    34,    35,    36,    52,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   183,   184,   188,   335,   343,   407,   463,   464,
     466,   467,   468,   477,   479,   480,   523,   527,   528,   529,
     530,   531,   532,   533,   535,    24,   260,   261,   262,   263,
     533,   331,   264,   257,   264,    92,   266,   267,   271,    37,
     163,   346,   348,   112,   533,   112,   112,   333,   479,    41,
     188,   382,    20,    41,    66,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    90,    94,    95,    96,    97,
      98,    99,   100,   101,   109,   110,   111,   113,   114,   115,
     118,   119,   120,   121,   122,   123,   124,   126,   127,   129,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   248,   249,   250,   251,   399,
     479,   504,   506,   508,   509,   510,   513,   516,   518,   523,
     527,   531,   533,   264,   195,   291,   331,    21,   108,   320,
     321,   325,   181,    56,   200,   329,   465,   338,    44,   344,
     345,   409,    41,   408,    89,   187,   524,   525,   526,   263,
     266,   266,   266,    26,    93,   268,   274,   349,   327,   327,
     327,    38,   376,   381,    37,    41,    62,    63,    65,   479,
     481,   482,   485,   488,   489,   492,   493,   499,   501,   502,
     503,   504,   516,   521,   523,   527,   531,   533,    76,    41,
      41,    41,   188,   505,    41,   188,   405,    41,    41,    41,
      41,   511,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,   405,    41,    41,    41,   188,   188,    41,
      41,    41,    41,   188,    41,   188,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,   249,    41,
      41,   188,   400,   266,   331,    24,   326,   533,    40,   235,
      37,   104,   151,   153,   155,   203,   204,   206,   207,   214,
     216,   217,   224,   263,    51,   412,   417,   478,   337,   339,
     340,   335,   410,   411,   412,   463,   469,   475,   477,   412,
     533,    41,   272,   273,   399,   479,   504,   275,   276,   398,
     399,   503,   504,    25,   269,   277,    52,   239,   240,   347,
     350,   351,   354,   422,   468,   470,   471,   473,   477,    37,
      42,   479,   386,   481,   502,   502,   502,    91,   246,   247,
     484,   487,    56,    57,    58,    59,    60,    61,    66,    67,
     490,   491,   498,   500,   400,   522,   514,   481,   481,   481,
     481,   481,   481,   481,   481,   512,   481,   481,   481,   481,
     479,   481,   481,   481,   481,   481,   481,    18,   402,   402,
     481,   481,   481,   481,   481,   481,   481,   481,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   481,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   481,   402,   402,
     533,   346,   180,   225,    43,   104,   164,   208,   209,   212,
     387,   479,   523,   527,   531,   533,   155,   218,   219,   222,
     387,   207,   205,   217,   215,    53,   418,   421,   475,    44,
     336,     6,    42,   475,   481,   273,   276,    26,    29,    30,
     270,   283,   286,   287,   472,   243,    38,   353,    44,   355,
     356,    41,   424,   423,   377,    38,    41,   188,   384,    42,
     479,    42,    54,   483,    55,   486,   492,   492,   492,   492,
     492,   492,    67,   405,    62,    63,   494,   497,   529,   530,
      20,    64,   495,   515,    42,    42,    42,   406,    49,    49,
      49,    49,   346,    42,    42,    49,    42,    42,    49,    42,
      42,    42,    42,    49,    20,   481,   517,   481,    42,    42,
      49,    49,    42,    42,    42,    42,    42,    42,    49,    42,
      42,    42,    49,    42,    42,    42,    49,    42,    42,    42,
      42,    42,    49,    42,    42,    42,   481,   481,    38,    41,
     226,   212,   104,   222,   155,   205,    44,   104,   210,   215,
      44,   155,   220,   416,   420,   335,   478,   247,    27,    28,
     278,   279,   280,   281,   282,   398,   479,   167,   167,   284,
     287,   285,   286,    41,    51,    65,   102,   427,   429,   435,
     436,   441,   442,   446,   450,   452,   454,   479,   533,   241,
       6,     7,     8,    31,    45,    46,    48,   125,   148,   352,
     357,   358,   359,   361,   365,   368,   371,   372,   388,   391,
     392,   397,   351,   470,   474,   476,   477,   425,   426,   427,
     427,    38,   378,   387,   385,   485,   488,   405,   499,   499,
     495,   496,   501,   501,   346,   404,   481,   481,   481,   481,
     481,   481,   481,    42,    50,   519,   520,   481,   481,   481,
     481,   481,   481,    42,   401,   227,   151,   213,   211,   154,
     223,   221,    50,   415,    49,   419,   341,    42,   279,   503,
     441,    41,    51,   102,   455,   461,   533,   450,    53,   428,
     443,   447,    20,    62,   103,   451,   453,   242,   362,   366,
     369,   373,   360,   389,   398,    41,   346,   336,   393,    42,
     476,   383,    42,    49,   403,    49,    42,    42,    49,    42,
      42,   403,   507,    77,    42,    42,    42,    42,   507,    42,
      42,   404,   230,   209,   219,   413,   414,   417,   421,    37,
      42,   458,   460,   461,    51,   462,   533,   437,   440,   476,
     445,   449,   264,   363,   367,   370,   346,   390,   481,   351,
     346,    42,   387,   481,   481,   481,    42,    56,    42,    42,
      42,   229,   231,   387,   418,   342,    42,   459,   434,   439,
     104,   444,    64,   448,   266,   478,   299,   299,   346,    91,
     396,    42,   507,   532,    49,   228,    56,   149,   150,   335,
     457,    50,   433,    49,   438,   446,   452,   288,   364,   478,
     478,   479,    47,   394,    42,   387,   387,   387,    38,   104,
     456,   429,   430,   432,   440,   346,   346,    23,    42,   395,
     461,   431,   331,   346,   418,   264
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
     304,   305,   306,   307,   309,   308,   311,   310,   313,   312,
     314,   315,   316,   316,   317,   317,   318,   318,   319,   319,
     320,   321,   321,   323,   322,   324,   325,   326,   326,   327,
     327,   328,   328,   329,   330,   330,   330,   330,   331,   332,
     334,   333,   335,   335,   336,   336,   337,   338,   338,   340,
     341,   342,   339,   343,   344,   345,   345,   346,   346,   347,
     347,   349,   348,   350,   351,   351,   352,   353,   353,   354,
     355,   356,   356,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   358,   360,   359,   362,   363,   364,   361,
     366,   367,   365,   369,   370,   368,   371,   372,   373,   373,
     375,   376,   374,   377,   377,   378,   380,   379,   381,   381,
     382,   382,   383,   383,   385,   384,   384,   386,   386,   387,
     387,   387,   387,   387,   387,   387,   389,   390,   388,   392,
     393,   391,   395,   394,   396,   396,   397,   398,   398,   398,
     399,   400,   401,   400,   402,   402,   403,   404,   404,   405,
     406,   405,   408,   407,   409,   407,   410,   411,   411,   412,
     413,   414,   414,   415,   416,   416,   417,   417,   418,   419,
     420,   420,   421,   423,   422,   424,   422,   425,   426,   426,
     428,   427,   429,   429,   431,   430,   432,   432,   433,   434,
     434,   435,   436,   437,   438,   439,   439,   440,   441,   443,
     442,   444,   445,   445,   447,   446,   448,   449,   449,   450,
     451,   451,   452,   452,   453,   453,   453,   454,   454,   454,
     454,   455,   455,   456,   457,   457,   459,   458,   460,   460,
     461,   461,   461,   462,   462,   463,   463,   465,   464,   466,
     467,   467,   467,   467,   467,   468,   468,   469,   469,   470,
     470,   472,   471,   473,   474,   474,   475,   475,   476,   476,
     477,   477,   478,   478,   479,   479,   480,   480,   480,   480,
     480,   480,   481,   482,   483,   484,   484,   485,   486,   487,
     487,   488,   489,   490,   490,   491,   491,   491,   491,   491,
     491,   491,   491,   492,   493,   494,   494,   495,   495,   496,
     496,   497,   497,   497,   498,   498,   499,   500,   500,   501,
     501,   501,   501,   502,   502,   502,   502,   502,   502,   502,
     502,   503,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   505,   505,   506,   507,
     507,   508,   509,   511,   512,   510,   514,   515,   513,   516,
     516,   516,   517,   517,   518,   518,   518,   518,   518,   519,
     520,   520,   521,   522,   522,   523,   524,   525,   525,   526,
     526,   527,   527,   527,   528,   528,   528,   529,   529,   529,
     530,   530,   530,   531,   531,   532,   532,   532,   532,   533,
     533,   534,   534,   535,   535
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
       3,     5,     5,     5,     0,     3,     0,     3,     0,     3,
       6,     2,     0,     1,     0,     1,     2,     1,     0,     2,
       2,     0,     1,     0,     3,     2,     2,     1,     2,     1,
       2,     0,     1,     2,     1,     1,     1,     1,     3,     3,
       0,     3,     0,     1,     0,     1,     3,     0,     2,     0,
       0,     0,     8,     2,     2,     0,     1,     1,     1,     1,
       1,     0,     4,     2,     0,     1,     3,     0,     2,     2,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     3,     0,     0,     0,     6,
       0,     0,     6,     0,     0,     8,     6,     2,     1,     1,
       0,     0,     6,     0,     2,     1,     0,     5,     0,     2,
       1,     3,     0,     2,     0,     4,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     0,     0,     4,     0,
       0,     4,     0,     3,     0,     2,     2,     1,     1,     1,
       2,     1,     0,     6,     0,     1,     2,     0,     2,     1,
       0,     5,     0,     3,     0,     3,     1,     0,     1,     3,
       2,     0,     1,     2,     0,     2,     1,     1,     2,     2,
       0,     2,     1,     0,     3,     0,     3,     1,     0,     1,
       0,     4,     1,     1,     0,     3,     0,     1,     2,     0,
       2,     1,     1,     2,     2,     0,     2,     1,     1,     0,
       3,     2,     0,     2,     0,     3,     2,     0,     2,     2,
       0,     1,     1,     2,     1,     1,     1,     1,     1,     2,
       3,     1,     3,     2,     0,     2,     0,     3,     0,     1,
       1,     1,     2,     1,     1,     1,     1,     0,     4,     4,
       1,     1,     1,     1,     1,     0,     1,     1,     2,     1,
       1,     0,     4,     4,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     0,     2,     2,     2,     0,
       2,     1,     2,     0,     1,     2,     2,     2,     2,     2,
       2,     2,     3,     1,     2,     1,     1,     2,     2,     0,
       1,     2,     2,     2,     0,     2,     2,     0,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     4,     6,     4,     4,     4,     4,     2,
       2,     4,     4,     4,     4,     2,     1,     4,     1,     4,
       4,     4,     6,     6,     6,     6,     6,     4,     4,     4,
       4,     4,     4,     4,     4,     2,     2,     2,     4,     4,
       4,     4,     4,     2,     8,     6,     6,     6,     4,     4,
       4,     4,     4,     1,     1,     1,     3,     1,     7,     0,
       1,     7,     9,     0,     0,     4,     0,     0,     5,     5,
       5,     6,     1,     1,     1,     1,     1,     1,     1,     4,
       0,     1,     2,     0,     1,     2,     2,     1,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
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
  "Add", "Move", "Copy", "InsertData", "$@12", "DeleteData", "$@13",
  "DeleteWhere", "$@14", "Modify", "_O_QIT_WITH_E_S_Qiri_E_C",
  "_Q_O_QIT_WITH_E_S_Qiri_E_C_E_Opt", "_QInsertClause_E_Opt",
  "_O_QDeleteClause_E_S_QInsertClause_E_Opt_Or_QInsertClause_E_C",
  "_QUsingClause_E_Star", "_O_QIT_CONSTRUCT_E_S_QQuadPattern_E_C",
  "_Q_O_QIT_CONSTRUCT_E_S_QQuadPattern_E_C_E_Opt", "DeleteClause", "$@15",
  "InsertClause", "UsingClause", "_O_Qiri_E_Or_QIT_NAMED_E_S_Qiri_E_C",
  "GraphOrDefault", "_QIT_GRAPH_E_Opt", "GraphRef", "GraphRefAll",
  "QuadPattern", "QuadData", "Quads", "$@16", "_QTriplesTemplate_E_Opt",
  "_QGT_DOT_E_Opt",
  "_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C_E_Star",
  "QuadsNotTriples", "@17", "@18", "$@19", "TriplesTemplate",
  "_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C_E_Opt", "GroupGraphPattern",
  "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C",
  "_O_QGT_LCURLEY_E_S_QSubSelect_E_Or_QGroupGraphPatternSub_E_S_QGT_RCURLEY_E_C",
  "$@20", "GroupGraphPatternSub", "_QTriplesBlock_E_Opt",
  "_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "Print", "OptionalGraphPattern", "@21", "GraphGraphPattern", "@22",
  "@23", "@24", "ServiceGraphPattern", "@25", "@26", "SADIinvocation",
  "@27", "@28", "Bind", "InlineData", "DataBlock", "InlineDataOneVar",
  "$@29", "$@30", "_QSingleValueRow_E_Star", "SingleValueRow",
  "InlineDataFull", "$@31", "_QVar_E_Star",
  "_O_QNIL_E_Or_QGT_LPAREN_E_S_QVar_E_Star_S_QGT_RPAREN_E_C",
  "_QDataBlockValue_E_Star",
  "_O_QGT_LPAREN_E_S_QDataBlockValue_E_Star_S_QGT_RPAREN_E_Or_QNIL_E_C",
  "$@32",
  "_Q_O_QGT_LPAREN_E_S_QDataBlockValue_E_Star_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star",
  "DataBlockValue", "MinusGraphPattern", "@33", "@34",
  "GroupOrUnionGraphPattern", "@35", "@36",
  "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@37",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "@38", "_QIT_DISTINCT_E_Opt",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ExpressionList", "@39",
  "TriplesSameSubject", "$@40", "$@41", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "PropertyListNotEmpty",
  "_O_QVerb_E_S_QObjectList_E_C", "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "Verb",
  "ObjectList", "_O_QGT_COMMA_E_S_QObject_E_C",
  "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star", "Object",
  "TriplesSameSubjectPath", "$@42", "$@43", "PropertyListPath",
  "_QPropertyListPathNotEmpty_E_Opt", "PropertyListPathNotEmpty", "$@44",
  "_O_QVerbPath_E_Or_QVerbSimple_E_C",
  "_O_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_C", "$@45",
  "_Q_O_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_Opt_C_E_Star",
  "VerbPath", "VerbSimple", "ObjectListPath",
  "_O_QGT_COMMA_E_S_QObjectPath_E_C",
  "_Q_O_QGT_COMMA_E_S_QObjectPath_E_C_E_Star", "ObjectPath", "Path",
  "PathAlternative", "@46", "_O_QGT_PIPE_E_S_QPathSequence_E_C",
  "_Q_O_QGT_PIPE_E_S_QPathSequence_E_C_E_Star", "PathSequence", "@47",
  "_O_QGT_DIVIDE_E_S_QPathEltOrInverse_E_C",
  "_Q_O_QGT_DIVIDE_E_S_QPathEltOrInverse_E_C_E_Star", "PathElt",
  "_QPathMod_E_Opt", "PathEltOrInverse", "PathMod", "PathPrimary",
  "PathNegatedPropertySet", "_O_QGT_PIPE_E_S_QPathOneInPropertySet_E_C",
  "_Q_O_QGT_PIPE_E_S_QPathOneInPropertySet_E_C_E_Star",
  "_O_QPathOneInPropertySet_E_S_QGT_PIPE_E_S_QPathOneInPropertySet_E_Star_C",
  "@48",
  "_Q_O_QPathOneInPropertySet_E_S_QGT_PIPE_E_S_QPathOneInPropertySet_E_Star_C_E_Opt",
  "PathOneInPropertySet", "_O_Qiri_E_Or_QIT_a_E_C", "TriplesNode",
  "BlankNodePropertyList", "@49", "Generator",
  "_O_QIT_MEMBERS_E_Or_QIT_STARTS_E_Or_QIT_ENDS_E_Or_QIT_ANY_E_Or_QIT_UNORDERED_E_C",
  "_Q_O_QIT_MEMBERS_E_Or_QIT_STARTS_E_Or_QIT_ENDS_E_Or_QIT_ANY_E_Or_QIT_UNORDERED_E_C_E_Opt",
  "_QGraphNode_E_Plus", "TriplesNodePath", "BlankNodePropertyListPath",
  "@50", "GeneratorPath", "_QGraphNodePath_E_Plus", "GraphNode",
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
  "SubstringExpression", "StrReplaceExpression", "ExistsFunc", "@51",
  "@52", "NotExistsFunc", "@53", "@54", "Aggregate",
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
     104,    -1,   208,    -1,    -1,   104,   211,   209,    -1,   387,
     104,    -1,   151,    -1,   216,   217,   215,   223,    -1,   217,
     215,    44,    -1,    -1,   215,   220,    -1,   153,    -1,   155,
     219,    -1,   222,    -1,   218,   222,    -1,   155,    -1,   218,
      -1,    -1,   155,   221,   219,    -1,   387,   155,    -1,   154,
      -1,    37,   225,    38,    -1,    -1,   225,   226,    -1,    -1,
      41,   227,   230,    42,    -1,    -1,    49,    -1,   231,   228,
      -1,    -1,   230,   229,    -1,   387,   150,   387,    -1,   387,
     149,   387,    -1,   387,    56,   387,    -1,    15,   180,    -1,
      -1,    -1,    16,   234,   181,   235,   180,    -1,    -1,   237,
     243,   238,   264,   266,    -1,    -1,   238,   259,    -1,    -1,
      -1,    -1,   240,   243,   241,   242,   264,   266,   288,    -1,
      17,   245,   251,    -1,    18,    -1,    19,    -1,    -1,   244,
      -1,    91,   479,    -1,    -1,   246,    -1,    41,   481,   247,
      42,    -1,   504,    -1,   523,    -1,   527,    -1,   531,    -1,
     479,    -1,   516,    -1,   399,    -1,   248,    -1,   249,    -1,
     250,   249,    -1,   250,    -1,    20,    -1,    21,   253,    -1,
     331,   238,   264,   266,    -1,   238,    40,   331,   266,    -1,
      22,   256,   238,   257,   266,    -1,   478,    -1,   255,   478,
      -1,   255,    -1,    20,    -1,    -1,   264,    -1,    39,   238,
     264,   266,    -1,    23,   260,    -1,   261,    -1,   262,    -1,
     263,    -1,    24,   263,    -1,   533,    -1,   265,   346,    -1,
      -1,    40,    -1,   267,   268,   269,   270,    -1,    -1,   271,
      -1,    -1,   274,    -1,    -1,   277,    -1,    -1,   283,    -1,
      92,    26,   272,    -1,   273,    -1,   272,   273,    -1,   504,
      -1,   399,    -1,    41,   481,   247,    42,    -1,   479,    -1,
      93,   275,    -1,   276,    -1,   275,   276,    -1,   398,    -1,
      25,    26,   278,    -1,   279,    -1,   278,   279,    -1,   281,
      -1,   282,    -1,    27,    -1,    28,    -1,   280,   503,    -1,
     398,    -1,   479,    -1,   286,   284,    -1,   287,   285,    -1,
      -1,   287,    -1,    -1,   286,    -1,    29,   167,    -1,    30,
     167,    -1,   290,    -1,    31,   373,    -1,    -1,   289,    -1,
     195,   296,    -1,    50,   291,    -1,    -1,   292,    -1,    -1,
     297,   295,   293,    -1,    -1,   294,    -1,   298,    -1,   302,
      -1,   303,    -1,   305,    -1,   306,    -1,   307,    -1,   304,
      -1,   308,    -1,   310,    -1,   312,    -1,   314,    -1,     9,
     299,   533,   301,    -1,    -1,    13,    -1,    10,   329,    -1,
      -1,   300,    -1,    11,   299,   330,    -1,    14,   299,   330,
      -1,    12,   299,   329,    -1,   116,   299,   327,   112,   327,
      -1,   128,   299,   327,   112,   327,    -1,   117,   299,   327,
     112,   327,    -1,    -1,   130,   309,   332,    -1,    -1,   131,
     311,   332,    -1,    -1,   132,   313,   331,    -1,   316,   318,
     319,   321,    40,   346,    -1,   105,   533,    -1,    -1,   315,
      -1,    -1,   324,    -1,   322,   317,    -1,   324,    -1,    -1,
     319,   325,    -1,    21,   331,    -1,    -1,   320,    -1,    -1,
       3,   323,   331,    -1,     4,   331,    -1,   108,   326,    -1,
     533,    -1,    24,   533,    -1,   106,    -1,   328,   533,    -1,
      -1,     6,    -1,     6,   533,    -1,   329,    -1,   106,    -1,
      24,    -1,   107,    -1,    37,   333,    38,    -1,    37,   333,
      38,    -1,    -1,   334,   335,   338,    -1,    -1,   343,    -1,
      -1,    44,    -1,   339,   336,   335,    -1,    -1,   338,   337,
      -1,    -1,    -1,    -1,   340,     6,   478,   341,    37,   342,
     335,    38,    -1,   407,   345,    -1,    44,   335,    -1,    -1,
     344,    -1,   348,    -1,   163,    -1,   239,    -1,   350,    -1,
      -1,    37,   349,   347,    38,    -1,   351,   353,    -1,    -1,
     354,    -1,   357,   336,   351,    -1,    -1,   353,   352,    -1,
     422,   356,    -1,    44,   351,    -1,    -1,   355,    -1,   391,
      -1,   359,    -1,   388,    -1,   361,    -1,   365,    -1,   368,
      -1,   397,    -1,   371,    -1,   372,    -1,   358,    -1,   148,
     346,    -1,    -1,    45,   360,   346,    -1,    -1,    -1,    -1,
       6,   362,   363,   478,   364,   346,    -1,    -1,    -1,     7,
     366,   367,   299,   478,   346,    -1,    -1,    -1,     8,   369,
     370,   299,   478,    23,   331,   264,    -1,   125,    41,   481,
      91,   479,    42,    -1,    31,   373,    -1,   374,    -1,   379,
      -1,    -1,    -1,   375,   479,   376,    37,   377,    38,    -1,
      -1,   377,   378,    -1,   387,    -1,    -1,   380,   382,    37,
     386,    38,    -1,    -1,   381,   479,    -1,   188,    -1,    41,
     381,    42,    -1,    -1,   383,   387,    -1,    -1,    41,   385,
     383,    42,    -1,   188,    -1,    -1,   386,   384,    -1,   533,
      -1,   523,    -1,   527,    -1,   531,    -1,    43,    -1,   164,
      -1,   479,    -1,    -1,    -1,    46,   389,   390,   346,    -1,
      -1,    -1,   392,   393,   346,   396,    -1,    -1,    47,   395,
     346,    -1,    -1,   396,   394,    -1,    48,   398,    -1,   503,
      -1,   504,    -1,   399,    -1,   533,   400,    -1,   188,    -1,
      -1,    41,   402,   481,   401,   404,    42,    -1,    -1,    18,
      -1,    49,   481,    -1,    -1,   404,   403,    -1,   188,    -1,
      -1,    41,   481,   406,   404,    42,    -1,    -1,   477,   408,
     412,    -1,    -1,   463,   409,   410,    -1,   411,    -1,    -1,
     412,    -1,   417,   418,   416,    -1,   417,   418,    -1,    -1,
     413,    -1,    50,   414,    -1,    -1,   416,   415,    -1,   478,
      -1,    51,    -1,   421,   420,    -1,    49,   421,    -1,    -1,
     420,   419,    -1,   475,    -1,    -1,   477,   423,   427,    -1,
      -1,   470,   424,   425,    -1,   426,    -1,    -1,   427,    -1,
      -1,   429,   428,   437,   434,    -1,   435,    -1,   436,    -1,
      -1,   429,   431,   418,    -1,    -1,   430,    -1,    50,   432,
      -1,    -1,   434,   433,    -1,   441,    -1,   479,    -1,   440,
     439,    -1,    49,   440,    -1,    -1,   439,   438,    -1,   476,
      -1,   442,    -1,    -1,   446,   443,   445,    -1,   104,   446,
      -1,    -1,   445,   444,    -1,    -1,   452,   447,   449,    -1,
      64,   452,    -1,    -1,   449,   448,    -1,   454,   451,    -1,
      -1,   453,    -1,   450,    -1,   102,   450,    -1,   103,    -1,
      20,    -1,    62,    -1,   533,    -1,    51,    -1,    65,   455,
      -1,    41,   441,    42,    -1,   461,    -1,    41,   460,    42,
      -1,   104,   461,    -1,    -1,   457,   456,    -1,    -1,   461,
     459,   457,    -1,    -1,   458,    -1,   533,    -1,    51,    -1,
     102,   462,    -1,   533,    -1,    51,    -1,   466,    -1,   464,
      -1,    -1,    52,   465,   412,    53,    -1,   468,    41,   469,
      42,    -1,    32,    -1,    33,    -1,    34,    -1,    35,    -1,
      36,    -1,    -1,   467,    -1,   475,    -1,   469,   475,    -1,
     473,    -1,   471,    -1,    -1,    52,   472,   427,    53,    -1,
     468,    41,   474,    42,    -1,   476,    -1,   474,   476,    -1,
     477,    -1,   463,    -1,   477,    -1,   470,    -1,   479,    -1,
     480,    -1,   479,    -1,   533,    -1,   185,    -1,   186,    -1,
     533,    -1,   523,    -1,   527,    -1,   531,    -1,   535,    -1,
     188,    -1,   482,    -1,   485,   484,    -1,    54,   485,    -1,
      -1,   484,   483,    -1,   488,   487,    -1,    55,   488,    -1,
      -1,   487,   486,    -1,   489,    -1,   492,   490,    -1,    -1,
     491,    -1,    56,   492,    -1,    57,   492,    -1,    58,   492,
      -1,    59,   492,    -1,    60,   492,    -1,    61,   492,    -1,
      67,   405,    -1,    66,    67,   405,    -1,   493,    -1,   499,
     498,    -1,   529,    -1,   530,    -1,    20,   501,    -1,    64,
     501,    -1,    -1,   495,    -1,    62,   499,    -1,    63,   499,
      -1,   494,   496,    -1,    -1,   498,   497,    -1,   501,   500,
      -1,    -1,   500,   495,    -1,    65,   502,    -1,    62,   502,
      -1,    63,   502,    -1,   502,    -1,   503,    -1,   504,    -1,
     521,    -1,   523,    -1,   527,    -1,   531,    -1,   479,    -1,
     516,    -1,    41,   481,    42,    -1,    78,    41,   481,    42,
      -1,    79,    41,   481,    42,    -1,    80,    41,   481,    49,
     481,    42,    -1,    81,    41,   481,    42,    -1,    82,    41,
     479,    42,    -1,    68,    41,   481,    42,    -1,    69,    41,
     481,    42,    -1,    70,   505,    -1,   118,   188,    -1,   142,
      41,   481,    42,    -1,   139,    41,   481,    42,    -1,   129,
      41,   481,    42,    -1,   123,    41,   481,    42,    -1,    90,
     405,    -1,   508,    -1,   145,    41,   481,    42,    -1,   509,
      -1,   143,    41,   481,    42,    -1,   141,    41,   481,    42,
      -1,   137,    41,   481,    42,    -1,   126,    41,   481,    49,
     481,    42,    -1,   138,    41,   481,    49,   481,    42,    -1,
     144,    41,   481,    49,   481,    42,    -1,   113,    41,   481,
      49,   481,    42,    -1,   114,    41,   481,    49,   481,    42,
      -1,   115,    41,   481,    42,    -1,   147,    41,   481,    42,
      -1,   140,    41,   481,    42,    -1,   136,    41,   481,    42,
      -1,   133,    41,   481,    42,    -1,   127,    41,   481,    42,
      -1,   122,    41,   481,    42,    -1,   121,    41,   481,    42,
      -1,   120,   188,    -1,   109,   188,    -1,   110,   188,    -1,
     111,    41,   481,    42,    -1,   146,    41,   481,    42,    -1,
     135,    41,   481,    42,    -1,   124,    41,   481,    42,    -1,
     119,    41,   481,    42,    -1,    71,   405,    -1,    72,    41,
     481,    49,   481,    49,   481,    42,    -1,    73,    41,   481,
      49,   481,    42,    -1,    74,    41,   481,    49,   481,    42,
      -1,    83,    41,   481,    49,   481,    42,    -1,    84,    41,
     481,    42,    -1,    85,    41,   481,    42,    -1,    86,    41,
     481,    42,    -1,    87,    41,   481,    42,    -1,   101,    41,
     481,    42,    -1,   506,    -1,   510,    -1,   513,    -1,    41,
     481,    42,    -1,   188,    -1,    88,    41,   481,    49,   481,
     507,    42,    -1,    -1,   403,    -1,   134,    41,   481,    49,
     481,   507,    42,    -1,    75,    41,   481,    49,   481,    49,
     481,   507,    42,    -1,    -1,    -1,    76,   511,   512,   346,
      -1,    -1,    -1,    66,    76,   514,   515,   346,    -1,    94,
      41,   402,   517,    42,    -1,   518,    41,   402,   481,    42,
      -1,    99,    41,   402,   481,   520,    42,    -1,    20,    -1,
     481,    -1,    95,    -1,    96,    -1,    97,    -1,    98,    -1,
     100,    -1,    50,    77,    56,   532,    -1,    -1,   519,    -1,
     533,   522,    -1,    -1,   400,    -1,   532,   526,    -1,    89,
     533,    -1,   187,    -1,   524,    -1,    -1,   525,    -1,   528,
      -1,   529,    -1,   530,    -1,   167,    -1,   168,    -1,   169,
      -1,   170,    -1,   171,    -1,   172,    -1,   173,    -1,   174,
      -1,   175,    -1,   165,    -1,   166,    -1,   176,    -1,   178,
      -1,   177,    -1,   179,    -1,   180,    -1,   534,    -1,   182,
      -1,   181,    -1,   183,    -1,   184,    -1
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
     461,   465,   471,   477,   483,   484,   488,   489,   493,   494,
     498,   505,   508,   509,   511,   512,   514,   517,   519,   520,
     523,   526,   527,   529,   530,   534,   537,   540,   542,   545,
     547,   550,   551,   553,   556,   558,   560,   562,   564,   568,
     572,   573,   577,   578,   580,   581,   583,   587,   588,   591,
     592,   593,   594,   603,   606,   609,   610,   612,   614,   616,
     618,   620,   621,   626,   629,   630,   632,   636,   637,   640,
     643,   646,   647,   649,   651,   653,   655,   657,   659,   661,
     663,   665,   667,   669,   672,   673,   677,   678,   679,   680,
     687,   688,   689,   696,   697,   698,   707,   714,   717,   719,
     721,   722,   723,   730,   731,   734,   736,   737,   743,   744,
     747,   749,   753,   754,   757,   758,   763,   765,   766,   769,
     771,   773,   775,   777,   779,   781,   783,   784,   785,   790,
     791,   792,   797,   798,   802,   803,   806,   809,   811,   813,
     815,   818,   820,   821,   828,   829,   831,   834,   835,   838,
     840,   841,   847,   848,   852,   853,   857,   859,   860,   862,
     866,   869,   870,   872,   875,   876,   879,   881,   883,   886,
     889,   890,   893,   895,   896,   900,   901,   905,   907,   908,
     910,   911,   916,   918,   920,   921,   925,   926,   928,   931,
     932,   935,   937,   939,   942,   945,   946,   949,   951,   953,
     954,   958,   961,   962,   965,   966,   970,   973,   974,   977,
     980,   981,   983,   985,   988,   990,   992,   994,   996,   998,
    1001,  1005,  1007,  1011,  1014,  1015,  1018,  1019,  1023,  1024,
    1026,  1028,  1030,  1033,  1035,  1037,  1039,  1041,  1042,  1047,
    1052,  1054,  1056,  1058,  1060,  1062,  1063,  1065,  1067,  1070,
    1072,  1074,  1075,  1080,  1085,  1087,  1090,  1092,  1094,  1096,
    1098,  1100,  1102,  1104,  1106,  1108,  1110,  1112,  1114,  1116,
    1118,  1120,  1122,  1124,  1127,  1130,  1131,  1134,  1137,  1140,
    1141,  1144,  1146,  1149,  1150,  1152,  1155,  1158,  1161,  1164,
    1167,  1170,  1173,  1177,  1179,  1182,  1184,  1186,  1189,  1192,
    1193,  1195,  1198,  1201,  1204,  1205,  1208,  1211,  1212,  1215,
    1218,  1221,  1224,  1226,  1228,  1230,  1232,  1234,  1236,  1238,
    1240,  1242,  1246,  1251,  1256,  1263,  1268,  1273,  1278,  1283,
    1286,  1289,  1294,  1299,  1304,  1309,  1312,  1314,  1319,  1321,
    1326,  1331,  1336,  1343,  1350,  1357,  1364,  1371,  1376,  1381,
    1386,  1391,  1396,  1401,  1406,  1411,  1414,  1417,  1420,  1425,
    1430,  1435,  1440,  1445,  1448,  1457,  1464,  1471,  1478,  1483,
    1488,  1493,  1498,  1503,  1505,  1507,  1509,  1513,  1515,  1523,
    1524,  1526,  1534,  1544,  1545,  1546,  1551,  1552,  1553,  1559,
    1565,  1571,  1578,  1580,  1582,  1584,  1586,  1588,  1590,  1592,
    1597,  1598,  1600,  1603,  1604,  1606,  1609,  1612,  1614,  1616,
    1617,  1619,  1621,  1623,  1625,  1627,  1629,  1631,  1633,  1635,
    1637,  1639,  1641,  1643,  1645,  1647,  1649,  1651,  1653,  1655,
    1657,  1659,  1661,  1663,  1665
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   529,   529,   532,   538,   543,   554,   555,   556,   557,
     561,   566,   570,   572,   576,   578,   581,   583,   587,   587,
     605,   611,   614,   618,   619,   620,   621,   627,   628,   631,
     633,   637,   641,   645,   646,   650,   651,   655,   655,   663,
     669,   673,   674,   677,   679,   683,   687,   691,   692,   696,
     697,   701,   701,   709,   715,   719,   722,   724,   728,   728,
     735,   737,   741,   744,   746,   750,   753,   756,   762,   768,
     770,   768,   780,   780,   792,   795,   803,   806,   810,   803,
     829,   837,   840,   847,   850,   855,   862,   865,   870,   877,
     880,   883,   886,   889,   892,   895,   899,   904,   907,   915,
     918,   924,   930,   935,   945,   953,   956,   964,   967,   974,
     977,   982,   990,   997,   998,  1002,  1008,  1014,  1021,  1028,
    1030,  1035,  1042,  1045,  1050,  1053,  1058,  1061,  1066,  1070,
    1074,  1081,  1084,  1091,  1094,  1097,  1100,  1106,  1112,  1115,
    1122,  1127,  1134,  1138,  1146,  1148,  1156,  1159,  1167,  1175,
    1176,  1183,  1187,  1195,  1198,  1203,  1206,  1210,  1216,  1222,
    1226,  1232,  1235,  1239,  1245,  1248,  1250,  1254,  1254,  1261,
    1263,  1267,  1268,  1269,  1270,  1271,  1272,  1273,  1274,  1275,
    1276,  1277,  1281,  1287,  1290,  1297,  1304,  1307,  1311,  1317,
    1323,  1329,  1335,  1341,  1347,  1347,  1358,  1358,  1369,  1369,
    1380,  1387,  1393,  1396,  1400,  1403,  1407,  1411,  1418,  1421,
    1430,  1436,  1439,  1443,  1443,  1452,  1458,  1464,  1468,  1475,
    1478,  1483,  1485,  1489,  1495,  1498,  1501,  1504,  1511,  1518,
    1524,  1524,  1532,  1534,  1538,  1540,  1544,  1547,  1549,  1554,
    1559,  1562,  1554,  1573,  1577,  1580,  1582,  1586,  1587,  1600,
    1601,  1606,  1606,  1617,  1621,  1623,  1633,  1637,  1640,  1656,
    1661,  1665,  1668,  1672,  1673,  1674,  1675,  1676,  1677,  1678,
    1679,  1680,  1683,  1687,  1693,  1693,  1709,  1713,  1715,  1709,
    1726,  1730,  1726,  1739,  1743,  1739,  1760,  1771,  1777,  1778,
    1782,  1784,  1782,  1791,  1793,  1797,  1805,  1805,  1812,  1814,
    1820,  1821,  1824,  1826,  1832,  1832,  1837,  1843,  1845,  1849,
    1852,  1855,  1858,  1861,  1864,  1867,  1873,  1877,  1873,  1887,
    1891,  1887,  1901,  1901,  1913,  1915,  1919,  1929,  1930,  1931,
    1935,  1943,  1947,  1947,  1957,  1960,  1967,  1973,  1975,  1989,
    1992,  1992,  2002,  2002,  2005,  2005,  2011,  2014,  2016,  2021,
    2026,  2030,  2032,  2037,  2041,  2043,  2047,  2051,  2059,  2064,
    2068,  2070,  2074,  2082,  2082,  2085,  2085,  2091,  2094,  2096,
    2100,  2100,  2106,  2107,  2111,  2111,  2116,  2118,  2122,  2125,
    2127,  2131,  2140,  2146,  2150,  2153,  2155,  2159,  2166,  2170,
    2170,  2180,  2186,  2189,  2195,  2195,  2205,  2211,  2214,  2220,
    2226,  2229,  2233,  2234,  2240,  2243,  2246,  2252,  2255,  2258,
    2261,  2267,  2268,  2274,  2280,  2283,  2289,  2289,  2299,  2302,
    2306,  2309,  2312,  2318,  2321,  2329,  2330,  2334,  2334,  2347,
    2375,  2378,  2381,  2384,  2387,  2394,  2397,  2402,  2406,  2413,
    2414,  2418,  2418,  2430,  2457,  2461,  2468,  2469,  2473,  2474,
    2478,  2481,  2485,  2488,  2494,  2495,  2499,  2502,  2505,  2508,
    2511,  2512,  2518,  2523,  2532,  2539,  2542,  2550,  2559,  2566,
    2569,  2576,  2581,  2594,  2598,  2602,  2606,  2610,  2614,  2618,
    2622,  2626,  2630,  2637,  2642,  2651,  2654,  2661,  2664,  2671,
    2674,  2679,  2682,  2686,  2700,  2703,  2711,  2720,  2723,  2730,
    2733,  2736,  2739,  2743,  2744,  2745,  2746,  2749,  2752,  2755,
    2758,  2762,  2768,  2771,  2774,  2777,  2780,  2783,  2786,  2790,
    2793,  2796,  2799,  2802,  2805,  2808,  2811,  2812,  2815,  2816,
    2819,  2822,  2825,  2828,  2831,  2834,  2837,  2840,  2843,  2846,
    2849,  2852,  2855,  2858,  2861,  2864,  2867,  2870,  2873,  2876,
    2879,  2882,  2885,  2888,  2891,  2894,  2897,  2900,  2903,  2906,
    2909,  2912,  2915,  2918,  2919,  2920,  2926,  2929,  2936,  2943,
    2946,  2950,  2956,  2962,  2965,  2962,  2977,  2980,  2977,  2993,
    2997,  3002,  3011,  3014,  3018,  3021,  3024,  3027,  3030,  3036,
    3042,  3045,  3049,  3059,  3062,  3067,  3075,  3082,  3086,  3094,
    3098,  3102,  3103,  3104,  3108,  3109,  3110,  3114,  3115,  3116,
    3120,  3121,  3122,  3126,  3127,  3131,  3132,  3133,  3134,  3138,
    3139,  3143,  3144,  3148,  3149
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
  const int SPARQLfedParser::yylast_ = 2628;
  const int SPARQLfedParser::yynnts_ = 347;
  const int SPARQLfedParser::yyempty_ = -2;
  const int SPARQLfedParser::yyfinal_ = 11;
  const int SPARQLfedParser::yyterror_ = 1;
  const int SPARQLfedParser::yyerrcode_ = 256;
  const int SPARQLfedParser::yyntokens_ = 189;

  const unsigned int SPARQLfedParser::yyuser_token_number_max_ = 443;
  const SPARQLfedParser::token_number_type SPARQLfedParser::yyundef_token_ = 2;


} // w3c_sw

/* Line 1136 of lalr1.cc  */
#line 6229 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 3155 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
    inINSERTDATA   = false;
    inDELETEDATA   = false;
    inDELETEWHERE  = false;
    inDELETECLAUSE = false;
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


