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
#line 312 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"

/* Line 299 of lalr1.cc  */
#line 464 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

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
#line 478 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 481 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 492 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 536 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.startBindingSet();
      }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 539 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 554 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = (yysemantic_stack_[(2) - (1)].p_RSName);
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 560 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = NULL;
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 570 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	throw std::runtime_error("need to partition out results set part of SimpleEngine::loadDataOrResults");
    }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 604 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 606 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 612 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 650 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 652 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 658 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 677 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow(false);
      }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 679 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 699 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 702 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 705 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 711 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 717 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 719 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 721 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 729 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 732 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause);
	(yyval.p_Operation) = new Select((yysemantic_stack_[(5) - (2)].p_Project).distinctness, (yysemantic_stack_[(5) - (2)].p_Project).varSet, (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
	driver.countStar = (yysemantic_stack_[(5) - (1)].p_parentCountStar);
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 741 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 744 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 752 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 755 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 758 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 762 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 773 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 781 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 784 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 791 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 799 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 806 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 814 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 821 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 824 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 827 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 830 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 833 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 836 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 839 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 848 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 851 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 859 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 862 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 869 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = NULL;
      }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 871 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.lastWhereClause = (yysemantic_stack_[(6) - (5)].p_WhereClause);
	  /* $2 is NO LONGER known to be a DefaultGraphPattern because of grammar restrictions. */
	  (yyval.p_Operation) = new Construct((yysemantic_stack_[(6) - (2)].p_TableOperation), (yysemantic_stack_[(6) - (4)].p_DatasetClauses), (yysemantic_stack_[(6) - (5)].p_WhereClause), (yysemantic_stack_[(6) - (6)].p_SolutionModifier));
      }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 880 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause) ? (yysemantic_stack_[(5) - (4)].p_WhereClause) : new WhereClause(new DefaultGraphPattern());
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 888 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm))));
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 891 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_TTerm))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 899 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 902 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 909 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 917 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(3) - (3)].p_WhereClause);
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(3) - (2)].p_DatasetClauses), (yysemantic_stack_[(3) - (3)].p_WhereClause));
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 925 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 937 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 943 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 949 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 956 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.ensureGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 970 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 977 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 985 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 993 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1001 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1009 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1016 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1019 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1026 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1029 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1032 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1035 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1041 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1047 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1050 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1062 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1069 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1073 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1083 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1091 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1094 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1102 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1111 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1118 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1122 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1130 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1138 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1145 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1151 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1161 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = (yysemantic_stack_[(2) - (2)].p_BindingClause);
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1167 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1174 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	OperationSet* ret = driver.root ? dynamic_cast<OperationSet*>(driver.root) : new OperationSet();
	ret->push_back((yysemantic_stack_[(2) - (2)].p_Operation));
	driver.root = ret;
      }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1178 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Operation) = driver.root;
	}
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 1212 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(3) - (2)].p_URI), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 1219 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1226 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1233 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1239 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1242 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1248 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1254 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1260 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1266 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1272 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1278 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1286 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1294 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1301 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(5) - (1)].p_URI))
	    w3c_sw_NEED_IMPL("WITH <URI> (DELETE INSERT?|INSERT) ...");
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(5) - (2)].p_DeleteInsert).del, (yysemantic_stack_[(5) - (2)].p_DeleteInsert).ins, new WhereClause(driver.ensureGraphPattern()));
	driver.curOp = NULL;
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1310 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1316 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1323 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1330 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1334 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1342 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("_QUsingClause_E_Star");
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 1348 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Delete) = new Delete((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1354 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = new Insert((yysemantic_stack_[(2) - (2)].p_TableOperation), NULL);
    }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1360 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1366 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1369 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1375 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1378 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 1389 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 1395 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 1398 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("DEFAULT");
      }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 1401 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("NAMED");
      }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 1404 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("ALL");
      }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 1411 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
    }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1417 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
    }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 1423 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1425 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TableOperation) = driver.ensureGraphPattern();
	  driver.curOp = NULL;
      }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 1453 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 1458 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 1461 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 1464 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 1486 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 242:

/* Line 690 of lalr1.cc  */
#line 1505 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 1507 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 1578 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_BindingClause)) : (yysemantic_stack_[(1) - (1)].p_BindingClause);
    }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 1585 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Print(driver.curOp);
    }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 1591 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 1595 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 266:

/* Line 690 of lalr1.cc  */
#line 1607 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 1611 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 1613 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 1616 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 1624 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 1628 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 1630 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 1633 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(7) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(7) - (6)].p_TTerm), driver.curOp, (yysemantic_stack_[(7) - (5)].p_Silence), driver.atomFactory, false));
	  driver.curGraphName = (yysemantic_stack_[(7) - (4)].p_TTerm);
      }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 1641 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Bind(driver.ensureGraphPattern(), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
	// no more triples go into the current BGP, per
	//   http://www.w3.org/TR/sparql11-query/#sparqlTranslateGraphPatterns
	// test reference:
	//   http://www.sparql.org/query-validator?query=ASK+{+%3Fs+%3Fp+%3Fo+FILTER+%281%29+BIND+%282+AS+%3Fb%29+%3Fs2+%3Fp2+%3Fo2+FILTER+%283%29+BIND+%284+AS+%3Fd%29}&languageSyntax=SPARQL&outputFormat=algebra&linenumbers=false
	driver.curBGP = NULL;
    }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 1652 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = (yysemantic_stack_[(2) - (2)].p_BindingClause);
    }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 1663 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 1665 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
      }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 1667 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 1678 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
	driver.endBindingRow();
    }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 1686 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
    }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 1688 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 1695 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 1707 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 1713 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 1715 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 1718 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 1730 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 1733 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 1736 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 1739 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 1742 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 1745 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 1748 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 1754 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 1758 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 1760 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 1768 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 1772 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 1774 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 1782 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 1787 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.ensureGraphPattern());
      }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 1800 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    driver.ensureGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 1816 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 1824 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 1828 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 1831 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yysemantic_stack_[(6) - (4)].p_Expressions);
      }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 1838 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 1841 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 1848 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 1856 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 1870 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 1873 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 1876 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(5) - (3)].p_Expressions);
      }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 1883 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 1886 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 1930 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 1934 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 1957 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 1965 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 1968 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 1974 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 1985 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 368:

/* Line 690 of lalr1.cc  */
#line 2013 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 2040 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 2047 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 2058 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 2065 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 2101 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 2104 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 2107 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 2110 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 2168 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 2172 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 2181 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 420:

/* Line 690 of lalr1.cc  */
#line 2208 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 2211 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 2214 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 2217 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 2220 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 2227 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 2235 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 2239 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 2251 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 2258 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 2261 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 2272 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 2275 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 2278 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 2281 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 2285 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 2296 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 2305 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 2312 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 2315 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 2323 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 2332 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 2339 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 2342 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 2354 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 454:

/* Line 690 of lalr1.cc  */
#line 2367 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = NULL;
    }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 2375 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 2379 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 2383 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 2387 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 2391 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 2395 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 2399 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 2403 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = true;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 2415 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 2424 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 2427 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 2434 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 2437 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 2444 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 2452 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 2455 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 2459 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 475:

/* Line 690 of lalr1.cc  */
#line 2473 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 2476 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 2484 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 2493 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 2496 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 2503 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 2506 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 2509 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 2519 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 2522 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 2525 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 2528 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 2535 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 2541 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 2544 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 2547 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 2550 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 2553 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 2556 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 2559 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 2563 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 2566 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 2569 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 2572 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ceil, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 2575 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 2578 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 2581 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 2585 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 2588 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 2591 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 2594 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 2597 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 2600 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 2603 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 2606 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 2609 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 2612 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 2615 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 2618 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 2621 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 2624 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 2627 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 2630 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 2633 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 2636 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 2639 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_uuid, NULL, NULL, NULL));
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 2642 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_struuid, NULL, NULL, NULL));
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 2645 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 2648 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 2651 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 2654 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 2657 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 2660 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 2663 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 2666 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 2669 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 2672 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 2675 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 2678 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 2681 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 2684 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 2687 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 2698 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 2701 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 2708 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 2715 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 2722 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 2728 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 2731 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 2734 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 2738 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expression) = new ExistsExpression(driver.ensureGraphPattern());
	  driver.curOp = (yysemantic_stack_[(5) - (4)].p_TableOperation);
	  driver.curGraphName = (yysemantic_stack_[(5) - (3)].p_TTerm);
	  driver.countStar = (yysemantic_stack_[(5) - (2)].p_parentCountStar);
      }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 2747 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 2750 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 2753 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 2757 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  // $$ = new ExistsExpression(false, driver.ensureGraphPattern());
	  (yyval.p_Expression) = new BooleanNegation(new ExistsExpression(driver.ensureGraphPattern()));
	  driver.curOp = (yysemantic_stack_[(6) - (5)].p_TableOperation);
	  driver.curGraphName = (yysemantic_stack_[(6) - (4)].p_TTerm);
	  driver.countStar = (yysemantic_stack_[(6) - (3)].p_parentCountStar);
      }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 2767 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 2771 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 2776 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  AggregateCall::ScalarVals svals;
	  if ((yysemantic_stack_[(6) - (5)].p_RDFLiteral) != NULL)
	      svals["separator"] = (yysemantic_stack_[(6) - (5)].p_RDFLiteral)->getLexicalValue();
	  (yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression), svals));
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 2785 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 2792 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 2795 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 2798 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 2801 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 2804 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 2810 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 2816 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 2823 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 2833 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 2841 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 2849 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 2856 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 2860 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 2868 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 690 of lalr1.cc  */
#line 3813 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -841;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        57,   -93,    77,  -841,  -841,  -841,   300,  -841,  -841,  -841,
    -841,  -841,   -52,    71,    71,    71,    61,    -3,  -841,   -52,
      71,    71,    61,    73,    71,    73,    87,  -841,   115,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,   266,   121,  -841,  -841,  -841,
     130,  -841,  -841,   139,   159,   139,  -841,  -841,  -841,  -841,
    -841,   100,  -841,  -841,  -841,  -841,    33,  -841,    36,    36,
    -841,  -841,  -841,    36,  -841,   -14,  -841,  -841,  -841,   287,
    -841,   122,    61,    61,  -841,   185,  -841,  -841,    44,  -841,
     159,  -841,  -841,   -52,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,   171,  1020,  -841,  -841,     2,     4,  -841,  -841,  -841,
      64,  -841,  -841,   106,   -52,   126,   181,   128,  -841,  -841,
     131,  -841,    -8,  -841,  -841,  -841,  1529,    33,    62,  -841,
    -841,  -841,  -841,    12,  -841,  -841,    66,   192,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
     197,  -841,  -841,  -841,  -841,   209,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,   -47,  -841,  -841,    33,   168,
    -841,   -52,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,    36,  -841,    36,  -841,    36,  -841,  -841,  -841,   227,
    -841,  1698,   191,   234,   245,     5,     8,   248,   251,   262,
    -841,   267,   272,   279,   297,   302,   312,   319,   321,   324,
     325,   333,     8,   334,  -841,  -841,  -841,  -841,   336,  -841,
     337,   143,   145,   338,   339,   340,   343,   176,   344,   200,
     348,   350,   351,   352,   353,   354,   355,   356,   357,   359,
     361,   364,   365,   366,   368,   371,   372,   376,   377,   379,
     381,   383,  -841,  -841,  1818,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,   384,  -841,  -841,  -841,    10,   168,
     322,  -841,  -841,    64,     7,  -841,  -841,  -841,    88,    93,
     421,  1020,  -841,  -841,    93,  1553,    93,   -52,  -841,  -841,
    -841,  -841,   168,   406,  -841,   342,  -841,  -841,   996,  -841,
    -841,  -841,   399,   -10,  -841,  1698,  1938,  1938,  1938,  -841,
     358,  -841,  -841,  -841,  -841,   291,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,    10,  -841,  1698,
    1698,  1698,  -841,  -841,  1698,  -841,  -841,  1698,  1698,  1698,
    -841,  1698,  1698,  1698,  1698,   131,  1698,  1698,  1698,  1698,
    1698,  1698,  -841,   424,   424,  1698,  -841,  -841,  1698,  1698,
    1698,  1698,  -841,  1698,  -841,  1698,  1698,  1698,  1698,  1698,
    1698,  1698,  1698,  1698,  1698,  1698,  1698,  1698,  1698,  1698,
    1698,  1698,  1698,  1698,  1698,  1698,  1698,  -841,   424,   424,
    -841,  -841,  -841,  -841,   -52,  -841,  -841,   265,  -841,  2130,
    -841,  -841,  2082,  -841,  -841,   346,  -841,  -841,   292,  -841,
    -841,  -841,  -841,   392,  1553,  -841,  -841,   403,   445,  -841,
    -841,  -841,  -841,  -841,  1176,  -841,  -841,  -841,  -841,  -841,
    2058,  2282,   429,  -841,  -841,  -841,   422,  -841,  -841,  -841,
     415,  -841,  -841,  -841,  -841,  -841,   -20,   420,  -841,  -841,
    -841,   131,  -841,   423,   409,   411,  1698,  1698,  1698,  1698,
    1698,  1698,   397,     8,  -841,  -841,   199,    56,  -841,  -841,
    -841,   425,   426,   427,  -841,   428,   430,   433,  -841,   436,
     441,   435,   443,   446,   438,   447,   448,   450,   451,   449,
    -841,  1355,  1698,   453,   455,   456,   457,   458,   460,   462,
     466,   467,   468,   463,   469,   473,   474,   470,   478,   479,
     480,   481,   485,   487,   490,   491,   492,   486,   495,   497,
     498,  1698,  1698,  -841,  -841,    68,  -841,  -841,  -841,  2162,
    -841,  -841,   396,  -841,  -841,  -841,  -841,  -841,  -841,  2162,
    -841,  -841,   363,  -841,    13,  -841,     1,  -841,  -841,  -841,
    -841,  -841,  1020,   100,  -841,  -841,  1698,  2058,  -841,  -841,
    -841,  -841,  2282,  -841,  -841,  -841,  -841,  -841,   516,   289,
    -841,   115,  -841,   105,  1020,  -841,  -841,    93,    23,   475,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  1698,  -841,  1698,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,     8,  -841,  1698,
    1698,    56,  -841,  -841,  -841,  1698,  1698,  -841,  -841,  -841,
    -841,  -841,  -841,  1698,  1698,  1698,    64,  -841,  -841,  1698,
    -841,  -841,  1698,  -841,  -841,  -841,  -841,  1698,  -841,  -841,
     502,   496,  -841,  -841,  1698,  1698,  -841,  -841,  -841,  -841,
    -841,  -841,  1698,  -841,  -841,  -841,  1698,  -841,  -841,  -841,
    1698,  -841,  -841,  -841,  -841,  -841,  1698,  -841,  -841,  -841,
     503,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,   -48,
    -841,  -841,  -841,   173,  -841,  -841,  -841,   500,   505,  -841,
    -841,   358,  -841,  -841,  1193,   309,   385,  -841,  -841,   493,
     518,  -841,  -841,  -841,   -14,  -841,  -841,  2282,   511,    64,
    -841,   403,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,    34,  -841,    53,    49,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,    46,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,    64,    18,   507,   515,   521,
    -841,   522,   523,   509,  -841,   484,  -841,   525,   526,   527,
     528,   509,   530,   531,  -841,  -841,  -841,  -841,  -841,  2130,
    -841,  -841,  2082,    93,  -841,  1553,  -841,   537,   534,  -841,
    -841,  1193,  -841,   536,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,   539,  -841,  -841,  -841,    64,  -841,
    -841,  1698,  -841,  1020,    64,   538,   -21,  -841,    41,  -841,
    -841,  -841,  -841,  -841,  -841,  1553,   488,   517,  -841,    -9,
    -841,  -841,  -841,  -841,  -841,  2043,  -841,  -841,  1698,  -841,
    1698,  -841,  -841,  -841,  -841,  -841,   540,   533,  -841,  -841,
    -841,  -841,   542,  -841,  -841,    84,  2106,  -841,  -841,  -841,
    -841,  1553,  -841,  -841,  -841,  -841,  -841,   168,   100,  -841,
    -841,    64,   504,  -841,  -841,  -841,  -841,   550,  -841,  -841,
    -841,  -841,  -841,    34,  -841,    34,  -841,   431,  -841,  -841,
      21,  -841,  -841,  -841,   551,  -841,    79,  -841,  -841,  -841,
    -841,   547,    51,  -841,  1020,    87,  -841,    71,  -841,   131,
     552,  -841,   499,   553,  -841,  -841,   566,  -841,    -1,  -841,
    -841,  -841,  -841,  -841,  2162,  2162,  2162,   567,  -841,    64,
     100,   564,  -841,  -841,   -21,  -841,    23,  -841,  -841,  -841,
    -841,   569,  -841,  -841,  -841,  -841,  -841,    64,  -841,    64,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  1553,  -841
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        12,     0,     0,     2,     4,     3,   197,    14,    13,    10,
      68,     1,     0,   185,   185,   185,     0,     0,    74,     0,
     185,   185,     0,     0,   185,     0,   160,     6,     0,     7,
       8,     9,   162,   169,   170,   171,   175,   172,   173,   174,
     176,   177,   178,   179,   198,     0,    16,   600,   603,   602,
     182,   601,   186,     0,     0,     0,   221,   101,   107,   435,
     436,   106,    74,   104,   433,   434,   118,   196,   212,   212,
     194,   221,   193,   212,   192,   278,     5,   161,   158,    83,
      74,   167,     0,     0,   203,   199,   202,    69,    11,    15,
       0,   183,   180,     0,   217,   216,   218,   215,   184,   188,
     187,     0,   223,    74,   105,   108,     0,   119,    75,   110,
       0,   213,   210,     0,     0,     0,     0,     0,   159,   276,
       0,   277,     0,    81,    82,    84,     0,   118,    12,   168,
     163,   205,   206,     0,   201,   200,     0,     0,    17,    22,
      18,   181,   214,   219,   420,   421,   422,   423,   424,   417,
     594,   595,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   596,   598,   597,   599,   604,   605,   442,   228,   224,
     236,   332,   416,   415,   426,     0,   330,   431,   432,   438,
     439,   582,   583,   584,   440,   580,   437,   441,   118,   121,
     109,     0,   111,   112,   113,   114,   116,   242,   239,   117,
     238,   212,   211,   212,   220,   212,   279,   286,   288,     0,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     552,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   565,   566,   567,   568,     0,   569,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    99,    80,    92,    89,    91,   543,
     507,   544,   545,    90,     0,    93,    94,    95,     0,   121,
     197,   165,   166,     0,     0,   204,    70,    20,     0,     0,
     222,   223,   237,   234,   342,   425,     0,     0,   578,   579,
     581,   576,   121,     0,   103,   123,   122,   115,   245,   189,
     191,   190,     0,     0,   295,     0,     0,     0,     0,   490,
      86,   443,   446,   450,   452,   454,   464,   475,   478,   483,
     484,   485,   491,   486,   487,   488,   489,   574,   556,     0,
       0,     0,   547,   500,     0,   327,   533,     0,     0,     0,
     553,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   506,   322,   322,     0,   526,   527,     0,     0,
       0,     0,   501,     0,   525,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    98,   322,   322,
     319,   318,    73,   195,     0,   207,   208,     0,    56,     0,
      31,    45,     0,    19,    23,     0,    29,    24,     0,    43,
      25,    26,   345,     0,   425,   344,   229,   225,     0,   235,
     343,   333,   341,   430,   425,   427,   429,   331,   577,   102,
       0,     0,   125,   124,   240,    77,     0,   241,   248,   246,
     252,   353,   351,   281,   289,   287,     0,     0,   481,   482,
     480,     0,    87,     0,   444,   448,     0,     0,     0,     0,
       0,     0,     0,     0,   453,   455,   465,   477,   575,   573,
     557,     0,     0,     0,   328,     0,     0,     0,   554,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     323,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   209,    71,     0,   301,    35,   302,    36,
      32,    33,     0,   303,   298,   299,   300,   297,    49,    50,
      46,    47,     0,    29,     0,    43,     0,   418,   339,   348,
     350,   226,   223,     0,   419,   428,     0,   129,   130,   133,
     135,   132,   136,   137,   139,   317,   315,   316,     0,   127,
     126,     0,   243,   307,   245,   253,   250,   342,     0,     0,
     285,   292,   294,   296,   492,    85,    88,     0,   447,     0,
     451,   456,   457,   458,   459,   460,   461,     0,   462,     0,
       0,   470,   476,   466,   467,     0,     0,   479,   558,   498,
     499,   546,   325,     0,     0,     0,     0,   493,   494,     0,
     496,   497,     0,   538,   539,   540,   541,     0,   563,   564,
       0,   571,   542,   528,     0,     0,   517,   532,   524,   523,
     505,   531,     0,   522,   504,   521,     0,   530,   520,   511,
       0,   503,   519,   510,   502,   509,     0,   508,   529,   518,
       0,   320,    55,    58,    57,    34,    39,    48,    53,     0,
      28,    37,    30,     0,    42,    51,    44,   334,   346,   227,
     231,    86,   131,   138,     0,     0,     0,   120,   128,   152,
     154,    78,   266,   270,   278,   264,   304,     0,     0,     0,
     249,   225,   262,   255,   257,   258,   260,   261,   256,   254,
     308,   259,   251,   366,   354,     0,   396,     0,     0,   352,
     355,   357,   358,   367,   369,   372,   381,   376,   379,   394,
     368,   395,   280,   282,   283,   290,   445,   449,   463,   472,
     473,   471,   474,   468,   469,     0,     0,     0,     0,     0,
     555,     0,     0,   549,   560,     0,   572,     0,     0,     0,
       0,   549,     0,     0,   561,   325,    63,    40,    27,     0,
      54,    41,     0,   336,   340,   425,   349,     0,     0,   145,
     146,   140,   141,     0,   143,   144,   148,   149,   156,   157,
     150,   153,   151,   155,   118,   267,   271,   275,     0,   305,
     314,     0,   263,   245,     0,     0,   404,   412,     0,   397,
     399,   406,   408,   411,   382,   425,   370,   374,   390,     0,
     392,   391,   378,   380,   383,     0,   559,   329,     0,   326,
       0,   535,   536,   495,   537,   550,     0,     0,   562,   515,
     516,   512,     0,   513,   514,     0,     0,    38,    52,   337,
     338,   425,   347,   232,   134,   142,   147,   121,     0,   272,
     265,     0,     0,   247,   312,   398,   405,     0,   401,   410,
     413,   409,   364,     0,   373,     0,   377,     0,   414,   393,
       0,   293,   291,   324,     0,   548,     0,   551,   321,    59,
      64,    60,     0,   335,   223,   160,   268,   185,   306,     0,
     309,   407,   403,   356,   371,   375,     0,   387,     0,   388,
     534,   570,    61,    62,     0,     0,     0,     0,    79,     0,
       0,     0,   310,   313,     0,   402,   361,   365,   389,   384,
     386,     0,    67,    66,    65,   233,   269,     0,   274,     0,
     400,   359,   362,   363,   385,   273,   311,   425,   360
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -841,  -841,  -841,  -841,  -841,  -841,   494,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,    50,  -841,   184,  -841,
    -175,  -841,  -841,    67,  -841,  -841,    54,  -841,   187,  -841,
    -174,  -841,  -841,    65,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,    30,
    -841,  -841,  -841,  -841,    29,  -841,  -841,  -841,   -80,  -841,
     349,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -157,  -102,  -841,  -277,  -841,  -841,
    -841,  -841,  -841,  -841,    48,  -841,  -841,    45,  -841,  -841,
    -173,  -841,  -841,  -841,  -841,  -841,  -841,   -84,   -79,  -284,
    -841,  -841,   508,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,    -6,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,   571,  -841,
    -841,    47,  -841,    14,   580,    39,   635,   590,  -841,  -297,
     -58,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -270,  -841,  -841,  -841,  -841,  -588,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,   -50,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -411,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -657,  -105,   315,  -841,  -279,  -703,  -120,  -219,  -841,  -841,
    -841,  -841,   -95,  -841,  -841,  -841,  -841,  -841,    69,  -125,
    -807,  -841,  -841,  -124,  -841,  -841,  -841,  -841,  -841,  -276,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,   -63,  -841,
    -841,  -841,  -220,  -841,  -841,   -64,  -841,  -218,  -841,  -841,
    -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -793,  -841,  -841,  -840,  -101,  -841,  -841,  -841,  -841,
    -841,  -841,  -252,   -92,   -15,    35,  -841,   745,  -841,  -841,
    -841,    72,  -841,  -841,    74,  -841,  -841,  -841,  -180,  -841,
    -841,    55,  -841,  -841,  -841,  -292,  -841,  -271,    -4,  -414,
    -107,  -841,  -841,  -106,  -841,  -841,  -841,  -841,  -841,  -841,
    -841,  -841,  -841,  -104,  -841,  -841,  -841,  -841,  -841,  -841,
     -59,  -841,  -841,  -841,   108,  -841,   195,   196,   155,  -228,
     -12,  -841,  -841
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,    26,     5,     6,     7,    46,    88,
     138,   298,   139,   140,   423,   424,   564,   425,   426,   549,
     550,   692,   789,   551,   788,   427,   566,   428,   429,   559,
     560,   696,   792,   561,   791,   430,   545,   684,   786,   933,
     910,   866,   911,     8,    89,   136,   417,    27,    28,    66,
     454,   455,   591,   814,    80,   125,   126,   472,   473,   272,
     273,   274,   275,    29,   103,    30,    61,    62,   189,    31,
     108,   192,   193,   194,   195,   109,   110,   314,   315,   452,
     589,   707,   316,   577,   578,   453,   582,   583,   590,   801,
     802,   803,   804,   805,   708,   810,   812,   709,   710,    76,
      77,    78,     9,    81,   292,   129,   130,    32,    33,    91,
      92,    34,    53,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,   134,    84,   133,    85,    86,   295,
     415,   113,   114,    97,    98,    57,    72,   101,   102,   168,
     572,   436,   300,   437,   438,   797,   914,   169,   302,   303,
     199,   456,   200,   318,   457,   458,   720,   593,   459,   595,
     596,   721,   722,   723,   818,   724,   815,   878,   939,   725,
     816,   879,   917,   726,   727,   118,   119,   120,   322,   599,
     753,   121,   122,   323,   209,   845,   603,   755,   466,   552,
     728,   819,   881,   729,   730,   824,   943,   959,   920,   731,
     584,   585,   411,   785,   511,   849,   766,   356,   632,   170,
     306,   304,   440,   869,   870,   794,   697,   441,   442,   434,
     568,   796,   698,   569,   460,   598,   597,   739,   835,   740,
     962,   967,   963,   947,   923,   734,   741,   742,   743,   744,
     894,   836,   745,   896,   837,   746,   842,   747,   843,   950,
     929,   899,   844,   748,   749,   829,   945,   922,   886,   887,
     830,   831,   890,   832,   900,   443,   172,   299,   173,   174,
     175,   444,   570,   446,   435,   329,   178,   330,   331,   608,
     474,   332,   610,   475,   333,   334,   484,   485,   335,   336,
     621,   627,   762,   622,   486,   337,   487,   338,   339,   340,
     341,   353,   279,   856,   280,   281,   360,   498,   636,   282,
     490,   628,   765,   342,   650,   284,   776,   777,   343,   489,
     344,   309,   310,   311,   345,   181,   182,   183,   346,   185,
     347,    51,   187
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int SPARQLfedParser::yytable_ninf_ = -426;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        50,   171,    63,   190,   439,    65,   732,    67,    54,    55,
     176,   562,   412,   372,    68,    69,    58,   600,    73,   278,
     601,   276,   283,   413,   106,   289,  -284,   191,   892,   827,
     414,   464,   207,   888,   317,   449,   949,   586,  -118,   897,
     307,   107,   111,   179,   694,   351,   104,   806,   354,    65,
     409,   293,    64,   445,   691,   106,   690,   926,   927,   847,
     820,    70,  -164,   735,   913,   838,   848,   285,    99,   928,
     855,     1,   107,   736,   735,   625,     1,    11,   855,   828,
     -21,   142,   839,    52,   736,    10,   312,   737,   951,   735,
     186,   889,   105,   826,   196,   512,    64,    56,   737,   736,
     197,   787,   202,   827,   141,   682,   934,   840,   683,    71,
     127,   712,   713,   737,   288,   691,   115,    75,   294,   626,
     117,   131,   132,   738,   418,   908,    47,    48,    49,   541,
     542,    79,   848,   188,   738,   714,    87,   177,   308,    90,
     112,   431,  -244,   432,   806,    93,   -21,   841,   562,   715,
     716,   960,   717,   828,   695,   206,   898,    47,    48,    49,
     968,   277,    94,  -118,   898,    93,   602,   278,   586,   276,
     283,   128,  -284,    59,    60,    47,    48,    49,   208,   196,
      59,    60,    47,    48,    49,    47,    48,    49,   754,    83,
     419,   352,   575,   -21,   355,   -21,   410,   -21,   935,   936,
     171,    47,    48,    49,   433,   137,    59,    60,   143,   176,
     180,   447,    47,    48,    49,   285,   201,   461,   204,    47,
      48,    49,   -21,   -21,   -21,   198,   462,    47,    48,    49,
     718,    47,    48,    49,   286,   883,   203,   420,   205,   421,
     301,   422,   179,    95,    96,   296,   179,   297,   319,   305,
     320,   719,   321,   161,   162,   163,   164,   184,   313,   179,
     619,   620,   288,   324,   618,   348,    47,    48,    49,    82,
      83,    47,    48,    49,   349,   699,    59,    60,    47,    48,
      49,   287,   416,    59,    60,   350,   196,    65,   357,   186,
     586,   358,    65,   186,    65,   448,   611,   612,   613,   614,
     615,   616,   359,   586,   123,   124,   186,   361,    12,   277,
      13,    14,   362,    15,    59,    60,   -72,   705,   706,   363,
      16,    17,   468,   469,   470,   790,   695,   759,   760,   376,
      12,   377,    13,    14,    64,    15,   177,   364,    18,    64,
     177,    64,   365,   581,   587,   579,   476,   477,   478,   479,
     480,   481,   366,   177,   763,   764,   482,   483,   465,   367,
     554,   368,   382,   554,   369,   370,   770,   155,   156,   157,
     158,   159,   160,   371,   373,   179,   374,   375,   378,   379,
     380,   562,   286,   381,   383,   179,   384,   586,   385,   876,
     386,   387,   388,   389,   390,   391,   392,   393,   758,   394,
     503,   395,   543,    19,   396,   397,   398,   557,   399,   180,
     557,   400,   401,   180,    20,    21,   402,   403,    22,   404,
      23,   405,   186,   406,   408,    19,   180,  -230,    24,   287,
      25,   450,   186,   451,   902,   463,    20,    21,   288,   288,
      22,   510,    23,   544,   567,   422,   571,   471,   419,   822,
      24,   573,    25,   588,   553,   912,   184,   553,   594,   592,
     184,   604,   607,   617,   606,   609,   629,   630,   631,   177,
     581,   171,   579,   184,   808,   587,   633,   637,   634,   177,
     176,   635,   638,   639,   640,   580,   642,   641,   643,   644,
     554,   645,   646,   461,   652,   846,   653,   647,   686,   656,
     554,   657,   462,   658,   654,   655,   605,   659,   660,   661,
     663,   662,   752,   179,   664,   665,   688,   546,   666,   667,
     668,   669,   706,   952,   953,   954,   671,   555,   672,   670,
     555,   673,   674,   675,   676,   179,   677,   557,   678,   679,
     554,   704,   180,   774,   784,   775,   705,   557,   880,   793,
     809,   821,   180,   795,   884,   850,   851,   848,   700,   857,
     186,    65,   852,   853,   854,   288,   858,   859,   860,   861,
     288,   863,   864,   873,   556,   874,   325,   556,   107,   885,
     895,   905,   186,   907,   553,    65,   751,   557,   906,   184,
     893,   921,   930,   919,   553,   932,   898,   587,   942,   184,
     915,   944,   946,   948,   955,   958,   964,   177,    64,   563,
     587,   918,   580,   689,   867,   565,   685,   937,   868,   693,
     711,   798,   290,   407,   687,   702,   813,   703,   875,   177,
     811,   938,    64,   750,   553,   100,   291,   548,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    47,    48,    49,   135,   555,    59,    60,
      74,   116,   488,   823,   817,   865,   733,   555,   871,   956,
     961,   872,   825,   924,   834,   862,   761,   925,   931,   756,
     180,   623,   624,   757,     0,     0,     0,   965,     0,   966,
       0,     0,   288,     0,   587,     0,     0,     0,     0,     0,
       0,     0,   180,     0,   556,   288,     0,   555,     0,     0,
       0,     0,   877,     0,   556,     0,     0,     0,     0,     0,
       0,     0,   461,   751,     0,   833,   751,   184,     0,     0,
     554,   462,     0,   554,     0,     0,   179,     0,     0,   807,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   184,
       0,     0,     0,     0,   556,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   179,   557,     0,     0,
     557,    65,     0,   186,     0,     0,   554,     0,     0,   288,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   554,     0,     0,
       0,   186,   179,   171,   833,     0,   891,     0,     0,     0,
       0,     0,   176,   186,   553,     0,     0,   553,    64,     0,
     177,     0,     0,   557,     0,     0,   807,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   557,   179,     0,     0,   177,   186,
       0,     0,     0,   916,     0,     0,    65,     0,     0,     0,
     177,     0,     0,     0,     0,   554,   554,   554,     0,     0,
     553,   751,     0,   751,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   555,     0,     0,
     555,   553,   186,   180,     0,     0,   177,     0,   179,     0,
       0,   940,     0,    64,     0,     0,     0,     0,     0,     0,
       0,     0,   557,   557,   557,   957,     0,     0,    65,     0,
       0,   180,   833,     0,   751,     0,     0,     0,     0,     0,
       0,     0,     0,   180,   556,     0,     0,   556,     0,   177,
     184,     0,     0,   555,   941,   186,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   553,
     553,   553,     0,     0,   555,    64,     0,     0,   184,   180,
       0,   750,     0,     0,     0,     0,     0,     0,     0,     0,
     184,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     556,     0,   177,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -76,     0,     0,     0,     0,     0,     0,     0,
       0,   556,   180,     0,     0,     0,   184,   144,   145,   146,
     147,   148,     0,     0,     0,     0,  -425,     0,     0,     0,
       0,     0,   555,   555,   555,     0,     0,   149,     0,     0,
       0,   144,   145,   146,   147,   148,     0,     0,     0,     0,
    -425,     0,     0,     0,     0,     0,     0,     0,     0,   184,
     467,   149,     0,     0,     0,   180,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   556,
     556,   556,     0,     0,   491,   492,   493,     0,     0,   494,
       0,     0,   495,   496,   497,     0,   499,   500,   501,   502,
       0,   504,   505,   506,   507,   508,   509,     0,     0,     0,
     513,     0,   184,   514,   515,   516,   517,     0,   518,     0,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,     0,     0,     0,     0,     0,     0,     0,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,    47,    48,    49,   165,   166,    59,
      60,     0,   167,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    47,    48,
      49,   165,   166,    59,    60,     0,   167,   144,   145,   146,
     147,   148,     0,     0,     0,     0,     0,   574,     0,   799,
     800,     0,     0,     0,     0,     0,     0,   149,     0,     0,
       0,     0,     0,   325,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   649,   651,   212,     0,
     213,   214,   215,   216,   217,   218,   219,   220,     0,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
       0,   232,     0,     0,     0,     0,   680,   681,     0,     0,
       0,     0,   240,     0,     0,     0,     0,     0,     0,     0,
     241,   242,   243,     0,   244,   245,   246,     0,     0,   247,
     248,     0,   249,     0,   250,   251,   252,   253,     0,   254,
     255,   701,   256,     0,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,    47,    48,    49,   165,   166,    59,
      60,     0,   167,     0,     0,     0,     0,     0,     0,     0,
       0,    47,    48,    49,   648,     0,    59,    60,   767,   768,
     769,     0,     0,     0,   771,     0,     0,   772,     0,     0,
       0,     0,   773,     0,     0,   325,     0,     0,     0,   778,
     779,     0,     0,     0,     0,     0,     0,   780,     0,     0,
       0,   781,     0,     0,     0,   782,   326,   327,     0,   328,
     212,   783,   213,   214,   215,   216,   217,   218,   219,   220,
       0,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,     0,   232,     0,     0,     0,   233,   234,   235,
     236,   237,   238,   239,   240,     0,     0,     0,     0,     0,
       0,     0,   241,   242,   243,     0,   244,   245,   246,     0,
       0,   247,   248,     0,   249,     0,   250,   251,   252,   253,
       0,   254,   255,     0,   256,     0,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,    47,    48,    49,     0,     0,    59,    60,
       0,     0,     0,     0,     0,     0,     0,     0,   210,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   882,     0,     0,   211,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   144,   145,   146,   147,   148,     0,
       0,     0,     0,   903,   212,   904,   213,   214,   215,   216,
     217,   218,   219,   220,   149,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,     0,   232,     0,     0,
       0,   233,   234,   235,   236,   237,   238,   239,   240,     0,
       0,     0,     0,     0,     0,     0,   241,   242,   243,     0,
     244,   245,   246,     0,     0,   247,   248,     0,   249,     0,
     250,   251,   252,   253,     0,   254,   255,     0,   256,     0,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    47,    48,    49,
       0,     0,    59,    60,     0,     0,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    47,    48,    49,   165,   166,    59,    60,   325,   167,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   326,
     327,     0,   328,   212,     0,   213,   214,   215,   216,   217,
     218,   219,   220,     0,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,     0,   232,     0,     0,     0,
     233,   234,   235,   236,   237,   238,   239,   240,     0,     0,
       0,     0,     0,     0,     0,   241,   242,   243,     0,   244,
     245,   246,     0,     0,   247,   248,     0,   249,     0,   250,
     251,   252,   253,     0,   254,   255,     0,   256,     0,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   211,     0,
       0,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    47,    48,    49,     0,
       0,    59,    60,   212,     0,   213,   214,   215,   216,   217,
     218,   219,   220,     0,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,     0,   232,     0,     0,     0,
     233,   234,   235,   236,   237,   238,   239,   240,     0,     0,
       0,     0,     0,     0,     0,   241,   242,   243,     0,   244,
     245,   246,     0,     0,   247,   248,     0,   249,     0,   250,
     251,   252,   253,     0,   254,   255,     0,   256,     0,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   325,     0,
       0,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    47,    48,    49,     0,
       0,    59,    60,   212,     0,   213,   214,   215,   216,   217,
     218,   219,   220,     0,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,     0,   232,     0,     0,     0,
     233,   234,   235,   236,   237,   238,   239,   240,     0,     0,
       0,     0,     0,     0,     0,   241,   242,   243,     0,   244,
     245,   246,     0,     0,   247,   248,     0,   249,     0,   250,
     251,   252,   253,     0,   254,   255,     0,   256,     0,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   901,   546,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   576,     0,
       0,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    47,    48,    49,     0,
       0,    59,    60,   212,   546,   213,   214,   215,   216,   217,
     218,   219,   220,     0,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,     0,   232,   909,   546,     0,
       0,     0,     0,     0,     0,     0,     0,   240,     0,     0,
       0,     0,     0,     0,     0,   241,   242,   243,     0,   244,
     245,   246,   546,     0,   247,   248,     0,   249,     0,   250,
     251,   252,   253,     0,   254,   255,     0,   256,     0,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   546,   548,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    47,    48,    49,     0,     0,    59,    60,     0,     0,
       0,     0,   547,     0,     0,   558,    47,    48,    49,     0,
       0,    59,    60,     0,   548,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      47,    48,    49,     0,     0,    59,    60,     0,   548,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,    47,    48,    49,     0,     0,    59,
      60,     0,   548,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    47,    48,
      49,     0,     0,    59,    60,     0,     0,     0,     0,     0,
       0,     0,   325,     0,   548,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      47,    48,    49,     0,     0,    59,    60,   212,     0,   213,
     214,   215,   216,   217,   218,   219,   220,     0,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,     0,
     232,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,     0,     0,     0,     0,     0,     0,     0,   241,
     242,   243,     0,   244,   245,   246,     0,     0,   247,   248,
       0,   249,     0,   250,   251,   252,   253,     0,   254,   255,
       0,   256,     0,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,    48,    49
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        12,   102,    17,   105,   301,    17,   594,    19,    14,    15,
     102,   422,   289,   232,    20,    21,    19,    37,    24,   126,
      40,   126,   126,   293,    22,   127,    40,    23,   835,    50,
      23,    41,    40,   826,   191,   312,    37,   451,    36,    48,
      87,    39,     6,   102,    43,    40,    61,   704,    40,    61,
      40,    39,    17,   305,   102,    22,    43,   897,    37,    41,
     717,    22,     0,    40,   871,    19,    48,   126,    54,    48,
     773,    14,    39,    50,    40,    19,    14,     0,   781,   100,
      36,    93,    36,    12,    50,   178,   188,    64,   928,    40,
     102,    50,    62,    40,   106,   374,    61,    36,    64,    50,
      36,   149,   114,    50,    90,    37,    55,    61,    40,    36,
      80,     6,     7,    64,   126,   102,    69,    30,   106,    63,
      73,    82,    83,   100,    36,    41,   178,   179,   180,   408,
     409,    16,    48,   103,   100,    30,    15,   102,   185,     9,
     104,   298,    37,    50,   801,     6,   102,   101,   559,    44,
      45,   944,    47,   100,   153,   120,   165,   178,   179,   180,
     967,   126,    23,   161,   165,     6,   186,   274,   582,   274,
     274,    49,   186,   183,   184,   178,   179,   180,   186,   191,
     183,   184,   178,   179,   180,   178,   179,   180,   599,     4,
     102,   186,   444,   149,   186,   151,   186,   153,   147,   148,
     301,   178,   179,   180,   299,   161,   183,   184,    37,   301,
     102,   306,   178,   179,   180,   274,   110,   318,    37,   178,
     179,   180,   178,   179,   180,   161,   318,   178,   179,   180,
     125,   178,   179,   180,   126,   823,   110,   149,   110,   151,
      43,   153,   301,   104,   105,   179,   305,    55,   201,    40,
     203,   146,   205,   174,   175,   176,   177,   102,    90,   318,
      61,    62,   274,    36,   483,    74,   178,   179,   180,     3,
       4,   178,   179,   180,    40,   572,   183,   184,   178,   179,
     180,   126,   294,   183,   184,    40,   298,   299,    40,   301,
     704,    40,   304,   305,   306,   307,   476,   477,   478,   479,
     480,   481,    40,   717,    17,    18,   318,    40,     8,   274,
      10,    11,    40,    13,   183,   184,    16,    28,    29,    40,
      20,    21,   326,   327,   328,   152,   153,   619,   620,   186,
       8,   186,    10,    11,   299,    13,   301,    40,    38,   304,
     305,   306,    40,   450,   451,   450,    55,    56,    57,    58,
      59,    60,    40,   318,   625,   626,    65,    66,   323,    40,
     419,    40,   186,   422,    40,    40,   636,   168,   169,   170,
     171,   172,   173,    40,    40,   434,    40,    40,    40,    40,
      40,   792,   274,    40,    40,   444,   186,   801,    40,   803,
      40,    40,    40,    40,    40,    40,    40,    40,   617,    40,
     365,    40,   414,   103,    40,    40,    40,   419,    40,   301,
     422,    40,    40,   305,   114,   115,    40,    40,   118,    40,
     120,    40,   434,    40,    40,   103,   318,     6,   128,   274,
     130,    25,   444,    91,   845,    36,   114,   115,   450,   451,
     118,    17,   120,   178,    52,   153,    43,    89,   102,   719,
     128,     6,   130,    24,   419,   866,   301,   422,    43,    37,
     305,    41,    53,    66,    41,    54,    41,    41,    41,   434,
     577,   572,   577,   318,   165,   582,    48,    41,    48,   444,
     572,    48,    41,    48,    41,   450,    48,    41,    41,    41,
     549,    41,    41,   594,    41,   765,    41,    48,   102,    41,
     559,    41,   594,    41,    48,    48,   471,    41,    41,    41,
      41,    48,    37,   572,    41,    41,   153,    42,    48,    41,
      41,    41,    29,   934,   935,   936,    41,   419,    41,    48,
     422,    41,    41,    41,    48,   594,    41,   549,    41,    41,
     599,    25,   434,    41,    41,    49,    28,   559,   818,    49,
     165,    40,   444,    48,   824,    48,    41,    48,   573,    75,
     572,   573,    41,    41,    41,   577,    41,    41,    41,    41,
     582,    41,    41,    36,   419,    41,    40,   422,    39,    41,
      63,    41,   594,    41,   549,   597,   598,   599,    55,   434,
     102,    41,    41,    89,   559,    48,   165,   704,    46,   444,
     877,   102,    49,    37,    37,    41,    37,   572,   573,   425,
     717,   881,   577,   563,   789,   428,   549,   914,   792,   565,
     591,   701,   128,   274,   559,   577,   710,   582,   801,   594,
     709,   915,   597,   598,   599,    55,   128,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    85,   549,   183,   184,
      25,    71,   347,   721,   714,   785,   597,   559,   793,   939,
     946,   795,   735,   893,   738,   781,   621,   895,   906,   607,
     572,   486,   486,   609,    -1,    -1,    -1,   957,    -1,   959,
      -1,    -1,   704,    -1,   801,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   594,    -1,   549,   717,    -1,   599,    -1,    -1,
      -1,    -1,   814,    -1,   559,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   823,   735,    -1,   737,   738,   572,    -1,    -1,
     789,   823,    -1,   792,    -1,    -1,   795,    -1,    -1,   704,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   594,
      -1,    -1,    -1,    -1,   599,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   823,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   835,   789,    -1,    -1,
     792,   793,    -1,   795,    -1,    -1,   845,    -1,    -1,   801,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   866,    -1,    -1,
      -1,   823,   871,   914,   826,    -1,   828,    -1,    -1,    -1,
      -1,    -1,   914,   835,   789,    -1,    -1,   792,   793,    -1,
     795,    -1,    -1,   845,    -1,    -1,   801,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   866,   914,    -1,    -1,   823,   871,
      -1,    -1,    -1,   878,    -1,    -1,   878,    -1,    -1,    -1,
     835,    -1,    -1,    -1,    -1,   934,   935,   936,    -1,    -1,
     845,   893,    -1,   895,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   789,    -1,    -1,
     792,   866,   914,   795,    -1,    -1,   871,    -1,   967,    -1,
      -1,   917,    -1,   878,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   934,   935,   936,   940,    -1,    -1,   940,    -1,
      -1,   823,   944,    -1,   946,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   835,   789,    -1,    -1,   792,    -1,   914,
     795,    -1,    -1,   845,   919,   967,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   934,
     935,   936,    -1,    -1,   866,   940,    -1,    -1,   823,   871,
      -1,   946,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     835,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     845,    -1,   967,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   866,   914,    -1,    -1,    -1,   871,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,   934,   935,   936,    -1,    -1,    51,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   914,
     325,    51,    -1,    -1,    -1,   967,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   934,
     935,   936,    -1,    -1,   349,   350,   351,    -1,    -1,   354,
      -1,    -1,   357,   358,   359,    -1,   361,   362,   363,   364,
      -1,   366,   367,   368,   369,   370,   371,    -1,    -1,    -1,
     375,    -1,   967,   378,   379,   380,   381,    -1,   383,    -1,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,    -1,   186,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,    -1,   186,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    41,    -1,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   511,   512,    65,    -1,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    -1,    -1,    -1,    -1,   541,   542,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     107,   108,   109,    -1,   111,   112,   113,    -1,    -1,   116,
     117,    -1,   119,    -1,   121,   122,   123,   124,    -1,   126,
     127,   576,   129,    -1,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   178,   179,   180,    19,    -1,   183,   184,   633,   634,
     635,    -1,    -1,    -1,   639,    -1,    -1,   642,    -1,    -1,
      -1,    -1,   647,    -1,    -1,    40,    -1,    -1,    -1,   654,
     655,    -1,    -1,    -1,    -1,    -1,    -1,   662,    -1,    -1,
      -1,   666,    -1,    -1,    -1,   670,    61,    62,    -1,    64,
      65,   676,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   107,   108,   109,    -1,   111,   112,   113,    -1,
      -1,   116,   117,    -1,   119,    -1,   121,   122,   123,   124,
      -1,   126,   127,    -1,   129,    -1,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,   183,   184,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   821,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,   848,    65,   850,    67,    68,    69,    70,
      71,    72,    73,    74,    51,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    -1,    -1,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,
     111,   112,   113,    -1,    -1,   116,   117,    -1,   119,    -1,
     121,   122,   123,   124,    -1,   126,   127,    -1,   129,    -1,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,   183,   184,    -1,    -1,   163,   164,   165,   166,
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
      82,    83,    84,    85,    86,    -1,    88,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,   111,
     112,   113,    42,    -1,   116,   117,    -1,   119,    -1,   121,
     122,   123,   124,    -1,   126,   127,    -1,   129,    -1,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    42,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,   183,   184,    -1,    -1,
      -1,    -1,   102,    -1,    -1,   153,   178,   179,   180,    -1,
      -1,   183,   184,    -1,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,    -1,    -1,   183,   184,    -1,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    -1,    -1,   183,
     184,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,    -1,    -1,   183,   184,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    -1,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,    -1,    -1,   183,   184,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,    -1,   111,   112,   113,    -1,    -1,   116,   117,
      -1,   119,    -1,   121,   122,   123,   124,    -1,   126,   127,
      -1,   129,    -1,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     178,   179,   180
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    14,   188,   189,   190,   192,   193,   194,   230,   289,
     178,     0,     8,    10,    11,    13,    20,    21,    38,   103,
     114,   115,   118,   120,   128,   130,   191,   234,   235,   250,
     252,   256,   294,   295,   298,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   195,   178,   179,   180,
     517,   518,    12,   299,   299,   299,    36,   322,    19,   183,
     184,   253,   254,   461,   462,   517,   236,   517,   299,   299,
     322,    36,   323,   299,   323,    30,   286,   287,   288,    16,
     241,   290,     3,     4,   312,   314,   315,    15,   196,   231,
       9,   296,   297,     6,    23,   104,   105,   320,   321,   320,
     321,   324,   325,   251,   461,   236,    22,    39,   257,   262,
     263,     6,   104,   318,   319,   318,   324,   318,   362,   363,
     364,   368,   369,    17,    18,   242,   243,   236,    49,   292,
     293,   322,   322,   313,   311,   315,   232,   161,   197,   199,
     200,   320,   517,    37,    31,    32,    33,    34,    35,    51,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   181,   182,   186,   326,   334,
     396,   452,   453,   455,   456,   457,   460,   462,   463,   507,
     511,   512,   513,   514,   515,   516,   517,   519,   236,   255,
     262,    23,   258,   259,   260,   261,   517,    36,   161,   337,
     339,   110,   517,   110,    37,   110,   462,    40,   186,   371,
      19,    40,    65,    67,    68,    69,    70,    71,    72,    73,
      74,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    88,    92,    93,    94,    95,    96,    97,    98,
      99,   107,   108,   109,   111,   112,   113,   116,   117,   119,
     121,   122,   123,   124,   126,   127,   129,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   246,   247,   248,   249,   388,   462,   487,   489,
     491,   492,   496,   500,   502,   507,   511,   515,   517,   262,
     193,   289,   291,    39,   106,   316,   179,    55,   198,   454,
     329,    43,   335,   336,   398,    40,   397,    87,   185,   508,
     509,   510,   262,    90,   264,   265,   269,   261,   340,   318,
     318,   318,   365,   370,    36,    40,    61,    62,    64,   462,
     464,   465,   468,   471,   472,   475,   476,   482,   484,   485,
     486,   487,   500,   505,   507,   511,   515,   517,    74,    40,
      40,    40,   186,   488,    40,   186,   394,    40,    40,    40,
     493,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,   394,    40,    40,    40,   186,   186,    40,    40,
      40,    40,   186,    40,   186,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,   247,    40,    40,
     186,   389,   264,   337,    23,   317,   517,   233,    36,   102,
     149,   151,   153,   201,   202,   204,   205,   212,   214,   215,
     222,   261,    50,   399,   406,   461,   328,   330,   331,   326,
     399,   404,   405,   452,   458,   459,   460,   399,   517,   264,
      25,    91,   266,   272,   237,   238,   338,   341,   342,   345,
     411,   452,   460,    36,    41,   462,   375,   464,   485,   485,
     485,    89,   244,   245,   467,   470,    55,    56,    57,    58,
      59,    60,    65,    66,   473,   474,   481,   483,   389,   506,
     497,   464,   464,   464,   464,   464,   464,   464,   494,   464,
     464,   464,   464,   462,   464,   464,   464,   464,   464,   464,
      17,   391,   391,   464,   464,   464,   464,   464,   464,   464,
     464,   464,   464,   464,   464,   464,   464,   464,   464,   464,
     464,   464,   464,   464,   464,   464,   464,   464,   464,   464,
     464,   391,   391,   517,   178,   223,    42,   102,   162,   206,
     207,   210,   376,   462,   507,   511,   515,   517,   153,   216,
     217,   220,   376,   205,   203,   215,   213,    52,   407,   410,
     459,    43,   327,     6,    41,   459,    40,   270,   271,   388,
     462,   487,   273,   274,   387,   388,   486,   487,    24,   267,
     275,   239,    37,   344,    43,   346,   347,   413,   412,   366,
      37,    40,   186,   373,    41,   462,    41,    53,   466,    54,
     469,   475,   475,   475,   475,   475,   475,    66,   394,    61,
      62,   477,   480,   513,   514,    19,    63,   478,   498,    41,
      41,    41,   395,    48,    48,    48,   495,    41,    41,    48,
      41,    41,    48,    41,    41,    41,    41,    48,    19,   464,
     501,   464,    41,    41,    48,    48,    41,    41,    41,    41,
      41,    41,    48,    41,    41,    41,    48,    41,    41,    41,
      48,    41,    41,    41,    41,    41,    48,    41,    41,    41,
     464,   464,    37,    40,   224,   210,   102,   220,   153,   203,
      43,   102,   208,   213,    43,   153,   218,   403,   409,   326,
     461,   464,   271,   274,    25,    28,    29,   268,   281,   284,
     285,   241,     6,     7,    30,    44,    45,    47,   125,   146,
     343,   348,   349,   350,   352,   356,   360,   361,   377,   380,
     381,   386,   342,   405,   422,    40,    50,    64,   100,   414,
     416,   423,   424,   425,   426,   429,   432,   434,   440,   441,
     462,   517,    37,   367,   376,   374,   468,   471,   394,   482,
     482,   478,   479,   484,   484,   499,   393,   464,   464,   464,
     337,   464,   464,   464,    41,    49,   503,   504,   464,   464,
     464,   464,   464,   464,    41,   390,   225,   149,   211,   209,
     152,   221,   219,    49,   402,    48,   408,   332,   245,    26,
      27,   276,   277,   278,   279,   280,   387,   462,   165,   165,
     282,   285,   283,   284,   240,   353,   357,   362,   351,   378,
     387,    40,   337,   327,   382,   425,    40,    50,   100,   442,
     447,   448,   450,   517,   432,   415,   428,   431,    19,    36,
      61,   101,   433,   435,   439,   372,   337,    41,    48,   392,
      48,    41,    41,    41,    41,   392,   490,    75,    41,    41,
      41,    41,   490,    41,    41,   393,   228,   207,   217,   400,
     401,   406,   410,    36,    41,   277,   486,   262,   354,   358,
     337,   379,   464,   342,   337,    41,   445,   446,   448,    50,
     449,   517,   407,   102,   427,    63,   430,    48,   165,   438,
     451,    41,   376,   464,   464,    41,    55,    41,    41,    41,
     227,   229,   376,   407,   333,   264,   461,   359,   337,    89,
     385,    41,   444,   421,   429,   434,   451,    37,    48,   437,
      41,   516,    48,   226,    55,   147,   148,   326,   286,   355,
     299,   462,    46,   383,   102,   443,    49,   420,    37,    37,
     436,   451,   376,   376,   376,    37,   337,   461,    41,   384,
     448,   416,   417,   419,    37,   337,   337,   418,   407
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
     249,   251,   250,   252,   253,   253,   254,   254,   255,   255,
     256,   257,   258,   258,   259,   260,   261,   262,   263,   263,
     264,   265,   265,   266,   266,   267,   267,   268,   268,   269,
     270,   270,   271,   271,   271,   271,   272,   273,   273,   274,
     275,   276,   276,   277,   277,   278,   278,   279,   280,   280,
     281,   281,   282,   282,   283,   283,   284,   285,   286,   287,
     288,   288,   290,   289,   291,   291,   292,   293,   293,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     295,   296,   297,   297,   298,   299,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   310,   311,
     311,   312,   312,   313,   313,   314,   315,   316,   317,   317,
     318,   318,   319,   319,   320,   321,   321,   321,   321,   322,
     323,   325,   324,   326,   326,   327,   327,   328,   329,   329,
     331,   332,   333,   330,   334,   335,   336,   336,   337,   337,
     338,   338,   340,   339,   341,   342,   342,   343,   344,   344,
     345,   346,   347,   347,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   349,   351,   350,   353,   354,   355,   352,
     357,   358,   359,   356,   360,   361,   362,   362,   364,   365,
     363,   366,   366,   367,   369,   368,   370,   370,   371,   371,
     372,   372,   374,   373,   373,   375,   375,   376,   376,   376,
     376,   376,   376,   376,   378,   379,   377,   381,   382,   380,
     384,   383,   385,   385,   386,   387,   387,   387,   388,   389,
     390,   389,   391,   391,   392,   393,   393,   394,   395,   394,
     397,   396,   398,   396,   399,   400,   401,   401,   402,   403,
     403,   404,   405,   405,   406,   406,   407,   408,   409,   409,
     410,   412,   411,   413,   411,   415,   414,   416,   416,   418,
     417,   419,   419,   420,   421,   421,   422,   423,   424,   425,
     426,   427,   428,   428,   429,   430,   431,   431,   432,   433,
     433,   434,   434,   435,   436,   436,   437,   437,   438,   438,
     439,   439,   439,   439,   440,   441,   441,   441,   441,   442,
     443,   444,   444,   445,   446,   446,   447,   447,   448,   449,
     449,   450,   450,   450,   451,   452,   452,   454,   453,   455,
     456,   456,   456,   456,   456,   457,   457,   458,   458,   459,
     459,   460,   460,   461,   461,   462,   462,   463,   463,   463,
     463,   463,   463,   464,   465,   466,   467,   467,   468,   469,
     470,   470,   471,   472,   473,   473,   474,   474,   474,   474,
     474,   474,   474,   474,   475,   476,   477,   477,   478,   478,
     479,   479,   480,   480,   480,   481,   481,   482,   483,   483,
     484,   484,   484,   484,   485,   485,   485,   485,   485,   485,
     485,   485,   486,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   488,   488,   489,   490,
     490,   491,   493,   494,   495,   492,   497,   498,   499,   496,
     500,   500,   500,   501,   501,   502,   502,   502,   502,   502,
     503,   504,   504,   505,   506,   506,   507,   508,   509,   509,
     510,   510,   511,   511,   511,   512,   512,   512,   513,   513,
     513,   514,   514,   514,   515,   515,   516,   516,   516,   516,
     517,   517,   518,   518,   519,   519
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
       1,     0,     6,     5,     1,     2,     1,     1,     0,     1,
       3,     2,     1,     1,     1,     2,     1,     2,     0,     1,
       4,     0,     1,     0,     1,     0,     1,     0,     1,     3,
       1,     2,     1,     1,     4,     1,     2,     1,     2,     1,
       3,     1,     2,     1,     1,     1,     1,     2,     1,     1,
       2,     2,     0,     1,     0,     1,     2,     2,     1,     2,
       0,     1,     0,     4,     0,     1,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     0,     1,     3,     0,     1,     3,     3,     5,
       5,     5,     2,     2,     2,     5,     2,     0,     1,     0,
       1,     2,     1,     0,     2,     2,     2,     2,     1,     2,
       1,     2,     0,     1,     2,     1,     1,     1,     1,     3,
       3,     0,     3,     0,     1,     0,     1,     3,     0,     2,
       0,     0,     0,     8,     2,     2,     0,     1,     1,     1,
       1,     1,     0,     4,     2,     0,     1,     3,     0,     2,
       2,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     3,     0,     0,     0,     6,
       0,     0,     0,     7,     6,     2,     1,     1,     0,     0,
       6,     0,     2,     1,     0,     5,     0,     2,     1,     3,
       0,     2,     0,     4,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     0,     0,     4,     0,     0,     4,
       0,     3,     0,     2,     2,     1,     1,     1,     2,     1,
       0,     6,     0,     1,     2,     0,     2,     1,     0,     5,
       0,     3,     0,     3,     3,     2,     0,     1,     2,     0,
       2,     1,     0,     1,     1,     1,     2,     2,     0,     2,
       1,     0,     3,     0,     3,     0,     4,     1,     1,     0,
       3,     0,     1,     2,     0,     2,     1,     1,     1,     1,
       2,     2,     0,     2,     2,     2,     0,     2,     2,     0,
       1,     1,     2,     1,     1,     2,     2,     1,     2,     3,
       1,     1,     1,     2,     1,     1,     1,     2,     3,     1,
       2,     0,     2,     2,     0,     1,     1,     3,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     0,     4,     4,
       1,     1,     1,     1,     1,     0,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     0,     2,     2,     2,
       0,     2,     1,     2,     0,     1,     2,     2,     2,     2,
       2,     2,     2,     3,     1,     2,     1,     1,     2,     2,
       0,     1,     2,     2,     2,     0,     2,     2,     0,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     4,     6,     4,     4,     4,     4,
       2,     2,     4,     4,     4,     4,     2,     1,     4,     4,
       4,     4,     6,     6,     6,     6,     6,     4,     4,     4,
       4,     4,     4,     4,     4,     2,     2,     2,     4,     4,
       4,     4,     4,     2,     8,     6,     6,     6,     4,     4,
       4,     4,     4,     1,     1,     1,     3,     1,     7,     0,
       1,     7,     0,     0,     0,     5,     0,     0,     0,     6,
       5,     5,     6,     1,     1,     1,     1,     1,     1,     1,
       4,     0,     1,     2,     0,     1,     2,     2,     1,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
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
  "_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_Q_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C_E_Plus",
  "_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_Plus_Or_QGT_TIMES_E_C",
  "ConstructQuery", "$@11", "DescribeQuery", "_QVarOrIri_E_Plus",
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
     191,   286,    -1,   234,    -1,   250,    -1,   252,    -1,   256,
      -1,   289,    -1,   194,   195,   196,    -1,    -1,   230,    -1,
      -1,   195,   231,    -1,    -1,   196,   197,    -1,    -1,   200,
     198,   201,    -1,   161,    55,    -1,    -1,   199,    -1,   202,
      -1,   212,    -1,   222,    -1,   261,    -1,   204,   205,   203,
     211,    -1,   205,   203,    43,    -1,    -1,   203,   208,    -1,
     149,    -1,   102,   207,    -1,   210,    -1,   206,   210,    -1,
     102,    -1,   206,    -1,    -1,   102,   209,   207,    -1,   376,
     102,    -1,   149,    -1,   214,   215,   213,   221,    -1,   215,
     213,    43,    -1,    -1,   213,   218,    -1,   151,    -1,   153,
     217,    -1,   220,    -1,   216,   220,    -1,   153,    -1,   216,
      -1,    -1,   153,   219,   217,    -1,   376,   153,    -1,   152,
      -1,    36,   223,    37,    -1,    -1,   223,   224,    -1,    -1,
      40,   225,   228,    41,    -1,    -1,    48,    -1,   229,   226,
      -1,    -1,   228,   227,    -1,   376,   148,   376,    -1,   376,
     147,   376,    -1,   376,    55,   376,    -1,    14,   178,    -1,
      -1,    -1,    15,   232,   179,   233,   178,    -1,    -1,   235,
     241,   236,   262,   264,    -1,    -1,   236,   257,    -1,    -1,
      -1,    -1,   238,   239,   241,   240,   262,   264,   286,    -1,
      16,   243,   249,    -1,    17,    -1,    18,    -1,    -1,   242,
      -1,    89,   462,    -1,    -1,   244,    -1,    40,   464,   245,
      41,    -1,   462,    -1,   500,    -1,   487,    -1,   388,    -1,
     507,    -1,   511,    -1,   515,    -1,   246,    -1,   247,    -1,
     248,   247,    -1,   248,    -1,    19,    -1,    -1,    20,   322,
     251,   236,   262,   264,    -1,    21,   254,   236,   255,   264,
      -1,   461,    -1,   253,   461,    -1,   253,    -1,    19,    -1,
      -1,   262,    -1,    38,   236,   262,    -1,    22,   258,    -1,
     259,    -1,   260,    -1,   261,    -1,    23,   261,    -1,   517,
      -1,   263,   337,    -1,    -1,    39,    -1,   265,   266,   267,
     268,    -1,    -1,   269,    -1,    -1,   272,    -1,    -1,   275,
      -1,    -1,   281,    -1,    90,    25,   270,    -1,   271,    -1,
     270,   271,    -1,   487,    -1,   388,    -1,    40,   464,   245,
      41,    -1,   462,    -1,    91,   273,    -1,   274,    -1,   273,
     274,    -1,   387,    -1,    24,    25,   276,    -1,   277,    -1,
     276,   277,    -1,   279,    -1,   280,    -1,    26,    -1,    27,
      -1,   278,   486,    -1,   387,    -1,   462,    -1,   284,   282,
      -1,   285,   283,    -1,    -1,   285,    -1,    -1,   284,    -1,
      28,   165,    -1,    29,   165,    -1,   288,    -1,    30,   362,
      -1,    -1,   287,    -1,    -1,   193,   294,   290,   293,    -1,
      -1,   289,    -1,    49,   291,    -1,    -1,   292,    -1,   295,
      -1,   298,    -1,   300,    -1,   302,    -1,   303,    -1,   304,
      -1,   301,    -1,   305,    -1,   306,    -1,   307,    -1,   308,
      -1,     8,   517,   297,    -1,     9,   320,    -1,    -1,   296,
      -1,    10,   299,   321,    -1,    -1,    12,    -1,    13,   299,
     321,    -1,    11,   299,   320,    -1,   114,   299,   318,   110,
     318,    -1,   128,   299,   318,   110,   318,    -1,   115,   299,
     318,   110,   318,    -1,   130,   323,    -1,   120,   323,    -1,
     118,   322,    -1,   310,   312,   313,    39,   337,    -1,   103,
     517,    -1,    -1,   309,    -1,    -1,   315,    -1,   314,   311,
      -1,   315,    -1,    -1,   313,   316,    -1,     3,   322,    -1,
       4,   322,    -1,   106,   317,    -1,   517,    -1,    23,   517,
      -1,   104,    -1,   319,   517,    -1,    -1,     6,    -1,     6,
     517,    -1,   320,    -1,   104,    -1,    23,    -1,   105,    -1,
      36,   324,    37,    -1,    36,   324,    37,    -1,    -1,   325,
     326,   329,    -1,    -1,   334,    -1,    -1,    43,    -1,   330,
     327,   326,    -1,    -1,   329,   328,    -1,    -1,    -1,    -1,
     331,     6,   461,   332,    36,   333,   326,    37,    -1,   396,
     336,    -1,    43,   326,    -1,    -1,   335,    -1,   339,    -1,
     161,    -1,   237,    -1,   341,    -1,    -1,    36,   340,   338,
      37,    -1,   342,   344,    -1,    -1,   345,    -1,   348,   327,
     342,    -1,    -1,   344,   343,    -1,   411,   347,    -1,    43,
     342,    -1,    -1,   346,    -1,   380,    -1,   350,    -1,   377,
      -1,   352,    -1,   356,    -1,   386,    -1,   360,    -1,   361,
      -1,   349,    -1,   146,   337,    -1,    -1,    44,   351,   337,
      -1,    -1,    -1,    -1,     6,   353,   354,   461,   355,   337,
      -1,    -1,    -1,    -1,     7,   357,   358,   359,   299,   461,
     337,    -1,   125,    40,   464,    89,   462,    41,    -1,    30,
     362,    -1,   363,    -1,   368,    -1,    -1,    -1,   364,   462,
     365,    36,   366,    37,    -1,    -1,   366,   367,    -1,   376,
      -1,    -1,   369,   371,    36,   375,    37,    -1,    -1,   370,
     462,    -1,   186,    -1,    40,   370,    41,    -1,    -1,   372,
     376,    -1,    -1,    40,   374,   372,    41,    -1,   186,    -1,
      -1,   375,   373,    -1,   517,    -1,   507,    -1,   511,    -1,
     515,    -1,    42,    -1,   162,    -1,   462,    -1,    -1,    -1,
      45,   378,   379,   337,    -1,    -1,    -1,   381,   382,   337,
     385,    -1,    -1,    46,   384,   337,    -1,    -1,   385,   383,
      -1,    47,   387,    -1,   486,    -1,   487,    -1,   388,    -1,
     517,   389,    -1,   186,    -1,    -1,    40,   391,   464,   390,
     393,    41,    -1,    -1,    17,    -1,    48,   464,    -1,    -1,
     393,   392,    -1,   186,    -1,    -1,    40,   464,   395,   393,
      41,    -1,    -1,   460,   397,   399,    -1,    -1,   452,   398,
     404,    -1,   406,   407,   403,    -1,   406,   407,    -1,    -1,
     400,    -1,    49,   401,    -1,    -1,   403,   402,    -1,   405,
      -1,    -1,   399,    -1,   461,    -1,    50,    -1,   410,   409,
      -1,    48,   410,    -1,    -1,   409,   408,    -1,   459,    -1,
      -1,   460,   412,   414,    -1,    -1,   452,   413,   422,    -1,
      -1,   416,   415,   407,   421,    -1,   423,    -1,   424,    -1,
      -1,   416,   418,   407,    -1,    -1,   417,    -1,    49,   419,
      -1,    -1,   421,   420,    -1,   405,    -1,   425,    -1,   462,
      -1,   426,    -1,   429,   428,    -1,   102,   429,    -1,    -1,
     428,   427,    -1,   434,   431,    -1,    63,   434,    -1,    -1,
     431,   430,    -1,   440,   433,    -1,    -1,   435,    -1,   432,
      -1,   100,   432,    -1,   439,    -1,    37,    -1,   451,    37,
      -1,    48,   436,    -1,    37,    -1,   451,   437,    -1,    48,
     451,    37,    -1,    19,    -1,   101,    -1,    61,    -1,    36,
     438,    -1,   441,    -1,   517,    -1,    50,    -1,    64,   442,
      -1,    40,   425,    41,    -1,   447,    -1,   102,   448,    -1,
      -1,   444,   443,    -1,   448,   444,    -1,    -1,   445,    -1,
     448,    -1,    40,   446,    41,    -1,   450,    -1,   517,    -1,
      50,    -1,   517,    -1,    50,    -1,   100,   449,    -1,   165,
      -1,   455,    -1,   453,    -1,    -1,    51,   454,   399,    52,
      -1,   457,    40,   458,    41,    -1,    31,    -1,    32,    -1,
      33,    -1,    34,    -1,    35,    -1,    -1,   456,    -1,   459,
      -1,   458,   459,    -1,   460,    -1,   452,    -1,   462,    -1,
     463,    -1,   462,    -1,   517,    -1,   183,    -1,   184,    -1,
     517,    -1,   507,    -1,   511,    -1,   515,    -1,   519,    -1,
     186,    -1,   465,    -1,   468,   467,    -1,    53,   468,    -1,
      -1,   467,   466,    -1,   471,   470,    -1,    54,   471,    -1,
      -1,   470,   469,    -1,   472,    -1,   475,   473,    -1,    -1,
     474,    -1,    55,   475,    -1,    56,   475,    -1,    57,   475,
      -1,    58,   475,    -1,    59,   475,    -1,    60,   475,    -1,
      66,   394,    -1,    65,    66,   394,    -1,   476,    -1,   482,
     481,    -1,   513,    -1,   514,    -1,    19,   484,    -1,    63,
     484,    -1,    -1,   478,    -1,    61,   482,    -1,    62,   482,
      -1,   477,   479,    -1,    -1,   481,   480,    -1,   484,   483,
      -1,    -1,   483,   478,    -1,    64,   485,    -1,    61,   485,
      -1,    62,   485,    -1,   485,    -1,   486,    -1,   487,    -1,
     505,    -1,   507,    -1,   511,    -1,   515,    -1,   462,    -1,
     500,    -1,    40,   464,    41,    -1,    76,    40,   464,    41,
      -1,    77,    40,   464,    41,    -1,    78,    40,   464,    48,
     464,    41,    -1,    79,    40,   464,    41,    -1,    80,    40,
     462,    41,    -1,    67,    40,   464,    41,    -1,    68,    40,
     464,    41,    -1,    69,   488,    -1,   116,   186,    -1,   140,
      40,   464,    41,    -1,   137,    40,   464,    41,    -1,   129,
      40,   464,    41,    -1,   123,    40,   464,    41,    -1,    88,
     394,    -1,   491,    -1,   143,    40,   464,    41,    -1,   141,
      40,   464,    41,    -1,   139,    40,   464,    41,    -1,   135,
      40,   464,    41,    -1,   126,    40,   464,    48,   464,    41,
      -1,   136,    40,   464,    48,   464,    41,    -1,   142,    40,
     464,    48,   464,    41,    -1,   111,    40,   464,    48,   464,
      41,    -1,   112,    40,   464,    48,   464,    41,    -1,   113,
      40,   464,    41,    -1,   145,    40,   464,    41,    -1,   138,
      40,   464,    41,    -1,   134,    40,   464,    41,    -1,   131,
      40,   464,    41,    -1,   127,    40,   464,    41,    -1,   122,
      40,   464,    41,    -1,   121,    40,   464,    41,    -1,   119,
     186,    -1,   107,   186,    -1,   108,   186,    -1,   109,    40,
     464,    41,    -1,   144,    40,   464,    41,    -1,   133,    40,
     464,    41,    -1,   124,    40,   464,    41,    -1,   117,    40,
     464,    41,    -1,    70,   394,    -1,    71,    40,   464,    48,
     464,    48,   464,    41,    -1,    72,    40,   464,    48,   464,
      41,    -1,    73,    40,   464,    48,   464,    41,    -1,    81,
      40,   464,    48,   464,    41,    -1,    82,    40,   464,    41,
      -1,    83,    40,   464,    41,    -1,    84,    40,   464,    41,
      -1,    85,    40,   464,    41,    -1,    99,    40,   464,    41,
      -1,   489,    -1,   492,    -1,   496,    -1,    40,   464,    41,
      -1,   186,    -1,    86,    40,   464,    48,   464,   490,    41,
      -1,    -1,   392,    -1,   132,    40,   464,    48,   464,   490,
      41,    -1,    -1,    -1,    -1,    74,   493,   494,   495,   337,
      -1,    -1,    -1,    -1,    65,    74,   497,   498,   499,   337,
      -1,    92,    40,   391,   501,    41,    -1,   502,    40,   391,
     464,    41,    -1,    97,    40,   391,   464,   504,    41,    -1,
      19,    -1,   464,    -1,    93,    -1,    94,    -1,    95,    -1,
      96,    -1,    98,    -1,    49,    75,    55,   516,    -1,    -1,
     503,    -1,   517,   506,    -1,    -1,   389,    -1,   516,   510,
      -1,    87,   517,    -1,   185,    -1,   508,    -1,    -1,   509,
      -1,   512,    -1,   513,    -1,   514,    -1,   165,    -1,   166,
      -1,   167,    -1,   168,    -1,   169,    -1,   170,    -1,   171,
      -1,   172,    -1,   173,    -1,   163,    -1,   164,    -1,   174,
      -1,   176,    -1,   175,    -1,   177,    -1,   178,    -1,   518,
      -1,   180,    -1,   179,    -1,   181,    -1,   182,    -1
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
     245,   247,   248,   255,   261,   263,   266,   268,   270,   271,
     273,   277,   280,   282,   284,   286,   289,   291,   294,   295,
     297,   302,   303,   305,   306,   308,   309,   311,   312,   314,
     318,   320,   323,   325,   327,   332,   334,   337,   339,   342,
     344,   348,   350,   353,   355,   357,   359,   361,   364,   366,
     368,   371,   374,   375,   377,   378,   380,   383,   386,   388,
     391,   392,   394,   395,   400,   401,   403,   406,   407,   409,
     411,   413,   415,   417,   419,   421,   423,   425,   427,   429,
     431,   435,   438,   439,   441,   445,   446,   448,   452,   456,
     462,   468,   474,   477,   480,   483,   489,   492,   493,   495,
     496,   498,   501,   503,   504,   507,   510,   513,   516,   518,
     521,   523,   526,   527,   529,   532,   534,   536,   538,   540,
     544,   548,   549,   553,   554,   556,   557,   559,   563,   564,
     567,   568,   569,   570,   579,   582,   585,   586,   588,   590,
     592,   594,   596,   597,   602,   605,   606,   608,   612,   613,
     616,   619,   622,   623,   625,   627,   629,   631,   633,   635,
     637,   639,   641,   643,   646,   647,   651,   652,   653,   654,
     661,   662,   663,   664,   672,   679,   682,   684,   686,   687,
     688,   695,   696,   699,   701,   702,   708,   709,   712,   714,
     718,   719,   722,   723,   728,   730,   731,   734,   736,   738,
     740,   742,   744,   746,   748,   749,   750,   755,   756,   757,
     762,   763,   767,   768,   771,   774,   776,   778,   780,   783,
     785,   786,   793,   794,   796,   799,   800,   803,   805,   806,
     812,   813,   817,   818,   822,   826,   829,   830,   832,   835,
     836,   839,   841,   842,   844,   846,   848,   851,   854,   855,
     858,   860,   861,   865,   866,   870,   871,   876,   878,   880,
     881,   885,   886,   888,   891,   892,   895,   897,   899,   901,
     903,   906,   909,   910,   913,   916,   919,   920,   923,   926,
     927,   929,   931,   934,   936,   938,   941,   944,   946,   949,
     953,   955,   957,   959,   962,   964,   966,   968,   971,   975,
     977,   980,   981,   984,   987,   988,   990,   992,   996,   998,
    1000,  1002,  1004,  1006,  1009,  1011,  1013,  1015,  1016,  1021,
    1026,  1028,  1030,  1032,  1034,  1036,  1037,  1039,  1041,  1044,
    1046,  1048,  1050,  1052,  1054,  1056,  1058,  1060,  1062,  1064,
    1066,  1068,  1070,  1072,  1074,  1077,  1080,  1081,  1084,  1087,
    1090,  1091,  1094,  1096,  1099,  1100,  1102,  1105,  1108,  1111,
    1114,  1117,  1120,  1123,  1127,  1129,  1132,  1134,  1136,  1139,
    1142,  1143,  1145,  1148,  1151,  1154,  1155,  1158,  1161,  1162,
    1165,  1168,  1171,  1174,  1176,  1178,  1180,  1182,  1184,  1186,
    1188,  1190,  1192,  1196,  1201,  1206,  1213,  1218,  1223,  1228,
    1233,  1236,  1239,  1244,  1249,  1254,  1259,  1262,  1264,  1269,
    1274,  1279,  1284,  1291,  1298,  1305,  1312,  1319,  1324,  1329,
    1334,  1339,  1344,  1349,  1354,  1359,  1362,  1365,  1368,  1373,
    1378,  1383,  1388,  1393,  1396,  1405,  1412,  1419,  1426,  1431,
    1436,  1441,  1446,  1451,  1453,  1455,  1457,  1461,  1463,  1471,
    1472,  1474,  1482,  1483,  1484,  1485,  1491,  1492,  1493,  1494,
    1501,  1507,  1513,  1520,  1522,  1524,  1526,  1528,  1530,  1532,
    1534,  1539,  1540,  1542,  1545,  1546,  1548,  1551,  1554,  1556,
    1558,  1559,  1561,  1563,  1565,  1567,  1569,  1571,  1573,  1575,
    1577,  1579,  1581,  1583,  1585,  1587,  1589,  1591,  1593,  1595,
    1597,  1599,  1601,  1603,  1605,  1607
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   478,   478,   481,   487,   492,   503,   504,   505,   506,
     510,   515,   519,   521,   525,   527,   530,   532,   536,   536,
     554,   560,   563,   567,   568,   569,   570,   576,   577,   580,
     582,   586,   590,   594,   595,   599,   600,   604,   604,   612,
     618,   622,   623,   626,   628,   632,   636,   640,   641,   645,
     646,   650,   650,   658,   664,   668,   671,   673,   677,   677,
     684,   686,   690,   693,   695,   699,   702,   705,   711,   717,
     719,   717,   729,   729,   741,   744,   752,   755,   758,   752,
     773,   781,   784,   791,   794,   799,   806,   809,   814,   821,
     824,   827,   830,   833,   836,   839,   843,   848,   851,   859,
     862,   869,   869,   880,   888,   891,   899,   902,   909,   912,
     917,   925,   932,   933,   937,   943,   949,   956,   963,   965,
     970,   977,   980,   985,   988,   993,   996,  1001,  1005,  1009,
    1016,  1019,  1026,  1029,  1032,  1035,  1041,  1047,  1050,  1057,
    1062,  1069,  1073,  1081,  1083,  1091,  1094,  1102,  1110,  1111,
    1118,  1122,  1130,  1133,  1138,  1141,  1145,  1151,  1157,  1161,
    1167,  1170,  1174,  1174,  1183,  1185,  1189,  1192,  1194,  1198,
    1199,  1200,  1201,  1202,  1203,  1204,  1205,  1206,  1207,  1208,
    1212,  1219,  1226,  1229,  1233,  1239,  1242,  1248,  1254,  1260,
    1266,  1272,  1278,  1286,  1294,  1301,  1310,  1316,  1319,  1323,
    1326,  1330,  1334,  1340,  1342,  1348,  1354,  1360,  1366,  1369,
    1375,  1378,  1383,  1385,  1389,  1395,  1398,  1401,  1404,  1411,
    1417,  1423,  1423,  1431,  1433,  1437,  1439,  1443,  1446,  1448,
    1453,  1458,  1461,  1453,  1472,  1476,  1479,  1481,  1485,  1486,
    1499,  1500,  1505,  1505,  1516,  1520,  1522,  1532,  1536,  1539,
    1555,  1560,  1564,  1567,  1571,  1572,  1573,  1574,  1575,  1576,
    1577,  1578,  1581,  1585,  1591,  1591,  1607,  1611,  1613,  1607,
    1624,  1628,  1630,  1624,  1641,  1652,  1658,  1659,  1663,  1665,
    1663,  1672,  1674,  1678,  1686,  1686,  1693,  1695,  1701,  1702,
    1705,  1707,  1713,  1713,  1718,  1724,  1726,  1730,  1733,  1736,
    1739,  1742,  1745,  1748,  1754,  1758,  1754,  1768,  1772,  1768,
    1782,  1782,  1794,  1796,  1800,  1810,  1811,  1812,  1816,  1824,
    1828,  1828,  1838,  1841,  1848,  1854,  1856,  1870,  1873,  1873,
    1883,  1883,  1886,  1886,  1893,  1898,  1902,  1904,  1909,  1913,
    1915,  1920,  1924,  1926,  1930,  1934,  1942,  1947,  1951,  1953,
    1957,  1965,  1965,  1968,  1968,  1974,  1974,  1980,  1981,  1985,
    1985,  1990,  1992,  1996,  1999,  2001,  2005,  2009,  2013,  2019,
    2023,  2027,  2030,  2032,  2036,  2040,  2045,  2047,  2053,  2056,
    2058,  2064,  2065,  2071,  2075,  2076,  2080,  2081,  2085,  2086,
    2090,  2091,  2092,  2093,  2097,  2101,  2104,  2107,  2110,  2116,
    2120,  2123,  2125,  2129,  2132,  2134,  2138,  2139,  2143,  2147,
    2148,  2152,  2153,  2154,  2158,  2163,  2164,  2168,  2168,  2181,
    2208,  2211,  2214,  2217,  2220,  2227,  2230,  2235,  2239,  2246,
    2247,  2251,  2254,  2258,  2261,  2267,  2268,  2272,  2275,  2278,
    2281,  2284,  2285,  2291,  2296,  2305,  2312,  2315,  2323,  2332,
    2339,  2342,  2349,  2354,  2367,  2371,  2375,  2379,  2383,  2387,
    2391,  2395,  2399,  2403,  2410,  2415,  2424,  2427,  2434,  2437,
    2444,  2447,  2452,  2455,  2459,  2473,  2476,  2484,  2493,  2496,
    2503,  2506,  2509,  2512,  2516,  2517,  2518,  2519,  2522,  2525,
    2528,  2531,  2535,  2541,  2544,  2547,  2550,  2553,  2556,  2559,
    2563,  2566,  2569,  2572,  2575,  2578,  2581,  2584,  2585,  2588,
    2591,  2594,  2597,  2600,  2603,  2606,  2609,  2612,  2615,  2618,
    2621,  2624,  2627,  2630,  2633,  2636,  2639,  2642,  2645,  2648,
    2651,  2654,  2657,  2660,  2663,  2666,  2669,  2672,  2675,  2678,
    2681,  2684,  2687,  2690,  2691,  2692,  2698,  2701,  2708,  2715,
    2718,  2722,  2728,  2731,  2734,  2728,  2747,  2750,  2753,  2747,
    2767,  2771,  2776,  2785,  2788,  2792,  2795,  2798,  2801,  2804,
    2810,  2816,  2819,  2823,  2833,  2836,  2841,  2849,  2856,  2860,
    2868,  2872,  2876,  2877,  2878,  2882,  2883,  2884,  2888,  2889,
    2890,  2894,  2895,  2896,  2900,  2901,  2905,  2906,  2907,  2908,
    2912,  2913,  2917,  2918,  2922,  2923
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
  const int SPARQLfedParser::yylast_ = 2462;
  const int SPARQLfedParser::yynnts_ = 333;
  const int SPARQLfedParser::yyempty_ = -2;
  const int SPARQLfedParser::yyfinal_ = 11;
  const int SPARQLfedParser::yyterror_ = 1;
  const int SPARQLfedParser::yyerrcode_ = 256;
  const int SPARQLfedParser::yyntokens_ = 187;

  const unsigned int SPARQLfedParser::yyuser_token_number_max_ = 441;
  const SPARQLfedParser::token_number_type SPARQLfedParser::yyundef_token_ = 2;


} // w3c_sw

/* Line 1136 of lalr1.cc  */
#line 5749 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 2929 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


