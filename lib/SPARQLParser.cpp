
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
   Foundation, Inc.
   
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


/* Line 311 of lalr1.cc  */
#line 43 "C:\\Users\\Jelle\\Documents\\GitHub\\SWObjects\\lib\\SPARQLParser.cpp"


#include "SPARQLParser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 370 "..\\..\\lib\\SPARQLParser.ypp"

#include "SPARQLScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 537 "..\\..\\lib\\SPARQLParser.ypp"

#include "SPARQLScanner.hpp"

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


/* Line 317 of lalr1.cc  */
#line 79 "C:\\Users\\Jelle\\Documents\\GitHub\\SWObjects\\lib\\SPARQLParser.cpp"

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
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


/* Line 380 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace w3c_sw {

/* Line 380 of lalr1.cc  */
#line 148 "C:\\Users\\Jelle\\Documents\\GitHub\\SWObjects\\lib\\SPARQLParser.cpp"
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  SPARQLParser::yytnamerr_ (const char *yystr)
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

#endif

  /// Build a parser object.
  SPARQLParser::SPARQLParser (class SPARQLDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  SPARQLParser::~SPARQLParser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  SPARQLParser::yy_symbol_value_print_ (int yytype,
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
  SPARQLParser::yy_symbol_print_ (int yytype,
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
  SPARQLParser::yydestruct_ (const char* yymsg,
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
  SPARQLParser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  SPARQLParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  SPARQLParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  SPARQLParser::debug_level_type
  SPARQLParser::debug_level () const
  {
    return yydebug_;
  }

  void
  SPARQLParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  SPARQLParser::parse ()
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
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 553 of lalr1.cc  */
#line 37 "..\\..\\lib\\SPARQLParser.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
    driver.yylloc = &yylloc;
}

/* Line 553 of lalr1.cc  */
#line 333 "C:\\Users\\Jelle\\Documents\\GitHub\\SWObjects\\lib\\SPARQLParser.cpp"

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
    if (yyn == yypact_ninf_)
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
	if (yyn == 0 || yyn == yytable_ninf_)
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

/* Line 678 of lalr1.cc  */
#line 562 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 565 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 576 "..\\..\\lib\\SPARQLParser.ypp"
    {
	assert(driver.lastWhereClause != NULL);
	if ((yysemantic_stack_[(3) - (3)].p_ValuesClause) != NULL) // got a bindings clause
	    driver.lastWhereClause->m_GroupGraphPattern = 
		driver.makeConjunction(driver.lastWhereClause->m_GroupGraphPattern, (yysemantic_stack_[(3) - (3)].p_ValuesClause));
	(yyval.p_Operation) = (yysemantic_stack_[(3) - (2)].p_Operation);
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 620 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.startBindingSet();
      }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 623 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  if ((yysemantic_stack_[(3) - (1)].p_RSName) != NULL) {
	      std::string s = (yysemantic_stack_[(3) - (1)].p_RSName)->name;
	      delete (yysemantic_stack_[(3) - (1)].p_RSName);
	      driver.bindingsMap[s] = (yysemantic_stack_[(3) - (3)].p_TableOperation);
	      driver.curOp = (yysemantic_stack_[(3) - (2)].p_TableOperation);
	  } else {
	      // if ($<p_TableOperation>2 != NULL)
	      driver.curOp = driver.makeConjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), (yysemantic_stack_[(3) - (3)].p_TableOperation));
	  }
      }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 637 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_RSName) = (yysemantic_stack_[(2) - (1)].p_RSName);
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 643 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_RSName) = NULL;
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 650 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TableOperation) = new ValuesClause(driver.endBindingSet());
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 653 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TableOperation) = new ValuesClause(driver.endBindingSet());
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 656 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TableOperation) = new ValuesClause(driver.endBindingSet());
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 659 "..\\..\\lib\\SPARQLParser.ypp"
    {
	throw std::runtime_error("need to partition out results set part of SimpleEngine::loadDataOrResults");
    }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 662 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.ensureGraphPattern();
	driver.curOp = NULL;
	//throw std::runtime_error("IMPL");
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 700 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 702 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 708 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 747 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 749 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 755 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 774 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.startBindingRow(false);
      }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 776 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 796 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 799 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 802 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 808 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 814 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 816 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 818 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 826 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 829 "..\\..\\lib\\SPARQLParser.ypp"
    {
	if (driver.validate & SPARQLDriver::VALIDATE_selectGrouped) {
	    const ExpressionAliasList* e = (yysemantic_stack_[(5) - (5)].p_SolutionModifier)->getGroupedBy();
	    if (e) {
		std::set<const TTerm*> errorSet = (yysemantic_stack_[(5) - (2)].p_Project).varSet->getNonProjectableVars(e, driver.atomFactory);
		if (errorSet.size() != 0)
		    error(yylloc, "can't select " + comma_str(errorSet) + " because "
			  + (errorSet.size() == 1 ? "it's" : "they're") + "not in a GROUP BY.");
	    }
	}
	if (driver.validate & SPARQLDriver::VALIDATE_noReassign) {
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

  case 77:

/* Line 678 of lalr1.cc  */
#line 870 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 873 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 881 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
      }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 884 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 888 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  if (!driver.curGraphName || (yysemantic_stack_[(3) - (2)].p_Project).varSet->includes(driver.curGraphName)) {
	      (yyval.p_GraphName) = NULL;
	  } else {
	      (yyval.p_GraphName) = driver.curGraphName;
	      driver.curGraphName = driver.createBNode();
	  }
      }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 895 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  if ((yysemantic_stack_[(7) - (4)].p_GraphName) != NULL)
	      driver.curGraphName = (yysemantic_stack_[(7) - (4)].p_GraphName);
	  if ((yysemantic_stack_[(7) - (7)].p_ValuesClause) != NULL)
	      (yysemantic_stack_[(7) - (5)].p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yysemantic_stack_[(7) - (5)].p_WhereClause)->m_GroupGraphPattern, (yysemantic_stack_[(7) - (7)].p_ValuesClause));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (3)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(7) - (2)].p_Project).distinctness, (yysemantic_stack_[(7) - (2)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(7) - (5)].p_WhereClause), (yysemantic_stack_[(7) - (6)].p_SolutionModifier))));
	  driver.countStar = (yysemantic_stack_[(7) - (1)].p_parentCountStar);
      }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 907 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 919 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 922 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 929 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 937 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 944 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 952 "..\\..\\lib\\SPARQLParser.ypp"
    {
	if (driver.validate & SPARQLDriver::VALIDATE_namedProjection && (yysemantic_stack_[(4) - (3)].p_Variable) == NULL)
	    error(yylloc, (yysemantic_stack_[(4) - (2)].p_Expression)->str() + " must be selected AS some variable");
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 966 "..\\..\\lib\\SPARQLParser.ypp"
    {
	if (driver.validate & SPARQLDriver::VALIDATE_namedProjection)
	    error(yylloc, (yysemantic_stack_[(1) - (1)].p_Expression)->str() + " must be selected AS some variable");
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 971 "..\\..\\lib\\SPARQLParser.ypp"
    {
	if (driver.validate & SPARQLDriver::VALIDATE_namedProjection)
	    error(yylloc, (yysemantic_stack_[(1) - (1)].p_RDFLiteral)->str() + " must be selected AS some variable");
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 976 "..\\..\\lib\\SPARQLParser.ypp"
    {
	if (driver.validate & SPARQLDriver::VALIDATE_namedProjection)
	    error(yylloc, (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)->str() + " must be selected AS some variable");
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 981 "..\\..\\lib\\SPARQLParser.ypp"
    {
	if (driver.validate & SPARQLDriver::VALIDATE_namedProjection)
	    error(yylloc, (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)->str() + " must be selected AS some variable");
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 986 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 989 "..\\..\\lib\\SPARQLParser.ypp"
    {
	if (driver.validate & SPARQLDriver::VALIDATE_namedProjection)
	    error(yylloc, (yysemantic_stack_[(1) - (1)].p_Expression)->str() + " must be selected AS some variable");
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 994 "..\\..\\lib\\SPARQLParser.ypp"
    {
	if (driver.validate & SPARQLDriver::VALIDATE_namedProjection)
	    error(yylloc, (yysemantic_stack_[(1) - (1)].p_Expression)->str() + " must be selected AS some variable");
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1005 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1008 "..\\..\\lib\\SPARQLParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1016 "..\\..\\lib\\SPARQLParser.ypp"
    {
	if (driver.validate & SPARQLDriver::VALIDATE_uniqueProjection) {
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

  case 103:

/* Line 678 of lalr1.cc  */
#line 1029 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1035 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Operation) = (yysemantic_stack_[(2) - (2)].p_Operation);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1041 "..\\..\\lib\\SPARQLParser.ypp"
    {
	if (driver.validate & SPARQLDriver::VALIDATE_constructNoQuads &&
	    dynamic_cast<const DefaultGraphPattern*>((yysemantic_stack_[(4) - (1)].p_TableOperation)) == NULL) {
	    error(yylloc, "can't CONSTRUCT quad pattern " + (yysemantic_stack_[(4) - (1)].p_TableOperation)->str() + ".");
	}
	driver.lastWhereClause = (yysemantic_stack_[(4) - (3)].p_WhereClause);
	/* $1 is NO LONGER known to be a DefaultGraphPattern because of grammar restrictions. */
	(yyval.p_Operation) = new Construct((yysemantic_stack_[(4) - (1)].p_TableOperation), (yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1050 "..\\..\\lib\\SPARQLParser.ypp"
    {
	if (driver.validate & SPARQLDriver::VALIDATE_constructNoQuads &&
	    dynamic_cast<const DefaultGraphPattern*>((yysemantic_stack_[(4) - (3)].p_TableOperation)) == NULL) {
	    error(yylloc, "can't re-CONSTRUCT quad pattern " + (yysemantic_stack_[(4) - (3)].p_TableOperation)->str() + ".");
	}
	SWObjectDuplicator dup(driver.atomFactory);
	(yysemantic_stack_[(4) - (3)].p_TableOperation)->express(&dup);
	driver.lastWhereClause = new WhereClause((yysemantic_stack_[(4) - (3)].p_TableOperation));
	(yyval.p_Operation) = new Construct(dup.last.tableOperation, (yysemantic_stack_[(4) - (1)].p_DatasetClauses), driver.lastWhereClause, (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1064 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.restoreFilter(NULL);
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause) ? (yysemantic_stack_[(5) - (4)].p_WhereClause) : new WhereClause(new DefaultGraphPattern());
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1073 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm))));
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1076 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_TTerm))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1084 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1087 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1094 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1102 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(4) - (3)].p_WhereClause);
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1110 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1122 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1128 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1134 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1141 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.ensureGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1155 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1162 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1170 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1178 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1186 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1194 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1201 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1204 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1211 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1214 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1217 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1226 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1232 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1238 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1241 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1253 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1260 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1264 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1274 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1282 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1285 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1293 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1302 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1309 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1313 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1321 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1329 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1336 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1342 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 1352 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_ValuesClause) = (yysemantic_stack_[(2) - (2)].p_ValuesClause);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 1358 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_ValuesClause) = NULL;
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1365 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  (yyval.p_Operation) = driver.root;
      }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1380 "..\\..\\lib\\SPARQLParser.ypp"
    {
	OperationSet* ret = driver.root ? dynamic_cast<OperationSet*>(driver.root) : new OperationSet();
	ret->push_back((yysemantic_stack_[(1) - (1)].p_Operation));
	driver.root = ret;
	std::copy(driver.bnodesInThisOpperation.begin(), driver.bnodesInThisOpperation.end(),
		  std::inserter(driver.bnodesInOldOpperations, driver.bnodesInOldOpperations.begin()));
      }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 1409 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(4) - (2)].p_Silence), (yysemantic_stack_[(4) - (3)].p_URI), (yysemantic_stack_[(4) - (4)].p_URI));
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 1415 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 1418 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 1425 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 1432 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 1439 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 1445 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 1451 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 1457 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1463 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1469 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1475 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.inINSERTDATA = true;
      }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1477 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  driver.inINSERTDATA = false;
	  (yyval.p_Operation) = new Insert((yysemantic_stack_[(3) - (3)].p_TableOperation), NULL);
	  driver.curOp = NULL;
	  driver.curBGP = NULL;
	}
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 1486 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.inDELETEDATA = true;
      }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 1488 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  driver.inDELETEDATA = false;
	  (yyval.p_Operation) = new Delete(true, (yysemantic_stack_[(3) - (3)].p_TableOperation), NULL);
	  driver.curOp = NULL;
	  driver.curBGP = NULL;
	}
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 1497 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.inDELETEWHERE = true;
      }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 1499 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  driver.inDELETEWHERE = false;
	  (yyval.p_Operation) = new Delete(true, (yysemantic_stack_[(3) - (3)].p_TableOperation), NULL);
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 1508 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(6) - (2)].p_DeleteInsert).del, (yysemantic_stack_[(6) - (2)].p_DeleteInsert).ins, new WhereClause(driver.ensureGraphPattern()), (yysemantic_stack_[(6) - (4)].p_TableOperation), (yysemantic_stack_[(6) - (1)].p_URI), (yysemantic_stack_[(6) - (3)].p_UsingPairs));
	driver.curOp = NULL;
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 1516 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 1522 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 1529 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 1536 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 1540 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 1547 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_UsingPairs) = NULL;
    }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 1550 "..\\..\\lib\\SPARQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (1)].p_UsingPairs) == NULL)
	    (yysemantic_stack_[(2) - (1)].p_UsingPairs) = new std::vector<s_UsingPair>();
	(yysemantic_stack_[(2) - (1)].p_UsingPairs)->push_back((yysemantic_stack_[(2) - (2)].p_UsingPair));
	(yyval.p_UsingPairs) = (yysemantic_stack_[(2) - (1)].p_UsingPairs);
    }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 1559 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(2) - (2)].p_TableOperation);
    }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 1565 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TableOperation) = NULL;
    }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 1572 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.inDELETECLAUSE = true;
      }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 1574 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  driver.inDELETECLAUSE = false;
	  (yyval.p_Delete) = new Delete(false, (yysemantic_stack_[(3) - (3)].p_TableOperation), NULL);
      }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 1581 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.inINSERTQUAD = true;
      }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 1583 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  driver.inINSERTQUAD = false;
	  (yyval.p_Insert) = new Insert((yysemantic_stack_[(3) - (3)].p_TableOperation), NULL);
      }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 1590 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_UsingPair) = (yysemantic_stack_[(2) - (2)].p_UsingPair);
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 1596 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_UsingPair).named = false;
	(yyval.p_UsingPair).name = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 1600 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_UsingPair).named = true;
	(yyval.p_UsingPair).name = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 1607 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 1610 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 1621 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 1627 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 1630 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_URI) = driver.atomFactory->getURI("tag:eric@w3.org,2012-swobjparm/DEFAULT");
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 1633 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_URI) = driver.atomFactory->getURI("tag:eric@w3.org,2012-swobjparm/NAMED");
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 1636 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_URI) = driver.atomFactory->getURI("tag:eric@w3.org,2012-swobjparm/ALL");
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 1643 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
	driver.curOp = NULL;
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 1650 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TableOperation) = (yysemantic_stack_[(3) - (2)].p_TableOperation);
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 1656 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 1658 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  (yyval.p_TableOperation) = driver.ensureGraphPattern();
	  driver.curOp = NULL;
      }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 1687 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 1692 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 1695 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 1698 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.ensureGraphPattern()));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 1720 "..\\..\\lib\\SPARQLParser.ypp"
    {
	BindingsMap::const_iterator rs = driver.bindingsMap.find((yysemantic_stack_[(1) - (1)].p_RSName)->name);
	if (rs == driver.bindingsMap.end() || rs->second == NULL) {
	    error(yylloc, std::string("") + "unknown named result set " + (yysemantic_stack_[(1) - (1)].p_RSName)->name);
	    driver.curOp = new DefaultGraphPattern();
	} else {
	    SWObjectDuplicator dup(driver.atomFactory);
	    rs->second->express(&dup);
	    TableOperation* b = dup.last.tableOperation;
	    driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, b) : b;
	}
      }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 1743 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 1745 "..\\..\\lib\\SPARQLParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 1819 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_ValuesClause)) : (yysemantic_stack_[(1) - (1)].p_ValuesClause);
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 1826 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.curOp = new Print(driver.ensureGraphPattern());
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 1832 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 1836 "..\\..\\lib\\SPARQLParser.ypp"
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

  case 284:

/* Line 678 of lalr1.cc  */
#line 1848 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 1852 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  (yyval.p_FilterExpressions) = driver.saveFilter();
      }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 1854 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 1857 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_FilterExpressions));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.ensureGraphPattern()));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 1865 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 1869 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  (yyval.p_FilterExpressions) = driver.saveFilter();
      }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 1871 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_FilterExpressions));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(6) - (5)].p_TTerm), driver.ensureGraphPattern(), (yysemantic_stack_[(6) - (4)].p_Silence), driver.atomFactory, false));
      }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 1878 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 1882 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  (yyval.p_FilterExpressions) = driver.saveFilter();
      }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 1884 "..\\..\\lib\\SPARQLParser.ypp"
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

  case 294:

/* Line 678 of lalr1.cc  */
#line 1899 "..\\..\\lib\\SPARQLParser.ypp"
    {
	const TableOperation* op = driver.ensureGraphPattern();
	if (driver.validate & SPARQLDriver::VALIDATE_noReassign &&
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

  case 295:

/* Line 678 of lalr1.cc  */
#line 1915 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_ValuesClause) = (yysemantic_stack_[(2) - (2)].p_ValuesClause);
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 1926 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 1928 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
      }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 1930 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  (yyval.p_ValuesClause) = new ValuesClause(driver.endBindingSet());
      }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 1941 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.startBindingRow();
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
	driver.endBindingRow();
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 1949 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.startBindingSet();
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 1951 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  (yyval.p_ValuesClause) = new ValuesClause(driver.endBindingSet());
      }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 1958 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 1970 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 1976 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 1978 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 1981 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 1993 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 1996 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 1999 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 2002 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 2005 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 2008 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 2011 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 2017 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 2021 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  (yyval.p_FilterExpressions) = driver.saveFilter();
      }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 2023 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_FilterExpressions));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 2031 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 2035 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  (yyval.p_FilterExpressions) = driver.saveFilter();
      }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 2037 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_FilterExpressions));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 2045 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 2050 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.ensureGraphPattern());
      }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 2063 "..\\..\\lib\\SPARQLParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    driver.ensureGraphPattern();
	    driver.curFilter = new FilterExpressions();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 2079 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 2087 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 2091 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 2094 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yysemantic_stack_[(6) - (4)].p_Expressions);
      }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 2101 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 2104 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 2111 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 2119 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 2134 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 2137 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 2140 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(5) - (3)].p_Expressions);
      }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 2147 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 2150 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 2192 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 2196 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::RDF_type;
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 2219 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)), true);
    }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 2227 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 2230 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 2245 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 2256 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 2276 "..\\..\\lib\\SPARQLParser.ypp"
    {
	const URI* t = (yysemantic_stack_[(1) - (1)].p_PropertyPath)->release();
	// if (!t)
	//     w3c_sw_LINEN << "property path: " << $1->str() << "\n";
	(yyval.p_TTerm) = t ? t : (const TTerm*)new PropertyPath((yysemantic_stack_[(1) - (1)].p_PropertyPath));
    }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 2285 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 2304 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)), true);
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 2315 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_PropertyPath) = driver.lastPropertyPathAlternative;
	driver.lastPropertyPathAlternative = (yysemantic_stack_[(1) - (1)].p_PropertyPath);
      }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 2318 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  (yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (3)].p_PropertyPath) ? (yysemantic_stack_[(3) - (3)].p_PropertyPath) : (yysemantic_stack_[(3) - (1)].p_PropertyPath);
	  driver.lastPropertyPathAlternative = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
      }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 2325 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(2) - (2)].p_PropertyPath);
    }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 2331 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_PropertyPath) = NULL;
    }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 2334 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Alternative((yysemantic_stack_[(2) - (1)].p_PropertyPath) ? (yysemantic_stack_[(2) - (1)].p_PropertyPath) : driver.lastPropertyPathAlternative, (yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 2340 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_PropertyPath) = driver.lastPropertyPathSequence;
	driver.lastPropertyPathSequence = (yysemantic_stack_[(1) - (1)].p_PropertyPath);
      }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 2343 "..\\..\\lib\\SPARQLParser.ypp"
    {	
	  (yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (3)].p_PropertyPath) ? (yysemantic_stack_[(3) - (3)].p_PropertyPath) : (yysemantic_stack_[(3) - (1)].p_PropertyPath);
	  driver.lastPropertyPathSequence = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
      }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 2350 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(2) - (2)].p_PropertyPath);
    }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 2356 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_PropertyPath) = NULL;
    }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 2359 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Sequence((yysemantic_stack_[(2) - (1)].p_PropertyPath) ? (yysemantic_stack_[(2) - (1)].p_PropertyPath) : driver.lastPropertyPathSequence, (yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 2365 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(2) - (2)].p_RepeatRange).min == 1 && (yysemantic_stack_[(2) - (2)].p_RepeatRange).max == 1 ? (yysemantic_stack_[(2) - (1)].p_PropertyPath) : new PropertyPath::Repeated((yysemantic_stack_[(2) - (1)].p_PropertyPath), (yysemantic_stack_[(2) - (2)].p_RepeatRange).min, (yysemantic_stack_[(2) - (2)].p_RepeatRange).max);
    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 2371 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_RepeatRange).min = 1; (yyval.p_RepeatRange).max = 1;
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 2379 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Inverse((yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 2385 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_RepeatRange).min = 0; (yyval.p_RepeatRange).max = 1;
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 2388 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_RepeatRange).min = 0; (yyval.p_RepeatRange).max = PropertyPath::Repeated::Unlimited;
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 2391 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_RepeatRange).min = 1; (yyval.p_RepeatRange).max = PropertyPath::Repeated::Unlimited;
    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 2397 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 2400 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate(TTerm::RDF_type);
    }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 2403 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Negated((yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 2406 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
    }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 2416 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
    }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 2425 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_PropertyPath) = (yysemantic_stack_[(2) - (2)].p_PropertyPath);
    }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 2431 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_PropertyPath) = NULL;
    }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 2434 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Alternative((yysemantic_stack_[(2) - (1)].p_PropertyPath) ? (yysemantic_stack_[(2) - (1)].p_PropertyPath) : driver.lastPropertyPathSetAlternative, (yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 2440 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_PropertyPath) = driver.lastPropertyPathSetAlternative;
	driver.lastPropertyPathSetAlternative = (yysemantic_stack_[(1) - (1)].p_PropertyPath);
      }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 2443 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  driver.lastPropertyPathSetAlternative = (yysemantic_stack_[(3) - (2)].p_PropertyPath);
	  (yyval.p_PropertyPath) = (yysemantic_stack_[(3) - (3)].p_PropertyPath);
      }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 2450 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_PropertyPath) = NULL;
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 2457 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 2460 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate(TTerm::RDF_type);
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 2463 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Inverse((yysemantic_stack_[(2) - (2)].p_PropertyPath));
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 2469 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate((yysemantic_stack_[(1) - (1)].p_URI));
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 2472 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_PropertyPath) = new PropertyPath::Predicate(TTerm::RDF_type);
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 2485 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 2489 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 2498 "..\\..\\lib\\SPARQLParser.ypp"
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

  case 438:

/* Line 678 of lalr1.cc  */
#line 2526 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 2529 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 2532 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 2535 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 2538 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 2545 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 2553 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 2557 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 2569 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 2573 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject;
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 2581 "..\\..\\lib\\SPARQLParser.ypp"
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

  case 452:

/* Line 678 of lalr1.cc  */
#line 2608 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 2612 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 2629 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 2636 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 2639 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 2650 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 2653 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 2656 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 2659 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 2663 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::RDF_nil; // !!! new GraphTerm_rule5($1);
    }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 2674 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 2683 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 2690 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 2693 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 2701 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 2710 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 2717 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 2720 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 2732 "..\\..\\lib\\SPARQLParser.ypp"
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

  case 481:

/* Line 678 of lalr1.cc  */
#line 2745 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = NULL;
    }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 2753 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 2757 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 2761 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 2765 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 2769 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 2773 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 2777 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = false;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 2781 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_ComparatorSense).neg = true;
	(yyval.p_ComparatorSense).comp = new NaryIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 2793 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 2802 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 2805 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 2812 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 2815 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 2822 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 2830 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 2833 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 2837 "..\\..\\lib\\SPARQLParser.ypp"
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

  case 502:

/* Line 678 of lalr1.cc  */
#line 2851 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 2854 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 2862 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 2871 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 2874 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 2881 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 2884 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 2887 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 2897 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 2900 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 2903 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 2906 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 2913 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 2925 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 2928 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 2931 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 2934 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 2937 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 2940 "..\\..\\lib\\SPARQLParser.ypp"
    {
      (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), new TTermExpression(driver.atomFactory->getURI(driver.getBase())), NULL));
    }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 2943 "..\\..\\lib\\SPARQLParser.ypp"
    {
      (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), new TTermExpression(driver.atomFactory->getURI(driver.getBase())), NULL));
    }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 2947 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 2950 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 2953 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 2956 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ceil, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 2959 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 2962 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 2965 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 2969 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 2973 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 2976 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 2979 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 2982 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 2985 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 2988 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 2991 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_before, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 2994 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring_after, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 2997 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 3000 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 3003 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 3006 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 3009 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 3012 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 3015 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 3018 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_tz, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 3021 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 3024 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_uuid, NULL, NULL, NULL));
    }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 3027 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_struuid, NULL, NULL, NULL));
    }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 3030 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 3033 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 3036 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 3039 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 3042 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 3045 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 3048 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 3051 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 3054 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 3057 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 3060 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 3063 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 3066 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 3069 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 3072 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 3083 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 3092 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 3099 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 3106 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 3113 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 3119 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_replace, (yysemantic_stack_[(9) - (3)].p_Expression), (yysemantic_stack_[(9) - (5)].p_Expression), (yysemantic_stack_[(9) - (7)].p_Expression))); // !! , $8
    }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 3125 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 3128 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 3132 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  (yyval.p_Expression) = new ExistsExpression(driver.ensureGraphPattern());
	  driver.curOp = (yysemantic_stack_[(4) - (3)].p_TableOperation);
	  driver.countStar = (yysemantic_stack_[(4) - (2)].p_parentCountStar);
      }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 3140 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
      }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 3143 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  (yyval.p_TableOperation) = driver.curOp;
	  driver.curOp = NULL;
      }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 3147 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  // $$ = new ExistsExpression(false, driver.ensureGraphPattern());
	  (yyval.p_Expression) = new BooleanNegation(new ExistsExpression(driver.ensureGraphPattern()));
	  driver.curOp = (yysemantic_stack_[(5) - (4)].p_TableOperation);
	  driver.countStar = (yysemantic_stack_[(5) - (3)].p_parentCountStar);
      }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 3156 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 3164 "..\\..\\lib\\SPARQLParser.ypp"
    {
	driver.countStar = true;
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression), AggregateCall::ScalarVals()));
    }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 3173 "..\\..\\lib\\SPARQLParser.ypp"
    {
	  AggregateCall::ScalarVals svals;
	  if ((yysemantic_stack_[(6) - (5)].p_RDFLiteral) != NULL)
	      svals["separator"] = (yysemantic_stack_[(6) - (5)].p_RDFLiteral)->getLexicalValue();
	  (yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group_concat, (yysemantic_stack_[(6) - (3)].p_distinctness), (yysemantic_stack_[(6) - (4)].p_Expression), svals));
    }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 3189 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 3196 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 3199 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 3202 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 3205 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 3208 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 3214 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 3220 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 3227 "..\\..\\lib\\SPARQLParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 3237 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 3245 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 3253 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 3260 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 3264 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 3272 "..\\..\\lib\\SPARQLParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 3326 "..\\..\\lib\\SPARQLParser.ypp"
    {
	if (driver.validate & SPARQLDriver::VALIDATE_bnodeScope) {
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



/* Line 678 of lalr1.cc  */
#line 4382 "C:\\Users\\Jelle\\Documents\\GitHub\\SWObjects\\lib\\SPARQLParser.cpp"
	default:
          break;
      }
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
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
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

    yyerror_range[0] = yylocation_stack_[yylen - 1];
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
	if (yyn != yypact_ninf_)
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

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
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
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

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
  SPARQLParser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int SPARQLParser::yypact_ninf_ = -853;
  const short int
  SPARQLParser::yypact_[] =
  {
        73,  -116,    91,  -853,  -853,  -853,   683,  -853,  -853,  -853,
    -853,  -853,    98,    98,    98,    98,    60,    20,  -853,    77,
      98,    98,    98,  -853,  -853,  -853,    85,  -853,   108,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,    99,   120,  -853,
      77,    46,   137,    46,  -853,    75,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,   276,  -853,  -853,  -853,  -853,  -853,
      95,  -853,    50,    50,    50,   110,   110,    60,    22,  -853,
    -853,  -853,   163,  -853,   100,  -853,  -853,  -853,   154,  -853,
    -853,    64,  -853,   177,    77,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,   175,  1172,    13,    60,  -853,    95,  -853,    70,
    -853,   125,    11,  -853,  -853,   121,    77,   153,   159,  -853,
    -853,  -853,  -853,  -853,  -853,    57,  -853,    23,  -853,  -853,
    -853,  1836,    95,    73,  -853,  -853,    60,    60,    55,  -853,
    -853,    58,   222,  -853,  -853,  -853,   137,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,   247,  -853,  -853,
    -853,  -853,   241,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,   -30,  -853,  -853,    77,  -853,  -853,  -853,  -853,
    -853,   125,   125,   125,  -853,   273,  -853,   208,  -853,  -853,
    -853,  -853,  -853,    50,  -853,    50,    50,   278,  -853,  -853,
    -853,   282,  -853,  2316,   253,   287,   289,    24,    28,   290,
     293,   295,   298,  -853,   301,   302,   308,   311,   313,   314,
     317,   322,   325,   326,   329,    28,   330,  -853,  -853,  -853,
    -853,   332,  -853,   333,   199,   203,   369,   370,   373,   374,
     242,   386,   245,   389,   392,   393,   394,   396,   398,   399,
     401,   402,   403,   404,   407,   409,   411,   417,   425,   426,
     427,   429,   433,   440,   441,  -853,  -853,  2435,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,   442,  -853,
    -853,  -853,    34,   125,   348,  -853,  -853,  -853,    60,    27,
    -853,   444,  -853,  -853,  -853,    84,  -853,    97,   479,  1172,
    -853,  -853,    97,  2121,    97,    77,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  2673,  2757,   462,  -853,  1277,  -853,
    -853,  -853,  -853,   452,    66,  -853,  2316,  2554,  2554,  2554,
    -853,   400,  -853,  -853,  -853,  -853,   321,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,    34,  -853,
    2316,  2316,  2316,  -853,  -853,  2316,  -853,  -853,  2316,  2316,
    2316,  2316,  -853,  2316,  2316,  2316,  2316,    57,  2316,  2316,
    2316,  2316,  2316,  2316,  -853,   472,   472,  2316,  -853,  -853,
    2316,  2316,  2316,  2316,  -853,  2316,  -853,  2316,  2316,  2316,
    2316,  2316,  2316,  2316,  2316,  2316,  2316,  2316,  2316,  2316,
    2316,  2316,  2316,  2316,  2316,  2316,  2316,  2316,  2316,  -853,
     472,   472,  -853,  -853,  -853,  -853,    77,  -853,  -853,    11,
     315,    11,  -853,  1427,  -853,  -853,  1243,  -853,  -853,   388,
    -853,  -853,   341,  -853,  -853,  -853,  -853,   443,  2121,  -853,
    -853,  1529,   491,  -853,  -853,  -853,  -853,  -853,  2017,  -853,
    -853,  -853,  -853,  2316,  2673,  -853,  -853,  -853,  -853,  2757,
    -853,  -853,  -853,  -853,  -853,   474,   244,  -853,  -853,  -853,
    -853,   108,   463,  -853,  -853,  -853,    35,   465,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,    16,   461,  -853,  -853,  -853,
      57,  -853,   467,   450,   455,  2316,  2316,  2316,  2316,  2316,
    2316,   445,    28,  -853,  -853,   252,    65,  -853,  -853,  -853,
     469,   473,   476,  -853,   458,   470,   477,   478,    11,   481,
     486,   480,   489,   490,   484,   492,   494,   495,   496,   493,
    -853,  1696,  2316,   498,   501,   497,   499,   503,   508,   509,
     510,   513,   514,   512,   527,   528,   529,   524,   533,   536,
     537,   531,   539,   540,   541,   543,   544,   538,   546,   547,
     549,  2316,  2316,  -853,  -853,  -853,  -853,    54,  -853,  -853,
    -853,  1490,  -853,  -853,   410,  -853,  -853,  -853,  -853,  -853,
    -853,  1490,  -853,  -853,   362,  -853,    45,  -853,    30,  -853,
    -853,  -853,  -853,   548,  -853,  1172,   276,  -853,  -853,   400,
    -853,  -853,  1957,   356,   428,  -853,  -853,   565,   567,    68,
    -853,  -853,   338,   556,  2073,  -853,  -853,  2172,    68,    68,
     229,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  2316,  -853,
    2316,  -853,  -853,  -853,  -853,  -853,  -853,  -853,    28,  -853,
    2316,  2316,    65,  -853,  -853,  -853,  2316,  2316,  -853,    11,
    -853,  -853,  -853,  -853,  2316,  2316,  2316,  2316,  -853,  -853,
    -853,  2316,  -853,  -853,  2316,  -853,  -853,  -853,  -853,  2316,
    -853,  -853,   559,   553,  -853,  -853,  2316,  2316,  -853,  -853,
    -853,  -853,  -853,  -853,  2316,  -853,  -853,  -853,  2316,  -853,
    -853,  -853,  2316,  -853,  -853,  -853,  -853,  -853,  2316,  -853,
    -853,  -853,   564,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,   -46,   563,  -853,  -853,  -853,   134,   566,  -853,  -853,
    -853,   558,   560,  -853,  -853,  -853,   569,  -853,  -853,  1957,
    -853,   572,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,   238,  -853,    49,    81,   561,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,    76,  -853,  -853,  -853,  -853,
    -853,  -853,    22,  -853,  -853,  2757,   574,    11,  -853,  1461,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  2073,  -853,  -853,  2097,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,    82,   575,   585,   586,   580,
     588,   589,   584,  -853,   557,  -853,   593,   594,   596,   597,
     584,   603,   604,  -853,  -853,  -853,  -853,  -853,  -853,  1427,
    -853,  -853,  -853,  1243,    97,  -853,  2121,  -853,   579,  -853,
    -853,  -853,   606,    43,  -853,   106,  -853,  -853,  -853,  -853,
    -853,  2172,  -853,  -853,  -853,  -853,  -853,  -853,  -853,   609,
    -853,  -853,  -853,  -853,    11,  -853,  -853,  2316,  -853,  2073,
      11,  -853,  -853,  -853,   964,  -853,  2316,  -853,  2316,  -853,
    -853,  2316,  -853,  -853,  -853,   608,   595,  -853,  -853,  -853,
    -853,   610,  -853,  -853,    88,  1200,  -853,  -853,  -853,  -853,
    2121,  -853,  -853,  -853,  -853,   612,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,   551,   592,   125,   276,    98,    98,  -853,
      11,   570,  -853,  -853,  -853,  -853,  -853,   615,   584,  -853,
     -35,  -853,  -853,  -853,  -853,   611,    26,  -853,  1172,  -853,
    -853,   613,   616,   238,  -853,   238,  -853,    85,  -853,   276,
     276,  -853,    57,   617,  -853,   624,  -853,  -853,  -853,  1490,
    1490,  1490,   620,   568,    68,  -853,  2172,  -853,  -853,  -853,
    -853,    11,    11,   644,   626,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,    43,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
      60,  -853,    11,  -853,  2121,   609,  -853,  -853,  -853
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  SPARQLParser::yydefact_[] =
  {
        12,     0,     0,     2,     4,     3,   205,    14,    13,    10,
      71,     1,   186,   186,   186,   186,    77,     0,    77,     0,
     186,   186,   186,   197,   199,   201,   164,     6,     0,     7,
       8,     9,   173,   166,   170,   174,   175,   176,   180,   177,
     178,   179,   181,   182,   183,   184,   206,     0,    16,   187,
       0,     0,     0,     0,   234,     0,   104,    77,   111,   627,
     630,   629,   462,   463,   110,    77,   108,   460,   461,   628,
     122,   204,   225,   225,   225,     0,     0,     0,   298,     5,
     165,   162,    86,    77,   168,   216,   218,   211,   207,   210,
      72,    11,    15,   189,     0,   230,   229,   231,   228,   191,
     193,   192,     0,   236,     0,     0,    78,   122,   109,   112,
     123,   125,     0,   226,   223,     0,     0,     0,     0,   234,
     198,   200,   202,   163,   296,     0,   297,     0,    84,    85,
      87,     0,   122,    12,   169,   171,     0,     0,   214,   209,
     208,     0,     0,    17,    22,    18,     0,   190,   185,   227,
     232,   438,   439,   440,   441,   442,   435,   621,   622,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   623,   625,
     624,   626,   631,   632,   469,   242,   237,   250,   352,   434,
     433,   444,     0,   350,   458,   459,   465,   466,   609,   610,
     611,   467,   607,   464,   468,     0,   115,   116,   117,   118,
     120,   125,   125,   125,   113,     0,   114,   127,   126,   257,
     253,   121,   252,   225,   224,   225,   225,     0,   299,   306,
     308,     0,   103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   581,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   592,   593,   594,
     595,     0,   596,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   100,   102,    83,    98,
      96,    92,   571,   534,   536,   572,   573,    97,     0,    93,
      94,    95,     0,   125,   205,   167,   217,   219,     0,     0,
     215,     0,   212,    73,    20,     0,   188,     0,   235,   236,
     251,   248,   355,   443,     0,     0,   605,   606,   608,   603,
     119,   106,   105,   107,     0,     0,   129,   128,     0,   194,
     196,   195,   233,     0,     0,   315,     0,     0,     0,     0,
     517,    89,   470,   473,   477,   479,   481,   491,   502,   505,
     510,   511,   512,   518,   513,   514,   515,   516,   601,   584,
       0,     0,     0,   575,   527,     0,   347,   561,     0,     0,
       0,     0,   582,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   533,   342,   342,     0,   554,   555,
       0,     0,     0,     0,   528,     0,   553,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   101,
     342,   342,   339,   338,    76,   213,     0,   220,   221,     0,
       0,     0,    59,     0,    33,    48,     0,    19,    23,     0,
      31,    24,     0,    46,    25,    26,   365,     0,   443,   364,
     243,     0,     0,   249,   353,   354,   356,   455,   443,   445,
     454,   351,   604,     0,   133,   134,   137,   139,   136,   140,
     141,   143,   337,   335,   336,     0,   131,   130,   256,   449,
     254,     0,     0,   255,   263,   261,     0,     0,   373,   448,
     447,   371,   301,   309,   307,     0,     0,   508,   509,   507,
       0,    90,     0,   471,   475,     0,     0,     0,     0,     0,
       0,     0,     0,   480,   482,   492,   504,   602,   600,   585,
       0,     0,     0,   348,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     343,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   222,   203,    74,    27,     0,   321,    37,
     322,    38,    34,    35,     0,   323,   318,   319,   320,   317,
      52,    53,    49,    50,     0,    31,     0,    46,     0,   436,
     362,   368,   370,     0,   239,   236,     0,   437,   446,    89,
     135,   142,     0,     0,     0,   124,   132,   156,   158,     0,
      80,   258,   327,   270,   260,   269,   265,   443,   376,     0,
       0,   305,   312,   314,   316,   519,    88,    91,     0,   474,
       0,   478,   483,   484,   485,   486,   487,   488,     0,   489,
       0,     0,   497,   503,   493,   494,     0,     0,   506,     0,
     525,   526,   574,   345,     0,     0,     0,     0,   583,   520,
     521,     0,   523,   524,     0,   566,   567,   568,   569,     0,
     590,   591,     0,   598,   570,   556,     0,     0,   545,   560,
     552,   551,   532,   559,     0,   550,   531,   549,     0,   558,
     548,   539,     0,   530,   547,   538,   529,   537,     0,   535,
     557,   546,     0,   340,    58,    61,    60,    36,    41,    51,
      56,     0,     0,    29,    39,    32,     0,     0,    44,    54,
      47,   357,   366,   240,   241,   245,     0,   149,   150,   144,
     145,     0,   147,   148,   152,   153,   160,   161,   154,   157,
     155,   159,     0,   416,     0,     0,     0,   378,   380,   381,
     389,   396,   397,   410,   402,   408,   390,   415,    81,   284,
     288,   291,   298,   282,   324,     0,     0,     0,   264,     0,
     280,   272,   274,   275,   276,   278,   279,   273,   271,   328,
     277,   260,   266,   457,   443,   452,   456,   374,   375,   377,
     372,   300,   302,   303,   310,   472,   476,   490,   499,   500,
     498,   501,   495,   496,   586,     0,     0,     0,     0,     0,
       0,     0,   577,   587,     0,   599,     0,     0,     0,     0,
     577,     0,     0,   588,   345,    66,    42,    28,    30,     0,
      57,    43,    45,     0,   359,   363,   443,   369,     0,   138,
     146,   151,     0,   426,   429,     0,   417,   419,   428,   411,
     450,   443,   400,   405,   413,   414,   412,   407,   409,   122,
     285,   289,   292,   295,     0,   325,   334,     0,   281,   260,
       0,   267,   451,   453,     0,   349,     0,   346,     0,   563,
     564,     0,   522,   565,   578,     0,     0,   589,   543,   544,
     540,     0,   541,   542,     0,     0,    40,    55,   360,   361,
     443,   367,   246,   418,   427,     0,   424,   432,   430,   431,
     387,   393,   395,   398,   403,   125,     0,   186,   186,   283,
       0,     0,   262,   332,   313,   311,   344,     0,   577,   576,
       0,   579,   341,    62,    67,    63,     0,   358,   236,   420,
     422,   379,   391,     0,   401,     0,   406,   164,   286,     0,
       0,   326,     0,   329,   562,     0,   597,    64,    65,     0,
       0,     0,     0,   425,   384,   388,   443,   394,   399,   404,
      82,     0,     0,     0,     0,   330,   333,   580,    70,    69,
      68,   247,     0,   423,   382,   385,   386,   392,   287,   290,
       0,   294,     0,   421,   443,   122,   331,   383,   293
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLParser::yypgoto_[] =
  {
      -853,  -853,  -853,  -853,  -853,  -853,   542,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,    69,  -853,   221,  -853,
    -178,  -853,  -853,    86,  -853,  -853,    71,  -853,   227,  -853,
    -173,  -853,  -853,    80,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,   102,
    -853,  -853,  -853,  -853,   191,  -853,  -853,  -853,    67,  -853,
     397,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -146,  -100,  -853,  -186,  -853,  -853,
    -853,  -853,  -853,  -853,   211,  -853,  -853,   210,  -853,  -853,
     -59,  -853,  -853,  -853,  -853,  -853,  -853,    63,    72,  -274,
    -853,  -853,   573,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
      -9,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,   614,  -853,  -853,  -853,    53,
    -853,    19,   643,   -76,   625,   590,  -853,  -305,   -82,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -415,  -853,
    -853,  -853,  -853,  -606,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,   -79,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -421,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -595,  -110,   342,  -853,  -318,  -770,  -132,  -211,  -853,  -853,
    -853,  -853,  -853,  -853,  -151,  -853,  -853,  -853,  -853,  -141,
    -852,  -853,  -853,  -142,  -853,  -853,  -853,  -853,  -853,  -342,
    -853,  -269,  -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,  -270,   -45,  -853,  -853,  -853,  -853,  -245,  -853,
    -853,  -853,   -42,  -853,  -246,  -853,  -853,  -853,  -853,  -853,
    -853,  -853,  -853,  -828,  -853,   -85,  -853,  -853,  -853,  -853,
    -299,  -853,  -618,  -853,  -853,  -853,  -853,  -279,  -607,   -80,
     -14,     3,  -853,   848,  -853,  -853,  -853,    78,  -853,  -853,
      79,  -853,  -853,  -853,    47,  -853,  -853,    74,  -853,  -853,
    -853,  -348,  -853,  -343,   -54,  -313,  -123,  -853,  -853,  -787,
    -853,  -853,  -853,  -853,  -853,  -853,  -853,  -853,   -86,  -853,
    -853,  -853,  -853,  -853,  -853,   -93,  -853,  -853,  -853,   201,
    -853,   195,   200,   230,  -223,   -17,  -853,  -853
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,    26,     5,     6,     7,    48,    91,
     143,   315,   144,   145,   447,   448,   606,   449,   450,   591,
     592,   735,   849,   593,   847,   451,   608,   452,   453,   601,
     602,   740,   853,   603,   851,   454,   587,   726,   845,   978,
     954,   915,   955,     8,    92,   141,   440,    27,    28,    55,
     490,   491,   778,   879,    83,   130,   131,   511,   512,   285,
     286,   287,   288,    29,    56,    30,    64,    65,   203,    31,
     106,   196,   197,   198,   199,   111,   112,   206,   207,   336,
     486,   625,   208,   474,   475,   337,   479,   480,   487,   749,
     750,   751,   752,   753,   626,   758,   760,   627,   628,    79,
      80,    81,     9,   134,   135,    32,    84,    33,    34,    35,
      50,   147,   148,    36,    37,    38,    39,    40,    41,    42,
      75,    43,    76,    44,    77,    45,    46,    47,   139,    87,
     138,   310,   311,    88,   136,    89,   137,   312,   437,   115,
     116,    98,    99,    57,   120,   102,   103,   175,   615,   460,
     318,   461,   462,   858,   958,   176,   320,   321,   211,   492,
     212,   338,   493,   494,   788,   632,   495,   635,   636,   789,
     790,   791,   884,   792,   880,   936,   991,   793,   881,   937,
     794,   882,   938,   795,   796,   123,   124,   125,   343,   640,
     812,   126,   127,   344,   221,   894,   644,   814,   505,   594,
     797,   885,   940,   798,   799,   890,   996,  1012,   973,   800,
     481,   482,   433,   844,   551,   904,   825,   377,   673,   177,
     324,   322,   464,   465,   457,   918,   919,   855,   741,   458,
     610,   857,   742,   611,   496,   639,   638,   807,   808,   766,
     871,   767,  1005,  1014,  1006,   985,   961,   768,   769,   930,
     987,   962,   931,   770,   771,   872,   964,   933,   772,   873,
     966,   934,   773,   877,   774,   878,   775,   866,  1003,   983,
     924,   960,   925,   867,   928,   467,   179,   317,   180,   181,
     182,   468,   498,   499,   629,   500,   804,   612,   932,   470,
     459,   350,   185,   351,   352,   649,   513,   353,   651,   514,
     354,   355,   523,   524,   356,   357,   662,   668,   821,   663,
     525,   358,   526,   359,   360,   361,   362,   374,   292,   905,
     293,   294,   295,   382,   538,   296,   529,   669,   363,   692,
     298,   835,   836,   364,   528,   365,   327,   328,   329,   366,
     188,   189,   190,   367,   192,   368,    69,   194
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SPARQLParser::yytable_ninf_ = -444;
  const short int
  SPARQLParser::yytable_[] =
  {
        68,   122,    71,    66,    51,    52,    53,   202,   291,   204,
     186,    72,    73,    74,   463,   331,   332,   333,   178,   803,
      67,   289,   483,   183,   584,   604,   586,   754,   802,   201,
     805,   737,   303,    93,   394,   926,   633,   195,   299,   497,
      58,  -268,  -268,  -268,   469,   297,   732,    68,   209,   330,
     108,   436,    94,   911,   641,   897,   113,   642,   734,   325,
     306,   307,    10,  -304,   219,   372,  -268,    67,   957,   375,
      95,   100,  -268,  -268,   738,   431,   308,   149,   552,   634,
    -268,  -268,   979,  -268,   -21,   666,   193,   200,     1,   733,
     863,    11,   724,   104,   864,   725,   874,    54,   104,   214,
     864,   -21,    85,    86,   441,   846,   184,  -122,   503,   762,
     110,    49,   581,   582,   302,   105,    78,   434,   104,   763,
      70,   442,   762,   678,   895,    82,   117,   118,   218,   667,
     952,   896,   763,   764,   290,   110,    90,   896,   875,   168,
     169,   170,   171,    94,   897,   865,   764,   119,   456,   734,
     133,   865,    96,    97,   754,   326,   114,   927,    86,   107,
    -268,   975,  1017,   309,   291,   316,   483,   109,   -21,   455,
     765,   466,   210,   471,  1013,   980,   981,   289,   200,   876,
     604,   128,   129,  -268,   739,   132,   803,   146,   443,   618,
     886,    59,    60,    61,   299,   891,  -268,   893,    59,    60,
      61,   297,   643,    62,    63,    59,    60,    61,  -304,   220,
     373,   478,   484,   150,   376,   -21,   -21,   205,   -21,   813,
     432,    59,    60,    61,   476,   142,   186,    59,    60,    61,
     186,  -122,   435,   213,   178,   444,   445,   313,   446,   183,
      62,    63,   -21,   -21,   -21,   186,    59,    60,    61,    62,
      63,    62,    63,   803,   824,    59,    60,    61,   501,    59,
      60,    61,    59,    60,    61,   215,   339,   811,   340,   341,
     302,   216,   588,   623,   624,    59,    60,    61,   314,   762,
      62,    63,   323,   942,    59,    60,    61,   850,   739,   763,
     290,   319,   438,   507,   508,   509,   809,   810,   200,   334,
      68,   335,   193,   764,   187,    68,   193,    68,   472,   483,
     744,   659,   818,   819,   660,   661,   342,   302,   302,   345,
      67,   193,   184,   822,   823,    67,   184,    67,   370,   369,
     371,   378,   300,   191,   379,   497,   380,   477,   497,   381,
     765,   184,   383,   384,   779,   780,   781,   504,  -172,   385,
     596,   478,   386,   596,   387,   388,   484,    12,   389,    13,
      14,   301,    15,   390,   476,   186,   391,   392,   803,   782,
     393,   395,   888,   396,   397,   186,  -259,   515,   516,   517,
     518,   519,   520,   783,   784,   398,   785,   521,   522,   399,
     543,   590,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,    59,    60,    61,
     400,   401,    62,    63,   402,   403,    59,    60,    61,   583,
     162,   163,   164,   165,   166,   167,   599,   405,   404,   599,
     407,   406,   604,   408,   409,   410,   483,   411,   861,   412,
     413,   193,   414,   415,   416,   417,   595,   817,   418,   595,
     419,   193,   420,    19,    59,    60,    61,   302,   421,    62,
      63,   184,   302,   786,    20,    21,   422,   423,   424,   939,
     425,   184,   483,   945,   426,   943,    22,   477,    23,    24,
      25,   427,   428,   430,   439,  -244,   787,   485,   300,   502,
     550,   510,   443,   585,   956,   446,   609,   616,   596,   484,
     622,   631,   497,   645,   648,   497,   637,   674,   596,   647,
     650,   670,   658,   646,   728,   671,   730,   301,   672,   675,
     187,   756,   186,   679,   187,   971,   676,   677,   680,   681,
     178,   682,   683,   684,   685,   183,   686,   687,   688,   187,
     694,   186,   689,   695,   186,   698,   696,   596,   697,   191,
     699,   700,   701,   191,   501,   702,   703,   806,   998,   999,
    1000,   704,   652,   653,   654,   655,   656,   657,   191,   705,
     706,   707,   497,   708,   599,   709,  1008,  1009,   710,   711,
     712,   713,   714,   715,   599,   716,   717,   718,   719,   720,
     497,   721,   743,   757,   595,   624,   623,  1016,   193,    68,
     801,   833,   745,   834,   595,   302,   843,   848,   854,   856,
     852,   859,   777,   346,   870,   887,   922,   193,   184,    67,
     193,   777,   777,   599,   898,   755,   484,   899,   900,   901,
     902,   903,   776,   896,   906,   907,   908,   184,   909,   910,
     184,   776,   776,   595,   597,   912,   913,   597,   923,   110,
     949,   950,   951,   982,   959,   963,   965,   974,  1001,   187,
     977,   972,   484,   984,   995,   986,   997,  1010,  1011,   187,
     605,   916,  1002,   598,   731,   304,   598,   727,   736,   607,
     917,   729,   630,  -172,   429,   620,   746,   497,   191,   621,
     860,   761,    12,   990,    13,    14,   101,    15,   191,   759,
     -75,   121,   140,   883,    16,    17,   305,   889,   186,   217,
     527,   186,   914,   920,   921,  1004,  1007,   862,   988,   989,
     664,   501,    18,   869,   806,   665,   815,   976,     0,   816,
       0,     0,   302,     0,     0,     0,   820,     0,     0,     0,
       0,     0,     0,     0,     0,   777,     0,   868,   777,   967,
       0,     0,   755,     0,     0,     0,   596,     0,     0,     0,
     596,     0,     0,   186,     0,     0,     0,     0,   302,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   186,   935,
       0,     0,     0,     0,   193,     0,     0,   193,    19,     0,
       0,   806,   597,     0,     0,     0,   186,     0,     0,    20,
      21,   596,   597,     0,   184,     0,     0,   184,     0,   501,
       0,    22,     0,    23,    24,    25,   187,     0,     0,     0,
       0,   598,   596,     0,     0,     0,     0,   186,     0,     0,
       0,   598,   599,     0,     0,   187,   599,    68,   187,   193,
       0,   597,     0,     0,     0,   191,   868,     0,   929,     0,
       0,     0,   595,     0,   193,     0,   595,    67,     0,   184,
       0,     0,     0,     0,   191,   186,     0,   191,     0,     0,
     598,     0,   193,   178,   184,     0,     0,   599,   183,     0,
       0,     0,     0,     0,     0,     0,   596,   596,   596,     0,
       0,     0,   184,   186,     0,     0,     0,   595,   599,     0,
       0,     0,     0,   193,     0,     0,   806,     0,     0,     0,
       0,     0,     0,     0,     0,  1018,     0,     0,   595,    68,
       0,   186,   968,   184,     0,     0,     0,     0,   969,   970,
       0,     0,     0,     0,  1015,     0,     0,     0,     0,    67,
       0,   193,     0,     0,     0,     0,   777,     0,   777,     0,
       0,     0,    68,    68,     0,   992,   993,     0,     0,     0,
       0,   184,   599,   599,   599,     0,     0,   777,     0,   193,
       0,     0,    67,    67,     0,   994,     0,     0,     0,     0,
       0,     0,   595,   595,   595,   868,     0,   776,     0,   184,
       0,     0,     0,     0,     0,     0,     0,   193,     0,     0,
       0,     0,   187,     0,     0,   187,   944,   588,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   184,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   191,     0,     0,   191,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     597,     0,     0,     0,   597,     0,     0,   187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   187,     0,     0,     0,     0,     0,     0,   598,
       0,     0,     0,   598,     0,     0,   191,     0,     0,     0,
     187,     0,     0,     0,     0,   597,     0,     0,     0,     0,
       0,   191,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   597,     0,     0,   191,
       0,   187,     0,     0,   598,     0,   590,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    59,    60,    61,   598,     0,    62,    63,     0,
     191,     0,     0,     0,     0,     0,     0,     0,     0,   187,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     597,   597,   597,     0,     0,     0,     0,   187,   191,     0,
       0,     0,     0,     0,   506,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   151,   152,   153,   154,   155,   598,
     598,   598,     0,  -443,     0,   187,   191,     0,   530,   531,
     532,     0,     0,   533,   156,     0,   534,   535,   536,   537,
       0,   539,   540,   541,   542,     0,   544,   545,   546,   547,
     548,   549,   953,   588,   191,   553,     0,     0,   554,   555,
     556,   557,     0,   558,     0,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,     0,   488,     0,
       0,     0,     0,  -260,  -260,  -260,   588,     0,     0,     0,
       0,     0,     0,     0,   -79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -260,   151,
     152,   153,   154,   155,  -260,  -260,     0,     0,  -443,     0,
       0,   619,  -260,  -260,     0,  -260,     0,     0,     0,   489,
       0,     0,     0,     0,     0,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      59,    60,    61,   172,   173,    62,    63,     0,   174,     0,
       0,     0,   590,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    59,    60,
      61,     0,     0,    62,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   600,     0,   691,
     693,     0,  -260,     0,     0,   590,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,    59,    60,    61,     0,  -260,    62,    63,     0,   722,
     723,     0,     0,     0,     0,     0,     0,     0,  -260,     0,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    59,    60,    61,   172,   173,
      62,    63,   613,   174,     0,     0,     0,  -238,  -238,  -238,
     588,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
       0,     0,  -238,     0,     0,   614,  -238,  -238,     0,  -238,
       0,     0,     0,  -238,     0,     0,     0,     0,     0,     0,
       0,     0,   826,   827,   828,   829,     0,     0,     0,   830,
     613,   589,   831,   588,     0,  -238,     0,   832,     0,     0,
       0,     0,     0,     0,   837,   838,     0,     0,     0,     0,
       0,     0,   839,     0,     0,     0,   840,     0,     0,     0,
     841,  -238,  -238,  -238,  -238,  -238,   842,  -238,     0,     0,
    -238,     0,     0,   614,     0,     0,     0,     0,     0,     0,
       0,  -238,     0,     0,     0,     0,  -238,     0,     0,   590,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    59,    60,    61,     0,  -238,
      62,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -238,     0,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,  -238,  -238,     0,  -238,     0,     0,
       0,     0,   590,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    59,    60,
      61,     0,     0,    62,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,     0,  -238,   690,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   941,     0,   346,     0,     0,
       0,     0,     0,     0,   946,     0,   947,     0,     0,   948,
       0,     0,     0,     0,     0,     0,     0,     0,   347,   348,
       0,   349,   224,     0,   225,   226,   227,   228,   229,   230,
     231,   232,   233,     0,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,     0,   245,     0,     0,     0,
     246,   247,   248,   249,   250,   251,   252,   253,     0,     0,
       0,     0,     0,     0,     0,   254,   255,   256,     0,   257,
     258,   259,     0,     0,   260,   261,   262,   263,   264,   265,
     266,     0,   267,   268,     0,   269,     0,     0,     0,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   222,     0,     0,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    59,    60,    61,   223,     0,    62,
      63,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   224,     0,   225,   226,   227,   228,   229,   230,
     231,   232,   233,     0,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,     0,   245,     0,     0,     0,
     246,   247,   248,   249,   250,   251,   252,   253,     0,     0,
       0,     0,     0,     0,     0,   254,   255,   256,     0,   257,
     258,   259,     0,     0,   260,   261,   262,   263,   264,   265,
     266,     0,   267,   268,     0,   269,     0,     0,     0,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   747,   748,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   346,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    59,    60,    61,     0,     0,    62,
      63,     0,     0,   224,     0,   225,   226,   227,   228,   229,
     230,   231,   232,   233,     0,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,     0,   245,     0,   151,
     152,   153,   154,   155,     0,     0,     0,     0,   253,   617,
       0,     0,     0,     0,     0,     0,   254,   255,   256,   156,
     257,   258,   259,     0,     0,   260,   261,   262,   263,   264,
     265,   266,     0,   267,   268,     0,   269,     0,     0,     0,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   151,   152,   153,   154,   155,
       0,     0,     0,     0,  -443,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   489,     0,     0,     0,   151,
     152,   153,   154,   155,     0,    59,    60,    61,     0,   892,
      62,    63,     0,     0,     0,     0,     0,     0,     0,   489,
       0,     0,     0,   151,   152,   153,   154,   155,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   156,     0,     0,     0,     0,     0,     0,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    59,    60,    61,   172,   173,
      62,    63,     0,   174,   151,   152,   153,   154,   155,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   489,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,    59,    60,    61,   172,   173,    62,    63,     0,   174,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    59,    60,    61,   172,   173,
      62,    63,     0,   174,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,    59,
      60,    61,   172,   173,    62,    63,     0,   174,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      59,    60,    61,   172,   173,    62,    63,   346,   174,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   347,   348,
       0,   349,   224,     0,   225,   226,   227,   228,   229,   230,
     231,   232,   233,     0,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,     0,   245,     0,     0,     0,
     246,   247,   248,   249,   250,   251,   252,   253,     0,     0,
       0,     0,     0,     0,     0,   254,   255,   256,     0,   257,
     258,   259,     0,     0,   260,   261,   262,   263,   264,   265,
     266,     0,   267,   268,     0,   269,     0,     0,     0,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   223,     0,     0,   157,
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
       0,     0,     0,     0,     0,   346,     0,     0,   157,   158,
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
       0,     0,     0,     0,   473,     0,     0,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    59,    60,    61,     0,     0,    62,    63,   224,
       0,   225,   226,   227,   228,   229,   230,   231,   232,   233,
       0,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,     0,   245,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   253,     0,     0,     0,     0,     0,
       0,     0,   254,   255,   256,     0,   257,   258,   259,     0,
       0,   260,   261,   262,   263,   264,   265,   266,   346,   267,
     268,     0,   269,     0,     0,     0,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,     0,     0,   224,     0,   225,   226,   227,   228,   229,
     230,   231,   232,   233,     0,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,     0,   245,     0,     0,
       0,    59,    60,    61,     0,     0,    62,    63,   253,     0,
       0,     0,     0,     0,     0,     0,   254,   255,   256,     0,
     257,   258,   259,     0,     0,   260,   261,   262,   263,   264,
     265,   266,     0,   267,   268,     0,   269,     0,     0,     0,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    59,    60,    61
  };

  /* YYCHECK.  */
  const short int
  SPARQLParser::yycheck_[] =
  {
        17,    77,    19,    17,    13,    14,    15,   107,   131,   109,
     103,    20,    21,    22,   319,   201,   202,   203,   103,   637,
      17,   131,   335,   103,   439,   446,   441,   622,   634,   105,
     637,     1,   132,    50,   245,   863,     1,    24,   131,   338,
      20,     6,     7,     8,   323,   131,     1,    64,    37,   195,
      64,    24,     6,   840,    38,   825,     6,    41,   104,    89,
     136,   137,   178,    41,    41,    41,    31,    64,   920,    41,
      24,    52,    37,    38,    44,    41,    21,    94,   396,    44,
      45,    46,    56,    48,    20,    20,   103,   104,    15,    44,
      41,     0,    38,    23,    51,    41,    20,    37,    23,   116,
      51,    37,     3,     4,    20,   151,   103,    37,    42,    41,
      40,    13,   430,   431,   131,    40,    31,   303,    23,    51,
      18,    37,    41,   538,    42,    17,    73,    74,   125,    64,
      42,    49,    51,    65,   131,    40,    16,    49,    62,   174,
     175,   176,   177,     6,   914,   102,    65,    37,    51,   104,
      50,   102,   106,   107,   749,   185,   106,    51,     4,    57,
     125,   948,  1014,   108,   287,   146,   479,    65,   104,   315,
     102,   322,   161,   324,  1002,   149,   150,   287,   195,   103,
     601,    18,    19,   148,   154,    83,   804,    10,   104,   468,
     785,   178,   179,   180,   287,   801,   161,   804,   178,   179,
     180,   287,   186,   183,   184,   178,   179,   180,   186,   186,
     186,   334,   335,    38,   186,   151,   152,    92,   154,   640,
     186,   178,   179,   180,   334,   161,   319,   178,   179,   180,
     323,   161,   308,   112,   319,   151,   152,   179,   154,   319,
     183,   184,   178,   179,   180,   338,   178,   179,   180,   183,
     184,   183,   184,   871,   669,   178,   179,   180,   338,   178,
     179,   180,   178,   179,   180,   112,   213,    38,   215,   216,
     287,   112,    43,    29,    30,   178,   179,   180,    56,    41,
     183,   184,    41,   889,   178,   179,   180,   153,   154,    51,
     287,    44,   309,   347,   348,   349,   638,   639,   315,    26,
     317,    93,   319,    65,   103,   322,   323,   324,   325,   622,
     615,   522,   660,   661,    62,    63,    38,   334,   335,    37,
     317,   338,   319,   666,   667,   322,   323,   324,    41,    76,
      41,    41,   131,   103,    41,   634,    41,   334,   637,    41,
     102,   338,    41,    41,     6,     7,     8,   344,     0,    41,
     443,   474,    41,   446,    41,    41,   479,     9,    41,    11,
      12,   131,    14,    41,   474,   458,    41,    41,   986,    31,
      41,    41,   787,    41,    41,   468,    38,    56,    57,    58,
      59,    60,    61,    45,    46,   186,    48,    66,    67,   186,
     387,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      41,    41,   183,   184,    41,    41,   178,   179,   180,   436,
     168,   169,   170,   171,   172,   173,   443,    41,   186,   446,
      41,   186,   853,    41,    41,    41,   749,    41,   751,    41,
      41,   458,    41,    41,    41,    41,   443,   658,    41,   446,
      41,   468,    41,   105,   178,   179,   180,   474,    41,   183,
     184,   458,   479,   125,   116,   117,    41,    41,    41,   884,
      41,   468,   785,   894,    41,   890,   128,   474,   130,   131,
     132,    41,    41,    41,    40,     6,   148,    25,   287,    37,
      18,    91,   104,   178,   915,   154,    53,     6,   591,   622,
      26,    38,   801,    42,    54,   804,    41,    49,   601,    42,
      55,    42,    67,   510,   104,    42,   154,   287,    42,    49,
     319,   165,   615,    42,   323,   940,    49,    49,    42,    49,
     615,    42,    42,    49,    42,   615,    42,    42,    42,   338,
      42,   634,    49,    42,   637,    42,    49,   640,    49,   319,
      42,    42,    42,   323,   634,    42,    42,   637,   979,   980,
     981,    49,   515,   516,   517,   518,   519,   520,   338,    42,
      42,    42,   871,    49,   591,    42,   991,   992,    42,    42,
      49,    42,    42,    42,   601,    42,    42,    49,    42,    42,
     889,    42,    44,   165,   591,    30,    29,  1012,   615,   616,
      44,    42,   616,    50,   601,   622,    42,    44,    50,    49,
      44,    42,   629,    41,    53,    41,    37,   634,   615,   616,
     637,   638,   639,   640,    49,   622,   749,    42,    42,    49,
      42,    42,   629,    49,    77,    42,    42,   634,    42,    42,
     637,   638,   639,   640,   443,    42,    42,   446,    42,    40,
      42,    56,    42,   958,    42,   104,    64,    42,    38,   458,
      49,    91,   785,    50,    47,    49,    42,    23,    42,   468,
     449,   849,   104,   443,   605,   133,   446,   591,   607,   452,
     853,   601,   491,     0,   287,   474,   619,   986,   458,   479,
     749,   628,     9,   967,    11,    12,    53,    14,   468,   627,
      17,    76,    88,   782,    21,    22,   133,   789,   801,   119,
     368,   804,   844,   854,   856,   984,   986,   762,   963,   965,
     525,   801,    39,   765,   804,   525,   648,   950,    -1,   650,
      -1,    -1,   749,    -1,    -1,    -1,   662,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   762,    -1,   764,   765,   935,
      -1,    -1,   749,    -1,    -1,    -1,   849,    -1,    -1,    -1,
     853,    -1,    -1,   856,    -1,    -1,    -1,    -1,   785,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   871,   879,
      -1,    -1,    -1,    -1,   801,    -1,    -1,   804,   105,    -1,
      -1,   871,   591,    -1,    -1,    -1,   889,    -1,    -1,   116,
     117,   894,   601,    -1,   801,    -1,    -1,   804,    -1,   889,
      -1,   128,    -1,   130,   131,   132,   615,    -1,    -1,    -1,
      -1,   591,   915,    -1,    -1,    -1,    -1,   920,    -1,    -1,
      -1,   601,   849,    -1,    -1,   634,   853,   854,   637,   856,
      -1,   640,    -1,    -1,    -1,   615,   863,    -1,   865,    -1,
      -1,    -1,   849,    -1,   871,    -1,   853,   854,    -1,   856,
      -1,    -1,    -1,    -1,   634,   958,    -1,   637,    -1,    -1,
     640,    -1,   889,   958,   871,    -1,    -1,   894,   958,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   979,   980,   981,    -1,
      -1,    -1,   889,   986,    -1,    -1,    -1,   894,   915,    -1,
      -1,    -1,    -1,   920,    -1,    -1,   986,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1015,    -1,    -1,   915,   936,
      -1,  1014,   936,   920,    -1,    -1,    -1,    -1,   937,   938,
      -1,    -1,    -1,    -1,  1010,    -1,    -1,    -1,    -1,   936,
      -1,   958,    -1,    -1,    -1,    -1,   963,    -1,   965,    -1,
      -1,    -1,   969,   970,    -1,   969,   970,    -1,    -1,    -1,
      -1,   958,   979,   980,   981,    -1,    -1,   984,    -1,   986,
      -1,    -1,   969,   970,    -1,   972,    -1,    -1,    -1,    -1,
      -1,    -1,   979,   980,   981,  1002,    -1,   984,    -1,   986,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1014,    -1,    -1,
      -1,    -1,   801,    -1,    -1,   804,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1014,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   801,    -1,    -1,   804,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     849,    -1,    -1,    -1,   853,    -1,    -1,   856,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   871,    -1,    -1,    -1,    -1,    -1,    -1,   849,
      -1,    -1,    -1,   853,    -1,    -1,   856,    -1,    -1,    -1,
     889,    -1,    -1,    -1,    -1,   894,    -1,    -1,    -1,    -1,
      -1,   871,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   915,    -1,    -1,   889,
      -1,   920,    -1,    -1,   894,    -1,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   915,    -1,   183,   184,    -1,
     920,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   958,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     979,   980,   981,    -1,    -1,    -1,    -1,   986,   958,    -1,
      -1,    -1,    -1,    -1,   346,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,   979,
     980,   981,    -1,    41,    -1,  1014,   986,    -1,   370,   371,
     372,    -1,    -1,   375,    52,    -1,   378,   379,   380,   381,
      -1,   383,   384,   385,   386,    -1,   388,   389,   390,   391,
     392,   393,    42,    43,  1014,   397,    -1,    -1,   400,   401,
     402,   403,    -1,   405,    -1,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,    -1,     1,    -1,
      -1,    -1,    -1,     6,     7,     8,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    41,    -1,
      -1,   473,    45,    46,    -1,    48,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,    -1,   186,    -1,
      -1,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,    -1,    -1,   183,   184,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,   551,
     552,    -1,   125,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,   148,   183,   184,    -1,   581,
     582,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,     1,   186,    -1,    -1,    -1,     6,     7,     8,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    41,    -1,    -1,    44,    45,    46,    -1,    48,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   674,   675,   676,   677,    -1,    -1,    -1,   681,
       1,   104,   684,    43,    -1,     6,    -1,   689,    -1,    -1,
      -1,    -1,    -1,    -1,   696,   697,    -1,    -1,    -1,    -1,
      -1,    -1,   704,    -1,    -1,    -1,   708,    -1,    -1,    -1,
     712,    32,    33,    34,    35,    36,   718,    38,    -1,    -1,
      41,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,   125,    -1,    -1,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,   148,
     183,   184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   161,    -1,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,    -1,   186,    -1,    -1,
      -1,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,    -1,    -1,   183,   184,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,    -1,   186,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   887,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,   896,    -1,   898,    -1,    -1,   901,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      -1,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,   113,
     114,   115,    -1,    -1,   118,   119,   120,   121,   122,   123,
     124,    -1,   126,   127,    -1,   129,    -1,    -1,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    41,    -1,   183,
     184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,   113,
     114,   115,    -1,    -1,   118,   119,   120,   121,   122,   123,
     124,    -1,   126,   127,    -1,   129,    -1,    -1,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    -1,    -1,   183,
     184,    -1,    -1,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    90,    -1,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,   101,    42,
      -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,    52,
     113,   114,   115,    -1,    -1,   118,   119,   120,   121,   122,
     123,   124,    -1,   126,   127,    -1,   129,    -1,    -1,    -1,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    -1,   178,   179,   180,    -1,    42,
     183,   184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,    -1,   186,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,    -1,   186,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,    -1,   186,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,    41,   186,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      -1,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
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
      86,    87,    88,    -1,    90,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,   110,   111,    -1,   113,   114,   115,
      -1,    -1,   118,   119,   120,   121,   122,   123,   124,    -1,
     126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    -1,    -1,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,    -1,    -1,   183,   184,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,   110,   111,    -1,   113,   114,   115,    -1,
      -1,   118,   119,   120,   121,   122,   123,   124,    41,   126,
     127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,    -1,    -1,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    -1,    90,    -1,    -1,
      -1,   178,   179,   180,    -1,    -1,   183,   184,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,
     113,   114,   115,    -1,    -1,   118,   119,   120,   121,   122,
     123,   124,    -1,   126,   127,    -1,   129,    -1,    -1,    -1,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   178,   179,   180
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLParser::yystos_[] =
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
     233,    20,    37,   104,   151,   152,   154,   201,   202,   204,
     205,   212,   214,   215,   222,   261,    51,   411,   416,   477,
     336,   338,   339,   334,   409,   410,   411,   462,   468,   474,
     476,   411,   532,    41,   270,   271,   398,   478,   503,   273,
     274,   397,   398,   502,   503,    25,   267,   275,     1,    52,
     237,   238,   346,   349,   350,   353,   421,   467,   469,   470,
     472,   476,    37,    42,   478,   385,   480,   501,   501,   501,
      91,   244,   245,   483,   486,    56,    57,    58,    59,    60,
      61,    66,    67,   489,   490,   497,   499,   399,   521,   513,
     480,   480,   480,   480,   480,   480,   480,   480,   511,   480,
     480,   480,   480,   478,   480,   480,   480,   480,   480,   480,
      18,   401,   401,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   401,   401,   532,   345,   178,   345,   223,    43,   104,
     162,   206,   207,   210,   386,   478,   522,   526,   530,   532,
     154,   216,   217,   220,   386,   205,   203,   215,   213,    53,
     417,   420,   474,     1,    44,   335,     6,    42,   474,   480,
     271,   274,    26,    29,    30,   268,   281,   284,   285,   471,
     241,    38,   352,     1,    44,   354,   355,    41,   423,   422,
     376,    38,    41,   186,   383,    42,   478,    42,    54,   482,
      55,   485,   491,   491,   491,   491,   491,   491,    67,   404,
      62,    63,   493,   496,   528,   529,    20,    64,   494,   514,
      42,    42,    42,   405,    49,    49,    49,    49,   345,    42,
      42,    49,    42,    42,    49,    42,    42,    42,    42,    49,
      20,   480,   516,   480,    42,    42,    49,    49,    42,    42,
      42,    42,    42,    42,    49,    42,    42,    42,    49,    42,
      42,    42,    49,    42,    42,    42,    42,    42,    49,    42,
      42,    42,   480,   480,    38,    41,   224,   210,   104,   220,
     154,   203,     1,    44,   104,   208,   213,     1,    44,   154,
     218,   415,   419,    44,   334,   477,   245,    27,    28,   276,
     277,   278,   279,   280,   397,   478,   165,   165,   282,   285,
     283,   284,    41,    51,    65,   102,   426,   428,   434,   435,
     440,   441,   445,   449,   451,   453,   478,   532,   239,     6,
       7,     8,    31,    45,    46,    48,   125,   148,   351,   356,
     357,   358,   360,   364,   367,   370,   371,   387,   390,   391,
     396,    44,   350,   469,   473,   475,   476,   424,   425,   426,
     426,    38,   377,   386,   384,   484,   487,   404,   498,   498,
     494,   495,   500,   500,   345,   403,   480,   480,   480,   480,
     480,   480,   480,    42,    50,   518,   519,   480,   480,   480,
     480,   480,   480,    42,   400,   225,   151,   211,    44,   209,
     153,   221,    44,   219,    50,   414,    49,   418,   340,    42,
     277,   502,   440,    41,    51,   102,   454,   460,   532,   449,
      53,   427,   442,   446,    20,    62,   103,   450,   452,   240,
     361,   365,   368,   372,   359,   388,   397,    41,   345,   335,
     392,   350,    42,   475,   382,    42,    49,   402,    49,    42,
      42,    49,    42,    42,   402,   506,    77,    42,    42,    42,
      42,   506,    42,    42,   403,   228,   207,   217,   412,   413,
     416,   420,    37,    42,   457,   459,   460,    51,   461,   532,
     436,   439,   475,   444,   448,   262,   362,   366,   369,   345,
     389,   480,   350,   345,    42,   386,   480,   480,   480,    42,
      56,    42,    42,    42,   227,   229,   386,   417,   341,    42,
     458,   433,   438,   104,   443,    64,   447,   264,   477,   297,
     297,   345,    91,   395,    42,   506,   531,    49,   226,    56,
     149,   150,   334,   456,    50,   432,    49,   437,   445,   451,
     286,   363,   477,   477,   478,    47,   393,    42,   386,   386,
     386,    38,   104,   455,   428,   429,   431,   439,   345,   345,
      23,    42,   394,   460,   430,   330,   345,   417,   262
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  SPARQLParser::yytoken_number_[] =
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
  SPARQLParser::yyr1_[] =
  {
         0,   187,   188,   188,   189,   190,   191,   191,   191,   191,
     192,   193,   194,   194,   195,   195,   196,   196,   198,   197,
     199,   200,   200,   201,   201,   201,   201,   201,   202,   202,
     202,   203,   203,   204,   205,   206,   206,   207,   207,   209,
     208,   210,   211,   212,   212,   212,   213,   213,   214,   215,
     216,   216,   217,   217,   219,   218,   220,   221,   222,   223,
     223,   225,   224,   226,   226,   227,   228,   228,   229,   229,
     229,   230,   232,   233,   231,   235,   234,   236,   236,   238,
     239,   240,   237,   241,   242,   242,   243,   243,   244,   245,
     245,   246,   247,   247,   247,   247,   247,   247,   247,   247,
     248,   248,   249,   249,   250,   251,   251,   252,   253,   253,
     254,   254,   255,   255,   256,   257,   258,   258,   259,   260,
     261,   262,   263,   263,   264,   265,   265,   266,   266,   267,
     267,   268,   268,   269,   270,   270,   271,   271,   271,   271,
     272,   273,   273,   274,   275,   276,   276,   277,   277,   278,
     278,   279,   280,   280,   281,   281,   282,   282,   283,   283,
     284,   285,   286,   287,   288,   288,   289,   290,   291,   291,
     293,   292,   294,   294,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   296,   297,   297,   298,   299,
     299,   300,   301,   302,   303,   304,   305,   307,   306,   309,
     308,   311,   310,   312,   313,   314,   314,   315,   315,   316,
     316,   317,   317,   318,   319,   319,   321,   320,   323,   322,
     324,   325,   325,   326,   326,   327,   327,   328,   329,   329,
     329,   329,   330,   331,   333,   332,   334,   334,   335,   335,
     335,   336,   337,   337,   339,   340,   341,   338,   342,   343,
     344,   344,   345,   345,   346,   346,   346,   348,   347,   349,
     350,   350,   351,   352,   352,   353,   354,   354,   355,   355,
     355,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     356,   357,   359,   358,   361,   362,   363,   360,   365,   366,
     364,   368,   369,   367,   370,   371,   372,   372,   374,   375,
     373,   376,   376,   377,   379,   378,   380,   380,   381,   381,
     382,   382,   384,   383,   383,   385,   385,   386,   386,   386,
     386,   386,   386,   386,   388,   389,   387,   391,   392,   390,
     394,   393,   395,   395,   396,   397,   397,   397,   398,   399,
     400,   399,   401,   401,   402,   403,   403,   404,   405,   404,
     407,   406,   408,   406,   409,   410,   410,   411,   412,   413,
     413,   414,   415,   415,   416,   416,   417,   418,   419,   419,
     420,   422,   421,   423,   421,   424,   425,   425,   427,   426,
     428,   428,   430,   429,   431,   431,   432,   433,   433,   434,
     435,   436,   437,   438,   438,   439,   440,   442,   441,   443,
     444,   444,   446,   445,   447,   448,   448,   449,   450,   450,
     451,   451,   452,   452,   452,   453,   453,   453,   453,   454,
     454,   455,   456,   456,   458,   457,   459,   459,   460,   460,
     460,   461,   461,   462,   462,   464,   463,   465,   466,   466,
     466,   466,   466,   467,   467,   468,   468,   469,   469,   471,
     470,   472,   473,   473,   474,   474,   475,   475,   476,   476,
     477,   477,   478,   478,   479,   479,   479,   479,   479,   479,
     480,   481,   482,   483,   483,   484,   485,   486,   486,   487,
     488,   489,   489,   490,   490,   490,   490,   490,   490,   490,
     490,   491,   492,   493,   493,   494,   494,   495,   495,   496,
     496,   496,   497,   497,   498,   499,   499,   500,   500,   500,
     500,   501,   501,   501,   501,   501,   501,   501,   501,   502,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   504,   504,   505,   506,   506,   507,
     508,   510,   511,   509,   513,   514,   512,   515,   515,   515,
     516,   516,   517,   517,   517,   517,   517,   518,   519,   519,
     520,   521,   521,   522,   523,   524,   524,   525,   525,   526,
     526,   526,   527,   527,   527,   528,   528,   528,   529,   529,
     529,   530,   530,   531,   531,   531,   531,   532,   532,   533,
     533,   534,   534
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SPARQLParser::yyr2_[] =
  {
         0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     3,     0,     1,     0,     2,     0,     2,     0,     3,
       2,     0,     1,     1,     1,     1,     1,     2,     4,     3,
       4,     0,     2,     1,     2,     1,     2,     1,     1,     0,
       3,     2,     1,     4,     3,     4,     0,     2,     1,     2,
       1,     2,     1,     1,     0,     3,     2,     1,     3,     0,
       2,     0,     4,     0,     1,     2,     0,     2,     3,     3,
       3,     2,     0,     0,     5,     0,     5,     0,     2,     0,
       0,     0,     7,     3,     1,     1,     0,     1,     2,     0,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     2,     4,     4,     5,     1,     2,
       1,     1,     0,     1,     4,     2,     1,     1,     1,     2,
       1,     2,     0,     1,     4,     0,     1,     0,     1,     0,
       1,     0,     1,     3,     1,     2,     1,     1,     4,     1,
       2,     1,     2,     1,     3,     1,     2,     1,     1,     1,
       1,     2,     1,     1,     2,     2,     0,     1,     0,     1,
       2,     2,     1,     2,     0,     1,     2,     2,     0,     1,
       0,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     0,     1,     2,     0,
       1,     3,     3,     3,     5,     5,     5,     0,     3,     0,
       3,     0,     3,     6,     2,     0,     1,     0,     1,     2,
       1,     0,     2,     2,     0,     1,     0,     3,     0,     3,
       2,     1,     2,     1,     2,     0,     1,     2,     1,     1,
       1,     1,     3,     3,     0,     3,     0,     1,     0,     1,
       2,     3,     0,     2,     0,     0,     0,     8,     2,     2,
       0,     1,     1,     1,     1,     1,     1,     0,     4,     2,
       0,     1,     3,     0,     2,     2,     2,     3,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     0,     3,     0,     0,     0,     6,     0,     0,
       6,     0,     0,     8,     6,     2,     1,     1,     0,     0,
       6,     0,     2,     1,     0,     5,     0,     2,     1,     3,
       0,     2,     0,     4,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     0,     0,     4,     0,     0,     4,
       0,     3,     0,     2,     2,     1,     1,     1,     2,     1,
       0,     6,     0,     1,     2,     0,     2,     1,     0,     5,
       0,     3,     0,     3,     1,     0,     1,     3,     2,     0,
       1,     2,     0,     2,     1,     1,     2,     2,     0,     2,
       1,     0,     3,     0,     3,     1,     0,     1,     0,     4,
       1,     1,     0,     3,     0,     1,     2,     0,     2,     1,
       1,     2,     2,     0,     2,     1,     1,     0,     3,     2,
       0,     2,     0,     3,     2,     0,     2,     2,     0,     1,
       1,     2,     1,     1,     1,     1,     1,     2,     3,     1,
       3,     2,     0,     2,     0,     3,     0,     1,     1,     1,
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
  const SPARQLParser::yytname_[] =
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
  const SPARQLParser::rhs_number_type
  SPARQLParser::yyrhs_[] =
  {
       188,     0,    -1,   189,    -1,   192,    -1,   190,    -1,   193,
     191,   286,    -1,   234,    -1,   250,    -1,   252,    -1,   256,
      -1,   289,    -1,   194,   195,   196,    -1,    -1,   230,    -1,
      -1,   195,   231,    -1,    -1,   196,   197,    -1,    -1,   200,
     198,   201,    -1,   161,    56,    -1,    -1,   199,    -1,   202,
      -1,   212,    -1,   222,    -1,   261,    -1,    20,   345,    -1,
     204,   205,   203,   211,    -1,   205,   203,    44,    -1,   205,
     203,     1,    44,    -1,    -1,   203,   208,    -1,   151,    -1,
     104,   207,    -1,   210,    -1,   206,   210,    -1,   104,    -1,
     206,    -1,    -1,   104,   209,   207,    -1,   386,   104,    -1,
     151,    -1,   214,   215,   213,   221,    -1,   215,   213,    44,
      -1,   215,   213,     1,    44,    -1,    -1,   213,   218,    -1,
     152,    -1,   154,   217,    -1,   220,    -1,   216,   220,    -1,
     154,    -1,   216,    -1,    -1,   154,   219,   217,    -1,   386,
     154,    -1,   153,    -1,    37,   223,    38,    -1,    -1,   223,
     224,    -1,    -1,    41,   225,   228,    42,    -1,    -1,    49,
      -1,   229,   226,    -1,    -1,   228,   227,    -1,   386,   150,
     386,    -1,   386,   149,   386,    -1,   386,    56,   386,    -1,
      15,   178,    -1,    -1,    -1,    16,   232,   179,   233,   178,
      -1,    -1,   235,   241,   236,   262,   264,    -1,    -1,   236,
     257,    -1,    -1,    -1,    -1,   238,   241,   239,   240,   262,
     264,   286,    -1,    17,   243,   249,    -1,    18,    -1,    19,
      -1,    -1,   242,    -1,    91,   478,    -1,    -1,   244,    -1,
      41,   480,   245,    42,    -1,   503,    -1,   522,    -1,   526,
      -1,   530,    -1,   478,    -1,   515,    -1,   398,    -1,   246,
      -1,   247,    -1,   248,   247,    -1,   248,    -1,    20,    -1,
      21,   251,    -1,   330,   236,   262,   264,    -1,   236,    40,
     330,   264,    -1,    22,   254,   236,   255,   264,    -1,   477,
      -1,   253,   477,    -1,   253,    -1,    20,    -1,    -1,   262,
      -1,    39,   236,   262,   264,    -1,    23,   258,    -1,   259,
      -1,   260,    -1,   261,    -1,    24,   261,    -1,   532,    -1,
     263,   345,    -1,    -1,    40,    -1,   265,   266,   267,   268,
      -1,    -1,   269,    -1,    -1,   272,    -1,    -1,   275,    -1,
      -1,   281,    -1,    92,    26,   270,    -1,   271,    -1,   270,
     271,    -1,   503,    -1,   398,    -1,    41,   480,   245,    42,
      -1,   478,    -1,    93,   273,    -1,   274,    -1,   273,   274,
      -1,   397,    -1,    25,    26,   276,    -1,   277,    -1,   276,
     277,    -1,   279,    -1,   280,    -1,    27,    -1,    28,    -1,
     278,   502,    -1,   397,    -1,   478,    -1,   284,   282,    -1,
     285,   283,    -1,    -1,   285,    -1,    -1,   284,    -1,    29,
     165,    -1,    30,   165,    -1,   288,    -1,    31,   372,    -1,
      -1,   287,    -1,   193,   294,    -1,    50,   289,    -1,    -1,
     290,    -1,    -1,   295,   293,   291,    -1,    -1,   292,    -1,
     296,    -1,   300,    -1,   301,    -1,   303,    -1,   304,    -1,
     305,    -1,   302,    -1,   306,    -1,   308,    -1,   310,    -1,
     312,    -1,     9,   297,   532,   299,    -1,    -1,    13,    -1,
      10,   328,    -1,    -1,   298,    -1,    11,   297,   329,    -1,
      14,   297,   329,    -1,    12,   297,   328,    -1,   116,   297,
     326,   112,   326,    -1,   128,   297,   326,   112,   326,    -1,
     117,   297,   326,   112,   326,    -1,    -1,   130,   307,   331,
      -1,    -1,   131,   309,   331,    -1,    -1,   132,   311,   330,
      -1,   314,   316,   317,   319,    40,   345,    -1,   105,   532,
      -1,    -1,   313,    -1,    -1,   322,    -1,   320,   315,    -1,
     322,    -1,    -1,   317,   324,    -1,    21,   330,    -1,    -1,
     318,    -1,    -1,     3,   321,   330,    -1,    -1,     4,   323,
     330,    -1,   108,   325,    -1,   532,    -1,    24,   532,    -1,
     106,    -1,   327,   532,    -1,    -1,     6,    -1,     6,   532,
      -1,   328,    -1,   106,    -1,    24,    -1,   107,    -1,    37,
     332,    38,    -1,    37,   332,    38,    -1,    -1,   333,   334,
     337,    -1,    -1,   342,    -1,    -1,    44,    -1,     1,    44,
      -1,   338,   335,   334,    -1,    -1,   337,   336,    -1,    -1,
      -1,    -1,   339,     6,   477,   340,    37,   341,   334,    38,
      -1,   406,   344,    -1,    44,   334,    -1,    -1,   343,    -1,
     347,    -1,   161,    -1,   237,    -1,   349,    -1,     1,    -1,
      -1,    37,   348,   346,    38,    -1,   350,   352,    -1,    -1,
     353,    -1,   356,   335,   350,    -1,    -1,   352,   351,    -1,
     421,   355,    -1,    44,   350,    -1,     1,    44,   350,    -1,
      -1,   354,    -1,     1,    -1,   390,    -1,   358,    -1,   387,
      -1,   360,    -1,   364,    -1,   367,    -1,   396,    -1,   370,
      -1,   371,    -1,   357,    -1,   148,   345,    -1,    -1,    45,
     359,   345,    -1,    -1,    -1,    -1,     6,   361,   362,   477,
     363,   345,    -1,    -1,    -1,     7,   365,   366,   297,   477,
     345,    -1,    -1,    -1,     8,   368,   369,   297,   477,    23,
     330,   262,    -1,   125,    41,   480,    91,   478,    42,    -1,
      31,   372,    -1,   373,    -1,   378,    -1,    -1,    -1,   374,
     478,   375,    37,   376,    38,    -1,    -1,   376,   377,    -1,
     386,    -1,    -1,   379,   381,    37,   385,    38,    -1,    -1,
     380,   478,    -1,   186,    -1,    41,   380,    42,    -1,    -1,
     382,   386,    -1,    -1,    41,   384,   382,    42,    -1,   186,
      -1,    -1,   385,   383,    -1,   532,    -1,   522,    -1,   526,
      -1,   530,    -1,    43,    -1,   162,    -1,   478,    -1,    -1,
      -1,    46,   388,   389,   345,    -1,    -1,    -1,   391,   392,
     345,   395,    -1,    -1,    47,   394,   345,    -1,    -1,   395,
     393,    -1,    48,   397,    -1,   502,    -1,   503,    -1,   398,
      -1,   532,   399,    -1,   186,    -1,    -1,    41,   401,   480,
     400,   403,    42,    -1,    -1,    18,    -1,    49,   480,    -1,
      -1,   403,   402,    -1,   186,    -1,    -1,    41,   480,   405,
     403,    42,    -1,    -1,   476,   407,   411,    -1,    -1,   462,
     408,   409,    -1,   410,    -1,    -1,   411,    -1,   416,   417,
     415,    -1,   416,   417,    -1,    -1,   412,    -1,    50,   413,
      -1,    -1,   415,   414,    -1,   477,    -1,    51,    -1,   420,
     419,    -1,    49,   420,    -1,    -1,   419,   418,    -1,   474,
      -1,    -1,   476,   422,   426,    -1,    -1,   469,   423,   424,
      -1,   425,    -1,    -1,   426,    -1,    -1,   428,   427,   436,
     433,    -1,   434,    -1,   435,    -1,    -1,   428,   430,   417,
      -1,    -1,   429,    -1,    50,   431,    -1,    -1,   433,   432,
      -1,   440,    -1,   478,    -1,   439,   438,    -1,    49,   439,
      -1,    -1,   438,   437,    -1,   475,    -1,   441,    -1,    -1,
     445,   442,   444,    -1,   104,   445,    -1,    -1,   444,   443,
      -1,    -1,   451,   446,   448,    -1,    64,   451,    -1,    -1,
     448,   447,    -1,   453,   450,    -1,    -1,   452,    -1,   449,
      -1,   102,   449,    -1,   103,    -1,    20,    -1,    62,    -1,
     532,    -1,    51,    -1,    65,   454,    -1,    41,   440,    42,
      -1,   460,    -1,    41,   459,    42,    -1,   104,   460,    -1,
      -1,   456,   455,    -1,    -1,   460,   458,   456,    -1,    -1,
     457,    -1,   532,    -1,    51,    -1,   102,   461,    -1,   532,
      -1,    51,    -1,   465,    -1,   463,    -1,    -1,    52,   464,
     411,    53,    -1,   467,    41,   468,    42,    -1,    32,    -1,
      33,    -1,    34,    -1,    35,    -1,    36,    -1,    -1,   466,
      -1,   474,    -1,   468,   474,    -1,   472,    -1,   470,    -1,
      -1,    52,   471,   426,    53,    -1,   467,    41,   473,    42,
      -1,   475,    -1,   473,   475,    -1,   476,    -1,   462,    -1,
     476,    -1,   469,    -1,   478,    -1,   479,    -1,   478,    -1,
     532,    -1,   183,    -1,   184,    -1,   532,    -1,   522,    -1,
     526,    -1,   530,    -1,   534,    -1,   186,    -1,   481,    -1,
     484,   483,    -1,    54,   484,    -1,    -1,   483,   482,    -1,
     487,   486,    -1,    55,   487,    -1,    -1,   486,   485,    -1,
     488,    -1,   491,   489,    -1,    -1,   490,    -1,    56,   491,
      -1,    57,   491,    -1,    58,   491,    -1,    59,   491,    -1,
      60,   491,    -1,    61,   491,    -1,    67,   404,    -1,    66,
      67,   404,    -1,   492,    -1,   498,   497,    -1,   528,    -1,
     529,    -1,    20,   500,    -1,    64,   500,    -1,    -1,   494,
      -1,    62,   498,    -1,    63,   498,    -1,   493,   495,    -1,
      -1,   497,   496,    -1,   500,   499,    -1,    -1,   499,   494,
      -1,    65,   501,    -1,    62,   501,    -1,    63,   501,    -1,
     501,    -1,   502,    -1,   503,    -1,   520,    -1,   522,    -1,
     526,    -1,   530,    -1,   478,    -1,   515,    -1,    41,   480,
      42,    -1,    78,    41,   480,    42,    -1,    79,    41,   480,
      42,    -1,    80,    41,   480,    49,   480,    42,    -1,    81,
      41,   480,    42,    -1,    82,    41,   478,    42,    -1,    68,
      41,   480,    42,    -1,    69,    41,   480,    42,    -1,    70,
     504,    -1,   118,   186,    -1,   142,    41,   480,    42,    -1,
     139,    41,   480,    42,    -1,   129,    41,   480,    42,    -1,
     123,    41,   480,    42,    -1,    90,   404,    -1,   507,    -1,
     145,    41,   480,    42,    -1,   508,    -1,   143,    41,   480,
      42,    -1,   141,    41,   480,    42,    -1,   137,    41,   480,
      42,    -1,   126,    41,   480,    49,   480,    42,    -1,   138,
      41,   480,    49,   480,    42,    -1,   144,    41,   480,    49,
     480,    42,    -1,   113,    41,   480,    49,   480,    42,    -1,
     114,    41,   480,    49,   480,    42,    -1,   115,    41,   480,
      42,    -1,   147,    41,   480,    42,    -1,   140,    41,   480,
      42,    -1,   136,    41,   480,    42,    -1,   133,    41,   480,
      42,    -1,   127,    41,   480,    42,    -1,   122,    41,   480,
      42,    -1,   121,    41,   480,    42,    -1,   120,   186,    -1,
     109,   186,    -1,   110,   186,    -1,   111,    41,   480,    42,
      -1,   146,    41,   480,    42,    -1,   135,    41,   480,    42,
      -1,   124,    41,   480,    42,    -1,   119,    41,   480,    42,
      -1,    71,   404,    -1,    72,    41,   480,    49,   480,    49,
     480,    42,    -1,    73,    41,   480,    49,   480,    42,    -1,
      74,    41,   480,    49,   480,    42,    -1,    83,    41,   480,
      49,   480,    42,    -1,    84,    41,   480,    42,    -1,    85,
      41,   480,    42,    -1,    86,    41,   480,    42,    -1,    87,
      41,   480,    42,    -1,   101,    41,   480,    42,    -1,   505,
      -1,   509,    -1,   512,    -1,    41,   480,    42,    -1,   186,
      -1,    88,    41,   480,    49,   480,   506,    42,    -1,    -1,
     402,    -1,   134,    41,   480,    49,   480,   506,    42,    -1,
      75,    41,   480,    49,   480,    49,   480,   506,    42,    -1,
      -1,    -1,    76,   510,   511,   345,    -1,    -1,    -1,    66,
      76,   513,   514,   345,    -1,    94,    41,   401,   516,    42,
      -1,   517,    41,   401,   480,    42,    -1,    99,    41,   401,
     480,   519,    42,    -1,    20,    -1,   480,    -1,    95,    -1,
      96,    -1,    97,    -1,    98,    -1,   100,    -1,    50,    77,
      56,   531,    -1,    -1,   518,    -1,   532,   521,    -1,    -1,
     399,    -1,   531,   525,    -1,    89,   532,    -1,   185,    -1,
     523,    -1,    -1,   524,    -1,   527,    -1,   528,    -1,   529,
      -1,   165,    -1,   166,    -1,   167,    -1,   168,    -1,   169,
      -1,   170,    -1,   171,    -1,   172,    -1,   173,    -1,   163,
      -1,   164,    -1,   174,    -1,   176,    -1,   175,    -1,   177,
      -1,   178,    -1,   533,    -1,   180,    -1,   179,    -1,   181,
      -1,   182,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SPARQLParser::yyprhs_[] =
  {
         0,     0,     3,     5,     7,     9,    13,    15,    17,    19,
      21,    23,    27,    28,    30,    31,    34,    35,    38,    39,
      43,    46,    47,    49,    51,    53,    55,    57,    60,    65,
      69,    74,    75,    78,    80,    83,    85,    88,    90,    92,
      93,    97,   100,   102,   107,   111,   116,   117,   120,   122,
     125,   127,   130,   132,   134,   135,   139,   142,   144,   148,
     149,   152,   153,   158,   159,   161,   164,   165,   168,   172,
     176,   180,   183,   184,   185,   191,   192,   198,   199,   202,
     203,   204,   205,   213,   217,   219,   221,   222,   224,   227,
     228,   230,   235,   237,   239,   241,   243,   245,   247,   249,
     251,   253,   256,   258,   260,   263,   268,   273,   279,   281,
     284,   286,   288,   289,   291,   296,   299,   301,   303,   305,
     308,   310,   313,   314,   316,   321,   322,   324,   325,   327,
     328,   330,   331,   333,   337,   339,   342,   344,   346,   351,
     353,   356,   358,   361,   363,   367,   369,   372,   374,   376,
     378,   380,   383,   385,   387,   390,   393,   394,   396,   397,
     399,   402,   405,   407,   410,   411,   413,   416,   419,   420,
     422,   423,   427,   428,   430,   432,   434,   436,   438,   440,
     442,   444,   446,   448,   450,   452,   457,   458,   460,   463,
     464,   466,   470,   474,   478,   484,   490,   496,   497,   501,
     502,   506,   507,   511,   518,   521,   522,   524,   525,   527,
     530,   532,   533,   536,   539,   540,   542,   543,   547,   548,
     552,   555,   557,   560,   562,   565,   566,   568,   571,   573,
     575,   577,   579,   583,   587,   588,   592,   593,   595,   596,
     598,   601,   605,   606,   609,   610,   611,   612,   621,   624,
     627,   628,   630,   632,   634,   636,   638,   640,   641,   646,
     649,   650,   652,   656,   657,   660,   663,   666,   670,   671,
     673,   675,   677,   679,   681,   683,   685,   687,   689,   691,
     693,   695,   698,   699,   703,   704,   705,   706,   713,   714,
     715,   722,   723,   724,   733,   740,   743,   745,   747,   748,
     749,   756,   757,   760,   762,   763,   769,   770,   773,   775,
     779,   780,   783,   784,   789,   791,   792,   795,   797,   799,
     801,   803,   805,   807,   809,   810,   811,   816,   817,   818,
     823,   824,   828,   829,   832,   835,   837,   839,   841,   844,
     846,   847,   854,   855,   857,   860,   861,   864,   866,   867,
     873,   874,   878,   879,   883,   885,   886,   888,   892,   895,
     896,   898,   901,   902,   905,   907,   909,   912,   915,   916,
     919,   921,   922,   926,   927,   931,   933,   934,   936,   937,
     942,   944,   946,   947,   951,   952,   954,   957,   958,   961,
     963,   965,   968,   971,   972,   975,   977,   979,   980,   984,
     987,   988,   991,   992,   996,   999,  1000,  1003,  1006,  1007,
    1009,  1011,  1014,  1016,  1018,  1020,  1022,  1024,  1027,  1031,
    1033,  1037,  1040,  1041,  1044,  1045,  1049,  1050,  1052,  1054,
    1056,  1059,  1061,  1063,  1065,  1067,  1068,  1073,  1078,  1080,
    1082,  1084,  1086,  1088,  1089,  1091,  1093,  1096,  1098,  1100,
    1101,  1106,  1111,  1113,  1116,  1118,  1120,  1122,  1124,  1126,
    1128,  1130,  1132,  1134,  1136,  1138,  1140,  1142,  1144,  1146,
    1148,  1150,  1153,  1156,  1157,  1160,  1163,  1166,  1167,  1170,
    1172,  1175,  1176,  1178,  1181,  1184,  1187,  1190,  1193,  1196,
    1199,  1203,  1205,  1208,  1210,  1212,  1215,  1218,  1219,  1221,
    1224,  1227,  1230,  1231,  1234,  1237,  1238,  1241,  1244,  1247,
    1250,  1252,  1254,  1256,  1258,  1260,  1262,  1264,  1266,  1268,
    1272,  1277,  1282,  1289,  1294,  1299,  1304,  1309,  1312,  1315,
    1320,  1325,  1330,  1335,  1338,  1340,  1345,  1347,  1352,  1357,
    1362,  1369,  1376,  1383,  1390,  1397,  1402,  1407,  1412,  1417,
    1422,  1427,  1432,  1437,  1440,  1443,  1446,  1451,  1456,  1461,
    1466,  1471,  1474,  1483,  1490,  1497,  1504,  1509,  1514,  1519,
    1524,  1529,  1531,  1533,  1535,  1539,  1541,  1549,  1550,  1552,
    1560,  1570,  1571,  1572,  1577,  1578,  1579,  1585,  1591,  1597,
    1604,  1606,  1608,  1610,  1612,  1614,  1616,  1618,  1623,  1624,
    1626,  1629,  1630,  1632,  1635,  1638,  1640,  1642,  1643,  1645,
    1647,  1649,  1651,  1653,  1655,  1657,  1659,  1661,  1663,  1665,
    1667,  1669,  1671,  1673,  1675,  1677,  1679,  1681,  1683,  1685,
    1687,  1689,  1691
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLParser::yyrline_[] =
  {
         0,   562,   562,   565,   571,   576,   587,   588,   589,   590,
     594,   599,   603,   605,   609,   611,   614,   616,   620,   620,
     637,   643,   646,   650,   653,   656,   659,   662,   671,   672,
     673,   676,   678,   682,   686,   690,   691,   695,   696,   700,
     700,   708,   714,   718,   719,   720,   723,   725,   729,   733,
     737,   738,   742,   743,   747,   747,   755,   761,   765,   768,
     770,   774,   774,   781,   783,   787,   790,   792,   796,   799,
     802,   808,   814,   816,   814,   826,   826,   870,   873,   881,
     884,   888,   881,   907,   919,   922,   929,   932,   937,   944,
     947,   952,   966,   971,   976,   981,   986,   989,   994,  1000,
    1005,  1008,  1016,  1029,  1035,  1041,  1050,  1064,  1073,  1076,
    1084,  1087,  1094,  1097,  1102,  1110,  1117,  1118,  1122,  1128,
    1134,  1141,  1148,  1150,  1155,  1162,  1165,  1170,  1173,  1178,
    1181,  1186,  1190,  1194,  1201,  1204,  1211,  1214,  1217,  1226,
    1232,  1238,  1241,  1248,  1253,  1260,  1264,  1272,  1274,  1282,
    1285,  1293,  1301,  1302,  1309,  1313,  1321,  1324,  1329,  1332,
    1336,  1342,  1348,  1352,  1358,  1361,  1365,  1371,  1374,  1376,
    1380,  1380,  1389,  1391,  1395,  1396,  1397,  1398,  1399,  1400,
    1401,  1402,  1403,  1404,  1405,  1409,  1415,  1418,  1425,  1432,
    1435,  1439,  1445,  1451,  1457,  1463,  1469,  1475,  1475,  1486,
    1486,  1497,  1497,  1508,  1516,  1522,  1525,  1529,  1532,  1536,
    1540,  1547,  1550,  1559,  1565,  1568,  1572,  1572,  1581,  1581,
    1590,  1596,  1600,  1607,  1610,  1615,  1617,  1621,  1627,  1630,
    1633,  1636,  1643,  1650,  1656,  1656,  1664,  1666,  1670,  1672,
    1673,  1677,  1680,  1682,  1687,  1692,  1695,  1687,  1706,  1710,
    1713,  1715,  1719,  1720,  1736,  1737,  1738,  1743,  1743,  1754,
    1758,  1760,  1770,  1774,  1777,  1793,  1798,  1799,  1803,  1806,
    1807,  1811,  1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,
    1822,  1826,  1832,  1832,  1848,  1852,  1854,  1848,  1865,  1869,
    1865,  1878,  1882,  1878,  1899,  1915,  1921,  1922,  1926,  1928,
    1926,  1935,  1937,  1941,  1949,  1949,  1956,  1958,  1964,  1965,
    1968,  1970,  1976,  1976,  1981,  1987,  1989,  1993,  1996,  1999,
    2002,  2005,  2008,  2011,  2017,  2021,  2017,  2031,  2035,  2031,
    2045,  2045,  2057,  2059,  2063,  2073,  2074,  2075,  2079,  2087,
    2091,  2091,  2101,  2104,  2111,  2117,  2119,  2134,  2137,  2137,
    2147,  2147,  2150,  2150,  2156,  2159,  2161,  2166,  2171,  2175,
    2177,  2182,  2186,  2188,  2192,  2196,  2204,  2209,  2213,  2215,
    2219,  2227,  2227,  2230,  2230,  2236,  2239,  2241,  2245,  2245,
    2251,  2252,  2256,  2256,  2261,  2263,  2267,  2270,  2272,  2276,
    2285,  2291,  2295,  2298,  2300,  2304,  2311,  2315,  2315,  2325,
    2331,  2334,  2340,  2340,  2350,  2356,  2359,  2365,  2371,  2374,
    2378,  2379,  2385,  2388,  2391,  2397,  2400,  2403,  2406,  2415,
    2416,  2425,  2431,  2434,  2440,  2440,  2450,  2453,  2457,  2460,
    2463,  2469,  2472,  2480,  2481,  2485,  2485,  2498,  2526,  2529,
    2532,  2535,  2538,  2545,  2548,  2553,  2557,  2564,  2565,  2569,
    2569,  2581,  2608,  2612,  2619,  2620,  2624,  2625,  2629,  2632,
    2636,  2639,  2645,  2646,  2650,  2653,  2656,  2659,  2662,  2663,
    2669,  2674,  2683,  2690,  2693,  2701,  2710,  2717,  2720,  2727,
    2732,  2745,  2749,  2753,  2757,  2761,  2765,  2769,  2773,  2777,
    2781,  2788,  2793,  2802,  2805,  2812,  2815,  2822,  2825,  2830,
    2833,  2837,  2851,  2854,  2862,  2871,  2874,  2881,  2884,  2887,
    2890,  2894,  2895,  2896,  2897,  2900,  2903,  2906,  2909,  2913,
    2925,  2928,  2931,  2934,  2937,  2940,  2943,  2947,  2950,  2953,
    2956,  2959,  2962,  2965,  2968,  2969,  2972,  2973,  2976,  2979,
    2982,  2985,  2988,  2991,  2994,  2997,  3000,  3003,  3006,  3009,
    3012,  3015,  3018,  3021,  3024,  3027,  3030,  3033,  3036,  3039,
    3042,  3045,  3048,  3051,  3054,  3057,  3060,  3063,  3066,  3069,
    3072,  3075,  3076,  3077,  3083,  3092,  3099,  3106,  3109,  3113,
    3119,  3125,  3128,  3125,  3140,  3143,  3140,  3156,  3164,  3173,
    3189,  3192,  3196,  3199,  3202,  3205,  3208,  3214,  3220,  3223,
    3227,  3237,  3240,  3245,  3253,  3260,  3264,  3272,  3276,  3280,
    3281,  3282,  3286,  3287,  3288,  3292,  3293,  3294,  3298,  3299,
    3300,  3304,  3305,  3309,  3310,  3311,  3312,  3316,  3317,  3321,
    3322,  3326,  3360
  };

  // Print the state stack on the debug stream.
  void
  SPARQLParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  SPARQLParser::yy_reduce_print_ (int yyrule)
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
  SPARQLParser::token_number_type
  SPARQLParser::yytranslate_ (int t)
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

  const int SPARQLParser::yyeof_ = 0;
  const int SPARQLParser::yylast_ = 2937;
  const int SPARQLParser::yynnts_ = 348;
  const int SPARQLParser::yyempty_ = -2;
  const int SPARQLParser::yyfinal_ = 11;
  const int SPARQLParser::yyterror_ = 1;
  const int SPARQLParser::yyerrcode_ = 256;
  const int SPARQLParser::yyntokens_ = 187;

  const unsigned int SPARQLParser::yyuser_token_number_max_ = 441;
  const SPARQLParser::token_number_type SPARQLParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 6385 "C:\\Users\\Jelle\\Documents\\GitHub\\SWObjects\\lib\\SPARQLParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 3366 "..\\..\\lib\\SPARQLParser.ypp"
 /*** Additional Code ***/

void w3c_sw::SPARQLParser::error(const SPARQLParser::location_type& l,
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

size_t SPARQLDriver::DefaultAbortErrorCount = 100;

    SPARQLDriver::e_Validation SPARQLDriver::DefaultValidation = SPARQLDriver::VALIDATE_all;

Operation* SPARQLDriver::parse (IStreamContext& in)
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

    SPARQLScanner scanner(this, in.p);
    scanner.set_debug(trace_scanning);
    lexer = &scanner;

    SPARQLParser parser(*this);
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

Operation* SPARQLDriver::parse (std::string queryStr)
{
    IStreamContext in(queryStr.c_str(), IStreamContext::STRING);
    return parse(in);
}

void SPARQLDriver::executeSelect (IStreamContext& in, RdfDB* db, ResultSet* rs) {
    parse(in);
    root->execute(db, rs);
    delete root;
    root = NULL;
}
void SPARQLDriver::executeSelect (std::string queryStr, RdfDB* db, ResultSet* rs) {
    parse(queryStr);
    root->execute(db, rs);
    delete root;
    root = NULL;
}


} // namespace w3c_sw

/* END Driver */


