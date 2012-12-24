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
#line 361 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"

/* Line 299 of lalr1.cc  */
#line 528 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

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
#line 553 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 556 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 567 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 611 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.startBindingSet();
      }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 614 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 629 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = (yysemantic_stack_[(2) - (1)].p_RSName);
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 635 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = NULL;
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 645 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	throw std::runtime_error("need to partition out results set part of SimpleEngine::loadDataOrResults");
    }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 679 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 681 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 687 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 725 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 727 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 733 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 752 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow(false);
      }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 754 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 774 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 777 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 780 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 786 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 792 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 794 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 796 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 804 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 807 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.validate & VALIDATE_selectGrouped) {
	    const ExpressionAliasList* e = (yysemantic_stack_[(5) - (5)].p_SolutionModifier)->getGroupedBy();
	    if (e) {
		std::set<const TTerm*> errorSet = (yysemantic_stack_[(5) - (2)].p_Project).varSet->getNonProjectableVars(e, driver.atomFactory);
		if (errorSet.size() != 0)
		    error(yylloc, "can't select " + comma_str(errorSet) + " because "
			  + (errorSet.size() == 1 ? "it's" : "they're") + "not in a GROUP BY.");
	    }
	}
	if (driver.validate & VALIDATE_noReassign) {
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

  case 74:

/* Line 690 of lalr1.cc  */
#line 848 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 851 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 859 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
      }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 862 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 866 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 873 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if ((yysemantic_stack_[(7) - (4)].p_GraphName) != NULL)
	      driver.curGraphName = (yysemantic_stack_[(7) - (4)].p_GraphName);
	  if ((yysemantic_stack_[(7) - (7)].p_ValuesClause) != NULL)
	      (yysemantic_stack_[(7) - (5)].p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yysemantic_stack_[(7) - (5)].p_WhereClause)->m_GroupGraphPattern, (yysemantic_stack_[(7) - (7)].p_ValuesClause));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (3)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(7) - (2)].p_Project).distinctness, (yysemantic_stack_[(7) - (2)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(7) - (5)].p_WhereClause), (yysemantic_stack_[(7) - (6)].p_SolutionModifier))));
	  driver.countStar = (yysemantic_stack_[(7) - (1)].p_parentCountStar);
      }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 885 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 893 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 896 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 903 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 911 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 918 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 926 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.validate & VALIDATE_namedProjection && (yysemantic_stack_[(4) - (3)].p_Variable) == NULL)
	    error(yylloc, (yysemantic_stack_[(4) - (2)].p_Expression)->str() + " must be selected AS some variable");
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 935 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.validate & VALIDATE_namedProjection)
	    error(yylloc, (yysemantic_stack_[(1) - (1)].p_Expression)->str() + " must be selected AS some variable");
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 940 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.validate & VALIDATE_namedProjection)
	    error(yylloc, (yysemantic_stack_[(1) - (1)].p_RDFLiteral)->str() + " must be selected AS some variable");
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 945 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.validate & VALIDATE_namedProjection)
	    error(yylloc, (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)->str() + " must be selected AS some variable");
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 950 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.validate & VALIDATE_namedProjection)
	    error(yylloc, (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)->str() + " must be selected AS some variable");
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 955 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 958 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.validate & VALIDATE_namedProjection)
	    error(yylloc, (yysemantic_stack_[(1) - (1)].p_Expression)->str() + " must be selected AS some variable");
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 963 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.validate & VALIDATE_namedProjection)
	    error(yylloc, (yysemantic_stack_[(1) - (1)].p_Expression)->str() + " must be selected AS some variable");
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 974 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 977 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 985 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.validate & VALIDATE_uniqueProjection) {
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

  case 100:

/* Line 690 of lalr1.cc  */
#line 998 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1004 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(2) - (2)].p_Operation);
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1010 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.validate & VALIDATE_constructNoQuads &&
	    dynamic_cast<const DefaultGraphPattern*>((yysemantic_stack_[(4) - (1)].p_TableOperation)) == NULL) {
	    error(yylloc, "can't CONSTRUCT quad pattern " + (yysemantic_stack_[(4) - (1)].p_TableOperation)->str() + ".");
	}
	driver.lastWhereClause = (yysemantic_stack_[(4) - (3)].p_WhereClause);
	/* $1 is NO LONGER known to be a DefaultGraphPattern because of grammar restrictions. */
	(yyval.p_Operation) = new Construct((yysemantic_stack_[(4) - (1)].p_TableOperation), (yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1019 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.validate & VALIDATE_constructNoQuads &&
	    dynamic_cast<const DefaultGraphPattern*>((yysemantic_stack_[(4) - (3)].p_TableOperation)) == NULL) {
	    error(yylloc, "can't re-CONSTRUCT quad pattern " + (yysemantic_stack_[(4) - (3)].p_TableOperation)->str() + ".");
	}
	SWObjectDuplicator dup(driver.atomFactory);
	(yysemantic_stack_[(4) - (3)].p_TableOperation)->express(&dup);
	driver.lastWhereClause = new WhereClause((yysemantic_stack_[(4) - (3)].p_TableOperation));
	(yyval.p_Operation) = new Construct(dup.last.tableOperation, (yysemantic_stack_[(4) - (1)].p_DatasetClauses), driver.lastWhereClause, (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1033 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause) ? (yysemantic_stack_[(5) - (4)].p_WhereClause) : new WhereClause(new DefaultGraphPattern());
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1041 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm))));
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1044 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_TTerm))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1052 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1055 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1062 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1070 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(4) - (3)].p_WhereClause);
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1078 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1090 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1096 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1102 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1109 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.ensureGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1123 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1130 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1138 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1146 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1154 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1162 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1169 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1172 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1179 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1182 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1185 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1188 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1194 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1200 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1203 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1215 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1222 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1226 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1236 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1244 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1247 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1255 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1264 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1271 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1275 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1283 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1291 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1298 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1304 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 1314 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ValuesClause) = (yysemantic_stack_[(2) - (2)].p_ValuesClause);
    }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 1320 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ValuesClause) = NULL;
    }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 1327 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Operation) = driver.root;
      }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1342 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	OperationSet* ret = driver.root ? dynamic_cast<OperationSet*>(driver.root) : new OperationSet();
	ret->push_back((yysemantic_stack_[(1) - (1)].p_Operation));
	driver.root = ret;
	std::copy(driver.bnodesInThisOpperation.begin(), driver.bnodesInThisOpperation.end(),
		  std::inserter(driver.bnodesInOldOpperations, driver.bnodesInOldOpperations.begin()));
      }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 1371 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(4) - (2)].p_Silence), (yysemantic_stack_[(4) - (3)].p_URI), (yysemantic_stack_[(4) - (4)].p_URI));
    }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 1377 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 1380 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 1387 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 1394 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1401 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1407 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1413 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1419 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1425 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1431 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1437 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.inINSERTDATA = true;
      }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1439 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.inINSERTDATA = false;
	  (yyval.p_Operation) = new Insert((yysemantic_stack_[(3) - (3)].p_TableOperation), NULL);
	  driver.curOp = NULL;
	  driver.curBGP = NULL;
	}
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1448 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.inDELETEDATA = true;
      }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1450 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.inDELETEDATA = false;
	  (yyval.p_Operation) = new Delete(true, (yysemantic_stack_[(3) - (3)].p_TableOperation), NULL);
	  driver.curOp = NULL;
	  driver.curBGP = NULL;
	}
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1459 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.inDELETEWHERE = true;
      }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1461 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.inDELETEWHERE = false;
	  (yyval.p_Operation) = new Delete(true, (yysemantic_stack_[(3) - (3)].p_TableOperation), NULL);
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1470 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(6) - (2)].p_DeleteInsert).del, (yysemantic_stack_[(6) - (2)].p_DeleteInsert).ins, new WhereClause(driver.ensureGraphPattern()), (yysemantic_stack_[(6) - (4)].p_TableOperation), (yysemantic_stack_[(6) - (1)].p_URI), (yysemantic_stack_[(6) - (3)].p_UsingPairs));
	driver.curOp = NULL;
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1477 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1483 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 1490 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 1497 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 1501 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 1508 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_UsingPairs) = NULL;
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 1511 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (1)].p_UsingPairs) == NULL)
	    (yysemantic_stack_[(2) - (1)].p_UsingPairs) = new std::vector<s_UsingPair>();
	(yysemantic_stack_[(2) - (1)].p_UsingPairs)->push_back((yysemantic_stack_[(2) - (2)].p_UsingPair));
	(yyval.p_UsingPairs) = (yysemantic_stack_[(2) - (1)].p_UsingPairs);
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 1520 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(2) - (2)].p_TableOperation);
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 1526 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = NULL;
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 1533 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.inDELETECLAUSE = true;
      }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 1535 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.inDELETECLAUSE = false;
	  (yyval.p_Delete) = new Delete(false, (yysemantic_stack_[(3) - (3)].p_TableOperation), NULL);
      }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 1542 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.inINSERTQUAD = true;
      }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 1544 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.inINSERTQUAD = false;
	  (yyval.p_Insert) = new Insert((yysemantic_stack_[(3) - (3)].p_TableOperation), NULL);
      }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 1551 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_UsingPair) = (yysemantic_stack_[(2) - (2)].p_UsingPair);
    }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 1557 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_UsingPair).named = false;
	(yyval.p_UsingPair).name = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 219:

/* Line 690 of lalr1.cc  */
#line 1561 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_UsingPair).named = true;
	(yyval.p_UsingPair).name = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 1568 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 1571 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 224:

/* Line 690 of lalr1.cc  */
#line 1582 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 1588 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 1591 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = driver.atomFactory->getURI("tag:eric@w3.org,2012-swobjparm/DEFAULT");
    }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 1594 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = driver.atomFactory->getURI("tag:eric@w3.org,2012-swobjparm/NAMED");
    }
    break;

  case 228:

/* Line 690 of lalr1.cc  */
#line 1597 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = driver.atomFactory->getURI("tag:eric@w3.org,2012-swobjparm/ALL");
    }
    break;

  case 229:

/* Line 690 of lalr1.cc  */
#line 1604 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
	driver.curOp = NULL;
    }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 1611 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
    }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 1617 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 1619 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TableOperation) = driver.ensureGraphPattern();
	  driver.curOp = NULL;
      }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 1647 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 1652 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 1655 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 1658 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.ensureGraphPattern()));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 1680 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 252:

/* Line 690 of lalr1.cc  */
#line 1699 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 1701 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 1773 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_ValuesClause)) : (yysemantic_stack_[(1) - (1)].p_ValuesClause);
    }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 1780 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Print(driver.ensureGraphPattern());
    }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 1786 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 1790 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 277:

/* Line 690 of lalr1.cc  */
#line 1802 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 1806 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_FilterExpressions) = driver.saveFilter();
      }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 1808 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 1811 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_FilterExpressions));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.ensureGraphPattern()));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 1819 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 1823 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_FilterExpressions) = driver.saveFilter();
      }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 1825 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_FilterExpressions));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(6) - (5)].p_TTerm), driver.ensureGraphPattern(), (yysemantic_stack_[(6) - (4)].p_Silence), driver.atomFactory, false));
      }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 1832 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 1836 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_FilterExpressions) = driver.saveFilter();
      }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 1838 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 287:

/* Line 690 of lalr1.cc  */
#line 1853 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	const TableOperation* op = driver.ensureGraphPattern();
	if (driver.validate & VALIDATE_noReassign &&
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

  case 288:

/* Line 690 of lalr1.cc  */
#line 1869 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ValuesClause) = (yysemantic_stack_[(2) - (2)].p_ValuesClause);
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 1880 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 1882 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
      }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 1884 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ValuesClause) = new ValuesClause(driver.endBindingSet());
      }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 1895 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
	driver.endBindingRow();
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 1903 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 1905 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ValuesClause) = new ValuesClause(driver.endBindingSet());
      }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 1912 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 1924 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 1930 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 1932 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 1935 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 1947 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 1950 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 1953 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 1956 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 1959 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 1962 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 1965 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 1971 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 1975 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_FilterExpressions) = driver.saveFilter();
      }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 1977 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_FilterExpressions));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 1985 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 1989 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_FilterExpressions) = driver.saveFilter();
      }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 1991 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_FilterExpressions));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 1999 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 2004 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.ensureGraphPattern());
      }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 2017 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    driver.ensureGraphPattern();
	    driver.curFilter = new FilterExpressions();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 2033 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 2041 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 2045 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 2048 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yysemantic_stack_[(6) - (4)].p_Expressions);
      }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 2055 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 2058 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 2065 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 2073 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 2087 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 2090 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 2093 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(5) - (3)].p_Expressions);
      }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 2100 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 2103 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 2145 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 2149 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::RDF_type;
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 2172 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)), true);
    }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 2180 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 2183 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 2198 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 2209 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 2229 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	const URI* t = (yysemantic_stack_[(1) - (1)].p_PropertyPath)->release();
	// if (!t)
	//     w3c_sw_LINEN << "property path: " << $1->str() << "\n";
	(yyval.p_TTerm) = t ? t : (const TTerm*)new PropertyPath((yysemantic_stack_[(1) - (1)].p_PropertyPath));
    }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 2238 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 2257 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)), true);
    }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 2268 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = driver.lastPropertyPathAlternative;
	driver.lastPropertyPathAlternative = (yysemantic_stack_[(1) - (1)].p_PropertyPath);
      }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 2271 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (3)].p_PropertyPath) ? (yysemantic_stack_[(3) - (3)].p_PropertyPath) : (yysemantic_stack_[(3) - (1)].p_PropertyPath);
	  driver.lastPropertyPathAlternative = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
      }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 2278 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(2) - (2)].p_PropertyPath);
    }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 2284 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = NULL;
    }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 2287 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Alternative((yysemantic_stack_[(2) - (1)].p_PropertyPath) ? (yysemantic_stack_[(2) - (1)].p_PropertyPath) : driver.lastPropertyPathAlternative, (yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 2293 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = driver.lastPropertyPathSequence;
	driver.lastPropertyPathSequence = (yysemantic_stack_[(1) - (1)].p_PropertyPath);
      }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 2296 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {	
	  (yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (3)].p_PropertyPath) ? (yysemantic_stack_[(3) - (3)].p_PropertyPath) : (yysemantic_stack_[(3) - (1)].p_PropertyPath);
	  driver.lastPropertyPathSequence = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
      }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 2303 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(2) - (2)].p_PropertyPath);
    }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 2309 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = NULL;
    }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 2312 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Sequence((yysemantic_stack_[(2) - (1)].p_PropertyPath) ? (yysemantic_stack_[(2) - (1)].p_PropertyPath) : driver.lastPropertyPathSequence, (yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 2318 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(2) - (2)].p_RepeatRange).min == 1 && (yysemantic_stack_[(2) - (2)].p_RepeatRange).max == 1 ? (yysemantic_stack_[(2) - (1)].p_PropertyPath) : new PropertyPath::Repeated((yysemantic_stack_[(2) - (1)].p_PropertyPath), (yysemantic_stack_[(2) - (2)].p_RepeatRange).min, (yysemantic_stack_[(2) - (2)].p_RepeatRange).max);
    }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 2324 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RepeatRange).min = 1; (yyval.p_RepeatRange).max = 1;
    }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 2332 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Inverse((yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 2338 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RepeatRange).min = 0; (yyval.p_RepeatRange).max = 1;
    }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 2341 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RepeatRange).min = 0; (yyval.p_RepeatRange).max = PropertyPath::Repeated::Unlimited;
    }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 2344 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RepeatRange).min = 1; (yyval.p_RepeatRange).max = PropertyPath::Repeated::Unlimited;
    }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 2350 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 2353 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate(TTerm::RDF_type);
    }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 2356 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Negated((yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 2359 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
    }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 2366 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
    }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 2372 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(2) - (2)].p_PropertyPath);
    }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 2378 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = NULL;
    }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 2381 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Alternative((yysemantic_stack_[(2) - (1)].p_PropertyPath) ? (yysemantic_stack_[(2) - (1)].p_PropertyPath) : driver.lastPropertyPathSetAlternative, (yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 2387 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = driver.lastPropertyPathSetAlternative;
	driver.lastPropertyPathSetAlternative = (yysemantic_stack_[(1) - (1)].p_PropertyPath);
      }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 2390 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.lastPropertyPathSetAlternative = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
	  (yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (3)].p_PropertyPath);
      }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 2397 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = NULL;
    }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 2404 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 2407 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate(TTerm::RDF_type);
    }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 2410 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Inverse((yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 2416 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 2419 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate(TTerm::RDF_type);
    }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 2432 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 2436 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 2445 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 431:

/* Line 690 of lalr1.cc  */
#line 2473 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 2476 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 2479 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 2482 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 2485 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 2492 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 2500 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 2504 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 2516 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 2520 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject;
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 2528 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 445:

/* Line 690 of lalr1.cc  */
#line 2555 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 2559 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 2576 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 2583 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 2586 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 2597 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 2600 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 2603 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 2606 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 2610 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::RDF_nil; // !!! new GraphTerm_rule5($1);
    }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 2621 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 2630 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 2637 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 2640 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 2648 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 2657 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 2664 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 2667 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 2679 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 474:

/* Line 690 of lalr1.cc  */
#line 2692 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = NULL;
    }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 2700 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 2704 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 2708 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 2712 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 2716 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 2720 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 2724 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 2728 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = true;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 2740 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 2749 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 2752 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 2759 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 2762 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 2769 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 2777 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 2780 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 2784 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 495:

/* Line 690 of lalr1.cc  */
#line 2798 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 2801 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 2809 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 2818 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 2821 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 2828 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 2831 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 2834 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 2844 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 2847 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 2850 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 2853 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 2860 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 2866 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 2869 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 2872 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 2875 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 2878 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 2881 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
      (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), new TTermExpression(driver.atomFactory->getURI(driver.getBase())), NULL));
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 2884 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
      (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), new TTermExpression(driver.atomFactory->getURI(driver.getBase())), NULL));
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 2888 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 2891 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 2894 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 2897 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ceil, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 2900 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 2903 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 2906 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 2910 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 2914 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 2917 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 2920 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 2923 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 2926 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 2929 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 2932 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 2935 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 2938 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 2941 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 2944 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 2947 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 2950 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 2953 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 2956 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 2959 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_tz, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 2962 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 2965 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_uuid, NULL, NULL, NULL));
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 2968 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_struuid, NULL, NULL, NULL));
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 2971 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 2974 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 2977 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 2980 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 2983 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 2986 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 2989 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 2992 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 2995 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 2998 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 3001 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 3004 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 3007 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 3010 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 3013 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 3024 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 3027 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 3034 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 3041 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 3048 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 3054 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_replace, (yysemantic_stack_[(9) - (3)].p_Expression), (yysemantic_stack_[(9) - (5)].p_Expression), (yysemantic_stack_[(9) - (7)].p_Expression))); // !! , $8
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 3060 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 3063 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 3067 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expression) = new ExistsExpression(driver.ensureGraphPattern());
	  driver.curOp = (yysemantic_stack_[(4) - (3)].p_TableOperation);
	  driver.countStar = (yysemantic_stack_[(4) - (2)].p_parentCountStar);
      }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 3075 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
      }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 3078 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 3082 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  // $$ = new ExistsExpression(false, driver.ensureGraphPattern());
	  (yyval.p_Expression) = new BooleanNegation(new ExistsExpression(driver.ensureGraphPattern()));
	  driver.curOp = (yysemantic_stack_[(5) - (4)].p_TableOperation);
	  driver.countStar = (yysemantic_stack_[(5) - (3)].p_parentCountStar);
      }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 3091 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 3095 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 3100 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  AggregateCall::ScalarVals svals;
	  if ((yysemantic_stack_[(6) - (5)].p_RDFLiteral) != NULL)
	      svals["separator"] = (yysemantic_stack_[(6) - (5)].p_RDFLiteral)->getLexicalValue();
	  (yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression), svals));
    }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 3109 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 3116 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 3119 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 3122 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 3125 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 3128 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 3134 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 3140 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 3147 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 3157 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 3165 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 3173 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 3180 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 3184 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 3192 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 3246 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.validate & VALIDATE_bnodeScope) {
	    driver.ensureBasicGraphPattern();

	    // prohibit e.g. ASK WHERE { {_:x :a :b } {_:x :c :d } }
	    // but not:
	    //   INSERT { _:b :a :b } WHERE {}; INSERT { _:b :c :d } WHERE {};
	    //   INSERT DATA { _:b :a :b }; INSERT DATA { _:b :c :d };
	    //   INSERT DATA { GRAPH <g1>{_:b :a :b } GRAPH <g2>{ _:b :c :d } }
	    if (!driver.inINSERTQUAD && !driver.inINSERTDATA) {
		if (driver.bnode2bgp.find((yysemantic_stack_[(1) - (1)].p_TTerm)) != driver.bnode2bgp.end())
		    error((yyloc), "bnode " + (yysemantic_stack_[(1) - (1)].p_TTerm)->str() +
			  " already scoped to " + driver.bnode2bgp[(yysemantic_stack_[(1) - (1)].p_TTerm)]->str());
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
#line 4361 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -844;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        66,   -83,   106,  -844,  -844,  -844,   680,  -844,  -844,  -844,
    -844,  -844,    96,    96,    96,    96,    74,     2,  -844,  -110,
      96,    96,    96,  -844,  -844,  -844,    87,  -844,   103,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,   127,   110,  -844,
    -110,   146,   122,   146,  -844,    50,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,   101,  -844,  -844,  -844,  -844,  -844,
      55,  -844,    35,    35,    35,   125,   125,    74,    -3,  -844,
    -844,  -844,   147,  -844,    90,  -844,  -844,  -844,   143,  -844,
    -844,    59,  -844,   158,  -110,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,   171,  1182,    12,    74,  -844,    55,  -844,    52,
    -844,   119,     8,  -844,  -844,   112,  -110,   133,   137,  -844,
    -844,  -844,  -844,  -844,  -844,    -9,  -844,     1,  -844,  -844,
    -844,  1562,    55,    66,  -844,  -844,    74,    74,    30,  -844,
    -844,    80,   207,  -844,  -844,  -844,   122,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,   224,  -844,  -844,
    -844,  -844,   243,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,   -34,  -844,  -844,  -110,  -844,  -844,  -844,  -844,
    -844,   119,   119,   119,  -844,   270,  -844,   206,  -844,  -844,
    -844,  -844,  -844,    35,  -844,    35,    35,   263,  -844,  -844,
    -844,   267,  -844,  1993,   240,   302,   303,     3,     7,   304,
     308,   309,   311,  -844,   313,   315,   320,   322,   323,   326,
     334,   336,   337,   338,   340,     7,   341,  -844,  -844,  -844,
    -844,   342,  -844,   343,   134,   197,   345,   346,   348,   349,
     203,   351,   205,   353,   354,   355,   356,   358,   359,   360,
     361,   362,   363,   364,   365,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,  -844,  -844,  2114,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,   377,  -844,
    -844,  -844,    13,   119,   357,  -844,  -844,  -844,    74,    16,
    -844,   380,  -844,  -844,  -844,   109,  -844,    94,   416,  1182,
    -844,  -844,    94,  1823,    94,  -110,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  2356,  2483,   399,  -844,  1156,  -844,
    -844,  -844,  -844,   389,    14,  -844,  1993,  2235,  2235,  2235,
    -844,   339,  -844,  -844,  -844,  -844,   281,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,    13,  -844,
    1993,  1993,  1993,  -844,  -844,  1993,  -844,  -844,  1993,  1993,
    1993,  1993,  -844,  1993,  1993,  1993,  1993,    -9,  1993,  1993,
    1993,  1993,  1993,  1993,  -844,   409,   409,  1993,  -844,  -844,
    1993,  1993,  1993,  1993,  -844,  1993,  -844,  1993,  1993,  1993,
    1993,  1993,  1993,  1993,  1993,  1993,  1993,  1993,  1993,  1993,
    1993,  1993,  1993,  1993,  1993,  1993,  1993,  1993,  1993,  -844,
     409,   409,  -844,  -844,  -844,  -844,  -110,  -844,  -844,     8,
     249,  -844,  2341,  -844,  -844,  1095,  -844,  -844,   327,  -844,
    -844,   278,  -844,  -844,  -844,  -844,   382,  1823,  -844,  -844,
     392,   431,  -844,  -844,  -844,  -844,  -844,  1206,  -844,  -844,
    -844,  -844,  1993,  2356,  -844,  -844,  -844,  -844,  2483,  -844,
    -844,  -844,  -844,  -844,   412,   226,  -844,  -844,  -844,   103,
     403,  -844,  -844,  -844,   398,   404,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,   -13,   402,  -844,  -844,  -844,    -9,  -844,
     405,   394,   391,  1993,  1993,  1993,  1993,  1993,  1993,   384,
       7,  -844,  -844,   154,    60,  -844,  -844,  -844,   407,   410,
     411,  -844,   406,   408,   414,   415,     8,   417,   418,   420,
     425,   428,   422,   433,   434,   435,   437,   441,  -844,  1386,
    1993,   438,   440,   443,   445,   442,   444,   453,   455,   456,
     457,   451,   459,   460,   462,   458,   464,   466,   468,   463,
     471,   472,   473,   474,   475,   476,   478,   480,   481,  1993,
    1993,  -844,  -844,  -844,    41,  -844,  -844,  -844,  1420,  -844,
    -844,   350,  -844,  -844,  -844,  -844,  -844,  -844,  1420,  -844,
    -844,   328,  -844,    15,  -844,    -7,  -844,  -844,  -844,  -844,
    -844,  1182,   101,  -844,  -844,   339,  -844,  -844,  1683,   366,
     378,  -844,  -844,   494,   498,    62,  -844,  -844,    77,  1747,
    -844,  -844,  1847,    62,    62,   878,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  1993,  -844,  1993,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,     7,  -844,  1993,  1993,    60,  -844,  -844,
    -844,  1993,  1993,  -844,     8,  -844,  -844,  -844,  -844,  1993,
    1993,  1993,  1993,  -844,  -844,  -844,  1993,  -844,  -844,  1993,
    -844,  -844,  -844,  -844,  1993,  -844,  -844,   486,   482,  -844,
    -844,  1993,  1993,  -844,  -844,  -844,  -844,  -844,  -844,  1993,
    -844,  -844,  -844,  1993,  -844,  -844,  -844,  1993,  -844,  -844,
    -844,  -844,  -844,  1993,  -844,  -844,  -844,   488,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,   -46,  -844,  -844,  -844,
     123,  -844,  -844,  -844,   484,   487,  -844,  -844,   489,  -844,
    -844,  1683,  -844,   496,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,    47,  -844,    53,    91,   490,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,    54,  -844,  -844,
    -844,  -844,  -844,  -844,    -3,  -844,  -844,  2483,   499,     8,
    -844,   392,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  1799,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,    27,   492,   493,   497,
     500,   505,   506,   502,  -844,   491,  -844,   510,   511,   513,
     515,   502,   516,   522,  -844,  -844,  -844,  -844,  -844,  2341,
    -844,  -844,  1095,    94,  -844,  1823,  -844,   530,  -844,  -844,
    -844,   528,    56,  -844,    -8,  -844,  -844,  -844,  -844,  -844,
    1847,  -844,  -844,  -844,  -844,  -844,  -844,  -844,   534,  -844,
    -844,  -844,  -844,     8,  -844,  -844,  1993,  -844,  1747,     8,
    -844,  -844,  1127,  -844,  1993,  -844,  1993,  -844,  -844,  1993,
    -844,  -844,  -844,   533,   520,  -844,  -844,  -844,  -844,   536,
    -844,  -844,    68,  1772,  -844,  -844,  -844,  -844,  1823,  -844,
    -844,  -844,  -844,   538,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,   479,   518,   119,   101,    96,    96,  -844,     8,   495,
    -844,  -844,  -844,  -844,  -844,   542,   502,  -844,   -43,  -844,
    -844,  -844,  -844,   539,    81,  -844,  1182,  -844,  -844,   535,
     540,    47,  -844,    47,  -844,    87,  -844,   101,   101,  -844,
      -9,   549,  -844,   555,  -844,  -844,  -844,  1420,  1420,  1420,
     560,   501,    62,  -844,  1847,  -844,  -844,  -844,  -844,     8,
       8,   576,   561,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
      56,  -844,  -844,  -844,  -844,  -844,  -844,  -844,    74,  -844,
       8,  -844,  1823,   534,  -844,  -844,  -844
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        12,     0,     0,     2,     4,     3,   202,    14,    13,    10,
      68,     1,   183,   183,   183,   183,    74,     0,    74,     0,
     183,   183,   183,   194,   196,   198,   161,     6,     0,     7,
       8,     9,   170,   163,   167,   171,   172,   173,   177,   174,
     175,   176,   178,   179,   180,   181,   203,     0,    16,   184,
       0,     0,     0,     0,   231,     0,   101,    74,   108,   620,
     623,   622,   455,   456,   107,    74,   105,   453,   454,   621,
     119,   201,   222,   222,   222,     0,     0,     0,   291,     5,
     162,   159,    83,    74,   165,   213,   215,   208,   204,   207,
      69,    11,    15,   186,     0,   227,   226,   228,   225,   188,
     190,   189,     0,   233,     0,     0,    75,   119,   106,   109,
     120,   122,     0,   223,   220,     0,     0,     0,     0,   231,
     195,   197,   199,   160,   289,     0,   290,     0,    81,    82,
      84,     0,   119,    12,   166,   168,     0,     0,   211,   206,
     205,     0,     0,    17,    22,    18,     0,   187,   182,   224,
     229,   431,   432,   433,   434,   435,   428,   614,   615,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   616,   618,
     617,   619,   624,   625,   462,   238,   234,   246,   345,   427,
     426,   437,     0,   343,   451,   452,   458,   459,   602,   603,
     604,   460,   600,   457,   461,     0,   112,   113,   114,   115,
     117,   122,   122,   122,   110,     0,   111,   124,   123,   252,
     249,   118,   248,   222,   221,   222,   222,     0,   292,   299,
     301,     0,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   574,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   585,   586,   587,
     588,     0,   589,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    99,    80,    95,
      93,    89,   564,   527,   529,   565,   566,    94,     0,    90,
      91,    92,     0,   122,   202,   164,   214,   216,     0,     0,
     212,     0,   209,    70,    20,     0,   185,     0,   232,   233,
     247,   244,   348,   436,     0,     0,   598,   599,   601,   596,
     116,   103,   102,   104,     0,     0,   126,   125,   255,   191,
     193,   192,   230,     0,     0,   308,     0,     0,     0,     0,
     510,    86,   463,   466,   470,   472,   474,   484,   495,   498,
     503,   504,   505,   511,   506,   507,   508,   509,   594,   577,
       0,     0,     0,   568,   520,     0,   340,   554,     0,     0,
       0,     0,   575,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   526,   335,   335,     0,   547,   548,
       0,     0,     0,     0,   521,     0,   546,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    98,
     335,   335,   332,   331,    73,   210,     0,   217,   218,     0,
       0,    56,     0,    31,    45,     0,    19,    23,     0,    29,
      24,     0,    43,    25,    26,   358,     0,   436,   357,   239,
     235,     0,   245,   346,   347,   349,   448,   436,   438,   447,
     344,   597,     0,   130,   131,   134,   136,   133,   137,   138,
     140,   330,   328,   329,     0,   128,   127,   442,   250,     0,
       0,   251,   258,   256,   262,     0,   366,   441,   440,   364,
     294,   302,   300,     0,     0,   501,   502,   500,     0,    87,
       0,   464,   468,     0,     0,     0,     0,     0,     0,     0,
       0,   473,   475,   485,   497,   595,   593,   578,     0,     0,
       0,   341,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   336,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   219,   200,    71,     0,   314,    35,   315,    36,    32,
      33,     0,   316,   311,   312,   313,   310,    49,    50,    46,
      47,     0,    29,     0,    43,     0,   429,   355,   361,   363,
     236,   233,     0,   430,   439,    86,   132,   139,     0,     0,
       0,   121,   129,   153,   155,     0,    77,   253,   320,   255,
     263,   260,   436,   369,     0,     0,   298,   305,   307,   309,
     512,    85,    88,     0,   467,     0,   471,   476,   477,   478,
     479,   480,   481,     0,   482,     0,     0,   490,   496,   486,
     487,     0,     0,   499,     0,   518,   519,   567,   338,     0,
       0,     0,     0,   576,   513,   514,     0,   516,   517,     0,
     559,   560,   561,   562,     0,   583,   584,     0,   591,   563,
     549,     0,     0,   538,   553,   545,   544,   525,   552,     0,
     543,   524,   542,     0,   551,   541,   532,     0,   523,   540,
     531,   522,   530,     0,   528,   550,   539,     0,   333,    55,
      58,    57,    34,    39,    48,    53,     0,    28,    37,    30,
       0,    42,    51,    44,   350,   359,   237,   241,     0,   146,
     147,   141,   142,     0,   144,   145,   149,   150,   157,   158,
     151,   154,   152,   156,     0,   409,     0,     0,     0,   371,
     373,   374,   382,   389,   390,   403,   395,   401,   383,   408,
      78,   277,   281,   284,   291,   275,   317,     0,     0,     0,
     259,   235,   273,   265,   267,   268,   269,   271,   272,   266,
     264,   321,   270,   261,   450,   436,   445,   449,   367,   368,
     370,   365,   293,   295,   296,   303,   465,   469,   483,   492,
     493,   491,   494,   488,   489,   579,     0,     0,     0,     0,
       0,     0,     0,   570,   580,     0,   592,     0,     0,     0,
       0,   570,     0,     0,   581,   338,    63,    40,    27,     0,
      54,    41,     0,   352,   356,   436,   362,     0,   135,   143,
     148,     0,   419,   422,     0,   410,   412,   421,   404,   443,
     436,   393,   398,   406,   407,   405,   400,   402,   119,   278,
     282,   285,   288,     0,   318,   327,     0,   274,   255,     0,
     444,   446,     0,   342,     0,   339,     0,   556,   557,     0,
     515,   558,   571,     0,     0,   582,   536,   537,   533,     0,
     534,   535,     0,     0,    38,    52,   353,   354,   436,   360,
     242,   411,   420,     0,   417,   425,   423,   424,   380,   386,
     388,   391,   396,   122,     0,   183,   183,   276,     0,     0,
     257,   325,   306,   304,   337,     0,   570,   569,     0,   572,
     334,    59,    64,    60,     0,   351,   233,   413,   415,   372,
     384,     0,   394,     0,   399,   161,   279,     0,     0,   319,
       0,   322,   555,     0,   590,    61,    62,     0,     0,     0,
       0,   418,   377,   381,   436,   387,   392,   397,    79,     0,
       0,     0,     0,   323,   326,   573,    67,    66,    65,   243,
       0,   416,   375,   378,   379,   385,   280,   283,     0,   287,
       0,   414,   436,   119,   324,   376,   286
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -844,  -844,  -844,  -844,  -844,  -844,   469,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,     4,  -844,   156,  -844,
    -230,  -844,  -844,    19,  -844,  -844,     6,  -844,   160,  -844,
    -229,  -844,  -844,    21,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,   202,
    -844,  -844,  -844,  -844,   131,  -844,  -844,  -844,    10,  -844,
     335,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -164,   -97,  -844,  -182,  -844,  -844,
    -844,  -844,  -844,  -844,   148,  -844,  -844,   145,  -844,  -844,
    -115,  -844,  -844,  -844,  -844,  -844,  -844,     5,     9,  -328,
    -844,  -844,   503,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
      -6,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,   543,  -844,  -844,  -844,   -10,
    -844,    -2,   575,   -76,   554,   514,  -844,  -308,  -146,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -407,  -844,
    -844,  -844,  -844,  -612,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -137,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -377,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -591,  -108,   271,  -844,  -329,  -759,  -195,  -232,  -844,  -844,
    -844,  -844,  -844,  -844,  -231,  -844,  -844,  -844,  -844,  -202,
    -843,  -844,  -844,  -201,  -844,  -844,  -844,  -844,  -844,  -314,
    -844,  -330,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -331,  -109,  -844,  -844,  -844,  -844,  -305,  -844,
    -844,  -844,  -106,  -844,  -304,  -844,  -844,  -844,  -844,  -844,
    -844,  -844,  -844,  -786,  -844,  -100,  -844,  -844,  -844,  -844,
    -299,  -844,  -332,  -844,  -844,  -844,  -844,  -277,  -614,   -73,
     -12,    36,  -844,   740,  -844,  -844,  -844,    17,  -844,  -844,
      11,  -844,  -844,  -844,  -203,  -844,  -844,    -5,  -844,  -844,
    -844,  -324,  -844,  -326,   -54,  -309,  -127,  -844,  -844,  -782,
    -844,  -844,  -844,  -844,  -844,  -844,  -844,  -844,  -107,  -844,
    -844,  -844,  -844,  -844,  -844,   -69,  -844,  -844,  -844,   120,
    -844,   130,   132,   231,  -281,   -17,  -844,  -844
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,    26,     5,     6,     7,    48,    91,
     143,   315,   144,   145,   446,   447,   603,   448,   449,   588,
     589,   729,   839,   590,   838,   450,   605,   451,   452,   598,
     599,   733,   842,   600,   841,   453,   584,   721,   836,   966,
     942,   903,   943,     8,    92,   141,   440,    27,    28,    55,
     488,   489,   770,   868,    83,   130,   131,   509,   510,   285,
     286,   287,   288,    29,    56,    30,    64,    65,   203,    31,
     106,   196,   197,   198,   199,   111,   112,   206,   207,   336,
     485,   621,   208,   473,   474,   337,   478,   479,   486,   741,
     742,   743,   744,   745,   622,   750,   752,   623,   624,    79,
      80,    81,     9,   134,   135,    32,    84,    33,    34,    35,
      50,   147,   148,    36,    37,    38,    39,    40,    41,    42,
      75,    43,    76,    44,    77,    45,    46,    47,   139,    87,
     138,   310,   311,    88,   136,    89,   137,   312,   437,   115,
     116,    98,    99,    57,   120,   102,   103,   175,   611,   459,
     318,   460,   461,   847,   946,   176,   320,   321,   211,   490,
     212,   338,   491,   492,   780,   628,   493,   630,   631,   781,
     782,   783,   873,   784,   869,   924,   979,   785,   870,   925,
     786,   871,   926,   787,   788,   123,   124,   125,   343,   635,
     803,   126,   127,   344,   221,   882,   639,   805,   503,   591,
     789,   874,   928,   790,   791,   879,   984,  1000,   961,   792,
     480,   481,   433,   835,   549,   892,   816,   377,   668,   177,
     324,   322,   463,   464,   456,   906,   907,   844,   734,   457,
     607,   846,   735,   608,   494,   634,   633,   798,   799,   758,
     860,   759,   993,  1002,   994,   973,   949,   760,   761,   918,
     975,   950,   919,   762,   763,   861,   952,   921,   764,   862,
     954,   922,   765,   866,   766,   867,   767,   855,   991,   971,
     912,   948,   913,   856,   916,   466,   179,   317,   180,   181,
     182,   467,   794,   497,   625,   498,   795,   609,   920,   469,
     458,   350,   185,   351,   352,   644,   511,   353,   646,   512,
     354,   355,   521,   522,   356,   357,   657,   663,   812,   658,
     523,   358,   524,   359,   360,   361,   362,   374,   292,   893,
     293,   294,   295,   382,   536,   296,   527,   664,   363,   687,
     298,   826,   827,   364,   526,   365,   327,   328,   329,   366,
     188,   189,   190,   367,   192,   368,    69,   194
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int SPARQLfedParser::yytable_ninf_ = -437;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        68,   122,    71,   178,   291,    66,   496,    51,    52,    53,
     202,   462,   204,   394,    72,    73,    74,   793,   796,   331,
     332,   333,    58,   289,   297,   636,   482,   746,   637,   201,
     183,   330,   582,    93,   186,   303,   195,   731,  -297,   495,
     436,   113,   219,   915,   372,   209,   468,    68,   375,   899,
     100,   308,   108,    67,   431,   325,   501,   885,   728,   727,
     306,   307,   299,   117,   118,   945,   914,   550,   601,   883,
      59,    60,    61,   104,   863,   104,   884,   149,   104,   719,
     661,     1,   720,   771,   772,   773,   193,   200,   754,  -119,
     105,   465,   110,   470,   852,   110,   -21,    10,   755,   214,
      67,   579,   580,   754,   853,   837,    11,   853,   774,    49,
     940,    54,   756,   755,   302,  -254,   864,   884,    78,   728,
      82,   434,   775,   776,   662,   777,    90,   756,    94,   673,
      85,    86,   754,   168,   169,   170,   171,   967,   309,   184,
     133,   114,   755,   885,   316,   455,   441,    86,   732,   757,
     746,   454,    94,   326,   963,   854,   756,   865,   854,  1005,
     291,   218,   119,   -21,   757,   128,   129,   290,   146,   482,
      95,   210,    59,    60,    61,   638,    62,    63,   200,   289,
     297,   881,    59,    60,    61,  -297,   875,    62,    63,   220,
     614,   373,    59,    60,    61,   376,    59,    60,    61,    62,
      63,   432,   778,   339,  1001,   340,   341,   477,   483,   150,
     -21,   205,   -21,   442,   -21,  -119,   655,   656,   299,   178,
      70,   601,   142,   187,   213,   779,   475,    59,    60,    61,
     968,   969,   435,    59,    60,    61,    59,    60,    61,   -21,
     -21,   -21,    59,    60,    61,   215,   183,    62,    63,   216,
     186,   300,    96,    97,   186,   619,   620,   815,   804,   107,
     443,   313,   444,   314,   445,   499,   930,   109,   319,   186,
     302,    59,    60,    61,    59,    60,    61,   840,   732,    62,
      63,    59,    60,    61,   323,   132,    62,    63,   654,    59,
      60,    61,   438,   505,   506,   507,   334,   496,   200,   335,
      68,   342,   193,   736,   345,    68,   193,    68,   471,   482,
     647,   648,   649,   650,   651,   652,   369,   302,   302,   800,
     801,   193,   398,   290,   162,   163,   164,   165,   166,   167,
     495,   809,   810,   495,   191,   813,   814,   513,   514,   515,
     516,   517,   518,   370,   371,   378,   477,   519,   520,   379,
     380,   483,   381,    67,   383,   184,   384,  -169,    67,   184,
      67,   385,   301,   386,   387,   475,    12,   388,    13,    14,
     476,    15,   877,   593,   184,   389,   593,   390,   391,   392,
     502,   393,   395,   396,   397,   399,   400,   401,   186,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   186,   411,
     412,   413,   414,   415,   416,   417,   418,   300,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   430,   581,
     439,   808,  -240,   541,   484,   596,   500,   548,   596,   583,
     508,   442,   482,   445,   850,   606,   610,   612,   618,   187,
     193,   627,   629,   187,   640,   632,   645,   642,   643,   665,
     193,   653,   666,   667,   723,   669,   302,   670,   187,   674,
     675,   302,    19,   671,   672,   601,   927,   677,   482,   676,
     678,   679,   931,    20,    21,   680,   681,   682,   592,   683,
     689,   592,   690,   725,   693,    22,   694,    23,    24,    25,
     684,   483,   691,   184,   692,   695,   495,   696,   697,   698,
     699,   700,   701,   184,   702,   933,   704,   703,   705,   476,
     706,   178,   707,   708,   709,   710,   711,   712,   301,   593,
     714,   959,   715,   716,   620,   713,   944,   619,   824,   593,
     834,   848,   825,   748,   843,   887,   845,   346,   183,   888,
     876,   886,   186,   859,   641,   749,   496,   890,   891,   889,
     191,   884,   895,   896,   191,   897,   499,   898,   900,   797,
     186,   495,   594,   186,   901,   594,   593,   910,   894,   191,
     911,   596,   996,   997,   110,   937,   938,   187,   939,   495,
     947,   596,   953,   951,   962,   972,   960,   187,   965,   974,
     986,   987,   988,  1004,   193,    68,   983,   985,   989,   998,
     737,   302,   304,   999,   602,   990,   726,   722,   769,   904,
     730,   604,   193,   905,   483,   193,   769,   769,   596,   724,
     626,   616,   429,   617,   592,   738,   849,   978,   101,   753,
     121,   140,   751,   217,   592,   878,   305,   872,   970,   525,
     902,   908,   992,   995,   909,   851,   976,   184,    67,   977,
     483,   858,   811,   659,   747,   660,   807,   964,     0,     0,
     806,   768,     0,     0,     0,   184,     0,     0,   184,   768,
     768,   592,     0,   595,     0,   495,   595,     0,     0,     0,
    -169,     0,     0,     0,     0,     0,     0,     0,   191,    12,
       0,    13,    14,     0,    15,     0,     0,   -72,   191,     0,
       0,    16,    17,     0,     0,     0,     0,     0,   594,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   594,    18,
       0,     0,   797,     0,   302,     0,   186,     0,     0,     0,
       0,   187,     0,     0,     0,     0,     0,   769,     0,   857,
     769,   955,     0,     0,     0,     0,     0,     0,     0,   187,
       0,     0,   187,     0,     0,   594,     0,     0,     0,     0,
     302,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     593,   923,     0,   593,     0,     0,   186,   747,   193,     0,
       0,     0,     0,     0,     0,    19,     0,   797,     0,     0,
       0,   186,     0,     0,     0,     0,    20,    21,     0,     0,
       0,     0,     0,     0,     0,   499,     0,     0,    22,   186,
      23,    24,    25,   593,     0,     0,     0,     0,     0,   595,
       0,     0,   596,     0,     0,   596,    68,     0,   193,   595,
       0,   184,     0,     0,   593,   857,     0,   917,     0,   186,
       0,     0,   191,   193,     0,     0,   178,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     191,   193,     0,   191,     0,   596,   595,     0,     0,     0,
       0,     0,     0,   183,     0,   592,     0,   186,   592,    67,
       0,   184,     0,     0,     0,     0,   596,     0,     0,     0,
       0,   193,     0,     0,     0,     0,   184,     0,   593,   593,
     593,   797,     0,     0,     0,   186,  1006,    68,     0,     0,
       0,     0,   956,     0,   184,   187,   802,     0,   592,   957,
     958,   585,  1003,     0,     0,     0,     0,     0,     0,   193,
       0,     0,     0,   186,   769,     0,   769,     0,     0,   592,
      68,    68,     0,     0,   184,   980,   981,     0,     0,     0,
     596,   596,   596,     0,     0,   769,     0,   193,     0,   594,
      67,     0,   594,     0,     0,   187,     0,     0,     0,     0,
       0,     0,     0,   857,     0,     0,     0,     0,     0,     0,
     187,     0,   184,     0,     0,   193,     0,     0,     0,     0,
       0,     0,     0,    67,    67,     0,   982,     0,   187,     0,
       0,     0,   594,   592,   592,   592,     0,     0,   768,     0,
     184,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   594,     0,     0,   191,     0,   187,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   184,     0,
       0,     0,   587,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    59,    60,
      61,     0,     0,    62,    63,     0,   187,     0,     0,     0,
     595,     0,     0,   595,     0,     0,   191,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   504,   594,   594,   594,
       0,   191,     0,     0,   187,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   191,
     528,   529,   530,   595,     0,   531,     0,     0,   532,   533,
     534,   535,   187,   537,   538,   539,   540,     0,   542,   543,
     544,   545,   546,   547,   595,     0,     0,   551,   585,   191,
     552,   553,   554,   555,     0,   556,     0,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   932,
     585,     0,     0,   -76,     0,     0,     0,   191,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   151,   152,
     153,   154,   155,     0,     0,     0,     0,  -436,   595,   595,
     595,     0,     0,     0,     0,   191,     0,     0,   487,     0,
       0,     0,   615,     0,   151,   152,   153,   154,   155,     0,
       0,     0,     0,  -436,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   191,   156,     0,     0,     0,   151,   152,
     153,   154,   155,     0,     0,     0,     0,     0,   613,     0,
     597,     0,     0,     0,     0,     0,     0,     0,   156,   587,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    59,    60,    61,     0,     0,
      62,    63,     0,     0,     0,     0,     0,     0,     0,   686,
     688,   587,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,    59,    60,    61,
       0,     0,    62,    63,     0,     0,     0,     0,     0,   717,
     718,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    59,    60,    61,   172,
     173,    62,    63,     0,   174,     0,     0,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    59,    60,    61,   172,   173,    62,    63,     0,
     174,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    59,    60,    61,   172,
     173,    62,    63,     0,   174,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   685,     0,     0,   817,
     818,   819,   820,     0,     0,     0,   821,     0,     0,   822,
       0,     0,     0,     0,   823,     0,     0,   346,     0,     0,
       0,   828,   829,     0,     0,     0,     0,     0,     0,   830,
       0,     0,     0,   831,     0,     0,     0,   832,   347,   348,
       0,   349,   224,   833,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   585,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,     0,   245,     0,     0,     0,
     246,   247,   248,   249,   250,   251,   252,   253,     0,     0,
       0,     0,     0,     0,     0,   254,   255,   256,     0,   257,
     258,   259,     0,     0,   260,   261,   262,   263,   264,   265,
     266,     0,   267,   268,     0,   269,     0,     0,     0,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    59,    60,    61,     0,
       0,    62,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   222,     0,   587,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      59,    60,    61,   223,     0,    62,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   929,     0,     0,     0,
       0,     0,     0,     0,   934,     0,   935,     0,   224,   936,
     225,   226,   227,   228,   229,   230,   231,   232,   233,     0,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,     0,   245,     0,     0,     0,   246,   247,   248,   249,
     250,   251,   252,   253,     0,     0,     0,     0,     0,     0,
       0,   254,   255,   256,     0,   257,   258,   259,     0,     0,
     260,   261,   262,   263,   264,   265,   266,     0,   267,   268,
       0,   269,     0,     0,     0,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     739,   740,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   346,     0,     0,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    59,    60,    61,     0,     0,    62,    63,   224,
       0,   225,   226,   227,   228,   229,   230,   231,   232,   233,
       0,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,     0,   245,     0,     0,     0,     0,     0,   151,
     152,   153,   154,   155,   253,     0,     0,     0,  -436,     0,
       0,     0,   254,   255,   256,     0,   257,   258,   259,   487,
       0,   260,   261,   262,   263,   264,   265,   266,     0,   267,
     268,     0,   269,     0,   941,   585,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   151,   152,   153,   154,   155,     0,     0,     0,     0,
       0,   880,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   487,     0,     0,     0,   151,   152,   153,   154,   155,
       0,     0,     0,    59,    60,    61,     0,     0,    62,    63,
       0,     0,     0,     0,     0,   156,     0,     0,     0,   151,
     152,   153,   154,   155,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   487,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,    59,    60,    61,
     172,   173,    62,    63,     0,   174,   587,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    59,    60,    61,     0,     0,    62,    63,     0,
       0,     0,     0,     0,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,    59,
      60,    61,   172,   173,    62,    63,     0,   174,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,    59,    60,    61,   172,   173,    62,    63,
       0,   174,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,    59,    60,    61,
     172,   173,    62,    63,   346,   174,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   347,   348,     0,   349,   224,
       0,   225,   226,   227,   228,   229,   230,   231,   232,   233,
       0,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,     0,   245,     0,     0,     0,   246,   247,   248,
     249,   250,   251,   252,   253,     0,     0,     0,     0,     0,
       0,     0,   254,   255,   256,     0,   257,   258,   259,     0,
       0,   260,   261,   262,   263,   264,   265,   266,     0,   267,
     268,     0,   269,     0,     0,     0,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   223,     0,     0,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,    59,    60,    61,     0,     0,    62,    63,
     224,     0,   225,   226,   227,   228,   229,   230,   231,   232,
     233,     0,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,     0,   245,     0,     0,     0,   246,   247,
     248,   249,   250,   251,   252,   253,     0,     0,     0,     0,
       0,     0,     0,   254,   255,   256,     0,   257,   258,   259,
       0,     0,   260,   261,   262,   263,   264,   265,   266,     0,
     267,   268,     0,   269,     0,     0,     0,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,     0,     0,     0,     0,     0,     0,     0,     0,
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
     282,   283,   284,     0,   585,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   472,     0,     0,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    59,    60,    61,     0,     0,
      62,    63,   224,     0,   225,   226,   227,   228,   229,   230,
     231,   232,   233,     0,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   586,   245,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   253,     0,     0,
       0,     0,     0,     0,     0,   254,   255,   256,     0,   257,
     258,   259,     0,     0,   260,   261,   262,   263,   264,   265,
     266,     0,   267,   268,     0,   269,     0,     0,     0,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,     0,   587,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,    59,    60,    61,   346,     0,    62,    63,     0,     0,
       0,     0,     0,     0,     0,     0,    59,    60,    61,     0,
       0,    62,    63,     0,     0,     0,     0,     0,     0,   224,
       0,   225,   226,   227,   228,   229,   230,   231,   232,   233,
       0,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,     0,   245,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   253,     0,     0,     0,     0,     0,
       0,     0,   254,   255,   256,     0,   257,   258,   259,     0,
       0,   260,   261,   262,   263,   264,   265,   266,     0,   267,
     268,     0,   269,     0,     0,     0,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    59,    60,    61
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        17,    77,    19,   103,   131,    17,   338,    13,    14,    15,
     107,   319,   109,   245,    20,    21,    22,   629,   632,   201,
     202,   203,    20,   131,   131,    38,   335,   618,    41,   105,
     103,   195,   439,    50,   103,   132,    24,    44,    41,   338,
      24,     6,    41,    51,    41,    37,   323,    64,    41,   831,
      52,    21,    64,    17,    41,    89,    42,   816,   104,    44,
     136,   137,   131,    73,    74,   908,   852,   396,   445,    42,
     180,   181,   182,    23,    20,    23,    49,    94,    23,    38,
      20,    15,    41,     6,     7,     8,   103,   104,    41,    37,
      40,   322,    40,   324,    41,    40,    37,   180,    51,   116,
      64,   430,   431,    41,    51,   151,     0,    51,    31,    13,
      42,    37,    65,    51,   131,    38,    62,    49,    31,   104,
      17,   303,    45,    46,    64,    48,    16,    65,     6,   536,
       3,     4,    41,   176,   177,   178,   179,    56,   108,   103,
      50,   106,    51,   902,   146,    51,    37,     4,   155,   102,
     741,   315,     6,   187,   936,   102,    65,   103,   102,  1002,
     287,   125,    37,   104,   102,    18,    19,   131,    10,   478,
      24,   163,   180,   181,   182,   188,   185,   186,   195,   287,
     287,   795,   180,   181,   182,   188,   777,   185,   186,   188,
     467,   188,   180,   181,   182,   188,   180,   181,   182,   185,
     186,   188,   125,   213,   990,   215,   216,   334,   335,    38,
     151,    92,   153,   104,   155,   163,    62,    63,   287,   319,
      18,   598,   163,   103,   112,   148,   334,   180,   181,   182,
     149,   150,   308,   180,   181,   182,   180,   181,   182,   180,
     181,   182,   180,   181,   182,   112,   319,   185,   186,   112,
     319,   131,   106,   107,   323,    29,    30,   664,   635,    57,
     151,   181,   153,    56,   155,   338,   878,    65,    44,   338,
     287,   180,   181,   182,   180,   181,   182,   154,   155,   185,
     186,   180,   181,   182,    41,    83,   185,   186,   520,   180,
     181,   182,   309,   347,   348,   349,    26,   629,   315,    93,
     317,    38,   319,   611,    37,   322,   323,   324,   325,   618,
     513,   514,   515,   516,   517,   518,    76,   334,   335,   633,
     634,   338,   188,   287,   170,   171,   172,   173,   174,   175,
     629,   655,   656,   632,   103,   661,   662,    56,    57,    58,
      59,    60,    61,    41,    41,    41,   473,    66,    67,    41,
      41,   478,    41,   317,    41,   319,    41,     0,   322,   323,
     324,    41,   131,    41,    41,   473,     9,    41,    11,    12,
     334,    14,   779,   442,   338,    41,   445,    41,    41,    41,
     344,    41,    41,    41,    41,   188,    41,    41,   457,    41,
      41,   188,    41,   188,    41,    41,    41,    41,   467,    41,
      41,    41,    41,    41,    41,    41,    41,   287,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,   436,
      40,   653,     6,   387,    25,   442,    37,    18,   445,   180,
      91,   104,   741,   155,   743,    53,    44,     6,    26,   319,
     457,    38,    44,   323,    42,    41,    55,    42,    54,    42,
     467,    67,    42,    42,   104,    49,   473,    49,   338,    42,
      42,   478,   105,    49,    49,   842,   873,    42,   777,    49,
      42,    49,   879,   116,   117,    42,    42,    42,   442,    42,
      42,   445,    42,   155,    42,   128,    42,   130,   131,   132,
      49,   618,    49,   457,    49,    42,   795,    42,    42,    42,
      49,    42,    42,   467,    42,   882,    42,    49,    42,   473,
      42,   611,    49,    42,    42,    42,    42,    42,   287,   588,
      42,   928,    42,    42,    30,    49,   903,    29,    42,   598,
      42,    42,    50,   167,    50,    42,    49,    41,   611,    42,
      41,    49,   611,    53,   508,   167,   878,    42,    42,    49,
     319,    49,    42,    42,   323,    42,   629,    42,    42,   632,
     629,   860,   442,   632,    42,   445,   635,    37,    77,   338,
      42,   588,   979,   980,    40,    42,    56,   457,    42,   878,
      42,   598,    64,   104,    42,    50,    91,   467,    49,    49,
     967,   968,   969,  1000,   611,   612,    47,    42,    38,    23,
     612,   618,   133,    42,   448,   104,   602,   588,   625,   839,
     604,   451,   629,   842,   741,   632,   633,   634,   635,   598,
     489,   473,   287,   478,   588,   615,   741,   955,    53,   624,
      76,    88,   623,   119,   598,   781,   133,   774,   946,   368,
     835,   843,   972,   974,   845,   754,   951,   611,   612,   953,
     777,   757,   657,   523,   618,   523,   645,   938,    -1,    -1,
     643,   625,    -1,    -1,    -1,   629,    -1,    -1,   632,   633,
     634,   635,    -1,   442,    -1,   974,   445,    -1,    -1,    -1,
       0,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   457,     9,
      -1,    11,    12,    -1,    14,    -1,    -1,    17,   467,    -1,
      -1,    21,    22,    -1,    -1,    -1,    -1,    -1,   588,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   598,    39,
      -1,    -1,   795,    -1,   741,    -1,   795,    -1,    -1,    -1,
      -1,   611,    -1,    -1,    -1,    -1,    -1,   754,    -1,   756,
     757,   923,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   629,
      -1,    -1,   632,    -1,    -1,   635,    -1,    -1,    -1,    -1,
     777,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     839,   868,    -1,   842,    -1,    -1,   845,   741,   795,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,   860,    -1,    -1,
      -1,   860,    -1,    -1,    -1,    -1,   116,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   878,    -1,    -1,   128,   878,
     130,   131,   132,   882,    -1,    -1,    -1,    -1,    -1,   588,
      -1,    -1,   839,    -1,    -1,   842,   843,    -1,   845,   598,
      -1,   795,    -1,    -1,   903,   852,    -1,   854,    -1,   908,
      -1,    -1,   611,   860,    -1,    -1,   946,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     629,   878,    -1,   632,    -1,   882,   635,    -1,    -1,    -1,
      -1,    -1,    -1,   946,    -1,   839,    -1,   946,   842,   843,
      -1,   845,    -1,    -1,    -1,    -1,   903,    -1,    -1,    -1,
      -1,   908,    -1,    -1,    -1,    -1,   860,    -1,   967,   968,
     969,   974,    -1,    -1,    -1,   974,  1003,   924,    -1,    -1,
      -1,    -1,   924,    -1,   878,   795,    38,    -1,   882,   925,
     926,    43,   998,    -1,    -1,    -1,    -1,    -1,    -1,   946,
      -1,    -1,    -1,  1002,   951,    -1,   953,    -1,    -1,   903,
     957,   958,    -1,    -1,   908,   957,   958,    -1,    -1,    -1,
     967,   968,   969,    -1,    -1,   972,    -1,   974,    -1,   839,
     924,    -1,   842,    -1,    -1,   845,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   990,    -1,    -1,    -1,    -1,    -1,    -1,
     860,    -1,   946,    -1,    -1,  1002,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   957,   958,    -1,   960,    -1,   878,    -1,
      -1,    -1,   882,   967,   968,   969,    -1,    -1,   972,    -1,
     974,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   903,    -1,    -1,   795,    -1,   908,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1002,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    -1,    -1,   185,   186,    -1,   946,    -1,    -1,    -1,
     839,    -1,    -1,   842,    -1,    -1,   845,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   346,   967,   968,   969,
      -1,   860,    -1,    -1,   974,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   878,
     370,   371,   372,   882,    -1,   375,    -1,    -1,   378,   379,
     380,   381,  1002,   383,   384,   385,   386,    -1,   388,   389,
     390,   391,   392,   393,   903,    -1,    -1,   397,    43,   908,
     400,   401,   402,   403,    -1,   405,    -1,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,    42,
      43,    -1,    -1,    17,    -1,    -1,    -1,   946,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    41,   967,   968,
     969,    -1,    -1,    -1,    -1,   974,    -1,    -1,    52,    -1,
      -1,    -1,   472,    -1,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1002,    52,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    42,    -1,
     155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,    -1,    -1,
     185,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   549,
     550,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
      -1,    -1,   185,   186,    -1,    -1,    -1,    -1,    -1,   579,
     580,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    -1,   188,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
     188,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,    -1,   188,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,   669,
     670,   671,   672,    -1,    -1,    -1,   676,    -1,    -1,   679,
      -1,    -1,    -1,    -1,   684,    -1,    -1,    41,    -1,    -1,
      -1,   691,   692,    -1,    -1,    -1,    -1,    -1,    -1,   699,
      -1,    -1,    -1,   703,    -1,    -1,    -1,   707,    62,    63,
      -1,    65,    66,   713,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    43,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,   113,
     114,   115,    -1,    -1,   118,   119,   120,   121,   122,   123,
     124,    -1,   126,   127,    -1,   129,    -1,    -1,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,    -1,
      -1,   185,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,    41,    -1,   185,   186,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   876,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   884,    -1,   886,    -1,    66,   889,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    -1,    90,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   109,   110,   111,    -1,   113,   114,   115,    -1,    -1,
     118,   119,   120,   121,   122,   123,   124,    -1,   126,   127,
      -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    -1,    -1,   185,   186,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    90,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,   101,    -1,    -1,    -1,    41,    -1,
      -1,    -1,   109,   110,   111,    -1,   113,   114,   115,    52,
      -1,   118,   119,   120,   121,   122,   123,   124,    -1,   126,
     127,    -1,   129,    -1,    42,    43,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,   185,   186,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,    -1,   188,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    -1,    -1,   185,   186,    -1,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,    -1,   188,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
      -1,   188,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,    41,   188,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    90,    -1,    -1,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,   110,   111,    -1,   113,   114,   115,    -1,
      -1,   118,   119,   120,   121,   122,   123,   124,    -1,   126,
     127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,    -1,    -1,   185,   186,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    -1,    90,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,   110,   111,    -1,   113,   114,   115,
      -1,    -1,   118,   119,   120,   121,   122,   123,   124,    -1,
     126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    -1,    -1,   185,
     186,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,   110,   111,    -1,   113,   114,
     115,    -1,    -1,   118,   119,   120,   121,   122,   123,   124,
      -1,   126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,    -1,    -1,
     185,   186,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,   104,    90,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,   113,
     114,   115,    -1,    -1,   118,   119,   120,   121,   122,   123,
     124,    -1,   126,   127,    -1,   129,    -1,    -1,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,    41,    -1,   185,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,   185,   186,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,   110,   111,    -1,   113,   114,   115,    -1,
      -1,   118,   119,   120,   121,   122,   123,   124,    -1,   126,
     127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    15,   190,   191,   192,   194,   195,   196,   232,   291,
     180,     0,     9,    11,    12,    14,    21,    22,    39,   105,
     116,   117,   128,   130,   131,   132,   193,   236,   237,   252,
     254,   258,   294,   296,   297,   298,   302,   303,   304,   305,
     306,   307,   308,   310,   312,   314,   315,   316,   197,    13,
     299,   299,   299,   299,    37,   238,   253,   332,    20,   180,
     181,   182,   185,   186,   255,   256,   479,   480,   534,   535,
     238,   534,   299,   299,   299,   309,   311,   313,    31,   288,
     289,   290,    17,   243,   295,     3,     4,   318,   322,   324,
      16,   198,   233,   534,     6,    24,   106,   107,   330,   331,
     330,   331,   334,   335,    23,    40,   259,   238,   479,   238,
      40,   264,   265,     6,   106,   328,   329,   328,   328,    37,
     333,   333,   332,   374,   375,   376,   380,   381,    18,    19,
     244,   245,   238,    50,   292,   293,   323,   325,   319,   317,
     324,   234,   163,   199,   201,   202,    10,   300,   301,   534,
      38,    32,    33,    34,    35,    36,    52,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   183,   184,   188,   336,   344,   408,   464,   465,
     467,   468,   469,   478,   480,   481,   524,   528,   529,   530,
     531,   532,   533,   534,   536,    24,   260,   261,   262,   263,
     534,   332,   264,   257,   264,    92,   266,   267,   271,    37,
     163,   347,   349,   112,   534,   112,   112,   334,   480,    41,
     188,   383,    20,    41,    66,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    90,    94,    95,    96,    97,
      98,    99,   100,   101,   109,   110,   111,   113,   114,   115,
     118,   119,   120,   121,   122,   123,   124,   126,   127,   129,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   248,   249,   250,   251,   400,
     480,   505,   507,   509,   510,   511,   514,   517,   519,   524,
     528,   532,   534,   264,   195,   291,   332,   332,    21,   108,
     320,   321,   326,   181,    56,   200,   330,   466,   339,    44,
     345,   346,   410,    41,   409,    89,   187,   525,   526,   527,
     263,   266,   266,   266,    26,    93,   268,   274,   350,   328,
     328,   328,    38,   377,   382,    37,    41,    62,    63,    65,
     480,   482,   483,   486,   489,   490,   493,   494,   500,   502,
     503,   504,   505,   517,   522,   524,   528,   532,   534,    76,
      41,    41,    41,   188,   506,    41,   188,   406,    41,    41,
      41,    41,   512,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,   406,    41,    41,    41,   188,   188,
      41,    41,    41,    41,   188,    41,   188,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,   249,
      41,    41,   188,   401,   266,   332,    24,   327,   534,    40,
     235,    37,   104,   151,   153,   155,   203,   204,   206,   207,
     214,   216,   217,   224,   263,    51,   413,   418,   479,   338,
     340,   341,   336,   411,   412,   413,   464,   470,   476,   478,
     413,   534,    41,   272,   273,   400,   480,   505,   275,   276,
     399,   400,   504,   505,    25,   269,   277,    52,   239,   240,
     348,   351,   352,   355,   423,   469,   471,   472,   474,   478,
      37,    42,   480,   387,   482,   503,   503,   503,    91,   246,
     247,   485,   488,    56,    57,    58,    59,    60,    61,    66,
      67,   491,   492,   499,   501,   401,   523,   515,   482,   482,
     482,   482,   482,   482,   482,   482,   513,   482,   482,   482,
     482,   480,   482,   482,   482,   482,   482,   482,    18,   403,
     403,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   403,
     403,   534,   347,   180,   225,    43,   104,   164,   208,   209,
     212,   388,   480,   524,   528,   532,   534,   155,   218,   219,
     222,   388,   207,   205,   217,   215,    53,   419,   422,   476,
      44,   337,     6,    42,   476,   482,   273,   276,    26,    29,
      30,   270,   283,   286,   287,   473,   243,    38,   354,    44,
     356,   357,    41,   425,   424,   378,    38,    41,   188,   385,
      42,   480,    42,    54,   484,    55,   487,   493,   493,   493,
     493,   493,   493,    67,   406,    62,    63,   495,   498,   530,
     531,    20,    64,   496,   516,    42,    42,    42,   407,    49,
      49,    49,    49,   347,    42,    42,    49,    42,    42,    49,
      42,    42,    42,    42,    49,    20,   482,   518,   482,    42,
      42,    49,    49,    42,    42,    42,    42,    42,    42,    49,
      42,    42,    42,    49,    42,    42,    42,    49,    42,    42,
      42,    42,    42,    49,    42,    42,    42,   482,   482,    38,
      41,   226,   212,   104,   222,   155,   205,    44,   104,   210,
     215,    44,   155,   220,   417,   421,   336,   479,   247,    27,
      28,   278,   279,   280,   281,   282,   399,   480,   167,   167,
     284,   287,   285,   286,    41,    51,    65,   102,   428,   430,
     436,   437,   442,   443,   447,   451,   453,   455,   480,   534,
     241,     6,     7,     8,    31,    45,    46,    48,   125,   148,
     353,   358,   359,   360,   362,   366,   369,   372,   373,   389,
     392,   393,   398,   352,   471,   475,   477,   478,   426,   427,
     428,   428,    38,   379,   388,   386,   486,   489,   406,   500,
     500,   496,   497,   502,   502,   347,   405,   482,   482,   482,
     482,   482,   482,   482,    42,    50,   520,   521,   482,   482,
     482,   482,   482,   482,    42,   402,   227,   151,   213,   211,
     154,   223,   221,    50,   416,    49,   420,   342,    42,   279,
     504,   442,    41,    51,   102,   456,   462,   534,   451,    53,
     429,   444,   448,    20,    62,   103,   452,   454,   242,   363,
     367,   370,   374,   361,   390,   399,    41,   347,   337,   394,
      42,   477,   384,    42,    49,   404,    49,    42,    42,    49,
      42,    42,   404,   508,    77,    42,    42,    42,    42,   508,
      42,    42,   405,   230,   209,   219,   414,   415,   418,   422,
      37,    42,   459,   461,   462,    51,   463,   534,   438,   441,
     477,   446,   450,   264,   364,   368,   371,   347,   391,   482,
     352,   347,    42,   388,   482,   482,   482,    42,    56,    42,
      42,    42,   229,   231,   388,   419,   343,    42,   460,   435,
     440,   104,   445,    64,   449,   266,   479,   299,   299,   347,
      91,   397,    42,   508,   533,    49,   228,    56,   149,   150,
     336,   458,    50,   434,    49,   439,   447,   453,   288,   365,
     479,   479,   480,    47,   395,    42,   388,   388,   388,    38,
     104,   457,   430,   431,   433,   441,   347,   347,    23,    42,
     396,   462,   432,   332,   347,   419,   264
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
     289,   290,   290,   291,   292,   293,   293,   295,   294,   296,
     296,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   298,   299,   299,   300,   301,   301,   302,   303,
     304,   305,   306,   307,   309,   308,   311,   310,   313,   312,
     314,   315,   316,   316,   317,   317,   318,   318,   319,   319,
     320,   321,   321,   323,   322,   325,   324,   326,   327,   327,
     328,   328,   329,   329,   330,   331,   331,   331,   331,   332,
     333,   335,   334,   336,   336,   337,   337,   338,   339,   339,
     341,   342,   343,   340,   344,   345,   346,   346,   347,   347,
     348,   348,   350,   349,   351,   352,   352,   353,   354,   354,
     355,   356,   357,   357,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   359,   361,   360,   363,   364,   365,
     362,   367,   368,   366,   370,   371,   369,   372,   373,   374,
     374,   376,   377,   375,   378,   378,   379,   381,   380,   382,
     382,   383,   383,   384,   384,   386,   385,   385,   387,   387,
     388,   388,   388,   388,   388,   388,   388,   390,   391,   389,
     393,   394,   392,   396,   395,   397,   397,   398,   399,   399,
     399,   400,   401,   402,   401,   403,   403,   404,   405,   405,
     406,   407,   406,   409,   408,   410,   408,   411,   412,   412,
     413,   414,   415,   415,   416,   417,   417,   418,   418,   419,
     420,   421,   421,   422,   424,   423,   425,   423,   426,   427,
     427,   429,   428,   430,   430,   432,   431,   433,   433,   434,
     435,   435,   436,   437,   438,   439,   440,   440,   441,   442,
     444,   443,   445,   446,   446,   448,   447,   449,   450,   450,
     451,   452,   452,   453,   453,   454,   454,   454,   455,   455,
     455,   455,   456,   456,   457,   458,   458,   460,   459,   461,
     461,   462,   462,   462,   463,   463,   464,   464,   466,   465,
     467,   468,   468,   468,   468,   468,   469,   469,   470,   470,
     471,   471,   473,   472,   474,   475,   475,   476,   476,   477,
     477,   478,   478,   479,   479,   480,   480,   481,   481,   481,
     481,   481,   481,   482,   483,   484,   485,   485,   486,   487,
     488,   488,   489,   490,   491,   491,   492,   492,   492,   492,
     492,   492,   492,   492,   493,   494,   495,   495,   496,   496,
     497,   497,   498,   498,   498,   499,   499,   500,   501,   501,
     502,   502,   502,   502,   503,   503,   503,   503,   503,   503,
     503,   503,   504,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   506,   506,   507,
     508,   508,   509,   510,   512,   513,   511,   515,   516,   514,
     517,   517,   517,   518,   518,   519,   519,   519,   519,   519,
     520,   521,   521,   522,   523,   523,   524,   525,   526,   526,
     527,   527,   528,   528,   528,   529,   529,   529,   530,   530,
     530,   531,   531,   531,   532,   532,   533,   533,   533,   533,
     534,   534,   535,   535,   536,   536
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
       2,     0,     1,     2,     2,     0,     1,     0,     3,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     0,     1,     2,     0,     1,     3,     3,
       3,     5,     5,     5,     0,     3,     0,     3,     0,     3,
       6,     2,     0,     1,     0,     1,     2,     1,     0,     2,
       2,     0,     1,     0,     3,     0,     3,     2,     1,     2,
       1,     2,     0,     1,     2,     1,     1,     1,     1,     3,
       3,     0,     3,     0,     1,     0,     1,     3,     0,     2,
       0,     0,     0,     8,     2,     2,     0,     1,     1,     1,
       1,     1,     0,     4,     2,     0,     1,     3,     0,     2,
       2,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     0,     3,     0,     0,     0,
       6,     0,     0,     6,     0,     0,     8,     6,     2,     1,
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
       0,     3,     2,     0,     2,     0,     3,     2,     0,     2,
       2,     0,     1,     1,     2,     1,     1,     1,     1,     1,
       2,     3,     1,     3,     2,     0,     2,     0,     3,     0,
       1,     1,     1,     2,     1,     1,     1,     1,     0,     4,
       4,     1,     1,     1,     1,     1,     0,     1,     1,     2,
       1,     1,     0,     4,     4,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     0,     2,     2,     2,
       0,     2,     1,     2,     0,     1,     2,     2,     2,     2,
       2,     2,     2,     3,     1,     2,     1,     1,     2,     2,
       0,     1,     2,     2,     2,     0,     2,     2,     0,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     4,     6,     4,     4,     4,     4,
       2,     2,     4,     4,     4,     4,     2,     1,     4,     1,
       4,     4,     4,     6,     6,     6,     6,     6,     4,     4,
       4,     4,     4,     4,     4,     4,     2,     2,     2,     4,
       4,     4,     4,     4,     2,     8,     6,     6,     6,     4,
       4,     4,     4,     4,     1,     1,     1,     3,     1,     7,
       0,     1,     7,     9,     0,     0,     4,     0,     0,     5,
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
       190,     0,    -1,   191,    -1,   194,    -1,   192,    -1,   195,
     193,   288,    -1,   236,    -1,   252,    -1,   254,    -1,   258,
      -1,   291,    -1,   196,   197,   198,    -1,    -1,   232,    -1,
      -1,   197,   233,    -1,    -1,   198,   199,    -1,    -1,   202,
     200,   203,    -1,   163,    56,    -1,    -1,   201,    -1,   204,
      -1,   214,    -1,   224,    -1,   263,    -1,   206,   207,   205,
     213,    -1,   207,   205,    44,    -1,    -1,   205,   210,    -1,
     151,    -1,   104,   209,    -1,   212,    -1,   208,   212,    -1,
     104,    -1,   208,    -1,    -1,   104,   211,   209,    -1,   388,
     104,    -1,   151,    -1,   216,   217,   215,   223,    -1,   217,
     215,    44,    -1,    -1,   215,   220,    -1,   153,    -1,   155,
     219,    -1,   222,    -1,   218,   222,    -1,   155,    -1,   218,
      -1,    -1,   155,   221,   219,    -1,   388,   155,    -1,   154,
      -1,    37,   225,    38,    -1,    -1,   225,   226,    -1,    -1,
      41,   227,   230,    42,    -1,    -1,    49,    -1,   231,   228,
      -1,    -1,   230,   229,    -1,   388,   150,   388,    -1,   388,
     149,   388,    -1,   388,    56,   388,    -1,    15,   180,    -1,
      -1,    -1,    16,   234,   181,   235,   180,    -1,    -1,   237,
     243,   238,   264,   266,    -1,    -1,   238,   259,    -1,    -1,
      -1,    -1,   240,   243,   241,   242,   264,   266,   288,    -1,
      17,   245,   251,    -1,    18,    -1,    19,    -1,    -1,   244,
      -1,    91,   480,    -1,    -1,   246,    -1,    41,   482,   247,
      42,    -1,   505,    -1,   524,    -1,   528,    -1,   532,    -1,
     480,    -1,   517,    -1,   400,    -1,   248,    -1,   249,    -1,
     250,   249,    -1,   250,    -1,    20,    -1,    21,   253,    -1,
     332,   238,   264,   266,    -1,   238,    40,   332,   266,    -1,
      22,   256,   238,   257,   266,    -1,   479,    -1,   255,   479,
      -1,   255,    -1,    20,    -1,    -1,   264,    -1,    39,   238,
     264,   266,    -1,    23,   260,    -1,   261,    -1,   262,    -1,
     263,    -1,    24,   263,    -1,   534,    -1,   265,   347,    -1,
      -1,    40,    -1,   267,   268,   269,   270,    -1,    -1,   271,
      -1,    -1,   274,    -1,    -1,   277,    -1,    -1,   283,    -1,
      92,    26,   272,    -1,   273,    -1,   272,   273,    -1,   505,
      -1,   400,    -1,    41,   482,   247,    42,    -1,   480,    -1,
      93,   275,    -1,   276,    -1,   275,   276,    -1,   399,    -1,
      25,    26,   278,    -1,   279,    -1,   278,   279,    -1,   281,
      -1,   282,    -1,    27,    -1,    28,    -1,   280,   504,    -1,
     399,    -1,   480,    -1,   286,   284,    -1,   287,   285,    -1,
      -1,   287,    -1,    -1,   286,    -1,    29,   167,    -1,    30,
     167,    -1,   290,    -1,    31,   374,    -1,    -1,   289,    -1,
     195,   296,    -1,    50,   291,    -1,    -1,   292,    -1,    -1,
     297,   295,   293,    -1,    -1,   294,    -1,   298,    -1,   302,
      -1,   303,    -1,   305,    -1,   306,    -1,   307,    -1,   304,
      -1,   308,    -1,   310,    -1,   312,    -1,   314,    -1,     9,
     299,   534,   301,    -1,    -1,    13,    -1,    10,   330,    -1,
      -1,   300,    -1,    11,   299,   331,    -1,    14,   299,   331,
      -1,    12,   299,   330,    -1,   116,   299,   328,   112,   328,
      -1,   128,   299,   328,   112,   328,    -1,   117,   299,   328,
     112,   328,    -1,    -1,   130,   309,   333,    -1,    -1,   131,
     311,   333,    -1,    -1,   132,   313,   332,    -1,   316,   318,
     319,   321,    40,   347,    -1,   105,   534,    -1,    -1,   315,
      -1,    -1,   324,    -1,   322,   317,    -1,   324,    -1,    -1,
     319,   326,    -1,    21,   332,    -1,    -1,   320,    -1,    -1,
       3,   323,   332,    -1,    -1,     4,   325,   332,    -1,   108,
     327,    -1,   534,    -1,    24,   534,    -1,   106,    -1,   329,
     534,    -1,    -1,     6,    -1,     6,   534,    -1,   330,    -1,
     106,    -1,    24,    -1,   107,    -1,    37,   334,    38,    -1,
      37,   334,    38,    -1,    -1,   335,   336,   339,    -1,    -1,
     344,    -1,    -1,    44,    -1,   340,   337,   336,    -1,    -1,
     339,   338,    -1,    -1,    -1,    -1,   341,     6,   479,   342,
      37,   343,   336,    38,    -1,   408,   346,    -1,    44,   336,
      -1,    -1,   345,    -1,   349,    -1,   163,    -1,   239,    -1,
     351,    -1,    -1,    37,   350,   348,    38,    -1,   352,   354,
      -1,    -1,   355,    -1,   358,   337,   352,    -1,    -1,   354,
     353,    -1,   423,   357,    -1,    44,   352,    -1,    -1,   356,
      -1,   392,    -1,   360,    -1,   389,    -1,   362,    -1,   366,
      -1,   369,    -1,   398,    -1,   372,    -1,   373,    -1,   359,
      -1,   148,   347,    -1,    -1,    45,   361,   347,    -1,    -1,
      -1,    -1,     6,   363,   364,   479,   365,   347,    -1,    -1,
      -1,     7,   367,   368,   299,   479,   347,    -1,    -1,    -1,
       8,   370,   371,   299,   479,    23,   332,   264,    -1,   125,
      41,   482,    91,   480,    42,    -1,    31,   374,    -1,   375,
      -1,   380,    -1,    -1,    -1,   376,   480,   377,    37,   378,
      38,    -1,    -1,   378,   379,    -1,   388,    -1,    -1,   381,
     383,    37,   387,    38,    -1,    -1,   382,   480,    -1,   188,
      -1,    41,   382,    42,    -1,    -1,   384,   388,    -1,    -1,
      41,   386,   384,    42,    -1,   188,    -1,    -1,   387,   385,
      -1,   534,    -1,   524,    -1,   528,    -1,   532,    -1,    43,
      -1,   164,    -1,   480,    -1,    -1,    -1,    46,   390,   391,
     347,    -1,    -1,    -1,   393,   394,   347,   397,    -1,    -1,
      47,   396,   347,    -1,    -1,   397,   395,    -1,    48,   399,
      -1,   504,    -1,   505,    -1,   400,    -1,   534,   401,    -1,
     188,    -1,    -1,    41,   403,   482,   402,   405,    42,    -1,
      -1,    18,    -1,    49,   482,    -1,    -1,   405,   404,    -1,
     188,    -1,    -1,    41,   482,   407,   405,    42,    -1,    -1,
     478,   409,   413,    -1,    -1,   464,   410,   411,    -1,   412,
      -1,    -1,   413,    -1,   418,   419,   417,    -1,   418,   419,
      -1,    -1,   414,    -1,    50,   415,    -1,    -1,   417,   416,
      -1,   479,    -1,    51,    -1,   422,   421,    -1,    49,   422,
      -1,    -1,   421,   420,    -1,   476,    -1,    -1,   478,   424,
     428,    -1,    -1,   471,   425,   426,    -1,   427,    -1,    -1,
     428,    -1,    -1,   430,   429,   438,   435,    -1,   436,    -1,
     437,    -1,    -1,   430,   432,   419,    -1,    -1,   431,    -1,
      50,   433,    -1,    -1,   435,   434,    -1,   442,    -1,   480,
      -1,   441,   440,    -1,    49,   441,    -1,    -1,   440,   439,
      -1,   477,    -1,   443,    -1,    -1,   447,   444,   446,    -1,
     104,   447,    -1,    -1,   446,   445,    -1,    -1,   453,   448,
     450,    -1,    64,   453,    -1,    -1,   450,   449,    -1,   455,
     452,    -1,    -1,   454,    -1,   451,    -1,   102,   451,    -1,
     103,    -1,    20,    -1,    62,    -1,   534,    -1,    51,    -1,
      65,   456,    -1,    41,   442,    42,    -1,   462,    -1,    41,
     461,    42,    -1,   104,   462,    -1,    -1,   458,   457,    -1,
      -1,   462,   460,   458,    -1,    -1,   459,    -1,   534,    -1,
      51,    -1,   102,   463,    -1,   534,    -1,    51,    -1,   467,
      -1,   465,    -1,    -1,    52,   466,   413,    53,    -1,   469,
      41,   470,    42,    -1,    32,    -1,    33,    -1,    34,    -1,
      35,    -1,    36,    -1,    -1,   468,    -1,   476,    -1,   470,
     476,    -1,   474,    -1,   472,    -1,    -1,    52,   473,   428,
      53,    -1,   469,    41,   475,    42,    -1,   477,    -1,   475,
     477,    -1,   478,    -1,   464,    -1,   478,    -1,   471,    -1,
     480,    -1,   481,    -1,   480,    -1,   534,    -1,   185,    -1,
     186,    -1,   534,    -1,   524,    -1,   528,    -1,   532,    -1,
     536,    -1,   188,    -1,   483,    -1,   486,   485,    -1,    54,
     486,    -1,    -1,   485,   484,    -1,   489,   488,    -1,    55,
     489,    -1,    -1,   488,   487,    -1,   490,    -1,   493,   491,
      -1,    -1,   492,    -1,    56,   493,    -1,    57,   493,    -1,
      58,   493,    -1,    59,   493,    -1,    60,   493,    -1,    61,
     493,    -1,    67,   406,    -1,    66,    67,   406,    -1,   494,
      -1,   500,   499,    -1,   530,    -1,   531,    -1,    20,   502,
      -1,    64,   502,    -1,    -1,   496,    -1,    62,   500,    -1,
      63,   500,    -1,   495,   497,    -1,    -1,   499,   498,    -1,
     502,   501,    -1,    -1,   501,   496,    -1,    65,   503,    -1,
      62,   503,    -1,    63,   503,    -1,   503,    -1,   504,    -1,
     505,    -1,   522,    -1,   524,    -1,   528,    -1,   532,    -1,
     480,    -1,   517,    -1,    41,   482,    42,    -1,    78,    41,
     482,    42,    -1,    79,    41,   482,    42,    -1,    80,    41,
     482,    49,   482,    42,    -1,    81,    41,   482,    42,    -1,
      82,    41,   480,    42,    -1,    68,    41,   482,    42,    -1,
      69,    41,   482,    42,    -1,    70,   506,    -1,   118,   188,
      -1,   142,    41,   482,    42,    -1,   139,    41,   482,    42,
      -1,   129,    41,   482,    42,    -1,   123,    41,   482,    42,
      -1,    90,   406,    -1,   509,    -1,   145,    41,   482,    42,
      -1,   510,    -1,   143,    41,   482,    42,    -1,   141,    41,
     482,    42,    -1,   137,    41,   482,    42,    -1,   126,    41,
     482,    49,   482,    42,    -1,   138,    41,   482,    49,   482,
      42,    -1,   144,    41,   482,    49,   482,    42,    -1,   113,
      41,   482,    49,   482,    42,    -1,   114,    41,   482,    49,
     482,    42,    -1,   115,    41,   482,    42,    -1,   147,    41,
     482,    42,    -1,   140,    41,   482,    42,    -1,   136,    41,
     482,    42,    -1,   133,    41,   482,    42,    -1,   127,    41,
     482,    42,    -1,   122,    41,   482,    42,    -1,   121,    41,
     482,    42,    -1,   120,   188,    -1,   109,   188,    -1,   110,
     188,    -1,   111,    41,   482,    42,    -1,   146,    41,   482,
      42,    -1,   135,    41,   482,    42,    -1,   124,    41,   482,
      42,    -1,   119,    41,   482,    42,    -1,    71,   406,    -1,
      72,    41,   482,    49,   482,    49,   482,    42,    -1,    73,
      41,   482,    49,   482,    42,    -1,    74,    41,   482,    49,
     482,    42,    -1,    83,    41,   482,    49,   482,    42,    -1,
      84,    41,   482,    42,    -1,    85,    41,   482,    42,    -1,
      86,    41,   482,    42,    -1,    87,    41,   482,    42,    -1,
     101,    41,   482,    42,    -1,   507,    -1,   511,    -1,   514,
      -1,    41,   482,    42,    -1,   188,    -1,    88,    41,   482,
      49,   482,   508,    42,    -1,    -1,   404,    -1,   134,    41,
     482,    49,   482,   508,    42,    -1,    75,    41,   482,    49,
     482,    49,   482,   508,    42,    -1,    -1,    -1,    76,   512,
     513,   347,    -1,    -1,    -1,    66,    76,   515,   516,   347,
      -1,    94,    41,   403,   518,    42,    -1,   519,    41,   403,
     482,    42,    -1,    99,    41,   403,   482,   521,    42,    -1,
      20,    -1,   482,    -1,    95,    -1,    96,    -1,    97,    -1,
      98,    -1,   100,    -1,    50,    77,    56,   533,    -1,    -1,
     520,    -1,   534,   523,    -1,    -1,   401,    -1,   533,   527,
      -1,    89,   534,    -1,   187,    -1,   525,    -1,    -1,   526,
      -1,   529,    -1,   530,    -1,   531,    -1,   167,    -1,   168,
      -1,   169,    -1,   170,    -1,   171,    -1,   172,    -1,   173,
      -1,   174,    -1,   175,    -1,   165,    -1,   166,    -1,   176,
      -1,   178,    -1,   177,    -1,   179,    -1,   180,    -1,   535,
      -1,   182,    -1,   181,    -1,   183,    -1,   184,    -1
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
     394,   397,   398,   400,   403,   406,   407,   409,   410,   414,
     415,   417,   419,   421,   423,   425,   427,   429,   431,   433,
     435,   437,   439,   444,   445,   447,   450,   451,   453,   457,
     461,   465,   471,   477,   483,   484,   488,   489,   493,   494,
     498,   505,   508,   509,   511,   512,   514,   517,   519,   520,
     523,   526,   527,   529,   530,   534,   535,   539,   542,   544,
     547,   549,   552,   553,   555,   558,   560,   562,   564,   566,
     570,   574,   575,   579,   580,   582,   583,   585,   589,   590,
     593,   594,   595,   596,   605,   608,   611,   612,   614,   616,
     618,   620,   622,   623,   628,   631,   632,   634,   638,   639,
     642,   645,   648,   649,   651,   653,   655,   657,   659,   661,
     663,   665,   667,   669,   671,   674,   675,   679,   680,   681,
     682,   689,   690,   691,   698,   699,   700,   709,   716,   719,
     721,   723,   724,   725,   732,   733,   736,   738,   739,   745,
     746,   749,   751,   755,   756,   759,   760,   765,   767,   768,
     771,   773,   775,   777,   779,   781,   783,   785,   786,   787,
     792,   793,   794,   799,   800,   804,   805,   808,   811,   813,
     815,   817,   820,   822,   823,   830,   831,   833,   836,   837,
     840,   842,   843,   849,   850,   854,   855,   859,   861,   862,
     864,   868,   871,   872,   874,   877,   878,   881,   883,   885,
     888,   891,   892,   895,   897,   898,   902,   903,   907,   909,
     910,   912,   913,   918,   920,   922,   923,   927,   928,   930,
     933,   934,   937,   939,   941,   944,   947,   948,   951,   953,
     955,   956,   960,   963,   964,   967,   968,   972,   975,   976,
     979,   982,   983,   985,   987,   990,   992,   994,   996,   998,
    1000,  1003,  1007,  1009,  1013,  1016,  1017,  1020,  1021,  1025,
    1026,  1028,  1030,  1032,  1035,  1037,  1039,  1041,  1043,  1044,
    1049,  1054,  1056,  1058,  1060,  1062,  1064,  1065,  1067,  1069,
    1072,  1074,  1076,  1077,  1082,  1087,  1089,  1092,  1094,  1096,
    1098,  1100,  1102,  1104,  1106,  1108,  1110,  1112,  1114,  1116,
    1118,  1120,  1122,  1124,  1126,  1129,  1132,  1133,  1136,  1139,
    1142,  1143,  1146,  1148,  1151,  1152,  1154,  1157,  1160,  1163,
    1166,  1169,  1172,  1175,  1179,  1181,  1184,  1186,  1188,  1191,
    1194,  1195,  1197,  1200,  1203,  1206,  1207,  1210,  1213,  1214,
    1217,  1220,  1223,  1226,  1228,  1230,  1232,  1234,  1236,  1238,
    1240,  1242,  1244,  1248,  1253,  1258,  1265,  1270,  1275,  1280,
    1285,  1288,  1291,  1296,  1301,  1306,  1311,  1314,  1316,  1321,
    1323,  1328,  1333,  1338,  1345,  1352,  1359,  1366,  1373,  1378,
    1383,  1388,  1393,  1398,  1403,  1408,  1413,  1416,  1419,  1422,
    1427,  1432,  1437,  1442,  1447,  1450,  1459,  1466,  1473,  1480,
    1485,  1490,  1495,  1500,  1505,  1507,  1509,  1511,  1515,  1517,
    1525,  1526,  1528,  1536,  1546,  1547,  1548,  1553,  1554,  1555,
    1561,  1567,  1573,  1580,  1582,  1584,  1586,  1588,  1590,  1592,
    1594,  1599,  1600,  1602,  1605,  1606,  1608,  1611,  1614,  1616,
    1618,  1619,  1621,  1623,  1625,  1627,  1629,  1631,  1633,  1635,
    1637,  1639,  1641,  1643,  1645,  1647,  1649,  1651,  1653,  1655,
    1657,  1659,  1661,  1663,  1665,  1667
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   553,   553,   556,   562,   567,   578,   579,   580,   581,
     585,   590,   594,   596,   600,   602,   605,   607,   611,   611,
     629,   635,   638,   642,   643,   644,   645,   651,   652,   655,
     657,   661,   665,   669,   670,   674,   675,   679,   679,   687,
     693,   697,   698,   701,   703,   707,   711,   715,   716,   720,
     721,   725,   725,   733,   739,   743,   746,   748,   752,   752,
     759,   761,   765,   768,   770,   774,   777,   780,   786,   792,
     794,   792,   804,   804,   848,   851,   859,   862,   866,   859,
     885,   893,   896,   903,   906,   911,   918,   921,   926,   935,
     940,   945,   950,   955,   958,   963,   969,   974,   977,   985,
     998,  1004,  1010,  1019,  1033,  1041,  1044,  1052,  1055,  1062,
    1065,  1070,  1078,  1085,  1086,  1090,  1096,  1102,  1109,  1116,
    1118,  1123,  1130,  1133,  1138,  1141,  1146,  1149,  1154,  1158,
    1162,  1169,  1172,  1179,  1182,  1185,  1188,  1194,  1200,  1203,
    1210,  1215,  1222,  1226,  1234,  1236,  1244,  1247,  1255,  1263,
    1264,  1271,  1275,  1283,  1286,  1291,  1294,  1298,  1304,  1310,
    1314,  1320,  1323,  1327,  1333,  1336,  1338,  1342,  1342,  1351,
    1353,  1357,  1358,  1359,  1360,  1361,  1362,  1363,  1364,  1365,
    1366,  1367,  1371,  1377,  1380,  1387,  1394,  1397,  1401,  1407,
    1413,  1419,  1425,  1431,  1437,  1437,  1448,  1448,  1459,  1459,
    1470,  1477,  1483,  1486,  1490,  1493,  1497,  1501,  1508,  1511,
    1520,  1526,  1529,  1533,  1533,  1542,  1542,  1551,  1557,  1561,
    1568,  1571,  1576,  1578,  1582,  1588,  1591,  1594,  1597,  1604,
    1611,  1617,  1617,  1625,  1627,  1631,  1633,  1637,  1640,  1642,
    1647,  1652,  1655,  1647,  1666,  1670,  1673,  1675,  1679,  1680,
    1693,  1694,  1699,  1699,  1710,  1714,  1716,  1726,  1730,  1733,
    1749,  1754,  1758,  1761,  1765,  1766,  1767,  1768,  1769,  1770,
    1771,  1772,  1773,  1776,  1780,  1786,  1786,  1802,  1806,  1808,
    1802,  1819,  1823,  1819,  1832,  1836,  1832,  1853,  1869,  1875,
    1876,  1880,  1882,  1880,  1889,  1891,  1895,  1903,  1903,  1910,
    1912,  1918,  1919,  1922,  1924,  1930,  1930,  1935,  1941,  1943,
    1947,  1950,  1953,  1956,  1959,  1962,  1965,  1971,  1975,  1971,
    1985,  1989,  1985,  1999,  1999,  2011,  2013,  2017,  2027,  2028,
    2029,  2033,  2041,  2045,  2045,  2055,  2058,  2065,  2071,  2073,
    2087,  2090,  2090,  2100,  2100,  2103,  2103,  2109,  2112,  2114,
    2119,  2124,  2128,  2130,  2135,  2139,  2141,  2145,  2149,  2157,
    2162,  2166,  2168,  2172,  2180,  2180,  2183,  2183,  2189,  2192,
    2194,  2198,  2198,  2204,  2205,  2209,  2209,  2214,  2216,  2220,
    2223,  2225,  2229,  2238,  2244,  2248,  2251,  2253,  2257,  2264,
    2268,  2268,  2278,  2284,  2287,  2293,  2293,  2303,  2309,  2312,
    2318,  2324,  2327,  2331,  2332,  2338,  2341,  2344,  2350,  2353,
    2356,  2359,  2365,  2366,  2372,  2378,  2381,  2387,  2387,  2397,
    2400,  2404,  2407,  2410,  2416,  2419,  2427,  2428,  2432,  2432,
    2445,  2473,  2476,  2479,  2482,  2485,  2492,  2495,  2500,  2504,
    2511,  2512,  2516,  2516,  2528,  2555,  2559,  2566,  2567,  2571,
    2572,  2576,  2579,  2583,  2586,  2592,  2593,  2597,  2600,  2603,
    2606,  2609,  2610,  2616,  2621,  2630,  2637,  2640,  2648,  2657,
    2664,  2667,  2674,  2679,  2692,  2696,  2700,  2704,  2708,  2712,
    2716,  2720,  2724,  2728,  2735,  2740,  2749,  2752,  2759,  2762,
    2769,  2772,  2777,  2780,  2784,  2798,  2801,  2809,  2818,  2821,
    2828,  2831,  2834,  2837,  2841,  2842,  2843,  2844,  2847,  2850,
    2853,  2856,  2860,  2866,  2869,  2872,  2875,  2878,  2881,  2884,
    2888,  2891,  2894,  2897,  2900,  2903,  2906,  2909,  2910,  2913,
    2914,  2917,  2920,  2923,  2926,  2929,  2932,  2935,  2938,  2941,
    2944,  2947,  2950,  2953,  2956,  2959,  2962,  2965,  2968,  2971,
    2974,  2977,  2980,  2983,  2986,  2989,  2992,  2995,  2998,  3001,
    3004,  3007,  3010,  3013,  3016,  3017,  3018,  3024,  3027,  3034,
    3041,  3044,  3048,  3054,  3060,  3063,  3060,  3075,  3078,  3075,
    3091,  3095,  3100,  3109,  3112,  3116,  3119,  3122,  3125,  3128,
    3134,  3140,  3143,  3147,  3157,  3160,  3165,  3173,  3180,  3184,
    3192,  3196,  3200,  3201,  3202,  3206,  3207,  3208,  3212,  3213,
    3214,  3218,  3219,  3220,  3224,  3225,  3229,  3230,  3231,  3232,
    3236,  3237,  3241,  3242,  3246,  3277
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
  const int SPARQLfedParser::yylast_ = 2665;
  const int SPARQLfedParser::yynnts_ = 348;
  const int SPARQLfedParser::yyempty_ = -2;
  const int SPARQLfedParser::yyfinal_ = 11;
  const int SPARQLfedParser::yyterror_ = 1;
  const int SPARQLfedParser::yyerrcode_ = 256;
  const int SPARQLfedParser::yyntokens_ = 189;

  const unsigned int SPARQLfedParser::yyuser_token_number_max_ = 443;
  const SPARQLfedParser::token_number_type SPARQLfedParser::yyundef_token_ = 2;


} // w3c_sw

/* Line 1136 of lalr1.cc  */
#line 6366 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1138 of lalr1.cc  */
#line 3283 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

    e_Validation SPARQLfedDriver::DefaultValidation = VALIDATE_all;

    SPARQLfedDriver::SPARQLfedDriver (std::string baseURI, AtomFactory* atomFactory) : 
	YaccDriver(baseURI, atomFactory), curSubject(NULL), curPredicate(NULL), 
	curBGP(NULL), curFilter(NULL), curResultSet(NULL), curResult(NULL),
	curExprList(NULL), validate(DefaultValidation), root(NULL), unnestTree(false)
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


