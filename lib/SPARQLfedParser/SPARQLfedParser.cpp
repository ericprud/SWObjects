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
#line 325 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"

/* Line 299 of lalr1.cc  */
#line 491 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

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
#line 505 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 508 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 519 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 563 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.startBindingSet();
      }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 566 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 581 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = (yysemantic_stack_[(2) - (1)].p_RSName);
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 587 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = NULL;
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 597 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	throw std::runtime_error("need to partition out results set part of SimpleEngine::loadDataOrResults");
    }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 631 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 633 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 639 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 677 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 679 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 685 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 704 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow(false);
      }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 706 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 726 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 729 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 732 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 738 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 744 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 746 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 748 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 756 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 759 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause);
	(yyval.p_Operation) = new Select((yysemantic_stack_[(5) - (2)].p_Project).distinctness, (yysemantic_stack_[(5) - (2)].p_Project).varSet, (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
	driver.countStar = (yysemantic_stack_[(5) - (1)].p_parentCountStar);
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 768 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 771 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 779 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
      }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 782 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 786 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 793 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 805 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 813 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 816 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 823 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 831 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 838 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 846 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 853 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 856 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 859 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 862 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 865 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 868 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 871 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 880 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 883 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 891 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 894 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 900 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(2) - (2)].p_Operation);
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 906 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.lastWhereClause = (yysemantic_stack_[(4) - (3)].p_WhereClause);
	  /* $1 is NO LONGER known to be a DefaultGraphPattern because of grammar restrictions. */
	  (yyval.p_Operation) = new Construct((yysemantic_stack_[(4) - (1)].p_TableOperation), (yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
      }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 911 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	SWObjectDuplicator dup(driver.atomFactory);
	(yysemantic_stack_[(4) - (3)].p_TableOperation)->express(&dup);
	driver.lastWhereClause = new WhereClause((yysemantic_stack_[(4) - (3)].p_TableOperation));
	(yyval.p_Operation) = new Construct(dup.last.tableOperation, (yysemantic_stack_[(4) - (1)].p_DatasetClauses), driver.lastWhereClause, (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 921 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause) ? (yysemantic_stack_[(5) - (4)].p_WhereClause) : new WhereClause(new DefaultGraphPattern());
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 929 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm))));
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 932 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_TTerm))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 940 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 943 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 950 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 958 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(4) - (3)].p_WhereClause);
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 966 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 978 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 984 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 990 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 997 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.ensureGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1011 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1018 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1026 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1034 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1042 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1050 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1057 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1060 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1067 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1070 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1073 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1076 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1082 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1088 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1091 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1103 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1110 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1114 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1124 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1132 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1135 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1143 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1152 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1159 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1163 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1171 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1179 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1186 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1192 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1202 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = (yysemantic_stack_[(2) - (2)].p_BindingClause);
    }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1208 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1215 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	OperationSet* ret = driver.root ? dynamic_cast<OperationSet*>(driver.root) : new OperationSet();
	ret->push_back((yysemantic_stack_[(2) - (2)].p_Operation));
	driver.root = ret;
      }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1219 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Operation) = driver.root;
	}
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1257 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(4) - (2)].p_Silence), (yysemantic_stack_[(4) - (3)].p_URI), (yysemantic_stack_[(4) - (4)].p_URI));
    }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1263 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1266 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1273 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1280 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1287 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1293 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1299 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1305 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1311 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1317 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1323 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1331 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1339 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1346 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(6) - (1)].p_URI))
	    w3c_sw_NEED_IMPL("WITH <URI> (DELETE INSERT?|INSERT) ...");
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(6) - (2)].p_DeleteInsert).del, (yysemantic_stack_[(6) - (2)].p_DeleteInsert).ins, new WhereClause(driver.ensureGraphPattern()), (yysemantic_stack_[(6) - (4)].p_TableOperation));
	driver.curOp = NULL;
    }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1355 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1361 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1368 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1375 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1379 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1387 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("_QUsingClause_E_Star");
    }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1393 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(2) - (2)].p_TableOperation);
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1399 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = NULL;
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1406 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Delete) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1412 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = new Insert((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 1418 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1424 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 1427 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 1433 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 1436 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 1447 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1453 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 1456 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("DEFAULT");
      }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1459 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("NAMED");
      }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 1462 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("ALL");
      }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 1469 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
	driver.curOp = NULL;
    }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 1476 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
    }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 1482 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 1484 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TableOperation) = driver.ensureGraphPattern();
	  driver.curOp = NULL;
      }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 1512 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 1517 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 1520 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 1523 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 1545 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 1564 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 1566 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 1638 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_BindingClause)) : (yysemantic_stack_[(1) - (1)].p_BindingClause);
    }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 1645 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Print(driver.curOp);
    }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 1651 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 1655 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 1667 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 1671 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 1673 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 1676 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 1684 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 1688 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 1690 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(6) - (5)].p_TTerm), driver.curOp, (yysemantic_stack_[(6) - (4)].p_Silence), driver.atomFactory, false));
      }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 1697 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 1701 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 1703 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 1718 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 1729 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = (yysemantic_stack_[(2) - (2)].p_BindingClause);
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 1740 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 1742 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
      }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 1744 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 1755 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
	driver.endBindingRow();
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 1763 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 1765 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 1772 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 1784 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 1790 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 1792 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 1795 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 1807 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 1810 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 1813 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 1816 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 1819 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 1822 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 1825 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 1831 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 1835 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 1837 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 1845 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 1849 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 1851 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 1859 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 1864 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.ensureGraphPattern());
      }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 1877 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 1893 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 1901 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 1905 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 1908 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yysemantic_stack_[(6) - (4)].p_Expressions);
      }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 1915 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 1918 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 1925 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 1933 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 1947 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 1950 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 1953 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(5) - (3)].p_Expressions);
      }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 1960 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 1963 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 2005 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 2009 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::RDF_type;
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 2032 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 2040 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 2043 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
        }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 2058 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 2069 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 2089 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	const URI* t = (yysemantic_stack_[(1) - (1)].p_PropertyPath)->release();
	if (!t) {
	    std::string s = (yysemantic_stack_[(1) - (1)].p_PropertyPath)->str();
	    w3c_sw_LINEN << "new PP(" << s << ")\n";
	}
	(yyval.p_TTerm) = t ? t : (const TTerm*)new PropertyPath((yysemantic_stack_[(1) - (1)].p_PropertyPath));
    }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 2100 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 2119 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 2130 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = driver.lastPropertyPathAlternative;
	driver.lastPropertyPathAlternative = (yysemantic_stack_[(1) - (1)].p_PropertyPath);
      }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 2133 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (3)].p_PropertyPath) ? (yysemantic_stack_[(3) - (3)].p_PropertyPath) : (yysemantic_stack_[(3) - (1)].p_PropertyPath);
	  driver.lastPropertyPathAlternative = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
      }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 2140 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(2) - (2)].p_PropertyPath);
    }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 2146 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = NULL;
    }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 2149 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Alternative((yysemantic_stack_[(2) - (1)].p_PropertyPath) ? (yysemantic_stack_[(2) - (1)].p_PropertyPath) : driver.lastPropertyPathAlternative, (yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 2155 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = driver.lastPropertyPathSequence;
	driver.lastPropertyPathSequence = (yysemantic_stack_[(1) - (1)].p_PropertyPath);
      }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 2158 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {	
	  (yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (3)].p_PropertyPath) ? (yysemantic_stack_[(3) - (3)].p_PropertyPath) : (yysemantic_stack_[(3) - (1)].p_PropertyPath);
	  driver.lastPropertyPathSequence = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
      }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 2165 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(2) - (2)].p_PropertyPath);
    }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 2171 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = NULL;
    }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 2174 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Sequence((yysemantic_stack_[(2) - (1)].p_PropertyPath) ? (yysemantic_stack_[(2) - (1)].p_PropertyPath) : driver.lastPropertyPathSequence, (yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 2180 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(2) - (2)].p_RepeatRange).min == 1 && (yysemantic_stack_[(2) - (2)].p_RepeatRange).max == 1 ? (yysemantic_stack_[(2) - (1)].p_PropertyPath) : new PropertyPath::Repeated((yysemantic_stack_[(2) - (1)].p_PropertyPath), (yysemantic_stack_[(2) - (2)].p_RepeatRange).min, (yysemantic_stack_[(2) - (2)].p_RepeatRange).max);
    }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 2186 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RepeatRange).min = 1; (yyval.p_RepeatRange).max = 1;
    }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 2194 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Inverse((yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 2200 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RepeatRange).min = 0; (yyval.p_RepeatRange).max = 1;
    }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 2203 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RepeatRange).min = 0; (yyval.p_RepeatRange).max = 999;
    }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 2206 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RepeatRange).min = 1; (yyval.p_RepeatRange).max = 999;
    }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 2212 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 2215 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate(TTerm::RDF_type);
    }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 2218 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Negated((yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 2221 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
    }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 2228 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
    }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 2234 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(2) - (2)].p_PropertyPath);
    }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 2240 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = NULL;
    }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 2243 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Alternative((yysemantic_stack_[(2) - (1)].p_PropertyPath) ? (yysemantic_stack_[(2) - (1)].p_PropertyPath) : driver.lastPropertyPathSetAlternative, (yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 2249 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = driver.lastPropertyPathSetAlternative;
	driver.lastPropertyPathSetAlternative = (yysemantic_stack_[(1) - (1)].p_PropertyPath);
      }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 2252 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.lastPropertyPathSetAlternative = (yyval.p_PropertyPath);
      }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 2258 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = NULL;
    }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 2265 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 2268 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate(TTerm::RDF_type);
    }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 2271 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Inverse((yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 2277 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 2280 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate(TTerm::RDF_type);
    }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 2293 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 2297 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 2306 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 2334 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 2337 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 2340 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 2343 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 2346 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 2353 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 2361 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 2365 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 2377 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 2381 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject;
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 2389 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 2416 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 2420 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 2437 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 2444 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 2447 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 2458 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 2461 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 2464 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 2467 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 2471 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::RDF_nil; // !!! new GraphTerm_rule5($1);
    }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 2482 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 2491 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 2498 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 2501 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 2509 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 2518 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 2525 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 2528 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 2540 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 2553 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = NULL;
    }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 2561 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 2565 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 2569 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 2573 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 2577 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 2581 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 2585 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 2589 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = true;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 2601 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 2610 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 2613 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 2620 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 2623 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 2630 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 2638 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 2641 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 2645 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 2659 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 2662 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 2670 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 2679 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 2682 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 2689 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 2692 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 2695 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 2705 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 2708 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 2711 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 2714 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 2721 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 2727 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 2730 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 2733 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 2736 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 2739 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 2742 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
      (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), new TTermExpression(driver.atomFactory->getURI(driver.getBase())), NULL));
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 2745 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
      (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), new TTermExpression(driver.atomFactory->getURI(driver.getBase())), NULL));
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 2749 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 2752 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 2755 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 2758 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ceil, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 2761 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 2764 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 2767 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 2771 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 2775 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 2778 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 2781 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 2784 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 2787 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 2790 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 2793 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 2796 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 2799 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 2802 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 2805 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 2808 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 2811 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 2814 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 2817 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 2820 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_tz, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 2823 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 2826 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_uuid, NULL, NULL, NULL));
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 2829 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_struuid, NULL, NULL, NULL));
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 2832 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 2835 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 2838 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 2841 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 2844 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 2847 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 2850 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 2853 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 2856 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 2859 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 2862 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 2865 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 2868 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 2871 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 2874 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 2885 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 2888 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 2895 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 2902 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 2909 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 2915 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_replace, (yysemantic_stack_[(9) - (3)].p_Expression), (yysemantic_stack_[(9) - (5)].p_Expression), (yysemantic_stack_[(9) - (7)].p_Expression))); // !! , $8
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 2921 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 2924 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 2928 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expression) = new ExistsExpression(driver.ensureGraphPattern());
	  driver.curOp = (yysemantic_stack_[(4) - (3)].p_TableOperation);
	  driver.countStar = (yysemantic_stack_[(4) - (2)].p_parentCountStar);
      }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 2936 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
      }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 2939 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 2943 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  // $$ = new ExistsExpression(false, driver.ensureGraphPattern());
	  (yyval.p_Expression) = new BooleanNegation(new ExistsExpression(driver.ensureGraphPattern()));
	  driver.curOp = (yysemantic_stack_[(5) - (4)].p_TableOperation);
	  driver.countStar = (yysemantic_stack_[(5) - (3)].p_parentCountStar);
      }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 2952 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 2956 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 2961 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  AggregateCall::ScalarVals svals;
	  if ((yysemantic_stack_[(6) - (5)].p_RDFLiteral) != NULL)
	      svals["separator"] = (yysemantic_stack_[(6) - (5)].p_RDFLiteral)->getLexicalValue();
	  (yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression), svals));
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 2970 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 2977 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 2980 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 2983 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 2986 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 2989 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 2995 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 3001 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 3008 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 3018 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 3026 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 3034 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 3041 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 3045 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 3053 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 690 of lalr1.cc  */
#line 4181 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -852;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        65,   -89,    94,  -852,  -852,  -852,   780,  -852,  -852,  -852,
    -852,  -852,    87,    87,    87,    87,    66,    42,  -852,   -53,
      87,    87,    66,    79,    87,    79,   105,  -852,   107,  -852,
    -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,
    -852,  -852,  -852,  -852,  -852,   160,   122,  -852,   -53,    44,
     134,    44,  -852,    52,  -852,  -852,  -852,  -852,  -852,  -852,
    -852,  -852,   159,  -852,  -852,  -852,  -852,  -852,    64,  -852,
      37,    37,  -852,  -852,  -852,    37,  -852,    -9,  -852,  -852,
    -852,   223,  -852,   730,    66,    66,  -852,   141,  -852,  -852,
     314,  -852,   142,   -53,  -852,  -852,  -852,  -852,  -852,  -852,
    -852,   128,   217,    49,    66,  -852,    64,  -852,    14,  -852,
      86,     4,  -852,  -852,    77,   -53,   121,   208,   147,  -852,
    -852,    95,  -852,    -5,  -852,  -852,  -852,  1609,    64,  -852,
    -852,   211,  -852,  -852,    34,  -852,  -852,    84,   212,  -852,
    -852,  -852,   134,  -852,  -852,  -852,  -852,  -852,  -852,  -852,
    -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,
    -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,
    -852,  -852,  -852,   232,  -852,  -852,  -852,  -852,   242,  -852,
    -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,   -41,  -852,
    -852,   -53,  -852,  -852,  -852,  -852,  -852,    86,    86,    86,
    -852,   260,  -852,   201,  -852,  -852,  -852,  -852,  -852,    37,
    -852,    37,  -852,    37,  -852,  -852,  -852,   259,  -852,  2016,
     228,   265,   270,    -1,    24,   274,   278,   284,   286,  -852,
     297,   305,   307,   309,   318,   321,   324,   325,   326,   328,
     329,    24,   330,  -852,  -852,  -852,  -852,   331,  -852,   333,
     187,   188,   337,   339,   363,   368,   222,   370,   224,   373,
     378,   379,   382,   384,   385,   386,   388,   390,   394,   397,
     399,   400,   401,   402,   404,   409,   410,   412,   414,   415,
     417,  -852,  -852,  2137,  -852,  -852,  -852,  -852,  -852,  -852,
    -852,  -852,  -852,  -852,   418,  -852,  -852,  -852,    26,    86,
      65,  -852,  -852,    66,    55,  -852,   421,  -852,  -852,  -852,
     226,  -852,    93,   456,   217,  -852,  -852,    93,  1846,    93,
     -53,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  2379,
    2465,   443,  -852,    25,  -852,  -852,  -852,   433,    -4,  -852,
    2016,  2258,  2258,  2258,  -852,   380,  -852,  -852,  -852,  -852,
     276,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,
    -852,  -852,    26,  -852,  2016,  2016,  2016,  -852,  -852,  2016,
    -852,  -852,  2016,  2016,  2016,  2016,  -852,  2016,  2016,  2016,
    2016,    95,  2016,  2016,  2016,  2016,  2016,  2016,  -852,   457,
     457,  2016,  -852,  -852,  2016,  2016,  2016,  2016,  -852,  2016,
    -852,  2016,  2016,  2016,  2016,  2016,  2016,  2016,  2016,  2016,
    2016,  2016,  2016,  2016,  2016,  2016,  2016,  2016,  2016,  2016,
    2016,  2016,  2016,  -852,   457,   457,  -852,  -852,  -852,   317,
    -852,  -852,   -53,  -852,  -852,     4,   294,  -852,  1206,  -852,
    -852,  1096,  -852,  -852,   374,  -852,  -852,   332,  -852,  -852,
    -852,  -852,   426,  1846,  -852,  -852,   440,   479,  -852,  -852,
    -852,  -852,  -852,   502,  -852,  -852,  -852,  -852,  2016,  2379,
    -852,  -852,  -852,  -852,  2465,  -852,  -852,  -852,  -852,  -852,
     460,   262,  -852,  -852,  -852,   107,   451,  -852,  -852,  -852,
     446,   450,  -852,  -852,  -852,  -852,  -852,  -852,  -852,    -8,
     458,  -852,  -852,  -852,    95,  -852,   463,   438,   444,  2016,
    2016,  2016,  2016,  2016,  2016,   435,    24,  -852,  -852,   575,
      50,  -852,  -852,  -852,   465,   469,   470,  -852,   466,   468,
     473,   476,     4,   472,   477,   478,   482,   486,   481,   489,
     490,   491,   498,   492,  -852,  1433,  2016,   500,   501,   497,
     499,   505,   507,   509,   510,   511,   513,   515,   520,   523,
     524,   521,   530,   534,   536,   533,   537,   538,   550,   552,
     554,   549,   557,   558,   559,  2016,  2016,  -852,  -852,  -852,
      40,  -852,  -852,  -852,  1467,  -852,  -852,   503,  -852,  -852,
    -852,  -852,  -852,  -852,  1467,  -852,  -852,   454,  -852,    28,
    -852,     3,  -852,  -852,  -852,  -852,  -852,   217,   159,  -852,
    -852,   380,  -852,  -852,  1730,   351,   406,  -852,  -852,   573,
     576,    58,  -852,  -852,   475,  1259,  -852,  -852,  1870,    58,
      58,   531,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  2016,
    -852,  2016,  -852,  -852,  -852,  -852,  -852,  -852,  -852,    24,
    -852,  2016,  2016,    50,  -852,  -852,  -852,  2016,  2016,  -852,
       4,  -852,  -852,  -852,  -852,  2016,  2016,  2016,  2016,  -852,
    -852,  -852,  2016,  -852,  -852,  2016,  -852,  -852,  -852,  -852,
    2016,  -852,  -852,   564,   560,  -852,  -852,  2016,  2016,  -852,
    -852,  -852,  -852,  -852,  -852,  2016,  -852,  -852,  -852,  2016,
    -852,  -852,  -852,  2016,  -852,  -852,  -852,  -852,  -852,  2016,
    -852,  -852,  -852,   574,  -852,  -852,  -852,  -852,  -852,  -852,
    -852,  -852,   -30,  -852,  -852,  -852,   144,  -852,  -852,  -852,
     565,   568,  -852,  -852,   578,  -852,  -852,  1730,  -852,   577,
    -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,
      74,  -852,   175,    90,   569,  -852,  -852,  -852,  -852,  -852,
    -852,  -852,  -852,    68,  -852,  -852,  -852,  -852,  -852,  -852,
      -9,  -852,  -852,  2465,   584,     4,  -852,   440,  -852,  -852,
    -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,
    -852,  1790,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,
    -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,
    -852,  -852,    47,   579,   585,   588,   582,   590,   591,   586,
    -852,   562,  -852,   592,   598,   599,   602,   586,   603,   605,
    -852,  -852,  -852,  -852,  -852,  1206,  -852,  -852,  1096,    93,
    -852,  1846,  -852,   611,  -852,  -852,  -852,   608,   -12,  -852,
     108,  -852,  -852,  -852,  -852,  -852,  1870,  -852,  -852,  -852,
    -852,  -852,  -852,  -852,   612,  -852,  -852,  -852,  -852,     4,
    -852,  -852,  2016,  -852,  1259,     4,  -852,  -852,   937,  -852,
    2016,  -852,  2016,  -852,  -852,  2016,  -852,  -852,  -852,   609,
     597,  -852,  -852,  -852,  -852,   615,  -852,  -852,    53,  1055,
    -852,  -852,  -852,  -852,  1846,  -852,  -852,  -852,  -852,   616,
    -852,  -852,  -852,  -852,  -852,  -852,  -852,   587,   625,    86,
     159,    87,    87,  -852,     4,   563,  -852,  -852,  -852,  -852,
    -852,   619,   586,  -852,   -71,  -852,  -852,  -852,  -852,   644,
      98,  -852,   217,  -852,  -852,   665,   645,    74,  -852,    74,
    -852,   105,  -852,   159,   159,  -852,    95,   671,  -852,   677,
    -852,  -852,  -852,  1467,  1467,  1467,   683,   618,    58,  -852,
    1870,  -852,  -852,  -852,  -852,     4,     4,   700,   684,  -852,
    -852,  -852,  -852,  -852,  -852,  -852,   -12,  -852,  -852,  -852,
    -852,  -852,  -852,  -852,    66,  -852,     4,  -852,  1846,   612,
    -852,  -852,  -852
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
       0,     0,   226,     0,   101,    74,   108,   615,   618,   617,
     450,   451,   107,    74,   105,   448,   449,   616,   119,   198,
     217,   217,   196,   226,   195,   217,   194,   286,     5,   162,
     159,    83,    74,   199,     0,     0,   205,   201,   204,    69,
      11,    15,   186,     0,   222,   221,   223,   220,   188,   190,
     189,     0,   228,     0,     0,    75,   119,   106,   109,   120,
     122,     0,   218,   215,     0,     0,     0,     0,     0,   160,
     284,     0,   285,     0,    81,    82,    84,     0,   119,   170,
     164,   166,   210,   211,   208,   203,   202,     0,     0,    17,
      22,    18,     0,   187,   182,   219,   224,   426,   427,   428,
     429,   430,   423,   609,   610,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   611,   613,   612,   614,   619,   620,
     457,   233,   229,   241,   340,   422,   421,   432,     0,   338,
     446,   447,   453,   454,   597,   598,   599,   455,   595,   452,
     456,     0,   112,   113,   114,   115,   117,   122,   122,   122,
     110,     0,   111,   124,   123,   247,   244,   118,   243,   217,
     216,   217,   225,   217,   287,   294,   296,     0,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   569,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   580,   581,   582,   583,     0,   584,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    99,    80,    95,    93,    89,   559,   522,
     524,   560,   561,    94,     0,    90,    91,    92,     0,   122,
      12,   167,   168,     0,     0,   209,     0,   206,    70,    20,
       0,   185,     0,   227,   228,   242,   239,   343,   431,     0,
       0,   593,   594,   596,   591,   116,   103,   102,   104,     0,
       0,   126,   125,   250,   191,   193,   192,     0,     0,   303,
       0,     0,     0,     0,   505,    86,   458,   461,   465,   467,
     469,   479,   490,   493,   498,   499,   500,   506,   501,   502,
     503,   504,   589,   572,     0,     0,     0,   563,   515,     0,
     335,   549,     0,     0,     0,     0,   570,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   521,   330,
     330,     0,   542,   543,     0,     0,     0,     0,   516,     0,
     541,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    98,   330,   330,   327,   326,    73,   199,
     165,   207,     0,   212,   213,     0,     0,    56,     0,    31,
      45,     0,    19,    23,     0,    29,    24,     0,    43,    25,
      26,   353,     0,   431,   352,   234,   230,     0,   240,   341,
     342,   344,   443,   431,   433,   442,   339,   592,     0,   130,
     131,   134,   136,   133,   137,   138,   140,   325,   323,   324,
       0,   128,   127,   437,   245,     0,     0,   246,   253,   251,
     257,     0,   361,   436,   435,   359,   289,   297,   295,     0,
       0,   496,   497,   495,     0,    87,     0,   459,   463,     0,
       0,     0,     0,     0,     0,     0,     0,   468,   470,   480,
     492,   590,   588,   573,     0,     0,     0,   336,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   331,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   214,   197,    71,
       0,   309,    35,   310,    36,    32,    33,     0,   311,   306,
     307,   308,   305,    49,    50,    46,    47,     0,    29,     0,
      43,     0,   424,   350,   356,   358,   231,   228,     0,   425,
     434,    86,   132,   139,     0,     0,     0,   121,   129,   153,
     155,     0,    77,   248,   315,   250,   258,   255,   431,   364,
       0,     0,   293,   300,   302,   304,   507,    85,    88,     0,
     462,     0,   466,   471,   472,   473,   474,   475,   476,     0,
     477,     0,     0,   485,   491,   481,   482,     0,     0,   494,
       0,   513,   514,   562,   333,     0,     0,     0,     0,   571,
     508,   509,     0,   511,   512,     0,   554,   555,   556,   557,
       0,   578,   579,     0,   586,   558,   544,     0,     0,   533,
     548,   540,   539,   520,   547,     0,   538,   519,   537,     0,
     546,   536,   527,     0,   518,   535,   526,   517,   525,     0,
     523,   545,   534,     0,   328,    55,    58,    57,    34,    39,
      48,    53,     0,    28,    37,    30,     0,    42,    51,    44,
     345,   354,   232,   236,     0,   146,   147,   141,   142,     0,
     144,   145,   149,   150,   157,   158,   151,   154,   152,   156,
       0,   404,     0,     0,     0,   366,   368,   369,   377,   384,
     385,   398,   390,   396,   378,   403,    78,   272,   276,   279,
     286,   270,   312,     0,     0,     0,   254,   230,   268,   260,
     262,   263,   264,   266,   267,   261,   259,   316,   265,   256,
     445,   431,   440,   444,   362,   363,   365,   360,   288,   290,
     291,   298,   460,   464,   478,   487,   488,   486,   489,   483,
     484,   574,     0,     0,     0,     0,     0,     0,     0,   565,
     575,     0,   587,     0,     0,     0,     0,   565,     0,     0,
     576,   333,    63,    40,    27,     0,    54,    41,     0,   347,
     351,   431,   357,     0,   135,   143,   148,     0,   414,   417,
       0,   405,   407,   416,   399,   438,   431,   388,   393,   401,
     402,   400,   395,   397,   119,   273,   277,   280,   283,     0,
     313,   322,     0,   269,   250,     0,   439,   441,     0,   337,
       0,   334,     0,   551,   552,     0,   510,   553,   566,     0,
       0,   577,   531,   532,   528,     0,   529,   530,     0,     0,
      38,    52,   348,   349,   431,   355,   237,   406,   415,     0,
     412,   420,   418,   419,   375,   381,   383,   386,   391,   122,
       0,   183,   183,   271,     0,     0,   252,   320,   301,   299,
     332,     0,   565,   564,     0,   567,   329,    59,    64,    60,
       0,   346,   228,   408,   410,   367,   379,     0,   389,     0,
     394,   161,   274,     0,     0,   314,     0,   317,   550,     0,
     585,    61,    62,     0,     0,     0,     0,   413,   372,   376,
     431,   382,   387,   392,    79,     0,     0,     0,     0,   318,
     321,   568,    67,    66,    65,   238,     0,   411,   370,   373,
     374,   380,   275,   278,     0,   282,     0,   409,   431,   119,
     319,   371,   281
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -852,  -852,  -852,  -852,  -852,  -852,   425,  -852,  -852,  -852,
    -852,  -852,  -852,  -852,  -852,  -852,   129,  -852,   285,  -852,
    -107,  -852,  -852,   150,  -852,  -852,   138,  -852,   293,  -852,
     -95,  -852,  -852,   157,  -852,  -852,  -852,  -852,  -852,  -852,
    -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,    38,
    -852,  -852,  -852,  -852,   267,  -852,  -852,  -852,   143,  -852,
     480,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,
    -852,  -852,  -852,  -852,  -157,   -82,  -852,  -187,  -852,  -852,
    -852,  -852,  -852,  -852,   290,  -852,  -852,   279,  -852,  -852,
      23,  -852,  -852,  -852,  -852,  -852,  -852,   145,   149,  -182,
    -852,  -852,   464,  -852,  -852,  -852,  -852,  -852,   687,  -852,
      -7,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,
    -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,
    -852,   686,  -852,  -852,    51,  -852,    19,   720,   -21,   751,
     705,  -852,  -287,     2,  -852,  -852,  -852,  -852,  -852,  -852,
    -852,  -852,  -852,  -415,  -852,  -852,  -852,  -852,  -607,  -852,
    -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,
    -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,
      10,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,
    -852,  -852,  -852,  -852,  -406,  -852,  -852,  -852,  -852,  -852,
    -852,  -852,  -852,  -852,  -852,  -589,  -108,   422,  -852,  -306,
    -741,   -48,  -232,  -852,  -852,  -852,  -852,  -852,  -852,  -206,
    -852,  -852,  -852,  -852,   -54,  -851,  -852,  -852,   -55,  -852,
    -852,  -852,  -852,  -852,  -321,  -852,  -181,  -852,  -852,  -852,
    -852,  -852,  -852,  -852,  -852,  -852,  -852,  -177,    45,  -852,
    -852,  -852,  -852,  -159,  -852,  -852,  -852,    43,  -852,  -151,
    -852,  -852,  -852,  -852,  -852,  -852,  -852,  -852,  -766,  -852,
     -97,  -852,  -852,  -852,  -852,  -311,  -852,  -318,  -852,  -852,
    -852,  -852,  -290,  -605,   -99,   -13,    35,  -852,   791,  -852,
    -852,  -852,   161,  -852,  -852,   158,  -852,  -852,  -852,    75,
    -852,  -852,   151,  -852,  -852,  -852,  -330,  -852,  -334,  -208,
    -309,  -111,  -852,  -852,  -783,  -852,  -852,  -852,  -852,  -852,
    -852,  -852,  -852,   -98,  -852,  -852,  -852,  -852,  -852,  -852,
     130,  -852,  -852,  -852,   183,  -852,   287,   288,   448,  -131,
     -17,  -852,  -852
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,    26,     5,     6,     7,    46,    90,
     139,   310,   140,   141,   442,   443,   599,   444,   445,   584,
     585,   725,   835,   586,   834,   446,   601,   447,   448,   594,
     595,   729,   838,   596,   837,   449,   580,   717,   832,   962,
     938,   899,   939,     8,    91,   137,   436,    27,    28,    53,
     484,   485,   766,   864,    82,   126,   127,   505,   506,   281,
     282,   283,   284,    29,    54,    30,    62,    63,   199,    31,
     105,   192,   193,   194,   195,   110,   111,   202,   203,   331,
     481,   617,   204,   469,   470,   332,   474,   475,   482,   737,
     738,   739,   740,   741,   618,   746,   748,   619,   620,    78,
      79,    80,     9,    83,   301,   302,   129,   130,    32,    33,
      48,   143,   144,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,   135,    86,   134,   305,   306,
      87,    88,   307,   433,   114,   115,    97,    98,    55,    74,
     101,   102,   171,   607,   455,   313,   456,   457,   843,   942,
     172,   315,   316,   207,   486,   208,   333,   487,   488,   776,
     624,   489,   626,   627,   777,   778,   779,   869,   780,   865,
     920,   975,   781,   866,   921,   782,   867,   922,   783,   784,
     119,   120,   121,   337,   631,   799,   122,   123,   338,   217,
     878,   635,   801,   499,   587,   785,   870,   924,   786,   787,
     875,   980,   996,   957,   788,   476,   477,   427,   831,   545,
     888,   812,   371,   664,   173,   319,   317,   459,   460,   452,
     902,   903,   840,   730,   453,   603,   842,   731,   604,   490,
     630,   629,   794,   795,   754,   856,   755,   989,   998,   990,
     969,   945,   756,   757,   914,   971,   946,   915,   758,   759,
     857,   948,   917,   760,   858,   950,   918,   761,   862,   762,
     863,   763,   851,   987,   967,   908,   944,   909,   852,   912,
     462,   175,   312,   176,   177,   178,   463,   790,   493,   621,
     494,   791,   605,   916,   465,   454,   344,   181,   345,   346,
     640,   507,   347,   642,   508,   348,   349,   517,   518,   350,
     351,   653,   659,   808,   654,   519,   352,   520,   353,   354,
     355,   356,   368,   288,   889,   289,   290,   291,   376,   532,
     292,   523,   660,   357,   683,   294,   822,   823,   358,   522,
     359,   322,   323,   324,   360,   184,   185,   186,   361,   188,
     362,    67,   190
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int SPARQLfedParser::yytable_ninf_ = -432;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        66,    72,    69,   179,    64,   174,    49,    50,    51,   388,
     326,   327,   328,    70,    71,   492,   287,    75,   789,   285,
     578,   478,   491,   792,   198,   742,   200,   458,   464,   293,
     632,    92,  -292,   633,   325,   597,   215,   103,   497,   849,
     366,   205,   -76,   112,   895,    66,   299,   727,   320,   107,
      93,  -119,    65,   941,   109,   303,    68,   147,   148,   149,
     150,   151,    56,   132,   133,   369,  -431,   425,    94,    99,
     657,   881,   723,   191,   724,   103,   145,   483,   715,   432,
       1,   716,   910,   197,   546,   189,   196,   103,   859,   879,
     850,    10,   104,   106,    11,   936,   880,    65,   210,   750,
      47,   108,   880,    52,   109,   164,   165,   166,   167,   751,
     298,   461,   428,   466,   658,   750,    73,   669,   575,   576,
     128,   833,   116,   752,    81,   751,   118,    57,    58,    59,
     860,   750,   724,   501,   502,   503,    77,   180,    89,   752,
      93,   751,   304,   113,   451,    85,   321,  1001,   742,   959,
      95,    96,   142,   450,   963,   752,   214,   881,   728,   911,
     753,   311,   286,    84,    85,   478,   146,   206,    57,    58,
      59,   861,   287,   610,   196,   285,   753,  -119,   201,  -292,
     634,    60,    61,   216,   871,   293,   877,   367,   597,   209,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    57,    58,    59,   168,   169,
      60,    61,   370,   170,   426,   179,   848,   174,   473,   479,
     997,   471,    57,    58,    59,   800,   849,    60,    61,    57,
      58,    59,   182,   211,   495,    57,    58,    59,    57,    58,
      59,   124,   125,    60,    61,   811,   212,   964,   965,   147,
     148,   149,   150,   151,    57,    58,    59,   295,  -431,   213,
     334,   300,   335,   437,   336,   308,   298,   926,   309,   152,
      57,    58,    59,    57,    58,    59,   314,   850,    60,    61,
      60,    61,   431,   318,   650,   183,   329,   434,    57,    58,
      59,   615,   616,   196,   330,    66,   339,   189,   836,   728,
      66,   189,    66,   467,   363,   478,   364,   492,   796,   797,
     296,   365,   298,   298,   491,   372,   189,   491,   286,   373,
     732,   805,   806,   809,   810,   374,    12,   375,    13,    14,
     438,    15,   509,   510,   511,   512,   513,   514,   377,    57,
      58,    59,   515,   516,    60,    61,   378,    65,   379,   180,
     380,   -21,    65,   180,    65,    57,    58,    59,   473,   381,
     873,   471,   382,   479,   472,   383,   384,   385,   180,   386,
     387,   389,   390,   498,   391,   392,   393,   439,   394,   440,
     395,   441,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    57,    58,    59,
     168,   169,    60,    61,   396,   170,    57,    58,    59,   397,
     398,   399,   400,   295,   401,   577,   537,   804,   -21,   402,
     403,   592,    19,   404,   592,   405,   406,   407,   478,   408,
     846,   409,   597,    20,    21,   410,   189,    22,   411,    23,
     412,   413,   414,   415,   182,   416,   189,    24,   182,    25,
     417,   418,   298,   419,   923,   420,   421,   298,   422,   424,
     927,   435,  -235,   182,   478,   -21,   296,   -21,   480,   -21,
     496,   504,   929,   588,   579,   544,   588,   138,   438,   602,
     491,   767,   768,   769,   606,   608,   614,   441,   180,   623,
     625,   628,   639,   940,   -21,   -21,   -21,   183,   180,   641,
     636,   183,   649,   479,   472,   638,   770,   661,   179,   955,
     174,   662,   663,  -249,   670,   665,   183,   666,   744,   671,
     771,   772,   667,   773,   673,   668,   495,   672,   674,   793,
     675,   676,   677,   678,   147,   148,   149,   150,   151,   637,
     679,   680,   685,   686,   609,   491,   687,   689,   688,   690,
     187,   691,   692,   693,   152,   694,   492,   982,   983,   984,
     992,   993,   696,   491,   695,   697,   698,   592,   589,   798,
     699,   589,   700,   745,   581,   297,   701,   592,   702,   704,
     705,  1000,   703,   182,   643,   644,   645,   646,   647,   648,
     189,    66,   706,   182,   707,   733,   708,   298,   709,   710,
     711,   712,   774,   616,   765,   615,   820,   719,   189,   721,
     821,   189,   765,   765,   592,   839,   830,   841,   340,   588,
     844,   590,   855,   775,   590,   872,   479,   883,   882,   588,
     884,   885,   886,   887,   891,   880,   183,   651,   652,   890,
     892,   893,   180,    65,   894,   896,   183,   897,   906,   743,
     907,   933,   109,   934,   956,   966,   764,   935,   943,   491,
     180,   958,   479,   180,   764,   764,   588,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    57,    58,    59,   168,   169,    60,    61,   949,
     170,   947,   793,   961,   970,   583,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    57,    58,    59,   589,   968,    60,    61,   979,   981,
     298,   985,   986,   994,   589,   429,   995,   722,   900,   598,
    -169,   297,   951,   765,   718,   853,   765,   182,   726,    12,
     600,    13,    14,   901,    15,   158,   159,   160,   161,   162,
     163,   720,   622,   613,   734,   182,   298,   793,   182,   612,
     845,   589,   187,   423,   430,   749,   187,   590,   747,   974,
     131,   100,   743,   136,   189,   495,    76,   590,   117,   874,
     868,   187,   919,   898,   521,   904,   905,   988,   972,    12,
     183,    13,    14,   991,    15,   847,   854,   -72,   973,   803,
     802,    16,    17,   960,   807,     0,   655,   656,   183,     0,
       0,   183,     0,     0,   590,     0,     0,     0,   592,    18,
       0,   592,    66,     0,   189,     0,   180,     0,     0,     0,
       0,   853,     0,   913,     0,    19,     0,     0,     0,   189,
       0,     0,     0,   179,     0,   174,    20,    21,     0,     0,
      22,     0,    23,     0,     0,     0,     0,   189,     0,     0,
      24,   592,    25,     0,     0,     0,     0,     0,     0,     0,
     588,   793,     0,   588,    65,     0,   180,     0,     0,     0,
       0,     0,   592,     0,     0,    19,   591,   189,     0,   591,
       0,   180,     0,     0,     0,     0,    20,    21,     0,     0,
      22,   187,    23,    66,     0,     0,     0,   952,     0,   180,
      24,   187,    25,   588,   953,   954,     0,  1002,     0,     0,
       0,   182,     0,     0,     0,   189,     0,     0,     0,     0,
     765,     0,   765,     0,   588,     0,    66,    66,     0,   180,
     976,   977,     0,     0,     0,     0,   592,   592,   592,     0,
       0,   765,     0,   189,     0,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   589,     0,     0,   589,   853,
       0,   182,     0,   999,   183,     0,     0,   180,     0,   928,
     581,   189,     0,     0,     0,     0,   182,     0,    65,    65,
       0,   978,     0,     0,     0,     0,     0,     0,   588,   588,
     588,     0,     0,   764,   182,   180,     0,     0,   589,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   590,     0,
       0,   590,     0,     0,   183,     0,     0,     0,     0,   589,
       0,     0,   591,   180,   182,     0,     0,     0,     0,   183,
       0,     0,   591,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   187,     0,   183,     0,     0,
       0,   590,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   182,   187,     0,     0,   187,     0,     0,   591,
       0,     0,   590,     0,     0,     0,     0,   183,     0,     0,
       0,     0,     0,   589,   589,   589,     0,   937,   581,     0,
     182,   583,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    57,    58,    59,
       0,     0,    60,    61,     0,   183,     0,     0,   182,     0,
       0,   500,     0,     0,     0,     0,     0,     0,     0,   581,
       0,     0,     0,     0,     0,     0,   590,   590,   590,     0,
       0,     0,     0,   183,     0,   524,   525,   526,     0,     0,
     527,     0,     0,   528,   529,   530,   531,     0,   533,   534,
     535,   536,     0,   538,   539,   540,   541,   542,   543,     0,
       0,   183,   547,     0,     0,   548,   549,   550,   551,     0,
     552,     0,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,     0,     0,     0,     0,     0,   583,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    57,    58,    59,     0,   187,
      60,    61,     0,     0,     0,     0,     0,     0,     0,   581,
       0,   593,     0,     0,     0,     0,     0,     0,     0,   611,
     583,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    57,    58,    59,     0,
       0,    60,    61,   591,     0,     0,   591,     0,     0,   187,
       0,   147,   148,   149,   150,   151,     0,     0,     0,     0,
    -431,     0,     0,     0,   187,     0,     0,     0,     0,     0,
     582,   483,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   187,     0,     0,     0,   591,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   682,   684,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   591,     0,     0,
       0,     0,   187,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   713,   714,     0,     0,
     583,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    57,    58,    59,     0,
     187,    60,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   591,   591,   591,     0,     0,     0,     0,   187,     0,
       0,     0,     0,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    57,
      58,    59,   168,   169,    60,    61,   187,   170,     0,     0,
       0,     0,     0,   681,     0,     0,   813,   814,   815,   816,
       0,     0,     0,   817,     0,     0,   818,     0,     0,     0,
       0,   819,     0,     0,   340,     0,     0,     0,   824,   825,
       0,     0,     0,     0,     0,     0,   826,     0,     0,     0,
     827,     0,     0,     0,   828,   341,   342,     0,   343,   220,
     829,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     581,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,     0,   241,     0,     0,     0,   242,   243,   244,
     245,   246,   247,   248,   249,     0,     0,     0,     0,     0,
       0,     0,   250,   251,   252,     0,   253,   254,   255,     0,
       0,   256,   257,     0,   258,     0,   259,   260,   261,   262,
       0,   263,   264,     0,   265,     0,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    57,    58,    59,     0,     0,    60,    61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   218,
       0,   583,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    57,    58,    59,
     219,     0,    60,    61,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   925,     0,     0,     0,     0,     0,     0,
       0,   930,     0,   931,     0,   220,   932,   221,   222,   223,
     224,   225,   226,   227,   228,   229,     0,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,     0,   241,
       0,     0,     0,   242,   243,   244,   245,   246,   247,   248,
     249,     0,     0,     0,     0,     0,     0,     0,   250,   251,
     252,     0,   253,   254,   255,     0,     0,   256,   257,     0,
     258,     0,   259,   260,   261,   262,     0,   263,   264,     0,
     265,     0,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   735,   736,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   340,     0,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    57,
      58,    59,     0,     0,    60,    61,   220,     0,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
     241,     0,   147,   148,   149,   150,   151,     0,     0,     0,
       0,   249,   876,     0,     0,     0,     0,     0,     0,   250,
     251,   252,   483,   253,   254,   255,     0,     0,   256,   257,
       0,   258,     0,   259,   260,   261,   262,     0,   263,   264,
       0,   265,     0,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   147,   148,
     149,   150,   151,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   152,     0,
       0,     0,   147,   148,   149,   150,   151,     0,     0,     0,
      57,    58,    59,     0,     0,    60,    61,     0,     0,     0,
       0,     0,   483,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      57,    58,    59,   168,   169,    60,    61,     0,   170,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    57,    58,    59,   168,
     169,    60,    61,     0,   170,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      57,    58,    59,   168,   169,    60,    61,   340,   170,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   341,   342,
       0,   343,   220,     0,   221,   222,   223,   224,   225,   226,
     227,   228,   229,     0,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,   241,     0,     0,     0,
     242,   243,   244,   245,   246,   247,   248,   249,     0,     0,
       0,     0,     0,     0,     0,   250,   251,   252,     0,   253,
     254,   255,     0,     0,   256,   257,     0,   258,     0,   259,
     260,   261,   262,     0,   263,   264,     0,   265,     0,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   219,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,   340,
       0,     0,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    57,    58,    59,
       0,     0,    60,    61,   220,     0,   221,   222,   223,   224,
     225,   226,   227,   228,   229,     0,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,     0,   241,     0,
       0,     0,   242,   243,   244,   245,   246,   247,   248,   249,
       0,     0,     0,     0,     0,     0,     0,   250,   251,   252,
       0,   253,   254,   255,     0,     0,   256,   257,     0,   258,
       0,   259,   260,   261,   262,     0,   263,   264,     0,   265,
       0,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     468,     0,     0,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    57,    58,
      59,     0,     0,    60,    61,   220,     0,   221,   222,   223,
     224,   225,   226,   227,   228,   229,     0,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,     0,   241,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     249,     0,     0,     0,     0,     0,     0,     0,   250,   251,
     252,     0,   253,   254,   255,     0,     0,   256,   257,     0,
     258,     0,   259,   260,   261,   262,   340,   263,   264,     0,
     265,     0,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,     0,     0,     0,
       0,   220,     0,   221,   222,   223,   224,   225,   226,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     0,   241,     0,     0,     0,    57,
      58,    59,     0,     0,    60,    61,   249,     0,     0,     0,
       0,     0,     0,     0,   250,   251,   252,     0,   253,   254,
     255,     0,     0,   256,   257,     0,   258,     0,   259,   260,
     261,   262,     0,   263,   264,     0,   265,     0,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    57,    58,    59
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        17,    22,    19,   102,    17,   102,    13,    14,    15,   241,
     197,   198,   199,    20,    21,   333,   127,    24,   625,   127,
     435,   330,   333,   628,   106,   614,   108,   314,   318,   127,
      38,    48,    41,    41,   191,   441,    41,    23,    42,    51,
      41,    37,    17,     6,   827,    62,   128,    44,    89,    62,
       6,    37,    17,   904,    40,    21,    18,    32,    33,    34,
      35,    36,    20,    84,    85,    41,    41,    41,    24,    50,
      20,   812,    44,    24,   104,    23,    93,    52,    38,    24,
      15,    41,   848,   104,   390,   102,   103,    23,    20,    42,
     102,   180,    40,    55,     0,    42,    49,    62,   115,    41,
      13,    63,    49,    37,    40,   176,   177,   178,   179,    51,
     127,   317,   299,   319,    64,    41,    37,   532,   424,   425,
      82,   151,    71,    65,    17,    51,    75,   180,   181,   182,
      62,    41,   104,   341,   342,   343,    31,   102,    16,    65,
       6,    51,   108,   106,    51,     4,   187,   998,   737,   932,
     106,   107,    10,   310,    56,    65,   121,   898,   155,    51,
     102,   142,   127,     3,     4,   474,    38,   163,   180,   181,
     182,   103,   283,   463,   191,   283,   102,   163,    92,   188,
     188,   185,   186,   188,   773,   283,   791,   188,   594,   112,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   188,   188,   188,   314,    41,   314,   329,   330,
     986,   329,   180,   181,   182,   631,    51,   185,   186,   180,
     181,   182,   102,   112,   333,   180,   181,   182,   180,   181,
     182,    18,    19,   185,   186,   660,    38,   149,   150,    32,
      33,    34,    35,    36,   180,   181,   182,   127,    41,   112,
     209,    50,   211,    37,   213,   181,   283,   874,    56,    52,
     180,   181,   182,   180,   181,   182,    44,   102,   185,   186,
     185,   186,   303,    41,   516,   102,    26,   304,   180,   181,
     182,    29,    30,   310,    93,   312,    37,   314,   154,   155,
     317,   318,   319,   320,    76,   614,    41,   625,   629,   630,
     127,    41,   329,   330,   625,    41,   333,   628,   283,    41,
     607,   651,   652,   657,   658,    41,     9,    41,    11,    12,
     104,    14,    56,    57,    58,    59,    60,    61,    41,   180,
     181,   182,    66,    67,   185,   186,    41,   312,    41,   314,
      41,    37,   317,   318,   319,   180,   181,   182,   469,    41,
     775,   469,    41,   474,   329,    41,    41,    41,   333,    41,
      41,    41,    41,   338,    41,   188,   188,   151,    41,   153,
      41,   155,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,    41,   188,   180,   181,   182,    41,
     188,    41,   188,   283,    41,   432,   381,   649,   104,    41,
      41,   438,   105,    41,   441,    41,    41,    41,   737,    41,
     739,    41,   838,   116,   117,    41,   453,   120,    41,   122,
      41,    41,    41,    41,   314,    41,   463,   130,   318,   132,
      41,    41,   469,    41,   869,    41,    41,   474,    41,    41,
     875,    40,     6,   333,   773,   151,   283,   153,    25,   155,
      37,    91,   878,   438,   180,    18,   441,   163,   104,    53,
     791,     6,     7,     8,    44,     6,    26,   155,   453,    38,
      44,    41,    54,   899,   180,   181,   182,   314,   463,    55,
      42,   318,    67,   614,   469,    42,    31,    42,   607,   924,
     607,    42,    42,    38,    42,    49,   333,    49,   167,    42,
      45,    46,    49,    48,    42,    49,   625,    49,    42,   628,
      49,    42,    42,    42,    32,    33,    34,    35,    36,   504,
      42,    49,    42,    42,    42,   856,    49,    42,    49,    42,
     102,    42,    42,    42,    52,    42,   874,   963,   964,   965,
     975,   976,    42,   874,    49,    42,    42,   584,   438,    38,
      49,   441,    42,   167,    43,   127,    42,   594,    42,    42,
      42,   996,    49,   453,   509,   510,   511,   512,   513,   514,
     607,   608,    42,   463,    42,   608,    42,   614,    49,    42,
      42,    42,   127,    30,   621,    29,    42,   104,   625,   155,
      50,   628,   629,   630,   631,    50,    42,    49,    41,   584,
      42,   438,    53,   148,   441,    41,   737,    42,    49,   594,
      42,    49,    42,    42,    42,    49,   453,    62,    63,    77,
      42,    42,   607,   608,    42,    42,   463,    42,    37,   614,
      42,    42,    40,    56,    91,   942,   621,    42,    42,   970,
     625,    42,   773,   628,   629,   630,   631,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    64,
     188,   104,   791,    49,    49,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   584,    50,   185,   186,    47,    42,
     737,    38,   104,    23,   594,   300,    42,   598,   835,   444,
       0,   283,   919,   750,   584,   752,   753,   607,   600,     9,
     447,    11,    12,   838,    14,   170,   171,   172,   173,   174,
     175,   594,   485,   474,   611,   625,   773,   856,   628,   469,
     737,   631,   314,   283,   300,   620,   318,   584,   619,   951,
      83,    51,   737,    87,   791,   874,    25,   594,    73,   777,
     770,   333,   864,   831,   362,   839,   841,   968,   947,     9,
     607,    11,    12,   970,    14,   750,   753,    17,   949,   641,
     639,    21,    22,   934,   653,    -1,   519,   519,   625,    -1,
      -1,   628,    -1,    -1,   631,    -1,    -1,    -1,   835,    39,
      -1,   838,   839,    -1,   841,    -1,   791,    -1,    -1,    -1,
      -1,   848,    -1,   850,    -1,   105,    -1,    -1,    -1,   856,
      -1,    -1,    -1,   942,    -1,   942,   116,   117,    -1,    -1,
     120,    -1,   122,    -1,    -1,    -1,    -1,   874,    -1,    -1,
     130,   878,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     835,   970,    -1,   838,   839,    -1,   841,    -1,    -1,    -1,
      -1,    -1,   899,    -1,    -1,   105,   438,   904,    -1,   441,
      -1,   856,    -1,    -1,    -1,    -1,   116,   117,    -1,    -1,
     120,   453,   122,   920,    -1,    -1,    -1,   920,    -1,   874,
     130,   463,   132,   878,   921,   922,    -1,   999,    -1,    -1,
      -1,   791,    -1,    -1,    -1,   942,    -1,    -1,    -1,    -1,
     947,    -1,   949,    -1,   899,    -1,   953,   954,    -1,   904,
     953,   954,    -1,    -1,    -1,    -1,   963,   964,   965,    -1,
      -1,   968,    -1,   970,    -1,   920,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   835,    -1,    -1,   838,   986,
      -1,   841,    -1,   994,   791,    -1,    -1,   942,    -1,    42,
      43,   998,    -1,    -1,    -1,    -1,   856,    -1,   953,   954,
      -1,   956,    -1,    -1,    -1,    -1,    -1,    -1,   963,   964,
     965,    -1,    -1,   968,   874,   970,    -1,    -1,   878,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   835,    -1,
      -1,   838,    -1,    -1,   841,    -1,    -1,    -1,    -1,   899,
      -1,    -1,   584,   998,   904,    -1,    -1,    -1,    -1,   856,
      -1,    -1,   594,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   607,    -1,   874,    -1,    -1,
      -1,   878,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   942,   625,    -1,    -1,   628,    -1,    -1,   631,
      -1,    -1,   899,    -1,    -1,    -1,    -1,   904,    -1,    -1,
      -1,    -1,    -1,   963,   964,   965,    -1,    42,    43,    -1,
     970,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
      -1,    -1,   185,   186,    -1,   942,    -1,    -1,   998,    -1,
      -1,   340,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    -1,   963,   964,   965,    -1,
      -1,    -1,    -1,   970,    -1,   364,   365,   366,    -1,    -1,
     369,    -1,    -1,   372,   373,   374,   375,    -1,   377,   378,
     379,   380,    -1,   382,   383,   384,   385,   386,   387,    -1,
      -1,   998,   391,    -1,    -1,   394,   395,   396,   397,    -1,
     399,    -1,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,    -1,    -1,    -1,    -1,    -1,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,    -1,   791,
     185,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   468,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,   185,   186,   835,    -1,    -1,   838,    -1,    -1,   841,
      -1,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      41,    -1,    -1,    -1,   856,    -1,    -1,    -1,    -1,    -1,
     104,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   874,    -1,    -1,    -1,   878,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   545,   546,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   899,    -1,    -1,
      -1,    -1,   904,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   575,   576,    -1,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
     942,   185,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   963,   964,   965,    -1,    -1,    -1,    -1,   970,    -1,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   998,   188,    -1,    -1,
      -1,    -1,    -1,    20,    -1,    -1,   665,   666,   667,   668,
      -1,    -1,    -1,   672,    -1,    -1,   675,    -1,    -1,    -1,
      -1,   680,    -1,    -1,    41,    -1,    -1,    -1,   687,   688,
      -1,    -1,    -1,    -1,    -1,    -1,   695,    -1,    -1,    -1,
     699,    -1,    -1,    -1,   703,    62,    63,    -1,    65,    66,
     709,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      43,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    90,    -1,    -1,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,   110,   111,    -1,   113,   114,   115,    -1,
      -1,   118,   119,    -1,   121,    -1,   123,   124,   125,   126,
      -1,   128,   129,    -1,   131,    -1,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,    -1,    -1,   185,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      -1,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
      41,    -1,   185,   186,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   872,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   880,    -1,   882,    -1,    66,   885,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    -1,    90,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,
     111,    -1,   113,   114,   115,    -1,    -1,   118,   119,    -1,
     121,    -1,   123,   124,   125,   126,    -1,   128,   129,    -1,
     131,    -1,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,    -1,    -1,   185,   186,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      90,    -1,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,   101,    42,    -1,    -1,    -1,    -1,    -1,    -1,   109,
     110,   111,    52,   113,   114,   115,    -1,    -1,   118,   119,
      -1,   121,    -1,   123,   124,   125,   126,    -1,   128,   129,
      -1,   131,    -1,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    -1,    -1,    -1,
     180,   181,   182,    -1,    -1,   185,   186,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,   173,
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
      -1,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,
      -1,   113,   114,   115,    -1,    -1,   118,   119,    -1,   121,
      -1,   123,   124,   125,   126,    -1,   128,   129,    -1,   131,
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
     111,    -1,   113,   114,   115,    -1,    -1,   118,   119,    -1,
     121,    -1,   123,   124,   125,   126,    41,   128,   129,    -1,
     131,    -1,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,    -1,
      -1,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,   185,   186,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,   110,   111,    -1,   113,   114,
     115,    -1,    -1,   118,   119,    -1,   121,    -1,   123,   124,
     125,   126,    -1,   128,   129,    -1,   131,    -1,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182
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
     185,   186,   255,   256,   474,   475,   529,   530,   238,   529,
     299,   299,   327,    37,   328,   299,   328,    31,   288,   289,
     290,    17,   243,   292,     3,     4,   315,   319,   320,    16,
     198,   233,   529,     6,    24,   106,   107,   325,   326,   325,
     326,   329,   330,    23,    40,   259,   238,   474,   238,    40,
     264,   265,     6,   106,   323,   324,   323,   329,   323,   369,
     370,   371,   375,   376,    18,    19,   244,   245,   238,   295,
     296,   297,   327,   327,   316,   314,   320,   234,   163,   199,
     201,   202,    10,   300,   301,   529,    38,    32,    33,    34,
      35,    36,    52,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   183,   184,
     188,   331,   339,   403,   459,   460,   462,   463,   464,   473,
     475,   476,   519,   523,   524,   525,   526,   527,   528,   529,
     531,    24,   260,   261,   262,   263,   529,   327,   264,   257,
     264,    92,   266,   267,   271,    37,   163,   342,   344,   112,
     529,   112,    38,   112,   475,    41,   188,   378,    20,    41,
      66,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    90,    94,    95,    96,    97,    98,    99,   100,   101,
     109,   110,   111,   113,   114,   115,   118,   119,   121,   123,
     124,   125,   126,   128,   129,   131,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   248,   249,   250,   251,   395,   475,   500,   502,   504,
     505,   506,   509,   512,   514,   519,   523,   527,   529,   264,
      50,   293,   294,    21,   108,   317,   318,   321,   181,    56,
     200,   325,   461,   334,    44,   340,   341,   405,    41,   404,
      89,   187,   520,   521,   522,   263,   266,   266,   266,    26,
      93,   268,   274,   345,   323,   323,   323,   372,   377,    37,
      41,    62,    63,    65,   475,   477,   478,   481,   484,   485,
     488,   489,   495,   497,   498,   499,   500,   512,   517,   519,
     523,   527,   529,    76,    41,    41,    41,   188,   501,    41,
     188,   401,    41,    41,    41,    41,   507,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,   401,    41,
      41,    41,   188,   188,    41,    41,    41,    41,   188,    41,
     188,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,   249,    41,    41,   188,   396,   266,   195,
     291,   327,    24,   322,   529,    40,   235,    37,   104,   151,
     153,   155,   203,   204,   206,   207,   214,   216,   217,   224,
     263,    51,   408,   413,   474,   333,   335,   336,   331,   406,
     407,   408,   459,   465,   471,   473,   408,   529,    41,   272,
     273,   395,   475,   500,   275,   276,   394,   395,   499,   500,
      25,   269,   277,    52,   239,   240,   343,   346,   347,   350,
     418,   464,   466,   467,   469,   473,    37,    42,   475,   382,
     477,   498,   498,   498,    91,   246,   247,   480,   483,    56,
      57,    58,    59,    60,    61,    66,    67,   486,   487,   494,
     496,   396,   518,   510,   477,   477,   477,   477,   477,   477,
     477,   477,   508,   477,   477,   477,   477,   475,   477,   477,
     477,   477,   477,   477,    18,   398,   398,   477,   477,   477,
     477,   477,   477,   477,   477,   477,   477,   477,   477,   477,
     477,   477,   477,   477,   477,   477,   477,   477,   477,   477,
     477,   477,   477,   477,   477,   398,   398,   529,   342,   180,
     225,    43,   104,   164,   208,   209,   212,   383,   475,   519,
     523,   527,   529,   155,   218,   219,   222,   383,   207,   205,
     217,   215,    53,   414,   417,   471,    44,   332,     6,    42,
     471,   477,   273,   276,    26,    29,    30,   270,   283,   286,
     287,   468,   243,    38,   349,    44,   351,   352,    41,   420,
     419,   373,    38,    41,   188,   380,    42,   475,    42,    54,
     479,    55,   482,   488,   488,   488,   488,   488,   488,    67,
     401,    62,    63,   490,   493,   525,   526,    20,    64,   491,
     511,    42,    42,    42,   402,    49,    49,    49,    49,   342,
      42,    42,    49,    42,    42,    49,    42,    42,    42,    42,
      49,    20,   477,   513,   477,    42,    42,    49,    49,    42,
      42,    42,    42,    42,    42,    49,    42,    42,    42,    49,
      42,    42,    42,    49,    42,    42,    42,    42,    42,    49,
      42,    42,    42,   477,   477,    38,    41,   226,   212,   104,
     222,   155,   205,    44,   104,   210,   215,    44,   155,   220,
     412,   416,   331,   474,   247,    27,    28,   278,   279,   280,
     281,   282,   394,   475,   167,   167,   284,   287,   285,   286,
      41,    51,    65,   102,   423,   425,   431,   432,   437,   438,
     442,   446,   448,   450,   475,   529,   241,     6,     7,     8,
      31,    45,    46,    48,   127,   148,   348,   353,   354,   355,
     357,   361,   364,   367,   368,   384,   387,   388,   393,   347,
     466,   470,   472,   473,   421,   422,   423,   423,    38,   374,
     383,   381,   481,   484,   401,   495,   495,   491,   492,   497,
     497,   342,   400,   477,   477,   477,   477,   477,   477,   477,
      42,    50,   515,   516,   477,   477,   477,   477,   477,   477,
      42,   397,   227,   151,   213,   211,   154,   223,   221,    50,
     411,    49,   415,   337,    42,   279,   499,   437,    41,    51,
     102,   451,   457,   529,   446,    53,   424,   439,   443,    20,
      62,   103,   447,   449,   242,   358,   362,   365,   369,   356,
     385,   394,    41,   342,   332,   389,    42,   472,   379,    42,
      49,   399,    49,    42,    42,    49,    42,    42,   399,   503,
      77,    42,    42,    42,    42,   503,    42,    42,   400,   230,
     209,   219,   409,   410,   413,   417,    37,    42,   454,   456,
     457,    51,   458,   529,   433,   436,   472,   441,   445,   264,
     359,   363,   366,   342,   386,   477,   347,   342,    42,   383,
     477,   477,   477,    42,    56,    42,    42,    42,   229,   231,
     383,   414,   338,    42,   455,   430,   435,   104,   440,    64,
     444,   266,   474,   299,   299,   342,    91,   392,    42,   503,
     528,    49,   228,    56,   149,   150,   331,   453,    50,   429,
      49,   434,   442,   448,   288,   360,   474,   474,   475,    47,
     390,    42,   383,   383,   383,    38,   104,   452,   425,   426,
     428,   436,   342,   342,    23,    42,   391,   457,   427,   327,
     342,   414,   264
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
      -1,   195,   297,   292,   296,    -1,    50,   291,    -1,    -1,
     293,    -1,   297,   294,    -1,    -1,   295,    -1,   298,    -1,
     302,    -1,   303,    -1,   305,    -1,   306,    -1,   307,    -1,
     304,    -1,   308,    -1,   309,    -1,   310,    -1,   311,    -1,
       9,   299,   529,   301,    -1,    -1,    13,    -1,    10,   325,
      -1,    -1,   300,    -1,    11,   299,   326,    -1,    14,   299,
     326,    -1,    12,   299,   325,    -1,   116,   299,   323,   112,
     323,    -1,   130,   299,   323,   112,   323,    -1,   117,   299,
     323,   112,   323,    -1,   132,   328,    -1,   122,   328,    -1,
     120,   327,    -1,   313,   315,   316,   318,    40,   342,    -1,
     105,   529,    -1,    -1,   312,    -1,    -1,   320,    -1,   319,
     314,    -1,   320,    -1,    -1,   316,   321,    -1,    21,   327,
      -1,    -1,   317,    -1,     3,   327,    -1,     4,   327,    -1,
     108,   322,    -1,   529,    -1,    24,   529,    -1,   106,    -1,
     324,   529,    -1,    -1,     6,    -1,     6,   529,    -1,   325,
      -1,   106,    -1,    24,    -1,   107,    -1,    37,   329,    38,
      -1,    37,   329,    38,    -1,    -1,   330,   331,   334,    -1,
      -1,   339,    -1,    -1,    44,    -1,   335,   332,   331,    -1,
      -1,   334,   333,    -1,    -1,    -1,    -1,   336,     6,   474,
     337,    37,   338,   331,    38,    -1,   403,   341,    -1,    44,
     331,    -1,    -1,   340,    -1,   344,    -1,   163,    -1,   239,
      -1,   346,    -1,    -1,    37,   345,   343,    38,    -1,   347,
     349,    -1,    -1,   350,    -1,   353,   332,   347,    -1,    -1,
     349,   348,    -1,   418,   352,    -1,    44,   347,    -1,    -1,
     351,    -1,   387,    -1,   355,    -1,   384,    -1,   357,    -1,
     361,    -1,   364,    -1,   393,    -1,   367,    -1,   368,    -1,
     354,    -1,   148,   342,    -1,    -1,    45,   356,   342,    -1,
      -1,    -1,    -1,     6,   358,   359,   474,   360,   342,    -1,
      -1,    -1,     7,   362,   363,   299,   474,   342,    -1,    -1,
      -1,     8,   365,   366,   299,   474,    23,   327,   264,    -1,
     127,    41,   477,    91,   475,    42,    -1,    31,   369,    -1,
     370,    -1,   375,    -1,    -1,    -1,   371,   475,   372,    37,
     373,    38,    -1,    -1,   373,   374,    -1,   383,    -1,    -1,
     376,   378,    37,   382,    38,    -1,    -1,   377,   475,    -1,
     188,    -1,    41,   377,    42,    -1,    -1,   379,   383,    -1,
      -1,    41,   381,   379,    42,    -1,   188,    -1,    -1,   382,
     380,    -1,   529,    -1,   519,    -1,   523,    -1,   527,    -1,
      43,    -1,   164,    -1,   475,    -1,    -1,    -1,    46,   385,
     386,   342,    -1,    -1,    -1,   388,   389,   342,   392,    -1,
      -1,    47,   391,   342,    -1,    -1,   392,   390,    -1,    48,
     394,    -1,   499,    -1,   500,    -1,   395,    -1,   529,   396,
      -1,   188,    -1,    -1,    41,   398,   477,   397,   400,    42,
      -1,    -1,    18,    -1,    49,   477,    -1,    -1,   400,   399,
      -1,   188,    -1,    -1,    41,   477,   402,   400,    42,    -1,
      -1,   473,   404,   408,    -1,    -1,   459,   405,   406,    -1,
     407,    -1,    -1,   408,    -1,   413,   414,   412,    -1,   413,
     414,    -1,    -1,   409,    -1,    50,   410,    -1,    -1,   412,
     411,    -1,   474,    -1,    51,    -1,   417,   416,    -1,    49,
     417,    -1,    -1,   416,   415,    -1,   471,    -1,    -1,   473,
     419,   423,    -1,    -1,   466,   420,   421,    -1,   422,    -1,
      -1,   423,    -1,    -1,   425,   424,   433,   430,    -1,   431,
      -1,   432,    -1,    -1,   425,   427,   414,    -1,    -1,   426,
      -1,    50,   428,    -1,    -1,   430,   429,    -1,   437,    -1,
     475,    -1,   436,   435,    -1,    49,   436,    -1,    -1,   435,
     434,    -1,   472,    -1,   438,    -1,    -1,   442,   439,   441,
      -1,   104,   442,    -1,    -1,   441,   440,    -1,    -1,   448,
     443,   445,    -1,    64,   448,    -1,    -1,   445,   444,    -1,
     450,   447,    -1,    -1,   449,    -1,   446,    -1,   102,   446,
      -1,   103,    -1,    20,    -1,    62,    -1,   529,    -1,    51,
      -1,    65,   451,    -1,    41,   437,    42,    -1,   457,    -1,
      41,   456,    42,    -1,   104,   457,    -1,    -1,   453,   452,
      -1,    -1,   457,   455,   453,    -1,    -1,   454,    -1,   529,
      -1,    51,    -1,   102,   458,    -1,   529,    -1,    51,    -1,
     462,    -1,   460,    -1,    -1,    52,   461,   408,    53,    -1,
     464,    41,   465,    42,    -1,    32,    -1,    33,    -1,    34,
      -1,    35,    -1,    36,    -1,    -1,   463,    -1,   471,    -1,
     465,   471,    -1,   469,    -1,   467,    -1,    -1,    52,   468,
     423,    53,    -1,   464,    41,   470,    42,    -1,   472,    -1,
     470,   472,    -1,   473,    -1,   459,    -1,   473,    -1,   466,
      -1,   475,    -1,   476,    -1,   475,    -1,   529,    -1,   185,
      -1,   186,    -1,   529,    -1,   519,    -1,   523,    -1,   527,
      -1,   531,    -1,   188,    -1,   478,    -1,   481,   480,    -1,
      54,   481,    -1,    -1,   480,   479,    -1,   484,   483,    -1,
      55,   484,    -1,    -1,   483,   482,    -1,   485,    -1,   488,
     486,    -1,    -1,   487,    -1,    56,   488,    -1,    57,   488,
      -1,    58,   488,    -1,    59,   488,    -1,    60,   488,    -1,
      61,   488,    -1,    67,   401,    -1,    66,    67,   401,    -1,
     489,    -1,   495,   494,    -1,   525,    -1,   526,    -1,    20,
     497,    -1,    64,   497,    -1,    -1,   491,    -1,    62,   495,
      -1,    63,   495,    -1,   490,   492,    -1,    -1,   494,   493,
      -1,   497,   496,    -1,    -1,   496,   491,    -1,    65,   498,
      -1,    62,   498,    -1,    63,   498,    -1,   498,    -1,   499,
      -1,   500,    -1,   517,    -1,   519,    -1,   523,    -1,   527,
      -1,   475,    -1,   512,    -1,    41,   477,    42,    -1,    78,
      41,   477,    42,    -1,    79,    41,   477,    42,    -1,    80,
      41,   477,    49,   477,    42,    -1,    81,    41,   477,    42,
      -1,    82,    41,   475,    42,    -1,    68,    41,   477,    42,
      -1,    69,    41,   477,    42,    -1,    70,   501,    -1,   118,
     188,    -1,   142,    41,   477,    42,    -1,   139,    41,   477,
      42,    -1,   131,    41,   477,    42,    -1,   125,    41,   477,
      42,    -1,    90,   401,    -1,   504,    -1,   145,    41,   477,
      42,    -1,   505,    -1,   143,    41,   477,    42,    -1,   141,
      41,   477,    42,    -1,   137,    41,   477,    42,    -1,   128,
      41,   477,    49,   477,    42,    -1,   138,    41,   477,    49,
     477,    42,    -1,   144,    41,   477,    49,   477,    42,    -1,
     113,    41,   477,    49,   477,    42,    -1,   114,    41,   477,
      49,   477,    42,    -1,   115,    41,   477,    42,    -1,   147,
      41,   477,    42,    -1,   140,    41,   477,    42,    -1,   136,
      41,   477,    42,    -1,   133,    41,   477,    42,    -1,   129,
      41,   477,    42,    -1,   124,    41,   477,    42,    -1,   123,
      41,   477,    42,    -1,   121,   188,    -1,   109,   188,    -1,
     110,   188,    -1,   111,    41,   477,    42,    -1,   146,    41,
     477,    42,    -1,   135,    41,   477,    42,    -1,   126,    41,
     477,    42,    -1,   119,    41,   477,    42,    -1,    71,   401,
      -1,    72,    41,   477,    49,   477,    49,   477,    42,    -1,
      73,    41,   477,    49,   477,    42,    -1,    74,    41,   477,
      49,   477,    42,    -1,    83,    41,   477,    49,   477,    42,
      -1,    84,    41,   477,    42,    -1,    85,    41,   477,    42,
      -1,    86,    41,   477,    42,    -1,    87,    41,   477,    42,
      -1,   101,    41,   477,    42,    -1,   502,    -1,   506,    -1,
     509,    -1,    41,   477,    42,    -1,   188,    -1,    88,    41,
     477,    49,   477,   503,    42,    -1,    -1,   399,    -1,   134,
      41,   477,    49,   477,   503,    42,    -1,    75,    41,   477,
      49,   477,    49,   477,   503,    42,    -1,    -1,    -1,    76,
     507,   508,   342,    -1,    -1,    -1,    66,    76,   510,   511,
     342,    -1,    94,    41,   398,   513,    42,    -1,   514,    41,
     398,   477,    42,    -1,    99,    41,   398,   477,   516,    42,
      -1,    20,    -1,   477,    -1,    95,    -1,    96,    -1,    97,
      -1,    98,    -1,   100,    -1,    50,    77,    56,   528,    -1,
      -1,   515,    -1,   529,   518,    -1,    -1,   396,    -1,   528,
     522,    -1,    89,   529,    -1,   187,    -1,   520,    -1,    -1,
     521,    -1,   524,    -1,   525,    -1,   526,    -1,   167,    -1,
     168,    -1,   169,    -1,   170,    -1,   171,    -1,   172,    -1,
     173,    -1,   174,    -1,   175,    -1,   165,    -1,   166,    -1,
     176,    -1,   178,    -1,   177,    -1,   179,    -1,   180,    -1,
     530,    -1,   182,    -1,   181,    -1,   183,    -1,   184,    -1
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
     935,   938,   939,   942,   944,   946,   947,   951,   954,   955,
     958,   959,   963,   966,   967,   970,   973,   974,   976,   978,
     981,   983,   985,   987,   989,   991,   994,   998,  1000,  1004,
    1007,  1008,  1011,  1012,  1016,  1017,  1019,  1021,  1023,  1026,
    1028,  1030,  1032,  1034,  1035,  1040,  1045,  1047,  1049,  1051,
    1053,  1055,  1056,  1058,  1060,  1063,  1065,  1067,  1068,  1073,
    1078,  1080,  1083,  1085,  1087,  1089,  1091,  1093,  1095,  1097,
    1099,  1101,  1103,  1105,  1107,  1109,  1111,  1113,  1115,  1117,
    1120,  1123,  1124,  1127,  1130,  1133,  1134,  1137,  1139,  1142,
    1143,  1145,  1148,  1151,  1154,  1157,  1160,  1163,  1166,  1170,
    1172,  1175,  1177,  1179,  1182,  1185,  1186,  1188,  1191,  1194,
    1197,  1198,  1201,  1204,  1205,  1208,  1211,  1214,  1217,  1219,
    1221,  1223,  1225,  1227,  1229,  1231,  1233,  1235,  1239,  1244,
    1249,  1256,  1261,  1266,  1271,  1276,  1279,  1282,  1287,  1292,
    1297,  1302,  1305,  1307,  1312,  1314,  1319,  1324,  1329,  1336,
    1343,  1350,  1357,  1364,  1369,  1374,  1379,  1384,  1389,  1394,
    1399,  1404,  1407,  1410,  1413,  1418,  1423,  1428,  1433,  1438,
    1441,  1450,  1457,  1464,  1471,  1476,  1481,  1486,  1491,  1496,
    1498,  1500,  1502,  1506,  1508,  1516,  1517,  1519,  1527,  1537,
    1538,  1539,  1544,  1545,  1546,  1552,  1558,  1564,  1571,  1573,
    1575,  1577,  1579,  1581,  1583,  1585,  1590,  1591,  1593,  1596,
    1597,  1599,  1602,  1605,  1607,  1609,  1610,  1612,  1614,  1616,
    1618,  1620,  1622,  1624,  1626,  1628,  1630,  1632,  1634,  1636,
    1638,  1640,  1642,  1644,  1646,  1648,  1650,  1652,  1654,  1656,
    1658
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   505,   505,   508,   514,   519,   530,   531,   532,   533,
     537,   542,   546,   548,   552,   554,   557,   559,   563,   563,
     581,   587,   590,   594,   595,   596,   597,   603,   604,   607,
     609,   613,   617,   621,   622,   626,   627,   631,   631,   639,
     645,   649,   650,   653,   655,   659,   663,   667,   668,   672,
     673,   677,   677,   685,   691,   695,   698,   700,   704,   704,
     711,   713,   717,   720,   722,   726,   729,   732,   738,   744,
     746,   744,   756,   756,   768,   771,   779,   782,   786,   779,
     805,   813,   816,   823,   826,   831,   838,   841,   846,   853,
     856,   859,   862,   865,   868,   871,   875,   880,   883,   891,
     894,   900,   906,   911,   921,   929,   932,   940,   943,   950,
     953,   958,   966,   973,   974,   978,   984,   990,   997,  1004,
    1006,  1011,  1018,  1021,  1026,  1029,  1034,  1037,  1042,  1046,
    1050,  1057,  1060,  1067,  1070,  1073,  1076,  1082,  1088,  1091,
    1098,  1103,  1110,  1114,  1122,  1124,  1132,  1135,  1143,  1151,
    1152,  1159,  1163,  1171,  1174,  1179,  1182,  1186,  1192,  1198,
    1202,  1208,  1211,  1215,  1215,  1225,  1228,  1230,  1234,  1237,
    1239,  1243,  1244,  1245,  1246,  1247,  1248,  1249,  1250,  1251,
    1252,  1253,  1257,  1263,  1266,  1273,  1280,  1283,  1287,  1293,
    1299,  1305,  1311,  1317,  1323,  1331,  1339,  1346,  1355,  1361,
    1364,  1368,  1371,  1375,  1379,  1385,  1387,  1393,  1399,  1402,
    1406,  1412,  1418,  1424,  1427,  1433,  1436,  1441,  1443,  1447,
    1453,  1456,  1459,  1462,  1469,  1476,  1482,  1482,  1490,  1492,
    1496,  1498,  1502,  1505,  1507,  1512,  1517,  1520,  1512,  1531,
    1535,  1538,  1540,  1544,  1545,  1558,  1559,  1564,  1564,  1575,
    1579,  1581,  1591,  1595,  1598,  1614,  1619,  1623,  1626,  1630,
    1631,  1632,  1633,  1634,  1635,  1636,  1637,  1638,  1641,  1645,
    1651,  1651,  1667,  1671,  1673,  1667,  1684,  1688,  1684,  1697,
    1701,  1697,  1718,  1729,  1735,  1736,  1740,  1742,  1740,  1749,
    1751,  1755,  1763,  1763,  1770,  1772,  1778,  1779,  1782,  1784,
    1790,  1790,  1795,  1801,  1803,  1807,  1810,  1813,  1816,  1819,
    1822,  1825,  1831,  1835,  1831,  1845,  1849,  1845,  1859,  1859,
    1871,  1873,  1877,  1887,  1888,  1889,  1893,  1901,  1905,  1905,
    1915,  1918,  1925,  1931,  1933,  1947,  1950,  1950,  1960,  1960,
    1963,  1963,  1969,  1972,  1974,  1979,  1984,  1988,  1990,  1995,
    1999,  2001,  2005,  2009,  2017,  2022,  2026,  2028,  2032,  2040,
    2040,  2043,  2043,  2049,  2052,  2054,  2058,  2058,  2064,  2065,
    2069,  2069,  2074,  2076,  2080,  2083,  2085,  2089,  2100,  2106,
    2110,  2113,  2115,  2119,  2126,  2130,  2130,  2140,  2146,  2149,
    2155,  2155,  2165,  2171,  2174,  2180,  2186,  2189,  2193,  2194,
    2200,  2203,  2206,  2212,  2215,  2218,  2221,  2227,  2228,  2234,
    2240,  2243,  2249,  2249,  2258,  2261,  2265,  2268,  2271,  2277,
    2280,  2288,  2289,  2293,  2293,  2306,  2334,  2337,  2340,  2343,
    2346,  2353,  2356,  2361,  2365,  2372,  2373,  2377,  2377,  2389,
    2416,  2420,  2427,  2428,  2432,  2433,  2437,  2440,  2444,  2447,
    2453,  2454,  2458,  2461,  2464,  2467,  2470,  2471,  2477,  2482,
    2491,  2498,  2501,  2509,  2518,  2525,  2528,  2535,  2540,  2553,
    2557,  2561,  2565,  2569,  2573,  2577,  2581,  2585,  2589,  2596,
    2601,  2610,  2613,  2620,  2623,  2630,  2633,  2638,  2641,  2645,
    2659,  2662,  2670,  2679,  2682,  2689,  2692,  2695,  2698,  2702,
    2703,  2704,  2705,  2708,  2711,  2714,  2717,  2721,  2727,  2730,
    2733,  2736,  2739,  2742,  2745,  2749,  2752,  2755,  2758,  2761,
    2764,  2767,  2770,  2771,  2774,  2775,  2778,  2781,  2784,  2787,
    2790,  2793,  2796,  2799,  2802,  2805,  2808,  2811,  2814,  2817,
    2820,  2823,  2826,  2829,  2832,  2835,  2838,  2841,  2844,  2847,
    2850,  2853,  2856,  2859,  2862,  2865,  2868,  2871,  2874,  2877,
    2878,  2879,  2885,  2888,  2895,  2902,  2905,  2909,  2915,  2921,
    2924,  2921,  2936,  2939,  2936,  2952,  2956,  2961,  2970,  2973,
    2977,  2980,  2983,  2986,  2989,  2995,  3001,  3004,  3008,  3018,
    3021,  3026,  3034,  3041,  3045,  3053,  3057,  3061,  3062,  3063,
    3067,  3068,  3069,  3073,  3074,  3075,  3079,  3080,  3081,  3085,
    3086,  3090,  3091,  3092,  3093,  3097,  3098,  3102,  3103,  3107,
    3108
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
  const int SPARQLfedParser::yylast_ = 2647;
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
#line 6185 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 3114 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


