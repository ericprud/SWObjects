
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
#line 43 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


#include "SPARQLfedParser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 313 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 466 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lexWrapper


/* Line 317 of lalr1.cc  */
#line 68 "lib/SPARQLfedParser/SPARQLfedParser.cpp"

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
#line 137 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
#if YYERROR_VERBOSE

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

#endif

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
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 553 of lalr1.cc  */
#line 37 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 321 "lib/SPARQLfedParser/SPARQLfedParser.cpp"

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
#line 480 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 483 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 494 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	assert(driver.lastWhereClause != NULL);
	if ((yysemantic_stack_[(3) - (3)].p_BindingClause) != NULL) // got a bindings clause
	    driver.lastWhereClause->m_GroupGraphPattern = 
		driver.makeConjunction((yysemantic_stack_[(3) - (3)].p_BindingClause), driver.lastWhereClause->m_GroupGraphPattern);
	(yyval.p_Operation) = (yysemantic_stack_[(3) - (2)].p_Operation);
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 513 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 542 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.startBindingSet();
      }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 545 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

/* Line 678 of lalr1.cc  */
#line 560 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = (yysemantic_stack_[(2) - (1)].p_RSName);
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 566 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = NULL;
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 607 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 609 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 615 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 653 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 655 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 661 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 680 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow(false);
      }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 682 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 702 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 705 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 708 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 714 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 720 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 722 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 724 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 732 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 735 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause);
	(yyval.p_Operation) = new Select((yysemantic_stack_[(5) - (2)].p_Project).distinctness, (yysemantic_stack_[(5) - (2)].p_Project).varSet, (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
	driver.countStar = (yysemantic_stack_[(5) - (1)].p_parentCountStar);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 744 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 747 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 755 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 758 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 761 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 765 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if ((yysemantic_stack_[(7) - (7)].p_BindingClause) != NULL)
	      (yysemantic_stack_[(7) - (5)].p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yysemantic_stack_[(7) - (7)].p_BindingClause), (yysemantic_stack_[(7) - (5)].p_WhereClause)->m_GroupGraphPattern);
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (4)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(7) - (3)].p_Project).distinctness, (yysemantic_stack_[(7) - (3)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(7) - (5)].p_WhereClause), (yysemantic_stack_[(7) - (6)].p_SolutionModifier))));
	  driver.curGraphName = (yysemantic_stack_[(7) - (2)].p_TTerm);
	  driver.countStar = (yysemantic_stack_[(7) - (1)].p_parentCountStar);
      }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 776 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 784 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 787 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 794 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 802 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 809 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 817 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 824 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 827 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 830 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 833 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 836 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 839 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 842 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 851 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 854 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 862 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 865 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 872 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = NULL;
      }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 874 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.lastWhereClause = (yysemantic_stack_[(6) - (5)].p_WhereClause);
	  /* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	  (yyval.p_Operation) = new Construct((DefaultGraphPattern*)((yysemantic_stack_[(6) - (2)].p_BasicGraphPattern) ? (yysemantic_stack_[(6) - (2)].p_BasicGraphPattern) : new DefaultGraphPattern()), (yysemantic_stack_[(6) - (4)].p_DatasetClauses), (yysemantic_stack_[(6) - (5)].p_WhereClause), (yysemantic_stack_[(6) - (6)].p_SolutionModifier));
      }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 883 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause) ? (yysemantic_stack_[(5) - (4)].p_WhereClause) : new WhereClause(new DefaultGraphPattern());
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 891 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm))));
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 894 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_TTerm))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 902 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 905 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 912 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 920 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(3) - (3)].p_WhereClause);
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(3) - (2)].p_DatasetClauses), (yysemantic_stack_[(3) - (3)].p_WhereClause));
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 928 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 940 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 946 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 952 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 959 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.ensureGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 973 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 980 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 988 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 996 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1004 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1012 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1019 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1022 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1029 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1032 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1035 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1038 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1044 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1050 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1053 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1065 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1072 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1076 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1086 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1094 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1097 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1105 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1114 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1121 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1125 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1133 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1141 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1148 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1154 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1161 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1163 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1171 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 1177 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 1180 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 1186 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow(); // @@ push down to _Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star?
      }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1188 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1191 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1203 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1206 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 1209 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 1212 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 1215 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1218 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 1221 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 1231 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	OperationSet* ret = driver.root ? dynamic_cast<OperationSet*>(driver.root) : new OperationSet();
	ret->push_back((yysemantic_stack_[(2) - (2)].p_Operation));
	driver.root = ret;
      }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 1235 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Operation) = driver.root;
	}
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1269 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(3) - (2)].p_URI), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1276 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1283 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 1290 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 1296 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 1299 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 1305 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 1311 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 1317 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 1323 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 1329 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 1335 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert(driver.ensureGraphPattern(), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 1343 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete(driver.ensureGraphPattern(), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 1351 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete(driver.ensureGraphPattern(), NULL);
	driver.curOp = NULL;
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 1359 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(5) - (1)].p_URI))
	    w3c_sw_NEED_IMPL("WITH <URI> (DELETE INSERT?|INSERT) ...");
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(5) - (2)].p_DeleteInsert).del, (yysemantic_stack_[(5) - (2)].p_DeleteInsert).ins, new WhereClause(driver.ensureGraphPattern()));
	driver.curOp = NULL;
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 1368 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 1374 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 1381 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 1388 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 1392 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 1400 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("_QUsingClause_E_Star");
    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 1406 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Delete) = new Delete(driver.ensureGraphPattern(), NULL);
	driver.curOp = NULL;
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 1413 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = new Insert(driver.ensureGraphPattern(), NULL);
	driver.curOp = NULL;
    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 1420 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 1426 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 1429 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 1435 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 1438 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 1449 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 1455 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 1458 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("DEFAULT");
      }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 1461 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("NAMED");
      }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 1464 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("ALL");
      }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 1504 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 1509 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 1512 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 1515 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 1537 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 256:

/* Line 678 of lalr1.cc  */
#line 1556 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 1558 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 1629 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_BindingClause)) : (yysemantic_stack_[(1) - (1)].p_BindingClause);
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 1636 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Print(driver.curOp);
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 1642 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 1646 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 280:

/* Line 678 of lalr1.cc  */
#line 1658 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 1662 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 1664 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 1667 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 1675 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 1679 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 1681 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 1684 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(7) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(7) - (6)].p_TTerm), driver.curOp, (yysemantic_stack_[(7) - (5)].p_Silence), driver.atomFactory, false));
	  driver.curGraphName = (yysemantic_stack_[(7) - (4)].p_TTerm);
      }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 1692 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Bind(driver.ensureGraphPattern(), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
	// no more triples go into the current BGP, per
	//   http://www.w3.org/TR/sparql11-query/#sparqlTranslateGraphPatterns
	// test reference:
	//   http://www.sparql.org/query-validator?query=ASK+{+%3Fs+%3Fp+%3Fo+FILTER+%281%29+BIND+%282+AS+%3Fb%29+%3Fs2+%3Fp2+%3Fo2+FILTER+%283%29+BIND+%284+AS+%3Fd%29}&languageSyntax=SPARQL&outputFormat=algebra&linenumbers=false
	driver.curBGP = NULL;
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 1703 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 1707 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 1709 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 1717 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 1721 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 1723 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 1731 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 1736 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.ensureGraphPattern());
      }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 1749 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    driver.ensureGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 1765 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 1773 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 1777 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 1780 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yysemantic_stack_[(6) - (4)].p_Expressions);
      }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 1787 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 1790 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 1797 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 1805 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 1819 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 1822 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 1825 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(5) - (3)].p_Expressions);
      }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 1833 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 1835 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 1863 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 1866 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 1926 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 1933 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 1937 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 1945 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 1948 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 1954 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 1965 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 1993 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 2020 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 2027 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 2038 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 2045 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 2081 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 2084 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 2087 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 2090 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 2148 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 2152 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 2161 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 413:

/* Line 678 of lalr1.cc  */
#line 2186 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 2189 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 2192 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 2195 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 2198 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 2205 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 2213 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 2217 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 2229 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 2236 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 2239 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 2250 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 2253 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 2256 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 2259 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 2263 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 2274 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 2283 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 2290 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 2293 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 2301 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 2310 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 2317 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 2320 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 2332 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_GeneralComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_GeneralComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_GeneralComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 2343 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 2350 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 2353 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 2356 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 2359 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 2362 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 2365 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 2368 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 2371 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 2382 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 2391 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 2394 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 2401 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 2404 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 2411 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 2419 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 2422 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 2426 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 468:

/* Line 678 of lalr1.cc  */
#line 2440 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 2443 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 2451 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 2460 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 2463 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 2470 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 2473 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 2476 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 2486 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 2489 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 2492 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 2495 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 2502 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 2508 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 2511 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 2514 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 2517 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 2520 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 2523 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 2526 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 2530 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 2533 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 2536 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 2539 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ciel, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 2542 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 2545 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 2548 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 2552 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 2555 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 2558 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 2561 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 2564 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 2567 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 2570 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 2573 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 2576 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 2579 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 2582 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 2585 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 2588 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 2591 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 2594 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 2597 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 2600 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 2603 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha224, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 2606 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 2609 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 2612 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 2615 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 2619 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 2622 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 2625 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 2628 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 2631 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 2634 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 2637 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 2640 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 2643 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 2654 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 2657 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 2664 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 2671 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 2678 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 2684 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.ensureGraphPattern(), NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 2691 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.ensureGraphPattern(), NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 2698 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 2701 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 2705 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 2708 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  // x = new ArgList($2, driver.curExprList);
	  delete driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(7) - (5)].p_Expressions);
	  w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // $$ = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group-concat, $3, $4.p_Expression, $4.separator));
    }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 2718 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
	driver.countStar = true;
    }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 2726 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 2729 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 2732 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 2735 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 2738 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 2744 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 2750 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 2757 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 2767 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 2775 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 2783 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 2790 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 2794 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 2802 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 3610 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  SPARQLfedParser::yysyntax_error_ (int yystate, int tok)
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
  const short int SPARQLfedParser::yypact_ninf_ = -829;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        45,  -122,    79,  -829,  -829,   753,  -829,  -829,  -829,  -829,
    -829,  -829,   129,   108,   108,   108,   101,     4,  -829,   129,
     108,   108,   117,   140,   108,   140,   114,  -829,   132,  -829,
    -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,
    -829,  -829,  -829,  -829,  -829,    96,   141,  -829,  -829,  -829,
     173,  -829,  -829,   100,   189,   100,  -829,  -829,  -829,  -829,
    -829,   120,  -829,  -829,  -829,  -829,    52,  -829,    37,    37,
    1040,  -829,  1040,  -829,    37,  -829,  -829,  -829,  -829,   227,
    -829,   159,   117,   117,  -829,   213,  -829,  -829,   116,  -829,
     189,  -829,  -829,   129,  -829,  -829,  -829,  -829,  -829,  -829,
    -829,  1040,  -829,  -829,    76,    -2,  -829,  -829,  -829,     8,
    -829,  -829,   115,   129,   124,  -829,  -829,  -829,  -829,  -829,
    -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,
    -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,   199,
    -829,  -829,   205,  -829,  -829,  -829,  -829,   211,  -829,  -829,
    -829,  -829,  -829,  -829,  -829,  -829,  -829,   -41,  -829,  -829,
     218,   156,  -829,  -829,  -829,  -829,  1516,    52,   111,  -829,
    -829,  -829,  -829,    12,  -829,  -829,    87,   214,  -829,  -829,
    -829,  -829,  -829,   235,  -829,   243,    52,   202,  -829,   129,
    -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,    37,
    -829,    37,    55,  -829,   272,  1040,  -829,  -829,    55,  1691,
      55,   129,  -829,  -829,  -829,  -829,  -829,    37,     9,  -829,
    1832,   242,   261,   283,   -18,   -16,   285,   287,   289,     8,
     303,   307,   311,   312,   323,   325,   327,   329,   330,   331,
     334,   -16,   336,  -829,  -829,  -829,  -829,   337,  -829,   339,
     341,   342,   201,   345,   204,   347,   348,   349,   351,   352,
     354,   356,   364,   365,   366,   367,   368,   371,   373,   374,
     377,   379,   380,   381,   382,   383,   385,  -829,  -829,  1948,
    -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,   386,
    -829,  -829,  -829,    -1,   202,   239,  -829,  -829,     8,    11,
    -829,  -829,  -829,   179,  -829,  1040,  -829,  -829,   202,   402,
    -829,   344,  -829,  -829,  1016,  -829,  -829,  -829,   384,  1691,
    -829,  -829,   389,   427,  -829,  -829,  -829,  -829,  -829,  1065,
    -829,  -829,  -829,  -829,  -829,  -829,  -829,  1832,  2064,  2064,
    2064,  -829,   360,  -829,  -829,  -829,  -829,   279,  -829,  -829,
    -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,    -1,
       8,  1832,  1832,  1832,  -829,  -829,  1832,  -829,  -829,  1832,
    1832,  1832,  -829,  1832,  1832,  1832,  1832,   118,  1832,  1832,
    1832,  1832,  1832,  1832,  -829,   420,   420,  1832,  1832,  1832,
    -829,  1832,  -829,  1832,  1832,  1832,  1832,  1832,  1832,  1832,
    1832,  1832,  1832,  1832,  1832,  1832,  1832,  1832,  1832,  1832,
    1832,  1832,  1832,  1832,  1832,  -829,   420,   420,  -829,  -829,
    -829,  -829,   129,  -829,  -829,   264,  -829,  1179,  -829,  -829,
    1656,  -829,  -829,   338,  -829,  -829,   292,  -829,  -829,  -829,
    -829,  2180,  2302,   419,  -829,  -829,  -829,   408,  -829,  -829,
    -829,   407,  -829,  -829,  -829,  -829,  -829,  -829,  -829,  1040,
     120,  -829,  -829,   -11,   410,  -829,  -829,  -829,   118,  -829,
     411,   400,   401,  1832,  1832,  1832,  1832,  1832,  1832,   388,
     -16,  -829,  -829,   192,    51,  -829,  -829,  -829,   415,   416,
     417,  -829,   414,   418,   422,   423,   424,   425,   430,   431,
     426,   434,   435,   437,   438,   432,  -829,  1352,  1832,   440,
     441,   442,   443,   444,   446,   448,   447,   449,   451,   453,
     450,   455,   456,   458,   452,   460,   462,   463,   464,   465,
     467,   466,   472,   474,   475,  1832,  1832,  -829,  -829,   154,
    -829,  -829,  -829,  1399,  -829,  -829,   357,  -829,  -829,  -829,
    -829,  -829,  -829,  1399,  -829,  -829,   314,  -829,     5,  -829,
      20,  1832,  2180,  -829,  -829,  -829,  -829,  2302,  -829,  -829,
    -829,  -829,  -829,   493,   262,  -829,   132,  -829,    50,  1040,
    -829,  -829,    55,    46,   470,   476,  -829,  -829,  -829,  -829,
    -829,  -829,  -829,  -829,  -829,  1832,  -829,  1832,  -829,  -829,
    -829,  -829,  -829,  -829,  -829,   -16,  -829,  1832,  1832,    51,
    -829,  -829,  -829,  1832,  1832,  -829,  -829,  -829,  -829,  -829,
    1832,  1832,  1832,  -829,  -829,  1832,  -829,  -829,  1832,  -829,
    -829,  -829,  -829,  1832,  -829,  -829,   481,  -829,  -829,  -829,
    -829,  -829,  -829,  -829,  -829,  1832,  -829,  -829,  -829,  1832,
    -829,  -829,  -829,  1832,  -829,  -829,  -829,  -829,  -829,  -829,
    1832,  -829,  -829,  -829,   482,  -829,  -829,  -829,  -829,  -829,
    -829,  -829,  -829,   -37,  -829,  -829,  -829,   161,  -829,  -829,
    -829,   360,  -829,  -829,  1632,   369,   372,  -829,  -829,   439,
     497,  -829,  -829,  -829,  -829,  -829,  2302,   487,     8,  -829,
    -829,   389,  -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,
    -829,  -829,  -829,  -829,    63,  -829,    38,    26,  -829,  -829,
    -829,  -829,  -829,  -829,  -829,  -829,  -829,    31,  -829,  -829,
    -829,    55,  -829,  1691,  -829,   492,  1399,  -829,  -829,  -829,
    -829,  -829,  -829,  -829,  -829,  -829,    34,   484,   488,   494,
     496,   498,   486,  -829,   491,   501,   486,   502,   504,  -829,
    -829,  -829,  -829,  -829,  1179,  -829,  -829,  1656,   505,  -829,
    -829,  1632,  -829,   507,  -829,  -829,  -829,  -829,  -829,  -829,
    -829,  -829,  -829,  -829,   509,  -829,  -829,     8,  -829,  -829,
    1832,  -829,  1040,     8,   510,   157,  -829,    66,  -829,  -829,
    -829,  -829,  -829,  -829,  1691,   457,   489,  -829,     7,  -829,
    -829,  -829,  -829,  -829,  -829,  -829,  1691,  -829,  -829,  1619,
    -829,  -829,  1832,  -829,  1832,  -829,  -829,  -829,  -829,  -829,
     512,   483,  -829,   519,  -829,   520,  -829,  -829,    88,  2165,
    -829,  -829,  -829,  -829,  -829,   202,   120,  -829,  -829,     8,
     473,  -829,  -829,  -829,  -829,   523,  -829,  -829,  -829,  -829,
    -829,    63,  -829,    63,  -829,   404,  -829,  -829,    24,  -829,
    1040,  -829,  -829,  -829,   528,  -829,   518,  -829,  -829,  -829,
    -829,  -829,   526,   -22,   114,  -829,   108,  -829,   118,   529,
    -829,   477,   527,  -829,  -829,   540,  -829,    -6,  -829,   541,
    -829,   112,  -829,  -829,  1399,  1399,  1399,  -829,     8,   120,
     544,  -829,  -829,   157,  -829,    46,  -829,  -829,  -829,  -829,
     545,  -829,  -829,  -829,  -829,  -829,  -829,     8,  -829,     8,
    -829,  -829,  -829,  -829,  -829,  -829,  -829,  1691,  -829
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        13,     0,     0,     2,     4,   212,    15,    14,     3,   176,
      68,     1,     0,   200,   200,   200,     0,     0,    74,     0,
     200,   200,     0,     0,   200,     0,    10,     6,     0,     7,
       8,     9,   177,   184,   185,   186,   190,   187,   188,   189,
     191,   192,   193,   194,   213,     0,    17,   584,   587,   586,
     197,   585,   201,     0,     0,     0,   315,   101,   107,   428,
     429,   106,    74,   104,   426,   427,   118,   211,   227,   227,
     237,   209,   237,   208,   227,   207,   158,     5,    11,    83,
      74,   182,     0,     0,   218,   214,   217,    69,    12,    16,
       0,   198,   195,     0,   232,   231,   233,   230,   199,   203,
     202,   317,    74,   105,   108,     0,   119,    75,   110,     0,
     228,   225,     0,     0,     0,   413,   414,   415,   416,   417,
     410,   578,   579,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   580,   582,   581,   583,   588,   589,   435,     0,
     242,   238,   250,   325,   409,   408,   419,     0,   323,   424,
     425,   431,   432,   566,   567,   568,   433,   564,   430,   434,
       0,     0,   160,    81,    82,    84,     0,   118,    13,   183,
     178,   220,   221,     0,   216,   215,     0,     0,    18,    23,
      19,   196,   229,     0,   318,   321,   118,   121,   109,     0,
     111,   112,   113,   114,   116,   256,   253,   117,   252,   227,
     226,   227,     0,   234,   236,   237,   251,   248,   335,   418,
       0,     0,   562,   563,   565,   560,   235,   227,     0,   100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   549,   550,   551,   552,     0,   553,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    99,
      80,    92,    89,    91,   532,   500,   533,   534,    90,     0,
      93,    94,    95,     0,   121,   212,   180,   181,     0,     0,
     219,    70,    21,     0,   316,   317,   322,   319,   121,     0,
     103,   123,   122,   115,   259,   204,   206,   343,     0,   418,
     342,   243,   239,     0,   249,   336,   326,   334,   423,   418,
     420,   422,   324,   561,   205,   167,   161,     0,     0,     0,
       0,   483,    86,   436,   439,   443,   445,   447,   457,   468,
     471,   476,   477,   478,   484,   479,   480,   481,   482,   558,
       0,     0,     0,     0,   536,   493,     0,   312,   522,     0,
       0,     0,   541,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   499,   307,   307,     0,     0,     0,
     494,     0,   515,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,   307,   307,   304,   303,
      73,   210,     0,   222,   223,     0,    56,     0,    31,    45,
       0,    20,    24,     0,    29,    25,     0,    43,    26,   320,
     102,     0,     0,   125,   124,   254,    77,     0,   255,   262,
     260,   266,   346,   344,   411,   332,   339,   341,   240,   237,
       0,   412,   421,     0,     0,   474,   475,   473,     0,    87,
       0,   437,   441,     0,     0,     0,     0,     0,     0,     0,
       0,   446,   448,   458,   470,   559,   557,   542,     0,     0,
       0,   313,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   308,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   224,    71,     0,
     173,    35,   174,    36,    32,    33,     0,   175,   170,   171,
     172,   169,    49,    50,    46,    47,     0,    29,     0,    43,
       0,     0,   129,   130,   133,   135,   132,   136,   137,   139,
     302,   300,   301,     0,   127,   126,     0,   257,   292,   259,
     267,   264,   335,     0,   327,   337,   241,   245,   159,   164,
     166,   168,   485,    85,    88,     0,   440,     0,   444,   449,
     450,   451,   452,   453,   454,     0,   455,     0,     0,   463,
     469,   459,   460,     0,     0,   472,   491,   492,   535,   310,
       0,     0,     0,   486,   487,     0,   489,   490,     0,   527,
     528,   529,   530,     0,   547,   548,     0,   545,   531,   516,
     508,   521,   514,   498,   520,     0,   513,   497,   512,     0,
     519,   511,   504,     0,   496,   510,   503,   495,   502,   518,
       0,   501,   517,   509,     0,   305,    55,    58,    57,    34,
      39,    48,    53,     0,    28,    37,    30,     0,    42,    51,
      44,    86,   131,   138,     0,     0,     0,   120,   128,   152,
     154,    78,   280,   284,   278,   289,     0,     0,     0,   275,
     263,   239,   276,   269,   271,   272,   274,   270,   268,   293,
     273,   265,   359,   347,     0,   389,     0,     0,   345,   348,
     350,   351,   360,   362,   365,   374,   369,   372,   387,   361,
     388,   329,   333,   418,   340,     0,     0,   438,   442,   456,
     465,   466,   464,   467,   461,   462,     0,     0,     0,     0,
       0,     0,   538,   543,   555,     0,   538,     0,     0,   544,
     310,    63,    40,    27,     0,    54,    41,     0,     0,   145,
     146,   140,   141,     0,   143,   144,   148,   149,   156,   157,
     150,   153,   151,   155,   118,   281,   285,     0,   290,   299,
       0,   277,   259,     0,     0,   397,   405,     0,   390,   392,
     399,   401,   404,   375,   418,   363,   367,   383,     0,   385,
     384,   371,   373,   376,   330,   331,   418,   338,   246,     0,
     162,   314,     0,   311,     0,   524,   525,   488,   526,   539,
       0,     0,   556,     0,   505,     0,   506,   507,     0,     0,
      38,    52,   134,   142,   147,   121,     0,   286,   279,     0,
       0,   261,   297,   391,   398,     0,   394,   403,   406,   402,
     357,     0,   366,     0,   370,     0,   407,   386,     0,   328,
     237,   165,   163,   309,     0,   537,     0,   546,   540,   306,
      59,    64,    60,     0,    10,   282,   200,   291,     0,   294,
     400,   396,   349,   364,   368,     0,   380,     0,   381,     0,
     523,     0,    61,    62,     0,     0,     0,    79,     0,     0,
       0,   295,   298,     0,   395,   354,   358,   382,   377,   379,
       0,   247,   554,    67,    66,    65,   283,     0,   288,     0,
     393,   352,   355,   356,   378,   287,   296,   418,   353
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -829,  -829,  -829,  -829,  -829,  -303,   421,  -829,  -829,  -829,
    -829,  -829,  -829,  -829,  -829,  -829,    29,  -829,   155,  -829,
    -177,  -829,  -829,    47,  -829,  -829,    32,  -829,   158,  -829,
    -175,  -829,  -829,    40,  -829,  -829,  -829,  -829,  -829,  -829,
    -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,   166,
    -829,  -829,  -829,  -829,    19,  -829,  -829,  -829,   -85,  -829,
     319,  -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,
    -829,  -829,  -829,  -829,   412,  -103,  -829,  -288,  -829,  -829,
    -829,  -829,  -829,  -829,    41,  -829,  -829,    33,  -829,  -829,
    -172,  -829,  -829,  -829,  -829,  -829,  -829,   -88,   -84,    28,
    -829,  -829,  -829,  -829,  -829,  -829,  -395,  -829,   445,  -829,
    -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,    -5,  -829,
    -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,
    -829,  -829,  -829,  -829,   522,  -829,  -829,   -42,  -829,    14,
     555,   229,   586,   547,  -203,   -79,  -829,  -829,  -829,  -829,
    -829,  -829,  -829,  -829,  -829,  -221,  -829,  -829,  -829,  -829,
    -568,  -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,
    -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,
    -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,  -829,  -643,
    -153,   253,  -829,  -332,  -609,  -144,  -237,  -829,  -829,  -829,
     318,  -829,  -829,  -829,   -89,  -829,  -829,   -93,  -829,  -829,
    -829,  -829,  -829,    35,  -776,  -829,  -829,  -109,  -106,  -829,
    -829,  -829,  -829,  -829,  -286,  -829,  -829,  -829,  -829,  -829,
    -829,  -829,  -829,   -87,  -829,  -829,  -829,  -235,  -829,  -829,
     -86,  -829,  -233,  -829,  -829,  -829,  -829,  -829,  -829,  -829,
    -829,  -829,  -829,  -829,  -829,  -829,  -753,  -829,  -829,  -828,
    -195,  -829,  -829,  -829,  -829,  -829,  -829,  -179,  -184,   -14,
       1,  -829,   758,  -829,  -829,  -829,    43,  -829,  -829,    36,
    -829,  -829,  -829,   -75,  -829,  -829,    27,  -829,  -829,  -829,
    -289,  -829,  -292,   -64,  -425,  -128,  -829,  -829,  -121,  -829,
    -829,  -829,  -130,  -829,  -829,  -829,  -829,  -829,  -829,  -829,
      61,  -829,  -829,  -829,   188,  -829,   162,   163,   207,  -262,
     -12,  -829,  -829
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,    26,    77,     5,     6,    46,    88,
     178,   303,   179,   180,   431,   432,   558,   433,   434,   543,
     544,   676,   764,   545,   763,   435,   560,   436,   437,   553,
     554,   680,   767,   555,   766,   438,   539,   668,   761,   903,
     881,   839,   882,     7,    89,   176,   425,    27,    28,    66,
     445,   446,   576,   784,    80,   165,   166,   469,   470,   277,
     278,   279,   280,    29,   102,    30,    61,    62,   187,    31,
     107,   190,   191,   192,   193,   108,   109,   310,   311,   443,
     574,   687,   312,   562,   563,   444,   567,   568,   575,   771,
     772,   773,   774,   775,   688,   780,   782,   689,   690,    78,
     162,   218,   819,   591,   736,   463,   546,     8,     9,    81,
     297,   169,   170,    32,    33,    91,    92,    34,    53,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
     174,    84,   173,    85,    86,   300,   423,   112,   113,    97,
      98,    71,    73,   139,   140,   459,   321,   204,   322,   323,
     735,   870,   141,   206,   207,   197,   447,   198,   314,   448,
     449,   700,   578,   450,   580,   581,   701,   702,   703,   787,
     704,   785,   846,   908,   705,   786,   847,   886,   706,   707,
     788,   849,   708,   709,   793,   912,   929,   889,   710,   569,
     570,   419,   760,   507,   823,   746,   368,   619,    57,   101,
     183,   184,   306,   307,   142,   210,   208,   325,   814,   815,
     732,   584,   326,   327,   455,   734,   585,   456,   319,   451,
     583,   582,   718,   804,   719,   932,   937,   933,   916,   892,
     713,   720,   721,   722,   723,   862,   805,   724,   864,   806,
     725,   811,   726,   812,   919,   898,   867,   813,   727,   728,
     798,   914,   891,   854,   855,   799,   800,   858,   801,   868,
     143,   144,   202,   145,   146,   147,   329,   457,   148,   320,
     341,   150,   342,   343,   596,   471,   344,   598,   472,   345,
     346,   481,   482,   347,   348,   609,   615,   743,   610,   483,
     349,   484,   350,   351,   352,   353,   365,   284,   830,   285,
     286,   287,   354,   754,   636,   289,   832,   833,   355,   486,
     356,   213,   214,   215,   357,   153,   154,   155,   358,   157,
     359,    51,   159
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SPARQLfedParser::yytable_ninf_ = -419;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        50,   188,   324,    63,   384,    65,   420,    67,   372,    54,
      55,   711,   185,   281,   328,    68,    69,   571,    64,    74,
     440,   189,   363,    58,   366,   331,   588,   114,   860,   589,
     330,   918,   161,   904,   422,   556,   288,   895,   283,   417,
     869,   776,   856,   110,   195,   335,   211,   103,   674,    65,
     807,   298,    10,   789,   508,   865,   692,   693,   158,     1,
     158,   896,    64,   678,   294,   675,   714,   808,    99,   920,
     613,   149,   897,   149,   105,   821,   715,   421,   795,    11,
      76,   182,   822,   308,   535,   536,   714,  -258,   796,   158,
     716,   106,   809,   194,   694,   695,   715,   696,   105,    82,
      83,   200,   149,   714,   181,   317,    93,   675,   762,   318,
     716,  -179,  -118,   715,   614,   106,   857,   332,   299,   452,
      52,   905,   906,    94,   328,     1,   281,   716,   776,   879,
     453,   151,   810,   151,   328,   331,   822,    56,   797,   487,
     212,   111,   571,   829,    76,   331,   717,   829,    79,   288,
     462,   283,   -22,    70,   293,   866,    87,   315,   556,   316,
     930,   938,   151,   717,   364,   196,   367,   282,   866,   679,
     697,   590,    47,    48,    49,   334,    72,   194,    47,    48,
      49,   418,    90,    59,    60,    47,    48,    49,    59,    60,
      65,   666,   698,   158,   667,    93,    65,   158,    65,   333,
      47,    48,    49,    64,    95,    96,   149,   796,   168,    64,
     149,    64,    47,    48,    49,   426,   185,    83,   -22,   336,
      47,    48,    49,   199,   851,    59,    60,   290,   104,    47,
      48,    49,   201,  -118,    59,    60,   203,    47,    48,    49,
      47,    48,    49,   606,   163,   164,   167,    12,   205,    13,
      14,   209,    15,   607,   608,   216,   586,   797,   152,   571,
     152,   -22,   301,   -22,   217,   -22,   151,   293,   186,   302,
     151,   571,   304,   177,   465,   466,   467,   156,  -244,   156,
     282,   427,   132,   133,   134,   135,   305,   424,   564,   152,
     685,   686,   309,   158,    47,    48,    49,    59,    60,    59,
      60,   361,   158,    47,    48,    49,   149,   158,   156,   765,
     679,   171,   172,   566,   572,   149,   360,   158,   740,   741,
     149,   744,   745,   362,   428,   369,   429,   370,   430,   371,
     149,    47,    48,    49,   473,   474,   475,   476,   477,   478,
     290,   820,    19,   373,   479,   480,   571,   374,   844,    20,
      21,   375,   376,    22,   291,    23,   126,   127,   128,   129,
     130,   131,    24,   377,    25,   378,   151,   379,   739,   380,
     381,   382,   556,   292,   383,   151,   385,   386,   499,   387,
     151,   388,   389,   390,   452,   391,   392,   393,   394,   395,
     151,   396,   397,   152,   398,   453,   399,   152,   599,   600,
     601,   602,   603,   604,   400,   401,   402,   403,   404,   564,
     537,   405,   156,   406,   407,   551,   156,   408,   551,   409,
     410,   411,   412,   413,   872,   414,   416,   441,   547,   293,
     293,   547,   458,   460,   566,   442,   454,   506,   538,   572,
     427,   430,   565,   573,   883,   577,   587,   158,    65,   468,
     579,   592,   594,   595,   605,   597,   616,   617,   618,   670,
     149,    64,   620,   672,   623,   624,   621,   291,   686,   593,
     622,   626,   627,   625,   628,   629,   630,   791,   631,   632,
     633,   638,   639,   640,   641,   642,   292,   643,   548,   644,
     646,   548,   647,   152,   648,   645,   650,   651,   649,   652,
     653,   654,   152,   655,   656,   657,   658,   152,   659,   923,
     924,   925,   156,   661,   660,   662,   663,   152,   684,   731,
     151,   156,   753,   759,   733,   685,   156,   790,   818,   825,
     778,   551,   824,   779,   822,   826,   156,   827,   328,   828,
     831,   551,   834,   836,   547,   837,   842,   337,   106,   331,
     293,   853,   863,   875,   547,   293,   572,   884,   876,   861,
     877,   878,   888,   565,   890,   866,   848,   158,   572,   900,
      65,   730,   852,   901,   902,   911,   915,   917,   921,   913,
     149,   907,   934,    64,   729,   928,   673,   840,   557,   295,
     669,   677,   841,   671,   559,   691,   768,   452,   415,   843,
     683,   313,   783,   682,   548,   781,   699,   175,   453,   328,
     100,    75,   485,   296,   548,   549,   838,   712,   549,   160,
     331,   328,   792,   439,   817,   816,   893,   794,   887,   931,
     894,   803,   331,   738,   550,   835,   742,   550,   737,   922,
     151,     0,     0,   572,     0,   611,   612,   152,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   156,   899,     0,     0,
       0,     0,   293,     0,     0,     0,     0,     0,     0,     0,
       0,   845,     0,     0,   293,   777,     0,   926,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   730,     0,   802,   730,   935,     0,   936,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
       0,   158,     0,     0,   551,     0,     0,     0,     0,     0,
       0,   549,    64,     0,   149,     0,     0,   547,     0,     0,
       0,   549,   328,     0,     0,     0,     0,     0,     0,     0,
     550,     0,   551,   331,     0,   551,     0,     0,     0,   293,
     550,    12,     0,    13,    14,   547,    15,   152,   547,   -72,
       0,     0,   777,    16,    17,     0,     0,     0,     0,     0,
     158,     0,     0,   802,     0,   859,   156,     0,     0,     0,
       0,    18,   158,   149,   151,     0,     0,   548,     0,     0,
       0,     0,     0,     0,   158,   149,     0,   551,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,     0,
     547,     0,     0,     0,     0,   548,     0,   551,   548,     0,
       0,     0,   885,     0,    65,     0,     0,     0,     0,     0,
     547,     0,     0,     0,     0,     0,     0,    64,     0,   730,
       0,   730,     0,   151,     0,     0,    19,     0,   158,     0,
       0,     0,     0,    20,    21,   151,     0,    22,     0,    23,
       0,   149,     0,     0,     0,     0,    24,   151,    25,     0,
     548,   909,     0,     0,     0,     0,     0,     0,     0,   910,
       0,     0,   551,   551,   551,   927,     0,    65,     0,     0,
     548,   802,     0,   730,     0,   547,   547,   547,     0,     0,
      64,     0,     0,     0,     0,     0,   729,     0,     0,     0,
       0,   152,     0,     0,   549,   158,     0,     0,     0,     0,
       0,   151,     0,     0,     0,     0,     0,     0,   149,     0,
     156,     0,     0,   550,     0,     0,     0,     0,     0,     0,
       0,     0,   549,     0,     0,   549,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   548,   548,   548,     0,     0,
       0,   550,     0,     0,   550,     0,     0,     0,     0,     0,
     152,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   152,     0,     0,     0,     0,     0,   151,   156,
       0,     0,     0,     0,   152,     0,     0,   549,     0,     0,
       0,   156,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   156,     0,     0,   550,   549,     0,     0,
       0,     0,   -76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   550,   115,   116,   117,
     118,   119,     0,     0,     0,     0,  -418,     0,   152,     0,
       0,     0,     0,     0,     0,     0,     0,   120,     0,     0,
       0,   115,   116,   117,   118,   119,     0,   156,     0,     0,
    -418,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,   549,   549,   549,   464,   115,   116,   117,   118,
     119,     0,     0,     0,     0,     0,   461,     0,     0,     0,
       0,   550,   550,   550,     0,     0,   120,     0,     0,   488,
     489,   490,     0,     0,   491,   152,     0,   492,   493,   494,
       0,   495,   496,   497,   498,     0,   500,   501,   502,   503,
     504,   505,     0,     0,   156,   509,   510,   511,     0,   512,
       0,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,     0,     0,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      47,    48,    49,   136,   137,    59,    60,     0,   138,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    47,    48,    49,   136,   137,    59,
      60,   540,   138,     0,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    47,
      48,    49,   136,   137,    59,    60,     0,   138,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   635,   637,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   541,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   664,   665,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   681,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   542,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    47,    48,    49,     0,     0,    59,    60,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   634,     0,     0,     0,     0,     0,     0,   747,   748,
     749,     0,     0,   750,     0,     0,   751,     0,     0,     0,
       0,   752,   337,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   755,     0,     0,     0,   756,     0,     0,
       0,   757,     0,   338,   339,     0,   340,   221,   758,   222,
     223,   224,   225,   226,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
     241,   540,     0,     0,   242,   243,   244,   245,   246,   247,
     248,   249,     0,     0,     0,     0,     0,     0,     0,   250,
       0,   251,     0,     0,   252,   253,     0,   254,     0,   255,
     256,   257,     0,   258,   259,     0,   260,     0,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    47,    48,    49,     0,
       0,    59,    60,     0,     0,   219,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   850,     0,
       0,     0,     0,     0,     0,     0,   220,   542,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    47,    48,    49,     0,     0,    59,    60,
     873,   221,   874,   222,   223,   224,   225,   226,   227,   228,
     229,     0,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,   241,     0,     0,     0,   242,   243,
     244,   245,   246,   247,   248,   249,     0,     0,     0,     0,
       0,     0,     0,   250,     0,   251,     0,     0,   252,   253,
       0,   254,     0,   255,   256,   257,     0,   258,   259,     0,
     260,     0,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   769,   770,
     871,   540,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   337,     0,     0,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      47,    48,    49,     0,     0,    59,    60,   221,   540,   222,
     223,   224,   225,   226,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
     241,     0,   115,   116,   117,   118,   119,     0,     0,     0,
       0,   249,     0,     0,     0,     0,     0,     0,     0,   250,
       0,   251,   120,     0,   252,   253,     0,   254,     0,   255,
     256,   257,     0,   258,   259,     0,   260,     0,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,     0,     0,     0,   542,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    47,    48,    49,     0,     0,    59,    60,
       0,     0,     0,     0,     0,   552,    47,    48,    49,     0,
       0,    59,    60,     0,   542,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      47,    48,    49,     0,     0,    59,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    47,    48,    49,   136,   137,
      59,    60,   337,   138,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   338,   339,     0,   340,   221,     0,   222,
     223,   224,   225,   226,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
     241,     0,     0,     0,   242,   243,   244,   245,   246,   247,
     248,   249,     0,     0,     0,     0,     0,     0,     0,   250,
       0,   251,     0,     0,   252,   253,     0,   254,     0,   255,
     256,   257,     0,   258,   259,     0,   260,     0,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,     0,
       0,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    47,    48,    49,     0,
       0,    59,    60,   221,     0,   222,   223,   224,   225,   226,
     227,   228,   229,     0,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,   241,     0,     0,     0,
     242,   243,   244,   245,   246,   247,   248,   249,     0,     0,
       0,     0,     0,     0,     0,   250,     0,   251,     0,     0,
     252,   253,     0,   254,     0,   255,   256,   257,     0,   258,
     259,     0,   260,     0,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   337,     0,     0,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    47,    48,    49,     0,     0,    59,    60,   221,
       0,   222,   223,   224,   225,   226,   227,   228,   229,     0,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,     0,     0,     0,   242,   243,   244,   245,
     246,   247,   248,   249,     0,     0,     0,     0,     0,     0,
       0,   250,     0,   251,     0,     0,   252,   253,     0,   254,
       0,   255,   256,   257,     0,   258,   259,     0,   260,     0,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   880,   540,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     561,     0,     0,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    47,    48,
      49,     0,     0,    59,    60,   221,     0,   222,   223,   224,
     225,   226,   227,   228,   229,     0,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,     0,   241,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   249,
       0,     0,     0,     0,     0,     0,     0,   250,     0,   251,
       0,     0,   252,   253,     0,   254,     0,   255,   256,   257,
       0,   258,   259,     0,   260,     0,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,     0,   542,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    47,
      48,    49,   337,     0,    59,    60,     0,     0,     0,     0,
       0,     0,     0,     0,    47,    48,    49,     0,     0,    59,
      60,     0,     0,     0,     0,     0,     0,   221,     0,   222,
     223,   224,   225,   226,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
     241,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   249,     0,     0,     0,     0,     0,     0,     0,   250,
       0,   251,     0,     0,   252,   253,     0,   254,     0,   255,
     256,   257,     0,   258,   259,     0,   260,     0,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    47,    48,    49
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        12,   104,   205,    17,   241,    17,   294,    19,   229,    14,
      15,   579,   101,   166,   209,    20,    21,   442,    17,    24,
     308,    23,    40,    19,    40,   209,    37,    69,   804,    40,
     209,    37,    74,    55,    23,   430,   166,   865,   166,    40,
     816,   684,   795,     6,    36,    36,    87,    61,    43,    61,
      19,    39,   174,   696,   386,    48,     6,     7,    70,    14,
      72,    37,    61,    43,   167,   102,    40,    36,    54,   897,
      19,    70,    48,    72,    22,    41,    50,   298,    40,     0,
      30,    93,    48,   186,   416,   417,    40,    37,    50,   101,
      64,    39,    61,   105,    44,    45,    50,    47,    22,     3,
       4,   113,   101,    40,    90,    50,     6,   102,   145,   202,
      64,     0,    36,    50,    63,    39,    50,   210,   106,   314,
      12,   143,   144,    23,   319,    14,   279,    64,   771,    41,
     314,    70,   101,    72,   329,   319,    48,    36,   100,   360,
     181,   104,   567,   752,    30,   329,   100,   756,    16,   279,
     329,   279,    36,    36,   166,   161,    15,   199,   553,   201,
     913,   937,   101,   100,   182,   157,   182,   166,   161,   149,
     120,   182,   174,   175,   176,   217,    36,   189,   174,   175,
     176,   182,     9,   179,   180,   174,   175,   176,   179,   180,
     202,    37,   142,   205,    40,     6,   208,   209,   210,   211,
     174,   175,   176,   202,   104,   105,   205,    50,    49,   208,
     209,   210,   174,   175,   176,    36,   305,     4,   102,   218,
     174,   175,   176,   108,   792,   179,   180,   166,    62,   174,
     175,   176,   108,   157,   179,   180,    37,   174,   175,   176,
     174,   175,   176,   480,    17,    18,    80,     8,    43,    10,
      11,    40,    13,    61,    62,    37,   459,   100,    70,   684,
      72,   145,   175,   147,   108,   149,   205,   279,   102,    55,
     209,   696,    37,   157,   338,   339,   340,    70,     6,    72,
     279,   102,   170,   171,   172,   173,    43,   299,   441,   101,
      28,    29,    90,   305,   174,   175,   176,   179,   180,   179,
     180,    40,   314,   174,   175,   176,   305,   319,   101,   148,
     149,    82,    83,   441,   442,   314,    74,   329,   607,   608,
     319,   613,   614,    40,   145,    40,   147,    40,   149,    40,
     329,   174,   175,   176,    55,    56,    57,    58,    59,    60,
     279,   736,   103,    40,    65,    66,   771,    40,   773,   110,
     111,    40,    40,   114,   166,   116,   164,   165,   166,   167,
     168,   169,   123,    40,   125,    40,   305,    40,   605,    40,
      40,    40,   767,   166,    40,   314,    40,    40,   377,    40,
     319,    40,    40,   182,   579,    40,   182,    40,    40,    40,
     329,    40,    40,   205,    40,   579,    40,   209,   473,   474,
     475,   476,   477,   478,    40,    40,    40,    40,    40,   562,
     422,    40,   205,    40,    40,   427,   209,    40,   430,    40,
      40,    40,    40,    40,   819,    40,    40,    25,   427,   441,
     442,   430,    43,     6,   562,    91,    52,    17,   174,   567,
     102,   149,   441,    24,   839,    37,   460,   459,   460,    89,
      43,    41,    41,    53,    66,    54,    41,    41,    41,   102,
     459,   460,    48,   149,    41,    41,    48,   279,    29,   468,
      48,    41,    41,    48,    48,    41,    41,   698,    41,    41,
      48,    41,    41,    41,    41,    41,   279,    41,   427,    41,
      41,   430,    41,   305,    41,    48,    41,    41,    48,    41,
      48,    41,   314,    41,    41,    41,    41,   319,    41,   904,
     905,   906,   305,    41,    48,    41,    41,   329,    25,    49,
     459,   314,    41,    41,    48,    28,   319,    40,    36,    41,
     161,   543,    48,   161,    48,    41,   329,    41,   733,    41,
      49,   553,    41,    41,   543,    41,    41,    40,    39,   733,
     562,    41,    63,    41,   553,   567,   684,   845,    75,   102,
      41,    41,    89,   562,    41,   161,   787,   579,   696,    41,
     582,   583,   793,    55,    48,    46,    49,    37,    37,   102,
     579,   884,    37,   582,   583,    41,   557,   764,   433,   168,
     543,   559,   767,   553,   436,   576,   681,   792,   279,   771,
     567,   189,   690,   562,   543,   689,   578,    85,   792,   804,
      55,    25,   359,   168,   553,   427,   760,   582,   430,    72,
     804,   816,   701,   305,   733,   731,   861,   714,   849,   915,
     863,   717,   816,   597,   427,   756,   609,   430,   595,   901,
     579,    -1,    -1,   771,    -1,   483,   483,   459,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   459,   870,    -1,    -1,
      -1,    -1,   684,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   784,    -1,    -1,   696,   684,    -1,   908,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   714,    -1,   716,   717,   927,    -1,   929,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   731,
      -1,   733,    -1,    -1,   736,    -1,    -1,    -1,    -1,    -1,
      -1,   543,   731,    -1,   733,    -1,    -1,   736,    -1,    -1,
      -1,   553,   937,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     543,    -1,   764,   937,    -1,   767,    -1,    -1,    -1,   771,
     553,     8,    -1,    10,    11,   764,    13,   579,   767,    16,
      -1,    -1,   771,    20,    21,    -1,    -1,    -1,    -1,    -1,
     792,    -1,    -1,   795,    -1,   797,   579,    -1,    -1,    -1,
      -1,    38,   804,   792,   733,    -1,    -1,   736,    -1,    -1,
      -1,    -1,    -1,    -1,   816,   804,    -1,   819,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   816,    -1,    -1,
     819,    -1,    -1,    -1,    -1,   764,    -1,   839,   767,    -1,
      -1,    -1,   846,    -1,   846,    -1,    -1,    -1,    -1,    -1,
     839,    -1,    -1,    -1,    -1,    -1,    -1,   846,    -1,   861,
      -1,   863,    -1,   792,    -1,    -1,   103,    -1,   870,    -1,
      -1,    -1,    -1,   110,   111,   804,    -1,   114,    -1,   116,
      -1,   870,    -1,    -1,    -1,    -1,   123,   816,   125,    -1,
     819,   886,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   888,
      -1,    -1,   904,   905,   906,   909,    -1,   909,    -1,    -1,
     839,   913,    -1,   915,    -1,   904,   905,   906,    -1,    -1,
     909,    -1,    -1,    -1,    -1,    -1,   915,    -1,    -1,    -1,
      -1,   733,    -1,    -1,   736,   937,    -1,    -1,    -1,    -1,
      -1,   870,    -1,    -1,    -1,    -1,    -1,    -1,   937,    -1,
     733,    -1,    -1,   736,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   764,    -1,    -1,   767,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   904,   905,   906,    -1,    -1,
      -1,   764,    -1,    -1,   767,    -1,    -1,    -1,    -1,    -1,
     792,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   804,    -1,    -1,    -1,    -1,    -1,   937,   792,
      -1,    -1,    -1,    -1,   816,    -1,    -1,   819,    -1,    -1,
      -1,   804,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   816,    -1,    -1,   819,   839,    -1,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   839,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    40,    -1,   870,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    -1,   870,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,   904,   905,   906,   337,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      -1,   904,   905,   906,    -1,    -1,    51,    -1,    -1,   361,
     362,   363,    -1,    -1,   366,   937,    -1,   369,   370,   371,
      -1,   373,   374,   375,   376,    -1,   378,   379,   380,   381,
     382,   383,    -1,    -1,   937,   387,   388,   389,    -1,   391,
      -1,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,    -1,    -1,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    -1,   182,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,    42,   182,    -1,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,   182,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   507,   508,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   535,   536,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   561,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,    -1,    -1,   179,   180,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,   620,   621,
     622,    -1,    -1,   625,    -1,    -1,   628,    -1,    -1,    -1,
      -1,   633,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   645,    -1,    -1,    -1,   649,    -1,    -1,
      -1,   653,    -1,    61,    62,    -1,    64,    65,   660,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    42,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
      -1,   109,    -1,    -1,   112,   113,    -1,   115,    -1,   117,
     118,   119,    -1,   121,   122,    -1,   124,    -1,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    -1,
      -1,   179,   180,    -1,    -1,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   790,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,    -1,    -1,   179,   180,
     822,    65,   824,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,    -1,   109,    -1,    -1,   112,   113,
      -1,   115,    -1,   117,   118,   119,    -1,   121,   122,    -1,
     124,    -1,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    26,    27,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,   179,   180,    65,    42,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    -1,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
      -1,   109,    51,    -1,   112,   113,    -1,   115,    -1,   117,
     118,   119,    -1,   121,   122,    -1,   124,    -1,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    -1,    -1,    -1,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,    -1,    -1,   179,   180,
      -1,    -1,    -1,    -1,    -1,   149,   174,   175,   176,    -1,
      -1,   179,   180,    -1,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,   179,   180,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    40,   182,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    -1,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
      -1,   109,    -1,    -1,   112,   113,    -1,   115,    -1,   117,
     118,   119,    -1,   121,   122,    -1,   124,    -1,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    -1,
      -1,   179,   180,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,    -1,   109,    -1,    -1,
     112,   113,    -1,   115,    -1,   117,   118,   119,    -1,   121,
     122,    -1,   124,    -1,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    -1,    -1,   179,   180,    65,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    -1,    88,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,    -1,   109,    -1,    -1,   112,   113,    -1,   115,
      -1,   117,   118,   119,    -1,   121,   122,    -1,   124,    -1,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    -1,    -1,   179,   180,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    -1,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,   109,
      -1,    -1,   112,   113,    -1,   115,    -1,   117,   118,   119,
      -1,   121,   122,    -1,   124,    -1,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,    40,    -1,   179,   180,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   174,   175,   176,    -1,    -1,   179,
     180,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
      -1,   109,    -1,    -1,   112,   113,    -1,   115,    -1,   117,
     118,   119,    -1,   121,   122,    -1,   124,    -1,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   174,   175,   176
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    14,   184,   185,   186,   189,   190,   226,   290,   291,
     174,     0,     8,    10,    11,    13,    20,    21,    38,   103,
     110,   111,   114,   116,   123,   125,   187,   230,   231,   246,
     248,   252,   296,   297,   300,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   191,   174,   175,   176,
     503,   504,    12,   301,   301,   301,    36,   381,    19,   179,
     180,   249,   250,   452,   453,   503,   232,   503,   301,   301,
      36,   324,    36,   325,   301,   325,    30,   188,   282,    16,
     237,   292,     3,     4,   314,   316,   317,    15,   192,   227,
       9,   298,   299,     6,    23,   104,   105,   322,   323,   322,
     323,   382,   247,   452,   232,    22,    39,   253,   258,   259,
       6,   104,   320,   321,   320,    31,    32,    33,    34,    35,
      51,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   177,   178,   182,   326,
     327,   335,   387,   443,   444,   446,   447,   448,   451,   453,
     454,   493,   497,   498,   499,   500,   501,   502,   503,   505,
     326,   320,   283,    17,    18,   238,   239,   232,    49,   294,
     295,   324,   324,   315,   313,   317,   228,   157,   193,   195,
     196,   322,   503,   383,   384,   387,   232,   251,   258,    23,
     254,   255,   256,   257,   503,    36,   157,   338,   340,   108,
     503,   108,   445,    37,   330,    43,   336,   337,   389,    40,
     388,    87,   181,   494,   495,   496,    37,   108,   284,    19,
      40,    65,    67,    68,    69,    70,    71,    72,    73,    74,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    88,    92,    93,    94,    95,    96,    97,    98,    99,
     107,   109,   112,   113,   115,   117,   118,   119,   121,   122,
     124,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   242,   243,   244,
     245,   373,   453,   478,   480,   482,   483,   484,   485,   488,
     493,   497,   501,   503,   258,   189,   291,   293,    39,   106,
     318,   175,    55,   194,    37,    43,   385,   386,   258,    90,
     260,   261,   265,   257,   341,   320,   320,    50,   390,   401,
     452,   329,   331,   332,   327,   390,   395,   396,   443,   449,
     450,   451,   390,   503,   320,    36,   453,    40,    61,    62,
      64,   453,   455,   456,   459,   462,   463,   466,   467,   473,
     475,   476,   477,   478,   485,   491,   493,   497,   501,   503,
      74,    40,    40,    40,   182,   479,    40,   182,   379,    40,
      40,    40,   338,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,   379,    40,    40,    40,    40,    40,
     182,    40,   182,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,   243,    40,    40,   182,   374,
     260,   338,    23,   319,   503,   229,    36,   102,   145,   147,
     149,   197,   198,   200,   201,   208,   210,   211,   218,   383,
     260,    25,    91,   262,   268,   233,   234,   339,   342,   343,
     346,   402,   443,   451,    52,   397,   400,   450,    43,   328,
       6,    41,   450,   288,   455,   476,   476,   476,    89,   240,
     241,   458,   461,    55,    56,    57,    58,    59,    60,    65,
      66,   464,   465,   472,   474,   374,   492,   338,   455,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   453,
     455,   455,   455,   455,   455,   455,    17,   376,   376,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     455,   455,   455,   455,   455,   376,   376,   503,   174,   219,
      42,   102,   158,   202,   203,   206,   289,   453,   493,   497,
     501,   503,   149,   212,   213,   216,   289,   201,   199,   211,
     209,    40,   266,   267,   373,   453,   478,   269,   270,   372,
     373,   477,   478,    24,   263,   271,   235,    37,   345,    43,
     347,   348,   404,   403,   394,   399,   327,   452,    37,    40,
     182,   286,    41,   453,    41,    53,   457,    54,   460,   466,
     466,   466,   466,   466,   466,    66,   379,    61,    62,   468,
     471,   499,   500,    19,    63,   469,    41,    41,    41,   380,
      48,    48,    48,    41,    41,    48,    41,    41,    48,    41,
      41,    41,    41,    48,    19,   455,   487,   455,    41,    41,
      41,    41,    41,    41,    41,    48,    41,    41,    41,    48,
      41,    41,    41,    48,    41,    41,    41,    41,    41,    41,
      48,    41,    41,    41,   455,   455,    37,    40,   220,   206,
     102,   216,   149,   199,    43,   102,   204,   209,    43,   149,
     214,   455,   267,   270,    25,    28,    29,   264,   277,   280,
     281,   237,     6,     7,    44,    45,    47,   120,   142,   282,
     344,   349,   350,   351,   353,   357,   361,   362,   365,   366,
     371,   343,   396,   413,    40,    50,    64,   100,   405,   407,
     414,   415,   416,   417,   420,   423,   425,   431,   432,   453,
     503,    49,   393,    48,   398,   333,   287,   459,   462,   379,
     473,   473,   469,   470,   475,   475,   378,   455,   455,   455,
     455,   455,   455,    41,   486,   455,   455,   455,   455,    41,
     375,   221,   145,   207,   205,   148,   217,   215,   241,    26,
      27,   272,   273,   274,   275,   276,   372,   453,   161,   161,
     278,   281,   279,   280,   236,   354,   358,   352,   363,   372,
      40,   338,   328,   367,   416,    40,    50,   100,   433,   438,
     439,   441,   503,   423,   406,   419,   422,    19,    36,    61,
     101,   424,   426,   430,   391,   392,   401,   400,    36,   285,
     289,    41,    48,   377,    48,    41,    41,    41,    41,   377,
     481,    49,   489,   490,    41,   481,    41,    41,   378,   224,
     203,   213,    41,   273,   477,   258,   355,   359,   338,   364,
     455,   343,   338,    41,   436,   437,   439,    50,   440,   503,
     397,   102,   418,    63,   421,    48,   161,   429,   442,   397,
     334,    41,   289,   455,   455,    41,    75,    41,    41,    41,
      41,   223,   225,   289,   260,   452,   360,   338,    89,   370,
      41,   435,   412,   420,   425,   442,    37,    48,   428,   327,
      41,    55,    48,   222,    55,   143,   144,   188,   356,   301,
     453,    46,   368,   102,   434,    49,   411,    37,    37,   427,
     442,    37,   502,   289,   289,   289,   338,   452,    41,   369,
     439,   407,   408,   410,    37,   338,   338,   409,   397
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
     435,   436,   437
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  SPARQLfedParser::yyr1_[] =
  {
         0,   183,   184,   184,   185,   186,   187,   187,   187,   187,
     188,   188,   189,   190,   190,   191,   191,   192,   192,   194,
     193,   195,   196,   196,   197,   197,   197,   198,   198,   199,
     199,   200,   201,   202,   202,   203,   203,   205,   204,   206,
     207,   208,   208,   209,   209,   210,   211,   212,   212,   213,
     213,   215,   214,   216,   217,   218,   219,   219,   221,   220,
     222,   222,   223,   224,   224,   225,   225,   225,   226,   228,
     229,   227,   231,   230,   232,   232,   234,   235,   236,   233,
     237,   238,   238,   239,   239,   240,   241,   241,   242,   243,
     243,   243,   243,   243,   243,   243,   243,   244,   244,   245,
     245,   247,   246,   248,   249,   249,   250,   250,   251,   251,
     252,   253,   254,   254,   255,   256,   257,   258,   259,   259,
     260,   261,   261,   262,   262,   263,   263,   264,   264,   265,
     266,   266,   267,   267,   267,   267,   268,   269,   269,   270,
     271,   272,   272,   273,   273,   274,   274,   275,   276,   276,
     277,   277,   278,   278,   279,   279,   280,   281,   283,   282,
     284,   284,   285,   285,   287,   286,   286,   288,   288,   289,
     289,   289,   289,   289,   289,   289,   290,   292,   291,   293,
     293,   294,   295,   295,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   297,   298,   299,   299,   300,
     301,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   312,   313,   313,   314,   314,   315,   315,
     316,   317,   318,   319,   319,   320,   320,   321,   321,   322,
     323,   323,   323,   323,   324,   325,   326,   327,   327,   328,
     328,   329,   330,   330,   332,   333,   334,   331,   335,   336,
     337,   337,   338,   338,   339,   339,   341,   340,   342,   343,
     343,   344,   345,   345,   346,   347,   348,   348,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   350,   352,   351,
     354,   355,   356,   353,   358,   359,   360,   357,   361,   363,
     364,   362,   366,   367,   365,   369,   368,   370,   370,   371,
     372,   372,   372,   373,   374,   375,   374,   376,   376,   377,
     378,   378,   379,   380,   379,   382,   381,   383,   383,   384,
     385,   386,   386,   388,   387,   389,   387,   390,   391,   392,
     392,   393,   394,   394,   395,   396,   396,   397,   398,   399,
     399,   400,   401,   401,   403,   402,   404,   402,   406,   405,
     407,   407,   409,   408,   410,   410,   411,   412,   412,   413,
     414,   415,   416,   417,   418,   419,   419,   420,   421,   422,
     422,   423,   424,   424,   425,   425,   426,   427,   427,   428,
     428,   429,   429,   430,   430,   430,   430,   431,   432,   432,
     432,   432,   433,   434,   435,   435,   436,   437,   437,   438,
     438,   439,   440,   440,   441,   441,   441,   442,   443,   443,
     445,   444,   446,   447,   447,   447,   447,   447,   448,   448,
     449,   449,   450,   450,   451,   451,   452,   452,   453,   453,
     454,   454,   454,   454,   454,   454,   455,   456,   457,   458,
     458,   459,   460,   461,   461,   462,   463,   464,   464,   465,
     465,   465,   465,   465,   465,   465,   465,   466,   467,   468,
     468,   469,   469,   470,   470,   471,   471,   471,   472,   472,
     473,   474,   474,   475,   475,   475,   475,   476,   476,   476,
     476,   476,   476,   476,   476,   477,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   479,   479,   480,   481,   481,
     482,   483,   484,   485,   485,   486,   485,   487,   487,   488,
     488,   488,   488,   488,   489,   490,   490,   491,   492,   492,
     493,   494,   495,   495,   496,   496,   497,   497,   497,   498,
     498,   498,   499,   499,   499,   500,   500,   500,   501,   501,
     502,   502,   502,   502,   503,   503,   504,   504,   505,   505
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  SPARQLfedParser::yyr2_[] =
  {
         0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       0,     1,     3,     0,     1,     0,     2,     0,     2,     0,
       3,     2,     0,     1,     1,     1,     1,     4,     3,     0,
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
       2,     2,     0,     1,     0,     1,     2,     2,     0,     6,
       0,     2,     1,     2,     0,     4,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     0,
       1,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     0,     1,     3,
       0,     1,     3,     3,     5,     5,     5,     2,     2,     2,
       5,     2,     0,     1,     0,     1,     2,     1,     0,     2,
       2,     2,     2,     1,     2,     1,     2,     0,     1,     2,
       1,     1,     1,     1,     3,     3,     2,     0,     1,     0,
       1,     3,     0,     2,     0,     0,     0,     8,     2,     2,
       0,     1,     1,     1,     1,     1,     0,     4,     2,     0,
       1,     3,     0,     2,     2,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     0,     3,
       0,     0,     0,     6,     0,     0,     0,     7,     6,     0,
       0,     4,     0,     0,     4,     0,     3,     0,     2,     2,
       1,     1,     1,     2,     1,     0,     6,     0,     1,     2,
       0,     2,     1,     0,     5,     0,     4,     0,     1,     2,
       2,     0,     1,     0,     3,     0,     3,     3,     2,     0,
       1,     2,     0,     2,     1,     0,     1,     2,     2,     0,
       2,     1,     1,     1,     0,     3,     0,     3,     0,     4,
       1,     1,     0,     3,     0,     1,     2,     0,     2,     1,
       1,     1,     1,     2,     2,     0,     2,     2,     2,     0,
       2,     2,     0,     1,     1,     2,     1,     1,     2,     2,
       1,     2,     3,     1,     1,     1,     2,     1,     1,     1,
       2,     3,     1,     2,     0,     2,     2,     0,     1,     1,
       3,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       0,     4,     4,     1,     1,     1,     1,     1,     0,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     0,
       2,     2,     2,     0,     2,     1,     2,     0,     1,     2,
       2,     2,     2,     2,     2,     2,     3,     1,     2,     1,
       1,     2,     2,     0,     1,     2,     2,     2,     0,     2,
       2,     0,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     4,     4,     6,     4,
       4,     4,     4,     2,     2,     4,     4,     4,     4,     2,
       1,     4,     4,     4,     4,     6,     6,     6,     4,     4,
       4,     4,     4,     4,     4,     2,     4,     4,     4,     4,
       4,     4,     2,     8,     6,     6,     6,     4,     4,     4,
       4,     4,     1,     1,     1,     3,     1,     7,     0,     1,
       7,     2,     3,     5,     5,     0,     7,     1,     1,     1,
       1,     1,     1,     1,     4,     0,     1,     2,     0,     1,
       2,     2,     1,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
  "IT_USING", "IT_MD5", "IT_TO", "IT_YEAR", "IT_ADD", "IT_COPY", "IT_RAND",
  "IT_SHA512",
  "GT_DELETE_LBRACKET_SPACECHAR_TAB_RETURN_LINEFEED_RBRACKET_PLUS_WHERE",
  "IT_NOW",
  "GT_DELETE_LBRACKET_SPACECHAR_TAB_RETURN_LINEFEED_RBRACKET_PLUS_DATA",
  "IT_TIMEZONE", "IT_ROUND", "IT_SHA384", "IT_BIND", "IT_CONTAINS",
  "IT_SECONDS", "IT_MOVE", "IT_FLOOR",
  "GT_INSERT_LBRACKET_SPACECHAR_TAB_RETURN_LINEFEED_RBRACKET_PLUS_DATA",
  "IT_MINUTES", "IT_SUBSTR", "IT_SHA256", "IT_HOURS", "IT_ENCODE_FOR_URI",
  "IT_STRSTARTS", "IT_CEIL", "IT_DAY", "IT_LCASE", "IT_ABS", "IT_UCASE",
  "IT_SHA224", "IT_STRENDS", "IT_STRLEN", "IT_SHA1", "IT_MONTH",
  "IT_PRINT", "GT_H_2192_", "GT_MINUS_GT", "ABOX_HR", "ABOX_CELL",
  "UBOX_UHR", "UBOX_LHR", "GT_H_2502_", "UBOX_UL", "UBOX_U", "UBOX_UR",
  "UBOX_SEP", "UBOX_LL", "UBOX_L", "UBOX_LR", "RSREF", "GT_MINUS_MINUS",
  "IT_true", "IT_false", "INTEGER", "DECIMAL", "DOUBLE",
  "INTEGER_POSITIVE", "DECIMAL_POSITIVE", "DOUBLE_POSITIVE",
  "INTEGER_NEGATIVE", "DECIMAL_NEGATIVE", "DOUBLE_NEGATIVE",
  "STRING_LITERAL1", "STRING_LITERAL_LONG1", "STRING_LITERAL2",
  "STRING_LITERAL_LONG2", "IRI_REF", "PNAME_NS", "PNAME_LN",
  "BLANK_NODE_LABEL", "ANON", "VAR1", "VAR2", "LANGTAG", "NIL", "$accept",
  "Top", "QueryUnit", "Query",
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
       184,     0,    -1,   185,    -1,   290,    -1,   186,    -1,   189,
     187,   188,    -1,   230,    -1,   246,    -1,   248,    -1,   252,
      -1,    -1,   282,    -1,   190,   191,   192,    -1,    -1,   226,
      -1,    -1,   191,   227,    -1,    -1,   192,   193,    -1,    -1,
     196,   194,   197,    -1,   157,    55,    -1,    -1,   195,    -1,
     198,    -1,   208,    -1,   218,    -1,   200,   201,   199,   207,
      -1,   201,   199,    43,    -1,    -1,   199,   204,    -1,   145,
      -1,   102,   203,    -1,   206,    -1,   202,   206,    -1,   102,
      -1,   202,    -1,    -1,   102,   205,   203,    -1,   289,   102,
      -1,   145,    -1,   210,   211,   209,   217,    -1,   211,   209,
      43,    -1,    -1,   209,   214,    -1,   147,    -1,   149,   213,
      -1,   216,    -1,   212,   216,    -1,   149,    -1,   212,    -1,
      -1,   149,   215,   213,    -1,   289,   149,    -1,   148,    -1,
      36,   219,    37,    -1,    -1,   219,   220,    -1,    -1,    40,
     221,   224,    41,    -1,    -1,    48,    -1,   225,   222,    -1,
      -1,   224,   223,    -1,   289,   144,   289,    -1,   289,   143,
     289,    -1,   289,    55,   289,    -1,    14,   174,    -1,    -1,
      -1,    15,   228,   175,   229,   174,    -1,    -1,   231,   237,
     232,   258,   260,    -1,    -1,   232,   253,    -1,    -1,    -1,
      -1,   234,   235,   237,   236,   258,   260,   188,    -1,    16,
     239,   245,    -1,    17,    -1,    18,    -1,    -1,   238,    -1,
      89,   453,    -1,    -1,   240,    -1,    40,   455,   241,    41,
      -1,   453,    -1,   485,    -1,   478,    -1,   373,    -1,   493,
      -1,   497,    -1,   501,    -1,   242,    -1,   243,    -1,   244,
     243,    -1,   244,    -1,    19,    -1,    -1,    20,   381,   247,
     232,   258,   260,    -1,    21,   250,   232,   251,   260,    -1,
     452,    -1,   249,   452,    -1,   249,    -1,    19,    -1,    -1,
     258,    -1,    38,   232,   258,    -1,    22,   254,    -1,   255,
      -1,   256,    -1,   257,    -1,    23,   257,    -1,   503,    -1,
     259,   338,    -1,    -1,    39,    -1,   261,   262,   263,   264,
      -1,    -1,   265,    -1,    -1,   268,    -1,    -1,   271,    -1,
      -1,   277,    -1,    90,    25,   266,    -1,   267,    -1,   266,
     267,    -1,   478,    -1,   373,    -1,    40,   455,   241,    41,
      -1,   453,    -1,    91,   269,    -1,   270,    -1,   269,   270,
      -1,   372,    -1,    24,    25,   272,    -1,   273,    -1,   272,
     273,    -1,   275,    -1,   276,    -1,    26,    -1,    27,    -1,
     274,   477,    -1,   372,    -1,   453,    -1,   280,   278,    -1,
     281,   279,    -1,    -1,   281,    -1,    -1,   280,    -1,    28,
     161,    -1,    29,   161,    -1,    -1,    30,   283,   284,    36,
     288,    37,    -1,    -1,   284,   453,    -1,   289,    -1,   285,
     289,    -1,    -1,    40,   287,   285,    41,    -1,   182,    -1,
      -1,   288,   286,    -1,   503,    -1,   493,    -1,   497,    -1,
     501,    -1,    42,    -1,   158,    -1,   453,    -1,   291,    -1,
      -1,   189,   296,   292,   295,    -1,    -1,   291,    -1,    49,
     293,    -1,    -1,   294,    -1,   297,    -1,   300,    -1,   302,
      -1,   304,    -1,   305,    -1,   306,    -1,   303,    -1,   307,
      -1,   308,    -1,   309,    -1,   310,    -1,     8,   503,   299,
      -1,     9,   322,    -1,    -1,   298,    -1,    10,   301,   323,
      -1,    -1,    12,    -1,    13,   301,   323,    -1,    11,   301,
     322,    -1,   110,   301,   320,   108,   320,    -1,   123,   301,
     320,   108,   320,    -1,   111,   301,   320,   108,   320,    -1,
     125,   325,    -1,   116,   325,    -1,   114,   324,    -1,   312,
     314,   315,    39,   338,    -1,   103,   503,    -1,    -1,   311,
      -1,    -1,   317,    -1,   316,   313,    -1,   317,    -1,    -1,
     315,   318,    -1,     3,   324,    -1,     4,   324,    -1,   106,
     319,    -1,   503,    -1,    23,   503,    -1,   104,    -1,   321,
     503,    -1,    -1,     6,    -1,     6,   503,    -1,   322,    -1,
     104,    -1,    23,    -1,   105,    -1,    36,   326,    37,    -1,
      36,   326,    37,    -1,   327,   330,    -1,    -1,   335,    -1,
      -1,    43,    -1,   331,   328,   327,    -1,    -1,   330,   329,
      -1,    -1,    -1,    -1,   332,     6,   452,   333,    36,   334,
     327,    37,    -1,   387,   337,    -1,    43,   327,    -1,    -1,
     336,    -1,   340,    -1,   157,    -1,   233,    -1,   342,    -1,
      -1,    36,   341,   339,    37,    -1,   343,   345,    -1,    -1,
     346,    -1,   349,   328,   343,    -1,    -1,   345,   344,    -1,
     402,   348,    -1,    43,   343,    -1,    -1,   347,    -1,   365,
      -1,   351,    -1,   362,    -1,   353,    -1,   357,    -1,   371,
      -1,   361,    -1,   282,    -1,   350,    -1,   142,   338,    -1,
      -1,    44,   352,   338,    -1,    -1,    -1,    -1,     6,   354,
     355,   452,   356,   338,    -1,    -1,    -1,    -1,     7,   358,
     359,   360,   301,   452,   338,    -1,   120,    40,   455,    89,
     453,    41,    -1,    -1,    -1,    45,   363,   364,   338,    -1,
      -1,    -1,   366,   367,   338,   370,    -1,    -1,    46,   369,
     338,    -1,    -1,   370,   368,    -1,    47,   372,    -1,   477,
      -1,   478,    -1,   373,    -1,   503,   374,    -1,   182,    -1,
      -1,    40,   376,   455,   375,   378,    41,    -1,    -1,    17,
      -1,    48,   455,    -1,    -1,   378,   377,    -1,   182,    -1,
      -1,    40,   455,   380,   378,    41,    -1,    -1,    36,   382,
     383,    37,    -1,    -1,   384,    -1,   387,   386,    -1,    43,
     383,    -1,    -1,   385,    -1,    -1,   451,   388,   390,    -1,
      -1,   443,   389,   395,    -1,   401,   397,   394,    -1,   401,
     397,    -1,    -1,   391,    -1,    49,   392,    -1,    -1,   394,
     393,    -1,   396,    -1,    -1,   390,    -1,   400,   399,    -1,
      48,   400,    -1,    -1,   399,   398,    -1,   450,    -1,   452,
      -1,    50,    -1,    -1,   451,   403,   405,    -1,    -1,   443,
     404,   413,    -1,    -1,   407,   406,   397,   412,    -1,   414,
      -1,   415,    -1,    -1,   407,   409,   397,    -1,    -1,   408,
      -1,    49,   410,    -1,    -1,   412,   411,    -1,   396,    -1,
     416,    -1,   453,    -1,   417,    -1,   420,   419,    -1,   102,
     420,    -1,    -1,   419,   418,    -1,   425,   422,    -1,    63,
     425,    -1,    -1,   422,   421,    -1,   431,   424,    -1,    -1,
     426,    -1,   423,    -1,   100,   423,    -1,   430,    -1,    37,
      -1,   442,    37,    -1,    48,   427,    -1,    37,    -1,   442,
     428,    -1,    48,   442,    37,    -1,    19,    -1,   101,    -1,
      61,    -1,    36,   429,    -1,   432,    -1,   503,    -1,    50,
      -1,    64,   433,    -1,    40,   416,    41,    -1,   438,    -1,
     102,   439,    -1,    -1,   435,   434,    -1,   439,   435,    -1,
      -1,   436,    -1,   439,    -1,    40,   437,    41,    -1,   441,
      -1,   503,    -1,    50,    -1,   503,    -1,    50,    -1,   100,
     440,    -1,   161,    -1,   446,    -1,   444,    -1,    -1,    51,
     445,   390,    52,    -1,   448,    40,   449,    41,    -1,    31,
      -1,    32,    -1,    33,    -1,    34,    -1,    35,    -1,    -1,
     447,    -1,   450,    -1,   449,   450,    -1,   451,    -1,   443,
      -1,   453,    -1,   454,    -1,   453,    -1,   503,    -1,   179,
      -1,   180,    -1,   503,    -1,   493,    -1,   497,    -1,   501,
      -1,   505,    -1,   182,    -1,   456,    -1,   459,   458,    -1,
      53,   459,    -1,    -1,   458,   457,    -1,   462,   461,    -1,
      54,   462,    -1,    -1,   461,   460,    -1,   463,    -1,   466,
     464,    -1,    -1,   465,    -1,    55,   466,    -1,    56,   466,
      -1,    57,   466,    -1,    58,   466,    -1,    59,   466,    -1,
      60,   466,    -1,    66,   379,    -1,    65,    66,   379,    -1,
     467,    -1,   473,   472,    -1,   499,    -1,   500,    -1,    19,
     475,    -1,    63,   475,    -1,    -1,   469,    -1,    61,   473,
      -1,    62,   473,    -1,   468,   470,    -1,    -1,   472,   471,
      -1,   475,   474,    -1,    -1,   474,   469,    -1,    64,   476,
      -1,    61,   476,    -1,    62,   476,    -1,   476,    -1,   477,
      -1,   478,    -1,   491,    -1,   493,    -1,   497,    -1,   501,
      -1,   453,    -1,   485,    -1,    40,   455,    41,    -1,    76,
      40,   455,    41,    -1,    77,    40,   455,    41,    -1,    78,
      40,   455,    48,   455,    41,    -1,    79,    40,   455,    41,
      -1,    80,    40,   453,    41,    -1,    67,    40,   455,    41,
      -1,    68,    40,   455,    41,    -1,    69,   479,    -1,   112,
     182,    -1,   135,    40,   455,    41,    -1,   132,    40,   455,
      41,    -1,   124,    40,   455,    41,    -1,   118,    40,   455,
      41,    -1,    88,   379,    -1,   482,    -1,   139,    40,   455,
      41,    -1,   136,    40,   455,    41,    -1,   134,    40,   455,
      41,    -1,   130,    40,   455,    41,    -1,   121,    40,   455,
      48,   455,    41,    -1,   131,    40,   455,    48,   455,    41,
      -1,   138,    40,   455,    48,   455,    41,    -1,   109,    40,
     455,    41,    -1,   141,    40,   455,    41,    -1,   133,    40,
     455,    41,    -1,   129,    40,   455,    41,    -1,   126,    40,
     455,    41,    -1,   122,    40,   455,    41,    -1,   117,    40,
     455,    41,    -1,   115,   182,    -1,   107,    40,   455,    41,
      -1,   140,    40,   455,    41,    -1,   137,    40,   455,    41,
      -1,   128,    40,   455,    41,    -1,   119,    40,   455,    41,
      -1,   113,    40,   455,    41,    -1,    70,   379,    -1,    71,
      40,   455,    48,   455,    48,   455,    41,    -1,    72,    40,
     455,    48,   455,    41,    -1,    73,    40,   455,    48,   455,
      41,    -1,    81,    40,   455,    48,   455,    41,    -1,    82,
      40,   455,    41,    -1,    83,    40,   455,    41,    -1,    84,
      40,   455,    41,    -1,    85,    40,   455,    41,    -1,    99,
      40,   455,    41,    -1,   480,    -1,   483,    -1,   484,    -1,
      40,   455,    41,    -1,   182,    -1,    86,    40,   455,    48,
     455,   481,    41,    -1,    -1,   377,    -1,   127,    40,   455,
      48,   455,   481,    41,    -1,    74,   338,    -1,    65,    74,
     338,    -1,    92,    40,   376,   487,    41,    -1,   488,    40,
     376,   455,    41,    -1,    -1,    97,    40,   376,   455,   486,
     490,    41,    -1,    19,    -1,   455,    -1,    93,    -1,    94,
      -1,    95,    -1,    96,    -1,    98,    -1,    49,    75,    55,
     502,    -1,    -1,   489,    -1,   503,   492,    -1,    -1,   374,
      -1,   502,   496,    -1,    87,   503,    -1,   181,    -1,   494,
      -1,    -1,   495,    -1,   498,    -1,   499,    -1,   500,    -1,
     161,    -1,   162,    -1,   163,    -1,   164,    -1,   165,    -1,
     166,    -1,   167,    -1,   168,    -1,   169,    -1,   159,    -1,
     160,    -1,   170,    -1,   172,    -1,   171,    -1,   173,    -1,
     174,    -1,   504,    -1,   176,    -1,   175,    -1,   177,    -1,
     178,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  SPARQLfedParser::yyprhs_[] =
  {
         0,     0,     3,     5,     7,     9,    13,    15,    17,    19,
      21,    22,    24,    28,    29,    31,    32,    35,    36,    39,
      40,    44,    47,    48,    50,    52,    54,    56,    61,    65,
      66,    69,    71,    74,    76,    79,    81,    83,    84,    88,
      91,    93,    98,   102,   103,   106,   108,   111,   113,   116,
     118,   120,   121,   125,   128,   130,   134,   135,   138,   139,
     144,   145,   147,   150,   151,   154,   158,   162,   166,   169,
     170,   171,   177,   178,   184,   185,   188,   189,   190,   191,
     199,   203,   205,   207,   208,   210,   213,   214,   216,   221,
     223,   225,   227,   229,   231,   233,   235,   237,   239,   242,
     244,   246,   247,   254,   260,   262,   265,   267,   269,   270,
     272,   276,   279,   281,   283,   285,   288,   290,   293,   294,
     296,   301,   302,   304,   305,   307,   308,   310,   311,   313,
     317,   319,   322,   324,   326,   331,   333,   336,   338,   341,
     343,   347,   349,   352,   354,   356,   358,   360,   363,   365,
     367,   370,   373,   374,   376,   377,   379,   382,   385,   386,
     393,   394,   397,   399,   402,   403,   408,   410,   411,   414,
     416,   418,   420,   422,   424,   426,   428,   430,   431,   436,
     437,   439,   442,   443,   445,   447,   449,   451,   453,   455,
     457,   459,   461,   463,   465,   467,   471,   474,   475,   477,
     481,   482,   484,   488,   492,   498,   504,   510,   513,   516,
     519,   525,   528,   529,   531,   532,   534,   537,   539,   540,
     543,   546,   549,   552,   554,   557,   559,   562,   563,   565,
     568,   570,   572,   574,   576,   580,   584,   587,   588,   590,
     591,   593,   597,   598,   601,   602,   603,   604,   613,   616,
     619,   620,   622,   624,   626,   628,   630,   631,   636,   639,
     640,   642,   646,   647,   650,   653,   656,   657,   659,   661,
     663,   665,   667,   669,   671,   673,   675,   677,   680,   681,
     685,   686,   687,   688,   695,   696,   697,   698,   706,   713,
     714,   715,   720,   721,   722,   727,   728,   732,   733,   736,
     739,   741,   743,   745,   748,   750,   751,   758,   759,   761,
     764,   765,   768,   770,   771,   777,   778,   783,   784,   786,
     789,   792,   793,   795,   796,   800,   801,   805,   809,   812,
     813,   815,   818,   819,   822,   824,   825,   827,   830,   833,
     834,   837,   839,   841,   843,   844,   848,   849,   853,   854,
     859,   861,   863,   864,   868,   869,   871,   874,   875,   878,
     880,   882,   884,   886,   889,   892,   893,   896,   899,   902,
     903,   906,   909,   910,   912,   914,   917,   919,   921,   924,
     927,   929,   932,   936,   938,   940,   942,   945,   947,   949,
     951,   954,   958,   960,   963,   964,   967,   970,   971,   973,
     975,   979,   981,   983,   985,   987,   989,   992,   994,   996,
     998,   999,  1004,  1009,  1011,  1013,  1015,  1017,  1019,  1020,
    1022,  1024,  1027,  1029,  1031,  1033,  1035,  1037,  1039,  1041,
    1043,  1045,  1047,  1049,  1051,  1053,  1055,  1057,  1060,  1063,
    1064,  1067,  1070,  1073,  1074,  1077,  1079,  1082,  1083,  1085,
    1088,  1091,  1094,  1097,  1100,  1103,  1106,  1110,  1112,  1115,
    1117,  1119,  1122,  1125,  1126,  1128,  1131,  1134,  1137,  1138,
    1141,  1144,  1145,  1148,  1151,  1154,  1157,  1159,  1161,  1163,
    1165,  1167,  1169,  1171,  1173,  1175,  1179,  1184,  1189,  1196,
    1201,  1206,  1211,  1216,  1219,  1222,  1227,  1232,  1237,  1242,
    1245,  1247,  1252,  1257,  1262,  1267,  1274,  1281,  1288,  1293,
    1298,  1303,  1308,  1313,  1318,  1323,  1326,  1331,  1336,  1341,
    1346,  1351,  1356,  1359,  1368,  1375,  1382,  1389,  1394,  1399,
    1404,  1409,  1414,  1416,  1418,  1420,  1424,  1426,  1434,  1435,
    1437,  1445,  1448,  1452,  1458,  1464,  1465,  1473,  1475,  1477,
    1479,  1481,  1483,  1485,  1487,  1492,  1493,  1495,  1498,  1499,
    1501,  1504,  1507,  1509,  1511,  1512,  1514,  1516,  1518,  1520,
    1522,  1524,  1526,  1528,  1530,  1532,  1534,  1536,  1538,  1540,
    1542,  1544,  1546,  1548,  1550,  1552,  1554,  1556,  1558,  1560
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   480,   480,   483,   489,   494,   505,   506,   507,   508,
     513,   516,   521,   525,   527,   531,   533,   536,   538,   542,
     542,   560,   566,   569,   573,   574,   575,   579,   580,   583,
     585,   589,   593,   597,   598,   602,   603,   607,   607,   615,
     621,   625,   626,   629,   631,   635,   639,   643,   644,   648,
     649,   653,   653,   661,   667,   671,   674,   676,   680,   680,
     687,   689,   693,   696,   698,   702,   705,   708,   714,   720,
     722,   720,   732,   732,   744,   747,   755,   758,   761,   755,
     776,   784,   787,   794,   797,   802,   809,   812,   817,   824,
     827,   830,   833,   836,   839,   842,   846,   851,   854,   862,
     865,   872,   872,   883,   891,   894,   902,   905,   912,   915,
     920,   928,   935,   936,   940,   946,   952,   959,   966,   968,
     973,   980,   983,   988,   991,   996,   999,  1004,  1008,  1012,
    1019,  1022,  1029,  1032,  1035,  1038,  1044,  1050,  1053,  1060,
    1065,  1072,  1076,  1084,  1086,  1094,  1097,  1105,  1113,  1114,
    1121,  1125,  1133,  1136,  1141,  1144,  1148,  1154,  1161,  1161,
    1169,  1171,  1177,  1180,  1186,  1186,  1191,  1197,  1199,  1203,
    1206,  1209,  1212,  1215,  1218,  1221,  1227,  1231,  1231,  1240,
    1242,  1246,  1249,  1251,  1255,  1256,  1257,  1258,  1259,  1260,
    1261,  1262,  1263,  1264,  1265,  1269,  1276,  1283,  1286,  1290,
    1296,  1299,  1305,  1311,  1317,  1323,  1329,  1335,  1343,  1351,
    1359,  1368,  1374,  1377,  1381,  1384,  1388,  1392,  1398,  1400,
    1406,  1413,  1420,  1426,  1429,  1435,  1438,  1443,  1445,  1449,
    1455,  1458,  1461,  1464,  1471,  1475,  1479,  1482,  1484,  1488,
    1490,  1494,  1497,  1499,  1504,  1509,  1512,  1504,  1523,  1527,
    1530,  1532,  1536,  1537,  1550,  1551,  1556,  1556,  1567,  1571,
    1573,  1583,  1587,  1590,  1606,  1611,  1615,  1618,  1622,  1623,
    1624,  1625,  1626,  1627,  1628,  1629,  1632,  1636,  1642,  1642,
    1658,  1662,  1664,  1658,  1675,  1679,  1681,  1675,  1692,  1703,
    1707,  1703,  1717,  1721,  1717,  1731,  1731,  1743,  1745,  1749,
    1759,  1760,  1761,  1765,  1773,  1777,  1777,  1787,  1790,  1797,
    1803,  1805,  1819,  1822,  1822,  1833,  1833,  1841,  1843,  1848,
    1853,  1857,  1859,  1863,  1863,  1866,  1866,  1873,  1878,  1882,
    1884,  1889,  1893,  1895,  1900,  1904,  1906,  1911,  1916,  1920,
    1922,  1926,  1933,  1937,  1945,  1945,  1948,  1948,  1954,  1954,
    1960,  1961,  1965,  1965,  1970,  1972,  1976,  1979,  1981,  1985,
    1989,  1993,  1999,  2003,  2007,  2010,  2012,  2016,  2020,  2025,
    2027,  2033,  2036,  2038,  2044,  2045,  2051,  2055,  2056,  2060,
    2061,  2065,  2066,  2070,  2071,  2072,  2073,  2077,  2081,  2084,
    2087,  2090,  2096,  2100,  2103,  2105,  2109,  2112,  2114,  2118,
    2119,  2123,  2127,  2128,  2132,  2133,  2134,  2138,  2143,  2144,
    2148,  2148,  2161,  2186,  2189,  2192,  2195,  2198,  2205,  2208,
    2213,  2217,  2224,  2225,  2229,  2232,  2236,  2239,  2245,  2246,
    2250,  2253,  2256,  2259,  2262,  2263,  2269,  2274,  2283,  2290,
    2293,  2301,  2310,  2317,  2320,  2327,  2332,  2343,  2346,  2350,
    2353,  2356,  2359,  2362,  2365,  2368,  2371,  2377,  2382,  2391,
    2394,  2401,  2404,  2411,  2414,  2419,  2422,  2426,  2440,  2443,
    2451,  2460,  2463,  2470,  2473,  2476,  2479,  2483,  2484,  2485,
    2486,  2489,  2492,  2495,  2498,  2502,  2508,  2511,  2514,  2517,
    2520,  2523,  2526,  2530,  2533,  2536,  2539,  2542,  2545,  2548,
    2551,  2552,  2555,  2558,  2561,  2564,  2567,  2570,  2573,  2576,
    2579,  2582,  2585,  2588,  2591,  2594,  2597,  2600,  2603,  2606,
    2609,  2612,  2615,  2619,  2622,  2625,  2628,  2631,  2634,  2637,
    2640,  2643,  2646,  2647,  2648,  2654,  2657,  2664,  2671,  2674,
    2678,  2684,  2691,  2698,  2701,  2705,  2705,  2718,  2722,  2726,
    2729,  2732,  2735,  2738,  2744,  2750,  2753,  2757,  2767,  2770,
    2775,  2783,  2790,  2794,  2802,  2806,  2810,  2811,  2812,  2816,
    2817,  2818,  2822,  2823,  2824,  2828,  2829,  2830,  2834,  2835,
    2839,  2840,  2841,  2842,  2846,  2847,  2851,  2852,  2856,  2857
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
     175,   176,   177,   178,   179,   180,   181,   182
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int SPARQLfedParser::yyeof_ = 0;
  const int SPARQLfedParser::yylast_ = 2478;
  const int SPARQLfedParser::yynnts_ = 323;
  const int SPARQLfedParser::yyempty_ = -2;
  const int SPARQLfedParser::yyfinal_ = 11;
  const int SPARQLfedParser::yyterror_ = 1;
  const int SPARQLfedParser::yyerrcode_ = 256;
  const int SPARQLfedParser::yyntokens_ = 183;

  const unsigned int SPARQLfedParser::yyuser_token_number_max_ = 437;
  const SPARQLfedParser::token_number_type SPARQLfedParser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // w3c_sw

/* Line 1054 of lalr1.cc  */
#line 5457 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 2863 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


