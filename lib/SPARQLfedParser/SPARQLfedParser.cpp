
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
#line 307 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

#include "../SPARQLfedScanner.hpp"

/* Line 317 of lalr1.cc  */
#line 460 "lib/SPARQLfedParser/SPARQLfedParser.ypp"

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
#line 474 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 477 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.root = (yyval.p_Operation) = (yysemantic_stack_[(1) - (1)].p_Operation);
    }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 488 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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
#line 507 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_BindingClause) = NULL;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 536 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TableOperation) = driver.curOp;
	driver.startBindingSet();
      }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
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

  case 21:

/* Line 678 of lalr1.cc  */
#line 554 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = (yysemantic_stack_[(2) - (1)].p_RSName);
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 560 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RSName) = NULL;
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 601 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 603 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 609 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 647 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
      }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 649 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 655 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVarOrValue((yysemantic_stack_[(2) - (1)].p_TTerm));
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 674 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow(false);
      }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 676 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 696 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 699 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBinding((yysemantic_stack_[(3) - (1)].p_TTerm), (yysemantic_stack_[(3) - (3)].p_TTerm)); 
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 705 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.setBase((yysemantic_stack_[(2) - (2)].p_URI)->getLexicalValue());
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 711 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ignorePrefix(true);
      }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 713 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.ignorePrefix(false);
      }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 715 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  std::string prefix((yysemantic_stack_[(5) - (3)].p_URI)->getLexicalValue());
	  driver.addPrefix(prefix.substr(0, prefix.length()-1), (yysemantic_stack_[(5) - (5)].p_URI));
      }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 723 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(4) - (3)].p_WhereClause);
	(yyval.p_Operation) = new Select((yysemantic_stack_[(4) - (1)].p_Project).distinctness, (yysemantic_stack_[(4) - (1)].p_Project).varSet, (yysemantic_stack_[(4) - (2)].p_DatasetClauses), (yysemantic_stack_[(4) - (3)].p_WhereClause), (yysemantic_stack_[(4) - (4)].p_SolutionModifier));
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 731 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClauses) = new ProductionVector<const DatasetClause*>();
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 734 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_DatasetClauses)->push_back((yysemantic_stack_[(2) - (2)].p_DatasetClause));
	(yyval.p_DatasetClauses) = (yysemantic_stack_[(2) - (1)].p_DatasetClauses);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 742 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 746 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if ((yysemantic_stack_[(5) - (5)].p_BindingClause) != NULL)
	      (yysemantic_stack_[(5) - (3)].p_WhereClause)->m_GroupGraphPattern = driver.makeConjunction((yysemantic_stack_[(5) - (5)].p_BindingClause), (yysemantic_stack_[(5) - (3)].p_WhereClause)->m_GroupGraphPattern);
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new SubSelect(new Select((yysemantic_stack_[(5) - (1)].p_Project).distinctness, (yysemantic_stack_[(5) - (1)].p_Project).varSet, new ProductionVector<const DatasetClause*>(), (yysemantic_stack_[(5) - (3)].p_WhereClause), (yysemantic_stack_[(5) - (4)].p_SolutionModifier))));
      }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 755 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Project).distinctness = (yysemantic_stack_[(3) - (2)].p_distinctness);
	(yyval.p_Project).varSet = (yysemantic_stack_[(3) - (3)].p_VarSet);
    }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 763 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_distinct;
    }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 766 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_reduced;
    }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 773 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 781 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = (yysemantic_stack_[(2) - (2)].p_Variable);
    }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 788 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Variable) = NULL;
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 796 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 803 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 806 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 809 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 812 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 815 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral)));
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 818 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral)));
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 821 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral)));
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 830 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 833 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
    (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
    (yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
}
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 841 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList); // Grammar action needed for implicit upcast.
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 844 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 851 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = NULL;
      }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 853 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.lastWhereClause = (yysemantic_stack_[(6) - (5)].p_WhereClause);
	  /* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	  (yyval.p_Operation) = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(6) - (2)].p_BasicGraphPattern), (yysemantic_stack_[(6) - (4)].p_DatasetClauses), (yysemantic_stack_[(6) - (5)].p_WhereClause), (yysemantic_stack_[(6) - (6)].p_SolutionModifier));
      }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 862 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause) ? (yysemantic_stack_[(5) - (4)].p_WhereClause) : new WhereClause(new DefaultGraphPattern());
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 870 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm))));
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 873 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_TTerm))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 881 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 884 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 891 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 899 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(3) - (3)].p_WhereClause);
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(3) - (2)].p_DatasetClauses), (yysemantic_stack_[(3) - (3)].p_WhereClause));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 907 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 919 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 925 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 931 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 938 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp ? driver.curOp : new DefaultGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 952 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 959 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 967 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 975 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 983 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 991 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 998 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1001 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1008 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1011 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1014 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1017 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1023 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1029 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1032 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1044 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1051 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1055 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1065 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1073 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1076 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1084 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1093 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1100 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1104 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1112 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1120 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1127 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1133 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1140 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1142 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1150 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1156 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1159 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1165 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow(); // @@ push down to _Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star?
      }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1167 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 1170 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1182 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1185 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1188 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1191 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1194 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1197 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 1207 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	OperationSet* ret = driver.root ? dynamic_cast<OperationSet*>(driver.root) : new OperationSet();
	ret->push_back((yysemantic_stack_[(2) - (2)].p_Operation));
	driver.root = ret;
      }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 1211 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Operation) = driver.root;
	}
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 1245 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(3) - (2)].p_URI), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 1252 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 1259 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 1266 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1272 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1275 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1281 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1287 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 1293 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 1299 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 1305 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 1311 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert(driver.curOp, NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 1319 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete(driver.curOp, NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 1327 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete(driver.curOp, NULL);
	driver.curOp = NULL;
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 1335 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(5) - (1)].p_URI))
	    w3c_sw_NEED_IMPL("WITH <URI> (DELETE INSERT?|INSERT) ...");
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(5) - (2)].p_DeleteInsert).del, (yysemantic_stack_[(5) - (2)].p_DeleteInsert).ins, new WhereClause(driver.curOp));
	driver.curOp = NULL;
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 1344 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 1350 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 1357 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 1364 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 1368 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 1376 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("_QUsingClause_E_Star");
    }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 1382 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Delete) = new Delete(driver.curOp, NULL);
	driver.curOp = NULL;
    }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 1389 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = new Insert(driver.curOp, NULL);
	driver.curOp = NULL;
    }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 1396 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 1402 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 1405 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 1411 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 1414 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 1425 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 1431 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 1434 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("DEFAULT");
      }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 1437 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("NAMED");
      }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 1440 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("ALL");
      }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 1480 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 1485 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 1488 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 1491 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 1513 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 251:

/* Line 678 of lalr1.cc  */
#line 1532 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 1534 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 1605 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_BindingClause)) : (yysemantic_stack_[(1) - (1)].p_BindingClause);
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 1612 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Print(driver.curOp);
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 1618 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 1622 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  OptionalGraphPattern* ret = new OptionalGraphPattern(driver.curOp);
	  if (driver.curFilter) {
	      driver.curFilter->copyExpressionsTo(ret);
	      delete driver.curFilter;
	      driver.curFilter = NULL;
	  }
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), ret);
      }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 1634 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 1638 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 1640 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 1643 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 1651 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 1655 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 1657 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(5) - (4)].p_TTerm), driver.curOp, driver.atomFactory, false));
      }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 1664 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Bind(driver.curOp, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
	// no more triples go into the current BGP, per
	//   http://www.w3.org/TR/sparql11-query/#sparqlTranslateGraphPatterns
	// test reference:
	//   http://www.sparql.org/query-validator?query=ASK+{+%3Fs+%3Fp+%3Fo+FILTER+%281%29+BIND+%282+AS+%3Fb%29+%3Fs2+%3Fp2+%3Fo2+FILTER+%283%29+BIND+%284+AS+%3Fd%29}&languageSyntax=SPARQL&outputFormat=algebra&linenumbers=false
	driver.curBGP = NULL;
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 1675 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 1679 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 1681 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.curOp));
      }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 1689 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 1693 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 1695 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 1703 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 1709 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 1724 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    if (driver.curOp == NULL)
		driver.ensureBasicGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 1741 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 1749 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 1753 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 1755 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = NULL;
      }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 1762 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 1765 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 1772 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 1780 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 1794 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 1797 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 1799 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 1807 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 1809 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 1837 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 1840 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 1900 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 1907 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 1911 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 1919 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 1922 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 1928 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 1939 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 1967 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 1994 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 2001 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 2012 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 2019 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 2055 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 2058 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 2061 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 2064 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 2122 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 2126 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 2135 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 407:

/* Line 678 of lalr1.cc  */
#line 2160 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 2163 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 2166 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 2169 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 2172 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 2179 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 2187 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 2191 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 2203 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 2210 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 2213 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 2224 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 2227 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 2230 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 2233 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 2237 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 2248 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 2257 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 2264 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 2267 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 2275 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 2284 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 2291 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 2294 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 2306 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_GeneralComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_GeneralComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_GeneralComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 2317 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 2324 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 2327 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 2330 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 2333 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 2336 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 2339 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 2342 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 2345 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 2356 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 2365 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 2368 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 2375 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 2378 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 2385 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 2393 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 2396 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 2400 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 462:

/* Line 678 of lalr1.cc  */
#line 2414 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 2417 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 2425 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 2434 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 2437 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 2444 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 2447 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 2450 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 2460 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 2463 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 2466 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 2469 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 2476 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 2482 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 2485 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 2488 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 2491 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 2494 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 2497 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 2500 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 2504 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_blank, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 2507 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 2510 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 2513 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ciel, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 2516 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 2519 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 2522 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::XPATH_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 2526 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlen, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 2529 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ucase, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 2532 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lcase, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 2535 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encodeForUri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 2538 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 2541 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strStarts, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 2544 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strEnds, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 2547 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 2550 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 2553 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 2556 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 2559 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 2562 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 2565 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 2568 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 2571 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 2574 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 2577 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha224, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 2580 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 2583 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 2586 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 2589 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 2593 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 2596 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 2599 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 2602 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 2605 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 2608 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 2611 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 2614 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 2617 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 2628 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 2631 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 2638 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_regex, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 2645 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 2652 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 2658 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 2665 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 2672 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 2675 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 2679 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 2681 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  // x = new ArgList($2, driver.curExprList);
	  delete driver.curExprList;
	  driver.curExprList = NULL;
	  w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // $$ = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group-concat, $3, $4.p_Expression, $4.separator));
    }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 2691 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
	driver.countStar = true;
    }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 2699 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 2702 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 2705 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 2708 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 2711 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 2717 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 2723 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 2730 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 2740 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 2748 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 2756 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 2763 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 2767 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 2775 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 3549 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
        28,  -134,    55,  -815,  -815,   394,  -815,  -815,  -815,  -815,
    -815,  -815,    92,    46,    46,    46,   222,    42,    -4,  -815,
      92,    46,    46,    69,    74,    46,    74,   102,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,   252,    49,  -815,  -815,
    -815,   113,  -815,  -815,    50,   118,    50,  -815,  -815,  -815,
    1590,  -815,  -815,  -815,  -815,  -815,   175,  -815,  -815,  -815,
    -815,    23,  -815,    33,    33,   934,  -815,   934,  -815,    33,
    -815,  -815,  -815,  -815,    23,    95,    69,    69,  -815,   148,
    -815,  -815,   145,  -815,   118,  -815,  -815,    92,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,  1727,    76,   139,   143,
     -20,   -18,   150,   164,   174,   -11,   197,   219,   224,   230,
     232,   240,   251,   253,   255,   257,   259,   -18,   261,  -815,
    -815,  -815,  -815,   272,  -815,   277,   281,   283,   -24,   296,
       6,   299,   302,   312,   329,   330,   331,   332,   335,   338,
     339,   343,   344,   346,   348,   355,   356,   357,   358,   359,
     360,   361,   368,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
    1843,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
     371,  -815,  -815,  -815,  -815,  -815,  -815,   -41,    -5,   934,
    -815,  -815,    94,    18,  -815,  -815,  -815,   -11,  -815,  -815,
     135,    92,   207,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
    -815,  -815,   376,  -815,  -815,   373,  -815,  -815,  -815,  -815,
     377,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,   382,
     313,  -815,   334,    79,  -815,  -815,  -815,  -815,    -3,  -815,
    -815,   258,   365,  -815,  -815,  -815,  -815,  -815,  1727,  1959,
    1959,  1959,  -815,   345,  -815,  -815,  -815,  -815,   275,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
      -5,   -11,  1727,  1727,  1727,  -815,  -815,  1727,  -815,  -815,
    1727,  1727,  1727,  -815,  -815,  -815,  -815,  1727,  1727,  1727,
    1727,   109,  1727,  1727,  1727,  1727,  1727,  1727,  -815,   410,
     410,  1727,  1727,  1727,  -815,  1727,  -815,  1727,  1727,  1727,
    1727,  1727,  1727,  1727,  1727,  1727,  1727,  1727,  1727,  1727,
    1727,  1727,  1727,  1727,  1727,  1727,  1727,  1727,  1727,  -815,
     410,    92,  -815,  -815,  -815,  -815,   410,  -815,  -815,   398,
    -815,   395,    23,   334,  -815,    92,  -815,  -815,  -815,  -815,
    -815,  -815,    33,  -815,    33,    70,  -815,   433,   934,  -815,
    -815,    70,  1195,    70,  -815,    33,    -6,   416,  -815,   351,
    -815,   418,  -815,  -815,   -11,    21,  -815,  -815,  -815,   169,
     402,  -815,  -815,  -815,   109,  -815,   404,   393,   396,  1727,
    1727,  1727,  1727,  1727,  1727,   381,   -18,  -815,  -815,   225,
      34,  -815,  -815,  -815,   407,   411,   412,  -815,   403,   408,
     409,    56,   417,   419,   414,   422,   424,   420,   425,   428,
     429,   430,   431,  -815,  1432,  1727,   435,   439,   442,   446,
     447,   448,   449,   444,   452,   455,   457,   451,   459,   460,
     462,   458,   466,   468,   470,   473,   475,   477,   472,   481,
     482,   483,  1727,  -815,  1727,  -815,   934,  -815,  -815,   334,
    -815,  -815,  -815,  -815,  -815,   478,  1195,  -815,  -815,   484,
     453,  -815,  -815,  -815,  -815,  -815,  1094,  -815,  -815,  -815,
    -815,  -815,  -815,  2075,  2333,   501,  -815,  -815,    92,  -815,
    -815,   298,  -815,  2156,  -815,  -815,  2195,  -815,  -815,   434,
    -815,  -815,   384,  -815,  -815,  -815,  -815,  -815,  1727,  -815,
    1727,  -815,  -815,  -815,  -815,  -815,  -815,  -815,   -18,  -815,
    1727,  1727,    34,  -815,  -815,  -815,  1727,  1727,  -815,  -815,
    -815,  -815,  -815,  1727,  1727,  1727,  -815,  -815,   494,  -815,
    -815,  -815,   492,  -815,  -815,  -815,  -815,  1727,  -815,  -815,
    1727,  -815,  -815,  -815,  -815,  1727,  -815,  -815,   496,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,  -815,  1727,  -815,  -815,
    -815,  1727,  -815,  -815,  -815,  1727,  -815,  -815,  -815,  -815,
    -815,  -815,  1727,  -815,  -815,  -815,   497,  -815,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,   934,   175,  -815,  -815,   -21,
    1727,  2075,  -815,  -815,  -815,  -815,  2333,  -815,  -815,  -815,
    -815,  -815,   514,   297,  -815,  -815,  -815,   129,  -815,  -815,
    2217,  -815,  -815,   440,  -815,  -815,  -815,  -815,  -815,  -815,
    2217,  -815,  -815,   406,  -815,     0,  -815,   -14,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,  -815,    20,   503,   511,
     512,   505,  -815,    64,   934,  -815,  -815,    70,    78,   516,
     520,   515,  -815,   513,   523,   515,   524,   525,  -815,  -815,
     518,   521,  -815,  -815,  -815,  -815,  -815,  -815,   345,  -815,
    -815,  1212,   415,   421,  -815,  -815,   541,   544,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,   -65,  -815,  -815,  -815,   179,
    -815,  -815,  -815,  -815,  1727,  -815,  1727,  -815,  -815,   334,
    -815,  -815,  -815,  -815,  2333,   533,   -11,  -815,  -815,   484,
    -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
    -815,  -815,   103,  -815,   107,    99,  -815,  -815,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,    13,  -815,  -815,  -815,  -815,
    -815,  -815,   534,   502,  -815,   538,  -815,   539,  -815,  -815,
      58,    70,  -815,  1195,  -815,   547,  2217,   543,  -815,  -815,
    1212,  -815,   545,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,  2156,  -815,  -815,  2195,
    -815,   546,   102,  -815,  -815,   -11,  -815,  -815,  1727,  -815,
     934,   -11,   548,    86,  -815,    26,  -815,  -815,  -815,  -815,
    -815,  -815,  1195,   486,   529,  -815,   -10,  -815,  -815,  -815,
    -815,  -815,  -815,   531,  -815,  -815,  -815,  -815,  -815,  1195,
    -815,  -815,  2060,  -815,  -815,  -815,  -815,  2123,  -815,  -815,
    -815,  -815,   175,   175,  -815,   -11,   506,  -815,  -815,  -815,
    -815,   555,  -815,  -815,  -815,  -815,  -815,   103,  -815,   103,
    -815,   436,  -815,  -815,    44,    40,  -815,   934,  -815,  -815,
    -815,  -815,   550,   203,  -815,   -11,  -815,   109,   554,  -815,
     499,   553,  -815,  -815,   566,  -815,   -13,  -815,  -815,   568,
    -815,  -815,  2217,  2217,   -11,  -815,   565,  -815,  -815,    86,
    -815,    78,  -815,  -815,  -815,  -815,   570,  -815,  -815,  -815,
    -815,  -815,   -11,  -815,  -815,  -815,  -815,  -815,  -815,  1195,
    -815
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        13,     0,     0,     2,     4,   207,    15,    14,     3,   171,
      67,     1,     0,   195,   195,   195,    79,     0,     0,    72,
       0,   195,   195,     0,     0,   195,     0,    10,     6,    72,
       7,     8,     9,   172,   179,   180,   181,   185,   182,   183,
     184,   186,   187,   188,   189,   208,     0,    17,   578,   581,
     580,   192,   579,   196,     0,     0,     0,    77,    78,    80,
       0,   309,    97,   103,   422,   423,   102,    72,   100,   420,
     421,   114,   206,   222,   222,   232,   204,   232,   203,   222,
     202,   154,     5,    11,   114,   177,     0,     0,   213,   209,
     212,    68,    12,    16,     0,   193,   190,     0,   227,   226,
     228,   225,   194,   198,   197,    96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   543,
     544,   545,   546,     0,   547,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   572,   573,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   574,   576,   575,   577,    92,    93,
      95,    76,    88,    85,    87,   526,   494,   527,   528,    86,
       0,    89,    90,   560,   561,   562,    91,   558,     0,   311,
      72,   101,   104,     0,   115,    73,   106,     0,   223,   220,
       0,     0,     0,   407,   408,   409,   410,   411,   404,   582,
     583,   429,     0,   237,   233,   245,   319,   403,   402,   413,
       0,   317,   418,   419,   425,   426,   427,   424,   428,     0,
       0,   156,   117,    13,   178,   173,   215,   216,     0,   211,
     210,     0,     0,    18,    23,    19,   191,   224,     0,     0,
       0,     0,   477,    82,   430,   433,   437,   439,   441,   451,
     462,   465,   470,   471,   472,   478,   473,   474,   475,   476,
     552,     0,     0,     0,     0,   530,   487,     0,   306,   516,
       0,     0,     0,   251,   248,   535,   247,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   493,   301,
     301,     0,     0,     0,   488,     0,   509,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
     301,     0,   556,   557,   559,   554,   301,   298,   297,     0,
     312,   315,   114,   117,   105,     0,   107,   108,   109,   110,
     112,   113,   222,   221,   222,     0,   229,   231,   232,   246,
     243,   329,   412,     0,   230,   222,     0,     0,    71,   119,
     118,   207,   175,   176,     0,     0,   214,    69,    21,     0,
       0,   468,   469,   467,     0,    83,     0,   431,   435,     0,
       0,     0,     0,     0,     0,     0,     0,   440,   442,   452,
     464,   553,   551,   536,     0,     0,     0,   307,     0,     0,
       0,   254,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   302,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   555,     0,   310,   311,   316,   313,   117,
      99,   111,   199,   201,   337,     0,   412,   336,   238,   234,
       0,   244,   330,   320,   328,   417,   412,   414,   416,   318,
     200,   163,   157,     0,     0,   121,   120,   205,     0,   217,
     218,     0,    56,     0,    31,    45,     0,    20,    24,     0,
      29,    25,     0,    43,    26,   479,    81,    84,     0,   434,
       0,   438,   443,   444,   445,   446,   447,   448,     0,   449,
       0,     0,   457,   463,   453,   454,     0,     0,   466,   485,
     486,   529,   304,     0,     0,     0,   249,    74,     0,   250,
     257,   255,   261,   340,   338,   480,   481,     0,   483,   484,
       0,   521,   522,   523,   524,     0,   541,   542,     0,   539,
     525,   510,   502,   515,   508,   492,   514,     0,   507,   491,
     506,     0,   513,   505,   498,     0,   490,   504,   497,   489,
     496,   512,     0,   495,   511,   503,     0,   299,   314,    98,
     405,   326,   333,   335,   235,   232,     0,   406,   415,     0,
       0,   125,   126,   129,   131,   128,   132,   133,   135,   296,
     294,   295,     0,   123,   122,   219,    70,     0,   169,    35,
      36,    32,    33,     0,   170,   166,   167,   168,   165,    49,
      50,    46,    47,     0,    29,     0,    43,     0,   432,   436,
     450,   459,   460,   458,   461,   455,   456,     0,     0,     0,
       0,   114,   252,   286,   254,   262,   259,   329,     0,     0,
       0,   532,   537,   549,     0,   532,     0,     0,   538,   304,
     321,   331,   236,   240,   155,   160,   162,   164,    82,   127,
     134,     0,     0,     0,   116,   124,   148,   150,    55,    58,
      57,    34,    39,    48,    53,     0,    28,    37,    30,     0,
      42,    51,    44,   308,     0,   305,     0,   518,   519,   117,
     275,   279,   273,   283,     0,     0,     0,   270,   258,   234,
     271,   264,   266,   267,   269,   265,   263,   287,   268,   260,
     353,   341,     0,   383,     0,     0,   339,   342,   344,   345,
     354,   356,   359,   368,   363,   366,   381,   355,   382,   482,
     520,   533,     0,     0,   550,     0,   499,     0,   500,   501,
       0,   323,   327,   412,   334,     0,     0,     0,   141,   142,
     136,   137,     0,   139,   140,   144,   145,   152,   153,   146,
     149,   147,   151,    63,    40,    27,     0,    54,    41,     0,
     303,     0,    10,   276,   280,     0,   284,   293,     0,   272,
     254,     0,     0,   391,   399,     0,   384,   386,   393,   395,
     398,   369,   412,   357,   361,   377,     0,   379,   378,   365,
     367,   370,   531,     0,   540,   534,   300,   324,   325,   412,
     332,   241,     0,   158,   130,   138,   143,     0,    38,    52,
     517,    75,     0,     0,   274,     0,     0,   256,   291,   385,
     392,     0,   388,   397,   400,   396,   351,     0,   360,     0,
     364,     0,   401,   380,     0,     0,   322,   232,   161,   159,
      59,    64,    60,     0,   277,     0,   285,     0,   288,   394,
     390,   343,   358,   362,     0,   374,     0,   375,   548,     0,
      61,    62,     0,     0,     0,   281,     0,   289,   292,     0,
     389,   348,   352,   376,   371,   373,     0,   242,    66,    65,
     278,   282,     0,   387,   346,   349,   350,   372,   290,   412,
     347
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -815,  -815,  -815,  -815,  -815,  -192,   369,  -815,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,   -28,  -815,   112,  -815,
    -174,  -815,  -815,    -7,  -815,  -815,   -22,  -815,   114,  -815,
    -172,  -815,  -815,    -9,  -815,  -815,  -815,  -815,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,   -15,  -815,
    -815,   208,  -815,  -815,  -815,   -58,  -815,   456,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
    -815,   278,   -83,  -815,  -343,  -815,  -815,  -815,  -815,  -815,
    -815,    24,  -815,  -815,    16,  -815,  -815,  -143,  -815,  -815,
    -815,  -815,  -815,  -815,   -59,   -56,   -19,  -815,  -815,  -815,
    -815,  -815,  -815,  -480,  -815,   399,  -815,  -815,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,   323,  -815,  -815,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
    -815,   552,  -815,  -815,   -51,  -815,     4,   587,   271,   619,
     569,  -364,   -82,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
    -815,  -815,  -186,  -815,  -815,  -815,  -815,  -651,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
    -815,  -815,  -815,  -815,  -815,  -624,   -53,   370,  -815,  -263,
    -558,   -31,  -122,  -815,  -815,  -815,   185,  -815,  -815,  -815,
    -190,  -815,  -815,  -261,  -815,  -815,  -815,  -815,  -815,    -8,
    -788,  -815,  -815,  -120,  -114,  -815,  -815,  -815,  -815,  -815,
    -253,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,   -81,
    -815,  -815,  -815,  -207,  -815,  -815,   -80,  -815,  -206,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,  -815,
    -815,  -815,  -780,  -815,  -815,  -814,  -361,  -815,  -815,  -815,
    -815,  -815,  -815,  -341,  -355,   -16,     9,  -815,   873,  -815,
    -815,  -815,   144,  -815,  -815,   151,  -815,  -815,  -815,   146,
    -815,  -815,   136,  -815,  -815,  -815,  -167,  -815,  -171,    47,
    -482,   -57,  -815,  -815,     3,  -815,  -815,  -815,   -42,  -815,
    -815,  -815,  -815,  -815,  -815,  -815,   105,  -815,  -815,  -815,
     188,  -815,   263,   266,   245,  -205,   -12,  -815,  -815
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,    27,    82,     5,     6,    47,    92,
     253,   389,   254,   255,   507,   508,   645,   509,   510,   630,
     631,   708,   796,   632,   795,   511,   647,   512,   513,   640,
     641,   712,   799,   642,   798,   514,   627,   700,   793,   901,
     881,   847,   882,     7,    93,   251,   501,    28,    71,   546,
     661,    29,    59,    60,   395,   396,   178,   179,   180,   181,
      30,   200,    31,    66,    67,   353,    32,   205,   356,   357,
     358,   359,   206,   207,   378,   379,   495,   623,   694,   380,
     611,   612,   496,   616,   617,   624,   780,   781,   782,   783,
     784,   695,   789,   791,   696,   697,    83,   241,   376,   842,
     687,   776,   609,   633,     8,     9,    85,   383,   244,   245,
      33,    34,    95,    96,    35,    54,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,   249,    88,   248,
      89,    90,   386,   499,   210,   211,   101,   102,    76,    78,
     222,   223,   605,   478,   367,   479,   480,   775,   877,   224,
     369,   370,   295,   548,   296,   421,   549,   550,   728,   663,
     551,   665,   666,   729,   730,   731,   805,   732,   803,   852,
     904,   733,   804,   853,   734,   735,   806,   855,   736,   737,
     811,   908,   922,   888,   738,   618,   619,   348,   679,   434,
     715,   657,   289,   542,    62,   199,   349,   350,   467,   468,
     225,   373,   371,   482,   837,   838,   772,   680,   483,   484,
     601,   774,   681,   602,   476,   552,   668,   667,   746,   822,
     747,   925,   929,   926,   912,   891,   741,   748,   749,   750,
     751,   868,   823,   752,   870,   824,   753,   829,   754,   830,
     915,   897,   873,   831,   755,   756,   816,   910,   890,   860,
     861,   817,   818,   864,   819,   874,   226,   227,   365,   228,
     229,   230,   486,   603,   231,   477,   262,   233,   263,   264,
     519,   397,   265,   521,   398,   266,   267,   407,   408,   268,
     269,   532,   538,   654,   533,   409,   270,   410,   271,   272,
     273,   274,   286,   185,   762,   186,   187,   188,   275,   673,
     568,   190,   764,   765,   276,   412,   277,   343,   344,   345,
     278,   193,   194,   195,   279,   197,   280,    52,   238
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SPARQLfedParser::yytable_ninf_ = -413;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        51,   242,    68,   184,   481,   308,    70,   182,    72,   351,
     470,   485,   620,   739,    84,    63,   684,   488,   189,   685,
     284,   361,   287,   212,   914,   293,   643,    69,   240,   710,
     491,   487,   825,   862,   866,   346,   384,   707,   871,   208,
      10,   355,     1,   706,   498,   203,   341,   435,   198,   826,
     201,   876,   202,   536,    70,    11,    97,   894,    53,   103,
     553,   713,   204,   237,    91,   237,   554,   785,   714,   183,
     720,   721,    16,    98,   827,    69,   863,   462,    61,  -174,
     794,   895,   916,   464,   232,   257,   232,   213,   214,   215,
     216,   217,   896,     1,    81,   413,  -412,   537,   256,   836,
     807,  -253,   707,   385,   475,    75,   714,   218,   722,   723,
      77,   724,   489,   761,   828,   485,   203,   761,   742,   354,
     474,   488,    94,   184,    97,   485,   599,   182,   743,   923,
    -114,   488,    81,   204,   620,   711,   814,   209,   189,   742,
     342,   930,   744,   742,   243,   608,   294,   813,   872,   743,
     281,   872,    87,   743,    99,   100,   785,   814,   314,   857,
     643,   686,   285,   744,   288,   191,   698,   744,   198,   699,
      48,    49,    50,    64,    65,    64,    65,   347,   745,   282,
     234,   -22,   234,   283,   725,   352,   815,   237,   316,   183,
     290,   360,    48,    49,    50,    48,    49,    50,   497,   363,
      48,    49,    50,   745,   291,   502,   726,   815,   232,   620,
     174,   175,   176,   177,   292,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
      48,    49,    50,   219,   220,    64,    65,   297,   221,    57,
      58,   682,   620,   362,    48,    49,    50,   -22,   192,    64,
      65,  -114,    48,    49,    50,    86,    87,    64,    65,   298,
      48,    49,    50,   235,   299,   235,    48,    49,    50,   469,
     300,   503,   301,    48,    49,    50,   351,    48,    49,    50,
     302,    48,    49,    50,   529,   191,   530,   531,    64,    65,
     -22,   303,   -22,   304,   -22,   305,   843,   306,   620,   307,
     846,   309,   252,   553,   234,   196,   391,   392,   393,   554,
     426,   472,   310,   473,   504,   364,   505,   311,   506,   643,
     236,   312,   236,   313,   490,   692,   693,   797,   711,   463,
     399,   400,   401,   402,   403,   404,   315,    55,    56,   317,
     405,   406,   318,   360,    73,    74,   902,   903,    79,    48,
      49,    50,   319,    70,    64,    65,   237,   246,   247,    70,
     237,    70,   879,   651,   652,   655,   656,   883,   192,   320,
     321,   322,   323,   500,    69,   324,   802,   232,   325,   326,
      69,   232,    69,   327,   328,   492,   329,   235,   330,   168,
     169,   170,   171,   172,   173,   331,   332,   333,   334,   335,
     336,   337,    12,   516,    13,    14,   650,    15,   338,   237,
      16,   340,   485,   366,    17,    18,   368,   372,   488,   374,
     388,   375,   918,   919,   377,   196,    12,   433,    13,    14,
     232,    15,    19,   387,   394,   465,   615,   621,   466,  -239,
     613,   493,   494,   515,   236,   517,   518,   528,   539,   553,
     520,   543,   540,   541,   237,   554,   544,   545,   555,   606,
     556,   485,   557,   558,   237,   559,   561,   488,   560,   562,
     563,   564,   626,   234,   237,   232,   570,   234,   485,   565,
     571,   198,   198,   572,   488,   232,   625,   573,   574,   575,
     576,   638,   577,   578,   638,   232,   579,    20,   580,   581,
     582,   583,   614,   584,    21,    22,   585,   586,    23,   587,
      24,   588,   634,   899,   589,   634,   590,    25,   591,    26,
     592,    20,   593,   594,   595,   622,   234,   604,    21,    22,
     600,   662,    23,   506,    24,   664,   503,   672,   678,   691,
     809,    25,   702,    26,   204,   522,   523,   524,   525,   526,
     527,   716,   717,   718,   615,   704,   235,   759,   613,   621,
     235,   760,   763,   714,   766,   768,   769,   771,   485,   773,
     693,   234,   692,   808,   488,   832,   787,   833,   719,   834,
     835,   234,   788,   841,   844,   258,   875,   850,   867,   859,
     683,   234,   869,   237,    70,   887,   889,   872,   900,   198,
     907,   909,   911,   913,   198,   917,   921,   927,   635,   235,
     851,   635,   381,   236,   232,    69,   705,   236,   638,   854,
     614,   644,   848,   701,   709,   858,   646,   849,   638,   547,
     777,   703,   690,   471,   621,   689,   339,   845,   792,   634,
     790,   250,   382,   104,   727,    80,   239,   810,   770,   634,
     411,   598,   237,   840,   235,    70,   758,   839,   924,   740,
     892,   812,   648,   893,   235,   821,   236,   621,   653,   886,
     898,   649,   534,   232,   235,   535,    69,   757,   767,   198,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   636,     0,     0,   636,     0,     0,     0,     0,   905,
     786,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     234,   236,   198,     0,     0,     0,     0,     0,   920,     0,
       0,   236,     0,   621,     0,     0,     0,     0,     0,     0,
     758,   236,   820,   758,     0,   635,   928,     0,     0,     0,
       0,     0,     0,     0,     0,   635,     0,     0,   637,     0,
       0,   637,     0,     0,     0,     0,     0,     0,     0,    70,
       0,   237,     0,     0,   638,     0,     0,     0,   198,   234,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      69,     0,   232,     0,   638,   634,     0,   638,     0,   786,
       0,     0,     0,   235,     0,     0,     0,     0,   237,     0,
       0,   820,     0,   865,     0,   634,     0,     0,   634,     0,
     237,     0,     0,     0,     0,     0,     0,     0,   636,   232,
       0,     0,     0,     0,     0,     0,     0,   237,   636,     0,
     638,   232,     0,     0,     0,   638,   884,   885,     0,     0,
      70,    70,     0,     0,     0,     0,     0,     0,   232,     0,
     236,   634,   235,     0,     0,   758,   634,   758,     0,     0,
       0,    69,    69,     0,     0,   237,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   637,     0,     0,   234,     0,
       0,   635,     0,     0,     0,   637,   232,     0,     0,     0,
     638,   638,     0,     0,     0,     0,   906,   820,     0,   758,
       0,   635,     0,     0,   635,     0,     0,     0,     0,   236,
       0,   634,   634,     0,     0,   234,     0,   237,     0,     0,
     757,     0,     0,     0,     0,     0,     0,   234,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   232,     0,
       0,     0,     0,     0,   234,     0,     0,   635,     0,     0,
       0,     0,   635,     0,     0,     0,     0,     0,     0,     0,
       0,   235,     0,     0,   636,   213,   214,   215,   216,   217,
       0,     0,     0,     0,  -412,     0,     0,     0,     0,     0,
       0,     0,   234,     0,   636,   218,     0,   636,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   235,     0,
       0,     0,     0,     0,     0,     0,     0,   635,   635,     0,
     235,     0,     0,     0,     0,     0,     0,     0,   236,     0,
       0,   637,     0,     0,     0,     0,     0,   235,     0,     0,
     636,     0,     0,     0,   234,   636,     0,     0,     0,     0,
       0,   637,     0,     0,   637,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   236,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   235,     0,   236,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,     0,     0,   637,     0,     0,
     636,   636,   637,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,    48,    49,
      50,   219,   220,    64,    65,     0,   221,   235,     0,     0,
       0,     0,   236,     0,     0,   213,   214,   215,   216,   217,
       0,   390,     0,     0,     0,   607,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   218,     0,   637,   637,     0,
       0,     0,     0,     0,     0,   414,   415,   416,     0,     0,
     417,     0,     0,   418,   419,   420,     0,     0,     0,     0,
     422,   423,   424,   425,   236,   427,   428,   429,   430,   431,
     432,     0,     0,     0,   436,   437,   438,     0,   439,     0,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   213,   214,   215,   216,
     217,     0,     0,     0,     0,     0,     0,     0,   778,   779,
       0,     0,     0,     0,     0,     0,   218,     0,     0,     0,
       0,     0,   258,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,    48,    49,
      50,   219,   220,    64,    65,     0,   221,   107,     0,   108,
     109,   110,   111,   112,   113,   114,   115,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,     0,
     127,     0,     0,     0,     0,     0,     0,   567,   569,     0,
       0,   135,     0,     0,     0,     0,     0,     0,     0,   136,
       0,   137,     0,     0,   138,   139,     0,   140,     0,   141,
     142,   143,     0,   144,   145,   596,   146,   597,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,    48,
      49,    50,   219,   220,    64,    65,     0,   221,     0,     0,
       0,     0,     0,     0,     0,     0,    48,    49,    50,     0,
       0,    64,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   658,   659,   660,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     669,     0,     0,   670,     0,     0,     0,     0,   671,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     674,   566,     0,     0,   675,     0,     0,     0,   676,     0,
       0,     0,     0,     0,     0,   677,     0,     0,     0,     0,
       0,     0,   258,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   688,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,     0,   261,   107,     0,   108,
     109,   110,   111,   112,   113,   114,   115,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,     0,
     127,     0,     0,     0,   128,   129,   130,   131,   132,   133,
     134,   135,     0,     0,     0,     0,     0,     0,     0,   136,
       0,   137,     0,     0,   138,   139,     0,   140,     0,   141,
     142,   143,     0,   144,   145,     0,   146,     0,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   800,     0,   801,
       0,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,    48,    49,    50,   105,
       0,    64,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   107,     0,   108,   109,   110,
     111,   112,   113,   114,   115,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     0,   127,     0,
       0,   856,   128,   129,   130,   131,   132,   133,   134,   135,
       0,     0,     0,     0,     0,     0,     0,   136,     0,   137,
       0,     0,   138,   139,     0,   140,     0,   141,   142,   143,
       0,   144,   145,     0,   146,     0,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,    48,    49,    50,   258,     0,    64,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   259,   260,
       0,   261,   107,     0,   108,   109,   110,   111,   112,   113,
     114,   115,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,     0,   127,     0,     0,     0,   128,
     129,   130,   131,   132,   133,   134,   135,     0,     0,     0,
       0,     0,     0,     0,   136,     0,   137,     0,     0,   138,
     139,     0,   140,     0,   141,   142,   143,     0,   144,   145,
       0,   146,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,     0,     0,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,    48,    49,    50,     0,     0,    64,    65,   107,     0,
     108,   109,   110,   111,   112,   113,   114,   115,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
       0,   127,     0,     0,     0,   128,   129,   130,   131,   132,
     133,   134,   135,     0,     0,     0,     0,     0,     0,     0,
     136,     0,   137,     0,     0,   138,   139,     0,   140,     0,
     141,   142,   143,     0,   144,   145,     0,   146,     0,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   258,
       0,     0,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,    48,    49,    50,
       0,     0,    64,    65,   107,     0,   108,   109,   110,   111,
     112,   113,   114,   115,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,     0,   127,     0,     0,
       0,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,     0,     0,     0,     0,     0,   136,     0,   137,     0,
       0,   138,   139,     0,   140,     0,   141,   142,   143,     0,
     144,   145,     0,   146,     0,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   878,   628,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   610,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,    48,    49,    50,     0,     0,    64,    65,
     107,     0,   108,   109,   110,   111,   112,   113,   114,   115,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,     0,   127,   880,   628,     0,     0,     0,     0,
       0,     0,     0,     0,   135,     0,     0,     0,     0,     0,
       0,     0,   136,     0,   137,     0,     0,   138,   139,     0,
     140,     0,   141,   142,   143,     0,   144,   145,   628,   146,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,     0,     0,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,    48,    49,    50,   628,     0,    64,
      65,     0,     0,     0,     0,     0,     0,     0,     0,    48,
      49,    50,     0,     0,    64,    65,     0,     0,   629,   628,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,    48,    49,    50,
       0,     0,    64,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
      48,    49,    50,     0,     0,    64,    65,     0,     0,     0,
       0,     0,     0,     0,   639,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,    48,
      49,    50,     0,   258,    64,    65,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,    48,    49,    50,     0,     0,    64,    65,   107,     0,
     108,   109,   110,   111,   112,   113,   114,   115,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
       0,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   135,     0,     0,     0,     0,     0,     0,     0,
     136,     0,   137,     0,     0,   138,   139,     0,   140,     0,
     141,   142,   143,     0,   144,   145,     0,   146,     0,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    49,    50
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        12,    84,    18,    60,   368,   127,    18,    60,    20,   199,
     353,   372,   494,   664,    29,    19,    37,   372,    60,    40,
      40,   207,    40,    74,    37,    36,   506,    18,    79,    43,
      36,   372,    19,   813,   822,    40,    39,   102,    48,     6,
     174,    23,    14,    43,    23,    22,    87,   310,    60,    36,
      66,   839,    67,    19,    66,     0,     6,   871,    12,    55,
     421,    41,    39,    75,    15,    77,   421,   691,    48,    60,
       6,     7,    16,    23,    61,    66,    50,   340,    36,     0,
     145,    37,   896,   346,    75,    97,    77,    31,    32,    33,
      34,    35,    48,    14,    30,   281,    40,    63,    94,    41,
     724,    37,   102,   106,   365,    36,    48,    51,    44,    45,
      36,    47,   373,   671,   101,   476,    22,   675,    40,   202,
      50,   476,     9,   180,     6,   486,   469,   180,    50,   909,
      36,   486,    30,    39,   616,   149,    50,   104,   180,    40,
     181,   929,    64,    40,    49,   486,   157,    40,   161,    50,
      74,   161,     4,    50,   104,   105,   780,    50,   182,   810,
     640,   182,   182,    64,   182,    60,    37,    64,   180,    40,
     174,   175,   176,   179,   180,   179,   180,   182,   100,    40,
      75,    36,    77,    40,   120,   200,   100,   199,   182,   180,
      40,   203,   174,   175,   176,   174,   175,   176,   384,   211,
     174,   175,   176,   100,    40,    36,   142,   100,   199,   691,
     170,   171,   172,   173,    40,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    40,   182,    17,
      18,   605,   724,   108,   174,   175,   176,   102,    60,   179,
     180,   157,   174,   175,   176,     3,     4,   179,   180,    40,
     174,   175,   176,    75,    40,    77,   174,   175,   176,   352,
      40,   102,    40,   174,   175,   176,   466,   174,   175,   176,
      40,   174,   175,   176,   406,   180,    61,    62,   179,   180,
     145,    40,   147,    40,   149,    40,   776,    40,   780,    40,
     782,    40,   157,   664,   199,    60,   259,   260,   261,   664,
     301,   362,    40,   364,   145,   108,   147,    40,   149,   799,
      75,    40,    77,    40,   375,    28,    29,   148,   149,   341,
      55,    56,    57,    58,    59,    60,    40,    14,    15,    40,
      65,    66,    40,   355,    21,    22,   143,   144,    25,   174,
     175,   176,    40,   365,   179,   180,   368,    86,    87,   371,
     372,   373,   842,   530,   531,   536,   537,   847,   180,    40,
      40,    40,    40,   385,   365,    40,   719,   368,    40,    40,
     371,   372,   373,    40,    40,   376,    40,   199,    40,   164,
     165,   166,   167,   168,   169,    40,    40,    40,    40,    40,
      40,    40,     8,   394,    10,    11,   528,    13,    40,   421,
      16,    40,   773,    37,    20,    21,    43,    40,   773,    37,
      55,   108,   902,   903,    90,   180,     8,    17,    10,    11,
     421,    13,    38,   175,    89,    37,   493,   494,    43,     6,
     493,    25,    91,    41,   199,    41,    53,    66,    41,   810,
      54,    48,    41,    41,   466,   810,    48,    48,    41,     6,
      41,   822,    48,    41,   476,    41,    41,   822,    48,    41,
      41,    41,   174,   368,   486,   466,    41,   372,   839,    48,
      41,   493,   494,    41,   839,   476,   498,    41,    41,    41,
      41,   503,    48,    41,   506,   486,    41,   103,    41,    48,
      41,    41,   493,    41,   110,   111,    48,    41,   114,    41,
     116,    41,   503,   877,    41,   506,    41,   123,    41,   125,
      48,   103,    41,    41,    41,    24,   421,    43,   110,   111,
      52,    37,   114,   149,   116,    43,   102,    41,    41,    25,
     726,   123,   102,   125,    39,   399,   400,   401,   402,   403,
     404,    48,    41,    41,   611,   149,   368,    41,   611,   616,
     372,    41,    49,    48,    41,    41,    41,    49,   929,    48,
      29,   466,    28,    40,   929,    41,   161,    75,   661,    41,
      41,   476,   161,    36,    41,    40,    55,    41,   102,    41,
     606,   486,    63,   605,   606,    89,    41,   161,    48,   611,
      46,   102,    49,    37,   616,    37,    41,    37,   503,   421,
     802,   506,   243,   368,   605,   606,   644,   372,   630,   805,
     611,   509,   796,   630,   646,   811,   512,   799,   640,   421,
     688,   640,   616,   355,   691,   611,   180,   780,   697,   630,
     696,    89,   243,    56,   663,    26,    77,   729,   679,   640,
     280,   466,   664,   773,   466,   667,   668,   771,   911,   667,
     867,   742,   518,   869,   476,   745,   421,   724,   532,   855,
     875,   520,   409,   664,   486,   409,   667,   668,   675,   691,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   503,    -1,    -1,   506,    -1,    -1,    -1,    -1,   885,
     691,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     605,   466,   724,    -1,    -1,    -1,    -1,    -1,   904,    -1,
      -1,   476,    -1,   780,    -1,    -1,    -1,    -1,    -1,    -1,
     742,   486,   744,   745,    -1,   630,   922,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   640,    -1,    -1,   503,    -1,
      -1,   506,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   771,
      -1,   773,    -1,    -1,   776,    -1,    -1,    -1,   780,   664,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     771,    -1,   773,    -1,   796,   776,    -1,   799,    -1,   780,
      -1,    -1,    -1,   605,    -1,    -1,    -1,    -1,   810,    -1,
      -1,   813,    -1,   815,    -1,   796,    -1,    -1,   799,    -1,
     822,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   630,   810,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   839,   640,    -1,
     842,   822,    -1,    -1,    -1,   847,   852,   853,    -1,    -1,
     852,   853,    -1,    -1,    -1,    -1,    -1,    -1,   839,    -1,
     605,   842,   664,    -1,    -1,   867,   847,   869,    -1,    -1,
      -1,   852,   853,    -1,    -1,   877,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   630,    -1,    -1,   773,    -1,
      -1,   776,    -1,    -1,    -1,   640,   877,    -1,    -1,    -1,
     902,   903,    -1,    -1,    -1,    -1,   887,   909,    -1,   911,
      -1,   796,    -1,    -1,   799,    -1,    -1,    -1,    -1,   664,
      -1,   902,   903,    -1,    -1,   810,    -1,   929,    -1,    -1,
     911,    -1,    -1,    -1,    -1,    -1,    -1,   822,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   929,    -1,
      -1,    -1,    -1,    -1,   839,    -1,    -1,   842,    -1,    -1,
      -1,    -1,   847,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   773,    -1,    -1,   776,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   877,    -1,   796,    51,    -1,   799,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   810,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   902,   903,    -1,
     822,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   773,    -1,
      -1,   776,    -1,    -1,    -1,    -1,    -1,   839,    -1,    -1,
     842,    -1,    -1,    -1,   929,   847,    -1,    -1,    -1,    -1,
      -1,   796,    -1,    -1,   799,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   810,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   877,    -1,   822,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   839,    -1,    -1,   842,    -1,    -1,
     902,   903,   847,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,    -1,   182,   929,    -1,    -1,
      -1,    -1,   877,    -1,    -1,    31,    32,    33,    34,    35,
      -1,   258,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,   902,   903,    -1,
      -1,    -1,    -1,    -1,    -1,   282,   283,   284,    -1,    -1,
     287,    -1,    -1,   290,   291,   292,    -1,    -1,    -1,    -1,
     297,   298,   299,   300,   929,   302,   303,   304,   305,   306,
     307,    -1,    -1,    -1,   311,   312,   313,    -1,   315,    -1,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    40,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,    -1,   182,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    -1,    -1,    -1,    -1,    -1,    -1,   434,   435,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
      -1,   109,    -1,    -1,   112,   113,    -1,   115,    -1,   117,
     118,   119,    -1,   121,   122,   462,   124,   464,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,   182,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   174,   175,   176,    -1,
      -1,   179,   180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   543,   544,   545,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     557,    -1,    -1,   560,    -1,    -1,    -1,    -1,   565,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     577,    19,    -1,    -1,   581,    -1,    -1,    -1,   585,    -1,
      -1,    -1,    -1,    -1,    -1,   592,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   610,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    -1,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
      -1,   109,    -1,    -1,   112,   113,    -1,   115,    -1,   117,
     118,   119,    -1,   121,   122,    -1,   124,    -1,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   714,    -1,   716,
      -1,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    19,
      -1,   179,   180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    -1,    88,    -1,
      -1,   808,    92,    93,    94,    95,    96,    97,    98,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,   109,
      -1,    -1,   112,   113,    -1,   115,    -1,   117,   118,   119,
      -1,   121,   122,    -1,   124,    -1,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    40,    -1,   179,
     180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      85,    86,    -1,    88,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   107,    -1,   109,    -1,    -1,   112,   113,    -1,
     115,    -1,   117,   118,   119,    -1,   121,   122,    42,   124,
      -1,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,    -1,    -1,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    42,    -1,   179,
     180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,
     175,   176,    -1,    -1,   179,   180,    -1,    -1,   102,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
      -1,    -1,   179,   180,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,   179,   180,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,    -1,    40,   179,   180,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,    -1,    -1,   179,   180,    65,    -1,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,   109,    -1,    -1,   112,   113,    -1,   115,    -1,
     117,   118,   119,    -1,   121,   122,    -1,   124,    -1,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,   175,   176
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    14,   184,   185,   186,   189,   190,   226,   287,   288,
     174,     0,     8,    10,    11,    13,    16,    20,    21,    38,
     103,   110,   111,   114,   116,   123,   125,   187,   230,   234,
     243,   245,   249,   293,   294,   297,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   191,   174,   175,
     176,   499,   500,    12,   298,   298,   298,    17,    18,   235,
     236,    36,   377,    19,   179,   180,   246,   247,   448,   449,
     499,   231,   499,   298,   298,    36,   321,    36,   322,   298,
     322,    30,   188,   279,   231,   289,     3,     4,   311,   313,
     314,    15,   192,   227,     9,   295,   296,     6,    23,   104,
     105,   319,   320,   319,   320,    19,    40,    65,    67,    68,
      69,    70,    71,    72,    73,    74,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    88,    92,    93,
      94,    95,    96,    97,    98,    99,   107,   109,   112,   113,
     115,   117,   118,   119,   121,   122,   124,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   239,   240,
     241,   242,   369,   449,   474,   476,   478,   479,   480,   481,
     484,   489,   493,   494,   495,   496,   497,   498,   499,   378,
     244,   448,   231,    22,    39,   250,   255,   256,     6,   104,
     317,   318,   317,    31,    32,    33,    34,    35,    51,   177,
     178,   182,   323,   324,   332,   383,   439,   440,   442,   443,
     444,   447,   449,   450,   489,   493,   497,   499,   501,   323,
     317,   280,   255,    49,   291,   292,   321,   321,   312,   310,
     314,   228,   157,   193,   195,   196,   319,   499,    40,    61,
      62,    64,   449,   451,   452,   455,   458,   459,   462,   463,
     469,   471,   472,   473,   474,   481,   487,   489,   493,   497,
     499,    74,    40,    40,    40,   182,   475,    40,   182,   375,
      40,    40,    40,    36,   157,   335,   337,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,   375,    40,
      40,    40,    40,    40,   182,    40,   182,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,   240,
      40,    87,   181,   490,   491,   492,    40,   182,   370,   379,
     380,   383,   231,   248,   255,    23,   251,   252,   253,   254,
     499,   335,   108,   499,   108,   441,    37,   327,    43,   333,
     334,   385,    40,   384,    37,   108,   281,    90,   257,   258,
     262,   189,   288,   290,    39,   106,   315,   175,    55,   194,
     451,   472,   472,   472,    89,   237,   238,   454,   457,    55,
      56,    57,    58,    59,    60,    65,    66,   460,   461,   468,
     470,   370,   488,   335,   451,   451,   451,   451,   451,   451,
     451,   338,   451,   451,   451,   451,   449,   451,   451,   451,
     451,   451,   451,    17,   372,   372,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   372,   499,   372,    37,    43,   381,   382,   255,
     257,   254,   317,   317,    50,   386,   397,   448,   326,   328,
     329,   324,   386,   391,   392,   439,   445,   446,   447,   386,
     317,    36,   449,    25,    91,   259,   265,   335,    23,   316,
     499,   229,    36,   102,   145,   147,   149,   197,   198,   200,
     201,   208,   210,   211,   218,    41,   449,    41,    53,   453,
      54,   456,   462,   462,   462,   462,   462,   462,    66,   375,
      61,    62,   464,   467,   495,   496,    19,    63,   465,    41,
      41,    41,   376,    48,    48,    48,   232,   234,   336,   339,
     340,   343,   398,   439,   447,    41,    41,    48,    41,    41,
      48,    41,    41,    41,    41,    48,    19,   451,   483,   451,
      41,    41,    41,    41,    41,    41,    41,    48,    41,    41,
      41,    48,    41,    41,    41,    48,    41,    41,    41,    41,
      41,    41,    48,    41,    41,    41,   451,   451,   379,   257,
      52,   393,   396,   446,    43,   325,     6,    41,   446,   285,
      40,   263,   264,   369,   449,   474,   266,   267,   368,   369,
     473,   474,    24,   260,   268,   499,   174,   219,    42,   102,
     202,   203,   206,   286,   449,   489,   493,   497,   499,   149,
     212,   213,   216,   286,   201,   199,   211,   209,   455,   458,
     375,   469,   469,   465,   466,   471,   471,   374,   451,   451,
     451,   233,    37,   342,    43,   344,   345,   400,   399,   451,
     451,   451,    41,   482,   451,   451,   451,   451,    41,   371,
     390,   395,   324,   448,    37,    40,   182,   283,   451,   264,
     267,    25,    28,    29,   261,   274,   277,   278,    37,    40,
     220,   206,   102,   216,   149,   199,    43,   102,   204,   209,
      43,   149,   214,    41,    48,   373,    48,    41,    41,   255,
       6,     7,    44,    45,    47,   120,   142,   279,   341,   346,
     347,   348,   350,   354,   357,   358,   361,   362,   367,   340,
     392,   409,    40,    50,    64,   100,   401,   403,   410,   411,
     412,   413,   416,   419,   421,   427,   428,   449,   499,    41,
      41,   373,   477,    49,   485,   486,    41,   477,    41,    41,
     374,    49,   389,    48,   394,   330,   284,   238,    26,    27,
     269,   270,   271,   272,   273,   368,   449,   161,   161,   275,
     278,   276,   277,   221,   145,   207,   205,   148,   217,   215,
     451,   451,   257,   351,   355,   349,   359,   368,    40,   335,
     325,   363,   412,    40,    50,   100,   429,   434,   435,   437,
     499,   419,   402,   415,   418,    19,    36,    61,   101,   420,
     422,   426,    41,    75,    41,    41,    41,   387,   388,   397,
     396,    36,   282,   286,    41,   270,   473,   224,   203,   213,
      41,   188,   352,   356,   335,   360,   451,   340,   335,    41,
     432,   433,   435,    50,   436,   499,   393,   102,   414,    63,
     417,    48,   161,   425,   438,    55,   393,   331,    41,   286,
      41,   223,   225,   286,   448,   448,   335,    89,   366,    41,
     431,   408,   416,   421,   438,    37,    48,   424,   498,   324,
      48,   222,   143,   144,   353,   335,   449,    46,   364,   102,
     430,    49,   407,    37,    37,   423,   438,    37,   286,   286,
     335,    41,   365,   435,   403,   404,   406,    37,   335,   405,
     393
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
     227,   230,   231,   231,   233,   232,   234,   235,   235,   236,
     236,   237,   238,   238,   239,   240,   240,   240,   240,   240,
     240,   240,   240,   241,   241,   242,   242,   244,   243,   245,
     246,   246,   247,   247,   248,   248,   249,   250,   251,   251,
     252,   253,   254,   255,   256,   256,   257,   258,   258,   259,
     259,   260,   260,   261,   261,   262,   263,   263,   264,   264,
     264,   264,   265,   266,   266,   267,   268,   269,   269,   270,
     270,   271,   271,   272,   273,   273,   274,   274,   275,   275,
     276,   276,   277,   278,   280,   279,   281,   281,   282,   282,
     284,   283,   283,   285,   285,   286,   286,   286,   286,   286,
     286,   287,   289,   288,   290,   290,   291,   292,   292,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     294,   295,   296,   296,   297,   298,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   309,   310,
     310,   311,   311,   312,   312,   313,   314,   315,   316,   316,
     317,   317,   318,   318,   319,   320,   320,   320,   320,   321,
     322,   323,   324,   324,   325,   325,   326,   327,   327,   329,
     330,   331,   328,   332,   333,   334,   334,   335,   335,   336,
     336,   338,   337,   339,   340,   340,   341,   342,   342,   343,
     344,   345,   345,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   347,   349,   348,   351,   352,   353,   350,   355,
     356,   354,   357,   359,   360,   358,   362,   363,   361,   365,
     364,   366,   366,   367,   368,   368,   368,   369,   370,   371,
     370,   372,   372,   373,   374,   374,   375,   376,   375,   378,
     377,   379,   379,   380,   381,   382,   382,   384,   383,   385,
     383,   386,   387,   388,   388,   389,   390,   390,   391,   392,
     392,   393,   394,   395,   395,   396,   397,   397,   399,   398,
     400,   398,   402,   401,   403,   403,   405,   404,   406,   406,
     407,   408,   408,   409,   410,   411,   412,   413,   414,   415,
     415,   416,   417,   418,   418,   419,   420,   420,   421,   421,
     422,   423,   423,   424,   424,   425,   425,   426,   426,   426,
     426,   427,   428,   428,   428,   428,   429,   430,   431,   431,
     432,   433,   433,   434,   434,   435,   436,   436,   437,   437,
     437,   438,   439,   439,   441,   440,   442,   443,   443,   443,
     443,   443,   444,   444,   445,   445,   446,   446,   447,   447,
     448,   448,   449,   449,   450,   450,   450,   450,   450,   450,
     451,   452,   453,   454,   454,   455,   456,   457,   457,   458,
     459,   460,   460,   461,   461,   461,   461,   461,   461,   461,
     461,   462,   463,   464,   464,   465,   465,   466,   466,   467,
     467,   467,   468,   468,   469,   470,   470,   471,   471,   471,
     471,   472,   472,   472,   472,   472,   472,   472,   472,   473,
     474,   474,   474,   474,   474,   474,   474,   474,   474,   474,
     474,   474,   474,   474,   474,   474,   474,   474,   474,   474,
     474,   474,   474,   474,   474,   474,   474,   474,   474,   474,
     474,   474,   474,   474,   474,   474,   474,   474,   474,   474,
     474,   474,   474,   474,   474,   474,   474,   474,   474,   475,
     475,   476,   477,   477,   478,   479,   480,   481,   481,   482,
     481,   483,   483,   484,   484,   484,   484,   484,   485,   486,
     486,   487,   488,   488,   489,   490,   491,   491,   492,   492,
     493,   493,   493,   494,   494,   494,   495,   495,   495,   496,
     496,   496,   497,   497,   498,   498,   498,   498,   499,   499,
     500,   500,   501,   501
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
       5,     4,     0,     2,     0,     5,     3,     1,     1,     0,
       1,     2,     0,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     0,     6,     5,
       1,     2,     1,     1,     0,     1,     3,     2,     1,     1,
       1,     2,     1,     2,     0,     1,     4,     0,     1,     0,
       1,     0,     1,     0,     1,     3,     1,     2,     1,     1,
       4,     1,     2,     1,     2,     1,     3,     1,     2,     1,
       1,     1,     1,     2,     1,     1,     2,     2,     0,     1,
       0,     1,     2,     2,     0,     6,     0,     2,     1,     2,
       0,     4,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     0,     1,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     0,     1,     3,     0,     1,     3,     3,     5,
       5,     5,     2,     2,     2,     5,     2,     0,     1,     0,
       1,     2,     1,     0,     2,     2,     2,     2,     1,     2,
       1,     2,     0,     1,     2,     1,     1,     1,     1,     3,
       3,     2,     0,     1,     0,     1,     3,     0,     2,     0,
       0,     0,     8,     2,     2,     0,     1,     1,     1,     1,
       1,     0,     4,     2,     0,     1,     3,     0,     2,     2,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     0,     3,     0,     0,     0,     6,     0,
       0,     5,     6,     0,     0,     4,     0,     0,     4,     0,
       3,     0,     2,     2,     1,     1,     1,     2,     1,     0,
       6,     0,     1,     2,     0,     2,     1,     0,     5,     0,
       4,     0,     1,     2,     2,     0,     1,     0,     3,     0,
       3,     3,     2,     0,     1,     2,     0,     2,     1,     0,
       1,     2,     2,     0,     2,     1,     1,     1,     0,     3,
       0,     3,     0,     4,     1,     1,     0,     3,     0,     1,
       2,     0,     2,     1,     1,     1,     1,     2,     2,     0,
       2,     2,     2,     0,     2,     2,     0,     1,     1,     2,
       1,     1,     2,     2,     1,     2,     3,     1,     1,     1,
       2,     1,     1,     1,     2,     3,     1,     2,     0,     2,
       2,     0,     1,     1,     3,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     0,     4,     4,     1,     1,     1,
       1,     1,     0,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     0,     2,     2,     2,     0,     2,     1,
       2,     0,     1,     2,     2,     2,     2,     2,     2,     2,
       3,     1,     2,     1,     1,     2,     2,     0,     1,     2,
       2,     2,     0,     2,     2,     0,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     4,     6,     4,     4,     4,     4,     2,     2,     4,
       4,     4,     4,     2,     1,     4,     4,     4,     4,     6,
       6,     6,     4,     4,     4,     4,     4,     4,     4,     2,
       4,     4,     4,     4,     4,     4,     2,     8,     6,     6,
       6,     4,     4,     4,     4,     4,     1,     1,     1,     3,
       1,     7,     0,     1,     7,     2,     3,     5,     5,     0,
       7,     1,     1,     1,     1,     1,     1,     1,     4,     0,
       1,     2,     0,     1,     2,     2,     1,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
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
  "SubSelect", "@7", "SelectClause",
  "_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C",
  "_Q_O_QIT_DISTINCT_E_Or_QIT_REDUCED_E_C_E_Opt", "_O_QIT_AS_E_S_QVar_E_C",
  "_Q_O_QIT_AS_E_S_QVar_E_C_E_Opt",
  "_O_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C",
  "_Q_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_C_E_Plus",
  "_O_QVar_E_Or_QAggregate_E_Or_QBuiltInCall_E_Or_QFunctionCall_E_Or_QRDFLiteral_E_Or_QNumericLiteral_E_Or_QBooleanLiteral_E_Or_QGT_LPAREN_E_S_QExpression_E_S_QIT_AS_E_S_QVar_E_Opt_S_QGT_RPAREN_E_Plus_Or_QGT_TIMES_E_C",
  "ConstructQuery", "$@8", "DescribeQuery", "_QVarOrIRIref_E_Plus",
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
  "OffsetClause", "BindingsClause", "$@9", "_QVar_E_Star",
  "_QBindingValue_E_Plus",
  "_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C",
  "$@10",
  "_Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star",
  "BindingValue", "UpdateUnit", "Update", "$@11", "_QUpdate_E_Opt",
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
  "QuadsNotTriples", "@12", "@13", "$@14", "TriplesTemplate",
  "_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C_E_Opt", "GroupGraphPattern",
  "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C",
  "_O_QGT_LCURLEY_E_S_QSubSelect_E_Or_QGroupGraphPatternSub_E_S_QGT_RCURLEY_E_C",
  "$@15", "GroupGraphPatternSub", "_QTriplesBlock_E_Opt",
  "_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "Print", "OptionalGraphPattern", "@16", "GraphGraphPattern", "@17",
  "@18", "@19", "ServiceGraphPattern", "@20", "@21", "Bind",
  "MinusGraphPattern", "@22", "@23", "GroupOrUnionGraphPattern", "@24",
  "@25", "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@26",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "$@27", "_QIT_DISTINCT_E_Opt",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ExpressionList", "$@28",
  "ConstructTemplate", "$@29", "_QConstructTriples_E_Opt",
  "ConstructTriples", "_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C_E_Opt", "TriplesSameSubject",
  "$@30", "$@31", "PropertyListNotEmpty", "_O_QVerb_E_S_QObjectList_E_C",
  "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "Verb", "TriplesSameSubjectPath", "$@32", "$@33",
  "PropertyListNotEmptyPath", "$@34", "_O_QVerbPath_E_Or_QVerbSimple_E_C",
  "_O_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_C", "$@35",
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
  "Integer", "TriplesNode", "BlankNodePropertyList", "@36", "Generator",
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
  "SubstringExpression", "ExistsFunc", "NotExistsFunc", "Aggregate",
  "$@37", "_O_QGT_TIMES_E_Or_QExpression_E_C",
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
       184,     0,    -1,   185,    -1,   287,    -1,   186,    -1,   189,
     187,   188,    -1,   230,    -1,   243,    -1,   245,    -1,   249,
      -1,    -1,   279,    -1,   190,   191,   192,    -1,    -1,   226,
      -1,    -1,   191,   227,    -1,    -1,   192,   193,    -1,    -1,
     196,   194,   197,    -1,   157,    55,    -1,    -1,   195,    -1,
     198,    -1,   208,    -1,   218,    -1,   200,   201,   199,   207,
      -1,   201,   199,    43,    -1,    -1,   199,   204,    -1,   145,
      -1,   102,   203,    -1,   206,    -1,   202,   206,    -1,   102,
      -1,   202,    -1,    -1,   102,   205,   203,    -1,   286,   102,
      -1,   145,    -1,   210,   211,   209,   217,    -1,   211,   209,
      43,    -1,    -1,   209,   214,    -1,   147,    -1,   149,   213,
      -1,   216,    -1,   212,   216,    -1,   149,    -1,   212,    -1,
      -1,   149,   215,   213,    -1,   286,   149,    -1,   148,    -1,
      36,   219,    37,    -1,    -1,   219,   220,    -1,    -1,    40,
     221,   224,    41,    -1,    -1,    48,    -1,   225,   222,    -1,
      -1,   224,   223,    -1,   286,   144,   286,    -1,   286,   143,
     286,    -1,    14,   174,    -1,    -1,    -1,    15,   228,   175,
     229,   174,    -1,   234,   231,   255,   257,    -1,    -1,   231,
     250,    -1,    -1,   234,   233,   255,   257,   188,    -1,    16,
     236,   242,    -1,    17,    -1,    18,    -1,    -1,   235,    -1,
      89,   449,    -1,    -1,   237,    -1,    40,   451,   238,    41,
      -1,   449,    -1,   481,    -1,   474,    -1,   369,    -1,   489,
      -1,   493,    -1,   497,    -1,   239,    -1,   240,    -1,   241,
     240,    -1,   241,    -1,    19,    -1,    -1,    20,   377,   244,
     231,   255,   257,    -1,    21,   247,   231,   248,   257,    -1,
     448,    -1,   246,   448,    -1,   246,    -1,    19,    -1,    -1,
     255,    -1,    38,   231,   255,    -1,    22,   251,    -1,   252,
      -1,   253,    -1,   254,    -1,    23,   254,    -1,   499,    -1,
     256,   335,    -1,    -1,    39,    -1,   258,   259,   260,   261,
      -1,    -1,   262,    -1,    -1,   265,    -1,    -1,   268,    -1,
      -1,   274,    -1,    90,    25,   263,    -1,   264,    -1,   263,
     264,    -1,   474,    -1,   369,    -1,    40,   451,   238,    41,
      -1,   449,    -1,    91,   266,    -1,   267,    -1,   266,   267,
      -1,   368,    -1,    24,    25,   269,    -1,   270,    -1,   269,
     270,    -1,   272,    -1,   273,    -1,    26,    -1,    27,    -1,
     271,   473,    -1,   368,    -1,   449,    -1,   277,   275,    -1,
     278,   276,    -1,    -1,   278,    -1,    -1,   277,    -1,    28,
     161,    -1,    29,   161,    -1,    -1,    30,   280,   281,    36,
     285,    37,    -1,    -1,   281,   449,    -1,   286,    -1,   282,
     286,    -1,    -1,    40,   284,   282,    41,    -1,   182,    -1,
      -1,   285,   283,    -1,   499,    -1,   489,    -1,   493,    -1,
     497,    -1,    42,    -1,   449,    -1,   288,    -1,    -1,   189,
     293,   289,   292,    -1,    -1,   288,    -1,    49,   290,    -1,
      -1,   291,    -1,   294,    -1,   297,    -1,   299,    -1,   301,
      -1,   302,    -1,   303,    -1,   300,    -1,   304,    -1,   305,
      -1,   306,    -1,   307,    -1,     8,   499,   296,    -1,     9,
     319,    -1,    -1,   295,    -1,    10,   298,   320,    -1,    -1,
      12,    -1,    13,   298,   320,    -1,    11,   298,   319,    -1,
     110,   298,   317,   108,   317,    -1,   123,   298,   317,   108,
     317,    -1,   111,   298,   317,   108,   317,    -1,   125,   322,
      -1,   116,   322,    -1,   114,   321,    -1,   309,   311,   312,
      39,   335,    -1,   103,   499,    -1,    -1,   308,    -1,    -1,
     314,    -1,   313,   310,    -1,   314,    -1,    -1,   312,   315,
      -1,     3,   321,    -1,     4,   321,    -1,   106,   316,    -1,
     499,    -1,    23,   499,    -1,   104,    -1,   318,   499,    -1,
      -1,     6,    -1,     6,   499,    -1,   319,    -1,   104,    -1,
      23,    -1,   105,    -1,    36,   323,    37,    -1,    36,   323,
      37,    -1,   324,   327,    -1,    -1,   332,    -1,    -1,    43,
      -1,   328,   325,   324,    -1,    -1,   327,   326,    -1,    -1,
      -1,    -1,   329,     6,   448,   330,    36,   331,   324,    37,
      -1,   383,   334,    -1,    43,   324,    -1,    -1,   333,    -1,
     337,    -1,   157,    -1,   232,    -1,   339,    -1,    -1,    36,
     338,   336,    37,    -1,   340,   342,    -1,    -1,   343,    -1,
     346,   325,   340,    -1,    -1,   342,   341,    -1,   398,   345,
      -1,    43,   340,    -1,    -1,   344,    -1,   361,    -1,   348,
      -1,   358,    -1,   350,    -1,   354,    -1,   367,    -1,   357,
      -1,   279,    -1,   347,    -1,   142,   335,    -1,    -1,    44,
     349,   335,    -1,    -1,    -1,    -1,     6,   351,   352,   448,
     353,   335,    -1,    -1,    -1,     7,   355,   356,   448,   335,
      -1,   120,    40,   451,    89,   449,    41,    -1,    -1,    -1,
      45,   359,   360,   335,    -1,    -1,    -1,   362,   363,   335,
     366,    -1,    -1,    46,   365,   335,    -1,    -1,   366,   364,
      -1,    47,   368,    -1,   473,    -1,   474,    -1,   369,    -1,
     499,   370,    -1,   182,    -1,    -1,    40,   372,   451,   371,
     374,    41,    -1,    -1,    17,    -1,    48,   451,    -1,    -1,
     374,   373,    -1,   182,    -1,    -1,    40,   451,   376,   374,
      41,    -1,    -1,    36,   378,   379,    37,    -1,    -1,   380,
      -1,   383,   382,    -1,    43,   379,    -1,    -1,   381,    -1,
      -1,   447,   384,   386,    -1,    -1,   439,   385,   391,    -1,
     397,   393,   390,    -1,   397,   393,    -1,    -1,   387,    -1,
      49,   388,    -1,    -1,   390,   389,    -1,   392,    -1,    -1,
     386,    -1,   396,   395,    -1,    48,   396,    -1,    -1,   395,
     394,    -1,   446,    -1,   448,    -1,    50,    -1,    -1,   447,
     399,   401,    -1,    -1,   439,   400,   409,    -1,    -1,   403,
     402,   393,   408,    -1,   410,    -1,   411,    -1,    -1,   403,
     405,   393,    -1,    -1,   404,    -1,    49,   406,    -1,    -1,
     408,   407,    -1,   392,    -1,   412,    -1,   449,    -1,   413,
      -1,   416,   415,    -1,   102,   416,    -1,    -1,   415,   414,
      -1,   421,   418,    -1,    63,   421,    -1,    -1,   418,   417,
      -1,   427,   420,    -1,    -1,   422,    -1,   419,    -1,   100,
     419,    -1,   426,    -1,    37,    -1,   438,    37,    -1,    48,
     423,    -1,    37,    -1,   438,   424,    -1,    48,   438,    37,
      -1,    19,    -1,   101,    -1,    61,    -1,    36,   425,    -1,
     428,    -1,   499,    -1,    50,    -1,    64,   429,    -1,    40,
     412,    41,    -1,   434,    -1,   102,   435,    -1,    -1,   431,
     430,    -1,   435,   431,    -1,    -1,   432,    -1,   435,    -1,
      40,   433,    41,    -1,   437,    -1,   499,    -1,    50,    -1,
     499,    -1,    50,    -1,   100,   436,    -1,   161,    -1,   442,
      -1,   440,    -1,    -1,    51,   441,   386,    52,    -1,   444,
      40,   445,    41,    -1,    31,    -1,    32,    -1,    33,    -1,
      34,    -1,    35,    -1,    -1,   443,    -1,   446,    -1,   445,
     446,    -1,   447,    -1,   439,    -1,   449,    -1,   450,    -1,
     449,    -1,   499,    -1,   179,    -1,   180,    -1,   499,    -1,
     489,    -1,   493,    -1,   497,    -1,   501,    -1,   182,    -1,
     452,    -1,   455,   454,    -1,    53,   455,    -1,    -1,   454,
     453,    -1,   458,   457,    -1,    54,   458,    -1,    -1,   457,
     456,    -1,   459,    -1,   462,   460,    -1,    -1,   461,    -1,
      55,   462,    -1,    56,   462,    -1,    57,   462,    -1,    58,
     462,    -1,    59,   462,    -1,    60,   462,    -1,    66,   375,
      -1,    65,    66,   375,    -1,   463,    -1,   469,   468,    -1,
     495,    -1,   496,    -1,    19,   471,    -1,    63,   471,    -1,
      -1,   465,    -1,    61,   469,    -1,    62,   469,    -1,   464,
     466,    -1,    -1,   468,   467,    -1,   471,   470,    -1,    -1,
     470,   465,    -1,    64,   472,    -1,    61,   472,    -1,    62,
     472,    -1,   472,    -1,   473,    -1,   474,    -1,   487,    -1,
     489,    -1,   493,    -1,   497,    -1,   449,    -1,   481,    -1,
      40,   451,    41,    -1,    76,    40,   451,    41,    -1,    77,
      40,   451,    41,    -1,    78,    40,   451,    48,   451,    41,
      -1,    79,    40,   451,    41,    -1,    80,    40,   449,    41,
      -1,    67,    40,   451,    41,    -1,    68,    40,   451,    41,
      -1,    69,   475,    -1,   112,   182,    -1,   135,    40,   451,
      41,    -1,   132,    40,   451,    41,    -1,   124,    40,   451,
      41,    -1,   118,    40,   451,    41,    -1,    88,   375,    -1,
     478,    -1,   139,    40,   451,    41,    -1,   136,    40,   451,
      41,    -1,   134,    40,   451,    41,    -1,   130,    40,   451,
      41,    -1,   121,    40,   451,    48,   451,    41,    -1,   131,
      40,   451,    48,   451,    41,    -1,   138,    40,   451,    48,
     451,    41,    -1,   109,    40,   451,    41,    -1,   141,    40,
     451,    41,    -1,   133,    40,   451,    41,    -1,   129,    40,
     451,    41,    -1,   126,    40,   451,    41,    -1,   122,    40,
     451,    41,    -1,   117,    40,   451,    41,    -1,   115,   182,
      -1,   107,    40,   451,    41,    -1,   140,    40,   451,    41,
      -1,   137,    40,   451,    41,    -1,   128,    40,   451,    41,
      -1,   119,    40,   451,    41,    -1,   113,    40,   451,    41,
      -1,    70,   375,    -1,    71,    40,   451,    48,   451,    48,
     451,    41,    -1,    72,    40,   451,    48,   451,    41,    -1,
      73,    40,   451,    48,   451,    41,    -1,    81,    40,   451,
      48,   451,    41,    -1,    82,    40,   451,    41,    -1,    83,
      40,   451,    41,    -1,    84,    40,   451,    41,    -1,    85,
      40,   451,    41,    -1,    99,    40,   451,    41,    -1,   476,
      -1,   479,    -1,   480,    -1,    40,   451,    41,    -1,   182,
      -1,    86,    40,   451,    48,   451,   477,    41,    -1,    -1,
     373,    -1,   127,    40,   451,    48,   451,   477,    41,    -1,
      74,   335,    -1,    65,    74,   335,    -1,    92,    40,   372,
     483,    41,    -1,   484,    40,   372,   451,    41,    -1,    -1,
      97,    40,   372,   451,   482,   486,    41,    -1,    19,    -1,
     451,    -1,    93,    -1,    94,    -1,    95,    -1,    96,    -1,
      98,    -1,    49,    75,    55,   498,    -1,    -1,   485,    -1,
     499,   488,    -1,    -1,   370,    -1,   498,   492,    -1,    87,
     499,    -1,   181,    -1,   490,    -1,    -1,   491,    -1,   494,
      -1,   495,    -1,   496,    -1,   161,    -1,   162,    -1,   163,
      -1,   164,    -1,   165,    -1,   166,    -1,   167,    -1,   168,
      -1,   169,    -1,   159,    -1,   160,    -1,   170,    -1,   172,
      -1,   171,    -1,   173,    -1,   174,    -1,   500,    -1,   176,
      -1,   175,    -1,   177,    -1,   178,    -1
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
     167,   173,   178,   179,   182,   183,   189,   193,   195,   197,
     198,   200,   203,   204,   206,   211,   213,   215,   217,   219,
     221,   223,   225,   227,   229,   232,   234,   236,   237,   244,
     250,   252,   255,   257,   259,   260,   262,   266,   269,   271,
     273,   275,   278,   280,   283,   284,   286,   291,   292,   294,
     295,   297,   298,   300,   301,   303,   307,   309,   312,   314,
     316,   321,   323,   326,   328,   331,   333,   337,   339,   342,
     344,   346,   348,   350,   353,   355,   357,   360,   363,   364,
     366,   367,   369,   372,   375,   376,   383,   384,   387,   389,
     392,   393,   398,   400,   401,   404,   406,   408,   410,   412,
     414,   416,   418,   419,   424,   425,   427,   430,   431,   433,
     435,   437,   439,   441,   443,   445,   447,   449,   451,   453,
     455,   459,   462,   463,   465,   469,   470,   472,   476,   480,
     486,   492,   498,   501,   504,   507,   513,   516,   517,   519,
     520,   522,   525,   527,   528,   531,   534,   537,   540,   542,
     545,   547,   550,   551,   553,   556,   558,   560,   562,   564,
     568,   572,   575,   576,   578,   579,   581,   585,   586,   589,
     590,   591,   592,   601,   604,   607,   608,   610,   612,   614,
     616,   618,   619,   624,   627,   628,   630,   634,   635,   638,
     641,   644,   645,   647,   649,   651,   653,   655,   657,   659,
     661,   663,   665,   668,   669,   673,   674,   675,   676,   683,
     684,   685,   691,   698,   699,   700,   705,   706,   707,   712,
     713,   717,   718,   721,   724,   726,   728,   730,   733,   735,
     736,   743,   744,   746,   749,   750,   753,   755,   756,   762,
     763,   768,   769,   771,   774,   777,   778,   780,   781,   785,
     786,   790,   794,   797,   798,   800,   803,   804,   807,   809,
     810,   812,   815,   818,   819,   822,   824,   826,   828,   829,
     833,   834,   838,   839,   844,   846,   848,   849,   853,   854,
     856,   859,   860,   863,   865,   867,   869,   871,   874,   877,
     878,   881,   884,   887,   888,   891,   894,   895,   897,   899,
     902,   904,   906,   909,   912,   914,   917,   921,   923,   925,
     927,   930,   932,   934,   936,   939,   943,   945,   948,   949,
     952,   955,   956,   958,   960,   964,   966,   968,   970,   972,
     974,   977,   979,   981,   983,   984,   989,   994,   996,   998,
    1000,  1002,  1004,  1005,  1007,  1009,  1012,  1014,  1016,  1018,
    1020,  1022,  1024,  1026,  1028,  1030,  1032,  1034,  1036,  1038,
    1040,  1042,  1045,  1048,  1049,  1052,  1055,  1058,  1059,  1062,
    1064,  1067,  1068,  1070,  1073,  1076,  1079,  1082,  1085,  1088,
    1091,  1095,  1097,  1100,  1102,  1104,  1107,  1110,  1111,  1113,
    1116,  1119,  1122,  1123,  1126,  1129,  1130,  1133,  1136,  1139,
    1142,  1144,  1146,  1148,  1150,  1152,  1154,  1156,  1158,  1160,
    1164,  1169,  1174,  1181,  1186,  1191,  1196,  1201,  1204,  1207,
    1212,  1217,  1222,  1227,  1230,  1232,  1237,  1242,  1247,  1252,
    1259,  1266,  1273,  1278,  1283,  1288,  1293,  1298,  1303,  1308,
    1311,  1316,  1321,  1326,  1331,  1336,  1341,  1344,  1353,  1360,
    1367,  1374,  1379,  1384,  1389,  1394,  1399,  1401,  1403,  1405,
    1409,  1411,  1419,  1420,  1422,  1430,  1433,  1437,  1443,  1449,
    1450,  1458,  1460,  1462,  1464,  1466,  1468,  1470,  1472,  1477,
    1478,  1480,  1483,  1484,  1486,  1489,  1492,  1494,  1496,  1497,
    1499,  1501,  1503,  1505,  1507,  1509,  1511,  1513,  1515,  1517,
    1519,  1521,  1523,  1525,  1527,  1529,  1531,  1533,  1535,  1537,
    1539,  1541,  1543,  1545
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  SPARQLfedParser::yyrline_[] =
  {
         0,   474,   474,   477,   483,   488,   499,   500,   501,   502,
     507,   510,   515,   519,   521,   525,   527,   530,   532,   536,
     536,   554,   560,   563,   567,   568,   569,   573,   574,   577,
     579,   583,   587,   591,   592,   596,   597,   601,   601,   609,
     615,   619,   620,   623,   625,   629,   633,   637,   638,   642,
     643,   647,   647,   655,   661,   665,   668,   670,   674,   674,
     681,   683,   687,   690,   692,   696,   699,   705,   711,   713,
     711,   723,   731,   734,   742,   742,   755,   763,   766,   773,
     776,   781,   788,   791,   796,   803,   806,   809,   812,   815,
     818,   821,   825,   830,   833,   841,   844,   851,   851,   862,
     870,   873,   881,   884,   891,   894,   899,   907,   914,   915,
     919,   925,   931,   938,   945,   947,   952,   959,   962,   967,
     970,   975,   978,   983,   987,   991,   998,  1001,  1008,  1011,
    1014,  1017,  1023,  1029,  1032,  1039,  1044,  1051,  1055,  1063,
    1065,  1073,  1076,  1084,  1092,  1093,  1100,  1104,  1112,  1115,
    1120,  1123,  1127,  1133,  1140,  1140,  1148,  1150,  1156,  1159,
    1165,  1165,  1170,  1176,  1178,  1182,  1185,  1188,  1191,  1194,
    1197,  1203,  1207,  1207,  1216,  1218,  1222,  1225,  1227,  1231,
    1232,  1233,  1234,  1235,  1236,  1237,  1238,  1239,  1240,  1241,
    1245,  1252,  1259,  1262,  1266,  1272,  1275,  1281,  1287,  1293,
    1299,  1305,  1311,  1319,  1327,  1335,  1344,  1350,  1353,  1357,
    1360,  1364,  1368,  1374,  1376,  1382,  1389,  1396,  1402,  1405,
    1411,  1414,  1419,  1421,  1425,  1431,  1434,  1437,  1440,  1447,
    1451,  1455,  1458,  1460,  1464,  1466,  1470,  1473,  1475,  1480,
    1485,  1488,  1480,  1499,  1503,  1506,  1508,  1512,  1513,  1526,
    1527,  1532,  1532,  1543,  1547,  1549,  1559,  1563,  1566,  1582,
    1587,  1591,  1594,  1598,  1599,  1600,  1601,  1602,  1603,  1604,
    1605,  1608,  1612,  1618,  1618,  1634,  1638,  1640,  1634,  1651,
    1655,  1651,  1664,  1675,  1679,  1675,  1689,  1693,  1689,  1703,
    1703,  1718,  1720,  1724,  1735,  1736,  1737,  1741,  1749,  1753,
    1753,  1762,  1765,  1772,  1778,  1780,  1794,  1797,  1797,  1807,
    1807,  1815,  1817,  1822,  1827,  1831,  1833,  1837,  1837,  1840,
    1840,  1847,  1852,  1856,  1858,  1863,  1867,  1869,  1874,  1878,
    1880,  1885,  1890,  1894,  1896,  1900,  1907,  1911,  1919,  1919,
    1922,  1922,  1928,  1928,  1934,  1935,  1939,  1939,  1944,  1946,
    1950,  1953,  1955,  1959,  1963,  1967,  1973,  1977,  1981,  1984,
    1986,  1990,  1994,  1999,  2001,  2007,  2010,  2012,  2018,  2019,
    2025,  2029,  2030,  2034,  2035,  2039,  2040,  2044,  2045,  2046,
    2047,  2051,  2055,  2058,  2061,  2064,  2070,  2074,  2077,  2079,
    2083,  2086,  2088,  2092,  2093,  2097,  2101,  2102,  2106,  2107,
    2108,  2112,  2117,  2118,  2122,  2122,  2135,  2160,  2163,  2166,
    2169,  2172,  2179,  2182,  2187,  2191,  2198,  2199,  2203,  2206,
    2210,  2213,  2219,  2220,  2224,  2227,  2230,  2233,  2236,  2237,
    2243,  2248,  2257,  2264,  2267,  2275,  2284,  2291,  2294,  2301,
    2306,  2317,  2320,  2324,  2327,  2330,  2333,  2336,  2339,  2342,
    2345,  2351,  2356,  2365,  2368,  2375,  2378,  2385,  2388,  2393,
    2396,  2400,  2414,  2417,  2425,  2434,  2437,  2444,  2447,  2450,
    2453,  2457,  2458,  2459,  2460,  2463,  2466,  2469,  2472,  2476,
    2482,  2485,  2488,  2491,  2494,  2497,  2500,  2504,  2507,  2510,
    2513,  2516,  2519,  2522,  2525,  2526,  2529,  2532,  2535,  2538,
    2541,  2544,  2547,  2550,  2553,  2556,  2559,  2562,  2565,  2568,
    2571,  2574,  2577,  2580,  2583,  2586,  2589,  2593,  2596,  2599,
    2602,  2605,  2608,  2611,  2614,  2617,  2620,  2621,  2622,  2628,
    2631,  2638,  2645,  2648,  2652,  2658,  2665,  2672,  2675,  2679,
    2679,  2691,  2695,  2699,  2702,  2705,  2708,  2711,  2717,  2723,
    2726,  2730,  2740,  2743,  2748,  2756,  2763,  2767,  2775,  2779,
    2783,  2784,  2785,  2789,  2790,  2791,  2795,  2796,  2797,  2801,
    2802,  2803,  2807,  2808,  2812,  2813,  2814,  2815,  2819,  2820,
    2824,  2825,  2829,  2830
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
  const int SPARQLfedParser::yylast_ = 2509;
  const int SPARQLfedParser::yynnts_ = 319;
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
#line 5398 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 2836 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


