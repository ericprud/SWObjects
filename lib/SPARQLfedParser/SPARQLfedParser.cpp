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
#line 314 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"

/* Line 299 of lalr1.cc  */
#line 467 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

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
}

/* Line 565 of lalr1.cc  */
#line 346 "lib/SPARQLfedParser/SPARQLfedParser.cpp"

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
#line 481 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 484 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 495 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 514 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 543 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.startBindingSet();
      }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 546 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 21:

/* Line 690 of lalr1.cc  */
#line 561 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = (yysemantic_stack_[(2) - (1)].p_RSName);
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 567 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = NULL;
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 577 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	throw std::runtime_error("need to partition out results set part of SimpleEngine::loadDataOrResults");
    }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 611 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 613 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 619 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 657 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 659 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 665 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 684 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow(false);
      }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 686 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 706 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 709 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 712 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 718 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 724 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 726 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 728 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 736 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 739 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause);
	(yyval.p_Operation) = new Select((yysemantic_stack_[(5) - (2)].p_Project).distinctness, (yysemantic_stack_[(5) - (2)].p_Project).varSet, (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
	driver.countStar = (yysemantic_stack_[(5) - (1)].p_parentCountStar);
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 748 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 751 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 759 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 762 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 765 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 769 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if ((yysemantic_stack_[(7) - (7)].p_BindingClause) != NULL)
	      (yysemantic_stack_[(7) - (5)].p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yysemantic_stack_[(7) - (7)].p_BindingClause), (yysemantic_stack_[(7) - (5)].p_WhereClause)->m_GroupGraphPattern);
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (4)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(7) - (3)].p_Project).distinctness, (yysemantic_stack_[(7) - (3)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(7) - (5)].p_WhereClause), (yysemantic_stack_[(7) - (6)].p_SolutionModifier))));
	  driver.curGraphName = (yysemantic_stack_[(7) - (2)].p_TTerm);
	  driver.countStar = (yysemantic_stack_[(7) - (1)].p_parentCountStar);
      }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 780 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 788 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 791 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 798 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 806 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 813 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 821 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 828 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 831 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 834 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 837 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 840 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 843 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 846 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 855 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 858 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 866 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 869 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 876 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = NULL;
      }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 878 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.lastWhereClause = (yysemantic_stack_[(6) - (5)].p_WhereClause);
	  /* $2 is NO LONGER known to be a DefaultGraphPattern because of grammar restrictions. */
	  (yyval.p_Operation) = new Construct((yysemantic_stack_[(6) - (2)].p_TableOperation), (yysemantic_stack_[(6) - (4)].p_DatasetClauses), (yysemantic_stack_[(6) - (5)].p_WhereClause), (yysemantic_stack_[(6) - (6)].p_SolutionModifier));
      }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 887 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause) ? (yysemantic_stack_[(5) - (4)].p_WhereClause) : new WhereClause(new DefaultGraphPattern());
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 895 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm))));
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 898 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_TTerm))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 906 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 909 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 916 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 924 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(3) - (3)].p_WhereClause);
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(3) - (2)].p_DatasetClauses), (yysemantic_stack_[(3) - (3)].p_WhereClause));
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 932 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 944 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 950 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 956 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 963 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.ensureGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 977 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 984 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 992 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1000 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1008 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1016 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1023 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1026 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1033 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1036 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1039 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1042 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1048 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1054 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1057 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1069 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1076 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1080 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1090 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1098 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1101 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1109 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1118 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1125 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1129 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1137 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1145 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1152 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1158 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1165 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1167 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1175 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1181 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1184 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1190 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow(); // @@ push down to _Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star?
      }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1192 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1195 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1207 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1210 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1213 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1216 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 1219 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 1222 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 1225 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 1235 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	OperationSet* ret = driver.root ? dynamic_cast<OperationSet*>(driver.root) : new OperationSet();
	ret->push_back((yysemantic_stack_[(2) - (2)].p_Operation));
	driver.root = ret;
      }
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 1239 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Operation) = driver.root;
	}
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1273 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(3) - (2)].p_URI), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1280 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1287 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1294 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1300 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1303 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1309 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1315 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1321 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1327 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1333 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1339 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1347 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1355 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1362 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(5) - (1)].p_URI))
	    w3c_sw_NEED_IMPL("WITH <URI> (DELETE INSERT?|INSERT) ...");
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(5) - (2)].p_DeleteInsert).del, (yysemantic_stack_[(5) - (2)].p_DeleteInsert).ins, new WhereClause(driver.ensureGraphPattern()));
	driver.curOp = NULL;
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 1371 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1377 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 1384 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 1391 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 1395 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1403 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("_QUsingClause_E_Star");
    }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 1409 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Delete) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1415 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = new Insert((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 1421 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 1427 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 1430 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 1436 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 1439 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 1450 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 1456 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 1459 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("DEFAULT");
      }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 1462 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("NAMED");
      }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 1465 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("ALL");
      }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 1472 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
    }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 1478 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 1484 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 1486 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TableOperation) = driver.ensureGraphPattern();
	  driver.curOp = NULL;
      }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 1514 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 1519 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 1522 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 1525 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 1547 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	BindingsMap::const_iterator rs = driver.bindingsMap.find((yysemantic_stack_[(1) - (1)].p_RSName)->name);
	if (rs == driver.bindingsMap.end())
	    error(*(yylocation_stack_.end()), std::string("") + "unknown named result set " + (yysemantic_stack_[(1) - (1)].p_RSName)->name);
	ResultSet* copy = new ResultSet(*rs->second);
	delete (yysemantic_stack_[(1) - (1)].p_RSName);
	BindingClause* b = new BindingClause(copy);
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, b) : b;
      }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 1566 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 1568 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 1639 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_BindingClause)) : (yysemantic_stack_[(1) - (1)].p_BindingClause);
    }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 1646 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Print(driver.curOp);
    }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 1652 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 1656 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 1668 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 1672 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 1674 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 1677 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 1685 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 1689 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 1691 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 1694 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(7) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(7) - (6)].p_TTerm), driver.curOp, (yysemantic_stack_[(7) - (5)].p_Silence), driver.atomFactory, false));
	  driver.curGraphName = (yysemantic_stack_[(7) - (4)].p_TTerm);
      }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 1702 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 1713 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 1717 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 1719 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 1727 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 1731 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 1733 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 1741 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 1746 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.ensureGraphPattern());
      }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 1759 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 1775 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 1783 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 1787 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 1790 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yysemantic_stack_[(6) - (4)].p_Expressions);
      }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 1797 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 1800 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 1807 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 1815 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 1829 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 1832 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 1835 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(5) - (3)].p_Expressions);
      }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 1842 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 1845 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 1905 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 1912 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 1916 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 1924 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 1927 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 1933 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 1944 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 1972 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 1999 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 2006 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 2017 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 2024 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 2060 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 2063 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 2066 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 2069 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 2127 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 2131 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 2140 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 407:

/* Line 690 of lalr1.cc  */
#line 2165 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 2168 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 2171 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 2174 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 2177 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 2184 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 2192 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 2196 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 2208 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 2215 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 2218 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 2229 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 2232 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 2235 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 2238 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 2242 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 2253 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 2262 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 2269 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 2272 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 2280 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 2289 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 2296 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 2299 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 2311 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_GeneralComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_GeneralComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_GeneralComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 2322 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 2329 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 2332 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 2335 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 2338 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 2341 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 2344 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 2347 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 2350 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 2361 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 2370 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 2373 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 2380 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 2383 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 2390 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 2398 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 2401 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 2405 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 2419 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 2422 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 2430 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 2439 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 2442 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 2449 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 2452 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 2455 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 2465 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 2468 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 2471 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 2474 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 2481 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 2487 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 2490 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 2493 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 2496 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 2499 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 2502 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 2505 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 2509 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 2512 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 2515 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 2518 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ciel, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 2521 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 2524 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 2527 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 2531 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 2534 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 2537 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 2540 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 2543 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 2546 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 2549 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 2552 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 2555 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 2558 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 2561 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 2564 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 2567 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 2570 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 2573 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 2576 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 2579 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 2582 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 2585 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_uuid, NULL, NULL, NULL));
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 2588 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_struuid, NULL, NULL, NULL));
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 2591 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 2594 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 2597 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 2600 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 2603 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 2606 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 2610 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 2613 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 2616 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 2619 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 2622 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 2625 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 2628 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 2631 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 2634 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 2645 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 2648 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 2655 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 2662 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 2669 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 2675 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.ensureGraphPattern(), NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 2682 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.ensureGraphPattern(), NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 2689 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 2693 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 2698 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 2702 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 545:

/* Line 690 of lalr1.cc  */
#line 2718 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 2725 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 2728 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 2731 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 2734 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 2737 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 2743 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 2749 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 2756 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 2766 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 2774 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 2782 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 2789 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 2793 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 2801 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 690 of lalr1.cc  */
#line 3704 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -801;
  const short int
  SPARQLfedParser::yypact_[] =
  {
       113,   -82,   136,  -801,  -801,   353,  -801,  -801,  -801,  -801,
    -801,  -801,   167,   139,   139,   139,   168,     4,  -801,   167,
     139,   139,   168,   170,   139,   170,   193,  -801,   211,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,    62,   243,  -801,  -801,  -801,
     220,  -801,  -801,   224,   258,   224,  -801,  -801,  -801,  -801,
    -801,    73,  -801,  -801,  -801,  -801,    37,  -801,    36,    36,
    -801,  -801,  -801,    36,  -801,  -801,  -801,  -801,    64,  -801,
     239,   168,   168,  -801,   269,  -801,  -801,    58,  -801,   258,
    -801,  -801,   167,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
     262,   985,  -801,  -801,    33,     1,  -801,  -801,  -801,    41,
    -801,  -801,   213,   167,   216,   296,   226,  -801,  -801,  -801,
    -801,  1444,    37,    86,  -801,  -801,  -801,  -801,     6,  -801,
    -801,   116,   285,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,   308,  -801,  -801,  -801,  -801,
     316,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
     -35,  -801,  -801,    37,   268,  -801,   167,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,    36,  -801,    36,  -801,
      36,    -8,  -801,  1658,   286,   322,   325,    -9,     0,   328,
     330,   331,    41,   336,   338,   339,   340,   342,   343,   344,
     345,   346,   348,   349,     0,   352,  -801,  -801,  -801,  -801,
     355,  -801,   356,   223,   225,   360,   362,   370,   372,   228,
     375,   230,   378,   380,   381,   382,   384,   385,   386,   387,
     388,   391,   398,   399,   400,   405,   406,   414,   415,   417,
     418,   421,   423,   426,  -801,  -801,  1778,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,   430,  -801,  -801,  -801,
       7,   268,    28,  -801,  -801,    41,    12,  -801,  -801,  -801,
      61,    82,   411,   985,  -801,  -801,    82,  1468,    82,   167,
    -801,  -801,  -801,  -801,   268,   447,  -801,   389,  -801,  -801,
     138,  -801,  -801,  -801,  -801,  -801,  1658,  1898,  1898,  1898,
    -801,   390,  -801,  -801,  -801,  -801,   377,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,     7,    41,
    1658,  1658,  1658,  -801,  -801,  1658,  -801,  -801,  1658,  1658,
    1658,  -801,  1658,  1658,  1658,  1658,   -65,  1658,  1658,  1658,
    1658,  1658,  1658,  -801,   459,   459,  1658,  -801,  -801,  1658,
    1658,  1658,  1658,  -801,  1658,  -801,  1658,  1658,  1658,  1658,
    1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,
    1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,  -801,   459,
     459,  -801,  -801,  -801,  -801,   167,  -801,  -801,   299,  -801,
    2082,  -801,  -801,  2042,  -801,  -801,   376,  -801,  -801,   329,
    -801,  -801,  -801,  -801,   432,  1468,  -801,  -801,   442,   481,
    -801,  -801,  -801,  -801,  -801,  1513,  -801,  -801,  -801,  -801,
    -801,  2018,  2227,   464,  -801,  -801,  -801,   452,  -801,  -801,
    -801,   449,  -801,  -801,   -19,   454,  -801,  -801,  -801,   -65,
    -801,   458,   437,   448,  1658,  1658,  1658,  1658,  1658,  1658,
     435,     0,  -801,  -801,   235,    48,  -801,  -801,  -801,   462,
     463,   465,  -801,   457,   466,   467,   472,   475,   469,   477,
     479,   474,   482,   484,   485,   487,   488,  -801,  1302,  1658,
     489,   491,   490,   492,   494,   496,   498,   500,   501,   505,
     502,   508,   510,   512,   506,   514,   515,   517,   511,   519,
     520,   521,   522,   523,   518,   524,   526,   527,  1658,  1658,
    -801,  -801,   194,  -801,  -801,  -801,  2106,  -801,  -801,   427,
    -801,  -801,  -801,  -801,  -801,  -801,  2106,  -801,  -801,   354,
    -801,     5,  -801,   -14,  -801,  -801,  -801,  -801,  -801,   985,
      73,  -801,  -801,  1658,  2018,  -801,  -801,  -801,  -801,  2227,
    -801,  -801,  -801,  -801,  -801,   546,   214,  -801,   211,  -801,
      78,   985,  -801,  -801,    82,    38,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  1658,  -801,  1658,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,     0,  -801,  1658,  1658,    48,  -801,  -801,
    -801,  1658,  1658,  -801,  -801,  -801,  -801,  -801,  1658,  1658,
    1658,  -801,  -801,  1658,  -801,  -801,  1658,  -801,  -801,  -801,
    -801,  1658,  -801,  -801,   533,  -801,  -801,  -801,  1658,  1658,
    -801,  -801,  -801,  -801,  -801,  -801,  1658,  -801,  -801,  -801,
    1658,  -801,  -801,  -801,  1658,  -801,  -801,  -801,  -801,  -801,
    1658,  -801,  -801,  -801,   534,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,   -59,  -801,  -801,  -801,   123,  -801,  -801,
    -801,   528,   530,  -801,  -801,   390,  -801,  -801,  1173,   368,
     416,  -801,  -801,   547,   551,  -801,  -801,  -801,  -801,  -801,
    2227,   543,    41,  -801,  -801,   442,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,    66,  -801,
      21,    70,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,    43,  -801,  -801,  -801,  2106,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,    76,   537,   548,   549,   550,
     554,   539,  -801,   552,   556,   558,   559,   539,   561,   562,
    -801,  -801,  -801,  -801,  -801,  2082,  -801,  -801,  2042,    82,
    -801,  1468,  -801,   568,   564,  -801,  -801,  1173,  -801,   566,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
     553,  -801,  -801,    41,  -801,  -801,  1658,  -801,   985,    41,
     567,   163,  -801,    91,  -801,  -801,  -801,  -801,  -801,  -801,
    1468,   509,   544,  -801,    55,  -801,  -801,  -801,  -801,  -801,
     944,  -801,  -801,  1658,  -801,  1658,  -801,  -801,  -801,  -801,
    -801,   569,   538,  -801,   571,  -801,  -801,  -801,   573,  -801,
    -801,   185,  2003,  -801,  -801,  -801,  -801,  1468,  -801,  -801,
    -801,  -801,  -801,   268,    73,  -801,  -801,    41,   532,  -801,
    -801,  -801,  -801,   575,  -801,  -801,  -801,  -801,  -801,    66,
    -801,    66,  -801,   460,  -801,  -801,    89,  -801,  -801,  -801,
     576,  -801,   572,  -801,  -801,  -801,  -801,  -801,   574,   142,
    -801,   985,   193,  -801,   139,  -801,   -65,   577,  -801,   529,
     579,  -801,  -801,   587,  -801,    31,  -801,  -801,   117,  -801,
    -801,  2106,  2106,  2106,   589,  -801,    41,    73,   588,  -801,
    -801,   163,  -801,    38,  -801,  -801,  -801,  -801,   595,  -801,
    -801,  -801,  -801,  -801,  -801,    41,  -801,    41,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  1468,  -801
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        13,     0,     0,     2,     4,   213,    15,    14,     3,   177,
      69,     1,     0,   201,   201,   201,     0,     0,    75,     0,
     201,   201,     0,     0,   201,     0,    10,     6,     0,     7,
       8,     9,   178,   185,   186,   187,   191,   188,   189,   190,
     192,   193,   194,   195,   214,     0,    17,   582,   585,   584,
     198,   583,   202,     0,     0,     0,   237,   102,   108,   422,
     423,   107,    75,   105,   420,   421,   119,   212,   228,   228,
     210,   237,   209,   228,   208,   159,     5,    11,    84,    75,
     183,     0,     0,   219,   215,   218,    70,    12,    16,     0,
     199,   196,     0,   233,   232,   234,   231,   200,   204,   203,
       0,   239,    75,   106,   109,     0,   120,    76,   111,     0,
     229,   226,     0,     0,     0,     0,     0,   161,    82,    83,
      85,     0,   119,    13,   184,   179,   221,   222,     0,   217,
     216,     0,     0,    18,    23,    19,   197,   230,   235,   407,
     408,   409,   410,   411,   404,   576,   577,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   578,   580,   579,   581,
     586,   587,   429,   244,   240,   252,   319,   403,   402,   413,
       0,   317,   418,   419,   425,   426,   564,   565,   566,   427,
     562,   424,   428,   119,   122,   110,     0,   112,   113,   114,
     115,   117,   258,   255,   118,   254,   228,   227,   228,   236,
     228,     0,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   547,   548,   549,   550,
       0,   551,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,    98,   100,    81,    93,    90,
      92,   530,   494,   531,   532,    91,     0,    94,    95,    96,
       0,   122,   213,   181,   182,     0,     0,   220,    71,    21,
       0,     0,   238,   239,   253,   250,   329,   412,     0,     0,
     560,   561,   563,   558,   122,     0,   104,   124,   123,   116,
     261,   205,   207,   206,   168,   162,     0,     0,     0,     0,
     477,    87,   430,   433,   437,   439,   441,   451,   462,   465,
     470,   471,   472,   478,   473,   474,   475,   476,   556,     0,
       0,     0,     0,   534,   487,     0,   314,   520,     0,     0,
       0,   539,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   493,   309,   309,     0,   513,   514,     0,
       0,     0,     0,   488,     0,   512,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,   309,
     309,   306,   305,    74,   211,     0,   223,   224,     0,    57,
       0,    32,    46,     0,    20,    24,     0,    30,    25,     0,
      44,    26,    27,   337,     0,   412,   336,   245,   241,     0,
     251,   330,   320,   328,   417,   412,   414,   416,   318,   559,
     103,     0,     0,   126,   125,   256,    78,     0,   257,   264,
     262,   268,   340,   338,     0,     0,   468,   469,   467,     0,
      88,     0,   431,   435,     0,     0,     0,     0,     0,     0,
       0,     0,   440,   442,   452,   464,   557,   555,   540,     0,
       0,     0,   315,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   310,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     225,    72,     0,   174,    36,   175,    37,    33,    34,     0,
     176,   171,   172,   173,   170,    50,    51,    47,    48,     0,
      30,     0,    44,     0,   405,   326,   333,   335,   242,   239,
       0,   406,   415,     0,   130,   131,   134,   136,   133,   137,
     138,   140,   304,   302,   303,     0,   128,   127,     0,   259,
     294,   261,   269,   266,   329,     0,   160,   165,   167,   169,
     479,    86,    89,     0,   434,     0,   438,   443,   444,   445,
     446,   447,   448,     0,   449,     0,     0,   457,   463,   453,
     454,     0,     0,   466,   485,   486,   533,   312,     0,     0,
       0,   480,   481,     0,   483,   484,     0,   525,   526,   527,
     528,     0,   545,   546,     0,   543,   529,   515,     0,     0,
     504,   519,   511,   510,   492,   518,     0,   509,   491,   508,
       0,   517,   507,   498,     0,   490,   506,   497,   489,   496,
       0,   495,   516,   505,     0,   307,    56,    59,    58,    35,
      40,    49,    54,     0,    29,    38,    31,     0,    43,    52,
      45,   321,   331,   243,   247,    87,   132,   139,     0,     0,
       0,   121,   129,   153,   155,    79,   282,   286,   280,   291,
       0,     0,     0,   277,   265,   241,   278,   271,   273,   274,
     276,   272,   270,   295,   275,   267,   353,   341,     0,   383,
       0,     0,   339,   342,   344,   345,   354,   356,   359,   368,
     363,   366,   381,   355,   382,     0,   432,   436,   450,   459,
     460,   458,   461,   455,   456,     0,     0,     0,     0,     0,
       0,   536,   541,   553,     0,     0,     0,   536,     0,     0,
     542,   312,    64,    41,    28,     0,    55,    42,     0,   323,
     327,   412,   334,     0,     0,   146,   147,   141,   142,     0,
     144,   145,   149,   150,   157,   158,   151,   154,   152,   156,
     119,   283,   287,     0,   292,   301,     0,   279,   261,     0,
       0,   391,   399,     0,   384,   386,   393,   395,   398,   369,
     412,   357,   361,   377,     0,   379,   378,   365,   367,   370,
       0,   163,   316,     0,   313,     0,   522,   523,   482,   524,
     537,     0,     0,   554,     0,   502,   503,   499,     0,   500,
     501,     0,     0,    39,    53,   324,   325,   412,   332,   248,
     135,   143,   148,   122,     0,   288,   281,     0,     0,   263,
     299,   385,   392,     0,   388,   397,   400,   396,   351,     0,
     360,     0,   364,     0,   401,   380,     0,   166,   164,   311,
       0,   535,     0,   544,   538,   308,    60,    65,    61,     0,
     322,   239,    10,   284,   201,   293,     0,   296,   394,   390,
     343,   358,   362,     0,   374,     0,   375,   521,     0,    62,
      63,     0,     0,     0,     0,    80,     0,     0,     0,   297,
     300,     0,   389,   348,   352,   376,   371,   373,     0,   552,
      68,    67,    66,   249,   285,     0,   290,     0,   387,   346,
     349,   350,   372,   289,   298,   412,   347
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -801,  -801,  -801,  -801,  -801,  -259,   513,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,    85,  -801,   218,  -801,
    -128,  -801,  -801,   102,  -801,  -801,    87,  -801,   221,  -801,
    -127,  -801,  -801,    96,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,    -4,
    -801,  -801,  -801,  -801,    67,  -801,  -801,  -801,   -37,  -801,
     383,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -161,   -96,  -801,  -267,  -801,  -801,
    -801,  -801,  -801,  -801,    88,  -801,  -801,    81,  -801,  -801,
    -126,  -801,  -801,  -801,  -801,  -801,  -801,   -41,   -36,    74,
    -801,  -801,  -801,  -801,  -801,  -801,  -401,  -801,   535,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,   -11,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,   578,  -801,  -801,   -39,  -801,    10,
     600,    32,   631,   590,  -801,  -282,   -45,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -211,  -801,  -801,  -801,
    -801,  -566,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -644,  -102,   326,  -801,  -308,  -604,   -98,  -204,  -801,  -801,
    -801,  -801,  -238,  -801,  -801,  -801,  -801,  -801,    83,  -777,
    -801,  -801,  -105,  -101,  -801,  -801,  -801,  -801,  -801,  -253,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,   -47,  -801,
    -801,  -801,  -197,  -801,  -801,   -46,  -801,  -194,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -769,  -801,  -801,  -800,   -95,  -801,  -801,  -801,  -801,
    -801,  -801,  -270,   -85,   -15,    34,  -801,   708,  -801,  -801,
    -801,    90,  -801,  -801,    79,  -801,  -801,  -801,   -16,  -801,
    -801,    71,  -801,  -801,  -801,  -323,  -801,  -263,    35,  -420,
    -104,  -801,  -801,   -78,  -801,  -801,  -801,   -71,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,   -38,  -801,  -801,  -801,    84,
    -801,   206,   207,   234,  -226,   -12,  -801,  -801
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,    26,    76,     5,     6,    46,    87,
     133,   290,   134,   135,   414,   415,   551,   416,   417,   536,
     537,   676,   765,   538,   764,   418,   553,   419,   420,   546,
     547,   680,   768,   548,   767,   421,   532,   668,   762,   910,
     887,   842,   888,     7,    88,   131,   408,    27,    28,    66,
     445,   446,   578,   790,    79,   120,   121,   460,   461,   264,
     265,   266,   267,    29,   102,    30,    61,    62,   184,    31,
     107,   187,   188,   189,   190,   108,   109,   306,   307,   443,
     576,   691,   308,   564,   565,   444,   569,   570,   577,   777,
     778,   779,   780,   781,   692,   786,   788,   693,   694,    77,
     117,   201,   820,   589,   735,   454,   539,     8,     9,    80,
     284,   124,   125,    32,    33,    90,    91,    34,    53,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
     129,    83,   128,    84,    85,   287,   406,   112,   113,    96,
      97,    57,    72,   100,   101,   163,   559,   427,   292,   428,
     429,   773,   891,   164,   294,   295,   194,   447,   195,   310,
     448,   449,   704,   580,   450,   582,   583,   705,   706,   707,
     793,   708,   791,   854,   916,   709,   792,   855,   894,   710,
     711,   794,   857,   712,   713,   799,   920,   937,   897,   714,
     571,   572,   402,   761,   498,   824,   745,   347,   617,   165,
     298,   296,   431,   845,   846,   770,   681,   432,   433,   555,
     772,   682,   556,   425,   451,   585,   584,   722,   810,   723,
     940,   945,   941,   924,   900,   717,   724,   725,   726,   727,
     870,   811,   728,   872,   812,   729,   817,   730,   818,   927,
     906,   875,   819,   731,   732,   804,   922,   899,   862,   863,
     805,   806,   866,   807,   876,   434,   167,   291,   168,   169,
     170,   435,   557,   437,   426,   320,   173,   321,   322,   594,
     462,   323,   596,   463,   324,   325,   472,   473,   326,   327,
     607,   613,   742,   608,   474,   328,   475,   329,   330,   331,
     332,   344,   271,   831,   272,   273,   274,   333,   753,   634,
     276,   833,   834,   334,   477,   335,   301,   302,   303,   336,
     176,   177,   178,   337,   180,   338,    51,   182
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int SPARQLfedParser::yytable_ninf_ = -413;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        50,   351,    63,    54,    55,    65,   166,    67,   185,    68,
      69,   430,   549,    73,   403,   715,   171,   270,   586,   268,
     363,   587,   573,    58,   186,   309,   281,   436,   314,   678,
     114,   342,   864,   868,   116,   405,    12,   440,    13,    14,
     345,    15,   110,   675,   782,   285,   103,   400,   674,    65,
     275,    64,   299,   424,    70,   105,   795,   499,   104,   105,
     438,   801,   813,   174,    98,    81,    82,   611,   926,  -119,
     890,   802,   106,   903,   404,   122,   106,   192,   718,   814,
     137,   118,   119,   277,   696,   697,  -180,   304,   719,   181,
     763,   528,   529,   191,   -22,    64,    10,   409,   183,   136,
       1,   197,   720,   873,   815,   928,   718,   675,    75,   280,
     718,   612,   286,   126,   127,  -260,   719,   822,    59,    60,
     719,   803,   698,   699,   823,   700,   904,     1,   478,   422,
     720,    19,   423,   782,   720,   172,    11,   905,   721,   679,
     111,   865,    20,    21,   816,   549,    22,   830,    23,   573,
     300,    52,   938,   830,   -77,   269,    24,   311,    25,   312,
     -22,   313,   270,   410,   268,   562,   721,   588,   946,   139,
     140,   141,   142,   143,   191,    59,    60,   343,  -412,    47,
      48,    49,    47,    48,    49,   175,   346,    59,    60,   144,
      47,    48,    49,   401,  -119,   275,   874,   911,   166,    47,
      48,    49,   193,   701,    56,   278,    71,   -22,   171,   -22,
     411,   -22,   412,   802,   413,   452,    47,    48,    49,   132,
     874,    59,    60,    75,   702,   453,   885,    78,   277,    89,
      92,   666,   859,   823,   667,   315,   -22,   -22,   -22,    47,
      48,    49,   689,   690,    47,    48,    49,    93,    47,    48,
      49,    47,    48,    49,   280,   174,    59,    60,    86,   174,
      47,    48,    49,   803,    92,    59,    60,   604,   573,    47,
      48,    49,   174,    82,   407,   766,   679,   683,   191,    65,
     573,   181,   739,   740,    65,   181,    65,   439,   123,   912,
     913,   156,   157,   158,   159,   288,   605,   606,   181,   138,
     269,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,    47,    48,    49,   160,
     161,    59,    60,   196,   162,    64,   198,   172,    94,    95,
      64,   172,    64,   199,   821,   179,   200,   568,   574,   566,
     289,    47,    48,    49,   172,    47,    48,    49,   743,   744,
     278,   293,   456,   457,   458,   279,   297,   573,   305,   852,
     339,    12,   340,    13,    14,   341,    15,   549,   348,   -73,
     349,   350,   541,    16,    17,   541,   352,   175,   353,   354,
     355,   175,   356,   357,   358,   359,   360,   174,   361,   362,
     490,    18,   364,   530,   175,   365,   366,   174,   544,   738,
     369,   544,   370,   150,   151,   152,   153,   154,   155,   367,
     371,   368,   372,   181,   373,   374,   375,  -246,   376,   878,
     377,   378,   379,   181,   380,   381,   382,   383,   384,   280,
     280,   385,   464,   465,   466,   467,   468,   469,   386,   387,
     388,   889,   470,   471,   540,   389,   390,   540,   597,   598,
     599,   600,   601,   602,   391,   392,    19,   393,   394,   172,
     568,   395,   566,   396,   166,   574,   397,    20,    21,   172,
     399,    22,   441,    23,   171,   567,   497,   531,   410,   459,
     442,    24,   413,    25,   554,   558,   452,   560,   575,   579,
     593,   797,   581,   591,   542,   590,   453,   542,   541,   592,
     279,   603,   595,   614,   615,   618,   616,   672,   541,   175,
     930,   931,   932,   621,   619,   620,   622,   623,   624,   175,
     625,   174,   626,   627,   544,   628,   629,   179,   630,   670,
     636,   179,   637,   784,   544,   640,   631,   641,   638,   642,
     639,   643,   644,   174,   179,   684,   645,   181,    65,   647,
     646,   648,   280,   649,   650,   651,   652,   280,   653,   654,
     655,   656,   657,   658,   659,   661,   660,   662,   663,   181,
     540,   688,    65,   734,   752,   760,   690,   769,   771,   689,
     540,   785,   856,   796,   574,   825,   892,   823,   860,   826,
     827,   828,   106,   172,    64,   829,   574,   835,   567,   836,
     837,   832,   839,   840,   849,   850,   316,   871,   861,   914,
     881,   869,   883,   882,   884,   172,   898,   907,    64,   733,
     542,   896,   909,   919,   925,   874,   933,   908,   923,   936,
     542,   921,   942,   915,   550,   673,   282,   843,   669,   677,
     552,   844,   671,   175,   543,   695,   895,   543,   774,   398,
     687,   851,   686,   789,   703,    99,    74,   787,   283,   179,
     798,   115,   130,   841,   476,   175,   848,   716,   847,   179,
     939,   800,   901,   574,   737,   809,   280,   902,   741,   838,
     609,   610,   929,   736,     0,     0,     0,     0,   280,     0,
       0,     0,     0,     0,   853,     0,     0,   541,     0,     0,
       0,     0,     0,   452,     0,   934,   734,     0,   808,   734,
       0,     0,     0,   453,     0,     0,     0,     0,     0,     0,
       0,     0,   783,   544,   943,     0,   944,   541,     0,     0,
     541,     0,     0,   174,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   544,     0,     0,   544,    65,     0,   181,
     174,     0,     0,     0,     0,   280,     0,     0,     0,   540,
     543,     0,   174,     0,     0,     0,     0,     0,     0,     0,
     543,     0,   541,     0,     0,     0,   181,     0,     0,   808,
       0,   867,     0,   179,     0,     0,   166,     0,   181,   540,
       0,     0,   540,    64,   541,   172,   171,     0,   544,   174,
       0,   783,     0,     0,     0,   179,     0,     0,     0,   542,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     544,     0,   172,     0,     0,   181,     0,     0,     0,   893,
       0,     0,    65,     0,   172,     0,     0,     0,     0,   542,
       0,     0,   542,   174,   540,   175,     0,   734,     0,   734,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   541,   541,   541,   540,     0,     0,   181,
       0,   172,   175,   917,     0,     0,     0,     0,    64,     0,
       0,     0,     0,     0,   175,     0,     0,     0,     0,   544,
     544,   544,   935,     0,   542,    65,     0,   174,     0,   808,
       0,   734,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   172,   542,     0,     0,     0,
     918,   175,     0,   181,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   540,   540,   540,     0,     0,
       0,    64,     0,     0,     0,     0,     0,   733,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   543,
       0,     0,     0,     0,     0,   175,     0,     0,     0,   172,
       0,     0,     0,     0,     0,   877,   533,     0,     0,     0,
       0,     0,     0,     0,     0,   542,   542,   542,     0,   543,
       0,     0,   543,     0,     0,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   139,   140,   141,   142,
     143,     0,     0,     0,   455,  -412,     0,     0,     0,   175,
       0,     0,   179,     0,     0,     0,   144,     0,     0,     0,
       0,     0,     0,     0,   179,     0,     0,     0,   479,   480,
     481,     0,     0,   482,   543,     0,   483,   484,   485,     0,
     486,   487,   488,   489,     0,   491,   492,   493,   494,   495,
     496,     0,     0,     0,   500,     0,   543,   501,   502,   503,
     504,   179,   505,     0,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   535,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,    47,    48,    49,   179,     0,    59,    60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   543,   543,   543,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,    47,    48,    49,   160,   161,    59,    60,
       0,   162,     0,     0,     0,     0,     0,     0,     0,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   775,
     776,     0,     0,     0,     0,     0,   633,   635,     0,     0,
       0,     0,     0,   316,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   664,   665,   204,     0,
     205,   206,   207,   208,   209,   210,   211,   212,     0,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
       0,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   685,   232,     0,     0,     0,     0,     0,     0,     0,
     233,   234,   235,     0,   236,   237,   238,     0,     0,   239,
     240,     0,   241,     0,   242,   243,   244,   245,     0,   246,
     247,     0,   248,     0,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,     0,
       0,   632,     0,     0,     0,     0,   746,   747,   748,     0,
       0,   749,     0,     0,   750,     0,     0,     0,     0,   751,
       0,     0,   316,     0,     0,     0,   754,   755,     0,     0,
       0,    47,    48,    49,   756,     0,    59,    60,   757,     0,
       0,     0,   758,   317,   318,     0,   319,   204,   759,   205,
     206,   207,   208,   209,   210,   211,   212,     0,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,     0,
     224,     0,     0,     0,   225,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,     0,     0,   233,
     234,   235,     0,   236,   237,   238,     0,     0,   239,   240,
       0,   241,     0,   242,   243,   244,   245,     0,   246,   247,
       0,   248,     0,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   202,     0,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
      47,    48,    49,     0,   203,    59,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   139,
     140,   141,   142,   143,   858,     0,     0,     0,     0,   204,
       0,   205,   206,   207,   208,   209,   210,   211,   212,   144,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   879,   224,   880,     0,     0,   225,   226,   227,   228,
     229,   230,   231,   232,   139,   140,   141,   142,   143,     0,
       0,   233,   234,   235,   561,   236,   237,   238,     0,     0,
     239,   240,     0,   241,   144,   242,   243,   244,   245,     0,
     246,   247,     0,   248,     0,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,    47,    48,    49,     0,     0,    59,    60,     0,
       0,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,    47,    48,    49,   160,
     161,    59,    60,     0,   162,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,    47,    48,    49,   160,   161,    59,    60,   316,   162,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   317,
     318,     0,   319,   204,     0,   205,   206,   207,   208,   209,
     210,   211,   212,     0,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,     0,   224,     0,     0,     0,
     225,   226,   227,   228,   229,   230,   231,   232,     0,     0,
       0,     0,     0,     0,     0,   233,   234,   235,     0,   236,
     237,   238,     0,     0,   239,   240,     0,   241,     0,   242,
     243,   244,   245,     0,   246,   247,     0,   248,     0,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   203,     0,
       0,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,    47,    48,    49,     0,
       0,    59,    60,   204,     0,   205,   206,   207,   208,   209,
     210,   211,   212,     0,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,     0,   224,     0,     0,     0,
     225,   226,   227,   228,   229,   230,   231,   232,     0,     0,
       0,     0,     0,     0,     0,   233,   234,   235,     0,   236,
     237,   238,     0,     0,   239,   240,     0,   241,     0,   242,
     243,   244,   245,     0,   246,   247,     0,   248,     0,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   316,     0,
       0,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,    47,    48,    49,     0,
       0,    59,    60,   204,     0,   205,   206,   207,   208,   209,
     210,   211,   212,     0,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,     0,   224,     0,     0,     0,
     225,   226,   227,   228,   229,   230,   231,   232,     0,     0,
       0,     0,     0,     0,     0,   233,   234,   235,     0,   236,
     237,   238,     0,     0,   239,   240,     0,   241,     0,   242,
     243,   244,   245,     0,   246,   247,     0,   248,     0,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   886,   533,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   563,     0,
       0,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,    47,    48,    49,     0,
       0,    59,    60,   204,   533,   205,   206,   207,   208,   209,
     210,   211,   212,     0,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,     0,   224,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   232,     0,     0,
       0,     0,     0,     0,   533,   233,   234,   235,     0,   236,
     237,   238,     0,     0,   239,   240,     0,   241,     0,   242,
     243,   244,   245,     0,   246,   247,     0,   248,   533,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,     0,   535,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,    47,    48,    49,   534,     0,    59,    60,     0,     0,
       0,     0,     0,     0,     0,   545,    47,    48,    49,     0,
       0,    59,    60,     0,   535,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
      47,    48,    49,     0,     0,    59,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   535,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
      47,    48,    49,     0,     0,    59,    60,   316,   535,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,    47,    48,    49,     0,     0,    59,
      60,     0,   204,     0,   205,   206,   207,   208,   209,   210,
     211,   212,     0,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,     0,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   232,     0,     0,     0,
       0,     0,     0,     0,   233,   234,   235,     0,   236,   237,
     238,     0,     0,   239,   240,     0,   241,     0,   242,   243,
     244,   245,     0,   246,   247,     0,   248,     0,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    47,    48,    49
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        12,   212,    17,    14,    15,    17,   101,    19,   104,    20,
      21,   293,   413,    24,   281,   581,   101,   121,    37,   121,
     224,    40,   442,    19,    23,   186,   122,   297,    36,    43,
      69,    40,   801,   810,    73,    23,     8,   304,    10,    11,
      40,    13,     6,   102,   688,    39,    61,    40,    43,    61,
     121,    17,    87,   291,    22,    22,   700,   365,    62,    22,
     298,    40,    19,   101,    54,     3,     4,    19,    37,    36,
     847,    50,    39,   873,   285,    79,    39,    36,    40,    36,
      92,    17,    18,   121,     6,     7,     0,   183,    50,   101,
     149,   399,   400,   105,    36,    61,   178,    36,   102,    89,
      14,   113,    64,    48,    61,   905,    40,   102,    30,   121,
      40,    63,   106,    81,    82,    37,    50,    41,   183,   184,
      50,   100,    44,    45,    48,    47,    37,    14,   339,   290,
      64,   103,    50,   777,    64,   101,     0,    48,   100,   153,
     104,    50,   114,   115,   101,   546,   118,   751,   120,   569,
     185,    12,   921,   757,    16,   121,   128,   196,   130,   198,
     102,   200,   266,   102,   266,   435,   100,   186,   945,    31,
      32,    33,    34,    35,   186,   183,   184,   186,    40,   178,
     179,   180,   178,   179,   180,   101,   186,   183,   184,    51,
     178,   179,   180,   186,   161,   266,   165,    55,   293,   178,
     179,   180,   161,   125,    36,   121,    36,   149,   293,   151,
     149,   153,   151,    50,   153,   310,   178,   179,   180,   161,
     165,   183,   184,    30,   146,   310,    41,    16,   266,     9,
       6,    37,   798,    48,    40,   201,   178,   179,   180,   178,
     179,   180,    28,    29,   178,   179,   180,    23,   178,   179,
     180,   178,   179,   180,   266,   293,   183,   184,    15,   297,
     178,   179,   180,   100,     6,   183,   184,   471,   688,   178,
     179,   180,   310,     4,   286,   152,   153,   559,   290,   291,
     700,   293,   605,   606,   296,   297,   298,   299,    49,   147,
     148,   174,   175,   176,   177,   179,    61,    62,   310,    37,
     266,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   110,   186,   291,   110,   293,   104,   105,
     296,   297,   298,    37,   735,   101,   110,   441,   442,   441,
      55,   178,   179,   180,   310,   178,   179,   180,   611,   612,
     266,    43,   317,   318,   319,   121,    40,   777,    90,   779,
      74,     8,    40,    10,    11,    40,    13,   768,    40,    16,
      40,    40,   410,    20,    21,   413,    40,   293,    40,    40,
      40,   297,    40,    40,    40,    40,    40,   425,    40,    40,
     356,    38,    40,   405,   310,    40,    40,   435,   410,   603,
      40,   413,    40,   168,   169,   170,   171,   172,   173,   186,
      40,   186,    40,   425,   186,    40,   186,     6,    40,   820,
      40,    40,    40,   435,    40,    40,    40,    40,    40,   441,
     442,    40,    55,    56,    57,    58,    59,    60,    40,    40,
      40,   842,    65,    66,   410,    40,    40,   413,   464,   465,
     466,   467,   468,   469,    40,    40,   103,    40,    40,   425,
     564,    40,   564,    40,   559,   569,    40,   114,   115,   435,
      40,   118,    25,   120,   559,   441,    17,   178,   102,    89,
      91,   128,   153,   130,    52,    43,   581,     6,    24,    37,
      53,   702,    43,   459,   410,    41,   581,   413,   536,    41,
     266,    66,    54,    41,    41,    48,    41,   153,   546,   425,
     911,   912,   913,    41,    48,    48,    41,    48,    41,   435,
      41,   559,    48,    41,   536,    41,    41,   293,    41,   102,
      41,   297,    41,   165,   546,    41,    48,    41,    48,    41,
      48,    41,    41,   581,   310,   560,    41,   559,   560,    41,
      48,    41,   564,    41,    48,    41,    41,   569,    41,    48,
      41,    41,    41,    41,    41,    41,    48,    41,    41,   581,
     536,    25,   584,   585,    41,    41,    29,    49,    48,    28,
     546,   165,   793,    40,   688,    48,   853,    48,   799,    41,
      41,    41,    39,   559,   560,    41,   700,    41,   564,    41,
      41,    49,    41,    41,    36,    41,    40,    63,    41,   891,
      41,   102,    41,    75,    41,   581,    41,    41,   584,   585,
     536,    89,    48,    46,    37,   165,    37,    55,    49,    41,
     546,   102,    37,   892,   416,   550,   123,   765,   536,   552,
     419,   768,   546,   559,   410,   578,   857,   413,   685,   266,
     569,   777,   564,   694,   580,    55,    25,   693,   123,   425,
     705,    71,    84,   761,   338,   581,   771,   584,   769,   435,
     923,   718,   869,   777,   595,   721,   688,   871,   607,   757,
     474,   474,   908,   593,    -1,    -1,    -1,    -1,   700,    -1,
      -1,    -1,    -1,    -1,   790,    -1,    -1,   735,    -1,    -1,
      -1,    -1,    -1,   798,    -1,   916,   718,    -1,   720,   721,
      -1,    -1,    -1,   798,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   688,   735,   935,    -1,   937,   765,    -1,    -1,
     768,    -1,    -1,   771,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   765,    -1,    -1,   768,   769,    -1,   771,
     798,    -1,    -1,    -1,    -1,   777,    -1,    -1,    -1,   735,
     536,    -1,   810,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     546,    -1,   820,    -1,    -1,    -1,   798,    -1,    -1,   801,
      -1,   803,    -1,   559,    -1,    -1,   891,    -1,   810,   765,
      -1,    -1,   768,   769,   842,   771,   891,    -1,   820,   847,
      -1,   777,    -1,    -1,    -1,   581,    -1,    -1,    -1,   735,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     842,    -1,   798,    -1,    -1,   847,    -1,    -1,    -1,   854,
      -1,    -1,   854,    -1,   810,    -1,    -1,    -1,    -1,   765,
      -1,    -1,   768,   891,   820,   771,    -1,   869,    -1,   871,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   911,   912,   913,   842,    -1,    -1,   891,
      -1,   847,   798,   894,    -1,    -1,    -1,    -1,   854,    -1,
      -1,    -1,    -1,    -1,   810,    -1,    -1,    -1,    -1,   911,
     912,   913,   917,    -1,   820,   917,    -1,   945,    -1,   921,
      -1,   923,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   891,   842,    -1,    -1,    -1,
     896,   847,    -1,   945,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   911,   912,   913,    -1,    -1,
      -1,   917,    -1,    -1,    -1,    -1,    -1,   923,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   735,
      -1,    -1,    -1,    -1,    -1,   891,    -1,    -1,    -1,   945,
      -1,    -1,    -1,    -1,    -1,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   911,   912,   913,    -1,   765,
      -1,    -1,   768,    -1,    -1,   771,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    -1,    -1,    -1,   316,    40,    -1,    -1,    -1,   945,
      -1,    -1,   798,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   810,    -1,    -1,    -1,   340,   341,
     342,    -1,    -1,   345,   820,    -1,   348,   349,   350,    -1,
     352,   353,   354,   355,    -1,   357,   358,   359,   360,   361,
     362,    -1,    -1,    -1,   366,    -1,   842,   369,   370,   371,
     372,   847,   374,    -1,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   891,    -1,   183,   184,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   911,   912,   913,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
      -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   945,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    -1,    -1,    -1,    -1,    -1,   498,   499,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   528,   529,    65,    -1,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   563,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     107,   108,   109,    -1,   111,   112,   113,    -1,    -1,   116,
     117,    -1,   119,    -1,   121,   122,   123,   124,    -1,   126,
     127,    -1,   129,    -1,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,    -1,
      -1,    19,    -1,    -1,    -1,    -1,   618,   619,   620,    -1,
      -1,   623,    -1,    -1,   626,    -1,    -1,    -1,    -1,   631,
      -1,    -1,    40,    -1,    -1,    -1,   638,   639,    -1,    -1,
      -1,   178,   179,   180,   646,    -1,   183,   184,   650,    -1,
      -1,    -1,   654,    61,    62,    -1,    64,    65,   660,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,    -1,   111,   112,   113,    -1,    -1,   116,   117,
      -1,   119,    -1,   121,   122,   123,   124,    -1,   126,   127,
      -1,   129,    -1,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,    -1,    40,   183,   184,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,   796,    -1,    -1,    -1,    -1,    65,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    51,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,   823,    88,   825,    -1,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,    31,    32,    33,    34,    35,    -1,
      -1,   107,   108,   109,    41,   111,   112,   113,    -1,    -1,
     116,   117,    -1,   119,    51,   121,   122,   123,   124,    -1,
     126,   127,    -1,   129,    -1,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,    -1,    -1,   183,   184,    -1,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,    -1,   186,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,    40,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    -1,    64,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,   111,
     112,   113,    -1,    -1,   116,   117,    -1,   119,    -1,   121,
     122,   123,   124,    -1,   126,   127,    -1,   129,    -1,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,    -1,
      -1,   183,   184,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,   111,
     112,   113,    -1,    -1,   116,   117,    -1,   119,    -1,   121,
     122,   123,   124,    -1,   126,   127,    -1,   129,    -1,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,    -1,
      -1,   183,   184,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,   111,
     112,   113,    -1,    -1,   116,   117,    -1,   119,    -1,   121,
     122,   123,   124,    -1,   126,   127,    -1,   129,    -1,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,    -1,
      -1,   183,   184,    65,    42,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    42,   107,   108,   109,    -1,   111,
     112,   113,    -1,    -1,   116,   117,    -1,   119,    -1,   121,
     122,   123,   124,    -1,   126,   127,    -1,   129,    42,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   102,    -1,   183,   184,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   153,   178,   179,   180,    -1,
      -1,   183,   184,    -1,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,    -1,    -1,   183,   184,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,    -1,    -1,   183,   184,    40,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    -1,    -1,   183,
     184,    -1,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,    -1,   111,   112,
     113,    -1,    -1,   116,   117,    -1,   119,    -1,   121,   122,
     123,   124,    -1,   126,   127,    -1,   129,    -1,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   178,   179,   180
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    14,   188,   189,   190,   193,   194,   230,   294,   295,
     178,     0,     8,    10,    11,    13,    20,    21,    38,   103,
     114,   115,   118,   120,   128,   130,   191,   234,   235,   250,
     252,   256,   300,   301,   304,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   195,   178,   179,   180,
     502,   503,    12,   305,   305,   305,    36,   328,    19,   183,
     184,   253,   254,   451,   452,   502,   236,   502,   305,   305,
     328,    36,   329,   305,   329,    30,   192,   286,    16,   241,
     296,     3,     4,   318,   320,   321,    15,   196,   231,     9,
     302,   303,     6,    23,   104,   105,   326,   327,   326,   327,
     330,   331,   251,   451,   236,    22,    39,   257,   262,   263,
       6,   104,   324,   325,   324,   330,   324,   287,    17,    18,
     242,   243,   236,    49,   298,   299,   328,   328,   319,   317,
     321,   232,   161,   197,   199,   200,   326,   502,    37,    31,
      32,    33,    34,    35,    51,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     181,   182,   186,   332,   340,   386,   442,   443,   445,   446,
     447,   450,   452,   453,   492,   496,   497,   498,   499,   500,
     501,   502,   504,   236,   255,   262,    23,   258,   259,   260,
     261,   502,    36,   161,   343,   345,   110,   502,   110,    37,
     110,   288,    19,    40,    65,    67,    68,    69,    70,    71,
      72,    73,    74,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    88,    92,    93,    94,    95,    96,
      97,    98,    99,   107,   108,   109,   111,   112,   113,   116,
     117,   119,   121,   122,   123,   124,   126,   127,   129,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   246,   247,   248,   249,   378,   452,
     477,   479,   481,   482,   483,   484,   487,   492,   496,   500,
     502,   262,   193,   295,   297,    39,   106,   322,   179,    55,
     198,   444,   335,    43,   341,   342,   388,    40,   387,    87,
     185,   493,   494,   495,   262,    90,   264,   265,   269,   261,
     346,   324,   324,   324,    36,   452,    40,    61,    62,    64,
     452,   454,   455,   458,   461,   462,   465,   466,   472,   474,
     475,   476,   477,   484,   490,   492,   496,   500,   502,    74,
      40,    40,    40,   186,   478,    40,   186,   384,    40,    40,
      40,   343,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,   384,    40,    40,    40,   186,   186,    40,
      40,    40,    40,   186,    40,   186,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,   247,    40,
      40,   186,   379,   264,   343,    23,   323,   502,   233,    36,
     102,   149,   151,   153,   201,   202,   204,   205,   212,   214,
     215,   222,   261,    50,   389,   400,   451,   334,   336,   337,
     332,   389,   394,   395,   442,   448,   449,   450,   389,   502,
     264,    25,    91,   266,   272,   237,   238,   344,   347,   348,
     351,   401,   442,   450,   292,   454,   475,   475,   475,    89,
     244,   245,   457,   460,    55,    56,    57,    58,    59,    60,
      65,    66,   463,   464,   471,   473,   379,   491,   343,   454,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   454,
     452,   454,   454,   454,   454,   454,   454,    17,   381,   381,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   454,   454,   381,   381,
     502,   178,   223,    42,   102,   162,   206,   207,   210,   293,
     452,   492,   496,   500,   502,   153,   216,   217,   220,   293,
     205,   203,   215,   213,    52,   396,   399,   449,    43,   333,
       6,    41,   449,    40,   270,   271,   378,   452,   477,   273,
     274,   377,   378,   476,   477,    24,   267,   275,   239,    37,
     350,    43,   352,   353,   403,   402,    37,    40,   186,   290,
      41,   452,    41,    53,   456,    54,   459,   465,   465,   465,
     465,   465,   465,    66,   384,    61,    62,   467,   470,   498,
     499,    19,    63,   468,    41,    41,    41,   385,    48,    48,
      48,    41,    41,    48,    41,    41,    48,    41,    41,    41,
      41,    48,    19,   454,   486,   454,    41,    41,    48,    48,
      41,    41,    41,    41,    41,    41,    48,    41,    41,    41,
      48,    41,    41,    41,    48,    41,    41,    41,    41,    41,
      48,    41,    41,    41,   454,   454,    37,    40,   224,   210,
     102,   220,   153,   203,    43,   102,   208,   213,    43,   153,
     218,   393,   398,   332,   451,   454,   271,   274,    25,    28,
      29,   268,   281,   284,   285,   241,     6,     7,    44,    45,
      47,   125,   146,   286,   349,   354,   355,   356,   358,   362,
     366,   367,   370,   371,   376,   348,   395,   412,    40,    50,
      64,   100,   404,   406,   413,   414,   415,   416,   419,   422,
     424,   430,   431,   452,   502,   291,   458,   461,   384,   472,
     472,   468,   469,   474,   474,   383,   454,   454,   454,   454,
     454,   454,    41,   485,   454,   454,   454,   454,   454,   454,
      41,   380,   225,   149,   211,   209,   152,   221,   219,    49,
     392,    48,   397,   338,   245,    26,    27,   276,   277,   278,
     279,   280,   377,   452,   165,   165,   282,   285,   283,   284,
     240,   359,   363,   357,   368,   377,    40,   343,   333,   372,
     415,    40,    50,   100,   432,   437,   438,   440,   502,   422,
     405,   418,   421,    19,    36,    61,   101,   423,   425,   429,
     289,   293,    41,    48,   382,    48,    41,    41,    41,    41,
     382,   480,    49,   488,   489,    41,    41,    41,   480,    41,
      41,   383,   228,   207,   217,   390,   391,   400,   399,    36,
      41,   277,   476,   262,   360,   364,   343,   369,   454,   348,
     343,    41,   435,   436,   438,    50,   439,   502,   396,   102,
     417,    63,   420,    48,   165,   428,   441,    41,   293,   454,
     454,    41,    75,    41,    41,    41,    41,   227,   229,   293,
     396,   339,   264,   451,   365,   343,    89,   375,    41,   434,
     411,   419,   424,   441,    37,    48,   427,    41,    55,    48,
     226,    55,   147,   148,   332,   192,   361,   305,   452,    46,
     373,   102,   433,    49,   410,    37,    37,   426,   441,   501,
     293,   293,   293,    37,   343,   451,    41,   374,   438,   406,
     407,   409,    37,   343,   343,   408,   396
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
     192,   192,   193,   194,   194,   195,   195,   196,   196,   198,
     197,   199,   200,   200,   201,   201,   201,   201,   202,   202,
     203,   203,   204,   205,   206,   206,   207,   207,   209,   208,
     210,   211,   212,   212,   213,   213,   214,   215,   216,   216,
     217,   217,   219,   218,   220,   221,   222,   223,   223,   225,
     224,   226,   226,   227,   228,   228,   229,   229,   229,   230,
     232,   233,   231,   235,   234,   236,   236,   238,   239,   240,
     237,   241,   242,   242,   243,   243,   244,   245,   245,   246,
     247,   247,   247,   247,   247,   247,   247,   247,   248,   248,
     249,   249,   251,   250,   252,   253,   253,   254,   254,   255,
     255,   256,   257,   258,   258,   259,   260,   261,   262,   263,
     263,   264,   265,   265,   266,   266,   267,   267,   268,   268,
     269,   270,   270,   271,   271,   271,   271,   272,   273,   273,
     274,   275,   276,   276,   277,   277,   278,   278,   279,   280,
     280,   281,   281,   282,   282,   283,   283,   284,   285,   287,
     286,   288,   288,   289,   289,   291,   290,   290,   292,   292,
     293,   293,   293,   293,   293,   293,   293,   294,   296,   295,
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
     395,   396,   397,   398,   398,   399,   400,   400,   402,   401,
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
     477,   477,   477,   478,   478,   479,   480,   480,   481,   482,
     483,   484,   484,   485,   484,   486,   486,   487,   487,   487,
     487,   487,   488,   489,   489,   490,   491,   491,   492,   493,
     494,   494,   495,   495,   496,   496,   496,   497,   497,   497,
     498,   498,   498,   499,   499,   499,   500,   500,   501,   501,
     501,   501,   502,   502,   503,   503,   504,   504
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SPARQLfedParser::yyr2_[] =
  {
         0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       0,     1,     3,     0,     1,     0,     2,     0,     2,     0,
       3,     2,     0,     1,     1,     1,     1,     1,     4,     3,
       0,     2,     1,     2,     1,     2,     1,     1,     0,     3,
       2,     1,     4,     3,     0,     2,     1,     2,     1,     2,
       1,     1,     0,     3,     2,     1,     3,     0,     2,     0,
       4,     0,     1,     2,     0,     2,     3,     3,     3,     2,
       0,     0,     5,     0,     5,     0,     2,     0,     0,     0,
       7,     3,     1,     1,     0,     1,     2,     0,     1,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     0,     6,     5,     1,     2,     1,     1,     0,
       1,     3,     2,     1,     1,     1,     2,     1,     2,     0,
       1,     4,     0,     1,     0,     1,     0,     1,     0,     1,
       3,     1,     2,     1,     1,     4,     1,     2,     1,     2,
       1,     3,     1,     2,     1,     1,     1,     1,     2,     1,
       1,     2,     2,     0,     1,     0,     1,     2,     2,     0,
       6,     0,     2,     1,     2,     0,     4,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     4,
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
       1,     2,     2,     0,     2,     1,     1,     1,     0,     3,
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
       1,     1,     1,     3,     1,     7,     0,     1,     7,     2,
       3,     5,     5,     0,     7,     1,     1,     1,     1,     1,
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
  "IRI_REF", "PNAME_NS", "PNAME_LN", "BLANK_NODE_LABEL", "ANON", "VAR1",
  "VAR2", "LANGTAG", "NIL", "$accept", "Top", "QueryUnit", "Query",
  "_O_QSelectQuery_E_Or_QConstructQuery_E_Or_QDescribeQuery_E_Or_QAskQuery_E_C",
  "_QBindingsClause_E_Opt", "Prologue", "_QBaseDecl_E_Opt",
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
  "ConstructQuery", "$@11", "DescribeQuery", "_QVarOrIRIref_E_Plus",
  "_O_QVarOrIRIref_E_Plus_Or_QGT_TIMES_E_C", "_QWhereClause_E_Opt",
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
  "OffsetClause", "BindingsClause", "$@12", "_QVar_E_Star",
  "_QBindingValue_E_Plus",
  "_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C",
  "$@13",
  "_Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star",
  "BindingValue", "UpdateUnit", "Update", "$@14", "_QUpdate_E_Opt",
  "_O_QGT_SEMI_E_S_QUpdate_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QUpdate_E_Opt_C_E_Opt", "Update1", "Load",
  "_O_QIT_INTO_E_S_QGraphRef_E_C", "_Q_O_QIT_INTO_E_S_QGraphRef_E_C_E_Opt",
  "Clear", "_QIT_SILENT_E_Opt", "Drop", "Create", "Add", "Move", "Copy",
  "InsertData", "DeleteData", "DeleteWhere", "Modify",
  "_O_QIT_WITH_E_S_QIRIref_E_C", "_Q_O_QIT_WITH_E_S_QIRIref_E_C_E_Opt",
  "_QInsertClause_E_Opt",
  "_O_QDeleteClause_E_S_QInsertClause_E_Opt_Or_QInsertClause_E_C",
  "_QUsingClause_E_Star", "DeleteClause", "InsertClause", "UsingClause",
  "_O_QIRIref_E_Or_QIT_NAMED_E_S_QIRIref_E_C", "GraphOrDefault",
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
  "_QPropertyListNotEmpty_E_Opt", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "Verb", "TriplesSameSubjectPath", "$@36", "$@37",
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
  "_O_QIRIref_E_Or_QIT_a_E_Or_QGT_NOT_E_S_QPathNegatedPropertySet_E_Or_QGT_LPAREN_E_S_QPath_E_S_QGT_RPAREN_E_C",
  "PathNegatedPropertySet", "_O_QGT_PIPE_E_S_QPathOneInPropertySet_E_C",
  "_Q_O_QGT_PIPE_E_S_QPathOneInPropertySet_E_C_E_Star",
  "_O_QPathOneInPropertySet_E_S_QGT_PIPE_E_S_QPathOneInPropertySet_E_Star_C",
  "_Q_O_QPathOneInPropertySet_E_S_QGT_PIPE_E_S_QPathOneInPropertySet_E_Star_C_E_Opt",
  "_O_QPathOneInPropertySet_E_Or_QGT_LPAREN_E_S_QPathOneInPropertySet_E_S_QGT_PIPE_E_S_QPathOneInPropertySet_E_Star_Opt_S_QGT_RPAREN_E_C",
  "PathOneInPropertySet", "_O_QIRIref_E_Or_QIT_a_E_C",
  "_O_QIRIref_E_Or_QIT_a_E_Or_QGT_CARROT_E_S_QIRIref_E_Or_QIT_a_E_C",
  "Integer", "TriplesNode", "BlankNodePropertyList", "@40", "Generator",
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
  "SubstringExpression", "ExistsFunc", "NotExistsFunc", "Aggregate", "@41",
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
  const SPARQLfedParser::rhs_number_type
  SPARQLfedParser::yyrhs_[] =
  {
       188,     0,    -1,   189,    -1,   294,    -1,   190,    -1,   193,
     191,   192,    -1,   234,    -1,   250,    -1,   252,    -1,   256,
      -1,    -1,   286,    -1,   194,   195,   196,    -1,    -1,   230,
      -1,    -1,   195,   231,    -1,    -1,   196,   197,    -1,    -1,
     200,   198,   201,    -1,   161,    55,    -1,    -1,   199,    -1,
     202,    -1,   212,    -1,   222,    -1,   261,    -1,   204,   205,
     203,   211,    -1,   205,   203,    43,    -1,    -1,   203,   208,
      -1,   149,    -1,   102,   207,    -1,   210,    -1,   206,   210,
      -1,   102,    -1,   206,    -1,    -1,   102,   209,   207,    -1,
     293,   102,    -1,   149,    -1,   214,   215,   213,   221,    -1,
     215,   213,    43,    -1,    -1,   213,   218,    -1,   151,    -1,
     153,   217,    -1,   220,    -1,   216,   220,    -1,   153,    -1,
     216,    -1,    -1,   153,   219,   217,    -1,   293,   153,    -1,
     152,    -1,    36,   223,    37,    -1,    -1,   223,   224,    -1,
      -1,    40,   225,   228,    41,    -1,    -1,    48,    -1,   229,
     226,    -1,    -1,   228,   227,    -1,   293,   148,   293,    -1,
     293,   147,   293,    -1,   293,    55,   293,    -1,    14,   178,
      -1,    -1,    -1,    15,   232,   179,   233,   178,    -1,    -1,
     235,   241,   236,   262,   264,    -1,    -1,   236,   257,    -1,
      -1,    -1,    -1,   238,   239,   241,   240,   262,   264,   192,
      -1,    16,   243,   249,    -1,    17,    -1,    18,    -1,    -1,
     242,    -1,    89,   452,    -1,    -1,   244,    -1,    40,   454,
     245,    41,    -1,   452,    -1,   484,    -1,   477,    -1,   378,
      -1,   492,    -1,   496,    -1,   500,    -1,   246,    -1,   247,
      -1,   248,   247,    -1,   248,    -1,    19,    -1,    -1,    20,
     328,   251,   236,   262,   264,    -1,    21,   254,   236,   255,
     264,    -1,   451,    -1,   253,   451,    -1,   253,    -1,    19,
      -1,    -1,   262,    -1,    38,   236,   262,    -1,    22,   258,
      -1,   259,    -1,   260,    -1,   261,    -1,    23,   261,    -1,
     502,    -1,   263,   343,    -1,    -1,    39,    -1,   265,   266,
     267,   268,    -1,    -1,   269,    -1,    -1,   272,    -1,    -1,
     275,    -1,    -1,   281,    -1,    90,    25,   270,    -1,   271,
      -1,   270,   271,    -1,   477,    -1,   378,    -1,    40,   454,
     245,    41,    -1,   452,    -1,    91,   273,    -1,   274,    -1,
     273,   274,    -1,   377,    -1,    24,    25,   276,    -1,   277,
      -1,   276,   277,    -1,   279,    -1,   280,    -1,    26,    -1,
      27,    -1,   278,   476,    -1,   377,    -1,   452,    -1,   284,
     282,    -1,   285,   283,    -1,    -1,   285,    -1,    -1,   284,
      -1,    28,   165,    -1,    29,   165,    -1,    -1,    30,   287,
     288,    36,   292,    37,    -1,    -1,   288,   452,    -1,   293,
      -1,   289,   293,    -1,    -1,    40,   291,   289,    41,    -1,
     186,    -1,    -1,   292,   290,    -1,   502,    -1,   492,    -1,
     496,    -1,   500,    -1,    42,    -1,   162,    -1,   452,    -1,
     295,    -1,    -1,   193,   300,   296,   299,    -1,    -1,   295,
      -1,    49,   297,    -1,    -1,   298,    -1,   301,    -1,   304,
      -1,   306,    -1,   308,    -1,   309,    -1,   310,    -1,   307,
      -1,   311,    -1,   312,    -1,   313,    -1,   314,    -1,     8,
     502,   303,    -1,     9,   326,    -1,    -1,   302,    -1,    10,
     305,   327,    -1,    -1,    12,    -1,    13,   305,   327,    -1,
      11,   305,   326,    -1,   114,   305,   324,   110,   324,    -1,
     128,   305,   324,   110,   324,    -1,   115,   305,   324,   110,
     324,    -1,   130,   329,    -1,   120,   329,    -1,   118,   328,
      -1,   316,   318,   319,    39,   343,    -1,   103,   502,    -1,
      -1,   315,    -1,    -1,   321,    -1,   320,   317,    -1,   321,
      -1,    -1,   319,   322,    -1,     3,   328,    -1,     4,   328,
      -1,   106,   323,    -1,   502,    -1,    23,   502,    -1,   104,
      -1,   325,   502,    -1,    -1,     6,    -1,     6,   502,    -1,
     326,    -1,   104,    -1,    23,    -1,   105,    -1,    36,   330,
      37,    -1,    36,   330,    37,    -1,    -1,   331,   332,   335,
      -1,    -1,   340,    -1,    -1,    43,    -1,   336,   333,   332,
      -1,    -1,   335,   334,    -1,    -1,    -1,    -1,   337,     6,
     451,   338,    36,   339,   332,    37,    -1,   386,   342,    -1,
      43,   332,    -1,    -1,   341,    -1,   345,    -1,   161,    -1,
     237,    -1,   347,    -1,    -1,    36,   346,   344,    37,    -1,
     348,   350,    -1,    -1,   351,    -1,   354,   333,   348,    -1,
      -1,   350,   349,    -1,   401,   353,    -1,    43,   348,    -1,
      -1,   352,    -1,   370,    -1,   356,    -1,   367,    -1,   358,
      -1,   362,    -1,   376,    -1,   366,    -1,   286,    -1,   355,
      -1,   146,   343,    -1,    -1,    44,   357,   343,    -1,    -1,
      -1,    -1,     6,   359,   360,   451,   361,   343,    -1,    -1,
      -1,    -1,     7,   363,   364,   365,   305,   451,   343,    -1,
     125,    40,   454,    89,   452,    41,    -1,    -1,    -1,    45,
     368,   369,   343,    -1,    -1,    -1,   371,   372,   343,   375,
      -1,    -1,    46,   374,   343,    -1,    -1,   375,   373,    -1,
      47,   377,    -1,   476,    -1,   477,    -1,   378,    -1,   502,
     379,    -1,   186,    -1,    -1,    40,   381,   454,   380,   383,
      41,    -1,    -1,    17,    -1,    48,   454,    -1,    -1,   383,
     382,    -1,   186,    -1,    -1,    40,   454,   385,   383,    41,
      -1,    -1,   450,   387,   389,    -1,    -1,   442,   388,   394,
      -1,   400,   396,   393,    -1,   400,   396,    -1,    -1,   390,
      -1,    49,   391,    -1,    -1,   393,   392,    -1,   395,    -1,
      -1,   389,    -1,   399,   398,    -1,    48,   399,    -1,    -1,
     398,   397,    -1,   449,    -1,   451,    -1,    50,    -1,    -1,
     450,   402,   404,    -1,    -1,   442,   403,   412,    -1,    -1,
     406,   405,   396,   411,    -1,   413,    -1,   414,    -1,    -1,
     406,   408,   396,    -1,    -1,   407,    -1,    49,   409,    -1,
      -1,   411,   410,    -1,   395,    -1,   415,    -1,   452,    -1,
     416,    -1,   419,   418,    -1,   102,   419,    -1,    -1,   418,
     417,    -1,   424,   421,    -1,    63,   424,    -1,    -1,   421,
     420,    -1,   430,   423,    -1,    -1,   425,    -1,   422,    -1,
     100,   422,    -1,   429,    -1,    37,    -1,   441,    37,    -1,
      48,   426,    -1,    37,    -1,   441,   427,    -1,    48,   441,
      37,    -1,    19,    -1,   101,    -1,    61,    -1,    36,   428,
      -1,   431,    -1,   502,    -1,    50,    -1,    64,   432,    -1,
      40,   415,    41,    -1,   437,    -1,   102,   438,    -1,    -1,
     434,   433,    -1,   438,   434,    -1,    -1,   435,    -1,   438,
      -1,    40,   436,    41,    -1,   440,    -1,   502,    -1,    50,
      -1,   502,    -1,    50,    -1,   100,   439,    -1,   165,    -1,
     445,    -1,   443,    -1,    -1,    51,   444,   389,    52,    -1,
     447,    40,   448,    41,    -1,    31,    -1,    32,    -1,    33,
      -1,    34,    -1,    35,    -1,    -1,   446,    -1,   449,    -1,
     448,   449,    -1,   450,    -1,   442,    -1,   452,    -1,   453,
      -1,   452,    -1,   502,    -1,   183,    -1,   184,    -1,   502,
      -1,   492,    -1,   496,    -1,   500,    -1,   504,    -1,   186,
      -1,   455,    -1,   458,   457,    -1,    53,   458,    -1,    -1,
     457,   456,    -1,   461,   460,    -1,    54,   461,    -1,    -1,
     460,   459,    -1,   462,    -1,   465,   463,    -1,    -1,   464,
      -1,    55,   465,    -1,    56,   465,    -1,    57,   465,    -1,
      58,   465,    -1,    59,   465,    -1,    60,   465,    -1,    66,
     384,    -1,    65,    66,   384,    -1,   466,    -1,   472,   471,
      -1,   498,    -1,   499,    -1,    19,   474,    -1,    63,   474,
      -1,    -1,   468,    -1,    61,   472,    -1,    62,   472,    -1,
     467,   469,    -1,    -1,   471,   470,    -1,   474,   473,    -1,
      -1,   473,   468,    -1,    64,   475,    -1,    61,   475,    -1,
      62,   475,    -1,   475,    -1,   476,    -1,   477,    -1,   490,
      -1,   492,    -1,   496,    -1,   500,    -1,   452,    -1,   484,
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
     479,    -1,   482,    -1,   483,    -1,    40,   454,    41,    -1,
     186,    -1,    86,    40,   454,    48,   454,   480,    41,    -1,
      -1,   382,    -1,   132,    40,   454,    48,   454,   480,    41,
      -1,    74,   343,    -1,    65,    74,   343,    -1,    92,    40,
     381,   486,    41,    -1,   487,    40,   381,   454,    41,    -1,
      -1,    97,    40,   381,   454,   485,   489,    41,    -1,    19,
      -1,   454,    -1,    93,    -1,    94,    -1,    95,    -1,    96,
      -1,    98,    -1,    49,    75,    55,   501,    -1,    -1,   488,
      -1,   502,   491,    -1,    -1,   379,    -1,   501,   495,    -1,
      87,   502,    -1,   185,    -1,   493,    -1,    -1,   494,    -1,
     497,    -1,   498,    -1,   499,    -1,   165,    -1,   166,    -1,
     167,    -1,   168,    -1,   169,    -1,   170,    -1,   171,    -1,
     172,    -1,   173,    -1,   163,    -1,   164,    -1,   174,    -1,
     176,    -1,   175,    -1,   177,    -1,   178,    -1,   503,    -1,
     180,    -1,   179,    -1,   181,    -1,   182,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SPARQLfedParser::yyprhs_[] =
  {
         0,     0,     3,     5,     7,     9,    13,    15,    17,    19,
      21,    22,    24,    28,    29,    31,    32,    35,    36,    39,
      40,    44,    47,    48,    50,    52,    54,    56,    58,    63,
      67,    68,    71,    73,    76,    78,    81,    83,    85,    86,
      90,    93,    95,   100,   104,   105,   108,   110,   113,   115,
     118,   120,   122,   123,   127,   130,   132,   136,   137,   140,
     141,   146,   147,   149,   152,   153,   156,   160,   164,   168,
     171,   172,   173,   179,   180,   186,   187,   190,   191,   192,
     193,   201,   205,   207,   209,   210,   212,   215,   216,   218,
     223,   225,   227,   229,   231,   233,   235,   237,   239,   241,
     244,   246,   248,   249,   256,   262,   264,   267,   269,   271,
     272,   274,   278,   281,   283,   285,   287,   290,   292,   295,
     296,   298,   303,   304,   306,   307,   309,   310,   312,   313,
     315,   319,   321,   324,   326,   328,   333,   335,   338,   340,
     343,   345,   349,   351,   354,   356,   358,   360,   362,   365,
     367,   369,   372,   375,   376,   378,   379,   381,   384,   387,
     388,   395,   396,   399,   401,   404,   405,   410,   412,   413,
     416,   418,   420,   422,   424,   426,   428,   430,   432,   433,
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
     811,   813,   816,   819,   820,   823,   825,   827,   829,   830,
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
    1454,  1458,  1464,  1470,  1471,  1479,  1481,  1483,  1485,  1487,
    1489,  1491,  1493,  1498,  1499,  1501,  1504,  1505,  1507,  1510,
    1513,  1515,  1517,  1518,  1520,  1522,  1524,  1526,  1528,  1530,
    1532,  1534,  1536,  1538,  1540,  1542,  1544,  1546,  1548,  1550,
    1552,  1554,  1556,  1558,  1560,  1562,  1564,  1566
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   481,   481,   484,   490,   495,   506,   507,   508,   509,
     514,   517,   522,   526,   528,   532,   534,   537,   539,   543,
     543,   561,   567,   570,   574,   575,   576,   577,   583,   584,
     587,   589,   593,   597,   601,   602,   606,   607,   611,   611,
     619,   625,   629,   630,   633,   635,   639,   643,   647,   648,
     652,   653,   657,   657,   665,   671,   675,   678,   680,   684,
     684,   691,   693,   697,   700,   702,   706,   709,   712,   718,
     724,   726,   724,   736,   736,   748,   751,   759,   762,   765,
     759,   780,   788,   791,   798,   801,   806,   813,   816,   821,
     828,   831,   834,   837,   840,   843,   846,   850,   855,   858,
     866,   869,   876,   876,   887,   895,   898,   906,   909,   916,
     919,   924,   932,   939,   940,   944,   950,   956,   963,   970,
     972,   977,   984,   987,   992,   995,  1000,  1003,  1008,  1012,
    1016,  1023,  1026,  1033,  1036,  1039,  1042,  1048,  1054,  1057,
    1064,  1069,  1076,  1080,  1088,  1090,  1098,  1101,  1109,  1117,
    1118,  1125,  1129,  1137,  1140,  1145,  1148,  1152,  1158,  1165,
    1165,  1173,  1175,  1181,  1184,  1190,  1190,  1195,  1201,  1203,
    1207,  1210,  1213,  1216,  1219,  1222,  1225,  1231,  1235,  1235,
    1244,  1246,  1250,  1253,  1255,  1259,  1260,  1261,  1262,  1263,
    1264,  1265,  1266,  1267,  1268,  1269,  1273,  1280,  1287,  1290,
    1294,  1300,  1303,  1309,  1315,  1321,  1327,  1333,  1339,  1347,
    1355,  1362,  1371,  1377,  1380,  1384,  1387,  1391,  1395,  1401,
    1403,  1409,  1415,  1421,  1427,  1430,  1436,  1439,  1444,  1446,
    1450,  1456,  1459,  1462,  1465,  1472,  1478,  1484,  1484,  1492,
    1494,  1498,  1500,  1504,  1507,  1509,  1514,  1519,  1522,  1514,
    1533,  1537,  1540,  1542,  1546,  1547,  1560,  1561,  1566,  1566,
    1577,  1581,  1583,  1593,  1597,  1600,  1616,  1621,  1625,  1628,
    1632,  1633,  1634,  1635,  1636,  1637,  1638,  1639,  1642,  1646,
    1652,  1652,  1668,  1672,  1674,  1668,  1685,  1689,  1691,  1685,
    1702,  1713,  1717,  1713,  1727,  1731,  1727,  1741,  1741,  1753,
    1755,  1759,  1769,  1770,  1771,  1775,  1783,  1787,  1787,  1797,
    1800,  1807,  1813,  1815,  1829,  1832,  1832,  1842,  1842,  1845,
    1845,  1852,  1857,  1861,  1863,  1868,  1872,  1874,  1879,  1883,
    1885,  1890,  1895,  1899,  1901,  1905,  1912,  1916,  1924,  1924,
    1927,  1927,  1933,  1933,  1939,  1940,  1944,  1944,  1949,  1951,
    1955,  1958,  1960,  1964,  1968,  1972,  1978,  1982,  1986,  1989,
    1991,  1995,  1999,  2004,  2006,  2012,  2015,  2017,  2023,  2024,
    2030,  2034,  2035,  2039,  2040,  2044,  2045,  2049,  2050,  2051,
    2052,  2056,  2060,  2063,  2066,  2069,  2075,  2079,  2082,  2084,
    2088,  2091,  2093,  2097,  2098,  2102,  2106,  2107,  2111,  2112,
    2113,  2117,  2122,  2123,  2127,  2127,  2140,  2165,  2168,  2171,
    2174,  2177,  2184,  2187,  2192,  2196,  2203,  2204,  2208,  2211,
    2215,  2218,  2224,  2225,  2229,  2232,  2235,  2238,  2241,  2242,
    2248,  2253,  2262,  2269,  2272,  2280,  2289,  2296,  2299,  2306,
    2311,  2322,  2325,  2329,  2332,  2335,  2338,  2341,  2344,  2347,
    2350,  2356,  2361,  2370,  2373,  2380,  2383,  2390,  2393,  2398,
    2401,  2405,  2419,  2422,  2430,  2439,  2442,  2449,  2452,  2455,
    2458,  2462,  2463,  2464,  2465,  2468,  2471,  2474,  2477,  2481,
    2487,  2490,  2493,  2496,  2499,  2502,  2505,  2509,  2512,  2515,
    2518,  2521,  2524,  2527,  2530,  2531,  2534,  2537,  2540,  2543,
    2546,  2549,  2552,  2555,  2558,  2561,  2564,  2567,  2570,  2573,
    2576,  2579,  2582,  2585,  2588,  2591,  2594,  2597,  2600,  2603,
    2606,  2610,  2613,  2616,  2619,  2622,  2625,  2628,  2631,  2634,
    2637,  2638,  2639,  2645,  2648,  2655,  2662,  2665,  2669,  2675,
    2682,  2689,  2693,  2698,  2698,  2718,  2721,  2725,  2728,  2731,
    2734,  2737,  2743,  2749,  2752,  2756,  2766,  2769,  2774,  2782,
    2789,  2793,  2801,  2805,  2809,  2810,  2811,  2815,  2816,  2817,
    2821,  2822,  2823,  2827,  2828,  2829,  2833,  2834,  2838,  2839,
    2840,  2841,  2845,  2846,  2850,  2851,  2855,  2856
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
  const int SPARQLfedParser::yylast_ = 2407;
  const int SPARQLfedParser::yynnts_ = 318;
  const int SPARQLfedParser::yyempty_ = -2;
  const int SPARQLfedParser::yyfinal_ = 11;
  const int SPARQLfedParser::yyterror_ = 1;
  const int SPARQLfedParser::yyerrcode_ = 256;
  const int SPARQLfedParser::yyntokens_ = 187;

  const unsigned int SPARQLfedParser::yyuser_token_number_max_ = 441;
  const SPARQLfedParser::token_number_type SPARQLfedParser::yyundef_token_ = 2;


} // w3c_sw

/* Line 1136 of lalr1.cc  */
#line 5601 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 2862 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


