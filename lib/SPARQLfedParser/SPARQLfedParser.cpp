
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
	driver.lastWhereClause = (yysemantic_stack_[(4) - (3)].p_WhereClause);
	(yyval.p_Operation) = new Select((yysemantic_stack_[(4) - (1)].p_Project).distinctness, (yysemantic_stack_[(4) - (1)].p_Project).varSet, (yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 737 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 740 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 748 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 751 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 755 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if ((yysemantic_stack_[(6) - (6)].p_BindingClause) != NULL)
	      (yysemantic_stack_[(6) - (4)].p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yysemantic_stack_[(6) - (6)].p_BindingClause), (yysemantic_stack_[(6) - (4)].p_WhereClause)->m_GroupGraphPattern);
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (3)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(6) - (2)].p_Project).distinctness, (yysemantic_stack_[(6) - (2)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(6) - (4)].p_WhereClause), (yysemantic_stack_[(6) - (5)].p_SolutionModifier))));
	  driver.curGraphName = (yysemantic_stack_[(6) - (1)].p_TTerm);
      }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 765 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 773 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 776 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 783 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 791 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 798 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 806 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 813 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 816 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 819 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 822 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 825 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 828 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 831 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 840 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 843 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 851 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 854 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 861 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = NULL;
      }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 863 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.lastWhereClause = (yysemantic_stack_[(6) - (5)].p_WhereClause);
	  /* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	  (yyval.p_Operation) = new Construct((DefaultGraphPattern*)((yysemantic_stack_[(6) - (2)].p_BasicGraphPattern) ? (yysemantic_stack_[(6) - (2)].p_BasicGraphPattern) : new DefaultGraphPattern()), (yysemantic_stack_[(6) - (4)].p_DatasetClauses), (yysemantic_stack_[(6) - (5)].p_WhereClause), (yysemantic_stack_[(6) - (6)].p_SolutionModifier));
      }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 872 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause) ? (yysemantic_stack_[(5) - (4)].p_WhereClause) : new WhereClause(new DefaultGraphPattern());
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 880 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm))));
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 883 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_TTerm))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 891 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 894 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 901 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 909 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(3) - (3)].p_WhereClause);
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(3) - (2)].p_DatasetClauses), (yysemantic_stack_[(3) - (3)].p_WhereClause));
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 917 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 929 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 935 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 941 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 948 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.ensureGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 962 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 969 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 977 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 985 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 993 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1001 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1008 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1011 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1018 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1021 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1024 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1027 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1033 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1039 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1042 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1054 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1061 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1065 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1075 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1083 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1086 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1094 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1103 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1110 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1114 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1122 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1130 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1137 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1143 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1150 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1152 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1160 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1166 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1169 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1175 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow(); // @@ push down to _Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star?
      }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 1177 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 1180 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1192 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1195 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1198 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1201 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1204 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 1207 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 1217 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	OperationSet* ret = driver.root ? dynamic_cast<OperationSet*>(driver.root) : new OperationSet();
	ret->push_back((yysemantic_stack_[(2) - (2)].p_Operation));
	driver.root = ret;
      }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1221 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Operation) = driver.root;
	}
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 1255 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(3) - (2)].p_URI), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 1262 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 1269 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1276 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1282 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1285 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1291 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 1297 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 1303 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 1309 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 1315 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 1321 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert(driver.ensureGraphPattern(), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 1329 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete(driver.ensureGraphPattern(), NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 1337 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete(driver.ensureGraphPattern(), NULL);
	driver.curOp = NULL;
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 1345 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(5) - (1)].p_URI))
	    w3c_sw_NEED_IMPL("WITH <URI> (DELETE INSERT?|INSERT) ...");
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(5) - (2)].p_DeleteInsert).del, (yysemantic_stack_[(5) - (2)].p_DeleteInsert).ins, new WhereClause(driver.ensureGraphPattern()));
	driver.curOp = NULL;
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 1354 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 1360 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 1367 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 1374 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 1378 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 1386 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("_QUsingClause_E_Star");
    }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 1392 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Delete) = new Delete(driver.ensureGraphPattern(), NULL);
	driver.curOp = NULL;
    }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 1399 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = new Insert(driver.ensureGraphPattern(), NULL);
	driver.curOp = NULL;
    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 1406 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 1412 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 1415 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 1421 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 1424 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 1435 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 1441 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 1444 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("DEFAULT");
      }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 1447 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("NAMED");
      }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 1450 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("ALL");
      }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 1490 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 1495 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 1498 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 1501 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 1523 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 252:

/* Line 678 of lalr1.cc  */
#line 1542 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 1544 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 1615 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_BindingClause)) : (yysemantic_stack_[(1) - (1)].p_BindingClause);
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 1622 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Print(driver.curOp);
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 1628 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 1632 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 276:

/* Line 678 of lalr1.cc  */
#line 1644 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 1648 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 1650 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 1653 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 1661 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 1665 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 1667 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = NULL;
      }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 1670 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(7) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(7) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(7) - (6)].p_TTerm), driver.curOp, (yysemantic_stack_[(7) - (5)].p_Silence), driver.atomFactory, false));
	  driver.curGraphName = (yysemantic_stack_[(7) - (4)].p_TTerm);
      }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 1678 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Bind(driver.ensureGraphPattern(), (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
	// no more triples go into the current BGP, per
	//   http://www.w3.org/TR/sparql11-query/#sparqlTranslateGraphPatterns
	// test reference:
	//   http://www.sparql.org/query-validator?query=ASK+{+%3Fs+%3Fp+%3Fo+FILTER+%281%29+BIND+%282+AS+%3Fb%29+%3Fs2+%3Fp2+%3Fo2+FILTER+%283%29+BIND+%284+AS+%3Fd%29}&languageSyntax=SPARQL&outputFormat=algebra&linenumbers=false
	driver.curBGP = NULL;
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 1689 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 1693 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 1695 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.ensureGraphPattern()));
      }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 1703 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 1707 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 1709 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 1717 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 1722 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.ensureGraphPattern());
      }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 1735 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    driver.ensureGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 1751 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 1759 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 1763 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 1766 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = (yysemantic_stack_[(6) - (4)].p_Expressions);
      }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 1773 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 1776 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 1783 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 1791 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 1805 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 1808 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 1811 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(5) - (3)].p_Expressions);
      }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 1819 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 1821 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 1849 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 1852 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 1912 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 1919 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 1923 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 1931 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 1934 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 1940 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 1951 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 1979 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 2006 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 2013 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 2024 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 2031 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 2067 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 2070 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 2073 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 2076 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 2134 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 2138 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 2147 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 409:

/* Line 678 of lalr1.cc  */
#line 2172 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 2175 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 2178 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 2181 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 2184 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 2191 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 2199 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 2203 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 2215 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 2222 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 2225 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 2236 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 2239 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 2242 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 2245 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 2249 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 2260 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 2269 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 2276 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 2279 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 2287 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 2296 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 2303 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 2306 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 2318 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_GeneralComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_GeneralComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_GeneralComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 2329 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 2336 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 2339 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 2342 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 2345 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 2348 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 2351 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 2354 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 2357 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 2368 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 2377 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 2380 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 2387 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 2390 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 2397 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 2405 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 2408 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 2412 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 464:

/* Line 678 of lalr1.cc  */
#line 2426 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 2429 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 2437 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 2446 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 2449 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 2456 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 2459 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 2462 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 2472 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 2475 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 2478 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 2481 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 2488 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 2494 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 2497 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 2500 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 2503 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 2506 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 2509 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 2512 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 2516 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bnode, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 2519 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 2522 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 2525 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_ciel, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 2528 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 2531 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_numeric_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 2534 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 2538 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_string_length, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 2541 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_upper_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 2544 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lower_case, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 2547 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encode_for_uri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 2550 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 2553 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_starts_with, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 2556 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ends_with, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 2559 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 2562 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 2565 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 2568 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 2571 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 2574 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 2577 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone_from_dateTime, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 2580 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 2583 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 2586 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 2589 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha224, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 2592 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 2595 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 2598 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 2601 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 2605 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 2608 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 2611 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 2614 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 2617 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 2620 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 2623 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 2626 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 2629 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 2640 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 2643 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 2650 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_matches, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 2657 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 2664 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 2670 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.ensureGraphPattern(), NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 2677 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.ensureGraphPattern(), NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 2684 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 2687 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 2691 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = driver.curExprList;
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 2694 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  // x = new ArgList($2, driver.curExprList);
	  delete driver.curExprList;
	  driver.curExprList = (yysemantic_stack_[(7) - (5)].p_Expressions);
	  w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // $$ = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group-concat, $3, $4.p_Expression, $4.separator));
    }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 2704 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
	driver.countStar = true;
    }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 2712 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 2715 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 2718 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 2721 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 2724 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 2730 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 2736 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 2743 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 2753 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 2761 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 2769 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 2776 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 2780 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 2788 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 3570 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -815;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        59,   -49,   140,  -815,  -815,   543,  -815,  -815,  -815,  -815,
    -815,  -815,    96,   134,   134,   134,   196,   112,     3,  -815,
      96,   134,   134,   114,   135,   134,   135,   168,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,    64,   188,  -815,  -815,
    -815,   209,  -815,  -815,   184,   217,   184,  -815,  -815,  -815,
    1377,  -815,  -815,  -815,  -815,  -815,   119,  -815,  -815,  -815,
    -815,    50,  -815,    43,    43,  1011,  -815,  1011,  -815,    43,
    -815,  -815,  -815,  -815,    50,   194,   114,   114,  -815,   229,
    -815,  -815,    95,  -815,   217,  -815,  -815,    96,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,  1745,   175,   211,   213,
     -15,    -6,   227,   236,   238,     0,   246,   252,   263,   265,
     267,   269,   271,   273,   276,   278,   282,    -6,   288,  -815,
    -815,  -815,  -815,   301,  -815,   302,   304,   306,    87,   307,
     166,   309,   311,   312,   314,   315,   317,   318,   322,   329,
     330,   331,   332,   335,   338,   339,   343,   344,   346,   347,
     348,   349,   350,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
    1861,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
     351,  -815,  -815,  -815,  -815,  -815,  -815,   -43,     6,  1011,
    -815,  -815,     4,    10,  -815,  -815,  -815,     0,  -815,  -815,
     149,    96,   284,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
    -815,  -815,   356,  -815,  -815,   231,  -815,  -815,  -815,  -815,
     354,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,   358,
     289,  -815,   308,   100,  -815,  -815,  -815,  -815,    12,  -815,
    -815,   221,   345,  -815,  -815,  -815,  -815,  -815,  1745,  1977,
    1977,  1977,  -815,   310,  -815,  -815,  -815,  -815,   225,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
       6,     0,  1745,  1745,  1745,  -815,  -815,  1745,  -815,  -815,
    1745,  1745,  1745,  -815,  -815,  -815,  -815,  1745,  1745,  1745,
    1745,  -101,  1745,  1745,  1745,  1745,  1745,  1745,  -815,   384,
     384,  1745,  1745,  1745,  -815,  1745,  -815,  1745,  1745,  1745,
    1745,  1745,  1745,  1745,  1745,  1745,  1745,  1745,  1745,  1745,
    1745,  1745,  1745,  1745,  1745,  1745,  1745,  1745,  1745,  -815,
     384,    96,  -815,  -815,  -815,  -815,   384,  -815,  -815,   365,
    -815,   361,    50,   308,  -815,    96,  -815,  -815,  -815,  -815,
    -815,  -815,    43,  -815,    43,    45,  -815,   399,  1011,  -815,
    -815,    45,  1604,    45,  -815,    43,     1,   383,  -815,   320,
    -815,   152,  -815,  -815,     0,    19,  -815,  -815,  -815,   109,
     371,  -815,  -815,  -815,  -101,  -815,   374,   363,   366,  1745,
    1745,  1745,  1745,  1745,  1745,   353,    -6,  -815,  -815,   199,
      34,  -815,  -815,  -815,   381,   382,   385,  -815,   376,   377,
     379,   983,   387,   388,   389,   391,   392,   390,   401,   402,
     403,   404,   398,  -815,  1219,  1745,   406,   407,   408,   410,
     411,   412,   414,   409,   415,   418,   419,   420,   425,   426,
     428,   422,   430,   431,   432,   436,   437,   439,   435,   443,
     446,   448,  1745,  -815,  1745,  -815,  1011,  -815,  -815,   308,
    -815,  -815,  -815,  -815,  -815,   438,  1604,  -815,  -815,   449,
     487,  -815,  -815,  -815,  -815,  -815,  1552,  -815,  -815,  -815,
    -815,  -815,  -815,  2093,  2258,   472,  -815,  -815,    96,  -815,
    -815,   323,  -815,  1576,  -815,  -815,  1526,  -815,  -815,   396,
    -815,  -815,   352,  -815,  -815,  -815,  -815,  -815,  1745,  -815,
    1745,  -815,  -815,  -815,  -815,  -815,  -815,  -815,    -6,  -815,
    1745,  1745,    34,  -815,  -815,  -815,  1745,  1745,  -815,  -815,
    -815,  -815,  -815,  1745,  1745,  1745,  -815,   483,   463,  -815,
    -815,  -815,   460,  -815,  -815,  -815,  -815,  1745,  -815,  -815,
    1745,  -815,  -815,  -815,  -815,  1745,  -815,  -815,   465,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,  -815,  1745,  -815,  -815,
    -815,  1745,  -815,  -815,  -815,  1745,  -815,  -815,  -815,  -815,
    -815,  -815,  1745,  -815,  -815,  -815,   466,  -815,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,  1011,   119,  -815,  -815,    -9,
    1745,  2093,  -815,  -815,  -815,  -815,  2258,  -815,  -815,  -815,
    -815,  -815,   479,   210,  -815,  -815,  -815,   132,  -815,  -815,
    2117,  -815,  -815,   417,  -815,  -815,  -815,  -815,  -815,  -815,
    2117,  -815,  -815,   360,  -815,    31,  -815,    15,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,  -815,    67,   462,   470,
     473,  -815,  -815,    92,  1011,  -815,  -815,    45,    30,   475,
     476,   477,  -815,   464,   480,   477,   482,   485,  -815,  -815,
     471,   481,  -815,  -815,  -815,  -815,  -815,  -815,   310,  -815,
    -815,  1493,   369,   370,  -815,  -815,   495,   499,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,   -38,  -815,  -815,  -815,   116,
    -815,  -815,  -815,  -815,  1745,  -815,  1745,  -815,  -815,   493,
    -815,  -815,  -815,  -815,  2258,   494,     0,  -815,  -815,   449,
    -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
    -815,  -815,    41,  -815,    56,    26,  -815,  -815,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,    73,  -815,  -815,  -815,  -815,
    -815,  -815,   492,   461,  -815,   496,  -815,   498,  -815,  -815,
      72,    45,  -815,  1604,  -815,   504,  2117,   500,  -815,  -815,
    1493,  -815,   502,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,  1576,  -815,  -815,  1526,
    -815,   503,   308,  -815,  -815,     0,  -815,  -815,  1745,  -815,
    1011,     0,   505,    53,  -815,    61,  -815,  -815,  -815,  -815,
    -815,  -815,  1604,   433,   484,  -815,    -3,  -815,  -815,  -815,
    -815,  -815,  -815,   488,  -815,  -815,  -815,  -815,  -815,  1604,
    -815,  -815,  2078,  -815,  -815,  -815,  -815,  2141,  -815,  -815,
    -815,   168,   119,  -815,  -815,     0,   478,  -815,  -815,  -815,
    -815,   508,  -815,  -815,  -815,  -815,  -815,    41,  -815,    41,
    -815,   394,  -815,  -815,    23,    75,  -815,  1011,  -815,  -815,
    -815,  -815,   513,   157,  -815,  -815,   134,  -815,  -101,   516,
    -815,   467,   501,  -815,  -815,   528,  -815,    -2,  -815,  -815,
     529,  -815,  -815,  2117,  2117,     0,   119,   527,  -815,  -815,
      53,  -815,    30,  -815,  -815,  -815,  -815,   533,  -815,  -815,
    -815,  -815,     0,  -815,     0,  -815,  -815,  -815,  -815,  -815,
    -815,  -815,  1604,  -815
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        13,     0,     0,     2,     4,   208,    15,    14,     3,   172,
      67,     1,     0,   196,   196,   196,    80,     0,     0,    72,
       0,   196,   196,     0,     0,   196,     0,    10,     6,    72,
       7,     8,     9,   173,   180,   181,   182,   186,   183,   184,
     185,   187,   188,   189,   190,   209,     0,    17,   580,   583,
     582,   193,   581,   197,     0,     0,     0,    78,    79,    81,
       0,   311,    98,   104,   424,   425,   103,    72,   101,   422,
     423,   115,   207,   223,   223,   233,   205,   233,   204,   223,
     203,   155,     5,    11,   115,   178,     0,     0,   214,   210,
     213,    68,    12,    16,     0,   194,   191,     0,   228,   227,
     229,   226,   195,   199,   198,    97,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   545,
     546,   547,   548,     0,   549,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   574,   575,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   576,   578,   577,   579,    93,    94,
      96,    77,    89,    86,    88,   528,   496,   529,   530,    87,
       0,    90,    91,   562,   563,   564,    92,   560,     0,   313,
      72,   102,   105,     0,   116,    73,   107,     0,   224,   221,
       0,     0,     0,   409,   410,   411,   412,   413,   406,   584,
     585,   431,     0,   238,   234,   246,   321,   405,   404,   415,
       0,   319,   420,   421,   427,   428,   429,   426,   430,     0,
       0,   157,   118,    13,   179,   174,   216,   217,     0,   212,
     211,     0,     0,    18,    23,    19,   192,   225,     0,     0,
       0,     0,   479,    83,   432,   435,   439,   441,   443,   453,
     464,   467,   472,   473,   474,   480,   475,   476,   477,   478,
     554,     0,     0,     0,     0,   532,   489,     0,   308,   518,
       0,     0,     0,   252,   249,   537,   248,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   495,   303,
     303,     0,     0,     0,   490,     0,   511,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
     303,     0,   558,   559,   561,   556,   303,   300,   299,     0,
     314,   317,   115,   118,   106,     0,   108,   109,   110,   111,
     113,   114,   223,   222,   223,     0,   230,   232,   233,   247,
     244,   331,   414,     0,   231,   223,     0,     0,    71,   120,
     119,   208,   176,   177,     0,     0,   215,    69,    21,     0,
       0,   470,   471,   469,     0,    84,     0,   433,   437,     0,
       0,     0,     0,     0,     0,     0,     0,   442,   444,   454,
     466,   555,   553,   538,     0,     0,     0,   309,     0,     0,
       0,   255,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   304,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   557,     0,   312,   313,   318,   315,   118,
     100,   112,   200,   202,   339,     0,   414,   338,   239,   235,
       0,   245,   332,   322,   330,   419,   414,   416,   418,   320,
     201,   164,   158,     0,     0,   122,   121,   206,     0,   218,
     219,     0,    56,     0,    31,    45,     0,    20,    24,     0,
      29,    25,     0,    43,    26,   481,    82,    85,     0,   436,
       0,   440,   445,   446,   447,   448,   449,   450,     0,   451,
       0,     0,   459,   465,   455,   456,     0,     0,   468,   487,
     488,   531,   306,     0,     0,     0,   250,     0,     0,   251,
     258,   256,   262,   342,   340,   482,   483,     0,   485,   486,
       0,   523,   524,   525,   526,     0,   543,   544,     0,   541,
     527,   512,   504,   517,   510,   494,   516,     0,   509,   493,
     508,     0,   515,   507,   500,     0,   492,   506,   499,   491,
     498,   514,     0,   497,   513,   505,     0,   301,   316,    99,
     407,   328,   335,   337,   236,   233,     0,   408,   417,     0,
       0,   126,   127,   130,   132,   129,   133,   134,   136,   298,
     296,   297,     0,   124,   123,   220,    70,     0,   170,    35,
      36,    32,    33,     0,   171,   167,   168,   169,   166,    49,
      50,    46,    47,     0,    29,     0,    43,     0,   434,   438,
     452,   461,   462,   460,   463,   457,   458,     0,     0,     0,
       0,    75,   253,   288,   255,   263,   260,   331,     0,     0,
       0,   534,   539,   551,     0,   534,     0,     0,   540,   306,
     323,   333,   237,   241,   156,   161,   163,   165,    83,   128,
     135,     0,     0,     0,   117,   125,   149,   151,    55,    58,
      57,    34,    39,    48,    53,     0,    28,    37,    30,     0,
      42,    51,    44,   310,     0,   307,     0,   520,   521,   115,
     276,   280,   274,   285,     0,     0,     0,   271,   259,   235,
     272,   265,   267,   268,   270,   266,   264,   289,   269,   261,
     355,   343,     0,   385,     0,     0,   341,   344,   346,   347,
     356,   358,   361,   370,   365,   368,   383,   357,   384,   484,
     522,   535,     0,     0,   552,     0,   501,     0,   502,   503,
       0,   325,   329,   414,   336,     0,     0,     0,   142,   143,
     137,   138,     0,   140,   141,   145,   146,   153,   154,   147,
     150,   148,   152,    63,    40,    27,     0,    54,    41,     0,
     305,     0,   118,   277,   281,     0,   286,   295,     0,   273,
     255,     0,     0,   393,   401,     0,   386,   388,   395,   397,
     400,   371,   414,   359,   363,   379,     0,   381,   380,   367,
     369,   372,   533,     0,   542,   536,   302,   326,   327,   414,
     334,   242,     0,   159,   131,   139,   144,     0,    38,    52,
     519,    10,     0,   282,   275,     0,     0,   257,   293,   387,
     394,     0,   390,   399,   402,   398,   353,     0,   362,     0,
     366,     0,   403,   382,     0,     0,   324,   233,   162,   160,
      59,    64,    60,     0,    76,   278,   196,   287,     0,   290,
     396,   392,   345,   360,   364,     0,   376,     0,   377,   550,
       0,    61,    62,     0,     0,     0,     0,     0,   291,   294,
       0,   391,   350,   354,   378,   373,   375,     0,   243,    66,
      65,   279,     0,   284,     0,   389,   348,   351,   352,   374,
     283,   292,   414,   349
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -815,  -815,  -815,  -815,  -815,  -280,   333,  -815,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,   -71,  -815,    66,  -815,
    -222,  -815,  -815,   -52,  -815,  -815,   -69,  -815,    68,  -815,
    -220,  -815,  -815,   -58,  -815,  -815,  -815,  -815,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,    -8,  -815,
    -815,  -815,    36,  -815,  -815,  -815,  -104,  -815,   416,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
    -815,  -815,   232,   -79,  -815,  -337,  -815,  -815,  -815,  -815,
    -815,  -815,   -25,  -815,  -815,   -28,  -815,  -815,  -191,  -815,
    -815,  -815,  -815,  -815,  -815,  -106,   -99,   -63,  -815,  -815,
    -815,  -815,  -815,  -815,  -497,  -815,   359,  -815,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,   -11,  -815,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
    -815,  -815,   512,  -815,  -815,   -56,  -815,     7,   536,   234,
     577,   530,  -355,  -123,  -815,  -815,  -815,  -815,  -815,  -815,
    -815,  -815,  -815,  -188,  -815,  -815,  -815,  -815,  -640,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,  -815,  -614,   -53,   328,
    -815,  -258,  -547,   -67,  -110,  -815,  -815,  -815,   144,  -815,
    -815,  -815,  -179,  -815,  -815,  -261,  -815,  -815,  -815,  -815,
    -815,   -54,  -783,  -815,  -815,  -162,  -155,  -815,  -815,  -815,
    -815,  -815,  -291,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
    -815,  -120,  -815,  -815,  -815,  -243,  -815,  -815,  -119,  -815,
    -244,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
    -815,  -815,  -815,  -815,  -766,  -815,  -815,  -814,  -360,  -815,
    -815,  -815,  -815,  -815,  -815,  -331,  -334,   -16,     9,  -815,
     660,  -815,  -815,  -815,   111,  -815,  -815,   107,  -815,  -815,
    -815,   -68,  -815,  -815,    98,  -815,  -815,  -815,  -193,  -815,
    -197,    65,  -465,   -59,  -815,  -815,   -44,  -815,  -815,  -815,
      -5,  -815,  -815,  -815,  -815,  -815,  -815,  -815,   -45,  -815,
    -815,  -815,    42,  -815,   224,   226,   237,  -241,   -12,  -815,
    -815
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,    27,    82,     5,     6,    47,    92,
     253,   389,   254,   255,   507,   508,   645,   509,   510,   630,
     631,   708,   796,   632,   795,   511,   647,   512,   513,   640,
     641,   712,   799,   642,   798,   514,   627,   700,   793,   902,
     881,   847,   882,     7,    93,   251,   501,    28,    71,   546,
     547,   719,    29,    59,    60,   395,   396,   178,   179,   180,
     181,    30,   200,    31,    66,    67,   353,    32,   205,   356,
     357,   358,   359,   206,   207,   378,   379,   495,   623,   694,
     380,   611,   612,   496,   616,   617,   624,   780,   781,   782,
     783,   784,   695,   789,   791,   696,   697,    83,   241,   376,
     842,   687,   776,   609,   633,     8,     9,    85,   383,   244,
     245,    33,    34,    95,    96,    35,    54,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,   249,    88,
     248,    89,    90,   386,   499,   210,   211,   101,   102,    76,
      78,   222,   223,   605,   478,   367,   479,   480,   775,   877,
     224,   369,   370,   295,   548,   296,   421,   549,   550,   728,
     663,   551,   665,   666,   729,   730,   731,   805,   732,   803,
     852,   905,   733,   804,   853,   886,   734,   735,   806,   855,
     736,   737,   811,   909,   924,   889,   738,   618,   619,   348,
     679,   434,   715,   657,   289,   542,    62,   199,   349,   350,
     467,   468,   225,   373,   371,   482,   837,   838,   772,   680,
     483,   484,   601,   774,   681,   602,   476,   552,   668,   667,
     746,   822,   747,   927,   932,   928,   913,   892,   741,   748,
     749,   750,   751,   868,   823,   752,   870,   824,   753,   829,
     754,   830,   916,   898,   873,   831,   755,   756,   816,   911,
     891,   860,   861,   817,   818,   864,   819,   874,   226,   227,
     365,   228,   229,   230,   486,   603,   231,   477,   262,   233,
     263,   264,   519,   397,   265,   521,   398,   266,   267,   407,
     408,   268,   269,   532,   538,   654,   533,   409,   270,   410,
     271,   272,   273,   274,   286,   185,   762,   186,   187,   188,
     275,   673,   568,   190,   764,   765,   276,   412,   277,   343,
     344,   345,   278,   193,   194,   195,   279,   197,   280,    52,
     238
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SPARQLfedParser::yytable_ninf_ = -415;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        51,   184,    68,    55,    56,   242,    70,   182,    72,   643,
      73,    74,   485,   481,    79,   191,   470,   308,   212,   361,
     351,    84,    63,   240,   739,   284,   203,    69,   684,   620,
     234,   685,   234,   355,   287,   915,   293,   491,   488,   866,
    -115,   487,   498,   204,   341,   871,   346,   862,   198,   208,
     201,   384,   435,   536,    70,   189,   876,   895,   710,   202,
     896,   553,   103,   237,   707,   237,   742,    86,    87,   183,
     742,   897,   203,     1,   706,    69,   743,   785,    64,    65,
     743,   742,   462,   917,   232,   257,   232,   554,   464,   204,
     744,   743,   825,   413,   744,   474,   813,   537,   720,   721,
    -175,   256,   192,   814,   475,   744,   814,   794,   713,   826,
     807,   863,   489,   836,     1,   714,   485,   235,   385,   235,
     714,   184,    81,   354,   761,    10,   485,   182,   761,  -254,
     745,   -22,   599,   707,   827,   191,   722,   723,   342,   724,
      11,   745,   488,   643,   925,   502,    53,   209,    61,   933,
      75,   620,   488,   815,   234,   608,   815,   294,   872,   872,
      12,  -115,    13,    14,   711,    15,   785,   285,   198,   698,
     857,    77,   699,   686,   828,   189,   288,    48,    49,    50,
      64,    65,    64,    65,    48,    49,    50,   237,   347,   183,
      97,   360,   352,    48,    49,    50,   497,   -22,    81,   363,
      48,    49,    50,    91,    48,    49,    50,    98,   232,    64,
      65,   503,   725,    57,    58,    48,    49,    50,    94,    48,
      49,    50,   192,    97,    64,    65,   620,    48,    49,    50,
      48,    49,    50,    87,   726,    48,    49,    50,   692,   693,
     -22,   235,   -22,   243,   -22,   174,   175,   176,   177,   281,
     682,   282,   252,   283,   504,    20,   505,   362,   506,   620,
     530,   531,    21,    22,   797,   711,    23,   290,    24,   314,
      48,    49,    50,   469,   368,    25,   291,    26,   292,   843,
     399,   400,   401,   402,   403,   404,   297,   351,    99,   100,
     405,   406,   298,    48,    49,    50,   529,   196,    64,    65,
     903,   904,   643,   299,   553,   300,   472,   301,   473,   302,
     426,   303,   236,   304,   236,   620,   305,   846,   306,   490,
     246,   247,   307,   234,   391,   392,   393,   234,   309,   463,
     554,   522,   523,   524,   525,   526,   527,   651,   652,   655,
     656,   310,   311,   360,   312,   879,   313,   315,   316,   317,
     883,   318,   319,    70,   320,   321,   237,   322,   323,    70,
     237,    70,   324,   168,   169,   170,   171,   172,   173,   325,
     326,   327,   328,   500,    69,   329,   234,   232,   330,   331,
      69,   232,    69,   332,   333,   492,   334,   335,   336,   337,
     338,   340,   364,   366,   372,   374,   387,   375,   377,   394,
     388,   433,   465,   516,   466,  -240,   919,   920,   493,   237,
     235,   494,   515,   485,   235,   517,   518,   196,   650,   528,
     520,   234,   539,   540,   543,   544,   541,   545,   555,   556,
     232,   234,   558,   559,   615,   621,   236,   557,   560,   488,
     613,   234,   561,   562,   563,   564,   565,   570,   571,   572,
     553,   573,   574,   575,   237,   576,   578,   577,   635,   579,
     580,   635,   485,   235,   237,   851,   582,   583,   581,   584,
     585,   586,   587,   588,   237,   232,   554,   589,   590,   485,
     591,   198,   198,   592,   593,   232,   625,   594,   488,   595,
     600,   638,   604,   606,   638,   232,   622,   626,   503,    16,
     662,   506,   614,   664,   691,   488,   672,   678,   235,   704,
     716,   717,   634,   763,   718,   634,   759,   760,   235,   702,
     771,   766,   900,   768,   693,   714,   769,   692,   235,   773,
     787,   788,   204,   832,   808,   867,   833,   834,   809,   835,
     841,   844,   258,   875,   850,   636,   859,   869,   636,   890,
     912,    12,   615,    13,    14,   872,    15,   621,   613,    16,
     234,   901,   908,    17,    18,   914,   918,   888,   923,   910,
     929,   884,   485,   705,   848,   644,   381,   709,   701,   849,
     646,    19,   703,   661,   777,   635,   689,   471,   690,   845,
     683,   792,   104,   237,    70,   635,   339,   790,   488,   198,
     727,   250,   382,    80,   198,   236,   810,   239,   411,   236,
     598,   840,   770,   740,   232,    69,   839,   854,   638,   234,
     614,   926,   812,   858,   893,   894,   821,   649,   638,   648,
     653,   767,   621,   534,   899,   535,     0,     0,     0,   634,
     802,     0,     0,     0,     0,     0,    20,   235,     0,   634,
       0,     0,   237,    21,    22,    70,   758,    23,   236,    24,
       0,     0,     0,     0,     0,   621,    25,   887,    26,     0,
       0,     0,   636,   232,     0,     0,    69,   757,     0,   198,
       0,     0,   636,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     786,     0,     0,   236,     0,     0,   235,     0,     0,     0,
       0,     0,   198,   236,     0,     0,     0,   921,     0,     0,
       0,   621,     0,   236,     0,     0,     0,     0,   234,     0,
     758,   635,   820,   758,   930,     0,   931,     0,     0,     0,
     637,     0,     0,   637,     0,     0,     0,     0,     0,     0,
       0,   635,     0,     0,   635,     0,     0,     0,     0,    70,
       0,   237,     0,     0,   638,   234,     0,     0,   198,     0,
       0,     0,     0,     0,     0,     0,     0,   234,     0,     0,
      69,     0,   232,     0,   638,   634,     0,   638,     0,   786,
       0,     0,     0,     0,   234,     0,     0,   635,   237,     0,
       0,   820,   635,   865,     0,   634,     0,     0,   634,     0,
     237,     0,     0,     0,     0,   235,     0,     0,   636,   232,
       0,     0,     0,     0,     0,     0,     0,   237,     0,     0,
     638,   232,   234,     0,     0,   638,   885,     0,   636,     0,
      70,   636,   236,     0,     0,     0,     0,     0,   232,     0,
       0,   634,   235,     0,     0,   758,   634,   758,   635,   635,
       0,    69,     0,     0,   235,   237,     0,   637,     0,     0,
       0,     0,     0,     0,     0,   906,     0,   637,     0,     0,
       0,   235,     0,     0,   636,     0,   232,   234,     0,   636,
     922,   638,   638,     0,    70,     0,     0,   907,   820,     0,
     758,   236,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   634,   634,     0,    69,     0,     0,   390,   235,
     237,   757,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   232,   414,   415,   416,   636,   636,   417,     0,     0,
     418,   419,   420,     0,     0,     0,     0,   422,   423,   424,
     425,     0,   427,   428,   429,   430,   431,   432,     0,     0,
       0,   436,   437,   438,   235,   439,     0,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   -74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,     0,     0,   637,   213,   214,   215,   216,   217,     0,
       0,     0,     0,  -414,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   637,   218,     0,   637,     0,     0,     0,
       0,     0,   213,   214,   215,   216,   217,   236,     0,     0,
       0,  -414,     0,     0,     0,     0,     0,     0,     0,   236,
       0,     0,   218,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   236,     0,     0,   637,
       0,     0,     0,     0,   637,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   567,   569,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,     0,     0,     0,     0,     0,
       0,     0,   596,     0,   597,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     637,   637,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,    48,    49,    50,
     219,   220,    64,    65,     0,   221,     0,     0,     0,   236,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,    48,    49,    50,   219,   220,
      64,    65,     0,   221,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   658,   659,   660,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   669,     0,     0,
     670,     0,     0,     0,     0,   671,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   674,   566,     0,
       0,   675,     0,     0,     0,   676,     0,     0,     0,     0,
       0,     0,   677,     0,     0,     0,     0,     0,     0,   258,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     688,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     259,   260,     0,   261,   107,     0,   108,   109,   110,   111,
     112,   113,   114,   115,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,     0,   127,     0,     0,
       0,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,     0,     0,     0,     0,     0,   136,     0,   137,     0,
       0,   138,   139,     0,   140,     0,   141,   142,   143,     0,
     144,   145,     0,   146,     0,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   800,     0,   801,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,    48,    49,    50,   105,     0,    64,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   107,     0,   108,   109,   110,   111,   112,   113,
     114,   115,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,     0,   127,     0,     0,   856,   128,
     129,   130,   131,   132,   133,   134,   135,     0,     0,     0,
       0,     0,     0,     0,   136,     0,   137,     0,     0,   138,
     139,     0,   140,     0,   141,   142,   143,     0,   144,   145,
       0,   146,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   778,
     779,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   258,     0,     0,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,    48,    49,    50,     0,     0,    64,    65,   107,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   628,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
       0,   127,     0,   213,   214,   215,   216,   217,     0,     0,
       0,     0,   135,   607,     0,     0,     0,     0,     0,     0,
     136,     0,   137,   218,     0,   138,   139,     0,   140,     0,
     141,   142,   143,     0,   144,   145,     0,   146,   628,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   213,   214,   215,   216,   217,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   218,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    50,
       0,     0,    64,    65,     0,   639,     0,     0,   629,     0,
       0,     0,     0,     0,     0,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
      48,    49,    50,     0,     0,    64,    65,     0,     0,     0,
       0,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,    48,    49,    50,   219,
     220,    64,    65,     0,   221,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
      48,    49,    50,     0,     0,    64,    65,     0,     0,     0,
       0,     0,     0,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,    48,    49,
      50,   219,   220,    64,    65,   258,   221,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   259,   260,     0,   261,
     107,     0,   108,   109,   110,   111,   112,   113,   114,   115,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,     0,   127,     0,     0,     0,   128,   129,   130,
     131,   132,   133,   134,   135,     0,     0,     0,     0,     0,
       0,     0,   136,     0,   137,     0,     0,   138,   139,     0,
     140,     0,   141,   142,   143,     0,   144,   145,     0,   146,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   106,     0,     0,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,    48,
      49,    50,     0,     0,    64,    65,   107,     0,   108,   109,
     110,   111,   112,   113,   114,   115,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,     0,   127,
       0,     0,     0,   128,   129,   130,   131,   132,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,   136,     0,
     137,     0,     0,   138,   139,     0,   140,     0,   141,   142,
     143,     0,   144,   145,     0,   146,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   258,     0,     0,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,    48,    49,    50,     0,     0,
      64,    65,   107,     0,   108,   109,   110,   111,   112,   113,
     114,   115,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,     0,   127,     0,     0,     0,   128,
     129,   130,   131,   132,   133,   134,   135,     0,     0,     0,
       0,     0,     0,     0,   136,     0,   137,     0,     0,   138,
     139,     0,   140,     0,   141,   142,   143,     0,   144,   145,
       0,   146,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   878,
     628,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   610,     0,     0,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,    48,    49,    50,     0,     0,    64,    65,   107,   628,
     108,   109,   110,   111,   112,   113,   114,   115,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
       0,   127,   880,   628,     0,     0,     0,     0,     0,     0,
       0,     0,   135,     0,     0,     0,     0,     0,     0,     0,
     136,     0,   137,     0,     0,   138,   139,     0,   140,     0,
     141,   142,   143,     0,   144,   145,     0,   146,     0,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,     0,     0,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,    48,    49,    50,     0,     0,    64,    65,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    50,
       0,     0,    64,    65,     0,     0,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,    48,    49,    50,     0,     0,    64,    65,   258,     0,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,    48,    49,    50,     0,     0,
      64,    65,     0,   107,     0,   108,   109,   110,   111,   112,
     113,   114,   115,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,     0,   127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   135,     0,     0,
       0,     0,     0,     0,     0,   136,     0,   137,     0,     0,
     138,   139,     0,   140,     0,   141,   142,   143,     0,   144,
     145,     0,   146,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    49,    50
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        12,    60,    18,    14,    15,    84,    18,    60,    20,   506,
      21,    22,   372,   368,    25,    60,   353,   127,    74,   207,
     199,    29,    19,    79,   664,    40,    22,    18,    37,   494,
      75,    40,    77,    23,    40,    37,    36,    36,   372,   822,
      36,   372,    23,    39,    87,    48,    40,   813,    60,     6,
      66,    39,   310,    19,    66,    60,   839,   871,    43,    67,
      37,   421,    55,    75,   102,    77,    40,     3,     4,    60,
      40,    48,    22,    14,    43,    66,    50,   691,   179,   180,
      50,    40,   340,   897,    75,    97,    77,   421,   346,    39,
      64,    50,    19,   281,    64,    50,    40,    63,     6,     7,
       0,    94,    60,    50,   365,    64,    50,   145,    41,    36,
     724,    50,   373,    41,    14,    48,   476,    75,   106,    77,
      48,   180,    30,   202,   671,   174,   486,   180,   675,    37,
     100,    36,   469,   102,    61,   180,    44,    45,   181,    47,
       0,   100,   476,   640,   910,    36,    12,   104,    36,   932,
      36,   616,   486,   100,   199,   486,   100,   157,   161,   161,
       8,   157,    10,    11,   149,    13,   780,   182,   180,    37,
     810,    36,    40,   182,   101,   180,   182,   174,   175,   176,
     179,   180,   179,   180,   174,   175,   176,   199,   182,   180,
       6,   203,   200,   174,   175,   176,   384,   102,    30,   211,
     174,   175,   176,    15,   174,   175,   176,    23,   199,   179,
     180,   102,   120,    17,    18,   174,   175,   176,     9,   174,
     175,   176,   180,     6,   179,   180,   691,   174,   175,   176,
     174,   175,   176,     4,   142,   174,   175,   176,    28,    29,
     145,   199,   147,    49,   149,   170,   171,   172,   173,    74,
     605,    40,   157,    40,   145,   103,   147,   108,   149,   724,
      61,    62,   110,   111,   148,   149,   114,    40,   116,   182,
     174,   175,   176,   352,    43,   123,    40,   125,    40,   776,
      55,    56,    57,    58,    59,    60,    40,   466,   104,   105,
      65,    66,    40,   174,   175,   176,   406,    60,   179,   180,
     143,   144,   799,    40,   664,    40,   362,    40,   364,    40,
     301,    40,    75,    40,    77,   780,    40,   782,    40,   375,
      86,    87,    40,   368,   259,   260,   261,   372,    40,   341,
     664,   399,   400,   401,   402,   403,   404,   530,   531,   536,
     537,    40,    40,   355,    40,   842,    40,    40,   182,    40,
     847,    40,    40,   365,    40,    40,   368,    40,    40,   371,
     372,   373,    40,   164,   165,   166,   167,   168,   169,    40,
      40,    40,    40,   385,   365,    40,   421,   368,    40,    40,
     371,   372,   373,    40,    40,   376,    40,    40,    40,    40,
      40,    40,   108,    37,    40,    37,   175,   108,    90,    89,
      55,    17,    37,   394,    43,     6,   903,   904,    25,   421,
     368,    91,    41,   773,   372,    41,    53,   180,   528,    66,
      54,   466,    41,    41,    48,    48,    41,    48,    41,    41,
     421,   476,    41,    41,   493,   494,   199,    48,    48,   773,
     493,   486,    41,    41,    41,    41,    48,    41,    41,    41,
     810,    41,    41,    41,   466,    41,    41,    48,   503,    41,
      41,   506,   822,   421,   476,   802,    41,    41,    48,    41,
      48,    41,    41,    41,   486,   466,   810,    41,    41,   839,
      41,   493,   494,    48,    41,   476,   498,    41,   822,    41,
      52,   503,    43,     6,   506,   486,    24,   174,   102,    16,
      37,   149,   493,    43,    25,   839,    41,    41,   466,   149,
      48,    41,   503,    49,    41,   506,    41,    41,   476,   102,
      49,    41,   877,    41,    29,    48,    41,    28,   486,    48,
     161,   161,    39,    41,    40,   102,    75,    41,   726,    41,
      36,    41,    40,    55,    41,   503,    41,    63,   506,    41,
      49,     8,   611,    10,    11,   161,    13,   616,   611,    16,
     605,    48,    46,    20,    21,    37,    37,    89,    41,   102,
      37,   851,   932,   644,   796,   509,   243,   646,   630,   799,
     512,    38,   640,   547,   688,   630,   611,   355,   616,   780,
     606,   697,    56,   605,   606,   640,   180,   696,   932,   611,
     663,    89,   243,    26,   616,   368,   729,    77,   280,   372,
     466,   773,   679,   667,   605,   606,   771,   805,   630,   664,
     611,   912,   742,   811,   867,   869,   745,   520,   640,   518,
     532,   675,   691,   409,   875,   409,    -1,    -1,    -1,   630,
     719,    -1,    -1,    -1,    -1,    -1,   103,   605,    -1,   640,
      -1,    -1,   664,   110,   111,   667,   668,   114,   421,   116,
      -1,    -1,    -1,    -1,    -1,   724,   123,   855,   125,    -1,
      -1,    -1,   630,   664,    -1,    -1,   667,   668,    -1,   691,
      -1,    -1,   640,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     691,    -1,    -1,   466,    -1,    -1,   664,    -1,    -1,    -1,
      -1,    -1,   724,   476,    -1,    -1,    -1,   905,    -1,    -1,
      -1,   780,    -1,   486,    -1,    -1,    -1,    -1,   773,    -1,
     742,   776,   744,   745,   922,    -1,   924,    -1,    -1,    -1,
     503,    -1,    -1,   506,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   796,    -1,    -1,   799,    -1,    -1,    -1,    -1,   771,
      -1,   773,    -1,    -1,   776,   810,    -1,    -1,   780,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   822,    -1,    -1,
     771,    -1,   773,    -1,   796,   776,    -1,   799,    -1,   780,
      -1,    -1,    -1,    -1,   839,    -1,    -1,   842,   810,    -1,
      -1,   813,   847,   815,    -1,   796,    -1,    -1,   799,    -1,
     822,    -1,    -1,    -1,    -1,   773,    -1,    -1,   776,   810,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   839,    -1,    -1,
     842,   822,   877,    -1,    -1,   847,   852,    -1,   796,    -1,
     852,   799,   605,    -1,    -1,    -1,    -1,    -1,   839,    -1,
      -1,   842,   810,    -1,    -1,   867,   847,   869,   903,   904,
      -1,   852,    -1,    -1,   822,   877,    -1,   630,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   886,    -1,   640,    -1,    -1,
      -1,   839,    -1,    -1,   842,    -1,   877,   932,    -1,   847,
     906,   903,   904,    -1,   906,    -1,    -1,   888,   910,    -1,
     912,   664,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   903,   904,    -1,   906,    -1,    -1,   258,   877,
     932,   912,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   932,   282,   283,   284,   903,   904,   287,    -1,    -1,
     290,   291,   292,    -1,    -1,    -1,    -1,   297,   298,   299,
     300,    -1,   302,   303,   304,   305,   306,   307,    -1,    -1,
      -1,   311,   312,   313,   932,   315,    -1,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     773,    -1,    -1,   776,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   796,    51,    -1,   799,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,   810,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   822,
      -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   839,    -1,    -1,   842,
      -1,    -1,    -1,    -1,   847,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   434,   435,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   877,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   462,    -1,   464,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     903,   904,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,   182,    -1,    -1,    -1,   932,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   543,   544,   545,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   557,    -1,    -1,
     560,    -1,    -1,    -1,    -1,   565,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   577,    19,    -1,
      -1,   581,    -1,    -1,    -1,   585,    -1,    -1,    -1,    -1,
      -1,    -1,   592,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     610,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    -1,    64,    65,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    -1,    -1,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,   109,    -1,
      -1,   112,   113,    -1,   115,    -1,   117,   118,   119,    -1,
     121,   122,    -1,   124,    -1,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   714,    -1,   716,    -1,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,    19,    -1,   179,   180,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    -1,    -1,   808,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,    -1,   109,    -1,    -1,   112,
     113,    -1,   115,    -1,   117,   118,   119,    -1,   121,   122,
      -1,   124,    -1,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,    -1,    -1,   179,   180,    65,    -1,
      67,    68,    69,    70,    71,    72,    73,    74,    42,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    -1,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    99,    41,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,   109,    51,    -1,   112,   113,    -1,   115,    -1,
     117,   118,   119,    -1,   121,   122,    -1,   124,    42,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,   175,   176,
      -1,    -1,   179,   180,    -1,   149,    -1,    -1,   102,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,   179,   180,    -1,    -1,    -1,
      -1,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,    -1,   182,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,   179,   180,    -1,    -1,    -1,
      -1,    -1,    -1,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,    40,   182,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,    64,
      65,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   107,    -1,   109,    -1,    -1,   112,   113,    -1,
     115,    -1,   117,   118,   119,    -1,   121,   122,    -1,   124,
      -1,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,    -1,    -1,   179,   180,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    88,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,
     109,    -1,    -1,   112,   113,    -1,   115,    -1,   117,   118,
     119,    -1,   121,   122,    -1,   124,    -1,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,    -1,    -1,
     179,   180,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,    -1,   109,    -1,    -1,   112,
     113,    -1,   115,    -1,   117,   118,   119,    -1,   121,   122,
      -1,   124,    -1,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,    -1,    -1,   179,   180,    65,    42,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,   109,    -1,    -1,   112,   113,    -1,   115,    -1,
     117,   118,   119,    -1,   121,   122,    -1,   124,    -1,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,    -1,    -1,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    -1,    -1,   179,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,   175,   176,
      -1,    -1,   179,   180,    -1,    -1,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,    -1,    -1,   179,   180,    40,    -1,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,    -1,    -1,
     179,   180,    -1,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,    -1,   109,    -1,    -1,
     112,   113,    -1,   115,    -1,   117,   118,   119,    -1,   121,
     122,    -1,   124,    -1,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   174,   175,   176
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    14,   184,   185,   186,   189,   190,   226,   288,   289,
     174,     0,     8,    10,    11,    13,    16,    20,    21,    38,
     103,   110,   111,   114,   116,   123,   125,   187,   230,   235,
     244,   246,   250,   294,   295,   298,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   191,   174,   175,
     176,   501,   502,    12,   299,   299,   299,    17,    18,   236,
     237,    36,   379,    19,   179,   180,   247,   248,   450,   451,
     501,   231,   501,   299,   299,    36,   322,    36,   323,   299,
     323,    30,   188,   280,   231,   290,     3,     4,   312,   314,
     315,    15,   192,   227,     9,   296,   297,     6,    23,   104,
     105,   320,   321,   320,   321,    19,    40,    65,    67,    68,
      69,    70,    71,    72,    73,    74,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    88,    92,    93,
      94,    95,    96,    97,    98,    99,   107,   109,   112,   113,
     115,   117,   118,   119,   121,   122,   124,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   240,   241,
     242,   243,   371,   451,   476,   478,   480,   481,   482,   483,
     486,   491,   495,   496,   497,   498,   499,   500,   501,   380,
     245,   450,   231,    22,    39,   251,   256,   257,     6,   104,
     318,   319,   318,    31,    32,    33,    34,    35,    51,   177,
     178,   182,   324,   325,   333,   385,   441,   442,   444,   445,
     446,   449,   451,   452,   491,   495,   499,   501,   503,   324,
     318,   281,   256,    49,   292,   293,   322,   322,   313,   311,
     315,   228,   157,   193,   195,   196,   320,   501,    40,    61,
      62,    64,   451,   453,   454,   457,   460,   461,   464,   465,
     471,   473,   474,   475,   476,   483,   489,   491,   495,   499,
     501,    74,    40,    40,    40,   182,   477,    40,   182,   377,
      40,    40,    40,    36,   157,   336,   338,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,   377,    40,
      40,    40,    40,    40,   182,    40,   182,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,   241,
      40,    87,   181,   492,   493,   494,    40,   182,   372,   381,
     382,   385,   231,   249,   256,    23,   252,   253,   254,   255,
     501,   336,   108,   501,   108,   443,    37,   328,    43,   334,
     335,   387,    40,   386,    37,   108,   282,    90,   258,   259,
     263,   189,   289,   291,    39,   106,   316,   175,    55,   194,
     453,   474,   474,   474,    89,   238,   239,   456,   459,    55,
      56,    57,    58,    59,    60,    65,    66,   462,   463,   470,
     472,   372,   490,   336,   453,   453,   453,   453,   453,   453,
     453,   339,   453,   453,   453,   453,   451,   453,   453,   453,
     453,   453,   453,    17,   374,   374,   453,   453,   453,   453,
     453,   453,   453,   453,   453,   453,   453,   453,   453,   453,
     453,   453,   453,   453,   453,   453,   453,   453,   453,   453,
     453,   453,   374,   501,   374,    37,    43,   383,   384,   256,
     258,   255,   318,   318,    50,   388,   399,   450,   327,   329,
     330,   325,   388,   393,   394,   441,   447,   448,   449,   388,
     318,    36,   451,    25,    91,   260,   266,   336,    23,   317,
     501,   229,    36,   102,   145,   147,   149,   197,   198,   200,
     201,   208,   210,   211,   218,    41,   451,    41,    53,   455,
      54,   458,   464,   464,   464,   464,   464,   464,    66,   377,
      61,    62,   466,   469,   497,   498,    19,    63,   467,    41,
      41,    41,   378,    48,    48,    48,   232,   233,   337,   340,
     341,   344,   400,   441,   449,    41,    41,    48,    41,    41,
      48,    41,    41,    41,    41,    48,    19,   453,   485,   453,
      41,    41,    41,    41,    41,    41,    41,    48,    41,    41,
      41,    48,    41,    41,    41,    48,    41,    41,    41,    41,
      41,    41,    48,    41,    41,    41,   453,   453,   381,   258,
      52,   395,   398,   448,    43,   326,     6,    41,   448,   286,
      40,   264,   265,   371,   451,   476,   267,   268,   370,   371,
     475,   476,    24,   261,   269,   501,   174,   219,    42,   102,
     202,   203,   206,   287,   451,   491,   495,   499,   501,   149,
     212,   213,   216,   287,   201,   199,   211,   209,   457,   460,
     377,   471,   471,   467,   468,   473,   473,   376,   453,   453,
     453,   235,    37,   343,    43,   345,   346,   402,   401,   453,
     453,   453,    41,   484,   453,   453,   453,   453,    41,   373,
     392,   397,   325,   450,    37,    40,   182,   284,   453,   265,
     268,    25,    28,    29,   262,   275,   278,   279,    37,    40,
     220,   206,   102,   216,   149,   199,    43,   102,   204,   209,
      43,   149,   214,    41,    48,   375,    48,    41,    41,   234,
       6,     7,    44,    45,    47,   120,   142,   280,   342,   347,
     348,   349,   351,   355,   359,   360,   363,   364,   369,   341,
     394,   411,    40,    50,    64,   100,   403,   405,   412,   413,
     414,   415,   418,   421,   423,   429,   430,   451,   501,    41,
      41,   375,   479,    49,   487,   488,    41,   479,    41,    41,
     376,    49,   391,    48,   396,   331,   285,   239,    26,    27,
     270,   271,   272,   273,   274,   370,   451,   161,   161,   276,
     279,   277,   278,   221,   145,   207,   205,   148,   217,   215,
     453,   453,   256,   352,   356,   350,   361,   370,    40,   336,
     326,   365,   414,    40,    50,   100,   431,   436,   437,   439,
     501,   421,   404,   417,   420,    19,    36,    61,   101,   422,
     424,   428,    41,    75,    41,    41,    41,   389,   390,   399,
     398,    36,   283,   287,    41,   271,   475,   224,   203,   213,
      41,   258,   353,   357,   336,   362,   453,   341,   336,    41,
     434,   435,   437,    50,   438,   501,   395,   102,   416,    63,
     419,    48,   161,   427,   440,    55,   395,   332,    41,   287,
      41,   223,   225,   287,   188,   450,   358,   336,    89,   368,
      41,   433,   410,   418,   423,   440,    37,    48,   426,   500,
     325,    48,   222,   143,   144,   354,   299,   451,    46,   366,
     102,   432,    49,   409,    37,    37,   425,   440,    37,   287,
     287,   336,   450,    41,   367,   437,   405,   406,   408,    37,
     336,   336,   407,   395
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
     227,   230,   231,   231,   233,   234,   232,   235,   236,   236,
     237,   237,   238,   239,   239,   240,   241,   241,   241,   241,
     241,   241,   241,   241,   242,   242,   243,   243,   245,   244,
     246,   247,   247,   248,   248,   249,   249,   250,   251,   252,
     252,   253,   254,   255,   256,   257,   257,   258,   259,   259,
     260,   260,   261,   261,   262,   262,   263,   264,   264,   265,
     265,   265,   265,   266,   267,   267,   268,   269,   270,   270,
     271,   271,   272,   272,   273,   274,   274,   275,   275,   276,
     276,   277,   277,   278,   279,   281,   280,   282,   282,   283,
     283,   285,   284,   284,   286,   286,   287,   287,   287,   287,
     287,   287,   288,   290,   289,   291,   291,   292,   293,   293,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   295,   296,   297,   297,   298,   299,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   310,
     311,   311,   312,   312,   313,   313,   314,   315,   316,   317,
     317,   318,   318,   319,   319,   320,   321,   321,   321,   321,
     322,   323,   324,   325,   325,   326,   326,   327,   328,   328,
     330,   331,   332,   329,   333,   334,   335,   335,   336,   336,
     337,   337,   339,   338,   340,   341,   341,   342,   343,   343,
     344,   345,   346,   346,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   348,   350,   349,   352,   353,   354,   351,
     356,   357,   358,   355,   359,   361,   362,   360,   364,   365,
     363,   367,   366,   368,   368,   369,   370,   370,   370,   371,
     372,   373,   372,   374,   374,   375,   376,   376,   377,   378,
     377,   380,   379,   381,   381,   382,   383,   384,   384,   386,
     385,   387,   385,   388,   389,   390,   390,   391,   392,   392,
     393,   394,   394,   395,   396,   397,   397,   398,   399,   399,
     401,   400,   402,   400,   404,   403,   405,   405,   407,   406,
     408,   408,   409,   410,   410,   411,   412,   413,   414,   415,
     416,   417,   417,   418,   419,   420,   420,   421,   422,   422,
     423,   423,   424,   425,   425,   426,   426,   427,   427,   428,
     428,   428,   428,   429,   430,   430,   430,   430,   431,   432,
     433,   433,   434,   435,   435,   436,   436,   437,   438,   438,
     439,   439,   439,   440,   441,   441,   443,   442,   444,   445,
     445,   445,   445,   445,   446,   446,   447,   447,   448,   448,
     449,   449,   450,   450,   451,   451,   452,   452,   452,   452,
     452,   452,   453,   454,   455,   456,   456,   457,   458,   459,
     459,   460,   461,   462,   462,   463,   463,   463,   463,   463,
     463,   463,   463,   464,   465,   466,   466,   467,   467,   468,
     468,   469,   469,   469,   470,   470,   471,   472,   472,   473,
     473,   473,   473,   474,   474,   474,   474,   474,   474,   474,
     474,   475,   476,   476,   476,   476,   476,   476,   476,   476,
     476,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     476,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     476,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     476,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     476,   477,   477,   478,   479,   479,   480,   481,   482,   483,
     483,   484,   483,   485,   485,   486,   486,   486,   486,   486,
     487,   488,   488,   489,   490,   490,   491,   492,   493,   493,
     494,   494,   495,   495,   495,   496,   496,   496,   497,   497,
     497,   498,   498,   498,   499,   499,   500,   500,   500,   500,
     501,   501,   502,   502,   503,   503
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
       5,     4,     0,     2,     0,     0,     6,     3,     1,     1,
       0,     1,     2,     0,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     0,     6,
       5,     1,     2,     1,     1,     0,     1,     3,     2,     1,
       1,     1,     2,     1,     2,     0,     1,     4,     0,     1,
       0,     1,     0,     1,     0,     1,     3,     1,     2,     1,
       1,     4,     1,     2,     1,     2,     1,     3,     1,     2,
       1,     1,     1,     1,     2,     1,     1,     2,     2,     0,
       1,     0,     1,     2,     2,     0,     6,     0,     2,     1,
       2,     0,     4,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     0,     4,     0,     1,     2,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     0,     1,     3,     0,     1,     3,     3,
       5,     5,     5,     2,     2,     2,     5,     2,     0,     1,
       0,     1,     2,     1,     0,     2,     2,     2,     2,     1,
       2,     1,     2,     0,     1,     2,     1,     1,     1,     1,
       3,     3,     2,     0,     1,     0,     1,     3,     0,     2,
       0,     0,     0,     8,     2,     2,     0,     1,     1,     1,
       1,     1,     0,     4,     2,     0,     1,     3,     0,     2,
       2,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     3,     0,     0,     0,     6,
       0,     0,     0,     7,     6,     0,     0,     4,     0,     0,
       4,     0,     3,     0,     2,     2,     1,     1,     1,     2,
       1,     0,     6,     0,     1,     2,     0,     2,     1,     0,
       5,     0,     4,     0,     1,     2,     2,     0,     1,     0,
       3,     0,     3,     3,     2,     0,     1,     2,     0,     2,
       1,     0,     1,     2,     2,     0,     2,     1,     1,     1,
       0,     3,     0,     3,     0,     4,     1,     1,     0,     3,
       0,     1,     2,     0,     2,     1,     1,     1,     1,     2,
       2,     0,     2,     2,     2,     0,     2,     2,     0,     1,
       1,     2,     1,     1,     2,     2,     1,     2,     3,     1,
       1,     1,     2,     1,     1,     1,     2,     3,     1,     2,
       0,     2,     2,     0,     1,     1,     3,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     0,     4,     4,     1,
       1,     1,     1,     1,     0,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     0,     2,     2,     2,     0,
       2,     1,     2,     0,     1,     2,     2,     2,     2,     2,
       2,     2,     3,     1,     2,     1,     1,     2,     2,     0,
       1,     2,     2,     2,     0,     2,     2,     0,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     4,     6,     4,     4,     4,     4,     2,
       2,     4,     4,     4,     4,     2,     1,     4,     4,     4,
       4,     6,     6,     6,     4,     4,     4,     4,     4,     4,
       4,     2,     4,     4,     4,     4,     4,     4,     2,     8,
       6,     6,     6,     4,     4,     4,     4,     4,     1,     1,
       1,     3,     1,     7,     0,     1,     7,     2,     3,     5,
       5,     0,     7,     1,     1,     1,     1,     1,     1,     1,
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
  "PrefixDecl", "$@5", "$@6", "SelectQuery", "_QDatasetClause_E_Star",
  "SubSelect", "@7", "@8", "SelectClause",
  "_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C",
  "_Q_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C_E_Opt", "_O_QIT_AS_E_S_QVar_E_C",
  "_Q_O_QIT_AS_E_S_QVar_E_C_E_Opt",
  "_O_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_Q_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C_E_Plus",
  "_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_Plus_Or_QGT_TIMES_E_C",
  "ConstructQuery", "$@9", "DescribeQuery", "_QVarOrIRIref_E_Plus",
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
  "OffsetClause", "BindingsClause", "$@10", "_QVar_E_Star",
  "_QBindingValue_E_Plus",
  "_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C",
  "$@11",
  "_Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star",
  "BindingValue", "UpdateUnit", "Update", "$@12", "_QUpdate_E_Opt",
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
  "QuadsNotTriples", "@13", "@14", "$@15", "TriplesTemplate",
  "_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C_E_Opt", "GroupGraphPattern",
  "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C",
  "_O_QGT_LCURLEY_E_S_QSubSelect_E_Or_QGroupGraphPatternSub_E_S_QGT_RCURLEY_E_C",
  "$@16", "GroupGraphPatternSub", "_QTriplesBlock_E_Opt",
  "_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "Print", "OptionalGraphPattern", "@17", "GraphGraphPattern", "@18",
  "@19", "@20", "ServiceGraphPattern", "@21", "@22", "@23", "Bind",
  "MinusGraphPattern", "@24", "@25", "GroupOrUnionGraphPattern", "@26",
  "@27", "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@28",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "@29", "_QIT_DISTINCT_E_Opt",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ExpressionList", "@30",
  "ConstructTemplate", "$@31", "_QConstructTriples_E_Opt",
  "ConstructTriples", "_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C_E_Opt", "TriplesSameSubject",
  "$@32", "$@33", "PropertyListNotEmpty", "_O_QVerb_E_S_QObjectList_E_C",
  "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "Verb", "TriplesSameSubjectPath", "$@34", "$@35",
  "PropertyListNotEmptyPath", "$@36", "_O_QVerbPath_E_Or_QVerbSimple_E_C",
  "_O_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_C", "$@37",
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
  "Integer", "TriplesNode", "BlankNodePropertyList", "@38", "Generator",
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
  "SubstringExpression", "ExistsFunc", "NotExistsFunc", "Aggregate", "@39",
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
       184,     0,    -1,   185,    -1,   288,    -1,   186,    -1,   189,
     187,   188,    -1,   230,    -1,   244,    -1,   246,    -1,   250,
      -1,    -1,   280,    -1,   190,   191,   192,    -1,    -1,   226,
      -1,    -1,   191,   227,    -1,    -1,   192,   193,    -1,    -1,
     196,   194,   197,    -1,   157,    55,    -1,    -1,   195,    -1,
     198,    -1,   208,    -1,   218,    -1,   200,   201,   199,   207,
      -1,   201,   199,    43,    -1,    -1,   199,   204,    -1,   145,
      -1,   102,   203,    -1,   206,    -1,   202,   206,    -1,   102,
      -1,   202,    -1,    -1,   102,   205,   203,    -1,   287,   102,
      -1,   145,    -1,   210,   211,   209,   217,    -1,   211,   209,
      43,    -1,    -1,   209,   214,    -1,   147,    -1,   149,   213,
      -1,   216,    -1,   212,   216,    -1,   149,    -1,   212,    -1,
      -1,   149,   215,   213,    -1,   287,   149,    -1,   148,    -1,
      36,   219,    37,    -1,    -1,   219,   220,    -1,    -1,    40,
     221,   224,    41,    -1,    -1,    48,    -1,   225,   222,    -1,
      -1,   224,   223,    -1,   287,   144,   287,    -1,   287,   143,
     287,    -1,    14,   174,    -1,    -1,    -1,    15,   228,   175,
     229,   174,    -1,   235,   231,   256,   258,    -1,    -1,   231,
     251,    -1,    -1,    -1,   233,   235,   234,   256,   258,   188,
      -1,    16,   237,   243,    -1,    17,    -1,    18,    -1,    -1,
     236,    -1,    89,   451,    -1,    -1,   238,    -1,    40,   453,
     239,    41,    -1,   451,    -1,   483,    -1,   476,    -1,   371,
      -1,   491,    -1,   495,    -1,   499,    -1,   240,    -1,   241,
      -1,   242,   241,    -1,   242,    -1,    19,    -1,    -1,    20,
     379,   245,   231,   256,   258,    -1,    21,   248,   231,   249,
     258,    -1,   450,    -1,   247,   450,    -1,   247,    -1,    19,
      -1,    -1,   256,    -1,    38,   231,   256,    -1,    22,   252,
      -1,   253,    -1,   254,    -1,   255,    -1,    23,   255,    -1,
     501,    -1,   257,   336,    -1,    -1,    39,    -1,   259,   260,
     261,   262,    -1,    -1,   263,    -1,    -1,   266,    -1,    -1,
     269,    -1,    -1,   275,    -1,    90,    25,   264,    -1,   265,
      -1,   264,   265,    -1,   476,    -1,   371,    -1,    40,   453,
     239,    41,    -1,   451,    -1,    91,   267,    -1,   268,    -1,
     267,   268,    -1,   370,    -1,    24,    25,   270,    -1,   271,
      -1,   270,   271,    -1,   273,    -1,   274,    -1,    26,    -1,
      27,    -1,   272,   475,    -1,   370,    -1,   451,    -1,   278,
     276,    -1,   279,   277,    -1,    -1,   279,    -1,    -1,   278,
      -1,    28,   161,    -1,    29,   161,    -1,    -1,    30,   281,
     282,    36,   286,    37,    -1,    -1,   282,   451,    -1,   287,
      -1,   283,   287,    -1,    -1,    40,   285,   283,    41,    -1,
     182,    -1,    -1,   286,   284,    -1,   501,    -1,   491,    -1,
     495,    -1,   499,    -1,    42,    -1,   451,    -1,   289,    -1,
      -1,   189,   294,   290,   293,    -1,    -1,   289,    -1,    49,
     291,    -1,    -1,   292,    -1,   295,    -1,   298,    -1,   300,
      -1,   302,    -1,   303,    -1,   304,    -1,   301,    -1,   305,
      -1,   306,    -1,   307,    -1,   308,    -1,     8,   501,   297,
      -1,     9,   320,    -1,    -1,   296,    -1,    10,   299,   321,
      -1,    -1,    12,    -1,    13,   299,   321,    -1,    11,   299,
     320,    -1,   110,   299,   318,   108,   318,    -1,   123,   299,
     318,   108,   318,    -1,   111,   299,   318,   108,   318,    -1,
     125,   323,    -1,   116,   323,    -1,   114,   322,    -1,   310,
     312,   313,    39,   336,    -1,   103,   501,    -1,    -1,   309,
      -1,    -1,   315,    -1,   314,   311,    -1,   315,    -1,    -1,
     313,   316,    -1,     3,   322,    -1,     4,   322,    -1,   106,
     317,    -1,   501,    -1,    23,   501,    -1,   104,    -1,   319,
     501,    -1,    -1,     6,    -1,     6,   501,    -1,   320,    -1,
     104,    -1,    23,    -1,   105,    -1,    36,   324,    37,    -1,
      36,   324,    37,    -1,   325,   328,    -1,    -1,   333,    -1,
      -1,    43,    -1,   329,   326,   325,    -1,    -1,   328,   327,
      -1,    -1,    -1,    -1,   330,     6,   450,   331,    36,   332,
     325,    37,    -1,   385,   335,    -1,    43,   325,    -1,    -1,
     334,    -1,   338,    -1,   157,    -1,   232,    -1,   340,    -1,
      -1,    36,   339,   337,    37,    -1,   341,   343,    -1,    -1,
     344,    -1,   347,   326,   341,    -1,    -1,   343,   342,    -1,
     400,   346,    -1,    43,   341,    -1,    -1,   345,    -1,   363,
      -1,   349,    -1,   360,    -1,   351,    -1,   355,    -1,   369,
      -1,   359,    -1,   280,    -1,   348,    -1,   142,   336,    -1,
      -1,    44,   350,   336,    -1,    -1,    -1,    -1,     6,   352,
     353,   450,   354,   336,    -1,    -1,    -1,    -1,     7,   356,
     357,   358,   299,   450,   336,    -1,   120,    40,   453,    89,
     451,    41,    -1,    -1,    -1,    45,   361,   362,   336,    -1,
      -1,    -1,   364,   365,   336,   368,    -1,    -1,    46,   367,
     336,    -1,    -1,   368,   366,    -1,    47,   370,    -1,   475,
      -1,   476,    -1,   371,    -1,   501,   372,    -1,   182,    -1,
      -1,    40,   374,   453,   373,   376,    41,    -1,    -1,    17,
      -1,    48,   453,    -1,    -1,   376,   375,    -1,   182,    -1,
      -1,    40,   453,   378,   376,    41,    -1,    -1,    36,   380,
     381,    37,    -1,    -1,   382,    -1,   385,   384,    -1,    43,
     381,    -1,    -1,   383,    -1,    -1,   449,   386,   388,    -1,
      -1,   441,   387,   393,    -1,   399,   395,   392,    -1,   399,
     395,    -1,    -1,   389,    -1,    49,   390,    -1,    -1,   392,
     391,    -1,   394,    -1,    -1,   388,    -1,   398,   397,    -1,
      48,   398,    -1,    -1,   397,   396,    -1,   448,    -1,   450,
      -1,    50,    -1,    -1,   449,   401,   403,    -1,    -1,   441,
     402,   411,    -1,    -1,   405,   404,   395,   410,    -1,   412,
      -1,   413,    -1,    -1,   405,   407,   395,    -1,    -1,   406,
      -1,    49,   408,    -1,    -1,   410,   409,    -1,   394,    -1,
     414,    -1,   451,    -1,   415,    -1,   418,   417,    -1,   102,
     418,    -1,    -1,   417,   416,    -1,   423,   420,    -1,    63,
     423,    -1,    -1,   420,   419,    -1,   429,   422,    -1,    -1,
     424,    -1,   421,    -1,   100,   421,    -1,   428,    -1,    37,
      -1,   440,    37,    -1,    48,   425,    -1,    37,    -1,   440,
     426,    -1,    48,   440,    37,    -1,    19,    -1,   101,    -1,
      61,    -1,    36,   427,    -1,   430,    -1,   501,    -1,    50,
      -1,    64,   431,    -1,    40,   414,    41,    -1,   436,    -1,
     102,   437,    -1,    -1,   433,   432,    -1,   437,   433,    -1,
      -1,   434,    -1,   437,    -1,    40,   435,    41,    -1,   439,
      -1,   501,    -1,    50,    -1,   501,    -1,    50,    -1,   100,
     438,    -1,   161,    -1,   444,    -1,   442,    -1,    -1,    51,
     443,   388,    52,    -1,   446,    40,   447,    41,    -1,    31,
      -1,    32,    -1,    33,    -1,    34,    -1,    35,    -1,    -1,
     445,    -1,   448,    -1,   447,   448,    -1,   449,    -1,   441,
      -1,   451,    -1,   452,    -1,   451,    -1,   501,    -1,   179,
      -1,   180,    -1,   501,    -1,   491,    -1,   495,    -1,   499,
      -1,   503,    -1,   182,    -1,   454,    -1,   457,   456,    -1,
      53,   457,    -1,    -1,   456,   455,    -1,   460,   459,    -1,
      54,   460,    -1,    -1,   459,   458,    -1,   461,    -1,   464,
     462,    -1,    -1,   463,    -1,    55,   464,    -1,    56,   464,
      -1,    57,   464,    -1,    58,   464,    -1,    59,   464,    -1,
      60,   464,    -1,    66,   377,    -1,    65,    66,   377,    -1,
     465,    -1,   471,   470,    -1,   497,    -1,   498,    -1,    19,
     473,    -1,    63,   473,    -1,    -1,   467,    -1,    61,   471,
      -1,    62,   471,    -1,   466,   468,    -1,    -1,   470,   469,
      -1,   473,   472,    -1,    -1,   472,   467,    -1,    64,   474,
      -1,    61,   474,    -1,    62,   474,    -1,   474,    -1,   475,
      -1,   476,    -1,   489,    -1,   491,    -1,   495,    -1,   499,
      -1,   451,    -1,   483,    -1,    40,   453,    41,    -1,    76,
      40,   453,    41,    -1,    77,    40,   453,    41,    -1,    78,
      40,   453,    48,   453,    41,    -1,    79,    40,   453,    41,
      -1,    80,    40,   451,    41,    -1,    67,    40,   453,    41,
      -1,    68,    40,   453,    41,    -1,    69,   477,    -1,   112,
     182,    -1,   135,    40,   453,    41,    -1,   132,    40,   453,
      41,    -1,   124,    40,   453,    41,    -1,   118,    40,   453,
      41,    -1,    88,   377,    -1,   480,    -1,   139,    40,   453,
      41,    -1,   136,    40,   453,    41,    -1,   134,    40,   453,
      41,    -1,   130,    40,   453,    41,    -1,   121,    40,   453,
      48,   453,    41,    -1,   131,    40,   453,    48,   453,    41,
      -1,   138,    40,   453,    48,   453,    41,    -1,   109,    40,
     453,    41,    -1,   141,    40,   453,    41,    -1,   133,    40,
     453,    41,    -1,   129,    40,   453,    41,    -1,   126,    40,
     453,    41,    -1,   122,    40,   453,    41,    -1,   117,    40,
     453,    41,    -1,   115,   182,    -1,   107,    40,   453,    41,
      -1,   140,    40,   453,    41,    -1,   137,    40,   453,    41,
      -1,   128,    40,   453,    41,    -1,   119,    40,   453,    41,
      -1,   113,    40,   453,    41,    -1,    70,   377,    -1,    71,
      40,   453,    48,   453,    48,   453,    41,    -1,    72,    40,
     453,    48,   453,    41,    -1,    73,    40,   453,    48,   453,
      41,    -1,    81,    40,   453,    48,   453,    41,    -1,    82,
      40,   453,    41,    -1,    83,    40,   453,    41,    -1,    84,
      40,   453,    41,    -1,    85,    40,   453,    41,    -1,    99,
      40,   453,    41,    -1,   478,    -1,   481,    -1,   482,    -1,
      40,   453,    41,    -1,   182,    -1,    86,    40,   453,    48,
     453,   479,    41,    -1,    -1,   375,    -1,   127,    40,   453,
      48,   453,   479,    41,    -1,    74,   336,    -1,    65,    74,
     336,    -1,    92,    40,   374,   485,    41,    -1,   486,    40,
     374,   453,    41,    -1,    -1,    97,    40,   374,   453,   484,
     488,    41,    -1,    19,    -1,   453,    -1,    93,    -1,    94,
      -1,    95,    -1,    96,    -1,    98,    -1,    49,    75,    55,
     500,    -1,    -1,   487,    -1,   501,   490,    -1,    -1,   372,
      -1,   500,   494,    -1,    87,   501,    -1,   181,    -1,   492,
      -1,    -1,   493,    -1,   496,    -1,   497,    -1,   498,    -1,
     161,    -1,   162,    -1,   163,    -1,   164,    -1,   165,    -1,
     166,    -1,   167,    -1,   168,    -1,   169,    -1,   159,    -1,
     160,    -1,   170,    -1,   172,    -1,   171,    -1,   173,    -1,
     174,    -1,   502,    -1,   176,    -1,   175,    -1,   177,    -1,
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
     144,   145,   147,   150,   151,   154,   158,   162,   165,   166,
     167,   173,   178,   179,   182,   183,   184,   191,   195,   197,
     199,   200,   202,   205,   206,   208,   213,   215,   217,   219,
     221,   223,   225,   227,   229,   231,   234,   236,   238,   239,
     246,   252,   254,   257,   259,   261,   262,   264,   268,   271,
     273,   275,   277,   280,   282,   285,   286,   288,   293,   294,
     296,   297,   299,   300,   302,   303,   305,   309,   311,   314,
     316,   318,   323,   325,   328,   330,   333,   335,   339,   341,
     344,   346,   348,   350,   352,   355,   357,   359,   362,   365,
     366,   368,   369,   371,   374,   377,   378,   385,   386,   389,
     391,   394,   395,   400,   402,   403,   406,   408,   410,   412,
     414,   416,   418,   420,   421,   426,   427,   429,   432,   433,
     435,   437,   439,   441,   443,   445,   447,   449,   451,   453,
     455,   457,   461,   464,   465,   467,   471,   472,   474,   478,
     482,   488,   494,   500,   503,   506,   509,   515,   518,   519,
     521,   522,   524,   527,   529,   530,   533,   536,   539,   542,
     544,   547,   549,   552,   553,   555,   558,   560,   562,   564,
     566,   570,   574,   577,   578,   580,   581,   583,   587,   588,
     591,   592,   593,   594,   603,   606,   609,   610,   612,   614,
     616,   618,   620,   621,   626,   629,   630,   632,   636,   637,
     640,   643,   646,   647,   649,   651,   653,   655,   657,   659,
     661,   663,   665,   667,   670,   671,   675,   676,   677,   678,
     685,   686,   687,   688,   696,   703,   704,   705,   710,   711,
     712,   717,   718,   722,   723,   726,   729,   731,   733,   735,
     738,   740,   741,   748,   749,   751,   754,   755,   758,   760,
     761,   767,   768,   773,   774,   776,   779,   782,   783,   785,
     786,   790,   791,   795,   799,   802,   803,   805,   808,   809,
     812,   814,   815,   817,   820,   823,   824,   827,   829,   831,
     833,   834,   838,   839,   843,   844,   849,   851,   853,   854,
     858,   859,   861,   864,   865,   868,   870,   872,   874,   876,
     879,   882,   883,   886,   889,   892,   893,   896,   899,   900,
     902,   904,   907,   909,   911,   914,   917,   919,   922,   926,
     928,   930,   932,   935,   937,   939,   941,   944,   948,   950,
     953,   954,   957,   960,   961,   963,   965,   969,   971,   973,
     975,   977,   979,   982,   984,   986,   988,   989,   994,   999,
    1001,  1003,  1005,  1007,  1009,  1010,  1012,  1014,  1017,  1019,
    1021,  1023,  1025,  1027,  1029,  1031,  1033,  1035,  1037,  1039,
    1041,  1043,  1045,  1047,  1050,  1053,  1054,  1057,  1060,  1063,
    1064,  1067,  1069,  1072,  1073,  1075,  1078,  1081,  1084,  1087,
    1090,  1093,  1096,  1100,  1102,  1105,  1107,  1109,  1112,  1115,
    1116,  1118,  1121,  1124,  1127,  1128,  1131,  1134,  1135,  1138,
    1141,  1144,  1147,  1149,  1151,  1153,  1155,  1157,  1159,  1161,
    1163,  1165,  1169,  1174,  1179,  1186,  1191,  1196,  1201,  1206,
    1209,  1212,  1217,  1222,  1227,  1232,  1235,  1237,  1242,  1247,
    1252,  1257,  1264,  1271,  1278,  1283,  1288,  1293,  1298,  1303,
    1308,  1313,  1316,  1321,  1326,  1331,  1336,  1341,  1346,  1349,
    1358,  1365,  1372,  1379,  1384,  1389,  1394,  1399,  1404,  1406,
    1408,  1410,  1414,  1416,  1424,  1425,  1427,  1435,  1438,  1442,
    1448,  1454,  1455,  1463,  1465,  1467,  1469,  1471,  1473,  1475,
    1477,  1482,  1483,  1485,  1488,  1489,  1491,  1494,  1497,  1499,
    1501,  1502,  1504,  1506,  1508,  1510,  1512,  1514,  1516,  1518,
    1520,  1522,  1524,  1526,  1528,  1530,  1532,  1534,  1536,  1538,
    1540,  1542,  1544,  1546,  1548,  1550
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
     717,   729,   737,   740,   748,   751,   748,   765,   773,   776,
     783,   786,   791,   798,   801,   806,   813,   816,   819,   822,
     825,   828,   831,   835,   840,   843,   851,   854,   861,   861,
     872,   880,   883,   891,   894,   901,   904,   909,   917,   924,
     925,   929,   935,   941,   948,   955,   957,   962,   969,   972,
     977,   980,   985,   988,   993,   997,  1001,  1008,  1011,  1018,
    1021,  1024,  1027,  1033,  1039,  1042,  1049,  1054,  1061,  1065,
    1073,  1075,  1083,  1086,  1094,  1102,  1103,  1110,  1114,  1122,
    1125,  1130,  1133,  1137,  1143,  1150,  1150,  1158,  1160,  1166,
    1169,  1175,  1175,  1180,  1186,  1188,  1192,  1195,  1198,  1201,
    1204,  1207,  1213,  1217,  1217,  1226,  1228,  1232,  1235,  1237,
    1241,  1242,  1243,  1244,  1245,  1246,  1247,  1248,  1249,  1250,
    1251,  1255,  1262,  1269,  1272,  1276,  1282,  1285,  1291,  1297,
    1303,  1309,  1315,  1321,  1329,  1337,  1345,  1354,  1360,  1363,
    1367,  1370,  1374,  1378,  1384,  1386,  1392,  1399,  1406,  1412,
    1415,  1421,  1424,  1429,  1431,  1435,  1441,  1444,  1447,  1450,
    1457,  1461,  1465,  1468,  1470,  1474,  1476,  1480,  1483,  1485,
    1490,  1495,  1498,  1490,  1509,  1513,  1516,  1518,  1522,  1523,
    1536,  1537,  1542,  1542,  1553,  1557,  1559,  1569,  1573,  1576,
    1592,  1597,  1601,  1604,  1608,  1609,  1610,  1611,  1612,  1613,
    1614,  1615,  1618,  1622,  1628,  1628,  1644,  1648,  1650,  1644,
    1661,  1665,  1667,  1661,  1678,  1689,  1693,  1689,  1703,  1707,
    1703,  1717,  1717,  1729,  1731,  1735,  1745,  1746,  1747,  1751,
    1759,  1763,  1763,  1773,  1776,  1783,  1789,  1791,  1805,  1808,
    1808,  1819,  1819,  1827,  1829,  1834,  1839,  1843,  1845,  1849,
    1849,  1852,  1852,  1859,  1864,  1868,  1870,  1875,  1879,  1881,
    1886,  1890,  1892,  1897,  1902,  1906,  1908,  1912,  1919,  1923,
    1931,  1931,  1934,  1934,  1940,  1940,  1946,  1947,  1951,  1951,
    1956,  1958,  1962,  1965,  1967,  1971,  1975,  1979,  1985,  1989,
    1993,  1996,  1998,  2002,  2006,  2011,  2013,  2019,  2022,  2024,
    2030,  2031,  2037,  2041,  2042,  2046,  2047,  2051,  2052,  2056,
    2057,  2058,  2059,  2063,  2067,  2070,  2073,  2076,  2082,  2086,
    2089,  2091,  2095,  2098,  2100,  2104,  2105,  2109,  2113,  2114,
    2118,  2119,  2120,  2124,  2129,  2130,  2134,  2134,  2147,  2172,
    2175,  2178,  2181,  2184,  2191,  2194,  2199,  2203,  2210,  2211,
    2215,  2218,  2222,  2225,  2231,  2232,  2236,  2239,  2242,  2245,
    2248,  2249,  2255,  2260,  2269,  2276,  2279,  2287,  2296,  2303,
    2306,  2313,  2318,  2329,  2332,  2336,  2339,  2342,  2345,  2348,
    2351,  2354,  2357,  2363,  2368,  2377,  2380,  2387,  2390,  2397,
    2400,  2405,  2408,  2412,  2426,  2429,  2437,  2446,  2449,  2456,
    2459,  2462,  2465,  2469,  2470,  2471,  2472,  2475,  2478,  2481,
    2484,  2488,  2494,  2497,  2500,  2503,  2506,  2509,  2512,  2516,
    2519,  2522,  2525,  2528,  2531,  2534,  2537,  2538,  2541,  2544,
    2547,  2550,  2553,  2556,  2559,  2562,  2565,  2568,  2571,  2574,
    2577,  2580,  2583,  2586,  2589,  2592,  2595,  2598,  2601,  2605,
    2608,  2611,  2614,  2617,  2620,  2623,  2626,  2629,  2632,  2633,
    2634,  2640,  2643,  2650,  2657,  2660,  2664,  2670,  2677,  2684,
    2687,  2691,  2691,  2704,  2708,  2712,  2715,  2718,  2721,  2724,
    2730,  2736,  2739,  2743,  2753,  2756,  2761,  2769,  2776,  2780,
    2788,  2792,  2796,  2797,  2798,  2802,  2803,  2804,  2808,  2809,
    2810,  2814,  2815,  2816,  2820,  2821,  2825,  2826,  2827,  2828,
    2832,  2833,  2837,  2838,  2842,  2843
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
  const int SPARQLfedParser::yylast_ = 2434;
  const int SPARQLfedParser::yynnts_ = 321;
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
#line 5408 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 2849 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
	countStar(false), root(NULL), unnestTree(false)
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


