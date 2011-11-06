
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
#line 711 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 717 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 719 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 721 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 729 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 732 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause);
	(yyval.p_Operation) = new Select((yysemantic_stack_[(5) - (2)].p_Project).distinctness, (yysemantic_stack_[(5) - (2)].p_Project).varSet, (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
	driver.countStar = (yysemantic_stack_[(5) - (1)].p_parentCountStar);
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 741 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 744 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 752 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_parentCountStar) = driver.countStar;
	driver.countStar = false;
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 755 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 758 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 762 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if ((yysemantic_stack_[(7) - (7)].p_BindingClause) != NULL)
	      (yysemantic_stack_[(7) - (5)].p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yysemantic_stack_[(7) - (7)].p_BindingClause), (yysemantic_stack_[(7) - (5)].p_WhereClause)->m_GroupGraphPattern);
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (4)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(7) - (3)].p_Project).distinctness, (yysemantic_stack_[(7) - (3)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(7) - (5)].p_WhereClause), (yysemantic_stack_[(7) - (6)].p_SolutionModifier))));
	  driver.curGraphName = (yysemantic_stack_[(7) - (2)].p_TTerm);
	  driver.countStar = (yysemantic_stack_[(7) - (1)].p_parentCountStar);
      }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 773 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 781 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 784 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 791 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 799 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 806 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 814 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 821 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 824 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
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
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 836 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 839 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 848 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 851 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 859 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 862 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 869 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = NULL;
      }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 871 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.lastWhereClause = (yysemantic_stack_[(6) - (5)].p_WhereClause);
	  /* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	  (yyval.p_Operation) = new Construct((DefaultGraphPattern*)((yysemantic_stack_[(6) - (2)].p_BasicGraphPattern) ? (yysemantic_stack_[(6) - (2)].p_BasicGraphPattern) : new DefaultGraphPattern()), (yysemantic_stack_[(6) - (4)].p_DatasetClauses), (yysemantic_stack_[(6) - (5)].p_WhereClause), (yysemantic_stack_[(6) - (6)].p_SolutionModifier));
      }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 880 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause) ? (yysemantic_stack_[(5) - (4)].p_WhereClause) : new WhereClause(new DefaultGraphPattern());
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 888 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm))));
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 891 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_TTerm))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 899 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 902 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 909 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 917 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(3) - (3)].p_WhereClause);
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(3) - (2)].p_DatasetClauses), (yysemantic_stack_[(3) - (3)].p_WhereClause));
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 925 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 937 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 943 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 949 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 956 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.ensureGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 970 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 977 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 985 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 993 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1001 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1009 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1016 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1019 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1026 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
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
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1035 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1041 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1047 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1050 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1062 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1069 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1073 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1083 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1091 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1094 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1102 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1111 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1118 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1122 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1130 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1138 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1145 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1151 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1158 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1160 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1168 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1174 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 1177 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 1183 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow(); // @@ push down to _Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star?
      }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 1185 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1188 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1200 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1203 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1206 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 1209 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 1212 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 1215 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 1225 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	OperationSet* ret = driver.root ? dynamic_cast<OperationSet*>(driver.root) : new OperationSet();
	ret->push_back((yysemantic_stack_[(2) - (2)].p_Operation));
	driver.root = ret;
      }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 1229 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Operation) = driver.root;
	}
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 1263 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(3) - (2)].p_URI), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 1270 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1277 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1284 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1290 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 1293 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 1299 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 1305 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 1311 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 1317 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 1323 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 1329 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert(driver.ensureGraphPattern(), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 1337 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete(driver.ensureGraphPattern(), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 1345 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete(driver.ensureGraphPattern(), NULL);
	driver.curOp = NULL;
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 1353 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(5) - (1)].p_URI))
	    w3c_sw_NEED_IMPL("WITH <URI> (DELETE INSERT?|INSERT) ...");
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(5) - (2)].p_DeleteInsert).del, (yysemantic_stack_[(5) - (2)].p_DeleteInsert).ins, new WhereClause(driver.ensureGraphPattern()));
	driver.curOp = NULL;
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 1362 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 1368 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 1375 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 1382 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 1386 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 1394 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("_QUsingClause_E_Star");
    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 1400 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Delete) = new Delete(driver.ensureGraphPattern(), NULL);
	driver.curOp = NULL;
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 1407 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = new Insert(driver.ensureGraphPattern(), NULL);
	driver.curOp = NULL;
    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 1414 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 1420 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 1423 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 1429 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 1432 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 1443 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 1449 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 1452 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("DEFAULT");
      }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 1455 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("NAMED");
      }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 1458 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("ALL");
      }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 1498 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 1503 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 1506 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 1509 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 1531 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 254:

/* Line 678 of lalr1.cc  */
#line 1550 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 1552 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 1623 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_BindingClause)) : (yysemantic_stack_[(1) - (1)].p_BindingClause);
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 1630 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Print(driver.curOp);
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 1636 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 1640 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 278:

/* Line 678 of lalr1.cc  */
#line 1652 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 1656 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 1658 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 1661 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 1669 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 1673 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 1675 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 1678 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(7) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(7) - (6)].p_TTerm), driver.curOp, (yysemantic_stack_[(7) - (5)].p_Silence), driver.atomFactory, false));
	  driver.curGraphName = (yysemantic_stack_[(7) - (4)].p_TTerm);
      }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 1686 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Bind(driver.ensureGraphPattern(), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
	// no more triples go into the current BGP, per
	//   http://www.w3.org/TR/sparql11-query/#sparqlTranslateGraphPatterns
	// test reference:
	//   http://www.sparql.org/query-validator?query=ASK+{+%3Fs+%3Fp+%3Fo+FILTER+%281%29+BIND+%282+AS+%3Fb%29+%3Fs2+%3Fp2+%3Fo2+FILTER+%283%29+BIND+%284+AS+%3Fd%29}&languageSyntax=SPARQL&outputFormat=algebra&linenumbers=false
	driver.curBGP = NULL;
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 1697 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 1701 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 1703 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 1711 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 1715 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 1717 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 1725 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 1730 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.ensureGraphPattern());
      }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 1743 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    driver.ensureGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 1759 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 1767 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 1771 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 1774 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yysemantic_stack_[(6) - (4)].p_Expressions);
      }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 1781 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 1784 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 1791 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 1799 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 1813 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 1816 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 1819 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(5) - (3)].p_Expressions);
      }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 1827 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 1829 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 1857 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 1860 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 1920 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 1927 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 1931 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 1939 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 1942 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 1948 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 1959 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 1987 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 2014 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 2021 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 2032 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 2039 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 2075 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 2078 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 2081 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 2084 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 2142 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 2146 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 2155 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 411:

/* Line 678 of lalr1.cc  */
#line 2180 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 2183 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 2186 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 2189 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 2192 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 2199 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 2207 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 2211 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 2223 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 2230 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 2233 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 2244 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 2247 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 2250 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 2253 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 2257 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 2268 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 2277 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 2284 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 2287 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 2295 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 2304 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 2311 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 2314 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 2326 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_GeneralComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_GeneralComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_GeneralComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 2337 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 2344 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 2347 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 2350 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 2353 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 2356 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 2359 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 2362 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 2365 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 2376 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 2385 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 2388 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 2395 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 2398 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 2405 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 2413 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 2416 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 2420 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 466:

/* Line 678 of lalr1.cc  */
#line 2434 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 2437 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 2445 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 2454 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 2457 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 2464 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 2467 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 2470 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 2480 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 2483 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 2486 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 2489 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 2496 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 2502 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 2505 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 2508 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 2511 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 2514 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 2517 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 2520 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 2524 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 2527 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 2530 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 2533 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ciel, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 2536 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 2539 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 2542 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 2546 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 2549 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 2552 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 2555 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 2558 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 2561 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 2564 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 2567 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 2570 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 2573 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 2576 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 2579 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 2582 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 2585 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 2588 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 2591 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 2594 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 2597 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha224, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 2600 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 2603 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 2606 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 2609 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 2613 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 2616 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 2619 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 2622 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 2625 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 2628 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 2631 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 2634 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 2637 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 2648 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 2651 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 2658 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 2665 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 2672 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 2678 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.ensureGraphPattern(), NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 2685 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.ensureGraphPattern(), NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 2692 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 2695 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 2699 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 2702 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  // x = new ArgList($2, driver.curExprList);
	  delete driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(7) - (5)].p_Expressions);
	  w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // $$ = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group-concat, $3, $4.p_Expression, $4.separator));
    }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 2712 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
	driver.countStar = true;
    }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 2720 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 2723 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 2726 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 2729 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 2732 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 2738 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 2744 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 2751 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 2761 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 2769 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 2777 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 2784 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 2788 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 2796 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 3592 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -797;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        81,  -120,   137,  -797,  -797,   288,  -797,  -797,  -797,  -797,
    -797,  -797,    66,    60,    60,    60,   106,     4,  -797,    66,
      60,    60,   108,   122,    60,   122,   133,  -797,   152,  -797,
    -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,
    -797,  -797,  -797,  -797,  -797,   111,   161,  -797,  -797,  -797,
     172,  -797,  -797,    61,   183,    61,  -797,  -797,  -797,  -797,
    -797,   148,  -797,  -797,  -797,  -797,    39,  -797,    35,    35,
    1028,  -797,  1028,  -797,    35,  -797,  -797,  -797,  -797,    58,
    -797,   145,   108,   108,  -797,   198,  -797,  -797,   188,  -797,
     183,  -797,  -797,    66,  -797,  -797,  -797,  -797,  -797,  -797,
    -797,  1028,  -797,  -797,    43,    -1,  -797,  -797,  -797,     0,
    -797,  -797,    97,    66,   105,  -797,  -797,  -797,  -797,  -797,
    -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,
    -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,   180,
    -797,  -797,   177,  -797,  -797,  -797,  -797,   185,  -797,  -797,
    -797,  -797,  -797,  -797,  -797,  -797,  -797,   -45,  -797,  -797,
     208,   139,  -797,  -797,  -797,  -797,  1501,    39,    91,  -797,
    -797,  -797,  -797,     7,  -797,  -797,    88,   210,  -797,  -797,
    -797,  -797,  -797,   237,  -797,   235,    39,   215,  -797,    66,
    -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,    35,
    -797,    35,    74,  -797,   294,  1028,  -797,  -797,    74,  1676,
      74,    66,  -797,  -797,  -797,  -797,  -797,    35,    12,  -797,
    1817,   236,   271,   272,   -11,    13,   276,   278,   279,     0,
     281,   289,   291,   292,   296,   302,   303,   304,   307,   309,
     319,    13,   321,  -797,  -797,  -797,  -797,   326,  -797,   328,
     330,   331,   190,   333,   194,   337,   340,   342,   360,   366,
     367,   368,   369,   372,   380,   382,   383,   384,   385,   386,
     387,   392,   394,   395,   396,   397,   399,  -797,  -797,  1933,
    -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,   400,
    -797,  -797,  -797,    19,   215,   406,  -797,  -797,     0,    11,
    -797,  -797,  -797,   201,  -797,  1028,  -797,  -797,   215,   418,
    -797,   243,  -797,  -797,  1004,  -797,  -797,  -797,   393,  1676,
    -797,  -797,   401,   443,  -797,  -797,  -797,  -797,  -797,  1052,
    -797,  -797,  -797,  -797,  -797,  -797,  -797,  1817,  2049,  2049,
    2049,  -797,   361,  -797,  -797,  -797,  -797,   298,  -797,  -797,
    -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,    19,
       0,  1817,  1817,  1817,  -797,  -797,  1817,  -797,  -797,  1817,
    1817,  1817,  -797,  1817,  1817,  1817,  1817,   -51,  1817,  1817,
    1817,  1817,  1817,  1817,  -797,   434,   434,  1817,  1817,  1817,
    -797,  1817,  -797,  1817,  1817,  1817,  1817,  1817,  1817,  1817,
    1817,  1817,  1817,  1817,  1817,  1817,  1817,  1817,  1817,  1817,
    1817,  1817,  1817,  1817,  1817,  -797,   434,   434,  -797,  -797,
    -797,  -797,    66,  -797,  -797,   280,  -797,  1167,  -797,  -797,
    1641,  -797,  -797,   350,  -797,  -797,   306,  -797,  -797,  -797,
    -797,  2165,  2287,   432,  -797,  -797,  -797,   420,  -797,  -797,
    -797,   415,  -797,  -797,  -797,  -797,  -797,  -797,  -797,  1028,
     148,  -797,  -797,   -13,   421,  -797,  -797,  -797,   -51,  -797,
     422,   411,   405,  1817,  1817,  1817,  1817,  1817,  1817,   402,
      13,  -797,  -797,   220,    25,  -797,  -797,  -797,   424,   425,
     426,  -797,   423,   429,   430,   431,   433,   435,   439,   440,
     436,   441,   445,   446,   448,   442,  -797,  1337,  1817,   450,
     451,   453,   454,   455,   456,   457,   452,   458,   461,   463,
     460,   470,   471,   472,   466,   477,   478,   480,   482,   483,
     485,   479,   487,   491,   492,  1817,  1817,  -797,  -797,    72,
    -797,  -797,  1384,  -797,  -797,   437,  -797,  -797,  -797,  -797,
    -797,  -797,  1384,  -797,  -797,   388,  -797,    23,  -797,    -4,
    1817,  2165,  -797,  -797,  -797,  -797,  2287,  -797,  -797,  -797,
    -797,  -797,   509,   179,  -797,   152,  -797,   232,  1028,  -797,
    -797,    74,    56,   489,   488,  -797,  -797,  -797,  -797,  -797,
    -797,  -797,  -797,  -797,  1817,  -797,  1817,  -797,  -797,  -797,
    -797,  -797,  -797,  -797,    13,  -797,  1817,  1817,    25,  -797,
    -797,  -797,  1817,  1817,  -797,  -797,  -797,  -797,  -797,  1817,
    1817,  1817,  -797,  -797,  1817,  -797,  -797,  1817,  -797,  -797,
    -797,  -797,  1817,  -797,  -797,   500,  -797,  -797,  -797,  -797,
    -797,  -797,  -797,  -797,  1817,  -797,  -797,  -797,  1817,  -797,
    -797,  -797,  1817,  -797,  -797,  -797,  -797,  -797,  -797,  1817,
    -797,  -797,  -797,   501,  -797,  -797,  -797,  -797,  -797,  -797,
    -797,  -797,   -47,  -797,  -797,  -797,    85,  -797,  -797,  -797,
     361,  -797,  -797,  1617,   389,   390,  -797,  -797,   516,   518,
    -797,  -797,  -797,  -797,  -797,  2287,   507,     0,  -797,  -797,
     401,  -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,
    -797,  -797,  -797,    40,  -797,   -15,    47,  -797,  -797,  -797,
    -797,  -797,  -797,  -797,  -797,  -797,    33,  -797,  -797,  -797,
      74,  -797,  1676,  -797,   512,  1384,  -797,  -797,  -797,  -797,
    -797,  -797,  -797,  -797,  -797,     9,   504,   517,   519,   520,
     522,   511,  -797,   508,   523,   511,   524,   527,  -797,  -797,
    -797,  -797,  -797,  1167,  -797,  -797,  1641,   530,  -797,  -797,
    1617,  -797,   532,  -797,  -797,  -797,  -797,  -797,  -797,  -797,
    -797,  -797,  -797,   534,  -797,  -797,     0,  -797,  -797,  1817,
    -797,  1028,     0,   535,    53,  -797,    83,  -797,  -797,  -797,
    -797,  -797,  -797,  1676,   473,   407,  -797,   -18,  -797,  -797,
    -797,  -797,  -797,  -797,  -797,  1676,  -797,  -797,  1604,  -797,
    -797,  1817,  -797,  1817,  -797,  -797,  -797,  -797,  -797,   536,
     503,  -797,   540,  -797,   543,  -797,  -797,    82,  2150,  -797,
    -797,  -797,  -797,  -797,   215,   148,  -797,  -797,     0,   496,
    -797,  -797,  -797,  -797,   545,  -797,  -797,  -797,  -797,  -797,
      40,  -797,    40,  -797,   428,  -797,  -797,    62,  -797,  1028,
    -797,  -797,  -797,   546,  -797,   537,  -797,  -797,  -797,  -797,
    -797,   542,   117,   133,  -797,    60,  -797,   -51,   547,  -797,
     493,   548,  -797,  -797,   554,  -797,    -9,  -797,   559,  -797,
     100,  -797,  -797,  1384,  1384,  -797,     0,   148,   558,  -797,
    -797,    53,  -797,    56,  -797,  -797,  -797,  -797,   563,  -797,
    -797,  -797,  -797,  -797,     0,  -797,     0,  -797,  -797,  -797,
    -797,  -797,  -797,  -797,  1676,  -797
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        13,     0,     0,     2,     4,   210,    15,    14,     3,   174,
      67,     1,     0,   198,   198,   198,     0,     0,    73,     0,
     198,   198,     0,     0,   198,     0,    10,     6,     0,     7,
       8,     9,   175,   182,   183,   184,   188,   185,   186,   187,
     189,   190,   191,   192,   211,     0,    17,   582,   585,   584,
     195,   583,   199,     0,     0,     0,   313,   100,   106,   426,
     427,   105,    73,   103,   424,   425,   117,   209,   225,   225,
     235,   207,   235,   206,   225,   205,   157,     5,    11,    82,
      73,   180,     0,     0,   216,   212,   215,    68,    12,    16,
       0,   196,   193,     0,   230,   229,   231,   228,   197,   201,
     200,   315,    73,   104,   107,     0,   118,    74,   109,     0,
     226,   223,     0,     0,     0,   411,   412,   413,   414,   415,
     408,   576,   577,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   578,   580,   579,   581,   586,   587,   433,     0,
     240,   236,   248,   323,   407,   406,   417,     0,   321,   422,
     423,   429,   430,   564,   565,   566,   431,   562,   428,   432,
       0,     0,   159,    80,    81,    83,     0,   117,    13,   181,
     176,   218,   219,     0,   214,   213,     0,     0,    18,    23,
      19,   194,   227,     0,   316,   319,   117,   120,   108,     0,
     110,   111,   112,   113,   115,   254,   251,   116,   250,   225,
     224,   225,     0,   232,   234,   235,   249,   246,   333,   416,
       0,     0,   560,   561,   563,   558,   233,   225,     0,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   547,   548,   549,   550,     0,   551,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    98,
      79,    91,    88,    90,   530,   498,   531,   532,    89,     0,
      92,    93,    94,     0,   120,   210,   178,   179,     0,     0,
     217,    69,    21,     0,   314,   315,   320,   317,   120,     0,
     102,   122,   121,   114,   257,   202,   204,   341,     0,   416,
     340,   241,   237,     0,   247,   334,   324,   332,   421,   416,
     418,   420,   322,   559,   203,   166,   160,     0,     0,     0,
       0,   481,    85,   434,   437,   441,   443,   445,   455,   466,
     469,   474,   475,   476,   482,   477,   478,   479,   480,   556,
       0,     0,     0,     0,   534,   491,     0,   310,   520,     0,
       0,     0,   539,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   497,   305,   305,     0,     0,     0,
     492,     0,   513,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,   305,   305,   302,   301,
      72,   208,     0,   220,   221,     0,    56,     0,    31,    45,
       0,    20,    24,     0,    29,    25,     0,    43,    26,   318,
     101,     0,     0,   124,   123,   252,    76,     0,   253,   260,
     258,   264,   344,   342,   409,   330,   337,   339,   238,   235,
       0,   410,   419,     0,     0,   472,   473,   471,     0,    86,
       0,   435,   439,     0,     0,     0,     0,     0,     0,     0,
       0,   444,   446,   456,   468,   557,   555,   540,     0,     0,
       0,   311,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   306,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   222,    70,     0,
     172,    35,    36,    32,    33,     0,   173,   169,   170,   171,
     168,    49,    50,    46,    47,     0,    29,     0,    43,     0,
       0,   128,   129,   132,   134,   131,   135,   136,   138,   300,
     298,   299,     0,   126,   125,     0,   255,   290,   257,   265,
     262,   333,     0,   325,   335,   239,   243,   158,   163,   165,
     167,   483,    84,    87,     0,   438,     0,   442,   447,   448,
     449,   450,   451,   452,     0,   453,     0,     0,   461,   467,
     457,   458,     0,     0,   470,   489,   490,   533,   308,     0,
       0,     0,   484,   485,     0,   487,   488,     0,   525,   526,
     527,   528,     0,   545,   546,     0,   543,   529,   514,   506,
     519,   512,   496,   518,     0,   511,   495,   510,     0,   517,
     509,   502,     0,   494,   508,   501,   493,   500,   516,     0,
     499,   515,   507,     0,   303,    55,    58,    57,    34,    39,
      48,    53,     0,    28,    37,    30,     0,    42,    51,    44,
      85,   130,   137,     0,     0,     0,   119,   127,   151,   153,
      77,   278,   282,   276,   287,     0,     0,     0,   273,   261,
     237,   274,   267,   269,   270,   272,   268,   266,   291,   271,
     263,   357,   345,     0,   387,     0,     0,   343,   346,   348,
     349,   358,   360,   363,   372,   367,   370,   385,   359,   386,
     327,   331,   416,   338,     0,     0,   436,   440,   454,   463,
     464,   462,   465,   459,   460,     0,     0,     0,     0,     0,
       0,   536,   541,   553,     0,   536,     0,     0,   542,   308,
      63,    40,    27,     0,    54,    41,     0,     0,   144,   145,
     139,   140,     0,   142,   143,   147,   148,   155,   156,   149,
     152,   150,   154,   117,   279,   283,     0,   288,   297,     0,
     275,   257,     0,     0,   395,   403,     0,   388,   390,   397,
     399,   402,   373,   416,   361,   365,   381,     0,   383,   382,
     369,   371,   374,   328,   329,   416,   336,   244,     0,   161,
     312,     0,   309,     0,   522,   523,   486,   524,   537,     0,
       0,   554,     0,   503,     0,   504,   505,     0,     0,    38,
      52,   133,   141,   146,   120,     0,   284,   277,     0,     0,
     259,   295,   389,   396,     0,   392,   401,   404,   400,   355,
       0,   364,     0,   368,     0,   405,   384,     0,   326,   235,
     164,   162,   307,     0,   535,     0,   544,   538,   304,    59,
      64,    60,     0,    10,   280,   198,   289,     0,   292,   398,
     394,   347,   362,   366,     0,   378,     0,   379,     0,   521,
       0,    61,    62,     0,     0,    78,     0,     0,     0,   293,
     296,     0,   393,   352,   356,   380,   375,   377,     0,   245,
     552,    66,    65,   281,     0,   286,     0,   391,   350,   353,
     354,   376,   285,   294,   416,   351
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -797,  -797,  -797,  -797,  -797,  -281,   444,  -797,  -797,  -797,
    -797,  -797,  -797,  -797,  -797,  -797,    49,  -797,   175,  -797,
    -156,  -797,  -797,    67,  -797,  -797,    52,  -797,   178,  -797,
    -155,  -797,  -797,    64,  -797,  -797,  -797,  -797,  -797,  -797,
    -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,   102,
    -797,  -797,  -797,  -797,    38,  -797,  -797,  -797,   -63,  -797,
     341,  -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,
    -797,  -797,  -797,  -797,   449,  -103,  -797,  -288,  -797,  -797,
    -797,  -797,  -797,  -797,    68,  -797,  -797,    55,  -797,  -797,
    -151,  -797,  -797,  -797,  -797,  -797,  -797,   -67,   -60,    48,
    -797,  -797,  -797,  -797,  -797,  -797,  -397,  -797,   462,  -797,
    -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,    -5,  -797,
    -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,
    -797,  -797,  -797,  -797,   549,  -797,  -797,   -29,  -797,     2,
     576,   206,   607,   565,  -203,   -65,  -797,  -797,  -797,  -797,
    -797,  -797,  -797,  -797,  -797,  -212,  -797,  -797,  -797,  -797,
    -565,  -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,
    -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,
    -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,  -797,  -632,
    -158,   282,  -797,  -309,  -681,  -119,  -237,  -797,  -797,  -797,
     334,  -797,  -797,  -797,   -87,  -797,  -797,   -83,  -797,  -797,
    -797,  -797,  -797,    63,  -772,  -797,  -797,   -89,   -85,  -797,
    -797,  -797,  -797,  -797,  -267,  -797,  -797,  -797,  -797,  -797,
    -797,  -797,  -797,   -66,  -797,  -797,  -797,  -211,  -797,  -797,
     -68,  -797,  -210,  -797,  -797,  -797,  -797,  -797,  -797,  -797,
    -797,  -797,  -797,  -797,  -797,  -797,  -762,  -797,  -797,  -796,
    -197,  -797,  -797,  -797,  -797,  -797,  -797,  -183,  -188,   -14,
       1,  -797,   744,  -797,  -797,  -797,    57,  -797,  -797,    54,
    -797,  -797,  -797,   -81,  -797,  -797,    45,  -797,  -797,  -797,
    -315,  -797,  -318,   -54,  -431,  -128,  -797,  -797,  -101,  -797,
    -797,  -797,  -129,  -797,  -797,  -797,  -797,  -797,  -797,  -797,
      46,  -797,  -797,  -797,   174,  -797,   173,   176,   196,  -243,
     -12,  -797,  -797
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,    26,    77,     5,     6,    46,    88,
     178,   303,   179,   180,   431,   432,   557,   433,   434,   542,
     543,   675,   763,   544,   762,   435,   559,   436,   437,   552,
     553,   679,   766,   554,   765,   438,   539,   667,   760,   902,
     880,   838,   881,     7,    89,   176,   425,    27,    28,    66,
     445,   446,   575,   783,    80,   165,   166,   469,   470,   277,
     278,   279,   280,    29,   102,    30,    61,    62,   187,    31,
     107,   190,   191,   192,   193,   108,   109,   310,   311,   443,
     573,   686,   312,   561,   562,   444,   566,   567,   574,   770,
     771,   772,   773,   774,   687,   779,   781,   688,   689,    78,
     162,   218,   818,   590,   735,   463,   545,     8,     9,    81,
     297,   169,   170,    32,    33,    91,    92,    34,    53,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
     174,    84,   173,    85,    86,   300,   423,   112,   113,    97,
      98,    71,    73,   139,   140,   459,   321,   204,   322,   323,
     734,   869,   141,   206,   207,   197,   447,   198,   314,   448,
     449,   699,   577,   450,   579,   580,   700,   701,   702,   786,
     703,   784,   845,   906,   704,   785,   846,   885,   705,   706,
     787,   848,   707,   708,   792,   910,   926,   888,   709,   568,
     569,   419,   759,   507,   822,   745,   368,   618,    57,   101,
     183,   184,   306,   307,   142,   210,   208,   325,   813,   814,
     731,   583,   326,   327,   455,   733,   584,   456,   319,   451,
     582,   581,   717,   803,   718,   929,   934,   930,   914,   891,
     712,   719,   720,   721,   722,   861,   804,   723,   863,   805,
     724,   810,   725,   811,   917,   897,   866,   812,   726,   727,
     797,   912,   890,   853,   854,   798,   799,   857,   800,   867,
     143,   144,   202,   145,   146,   147,   329,   457,   148,   320,
     341,   150,   342,   343,   595,   471,   344,   597,   472,   345,
     346,   481,   482,   347,   348,   608,   614,   742,   609,   483,
     349,   484,   350,   351,   352,   353,   365,   284,   829,   285,
     286,   287,   354,   753,   635,   289,   831,   832,   355,   486,
     356,   213,   214,   215,   357,   153,   154,   155,   358,   157,
     359,    51,   159
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SPARQLfedParser::yytable_ninf_ = -417;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        50,   188,   324,    63,   384,    65,   420,    67,   281,    54,
      55,   570,   328,   710,   185,    68,    69,   372,    64,    74,
     440,   331,   189,    58,   587,   794,   330,   588,   916,   363,
     864,   859,   855,   555,   422,   795,   195,   288,   283,   677,
     114,   110,   211,   868,   612,   161,   298,   103,   335,    65,
     820,   775,   806,   366,    10,   674,    99,   821,   158,   417,
     158,   105,    64,   788,   294,   105,   673,    93,   894,   807,
     828,   149,    52,   149,   828,   163,   164,   508,   106,  -117,
     713,   182,   106,   308,    94,   796,   421,   713,   613,   158,
     714,  -177,   181,   194,   808,     1,   713,   714,   761,   895,
     918,   200,   149,   795,   715,     1,   714,   535,   536,   665,
     896,   715,   666,   299,    82,    83,   151,   452,   151,   318,
     715,   281,   328,   878,   317,   674,   453,   332,    59,    60,
     821,   331,   328,   856,   809,   570,   212,    11,   775,   111,
     716,   331,    56,   865,    70,   678,   462,   151,   487,   927,
     288,   283,   865,   796,   293,   555,   716,   196,    72,    47,
      48,    49,   935,    76,   104,    95,    96,   282,    79,   589,
     315,   364,   316,    47,    48,    49,    87,   194,    47,    48,
      49,    90,   167,    59,    60,    47,    48,    49,   334,    93,
      65,    59,    60,   158,   168,   367,    65,   158,    65,   333,
    -117,   418,    83,    64,   186,   199,   149,   684,   685,    64,
     149,    64,   290,   201,    47,    48,    49,   203,   185,   336,
     205,    47,    48,    49,   -22,   209,   850,    47,    48,    49,
      47,    48,    49,   764,   678,    59,    60,   426,   691,   692,
      47,    48,    49,   605,   152,   216,   152,   217,    47,    48,
      49,   151,   570,    59,    60,   151,   585,    47,    48,    49,
     903,   904,    76,   301,   570,   302,   156,   293,   156,  -256,
     132,   133,   134,   135,   304,   152,   693,   694,   305,   695,
     282,   606,   607,   563,   465,   466,   467,   424,   171,   172,
     -22,   739,   740,   158,   743,   744,    12,   156,    13,    14,
    -242,    15,   158,   427,   -71,   309,   149,   158,    16,    17,
     360,   361,   362,   565,   571,   149,   369,   158,   370,   371,
     149,   373,    47,    48,    49,   290,    18,    59,    60,   374,
     149,   375,   376,   -22,   442,   -22,   377,   -22,   819,   570,
     291,   843,   378,   379,   380,   177,   428,   381,   429,   382,
     430,   151,   696,   473,   474,   475,   476,   477,   478,   383,
     151,   385,   292,   479,   480,   151,   386,   738,   387,   555,
     388,   389,   390,   391,   697,   151,   392,   393,   499,   152,
     394,   452,   395,   152,   126,   127,   128,   129,   130,   131,
     453,    19,   598,   599,   600,   601,   602,   603,    20,    21,
     396,   156,    22,   563,    23,   156,   397,   398,   399,   400,
     537,    24,   401,    25,    12,   550,    13,    14,   550,    15,
     402,   871,   403,   404,   405,   406,   407,   408,   546,   293,
     293,   546,   409,   565,   410,   411,   412,   413,   571,   414,
     416,   882,   564,   441,   458,   454,   586,   158,    65,   460,
     468,   506,   427,   291,   538,   430,   572,   576,   578,   596,
     149,    64,   591,   593,   594,   615,   616,   617,   604,   592,
     862,   619,   622,   547,   623,   292,   547,   620,   621,   152,
     625,   626,   628,   624,   627,   790,   629,   630,   152,   631,
     632,   637,   638,   152,   639,   640,   641,   642,   643,   645,
     644,   156,   646,   152,   647,   151,   921,   922,   648,    19,
     156,   649,   650,   651,   652,   156,    20,    21,   653,   654,
      22,   655,    23,   656,   657,   156,   658,   659,   660,    24,
     550,    25,   661,   662,   683,   328,   732,   671,   730,   669,
     550,   752,   758,   546,   331,   685,   684,   789,   817,   293,
     777,   778,   823,   546,   293,   571,   883,   830,   824,   821,
     825,   826,   564,   827,   833,   835,   158,   571,   836,    65,
     729,   841,   337,   106,   847,   860,   852,   874,   875,   149,
     851,   876,    64,   728,   877,   887,   889,   899,   547,   865,
     901,   915,   900,   909,   452,   911,   919,   913,   547,   925,
     931,   548,   905,   453,   548,   672,   328,   839,   556,   668,
     676,   840,   295,   690,   558,   331,   670,   767,   328,   842,
     415,   682,   782,   549,   151,   698,   549,   331,   780,   681,
     296,   100,    75,   152,   175,   791,   886,   160,   313,   439,
     837,   485,   571,   816,   711,   815,   928,   793,   802,   892,
     737,   736,   893,   741,   834,   156,   610,   920,     0,   611,
       0,     0,     0,     0,     0,     0,   898,     0,     0,     0,
       0,   293,     0,     0,     0,     0,     0,     0,     0,     0,
     844,     0,     0,   293,   776,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   923,     0,     0,     0,     0,     0,
       0,   729,     0,   801,   729,     0,     0,     0,     0,     0,
       0,     0,   932,     0,   933,     0,   548,     0,    65,     0,
     158,     0,     0,   550,     0,     0,   548,     0,     0,     0,
       0,    64,     0,   149,     0,     0,   546,   328,   549,     0,
       0,     0,     0,     0,     0,     0,   331,     0,   549,     0,
       0,   550,   152,     0,   550,     0,     0,     0,   293,     0,
       0,     0,     0,     0,   546,     0,     0,   546,     0,     0,
       0,   776,     0,     0,   156,     0,     0,     0,   151,   158,
       0,   547,   801,     0,   858,     0,     0,     0,     0,     0,
       0,   158,   149,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   158,   149,     0,   550,     0,     0,   547,
       0,     0,   547,     0,     0,     0,   149,     0,     0,   546,
       0,     0,     0,     0,     0,     0,   550,     0,     0,     0,
       0,   884,     0,    65,     0,     0,     0,   151,     0,   546,
       0,     0,     0,     0,     0,     0,    64,     0,   729,   151,
     729,     0,     0,     0,     0,     0,     0,   158,     0,     0,
       0,   151,     0,     0,   547,     0,     0,     0,     0,     0,
     149,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     907,     0,     0,     0,   547,     0,     0,     0,   908,     0,
       0,   550,   550,   924,     0,    65,     0,     0,     0,   801,
       0,   729,     0,     0,   546,   546,   152,     0,    64,   548,
       0,     0,     0,     0,   728,   151,     0,     0,     0,     0,
       0,     0,   158,     0,     0,     0,     0,     0,   156,     0,
       0,   549,     0,     0,     0,   149,     0,   548,     0,     0,
     548,     0,     0,     0,     0,     0,     0,     0,     0,   547,
     547,     0,     0,     0,     0,     0,     0,     0,     0,   549,
       0,     0,   549,     0,     0,   152,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   152,     0,     0,
     151,     0,     0,     0,     0,     0,     0,   156,     0,   152,
       0,     0,   548,     0,     0,     0,     0,     0,     0,   156,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   156,   548,     0,   549,     0,     0,     0,     0,     0,
     -75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   549,   115,   116,   117,   118,   119,
       0,     0,     0,   152,  -416,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   120,     0,     0,     0,   115,
     116,   117,   118,   119,     0,   156,     0,     0,  -416,     0,
       0,     0,     0,     0,     0,     0,     0,   548,   548,   120,
       0,   464,     0,   115,   116,   117,   118,   119,     0,     0,
       0,     0,     0,   461,     0,     0,     0,     0,     0,   549,
     549,     0,     0,   120,     0,   488,   489,   490,   152,     0,
     491,     0,     0,   492,   493,   494,     0,   495,   496,   497,
     498,     0,   500,   501,   502,   503,   504,   505,     0,     0,
     156,   509,   510,   511,     0,   512,     0,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,     0,
       0,     0,     0,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    47,    48,
      49,   136,   137,    59,    60,     0,   138,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    47,    48,    49,   136,   137,    59,    60,   540,
     138,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    47,    48,    49,   136,
     137,    59,    60,     0,   138,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   634,   636,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   541,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   663,
     664,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   680,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    47,    48,    49,     0,     0,    59,    60,     0,     0,
       0,     0,     0,     0,     0,     0,   633,     0,     0,     0,
       0,     0,     0,   746,   747,   748,     0,     0,   749,     0,
       0,   750,     0,     0,     0,     0,   751,   337,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   754,     0,
       0,     0,   755,     0,     0,     0,   756,     0,   338,   339,
       0,   340,   221,   757,   222,   223,   224,   225,   226,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     0,   241,   540,     0,     0,   242,
     243,   244,   245,   246,   247,   248,   249,     0,     0,     0,
       0,     0,     0,     0,   250,     0,   251,     0,     0,   252,
     253,     0,   254,     0,   255,   256,   257,     0,   258,   259,
       0,   260,     0,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    47,    48,    49,     0,     0,    59,    60,     0,     0,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   849,     0,     0,     0,     0,     0,     0,
       0,   220,     0,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    47,    48,
      49,     0,     0,    59,    60,   872,   221,   873,   222,   223,
     224,   225,   226,   227,   228,   229,     0,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,     0,   241,
       0,     0,     0,   242,   243,   244,   245,   246,   247,   248,
     249,     0,     0,     0,     0,     0,     0,     0,   250,     0,
     251,     0,     0,   252,   253,     0,   254,     0,   255,   256,
     257,     0,   258,   259,     0,   260,     0,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   768,   769,   870,   540,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   337,     0,     0,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    47,    48,    49,     0,     0,
      59,    60,   221,   540,   222,   223,   224,   225,   226,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     0,   241,     0,   115,   116,   117,
     118,   119,     0,     0,     0,     0,   249,     0,     0,     0,
       0,     0,     0,     0,   250,     0,   251,   120,     0,   252,
     253,     0,   254,     0,   255,   256,   257,     0,   258,   259,
       0,   260,     0,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,     0,
       0,     0,     0,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    47,    48,
      49,     0,     0,    59,    60,     0,     0,     0,     0,     0,
     551,    47,    48,    49,     0,     0,    59,    60,     0,     0,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    47,    48,    49,     0,     0,
      59,    60,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      47,    48,    49,   136,   137,    59,    60,   337,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   338,   339,
       0,   340,   221,     0,   222,   223,   224,   225,   226,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     0,   241,     0,     0,     0,   242,
     243,   244,   245,   246,   247,   248,   249,     0,     0,     0,
       0,     0,     0,     0,   250,     0,   251,     0,     0,   252,
     253,     0,   254,     0,   255,   256,   257,     0,   258,   259,
       0,   260,     0,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,     0,     0,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    47,    48,    49,     0,     0,    59,    60,   221,     0,
     222,   223,   224,   225,   226,   227,   228,   229,     0,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
       0,   241,     0,     0,     0,   242,   243,   244,   245,   246,
     247,   248,   249,     0,     0,     0,     0,     0,     0,     0,
     250,     0,   251,     0,     0,   252,   253,     0,   254,     0,
     255,   256,   257,     0,   258,   259,     0,   260,     0,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   337,
       0,     0,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    47,    48,    49,
       0,     0,    59,    60,   221,     0,   222,   223,   224,   225,
     226,   227,   228,   229,     0,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,     0,   241,     0,     0,
       0,   242,   243,   244,   245,   246,   247,   248,   249,     0,
       0,     0,     0,     0,     0,     0,   250,     0,   251,     0,
       0,   252,   253,     0,   254,     0,   255,   256,   257,     0,
     258,   259,     0,   260,     0,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   879,   540,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   560,     0,     0,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    47,    48,    49,     0,     0,    59,    60,
     221,     0,   222,   223,   224,   225,   226,   227,   228,   229,
       0,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,     0,   241,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   249,     0,     0,     0,     0,     0,
       0,     0,   250,     0,   251,     0,     0,   252,   253,     0,
     254,     0,   255,   256,   257,     0,   258,   259,     0,   260,
       0,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,     0,     0,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    47,    48,    49,   337,     0,    59,
      60,     0,     0,     0,     0,     0,     0,     0,     0,    47,
      48,    49,     0,     0,    59,    60,     0,     0,     0,     0,
       0,     0,   221,     0,   222,   223,   224,   225,   226,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     0,   241,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   249,     0,     0,     0,
       0,     0,     0,     0,   250,     0,   251,     0,     0,   252,
     253,     0,   254,     0,   255,   256,   257,     0,   258,   259,
       0,   260,     0,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,    48,    49
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        12,   104,   205,    17,   241,    17,   294,    19,   166,    14,
      15,   442,   209,   578,   101,    20,    21,   229,    17,    24,
     308,   209,    23,    19,    37,    40,   209,    40,    37,    40,
      48,   803,   794,   430,    23,    50,    36,   166,   166,    43,
      69,     6,    87,   815,    19,    74,    39,    61,    36,    61,
      41,   683,    19,    40,   174,   102,    54,    48,    70,    40,
      72,    22,    61,   695,   167,    22,    43,     6,   864,    36,
     751,    70,    12,    72,   755,    17,    18,   386,    39,    36,
      40,    93,    39,   186,    23,   100,   298,    40,    63,   101,
      50,     0,    90,   105,    61,    14,    40,    50,   145,    37,
     896,   113,   101,    50,    64,    14,    50,   416,   417,    37,
      48,    64,    40,   106,     3,     4,    70,   314,    72,   202,
      64,   279,   319,    41,    50,   102,   314,   210,   179,   180,
      48,   319,   329,    50,   101,   566,   181,     0,   770,   104,
     100,   329,    36,   161,    36,   149,   329,   101,   360,   911,
     279,   279,   161,   100,   166,   552,   100,   157,    36,   174,
     175,   176,   934,    30,    62,   104,   105,   166,    16,   182,
     199,   182,   201,   174,   175,   176,    15,   189,   174,   175,
     176,     9,    80,   179,   180,   174,   175,   176,   217,     6,
     202,   179,   180,   205,    49,   182,   208,   209,   210,   211,
     157,   182,     4,   202,   102,   108,   205,    28,    29,   208,
     209,   210,   166,   108,   174,   175,   176,    37,   305,   218,
      43,   174,   175,   176,    36,    40,   791,   174,   175,   176,
     174,   175,   176,   148,   149,   179,   180,    36,     6,     7,
     174,   175,   176,   480,    70,    37,    72,   108,   174,   175,
     176,   205,   683,   179,   180,   209,   459,   174,   175,   176,
     143,   144,    30,   175,   695,    55,    70,   279,    72,    37,
     170,   171,   172,   173,    37,   101,    44,    45,    43,    47,
     279,    61,    62,   441,   338,   339,   340,   299,    82,    83,
     102,   606,   607,   305,   612,   613,     8,   101,    10,    11,
       6,    13,   314,   102,    16,    90,   305,   319,    20,    21,
      74,    40,    40,   441,   442,   314,    40,   329,    40,    40,
     319,    40,   174,   175,   176,   279,    38,   179,   180,    40,
     329,    40,    40,   145,    91,   147,    40,   149,   735,   770,
     166,   772,    40,    40,    40,   157,   145,    40,   147,    40,
     149,   305,   120,    55,    56,    57,    58,    59,    60,    40,
     314,    40,   166,    65,    66,   319,    40,   604,    40,   766,
      40,    40,   182,    40,   142,   329,   182,    40,   377,   205,
      40,   578,    40,   209,   164,   165,   166,   167,   168,   169,
     578,   103,   473,   474,   475,   476,   477,   478,   110,   111,
      40,   205,   114,   561,   116,   209,    40,    40,    40,    40,
     422,   123,    40,   125,     8,   427,    10,    11,   430,    13,
      40,   818,    40,    40,    40,    40,    40,    40,   427,   441,
     442,   430,    40,   561,    40,    40,    40,    40,   566,    40,
      40,   838,   441,    25,    43,    52,   460,   459,   460,     6,
      89,    17,   102,   279,   174,   149,    24,    37,    43,    54,
     459,   460,    41,    41,    53,    41,    41,    41,    66,   468,
      63,    48,    41,   427,    41,   279,   430,    48,    48,   305,
      41,    41,    41,    48,    48,   697,    41,    41,   314,    41,
      48,    41,    41,   319,    41,    41,    41,    41,    41,    41,
      48,   305,    41,   329,    41,   459,   903,   904,    48,   103,
     314,    41,    41,    41,    48,   319,   110,   111,    41,    41,
     114,    41,   116,    41,    41,   329,    41,    48,    41,   123,
     542,   125,    41,    41,    25,   732,    48,   149,    49,   102,
     552,    41,    41,   542,   732,    29,    28,    40,    36,   561,
     161,   161,    48,   552,   566,   683,   844,    49,    41,    48,
      41,    41,   561,    41,    41,    41,   578,   695,    41,   581,
     582,    41,    40,    39,   786,   102,    41,    41,    75,   578,
     792,    41,   581,   582,    41,    89,    41,    41,   542,   161,
      48,    37,    55,    46,   791,   102,    37,    49,   552,    41,
      37,   427,   883,   791,   430,   556,   803,   763,   433,   542,
     558,   766,   168,   575,   436,   803,   552,   680,   815,   770,
     279,   566,   689,   427,   578,   577,   430,   815,   688,   561,
     168,    55,    25,   459,    85,   700,   848,    72,   189,   305,
     759,   359,   770,   732,   581,   730,   913,   713,   716,   860,
     596,   594,   862,   608,   755,   459,   483,   900,    -1,   483,
      -1,    -1,    -1,    -1,    -1,    -1,   869,    -1,    -1,    -1,
      -1,   683,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     783,    -1,    -1,   695,   683,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   906,    -1,    -1,    -1,    -1,    -1,
      -1,   713,    -1,   715,   716,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   924,    -1,   926,    -1,   542,    -1,   730,    -1,
     732,    -1,    -1,   735,    -1,    -1,   552,    -1,    -1,    -1,
      -1,   730,    -1,   732,    -1,    -1,   735,   934,   542,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   934,    -1,   552,    -1,
      -1,   763,   578,    -1,   766,    -1,    -1,    -1,   770,    -1,
      -1,    -1,    -1,    -1,   763,    -1,    -1,   766,    -1,    -1,
      -1,   770,    -1,    -1,   578,    -1,    -1,    -1,   732,   791,
      -1,   735,   794,    -1,   796,    -1,    -1,    -1,    -1,    -1,
      -1,   803,   791,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   815,   803,    -1,   818,    -1,    -1,   763,
      -1,    -1,   766,    -1,    -1,    -1,   815,    -1,    -1,   818,
      -1,    -1,    -1,    -1,    -1,    -1,   838,    -1,    -1,    -1,
      -1,   845,    -1,   845,    -1,    -1,    -1,   791,    -1,   838,
      -1,    -1,    -1,    -1,    -1,    -1,   845,    -1,   860,   803,
     862,    -1,    -1,    -1,    -1,    -1,    -1,   869,    -1,    -1,
      -1,   815,    -1,    -1,   818,    -1,    -1,    -1,    -1,    -1,
     869,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     885,    -1,    -1,    -1,   838,    -1,    -1,    -1,   887,    -1,
      -1,   903,   904,   907,    -1,   907,    -1,    -1,    -1,   911,
      -1,   913,    -1,    -1,   903,   904,   732,    -1,   907,   735,
      -1,    -1,    -1,    -1,   913,   869,    -1,    -1,    -1,    -1,
      -1,    -1,   934,    -1,    -1,    -1,    -1,    -1,   732,    -1,
      -1,   735,    -1,    -1,    -1,   934,    -1,   763,    -1,    -1,
     766,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   903,
     904,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   763,
      -1,    -1,   766,    -1,    -1,   791,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   803,    -1,    -1,
     934,    -1,    -1,    -1,    -1,    -1,    -1,   791,    -1,   815,
      -1,    -1,   818,    -1,    -1,    -1,    -1,    -1,    -1,   803,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   815,   838,    -1,   818,    -1,    -1,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   838,    31,    32,    33,    34,    35,
      -1,    -1,    -1,   869,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    -1,   869,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   903,   904,    51,
      -1,   337,    -1,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,   903,
     904,    -1,    -1,    51,    -1,   361,   362,   363,   934,    -1,
     366,    -1,    -1,   369,   370,   371,    -1,   373,   374,   375,
     376,    -1,   378,   379,   380,   381,   382,   383,    -1,    -1,
     934,   387,   388,   389,    -1,   391,    -1,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,    -1,
      -1,    -1,    -1,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,    -1,   182,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,    42,
     182,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,    -1,   182,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   507,   508,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   535,
     536,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   560,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,    -1,    -1,   179,   180,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,
      -1,    -1,    -1,   619,   620,   621,    -1,    -1,   624,    -1,
      -1,   627,    -1,    -1,    -1,    -1,   632,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   644,    -1,
      -1,    -1,   648,    -1,    -1,    -1,   652,    -1,    61,    62,
      -1,    64,    65,   659,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    42,    -1,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,    -1,   109,    -1,    -1,   112,
     113,    -1,   115,    -1,   117,   118,   119,    -1,   121,   122,
      -1,   124,    -1,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,    -1,    -1,   179,   180,    -1,    -1,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   789,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    -1,    -1,   179,   180,   821,    65,   823,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    88,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,
     109,    -1,    -1,   112,   113,    -1,   115,    -1,   117,   118,
     119,    -1,   121,   122,    -1,   124,    -1,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,    26,    27,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,    -1,    -1,
     179,   180,    65,    42,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    -1,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,    -1,   109,    51,    -1,   112,
     113,    -1,   115,    -1,   117,   118,   119,    -1,   121,   122,
      -1,   124,    -1,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    -1,    -1,   179,   180,    -1,    -1,    -1,    -1,    -1,
     149,   174,   175,   176,    -1,    -1,   179,   180,    -1,    -1,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,    -1,    -1,
     179,   180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    40,   182,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      -1,    64,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,    -1,   109,    -1,    -1,   112,
     113,    -1,   115,    -1,   117,   118,   119,    -1,   121,   122,
      -1,   124,    -1,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,    -1,    -1,   179,   180,    65,    -1,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    -1,    -1,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,   109,    -1,    -1,   112,   113,    -1,   115,    -1,
     117,   118,   119,    -1,   121,   122,    -1,   124,    -1,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    -1,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
      -1,    -1,   179,   180,    65,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    -1,    -1,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,   109,    -1,
      -1,   112,   113,    -1,   115,    -1,   117,   118,   119,    -1,
     121,   122,    -1,   124,    -1,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,    -1,    -1,   179,   180,
      65,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   107,    -1,   109,    -1,    -1,   112,   113,    -1,
     115,    -1,   117,   118,   119,    -1,   121,   122,    -1,   124,
      -1,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,    -1,    -1,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    40,    -1,   179,
     180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,
     175,   176,    -1,    -1,   179,   180,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,    -1,   109,    -1,    -1,   112,
     113,    -1,   115,    -1,   117,   118,   119,    -1,   121,   122,
      -1,   124,    -1,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   174,   175,   176
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
      42,   102,   202,   203,   206,   289,   453,   493,   497,   501,
     503,   149,   212,   213,   216,   289,   201,   199,   211,   209,
      40,   266,   267,   373,   453,   478,   269,   270,   372,   373,
     477,   478,    24,   263,   271,   235,    37,   345,    43,   347,
     348,   404,   403,   394,   399,   327,   452,    37,    40,   182,
     286,    41,   453,    41,    53,   457,    54,   460,   466,   466,
     466,   466,   466,   466,    66,   379,    61,    62,   468,   471,
     499,   500,    19,    63,   469,    41,    41,    41,   380,    48,
      48,    48,    41,    41,    48,    41,    41,    48,    41,    41,
      41,    41,    48,    19,   455,   487,   455,    41,    41,    41,
      41,    41,    41,    41,    48,    41,    41,    41,    48,    41,
      41,    41,    48,    41,    41,    41,    41,    41,    41,    48,
      41,    41,    41,   455,   455,    37,    40,   220,   206,   102,
     216,   149,   199,    43,   102,   204,   209,    43,   149,   214,
     455,   267,   270,    25,    28,    29,   264,   277,   280,   281,
     237,     6,     7,    44,    45,    47,   120,   142,   282,   344,
     349,   350,   351,   353,   357,   361,   362,   365,   366,   371,
     343,   396,   413,    40,    50,    64,   100,   405,   407,   414,
     415,   416,   417,   420,   423,   425,   431,   432,   453,   503,
      49,   393,    48,   398,   333,   287,   459,   462,   379,   473,
     473,   469,   470,   475,   475,   378,   455,   455,   455,   455,
     455,   455,    41,   486,   455,   455,   455,   455,    41,   375,
     221,   145,   207,   205,   148,   217,   215,   241,    26,    27,
     272,   273,   274,   275,   276,   372,   453,   161,   161,   278,
     281,   279,   280,   236,   354,   358,   352,   363,   372,    40,
     338,   328,   367,   416,    40,    50,   100,   433,   438,   439,
     441,   503,   423,   406,   419,   422,    19,    36,    61,   101,
     424,   426,   430,   391,   392,   401,   400,    36,   285,   289,
      41,    48,   377,    48,    41,    41,    41,    41,   377,   481,
      49,   489,   490,    41,   481,    41,    41,   378,   224,   203,
     213,    41,   273,   477,   258,   355,   359,   338,   364,   455,
     343,   338,    41,   436,   437,   439,    50,   440,   503,   397,
     102,   418,    63,   421,    48,   161,   429,   442,   397,   334,
      41,   289,   455,   455,    41,    75,    41,    41,    41,    41,
     223,   225,   289,   260,   452,   360,   338,    89,   370,    41,
     435,   412,   420,   425,   442,    37,    48,   428,   327,    41,
      55,    48,   222,   143,   144,   188,   356,   301,   453,    46,
     368,   102,   434,    49,   411,    37,    37,   427,   442,    37,
     502,   289,   289,   338,   452,    41,   369,   439,   407,   408,
     410,    37,   338,   338,   409,   397
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
     222,   222,   223,   224,   224,   225,   225,   226,   228,   229,
     227,   231,   230,   232,   232,   234,   235,   236,   233,   237,
     238,   238,   239,   239,   240,   241,   241,   242,   243,   243,
     243,   243,   243,   243,   243,   243,   244,   244,   245,   245,
     247,   246,   248,   249,   249,   250,   250,   251,   251,   252,
     253,   254,   254,   255,   256,   257,   258,   259,   259,   260,
     261,   261,   262,   262,   263,   263,   264,   264,   265,   266,
     266,   267,   267,   267,   267,   268,   269,   269,   270,   271,
     272,   272,   273,   273,   274,   274,   275,   276,   276,   277,
     277,   278,   278,   279,   279,   280,   281,   283,   282,   284,
     284,   285,   285,   287,   286,   286,   288,   288,   289,   289,
     289,   289,   289,   289,   290,   292,   291,   293,   293,   294,
     295,   295,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   297,   298,   299,   299,   300,   301,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   312,   313,   313,   314,   314,   315,   315,   316,   317,
     318,   319,   319,   320,   320,   321,   321,   322,   323,   323,
     323,   323,   324,   325,   326,   327,   327,   328,   328,   329,
     330,   330,   332,   333,   334,   331,   335,   336,   337,   337,
     338,   338,   339,   339,   341,   340,   342,   343,   343,   344,
     345,   345,   346,   347,   348,   348,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   350,   352,   351,   354,   355,
     356,   353,   358,   359,   360,   357,   361,   363,   364,   362,
     366,   367,   365,   369,   368,   370,   370,   371,   372,   372,
     372,   373,   374,   375,   374,   376,   376,   377,   378,   378,
     379,   380,   379,   382,   381,   383,   383,   384,   385,   386,
     386,   388,   387,   389,   387,   390,   391,   392,   392,   393,
     394,   394,   395,   396,   396,   397,   398,   399,   399,   400,
     401,   401,   403,   402,   404,   402,   406,   405,   407,   407,
     409,   408,   410,   410,   411,   412,   412,   413,   414,   415,
     416,   417,   418,   419,   419,   420,   421,   422,   422,   423,
     424,   424,   425,   425,   426,   427,   427,   428,   428,   429,
     429,   430,   430,   430,   430,   431,   432,   432,   432,   432,
     433,   434,   435,   435,   436,   437,   437,   438,   438,   439,
     440,   440,   441,   441,   441,   442,   443,   443,   445,   444,
     446,   447,   447,   447,   447,   447,   448,   448,   449,   449,
     450,   450,   451,   451,   452,   452,   453,   453,   454,   454,
     454,   454,   454,   454,   455,   456,   457,   458,   458,   459,
     460,   461,   461,   462,   463,   464,   464,   465,   465,   465,
     465,   465,   465,   465,   465,   466,   467,   468,   468,   469,
     469,   470,   470,   471,   471,   471,   472,   472,   473,   474,
     474,   475,   475,   475,   475,   476,   476,   476,   476,   476,
     476,   476,   476,   477,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   479,   479,   480,   481,   481,   482,   483,
     484,   485,   485,   486,   485,   487,   487,   488,   488,   488,
     488,   488,   489,   490,   490,   491,   492,   492,   493,   494,
     495,   495,   496,   496,   497,   497,   497,   498,   498,   498,
     499,   499,   499,   500,   500,   500,   501,   501,   502,   502,
     502,   502,   503,   503,   504,   504,   505,   505
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
       0,     1,     2,     0,     2,     3,     3,     2,     0,     0,
       5,     0,     5,     0,     2,     0,     0,     0,     7,     3,
       1,     1,     0,     1,     2,     0,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       0,     6,     5,     1,     2,     1,     1,     0,     1,     3,
       2,     1,     1,     1,     2,     1,     2,     0,     1,     4,
       0,     1,     0,     1,     0,     1,     0,     1,     3,     1,
       2,     1,     1,     4,     1,     2,     1,     2,     1,     3,
       1,     2,     1,     1,     1,     1,     2,     1,     1,     2,
       2,     0,     1,     0,     1,     2,     2,     0,     6,     0,
       2,     1,     2,     0,     4,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     0,     4,     0,     1,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     0,     1,     3,     0,     1,
       3,     3,     5,     5,     5,     2,     2,     2,     5,     2,
       0,     1,     0,     1,     2,     1,     0,     2,     2,     2,
       2,     1,     2,     1,     2,     0,     1,     2,     1,     1,
       1,     1,     3,     3,     2,     0,     1,     0,     1,     3,
       0,     2,     0,     0,     0,     8,     2,     2,     0,     1,
       1,     1,     1,     1,     0,     4,     2,     0,     1,     3,
       0,     2,     2,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     0,     3,     0,     0,
       0,     6,     0,     0,     0,     7,     6,     0,     0,     4,
       0,     0,     4,     0,     3,     0,     2,     2,     1,     1,
       1,     2,     1,     0,     6,     0,     1,     2,     0,     2,
       1,     0,     5,     0,     4,     0,     1,     2,     2,     0,
       1,     0,     3,     0,     3,     3,     2,     0,     1,     2,
       0,     2,     1,     0,     1,     2,     2,     0,     2,     1,
       1,     1,     0,     3,     0,     3,     0,     4,     1,     1,
       0,     3,     0,     1,     2,     0,     2,     1,     1,     1,
       1,     2,     2,     0,     2,     2,     2,     0,     2,     2,
       0,     1,     1,     2,     1,     1,     2,     2,     1,     2,
       3,     1,     1,     1,     2,     1,     1,     1,     2,     3,
       1,     2,     0,     2,     2,     0,     1,     1,     3,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     0,     4,
       4,     1,     1,     1,     1,     1,     0,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     0,     2,     2,
       2,     0,     2,     1,     2,     0,     1,     2,     2,     2,
       2,     2,     2,     2,     3,     1,     2,     1,     1,     2,
       2,     0,     1,     2,     2,     2,     0,     2,     2,     0,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     4,     6,     4,     4,     4,
       4,     2,     2,     4,     4,     4,     4,     2,     1,     4,
       4,     4,     4,     6,     6,     6,     4,     4,     4,     4,
       4,     4,     4,     2,     4,     4,     4,     4,     4,     4,
       2,     8,     6,     6,     6,     4,     4,     4,     4,     4,
       1,     1,     1,     3,     1,     7,     0,     1,     7,     2,
       3,     5,     5,     0,     7,     1,     1,     1,     1,     1,
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
     289,    -1,    14,   174,    -1,    -1,    -1,    15,   228,   175,
     229,   174,    -1,    -1,   231,   237,   232,   258,   260,    -1,
      -1,   232,   253,    -1,    -1,    -1,    -1,   234,   235,   237,
     236,   258,   260,   188,    -1,    16,   239,   245,    -1,    17,
      -1,    18,    -1,    -1,   238,    -1,    89,   453,    -1,    -1,
     240,    -1,    40,   455,   241,    41,    -1,   453,    -1,   485,
      -1,   478,    -1,   373,    -1,   493,    -1,   497,    -1,   501,
      -1,   242,    -1,   243,    -1,   244,   243,    -1,   244,    -1,
      19,    -1,    -1,    20,   381,   247,   232,   258,   260,    -1,
      21,   250,   232,   251,   260,    -1,   452,    -1,   249,   452,
      -1,   249,    -1,    19,    -1,    -1,   258,    -1,    38,   232,
     258,    -1,    22,   254,    -1,   255,    -1,   256,    -1,   257,
      -1,    23,   257,    -1,   503,    -1,   259,   338,    -1,    -1,
      39,    -1,   261,   262,   263,   264,    -1,    -1,   265,    -1,
      -1,   268,    -1,    -1,   271,    -1,    -1,   277,    -1,    90,
      25,   266,    -1,   267,    -1,   266,   267,    -1,   478,    -1,
     373,    -1,    40,   455,   241,    41,    -1,   453,    -1,    91,
     269,    -1,   270,    -1,   269,   270,    -1,   372,    -1,    24,
      25,   272,    -1,   273,    -1,   272,   273,    -1,   275,    -1,
     276,    -1,    26,    -1,    27,    -1,   274,   477,    -1,   372,
      -1,   453,    -1,   280,   278,    -1,   281,   279,    -1,    -1,
     281,    -1,    -1,   280,    -1,    28,   161,    -1,    29,   161,
      -1,    -1,    30,   283,   284,    36,   288,    37,    -1,    -1,
     284,   453,    -1,   289,    -1,   285,   289,    -1,    -1,    40,
     287,   285,    41,    -1,   182,    -1,    -1,   288,   286,    -1,
     503,    -1,   493,    -1,   497,    -1,   501,    -1,    42,    -1,
     453,    -1,   291,    -1,    -1,   189,   296,   292,   295,    -1,
      -1,   291,    -1,    49,   293,    -1,    -1,   294,    -1,   297,
      -1,   300,    -1,   302,    -1,   304,    -1,   305,    -1,   306,
      -1,   303,    -1,   307,    -1,   308,    -1,   309,    -1,   310,
      -1,     8,   503,   299,    -1,     9,   322,    -1,    -1,   298,
      -1,    10,   301,   323,    -1,    -1,    12,    -1,    13,   301,
     323,    -1,    11,   301,   322,    -1,   110,   301,   320,   108,
     320,    -1,   123,   301,   320,   108,   320,    -1,   111,   301,
     320,   108,   320,    -1,   125,   325,    -1,   116,   325,    -1,
     114,   324,    -1,   312,   314,   315,    39,   338,    -1,   103,
     503,    -1,    -1,   311,    -1,    -1,   317,    -1,   316,   313,
      -1,   317,    -1,    -1,   315,   318,    -1,     3,   324,    -1,
       4,   324,    -1,   106,   319,    -1,   503,    -1,    23,   503,
      -1,   104,    -1,   321,   503,    -1,    -1,     6,    -1,     6,
     503,    -1,   322,    -1,   104,    -1,    23,    -1,   105,    -1,
      36,   326,    37,    -1,    36,   326,    37,    -1,   327,   330,
      -1,    -1,   335,    -1,    -1,    43,    -1,   331,   328,   327,
      -1,    -1,   330,   329,    -1,    -1,    -1,    -1,   332,     6,
     452,   333,    36,   334,   327,    37,    -1,   387,   337,    -1,
      43,   327,    -1,    -1,   336,    -1,   340,    -1,   157,    -1,
     233,    -1,   342,    -1,    -1,    36,   341,   339,    37,    -1,
     343,   345,    -1,    -1,   346,    -1,   349,   328,   343,    -1,
      -1,   345,   344,    -1,   402,   348,    -1,    43,   343,    -1,
      -1,   347,    -1,   365,    -1,   351,    -1,   362,    -1,   353,
      -1,   357,    -1,   371,    -1,   361,    -1,   282,    -1,   350,
      -1,   142,   338,    -1,    -1,    44,   352,   338,    -1,    -1,
      -1,    -1,     6,   354,   355,   452,   356,   338,    -1,    -1,
      -1,    -1,     7,   358,   359,   360,   301,   452,   338,    -1,
     120,    40,   455,    89,   453,    41,    -1,    -1,    -1,    45,
     363,   364,   338,    -1,    -1,    -1,   366,   367,   338,   370,
      -1,    -1,    46,   369,   338,    -1,    -1,   370,   368,    -1,
      47,   372,    -1,   477,    -1,   478,    -1,   373,    -1,   503,
     374,    -1,   182,    -1,    -1,    40,   376,   455,   375,   378,
      41,    -1,    -1,    17,    -1,    48,   455,    -1,    -1,   378,
     377,    -1,   182,    -1,    -1,    40,   455,   380,   378,    41,
      -1,    -1,    36,   382,   383,    37,    -1,    -1,   384,    -1,
     387,   386,    -1,    43,   383,    -1,    -1,   385,    -1,    -1,
     451,   388,   390,    -1,    -1,   443,   389,   395,    -1,   401,
     397,   394,    -1,   401,   397,    -1,    -1,   391,    -1,    49,
     392,    -1,    -1,   394,   393,    -1,   396,    -1,    -1,   390,
      -1,   400,   399,    -1,    48,   400,    -1,    -1,   399,   398,
      -1,   450,    -1,   452,    -1,    50,    -1,    -1,   451,   403,
     405,    -1,    -1,   443,   404,   413,    -1,    -1,   407,   406,
     397,   412,    -1,   414,    -1,   415,    -1,    -1,   407,   409,
     397,    -1,    -1,   408,    -1,    49,   410,    -1,    -1,   412,
     411,    -1,   396,    -1,   416,    -1,   453,    -1,   417,    -1,
     420,   419,    -1,   102,   420,    -1,    -1,   419,   418,    -1,
     425,   422,    -1,    63,   425,    -1,    -1,   422,   421,    -1,
     431,   424,    -1,    -1,   426,    -1,   423,    -1,   100,   423,
      -1,   430,    -1,    37,    -1,   442,    37,    -1,    48,   427,
      -1,    37,    -1,   442,   428,    -1,    48,   442,    37,    -1,
      19,    -1,   101,    -1,    61,    -1,    36,   429,    -1,   432,
      -1,   503,    -1,    50,    -1,    64,   433,    -1,    40,   416,
      41,    -1,   438,    -1,   102,   439,    -1,    -1,   435,   434,
      -1,   439,   435,    -1,    -1,   436,    -1,   439,    -1,    40,
     437,    41,    -1,   441,    -1,   503,    -1,    50,    -1,   503,
      -1,    50,    -1,   100,   440,    -1,   161,    -1,   446,    -1,
     444,    -1,    -1,    51,   445,   390,    52,    -1,   448,    40,
     449,    41,    -1,    31,    -1,    32,    -1,    33,    -1,    34,
      -1,    35,    -1,    -1,   447,    -1,   450,    -1,   449,   450,
      -1,   451,    -1,   443,    -1,   453,    -1,   454,    -1,   453,
      -1,   503,    -1,   179,    -1,   180,    -1,   503,    -1,   493,
      -1,   497,    -1,   501,    -1,   505,    -1,   182,    -1,   456,
      -1,   459,   458,    -1,    53,   459,    -1,    -1,   458,   457,
      -1,   462,   461,    -1,    54,   462,    -1,    -1,   461,   460,
      -1,   463,    -1,   466,   464,    -1,    -1,   465,    -1,    55,
     466,    -1,    56,   466,    -1,    57,   466,    -1,    58,   466,
      -1,    59,   466,    -1,    60,   466,    -1,    66,   379,    -1,
      65,    66,   379,    -1,   467,    -1,   473,   472,    -1,   499,
      -1,   500,    -1,    19,   475,    -1,    63,   475,    -1,    -1,
     469,    -1,    61,   473,    -1,    62,   473,    -1,   468,   470,
      -1,    -1,   472,   471,    -1,   475,   474,    -1,    -1,   474,
     469,    -1,    64,   476,    -1,    61,   476,    -1,    62,   476,
      -1,   476,    -1,   477,    -1,   478,    -1,   491,    -1,   493,
      -1,   497,    -1,   501,    -1,   453,    -1,   485,    -1,    40,
     455,    41,    -1,    76,    40,   455,    41,    -1,    77,    40,
     455,    41,    -1,    78,    40,   455,    48,   455,    41,    -1,
      79,    40,   455,    41,    -1,    80,    40,   453,    41,    -1,
      67,    40,   455,    41,    -1,    68,    40,   455,    41,    -1,
      69,   479,    -1,   112,   182,    -1,   135,    40,   455,    41,
      -1,   132,    40,   455,    41,    -1,   124,    40,   455,    41,
      -1,   118,    40,   455,    41,    -1,    88,   379,    -1,   482,
      -1,   139,    40,   455,    41,    -1,   136,    40,   455,    41,
      -1,   134,    40,   455,    41,    -1,   130,    40,   455,    41,
      -1,   121,    40,   455,    48,   455,    41,    -1,   131,    40,
     455,    48,   455,    41,    -1,   138,    40,   455,    48,   455,
      41,    -1,   109,    40,   455,    41,    -1,   141,    40,   455,
      41,    -1,   133,    40,   455,    41,    -1,   129,    40,   455,
      41,    -1,   126,    40,   455,    41,    -1,   122,    40,   455,
      41,    -1,   117,    40,   455,    41,    -1,   115,   182,    -1,
     107,    40,   455,    41,    -1,   140,    40,   455,    41,    -1,
     137,    40,   455,    41,    -1,   128,    40,   455,    41,    -1,
     119,    40,   455,    41,    -1,   113,    40,   455,    41,    -1,
      70,   379,    -1,    71,    40,   455,    48,   455,    48,   455,
      41,    -1,    72,    40,   455,    48,   455,    41,    -1,    73,
      40,   455,    48,   455,    41,    -1,    81,    40,   455,    48,
     455,    41,    -1,    82,    40,   455,    41,    -1,    83,    40,
     455,    41,    -1,    84,    40,   455,    41,    -1,    85,    40,
     455,    41,    -1,    99,    40,   455,    41,    -1,   480,    -1,
     483,    -1,   484,    -1,    40,   455,    41,    -1,   182,    -1,
      86,    40,   455,    48,   455,   481,    41,    -1,    -1,   377,
      -1,   127,    40,   455,    48,   455,   481,    41,    -1,    74,
     338,    -1,    65,    74,   338,    -1,    92,    40,   376,   487,
      41,    -1,   488,    40,   376,   455,    41,    -1,    -1,    97,
      40,   376,   455,   486,   490,    41,    -1,    19,    -1,   455,
      -1,    93,    -1,    94,    -1,    95,    -1,    96,    -1,    98,
      -1,    49,    75,    55,   502,    -1,    -1,   489,    -1,   503,
     492,    -1,    -1,   374,    -1,   502,   496,    -1,    87,   503,
      -1,   181,    -1,   494,    -1,    -1,   495,    -1,   498,    -1,
     499,    -1,   500,    -1,   161,    -1,   162,    -1,   163,    -1,
     164,    -1,   165,    -1,   166,    -1,   167,    -1,   168,    -1,
     169,    -1,   159,    -1,   160,    -1,   170,    -1,   172,    -1,
     171,    -1,   173,    -1,   174,    -1,   504,    -1,   176,    -1,
     175,    -1,   177,    -1,   178,    -1
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
     144,   145,   147,   150,   151,   154,   158,   162,   165,   166,
     167,   173,   174,   180,   181,   184,   185,   186,   187,   195,
     199,   201,   203,   204,   206,   209,   210,   212,   217,   219,
     221,   223,   225,   227,   229,   231,   233,   235,   238,   240,
     242,   243,   250,   256,   258,   261,   263,   265,   266,   268,
     272,   275,   277,   279,   281,   284,   286,   289,   290,   292,
     297,   298,   300,   301,   303,   304,   306,   307,   309,   313,
     315,   318,   320,   322,   327,   329,   332,   334,   337,   339,
     343,   345,   348,   350,   352,   354,   356,   359,   361,   363,
     366,   369,   370,   372,   373,   375,   378,   381,   382,   389,
     390,   393,   395,   398,   399,   404,   406,   407,   410,   412,
     414,   416,   418,   420,   422,   424,   425,   430,   431,   433,
     436,   437,   439,   441,   443,   445,   447,   449,   451,   453,
     455,   457,   459,   461,   465,   468,   469,   471,   475,   476,
     478,   482,   486,   492,   498,   504,   507,   510,   513,   519,
     522,   523,   525,   526,   528,   531,   533,   534,   537,   540,
     543,   546,   548,   551,   553,   556,   557,   559,   562,   564,
     566,   568,   570,   574,   578,   581,   582,   584,   585,   587,
     591,   592,   595,   596,   597,   598,   607,   610,   613,   614,
     616,   618,   620,   622,   624,   625,   630,   633,   634,   636,
     640,   641,   644,   647,   650,   651,   653,   655,   657,   659,
     661,   663,   665,   667,   669,   671,   674,   675,   679,   680,
     681,   682,   689,   690,   691,   692,   700,   707,   708,   709,
     714,   715,   716,   721,   722,   726,   727,   730,   733,   735,
     737,   739,   742,   744,   745,   752,   753,   755,   758,   759,
     762,   764,   765,   771,   772,   777,   778,   780,   783,   786,
     787,   789,   790,   794,   795,   799,   803,   806,   807,   809,
     812,   813,   816,   818,   819,   821,   824,   827,   828,   831,
     833,   835,   837,   838,   842,   843,   847,   848,   853,   855,
     857,   858,   862,   863,   865,   868,   869,   872,   874,   876,
     878,   880,   883,   886,   887,   890,   893,   896,   897,   900,
     903,   904,   906,   908,   911,   913,   915,   918,   921,   923,
     926,   930,   932,   934,   936,   939,   941,   943,   945,   948,
     952,   954,   957,   958,   961,   964,   965,   967,   969,   973,
     975,   977,   979,   981,   983,   986,   988,   990,   992,   993,
     998,  1003,  1005,  1007,  1009,  1011,  1013,  1014,  1016,  1018,
    1021,  1023,  1025,  1027,  1029,  1031,  1033,  1035,  1037,  1039,
    1041,  1043,  1045,  1047,  1049,  1051,  1054,  1057,  1058,  1061,
    1064,  1067,  1068,  1071,  1073,  1076,  1077,  1079,  1082,  1085,
    1088,  1091,  1094,  1097,  1100,  1104,  1106,  1109,  1111,  1113,
    1116,  1119,  1120,  1122,  1125,  1128,  1131,  1132,  1135,  1138,
    1139,  1142,  1145,  1148,  1151,  1153,  1155,  1157,  1159,  1161,
    1163,  1165,  1167,  1169,  1173,  1178,  1183,  1190,  1195,  1200,
    1205,  1210,  1213,  1216,  1221,  1226,  1231,  1236,  1239,  1241,
    1246,  1251,  1256,  1261,  1268,  1275,  1282,  1287,  1292,  1297,
    1302,  1307,  1312,  1317,  1320,  1325,  1330,  1335,  1340,  1345,
    1350,  1353,  1362,  1369,  1376,  1383,  1388,  1393,  1398,  1403,
    1408,  1410,  1412,  1414,  1418,  1420,  1428,  1429,  1431,  1439,
    1442,  1446,  1452,  1458,  1459,  1467,  1469,  1471,  1473,  1475,
    1477,  1479,  1481,  1486,  1487,  1489,  1492,  1493,  1495,  1498,
    1501,  1503,  1505,  1506,  1508,  1510,  1512,  1514,  1516,  1518,
    1520,  1522,  1524,  1526,  1528,  1530,  1532,  1534,  1536,  1538,
    1540,  1542,  1544,  1546,  1548,  1550,  1552,  1554
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
     687,   689,   693,   696,   698,   702,   705,   711,   717,   719,
     717,   729,   729,   741,   744,   752,   755,   758,   752,   773,
     781,   784,   791,   794,   799,   806,   809,   814,   821,   824,
     827,   830,   833,   836,   839,   843,   848,   851,   859,   862,
     869,   869,   880,   888,   891,   899,   902,   909,   912,   917,
     925,   932,   933,   937,   943,   949,   956,   963,   965,   970,
     977,   980,   985,   988,   993,   996,  1001,  1005,  1009,  1016,
    1019,  1026,  1029,  1032,  1035,  1041,  1047,  1050,  1057,  1062,
    1069,  1073,  1081,  1083,  1091,  1094,  1102,  1110,  1111,  1118,
    1122,  1130,  1133,  1138,  1141,  1145,  1151,  1158,  1158,  1166,
    1168,  1174,  1177,  1183,  1183,  1188,  1194,  1196,  1200,  1203,
    1206,  1209,  1212,  1215,  1221,  1225,  1225,  1234,  1236,  1240,
    1243,  1245,  1249,  1250,  1251,  1252,  1253,  1254,  1255,  1256,
    1257,  1258,  1259,  1263,  1270,  1277,  1280,  1284,  1290,  1293,
    1299,  1305,  1311,  1317,  1323,  1329,  1337,  1345,  1353,  1362,
    1368,  1371,  1375,  1378,  1382,  1386,  1392,  1394,  1400,  1407,
    1414,  1420,  1423,  1429,  1432,  1437,  1439,  1443,  1449,  1452,
    1455,  1458,  1465,  1469,  1473,  1476,  1478,  1482,  1484,  1488,
    1491,  1493,  1498,  1503,  1506,  1498,  1517,  1521,  1524,  1526,
    1530,  1531,  1544,  1545,  1550,  1550,  1561,  1565,  1567,  1577,
    1581,  1584,  1600,  1605,  1609,  1612,  1616,  1617,  1618,  1619,
    1620,  1621,  1622,  1623,  1626,  1630,  1636,  1636,  1652,  1656,
    1658,  1652,  1669,  1673,  1675,  1669,  1686,  1697,  1701,  1697,
    1711,  1715,  1711,  1725,  1725,  1737,  1739,  1743,  1753,  1754,
    1755,  1759,  1767,  1771,  1771,  1781,  1784,  1791,  1797,  1799,
    1813,  1816,  1816,  1827,  1827,  1835,  1837,  1842,  1847,  1851,
    1853,  1857,  1857,  1860,  1860,  1867,  1872,  1876,  1878,  1883,
    1887,  1889,  1894,  1898,  1900,  1905,  1910,  1914,  1916,  1920,
    1927,  1931,  1939,  1939,  1942,  1942,  1948,  1948,  1954,  1955,
    1959,  1959,  1964,  1966,  1970,  1973,  1975,  1979,  1983,  1987,
    1993,  1997,  2001,  2004,  2006,  2010,  2014,  2019,  2021,  2027,
    2030,  2032,  2038,  2039,  2045,  2049,  2050,  2054,  2055,  2059,
    2060,  2064,  2065,  2066,  2067,  2071,  2075,  2078,  2081,  2084,
    2090,  2094,  2097,  2099,  2103,  2106,  2108,  2112,  2113,  2117,
    2121,  2122,  2126,  2127,  2128,  2132,  2137,  2138,  2142,  2142,
    2155,  2180,  2183,  2186,  2189,  2192,  2199,  2202,  2207,  2211,
    2218,  2219,  2223,  2226,  2230,  2233,  2239,  2240,  2244,  2247,
    2250,  2253,  2256,  2257,  2263,  2268,  2277,  2284,  2287,  2295,
    2304,  2311,  2314,  2321,  2326,  2337,  2340,  2344,  2347,  2350,
    2353,  2356,  2359,  2362,  2365,  2371,  2376,  2385,  2388,  2395,
    2398,  2405,  2408,  2413,  2416,  2420,  2434,  2437,  2445,  2454,
    2457,  2464,  2467,  2470,  2473,  2477,  2478,  2479,  2480,  2483,
    2486,  2489,  2492,  2496,  2502,  2505,  2508,  2511,  2514,  2517,
    2520,  2524,  2527,  2530,  2533,  2536,  2539,  2542,  2545,  2546,
    2549,  2552,  2555,  2558,  2561,  2564,  2567,  2570,  2573,  2576,
    2579,  2582,  2585,  2588,  2591,  2594,  2597,  2600,  2603,  2606,
    2609,  2613,  2616,  2619,  2622,  2625,  2628,  2631,  2634,  2637,
    2640,  2641,  2642,  2648,  2651,  2658,  2665,  2668,  2672,  2678,
    2685,  2692,  2695,  2699,  2699,  2712,  2716,  2720,  2723,  2726,
    2729,  2732,  2738,  2744,  2747,  2751,  2761,  2764,  2769,  2777,
    2784,  2788,  2796,  2800,  2804,  2805,  2806,  2810,  2811,  2812,
    2816,  2817,  2818,  2822,  2823,  2824,  2828,  2829,  2833,  2834,
    2835,  2836,  2840,  2841,  2845,  2846,  2850,  2851
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
  const int SPARQLfedParser::yylast_ = 2463;
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
#line 5436 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 2857 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


