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
#line 320 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"

/* Line 299 of lalr1.cc  */
#line 474 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

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
#line 488 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 491 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 502 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 546 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.startBindingSet();
      }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 549 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 564 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = (yysemantic_stack_[(2) - (1)].p_RSName);
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 570 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = NULL;
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 580 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	throw std::runtime_error("need to partition out results set part of SimpleEngine::loadDataOrResults");
    }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 614 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 616 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 622 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 660 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 662 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 668 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 687 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow(false);
      }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 689 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 709 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 712 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 715 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 721 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 727 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 729 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 731 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 739 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 742 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause);
	(yyval.p_Operation) = new Select((yysemantic_stack_[(5) - (2)].p_Project).distinctness, (yysemantic_stack_[(5) - (2)].p_Project).varSet, (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
	driver.countStar = (yysemantic_stack_[(5) - (1)].p_parentCountStar);
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 751 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 754 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 762 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
      }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 765 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 769 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 776 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if ((yysemantic_stack_[(7) - (4)].p_GraphName) != NULL)
	      driver.curGraphName = (yysemantic_stack_[(7) - (4)].p_GraphName);
	  if ((yysemantic_stack_[(7) - (7)].p_BindingClause) != NULL)
	      (yysemantic_stack_[(7) - (5)].p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yysemantic_stack_[(7) - (7)].p_BindingClause), (yysemantic_stack_[(7) - (5)].p_WhereClause)->m_GroupGraphPattern);
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (3)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(7) - (2)].p_Project).distinctness, (yysemantic_stack_[(7) - (2)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(7) - (5)].p_WhereClause), (yysemantic_stack_[(7) - (6)].p_SolutionModifier))));
	  driver.countStar = (yysemantic_stack_[(7) - (1)].p_parentCountStar);
      }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 814 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 822 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 825 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 832 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 840 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 847 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 855 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 862 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 865 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 868 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 871 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 874 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 877 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 880 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 889 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 892 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 900 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 903 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 909 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(2) - (2)].p_Operation);
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 915 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.lastWhereClause = (yysemantic_stack_[(4) - (3)].p_WhereClause);
	  /* $1 is NO LONGER known to be a DefaultGraphPattern because of grammar restrictions. */
	  (yyval.p_Operation) = new Construct((yysemantic_stack_[(4) - (1)].p_TableOperation), (yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
      }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 920 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	SWObjectDuplicator dup(driver.atomFactory);
	(yysemantic_stack_[(4) - (3)].p_TableOperation)->express(&dup);
	driver.lastWhereClause = new WhereClause((yysemantic_stack_[(4) - (3)].p_TableOperation));
	(yyval.p_Operation) = new Construct(dup.last.tableOperation, (yysemantic_stack_[(4) - (1)].p_DatasetClauses), driver.lastWhereClause, (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 930 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause) ? (yysemantic_stack_[(5) - (4)].p_WhereClause) : new WhereClause(new DefaultGraphPattern());
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 938 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm))));
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 941 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_TTerm))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 949 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 952 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 959 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 967 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(4) - (3)].p_WhereClause);
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 975 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 987 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 993 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 999 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1006 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.ensureGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1020 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1027 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1035 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1043 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1051 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1059 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1066 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1069 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1076 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1079 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1082 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1085 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1091 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1097 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1100 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1112 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1119 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1123 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1133 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1141 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1144 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1152 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1161 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1168 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1172 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1180 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1188 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1195 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1201 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1211 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = (yysemantic_stack_[(2) - (2)].p_BindingClause);
    }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1217 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1224 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	OperationSet* ret = driver.root ? dynamic_cast<OperationSet*>(driver.root) : new OperationSet();
	ret->push_back((yysemantic_stack_[(2) - (2)].p_Operation));
	driver.root = ret;
      }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1228 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Operation) = driver.root;
	}
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1266 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(4) - (2)].p_Silence), (yysemantic_stack_[(4) - (3)].p_URI), (yysemantic_stack_[(4) - (4)].p_URI));
    }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1272 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1275 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1282 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1289 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1296 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1302 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1308 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1314 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1320 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1326 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1332 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1340 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1348 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1355 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(6) - (1)].p_URI))
	    w3c_sw_NEED_IMPL("WITH <URI> (DELETE INSERT?|INSERT) ...");
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(6) - (2)].p_DeleteInsert).del, (yysemantic_stack_[(6) - (2)].p_DeleteInsert).ins, new WhereClause(driver.ensureGraphPattern()), (yysemantic_stack_[(6) - (4)].p_TableOperation));
	driver.curOp = NULL;
    }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1364 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1370 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1377 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1384 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1388 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1396 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("_QUsingClause_E_Star");
    }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1402 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(2) - (2)].p_TableOperation);
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1408 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = NULL;
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1415 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Delete) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1421 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = new Insert((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 1427 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1433 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 1436 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
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
	w3c_sw_NEED_IMPL("DEFAULT");
      }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1468 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("NAMED");
      }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 1471 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("ALL");
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
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.curOp));
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
	driver.curOp = new Print(driver.curOp);
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
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
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
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(6) - (5)].p_TTerm), driver.curOp, (yysemantic_stack_[(6) - (4)].p_Silence), driver.atomFactory, false));
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

  case 378:

/* Line 690 of lalr1.cc  */
#line 2102 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 2121 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 2149 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 2156 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 2167 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 2174 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 2186 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 2189 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::RDF_type;
    }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 2192 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 2195 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 2242 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 2246 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 2255 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 423:

/* Line 690 of lalr1.cc  */
#line 2283 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 2286 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 2289 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 2292 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 2295 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 2302 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 2310 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 2314 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 2326 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 2330 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject;
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 2338 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 437:

/* Line 690 of lalr1.cc  */
#line 2365 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 2369 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 2386 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 2393 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 2396 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 2407 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 2410 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 2413 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 2416 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 2420 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::RDF_nil; // !!! new GraphTerm_rule5($1);
    }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 2431 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 2440 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 2447 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 2450 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 2458 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 2467 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 2474 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 2477 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 2489 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 466:

/* Line 690 of lalr1.cc  */
#line 2502 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = NULL;
    }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 2510 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 2514 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 2518 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 2522 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 2526 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 2530 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 2534 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 2538 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = true;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 2550 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 2559 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 2562 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 2569 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 2572 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 2579 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 2587 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 2590 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 2594 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 487:

/* Line 690 of lalr1.cc  */
#line 2608 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 2611 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 2619 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 2628 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 2631 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 2638 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 2641 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 2644 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 2654 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 2657 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 2660 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 2663 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 2670 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 2676 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 2679 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 2682 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 2685 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 2688 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 2691 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
      (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), new TTermExpression(driver.atomFactory->getURI(driver.getBase())), NULL));
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 2694 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
      (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), new TTermExpression(driver.atomFactory->getURI(driver.getBase())), NULL));
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 2698 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 2701 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 2704 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 2707 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ceil, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 2710 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 2713 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 2716 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 2720 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 2724 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 2727 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 2730 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 2733 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 2736 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 2739 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 2742 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 2745 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 2748 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 2751 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 2754 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 2757 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 2760 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 2763 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 2766 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 2769 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_tz, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 2772 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 2775 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_uuid, NULL, NULL, NULL));
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 2778 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_struuid, NULL, NULL, NULL));
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 2781 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 2784 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 2787 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 2790 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 2793 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 2796 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 2799 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 2802 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 2805 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 2808 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 2811 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 2814 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 2817 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 2820 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 2823 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 2834 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 2837 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 2844 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 2851 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 2858 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 2864 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_replace, (yysemantic_stack_[(9) - (3)].p_Expression), (yysemantic_stack_[(9) - (5)].p_Expression), (yysemantic_stack_[(9) - (7)].p_Expression))); // !! , $8
    }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 2870 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 2873 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 2877 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expression) = new ExistsExpression(driver.ensureGraphPattern());
	  driver.curOp = (yysemantic_stack_[(4) - (3)].p_TableOperation);
	  driver.countStar = (yysemantic_stack_[(4) - (2)].p_parentCountStar);
      }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 2885 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
      }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 2888 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 2892 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  // $$ = new ExistsExpression(false, driver.ensureGraphPattern());
	  (yyval.p_Expression) = new BooleanNegation(new ExistsExpression(driver.ensureGraphPattern()));
	  driver.curOp = (yysemantic_stack_[(5) - (4)].p_TableOperation);
	  driver.countStar = (yysemantic_stack_[(5) - (3)].p_parentCountStar);
      }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 2901 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 2905 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 2910 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  AggregateCall::ScalarVals svals;
	  if ((yysemantic_stack_[(6) - (5)].p_RDFLiteral) != NULL)
	      svals["separator"] = (yysemantic_stack_[(6) - (5)].p_RDFLiteral)->getLexicalValue();
	  (yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression), svals));
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 2919 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 2926 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 2929 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 2932 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 2935 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 2938 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 2944 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 2950 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 2957 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 2967 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 2975 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 2983 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 2990 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 2994 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 3002 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 690 of lalr1.cc  */
#line 3946 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -839;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        49,  -111,    87,  -839,  -839,  -839,   667,  -839,  -839,  -839,
    -839,  -839,    88,    88,    88,    88,    59,     2,  -839,    43,
      88,    88,    59,    77,    88,    77,    89,  -839,   115,  -839,
    -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,  -839,  -839,  -839,   122,   131,  -839,    43,    37,
     153,    37,  -839,    42,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,   171,  -839,  -839,  -839,  -839,  -839,    50,  -839,
      46,    46,  -839,  -839,  -839,    46,  -839,   -12,  -839,  -839,
    -839,    56,  -839,   381,    59,    59,  -839,   158,  -839,  -839,
      57,  -839,   154,    43,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,   132,  1136,    10,    59,  -839,    50,  -839,    44,  -839,
      81,     3,  -839,  -839,    63,    43,    67,   163,    99,  -839,
    -839,   -49,  -839,     8,  -839,  -839,  -839,  1643,    50,  -839,
    -839,   164,  -839,  -839,    30,  -839,  -839,    40,   162,  -839,
    -839,  -839,   153,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,  -839,   184,  -839,  -839,  -839,  -839,   189,  -839,
    -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,   -31,  -839,
    -839,    43,  -839,  -839,  -839,  -839,  -839,    81,    81,    81,
    -839,   220,  -839,   160,  -839,  -839,  -839,  -839,  -839,    46,
    -839,    46,  -839,    46,  -839,  -839,  -839,   223,  -839,  2040,
     186,   226,   232,    14,    15,   245,   250,   257,   265,  -839,
     268,   269,   274,   276,   277,   278,   279,   284,   291,   293,
     304,    15,   317,  -839,  -839,  -839,  -839,   320,  -839,   321,
     175,   177,   333,   334,   336,   337,   192,   347,   203,   353,
     355,   356,   357,   358,   359,   360,   363,   364,   365,   366,
     367,   368,   369,   371,   376,   377,   378,   379,   382,   384,
     385,  -839,  -839,  2161,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,  -839,  -839,   386,  -839,  -839,  -839,    16,    81,
      49,  -839,  -839,    59,    13,  -839,   389,  -839,  -839,  -839,
     141,  -839,   103,   416,  1136,  -839,  -839,   103,  1870,   103,
      43,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  2403,
    2549,   406,  -839,   970,  -839,  -839,  -839,   395,    20,  -839,
    2040,  2282,  2282,  2282,  -839,   342,  -839,  -839,  -839,  -839,
     270,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,    16,  -839,  2040,  2040,  2040,  -839,  -839,  2040,
    -839,  -839,  2040,  2040,  2040,  2040,  -839,  2040,  2040,  2040,
    2040,   -49,  2040,  2040,  2040,  2040,  2040,  2040,  -839,   417,
     417,  2040,  -839,  -839,  2040,  2040,  2040,  2040,  -839,  2040,
    -839,  2040,  2040,  2040,  2040,  2040,  2040,  2040,  2040,  2040,
    2040,  2040,  2040,  2040,  2040,  2040,  2040,  2040,  2040,  2040,
    2040,  2040,  2040,  -839,   417,   417,  -839,  -839,  -839,   402,
    -839,  -839,    43,  -839,  -839,     3,   259,  -839,  2388,  -839,
    -839,  1501,  -839,  -839,   338,  -839,  -839,   282,  -839,  -839,
    -839,  -839,   387,  1870,  -839,  -839,   400,   439,  -839,  -839,
    -839,  -839,  -839,  1713,  -839,  -839,  -839,  -839,  2040,  2403,
    -839,  -839,  -839,  -839,  2549,  -839,  -839,  -839,  -839,  -839,
     421,   138,  -839,  -839,  -839,   115,   410,  -839,  -839,  -839,
     405,   409,  -839,  -839,  -839,  -839,  -839,  -839,  -839,     9,
     412,  -839,  -839,  -839,   -49,  -839,   413,   397,   401,  2040,
    2040,  2040,  2040,  2040,  2040,   391,    15,  -839,  -839,   212,
      48,  -839,  -839,  -839,   418,   419,   423,  -839,   414,   420,
     422,   424,     3,   425,   426,   429,   430,   433,   431,   437,
     440,   443,   445,   432,  -839,  1467,  2040,   446,   447,   442,
     444,   450,   452,   453,   454,   457,   460,   459,   467,   470,
     472,   466,   474,   475,   479,   477,   481,   487,   488,   489,
     493,   490,   495,   496,   499,  2040,  2040,  -839,  -839,  -839,
      54,  -839,  -839,  -839,  2427,  -839,  -839,   362,  -839,  -839,
    -839,  -839,  -839,  -839,  2427,  -839,  -839,   388,  -839,    36,
    -839,    -2,  -839,  -839,  -839,  -839,  -839,  1136,   171,  -839,
    -839,   342,  -839,  -839,  1336,   380,   383,  -839,  -839,   514,
     516,    70,  -839,  -839,    71,  1798,  -839,  -839,  1894,    70,
      70,   863,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  2040,
    -839,  2040,  -839,  -839,  -839,  -839,  -839,  -839,  -839,    15,
    -839,  2040,  2040,    48,  -839,  -839,  -839,  2040,  2040,  -839,
       3,  -839,  -839,  -839,  -839,  2040,  2040,  2040,  2040,  -839,
    -839,  -839,  2040,  -839,  -839,  2040,  -839,  -839,  -839,  -839,
    2040,  -839,  -839,   510,   503,  -839,  -839,  2040,  2040,  -839,
    -839,  -839,  -839,  -839,  -839,  2040,  -839,  -839,  -839,  2040,
    -839,  -839,  -839,  2040,  -839,  -839,  -839,  -839,  -839,  2040,
    -839,  -839,  -839,   517,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,   -44,  -839,  -839,  -839,    94,  -839,  -839,  -839,
     506,   513,  -839,  -839,   521,  -839,  -839,  1336,  -839,   523,
    -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
      98,  -839,    83,    90,   512,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,  -839,    68,  -839,  -839,  -839,  -839,  -839,  -839,
     -12,  -839,  -839,  2549,   525,     3,  -839,   400,  -839,  -839,
    -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  1822,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,    64,   522,   530,   532,   529,   537,   538,   533,
    -839,   504,  -839,   542,   543,   544,   545,   533,   546,   547,
    -839,  -839,  -839,  -839,  -839,  2388,  -839,  -839,  1501,   103,
    -839,  1870,  -839,   555,  -839,  -839,  -839,   551,   166,  -839,
      52,  -839,  -839,  -839,  -839,  -839,  1894,   492,   534,  -839,
    -839,  -839,  -839,  -839,   559,  -839,  -839,  -839,  -839,     3,
    -839,  -839,  2040,  -839,  1798,     3,  -839,  -839,  1085,  -839,
    2040,  -839,  2040,  -839,  -839,  2040,  -839,  -839,  -839,   558,
     550,  -839,  -839,  -839,  -839,   560,  -839,  -839,    73,  1171,
    -839,  -839,  -839,  -839,  1870,  -839,  -839,  -839,  -839,   561,
    -839,  -839,  -839,  -839,  -839,  -839,  -839,    98,  -839,    98,
    -839,    81,   171,    88,    88,  -839,     3,   518,  -839,  -839,
    -839,  -839,  -839,   565,   533,  -839,   165,  -839,  -839,  -839,
    -839,   552,   -21,  -839,  1136,  -839,   515,   566,   568,  -839,
    -839,    89,  -839,   171,   171,  -839,   -49,   563,  -839,   576,
    -839,  -839,  -839,  2427,  2427,  2427,   582,   166,  -839,    70,
    -839,  1894,  -839,  -839,     3,     3,   598,   580,  -839,  -839,
    -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,    59,  -839,     3,  1870,   559,  -839,  -839,  -839
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
       0,     0,   226,     0,   101,    74,   108,   612,   615,   614,
     447,   448,   107,    74,   105,   445,   446,   613,   119,   198,
     217,   217,   196,   226,   195,   217,   194,   286,     5,   162,
     159,    83,    74,   199,     0,     0,   205,   201,   204,    69,
      11,    15,   186,     0,   222,   221,   223,   220,   188,   190,
     189,     0,   228,     0,     0,    75,   119,   106,   109,   120,
     122,     0,   218,   215,     0,     0,     0,     0,     0,   160,
     284,     0,   285,     0,    81,    82,    84,     0,   119,   170,
     164,   166,   210,   211,   208,   203,   202,     0,     0,    17,
      22,    18,     0,   187,   182,   219,   224,   423,   424,   425,
     426,   427,   420,   606,   607,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   608,   610,   609,   611,   616,   617,
     454,   233,   229,   241,   340,   419,   418,   429,     0,   338,
     443,   444,   450,   451,   594,   595,   596,   452,   592,   449,
     453,     0,   112,   113,   114,   115,   117,   122,   122,   122,
     110,     0,   111,   124,   123,   247,   244,   118,   243,   217,
     216,   217,   225,   217,   287,   294,   296,     0,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   566,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   577,   578,   579,   580,     0,   581,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    99,    80,    95,    93,    89,   556,   519,
     521,   557,   558,    94,     0,    90,    91,    92,     0,   122,
      12,   167,   168,     0,     0,   209,     0,   206,    70,    20,
       0,   185,     0,   227,   228,   242,   239,   343,   428,     0,
       0,   590,   591,   593,   588,   116,   103,   102,   104,     0,
       0,   126,   125,   250,   191,   193,   192,     0,     0,   303,
       0,     0,     0,     0,   502,    86,   455,   458,   462,   464,
     466,   476,   487,   490,   495,   496,   497,   503,   498,   499,
     500,   501,   586,   569,     0,     0,     0,   560,   512,     0,
     335,   546,     0,     0,     0,     0,   567,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   518,   330,
     330,     0,   539,   540,     0,     0,     0,     0,   513,     0,
     538,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    98,   330,   330,   327,   326,    73,   199,
     165,   207,     0,   212,   213,     0,     0,    56,     0,    31,
      45,     0,    19,    23,     0,    29,    24,     0,    43,    25,
      26,   353,     0,   428,   352,   234,   230,     0,   240,   341,
     342,   344,   440,   428,   430,   439,   339,   589,     0,   130,
     131,   134,   136,   133,   137,   138,   140,   325,   323,   324,
       0,   128,   127,   434,   245,     0,     0,   246,   253,   251,
     257,     0,   361,   433,   432,   359,   289,   297,   295,     0,
       0,   493,   494,   492,     0,    87,     0,   456,   460,     0,
       0,     0,     0,     0,     0,     0,     0,   465,   467,   477,
     489,   587,   585,   570,     0,     0,     0,   336,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   331,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   214,   197,    71,
       0,   309,    35,   310,    36,    32,    33,     0,   311,   306,
     307,   308,   305,    49,    50,    46,    47,     0,    29,     0,
      43,     0,   421,   350,   356,   358,   231,   228,     0,   422,
     431,    86,   132,   139,     0,     0,     0,   121,   129,   153,
     155,     0,    77,   248,   315,   250,   258,   255,   428,   364,
       0,     0,   293,   300,   302,   304,   504,    85,    88,     0,
     459,     0,   463,   468,   469,   470,   471,   472,   473,     0,
     474,     0,     0,   482,   488,   478,   479,     0,     0,   491,
       0,   510,   511,   559,   333,     0,     0,     0,     0,   568,
     505,   506,     0,   508,   509,     0,   551,   552,   553,   554,
       0,   575,   576,     0,   583,   555,   541,     0,     0,   530,
     545,   537,   536,   517,   544,     0,   535,   516,   534,     0,
     543,   533,   524,     0,   515,   532,   523,   514,   522,     0,
     520,   542,   531,     0,   328,    55,    58,    57,    34,    39,
      48,    53,     0,    28,    37,    30,     0,    42,    51,    44,
     345,   354,   232,   236,     0,   146,   147,   141,   142,     0,
     144,   145,   149,   150,   157,   158,   151,   154,   152,   156,
       0,   402,     0,     0,     0,   366,   368,   369,   377,   384,
     387,   396,   391,   394,   378,   401,    78,   272,   276,   279,
     286,   270,   312,     0,     0,     0,   254,   230,   268,   260,
     262,   263,   264,   266,   267,   261,   259,   316,   265,   256,
     442,   428,   437,   441,   362,   363,   365,   360,   288,   290,
     291,   298,   457,   461,   475,   484,   485,   483,   486,   480,
     481,   571,     0,     0,     0,     0,     0,     0,     0,   562,
     572,     0,   584,     0,     0,     0,     0,   562,     0,     0,
     573,   333,    63,    40,    27,     0,    54,    41,     0,   347,
     351,   428,   357,     0,   135,   143,   148,     0,   411,   414,
       0,   403,   405,   413,   397,   435,   428,   385,   389,   399,
     400,   398,   393,   395,   119,   273,   277,   280,   283,     0,
     313,   322,     0,   269,   250,     0,   436,   438,     0,   337,
       0,   334,     0,   548,   549,     0,   507,   550,   563,     0,
       0,   574,   528,   529,   525,     0,   526,   527,     0,     0,
      38,    52,   348,   349,   428,   355,   237,   404,   412,     0,
     408,   417,   415,   416,   375,   381,   383,     0,   388,     0,
     392,   122,     0,   183,   183,   271,     0,     0,   252,   320,
     301,   299,   332,     0,   562,   561,     0,   564,   329,    59,
      64,    60,     0,   346,   228,   406,   410,   367,   379,   386,
     390,   161,   274,     0,     0,   314,     0,   317,   547,     0,
     582,    61,    62,     0,     0,     0,     0,     0,   409,   372,
     376,   428,   382,    79,     0,     0,     0,     0,   318,   321,
     565,    67,    66,    65,   238,   407,   370,   373,   374,   380,
     275,   278,     0,   282,     0,   428,   119,   319,   371,   281
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -839,  -839,  -839,  -839,  -839,  -839,   324,  -839,  -839,  -839,
    -839,  -839,  -839,  -839,  -839,  -839,    27,  -839,   182,  -839,
    -205,  -839,  -839,    47,  -839,  -839,    32,  -839,   180,  -839,
    -204,  -839,  -839,    39,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,    45,
    -839,  -839,  -839,  -839,   151,  -839,  -839,  -839,    26,  -839,
     370,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,  -839,  -839,  -152,   -98,  -839,  -181,  -839,  -839,
    -839,  -839,  -839,  -839,   169,  -839,  -839,   167,  -839,  -839,
     -97,  -839,  -839,  -839,  -839,  -839,  -839,    19,    24,  -306,
    -839,  -839,   348,  -839,  -839,  -839,  -839,  -839,   564,  -839,
      -9,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,   567,  -839,  -839,    18,  -839,     4,   604,   -13,   631,
     585,  -839,  -300,  -116,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,  -839,  -399,  -839,  -839,  -839,  -839,  -605,  -839,
    -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
    -108,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,  -839,  -839,  -395,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,  -839,  -839,  -839,  -587,  -103,   302,  -839,  -320,
    -753,  -166,  -208,  -839,  -839,  -839,  -839,  -839,  -839,  -220,
    -839,  -839,  -839,  -839,  -173,  -838,  -839,  -839,  -174,  -839,
    -839,  -839,  -839,  -839,  -372,  -839,  -301,  -839,  -839,  -839,
    -839,  -839,  -839,  -839,  -839,  -839,  -839,  -302,   -80,  -839,
    -839,  -839,  -246,  -839,  -839,   -81,  -839,  -245,  -839,  -839,
    -839,  -839,  -839,  -839,  -839,  -807,  -839,  -101,  -839,  -839,
    -839,  -839,  -314,  -839,  -326,  -839,  -839,  -839,  -839,  -286,
    -602,   -79,   -14,    21,  -839,   825,  -839,  -839,  -839,    34,
    -839,  -839,    41,  -839,  -839,  -839,  -141,  -839,  -839,    33,
    -839,  -839,  -839,  -375,  -839,  -376,  -100,  -309,  -114,  -839,
    -839,  -783,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
    -102,  -839,  -839,  -839,  -839,  -839,  -839,   -74,  -839,  -839,
    -839,   120,  -839,   161,   168,   222,  -259,   -17,  -839,  -839
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
     484,   485,   766,   864,    82,   126,   127,   505,   506,   281,
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
     922,   974,   781,   866,   923,   782,   867,   924,   783,   784,
     119,   120,   121,   337,   631,   799,   122,   123,   338,   217,
     878,   635,   801,   499,   587,   785,   870,   926,   786,   787,
     875,   979,   994,   957,   788,   476,   477,   427,   831,   545,
     888,   812,   371,   664,   173,   319,   317,   459,   460,   452,
     902,   903,   840,   730,   453,   603,   842,   731,   604,   490,
     630,   629,   794,   795,   754,   856,   755,   987,   995,   988,
     970,   947,   756,   757,   914,   972,   948,   915,   758,   759,
     918,   857,   760,   920,   858,   761,   862,   762,   863,   763,
     851,   968,   946,   908,   909,   852,   912,   462,   175,   312,
     176,   177,   178,   463,   790,   493,   621,   494,   791,   605,
     916,   465,   454,   344,   181,   345,   346,   640,   507,   347,
     642,   508,   348,   349,   517,   518,   350,   351,   653,   659,
     808,   654,   519,   352,   520,   353,   354,   355,   356,   368,
     288,   889,   289,   290,   291,   376,   532,   292,   523,   660,
     357,   683,   294,   822,   823,   358,   522,   359,   322,   323,
     324,   360,   184,   185,   186,   361,   188,   362,    67,   190
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int SPARQLfedParser::yytable_ninf_ = -429;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        66,   174,    69,    64,    49,    50,    51,   492,   198,    72,
     200,    70,    71,   287,   458,    75,   326,   327,   328,   491,
     789,   478,    56,   179,   285,   293,   792,   742,   182,  -292,
     299,    92,   464,   388,   191,   963,   578,   432,    65,   325,
     205,   910,   727,    93,   895,    66,   597,   632,   107,   215,
     633,   303,   112,   295,    99,   366,   369,   425,   320,   881,
     724,    94,   497,    68,     1,   103,   943,   103,   657,    10,
     546,   132,   133,   103,   124,   125,   145,   767,   768,   769,
     723,  -119,   104,    65,   109,   189,   196,    11,   859,   116,
     109,   197,   715,   118,   -21,   716,    52,   461,   210,   466,
     106,    47,   770,   911,   575,   576,   879,   833,   108,  -249,
     298,   750,   658,   880,    73,   938,   771,   772,   428,   773,
      77,   751,   880,   180,   848,    84,    85,   128,   964,   965,
     860,   750,    81,   669,   849,   752,    60,    61,   304,   750,
     724,   751,   214,    95,    96,   881,   311,    89,   286,   751,
     742,   959,   113,   728,   451,   752,   321,   998,   450,    93,
     985,   -21,    85,   752,   142,   478,   206,   615,   616,   287,
     146,   861,   753,   201,   196,   209,  -292,   610,   437,   211,
     285,   293,    57,    58,    59,   850,   871,    60,    61,   877,
      57,    58,    59,    57,    58,    59,   216,   634,   774,   597,
     753,   212,   367,   370,   426,    60,    61,  -119,   -21,   295,
     -21,   213,   -21,   174,   300,   473,   479,   849,   309,   775,
     138,   308,   183,    57,    58,    59,   471,   334,   314,   335,
     318,   336,    57,    58,    59,   179,   800,   -21,   -21,   -21,
     182,   501,   502,   503,   182,   438,   329,   296,   836,   728,
      57,    58,    59,   330,   495,    60,    61,   796,   797,   182,
     339,   811,   363,    57,    58,    59,   298,   364,   850,   928,
      57,    58,    59,   365,   651,   652,   805,   806,    57,    58,
      59,   809,   810,    57,    58,    59,   372,   434,    60,    61,
     431,   373,   439,   196,   440,    66,   441,   189,   374,   492,
      66,   189,    66,   467,   286,   478,   375,   732,   650,   377,
     378,   491,   298,   298,   491,   379,   189,   380,   381,   382,
     383,    57,    58,    59,   187,   384,   509,   510,   511,   512,
     513,   514,   385,    65,   386,   180,   515,   516,    65,   180,
      65,   164,   165,   166,   167,   387,    57,    58,    59,   297,
     472,    57,    58,    59,   180,   473,    60,    61,   389,   498,
     479,   390,   391,   392,   589,   393,   471,   589,   643,   644,
     645,   646,   647,   648,   394,   395,   873,   396,   397,   182,
     398,  -169,   158,   159,   160,   161,   162,   163,   399,   182,
      12,   400,    13,    14,   401,    15,   402,   403,   404,   405,
     406,   407,   537,   296,   408,   409,   410,   411,   412,   413,
     414,    12,   415,    13,    14,   577,    15,   416,   417,   418,
     419,   592,  -235,   420,   592,   421,   422,   424,   478,   435,
     846,   480,   496,   504,   183,   544,   189,   441,   183,   579,
     602,   804,   438,   597,   606,   608,   189,   614,   623,   625,
     628,   639,   298,   183,   636,   638,   641,   298,   649,   588,
     661,   662,   588,   665,   478,   663,   719,   670,   671,   666,
     925,   667,   673,   668,   180,   674,   929,   491,   672,   676,
     675,   680,   677,   931,   180,   678,    19,   679,   685,   686,
     472,   687,   689,   688,   690,   691,   692,    20,    21,   693,
     479,    22,   694,    23,   942,   297,   174,    19,   695,   696,
     589,    24,   697,    25,   698,   699,   700,   701,    20,    21,
     589,   702,    22,   704,    23,   637,   703,   955,   179,   705,
     706,   707,    24,   182,    25,   708,   187,   710,   711,   709,
     187,   712,   491,   721,   616,   615,   495,   744,   492,   793,
     745,   182,   820,   821,   182,   187,   839,   589,   590,   830,
     491,   590,   841,   844,   340,   855,   872,   592,   981,   982,
     983,   882,   883,   183,   884,   990,   991,   592,   885,   886,
     887,   890,   880,   183,   891,   892,   893,   894,   896,   897,
     189,    66,   906,   907,   733,   997,   917,   298,   919,   109,
     935,   961,   937,   945,   765,   588,   936,   958,   189,   956,
     978,   189,   765,   765,   592,   588,   969,   971,   980,   967,
     984,   992,   993,   479,   429,   722,   598,   600,   180,    65,
     900,   718,   726,   720,   901,   743,   622,   734,   612,   749,
     845,   613,   764,   747,   966,   973,   180,   131,   430,   180,
     764,   764,   588,   423,   136,   100,    76,   491,   117,   479,
     591,   874,   868,   591,   521,   898,   904,   905,   986,   989,
     847,   949,   854,   802,   950,   187,    12,   960,    13,    14,
     655,    15,   803,     0,   -72,   187,   807,   656,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   590,     0,    18,     0,     0,     0,
       0,     0,   793,     0,   590,     0,     0,   182,     0,     0,
     298,     0,     0,     0,     0,     0,     0,   183,     0,     0,
       0,     0,     0,   765,     0,   853,   765,     0,     0,     0,
     951,     0,     0,     0,     0,   183,     0,     0,   183,     0,
       0,   590,     0,     0,     0,     0,   298,     0,   743,     0,
       0,   589,     0,     0,   589,     0,   921,   182,     0,     0,
       0,     0,    19,     0,   189,     0,     0,   793,     0,     0,
       0,     0,   182,    20,    21,     0,     0,    22,     0,    23,
       0,     0,     0,     0,     0,   495,     0,    24,     0,    25,
     182,     0,     0,     0,   589,     0,   591,     0,     0,     0,
       0,     0,   180,     0,     0,     0,   591,     0,   592,     0,
       0,   592,    66,     0,   189,   589,     0,     0,     0,   187,
     182,   853,     0,   913,     0,     0,     0,     0,     0,   189,
       0,     0,     0,   174,     0,     0,     0,   187,     0,     0,
     187,     0,     0,   591,     0,     0,   588,   189,     0,   588,
      65,   592,   180,     0,     0,   179,     0,     0,     0,     0,
     182,     0,     0,     0,     0,     0,     0,   180,     0,     0,
       0,     0,   592,     0,     0,     0,     0,   189,     0,   589,
     589,   589,   793,     0,     0,   180,     0,   182,   999,   588,
     765,   798,   765,     0,     0,    66,   581,     0,   952,     0,
       0,   183,     0,     0,   953,   954,     0,     0,     0,     0,
     588,   182,     0,     0,     0,   180,     0,   189,     0,     0,
       0,     0,     0,     0,     0,     0,    66,    66,     0,   975,
     976,     0,     0,    65,     0,     0,   592,   592,   592,     0,
     853,     0,   765,     0,   189,   590,     0,     0,   590,     0,
       0,   183,     0,     0,     0,   180,     0,     0,     0,     0,
       0,     0,     0,     0,    65,    65,   183,   977,   189,   996,
       0,     0,     0,     0,   588,   588,   588,   -76,     0,     0,
     764,     0,   180,     0,   183,     0,     0,     0,   590,     0,
       0,     0,   147,   148,   149,   150,   151,     0,     0,     0,
       0,  -428,     0,   187,     0,     0,   180,     0,     0,   590,
       0,     0,   483,     0,   183,     0,     0,   583,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    57,    58,    59,     0,     0,    60,    61,
       0,     0,     0,     0,     0,     0,     0,   591,     0,     0,
     591,     0,     0,   187,   183,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   187,     0,
       0,     0,     0,   590,   590,   590,     0,     0,     0,     0,
       0,   183,     0,     0,     0,     0,   187,     0,     0,     0,
     591,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   183,     0,     0,     0,     0,
       0,   591,     0,     0,     0,     0,   187,   930,   581,     0,
       0,     0,     0,     0,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      57,    58,    59,   168,   169,    60,    61,     0,   170,     0,
       0,     0,     0,     0,     0,   500,   187,     0,   147,   148,
     149,   150,   151,     0,     0,     0,     0,  -428,     0,     0,
       0,     0,     0,     0,     0,   591,   591,   591,   152,   524,
     525,   526,     0,   187,   527,     0,     0,   528,   529,   530,
     531,     0,   533,   534,   535,   536,     0,   538,   539,   540,
     541,   542,   543,   939,   581,     0,   547,   187,     0,   548,
     549,   550,   551,     0,   552,     0,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,     0,   583,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    57,    58,    59,     0,     0,
      60,    61,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   611,     0,     0,     0,     0,     0,     0,
       0,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    57,    58,    59,   168,
     169,    60,    61,     0,   170,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   583,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    57,    58,    59,     0,     0,    60,    61,     0,     0,
       0,     0,     0,   735,   736,     0,     0,     0,     0,     0,
     682,   684,     0,     0,     0,     0,     0,   340,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     713,   714,   220,     0,   221,   222,   223,   224,   225,   226,
     227,   228,   229,     0,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,   241,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   249,     0,     0,
       0,     0,     0,     0,     0,   250,   251,   252,     0,   253,
     254,   255,     0,     0,   256,   257,     0,   258,     0,   259,
     260,   261,   262,     0,   263,   264,     0,   265,     0,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,     0,     0,     0,   681,     0,     0,
     813,   814,   815,   816,     0,     0,     0,   817,     0,     0,
     818,     0,     0,     0,     0,   819,     0,     0,   340,     0,
       0,     0,   824,   825,     0,     0,    57,    58,    59,     0,
     826,    60,    61,     0,   827,     0,     0,     0,   828,   341,
     342,     0,   343,   220,   829,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   581,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,     0,   241,     0,     0,
       0,   242,   243,   244,   245,   246,   247,   248,   249,     0,
       0,     0,     0,     0,     0,     0,   250,   251,   252,     0,
     253,   254,   255,     0,     0,   256,   257,     0,   258,     0,
     259,   260,   261,   262,     0,   263,   264,     0,   265,     0,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    57,    58,    59,
       0,     0,    60,    61,     0,     0,   593,     0,     0,     0,
       0,     0,     0,   218,     0,   583,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    57,    58,    59,   219,     0,    60,    61,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   927,     0,     0,
       0,     0,     0,     0,     0,   932,     0,   933,     0,   220,
     934,   221,   222,   223,   224,   225,   226,   227,   228,   229,
       0,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,     0,   241,     0,     0,     0,   242,   243,   244,
     245,   246,   247,   248,   249,   147,   148,   149,   150,   151,
       0,     0,   250,   251,   252,   609,   253,   254,   255,     0,
       0,   256,   257,     0,   258,   152,   259,   260,   261,   262,
       0,   263,   264,     0,   265,     0,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    57,    58,    59,     0,     0,    60,    61,
     147,   148,   149,   150,   151,     0,     0,     0,     0,  -428,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     483,     0,     0,     0,   147,   148,   149,   150,   151,     0,
       0,     0,     0,     0,   876,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   483,     0,     0,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    57,    58,    59,   168,   169,    60,    61,
       0,   170,   147,   148,   149,   150,   151,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   152,     0,     0,     0,   147,   148,   149,   150,
     151,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   483,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    57,    58,
      59,   168,   169,    60,    61,     0,   170,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    57,    58,    59,   168,   169,    60,    61,     0,
     170,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      57,    58,    59,   168,   169,    60,    61,     0,   170,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    57,    58,    59,   168,   169,    60,
      61,   340,   170,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   341,   342,     0,   343,   220,     0,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
     241,     0,     0,     0,   242,   243,   244,   245,   246,   247,
     248,   249,     0,     0,     0,     0,     0,     0,     0,   250,
     251,   252,     0,   253,   254,   255,     0,     0,   256,   257,
       0,   258,     0,   259,   260,   261,   262,     0,   263,   264,
       0,   265,     0,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   219,     0,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      57,    58,    59,     0,     0,    60,    61,   220,     0,   221,
     222,   223,   224,   225,   226,   227,   228,   229,     0,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
       0,   241,     0,     0,     0,   242,   243,   244,   245,   246,
     247,   248,   249,     0,     0,     0,     0,     0,     0,     0,
     250,   251,   252,     0,   253,   254,   255,     0,     0,   256,
     257,     0,   258,     0,   259,   260,   261,   262,     0,   263,
     264,     0,   265,     0,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   340,     0,     0,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    57,    58,    59,     0,     0,    60,    61,   220,     0,
     221,   222,   223,   224,   225,   226,   227,   228,   229,     0,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,     0,     0,     0,   242,   243,   244,   245,
     246,   247,   248,   249,     0,     0,     0,     0,     0,     0,
       0,   250,   251,   252,     0,   253,   254,   255,     0,     0,
     256,   257,     0,   258,     0,   259,   260,   261,   262,     0,
     263,   264,     0,   265,     0,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
       0,   581,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   468,     0,     0,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    57,    58,    59,     0,     0,    60,    61,   220,
     581,   221,   222,   223,   224,   225,   226,   227,   228,   229,
       0,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   582,   241,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   249,     0,     0,     0,     0,     0,
       0,     0,   250,   251,   252,     0,   253,   254,   255,     0,
       0,   256,   257,     0,   258,     0,   259,   260,   261,   262,
       0,   263,   264,     0,   265,     0,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,     0,   583,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    57,    58,
      59,     0,     0,    60,    61,     0,     0,     0,     0,     0,
       0,     0,     0,    57,    58,    59,     0,     0,    60,    61,
     340,   583,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    57,    58,    59,
       0,     0,    60,    61,     0,   220,     0,   221,   222,   223,
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
        17,   102,    19,    17,    13,    14,    15,   333,   106,    22,
     108,    20,    21,   127,   314,    24,   197,   198,   199,   333,
     625,   330,    20,   102,   127,   127,   628,   614,   102,    41,
     128,    48,   318,   241,    24,    56,   435,    24,    17,   191,
      37,   848,    44,     6,   827,    62,   441,    38,    62,    41,
      41,    21,     6,   127,    50,    41,    41,    41,    89,   812,
     104,    24,    42,    18,    15,    23,   904,    23,    20,   180,
     390,    84,    85,    23,    18,    19,    93,     6,     7,     8,
      44,    37,    40,    62,    40,   102,   103,     0,    20,    71,
      40,   104,    38,    75,    37,    41,    37,   317,   115,   319,
      55,    13,    31,    51,   424,   425,    42,   151,    63,    38,
     127,    41,    64,    49,    37,    42,    45,    46,   299,    48,
      31,    51,    49,   102,    41,     3,     4,    82,   149,   150,
      62,    41,    17,   532,    51,    65,   185,   186,   108,    41,
     104,    51,   121,   106,   107,   898,   142,    16,   127,    51,
     737,   934,   106,   155,    51,    65,   187,   995,   310,     6,
     967,   104,     4,    65,    10,   474,   163,    29,    30,   283,
      38,   103,   102,    92,   191,   112,   188,   463,    37,   112,
     283,   283,   180,   181,   182,   102,   773,   185,   186,   791,
     180,   181,   182,   180,   181,   182,   188,   188,   127,   594,
     102,    38,   188,   188,   188,   185,   186,   163,   151,   283,
     153,   112,   155,   314,    50,   329,   330,    51,    56,   148,
     163,   181,   102,   180,   181,   182,   329,   209,    44,   211,
      41,   213,   180,   181,   182,   314,   631,   180,   181,   182,
     314,   341,   342,   343,   318,   104,    26,   127,   154,   155,
     180,   181,   182,    93,   333,   185,   186,   629,   630,   333,
      37,   660,    76,   180,   181,   182,   283,    41,   102,   874,
     180,   181,   182,    41,    62,    63,   651,   652,   180,   181,
     182,   657,   658,   180,   181,   182,    41,   304,   185,   186,
     303,    41,   151,   310,   153,   312,   155,   314,    41,   625,
     317,   318,   319,   320,   283,   614,    41,   607,   516,    41,
      41,   625,   329,   330,   628,    41,   333,    41,    41,    41,
      41,   180,   181,   182,   102,    41,    56,    57,    58,    59,
      60,    61,    41,   312,    41,   314,    66,    67,   317,   318,
     319,   176,   177,   178,   179,    41,   180,   181,   182,   127,
     329,   180,   181,   182,   333,   469,   185,   186,    41,   338,
     474,    41,    41,   188,   438,   188,   469,   441,   509,   510,
     511,   512,   513,   514,    41,    41,   775,    41,    41,   453,
     188,     0,   170,   171,   172,   173,   174,   175,    41,   463,
       9,   188,    11,    12,    41,    14,    41,    41,    41,    41,
      41,    41,   381,   283,    41,    41,    41,    41,    41,    41,
      41,     9,    41,    11,    12,   432,    14,    41,    41,    41,
      41,   438,     6,    41,   441,    41,    41,    41,   737,    40,
     739,    25,    37,    91,   314,    18,   453,   155,   318,   180,
      53,   649,   104,   838,    44,     6,   463,    26,    38,    44,
      41,    54,   469,   333,    42,    42,    55,   474,    67,   438,
      42,    42,   441,    49,   773,    42,   104,    42,    42,    49,
     869,    49,    42,    49,   453,    42,   875,   791,    49,    42,
      49,    49,    42,   878,   463,    42,   105,    42,    42,    42,
     469,    49,    42,    49,    42,    42,    42,   116,   117,    42,
     614,   120,    42,   122,   899,   283,   607,   105,    49,    42,
     584,   130,    42,   132,    42,    49,    42,    42,   116,   117,
     594,    42,   120,    42,   122,   504,    49,   926,   607,    42,
      42,    42,   130,   607,   132,    42,   314,    42,    42,    49,
     318,    42,   856,   155,    30,    29,   625,   167,   874,   628,
     167,   625,    42,    50,   628,   333,    50,   631,   438,    42,
     874,   441,    49,    42,    41,    53,    41,   584,   963,   964,
     965,    49,    42,   453,    42,   974,   975,   594,    49,    42,
      42,    77,    49,   463,    42,    42,    42,    42,    42,    42,
     607,   608,    37,    42,   608,   994,   104,   614,    64,    40,
      42,    49,    42,    42,   621,   584,    56,    42,   625,    91,
      47,   628,   629,   630,   631,   594,    50,    49,    42,   104,
      38,    23,    42,   737,   300,   598,   444,   447,   607,   608,
     835,   584,   600,   594,   838,   614,   485,   611,   469,   620,
     737,   474,   621,   619,   944,   951,   625,    83,   300,   628,
     629,   630,   631,   283,    87,    51,    25,   971,    73,   773,
     438,   777,   770,   441,   362,   831,   839,   841,   969,   971,
     750,   917,   753,   639,   919,   453,     9,   936,    11,    12,
     519,    14,   641,    -1,    17,   463,   653,   519,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   584,    -1,    39,    -1,    -1,    -1,
      -1,    -1,   791,    -1,   594,    -1,    -1,   791,    -1,    -1,
     737,    -1,    -1,    -1,    -1,    -1,    -1,   607,    -1,    -1,
      -1,    -1,    -1,   750,    -1,   752,   753,    -1,    -1,    -1,
     921,    -1,    -1,    -1,    -1,   625,    -1,    -1,   628,    -1,
      -1,   631,    -1,    -1,    -1,    -1,   773,    -1,   737,    -1,
      -1,   835,    -1,    -1,   838,    -1,   864,   841,    -1,    -1,
      -1,    -1,   105,    -1,   791,    -1,    -1,   856,    -1,    -1,
      -1,    -1,   856,   116,   117,    -1,    -1,   120,    -1,   122,
      -1,    -1,    -1,    -1,    -1,   874,    -1,   130,    -1,   132,
     874,    -1,    -1,    -1,   878,    -1,   584,    -1,    -1,    -1,
      -1,    -1,   791,    -1,    -1,    -1,   594,    -1,   835,    -1,
      -1,   838,   839,    -1,   841,   899,    -1,    -1,    -1,   607,
     904,   848,    -1,   850,    -1,    -1,    -1,    -1,    -1,   856,
      -1,    -1,    -1,   944,    -1,    -1,    -1,   625,    -1,    -1,
     628,    -1,    -1,   631,    -1,    -1,   835,   874,    -1,   838,
     839,   878,   841,    -1,    -1,   944,    -1,    -1,    -1,    -1,
     944,    -1,    -1,    -1,    -1,    -1,    -1,   856,    -1,    -1,
      -1,    -1,   899,    -1,    -1,    -1,    -1,   904,    -1,   963,
     964,   965,   971,    -1,    -1,   874,    -1,   971,   996,   878,
     917,    38,   919,    -1,    -1,   922,    43,    -1,   922,    -1,
      -1,   791,    -1,    -1,   923,   924,    -1,    -1,    -1,    -1,
     899,   995,    -1,    -1,    -1,   904,    -1,   944,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   953,   954,    -1,   953,
     954,    -1,    -1,   922,    -1,    -1,   963,   964,   965,    -1,
     967,    -1,   969,    -1,   971,   835,    -1,    -1,   838,    -1,
      -1,   841,    -1,    -1,    -1,   944,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   953,   954,   856,   956,   995,   992,
      -1,    -1,    -1,    -1,   963,   964,   965,    17,    -1,    -1,
     969,    -1,   971,    -1,   874,    -1,    -1,    -1,   878,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    41,    -1,   791,    -1,    -1,   995,    -1,    -1,   899,
      -1,    -1,    52,    -1,   904,    -1,    -1,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,    -1,    -1,   185,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   835,    -1,    -1,
     838,    -1,    -1,   841,   944,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   856,    -1,
      -1,    -1,    -1,   963,   964,   965,    -1,    -1,    -1,    -1,
      -1,   971,    -1,    -1,    -1,    -1,   874,    -1,    -1,    -1,
     878,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   995,    -1,    -1,    -1,    -1,
      -1,   899,    -1,    -1,    -1,    -1,   904,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,   340,   944,    -1,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   963,   964,   965,    52,   364,
     365,   366,    -1,   971,   369,    -1,    -1,   372,   373,   374,
     375,    -1,   377,   378,   379,   380,    -1,   382,   383,   384,
     385,   386,   387,    42,    43,    -1,   391,   995,    -1,   394,
     395,   396,   397,    -1,   399,    -1,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,    -1,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,    -1,    -1,
     185,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   468,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    -1,   188,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,    -1,    -1,   185,   186,    -1,    -1,
      -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,
     545,   546,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     575,   576,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,   113,
     114,   115,    -1,    -1,   118,   119,    -1,   121,    -1,   123,
     124,   125,   126,    -1,   128,   129,    -1,   131,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    20,    -1,    -1,
     665,   666,   667,   668,    -1,    -1,    -1,   672,    -1,    -1,
     675,    -1,    -1,    -1,    -1,   680,    -1,    -1,    41,    -1,
      -1,    -1,   687,   688,    -1,    -1,   180,   181,   182,    -1,
     695,   185,   186,    -1,   699,    -1,    -1,    -1,   703,    62,
      63,    -1,    65,    66,   709,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    43,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    90,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,
     113,   114,   115,    -1,    -1,   118,   119,    -1,   121,    -1,
     123,   124,   125,   126,    -1,   128,   129,    -1,   131,    -1,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
      -1,    -1,   185,   186,    -1,    -1,   155,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,    41,    -1,   185,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   872,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   880,    -1,   882,    -1,    66,
     885,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    90,    -1,    -1,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,    32,    33,    34,    35,    36,
      -1,    -1,   109,   110,   111,    42,   113,   114,   115,    -1,
      -1,   118,   119,    -1,   121,    52,   123,   124,   125,   126,
      -1,   128,   129,    -1,   131,    -1,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,    -1,    -1,   185,   186,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
      -1,   188,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    -1,   188,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
     188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,   188,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    41,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    -1,    65,    66,    -1,    68,    69,
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
     139,   140,   141,   142,   143,   144,   145,   146,   147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,    -1,    -1,   185,   186,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    -1,    90,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   109,   110,   111,    -1,   113,   114,   115,    -1,    -1,
     118,   119,    -1,   121,    -1,   123,   124,   125,   126,    -1,
     128,   129,    -1,   131,    -1,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    -1,    -1,   185,   186,    66,
      43,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,   104,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,   110,   111,    -1,   113,   114,   115,    -1,
      -1,   118,   119,    -1,   121,    -1,   123,   124,   125,   126,
      -1,   128,   129,    -1,   131,    -1,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,   185,   186,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,   185,   186,
      41,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
      -1,    -1,   185,   186,    -1,    66,    -1,    68,    69,    70,
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
         0,    15,   190,   191,   192,   194,   195,   196,   232,   291,
     180,     0,     9,    11,    12,    14,    21,    22,    39,   105,
     116,   117,   120,   122,   130,   132,   193,   236,   237,   252,
     254,   258,   297,   298,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   197,    13,   299,   299,
     299,   299,    37,   238,   253,   327,    20,   180,   181,   182,
     185,   186,   255,   256,   471,   472,   526,   527,   238,   526,
     299,   299,   327,    37,   328,   299,   328,    31,   288,   289,
     290,    17,   243,   292,     3,     4,   315,   319,   320,    16,
     198,   233,   526,     6,    24,   106,   107,   325,   326,   325,
     326,   329,   330,    23,    40,   259,   238,   471,   238,    40,
     264,   265,     6,   106,   323,   324,   323,   329,   323,   369,
     370,   371,   375,   376,    18,    19,   244,   245,   238,   295,
     296,   297,   327,   327,   316,   314,   320,   234,   163,   199,
     201,   202,    10,   300,   301,   526,    38,    32,    33,    34,
      35,    36,    52,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   183,   184,
     188,   331,   339,   403,   456,   457,   459,   460,   461,   470,
     472,   473,   516,   520,   521,   522,   523,   524,   525,   526,
     528,    24,   260,   261,   262,   263,   526,   327,   264,   257,
     264,    92,   266,   267,   271,    37,   163,   342,   344,   112,
     526,   112,    38,   112,   472,    41,   188,   378,    20,    41,
      66,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    90,    94,    95,    96,    97,    98,    99,   100,   101,
     109,   110,   111,   113,   114,   115,   118,   119,   121,   123,
     124,   125,   126,   128,   129,   131,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   248,   249,   250,   251,   395,   472,   497,   499,   501,
     502,   503,   506,   509,   511,   516,   520,   524,   526,   264,
      50,   293,   294,    21,   108,   317,   318,   321,   181,    56,
     200,   325,   458,   334,    44,   340,   341,   405,    41,   404,
      89,   187,   517,   518,   519,   263,   266,   266,   266,    26,
      93,   268,   274,   345,   323,   323,   323,   372,   377,    37,
      41,    62,    63,    65,   472,   474,   475,   478,   481,   482,
     485,   486,   492,   494,   495,   496,   497,   509,   514,   516,
     520,   524,   526,    76,    41,    41,    41,   188,   498,    41,
     188,   401,    41,    41,    41,    41,   504,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,   401,    41,
      41,    41,   188,   188,    41,    41,    41,    41,   188,    41,
     188,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,   249,    41,    41,   188,   396,   266,   195,
     291,   327,    24,   322,   526,    40,   235,    37,   104,   151,
     153,   155,   203,   204,   206,   207,   214,   216,   217,   224,
     263,    51,   408,   413,   471,   333,   335,   336,   331,   406,
     407,   408,   456,   462,   468,   470,   408,   526,    41,   272,
     273,   395,   472,   497,   275,   276,   394,   395,   496,   497,
      25,   269,   277,    52,   239,   240,   343,   346,   347,   350,
     418,   461,   463,   464,   466,   470,    37,    42,   472,   382,
     474,   495,   495,   495,    91,   246,   247,   477,   480,    56,
      57,    58,    59,    60,    61,    66,    67,   483,   484,   491,
     493,   396,   515,   507,   474,   474,   474,   474,   474,   474,
     474,   474,   505,   474,   474,   474,   474,   472,   474,   474,
     474,   474,   474,   474,    18,   398,   398,   474,   474,   474,
     474,   474,   474,   474,   474,   474,   474,   474,   474,   474,
     474,   474,   474,   474,   474,   474,   474,   474,   474,   474,
     474,   474,   474,   474,   474,   398,   398,   526,   342,   180,
     225,    43,   104,   164,   208,   209,   212,   383,   472,   516,
     520,   524,   526,   155,   218,   219,   222,   383,   207,   205,
     217,   215,    53,   414,   417,   468,    44,   332,     6,    42,
     468,   474,   273,   276,    26,    29,    30,   270,   283,   286,
     287,   465,   243,    38,   349,    44,   351,   352,    41,   420,
     419,   373,    38,    41,   188,   380,    42,   472,    42,    54,
     476,    55,   479,   485,   485,   485,   485,   485,   485,    67,
     401,    62,    63,   487,   490,   522,   523,    20,    64,   488,
     508,    42,    42,    42,   402,    49,    49,    49,    49,   342,
      42,    42,    49,    42,    42,    49,    42,    42,    42,    42,
      49,    20,   474,   510,   474,    42,    42,    49,    49,    42,
      42,    42,    42,    42,    42,    49,    42,    42,    42,    49,
      42,    42,    42,    49,    42,    42,    42,    42,    42,    49,
      42,    42,    42,   474,   474,    38,    41,   226,   212,   104,
     222,   155,   205,    44,   104,   210,   215,    44,   155,   220,
     412,   416,   331,   471,   247,    27,    28,   278,   279,   280,
     281,   282,   394,   472,   167,   167,   284,   287,   285,   286,
      41,    51,    65,   102,   423,   425,   431,   432,   437,   438,
     441,   444,   446,   448,   472,   526,   241,     6,     7,     8,
      31,    45,    46,    48,   127,   148,   348,   353,   354,   355,
     357,   361,   364,   367,   368,   384,   387,   388,   393,   347,
     463,   467,   469,   470,   421,   422,   423,   423,    38,   374,
     383,   381,   478,   481,   401,   492,   492,   488,   489,   494,
     494,   342,   400,   474,   474,   474,   474,   474,   474,   474,
      42,    50,   512,   513,   474,   474,   474,   474,   474,   474,
      42,   397,   227,   151,   213,   211,   154,   223,   221,    50,
     411,    49,   415,   337,    42,   279,   496,   437,    41,    51,
     102,   449,   454,   526,   444,    53,   424,   440,   443,    20,
      62,   103,   445,   447,   242,   358,   362,   365,   369,   356,
     385,   394,    41,   342,   332,   389,    42,   469,   379,    42,
      49,   399,    49,    42,    42,    49,    42,    42,   399,   500,
      77,    42,    42,    42,    42,   500,    42,    42,   400,   230,
     209,   219,   409,   410,   413,   417,    37,    42,   452,   453,
     454,    51,   455,   526,   433,   436,   469,   104,   439,    64,
     442,   264,   359,   363,   366,   342,   386,   474,   347,   342,
      42,   383,   474,   474,   474,    42,    56,    42,    42,    42,
     229,   231,   383,   414,   338,    42,   451,   430,   435,   441,
     446,   266,   471,   299,   299,   342,    91,   392,    42,   500,
     525,    49,   228,    56,   149,   150,   331,   104,   450,    50,
     429,    49,   434,   288,   360,   471,   471,   472,    47,   390,
      42,   383,   383,   383,    38,   454,   425,   426,   428,   436,
     342,   342,    23,    42,   391,   427,   327,   342,   414,   264
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
     434,   435,   435,   436,   437,   438,   439,   440,   440,   441,
     442,   443,   443,   444,   445,   445,   446,   446,   447,   447,
     447,   448,   448,   448,   448,   449,   449,   450,   451,   451,
     452,   453,   453,   454,   454,   454,   455,   455,   456,   456,
     458,   457,   459,   460,   460,   460,   460,   460,   461,   461,
     462,   462,   463,   463,   465,   464,   466,   467,   467,   468,
     468,   469,   469,   470,   470,   471,   471,   472,   472,   473,
     473,   473,   473,   473,   473,   474,   475,   476,   477,   477,
     478,   479,   480,   480,   481,   482,   483,   483,   484,   484,
     484,   484,   484,   484,   484,   484,   485,   486,   487,   487,
     488,   488,   489,   489,   490,   490,   490,   491,   491,   492,
     493,   493,   494,   494,   494,   494,   495,   495,   495,   495,
     495,   495,   495,   495,   496,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   498,
     498,   499,   500,   500,   501,   502,   504,   505,   503,   507,
     508,   506,   509,   509,   509,   510,   510,   511,   511,   511,
     511,   511,   512,   513,   513,   514,   515,   515,   516,   517,
     518,   518,   519,   519,   520,   520,   520,   521,   521,   521,
     522,   522,   522,   523,   523,   523,   524,   524,   525,   525,
     525,   525,   526,   526,   527,   527,   528,   528
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
       2,     0,     2,     1,     1,     2,     2,     0,     2,     2,
       2,     0,     2,     2,     0,     1,     1,     2,     1,     1,
       1,     1,     1,     2,     3,     1,     3,     2,     0,     2,
       2,     0,     1,     1,     1,     2,     1,     1,     1,     1,
       0,     4,     4,     1,     1,     1,     1,     1,     0,     1,
       1,     2,     1,     1,     0,     4,     4,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     0,     2,
       2,     2,     0,     2,     1,     2,     0,     1,     2,     2,
       2,     2,     2,     2,     2,     3,     1,     2,     1,     1,
       2,     2,     0,     1,     2,     2,     2,     0,     2,     2,
       0,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     4,     6,     4,     4,
       4,     4,     2,     2,     4,     4,     4,     4,     2,     1,
       4,     1,     4,     4,     4,     6,     6,     6,     6,     6,
       4,     4,     4,     4,     4,     4,     4,     4,     2,     2,
       2,     4,     4,     4,     4,     4,     2,     8,     6,     6,
       6,     4,     4,     4,     4,     4,     1,     1,     1,     3,
       1,     7,     0,     1,     7,     9,     0,     0,     4,     0,
       0,     5,     5,     5,     6,     1,     1,     1,     1,     1,
       1,     1,     4,     0,     1,     2,     0,     1,     2,     2,
       1,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
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
  "BlankNodePropertyList", "@42", "Generator",
  "_O_QIT_MEMBERS_E_Or_QIT_STARTS_E_Or_QIT_ENDS_E_Or_QIT_ANY_E_Or_QIT_UNORDERED_E_C",
  "_Q_O_QIT_MEMBERS_E_Or_QIT_STARTS_E_Or_QIT_ENDS_E_Or_QIT_ANY_E_Or_QIT_UNORDERED_E_C_E_Opt",
  "_QGraphNode_E_Plus", "TriplesNodePath", "BlankNodePropertyListPath",
  "@43", "GeneratorPath", "_QGraphNodePath_E_Plus", "GraphNode",
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
  "SubstringExpression", "StrReplaceExpression", "ExistsFunc", "@44",
  "@45", "NotExistsFunc", "@46", "@47", "Aggregate",
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
      -1,    91,   472,    -1,    -1,   246,    -1,    41,   474,   247,
      42,    -1,   497,    -1,   516,    -1,   520,    -1,   524,    -1,
     472,    -1,   509,    -1,   395,    -1,   248,    -1,   249,    -1,
     250,   249,    -1,   250,    -1,    20,    -1,    21,   253,    -1,
     327,   238,   264,   266,    -1,   238,    40,   327,   266,    -1,
      22,   256,   238,   257,   266,    -1,   471,    -1,   255,   471,
      -1,   255,    -1,    20,    -1,    -1,   264,    -1,    39,   238,
     264,   266,    -1,    23,   260,    -1,   261,    -1,   262,    -1,
     263,    -1,    24,   263,    -1,   526,    -1,   265,   342,    -1,
      -1,    40,    -1,   267,   268,   269,   270,    -1,    -1,   271,
      -1,    -1,   274,    -1,    -1,   277,    -1,    -1,   283,    -1,
      92,    26,   272,    -1,   273,    -1,   272,   273,    -1,   497,
      -1,   395,    -1,    41,   474,   247,    42,    -1,   472,    -1,
      93,   275,    -1,   276,    -1,   275,   276,    -1,   394,    -1,
      25,    26,   278,    -1,   279,    -1,   278,   279,    -1,   281,
      -1,   282,    -1,    27,    -1,    28,    -1,   280,   496,    -1,
     394,    -1,   472,    -1,   286,   284,    -1,   287,   285,    -1,
      -1,   287,    -1,    -1,   286,    -1,    29,   167,    -1,    30,
     167,    -1,   290,    -1,    31,   369,    -1,    -1,   289,    -1,
      -1,   195,   297,   292,   296,    -1,    50,   291,    -1,    -1,
     293,    -1,   297,   294,    -1,    -1,   295,    -1,   298,    -1,
     302,    -1,   303,    -1,   305,    -1,   306,    -1,   307,    -1,
     304,    -1,   308,    -1,   309,    -1,   310,    -1,   311,    -1,
       9,   299,   526,   301,    -1,    -1,    13,    -1,    10,   325,
      -1,    -1,   300,    -1,    11,   299,   326,    -1,    14,   299,
     326,    -1,    12,   299,   325,    -1,   116,   299,   323,   112,
     323,    -1,   130,   299,   323,   112,   323,    -1,   117,   299,
     323,   112,   323,    -1,   132,   328,    -1,   122,   328,    -1,
     120,   327,    -1,   313,   315,   316,   318,    40,   342,    -1,
     105,   526,    -1,    -1,   312,    -1,    -1,   320,    -1,   319,
     314,    -1,   320,    -1,    -1,   316,   321,    -1,    21,   327,
      -1,    -1,   317,    -1,     3,   327,    -1,     4,   327,    -1,
     108,   322,    -1,   526,    -1,    24,   526,    -1,   106,    -1,
     324,   526,    -1,    -1,     6,    -1,     6,   526,    -1,   325,
      -1,   106,    -1,    24,    -1,   107,    -1,    37,   329,    38,
      -1,    37,   329,    38,    -1,    -1,   330,   331,   334,    -1,
      -1,   339,    -1,    -1,    44,    -1,   335,   332,   331,    -1,
      -1,   334,   333,    -1,    -1,    -1,    -1,   336,     6,   471,
     337,    37,   338,   331,    38,    -1,   403,   341,    -1,    44,
     331,    -1,    -1,   340,    -1,   344,    -1,   163,    -1,   239,
      -1,   346,    -1,    -1,    37,   345,   343,    38,    -1,   347,
     349,    -1,    -1,   350,    -1,   353,   332,   347,    -1,    -1,
     349,   348,    -1,   418,   352,    -1,    44,   347,    -1,    -1,
     351,    -1,   387,    -1,   355,    -1,   384,    -1,   357,    -1,
     361,    -1,   364,    -1,   393,    -1,   367,    -1,   368,    -1,
     354,    -1,   148,   342,    -1,    -1,    45,   356,   342,    -1,
      -1,    -1,    -1,     6,   358,   359,   471,   360,   342,    -1,
      -1,    -1,     7,   362,   363,   299,   471,   342,    -1,    -1,
      -1,     8,   365,   366,   299,   471,    23,   327,   264,    -1,
     127,    41,   474,    91,   472,    42,    -1,    31,   369,    -1,
     370,    -1,   375,    -1,    -1,    -1,   371,   472,   372,    37,
     373,    38,    -1,    -1,   373,   374,    -1,   383,    -1,    -1,
     376,   378,    37,   382,    38,    -1,    -1,   377,   472,    -1,
     188,    -1,    41,   377,    42,    -1,    -1,   379,   383,    -1,
      -1,    41,   381,   379,    42,    -1,   188,    -1,    -1,   382,
     380,    -1,   526,    -1,   516,    -1,   520,    -1,   524,    -1,
      43,    -1,   164,    -1,   472,    -1,    -1,    -1,    46,   385,
     386,   342,    -1,    -1,    -1,   388,   389,   342,   392,    -1,
      -1,    47,   391,   342,    -1,    -1,   392,   390,    -1,    48,
     394,    -1,   496,    -1,   497,    -1,   395,    -1,   526,   396,
      -1,   188,    -1,    -1,    41,   398,   474,   397,   400,    42,
      -1,    -1,    18,    -1,    49,   474,    -1,    -1,   400,   399,
      -1,   188,    -1,    -1,    41,   474,   402,   400,    42,    -1,
      -1,   470,   404,   408,    -1,    -1,   456,   405,   406,    -1,
     407,    -1,    -1,   408,    -1,   413,   414,   412,    -1,   413,
     414,    -1,    -1,   409,    -1,    50,   410,    -1,    -1,   412,
     411,    -1,   471,    -1,    51,    -1,   417,   416,    -1,    49,
     417,    -1,    -1,   416,   415,    -1,   468,    -1,    -1,   470,
     419,   423,    -1,    -1,   463,   420,   421,    -1,   422,    -1,
      -1,   423,    -1,    -1,   425,   424,   433,   430,    -1,   431,
      -1,   432,    -1,    -1,   425,   427,   414,    -1,    -1,   426,
      -1,    50,   428,    -1,    -1,   430,   429,    -1,   437,    -1,
     472,    -1,   436,   435,    -1,    49,   436,    -1,    -1,   435,
     434,    -1,   469,    -1,   438,    -1,   441,   440,    -1,   104,
     441,    -1,    -1,   440,   439,    -1,   446,   443,    -1,    64,
     446,    -1,    -1,   443,   442,    -1,   448,   445,    -1,    -1,
     447,    -1,   444,    -1,   102,   444,    -1,   103,    -1,    20,
      -1,    62,    -1,   526,    -1,    51,    -1,    65,   449,    -1,
      41,   437,    42,    -1,   454,    -1,    41,   453,    42,    -1,
     104,   454,    -1,    -1,   451,   450,    -1,   454,   451,    -1,
      -1,   452,    -1,   526,    -1,    51,    -1,   102,   455,    -1,
     526,    -1,    51,    -1,   459,    -1,   457,    -1,    -1,    52,
     458,   408,    53,    -1,   461,    41,   462,    42,    -1,    32,
      -1,    33,    -1,    34,    -1,    35,    -1,    36,    -1,    -1,
     460,    -1,   468,    -1,   462,   468,    -1,   466,    -1,   464,
      -1,    -1,    52,   465,   423,    53,    -1,   461,    41,   467,
      42,    -1,   469,    -1,   467,   469,    -1,   470,    -1,   456,
      -1,   470,    -1,   463,    -1,   472,    -1,   473,    -1,   472,
      -1,   526,    -1,   185,    -1,   186,    -1,   526,    -1,   516,
      -1,   520,    -1,   524,    -1,   528,    -1,   188,    -1,   475,
      -1,   478,   477,    -1,    54,   478,    -1,    -1,   477,   476,
      -1,   481,   480,    -1,    55,   481,    -1,    -1,   480,   479,
      -1,   482,    -1,   485,   483,    -1,    -1,   484,    -1,    56,
     485,    -1,    57,   485,    -1,    58,   485,    -1,    59,   485,
      -1,    60,   485,    -1,    61,   485,    -1,    67,   401,    -1,
      66,    67,   401,    -1,   486,    -1,   492,   491,    -1,   522,
      -1,   523,    -1,    20,   494,    -1,    64,   494,    -1,    -1,
     488,    -1,    62,   492,    -1,    63,   492,    -1,   487,   489,
      -1,    -1,   491,   490,    -1,   494,   493,    -1,    -1,   493,
     488,    -1,    65,   495,    -1,    62,   495,    -1,    63,   495,
      -1,   495,    -1,   496,    -1,   497,    -1,   514,    -1,   516,
      -1,   520,    -1,   524,    -1,   472,    -1,   509,    -1,    41,
     474,    42,    -1,    78,    41,   474,    42,    -1,    79,    41,
     474,    42,    -1,    80,    41,   474,    49,   474,    42,    -1,
      81,    41,   474,    42,    -1,    82,    41,   472,    42,    -1,
      68,    41,   474,    42,    -1,    69,    41,   474,    42,    -1,
      70,   498,    -1,   118,   188,    -1,   142,    41,   474,    42,
      -1,   139,    41,   474,    42,    -1,   131,    41,   474,    42,
      -1,   125,    41,   474,    42,    -1,    90,   401,    -1,   501,
      -1,   145,    41,   474,    42,    -1,   502,    -1,   143,    41,
     474,    42,    -1,   141,    41,   474,    42,    -1,   137,    41,
     474,    42,    -1,   128,    41,   474,    49,   474,    42,    -1,
     138,    41,   474,    49,   474,    42,    -1,   144,    41,   474,
      49,   474,    42,    -1,   113,    41,   474,    49,   474,    42,
      -1,   114,    41,   474,    49,   474,    42,    -1,   115,    41,
     474,    42,    -1,   147,    41,   474,    42,    -1,   140,    41,
     474,    42,    -1,   136,    41,   474,    42,    -1,   133,    41,
     474,    42,    -1,   129,    41,   474,    42,    -1,   124,    41,
     474,    42,    -1,   123,    41,   474,    42,    -1,   121,   188,
      -1,   109,   188,    -1,   110,   188,    -1,   111,    41,   474,
      42,    -1,   146,    41,   474,    42,    -1,   135,    41,   474,
      42,    -1,   126,    41,   474,    42,    -1,   119,    41,   474,
      42,    -1,    71,   401,    -1,    72,    41,   474,    49,   474,
      49,   474,    42,    -1,    73,    41,   474,    49,   474,    42,
      -1,    74,    41,   474,    49,   474,    42,    -1,    83,    41,
     474,    49,   474,    42,    -1,    84,    41,   474,    42,    -1,
      85,    41,   474,    42,    -1,    86,    41,   474,    42,    -1,
      87,    41,   474,    42,    -1,   101,    41,   474,    42,    -1,
     499,    -1,   503,    -1,   506,    -1,    41,   474,    42,    -1,
     188,    -1,    88,    41,   474,    49,   474,   500,    42,    -1,
      -1,   399,    -1,   134,    41,   474,    49,   474,   500,    42,
      -1,    75,    41,   474,    49,   474,    49,   474,   500,    42,
      -1,    -1,    -1,    76,   504,   505,   342,    -1,    -1,    -1,
      66,    76,   507,   508,   342,    -1,    94,    41,   398,   510,
      42,    -1,   511,    41,   398,   474,    42,    -1,    99,    41,
     398,   474,   513,    42,    -1,    20,    -1,   474,    -1,    95,
      -1,    96,    -1,    97,    -1,    98,    -1,   100,    -1,    50,
      77,    56,   525,    -1,    -1,   512,    -1,   526,   515,    -1,
      -1,   396,    -1,   525,   519,    -1,    89,   526,    -1,   187,
      -1,   517,    -1,    -1,   518,    -1,   521,    -1,   522,    -1,
     523,    -1,   167,    -1,   168,    -1,   169,    -1,   170,    -1,
     171,    -1,   172,    -1,   173,    -1,   174,    -1,   175,    -1,
     165,    -1,   166,    -1,   176,    -1,   178,    -1,   177,    -1,
     179,    -1,   180,    -1,   527,    -1,   182,    -1,   181,    -1,
     183,    -1,   184,    -1
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
     665,   666,   670,   671,   672,   673,   680,   681,   682,   689,
     690,   691,   700,   707,   710,   712,   714,   715,   716,   723,
     724,   727,   729,   730,   736,   737,   740,   742,   746,   747,
     750,   751,   756,   758,   759,   762,   764,   766,   768,   770,
     772,   774,   776,   777,   778,   783,   784,   785,   790,   791,
     795,   796,   799,   802,   804,   806,   808,   811,   813,   814,
     821,   822,   824,   827,   828,   831,   833,   834,   840,   841,
     845,   846,   850,   852,   853,   855,   859,   862,   863,   865,
     868,   869,   872,   874,   876,   879,   882,   883,   886,   888,
     889,   893,   894,   898,   900,   901,   903,   904,   909,   911,
     913,   914,   918,   919,   921,   924,   925,   928,   930,   932,
     935,   938,   939,   942,   944,   946,   949,   952,   953,   956,
     959,   962,   963,   966,   969,   970,   972,   974,   977,   979,
     981,   983,   985,   987,   990,   994,   996,  1000,  1003,  1004,
    1007,  1010,  1011,  1013,  1015,  1017,  1020,  1022,  1024,  1026,
    1028,  1029,  1034,  1039,  1041,  1043,  1045,  1047,  1049,  1050,
    1052,  1054,  1057,  1059,  1061,  1062,  1067,  1072,  1074,  1077,
    1079,  1081,  1083,  1085,  1087,  1089,  1091,  1093,  1095,  1097,
    1099,  1101,  1103,  1105,  1107,  1109,  1111,  1114,  1117,  1118,
    1121,  1124,  1127,  1128,  1131,  1133,  1136,  1137,  1139,  1142,
    1145,  1148,  1151,  1154,  1157,  1160,  1164,  1166,  1169,  1171,
    1173,  1176,  1179,  1180,  1182,  1185,  1188,  1191,  1192,  1195,
    1198,  1199,  1202,  1205,  1208,  1211,  1213,  1215,  1217,  1219,
    1221,  1223,  1225,  1227,  1229,  1233,  1238,  1243,  1250,  1255,
    1260,  1265,  1270,  1273,  1276,  1281,  1286,  1291,  1296,  1299,
    1301,  1306,  1308,  1313,  1318,  1323,  1330,  1337,  1344,  1351,
    1358,  1363,  1368,  1373,  1378,  1383,  1388,  1393,  1398,  1401,
    1404,  1407,  1412,  1417,  1422,  1427,  1432,  1435,  1444,  1451,
    1458,  1465,  1470,  1475,  1480,  1485,  1490,  1492,  1494,  1496,
    1500,  1502,  1510,  1511,  1513,  1521,  1531,  1532,  1533,  1538,
    1539,  1540,  1546,  1552,  1558,  1565,  1567,  1569,  1571,  1573,
    1575,  1577,  1579,  1584,  1585,  1587,  1590,  1591,  1593,  1596,
    1599,  1601,  1603,  1604,  1606,  1608,  1610,  1612,  1614,  1616,
    1618,  1620,  1622,  1624,  1626,  1628,  1630,  1632,  1634,  1636,
    1638,  1640,  1642,  1644,  1646,  1648,  1650,  1652
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   488,   488,   491,   497,   502,   513,   514,   515,   516,
     520,   525,   529,   531,   535,   537,   540,   542,   546,   546,
     564,   570,   573,   577,   578,   579,   580,   586,   587,   590,
     592,   596,   600,   604,   605,   609,   610,   614,   614,   622,
     628,   632,   633,   636,   638,   642,   646,   650,   651,   655,
     656,   660,   660,   668,   674,   678,   681,   683,   687,   687,
     694,   696,   700,   703,   705,   709,   712,   715,   721,   727,
     729,   727,   739,   739,   751,   754,   762,   765,   769,   762,
     814,   822,   825,   832,   835,   840,   847,   850,   855,   862,
     865,   868,   871,   874,   877,   880,   884,   889,   892,   900,
     903,   909,   915,   920,   930,   938,   941,   949,   952,   959,
     962,   967,   975,   982,   983,   987,   993,   999,  1006,  1013,
    1015,  1020,  1027,  1030,  1035,  1038,  1043,  1046,  1051,  1055,
    1059,  1066,  1069,  1076,  1079,  1082,  1085,  1091,  1097,  1100,
    1107,  1112,  1119,  1123,  1131,  1133,  1141,  1144,  1152,  1160,
    1161,  1168,  1172,  1180,  1183,  1188,  1191,  1195,  1201,  1207,
    1211,  1217,  1220,  1224,  1224,  1234,  1237,  1239,  1243,  1246,
    1248,  1252,  1253,  1254,  1255,  1256,  1257,  1258,  1259,  1260,
    1261,  1262,  1266,  1272,  1275,  1282,  1289,  1292,  1296,  1302,
    1308,  1314,  1320,  1326,  1332,  1340,  1348,  1355,  1364,  1370,
    1373,  1377,  1380,  1384,  1388,  1394,  1396,  1402,  1408,  1411,
    1415,  1421,  1427,  1433,  1436,  1442,  1445,  1450,  1452,  1456,
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
    2078,  2078,  2083,  2085,  2089,  2092,  2094,  2098,  2102,  2108,
    2112,  2115,  2117,  2121,  2128,  2132,  2136,  2139,  2141,  2145,
    2149,  2154,  2156,  2162,  2165,  2167,  2173,  2174,  2180,  2181,
    2182,  2186,  2189,  2192,  2195,  2201,  2202,  2206,  2209,  2211,
    2215,  2218,  2220,  2224,  2225,  2226,  2230,  2231,  2237,  2238,
    2242,  2242,  2255,  2283,  2286,  2289,  2292,  2295,  2302,  2305,
    2310,  2314,  2321,  2322,  2326,  2326,  2338,  2365,  2369,  2376,
    2377,  2381,  2382,  2386,  2389,  2393,  2396,  2402,  2403,  2407,
    2410,  2413,  2416,  2419,  2420,  2426,  2431,  2440,  2447,  2450,
    2458,  2467,  2474,  2477,  2484,  2489,  2502,  2506,  2510,  2514,
    2518,  2522,  2526,  2530,  2534,  2538,  2545,  2550,  2559,  2562,
    2569,  2572,  2579,  2582,  2587,  2590,  2594,  2608,  2611,  2619,
    2628,  2631,  2638,  2641,  2644,  2647,  2651,  2652,  2653,  2654,
    2657,  2660,  2663,  2666,  2670,  2676,  2679,  2682,  2685,  2688,
    2691,  2694,  2698,  2701,  2704,  2707,  2710,  2713,  2716,  2719,
    2720,  2723,  2724,  2727,  2730,  2733,  2736,  2739,  2742,  2745,
    2748,  2751,  2754,  2757,  2760,  2763,  2766,  2769,  2772,  2775,
    2778,  2781,  2784,  2787,  2790,  2793,  2796,  2799,  2802,  2805,
    2808,  2811,  2814,  2817,  2820,  2823,  2826,  2827,  2828,  2834,
    2837,  2844,  2851,  2854,  2858,  2864,  2870,  2873,  2870,  2885,
    2888,  2885,  2901,  2905,  2910,  2919,  2922,  2926,  2929,  2932,
    2935,  2938,  2944,  2950,  2953,  2957,  2967,  2970,  2975,  2983,
    2990,  2994,  3002,  3006,  3010,  3011,  3012,  3016,  3017,  3018,
    3022,  3023,  3024,  3028,  3029,  3030,  3034,  3035,  3039,  3040,
    3041,  3042,  3046,  3047,  3051,  3052,  3056,  3057
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
  const int SPARQLfedParser::yynnts_ = 340;
  const int SPARQLfedParser::yyempty_ = -2;
  const int SPARQLfedParser::yyfinal_ = 11;
  const int SPARQLfedParser::yyterror_ = 1;
  const int SPARQLfedParser::yyerrcode_ = 256;
  const int SPARQLfedParser::yyntokens_ = 189;

  const unsigned int SPARQLfedParser::yyuser_token_number_max_ = 443;
  const SPARQLfedParser::token_number_type SPARQLfedParser::yyundef_token_ = 2;


} // w3c_sw

/* Line 1136 of lalr1.cc  */
#line 5958 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 3063 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


