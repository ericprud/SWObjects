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

  case 265:

/* Line 690 of lalr1.cc  */
#line 1598 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_BindingClause)) : (yysemantic_stack_[(1) - (1)].p_BindingClause);
    }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 1605 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Print(driver.curOp);
    }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 1611 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 1615 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 270:

/* Line 690 of lalr1.cc  */
#line 1627 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 1631 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 1633 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 1636 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 1644 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 1648 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 1650 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 1653 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(7) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(7) - (6)].p_TTerm), driver.curOp, (yysemantic_stack_[(7) - (5)].p_Silence), driver.atomFactory, false));
	  driver.curGraphName = (yysemantic_stack_[(7) - (4)].p_TTerm);
      }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 1661 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 1665 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 1667 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 1670 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curOp = NULL;
      }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 1672 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  /*
	    serviceID,
	    from,
	    e_Silence
	    where
	   */
	  driver.lastWhereClause = (yysemantic_stack_[(10) - (10)].p_WhereClause);
	  driver.restoreFilter((yysemantic_stack_[(10) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction
	      ((yysemantic_stack_[(10) - (2)].p_TableOperation), new SADIGraphPattern((yysemantic_stack_[(10) - (6)].p_TTerm), (yysemantic_stack_[(10) - (5)].p_Silence), (yysemantic_stack_[(10) - (8)].p_TableOperation), (yysemantic_stack_[(10) - (10)].p_WhereClause)));
	  driver.curGraphName = (yysemantic_stack_[(10) - (4)].p_TTerm);
    }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 1688 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Bind(driver.ensureGraphPattern(), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
	// no more triples go into the current BGP, per
	//   http://www.w3.org/TR/sparql11-query/#sparqlTranslateGraphPatterns
	// test reference:
	//   http://www.sparql.org/query-validator?query=ASK+{+%3Fs+%3Fp+%3Fo+FILTER+%281%29+BIND+%282+AS+%3Fb%29+%3Fs2+%3Fp2+%3Fo2+FILTER+%283%29+BIND+%284+AS+%3Fd%29}&languageSyntax=SPARQL&outputFormat=algebra&linenumbers=false
	driver.curBGP = NULL;
    }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 1699 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = (yysemantic_stack_[(2) - (2)].p_BindingClause);
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 1710 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 1712 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
      }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 1714 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 1725 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
	driver.endBindingRow();
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 1733 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 1735 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 1742 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 1754 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 1760 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 1762 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 1765 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 1777 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 1780 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 1783 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 1786 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 1789 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 1792 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 1795 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 1801 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 1805 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 1807 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 1815 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 1819 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 1821 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 1829 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 1834 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.ensureGraphPattern());
      }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 1847 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    driver.ensureGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 1863 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 1871 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 1875 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 1878 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yysemantic_stack_[(6) - (4)].p_Expressions);
      }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 1885 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 1888 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 1895 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 1903 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 1917 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 1920 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 1923 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(5) - (3)].p_Expressions);
      }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 1930 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 1933 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 1975 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 1979 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::RDF_type;
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 2002 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 2010 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 2013 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 2028 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 2039 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 2063 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 2082 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 2110 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 2117 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 2128 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 2135 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 2147 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 2150 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::RDF_type;
    }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 2153 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 2156 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 2203 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 2207 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 2216 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 424:

/* Line 690 of lalr1.cc  */
#line 2244 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 2247 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 2250 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 2253 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 2256 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 2263 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 2271 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 2275 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 2287 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 2291 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject;
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 2299 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 438:

/* Line 690 of lalr1.cc  */
#line 2326 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 2330 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 2347 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 2354 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 2357 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 2368 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 2371 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 2374 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 2377 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 2381 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::RDF_nil; // !!! new GraphTerm_rule5($1);
    }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 2392 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 2401 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 2408 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 2411 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 2419 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 2428 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 2435 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 2438 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 2450 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 467:

/* Line 690 of lalr1.cc  */
#line 2463 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = NULL;
    }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 2471 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 2475 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 2479 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 2483 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 2487 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 2491 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 2495 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 2499 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = true;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 2511 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 2520 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 2523 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 2530 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 2533 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 2540 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 2548 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 2551 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 2555 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 488:

/* Line 690 of lalr1.cc  */
#line 2569 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 2572 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 2580 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 2589 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 2592 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 2599 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 2602 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 2605 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 2615 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 2618 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 2621 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 2624 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 2631 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 2637 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 2640 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 2643 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 2646 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 2649 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 2652 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 2655 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 2659 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 2662 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 2665 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 2668 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ceil, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 2671 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 2674 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 2677 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 2681 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 2685 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 2688 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 2691 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 2694 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 2697 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 2700 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 2703 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 2706 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 2709 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 2712 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 2715 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 2718 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 2721 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 2724 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 2727 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 2730 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 2733 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 2736 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_uuid, NULL, NULL, NULL));
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 2739 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_struuid, NULL, NULL, NULL));
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 2742 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 2745 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 2748 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 2751 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 2754 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 2757 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 2760 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 2763 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 2766 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 2769 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 2772 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 2775 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 2778 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 2781 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 2784 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 2795 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 2798 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 2805 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 2812 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 2819 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 2825 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_replace, (yysemantic_stack_[(9) - (3)].p_Expression), (yysemantic_stack_[(9) - (5)].p_Expression), (yysemantic_stack_[(9) - (7)].p_Expression))); // !! , $8
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 2831 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 2834 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 2838 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expression) = new ExistsExpression(driver.ensureGraphPattern());
	  driver.curOp = (yysemantic_stack_[(4) - (3)].p_TableOperation);
	  driver.countStar = (yysemantic_stack_[(4) - (2)].p_parentCountStar);
      }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 2846 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
      }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 2849 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 2853 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  // $$ = new ExistsExpression(false, driver.ensureGraphPattern());
	  (yyval.p_Expression) = new BooleanNegation(new ExistsExpression(driver.ensureGraphPattern()));
	  driver.curOp = (yysemantic_stack_[(5) - (4)].p_TableOperation);
	  driver.countStar = (yysemantic_stack_[(5) - (3)].p_parentCountStar);
      }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 2862 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 2866 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 2871 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  AggregateCall::ScalarVals svals;
	  if ((yysemantic_stack_[(6) - (5)].p_RDFLiteral) != NULL)
	      svals["separator"] = (yysemantic_stack_[(6) - (5)].p_RDFLiteral)->getLexicalValue();
	  (yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression), svals));
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 2880 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 2887 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 2890 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 2893 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 2896 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 2899 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 2905 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 2911 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 2918 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 2928 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 2936 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 2944 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 2951 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 2955 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 2963 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 690 of lalr1.cc  */
#line 3962 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
        66,  -114,    75,  -856,  -856,  -856,  1067,  -856,  -856,  -856,
    -856,  -856,    77,    77,    77,    77,    65,     9,  -856,   101,
      77,    77,    65,    96,    77,    96,   117,  -856,   135,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,   114,   140,  -856,   101,   262,
     169,   262,  -856,    60,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,   159,  -856,  -856,  -856,  -856,  -856,    80,  -856,
      59,    59,  -856,  -856,  -856,    59,  -856,    -9,  -856,  -856,
    -856,   106,  -856,   380,    65,    65,  -856,   202,  -856,  -856,
      54,  -856,   206,   101,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,   174,  1652,     6,    65,  -856,  -856,  -856,    64,  -856,
     126,    -2,  -856,  -856,   121,   101,   125,   188,   127,  -856,
    -856,   -42,  -856,    -4,  -856,  -856,  -856,  1467,    80,  -856,
    -856,   210,  -856,  -856,    21,  -856,  -856,    89,   236,  -856,
    -856,  -856,   169,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,   259,  -856,  -856,  -856,  -856,   265,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,   -47,  -856,
    -856,   101,  -856,  -856,  -856,  -856,  -856,   126,    80,   126,
    -856,   282,  -856,   216,  -856,  -856,  -856,  -856,  -856,    59,
    -856,    59,  -856,    59,  -856,  -856,  -856,   275,  -856,  2057,
     237,   274,   278,    13,    14,   279,   283,   288,   294,  -856,
     295,   302,   305,   309,   311,   312,   313,   315,   316,   323,
     337,    14,   341,  -856,  -856,  -856,  -856,   342,  -856,   343,
     197,   198,   346,   347,   352,   354,   208,   356,   211,   357,
     359,   360,   361,   368,   369,   373,   374,   375,   376,   378,
     379,   381,   382,   383,   390,   391,   393,   394,   395,   396,
     397,  -856,  -856,  2178,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,   401,  -856,  -856,  -856,    15,   126,
      66,  -856,  -856,    -2,    16,  -856,  -856,  -856,   226,  -856,
     181,   438,  1652,  -856,  -856,   181,  1809,   181,   101,  -856,
    -856,  -856,  -856,  -856,  -856,   126,  -856,  2420,  2506,   420,
    -856,  1075,  -856,  -856,  -856,   410,    28,  -856,  2057,  2299,
    2299,  2299,  -856,   362,  -856,  -856,  -856,  -856,   459,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
      15,  -856,  2057,  2057,  2057,  -856,  -856,  2057,  -856,  -856,
    2057,  2057,  2057,  2057,  -856,  2057,  2057,  2057,  2057,   -42,
    2057,  2057,  2057,  2057,  2057,  2057,  -856,   430,   430,  2057,
    -856,  -856,  2057,  2057,  2057,  2057,  -856,  2057,  -856,  2057,
    2057,  2057,  2057,  2057,  2057,  2057,  2057,  2057,  2057,  2057,
    2057,  2057,  2057,  2057,  2057,  2057,  2057,  2057,  2057,  2057,
    2057,  -856,   430,   430,  -856,  -856,  -856,   536,  -856,  -856,
     101,  -856,  -856,   272,  -856,  1848,  -856,  -856,  1325,  -856,
    -856,   350,  -856,  -856,   301,  -856,  -856,  -856,  -856,   404,
    1809,  -856,  -856,   414,   453,  -856,  -856,  -856,  -856,  -856,
    1704,  -856,  -856,  -856,  -856,  -856,  2057,  2420,  -856,  -856,
    -856,  -856,  2506,  -856,  -856,  -856,  -856,  -856,   434,   139,
    -856,  -856,  -856,  -856,   424,  -856,  -856,  -856,   419,   423,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,    12,   425,  -856,
    -856,  -856,   -42,  -856,   427,   412,   415,  2057,  2057,  2057,
    2057,  2057,  2057,   409,    14,  -856,  -856,   255,    52,  -856,
    -856,  -856,   437,   439,   440,  -856,   435,   442,   443,   444,
      -2,   441,   445,   446,   452,   456,   457,   463,   465,   466,
     467,   473,  -856,  1291,  2057,   481,   486,   482,   485,   488,
     493,   497,   498,   499,   500,   494,   502,   504,   507,   503,
     512,   513,   514,   508,   516,   517,   518,   519,   520,   521,
     523,   524,   526,  2057,  2057,  -856,  -856,    71,  -856,  -856,
    -856,  1874,  -856,  -856,   384,  -856,  -856,  -856,  -856,  -856,
    -856,  1874,  -856,  -856,   331,  -856,    19,  -856,     8,  -856,
    -856,  -856,  -856,  -856,  1652,   159,  -856,  -856,   362,  -856,
    -856,  1588,   334,   402,  -856,  -856,   541,   534,    43,   135,
    -856,    51,  1730,  -856,  -856,  1911,    43,    43,    76,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  2057,  -856,  2057,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,    14,  -856,  2057,  2057,
      52,  -856,  -856,  -856,  2057,  2057,  -856,    -2,  -856,  -856,
    -856,  -856,  2057,  2057,  2057,  2057,  -856,  -856,  -856,  2057,
    -856,  -856,  2057,  -856,  -856,  -856,  -856,  2057,  -856,  -856,
     530,   527,  -856,  -856,  2057,  2057,  -856,  -856,  -856,  -856,
    -856,  -856,  2057,  -856,  -856,  -856,  2057,  -856,  -856,  -856,
    2057,  -856,  -856,  -856,  -856,  -856,  2057,  -856,  -856,  -856,
     537,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,   -40,
    -856,  -856,  -856,    26,  -856,  -856,  -856,   528,   531,  -856,
    -856,   539,  -856,  -856,  1588,  -856,   542,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,   108,  -856,   223,
      95,   529,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
      31,  -856,  -856,  -856,  -856,  -856,  -856,    -9,  -856,  -856,
    2506,   543,    -2,  -856,   414,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  1754,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,    25,
     540,   544,   548,   546,   551,   554,   549,  -856,   522,  -856,
     555,   558,   561,   562,   549,   564,   565,  -856,  -856,  -856,
    -856,  -856,  1848,  -856,  -856,  1325,   181,  -856,  1809,  -856,
     575,  -856,  -856,  -856,   571,   -10,  -856,    91,  -856,  -856,
    -856,  -856,  -856,  1911,   510,   553,  -856,  -856,  -856,  -856,
    -856,   545,  -856,  -856,  -856,  -856,    -2,  -856,  -856,  2057,
    -856,  1730,    -2,  -856,  -856,   533,  -856,  2057,  -856,  2057,
    -856,  -856,  2057,  -856,  -856,  -856,   576,   563,  -856,  -856,
    -856,  -856,   581,  -856,  -856,    73,   966,  -856,  -856,  -856,
    -856,  1809,  -856,  -856,  -856,  -856,   583,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,   108,  -856,   108,  -856,   126,   159,
    -856,  -856,  -856,    -2,   535,  -856,  -856,  -856,  -856,  -856,
     586,   549,  -856,   -99,  -856,  -856,  -856,  -856,   582,     4,
    -856,  1652,  -856,   538,   584,   591,  -856,  -856,   117,  -856,
      77,    77,  -856,   -42,   585,  -856,   593,  -856,  -856,  -856,
    1874,  1874,  1874,   607,   -10,  -856,    43,  -856,  1911,  -856,
    -856,    -2,   159,   159,   604,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,    -2,   624,
    -856,    -2,  1809,  -856,    65,  -856,  -856,  -856,   545,  -856
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
       0,     0,   224,     0,   101,   102,   109,   613,   616,   615,
     448,   449,   108,    74,   106,   446,   447,   614,   120,   199,
     215,   215,   197,   224,   196,   215,   195,   287,     5,   163,
     160,    83,    74,   200,     0,     0,   206,   202,   205,    69,
      11,    15,   187,     0,   220,   219,   221,   218,   189,   191,
     190,     0,   226,     0,     0,    75,    74,   107,   110,   121,
     123,     0,   216,   213,     0,     0,     0,     0,     0,   161,
     285,     0,   286,     0,    81,    82,    84,     0,   120,   171,
     165,   167,   208,   209,     0,   204,   203,     0,     0,    17,
      22,    18,     0,   188,   183,   217,   222,   424,   425,   426,
     427,   428,   421,   607,   608,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   609,   611,   610,   612,   617,   618,
     455,   231,   227,   239,   341,   420,   419,   430,     0,   339,
     444,   445,   451,   452,   595,   596,   597,   453,   593,   450,
     454,     0,   113,   114,   115,   116,   118,   123,   120,   123,
     111,     0,   112,   125,   124,   245,   242,   119,   241,   215,
     214,   215,   223,   215,   288,   295,   297,     0,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   567,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   578,   579,   580,   581,     0,   582,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    99,    80,    95,    93,    89,   557,   520,
     522,   558,   559,    94,     0,    90,    91,    92,     0,   123,
      12,   168,   169,     0,     0,   207,    70,    20,     0,   186,
       0,   225,   226,   240,   237,   344,   429,     0,     0,   591,
     592,   594,   589,   117,   104,   123,   105,     0,     0,   127,
     126,   248,   192,   194,   193,     0,     0,   304,     0,     0,
       0,     0,   503,    86,   456,   459,   463,   465,   467,   477,
     488,   491,   496,   497,   498,   504,   499,   500,   501,   502,
     587,   570,     0,     0,     0,   561,   513,     0,   336,   547,
       0,     0,     0,     0,   568,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   519,   331,   331,     0,
     540,   541,     0,     0,     0,     0,   514,     0,   539,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,   331,   331,   328,   327,    73,   200,   166,   198,
       0,   210,   211,     0,    56,     0,    31,    45,     0,    19,
      23,     0,    29,    24,     0,    43,    25,    26,   354,     0,
     429,   353,   232,   228,     0,   238,   342,   343,   345,   441,
     429,   431,   440,   340,   590,   103,     0,   131,   132,   135,
     137,   134,   138,   139,   141,   326,   324,   325,     0,   129,
     128,   435,   243,    77,     0,   244,   251,   249,   255,     0,
     362,   434,   433,   360,   290,   298,   296,     0,     0,   494,
     495,   493,     0,    87,     0,   457,   461,     0,     0,     0,
       0,     0,     0,     0,     0,   466,   468,   478,   490,   588,
     586,   571,     0,     0,     0,   337,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   332,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   212,    71,     0,   310,    35,
     311,    36,    32,    33,     0,   312,   307,   308,   309,   306,
      49,    50,    46,    47,     0,    29,     0,    43,     0,   422,
     351,   357,   359,   229,   226,     0,   423,   432,    86,   133,
     140,     0,     0,     0,   122,   130,   154,   156,     0,     0,
     246,   316,   248,   256,   253,   429,   365,     0,     0,   294,
     301,   303,   305,   505,    85,    88,     0,   460,     0,   464,
     469,   470,   471,   472,   473,   474,     0,   475,     0,     0,
     483,   489,   479,   480,     0,     0,   492,     0,   511,   512,
     560,   334,     0,     0,     0,     0,   569,   506,   507,     0,
     509,   510,     0,   552,   553,   554,   555,     0,   576,   577,
       0,   584,   556,   542,     0,     0,   531,   546,   538,   537,
     518,   545,     0,   536,   517,   535,     0,   544,   534,   525,
       0,   516,   533,   524,   515,   523,     0,   521,   543,   532,
       0,   329,    55,    58,    57,    34,    39,    48,    53,     0,
      28,    37,    30,     0,    42,    51,    44,   346,   355,   230,
     234,     0,   147,   148,   142,   143,     0,   145,   146,   150,
     151,   158,   159,   152,   155,   153,   157,     0,   403,     0,
       0,     0,   367,   369,   370,   378,   385,   388,   397,   392,
     395,   379,   402,    78,   270,   274,   278,   287,   268,   313,
       0,     0,     0,   252,   228,   266,   258,   260,   261,   262,
     264,   265,   259,   257,   317,   263,   254,   443,   429,   438,
     442,   363,   364,   366,   361,   289,   291,   292,   299,   458,
     462,   476,   485,   486,   484,   487,   481,   482,   572,     0,
       0,     0,     0,     0,     0,     0,   563,   573,     0,   585,
       0,     0,     0,     0,   563,     0,     0,   574,   334,    63,
      40,    27,     0,    54,    41,     0,   348,   352,   429,   358,
       0,   136,   144,   149,     0,   412,   415,     0,   404,   406,
     414,   398,   436,   429,   386,   390,   400,   401,   399,   394,
     396,   120,   271,   275,   279,   284,     0,   314,   323,     0,
     267,   248,     0,   437,   439,     0,   338,     0,   335,     0,
     549,   550,     0,   508,   551,   564,     0,     0,   575,   529,
     530,   526,     0,   527,   528,     0,     0,    38,    52,   349,
     350,   429,   356,   235,   405,   413,     0,   409,   418,   416,
     417,   376,   382,   384,     0,   389,     0,   393,   123,     0,
     276,   280,   269,     0,     0,   250,   321,   302,   300,   333,
       0,   563,   562,     0,   565,   330,    59,    64,    60,     0,
     347,   226,   407,   411,   368,   380,   387,   391,   162,   272,
     184,   184,   315,     0,   318,   548,     0,   583,    61,    62,
       0,     0,     0,     0,     0,   410,   373,   377,   429,   383,
      79,     0,     0,     0,     0,   319,   322,   566,    67,    66,
      65,   236,   408,   371,   374,   375,   381,   273,     0,     0,
     283,     0,   429,   277,     0,   320,   372,   281,   120,   282
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -856,  -856,  -856,  -856,  -856,  -856,   349,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,    62,  -856,   214,  -856,
    -181,  -856,  -856,    78,  -856,  -856,    63,  -856,   218,  -856,
    -170,  -856,  -856,    79,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,    44,
    -856,  -856,  -856,  -856,    55,  -856,  -856,  -856,    67,  -856,
     388,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,  -153,  -103,  -856,  -178,  -856,
    -856,  -856,  -856,  -856,  -856,   209,  -856,  -856,   201,  -856,
    -856,   -57,  -856,  -856,  -856,  -856,  -856,  -856,    61,    68,
    -269,  -856,  -856,   385,  -856,  -856,  -856,  -856,  -856,   597,
    -856,     3,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
     594,  -856,  -856,    56,  -856,    -3,   631,   -16,   658,   613,
    -856,  -297,   -86,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -299,  -856,  -856,  -856,  -856,  -612,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,   -77,  -856,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -424,  -856,  -856,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -577,  -119,   333,
    -856,  -317,  -760,  -137,  -234,  -856,  -856,  -856,  -856,  -856,
    -856,  -187,  -856,  -856,  -856,  -856,  -142,  -855,  -856,  -856,
    -122,  -856,  -856,  -856,  -856,  -856,  -348,  -856,  -270,  -856,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -856,  -248,
     -26,  -856,  -856,  -856,  -192,  -856,  -856,   -27,  -856,  -191,
    -856,  -856,  -856,  -856,  -856,  -856,  -856,  -802,  -856,   -90,
    -856,  -856,  -856,  -856,  -320,  -856,  -318,  -856,  -856,  -856,
    -856,  -277,  -603,   -93,   -14,    11,  -856,   652,  -856,  -856,
    -856,    88,  -856,  -856,    90,  -856,  -856,  -856,  -136,  -856,
    -856,    85,  -856,  -856,  -856,  -364,  -856,  -358,    -8,  -295,
    -107,  -856,  -856,  -780,  -856,  -856,  -856,  -856,  -856,  -856,
    -856,  -856,   -91,  -856,  -856,  -856,  -856,  -856,  -856,  -101,
    -856,  -856,  -856,    39,  -856,   212,   219,   338,  -207,   -17,
    -856,  -856
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,    26,     5,     6,     7,    46,    90,
     139,   308,   140,   141,   439,   440,   596,   441,   442,   581,
     582,   722,   832,   583,   831,   443,   598,   444,   445,   591,
     592,   726,   835,   593,   834,   446,   577,   714,   829,   959,
     937,   896,   938,     8,    91,   137,   433,    27,    28,    53,
     482,   483,   619,   861,    82,   126,   127,   503,   504,   281,
     282,   283,   284,    29,    54,   106,    30,    62,    63,   199,
      31,   105,   192,   193,   194,   195,   110,   111,   202,   203,
     329,   479,   614,   204,   467,   468,   330,   472,   473,   480,
     734,   735,   736,   737,   738,   615,   743,   745,   616,   617,
      78,    79,    80,     9,    83,   301,   302,   129,   130,    32,
      33,    48,   143,   144,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,   135,    86,   134,    87,
      88,   305,   431,   114,   115,    97,    98,    55,    74,   101,
     102,   171,   604,   452,   311,   453,   454,   840,   941,   172,
     313,   314,   207,   484,   208,   331,   485,   486,   773,   621,
     487,   623,   624,   774,   775,   776,   866,   777,   862,   919,
     971,   778,   863,   920,   950,   779,   864,   921,   951,   998,
     780,   781,   119,   120,   121,   335,   628,   796,   122,   123,
     336,   217,   875,   632,   798,   497,   584,   782,   867,   923,
     783,   784,   872,   976,   991,   954,   785,   474,   475,   425,
     828,   543,   885,   809,   369,   661,   173,   317,   315,   456,
     457,   449,   899,   900,   837,   727,   450,   600,   839,   728,
     601,   488,   627,   626,   791,   792,   751,   853,   752,   984,
     992,   985,   967,   944,   753,   754,   911,   969,   945,   912,
     755,   756,   915,   854,   757,   917,   855,   758,   859,   759,
     860,   760,   848,   965,   943,   905,   906,   849,   909,   459,
     175,   310,   176,   177,   178,   460,   787,   491,   618,   492,
     788,   602,   913,   462,   451,   342,   181,   343,   344,   637,
     505,   345,   639,   506,   346,   347,   515,   516,   348,   349,
     650,   656,   805,   651,   517,   350,   518,   351,   352,   353,
     354,   366,   288,   886,   289,   290,   291,   374,   530,   292,
     521,   657,   355,   680,   294,   819,   820,   356,   520,   357,
     320,   321,   322,   358,   184,   185,   186,   359,   188,   360,
      67,   190
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int SPARQLfedParser::yytable_ninf_ = -430;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        66,   182,    69,    64,   429,   200,    72,   386,   285,   179,
     786,   489,   174,   490,   594,   455,    49,    50,    51,   324,
     287,   326,   789,    70,    71,   299,   295,    75,    65,    56,
     191,    92,  -293,   476,   739,   205,   293,   215,   323,   461,
     430,   846,   318,   907,   892,    66,   940,    99,   107,   878,
     629,   856,   724,   630,   364,   367,   423,   764,   765,   766,
     960,   303,    68,   720,   721,   112,    10,   876,   132,   133,
     495,   544,   654,    65,   877,    11,   145,   164,   165,   166,
     167,     1,   767,   103,   747,   189,   196,   103,   197,  -247,
      47,   -21,   847,   857,   748,   325,   768,   769,   210,   770,
     104,  -120,    52,   103,   109,   573,   574,   108,   749,   712,
     298,   830,   713,   180,   795,   935,   655,    84,    85,   578,
     109,   426,   877,   721,   124,   125,   128,   116,   458,   304,
     463,   118,   214,    73,   858,   878,   747,   996,   286,   309,
     319,   183,   908,    60,    61,   750,   748,   465,    77,   747,
     198,   956,    81,   961,   962,   447,    89,   739,   -21,   748,
     749,   206,   982,   725,   285,   113,   296,   594,   612,   613,
      57,    58,    59,   749,   196,    93,   287,   476,   771,  -293,
     833,   725,   295,   607,   216,   874,    57,    58,    59,    57,
      58,    59,   293,   868,    60,    61,    57,    58,    59,   772,
     631,   365,   368,   424,   797,   -21,    85,   -21,   469,   -21,
     750,   182,   146,    60,    61,   182,   142,   138,   201,   179,
     471,   477,   174,    57,    58,    59,   212,  -120,    60,    61,
     182,   666,   448,   209,   -21,   -21,   -21,   211,   493,   213,
     580,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    57,    58,    59,   925,
     300,    60,    61,   434,   845,   332,   298,   333,    93,   334,
     306,    57,    58,    59,   846,    57,    58,    59,   793,   794,
     647,    57,    58,    59,   802,   803,    94,   432,    57,    58,
      59,   196,   307,    66,   286,   189,   806,   807,    66,   189,
      66,   464,   489,   312,   490,   489,   316,   729,   327,   328,
     298,   298,   337,   361,   189,   362,   476,   648,   649,   363,
     370,    65,   296,   180,   371,   847,    65,   180,    65,   372,
     435,   499,   500,   501,   586,   373,   375,   586,   470,    57,
      58,    59,   180,   376,    60,    61,   377,   496,   469,   182,
     378,   183,   379,   380,   381,   183,   382,   383,   808,   182,
     471,    57,    58,    59,   384,   477,    60,    61,    95,    96,
     183,   640,   641,   642,   643,   644,   645,   436,   385,   437,
    -170,   438,   387,   388,   389,   390,   391,   392,   393,    12,
     535,    13,    14,   394,    15,   395,   396,   397,   399,   398,
     400,   401,   402,    57,    58,    59,    57,    58,    59,   403,
     404,   594,   801,   575,   405,   406,   407,   408,   589,   409,
     410,   589,   411,   412,   413,   158,   159,   160,   161,   162,
     163,   414,   415,   189,   416,   417,   418,   419,   420,   476,
     187,   843,   422,   189,  -233,   478,   585,   494,   542,   585,
     298,   928,   576,   502,   435,   298,   438,   599,   603,   605,
     611,   180,   620,   622,   625,   297,   636,   633,   489,   635,
     638,   180,   939,   870,   587,   476,   646,   587,   470,   658,
     586,   659,   660,   667,   662,    19,   718,   668,   716,   183,
     586,   663,   664,   665,   670,   669,    20,    21,   671,   183,
      22,   741,    23,   182,   477,   673,   672,   674,   675,   676,
      24,   179,    25,   634,   174,   507,   508,   509,   510,   511,
     512,   182,   677,   682,   182,   513,   514,   586,   683,   493,
     686,   684,   790,   489,   685,   687,   978,   979,   980,   688,
     689,   690,   691,   692,   693,    12,   694,    13,    14,   695,
      15,   489,   696,   490,   697,   698,   699,   700,   701,   702,
     703,   704,   705,   612,   589,   707,   708,   922,   709,   742,
     706,   613,   817,   926,   589,   927,   578,   818,   836,   827,
     838,   841,   852,   338,   869,   109,   880,   189,    66,   879,
     881,   730,   585,   883,   298,   882,   884,   888,   877,   887,
     889,   762,   585,   890,   891,   189,   893,   894,   189,   762,
     762,   589,   903,   904,   914,   180,    65,   916,   932,   933,
     587,   297,   740,   934,   952,   942,   953,   477,   955,   761,
     587,   958,   975,   180,   966,   977,   180,   761,   761,   585,
     968,    19,   964,   183,   963,   981,   990,   994,   489,   427,
     187,   897,    20,    21,   187,   595,    22,   719,    23,   715,
     723,   183,   597,   477,   183,   898,    24,   587,    25,   187,
     717,   421,   987,   610,   763,   731,   609,   842,   746,   970,
     131,   136,   100,    76,   744,   428,   117,   182,   871,   993,
     865,   895,   995,   519,   901,   790,   983,   580,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    57,    58,    59,   902,   298,    60,    61,
     986,   844,   946,   851,   799,   947,   957,     0,   800,   652,
     762,   586,   850,   762,   586,   804,   653,   182,     0,     0,
     948,     0,     0,     0,     0,   740,     0,     0,     0,     0,
       0,     0,   182,   298,     0,     0,     0,     0,   918,     0,
     790,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,   189,     0,   588,   586,     0,   588,     0,   493,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   187,     0,
       0,     0,     0,     0,     0,   586,     0,     0,   187,   180,
     182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   589,     0,     0,   589,    66,
       0,   189,     0,     0,     0,     0,     0,   183,   850,     0,
     910,     0,     0,     0,     0,     0,   189,     0,     0,     0,
     182,     0,     0,   585,     0,     0,   585,    65,   179,   180,
       0,   174,     0,     0,   189,     0,     0,     0,   589,   586,
     586,   586,     0,     0,   180,     0,     0,   182,     0,     0,
       0,   587,     0,     0,   587,   790,     0,   183,     0,   589,
       0,     0,   180,     0,   189,     0,   585,     0,     0,     0,
       0,   182,   183,     0,     0,   999,     0,   762,     0,   762,
       0,     0,    66,     0,     0,   949,     0,   585,     0,     0,
     183,     0,   180,     0,   587,     0,     0,     0,     0,   588,
       0,     0,     0,     0,   189,     0,     0,     0,     0,   588,
      65,     0,     0,     0,     0,   587,     0,     0,     0,     0,
     183,     0,   187,   589,   589,   589,     0,   850,     0,   762,
       0,   189,   180,   972,   973,    66,    66,     0,   988,   989,
     187,     0,     0,   187,   974,     0,   588,     0,     0,     0,
       0,   585,   585,   585,     0,   189,     0,   761,   997,   180,
     183,     0,     0,    65,    65,     0,     0,     0,     0,     0,
     498,     0,     0,     0,     0,     0,     0,     0,     0,   587,
     587,   587,     0,   180,     0,     0,     0,   183,   936,   578,
       0,     0,     0,     0,   522,   523,   524,     0,     0,   525,
       0,     0,   526,   527,   528,   529,     0,   531,   532,   533,
     534,   183,   536,   537,   538,   539,   540,   541,     0,     0,
       0,   545,     0,     0,   546,   547,   548,   549,     0,   550,
       0,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,     0,     0,     0,    12,     0,    13,    14,
       0,    15,     0,     0,   -72,     0,     0,     0,    16,    17,
       0,     0,   -76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,   147,   148,   149,
     150,   151,     0,     0,     0,     0,  -429,     0,   608,     0,
       0,     0,     0,     0,     0,     0,   187,   481,     0,     0,
     580,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    57,    58,    59,     0,
       0,    60,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     588,     0,    19,   588,     0,     0,   187,     0,     0,     0,
       0,     0,     0,    20,    21,     0,     0,    22,     0,    23,
       0,   187,     0,     0,     0,   679,   681,    24,     0,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   187,
       0,     0,     0,   588,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   710,   711,     0,     0,     0,
       0,     0,     0,     0,   588,     0,     0,     0,     0,   187,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    57,    58,    59,   168,   169,
      60,    61,     0,   170,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   187,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   588,   588,
     588,     0,     0,     0,     0,     0,   187,     0,     0,     0,
       0,   678,     0,     0,   810,   811,   812,   813,     0,     0,
       0,   814,     0,     0,   815,     0,     0,     0,     0,   816,
     187,     0,   338,     0,     0,     0,   821,   822,     0,     0,
       0,     0,     0,     0,   823,     0,     0,     0,   824,     0,
       0,     0,   825,   339,   340,     0,   341,   220,   826,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   578,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
       0,   241,     0,     0,     0,   242,   243,   244,   245,   246,
     247,   248,   249,     0,     0,     0,     0,     0,     0,     0,
     250,   251,   252,     0,   253,   254,   255,     0,     0,   256,
     257,     0,   258,     0,   259,   260,   261,   262,     0,   263,
     264,     0,   265,     0,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    57,    58,    59,     0,     0,    60,    61,     0,     0,
     590,     0,     0,     0,     0,     0,     0,   218,     0,   580,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    57,    58,    59,   219,     0,
      60,    61,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   924,     0,     0,     0,     0,     0,     0,     0,   929,
       0,   930,     0,   220,   931,   221,   222,   223,   224,   225,
     226,   227,   228,   229,     0,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,     0,   241,     0,     0,
       0,   242,   243,   244,   245,   246,   247,   248,   249,     0,
       0,     0,     0,     0,     0,     0,   250,   251,   252,     0,
     253,   254,   255,     0,     0,   256,   257,     0,   258,     0,
     259,   260,   261,   262,     0,   263,   264,     0,   265,     0,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   732,   733,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   338,
       0,     0,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    57,    58,    59,
       0,     0,    60,    61,   220,     0,   221,   222,   223,   224,
     225,   226,   227,   228,   229,     0,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,     0,   241,     0,
       0,     0,     0,     0,   147,   148,   149,   150,   151,   249,
       0,     0,     0,  -429,     0,     0,     0,   250,   251,   252,
       0,   253,   254,   255,   152,     0,   256,   257,     0,   258,
       0,   259,   260,   261,   262,     0,   263,   264,     0,   265,
       0,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   147,   148,   149,   150,
     151,     0,     0,     0,     0,     0,   606,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   152,     0,     0,     0,
       0,     0,   147,   148,   149,   150,   151,     0,    57,    58,
      59,  -429,     0,    60,    61,     0,     0,     0,     0,     0,
       0,     0,   481,     0,     0,     0,   147,   148,   149,   150,
     151,     0,     0,     0,     0,     0,   873,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   481,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    57,    58,    59,   168,   169,    60,    61,     0,
     170,   147,   148,   149,   150,   151,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   152,     0,     0,     0,     0,     0,     0,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    57,    58,    59,   168,   169,    60,
      61,   578,   170,     0,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      57,    58,    59,   168,   169,    60,    61,   578,   170,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    57,    58,    59,   168,   169,    60,
      61,     0,   170,   147,   148,   149,   150,   151,     0,     0,
       0,     0,   579,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   481,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    57,
      58,    59,   168,   169,    60,    61,     0,   170,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   580,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    57,    58,
      59,     0,     0,    60,    61,     0,     0,     0,   580,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    57,    58,    59,     0,     0,    60,
      61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    57,    58,    59,   168,   169,    60,    61,   338,   170,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   339,
     340,     0,   341,   220,     0,   221,   222,   223,   224,   225,
     226,   227,   228,   229,     0,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,     0,   241,     0,     0,
       0,   242,   243,   244,   245,   246,   247,   248,   249,     0,
       0,     0,     0,     0,     0,     0,   250,   251,   252,     0,
     253,   254,   255,     0,     0,   256,   257,     0,   258,     0,
     259,   260,   261,   262,     0,   263,   264,     0,   265,     0,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   219,
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
     338,     0,     0,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    57,    58,
      59,     0,     0,    60,    61,   220,     0,   221,   222,   223,
     224,   225,   226,   227,   228,   229,     0,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,     0,   241,
       0,     0,     0,   242,   243,   244,   245,   246,   247,   248,
     249,     0,     0,     0,     0,     0,     0,     0,   250,   251,
     252,     0,   253,   254,   255,     0,     0,   256,   257,     0,
     258,     0,   259,   260,   261,   262,     0,   263,   264,     0,
     265,     0,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   466,     0,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    57,
      58,    59,     0,     0,    60,    61,   220,     0,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
     241,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   249,     0,     0,     0,     0,     0,     0,     0,   250,
     251,   252,     0,   253,   254,   255,     0,     0,   256,   257,
       0,   258,     0,   259,   260,   261,   262,   338,   263,   264,
       0,   265,     0,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,     0,     0,
       0,     0,   220,     0,   221,   222,   223,   224,   225,   226,
     227,   228,   229,     0,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,   241,     0,     0,     0,
      57,    58,    59,     0,     0,    60,    61,   249,     0,     0,
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
        17,   102,    19,    17,   303,   108,    22,   241,   127,   102,
     622,   331,   102,   331,   438,   312,    13,    14,    15,   197,
     127,   199,   625,    20,    21,   128,   127,    24,    17,    20,
      24,    48,    41,   328,   611,    37,   127,    41,   191,   316,
      24,    51,    89,   845,   824,    62,   901,    50,    62,   809,
      38,    20,    44,    41,    41,    41,    41,     6,     7,     8,
      56,    40,    18,    44,   104,     6,   180,    42,    84,    85,
      42,   388,    20,    62,    49,     0,    93,   176,   177,   178,
     179,    15,    31,    23,    41,   102,   103,    23,   104,    38,
      13,    37,   102,    62,    51,   198,    45,    46,   115,    48,
      40,    37,    37,    23,    40,   422,   423,    63,    65,    38,
     127,   151,    41,   102,    38,    42,    64,     3,     4,    43,
      40,   299,    49,   104,    18,    19,    82,    71,   315,   108,
     317,    75,   121,    37,   103,   895,    41,   992,   127,   142,
     187,   102,    51,   185,   186,   102,    51,   325,    31,    41,
     106,   931,    17,   149,   150,   308,    16,   734,   104,    51,
      65,   163,   964,   155,   283,   106,   127,   591,    29,    30,
     180,   181,   182,    65,   191,     6,   283,   472,   127,   188,
     154,   155,   283,   460,   188,   788,   180,   181,   182,   180,
     181,   182,   283,   770,   185,   186,   180,   181,   182,   148,
     188,   188,   188,   188,   628,   151,     4,   153,   327,   155,
     102,   312,    38,   185,   186,   316,    10,   163,    92,   312,
     327,   328,   312,   180,   181,   182,    38,   163,   185,   186,
     331,   530,    51,   112,   180,   181,   182,   112,   331,   112,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   871,
      50,   185,   186,    37,    41,   209,   283,   211,     6,   213,
     181,   180,   181,   182,    51,   180,   181,   182,   626,   627,
     514,   180,   181,   182,   648,   649,    24,   304,   180,   181,
     182,   308,    56,   310,   283,   312,   654,   655,   315,   316,
     317,   318,   622,    44,   622,   625,    41,   604,    26,    93,
     327,   328,    37,    76,   331,    41,   611,    62,    63,    41,
      41,   310,   283,   312,    41,   102,   315,   316,   317,    41,
     104,   339,   340,   341,   435,    41,    41,   438,   327,   180,
     181,   182,   331,    41,   185,   186,    41,   336,   467,   450,
      41,   312,    41,    41,    41,   316,    41,    41,   657,   460,
     467,   180,   181,   182,    41,   472,   185,   186,   106,   107,
     331,   507,   508,   509,   510,   511,   512,   151,    41,   153,
       0,   155,    41,    41,    41,   188,   188,    41,    41,     9,
     379,    11,    12,    41,    14,    41,   188,    41,    41,   188,
      41,    41,    41,   180,   181,   182,   180,   181,   182,    41,
      41,   835,   646,   430,    41,    41,    41,    41,   435,    41,
      41,   438,    41,    41,    41,   170,   171,   172,   173,   174,
     175,    41,    41,   450,    41,    41,    41,    41,    41,   734,
     102,   736,    41,   460,     6,    25,   435,    37,    18,   438,
     467,   875,   180,    91,   104,   472,   155,    53,    44,     6,
      26,   450,    38,    44,    41,   127,    54,    42,   788,    42,
      55,   460,   896,   772,   435,   770,    67,   438,   467,    42,
     581,    42,    42,    42,    49,   105,   155,    42,   104,   450,
     591,    49,    49,    49,    42,    49,   116,   117,    42,   460,
     120,   167,   122,   604,   611,    42,    49,    42,    42,    42,
     130,   604,   132,   502,   604,    56,    57,    58,    59,    60,
      61,   622,    49,    42,   625,    66,    67,   628,    42,   622,
      42,    49,   625,   853,    49,    42,   960,   961,   962,    42,
      42,    42,    42,    49,    42,     9,    42,    11,    12,    42,
      14,   871,    49,   871,    42,    42,    42,    49,    42,    42,
      42,    42,    42,    29,   581,    42,    42,   866,    42,   167,
      49,    30,    42,   872,   591,    42,    43,    50,    50,    42,
      49,    42,    53,    41,    41,    40,    42,   604,   605,    49,
      42,   605,   581,    42,   611,    49,    42,    42,    49,    77,
      42,   618,   591,    42,    42,   622,    42,    42,   625,   626,
     627,   628,    37,    42,   104,   604,   605,    64,    42,    56,
     581,   283,   611,    42,   923,    42,    91,   734,    42,   618,
     591,    49,    47,   622,    50,    42,   625,   626,   627,   628,
      49,   105,   104,   604,   941,    38,    42,    23,   968,   300,
     312,   832,   116,   117,   316,   441,   120,   595,   122,   581,
     597,   622,   444,   770,   625,   835,   130,   628,   132,   331,
     591,   283,   971,   472,   619,   608,   467,   734,   617,   948,
      83,    87,    51,    25,   616,   300,    73,   788,   774,   988,
     767,   828,   991,   360,   836,   788,   966,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   838,   734,   185,   186,
     968,   747,   914,   750,   636,   916,   933,    -1,   638,   517,
     747,   832,   749,   750,   835,   650,   517,   838,    -1,    -1,
     918,    -1,    -1,    -1,    -1,   734,    -1,    -1,    -1,    -1,
      -1,    -1,   853,   770,    -1,    -1,    -1,    -1,   861,    -1,
     853,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     871,   788,    -1,   435,   875,    -1,   438,    -1,   871,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   450,    -1,
      -1,    -1,    -1,    -1,    -1,   896,    -1,    -1,   460,   788,
     901,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   832,    -1,    -1,   835,   836,
      -1,   838,    -1,    -1,    -1,    -1,    -1,   788,   845,    -1,
     847,    -1,    -1,    -1,    -1,    -1,   853,    -1,    -1,    -1,
     941,    -1,    -1,   832,    -1,    -1,   835,   836,   941,   838,
      -1,   941,    -1,    -1,   871,    -1,    -1,    -1,   875,   960,
     961,   962,    -1,    -1,   853,    -1,    -1,   968,    -1,    -1,
      -1,   832,    -1,    -1,   835,   968,    -1,   838,    -1,   896,
      -1,    -1,   871,    -1,   901,    -1,   875,    -1,    -1,    -1,
      -1,   992,   853,    -1,    -1,   998,    -1,   914,    -1,   916,
      -1,    -1,   919,    -1,    -1,   919,    -1,   896,    -1,    -1,
     871,    -1,   901,    -1,   875,    -1,    -1,    -1,    -1,   581,
      -1,    -1,    -1,    -1,   941,    -1,    -1,    -1,    -1,   591,
     919,    -1,    -1,    -1,    -1,   896,    -1,    -1,    -1,    -1,
     901,    -1,   604,   960,   961,   962,    -1,   964,    -1,   966,
      -1,   968,   941,   950,   951,   972,   973,    -1,   972,   973,
     622,    -1,    -1,   625,   953,    -1,   628,    -1,    -1,    -1,
      -1,   960,   961,   962,    -1,   992,    -1,   966,   994,   968,
     941,    -1,    -1,   972,   973,    -1,    -1,    -1,    -1,    -1,
     338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   960,
     961,   962,    -1,   992,    -1,    -1,    -1,   968,    42,    43,
      -1,    -1,    -1,    -1,   362,   363,   364,    -1,    -1,   367,
      -1,    -1,   370,   371,   372,   373,    -1,   375,   376,   377,
     378,   992,   380,   381,   382,   383,   384,   385,    -1,    -1,
      -1,   389,    -1,    -1,   392,   393,   394,   395,    -1,   397,
      -1,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,    -1,    -1,    -1,     9,    -1,    11,    12,
      -1,    14,    -1,    -1,    17,    -1,    -1,    -1,    21,    22,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    41,    -1,   466,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   788,    52,    -1,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,   185,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     832,    -1,   105,   835,    -1,    -1,   838,    -1,    -1,    -1,
      -1,    -1,    -1,   116,   117,    -1,    -1,   120,    -1,   122,
      -1,   853,    -1,    -1,    -1,   543,   544,   130,    -1,   132,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   871,
      -1,    -1,    -1,   875,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   573,   574,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   896,    -1,    -1,    -1,    -1,   901,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   941,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   960,   961,
     962,    -1,    -1,    -1,    -1,    -1,   968,    -1,    -1,    -1,
      -1,    20,    -1,    -1,   662,   663,   664,   665,    -1,    -1,
      -1,   669,    -1,    -1,   672,    -1,    -1,    -1,    -1,   677,
     992,    -1,    41,    -1,    -1,    -1,   684,   685,    -1,    -1,
      -1,    -1,    -1,    -1,   692,    -1,    -1,    -1,   696,    -1,
      -1,    -1,   700,    62,    63,    -1,    65,    66,   706,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    43,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      -1,    90,    -1,    -1,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,   110,   111,    -1,   113,   114,   115,    -1,    -1,   118,
     119,    -1,   121,    -1,   123,   124,   125,   126,    -1,   128,
     129,    -1,   131,    -1,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,    -1,    -1,   185,   186,    -1,    -1,
     155,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,    41,    -1,
     185,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   869,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   877,
      -1,   879,    -1,    66,   882,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    90,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,
     113,   114,   115,    -1,    -1,   118,   119,    -1,   121,    -1,
     123,   124,   125,   126,    -1,   128,   129,    -1,   131,    -1,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
      -1,    -1,   185,   186,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    90,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,   101,
      -1,    -1,    -1,    41,    -1,    -1,    -1,   109,   110,   111,
      -1,   113,   114,   115,    52,    -1,   118,   119,    -1,   121,
      -1,   123,   124,   125,   126,    -1,   128,   129,    -1,   131,
      -1,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    -1,   180,   181,
     182,    41,    -1,   185,   186,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
     188,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    43,   188,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    43,   188,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    -1,   188,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,    -1,   188,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,   185,   186,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,   185,
     186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,    41,   188,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      63,    -1,    65,    66,    -1,    68,    69,    70,    71,    72,
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
      90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,
     110,   111,    -1,   113,   114,   115,    -1,    -1,   118,   119,
      -1,   121,    -1,   123,   124,   125,   126,    41,   128,   129,
      -1,   131,    -1,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,
     180,   181,   182,    -1,    -1,   185,   186,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,   113,
     114,   115,    -1,    -1,   118,   119,    -1,   121,    -1,   123,
     124,   125,   126,    -1,   128,   129,    -1,   131,    -1,   133,
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
         0,    15,   190,   191,   192,   194,   195,   196,   232,   292,
     180,     0,     9,    11,    12,    14,    21,    22,    39,   105,
     116,   117,   120,   122,   130,   132,   193,   236,   237,   252,
     255,   259,   298,   299,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   197,    13,   300,   300,
     300,   300,    37,   238,   253,   326,    20,   180,   181,   182,
     185,   186,   256,   257,   473,   474,   528,   529,   238,   528,
     300,   300,   326,    37,   327,   300,   327,    31,   289,   290,
     291,    17,   243,   293,     3,     4,   316,   318,   319,    16,
     198,   233,   528,     6,    24,   106,   107,   324,   325,   324,
     325,   328,   329,    23,    40,   260,   254,   473,   238,    40,
     265,   266,     6,   106,   322,   323,   322,   328,   322,   371,
     372,   373,   377,   378,    18,    19,   244,   245,   238,   296,
     297,   298,   326,   326,   317,   315,   319,   234,   163,   199,
     201,   202,    10,   301,   302,   528,    38,    32,    33,    34,
      35,    36,    52,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   183,   184,
     188,   330,   338,   405,   458,   459,   461,   462,   463,   472,
     474,   475,   518,   522,   523,   524,   525,   526,   527,   528,
     530,    24,   261,   262,   263,   264,   528,   326,   238,   258,
     265,    92,   267,   268,   272,    37,   163,   341,   343,   112,
     528,   112,    38,   112,   474,    41,   188,   380,    20,    41,
      66,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    90,    94,    95,    96,    97,    98,    99,   100,   101,
     109,   110,   111,   113,   114,   115,   118,   119,   121,   123,
     124,   125,   126,   128,   129,   131,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   248,   249,   250,   251,   397,   474,   499,   501,   503,
     504,   505,   508,   511,   513,   518,   522,   526,   528,   265,
      50,   294,   295,    40,   108,   320,   181,    56,   200,   324,
     460,   333,    44,   339,   340,   407,    41,   406,    89,   187,
     519,   520,   521,   264,   267,   265,   267,    26,    93,   269,
     275,   344,   322,   322,   322,   374,   379,    37,    41,    62,
      63,    65,   474,   476,   477,   480,   483,   484,   487,   488,
     494,   496,   497,   498,   499,   511,   516,   518,   522,   526,
     528,    76,    41,    41,    41,   188,   500,    41,   188,   403,
      41,    41,    41,    41,   506,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,   403,    41,    41,    41,
     188,   188,    41,    41,    41,    41,   188,    41,   188,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,   249,    41,    41,   188,   398,   267,   195,   292,   341,
      24,   321,   528,   235,    37,   104,   151,   153,   155,   203,
     204,   206,   207,   214,   216,   217,   224,   264,    51,   410,
     415,   473,   332,   334,   335,   330,   408,   409,   410,   458,
     464,   470,   472,   410,   528,   267,    41,   273,   274,   397,
     474,   499,   276,   277,   396,   397,   498,   499,    25,   270,
     278,    52,   239,   240,   342,   345,   346,   349,   420,   463,
     465,   466,   468,   472,    37,    42,   474,   384,   476,   497,
     497,   497,    91,   246,   247,   479,   482,    56,    57,    58,
      59,    60,    61,    66,    67,   485,   486,   493,   495,   398,
     517,   509,   476,   476,   476,   476,   476,   476,   476,   476,
     507,   476,   476,   476,   476,   474,   476,   476,   476,   476,
     476,   476,    18,   400,   400,   476,   476,   476,   476,   476,
     476,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     476,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     476,   476,   476,   400,   400,   528,   180,   225,    43,   104,
     164,   208,   209,   212,   385,   474,   518,   522,   526,   528,
     155,   218,   219,   222,   385,   207,   205,   217,   215,    53,
     416,   419,   470,    44,   331,     6,    42,   470,   476,   274,
     277,    26,    29,    30,   271,   284,   287,   288,   467,   241,
      38,   348,    44,   350,   351,    41,   422,   421,   375,    38,
      41,   188,   382,    42,   474,    42,    54,   478,    55,   481,
     487,   487,   487,   487,   487,   487,    67,   403,    62,    63,
     489,   492,   524,   525,    20,    64,   490,   510,    42,    42,
      42,   404,    49,    49,    49,    49,   341,    42,    42,    49,
      42,    42,    49,    42,    42,    42,    42,    49,    20,   476,
     512,   476,    42,    42,    49,    49,    42,    42,    42,    42,
      42,    42,    49,    42,    42,    42,    49,    42,    42,    42,
      49,    42,    42,    42,    42,    42,    49,    42,    42,    42,
     476,   476,    38,    41,   226,   212,   104,   222,   155,   205,
      44,   104,   210,   215,    44,   155,   220,   414,   418,   330,
     473,   247,    27,    28,   279,   280,   281,   282,   283,   396,
     474,   167,   167,   285,   288,   286,   287,    41,    51,    65,
     102,   425,   427,   433,   434,   439,   440,   443,   446,   448,
     450,   474,   528,   243,     6,     7,     8,    31,    45,    46,
      48,   127,   148,   347,   352,   353,   354,   356,   360,   364,
     369,   370,   386,   389,   390,   395,   346,   465,   469,   471,
     472,   423,   424,   425,   425,    38,   376,   385,   383,   480,
     483,   403,   494,   494,   490,   491,   496,   496,   341,   402,
     476,   476,   476,   476,   476,   476,   476,    42,    50,   514,
     515,   476,   476,   476,   476,   476,   476,    42,   399,   227,
     151,   213,   211,   154,   223,   221,    50,   413,    49,   417,
     336,    42,   280,   498,   439,    41,    51,   102,   451,   456,
     528,   446,    53,   426,   442,   445,    20,    62,   103,   447,
     449,   242,   357,   361,   365,   371,   355,   387,   396,    41,
     341,   331,   391,    42,   471,   381,    42,    49,   401,    49,
      42,    42,    49,    42,    42,   401,   502,    77,    42,    42,
      42,    42,   502,    42,    42,   402,   230,   209,   219,   411,
     412,   415,   419,    37,    42,   454,   455,   456,    51,   457,
     528,   435,   438,   471,   104,   441,    64,   444,   265,   358,
     362,   366,   341,   388,   476,   346,   341,    42,   385,   476,
     476,   476,    42,    56,    42,    42,    42,   229,   231,   385,
     416,   337,    42,   453,   432,   437,   443,   448,   267,   473,
     363,   367,   341,    91,   394,    42,   502,   527,    49,   228,
      56,   149,   150,   330,   104,   452,    50,   431,    49,   436,
     289,   359,   300,   300,   474,    47,   392,    42,   385,   385,
     385,    38,   456,   427,   428,   430,   438,   341,   473,   473,
      42,   393,   429,   341,    23,   341,   416,   326,   368,   265
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
     251,   252,   254,   253,   253,   255,   256,   256,   257,   257,
     258,   258,   259,   260,   261,   261,   262,   263,   264,   265,
     266,   266,   267,   268,   268,   269,   269,   270,   270,   271,
     271,   272,   273,   273,   274,   274,   274,   274,   275,   276,
     276,   277,   278,   279,   279,   280,   280,   281,   281,   282,
     283,   283,   284,   284,   285,   285,   286,   286,   287,   288,
     289,   290,   291,   291,   293,   292,   294,   295,   295,   296,
     297,   297,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   299,   300,   300,   301,   302,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   314,   315,   315,   316,   316,   317,   317,   318,   319,
     320,   321,   321,   322,   322,   323,   323,   324,   325,   325,
     325,   325,   326,   327,   329,   328,   330,   330,   331,   331,
     332,   333,   333,   335,   336,   337,   334,   338,   339,   340,
     340,   341,   341,   342,   342,   344,   343,   345,   346,   346,
     347,   348,   348,   349,   350,   351,   351,   352,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   353,   355,   354,
     357,   358,   359,   356,   361,   362,   363,   360,   365,   366,
     367,   368,   364,   369,   370,   371,   371,   373,   374,   372,
     375,   375,   376,   378,   377,   379,   379,   380,   380,   381,
     381,   383,   382,   382,   384,   384,   385,   385,   385,   385,
     385,   385,   385,   387,   388,   386,   390,   391,   389,   393,
     392,   394,   394,   395,   396,   396,   396,   397,   398,   399,
     398,   400,   400,   401,   402,   402,   403,   404,   403,   406,
     405,   407,   405,   408,   409,   409,   410,   411,   412,   412,
     413,   414,   414,   415,   415,   416,   417,   418,   418,   419,
     421,   420,   422,   420,   423,   424,   424,   426,   425,   427,
     427,   429,   428,   430,   430,   431,   432,   432,   433,   434,
     435,   436,   437,   437,   438,   439,   440,   441,   442,   442,
     443,   444,   445,   445,   446,   447,   447,   448,   448,   449,
     449,   449,   450,   450,   450,   450,   451,   451,   452,   453,
     453,   454,   455,   455,   456,   456,   456,   457,   457,   458,
     458,   460,   459,   461,   462,   462,   462,   462,   462,   463,
     463,   464,   464,   465,   465,   467,   466,   468,   469,   469,
     470,   470,   471,   471,   472,   472,   473,   473,   474,   474,
     475,   475,   475,   475,   475,   475,   476,   477,   478,   479,
     479,   480,   481,   482,   482,   483,   484,   485,   485,   486,
     486,   486,   486,   486,   486,   486,   486,   487,   488,   489,
     489,   490,   490,   491,   491,   492,   492,   492,   493,   493,
     494,   495,   495,   496,   496,   496,   496,   497,   497,   497,
     497,   497,   497,   497,   497,   498,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     500,   500,   501,   502,   502,   503,   504,   506,   507,   505,
     509,   510,   508,   511,   511,   511,   512,   512,   513,   513,
     513,   513,   513,   514,   515,   515,   516,   517,   517,   518,
     519,   520,   520,   521,   521,   522,   522,   522,   523,   523,
     523,   524,   524,   524,   525,   525,   525,   526,   526,   527,
     527,   527,   527,   528,   528,   529,   529,   530,   530
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
       1,     1,     1,     1,     1,     1,     1,     2,     0,     3,
       0,     0,     0,     6,     0,     0,     0,     7,     0,     0,
       0,     0,    10,     6,     2,     1,     1,     0,     0,     6,
       0,     2,     1,     0,     5,     0,     2,     1,     3,     0,
       2,     0,     4,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     0,     0,     4,     0,     0,     4,     0,
       3,     0,     2,     2,     1,     1,     1,     2,     1,     0,
       6,     0,     1,     2,     0,     2,     1,     0,     5,     0,
       3,     0,     3,     1,     0,     1,     3,     2,     0,     1,
       2,     0,     2,     1,     1,     2,     2,     0,     2,     1,
       0,     3,     0,     3,     1,     0,     1,     0,     4,     1,
       1,     0,     3,     0,     1,     2,     0,     2,     1,     1,
       2,     2,     0,     2,     1,     1,     2,     2,     0,     2,
       2,     2,     0,     2,     2,     0,     1,     1,     2,     1,
       1,     1,     1,     1,     2,     3,     1,     3,     2,     0,
       2,     2,     0,     1,     1,     1,     2,     1,     1,     1,
       1,     0,     4,     4,     1,     1,     1,     1,     1,     0,
       1,     1,     2,     1,     1,     0,     4,     4,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     0,
       2,     2,     2,     0,     2,     1,     2,     0,     1,     2,
       2,     2,     2,     2,     2,     2,     3,     1,     2,     1,
       1,     2,     2,     0,     1,     2,     2,     2,     0,     2,
       2,     0,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     4,     4,     6,     4,
       4,     4,     4,     2,     2,     4,     4,     4,     4,     2,
       1,     4,     1,     4,     4,     4,     6,     6,     6,     6,
       6,     4,     4,     4,     4,     4,     4,     4,     4,     2,
       2,     2,     4,     4,     4,     4,     4,     2,     8,     6,
       6,     6,     4,     4,     4,     4,     4,     1,     1,     1,
       3,     1,     7,     0,     1,     7,     9,     0,     0,     4,
       0,     0,     5,     5,     5,     6,     1,     1,     1,     1,
       1,     1,     1,     4,     0,     1,     2,     0,     1,     2,
       2,     1,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
  "@20", "@21", "ServiceGraphPattern", "@22", "@23", "@24",
  "SADIinvocation", "@25", "@26", "@27", "$@28", "Bind", "InlineData",
  "DataBlock", "InlineDataOneVar", "$@29", "$@30",
  "_QSingleValueRow_E_Star", "SingleValueRow", "InlineDataFull", "$@31",
  "_QVar_E_Star",
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
  "BlankNodePropertyList", "@46", "Generator",
  "_O_QIT_MEMBERS_E_Or_QIT_STARTS_E_Or_QIT_ENDS_E_Or_QIT_ANY_E_Or_QIT_UNORDERED_E_C",
  "_Q_O_QIT_MEMBERS_E_Or_QIT_STARTS_E_Or_QIT_ENDS_E_Or_QIT_ANY_E_Or_QIT_UNORDERED_E_C_E_Opt",
  "_QGraphNode_E_Plus", "TriplesNodePath", "BlankNodePropertyListPath",
  "@47", "GeneratorPath", "_QGraphNodePath_E_Plus", "GraphNode",
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
  "SubstringExpression", "StrReplaceExpression", "ExistsFunc", "@48",
  "@49", "NotExistsFunc", "@50", "@51", "Aggregate",
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
     193,   289,    -1,   236,    -1,   252,    -1,   255,    -1,   259,
      -1,   292,    -1,   196,   197,   198,    -1,    -1,   232,    -1,
      -1,   197,   233,    -1,    -1,   198,   199,    -1,    -1,   202,
     200,   203,    -1,   163,    56,    -1,    -1,   201,    -1,   204,
      -1,   214,    -1,   224,    -1,   264,    -1,   206,   207,   205,
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
     243,   238,   265,   267,    -1,    -1,   238,   260,    -1,    -1,
      -1,    -1,   240,   241,   243,   242,   265,   267,   289,    -1,
      17,   245,   251,    -1,    18,    -1,    19,    -1,    -1,   244,
      -1,    91,   474,    -1,    -1,   246,    -1,    41,   476,   247,
      42,    -1,   499,    -1,   518,    -1,   522,    -1,   526,    -1,
     474,    -1,   511,    -1,   397,    -1,   248,    -1,   249,    -1,
     250,   249,    -1,   250,    -1,    20,    -1,    21,   253,    -1,
      -1,   326,   254,   238,   265,   267,    -1,   238,    40,   326,
     267,    -1,    22,   257,   238,   258,   267,    -1,   473,    -1,
     256,   473,    -1,   256,    -1,    20,    -1,    -1,   265,    -1,
      39,   238,   265,   267,    -1,    23,   261,    -1,   262,    -1,
     263,    -1,   264,    -1,    24,   264,    -1,   528,    -1,   266,
     341,    -1,    -1,    40,    -1,   268,   269,   270,   271,    -1,
      -1,   272,    -1,    -1,   275,    -1,    -1,   278,    -1,    -1,
     284,    -1,    92,    26,   273,    -1,   274,    -1,   273,   274,
      -1,   499,    -1,   397,    -1,    41,   476,   247,    42,    -1,
     474,    -1,    93,   276,    -1,   277,    -1,   276,   277,    -1,
     396,    -1,    25,    26,   279,    -1,   280,    -1,   279,   280,
      -1,   282,    -1,   283,    -1,    27,    -1,    28,    -1,   281,
     498,    -1,   396,    -1,   474,    -1,   287,   285,    -1,   288,
     286,    -1,    -1,   288,    -1,    -1,   287,    -1,    29,   167,
      -1,    30,   167,    -1,   291,    -1,    31,   371,    -1,    -1,
     290,    -1,    -1,   195,   298,   293,   297,    -1,    50,   292,
      -1,    -1,   294,    -1,   298,   295,    -1,    -1,   296,    -1,
     299,    -1,   303,    -1,   304,    -1,   306,    -1,   307,    -1,
     308,    -1,   305,    -1,   309,    -1,   310,    -1,   311,    -1,
     312,    -1,     9,   300,   528,   302,    -1,    -1,    13,    -1,
      10,   324,    -1,    -1,   301,    -1,    11,   300,   325,    -1,
      14,   300,   325,    -1,    12,   300,   324,    -1,   116,   300,
     322,   112,   322,    -1,   130,   300,   322,   112,   322,    -1,
     117,   300,   322,   112,   322,    -1,   132,   327,    -1,   122,
     327,    -1,   120,   326,    -1,   314,   316,   317,    40,   341,
      -1,   105,   528,    -1,    -1,   313,    -1,    -1,   319,    -1,
     318,   315,    -1,   319,    -1,    -1,   317,   320,    -1,     3,
     326,    -1,     4,   326,    -1,   108,   321,    -1,   528,    -1,
      24,   528,    -1,   106,    -1,   323,   528,    -1,    -1,     6,
      -1,     6,   528,    -1,   324,    -1,   106,    -1,    24,    -1,
     107,    -1,    37,   328,    38,    -1,    37,   328,    38,    -1,
      -1,   329,   330,   333,    -1,    -1,   338,    -1,    -1,    44,
      -1,   334,   331,   330,    -1,    -1,   333,   332,    -1,    -1,
      -1,    -1,   335,     6,   473,   336,    37,   337,   330,    38,
      -1,   405,   340,    -1,    44,   330,    -1,    -1,   339,    -1,
     343,    -1,   163,    -1,   239,    -1,   345,    -1,    -1,    37,
     344,   342,    38,    -1,   346,   348,    -1,    -1,   349,    -1,
     352,   331,   346,    -1,    -1,   348,   347,    -1,   420,   351,
      -1,    44,   346,    -1,    -1,   350,    -1,   389,    -1,   354,
      -1,   386,    -1,   356,    -1,   360,    -1,   364,    -1,   395,
      -1,   369,    -1,   370,    -1,   353,    -1,   148,   341,    -1,
      -1,    45,   355,   341,    -1,    -1,    -1,    -1,     6,   357,
     358,   473,   359,   341,    -1,    -1,    -1,    -1,     7,   361,
     362,   363,   300,   473,   341,    -1,    -1,    -1,    -1,    -1,
       8,   365,   366,   367,   300,   473,    23,   326,   368,   265,
      -1,   127,    41,   476,    91,   474,    42,    -1,    31,   371,
      -1,   372,    -1,   377,    -1,    -1,    -1,   373,   474,   374,
      37,   375,    38,    -1,    -1,   375,   376,    -1,   385,    -1,
      -1,   378,   380,    37,   384,    38,    -1,    -1,   379,   474,
      -1,   188,    -1,    41,   379,    42,    -1,    -1,   381,   385,
      -1,    -1,    41,   383,   381,    42,    -1,   188,    -1,    -1,
     384,   382,    -1,   528,    -1,   518,    -1,   522,    -1,   526,
      -1,    43,    -1,   164,    -1,   474,    -1,    -1,    -1,    46,
     387,   388,   341,    -1,    -1,    -1,   390,   391,   341,   394,
      -1,    -1,    47,   393,   341,    -1,    -1,   394,   392,    -1,
      48,   396,    -1,   498,    -1,   499,    -1,   397,    -1,   528,
     398,    -1,   188,    -1,    -1,    41,   400,   476,   399,   402,
      42,    -1,    -1,    18,    -1,    49,   476,    -1,    -1,   402,
     401,    -1,   188,    -1,    -1,    41,   476,   404,   402,    42,
      -1,    -1,   472,   406,   410,    -1,    -1,   458,   407,   408,
      -1,   409,    -1,    -1,   410,    -1,   415,   416,   414,    -1,
     415,   416,    -1,    -1,   411,    -1,    50,   412,    -1,    -1,
     414,   413,    -1,   473,    -1,    51,    -1,   419,   418,    -1,
      49,   419,    -1,    -1,   418,   417,    -1,   470,    -1,    -1,
     472,   421,   425,    -1,    -1,   465,   422,   423,    -1,   424,
      -1,    -1,   425,    -1,    -1,   427,   426,   435,   432,    -1,
     433,    -1,   434,    -1,    -1,   427,   429,   416,    -1,    -1,
     428,    -1,    50,   430,    -1,    -1,   432,   431,    -1,   439,
      -1,   474,    -1,   438,   437,    -1,    49,   438,    -1,    -1,
     437,   436,    -1,   471,    -1,   440,    -1,   443,   442,    -1,
     104,   443,    -1,    -1,   442,   441,    -1,   448,   445,    -1,
      64,   448,    -1,    -1,   445,   444,    -1,   450,   447,    -1,
      -1,   449,    -1,   446,    -1,   102,   446,    -1,   103,    -1,
      20,    -1,    62,    -1,   528,    -1,    51,    -1,    65,   451,
      -1,    41,   439,    42,    -1,   456,    -1,    41,   455,    42,
      -1,   104,   456,    -1,    -1,   453,   452,    -1,   456,   453,
      -1,    -1,   454,    -1,   528,    -1,    51,    -1,   102,   457,
      -1,   528,    -1,    51,    -1,   461,    -1,   459,    -1,    -1,
      52,   460,   410,    53,    -1,   463,    41,   464,    42,    -1,
      32,    -1,    33,    -1,    34,    -1,    35,    -1,    36,    -1,
      -1,   462,    -1,   470,    -1,   464,   470,    -1,   468,    -1,
     466,    -1,    -1,    52,   467,   425,    53,    -1,   463,    41,
     469,    42,    -1,   471,    -1,   469,   471,    -1,   472,    -1,
     458,    -1,   472,    -1,   465,    -1,   474,    -1,   475,    -1,
     474,    -1,   528,    -1,   185,    -1,   186,    -1,   528,    -1,
     518,    -1,   522,    -1,   526,    -1,   530,    -1,   188,    -1,
     477,    -1,   480,   479,    -1,    54,   480,    -1,    -1,   479,
     478,    -1,   483,   482,    -1,    55,   483,    -1,    -1,   482,
     481,    -1,   484,    -1,   487,   485,    -1,    -1,   486,    -1,
      56,   487,    -1,    57,   487,    -1,    58,   487,    -1,    59,
     487,    -1,    60,   487,    -1,    61,   487,    -1,    67,   403,
      -1,    66,    67,   403,    -1,   488,    -1,   494,   493,    -1,
     524,    -1,   525,    -1,    20,   496,    -1,    64,   496,    -1,
      -1,   490,    -1,    62,   494,    -1,    63,   494,    -1,   489,
     491,    -1,    -1,   493,   492,    -1,   496,   495,    -1,    -1,
     495,   490,    -1,    65,   497,    -1,    62,   497,    -1,    63,
     497,    -1,   497,    -1,   498,    -1,   499,    -1,   516,    -1,
     518,    -1,   522,    -1,   526,    -1,   474,    -1,   511,    -1,
      41,   476,    42,    -1,    78,    41,   476,    42,    -1,    79,
      41,   476,    42,    -1,    80,    41,   476,    49,   476,    42,
      -1,    81,    41,   476,    42,    -1,    82,    41,   474,    42,
      -1,    68,    41,   476,    42,    -1,    69,    41,   476,    42,
      -1,    70,   500,    -1,   118,   188,    -1,   142,    41,   476,
      42,    -1,   139,    41,   476,    42,    -1,   131,    41,   476,
      42,    -1,   125,    41,   476,    42,    -1,    90,   403,    -1,
     503,    -1,   145,    41,   476,    42,    -1,   504,    -1,   143,
      41,   476,    42,    -1,   141,    41,   476,    42,    -1,   137,
      41,   476,    42,    -1,   128,    41,   476,    49,   476,    42,
      -1,   138,    41,   476,    49,   476,    42,    -1,   144,    41,
     476,    49,   476,    42,    -1,   113,    41,   476,    49,   476,
      42,    -1,   114,    41,   476,    49,   476,    42,    -1,   115,
      41,   476,    42,    -1,   147,    41,   476,    42,    -1,   140,
      41,   476,    42,    -1,   136,    41,   476,    42,    -1,   133,
      41,   476,    42,    -1,   129,    41,   476,    42,    -1,   124,
      41,   476,    42,    -1,   123,    41,   476,    42,    -1,   121,
     188,    -1,   109,   188,    -1,   110,   188,    -1,   111,    41,
     476,    42,    -1,   146,    41,   476,    42,    -1,   135,    41,
     476,    42,    -1,   126,    41,   476,    42,    -1,   119,    41,
     476,    42,    -1,    71,   403,    -1,    72,    41,   476,    49,
     476,    49,   476,    42,    -1,    73,    41,   476,    49,   476,
      42,    -1,    74,    41,   476,    49,   476,    42,    -1,    83,
      41,   476,    49,   476,    42,    -1,    84,    41,   476,    42,
      -1,    85,    41,   476,    42,    -1,    86,    41,   476,    42,
      -1,    87,    41,   476,    42,    -1,   101,    41,   476,    42,
      -1,   501,    -1,   505,    -1,   508,    -1,    41,   476,    42,
      -1,   188,    -1,    88,    41,   476,    49,   476,   502,    42,
      -1,    -1,   401,    -1,   134,    41,   476,    49,   476,   502,
      42,    -1,    75,    41,   476,    49,   476,    49,   476,   502,
      42,    -1,    -1,    -1,    76,   506,   507,   341,    -1,    -1,
      -1,    66,    76,   509,   510,   341,    -1,    94,    41,   400,
     512,    42,    -1,   513,    41,   400,   476,    42,    -1,    99,
      41,   400,   476,   515,    42,    -1,    20,    -1,   476,    -1,
      95,    -1,    96,    -1,    97,    -1,    98,    -1,   100,    -1,
      50,    77,    56,   527,    -1,    -1,   514,    -1,   528,   517,
      -1,    -1,   398,    -1,   527,   521,    -1,    89,   528,    -1,
     187,    -1,   519,    -1,    -1,   520,    -1,   523,    -1,   524,
      -1,   525,    -1,   167,    -1,   168,    -1,   169,    -1,   170,
      -1,   171,    -1,   172,    -1,   173,    -1,   174,    -1,   175,
      -1,   165,    -1,   166,    -1,   176,    -1,   178,    -1,   177,
      -1,   179,    -1,   180,    -1,   529,    -1,   182,    -1,   181,
      -1,   183,    -1,   184,    -1
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
     643,   645,   647,   649,   651,   653,   655,   657,   660,   661,
     665,   666,   667,   668,   675,   676,   677,   678,   686,   687,
     688,   689,   690,   701,   708,   711,   713,   715,   716,   717,
     724,   725,   728,   730,   731,   737,   738,   741,   743,   747,
     748,   751,   752,   757,   759,   760,   763,   765,   767,   769,
     771,   773,   775,   777,   778,   779,   784,   785,   786,   791,
     792,   796,   797,   800,   803,   805,   807,   809,   812,   814,
     815,   822,   823,   825,   828,   829,   832,   834,   835,   841,
     842,   846,   847,   851,   853,   854,   856,   860,   863,   864,
     866,   869,   870,   873,   875,   877,   880,   883,   884,   887,
     889,   890,   894,   895,   899,   901,   902,   904,   905,   910,
     912,   914,   915,   919,   920,   922,   925,   926,   929,   931,
     933,   936,   939,   940,   943,   945,   947,   950,   953,   954,
     957,   960,   963,   964,   967,   970,   971,   973,   975,   978,
     980,   982,   984,   986,   988,   991,   995,   997,  1001,  1004,
    1005,  1008,  1011,  1012,  1014,  1016,  1018,  1021,  1023,  1025,
    1027,  1029,  1030,  1035,  1040,  1042,  1044,  1046,  1048,  1050,
    1051,  1053,  1055,  1058,  1060,  1062,  1063,  1068,  1073,  1075,
    1078,  1080,  1082,  1084,  1086,  1088,  1090,  1092,  1094,  1096,
    1098,  1100,  1102,  1104,  1106,  1108,  1110,  1112,  1115,  1118,
    1119,  1122,  1125,  1128,  1129,  1132,  1134,  1137,  1138,  1140,
    1143,  1146,  1149,  1152,  1155,  1158,  1161,  1165,  1167,  1170,
    1172,  1174,  1177,  1180,  1181,  1183,  1186,  1189,  1192,  1193,
    1196,  1199,  1200,  1203,  1206,  1209,  1212,  1214,  1216,  1218,
    1220,  1222,  1224,  1226,  1228,  1230,  1234,  1239,  1244,  1251,
    1256,  1261,  1266,  1271,  1274,  1277,  1282,  1287,  1292,  1297,
    1300,  1302,  1307,  1309,  1314,  1319,  1324,  1331,  1338,  1345,
    1352,  1359,  1364,  1369,  1374,  1379,  1384,  1389,  1394,  1399,
    1402,  1405,  1408,  1413,  1418,  1423,  1428,  1433,  1436,  1445,
    1452,  1459,  1466,  1471,  1476,  1481,  1486,  1491,  1493,  1495,
    1497,  1501,  1503,  1511,  1512,  1514,  1522,  1532,  1533,  1534,
    1539,  1540,  1541,  1547,  1553,  1559,  1566,  1568,  1570,  1572,
    1574,  1576,  1578,  1580,  1585,  1586,  1588,  1591,  1592,  1594,
    1597,  1600,  1602,  1604,  1605,  1607,  1609,  1611,  1613,  1615,
    1617,  1619,  1621,  1623,  1625,  1627,  1629,  1631,  1633,  1635,
    1637,  1639,  1641,  1643,  1645,  1647,  1649,  1651,  1653
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
    1593,  1594,  1595,  1596,  1597,  1598,  1601,  1605,  1611,  1611,
    1627,  1631,  1633,  1627,  1644,  1648,  1650,  1644,  1661,  1665,
    1667,  1670,  1661,  1688,  1699,  1705,  1706,  1710,  1712,  1710,
    1719,  1721,  1725,  1733,  1733,  1740,  1742,  1748,  1749,  1752,
    1754,  1760,  1760,  1765,  1771,  1773,  1777,  1780,  1783,  1786,
    1789,  1792,  1795,  1801,  1805,  1801,  1815,  1819,  1815,  1829,
    1829,  1841,  1843,  1847,  1857,  1858,  1859,  1863,  1871,  1875,
    1875,  1885,  1888,  1895,  1901,  1903,  1917,  1920,  1920,  1930,
    1930,  1933,  1933,  1939,  1942,  1944,  1949,  1954,  1958,  1960,
    1965,  1969,  1971,  1975,  1979,  1987,  1992,  1996,  1998,  2002,
    2010,  2010,  2013,  2013,  2019,  2022,  2024,  2028,  2028,  2034,
    2035,  2039,  2039,  2044,  2046,  2050,  2053,  2055,  2059,  2063,
    2069,  2073,  2076,  2078,  2082,  2089,  2093,  2097,  2100,  2102,
    2106,  2110,  2115,  2117,  2123,  2126,  2128,  2134,  2135,  2141,
    2142,  2143,  2147,  2150,  2153,  2156,  2162,  2163,  2167,  2170,
    2172,  2176,  2179,  2181,  2185,  2186,  2187,  2191,  2192,  2198,
    2199,  2203,  2203,  2216,  2244,  2247,  2250,  2253,  2256,  2263,
    2266,  2271,  2275,  2282,  2283,  2287,  2287,  2299,  2326,  2330,
    2337,  2338,  2342,  2343,  2347,  2350,  2354,  2357,  2363,  2364,
    2368,  2371,  2374,  2377,  2380,  2381,  2387,  2392,  2401,  2408,
    2411,  2419,  2428,  2435,  2438,  2445,  2450,  2463,  2467,  2471,
    2475,  2479,  2483,  2487,  2491,  2495,  2499,  2506,  2511,  2520,
    2523,  2530,  2533,  2540,  2543,  2548,  2551,  2555,  2569,  2572,
    2580,  2589,  2592,  2599,  2602,  2605,  2608,  2612,  2613,  2614,
    2615,  2618,  2621,  2624,  2627,  2631,  2637,  2640,  2643,  2646,
    2649,  2652,  2655,  2659,  2662,  2665,  2668,  2671,  2674,  2677,
    2680,  2681,  2684,  2685,  2688,  2691,  2694,  2697,  2700,  2703,
    2706,  2709,  2712,  2715,  2718,  2721,  2724,  2727,  2730,  2733,
    2736,  2739,  2742,  2745,  2748,  2751,  2754,  2757,  2760,  2763,
    2766,  2769,  2772,  2775,  2778,  2781,  2784,  2787,  2788,  2789,
    2795,  2798,  2805,  2812,  2815,  2819,  2825,  2831,  2834,  2831,
    2846,  2849,  2846,  2862,  2866,  2871,  2880,  2883,  2887,  2890,
    2893,  2896,  2899,  2905,  2911,  2914,  2918,  2928,  2931,  2936,
    2944,  2951,  2955,  2963,  2967,  2971,  2972,  2973,  2977,  2978,
    2979,  2983,  2984,  2985,  2989,  2990,  2991,  2995,  2996,  3000,
    3001,  3002,  3003,  3007,  3008,  3012,  3013,  3017,  3018
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
  const int SPARQLfedParser::yylast_ = 2688;
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
#line 5965 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 3024 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


