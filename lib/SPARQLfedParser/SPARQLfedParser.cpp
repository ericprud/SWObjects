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
#line 370 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"

/* Line 299 of lalr1.cc  */
#line 537 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lexWrapper

template <typename T>
std::string comma_str (const T c) {
    std::stringstream ss;
    for (typename T::const_iterator it = c.begin(); it != c.end(); ++it) {
	if (it != c.begin())
	    ss << ", ";
	ss << (*it)->str();
    }
    return ss.str();
}


/* Line 299 of lalr1.cc  */
#line 77 "lib/SPARQLfedParser/SPARQLfedParser.cpp"

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
#line 163 "lib/SPARQLfedParser/SPARQLfedParser.cpp"

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
#line 358 "lib/SPARQLfedParser/SPARQLfedParser.cpp"

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
#line 562 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 565 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 576 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	assert(driver.lastWhereClause != NULL);
	if ((yysemantic_stack_[(3) - (3)].p_ValuesClause) != NULL) // got a bindings clause
	    driver.lastWhereClause->m_GroupGraphPattern = 
		driver.makeConjunction(driver.lastWhereClause->m_GroupGraphPattern, (yysemantic_stack_[(3) - (3)].p_ValuesClause));
	(yyval.p_Operation) = (yysemantic_stack_[(3) - (2)].p_Operation);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 620 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.startBindingSet();
      }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 623 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  ResultSet* r = driver.endBindingSet();
	  if ((yysemantic_stack_[(3) - (1)].p_RSName) != NULL) {
	      std::string s = (yysemantic_stack_[(3) - (1)].p_RSName)->name;
	      delete (yysemantic_stack_[(3) - (1)].p_RSName);
	      driver.bindingsMap[s] = r;
	      driver.curOp = (yysemantic_stack_[(3) - (2)].p_TableOperation);
	  } else {
	      // if ($<p_TableOperation>2 != NULL)
	      driver.curOp = driver.makeConjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), new ValuesClause(r));
	  }
      }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 638 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = (yysemantic_stack_[(2) - (1)].p_RSName);
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 644 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = NULL;
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 654 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	throw std::runtime_error("need to partition out results set part of SimpleEngine::loadDataOrResults");
    }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 689 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 691 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 697 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 736 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 738 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 744 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 763 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow(false);
      }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 765 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 785 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 788 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 791 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 797 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 803 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 805 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 807 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 815 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 818 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.validate & SPARQLfedDriver::VALIDATE_selectGrouped) {
	    const ExpressionAliasList* e = (yysemantic_stack_[(5) - (5)].p_SolutionModifier)->getGroupedBy();
	    if (e) {
		std::set<const TTerm*> errorSet = (yysemantic_stack_[(5) - (2)].p_Project).varSet->getNonProjectableVars(e, driver.atomFactory);
		if (errorSet.size() != 0)
		    error(yylloc, "can't select " + comma_str(errorSet) + " because "
			  + (errorSet.size() == 1 ? "it's" : "they're") + "not in a GROUP BY.");
	    }
	}
	if (driver.validate & SPARQLfedDriver::VALIDATE_noReassign) {
	    struct CreatedVars : public TestExpressor {
		std::set<const TTerm*> vars;
		virtual void variable (const Variable* const self, std::string)
		{ vars.insert(self); }
		virtual void expressionAlias (const ExpressionAlias* const,
					      const Expression*, const Bindable* label)
		{ if (label != NULL) label->express(this); }
	    };
	    CreatedVars cv;
	    (yysemantic_stack_[(5) - (2)].p_Project).varSet->express(&cv);

	    const BindingState& nested = (yysemantic_stack_[(5) - (4)].p_WhereClause)->m_GroupGraphPattern->getBindingState();
	    std::set<const TTerm*> known;
	    std::copy(nested.binds   .begin(), nested.binds   .end(), std::inserter(known, known.begin()));
	    std::copy(nested.optional.begin(), nested.optional.end(), std::inserter(known, known.begin()));

	    std::set<const TTerm*> errorSet;
	    std::set_intersection(cv.vars.begin(), cv.vars.end(), known.begin(), known.end(), std::inserter(errorSet, errorSet.begin()));
	    if (errorSet.size() != 0)
		error(yylloc, "select can't bind " + comma_str(errorSet) + " because "
		      + (errorSet.size() == 1 ? "it's" : "they're") + " bound in the WHERE clause.");
	}
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause);
	(yyval.p_Operation) = new Select((yysemantic_stack_[(5) - (2)].p_Project).distinctness, (yysemantic_stack_[(5) - (2)].p_Project).varSet, (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
	driver.countStar = (yysemantic_stack_[(5) - (1)].p_parentCountStar);
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 859 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 862 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 870 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
      }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 873 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 877 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if (!driver.curGraphName || (yysemantic_stack_[(3) - (2)].p_Project).varSet->includes(driver.curGraphName)) {
	      (yyval.p_GraphName) = NULL;
	  } else {
	      (yyval.p_GraphName) = driver.curGraphName;
	      driver.curGraphName = driver.createBNode();
	  }
      }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 884 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if ((yysemantic_stack_[(7) - (4)].p_GraphName) != NULL)
	      driver.curGraphName = (yysemantic_stack_[(7) - (4)].p_GraphName);
	  if ((yysemantic_stack_[(7) - (7)].p_ValuesClause) != NULL)
	      (yysemantic_stack_[(7) - (5)].p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yysemantic_stack_[(7) - (5)].p_WhereClause)->m_GroupGraphPattern, (yysemantic_stack_[(7) - (7)].p_ValuesClause));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (3)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(7) - (2)].p_Project).distinctness, (yysemantic_stack_[(7) - (2)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(7) - (5)].p_WhereClause), (yysemantic_stack_[(7) - (6)].p_SolutionModifier))));
	  driver.countStar = (yysemantic_stack_[(7) - (1)].p_parentCountStar);
      }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 896 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 908 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 911 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 918 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 926 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 933 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 941 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.validate & SPARQLfedDriver::VALIDATE_namedProjection && (yysemantic_stack_[(4) - (3)].p_Variable) == NULL)
	    error(yylloc, (yysemantic_stack_[(4) - (2)].p_Expression)->str() + " must be selected AS some variable");
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 955 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.validate & SPARQLfedDriver::VALIDATE_namedProjection)
	    error(yylloc, (yysemantic_stack_[(1) - (1)].p_Expression)->str() + " must be selected AS some variable");
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 960 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.validate & SPARQLfedDriver::VALIDATE_namedProjection)
	    error(yylloc, (yysemantic_stack_[(1) - (1)].p_RDFLiteral)->str() + " must be selected AS some variable");
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 965 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.validate & SPARQLfedDriver::VALIDATE_namedProjection)
	    error(yylloc, (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)->str() + " must be selected AS some variable");
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 970 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.validate & SPARQLfedDriver::VALIDATE_namedProjection)
	    error(yylloc, (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)->str() + " must be selected AS some variable");
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 975 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 978 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.validate & SPARQLfedDriver::VALIDATE_namedProjection)
	    error(yylloc, (yysemantic_stack_[(1) - (1)].p_Expression)->str() + " must be selected AS some variable");
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 983 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.validate & SPARQLfedDriver::VALIDATE_namedProjection)
	    error(yylloc, (yysemantic_stack_[(1) - (1)].p_Expression)->str() + " must be selected AS some variable");
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 994 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 997 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1005 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.validate & SPARQLfedDriver::VALIDATE_uniqueProjection) {
	    std::set<const TTerm*> labels;
	    for (std::vector<const ExpressionAlias*>::const_iterator it = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList)->begin();
		 it != (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList)->end(); ++it) {
		const TTerm* label = (*it)->getLabel(driver.atomFactory);
		if (labels.find(label) != labels.end())
		    error(yylloc, label->str() + " duplicated in select list.");
		labels.insert(label);
	    }
	}
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1018 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1024 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(2) - (2)].p_Operation);
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1030 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.validate & SPARQLfedDriver::VALIDATE_constructNoQuads &&
	    dynamic_cast<const DefaultGraphPattern*>((yysemantic_stack_[(4) - (1)].p_TableOperation)) == NULL) {
	    error(yylloc, "can't CONSTRUCT quad pattern " + (yysemantic_stack_[(4) - (1)].p_TableOperation)->str() + ".");
	}
	driver.lastWhereClause = (yysemantic_stack_[(4) - (3)].p_WhereClause);
	/* $1 is NO LONGER known to be a DefaultGraphPattern because of grammar restrictions. */
	(yyval.p_Operation) = new Construct((yysemantic_stack_[(4) - (1)].p_TableOperation), (yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1039 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.validate & SPARQLfedDriver::VALIDATE_constructNoQuads &&
	    dynamic_cast<const DefaultGraphPattern*>((yysemantic_stack_[(4) - (3)].p_TableOperation)) == NULL) {
	    error(yylloc, "can't re-CONSTRUCT quad pattern " + (yysemantic_stack_[(4) - (3)].p_TableOperation)->str() + ".");
	}
	SWObjectDuplicator dup(driver.atomFactory);
	(yysemantic_stack_[(4) - (3)].p_TableOperation)->express(&dup);
	driver.lastWhereClause = new WhereClause((yysemantic_stack_[(4) - (3)].p_TableOperation));
	(yyval.p_Operation) = new Construct(dup.last.tableOperation, (yysemantic_stack_[(4) - (1)].p_DatasetClauses), driver.lastWhereClause, (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1053 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause) ? (yysemantic_stack_[(5) - (4)].p_WhereClause) : new WhereClause(new DefaultGraphPattern());
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1062 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm))));
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1065 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_TTerm))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1073 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1076 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1083 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1091 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(4) - (3)].p_WhereClause);
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1099 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1111 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1117 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1123 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1130 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.ensureGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1144 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1151 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1159 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1167 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1175 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1183 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1190 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1193 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1200 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1203 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1206 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1215 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1221 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1227 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1230 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1242 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1249 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1253 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1263 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1271 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1274 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1282 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1291 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1298 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1302 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1310 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1318 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 1325 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1331 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 1341 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ValuesClause) = (yysemantic_stack_[(2) - (2)].p_ValuesClause);
    }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1347 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ValuesClause) = NULL;
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1354 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Operation) = driver.root;
      }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1369 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	OperationSet* ret = driver.root ? dynamic_cast<OperationSet*>(driver.root) : new OperationSet();
	ret->push_back((yysemantic_stack_[(1) - (1)].p_Operation));
	driver.root = ret;
	std::copy(driver.bnodesInThisOpperation.begin(), driver.bnodesInThisOpperation.end(),
		  std::inserter(driver.bnodesInOldOpperations, driver.bnodesInOldOpperations.begin()));
      }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1398 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(4) - (2)].p_Silence), (yysemantic_stack_[(4) - (3)].p_URI), (yysemantic_stack_[(4) - (4)].p_URI));
    }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1404 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1407 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1414 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1421 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1428 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1434 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1440 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1446 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1452 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1458 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1464 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.inINSERTDATA = true;
      }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1466 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.inINSERTDATA = false;
	  (yyval.p_Operation) = new Insert((yysemantic_stack_[(3) - (3)].p_TableOperation), NULL);
	  driver.curOp = NULL;
	  driver.curBGP = NULL;
	}
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1475 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.inDELETEDATA = true;
      }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1477 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.inDELETEDATA = false;
	  (yyval.p_Operation) = new Delete(true, (yysemantic_stack_[(3) - (3)].p_TableOperation), NULL);
	  driver.curOp = NULL;
	  driver.curBGP = NULL;
	}
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1486 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.inDELETEWHERE = true;
      }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1488 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.inDELETEWHERE = false;
	  (yyval.p_Operation) = new Delete(true, (yysemantic_stack_[(3) - (3)].p_TableOperation), NULL);
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1497 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(6) - (2)].p_DeleteInsert).del, (yysemantic_stack_[(6) - (2)].p_DeleteInsert).ins, new WhereClause(driver.ensureGraphPattern()), (yysemantic_stack_[(6) - (4)].p_TableOperation), (yysemantic_stack_[(6) - (1)].p_URI), (yysemantic_stack_[(6) - (3)].p_UsingPairs));
	driver.curOp = NULL;
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 1505 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1511 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1518 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1525 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1529 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1536 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_UsingPairs) = NULL;
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1539 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (1)].p_UsingPairs) == NULL)
	    (yysemantic_stack_[(2) - (1)].p_UsingPairs) = new std::vector<s_UsingPair>();
	(yysemantic_stack_[(2) - (1)].p_UsingPairs)->push_back((yysemantic_stack_[(2) - (2)].p_UsingPair));
	(yyval.p_UsingPairs) = (yysemantic_stack_[(2) - (1)].p_UsingPairs);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 1548 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(2) - (2)].p_TableOperation);
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1554 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = NULL;
    }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 1561 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.inDELETECLAUSE = true;
      }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 1563 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.inDELETECLAUSE = false;
	  (yyval.p_Delete) = new Delete(false, (yysemantic_stack_[(3) - (3)].p_TableOperation), NULL);
      }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 1570 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.inINSERTQUAD = true;
      }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 1572 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.inINSERTQUAD = false;
	  (yyval.p_Insert) = new Insert((yysemantic_stack_[(3) - (3)].p_TableOperation), NULL);
      }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 1579 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_UsingPair) = (yysemantic_stack_[(2) - (2)].p_UsingPair);
    }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1585 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_UsingPair).named = false;
	(yyval.p_UsingPair).name = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 1589 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_UsingPair).named = true;
	(yyval.p_UsingPair).name = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 222:

/* Line 690 of lalr1.cc  */
#line 1596 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 223:

/* Line 690 of lalr1.cc  */
#line 1599 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 1610 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 1616 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 228:

/* Line 690 of lalr1.cc  */
#line 1619 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = driver.atomFactory->getURI("tag:eric@w3.org,2012-swobjparm/DEFAULT");
    }
    break;

  case 229:

/* Line 690 of lalr1.cc  */
#line 1622 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = driver.atomFactory->getURI("tag:eric@w3.org,2012-swobjparm/NAMED");
    }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 1625 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = driver.atomFactory->getURI("tag:eric@w3.org,2012-swobjparm/ALL");
    }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 1632 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
	driver.curOp = NULL;
    }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 1639 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
    }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 1645 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 1647 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TableOperation) = driver.ensureGraphPattern();
	  driver.curOp = NULL;
      }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 1676 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 1681 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 1684 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 1687 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.ensureGraphPattern()));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 1709 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	BindingsMap::const_iterator rs = driver.bindingsMap.find((yysemantic_stack_[(1) - (1)].p_RSName)->name);
	if (rs == driver.bindingsMap.end())
	    error(yylloc, std::string("") + "unknown named result set " + (yysemantic_stack_[(1) - (1)].p_RSName)->name);
	ResultSet* copy = new ResultSet(*rs->second);
	delete (yysemantic_stack_[(1) - (1)].p_RSName);
	ValuesClause* b = new ValuesClause(copy);
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, b) : b;
      }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 1729 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 1731 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 1805 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_ValuesClause)) : (yysemantic_stack_[(1) - (1)].p_ValuesClause);
    }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 1812 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Print(driver.ensureGraphPattern());
    }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 1818 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 1822 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 283:

/* Line 690 of lalr1.cc  */
#line 1834 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 1838 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_FilterExpressions) = driver.saveFilter();
      }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 1840 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 1843 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_FilterExpressions));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.ensureGraphPattern()));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 1851 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 1855 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_FilterExpressions) = driver.saveFilter();
      }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 1857 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_FilterExpressions));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(6) - (5)].p_TTerm), driver.ensureGraphPattern(), (yysemantic_stack_[(6) - (4)].p_Silence), driver.atomFactory, false));
      }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 1864 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 1868 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_FilterExpressions) = driver.saveFilter();
      }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 1870 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  /*
	    serviceID,
	    from,
	    e_Silence
	    where
	   */
	  driver.lastWhereClause = (yysemantic_stack_[(8) - (8)].p_WhereClause);
	  driver.restoreFilter((yysemantic_stack_[(8) - (3)].p_FilterExpressions));
	  driver.curOp = driver.makeConjunction
	      ((yysemantic_stack_[(8) - (2)].p_TableOperation), new SADIGraphPattern((yysemantic_stack_[(8) - (5)].p_TTerm), (yysemantic_stack_[(8) - (4)].p_Silence), (yysemantic_stack_[(8) - (7)].p_TableOperation), (yysemantic_stack_[(8) - (8)].p_WhereClause)));
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 1885 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	const TableOperation* op = driver.ensureGraphPattern();
	if (driver.validate & SPARQLfedDriver::VALIDATE_noReassign &&
	    (op->getBindingState().binds   .find((yysemantic_stack_[(6) - (5)].p_Variable)) != op->getBindingState().binds   .end() ||
	     op->getBindingState().optional.find((yysemantic_stack_[(6) - (5)].p_Variable)) != op->getBindingState().optional.end()))
	    error(yylloc, "Can't bind " + (yysemantic_stack_[(6) - (5)].p_Variable)->str() + " to " + (yysemantic_stack_[(6) - (3)].p_Expression)->str() + " because it's already bound");
	driver.curOp = new Bind(op, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
	// no more triples go into the current BGP, per
	//   http://www.w3.org/TR/sparql11-query/#sparqlTranslateGraphPatterns
	// test reference:
	//   http://www.sparql.org/query-validator?query=ASK+{+%3Fs+%3Fp+%3Fo+FILTER+%281%29+BIND+%282+AS+%3Fb%29+%3Fs2+%3Fp2+%3Fo2+FILTER+%283%29+BIND+%284+AS+%3Fd%29}&languageSyntax=SPARQL&outputFormat=algebra&linenumbers=false
	driver.curBGP = NULL;
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 1901 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ValuesClause) = (yysemantic_stack_[(2) - (2)].p_ValuesClause);
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 1912 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 1914 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
      }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 1916 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ValuesClause) = new ValuesClause(driver.endBindingSet());
      }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 1927 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
	driver.endBindingRow();
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 1935 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
    }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 1937 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ValuesClause) = new ValuesClause(driver.endBindingSet());
      }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 1944 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 1956 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 1962 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 1964 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 1967 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 1979 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 1982 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 1985 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 1988 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 1991 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 1994 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 1997 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 2003 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 2007 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_FilterExpressions) = driver.saveFilter();
      }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 2009 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_FilterExpressions));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 2017 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 2021 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_FilterExpressions) = driver.saveFilter();
      }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 2023 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_FilterExpressions));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 2031 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 2036 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.ensureGraphPattern());
      }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 2049 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    driver.ensureGraphPattern();
	    driver.curFilter = new FilterExpressions();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 2065 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 2073 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 2077 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 2080 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yysemantic_stack_[(6) - (4)].p_Expressions);
      }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 2087 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 2090 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 2097 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 2105 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 2120 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 2123 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 2126 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(5) - (3)].p_Expressions);
      }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 2133 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 2136 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 2178 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 2182 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::RDF_type;
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 2205 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)), true);
    }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 2213 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 2216 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 2231 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 2242 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 2262 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	const URI* t = (yysemantic_stack_[(1) - (1)].p_PropertyPath)->release();
	// if (!t)
	//     w3c_sw_LINEN << "property path: " << $1->str() << "\n";
	(yyval.p_TTerm) = t ? t : (const TTerm*)new PropertyPath((yysemantic_stack_[(1) - (1)].p_PropertyPath));
    }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 2271 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 2290 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)), true);
    }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 2301 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = driver.lastPropertyPathAlternative;
	driver.lastPropertyPathAlternative = (yysemantic_stack_[(1) - (1)].p_PropertyPath);
      }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 2304 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (3)].p_PropertyPath) ? (yysemantic_stack_[(3) - (3)].p_PropertyPath) : (yysemantic_stack_[(3) - (1)].p_PropertyPath);
	  driver.lastPropertyPathAlternative = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
      }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 2311 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(2) - (2)].p_PropertyPath);
    }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 2317 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = NULL;
    }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 2320 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Alternative((yysemantic_stack_[(2) - (1)].p_PropertyPath) ? (yysemantic_stack_[(2) - (1)].p_PropertyPath) : driver.lastPropertyPathAlternative, (yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 2326 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = driver.lastPropertyPathSequence;
	driver.lastPropertyPathSequence = (yysemantic_stack_[(1) - (1)].p_PropertyPath);
      }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 2329 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {	
	  (yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (3)].p_PropertyPath) ? (yysemantic_stack_[(3) - (3)].p_PropertyPath) : (yysemantic_stack_[(3) - (1)].p_PropertyPath);
	  driver.lastPropertyPathSequence = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
      }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 2336 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(2) - (2)].p_PropertyPath);
    }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 2342 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = NULL;
    }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 2345 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Sequence((yysemantic_stack_[(2) - (1)].p_PropertyPath) ? (yysemantic_stack_[(2) - (1)].p_PropertyPath) : driver.lastPropertyPathSequence, (yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 2351 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(2) - (2)].p_RepeatRange).min == 1 && (yysemantic_stack_[(2) - (2)].p_RepeatRange).max == 1 ? (yysemantic_stack_[(2) - (1)].p_PropertyPath) : new PropertyPath::Repeated((yysemantic_stack_[(2) - (1)].p_PropertyPath), (yysemantic_stack_[(2) - (2)].p_RepeatRange).min, (yysemantic_stack_[(2) - (2)].p_RepeatRange).max);
    }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 2357 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RepeatRange).min = 1; (yyval.p_RepeatRange).max = 1;
    }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 2365 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Inverse((yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 2371 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RepeatRange).min = 0; (yyval.p_RepeatRange).max = 1;
    }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 2374 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RepeatRange).min = 0; (yyval.p_RepeatRange).max = PropertyPath::Repeated::Unlimited;
    }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 2377 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RepeatRange).min = 1; (yyval.p_RepeatRange).max = PropertyPath::Repeated::Unlimited;
    }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 2383 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 2386 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate(TTerm::RDF_type);
    }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 2389 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Negated((yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 2392 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
    }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 2402 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
    }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 2411 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(2) - (2)].p_PropertyPath);
    }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 2417 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = NULL;
    }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 2420 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Alternative((yysemantic_stack_[(2) - (1)].p_PropertyPath) ? (yysemantic_stack_[(2) - (1)].p_PropertyPath) : driver.lastPropertyPathSetAlternative, (yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 2426 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = driver.lastPropertyPathSetAlternative;
	driver.lastPropertyPathSetAlternative = (yysemantic_stack_[(1) - (1)].p_PropertyPath);
      }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 2429 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.lastPropertyPathSetAlternative = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
	  (yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (3)].p_PropertyPath);
      }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 2436 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = NULL;
    }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 2443 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 2446 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate(TTerm::RDF_type);
    }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 2449 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Inverse((yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 2455 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 2458 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate(TTerm::RDF_type);
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 2471 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 2475 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 2484 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(4) - (1)].p_listModifier) == LIST_exact) {
	    (yyval.p_TTerm) = driver.createBNode();
	    const TTerm* tail = (yyval.p_TTerm);
	    ProductionVector<const TTerm*>* members = (yysemantic_stack_[(4) - (3)].p_TTerms);
	    driver.ensureBasicGraphPattern();
	    for (unsigned i = 0; i < members->size(); i++) {
		// driver.curBGP->addTriplePattern
		//     (driver.atomFactory->getTriple(tail, TTerm::RDF_type, TTerm::RDF_List), true);
		driver.curBGP->addTriplePattern
		    (driver.atomFactory->getTriple(tail, TTerm::RDF_first, members->at(i)), true);
		const TTerm* nextTail = i == members->size()-1 ? (const TTerm*)TTerm::RDF_nil : driver.createBNode();
		driver.curBGP->addTriplePattern
		    (driver.atomFactory->getTriple(tail, TTerm::RDF_rest, nextTail), true);
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
#line 2512 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 2515 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 2518 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 2521 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 2524 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 2531 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 2539 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 2543 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 2555 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 2559 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject;
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 2567 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(4) - (1)].p_listModifier) == LIST_exact) {
	    (yyval.p_TTerm) = driver.createBNode();
	    const TTerm* tail = (yyval.p_TTerm);
	    ProductionVector<const TTerm*>* members = (yysemantic_stack_[(4) - (3)].p_TTerms);
	    driver.ensureBasicGraphPattern();
	    for (unsigned i = 0; i < members->size(); i++) {
		// driver.curBGP->addTriplePattern
		//     (driver.atomFactory->getTriple(tail, TTerm::RDF_type, TTerm::RDF_List), true);
		driver.curBGP->addTriplePattern
		    (driver.atomFactory->getTriple(tail, TTerm::RDF_first, members->at(i)), true);
		const TTerm* nextTail = i == members->size()-1 ? (const TTerm*)TTerm::RDF_nil : driver.createBNode();
		driver.curBGP->addTriplePattern
		    (driver.atomFactory->getTriple(tail, TTerm::RDF_rest, nextTail), true);
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

  case 451:

/* Line 690 of lalr1.cc  */
#line 2594 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 2598 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 2615 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 2622 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 2625 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 2636 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 2639 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 2642 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 2645 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 2649 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::RDF_nil; // !!! new GraphTerm_rule5($1);
    }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 2660 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 2669 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 2676 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 2679 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 2687 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 2696 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 2703 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 2706 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 2718 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 480:

/* Line 690 of lalr1.cc  */
#line 2731 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = NULL;
    }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 2739 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 2743 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 2747 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 2751 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 2755 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 2759 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 2763 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 2767 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = true;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 2779 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 2788 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 2791 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 2798 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 2801 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 2808 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 2816 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 2819 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 2823 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 501:

/* Line 690 of lalr1.cc  */
#line 2837 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 2840 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 2848 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 2857 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 2860 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 2867 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 2870 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 2873 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 2883 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 2886 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 2889 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 2892 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 2899 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 2911 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 2914 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 2917 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 2920 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 2923 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 2926 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
      (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), new TTermExpression(driver.atomFactory->getURI(driver.getBase())), NULL));
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 2929 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
      (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), new TTermExpression(driver.atomFactory->getURI(driver.getBase())), NULL));
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 2933 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 2936 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 2939 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 2942 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ceil, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 2945 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 2948 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 2951 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 2955 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 2959 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 2962 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 2965 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 2968 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 2971 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 2974 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 2977 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 2980 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 2983 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 2986 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 2989 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 2992 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 2995 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 2998 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 3001 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 3004 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_tz, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 3007 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 3010 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_uuid, NULL, NULL, NULL));
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 3013 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_struuid, NULL, NULL, NULL));
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 3016 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 3019 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 3022 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 3025 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 3028 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 3031 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 3034 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 3037 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 3040 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 3043 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 3046 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 3049 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 3052 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 3055 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 3058 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 3069 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 3078 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 3085 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 3092 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 3099 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 3105 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_replace, (yysemantic_stack_[(9) - (3)].p_Expression), (yysemantic_stack_[(9) - (5)].p_Expression), (yysemantic_stack_[(9) - (7)].p_Expression))); // !! , $8
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 3111 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 3114 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 3118 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expression) = new ExistsExpression(driver.ensureGraphPattern());
	  driver.curOp = (yysemantic_stack_[(4) - (3)].p_TableOperation);
	  driver.countStar = (yysemantic_stack_[(4) - (2)].p_parentCountStar);
      }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 3126 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
      }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 3129 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 3133 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  // $$ = new ExistsExpression(false, driver.ensureGraphPattern());
	  (yyval.p_Expression) = new BooleanNegation(new ExistsExpression(driver.ensureGraphPattern()));
	  driver.curOp = (yysemantic_stack_[(5) - (4)].p_TableOperation);
	  driver.countStar = (yysemantic_stack_[(5) - (3)].p_parentCountStar);
      }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 3142 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 3150 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 3159 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  AggregateCall::ScalarVals svals;
	  if ((yysemantic_stack_[(6) - (5)].p_RDFLiteral) != NULL)
	      svals["separator"] = (yysemantic_stack_[(6) - (5)].p_RDFLiteral)->getLexicalValue();
	  (yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression), svals));
    }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 3175 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 3182 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 3185 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 3188 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 3191 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 3194 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 3200 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 3206 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 3213 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 3223 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 3231 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 3239 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 3246 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 3250 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 3258 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 3312 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.validate & SPARQLfedDriver::VALIDATE_bnodeScope) {
	    driver.ensureBasicGraphPattern();

	    // prohibit e.g. ASK WHERE { {_:x :a :b } {_:x :c :d } }
	    // but not:
	    //   INSERT { _:b :a :b } WHERE {}; INSERT { _:b :c :d } WHERE {};
	    //   INSERT DATA { _:b :a :b }; INSERT DATA { _:b :c :d };
	    //   INSERT DATA { GRAPH <g1>{_:b :a :b } GRAPH <g2>{ _:b :c :d } }
	    if (!driver.inINSERTQUAD && !driver.inINSERTDATA) {
		std::map<const TTerm*, BasicGraphPattern*>::const_iterator lastUse
		    = driver.bnode2bgp.find((yysemantic_stack_[(1) - (1)].p_TTerm));
		if (lastUse != driver.bnode2bgp.end() &&
		    lastUse->second != driver.curBGP)
		    error((yyloc), "bnode " + (yysemantic_stack_[(1) - (1)].p_TTerm)->str() +
			  " already scoped to " + lastUse->second->str());
		else
		    driver.bnode2bgp.insert(std::make_pair((yysemantic_stack_[(1) - (1)].p_TTerm), driver.curBGP));
	    }

	    // prohibit INSERT DATA { _:b1 :a :b };INSERT DATA { _:b1 :c :c }
	    // but not:
	    //   INSERT { _:b :a :b } WHERE { {_:b :a :b} }; INSERT { _:b :c :d } WHERE { {_:b :a :b} }
	    if (!driver.inINSERTQUAD) {
		if (driver.bnodesInOldOpperations.find((yysemantic_stack_[(1) - (1)].p_TTerm))
		    != driver.bnodesInOldOpperations.end())
		    error((yyloc), "bnode " + (yysemantic_stack_[(1) - (1)].p_TTerm)->str() +
			  " already scoped to an earlier opperation");
		else
		    driver.bnodesInThisOpperation.insert((yysemantic_stack_[(1) - (1)].p_TTerm));
	    }
	}
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;



/* Line 690 of lalr1.cc  */
#line 4366 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -860;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        49,   -96,   105,  -860,  -860,  -860,   569,  -860,  -860,  -860,
    -860,  -860,   104,   104,   104,   104,    61,    17,  -860,   132,
     104,   104,   104,  -860,  -860,  -860,   102,  -860,   146,  -860,
    -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,  -860,  -860,  -860,  -860,  -860,    85,   143,  -860,
     132,   137,   161,   137,  -860,    57,  -860,  -860,  -860,  -860,
    -860,  -860,  -860,  -860,   155,  -860,  -860,  -860,  -860,  -860,
      60,  -860,    46,    46,    46,   111,   111,    61,    -1,  -860,
    -860,  -860,   106,  -860,   163,  -860,  -860,  -860,   207,  -860,
    -860,   199,  -860,   206,   132,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,   189,   231,    24,    61,  -860,    60,  -860,    67,
    -860,   159,     7,  -860,  -860,   117,   132,   123,   145,  -860,
    -860,  -860,  -860,  -860,  -860,    63,  -860,     0,  -860,  -860,
    -860,  1838,    60,    49,  -860,  -860,    61,    61,    36,  -860,
    -860,    76,   203,  -860,  -860,  -860,   161,  -860,  -860,  -860,
    -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,  -860,  -860,  -860,  -860,  -860,   240,  -860,  -860,
    -860,  -860,   230,  -860,  -860,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,   -34,  -860,  -860,   132,  -860,  -860,  -860,  -860,
    -860,   159,   159,   159,  -860,   265,  -860,   211,  -860,  -860,
    -860,  -860,  -860,    46,  -860,    46,    46,   258,  -860,  -860,
    -860,   262,  -860,  2267,   225,   268,   273,     1,    13,   287,
     288,   291,   295,  -860,   299,   304,   305,   307,   313,   314,
     318,   320,   322,   324,   325,    13,   327,  -860,  -860,  -860,
    -860,   328,  -860,   331,   185,   187,   335,   339,   348,   350,
     232,   351,   234,   375,   381,   382,   383,   385,   386,   388,
     389,   390,   394,   395,   396,   397,   398,   400,   402,   405,
     406,   408,   410,   411,   412,  -860,  -860,  2386,  -860,  -860,
    -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,   413,  -860,
    -860,  -860,    22,   159,   517,  -860,  -860,  -860,    61,    27,
    -860,   415,  -860,  -860,  -860,   330,  -860,    98,   451,   231,
    -860,  -860,    98,  2099,    98,   132,  -860,  -860,  -860,  -860,
    -860,  -860,  -860,  -860,  2624,  2708,   306,  -860,  1334,  -860,
    -860,  -860,  -860,   421,    31,  -860,  2267,  2505,  2505,  2505,
    -860,   368,  -860,  -860,  -860,  -860,   594,  -860,  -860,  -860,
    -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,    22,  -860,
    2267,  2267,  2267,  -860,  -860,  2267,  -860,  -860,  2267,  2267,
    2267,  2267,  -860,  2267,  2267,  2267,  2267,    63,  2267,  2267,
    2267,  2267,  2267,  2267,  -860,   444,   444,  2267,  -860,  -860,
    2267,  2267,  2267,  2267,  -860,  2267,  -860,  2267,  2267,  2267,
    2267,  2267,  2267,  2267,  2267,  2267,  2267,  2267,  2267,  2267,
    2267,  2267,  2267,  2267,  2267,  2267,  2267,  2267,  2267,  -860,
     444,   444,  -860,  -860,  -860,  -860,   132,  -860,  -860,     7,
     285,  -860,   834,  -860,  -860,  1484,  -860,  -860,   360,  -860,
    -860,   311,  -860,  -860,  -860,  -860,   416,  2099,  -860,  -860,
    1050,   460,  -860,  -860,  -860,  -860,  -860,  1228,  -860,  -860,
    -860,  -860,  2267,  2624,  -860,  -860,  -860,  -860,  2708,  -860,
    -860,  -860,  -860,  -860,   442,   208,  -860,  -860,  -860,  -860,
     146,   433,  -860,  -860,  -860,    64,   431,  -860,  -860,  -860,
    -860,  -860,  -860,  -860,    -2,   435,  -860,  -860,  -860,    63,
    -860,   437,   426,   420,  2267,  2267,  2267,  2267,  2267,  2267,
     418,    13,  -860,  -860,   319,    29,  -860,  -860,  -860,   452,
     455,   456,  -860,   450,   453,   454,   458,     7,   459,   463,
     462,   471,   473,   467,   477,   479,   480,   482,   476,  -860,
    1698,  2267,   485,   488,   483,   486,   492,   494,   495,   496,
     498,   499,   500,   501,   502,   505,   507,   506,   509,   512,
     508,   516,   520,   521,   522,   524,   518,   526,   528,   531,
    2267,  2267,  -860,  -860,  -860,   142,  -860,  -860,  -860,  2048,
    -860,  -860,   472,  -860,  -860,  -860,  -860,  -860,  -860,  2048,
    -860,  -860,   346,  -860,    52,  -860,    34,  -860,  -860,  -860,
    -860,   449,  -860,   231,   155,  -860,  -860,   368,  -860,  -860,
    1959,   414,   419,  -860,  -860,   555,   558,    70,  -860,  -860,
     131,   544,  2023,  -860,  -860,  2123,    70,    70,   869,  -860,
    -860,  -860,  -860,  -860,  -860,  -860,  2267,  -860,  2267,  -860,
    -860,  -860,  -860,  -860,  -860,  -860,    13,  -860,  2267,  2267,
      29,  -860,  -860,  -860,  2267,  2267,  -860,     7,  -860,  -860,
    -860,  -860,  2267,  2267,  2267,  2267,  -860,  -860,  -860,  2267,
    -860,  -860,  2267,  -860,  -860,  -860,  -860,  2267,  -860,  -860,
     547,   543,  -860,  -860,  2267,  2267,  -860,  -860,  -860,  -860,
    -860,  -860,  2267,  -860,  -860,  -860,  2267,  -860,  -860,  -860,
    2267,  -860,  -860,  -860,  -860,  -860,  2267,  -860,  -860,  -860,
     552,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,   -25,
     554,  -860,  -860,  -860,   108,   557,  -860,  -860,  -860,   549,
     556,  -860,  -860,  -860,   562,  -860,  -860,  1959,  -860,   565,
    -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,
      62,  -860,    43,    95,   559,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,  -860,    54,  -860,  -860,  -860,  -860,  -860,  -860,
      -1,  -860,  -860,  2708,   566,     7,  -860,  1518,  -860,  -860,
    -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  2023,
    -860,  -860,  2075,  -860,  -860,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,  -860,    20,   575,   572,   583,   577,   585,   587,
     588,  -860,   534,  -860,   590,   600,   601,   602,   588,   604,
     615,  -860,  -860,  -860,  -860,  -860,  -860,   834,  -860,  -860,
    -860,  1484,    98,  -860,  2099,  -860,   599,  -860,  -860,  -860,
     616,   107,  -860,   115,  -860,  -860,  -860,  -860,  -860,  2123,
    -860,  -860,  -860,  -860,  -860,  -860,  -860,   619,  -860,  -860,
    -860,  -860,     7,  -860,  -860,  2267,  -860,  2023,     7,  -860,
    -860,  -860,  1258,  -860,  2267,  -860,  2267,  -860,  -860,  2267,
    -860,  -860,  -860,   620,   607,  -860,  -860,  -860,  -860,   622,
    -860,  -860,    26,  1301,  -860,  -860,  -860,  -860,  2099,  -860,
    -860,  -860,  -860,   623,  -860,  -860,  -860,  -860,  -860,  -860,
    -860,   567,   606,   159,   155,   104,   104,  -860,     7,   582,
    -860,  -860,  -860,  -860,  -860,   624,   588,  -860,   -45,  -860,
    -860,  -860,  -860,   626,    25,  -860,   231,  -860,  -860,   627,
     629,    62,  -860,    62,  -860,   102,  -860,   155,   155,  -860,
      63,   632,  -860,   634,  -860,  -860,  -860,  2048,  2048,  2048,
     642,   578,    70,  -860,  2123,  -860,  -860,  -860,  -860,     7,
       7,   658,   641,  -860,  -860,  -860,  -860,  -860,  -860,  -860,
     107,  -860,  -860,  -860,  -860,  -860,  -860,  -860,    61,  -860,
       7,  -860,  2099,   619,  -860,  -860,  -860
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        12,     0,     0,     2,     4,     3,   204,    14,    13,    10,
      70,     1,   185,   185,   185,   185,    76,     0,    76,     0,
     185,   185,   185,   196,   198,   200,   163,     6,     0,     7,
       8,     9,   172,   165,   169,   173,   174,   175,   179,   176,
     177,   178,   180,   181,   182,   183,   205,     0,    16,   186,
       0,     0,     0,     0,   233,     0,   103,    76,   110,   626,
     629,   628,   461,   462,   109,    76,   107,   459,   460,   627,
     121,   203,   224,   224,   224,     0,     0,     0,   297,     5,
     164,   161,    85,    76,   167,   215,   217,   210,   206,   209,
      71,    11,    15,   188,     0,   229,   228,   230,   227,   190,
     192,   191,     0,   235,     0,     0,    77,   121,   108,   111,
     122,   124,     0,   225,   222,     0,     0,     0,     0,   233,
     197,   199,   201,   162,   295,     0,   296,     0,    83,    84,
      86,     0,   121,    12,   168,   170,     0,     0,   213,   208,
     207,     0,     0,    17,    22,    18,     0,   189,   184,   226,
     231,   437,   438,   439,   440,   441,   434,   620,   621,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   622,   624,
     623,   625,   630,   631,   468,   241,   236,   249,   351,   433,
     432,   443,     0,   349,   457,   458,   464,   465,   608,   609,
     610,   466,   606,   463,   467,     0,   114,   115,   116,   117,
     119,   124,   124,   124,   112,     0,   113,   126,   125,   256,
     252,   120,   251,   224,   223,   224,   224,     0,   298,   305,
     307,     0,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   580,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   591,   592,   593,
     594,     0,   595,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,    99,   101,    82,    97,
      95,    91,   570,   533,   535,   571,   572,    96,     0,    92,
      93,    94,     0,   124,   204,   166,   216,   218,     0,     0,
     214,     0,   211,    72,    20,     0,   187,     0,   234,   235,
     250,   247,   354,   442,     0,     0,   604,   605,   607,   602,
     118,   105,   104,   106,     0,     0,   128,   127,     0,   193,
     195,   194,   232,     0,     0,   314,     0,     0,     0,     0,
     516,    88,   469,   472,   476,   478,   480,   490,   501,   504,
     509,   510,   511,   517,   512,   513,   514,   515,   600,   583,
       0,     0,     0,   574,   526,     0,   346,   560,     0,     0,
       0,     0,   581,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   532,   341,   341,     0,   553,   554,
       0,     0,     0,     0,   527,     0,   552,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
     341,   341,   338,   337,    75,   212,     0,   219,   220,     0,
       0,    58,     0,    32,    47,     0,    19,    23,     0,    30,
      24,     0,    45,    25,    26,   364,     0,   442,   363,   242,
       0,     0,   248,   352,   353,   355,   454,   442,   444,   453,
     350,   603,     0,   132,   133,   136,   138,   135,   139,   140,
     142,   336,   334,   335,     0,   130,   129,   255,   448,   253,
       0,     0,   254,   262,   260,     0,     0,   372,   447,   446,
     370,   300,   308,   306,     0,     0,   507,   508,   506,     0,
      89,     0,   470,   474,     0,     0,     0,     0,     0,     0,
       0,     0,   479,   481,   491,   503,   601,   599,   584,     0,
       0,     0,   347,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   342,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   221,   202,    73,     0,   320,    36,   321,    37,
      33,    34,     0,   322,   317,   318,   319,   316,    51,    52,
      48,    49,     0,    30,     0,    45,     0,   435,   361,   367,
     369,     0,   238,   235,     0,   436,   445,    88,   134,   141,
       0,     0,     0,   123,   131,   155,   157,     0,    79,   257,
     326,   269,   259,   268,   264,   442,   375,     0,     0,   304,
     311,   313,   315,   518,    87,    90,     0,   473,     0,   477,
     482,   483,   484,   485,   486,   487,     0,   488,     0,     0,
     496,   502,   492,   493,     0,     0,   505,     0,   524,   525,
     573,   344,     0,     0,     0,     0,   582,   519,   520,     0,
     522,   523,     0,   565,   566,   567,   568,     0,   589,   590,
       0,   597,   569,   555,     0,     0,   544,   559,   551,   550,
     531,   558,     0,   549,   530,   548,     0,   557,   547,   538,
       0,   529,   546,   537,   528,   536,     0,   534,   556,   545,
       0,   339,    57,    60,    59,    35,    40,    50,    55,     0,
       0,    28,    38,    31,     0,     0,    43,    53,    46,   356,
     365,   239,   240,   244,     0,   148,   149,   143,   144,     0,
     146,   147,   151,   152,   159,   160,   153,   156,   154,   158,
       0,   415,     0,     0,     0,   377,   379,   380,   388,   395,
     396,   409,   401,   407,   389,   414,    80,   283,   287,   290,
     297,   281,   323,     0,     0,     0,   263,     0,   279,   271,
     273,   274,   275,   277,   278,   272,   270,   327,   276,   259,
     265,   456,   442,   451,   455,   373,   374,   376,   371,   299,
     301,   302,   309,   471,   475,   489,   498,   499,   497,   500,
     494,   495,   585,     0,     0,     0,     0,     0,     0,     0,
     576,   586,     0,   598,     0,     0,     0,     0,   576,     0,
       0,   587,   344,    65,    41,    27,    29,     0,    56,    42,
      44,     0,   358,   362,   442,   368,     0,   137,   145,   150,
       0,   425,   428,     0,   416,   418,   427,   410,   449,   442,
     399,   404,   412,   413,   411,   406,   408,   121,   284,   288,
     291,   294,     0,   324,   333,     0,   280,   259,     0,   266,
     450,   452,     0,   348,     0,   345,     0,   562,   563,     0,
     521,   564,   577,     0,     0,   588,   542,   543,   539,     0,
     540,   541,     0,     0,    39,    54,   359,   360,   442,   366,
     245,   417,   426,     0,   423,   431,   429,   430,   386,   392,
     394,   397,   402,   124,     0,   185,   185,   282,     0,     0,
     261,   331,   312,   310,   343,     0,   576,   575,     0,   578,
     340,    61,    66,    62,     0,   357,   235,   419,   421,   378,
     390,     0,   400,     0,   405,   163,   285,     0,     0,   325,
       0,   328,   561,     0,   596,    63,    64,     0,     0,     0,
       0,   424,   383,   387,   442,   393,   398,   403,    81,     0,
       0,     0,     0,   329,   332,   579,    69,    68,    67,   246,
       0,   422,   381,   384,   385,   391,   286,   289,     0,   293,
       0,   420,   442,   121,   330,   382,   292
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -860,  -860,  -860,  -860,  -860,  -860,   560,  -860,  -860,  -860,
    -860,  -860,  -860,  -860,  -860,  -860,    84,  -860,   241,  -860,
    -159,  -860,  -860,   101,  -860,  -860,    86,  -860,   244,  -860,
    -155,  -860,  -860,    93,  -860,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,    58,
    -860,  -860,  -860,  -860,   212,  -860,  -860,  -860,    81,  -860,
     417,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,  -860,  -860,  -150,  -100,  -860,  -185,  -860,  -860,
    -860,  -860,  -860,  -860,   235,  -860,  -860,   229,  -860,  -860,
     -44,  -860,  -860,  -860,  -860,  -860,  -860,    79,    87,  -255,
    -860,  -860,   580,  -860,  -860,  -860,  -860,  -860,  -860,  -860,
      -9,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,  -860,  -860,  -860,   628,  -860,  -860,  -860,    18,
    -860,     4,   661,   -76,   635,   596,  -860,  -300,   -70,  -860,
    -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -415,  -860,
    -860,  -860,  -860,  -607,  -860,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,  -860,  -860,  -860,   -62,  -860,  -860,  -860,  -860,
    -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -418,
    -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,
    -592,  -117,   352,  -860,  -311,  -765,  -121,  -224,  -860,  -860,
    -860,  -860,  -860,  -860,  -182,  -860,  -860,  -860,  -860,  -129,
    -859,  -860,  -860,  -130,  -860,  -860,  -860,  -860,  -860,  -368,
    -860,  -256,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,  -259,   -33,  -860,  -860,  -860,  -860,  -233,  -860,
    -860,  -860,   -32,  -860,  -234,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,  -860,  -818,  -860,   -95,  -860,  -860,  -860,  -860,
    -316,  -860,  -609,  -860,  -860,  -860,  -860,  -257,  -604,   -80,
     -14,     3,  -860,   906,  -860,  -860,  -860,    88,  -860,  -860,
      89,  -860,  -860,  -860,  -131,  -860,  -860,    73,  -860,  -860,
    -860,  -370,  -860,  -341,    -5,  -305,  -116,  -860,  -860,  -792,
    -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,   -97,  -860,
    -860,  -860,  -860,  -860,  -860,   -93,  -860,  -860,  -860,   227,
    -860,   214,   215,   290,  -212,   -17,  -860,  -860
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,    26,     5,     6,     7,    48,    91,
     143,   315,   144,   145,   446,   447,   604,   448,   449,   589,
     590,   733,   847,   591,   845,   450,   606,   451,   452,   599,
     600,   738,   851,   601,   849,   453,   585,   724,   843,   976,
     952,   913,   953,     8,    92,   141,   440,    27,    28,    55,
     489,   490,   776,   877,    83,   130,   131,   510,   511,   285,
     286,   287,   288,    29,    56,    30,    64,    65,   203,    31,
     106,   196,   197,   198,   199,   111,   112,   206,   207,   336,
     485,   623,   208,   473,   474,   337,   478,   479,   486,   747,
     748,   749,   750,   751,   624,   756,   758,   625,   626,    79,
      80,    81,     9,   134,   135,    32,    84,    33,    34,    35,
      50,   147,   148,    36,    37,    38,    39,    40,    41,    42,
      75,    43,    76,    44,    77,    45,    46,    47,   139,    87,
     138,   310,   311,    88,   136,    89,   137,   312,   437,   115,
     116,    98,    99,    57,   120,   102,   103,   175,   613,   459,
     318,   460,   461,   856,   956,   176,   320,   321,   211,   491,
     212,   338,   492,   493,   786,   630,   494,   633,   634,   787,
     788,   789,   882,   790,   878,   934,   989,   791,   879,   935,
     792,   880,   936,   793,   794,   123,   124,   125,   343,   638,
     810,   126,   127,   344,   221,   892,   642,   812,   504,   592,
     795,   883,   938,   796,   797,   888,   994,  1010,   971,   798,
     480,   481,   433,   842,   550,   902,   823,   377,   671,   177,
     324,   322,   463,   464,   456,   916,   917,   853,   739,   457,
     608,   855,   740,   609,   495,   637,   636,   805,   806,   764,
     869,   765,  1003,  1012,  1004,   983,   959,   766,   767,   928,
     985,   960,   929,   768,   769,   870,   962,   931,   770,   871,
     964,   932,   771,   875,   772,   876,   773,   864,  1001,   981,
     922,   958,   923,   865,   926,   466,   179,   317,   180,   181,
     182,   467,   497,   498,   627,   499,   802,   610,   930,   469,
     458,   350,   185,   351,   352,   647,   512,   353,   649,   513,
     354,   355,   522,   523,   356,   357,   660,   666,   819,   661,
     524,   358,   525,   359,   360,   361,   362,   374,   292,   903,
     293,   294,   295,   382,   537,   296,   528,   667,   363,   690,
     298,   833,   834,   364,   527,   365,   327,   328,   329,   366,
     188,   189,   190,   367,   192,   368,    69,   194
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int SPARQLfedParser::yytable_ninf_ = -443;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        68,   122,    71,    66,    51,    52,    53,   202,   178,   204,
     186,    72,    73,    74,   289,   291,   331,   332,   333,   462,
      67,   394,   496,   183,   583,   800,   801,   602,   752,   201,
     482,   803,   303,    93,   297,   735,   639,    58,   299,   640,
    -303,   219,   372,   924,   209,   330,   909,    68,   195,   664,
     108,   436,   113,   730,   375,   325,   100,   308,   895,   955,
     306,   307,   893,   431,     1,   631,   468,    67,   950,   894,
    -267,  -267,  -267,   502,   872,   894,    70,   149,   736,   732,
     104,   977,    10,   104,   861,   551,   193,   200,    85,    86,
     104,   117,   118,   665,   862,  -267,   731,   105,    54,   214,
     110,  -267,  -267,   760,  -121,    11,   184,   110,   632,  -267,
    -267,   760,  -267,   761,   302,   107,   873,    49,   434,   580,
     581,   761,   676,   109,   128,   129,   844,   762,   218,   168,
     169,   170,   171,    78,   290,   762,   760,   777,   778,   779,
     465,   132,   470,    94,   309,   863,   761,   895,   119,   455,
     316,   326,   114,  1015,   973,   752,   732,   874,   862,    90,
     762,    95,   780,    82,   763,   454,   925,    94,   210,  -258,
     289,   291,   763,   482,   978,   979,   781,   782,   200,   783,
     722,   602,  1011,   723,   641,  -303,   220,   373,   737,  -267,
     297,   884,   889,   801,   299,    59,    60,    61,   891,   376,
      62,    63,    59,    60,    61,    59,    60,    61,   432,   863,
     616,    86,  -267,   133,    62,    63,   146,   475,   477,   483,
     811,    59,    60,    61,   178,  -267,   186,   150,  -121,   213,
     186,   339,   435,   340,   341,   215,   -21,   621,   622,   183,
      59,    60,    61,    96,    97,   186,    62,    63,    59,    60,
      61,   205,   822,    62,    63,   313,   784,   216,   500,   314,
     801,   848,   737,   151,   152,   153,   154,   155,   807,   808,
     302,   323,  -442,    59,    60,    61,    59,    60,    61,   785,
     940,    62,    63,   156,   319,    59,    60,    61,   816,   817,
     290,   334,   438,    59,    60,    61,   342,   657,   200,   345,
      68,   369,   193,   -21,   335,    68,   193,    68,   471,   370,
      59,    60,    61,   742,   371,   482,   496,   302,   302,   496,
      67,   193,   184,   820,   821,    67,   184,    67,   378,   379,
     187,   484,   380,    59,    60,    61,   381,   476,    62,    63,
     383,   184,   506,   507,   508,   384,   385,   503,   386,   594,
     -21,   -21,   594,   -21,   387,   388,   475,   477,   300,   389,
     142,   390,   483,   391,   186,   392,   393,   441,   395,   396,
     886,   398,   397,   399,   186,   801,   400,   -21,   -21,   -21,
     401,   658,   659,   650,   651,   652,   653,   654,   655,   402,
     542,   403,   405,   191,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,    59,
      60,    61,   172,   173,    62,    63,   407,   174,   404,   582,
     406,   301,   408,   409,   410,   597,   411,   412,   597,   413,
     414,   415,   815,   602,   442,   416,   417,   418,   419,   420,
     193,   421,   482,   422,   859,   593,   423,   424,   593,   425,
     193,   426,   427,   428,   430,   439,   302,  -243,   501,   509,
     184,   302,   549,   584,   442,   445,   614,   937,   620,   607,
     184,   629,   635,   941,   943,   648,   476,   643,   482,   645,
     646,   443,   444,   496,   445,   656,   496,   162,   163,   164,
     165,   166,   167,   741,   668,   954,   594,   669,   670,   672,
     728,   677,   673,   674,   483,   678,   594,   675,    59,    60,
      61,   679,   644,   680,   300,   681,   682,  -171,   178,   683,
     186,   684,   685,   969,   686,   687,    12,   692,    13,    14,
     693,    15,   694,   183,   696,   695,   697,   698,   699,   186,
     700,   701,   186,   703,   704,   594,   187,   705,   707,   702,
     187,   708,   500,   496,   709,   804,   706,   710,   711,   996,
     997,   998,   712,   713,   714,   187,   715,   716,   717,  -171,
     718,   496,   597,   719,  1006,  1007,   726,   301,    12,   754,
      13,    14,   597,    15,   755,   622,   -74,   621,   799,   831,
      16,    17,   593,   832,   841,  1014,   193,    68,   846,   852,
     743,   850,   593,   302,   857,   854,   346,   885,    18,   191,
     775,   904,   868,   191,   897,   193,   184,    67,   193,   775,
     775,   597,    19,   753,   896,   898,   899,   900,   191,   901,
     774,   483,   905,    20,    21,   184,   920,   894,   184,   774,
     774,   593,   906,   907,   908,    22,   910,    23,    24,    25,
     514,   515,   516,   517,   518,   519,   980,   911,   921,   110,
     520,   521,   947,   948,   949,   957,   972,   483,   496,   595,
     963,   961,   595,   970,    19,   975,   995,   982,   984,   993,
     999,  1008,  1000,  1009,   187,    20,    21,   729,   914,   603,
     725,   734,   727,   304,   187,   605,   915,    22,   744,    23,
      24,    25,   628,   858,   429,   759,   186,   619,   618,   186,
     988,   121,   757,   305,   101,   217,   140,   887,   881,   500,
     526,   912,   804,   918,   919,  1005,  1002,   860,   986,   987,
     302,   867,   596,   818,   813,   596,   974,   814,   662,   663,
       0,     0,     0,   775,     0,   866,   775,   191,   965,     0,
     753,     0,     0,     0,   594,     0,     0,   191,   594,     0,
       0,   186,     0,     0,     0,     0,   302,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   186,   933,     0,     0,
       0,     0,   193,     0,     0,   193,     0,     0,     0,   804,
       0,     0,     0,     0,   186,     0,     0,     0,     0,   594,
       0,     0,   184,     0,     0,   184,     0,   500,     0,     0,
       0,     0,     0,     0,     0,     0,   595,     0,     0,     0,
     594,     0,     0,     0,     0,   186,   595,     0,     0,     0,
     597,     0,     0,     0,   597,    68,     0,   193,     0,     0,
     187,     0,     0,     0,   866,     0,   927,     0,     0,     0,
     593,     0,   193,     0,   593,    67,     0,   184,     0,   187,
       0,   178,   187,   186,     0,   595,     0,     0,     0,     0,
     193,     0,   184,     0,     0,   597,   183,   586,     0,   596,
       0,     0,     0,     0,   594,   594,   594,     0,     0,   596,
     184,   186,     0,     0,     0,   593,   597,     0,     0,     0,
       0,   193,     0,   191,   804,     0,     0,   809,     0,     0,
       0,     0,   586,  1016,     0,     0,   593,    68,     0,   186,
     966,   184,   191,     0,     0,   191,   967,   968,   596,     0,
       0,     0,  1013,     0,     0,     0,     0,    67,   587,   193,
       0,     0,     0,     0,   775,     0,   775,     0,     0,     0,
      68,    68,     0,   990,   991,     0,     0,     0,     0,   184,
     597,   597,   597,     0,     0,   775,     0,   193,     0,     0,
      67,    67,     0,   992,     0,     0,     0,     0,     0,     0,
     593,   593,   593,   866,     0,   774,     0,   184,     0,     0,
       0,     0,     0,     0,     0,   193,   588,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    59,    60,    61,   184,     0,    62,    63,     0,
       0,     0,     0,     0,     0,     0,   187,     0,     0,   187,
       0,   588,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,    59,    60,    61,
       0,   611,    62,    63,     0,     0,  -237,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   595,     0,     0,     0,   595,     0,
       0,   187,  -237,  -237,  -237,  -237,  -237,     0,  -237,   191,
       0,  -237,   191,     0,   612,     0,   187,     0,     0,     0,
       0,     0,  -237,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   187,     0,     0,     0,     0,   595,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   596,     0,     0,
     595,   596,     0,     0,   191,   187,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   191,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   191,     0,     0,
       0,     0,   596,   187,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   596,   595,   595,   595,     0,   191,     0,
       0,   187,     0,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,     0,  -237,     0,     0,   187,
       0,     0,     0,     0,     0,     0,   191,     0,     0,     0,
       0,     0,   505,     0,     0,     0,     0,     0,     0,     0,
     151,   152,   153,   154,   155,     0,     0,   596,   596,   596,
     615,     0,     0,     0,   191,     0,   529,   530,   531,     0,
     156,   532,     0,     0,   533,   534,   535,   536,     0,   538,
     539,   540,   541,     0,   543,   544,   545,   546,   547,   548,
     942,   586,   191,   552,     0,     0,   553,   554,   555,   556,
       0,   557,     0,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   487,     0,     0,     0,     0,
    -259,  -259,  -259,   951,   586,     0,     0,     0,     0,     0,
       0,   -78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -259,   151,   152,   153,   154,
     155,  -259,  -259,     0,     0,  -442,     0,     0,   617,  -259,
    -259,     0,  -259,     0,     0,     0,   488,     0,     0,     0,
       0,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    59,    60,    61,   172,
     173,    62,    63,     0,   174,     0,     0,     0,     0,     0,
     588,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    59,    60,    61,     0,
       0,    62,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   689,   691,     0,  -259,
       0,     0,     0,   588,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,    59,
      60,    61,  -259,     0,    62,    63,   720,   721,     0,     0,
       0,     0,     0,     0,     0,  -259,     0,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    59,    60,    61,   172,   173,    62,    63,   611,
     174,     0,     0,     0,  -237,  -237,  -237,   586,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,     0,     0,  -237,
       0,     0,   612,  -237,  -237,     0,  -237,     0,     0,     0,
    -237,     0,     0,     0,     0,     0,     0,     0,   824,   825,
     826,   827,     0,     0,     0,   828,     0,     0,   829,     0,
       0,     0,     0,   830,     0,     0,     0,     0,     0,     0,
     835,   836,     0,     0,     0,     0,     0,     0,   837,     0,
       0,     0,   838,     0,     0,     0,   839,     0,     0,     0,
       0,     0,   840,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   598,     0,
       0,     0,     0,  -237,     0,     0,   588,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    59,    60,    61,     0,  -237,    62,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -237,
       0,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,     0,  -237,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   688,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   346,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     347,   348,     0,   349,   224,     0,   225,   226,   227,   228,
     229,   230,   231,   232,   233,     0,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,     0,   245,     0,
       0,   939,   246,   247,   248,   249,   250,   251,   252,   253,
     944,     0,   945,     0,     0,   946,     0,   254,   255,   256,
       0,   257,   258,   259,     0,     0,   260,   261,   262,   263,
     264,   265,   266,     0,   267,   268,     0,   269,     0,     0,
       0,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   222,     0,
       0,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    59,    60,    61,   223,
       0,    62,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   224,     0,   225,   226,   227,   228,
     229,   230,   231,   232,   233,     0,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,     0,   245,     0,
       0,     0,   246,   247,   248,   249,   250,   251,   252,   253,
       0,     0,     0,     0,     0,     0,     0,   254,   255,   256,
       0,   257,   258,   259,     0,     0,   260,   261,   262,   263,
     264,   265,   266,     0,   267,   268,     0,   269,     0,     0,
       0,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   745,   746,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     346,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    59,    60,    61,     0,
       0,    62,    63,     0,     0,   224,     0,   225,   226,   227,
     228,   229,   230,   231,   232,   233,     0,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,     0,   245,
       0,     0,     0,     0,     0,   151,   152,   153,   154,   155,
     253,     0,     0,     0,  -442,     0,     0,     0,   254,   255,
     256,     0,   257,   258,   259,   488,     0,   260,   261,   262,
     263,   264,   265,   266,     0,   267,   268,     0,   269,     0,
       0,   586,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   151,   152,   153,
     154,   155,     0,     0,     0,     0,     0,   890,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   488,     0,     0,
       0,   151,   152,   153,   154,   155,     0,    59,    60,    61,
       0,     0,    62,    63,     0,     0,     0,     0,     0,     0,
       0,   156,     0,     0,     0,   151,   152,   153,   154,   155,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   488,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,    59,    60,    61,   172,   173,    62,    63,     0,   174,
     588,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    59,    60,    61,     0,
       0,    62,    63,     0,     0,     0,     0,     0,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,    59,    60,    61,   172,   173,    62,    63,
       0,   174,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,    59,    60,    61,
     172,   173,    62,    63,     0,   174,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,    59,    60,    61,   172,   173,    62,    63,   346,   174,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   347,
     348,     0,   349,   224,     0,   225,   226,   227,   228,   229,
     230,   231,   232,   233,     0,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,     0,   245,     0,     0,
       0,   246,   247,   248,   249,   250,   251,   252,   253,     0,
       0,     0,     0,     0,     0,     0,   254,   255,   256,     0,
     257,   258,   259,     0,     0,   260,   261,   262,   263,   264,
     265,   266,     0,   267,   268,     0,   269,     0,     0,     0,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   223,     0,     0,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    59,    60,    61,     0,     0,
      62,    63,   224,     0,   225,   226,   227,   228,   229,   230,
     231,   232,   233,     0,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,     0,   245,     0,     0,     0,
     246,   247,   248,   249,   250,   251,   252,   253,     0,     0,
       0,     0,     0,     0,     0,   254,   255,   256,     0,   257,
     258,   259,     0,     0,   260,   261,   262,   263,   264,   265,
     266,     0,   267,   268,     0,   269,     0,     0,     0,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   346,     0,     0,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    59,    60,    61,     0,     0,    62,
      63,   224,     0,   225,   226,   227,   228,   229,   230,   231,
     232,   233,     0,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,     0,   245,     0,     0,     0,   246,
     247,   248,   249,   250,   251,   252,   253,     0,     0,     0,
       0,     0,     0,     0,   254,   255,   256,     0,   257,   258,
     259,     0,     0,   260,   261,   262,   263,   264,   265,   266,
       0,   267,   268,     0,   269,     0,     0,     0,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   472,     0,     0,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,    59,    60,    61,     0,     0,    62,    63,
     224,     0,   225,   226,   227,   228,   229,   230,   231,   232,
     233,     0,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,     0,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   253,     0,     0,     0,     0,
       0,     0,     0,   254,   255,   256,     0,   257,   258,   259,
       0,     0,   260,   261,   262,   263,   264,   265,   266,   346,
     267,   268,     0,   269,     0,     0,     0,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,     0,     0,   224,     0,   225,   226,   227,   228,
     229,   230,   231,   232,   233,     0,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,     0,   245,     0,
       0,     0,    59,    60,    61,     0,     0,    62,    63,   253,
       0,     0,     0,     0,     0,     0,     0,   254,   255,   256,
       0,   257,   258,   259,     0,     0,   260,   261,   262,   263,
     264,   265,   266,     0,   267,   268,     0,   269,     0,     0,
       0,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    59,    60,    61
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        17,    77,    19,    17,    13,    14,    15,   107,   103,   109,
     103,    20,    21,    22,   131,   131,   201,   202,   203,   319,
      17,   245,   338,   103,   439,   632,   635,   445,   620,   105,
     335,   635,   132,    50,   131,     1,    38,    20,   131,    41,
      41,    41,    41,   861,    37,   195,   838,    64,    24,    20,
      64,    24,     6,     1,    41,    89,    52,    21,   823,   918,
     136,   137,    42,    41,    15,     1,   323,    64,    42,    49,
       6,     7,     8,    42,    20,    49,    18,    94,    44,   104,
      23,    56,   178,    23,    41,   396,   103,   104,     3,     4,
      23,    73,    74,    64,    51,    31,    44,    40,    37,   116,
      40,    37,    38,    41,    37,     0,   103,    40,    44,    45,
      46,    41,    48,    51,   131,    57,    62,    13,   303,   430,
     431,    51,   537,    65,    18,    19,   151,    65,   125,   174,
     175,   176,   177,    31,   131,    65,    41,     6,     7,     8,
     322,    83,   324,     6,   108,   102,    51,   912,    37,    51,
     146,   185,   106,  1012,   946,   747,   104,   103,    51,    16,
      65,    24,    31,    17,   102,   315,    51,     6,   161,    38,
     287,   287,   102,   478,   149,   150,    45,    46,   195,    48,
      38,   599,  1000,    41,   186,   186,   186,   186,   154,   125,
     287,   783,   799,   802,   287,   178,   179,   180,   802,   186,
     183,   184,   178,   179,   180,   178,   179,   180,   186,   102,
     467,     4,   148,    50,   183,   184,    10,   334,   334,   335,
     638,   178,   179,   180,   319,   161,   319,    38,   161,   112,
     323,   213,   308,   215,   216,   112,    37,    29,    30,   319,
     178,   179,   180,   106,   107,   338,   183,   184,   178,   179,
     180,    92,   667,   183,   184,   179,   125,   112,   338,    56,
     869,   153,   154,    32,    33,    34,    35,    36,   636,   637,
     287,    41,    41,   178,   179,   180,   178,   179,   180,   148,
     887,   183,   184,    52,    44,   178,   179,   180,   658,   659,
     287,    26,   309,   178,   179,   180,    38,   521,   315,    37,
     317,    76,   319,   104,    93,   322,   323,   324,   325,    41,
     178,   179,   180,   613,    41,   620,   632,   334,   335,   635,
     317,   338,   319,   664,   665,   322,   323,   324,    41,    41,
     103,    25,    41,   178,   179,   180,    41,   334,   183,   184,
      41,   338,   347,   348,   349,    41,    41,   344,    41,   442,
     151,   152,   445,   154,    41,    41,   473,   473,   131,    41,
     161,    41,   478,    41,   457,    41,    41,    37,    41,    41,
     785,   186,    41,   186,   467,   984,    41,   178,   179,   180,
      41,    62,    63,   514,   515,   516,   517,   518,   519,    41,
     387,    41,    41,   103,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,    41,   186,   186,   436,
     186,   131,    41,    41,    41,   442,    41,    41,   445,    41,
      41,    41,   656,   851,   104,    41,    41,    41,    41,    41,
     457,    41,   747,    41,   749,   442,    41,    41,   445,    41,
     467,    41,    41,    41,    41,    40,   473,     6,    37,    91,
     457,   478,    18,   178,   104,   154,     6,   882,    26,    53,
     467,    38,    41,   888,   892,    55,   473,    42,   783,    42,
      54,   151,   152,   799,   154,    67,   802,   168,   169,   170,
     171,   172,   173,    44,    42,   913,   589,    42,    42,    49,
     154,    42,    49,    49,   620,    42,   599,    49,   178,   179,
     180,    49,   509,    42,   287,    42,    49,     0,   613,    42,
     613,    42,    42,   938,    42,    49,     9,    42,    11,    12,
      42,    14,    49,   613,    42,    49,    42,    42,    42,   632,
      42,    42,   635,    42,    42,   638,   319,    42,    42,    49,
     323,    42,   632,   869,    42,   635,    49,    49,    42,   977,
     978,   979,    42,    42,    42,   338,    42,    49,    42,     0,
      42,   887,   589,    42,   989,   990,   104,   287,     9,   165,
      11,    12,   599,    14,   165,    30,    17,    29,    44,    42,
      21,    22,   589,    50,    42,  1010,   613,   614,    44,    50,
     614,    44,   599,   620,    42,    49,    41,    41,    39,   319,
     627,    77,    53,   323,    42,   632,   613,   614,   635,   636,
     637,   638,   105,   620,    49,    42,    49,    42,   338,    42,
     627,   747,    42,   116,   117,   632,    37,    49,   635,   636,
     637,   638,    42,    42,    42,   128,    42,   130,   131,   132,
      56,    57,    58,    59,    60,    61,   956,    42,    42,    40,
      66,    67,    42,    56,    42,    42,    42,   783,   984,   442,
      64,   104,   445,    91,   105,    49,    42,    50,    49,    47,
      38,    23,   104,    42,   457,   116,   117,   603,   847,   448,
     589,   605,   599,   133,   467,   451,   851,   128,   617,   130,
     131,   132,   490,   747,   287,   626,   799,   478,   473,   802,
     965,    76,   625,   133,    53,   119,    88,   787,   780,   799,
     368,   842,   802,   852,   854,   984,   982,   760,   961,   963,
     747,   763,   442,   660,   646,   445,   948,   648,   524,   524,
      -1,    -1,    -1,   760,    -1,   762,   763,   457,   933,    -1,
     747,    -1,    -1,    -1,   847,    -1,    -1,   467,   851,    -1,
      -1,   854,    -1,    -1,    -1,    -1,   783,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   869,   877,    -1,    -1,
      -1,    -1,   799,    -1,    -1,   802,    -1,    -1,    -1,   869,
      -1,    -1,    -1,    -1,   887,    -1,    -1,    -1,    -1,   892,
      -1,    -1,   799,    -1,    -1,   802,    -1,   887,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   589,    -1,    -1,    -1,
     913,    -1,    -1,    -1,    -1,   918,   599,    -1,    -1,    -1,
     847,    -1,    -1,    -1,   851,   852,    -1,   854,    -1,    -1,
     613,    -1,    -1,    -1,   861,    -1,   863,    -1,    -1,    -1,
     847,    -1,   869,    -1,   851,   852,    -1,   854,    -1,   632,
      -1,   956,   635,   956,    -1,   638,    -1,    -1,    -1,    -1,
     887,    -1,   869,    -1,    -1,   892,   956,    43,    -1,   589,
      -1,    -1,    -1,    -1,   977,   978,   979,    -1,    -1,   599,
     887,   984,    -1,    -1,    -1,   892,   913,    -1,    -1,    -1,
      -1,   918,    -1,   613,   984,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    43,  1013,    -1,    -1,   913,   934,    -1,  1012,
     934,   918,   632,    -1,    -1,   635,   935,   936,   638,    -1,
      -1,    -1,  1008,    -1,    -1,    -1,    -1,   934,   104,   956,
      -1,    -1,    -1,    -1,   961,    -1,   963,    -1,    -1,    -1,
     967,   968,    -1,   967,   968,    -1,    -1,    -1,    -1,   956,
     977,   978,   979,    -1,    -1,   982,    -1,   984,    -1,    -1,
     967,   968,    -1,   970,    -1,    -1,    -1,    -1,    -1,    -1,
     977,   978,   979,  1000,    -1,   982,    -1,   984,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1012,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,  1012,    -1,   183,   184,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   799,    -1,    -1,   802,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,     1,   183,   184,    -1,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   847,    -1,    -1,    -1,   851,    -1,
      -1,   854,    32,    33,    34,    35,    36,    -1,    38,   799,
      -1,    41,   802,    -1,    44,    -1,   869,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   887,    -1,    -1,    -1,    -1,   892,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   847,    -1,    -1,
     913,   851,    -1,    -1,   854,   918,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   869,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   887,    -1,    -1,
      -1,    -1,   892,   956,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   913,   977,   978,   979,    -1,   918,    -1,
      -1,   984,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,    -1,   186,    -1,    -1,  1012,
      -1,    -1,    -1,    -1,    -1,    -1,   956,    -1,    -1,    -1,
      -1,    -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    -1,    -1,   977,   978,   979,
      42,    -1,    -1,    -1,   984,    -1,   370,   371,   372,    -1,
      52,   375,    -1,    -1,   378,   379,   380,   381,    -1,   383,
     384,   385,   386,    -1,   388,   389,   390,   391,   392,   393,
      42,    43,  1012,   397,    -1,    -1,   400,   401,   402,   403,
      -1,   405,    -1,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,     1,    -1,    -1,    -1,    -1,
       6,     7,     8,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    41,    -1,    -1,   472,    45,
      46,    -1,    48,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,    -1,   186,    -1,    -1,    -1,    -1,    -1,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,    -1,
      -1,   183,   184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   550,   551,    -1,   125,
      -1,    -1,    -1,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   148,    -1,   183,   184,   580,   581,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,    -1,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,     1,
     186,    -1,    -1,    -1,     6,     7,     8,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    41,
      -1,    -1,    44,    45,    46,    -1,    48,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   672,   673,
     674,   675,    -1,    -1,    -1,   679,    -1,    -1,   682,    -1,
      -1,    -1,    -1,   687,    -1,    -1,    -1,    -1,    -1,    -1,
     694,   695,    -1,    -1,    -1,    -1,    -1,    -1,   702,    -1,
      -1,    -1,   706,    -1,    -1,    -1,   710,    -1,    -1,    -1,
      -1,    -1,   716,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,   125,    -1,    -1,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,    -1,   148,   183,   184,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,    -1,   186,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    -1,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    90,    -1,
      -1,   885,    94,    95,    96,    97,    98,    99,   100,   101,
     894,    -1,   896,    -1,    -1,   899,    -1,   109,   110,   111,
      -1,   113,   114,   115,    -1,    -1,   118,   119,   120,   121,
     122,   123,   124,    -1,   126,   127,    -1,   129,    -1,    -1,
      -1,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,    41,
      -1,   183,   184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    90,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,
      -1,   113,   114,   115,    -1,    -1,   118,   119,   120,   121,
     122,   123,   124,    -1,   126,   127,    -1,   129,    -1,    -1,
      -1,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,    -1,
      -1,   183,   184,    -1,    -1,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    -1,    90,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
     101,    -1,    -1,    -1,    41,    -1,    -1,    -1,   109,   110,
     111,    -1,   113,   114,   115,    52,    -1,   118,   119,   120,
     121,   122,   123,   124,    -1,   126,   127,    -1,   129,    -1,
      -1,    43,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    -1,   178,   179,   180,
      -1,    -1,   183,   184,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,    -1,   186,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,    -1,
      -1,   183,   184,    -1,    -1,    -1,    -1,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
      -1,   186,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,    -1,   186,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,    41,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      63,    -1,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    90,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,
     113,   114,   115,    -1,    -1,   118,   119,   120,   121,   122,
     123,   124,    -1,   126,   127,    -1,   129,    -1,    -1,    -1,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
     183,   184,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,   113,
     114,   115,    -1,    -1,   118,   119,   120,   121,   122,   123,
     124,    -1,   126,   127,    -1,   129,    -1,    -1,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    -1,    -1,   183,
     184,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,   110,   111,    -1,   113,   114,
     115,    -1,    -1,   118,   119,   120,   121,   122,   123,   124,
      -1,   126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,   183,   184,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    -1,    90,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,   110,   111,    -1,   113,   114,   115,
      -1,    -1,   118,   119,   120,   121,   122,   123,   124,    41,
     126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    90,    -1,
      -1,    -1,   178,   179,   180,    -1,    -1,   183,   184,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,
      -1,   113,   114,   115,    -1,    -1,   118,   119,   120,   121,
     122,   123,   124,    -1,   126,   127,    -1,   129,    -1,    -1,
      -1,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   178,   179,   180
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    15,   188,   189,   190,   192,   193,   194,   230,   289,
     178,     0,     9,    11,    12,    14,    21,    22,    39,   105,
     116,   117,   128,   130,   131,   132,   191,   234,   235,   250,
     252,   256,   292,   294,   295,   296,   300,   301,   302,   303,
     304,   305,   306,   308,   310,   312,   313,   314,   195,    13,
     297,   297,   297,   297,    37,   236,   251,   330,    20,   178,
     179,   180,   183,   184,   253,   254,   477,   478,   532,   533,
     236,   532,   297,   297,   297,   307,   309,   311,    31,   286,
     287,   288,    17,   241,   293,     3,     4,   316,   320,   322,
      16,   196,   231,   532,     6,    24,   106,   107,   328,   329,
     328,   329,   332,   333,    23,    40,   257,   236,   477,   236,
      40,   262,   263,     6,   106,   326,   327,   326,   326,    37,
     331,   331,   330,   372,   373,   374,   378,   379,    18,    19,
     242,   243,   236,    50,   290,   291,   321,   323,   317,   315,
     322,   232,   161,   197,   199,   200,    10,   298,   299,   532,
      38,    32,    33,    34,    35,    36,    52,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   181,   182,   186,   334,   342,   406,   462,   463,
     465,   466,   467,   476,   478,   479,   522,   526,   527,   528,
     529,   530,   531,   532,   534,    24,   258,   259,   260,   261,
     532,   330,   262,   255,   262,    92,   264,   265,   269,    37,
     161,   345,   347,   112,   532,   112,   112,   332,   478,    41,
     186,   381,    20,    41,    66,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    90,    94,    95,    96,    97,
      98,    99,   100,   101,   109,   110,   111,   113,   114,   115,
     118,   119,   120,   121,   122,   123,   124,   126,   127,   129,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   246,   247,   248,   249,   398,
     478,   503,   505,   507,   508,   509,   512,   515,   517,   522,
     526,   530,   532,   262,   193,   289,   330,   330,    21,   108,
     318,   319,   324,   179,    56,   198,   328,   464,   337,    44,
     343,   344,   408,    41,   407,    89,   185,   523,   524,   525,
     261,   264,   264,   264,    26,    93,   266,   272,   348,   326,
     326,   326,    38,   375,   380,    37,    41,    62,    63,    65,
     478,   480,   481,   484,   487,   488,   491,   492,   498,   500,
     501,   502,   503,   515,   520,   522,   526,   530,   532,    76,
      41,    41,    41,   186,   504,    41,   186,   404,    41,    41,
      41,    41,   510,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,   404,    41,    41,    41,   186,   186,
      41,    41,    41,    41,   186,    41,   186,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,   247,
      41,    41,   186,   399,   264,   330,    24,   325,   532,    40,
     233,    37,   104,   151,   152,   154,   201,   202,   204,   205,
     212,   214,   215,   222,   261,    51,   411,   416,   477,   336,
     338,   339,   334,   409,   410,   411,   462,   468,   474,   476,
     411,   532,    41,   270,   271,   398,   478,   503,   273,   274,
     397,   398,   502,   503,    25,   267,   275,     1,    52,   237,
     238,   346,   349,   350,   353,   421,   467,   469,   470,   472,
     476,    37,    42,   478,   385,   480,   501,   501,   501,    91,
     244,   245,   483,   486,    56,    57,    58,    59,    60,    61,
      66,    67,   489,   490,   497,   499,   399,   521,   513,   480,
     480,   480,   480,   480,   480,   480,   480,   511,   480,   480,
     480,   480,   478,   480,   480,   480,   480,   480,   480,    18,
     401,   401,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     401,   401,   532,   345,   178,   223,    43,   104,   162,   206,
     207,   210,   386,   478,   522,   526,   530,   532,   154,   216,
     217,   220,   386,   205,   203,   215,   213,    53,   417,   420,
     474,     1,    44,   335,     6,    42,   474,   480,   271,   274,
      26,    29,    30,   268,   281,   284,   285,   471,   241,    38,
     352,     1,    44,   354,   355,    41,   423,   422,   376,    38,
      41,   186,   383,    42,   478,    42,    54,   482,    55,   485,
     491,   491,   491,   491,   491,   491,    67,   404,    62,    63,
     493,   496,   528,   529,    20,    64,   494,   514,    42,    42,
      42,   405,    49,    49,    49,    49,   345,    42,    42,    49,
      42,    42,    49,    42,    42,    42,    42,    49,    20,   480,
     516,   480,    42,    42,    49,    49,    42,    42,    42,    42,
      42,    42,    49,    42,    42,    42,    49,    42,    42,    42,
      49,    42,    42,    42,    42,    42,    49,    42,    42,    42,
     480,   480,    38,    41,   224,   210,   104,   220,   154,   203,
       1,    44,   104,   208,   213,     1,    44,   154,   218,   415,
     419,    44,   334,   477,   245,    27,    28,   276,   277,   278,
     279,   280,   397,   478,   165,   165,   282,   285,   283,   284,
      41,    51,    65,   102,   426,   428,   434,   435,   440,   441,
     445,   449,   451,   453,   478,   532,   239,     6,     7,     8,
      31,    45,    46,    48,   125,   148,   351,   356,   357,   358,
     360,   364,   367,   370,   371,   387,   390,   391,   396,    44,
     350,   469,   473,   475,   476,   424,   425,   426,   426,    38,
     377,   386,   384,   484,   487,   404,   498,   498,   494,   495,
     500,   500,   345,   403,   480,   480,   480,   480,   480,   480,
     480,    42,    50,   518,   519,   480,   480,   480,   480,   480,
     480,    42,   400,   225,   151,   211,    44,   209,   153,   221,
      44,   219,    50,   414,    49,   418,   340,    42,   277,   502,
     440,    41,    51,   102,   454,   460,   532,   449,    53,   427,
     442,   446,    20,    62,   103,   450,   452,   240,   361,   365,
     368,   372,   359,   388,   397,    41,   345,   335,   392,   350,
      42,   475,   382,    42,    49,   402,    49,    42,    42,    49,
      42,    42,   402,   506,    77,    42,    42,    42,    42,   506,
      42,    42,   403,   228,   207,   217,   412,   413,   416,   420,
      37,    42,   457,   459,   460,    51,   461,   532,   436,   439,
     475,   444,   448,   262,   362,   366,   369,   345,   389,   480,
     350,   345,    42,   386,   480,   480,   480,    42,    56,    42,
      42,    42,   227,   229,   386,   417,   341,    42,   458,   433,
     438,   104,   443,    64,   447,   264,   477,   297,   297,   345,
      91,   395,    42,   506,   531,    49,   226,    56,   149,   150,
     334,   456,    50,   432,    49,   437,   445,   451,   286,   363,
     477,   477,   478,    47,   393,    42,   386,   386,   386,    38,
     104,   455,   428,   429,   431,   439,   345,   345,    23,    42,
     394,   460,   430,   330,   345,   417,   262
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
     199,   200,   200,   201,   201,   201,   201,   202,   202,   202,
     203,   203,   204,   205,   206,   206,   207,   207,   209,   208,
     210,   211,   212,   212,   212,   213,   213,   214,   215,   216,
     216,   217,   217,   219,   218,   220,   221,   222,   223,   223,
     225,   224,   226,   226,   227,   228,   228,   229,   229,   229,
     230,   232,   233,   231,   235,   234,   236,   236,   238,   239,
     240,   237,   241,   242,   242,   243,   243,   244,   245,   245,
     246,   247,   247,   247,   247,   247,   247,   247,   247,   248,
     248,   249,   249,   250,   251,   251,   252,   253,   253,   254,
     254,   255,   255,   256,   257,   258,   258,   259,   260,   261,
     262,   263,   263,   264,   265,   265,   266,   266,   267,   267,
     268,   268,   269,   270,   270,   271,   271,   271,   271,   272,
     273,   273,   274,   275,   276,   276,   277,   277,   278,   278,
     279,   280,   280,   281,   281,   282,   282,   283,   283,   284,
     285,   286,   287,   288,   288,   289,   290,   291,   291,   293,
     292,   294,   294,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   296,   297,   297,   298,   299,   299,
     300,   301,   302,   303,   304,   305,   307,   306,   309,   308,
     311,   310,   312,   313,   314,   314,   315,   315,   316,   316,
     317,   317,   318,   319,   319,   321,   320,   323,   322,   324,
     325,   325,   326,   326,   327,   327,   328,   329,   329,   329,
     329,   330,   331,   333,   332,   334,   334,   335,   335,   335,
     336,   337,   337,   339,   340,   341,   338,   342,   343,   344,
     344,   345,   345,   346,   346,   346,   348,   347,   349,   350,
     350,   351,   352,   352,   353,   354,   354,   355,   355,   355,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     357,   359,   358,   361,   362,   363,   360,   365,   366,   364,
     368,   369,   367,   370,   371,   372,   372,   374,   375,   373,
     376,   376,   377,   379,   378,   380,   380,   381,   381,   382,
     382,   384,   383,   383,   385,   385,   386,   386,   386,   386,
     386,   386,   386,   388,   389,   387,   391,   392,   390,   394,
     393,   395,   395,   396,   397,   397,   397,   398,   399,   400,
     399,   401,   401,   402,   403,   403,   404,   405,   404,   407,
     406,   408,   406,   409,   410,   410,   411,   412,   413,   413,
     414,   415,   415,   416,   416,   417,   418,   419,   419,   420,
     422,   421,   423,   421,   424,   425,   425,   427,   426,   428,
     428,   430,   429,   431,   431,   432,   433,   433,   434,   435,
     436,   437,   438,   438,   439,   440,   442,   441,   443,   444,
     444,   446,   445,   447,   448,   448,   449,   450,   450,   451,
     451,   452,   452,   452,   453,   453,   453,   453,   454,   454,
     455,   456,   456,   458,   457,   459,   459,   460,   460,   460,
     461,   461,   462,   462,   464,   463,   465,   466,   466,   466,
     466,   466,   467,   467,   468,   468,   469,   469,   471,   470,
     472,   473,   473,   474,   474,   475,   475,   476,   476,   477,
     477,   478,   478,   479,   479,   479,   479,   479,   479,   480,
     481,   482,   483,   483,   484,   485,   486,   486,   487,   488,
     489,   489,   490,   490,   490,   490,   490,   490,   490,   490,
     491,   492,   493,   493,   494,   494,   495,   495,   496,   496,
     496,   497,   497,   498,   499,   499,   500,   500,   500,   500,
     501,   501,   501,   501,   501,   501,   501,   501,   502,   503,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   504,   504,   505,   506,   506,   507,   508,
     510,   511,   509,   513,   514,   512,   515,   515,   515,   516,
     516,   517,   517,   517,   517,   517,   518,   519,   519,   520,
     521,   521,   522,   523,   524,   524,   525,   525,   526,   526,
     526,   527,   527,   527,   528,   528,   528,   529,   529,   529,
     530,   530,   531,   531,   531,   531,   532,   532,   533,   533,
     534,   534
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SPARQLfedParser::yyr2_[] =
  {
         0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     3,     0,     1,     0,     2,     0,     2,     0,     3,
       2,     0,     1,     1,     1,     1,     1,     4,     3,     4,
       0,     2,     1,     2,     1,     2,     1,     1,     0,     3,
       2,     1,     4,     3,     4,     0,     2,     1,     2,     1,
       2,     1,     1,     0,     3,     2,     1,     3,     0,     2,
       0,     4,     0,     1,     2,     0,     2,     3,     3,     3,
       2,     0,     0,     5,     0,     5,     0,     2,     0,     0,
       0,     7,     3,     1,     1,     0,     1,     2,     0,     1,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     2,     4,     4,     5,     1,     2,     1,
       1,     0,     1,     4,     2,     1,     1,     1,     2,     1,
       2,     0,     1,     4,     0,     1,     0,     1,     0,     1,
       0,     1,     3,     1,     2,     1,     1,     4,     1,     2,
       1,     2,     1,     3,     1,     2,     1,     1,     1,     1,
       2,     1,     1,     2,     2,     0,     1,     0,     1,     2,
       2,     1,     2,     0,     1,     2,     2,     0,     1,     0,
       3,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     0,     1,     2,     0,     1,
       3,     3,     3,     5,     5,     5,     0,     3,     0,     3,
       0,     3,     6,     2,     0,     1,     0,     1,     2,     1,
       0,     2,     2,     0,     1,     0,     3,     0,     3,     2,
       1,     2,     1,     2,     0,     1,     2,     1,     1,     1,
       1,     3,     3,     0,     3,     0,     1,     0,     1,     2,
       3,     0,     2,     0,     0,     0,     8,     2,     2,     0,
       1,     1,     1,     1,     1,     1,     0,     4,     2,     0,
       1,     3,     0,     2,     2,     2,     3,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     0,     3,     0,     0,     0,     6,     0,     0,     6,
       0,     0,     8,     6,     2,     1,     1,     0,     0,     6,
       0,     2,     1,     0,     5,     0,     2,     1,     3,     0,
       2,     0,     4,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     0,     0,     4,     0,     0,     4,     0,
       3,     0,     2,     2,     1,     1,     1,     2,     1,     0,
       6,     0,     1,     2,     0,     2,     1,     0,     5,     0,
       3,     0,     3,     1,     0,     1,     3,     2,     0,     1,
       2,     0,     2,     1,     1,     2,     2,     0,     2,     1,
       0,     3,     0,     3,     1,     0,     1,     0,     4,     1,
       1,     0,     3,     0,     1,     2,     0,     2,     1,     1,
       2,     2,     0,     2,     1,     1,     0,     3,     2,     0,
       2,     0,     3,     2,     0,     2,     2,     0,     1,     1,
       2,     1,     1,     1,     1,     1,     2,     3,     1,     3,
       2,     0,     2,     0,     3,     0,     1,     1,     1,     2,
       1,     1,     1,     1,     0,     4,     4,     1,     1,     1,
       1,     1,     0,     1,     1,     2,     1,     1,     0,     4,
       4,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     0,     2,     2,     2,     0,     2,     1,     2,
       0,     1,     2,     2,     2,     2,     2,     2,     2,     3,
       1,     2,     1,     1,     2,     2,     0,     1,     2,     2,
       2,     0,     2,     2,     0,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     4,
       4,     6,     4,     4,     4,     4,     2,     2,     4,     4,
       4,     4,     2,     1,     4,     1,     4,     4,     4,     6,
       6,     6,     6,     6,     4,     4,     4,     4,     4,     4,
       4,     4,     2,     2,     2,     4,     4,     4,     4,     4,
       2,     8,     6,     6,     6,     4,     4,     4,     4,     4,
       1,     1,     1,     3,     1,     7,     0,     1,     7,     9,
       0,     0,     4,     0,     0,     5,     5,     5,     6,     1,
       1,     1,     1,     1,     1,     1,     4,     0,     1,     2,
       0,     1,     2,     2,     1,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
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
  "GT_H_2192_", "GT_MINUS_GT", "ABOX_HR", "UBOX_UHR", "UBOX_LHR",
  "GT_H_2502_", "UBOX_UL", "UBOX_U", "UBOX_UR", "UBOX_LL", "UBOX_L",
  "UBOX_LR", "RSREF", "GT_MINUS_MINUS", "IT_true", "IT_false", "INTEGER",
  "DECIMAL", "DOUBLE", "INTEGER_POSITIVE", "DECIMAL_POSITIVE",
  "DOUBLE_POSITIVE", "INTEGER_NEGATIVE", "DECIMAL_NEGATIVE",
  "DOUBLE_NEGATIVE", "STRING_LITERAL1", "STRING_LITERAL_LONG1",
  "STRING_LITERAL2", "STRING_LITERAL_LONG2", "IRIREF", "PNAME_NS",
  "PNAME_LN", "BLANK_NODE_LABEL", "ANON", "VAR1", "VAR2", "LANGTAG", "NIL",
  "$accept", "Top", "QueryUnit", "Query",
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
  "InsertClause", "$@16", "UsingClause",
  "_O_Qiri_E_Or_QIT_NAMED_E_S_Qiri_E_C", "GraphOrDefault",
  "_QIT_GRAPH_E_Opt", "GraphRef", "GraphRefAll", "QuadPattern", "QuadData",
  "Quads", "$@17", "_QTriplesTemplate_E_Opt", "_QGT_DOT_E_Opt",
  "_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QQuadsNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesTemplate_E_Opt_C_E_Star",
  "QuadsNotTriples", "@18", "@19", "$@20", "TriplesTemplate",
  "_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C_E_Opt", "GroupGraphPattern",
  "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C",
  "_O_QGT_LCURLEY_E_S_QSubSelect_E_Or_QGroupGraphPatternSub_E_S_QGT_RCURLEY_E_C",
  "$@21", "GroupGraphPatternSub", "_QTriplesBlock_E_Opt",
  "_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "Print", "OptionalGraphPattern", "@22", "GraphGraphPattern", "@23",
  "@24", "@25", "ServiceGraphPattern", "@26", "@27", "SADIinvocation",
  "@28", "@29", "Bind", "InlineData", "DataBlock", "InlineDataOneVar",
  "$@30", "$@31", "_QSingleValueRow_E_Star", "SingleValueRow",
  "InlineDataFull", "$@32", "_QVar_E_Star",
  "_O_QNIL_E_Or_QGT_LPAREN_E_S_QVar_E_Star_S_QGT_RPAREN_E_C",
  "_QDataBlockValue_E_Star",
  "_O_QGT_LPAREN_E_S_QDataBlockValue_E_Star_S_QGT_RPAREN_E_Or_QNIL_E_C",
  "$@33",
  "_Q_O_QGT_LPAREN_E_S_QDataBlockValue_E_Star_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star",
  "DataBlockValue", "MinusGraphPattern", "@34", "@35",
  "GroupOrUnionGraphPattern", "@36", "@37",
  "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@38",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "@39", "_QIT_DISTINCT_E_Opt",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ExpressionList", "@40",
  "TriplesSameSubject", "$@41", "$@42", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "PropertyListNotEmpty",
  "_O_QVerb_E_S_QObjectList_E_C", "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "Verb",
  "ObjectList", "_O_QGT_COMMA_E_S_QObject_E_C",
  "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star", "Object",
  "TriplesSameSubjectPath", "$@43", "$@44", "PropertyListPath",
  "_QPropertyListPathNotEmpty_E_Opt", "PropertyListPathNotEmpty", "$@45",
  "_O_QVerbPath_E_Or_QVerbSimple_E_C",
  "_O_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_C", "$@46",
  "_Q_O_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_Opt_C_E_Star",
  "VerbPath", "VerbSimple", "ObjectListPath",
  "_O_QGT_COMMA_E_S_QObjectPath_E_C",
  "_Q_O_QGT_COMMA_E_S_QObjectPath_E_C_E_Star", "ObjectPath", "Path",
  "PathAlternative", "@47", "_O_QGT_PIPE_E_S_QPathSequence_E_C",
  "_Q_O_QGT_PIPE_E_S_QPathSequence_E_C_E_Star", "PathSequence", "@48",
  "_O_QGT_DIVIDE_E_S_QPathEltOrInverse_E_C",
  "_Q_O_QGT_DIVIDE_E_S_QPathEltOrInverse_E_C_E_Star", "PathElt",
  "_QPathMod_E_Opt", "PathEltOrInverse", "PathMod", "PathPrimary",
  "PathNegatedPropertySet", "_O_QGT_PIPE_E_S_QPathOneInPropertySet_E_C",
  "_Q_O_QGT_PIPE_E_S_QPathOneInPropertySet_E_C_E_Star",
  "_O_QPathOneInPropertySet_E_S_QGT_PIPE_E_S_QPathOneInPropertySet_E_Star_C",
  "@49",
  "_Q_O_QPathOneInPropertySet_E_S_QGT_PIPE_E_S_QPathOneInPropertySet_E_Star_C_E_Opt",
  "PathOneInPropertySet", "_O_Qiri_E_Or_QIT_a_E_C", "TriplesNode",
  "BlankNodePropertyList", "@50", "Generator",
  "_O_QIT_MEMBERS_E_Or_QIT_STARTS_E_Or_QIT_ENDS_E_Or_QIT_ANY_E_Or_QIT_UNORDERED_E_C",
  "_Q_O_QIT_MEMBERS_E_Or_QIT_STARTS_E_Or_QIT_ENDS_E_Or_QIT_ANY_E_Or_QIT_UNORDERED_E_C_E_Opt",
  "_QGraphNode_E_Plus", "TriplesNodePath", "BlankNodePropertyListPath",
  "@51", "GeneratorPath", "_QGraphNodePath_E_Plus", "GraphNode",
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
  "SubstringExpression", "StrReplaceExpression", "ExistsFunc", "@52",
  "@53", "NotExistsFunc", "@54", "@55", "Aggregate",
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
     198,   201,    -1,   161,    56,    -1,    -1,   199,    -1,   202,
      -1,   212,    -1,   222,    -1,   261,    -1,   204,   205,   203,
     211,    -1,   205,   203,    44,    -1,   205,   203,     1,    44,
      -1,    -1,   203,   208,    -1,   151,    -1,   104,   207,    -1,
     210,    -1,   206,   210,    -1,   104,    -1,   206,    -1,    -1,
     104,   209,   207,    -1,   386,   104,    -1,   151,    -1,   214,
     215,   213,   221,    -1,   215,   213,    44,    -1,   215,   213,
       1,    44,    -1,    -1,   213,   218,    -1,   152,    -1,   154,
     217,    -1,   220,    -1,   216,   220,    -1,   154,    -1,   216,
      -1,    -1,   154,   219,   217,    -1,   386,   154,    -1,   153,
      -1,    37,   223,    38,    -1,    -1,   223,   224,    -1,    -1,
      41,   225,   228,    42,    -1,    -1,    49,    -1,   229,   226,
      -1,    -1,   228,   227,    -1,   386,   150,   386,    -1,   386,
     149,   386,    -1,   386,    56,   386,    -1,    15,   178,    -1,
      -1,    -1,    16,   232,   179,   233,   178,    -1,    -1,   235,
     241,   236,   262,   264,    -1,    -1,   236,   257,    -1,    -1,
      -1,    -1,   238,   241,   239,   240,   262,   264,   286,    -1,
      17,   243,   249,    -1,    18,    -1,    19,    -1,    -1,   242,
      -1,    91,   478,    -1,    -1,   244,    -1,    41,   480,   245,
      42,    -1,   503,    -1,   522,    -1,   526,    -1,   530,    -1,
     478,    -1,   515,    -1,   398,    -1,   246,    -1,   247,    -1,
     248,   247,    -1,   248,    -1,    20,    -1,    21,   251,    -1,
     330,   236,   262,   264,    -1,   236,    40,   330,   264,    -1,
      22,   254,   236,   255,   264,    -1,   477,    -1,   253,   477,
      -1,   253,    -1,    20,    -1,    -1,   262,    -1,    39,   236,
     262,   264,    -1,    23,   258,    -1,   259,    -1,   260,    -1,
     261,    -1,    24,   261,    -1,   532,    -1,   263,   345,    -1,
      -1,    40,    -1,   265,   266,   267,   268,    -1,    -1,   269,
      -1,    -1,   272,    -1,    -1,   275,    -1,    -1,   281,    -1,
      92,    26,   270,    -1,   271,    -1,   270,   271,    -1,   503,
      -1,   398,    -1,    41,   480,   245,    42,    -1,   478,    -1,
      93,   273,    -1,   274,    -1,   273,   274,    -1,   397,    -1,
      25,    26,   276,    -1,   277,    -1,   276,   277,    -1,   279,
      -1,   280,    -1,    27,    -1,    28,    -1,   278,   502,    -1,
     397,    -1,   478,    -1,   284,   282,    -1,   285,   283,    -1,
      -1,   285,    -1,    -1,   284,    -1,    29,   165,    -1,    30,
     165,    -1,   288,    -1,    31,   372,    -1,    -1,   287,    -1,
     193,   294,    -1,    50,   289,    -1,    -1,   290,    -1,    -1,
     295,   293,   291,    -1,    -1,   292,    -1,   296,    -1,   300,
      -1,   301,    -1,   303,    -1,   304,    -1,   305,    -1,   302,
      -1,   306,    -1,   308,    -1,   310,    -1,   312,    -1,     9,
     297,   532,   299,    -1,    -1,    13,    -1,    10,   328,    -1,
      -1,   298,    -1,    11,   297,   329,    -1,    14,   297,   329,
      -1,    12,   297,   328,    -1,   116,   297,   326,   112,   326,
      -1,   128,   297,   326,   112,   326,    -1,   117,   297,   326,
     112,   326,    -1,    -1,   130,   307,   331,    -1,    -1,   131,
     309,   331,    -1,    -1,   132,   311,   330,    -1,   314,   316,
     317,   319,    40,   345,    -1,   105,   532,    -1,    -1,   313,
      -1,    -1,   322,    -1,   320,   315,    -1,   322,    -1,    -1,
     317,   324,    -1,    21,   330,    -1,    -1,   318,    -1,    -1,
       3,   321,   330,    -1,    -1,     4,   323,   330,    -1,   108,
     325,    -1,   532,    -1,    24,   532,    -1,   106,    -1,   327,
     532,    -1,    -1,     6,    -1,     6,   532,    -1,   328,    -1,
     106,    -1,    24,    -1,   107,    -1,    37,   332,    38,    -1,
      37,   332,    38,    -1,    -1,   333,   334,   337,    -1,    -1,
     342,    -1,    -1,    44,    -1,     1,    44,    -1,   338,   335,
     334,    -1,    -1,   337,   336,    -1,    -1,    -1,    -1,   339,
       6,   477,   340,    37,   341,   334,    38,    -1,   406,   344,
      -1,    44,   334,    -1,    -1,   343,    -1,   347,    -1,   161,
      -1,   237,    -1,   349,    -1,     1,    -1,    -1,    37,   348,
     346,    38,    -1,   350,   352,    -1,    -1,   353,    -1,   356,
     335,   350,    -1,    -1,   352,   351,    -1,   421,   355,    -1,
      44,   350,    -1,     1,    44,   350,    -1,    -1,   354,    -1,
       1,    -1,   390,    -1,   358,    -1,   387,    -1,   360,    -1,
     364,    -1,   367,    -1,   396,    -1,   370,    -1,   371,    -1,
     357,    -1,   148,   345,    -1,    -1,    45,   359,   345,    -1,
      -1,    -1,    -1,     6,   361,   362,   477,   363,   345,    -1,
      -1,    -1,     7,   365,   366,   297,   477,   345,    -1,    -1,
      -1,     8,   368,   369,   297,   477,    23,   330,   262,    -1,
     125,    41,   480,    91,   478,    42,    -1,    31,   372,    -1,
     373,    -1,   378,    -1,    -1,    -1,   374,   478,   375,    37,
     376,    38,    -1,    -1,   376,   377,    -1,   386,    -1,    -1,
     379,   381,    37,   385,    38,    -1,    -1,   380,   478,    -1,
     186,    -1,    41,   380,    42,    -1,    -1,   382,   386,    -1,
      -1,    41,   384,   382,    42,    -1,   186,    -1,    -1,   385,
     383,    -1,   532,    -1,   522,    -1,   526,    -1,   530,    -1,
      43,    -1,   162,    -1,   478,    -1,    -1,    -1,    46,   388,
     389,   345,    -1,    -1,    -1,   391,   392,   345,   395,    -1,
      -1,    47,   394,   345,    -1,    -1,   395,   393,    -1,    48,
     397,    -1,   502,    -1,   503,    -1,   398,    -1,   532,   399,
      -1,   186,    -1,    -1,    41,   401,   480,   400,   403,    42,
      -1,    -1,    18,    -1,    49,   480,    -1,    -1,   403,   402,
      -1,   186,    -1,    -1,    41,   480,   405,   403,    42,    -1,
      -1,   476,   407,   411,    -1,    -1,   462,   408,   409,    -1,
     410,    -1,    -1,   411,    -1,   416,   417,   415,    -1,   416,
     417,    -1,    -1,   412,    -1,    50,   413,    -1,    -1,   415,
     414,    -1,   477,    -1,    51,    -1,   420,   419,    -1,    49,
     420,    -1,    -1,   419,   418,    -1,   474,    -1,    -1,   476,
     422,   426,    -1,    -1,   469,   423,   424,    -1,   425,    -1,
      -1,   426,    -1,    -1,   428,   427,   436,   433,    -1,   434,
      -1,   435,    -1,    -1,   428,   430,   417,    -1,    -1,   429,
      -1,    50,   431,    -1,    -1,   433,   432,    -1,   440,    -1,
     478,    -1,   439,   438,    -1,    49,   439,    -1,    -1,   438,
     437,    -1,   475,    -1,   441,    -1,    -1,   445,   442,   444,
      -1,   104,   445,    -1,    -1,   444,   443,    -1,    -1,   451,
     446,   448,    -1,    64,   451,    -1,    -1,   448,   447,    -1,
     453,   450,    -1,    -1,   452,    -1,   449,    -1,   102,   449,
      -1,   103,    -1,    20,    -1,    62,    -1,   532,    -1,    51,
      -1,    65,   454,    -1,    41,   440,    42,    -1,   460,    -1,
      41,   459,    42,    -1,   104,   460,    -1,    -1,   456,   455,
      -1,    -1,   460,   458,   456,    -1,    -1,   457,    -1,   532,
      -1,    51,    -1,   102,   461,    -1,   532,    -1,    51,    -1,
     465,    -1,   463,    -1,    -1,    52,   464,   411,    53,    -1,
     467,    41,   468,    42,    -1,    32,    -1,    33,    -1,    34,
      -1,    35,    -1,    36,    -1,    -1,   466,    -1,   474,    -1,
     468,   474,    -1,   472,    -1,   470,    -1,    -1,    52,   471,
     426,    53,    -1,   467,    41,   473,    42,    -1,   475,    -1,
     473,   475,    -1,   476,    -1,   462,    -1,   476,    -1,   469,
      -1,   478,    -1,   479,    -1,   478,    -1,   532,    -1,   183,
      -1,   184,    -1,   532,    -1,   522,    -1,   526,    -1,   530,
      -1,   534,    -1,   186,    -1,   481,    -1,   484,   483,    -1,
      54,   484,    -1,    -1,   483,   482,    -1,   487,   486,    -1,
      55,   487,    -1,    -1,   486,   485,    -1,   488,    -1,   491,
     489,    -1,    -1,   490,    -1,    56,   491,    -1,    57,   491,
      -1,    58,   491,    -1,    59,   491,    -1,    60,   491,    -1,
      61,   491,    -1,    67,   404,    -1,    66,    67,   404,    -1,
     492,    -1,   498,   497,    -1,   528,    -1,   529,    -1,    20,
     500,    -1,    64,   500,    -1,    -1,   494,    -1,    62,   498,
      -1,    63,   498,    -1,   493,   495,    -1,    -1,   497,   496,
      -1,   500,   499,    -1,    -1,   499,   494,    -1,    65,   501,
      -1,    62,   501,    -1,    63,   501,    -1,   501,    -1,   502,
      -1,   503,    -1,   520,    -1,   522,    -1,   526,    -1,   530,
      -1,   478,    -1,   515,    -1,    41,   480,    42,    -1,    78,
      41,   480,    42,    -1,    79,    41,   480,    42,    -1,    80,
      41,   480,    49,   480,    42,    -1,    81,    41,   480,    42,
      -1,    82,    41,   478,    42,    -1,    68,    41,   480,    42,
      -1,    69,    41,   480,    42,    -1,    70,   504,    -1,   118,
     186,    -1,   142,    41,   480,    42,    -1,   139,    41,   480,
      42,    -1,   129,    41,   480,    42,    -1,   123,    41,   480,
      42,    -1,    90,   404,    -1,   507,    -1,   145,    41,   480,
      42,    -1,   508,    -1,   143,    41,   480,    42,    -1,   141,
      41,   480,    42,    -1,   137,    41,   480,    42,    -1,   126,
      41,   480,    49,   480,    42,    -1,   138,    41,   480,    49,
     480,    42,    -1,   144,    41,   480,    49,   480,    42,    -1,
     113,    41,   480,    49,   480,    42,    -1,   114,    41,   480,
      49,   480,    42,    -1,   115,    41,   480,    42,    -1,   147,
      41,   480,    42,    -1,   140,    41,   480,    42,    -1,   136,
      41,   480,    42,    -1,   133,    41,   480,    42,    -1,   127,
      41,   480,    42,    -1,   122,    41,   480,    42,    -1,   121,
      41,   480,    42,    -1,   120,   186,    -1,   109,   186,    -1,
     110,   186,    -1,   111,    41,   480,    42,    -1,   146,    41,
     480,    42,    -1,   135,    41,   480,    42,    -1,   124,    41,
     480,    42,    -1,   119,    41,   480,    42,    -1,    71,   404,
      -1,    72,    41,   480,    49,   480,    49,   480,    42,    -1,
      73,    41,   480,    49,   480,    42,    -1,    74,    41,   480,
      49,   480,    42,    -1,    83,    41,   480,    49,   480,    42,
      -1,    84,    41,   480,    42,    -1,    85,    41,   480,    42,
      -1,    86,    41,   480,    42,    -1,    87,    41,   480,    42,
      -1,   101,    41,   480,    42,    -1,   505,    -1,   509,    -1,
     512,    -1,    41,   480,    42,    -1,   186,    -1,    88,    41,
     480,    49,   480,   506,    42,    -1,    -1,   402,    -1,   134,
      41,   480,    49,   480,   506,    42,    -1,    75,    41,   480,
      49,   480,    49,   480,   506,    42,    -1,    -1,    -1,    76,
     510,   511,   345,    -1,    -1,    -1,    66,    76,   513,   514,
     345,    -1,    94,    41,   401,   516,    42,    -1,   517,    41,
     401,   480,    42,    -1,    99,    41,   401,   480,   519,    42,
      -1,    20,    -1,   480,    -1,    95,    -1,    96,    -1,    97,
      -1,    98,    -1,   100,    -1,    50,    77,    56,   531,    -1,
      -1,   518,    -1,   532,   521,    -1,    -1,   399,    -1,   531,
     525,    -1,    89,   532,    -1,   185,    -1,   523,    -1,    -1,
     524,    -1,   527,    -1,   528,    -1,   529,    -1,   165,    -1,
     166,    -1,   167,    -1,   168,    -1,   169,    -1,   170,    -1,
     171,    -1,   172,    -1,   173,    -1,   163,    -1,   164,    -1,
     174,    -1,   176,    -1,   175,    -1,   177,    -1,   178,    -1,
     533,    -1,   180,    -1,   179,    -1,   181,    -1,   182,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SPARQLfedParser::yyprhs_[] =
  {
         0,     0,     3,     5,     7,     9,    13,    15,    17,    19,
      21,    23,    27,    28,    30,    31,    34,    35,    38,    39,
      43,    46,    47,    49,    51,    53,    55,    57,    62,    66,
      71,    72,    75,    77,    80,    82,    85,    87,    89,    90,
      94,    97,    99,   104,   108,   113,   114,   117,   119,   122,
     124,   127,   129,   131,   132,   136,   139,   141,   145,   146,
     149,   150,   155,   156,   158,   161,   162,   165,   169,   173,
     177,   180,   181,   182,   188,   189,   195,   196,   199,   200,
     201,   202,   210,   214,   216,   218,   219,   221,   224,   225,
     227,   232,   234,   236,   238,   240,   242,   244,   246,   248,
     250,   253,   255,   257,   260,   265,   270,   276,   278,   281,
     283,   285,   286,   288,   293,   296,   298,   300,   302,   305,
     307,   310,   311,   313,   318,   319,   321,   322,   324,   325,
     327,   328,   330,   334,   336,   339,   341,   343,   348,   350,
     353,   355,   358,   360,   364,   366,   369,   371,   373,   375,
     377,   380,   382,   384,   387,   390,   391,   393,   394,   396,
     399,   402,   404,   407,   408,   410,   413,   416,   417,   419,
     420,   424,   425,   427,   429,   431,   433,   435,   437,   439,
     441,   443,   445,   447,   449,   454,   455,   457,   460,   461,
     463,   467,   471,   475,   481,   487,   493,   494,   498,   499,
     503,   504,   508,   515,   518,   519,   521,   522,   524,   527,
     529,   530,   533,   536,   537,   539,   540,   544,   545,   549,
     552,   554,   557,   559,   562,   563,   565,   568,   570,   572,
     574,   576,   580,   584,   585,   589,   590,   592,   593,   595,
     598,   602,   603,   606,   607,   608,   609,   618,   621,   624,
     625,   627,   629,   631,   633,   635,   637,   638,   643,   646,
     647,   649,   653,   654,   657,   660,   663,   667,   668,   670,
     672,   674,   676,   678,   680,   682,   684,   686,   688,   690,
     692,   695,   696,   700,   701,   702,   703,   710,   711,   712,
     719,   720,   721,   730,   737,   740,   742,   744,   745,   746,
     753,   754,   757,   759,   760,   766,   767,   770,   772,   776,
     777,   780,   781,   786,   788,   789,   792,   794,   796,   798,
     800,   802,   804,   806,   807,   808,   813,   814,   815,   820,
     821,   825,   826,   829,   832,   834,   836,   838,   841,   843,
     844,   851,   852,   854,   857,   858,   861,   863,   864,   870,
     871,   875,   876,   880,   882,   883,   885,   889,   892,   893,
     895,   898,   899,   902,   904,   906,   909,   912,   913,   916,
     918,   919,   923,   924,   928,   930,   931,   933,   934,   939,
     941,   943,   944,   948,   949,   951,   954,   955,   958,   960,
     962,   965,   968,   969,   972,   974,   976,   977,   981,   984,
     985,   988,   989,   993,   996,   997,  1000,  1003,  1004,  1006,
    1008,  1011,  1013,  1015,  1017,  1019,  1021,  1024,  1028,  1030,
    1034,  1037,  1038,  1041,  1042,  1046,  1047,  1049,  1051,  1053,
    1056,  1058,  1060,  1062,  1064,  1065,  1070,  1075,  1077,  1079,
    1081,  1083,  1085,  1086,  1088,  1090,  1093,  1095,  1097,  1098,
    1103,  1108,  1110,  1113,  1115,  1117,  1119,  1121,  1123,  1125,
    1127,  1129,  1131,  1133,  1135,  1137,  1139,  1141,  1143,  1145,
    1147,  1150,  1153,  1154,  1157,  1160,  1163,  1164,  1167,  1169,
    1172,  1173,  1175,  1178,  1181,  1184,  1187,  1190,  1193,  1196,
    1200,  1202,  1205,  1207,  1209,  1212,  1215,  1216,  1218,  1221,
    1224,  1227,  1228,  1231,  1234,  1235,  1238,  1241,  1244,  1247,
    1249,  1251,  1253,  1255,  1257,  1259,  1261,  1263,  1265,  1269,
    1274,  1279,  1286,  1291,  1296,  1301,  1306,  1309,  1312,  1317,
    1322,  1327,  1332,  1335,  1337,  1342,  1344,  1349,  1354,  1359,
    1366,  1373,  1380,  1387,  1394,  1399,  1404,  1409,  1414,  1419,
    1424,  1429,  1434,  1437,  1440,  1443,  1448,  1453,  1458,  1463,
    1468,  1471,  1480,  1487,  1494,  1501,  1506,  1511,  1516,  1521,
    1526,  1528,  1530,  1532,  1536,  1538,  1546,  1547,  1549,  1557,
    1567,  1568,  1569,  1574,  1575,  1576,  1582,  1588,  1594,  1601,
    1603,  1605,  1607,  1609,  1611,  1613,  1615,  1620,  1621,  1623,
    1626,  1627,  1629,  1632,  1635,  1637,  1639,  1640,  1642,  1644,
    1646,  1648,  1650,  1652,  1654,  1656,  1658,  1660,  1662,  1664,
    1666,  1668,  1670,  1672,  1674,  1676,  1678,  1680,  1682,  1684,
    1686,  1688
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   562,   562,   565,   571,   576,   587,   588,   589,   590,
     594,   599,   603,   605,   609,   611,   614,   616,   620,   620,
     638,   644,   647,   651,   652,   653,   654,   660,   661,   662,
     665,   667,   671,   675,   679,   680,   684,   685,   689,   689,
     697,   703,   707,   708,   709,   712,   714,   718,   722,   726,
     727,   731,   732,   736,   736,   744,   750,   754,   757,   759,
     763,   763,   770,   772,   776,   779,   781,   785,   788,   791,
     797,   803,   805,   803,   815,   815,   859,   862,   870,   873,
     877,   870,   896,   908,   911,   918,   921,   926,   933,   936,
     941,   955,   960,   965,   970,   975,   978,   983,   989,   994,
     997,  1005,  1018,  1024,  1030,  1039,  1053,  1062,  1065,  1073,
    1076,  1083,  1086,  1091,  1099,  1106,  1107,  1111,  1117,  1123,
    1130,  1137,  1139,  1144,  1151,  1154,  1159,  1162,  1167,  1170,
    1175,  1179,  1183,  1190,  1193,  1200,  1203,  1206,  1215,  1221,
    1227,  1230,  1237,  1242,  1249,  1253,  1261,  1263,  1271,  1274,
    1282,  1290,  1291,  1298,  1302,  1310,  1313,  1318,  1321,  1325,
    1331,  1337,  1341,  1347,  1350,  1354,  1360,  1363,  1365,  1369,
    1369,  1378,  1380,  1384,  1385,  1386,  1387,  1388,  1389,  1390,
    1391,  1392,  1393,  1394,  1398,  1404,  1407,  1414,  1421,  1424,
    1428,  1434,  1440,  1446,  1452,  1458,  1464,  1464,  1475,  1475,
    1486,  1486,  1497,  1505,  1511,  1514,  1518,  1521,  1525,  1529,
    1536,  1539,  1548,  1554,  1557,  1561,  1561,  1570,  1570,  1579,
    1585,  1589,  1596,  1599,  1604,  1606,  1610,  1616,  1619,  1622,
    1625,  1632,  1639,  1645,  1645,  1653,  1655,  1659,  1661,  1662,
    1666,  1669,  1671,  1676,  1681,  1684,  1676,  1695,  1699,  1702,
    1704,  1708,  1709,  1722,  1723,  1724,  1729,  1729,  1740,  1744,
    1746,  1756,  1760,  1763,  1779,  1784,  1785,  1789,  1792,  1793,
    1797,  1798,  1799,  1800,  1801,  1802,  1803,  1804,  1805,  1808,
    1812,  1818,  1818,  1834,  1838,  1840,  1834,  1851,  1855,  1851,
    1864,  1868,  1864,  1885,  1901,  1907,  1908,  1912,  1914,  1912,
    1921,  1923,  1927,  1935,  1935,  1942,  1944,  1950,  1951,  1954,
    1956,  1962,  1962,  1967,  1973,  1975,  1979,  1982,  1985,  1988,
    1991,  1994,  1997,  2003,  2007,  2003,  2017,  2021,  2017,  2031,
    2031,  2043,  2045,  2049,  2059,  2060,  2061,  2065,  2073,  2077,
    2077,  2087,  2090,  2097,  2103,  2105,  2120,  2123,  2123,  2133,
    2133,  2136,  2136,  2142,  2145,  2147,  2152,  2157,  2161,  2163,
    2168,  2172,  2174,  2178,  2182,  2190,  2195,  2199,  2201,  2205,
    2213,  2213,  2216,  2216,  2222,  2225,  2227,  2231,  2231,  2237,
    2238,  2242,  2242,  2247,  2249,  2253,  2256,  2258,  2262,  2271,
    2277,  2281,  2284,  2286,  2290,  2297,  2301,  2301,  2311,  2317,
    2320,  2326,  2326,  2336,  2342,  2345,  2351,  2357,  2360,  2364,
    2365,  2371,  2374,  2377,  2383,  2386,  2389,  2392,  2401,  2402,
    2411,  2417,  2420,  2426,  2426,  2436,  2439,  2443,  2446,  2449,
    2455,  2458,  2466,  2467,  2471,  2471,  2484,  2512,  2515,  2518,
    2521,  2524,  2531,  2534,  2539,  2543,  2550,  2551,  2555,  2555,
    2567,  2594,  2598,  2605,  2606,  2610,  2611,  2615,  2618,  2622,
    2625,  2631,  2632,  2636,  2639,  2642,  2645,  2648,  2649,  2655,
    2660,  2669,  2676,  2679,  2687,  2696,  2703,  2706,  2713,  2718,
    2731,  2735,  2739,  2743,  2747,  2751,  2755,  2759,  2763,  2767,
    2774,  2779,  2788,  2791,  2798,  2801,  2808,  2811,  2816,  2819,
    2823,  2837,  2840,  2848,  2857,  2860,  2867,  2870,  2873,  2876,
    2880,  2881,  2882,  2883,  2886,  2889,  2892,  2895,  2899,  2911,
    2914,  2917,  2920,  2923,  2926,  2929,  2933,  2936,  2939,  2942,
    2945,  2948,  2951,  2954,  2955,  2958,  2959,  2962,  2965,  2968,
    2971,  2974,  2977,  2980,  2983,  2986,  2989,  2992,  2995,  2998,
    3001,  3004,  3007,  3010,  3013,  3016,  3019,  3022,  3025,  3028,
    3031,  3034,  3037,  3040,  3043,  3046,  3049,  3052,  3055,  3058,
    3061,  3062,  3063,  3069,  3078,  3085,  3092,  3095,  3099,  3105,
    3111,  3114,  3111,  3126,  3129,  3126,  3142,  3150,  3159,  3175,
    3178,  3182,  3185,  3188,  3191,  3194,  3200,  3206,  3209,  3213,
    3223,  3226,  3231,  3239,  3246,  3250,  3258,  3262,  3266,  3267,
    3268,  3272,  3273,  3274,  3278,  3279,  3280,  3284,  3285,  3286,
    3290,  3291,  3295,  3296,  3297,  3298,  3302,  3303,  3307,  3308,
    3312,  3346
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
  const int SPARQLfedParser::yylast_ = 2888;
  const int SPARQLfedParser::yynnts_ = 348;
  const int SPARQLfedParser::yyempty_ = -2;
  const int SPARQLfedParser::yyfinal_ = 11;
  const int SPARQLfedParser::yyterror_ = 1;
  const int SPARQLfedParser::yyerrcode_ = 256;
  const int SPARQLfedParser::yyntokens_ = 187;

  const unsigned int SPARQLfedParser::yyuser_token_number_max_ = 441;
  const SPARQLfedParser::token_number_type SPARQLfedParser::yyundef_token_ = 2;


} // w3c_sw

/* Line 1136 of lalr1.cc  */
#line 6424 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 3352 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
 /*** Additional Code ***/

void w3c_sw::SPARQLfedParser::error(const SPARQLfedParser::location_type& l,
				    const std::string& m)
{
    std::string s = m;
    _SUBS(s, "GT_DOT", "'.'");
    _SUBS(s, "GT_SEMI", "';'");
    _SUBS(s, "GT_LBRACKET", "'['");
    _SUBS(s, "GT_RBRACKET", "']'");
    _SUBS(s, "GT_LPAREN", "'('");
    _SUBS(s, "GT_RPAREN", "')'");
    _SUBS(s, "GT_DTYPE", "'^^'");
    _SUBS(s, "IT_true", "boolean true");
    _SUBS(s, "IT_false", "boolean false");
    _SUBS(s, "IT_BASE", "@base");
    _SUBS(s, "IT_PREFIX", "@prefix");
    _SUBS(s, "IT_a", "keyword 'a'");
    _SUBS(s, "IRIREF", "IRI");
    _SUBS(s, "PNAME_NS", "namespace prefix");
    _SUBS(s, "PNAME_LN", "local name");
    _SUBS(s, "BLANK_NODE_LABEL", "blank node label");
    _SUBS(s, "LANGTAG", "language tag");
    _SUBS(s, "INTEGER", "integer");
    _SUBS(s, "DECIMAL", "decimal");
    _SUBS(s, "DOUBLE", "double");
    _SUBS(s, "STRING_LITERAL1", "'string'");
    _SUBS(s, "STRING_LITERAL2", "\"string\"");
    _SUBS(s, "STRING_LITERAL_LONG1", "'''string'''");
    _SUBS(s, "STRING_LITERAL_LONG2", "\"\"\"string\"\"\"");
    _SUBS(s, "ANON", "anonymous blank node");

    _SUBS(s, "GT_TIMES", "'*'");
    _SUBS(s, "GT_LCURLEY", "'{'");
    _SUBS(s, "GT_RCURLEY", "'}'");
    _SUBS(s, "GT_COMMA", "','");
    _SUBS(s, "GT_OR", "'||'");
    _SUBS(s, "GT_AND", "'&&'");
    _SUBS(s, "GT_EQUAL", "'='");
    _SUBS(s, "GT_NEQUAL", "'!='");
    _SUBS(s, "GT_LT", "'<'");
    _SUBS(s, "GT_GT", "'>'");
    _SUBS(s, "GT_LE", "'<='");
    _SUBS(s, "GT_GE", "'>='");
    _SUBS(s, "GT_DIVIDE", "'/'");
    _SUBS(s, "GT_PLUS", "'+'");
    _SUBS(s, "GT_MINUS", "'-'");
    _SUBS(s, "GT_NOT", "'!'");

    _SUBS(s, "GT_CARROT", "'^'");
    _SUBS(s, "GT_OPT", "'?'");
    _SUBS(s, "GT_PIPE", "'|'");
    _SUBS(s, "GT_MINUS_GT", "'->'");
    _SUBS(s, "GT_MINUS_MINUS", "'--'");

    _SUBS(s, "INTEGER_POSITIVE", "+integer");
    _SUBS(s, "DECIMAL_POSITIVE", "+decimal");
    _SUBS(s, "DOUBLE_POSITIVE", "+double");
    _SUBS(s, "INTEGER_NEGATIVE", "-integer");
    _SUBS(s, "DECIMAL_NEGATIVE", "-decimal");
    _SUBS(s, "DOUBLE_NEGATIVE", "-double");

    _SUBS(s, "GT_H_2192_", "→");



    _SUBS(s, "ABOX_HR", "'-'");
    _SUBS(s, "UBOX_UHR", "'┌─┬┐'");
    _SUBS(s, "UBOX_LHR", "'└─┴┘'");
    _SUBS(s, "GT_H_2502_", "'│'");
    _SUBS(s, "UBOX_UL", "'┌'");
    _SUBS(s, "UBOX_U", "'─'");
    _SUBS(s, "UBOX_UR", "'┐'");
    _SUBS(s, "UBOX_LL", "'└'");
    _SUBS(s, "UBOX_L", "'─'");
    _SUBS(s, "UBOX_LR", "'┘'");
    _SUBS(s, "RSREF", "*<name>");

    _SUBS(s, "INSERTDATA", "'INSERT DATA'");
    _SUBS(s, "DELETEDATA", "'DELETE DATA'");
    _SUBS(s, "DELETEWHERE", "'DELETE WHERE'");

    _SUBS(s, "IT_DELETE", "'DELETE'");
    _SUBS(s, "IT_INSERT", "'INSERT'");
    _SUBS(s, "IT_DATA", "'DATA'");
    _SUBS(s, "IT_GRAPH", "'GRAPH'");
    _SUBS(s, "IT_SERVICE", "'SERVICE'");
    _SUBS(s, "IT_SADI", "'SADI'");
    _SUBS(s, "IT_LOAD", "'LOAD'");
    _SUBS(s, "IT_INTO", "'INTO'");
    _SUBS(s, "IT_CLEAR", "'CLEAR'");
    _SUBS(s, "IT_CREATE", "'CREATE'");
    _SUBS(s, "IT_SILENT", "'SILENT'");
    _SUBS(s, "IT_DROP", "'DROP'");
    _SUBS(s, "IT_SELECT", "'SELECT'");
    _SUBS(s, "IT_DISTINCT", "'DISTINCT'");
    _SUBS(s, "IT_REDUCED", "'REDUCED'");
    _SUBS(s, "IT_CONSTRUCT", "'CONSTRUCT'");
    _SUBS(s, "IT_DESCRIBE", "'DESCRIBE'");
    _SUBS(s, "IT_FROM", "'FROM'");
    _SUBS(s, "IT_NAMED", "'NAMED'");
    _SUBS(s, "IT_ORDER", "'ORDER'");
    _SUBS(s, "IT_BY", "'BY'");
    _SUBS(s, "IT_ASC", "'ASC'");
    _SUBS(s, "IT_DESC", "'DESC'");
    _SUBS(s, "IT_LIMIT", "'LIMIT'");
    _SUBS(s, "IT_OFFSET", "'OFFSET'");
    _SUBS(s, "IT_VALUES", "'VALUES'");
    _SUBS(s, "IT_MEMBERS", "'MEMBERS'");
    _SUBS(s, "IT_STARTS", "'STARTS'");
    _SUBS(s, "IT_ENDS", "'ENDS'");
    _SUBS(s, "IT_ANY", "'ANY'");
    _SUBS(s, "IT_UNORDERED", "'UNORDERED'");
    _SUBS(s, "IT_ASK", "'ASK'");
    _SUBS(s, "IT_WHERE", "'WHERE'");
    _SUBS(s, "IT_UNDEF", "'UNDEF'");
    _SUBS(s, "IT_OPTIONAL", "'OPTIONAL'");
    _SUBS(s, "IT_MINUS", "'MINUS'");
    _SUBS(s, "IT_UNION", "'UNION'");
    _SUBS(s, "IT_FILTER", "'FILTER'");
    _SUBS(s, "IT_NOT", "'NOT'");
    _SUBS(s, "IT_IN", "'IN'");
    _SUBS(s, "IT_IRI", "'IRI'");
    _SUBS(s, "IT_URI", "'URI'");
    _SUBS(s, "IT_BNODE", "'BNODE'");
    _SUBS(s, "IT_COALESCE", "'COALESCE'");
    _SUBS(s, "IT_IF", "'IF'");
    _SUBS(s, "IT_STRLANG", "'STRLANG'");
    _SUBS(s, "IT_STRDT", "'STRDT'");
    _SUBS(s, "IT_REPLACE", "'REPLACE'");
    _SUBS(s, "IT_EXISTS", "'EXISTS'");
    _SUBS(s, "IT_SEPARATOR", "'SEPARATOR'");
    _SUBS(s, "IT_STR", "'STR'");
    _SUBS(s, "IT_LANG", "'LANG'");
    _SUBS(s, "IT_LANGMATCHES", "'LANGMATCHES'");
    _SUBS(s, "IT_DATATYPE", "'DATATYPE'");
    _SUBS(s, "IT_BOUND", "'BOUND'");
    _SUBS(s, "IT_sameTerm", "'sameTerm'");
    _SUBS(s, "IT_isIRI", "'isIRI'");
    _SUBS(s, "IT_isURI", "'isURI'");
    _SUBS(s, "IT_isBLANK", "'isBLANK'");
    _SUBS(s, "IT_isLITERAL", "'isLITERAL'");
    _SUBS(s, "IT_REGEX", "'REGEX'");
    _SUBS(s, "IT_CONCAT", "'CONCAT'");
    _SUBS(s, "IT_AS", "'AS'");
    _SUBS(s, "IT_GROUP", "'GROUP'");
    _SUBS(s, "IT_HAVING", "'HAVING'");
    _SUBS(s, "IT_COUNT", "'COUNT'");
    _SUBS(s, "IT_SUM", "'SUM'");
    _SUBS(s, "IT_MIN", "'MIN'");
    _SUBS(s, "IT_MAX", "'MAX'");
    _SUBS(s, "IT_AVG", "'AVG'");
    _SUBS(s, "IT_GROUP_CONCAT", "'GROUP_CONCAT'");
    _SUBS(s, "IT_SAMPLE", "'SAMPLE'");
    _SUBS(s, "IT_isNUMERIC", "'isNUMERIC'");
    _SUBS(s, "IT_WITH", "'WITH'");
    _SUBS(s, "IT_DEFAULT", "'DEFAULT'");
    _SUBS(s, "IT_ALL", "'ALL'");
    _SUBS(s, "IT_USING", "'USING'");
    _SUBS(s, "IT_UUID", "'UUID'");
    _SUBS(s, "IT_STRUUID", "'STRUUID'");
    _SUBS(s, "IT_MD5", "'MD5'");
    _SUBS(s, "IT_TO", "'TO'");
    _SUBS(s, "IT_STRBEFORE", "'STRBEFORE'");
    _SUBS(s, "IT_STRAFTER", "'STRAFTER'");
    _SUBS(s, "IT_YEAR", "'YEAR'");
    _SUBS(s, "IT_ADD", "'ADD'");
    _SUBS(s, "IT_COPY", "'COPY'");
    _SUBS(s, "IT_RAND", "'RAND'");
    _SUBS(s, "IT_SHA512", "'SHA512'");
    _SUBS(s, "IT_NOW ", "'NOW '");
    _SUBS(s, "IT_TZ", "'TZ'");
    _SUBS(s, "IT_TIMEZONE", "'TIMEZONE'");
    _SUBS(s, "IT_ROUND", "'ROUND'");
    _SUBS(s, "IT_SHA384", "'SHA384'");
    _SUBS(s, "IT_BIND", "'BIND'");
    _SUBS(s, "IT_CONTAINS", "'CONTAINS'");
    _SUBS(s, "IT_SECONDS", "'SECONDS'");
    _SUBS(s, "IT_MOVE", "'MOVE'");
    _SUBS(s, "IT_FLOOR", "'FLOOR'");
    _SUBS(s, "IT_MINUTES", "'MINUTES'");
    _SUBS(s, "IT_SUBSTR", "'SUBSTR'");
    _SUBS(s, "IT_SHA256", "'SHA256'");
    _SUBS(s, "IT_HOURS", "'HOURS'");
    _SUBS(s, "IT_ENCODE_FOR_URI", "'ENCODE_FOR_URI'");
    _SUBS(s, "IT_STRSTARTS", "'STRSTARTS'");
    _SUBS(s, "IT_CEIL", "'CEIL'");
    _SUBS(s, "IT_DAY", "'DAY'");
    _SUBS(s, "IT_LCASE", "'LCASE'");
    _SUBS(s, "IT_ABS", "'ABS'");
    _SUBS(s, "IT_UCASE", "'UCASE'");
    _SUBS(s, "IT_STRENDS", "'STRENDS'");
    _SUBS(s, "IT_STRLEN", "'STRLEN'");
    _SUBS(s, "IT_SHA1", "'SHA1'");
    _SUBS(s, "IT_MONTH", "'MONTH'");
    _SUBS(s, "IT_PRINT", "'PRINT'");

    _SUBS(s, "VAR1", "?VAR");
    _SUBS(s, "VAR2", "$VAR");
    _SUBS(s, "NIL", "'()'");
    driver.error(l, s);
}

/* START Driver (@@ stand-alone would allow it to be shared with other parsers */

namespace w3c_sw {

size_t SPARQLfedDriver::DefaultAbortErrorCount = 100;

    SPARQLfedDriver::e_Validation SPARQLfedDriver::DefaultValidation = SPARQLfedDriver::VALIDATE_all;

Operation* SPARQLfedDriver::parse (IStreamContext& in)
{
    reset();
    root = NULL;
    curBGP = NULL;
    curOp = NULL;
    bnode2bgp.clear();
    bnodesInOldOpperations.clear();
    bnodesInThisOpperation.clear();
    inINSERTQUAD   = false;
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
    bnode2bgp.clear();
    bnodesInOldOpperations.clear();
    bnodesInThisOpperation.clear();
    checkErrors();
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


