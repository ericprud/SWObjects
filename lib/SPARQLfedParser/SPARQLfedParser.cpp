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
#line 468 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

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
#line 482 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 485 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 496 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 540 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.startBindingSet();
      }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 543 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 558 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = (yysemantic_stack_[(2) - (1)].p_RSName);
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 564 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = NULL;
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 574 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	throw std::runtime_error("need to partition out results set part of SimpleEngine::loadDataOrResults");
    }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 608 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 610 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 616 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 654 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 656 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 662 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 681 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow(false);
      }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 683 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 703 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
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
#line 715 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 721 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 723 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 725 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 733 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 736 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause);
	(yyval.p_Operation) = new Select((yysemantic_stack_[(5) - (2)].p_Project).distinctness, (yysemantic_stack_[(5) - (2)].p_Project).varSet, (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
	driver.countStar = (yysemantic_stack_[(5) - (1)].p_parentCountStar);
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 745 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 748 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 756 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 759 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 762 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 766 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 777 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 785 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 788 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 795 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 803 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 810 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 818 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 825 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 828 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 831 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 834 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 837 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 840 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 843 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 852 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 855 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 863 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 866 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 872 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(2) - (2)].p_Operation);
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 878 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = NULL;
      }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 880 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause);
	  /* $1 is NO LONGER known to be a DefaultGraphPattern because of grammar restrictions. */
	  (yyval.p_Operation) = new Construct((yysemantic_stack_[(5) - (1)].p_TableOperation), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
      }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 885 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	SWObjectDuplicator dup(driver.atomFactory);
	(yysemantic_stack_[(4) - (3)].p_TableOperation)->express(&dup);
	driver.lastWhereClause = new WhereClause((yysemantic_stack_[(4) - (3)].p_TableOperation));
	(yyval.p_Operation) = new Construct(dup.last.tableOperation, (yysemantic_stack_[(4) - (1)].p_DatasetClauses), driver.lastWhereClause, (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 895 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause) ? (yysemantic_stack_[(5) - (4)].p_WhereClause) : new WhereClause(new DefaultGraphPattern());
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 903 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm))));
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 906 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_TTerm))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 914 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 917 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 924 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 932 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(4) - (3)].p_WhereClause);
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 940 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 952 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 958 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 964 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 971 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.ensureGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 985 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 992 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1000 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1008 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1016 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1024 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1031 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1034 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1041 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1044 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1047 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1050 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1056 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1062 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1065 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1077 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1084 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1088 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1098 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1106 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1109 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1117 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1126 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1133 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1137 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1145 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1153 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1160 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1166 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1176 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = (yysemantic_stack_[(2) - (2)].p_BindingClause);
    }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1182 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1189 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	OperationSet* ret = driver.root ? dynamic_cast<OperationSet*>(driver.root) : new OperationSet();
	ret->push_back((yysemantic_stack_[(2) - (2)].p_Operation));
	driver.root = ret;
      }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1193 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Operation) = driver.root;
	}
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1231 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(4) - (2)].p_Silence), (yysemantic_stack_[(4) - (3)].p_URI), (yysemantic_stack_[(4) - (4)].p_URI));
    }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1237 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1240 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1247 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1254 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1261 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1267 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1273 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1279 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1285 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1291 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1297 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1305 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1313 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1320 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(5) - (1)].p_URI))
	    w3c_sw_NEED_IMPL("WITH <URI> (DELETE INSERT?|INSERT) ...");
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(5) - (2)].p_DeleteInsert).del, (yysemantic_stack_[(5) - (2)].p_DeleteInsert).ins, new WhereClause(driver.ensureGraphPattern()));
	driver.curOp = NULL;
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1329 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1335 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1342 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1349 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1353 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1361 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("_QUsingClause_E_Star");
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1367 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Delete) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1373 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = new Insert((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1379 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1385 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 1388 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1394 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 1397 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 1408 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 1414 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 1417 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("DEFAULT");
      }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1420 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("NAMED");
      }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 1423 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("ALL");
      }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1430 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
    }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 1436 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
    }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 1442 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 1444 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TableOperation) = driver.ensureGraphPattern();
	  driver.curOp = NULL;
      }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 1472 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 1477 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 1480 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 1483 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 1505 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 245:

/* Line 690 of lalr1.cc  */
#line 1524 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 1526 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 1597 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_BindingClause)) : (yysemantic_stack_[(1) - (1)].p_BindingClause);
    }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 1604 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Print(driver.curOp);
    }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 1610 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 1614 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 269:

/* Line 690 of lalr1.cc  */
#line 1626 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 1630 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 1632 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 1635 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 1643 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 1647 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 1649 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 1652 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(7) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(7) - (6)].p_TTerm), driver.curOp, (yysemantic_stack_[(7) - (5)].p_Silence), driver.atomFactory, false));
	  driver.curGraphName = (yysemantic_stack_[(7) - (4)].p_TTerm);
      }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 1660 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Bind(driver.ensureGraphPattern(), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
	// no more triples go into the current BGP, per
	//   http://www.w3.org/TR/sparql11-query/#sparqlTranslateGraphPatterns
	// test reference:
	//   http://www.sparql.org/query-validator?query=ASK+{+%3Fs+%3Fp+%3Fo+FILTER+%281%29+BIND+%282+AS+%3Fb%29+%3Fs2+%3Fp2+%3Fo2+FILTER+%283%29+BIND+%284+AS+%3Fd%29}&languageSyntax=SPARQL&outputFormat=algebra&linenumbers=false
	driver.curBGP = NULL;
    }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 1671 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = (yysemantic_stack_[(2) - (2)].p_BindingClause);
    }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 1682 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 1684 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
      }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 1686 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 1697 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
	driver.endBindingRow();
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 1705 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
    }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 1707 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 1714 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 1726 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 1732 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 1734 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 1737 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 1749 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 1752 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 1755 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 1758 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 1761 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 1764 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 1767 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 1773 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 1777 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 1779 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 1787 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 1791 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 1793 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 1801 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 1806 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.ensureGraphPattern());
      }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 1819 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    driver.ensureGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 1835 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 1843 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 1847 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 1850 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yysemantic_stack_[(6) - (4)].p_Expressions);
      }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 1857 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 1860 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 1867 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 1875 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 1889 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 1892 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 1895 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(5) - (3)].p_Expressions);
      }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 1902 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 1905 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 1947 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 1951 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::RDF_type;
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 1974 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 1982 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 1985 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 2000 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 2011 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 2035 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 2054 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 2082 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 2089 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 2100 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 2107 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 2119 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 2122 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::RDF_type;
    }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 2125 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 2128 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 2175 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 2179 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 2188 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 418:

/* Line 690 of lalr1.cc  */
#line 2216 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 2219 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 2222 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 2225 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 2228 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 2235 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 2243 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 2247 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 2259 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 2263 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject;
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 2271 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 432:

/* Line 690 of lalr1.cc  */
#line 2298 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 2302 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 2319 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 2326 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 2329 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 2340 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 2343 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 2346 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 2349 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 2353 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::RDF_nil; // !!! new GraphTerm_rule5($1);
    }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 2364 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 2373 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 2380 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 2383 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 2391 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 2400 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 2407 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 2410 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 2422 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 461:

/* Line 690 of lalr1.cc  */
#line 2435 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = NULL;
    }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 2443 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 2447 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 2451 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 2455 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 2459 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 2463 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 2467 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 2471 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = true;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 2483 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 2492 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 2495 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 2502 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 2505 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 2512 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 2520 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 2523 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 2527 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 482:

/* Line 690 of lalr1.cc  */
#line 2541 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 2544 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 2552 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 2561 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 2564 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 2571 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 2574 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 2577 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 2587 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 2590 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 2593 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 2596 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 2603 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 2609 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 2612 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 2615 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 2618 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 2621 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 2624 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 2627 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 2631 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 2634 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 2637 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 2640 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ceil, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 2643 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 2646 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 2649 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 2653 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 2657 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 2660 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 2663 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 2666 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 2669 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 2672 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 2675 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 2678 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 2681 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 2684 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 2687 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 2690 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 2693 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 2696 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 2699 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 2702 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 2705 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 2708 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_uuid, NULL, NULL, NULL));
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 2711 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_struuid, NULL, NULL, NULL));
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 2714 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 2717 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 2720 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 2723 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 2726 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 2729 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 2732 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 2735 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 2738 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 2741 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 2744 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 2747 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 2750 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 2753 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 2756 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 2767 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 2770 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 2777 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 2784 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 2791 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 2797 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_replace, (yysemantic_stack_[(9) - (3)].p_Expression), (yysemantic_stack_[(9) - (5)].p_Expression), (yysemantic_stack_[(9) - (7)].p_Expression))); // !! , $8
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 2803 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 2806 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 2810 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expression) = new ExistsExpression(driver.ensureGraphPattern());
	  driver.curOp = (yysemantic_stack_[(4) - (3)].p_TableOperation);
	  driver.countStar = (yysemantic_stack_[(4) - (2)].p_parentCountStar);
      }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 2818 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
      }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 2821 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 2825 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  // $$ = new ExistsExpression(false, driver.ensureGraphPattern());
	  (yyval.p_Expression) = new BooleanNegation(new ExistsExpression(driver.ensureGraphPattern()));
	  driver.curOp = (yysemantic_stack_[(5) - (4)].p_TableOperation);
	  driver.countStar = (yysemantic_stack_[(5) - (3)].p_parentCountStar);
      }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 2834 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 2838 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 2843 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  AggregateCall::ScalarVals svals;
	  if ((yysemantic_stack_[(6) - (5)].p_RDFLiteral) != NULL)
	      svals["separator"] = (yysemantic_stack_[(6) - (5)].p_RDFLiteral)->getLexicalValue();
	  (yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression), svals));
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 2852 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 2859 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 2862 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 2865 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 2868 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 2871 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 2877 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 2883 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 2890 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 2900 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 2908 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 2916 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 2923 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 2927 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 2935 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 690 of lalr1.cc  */
#line 3904 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -849;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        69,   -90,    93,  -849,  -849,  -849,   385,  -849,  -849,  -849,
    -849,  -849,    53,    53,    53,    53,    86,     3,  -849,   128,
      53,    53,    86,    90,    53,    90,   108,  -849,   132,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,   100,    82,  -849,   128,   280,
     164,   280,  -849,    45,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,   137,  -849,  -849,  -849,  -849,  -849,    52,  -849,
      56,    56,  -849,  -849,  -849,    56,  -849,   -15,  -849,  -849,
    -849,    96,  -849,   330,    86,    86,  -849,   192,  -849,  -849,
      54,  -849,   198,   128,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,   175,  1222,     0,    86,  -849,  -849,  -849,    33,  -849,
     138,    -7,  -849,  -849,   117,   128,   125,   200,   141,  -849,
    -849,   -65,  -849,     7,  -849,  -849,  -849,  1570,    52,  -849,
    -849,   190,  -849,  -849,    17,  -849,  -849,    63,   194,  -849,
    -849,  -849,   164,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,   212,  -849,  -849,  -849,  -849,   219,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,   -44,  -849,
    -849,   128,  -849,  -849,  -849,  -849,  -849,   138,    52,   138,
    -849,   239,  -849,   173,  -849,  -849,  -849,  -849,  -849,    56,
    -849,    56,  -849,    56,  -849,  -849,  -849,   258,  -849,  2054,
     229,   265,   273,    11,    12,   279,   284,   285,   288,  -849,
     289,   296,   299,   305,   306,   310,   311,   316,   317,   321,
     322,    12,   324,  -849,  -849,  -849,  -849,   325,  -849,   326,
     182,   184,   332,   333,   335,   336,   191,   339,   196,   341,
     344,   350,   351,   354,   357,   359,   360,   363,   364,   367,
     368,   372,   374,   375,   377,   379,   380,   384,   386,   388,
     389,  -849,  -849,  2175,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,   390,  -849,  -849,  -849,    13,   138,
      69,  -849,  -849,    -7,    10,  -849,  -849,  -849,    51,  -849,
      66,   425,  1222,  -849,  -849,    66,  1856,    66,   128,  -849,
    -849,  -849,  -849,  -849,  -849,   138,  -849,  2417,  2587,   408,
    -849,   875,  -849,  -849,  -849,   399,    25,  -849,  2054,  2296,
    2296,  2296,  -849,   346,  -849,  -849,  -849,  -849,   482,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
      13,  -849,  2054,  2054,  2054,  -849,  -849,  2054,  -849,  -849,
    2054,  2054,  2054,  2054,  -849,  2054,  2054,  2054,  2054,   -65,
    2054,  2054,  2054,  2054,  2054,  2054,  -849,   421,   421,  2054,
    -849,  -849,  2054,  2054,  2054,  2054,  -849,  2054,  -849,  2054,
    2054,  2054,  2054,  2054,  2054,  2054,  2054,  2054,  2054,  2054,
    2054,  2054,  2054,  2054,  2054,  2054,  2054,  2054,  2054,  2054,
    2054,  -849,   421,   421,  -849,  -849,  -849,   464,  -849,  -849,
     128,  -849,  -849,   260,  -849,  1111,  -849,  -849,  2441,  -849,
    -849,   337,  -849,  -849,   293,  -849,  -849,  -849,  -849,   392,
    1856,  -849,  -849,   405,   436,  -849,  -849,  -849,  -849,  -849,
    1751,  -849,  -849,  -849,  -849,  -849,  2054,  2417,  -849,  -849,
    -849,  -849,  2587,  -849,  -849,  -849,  -849,  -849,   427,   101,
    -849,  -849,  -849,  -849,   416,  -849,  -849,  -849,   411,   417,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,     6,   415,  -849,
    -849,  -849,   -65,  -849,   422,   412,   404,  2054,  2054,  2054,
    2054,  2054,  2054,   398,    12,  -849,  -849,   348,    49,  -849,
    -849,  -849,   428,   430,   432,  -849,   418,   420,   431,   433,
      -7,   435,   437,   438,   439,   442,   440,   443,   444,   449,
     450,   445,  -849,  1397,  2054,   454,   455,   457,   459,   467,
     468,   469,   471,   474,   487,   483,   489,   494,   502,   496,
     504,   505,   508,   503,   509,   512,   514,   515,   518,   513,
     522,   524,   526,  2054,  2054,  -849,  -849,    65,  -849,  -849,
    -849,  2465,  -849,  -849,   395,  -849,  -849,  -849,  -849,  -849,
    -849,  2465,  -849,  -849,   419,  -849,    20,  -849,    -5,  -849,
    -849,  -849,  -849,  -849,  1222,   137,  -849,  -849,   346,  -849,
    -849,  1691,   406,   409,  -849,  -849,   541,   543,    42,   132,
    -849,   290,  1807,  -849,  -849,  1908,    42,    42,   104,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  2054,  -849,  2054,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,    12,  -849,  2054,  2054,
      49,  -849,  -849,  -849,  2054,  2054,  -849,    -7,  -849,  -849,
    -849,  -849,  2054,  2054,  2054,  2054,  -849,  -849,  -849,  2054,
    -849,  -849,  2054,  -849,  -849,  -849,  -849,  2054,  -849,  -849,
     535,   528,  -849,  -849,  2054,  2054,  -849,  -849,  -849,  -849,
    -849,  -849,  2054,  -849,  -849,  -849,  2054,  -849,  -849,  -849,
    2054,  -849,  -849,  -849,  -849,  -849,  2054,  -849,  -849,  -849,
     537,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,   -43,
    -849,  -849,  -849,   -21,  -849,  -849,  -849,   533,   536,  -849,
    -849,   548,  -849,  -849,  1691,  -849,   550,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,    61,  -849,    77,
      81,   544,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
      38,  -849,  -849,  -849,  -849,  -849,   -15,  -849,  -849,  2587,
     557,    -7,  -849,   405,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  1832,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,    29,   551,   559,
     561,   555,   563,   565,   564,  -849,   531,  -849,   580,   581,
     583,   584,   564,   585,   586,  -849,  -849,  -849,  -849,  -849,
    1111,  -849,  -849,  2441,    66,  -849,  1856,  -849,   562,  -849,
    -849,  -849,   587,   -13,  -849,   152,  -849,  -849,  -849,  -849,
    -849,  1908,   527,   566,  -849,  -849,  -849,  -849,  -849,   592,
    -849,  -849,  -849,    -7,  -849,  -849,  2054,  -849,  1807,    -7,
    -849,  -849,  1139,  -849,  2054,  -849,  2054,  -849,  -849,  2054,
    -849,  -849,  -849,   591,   578,  -849,  -849,  -849,  -849,   593,
    -849,  -849,    67,  2402,  -849,  -849,  -849,  -849,  1856,  -849,
    -849,  -849,  -849,   594,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,    61,  -849,    61,  -849,   138,   137,  -849,  -849,    -7,
     554,  -849,  -849,  -849,  -849,  -849,   597,   564,  -849,   -97,
    -849,  -849,  -849,  -849,   598,    16,  -849,  1222,  -849,   538,
     596,   599,  -849,  -849,   108,  -849,    53,  -849,   -65,   602,
    -849,   608,  -849,  -849,  -849,  2465,  2465,  2465,   603,   -13,
    -849,    42,  -849,  1908,  -849,  -849,    -7,   137,   610,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,    -7,  -849,    -7,  1856,  -849,  -849,  -849
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        12,     0,     0,     2,     4,     3,   200,    14,    13,    10,
      68,     1,   184,   184,   184,   184,    74,     0,    74,     0,
     184,   184,     0,     0,   184,     0,   162,     6,     0,     7,
       8,     9,   164,   172,   173,   174,   178,   175,   176,   177,
     179,   180,   181,   182,   201,     0,    16,   185,     0,     0,
       0,     0,   224,     0,   101,   102,   109,   607,   610,   609,
     442,   443,   108,    74,   106,   440,   441,   608,   120,   199,
     215,   215,   197,   224,   196,   215,   195,   281,     5,   163,
     160,    83,    74,   200,     0,     0,   206,   202,   205,    69,
      11,    15,   187,     0,   220,   219,   221,   218,   189,   191,
     190,     0,   226,     0,     0,    75,    74,   107,   110,   121,
     123,     0,   216,   213,     0,     0,     0,     0,     0,   161,
     279,     0,   280,     0,    81,    82,    84,     0,   120,   171,
     165,   167,   208,   209,     0,   204,   203,     0,     0,    17,
      22,    18,     0,   188,   183,   217,   222,   418,   419,   420,
     421,   422,   415,   601,   602,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   603,   605,   604,   606,   611,   612,
     449,   231,   227,   239,   335,   414,   413,   424,     0,   333,
     438,   439,   445,   446,   589,   590,   591,   447,   587,   444,
     448,     0,   113,   114,   115,   116,   118,   123,   120,   123,
     111,     0,   112,   125,   124,   245,   242,   119,   241,   215,
     214,   215,   223,   215,   282,   289,   291,     0,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   561,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   572,   573,   574,   575,     0,   576,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    99,    80,    95,    93,    89,   551,   514,
     516,   552,   553,    94,     0,    90,    91,    92,     0,   123,
      12,   168,   169,     0,     0,   207,    70,    20,     0,   186,
       0,   225,   226,   240,   237,   338,   423,     0,     0,   585,
     586,   588,   583,   117,   104,   123,   105,     0,     0,   127,
     126,   248,   192,   194,   193,     0,     0,   298,     0,     0,
       0,     0,   497,    86,   450,   453,   457,   459,   461,   471,
     482,   485,   490,   491,   492,   498,   493,   494,   495,   496,
     581,   564,     0,     0,     0,   555,   507,     0,   330,   541,
       0,     0,     0,     0,   562,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   513,   325,   325,     0,
     534,   535,     0,     0,     0,     0,   508,     0,   533,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,   325,   325,   322,   321,    73,   200,   166,   198,
       0,   210,   211,     0,    56,     0,    31,    45,     0,    19,
      23,     0,    29,    24,     0,    43,    25,    26,   348,     0,
     423,   347,   232,   228,     0,   238,   336,   337,   339,   435,
     423,   425,   434,   334,   584,   103,     0,   131,   132,   135,
     137,   134,   138,   139,   141,   320,   318,   319,     0,   129,
     128,   429,   243,    77,     0,   244,   251,   249,   255,     0,
     356,   428,   427,   354,   284,   292,   290,     0,     0,   488,
     489,   487,     0,    87,     0,   451,   455,     0,     0,     0,
       0,     0,     0,     0,     0,   460,   462,   472,   484,   582,
     580,   565,     0,     0,     0,   331,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   326,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   212,    71,     0,   304,    35,
     305,    36,    32,    33,     0,   306,   301,   302,   303,   300,
      49,    50,    46,    47,     0,    29,     0,    43,     0,   416,
     345,   351,   353,   229,   226,     0,   417,   426,    86,   133,
     140,     0,     0,     0,   122,   130,   154,   156,     0,     0,
     246,   310,   248,   256,   253,   423,   359,     0,     0,   288,
     295,   297,   299,   499,    85,    88,     0,   454,     0,   458,
     463,   464,   465,   466,   467,   468,     0,   469,     0,     0,
     477,   483,   473,   474,     0,     0,   486,     0,   505,   506,
     554,   328,     0,     0,     0,     0,   563,   500,   501,     0,
     503,   504,     0,   546,   547,   548,   549,     0,   570,   571,
       0,   578,   550,   536,     0,     0,   525,   540,   532,   531,
     512,   539,     0,   530,   511,   529,     0,   538,   528,   519,
       0,   510,   527,   518,   509,   517,     0,   515,   537,   526,
       0,   323,    55,    58,    57,    34,    39,    48,    53,     0,
      28,    37,    30,     0,    42,    51,    44,   340,   349,   230,
     234,     0,   147,   148,   142,   143,     0,   145,   146,   150,
     151,   158,   159,   152,   155,   153,   157,     0,   397,     0,
       0,     0,   361,   363,   364,   372,   379,   382,   391,   386,
     389,   373,   396,    78,   269,   273,   281,   267,   307,     0,
       0,     0,   252,   228,   265,   258,   260,   261,   263,   264,
     259,   257,   311,   262,   254,   437,   423,   432,   436,   357,
     358,   360,   355,   283,   285,   286,   293,   452,   456,   470,
     479,   480,   478,   481,   475,   476,   566,     0,     0,     0,
       0,     0,     0,     0,   557,   567,     0,   579,     0,     0,
       0,     0,   557,     0,     0,   568,   328,    63,    40,    27,
       0,    54,    41,     0,   342,   346,   423,   352,     0,   136,
     144,   149,     0,   406,   409,     0,   398,   400,   408,   392,
     430,   423,   380,   384,   394,   395,   393,   388,   390,   120,
     270,   274,   278,     0,   308,   317,     0,   266,   248,     0,
     431,   433,     0,   332,     0,   329,     0,   543,   544,     0,
     502,   545,   558,     0,     0,   569,   523,   524,   520,     0,
     521,   522,     0,     0,    38,    52,   343,   344,   423,   350,
     235,   399,   407,     0,   403,   412,   410,   411,   370,   376,
     378,     0,   383,     0,   387,   123,     0,   275,   268,     0,
       0,   250,   315,   296,   294,   327,     0,   557,   556,     0,
     559,   324,    59,    64,    60,     0,   341,   226,   401,   405,
     362,   374,   381,   385,   162,   271,   184,   309,     0,   312,
     542,     0,   577,    61,    62,     0,     0,     0,     0,     0,
     404,   367,   371,   423,   377,    79,     0,     0,     0,   313,
     316,   560,    67,    66,    65,   236,   402,   365,   368,   369,
     375,   272,     0,   277,     0,   423,   276,   314,   366
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -849,  -849,  -849,  -849,  -849,  -849,   352,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,    58,  -849,   215,  -849,
    -169,  -849,  -849,    84,  -849,  -849,    70,  -849,   218,  -849,
    -170,  -849,  -849,    75,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,    46,
    -849,  -849,  -849,  -849,    50,  -849,  -849,  -849,    60,  -849,
     387,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -150,   -98,  -849,  -181,  -849,
    -849,  -849,  -849,  -849,  -849,   204,  -849,  -849,   201,  -849,
    -849,   -62,  -849,  -849,  -849,  -849,  -849,  -849,    57,    59,
    -268,  -849,  -849,   378,  -849,  -849,  -849,  -849,  -849,   601,
    -849,    -9,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
     590,  -849,  -849,   -36,  -849,     8,   628,   270,   655,   609,
    -849,  -298,   -92,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -277,  -849,  -849,  -849,  -849,  -614,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,   -80,  -849,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -431,  -849,  -849,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -583,  -107,   327,  -849,  -327,  -753,  -136,  -224,
    -849,  -849,  -849,  -849,  -849,  -849,  -242,  -849,  -849,  -849,
    -849,  -143,  -848,  -849,  -849,  -144,  -849,  -849,  -849,  -849,
    -849,  -491,  -849,  -267,  -849,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -849,  -849,  -266,   -52,  -849,  -849,  -849,  -215,
    -849,  -849,   -51,  -849,  -212,  -849,  -849,  -849,  -849,  -849,
    -849,  -849,  -803,  -849,  -101,  -849,  -849,  -849,  -849,  -299,
    -849,  -310,  -849,  -849,  -849,  -849,  -289,  -601,   -93,   -14,
      32,  -849,   757,  -849,  -849,  -849,    62,  -849,  -849,    64,
    -849,  -849,  -849,   107,  -849,  -849,    71,  -849,  -849,  -849,
    -424,  -849,  -437,    48,  -309,  -114,  -849,  -849,  -780,  -849,
    -849,  -849,  -849,  -849,  -849,  -849,  -849,   -91,  -849,  -849,
    -849,  -849,  -849,  -849,   -68,  -849,  -849,  -849,   250,  -849,
     186,   187,   400,  -223,   -17,  -849,  -849
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,    26,     5,     6,     7,    46,    90,
     139,   308,   140,   141,   439,   440,   596,   441,   442,   581,
     582,   722,   830,   583,   829,   443,   598,   444,   445,   591,
     592,   726,   833,   593,   832,   446,   577,   714,   827,   954,
     933,   893,   934,     8,    91,   137,   433,    27,    28,    53,
     482,   483,   619,   859,    82,   126,   127,   503,   504,   281,
     282,   283,   284,    29,    54,   106,    30,    62,    63,   199,
      31,   105,   192,   193,   194,   195,   110,   111,   202,   203,
     329,   479,   614,   204,   467,   468,   330,   472,   473,   480,
     734,   735,   736,   737,   738,   615,   743,   745,   616,   617,
      78,    79,    80,     9,    83,   301,   302,   129,   130,    32,
      33,    48,   143,   144,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,   135,    86,   134,    87,
      88,   305,   431,   114,   115,    97,    98,    55,    74,   101,
     102,   171,   604,   452,   311,   453,   454,   838,   937,   172,
     313,   314,   207,   484,   208,   331,   485,   486,   772,   621,
     487,   623,   624,   773,   774,   775,   863,   776,   860,   916,
     966,   777,   861,   917,   946,   778,   779,   119,   120,   121,
     335,   628,   794,   122,   123,   336,   217,   872,   632,   796,
     497,   584,   780,   864,   919,   781,   782,   869,   970,   984,
     949,   783,   474,   475,   425,   826,   543,   882,   807,   369,
     661,   173,   317,   315,   456,   457,   449,   896,   897,   835,
     727,   450,   600,   837,   728,   601,   488,   627,   626,   789,
     790,   751,   851,   752,   978,   985,   979,   962,   940,   753,
     754,   908,   964,   941,   909,   755,   756,   912,   852,   757,
     914,   853,   758,   857,   759,   858,   760,   846,   960,   939,
     902,   903,   847,   906,   459,   175,   310,   176,   177,   178,
     460,   785,   491,   618,   492,   786,   602,   910,   462,   451,
     342,   181,   343,   344,   637,   505,   345,   639,   506,   346,
     347,   515,   516,   348,   349,   650,   656,   803,   651,   517,
     350,   518,   351,   352,   353,   354,   366,   288,   883,   289,
     290,   291,   374,   530,   292,   521,   657,   355,   680,   294,
     817,   818,   356,   520,   357,   320,   321,   322,   358,   184,
     185,   186,   359,   188,   360,    67,   190
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int SPARQLfedParser::yytable_ninf_ = -424;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        66,   174,    69,    64,    49,    50,    51,   594,   784,   179,
     200,    70,    71,   287,   455,    75,   324,   386,   326,   476,
     285,   490,    56,   191,   787,  -287,   429,   461,   739,   205,
     299,    92,   489,   430,   182,   116,   293,   844,   724,   118,
     904,   323,   889,   629,   318,    66,   630,   215,   107,    65,
     936,   364,   367,   423,   875,   103,   303,   854,    99,   295,
     721,   544,   112,   720,    68,    47,   495,   103,   654,  -120,
     873,   955,   109,   458,   103,   463,   145,   874,   164,   165,
     166,   167,   747,     1,   104,   189,   196,   434,   845,    10,
     -21,   109,   748,    11,    65,   573,   574,    89,   210,   855,
     325,   747,   712,    84,    85,   713,   749,   828,   931,   108,
     298,   748,   655,   124,   125,   874,   448,   843,   426,    60,
      61,   747,    52,   721,   304,   749,    73,   844,   128,   612,
     613,   748,   831,   725,   180,   791,   792,   988,    77,   875,
     856,   793,   319,   750,   465,   749,   578,   951,    81,   725,
     309,   739,   198,   214,   435,   206,   976,   -21,   447,   286,
     594,   113,   750,   476,   956,   957,    57,    58,    59,   287,
      93,   607,  -287,   332,   196,   333,   285,   334,   845,    57,
      58,    59,    57,    58,    59,   871,   865,    60,    61,    57,
      58,    59,   293,   631,   216,  -120,    85,   795,   365,   368,
     424,   436,   905,   437,   -21,   438,   -21,   142,   -21,    60,
      61,   174,   146,   471,   477,   295,   138,   804,   805,   179,
     469,    57,    58,    59,   800,   801,    60,    61,   209,   201,
      57,    58,    59,   -21,   -21,   -21,   211,   212,   493,   300,
      57,    58,    59,   306,   182,    57,    58,    59,   182,   307,
      60,    61,   213,   666,   921,   312,    57,    58,    59,   316,
      57,    58,    59,   182,   327,   328,   298,   580,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    57,    58,    59,    93,   432,    60,    61,
     647,   196,    72,    66,   337,   189,   764,   765,    66,   189,
      66,   464,   476,    94,   361,   362,   729,    57,    58,    59,
     298,   298,   490,   363,   189,   286,    57,    58,    59,   370,
     766,    60,    61,   489,   371,   372,   489,  -247,   373,   375,
    -170,    57,    58,    59,   767,   768,   376,   769,    12,   377,
      13,    14,    65,    15,   180,   378,   379,    65,   180,    65,
     380,   381,   183,   471,   132,   133,   382,   383,   477,   470,
     469,   384,   385,   180,   387,   388,   389,   586,   496,   390,
     586,   391,   392,   393,   197,   394,   395,   296,   396,   397,
     806,   399,   182,   398,   400,    95,    96,   499,   500,   501,
     401,   402,   182,    12,   403,    13,    14,   404,    15,   405,
     406,   -72,   594,   407,   408,    16,    17,   409,   410,   648,
     649,   535,   411,   575,   412,   413,   770,   414,   589,   415,
     416,   589,   799,    18,   417,   476,   418,   841,   419,   420,
     422,  -233,   478,   189,    19,   494,   502,   771,   542,   576,
     435,   924,   605,   189,   599,    20,    21,   438,   603,    22,
     298,    23,   611,   620,   622,   298,   633,   625,   638,    24,
     476,    25,   935,   635,   646,   636,   662,   585,   663,   658,
     585,   659,    12,   660,    13,    14,   667,    15,   668,   664,
     670,   665,   180,   671,   673,   674,   669,   489,   672,    19,
     675,   676,   180,   677,   867,   682,   683,   477,   716,   470,
      20,    21,   187,   174,    22,   684,    23,   685,   686,   687,
     688,   179,   689,   586,    24,   690,    25,   158,   159,   160,
     161,   162,   163,   586,   972,   973,   974,   297,   691,   493,
     693,   692,   788,   296,   634,   694,   182,   507,   508,   509,
     510,   511,   512,   695,   696,   697,   698,   513,   514,   699,
     701,   700,   489,   702,   182,   703,   704,   182,   490,   705,
     586,   706,   183,   707,   589,   708,   183,   709,    19,   489,
     613,   612,   741,   718,   589,   742,   815,   816,   825,    20,
      21,   183,   834,    22,   836,    23,   918,   189,    66,   839,
     338,   730,   922,    24,   298,    25,   850,   866,   900,   876,
     877,   762,   878,   879,   880,   189,   881,   884,   189,   762,
     762,   589,   874,   585,   640,   641,   642,   643,   644,   645,
     477,   885,   886,   585,   887,   888,   890,   891,   901,   913,
     911,   109,   928,   929,   930,   938,   180,    65,   950,   958,
     975,   959,   947,   740,   948,   961,   953,   963,   969,   971,
     761,   983,   427,   719,   180,   477,   595,   180,   761,   761,
     585,   894,   597,   895,   489,   715,   717,   723,   731,   763,
     421,   609,   840,   610,   746,   744,   965,   136,   428,   100,
      76,   868,   117,   297,   131,   587,   862,   519,   587,   981,
     892,   898,   899,   788,   977,   842,   942,   980,   797,   849,
     183,   943,   798,   652,   653,   986,   952,   987,     0,     0,
     183,     0,   187,     0,     0,     0,   187,   298,   182,     0,
       0,   802,     0,     0,     0,     0,     0,     0,     0,     0,
     762,   187,   848,   762,   944,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   298,     0,     0,     0,     0,     0,   788,     0,
       0,   915,   586,     0,     0,   586,   740,     0,   182,   189,
       0,     0,     0,     0,     0,   493,     0,     0,     0,     0,
       0,     0,     0,   182,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,     0,     0,     0,   586,     0,     0,     0,     0,     0,
       0,     0,     0,   589,     0,     0,   589,    66,   180,   189,
       0,     0,     0,     0,     0,   586,   848,     0,   907,     0,
     182,   587,     0,     0,   189,   588,   174,     0,   588,     0,
       0,   587,     0,     0,   179,     0,     0,     0,     0,     0,
     187,   189,     0,     0,   183,   589,     0,     0,     0,     0,
     187,     0,   585,     0,     0,   585,    65,     0,   180,   182,
     788,     0,   183,     0,     0,   183,   589,     0,   587,     0,
       0,   189,     0,   180,     0,     0,     0,   586,   586,   586,
       0,   -76,     0,     0,   762,   182,   762,     0,     0,    66,
     180,     0,   945,     0,   585,     0,   147,   148,   149,   150,
     151,     0,     0,     0,     0,  -423,     0,   182,     0,     0,
     189,     0,     0,     0,     0,   585,   481,     0,     0,     0,
     180,     0,     0,     0,     0,     0,     0,   967,   589,   589,
     589,     0,   848,     0,   762,     0,   189,     0,    65,     0,
      66,     0,     0,   982,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   189,   180,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     968,   588,     0,     0,     0,     0,     0,   585,   585,   585,
       0,   588,     0,   761,     0,   180,     0,     0,     0,    65,
       0,     0,     0,     0,   187,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   180,     0,     0,
       0,     0,   187,     0,     0,   187,     0,     0,   588,     0,
       0,     0,     0,     0,     0,     0,   183,     0,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    57,    58,    59,   168,   169,    60,
      61,     0,   170,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     587,     0,     0,   587,     0,     0,   183,     0,     0,     0,
       0,     0,     0,     0,     0,   498,     0,     0,     0,     0,
       0,   183,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   183,   522,
     523,   524,   587,     0,   525,     0,     0,   526,   527,   528,
     529,     0,   531,   532,   533,   534,     0,   536,   537,   538,
     539,   540,   541,   587,     0,     0,   545,     0,   183,   546,
     547,   548,   549,   578,   550,     0,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,     0,     0,
     923,   578,     0,     0,     0,     0,   187,   183,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   587,   587,   587,     0,     0,
       0,     0,     0,   183,   579,     0,     0,     0,     0,     0,
       0,     0,     0,   608,     0,     0,     0,     0,     0,     0,
     588,     0,     0,   588,     0,   183,   187,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   187,     0,   147,   148,   149,   150,   151,     0,     0,
       0,     0,  -423,     0,     0,     0,     0,     0,   187,     0,
       0,     0,   588,   152,   580,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      57,    58,    59,   588,     0,    60,    61,     0,   187,     0,
     679,   681,   580,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    57,    58,
      59,     0,     0,    60,    61,     0,     0,     0,     0,     0,
     710,   711,     0,     0,     0,     0,     0,   187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   588,   588,   588,     0,     0,
       0,     0,     0,   187,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   187,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    57,    58,    59,   168,   169,    60,    61,     0,   170,
       0,     0,     0,     0,     0,     0,   678,     0,     0,   808,
     809,   810,   811,     0,     0,     0,   812,     0,     0,   813,
       0,     0,     0,     0,   814,     0,     0,   338,     0,     0,
       0,   819,   820,     0,     0,     0,     0,     0,     0,   821,
       0,     0,     0,   822,     0,     0,     0,   823,   339,   340,
       0,   341,   220,   824,   221,   222,   223,   224,   225,   226,
     227,   228,   229,     0,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,   241,     0,     0,     0,
     242,   243,   244,   245,   246,   247,   248,   249,     0,     0,
       0,     0,     0,     0,     0,   250,   251,   252,     0,   253,
     254,   255,     0,     0,   256,   257,     0,   258,     0,   259,
     260,   261,   262,     0,   263,   264,     0,   265,     0,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    57,    58,    59,     0,
       0,    60,    61,     0,     0,     0,     0,     0,     0,   218,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   920,     0,     0,     0,     0,     0,     0,
       0,   925,     0,   926,     0,   220,   927,   221,   222,   223,
     224,   225,   226,   227,   228,   229,     0,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,     0,   241,
       0,     0,     0,   242,   243,   244,   245,   246,   247,   248,
     249,     0,     0,     0,     0,     0,     0,     0,   250,   251,
     252,     0,   253,   254,   255,     0,     0,   256,   257,     0,
     258,     0,   259,   260,   261,   262,     0,   263,   264,     0,
     265,     0,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   732,   733,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   338,     0,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    57,
      58,    59,     0,     0,    60,    61,   220,     0,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
     241,     0,   147,   148,   149,   150,   151,     0,     0,     0,
       0,   249,   606,     0,     0,     0,     0,     0,     0,   250,
     251,   252,   152,   253,   254,   255,     0,     0,   256,   257,
       0,   258,     0,   259,   260,   261,   262,     0,   263,   264,
       0,   265,     0,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   147,   148,
     149,   150,   151,     0,     0,     0,     0,  -423,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   481,     0,
       0,     0,     0,   147,   148,   149,   150,   151,     0,     0,
      57,    58,    59,   870,     0,    60,    61,     0,     0,     0,
       0,     0,     0,   481,     0,     0,     0,   147,   148,   149,
     150,   151,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   152,     0,     0,
       0,     0,     0,     0,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      57,    58,    59,   168,   169,    60,    61,     0,   170,   147,
     148,   149,   150,   151,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   481,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    57,    58,    59,   168,
     169,    60,    61,     0,   170,     0,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    57,    58,    59,   168,   169,    60,    61,     0,   170,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    57,    58,    59,   168,   169,
      60,    61,     0,   170,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    57,    58,    59,
     168,   169,    60,    61,   338,   170,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   339,   340,     0,   341,   220,
       0,   221,   222,   223,   224,   225,   226,   227,   228,   229,
       0,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,     0,   241,     0,     0,     0,   242,   243,   244,
     245,   246,   247,   248,   249,     0,     0,     0,     0,     0,
       0,     0,   250,   251,   252,     0,   253,   254,   255,     0,
       0,   256,   257,     0,   258,     0,   259,   260,   261,   262,
       0,   263,   264,     0,   265,     0,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   219,     0,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    57,    58,    59,     0,     0,    60,    61,
     220,     0,   221,   222,   223,   224,   225,   226,   227,   228,
     229,     0,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,   241,     0,     0,     0,   242,   243,
     244,   245,   246,   247,   248,   249,     0,     0,     0,     0,
       0,     0,     0,   250,   251,   252,     0,   253,   254,   255,
       0,     0,   256,   257,     0,   258,     0,   259,   260,   261,
     262,     0,   263,   264,     0,   265,     0,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   338,     0,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    57,    58,    59,     0,     0,    60,
      61,   220,     0,   221,   222,   223,   224,   225,   226,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     0,   241,     0,     0,     0,   242,
     243,   244,   245,   246,   247,   248,   249,     0,     0,     0,
       0,     0,     0,     0,   250,   251,   252,     0,   253,   254,
     255,     0,     0,   256,   257,     0,   258,     0,   259,   260,
     261,   262,     0,   263,   264,     0,   265,     0,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   932,   578,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   466,     0,     0,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    57,    58,    59,     0,     0,
      60,    61,   220,   578,   221,   222,   223,   224,   225,   226,
     227,   228,   229,     0,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,   241,   578,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   249,     0,     0,
       0,     0,     0,     0,     0,   250,   251,   252,     0,   253,
     254,   255,     0,     0,   256,   257,     0,   258,     0,   259,
     260,   261,   262,     0,   263,   264,     0,   265,     0,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,     0,   580,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    57,    58,    59,     0,     0,    60,    61,     0,     0,
       0,     0,     0,     0,     0,   590,    57,    58,    59,     0,
       0,    60,    61,     0,   580,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      57,    58,    59,     0,     0,    60,    61,   338,   580,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    57,    58,    59,     0,     0,    60,
      61,     0,   220,     0,   221,   222,   223,   224,   225,   226,
     227,   228,   229,     0,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,   241,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   249,     0,     0,
       0,     0,     0,     0,     0,   250,   251,   252,     0,   253,
     254,   255,     0,     0,   256,   257,     0,   258,     0,   259,
     260,   261,   262,     0,   263,   264,     0,   265,     0,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    57,    58,    59
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        17,   102,    19,    17,    13,    14,    15,   438,   622,   102,
     108,    20,    21,   127,   312,    24,   197,   241,   199,   328,
     127,   331,    19,    23,   625,    40,   303,   316,   611,    36,
     128,    48,   331,    23,   102,    71,   127,    50,    43,    75,
     843,   191,   822,    37,    88,    62,    40,    40,    62,    17,
     898,    40,    40,    40,   807,    22,    39,    19,    50,   127,
     103,   388,     6,    43,    18,    12,    41,    22,    19,    36,
      41,    55,    39,   315,    22,   317,    93,    48,   175,   176,
     177,   178,    40,    14,    39,   102,   103,    36,   101,   179,
      36,    39,    50,     0,    62,   422,   423,    15,   115,    61,
     198,    40,    37,     3,     4,    40,    64,   150,    41,    63,
     127,    50,    63,    17,    18,    48,    50,    40,   299,   184,
     185,    40,    36,   103,   107,    64,    36,    50,    82,    28,
      29,    50,   153,   154,   102,   626,   627,   985,    30,   892,
     102,    37,   186,   101,   325,    64,    42,   927,    16,   154,
     142,   734,   106,   121,   103,   162,   959,   103,   308,   127,
     591,   105,   101,   472,   148,   149,   179,   180,   181,   283,
       6,   460,   187,   209,   191,   211,   283,   213,   101,   179,
     180,   181,   179,   180,   181,   786,   769,   184,   185,   179,
     180,   181,   283,   187,   187,   162,     4,   628,   187,   187,
     187,   150,    50,   152,   150,   154,   152,     9,   154,   184,
     185,   312,    37,   327,   328,   283,   162,   654,   655,   312,
     327,   179,   180,   181,   648,   649,   184,   185,   111,    91,
     179,   180,   181,   179,   180,   181,   111,    37,   331,    49,
     179,   180,   181,   180,   312,   179,   180,   181,   316,    55,
     184,   185,   111,   530,   868,    43,   179,   180,   181,    40,
     179,   180,   181,   331,    25,    92,   283,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,     6,   304,   184,   185,
     514,   308,    22,   310,    36,   312,     6,     7,   315,   316,
     317,   318,   611,    23,    75,    40,   604,   179,   180,   181,
     327,   328,   622,    40,   331,   283,   179,   180,   181,    40,
      30,   184,   185,   622,    40,    40,   625,    37,    40,    40,
       0,   179,   180,   181,    44,    45,    40,    47,     8,    40,
      10,    11,   310,    13,   312,    40,    40,   315,   316,   317,
      40,    40,   102,   467,    84,    85,    40,    40,   472,   327,
     467,    40,    40,   331,    40,    40,    40,   435,   336,   187,
     438,   187,    40,    40,   104,    40,    40,   127,   187,    40,
     657,    40,   450,   187,    40,   105,   106,   339,   340,   341,
      40,    40,   460,     8,    40,    10,    11,    40,    13,    40,
      40,    16,   833,    40,    40,    20,    21,    40,    40,    61,
      62,   379,    40,   430,    40,    40,   126,    40,   435,    40,
      40,   438,   646,    38,    40,   734,    40,   736,    40,    40,
      40,     6,    24,   450,   104,    36,    90,   147,    17,   179,
     103,   872,     6,   460,    52,   115,   116,   154,    43,   119,
     467,   121,    25,    37,    43,   472,    41,    40,    54,   129,
     769,   131,   893,    41,    66,    53,    48,   435,    48,    41,
     438,    41,     8,    41,    10,    11,    41,    13,    41,    48,
      41,    48,   450,    41,    41,    41,    48,   786,    48,   104,
      41,    41,   460,    48,   771,    41,    41,   611,   103,   467,
     115,   116,   102,   604,   119,    48,   121,    48,    41,    41,
      41,   604,    41,   581,   129,    41,   131,   169,   170,   171,
     172,   173,   174,   591,   955,   956,   957,   127,    41,   622,
      41,    48,   625,   283,   502,    41,   604,    55,    56,    57,
      58,    59,    60,    41,    48,    41,    41,    65,    66,    41,
      41,    48,   851,    41,   622,    41,    41,   625,   868,    41,
     628,    48,   312,    41,   581,    41,   316,    41,   104,   868,
      29,    28,   166,   154,   591,   166,    41,    49,    41,   115,
     116,   331,    49,   119,    48,   121,   863,   604,   605,    41,
      40,   605,   869,   129,   611,   131,    52,    40,    36,    48,
      41,   618,    41,    48,    41,   622,    41,    76,   625,   626,
     627,   628,    48,   581,   507,   508,   509,   510,   511,   512,
     734,    41,    41,   591,    41,    41,    41,    41,    41,    63,
     103,    39,    41,    55,    41,    41,   604,   605,    41,   937,
      37,   103,   919,   611,    90,    49,    48,    48,    46,    41,
     618,    41,   300,   595,   622,   769,   441,   625,   626,   627,
     628,   830,   444,   833,   963,   581,   591,   597,   608,   619,
     283,   467,   734,   472,   617,   616,   944,    87,   300,    51,
      25,   773,    73,   283,    83,   435,   766,   360,   438,   966,
     826,   834,   836,   786,   961,   747,   911,   963,   636,   750,
     450,   913,   638,   517,   517,   982,   929,   984,    -1,    -1,
     460,    -1,   312,    -1,    -1,    -1,   316,   734,   786,    -1,
      -1,   650,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     747,   331,   749,   750,   915,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   769,    -1,    -1,    -1,    -1,    -1,   851,    -1,
      -1,   859,   830,    -1,    -1,   833,   734,    -1,   836,   786,
      -1,    -1,    -1,    -1,    -1,   868,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   851,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     868,    -1,    -1,    -1,   872,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   830,    -1,    -1,   833,   834,   786,   836,
      -1,    -1,    -1,    -1,    -1,   893,   843,    -1,   845,    -1,
     898,   581,    -1,    -1,   851,   435,   937,    -1,   438,    -1,
      -1,   591,    -1,    -1,   937,    -1,    -1,    -1,    -1,    -1,
     450,   868,    -1,    -1,   604,   872,    -1,    -1,    -1,    -1,
     460,    -1,   830,    -1,    -1,   833,   834,    -1,   836,   937,
     963,    -1,   622,    -1,    -1,   625,   893,    -1,   628,    -1,
      -1,   898,    -1,   851,    -1,    -1,    -1,   955,   956,   957,
      -1,    16,    -1,    -1,   911,   963,   913,    -1,    -1,   916,
     868,    -1,   916,    -1,   872,    -1,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    40,    -1,   985,    -1,    -1,
     937,    -1,    -1,    -1,    -1,   893,    51,    -1,    -1,    -1,
     898,    -1,    -1,    -1,    -1,    -1,    -1,   946,   955,   956,
     957,    -1,   959,    -1,   961,    -1,   963,    -1,   916,    -1,
     967,    -1,    -1,   967,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   985,   937,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     948,   581,    -1,    -1,    -1,    -1,    -1,   955,   956,   957,
      -1,   591,    -1,   961,    -1,   963,    -1,    -1,    -1,   967,
      -1,    -1,    -1,    -1,   604,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   985,    -1,    -1,
      -1,    -1,   622,    -1,    -1,   625,    -1,    -1,   628,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   786,    -1,    -1,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     830,    -1,    -1,   833,    -1,    -1,   836,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   338,    -1,    -1,    -1,    -1,
      -1,   851,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   868,   362,
     363,   364,   872,    -1,   367,    -1,    -1,   370,   371,   372,
     373,    -1,   375,   376,   377,   378,    -1,   380,   381,   382,
     383,   384,   385,   893,    -1,    -1,   389,    -1,   898,   392,
     393,   394,   395,    42,   397,    -1,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,    -1,    -1,
      41,    42,    -1,    -1,    -1,    -1,   786,   937,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   955,   956,   957,    -1,    -1,
      -1,    -1,    -1,   963,   103,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   466,    -1,    -1,    -1,    -1,    -1,    -1,
     830,    -1,    -1,   833,    -1,   985,   836,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   851,    -1,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,   868,    -1,
      -1,    -1,   872,    51,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   893,    -1,   184,   185,    -1,   898,    -1,
     543,   544,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,   184,   185,    -1,    -1,    -1,    -1,    -1,
     573,   574,    -1,    -1,    -1,    -1,    -1,   937,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   955,   956,   957,    -1,    -1,
      -1,    -1,    -1,   963,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   985,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,   187,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,   662,
     663,   664,   665,    -1,    -1,    -1,   669,    -1,    -1,   672,
      -1,    -1,    -1,    -1,   677,    -1,    -1,    40,    -1,    -1,
      -1,   684,   685,    -1,    -1,    -1,    -1,    -1,    -1,   692,
      -1,    -1,    -1,   696,    -1,    -1,    -1,   700,    61,    62,
      -1,    64,    65,   706,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    89,    -1,    -1,    -1,
      93,    94,    95,    96,    97,    98,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,    -1,   112,
     113,   114,    -1,    -1,   117,   118,    -1,   120,    -1,   122,
     123,   124,   125,    -1,   127,   128,    -1,   130,    -1,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,   184,   185,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   866,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   874,    -1,   876,    -1,    65,   879,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    -1,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    -1,    89,
      -1,    -1,    -1,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,    -1,   112,   113,   114,    -1,    -1,   117,   118,    -1,
     120,    -1,   122,   123,   124,   125,    -1,   127,   128,    -1,
     130,    -1,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,   184,   185,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    -1,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    -1,
      89,    -1,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,   100,    41,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,    51,   112,   113,   114,    -1,    -1,   117,   118,
      -1,   120,    -1,   122,   123,   124,   125,    -1,   127,   128,
      -1,   130,    -1,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    -1,    -1,
     179,   180,   181,    41,    -1,   184,   185,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,   187,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,   187,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,   187,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    40,   187,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    62,    -1,    64,    65,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      -1,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    89,    -1,    -1,    -1,    93,    94,    95,
      96,    97,    98,    99,   100,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,   109,   110,    -1,   112,   113,   114,    -1,
      -1,   117,   118,    -1,   120,    -1,   122,   123,   124,   125,
      -1,   127,   128,    -1,   130,    -1,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,   184,   185,
      65,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    89,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,    -1,   112,   113,   114,
      -1,    -1,   117,   118,    -1,   120,    -1,   122,   123,   124,
     125,    -1,   127,   128,    -1,   130,    -1,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,   184,
     185,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    -1,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    89,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    98,    99,   100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,   109,   110,    -1,   112,   113,
     114,    -1,    -1,   117,   118,    -1,   120,    -1,   122,   123,
     124,   125,    -1,   127,   128,    -1,   130,    -1,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,    -1,    -1,
     184,   185,    65,    42,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    89,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,    -1,   112,
     113,   114,    -1,    -1,   117,   118,    -1,   120,    -1,   122,
     123,   124,   125,    -1,   127,   128,    -1,   130,    -1,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,   184,   185,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   154,   179,   180,   181,    -1,
      -1,   184,   185,    -1,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,   184,   185,    40,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,   184,
     185,    -1,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,    -1,   112,
     113,   114,    -1,    -1,   117,   118,    -1,   120,    -1,   122,
     123,   124,   125,    -1,   127,   128,    -1,   130,    -1,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    14,   189,   190,   191,   193,   194,   195,   231,   291,
     179,     0,     8,    10,    11,    13,    20,    21,    38,   104,
     115,   116,   119,   121,   129,   131,   192,   235,   236,   251,
     254,   258,   297,   298,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   196,    12,   299,   299,
     299,   299,    36,   237,   252,   325,    19,   179,   180,   181,
     184,   185,   255,   256,   467,   468,   522,   523,   237,   522,
     299,   299,   325,    36,   326,   299,   326,    30,   288,   289,
     290,    16,   242,   292,     3,     4,   315,   317,   318,    15,
     197,   232,   522,     6,    23,   105,   106,   323,   324,   323,
     324,   327,   328,    22,    39,   259,   253,   467,   237,    39,
     264,   265,     6,   105,   321,   322,   321,   327,   321,   365,
     366,   367,   371,   372,    17,    18,   243,   244,   237,   295,
     296,   297,   325,   325,   316,   314,   318,   233,   162,   198,
     200,   201,     9,   300,   301,   522,    37,    31,    32,    33,
      34,    35,    51,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   182,   183,
     187,   329,   337,   399,   452,   453,   455,   456,   457,   466,
     468,   469,   512,   516,   517,   518,   519,   520,   521,   522,
     524,    23,   260,   261,   262,   263,   522,   325,   237,   257,
     264,    91,   266,   267,   271,    36,   162,   340,   342,   111,
     522,   111,    37,   111,   468,    40,   187,   374,    19,    40,
      65,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    89,    93,    94,    95,    96,    97,    98,    99,   100,
     108,   109,   110,   112,   113,   114,   117,   118,   120,   122,
     123,   124,   125,   127,   128,   130,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   247,   248,   249,   250,   391,   468,   493,   495,   497,
     498,   499,   502,   505,   507,   512,   516,   520,   522,   264,
      49,   293,   294,    39,   107,   319,   180,    55,   199,   323,
     454,   332,    43,   338,   339,   401,    40,   400,    88,   186,
     513,   514,   515,   263,   266,   264,   266,    25,    92,   268,
     274,   343,   321,   321,   321,   368,   373,    36,    40,    61,
      62,    64,   468,   470,   471,   474,   477,   478,   481,   482,
     488,   490,   491,   492,   493,   505,   510,   512,   516,   520,
     522,    75,    40,    40,    40,   187,   494,    40,   187,   397,
      40,    40,    40,    40,   500,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,   397,    40,    40,    40,
     187,   187,    40,    40,    40,    40,   187,    40,   187,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,   248,    40,    40,   187,   392,   266,   194,   291,   340,
      23,   320,   522,   234,    36,   103,   150,   152,   154,   202,
     203,   205,   206,   213,   215,   216,   223,   263,    50,   404,
     409,   467,   331,   333,   334,   329,   402,   403,   404,   452,
     458,   464,   466,   404,   522,   266,    40,   272,   273,   391,
     468,   493,   275,   276,   390,   391,   492,   493,    24,   269,
     277,    51,   238,   239,   341,   344,   345,   348,   414,   457,
     459,   460,   462,   466,    36,    41,   468,   378,   470,   491,
     491,   491,    90,   245,   246,   473,   476,    55,    56,    57,
      58,    59,    60,    65,    66,   479,   480,   487,   489,   392,
     511,   503,   470,   470,   470,   470,   470,   470,   470,   470,
     501,   470,   470,   470,   470,   468,   470,   470,   470,   470,
     470,   470,    17,   394,   394,   470,   470,   470,   470,   470,
     470,   470,   470,   470,   470,   470,   470,   470,   470,   470,
     470,   470,   470,   470,   470,   470,   470,   470,   470,   470,
     470,   470,   470,   394,   394,   522,   179,   224,    42,   103,
     163,   207,   208,   211,   379,   468,   512,   516,   520,   522,
     154,   217,   218,   221,   379,   206,   204,   216,   214,    52,
     410,   413,   464,    43,   330,     6,    41,   464,   470,   273,
     276,    25,    28,    29,   270,   283,   286,   287,   461,   240,
      37,   347,    43,   349,   350,    40,   416,   415,   369,    37,
      40,   187,   376,    41,   468,    41,    53,   472,    54,   475,
     481,   481,   481,   481,   481,   481,    66,   397,    61,    62,
     483,   486,   518,   519,    19,    63,   484,   504,    41,    41,
      41,   398,    48,    48,    48,    48,   340,    41,    41,    48,
      41,    41,    48,    41,    41,    41,    41,    48,    19,   470,
     506,   470,    41,    41,    48,    48,    41,    41,    41,    41,
      41,    41,    48,    41,    41,    41,    48,    41,    41,    41,
      48,    41,    41,    41,    41,    41,    48,    41,    41,    41,
     470,   470,    37,    40,   225,   211,   103,   221,   154,   204,
      43,   103,   209,   214,    43,   154,   219,   408,   412,   329,
     467,   246,    26,    27,   278,   279,   280,   281,   282,   390,
     468,   166,   166,   284,   287,   285,   286,    40,    50,    64,
     101,   419,   421,   427,   428,   433,   434,   437,   440,   442,
     444,   468,   522,   242,     6,     7,    30,    44,    45,    47,
     126,   147,   346,   351,   352,   353,   355,   359,   363,   364,
     380,   383,   384,   389,   345,   459,   463,   465,   466,   417,
     418,   419,   419,    37,   370,   379,   377,   474,   477,   397,
     488,   488,   484,   485,   490,   490,   340,   396,   470,   470,
     470,   470,   470,   470,   470,    41,    49,   508,   509,   470,
     470,   470,   470,   470,   470,    41,   393,   226,   150,   212,
     210,   153,   222,   220,    49,   407,    48,   411,   335,    41,
     279,   492,   433,    40,    50,   101,   445,   450,   522,   440,
      52,   420,   436,   439,    19,    61,   102,   441,   443,   241,
     356,   360,   365,   354,   381,   390,    40,   340,   330,   385,
      41,   465,   375,    41,    48,   395,    48,    41,    41,    48,
      41,    41,   395,   496,    76,    41,    41,    41,    41,   496,
      41,    41,   396,   229,   208,   218,   405,   406,   409,   413,
      36,    41,   448,   449,   450,    50,   451,   522,   429,   432,
     465,   103,   435,    63,   438,   264,   357,   361,   340,   382,
     470,   345,   340,    41,   379,   470,   470,   470,    41,    55,
      41,    41,    41,   228,   230,   379,   410,   336,    41,   447,
     426,   431,   437,   442,   266,   467,   362,   340,    90,   388,
      41,   496,   521,    48,   227,    55,   148,   149,   329,   103,
     446,    49,   425,    48,   430,   288,   358,   299,   468,    46,
     386,    41,   379,   379,   379,    37,   450,   421,   422,   424,
     432,   340,   467,    41,   387,   423,   340,   340,   410
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
     435,   436,   437,   438,   439,   440,   441,   442
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  SPARQLfedParser::yyr1_[] =
  {
         0,   188,   189,   189,   190,   191,   192,   192,   192,   192,
     193,   194,   195,   195,   196,   196,   197,   197,   199,   198,
     200,   201,   201,   202,   202,   202,   202,   203,   203,   204,
     204,   205,   206,   207,   207,   208,   208,   210,   209,   211,
     212,   213,   213,   214,   214,   215,   216,   217,   217,   218,
     218,   220,   219,   221,   222,   223,   224,   224,   226,   225,
     227,   227,   228,   229,   229,   230,   230,   230,   231,   233,
     234,   232,   236,   235,   237,   237,   239,   240,   241,   238,
     242,   243,   243,   244,   244,   245,   246,   246,   247,   248,
     248,   248,   248,   248,   248,   248,   248,   249,   249,   250,
     250,   251,   253,   252,   252,   254,   255,   255,   256,   256,
     257,   257,   258,   259,   260,   260,   261,   262,   263,   264,
     265,   265,   266,   267,   267,   268,   268,   269,   269,   270,
     270,   271,   272,   272,   273,   273,   273,   273,   274,   275,
     275,   276,   277,   278,   278,   279,   279,   280,   280,   281,
     282,   282,   283,   283,   284,   284,   285,   285,   286,   287,
     288,   289,   290,   290,   292,   291,   293,   294,   294,   295,
     296,   296,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   298,   299,   299,   300,   301,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   313,   314,   314,   315,   315,   316,   316,   317,   318,
     319,   320,   320,   321,   321,   322,   322,   323,   324,   324,
     324,   324,   325,   326,   328,   327,   329,   329,   330,   330,
     331,   332,   332,   334,   335,   336,   333,   337,   338,   339,
     339,   340,   340,   341,   341,   343,   342,   344,   345,   345,
     346,   347,   347,   348,   349,   350,   350,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   352,   354,   353,   356,
     357,   358,   355,   360,   361,   362,   359,   363,   364,   365,
     365,   367,   368,   366,   369,   369,   370,   372,   371,   373,
     373,   374,   374,   375,   375,   377,   376,   376,   378,   378,
     379,   379,   379,   379,   379,   379,   379,   381,   382,   380,
     384,   385,   383,   387,   386,   388,   388,   389,   390,   390,
     390,   391,   392,   393,   392,   394,   394,   395,   396,   396,
     397,   398,   397,   400,   399,   401,   399,   402,   403,   403,
     404,   405,   406,   406,   407,   408,   408,   409,   409,   410,
     411,   412,   412,   413,   415,   414,   416,   414,   417,   418,
     418,   420,   419,   421,   421,   423,   422,   424,   424,   425,
     426,   426,   427,   428,   429,   430,   431,   431,   432,   433,
     434,   435,   436,   436,   437,   438,   439,   439,   440,   441,
     441,   442,   442,   443,   443,   443,   444,   444,   444,   444,
     445,   445,   446,   447,   447,   448,   449,   449,   450,   450,
     450,   451,   451,   452,   452,   454,   453,   455,   456,   456,
     456,   456,   456,   457,   457,   458,   458,   459,   459,   461,
     460,   462,   463,   463,   464,   464,   465,   465,   466,   466,
     467,   467,   468,   468,   469,   469,   469,   469,   469,   469,
     470,   471,   472,   473,   473,   474,   475,   476,   476,   477,
     478,   479,   479,   480,   480,   480,   480,   480,   480,   480,
     480,   481,   482,   483,   483,   484,   484,   485,   485,   486,
     486,   486,   487,   487,   488,   489,   489,   490,   490,   490,
     490,   491,   491,   491,   491,   491,   491,   491,   491,   492,
     493,   493,   493,   493,   493,   493,   493,   493,   493,   493,
     493,   493,   493,   493,   493,   493,   493,   493,   493,   493,
     493,   493,   493,   493,   493,   493,   493,   493,   493,   493,
     493,   493,   493,   493,   493,   493,   493,   493,   493,   493,
     493,   493,   493,   493,   493,   493,   493,   493,   493,   493,
     493,   493,   493,   493,   494,   494,   495,   496,   496,   497,
     498,   500,   501,   499,   503,   504,   502,   505,   505,   505,
     506,   506,   507,   507,   507,   507,   507,   508,   509,   509,
     510,   511,   511,   512,   513,   514,   514,   515,   515,   516,
     516,   516,   517,   517,   517,   518,   518,   518,   519,   519,
     519,   520,   520,   521,   521,   521,   521,   522,   522,   523,
     523,   524,   524
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
       1,     2,     0,     5,     4,     5,     1,     2,     1,     1,
       0,     1,     4,     2,     1,     1,     1,     2,     1,     2,
       0,     1,     4,     0,     1,     0,     1,     0,     1,     0,
       1,     3,     1,     2,     1,     1,     4,     1,     2,     1,
       2,     1,     3,     1,     2,     1,     1,     1,     1,     2,
       1,     1,     2,     2,     0,     1,     0,     1,     2,     2,
       1,     2,     0,     1,     0,     4,     2,     0,     1,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     0,     1,     2,     0,     1,     3,
       3,     3,     5,     5,     5,     2,     2,     2,     5,     2,
       0,     1,     0,     1,     2,     1,     0,     2,     2,     2,
       2,     1,     2,     1,     2,     0,     1,     2,     1,     1,
       1,     1,     3,     3,     0,     3,     0,     1,     0,     1,
       3,     0,     2,     0,     0,     0,     8,     2,     2,     0,
       1,     1,     1,     1,     1,     0,     4,     2,     0,     1,
       3,     0,     2,     2,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     0,     3,     0,
       0,     0,     6,     0,     0,     0,     7,     6,     2,     1,
       1,     0,     0,     6,     0,     2,     1,     0,     5,     0,
       2,     1,     3,     0,     2,     0,     4,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     0,     0,     4,
       0,     0,     4,     0,     3,     0,     2,     2,     1,     1,
       1,     2,     1,     0,     6,     0,     1,     2,     0,     2,
       1,     0,     5,     0,     3,     0,     3,     1,     0,     1,
       3,     2,     0,     1,     2,     0,     2,     1,     1,     2,
       2,     0,     2,     1,     0,     3,     0,     3,     1,     0,
       1,     0,     4,     1,     1,     0,     3,     0,     1,     2,
       0,     2,     1,     1,     2,     2,     0,     2,     1,     1,
       2,     2,     0,     2,     2,     2,     0,     2,     2,     0,
       1,     1,     2,     1,     1,     1,     1,     1,     2,     3,
       1,     3,     2,     0,     2,     2,     0,     1,     1,     1,
       2,     1,     1,     1,     1,     0,     4,     4,     1,     1,
       1,     1,     1,     0,     1,     1,     2,     1,     1,     0,
       4,     4,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     0,     2,     2,     2,     0,     2,     1,
       2,     0,     1,     2,     2,     2,     2,     2,     2,     2,
       3,     1,     2,     1,     1,     2,     2,     0,     1,     2,
       2,     2,     0,     2,     2,     0,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     4,     6,     4,     4,     4,     4,     2,     2,     4,
       4,     4,     4,     2,     1,     4,     1,     4,     4,     4,
       6,     6,     6,     6,     6,     4,     4,     4,     4,     4,
       4,     4,     4,     2,     2,     2,     4,     4,     4,     4,
       4,     2,     8,     6,     6,     6,     4,     4,     4,     4,
       4,     1,     1,     1,     3,     1,     7,     0,     1,     7,
       9,     0,     0,     4,     0,     0,     5,     5,     5,     6,
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
  "IT_LIMIT", "IT_OFFSET", "IT_VALUES", "IT_MEMBERS", "IT_STARTS",
  "IT_ENDS", "IT_ANY", "IT_UNORDERED", "GT_LCURLEY", "GT_RCURLEY",
  "IT_ASK", "IT_WHERE", "GT_LPAREN", "GT_RPAREN", "IT_UNDEF", "GT_DOT",
  "IT_OPTIONAL", "IT_MINUS", "IT_UNION", "IT_FILTER", "GT_COMMA",
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
  "$@11", "DescribeQuery", "_QVarOrIri_E_Plus",
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
  "_Q_O_QIT_VALUES_E_S_QDataBlock_E_C_E_Opt", "Update", "$@12",
  "_O_QGT_SEMI_E_S_QUpdate_E_C", "_Q_O_QGT_SEMI_E_S_QUpdate_E_C_E_Opt",
  "_O_QUpdate1_E_S_QGT_SEMI_E_S_QUpdate_E_Opt_C",
  "_Q_O_QUpdate1_E_S_QGT_SEMI_E_S_QUpdate_E_Opt_C_E_Opt", "Update1",
  "Load", "_QIT_SILENT_E_Opt", "_O_QIT_INTO_E_S_QGraphRef_E_C",
  "_Q_O_QIT_INTO_E_S_QGraphRef_E_C_E_Opt", "Clear", "Drop", "Create",
  "Add", "Move", "Copy", "InsertData", "DeleteData", "DeleteWhere",
  "Modify", "_O_QIT_WITH_E_S_Qiri_E_C", "_Q_O_QIT_WITH_E_S_Qiri_E_C_E_Opt",
  "_QInsertClause_E_Opt",
  "_O_QDeleteClause_E_S_QInsertClause_E_Opt_Or_QInsertClause_E_C",
  "_QUsingClause_E_Star", "DeleteClause", "InsertClause", "UsingClause",
  "_O_Qiri_E_Or_QIT_NAMED_E_S_Qiri_E_C", "GraphOrDefault",
  "_QIT_GRAPH_E_Opt", "GraphRef", "GraphRefAll", "QuadPattern", "QuadData",
  "Quads", "$@13", "_QTriplesTemplate_E_Opt", "_QGT_DOT_E_Opt",
  "_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C_E_Star",
  "QuadsNotTriples", "@14", "@15", "$@16", "TriplesTemplate",
  "_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C_E_Opt", "GroupGraphPattern",
  "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C",
  "_O_QGT_LCURLEY_E_S_QSubSelect_E_Or_QGroupGraphPatternSub_E_S_QGT_RCURLEY_E_C",
  "$@17", "GroupGraphPatternSub", "_QTriplesBlock_E_Opt",
  "_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "Print", "OptionalGraphPattern", "@18", "GraphGraphPattern", "@19",
  "@20", "@21", "ServiceGraphPattern", "@22", "@23", "@24", "Bind",
  "InlineData", "DataBlock", "InlineDataOneVar", "$@25", "$@26",
  "_QSingleValueRow_E_Star", "SingleValueRow", "InlineDataFull", "$@27",
  "_QVar_E_Star",
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
       189,     0,    -1,   190,    -1,   193,    -1,   191,    -1,   194,
     192,   288,    -1,   235,    -1,   251,    -1,   254,    -1,   258,
      -1,   291,    -1,   195,   196,   197,    -1,    -1,   231,    -1,
      -1,   196,   232,    -1,    -1,   197,   198,    -1,    -1,   201,
     199,   202,    -1,   162,    55,    -1,    -1,   200,    -1,   203,
      -1,   213,    -1,   223,    -1,   263,    -1,   205,   206,   204,
     212,    -1,   206,   204,    43,    -1,    -1,   204,   209,    -1,
     150,    -1,   103,   208,    -1,   211,    -1,   207,   211,    -1,
     103,    -1,   207,    -1,    -1,   103,   210,   208,    -1,   379,
     103,    -1,   150,    -1,   215,   216,   214,   222,    -1,   216,
     214,    43,    -1,    -1,   214,   219,    -1,   152,    -1,   154,
     218,    -1,   221,    -1,   217,   221,    -1,   154,    -1,   217,
      -1,    -1,   154,   220,   218,    -1,   379,   154,    -1,   153,
      -1,    36,   224,    37,    -1,    -1,   224,   225,    -1,    -1,
      40,   226,   229,    41,    -1,    -1,    48,    -1,   230,   227,
      -1,    -1,   229,   228,    -1,   379,   149,   379,    -1,   379,
     148,   379,    -1,   379,    55,   379,    -1,    14,   179,    -1,
      -1,    -1,    15,   233,   180,   234,   179,    -1,    -1,   236,
     242,   237,   264,   266,    -1,    -1,   237,   259,    -1,    -1,
      -1,    -1,   239,   240,   242,   241,   264,   266,   288,    -1,
      16,   244,   250,    -1,    17,    -1,    18,    -1,    -1,   243,
      -1,    90,   468,    -1,    -1,   245,    -1,    40,   470,   246,
      41,    -1,   493,    -1,   512,    -1,   516,    -1,   520,    -1,
     468,    -1,   505,    -1,   391,    -1,   247,    -1,   248,    -1,
     249,   248,    -1,   249,    -1,    19,    -1,    20,   252,    -1,
      -1,   325,   253,   237,   264,   266,    -1,   237,    39,   325,
     266,    -1,    21,   256,   237,   257,   266,    -1,   467,    -1,
     255,   467,    -1,   255,    -1,    19,    -1,    -1,   264,    -1,
      38,   237,   264,   266,    -1,    22,   260,    -1,   261,    -1,
     262,    -1,   263,    -1,    23,   263,    -1,   522,    -1,   265,
     340,    -1,    -1,    39,    -1,   267,   268,   269,   270,    -1,
      -1,   271,    -1,    -1,   274,    -1,    -1,   277,    -1,    -1,
     283,    -1,    91,    25,   272,    -1,   273,    -1,   272,   273,
      -1,   493,    -1,   391,    -1,    40,   470,   246,    41,    -1,
     468,    -1,    92,   275,    -1,   276,    -1,   275,   276,    -1,
     390,    -1,    24,    25,   278,    -1,   279,    -1,   278,   279,
      -1,   281,    -1,   282,    -1,    26,    -1,    27,    -1,   280,
     492,    -1,   390,    -1,   468,    -1,   286,   284,    -1,   287,
     285,    -1,    -1,   287,    -1,    -1,   286,    -1,    28,   166,
      -1,    29,   166,    -1,   290,    -1,    30,   365,    -1,    -1,
     289,    -1,    -1,   194,   297,   292,   296,    -1,    49,   291,
      -1,    -1,   293,    -1,   297,   294,    -1,    -1,   295,    -1,
     298,    -1,   302,    -1,   303,    -1,   305,    -1,   306,    -1,
     307,    -1,   304,    -1,   308,    -1,   309,    -1,   310,    -1,
     311,    -1,     8,   299,   522,   301,    -1,    -1,    12,    -1,
       9,   323,    -1,    -1,   300,    -1,    10,   299,   324,    -1,
      13,   299,   324,    -1,    11,   299,   323,    -1,   115,   299,
     321,   111,   321,    -1,   129,   299,   321,   111,   321,    -1,
     116,   299,   321,   111,   321,    -1,   131,   326,    -1,   121,
     326,    -1,   119,   325,    -1,   313,   315,   316,    39,   340,
      -1,   104,   522,    -1,    -1,   312,    -1,    -1,   318,    -1,
     317,   314,    -1,   318,    -1,    -1,   316,   319,    -1,     3,
     325,    -1,     4,   325,    -1,   107,   320,    -1,   522,    -1,
      23,   522,    -1,   105,    -1,   322,   522,    -1,    -1,     6,
      -1,     6,   522,    -1,   323,    -1,   105,    -1,    23,    -1,
     106,    -1,    36,   327,    37,    -1,    36,   327,    37,    -1,
      -1,   328,   329,   332,    -1,    -1,   337,    -1,    -1,    43,
      -1,   333,   330,   329,    -1,    -1,   332,   331,    -1,    -1,
      -1,    -1,   334,     6,   467,   335,    36,   336,   329,    37,
      -1,   399,   339,    -1,    43,   329,    -1,    -1,   338,    -1,
     342,    -1,   162,    -1,   238,    -1,   344,    -1,    -1,    36,
     343,   341,    37,    -1,   345,   347,    -1,    -1,   348,    -1,
     351,   330,   345,    -1,    -1,   347,   346,    -1,   414,   350,
      -1,    43,   345,    -1,    -1,   349,    -1,   383,    -1,   353,
      -1,   380,    -1,   355,    -1,   359,    -1,   389,    -1,   363,
      -1,   364,    -1,   352,    -1,   147,   340,    -1,    -1,    44,
     354,   340,    -1,    -1,    -1,    -1,     6,   356,   357,   467,
     358,   340,    -1,    -1,    -1,    -1,     7,   360,   361,   362,
     299,   467,   340,    -1,   126,    40,   470,    90,   468,    41,
      -1,    30,   365,    -1,   366,    -1,   371,    -1,    -1,    -1,
     367,   468,   368,    36,   369,    37,    -1,    -1,   369,   370,
      -1,   379,    -1,    -1,   372,   374,    36,   378,    37,    -1,
      -1,   373,   468,    -1,   187,    -1,    40,   373,    41,    -1,
      -1,   375,   379,    -1,    -1,    40,   377,   375,    41,    -1,
     187,    -1,    -1,   378,   376,    -1,   522,    -1,   512,    -1,
     516,    -1,   520,    -1,    42,    -1,   163,    -1,   468,    -1,
      -1,    -1,    45,   381,   382,   340,    -1,    -1,    -1,   384,
     385,   340,   388,    -1,    -1,    46,   387,   340,    -1,    -1,
     388,   386,    -1,    47,   390,    -1,   492,    -1,   493,    -1,
     391,    -1,   522,   392,    -1,   187,    -1,    -1,    40,   394,
     470,   393,   396,    41,    -1,    -1,    17,    -1,    48,   470,
      -1,    -1,   396,   395,    -1,   187,    -1,    -1,    40,   470,
     398,   396,    41,    -1,    -1,   466,   400,   404,    -1,    -1,
     452,   401,   402,    -1,   403,    -1,    -1,   404,    -1,   409,
     410,   408,    -1,   409,   410,    -1,    -1,   405,    -1,    49,
     406,    -1,    -1,   408,   407,    -1,   467,    -1,    50,    -1,
     413,   412,    -1,    48,   413,    -1,    -1,   412,   411,    -1,
     464,    -1,    -1,   466,   415,   419,    -1,    -1,   459,   416,
     417,    -1,   418,    -1,    -1,   419,    -1,    -1,   421,   420,
     429,   426,    -1,   427,    -1,   428,    -1,    -1,   421,   423,
     410,    -1,    -1,   422,    -1,    49,   424,    -1,    -1,   426,
     425,    -1,   433,    -1,   468,    -1,   432,   431,    -1,    48,
     432,    -1,    -1,   431,   430,    -1,   465,    -1,   434,    -1,
     437,   436,    -1,   103,   437,    -1,    -1,   436,   435,    -1,
     442,   439,    -1,    63,   442,    -1,    -1,   439,   438,    -1,
     444,   441,    -1,    -1,   443,    -1,   440,    -1,   101,   440,
      -1,   102,    -1,    19,    -1,    61,    -1,   522,    -1,    50,
      -1,    64,   445,    -1,    40,   433,    41,    -1,   450,    -1,
      40,   449,    41,    -1,   103,   450,    -1,    -1,   447,   446,
      -1,   450,   447,    -1,    -1,   448,    -1,   522,    -1,    50,
      -1,   101,   451,    -1,   522,    -1,    50,    -1,   455,    -1,
     453,    -1,    -1,    51,   454,   404,    52,    -1,   457,    40,
     458,    41,    -1,    31,    -1,    32,    -1,    33,    -1,    34,
      -1,    35,    -1,    -1,   456,    -1,   464,    -1,   458,   464,
      -1,   462,    -1,   460,    -1,    -1,    51,   461,   419,    52,
      -1,   457,    40,   463,    41,    -1,   465,    -1,   463,   465,
      -1,   466,    -1,   452,    -1,   466,    -1,   459,    -1,   468,
      -1,   469,    -1,   468,    -1,   522,    -1,   184,    -1,   185,
      -1,   522,    -1,   512,    -1,   516,    -1,   520,    -1,   524,
      -1,   187,    -1,   471,    -1,   474,   473,    -1,    53,   474,
      -1,    -1,   473,   472,    -1,   477,   476,    -1,    54,   477,
      -1,    -1,   476,   475,    -1,   478,    -1,   481,   479,    -1,
      -1,   480,    -1,    55,   481,    -1,    56,   481,    -1,    57,
     481,    -1,    58,   481,    -1,    59,   481,    -1,    60,   481,
      -1,    66,   397,    -1,    65,    66,   397,    -1,   482,    -1,
     488,   487,    -1,   518,    -1,   519,    -1,    19,   490,    -1,
      63,   490,    -1,    -1,   484,    -1,    61,   488,    -1,    62,
     488,    -1,   483,   485,    -1,    -1,   487,   486,    -1,   490,
     489,    -1,    -1,   489,   484,    -1,    64,   491,    -1,    61,
     491,    -1,    62,   491,    -1,   491,    -1,   492,    -1,   493,
      -1,   510,    -1,   512,    -1,   516,    -1,   520,    -1,   468,
      -1,   505,    -1,    40,   470,    41,    -1,    77,    40,   470,
      41,    -1,    78,    40,   470,    41,    -1,    79,    40,   470,
      48,   470,    41,    -1,    80,    40,   470,    41,    -1,    81,
      40,   468,    41,    -1,    67,    40,   470,    41,    -1,    68,
      40,   470,    41,    -1,    69,   494,    -1,   117,   187,    -1,
     141,    40,   470,    41,    -1,   138,    40,   470,    41,    -1,
     130,    40,   470,    41,    -1,   124,    40,   470,    41,    -1,
      89,   397,    -1,   497,    -1,   144,    40,   470,    41,    -1,
     498,    -1,   142,    40,   470,    41,    -1,   140,    40,   470,
      41,    -1,   136,    40,   470,    41,    -1,   127,    40,   470,
      48,   470,    41,    -1,   137,    40,   470,    48,   470,    41,
      -1,   143,    40,   470,    48,   470,    41,    -1,   112,    40,
     470,    48,   470,    41,    -1,   113,    40,   470,    48,   470,
      41,    -1,   114,    40,   470,    41,    -1,   146,    40,   470,
      41,    -1,   139,    40,   470,    41,    -1,   135,    40,   470,
      41,    -1,   132,    40,   470,    41,    -1,   128,    40,   470,
      41,    -1,   123,    40,   470,    41,    -1,   122,    40,   470,
      41,    -1,   120,   187,    -1,   108,   187,    -1,   109,   187,
      -1,   110,    40,   470,    41,    -1,   145,    40,   470,    41,
      -1,   134,    40,   470,    41,    -1,   125,    40,   470,    41,
      -1,   118,    40,   470,    41,    -1,    70,   397,    -1,    71,
      40,   470,    48,   470,    48,   470,    41,    -1,    72,    40,
     470,    48,   470,    41,    -1,    73,    40,   470,    48,   470,
      41,    -1,    82,    40,   470,    48,   470,    41,    -1,    83,
      40,   470,    41,    -1,    84,    40,   470,    41,    -1,    85,
      40,   470,    41,    -1,    86,    40,   470,    41,    -1,   100,
      40,   470,    41,    -1,   495,    -1,   499,    -1,   502,    -1,
      40,   470,    41,    -1,   187,    -1,    87,    40,   470,    48,
     470,   496,    41,    -1,    -1,   395,    -1,   133,    40,   470,
      48,   470,   496,    41,    -1,    74,    40,   470,    48,   470,
      48,   470,   496,    41,    -1,    -1,    -1,    75,   500,   501,
     340,    -1,    -1,    -1,    65,    75,   503,   504,   340,    -1,
      93,    40,   394,   506,    41,    -1,   507,    40,   394,   470,
      41,    -1,    98,    40,   394,   470,   509,    41,    -1,    19,
      -1,   470,    -1,    94,    -1,    95,    -1,    96,    -1,    97,
      -1,    99,    -1,    49,    76,    55,   521,    -1,    -1,   508,
      -1,   522,   511,    -1,    -1,   392,    -1,   521,   515,    -1,
      88,   522,    -1,   186,    -1,   513,    -1,    -1,   514,    -1,
     517,    -1,   518,    -1,   519,    -1,   166,    -1,   167,    -1,
     168,    -1,   169,    -1,   170,    -1,   171,    -1,   172,    -1,
     173,    -1,   174,    -1,   164,    -1,   165,    -1,   175,    -1,
     177,    -1,   176,    -1,   178,    -1,   179,    -1,   523,    -1,
     181,    -1,   180,    -1,   182,    -1,   183,    -1
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
     245,   247,   250,   251,   257,   262,   268,   270,   273,   275,
     277,   278,   280,   285,   288,   290,   292,   294,   297,   299,
     302,   303,   305,   310,   311,   313,   314,   316,   317,   319,
     320,   322,   326,   328,   331,   333,   335,   340,   342,   345,
     347,   350,   352,   356,   358,   361,   363,   365,   367,   369,
     372,   374,   376,   379,   382,   383,   385,   386,   388,   391,
     394,   396,   399,   400,   402,   403,   408,   411,   412,   414,
     417,   418,   420,   422,   424,   426,   428,   430,   432,   434,
     436,   438,   440,   442,   447,   448,   450,   453,   454,   456,
     460,   464,   468,   474,   480,   486,   489,   492,   495,   501,
     504,   505,   507,   508,   510,   513,   515,   516,   519,   522,
     525,   528,   530,   533,   535,   538,   539,   541,   544,   546,
     548,   550,   552,   556,   560,   561,   565,   566,   568,   569,
     571,   575,   576,   579,   580,   581,   582,   591,   594,   597,
     598,   600,   602,   604,   606,   608,   609,   614,   617,   618,
     620,   624,   625,   628,   631,   634,   635,   637,   639,   641,
     643,   645,   647,   649,   651,   653,   655,   658,   659,   663,
     664,   665,   666,   673,   674,   675,   676,   684,   691,   694,
     696,   698,   699,   700,   707,   708,   711,   713,   714,   720,
     721,   724,   726,   730,   731,   734,   735,   740,   742,   743,
     746,   748,   750,   752,   754,   756,   758,   760,   761,   762,
     767,   768,   769,   774,   775,   779,   780,   783,   786,   788,
     790,   792,   795,   797,   798,   805,   806,   808,   811,   812,
     815,   817,   818,   824,   825,   829,   830,   834,   836,   837,
     839,   843,   846,   847,   849,   852,   853,   856,   858,   860,
     863,   866,   867,   870,   872,   873,   877,   878,   882,   884,
     885,   887,   888,   893,   895,   897,   898,   902,   903,   905,
     908,   909,   912,   914,   916,   919,   922,   923,   926,   928,
     930,   933,   936,   937,   940,   943,   946,   947,   950,   953,
     954,   956,   958,   961,   963,   965,   967,   969,   971,   974,
     978,   980,   984,   987,   988,   991,   994,   995,   997,   999,
    1001,  1004,  1006,  1008,  1010,  1012,  1013,  1018,  1023,  1025,
    1027,  1029,  1031,  1033,  1034,  1036,  1038,  1041,  1043,  1045,
    1046,  1051,  1056,  1058,  1061,  1063,  1065,  1067,  1069,  1071,
    1073,  1075,  1077,  1079,  1081,  1083,  1085,  1087,  1089,  1091,
    1093,  1095,  1098,  1101,  1102,  1105,  1108,  1111,  1112,  1115,
    1117,  1120,  1121,  1123,  1126,  1129,  1132,  1135,  1138,  1141,
    1144,  1148,  1150,  1153,  1155,  1157,  1160,  1163,  1164,  1166,
    1169,  1172,  1175,  1176,  1179,  1182,  1183,  1186,  1189,  1192,
    1195,  1197,  1199,  1201,  1203,  1205,  1207,  1209,  1211,  1213,
    1217,  1222,  1227,  1234,  1239,  1244,  1249,  1254,  1257,  1260,
    1265,  1270,  1275,  1280,  1283,  1285,  1290,  1292,  1297,  1302,
    1307,  1314,  1321,  1328,  1335,  1342,  1347,  1352,  1357,  1362,
    1367,  1372,  1377,  1382,  1385,  1388,  1391,  1396,  1401,  1406,
    1411,  1416,  1419,  1428,  1435,  1442,  1449,  1454,  1459,  1464,
    1469,  1474,  1476,  1478,  1480,  1484,  1486,  1494,  1495,  1497,
    1505,  1515,  1516,  1517,  1522,  1523,  1524,  1530,  1536,  1542,
    1549,  1551,  1553,  1555,  1557,  1559,  1561,  1563,  1568,  1569,
    1571,  1574,  1575,  1577,  1580,  1583,  1585,  1587,  1588,  1590,
    1592,  1594,  1596,  1598,  1600,  1602,  1604,  1606,  1608,  1610,
    1612,  1614,  1616,  1618,  1620,  1622,  1624,  1626,  1628,  1630,
    1632,  1634,  1636
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   482,   482,   485,   491,   496,   507,   508,   509,   510,
     514,   519,   523,   525,   529,   531,   534,   536,   540,   540,
     558,   564,   567,   571,   572,   573,   574,   580,   581,   584,
     586,   590,   594,   598,   599,   603,   604,   608,   608,   616,
     622,   626,   627,   630,   632,   636,   640,   644,   645,   649,
     650,   654,   654,   662,   668,   672,   675,   677,   681,   681,
     688,   690,   694,   697,   699,   703,   706,   709,   715,   721,
     723,   721,   733,   733,   745,   748,   756,   759,   762,   756,
     777,   785,   788,   795,   798,   803,   810,   813,   818,   825,
     828,   831,   834,   837,   840,   843,   847,   852,   855,   863,
     866,   872,   878,   878,   885,   895,   903,   906,   914,   917,
     924,   927,   932,   940,   947,   948,   952,   958,   964,   971,
     978,   980,   985,   992,   995,  1000,  1003,  1008,  1011,  1016,
    1020,  1024,  1031,  1034,  1041,  1044,  1047,  1050,  1056,  1062,
    1065,  1072,  1077,  1084,  1088,  1096,  1098,  1106,  1109,  1117,
    1125,  1126,  1133,  1137,  1145,  1148,  1153,  1156,  1160,  1166,
    1172,  1176,  1182,  1185,  1189,  1189,  1199,  1202,  1204,  1208,
    1211,  1213,  1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,
    1225,  1226,  1227,  1231,  1237,  1240,  1247,  1254,  1257,  1261,
    1267,  1273,  1279,  1285,  1291,  1297,  1305,  1313,  1320,  1329,
    1335,  1338,  1342,  1345,  1349,  1353,  1359,  1361,  1367,  1373,
    1379,  1385,  1388,  1394,  1397,  1402,  1404,  1408,  1414,  1417,
    1420,  1423,  1430,  1436,  1442,  1442,  1450,  1452,  1456,  1458,
    1462,  1465,  1467,  1472,  1477,  1480,  1472,  1491,  1495,  1498,
    1500,  1504,  1505,  1518,  1519,  1524,  1524,  1535,  1539,  1541,
    1551,  1555,  1558,  1574,  1579,  1583,  1586,  1590,  1591,  1592,
    1593,  1594,  1595,  1596,  1597,  1600,  1604,  1610,  1610,  1626,
    1630,  1632,  1626,  1643,  1647,  1649,  1643,  1660,  1671,  1677,
    1678,  1682,  1684,  1682,  1691,  1693,  1697,  1705,  1705,  1712,
    1714,  1720,  1721,  1724,  1726,  1732,  1732,  1737,  1743,  1745,
    1749,  1752,  1755,  1758,  1761,  1764,  1767,  1773,  1777,  1773,
    1787,  1791,  1787,  1801,  1801,  1813,  1815,  1819,  1829,  1830,
    1831,  1835,  1843,  1847,  1847,  1857,  1860,  1867,  1873,  1875,
    1889,  1892,  1892,  1902,  1902,  1905,  1905,  1911,  1914,  1916,
    1921,  1926,  1930,  1932,  1937,  1941,  1943,  1947,  1951,  1959,
    1964,  1968,  1970,  1974,  1982,  1982,  1985,  1985,  1991,  1994,
    1996,  2000,  2000,  2006,  2007,  2011,  2011,  2016,  2018,  2022,
    2025,  2027,  2031,  2035,  2041,  2045,  2048,  2050,  2054,  2061,
    2065,  2069,  2072,  2074,  2078,  2082,  2087,  2089,  2095,  2098,
    2100,  2106,  2107,  2113,  2114,  2115,  2119,  2122,  2125,  2128,
    2134,  2135,  2139,  2142,  2144,  2148,  2151,  2153,  2157,  2158,
    2159,  2163,  2164,  2170,  2171,  2175,  2175,  2188,  2216,  2219,
    2222,  2225,  2228,  2235,  2238,  2243,  2247,  2254,  2255,  2259,
    2259,  2271,  2298,  2302,  2309,  2310,  2314,  2315,  2319,  2322,
    2326,  2329,  2335,  2336,  2340,  2343,  2346,  2349,  2352,  2353,
    2359,  2364,  2373,  2380,  2383,  2391,  2400,  2407,  2410,  2417,
    2422,  2435,  2439,  2443,  2447,  2451,  2455,  2459,  2463,  2467,
    2471,  2478,  2483,  2492,  2495,  2502,  2505,  2512,  2515,  2520,
    2523,  2527,  2541,  2544,  2552,  2561,  2564,  2571,  2574,  2577,
    2580,  2584,  2585,  2586,  2587,  2590,  2593,  2596,  2599,  2603,
    2609,  2612,  2615,  2618,  2621,  2624,  2627,  2631,  2634,  2637,
    2640,  2643,  2646,  2649,  2652,  2653,  2656,  2657,  2660,  2663,
    2666,  2669,  2672,  2675,  2678,  2681,  2684,  2687,  2690,  2693,
    2696,  2699,  2702,  2705,  2708,  2711,  2714,  2717,  2720,  2723,
    2726,  2729,  2732,  2735,  2738,  2741,  2744,  2747,  2750,  2753,
    2756,  2759,  2760,  2761,  2767,  2770,  2777,  2784,  2787,  2791,
    2797,  2803,  2806,  2803,  2818,  2821,  2818,  2834,  2838,  2843,
    2852,  2855,  2859,  2862,  2865,  2868,  2871,  2877,  2883,  2886,
    2890,  2900,  2903,  2908,  2916,  2923,  2927,  2935,  2939,  2943,
    2944,  2945,  2949,  2950,  2951,  2955,  2956,  2957,  2961,  2962,
    2963,  2967,  2968,  2972,  2973,  2974,  2975,  2979,  2980,  2984,
    2985,  2989,  2990
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
     185,   186,   187
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SPARQLfedParser::yyeof_ = 0;
  const int SPARQLfedParser::yylast_ = 2768;
  const int SPARQLfedParser::yynnts_ = 337;
  const int SPARQLfedParser::yyempty_ = -2;
  const int SPARQLfedParser::yyfinal_ = 11;
  const int SPARQLfedParser::yyterror_ = 1;
  const int SPARQLfedParser::yyerrcode_ = 256;
  const int SPARQLfedParser::yyntokens_ = 188;

  const unsigned int SPARQLfedParser::yyuser_token_number_max_ = 442;
  const SPARQLfedParser::token_number_type SPARQLfedParser::yyundef_token_ = 2;


} // w3c_sw

/* Line 1136 of lalr1.cc  */
#line 5915 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 2996 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


