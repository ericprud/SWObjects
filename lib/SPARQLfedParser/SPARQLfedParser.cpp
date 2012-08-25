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

  case 104:

/* Line 690 of lalr1.cc  */
#line 881 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = NULL;
      }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 883 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause);
	  /* $1 is NO LONGER known to be a DefaultGraphPattern because of grammar restrictions. */
	  (yyval.p_Operation) = new Construct((yysemantic_stack_[(5) - (1)].p_TableOperation), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
      }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 888 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	const TableOperation* pattern = driver.ensureGraphPattern();
	SWObjectDuplicator dup(driver.atomFactory);
	pattern->express(&dup);
	driver.lastWhereClause = new WhereClause(pattern);
	(yyval.p_Operation) = new Construct(dup.last.tableOperation, (yysemantic_stack_[(6) - (1)].p_DatasetClauses), driver.lastWhereClause, (yysemantic_stack_[(6) - (6)].p_SolutionModifier));
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 899 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause) ? (yysemantic_stack_[(5) - (4)].p_WhereClause) : new WhereClause(new DefaultGraphPattern());
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 907 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm))));
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 910 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_TTerm))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 918 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 921 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 928 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 936 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(3) - (3)].p_WhereClause);
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(3) - (2)].p_DatasetClauses), (yysemantic_stack_[(3) - (3)].p_WhereClause));
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 944 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 956 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 962 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 968 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 975 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.ensureGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 989 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 996 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1004 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1012 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1020 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1028 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1035 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1038 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1045 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1048 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1051 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1054 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1060 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1066 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1069 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1081 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1088 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1092 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1102 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1110 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1113 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1121 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1130 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1137 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1141 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1149 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1157 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1164 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1170 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1180 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = (yysemantic_stack_[(2) - (2)].p_BindingClause);
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1186 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1193 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	OperationSet* ret = driver.root ? dynamic_cast<OperationSet*>(driver.root) : new OperationSet();
	ret->push_back((yysemantic_stack_[(2) - (2)].p_Operation));
	driver.root = ret;
      }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1197 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Operation) = driver.root;
	}
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1231 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(3) - (2)].p_URI), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1238 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1245 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1252 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1258 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1261 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1267 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1273 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1279 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1285 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1291 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1297 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1305 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1313 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1320 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(5) - (1)].p_URI))
	    w3c_sw_NEED_IMPL("WITH <URI> (DELETE INSERT?|INSERT) ...");
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(5) - (2)].p_DeleteInsert).del, (yysemantic_stack_[(5) - (2)].p_DeleteInsert).ins, new WhereClause(driver.ensureGraphPattern()));
	driver.curOp = NULL;
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1329 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1335 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1342 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1349 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1353 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1361 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("_QUsingClause_E_Star");
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1367 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Delete) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1373 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = new Insert((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1379 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 1385 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1388 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 1394 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 1397 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 1408 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 1414 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1417 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("DEFAULT");
      }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 1420 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("NAMED");
      }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1423 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("ALL");
      }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 1430 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
    }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 1436 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
    }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 1442 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 1444 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TableOperation) = driver.ensureGraphPattern();
	  driver.curOp = NULL;
      }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 1467 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 1472 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 1475 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 1478 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 1500 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 1519 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 1521 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 1592 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_BindingClause)) : (yysemantic_stack_[(1) - (1)].p_BindingClause);
    }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 1599 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Print(driver.curOp);
    }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 1605 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 1609 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 1621 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 1625 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 1627 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 1630 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 1638 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 1642 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 1644 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 1647 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(7) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(7) - (6)].p_TTerm), driver.curOp, (yysemantic_stack_[(7) - (5)].p_Silence), driver.atomFactory, false));
	  driver.curGraphName = (yysemantic_stack_[(7) - (4)].p_TTerm);
      }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 1655 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 1666 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = (yysemantic_stack_[(2) - (2)].p_BindingClause);
    }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 1677 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 1679 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
      }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 1681 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 1692 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
	driver.endBindingRow();
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 1700 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 1702 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 1709 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 1721 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 1727 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 1729 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 1732 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 1744 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 1747 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 1750 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 1753 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 1756 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 1759 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 1762 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 1768 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 1772 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 1774 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 1782 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 1786 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 1788 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 1796 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 1801 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.ensureGraphPattern());
      }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 1814 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 1830 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 1838 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 1842 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 1845 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yysemantic_stack_[(6) - (4)].p_Expressions);
      }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 1852 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 1855 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 1862 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 1870 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 1884 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 1887 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 1890 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(5) - (3)].p_Expressions);
      }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 1897 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 1900 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 1944 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 1948 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 1971 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 1979 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 1982 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 1988 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 1999 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 2027 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 2054 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 2061 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 2072 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 2079 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 2115 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 2118 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 2121 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 2124 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 2182 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 2186 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 2195 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 2222 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 2225 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 2228 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 2231 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 2234 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 2241 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 2249 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 2253 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 2265 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 2272 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 2275 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 2286 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 2289 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 2292 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 2295 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 2299 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 2310 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 2319 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 2326 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 2329 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 2337 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 2346 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 2353 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 2356 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 2368 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 2381 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = NULL;
    }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 2389 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 2393 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 2397 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 2401 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 2405 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 2409 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 2413 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 2417 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = true;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 2429 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 2438 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 2441 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 2448 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 2451 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 2458 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 2466 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 2469 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 2473 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 2487 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 2490 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 2498 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 2507 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 2510 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 2517 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 2520 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 2523 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 2533 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 2536 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 2539 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 2542 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 2549 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 2555 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 2558 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 2561 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 2564 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 2567 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 2570 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 2573 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 2577 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 2580 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 2583 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 2586 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ceil, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 2589 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 2592 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 2595 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 2599 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 2602 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 2605 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 2608 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 2611 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 2614 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 2617 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 2620 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 2623 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 2626 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 2629 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 2632 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 2635 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 2638 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 2641 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 2644 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 2647 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 2650 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 2653 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_uuid, NULL, NULL, NULL));
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 2656 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_struuid, NULL, NULL, NULL));
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 2659 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 2662 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 2665 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 2668 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 2671 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 2674 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 2677 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 2680 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 2683 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 2686 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 2689 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 2692 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 2695 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 2698 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 2701 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 2712 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 2715 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 2722 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 2729 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 2736 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 2742 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 2745 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 2748 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 2752 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expression) = new ExistsExpression(driver.ensureGraphPattern());
	  driver.curOp = (yysemantic_stack_[(5) - (4)].p_TableOperation);
	  driver.curGraphName = (yysemantic_stack_[(5) - (3)].p_TTerm);
	  driver.countStar = (yysemantic_stack_[(5) - (2)].p_parentCountStar);
      }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 2761 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 2764 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 2767 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 2771 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 2781 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 2785 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 2790 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  AggregateCall::ScalarVals svals;
	  if ((yysemantic_stack_[(6) - (5)].p_RDFLiteral) != NULL)
	      svals["separator"] = (yysemantic_stack_[(6) - (5)].p_RDFLiteral)->getLexicalValue();
	  (yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression), svals));
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 2799 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 2806 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 2809 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 2812 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 2815 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 2818 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 2824 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 2830 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 2837 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 2847 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 2855 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 2863 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 2870 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 2874 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 2882 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 690 of lalr1.cc  */
#line 3835 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -846;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        61,  -101,   104,  -846,  -846,  -846,   306,  -846,  -846,  -846,
    -846,  -846,   145,    98,    98,    98,    76,     3,  -846,   145,
      98,    98,    76,    78,    98,    78,    86,  -846,   118,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,   157,   121,  -846,  -846,  -846,
     134,  -846,  -846,   216,   148,   216,  -846,    27,  -846,  -846,
    -846,  -846,  -846,   122,  -846,  -846,  -846,  -846,    45,  -846,
      33,    33,  -846,  -846,  -846,    33,  -846,    -8,  -846,  -846,
    -846,   235,  -846,   125,    76,    76,  -846,   209,  -846,  -846,
      63,  -846,   148,  -846,  -846,   145,  -846,  -846,  -846,  -846,
    -846,  -846,  -846,   181,  1059,    -3,   192,  -846,  -846,  -846,
      42,  -846,  -846,   -10,  -846,  -846,   124,   145,   126,   201,
     135,  -846,  -846,    79,  -846,    -6,  -846,  -846,  -846,  1412,
      45,    57,  -846,  -846,  -846,  -846,    14,  -846,  -846,    68,
     200,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,
    -846,  -846,  -846,   215,  -846,  -846,  -846,  -846,   225,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,   -45,  -846,
    -846,   145,  -846,  -846,  -846,  -846,  -846,  1059,    45,   188,
    -846,  -846,  -846,  -846,  -846,    33,  -846,    33,  -846,    33,
    -846,  -846,  -846,   231,  -846,  1626,   206,   244,   252,    -2,
       5,   263,   267,   272,  -846,   278,   288,   290,   292,   293,
     297,   298,   303,   313,   318,   319,     5,   321,  -846,  -846,
    -846,  -846,   328,  -846,   334,   190,   191,   344,   345,   347,
     348,   211,   351,   213,   361,   362,   364,   365,   366,   370,
     371,   373,   374,   376,   377,   378,   379,   382,   383,   385,
     398,   399,   400,   401,   402,   403,  -846,  -846,  1746,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,   406,  -846,
    -846,  -846,     6,   188,   611,  -846,  -846,   -10,    10,  -846,
    -846,  -846,   130,   -21,   441,  1059,  -846,  -846,   -21,  1436,
     -21,   145,  -846,  -846,  -846,  -846,  -846,   411,   188,   424,
    -846,   360,  -846,   887,  -846,  -846,  -846,   416,    11,  -846,
    1626,  1866,  1866,  1866,  -846,   375,  -846,  -846,  -846,  -846,
     307,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,
    -846,  -846,     6,  -846,  1626,  1626,  1626,  -846,  -846,  1626,
    -846,  -846,  1626,  1626,  1626,  -846,  1626,  1626,  1626,  1626,
      79,  1626,  1626,  1626,  1626,  1626,  1626,  -846,   437,   437,
    1626,  -846,  -846,  1626,  1626,  1626,  1626,  -846,  1626,  -846,
    1626,  1626,  1626,  1626,  1626,  1626,  1626,  1626,  1626,  1626,
    1626,  1626,  1626,  1626,  1626,  1626,  1626,  1626,  1626,  1626,
    1626,  1626,  -846,   437,   437,  -846,  -846,  -846,  -846,   145,
    -846,  -846,   277,  -846,  2050,  -846,  -846,  2010,  -846,  -846,
     367,  -846,  -846,   310,  -846,  -846,  -846,  -846,   414,  1436,
    -846,  -846,   425,   461,  -846,  -846,  -846,  -846,  -846,  1481,
    -846,  -846,  -846,  -846,   188,  -846,  1986,  2195,   447,  -846,
    -846,  -846,   435,  -846,  -846,  -846,   430,  -846,  -846,  -846,
    -846,  -846,   -16,   439,  -846,  -846,  -846,    79,  -846,   442,
     431,   433,  1626,  1626,  1626,  1626,  1626,  1626,   412,     5,
    -846,  -846,   289,    35,  -846,  -846,  -846,   444,   448,   450,
    -846,   445,   446,   449,  -846,   451,   454,   452,   455,   457,
     453,   463,   464,   466,   467,   469,  -846,  1238,  1626,   468,
     471,   470,   472,   478,   480,   482,   484,   485,   487,   483,
     489,   491,   492,   488,   494,   497,   498,   493,   501,   503,
     507,   508,   509,   506,   510,   514,   515,  1626,  1626,  -846,
    -846,   105,  -846,  -846,  -846,  2074,  -846,  -846,   459,  -846,
    -846,  -846,  -846,  -846,  -846,  2074,  -846,  -846,   349,  -846,
       1,  -846,    -7,  -846,  -846,  -846,  -846,  -846,  1059,   122,
    -846,  -846,  -846,  1626,  1986,  -846,  -846,  -846,  -846,  2195,
    -846,  -846,  -846,  -846,  -846,   537,   241,  -846,   118,  -846,
      94,  1059,  -846,  -846,   -21,    22,   473,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,  1626,  -846,  1626,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,     5,  -846,  1626,  1626,    35,  -846,
    -846,  -846,  1626,  1626,  -846,  -846,  -846,  -846,  -846,  -846,
    1626,  1626,  1626,   -10,  -846,  -846,  1626,  -846,  -846,  1626,
    -846,  -846,  -846,  -846,  1626,  -846,  -846,   522,   519,  -846,
    -846,  1626,  1626,  -846,  -846,  -846,  -846,  -846,  -846,  1626,
    -846,  -846,  -846,  1626,  -846,  -846,  -846,  1626,  -846,  -846,
    -846,  -846,  -846,  1626,  -846,  -846,  -846,   528,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,   -62,  -846,  -846,  -846,
     123,  -846,  -846,  -846,   521,   523,  -846,  -846,   375,  -846,
    -846,  1076,   408,   409,  -846,  -846,   546,   548,  -846,  -846,
    -846,    -8,  -846,  -846,  2195,   538,   -10,  -846,   425,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,
    -846,  -846,    71,  -846,    29,    18,  -846,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,   212,  -846,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,
    -846,  -846,   -10,    54,   531,   539,   541,  -846,   542,   543,
     540,  -846,   511,  -846,   544,   549,   554,   555,   540,   557,
     558,  -846,  -846,  -846,  -846,  -846,  2050,  -846,  -846,  2010,
     -21,  -846,  1436,  -846,   551,   559,  -846,  -846,  1076,  -846,
     562,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,
    -846,   567,  -846,  -846,  -846,   -10,  -846,  -846,  1626,  -846,
    1059,   -10,   566,   177,  -846,   161,  -846,  -846,  -846,  -846,
    -846,  -846,  1436,   513,   545,  -846,   -18,  -846,  -846,  -846,
    -846,  -846,   517,  -846,  -846,  1626,  -846,  1626,  -846,  -846,
    -846,  -846,  -846,   568,   556,  -846,  -846,  -846,  -846,   571,
    -846,  -846,    65,  1971,  -846,  -846,  -846,  -846,  1436,  -846,
    -846,  -846,  -846,  -846,   188,   122,  -846,  -846,   -10,   524,
    -846,  -846,  -846,  -846,   575,  -846,  -846,  -846,  -846,  -846,
      71,  -846,    71,  -846,   458,  -846,  -846,    37,  -846,  -846,
    -846,   576,  -846,   205,  -846,  -846,  -846,  -846,   570,    73,
    -846,  1059,    86,  -846,    98,  -846,    79,   574,  -846,   526,
     577,  -846,  -846,   588,  -846,    39,  -846,  -846,  -846,  -846,
    -846,  2074,  2074,  2074,   592,  -846,   -10,   122,   593,  -846,
    -846,   177,  -846,    22,  -846,  -846,  -846,  -846,   596,  -846,
    -846,  -846,  -846,  -846,   -10,  -846,   -10,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,  1436,  -846
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        12,     0,     0,     2,     4,     3,   201,    14,    13,    10,
      68,     1,     0,   189,   189,   189,    74,     0,    74,     0,
     189,   189,     0,     0,   189,     0,   164,     6,     0,     7,
       8,     9,   166,   173,   174,   175,   179,   176,   177,   178,
     180,   181,   182,   183,   202,     0,    16,   602,   605,   604,
     186,   603,   190,     0,     0,     0,   225,     0,   101,   104,
     111,   437,   438,   110,    74,   108,   435,   436,   122,   200,
     216,   216,   198,   225,   197,   216,   196,   280,     5,   165,
     162,    83,    74,   171,     0,     0,   207,   203,   206,    69,
      11,    15,     0,   187,   184,     0,   221,   220,   222,   219,
     188,   192,   191,     0,   102,     0,     0,    75,    74,   109,
     112,   123,   114,     0,   217,   214,     0,     0,     0,     0,
       0,   163,   278,     0,   279,     0,    81,    82,    84,     0,
     122,    12,   172,   167,   209,   210,     0,   205,   204,     0,
       0,    17,    22,    18,   185,   218,   223,   422,   423,   424,
     425,   426,   419,   596,   597,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   598,   600,   599,   601,   606,   607,
     444,   230,   103,   238,   334,   418,   417,   428,     0,   332,
     433,   434,   440,   441,   584,   585,   586,   442,   582,   439,
     443,     0,   115,   116,   117,   118,   120,   102,   122,   125,
     113,   244,   241,   121,   240,   216,   215,   216,   224,   216,
     281,   288,   290,     0,   100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   554,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   567,   568,
     569,   570,     0,   571,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    99,    80,
      95,    93,    89,   545,   509,   546,   547,    94,     0,    90,
      91,    92,     0,   125,   201,   169,   170,     0,     0,   208,
      70,    20,     0,     0,   226,   102,   239,   236,   344,   427,
       0,     0,   580,   581,   583,   578,   119,     0,   125,     0,
     107,   127,   126,   247,   193,   195,   194,     0,     0,   297,
       0,     0,     0,     0,   492,    86,   445,   448,   452,   454,
     456,   466,   477,   480,   485,   486,   487,   493,   488,   489,
     490,   491,   576,   558,     0,     0,     0,   549,   502,     0,
     329,   535,     0,     0,     0,   555,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   508,   324,   324,
       0,   528,   529,     0,     0,     0,     0,   503,     0,   527,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,   324,   324,   321,   320,    73,   199,     0,
     211,   212,     0,    56,     0,    31,    45,     0,    19,    23,
       0,    29,    24,     0,    43,    25,    26,   347,     0,   427,
     346,   231,   227,     0,   237,   345,   335,   343,   432,   427,
     429,   431,   333,   579,   125,   105,     0,     0,   129,   128,
     242,    77,     0,   243,   250,   248,   254,   355,   353,   283,
     291,   289,     0,     0,   483,   484,   482,     0,    87,     0,
     446,   450,     0,     0,     0,     0,     0,     0,     0,     0,
     455,   457,   467,   479,   577,   575,   559,     0,     0,     0,
     330,     0,     0,     0,   556,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   325,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   213,
      71,     0,   303,    35,   304,    36,    32,    33,     0,   305,
     300,   301,   302,   299,    49,    50,    46,    47,     0,    29,
       0,    43,     0,   420,   341,   350,   352,   228,   102,     0,
     421,   430,   106,     0,   133,   134,   137,   139,   136,   140,
     141,   143,   319,   317,   318,     0,   131,   130,     0,   245,
     309,   247,   255,   252,   344,     0,     0,   287,   294,   296,
     298,   494,    85,    88,     0,   449,     0,   453,   458,   459,
     460,   461,   462,   463,     0,   464,     0,     0,   472,   478,
     468,   469,     0,     0,   481,   560,   500,   501,   548,   327,
       0,     0,     0,     0,   495,   496,     0,   498,   499,     0,
     540,   541,   542,   543,     0,   565,   566,     0,   573,   544,
     530,     0,     0,   519,   534,   526,   525,   507,   533,     0,
     524,   506,   523,     0,   532,   522,   513,     0,   505,   521,
     512,   504,   511,     0,   510,   531,   520,     0,   322,    55,
      58,    57,    34,    39,    48,    53,     0,    28,    37,    30,
       0,    42,    51,    44,   336,   348,   229,   233,    86,   135,
     142,     0,     0,     0,   124,   132,   156,   158,    78,   268,
     272,   280,   266,   306,     0,     0,     0,   251,   227,   264,
     257,   259,   260,   262,   263,   258,   256,   310,   261,   253,
     368,   356,     0,   398,     0,     0,   354,   357,   359,   360,
     369,   371,   374,   383,   378,   381,   396,   370,   397,   282,
     284,   285,   292,   447,   451,   465,   474,   475,   473,   476,
     470,   471,     0,     0,     0,     0,     0,   557,     0,     0,
     551,   562,     0,   574,     0,     0,     0,     0,   551,     0,
       0,   563,   327,    63,    40,    27,     0,    54,    41,     0,
     338,   342,   427,   351,     0,     0,   149,   150,   144,   145,
       0,   147,   148,   152,   153,   160,   161,   154,   157,   155,
     159,   122,   269,   273,   277,     0,   307,   316,     0,   265,
     247,     0,     0,   406,   414,     0,   399,   401,   408,   410,
     413,   384,   427,   372,   376,   392,     0,   394,   393,   380,
     382,   385,     0,   561,   331,     0,   328,     0,   537,   538,
     497,   539,   552,     0,     0,   564,   517,   518,   514,     0,
     515,   516,     0,     0,    38,    52,   339,   340,   427,   349,
     234,   138,   146,   151,   125,     0,   274,   267,     0,     0,
     249,   314,   400,   407,     0,   403,   412,   415,   411,   366,
       0,   375,     0,   379,     0,   416,   395,     0,   295,   293,
     326,     0,   550,     0,   553,   323,    59,    64,    60,     0,
     337,   102,   164,   270,   189,   308,     0,   311,   409,   405,
     358,   373,   377,     0,   389,     0,   390,   536,   572,    61,
      62,     0,     0,     0,     0,    79,     0,     0,     0,   312,
     315,     0,   404,   363,   367,   391,   386,   388,     0,    67,
      66,    65,   235,   271,     0,   276,     0,   402,   361,   364,
     365,   387,   275,   313,   427,   362
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -846,  -846,  -846,  -846,  -846,  -846,   527,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,    85,  -846,   229,  -846,
    -136,  -846,  -846,   106,  -846,  -846,    91,  -846,   230,  -846,
    -135,  -846,  -846,   100,  -846,  -846,  -846,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,   207,
    -846,  -846,  -846,  -846,    69,  -846,  -846,  -846,   -42,  -846,
     390,  -846,  -846,  -846,  -186,  -846,  -846,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,  -150,  -102,  -846,  -281,
    -846,  -846,  -846,  -846,  -846,  -846,    87,  -846,  -846,    80,
    -846,  -846,  -138,  -846,  -846,  -846,  -846,  -846,  -846,   -43,
     -44,  -246,  -846,  -846,   547,  -846,  -846,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,   -11,  -846,  -846,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,
     590,  -846,  -846,    52,  -846,     2,   647,    48,   678,   631,
    -846,   -23,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,
    -846,  -291,  -846,  -846,  -846,  -846,  -584,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,   -14,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,
    -396,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,
    -846,  -664,  -114,   354,  -846,  -288,  -715,   -84,  -235,  -846,
    -846,  -846,  -846,  -195,  -846,  -846,  -846,  -846,  -846,   107,
     -91,  -781,  -846,  -846,   -92,  -846,  -846,  -846,  -846,  -846,
    -240,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,   -27,
    -846,  -846,  -846,  -184,  -846,  -846,   -24,  -846,  -180,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,
    -846,  -846,  -798,  -846,  -846,  -845,   -90,  -846,  -846,  -846,
    -846,  -846,  -846,  -282,   -88,   -15,    26,  -846,   621,  -846,
    -846,  -846,   110,  -846,  -846,   102,  -846,  -846,  -846,   -54,
    -846,  -846,    99,  -846,  -846,  -846,  -339,  -846,  -338,    62,
    -439,  -110,  -846,  -846,   -60,  -846,  -846,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,  -106,  -846,  -846,  -846,  -846,  -846,
    -846,   -79,  -846,  -846,  -846,   -49,  -846,   242,   246,   -41,
    -177,   -12,  -846,  -846
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,    26,     5,     6,     7,    46,    90,
     141,   302,   142,   143,   428,   429,   570,   430,   431,   555,
     556,   699,   796,   557,   795,   432,   572,   433,   434,   565,
     566,   703,   799,   567,   798,   435,   551,   691,   793,   940,
     917,   873,   918,     8,    91,   139,   422,    27,    28,    57,
     460,   461,   598,   821,    82,   128,   129,   478,   479,   276,
     277,   278,   279,    29,   171,    58,   108,    30,    63,    64,
     199,    31,   107,   192,   193,   194,   195,   112,   113,   320,
     321,   458,   596,   714,   322,   584,   585,   459,   589,   590,
     597,   808,   809,   810,   811,   812,   715,   817,   819,   716,
     717,    78,    79,    80,     9,    83,   296,   132,   133,    32,
      33,    93,    94,    34,    53,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,   137,    86,   136,    87,
      88,   299,   420,   116,   117,    99,   100,    59,    74,   103,
     104,   578,   441,   304,   442,   443,   804,   921,   172,   306,
     307,   203,   462,   204,   323,   463,   464,   727,   600,   465,
     602,   603,   728,   729,   730,   825,   731,   822,   885,   946,
     732,   823,   886,   924,   733,   734,   121,   122,   123,   327,
     606,   760,   124,   125,   328,   213,   852,   610,   762,   472,
     558,   735,   826,   888,   736,   737,   831,   950,   966,   927,
     738,   591,   592,   416,   792,   517,   856,   773,   361,   639,
     173,   310,   308,   445,   876,   877,   801,   704,   446,   447,
     439,   574,   803,   705,   575,   466,   605,   604,   746,   842,
     747,   969,   974,   970,   954,   930,   741,   748,   749,   750,
     751,   901,   843,   752,   903,   844,   753,   849,   754,   850,
     957,   936,   906,   851,   755,   756,   836,   952,   929,   893,
     894,   837,   838,   897,   839,   907,   448,   175,   303,   176,
     177,   178,   449,   576,   451,   440,   334,   181,   335,   336,
     615,   480,   337,   617,   481,   338,   339,   490,   491,   340,
     341,   628,   634,   769,   629,   492,   342,   493,   343,   344,
     345,   346,   358,   283,   863,   284,   285,   365,   504,   643,
     286,   496,   635,   772,   347,   657,   288,   783,   784,   348,
     495,   349,   313,   314,   315,   350,   184,   185,   186,   351,
     188,   352,    51,   190
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int SPARQLfedParser::yytable_ninf_ = -428;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        50,   377,    65,    54,    55,    67,   418,    69,   200,    70,
      71,   317,   417,    75,   174,   280,   179,   739,   593,   282,
     191,   607,    60,   287,   608,   182,   201,   450,   293,   437,
     904,   568,  -286,   419,   211,   895,   701,   455,   356,   114,
     698,   316,   311,    66,   697,   359,   414,   813,   109,   105,
     289,    67,   470,   297,   632,   183,   101,  -168,   742,   933,
     827,   899,   742,   187,   105,   862,   106,   105,   743,   833,
      72,     1,   743,   862,   934,     1,   956,    10,  -122,   834,
     290,   111,   744,   145,   111,   935,   744,   794,   291,    66,
     958,   518,   189,   196,   144,   854,   318,   920,   633,   -21,
     719,   720,   855,   698,    11,   206,   915,   174,   438,   179,
      52,   742,    56,   855,    73,   452,    77,   292,   182,   444,
     298,   743,   745,   118,   721,   547,   548,   120,   941,   835,
     180,  -246,   134,   135,    81,   744,    89,   115,   722,   723,
     312,   724,   689,    92,   813,   690,   702,   905,   183,   210,
     593,   202,   436,   967,    95,   281,   187,    47,    48,    49,
      84,    85,    61,    62,   280,   -21,   423,   581,   282,   568,
     609,   745,   287,   582,   131,    47,    48,    49,  -286,   196,
     212,    47,    48,    49,   357,   189,    61,    62,    47,    48,
      49,   360,   415,   975,    61,    62,    47,    48,    49,   289,
      47,    48,    49,  -122,   905,    61,    62,    47,    48,    49,
     761,   896,   -21,    85,   -21,   174,   -21,   179,   146,   725,
     942,   943,    95,   180,   140,    68,   182,   834,   197,   290,
     182,   845,   424,   467,   205,   468,   207,   291,   208,    96,
     726,   -21,   -21,   -21,   182,   209,   890,   300,   846,    47,
      48,    49,   126,   127,   625,   301,   183,   324,   305,   325,
     183,   326,    61,    62,   187,   309,   292,   329,   187,   712,
     713,   110,   593,   847,   183,   797,   702,   835,   319,   425,
     353,   426,   187,   427,   354,   593,   421,   766,   767,   130,
     196,    67,   355,   189,   770,   771,    67,   189,    67,   453,
      47,    48,    49,   362,   281,    61,    62,   363,    47,    48,
      49,   189,   364,   848,    12,   198,    13,    14,   366,    15,
      97,    98,   -72,    47,    48,    49,    16,    17,   367,    66,
     368,   180,   369,   370,    66,   180,    66,   371,   372,    47,
      48,    49,   586,   373,    18,   560,   588,   594,   560,   180,
     626,   627,   777,   374,   471,    47,    48,    49,   375,   376,
     182,   378,   482,   483,   484,   485,   486,   487,   379,   593,
     182,   883,   488,   489,   380,   561,   381,   382,   561,   164,
     165,   166,   167,   562,   383,   384,   562,   385,   386,   765,
     183,   388,   706,   474,   475,   476,   509,   387,   187,   389,
     183,   390,   391,   568,   392,   393,   394,   549,   187,    19,
     395,   396,   563,   397,   398,   563,   399,   400,   401,   402,
      20,    21,   403,   404,    22,   405,    23,   189,   618,   619,
     620,   621,   622,   623,    24,   829,    25,   189,   406,   407,
     408,   409,   410,   411,   292,   292,   413,  -232,   454,   456,
     559,   457,   469,   559,   516,   550,   909,   158,   159,   160,
     161,   162,   163,   427,   477,   180,   573,   579,   577,   424,
     586,   595,   599,   601,   588,   180,   560,   919,   624,   594,
     611,   853,   587,   613,   614,   636,   560,   616,   174,   637,
     179,   638,   644,   640,   641,   645,   647,   642,   648,   182,
     646,   649,   695,   612,   650,   651,   561,   652,   653,   659,
     759,   467,   660,   468,   562,   552,   561,   654,   661,   663,
     662,   664,   182,   665,   562,   666,   667,   560,   668,   183,
     670,   669,   671,   672,   887,   674,   673,   187,   675,   676,
     891,   677,   678,   563,   679,   959,   960,   961,   680,   681,
     682,   684,   183,   563,   683,   685,   686,   561,   908,   552,
     187,   693,   711,   781,   707,   562,   189,    67,   782,   791,
     800,   802,   292,   815,   816,   713,   712,   292,   828,   857,
     858,   559,   859,   860,   861,   865,   864,   880,   855,   189,
     866,   559,    67,   758,   563,   867,   868,   925,   870,   871,
     881,   594,   330,   922,   180,    66,   111,   892,   902,   912,
     587,   913,   914,   926,   594,   900,   928,   937,   939,    12,
     949,    13,    14,   905,    15,   955,   953,   180,   951,   962,
      66,   757,   559,   971,   965,   554,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    47,    48,    49,   696,   963,    61,    62,   294,   569,
     874,   692,   700,   571,   875,   694,   805,   718,   412,   710,
     882,   709,   818,   972,   820,   973,   945,   138,   295,   554,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    47,    48,    49,   594,   292,
      61,    62,   102,    76,   119,   830,   494,   824,   872,   878,
     879,   740,   292,   968,    19,   832,   931,   560,   764,   884,
     560,   841,   932,   182,   763,    20,    21,   768,   869,    22,
     758,    23,   840,   758,   630,   944,   938,   814,   631,    24,
     467,    25,   468,     0,     0,     0,     0,   561,     0,     0,
     561,   182,     0,   183,     0,   562,     0,     0,   562,     0,
       0,   187,     0,   182,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   560,     0,     0,     0,     0,     0,     0,
       0,   183,     0,     0,   563,     0,     0,   563,    67,   187,
     189,     0,     0,   183,   560,     0,   292,     0,     0,   182,
       0,   187,     0,   561,     0,     0,     0,     0,     0,     0,
       0,   562,     0,     0,     0,     0,     0,     0,   189,     0,
       0,   840,   559,   898,   561,   559,    66,     0,   180,   183,
     189,   174,   562,   179,   814,     0,     0,   187,     0,     0,
     563,     0,   182,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   180,     0,     0,     0,
       0,   563,   560,   560,   560,     0,   189,     0,   180,     0,
     923,     0,   183,    67,     0,     0,     0,     0,   559,     0,
     187,     0,     0,     0,     0,     0,     0,     0,   758,     0,
     758,     0,   561,   561,   561,   182,     0,     0,     0,   559,
     562,   562,   562,   -76,   180,     0,     0,     0,     0,   189,
       0,    66,     0,   947,     0,     0,     0,     0,   147,   148,
     149,   150,   151,     0,     0,   183,     0,  -427,     0,   563,
     563,   563,   964,   187,     0,    67,     0,     0,   152,   840,
       0,   758,     0,     0,     0,     0,     0,   180,     0,     0,
       0,   473,   948,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   189,     0,     0,     0,     0,   559,   559,   559,
       0,     0,     0,    66,     0,   497,   498,   499,     0,   757,
     500,     0,     0,   501,   502,   503,     0,   505,   506,   507,
     508,     0,   510,   511,   512,   513,   514,   515,     0,     0,
     180,   519,     0,     0,   520,   521,   522,   523,     0,   524,
       0,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    47,    48,    49,   168,   169,
      61,    62,     0,   170,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     147,   148,   149,   150,   151,     0,     0,     0,     0,  -427,
       0,     0,   806,   807,     0,     0,     0,     0,     0,     0,
     152,     0,     0,     0,     0,     0,   330,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   656,   658,
       0,   216,     0,   217,   218,   219,   220,   221,   222,   223,
     224,     0,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,     0,   236,     0,     0,     0,   687,   688,
       0,     0,     0,     0,     0,   244,     0,     0,     0,     0,
       0,     0,     0,   245,   246,   247,     0,   248,   249,   250,
       0,     0,   251,   252,     0,   253,     0,   254,   255,   256,
     257,     0,   258,   259,   708,   260,     0,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    47,    48,    49,
     168,   169,    61,    62,     0,   170,     0,     0,     0,     0,
       0,     0,     0,     0,    47,    48,    49,   655,     0,    61,
      62,   774,   775,   776,     0,     0,     0,   778,     0,     0,
     779,     0,     0,     0,     0,   780,     0,     0,   330,     0,
       0,     0,   785,   786,     0,     0,     0,     0,     0,     0,
     787,     0,     0,     0,   788,     0,     0,     0,   789,   331,
     332,     0,   333,   216,   790,   217,   218,   219,   220,   221,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,   889,
       0,     0,   215,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   147,   148,   149,
     150,   151,     0,     0,     0,     0,   910,   216,   911,   217,
     218,   219,   220,   221,   222,   223,   224,   152,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,     0,
     236,     0,     0,     0,   237,   238,   239,   240,   241,   242,
     243,   244,   147,   148,   149,   150,   151,     0,     0,   245,
     246,   247,   580,   248,   249,   250,     0,     0,   251,   252,
       0,   253,   152,   254,   255,   256,   257,     0,   258,   259,
       0,   260,     0,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      47,    48,    49,     0,     0,    61,    62,     0,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    47,    48,    49,   168,   169,    61,
      62,     0,   170,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    47,
      48,    49,   168,   169,    61,    62,   330,   170,     0,     0,
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
     274,   275,   916,   552,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   583,     0,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    47,    48,    49,     0,     0,    61,
      62,   216,   552,   217,   218,   219,   220,   221,   222,   223,
     224,     0,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,     0,   236,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   244,     0,     0,     0,     0,
       0,     0,   552,   245,   246,   247,     0,   248,   249,   250,
       0,     0,   251,   252,     0,   253,     0,   254,   255,   256,
     257,     0,   258,   259,     0,   260,   552,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,     0,   554,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    47,
      48,    49,   553,     0,    61,    62,     0,     0,     0,     0,
       0,     0,     0,   564,    47,    48,    49,     0,     0,    61,
      62,     0,   554,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    47,    48,
      49,     0,     0,    61,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   554,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    47,    48,
      49,     0,     0,    61,    62,   330,   554,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    47,    48,    49,     0,     0,    61,    62,     0,
     216,     0,   217,   218,   219,   220,   221,   222,   223,   224,
       0,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,     0,   236,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   244,     0,     0,     0,     0,     0,
       0,     0,   245,   246,   247,     0,   248,   249,   250,     0,
       0,   251,   252,     0,   253,     0,   254,   255,   256,   257,
       0,   258,   259,     0,   260,     0,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47,    48,    49
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        12,   236,    17,    14,    15,    17,   297,    19,   110,    20,
      21,   197,   293,    24,   104,   129,   104,   601,   457,   129,
      23,    37,    19,   129,    40,   104,    36,   309,   130,    50,
      48,   427,    40,    23,    40,   833,    43,   318,    40,     6,
     102,   191,    87,    17,    43,    40,    40,   711,    63,    22,
     129,    63,    41,    39,    19,   104,    54,     0,    40,   904,
     724,   842,    40,   104,    22,   780,    39,    22,    50,    40,
      22,    14,    50,   788,    37,    14,    37,   178,    36,    50,
     129,    39,    64,    95,    39,    48,    64,   149,   129,    63,
     935,   379,   104,   105,    92,    41,   198,   878,    63,    36,
       6,     7,    48,   102,     0,   117,    41,   197,   303,   197,
      12,    40,    36,    48,    36,   310,    30,   129,   197,   305,
     106,    50,   100,    71,    30,   413,   414,    75,    55,   100,
     104,    37,    84,    85,    16,    64,    15,   104,    44,    45,
     185,    47,    37,     9,   808,    40,   153,   165,   197,   123,
     589,   161,   302,   951,     6,   129,   197,   178,   179,   180,
       3,     4,   183,   184,   278,   102,    36,   449,   278,   565,
     186,   100,   278,   454,    49,   178,   179,   180,   186,   191,
     186,   178,   179,   180,   186,   197,   183,   184,   178,   179,
     180,   186,   186,   974,   183,   184,   178,   179,   180,   278,
     178,   179,   180,   161,   165,   183,   184,   178,   179,   180,
     606,    50,   149,     4,   151,   305,   153,   305,    37,   125,
     147,   148,     6,   197,   161,    18,   305,    50,    36,   278,
     309,    19,   102,   323,   110,   323,   110,   278,    37,    23,
     146,   178,   179,   180,   323,   110,   830,   179,    36,   178,
     179,   180,    17,    18,   489,    55,   305,   205,    43,   207,
     309,   209,   183,   184,   305,    40,   278,    36,   309,    28,
      29,    64,   711,    61,   323,   152,   153,   100,    90,   149,
      74,   151,   323,   153,    40,   724,   298,   626,   627,    82,
     302,   303,    40,   305,   632,   633,   308,   309,   310,   311,
     178,   179,   180,    40,   278,   183,   184,    40,   178,   179,
     180,   323,    40,   101,     8,   108,    10,    11,    40,    13,
     104,   105,    16,   178,   179,   180,    20,    21,    40,   303,
      40,   305,    40,    40,   308,   309,   310,    40,    40,   178,
     179,   180,   456,    40,    38,   424,   456,   457,   427,   323,
      61,    62,   643,    40,   328,   178,   179,   180,    40,    40,
     439,    40,    55,    56,    57,    58,    59,    60,    40,   808,
     449,   810,    65,    66,    40,   424,   186,   186,   427,   174,
     175,   176,   177,   424,    40,    40,   427,    40,    40,   624,
     439,    40,   578,   331,   332,   333,   370,   186,   439,   186,
     449,    40,    40,   799,    40,    40,    40,   419,   449,   103,
      40,    40,   424,    40,    40,   427,    40,    40,    40,    40,
     114,   115,    40,    40,   118,    40,   120,   439,   482,   483,
     484,   485,   486,   487,   128,   726,   130,   449,    40,    40,
      40,    40,    40,    40,   456,   457,    40,     6,    37,    25,
     424,    91,    36,   427,    17,   178,   852,   168,   169,   170,
     171,   172,   173,   153,    89,   439,    52,     6,    43,   102,
     584,    24,    37,    43,   584,   449,   555,   873,    66,   589,
      41,   772,   456,    41,    53,    41,   565,    54,   578,    41,
     578,    41,    41,    48,    48,    41,    41,    48,    41,   578,
      48,    48,   153,   477,    41,    41,   555,    41,    41,    41,
      37,   601,    41,   601,   555,    42,   565,    48,    48,    41,
      48,    41,   601,    41,   565,    41,    41,   606,    41,   578,
      41,    48,    41,    41,   825,    41,    48,   578,    41,    41,
     831,    48,    41,   555,    41,   941,   942,   943,    41,    41,
      41,    41,   601,   565,    48,    41,    41,   606,    41,    42,
     601,   102,    25,    41,   579,   606,   578,   579,    49,    41,
      49,    48,   584,   165,   165,    29,    28,   589,    40,    48,
      41,   555,    41,    41,    41,    41,    75,    36,    48,   601,
      41,   565,   604,   605,   606,    41,    41,   888,    41,    41,
      41,   711,    40,   884,   578,   579,    39,    41,    63,    41,
     584,    55,    41,    89,   724,   102,    41,    41,    48,     8,
      46,    10,    11,   165,    13,    37,    49,   601,   102,    37,
     604,   605,   606,    37,    41,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   569,   946,   183,   184,   131,   430,
     796,   555,   571,   433,   799,   565,   708,   598,   278,   589,
     808,   584,   716,   964,   717,   966,   922,    87,   131,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   808,   711,
     183,   184,    55,    25,    73,   728,   352,   721,   792,   800,
     802,   604,   724,   953,   103,   742,   900,   796,   616,   821,
     799,   745,   902,   802,   614,   114,   115,   628,   788,   118,
     742,   120,   744,   745,   492,   921,   913,   711,   492,   128,
     830,   130,   830,    -1,    -1,    -1,    -1,   796,    -1,    -1,
     799,   830,    -1,   802,    -1,   796,    -1,    -1,   799,    -1,
      -1,   802,    -1,   842,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   852,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   830,    -1,    -1,   796,    -1,    -1,   799,   800,   830,
     802,    -1,    -1,   842,   873,    -1,   808,    -1,    -1,   878,
      -1,   842,    -1,   852,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   852,    -1,    -1,    -1,    -1,    -1,    -1,   830,    -1,
      -1,   833,   796,   835,   873,   799,   800,    -1,   802,   878,
     842,   921,   873,   921,   808,    -1,    -1,   878,    -1,    -1,
     852,    -1,   921,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   830,    -1,    -1,    -1,
      -1,   873,   941,   942,   943,    -1,   878,    -1,   842,    -1,
     885,    -1,   921,   885,    -1,    -1,    -1,    -1,   852,    -1,
     921,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   900,    -1,
     902,    -1,   941,   942,   943,   974,    -1,    -1,    -1,   873,
     941,   942,   943,    16,   878,    -1,    -1,    -1,    -1,   921,
      -1,   885,    -1,   924,    -1,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    -1,    -1,   974,    -1,    40,    -1,   941,
     942,   943,   947,   974,    -1,   947,    -1,    -1,    51,   951,
      -1,   953,    -1,    -1,    -1,    -1,    -1,   921,    -1,    -1,
      -1,   330,   926,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   974,    -1,    -1,    -1,    -1,   941,   942,   943,
      -1,    -1,    -1,   947,    -1,   354,   355,   356,    -1,   953,
     359,    -1,    -1,   362,   363,   364,    -1,   366,   367,   368,
     369,    -1,   371,   372,   373,   374,   375,   376,    -1,    -1,
     974,   380,    -1,    -1,   383,   384,   385,   386,    -1,   388,
      -1,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   517,   518,
      -1,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    -1,    -1,    -1,   547,   548,
      -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,   108,   109,    -1,   111,   112,   113,
      -1,    -1,   116,   117,    -1,   119,    -1,   121,   122,   123,
     124,    -1,   126,   127,   583,   129,    -1,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,    -1,   186,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   178,   179,   180,    19,    -1,   183,
     184,   640,   641,   642,    -1,    -1,    -1,   646,    -1,    -1,
     649,    -1,    -1,    -1,    -1,   654,    -1,    -1,    40,    -1,
      -1,    -1,   661,   662,    -1,    -1,    -1,    -1,    -1,    -1,
     669,    -1,    -1,    -1,   673,    -1,    -1,    -1,   677,    61,
      62,    -1,    64,    65,   683,    67,    68,    69,    70,    71,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   828,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,   855,    65,   857,    67,
      68,    69,    70,    71,    72,    73,    74,    51,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    31,    32,    33,    34,    35,    -1,    -1,   107,
     108,   109,    41,   111,   112,   113,    -1,    -1,   116,   117,
      -1,   119,    51,   121,   122,   123,   124,    -1,   126,   127,
      -1,   129,    -1,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,    -1,    -1,   183,   184,    -1,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,    40,   186,    -1,    -1,
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
      84,    85,    86,    -1,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    42,   107,   108,   109,    -1,   111,   112,   113,
      -1,    -1,   116,   117,    -1,   119,    -1,   121,   122,   123,
     124,    -1,   126,   127,    -1,   129,    42,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,    -1,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   102,    -1,   183,   184,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   153,   178,   179,   180,    -1,    -1,   183,
     184,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,    -1,    -1,   183,   184,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,    -1,    -1,   183,   184,    40,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,    -1,    -1,   183,   184,    -1,
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
         0,    14,   188,   189,   190,   192,   193,   194,   230,   291,
     178,     0,     8,    10,    11,    13,    20,    21,    38,   103,
     114,   115,   118,   120,   128,   130,   191,   234,   235,   250,
     254,   258,   296,   297,   300,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   195,   178,   179,   180,
     518,   519,    12,   301,   301,   301,    36,   236,   252,   324,
      19,   183,   184,   255,   256,   462,   463,   518,   236,   518,
     301,   301,   324,    36,   325,   301,   325,    30,   288,   289,
     290,    16,   241,   292,     3,     4,   314,   316,   317,    15,
     196,   231,     9,   298,   299,     6,    23,   104,   105,   322,
     323,   322,   323,   326,   327,    22,    39,   259,   253,   462,
     236,    39,   264,   265,     6,   104,   320,   321,   320,   326,
     320,   363,   364,   365,   369,   370,    17,    18,   242,   243,
     236,    49,   294,   295,   324,   324,   315,   313,   317,   232,
     161,   197,   199,   200,   322,   518,    37,    31,    32,    33,
      34,    35,    51,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   181,   182,
     186,   251,   335,   397,   453,   454,   456,   457,   458,   461,
     463,   464,   508,   512,   513,   514,   515,   516,   517,   518,
     520,    23,   260,   261,   262,   263,   518,    36,   236,   257,
     264,    36,   161,   338,   340,   110,   518,   110,    37,   110,
     463,    40,   186,   372,    19,    40,    65,    67,    68,    69,
      70,    71,    72,    73,    74,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    88,    92,    93,    94,
      95,    96,    97,    98,    99,   107,   108,   109,   111,   112,
     113,   116,   117,   119,   121,   122,   123,   124,   126,   127,
     129,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   246,   247,   248,   249,
     389,   463,   488,   490,   492,   493,   497,   501,   503,   508,
     512,   516,   518,   264,   193,   291,   293,    39,   106,   318,
     179,    55,   198,   455,   330,    43,   336,   337,   399,    40,
     398,    87,   185,   509,   510,   511,   263,   251,   264,    90,
     266,   267,   271,   341,   320,   320,   320,   366,   371,    36,
      40,    61,    62,    64,   463,   465,   466,   469,   472,   473,
     476,   477,   483,   485,   486,   487,   488,   501,   506,   508,
     512,   516,   518,    74,    40,    40,    40,   186,   489,    40,
     186,   395,    40,    40,    40,   494,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,   395,    40,    40,
      40,   186,   186,    40,    40,    40,    40,   186,    40,   186,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,   247,    40,    40,   186,   390,   266,   338,    23,
     319,   518,   233,    36,   102,   149,   151,   153,   201,   202,
     204,   205,   212,   214,   215,   222,   263,    50,   400,   407,
     462,   329,   331,   332,   251,   400,   405,   406,   453,   459,
     460,   461,   400,   518,    37,   266,    25,    91,   268,   274,
     237,   238,   339,   342,   343,   346,   412,   453,   461,    36,
      41,   463,   376,   465,   486,   486,   486,    89,   244,   245,
     468,   471,    55,    56,    57,    58,    59,    60,    65,    66,
     474,   475,   482,   484,   390,   507,   498,   465,   465,   465,
     465,   465,   465,   465,   495,   465,   465,   465,   465,   463,
     465,   465,   465,   465,   465,   465,    17,   392,   392,   465,
     465,   465,   465,   465,   465,   465,   465,   465,   465,   465,
     465,   465,   465,   465,   465,   465,   465,   465,   465,   465,
     465,   465,   465,   465,   465,   465,   465,   392,   392,   518,
     178,   223,    42,   102,   162,   206,   207,   210,   377,   463,
     508,   512,   516,   518,   153,   216,   217,   220,   377,   205,
     203,   215,   213,    52,   408,   411,   460,    43,   328,     6,
      41,   460,   266,    40,   272,   273,   389,   463,   488,   275,
     276,   388,   389,   487,   488,    24,   269,   277,   239,    37,
     345,    43,   347,   348,   414,   413,   367,    37,    40,   186,
     374,    41,   463,    41,    53,   467,    54,   470,   476,   476,
     476,   476,   476,   476,    66,   395,    61,    62,   478,   481,
     514,   515,    19,    63,   479,   499,    41,    41,    41,   396,
      48,    48,    48,   496,    41,    41,    48,    41,    41,    48,
      41,    41,    41,    41,    48,    19,   465,   502,   465,    41,
      41,    48,    48,    41,    41,    41,    41,    41,    41,    48,
      41,    41,    41,    48,    41,    41,    41,    48,    41,    41,
      41,    41,    41,    48,    41,    41,    41,   465,   465,    37,
      40,   224,   210,   102,   220,   153,   203,    43,   102,   208,
     213,    43,   153,   218,   404,   410,   251,   462,   465,   273,
     276,    25,    28,    29,   270,   283,   286,   287,   241,     6,
       7,    30,    44,    45,    47,   125,   146,   344,   349,   350,
     351,   353,   357,   361,   362,   378,   381,   382,   387,   343,
     406,   423,    40,    50,    64,   100,   415,   417,   424,   425,
     426,   427,   430,   433,   435,   441,   442,   463,   518,    37,
     368,   377,   375,   469,   472,   395,   483,   483,   479,   480,
     485,   485,   500,   394,   465,   465,   465,   338,   465,   465,
     465,    41,    49,   504,   505,   465,   465,   465,   465,   465,
     465,    41,   391,   225,   149,   211,   209,   152,   221,   219,
      49,   403,    48,   409,   333,   245,    26,    27,   278,   279,
     280,   281,   282,   388,   463,   165,   165,   284,   287,   285,
     286,   240,   354,   358,   363,   352,   379,   388,    40,   338,
     328,   383,   426,    40,    50,   100,   443,   448,   449,   451,
     518,   433,   416,   429,   432,    19,    36,    61,   101,   434,
     436,   440,   373,   338,    41,    48,   393,    48,    41,    41,
      41,    41,   393,   491,    75,    41,    41,    41,    41,   491,
      41,    41,   394,   228,   207,   217,   401,   402,   407,   411,
      36,    41,   279,   487,   264,   355,   359,   338,   380,   465,
     343,   338,    41,   446,   447,   449,    50,   450,   518,   408,
     102,   428,    63,   431,    48,   165,   439,   452,    41,   377,
     465,   465,    41,    55,    41,    41,    41,   227,   229,   377,
     408,   334,   266,   462,   360,   338,    89,   386,    41,   445,
     422,   430,   435,   452,    37,    48,   438,    41,   517,    48,
     226,    55,   147,   148,   251,   288,   356,   301,   463,    46,
     384,   102,   444,    49,   421,    37,    37,   437,   452,   377,
     377,   377,    37,   338,   462,    41,   385,   449,   417,   418,
     420,    37,   338,   338,   419,   408
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
     249,   250,   251,   251,   253,   252,   252,   254,   255,   255,
     256,   256,   257,   257,   258,   259,   260,   260,   261,   262,
     263,   264,   265,   265,   266,   267,   267,   268,   268,   269,
     269,   270,   270,   271,   272,   272,   273,   273,   273,   273,
     274,   275,   275,   276,   277,   278,   278,   279,   279,   280,
     280,   281,   282,   282,   283,   283,   284,   284,   285,   285,
     286,   287,   288,   289,   290,   290,   292,   291,   293,   293,
     294,   295,   295,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   297,   298,   299,   299,   300,   301,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   312,   313,   313,   314,   314,   315,   315,   316,
     317,   318,   319,   319,   320,   320,   321,   321,   322,   323,
     323,   323,   323,   324,   325,   327,   326,   328,   328,   329,
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
       1,     2,     0,     1,     0,     5,     6,     5,     1,     2,
       1,     1,     0,     1,     3,     2,     1,     1,     1,     2,
       1,     2,     0,     1,     4,     0,     1,     0,     1,     0,
       1,     0,     1,     3,     1,     2,     1,     1,     4,     1,
       2,     1,     2,     1,     3,     1,     2,     1,     1,     1,
       1,     2,     1,     1,     2,     2,     0,     1,     0,     1,
       2,     2,     1,     2,     0,     1,     0,     4,     0,     1,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     0,     1,     3,     0,
       1,     3,     3,     5,     5,     5,     2,     2,     2,     5,
       2,     0,     1,     0,     1,     2,     1,     0,     2,     2,
       2,     2,     1,     2,     1,     2,     0,     1,     2,     1,
       1,     1,     1,     3,     3,     0,     3,     0,     1,     3,
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
  "ConstructQuery", "_QTriplesTemplate_E_Opt",
  "_O_QQuadPattern_E_S_QDatasetClause_E_Star_S_QWhereClause_E_S_QSolutionModifier_E_Or_QDatasetClause_E_Star_S_QIT_WHERE_E_S_QGT_LCURLEY_E_S_QTriplesTemplate_E_Opt_S_QGT_RCURLEY_E_S_QSolutionModifier_E_C",
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
  "Quads", "$@13", "_QGT_DOT_E_Opt",
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
     191,   288,    -1,   234,    -1,   250,    -1,   254,    -1,   258,
      -1,   291,    -1,   194,   195,   196,    -1,    -1,   230,    -1,
      -1,   195,   231,    -1,    -1,   196,   197,    -1,    -1,   200,
     198,   201,    -1,   161,    55,    -1,    -1,   199,    -1,   202,
      -1,   212,    -1,   222,    -1,   263,    -1,   204,   205,   203,
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
     241,   236,   264,   266,    -1,    -1,   236,   259,    -1,    -1,
      -1,    -1,   238,   239,   241,   240,   264,   266,   288,    -1,
      16,   243,   249,    -1,    17,    -1,    18,    -1,    -1,   242,
      -1,    89,   463,    -1,    -1,   244,    -1,    40,   465,   245,
      41,    -1,   488,    -1,   508,    -1,   512,    -1,   516,    -1,
     463,    -1,   501,    -1,   389,    -1,   246,    -1,   247,    -1,
     248,   247,    -1,   248,    -1,    19,    -1,    20,   252,    -1,
      -1,   335,    -1,    -1,   324,   253,   236,   264,   266,    -1,
     236,    39,    36,   251,    37,   266,    -1,    21,   256,   236,
     257,   266,    -1,   462,    -1,   255,   462,    -1,   255,    -1,
      19,    -1,    -1,   264,    -1,    38,   236,   264,    -1,    22,
     260,    -1,   261,    -1,   262,    -1,   263,    -1,    23,   263,
      -1,   518,    -1,   265,   338,    -1,    -1,    39,    -1,   267,
     268,   269,   270,    -1,    -1,   271,    -1,    -1,   274,    -1,
      -1,   277,    -1,    -1,   283,    -1,    90,    25,   272,    -1,
     273,    -1,   272,   273,    -1,   488,    -1,   389,    -1,    40,
     465,   245,    41,    -1,   463,    -1,    91,   275,    -1,   276,
      -1,   275,   276,    -1,   388,    -1,    24,    25,   278,    -1,
     279,    -1,   278,   279,    -1,   281,    -1,   282,    -1,    26,
      -1,    27,    -1,   280,   487,    -1,   388,    -1,   463,    -1,
     286,   284,    -1,   287,   285,    -1,    -1,   287,    -1,    -1,
     286,    -1,    28,   165,    -1,    29,   165,    -1,   290,    -1,
      30,   363,    -1,    -1,   289,    -1,    -1,   193,   296,   292,
     295,    -1,    -1,   291,    -1,    49,   293,    -1,    -1,   294,
      -1,   297,    -1,   300,    -1,   302,    -1,   304,    -1,   305,
      -1,   306,    -1,   303,    -1,   307,    -1,   308,    -1,   309,
      -1,   310,    -1,     8,   518,   299,    -1,     9,   322,    -1,
      -1,   298,    -1,    10,   301,   323,    -1,    -1,    12,    -1,
      13,   301,   323,    -1,    11,   301,   322,    -1,   114,   301,
     320,   110,   320,    -1,   128,   301,   320,   110,   320,    -1,
     115,   301,   320,   110,   320,    -1,   130,   325,    -1,   120,
     325,    -1,   118,   324,    -1,   312,   314,   315,    39,   338,
      -1,   103,   518,    -1,    -1,   311,    -1,    -1,   317,    -1,
     316,   313,    -1,   317,    -1,    -1,   315,   318,    -1,     3,
     324,    -1,     4,   324,    -1,   106,   319,    -1,   518,    -1,
      23,   518,    -1,   104,    -1,   321,   518,    -1,    -1,     6,
      -1,     6,   518,    -1,   322,    -1,   104,    -1,    23,    -1,
     105,    -1,    36,   326,    37,    -1,    36,   326,    37,    -1,
      -1,   327,   251,   330,    -1,    -1,    43,    -1,   331,   328,
     251,    -1,    -1,   330,   329,    -1,    -1,    -1,    -1,   332,
       6,   462,   333,    36,   334,   251,    37,    -1,   397,   337,
      -1,    43,   251,    -1,    -1,   336,    -1,   340,    -1,   161,
      -1,   237,    -1,   342,    -1,    -1,    36,   341,   339,    37,
      -1,   343,   345,    -1,    -1,   346,    -1,   349,   328,   343,
      -1,    -1,   345,   344,    -1,   412,   348,    -1,    43,   343,
      -1,    -1,   347,    -1,   381,    -1,   351,    -1,   378,    -1,
     353,    -1,   357,    -1,   387,    -1,   361,    -1,   362,    -1,
     350,    -1,   146,   338,    -1,    -1,    44,   352,   338,    -1,
      -1,    -1,    -1,     6,   354,   355,   462,   356,   338,    -1,
      -1,    -1,    -1,     7,   358,   359,   360,   301,   462,   338,
      -1,   125,    40,   465,    89,   463,    41,    -1,    30,   363,
      -1,   364,    -1,   369,    -1,    -1,    -1,   365,   463,   366,
      36,   367,    37,    -1,    -1,   367,   368,    -1,   377,    -1,
      -1,   370,   372,    36,   376,    37,    -1,    -1,   371,   463,
      -1,   186,    -1,    40,   371,    41,    -1,    -1,   373,   377,
      -1,    -1,    40,   375,   373,    41,    -1,   186,    -1,    -1,
     376,   374,    -1,   518,    -1,   508,    -1,   512,    -1,   516,
      -1,    42,    -1,   162,    -1,   463,    -1,    -1,    -1,    45,
     379,   380,   338,    -1,    -1,    -1,   382,   383,   338,   386,
      -1,    -1,    46,   385,   338,    -1,    -1,   386,   384,    -1,
      47,   388,    -1,   487,    -1,   488,    -1,   389,    -1,   518,
     390,    -1,   186,    -1,    -1,    40,   392,   465,   391,   394,
      41,    -1,    -1,    17,    -1,    48,   465,    -1,    -1,   394,
     393,    -1,   186,    -1,    -1,    40,   465,   396,   394,    41,
      -1,    -1,   461,   398,   400,    -1,    -1,   453,   399,   405,
      -1,   407,   408,   404,    -1,   407,   408,    -1,    -1,   401,
      -1,    49,   402,    -1,    -1,   404,   403,    -1,   406,    -1,
      -1,   400,    -1,   462,    -1,    50,    -1,   411,   410,    -1,
      48,   411,    -1,    -1,   410,   409,    -1,   460,    -1,    -1,
     461,   413,   415,    -1,    -1,   453,   414,   423,    -1,    -1,
     417,   416,   408,   422,    -1,   424,    -1,   425,    -1,    -1,
     417,   419,   408,    -1,    -1,   418,    -1,    49,   420,    -1,
      -1,   422,   421,    -1,   406,    -1,   426,    -1,   463,    -1,
     427,    -1,   430,   429,    -1,   102,   430,    -1,    -1,   429,
     428,    -1,   435,   432,    -1,    63,   435,    -1,    -1,   432,
     431,    -1,   441,   434,    -1,    -1,   436,    -1,   433,    -1,
     100,   433,    -1,   440,    -1,    37,    -1,   452,    37,    -1,
      48,   437,    -1,    37,    -1,   452,   438,    -1,    48,   452,
      37,    -1,    19,    -1,   101,    -1,    61,    -1,    36,   439,
      -1,   442,    -1,   518,    -1,    50,    -1,    64,   443,    -1,
      40,   426,    41,    -1,   448,    -1,   102,   449,    -1,    -1,
     445,   444,    -1,   449,   445,    -1,    -1,   446,    -1,   449,
      -1,    40,   447,    41,    -1,   451,    -1,   518,    -1,    50,
      -1,   518,    -1,    50,    -1,   100,   450,    -1,   165,    -1,
     456,    -1,   454,    -1,    -1,    51,   455,   400,    52,    -1,
     458,    40,   459,    41,    -1,    31,    -1,    32,    -1,    33,
      -1,    34,    -1,    35,    -1,    -1,   457,    -1,   460,    -1,
     459,   460,    -1,   461,    -1,   453,    -1,   463,    -1,   464,
      -1,   463,    -1,   518,    -1,   183,    -1,   184,    -1,   518,
      -1,   508,    -1,   512,    -1,   516,    -1,   520,    -1,   186,
      -1,   466,    -1,   469,   468,    -1,    53,   469,    -1,    -1,
     468,   467,    -1,   472,   471,    -1,    54,   472,    -1,    -1,
     471,   470,    -1,   473,    -1,   476,   474,    -1,    -1,   475,
      -1,    55,   476,    -1,    56,   476,    -1,    57,   476,    -1,
      58,   476,    -1,    59,   476,    -1,    60,   476,    -1,    66,
     395,    -1,    65,    66,   395,    -1,   477,    -1,   483,   482,
      -1,   514,    -1,   515,    -1,    19,   485,    -1,    63,   485,
      -1,    -1,   479,    -1,    61,   483,    -1,    62,   483,    -1,
     478,   480,    -1,    -1,   482,   481,    -1,   485,   484,    -1,
      -1,   484,   479,    -1,    64,   486,    -1,    61,   486,    -1,
      62,   486,    -1,   486,    -1,   487,    -1,   488,    -1,   506,
      -1,   508,    -1,   512,    -1,   516,    -1,   463,    -1,   501,
      -1,    40,   465,    41,    -1,    76,    40,   465,    41,    -1,
      77,    40,   465,    41,    -1,    78,    40,   465,    48,   465,
      41,    -1,    79,    40,   465,    41,    -1,    80,    40,   463,
      41,    -1,    67,    40,   465,    41,    -1,    68,    40,   465,
      41,    -1,    69,   489,    -1,   116,   186,    -1,   140,    40,
     465,    41,    -1,   137,    40,   465,    41,    -1,   129,    40,
     465,    41,    -1,   123,    40,   465,    41,    -1,    88,   395,
      -1,   492,    -1,   143,    40,   465,    41,    -1,   141,    40,
     465,    41,    -1,   139,    40,   465,    41,    -1,   135,    40,
     465,    41,    -1,   126,    40,   465,    48,   465,    41,    -1,
     136,    40,   465,    48,   465,    41,    -1,   142,    40,   465,
      48,   465,    41,    -1,   111,    40,   465,    48,   465,    41,
      -1,   112,    40,   465,    48,   465,    41,    -1,   113,    40,
     465,    41,    -1,   145,    40,   465,    41,    -1,   138,    40,
     465,    41,    -1,   134,    40,   465,    41,    -1,   131,    40,
     465,    41,    -1,   127,    40,   465,    41,    -1,   122,    40,
     465,    41,    -1,   121,    40,   465,    41,    -1,   119,   186,
      -1,   107,   186,    -1,   108,   186,    -1,   109,    40,   465,
      41,    -1,   144,    40,   465,    41,    -1,   133,    40,   465,
      41,    -1,   124,    40,   465,    41,    -1,   117,    40,   465,
      41,    -1,    70,   395,    -1,    71,    40,   465,    48,   465,
      48,   465,    41,    -1,    72,    40,   465,    48,   465,    41,
      -1,    73,    40,   465,    48,   465,    41,    -1,    81,    40,
     465,    48,   465,    41,    -1,    82,    40,   465,    41,    -1,
      83,    40,   465,    41,    -1,    84,    40,   465,    41,    -1,
      85,    40,   465,    41,    -1,    99,    40,   465,    41,    -1,
     490,    -1,   493,    -1,   497,    -1,    40,   465,    41,    -1,
     186,    -1,    86,    40,   465,    48,   465,   491,    41,    -1,
      -1,   393,    -1,   132,    40,   465,    48,   465,   491,    41,
      -1,    -1,    -1,    -1,    74,   494,   495,   496,   338,    -1,
      -1,    -1,    -1,    65,    74,   498,   499,   500,   338,    -1,
      92,    40,   392,   502,    41,    -1,   503,    40,   392,   465,
      41,    -1,    97,    40,   392,   465,   505,    41,    -1,    19,
      -1,   465,    -1,    93,    -1,    94,    -1,    95,    -1,    96,
      -1,    98,    -1,    49,    75,    55,   517,    -1,    -1,   504,
      -1,   518,   507,    -1,    -1,   390,    -1,   517,   511,    -1,
      87,   518,    -1,   185,    -1,   509,    -1,    -1,   510,    -1,
     513,    -1,   514,    -1,   515,    -1,   165,    -1,   166,    -1,
     167,    -1,   168,    -1,   169,    -1,   170,    -1,   171,    -1,
     172,    -1,   173,    -1,   163,    -1,   164,    -1,   174,    -1,
     176,    -1,   175,    -1,   177,    -1,   178,    -1,   519,    -1,
     180,    -1,   179,    -1,   181,    -1,   182,    -1
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
     245,   247,   250,   251,   253,   254,   260,   267,   273,   275,
     278,   280,   282,   283,   285,   289,   292,   294,   296,   298,
     301,   303,   306,   307,   309,   314,   315,   317,   318,   320,
     321,   323,   324,   326,   330,   332,   335,   337,   339,   344,
     346,   349,   351,   354,   356,   360,   362,   365,   367,   369,
     371,   373,   376,   378,   380,   383,   386,   387,   389,   390,
     392,   395,   398,   400,   403,   404,   406,   407,   412,   413,
     415,   418,   419,   421,   423,   425,   427,   429,   431,   433,
     435,   437,   439,   441,   443,   447,   450,   451,   453,   457,
     458,   460,   464,   468,   474,   480,   486,   489,   492,   495,
     501,   504,   505,   507,   508,   510,   513,   515,   516,   519,
     522,   525,   528,   530,   533,   535,   538,   539,   541,   544,
     546,   548,   550,   552,   556,   560,   561,   565,   566,   568,
     572,   573,   576,   577,   578,   579,   588,   591,   594,   595,
     597,   599,   601,   603,   605,   606,   611,   614,   615,   617,
     621,   622,   625,   628,   631,   632,   634,   636,   638,   640,
     642,   644,   646,   648,   650,   652,   655,   656,   660,   661,
     662,   663,   670,   671,   672,   673,   681,   688,   691,   693,
     695,   696,   697,   704,   705,   708,   710,   711,   717,   718,
     721,   723,   727,   728,   731,   732,   737,   739,   740,   743,
     745,   747,   749,   751,   753,   755,   757,   758,   759,   764,
     765,   766,   771,   772,   776,   777,   780,   783,   785,   787,
     789,   792,   794,   795,   802,   803,   805,   808,   809,   812,
     814,   815,   821,   822,   826,   827,   831,   835,   838,   839,
     841,   844,   845,   848,   850,   851,   853,   855,   857,   860,
     863,   864,   867,   869,   870,   874,   875,   879,   880,   885,
     887,   889,   890,   894,   895,   897,   900,   901,   904,   906,
     908,   910,   912,   915,   918,   919,   922,   925,   928,   929,
     932,   935,   936,   938,   940,   943,   945,   947,   950,   953,
     955,   958,   962,   964,   966,   968,   971,   973,   975,   977,
     980,   984,   986,   989,   990,   993,   996,   997,   999,  1001,
    1005,  1007,  1009,  1011,  1013,  1015,  1018,  1020,  1022,  1024,
    1025,  1030,  1035,  1037,  1039,  1041,  1043,  1045,  1046,  1048,
    1050,  1053,  1055,  1057,  1059,  1061,  1063,  1065,  1067,  1069,
    1071,  1073,  1075,  1077,  1079,  1081,  1083,  1086,  1089,  1090,
    1093,  1096,  1099,  1100,  1103,  1105,  1108,  1109,  1111,  1114,
    1117,  1120,  1123,  1126,  1129,  1132,  1136,  1138,  1141,  1143,
    1145,  1148,  1151,  1152,  1154,  1157,  1160,  1163,  1164,  1167,
    1170,  1171,  1174,  1177,  1180,  1183,  1185,  1187,  1189,  1191,
    1193,  1195,  1197,  1199,  1201,  1205,  1210,  1215,  1222,  1227,
    1232,  1237,  1242,  1245,  1248,  1253,  1258,  1263,  1268,  1271,
    1273,  1278,  1283,  1288,  1293,  1300,  1307,  1314,  1321,  1328,
    1333,  1338,  1343,  1348,  1353,  1358,  1363,  1368,  1371,  1374,
    1377,  1382,  1387,  1392,  1397,  1402,  1405,  1414,  1421,  1428,
    1435,  1440,  1445,  1450,  1455,  1460,  1462,  1464,  1466,  1470,
    1472,  1480,  1481,  1483,  1491,  1492,  1493,  1494,  1500,  1501,
    1502,  1503,  1510,  1516,  1522,  1529,  1531,  1533,  1535,  1537,
    1539,  1541,  1543,  1548,  1549,  1551,  1554,  1555,  1557,  1560,
    1563,  1565,  1567,  1568,  1570,  1572,  1574,  1576,  1578,  1580,
    1582,  1584,  1586,  1588,  1590,  1592,  1594,  1596,  1598,  1600,
    1602,  1604,  1606,  1608,  1610,  1612,  1614,  1616
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
     864,   870,   875,   877,   881,   881,   888,   899,   907,   910,
     918,   921,   928,   931,   936,   944,   951,   952,   956,   962,
     968,   975,   982,   984,   989,   996,   999,  1004,  1007,  1012,
    1015,  1020,  1024,  1028,  1035,  1038,  1045,  1048,  1051,  1054,
    1060,  1066,  1069,  1076,  1081,  1088,  1092,  1100,  1102,  1110,
    1113,  1121,  1129,  1130,  1137,  1141,  1149,  1152,  1157,  1160,
    1164,  1170,  1176,  1180,  1186,  1189,  1193,  1193,  1202,  1204,
    1208,  1211,  1213,  1217,  1218,  1219,  1220,  1221,  1222,  1223,
    1224,  1225,  1226,  1227,  1231,  1238,  1245,  1248,  1252,  1258,
    1261,  1267,  1273,  1279,  1285,  1291,  1297,  1305,  1313,  1320,
    1329,  1335,  1338,  1342,  1345,  1349,  1353,  1359,  1361,  1367,
    1373,  1379,  1385,  1388,  1394,  1397,  1402,  1404,  1408,  1414,
    1417,  1420,  1423,  1430,  1436,  1442,  1442,  1451,  1453,  1457,
    1460,  1462,  1467,  1472,  1475,  1467,  1486,  1490,  1493,  1495,
    1499,  1500,  1513,  1514,  1519,  1519,  1530,  1534,  1536,  1546,
    1550,  1553,  1569,  1574,  1578,  1581,  1585,  1586,  1587,  1588,
    1589,  1590,  1591,  1592,  1595,  1599,  1605,  1605,  1621,  1625,
    1627,  1621,  1638,  1642,  1644,  1638,  1655,  1666,  1672,  1673,
    1677,  1679,  1677,  1686,  1688,  1692,  1700,  1700,  1707,  1709,
    1715,  1716,  1719,  1721,  1727,  1727,  1732,  1738,  1740,  1744,
    1747,  1750,  1753,  1756,  1759,  1762,  1768,  1772,  1768,  1782,
    1786,  1782,  1796,  1796,  1808,  1810,  1814,  1824,  1825,  1826,
    1830,  1838,  1842,  1842,  1852,  1855,  1862,  1868,  1870,  1884,
    1887,  1887,  1897,  1897,  1900,  1900,  1907,  1912,  1916,  1918,
    1923,  1927,  1929,  1934,  1938,  1940,  1944,  1948,  1956,  1961,
    1965,  1967,  1971,  1979,  1979,  1982,  1982,  1988,  1988,  1994,
    1995,  1999,  1999,  2004,  2006,  2010,  2013,  2015,  2019,  2023,
    2027,  2033,  2037,  2041,  2044,  2046,  2050,  2054,  2059,  2061,
    2067,  2070,  2072,  2078,  2079,  2085,  2089,  2090,  2094,  2095,
    2099,  2100,  2104,  2105,  2106,  2107,  2111,  2115,  2118,  2121,
    2124,  2130,  2134,  2137,  2139,  2143,  2146,  2148,  2152,  2153,
    2157,  2161,  2162,  2166,  2167,  2168,  2172,  2177,  2178,  2182,
    2182,  2195,  2222,  2225,  2228,  2231,  2234,  2241,  2244,  2249,
    2253,  2260,  2261,  2265,  2268,  2272,  2275,  2281,  2282,  2286,
    2289,  2292,  2295,  2298,  2299,  2305,  2310,  2319,  2326,  2329,
    2337,  2346,  2353,  2356,  2363,  2368,  2381,  2385,  2389,  2393,
    2397,  2401,  2405,  2409,  2413,  2417,  2424,  2429,  2438,  2441,
    2448,  2451,  2458,  2461,  2466,  2469,  2473,  2487,  2490,  2498,
    2507,  2510,  2517,  2520,  2523,  2526,  2530,  2531,  2532,  2533,
    2536,  2539,  2542,  2545,  2549,  2555,  2558,  2561,  2564,  2567,
    2570,  2573,  2577,  2580,  2583,  2586,  2589,  2592,  2595,  2598,
    2599,  2602,  2605,  2608,  2611,  2614,  2617,  2620,  2623,  2626,
    2629,  2632,  2635,  2638,  2641,  2644,  2647,  2650,  2653,  2656,
    2659,  2662,  2665,  2668,  2671,  2674,  2677,  2680,  2683,  2686,
    2689,  2692,  2695,  2698,  2701,  2704,  2705,  2706,  2712,  2715,
    2722,  2729,  2732,  2736,  2742,  2745,  2748,  2742,  2761,  2764,
    2767,  2761,  2781,  2785,  2790,  2799,  2802,  2806,  2809,  2812,
    2815,  2818,  2824,  2830,  2833,  2837,  2847,  2850,  2855,  2863,
    2870,  2874,  2882,  2886,  2890,  2891,  2892,  2896,  2897,  2898,
    2902,  2903,  2904,  2908,  2909,  2910,  2914,  2915,  2919,  2920,
    2921,  2922,  2926,  2927,  2931,  2932,  2936,  2937
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
  const int SPARQLfedParser::yylast_ = 2375;
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
#line 5759 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 2943 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


