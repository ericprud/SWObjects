
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
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause);
	/* $2 is known to be a DefaultGraphPattern because of grammar restrictions. */
	(yyval.p_Operation) = new Construct((DefaultGraphPattern*)(yysemantic_stack_[(5) - (2)].p_BasicGraphPattern), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 860 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(5) - (4)].p_WhereClause) ? (yysemantic_stack_[(5) - (4)].p_WhereClause) : new WhereClause(new DefaultGraphPattern());
	(yyval.p_Operation) = new Describe((yysemantic_stack_[(5) - (2)].p_VarSet), (yysemantic_stack_[(5) - (3)].p_DatasetClauses), (yysemantic_stack_[(5) - (4)].p_WhereClause), (yysemantic_stack_[(5) - (5)].p_SolutionModifier));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 868 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_TTerm))));
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 871 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back(new ExpressionAlias(new TTermExpression((yysemantic_stack_[(2) - (2)].p_TTerm))));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 879 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = (yysemantic_stack_[(1) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 882 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_VarSet) = new StarVarSet();
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 889 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_WhereClause) = NULL;
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 897 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.lastWhereClause = (yysemantic_stack_[(3) - (3)].p_WhereClause);
	(yyval.p_Operation) = new Ask((yysemantic_stack_[(3) - (2)].p_DatasetClauses), (yysemantic_stack_[(3) - (3)].p_WhereClause));
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 905 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = (yysemantic_stack_[(2) - (2)].p_DatasetClause);
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 917 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new DefaultGraphClause((yysemantic_stack_[(1) - (1)].p_TTerm), driver.atomFactory);
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 923 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DatasetClause) = new NamedGraphClause((yysemantic_stack_[(2) - (2)].p_TTerm), driver.atomFactory);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 929 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 936 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_WhereClause) = new WhereClause(driver.curOp ? driver.curOp : new DefaultGraphPattern());
	driver.curOp = NULL;
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 950 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SolutionModifier) = new SolutionModifier((yysemantic_stack_[(4) - (1)].p_ExpressionAliaseList), (yysemantic_stack_[(4) - (2)].p_Expressions), (yysemantic_stack_[(4) - (3)].p_OrderConditions), (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).limit, (yysemantic_stack_[(4) - (4)].p_LimitOffsetPair).offset); // !!!
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 957 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = driver.countStar ? new ExpressionAliasList() : NULL;
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 965 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 973 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = NULL;
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 981 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 989 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(3) - (3)].p_ExpressionAliaseList);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 996 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAliaseList) = new ExpressionAliasList((yysemantic_stack_[(1) - (1)].p_ExpressionAlias));
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 999 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList)->push_back((yysemantic_stack_[(2) - (2)].p_ExpressionAlias));
	(yyval.p_ExpressionAliaseList) = (yysemantic_stack_[(2) - (1)].p_ExpressionAliaseList);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1006 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1009 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1012 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = (yysemantic_stack_[(4) - (3)].p_Variable) ? new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression), (yysemantic_stack_[(4) - (3)].p_Variable)) : new ExpressionAlias((yysemantic_stack_[(4) - (2)].p_Expression));
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1015 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ExpressionAlias) = new ExpressionAlias(new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable)));
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1021 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (2)].p_Expressions);
}
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1027 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>((yysemantic_stack_[(1) - (1)].p_Expression));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1030 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1042 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = (yysemantic_stack_[(3) - (3)].p_OrderConditions);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1049 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditions) = new std::vector<s_OrderConditionPair>();
	(yyval.p_OrderConditions)->push_back((yysemantic_stack_[(1) - (1)].p_OrderConditionPair));
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1053 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_OrderConditions)->push_back((yysemantic_stack_[(2) - (2)].p_OrderConditionPair));
	(yyval.p_OrderConditions) = (yysemantic_stack_[(2) - (1)].p_OrderConditions);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1063 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = ORDER_Asc;
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(1) - (1)].p_Expression);
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1071 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Asc;
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1074 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_e_ASCorDESC) = ORDER_Desc;
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1082 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_OrderConditionPair).ascOrDesc = (yysemantic_stack_[(2) - (1)].p_e_ASCorDESC);
	(yyval.p_OrderConditionPair).expression = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1091 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1098 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).offset;
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1102 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = (yysemantic_stack_[(2) - (2)].p_LimitOffsetPair).limit;
	(yyval.p_LimitOffsetPair).offset = (yysemantic_stack_[(2) - (1)].p_LimitOffsetPair).offset;
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1110 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = OFFSET_None;
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1118 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = LIMIT_None;
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1125 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).limit = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1131 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_LimitOffsetPair).offset = ((IntegerRDFLiteral*)(yysemantic_stack_[(2) - (2)].p_NumericRDFLiteral))->getValue();
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1138 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingSet();
      }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1140 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BindingClause) = new BindingClause(driver.endBindingSet());
      }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1148 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingVar((yysemantic_stack_[(2) - (2)].p_Variable));
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1154 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1157 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.addBindingValue((yysemantic_stack_[(2) - (2)].p_TTerm));
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1163 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow(); // @@ push down to _Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star?
      }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1165 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.endBindingRow();
      }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1168 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.startBindingRow();
	driver.endBindingRow();
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 1180 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1183 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1186 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1189 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1192 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = TTerm::Unbound;
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1195 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 1205 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	OperationSet* ret = driver.root ? dynamic_cast<OperationSet*>(driver.root) : new OperationSet();
	ret->push_back((yysemantic_stack_[(2) - (2)].p_Operation));
	driver.root = ret;
      }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 1209 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Operation) = driver.root;
	}
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 1243 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Load((yysemantic_stack_[(3) - (2)].p_URI), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 1250 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 1257 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 1264 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Clear((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 1270 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_No;
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1273 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Silence) = SILENT_Yes;
}
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1279 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Drop((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
}
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1285 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Create((yysemantic_stack_[(3) - (2)].p_Silence), (yysemantic_stack_[(3) - (3)].p_URI));
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1291 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Add((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 1297 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Move((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 1303 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Copy((yysemantic_stack_[(5) - (2)].p_Silence), (yysemantic_stack_[(5) - (3)].p_URI), (yysemantic_stack_[(5) - (5)].p_URI));
}
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 1309 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Insert(driver.curOp, NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 1317 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete(driver.curOp, NULL);
	driver.curOp = NULL;
	driver.curBGP = NULL;
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 1325 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Operation) = new Delete(driver.curOp, NULL);
	driver.curOp = NULL;
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 1333 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(5) - (1)].p_URI))
	    w3c_sw_NEED_IMPL("WITH <URI> (DELETE INSERT?|INSERT) ...");
	(yyval.p_Operation) = new Modify((yysemantic_stack_[(5) - (2)].p_DeleteInsert).del, (yysemantic_stack_[(5) - (2)].p_DeleteInsert).ins, new WhereClause(driver.curOp));
	driver.curOp = NULL;
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 1342 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 1348 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 1355 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = NULL;
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 1362 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = (yysemantic_stack_[(2) - (1)].p_Delete);
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(2) - (2)].p_Insert);
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 1366 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_DeleteInsert).del = NULL;
	(yyval.p_DeleteInsert).ins = (yysemantic_stack_[(1) - (1)].p_Insert);
    }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 1374 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("_QUsingClause_E_Star");
    }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 1380 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Delete) = new Delete(driver.curOp, NULL);
	driver.curOp = NULL;
    }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 1387 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Insert) = new Insert(driver.curOp, NULL);
	driver.curOp = NULL;
    }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 1394 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 1400 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 1403 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@");
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 1409 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = NULL;
    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 1412 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 1423 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 1429 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 1432 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("DEFAULT");
      }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 1435 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("NAMED");
      }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 1438 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("ALL");
      }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 1478 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
	driver.curFilter = NULL;
      }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 1483 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(3) - (3)].p_TTerm);
      }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 1486 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
	driver.curOp = NULL;
      }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 1489 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.curBGP = NULL;
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(8) - (1)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(8) - (3)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(8) - (4)].p_TTerm);
      }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 1511 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	ResultSet* copy = new ResultSet(*driver.bindingsMap[(yysemantic_stack_[(1) - (1)].p_RSName)->name]);
	delete (yysemantic_stack_[(1) - (1)].p_RSName);
	BindingClause* b = new BindingClause(copy);
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, b) : b;
      }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 1527 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = NULL;
	driver.curBGP = NULL;
      }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 1530 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
 	  // if ($2) LINE << $2 << ": " << *$2 << "--\n";
	  // if ($4) LINE << $4 << ": " << *$4 << "--\n";
	  driver.curBGP = NULL;
      }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 1601 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = driver.curOp ? driver.makeConjunction(driver.curOp, (yysemantic_stack_[(1) - (1)].p_BindingClause)) : (yysemantic_stack_[(1) - (1)].p_BindingClause);
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 1608 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Print(driver.curOp);
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 1614 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 1618 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 274:

/* Line 678 of lalr1.cc  */
#line 1630 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 1634 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 1636 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curGraphName;
	  driver.curGraphName = (yysemantic_stack_[(4) - (4)].p_TTerm);
      }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 1639 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(6) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(6) - (2)].p_TableOperation), new GraphGraphPattern((yysemantic_stack_[(6) - (4)].p_TTerm), driver.curOp));
	  driver.curGraphName = (yysemantic_stack_[(6) - (5)].p_TTerm);
      }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 1647 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 1651 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 1653 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(5) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(5) - (2)].p_TableOperation), new ServiceGraphPattern((yysemantic_stack_[(5) - (4)].p_TTerm), driver.curOp, driver.atomFactory, false));
      }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 1660 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curOp = new Bind(driver.curOp, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Variable));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 1666 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 1670 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 1672 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (3)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (2)].p_TableOperation), new MinusGraphPattern(driver.curOp));
      }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 1680 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 1684 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ParserFilter) = driver.saveFilter();
      }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 1686 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  driver.restoreFilter((yysemantic_stack_[(4) - (2)].p_ParserFilter));
	  driver.curOp = driver.makeConjunction((yysemantic_stack_[(4) - (1)].p_TableOperation), driver.curOp);
      }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 1694 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curOp == NULL)
	    driver.ensureBasicGraphPattern();
	driver.restoreFilter(NULL);
	(yyval.p_TableOperation) = driver.curOp;
	driver.curOp = NULL;
      }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 1700 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  if (driver.curOp == NULL)
	      driver.ensureBasicGraphPattern();
	  driver.restoreFilter(NULL);
	  driver.curOp = driver.makeDisjunction((yysemantic_stack_[(3) - (2)].p_TableOperation), driver.curOp);
      }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 1715 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if (driver.curFilter == NULL) {
	    if (driver.curOp == NULL)
		driver.ensureBasicGraphPattern();
	    driver.curFilter = new ParserFilter();
	}
	driver.curFilter->addExpression((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 1732 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 1740 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 1744 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(3) - (3)].p_Expression));
      }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 1746 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_ArgList) = new ArgList(driver.curExprList); // !!! $2, 
	  driver.curExprList = NULL;
      }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 1753 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 1756 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_distinctness) = DIST_all;
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 1763 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 1771 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 1785 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = NULL;
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 1788 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(2) - (2)].p_Expression));
      }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 1790 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_Expressions) = driver.curExprList;
	  driver.curExprList = NULL;
      }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 1798 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curBGP = NULL;
      }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 1800 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_BasicGraphPattern) = driver.curBGP;
      }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 1828 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 1831 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 1891 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.ensureBasicGraphPattern();
	driver.curBGP->addTriplePattern(driver.atomFactory->getTriple(driver.curSubject, driver.curPredicate, (yysemantic_stack_[(1) - (1)].p_TTerm)));
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 1898 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_TTerm);
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 1902 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
	driver.curPredicate = (yyval.p_TTerm);
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 1910 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 1913 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curSubject = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 1919 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 1930 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curPredicate = (yysemantic_stack_[(1) - (1)].p_TTerm);
      }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 1958 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 1985 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 1992 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 2003 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 2010 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 2046 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 2049 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#type");
    }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 2052 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 2055 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	w3c_sw_NEED_IMPL("@@@");
    }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 2113 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_SubjectPredicatePair).subject = driver.curSubject;
	(yyval.p_SubjectPredicatePair).predicate = driver.curPredicate;
	driver.curSubject = driver.createBNode();
      }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 2117 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  (yyval.p_TTerm) = driver.curSubject; // could store w/ type in ctx..
	  driver.curSubject = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).subject;
	  driver.curPredicate = (yysemantic_stack_[(4) - (2)].p_SubjectPredicatePair).predicate;
      }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 2126 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 406:

/* Line 678 of lalr1.cc  */
#line 2151 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_members;
    }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 2154 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_starts;
    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 2157 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_ends;
    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 2160 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_any;
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 2163 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_unordered;
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 2170 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_listModifier) = LIST_exact;
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 2178 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerms) = new ProductionVector<const TTerm*>();
	(yyval.p_TTerms)->push_back((yysemantic_stack_[(1) - (1)].p_TTerm));
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 2182 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_TTerms)->push_back((yysemantic_stack_[(2) - (2)].p_TTerm));
	(yyval.p_TTerms) = (yysemantic_stack_[(2) - (1)].p_TTerms);
    }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 2194 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 2201 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_Variable);
    }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 2204 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 2215 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_URI);
    }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 2218 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_RDFLiteral);
    }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 2221 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral);
    }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 2224 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = (yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral);
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 2228 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_TTerm) = driver.getURI("http://www.w3.org/1999/02/22-rdf-syntax-ns#nil"); // !!! new GraphTerm_rule5($1);
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 2239 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanDisjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 2248 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 2255 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 2258 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 2266 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new BooleanConjunction((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 2275 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 2282 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 2285 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 2297 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_GeneralComparator)) {
	    (yysemantic_stack_[(2) - (2)].p_GeneralComparator)->setLeftParm((yysemantic_stack_[(2) - (1)].p_Expression));
	    (yyval.p_Expression) = new ComparatorExpression((yysemantic_stack_[(2) - (2)].p_GeneralComparator)); // !!!
	} else
	    (yyval.p_Expression) = (yysemantic_stack_[(2) - (1)].p_Expression);
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 2308 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = NULL;
    }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 2315 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanEQ((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 2318 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanNE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 2321 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 2324 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGT((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 2327 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanLE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 2330 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new BooleanGE((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 2333 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryIn((yysemantic_stack_[(2) - (2)].p_Expressions));
    }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 2336 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_GeneralComparator) = new NaryNotIn((yysemantic_stack_[(3) - (3)].p_Expressions));
    }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 2347 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticSum((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 2356 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 2359 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new NumberExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 2366 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 2369 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticInverse((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 2376 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 2384 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 2387 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 2391 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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

  case 461:

/* Line 678 of lalr1.cc  */
#line 2405 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 2408 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 2416 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expressions)->size() > 0 ? new ArithmeticProduct((yysemantic_stack_[(2) - (1)].p_Expression), (yysemantic_stack_[(2) - (2)].p_Expressions)) : (yysemantic_stack_[(2) - (1)].p_Expression);
	(yysemantic_stack_[(2) - (2)].p_Expressions)->clear();
	delete (yysemantic_stack_[(2) - (2)].p_Expressions);
    }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 2425 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expressions) = new ProductionVector<const Expression*>();
    }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 2428 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yysemantic_stack_[(2) - (1)].p_Expressions)->push_back((yysemantic_stack_[(2) - (2)].p_Expression));
	(yyval.p_Expressions) = (yysemantic_stack_[(2) - (1)].p_Expressions);
    }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 2435 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new BooleanNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 2438 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(2) - (2)].p_Expression);
    }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 2441 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new ArithmeticNegation((yysemantic_stack_[(2) - (2)].p_Expression));
    }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 2451 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_RDFLiteral));
    }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 2454 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_NumericRDFLiteral));
    }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 2457 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_BooleanRDFLiteral));
    }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 2460 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(1) - (1)].p_Variable));
    }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 2467 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 2473 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_str, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 2476 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lang, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 2479 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_langMatches, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 2482 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_datatype, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 2485 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_bound, new TTermExpression((yysemantic_stack_[(4) - (3)].p_Variable)), NULL, NULL));
    }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 2488 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 2491 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_iri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 2495 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_blank, (yysemantic_stack_[(2) - (2)].p_Expression), NULL, NULL));
    }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 2498 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_rand, NULL, NULL, NULL));
    }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 2501 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_abs, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 2504 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ciel, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 2507 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_floor, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 2510 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_round, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 2513 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::XPATH_concat, new ArgList((yysemantic_stack_[(2) - (2)].p_Expressions))));
    }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 2517 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlen, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 2520 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_ucase, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 2523 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_lcase, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 2526 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_encodeForUri, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 2529 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_contains, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 2532 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strStarts, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 2535 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strEnds, (yysemantic_stack_[(6) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 2538 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_year, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 2541 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_month, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 2544 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_day, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 2547 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_hours, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 2550 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_minutes, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 2553 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_seconds, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 2556 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_timezone, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 2559 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_now, NULL, NULL, NULL));
    }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 2562 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_md5, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 2565 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha1, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 2568 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha224, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 2571 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha256, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 2574 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha384, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 2577 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sha512, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 2580 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_coalesce, $2, NULL, NULL));
	w3c_sw_NEED_IMPL("COALESCE");
    }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 2584 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_if, (yysemantic_stack_[(8) - (3)].p_Expression), (yysemantic_stack_[(8) - (5)].p_Expression), (yysemantic_stack_[(8) - (7)].p_Expression)));
    }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 2587 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strlang, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 2590 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_strdt, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 2593 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_sameTerm, (yysemantic_stack_[(6) - (3)].p_Expression), (yysemantic_stack_[(6) - (5)].p_Expression), NULL));
    }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 2596 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 2599 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isIRI, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 2602 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isBlank, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 2605 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isLiteral, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 2608 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_isNumeric, (yysemantic_stack_[(4) - (3)].p_Expression), NULL, NULL));
    }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 2619 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = (yysemantic_stack_[(3) - (2)].p_Expression);
    }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 2622 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 2629 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_regex, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 2636 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
    }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 2643 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new FunctionCall(TTerm::FUNC_substring, (yysemantic_stack_[(7) - (3)].p_Expression), (yysemantic_stack_[(7) - (5)].p_Expression), (yysemantic_stack_[(7) - (6)].p_Expression)));
    }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 2649 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 2656 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL; // new FunctionCallExpression(new BooleanNegation(new FunctionCall(TTerm::FUNC_exists, driver.curOp, NULL, NULL)));
	w3c_sw_NEED_IMPL("EXISTS");
    }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 2663 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_count, (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 2666 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = new FunctionCallExpression(new AggregateCall((yysemantic_stack_[(5) - (1)].p_URI), (yysemantic_stack_[(5) - (3)].p_distinctness), (yysemantic_stack_[(5) - (4)].p_Expression)));
    }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 2670 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	driver.curExprList = new ProductionVector<const Expression*>((yysemantic_stack_[(4) - (4)].p_Expression));
      }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 2672 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	  // x = new ArgList($2, driver.curExprList);
	  delete driver.curExprList;
	  driver.curExprList = NULL;
	  w3c_sw_NEED_IMPL("GROUP_CONCAT"); // !!!
	  // $$ = new FunctionCallExpression(new AggregateCall(TTerm::FUNC_group-concat, $3, $4.p_Expression, $4.separator));
    }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 2682 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_Expression) = NULL;
	driver.countStar = true;
    }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 2690 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sum;
    }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 2693 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_min;
    }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 2696 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_max;
    }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 2699 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_avg;
    }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 2702 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = TTerm::FUNC_sample;
    }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 2708 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(4) - (4)].p_string), NULL, NULL);
    }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 2714 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = NULL;
    }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 2721 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	if ((yysemantic_stack_[(2) - (2)].p_ArgList))
	    (yyval.p_Expression) = new FunctionCallExpression(new FunctionCall((yysemantic_stack_[(2) - (1)].p_URI), (yysemantic_stack_[(2) - (2)].p_ArgList)));
	else
	    (yyval.p_Expression) = new TTermExpression((yysemantic_stack_[(2) - (1)].p_URI));
    }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 2731 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_ArgList) = NULL;
    }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 2739 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_RDFLiteral) = driver.getRDFLiteral(*(yysemantic_stack_[(2) - (1)].p_string), (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).uri, (yysemantic_stack_[(2) - (2)].p_uri_or_langtag).langtag);
	delete (yysemantic_stack_[(2) - (1)].p_string);
    }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 2747 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_URI) = (yysemantic_stack_[(2) - (2)].p_URI);
    }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 2754 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = (yysemantic_stack_[(1) - (1)].p_LANGTAG);
    }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 2758 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = (yysemantic_stack_[(1) - (1)].p_URI);
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 2766 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
    {
	(yyval.p_uri_or_langtag).uri = NULL;
	(yyval.p_uri_or_langtag).langtag = NULL;
    }
    break;



/* Line 678 of lalr1.cc  */
#line 3533 "lib/SPARQLfedParser/SPARQLfedParser.cpp"
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
  const short int SPARQLfedParser::yypact_ninf_ = -828;
  const short int
  SPARQLfedParser::yypact_[] =
  {
        36,  -119,    71,  -828,  -828,  2273,  -828,  -828,  -828,  -828,
    -828,  -828,    37,    46,    46,    46,   142,    42,    -4,  -828,
      37,    46,    46,    64,    77,    46,    77,    87,  -828,  -828,
    -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,
    -828,  -828,  -828,  -828,  -828,  -828,   174,   104,  -828,  -828,
    -828,   106,  -828,  -828,   284,   119,   284,  -828,  -828,  -828,
    1585,  -828,  -828,  -828,  -828,  -828,   156,  -828,  -828,  -828,
    -828,    25,  -828,    29,    29,   896,  -828,   896,  -828,    29,
    -828,  -828,  -828,  -828,    25,    80,    64,    64,  -828,   137,
    -828,  -828,   -10,  -828,   119,  -828,  -828,    37,  -828,  -828,
    -828,  -828,  -828,  -828,  -828,  -828,  1722,    95,   143,   150,
     -21,   -20,   161,   197,   199,    -8,   230,   232,   252,   257,
     262,   265,   269,   276,   280,   297,   301,   -20,   307,  -828,
    -828,  -828,  -828,   318,  -828,   330,   331,   332,   193,   336,
     196,   343,   350,   360,   361,   362,   364,   365,   367,   373,
     374,   375,   376,   379,   380,   387,   388,   389,   393,   397,
     398,   399,   400,  -828,  -828,  -828,  -828,  -828,  -828,  -828,
    -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,
    1838,  -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,
     401,  -828,  -828,  -828,  -828,  -828,  -828,   -50,   -15,   896,
      25,  -828,   112,    10,  -828,  -828,  -828,    -8,  -828,  -828,
     334,    37,   335,  -828,  -828,  -828,  -828,  -828,  -828,  -828,
    -828,  -828,   407,  -828,  -828,   402,  -828,  -828,  -828,  -828,
     406,  -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,   411,
     342,  -828,   363,    52,  -828,  -828,  -828,  -828,    -3,  -828,
    -828,   277,   396,  -828,  -828,  -828,  -828,  -828,  1722,  1954,
    1954,  1954,  -828,   377,  -828,  -828,  -828,  -828,   366,  -828,
    -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,
     -15,    -8,  1722,  1722,  1722,  -828,  -828,  1722,  -828,  -828,
    1722,  1722,  1722,  -828,  -828,  -828,  -828,  1722,  1722,  1722,
    1722,   101,  1722,  1722,  1722,  1722,  1722,  1722,  -828,   439,
     439,  1722,  1722,  1722,  -828,  1722,  -828,  1722,  1722,  1722,
    1722,  1722,  1722,  1722,  1722,  1722,  1722,  1722,  1722,  1722,
    1722,  1722,  1722,  1722,  1722,  1722,  1722,  1722,  1722,  -828,
     439,    37,  -828,  -828,  -828,  -828,   439,  -828,  -828,   425,
    -828,   420,   363,   363,  -828,    37,  -828,  -828,  -828,  -828,
    -828,  -828,    29,  -828,    29,   147,  -828,   459,   896,  -828,
    -828,   147,  1191,   147,  -828,    29,    -6,   442,  -828,   378,
    -828,   447,  -828,  -828,    -8,    18,  -828,  -828,  -828,   166,
     427,  -828,  -828,  -828,   101,  -828,   429,   419,   426,  1722,
    1722,  1722,  1722,  1722,  1722,   413,   -20,  -828,  -828,   227,
      32,  -828,  -828,  -828,   443,   446,   449,  -828,   435,   440,
     444,    56,   452,   455,   450,   456,   458,   453,   462,   463,
     464,   465,   461,  -828,  1426,  1722,   466,   469,   470,   473,
     475,   476,   477,   471,   480,   481,   482,   479,   483,   484,
     505,   499,   511,   513,   514,   518,   519,   521,   516,   524,
     526,   528,  1722,  -828,  1722,  -828,   896,  -828,  -828,  -828,
    -828,  -828,  -828,  -828,  -828,   448,  1191,  -828,  -828,   530,
     568,  -828,  -828,  -828,  -828,  -828,  1090,  -828,  -828,  -828,
    -828,  -828,  -828,  2070,  2191,   552,  -828,  -828,    37,  -828,
    -828,   403,  -828,   369,  -828,  -828,   795,  -828,  -828,   485,
    -828,  -828,   433,  -828,  -828,  -828,  -828,  -828,  1722,  -828,
    1722,  -828,  -828,  -828,  -828,  -828,  -828,  -828,   -20,  -828,
    1722,  1722,    32,  -828,  -828,  -828,  1722,  1722,  -828,  -828,
    -828,  -828,  -828,  1722,  1722,  1722,  -828,  -828,   541,  -828,
    -828,  -828,   540,  -828,  -828,  -828,  -828,  1722,  -828,  -828,
    1722,  -828,  -828,  -828,  -828,  1722,  -828,  -828,   543,  -828,
    -828,  -828,  -828,  -828,  -828,  -828,  -828,  1722,  -828,  -828,
    -828,  1722,  -828,  -828,  -828,  1722,  -828,  -828,  -828,  -828,
    -828,  -828,  1722,  -828,  -828,  -828,   544,  -828,  -828,  -828,
    -828,  -828,  -828,  -828,   896,   156,  -828,  -828,   -16,  1722,
    2070,  -828,  -828,  -828,  -828,  2191,  -828,  -828,  -828,  -828,
    -828,   561,   266,  -828,  -828,  -828,    65,  -828,  -828,  2054,
    -828,  -828,   486,  -828,  -828,  -828,  -828,  -828,  -828,  2054,
    -828,  -828,   441,  -828,    -1,  -828,     3,  -828,  -828,  -828,
    -828,  -828,  -828,  -828,  -828,  -828,    26,   546,   548,   554,
     558,  -828,   151,   896,  -828,  -828,   147,    30,   559,   560,
     556,  -828,   553,   565,   556,   566,   569,  -828,  -828,   563,
     567,  -828,  -828,  -828,  -828,  -828,  -828,   377,  -828,  -828,
    1208,   457,   460,  -828,  -828,   580,   588,  -828,  -828,  -828,
    -828,  -828,  -828,  -828,   -64,  -828,  -828,  -828,   185,  -828,
    -828,  -828,  -828,  1722,  -828,  1722,  -828,  -828,   363,  -828,
    -828,  -828,  -828,  2191,   582,    -8,  -828,  -828,   530,  -828,
    -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,
    -828,   100,  -828,   103,   223,  -828,  -828,  -828,  -828,  -828,
    -828,  -828,  -828,  -828,    43,  -828,  -828,  -828,  -828,  -828,
    -828,   579,   549,  -828,   584,  -828,   585,  -828,  -828,    58,
     147,  -828,  1191,  -828,   587,  2054,   589,  -828,  -828,  1208,
    -828,   592,  -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,
    -828,  -828,  -828,  -828,  -828,   369,  -828,  -828,   795,  -828,
     593,    87,  -828,  -828,    -8,  -828,  -828,  1722,  -828,   896,
      -8,   594,   164,  -828,    68,  -828,  -828,  -828,  -828,  -828,
    -828,  1191,   527,   570,  -828,   -19,  -828,  -828,  -828,  -828,
    -828,  -828,   581,  -828,  -828,  -828,  -828,  -828,  1191,  -828,
    -828,    86,  -828,  -828,  -828,  -828,   824,  -828,  -828,  -828,
    -828,   156,   156,  -828,    -8,   550,  -828,  -828,  -828,  -828,
     596,  -828,  -828,  -828,  -828,  -828,   100,  -828,   100,  -828,
     489,  -828,  -828,    60,   -61,  -828,   896,  -828,  -828,  -828,
    -828,   595,   206,  -828,    -8,  -828,   101,   598,  -828,   538,
     597,  -828,  -828,   604,  -828,    -5,  -828,  -828,   605,  -828,
    -828,  2054,  2054,    -8,  -828,   606,  -828,  -828,   164,  -828,
      30,  -828,  -828,  -828,  -828,   608,  -828,  -828,  -828,  -828,
    -828,    -8,  -828,  -828,  -828,  -828,  -828,  -828,  1191,  -828
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  SPARQLfedParser::yydefact_[] =
  {
        13,     0,     0,     2,     4,   206,    15,    14,     3,   170,
      67,     1,     0,   194,   194,   194,    79,     0,     0,    72,
       0,   194,   194,     0,     0,   194,     0,    10,     6,    72,
       7,     8,     9,   171,   178,   179,   180,   184,   181,   182,
     183,   185,   186,   187,   188,   207,     0,    17,   577,   580,
     579,   191,   578,   195,     0,     0,     0,    77,    78,    80,
       0,   308,    72,   102,   421,   422,   101,    72,    99,   419,
     420,   113,   205,   221,   221,   231,   203,   231,   202,   221,
     201,   153,     5,    11,   113,   176,     0,     0,   212,   208,
     211,    68,    12,    16,     0,   192,   189,     0,   226,   225,
     227,   224,   193,   197,   196,    96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   542,
     543,   544,   545,     0,   546,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   571,   572,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   573,   575,   574,   576,    92,    93,
      95,    76,    88,    85,    87,   525,   493,   526,   527,    86,
       0,    89,    90,   559,   560,   561,    91,   557,     0,   310,
     113,   100,   103,     0,   114,    73,   105,     0,   222,   219,
       0,     0,     0,   406,   407,   408,   409,   410,   403,   581,
     582,   428,     0,   236,   232,   244,   318,   402,   401,   412,
       0,   316,   417,   418,   424,   425,   426,   423,   427,     0,
       0,   155,   116,    13,   177,   172,   214,   215,     0,   210,
     209,     0,     0,    18,    23,    19,   190,   223,     0,     0,
       0,     0,   476,    82,   429,   432,   436,   438,   440,   450,
     461,   464,   469,   470,   471,   477,   472,   473,   474,   475,
     551,     0,     0,     0,     0,   529,   486,     0,   305,   515,
       0,     0,     0,   250,   247,   534,   246,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   492,   300,
     300,     0,     0,     0,   487,     0,   508,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
     300,     0,   555,   556,   558,   553,   300,   297,   296,     0,
     311,   314,   116,   116,   104,     0,   106,   107,   108,   109,
     111,   112,   221,   220,   221,     0,   228,   230,   231,   245,
     242,   328,   411,     0,   229,   221,     0,     0,    71,   118,
     117,   206,   174,   175,     0,     0,   213,    69,    21,     0,
       0,   467,   468,   466,     0,    83,     0,   430,   434,     0,
       0,     0,     0,     0,     0,     0,     0,   439,   441,   451,
     463,   552,   550,   535,     0,     0,     0,   306,     0,     0,
       0,   253,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   301,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   554,     0,   309,   310,   315,   312,    97,
      98,   110,   198,   200,   336,     0,   411,   335,   237,   233,
       0,   243,   329,   319,   327,   416,   411,   413,   415,   317,
     199,   162,   156,     0,     0,   120,   119,   204,     0,   216,
     217,     0,    56,     0,    31,    45,     0,    20,    24,     0,
      29,    25,     0,    43,    26,   478,    81,    84,     0,   433,
       0,   437,   442,   443,   444,   445,   446,   447,     0,   448,
       0,     0,   456,   462,   452,   453,     0,     0,   465,   484,
     485,   528,   303,     0,     0,     0,   248,    74,     0,   249,
     256,   254,   260,   339,   337,   479,   480,     0,   482,   483,
       0,   520,   521,   522,   523,     0,   540,   541,     0,   538,
     524,   509,   501,   514,   507,   491,   513,     0,   506,   490,
     505,     0,   512,   504,   497,     0,   489,   503,   496,   488,
     495,   511,     0,   494,   510,   502,     0,   298,   313,   404,
     325,   332,   334,   234,   231,     0,   405,   414,     0,     0,
     124,   125,   128,   130,   127,   131,   132,   134,   295,   293,
     294,     0,   122,   121,   218,    70,     0,   168,    35,    36,
      32,    33,     0,   169,   165,   166,   167,   164,    49,    50,
      46,    47,     0,    29,     0,    43,     0,   431,   435,   449,
     458,   459,   457,   460,   454,   455,     0,     0,     0,     0,
     113,   251,   285,   253,   261,   258,   328,     0,     0,     0,
     531,   536,   548,     0,   531,     0,     0,   537,   303,   320,
     330,   235,   239,   154,   159,   161,   163,    82,   126,   133,
       0,     0,     0,   115,   123,   147,   149,    55,    58,    57,
      34,    39,    48,    53,     0,    28,    37,    30,     0,    42,
      51,    44,   307,     0,   304,     0,   517,   518,   116,   274,
     278,   272,   282,     0,     0,     0,   269,   257,   233,   270,
     263,   265,   266,   268,   264,   262,   286,   267,   259,   352,
     340,     0,   382,     0,     0,   338,   341,   343,   344,   353,
     355,   358,   367,   362,   365,   380,   354,   381,   481,   519,
     532,     0,     0,   549,     0,   498,     0,   499,   500,     0,
     322,   326,   411,   333,     0,     0,     0,   140,   141,   135,
     136,     0,   138,   139,   143,   144,   151,   152,   145,   148,
     146,   150,    63,    40,    27,     0,    54,    41,     0,   302,
       0,    10,   275,   279,     0,   283,   292,     0,   271,   253,
       0,     0,   390,   398,     0,   383,   385,   392,   394,   397,
     368,   411,   356,   360,   376,     0,   378,   377,   364,   366,
     369,   530,     0,   539,   533,   299,   323,   324,   411,   331,
     240,     0,   157,   129,   137,   142,     0,    38,    52,   516,
      75,     0,     0,   273,     0,     0,   255,   290,   384,   391,
       0,   387,   396,   399,   395,   350,     0,   359,     0,   363,
       0,   400,   379,     0,     0,   321,   231,   160,   158,    59,
      64,    60,     0,   276,     0,   284,     0,   287,   393,   389,
     342,   357,   361,     0,   373,     0,   374,   547,     0,    61,
      62,     0,     0,     0,   280,     0,   288,   291,     0,   388,
     347,   351,   375,   370,   372,     0,   241,    66,    65,   277,
     281,     0,   386,   345,   348,   349,   371,   289,   411,   346
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yypgoto_[] =
  {
      -828,  -828,  -828,  -828,  -828,  -149,   410,  -828,  -828,  -828,
    -828,  -828,  -828,  -828,  -828,  -828,    13,  -828,   148,  -828,
    -137,  -828,  -828,    33,  -828,  -828,    14,  -828,   149,  -828,
    -138,  -828,  -828,    24,  -828,  -828,  -828,  -828,  -828,  -828,
    -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,    31,  -828,
    -828,   244,  -828,  -828,  -828,   -18,  -828,   487,  -828,  -828,
    -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,
     311,   -80,  -828,  -339,  -828,  -828,  -828,  -828,  -828,  -828,
      61,  -828,  -828,    53,  -828,  -828,  -109,  -828,  -828,  -828,
    -828,  -828,  -828,   -22,   -13,    22,  -828,  -828,  -828,  -828,
    -828,  -828,  -484,  -828,   437,  -828,  -828,  -828,  -828,  -828,
    -828,  -828,  -828,  -828,   303,  -828,  -828,  -828,  -828,  -828,
    -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,
     599,  -828,  -828,   -56,  -828,   -11,   629,   213,   660,   610,
    -363,   -39,  -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,
    -828,  -205,  -828,  -828,  -828,  -828,  -646,  -828,  -828,  -828,
    -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,
    -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,
    -828,  -828,  -828,  -828,  -641,   -57,   412,  -828,     2,  -597,
      12,  -120,  -828,  -828,  -828,   225,  -828,  -828,  -828,  -183,
    -828,  -828,  -320,  -828,  -828,  -828,  -828,  -828,    28,  -782,
    -828,  -828,   -77,   -74,  -828,  -828,  -828,  -828,  -828,  -213,
    -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,   -41,  -828,
    -828,  -828,  -165,  -828,  -828,   -42,  -828,  -164,  -828,  -828,
    -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,  -828,
    -828,  -772,  -828,  -828,  -827,  -362,  -828,  -828,  -828,  -828,
    -828,  -828,  -341,  -360,    -9,     9,  -828,   869,  -828,  -828,
    -828,   187,  -828,  -828,   183,  -828,  -828,  -828,   -36,  -828,
    -828,   175,  -828,  -828,  -828,  -179,  -828,  -182,    85,  -483,
     -59,  -828,  -828,    34,  -828,  -828,  -828,   -26,  -828,  -828,
    -828,  -828,  -828,  -828,  -828,   105,  -828,  -828,  -828,   207,
    -828,   305,   306,   309,  -168,   -12,  -828,  -828
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  SPARQLfedParser::yydefgoto_[] =
  {
        -1,     2,     3,     4,    27,    82,     5,     6,    47,    92,
     253,   389,   254,   255,   507,   508,   644,   509,   510,   629,
     630,   707,   795,   631,   794,   511,   646,   512,   513,   639,
     640,   711,   798,   641,   797,   514,   626,   699,   792,   900,
     880,   846,   881,     7,    93,   251,   501,    28,    71,   546,
     660,    29,    59,    60,   395,   396,   178,   179,   180,   181,
      30,    31,    66,    67,   353,    32,   205,   356,   357,   358,
     359,   206,   207,   378,   379,   495,   622,   693,   380,   610,
     611,   496,   615,   616,   623,   779,   780,   781,   782,   783,
     694,   788,   790,   695,   696,    83,   241,   376,   841,   686,
     775,   608,   632,     8,     9,    85,   383,   244,   245,    33,
      34,    95,    96,    35,    54,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,   249,    88,   248,    89,
      90,   386,   499,   210,   211,   101,   102,    76,    78,   222,
     223,   604,   478,   367,   479,   480,   774,   876,   224,   369,
     370,   295,   548,   296,   421,   549,   550,   727,   662,   551,
     664,   665,   728,   729,   730,   804,   731,   802,   851,   903,
     732,   803,   852,   733,   734,   805,   854,   735,   736,   810,
     907,   921,   887,   737,   617,   618,   348,   678,   434,   714,
     656,   289,   542,    62,   199,   349,   350,   467,   468,   225,
     373,   371,   482,   836,   837,   771,   679,   483,   484,   600,
     773,   680,   601,   476,   552,   667,   666,   745,   821,   746,
     924,   928,   925,   911,   890,   740,   747,   748,   749,   750,
     867,   822,   751,   869,   823,   752,   828,   753,   829,   914,
     896,   872,   830,   754,   755,   815,   909,   889,   859,   860,
     816,   817,   863,   818,   873,   226,   227,   365,   228,   229,
     230,   486,   602,   231,   477,   262,   233,   263,   264,   519,
     397,   265,   521,   398,   266,   267,   407,   408,   268,   269,
     532,   538,   653,   533,   409,   270,   410,   271,   272,   273,
     274,   286,   185,   761,   186,   187,   188,   275,   672,   568,
     190,   763,   764,   276,   412,   277,   343,   344,   345,   278,
     193,   194,   195,   279,   197,   280,    52,   238
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int SPARQLfedParser::yytable_ninf_ = -412;
  const short int
  SPARQLfedParser::yytable_[] =
  {
        51,   184,   361,   182,   242,   481,    70,   308,    72,    68,
     485,   619,   488,   469,   470,    63,   351,   738,   212,   284,
     287,   683,   642,   240,   684,   346,   -22,    69,   293,   870,
     491,   487,   913,   355,   189,   208,   384,   341,   706,   865,
     861,   498,   705,   893,   103,   475,   709,   203,   198,   784,
       1,   536,  -173,   489,    70,    10,   875,   201,    53,   553,
      84,   554,   824,   237,   204,   237,     1,   712,   915,   183,
     741,    11,    16,   760,   713,    69,   413,   760,    61,   825,
     742,   793,   806,   256,   232,   257,   232,   213,   214,   215,
     216,   217,   -22,   200,   743,   537,  -411,   894,   202,   835,
      75,   706,   697,   385,   826,   698,   713,   218,   895,   174,
     175,   176,   177,    77,   485,    94,   488,    81,   862,    91,
     352,   184,   354,   182,   485,    97,   488,   877,   627,   243,
     744,   342,   619,   209,   203,   -22,   922,   -22,   784,   -22,
     741,    87,   871,   812,   827,   607,   929,   252,  -113,   294,
     742,   204,   710,   813,   189,   642,   871,   719,   720,    57,
      58,   285,   288,   856,   743,   191,   685,   347,   198,   281,
      48,    49,    50,    64,    65,    64,    65,    86,    87,   497,
     234,    81,   234,   282,    48,    49,    50,   237,  -252,   183,
     283,   360,    48,    49,    50,   721,   722,   474,   723,   363,
     744,   290,   502,   814,    48,    49,    50,   619,   232,    64,
      65,    48,    49,    50,   813,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
      48,    49,    50,   219,   220,    64,    65,   291,   221,   292,
     619,   681,    48,    49,    50,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
      48,    49,    50,   741,   814,    64,    65,   192,   503,  -113,
     297,   724,   298,   742,    48,    49,    50,    48,    49,    50,
      64,    65,   235,   351,   235,   191,   529,   743,   530,   531,
      97,   842,   299,   725,   691,   692,   619,   300,   845,   246,
     247,   553,   301,   554,   234,   302,   472,    98,   473,   303,
     426,   504,   435,   505,   642,   506,   304,    55,    56,   490,
     305,    48,    49,    50,    73,    74,    64,    65,    79,   463,
      48,    49,    50,   796,   710,    64,    65,   306,    48,    49,
      50,   307,   462,   360,   391,   392,   393,   309,   464,   901,
     902,   650,   651,    70,   654,   655,   237,   878,   310,    70,
     237,    70,   882,   522,   523,   524,   525,   526,   527,   196,
     311,   312,   313,   500,    69,   314,   315,   232,   316,   801,
      69,   232,    69,   317,   236,   492,   236,   192,    99,   100,
     318,   168,   169,   170,   171,   172,   173,    48,    49,    50,
     319,   320,   321,   516,   322,   323,   235,   324,   649,   237,
     485,   627,   488,   325,   326,   327,   328,   917,   918,   329,
     330,   399,   400,   401,   402,   403,   404,   331,   332,   333,
     232,   405,   406,   334,   614,   620,   612,   335,   336,   337,
     338,   340,   362,   364,   366,   368,   372,   553,   374,   554,
     375,   388,   387,   377,   237,    12,   433,    13,    14,   485,
      15,   488,   465,   466,   237,  -238,   394,   493,   515,   494,
     517,   628,   518,   234,   237,   232,   485,   234,   488,   528,
     520,   198,   198,   543,   539,   232,   624,   540,   544,   196,
     541,   637,   545,   555,   637,   232,   556,   558,   557,   559,
     599,   560,   613,   561,   562,   563,   564,   570,   236,   565,
     571,   572,   633,   898,   573,   633,   574,   575,   576,   577,
     808,   578,   579,   580,   582,   583,   234,   581,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,    48,    49,    50,   584,   585,    64,    65,
      20,   614,   586,   612,   587,   588,   620,    21,    22,   589,
     590,    23,   591,    24,   592,   593,   485,   594,   488,   595,
      25,   234,    26,   603,   605,   235,   621,   625,   661,   235,
     718,   234,   506,   663,   671,   677,   690,   503,   701,   716,
     703,   234,   237,    70,   715,   717,   682,   204,   198,   853,
     758,   759,   762,   198,   713,   857,   765,   767,   634,   692,
     768,   634,   770,   232,    69,   772,   691,   637,   786,   613,
     831,   787,   807,   840,   832,   833,   834,   637,   235,   866,
     843,   620,   258,   868,   849,   858,   874,   888,   633,   886,
     908,   912,   916,   899,   906,   926,   910,   920,   633,   885,
     871,   237,   850,   381,    70,   757,   704,   643,   847,   708,
     848,   645,   700,   702,   620,   547,   471,   339,   689,   776,
     844,   688,   232,   235,   791,    69,   756,   236,   198,   904,
     382,   236,   789,   235,   726,   104,    80,   239,   250,   809,
     769,   598,   411,   235,   739,   839,   838,   923,   919,   785,
     811,   891,   820,   648,   892,   647,   897,   652,   766,   234,
     635,   198,     0,   635,   534,   535,   927,     0,     0,     0,
     620,     0,     0,     0,     0,     0,     0,     0,     0,   757,
     236,   819,   757,     0,   634,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   634,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,     0,
     237,     0,     0,   637,     0,     0,     0,   198,   234,     0,
       0,     0,     0,     0,     0,   236,     0,     0,     0,    69,
       0,   232,     0,   637,   633,   236,   637,     0,   785,     0,
       0,     0,     0,     0,     0,   236,     0,   237,     0,     0,
     819,     0,   864,     0,   633,     0,     0,   633,     0,   237,
       0,   235,   636,     0,     0,   636,     0,     0,   232,     0,
       0,     0,     0,     0,     0,     0,   237,     0,     0,   637,
     232,     0,     0,     0,   637,     0,   635,   627,     0,    70,
      70,     0,   883,   884,     0,     0,   635,   232,     0,     0,
     633,     0,     0,     0,   757,   633,   757,     0,     0,     0,
      69,    69,     0,     0,   237,   879,   627,     0,     0,     0,
     235,     0,     0,     0,     0,     0,     0,   234,     0,     0,
     634,     0,     0,     0,     0,   232,     0,     0,     0,   637,
     637,     0,     0,     0,     0,   905,   819,     0,   757,     0,
     634,     0,     0,   634,     0,     0,     0,     0,     0,     0,
     633,   633,     0,   236,   234,     0,   237,     0,     0,   756,
       0,     0,     0,     0,     0,     0,   234,   213,   214,   215,
     216,   217,     0,     0,     0,     0,  -411,   232,   636,     0,
       0,     0,     0,   234,   638,     0,   634,   218,   636,     0,
       0,   634,     0,     0,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,    48,
      49,    50,   236,     0,    64,    65,     0,     0,     0,   235,
       0,   234,   635,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,    48,    49,
      50,     0,   635,    64,    65,   635,   634,   634,     0,     0,
       0,     0,     0,     0,     0,     0,   235,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   235,     0,
       0,     0,     0,   234,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   235,     0,     0,   635,     0,
       0,     0,     0,   635,     0,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
      48,    49,    50,   219,   220,    64,    65,     0,   221,     0,
       0,   236,     0,   235,   636,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   636,     0,     0,   636,   635,   635,
       0,     0,     0,     0,     0,     0,     0,     0,   236,     0,
       0,   213,   214,   215,   216,   217,     0,   390,     0,     0,
     236,   606,     0,     0,     0,   235,     0,     0,     0,     0,
       0,   218,     0,     0,     0,     0,     0,   236,     0,     0,
     636,   414,   415,   416,     0,   636,   417,     0,     0,   418,
     419,   420,     0,     0,     0,     0,   422,   423,   424,   425,
       0,   427,   428,   429,   430,   431,   432,     0,     0,     0,
     436,   437,   438,     0,   439,   236,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,     0,     0,
     636,   636,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   213,   214,   215,   216,   217,     0,     0,     0,
       0,     0,     0,     0,   777,   778,     0,   236,     0,     0,
       0,     0,   218,     0,     0,     0,     0,     0,   258,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,    48,    49,    50,   219,   220,    64,
      65,     0,   221,   107,     0,   108,   109,   110,   111,   112,
     113,   114,   115,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,     0,   127,     0,     0,     0,
       0,     0,     0,   567,   569,     0,     0,   135,     0,     0,
       0,     0,     0,     0,     0,   136,     0,   137,     0,     0,
     138,   139,     0,   140,     0,   141,   142,   143,     0,   144,
     145,   596,   146,   597,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,    48,    49,    50,   219,   220,
      64,    65,     0,   221,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    49,    50,     0,     0,    64,    65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   657,   658,   659,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   668,     0,     0,   669,
       0,     0,     0,     0,   670,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   566,   673,     0,     0,     0,
     674,     0,     0,     0,   675,     0,     0,     0,     0,     0,
       0,   676,     0,     0,     0,     0,   258,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   687,     0,
       0,     0,     0,     0,     0,     0,     0,   259,   260,     0,
     261,   107,     0,   108,   109,   110,   111,   112,   113,   114,
     115,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,     0,   127,     0,     0,     0,   128,   129,
     130,   131,   132,   133,   134,   135,     0,     0,     0,     0,
       0,     0,     0,   136,     0,   137,     0,     0,   138,   139,
       0,   140,     0,   141,   142,   143,     0,   144,   145,     0,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   799,     0,   800,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
      48,    49,    50,     0,   105,    64,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     107,     0,   108,   109,   110,   111,   112,   113,   114,   115,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,     0,   127,     0,     0,   855,   128,   129,   130,
     131,   132,   133,   134,   135,     0,     0,     0,     0,     0,
       0,     0,   136,     0,   137,     0,     0,   138,   139,     0,
     140,     0,   141,   142,   143,     0,   144,   145,     0,   146,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,    48,
      49,    50,   258,     0,    64,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,     0,   261,   107,     0,   108,
     109,   110,   111,   112,   113,   114,   115,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,     0,
     127,     0,     0,     0,   128,   129,   130,   131,   132,   133,
     134,   135,     0,     0,     0,     0,     0,     0,     0,   136,
       0,   137,     0,     0,   138,   139,     0,   140,     0,   141,
     142,   143,     0,   144,   145,     0,   146,     0,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   106,     0,
       0,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,    48,    49,    50,     0,
       0,    64,    65,   107,     0,   108,   109,   110,   111,   112,
     113,   114,   115,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,     0,   127,     0,     0,     0,
     128,   129,   130,   131,   132,   133,   134,   135,     0,     0,
       0,     0,     0,     0,     0,   136,     0,   137,     0,     0,
     138,   139,     0,   140,     0,   141,   142,   143,     0,   144,
     145,     0,   146,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   258,     0,     0,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,    48,    49,    50,     0,     0,    64,    65,   107,
       0,   108,   109,   110,   111,   112,   113,   114,   115,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,     0,   127,     0,     0,     0,   128,   129,   130,   131,
     132,   133,   134,   135,     0,     0,     0,     0,     0,     0,
       0,   136,     0,   137,     0,     0,   138,   139,     0,   140,
       0,   141,   142,   143,     0,   144,   145,     0,   146,     0,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   627,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     609,     0,     0,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,    48,    49,
      50,     0,     0,    64,    65,   107,     0,   108,   109,   110,
     111,   112,   113,   114,   115,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     0,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   135,
       0,     0,     0,     0,     0,     0,     0,   136,     0,   137,
       0,     0,   138,   139,     0,   140,     0,   141,   142,   143,
       0,   144,   145,     0,   146,     0,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,     0,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,    48,    49,
      50,   258,     0,    64,    65,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,    49,    50,     0,     0,    64,
      65,     0,     0,     0,     0,     0,   107,     0,   108,   109,
     110,   111,   112,   113,   114,   115,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,     0,   127,
       0,    12,     0,    13,    14,     0,    15,     0,     0,    16,
     135,     0,     0,    17,    18,     0,     0,     0,   136,     0,
     137,     0,     0,   138,   139,     0,   140,     0,   141,   142,
     143,    19,   144,   145,     0,   146,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,    49,    50,     0,     0,
       0,     0,     0,     0,     0,     0,    20,     0,     0,     0,
       0,     0,     0,    21,    22,     0,     0,    23,     0,    24,
       0,     0,     0,     0,     0,     0,    25,     0,    26
  };

  /* YYCHECK.  */
  const short int
  SPARQLfedParser::yycheck_[] =
  {
        12,    60,   207,    60,    84,   368,    18,   127,    20,    18,
     372,   494,   372,   352,   353,    19,   199,   663,    74,    40,
      40,    37,   506,    79,    40,    40,    36,    18,    36,    48,
      36,   372,    37,    23,    60,     6,    39,    87,   102,   821,
     812,    23,    43,   870,    55,   365,    43,    22,    60,   690,
      14,    19,     0,   373,    66,   174,   838,    66,    12,   421,
      29,   421,    19,    75,    39,    77,    14,    41,   895,    60,
      40,     0,    16,   670,    48,    66,   281,   674,    36,    36,
      50,   145,   723,    94,    75,    97,    77,    31,    32,    33,
      34,    35,   102,    62,    64,    63,    40,    37,    67,    41,
      36,   102,    37,   106,    61,    40,    48,    51,    48,   170,
     171,   172,   173,    36,   476,     9,   476,    30,    50,    15,
     200,   180,   202,   180,   486,     6,   486,    41,    42,    49,
     100,   181,   615,   104,    22,   145,   908,   147,   779,   149,
      40,     4,   161,    40,   101,   486,   928,   157,    36,   157,
      50,    39,   149,    50,   180,   639,   161,     6,     7,    17,
      18,   182,   182,   809,    64,    60,   182,   182,   180,    74,
     174,   175,   176,   179,   180,   179,   180,     3,     4,   384,
      75,    30,    77,    40,   174,   175,   176,   199,    37,   180,
      40,   203,   174,   175,   176,    44,    45,    50,    47,   211,
     100,    40,    36,   100,   174,   175,   176,   690,   199,   179,
     180,   174,   175,   176,    50,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    40,   182,    40,
     723,   604,   174,   175,   176,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    40,   100,   179,   180,    60,   102,   157,
      40,   120,    40,    50,   174,   175,   176,   174,   175,   176,
     179,   180,    75,   466,    77,   180,   406,    64,    61,    62,
       6,   775,    40,   142,    28,    29,   779,    40,   781,    86,
      87,   663,    40,   663,   199,    40,   362,    23,   364,    40,
     301,   145,   310,   147,   798,   149,    40,    14,    15,   375,
      40,   174,   175,   176,    21,    22,   179,   180,    25,   341,
     174,   175,   176,   148,   149,   179,   180,    40,   174,   175,
     176,    40,   340,   355,   259,   260,   261,    40,   346,   143,
     144,   530,   531,   365,   536,   537,   368,   841,    40,   371,
     372,   373,   846,   399,   400,   401,   402,   403,   404,    60,
      40,    40,    40,   385,   365,   182,    40,   368,   182,   718,
     371,   372,   373,    40,    75,   376,    77,   180,   104,   105,
      40,   164,   165,   166,   167,   168,   169,   174,   175,   176,
      40,    40,    40,   394,    40,    40,   199,    40,   528,   421,
     772,    42,   772,    40,    40,    40,    40,   901,   902,    40,
      40,    55,    56,    57,    58,    59,    60,    40,    40,    40,
     421,    65,    66,    40,   493,   494,   493,    40,    40,    40,
      40,    40,   108,   108,    37,    43,    40,   809,    37,   809,
     108,    55,   175,    90,   466,     8,    17,    10,    11,   821,
      13,   821,    37,    43,   476,     6,    89,    25,    41,    91,
      41,   102,    53,   368,   486,   466,   838,   372,   838,    66,
      54,   493,   494,    48,    41,   476,   498,    41,    48,   180,
      41,   503,    48,    41,   506,   486,    41,    41,    48,    41,
      52,    48,   493,    41,    41,    41,    41,    41,   199,    48,
      41,    41,   503,   876,    41,   506,    41,    41,    41,    48,
     725,    41,    41,    41,    41,    41,   421,    48,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,    41,    48,   179,   180,
     103,   610,    41,   610,    41,    41,   615,   110,   111,    41,
      41,   114,    41,   116,    48,    41,   928,    41,   928,    41,
     123,   466,   125,    43,     6,   368,    24,   174,    37,   372,
     660,   476,   149,    43,    41,    41,    25,   102,   102,    41,
     149,   486,   604,   605,    48,    41,   605,    39,   610,   804,
      41,    41,    49,   615,    48,   810,    41,    41,   503,    29,
      41,   506,    49,   604,   605,    48,    28,   629,   161,   610,
      41,   161,    40,    36,    75,    41,    41,   639,   421,   102,
      41,   690,    40,    63,    41,    41,    55,    41,   629,    89,
     102,    37,    37,    48,    46,    37,    49,    41,   639,   854,
     161,   663,   801,   243,   666,   667,   643,   509,   795,   645,
     798,   512,   629,   639,   723,   421,   355,   180,   615,   687,
     779,   610,   663,   466,   696,   666,   667,   368,   690,   884,
     243,   372,   695,   476,   662,    56,    26,    77,    89,   728,
     678,   466,   280,   486,   666,   772,   770,   910,   903,   690,
     741,   866,   744,   520,   868,   518,   874,   532,   674,   604,
     503,   723,    -1,   506,   409,   409,   921,    -1,    -1,    -1,
     779,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   741,
     421,   743,   744,    -1,   629,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   639,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   770,    -1,
     772,    -1,    -1,   775,    -1,    -1,    -1,   779,   663,    -1,
      -1,    -1,    -1,    -1,    -1,   466,    -1,    -1,    -1,   770,
      -1,   772,    -1,   795,   775,   476,   798,    -1,   779,    -1,
      -1,    -1,    -1,    -1,    -1,   486,    -1,   809,    -1,    -1,
     812,    -1,   814,    -1,   795,    -1,    -1,   798,    -1,   821,
      -1,   604,   503,    -1,    -1,   506,    -1,    -1,   809,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   838,    -1,    -1,   841,
     821,    -1,    -1,    -1,   846,    -1,   629,    42,    -1,   851,
     852,    -1,   851,   852,    -1,    -1,   639,   838,    -1,    -1,
     841,    -1,    -1,    -1,   866,   846,   868,    -1,    -1,    -1,
     851,   852,    -1,    -1,   876,    41,    42,    -1,    -1,    -1,
     663,    -1,    -1,    -1,    -1,    -1,    -1,   772,    -1,    -1,
     775,    -1,    -1,    -1,    -1,   876,    -1,    -1,    -1,   901,
     902,    -1,    -1,    -1,    -1,   886,   908,    -1,   910,    -1,
     795,    -1,    -1,   798,    -1,    -1,    -1,    -1,    -1,    -1,
     901,   902,    -1,   604,   809,    -1,   928,    -1,    -1,   910,
      -1,    -1,    -1,    -1,    -1,    -1,   821,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    40,   928,   629,    -1,
      -1,    -1,    -1,   838,   149,    -1,   841,    51,   639,    -1,
      -1,   846,    -1,    -1,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   663,    -1,   179,   180,    -1,    -1,    -1,   772,
      -1,   876,   775,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    -1,   795,   179,   180,   798,   901,   902,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   809,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   821,    -1,
      -1,    -1,    -1,   928,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   838,    -1,    -1,   841,    -1,
      -1,    -1,    -1,   846,    -1,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    -1,   182,    -1,
      -1,   772,    -1,   876,   775,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   795,    -1,    -1,   798,   901,   902,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   809,    -1,
      -1,    31,    32,    33,    34,    35,    -1,   258,    -1,    -1,
     821,    41,    -1,    -1,    -1,   928,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    -1,    -1,    -1,   838,    -1,    -1,
     841,   282,   283,   284,    -1,   846,   287,    -1,    -1,   290,
     291,   292,    -1,    -1,    -1,    -1,   297,   298,   299,   300,
      -1,   302,   303,   304,   305,   306,   307,    -1,    -1,    -1,
     311,   312,   313,    -1,   315,   876,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,    -1,    -1,
     901,   902,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    -1,   928,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    40,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,    -1,   182,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    -1,   434,   435,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,    -1,   109,    -1,    -1,
     112,   113,    -1,   115,    -1,   117,   118,   119,    -1,   121,
     122,   462,   124,   464,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   174,   175,   176,    -1,    -1,   179,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   543,   544,   545,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   557,    -1,    -1,   560,
      -1,    -1,    -1,    -1,   565,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,   577,    -1,    -1,    -1,
     581,    -1,    -1,    -1,   585,    -1,    -1,    -1,    -1,    -1,
      -1,   592,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   609,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,
      64,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,    -1,   109,    -1,    -1,   112,   113,
      -1,   115,    -1,   117,   118,   119,    -1,   121,   122,    -1,
     124,    -1,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   713,    -1,   715,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    -1,    19,   179,   180,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    -1,    -1,   807,    92,    93,    94,
      95,    96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   107,    -1,   109,    -1,    -1,   112,   113,    -1,
     115,    -1,   117,   118,   119,    -1,   121,   122,    -1,   124,
      -1,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,    40,    -1,   179,   180,    -1,    -1,    -1,    -1,
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
     136,   137,   138,   139,   140,   141,    42,    -1,    -1,    -1,
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
     140,   141,    -1,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    40,    -1,   179,   180,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   174,   175,   176,    -1,    -1,   179,
     180,    -1,    -1,    -1,    -1,    -1,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    88,
      -1,     8,    -1,    10,    11,    -1,    13,    -1,    -1,    16,
      99,    -1,    -1,    20,    21,    -1,    -1,    -1,   107,    -1,
     109,    -1,    -1,   112,   113,    -1,   115,    -1,   117,   118,
     119,    38,   121,   122,    -1,   124,    -1,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   174,   175,   176,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,
      -1,    -1,    -1,   110,   111,    -1,    -1,   114,    -1,   116,
      -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,   125
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  SPARQLfedParser::yystos_[] =
  {
         0,    14,   184,   185,   186,   189,   190,   226,   286,   287,
     174,     0,     8,    10,    11,    13,    16,    20,    21,    38,
     103,   110,   111,   114,   116,   123,   125,   187,   230,   234,
     243,   244,   248,   292,   293,   296,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   191,   174,   175,
     176,   498,   499,    12,   297,   297,   297,    17,    18,   235,
     236,    36,   376,    19,   179,   180,   245,   246,   447,   448,
     498,   231,   498,   297,   297,    36,   320,    36,   321,   297,
     321,    30,   188,   278,   231,   288,     3,     4,   310,   312,
     313,    15,   192,   227,     9,   294,   295,     6,    23,   104,
     105,   318,   319,   318,   319,    19,    40,    65,    67,    68,
      69,    70,    71,    72,    73,    74,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    88,    92,    93,
      94,    95,    96,    97,    98,    99,   107,   109,   112,   113,
     115,   117,   118,   119,   121,   122,   124,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   239,   240,
     241,   242,   368,   448,   473,   475,   477,   478,   479,   480,
     483,   488,   492,   493,   494,   495,   496,   497,   498,   377,
     231,   447,   231,    22,    39,   249,   254,   255,     6,   104,
     316,   317,   316,    31,    32,    33,    34,    35,    51,   177,
     178,   182,   322,   323,   331,   382,   438,   439,   441,   442,
     443,   446,   448,   449,   488,   492,   496,   498,   500,   322,
     316,   279,   254,    49,   290,   291,   320,   320,   311,   309,
     313,   228,   157,   193,   195,   196,   318,   498,    40,    61,
      62,    64,   448,   450,   451,   454,   457,   458,   461,   462,
     468,   470,   471,   472,   473,   480,   486,   488,   492,   496,
     498,    74,    40,    40,    40,   182,   474,    40,   182,   374,
      40,    40,    40,    36,   157,   334,   336,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,   374,    40,
      40,    40,    40,    40,   182,    40,   182,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,   240,
      40,    87,   181,   489,   490,   491,    40,   182,   369,   378,
     379,   382,   254,   247,   254,    23,   250,   251,   252,   253,
     498,   334,   108,   498,   108,   440,    37,   326,    43,   332,
     333,   384,    40,   383,    37,   108,   280,    90,   256,   257,
     261,   189,   287,   289,    39,   106,   314,   175,    55,   194,
     450,   471,   471,   471,    89,   237,   238,   453,   456,    55,
      56,    57,    58,    59,    60,    65,    66,   459,   460,   467,
     469,   369,   487,   334,   450,   450,   450,   450,   450,   450,
     450,   337,   450,   450,   450,   450,   448,   450,   450,   450,
     450,   450,   450,    17,   371,   371,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   371,   498,   371,    37,    43,   380,   381,   256,
     256,   253,   316,   316,    50,   385,   396,   447,   325,   327,
     328,   323,   385,   390,   391,   438,   444,   445,   446,   385,
     316,    36,   448,    25,    91,   258,   264,   334,    23,   315,
     498,   229,    36,   102,   145,   147,   149,   197,   198,   200,
     201,   208,   210,   211,   218,    41,   448,    41,    53,   452,
      54,   455,   461,   461,   461,   461,   461,   461,    66,   374,
      61,    62,   463,   466,   494,   495,    19,    63,   464,    41,
      41,    41,   375,    48,    48,    48,   232,   234,   335,   338,
     339,   342,   397,   438,   446,    41,    41,    48,    41,    41,
      48,    41,    41,    41,    41,    48,    19,   450,   482,   450,
      41,    41,    41,    41,    41,    41,    41,    48,    41,    41,
      41,    48,    41,    41,    41,    48,    41,    41,    41,    41,
      41,    41,    48,    41,    41,    41,   450,   450,   378,    52,
     392,   395,   445,    43,   324,     6,    41,   445,   284,    40,
     262,   263,   368,   448,   473,   265,   266,   367,   368,   472,
     473,    24,   259,   267,   498,   174,   219,    42,   102,   202,
     203,   206,   285,   448,   488,   492,   496,   498,   149,   212,
     213,   216,   285,   201,   199,   211,   209,   454,   457,   374,
     468,   468,   464,   465,   470,   470,   373,   450,   450,   450,
     233,    37,   341,    43,   343,   344,   399,   398,   450,   450,
     450,    41,   481,   450,   450,   450,   450,    41,   370,   389,
     394,   323,   447,    37,    40,   182,   282,   450,   263,   266,
      25,    28,    29,   260,   273,   276,   277,    37,    40,   220,
     206,   102,   216,   149,   199,    43,   102,   204,   209,    43,
     149,   214,    41,    48,   372,    48,    41,    41,   254,     6,
       7,    44,    45,    47,   120,   142,   278,   340,   345,   346,
     347,   349,   353,   356,   357,   360,   361,   366,   339,   391,
     408,    40,    50,    64,   100,   400,   402,   409,   410,   411,
     412,   415,   418,   420,   426,   427,   448,   498,    41,    41,
     372,   476,    49,   484,   485,    41,   476,    41,    41,   373,
      49,   388,    48,   393,   329,   283,   238,    26,    27,   268,
     269,   270,   271,   272,   367,   448,   161,   161,   274,   277,
     275,   276,   221,   145,   207,   205,   148,   217,   215,   450,
     450,   256,   350,   354,   348,   358,   367,    40,   334,   324,
     362,   411,    40,    50,   100,   428,   433,   434,   436,   498,
     418,   401,   414,   417,    19,    36,    61,   101,   419,   421,
     425,    41,    75,    41,    41,    41,   386,   387,   396,   395,
      36,   281,   285,    41,   269,   472,   224,   203,   213,    41,
     188,   351,   355,   334,   359,   450,   339,   334,    41,   431,
     432,   434,    50,   435,   498,   392,   102,   413,    63,   416,
      48,   161,   424,   437,    55,   392,   330,    41,   285,    41,
     223,   225,   285,   447,   447,   334,    89,   365,    41,   430,
     407,   415,   420,   437,    37,    48,   423,   497,   323,    48,
     222,   143,   144,   352,   334,   448,    46,   363,   102,   429,
      49,   406,    37,    37,   422,   437,    37,   285,   285,   334,
      41,   364,   434,   402,   403,   405,    37,   334,   404,   392
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
     240,   240,   240,   241,   241,   242,   242,   243,   244,   245,
     245,   246,   246,   247,   247,   248,   249,   250,   250,   251,
     252,   253,   254,   255,   255,   256,   257,   257,   258,   258,
     259,   259,   260,   260,   261,   262,   262,   263,   263,   263,
     263,   264,   265,   265,   266,   267,   268,   268,   269,   269,
     270,   270,   271,   272,   272,   273,   273,   274,   274,   275,
     275,   276,   277,   279,   278,   280,   280,   281,   281,   283,
     282,   282,   284,   284,   285,   285,   285,   285,   285,   285,
     286,   288,   287,   289,   289,   290,   291,   291,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   293,
     294,   295,   295,   296,   297,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   308,   309,   309,
     310,   310,   311,   311,   312,   313,   314,   315,   315,   316,
     316,   317,   317,   318,   319,   319,   319,   319,   320,   321,
     322,   323,   323,   324,   324,   325,   326,   326,   328,   329,
     330,   327,   331,   332,   333,   333,   334,   334,   335,   335,
     337,   336,   338,   339,   339,   340,   341,   341,   342,   343,
     344,   344,   345,   345,   345,   345,   345,   345,   345,   345,
     345,   346,   348,   347,   350,   351,   352,   349,   354,   355,
     353,   356,   358,   359,   357,   361,   362,   360,   364,   363,
     365,   365,   366,   367,   367,   367,   368,   369,   370,   369,
     371,   371,   372,   373,   373,   374,   375,   374,   377,   376,
     378,   378,   379,   380,   381,   381,   383,   382,   384,   382,
     385,   386,   387,   387,   388,   389,   389,   390,   391,   391,
     392,   393,   394,   394,   395,   396,   396,   398,   397,   399,
     397,   401,   400,   402,   402,   404,   403,   405,   405,   406,
     407,   407,   408,   409,   410,   411,   412,   413,   414,   414,
     415,   416,   417,   417,   418,   419,   419,   420,   420,   421,
     422,   422,   423,   423,   424,   424,   425,   425,   425,   425,
     426,   427,   427,   427,   427,   428,   429,   430,   430,   431,
     432,   432,   433,   433,   434,   435,   435,   436,   436,   436,
     437,   438,   438,   440,   439,   441,   442,   442,   442,   442,
     442,   443,   443,   444,   444,   445,   445,   446,   446,   447,
     447,   448,   448,   449,   449,   449,   449,   449,   449,   450,
     451,   452,   453,   453,   454,   455,   456,   456,   457,   458,
     459,   459,   460,   460,   460,   460,   460,   460,   460,   460,
     461,   462,   463,   463,   464,   464,   465,   465,   466,   466,
     466,   467,   467,   468,   469,   469,   470,   470,   470,   470,
     471,   471,   471,   471,   471,   471,   471,   471,   472,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   474,   474,
     475,   476,   476,   477,   478,   479,   480,   480,   481,   480,
     482,   482,   483,   483,   483,   483,   483,   484,   485,   485,
     486,   487,   487,   488,   489,   490,   490,   491,   491,   492,
     492,   492,   493,   493,   493,   494,   494,   494,   495,   495,
     495,   496,   496,   497,   497,   497,   497,   498,   498,   499,
     499,   500,   500
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
       1,     1,     1,     1,     2,     1,     1,     5,     5,     1,
       2,     1,     1,     0,     1,     3,     2,     1,     1,     1,
       2,     1,     2,     0,     1,     4,     0,     1,     0,     1,
       0,     1,     0,     1,     3,     1,     2,     1,     1,     4,
       1,     2,     1,     2,     1,     3,     1,     2,     1,     1,
       1,     1,     2,     1,     1,     2,     2,     0,     1,     0,
       1,     2,     2,     0,     6,     0,     2,     1,     2,     0,
       4,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     0,     1,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     0,     1,     3,     0,     1,     3,     3,     5,     5,
       5,     2,     2,     2,     5,     2,     0,     1,     0,     1,
       2,     1,     0,     2,     2,     2,     2,     1,     2,     1,
       2,     0,     1,     2,     1,     1,     1,     1,     3,     3,
       2,     0,     1,     0,     1,     3,     0,     2,     0,     0,
       0,     8,     2,     2,     0,     1,     1,     1,     1,     1,
       0,     4,     2,     0,     1,     3,     0,     2,     2,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     0,     3,     0,     0,     0,     6,     0,     0,
       5,     6,     0,     0,     4,     0,     0,     4,     0,     3,
       0,     2,     2,     1,     1,     1,     2,     1,     0,     6,
       0,     1,     2,     0,     2,     1,     0,     5,     0,     4,
       0,     1,     2,     2,     0,     1,     0,     3,     0,     3,
       3,     2,     0,     1,     2,     0,     2,     1,     0,     1,
       2,     2,     0,     2,     1,     1,     1,     0,     3,     0,
       3,     0,     4,     1,     1,     0,     3,     0,     1,     2,
       0,     2,     1,     1,     1,     1,     2,     2,     0,     2,
       2,     2,     0,     2,     2,     0,     1,     1,     2,     1,
       1,     2,     2,     1,     2,     3,     1,     1,     1,     2,
       1,     1,     1,     2,     3,     1,     2,     0,     2,     2,
       0,     1,     1,     3,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     0,     4,     4,     1,     1,     1,     1,
       1,     0,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     0,     2,     2,     2,     0,     2,     1,     2,
       0,     1,     2,     2,     2,     2,     2,     2,     2,     3,
       1,     2,     1,     1,     2,     2,     0,     1,     2,     2,
       2,     0,     2,     2,     0,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     4,
       4,     6,     4,     4,     4,     4,     2,     2,     4,     4,
       4,     4,     2,     1,     4,     4,     4,     4,     6,     6,
       6,     4,     4,     4,     4,     4,     4,     4,     2,     4,
       4,     4,     4,     4,     4,     2,     8,     6,     6,     6,
       4,     4,     4,     4,     4,     1,     1,     1,     3,     1,
       7,     0,     1,     7,     2,     3,     5,     5,     0,     7,
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
  "ConstructQuery", "DescribeQuery", "_QVarOrIRIref_E_Plus",
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
  "OffsetClause", "BindingsClause", "$@8", "_QVar_E_Star",
  "_QBindingValue_E_Plus",
  "_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C",
  "$@9",
  "_Q_O_QGT_LPAREN_E_S_QBindingValue_E_Plus_S_QGT_RPAREN_E_Or_QNIL_E_C_E_Star",
  "BindingValue", "UpdateUnit", "Update", "$@10", "_QUpdate_E_Opt",
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
  "QuadsNotTriples", "@11", "@12", "$@13", "TriplesTemplate",
  "_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesTemplate_E_Opt_C_E_Opt", "GroupGraphPattern",
  "_O_QSubSelect_E_Or_QGroupGraphPatternSub_E_C",
  "_O_QGT_LCURLEY_E_S_QSubSelect_E_Or_QGroupGraphPatternSub_E_S_QGT_RCURLEY_E_C",
  "$@14", "GroupGraphPatternSub", "_QTriplesBlock_E_Opt",
  "_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGraphPatternNotTriples_E_S_QGT_DOT_E_Opt_S_QTriplesBlock_E_Opt_C_E_Star",
  "TriplesBlock", "_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QTriplesBlock_E_Opt_C_E_Opt", "GraphPatternNotTriples",
  "Print", "OptionalGraphPattern", "@15", "GraphGraphPattern", "@16",
  "@17", "@18", "ServiceGraphPattern", "@19", "@20", "Bind",
  "MinusGraphPattern", "@21", "@22", "GroupOrUnionGraphPattern", "@23",
  "@24", "_O_QIT_UNION_E_S_QGroupGraphPattern_E_C", "@25",
  "_Q_O_QIT_UNION_E_S_QGroupGraphPattern_E_C_E_Star", "Filter",
  "Constraint", "FunctionCall", "ArgList", "$@26", "_QIT_DISTINCT_E_Opt",
  "_O_QGT_COMMA_E_S_QExpression_E_C",
  "_Q_O_QGT_COMMA_E_S_QExpression_E_C_E_Star", "ExpressionList", "$@27",
  "ConstructTemplate", "$@28", "_QConstructTriples_E_Opt",
  "ConstructTriples", "_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C",
  "_Q_O_QGT_DOT_E_S_QConstructTriples_E_Opt_C_E_Opt", "TriplesSameSubject",
  "$@29", "$@30", "PropertyListNotEmpty", "_O_QVerb_E_S_QObjectList_E_C",
  "_Q_O_QVerb_E_S_QObjectList_E_C_E_Opt",
  "_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C",
  "_Q_O_QGT_SEMI_E_S_QVerb_E_S_QObjectList_E_Opt_C_E_Star", "PropertyList",
  "_QPropertyListNotEmpty_E_Opt", "ObjectList",
  "_O_QGT_COMMA_E_S_QObject_E_C", "_Q_O_QGT_COMMA_E_S_QObject_E_C_E_Star",
  "Object", "Verb", "TriplesSameSubjectPath", "$@31", "$@32",
  "PropertyListNotEmptyPath", "$@33", "_O_QVerbPath_E_Or_QVerbSimple_E_C",
  "_O_QVerbPath_E_Or_QVerbSimple_E_S_QObjectList_E_C", "$@34",
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
  "Integer", "TriplesNode", "BlankNodePropertyList", "@35", "Generator",
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
  "$@36", "_O_QGT_TIMES_E_Or_QExpression_E_C",
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
       184,     0,    -1,   185,    -1,   286,    -1,   186,    -1,   189,
     187,   188,    -1,   230,    -1,   243,    -1,   244,    -1,   248,
      -1,    -1,   278,    -1,   190,   191,   192,    -1,    -1,   226,
      -1,    -1,   191,   227,    -1,    -1,   192,   193,    -1,    -1,
     196,   194,   197,    -1,   157,    55,    -1,    -1,   195,    -1,
     198,    -1,   208,    -1,   218,    -1,   200,   201,   199,   207,
      -1,   201,   199,    43,    -1,    -1,   199,   204,    -1,   145,
      -1,   102,   203,    -1,   206,    -1,   202,   206,    -1,   102,
      -1,   202,    -1,    -1,   102,   205,   203,    -1,   285,   102,
      -1,   145,    -1,   210,   211,   209,   217,    -1,   211,   209,
      43,    -1,    -1,   209,   214,    -1,   147,    -1,   149,   213,
      -1,   216,    -1,   212,   216,    -1,   149,    -1,   212,    -1,
      -1,   149,   215,   213,    -1,   285,   149,    -1,   148,    -1,
      36,   219,    37,    -1,    -1,   219,   220,    -1,    -1,    40,
     221,   224,    41,    -1,    -1,    48,    -1,   225,   222,    -1,
      -1,   224,   223,    -1,   285,   144,   285,    -1,   285,   143,
     285,    -1,    14,   174,    -1,    -1,    -1,    15,   228,   175,
     229,   174,    -1,   234,   231,   254,   256,    -1,    -1,   231,
     249,    -1,    -1,   234,   233,   254,   256,   188,    -1,    16,
     236,   242,    -1,    17,    -1,    18,    -1,    -1,   235,    -1,
      89,   448,    -1,    -1,   237,    -1,    40,   450,   238,    41,
      -1,   448,    -1,   480,    -1,   473,    -1,   368,    -1,   488,
      -1,   492,    -1,   496,    -1,   239,    -1,   240,    -1,   241,
     240,    -1,   241,    -1,    19,    -1,    20,   376,   231,   254,
     256,    -1,    21,   246,   231,   247,   256,    -1,   447,    -1,
     245,   447,    -1,   245,    -1,    19,    -1,    -1,   254,    -1,
      38,   231,   254,    -1,    22,   250,    -1,   251,    -1,   252,
      -1,   253,    -1,    23,   253,    -1,   498,    -1,   255,   334,
      -1,    -1,    39,    -1,   257,   258,   259,   260,    -1,    -1,
     261,    -1,    -1,   264,    -1,    -1,   267,    -1,    -1,   273,
      -1,    90,    25,   262,    -1,   263,    -1,   262,   263,    -1,
     473,    -1,   368,    -1,    40,   450,   238,    41,    -1,   448,
      -1,    91,   265,    -1,   266,    -1,   265,   266,    -1,   367,
      -1,    24,    25,   268,    -1,   269,    -1,   268,   269,    -1,
     271,    -1,   272,    -1,    26,    -1,    27,    -1,   270,   472,
      -1,   367,    -1,   448,    -1,   276,   274,    -1,   277,   275,
      -1,    -1,   277,    -1,    -1,   276,    -1,    28,   161,    -1,
      29,   161,    -1,    -1,    30,   279,   280,    36,   284,    37,
      -1,    -1,   280,   448,    -1,   285,    -1,   281,   285,    -1,
      -1,    40,   283,   281,    41,    -1,   182,    -1,    -1,   284,
     282,    -1,   498,    -1,   488,    -1,   492,    -1,   496,    -1,
      42,    -1,   448,    -1,   287,    -1,    -1,   189,   292,   288,
     291,    -1,    -1,   287,    -1,    49,   289,    -1,    -1,   290,
      -1,   293,    -1,   296,    -1,   298,    -1,   300,    -1,   301,
      -1,   302,    -1,   299,    -1,   303,    -1,   304,    -1,   305,
      -1,   306,    -1,     8,   498,   295,    -1,     9,   318,    -1,
      -1,   294,    -1,    10,   297,   319,    -1,    -1,    12,    -1,
      13,   297,   319,    -1,    11,   297,   318,    -1,   110,   297,
     316,   108,   316,    -1,   123,   297,   316,   108,   316,    -1,
     111,   297,   316,   108,   316,    -1,   125,   321,    -1,   116,
     321,    -1,   114,   320,    -1,   308,   310,   311,    39,   334,
      -1,   103,   498,    -1,    -1,   307,    -1,    -1,   313,    -1,
     312,   309,    -1,   313,    -1,    -1,   311,   314,    -1,     3,
     320,    -1,     4,   320,    -1,   106,   315,    -1,   498,    -1,
      23,   498,    -1,   104,    -1,   317,   498,    -1,    -1,     6,
      -1,     6,   498,    -1,   318,    -1,   104,    -1,    23,    -1,
     105,    -1,    36,   322,    37,    -1,    36,   322,    37,    -1,
     323,   326,    -1,    -1,   331,    -1,    -1,    43,    -1,   327,
     324,   323,    -1,    -1,   326,   325,    -1,    -1,    -1,    -1,
     328,     6,   447,   329,    36,   330,   323,    37,    -1,   382,
     333,    -1,    43,   323,    -1,    -1,   332,    -1,   336,    -1,
     157,    -1,   232,    -1,   338,    -1,    -1,    36,   337,   335,
      37,    -1,   339,   341,    -1,    -1,   342,    -1,   345,   324,
     339,    -1,    -1,   341,   340,    -1,   397,   344,    -1,    43,
     339,    -1,    -1,   343,    -1,   360,    -1,   347,    -1,   357,
      -1,   349,    -1,   353,    -1,   366,    -1,   356,    -1,   278,
      -1,   346,    -1,   142,   334,    -1,    -1,    44,   348,   334,
      -1,    -1,    -1,    -1,     6,   350,   351,   447,   352,   334,
      -1,    -1,    -1,     7,   354,   355,   447,   334,    -1,   120,
      40,   450,    89,   448,    41,    -1,    -1,    -1,    45,   358,
     359,   334,    -1,    -1,    -1,   361,   362,   334,   365,    -1,
      -1,    46,   364,   334,    -1,    -1,   365,   363,    -1,    47,
     367,    -1,   472,    -1,   473,    -1,   368,    -1,   498,   369,
      -1,   182,    -1,    -1,    40,   371,   450,   370,   373,    41,
      -1,    -1,    17,    -1,    48,   450,    -1,    -1,   373,   372,
      -1,   182,    -1,    -1,    40,   450,   375,   373,    41,    -1,
      -1,    36,   377,   378,    37,    -1,    -1,   379,    -1,   382,
     381,    -1,    43,   378,    -1,    -1,   380,    -1,    -1,   446,
     383,   385,    -1,    -1,   438,   384,   390,    -1,   396,   392,
     389,    -1,   396,   392,    -1,    -1,   386,    -1,    49,   387,
      -1,    -1,   389,   388,    -1,   391,    -1,    -1,   385,    -1,
     395,   394,    -1,    48,   395,    -1,    -1,   394,   393,    -1,
     445,    -1,   447,    -1,    50,    -1,    -1,   446,   398,   400,
      -1,    -1,   438,   399,   408,    -1,    -1,   402,   401,   392,
     407,    -1,   409,    -1,   410,    -1,    -1,   402,   404,   392,
      -1,    -1,   403,    -1,    49,   405,    -1,    -1,   407,   406,
      -1,   391,    -1,   411,    -1,   448,    -1,   412,    -1,   415,
     414,    -1,   102,   415,    -1,    -1,   414,   413,    -1,   420,
     417,    -1,    63,   420,    -1,    -1,   417,   416,    -1,   426,
     419,    -1,    -1,   421,    -1,   418,    -1,   100,   418,    -1,
     425,    -1,    37,    -1,   437,    37,    -1,    48,   422,    -1,
      37,    -1,   437,   423,    -1,    48,   437,    37,    -1,    19,
      -1,   101,    -1,    61,    -1,    36,   424,    -1,   427,    -1,
     498,    -1,    50,    -1,    64,   428,    -1,    40,   411,    41,
      -1,   433,    -1,   102,   434,    -1,    -1,   430,   429,    -1,
     434,   430,    -1,    -1,   431,    -1,   434,    -1,    40,   432,
      41,    -1,   436,    -1,   498,    -1,    50,    -1,   498,    -1,
      50,    -1,   100,   435,    -1,   161,    -1,   441,    -1,   439,
      -1,    -1,    51,   440,   385,    52,    -1,   443,    40,   444,
      41,    -1,    31,    -1,    32,    -1,    33,    -1,    34,    -1,
      35,    -1,    -1,   442,    -1,   445,    -1,   444,   445,    -1,
     446,    -1,   438,    -1,   448,    -1,   449,    -1,   448,    -1,
     498,    -1,   179,    -1,   180,    -1,   498,    -1,   488,    -1,
     492,    -1,   496,    -1,   500,    -1,   182,    -1,   451,    -1,
     454,   453,    -1,    53,   454,    -1,    -1,   453,   452,    -1,
     457,   456,    -1,    54,   457,    -1,    -1,   456,   455,    -1,
     458,    -1,   461,   459,    -1,    -1,   460,    -1,    55,   461,
      -1,    56,   461,    -1,    57,   461,    -1,    58,   461,    -1,
      59,   461,    -1,    60,   461,    -1,    66,   374,    -1,    65,
      66,   374,    -1,   462,    -1,   468,   467,    -1,   494,    -1,
     495,    -1,    19,   470,    -1,    63,   470,    -1,    -1,   464,
      -1,    61,   468,    -1,    62,   468,    -1,   463,   465,    -1,
      -1,   467,   466,    -1,   470,   469,    -1,    -1,   469,   464,
      -1,    64,   471,    -1,    61,   471,    -1,    62,   471,    -1,
     471,    -1,   472,    -1,   473,    -1,   486,    -1,   488,    -1,
     492,    -1,   496,    -1,   448,    -1,   480,    -1,    40,   450,
      41,    -1,    76,    40,   450,    41,    -1,    77,    40,   450,
      41,    -1,    78,    40,   450,    48,   450,    41,    -1,    79,
      40,   450,    41,    -1,    80,    40,   448,    41,    -1,    67,
      40,   450,    41,    -1,    68,    40,   450,    41,    -1,    69,
     474,    -1,   112,   182,    -1,   135,    40,   450,    41,    -1,
     132,    40,   450,    41,    -1,   124,    40,   450,    41,    -1,
     118,    40,   450,    41,    -1,    88,   374,    -1,   477,    -1,
     139,    40,   450,    41,    -1,   136,    40,   450,    41,    -1,
     134,    40,   450,    41,    -1,   130,    40,   450,    41,    -1,
     121,    40,   450,    48,   450,    41,    -1,   131,    40,   450,
      48,   450,    41,    -1,   138,    40,   450,    48,   450,    41,
      -1,   109,    40,   450,    41,    -1,   141,    40,   450,    41,
      -1,   133,    40,   450,    41,    -1,   129,    40,   450,    41,
      -1,   126,    40,   450,    41,    -1,   122,    40,   450,    41,
      -1,   117,    40,   450,    41,    -1,   115,   182,    -1,   107,
      40,   450,    41,    -1,   140,    40,   450,    41,    -1,   137,
      40,   450,    41,    -1,   128,    40,   450,    41,    -1,   119,
      40,   450,    41,    -1,   113,    40,   450,    41,    -1,    70,
     374,    -1,    71,    40,   450,    48,   450,    48,   450,    41,
      -1,    72,    40,   450,    48,   450,    41,    -1,    73,    40,
     450,    48,   450,    41,    -1,    81,    40,   450,    48,   450,
      41,    -1,    82,    40,   450,    41,    -1,    83,    40,   450,
      41,    -1,    84,    40,   450,    41,    -1,    85,    40,   450,
      41,    -1,    99,    40,   450,    41,    -1,   475,    -1,   478,
      -1,   479,    -1,    40,   450,    41,    -1,   182,    -1,    86,
      40,   450,    48,   450,   476,    41,    -1,    -1,   372,    -1,
     127,    40,   450,    48,   450,   476,    41,    -1,    74,   334,
      -1,    65,    74,   334,    -1,    92,    40,   371,   482,    41,
      -1,   483,    40,   371,   450,    41,    -1,    -1,    97,    40,
     371,   450,   481,   485,    41,    -1,    19,    -1,   450,    -1,
      93,    -1,    94,    -1,    95,    -1,    96,    -1,    98,    -1,
      49,    75,    55,   497,    -1,    -1,   484,    -1,   498,   487,
      -1,    -1,   369,    -1,   497,   491,    -1,    87,   498,    -1,
     181,    -1,   489,    -1,    -1,   490,    -1,   493,    -1,   494,
      -1,   495,    -1,   161,    -1,   162,    -1,   163,    -1,   164,
      -1,   165,    -1,   166,    -1,   167,    -1,   168,    -1,   169,
      -1,   159,    -1,   160,    -1,   170,    -1,   172,    -1,   171,
      -1,   173,    -1,   174,    -1,   499,    -1,   176,    -1,   175,
      -1,   177,    -1,   178,    -1
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
     221,   223,   225,   227,   229,   232,   234,   236,   242,   248,
     250,   253,   255,   257,   258,   260,   264,   267,   269,   271,
     273,   276,   278,   281,   282,   284,   289,   290,   292,   293,
     295,   296,   298,   299,   301,   305,   307,   310,   312,   314,
     319,   321,   324,   326,   329,   331,   335,   337,   340,   342,
     344,   346,   348,   351,   353,   355,   358,   361,   362,   364,
     365,   367,   370,   373,   374,   381,   382,   385,   387,   390,
     391,   396,   398,   399,   402,   404,   406,   408,   410,   412,
     414,   416,   417,   422,   423,   425,   428,   429,   431,   433,
     435,   437,   439,   441,   443,   445,   447,   449,   451,   453,
     457,   460,   461,   463,   467,   468,   470,   474,   478,   484,
     490,   496,   499,   502,   505,   511,   514,   515,   517,   518,
     520,   523,   525,   526,   529,   532,   535,   538,   540,   543,
     545,   548,   549,   551,   554,   556,   558,   560,   562,   566,
     570,   573,   574,   576,   577,   579,   583,   584,   587,   588,
     589,   590,   599,   602,   605,   606,   608,   610,   612,   614,
     616,   617,   622,   625,   626,   628,   632,   633,   636,   639,
     642,   643,   645,   647,   649,   651,   653,   655,   657,   659,
     661,   663,   666,   667,   671,   672,   673,   674,   681,   682,
     683,   689,   696,   697,   698,   703,   704,   705,   710,   711,
     715,   716,   719,   722,   724,   726,   728,   731,   733,   734,
     741,   742,   744,   747,   748,   751,   753,   754,   760,   761,
     766,   767,   769,   772,   775,   776,   778,   779,   783,   784,
     788,   792,   795,   796,   798,   801,   802,   805,   807,   808,
     810,   813,   816,   817,   820,   822,   824,   826,   827,   831,
     832,   836,   837,   842,   844,   846,   847,   851,   852,   854,
     857,   858,   861,   863,   865,   867,   869,   872,   875,   876,
     879,   882,   885,   886,   889,   892,   893,   895,   897,   900,
     902,   904,   907,   910,   912,   915,   919,   921,   923,   925,
     928,   930,   932,   934,   937,   941,   943,   946,   947,   950,
     953,   954,   956,   958,   962,   964,   966,   968,   970,   972,
     975,   977,   979,   981,   982,   987,   992,   994,   996,   998,
    1000,  1002,  1003,  1005,  1007,  1010,  1012,  1014,  1016,  1018,
    1020,  1022,  1024,  1026,  1028,  1030,  1032,  1034,  1036,  1038,
    1040,  1043,  1046,  1047,  1050,  1053,  1056,  1057,  1060,  1062,
    1065,  1066,  1068,  1071,  1074,  1077,  1080,  1083,  1086,  1089,
    1093,  1095,  1098,  1100,  1102,  1105,  1108,  1109,  1111,  1114,
    1117,  1120,  1121,  1124,  1127,  1128,  1131,  1134,  1137,  1140,
    1142,  1144,  1146,  1148,  1150,  1152,  1154,  1156,  1158,  1162,
    1167,  1172,  1179,  1184,  1189,  1194,  1199,  1202,  1205,  1210,
    1215,  1220,  1225,  1228,  1230,  1235,  1240,  1245,  1250,  1257,
    1264,  1271,  1276,  1281,  1286,  1291,  1296,  1301,  1306,  1309,
    1314,  1319,  1324,  1329,  1334,  1339,  1342,  1351,  1358,  1365,
    1372,  1377,  1382,  1387,  1392,  1397,  1399,  1401,  1403,  1407,
    1409,  1417,  1418,  1420,  1428,  1431,  1435,  1441,  1447,  1448,
    1456,  1458,  1460,  1462,  1464,  1466,  1468,  1470,  1475,  1476,
    1478,  1481,  1482,  1484,  1487,  1490,  1492,  1494,  1495,  1497,
    1499,  1501,  1503,  1505,  1507,  1509,  1511,  1513,  1515,  1517,
    1519,  1521,  1523,  1525,  1527,  1529,  1531,  1533,  1535,  1537,
    1539,  1541,  1543
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
     818,   821,   825,   830,   833,   841,   844,   851,   860,   868,
     871,   879,   882,   889,   892,   897,   905,   912,   913,   917,
     923,   929,   936,   943,   945,   950,   957,   960,   965,   968,
     973,   976,   981,   985,   989,   996,   999,  1006,  1009,  1012,
    1015,  1021,  1027,  1030,  1037,  1042,  1049,  1053,  1061,  1063,
    1071,  1074,  1082,  1090,  1091,  1098,  1102,  1110,  1113,  1118,
    1121,  1125,  1131,  1138,  1138,  1146,  1148,  1154,  1157,  1163,
    1163,  1168,  1174,  1176,  1180,  1183,  1186,  1189,  1192,  1195,
    1201,  1205,  1205,  1214,  1216,  1220,  1223,  1225,  1229,  1230,
    1231,  1232,  1233,  1234,  1235,  1236,  1237,  1238,  1239,  1243,
    1250,  1257,  1260,  1264,  1270,  1273,  1279,  1285,  1291,  1297,
    1303,  1309,  1317,  1325,  1333,  1342,  1348,  1351,  1355,  1358,
    1362,  1366,  1372,  1374,  1380,  1387,  1394,  1400,  1403,  1409,
    1412,  1417,  1419,  1423,  1429,  1432,  1435,  1438,  1445,  1449,
    1453,  1456,  1458,  1462,  1464,  1468,  1471,  1473,  1478,  1483,
    1486,  1478,  1497,  1501,  1504,  1506,  1510,  1511,  1521,  1522,
    1527,  1527,  1539,  1543,  1545,  1555,  1559,  1562,  1578,  1583,
    1587,  1590,  1594,  1595,  1596,  1597,  1598,  1599,  1600,  1601,
    1604,  1608,  1614,  1614,  1630,  1634,  1636,  1630,  1647,  1651,
    1647,  1660,  1666,  1670,  1666,  1680,  1684,  1680,  1694,  1694,
    1709,  1711,  1715,  1726,  1727,  1728,  1732,  1740,  1744,  1744,
    1753,  1756,  1763,  1769,  1771,  1785,  1788,  1788,  1798,  1798,
    1806,  1808,  1813,  1818,  1822,  1824,  1828,  1828,  1831,  1831,
    1838,  1843,  1847,  1849,  1854,  1858,  1860,  1865,  1869,  1871,
    1876,  1881,  1885,  1887,  1891,  1898,  1902,  1910,  1910,  1913,
    1913,  1919,  1919,  1925,  1926,  1930,  1930,  1935,  1937,  1941,
    1944,  1946,  1950,  1954,  1958,  1964,  1968,  1972,  1975,  1977,
    1981,  1985,  1990,  1992,  1998,  2001,  2003,  2009,  2010,  2016,
    2020,  2021,  2025,  2026,  2030,  2031,  2035,  2036,  2037,  2038,
    2042,  2046,  2049,  2052,  2055,  2061,  2065,  2068,  2070,  2074,
    2077,  2079,  2083,  2084,  2088,  2092,  2093,  2097,  2098,  2099,
    2103,  2108,  2109,  2113,  2113,  2126,  2151,  2154,  2157,  2160,
    2163,  2170,  2173,  2178,  2182,  2189,  2190,  2194,  2197,  2201,
    2204,  2210,  2211,  2215,  2218,  2221,  2224,  2227,  2228,  2234,
    2239,  2248,  2255,  2258,  2266,  2275,  2282,  2285,  2292,  2297,
    2308,  2311,  2315,  2318,  2321,  2324,  2327,  2330,  2333,  2336,
    2342,  2347,  2356,  2359,  2366,  2369,  2376,  2379,  2384,  2387,
    2391,  2405,  2408,  2416,  2425,  2428,  2435,  2438,  2441,  2444,
    2448,  2449,  2450,  2451,  2454,  2457,  2460,  2463,  2467,  2473,
    2476,  2479,  2482,  2485,  2488,  2491,  2495,  2498,  2501,  2504,
    2507,  2510,  2513,  2516,  2517,  2520,  2523,  2526,  2529,  2532,
    2535,  2538,  2541,  2544,  2547,  2550,  2553,  2556,  2559,  2562,
    2565,  2568,  2571,  2574,  2577,  2580,  2584,  2587,  2590,  2593,
    2596,  2599,  2602,  2605,  2608,  2611,  2612,  2613,  2619,  2622,
    2629,  2636,  2639,  2643,  2649,  2656,  2663,  2666,  2670,  2670,
    2682,  2686,  2690,  2693,  2696,  2699,  2702,  2708,  2714,  2717,
    2721,  2731,  2734,  2739,  2747,  2754,  2758,  2766,  2770,  2774,
    2775,  2776,  2780,  2781,  2782,  2786,  2787,  2788,  2792,  2793,
    2794,  2798,  2799,  2803,  2804,  2805,  2806,  2810,  2811,  2815,
    2816,  2820,  2821
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
  const int SPARQLfedParser::yylast_ = 2398;
  const int SPARQLfedParser::yynnts_ = 318;
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
#line 5357 "lib/SPARQLfedParser/SPARQLfedParser.cpp"


/* Line 1056 of lalr1.cc  */
#line 2827 "lib/SPARQLfedParser/SPARQLfedParser.ypp"
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


