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
	  /* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	  (yyval.p_Operation) = new Construct((DefaultGraphPattern*)((yysemantic_stack_[(6) - (2)].p_BasicGraphPattern) ? (yysemantic_stack_[(6) - (2)].p_BasicGraphPattern) : new DefaultGraphPattern()), (yysemantic_stack_[(6) - (4)].p_DatasetClauses), (yysemantic_stack_[(6) - (5)].p_WhereClause), (yysemantic_stack_[(6) - (6)].p_SolutionModifier));
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
	(yyval.p_Operation) = new Insert(driver.ensureGraphPattern(), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1347 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete(driver.ensureGraphPattern(), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1355 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete(driver.ensureGraphPattern(), NULL);
	driver.curOp = NULL;
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1363 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(5) - (1)].p_URI))
	    w3c_sw_NEED_IMPL("WITH <URI> (DELETE INSERT?|INSERT) ...");
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(5) - (2)].p_DeleteInsert).del, (yysemantic_stack_[(5) - (2)].p_DeleteInsert).ins, new WhereClause(driver.ensureGraphPattern()));
	driver.curOp = NULL;
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 1372 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1378 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 1385 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 1392 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 1396 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1404 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("_QUsingClause_E_Star");
    }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 1410 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Delete) = new Delete(driver.ensureGraphPattern(), NULL);
	driver.curOp = NULL;
    }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1417 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = new Insert(driver.ensureGraphPattern(), NULL);
	driver.curOp = NULL;
    }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 1424 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 1430 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 1433 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 1439 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 1442 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 1453 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 1459 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 1462 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("DEFAULT");
      }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 1465 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("NAMED");
      }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 1468 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("ALL");
      }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 1508 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 1513 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 247:

/* Line 690 of lalr1.cc  */
#line 1516 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 1519 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 1541 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 257:

/* Line 690 of lalr1.cc  */
#line 1560 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 1562 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 1633 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_BindingClause)) : (yysemantic_stack_[(1) - (1)].p_BindingClause);
    }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 1640 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Print(driver.curOp);
    }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 1646 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 1650 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 281:

/* Line 690 of lalr1.cc  */
#line 1662 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 1666 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 1668 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 1671 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 1679 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 1683 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 1685 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 1688 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(7) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(7) - (6)].p_TTerm), driver.curOp, (yysemantic_stack_[(7) - (5)].p_Silence), driver.atomFactory, false));
	  driver.curGraphName = (yysemantic_stack_[(7) - (4)].p_TTerm);
      }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 1696 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Bind(driver.ensureGraphPattern(), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
	// no more triples go into the current BGP, per
	//   http://www.w3.org/TR/sparql11-query/#sparqlTranslateGraphPatterns
	// test reference:
	//   http://www.sparql.org/query-validator?query=ASK+{+%3Fs+%3Fp+%3Fo+FILTER+%281%29+BIND+%282+AS+%3Fb%29+%3Fs2+%3Fp2+%3Fo2+FILTER+%283%29+BIND+%284+AS+%3Fd%29}&languageSyntax=SPARQL&outputFormat=algebra&linenumbers=false
	driver.curBGP = NULL;
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 1707 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 1711 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 1713 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 1721 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 1725 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 1727 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 1735 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 1740 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.ensureGraphPattern());
      }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 1753 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    driver.ensureGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 1769 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 1777 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 1781 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 1784 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yysemantic_stack_[(6) - (4)].p_Expressions);
      }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 1791 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 1794 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 1801 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 1809 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 1823 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 1826 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 1829 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(5) - (3)].p_Expressions);
      }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 1837 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 1839 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 1867 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 1870 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 1930 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 1937 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 1941 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 1949 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 1952 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 1958 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 1969 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 1997 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 2024 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 2031 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 2042 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 2049 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 2085 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 2088 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 2091 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 2094 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 2152 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 2156 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 2165 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 414:

/* Line 690 of lalr1.cc  */
#line 2190 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 2193 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 2196 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 2199 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 2202 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 2209 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 2217 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 2221 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 2233 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 2240 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 2243 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 2254 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 2257 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 2260 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 2263 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 2267 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 2278 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 2287 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 2294 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 2297 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 2305 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 2314 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 2321 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 2324 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 2336 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_GeneralComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_GeneralComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_GeneralComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 2347 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 2354 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 2357 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 2360 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 2363 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 2366 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 2369 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 2372 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 2375 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 2386 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 2395 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 2398 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 2405 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 2408 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 2415 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 2423 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 2426 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 2430 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 469:

/* Line 690 of lalr1.cc  */
#line 2444 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 2447 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 2455 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 2464 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 2467 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 2474 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 2477 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 2480 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 2490 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 2493 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 2496 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 2499 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 2506 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 2512 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 2515 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 2518 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 2521 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 2524 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 2527 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 2530 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 2534 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 2537 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 2540 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 2543 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ciel, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 2546 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 2549 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 2552 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 2556 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 2559 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 2562 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 2565 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 2568 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 2571 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 2574 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 2577 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 2580 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 2583 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 2586 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 2589 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 2592 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 2595 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 2598 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 2601 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 2604 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 2607 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 2610 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_uuid, NULL, NULL, NULL));
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 2613 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_struuid, NULL, NULL, NULL));
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 2616 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 2619 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 2622 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 2625 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 2628 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 2631 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 2635 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 2638 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 2641 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 2644 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 2647 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 2650 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 2653 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 2656 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 2659 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 2670 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 2673 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 2680 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 2687 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 2694 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 2700 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.ensureGraphPattern(), NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 2707 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.ensureGraphPattern(), NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 2714 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 2717 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 2721 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 2724 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(7) - (3)].p_distinctness), (yysemantic_stack_[(7) - (4)].p_Expression)));
	  // // x = new ArgList($2, driver.curExprList);
	  // delete driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(7) - (5)].p_Expressions);
	  // w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // // $$ = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group-concat, $3, $4.p_Expression, $4.separator));
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 2735 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
	driver.countStar = true;
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 2743 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 2746 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 2749 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 2752 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 2755 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 2761 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 2767 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 2774 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 2784 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 2792 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 2800 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 2807 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 2811 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 2819 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 690 of lalr1.cc  */
#line 3681 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -837;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        65,   -92,    91,  -837,  -837,   373,  -837,  -837,  -837,  -837,
    -837,  -837,    73,   113,   113,   113,    94,     3,  -837,    73,
     113,   113,   100,   135,   113,   135,   129,  -837,   175,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,   130,   194,  -837,  -837,  -837,
     208,  -837,  -837,   198,   224,   198,  -837,  -837,  -837,  -837,
    -837,   146,  -837,  -837,  -837,  -837,    41,  -837,    38,    38,
     951,  -837,   951,  -837,    38,  -837,  -837,  -837,  -837,   177,
    -837,   191,   100,   100,  -837,   242,  -837,  -837,    59,  -837,
     224,  -837,  -837,    73,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,   951,  -837,  -837,    28,     0,  -837,  -837,  -837,     1,
    -837,  -837,   162,    73,   172,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,   253,
    -837,  -837,   258,  -837,  -837,  -837,  -837,   265,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,   -34,  -837,  -837,
     270,   210,  -837,  -837,  -837,  -837,  1437,    41,    52,  -837,
    -837,  -837,  -837,     4,  -837,  -837,   133,   264,  -837,  -837,
    -837,  -837,  -837,   271,  -837,   291,    41,   249,  -837,    73,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,    38,
    -837,    38,   153,  -837,   336,   951,  -837,  -837,   153,  1672,
     153,    73,  -837,  -837,  -837,  -837,  -837,    38,    -8,  -837,
    1817,   272,   305,   307,    -2,    -1,   310,   312,   315,     1,
     318,   320,   324,   325,   326,   327,   329,   331,   333,   334,
     335,    -1,   337,  -837,  -837,  -837,  -837,   339,  -837,   340,
     184,   190,   350,   351,   355,   356,   201,   357,   213,   360,
     361,   370,   375,   376,   377,   379,   381,   382,   384,   385,
     388,   389,   392,   394,   396,   397,   400,   401,   402,   403,
     406,  -837,  -837,  1937,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,   407,  -837,  -837,  -837,     2,   249,   330,
    -837,  -837,     1,    22,  -837,  -837,  -837,   114,  -837,   951,
    -837,  -837,   249,   424,  -837,   362,  -837,  -837,   987,  -837,
    -837,  -837,   399,  1672,  -837,  -837,   409,   448,  -837,  -837,
    -837,  -837,  -837,  1616,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  1817,  2057,  2057,  2057,  -837,   374,  -837,  -837,  -837,
    -837,   347,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,     2,     1,  1817,  1817,  1817,  -837,  -837,
    1817,  -837,  -837,  1817,  1817,  1817,  -837,  1817,  1817,  1817,
    1817,    72,  1817,  1817,  1817,  1817,  1817,  1817,  -837,   442,
     442,  1817,  -837,  -837,  1817,  1817,  1817,  1817,  -837,  1817,
    -837,  1817,  1817,  1817,  1817,  1817,  1817,  1817,  1817,  1817,
    1817,  1817,  1817,  1817,  1817,  1817,  1817,  1817,  1817,  1817,
    1817,  1817,  1817,  -837,   442,   442,  -837,  -837,  -837,  -837,
      73,  -837,  -837,   284,  -837,  1643,  -837,  -837,  1019,  -837,
    -837,   369,  -837,  -837,   319,  -837,  -837,  -837,  -837,  -837,
    2177,  2265,   449,  -837,  -837,  -837,   438,  -837,  -837,  -837,
     435,  -837,  -837,  -837,  -837,  -837,  -837,  -837,   951,   146,
    -837,  -837,   -13,   440,  -837,  -837,  -837,    72,  -837,   441,
     426,   430,  1817,  1817,  1817,  1817,  1817,  1817,   419,    -1,
    -837,  -837,   145,    43,  -837,  -837,  -837,   445,   457,   458,
    -837,   452,   454,   456,   464,   465,   462,   470,   471,   466,
     474,   476,   477,   478,   472,  -837,  1296,  1817,   480,   481,
     475,   479,   483,   484,   485,   487,   488,   489,   486,   490,
     491,   495,   492,   496,   497,   498,   499,   502,   505,   507,
     509,   510,   508,   512,   514,   516,  1817,  1817,  -837,  -837,
      92,  -837,  -837,  -837,  1045,  -837,  -837,   460,  -837,  -837,
    -837,  -837,  -837,  -837,  1045,  -837,  -837,   405,  -837,     5,
    -837,    14,  1817,  2177,  -837,  -837,  -837,  -837,  2265,  -837,
    -837,  -837,  -837,  -837,   535,   240,  -837,   175,  -837,   236,
     951,  -837,  -837,   153,    35,   515,   517,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  1817,  -837,  1817,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,    -1,  -837,  1817,  1817,
      43,  -837,  -837,  -837,  1817,  1817,  -837,  -837,  -837,  -837,
    -837,  1817,  1817,  1817,  -837,  -837,  1817,  -837,  -837,  1817,
    -837,  -837,  -837,  -837,  1817,  -837,  -837,   522,  -837,  -837,
    -837,  1817,  1817,  -837,  -837,  -837,  -837,  -837,  -837,  1817,
    -837,  -837,  -837,  1817,  -837,  -837,  -837,  1817,  -837,  -837,
    -837,  -837,  -837,  1817,  -837,  -837,  -837,   526,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,   -41,  -837,  -837,  -837,
     123,  -837,  -837,  -837,   374,  -837,  -837,  1557,   404,   408,
    -837,  -837,   461,   540,  -837,  -837,  -837,  -837,  -837,  2265,
     530,     1,  -837,  -837,   409,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,   -10,  -837,    44,
      99,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
     209,  -837,  -837,  -837,   153,  -837,  1672,  -837,   536,  1045,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,    24,
     523,   533,   538,   543,   544,   528,  -837,   537,   546,   547,
     550,   528,   551,   553,  -837,  -837,  -837,  -837,  -837,  1643,
    -837,  -837,  1019,   554,  -837,  -837,  1557,  -837,   556,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,   558,
    -837,  -837,     1,  -837,  -837,  1817,  -837,   951,     1,   557,
      47,  -837,    54,  -837,  -837,  -837,  -837,  -837,  -837,  1672,
     503,   541,  -837,     7,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  1672,  -837,  -837,  1100,  -837,  -837,  1817,  -837,  1817,
    -837,  -837,  -837,  -837,  -837,   559,   531,  -837,   560,  -837,
    -837,  -837,   566,  -837,  -837,    29,  1133,  -837,  -837,  -837,
    -837,  -837,   249,   146,  -837,  -837,     1,   519,  -837,  -837,
    -837,  -837,   569,  -837,  -837,  -837,  -837,  -837,   -10,  -837,
     -10,  -837,   412,  -837,  -837,    68,  -837,   951,  -837,  -837,
    -837,   570,  -837,   562,  -837,  -837,  -837,  -837,  -837,   565,
      18,   129,  -837,   113,  -837,    72,   572,  -837,   518,   574,
    -837,  -837,   582,  -837,    -5,  -837,   584,  -837,   -53,  -837,
    -837,  1045,  1045,  1045,  -837,     1,   146,   583,  -837,  -837,
      47,  -837,    35,  -837,  -837,  -837,  -837,   588,  -837,  -837,
    -837,  -837,  -837,  -837,     1,  -837,     1,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  1672,  -837
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
     192,   193,   194,   195,   214,     0,    17,   589,   592,   591,
     198,   590,   202,     0,     0,     0,   316,   102,   108,   429,
     430,   107,    75,   105,   427,   428,   119,   212,   228,   228,
     238,   210,   238,   209,   228,   208,   159,     5,    11,    84,
      75,   183,     0,     0,   219,   215,   218,    70,    12,    16,
       0,   199,   196,     0,   233,   232,   234,   231,   200,   204,
     203,   318,    75,   106,   109,     0,   120,    76,   111,     0,
     229,   226,     0,     0,     0,   414,   415,   416,   417,   418,
     411,   583,   584,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   585,   587,   586,   588,   593,   594,   436,     0,
     243,   239,   251,   326,   410,   409,   420,     0,   324,   425,
     426,   432,   433,   571,   572,   573,   434,   569,   431,   435,
       0,     0,   161,    82,    83,    85,     0,   119,    13,   184,
     179,   221,   222,     0,   217,   216,     0,     0,    18,    23,
      19,   197,   230,     0,   319,   322,   119,   122,   110,     0,
     112,   113,   114,   115,   117,   257,   254,   118,   253,   228,
     227,   228,     0,   235,   237,   238,   252,   249,   336,   419,
       0,     0,   567,   568,   570,   565,   236,   228,     0,   101,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   554,   555,   556,   557,     0,   558,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,    98,   100,    81,    93,    90,    92,   537,   501,
     538,   539,    91,     0,    94,    95,    96,     0,   122,   213,
     181,   182,     0,     0,   220,    71,    21,     0,   317,   318,
     323,   320,   122,     0,   104,   124,   123,   116,   260,   205,
     207,   344,     0,   419,   343,   244,   240,     0,   250,   337,
     327,   335,   424,   419,   421,   423,   325,   566,   206,   168,
     162,     0,     0,     0,     0,   484,    87,   437,   440,   444,
     446,   448,   458,   469,   472,   477,   478,   479,   485,   480,
     481,   482,   483,   563,     0,     0,     0,     0,   541,   494,
       0,   313,   527,     0,     0,     0,   546,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   500,   308,
     308,     0,   520,   521,     0,     0,     0,     0,   495,     0,
     519,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    99,   308,   308,   305,   304,    74,   211,
       0,   223,   224,     0,    57,     0,    32,    46,     0,    20,
      24,     0,    30,    25,     0,    44,    26,    27,   321,   103,
       0,     0,   126,   125,   255,    78,     0,   256,   263,   261,
     267,   347,   345,   412,   333,   340,   342,   241,   238,     0,
     413,   422,     0,     0,   475,   476,   474,     0,    88,     0,
     438,   442,     0,     0,     0,     0,     0,     0,     0,     0,
     447,   449,   459,   471,   564,   562,   547,     0,     0,     0,
     314,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   309,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   225,    72,
       0,   174,    36,   175,    37,    33,    34,     0,   176,   171,
     172,   173,   170,    50,    51,    47,    48,     0,    30,     0,
      44,     0,     0,   130,   131,   134,   136,   133,   137,   138,
     140,   303,   301,   302,     0,   128,   127,     0,   258,   293,
     260,   268,   265,   336,     0,   328,   338,   242,   246,   160,
     165,   167,   169,   486,    86,    89,     0,   441,     0,   445,
     450,   451,   452,   453,   454,   455,     0,   456,     0,     0,
     464,   470,   460,   461,     0,     0,   473,   492,   493,   540,
     311,     0,     0,     0,   487,   488,     0,   490,   491,     0,
     532,   533,   534,   535,     0,   552,   553,     0,   550,   536,
     522,     0,     0,   511,   526,   518,   517,   499,   525,     0,
     516,   498,   515,     0,   524,   514,   505,     0,   497,   513,
     504,   496,   503,     0,   502,   523,   512,     0,   306,    56,
      59,    58,    35,    40,    49,    54,     0,    29,    38,    31,
       0,    43,    52,    45,    87,   132,   139,     0,     0,     0,
     121,   129,   153,   155,    79,   281,   285,   279,   290,     0,
       0,     0,   276,   264,   240,   277,   270,   272,   273,   275,
     271,   269,   294,   274,   266,   360,   348,     0,   390,     0,
       0,   346,   349,   351,   352,   361,   363,   366,   375,   370,
     373,   388,   362,   389,   330,   334,   419,   341,     0,     0,
     439,   443,   457,   466,   467,   465,   468,   462,   463,     0,
       0,     0,     0,     0,     0,   543,   548,   560,     0,     0,
       0,   543,     0,     0,   549,   311,    64,    41,    28,     0,
      55,    42,     0,     0,   146,   147,   141,   142,     0,   144,
     145,   149,   150,   157,   158,   151,   154,   152,   156,   119,
     282,   286,     0,   291,   300,     0,   278,   260,     0,     0,
     398,   406,     0,   391,   393,   400,   402,   405,   376,   419,
     364,   368,   384,     0,   386,   385,   372,   374,   377,   331,
     332,   419,   339,   247,     0,   163,   315,     0,   312,     0,
     529,   530,   489,   531,   544,     0,     0,   561,     0,   509,
     510,   506,     0,   507,   508,     0,     0,    39,    53,   135,
     143,   148,   122,     0,   287,   280,     0,     0,   262,   298,
     392,   399,     0,   395,   404,   407,   403,   358,     0,   367,
       0,   371,     0,   408,   387,     0,   329,   238,   166,   164,
     310,     0,   542,     0,   551,   545,   307,    60,    65,    61,
       0,    10,   283,   201,   292,     0,   295,   401,   397,   350,
     365,   369,     0,   381,     0,   382,     0,   528,     0,    62,
      63,     0,     0,     0,    80,     0,     0,     0,   296,   299,
       0,   396,   355,   359,   383,   378,   380,     0,   248,   559,
      68,    67,    66,   284,     0,   289,     0,   394,   353,   356,
     357,   379,   288,   297,   419,   354
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -837,  -837,  -837,  -837,  -837,  -273,   463,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,    62,  -837,   193,  -837,
    -143,  -837,  -837,    83,  -837,  -837,    70,  -837,   197,  -837,
    -144,  -837,  -837,    78,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,    12,
    -837,  -837,  -837,  -837,    56,  -837,  -837,  -837,   -50,  -837,
     363,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -155,   -98,  -837,  -287,  -837,  -837,
    -837,  -837,  -837,  -837,    75,  -837,  -837,    67,  -837,  -837,
    -137,  -837,  -837,  -837,  -837,  -837,  -837,   -52,   -49,    61,
    -837,  -837,  -837,  -837,  -837,  -837,  -426,  -837,   494,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,    -6,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,   567,  -837,  -837,   -43,  -837,    -3,
     599,   202,   630,   585,  -204,   -58,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -219,  -837,  -837,  -837,  -837,
    -571,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -837,  -638,
    -146,   295,  -837,  -322,  -689,  -116,  -228,  -837,  -837,  -837,
     354,  -837,  -837,  -837,   -80,  -837,  -837,   -90,  -837,  -837,
    -837,  -837,  -837,    74,  -790,  -837,  -837,   -86,   -79,  -837,
    -837,  -837,  -837,  -837,  -266,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,   -59,  -837,  -837,  -837,  -209,  -837,  -837,
     -60,  -837,  -208,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
    -837,  -837,  -837,  -837,  -837,  -837,  -775,  -837,  -837,  -836,
    -205,  -837,  -837,  -837,  -837,  -837,  -837,  -176,  -192,   -14,
      39,  -837,   689,  -837,  -837,  -837,    69,  -837,  -837,    63,
    -837,  -837,  -837,   -17,  -837,  -837,    53,  -837,  -837,  -837,
    -330,  -837,  -325,   -84,  -435,  -164,  -837,  -837,   -97,  -837,
    -837,  -837,  -130,  -837,  -837,  -837,  -837,  -837,  -837,  -837,
      26,  -837,  -837,  -837,    45,  -837,   185,   186,   226,  -242,
     -12,  -837,  -837
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,    26,    77,     5,     6,    46,    88,
     178,   307,   179,   180,   439,   440,   569,   441,   442,   554,
     555,   689,   779,   556,   778,   443,   571,   444,   445,   564,
     565,   693,   782,   566,   781,   446,   550,   681,   776,   920,
     898,   856,   899,     7,    89,   176,   433,    27,    28,    66,
     454,   455,   587,   799,    80,   165,   166,   478,   479,   281,
     282,   283,   284,    29,   102,    30,    61,    62,   187,    31,
     107,   190,   191,   192,   193,   108,   109,   314,   315,   452,
     585,   700,   316,   573,   574,   453,   578,   579,   586,   786,
     787,   788,   789,   790,   701,   795,   797,   702,   703,    78,
     162,   218,   834,   602,   749,   472,   557,     8,     9,    81,
     301,   169,   170,    32,    33,    91,    92,    34,    53,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
     174,    84,   173,    85,    86,   304,   431,   112,   113,    97,
      98,    71,    73,   139,   140,   468,   325,   204,   326,   327,
     748,   887,   141,   206,   207,   197,   456,   198,   318,   457,
     458,   713,   589,   459,   591,   592,   714,   715,   716,   802,
     717,   800,   863,   925,   718,   801,   864,   903,   719,   720,
     803,   866,   721,   722,   808,   929,   946,   906,   723,   580,
     581,   427,   775,   516,   838,   759,   372,   630,    57,   101,
     183,   184,   310,   311,   142,   210,   208,   329,   829,   830,
     745,   595,   330,   331,   464,   747,   596,   465,   323,   460,
     594,   593,   731,   819,   732,   949,   954,   950,   933,   909,
     726,   733,   734,   735,   736,   879,   820,   737,   881,   821,
     738,   826,   739,   827,   936,   915,   884,   828,   740,   741,
     813,   931,   908,   871,   872,   814,   815,   875,   816,   885,
     143,   144,   202,   145,   146,   147,   333,   466,   148,   324,
     345,   150,   346,   347,   607,   480,   348,   609,   481,   349,
     350,   490,   491,   351,   352,   620,   626,   756,   621,   492,
     353,   493,   354,   355,   356,   357,   369,   288,   845,   289,
     290,   291,   358,   767,   647,   293,   847,   848,   359,   495,
     360,   213,   214,   215,   361,   153,   154,   155,   362,   157,
     363,    51,   159
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int SPARQLfedParser::yytable_ninf_ = -420;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        50,   328,   287,    63,   332,    65,   188,    67,    54,    55,
     376,   428,   567,   388,    68,    69,   582,   335,    74,   724,
     285,   185,    58,   189,   599,   449,   114,   600,   339,   877,
     727,   161,   935,   334,   317,   873,   292,   195,   367,   370,
     728,   886,   425,   302,   110,   430,   912,   103,   687,    65,
     105,    99,  -180,   211,   729,   882,    64,   691,   158,   791,
     158,   688,   624,   105,  -119,   836,     1,   106,   517,   298,
     896,   804,   837,   921,   104,   727,   844,   837,   937,     1,
     106,   182,   844,   429,   810,   728,    10,   181,   312,   158,
     730,    11,   167,   194,   811,   -22,   151,   811,   151,   729,
      64,   200,   546,   547,   874,   913,   625,   688,   777,   149,
     303,   149,   322,   461,   186,   152,   914,   152,   332,   287,
     336,   132,   133,   134,   135,    52,   462,   151,   332,   679,
      56,   335,   680,    82,    83,   730,    70,   285,   567,   727,
     149,   335,   111,   582,   812,   496,   152,   812,   791,   728,
     434,   212,   447,   292,   297,   947,   319,   471,   320,    76,
     883,   -22,   196,   729,   955,   922,   923,   692,    47,    48,
      49,    72,   883,   601,   338,    59,    60,   194,    47,    48,
      49,    47,    48,    49,   368,   371,    59,    60,   426,  -119,
      65,    79,   294,   158,   163,   164,    65,   158,    65,   337,
      47,    48,    49,   321,    93,   286,   618,   619,   -22,    87,
     -22,   295,   -22,    47,    48,    49,   435,    90,    59,    60,
     177,    94,    47,    48,    49,    47,    48,    49,   822,   185,
      93,   151,    47,    48,    49,   151,   868,   -22,   -22,   -22,
     168,    64,   705,   706,   149,   823,    83,    64,   149,    64,
     152,    47,    48,    49,   152,    59,    60,   340,   474,   475,
     476,   617,   582,   436,   597,   437,    76,   438,   698,   699,
     824,   297,   199,  -259,   582,   780,   692,    47,    48,    49,
     707,   708,   201,   709,   171,   172,   577,   583,   753,   754,
     203,   432,    47,    48,    49,   194,   156,   158,   156,   757,
     758,   205,    95,    96,   575,   209,   158,   216,   308,   294,
     825,   158,   305,   126,   127,   128,   129,   130,   131,   306,
     217,   158,   286,   835,    47,    48,    49,   156,   295,    59,
      60,    47,    48,    49,   309,   151,    59,    60,    12,   313,
      13,    14,  -245,    15,   151,   365,   364,   366,   149,   151,
     373,   582,   374,   861,   152,   375,   567,   149,   377,   151,
     378,   710,   149,   152,   379,   380,   381,   382,   152,   383,
     392,   384,   149,   385,   386,   387,   393,   389,   152,   390,
     391,    12,   711,    13,    14,   461,    15,   398,   752,   -73,
     394,   395,   296,    16,    17,   396,   397,   399,   462,   400,
     401,   402,   482,   483,   484,   485,   486,   487,   889,   577,
     403,    18,   488,   489,   583,   404,   405,   406,   548,   407,
     508,   408,   409,   562,   410,   411,   562,   575,   412,   413,
     900,   156,   414,    19,   415,   156,   416,   417,   297,   297,
     418,   419,   420,   421,    20,    21,   422,   424,    22,   450,
      23,   463,   467,   451,   469,   598,   158,    65,    24,   515,
      25,   559,   549,   477,   559,   610,   611,   612,   613,   614,
     615,   435,   438,   584,   558,   588,    19,   558,   590,   606,
     560,   603,   605,   560,   608,   616,   627,    20,    21,   576,
     699,    22,   806,    23,   151,   940,   941,   942,   628,   629,
     631,    24,   632,    25,   633,   634,   635,   149,    64,   296,
     636,   637,   638,   152,   639,   640,   604,   641,   642,   643,
     644,   649,   650,   651,   653,   654,   655,   652,   656,   657,
     658,   660,   661,   583,   659,   156,   662,   664,   665,   666,
     663,   332,   562,   668,   156,   583,   669,   667,   670,   156,
     671,   672,   562,   674,   335,   675,   673,   676,   685,   156,
     697,   297,   683,   766,   744,   746,   297,   774,   698,   793,
     805,   839,   833,   794,   840,   901,   837,   883,   158,   841,
     559,    65,   743,   865,   842,   843,   846,   849,   850,   869,
     559,   851,   853,   558,   854,   859,   341,   106,   870,   560,
     892,   894,   461,   558,   880,   878,   893,   895,   905,   560,
     907,   917,   576,   919,   332,   462,   151,   918,   928,   934,
     930,   938,   583,   932,   945,   951,   332,   335,   924,   149,
     686,   299,    64,   742,   568,   152,   857,   682,   858,   335,
     690,   570,   684,   704,   783,   696,   423,   904,   695,   860,
     712,   798,   175,   796,   100,    75,   807,   160,   494,   855,
     832,   561,   300,   448,   561,   831,   948,   725,   809,   910,
     818,   751,   911,   755,   852,   750,   939,   622,   623,     0,
       0,     0,     0,   916,     0,   297,     0,     0,     0,     0,
       0,     0,     0,     0,   156,     0,     0,   297,     0,     0,
       0,   862,     0,     0,     0,     0,   943,     0,     0,     0,
       0,     0,     0,     0,     0,   743,     0,   817,   743,     0,
       0,     0,     0,     0,     0,   952,     0,   953,     0,     0,
       0,     0,    65,     0,   158,     0,   792,   562,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   332,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   335,     0,     0,     0,     0,   562,     0,     0,
     562,     0,   151,     0,   297,   559,     0,     0,     0,     0,
     561,     0,     0,    64,     0,   149,     0,     0,   558,     0,
     561,   152,     0,     0,   560,   158,     0,     0,   817,     0,
     876,     0,     0,     0,     0,   559,     0,   158,   559,     0,
       0,     0,     0,     0,     0,     0,   156,     0,   558,   158,
       0,   558,   562,     0,   560,   792,     0,   560,     0,     0,
       0,     0,     0,   151,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   562,   151,   149,     0,     0,   902,
       0,    65,   152,     0,     0,     0,     0,   151,   149,     0,
     559,     0,     0,     0,   152,     0,   743,     0,   743,     0,
     149,     0,     0,   558,     0,   158,   152,     0,     0,   560,
       0,     0,   559,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   558,     0,   926,     0,     0,
       0,   560,    64,     0,     0,     0,     0,     0,     0,   562,
     562,   562,   944,   151,    65,     0,     0,     0,   817,     0,
     743,     0,     0,     0,     0,     0,   149,     0,     0,     0,
       0,     0,   152,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   158,     0,   927,     0,     0,   559,   559,   559,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     558,   558,   558,     0,     0,    64,   560,   560,   560,     0,
       0,   742,   156,     0,     0,   561,     0,     0,     0,     0,
     151,     0,   115,   116,   117,   118,   119,     0,     0,     0,
       0,  -419,     0,   149,     0,     0,     0,     0,     0,   152,
       0,     0,   120,   -77,     0,   561,     0,     0,   561,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   115,   116,
     117,   118,   119,     0,     0,     0,     0,  -419,     0,     0,
     473,     0,     0,   156,     0,     0,     0,     0,   120,     0,
       0,     0,     0,     0,     0,   156,     0,     0,     0,     0,
       0,     0,     0,     0,   497,   498,   499,   156,     0,   500,
     561,   551,   501,   502,   503,     0,   504,   505,   506,   507,
       0,   509,   510,   511,   512,   513,   514,     0,     0,     0,
     518,     0,   561,   519,   520,   521,   522,   551,   523,     0,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,     0,   156,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    47,
      48,    49,   136,   137,    59,    60,     0,   138,     0,     0,
       0,   888,   551,     0,     0,     0,     0,   561,   561,   561,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    47,    48,    49,   136,   137,
      59,    60,   563,   138,   897,   551,     0,     0,     0,     0,
     156,   553,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    47,    48,    49,
       0,     0,    59,    60,     0,   646,   648,   553,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    47,    48,    49,     0,     0,    59,    60,
       0,     0,     0,     0,     0,   677,   678,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   694,   553,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    47,    48,
      49,     0,     0,    59,    60,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   553,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    47,    48,    49,     0,   645,    59,    60,     0,     0,
     760,   761,   762,     0,     0,   763,     0,     0,   764,     0,
       0,     0,     0,   765,     0,     0,   341,     0,     0,     0,
     768,   769,     0,     0,     0,     0,     0,     0,   770,     0,
       0,     0,   771,     0,     0,     0,   772,   342,   343,     0,
     344,   221,   773,   222,   223,   224,   225,   226,   227,   228,
     229,     0,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,   241,     0,     0,     0,   242,   243,
     244,   245,   246,   247,   248,   249,     0,     0,     0,     0,
       0,     0,     0,   250,   251,   252,     0,   253,   254,   255,
       0,     0,   256,   257,     0,   258,     0,   259,   260,   261,
     262,     0,   263,   264,     0,   265,     0,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   219,     0,     0,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    47,    48,    49,   220,     0,    59,
      60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   867,     0,     0,     0,     0,     0,
       0,     0,   221,     0,   222,   223,   224,   225,   226,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     0,   241,   890,     0,   891,   242,
     243,   244,   245,   246,   247,   248,   249,     0,     0,     0,
       0,     0,     0,     0,   250,   251,   252,     0,   253,   254,
     255,     0,     0,   256,   257,     0,   258,     0,   259,   260,
     261,   262,     0,   263,   264,     0,   265,     0,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   784,   785,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   341,     0,     0,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    47,    48,    49,     0,     0,
      59,    60,   221,     0,   222,   223,   224,   225,   226,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     0,   241,     0,   115,   116,   117,
     118,   119,     0,     0,     0,     0,   249,   470,     0,     0,
       0,     0,     0,     0,   250,   251,   252,   120,   253,   254,
     255,     0,     0,   256,   257,     0,   258,     0,   259,   260,
     261,   262,     0,   263,   264,   551,   265,     0,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   115,   116,   117,   118,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   120,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    47,    48,    49,     0,     0,
      59,    60,     0,     0,     0,   552,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    47,    48,    49,   136,   137,    59,
      60,     0,   138,     0,     0,   553,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    47,    48,    49,     0,     0,    59,    60,     0,     0,
       0,     0,     0,     0,     0,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      47,    48,    49,   136,   137,    59,    60,   341,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   342,   343,
       0,   344,   221,     0,   222,   223,   224,   225,   226,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     0,   241,     0,     0,     0,   242,
     243,   244,   245,   246,   247,   248,   249,     0,     0,     0,
       0,     0,     0,     0,   250,   251,   252,     0,   253,   254,
     255,     0,     0,   256,   257,     0,   258,     0,   259,   260,
     261,   262,     0,   263,   264,     0,   265,     0,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   220,     0,     0,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    47,    48,    49,     0,     0,
      59,    60,   221,     0,   222,   223,   224,   225,   226,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     0,   241,     0,     0,     0,   242,
     243,   244,   245,   246,   247,   248,   249,     0,     0,     0,
       0,     0,     0,     0,   250,   251,   252,     0,   253,   254,
     255,     0,     0,   256,   257,     0,   258,     0,   259,   260,
     261,   262,     0,   263,   264,     0,   265,     0,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   341,     0,     0,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    47,    48,    49,     0,     0,
      59,    60,   221,     0,   222,   223,   224,   225,   226,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     0,   241,     0,     0,     0,   242,
     243,   244,   245,   246,   247,   248,   249,     0,     0,     0,
       0,     0,     0,     0,   250,   251,   252,     0,   253,   254,
     255,     0,     0,   256,   257,     0,   258,     0,   259,   260,
     261,   262,     0,   263,   264,     0,   265,     0,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   572,     0,     0,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    47,    48,    49,     0,     0,
      59,    60,   221,     0,   222,   223,   224,   225,   226,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     0,   241,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   249,     0,     0,     0,
       0,     0,     0,     0,   250,   251,   252,     0,   253,   254,
     255,     0,     0,   256,   257,     0,   258,     0,   259,   260,
     261,   262,     0,   263,   264,   341,   265,     0,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,     0,     0,     0,     0,     0,     0,     0,
     221,     0,   222,   223,   224,   225,   226,   227,   228,   229,
       0,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,     0,   241,     0,    47,    48,    49,     0,     0,
      59,    60,     0,     0,   249,     0,     0,     0,     0,     0,
       0,     0,   250,   251,   252,     0,   253,   254,   255,     0,
       0,   256,   257,     0,   258,     0,   259,   260,   261,   262,
       0,   263,   264,     0,   265,     0,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47,    48,    49
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        12,   205,   166,    17,   209,    17,   104,    19,    14,    15,
     229,   298,   438,   241,    20,    21,   451,   209,    24,   590,
     166,   101,    19,    23,    37,   312,    69,    40,    36,   819,
      40,    74,    37,   209,   189,   810,   166,    36,    40,    40,
      50,   831,    40,    39,     6,    23,   882,    61,    43,    61,
      22,    54,     0,    87,    64,    48,    17,    43,    70,   697,
      72,   102,    19,    22,    36,    41,    14,    39,   390,   167,
      41,   709,    48,    55,    62,    40,   765,    48,   914,    14,
      39,    93,   771,   302,    40,    50,   178,    90,   186,   101,
     100,     0,    80,   105,    50,    36,    70,    50,    72,    64,
      61,   113,   424,   425,    50,    37,    63,   102,   149,    70,
     106,    72,   202,   318,   102,    70,    48,    72,   323,   283,
     210,   174,   175,   176,   177,    12,   318,   101,   333,    37,
      36,   323,    40,     3,     4,   100,    36,   283,   564,    40,
     101,   333,   104,   578,   100,   364,   101,   100,   786,    50,
      36,   185,   307,   283,   166,   930,   199,   333,   201,    30,
     165,   102,   161,    64,   954,   147,   148,   153,   178,   179,
     180,    36,   165,   186,   217,   183,   184,   189,   178,   179,
     180,   178,   179,   180,   186,   186,   183,   184,   186,   161,
     202,    16,   166,   205,    17,    18,   208,   209,   210,   211,
     178,   179,   180,    50,     6,   166,    61,    62,   149,    15,
     151,   166,   153,   178,   179,   180,   102,     9,   183,   184,
     161,    23,   178,   179,   180,   178,   179,   180,    19,   309,
       6,   205,   178,   179,   180,   209,   807,   178,   179,   180,
      49,   202,     6,     7,   205,    36,     4,   208,   209,   210,
     205,   178,   179,   180,   209,   183,   184,   218,   342,   343,
     344,   489,   697,   149,   468,   151,    30,   153,    28,    29,
      61,   283,   110,    37,   709,   152,   153,   178,   179,   180,
      44,    45,   110,    47,    82,    83,   450,   451,   618,   619,
      37,   303,   178,   179,   180,   307,    70,   309,    72,   624,
     625,    43,   104,   105,   450,    40,   318,    37,    37,   283,
     101,   323,   179,   168,   169,   170,   171,   172,   173,    55,
     110,   333,   283,   749,   178,   179,   180,   101,   283,   183,
     184,   178,   179,   180,    43,   309,   183,   184,     8,    90,
      10,    11,     6,    13,   318,    40,    74,    40,   309,   323,
      40,   786,    40,   788,   309,    40,   782,   318,    40,   333,
      40,   125,   323,   318,    40,    40,    40,    40,   323,    40,
     186,    40,   333,    40,    40,    40,   186,    40,   333,    40,
      40,     8,   146,    10,    11,   590,    13,   186,   616,    16,
      40,    40,   166,    20,    21,    40,    40,    40,   590,   186,
      40,    40,    55,    56,    57,    58,    59,    60,   834,   573,
      40,    38,    65,    66,   578,    40,    40,    40,   430,    40,
     381,    40,    40,   435,    40,    40,   438,   573,    40,    40,
     856,   205,    40,   103,    40,   209,    40,    40,   450,   451,
      40,    40,    40,    40,   114,   115,    40,    40,   118,    25,
     120,    52,    43,    91,     6,   469,   468,   469,   128,    17,
     130,   435,   178,    89,   438,   482,   483,   484,   485,   486,
     487,   102,   153,    24,   435,    37,   103,   438,    43,    53,
     435,    41,    41,   438,    54,    66,    41,   114,   115,   450,
      29,   118,   711,   120,   468,   921,   922,   923,    41,    41,
      48,   128,    48,   130,    48,    41,    41,   468,   469,   283,
      48,    41,    41,   468,    48,    41,   477,    41,    41,    41,
      48,    41,    41,    48,    41,    41,    41,    48,    41,    41,
      41,    41,    41,   697,    48,   309,    41,    41,    41,    41,
      48,   746,   554,    41,   318,   709,    41,    48,    41,   323,
      41,    41,   564,    41,   746,    41,    48,    41,   153,   333,
      25,   573,   102,    41,    49,    48,   578,    41,    28,   165,
      40,    48,    36,   165,    41,   862,    48,   165,   590,    41,
     554,   593,   594,   802,    41,    41,    49,    41,    41,   808,
     564,    41,    41,   554,    41,    41,    40,    39,    41,   554,
      41,    41,   807,   564,    63,   102,    75,    41,    89,   564,
      41,    41,   573,    48,   819,   807,   590,    55,    46,    37,
     102,    37,   786,    49,    41,    37,   831,   819,   901,   590,
     568,   168,   593,   594,   441,   590,   779,   554,   782,   831,
     570,   444,   564,   587,   694,   578,   283,   866,   573,   786,
     589,   703,    85,   702,    55,    25,   714,    72,   363,   775,
     746,   435,   168,   309,   438,   744,   932,   593,   727,   878,
     730,   608,   880,   620,   771,   606,   918,   492,   492,    -1,
      -1,    -1,    -1,   887,    -1,   697,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   468,    -1,    -1,   709,    -1,    -1,
      -1,   799,    -1,    -1,    -1,    -1,   925,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   727,    -1,   729,   730,    -1,
      -1,    -1,    -1,    -1,    -1,   944,    -1,   946,    -1,    -1,
      -1,    -1,   744,    -1,   746,    -1,   697,   749,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   954,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   954,    -1,    -1,    -1,    -1,   779,    -1,    -1,
     782,    -1,   746,    -1,   786,   749,    -1,    -1,    -1,    -1,
     554,    -1,    -1,   744,    -1,   746,    -1,    -1,   749,    -1,
     564,   746,    -1,    -1,   749,   807,    -1,    -1,   810,    -1,
     812,    -1,    -1,    -1,    -1,   779,    -1,   819,   782,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   590,    -1,   779,   831,
      -1,   782,   834,    -1,   779,   786,    -1,   782,    -1,    -1,
      -1,    -1,    -1,   807,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   856,   819,   807,    -1,    -1,   863,
      -1,   863,   807,    -1,    -1,    -1,    -1,   831,   819,    -1,
     834,    -1,    -1,    -1,   819,    -1,   878,    -1,   880,    -1,
     831,    -1,    -1,   834,    -1,   887,   831,    -1,    -1,   834,
      -1,    -1,   856,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   856,    -1,   903,    -1,    -1,
      -1,   856,   863,    -1,    -1,    -1,    -1,    -1,    -1,   921,
     922,   923,   926,   887,   926,    -1,    -1,    -1,   930,    -1,
     932,    -1,    -1,    -1,    -1,    -1,   887,    -1,    -1,    -1,
      -1,    -1,   887,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   954,    -1,   905,    -1,    -1,   921,   922,   923,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     921,   922,   923,    -1,    -1,   926,   921,   922,   923,    -1,
      -1,   932,   746,    -1,    -1,   749,    -1,    -1,    -1,    -1,
     954,    -1,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    40,    -1,   954,    -1,    -1,    -1,    -1,    -1,   954,
      -1,    -1,    51,    16,    -1,   779,    -1,    -1,   782,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    40,    -1,    -1,
     341,    -1,    -1,   807,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    -1,   819,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   365,   366,   367,   831,    -1,   370,
     834,    42,   373,   374,   375,    -1,   377,   378,   379,   380,
      -1,   382,   383,   384,   385,   386,   387,    -1,    -1,    -1,
     391,    -1,   856,   394,   395,   396,   397,    42,   399,    -1,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,    -1,   887,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,    -1,   186,    -1,    -1,
      -1,    41,    42,    -1,    -1,    -1,    -1,   921,   922,   923,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   153,   186,    41,    42,    -1,    -1,    -1,    -1,
     954,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,   183,   184,    -1,   516,   517,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,   183,   184,
      -1,    -1,    -1,    -1,    -1,   546,   547,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   572,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,    -1,    -1,   183,   184,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,    19,   183,   184,    -1,    -1,
     631,   632,   633,    -1,    -1,   636,    -1,    -1,   639,    -1,
      -1,    -1,    -1,   644,    -1,    -1,    40,    -1,    -1,    -1,
     651,   652,    -1,    -1,    -1,    -1,    -1,    -1,   659,    -1,
      -1,    -1,   663,    -1,    -1,    -1,   667,    61,    62,    -1,
      64,    65,   673,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,   108,   109,    -1,   111,   112,   113,
      -1,    -1,   116,   117,    -1,   119,    -1,   121,   122,   123,
     124,    -1,   126,   127,    -1,   129,    -1,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    40,    -1,   183,
     184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   805,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,   837,    -1,   839,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,    -1,   111,   112,
     113,    -1,    -1,   116,   117,    -1,   119,    -1,   121,   122,
     123,   124,    -1,   126,   127,    -1,   129,    -1,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
     183,   184,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    -1,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    99,    41,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,    51,   111,   112,
     113,    -1,    -1,   116,   117,    -1,   119,    -1,   121,   122,
     123,   124,    -1,   126,   127,    42,   129,    -1,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   178,   179,   180,    -1,    -1,
     183,   184,    -1,    -1,    -1,   102,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,    -1,   186,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,   183,   184,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,    40,   186,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      -1,    64,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,    -1,   111,   112,
     113,    -1,    -1,   116,   117,    -1,   119,    -1,   121,   122,
     123,   124,    -1,   126,   127,    -1,   129,    -1,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
     183,   184,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,    -1,   111,   112,
     113,    -1,    -1,   116,   117,    -1,   119,    -1,   121,   122,
     123,   124,    -1,   126,   127,    -1,   129,    -1,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
     183,   184,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,    -1,   111,   112,
     113,    -1,    -1,   116,   117,    -1,   119,    -1,   121,   122,
     123,   124,    -1,   126,   127,    -1,   129,    -1,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
     183,   184,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,    -1,   111,   112,
     113,    -1,    -1,   116,   117,    -1,   119,    -1,   121,   122,
     123,   124,    -1,   126,   127,    40,   129,    -1,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    -1,   178,   179,   180,    -1,    -1,
     183,   184,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
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
         0,    14,   188,   189,   190,   193,   194,   230,   294,   295,
     178,     0,     8,    10,    11,    13,    20,    21,    38,   103,
     114,   115,   118,   120,   128,   130,   191,   234,   235,   250,
     252,   256,   300,   301,   304,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   195,   178,   179,   180,
     507,   508,    12,   305,   305,   305,    36,   385,    19,   183,
     184,   253,   254,   456,   457,   507,   236,   507,   305,   305,
      36,   328,    36,   329,   305,   329,    30,   192,   286,    16,
     241,   296,     3,     4,   318,   320,   321,    15,   196,   231,
       9,   302,   303,     6,    23,   104,   105,   326,   327,   326,
     327,   386,   251,   456,   236,    22,    39,   257,   262,   263,
       6,   104,   324,   325,   324,    31,    32,    33,    34,    35,
      51,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   181,   182,   186,   330,
     331,   339,   391,   447,   448,   450,   451,   452,   455,   457,
     458,   497,   501,   502,   503,   504,   505,   506,   507,   509,
     330,   324,   287,    17,    18,   242,   243,   236,    49,   298,
     299,   328,   328,   319,   317,   321,   232,   161,   197,   199,
     200,   326,   507,   387,   388,   391,   236,   255,   262,    23,
     258,   259,   260,   261,   507,    36,   161,   342,   344,   110,
     507,   110,   449,    37,   334,    43,   340,   341,   393,    40,
     392,    87,   185,   498,   499,   500,    37,   110,   288,    19,
      40,    65,    67,    68,    69,    70,    71,    72,    73,    74,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    88,    92,    93,    94,    95,    96,    97,    98,    99,
     107,   108,   109,   111,   112,   113,   116,   117,   119,   121,
     122,   123,   124,   126,   127,   129,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   246,   247,   248,   249,   377,   457,   482,   484,   486,
     487,   488,   489,   492,   497,   501,   505,   507,   262,   193,
     295,   297,    39,   106,   322,   179,    55,   198,    37,    43,
     389,   390,   262,    90,   264,   265,   269,   261,   345,   324,
     324,    50,   394,   405,   456,   333,   335,   336,   331,   394,
     399,   400,   447,   453,   454,   455,   394,   507,   324,    36,
     457,    40,    61,    62,    64,   457,   459,   460,   463,   466,
     467,   470,   471,   477,   479,   480,   481,   482,   489,   495,
     497,   501,   505,   507,    74,    40,    40,    40,   186,   483,
      40,   186,   383,    40,    40,    40,   342,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,   383,    40,
      40,    40,   186,   186,    40,    40,    40,    40,   186,    40,
     186,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,   247,    40,    40,   186,   378,   264,   342,
      23,   323,   507,   233,    36,   102,   149,   151,   153,   201,
     202,   204,   205,   212,   214,   215,   222,   261,   387,   264,
      25,    91,   266,   272,   237,   238,   343,   346,   347,   350,
     406,   447,   455,    52,   401,   404,   454,    43,   332,     6,
      41,   454,   292,   459,   480,   480,   480,    89,   244,   245,
     462,   465,    55,    56,    57,    58,    59,    60,    65,    66,
     468,   469,   476,   478,   378,   496,   342,   459,   459,   459,
     459,   459,   459,   459,   459,   459,   459,   459,   457,   459,
     459,   459,   459,   459,   459,    17,   380,   380,   459,   459,
     459,   459,   459,   459,   459,   459,   459,   459,   459,   459,
     459,   459,   459,   459,   459,   459,   459,   459,   459,   459,
     459,   459,   459,   459,   459,   459,   380,   380,   507,   178,
     223,    42,   102,   162,   206,   207,   210,   293,   457,   497,
     501,   505,   507,   153,   216,   217,   220,   293,   205,   203,
     215,   213,    40,   270,   271,   377,   457,   482,   273,   274,
     376,   377,   481,   482,    24,   267,   275,   239,    37,   349,
      43,   351,   352,   408,   407,   398,   403,   331,   456,    37,
      40,   186,   290,    41,   457,    41,    53,   461,    54,   464,
     470,   470,   470,   470,   470,   470,    66,   383,    61,    62,
     472,   475,   503,   504,    19,    63,   473,    41,    41,    41,
     384,    48,    48,    48,    41,    41,    48,    41,    41,    48,
      41,    41,    41,    41,    48,    19,   459,   491,   459,    41,
      41,    48,    48,    41,    41,    41,    41,    41,    41,    48,
      41,    41,    41,    48,    41,    41,    41,    48,    41,    41,
      41,    41,    41,    48,    41,    41,    41,   459,   459,    37,
      40,   224,   210,   102,   220,   153,   203,    43,   102,   208,
     213,    43,   153,   218,   459,   271,   274,    25,    28,    29,
     268,   281,   284,   285,   241,     6,     7,    44,    45,    47,
     125,   146,   286,   348,   353,   354,   355,   357,   361,   365,
     366,   369,   370,   375,   347,   400,   417,    40,    50,    64,
     100,   409,   411,   418,   419,   420,   421,   424,   427,   429,
     435,   436,   457,   507,    49,   397,    48,   402,   337,   291,
     463,   466,   383,   477,   477,   473,   474,   479,   479,   382,
     459,   459,   459,   459,   459,   459,    41,   490,   459,   459,
     459,   459,   459,   459,    41,   379,   225,   149,   211,   209,
     152,   221,   219,   245,    26,    27,   276,   277,   278,   279,
     280,   376,   457,   165,   165,   282,   285,   283,   284,   240,
     358,   362,   356,   367,   376,    40,   342,   332,   371,   420,
      40,    50,   100,   437,   442,   443,   445,   507,   427,   410,
     423,   426,    19,    36,    61,   101,   428,   430,   434,   395,
     396,   405,   404,    36,   289,   293,    41,    48,   381,    48,
      41,    41,    41,    41,   381,   485,    49,   493,   494,    41,
      41,    41,   485,    41,    41,   382,   228,   207,   217,    41,
     277,   481,   262,   359,   363,   342,   368,   459,   347,   342,
      41,   440,   441,   443,    50,   444,   507,   401,   102,   422,
      63,   425,    48,   165,   433,   446,   401,   338,    41,   293,
     459,   459,    41,    75,    41,    41,    41,    41,   227,   229,
     293,   264,   456,   364,   342,    89,   374,    41,   439,   416,
     424,   429,   446,    37,    48,   432,   331,    41,    55,    48,
     226,    55,   147,   148,   192,   360,   305,   457,    46,   372,
     102,   438,    49,   415,    37,    37,   431,   446,    37,   506,
     293,   293,   293,   342,   456,    41,   373,   443,   411,   412,
     414,    37,   342,   342,   413,   401
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
     326,   327,   327,   327,   327,   328,   329,   330,   331,   331,
     332,   332,   333,   334,   334,   336,   337,   338,   335,   339,
     340,   341,   341,   342,   342,   343,   343,   345,   344,   346,
     347,   347,   348,   349,   349,   350,   351,   352,   352,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   354,   356,
     355,   358,   359,   360,   357,   362,   363,   364,   361,   365,
     367,   368,   366,   370,   371,   369,   373,   372,   374,   374,
     375,   376,   376,   376,   377,   378,   379,   378,   380,   380,
     381,   382,   382,   383,   384,   383,   386,   385,   387,   387,
     388,   389,   390,   390,   392,   391,   393,   391,   394,   395,
     396,   396,   397,   398,   398,   399,   400,   400,   401,   402,
     403,   403,   404,   405,   405,   407,   406,   408,   406,   410,
     409,   411,   411,   413,   412,   414,   414,   415,   416,   416,
     417,   418,   419,   420,   421,   422,   423,   423,   424,   425,
     426,   426,   427,   428,   428,   429,   429,   430,   431,   431,
     432,   432,   433,   433,   434,   434,   434,   434,   435,   436,
     436,   436,   436,   437,   438,   439,   439,   440,   441,   441,
     442,   442,   443,   444,   444,   445,   445,   445,   446,   447,
     447,   449,   448,   450,   451,   451,   451,   451,   451,   452,
     452,   453,   453,   454,   454,   455,   455,   456,   456,   457,
     457,   458,   458,   458,   458,   458,   458,   459,   460,   461,
     462,   462,   463,   464,   465,   465,   466,   467,   468,   468,
     469,   469,   469,   469,   469,   469,   469,   469,   470,   471,
     472,   472,   473,   473,   474,   474,   475,   475,   475,   476,
     476,   477,   478,   478,   479,   479,   479,   479,   480,   480,
     480,   480,   480,   480,   480,   480,   481,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     483,   483,   484,   485,   485,   486,   487,   488,   489,   489,
     490,   489,   491,   491,   492,   492,   492,   492,   492,   493,
     494,   494,   495,   496,   496,   497,   498,   499,   499,   500,
     500,   501,   501,   501,   502,   502,   502,   503,   503,   503,
     504,   504,   504,   505,   505,   506,   506,   506,   506,   507,
     507,   508,   508,   509,   509
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
       2,     1,     1,     1,     1,     3,     3,     2,     0,     1,
       0,     1,     3,     0,     2,     0,     0,     0,     8,     2,
       2,     0,     1,     1,     1,     1,     1,     0,     4,     2,
       0,     1,     3,     0,     2,     2,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     0,
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
       2,     2,     4,     4,     4,     4,     4,     2,     8,     6,
       6,     6,     4,     4,     4,     4,     4,     1,     1,     1,
       3,     1,     7,     0,     1,     7,     2,     3,     5,     5,
       0,     7,     1,     1,     1,     1,     1,     1,     1,     4,
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
  "Quads", "_QTriplesTemplate_E_Opt", "_QGT_DOT_E_Opt",
  "_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C_E_Star",
  "QuadsNotTriples", "@15", "@16", "$@17", "TriplesTemplate",
  "_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C_E_Opt", "GroupGraphPattern",
  "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C",
  "_O_QGT_LCURLEY_E_S_QSubSelect_E_Or_QGroupGraphPatternSub_E_S_QGT_RCURLEY_E_C",
  "$@18", "GroupGraphPatternSub", "_QTriplesBlock_E_Opt",
  "_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "Print", "OptionalGraphPattern", "@19", "GraphGraphPattern", "@20",
  "@21", "@22", "ServiceGraphPattern", "@23", "@24", "@25", "Bind",
  "MinusGraphPattern", "@26", "@27", "GroupOrUnionGraphPattern", "@28",
  "@29", "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@30",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "@31", "_QIT_DISTINCT_E_Opt",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ExpressionList", "@32",
  "ConstructTemplate", "$@33", "_QConstructTriples_E_Opt",
  "ConstructTriples", "_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C_E_Opt", "TriplesSameSubject",
  "$@34", "$@35", "PropertyListNotEmpty", "_O_QVerb_E_S_QObjectList_E_C",
  "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
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
     242,    -1,    89,   457,    -1,    -1,   244,    -1,    40,   459,
     245,    41,    -1,   457,    -1,   489,    -1,   482,    -1,   377,
      -1,   497,    -1,   501,    -1,   505,    -1,   246,    -1,   247,
      -1,   248,   247,    -1,   248,    -1,    19,    -1,    -1,    20,
     385,   251,   236,   262,   264,    -1,    21,   254,   236,   255,
     264,    -1,   456,    -1,   253,   456,    -1,   253,    -1,    19,
      -1,    -1,   262,    -1,    38,   236,   262,    -1,    22,   258,
      -1,   259,    -1,   260,    -1,   261,    -1,    23,   261,    -1,
     507,    -1,   263,   342,    -1,    -1,    39,    -1,   265,   266,
     267,   268,    -1,    -1,   269,    -1,    -1,   272,    -1,    -1,
     275,    -1,    -1,   281,    -1,    90,    25,   270,    -1,   271,
      -1,   270,   271,    -1,   482,    -1,   377,    -1,    40,   459,
     245,    41,    -1,   457,    -1,    91,   273,    -1,   274,    -1,
     273,   274,    -1,   376,    -1,    24,    25,   276,    -1,   277,
      -1,   276,   277,    -1,   279,    -1,   280,    -1,    26,    -1,
      27,    -1,   278,   481,    -1,   376,    -1,   457,    -1,   284,
     282,    -1,   285,   283,    -1,    -1,   285,    -1,    -1,   284,
      -1,    28,   165,    -1,    29,   165,    -1,    -1,    30,   287,
     288,    36,   292,    37,    -1,    -1,   288,   457,    -1,   293,
      -1,   289,   293,    -1,    -1,    40,   291,   289,    41,    -1,
     186,    -1,    -1,   292,   290,    -1,   507,    -1,   497,    -1,
     501,    -1,   505,    -1,    42,    -1,   162,    -1,   457,    -1,
     295,    -1,    -1,   193,   300,   296,   299,    -1,    -1,   295,
      -1,    49,   297,    -1,    -1,   298,    -1,   301,    -1,   304,
      -1,   306,    -1,   308,    -1,   309,    -1,   310,    -1,   307,
      -1,   311,    -1,   312,    -1,   313,    -1,   314,    -1,     8,
     507,   303,    -1,     9,   326,    -1,    -1,   302,    -1,    10,
     305,   327,    -1,    -1,    12,    -1,    13,   305,   327,    -1,
      11,   305,   326,    -1,   114,   305,   324,   110,   324,    -1,
     128,   305,   324,   110,   324,    -1,   115,   305,   324,   110,
     324,    -1,   130,   329,    -1,   120,   329,    -1,   118,   328,
      -1,   316,   318,   319,    39,   342,    -1,   103,   507,    -1,
      -1,   315,    -1,    -1,   321,    -1,   320,   317,    -1,   321,
      -1,    -1,   319,   322,    -1,     3,   328,    -1,     4,   328,
      -1,   106,   323,    -1,   507,    -1,    23,   507,    -1,   104,
      -1,   325,   507,    -1,    -1,     6,    -1,     6,   507,    -1,
     326,    -1,   104,    -1,    23,    -1,   105,    -1,    36,   330,
      37,    -1,    36,   330,    37,    -1,   331,   334,    -1,    -1,
     339,    -1,    -1,    43,    -1,   335,   332,   331,    -1,    -1,
     334,   333,    -1,    -1,    -1,    -1,   336,     6,   456,   337,
      36,   338,   331,    37,    -1,   391,   341,    -1,    43,   331,
      -1,    -1,   340,    -1,   344,    -1,   161,    -1,   237,    -1,
     346,    -1,    -1,    36,   345,   343,    37,    -1,   347,   349,
      -1,    -1,   350,    -1,   353,   332,   347,    -1,    -1,   349,
     348,    -1,   406,   352,    -1,    43,   347,    -1,    -1,   351,
      -1,   369,    -1,   355,    -1,   366,    -1,   357,    -1,   361,
      -1,   375,    -1,   365,    -1,   286,    -1,   354,    -1,   146,
     342,    -1,    -1,    44,   356,   342,    -1,    -1,    -1,    -1,
       6,   358,   359,   456,   360,   342,    -1,    -1,    -1,    -1,
       7,   362,   363,   364,   305,   456,   342,    -1,   125,    40,
     459,    89,   457,    41,    -1,    -1,    -1,    45,   367,   368,
     342,    -1,    -1,    -1,   370,   371,   342,   374,    -1,    -1,
      46,   373,   342,    -1,    -1,   374,   372,    -1,    47,   376,
      -1,   481,    -1,   482,    -1,   377,    -1,   507,   378,    -1,
     186,    -1,    -1,    40,   380,   459,   379,   382,    41,    -1,
      -1,    17,    -1,    48,   459,    -1,    -1,   382,   381,    -1,
     186,    -1,    -1,    40,   459,   384,   382,    41,    -1,    -1,
      36,   386,   387,    37,    -1,    -1,   388,    -1,   391,   390,
      -1,    43,   387,    -1,    -1,   389,    -1,    -1,   455,   392,
     394,    -1,    -1,   447,   393,   399,    -1,   405,   401,   398,
      -1,   405,   401,    -1,    -1,   395,    -1,    49,   396,    -1,
      -1,   398,   397,    -1,   400,    -1,    -1,   394,    -1,   404,
     403,    -1,    48,   404,    -1,    -1,   403,   402,    -1,   454,
      -1,   456,    -1,    50,    -1,    -1,   455,   407,   409,    -1,
      -1,   447,   408,   417,    -1,    -1,   411,   410,   401,   416,
      -1,   418,    -1,   419,    -1,    -1,   411,   413,   401,    -1,
      -1,   412,    -1,    49,   414,    -1,    -1,   416,   415,    -1,
     400,    -1,   420,    -1,   457,    -1,   421,    -1,   424,   423,
      -1,   102,   424,    -1,    -1,   423,   422,    -1,   429,   426,
      -1,    63,   429,    -1,    -1,   426,   425,    -1,   435,   428,
      -1,    -1,   430,    -1,   427,    -1,   100,   427,    -1,   434,
      -1,    37,    -1,   446,    37,    -1,    48,   431,    -1,    37,
      -1,   446,   432,    -1,    48,   446,    37,    -1,    19,    -1,
     101,    -1,    61,    -1,    36,   433,    -1,   436,    -1,   507,
      -1,    50,    -1,    64,   437,    -1,    40,   420,    41,    -1,
     442,    -1,   102,   443,    -1,    -1,   439,   438,    -1,   443,
     439,    -1,    -1,   440,    -1,   443,    -1,    40,   441,    41,
      -1,   445,    -1,   507,    -1,    50,    -1,   507,    -1,    50,
      -1,   100,   444,    -1,   165,    -1,   450,    -1,   448,    -1,
      -1,    51,   449,   394,    52,    -1,   452,    40,   453,    41,
      -1,    31,    -1,    32,    -1,    33,    -1,    34,    -1,    35,
      -1,    -1,   451,    -1,   454,    -1,   453,   454,    -1,   455,
      -1,   447,    -1,   457,    -1,   458,    -1,   457,    -1,   507,
      -1,   183,    -1,   184,    -1,   507,    -1,   497,    -1,   501,
      -1,   505,    -1,   509,    -1,   186,    -1,   460,    -1,   463,
     462,    -1,    53,   463,    -1,    -1,   462,   461,    -1,   466,
     465,    -1,    54,   466,    -1,    -1,   465,   464,    -1,   467,
      -1,   470,   468,    -1,    -1,   469,    -1,    55,   470,    -1,
      56,   470,    -1,    57,   470,    -1,    58,   470,    -1,    59,
     470,    -1,    60,   470,    -1,    66,   383,    -1,    65,    66,
     383,    -1,   471,    -1,   477,   476,    -1,   503,    -1,   504,
      -1,    19,   479,    -1,    63,   479,    -1,    -1,   473,    -1,
      61,   477,    -1,    62,   477,    -1,   472,   474,    -1,    -1,
     476,   475,    -1,   479,   478,    -1,    -1,   478,   473,    -1,
      64,   480,    -1,    61,   480,    -1,    62,   480,    -1,   480,
      -1,   481,    -1,   482,    -1,   495,    -1,   497,    -1,   501,
      -1,   505,    -1,   457,    -1,   489,    -1,    40,   459,    41,
      -1,    76,    40,   459,    41,    -1,    77,    40,   459,    41,
      -1,    78,    40,   459,    48,   459,    41,    -1,    79,    40,
     459,    41,    -1,    80,    40,   457,    41,    -1,    67,    40,
     459,    41,    -1,    68,    40,   459,    41,    -1,    69,   483,
      -1,   116,   186,    -1,   140,    40,   459,    41,    -1,   137,
      40,   459,    41,    -1,   129,    40,   459,    41,    -1,   123,
      40,   459,    41,    -1,    88,   383,    -1,   486,    -1,   143,
      40,   459,    41,    -1,   141,    40,   459,    41,    -1,   139,
      40,   459,    41,    -1,   135,    40,   459,    41,    -1,   126,
      40,   459,    48,   459,    41,    -1,   136,    40,   459,    48,
     459,    41,    -1,   142,    40,   459,    48,   459,    41,    -1,
     111,    40,   459,    48,   459,    41,    -1,   112,    40,   459,
      48,   459,    41,    -1,   113,    40,   459,    41,    -1,   145,
      40,   459,    41,    -1,   138,    40,   459,    41,    -1,   134,
      40,   459,    41,    -1,   131,    40,   459,    41,    -1,   127,
      40,   459,    41,    -1,   122,    40,   459,    41,    -1,   121,
      40,   459,    41,    -1,   119,   186,    -1,   107,   186,    -1,
     108,   186,    -1,   109,    40,   459,    41,    -1,   144,    40,
     459,    41,    -1,   133,    40,   459,    41,    -1,   124,    40,
     459,    41,    -1,   117,    40,   459,    41,    -1,    70,   383,
      -1,    71,    40,   459,    48,   459,    48,   459,    41,    -1,
      72,    40,   459,    48,   459,    41,    -1,    73,    40,   459,
      48,   459,    41,    -1,    81,    40,   459,    48,   459,    41,
      -1,    82,    40,   459,    41,    -1,    83,    40,   459,    41,
      -1,    84,    40,   459,    41,    -1,    85,    40,   459,    41,
      -1,    99,    40,   459,    41,    -1,   484,    -1,   487,    -1,
     488,    -1,    40,   459,    41,    -1,   186,    -1,    86,    40,
     459,    48,   459,   485,    41,    -1,    -1,   381,    -1,   132,
      40,   459,    48,   459,   485,    41,    -1,    74,   342,    -1,
      65,    74,   342,    -1,    92,    40,   380,   491,    41,    -1,
     492,    40,   380,   459,    41,    -1,    -1,    97,    40,   380,
     459,   490,   494,    41,    -1,    19,    -1,   459,    -1,    93,
      -1,    94,    -1,    95,    -1,    96,    -1,    98,    -1,    49,
      75,    55,   506,    -1,    -1,   493,    -1,   507,   496,    -1,
      -1,   378,    -1,   506,   500,    -1,    87,   507,    -1,   185,
      -1,   498,    -1,    -1,   499,    -1,   502,    -1,   503,    -1,
     504,    -1,   165,    -1,   166,    -1,   167,    -1,   168,    -1,
     169,    -1,   170,    -1,   171,    -1,   172,    -1,   173,    -1,
     163,    -1,   164,    -1,   174,    -1,   176,    -1,   175,    -1,
     177,    -1,   178,    -1,   508,    -1,   180,    -1,   179,    -1,
     181,    -1,   182,    -1
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
     567,   570,   572,   574,   576,   578,   582,   586,   589,   590,
     592,   593,   595,   599,   600,   603,   604,   605,   606,   615,
     618,   621,   622,   624,   626,   628,   630,   632,   633,   638,
     641,   642,   644,   648,   649,   652,   655,   658,   659,   661,
     663,   665,   667,   669,   671,   673,   675,   677,   679,   682,
     683,   687,   688,   689,   690,   697,   698,   699,   700,   708,
     715,   716,   717,   722,   723,   724,   729,   730,   734,   735,
     738,   741,   743,   745,   747,   750,   752,   753,   760,   761,
     763,   766,   767,   770,   772,   773,   779,   780,   785,   786,
     788,   791,   794,   795,   797,   798,   802,   803,   807,   811,
     814,   815,   817,   820,   821,   824,   826,   827,   829,   832,
     835,   836,   839,   841,   843,   845,   846,   850,   851,   855,
     856,   861,   863,   865,   866,   870,   871,   873,   876,   877,
     880,   882,   884,   886,   888,   891,   894,   895,   898,   901,
     904,   905,   908,   911,   912,   914,   916,   919,   921,   923,
     926,   929,   931,   934,   938,   940,   942,   944,   947,   949,
     951,   953,   956,   960,   962,   965,   966,   969,   972,   973,
     975,   977,   981,   983,   985,   987,   989,   991,   994,   996,
     998,  1000,  1001,  1006,  1011,  1013,  1015,  1017,  1019,  1021,
    1022,  1024,  1026,  1029,  1031,  1033,  1035,  1037,  1039,  1041,
    1043,  1045,  1047,  1049,  1051,  1053,  1055,  1057,  1059,  1062,
    1065,  1066,  1069,  1072,  1075,  1076,  1079,  1081,  1084,  1085,
    1087,  1090,  1093,  1096,  1099,  1102,  1105,  1108,  1112,  1114,
    1117,  1119,  1121,  1124,  1127,  1128,  1130,  1133,  1136,  1139,
    1140,  1143,  1146,  1147,  1150,  1153,  1156,  1159,  1161,  1163,
    1165,  1167,  1169,  1171,  1173,  1175,  1177,  1181,  1186,  1191,
    1198,  1203,  1208,  1213,  1218,  1221,  1224,  1229,  1234,  1239,
    1244,  1247,  1249,  1254,  1259,  1264,  1269,  1276,  1283,  1290,
    1297,  1304,  1309,  1314,  1319,  1324,  1329,  1334,  1339,  1344,
    1347,  1350,  1353,  1358,  1363,  1368,  1373,  1378,  1381,  1390,
    1397,  1404,  1411,  1416,  1421,  1426,  1431,  1436,  1438,  1440,
    1442,  1446,  1448,  1456,  1457,  1459,  1467,  1470,  1474,  1480,
    1486,  1487,  1495,  1497,  1499,  1501,  1503,  1505,  1507,  1509,
    1514,  1515,  1517,  1520,  1521,  1523,  1526,  1529,  1531,  1533,
    1534,  1536,  1538,  1540,  1542,  1544,  1546,  1548,  1550,  1552,
    1554,  1556,  1558,  1560,  1562,  1564,  1566,  1568,  1570,  1572,
    1574,  1576,  1578,  1580,  1582
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
    1355,  1363,  1372,  1378,  1381,  1385,  1388,  1392,  1396,  1402,
    1404,  1410,  1417,  1424,  1430,  1433,  1439,  1442,  1447,  1449,
    1453,  1459,  1462,  1465,  1468,  1475,  1479,  1483,  1486,  1488,
    1492,  1494,  1498,  1501,  1503,  1508,  1513,  1516,  1508,  1527,
    1531,  1534,  1536,  1540,  1541,  1554,  1555,  1560,  1560,  1571,
    1575,  1577,  1587,  1591,  1594,  1610,  1615,  1619,  1622,  1626,
    1627,  1628,  1629,  1630,  1631,  1632,  1633,  1636,  1640,  1646,
    1646,  1662,  1666,  1668,  1662,  1679,  1683,  1685,  1679,  1696,
    1707,  1711,  1707,  1721,  1725,  1721,  1735,  1735,  1747,  1749,
    1753,  1763,  1764,  1765,  1769,  1777,  1781,  1781,  1791,  1794,
    1801,  1807,  1809,  1823,  1826,  1826,  1837,  1837,  1845,  1847,
    1852,  1857,  1861,  1863,  1867,  1867,  1870,  1870,  1877,  1882,
    1886,  1888,  1893,  1897,  1899,  1904,  1908,  1910,  1915,  1920,
    1924,  1926,  1930,  1937,  1941,  1949,  1949,  1952,  1952,  1958,
    1958,  1964,  1965,  1969,  1969,  1974,  1976,  1980,  1983,  1985,
    1989,  1993,  1997,  2003,  2007,  2011,  2014,  2016,  2020,  2024,
    2029,  2031,  2037,  2040,  2042,  2048,  2049,  2055,  2059,  2060,
    2064,  2065,  2069,  2070,  2074,  2075,  2076,  2077,  2081,  2085,
    2088,  2091,  2094,  2100,  2104,  2107,  2109,  2113,  2116,  2118,
    2122,  2123,  2127,  2131,  2132,  2136,  2137,  2138,  2142,  2147,
    2148,  2152,  2152,  2165,  2190,  2193,  2196,  2199,  2202,  2209,
    2212,  2217,  2221,  2228,  2229,  2233,  2236,  2240,  2243,  2249,
    2250,  2254,  2257,  2260,  2263,  2266,  2267,  2273,  2278,  2287,
    2294,  2297,  2305,  2314,  2321,  2324,  2331,  2336,  2347,  2350,
    2354,  2357,  2360,  2363,  2366,  2369,  2372,  2375,  2381,  2386,
    2395,  2398,  2405,  2408,  2415,  2418,  2423,  2426,  2430,  2444,
    2447,  2455,  2464,  2467,  2474,  2477,  2480,  2483,  2487,  2488,
    2489,  2490,  2493,  2496,  2499,  2502,  2506,  2512,  2515,  2518,
    2521,  2524,  2527,  2530,  2534,  2537,  2540,  2543,  2546,  2549,
    2552,  2555,  2556,  2559,  2562,  2565,  2568,  2571,  2574,  2577,
    2580,  2583,  2586,  2589,  2592,  2595,  2598,  2601,  2604,  2607,
    2610,  2613,  2616,  2619,  2622,  2625,  2628,  2631,  2635,  2638,
    2641,  2644,  2647,  2650,  2653,  2656,  2659,  2662,  2663,  2664,
    2670,  2673,  2680,  2687,  2690,  2694,  2700,  2707,  2714,  2717,
    2721,  2721,  2735,  2739,  2743,  2746,  2749,  2752,  2755,  2761,
    2767,  2770,  2774,  2784,  2787,  2792,  2800,  2807,  2811,  2819,
    2823,  2827,  2828,  2829,  2833,  2834,  2835,  2839,  2840,  2841,
    2845,  2846,  2847,  2851,  2852,  2856,  2857,  2858,  2859,  2863,
    2864,  2868,  2869,  2873,  2874
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
  const int SPARQLfedParser::yylast_ = 2445;
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
#line 5600 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 2880 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


