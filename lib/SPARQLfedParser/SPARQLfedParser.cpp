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
#line 313 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"

/* Line 299 of lalr1.cc  */
#line 466 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

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
#line 480 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 483 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 494 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 538 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.startBindingSet();
      }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 541 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 556 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = (yysemantic_stack_[(2) - (1)].p_RSName);
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 562 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = NULL;
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 572 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	throw std::runtime_error("need to partition out results set part of SimpleEngine::loadDataOrResults");
    }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 606 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 608 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 614 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 652 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 654 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 660 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 679 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow(false);
      }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 681 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 701 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 704 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
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
#line 713 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 719 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 721 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 723 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 731 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 734 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause);
	(yyval.p_Operation) = new Select((yysemantic_stack_[(5) - (2)].p_Project).distinctness, (yysemantic_stack_[(5) - (2)].p_Project).varSet, (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
	driver.countStar = (yysemantic_stack_[(5) - (1)].p_parentCountStar);
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 743 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 746 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 754 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 757 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 760 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 764 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 775 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 783 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 786 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 793 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 801 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 808 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 816 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 823 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 826 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 829 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 832 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 835 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
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
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 850 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 853 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 861 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 864 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 870 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(2) - (2)].p_Operation);
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
	  driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause);
	  /* $1 is NO LONGER known to be a DefaultGraphPattern because of grammar restrictions. */
	  (yyval.p_Operation) = new Construct((yysemantic_stack_[(5) - (1)].p_TableOperation), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
      }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 883 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	SWObjectDuplicator dup(driver.atomFactory);
	(yysemantic_stack_[(4) - (3)].p_TableOperation)->express(&dup);
	driver.lastWhereClause = new WhereClause((yysemantic_stack_[(4) - (3)].p_TableOperation));
	(yyval.p_Operation) = new Construct(dup.last.tableOperation, (yysemantic_stack_[(4) - (1)].p_DatasetClauses), driver.lastWhereClause, (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 893 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause) ? (yysemantic_stack_[(5) - (4)].p_WhereClause) : new WhereClause(new DefaultGraphPattern());
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 901 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm))));
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 904 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_TTerm))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 912 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 915 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 922 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 930 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(3) - (3)].p_WhereClause);
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(3) - (2)].p_DatasetClauses), (yysemantic_stack_[(3) - (3)].p_WhereClause));
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 938 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 950 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 956 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 962 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 969 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.ensureGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 983 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 990 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 998 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1006 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1014 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1022 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1029 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1032 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1039 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1042 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1045 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1048 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1054 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1060 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1063 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1075 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1082 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1086 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1096 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1104 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1107 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1115 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1124 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1131 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1135 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1143 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1151 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1158 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1164 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1174 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = (yysemantic_stack_[(2) - (2)].p_BindingClause);
    }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1180 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1187 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	OperationSet* ret = driver.root ? dynamic_cast<OperationSet*>(driver.root) : new OperationSet();
	ret->push_back((yysemantic_stack_[(2) - (2)].p_Operation));
	driver.root = ret;
      }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1191 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Operation) = driver.root;
	}
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1225 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(3) - (2)].p_URI), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1232 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1239 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1246 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1252 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1255 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1261 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1267 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1273 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1279 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1285 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1291 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1299 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1307 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1314 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(5) - (1)].p_URI))
	    w3c_sw_NEED_IMPL("WITH <URI> (DELETE INSERT?|INSERT) ...");
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(5) - (2)].p_DeleteInsert).del, (yysemantic_stack_[(5) - (2)].p_DeleteInsert).ins, new WhereClause(driver.ensureGraphPattern()));
	driver.curOp = NULL;
    }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1323 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1329 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1336 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1343 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1347 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1355 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("_QUsingClause_E_Star");
    }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1361 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Delete) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1367 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = new Insert((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1373 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
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
#line 1382 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 1388 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1391 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 1402 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 1408 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 1411 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("DEFAULT");
      }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 1414 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("NAMED");
      }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1417 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("ALL");
      }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 1424 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
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
	driver.curBGP = NULL;
      }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 1438 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TableOperation) = driver.ensureGraphPattern();
	  driver.curOp = NULL;
      }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 1466 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 1471 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 1474 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 1477 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 1499 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 244:

/* Line 690 of lalr1.cc  */
#line 1518 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 1520 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 1591 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_BindingClause)) : (yysemantic_stack_[(1) - (1)].p_BindingClause);
    }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 1598 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Print(driver.curOp);
    }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 1604 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 1608 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 268:

/* Line 690 of lalr1.cc  */
#line 1620 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 1624 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 1626 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 1629 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 1637 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 1641 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 1643 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 1646 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(7) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(7) - (6)].p_TTerm), driver.curOp, (yysemantic_stack_[(7) - (5)].p_Silence), driver.atomFactory, false));
	  driver.curGraphName = (yysemantic_stack_[(7) - (4)].p_TTerm);
      }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 1654 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Bind(driver.ensureGraphPattern(), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
	// no more triples go into the current BGP, per
	//   http://www.w3.org/TR/sparql11-query/#sparqlTranslateGraphPatterns
	// test reference:
	//   http://www.sparql.org/query-validator?query=ASK+{+%3Fs+%3Fp+%3Fo+FILTER+%281%29+BIND+%282+AS+%3Fb%29+%3Fs2+%3Fp2+%3Fo2+FILTER+%283%29+BIND+%284+AS+%3Fd%29}&languageSyntax=SPARQL&outputFormat=algebra&linenumbers=false
	driver.curBGP = NULL;
    }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 1665 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = (yysemantic_stack_[(2) - (2)].p_BindingClause);
    }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 1676 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 1678 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
      }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 1680 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 1691 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
	driver.endBindingRow();
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 1699 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 1701 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 1708 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 1720 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 1726 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 1728 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 1731 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 1743 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 1746 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 1749 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 1752 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 1755 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 1758 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 1761 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 1767 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 1771 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 1773 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 1781 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 1785 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 1787 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 1795 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 1800 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.ensureGraphPattern());
      }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 1813 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    driver.ensureGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 1829 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 1837 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 1841 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 1844 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yysemantic_stack_[(6) - (4)].p_Expressions);
      }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 1851 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 1854 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 1861 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 1869 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 1883 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 1886 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 1889 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(5) - (3)].p_Expressions);
      }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 1896 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 1899 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 1943 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 1947 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 1970 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 1978 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 1981 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 1987 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 1998 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 2026 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 2053 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 2060 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 2071 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 2078 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 2114 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 2117 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 2120 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 2123 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 2181 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 2185 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 2194 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 422:

/* Line 690 of lalr1.cc  */
#line 2221 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 2224 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 2227 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 2230 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 2233 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 2240 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 2248 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 2252 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 2264 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 2271 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 2274 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 2285 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 2288 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 2291 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 2294 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 2298 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 2309 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 2318 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 2325 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 2328 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 2336 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 2345 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 2352 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 2355 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 2367 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 456:

/* Line 690 of lalr1.cc  */
#line 2380 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = NULL;
    }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 2388 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 2392 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 2396 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 2400 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 2404 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 2408 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 2412 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 2416 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = true;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 2428 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 2437 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 2440 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 2447 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 2450 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 2457 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 2465 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 2468 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 2472 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 477:

/* Line 690 of lalr1.cc  */
#line 2486 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 2489 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 2497 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 2506 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 2509 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 2516 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 2519 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 2522 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 2532 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 2535 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 2538 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 2541 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 2548 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 2554 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 2557 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 2560 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 2563 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 2566 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 2569 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 2572 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 2576 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 2579 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 2582 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 2585 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ceil, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 2588 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 2591 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 2594 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 2598 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 2601 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 2604 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 2607 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 2610 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 2613 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 2616 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 2619 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 2622 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 2625 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 2628 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 2631 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 2634 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 2637 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 2640 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 2643 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 2646 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 2649 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 2652 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_uuid, NULL, NULL, NULL));
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 2655 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_struuid, NULL, NULL, NULL));
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 2658 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 2661 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 2664 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 2667 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 2670 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 2673 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 2676 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 2679 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 2682 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 2685 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 2688 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 2691 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 2694 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 2697 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 2700 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 2711 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 2714 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 2721 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 2728 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 2735 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 2741 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 2744 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 2747 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 2751 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expression) = new ExistsExpression(driver.ensureGraphPattern());
	  driver.curOp = (yysemantic_stack_[(5) - (4)].p_TableOperation);
	  driver.curGraphName = (yysemantic_stack_[(5) - (3)].p_TTerm);
	  driver.countStar = (yysemantic_stack_[(5) - (2)].p_parentCountStar);
      }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 2760 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 2763 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 2766 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 2770 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  // $$ = new ExistsExpression(false, driver.ensureGraphPattern());
	  (yyval.p_Expression) = new BooleanNegation(new ExistsExpression(driver.ensureGraphPattern()));
	  driver.curOp = (yysemantic_stack_[(6) - (5)].p_TableOperation);
	  driver.curGraphName = (yysemantic_stack_[(6) - (4)].p_TTerm);
	  driver.countStar = (yysemantic_stack_[(6) - (3)].p_parentCountStar);
      }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 2780 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 2784 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 2789 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  AggregateCall::ScalarVals svals;
	  if ((yysemantic_stack_[(6) - (5)].p_RDFLiteral) != NULL)
	      svals["separator"] = (yysemantic_stack_[(6) - (5)].p_RDFLiteral)->getLexicalValue();
	  (yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression), svals));
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 2798 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 2805 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 2808 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 2811 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 2814 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 2817 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 2823 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 2829 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 2836 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 2846 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 2854 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 2862 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 2869 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 2873 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 2881 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 690 of lalr1.cc  */
#line 3834 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -843;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        64,   -94,   103,  -843,  -843,  -843,   403,  -843,  -843,  -843,
    -843,  -843,   158,   129,   129,   129,    77,     8,  -843,   158,
     129,   129,    77,   135,   129,   135,   160,  -843,   149,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,   140,   188,  -843,  -843,  -843,
     199,  -843,  -843,    41,   205,    41,  -843,    37,  -843,  -843,
    -843,  -843,  -843,   185,  -843,  -843,  -843,  -843,    46,  -843,
      50,    50,  -843,  -843,  -843,    50,  -843,   -18,  -843,  -843,
    -843,    69,  -843,   168,    77,    77,  -843,   217,  -843,  -843,
      61,  -843,   205,  -843,  -843,   158,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,   192,   949,    16,    77,  -843,  -843,  -843,
       6,  -843,  -843,     1,  -843,  -843,   115,   158,   125,   213,
     145,  -843,  -843,   -36,  -843,   -10,  -843,  -843,  -843,  1452,
      46,    63,  -843,  -843,  -843,  -843,    15,  -843,  -843,    80,
     209,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,   225,  -843,  -843,  -843,  -843,   220,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,   -30,  -843,
    -843,   158,  -843,  -843,  -843,  -843,  -843,   181,    46,   181,
    -843,  -843,  -843,  -843,  -843,    50,  -843,    50,  -843,    50,
    -843,  -843,  -843,   237,  -843,  1656,   201,   248,   252,    -8,
      -6,   254,   255,   260,  -843,   264,   265,   268,   269,   273,
     289,   294,   299,   300,   301,   304,    -6,   306,  -843,  -843,
    -843,  -843,   307,  -843,   309,   166,   173,   315,   326,   327,
     332,   189,   334,   190,   339,   340,   341,   343,   344,   345,
     347,   348,   355,   363,   365,   366,   368,   369,   370,   377,
     378,   380,   381,   382,   385,   386,  -843,  -843,  1776,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,   388,  -843,
    -843,  -843,    -5,   181,   444,  -843,  -843,     1,    26,  -843,
    -843,  -843,    98,   123,   423,   949,  -843,  -843,   123,  1476,
     123,   158,  -843,  -843,  -843,  -843,  -843,   405,  -843,   349,
    -843,   181,  -843,   922,  -843,  -843,  -843,   396,     0,  -843,
    1656,  1896,  1896,  1896,  -843,   346,  -843,  -843,  -843,  -843,
     267,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,    -5,  -843,  1656,  1656,  1656,  -843,  -843,  1656,
    -843,  -843,  1656,  1656,  1656,  -843,  1656,  1656,  1656,  1656,
     -36,  1656,  1656,  1656,  1656,  1656,  1656,  -843,   419,   419,
    1656,  -843,  -843,  1656,  1656,  1656,  1656,  -843,  1656,  -843,
    1656,  1656,  1656,  1656,  1656,  1656,  1656,  1656,  1656,  1656,
    1656,  1656,  1656,  1656,  1656,  1656,  1656,  1656,  1656,  1656,
    1656,  1656,  -843,   419,   419,  -843,  -843,  -843,  -843,   158,
    -843,  -843,   266,  -843,  2088,  -843,  -843,  2040,  -843,  -843,
     336,  -843,  -843,   292,  -843,  -843,  -843,  -843,   395,  1476,
    -843,  -843,   406,   442,  -843,  -843,  -843,  -843,  -843,  1106,
    -843,  -843,  -843,  -843,  2016,  2240,   426,  -843,  -843,  -843,
    -843,   414,  -843,  -843,  -843,   410,  -843,  -843,  -843,  -843,
    -843,   -14,   418,  -843,  -843,  -843,   -36,  -843,   421,   411,
     409,  1656,  1656,  1656,  1656,  1656,  1656,   399,    -6,  -843,
    -843,   221,    43,  -843,  -843,  -843,   425,   428,   430,  -843,
     424,   429,   432,  -843,   433,   435,   434,   437,   443,   438,
     449,   450,   451,   452,   447,  -843,  1278,  1656,   455,   458,
     453,   454,   463,   464,   466,   470,   472,   473,   467,   475,
     478,   483,   479,   485,   493,   494,   488,   496,   498,   499,
     500,   502,   497,   503,   505,   507,  1656,  1656,  -843,  -843,
      32,  -843,  -843,  -843,  2120,  -843,  -843,   371,  -843,  -843,
    -843,  -843,  -843,  -843,  2120,  -843,  -843,   314,  -843,    23,
    -843,    -3,  -843,  -843,  -843,  -843,  -843,   949,   185,  -843,
    -843,  1656,  2016,  -843,  -843,  -843,  -843,  2240,  -843,  -843,
    -843,  -843,  -843,   524,   169,  -843,   149,  -843,    82,   949,
    -843,  -843,   123,    40,  1515,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  1656,  -843,  1656,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,    -6,  -843,  1656,  1656,    43,  -843,  -843,  -843,
    1656,  1656,  -843,  -843,  -843,  -843,  -843,  -843,  1656,  1656,
    1656,     1,  -843,  -843,  1656,  -843,  -843,  1656,  -843,  -843,
    -843,  -843,  1656,  -843,  -843,   509,   504,  -843,  -843,  1656,
    1656,  -843,  -843,  -843,  -843,  -843,  -843,  1656,  -843,  -843,
    -843,  1656,  -843,  -843,  -843,  1656,  -843,  -843,  -843,  -843,
    -843,  1656,  -843,  -843,  -843,   510,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,   -47,  -843,  -843,  -843,    79,  -843,
    -843,  -843,   506,   508,  -843,  -843,   346,  -843,  -843,  1116,
     389,   392,  -843,  -843,   531,   539,  -843,  -843,  -843,   -18,
    -843,  -843,  2240,   528,     1,  -843,   406,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
      58,  -843,    74,    78,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,   253,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
       1,    53,   521,   532,   535,  -843,   536,   537,   533,  -843,
     511,  -843,   538,   541,   542,   547,   533,   552,   553,  -843,
    -843,  -843,  -843,  -843,  2088,  -843,  -843,  2040,   123,  -843,
    1476,  -843,   544,   555,  -843,  -843,  1116,  -843,   557,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,   559,
    -843,  -843,  -843,     1,  -843,  -843,  1656,  -843,   949,     1,
     558,   101,  -843,    83,  -843,  -843,  -843,  -843,  -843,  -843,
    1476,   501,   545,  -843,    -4,  -843,  -843,  -843,  -843,  -843,
    2001,  -843,  -843,  1656,  -843,  1656,  -843,  -843,  -843,  -843,
    -843,   560,   549,  -843,  -843,  -843,  -843,   561,  -843,  -843,
      59,  2064,  -843,  -843,  -843,  -843,  1476,  -843,  -843,  -843,
    -843,  -843,   181,   185,  -843,  -843,     1,   516,  -843,  -843,
    -843,  -843,   566,  -843,  -843,  -843,  -843,  -843,    58,  -843,
      58,  -843,   448,  -843,  -843,    34,  -843,  -843,  -843,   571,
    -843,   144,  -843,  -843,  -843,  -843,   567,    12,  -843,   949,
     160,  -843,   129,  -843,   -36,   554,  -843,   512,   568,  -843,
    -843,   581,  -843,    24,  -843,  -843,  -843,  -843,  -843,  2120,
    2120,  2120,   582,  -843,     1,   185,   579,  -843,  -843,   101,
    -843,    40,  -843,  -843,  -843,  -843,   584,  -843,  -843,  -843,
    -843,  -843,     1,  -843,     1,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  1476,  -843
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        12,     0,     0,     2,     4,     3,   199,    14,    13,    10,
      68,     1,     0,   187,   187,   187,    74,     0,    74,     0,
     187,   187,     0,     0,   187,     0,   162,     6,     0,     7,
       8,     9,   164,   171,   172,   173,   177,   174,   175,   176,
     178,   179,   180,   181,   200,     0,    16,   602,   605,   604,
     184,   603,   188,     0,     0,     0,   223,     0,   101,   102,
     109,   437,   438,   108,    74,   106,   435,   436,   120,   198,
     214,   214,   196,   223,   195,   214,   194,   280,     5,   163,
     160,    83,    74,   169,     0,     0,   205,   201,   204,    69,
      11,    15,     0,   185,   182,     0,   219,   218,   220,   217,
     186,   190,   189,     0,   225,     0,     0,    75,    74,   107,
     110,   121,   112,     0,   215,   212,     0,     0,     0,     0,
       0,   161,   278,     0,   279,     0,    81,    82,    84,     0,
     120,    12,   170,   165,   207,   208,     0,   203,   202,     0,
       0,    17,    22,    18,   183,   216,   221,   422,   423,   424,
     425,   426,   419,   596,   597,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   598,   600,   599,   601,   606,   607,
     444,   230,   226,   238,   334,   418,   417,   428,     0,   332,
     433,   434,   440,   441,   584,   585,   586,   442,   582,   439,
     443,     0,   113,   114,   115,   116,   118,   123,   120,   123,
     111,   244,   241,   119,   240,   214,   213,   214,   222,   214,
     281,   288,   290,     0,   100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   554,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   567,   568,
     569,   570,     0,   571,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    99,    80,
      95,    93,    89,   545,   509,   546,   547,    94,     0,    90,
      91,    92,     0,   123,   199,   167,   168,     0,     0,   206,
      70,    20,     0,     0,   224,   225,   239,   236,   344,   427,
       0,     0,   580,   581,   583,   578,   117,     0,   104,   125,
     124,   123,   105,   247,   191,   193,   192,     0,     0,   297,
       0,     0,     0,     0,   492,    86,   445,   448,   452,   454,
     456,   466,   477,   480,   485,   486,   487,   493,   488,   489,
     490,   491,   576,   558,     0,     0,     0,   549,   502,     0,
     329,   535,     0,     0,     0,   555,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   508,   324,   324,
       0,   528,   529,     0,     0,     0,     0,   503,     0,   527,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,   324,   324,   321,   320,    73,   197,     0,
     209,   210,     0,    56,     0,    31,    45,     0,    19,    23,
       0,    29,    24,     0,    43,    25,    26,   347,     0,   427,
     346,   231,   227,     0,   237,   345,   335,   343,   432,   427,
     429,   431,   333,   579,     0,     0,   127,   126,   103,   242,
      77,     0,   243,   250,   248,   254,   355,   353,   283,   291,
     289,     0,     0,   483,   484,   482,     0,    87,     0,   446,
     450,     0,     0,     0,     0,     0,     0,     0,     0,   455,
     457,   467,   479,   577,   575,   559,     0,     0,     0,   330,
       0,     0,     0,   556,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   325,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   211,    71,
       0,   303,    35,   304,    36,    32,    33,     0,   305,   300,
     301,   302,   299,    49,    50,    46,    47,     0,    29,     0,
      43,     0,   420,   341,   350,   352,   228,   225,     0,   421,
     430,     0,   131,   132,   135,   137,   134,   138,   139,   141,
     319,   317,   318,     0,   129,   128,     0,   245,   309,   247,
     255,   252,   344,     0,     0,   287,   294,   296,   298,   494,
      85,    88,     0,   449,     0,   453,   458,   459,   460,   461,
     462,   463,     0,   464,     0,     0,   472,   478,   468,   469,
       0,     0,   481,   560,   500,   501,   548,   327,     0,     0,
       0,     0,   495,   496,     0,   498,   499,     0,   540,   541,
     542,   543,     0,   565,   566,     0,   573,   544,   530,     0,
       0,   519,   534,   526,   525,   507,   533,     0,   524,   506,
     523,     0,   532,   522,   513,     0,   505,   521,   512,   504,
     511,     0,   510,   531,   520,     0,   322,    55,    58,    57,
      34,    39,    48,    53,     0,    28,    37,    30,     0,    42,
      51,    44,   336,   348,   229,   233,    86,   133,   140,     0,
       0,     0,   122,   130,   154,   156,    78,   268,   272,   280,
     266,   306,     0,     0,     0,   251,   227,   264,   257,   259,
     260,   262,   263,   258,   256,   310,   261,   253,   368,   356,
       0,   398,     0,     0,   354,   357,   359,   360,   369,   371,
     374,   383,   378,   381,   396,   370,   397,   282,   284,   285,
     292,   447,   451,   465,   474,   475,   473,   476,   470,   471,
       0,     0,     0,     0,     0,   557,     0,     0,   551,   562,
       0,   574,     0,     0,     0,     0,   551,     0,     0,   563,
     327,    63,    40,    27,     0,    54,    41,     0,   338,   342,
     427,   351,     0,     0,   147,   148,   142,   143,     0,   145,
     146,   150,   151,   158,   159,   152,   155,   153,   157,   120,
     269,   273,   277,     0,   307,   316,     0,   265,   247,     0,
       0,   406,   414,     0,   399,   401,   408,   410,   413,   384,
     427,   372,   376,   392,     0,   394,   393,   380,   382,   385,
       0,   561,   331,     0,   328,     0,   537,   538,   497,   539,
     552,     0,     0,   564,   517,   518,   514,     0,   515,   516,
       0,     0,    38,    52,   339,   340,   427,   349,   234,   136,
     144,   149,   123,     0,   274,   267,     0,     0,   249,   314,
     400,   407,     0,   403,   412,   415,   411,   366,     0,   375,
       0,   379,     0,   416,   395,     0,   295,   293,   326,     0,
     550,     0,   553,   323,    59,    64,    60,     0,   337,   225,
     162,   270,   187,   308,     0,   311,   409,   405,   358,   373,
     377,     0,   389,     0,   390,   536,   572,    61,    62,     0,
       0,     0,     0,    79,     0,     0,     0,   312,   315,     0,
     404,   363,   367,   391,   386,   388,     0,    67,    66,    65,
     235,   271,     0,   276,     0,   402,   361,   364,   365,   387,
     275,   313,   427,   362
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -843,  -843,  -843,  -843,  -843,  -843,   491,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,    55,  -843,   194,  -843,
    -169,  -843,  -843,    76,  -843,  -843,    62,  -843,   195,  -843,
    -166,  -843,  -843,    70,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,    56,
    -843,  -843,  -843,  -843,    39,  -843,  -843,  -843,   -73,  -843,
     358,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -145,   -99,  -843,  -198,  -843,
    -843,  -843,  -843,  -843,  -843,    57,  -843,  -843,    51,  -843,
    -843,  -165,  -843,  -843,  -843,  -843,  -843,  -843,   -75,   -72,
    -277,  -843,  -843,   513,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,   -11,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,   562,
    -843,  -843,    60,  -843,     4,   590,    31,   621,   574,  -843,
    -293,   -78,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -291,  -843,  -843,  -843,  -843,  -580,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,   -68,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -411,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -657,  -112,   302,  -843,  -304,  -705,  -138,  -218,  -843,
    -843,  -843,  -843,  -171,  -843,  -843,  -843,  -843,  -843,    54,
    -143,  -797,  -843,  -843,  -142,  -843,  -843,  -843,  -843,  -843,
    -294,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,   -81,
    -843,  -843,  -843,  -238,  -843,  -843,   -82,  -843,  -237,  -843,
    -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -793,  -843,  -843,  -842,   -90,  -843,  -843,  -843,
    -843,  -843,  -843,  -280,   -89,   -15,     7,  -843,   663,  -843,
    -843,  -843,    52,  -843,  -843,    48,  -843,  -843,  -843,   -84,
    -843,  -843,    42,  -843,  -843,  -843,  -382,  -843,  -385,    25,
    -435,   -93,  -843,  -843,  -121,  -843,  -843,  -843,  -843,  -843,
    -843,  -843,  -843,  -843,  -108,  -843,  -843,  -843,  -843,  -843,
    -843,   -96,  -843,  -843,  -843,   -79,  -843,   175,   176,    73,
    -242,   -12,  -843,  -843
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,    26,     5,     6,     7,    46,    90,
     141,   302,   142,   143,   428,   429,   569,   430,   431,   554,
     555,   697,   794,   556,   793,   432,   571,   433,   434,   564,
     565,   701,   797,   566,   796,   435,   550,   689,   791,   938,
     915,   871,   916,     8,    91,   139,   422,    27,    28,    57,
     459,   460,   596,   819,    82,   128,   129,   477,   478,   276,
     277,   278,   279,    29,    58,   108,    30,    63,    64,   199,
      31,   107,   192,   193,   194,   195,   112,   113,   318,   319,
     456,   594,   712,   320,   582,   583,   457,   587,   588,   595,
     806,   807,   808,   809,   810,   713,   815,   817,   714,   715,
      78,    79,    80,     9,    83,   296,   132,   133,    32,    33,
      93,    94,    34,    53,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,   137,    86,   136,    87,    88,
     299,   420,   116,   117,    99,   100,    59,    74,   103,   104,
     171,   577,   441,   304,   442,   443,   802,   919,   172,   306,
     307,   203,   461,   204,   323,   462,   463,   725,   598,   464,
     600,   601,   726,   727,   728,   823,   729,   820,   883,   944,
     730,   821,   884,   922,   731,   732,   121,   122,   123,   327,
     604,   758,   124,   125,   328,   213,   850,   608,   760,   471,
     557,   733,   824,   886,   734,   735,   829,   948,   964,   925,
     736,   589,   590,   416,   790,   516,   854,   771,   361,   637,
     173,   310,   308,   445,   874,   875,   799,   702,   446,   447,
     439,   573,   801,   703,   574,   465,   603,   602,   744,   840,
     745,   967,   972,   968,   952,   928,   739,   746,   747,   748,
     749,   899,   841,   750,   901,   842,   751,   847,   752,   848,
     955,   934,   904,   849,   753,   754,   834,   950,   927,   891,
     892,   835,   836,   895,   837,   905,   448,   175,   303,   176,
     177,   178,   449,   575,   451,   440,   334,   181,   335,   336,
     613,   479,   337,   615,   480,   338,   339,   489,   490,   340,
     341,   626,   632,   767,   627,   491,   342,   492,   343,   344,
     345,   346,   358,   283,   861,   284,   285,   365,   503,   641,
     286,   495,   633,   770,   347,   655,   288,   781,   782,   348,
     494,   349,   313,   314,   315,   350,   184,   185,   186,   351,
     188,   352,    51,   190
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int SPARQLfedParser::yytable_ninf_ = -428;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        50,   322,    65,    54,    55,    67,   418,    69,   182,    70,
      71,   200,   444,    75,   174,   179,   567,   280,   377,   737,
     591,   287,  -286,   605,    66,   183,   606,    60,   105,   450,
     211,   293,   356,   289,   359,   414,   282,   201,   893,   191,
     699,   469,  -120,   897,   902,   111,   316,    95,   109,   419,
     290,    67,   811,    72,   297,   696,   114,   311,   101,   105,
     931,   954,   630,  -166,    96,   825,   695,   939,   105,   687,
      66,   932,   688,   860,    68,   517,   106,     1,     1,   918,
     740,   860,   933,   145,    10,   111,   126,   127,   717,   718,
     741,   956,   189,   196,   852,   417,   144,   -21,   740,   321,
     913,   853,   792,    11,   742,   206,   631,   853,   741,   546,
     547,   180,   719,    56,   831,   134,   135,   292,   740,  -246,
     110,   298,   742,   458,   832,   696,   720,   721,   741,   722,
     210,   118,   438,   894,   423,   120,   281,   197,   130,   452,
     743,    52,   742,    84,    85,    97,    98,    61,    62,   811,
     700,   832,   591,   567,   115,   312,   965,   436,   743,   940,
     941,   903,   202,   -21,   198,    81,   280,  -120,  -286,   580,
     287,    73,   607,   437,   833,   973,   212,   187,   357,   196,
     360,   415,   289,    61,    62,   282,    47,    48,    49,   903,
      77,    61,    62,   759,    47,    48,    49,   710,   711,   290,
     424,   833,   291,    89,    47,    48,    49,   723,    92,   182,
     -21,    95,   -21,   182,   -21,   174,   179,   131,    47,    48,
      49,    85,   140,    61,    62,   205,   183,   182,   724,   146,
     183,   795,   700,   466,   467,   207,    47,    48,    49,   -21,
     -21,   -21,   764,   765,   183,   768,   769,   425,   888,   426,
     208,   427,    47,    48,    49,   209,    47,    48,    49,   300,
     309,    47,    48,    49,   301,   324,   292,   325,   305,   326,
     623,   317,   843,   329,   591,   353,    47,    48,    49,    47,
      48,    49,   624,   625,   704,   281,   421,   591,   354,   844,
     196,    67,   355,   189,   362,   363,    67,   189,    67,   453,
     364,    47,    48,    49,   366,   367,    61,    62,   368,   369,
      66,   189,   180,   370,   845,    66,   180,    66,   164,   165,
     166,   167,   481,   482,   483,   484,   485,   486,   559,   371,
     180,   559,   487,   488,   372,   470,    47,    48,    49,   373,
     374,   375,   584,   182,   376,   560,   378,   379,   560,   380,
     775,   291,   381,   182,   846,   383,   473,   474,   475,   382,
     183,   586,   592,    47,    48,    49,   384,   385,    61,    62,
     183,   591,   386,   881,   388,   387,   389,   508,   187,   390,
     391,   392,   187,   393,   394,   395,   567,   396,   397,   158,
     159,   160,   161,   162,   163,   398,   187,   616,   617,   618,
     619,   620,   621,   399,   763,   400,   401,   548,   402,   403,
     404,    12,   562,    13,    14,   562,    15,   405,   406,   -72,
     407,   408,   409,    16,    17,   410,   411,   189,   413,  -232,
     454,   558,   468,   827,   558,   476,   515,   189,   424,   907,
     455,    18,   292,   292,   549,   427,   180,   572,   578,   576,
     593,   597,    12,   599,    13,    14,   180,    15,   559,   609,
     917,   585,   611,   614,   612,   622,   634,   693,   559,   635,
     584,   636,   638,   691,   642,   560,   643,   639,   645,   851,
     640,   182,   644,   610,   646,   560,   647,   174,   179,   586,
     648,   649,   650,   651,   592,   652,   657,   561,   183,   658,
     561,   659,   660,   182,   661,   662,    19,   663,   559,   466,
     467,   664,   187,   665,   666,   667,   668,    20,    21,   669,
     183,    22,   187,    23,   670,   560,   672,   671,   957,   958,
     959,    24,   885,    25,   673,   674,   675,   676,   889,   677,
     678,   679,   562,   680,   682,   681,   683,    19,   684,   709,
     779,   789,   562,   780,   813,   798,   800,   814,    20,    21,
     711,   558,    22,   705,    23,   189,    67,   710,   826,   855,
     292,   558,    24,   856,    25,   292,   857,   858,   859,   863,
     878,   853,   864,   865,   180,    66,   862,   189,   866,   585,
      67,   756,   562,   868,   869,   923,   879,   330,   111,   890,
     947,   910,   912,   898,   911,   924,   180,   926,   900,    66,
     755,   558,   935,   903,   949,   937,   592,   951,   953,   960,
     963,   969,   294,   694,   568,   872,   942,   561,   570,   592,
     690,   873,   698,   803,   692,   716,   412,   561,   708,   707,
     818,   880,   816,   943,   295,   102,    76,   119,   828,   138,
     187,   822,   870,   961,   493,   876,   738,   966,   877,   830,
     929,   839,   762,   930,   761,   867,   628,   629,   766,   936,
       0,   970,   187,   971,     0,     0,     0,   561,     0,     0,
       0,     0,     0,     0,   920,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   292,   559,     0,
       0,   559,     0,     0,   182,     0,     0,     0,     0,     0,
     292,     0,     0,   592,     0,   560,   812,     0,   560,     0,
     882,   183,     0,     0,     0,     0,     0,     0,   756,     0,
     838,   756,   182,     0,     0,     0,     0,     0,   466,   467,
       0,     0,     0,     0,   182,     0,     0,     0,     0,   183,
       0,     0,     0,     0,   559,     0,     0,     0,     0,     0,
       0,   183,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   560,     0,     0,     0,   559,     0,     0,     0,     0,
     182,     0,   562,     0,     0,   562,    67,     0,   189,     0,
       0,     0,   560,     0,   292,     0,     0,   183,     0,     0,
       0,   558,     0,     0,   558,    66,     0,   180,     0,     0,
       0,     0,     0,   812,     0,     0,   189,     0,     0,   838,
       0,   896,     0,   182,     0,     0,     0,     0,   189,   174,
     179,     0,     0,     0,     0,   180,     0,     0,   562,     0,
     183,     0,     0,   559,   559,   559,     0,   180,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   558,     0,   562,
     560,   560,   560,     0,   189,     0,     0,   561,   921,     0,
     561,    67,     0,   187,     0,     0,   182,     0,   558,     0,
       0,     0,     0,   180,     0,     0,   756,     0,   756,     0,
      66,     0,     0,   183,     0,     0,     0,     0,     0,     0,
       0,   187,     0,     0,     0,     0,     0,   189,     0,     0,
       0,   945,     0,   187,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   561,     0,     0,   180,   562,   562,   562,
     962,   946,     0,    67,     0,     0,     0,   838,   -76,   756,
       0,     0,     0,     0,   561,     0,   558,   558,   558,   187,
       0,     0,    66,   147,   148,   149,   150,   151,   755,     0,
     189,     0,  -427,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   152,     0,     0,     0,     0,     0,   180,
     147,   148,   149,   150,   151,     0,     0,     0,     0,  -427,
       0,     0,   187,   472,     0,     0,     0,     0,     0,     0,
     152,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   561,   561,   561,     0,     0,   496,   497,   498,
       0,     0,   499,     0,     0,   500,   501,   502,     0,   504,
     505,   506,   507,     0,   509,   510,   511,   512,   513,   514,
       0,     0,     0,   518,     0,   187,   519,   520,   521,   522,
       0,   523,     0,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      47,    48,    49,   168,   169,    61,    62,     0,   170,     0,
       0,     0,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    47,    48,    49,
     168,   169,    61,    62,     0,   170,     0,   147,   148,   149,
     150,   151,   804,   805,     0,     0,     0,   579,     0,     0,
       0,     0,     0,     0,     0,     0,   330,   152,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   654,
     656,   216,     0,   217,   218,   219,   220,   221,   222,   223,
     224,     0,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,     0,   236,     0,     0,     0,     0,   685,
     686,     0,     0,     0,     0,   244,     0,     0,     0,     0,
       0,     0,     0,   245,   246,   247,     0,   248,   249,   250,
       0,     0,   251,   252,     0,   253,     0,   254,   255,   256,
     257,     0,   258,   259,   706,   260,     0,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,     0,     0,     0,     0,     0,     0,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    47,    48,    49,   168,   169,    61,
      62,     0,   170,     0,    47,    48,    49,   653,     0,    61,
      62,   772,   773,   774,     0,     0,     0,   776,     0,     0,
     777,     0,     0,     0,     0,   778,     0,     0,   330,     0,
       0,     0,   783,   784,     0,     0,     0,     0,     0,     0,
     785,     0,     0,     0,   786,     0,     0,     0,   787,   331,
     332,     0,   333,   216,   788,   217,   218,   219,   220,   221,
     222,   223,   224,     0,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,     0,   236,     0,     0,     0,
     237,   238,   239,   240,   241,   242,   243,   244,     0,     0,
       0,     0,     0,     0,     0,   245,   246,   247,     0,   248,
     249,   250,     0,     0,   251,   252,     0,   253,     0,   254,
     255,   256,   257,     0,   258,   259,     0,   260,     0,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    47,    48,    49,     0,
       0,    61,    62,     0,     0,     0,     0,     0,     0,     0,
       0,   214,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   887,
       0,     0,   215,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   147,   148,   149,
     150,   151,     0,     0,     0,     0,   908,   216,   909,   217,
     218,   219,   220,   221,   222,   223,   224,   152,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,     0,
     236,     0,     0,     0,   237,   238,   239,   240,   241,   242,
     243,   244,   757,     0,     0,     0,     0,   551,     0,   245,
     246,   247,     0,   248,   249,   250,     0,     0,   251,   252,
       0,   253,     0,   254,   255,   256,   257,     0,   258,   259,
       0,   260,     0,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      47,    48,    49,     0,     0,    61,    62,     0,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    47,    48,    49,   168,   169,    61,
      62,     0,   170,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   553,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    47,    48,    49,   330,     0,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   331,   332,     0,
     333,   216,     0,   217,   218,   219,   220,   221,   222,   223,
     224,     0,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,     0,   236,     0,     0,     0,   237,   238,
     239,   240,   241,   242,   243,   244,     0,     0,     0,     0,
       0,     0,     0,   245,   246,   247,     0,   248,   249,   250,
       0,     0,   251,   252,     0,   253,     0,   254,   255,   256,
     257,     0,   258,   259,     0,   260,     0,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   215,     0,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    47,    48,    49,     0,     0,    61,
      62,   216,     0,   217,   218,   219,   220,   221,   222,   223,
     224,     0,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,     0,   236,     0,     0,     0,   237,   238,
     239,   240,   241,   242,   243,   244,     0,     0,     0,     0,
       0,     0,     0,   245,   246,   247,     0,   248,   249,   250,
       0,     0,   251,   252,     0,   253,     0,   254,   255,   256,
     257,     0,   258,   259,     0,   260,     0,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   330,     0,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    47,    48,    49,     0,     0,    61,
      62,   216,     0,   217,   218,   219,   220,   221,   222,   223,
     224,     0,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,     0,   236,     0,     0,     0,   237,   238,
     239,   240,   241,   242,   243,   244,     0,     0,     0,     0,
       0,     0,     0,   245,   246,   247,     0,   248,   249,   250,
       0,     0,   251,   252,     0,   253,     0,   254,   255,   256,
     257,     0,   258,   259,     0,   260,     0,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   906,   551,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   581,     0,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    47,    48,    49,     0,     0,    61,
      62,   216,   551,   217,   218,   219,   220,   221,   222,   223,
     224,     0,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,     0,   236,   914,   551,     0,     0,     0,
       0,     0,     0,     0,     0,   244,     0,     0,     0,     0,
       0,     0,     0,   245,   246,   247,     0,   248,   249,   250,
     551,     0,   251,   252,     0,   253,     0,   254,   255,   256,
     257,     0,   258,   259,     0,   260,     0,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   551,   553,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    47,
      48,    49,     0,     0,    61,    62,     0,     0,     0,     0,
     552,     0,     0,   563,    47,    48,    49,     0,     0,    61,
      62,     0,   553,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    47,    48,
      49,     0,     0,    61,    62,     0,   553,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    47,    48,    49,     0,     0,    61,    62,     0,
     553,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    47,    48,    49,     0,
       0,    61,    62,     0,     0,     0,     0,     0,     0,     0,
     330,     0,   553,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    47,    48,
      49,     0,     0,    61,    62,   216,     0,   217,   218,   219,
     220,   221,   222,   223,   224,     0,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,     0,   236,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   244,
       0,     0,     0,     0,     0,     0,     0,   245,   246,   247,
       0,   248,   249,   250,     0,     0,   251,   252,     0,   253,
       0,   254,   255,   256,   257,     0,   258,   259,     0,   260,
       0,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,    48,
      49
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        12,   199,    17,    14,    15,    17,   297,    19,   104,    20,
      21,   110,   305,    24,   104,   104,   427,   129,   236,   599,
     455,   129,    40,    37,    17,   104,    40,    19,    22,   309,
      40,   130,    40,   129,    40,    40,   129,    36,   831,    23,
      43,    41,    36,   840,    48,    39,   191,     6,    63,    23,
     129,    63,   709,    22,    39,   102,     6,    87,    54,    22,
     902,    37,    19,     0,    23,   722,    43,    55,    22,    37,
      63,    37,    40,   778,    18,   379,    39,    14,    14,   876,
      40,   786,    48,    95,   178,    39,    17,    18,     6,     7,
      50,   933,   104,   105,    41,   293,    92,    36,    40,   198,
      41,    48,   149,     0,    64,   117,    63,    48,    50,   413,
     414,   104,    30,    36,    40,    84,    85,   129,    40,    37,
      64,   106,    64,   321,    50,   102,    44,    45,    50,    47,
     123,    71,   303,    50,    36,    75,   129,   106,    82,   310,
     100,    12,    64,     3,     4,   104,   105,   183,   184,   806,
     153,    50,   587,   564,   104,   185,   949,   302,   100,   147,
     148,   165,   161,   102,   108,    16,   278,   161,   186,   449,
     278,    36,   186,    50,   100,   972,   186,   104,   186,   191,
     186,   186,   278,   183,   184,   278,   178,   179,   180,   165,
      30,   183,   184,   604,   178,   179,   180,    28,    29,   278,
     102,   100,   129,    15,   178,   179,   180,   125,     9,   305,
     149,     6,   151,   309,   153,   305,   305,    49,   178,   179,
     180,     4,   161,   183,   184,   110,   305,   323,   146,    37,
     309,   152,   153,   323,   323,   110,   178,   179,   180,   178,
     179,   180,   624,   625,   323,   630,   631,   149,   828,   151,
      37,   153,   178,   179,   180,   110,   178,   179,   180,   179,
      40,   178,   179,   180,    55,   205,   278,   207,    43,   209,
     488,    90,    19,    36,   709,    74,   178,   179,   180,   178,
     179,   180,    61,    62,   577,   278,   298,   722,    40,    36,
     302,   303,    40,   305,    40,    40,   308,   309,   310,   311,
      40,   178,   179,   180,    40,    40,   183,   184,    40,    40,
     303,   323,   305,    40,    61,   308,   309,   310,   174,   175,
     176,   177,    55,    56,    57,    58,    59,    60,   424,    40,
     323,   427,    65,    66,    40,   328,   178,   179,   180,    40,
      40,    40,   454,   439,    40,   424,    40,    40,   427,    40,
     641,   278,   186,   449,   101,    40,   331,   332,   333,   186,
     439,   454,   455,   178,   179,   180,    40,    40,   183,   184,
     449,   806,    40,   808,    40,   186,   186,   370,   305,    40,
      40,    40,   309,    40,    40,    40,   797,    40,    40,   168,
     169,   170,   171,   172,   173,    40,   323,   481,   482,   483,
     484,   485,   486,    40,   622,    40,    40,   419,    40,    40,
      40,     8,   424,    10,    11,   427,    13,    40,    40,    16,
      40,    40,    40,    20,    21,    40,    40,   439,    40,     6,
      25,   424,    36,   724,   427,    89,    17,   449,   102,   850,
      91,    38,   454,   455,   178,   153,   439,    52,     6,    43,
      24,    37,     8,    43,    10,    11,   449,    13,   554,    41,
     871,   454,    41,    54,    53,    66,    41,   153,   564,    41,
     582,    41,    48,   102,    41,   554,    41,    48,    41,   770,
      48,   577,    48,   476,    41,   564,    48,   577,   577,   582,
      41,    41,    41,    41,   587,    48,    41,   424,   577,    41,
     427,    48,    48,   599,    41,    41,   103,    41,   604,   599,
     599,    41,   439,    41,    41,    48,    41,   114,   115,    41,
     599,   118,   449,   120,    41,   604,    41,    48,   939,   940,
     941,   128,   823,   130,    41,    41,    48,    41,   829,    41,
      41,    41,   554,    41,    41,    48,    41,   103,    41,    25,
      41,    41,   564,    49,   165,    49,    48,   165,   114,   115,
      29,   554,   118,   578,   120,   577,   578,    28,    40,    48,
     582,   564,   128,    41,   130,   587,    41,    41,    41,    41,
      36,    48,    41,    41,   577,   578,    75,   599,    41,   582,
     602,   603,   604,    41,    41,   886,    41,    40,    39,    41,
      46,    41,    41,   102,    55,    89,   599,    41,    63,   602,
     603,   604,    41,   165,   102,    48,   709,    49,    37,    37,
      41,    37,   131,   568,   430,   794,   919,   554,   433,   722,
     554,   797,   570,   706,   564,   596,   278,   564,   587,   582,
     715,   806,   714,   920,   131,    55,    25,    73,   726,    87,
     577,   719,   790,   944,   352,   798,   602,   951,   800,   740,
     898,   743,   614,   900,   612,   786,   491,   491,   626,   911,
      -1,   962,   599,   964,    -1,    -1,    -1,   604,    -1,    -1,
      -1,    -1,    -1,    -1,   882,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   709,   794,    -1,
      -1,   797,    -1,    -1,   800,    -1,    -1,    -1,    -1,    -1,
     722,    -1,    -1,   806,    -1,   794,   709,    -1,   797,    -1,
     819,   800,    -1,    -1,    -1,    -1,    -1,    -1,   740,    -1,
     742,   743,   828,    -1,    -1,    -1,    -1,    -1,   828,   828,
      -1,    -1,    -1,    -1,   840,    -1,    -1,    -1,    -1,   828,
      -1,    -1,    -1,    -1,   850,    -1,    -1,    -1,    -1,    -1,
      -1,   840,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   850,    -1,    -1,    -1,   871,    -1,    -1,    -1,    -1,
     876,    -1,   794,    -1,    -1,   797,   798,    -1,   800,    -1,
      -1,    -1,   871,    -1,   806,    -1,    -1,   876,    -1,    -1,
      -1,   794,    -1,    -1,   797,   798,    -1,   800,    -1,    -1,
      -1,    -1,    -1,   806,    -1,    -1,   828,    -1,    -1,   831,
      -1,   833,    -1,   919,    -1,    -1,    -1,    -1,   840,   919,
     919,    -1,    -1,    -1,    -1,   828,    -1,    -1,   850,    -1,
     919,    -1,    -1,   939,   940,   941,    -1,   840,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   850,    -1,   871,
     939,   940,   941,    -1,   876,    -1,    -1,   794,   883,    -1,
     797,   883,    -1,   800,    -1,    -1,   972,    -1,   871,    -1,
      -1,    -1,    -1,   876,    -1,    -1,   898,    -1,   900,    -1,
     883,    -1,    -1,   972,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   828,    -1,    -1,    -1,    -1,    -1,   919,    -1,    -1,
      -1,   922,    -1,   840,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   850,    -1,    -1,   919,   939,   940,   941,
     945,   924,    -1,   945,    -1,    -1,    -1,   949,    16,   951,
      -1,    -1,    -1,    -1,   871,    -1,   939,   940,   941,   876,
      -1,    -1,   945,    31,    32,    33,    34,    35,   951,    -1,
     972,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,   972,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    40,
      -1,    -1,   919,   330,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   939,   940,   941,    -1,    -1,   354,   355,   356,
      -1,    -1,   359,    -1,    -1,   362,   363,   364,    -1,   366,
     367,   368,   369,    -1,   371,   372,   373,   374,   375,   376,
      -1,    -1,    -1,   380,    -1,   972,   383,   384,   385,   386,
      -1,   388,    -1,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,    -1,   186,    -1,
      -1,    -1,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,    -1,   186,    -1,    31,    32,    33,
      34,    35,    26,    27,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   516,
     517,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    -1,    -1,    -1,    -1,   546,
     547,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,   108,   109,    -1,   111,   112,   113,
      -1,    -1,   116,   117,    -1,   119,    -1,   121,   122,   123,
     124,    -1,   126,   127,   581,   129,    -1,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,    -1,   186,    -1,   178,   179,   180,    19,    -1,   183,
     184,   638,   639,   640,    -1,    -1,    -1,   644,    -1,    -1,
     647,    -1,    -1,    -1,    -1,   652,    -1,    -1,    40,    -1,
      -1,    -1,   659,   660,    -1,    -1,    -1,    -1,    -1,    -1,
     667,    -1,    -1,    -1,   671,    -1,    -1,    -1,   675,    61,
      62,    -1,    64,    65,   681,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,   111,
     112,   113,    -1,    -1,   116,   117,    -1,   119,    -1,   121,
     122,   123,   124,    -1,   126,   127,    -1,   129,    -1,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,    -1,
      -1,   183,   184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   826,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,   853,    65,   855,    67,
      68,    69,    70,    71,    72,    73,    74,    51,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    37,    -1,    -1,    -1,    -1,    42,    -1,   107,
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
     184,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    40,    -1,   183,   184,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,
      64,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,   108,   109,    -1,   111,   112,   113,
      -1,    -1,   116,   117,    -1,   119,    -1,   121,   122,   123,
     124,    -1,   126,   127,    -1,   129,    -1,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    -1,    -1,   183,
     184,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,   108,   109,    -1,   111,   112,   113,
      -1,    -1,   116,   117,    -1,   119,    -1,   121,   122,   123,
     124,    -1,   126,   127,    -1,   129,    -1,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    -1,    -1,   183,
     184,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,   108,   109,    -1,   111,   112,   113,
      -1,    -1,   116,   117,    -1,   119,    -1,   121,   122,   123,
     124,    -1,   126,   127,    -1,   129,    -1,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    -1,    -1,   183,
     184,    65,    42,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,   108,   109,    -1,   111,   112,   113,
      42,    -1,   116,   117,    -1,   119,    -1,   121,   122,   123,
     124,    -1,   126,   127,    -1,   129,    -1,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,    42,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,   183,   184,    -1,    -1,    -1,    -1,
     102,    -1,    -1,   153,   178,   179,   180,    -1,    -1,   183,
     184,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,    -1,    -1,   183,   184,    -1,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,    -1,    -1,   183,   184,    -1,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,    -1,
      -1,   183,   184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,    -1,    -1,   183,   184,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    -1,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,
      -1,   111,   112,   113,    -1,    -1,   116,   117,    -1,   119,
      -1,   121,   122,   123,   124,    -1,   126,   127,    -1,   129,
      -1,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,   179,
     180
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    14,   188,   189,   190,   192,   193,   194,   230,   290,
     178,     0,     8,    10,    11,    13,    20,    21,    38,   103,
     114,   115,   118,   120,   128,   130,   191,   234,   235,   250,
     253,   257,   295,   296,   299,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   195,   178,   179,   180,
     518,   519,    12,   300,   300,   300,    36,   236,   251,   323,
      19,   183,   184,   254,   255,   462,   463,   518,   236,   518,
     300,   300,   323,    36,   324,   300,   324,    30,   287,   288,
     289,    16,   241,   291,     3,     4,   313,   315,   316,    15,
     196,   231,     9,   297,   298,     6,    23,   104,   105,   321,
     322,   321,   322,   325,   326,    22,    39,   258,   252,   462,
     236,    39,   263,   264,     6,   104,   319,   320,   319,   325,
     319,   363,   364,   365,   369,   370,    17,    18,   242,   243,
     236,    49,   293,   294,   323,   323,   314,   312,   316,   232,
     161,   197,   199,   200,   321,   518,    37,    31,    32,    33,
      34,    35,    51,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   181,   182,
     186,   327,   335,   397,   453,   454,   456,   457,   458,   461,
     463,   464,   508,   512,   513,   514,   515,   516,   517,   518,
     520,    23,   259,   260,   261,   262,   518,   323,   236,   256,
     263,    36,   161,   338,   340,   110,   518,   110,    37,   110,
     463,    40,   186,   372,    19,    40,    65,    67,    68,    69,
      70,    71,    72,    73,    74,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    88,    92,    93,    94,
      95,    96,    97,    98,    99,   107,   108,   109,   111,   112,
     113,   116,   117,   119,   121,   122,   123,   124,   126,   127,
     129,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   246,   247,   248,   249,
     389,   463,   488,   490,   492,   493,   497,   501,   503,   508,
     512,   516,   518,   263,   193,   290,   292,    39,   106,   317,
     179,    55,   198,   455,   330,    43,   336,   337,   399,    40,
     398,    87,   185,   509,   510,   511,   262,    90,   265,   266,
     270,   263,   265,   341,   319,   319,   319,   366,   371,    36,
      40,    61,    62,    64,   463,   465,   466,   469,   472,   473,
     476,   477,   483,   485,   486,   487,   488,   501,   506,   508,
     512,   516,   518,    74,    40,    40,    40,   186,   489,    40,
     186,   395,    40,    40,    40,   494,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,   395,    40,    40,
      40,   186,   186,    40,    40,    40,    40,   186,    40,   186,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,   247,    40,    40,   186,   390,   265,   338,    23,
     318,   518,   233,    36,   102,   149,   151,   153,   201,   202,
     204,   205,   212,   214,   215,   222,   262,    50,   400,   407,
     462,   329,   331,   332,   327,   400,   405,   406,   453,   459,
     460,   461,   400,   518,    25,    91,   267,   273,   265,   237,
     238,   339,   342,   343,   346,   412,   453,   461,    36,    41,
     463,   376,   465,   486,   486,   486,    89,   244,   245,   468,
     471,    55,    56,    57,    58,    59,    60,    65,    66,   474,
     475,   482,   484,   390,   507,   498,   465,   465,   465,   465,
     465,   465,   465,   495,   465,   465,   465,   465,   463,   465,
     465,   465,   465,   465,   465,    17,   392,   392,   465,   465,
     465,   465,   465,   465,   465,   465,   465,   465,   465,   465,
     465,   465,   465,   465,   465,   465,   465,   465,   465,   465,
     465,   465,   465,   465,   465,   465,   392,   392,   518,   178,
     223,    42,   102,   162,   206,   207,   210,   377,   463,   508,
     512,   516,   518,   153,   216,   217,   220,   377,   205,   203,
     215,   213,    52,   408,   411,   460,    43,   328,     6,    41,
     460,    40,   271,   272,   389,   463,   488,   274,   275,   388,
     389,   487,   488,    24,   268,   276,   239,    37,   345,    43,
     347,   348,   414,   413,   367,    37,    40,   186,   374,    41,
     463,    41,    53,   467,    54,   470,   476,   476,   476,   476,
     476,   476,    66,   395,    61,    62,   478,   481,   514,   515,
      19,    63,   479,   499,    41,    41,    41,   396,    48,    48,
      48,   496,    41,    41,    48,    41,    41,    48,    41,    41,
      41,    41,    48,    19,   465,   502,   465,    41,    41,    48,
      48,    41,    41,    41,    41,    41,    41,    48,    41,    41,
      41,    48,    41,    41,    41,    48,    41,    41,    41,    41,
      41,    48,    41,    41,    41,   465,   465,    37,    40,   224,
     210,   102,   220,   153,   203,    43,   102,   208,   213,    43,
     153,   218,   404,   410,   327,   462,   465,   272,   275,    25,
      28,    29,   269,   282,   285,   286,   241,     6,     7,    30,
      44,    45,    47,   125,   146,   344,   349,   350,   351,   353,
     357,   361,   362,   378,   381,   382,   387,   343,   406,   423,
      40,    50,    64,   100,   415,   417,   424,   425,   426,   427,
     430,   433,   435,   441,   442,   463,   518,    37,   368,   377,
     375,   469,   472,   395,   483,   483,   479,   480,   485,   485,
     500,   394,   465,   465,   465,   338,   465,   465,   465,    41,
      49,   504,   505,   465,   465,   465,   465,   465,   465,    41,
     391,   225,   149,   211,   209,   152,   221,   219,    49,   403,
      48,   409,   333,   245,    26,    27,   277,   278,   279,   280,
     281,   388,   463,   165,   165,   283,   286,   284,   285,   240,
     354,   358,   363,   352,   379,   388,    40,   338,   328,   383,
     426,    40,    50,   100,   443,   448,   449,   451,   518,   433,
     416,   429,   432,    19,    36,    61,   101,   434,   436,   440,
     373,   338,    41,    48,   393,    48,    41,    41,    41,    41,
     393,   491,    75,    41,    41,    41,    41,   491,    41,    41,
     394,   228,   207,   217,   401,   402,   407,   411,    36,    41,
     278,   487,   263,   355,   359,   338,   380,   465,   343,   338,
      41,   446,   447,   449,    50,   450,   518,   408,   102,   428,
      63,   431,    48,   165,   439,   452,    41,   377,   465,   465,
      41,    55,    41,    41,    41,   227,   229,   377,   408,   334,
     265,   462,   360,   338,    89,   386,    41,   445,   422,   430,
     435,   452,    37,    48,   438,    41,   517,    48,   226,    55,
     147,   148,   327,   287,   356,   300,   463,    46,   384,   102,
     444,    49,   421,    37,    37,   437,   452,   377,   377,   377,
      37,   338,   462,    41,   385,   449,   417,   418,   420,    37,
     338,   338,   419,   408
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
     192,   193,   194,   194,   195,   195,   196,   196,   198,   197,
     199,   200,   200,   201,   201,   201,   201,   202,   202,   203,
     203,   204,   205,   206,   206,   207,   207,   209,   208,   210,
     211,   212,   212,   213,   213,   214,   215,   216,   216,   217,
     217,   219,   218,   220,   221,   222,   223,   223,   225,   224,
     226,   226,   227,   228,   228,   229,   229,   229,   230,   232,
     233,   231,   235,   234,   236,   236,   238,   239,   240,   237,
     241,   242,   242,   243,   243,   244,   245,   245,   246,   247,
     247,   247,   247,   247,   247,   247,   247,   248,   248,   249,
     249,   250,   252,   251,   251,   253,   254,   254,   255,   255,
     256,   256,   257,   258,   259,   259,   260,   261,   262,   263,
     264,   264,   265,   266,   266,   267,   267,   268,   268,   269,
     269,   270,   271,   271,   272,   272,   272,   272,   273,   274,
     274,   275,   276,   277,   277,   278,   278,   279,   279,   280,
     281,   281,   282,   282,   283,   283,   284,   284,   285,   286,
     287,   288,   289,   289,   291,   290,   292,   292,   293,   294,
     294,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   296,   297,   298,   298,   299,   300,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     311,   312,   312,   313,   313,   314,   314,   315,   316,   317,
     318,   318,   319,   319,   320,   320,   321,   322,   322,   322,
     322,   323,   324,   326,   325,   327,   327,   328,   328,   329,
     330,   330,   332,   333,   334,   331,   335,   336,   337,   337,
     338,   338,   339,   339,   341,   340,   342,   343,   343,   344,
     345,   345,   346,   347,   348,   348,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   350,   352,   351,   354,   355,
     356,   353,   358,   359,   360,   357,   361,   362,   363,   363,
     365,   366,   364,   367,   367,   368,   370,   369,   371,   371,
     372,   372,   373,   373,   375,   374,   374,   376,   376,   377,
     377,   377,   377,   377,   377,   377,   379,   380,   378,   382,
     383,   381,   385,   384,   386,   386,   387,   388,   388,   388,
     389,   390,   391,   390,   392,   392,   393,   394,   394,   395,
     396,   395,   398,   397,   399,   397,   400,   401,   402,   402,
     403,   404,   404,   405,   406,   406,   407,   407,   408,   409,
     410,   410,   411,   413,   412,   414,   412,   416,   415,   417,
     417,   419,   418,   420,   420,   421,   422,   422,   423,   424,
     425,   426,   427,   428,   429,   429,   430,   431,   432,   432,
     433,   434,   434,   435,   435,   436,   437,   437,   438,   438,
     439,   439,   440,   440,   440,   440,   441,   442,   442,   442,
     442,   443,   444,   445,   445,   446,   447,   447,   448,   448,
     449,   450,   450,   451,   451,   451,   452,   453,   453,   455,
     454,   456,   457,   457,   457,   457,   457,   458,   458,   459,
     459,   460,   460,   461,   461,   462,   462,   463,   463,   464,
     464,   464,   464,   464,   464,   465,   466,   467,   468,   468,
     469,   470,   471,   471,   472,   473,   474,   474,   475,   475,
     475,   475,   475,   475,   475,   475,   476,   477,   478,   478,
     479,   479,   480,   480,   481,   481,   481,   482,   482,   483,
     484,   484,   485,   485,   485,   485,   486,   486,   486,   486,
     486,   486,   486,   486,   487,   488,   488,   488,   488,   488,
     488,   488,   488,   488,   488,   488,   488,   488,   488,   488,
     488,   488,   488,   488,   488,   488,   488,   488,   488,   488,
     488,   488,   488,   488,   488,   488,   488,   488,   488,   488,
     488,   488,   488,   488,   488,   488,   488,   488,   488,   488,
     488,   488,   488,   488,   488,   488,   488,   488,   489,   489,
     490,   491,   491,   492,   494,   495,   496,   493,   498,   499,
     500,   497,   501,   501,   501,   502,   502,   503,   503,   503,
     503,   503,   504,   505,   505,   506,   507,   507,   508,   509,
     510,   510,   511,   511,   512,   512,   512,   513,   513,   513,
     514,   514,   514,   515,   515,   515,   516,   516,   517,   517,
     517,   517,   518,   518,   519,   519,   520,   520
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
       0,     1,     3,     2,     1,     1,     1,     2,     1,     2,
       0,     1,     4,     0,     1,     0,     1,     0,     1,     0,
       1,     3,     1,     2,     1,     1,     4,     1,     2,     1,
       2,     1,     3,     1,     2,     1,     1,     1,     1,     2,
       1,     1,     2,     2,     0,     1,     0,     1,     2,     2,
       1,     2,     0,     1,     0,     4,     0,     1,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     0,     1,     3,     0,     1,     3,
       3,     5,     5,     5,     2,     2,     2,     5,     2,     0,
       1,     0,     1,     2,     1,     0,     2,     2,     2,     2,
       1,     2,     1,     2,     0,     1,     2,     1,     1,     1,
       1,     3,     3,     0,     3,     0,     1,     0,     1,     3,
       0,     2,     0,     0,     0,     8,     2,     2,     0,     1,
       1,     1,     1,     1,     0,     4,     2,     0,     1,     3,
       0,     2,     2,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     0,     3,     0,     0,
       0,     6,     0,     0,     0,     7,     6,     2,     1,     1,
       0,     0,     6,     0,     2,     1,     0,     5,     0,     2,
       1,     3,     0,     2,     0,     4,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     0,     0,     4,     0,
       0,     4,     0,     3,     0,     2,     2,     1,     1,     1,
       2,     1,     0,     6,     0,     1,     2,     0,     2,     1,
       0,     5,     0,     3,     0,     3,     3,     2,     0,     1,
       2,     0,     2,     1,     0,     1,     1,     1,     2,     2,
       0,     2,     1,     0,     3,     0,     3,     0,     4,     1,
       1,     0,     3,     0,     1,     2,     0,     2,     1,     1,
       1,     1,     2,     2,     0,     2,     2,     2,     0,     2,
       2,     0,     1,     1,     2,     1,     1,     2,     2,     1,
       2,     3,     1,     1,     1,     2,     1,     1,     1,     2,
       3,     1,     2,     0,     2,     2,     0,     1,     1,     3,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     0,
       4,     4,     1,     1,     1,     1,     1,     0,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     0,     2,
       2,     2,     0,     2,     1,     2,     0,     1,     2,     2,
       2,     2,     2,     2,     2,     3,     1,     2,     1,     1,
       2,     2,     0,     1,     2,     2,     2,     0,     2,     2,
       0,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     4,     6,     4,     4,
       4,     4,     2,     2,     4,     4,     4,     4,     2,     1,
       4,     4,     4,     4,     6,     6,     6,     6,     6,     4,
       4,     4,     4,     4,     4,     4,     4,     2,     2,     2,
       4,     4,     4,     4,     4,     2,     8,     6,     6,     6,
       4,     4,     4,     4,     4,     1,     1,     1,     3,     1,
       7,     0,     1,     7,     0,     0,     0,     5,     0,     0,
       0,     6,     5,     5,     6,     1,     1,     1,     1,     1,
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
  "IT_LIMIT", "IT_OFFSET", "IT_VALUES", "IT_MEMBERS", "IT_STARTS",
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
  "_QUpdate_E_Opt", "_O_QGT_SEMI_E_S_QUpdate_E_Opt_C",
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
  "TriplesSameSubject", "$@36", "$@37", "PropertyListNotEmpty",
  "_O_QVerb_E_S_QObjectList_E_C", "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "Verb", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "TriplesSameSubjectPath", "$@38", "$@39",
  "PropertyListNotEmptyPath", "$@40", "_O_QVerbPath_E_Or_QVerbSimple_E_C",
  "_O_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_C", "$@41",
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
  "TriplesNode", "BlankNodePropertyList", "@42", "Generator",
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
  "SubstringExpression", "ExistsFunc", "@43", "@44", "@45",
  "NotExistsFunc", "@46", "@47", "@48", "Aggregate",
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
       188,     0,    -1,   189,    -1,   192,    -1,   190,    -1,   193,
     191,   287,    -1,   234,    -1,   250,    -1,   253,    -1,   257,
      -1,   290,    -1,   194,   195,   196,    -1,    -1,   230,    -1,
      -1,   195,   231,    -1,    -1,   196,   197,    -1,    -1,   200,
     198,   201,    -1,   161,    55,    -1,    -1,   199,    -1,   202,
      -1,   212,    -1,   222,    -1,   262,    -1,   204,   205,   203,
     211,    -1,   205,   203,    43,    -1,    -1,   203,   208,    -1,
     149,    -1,   102,   207,    -1,   210,    -1,   206,   210,    -1,
     102,    -1,   206,    -1,    -1,   102,   209,   207,    -1,   377,
     102,    -1,   149,    -1,   214,   215,   213,   221,    -1,   215,
     213,    43,    -1,    -1,   213,   218,    -1,   151,    -1,   153,
     217,    -1,   220,    -1,   216,   220,    -1,   153,    -1,   216,
      -1,    -1,   153,   219,   217,    -1,   377,   153,    -1,   152,
      -1,    36,   223,    37,    -1,    -1,   223,   224,    -1,    -1,
      40,   225,   228,    41,    -1,    -1,    48,    -1,   229,   226,
      -1,    -1,   228,   227,    -1,   377,   148,   377,    -1,   377,
     147,   377,    -1,   377,    55,   377,    -1,    14,   178,    -1,
      -1,    -1,    15,   232,   179,   233,   178,    -1,    -1,   235,
     241,   236,   263,   265,    -1,    -1,   236,   258,    -1,    -1,
      -1,    -1,   238,   239,   241,   240,   263,   265,   287,    -1,
      16,   243,   249,    -1,    17,    -1,    18,    -1,    -1,   242,
      -1,    89,   463,    -1,    -1,   244,    -1,    40,   465,   245,
      41,    -1,   488,    -1,   508,    -1,   512,    -1,   516,    -1,
     463,    -1,   501,    -1,   389,    -1,   246,    -1,   247,    -1,
     248,   247,    -1,   248,    -1,    19,    -1,    20,   251,    -1,
      -1,   323,   252,   236,   263,   265,    -1,   236,    39,   323,
     265,    -1,    21,   255,   236,   256,   265,    -1,   462,    -1,
     254,   462,    -1,   254,    -1,    19,    -1,    -1,   263,    -1,
      38,   236,   263,    -1,    22,   259,    -1,   260,    -1,   261,
      -1,   262,    -1,    23,   262,    -1,   518,    -1,   264,   338,
      -1,    -1,    39,    -1,   266,   267,   268,   269,    -1,    -1,
     270,    -1,    -1,   273,    -1,    -1,   276,    -1,    -1,   282,
      -1,    90,    25,   271,    -1,   272,    -1,   271,   272,    -1,
     488,    -1,   389,    -1,    40,   465,   245,    41,    -1,   463,
      -1,    91,   274,    -1,   275,    -1,   274,   275,    -1,   388,
      -1,    24,    25,   277,    -1,   278,    -1,   277,   278,    -1,
     280,    -1,   281,    -1,    26,    -1,    27,    -1,   279,   487,
      -1,   388,    -1,   463,    -1,   285,   283,    -1,   286,   284,
      -1,    -1,   286,    -1,    -1,   285,    -1,    28,   165,    -1,
      29,   165,    -1,   289,    -1,    30,   363,    -1,    -1,   288,
      -1,    -1,   193,   295,   291,   294,    -1,    -1,   290,    -1,
      49,   292,    -1,    -1,   293,    -1,   296,    -1,   299,    -1,
     301,    -1,   303,    -1,   304,    -1,   305,    -1,   302,    -1,
     306,    -1,   307,    -1,   308,    -1,   309,    -1,     8,   518,
     298,    -1,     9,   321,    -1,    -1,   297,    -1,    10,   300,
     322,    -1,    -1,    12,    -1,    13,   300,   322,    -1,    11,
     300,   321,    -1,   114,   300,   319,   110,   319,    -1,   128,
     300,   319,   110,   319,    -1,   115,   300,   319,   110,   319,
      -1,   130,   324,    -1,   120,   324,    -1,   118,   323,    -1,
     311,   313,   314,    39,   338,    -1,   103,   518,    -1,    -1,
     310,    -1,    -1,   316,    -1,   315,   312,    -1,   316,    -1,
      -1,   314,   317,    -1,     3,   323,    -1,     4,   323,    -1,
     106,   318,    -1,   518,    -1,    23,   518,    -1,   104,    -1,
     320,   518,    -1,    -1,     6,    -1,     6,   518,    -1,   321,
      -1,   104,    -1,    23,    -1,   105,    -1,    36,   325,    37,
      -1,    36,   325,    37,    -1,    -1,   326,   327,   330,    -1,
      -1,   335,    -1,    -1,    43,    -1,   331,   328,   327,    -1,
      -1,   330,   329,    -1,    -1,    -1,    -1,   332,     6,   462,
     333,    36,   334,   327,    37,    -1,   397,   337,    -1,    43,
     327,    -1,    -1,   336,    -1,   340,    -1,   161,    -1,   237,
      -1,   342,    -1,    -1,    36,   341,   339,    37,    -1,   343,
     345,    -1,    -1,   346,    -1,   349,   328,   343,    -1,    -1,
     345,   344,    -1,   412,   348,    -1,    43,   343,    -1,    -1,
     347,    -1,   381,    -1,   351,    -1,   378,    -1,   353,    -1,
     357,    -1,   387,    -1,   361,    -1,   362,    -1,   350,    -1,
     146,   338,    -1,    -1,    44,   352,   338,    -1,    -1,    -1,
      -1,     6,   354,   355,   462,   356,   338,    -1,    -1,    -1,
      -1,     7,   358,   359,   360,   300,   462,   338,    -1,   125,
      40,   465,    89,   463,    41,    -1,    30,   363,    -1,   364,
      -1,   369,    -1,    -1,    -1,   365,   463,   366,    36,   367,
      37,    -1,    -1,   367,   368,    -1,   377,    -1,    -1,   370,
     372,    36,   376,    37,    -1,    -1,   371,   463,    -1,   186,
      -1,    40,   371,    41,    -1,    -1,   373,   377,    -1,    -1,
      40,   375,   373,    41,    -1,   186,    -1,    -1,   376,   374,
      -1,   518,    -1,   508,    -1,   512,    -1,   516,    -1,    42,
      -1,   162,    -1,   463,    -1,    -1,    -1,    45,   379,   380,
     338,    -1,    -1,    -1,   382,   383,   338,   386,    -1,    -1,
      46,   385,   338,    -1,    -1,   386,   384,    -1,    47,   388,
      -1,   487,    -1,   488,    -1,   389,    -1,   518,   390,    -1,
     186,    -1,    -1,    40,   392,   465,   391,   394,    41,    -1,
      -1,    17,    -1,    48,   465,    -1,    -1,   394,   393,    -1,
     186,    -1,    -1,    40,   465,   396,   394,    41,    -1,    -1,
     461,   398,   400,    -1,    -1,   453,   399,   405,    -1,   407,
     408,   404,    -1,   407,   408,    -1,    -1,   401,    -1,    49,
     402,    -1,    -1,   404,   403,    -1,   406,    -1,    -1,   400,
      -1,   462,    -1,    50,    -1,   411,   410,    -1,    48,   411,
      -1,    -1,   410,   409,    -1,   460,    -1,    -1,   461,   413,
     415,    -1,    -1,   453,   414,   423,    -1,    -1,   417,   416,
     408,   422,    -1,   424,    -1,   425,    -1,    -1,   417,   419,
     408,    -1,    -1,   418,    -1,    49,   420,    -1,    -1,   422,
     421,    -1,   406,    -1,   426,    -1,   463,    -1,   427,    -1,
     430,   429,    -1,   102,   430,    -1,    -1,   429,   428,    -1,
     435,   432,    -1,    63,   435,    -1,    -1,   432,   431,    -1,
     441,   434,    -1,    -1,   436,    -1,   433,    -1,   100,   433,
      -1,   440,    -1,    37,    -1,   452,    37,    -1,    48,   437,
      -1,    37,    -1,   452,   438,    -1,    48,   452,    37,    -1,
      19,    -1,   101,    -1,    61,    -1,    36,   439,    -1,   442,
      -1,   518,    -1,    50,    -1,    64,   443,    -1,    40,   426,
      41,    -1,   448,    -1,   102,   449,    -1,    -1,   445,   444,
      -1,   449,   445,    -1,    -1,   446,    -1,   449,    -1,    40,
     447,    41,    -1,   451,    -1,   518,    -1,    50,    -1,   518,
      -1,    50,    -1,   100,   450,    -1,   165,    -1,   456,    -1,
     454,    -1,    -1,    51,   455,   400,    52,    -1,   458,    40,
     459,    41,    -1,    31,    -1,    32,    -1,    33,    -1,    34,
      -1,    35,    -1,    -1,   457,    -1,   460,    -1,   459,   460,
      -1,   461,    -1,   453,    -1,   463,    -1,   464,    -1,   463,
      -1,   518,    -1,   183,    -1,   184,    -1,   518,    -1,   508,
      -1,   512,    -1,   516,    -1,   520,    -1,   186,    -1,   466,
      -1,   469,   468,    -1,    53,   469,    -1,    -1,   468,   467,
      -1,   472,   471,    -1,    54,   472,    -1,    -1,   471,   470,
      -1,   473,    -1,   476,   474,    -1,    -1,   475,    -1,    55,
     476,    -1,    56,   476,    -1,    57,   476,    -1,    58,   476,
      -1,    59,   476,    -1,    60,   476,    -1,    66,   395,    -1,
      65,    66,   395,    -1,   477,    -1,   483,   482,    -1,   514,
      -1,   515,    -1,    19,   485,    -1,    63,   485,    -1,    -1,
     479,    -1,    61,   483,    -1,    62,   483,    -1,   478,   480,
      -1,    -1,   482,   481,    -1,   485,   484,    -1,    -1,   484,
     479,    -1,    64,   486,    -1,    61,   486,    -1,    62,   486,
      -1,   486,    -1,   487,    -1,   488,    -1,   506,    -1,   508,
      -1,   512,    -1,   516,    -1,   463,    -1,   501,    -1,    40,
     465,    41,    -1,    76,    40,   465,    41,    -1,    77,    40,
     465,    41,    -1,    78,    40,   465,    48,   465,    41,    -1,
      79,    40,   465,    41,    -1,    80,    40,   463,    41,    -1,
      67,    40,   465,    41,    -1,    68,    40,   465,    41,    -1,
      69,   489,    -1,   116,   186,    -1,   140,    40,   465,    41,
      -1,   137,    40,   465,    41,    -1,   129,    40,   465,    41,
      -1,   123,    40,   465,    41,    -1,    88,   395,    -1,   492,
      -1,   143,    40,   465,    41,    -1,   141,    40,   465,    41,
      -1,   139,    40,   465,    41,    -1,   135,    40,   465,    41,
      -1,   126,    40,   465,    48,   465,    41,    -1,   136,    40,
     465,    48,   465,    41,    -1,   142,    40,   465,    48,   465,
      41,    -1,   111,    40,   465,    48,   465,    41,    -1,   112,
      40,   465,    48,   465,    41,    -1,   113,    40,   465,    41,
      -1,   145,    40,   465,    41,    -1,   138,    40,   465,    41,
      -1,   134,    40,   465,    41,    -1,   131,    40,   465,    41,
      -1,   127,    40,   465,    41,    -1,   122,    40,   465,    41,
      -1,   121,    40,   465,    41,    -1,   119,   186,    -1,   107,
     186,    -1,   108,   186,    -1,   109,    40,   465,    41,    -1,
     144,    40,   465,    41,    -1,   133,    40,   465,    41,    -1,
     124,    40,   465,    41,    -1,   117,    40,   465,    41,    -1,
      70,   395,    -1,    71,    40,   465,    48,   465,    48,   465,
      41,    -1,    72,    40,   465,    48,   465,    41,    -1,    73,
      40,   465,    48,   465,    41,    -1,    81,    40,   465,    48,
     465,    41,    -1,    82,    40,   465,    41,    -1,    83,    40,
     465,    41,    -1,    84,    40,   465,    41,    -1,    85,    40,
     465,    41,    -1,    99,    40,   465,    41,    -1,   490,    -1,
     493,    -1,   497,    -1,    40,   465,    41,    -1,   186,    -1,
      86,    40,   465,    48,   465,   491,    41,    -1,    -1,   393,
      -1,   132,    40,   465,    48,   465,   491,    41,    -1,    -1,
      -1,    -1,    74,   494,   495,   496,   338,    -1,    -1,    -1,
      -1,    65,    74,   498,   499,   500,   338,    -1,    92,    40,
     392,   502,    41,    -1,   503,    40,   392,   465,    41,    -1,
      97,    40,   392,   465,   505,    41,    -1,    19,    -1,   465,
      -1,    93,    -1,    94,    -1,    95,    -1,    96,    -1,    98,
      -1,    49,    75,    55,   517,    -1,    -1,   504,    -1,   518,
     507,    -1,    -1,   390,    -1,   517,   511,    -1,    87,   518,
      -1,   185,    -1,   509,    -1,    -1,   510,    -1,   513,    -1,
     514,    -1,   515,    -1,   165,    -1,   166,    -1,   167,    -1,
     168,    -1,   169,    -1,   170,    -1,   171,    -1,   172,    -1,
     173,    -1,   163,    -1,   164,    -1,   174,    -1,   176,    -1,
     175,    -1,   177,    -1,   178,    -1,   519,    -1,   180,    -1,
     179,    -1,   181,    -1,   182,    -1
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
     277,   278,   280,   284,   287,   289,   291,   293,   296,   298,
     301,   302,   304,   309,   310,   312,   313,   315,   316,   318,
     319,   321,   325,   327,   330,   332,   334,   339,   341,   344,
     346,   349,   351,   355,   357,   360,   362,   364,   366,   368,
     371,   373,   375,   378,   381,   382,   384,   385,   387,   390,
     393,   395,   398,   399,   401,   402,   407,   408,   410,   413,
     414,   416,   418,   420,   422,   424,   426,   428,   430,   432,
     434,   436,   438,   442,   445,   446,   448,   452,   453,   455,
     459,   463,   469,   475,   481,   484,   487,   490,   496,   499,
     500,   502,   503,   505,   508,   510,   511,   514,   517,   520,
     523,   525,   528,   530,   533,   534,   536,   539,   541,   543,
     545,   547,   551,   555,   556,   560,   561,   563,   564,   566,
     570,   571,   574,   575,   576,   577,   586,   589,   592,   593,
     595,   597,   599,   601,   603,   604,   609,   612,   613,   615,
     619,   620,   623,   626,   629,   630,   632,   634,   636,   638,
     640,   642,   644,   646,   648,   650,   653,   654,   658,   659,
     660,   661,   668,   669,   670,   671,   679,   686,   689,   691,
     693,   694,   695,   702,   703,   706,   708,   709,   715,   716,
     719,   721,   725,   726,   729,   730,   735,   737,   738,   741,
     743,   745,   747,   749,   751,   753,   755,   756,   757,   762,
     763,   764,   769,   770,   774,   775,   778,   781,   783,   785,
     787,   790,   792,   793,   800,   801,   803,   806,   807,   810,
     812,   813,   819,   820,   824,   825,   829,   833,   836,   837,
     839,   842,   843,   846,   848,   849,   851,   853,   855,   858,
     861,   862,   865,   867,   868,   872,   873,   877,   878,   883,
     885,   887,   888,   892,   893,   895,   898,   899,   902,   904,
     906,   908,   910,   913,   916,   917,   920,   923,   926,   927,
     930,   933,   934,   936,   938,   941,   943,   945,   948,   951,
     953,   956,   960,   962,   964,   966,   969,   971,   973,   975,
     978,   982,   984,   987,   988,   991,   994,   995,   997,   999,
    1003,  1005,  1007,  1009,  1011,  1013,  1016,  1018,  1020,  1022,
    1023,  1028,  1033,  1035,  1037,  1039,  1041,  1043,  1044,  1046,
    1048,  1051,  1053,  1055,  1057,  1059,  1061,  1063,  1065,  1067,
    1069,  1071,  1073,  1075,  1077,  1079,  1081,  1084,  1087,  1088,
    1091,  1094,  1097,  1098,  1101,  1103,  1106,  1107,  1109,  1112,
    1115,  1118,  1121,  1124,  1127,  1130,  1134,  1136,  1139,  1141,
    1143,  1146,  1149,  1150,  1152,  1155,  1158,  1161,  1162,  1165,
    1168,  1169,  1172,  1175,  1178,  1181,  1183,  1185,  1187,  1189,
    1191,  1193,  1195,  1197,  1199,  1203,  1208,  1213,  1220,  1225,
    1230,  1235,  1240,  1243,  1246,  1251,  1256,  1261,  1266,  1269,
    1271,  1276,  1281,  1286,  1291,  1298,  1305,  1312,  1319,  1326,
    1331,  1336,  1341,  1346,  1351,  1356,  1361,  1366,  1369,  1372,
    1375,  1380,  1385,  1390,  1395,  1400,  1403,  1412,  1419,  1426,
    1433,  1438,  1443,  1448,  1453,  1458,  1460,  1462,  1464,  1468,
    1470,  1478,  1479,  1481,  1489,  1490,  1491,  1492,  1498,  1499,
    1500,  1501,  1508,  1514,  1520,  1527,  1529,  1531,  1533,  1535,
    1537,  1539,  1541,  1546,  1547,  1549,  1552,  1553,  1555,  1558,
    1561,  1563,  1565,  1566,  1568,  1570,  1572,  1574,  1576,  1578,
    1580,  1582,  1584,  1586,  1588,  1590,  1592,  1594,  1596,  1598,
    1600,  1602,  1604,  1606,  1608,  1610,  1612,  1614
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   480,   480,   483,   489,   494,   505,   506,   507,   508,
     512,   517,   521,   523,   527,   529,   532,   534,   538,   538,
     556,   562,   565,   569,   570,   571,   572,   578,   579,   582,
     584,   588,   592,   596,   597,   601,   602,   606,   606,   614,
     620,   624,   625,   628,   630,   634,   638,   642,   643,   647,
     648,   652,   652,   660,   666,   670,   673,   675,   679,   679,
     686,   688,   692,   695,   697,   701,   704,   707,   713,   719,
     721,   719,   731,   731,   743,   746,   754,   757,   760,   754,
     775,   783,   786,   793,   796,   801,   808,   811,   816,   823,
     826,   829,   832,   835,   838,   841,   845,   850,   853,   861,
     864,   870,   876,   876,   883,   893,   901,   904,   912,   915,
     922,   925,   930,   938,   945,   946,   950,   956,   962,   969,
     976,   978,   983,   990,   993,   998,  1001,  1006,  1009,  1014,
    1018,  1022,  1029,  1032,  1039,  1042,  1045,  1048,  1054,  1060,
    1063,  1070,  1075,  1082,  1086,  1094,  1096,  1104,  1107,  1115,
    1123,  1124,  1131,  1135,  1143,  1146,  1151,  1154,  1158,  1164,
    1170,  1174,  1180,  1183,  1187,  1187,  1196,  1198,  1202,  1205,
    1207,  1211,  1212,  1213,  1214,  1215,  1216,  1217,  1218,  1219,
    1220,  1221,  1225,  1232,  1239,  1242,  1246,  1252,  1255,  1261,
    1267,  1273,  1279,  1285,  1291,  1299,  1307,  1314,  1323,  1329,
    1332,  1336,  1339,  1343,  1347,  1353,  1355,  1361,  1367,  1373,
    1379,  1382,  1388,  1391,  1396,  1398,  1402,  1408,  1411,  1414,
    1417,  1424,  1430,  1436,  1436,  1444,  1446,  1450,  1452,  1456,
    1459,  1461,  1466,  1471,  1474,  1466,  1485,  1489,  1492,  1494,
    1498,  1499,  1512,  1513,  1518,  1518,  1529,  1533,  1535,  1545,
    1549,  1552,  1568,  1573,  1577,  1580,  1584,  1585,  1586,  1587,
    1588,  1589,  1590,  1591,  1594,  1598,  1604,  1604,  1620,  1624,
    1626,  1620,  1637,  1641,  1643,  1637,  1654,  1665,  1671,  1672,
    1676,  1678,  1676,  1685,  1687,  1691,  1699,  1699,  1706,  1708,
    1714,  1715,  1718,  1720,  1726,  1726,  1731,  1737,  1739,  1743,
    1746,  1749,  1752,  1755,  1758,  1761,  1767,  1771,  1767,  1781,
    1785,  1781,  1795,  1795,  1807,  1809,  1813,  1823,  1824,  1825,
    1829,  1837,  1841,  1841,  1851,  1854,  1861,  1867,  1869,  1883,
    1886,  1886,  1896,  1896,  1899,  1899,  1906,  1911,  1915,  1917,
    1922,  1926,  1928,  1933,  1937,  1939,  1943,  1947,  1955,  1960,
    1964,  1966,  1970,  1978,  1978,  1981,  1981,  1987,  1987,  1993,
    1994,  1998,  1998,  2003,  2005,  2009,  2012,  2014,  2018,  2022,
    2026,  2032,  2036,  2040,  2043,  2045,  2049,  2053,  2058,  2060,
    2066,  2069,  2071,  2077,  2078,  2084,  2088,  2089,  2093,  2094,
    2098,  2099,  2103,  2104,  2105,  2106,  2110,  2114,  2117,  2120,
    2123,  2129,  2133,  2136,  2138,  2142,  2145,  2147,  2151,  2152,
    2156,  2160,  2161,  2165,  2166,  2167,  2171,  2176,  2177,  2181,
    2181,  2194,  2221,  2224,  2227,  2230,  2233,  2240,  2243,  2248,
    2252,  2259,  2260,  2264,  2267,  2271,  2274,  2280,  2281,  2285,
    2288,  2291,  2294,  2297,  2298,  2304,  2309,  2318,  2325,  2328,
    2336,  2345,  2352,  2355,  2362,  2367,  2380,  2384,  2388,  2392,
    2396,  2400,  2404,  2408,  2412,  2416,  2423,  2428,  2437,  2440,
    2447,  2450,  2457,  2460,  2465,  2468,  2472,  2486,  2489,  2497,
    2506,  2509,  2516,  2519,  2522,  2525,  2529,  2530,  2531,  2532,
    2535,  2538,  2541,  2544,  2548,  2554,  2557,  2560,  2563,  2566,
    2569,  2572,  2576,  2579,  2582,  2585,  2588,  2591,  2594,  2597,
    2598,  2601,  2604,  2607,  2610,  2613,  2616,  2619,  2622,  2625,
    2628,  2631,  2634,  2637,  2640,  2643,  2646,  2649,  2652,  2655,
    2658,  2661,  2664,  2667,  2670,  2673,  2676,  2679,  2682,  2685,
    2688,  2691,  2694,  2697,  2700,  2703,  2704,  2705,  2711,  2714,
    2721,  2728,  2731,  2735,  2741,  2744,  2747,  2741,  2760,  2763,
    2766,  2760,  2780,  2784,  2789,  2798,  2801,  2805,  2808,  2811,
    2814,  2817,  2823,  2829,  2832,  2836,  2846,  2849,  2854,  2862,
    2869,  2873,  2881,  2885,  2889,  2890,  2891,  2895,  2896,  2897,
    2901,  2902,  2903,  2907,  2908,  2909,  2913,  2914,  2918,  2919,
    2920,  2921,  2925,  2926,  2930,  2931,  2935,  2936
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
  const int SPARQLfedParser::yylast_ = 2420;
  const int SPARQLfedParser::yynnts_ = 334;
  const int SPARQLfedParser::yyempty_ = -2;
  const int SPARQLfedParser::yyfinal_ = 11;
  const int SPARQLfedParser::yyterror_ = 1;
  const int SPARQLfedParser::yyerrcode_ = 256;
  const int SPARQLfedParser::yyntokens_ = 187;

  const unsigned int SPARQLfedParser::yyuser_token_number_max_ = 441;
  const SPARQLfedParser::token_number_type SPARQLfedParser::yyundef_token_ = 2;


} // w3c_sw

/* Line 1136 of lalr1.cc  */
#line 5768 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 2942 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


